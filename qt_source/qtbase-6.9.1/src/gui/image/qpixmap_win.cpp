// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#include "qbitmap.h"
#include "qpixmap.h"
#include <private/qpixmap_win_p.h>
#include <qpa/qplatformpixmap.h>
#include "qpixmap_raster_p.h"

#include <qdebug.h>
#include <QScopedArrayPointer>
#include <qt_windows.h>

#include <algorithm>
#include <iterator>

QT_BEGIN_NAMESPACE

template <typename Int>
static inline Int pad4(Int v)
{
    return (v + Int(3)) & ~Int(3);
}

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug d, const BITMAPINFOHEADER &bih)
{
    QDebugStateSaver saver(d);
    d.nospace();
    d << "BITMAPINFOHEADER(" << bih.biWidth << 'x' << qAbs(bih.biHeight)
      << (bih.biHeight < 0 ? ", top-down" : ", bottom-up")
      << ", planes=" << bih.biPlanes << ", bitCount=" << bih.biBitCount
      << ", compression="  << bih.biCompression << ", size="
      << bih.biSizeImage << ')';
    return d;
}
#endif // !QT_NO_DEBUG_STREAM

static inline void initBitMapInfoHeader(int width, int height, bool topToBottom,
                                        DWORD compression, DWORD bitCount,
                                        BITMAPINFOHEADER *bih)
{
    memset(bih, 0, sizeof(BITMAPINFOHEADER));
    bih->biSize        = sizeof(BITMAPINFOHEADER);
    bih->biWidth       = width;
    bih->biHeight      = topToBottom ? -height : height;
    bih->biPlanes      = 1;
    bih->biBitCount    = WORD(bitCount);
    bih->biCompression = compression;
     // scan lines are word-aligned (unless RLE)
    const DWORD bytesPerLine = bitCount == 1 ? pad4(DWORD(qCeil(width / 8.0)))
                                             : pad4(DWORD(width) * bitCount / 8);
    bih->biSizeImage   = bytesPerLine * DWORD(height);
}

enum { Indexed8ColorTableSize = 256 };

struct BITMAPINFO_COLORTABLE256 { // BITMAPINFO with 256 entry color table for Indexed 8 format
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[Indexed8ColorTableSize];
};

template <class BITMAPINFO_T> // BITMAPINFO, BITMAPINFO_COLORTABLE256
static inline void initBitMapInfo(int width, int height, bool topToBottom,
                                  DWORD compression, DWORD bitCount,
                                  BITMAPINFO_T *bmi)
{
    initBitMapInfoHeader(width, height, topToBottom, compression, bitCount, &bmi->bmiHeader);
    memset(bmi->bmiColors, 0, sizeof(bmi->bmiColors));
}

static inline uchar *getDiBits(HDC hdc, HBITMAP bitmap, int width, int height, bool topToBottom = true)
{
    BITMAPINFO bmi;
    initBitMapInfo(width, height, topToBottom, BI_RGB, 32u, &bmi);
    uchar *result = new uchar[bmi.bmiHeader.biSizeImage];
    if (!GetDIBits(hdc, bitmap, 0, UINT(height), result, &bmi, DIB_RGB_COLORS)) {
        delete [] result;
        qErrnoWarning("%s: GetDIBits() failed to get bitmap bits.", __FUNCTION__);
        return nullptr;
    }
    return result;
}

static inline void copyImageDataCreateAlpha(const uchar *data, QImage *target)
{
    const uint mask = target->format() == QImage::Format_RGB32 ? 0xff000000 : 0;
    const int height = target->height();
    const int width = target->width();
    const qsizetype bytesPerLine = width * sizeof(QRgb);
    for (int y = 0; y < height; ++y) {
        QRgb *dest = reinterpret_cast<QRgb *>(target->scanLine(y));
        const QRgb *src = reinterpret_cast<const QRgb *>(data + y * bytesPerLine);
        for (int x = 0; x < width; ++x) {
            const uint pixel = src[x];
            if ((pixel & 0xff000000) == 0 && (pixel & 0x00ffffff) != 0)
                dest[x] = pixel | 0xff000000;
            else
                dest[x] = pixel | mask;
        }
    }
}

