// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#include "private/qppmhandler_p.h"

#ifndef QT_NO_IMAGEFORMAT_PPM

#include <qdebug.h>
#include <qimage.h>
#include <qlist.h>
#include <qloggingcategory.h>
#include <qrgba64.h>
#include <qvariant.h>
#include <private/qlocale_p.h>
#include <private/qtools_p.h>
#include <private/qimage_p.h>

QT_BEGIN_NAMESPACE

/*****************************************************************************
  PBM/PGM/PPM (ASCII and RAW) image read/write functions
 *****************************************************************************/

static void discard_pbm_line(QIODevice *d)
{
    const int buflen = 100;
    char buf[buflen];
    int res = 0;
    do {
        res = d->readLine(buf, buflen);
    } while (res > 0 && buf[res-1] != '\n');
}

static int read_pbm_int(QIODevice *d, bool *ok, int maxDigits = -1)
{
    char c;
    int          val = -1;
    bool  digit;
    bool hasOverflow = false;
    for (;;) {
        if (!d->getChar(&c))                // end of file
            break;
        digit = QtMiscUtils::isAsciiDigit(c);
        if (val != -1) {
            if (digit) {
                const int cValue = c - '0';
                if (val <= (INT_MAX - cValue) / 10) {
                    val = 10*val + cValue;
                } else {
                    hasOverflow = true;
                }
                if (maxDigits > 0 && --maxDigits == 0)
                    break;
                continue;
            } else {
                if (c == '#')                        // comment
                    discard_pbm_line(d);
                break;
            }
        }
        if (digit)                                // first digit
            val = c - '0';
        else if (ascii_isspace(c))
            continue;
        else if (c == '#')
            discard_pbm_line(d);
        else
            break;
        if (maxDigits > 0 && --maxDigits == 0)
            break;
    }
    if (val < 0)
        *ok = false;
    return hasOverflow ? -1 : val;
}

static bool read_pbm_header(QIODevice *device, char& type, int& w, int& h, int& mcc)
{
    char buf[3];
    if (device->read(buf, 3) != 3)                        // read P[1-6]<white-space>
        return false;

    if (!(buf[0] == 'P' && QtMiscUtils::isAsciiDigit(buf[1]) && ascii_isspace(buf[2])))
        return false;

    type = buf[1];
    if (type < '1' || type > '6')
        return false;

    bool ok = true;
    w = read_pbm_int(device, &ok);                // get image width
    h = read_pbm_int(device, &ok);                // get image height

    if (type == '1' || type == '4')
        mcc = 1;                                  // ignore max color component
    else
        mcc = read_pbm_int(device, &ok);          // get max color component

    if (!ok || w <= 0 || w > 32767 || h <= 0 || h > 32767 || mcc <= 0 || mcc > 0xffff)
        return false;                             // weird P.M image

    return true;
}

static inline QRgb scale_pbm_color(quint16 mx, quint16 rv, quint16 gv, quint16 bv)
{
    return QRgba64::fromRgba64((rv * 0xffffu) / mx, (gv * 0xffffu) / mx, (bv * 0xffffu) / mx, 0xffff).toArgb32();
}

