// Copyright (C) 2022 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#include "qimage.h"

#include "qbuffer.h"
#include "qdatastream.h"
#include "qcolortransform.h"
#include "qfloat16.h"
#include "qmap.h"
#include "qtransform.h"
#include "qimagereader.h"
#include "qimagewriter.h"
#include "qrgbafloat.h"
#include "qstringlist.h"
#include "qvariant.h"
#include "qimagepixmapcleanuphooks_p.h"
#include <qpa/qplatformintegration.h>
#include <private/qguiapplication_p.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <qpa/qplatformpixmap.h>
#include <private/qcolorspace_p.h>
#include <private/qcolortransform_p.h>
#include <private/qmemrotate_p.h>
#include <private/qimagescale_p.h>
#include <private/qpixellayout_p.h>
#include <private/qsimd_p.h>

#include <qhash.h>

#include <private/qpaintengine_raster_p.h>

#include <private/qimage_p.h>
#include <private/qfont_p.h>

#if QT_CONFIG(qtgui_threadpool)
#include <qsemaphore.h>
#include <qthreadpool.h>
#include <private/qthreadpool_p.h>
#endif

#include <qtgui_tracepoints_p.h>

#include <memory>

QT_BEGIN_NAMESPACE
class QCmyk32;

using namespace Qt::StringLiterals;

// MSVC 19.28 does show spurious warning "C4723: potential divide by 0" for code that divides
// by height() in release builds. Anyhow, all the code paths in this file are only executed
// for valid QImage's, where height() cannot be 0. Therefore disable the warning.
QT_WARNING_DISABLE_MSVC(4723)

#if defined(Q_CC_DEC) && defined(__alpha) && (__DECCXX_VER-0 >= 50190001)
#pragma message disable narrowptr
#endif


#define QIMAGE_SANITYCHECK_MEMORY(image) \
    if ((image).isNull()) { \
        qWarning("QImage: out of memory, returning null image"); \
        return QImage(); \
    }

Q_TRACE_PREFIX(qtgui,
   "#include <qimagereader.h>"
);

Q_TRACE_METADATA(qtgui,
"ENUM { } QImage::Format;" \
"FLAGS { } Qt::ImageConversionFlags;"
);

Q_TRACE_PARAM_REPLACE(Qt::AspectRatioMode, int);
Q_TRACE_PARAM_REPLACE(Qt::TransformationMode, int);

static QImage rotated90(const QImage &src);
static QImage rotated180(const QImage &src);
static QImage rotated270(const QImage &src);

static int next_qimage_serial_number()
{
    Q_CONSTINIT static QBasicAtomicInt serial = Q_BASIC_ATOMIC_INITIALIZER(0);
    return 1 + serial.fetchAndAddRelaxed(1);
}

QImageData::QImageData()
    : ref(0), width(0), height(0), depth(0), nbytes(0), devicePixelRatio(1.0), data(nullptr),
      format(QImage::Format_ARGB32), bytes_per_line(0),
      ser_no(next_qimage_serial_number()),
      detach_no(0),
      dpmx(qt_defaultDpiX() * 100 / qreal(2.54)),
      dpmy(qt_defaultDpiY() * 100 / qreal(2.54)),
      offset(0, 0), own_data(true), ro_data(false), has_alpha_clut(false),
      is_cached(false), cleanupFunction(nullptr), cleanupInfo(nullptr),
      paintEngine(nullptr)
{
}

/*! \fn QImageData * QImageData::create(const QSize &size, QImage::Format format)

    \internal

    Creates a new image data.
    Returns \nullptr if invalid parameters are give or anything else failed.
*/
QImageData * Q_TRACE_INSTRUMENT(qtgui) QImageData::create(const QSize &size, QImage::Format format)
{
    if (size.isEmpty() || format <= QImage::Format_Invalid || format >= QImage::NImageFormats)
        return nullptr;                             // invalid parameter(s)

    Q_TRACE_SCOPE(QImageData_create, size, format);

    int width = size.width();
    int height = size.height();
    int depth = qt_depthForFormat(format);
    auto params = calculateImageParameters(width, height, depth);
    if (!params.isValid())
        return nullptr;

    auto d = std::make_unique<QImageData>();

    switch (format) {
    case QImage::Format_Mono:
    case QImage::Format_MonoLSB:
        d->colortable.resize(2);
        d->colortable[0] = QColor(Qt::black).rgba();
        d->colortable[1] = QColor(Qt::white).rgba();
        break;
    default:
        break;
    }

    d->width = width;
    d->height = height;
    d->depth = depth;
    d->format = format;
    d->has_alpha_clut = false;
    d->is_cached = false;

    d->bytes_per_line = params.bytesPerLine;
    d->nbytes = params.totalSize;
    d->data  = (uchar *)malloc(d->nbytes);

    if (!d->data)
        return nullptr;

    d->ref.ref();
    return d.release();
}

QImageData::~QImageData()
{
    if (cleanupFunction)
        cleanupFunction(cleanupInfo);
    if (is_cached)
        QImagePixmapCleanupHooks::executeImageHooks((((qint64) ser_no) << 32) | ((qint64) detach_no));
    delete paintEngine;
    if (data && own_data)
        free(data);
    data = nullptr;
}

#if defined(_M_ARM) && defined(_MSC_VER)
#pragma optimize("", off)
#endif

bool QImageData::checkForAlphaPixels() const
{
    bool has_alpha_pixels = false;

    switch (format) {

    case QImage::Format_Mono:
    case QImage::Format_MonoLSB:
    case QImage::Format_Indexed8:
        has_alpha_pixels = has_alpha_clut;
        break;
    case QImage::Format_Alpha8:
        has_alpha_pixels = true;
        break;
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied: {
        const uchar *bits = data;
        for (int y=0; y<height && !has_alpha_pixels; ++y) {
            uint alphaAnd = 0xff000000;
            for (int x=0; x<width; ++x)
                alphaAnd &= reinterpret_cast<const uint*>(bits)[x];
            has_alpha_pixels = (alphaAnd != 0xff000000);
            bits += bytes_per_line;
        }
    } break;

    case QImage::Format_RGBA8888:
    case QImage::Format_RGBA8888_Premultiplied: {
        const uchar *bits = data;
        for (int y=0; y<height && !has_alpha_pixels; ++y) {
            uchar alphaAnd = 0xff;
            for (int x=0; x<width; ++x)
                alphaAnd &= bits[x * 4+ 3];
            has_alpha_pixels = (alphaAnd != 0xff);
            bits += bytes_per_line;
        }
    } break;

    case QImage::Format_A2BGR30_Premultiplied:
    case QImage::Format_A2RGB30_Premultiplied: {
        const uchar *bits = data;
        for (int y=0; y<height && !has_alpha_pixels; ++y) {
            uint alphaAnd = 0xc0000000;
            for (int x=0; x<width; ++x)
                alphaAnd &= reinterpret_cast<const uint*>(bits)[x];
            has_alpha_pixels = (alphaAnd != 0xc0000000);
            bits += bytes_per_line;
        }
    } break;

    case QImage::Format_ARGB8555_Premultiplied:
    case QImage::Format_ARGB8565_Premultiplied: {
        const uchar *bits = data;
        const uchar *end_bits = data + bytes_per_line;

        for (int y=0; y<height && !has_alpha_pixels; ++y) {
            uchar alphaAnd = 0xff;
            while (bits < end_bits) {
                alphaAnd &= bits[0];
                bits += 3;
            }
            has_alpha_pixels = (alphaAnd != 0xff);
            bits = end_bits;
            end_bits += bytes_per_line;
        }
    } break;

    case QImage::Format_ARGB6666_Premultiplied: {
        const uchar *bits = data;
        const uchar *end_bits = data + bytes_per_line;

        for (int y=0; y<height && !has_alpha_pixels; ++y) {
            uchar alphaAnd = 0xfc;
            while (bits < end_bits) {
                alphaAnd &= bits[0];
                bits += 3;
            }
            has_alpha_pixels = (alphaAnd != 0xfc);
            bits = end_bits;
            end_bits += bytes_per_line;
        }
    } break;

    case QImage::Format_ARGB4444_Premultiplied: {
        const uchar *bits = data;
        for (int y=0; y<height && !has_alpha_pixels; ++y) {
            ushort alphaAnd = 0xf000;
            for (int x=0; x<width; ++x)
                alphaAnd &= reinterpret_cast<const ushort*>(bits)[x];
            has_alpha_pixels = (alphaAnd != 0xf000);
            bits += bytes_per_line;
        }
    } break;
    case QImage::Format_RGBA64:
    case QImage::Format_RGBA64_Premultiplied: {
        uchar *bits = data;
        for (int y=0; y<height && !has_alpha_pixels; ++y) {
            for (int x=0; x<width; ++x) {
                has_alpha_pixels |= !(((QRgba64 *)bits)[x].isOpaque());
            }
            bits += bytes_per_line;
        }
    } break;
    case QImage::Format_RGBA16FPx4:
    case QImage::Format_RGBA16FPx4_Premultiplied: {
        uchar *bits = data;
        for (int y = 0; y < height && !has_alpha_pixels; ++y) {
            for (int x = 0; x < width; ++x)
                has_alpha_pixels |= ((qfloat16 *)bits)[x * 4 + 3] < 1.0f;
            bits += bytes_per_line;
        }
    } break;
    case QImage::Format_RGBA32FPx4:
    case QImage::Format_RGBA32FPx4_Premultiplied: {
        uchar *bits = data;
        for (int y = 0; y < height && !has_alpha_pixels; ++y) {
            for (int x = 0; x < width; ++x)
                has_alpha_pixels |= ((float *)bits)[x * 4 + 3] < 1.0f;
            bits += bytes_per_line;
        }
    } break;

    case QImage::Format_RGB32:
    case QImage::Format_RGB16:
    case QImage::Format_RGB444:
    case QImage::Format_RGB555:
    case QImage::Format_RGB666:
    case QImage::Format_RGB888:
    case QImage::Format_BGR888:
    case QImage::Format_RGBX8888:
    case QImage::Format_BGR30:
    case QImage::Format_RGB30:
    case QImage::Format_Grayscale8:
    case QImage::Format_Grayscale16:
    case QImage::Format_RGBX64:
    case QImage::Format_RGBX16FPx4:
    case QImage::Format_RGBX32FPx4:
    case QImage::Format_CMYK8888:
        break;
    case QImage::Format_Invalid:
    case QImage::NImageFormats:
        Q_UNREACHABLE();
        break;
    }

    return has_alpha_pixels;
}
#if defined(_M_ARM) && defined(_MSC_VER)
#pragma optimize("", on)
#endif

/*!
    \class QImage

    \inmodule QtGui
    \ingroup painting
    \ingroup shared

    \reentrant

    \brief The QImage class provides a hardware-independent image
    representation that allows direct access to the pixel data, and
    can be used as a paint device.

    Qt provides four classes for handling image data: QImage, QPixmap,
    QBitmap and QPicture.  QImage is designed and optimized for I/O,
    and for direct pixel access and manipulation, while QPixmap is
    designed and optimized for showing images on screen. QBitmap is
    only a convenience class that inherits QPixmap, ensuring a
    depth of 1. Finally, the QPicture class is a paint device that
    records and replays QPainter commands.

    Because QImage is a QPaintDevice subclass, QPainter can be used to
    draw directly onto images.  When using QPainter on a QImage, the
    painting can be performed in another thread than the current GUI
    thread.

    The QImage class supports several image formats described by the
    \l Format enum. These include monochrome, 8-bit, 32-bit and
    alpha-blended images which are available in all versions of Qt
    4.x.

    QImage provides a collection of functions that can be used to
    obtain a variety of information about the image. There are also
    several functions that enables transformation of the image.

    QImage objects can be passed around by value since the QImage
    class uses \l{Implicit Data Sharing}{implicit data
    sharing}. QImage objects can also be streamed and compared.

    \note If you would like to load QImage objects in a static build of Qt,
    refer to the \l{How to Create Qt Plugins}{Plugin HowTo}.

    \warning Painting on a QImage with the format
    QImage::Format_Indexed8 or QImage::Format_CMYK8888 is not supported.

    \section1 Reading and Writing Image Files

    QImage provides several ways of loading an image file: The file
    can be loaded when constructing the QImage object, or by using the
    load() or loadFromData() functions later on. QImage also provides
    the static fromData() function, constructing a QImage from the
    given data.  When loading an image, the file name can either refer
    to an actual file on disk or to one of the application's embedded
    resources. See \l{The Qt Resource System} overview for details
    on how to embed images and other resource files in the
    application's executable.

    Simply call the save() function to save a QImage object.

    The complete list of supported file formats are available through
    the QImageReader::supportedImageFormats() and
    QImageWriter::supportedImageFormats() functions. New file formats
    can be added as plugins. By default, Qt supports the following
    formats:

    \table
    \header \li Format \li Description                      \li Qt's support
    \row    \li BMP    \li Windows Bitmap                   \li Read/write
    \row    \li GIF    \li Graphic Interchange Format (optional) \li Read
    \row    \li JPG    \li Joint Photographic Experts Group \li Read/write
    \row    \li JPEG   \li Joint Photographic Experts Group \li Read/write
    \row    \li PNG    \li Portable Network Graphics        \li Read/write
    \row    \li PBM    \li Portable Bitmap                  \li Read
    \row    \li PGM    \li Portable Graymap                 \li Read
    \row    \li PPM    \li Portable Pixmap                  \li Read/write
    \row    \li XBM    \li X11 Bitmap                       \li Read/write
    \row    \li XPM    \li X11 Pixmap                       \li Read/write
    \endtable

    \section1 Image Information

    QImage provides a collection of functions that can be used to
    obtain a variety of information about the image:

    \table
    \header
    \li \li Available Functions

    \row
    \li Geometry
    \li

    The size(), width(), height(), dotsPerMeterX(), and
    dotsPerMeterY() functions provide information about the image size
    and aspect ratio.

    The rect() function returns the image's enclosing rectangle. The
    valid() function tells if a given pair of coordinates is within
    this rectangle. The offset() function returns the number of pixels
    by which the image is intended to be offset by when positioned
    relative to other images, which also can be manipulated using the
    setOffset() function.

    \row
    \li Colors
    \li

    The color of a pixel can be retrieved by passing its coordinates
    to the pixel() function.  The pixel() function returns the color
    as a QRgb value independent of the image's format.

    In case of monochrome and 8-bit images, the colorCount() and
    colorTable() functions provide information about the color
    components used to store the image data: The colorTable() function
    returns the image's entire color table. To obtain a single entry,
    use the pixelIndex() function to retrieve the pixel index for a
    given pair of coordinates, then use the color() function to
    retrieve the color. Note that if you create an 8-bit image
    manually, you have to set a valid color table on the image as
    well.

    The hasAlphaChannel() function tells if the image's format
    respects the alpha channel, or not. The allGray() and
    isGrayscale() functions tell whether an image's colors are all
    shades of gray.

    See also the \l {QImage#Pixel Manipulation}{Pixel Manipulation}
    and \l {QImage#Image Transformations}{Image Transformations}
    sections.

    \row
    \li Text
    \li

    The text() function returns the image text associated with the
    given text key. An image's text keys can be retrieved using the
    textKeys() function. Use the setText() function to alter an
    image's text.

    \row
    \li Low-level information
    \li

    The depth() function returns the depth of the image. The supported
    depths are 1 (monochrome), 8, 16, 24 and 32 bits. The
    bitPlaneCount() function tells how many of those bits that are
    used. For more information see the
    \l {QImage#Image Formats}{Image Formats} section.

    The format(), bytesPerLine(), and sizeInBytes() functions provide
    low-level information about the data stored in the image.

    The cacheKey() function returns a number that uniquely
    identifies the contents of this QImage object.
    \endtable

    \section1 Pixel Manipulation

    The functions used to manipulate an image's pixels depend on the
    image format. The reason is that monochrome and 8-bit images are
    index-based and use a color lookup table, while 32-bit images
    store ARGB values directly. For more information on image formats,
    see the \l {Image Formats} section.

    In case of a 32-bit image, the setPixel() function can be used to
    alter the color of the pixel at the given coordinates to any other
    color specified as an ARGB quadruplet. To make a suitable QRgb
    value, use the qRgb() (adding a default alpha component to the
    given RGB values, i.e. creating an opaque color) or qRgba()
    function. For example:

    \table
    \header
    \li {2,1}32-bit
    \row
    \li \inlineimage qimage-32bit_scaled.png
    \li
    \snippet code/src_gui_image_qimage.cpp 0
    \endtable

    In case of a 8-bit and monchrome images, the pixel value is only
    an index from the image's color table. So the setPixel() function
    can only be used to alter the color of the pixel at the given
    coordinates to a predefined color from the image's color table,
    i.e. it can only change the pixel's index value. To alter or add a
    color to an image's color table, use the setColor() function.

    An entry in the color table is an ARGB quadruplet encoded as an
    QRgb value. Use the qRgb() and qRgba() functions to make a
    suitable QRgb value for use with the setColor() function. For
    example:

    \table
    \header
    \li {2,1} 8-bit
    \row
    \li \inlineimage qimage-8bit_scaled.png
    \li
    \snippet code/src_gui_image_qimage.cpp 1
    \endtable

    For images with more than 8-bit per color-channel. The methods
    setPixelColor() and pixelColor() can be used to set and get
    with QColor values.

    QImage also provide the scanLine() function which returns a
    pointer to the pixel data at the scanline with the given index,
    and the bits() function which returns a pointer to the first pixel
    data (this is equivalent to \c scanLine(0)).

    \section1 Image Formats

    Each pixel stored in a QImage is represented by an integer. The
    size of the integer varies depending on the format. QImage
    supports several image formats described by the \l Format
    enum.

    Monochrome images are stored using 1-bit indexes into a color table
    with at most two colors. There are two different types of
    monochrome images: big endian (MSB first) or little endian (LSB
    first) bit order.

    8-bit images are stored using 8-bit indexes into a color table,
    i.e.  they have a single byte per pixel. The color table is a
    QList<QRgb>, and the QRgb typedef is equivalent to an unsigned
    int containing an ARGB quadruplet on the format 0xAARRGGBB.

    32-bit images have no color table; instead, each pixel contains an
    QRgb value. There are three different types of 32-bit images
    storing RGB (i.e. 0xffRRGGBB), ARGB and premultiplied ARGB
    values respectively. In the premultiplied format the red, green,
    and blue channels are multiplied by the alpha component divided by
    255.

    An image's format can be retrieved using the format()
    function. Use the convertToFormat() functions to convert an image
    into another format. The allGray() and isGrayscale() functions
    tell whether a color image can safely be converted to a grayscale
    image.

    \section1 Image Transformations

    QImage supports a number of functions for creating a new image
    that is a transformed version of the original: The
    createAlphaMask() function builds and returns a 1-bpp mask from
    the alpha buffer in this image, and the createHeuristicMask()
    function creates and returns a 1-bpp heuristic mask for this
    image. The latter function works by selecting a color from one of
    the corners, then chipping away pixels of that color starting at
    all the edges.

    The mirrored() function returns a mirror of the image in the
    desired direction, the scaled() returns a copy of the image scaled
    to a rectangle of the desired measures, and the rgbSwapped() function
    constructs a BGR image from a RGB image.

    The scaledToWidth() and scaledToHeight() functions return scaled
    copies of the image.

    The transformed() function returns a copy of the image that is
    transformed with the given transformation matrix and
    transformation mode: Internally, the transformation matrix is
    adjusted to compensate for unwanted translation,
    i.e. transformed() returns the smallest image containing all
    transformed points of the original image. The static trueMatrix()
    function returns the actual matrix used for transforming the
    image.

    There are also functions for changing attributes of an image
    in-place:

    \table
    \header \li Function \li Description
    \row
    \li setDotsPerMeterX()
    \li Defines the aspect ratio by setting the number of pixels that fit
    horizontally in a physical meter.
    \row
    \li setDotsPerMeterY()
    \li Defines the aspect ratio by setting the number of pixels that fit
    vertically in a physical meter.
    \row
    \li fill()
    \li Fills the entire image with the given pixel value.
    \row
    \li invertPixels()
    \li Inverts all pixel values in the image using the given InvertMode value.
    \row
    \li setColorTable()
    \li Sets the color table used to translate color indexes. Only
    monochrome and 8-bit formats.
    \row
    \li setColorCount()
    \li Resizes the color table. Only monochrome and 8-bit formats.

    \endtable

    \sa QImageReader, QImageWriter, QPixmap, QSvgRenderer,
        {Image Composition Example}, {Scribble Example}
*/

/*!
    \fn QImage::QImage(QImage &&other)

    Move-constructs a QImage instance, making it point at the same
    object that \a other was pointing to.

    \since 5.2
*/

/*!
    \fn QImage &QImage::operator=(QImage &&other)

    Move-assigns \a other to this QImage instance.

    \since 5.2
*/

/*!
    \typedef QImageCleanupFunction
    \relates QImage
    \since 5.0

    A function with the following signature that can be used to
    implement basic image memory management:

    \code
    void myImageCleanupHandler(void *info);
    \endcode
*/

/*!
    \enum QImage::InvertMode

    This enum type is used to describe how pixel values should be
    inverted in the invertPixels() function.

    \value InvertRgb    Invert only the RGB values and leave the alpha
                        channel unchanged.

    \value InvertRgba   Invert all channels, including the alpha channel.

    \sa invertPixels()
*/

/*!
    \enum QImage::Format

    The following image formats are available in Qt.
    See the notes after the table.

    \value Format_Invalid   The image is invalid.
    \value Format_Mono      The image is stored using 1-bit per pixel. Bytes are
                            packed with the most significant bit (MSB) first.
    \value Format_MonoLSB   The image is stored using 1-bit per pixel. Bytes are
                            packed with the less significant bit (LSB) first.

    \value Format_Indexed8  The image is stored using 8-bit indexes
                            into a colormap.

    \value Format_RGB32     The image is stored using a 32-bit RGB format (0xffRRGGBB).

    \value Format_ARGB32    The image is stored using a 32-bit ARGB
                            format (0xAARRGGBB).

    \value Format_ARGB32_Premultiplied  The image is stored using a premultiplied 32-bit
                            ARGB format (0xAARRGGBB), i.e. the red,
                            green, and blue channels are multiplied
                            by the alpha component divided by 255. (If RR, GG, or BB
                            has a higher value than the alpha channel, the results are
                            undefined.) Certain operations (such as image composition
                            using alpha blending) are faster using premultiplied ARGB32
                            than with plain ARGB32.

    \value Format_RGB16     The image is stored using a 16-bit RGB format (5-6-5).

    \value Format_ARGB8565_Premultiplied  The image is stored using a
                            premultiplied 24-bit ARGB format (8-5-6-5).
    \value Format_RGB666    The image is stored using a 24-bit RGB format (6-6-6).
                            The unused most significant bits is always zero.
    \value Format_ARGB6666_Premultiplied  The image is stored using a
                            premultiplied 24-bit ARGB format (6-6-6-6).
    \value Format_RGB555    The image is stored using a 16-bit RGB format (5-5-5).
                            The unused most significant bit is always zero.
    \value Format_ARGB8555_Premultiplied  The image is stored using a
                            premultiplied 24-bit ARGB format (8-5-5-5).
    \value Format_RGB888    The image is stored using a 24-bit RGB format (8-8-8).
    \value Format_RGB444    The image is stored using a 16-bit RGB format (4-4-4).
                            The unused bits are always zero.
    \value Format_ARGB4444_Premultiplied  The image is stored using a
                            premultiplied 16-bit ARGB format (4-4-4-4).
    \value [since 5.2]
           Format_RGBX8888   The image is stored using a 32-bit byte-ordered RGB(x) format (8-8-8-8).
                             This is the same as the Format_RGBA8888 except alpha must always be 255.
    \value [since 5.2]
           Format_RGBA8888   The image is stored using a 32-bit byte-ordered RGBA format (8-8-8-8).
                             Unlike ARGB32 this is a byte-ordered format, which means the 32bit
                             encoding differs between big endian and little endian architectures,
                             being respectively (0xRRGGBBAA) and (0xAABBGGRR). The order of the colors
                             is the same on any architecture if read as bytes 0xRR,0xGG,0xBB,0xAA.
    \value [since 5.2]
           Format_RGBA8888_Premultiplied    The image is stored using a
                            premultiplied 32-bit byte-ordered RGBA format (8-8-8-8).
    \value [since 5.4]
           Format_BGR30      The image is stored using a 32-bit BGR format (x-10-10-10).
    \value [since 5.4]
           Format_A2BGR30_Premultiplied    The image is stored using a 32-bit premultiplied ABGR format (2-10-10-10).
    \value [since 5.4]
           Format_RGB30      The image is stored using a 32-bit RGB format (x-10-10-10).
    \value [since 5.4]
           Format_A2RGB30_Premultiplied    The image is stored using a 32-bit premultiplied ARGB format (2-10-10-10).
    \value [since 5.5]
           Format_Alpha8     The image is stored using an 8-bit alpha only format.
    \value [since 5.5]
           Format_Grayscale8 The image is stored using an 8-bit grayscale format.
    \value [since 5.13]
           Format_Grayscale16 The image is stored using an 16-bit grayscale format.
    \value [since 5.12]
           Format_RGBX64     The image is stored using a 64-bit halfword-ordered RGB(x) format (16-16-16-16).
                             This is the same as the Format_RGBA64 except alpha must always be 65535.
    \value [since 5.12]
           Format_RGBA64     The image is stored using a 64-bit halfword-ordered RGBA format (16-16-16-16).
    \value [since 5.12]
           Format_RGBA64_Premultiplied    The image is stored using a premultiplied 64-bit halfword-ordered
                             RGBA format (16-16-16-16).
    \value [since 5.14]
           Format_BGR888     The image is stored using a 24-bit BGR format.
    \value [since 6.2]
           Format_RGBX16FPx4 The image is stored using a four 16-bit halfword floating point RGBx format (16FP-16FP-16FP-16FP).
                             This is the same as the Format_RGBA16FPx4 except alpha must always be 1.0.
    \value [since 6.2]
           Format_RGBA16FPx4 The image is stored using a four 16-bit halfword floating point RGBA format (16FP-16FP-16FP-16FP).
    \value [since 6.2]
           Format_RGBA16FPx4_Premultiplied    The image is stored using a premultiplied four 16-bit halfword floating point
                             RGBA format (16FP-16FP-16FP-16FP).
    \value [since 6.2]
           Format_RGBX32FPx4 The image is stored using a four 32-bit floating point RGBx format (32FP-32FP-32FP-32FP).
                             This is the same as the Format_RGBA32FPx4 except alpha must always be 1.0.
    \value [since 6.2]
           Format_RGBA32FPx4 The image is stored using a four 32-bit floating point RGBA format (32FP-32FP-32FP-32FP).
    \value [since 6.2]
           Format_RGBA32FPx4_Premultiplied    The image is stored using a premultiplied four 32-bit floating point
                             RGBA format (32FP-32FP-32FP-32FP).
    \value [since 6.8]
           Format_CMYK8888   The image is stored using a 32-bit byte-ordered CMYK format.

    \note Drawing into a QImage with format QImage::Format_Indexed8 or QImage::Format_CMYK8888 is not
    supported.

    \note Avoid most rendering directly to most of these formats using QPainter. Rendering
    is best optimized to the \c Format_RGB32 and \c Format_ARGB32_Premultiplied formats, and secondarily for rendering to the
    \c Format_RGB16, \c Format_RGBX8888, \c Format_RGBA8888_Premultiplied, \c Format_RGBX64 and \c Format_RGBA64_Premultiplied formats

    \sa format(), convertToFormat()
*/