// Flip RGB triplets from DIB to QImage formats. Scan lines are padded to 32bit
// both in QImage and DIB.
static inline void flipRgb3(uchar *p, int width, int height)
{
    const int lineSize = 3 * width;
    const int linePad = pad4(lineSize) - lineSize;
    for (int y = 0; y < height; ++y) {
        uchar *end = p + lineSize;
        for ( ; p < end; p += 3)
            std::swap(*p, *(p + 2));
        p += linePad;
    }
}

static inline RGBQUAD qRgbToRgbQuad(QRgb qrgb)
{
    RGBQUAD result = {BYTE(qBlue(qrgb)), BYTE(qGreen(qrgb)), BYTE(qRed(qrgb)), 0};
    return result;
}

static inline QRgb rgbQuadToQRgb(RGBQUAD quad)
{
    return QRgb(quad.rgbBlue) + (QRgb(quad.rgbGreen) << 8) + (QRgb(quad.rgbRed) << 16)
        + 0xff000000;
}

// Helper for imageFromWinHBITMAP_*(), create image in desired format
static QImage copyImageData(const BITMAPINFOHEADER &header, const RGBQUAD *colorTableIn,
                            const void *data, QImage::Format format)
{
    const QSize size = QSize(header.biWidth, qAbs(header.biHeight));
    QImage image(size, format);

    int colorTableSize = 0;
    switch (format) {
    case QImage::Format_Mono:
        colorTableSize = 2;
        break;
    case QImage::Format_Indexed8:
        colorTableSize = Indexed8ColorTableSize;
        break;
    default:
        break;
    }
    if (colorTableSize) {
        Q_ASSERT(colorTableIn);
        QList<QRgb> colorTable;
        colorTable.reserve(colorTableSize);
        std::transform(colorTableIn, colorTableIn + colorTableSize,
                       std::back_inserter(colorTable), rgbQuadToQRgb);
        image.setColorTable(colorTable);
    }

    switch (header.biBitCount) {
    case 32:
        copyImageDataCreateAlpha(static_cast<const uchar *>(data), &image);
        break;
    case 1:
    case 8:
    case 16:
    case 24:
        Q_ASSERT(DWORD(image.sizeInBytes()) == header.biSizeImage);
        memcpy(image.bits(), data, header.biSizeImage);
        if (format == QImage::Format_RGB888)
            image = std::move(image).rgbSwapped();
        break;
    default:
        Q_UNREACHABLE();
        break;
    }
    return image;
}

class DisplayHdc
{
    Q_DISABLE_COPY_MOVE(DisplayHdc)
public:
    DisplayHdc() : m_displayDc(GetDC(nullptr)) {}
    ~DisplayHdc() { ReleaseDC(nullptr, m_displayDc); }

    operator HDC() const { return m_displayDc; }

private:
     const HDC m_displayDc;
};

enum HBitmapFormat
{
    HBitmapNoAlpha,
    HBitmapPremultipliedAlpha,
    HBitmapAlpha
};

static HBITMAP qt_createIconMask(QImage bm)
{
    Q_ASSERT(bm.format() == QImage::Format_Mono);
    const int w = bm.width();
    const int h = bm.height();
    const int bpl = ((w+15)/16)*2; // bpl, 16 bit alignment
    QScopedArrayPointer<uchar> bits(new uchar[size_t(bpl * h)]);
    bm.invertPixels();
    for (int y = 0; y < h; ++y)
        memcpy(bits.data() + y * bpl, bm.constScanLine(y), size_t(bpl));
    HBITMAP hbm = CreateBitmap(w, h, 1, 1, bits.data());
    return hbm;
}

HBITMAP qt_createIconMask(const QBitmap &bitmap)
{
    return qt_createIconMask(bitmap.toImage().convertToFormat(QImage::Format_Mono));
}