static bool read_pbm_body(QIODevice *device, char type, int w, int h, int mcc, QImage *outImage)
{
    int nbits, y;
    qsizetype pbm_bpl;
    bool raw;

    QImage::Format format;
    switch (type) {
        case '1':                                // ascii PBM
        case '4':                                // raw PBM
            nbits = 1;
            format = QImage::Format_Mono;
            break;
        case '2':                                // ascii PGM
        case '5':                                // raw PGM
            nbits = 8;
            format = QImage::Format_Grayscale8;
            break;
        case '3':                                // ascii PPM
        case '6':                                // raw PPM
            nbits = 32;
            format = QImage::Format_RGB32;
            break;
        default:
            return false;
    }
    raw = type >= '4';

    if (!QImageIOHandler::allocateImage(QSize(w, h), format, outImage))
        return false;

    pbm_bpl = (qsizetype(w) * nbits + 7) / 8;   // bytes per scanline in PBM

    if (raw) {                                // read raw data
        if (nbits == 32) {                        // type 6
            pbm_bpl = mcc < 256 ? 3*w : 6*w;
            uchar *buf24 = new uchar[pbm_bpl], *b;
            QRgb  *p;
            QRgb  *end;
            for (y=0; y<h; y++) {
                if (device->read((char *)buf24, pbm_bpl) != pbm_bpl) {
                    delete[] buf24;
                    return false;
                }
                p = (QRgb *)outImage->scanLine(y);
                end = p + w;
                b = buf24;
                while (p < end) {
                    if (mcc < 256) {
                        if (mcc == 255)
                            *p++ = qRgb(b[0],b[1],b[2]);
                        else
                            *p++ = scale_pbm_color(mcc, b[0], b[1], b[2]);
                        b += 3;
                    } else {
                        quint16 rv = b[0] << 8 | b[1];
                        quint16 gv = b[2] << 8 | b[3];
                        quint16 bv = b[4] << 8 | b[5];
                        if (mcc == 0xffff)
                            *p++ = QRgba64::fromRgba64(rv, gv, bv, 0xffff).toArgb32();
                        else
                            *p++ = scale_pbm_color(mcc, rv, gv, bv);
                        b += 6;
                    }
                }
            }
            delete[] buf24;
        } else if (nbits == 8 && mcc > 255) {  // type 5 16bit
            pbm_bpl = 2*w;
            uchar *buf16 = new uchar[pbm_bpl];
            for (y=0; y<h; y++) {
                if (device->read((char *)buf16, pbm_bpl) != pbm_bpl) {
                    delete[] buf16;
                    return false;
                }
                uchar *p = outImage->scanLine(y);
                uchar *end = p + w;
                uchar *b = buf16;
                while (p < end) {
                    *p++ = (b[0] << 8 | b[1]) * 255 / mcc;
                    b += 2;
                }
            }
            delete[] buf16;
        } else {                                // type 4,5
            for (y=0; y<h; y++) {
                uchar *p = outImage->scanLine(y);
                if (device->read((char *)p, pbm_bpl) != pbm_bpl)
                    return false;
                if (nbits == 8 && mcc < 255) {
                    for (qsizetype i = 0; i < pbm_bpl; i++)
                        p[i] = (p[i] * 255) / mcc;
                }
            }
        }
    } else {                                        // read ascii data
        uchar *p;
        qsizetype n;
        bool ok = true;
        for (y = 0; y < h && ok; y++) {
            p = outImage->scanLine(y);
            n = pbm_bpl;
            if (nbits == 1) {
                int b;
                int bitsLeft = w;
                while (n-- && ok) {
                    b = 0;
                    for (int i=0; i<8; i++) {
                        if (i < bitsLeft)
                            b = (b << 1) | (read_pbm_int(device, &ok, 1) & 1);
                        else
                            b = (b << 1) | (0 & 1); // pad it our self if we need to
                    }
                    bitsLeft -= 8;
                    *p++ = b;
                }
            } else if (nbits == 8) {
                if (mcc == 255) {
                    while (n-- && ok) {
                        *p++ = read_pbm_int(device, &ok);
                    }
                } else {
                    while (n-- && ok) {
                        *p++ = (read_pbm_int(device, &ok) & 0xffff) * 255 / mcc;
                    }
                }
            } else {                                // 32 bits
                n /= 4;
                int r, g, b;
                if (mcc == 255) {
                    while (n-- && ok) {
                        r = read_pbm_int(device, &ok);
                        g = read_pbm_int(device, &ok);
                        b = read_pbm_int(device, &ok);
                        *((QRgb*)p) = qRgb(r, g, b);
                        p += 4;
                    }
                } else {
                    while (n-- && ok) {
                        r = read_pbm_int(device, &ok);
                        g = read_pbm_int(device, &ok);
                        b = read_pbm_int(device, &ok);
                        *((QRgb*)p) = scale_pbm_color(mcc, r, g, b);
                        p += 4;
                    }
                }
            }
        }
        if (!ok)
            return false;
    }

    if (format == QImage::Format_Mono) {
        outImage->setColorCount(2);
        outImage->setColor(0, qRgb(255,255,255));   // white
        outImage->setColor(1, qRgb(0,0,0));         // black
    }

    return true;
}