/*****************************************************************************
  QImage member functions
 *****************************************************************************/

/*!
    Constructs a null image.

    \sa isNull()
*/

QImage::QImage() noexcept
    : QPaintDevice()
{
    d = nullptr;
}

/*!
    Constructs an image with the given \a width, \a height and \a
    format.

    A \l{isNull()}{null} image will be returned if memory cannot be allocated.

    \warning This will create a QImage with uninitialized data. Call
    fill() to fill the image with an appropriate pixel value before
    drawing onto it with QPainter.
*/
QImage::QImage(int width, int height, Format format)
    : QImage(QSize(width, height), format)
{
}

/*!
    Constructs an image with the given \a size and \a format.

    A \l{isNull()}{null} image is returned if memory cannot be allocated.

    \warning This will create a QImage with uninitialized data. Call
    fill() to fill the image with an appropriate pixel value before
    drawing onto it with QPainter.
*/
QImage::QImage(const QSize &size, Format format)
    : QPaintDevice()
{
    d = QImageData::create(size, format);
}



QImageData *QImageData::create(uchar *data, int width, int height,  qsizetype bpl, QImage::Format format, bool readOnly, QImageCleanupFunction cleanupFunction, void *cleanupInfo)
{
    if (width <= 0 || height <= 0 || !data || format <= QImage::Format_Invalid || format >= QImage::NImageFormats)
        return nullptr;

    const int depth = qt_depthForFormat(format);
    auto params = calculateImageParameters(width, height, depth);
    if (!params.isValid())
        return nullptr;

    if (bpl > 0) {
        // can't overflow, because has calculateImageParameters already done this multiplication
        const qsizetype min_bytes_per_line = (qsizetype(width) * depth + 7)/8;
        if (bpl < min_bytes_per_line)
            return nullptr;

        // recalculate the total with this value
        params.bytesPerLine = bpl;
        if (qMulOverflow<qsizetype>(bpl, height, &params.totalSize))
            return nullptr;
    }

    QImageData *d = new QImageData;
    d->ref.ref();

    d->own_data = false;
    d->ro_data = readOnly;
    d->data = data;
    d->width = width;
    d->height = height;
    d->depth = depth;
    d->format = format;

    d->bytes_per_line = params.bytesPerLine;
    d->nbytes = params.totalSize;

    d->cleanupFunction = cleanupFunction;
    d->cleanupInfo = cleanupInfo;

    return d;
}

/*!
    Constructs an image with the given \a width, \a height and \a
    format, that uses an existing memory buffer, \a data. The \a width
    and \a height must be specified in pixels, \a data must be 32-bit aligned,
    and each scanline of data in the image must also be 32-bit aligned.

    The buffer must remain valid throughout the life of the QImage and
    all copies that have not been modified or otherwise detached from
    the original buffer. The image does not delete the buffer at destruction.
    You can provide a function pointer \a cleanupFunction along with an
    extra pointer \a cleanupInfo that will be called when the last copy
    is destroyed.

    If \a format is an indexed color format, the image color table is
    initially empty and must be sufficiently expanded with
    setColorCount() or setColorTable() before the image is used.
*/
QImage::QImage(uchar* data, int width, int height, Format format, QImageCleanupFunction cleanupFunction, void *cleanupInfo)
    : QPaintDevice()
{
    d = QImageData::create(data, width, height, 0, format, false, cleanupFunction, cleanupInfo);
}

/*!
    Constructs an image with the given \a width, \a height and \a
    format, that uses an existing read-only memory buffer, \a
    data. The \a width and \a height must be specified in pixels, \a
    data must be 32-bit aligned, and each scanline of data in the
    image must also be 32-bit aligned.

    The buffer must remain valid throughout the life of the QImage and
    all copies that have not been modified or otherwise detached from
    the original buffer. The image does not delete the buffer at destruction.
    You can provide a function pointer \a cleanupFunction along with an
    extra pointer \a cleanupInfo that will be called when the last copy
    is destroyed.

    If \a format is an indexed color format, the image color table is
    initially empty and must be sufficiently expanded with
    setColorCount() or setColorTable() before the image is used.

    Unlike the similar QImage constructor that takes a non-const data buffer,
    this version will never alter the contents of the buffer.  For example,
    calling QImage::bits() will return a deep copy of the image, rather than
    the buffer passed to the constructor.  This allows for the efficiency of
    constructing a QImage from raw data, without the possibility of the raw
    data being changed.
*/
QImage::QImage(const uchar* data, int width, int height, Format format, QImageCleanupFunction cleanupFunction, void *cleanupInfo)
    : QPaintDevice()
{
    d = QImageData::create(const_cast<uchar*>(data), width, height, 0, format, true, cleanupFunction, cleanupInfo);
}

/*!
    Constructs an image with the given \a width, \a height and \a
    format, that uses an existing memory buffer, \a data. The \a width
    and \a height must be specified in pixels. \a bytesPerLine
    specifies the number of bytes per line (stride).

    The buffer must remain valid throughout the life of the QImage and
    all copies that have not been modified or otherwise detached from
    the original buffer. The image does not delete the buffer at destruction.
    You can provide a function pointer \a cleanupFunction along with an
    extra pointer \a cleanupInfo that will be called when the last copy
    is destroyed.

    If \a format is an indexed color format, the image color table is
    initially empty and must be sufficiently expanded with
    setColorCount() or setColorTable() before the image is used.
*/

QImage::QImage(uchar *data, int width, int height, qsizetype bytesPerLine, Format format, QImageCleanupFunction cleanupFunction, void *cleanupInfo)
    :QPaintDevice()
{
    d = QImageData::create(data, width, height, bytesPerLine, format, false, cleanupFunction, cleanupInfo);
}

/*!
    Constructs an image with the given \a width, \a height and \a
    format, that uses an existing memory buffer, \a data. The \a width
    and \a height must be specified in pixels. \a bytesPerLine
    specifies the number of bytes per line (stride).

    The buffer must remain valid throughout the life of the QImage and
    all copies that have not been modified or otherwise detached from
    the original buffer. The image does not delete the buffer at destruction.
    You can provide a function pointer \a cleanupFunction along with an
    extra pointer \a cleanupInfo that will be called when the last copy
    is destroyed.

    If \a format is an indexed color format, the image color table is
    initially empty and must be sufficiently expanded with
    setColorCount() or setColorTable() before the image is used.

    Unlike the similar QImage constructor that takes a non-const data buffer,
    this version will never alter the contents of the buffer.  For example,
    calling QImage::bits() will return a deep copy of the image, rather than
    the buffer passed to the constructor.  This allows for the efficiency of
    constructing a QImage from raw data, without the possibility of the raw
    data being changed.
*/

QImage::QImage(const uchar *data, int width, int height, qsizetype bytesPerLine, Format format, QImageCleanupFunction cleanupFunction, void *cleanupInfo)
    :QPaintDevice()
{
    d = QImageData::create(const_cast<uchar*>(data), width, height, bytesPerLine, format, true, cleanupFunction, cleanupInfo);
}

/*!
    Constructs an image and tries to load the image from the file with
    the given \a fileName.

    The loader attempts to read the image using the specified \a
    format. If the \a format is not specified (which is the default),
    it is auto-detected based on the file's suffix and header. For
    details, see {QImageReader::setAutoDetectImageFormat()}{QImageReader}.

    If the loading of the image failed, this object is a null image.

    The file name can either refer to an actual file on disk or to one
    of the application's embedded resources. See the
    \l{resources.html}{Resource System} overview for details on how to
    embed images and other resource files in the application's
    executable.

    \sa isNull(), {QImage#Reading and Writing Image Files}{Reading and Writing Image Files}
*/

QImage::QImage(const QString &fileName, const char *format)
    : QPaintDevice()
{
    d = nullptr;
    load(fileName, format);
}

#ifndef QT_NO_IMAGEFORMAT_XPM
extern bool qt_read_xpm_image_or_array(QIODevice *device, const char * const *source, QImage &image);

/*!
    Constructs an image from the given \a xpm image.

    Make sure that the image is a valid XPM image. Errors are silently
    ignored.

    Note that it's possible to squeeze the XPM variable a little bit
    by using an unusual declaration:

    \snippet code/src_gui_image_qimage.cpp 2

    The extra \c const makes the entire definition read-only, which is
    slightly more efficient (e.g., when the code is in a shared
    library) and able to be stored in ROM with the application.
*/

QImage::QImage(const char * const xpm[])
    : QPaintDevice()
{
    d = nullptr;
    if (!xpm)
        return;
    if (!qt_read_xpm_image_or_array(nullptr, xpm, *this))
        // Issue: Warning because the constructor may be ambiguous
        qWarning("QImage::QImage(), XPM is not supported");
}
#endif // QT_NO_IMAGEFORMAT_XPM

/*!
    Constructs a shallow copy of the given \a image.

    For more information about shallow copies, see the \l {Implicit
    Data Sharing} documentation.

    \sa copy()
*/

QImage::QImage(const QImage &image)
    : QPaintDevice()
{
    if (image.paintingActive()) {
        d = nullptr;
        image.copy().swap(*this);
    } else {
        d = image.d;
        if (d)
            d->ref.ref();
    }
}

/*!
    Destroys the image and cleans up.
*/

QImage::~QImage()
{
    if (d && !d->ref.deref())
        delete d;
}

/*!
    Assigns a shallow copy of the given \a image to this image and
    returns a reference to this image.

    For more information about shallow copies, see the \l {Implicit
    Data Sharing} documentation.

    \sa copy(), QImage()
*/

QImage &QImage::operator=(const QImage &image)
{
    if (image.paintingActive()) {
        operator=(image.copy());
    } else {
        if (image.d)
            image.d->ref.ref();
        if (d && !d->ref.deref())
            delete d;
        d = image.d;
    }
    return *this;
}

/*!
    \fn void QImage::swap(QImage &other)
    \memberswap{image}
*/

/*!
  \internal
*/
int QImage::devType() const
{
    return QInternal::Image;
}

/*!
   Returns the image as a QVariant.
*/
QImage::operator QVariant() const
{
    return QVariant::fromValue(*this);
}

/*!
    \internal

    If multiple images share common data, this image makes a copy of
    the data and detaches itself from the sharing mechanism, making
    sure that this image is the only one referring to the data.

    Nothing is done if there is just a single reference.

    \sa copy(), {QImage::isDetached()}{isDetached()}, {Implicit Data Sharing}
*/
void QImage::detach()
{
    if (d) {
        if (d->is_cached && d->ref.loadRelaxed() == 1)
            QImagePixmapCleanupHooks::executeImageHooks(cacheKey());

        if (d->ref.loadRelaxed() != 1 || d->ro_data)
            *this = copy();

        if (d)
            ++d->detach_no;
    }
}


/*!
    \internal

    A variant for metadata-only detach, which will not detach readonly image data,
    and only invalidate caches of the image data if asked to.

    \sa detach(), isDetached()
*/
void QImage::detachMetadata(bool invalidateCache)
{
    if (d) {
        if (d->is_cached && d->ref.loadRelaxed() == 1)
            QImagePixmapCleanupHooks::executeImageHooks(cacheKey());

        if (d->ref.loadRelaxed() != 1)
            *this = copy();

        if (d && invalidateCache)
            ++d->detach_no;
    }
}

static void copyPhysicalMetadata(QImageData *dst, const QImageData *src)
{
    dst->dpmx = src->dpmx;
    dst->dpmy = src->dpmy;
    dst->devicePixelRatio = src->devicePixelRatio;
}

static void copyMetadata(QImageData *dst, const QImageData *src)
{
    // Doesn't copy colortable and alpha_clut.
    copyPhysicalMetadata(dst, src);
    dst->text = src->text;
    dst->offset = src->offset;
    dst->colorSpace = src->colorSpace;
}

static void copyMetadata(QImage *dst, const QImage &src)
{
    dst->setDotsPerMeterX(src.dotsPerMeterX());
    dst->setDotsPerMeterY(src.dotsPerMeterY());
    dst->setDevicePixelRatio(src.devicePixelRatio());
    const auto textKeys = src.textKeys();
    for (const auto &key: textKeys)
        dst->setText(key, src.text(key));

}

/*!
    \fn QImage QImage::copy(int x, int y, int width, int height) const
    \overload

    The returned image is copied from the position (\a x, \a y) in
    this image, and will always have the given \a width and \a height.
    In areas beyond this image, pixels are set to 0.

*/

/*!
    \fn QImage QImage::copy(const QRect& rectangle) const

    Returns a sub-area of the image as a new image.

    The returned image is copied from the position (\a
    {rectangle}.x(), \a{rectangle}.y()) in this image, and will always
    have the size of the given \a rectangle.

    In areas beyond this image, pixels are set to 0. For 32-bit RGB
    images, this means black; for 32-bit ARGB images, this means
    transparent black; for 8-bit images, this means the color with
    index 0 in the color table which can be anything; for 1-bit
    images, this means Qt::color0.

    If the given \a rectangle is a null rectangle the entire image is
    copied.

    \sa QImage()
*/
QImage Q_TRACE_INSTRUMENT(qtgui) QImage::copy(const QRect& r) const
{
    Q_TRACE_SCOPE(QImage_copy, r);
    if (!d)
        return QImage();

    if (r.isNull()) {
        QImage image(d->width, d->height, d->format);
        if (image.isNull())
            return image;

        // Qt for Embedded Linux can create images with non-default bpl
        // make sure we don't crash.
        if (image.d->nbytes != d->nbytes) {
            qsizetype bpl = qMin(bytesPerLine(), image.bytesPerLine());
            for (int i = 0; i < height(); i++)
                memcpy(image.scanLine(i), scanLine(i), bpl);
        } else
            memcpy(image.bits(), bits(), d->nbytes);
        image.d->colortable = d->colortable;
        image.d->has_alpha_clut = d->has_alpha_clut;
        copyMetadata(image.d, d);
        return image;
    }

    int x = r.x();
    int y = r.y();
    int w = r.width();
    int h = r.height();

    int dx = 0;
    int dy = 0;
    if (w <= 0 || h <= 0)
        return QImage();

    QImage image(w, h, d->format);
    if (image.isNull())
        return image;

    if (x < 0 || y < 0 || x + w > d->width || y + h > d->height) {
        // bitBlt will not cover entire image - clear it.
        image.fill(0);
        if (x < 0) {
            dx = -x;
            x = 0;
        }
        if (y < 0) {
            dy = -y;
            y = 0;
        }
    }

    image.d->colortable = d->colortable;

    int pixels_to_copy = qMax(w - dx, 0);
    if (x > d->width)
        pixels_to_copy = 0;
    else if (pixels_to_copy > d->width - x)
        pixels_to_copy = d->width - x;
    int lines_to_copy = qMax(h - dy, 0);
    if (y > d->height)
        lines_to_copy = 0;
    else if (lines_to_copy > d->height - y)
        lines_to_copy = d->height - y;

    bool byteAligned = true;
    if (d->format == Format_Mono || d->format == Format_MonoLSB)
        byteAligned = !(dx & 7) && !(x & 7) && !(pixels_to_copy & 7);

    if (byteAligned) {
        const uchar *src = d->data + ((x * d->depth) >> 3) + y * d->bytes_per_line;
        uchar *dest = image.d->data + ((dx * d->depth) >> 3) + dy * image.d->bytes_per_line;
        const qsizetype bytes_to_copy = (qsizetype(pixels_to_copy) * d->depth) >> 3;
        for (int i = 0; i < lines_to_copy; ++i) {
            memcpy(dest, src, bytes_to_copy);
            src += d->bytes_per_line;
            dest += image.d->bytes_per_line;
        }
    } else if (d->format == Format_Mono) {
        const uchar *src = d->data + y * d->bytes_per_line;
        uchar *dest = image.d->data + dy * image.d->bytes_per_line;
        for (int i = 0; i < lines_to_copy; ++i) {
            for (int j = 0; j < pixels_to_copy; ++j) {
                if (src[(x + j) >> 3] & (0x80 >> ((x + j) & 7)))
                    dest[(dx + j) >> 3] |= (0x80 >> ((dx + j) & 7));
                else
                    dest[(dx + j) >> 3] &= ~(0x80 >> ((dx + j) & 7));
            }
            src += d->bytes_per_line;
            dest += image.d->bytes_per_line;
        }
    } else { // Format_MonoLSB
        Q_ASSERT(d->format == Format_MonoLSB);
        const uchar *src = d->data + y * d->bytes_per_line;
        uchar *dest = image.d->data + dy * image.d->bytes_per_line;
        for (int i = 0; i < lines_to_copy; ++i) {
            for (int j = 0; j < pixels_to_copy; ++j) {
                if (src[(x + j) >> 3] & (0x1 << ((x + j) & 7)))
                    dest[(dx + j) >> 3] |= (0x1 << ((dx + j) & 7));
                else
                    dest[(dx + j) >> 3] &= ~(0x1 << ((dx + j) & 7));
            }
            src += d->bytes_per_line;
            dest += image.d->bytes_per_line;
        }
    }

    copyMetadata(image.d, d);
    image.d->has_alpha_clut = d->has_alpha_clut;
    return image;
}


/*!
    \fn bool QImage::isNull() const

    Returns \c true if it is a null image, otherwise returns \c false.

    A null image has all parameters set to zero and no allocated data.
*/
bool QImage::isNull() const
{
    return !d;
}

/*!
    \fn int QImage::width() const

    Returns the width of the image.

    \sa {QImage#Image Information}{Image Information}
*/
int QImage::width() const
{
    return d ? d->width : 0;
}

/*!
    \fn int QImage::height() const

    Returns the height of the image.

    \sa {QImage#Image Information}{Image Information}
*/
int QImage::height() const
{
    return d ? d->height : 0;
}

/*!
    \fn QSize QImage::size() const

    Returns the size of the image, i.e. its width() and height().

    \sa {QImage#Image Information}{Image Information}, deviceIndependentSize()
*/
QSize QImage::size() const
{
    return d ? QSize(d->width, d->height) : QSize(0, 0);
}

/*!
    \fn QRect QImage::rect() const

    Returns the enclosing rectangle (0, 0, width(), height()) of the
    image.

    \sa {QImage#Image Information}{Image Information}
*/
QRect QImage::rect() const
{
    return d ? QRect(0, 0, d->width, d->height) : QRect();
}

/*!
    Returns the depth of the image.

    The image depth is the number of bits used to store a single
    pixel, also called bits per pixel (bpp).

    The supported depths are 1, 8, 16, 24, 32 and 64.

    \sa bitPlaneCount(), convertToFormat(), {QImage#Image Formats}{Image Formats},
    {QImage#Image Information}{Image Information}

*/
int QImage::depth() const
{
    return d ? d->depth : 0;
}

/*!
    \fn int QImage::colorCount() const

    Returns the size of the color table for the image.

    Notice that colorCount() returns 0 for 32-bpp images because these
    images do not use color tables, but instead encode pixel values as
    ARGB quadruplets.

    \sa setColorCount(), {QImage#Image Information}{Image Information}
*/
int QImage::colorCount() const
{
    return d ? d->colortable.size() : 0;
}

/*!
    Sets the color table used to translate color indexes to QRgb
    values, to the specified \a colors.

    When the image is used, the color table must be large enough to
    have entries for all the pixel/index values present in the image,
    otherwise the results are undefined.

    \sa colorTable(), setColor(), {QImage#Image Transformations}{Image
    Transformations}
*/
void QImage::setColorTable(const QList<QRgb> &colors)
{
    if (!d)
        return;
    detachMetadata(true);

    // In case detach() ran out of memory
    if (!d)
        return;

    d->colortable = colors;
    d->has_alpha_clut = false;
    for (int i = 0; i < d->colortable.size(); ++i) {
        if (qAlpha(d->colortable.at(i)) != 255) {
            d->has_alpha_clut = true;
            break;
        }
    }
}

/*!
    Returns a list of the colors contained in the image's color table,
    or an empty list if the image does not have a color table

    \sa setColorTable(), colorCount(), color()
*/
QList<QRgb> QImage::colorTable() const
{
    return d ? d->colortable : QList<QRgb>();
}

/*!
    Returns the device pixel ratio for the image. This is the
    ratio between \e{device pixels} and \e{device independent pixels}.

    Use this function when calculating layout geometry based on
    the image size: QSize layoutSize = image.size() / image.devicePixelRatio()

    The default value is 1.0.

    \sa setDevicePixelRatio(), QImageReader
*/
qreal QImage::devicePixelRatio() const
{
    if (!d)
        return 1.0;
    return d->devicePixelRatio;
}

/*!
    Sets the device pixel ratio for the image. This is the
    ratio between image pixels and device-independent pixels.

    The default \a scaleFactor is 1.0. Setting it to something else has
    two effects:

    QPainters that are opened on the image will be scaled. For
    example, painting on a 200x200 image if with a ratio of 2.0
    will result in effective (device-independent) painting bounds
    of 100x100.

    Code paths in Qt that calculate layout geometry based on the
    image size will take the ratio into account:
    QSize layoutSize = image.size() / image.devicePixelRatio()
    The net effect of this is that the image is displayed as
    high-DPI image rather than a large image
    (see \l{Drawing High Resolution Versions of Pixmaps and Images}).

    \sa devicePixelRatio(), deviceIndependentSize()
*/
void QImage::setDevicePixelRatio(qreal scaleFactor)
{
    if (!d)
        return;

    if (scaleFactor == d->devicePixelRatio)
        return;

    detachMetadata();
    if (d)
        d->devicePixelRatio = scaleFactor;
}

/*!
    Returns the size of the image in device independent pixels.

    This value should be used when using the image size in user interface
    size calculations.

    The return value is equivalent to image.size() / image.devicePixelRatio().

    \since 6.2
*/
QSizeF QImage::deviceIndependentSize() const
{
    if (!d)
        return QSizeF(0, 0);
    return QSizeF(d->width, d->height) / d->devicePixelRatio;
}


/*!
    \since 5.10
    Returns the image data size in bytes.

    \sa bytesPerLine(), bits(), {QImage#Image Information}{Image
    Information}
*/
qsizetype QImage::sizeInBytes() const
{
    return d ? d->nbytes : 0;
}

/*!
    Returns the number of bytes per image scanline.

    This is equivalent to sizeInBytes() / height() if height() is non-zero.

    \sa scanLine()
*/
qsizetype QImage::bytesPerLine() const
{
    return d ? d->bytes_per_line : 0;
}


/*!
    Returns the color in the color table at index \a i. The first
    color is at index 0.

    The colors in an image's color table are specified as ARGB
    quadruplets (QRgb). Use the qAlpha(), qRed(), qGreen(), and
    qBlue() functions to get the color value components.

    \sa setColor(), pixelIndex(), {QImage#Pixel Manipulation}{Pixel
    Manipulation}
*/
QRgb QImage::color(int i) const
{
    Q_ASSERT(i < colorCount());
    return d ? d->colortable.at(i) : QRgb(uint(-1));
}

/*!
    \fn void QImage::setColor(int index, QRgb colorValue)

    Sets the color at the given \a index in the color table, to the
    given to \a colorValue. The color value is an ARGB quadruplet.

    If \a index is outside the current size of the color table, it is
    expanded with setColorCount().

    \sa color(), colorCount(), setColorTable(), {QImage#Pixel Manipulation}{Pixel
    Manipulation}
*/
void QImage::setColor(int i, QRgb c)
{
    if (!d)
        return;
    if (i < 0 || d->depth > 8 || i >= 1<<d->depth) {
        qWarning("QImage::setColor: Index out of bound %d", i);
        return;
    }
    detachMetadata(true);

    // In case detach() run out of memory
    if (!d)
        return;

    if (i >= d->colortable.size())
        setColorCount(i+1);
    d->colortable[i] = c;
    d->has_alpha_clut |= (qAlpha(c) != 255);
}