static inline QImage::Format format32(int hbitmapFormat)
{
    switch (hbitmapFormat) {
    case HBitmapNoAlpha:
        return QImage::Format_RGB32;
    case HBitmapAlpha:
        return QImage::Format_ARGB32;
    default:
        break;
    }
    return QImage::Format_ARGB32_Premultiplied;
}

HBITMAP qt_imageToWinHBITMAP(const QImage &imageIn, int hbitmapFormat)
{
    if (imageIn.isNull())
        return nullptr;

    // Define the header
    DWORD compression = 0;
    DWORD bitCount = 0;

    // Copy over the data
    QImage image = imageIn;
    switch (image.format()) {
    case QImage::Format_Mono:
        bitCount = 1u;
        break;
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied: {
        compression = BI_RGB;
        bitCount = 32u;
        const QImage::Format targetFormat = format32(hbitmapFormat);
        if (targetFormat != image.format())
            image = image.convertToFormat(targetFormat);
    }
        break;
    case QImage::Format_RGB888:
    case QImage::Format_BGR888:
        compression = BI_RGB;
        bitCount = 24u;
        break;
    case QImage::Format_Indexed8:
        bitCount = 8u;
        break;
    case QImage::Format_RGB555:
        bitCount = 16u;
        break;
    default: {
        QImage::Format fallbackFormat = QImage::Format_ARGB32_Premultiplied;
        switch (image.format()) { // Convert to a suitable format.
        case QImage::Format_MonoLSB:
            fallbackFormat = QImage::Format_Mono;
            break;
        case QImage::Format_RGB16:
            fallbackFormat = QImage::Format_RGB555;
            break;
        case QImage::Format_Grayscale8:
            fallbackFormat = QImage::Format_Indexed8;
            break;
        default:
            break;
        } // switch conversion format
        return qt_imageToWinHBITMAP(imageIn.convertToFormat(fallbackFormat), hbitmapFormat);
    }
    }

    const int w = image.width();
    const int h = image.height();

    BITMAPINFO_COLORTABLE256 bmiColorTable256;
    initBitMapInfo(w, h, true, compression, bitCount, &bmiColorTable256);
    BITMAPINFO &bmi = reinterpret_cast<BITMAPINFO &>(bmiColorTable256);
    switch (image.format()) {
    case QImage::Format_Mono: // Color table with 2 entries
    case QImage::Format_Indexed8:
        std::transform(image.colorTable().constBegin(), image.colorTable().constEnd(),
                       bmiColorTable256.bmiColors, qRgbToRgbQuad);
        break;
    default:
        break;
    }

    // Create the pixmap
    uchar *pixels = nullptr;
    const HBITMAP bitmap = CreateDIBSection(nullptr, &bmi, DIB_RGB_COLORS,
                                            reinterpret_cast<void **>(&pixels), nullptr, 0);
    if (!bitmap) {
        qErrnoWarning("%s, failed to create dibsection", __FUNCTION__);
        return nullptr;
    }
    if (!pixels) {
        DeleteObject(bitmap);
        qErrnoWarning("%s, did not allocate pixel data", __FUNCTION__);
        return nullptr;
    }
    memcpy(pixels, image.constBits(), bmi.bmiHeader.biSizeImage);
    if (image.format() == QImage::Format_RGB888)
        flipRgb3(pixels, w, h);
    return bitmap;
}

/*!
    \since 6.0

    \brief Creates a \c HBITMAP equivalent of the QImage.

    Returns the \c HBITMAP handle.

    It is the caller's responsibility to free the \c HBITMAP data
    after use.

    For usage with standard GDI calls, such as \c BitBlt(), the image
    should have the format QImage::Format_RGB32.

    When using the resulting HBITMAP for the \c AlphaBlend() GDI function,
    the image should have the format QImage::Format_ARGB32_Premultiplied
    (use convertToFormat()).

    When using the resulting HBITMAP as application icon or a systray icon,
    the image should have the format QImage::Format_ARGB32.

    \ingroup platform-type-conversions

    \sa fromHBITMAP(), convertToFormat()
*/
HBITMAP QImage::toHBITMAP() const
{
    switch (format()) {
    case QImage::Format_ARGB32:
        return qt_imageToWinHBITMAP(*this, HBitmapAlpha);
    case QImage::Format_ARGB32_Premultiplied:
        return qt_imageToWinHBITMAP(*this, HBitmapPremultipliedAlpha);
    default:
        break;
    }
    return qt_imageToWinHBITMAP(*this);
}