static bool write_pbm_image(QIODevice *out, const QImage &sourceImage, QByteArrayView sourceFormat)
{
    QByteArray str;
    QImage image = sourceImage;
    const QByteArrayView format = sourceFormat.left(3); // ignore RAW part

    bool gray = format == "pgm";

    if (format == "pbm") {
        image = image.convertToFormat(QImage::Format_Mono);
    } else if (gray) {
        image = image.convertToFormat(QImage::Format_Grayscale8);
    } else {
        switch (image.format()) {
        case QImage::Format_Mono:
        case QImage::Format_MonoLSB:
            image = image.convertToFormat(QImage::Format_Indexed8);
            break;
        case QImage::Format_Indexed8:
        case QImage::Format_RGB32:
        case QImage::Format_ARGB32:
            break;
        default:
            if (image.hasAlphaChannel())
                image = image.convertToFormat(QImage::Format_ARGB32);
            else
                image = image.convertToFormat(QImage::Format_RGB32);
            break;
        }
    }

    if (image.depth() == 1 && image.colorCount() == 2) {
        if (qGray(image.color(0)) < qGray(image.color(1))) {
            // 0=dark/black, 1=light/white - invert
            image.detach();
            for (int y=0; y<image.height(); y++) {
                uchar *p = image.scanLine(y);
                uchar *end = p + image.bytesPerLine();
                while (p < end)
                    *p++ ^= 0xff;
            }
        }
    }

    uint w = image.width();
    uint h = image.height();

    str = "P\n";
    str += QByteArray::number(w);
    str += ' ';
    str += QByteArray::number(h);
    str += '\n';

    switch (image.depth()) {
        case 1: {
            str.insert(1, '4');
            if (out->write(str, str.size()) != str.size())
                return false;
            w = (w+7)/8;
            for (uint y=0; y<h; y++) {
                uchar* line = image.scanLine(y);
                if (w != (uint)out->write((char*)line, w))
                    return false;
            }
            }
            break;

        case 8: {
            str.insert(1, gray ? '5' : '6');
            str.append("255\n");
            if (out->write(str, str.size()) != str.size())
                return false;
            qsizetype bpl = qsizetype(w) * (gray ? 1 : 3);
            uchar *buf = new uchar[bpl];
            if (image.format() == QImage::Format_Indexed8) {
                const QList<QRgb> color = image.colorTable();
                for (uint y=0; y<h; y++) {
                    const uchar *b = image.constScanLine(y);
                    uchar *p = buf;
                    uchar *end = buf+bpl;
                    if (gray) {
                        while (p < end) {
                            uchar g = (uchar)qGray(color[*b++]);
                            *p++ = g;
                        }
                    } else {
                        while (p < end) {
                            QRgb rgb = color[*b++];
                            *p++ = qRed(rgb);
                            *p++ = qGreen(rgb);
                            *p++ = qBlue(rgb);
                        }
                    }
                    if (bpl != (qsizetype)out->write((char*)buf, bpl))
                        return false;
                }
            } else {
                for (uint y=0; y<h; y++) {
                    const uchar *b = image.constScanLine(y);
                    uchar *p = buf;
                    uchar *end = buf + bpl;
                    if (gray) {
                        while (p < end)
                            *p++ = *b++;
                    } else {
                        while (p < end) {
                            uchar color = *b++;
                            *p++ = color;
                            *p++ = color;
                            *p++ = color;
                        }
                    }
                    if (bpl != (qsizetype)out->write((char*)buf, bpl))
                        return false;
                }
            }
            delete [] buf;
            break;
        }

        case 32: {
            str.insert(1, '6');
            str.append("255\n");
            if (out->write(str, str.size()) != str.size())
                return false;
            qsizetype bpl = qsizetype(w) * 3;
            uchar *buf = new uchar[bpl];
            for (uint y=0; y<h; y++) {
                const QRgb  *b = reinterpret_cast<const QRgb *>(image.constScanLine(y));
                uchar *p = buf;
                uchar *end = buf+bpl;
                while (p < end) {
                    QRgb rgb = *b++;
                    *p++ = qRed(rgb);
                    *p++ = qGreen(rgb);
                    *p++ = qBlue(rgb);
                }
                if (bpl != (qsizetype)out->write((char*)buf, bpl))
                    return false;
            }
            delete [] buf;
            break;
        }

    default:
        return false;
    }

    return true;
}