/*!
    Returns a pointer to the pixel data at the scanline with index \a
    i. The first scanline is at index 0.

    The scanline data is as minimum 32-bit aligned. For 64-bit formats
    it follows the native alignment of 64-bit integers (64-bit for most
    platforms, but notably 32-bit on i386).

    For example, to remove the green component of each pixel in an image:

    \snippet code/src_gui_image_qimage.cpp scanLine

    \warning If you are accessing 32-bpp image data, cast the returned
    pointer to \c{QRgb*} (QRgb has a 32-bit size) and use it to
    read/write the pixel value. You cannot use the \c{uchar*} pointer
    directly, because the pixel format depends on the byte order on
    the underlying platform. Use qRed(), qGreen(), qBlue(), and
    qAlpha() to access the pixels.

    \sa bytesPerLine(), bits(), {QImage#Pixel Manipulation}{Pixel
    Manipulation}, constScanLine()
*/
uchar *QImage::scanLine(int i)
{
    if (!d)
        return nullptr;

    detach();

    // In case detach() ran out of memory
    if (!d)
        return nullptr;

    return d->data + i * d->bytes_per_line;
}

/*!
    \overload
*/
const uchar *QImage::scanLine(int i) const
{
    if (!d)
        return nullptr;

    Q_ASSERT(i >= 0 && i < height());
    return d->data + i * d->bytes_per_line;
}


/*!
    Returns a pointer to the pixel data at the scanline with index \a
    i. The first scanline is at index 0.

    The scanline data is as minimum 32-bit aligned. For 64-bit formats
    it follows the native alignment of 64-bit integers (64-bit for most
    platforms, but notably 32-bit on i386).

    Note that QImage uses \l{Implicit Data Sharing} {implicit data
    sharing}, but this function does \e not perform a deep copy of the
    shared pixel data, because the returned data is const.

    \sa scanLine(), constBits()
*/
const uchar *QImage::constScanLine(int i) const
{
    if (!d)
        return nullptr;

    Q_ASSERT(i >= 0 && i < height());
    return d->data + i * d->bytes_per_line;
}

/*!
    Returns a pointer to the first pixel data. This is equivalent to
    scanLine(0).

    Note that QImage uses \l{Implicit Data Sharing} {implicit data
    sharing}. This function performs a deep copy of the shared pixel
    data, thus ensuring that this QImage is the only one using the
    current return value.

    \sa scanLine(), sizeInBytes(), constBits()
*/
uchar *QImage::bits()
{
    if (!d)
        return nullptr;
    detach();

    // In case detach ran out of memory...
    if (!d)
        return nullptr;

    return d->data;
}

/*!
    \overload

    Note that QImage uses \l{Implicit Data Sharing} {implicit data
    sharing}, but this function does \e not perform a deep copy of the
    shared pixel data, because the returned data is const.
*/
const uchar *QImage::bits() const
{
    return d ? d->data : nullptr;
}


/*!
    Returns a pointer to the first pixel data.

    Note that QImage uses \l{Implicit Data Sharing} {implicit data
    sharing}, but this function does \e not perform a deep copy of the
    shared pixel data, because the returned data is const.

    \sa bits(), constScanLine()
*/
const uchar *QImage::constBits() const
{
    return d ? d->data : nullptr;
}

/*!
    \fn void QImage::fill(uint pixelValue)

    Fills the entire image with the given \a pixelValue.

    If the depth of this image is 1, only the lowest bit is used. If
    you say fill(0), fill(2), etc., the image is filled with 0s. If
    you say fill(1), fill(3), etc., the image is filled with 1s. If
    the depth is 8, the lowest 8 bits are used and if the depth is 16
    the lowest 16 bits are used.

    If the image depth is higher than 32bit the result is undefined.

    \note There are no corresponding value getter, though QImage::pixelIndex()
    will return the same value for indexed formats, and QImage::pixel() for
    RGB32, ARGB32, and ARGB32PM formats.

    \sa depth(), {QImage#Image Transformations}{Image Transformations}
*/

void QImage::fill(uint pixel)
{
    if (!d)
        return;

    detach();

    // In case detach() ran out of memory
    if (!d)
        return;

    if (d->depth == 1 || d->depth == 8) {
        int w = d->width;
        if (d->depth == 1) {
            if (pixel & 1)
                pixel = 0xffffffff;
            else
                pixel = 0;
            w = (w + 7) / 8;
        } else {
            pixel &= 0xff;
        }
        qt_rectfill<quint8>(d->data, pixel, 0, 0,
                            w, d->height, d->bytes_per_line);
        return;
    } else if (d->depth == 16) {
        if (d->format == Format_RGB444)
            pixel |= 0xf000;
        qt_rectfill<quint16>(reinterpret_cast<quint16*>(d->data), pixel,
                             0, 0, d->width, d->height, d->bytes_per_line);
        return;
    } else if (d->depth == 24) {
        if (d->format == Format_RGB666)
            pixel |= 0xfc0000;
        qt_rectfill<quint24>(reinterpret_cast<quint24*>(d->data), pixel,
                             0, 0, d->width, d->height, d->bytes_per_line);
        return;
    } else if (d->format >= QImage::Format_RGBX64 && d->format <= QImage::Format_RGBA64_Premultiplied) {
        qt_rectfill<quint64>(reinterpret_cast<quint64*>(d->data), QRgba64::fromArgb32(pixel),
                             0, 0, d->width, d->height, d->bytes_per_line);
        return;
    } else if (d->format >= QImage::Format_RGBX16FPx4 && d->format <= QImage::Format_RGBA16FPx4_Premultiplied) {
        quint64 cu;
        QRgbaFloat16 cf = QRgbaFloat16::fromArgb32(pixel);
        ::memcpy(&cu, &cf, sizeof(quint64));
        qt_rectfill<quint64>(reinterpret_cast<quint64*>(d->data), cu,
                             0, 0, d->width, d->height, d->bytes_per_line);
        return;
    } else if (d->format >= QImage::Format_RGBX32FPx4 && d->format <= QImage::Format_RGBA32FPx4_Premultiplied) {
        QRgbaFloat32 cf = QRgbaFloat32::fromArgb32(pixel);
        uchar *data = d->data;
        for (int y = 0; y < d->height; ++y) {
            QRgbaFloat32 *line = reinterpret_cast<QRgbaFloat32 *>(data);
            for (int x = 0; x < d->width; ++x)
                line[x] = cf;
            data += d->bytes_per_line;
        }
        return;
    }
    Q_ASSERT(d->depth == 32);

    if (d->format == Format_RGB32)
        pixel |= 0xff000000;
    if (d->format == Format_RGBX8888)
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
        pixel |= 0xff000000;
#else
        pixel |= 0x000000ff;
#endif
    if (d->format == Format_BGR30 || d->format == Format_RGB30)
        pixel |= 0xc0000000;

    qt_rectfill<uint>(reinterpret_cast<uint*>(d->data), pixel,
                      0, 0, d->width, d->height, d->bytes_per_line);
}


/*!
    \fn void QImage::fill(Qt::GlobalColor color)
    \overload

    Fills the image with the given \a color, described as a standard global
    color.
 */

void QImage::fill(Qt::GlobalColor color)
{
    fill(QColor(color));
}



/*!
    \fn void QImage::fill(const QColor &color)

    \overload

    Fills the entire image with the given \a color.

    If the depth of the image is 1, the image will be filled with 1 if
    \a color equals Qt::color1; it will otherwise be filled with 0.

    If the depth of the image is 8, the image will be filled with the
    index corresponding the \a color in the color table if present; it
    will otherwise be filled with 0.
*/

void QImage::fill(const QColor &color)
{
    if (!d)
        return;
    detach();

    // In case we run out of memory
    if (!d)
        return;

    QRgba64 opaque = color.rgba64();
    opaque.setAlpha(65535);
    switch (d->format) {
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32:
        fill(color.rgba());
        break;
    case QImage::Format_ARGB32_Premultiplied:
        fill(qPremultiply(color.rgba()));
        break;
    case QImage::Format_RGBX8888:
        fill(ARGB2RGBA(color.rgba() | 0xff000000));
        break;
    case QImage::Format_RGBA8888:
        fill(ARGB2RGBA(color.rgba()));
        break;
    case QImage::Format_RGBA8888_Premultiplied:
        fill(ARGB2RGBA(qPremultiply(color.rgba())));
        break;
    case QImage::Format_BGR30:
        fill(qConvertRgb64ToRgb30<PixelOrderBGR>(opaque));
        break;
    case QImage::Format_RGB30:
        fill(qConvertRgb64ToRgb30<PixelOrderRGB>(opaque));
        break;
    case QImage::Format_RGB16:
        fill((uint) qConvertRgb32To16(color.rgba()));
        break;
    case QImage::Format_Indexed8: {
        uint pixel = 0;
        for (int i=0; i<d->colortable.size(); ++i) {
            if (color.rgba() == d->colortable.at(i)) {
                pixel = i;
                break;
            }
        }
        fill(pixel);
        break;
    }
    case QImage::Format_Mono:
    case QImage::Format_MonoLSB:
        if (color == Qt::color1)
            fill((uint) 1);
        else
            fill((uint) 0);
        break;
    case QImage::Format_RGBX64:
        qt_rectfill<quint64>(reinterpret_cast<quint64*>(d->data), opaque,
                             0, 0, d->width, d->height, d->bytes_per_line);
        break;
    case QImage::Format_RGBA64:
        qt_rectfill<quint64>(reinterpret_cast<quint64*>(d->data), color.rgba64(),
                             0, 0, d->width, d->height, d->bytes_per_line);
        break;
    case QImage::Format_RGBA64_Premultiplied:
        qt_rectfill<quint64>(reinterpret_cast<quint64 *>(d->data), color.rgba64().premultiplied(),
                             0, 0, d->width, d->height, d->bytes_per_line);
        break;
    case QImage::Format_RGBX16FPx4:
    case QImage::Format_RGBA16FPx4:
    case QImage::Format_RGBA16FPx4_Premultiplied:
    case QImage::Format_RGBX32FPx4:
    case QImage::Format_RGBA32FPx4:
    case QImage::Format_RGBA32FPx4_Premultiplied:{
        float r, g, b, a;
        color.getRgbF(&r, &g, &b, &a);
        if (!hasAlphaChannel())
            a = 1.0f;
        if (depth() == 64) {
            QRgbaFloat16 c16{qfloat16(r), qfloat16(g), qfloat16(b), qfloat16(a)};
            if (d->format == Format_RGBA16FPx4_Premultiplied)
                c16 = c16.premultiplied();
            qt_rectfill<QRgbaFloat16>(reinterpret_cast<QRgbaFloat16 *>(d->data), c16,
                                 0, 0, d->width, d->height, d->bytes_per_line);
        } else {
            QRgbaFloat32 c32{r, g, b, a};
            if (d->format == Format_RGBA32FPx4_Premultiplied)
                c32 = c32.premultiplied();
            qt_rectfill<QRgbaFloat32>(reinterpret_cast<QRgbaFloat32 *>(d->data), c32,
                                 0, 0, d->width, d->height, d->bytes_per_line);
        }
        break;
    }
    default: {
        QPainter p(this);
        p.setCompositionMode(QPainter::CompositionMode_Source);
        p.fillRect(rect(), color);
    }}
}



/*!
    Inverts all pixel values in the image.

    The given invert \a mode only have a meaning when the image's
    depth is 32. The default \a mode is InvertRgb, which leaves the
    alpha channel unchanged. If the \a mode is InvertRgba, the alpha
    bits are also inverted.

    Inverting an 8-bit image means to replace all pixels using color
    index \e i with a pixel using color index 255 minus \e i. The same
    is the case for a 1-bit image. Note that the color table is \e not
    changed.

    If the image has a premultiplied alpha channel, the image is first
    converted to an unpremultiplied image format to be inverted and
    then converted back.

    \sa {QImage#Image Transformations}{Image Transformations}
*/

void QImage::invertPixels(InvertMode mode)
{
    if (!d)
        return;

    detach();

    // In case detach() ran out of memory
    if (!d)
        return;

    QImage::Format originalFormat = d->format;
    // Inverting premultiplied pixels would produce invalid image data.
    if (hasAlphaChannel() && qPixelLayouts[d->format].premultiplied) {
        if (d->format == QImage::Format_RGBA16FPx4_Premultiplied) {
            if (!d->convertInPlace(QImage::Format_RGBA16FPx4, { }))
                *this = convertToFormat(QImage::Format_RGBA16FPx4);
        } else if (d->format == QImage::Format_RGBA32FPx4_Premultiplied) {
            if (!d->convertInPlace(QImage::Format_RGBA32FPx4, { }))
                *this = convertToFormat(QImage::Format_RGBA32FPx4);
        } else if (depth() > 32) {
            if (!d->convertInPlace(QImage::Format_RGBA64, { }))
                *this = convertToFormat(QImage::Format_RGBA64);
        } else {
            if (!d->convertInPlace(QImage::Format_ARGB32, { }))
                *this = convertToFormat(QImage::Format_ARGB32);
        }
    }

    if (depth() < 32) {
        // This assumes no alpha-channel as the only formats with non-premultipled alpha are 32bit.
        qsizetype bpl = (qsizetype(d->width) * d->depth + 7) / 8;
        int pad = d->bytes_per_line - bpl;
        uchar *sl = d->data;
        for (int y=0; y<d->height; ++y) {
            for (qsizetype x=0; x<bpl; ++x)
                *sl++ ^= 0xff;
            sl += pad;
        }
    } else if (format() >= QImage::Format_RGBX16FPx4 && format() <= QImage::Format_RGBA16FPx4_Premultiplied) {
        qfloat16 *p = reinterpret_cast<qfloat16 *>(d->data);
        qfloat16 *end = reinterpret_cast<qfloat16 *>(d->data + d->nbytes);
        while (p < end) {
            p[0] = qfloat16(1) - p[0];
            p[1] = qfloat16(1) - p[1];
            p[2] = qfloat16(1) - p[2];
            if (mode == InvertRgba)
                p[3] = qfloat16(1) - p[3];
            p += 4;
        }
    } else if (format() >= QImage::Format_RGBX32FPx4 && format() <= QImage::Format_RGBA32FPx4_Premultiplied) {
        uchar *data = d->data;
        for (int y = 0; y < d->height; ++y) {
            float *p = reinterpret_cast<float *>(data);
            for (int x = 0; x < d->width; ++x) {
                p[0] = 1.0f - p[0];
                p[1] = 1.0f - p[1];
                p[2] = 1.0f - p[2];
                if (mode == InvertRgba)
                    p[3] = 1.0f - p[3];
                p += 4;
            }
            data += d->bytes_per_line;
        }
    } else if (depth() == 64) {
        quint16 *p = (quint16*)d->data;
        quint16 *end = (quint16*)(d->data + d->nbytes);
        quint16 xorbits = 0xffff;
        while (p < end) {
            *p++ ^= xorbits;
            *p++ ^= xorbits;
            *p++ ^= xorbits;
            if (mode == InvertRgba)
                *p++ ^= xorbits;
            else
                p++;
        }
    } else {
        quint32 *p = (quint32*)d->data;
        quint32 *end = (quint32*)(d->data + d->nbytes);
        quint32 xorbits = 0xffffffff;
        switch (d->format) {
        case QImage::Format_RGBA8888:
            if (mode == InvertRgba)
                break;
            Q_FALLTHROUGH();
        case QImage::Format_RGBX8888:
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
            xorbits = 0xffffff00;
            break;
#else
            xorbits = 0x00ffffff;
            break;
#endif
        case QImage::Format_ARGB32:
            if (mode == InvertRgba)
                break;
            Q_FALLTHROUGH();
        case QImage::Format_RGB32:
            xorbits = 0x00ffffff;
            break;
        case QImage::Format_BGR30:
        case QImage::Format_RGB30:
            xorbits = 0x3fffffff;
            break;
        default:
            Q_UNREACHABLE();
            xorbits = 0;
            break;
        }
        while (p < end)
            *p++ ^= xorbits;
    }

    if (originalFormat != d->format) {
        if (!d->convertInPlace(originalFormat, { }))
            *this = convertToFormat(originalFormat);
    }
}

// Windows defines these
#if defined(write)
# undef write
#endif
#if defined(close)
# undef close
#endif
#if defined(read)
# undef read
#endif

/*!
    Resizes the color table to contain \a colorCount entries.

    If the color table is expanded, all the extra colors will be set to
    transparent (i.e qRgba(0, 0, 0, 0)).

    When the image is used, the color table must be large enough to
    have entries for all the pixel/index values present in the image,
    otherwise the results are undefined.

    \sa colorCount(), colorTable(), setColor(), {QImage#Image
    Transformations}{Image Transformations}
*/

void QImage::setColorCount(int colorCount)
{
    if (!d) {
        qWarning("QImage::setColorCount: null image");
        return;
    }

    detachMetadata(true);

    // In case detach() ran out of memory
    if (!d)
        return;

    if (colorCount == d->colortable.size())
        return;
    if (colorCount <= 0) {                        // use no color table
        d->colortable.clear();
        return;
    }
    int nc = d->colortable.size();
    d->colortable.resize(colorCount);
    for (int i = nc; i < colorCount; ++i)
        d->colortable[i] = 0;
}

/*!
    Returns the format of the image.

    \sa {QImage#Image Formats}{Image Formats}
*/
QImage::Format QImage::format() const
{
    if (d) {
        // Class Invariant Check
        Q_ASSERT(d->format < NImageFormats);
        Q_ASSERT(d->format > Format_Invalid);
    }
    return d ? d->format : Format_Invalid;
}

/*!
    \fn QImage QImage::convertToFormat(Format format, Qt::ImageConversionFlags flags) const &
    \fn QImage QImage::convertToFormat(Format format, Qt::ImageConversionFlags flags) &&

    Returns a copy of the image in the given \a format.

    The specified image conversion \a flags control how the image data
    is handled during the conversion process.

    \sa convertTo(), {Image Formats}
*/

/*!
    \fn QImage QImage::convertedTo(Format format, Qt::ImageConversionFlags flags) const &
    \fn QImage QImage::convertedTo(Format format, Qt::ImageConversionFlags flags) &&
    \since 6.0

    Returns a copy of the image in the given \a format.

    The specified image conversion \a flags control how the image data
    is handled during the conversion process.

    \sa convertTo(), {Image Formats}
*/

/*!
    \internal
*/
QImage QImage::convertToFormat_helper(Format format, Qt::ImageConversionFlags flags) const
{
    if (!d || d->format == format)
        return *this;

    if (d->format == Format_Invalid || format <= Format_Invalid || format >= NImageFormats)
        return QImage();

    const QPixelLayout *destLayout = &qPixelLayouts[format];
    Image_Converter converter = qimage_converter_map[d->format][format];
    if (!converter && format > QImage::Format_Indexed8 && d->format > QImage::Format_Indexed8) {
        if (qt_highColorPrecision(d->format, !destLayout->hasAlphaChannel)
                && qt_highColorPrecision(format, !hasAlphaChannel())) {
#if QT_CONFIG(raster_fp)
            if (qt_fpColorPrecision(d->format) && qt_fpColorPrecision(format))
                converter = convert_generic_over_rgba32f;
            else
#endif
                converter = convert_generic_over_rgb64;
        } else
            converter = convert_generic;
    }
    if (converter) {
        QImage image(d->width, d->height, format);

        QIMAGE_SANITYCHECK_MEMORY(image);

        copyMetadata(image.d, d);

        converter(image.d, d, flags);
        return image;
    }

    // Convert indexed formats over ARGB32 or RGB32 to the final format.
    Q_ASSERT(format != QImage::Format_ARGB32 && format != QImage::Format_RGB32);
    Q_ASSERT(d->format != QImage::Format_ARGB32 && d->format != QImage::Format_RGB32);

    if (!hasAlphaChannel())
        return convertToFormat(Format_RGB32, flags).convertToFormat(format, flags);

    return convertToFormat(Format_ARGB32, flags).convertToFormat(format, flags);
}

/*!
    \internal
*/
bool QImage::convertToFormat_inplace(Format format, Qt::ImageConversionFlags flags)
{
    return d && d->convertInPlace(format, flags);
}

static inline int pixel_distance(QRgb p1, QRgb p2) {
    int r1 = qRed(p1);
    int g1 = qGreen(p1);
    int b1 = qBlue(p1);
    int a1 = qAlpha(p1);

    int r2 = qRed(p2);
    int g2 = qGreen(p2);
    int b2 = qBlue(p2);
    int a2 = qAlpha(p2);

    return abs(r1 - r2) + abs(g1 - g2) + abs(b1 - b2) + abs(a1 - a2);
}

static inline int closestMatch(QRgb pixel, const QList<QRgb> &clut) {
    int idx = 0;
    int current_distance = INT_MAX;
    for (int i=0; i<clut.size(); ++i) {
        int dist = pixel_distance(pixel, clut.at(i));
        if (dist < current_distance) {
            current_distance = dist;
            idx = i;
        }
    }
    return idx;
}

static QImage convertWithPalette(const QImage &src, QImage::Format format,
                                 const QList<QRgb> &clut) {
    QImage dest(src.size(), format);
    dest.setColorTable(clut);

    copyMetadata(QImageData::get(dest), QImageData::get(src));

    int h = src.height();
    int w = src.width();

    QHash<QRgb, int> cache;

    if (format == QImage::Format_Indexed8) {
        for (int y=0; y<h; ++y) {
            const QRgb *src_pixels = (const QRgb *) src.scanLine(y);
            uchar *dest_pixels = (uchar *) dest.scanLine(y);
            for (int x=0; x<w; ++x) {
                int src_pixel = src_pixels[x];
                int value = cache.value(src_pixel, -1);
                if (value == -1) {
                    value = closestMatch(src_pixel, clut);
                    cache.insert(src_pixel, value);
                }
                dest_pixels[x] = (uchar) value;
            }
        }
    } else {
        QList<QRgb> table = clut;
        table.resize(2);
        for (int y=0; y<h; ++y) {
            const QRgb *src_pixels = (const QRgb *) src.scanLine(y);
            for (int x=0; x<w; ++x) {
                int src_pixel = src_pixels[x];
                int value = cache.value(src_pixel, -1);
                if (value == -1) {
                    value = closestMatch(src_pixel, table);
                    cache.insert(src_pixel, value);
                }
                dest.setPixel(x, y, value);
            }
        }
    }

    return dest;
}

/*!
    \overload

    Returns a copy of the image converted to the given \a format,
    using the specified \a colorTable.

    Conversion from RGB formats to indexed formats is a slow operation
    and will use a straightforward nearest color approach, with no
    dithering.
*/
QImage QImage::convertToFormat(Format format, const QList<QRgb> &colorTable, Qt::ImageConversionFlags flags) const
{
    if (!d || d->format == format)
        return *this;

    if (format <= QImage::Format_Invalid || format >= QImage::NImageFormats)
        return QImage();
    if (format <= QImage::Format_Indexed8)
        return convertWithPalette(convertToFormat(QImage::Format_ARGB32, flags), format, colorTable);

    return convertToFormat(format, flags);
}

/*!
    \since 5.9

    Changes the format of the image to \a format without changing the
    data. Only works between formats of the same depth.

    Returns \c true if successful.

    This function can be used to change images with alpha-channels to
    their corresponding opaque formats if the data is known to be opaque-only,
    or to change the format of a given image buffer before overwriting
    it with new data.

    \warning The function does not check if the image data is valid in the
    new format and will still return \c true if the depths are compatible.
    Operations on an image with invalid data are undefined.

    \warning If the image is not detached, this will cause the data to be
    copied.

    \sa hasAlphaChannel(), convertToFormat()
*/

bool QImage::reinterpretAsFormat(Format format)
{
    if (format <= Format_Invalid || format >= NImageFormats)
        return false;
    if (!d)
        return false;
    if (d->format == format)
        return true;
    if (qt_depthForFormat(format) != qt_depthForFormat(d->format))
        return false;
    if (!isDetached()) { // Detach only if shared, not for read-only data.
        QImageData *oldD = d;
        detach();
        // In case detach() ran out of memory
        if (!d) {
            d = oldD;
            d->ref.ref();
            return false;
        }
    }

    d->format = format;
    return true;
}

/*!
    \since 5.13

    Converts the image to the given \a format in place, detaching if necessary.

    The specified image conversion \a flags control how the image data
    is handled during the conversion process.

    \sa convertedTo()
*/

void QImage::convertTo(Format format, Qt::ImageConversionFlags flags)
{
    if (!d || format <= QImage::Format_Invalid || format >= QImage::NImageFormats)
        return;

    if (d->format == format)
        return;

    detach();
    if (convertToFormat_inplace(format, flags))
        return;

    *this = convertToFormat_helper(format, flags);
}

/*!
    \fn bool QImage::valid(const QPoint &pos) const

    Returns \c true if \a pos is a valid coordinate pair within the
    image; otherwise returns \c false.

    \sa rect(), QRect::contains()
*/

/*!
    \overload

    Returns \c true if QPoint(\a x, \a y) is a valid coordinate pair
    within the image; otherwise returns \c false.
*/
bool QImage::valid(int x, int y) const
{
    return d
        && x >= 0 && x < d->width
        && y >= 0 && y < d->height;
}

/*!
    \fn int QImage::pixelIndex(const QPoint &position) const

    Returns the pixel index at the given \a position.

    If \a position is not valid, or if the image is not a paletted
    image (depth() > 8), the results are undefined.

    \sa valid(), depth(), {QImage#Pixel Manipulation}{Pixel Manipulation}
*/

/*!
    \overload

    Returns the pixel index at (\a x, \a y).
*/
int QImage::pixelIndex(int x, int y) const
{
    if (!d || x < 0 || x >= d->width || y < 0 || y >= height()) {
        qWarning("QImage::pixelIndex: coordinate (%d,%d) out of range", x, y);
        return -12345;
    }
    const uchar * s = scanLine(y);
    switch(d->format) {
    case Format_Mono:
        return (*(s + (x >> 3)) >> (7- (x & 7))) & 1;
    case Format_MonoLSB:
        return (*(s + (x >> 3)) >> (x & 7)) & 1;
    case Format_Indexed8:
        return (int)s[x];
    default:
        qWarning("QImage::pixelIndex: Not applicable for %d-bpp images (no palette)", d->depth);
    }
    return 0;
}