HBITMAP qt_pixmapToWinHBITMAP(const QPixmap &p, int hbitmapFormat)
{
    if (p.isNull())
        return nullptr;

    QPlatformPixmap *platformPixmap = p.handle();
    if (platformPixmap->classId() != QPlatformPixmap::RasterClass) {
        QRasterPlatformPixmap *data = new QRasterPlatformPixmap(p.depth() == 1 ?
            QRasterPlatformPixmap::BitmapType : QRasterPlatformPixmap::PixmapType);
        data->fromImage(p.toImage(), Qt::AutoColor);
        return qt_pixmapToWinHBITMAP(QPixmap(data), hbitmapFormat);
    }

    return qt_imageToWinHBITMAP(*static_cast<QRasterPlatformPixmap*>(platformPixmap)->buffer(), hbitmapFormat);
}

static QImage::Format imageFromWinHBITMAP_Format(const BITMAPINFOHEADER &header, int hbitmapFormat)
{
    QImage::Format result = QImage::Format_Invalid;
    switch (header.biBitCount) {
    case 32:
        result = hbitmapFormat == HBitmapNoAlpha
            ? QImage::Format_RGB32 : QImage::Format_ARGB32_Premultiplied;
        break;
    case 24:
        result = QImage::Format_BGR888;
        break;
    case 16:
        result = QImage::Format_RGB555;
        break;
    case 8:
        result = QImage::Format_Indexed8;
        break;
    case 1:
        result = QImage::Format_Mono;
        break;
    }
    return result;
}

// Fast path for creating a QImage directly from a HBITMAP created by CreateDIBSection(),
// not requiring memory allocation.
static QImage imageFromWinHBITMAP_DibSection(HBITMAP bitmap, int hbitmapFormat)
{
    DIBSECTION dibSection;
    memset(&dibSection, 0, sizeof(dibSection));
    dibSection.dsBmih.biSize = sizeof(dibSection.dsBmih);

    if (!GetObject(bitmap, sizeof(dibSection), &dibSection)
        || !dibSection.dsBm.bmBits
        || dibSection.dsBmih.biBitCount <= 8 // Cannot access the color table for Indexed8, Mono
        || dibSection.dsBmih.biCompression != BI_RGB) {
        return QImage();
    }

    const QImage::Format imageFormat = imageFromWinHBITMAP_Format(dibSection.dsBmih, hbitmapFormat);
    if (imageFormat == QImage::Format_Invalid)
        return QImage();

    return copyImageData(dibSection.dsBmih, nullptr, dibSection.dsBm.bmBits, imageFormat);
}

// Create QImage from a HBITMAP using GetDIBits(), potentially with conversion.
static QImage imageFromWinHBITMAP_GetDiBits(HBITMAP bitmap, bool forceQuads, int hbitmapFormat)
{
    BITMAPINFO_COLORTABLE256 bmiColorTable256;
    BITMAPINFO &info = reinterpret_cast<BITMAPINFO &>(bmiColorTable256);
    memset(&info, 0, sizeof(info));
    info.bmiHeader.biSize = sizeof(info.bmiHeader);

    DisplayHdc displayDc;
    if (!GetDIBits(displayDc, bitmap, 0, 1, 0, &info, DIB_RGB_COLORS)) {
        qErrnoWarning("%s: GetDIBits() failed to query data.", __FUNCTION__);
        return QImage();
    }

    if (info.bmiHeader.biHeight > 0) // Force top-down
        info.bmiHeader.biHeight = -info.bmiHeader.biHeight;
    info.bmiHeader.biCompression = BI_RGB; // Extract using no compression (can be BI_BITFIELD)
    size_t allocSize = info.bmiHeader.biSizeImage;
    if (forceQuads) {
       info.bmiHeader.biBitCount = 32;
       allocSize = info.bmiHeader.biWidth * qAbs(info.bmiHeader.biHeight) * 4;
    }

    const QImage::Format imageFormat = imageFromWinHBITMAP_Format(info.bmiHeader, hbitmapFormat);
    if (imageFormat == QImage::Format_Invalid) {
        qWarning().nospace() << __FUNCTION__ << ": unsupported image format:" << info.bmiHeader;
        return QImage();
    }

    QScopedArrayPointer<uchar> data(new uchar[allocSize]);
    if (!GetDIBits(displayDc, bitmap, 0, qAbs(info.bmiHeader.biHeight), data.data(), &info, DIB_RGB_COLORS)) {
        qErrnoWarning("%s: GetDIBits() failed to get data.", __FUNCTION__);
        return QImage();
    }
    return copyImageData(info.bmiHeader, bmiColorTable256.bmiColors, data.data(), imageFormat);
}