QPpmHandler::QPpmHandler()
    : state(Ready)
{
}

bool QPpmHandler::readHeader()
{
    state = Error;
    if (!read_pbm_header(device(), type, width, height, mcc))
        return false;
    state = ReadHeader;
    return true;
}

bool QPpmHandler::canRead() const
{
    if (state == Ready && !canRead(device(), &subType))
        return false;

    if (state != Error) {
        setFormat(subType);
        return true;
    }

    return false;
}

bool QPpmHandler::canRead(QIODevice *device, QByteArray *subType)
{
    if (!device) {
        qCWarning(lcImageIo, "QPpmHandler::canRead() called with no device");
        return false;
    }

    char head[2];
    if (device->peek(head, sizeof(head)) != sizeof(head))
        return false;

    if (head[0] != 'P')
        return false;

    if (head[1] == '1' || head[1] == '4') {
        if (subType)
            *subType = "pbm";
    } else if (head[1] == '2' || head[1] == '5') {
        if (subType)
            *subType = "pgm";
    } else if (head[1] == '3' || head[1] == '6') {
        if (subType)
            *subType = "ppm";
    } else {
        return false;
    }
    return true;
}

bool QPpmHandler::read(QImage *image)
{
    if (state == Error)
        return false;

    if (state == Ready && !readHeader()) {
        state = Error;
        return false;
    }

    if (!read_pbm_body(device(), type, width, height, mcc, image)) {
        state = Error;
        return false;
    }

    state = Ready;
    return true;
}

bool QPpmHandler::write(const QImage &image)
{
    return write_pbm_image(device(), image, subType);
}

bool QPpmHandler::supportsOption(ImageOption option) const
{
    return option == SubType
        || option == Size
        || option == ImageFormat;
}

QVariant QPpmHandler::option(ImageOption option) const
{
    if (option == SubType) {
        return subType;
    } else if (option == Size) {
        if (state == Error)
            return QVariant();
        if (state == Ready && !const_cast<QPpmHandler*>(this)->readHeader())
            return QVariant();
        return QSize(width, height);
    } else if (option == ImageFormat) {
        if (state == Error)
            return QVariant();
        if (state == Ready && !const_cast<QPpmHandler*>(this)->readHeader())
            return QVariant();
        QImage::Format format = QImage::Format_Invalid;
        switch (type) {
            case '1':                                // ascii PBM
            case '4':                                // raw PBM
                format = QImage::Format_Mono;
                break;
            case '2':                                // ascii PGM
            case '5':                                // raw PGM
                format = QImage::Format_Grayscale8;
                break;
            case '3':                                // ascii PPM
            case '6':                                // raw PPM
                format = QImage::Format_RGB32;
                break;
            default:
                break;
        }
        return format;
    }
    return QVariant();
}

void QPpmHandler::setOption(ImageOption option, const QVariant &value)
{
    if (option == SubType)
        subType = value.toByteArray().toLower();
}

QT_END_NAMESPACE

#endif // QT_NO_IMAGEFORMAT_PPM