/*!
    \fn QRgb QImage::pixel(const QPoint &position) const

    Returns the color of the pixel at the given \a position.

    If the \a position is not valid, the results are undefined.

    \warning This function is expensive when used for massive pixel
    manipulations. Use constBits() or constScanLine() when many
    pixels needs to be read.

    \sa setPixel(), valid(), constBits(), constScanLine(), {QImage#Pixel Manipulation}{Pixel
    Manipulation}
*/

/*!
    \overload

    Returns the color of the pixel at coordinates (\a x, \a y).
*/
QRgb QImage::pixel(int x, int y) const
{
    if (!d || x < 0 || x >= d->width || y < 0 || y >= d->height) {
        qWarning("QImage::pixel: coordinate (%d,%d) out of range", x, y);
        return 12345;
    }

    const uchar *s = d->data + y * d->bytes_per_line;

    int index = -1;
    switch (d->format) {
    case Format_Mono:
        index = (*(s + (x >> 3)) >> (~x & 7)) & 1;
        break;
    case Format_MonoLSB:
        index = (*(s + (x >> 3)) >> (x & 7)) & 1;
        break;
    case Format_Indexed8:
        index = s[x];
        break;
    default:
        break;
    }
    if (index >= 0) {    // Indexed format
        if (index >= d->colortable.size()) {
            qWarning("QImage::pixel: color table index %d out of range.", index);
            return 0;
        }
        return d->colortable.at(index);
    }

    switch (d->format) {
    case Format_RGB32:
        return 0xff000000 | reinterpret_cast<const QRgb *>(s)[x];
    case Format_ARGB32: // Keep old behaviour.
    case Format_ARGB32_Premultiplied:
        return reinterpret_cast<const QRgb *>(s)[x];
    case Format_RGBX8888:
    case Format_RGBA8888: // Match ARGB32 behavior.
    case Format_RGBA8888_Premultiplied:
        return RGBA2ARGB(reinterpret_cast<const quint32 *>(s)[x]);
    case Format_BGR30:
    case Format_A2BGR30_Premultiplied:
        return qConvertA2rgb30ToArgb32<PixelOrderBGR>(reinterpret_cast<const quint32 *>(s)[x]);
    case Format_RGB30:
    case Format_A2RGB30_Premultiplied:
        return qConvertA2rgb30ToArgb32<PixelOrderRGB>(reinterpret_cast<const quint32 *>(s)[x]);
    case Format_RGB16:
        return qConvertRgb16To32(reinterpret_cast<const quint16 *>(s)[x]);
    case Format_RGBX64:
    case Format_RGBA64: // Match ARGB32 behavior.
    case Format_RGBA64_Premultiplied:
        return reinterpret_cast<const QRgba64 *>(s)[x].toArgb32();
    case Format_RGBX16FPx4:
    case Format_RGBA16FPx4: // Match ARGB32 behavior.
    case Format_RGBA16FPx4_Premultiplied:
        return reinterpret_cast<const QRgbaFloat16 *>(s)[x].toArgb32();
    case Format_RGBX32FPx4:
    case Format_RGBA32FPx4: // Match ARGB32 behavior.
    case Format_RGBA32FPx4_Premultiplied:
        return reinterpret_cast<const QRgbaFloat32 *>(s)[x].toArgb32();
    default:
        break;
    }
    const QPixelLayout *layout = &qPixelLayouts[d->format];
    uint result;
    return *layout->fetchToARGB32PM(&result, s, x, 1, nullptr, nullptr);
}

/*!
    \fn void QImage::setPixel(const QPoint &position, uint index_or_rgb)

    Sets the pixel index or color at the given \a position to \a
    index_or_rgb.

    If the image's format is either monochrome or paletted, the given \a
    index_or_rgb value must be an index in the image's color table,
    otherwise the parameter must be a QRgb value.

    If \a position is not a valid coordinate pair in the image, or if
    \a index_or_rgb >= colorCount() in the case of monochrome and
    paletted images, the result is undefined.

    \warning This function is expensive due to the call of the internal
    \c{detach()} function called within; if performance is a concern, we
    recommend the use of scanLine() or bits() to access pixel data directly.

    \sa pixel(), {QImage#Pixel Manipulation}{Pixel Manipulation}
*/

/*!
    \overload

    Sets the pixel index or color at (\a x, \a y) to \a index_or_rgb.
*/
void QImage::setPixel(int x, int y, uint index_or_rgb)
{
    if (!d || x < 0 || x >= width() || y < 0 || y >= height()) {
        qWarning("QImage::setPixel: coordinate (%d,%d) out of range", x, y);
        return;
    }
    // detach is called from within scanLine
    uchar * s = scanLine(y);
    switch(d->format) {
    case Format_Mono:
    case Format_MonoLSB:
        if (index_or_rgb > 1) {
            qWarning("QImage::setPixel: Index %d out of range", index_or_rgb);
        } else if (format() == Format_MonoLSB) {
            if (index_or_rgb==0)
                *(s + (x >> 3)) &= ~(1 << (x & 7));
            else
                *(s + (x >> 3)) |= (1 << (x & 7));
        } else {
            if (index_or_rgb==0)
                *(s + (x >> 3)) &= ~(1 << (7-(x & 7)));
            else
                *(s + (x >> 3)) |= (1 << (7-(x & 7)));
        }
        return;
    case Format_Indexed8:
        if (index_or_rgb >= (uint)d->colortable.size()) {
            qWarning("QImage::setPixel: Index %d out of range", index_or_rgb);
            return;
        }
        s[x] = index_or_rgb;
        return;
    case Format_RGB32:
        //make sure alpha is 255, we depend on it in qdrawhelper for cases
        // when image is set as a texture pattern on a qbrush
        ((uint *)s)[x] = 0xff000000 | index_or_rgb;
        return;
    case Format_ARGB32:
    case Format_ARGB32_Premultiplied:
        ((uint *)s)[x] = index_or_rgb;
        return;
    case Format_RGB16:
        ((quint16 *)s)[x] = qConvertRgb32To16(index_or_rgb);
        return;
    case Format_RGBX8888:
        ((uint *)s)[x] = ARGB2RGBA(0xff000000 | index_or_rgb);
        return;
    case Format_RGBA8888:
    case Format_RGBA8888_Premultiplied:
        ((uint *)s)[x] = ARGB2RGBA(index_or_rgb);
        return;
    case Format_BGR30:
        ((uint *)s)[x] = qConvertRgb32ToRgb30<PixelOrderBGR>(index_or_rgb);
        return;
    case Format_A2BGR30_Premultiplied:
        ((uint *)s)[x] = qConvertArgb32ToA2rgb30<PixelOrderBGR>(index_or_rgb);
        return;
    case Format_RGB30:
        ((uint *)s)[x] = qConvertRgb32ToRgb30<PixelOrderRGB>(index_or_rgb);
        return;
    case Format_A2RGB30_Premultiplied:
        ((uint *)s)[x] = qConvertArgb32ToA2rgb30<PixelOrderRGB>(index_or_rgb);
        return;
    case Format_RGBX64:
        ((QRgba64 *)s)[x] = QRgba64::fromArgb32(index_or_rgb | 0xff000000);
        return;
    case Format_RGBA64:
    case Format_RGBA64_Premultiplied:
        ((QRgba64 *)s)[x] = QRgba64::fromArgb32(index_or_rgb);
        return;
    case Format_RGBX16FPx4:
        ((QRgbaFloat16 *)s)[x] = QRgbaFloat16::fromArgb32(index_or_rgb | 0xff000000);
        return;
    case Format_RGBA16FPx4:
    case Format_RGBA16FPx4_Premultiplied:
        ((QRgbaFloat16 *)s)[x] = QRgbaFloat16::fromArgb32(index_or_rgb);
        return;
    case Format_RGBX32FPx4:
        ((QRgbaFloat32 *)s)[x] = QRgbaFloat32::fromArgb32(index_or_rgb | 0xff000000);
        return;
    case Format_RGBA32FPx4:
    case Format_RGBA32FPx4_Premultiplied:
        ((QRgbaFloat32 *)s)[x] = QRgbaFloat32::fromArgb32(index_or_rgb);
        return;
    case Format_Invalid:
    case NImageFormats:
        Q_ASSERT(false);
        return;
    default:
        break;
    }

    const QPixelLayout *layout = &qPixelLayouts[d->format];
    if (!hasAlphaChannel())
        layout->storeFromRGB32(s, &index_or_rgb, x, 1, nullptr, nullptr);
    else
        layout->storeFromARGB32PM(s, &index_or_rgb, x, 1, nullptr, nullptr);
}

/*!
    \fn QColor QImage::pixelColor(const QPoint &position) const
    \since 5.6

    Returns the color of the pixel at the given \a position as a QColor.

    If the \a position is not valid, an invalid QColor is returned.

    \warning This function is expensive when used for massive pixel
    manipulations. Use constBits() or constScanLine() when many
    pixels needs to be read.

    \sa setPixel(), valid(), constBits(), constScanLine(), {QImage#Pixel Manipulation}{Pixel
    Manipulation}
*/

/*!
    \overload
    \since 5.6

    Returns the color of the pixel at coordinates (\a x, \a y) as a QColor.
*/
QColor QImage::pixelColor(int x, int y) const
{
    if (!d || x < 0 || x >= d->width || y < 0 || y >= height()) {
        qWarning("QImage::pixelColor: coordinate (%d,%d) out of range", x, y);
        return QColor();
    }

    QRgba64 c;
    const uchar * s = constScanLine(y);
    switch (d->format) {
    case Format_BGR30:
    case Format_A2BGR30_Premultiplied:
        c = qConvertA2rgb30ToRgb64<PixelOrderBGR>(reinterpret_cast<const quint32 *>(s)[x]);
        break;
    case Format_RGB30:
    case Format_A2RGB30_Premultiplied:
        c = qConvertA2rgb30ToRgb64<PixelOrderRGB>(reinterpret_cast<const quint32 *>(s)[x]);
        break;
    case Format_RGBX64:
    case Format_RGBA64:
    case Format_RGBA64_Premultiplied:
        c = reinterpret_cast<const QRgba64 *>(s)[x];
        break;
    case Format_Grayscale16: {
        quint16 v = reinterpret_cast<const quint16 *>(s)[x];
        return QColor(qRgba64(v, v, v, 0xffff));
    }
    case Format_RGBX16FPx4:
    case Format_RGBA16FPx4:
    case Format_RGBA16FPx4_Premultiplied: {
        QRgbaFloat16 p = reinterpret_cast<const QRgbaFloat16 *>(s)[x];
        if (d->format == Format_RGBA16FPx4_Premultiplied)
            p = p.unpremultiplied();
        QColor color;
        color.setRgbF(p.red(), p.green(), p.blue(), p.alpha());
        return color;
    }
    case Format_RGBX32FPx4:
    case Format_RGBA32FPx4:
    case Format_RGBA32FPx4_Premultiplied: {
        QRgbaFloat32 p = reinterpret_cast<const QRgbaFloat32 *>(s)[x];
        if (d->format == Format_RGBA32FPx4_Premultiplied)
            p = p.unpremultiplied();
        QColor color;
        color.setRgbF(p.red(), p.green(), p.blue(), p.alpha());
        return color;
    }
    default:
        c = QRgba64::fromArgb32(pixel(x, y));
        break;
    }
    // QColor is always unpremultiplied
    if (hasAlphaChannel() && qPixelLayouts[d->format].premultiplied)
        c = c.unpremultiplied();
    return QColor(c);
}

/*!
    \fn void QImage::setPixelColor(const QPoint &position, const QColor &color)
    \since 5.6

    Sets the color at the given \a position to \a color.

    If \a position is not a valid coordinate pair in the image, or
    the image's format is either monochrome or paletted, the result is undefined.

    \warning This function is expensive due to the call of the internal
    \c{detach()} function called within; if performance is a concern, we
    recommend the use of scanLine() or bits() to access pixel data directly.

    \sa pixel(), bits(), scanLine(), {QImage#Pixel Manipulation}{Pixel Manipulation}
*/

/*!
    \overload
    \since 5.6

    Sets the pixel color at (\a x, \a y) to \a color.
*/
void QImage::setPixelColor(int x, int y, const QColor &color)
{
    if (!d || x < 0 || x >= width() || y < 0 || y >= height()) {
        qWarning("QImage::setPixelColor: coordinate (%d,%d) out of range", x, y);
        return;
    }

    if (!color.isValid()) {
        qWarning("QImage::setPixelColor: color is invalid");
        return;
    }

    // QColor is always unpremultiplied
    QRgba64 c = color.rgba64();
    if (!hasAlphaChannel())
        c.setAlpha(65535);
    else if (qPixelLayouts[d->format].premultiplied)
        c = c.premultiplied();
    // detach is called from within scanLine
    uchar * s = scanLine(y);
    switch (d->format) {
    case Format_Mono:
    case Format_MonoLSB:
    case Format_Indexed8:
        qWarning("QImage::setPixelColor: called on monochrome or indexed format");
        return;
    case Format_BGR30:
        ((uint *)s)[x] = qConvertRgb64ToRgb30<PixelOrderBGR>(c) | 0xc0000000;
        return;
    case Format_A2BGR30_Premultiplied:
        ((uint *)s)[x] = qConvertRgb64ToRgb30<PixelOrderBGR>(c);
        return;
    case Format_RGB30:
        ((uint *)s)[x] = qConvertRgb64ToRgb30<PixelOrderRGB>(c) | 0xc0000000;
        return;
    case Format_A2RGB30_Premultiplied:
        ((uint *)s)[x] = qConvertRgb64ToRgb30<PixelOrderRGB>(c);
        return;
    case Format_RGBX64:
    case Format_RGBA64:
    case Format_RGBA64_Premultiplied:
        ((QRgba64 *)s)[x] = c;
        return;
    case Format_RGBX16FPx4:
    case Format_RGBA16FPx4:
    case Format_RGBA16FPx4_Premultiplied: {
        float r, g, b, a;
        color.getRgbF(&r, &g, &b, &a);
        if (d->format == Format_RGBX16FPx4)
            a = 1.0f;
        QRgbaFloat16 c16f{qfloat16(r), qfloat16(g), qfloat16(b), qfloat16(a)};
        if (d->format == Format_RGBA16FPx4_Premultiplied)
            c16f = c16f.premultiplied();
        ((QRgbaFloat16 *)s)[x] = c16f;
        return;
    }
    case Format_RGBX32FPx4:
    case Format_RGBA32FPx4:
    case Format_RGBA32FPx4_Premultiplied: {
        float r, g, b, a;
        color.getRgbF(&r, &g, &b, &a);
        if (d->format == Format_RGBX32FPx4)
            a = 1.0f;
        QRgbaFloat32 c32f{r, g, b, a};
        if (d->format == Format_RGBA32FPx4_Premultiplied)
            c32f = c32f.premultiplied();
        ((QRgbaFloat32 *)s)[x] = c32f;
        return;
    }
    default:
        setPixel(x, y, c.toArgb32());
        return;
    }
}

/*!
    Returns \c true if all the colors in the image are shades of gray
    (i.e. their red, green and blue components are equal); otherwise
    false.

    Note that this function is slow for images without color table.

    \sa isGrayscale()
*/
bool QImage::allGray() const
{
    if (!d)
        return true;

    switch (d->format) {
    case Format_Mono:
    case Format_MonoLSB:
    case Format_Indexed8:
        for (int i = 0; i < d->colortable.size(); ++i) {
            if (!qIsGray(d->colortable.at(i)))
                return false;
        }
        return true;
    case Format_Alpha8:
        return false;
    case Format_Grayscale8:
    case Format_Grayscale16:
        return true;
    case Format_RGB32:
    case Format_ARGB32:
    case Format_ARGB32_Premultiplied:
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    case Format_RGBX8888:
    case Format_RGBA8888:
    case Format_RGBA8888_Premultiplied:
#endif
        for (int j = 0; j < d->height; ++j) {
            const QRgb *b = (const QRgb *)constScanLine(j);
            for (int i = 0; i < d->width; ++i) {
                if (!qIsGray(b[i]))
                    return false;
            }
        }
        return true;
    case Format_RGB16:
        for (int j = 0; j < d->height; ++j) {
            const quint16 *b = (const quint16 *)constScanLine(j);
            for (int i = 0; i < d->width; ++i) {
                if (!qIsGray(qConvertRgb16To32(b[i])))
                    return false;
            }
        }
        return true;
    default:
        break;
    }

    Q_DECL_UNINITIALIZED uint buffer[BufferSize];
    const QPixelLayout *layout = &qPixelLayouts[d->format];
    const auto fetch = layout->fetchToARGB32PM;
    for (int j = 0; j < d->height; ++j) {
        const uchar *b = constScanLine(j);
        int x = 0;
        while (x < d->width) {
            int l = qMin(d->width - x, BufferSize);
            const uint *ptr = fetch(buffer, b, x, l, nullptr, nullptr);
            for (int i = 0; i < l; ++i) {
                if (!qIsGray(ptr[i]))
                    return false;
            }
            x += l;
        }
    }
    return true;
}

/*!
    For 32-bit images, this function is equivalent to allGray().

    For color indexed images, this function returns \c true if
    color(i) is QRgb(i, i, i) for all indexes of the color table;
    otherwise returns \c false.

    \sa allGray(), {QImage#Image Formats}{Image Formats}
*/
bool QImage::isGrayscale() const
{
    if (!d)
        return false;

    if (d->format == QImage::Format_Alpha8)
        return false;

    if (d->format == QImage::Format_Grayscale8 || d->format == QImage::Format_Grayscale16)
        return true;

    switch (depth()) {
    case 32:
    case 24:
    case 16:
        return allGray();
    case 8: {
        Q_ASSERT(d->format == QImage::Format_Indexed8);
        for (int i = 0; i < colorCount(); i++)
            if (d->colortable.at(i) != qRgb(i,i,i))
                return false;
        return true;
        }
    }
    return false;
}

/*!
    \fn QImage QImage::scaled(int width, int height, Qt::AspectRatioMode aspectRatioMode,
                             Qt::TransformationMode transformMode) const
    \overload

    Returns a copy of the image scaled to a rectangle with the given
    \a width and \a height according to the given \a aspectRatioMode
    and \a transformMode.

    If either the \a width or the \a height is zero or negative, this
    function returns a null image.
*/

/*!
    \fn QImage QImage::scaled(const QSize &size, Qt::AspectRatioMode aspectRatioMode,
                             Qt::TransformationMode transformMode) const

    Returns a copy of the image scaled to a rectangle defined by the
    given \a size according to the given \a aspectRatioMode and \a
    transformMode.

    \image qimage-scaling.png

    \list
    \li If \a aspectRatioMode is Qt::IgnoreAspectRatio, the image
       is scaled to \a size.
    \li If \a aspectRatioMode is Qt::KeepAspectRatio, the image is
       scaled to a rectangle as large as possible inside \a size, preserving the aspect ratio.
    \li If \a aspectRatioMode is Qt::KeepAspectRatioByExpanding,
       the image is scaled to a rectangle as small as possible
       outside \a size, preserving the aspect ratio.
    \endlist

    If the given \a size is empty, this function returns a null image.

    \sa isNull(), {QImage#Image Transformations}{Image
    Transformations}
*/
QImage Q_TRACE_INSTRUMENT(qtgui) QImage::scaled(const QSize& s, Qt::AspectRatioMode aspectMode, Qt::TransformationMode mode) const
{
    if (!d) {
        qWarning("QImage::scaled: Image is a null image");
        return QImage();
    }
    if (s.isEmpty())
        return QImage();

    QSize newSize = size();
    newSize.scale(s, aspectMode);
    newSize.rwidth() = qMax(newSize.width(), 1);
    newSize.rheight() = qMax(newSize.height(), 1);
    if (newSize == size())
        return *this;

    Q_TRACE_SCOPE(QImage_scaled, s, aspectMode, mode);

    QTransform wm = QTransform::fromScale((qreal)newSize.width() / width(), (qreal)newSize.height() / height());
    QImage img = transformed(wm, mode);
    return img;
}

/*!
    \fn QImage QImage::scaledToWidth(int width, Qt::TransformationMode mode) const

    Returns a scaled copy of the image. The returned image is scaled
    to the given \a width using the specified transformation \a
    mode.

    This function automatically calculates the height of the image so
    that its aspect ratio is preserved.

    If the given \a width is 0 or negative, a null image is returned.

    \sa {QImage#Image Transformations}{Image Transformations}
*/
QImage Q_TRACE_INSTRUMENT(qtgui) QImage::scaledToWidth(int w, Qt::TransformationMode mode) const
{
    if (!d) {
        qWarning("QImage::scaleWidth: Image is a null image");
        return QImage();
    }
    if (w <= 0)
        return QImage();

    Q_TRACE_SCOPE(QImage_scaledToWidth, w, mode);

    qreal factor = (qreal) w / width();
    QTransform wm = QTransform::fromScale(factor, factor);
    return transformed(wm, mode);
}

/*!
    \fn QImage QImage::scaledToHeight(int height, Qt::TransformationMode mode) const

    Returns a scaled copy of the image. The returned image is scaled
    to the given \a height using the specified transformation \a
    mode.

    This function automatically calculates the width of the image so that
    the ratio of the image is preserved.

    If the given \a height is 0 or negative, a null image is returned.

    \sa {QImage#Image Transformations}{Image Transformations}
*/
QImage Q_TRACE_INSTRUMENT(qtgui) QImage::scaledToHeight(int h, Qt::TransformationMode mode) const
{
    if (!d) {
        qWarning("QImage::scaleHeight: Image is a null image");
        return QImage();
    }
    if (h <= 0)
        return QImage();

    Q_TRACE_SCOPE(QImage_scaledToHeight, h, mode);

    qreal factor = (qreal) h / height();
    QTransform wm = QTransform::fromScale(factor, factor);
    return transformed(wm, mode);
}

/*!
    Builds and returns a 1-bpp mask from the alpha buffer in this
    image. Returns a null image if the image's format is
    QImage::Format_RGB32.

    The \a flags argument is a bitwise-OR of the
    Qt::ImageConversionFlags, and controls the conversion
    process. Passing 0 for flags sets all the default options.

    The returned image has little-endian bit order (i.e. the image's
    format is QImage::Format_MonoLSB), which you can convert to
    big-endian (QImage::Format_Mono) using the convertToFormat()
    function.

    \sa createHeuristicMask(), {QImage#Image Transformations}{Image
    Transformations}
*/
QImage Q_TRACE_INSTRUMENT(qtgui) QImage::createAlphaMask(Qt::ImageConversionFlags flags) const
{
    if (!d || d->format == QImage::Format_RGB32)
        return QImage();

    if (d->depth == 1) {
        // A monochrome pixmap, with alpha channels on those two colors.
        // Pretty unlikely, so use less efficient solution.
        return convertToFormat(Format_Indexed8, flags).createAlphaMask(flags);
    }

    QImage mask(d->width, d->height, Format_MonoLSB);
    if (!mask.isNull()) {
        dither_to_Mono(mask.d, d, flags, true);
        copyPhysicalMetadata(mask.d, d);
    }
    return mask;
}

#ifndef QT_NO_IMAGE_HEURISTIC_MASK
/*!
    Creates and returns a 1-bpp heuristic mask for this image.

    The function works by selecting a color from one of the corners,
    then chipping away pixels of that color starting at all the edges.
    The four corners vote for which color is to be masked away. In
    case of a draw (this generally means that this function is not
    applicable to the image), the result is arbitrary.

    The returned image has little-endian bit order (i.e. the image's
    format is QImage::Format_MonoLSB), which you can convert to
    big-endian (QImage::Format_Mono) using the convertToFormat()
    function.

    If \a clipTight is true (the default) the mask is just large
    enough to cover the pixels; otherwise, the mask is larger than the
    data pixels.

    Note that this function disregards the alpha buffer.

    \sa createAlphaMask(), {QImage#Image Transformations}{Image
    Transformations}
*/