QImage qt_imageFromWinHBITMAP(HBITMAP bitmap, int hbitmapFormat)
{
    QImage result = imageFromWinHBITMAP_DibSection(bitmap, hbitmapFormat);
    if (result.isNull())
        result = imageFromWinHBITMAP_GetDiBits(bitmap, /* forceQuads */ false, hbitmapFormat);
    return result;
}

/*!
    \since 6.0

    \brief Returns a QImage that is equivalent to the given \a hbitmap.

    HBITMAP does not store information about the alpha channel.

    In the standard case, the alpha channel is ignored and a fully
    opaque image is created (typically of format QImage::Format_RGB32).

    There are cases where the alpha channel is used, though, for example
    for application icon or systray icons. In that case,
    \c reinterpretAsFormat(QImage::Format_ARGB32) should be called
    on the returned image to ensure the format is correct.

    \ingroup platform-type-conversions

    \sa toHBITMAP(), reinterpretAsFormat()
*/
QImage QImage::fromHBITMAP(HBITMAP hbitmap)
{
    return qt_imageFromWinHBITMAP(hbitmap);
}

QPixmap qt_pixmapFromWinHBITMAP(HBITMAP bitmap, int hbitmapFormat)
{
    return QPixmap::fromImage(imageFromWinHBITMAP_GetDiBits(bitmap, /* forceQuads */ true, hbitmapFormat));
}

/*!
    \since 6.0

    \brief Creates a \c HICON equivalent of the QPixmap, applying the mask
    \a mask.

    If \a mask is not null, it needs to be of format QImage::Format_Mono.
    Returns the \c HICON handle.

    It is the caller's responsibility to free the \c HICON data after use.

    \ingroup platform-type-conversions

    \sa fromHICON()
*/
HICON QImage::toHICON(const QImage &mask) const
{
    if (!mask.isNull() && mask.format() != QImage::Format_Mono) {
        qWarning("QImage::toHICON(): Mask must be empty or have format Format_Mono");
        return nullptr;
    }

    if (isNull())
        return nullptr;

    auto effectiveMask = mask;
    if (effectiveMask.isNull()) {
        effectiveMask = QImage(size(), QImage::Format_Mono);
        effectiveMask.fill(Qt::color1);
    }

    ICONINFO ii;
    ii.fIcon    = true;
    ii.hbmMask  = qt_createIconMask(effectiveMask);
    ii.hbmColor = qt_imageToWinHBITMAP(*this, HBitmapAlpha);
    ii.xHotspot = 0;
    ii.yHotspot = 0;

    HICON hIcon = CreateIconIndirect(&ii);

    DeleteObject(ii.hbmColor);
    DeleteObject(ii.hbmMask);

    return hIcon;
}

HICON qt_pixmapToWinHICON(const QPixmap &p)
{
    QImage mask;
    QBitmap maskBitmap = p.mask();
    if (!maskBitmap.isNull())
        mask = maskBitmap.toImage().convertToFormat(QImage::Format_Mono);
    return p.toImage().toHICON(mask);
}