QImage QImage::createHeuristicMask(bool clipTight) const
{
    if (!d)
        return QImage();

    if (d->depth != 32) {
        QImage img32 = convertToFormat(Format_RGB32);
        return img32.createHeuristicMask(clipTight);
    }

#define PIX(x,y)  (*((const QRgb*)scanLine(y)+x) & 0x00ffffff)

    int w = width();
    int h = height();
    QImage m(w, h, Format_MonoLSB);
    QIMAGE_SANITYCHECK_MEMORY(m);
    m.setColorCount(2);
    m.setColor(0, QColor(Qt::color0).rgba());
    m.setColor(1, QColor(Qt::color1).rgba());
    m.fill(0xff);

    QRgb background = PIX(0,0);
    if (background != PIX(w-1,0) &&
         background != PIX(0,h-1) &&
         background != PIX(w-1,h-1)) {
        background = PIX(w-1,0);
        if (background != PIX(w-1,h-1) &&
             background != PIX(0,h-1) &&
             PIX(0,h-1) == PIX(w-1,h-1)) {
            background = PIX(w-1,h-1);
        }
    }

    int x,y;
    bool done = false;
    uchar *ypp, *ypc, *ypn;
    while(!done) {
        done = true;
        ypn = m.scanLine(0);
        ypc = nullptr;
        for (y = 0; y < h; y++) {
            ypp = ypc;
            ypc = ypn;
            ypn = (y == h-1) ? nullptr : m.scanLine(y+1);
            const QRgb *p = (const QRgb *)scanLine(y);
            for (x = 0; x < w; x++) {
                // slowness here - it's possible to do six of these tests
                // together in one go. oh well.
                if ((x == 0 || y == 0 || x == w-1 || y == h-1 ||
                       !(*(ypc + ((x-1) >> 3)) & (1 << ((x-1) & 7))) ||
                       !(*(ypc + ((x+1) >> 3)) & (1 << ((x+1) & 7))) ||
                       !(*(ypp + (x     >> 3)) & (1 << (x     & 7))) ||
                       !(*(ypn + (x     >> 3)) & (1 << (x     & 7)))) &&
                     (       (*(ypc + (x     >> 3)) & (1 << (x     & 7)))) &&
                     ((*p & 0x00ffffff) == background)) {
                    done = false;
                    *(ypc + (x >> 3)) &= ~(1 << (x & 7));
                }
                p++;
            }
        }
    }

    if (!clipTight) {
        ypn = m.scanLine(0);
        ypc = nullptr;
        for (y = 0; y < h; y++) {
            ypp = ypc;
            ypc = ypn;
            ypn = (y == h-1) ? nullptr : m.scanLine(y+1);
            const QRgb *p = (const QRgb *)scanLine(y);
            for (x = 0; x < w; x++) {
                if ((*p & 0x00ffffff) != background) {
                    if (x > 0)
                        *(ypc + ((x-1) >> 3)) |= (1 << ((x-1) & 7));
                    if (x < w-1)
                        *(ypc + ((x+1) >> 3)) |= (1 << ((x+1) & 7));
                    if (y > 0)
                        *(ypp + (x >> 3)) |= (1 << (x & 7));
                    if (y < h-1)
                        *(ypn + (x >> 3)) |= (1 << (x & 7));
                }
                p++;
            }
        }
    }

#undef PIX

    copyPhysicalMetadata(m.d, d);
    return m;
}
#endif //QT_NO_IMAGE_HEURISTIC_MASK

/*!
    Creates and returns a mask for this image based on the given \a
    color value. If the \a mode is MaskInColor (the default value),
    all pixels matching \a color will be opaque pixels in the mask. If
    \a mode is MaskOutColor, all pixels matching the given color will
    be transparent.

    \sa createAlphaMask(), createHeuristicMask()
*/

QImage QImage::createMaskFromColor(QRgb color, Qt::MaskMode mode) const
{
    if (!d)
        return QImage();
    QImage maskImage(size(), QImage::Format_MonoLSB);
    QIMAGE_SANITYCHECK_MEMORY(maskImage);
    maskImage.fill(0);
    uchar *s = maskImage.bits();
    if (!s)
        return QImage();

    if (depth() == 32) {
        for (int h = 0; h < d->height; h++) {
            const uint *sl = (const uint *) scanLine(h);
            for (int w = 0; w < d->width; w++) {
                if (sl[w] == color)
                    *(s + (w >> 3)) |= (1 << (w & 7));
            }
            s += maskImage.bytesPerLine();
        }
    } else {
        for (int h = 0; h < d->height; h++) {
            for (int w = 0; w < d->width; w++) {
                if ((uint) pixel(w, h) == color)
                    *(s + (w >> 3)) |= (1 << (w & 7));
            }
            s += maskImage.bytesPerLine();
        }
    }
    if  (mode == Qt::MaskOutColor)
        maskImage.invertPixels();

    copyPhysicalMetadata(maskImage.d, d);
    return maskImage;
}

/*!
    \fn QImage QImage::mirrored(bool horizontal = false, bool vertical = true) const &
    \fn QImage QImage::mirrored(bool horizontal = false, bool vertical = true) &&
    \deprecated [6.13] Use flipped(Qt::Orientations) instead.

    Returns a mirror of the image, mirrored in the horizontal and/or
    the vertical direction depending on whether \a horizontal and \a
    vertical are set to true or false.

    Note that the original image is not changed.

    \sa mirror(), {QImage#Image Transformations}{Image Transformations}
*/

/*!
    \fn void QImage::mirror(bool horizontal = false, bool vertical = true)
    \since 6.0
    \deprecated [6.13] Use flip(Qt::Orientations) instead.

    Mirrors of the image in the horizontal and/or the vertical direction depending
    on whether \a horizontal and \a vertical are set to true or false.

    \sa mirrored(), {QImage#Image Transformations}{Image Transformations}
*/

/*!
    \fn QImage QImage::flipped(Qt::Orientations orient) const &
    \fn QImage QImage::flipped(Qt::Orientations orient) &&
    \since 6.9

    Returns a flipped or mirror version of the image, mirrored in the horizontal and/or
    the vertical direction depending on \a orient.

    Note that the original image is not changed.

    \sa flip(Qt::Orientations), {QImage#Image Transformations}{Image Transformations}
*/

/*!
    \fn void QImage::flip(Qt::Orientations orient)
    \since 6.9

    Flips or mirrors the image in the horizontal and/or the vertical direction depending
    on \a orient.

    \sa flipped(Qt::Orientations), {QImage#Image Transformations}{Image Transformations}
*/

template<class T> inline void do_mirror_data(QImageData *dst, QImageData *src,
                                             int dstX0, int dstY0,
                                             int dstXIncr, int dstYIncr,
                                             int w, int h)
{
    if (dst == src) {
        // When mirroring in-place, stop in the middle for one of the directions, since we
        // are swapping the bytes instead of merely copying.
        const int srcXEnd = (dstX0 && !dstY0) ? w / 2 : w;
        const int srcYEnd = dstY0 ? h / 2 : h;
        for (int srcY = 0, dstY = dstY0; srcY < srcYEnd; ++srcY, dstY += dstYIncr) {
            T *srcPtr = (T *) (src->data + srcY * src->bytes_per_line);
            T *dstPtr = (T *) (dst->data + dstY * dst->bytes_per_line);
            for (int srcX = 0, dstX = dstX0; srcX < srcXEnd; ++srcX, dstX += dstXIncr)
                std::swap(srcPtr[srcX], dstPtr[dstX]);
        }
        // If mirroring both ways, the middle line needs to be mirrored horizontally only.
        if (dstX0 && dstY0 && (h & 1)) {
            int srcY = h / 2;
            int srcXEnd2 = w / 2;
            T *srcPtr = (T *) (src->data + srcY * src->bytes_per_line);
            for (int srcX = 0, dstX = dstX0; srcX < srcXEnd2; ++srcX, dstX += dstXIncr)
                std::swap(srcPtr[srcX], srcPtr[dstX]);
        }
    } else {
        for (int srcY = 0, dstY = dstY0; srcY < h; ++srcY, dstY += dstYIncr) {
            T *srcPtr = (T *) (src->data + srcY * src->bytes_per_line);
            T *dstPtr = (T *) (dst->data + dstY * dst->bytes_per_line);
            for (int srcX = 0, dstX = dstX0; srcX < w; ++srcX, dstX += dstXIncr)
                dstPtr[dstX] = srcPtr[srcX];
        }
    }
}

inline void do_flip(QImageData *dst, QImageData *src, int w, int h, int depth)
{
    const int data_bytes_per_line = w * (depth / 8);
    if (dst == src) {
        uint *srcPtr = reinterpret_cast<uint *>(src->data);
        uint *dstPtr = reinterpret_cast<uint *>(dst->data + (h - 1) * dst->bytes_per_line);
        h = h / 2;
        const int uint_per_line = (data_bytes_per_line + 3) >> 2; // bytes per line must be a multiple of 4
        for (int y = 0; y < h; ++y) {
            // This is auto-vectorized, no need for SSE2 or NEON versions:
            for (int x = 0; x < uint_per_line; x++) {
                const uint d = dstPtr[x];
                const uint s = srcPtr[x];
                dstPtr[x] = s;
                srcPtr[x] = d;
            }
            srcPtr += src->bytes_per_line >> 2;
            dstPtr -= dst->bytes_per_line >> 2;
        }

    } else {
        const uchar *srcPtr = src->data;
        uchar *dstPtr = dst->data + (h - 1) * dst->bytes_per_line;
        for (int y = 0; y < h; ++y) {
            memcpy(dstPtr, srcPtr, data_bytes_per_line);
            srcPtr += src->bytes_per_line;
            dstPtr -= dst->bytes_per_line;
        }
    }
}

inline void do_mirror(QImageData *dst, QImageData *src, bool horizontal, bool vertical)
{
    Q_ASSERT(src->width == dst->width && src->height == dst->height && src->depth == dst->depth);
    int w = src->width;
    int h = src->height;
    int depth = src->depth;

    if (src->depth == 1) {
        w = (w + 7) / 8; // byte aligned width
        depth = 8;
    }

    if (vertical && !horizontal) {
        // This one is simple and common, so do it a little more optimized
        do_flip(dst, src, w, h, depth);
        return;
    }

    int dstX0 = 0, dstXIncr = 1;
    int dstY0 = 0, dstYIncr = 1;
    if (horizontal) {
        // 0 -> w-1, 1 -> w-2, 2 -> w-3, ...
        dstX0 = w - 1;
        dstXIncr = -1;
    }
    if (vertical) {
        // 0 -> h-1, 1 -> h-2, 2 -> h-3, ...
        dstY0 = h - 1;
        dstYIncr = -1;
    }

    switch (depth) {
    case 128:
        do_mirror_data<QRgbaFloat32>(dst, src, dstX0, dstY0, dstXIncr, dstYIncr, w, h);
        break;
    case 64:
        do_mirror_data<quint64>(dst, src, dstX0, dstY0, dstXIncr, dstYIncr, w, h);
        break;
    case 32:
        do_mirror_data<quint32>(dst, src, dstX0, dstY0, dstXIncr, dstYIncr, w, h);
        break;
    case 24:
        do_mirror_data<quint24>(dst, src, dstX0, dstY0, dstXIncr, dstYIncr, w, h);
        break;
    case 16:
        do_mirror_data<quint16>(dst, src, dstX0, dstY0, dstXIncr, dstYIncr, w, h);
        break;
    case 8:
        do_mirror_data<quint8>(dst, src, dstX0, dstY0, dstXIncr, dstYIncr, w, h);
        break;
    default:
        Q_ASSERT(false);
        break;
    }

    // The bytes are now all in the correct place. In addition, the bits in the individual
    // bytes have to be flipped too when horizontally mirroring a 1 bit-per-pixel image.
    if (horizontal && dst->depth == 1) {
        Q_ASSERT(dst->format == QImage::Format_Mono || dst->format == QImage::Format_MonoLSB);
        const int shift = 8 - (dst->width % 8);
        const uchar *bitflip = qt_get_bitflip_array();
        for (int y = 0; y < h; ++y) {
            uchar *begin = dst->data + y * dst->bytes_per_line;
            uchar *end = begin + dst->bytes_per_line;
            for (uchar *p = begin; p < end; ++p) {
                *p = bitflip[*p];
                // When the data is non-byte aligned, an extra bit shift (of the number of
                // unused bits at the end) is needed for the entire scanline.
                if (shift != 8 && p != begin) {
                    if (dst->format == QImage::Format_Mono) {
                        for (int i = 0; i < shift; ++i) {
                            p[-1] <<= 1;
                            p[-1] |= (*p & (128 >> i)) >> (7 - i);
                        }
                    } else {
                        for (int i = 0; i < shift; ++i) {
                            p[-1] >>= 1;
                            p[-1] |= (*p & (1 << i)) << (7 - i);
                        }
                    }
                }
            }
            if (shift != 8) {
                if (dst->format == QImage::Format_Mono)
                    end[-1] <<= shift;
                else
                    end[-1] >>= shift;
            }
        }
    }
}

/*!
    \internal
*/
QImage QImage::mirrored_helper(bool horizontal, bool vertical) const
{
    if (!d)
        return QImage();

    if ((d->width <= 1 && d->height <= 1) || (!horizontal && !vertical))
        return *this;

    // Create result image, copy colormap
    QImage result(d->width, d->height, d->format);
    QIMAGE_SANITYCHECK_MEMORY(result);

    // check if we ran out of of memory..
    if (!result.d)
        return QImage();

    result.d->colortable = d->colortable;
    result.d->has_alpha_clut = d->has_alpha_clut;
    copyMetadata(result.d, d);

    do_mirror(result.d, d, horizontal, vertical);

    return result;
}

/*!
    \internal
*/
void QImage::mirrored_inplace(bool horizontal, bool vertical)
{
    if (!d || (d->width <= 1 && d->height <= 1) || (!horizontal && !vertical))
        return;

    detach();
    if (!d)
        return;
    if (!d->own_data)
        *this = copy();

    do_mirror(d, d, horizontal, vertical);
}

/*!
    \fn QImage QImage::rgbSwapped() const &
    \fn QImage QImage::rgbSwapped() &&

    Returns a QImage in which the values of the red and blue
    components of all pixels have been swapped, effectively converting
    an RGB image to an BGR image.

    The original QImage is not changed.

    \sa rgbSwap(), {QImage#Image Transformations}{Image Transformations}
*/

/*!
    \fn void QImage::rgbSwap()
    \since 6.0

    Swaps the values of the red and blue components of all pixels, effectively converting
    an RGB image to an BGR image.

    \sa rgbSwapped(), {QImage#Image Transformations}{Image Transformations}
*/

static inline void rgbSwapped_generic(int width, int height, const QImage *src, QImage *dst, const QPixelLayout* layout)
{
    const RbSwapFunc func = layout->rbSwap;
    if (!func) {
        qWarning("Trying to rb-swap an image format where it doesn't make sense");
        if (src != dst)
            *dst = *src;
        return;
    }

    for (int i = 0; i < height; ++i) {
        uchar *q = dst->scanLine(i);
        const uchar *p = src->constScanLine(i);
        func(q, p, width);
    }
}

/*!
    \internal
*/
QImage Q_TRACE_INSTRUMENT(qtgui) QImage::rgbSwapped_helper() const
{
    if (isNull())
        return *this;

    Q_TRACE_SCOPE(QImage_rgbSwapped_helper);

    QImage res;

    switch (d->format) {
    case Format_Invalid:
    case NImageFormats:
        Q_ASSERT(false);
        break;
    case Format_Alpha8:
    case Format_Grayscale8:
    case Format_Grayscale16:
        return *this;
    case Format_Mono:
    case Format_MonoLSB:
    case Format_Indexed8:
        res = copy();
        for (int i = 0; i < res.d->colortable.size(); i++) {
            QRgb c = res.d->colortable.at(i);
            res.d->colortable[i] = QRgb(((c << 16) & 0xff0000) | ((c >> 16) & 0xff) | (c & 0xff00ff00));
        }
        break;
    case Format_RGBX8888:
    case Format_RGBA8888:
    case Format_RGBA8888_Premultiplied:
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
        res = QImage(d->width, d->height, d->format);
        QIMAGE_SANITYCHECK_MEMORY(res);
        for (int i = 0; i < d->height; i++) {
            uint *q = (uint*)res.scanLine(i);
            const uint *p = (const uint*)constScanLine(i);
            const uint *end = p + d->width;
            while (p < end) {
                uint c = *p;
                *q = ((c << 16) & 0xff000000) | ((c >> 16) & 0xff00) | (c & 0x00ff00ff);
                p++;
                q++;
            }
        }
        break;
#else
        // On little-endian rgba8888 is abgr32 and can use same rgb-swap as argb32
        Q_FALLTHROUGH();
#endif
    case Format_RGB32:
    case Format_ARGB32:
    case Format_ARGB32_Premultiplied:
        res = QImage(d->width, d->height, d->format);
        QIMAGE_SANITYCHECK_MEMORY(res);
        for (int i = 0; i < d->height; i++) {
            uint *q = (uint*)res.scanLine(i);
            const uint *p = (const uint*)constScanLine(i);
            const uint *end = p + d->width;
            while (p < end) {
                uint c = *p;
                *q = ((c << 16) & 0xff0000) | ((c >> 16) & 0xff) | (c & 0xff00ff00);
                p++;
                q++;
            }
        }
        break;
    case Format_RGB16:
        res = QImage(d->width, d->height, d->format);
        QIMAGE_SANITYCHECK_MEMORY(res);
        for (int i = 0; i < d->height; i++) {
            ushort *q = (ushort*)res.scanLine(i);
            const ushort *p = (const ushort*)constScanLine(i);
            const ushort *end = p + d->width;
            while (p < end) {
                ushort c = *p;
                *q = ((c << 11) & 0xf800) | ((c >> 11) & 0x1f) | (c & 0x07e0);
                p++;
                q++;
            }
        }
        break;
    default:
        res = QImage(d->width, d->height, d->format);
        QIMAGE_SANITYCHECK_MEMORY(res);
        rgbSwapped_generic(d->width, d->height, this, &res, &qPixelLayouts[d->format]);
        break;
    }
    copyMetadata(res.d, d);
    return res;
}

/*!
    \internal
*/
void QImage::rgbSwapped_inplace()
{
    if (isNull())
        return;

    detach();
    if (!d)
        return;
    if (!d->own_data)
        *this = copy();

    switch (d->format) {
    case Format_Invalid:
    case NImageFormats:
        Q_ASSERT(false);
        break;
    case Format_Alpha8:
    case Format_Grayscale8:
    case Format_Grayscale16:
        return;
    case Format_Mono:
    case Format_MonoLSB:
    case Format_Indexed8:
        for (int i = 0; i < d->colortable.size(); i++) {
            QRgb c = d->colortable.at(i);
            d->colortable[i] = QRgb(((c << 16) & 0xff0000) | ((c >> 16) & 0xff) | (c & 0xff00ff00));
        }
        break;
    case Format_RGBX8888:
    case Format_RGBA8888:
    case Format_RGBA8888_Premultiplied:
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
        for (int i = 0; i < d->height; i++) {
            uint *p = (uint*)scanLine(i);
            uint *end = p + d->width;
            while (p < end) {
                uint c = *p;
                *p = ((c << 16) & 0xff000000) | ((c >> 16) & 0xff00) | (c & 0x00ff00ff);
                p++;
            }
        }
        break;
#else
        // On little-endian rgba8888 is abgr32 and can use same rgb-swap as argb32
        Q_FALLTHROUGH();
#endif
    case Format_RGB32:
    case Format_ARGB32:
    case Format_ARGB32_Premultiplied:
        for (int i = 0; i < d->height; i++) {
            uint *p = (uint*)scanLine(i);
            uint *end = p + d->width;
            while (p < end) {
                uint c = *p;
                *p = ((c << 16) & 0xff0000) | ((c >> 16) & 0xff) | (c & 0xff00ff00);
                p++;
            }
        }
        break;
    case Format_RGB16:
        for (int i = 0; i < d->height; i++) {
            ushort *p = (ushort*)scanLine(i);
            ushort *end = p + d->width;
            while (p < end) {
                ushort c = *p;
                *p = ((c << 11) & 0xf800) | ((c >> 11) & 0x1f) | (c & 0x07e0);
                p++;
            }
        }
        break;
    case Format_BGR30:
    case Format_A2BGR30_Premultiplied:
    case Format_RGB30:
    case Format_A2RGB30_Premultiplied:
        for (int i = 0; i < d->height; i++) {
            uint *p = (uint*)scanLine(i);
            uint *end = p + d->width;
            while (p < end) {
                *p = qRgbSwapRgb30(*p);
                p++;
            }
        }
        break;
    default:
        rgbSwapped_generic(d->width, d->height, this, this, &qPixelLayouts[d->format]);
        break;
    }
}

/*!
    Loads an image from the file with the given \a fileName. Returns \c true if
    the image was successfully loaded; otherwise invalidates the image
    and returns \c false.

    The loader attempts to read the image using the specified \a format, e.g.,
    PNG or JPG. If \a format is not specified (which is the default), it is
    auto-detected based on the file's suffix and header. For details, see
    QImageReader::setAutoDetectImageFormat().

    The file name can either refer to an actual file on disk or to one
    of the application's embedded resources. See the
    \l{resources.html}{Resource System} overview for details on how to
    embed images and other resource files in the application's
    executable.

    \sa {QImage#Reading and Writing Image Files}{Reading and Writing Image Files}
*/

bool QImage::load(const QString &fileName, const char* format)
{
    *this = QImageReader(fileName, format).read();
    return !isNull();
}

/*!
    \overload

    This function reads a QImage from the given \a device. This can,
    for example, be used to load an image directly into a QByteArray.
*/

bool QImage::load(QIODevice* device, const char* format)
{
    *this = QImageReader(device, format).read();
    return !isNull();
}

/*!
    \since 6.2

    Loads an image from the given QByteArrayView \a data. Returns \c true if the image was
    successfully loaded; otherwise invalidates the image and returns \c false.

    The loader attempts to read the image using the specified \a format, e.g.,
    PNG or JPG. If \a format is not specified (which is the default), the
    loader probes the file for a header to guess the file format.

    \sa {QImage#Reading and Writing Image Files}{Reading and Writing Image Files}
*/

bool QImage::loadFromData(QByteArrayView data, const char *format)
{
    *this = fromData(data, format);
    return !isNull();
}

/*!
    \fn bool QImage::loadFromData(const uchar *data, int len, const char *format)

    \overload

    Loads an image from the first \a len bytes of the given binary \a data.
*/

bool QImage::loadFromData(const uchar *buf, int len, const char *format)
{
    return loadFromData(QByteArrayView(buf, len), format);
}

/*!
    \fn bool QImage::loadFromData(const QByteArray &data, const char *format)

    \overload

    Loads an image from the given QByteArray \a data.
*/

/*!
    \since 6.2

    Constructs an image from the given QByteArrayView \a data. The loader attempts to read the image
    using the specified \a format. If \a format is not specified (which is the default), the loader
    probes the data for a header to guess the file format.

    If \a format is specified, it must be one of the values returned by
    QImageReader::supportedImageFormats().

    If the loading of the image fails, the image returned will be a null image.

    \sa load(), save(), {QImage#Reading and Writing Image Files}{Reading and Writing Image Files}
 */

QImage QImage::fromData(QByteArrayView data, const char *format)
{
    QByteArray a = QByteArray::fromRawData(data.constData(), data.size());
    QBuffer b;
    b.setData(a);
    b.open(QIODevice::ReadOnly);
    return QImageReader(&b, format).read();
}

/*!
    \fn QImage QImage::fromData(const uchar *data, int size, const char *format)

    \overload

    Constructs a QImage from the first \a size bytes of the given binary \a data.
*/

QImage QImage::fromData(const uchar *data, int size, const char *format)
{
    return fromData(QByteArrayView(data, size), format);
}

/*!
    \fn QImage QImage::fromData(const QByteArray &data, const char *format)

    \overload

    Constructs a QImage from the given QByteArray \a data.

*/

/*!
    Saves the image to the file with the given \a fileName, using the
    given image file \a format and \a quality factor. If \a format is
    \nullptr, QImage will attempt to guess the format by looking at
    \a fileName's suffix.

    The \a quality factor must be in the range 0 to 100 or -1. Specify
    0 to obtain small compressed files, 100 for large uncompressed
    files, and -1 (the default) to use the default settings.

    Returns \c true if the image was successfully saved; otherwise
    returns \c false.

    \sa {QImage#Reading and Writing Image Files}{Reading and Writing
    Image Files}
*/
bool QImage::save(const QString &fileName, const char *format, int quality) const
{
    if (isNull())
        return false;
    QImageWriter writer(fileName, format);
    return d->doImageIO(this, &writer, quality);
}

/*!
    \overload

    This function writes a QImage to the given \a device.

    This can, for example, be used to save an image directly into a
    QByteArray:

    \snippet image/image.cpp 0
*/

bool QImage::save(QIODevice* device, const char* format, int quality) const
{
    if (isNull())
        return false;                                // nothing to save
    QImageWriter writer(device, format);
    return d->doImageIO(this, &writer, quality);
}

/* \internal
*/

bool QImageData::doImageIO(const QImage *image, QImageWriter *writer, int quality) const
{
    if (quality > 100  || quality < -1)
        qWarning("QImage::save: Quality out of range [-1, 100]");
    if (quality >= 0)
        writer->setQuality(qMin(quality,100));
    const bool result = writer->write(*image);
#ifdef QT_DEBUG
    if (!result)
        qWarning("QImage::save: failed to write image - %s", qPrintable(writer->errorString()));
#endif
    return result;
}

/*****************************************************************************
  QImage stream functions
 *****************************************************************************/
#if !defined(QT_NO_DATASTREAM)
/*!
    \fn QDataStream &operator<<(QDataStream &stream, const QImage &image)
    \relates QImage

    Writes the given \a image to the given \a stream as a PNG image,
    or as a BMP image if the stream's version is 1. Note that writing
    the stream to a file will not produce a valid image file.

    \sa QImage::save(), {Serializing Qt Data Types}
*/

QDataStream &operator<<(QDataStream &s, const QImage &image)
{
    if (s.version() >= 5) {
        if (image.isNull()) {
            s << (qint32) 0; // null image marker
            return s;
        } else {
            s << (qint32) 1;
            // continue ...
        }
    }
    QImageWriter writer(s.device(), s.version() == 1 ? "bmp" : "png");
    writer.write(image);
    return s;
}

/*!
    \fn QDataStream &operator>>(QDataStream &stream, QImage &image)
    \relates QImage

    Reads an image from the given \a stream and stores it in the given
    \a image.

    \sa QImage::load(), {Serializing Qt Data Types}
*/

QDataStream &operator>>(QDataStream &s, QImage &image)
{
    if (s.version() >= 5) {
        qint32 nullMarker;
        s >> nullMarker;
        if (!nullMarker) {
            image = QImage(); // null image
            return s;
        }
    }
    image = QImageReader(s.device(), s.version() == 1 ? "bmp" : "png").read();
    if (image.isNull() && s.version() >= 5)
        s.setStatus(QDataStream::ReadPastEnd);
    return s;
}
#endif // QT_NO_DATASTREAM



/*!
    \fn bool QImage::operator==(const QImage & image) const

    Returns \c true if this image and the given \a image have the same
    contents; otherwise returns \c false.

    The comparison can be slow, unless there is some obvious
    difference (e.g. different size or format), in which case the
    function will return quickly.

    \sa operator=()
*/

bool QImage::operator==(const QImage & i) const
{
    // same object, or shared?
    if (i.d == d)
        return true;
    if (!i.d || !d)
        return false;

    // obviously different stuff?
    if (i.d->height != d->height || i.d->width != d->width || i.d->format != d->format || i.d->colorSpace != d->colorSpace)
        return false;

    if (d->format != Format_RGB32) {
        if (d->format >= Format_ARGB32) { // all bits defined
            const int n = d->width * d->depth / 8;
            if (n == d->bytes_per_line && n == i.d->bytes_per_line) {
                if (memcmp(bits(), i.bits(), d->nbytes))
                    return false;
            } else {
                for (int y = 0; y < d->height; ++y) {
                    if (memcmp(scanLine(y), i.scanLine(y), n))
                        return false;
                }
            }
        } else {
            const int w = width();
            const int h = height();
            const QList<QRgb> &colortable = d->colortable;
            const QList<QRgb> &icolortable = i.d->colortable;
            for (int y=0; y<h; ++y) {
                for (int x=0; x<w; ++x) {
                    if (colortable[pixelIndex(x, y)] != icolortable[i.pixelIndex(x, y)])
                        return false;
                }
            }
        }
    } else {
        //alpha channel undefined, so we must mask it out
        for(int l = 0; l < d->height; l++) {
            int w = d->width;
            const uint *p1 = reinterpret_cast<const uint*>(scanLine(l));
            const uint *p2 = reinterpret_cast<const uint*>(i.scanLine(l));
            while (w--) {
                if ((*p1++ & 0x00ffffff) != (*p2++ & 0x00ffffff))
                    return false;
            }
        }
    }
    return true;
}


/*!
    \fn bool QImage::operator!=(const QImage & image) const

    Returns \c true if this image and the given \a image have different
    contents; otherwise returns \c false.

    The comparison can be slow, unless there is some obvious
    difference, such as different widths, in which case the function
    will return quickly.

    \sa operator=()
*/

bool QImage::operator!=(const QImage & i) const
{
    return !(*this == i);
}




/*!
    Returns the number of pixels that fit horizontally in a physical
    meter. Together with dotsPerMeterY(), this number defines the
    intended scale and aspect ratio of the image.

    \sa setDotsPerMeterX(), {QImage#Image Information}{Image
    Information}
*/
int QImage::dotsPerMeterX() const
{
    return d ? qRound(d->dpmx) : 0;
}

/*!
    Returns the number of pixels that fit vertically in a physical
    meter. Together with dotsPerMeterX(), this number defines the
    intended scale and aspect ratio of the image.

    \sa setDotsPerMeterY(), {QImage#Image Information}{Image
    Information}
*/
int QImage::dotsPerMeterY() const
{
    return d ? qRound(d->dpmy) : 0;
}

/*!
    Sets the number of pixels that fit horizontally in a physical
    meter, to \a x.

    Together with dotsPerMeterY(), this number defines the intended
    scale and aspect ratio of the image, and determines the scale
    at which QPainter will draw graphics on the image. It does not
    change the scale or aspect ratio of the image when it is rendered
    on other paint devices.

    \sa dotsPerMeterX(), {QImage#Image Information}{Image Information}
*/
void QImage::setDotsPerMeterX(int x)
{
    if (!d || !x || d->dpmx == x)
        return;
    detachMetadata();

    if (d)
        d->dpmx = x;
}

/*!
    Sets the number of pixels that fit vertically in a physical meter,
    to \a y.

    Together with dotsPerMeterX(), this number defines the intended
    scale and aspect ratio of the image, and determines the scale
    at which QPainter will draw graphics on the image. It does not
    change the scale or aspect ratio of the image when it is rendered
    on other paint devices.

    \sa dotsPerMeterY(), {QImage#Image Information}{Image Information}
*/
void QImage::setDotsPerMeterY(int y)
{
    if (!d || !y || d->dpmy == y)
        return;
    detachMetadata();

    if (d)
        d->dpmy = y;
}

/*!
    \fn QPoint QImage::offset() const

    Returns the number of pixels by which the image is intended to be
    offset by when positioning relative to other images.

    \sa setOffset(), {QImage#Image Information}{Image Information}
*/
QPoint QImage::offset() const
{
    return d ? d->offset : QPoint();
}


/*!
    \fn void QImage::setOffset(const QPoint& offset)

    Sets the number of pixels by which the image is intended to be
    offset by when positioning relative to other images, to \a offset.

    \sa offset(), {QImage#Image Information}{Image Information}
*/
void QImage::setOffset(const QPoint& p)
{
    if (!d || d->offset == p)
        return;
    detachMetadata();

    if (d)
        d->offset = p;
}

/*!
    Returns the text keys for this image.

    You can use these keys with text() to list the image text for a
    certain key.

    \sa text()
*/
QStringList QImage::textKeys() const
{
    return d ? QStringList(d->text.keys()) : QStringList();
}

/*!
    Returns the image text associated with the given \a key. If the
    specified \a key is an empty string, the whole image text is
    returned, with each key-text pair separated by a newline.

    \sa setText(), textKeys()
*/
QString QImage::text(const QString &key) const
{
    if (!d)
        return QString();

    if (!key.isEmpty())
        return d->text.value(key);

    QString tmp;
    for (auto it = d->text.begin(), end = d->text.end(); it != end; ++it)
        tmp += it.key() + ": "_L1 + it.value().simplified() + "\n\n"_L1;
    if (!tmp.isEmpty())
        tmp.chop(2); // remove final \n\n
    return tmp;
}

/*!
    \fn void QImage::setText(const QString &key, const QString &text)

    Sets the image text to the given \a text and associate it with the
    given \a key.

    If you just want to store a single text block (i.e., a "comment"
    or just a description), you can either pass an empty key, or use a
    generic key like "Description".

    The image text is embedded into the image data when you
    call save() or QImageWriter::write().

    Not all image formats support embedded text. You can find out
    if a specific image or format supports embedding text
    by using QImageWriter::supportsOption(). We give an example:

    \snippet image/supportedformat.cpp 0

    You can use QImageWriter::supportedImageFormats() to find out
    which image formats are available to you.

    \sa text(), textKeys()
*/
void QImage::setText(const QString &key, const QString &value)
{
    if (!d)
        return;
    detachMetadata();

    if (d)
        d->text.insert(key, value);
}

/*!
    \internal

    Used by QPainter to retrieve a paint engine for the image.
*/
QPaintEngine *QImage::paintEngine() const
{
    if (!d)
        return nullptr;

    if (!d->paintEngine) {
        QPaintDevice *paintDevice = const_cast<QImage *>(this);
        QPlatformIntegration *platformIntegration = QGuiApplicationPrivate::platformIntegration();
        if (platformIntegration)
            d->paintEngine = platformIntegration->createImagePaintEngine(paintDevice);
       if (!d->paintEngine)
            d->paintEngine = new QRasterPaintEngine(paintDevice);
    }

    return d->paintEngine;
}


/*!
    \internal

    Returns the size for the specified \a metric on the device.
*/
int QImage::metric(PaintDeviceMetric metric) const
{
    if (!d)
        return 0;

    switch (metric) {
    case PdmWidth:
        return d->width;

    case PdmHeight:
        return d->height;

    case PdmWidthMM:
        return qRound(d->width * 1000 / d->dpmx);

    case PdmHeightMM:
        return qRound(d->height * 1000 / d->dpmy);

    case PdmNumColors:
        return d->colortable.size();

    case PdmDepth:
        return d->depth;

    case PdmDpiX:
        return qRound(d->dpmx * 0.0254);
        break;

    case PdmDpiY:
        return qRound(d->dpmy * 0.0254);
        break;

    case PdmPhysicalDpiX:
        return qRound(d->dpmx * 0.0254);
        break;

    case PdmPhysicalDpiY:
        return qRound(d->dpmy * 0.0254);
        break;

    case PdmDevicePixelRatio:
        return d->devicePixelRatio;
        break;

    case PdmDevicePixelRatioScaled:
        return d->devicePixelRatio * QPaintDevice::devicePixelRatioFScale();
        break;

    case PdmDevicePixelRatioF_EncodedA:
        Q_FALLTHROUGH();
    case PdmDevicePixelRatioF_EncodedB:
        return QPaintDevice::encodeMetricF(metric, d->devicePixelRatio);
        break;

    default:
        qWarning("QImage::metric(): Unhandled metric type %d", metric);
        break;
    }
    return 0;
}



/*****************************************************************************
  QPixmap (and QImage) helper functions
 *****************************************************************************/
/*
  This internal function contains the common (i.e. platform independent) code
  to do a transformation of pixel data. It is used by QPixmap::transform() and by
  QImage::transform().

  \a trueMat is the true transformation matrix (see QPixmap::trueMatrix()) and
  \a xoffset is an offset to the matrix.

  \a msbfirst specifies for 1bpp images, if the MSB or LSB comes first and \a
  depth specifies the colordepth of the data.

  \a dptr is a pointer to the destination data, \a dbpl specifies the bits per
  line for the destination data, \a p_inc is the offset that we advance for
  every scanline and \a dHeight is the height of the destination image.

  \a sprt is the pointer to the source data, \a sbpl specifies the bits per
  line of the source data, \a sWidth and \a sHeight are the width and height of
  the source data.
*/

#undef IWX_MSB
#define IWX_MSB(b)        if (trigx < maxws && trigy < maxhs) {                              \
                            if (*(sptr+sbpl*(trigy>>12)+(trigx>>15)) &                      \
                                 (1 << (7-((trigx>>12)&7))))                              \
                                *dptr |= b;                                              \
                        }                                                              \
                        trigx += m11;                                                      \
                        trigy += m12;
        // END OF MACRO
#undef IWX_LSB
#define IWX_LSB(b)        if (trigx < maxws && trigy < maxhs) {                              \
                            if (*(sptr+sbpl*(trigy>>12)+(trigx>>15)) &                      \
                                 (1 << ((trigx>>12)&7)))                              \
                                *dptr |= b;                                              \
                        }                                                              \
                        trigx += m11;                                                      \
                        trigy += m12;
        // END OF MACRO
#undef IWX_PIX
#define IWX_PIX(b)        if (trigx < maxws && trigy < maxhs) {                              \
                            if ((*(sptr+sbpl*(trigy>>12)+(trigx>>15)) &              \
                                 (1 << (7-((trigx>>12)&7)))) == 0)                      \
                                *dptr &= ~b;                                              \
                        }                                                              \
                        trigx += m11;                                                      \
                        trigy += m12;
        // END OF MACRO
bool qt_xForm_helper(const QTransform &trueMat, int xoffset, int type, int depth,
                     uchar *dptr, qsizetype dbpl, int p_inc, int dHeight,
                     const uchar *sptr, qsizetype sbpl, int sWidth, int sHeight)
{
    int m11 = int(trueMat.m11()*4096.0);
    int m12 = int(trueMat.m12()*4096.0);
    int m21 = int(trueMat.m21()*4096.0);
    int m22 = int(trueMat.m22()*4096.0);
    int dx  = qRound(trueMat.dx()*4096.0);
    int dy  = qRound(trueMat.dy()*4096.0);

    int m21ydx = dx + (xoffset<<16) + (m11 + m21) / 2;
    int m22ydy = dy + (m12 + m22) / 2;
    uint trigx;
    uint trigy;
    uint maxws = sWidth<<12;
    uint maxhs = sHeight<<12;

    for (int y=0; y<dHeight; y++) {                // for each target scanline
        trigx = m21ydx;
        trigy = m22ydy;
        uchar *maxp = dptr + dbpl;
        if (depth != 1) {
            switch (depth) {
                case 8:                                // 8 bpp transform
                while (dptr < maxp) {
                    if (trigx < maxws && trigy < maxhs)
                        *dptr = *(sptr+sbpl*(trigy>>12)+(trigx>>12));
                    trigx += m11;
                    trigy += m12;
                    dptr++;
                }
                break;

                case 16:                        // 16 bpp transform
                while (dptr < maxp) {
                    if (trigx < maxws && trigy < maxhs)
                        *((ushort*)dptr) = *((const ushort *)(sptr+sbpl*(trigy>>12) +
                                                     ((trigx>>12)<<1)));
                    trigx += m11;
                    trigy += m12;
                    dptr++;
                    dptr++;
                }
                break;

                case 24:                        // 24 bpp transform
                while (dptr < maxp) {
                    if (trigx < maxws && trigy < maxhs) {
                        const uchar *p2 = sptr+sbpl*(trigy>>12) + ((trigx>>12)*3);
                        dptr[0] = p2[0];
                        dptr[1] = p2[1];
                        dptr[2] = p2[2];
                    }
                    trigx += m11;
                    trigy += m12;
                    dptr += 3;
                }
                break;

                case 32:                        // 32 bpp transform
                while (dptr < maxp) {
                    if (trigx < maxws && trigy < maxhs)
                        *((uint*)dptr) = *((const uint *)(sptr+sbpl*(trigy>>12) +
                                                   ((trigx>>12)<<2)));
                    trigx += m11;
                    trigy += m12;
                    dptr += 4;
                }
                break;

                default: {
                return false;
                }
            }
        } else  {
            switch (type) {
                case QT_XFORM_TYPE_MSBFIRST:
                    while (dptr < maxp) {
                        IWX_MSB(128);
                        IWX_MSB(64);
                        IWX_MSB(32);
                        IWX_MSB(16);
                        IWX_MSB(8);
                        IWX_MSB(4);
                        IWX_MSB(2);
                        IWX_MSB(1);
                        dptr++;
                    }
                    break;
                case QT_XFORM_TYPE_LSBFIRST:
                    while (dptr < maxp) {
                        IWX_LSB(1);
                        IWX_LSB(2);
                        IWX_LSB(4);
                        IWX_LSB(8);
                        IWX_LSB(16);
                        IWX_LSB(32);
                        IWX_LSB(64);
                        IWX_LSB(128);
                        dptr++;
                    }
                    break;
            }
        }
        m21ydx += m21;
        m22ydy += m22;
        dptr += p_inc;
    }
    return true;
}
#undef IWX_MSB
#undef IWX_LSB
#undef IWX_PIX

/*!
    Returns a number that identifies the contents of this QImage
    object. Distinct QImage objects can only have the same key if they
    refer to the same contents.

    The key will change when the image is altered.
*/
qint64 QImage::cacheKey() const
{
    if (!d)
        return 0;
    else
        return (((qint64) d->ser_no) << 32) | ((qint64) d->detach_no);
}

/*!
    \internal

    Returns \c true if the image is detached; otherwise returns \c false.

    \sa detach(), {Implicit Data Sharing}
*/

bool QImage::isDetached() const
{
    return d && d->ref.loadRelaxed() == 1;
}


/*!
    Sets the alpha channel of this image to the given \a alphaChannel.

    If \a alphaChannel is an 8 bit alpha image, the alpha values are
    used directly. Otherwise, \a alphaChannel is converted to 8 bit
    grayscale and the intensity of the pixel values is used.

    If the image already has an alpha channel, the existing alpha channel
    is multiplied with the new one. If the image doesn't have an alpha
    channel it will be converted to a format that does.

    The operation is similar to painting \a alphaChannel as an alpha image
    over this image using \c QPainter::CompositionMode_DestinationIn.

    \sa hasAlphaChannel(),
        {QImage#Image Transformations}{Image Transformations},
        {QImage#Image Formats}{Image Formats}
*/

void QImage::setAlphaChannel(const QImage &alphaChannel)
{
    if (!d || alphaChannel.isNull())
        return;

    if (d->paintEngine && d->paintEngine->isActive()) {
        qWarning("QImage::setAlphaChannel: "
                 "Unable to set alpha channel while image is being painted on");
        return;
    }

    const Format alphaFormat = qt_alphaVersionForPainting(d->format);
    if (d->format == alphaFormat)
        detach();
    else
        convertTo(alphaFormat);

    if (isNull())
        return;

    QImage sourceImage;
    if (alphaChannel.format() == QImage::Format_Alpha8 || (alphaChannel.d->depth == 8 && alphaChannel.isGrayscale()))
        sourceImage = alphaChannel;
    else
        sourceImage = alphaChannel.convertToFormat(QImage::Format_Grayscale8);
    if (!sourceImage.reinterpretAsFormat(QImage::Format_Alpha8))
        return;

    QPainter painter(this);
    if (sourceImage.size() != size())
        painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    painter.drawImage(rect(), sourceImage);
}

/*!
    Returns \c true if the image has a format that respects the alpha
    channel, otherwise returns \c false.

    \sa {QImage#Image Information}{Image Information}
*/
bool QImage::hasAlphaChannel() const
{
    if (!d)
        return false;
    const QPixelFormat format = pixelFormat();
    if (format.alphaUsage() == QPixelFormat::UsesAlpha)
        return true;
    if (format.colorModel() == QPixelFormat::Indexed)
        return d->has_alpha_clut;
    return false;
}

/*!
    Returns the number of bit planes in the image.

    The number of bit planes is the number of bits of color and
    transparency information for each pixel. This is different from
    (i.e. smaller than) the depth when the image format contains
    unused bits.

    \sa depth(), format(), {QImage#Image Formats}{Image Formats}
*/
int QImage::bitPlaneCount() const
{
    if (!d)
        return 0;
    int bpc = 0;
    switch (d->format) {
    case QImage::Format_Invalid:
        break;
    case QImage::Format_BGR30:
    case QImage::Format_RGB30:
        bpc = 30;
        break;
    case QImage::Format_RGB32:
    case QImage::Format_RGBX8888:
        bpc = 24;
        break;
    case QImage::Format_RGB666:
        bpc = 18;
        break;
    case QImage::Format_RGB555:
        bpc = 15;
        break;
    case QImage::Format_ARGB8555_Premultiplied:
        bpc = 23;
        break;
    case QImage::Format_RGB444:
        bpc = 12;
        break;
    case QImage::Format_RGBX64:
    case QImage::Format_RGBX16FPx4:
        bpc = 48;
        break;
    case QImage::Format_RGBX32FPx4:
        bpc = 96;
        break;
    default:
        bpc = qt_depthForFormat(d->format);
        break;
    }
    return bpc;
}

/*!
   \internal
   Returns a smoothly scaled copy of the image. The returned image has a size
   of width \a w by height \a h pixels.

   The function operates internally on \c Format_RGB32, \c Format_ARGB32_Premultiplied,
   \c Format_RGBX8888, \c Format_RGBA8888_Premultiplied, \c Format_RGBX64,
   or \c Format_RGBA64_Premultiplied and will convert to those formats
   if necessary. To avoid unnecessary conversion the result is returned in the format
   internally used, and not in the original format.
*/
QImage QImage::smoothScaled(int w, int h) const
{
    QImage src = *this;
    switch (src.format()) {
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    case QImage::Format_RGBX8888:
#endif
    case QImage::Format_RGBA8888_Premultiplied:
#if QT_CONFIG(raster_64bit)
    case QImage::Format_RGBX64:
    case QImage::Format_RGBA64_Premultiplied:
        break;
    case QImage::Format_RGBA64:
    case QImage::Format_Grayscale16:
        src.convertTo(QImage::Format_RGBA64_Premultiplied);
        break;
#endif
#if QT_CONFIG(raster_fp)
    case QImage::Format_RGBX32FPx4:
    case QImage::Format_RGBA32FPx4_Premultiplied:
        break;
    case QImage::Format_RGBX16FPx4:
        src.convertTo(QImage::Format_RGBX32FPx4);
        break;
    case QImage::Format_RGBA16FPx4:
    case QImage::Format_RGBA16FPx4_Premultiplied:
    case QImage::Format_RGBA32FPx4:
        src.convertTo(QImage::Format_RGBA32FPx4_Premultiplied);
        break;
#endif
    case QImage::Format_CMYK8888:
        break;
    default:
        if (src.hasAlphaChannel())
            src.convertTo(QImage::Format_ARGB32_Premultiplied);
        else
            src.convertTo(QImage::Format_RGB32);
    }
    src = qSmoothScaleImage(src, w, h);
    if (!src.isNull())
        copyMetadata(src.d, d);
    return src;
}

static QImage rotated90(const QImage &image)
{
    QImage out(image.height(), image.width(), image.format());
    if (out.isNull())
        return out;
    copyMetadata(QImageData::get(out), QImageData::get(image));
    if (image.colorCount() > 0)
        out.setColorTable(image.colorTable());
    int w = image.width();
    int h = image.height();
    const MemRotateFunc memrotate = qMemRotateFunctions[qPixelLayouts[image.format()].bpp][2];
    if (memrotate) {
        memrotate(image.constBits(), w, h, image.bytesPerLine(), out.bits(), out.bytesPerLine());
    } else {
        for (int y=0; y<h; ++y) {
            if (image.colorCount())
                for (int x=0; x<w; ++x)
                    out.setPixel(h-y-1, x, image.pixelIndex(x, y));
            else
                for (int x=0; x<w; ++x)
                    out.setPixel(h-y-1, x, image.pixel(x, y));
        }
    }
    return out;
}

static QImage rotated180(const QImage &image)
{
    const MemRotateFunc memrotate = qMemRotateFunctions[qPixelLayouts[image.format()].bpp][1];
    if (!memrotate)
        return image.flipped(Qt::Horizontal | Qt::Vertical);

    QImage out(image.width(), image.height(), image.format());
    if (out.isNull())
        return out;
    copyMetadata(QImageData::get(out), QImageData::get(image));
    if (image.colorCount() > 0)
        out.setColorTable(image.colorTable());
    int w = image.width();
    int h = image.height();
    memrotate(image.constBits(), w, h, image.bytesPerLine(), out.bits(), out.bytesPerLine());
    return out;
}

static QImage rotated270(const QImage &image)
{
    QImage out(image.height(), image.width(), image.format());
    if (out.isNull())
        return out;
    copyMetadata(QImageData::get(out), QImageData::get(image));
    if (image.colorCount() > 0)
        out.setColorTable(image.colorTable());
    int w = image.width();
    int h = image.height();
    const MemRotateFunc memrotate = qMemRotateFunctions[qPixelLayouts[image.format()].bpp][0];
    if (memrotate) {
        memrotate(image.constBits(), w, h, image.bytesPerLine(), out.bits(), out.bytesPerLine());
    } else {
        for (int y=0; y<h; ++y) {
            if (image.colorCount())
                for (int x=0; x<w; ++x)
                    out.setPixel(y, w-x-1, image.pixelIndex(x, y));
            else
                for (int x=0; x<w; ++x)
                    out.setPixel(y, w-x-1, image.pixel(x, y));
        }
    }
    return out;
}

/*!
    Returns a copy of the image that is transformed using the given
    transformation \a matrix and transformation \a mode.

    The returned image will normally have the same {Image Formats}{format} as
    the original image. However, a complex transformation may result in an
    image where not all pixels are covered by the transformed pixels of the
    original image. In such cases, those background pixels will be assigned a
    transparent color value, and the transformed image will be given a format
    with an alpha channel, even if the original image did not have that.

    The transformation \a matrix is internally adjusted to compensate
    for unwanted translation; i.e. the image produced is the smallest
    image that contains all the transformed points of the original
    image. Use the trueMatrix() function to retrieve the actual matrix
    used for transforming an image.

    Unlike the other overload, this function can be used to perform perspective
    transformations on images.

    \sa trueMatrix(), {QImage#Image Transformations}{Image
    Transformations}
*/