QImage qt_imageFromWinHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h)
{
    QImage image(w, h, QImage::Format_ARGB32_Premultiplied);
    if (image.isNull())
        return image;
    QScopedArrayPointer<uchar> data(getDiBits(hdc, bitmap, w, h, true));
    if (data.isNull())
        return QImage();
    copyImageDataCreateAlpha(data.data(), &image);
    return image;
}

static QImage qt_imageFromWinIconHBITMAP(HDC hdc, HBITMAP bitmap, int w, int h)
{
    QImage image(w, h, QImage::Format_ARGB32_Premultiplied);
    if (image.isNull())
        return image;
    QScopedArrayPointer<uchar> data(getDiBits(hdc, bitmap, w, h, true));
    if (data.isNull())
        return QImage();
    memcpy(image.bits(), data.data(), size_t(image.sizeInBytes()));
    return image;
}

static inline bool hasAlpha(const QImage &image)
{
    const int w = image.width();
    const int h = image.height();
    for (int y = 0; y < h; ++y) {
        const QRgb *scanLine = reinterpret_cast<const QRgb *>(image.scanLine(y));
        for (int x = 0; x < w; ++x) {
            if (qAlpha(scanLine[x]) != 0)
                return true;
        }
    }
    return false;
}

/*!
    \since 6.0

    \brief Returns a QImage that is equivalent to the given \a icon.

    \ingroup platform-type-conversions

    \sa toHICON()
*/
QImage QImage::fromHICON(HICON icon)
{
    HDC screenDevice = GetDC(nullptr);
    HDC hdc = CreateCompatibleDC(screenDevice);
    ReleaseDC(nullptr, screenDevice);

    ICONINFO iconinfo;
    const bool result = GetIconInfo(icon, &iconinfo); //x and y Hotspot describes the icon center
    if (!result) {
        qErrnoWarning("QPixmap::fromWinHICON(), failed to GetIconInfo()");
        DeleteDC(hdc);
        return {};
    }

    const int w = int(iconinfo.xHotspot) * 2;
    const int h = int(iconinfo.yHotspot) * 2;

    BITMAPINFOHEADER bitmapInfo;
    initBitMapInfoHeader(w, h, false, BI_RGB, 32u, &bitmapInfo);
    DWORD* bits;

    HBITMAP winBitmap = CreateDIBSection(hdc, reinterpret_cast<BITMAPINFO *>(&bitmapInfo),
                                         DIB_RGB_COLORS, reinterpret_cast<VOID **>(&bits),
                                         nullptr, 0);
    HGDIOBJ oldhdc = static_cast<HBITMAP>(SelectObject(hdc, winBitmap));
    DrawIconEx(hdc, 0, 0, icon, w, h, 0, nullptr, DI_NORMAL);
    QImage image = qt_imageFromWinIconHBITMAP(hdc, winBitmap, w, h);

    if (!image.isNull() && !hasAlpha(image)) { //If no alpha was found, we use the mask to set alpha values
        DrawIconEx( hdc, 0, 0, icon, w, h, 0, nullptr, DI_MASK);
        const QImage mask = qt_imageFromWinIconHBITMAP(hdc, winBitmap, w, h);

        for (int y = 0 ; y < h ; y++){
            QRgb *scanlineImage = reinterpret_cast<QRgb *>(image.scanLine(y));
            const QRgb *scanlineMask = mask.isNull() ? nullptr : reinterpret_cast<const QRgb *>(mask.scanLine(y));
            for (int x = 0; x < w ; x++){
                if (scanlineMask && qRed(scanlineMask[x]) != 0)
                    scanlineImage[x] = 0; //mask out this pixel
                else
                    scanlineImage[x] |= 0xff000000; // set the alpha channel to 255
            }
        }
    }
    //dispose resources created by iconinfo call
    DeleteObject(iconinfo.hbmMask);
    DeleteObject(iconinfo.hbmColor);

    SelectObject(hdc, oldhdc); //restore state
    DeleteObject(winBitmap);
    DeleteDC(hdc);
    return image;
}

QPixmap qt_pixmapFromWinHICON(HICON icon)
{
    return QPixmap::fromImage(QImage::fromHICON(icon));
}

QT_END_NAMESPACE