QImage Q_TRACE_INSTRUMENT(qtgui) QImage::transformed(const QTransform &matrix, Qt::TransformationMode mode ) const
{
    if (!d)
        return QImage();

    Q_TRACE_PARAM_REPLACE(const QTransform &, double[9]);
    Q_TRACE_SCOPE(QImage_transformed, QList<double>({matrix.m11(), matrix.m12(), matrix.m13(),
                                                  matrix.m21(), matrix.m22(), matrix.m23(),
                                                  matrix.m31(), matrix.m32(), matrix.m33()}).data(), mode);

    // source image data
    const int ws = width();
    const int hs = height();

    // target image data
    int wd;
    int hd;

    // compute size of target image
    QTransform mat = trueMatrix(matrix, ws, hs);
    bool complex_xform = false;
    bool scale_xform = false;
    bool nonpaintable_scale_xform = false;
    if (mat.type() <= QTransform::TxScale) {
        if (mat.type() == QTransform::TxNone) // identity matrix
            return *this;
        else if (mat.m11() == -1. && mat.m22() == -1.)
            return rotated180(*this);

        hd = qRound(qAbs(mat.m22()) * hs);
        wd = qRound(qAbs(mat.m11()) * ws);
        scale_xform = true;
        // The paint-based scaling is only bilinear, and has problems
        // with scaling smoothly more than 2x down.
        if (hd * 2 < hs || wd * 2 < ws)
            nonpaintable_scale_xform = true;
        // We cannot paint on a CMYK image, so don't try to do so
        if (format() == QImage::Format_CMYK8888)
            nonpaintable_scale_xform = true;
    } else {
        if (mat.type() <= QTransform::TxRotate && mat.m11() == 0 && mat.m22() == 0) {
            if (mat.m12() == 1. && mat.m21() == -1.)
                return rotated90(*this);
            else if (mat.m12() == -1. && mat.m21() == 1.)
                return rotated270(*this);
        }

        QPolygonF a(QRectF(0, 0, ws, hs));
        a = mat.map(a);
        QRect r = a.boundingRect().toAlignedRect();
        wd = r.width();
        hd = r.height();
        complex_xform = true;
    }

    if (wd == 0 || hd == 0)
        return QImage();

    if (scale_xform && mode == Qt::SmoothTransformation) {
        switch (format()) {
        case QImage::Format_RGB32:
        case QImage::Format_ARGB32_Premultiplied:
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
        case QImage::Format_RGBX8888:
#endif
        case QImage::Format_RGBA8888_Premultiplied:
#if QT_CONFIG(raster_64bit)
        case QImage::Format_RGBX64:
        case QImage::Format_RGBA64_Premultiplied:
#endif
        case QImage::Format_CMYK8888:
            // Use smoothScaled for scaling when we can do so without conversion.
            if (mat.m11() > 0.0F && mat.m22() > 0.0F)
                return smoothScaled(wd, hd);
            break;
        default:
            break;
        }
        // Otherwise only use it when the scaling factor demands it, or the image is large enough to scale multi-threaded
        if (nonpaintable_scale_xform
#if QT_CONFIG(qtgui_threadpool)
            || (ws * hs) >= (1<<20)
#endif
            ) {
            QImage scaledImage;
            if (mat.m11() < 0.0F && mat.m22() < 0.0F) { // horizontal/vertical flip
                scaledImage = smoothScaled(wd, hd).flipped(Qt::Horizontal | Qt::Vertical);
            } else if (mat.m11() < 0.0F) { // horizontal flip
                scaledImage = smoothScaled(wd, hd).flipped(Qt::Horizontal);
            } else if (mat.m22() < 0.0F) { // vertical flip
                scaledImage = smoothScaled(wd, hd).flipped(Qt::Vertical);
            } else { // no flipping
                scaledImage = smoothScaled(wd, hd);
            }

            switch (format()) {
            case QImage::Format_Mono:
            case QImage::Format_MonoLSB:
            case QImage::Format_Indexed8:
                return scaledImage;
            default:
                return scaledImage.convertToFormat(format());
            }
        }
    }

    int bpp = depth();

    qsizetype sbpl = bytesPerLine();
    const uchar *sptr = bits();

    QImage::Format target_format = d->format;

    if (complex_xform || mode == Qt::SmoothTransformation) {
        if (d->format < QImage::Format_RGB32 || (!hasAlphaChannel() && complex_xform)) {
            target_format = qt_alphaVersion(d->format);
        }
    }

    QImage dImage(wd, hd, target_format);
    QIMAGE_SANITYCHECK_MEMORY(dImage);

    if (target_format == QImage::Format_MonoLSB
        || target_format == QImage::Format_Mono
        || target_format == QImage::Format_Indexed8) {
        dImage.d->colortable = d->colortable;
        dImage.d->has_alpha_clut = d->has_alpha_clut | complex_xform;
    }

    // initizialize the data
    if (target_format == QImage::Format_Indexed8) {
        if (dImage.d->colortable.size() < 256) {
            // colors are left in the color table, so pick that one as transparent
            dImage.d->colortable.append(0x0);
            memset(dImage.bits(), dImage.d->colortable.size() - 1, dImage.d->nbytes);
        } else {
            memset(dImage.bits(), 0, dImage.d->nbytes);
        }
    } else
        memset(dImage.bits(), 0x00, dImage.d->nbytes);

    if (target_format >= QImage::Format_RGB32 && target_format != QImage::Format_CMYK8888) {
        // Prevent QPainter from applying devicePixelRatio corrections
        QImage sImage = (devicePixelRatio() != 1) ? QImage(constBits(), width(), height(), format()) : *this;
        if (sImage.d != d
            && (d->format == QImage::Format_MonoLSB
             || d->format == QImage::Format_Mono
             || d->format == QImage::Format_Indexed8)) {
            sImage.d->colortable = d->colortable;
            sImage.d->has_alpha_clut = d->has_alpha_clut;
        }

        Q_ASSERT(sImage.devicePixelRatio() == 1);
        Q_ASSERT(sImage.devicePixelRatio() == dImage.devicePixelRatio());

        QPainter p(&dImage);
        if (mode == Qt::SmoothTransformation) {
            p.setRenderHint(QPainter::Antialiasing);
            p.setRenderHint(QPainter::SmoothPixmapTransform);
        }
        p.setTransform(mat);
        p.drawImage(QPoint(0, 0), sImage);
    } else {
        bool invertible;
        mat = mat.inverted(&invertible);                // invert matrix
        if (!invertible)        // error, return null image
            return QImage();

        // create target image (some of the code is from QImage::copy())
        int type = format() == Format_Mono ? QT_XFORM_TYPE_MSBFIRST : QT_XFORM_TYPE_LSBFIRST;
        qsizetype dbpl = dImage.bytesPerLine();
        qt_xForm_helper(mat, 0, type, bpp, dImage.bits(), dbpl, 0, hd, sptr, sbpl, ws, hs);
    }
    copyMetadata(dImage.d, d);

    return dImage;
}

/*!
    \fn QTransform QImage::trueMatrix(const QTransform &matrix, int width, int height)

    Returns the actual matrix used for transforming an image with the
    given \a width, \a height and \a matrix.

    When transforming an image using the transformed() function, the
    transformation matrix is internally adjusted to compensate for
    unwanted translation, i.e. transformed() returns the smallest
    image containing all transformed points of the original image.
    This function returns the modified matrix, which maps points
    correctly from the original image into the new image.

    Unlike the other overload, this function creates transformation
    matrices that can be used to perform perspective
    transformations on images.

    \sa transformed(), {QImage#Image Transformations}{Image
    Transformations}
*/

QTransform QImage::trueMatrix(const QTransform &matrix, int w, int h)
{
    const QRectF rect(0, 0, w, h);
    const QRect mapped = matrix.mapRect(rect).toAlignedRect();
    const QPoint delta = mapped.topLeft();
    return matrix * QTransform().translate(-delta.x(), -delta.y());
}

/*!
    \since 5.14

    Sets the image color space to \a colorSpace without performing any conversions on image data.

    \sa colorSpace()
*/
void QImage::setColorSpace(const QColorSpace &colorSpace)
{
    if (!d)
        return;
    if (d->colorSpace == colorSpace)
        return;
    if (colorSpace.isValid() && !qt_compatibleColorModelSource(pixelFormat().colorModel(), colorSpace.colorModel()))
        return;

    detachMetadata(false);
    if (d)
        d->colorSpace = colorSpace;
}

/*!
    \since 5.14

    Converts the image to \a colorSpace.

    If the image has no valid color space, the method does nothing.

    \note If \a colorSpace is not compatible with the current format, the image
    will be converted to one that is.

    \sa convertedToColorSpace(), setColorSpace()
*/
void QImage::convertToColorSpace(const QColorSpace &colorSpace)
{
    if (!d || !d->colorSpace.isValid())
        return;
    if (!colorSpace.isValidTarget()) {
        qWarning() << "QImage::convertToColorSpace: Output colorspace is not valid";
        return;
    }
    if (d->colorSpace == colorSpace)
        return;
    if (!qt_compatibleColorModelTarget(pixelFormat().colorModel(),
                                       colorSpace.colorModel(), colorSpace.transformModel())) {
        *this = convertedToColorSpace(colorSpace);
        return;
    }
    applyColorTransform(d->colorSpace.transformationToColorSpace(colorSpace));
    if (d->ref.loadRelaxed() != 1)
        detachMetadata(false);
    d->colorSpace = colorSpace;
}

/*!
    \since 6.8

    Converts the image to \a colorSpace and \a format.

    If the image has no valid color space, the method does nothing,
    nor if the color space is not compatible with with the format.

    The specified image conversion \a flags control how the image data
    is handled during the format conversion process.

    \sa convertedToColorSpace(), setColorSpace()
*/
void QImage::convertToColorSpace(const QColorSpace &colorSpace, QImage::Format format, Qt::ImageConversionFlags flags)
{
    if (!d || !d->colorSpace.isValid())
        return;
    if (!colorSpace.isValidTarget()) {
        qWarning() << "QImage::convertToColorSpace: Output colorspace is not valid";
        return;
    }
    if (!qt_compatibleColorModelTarget(toPixelFormat(format).colorModel(),
                                       colorSpace.colorModel(), colorSpace.transformModel())) {
        qWarning() << "QImage::convertToColorSpace: Color space is not compatible with format";
        return;
    }

    if (d->colorSpace == colorSpace)
        return convertTo(format, flags);
    applyColorTransform(d->colorSpace.transformationToColorSpace(colorSpace), format, flags);
    d->colorSpace = colorSpace;
}

/*!
    \since 5.14

    Returns the image converted to \a colorSpace.

    If the image has no valid color space, a null QImage is returned.

    \note If \a colorSpace is not compatible with the current format,
    the returned image will also be converted to a format this is.
    For more control over returned image format, see the three argument
    overload of this method.

    \sa convertToColorSpace(), colorTransformed()
*/
QImage QImage::convertedToColorSpace(const QColorSpace &colorSpace) const
{
    if (!d || !d->colorSpace.isValid())
        return QImage();
    if (!colorSpace.isValidTarget()) {
        qWarning() << "QImage::convertedToColorSpace: Output colorspace is not valid";
        return QImage();
    }
    if (d->colorSpace == colorSpace)
        return *this;
    QImage image = colorTransformed(d->colorSpace.transformationToColorSpace(colorSpace));
    image.setColorSpace(colorSpace);
    return image;
}

/*!
    \fn QImage QImage::convertedToColorSpace(const QColorSpace &colorSpace, QImage::Format format, Qt::ImageConversionFlags flags) const &
    \fn QImage QImage::convertedToColorSpace(const QColorSpace &colorSpace, QImage::Format format, Qt::ImageConversionFlags flags) &&
    \since 6.8

    Returns the image converted to \a colorSpace and \a format.

    If the image has no valid color space, a null QImage is returned.

    The specified image conversion \a flags control how the image data
    is handled during the format conversion process.

    \sa colorTransformed()
*/
QImage QImage::convertedToColorSpace(const QColorSpace &colorSpace, QImage::Format format, Qt::ImageConversionFlags flags) const &
{
    if (!d || !d->colorSpace.isValid())
        return QImage();
    if (!colorSpace.isValidTarget()) {
        qWarning() << "QImage::convertedToColorSpace: Output colorspace is not valid";
        return QImage();
    }
    if (!qt_compatibleColorModelTarget(toPixelFormat(format).colorModel(),
                                       colorSpace.colorModel(), colorSpace.transformModel())) {
        qWarning() << "QImage::convertedToColorSpace: Color space is not compatible with format";
        return QImage();
    }
    if (d->colorSpace == colorSpace)
        return convertedTo(format, flags);
    QImage image = colorTransformed(d->colorSpace.transformationToColorSpace(colorSpace), format, flags);
    image.setColorSpace(colorSpace);
    return image;
}

QImage QImage::convertedToColorSpace(const QColorSpace &colorSpace, QImage::Format format, Qt::ImageConversionFlags flags) &&
{
    if (!d || !d->colorSpace.isValid())
        return QImage();
    if (!colorSpace.isValidTarget()) {
        qWarning() << "QImage::convertedToColorSpace: Output colorspace is not valid";
        return QImage();
    }
    if (!qt_compatibleColorModelTarget(toPixelFormat(format).colorModel(),
                                       colorSpace.colorModel(), colorSpace.transformModel())) {
        qWarning() << "QImage::convertedToColorSpace: Color space is not compatible with format";
        return QImage();
    }
    if (d->colorSpace == colorSpace)
        return convertedTo(format, flags);
    applyColorTransform(d->colorSpace.transformationToColorSpace(colorSpace), format, flags);
    return std::move(*this);
}

/*!
    \since 5.14

    Returns the color space of the image if a color space is defined.
*/
QColorSpace QImage::colorSpace() const
{
    if (!d)
        return QColorSpace();
    return d->colorSpace;
}

/*!
    \since 5.14

    Applies the color transformation \a transform to all pixels in the image.
*/
void QImage::applyColorTransform(const QColorTransform &transform)
{
    if (transform.isIdentity())
        return;

    if (!qt_compatibleColorModelSource(pixelFormat().colorModel(), QColorTransformPrivate::get(transform)->colorSpaceIn->colorModel) ||
        !qt_compatibleColorModelTarget(pixelFormat().colorModel(), QColorTransformPrivate::get(transform)->colorSpaceOut->colorModel,
                                       QColorTransformPrivate::get(transform)->colorSpaceOut->transformModel)) {
        qWarning() << "QImage::applyColorTransform can not apply format switching transform without switching format";
        return;
    }

    detach();
    if (!d)
        return;
    if (pixelFormat().colorModel() == QPixelFormat::Indexed) {
        for (int i = 0; i < d->colortable.size(); ++i)
            d->colortable[i] = transform.map(d->colortable[i]);
        return;
    }
    QImage::Format oldFormat = format();
    if (qt_fpColorPrecision(oldFormat)) {
        if (oldFormat != QImage::Format_RGBX32FPx4 && oldFormat != QImage::Format_RGBA32FPx4
                && oldFormat != QImage::Format_RGBA32FPx4_Premultiplied)
            convertTo(QImage::Format_RGBA32FPx4);
    } else if (depth() > 32) {
        if (oldFormat != QImage::Format_RGBX64 && oldFormat != QImage::Format_RGBA64
                && oldFormat != QImage::Format_RGBA64_Premultiplied)
            convertTo(QImage::Format_RGBA64);
    } else if (oldFormat != QImage::Format_ARGB32 && oldFormat != QImage::Format_RGB32
                && oldFormat != QImage::Format_ARGB32_Premultiplied && oldFormat != QImage::Format_CMYK8888
                && oldFormat != QImage::Format_Grayscale8 && oldFormat != QImage::Format_Grayscale16) {
        if (hasAlphaChannel())
            convertTo(QImage::Format_ARGB32);
        else
            convertTo(QImage::Format_RGB32);
    }

    QColorTransformPrivate::TransformFlags flags = QColorTransformPrivate::Unpremultiplied;
    switch (format()) {
    case Format_ARGB32_Premultiplied:
    case Format_RGBA64_Premultiplied:
    case Format_RGBA32FPx4_Premultiplied:
        flags = QColorTransformPrivate::Premultiplied;
        break;
    case Format_Grayscale8:
    case Format_Grayscale16:
    case Format_RGB32:
    case Format_CMYK8888:
    case Format_RGBX64:
    case Format_RGBX32FPx4:
        flags = QColorTransformPrivate::InputOpaque;
        break;
    case Format_ARGB32:
    case Format_RGBA64:
    case Format_RGBA32FPx4:
        break;
    default:
        Q_UNREACHABLE();
    }

    std::function<void(int,int)> transformSegment;

    if (format() == Format_Grayscale8) {
        transformSegment = [&](int yStart, int yEnd) {
            for (int y = yStart; y < yEnd; ++y) {
                uint8_t *scanline = reinterpret_cast<uint8_t *>(d->data + y * d->bytes_per_line);
                QColorTransformPrivate::get(transform)->apply(scanline, scanline, width(), flags);
            }
        };
    } else if (format() == Format_Grayscale16) {
        transformSegment = [&](int yStart, int yEnd) {
            for (int y = yStart; y < yEnd; ++y) {
                uint16_t *scanline = reinterpret_cast<uint16_t *>(d->data + y * d->bytes_per_line);
                QColorTransformPrivate::get(transform)->apply(scanline, scanline, width(), flags);
            }
        };
    } else if (qt_fpColorPrecision(format())) {
        transformSegment = [&](int yStart, int yEnd) {
            for (int y = yStart; y < yEnd; ++y) {
                QRgbaFloat32 *scanline = reinterpret_cast<QRgbaFloat32 *>(d->data + y * d->bytes_per_line);
                QColorTransformPrivate::get(transform)->apply(scanline, scanline, width(), flags);
            }
        };
    } else  if (depth() > 32) {
        transformSegment = [&](int yStart, int yEnd) {
            for (int y = yStart; y < yEnd; ++y) {
                QRgba64 *scanline = reinterpret_cast<QRgba64 *>(d->data + y * d->bytes_per_line);
                QColorTransformPrivate::get(transform)->apply(scanline, scanline, width(), flags);
            }
        };
    } else if (oldFormat == QImage::Format_CMYK8888) {
        transformSegment = [&](int yStart, int yEnd) {
            for (int y = yStart; y < yEnd; ++y) {
                QCmyk32 *scanline = reinterpret_cast<QCmyk32 *>(d->data + y * d->bytes_per_line);
                QColorTransformPrivate::get(transform)->apply(scanline, scanline, width(), flags);
            }
        };
    } else {
        transformSegment = [&](int yStart, int yEnd) {
            for (int y = yStart; y < yEnd; ++y) {
                QRgb *scanline = reinterpret_cast<QRgb *>(d->data + y * d->bytes_per_line);
                QColorTransformPrivate::get(transform)->apply(scanline, scanline, width(), flags);
            }
        };
    }

#if QT_CONFIG(qtgui_threadpool)
    int segments = (qsizetype(width()) * height()) >> 16;
    segments = std::min(segments, height());
    QThreadPool *threadPool = QGuiApplicationPrivate::qtGuiThreadPool();
    if (segments > 1 && threadPool && !threadPool->contains(QThread::currentThread())) {
        QSemaphore semaphore;
        int y = 0;
        for (int i = 0; i < segments; ++i) {
            int yn = (height() - y) / (segments - i);
            threadPool->start([&, y, yn]() {
                transformSegment(y, y + yn);
                semaphore.release(1);
            });
            y += yn;
        }
        semaphore.acquire(segments);
    } else
#endif
        transformSegment(0, height());

    if (oldFormat != format())
        *this = std::move(*this).convertToFormat(oldFormat);
}

/*!
    \since 6.8

    Applies the color transformation \a transform to all pixels in the image, and converts the format of the image to \a toFormat.

    The specified image conversion \a flags control how the image data
    is handled during the format conversion process.
*/
void QImage::applyColorTransform(const QColorTransform &transform, QImage::Format toFormat, Qt::ImageConversionFlags flags)
{
    if (!d)
        return;
    if (transform.isIdentity())
        return convertTo(toFormat, flags);

    *this = colorTransformed(transform, toFormat, flags);
}

/*!
    \since 6.4

    Returns the image color transformed using \a transform on all pixels in the image.

    \note If \a transform has a source color space which is incompatible with the format of this image,
    returns a null QImage. If \a transform has a target color space which is incompatible with the format
    of this image, the image will also be converted to a compatible format. For more control about the
    choice of the target pixel format, see the three argument overload of this method.

    \sa applyColorTransform()
*/
QImage QImage::colorTransformed(const QColorTransform &transform) const &
{
    if (!d)
        return QImage();
    if (transform.isIdentity())
        return *this;

    const QColorSpacePrivate *inColorSpace = QColorTransformPrivate::get(transform)->colorSpaceIn.constData();
    const QColorSpacePrivate *outColorSpace = QColorTransformPrivate::get(transform)->colorSpaceOut.constData();
    if (!qt_compatibleColorModelSource(pixelFormat().colorModel(), inColorSpace->colorModel)) {
        qWarning() << "QImage::colorTransformed: Invalid input color space for transform";
        return QImage();
    }
    if (!qt_compatibleColorModelTarget(pixelFormat().colorModel(), outColorSpace->colorModel, outColorSpace->transformModel)) {
        // All model switching transforms are opaque in at least one end.
        switch (outColorSpace->colorModel) {
        case QColorSpace::ColorModel::Rgb:
            return colorTransformed(transform, qt_highColorPrecision(format(), true) ? QImage::Format_RGBX64 : QImage::Format_RGB32);
        case QColorSpace::ColorModel::Gray:
            return colorTransformed(transform, qt_highColorPrecision(format(), true) ? QImage::Format_Grayscale16 : QImage::Format_Grayscale8);
        case QColorSpace::ColorModel::Cmyk:
            return colorTransformed(transform, QImage::Format_CMYK8888);
        case QColorSpace::ColorModel::Undefined:
            break;
        }
        return QImage();
    }

    QImage image = copy();
    image.applyColorTransform(transform);
    return image;
}

static bool isRgb32Data(QImage::Format f)
{
    switch (f) {
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied:
        return true;
    default:
        break;
    }
    return false;
}

static bool isRgb64Data(QImage::Format f)
{
    switch (f) {
    case QImage::Format_RGBX64:
    case QImage::Format_RGBA64:
    case QImage::Format_RGBA64_Premultiplied:
        return true;
    default:
        break;
    }
    return false;
}

static bool isRgb32fpx4Data(QImage::Format f)
{
    switch (f) {
    case QImage::Format_RGBX32FPx4:
    case QImage::Format_RGBA32FPx4:
    case QImage::Format_RGBA32FPx4_Premultiplied:
        return true;
    default:
        break;
    }
    return false;
}

/*!
    \since 6.8

    Returns the image color transformed using \a transform on all pixels in the image, returning an image of format \a toFormat.

    The specified image conversion \a flags control how the image data
    is handled during the format conversion process.

    \note If \a transform has a source color space which is incompatible with the format of this image,
    or a target color space that is incompatible with \a toFormat, returns a null QImage.

    \sa applyColorTransform()
*/
QImage QImage::colorTransformed(const QColorTransform &transform, QImage::Format toFormat, Qt::ImageConversionFlags flags) const &
{
    if (!d)
        return QImage();
    if (toFormat == QImage::Format_Invalid)
        toFormat = format();
    if (transform.isIdentity())
        return convertedTo(toFormat, flags);

    const QColorSpacePrivate *inColorSpace = QColorTransformPrivate::get(transform)->colorSpaceIn.constData();
    const QColorSpacePrivate *outColorSpace = QColorTransformPrivate::get(transform)->colorSpaceOut.constData();
    if (!qt_compatibleColorModelSource(pixelFormat().colorModel(), inColorSpace->colorModel)) {
        qWarning() << "QImage::colorTransformed: Invalid input color space for transform";
        return QImage();
    }
    if (!qt_compatibleColorModelTarget(toPixelFormat(toFormat).colorModel(), outColorSpace->colorModel, outColorSpace->transformModel)) {
        qWarning() << "QImage::colorTransformed: Invalid output color space for transform";
        return QImage();
    }

    QImage fromImage = *this;

    QImage::Format tmpFormat = toFormat;
    switch (toFormat) {
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied:
    case QImage::Format_RGBX32FPx4:
    case QImage::Format_RGBA32FPx4:
    case QImage::Format_RGBA32FPx4_Premultiplied:
    case QImage::Format_RGBX64:
    case QImage::Format_RGBA64:
    case QImage::Format_RGBA64_Premultiplied:
    case QImage::Format_Grayscale8:
    case QImage::Format_Grayscale16:
    case QImage::Format_CMYK8888:
        // can be output natively
        break;
    case QImage::Format_RGB16:
    case QImage::Format_RGB444:
    case QImage::Format_RGB555:
    case QImage::Format_RGB666:
    case QImage::Format_RGB888:
    case QImage::Format_BGR888:
    case QImage::Format_RGBX8888:
        tmpFormat = QImage::Format_RGB32;
        break;
    case QImage::Format_Mono:
    case QImage::Format_MonoLSB:
    case QImage::Format_Indexed8:
    case QImage::Format_ARGB8565_Premultiplied:
    case QImage::Format_ARGB6666_Premultiplied:
    case QImage::Format_ARGB8555_Premultiplied:
    case QImage::Format_ARGB4444_Premultiplied:
    case QImage::Format_RGBA8888:
    case QImage::Format_RGBA8888_Premultiplied:
        tmpFormat = QImage::Format_ARGB32;
        break;
    case QImage::Format_BGR30:
    case QImage::Format_RGB30:
        tmpFormat = QImage::Format_RGBX64;
        break;
    case QImage::Format_A2BGR30_Premultiplied:
    case QImage::Format_A2RGB30_Premultiplied:
        tmpFormat = QImage::Format_RGBA64;
        break;
    case QImage::Format_RGBX16FPx4:
    case QImage::Format_RGBA16FPx4:
    case QImage::Format_RGBA16FPx4_Premultiplied:
        tmpFormat = QImage::Format_RGBA32FPx4;
        break;
    case QImage::Format_Alpha8:
        return convertedTo(QImage::Format_Alpha8);
    case QImage::Format_Invalid:
    case QImage::NImageFormats:
        Q_UNREACHABLE();
        break;
    }
    QColorSpace::ColorModel inColorData = qt_csColorData(pixelFormat().colorModel());
    QColorSpace::ColorModel outColorData = qt_csColorData(toPixelFormat(toFormat).colorModel());
    // Ensure only precision increasing transforms
    if (inColorData != outColorData) {
        if (fromImage.format() == QImage::Format_Grayscale8 && outColorData == QColorSpace::ColorModel::Rgb)
            tmpFormat = QImage::Format_RGB32;
        else if (tmpFormat == QImage::Format_Grayscale8 && qt_highColorPrecision(fromImage.format()))
            tmpFormat = QImage::Format_Grayscale16;
        else if (fromImage.format() == QImage::Format_Grayscale16 && outColorData == QColorSpace::ColorModel::Rgb)
            tmpFormat = QImage::Format_RGBX64;
    } else {
        if (tmpFormat == QImage::Format_Grayscale8 && fromImage.format() == QImage::Format_Grayscale16)
            tmpFormat = QImage::Format_Grayscale16;
        else if (qt_fpColorPrecision(fromImage.format()) && !qt_fpColorPrecision(tmpFormat))
            tmpFormat = QImage::Format_RGBA32FPx4;
        else if (isRgb32Data(tmpFormat) && qt_highColorPrecision(fromImage.format(), true))
            tmpFormat = QImage::Format_RGBA64;
    }

    QImage toImage(size(), tmpFormat);
    copyMetadata(&toImage, *this);

    std::function<void(int, int)> transformSegment;
    QColorTransformPrivate::TransformFlags transFlags = QColorTransformPrivate::Unpremultiplied;

    if (inColorData != outColorData) {
        // Needs color model switching transform
        if (inColorData == QColorSpace::ColorModel::Gray && outColorData == QColorSpace::ColorModel::Rgb) {
            // Gray -> RGB
            if (format() == QImage::Format_Grayscale8) {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const quint8 *in_scanline = reinterpret_cast<const quint8 *>(d->data + y * d->bytes_per_line);
                        QRgb *out_scanline = reinterpret_cast<QRgb *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            } else {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const quint16 *in_scanline = reinterpret_cast<const quint16 *>(d->data + y * d->bytes_per_line);
                        QRgba64 *out_scanline = reinterpret_cast<QRgba64 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            }
        } else if (inColorData == QColorSpace::ColorModel::Gray && outColorData == QColorSpace::ColorModel::Cmyk) {
            // Gray -> CMYK
            if (format() == QImage::Format_Grayscale8) {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const quint8 *in_scanline = reinterpret_cast<const quint8 *>(d->data + y * d->bytes_per_line);
                        QCmyk32 *out_scanline = reinterpret_cast<QCmyk32 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            } else {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const quint16 *in_scanline = reinterpret_cast<const quint16 *>(d->data + y * d->bytes_per_line);
                        QCmyk32 *out_scanline = reinterpret_cast<QCmyk32 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            }
        } else if (inColorData == QColorSpace::ColorModel::Rgb && outColorData == QColorSpace::ColorModel::Gray) {
            // RGB -> Gray
            if (tmpFormat == QImage::Format_Grayscale8) {
                fromImage.convertTo(QImage::Format_RGB32);
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QRgb *in_scanline = reinterpret_cast<const QRgb *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        quint8 *out_scanline = reinterpret_cast<quint8 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            } else {
                fromImage.convertTo(QImage::Format_RGBX64);
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QRgba64 *in_scanline = reinterpret_cast<const QRgba64 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        quint16 *out_scanline = reinterpret_cast<quint16 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            }
        } else if (inColorData == QColorSpace::ColorModel::Cmyk && outColorData == QColorSpace::ColorModel::Gray) {
             // CMYK -> Gray
            if (tmpFormat == QImage::Format_Grayscale8) {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QCmyk32 *in_scanline = reinterpret_cast<const QCmyk32 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        quint8 *out_scanline = reinterpret_cast<quint8 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            } else {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QCmyk32 *in_scanline = reinterpret_cast<const QCmyk32 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        quint16 *out_scanline = reinterpret_cast<quint16 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            }
        } else if (inColorData == QColorSpace::ColorModel::Cmyk && outColorData == QColorSpace::ColorModel::Rgb) {
             // CMYK -> RGB
            if (isRgb32Data(tmpFormat) ) {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QCmyk32 *in_scanline = reinterpret_cast<const QCmyk32 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        QRgb *out_scanline = reinterpret_cast<QRgb *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            } else if (isRgb64Data(tmpFormat)) {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QCmyk32 *in_scanline = reinterpret_cast<const QCmyk32 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        QRgba64 *out_scanline = reinterpret_cast<QRgba64 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            } else {
                Q_ASSERT(isRgb32fpx4Data(tmpFormat));
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QCmyk32 *in_scanline = reinterpret_cast<const QCmyk32 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        QRgbaFloat32 *out_scanline = reinterpret_cast<QRgbaFloat32 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), QColorTransformPrivate::InputOpaque);
                    }
                };
            }
        } else if (inColorData == QColorSpace::ColorModel::Rgb && outColorData == QColorSpace::ColorModel::Cmyk) {
            // RGB -> CMYK
            if (!fromImage.hasAlphaChannel())
                transFlags = QColorTransformPrivate::InputOpaque;
            else if (qPixelLayouts[fromImage.format()].premultiplied)
                transFlags = QColorTransformPrivate::Premultiplied;
            if (isRgb32Data(fromImage.format()) ) {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QRgb *in_scanline = reinterpret_cast<const QRgb *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        QCmyk32 *out_scanline = reinterpret_cast<QCmyk32 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    }
                };
            } else if (isRgb64Data(fromImage.format())) {
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QRgba64 *in_scanline = reinterpret_cast<const QRgba64 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        QCmyk32 *out_scanline = reinterpret_cast<QCmyk32 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    }
                };
            } else {
                Q_ASSERT(isRgb32fpx4Data(fromImage.format()));
                transformSegment = [&](int yStart, int yEnd) {
                    for (int y = yStart; y < yEnd; ++y) {
                        const QRgbaFloat32 *in_scanline = reinterpret_cast<const QRgbaFloat32 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                        QCmyk32 *out_scanline = reinterpret_cast<QCmyk32 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    }
                };
            }
        } else {
            Q_UNREACHABLE();
        }
    } else {
        // Conversion on same color model
        if (pixelFormat().colorModel() == QPixelFormat::Indexed) {
            for (int i = 0; i < d->colortable.size(); ++i)
                fromImage.d->colortable[i] = transform.map(d->colortable[i]);
            return fromImage.convertedTo(toFormat, flags);
        }

        QImage::Format oldFormat = format();
        if (qt_fpColorPrecision(oldFormat)) {
            if (oldFormat != QImage::Format_RGBX32FPx4 && oldFormat != QImage::Format_RGBA32FPx4
                && oldFormat != QImage::Format_RGBA32FPx4_Premultiplied)
                fromImage.convertTo(QImage::Format_RGBA32FPx4);
        } else if (qt_highColorPrecision(oldFormat, true)) {
            if (oldFormat != QImage::Format_RGBX64 && oldFormat != QImage::Format_RGBA64
                && oldFormat != QImage::Format_RGBA64_Premultiplied && oldFormat != QImage::Format_Grayscale16)
                fromImage.convertTo(QImage::Format_RGBA64);
        } else if (oldFormat != QImage::Format_ARGB32 && oldFormat != QImage::Format_RGB32
                   && oldFormat != QImage::Format_ARGB32_Premultiplied && oldFormat != QImage::Format_CMYK8888
                   && oldFormat != QImage::Format_Grayscale8 && oldFormat != QImage::Format_Grayscale16) {
            if (hasAlphaChannel())
                fromImage.convertTo(QImage::Format_ARGB32);
            else
                fromImage.convertTo(QImage::Format_RGB32);
        }

        if (!fromImage.hasAlphaChannel())
            transFlags = QColorTransformPrivate::InputOpaque;
        else if (qPixelLayouts[fromImage.format()].premultiplied)
            transFlags = QColorTransformPrivate::Premultiplied;

        if (fromImage.format() == Format_Grayscale8) {
            transformSegment = [&](int yStart, int yEnd) {
                for (int y = yStart; y < yEnd; ++y) {
                    const quint8 *in_scanline = reinterpret_cast<const quint8 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                    if (tmpFormat == Format_Grayscale8) {
                        quint8 *out_scanline = reinterpret_cast<quint8 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    } else {
                        Q_ASSERT(tmpFormat == Format_Grayscale16);
                        quint16 *out_scanline = reinterpret_cast<quint16 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    }
                }
            };
        } else if (fromImage.format() == Format_Grayscale16) {
            transformSegment = [&](int yStart, int yEnd) {
                for (int y = yStart; y < yEnd; ++y) {
                    const quint16 *in_scanline = reinterpret_cast<const quint16 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                    quint16 *out_scanline = reinterpret_cast<quint16 *>(toImage.d->data + y * toImage.bytesPerLine());
                    QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                }
            };
        } else if (fromImage.format() == Format_CMYK8888) {
            Q_ASSERT(tmpFormat == Format_CMYK8888);
            transformSegment = [&](int yStart, int yEnd) {
                for (int y = yStart; y < yEnd; ++y) {
                    const QCmyk32 *in_scanline = reinterpret_cast<const QCmyk32 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                    QCmyk32 *out_scanline = reinterpret_cast<QCmyk32 *>(toImage.d->data + y * toImage.bytesPerLine());
                    QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                }
            };
        } else if (isRgb32fpx4Data(fromImage.format())) {
            Q_ASSERT(isRgb32fpx4Data(tmpFormat));
            transformSegment = [&](int yStart, int yEnd) {
                for (int y = yStart; y < yEnd; ++y) {
                    const QRgbaFloat32 *in_scanline = reinterpret_cast<const QRgbaFloat32 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                    QRgbaFloat32 *out_scanline = reinterpret_cast<QRgbaFloat32 *>(toImage.d->data + y * toImage.bytesPerLine());
                    QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                }
            };
        } else if (isRgb64Data(fromImage.format())) {
            transformSegment = [&](int yStart, int yEnd) {
                for (int y = yStart; y < yEnd; ++y) {
                    const QRgba64 *in_scanline = reinterpret_cast<const QRgba64 *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                    if (isRgb32fpx4Data(tmpFormat)) {
                        QRgbaFloat32 *out_scanline = reinterpret_cast<QRgbaFloat32 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    } else {
                        Q_ASSERT(isRgb64Data(tmpFormat));
                        QRgba64 *out_scanline = reinterpret_cast<QRgba64 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    }
                }
            };
        } else {
            transformSegment = [&](int yStart, int yEnd) {
                for (int y = yStart; y < yEnd; ++y) {
                    const QRgb *in_scanline = reinterpret_cast<const QRgb *>(fromImage.constBits() + y * fromImage.bytesPerLine());
                    if (isRgb32fpx4Data(tmpFormat)) {
                        QRgbaFloat32 *out_scanline = reinterpret_cast<QRgbaFloat32 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    } else if (isRgb64Data(tmpFormat)) {
                        QRgba64 *out_scanline = reinterpret_cast<QRgba64 *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    } else {
                        Q_ASSERT(isRgb32Data(tmpFormat));
                        QRgb *out_scanline = reinterpret_cast<QRgb *>(toImage.d->data + y * toImage.bytesPerLine());
                        QColorTransformPrivate::get(transform)->apply(out_scanline, in_scanline, width(), transFlags);
                    }
                }
            };
        }
    }

#if QT_CONFIG(qtgui_threadpool)
    int segments = (qsizetype(width()) * height()) >> 16;
    segments = std::min(segments, height());
    QThreadPool *threadPool = QGuiApplicationPrivate::qtGuiThreadPool();
    if (segments > 1 && threadPool && !threadPool->contains(QThread::currentThread())) {
        QSemaphore semaphore;
        int y = 0;
        for (int i = 0; i < segments; ++i) {
            int yn = (height() - y) / (segments - i);
            threadPool->start([&, y, yn]() {
                transformSegment(y, y + yn);
                semaphore.release(1);
            });
            y += yn;
        }
        semaphore.acquire(segments);
    } else
#endif
        transformSegment(0, height());

    if (tmpFormat != toFormat)
        toImage.convertTo(toFormat);

    return toImage;
}

/*!
    \since 6.4
    \overload

    Returns the image color transformed using \a transform on all pixels in the image.

    \sa applyColorTransform()
*/
QImage QImage::colorTransformed(const QColorTransform &transform) &&
{
    if (!d)
        return QImage();

    const QColorSpacePrivate *inColorSpace = QColorTransformPrivate::get(transform)->colorSpaceIn.constData();
    const QColorSpacePrivate *outColorSpace = QColorTransformPrivate::get(transform)->colorSpaceOut.constData();
    if (!qt_compatibleColorModelSource(pixelFormat().colorModel(), inColorSpace->colorModel)) {
        qWarning() << "QImage::colorTransformed: Invalid input color space for transform";
        return QImage();
    }
    if (!qt_compatibleColorModelTarget(pixelFormat().colorModel(), outColorSpace->colorModel, outColorSpace->transformModel)) {
        // There is currently no inplace conversion of both colorspace and format, so just use the normal version.
        switch (outColorSpace->colorModel) {
        case QColorSpace::ColorModel::Rgb:
            return colorTransformed(transform, qt_highColorPrecision(format(), true) ? QImage::Format_RGBX64 : QImage::Format_RGB32);
        case QColorSpace::ColorModel::Gray:
            return colorTransformed(transform, qt_highColorPrecision(format(), true) ? QImage::Format_Grayscale16 : QImage::Format_Grayscale8);
        case QColorSpace::ColorModel::Cmyk:
            return colorTransformed(transform, QImage::Format_CMYK8888);
        case QColorSpace::ColorModel::Undefined:
            break;
        }
        return QImage();
    }

    applyColorTransform(transform);
    return std::move(*this);
}

/*!
    \since 6.8
    \overload

    Returns the image color transformed using \a transform on all pixels in the image.

    \sa applyColorTransform()
*/
QImage QImage::colorTransformed(const QColorTransform &transform, QImage::Format format, Qt::ImageConversionFlags flags) &&
{
    // There is currently no inplace conversion of both colorspace and format, so just use the normal version.
    return colorTransformed(transform, format, flags);
}

bool QImageData::convertInPlace(QImage::Format newFormat, Qt::ImageConversionFlags flags)
{
    if (format == newFormat)
        return true;

    // No in-place conversion if we have to detach
    if (ref.loadRelaxed() > 1 || !own_data)
        return false;

    InPlace_Image_Converter converter = qimage_inplace_converter_map[format][newFormat];
    if (converter)
        return converter(this, flags);
    if (format > QImage::Format_Indexed8 && newFormat > QImage::Format_Indexed8 && !qimage_converter_map[format][newFormat]) {
        // Convert inplace generic, but only if there are no direct converters,
        // any direct ones are probably better even if not inplace.
        if (qt_highColorPrecision(newFormat, !qPixelLayouts[newFormat].hasAlphaChannel)
                && qt_highColorPrecision(format, !qPixelLayouts[format].hasAlphaChannel)) {
#if QT_CONFIG(raster_fp)
            if (qt_fpColorPrecision(format) && qt_fpColorPrecision(newFormat))
                return convert_generic_inplace_over_rgba32f(this, newFormat, flags);
#endif
            return convert_generic_inplace_over_rgb64(this, newFormat, flags);
        }
        return convert_generic_inplace(this, newFormat, flags);
    }
    return false;
}

/*!
    \typedef QImage::DataPtr
    \internal
*/

/*!
    \fn DataPtr & QImage::data_ptr()
    \internal
*/

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const QImage &i)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace();
    dbg.noquote();
    dbg << "QImage(";
    if (i.isNull()) {
        dbg << "null";
    } else {
        dbg << i.size() << ",format=" << i.format() << ",depth=" << i.depth();
        if (i.colorCount())
            dbg << ",colorCount=" << i.colorCount();
        const int bytesPerLine = i.bytesPerLine();
        dbg << ",devicePixelRatio=" << i.devicePixelRatio()
            << ",bytesPerLine=" << bytesPerLine << ",sizeInBytes=" << i.sizeInBytes();
        if (dbg.verbosity() > 2 && i.height() > 0) {
            const int outputLength = qMin(bytesPerLine, 24);
            dbg << ",line0="
                << QByteArray(reinterpret_cast<const char *>(i.scanLine(0)), outputLength).toHex()
                << "...";
        }
    }
    dbg << ')';
    return dbg;
}
#endif

static constexpr QPixelFormat pixelformats[] = {
        //QImage::Format_Invalid:
        QPixelFormat(),
        //QImage::Format_Mono:
        QPixelFormat(QPixelFormat::Indexed,
                        /*RED*/            1,
                        /*GREEN*/          0,
                        /*BLUE*/           0,
                        /*FOURTH*/         0,
                        /*FIFTH*/          0,
                        /*ALPHA*/          0,
                        /*ALPHA USAGE*/    QPixelFormat::IgnoresAlpha,
                        /*ALPHA POSITION*/ QPixelFormat::AtBeginning,
                        /*PREMULTIPLIED*/  QPixelFormat::NotPremultiplied,
                        /*INTERPRETATION*/ QPixelFormat::UnsignedByte,
                        /*BYTE ORDER*/     QPixelFormat::CurrentSystemEndian),
        //QImage::Format_MonoLSB:
        QPixelFormat(QPixelFormat::Indexed,
                        /*RED*/            1,
                        /*GREEN*/          0,
                        /*BLUE*/           0,
                        /*FOURTH*/         0,
                        /*FIFTH*/          0,
                        /*ALPHA*/          0,
                        /*ALPHA USAGE*/    QPixelFormat::IgnoresAlpha,
                        /*ALPHA POSITION*/ QPixelFormat::AtBeginning,
                        /*PREMULTIPLIED*/  QPixelFormat::NotPremultiplied,
                        /*INTERPRETATION*/ QPixelFormat::UnsignedByte,
                        /*BYTE ORDER*/     QPixelFormat::CurrentSystemEndian),
        //QImage::Format_Indexed8:
         QPixelFormat(QPixelFormat::Indexed,
                        /*RED*/            8,
                        /*GREEN*/          0,
                        /*BLUE*/           0,
                        /*FOURTH*/         0,
                        /*FIFTH*/          0,
                        /*ALPHA*/          0,
                        /*ALPHA USAGE*/    QPixelFormat::IgnoresAlpha,
                        /*ALPHA POSITION*/ QPixelFormat::AtBeginning,
                        /*PREMULTIPLIED*/  QPixelFormat::NotPremultiplied,
                        /*INTERPRETATION*/ QPixelFormat::UnsignedByte,
                        /*BYTE ORDER*/     QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGB32:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                8,
                     /*GREEN*/              8,
                     /*BLUE*/               8,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              8,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_ARGB32:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                8,
                     /*GREEN*/              8,
                     /*BLUE*/               8,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              8,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_ARGB32_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                8,
                     /*GREEN*/              8,
                     /*BLUE*/               8,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              8,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGB16:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                5,
                     /*GREEN*/              6,
                     /*BLUE*/               5,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              0,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedShort,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_ARGB8565_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                5,
                     /*GREEN*/              6,
                     /*BLUE*/               5,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              8,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGB666:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                6,
                     /*GREEN*/              6,
                     /*BLUE*/               6,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              0,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_ARGB6666_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                6,
                     /*GREEN*/              6,
                     /*BLUE*/               6,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              6,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGB555:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                5,
                     /*GREEN*/              5,
                     /*BLUE*/               5,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              0,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedShort,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_ARGB8555_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                5,
                     /*GREEN*/              5,
                     /*BLUE*/               5,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              8,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGB888:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                8,
                     /*GREEN*/              8,
                     /*BLUE*/               8,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              0,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedByte,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGB444:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                4,
                     /*GREEN*/              4,
                     /*BLUE*/               4,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              0,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedShort,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_ARGB4444_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                4,
                     /*GREEN*/              4,
                     /*BLUE*/               4,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              4,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedShort,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBX8888:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                8,
                     /*GREEN*/              8,
                     /*BLUE*/               8,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              8,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedByte,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBA8888:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                8,
                     /*GREEN*/              8,
                     /*BLUE*/               8,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              8,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedByte,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBA8888_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                8,
                     /*GREEN*/              8,
                     /*BLUE*/               8,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              8,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedByte,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_BGR30:
         QPixelFormat(QPixelFormat::BGR,
                     /*RED*/                10,
                     /*GREEN*/              10,
                     /*BLUE*/               10,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              2,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_A2BGR30_Premultiplied:
         QPixelFormat(QPixelFormat::BGR,
                     /*RED*/                10,
                     /*GREEN*/              10,
                     /*BLUE*/               10,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              2,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGB30:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                10,
                     /*GREEN*/              10,
                     /*BLUE*/               10,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              2,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_A2RGB30_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                10,
                     /*GREEN*/              10,
                     /*BLUE*/               10,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              2,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_Alpha8:
        QPixelFormat(QPixelFormat::Alpha,
                    /*First*/              0,
                    /*SECOND*/             0,
                    /*THIRD*/              0,
                    /*FOURTH*/             0,
                    /*FIFTH*/              0,
                    /*ALPHA*/              8,
                    /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                    /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                    /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                    /*INTERPRETATION*/    QPixelFormat::UnsignedByte,
                    /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_Grayscale8:
        QPixelFormat(QPixelFormat::Grayscale,
                    /*GRAY*/               8,
                    /*SECOND*/             0,
                    /*THIRD*/              0,
                    /*FOURTH*/             0,
                    /*FIFTH*/              0,
                    /*ALPHA*/              0,
                    /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                    /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                    /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                    /*INTERPRETATION*/    QPixelFormat::UnsignedByte,
                    /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBX64:
        QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                16,
                     /*GREEN*/              16,
                     /*BLUE*/               16,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              16,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedShort,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBA64:
        QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                16,
                     /*GREEN*/              16,
                     /*BLUE*/               16,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              16,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedShort,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
         //QImage::Format_RGBA64_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                16,
                     /*GREEN*/              16,
                     /*BLUE*/               16,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              16,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedShort,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_Grayscale16:
        QPixelFormat(QPixelFormat::Grayscale,
                    /*GRAY*/               16,
                    /*SECOND*/             0,
                    /*THIRD*/              0,
                    /*FOURTH*/             0,
                    /*FIFTH*/              0,
                    /*ALPHA*/              0,
                    /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                    /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                    /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                    /*INTERPRETATION*/    QPixelFormat::UnsignedShort,
                    /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_BGR888:
        QPixelFormat(QPixelFormat::BGR,
                    /*RED*/                8,
                    /*GREEN*/              8,
                    /*BLUE*/               8,
                    /*FOURTH*/             0,
                    /*FIFTH*/              0,
                    /*ALPHA*/              0,
                    /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                    /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                    /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                    /*INTERPRETATION*/    QPixelFormat::UnsignedByte,
                    /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBX16FPx4:
        QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                16,
                     /*GREEN*/              16,
                     /*BLUE*/               16,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              16,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::FloatingPoint,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBA16FPx4:
        QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                16,
                     /*GREEN*/              16,
                     /*BLUE*/               16,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              16,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::FloatingPoint,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
         //QImage::Format_RGBA16FPx4_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                16,
                     /*GREEN*/              16,
                     /*BLUE*/               16,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              16,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::FloatingPoint,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBX32FPx4:
        QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                32,
                     /*GREEN*/              32,
                     /*BLUE*/               32,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              32,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::FloatingPoint,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_RGBA32FPx4:
        QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                32,
                     /*GREEN*/              32,
                     /*BLUE*/               32,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              32,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::FloatingPoint,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
         //QImage::Format_RGBA32FPx4_Premultiplied:
         QPixelFormat(QPixelFormat::RGB,
                     /*RED*/                32,
                     /*GREEN*/              32,
                     /*BLUE*/               32,
                     /*FOURTH*/             0,
                     /*FIFTH*/              0,
                     /*ALPHA*/              32,
                     /*ALPHA USAGE*/       QPixelFormat::UsesAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtEnd,
                     /*PREMULTIPLIED*/     QPixelFormat::Premultiplied,
                     /*INTERPRETATION*/    QPixelFormat::FloatingPoint,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
        //QImage::Format_CMYK8888:
        QPixelFormat(QPixelFormat::CMYK,
                     /*RED*/                8,
                     /*GREEN*/              8,
                     /*BLUE*/               8,
                     /*FOURTH*/             8,
                     /*FIFTH*/              0,
                     /*ALPHA*/              0,
                     /*ALPHA USAGE*/       QPixelFormat::IgnoresAlpha,
                     /*ALPHA POSITION*/    QPixelFormat::AtBeginning,
                     /*PREMULTIPLIED*/     QPixelFormat::NotPremultiplied,
                     /*INTERPRETATION*/    QPixelFormat::UnsignedInteger,
                     /*BYTE ORDER*/        QPixelFormat::CurrentSystemEndian),
};
static_assert(sizeof(pixelformats) / sizeof(*pixelformats) == QImage::NImageFormats);

/*!
    Returns the QImage::Format as a QPixelFormat
*/
QPixelFormat QImage::pixelFormat() const noexcept
{
    return toPixelFormat(format());
}

/*!
    Converts \a format into a QPixelFormat
*/
QPixelFormat QImage::toPixelFormat(QImage::Format format) noexcept
{
    Q_ASSERT(static_cast<int>(format) < NImageFormats && static_cast<int>(format) >= 0);
    return pixelformats[format];
}

/*!
    Converts \a format into a QImage::Format
*/
QImage::Format QImage::toImageFormat(QPixelFormat format) noexcept
{
    for (int i = 0; i < NImageFormats; i++) {
        if (format == pixelformats[i])
            return Format(i);
    }
    return Format_Invalid;
}

static inline Qt::Orientations toOrientations(QImageIOHandler::Transformations orient)
{
    Qt::Orientations orients = {};
    if (orient.testFlag(QImageIOHandler::TransformationMirror))
        orients |= Qt::Horizontal;
    if (orient.testFlag(QImageIOHandler::TransformationFlip))
        orients |= Qt::Vertical;
    return orients;
}

Q_GUI_EXPORT void qt_imageTransform(QImage &src, QImageIOHandler::Transformations orient)
{
    if (orient == QImageIOHandler::TransformationNone)
        return;
    if (orient == QImageIOHandler::TransformationRotate270) {
        src = rotated270(src);
    } else {
        src.flip(toOrientations(orient));
        if (orient & QImageIOHandler::TransformationRotate90)
            src = rotated90(src);
    }
}

QMap<QString, QString> qt_getImageText(const QImage &image, const QString &description)
{
    QMap<QString, QString> text = qt_getImageTextFromDescription(description);
    const auto textKeys = image.textKeys();
    for (const QString &key : textKeys) {
        if (!key.isEmpty() && !text.contains(key))
            text.insert(key, image.text(key));
    }
    return text;
}

QMap<QString, QString> qt_getImageTextFromDescription(const QString &description)
{
    QMap<QString, QString> text;
    for (const auto &pair : QStringView{description}.tokenize(u"\n\n")) {
        int index = pair.indexOf(u':');
        if (index >= 0 && pair.indexOf(u' ') < index) {
            if (!pair.trimmed().isEmpty())
                text.insert("Description"_L1, pair.toString().simplified());
        } else {
            const auto key = pair.left(index);
            if (!key.trimmed().isEmpty())
                text.insert(key.toString(), pair.mid(index + 2).toString().simplified());
        }
    }
    return text;
}

QT_END_NAMESPACE

#include "moc_qimage.cpp"
