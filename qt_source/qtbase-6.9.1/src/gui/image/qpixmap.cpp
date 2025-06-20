// Copyright (C) 2021 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include <qglobal.h>

#include "qpixmap.h"
#include <qpa/qplatformpixmap.h>
#include "qimagepixmapcleanuphooks_p.h"

#include "qbitmap.h"
#include "qimage.h"
#include "qpainter.h"
#include "qdatastream.h"
#include "qbuffer.h"
#include <private/qguiapplication_p.h>
#include "qevent.h"
#include "qfile.h"
#include "qfileinfo.h"
#include "qpixmapcache.h"
#include "qdatetime.h"
#include "qimagereader.h"
#include "qimagewriter.h"
#include "qpaintengine.h"
#include "qscreen.h"
#include "qthread.h"
#include "qdebug.h"

#include <qpa/qplatformintegration.h>

#include "qpixmap_raster_p.h"
#include "private/qhexstring_p.h"

#include <qtgui_tracepoints_p.h>

#include <memory>

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

Q_TRACE_PARAM_REPLACE(Qt::AspectRatioMode, int);
Q_TRACE_PARAM_REPLACE(Qt::TransformationMode, int);

// MSVC 19.28 does show spurious warning "C4723: potential divide by 0" for code that divides
// by height() in release builds. Anyhow, all the code paths in this file are only executed
// for valid QPixmap's, where height() cannot be 0. Therefore disable the warning.
QT_WARNING_DISABLE_MSVC(4723)

static bool qt_pixmap_thread_test()
{
    if (Q_UNLIKELY(!QCoreApplication::instance())) {
        qFatal("QPixmap: Must construct a QGuiApplication before a QPixmap");
        return false;
    }
    if (QGuiApplicationPrivate::instance()
        && !QThread::isMainThread()
        && !QGuiApplicationPrivate::platformIntegration()->hasCapability(QPlatformIntegration::ThreadedPixmaps)) {
        qWarning("QPixmap: It is not safe to use pixmaps outside the GUI thread on this platform");
        return false;
    }
    return true;
}

void QPixmap::doInit(int w, int h, int type)
{
    if ((w > 0 && h > 0) || type == QPlatformPixmap::BitmapType)
        data = QPlatformPixmap::create(w, h, (QPlatformPixmap::PixelType) type);
    else
        data = nullptr;
}

/*!
    Constructs a null pixmap.

    \sa isNull()
*/

QPixmap::QPixmap()
    : QPaintDevice()
{
    (void) qt_pixmap_thread_test();
    doInit(0, 0, QPlatformPixmap::PixmapType);
}

/*!
    \fn QPixmap::QPixmap(int width, int height)

    Constructs a pixmap with the given \a width and \a height. If
    either \a width or \a height is zero, a null pixmap is
    constructed.

    \warning This will create a QPixmap with uninitialized data. Call
    fill() to fill the pixmap with an appropriate color before drawing
    onto it with QPainter.

    \sa isNull()
*/

QPixmap::QPixmap(int w, int h)
    : QPixmap(QSize(w, h))
{
}

/*!
    \overload

    Constructs a pixmap of the given \a size.

    \warning This will create a QPixmap with uninitialized data. Call
    fill() to fill the pixmap with an appropriate color before drawing
    onto it with QPainter.
*/

QPixmap::QPixmap(const QSize &size)
    : QPixmap(size, QPlatformPixmap::PixmapType)
{
}

/*!
  \internal
*/
QPixmap::QPixmap(const QSize &s, int type)
{
    if (!qt_pixmap_thread_test())
        doInit(0, 0, static_cast<QPlatformPixmap::PixelType>(type));
    else
        doInit(s.width(), s.height(), static_cast<QPlatformPixmap::PixelType>(type));
}

/*!
    \internal
*/
QPixmap::QPixmap(QPlatformPixmap *d)
    : QPaintDevice(), data(d)
{
}

/*!
    Constructs a pixmap from the file with the given \a fileName. If the
    file does not exist or is of an unknown format, the pixmap becomes a
    null pixmap.

    The loader attempts to read the pixmap using the specified \a
    format. If the \a format is not specified (which is the default),
    the loader probes the file for a header to guess the file format.

    The file name can either refer to an actual file on disk or to
    one of the application's embedded resources. See the
    \l{resources.html}{Resource System} overview for details on how
    to embed images and other resource files in the application's
    executable.

    If the image needs to be modified to fit in a lower-resolution
    result (e.g. converting from 32-bit to 8-bit), use the \a
    flags to control the conversion.

    The \a fileName, \a format and \a flags parameters are
    passed on to load(). This means that the data in \a fileName is
    not compiled into the binary. If \a fileName contains a relative
    path (e.g. the filename only) the relevant file must be found
    relative to the runtime working directory.

    \sa {QPixmap#Reading and Writing Image Files}{Reading and Writing
    Image Files}
*/

QPixmap::QPixmap(const QString& fileName, const char *format, Qt::ImageConversionFlags flags)
    : QPaintDevice()
{
    doInit(0, 0, QPlatformPixmap::PixmapType);
    if (!qt_pixmap_thread_test())
        return;

    load(fileName, format, flags);
}

/*!
    Constructs a pixmap that is a copy of the given \a pixmap.

    \sa copy()
*/

QPixmap::QPixmap(const QPixmap &pixmap)
    : QPaintDevice()
{
    if (!qt_pixmap_thread_test()) {
        doInit(0, 0, QPlatformPixmap::PixmapType);
        return;
    }
    if (pixmap.paintingActive()) {                // make a deep copy
        pixmap.copy().swap(*this);
    } else {
        data = pixmap.data;
    }
}

/*! \fn QPixmap::QPixmap(QPixmap &&other)
    Move-constructs a QPixmap instance from \a other.

    \sa swap() operator=(QPixmap&&)
*/

QT_DEFINE_QESDP_SPECIALIZATION_DTOR(QPlatformPixmap)

/*!
    Constructs a pixmap from the given \a xpm data, which must be a
    valid XPM image.

    Errors are silently ignored.

    Note that it's possible to squeeze the XPM variable a little bit
    by using an unusual declaration:

    \snippet code/src_gui_image_qimage.cpp 2

    The extra \c const makes the entire definition read-only, which is
    slightly more efficient (for example, when the code is in a shared
    library) and ROMable when the application is to be stored in ROM.
*/
#ifndef QT_NO_IMAGEFORMAT_XPM
QPixmap::QPixmap(const char * const xpm[])
    : QPaintDevice()
{
    doInit(0, 0, QPlatformPixmap::PixmapType);
    if (!xpm)
        return;

    QImage image(xpm);
    if (!image.isNull()) {
        if (data && data->pixelType() == QPlatformPixmap::BitmapType)
            *this = QBitmap::fromImage(std::move(image));
        else
            *this = fromImage(std::move(image));
    }
}
#endif


/*!
    Destroys the pixmap.
*/

QPixmap::~QPixmap()
{
    Q_ASSERT(!data || data->ref.loadRelaxed() >= 1); // Catch if ref-counting changes again
}

/*!
  \internal
*/
int QPixmap::devType() const
{
    return QInternal::Pixmap;
}

/*!
    \fn QPixmap QPixmap::copy(int x, int y, int width, int height) const
    \overload

    Returns a deep copy of the subset of the pixmap that is specified
    by the rectangle QRect( \a x, \a y, \a width, \a height).
*/

/*!
    \fn QPixmap QPixmap::copy(const QRect &rectangle) const

    Returns a deep copy of the subset of the pixmap that is specified
    by the given \a rectangle. For more information on deep copies,
    see the \l {Implicit Data Sharing} documentation.

    If the given \a rectangle is empty, the whole image is copied.

    \sa operator=(), QPixmap(), {QPixmap#Pixmap
    Transformations}{Pixmap Transformations}
*/
QPixmap QPixmap::copy(const QRect &rect) const
{
    if (isNull())
        return QPixmap();

    QRect r(0, 0, width(), height());
    if (!rect.isEmpty())
        r = r.intersected(rect);

    QPlatformPixmap *d = data->createCompatiblePlatformPixmap();
    d->copy(data.data(), r);
    return QPixmap(d);
}

/*!
    \fn QPixmap::scroll(int dx, int dy, int x, int y, int width, int height, QRegion *exposed)

    This convenience function is equivalent to calling QPixmap::scroll(\a dx,
    \a dy, QRect(\a x, \a y, \a width, \a height), \a exposed).

    \sa QWidget::scroll(), QGraphicsItem::scroll()
*/

/*!
    Scrolls the area \a rect of this pixmap by (\a dx, \a dy). The exposed
    region is left unchanged. You can optionally pass a pointer to an empty
    QRegion to get the region that is \a exposed by the scroll operation.

    \snippet code/src_gui_image_qpixmap.cpp 2

    You cannot scroll while there is an active painter on the pixmap.

    \sa QWidget::scroll(), QGraphicsItem::scroll()
*/
void QPixmap::scroll(int dx, int dy, const QRect &rect, QRegion *exposed)
{
    if (isNull() || (dx == 0 && dy == 0))
        return;
    QRect dest = rect & this->rect();
    QRect src = dest.translated(-dx, -dy) & dest;
    if (src.isEmpty()) {
        if (exposed)
            *exposed += dest;
        return;
    }

    detach();

    if (!data->scroll(dx, dy, src)) {
        // Fallback
        QPixmap pix = *this;
        QPainter painter(&pix);
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.drawPixmap(src.translated(dx, dy), *this, src);
        painter.end();
        *this = pix;
    }

    if (exposed) {
        *exposed += dest;
        *exposed -= src.translated(dx, dy);
    }
}

/*!
    Assigns the given \a pixmap to this pixmap and returns a reference
    to this pixmap.

    \sa copy(), QPixmap()
*/

QPixmap &QPixmap::operator=(const QPixmap &pixmap)
{
    if (paintingActive()) {
        qWarning("QPixmap::operator=: Cannot assign to pixmap during painting");
        return *this;
    }
    if (pixmap.paintingActive()) {                // make a deep copy
        pixmap.copy().swap(*this);
    } else {
        data = pixmap.data;
    }
    return *this;
}

/*!
    \fn QPixmap &QPixmap::operator=(QPixmap &&other)

    Move-assigns \a other to this QPixmap instance.

    \since 5.2
*/

/*!
    \fn void QPixmap::swap(QPixmap &other)
    \memberswap{pixmap}
*/

/*!
   Returns the pixmap as a QVariant.
*/
QPixmap::operator QVariant() const
{
    return QVariant::fromValue(*this);
}

/*!
    \fn bool QPixmap::operator!() const

    Returns \c true if this is a null pixmap; otherwise returns \c false.

    \sa isNull()
*/

/*!
    Converts the pixmap to a QImage. Returns a null image if the
    conversion fails.

    If the pixmap has 1-bit depth, the returned image will also be 1
    bit deep. Images with more bits will be returned in a format
    closely represents the underlying system. Usually this will be
    QImage::Format_ARGB32_Premultiplied for pixmaps with an alpha and
    QImage::Format_RGB32 or QImage::Format_RGB16 for pixmaps without
    alpha.

    Note that for the moment, alpha masks on monochrome images are
    ignored.

    \sa fromImage(), {QImage#Image Formats}{Image Formats}
*/
QImage QPixmap::toImage() const
{
    if (isNull())
        return QImage();

    return data->toImage();
}

/*!
    \fn QTransform QPixmap::trueMatrix(const QTransform &matrix, int width, int height)

    Returns the actual matrix used for transforming a pixmap with the
    given \a width, \a height and \a matrix.

    When transforming a pixmap using the transformed() function, the
    transformation matrix is internally adjusted to compensate for
    unwanted translation, i.e. transformed() returns the smallest
    pixmap containing all transformed points of the original
    pixmap. This function returns the modified matrix, which maps
    points correctly from the original pixmap into the new pixmap.

    \sa transformed(), {QPixmap#Pixmap Transformations}{Pixmap
    Transformations}
*/
QTransform QPixmap::trueMatrix(const QTransform &m, int w, int h)
{
    return QImage::trueMatrix(m, w, h);
}

/*!
    \fn bool QPixmap::isQBitmap() const

    Returns \c true if this is a QBitmap; otherwise returns \c false.
*/

bool QPixmap::isQBitmap() const
{
    return data && data->type == QPlatformPixmap::BitmapType;
}

/*!
    \fn bool QPixmap::isNull() const

    Returns \c true if this is a null pixmap; otherwise returns \c false.

    A null pixmap has zero width, zero height and no contents. You
    cannot draw in a null pixmap.
*/
bool QPixmap::isNull() const
{
    return !data || data->isNull();
}

/*!
    \fn int QPixmap::width() const

    Returns the width of the pixmap.

    \sa size(), {QPixmap#Pixmap Information}{Pixmap Information}
*/
int QPixmap::width() const
{
    return data ? data->width() : 0;
}

/*!
    \fn int QPixmap::height() const

    Returns the height of the pixmap.

    \sa size(), {QPixmap#Pixmap Information}{Pixmap Information}
*/
int QPixmap::height() const
{
    return data ? data->height() : 0;
}

/*!
    \fn QSize QPixmap::size() const

    Returns the size of the pixmap.

    \sa width(), height(), {QPixmap#Pixmap Information}{Pixmap
    Information}
*/
QSize QPixmap::size() const
{
    return data ? QSize(data->width(), data->height()) : QSize(0, 0);
}

/*!
    \fn QRect QPixmap::rect() const

    Returns the pixmap's enclosing rectangle.

    \sa {QPixmap#Pixmap Information}{Pixmap Information}
*/
QRect QPixmap::rect() const
{
    return data ? QRect(0, 0, data->width(), data->height()) : QRect();
}

/*!
    \fn int QPixmap::depth() const

    Returns the depth of the pixmap.

    The pixmap depth is also called bits per pixel (bpp) or bit planes
    of a pixmap. A null pixmap has depth 0.

    \sa defaultDepth(), {QPixmap#Pixmap Information}{Pixmap
    Information}
*/
int QPixmap::depth() const
{
    return data ? data->depth() : 0;
}

/*!
    Sets a mask bitmap.

    This function merges the \a mask with the pixmap's alpha channel. A pixel
    value of 1 on the mask means the pixmap's pixel is unchanged; a value of 0
    means the pixel is transparent. The mask must have the same size as this
    pixmap.

    Setting a null mask resets the mask, leaving the previously transparent
    pixels black. The effect of this function is undefined when the pixmap is
    being painted on.

    \warning This is potentially an expensive operation.

    \sa mask(), {QPixmap#Pixmap Transformations}{Pixmap Transformations},
    QBitmap
*/
void QPixmap::setMask(const QBitmap &mask)
{
    if (paintingActive()) {
        qWarning("QPixmap::setMask: Cannot set mask while pixmap is being painted on");
        return;
    }

    if (!mask.isNull() && mask.size() != size()) {
        qWarning("QPixmap::setMask() mask size differs from pixmap size");
        return;
    }

    if (isNull())
        return;

    if (static_cast<const QPixmap &>(mask).data == data) // trying to selfmask
       return;

    detach();
    data->setMask(mask);
}

/*!
    Returns the device pixel ratio for the pixmap. This is the
    ratio between \e{device pixels} and \e{device independent pixels}.

    Use this function when calculating layout geometry based on
    the pixmap size: QSize layoutSize = image.size() / image.devicePixelRatio()

    The default value is 1.0.

    \sa setDevicePixelRatio(), QImageReader
*/
qreal QPixmap::devicePixelRatio() const
{
    if (!data)
        return qreal(1.0);
    return data->devicePixelRatio();
}

/*!
    Sets the device pixel ratio for the pixmap. This is the
    ratio between image pixels and device-independent pixels.

    The default \a scaleFactor is 1.0. Setting it to something else has
    two effects:

    QPainters that are opened on the pixmap will be scaled. For
    example, painting on a 200x200 image if with a ratio of 2.0
    will result in effective (device-independent) painting bounds
    of 100x100.

    Code paths in Qt that calculate layout geometry based on the
    pixmap size will take the ratio into account:
    QSize layoutSize = pixmap.size() / pixmap.devicePixelRatio()
    The net effect of this is that the pixmap is displayed as
    high-DPI pixmap rather than a large pixmap
    (see \l{Drawing High Resolution Versions of Pixmaps and Images}).

    \sa devicePixelRatio(), deviceIndependentSize()
*/
void QPixmap::setDevicePixelRatio(qreal scaleFactor)
{
    if (isNull())
        return;

    if (scaleFactor == data->devicePixelRatio())
        return;

    detach();
    data->setDevicePixelRatio(scaleFactor);
}

/*!
    Returns the size of the pixmap in device independent pixels.

    This value should be used when using the pixmap size in user interface
    size calculations.

    The return value is equivalent to pixmap.size() / pixmap.devicePixelRatio().

    \since 6.2
*/
QSizeF QPixmap::deviceIndependentSize() const
{
    if (!data)
        return QSizeF(0, 0);
    return QSizeF(data->width(), data->height()) / data->devicePixelRatio();
}

#ifndef QT_NO_IMAGE_HEURISTIC_MASK
/*!
    Creates and returns a heuristic mask for this pixmap.

    The function works by selecting a color from one of the corners
    and then chipping away pixels of that color, starting at all the
    edges.  If \a clipTight is true (the default) the mask is just
    large enough to cover the pixels; otherwise, the mask is larger
    than the data pixels.

    The mask may not be perfect but it should be reasonable, so you
    can do things such as the following:

    \snippet code/src_gui_image_qpixmap.cpp 1

    This function is slow because it involves converting to/from a
    QImage, and non-trivial computations.

    \sa QImage::createHeuristicMask(), createMaskFromColor()
*/
QBitmap QPixmap::createHeuristicMask(bool clipTight) const
{
    QBitmap m = QBitmap::fromImage(toImage().createHeuristicMask(clipTight));
    return m;
}
#endif

/*!
    Creates and returns a mask for this pixmap based on the given \a
    maskColor. If the \a mode is Qt::MaskInColor, all pixels matching the
    maskColor will be transparent. If \a mode is Qt::MaskOutColor, all pixels
    matching the maskColor will be opaque.

    This function is slow because it involves converting to/from a
    QImage.

    \sa createHeuristicMask(), QImage::createMaskFromColor()
*/
QBitmap QPixmap::createMaskFromColor(const QColor &maskColor, Qt::MaskMode mode) const
{
    QImage image = toImage().convertToFormat(QImage::Format_ARGB32);
    return QBitmap::fromImage(std::move(image).createMaskFromColor(maskColor.rgba(), mode));
}

/*!
    Loads a pixmap from the file with the given \a fileName. Returns
    true if the pixmap was successfully loaded; otherwise invalidates
    the pixmap and returns \c false.

    The loader attempts to read the pixmap using the specified \a
    format. If the \a format is not specified (which is the default),
    the loader probes the file for a header to guess the file format.

    The file name can either refer to an actual file on disk or to one
    of the application's embedded resources. See the
    \l{resources.html}{Resource System} overview for details on how to
    embed pixmaps and other resource files in the application's
    executable.

    If the data needs to be modified to fit in a lower-resolution
    result (e.g. converting from 32-bit to 8-bit), use the \a flags to
    control the conversion.

    Note that QPixmaps are automatically added to the QPixmapCache
    when loaded from a file in main thread; the key used is internal
    and cannot be acquired.

    \sa loadFromData(), {QPixmap#Reading and Writing Image
    Files}{Reading and Writing Image Files}
*/

bool QPixmap::load(const QString &fileName, const char *format, Qt::ImageConversionFlags flags)
{
    if (!fileName.isEmpty()) {

        QFileInfo info(fileName);
        // Note: If no extension is provided, we try to match the
        // file against known plugin extensions
        if (info.completeSuffix().isEmpty() || info.exists()) {
            const bool inGuiThread = qApp->thread() == QThread::currentThread();

            QString key = "qt_pixmap"_L1
                    % info.absoluteFilePath()
                    % HexString<uint>(info.lastModified(QTimeZone::UTC).toSecsSinceEpoch())
                    % HexString<quint64>(info.size())
                    % HexString<uint>(data ? data->pixelType() : QPlatformPixmap::PixmapType);

            if (inGuiThread && QPixmapCache::find(key, this))
                return true;

            data = QPlatformPixmap::create(0, 0, data ? data->pixelType() : QPlatformPixmap::PixmapType);

            if (data->fromFile(fileName, format, flags)) {
                if (inGuiThread)
                    QPixmapCache::insert(key, *this);
                return true;
            }
        }
    }

    if (!isNull()) {
        if (isQBitmap())
            *this = QBitmap();
        else
            data.reset();
    }
    return false;
}

/*!
    \fn bool QPixmap::loadFromData(const uchar *data, uint len, const char *format, Qt::ImageConversionFlags flags)

    Loads a pixmap from the \a len first bytes of the given binary \a
    data.  Returns \c true if the pixmap was loaded successfully;
    otherwise invalidates the pixmap and returns \c false.

    The loader attempts to read the pixmap using the specified \a
    format. If the \a format is not specified (which is the default),
    the loader probes the file for a header to guess the file format.

    If the data needs to be modified to fit in a lower-resolution
    result (e.g. converting from 32-bit to 8-bit), use the \a flags to
    control the conversion.

    \sa load(), {QPixmap#Reading and Writing Image Files}{Reading and
    Writing Image Files}
*/

bool QPixmap::loadFromData(const uchar *buf, uint len, const char *format, Qt::ImageConversionFlags flags)
{
    if (len == 0 || buf == nullptr) {
        data.reset();
        return false;
    }

    data = QPlatformPixmap::create(0, 0, QPlatformPixmap::PixmapType);

    if (data->fromData(buf, len, format, flags))
        return true;

    data.reset();
    return false;
}

/*!
    \fn bool QPixmap::loadFromData(const QByteArray &data, const char *format, Qt::ImageConversionFlags flags)

    \overload

    Loads a pixmap from the binary \a data using the specified \a
    format and conversion \a flags.
*/


/*!
    Saves the pixmap to the file with the given \a fileName using the
    specified image file \a format and \a quality factor. Returns \c true
    if successful; otherwise returns \c false.

    The \a quality factor must be in the range [0,100] or -1. Specify
    0 to obtain small compressed files, 100 for large uncompressed
    files, and -1 to use the default settings.

    If \a format is \nullptr, an image format will be chosen from
    \a fileName's suffix.

    \sa {QPixmap#Reading and Writing Image Files}{Reading and Writing
    Image Files}
*/

bool QPixmap::save(const QString &fileName, const char *format, int quality) const
{
    if (isNull())
        return false;                                // nothing to save
    QImageWriter writer(fileName, format);
    return doImageIO(&writer, quality);
}

/*!
    \overload

    This function writes a QPixmap to the given \a device using the
    specified image file \a format and \a quality factor. This can be
    used, for example, to save a pixmap directly into a QByteArray:

    \snippet image/image.cpp 1
*/

bool QPixmap::save(QIODevice* device, const char* format, int quality) const
{
    if (isNull())
        return false;                                // nothing to save
    QImageWriter writer(device, format);
    return doImageIO(&writer, quality);
}

/*! \internal
*/
bool QPixmap::doImageIO(QImageWriter *writer, int quality) const
{
    if (quality > 100  || quality < -1)
        qWarning("QPixmap::save: quality out of range [-1,100]");
    if (quality >= 0)
        writer->setQuality(qMin(quality,100));
    return writer->write(toImage());
}


/*!
    Fills the pixmap with the given \a color.

    The effect of this function is undefined when the pixmap is
    being painted on.

    \sa {QPixmap#Pixmap Transformations}{Pixmap Transformations}
*/

void QPixmap::fill(const QColor &color)
{
    if (isNull())
        return;

    // Some people are probably already calling fill while a painter is active, so to not break
    // their programs, only print a warning and return when the fill operation could cause a crash.
    if (paintingActive() && (color.alpha() != 255) && !hasAlphaChannel()) {
        qWarning("QPixmap::fill: Cannot fill while pixmap is being painted on");
        return;
    }

    if (data->ref.loadRelaxed() == 1) {
        // detach() will also remove this pixmap from caches, so
        // it has to be called even when ref == 1.
        detach();
    } else {
        // Don't bother to make a copy of the data object, since
        // it will be filled with new pixel data anyway.
        QPlatformPixmap *d = data->createCompatiblePlatformPixmap();
        d->resize(data->width(), data->height());
        d->setDevicePixelRatio(data->devicePixelRatio());
        data = d;
    }
    data->fill(color);
}

/*!
    Returns a number that identifies this QPixmap. Distinct QPixmap
    objects can only have the same cache key if they refer to the same
    contents.

    The cacheKey() will change when the pixmap is altered.
*/
qint64 QPixmap::cacheKey() const
{
    if (isNull())
        return 0;

    Q_ASSERT(data);
    return data->cacheKey();
}

#if 0
static void sendResizeEvents(QWidget *target)
{
    QResizeEvent e(target->size(), QSize());
    QApplication::sendEvent(target, &e);

    const QObjectList children = target->children();
    for (int i = 0; i < children.size(); ++i) {
        QWidget *child = static_cast<QWidget*>(children.at(i));
        if (child->isWidgetType() && !child->isWindow() && child->testAttribute(Qt::WA_PendingResizeEvent))
            sendResizeEvents(child);
    }
}
#endif


/*****************************************************************************
  QPixmap stream functions
 *****************************************************************************/
#if !defined(QT_NO_DATASTREAM)
/*!
    \relates QPixmap

    Writes the given \a pixmap to the given \a stream as a PNG
    image. Note that writing the stream to a file will not produce a
    valid image file.

    \sa QPixmap::save(), {Serializing Qt Data Types}
*/

QDataStream &operator<<(QDataStream &stream, const QPixmap &pixmap)
{
    return stream << pixmap.toImage();
}

/*!
    \relates QPixmap

    Reads an image from the given \a stream into the given \a pixmap.

    \sa QPixmap::load(), {Serializing Qt Data Types}
*/

QDataStream &operator>>(QDataStream &stream, QPixmap &pixmap)
{
    QImage image;
    stream >> image;

    if (image.isNull()) {
        pixmap = QPixmap();
    } else if (image.depth() == 1) {
        pixmap = QBitmap::fromImage(std::move(image));
    } else {
        pixmap = QPixmap::fromImage(std::move(image));
    }
    return stream;
}

#endif // QT_NO_DATASTREAM

/*!
    \internal
*/

bool QPixmap::isDetached() const
{
    return data && data->ref.loadRelaxed() == 1;
}

/*!
    Replaces this pixmap's data with the given \a image using the
    specified \a flags to control the conversion.  The \a flags
    argument is a bitwise-OR of the \l{Qt::ImageConversionFlags}.
    Passing 0 for \a flags sets all the default options. Returns \c true
    if the result is that this pixmap is not null.

    \sa fromImage()
*/
bool QPixmap::convertFromImage(const QImage &image, Qt::ImageConversionFlags flags)
{
    detach();
    if (image.isNull() || !data)
        *this = QPixmap::fromImage(image, flags);
    else
        data->fromImage(image, flags);
    return !isNull();
}

/*!
    \fn QPixmap QPixmap::scaled(int width, int height,
    Qt::AspectRatioMode aspectRatioMode, Qt::TransformationMode
    transformMode) const

    \overload

    Returns a copy of the pixmap scaled to a rectangle with the given
    \a width and \a height according to the given \a aspectRatioMode and
    \a transformMode.

    If either the \a width or the \a height is zero or negative, this
    function returns a null pixmap.
*/

/*!
    \fn QPixmap QPixmap::scaled(const QSize &size, Qt::AspectRatioMode
    aspectRatioMode, Qt::TransformationMode transformMode) const

    Scales the pixmap to the given \a size, using the aspect ratio and
    transformation modes specified by \a aspectRatioMode and \a
    transformMode.

    \image qimage-scaling.png

    \list
    \li If \a aspectRatioMode is Qt::IgnoreAspectRatio, the pixmap
       is scaled to \a size.
    \li If \a aspectRatioMode is Qt::KeepAspectRatio, the pixmap is
       scaled to a rectangle as large as possible inside \a size, preserving the aspect ratio.
    \li If \a aspectRatioMode is Qt::KeepAspectRatioByExpanding,
       the pixmap is scaled to a rectangle as small as possible
       outside \a size, preserving the aspect ratio.
    \endlist

    If the given \a size is empty, this function returns a null
    pixmap.


    In some cases it can be more beneficial to draw the pixmap to a
    painter with a scale set rather than scaling the pixmap. This is
    the case when the painter is for instance based on OpenGL or when
    the scale factor changes rapidly.

    \sa isNull(), {QPixmap#Pixmap Transformations}{Pixmap
    Transformations}

*/
QPixmap Q_TRACE_INSTRUMENT(qtgui) QPixmap::scaled(const QSize& s, Qt::AspectRatioMode aspectMode, Qt::TransformationMode mode) const
{
    if (isNull()) {
        qWarning("QPixmap::scaled: Pixmap is a null pixmap");
        return QPixmap();
    }
    if (s.isEmpty())
        return QPixmap();

    QSize newSize = size();
    newSize.scale(s, aspectMode);
    newSize.rwidth() = qMax(newSize.width(), 1);
    newSize.rheight() = qMax(newSize.height(), 1);
    if (newSize == size())
        return *this;

    Q_TRACE_SCOPE(QPixmap_scaled, s, aspectMode, mode);

    QTransform wm = QTransform::fromScale((qreal)newSize.width() / width(),
                                          (qreal)newSize.height() / height());
    QPixmap pix = transformed(wm, mode);
    return pix;
}

/*!
    \fn QPixmap QPixmap::scaledToWidth(int width, Qt::TransformationMode
    mode) const

    Returns a scaled copy of the image. The returned image is scaled
    to the given \a width using the specified transformation \a mode.
    The height of the pixmap is automatically calculated so that the
    aspect ratio of the pixmap is preserved.

    If \a width is 0 or negative, a null pixmap is returned.

    \sa isNull(), {QPixmap#Pixmap Transformations}{Pixmap
    Transformations}
*/
QPixmap Q_TRACE_INSTRUMENT(qtgui) QPixmap::scaledToWidth(int w, Qt::TransformationMode mode) const
{
    if (isNull()) {
        qWarning("QPixmap::scaleWidth: Pixmap is a null pixmap");
        return copy();
    }
    if (w <= 0)
        return QPixmap();

    Q_TRACE_SCOPE(QPixmap_scaledToWidth, w, mode);

    qreal factor = (qreal) w / width();
    QTransform wm = QTransform::fromScale(factor, factor);
    return transformed(wm, mode);
}

/*!
    \fn QPixmap QPixmap::scaledToHeight(int height,
    Qt::TransformationMode mode) const

    Returns a scaled copy of the image. The returned image is scaled
    to the given \a height using the specified transformation \a mode.
    The width of the pixmap is automatically calculated so that the
    aspect ratio of the pixmap is preserved.

    If \a height is 0 or negative, a null pixmap is returned.

    \sa isNull(), {QPixmap#Pixmap Transformations}{Pixmap
    Transformations}
*/
QPixmap Q_TRACE_INSTRUMENT(qtgui) QPixmap::scaledToHeight(int h, Qt::TransformationMode mode) const
{
    if (isNull()) {
        qWarning("QPixmap::scaleHeight: Pixmap is a null pixmap");
        return copy();
    }
    if (h <= 0)
        return QPixmap();

    Q_TRACE_SCOPE(QPixmap_scaledToHeight, h, mode);

    qreal factor = (qreal) h / height();
    QTransform wm = QTransform::fromScale(factor, factor);
    return transformed(wm, mode);
}

/*!
    Returns a copy of the pixmap that is transformed using the given
    transformation \a transform and transformation \a mode. The original
    pixmap is not changed.

    The transformation \a transform is internally adjusted to compensate
    for unwanted translation; i.e. the pixmap produced is the smallest
    pixmap that contains all the transformed points of the original
    pixmap. Use the trueMatrix() function to retrieve the actual
    matrix used for transforming the pixmap.

    This function is slow because it involves transformation to a
    QImage, non-trivial computations and a transformation back to a
    QPixmap.

    \sa trueMatrix(), {QPixmap#Pixmap Transformations}{Pixmap
    Transformations}
*/
QPixmap QPixmap::transformed(const QTransform &transform,
                             Qt::TransformationMode mode) const
{
    if (isNull() || transform.type() <= QTransform::TxTranslate)
        return *this;

    return data->transformed(transform, mode);
}

/*!
    \class QPixmap
    \inmodule QtGui

    \brief The QPixmap class is an off-screen image representation
    that can be used as a paint device.

    \ingroup painting
    \ingroup shared


    Qt provides four classes for handling image data: QImage, QPixmap,
    QBitmap and QPicture. QImage is designed and optimized for I/O,
    and for direct pixel access and manipulation, while QPixmap is
    designed and optimized for showing images on screen. QBitmap is
    only a convenience class that inherits QPixmap, ensuring a depth
    of 1. The isQBitmap() function returns \c true if a QPixmap object is
    really a bitmap, otherwise returns \c false. Finally, the QPicture class
    is a paint device that records and replays QPainter commands.

    A QPixmap can easily be displayed on the screen using QLabel or
    one of QAbstractButton's subclasses (such as QPushButton and
    QToolButton). QLabel has a pixmap property, whereas
    QAbstractButton has an icon property.

    QPixmap objects can be passed around by value since the QPixmap
    class uses implicit data sharing. For more information, see the \l
    {Implicit Data Sharing} documentation. QPixmap objects can also be
    streamed.

    Note that the pixel data in a pixmap is internal and is managed by
    the underlying window system. Because QPixmap is a QPaintDevice
    subclass, QPainter can be used to draw directly onto pixmaps.
    Pixels can only be accessed through QPainter functions or by
    converting the QPixmap to a QImage. However, the fill() function
    is available for initializing the entire pixmap with a given color.

    There are functions to convert between QImage and
    QPixmap. Typically, the QImage class is used to load an image
    file, optionally manipulating the image data, before the QImage
    object is converted into a QPixmap to be shown on
    screen. Alternatively, if no manipulation is desired, the image
    file can be loaded directly into a QPixmap.

    QPixmap provides a collection of functions that can be used to
    obtain a variety of information about the pixmap. In addition,
    there are several functions that enables transformation of the
    pixmap.

    \section1 Reading and Writing Image Files

    QPixmap provides several ways of reading an image file: The file
    can be loaded when constructing the QPixmap object, or by using
    the load() or loadFromData() functions later on. When loading an
    image, the file name can either refer to an actual file on disk or
    to one of the application's embedded resources. See \l{The Qt
    Resource System} overview for details on how to embed images and
    other resource files in the application's executable.

    Simply call the save() function to save a QPixmap object.

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

    \section1 Pixmap Information

    QPixmap provides a collection of functions that can be used to
    obtain a variety of information about the pixmap:

    \table
    \header
    \li \li Available Functions
    \row
    \li Geometry
    \li
    The size(), width() and height() functions provide information
    about the pixmap's size. The rect() function returns the image's
    enclosing rectangle.

    \row
    \li Alpha component
    \li

    The hasAlphaChannel() returns \c true if the pixmap has a format that
    respects the alpha channel, otherwise returns \c false. The hasAlpha(),
    setMask() and mask() functions are legacy and should not be used.
    They are potentially very slow.

    The createHeuristicMask() function creates and returns a 1-bpp
    heuristic mask (i.e. a QBitmap) for this pixmap. It works by
    selecting a color from one of the corners and then chipping away
    pixels of that color, starting at all the edges. The
    createMaskFromColor() function creates and returns a mask (i.e. a
    QBitmap) for the pixmap based on a given color.

    \row
    \li Low-level information
    \li

    The depth() function returns the depth of the pixmap. The
    defaultDepth() function returns the default depth, i.e. the depth
    used by the application on the given screen.

    The cacheKey() function returns a number that uniquely
    identifies the contents of the QPixmap object.

    \endtable

    \section1 Pixmap Conversion

    A QPixmap object can be converted into a QImage using the
    toImage() function. Likewise, a QImage can be converted into a
    QPixmap using the fromImage(). If this is too expensive an
    operation, you can use QBitmap::fromImage() instead.

    To convert a QPixmap to and from HICON you can use the
    QImage::toHICON() and QImage::fromHICON() functions respectively
    (after converting the QPixmap to a QImage, as explained above).

    \section1 Pixmap Transformations

    QPixmap supports a number of functions for creating a new pixmap
    that is a transformed version of the original:

    The scaled(), scaledToWidth() and scaledToHeight() functions
    return scaled copies of the pixmap, while the copy() function
    creates a QPixmap that is a plain copy of the original one.

    The transformed() function returns a copy of the pixmap that is
    transformed with the given transformation matrix and
    transformation mode: Internally, the transformation matrix is
    adjusted to compensate for unwanted translation,
    i.e. transformed() returns the smallest pixmap containing all
    transformed points of the original pixmap. The static trueMatrix()
    function returns the actual matrix used for transforming the
    pixmap.

    \sa QBitmap, QImage, QImageReader, QImageWriter
*/


/*!
    \typedef QPixmap::DataPtr
    \internal
*/

/*!
    \fn DataPtr &QPixmap::data_ptr()
    \internal
*/

/*!
    Returns \c true if this pixmap has an alpha channel, \e or has a
    mask, otherwise returns \c false.

    \sa hasAlphaChannel(), mask()
*/
bool QPixmap::hasAlpha() const
{
    return data && data->hasAlphaChannel();
}

/*!
    Returns \c true if the pixmap has a format that respects the alpha
    channel, otherwise returns \c false.

    \sa hasAlpha()
*/
bool QPixmap::hasAlphaChannel() const
{
    return data && data->hasAlphaChannel();
}

/*!
    \internal
*/
int QPixmap::metric(PaintDeviceMetric metric) const
{
    return data ? data->metric(metric) : 0;
}

/*!
    \internal
*/
QPaintEngine *QPixmap::paintEngine() const
{
    return data ? data->paintEngine() : nullptr;
}

/*!
    \fn QBitmap QPixmap::mask() const

    Extracts a bitmap mask from the pixmap's alpha channel.

    \warning This is potentially an expensive operation. The mask of
    the pixmap is extracted dynamically from the pixeldata.

    \sa setMask(), {QPixmap#Pixmap Information}{Pixmap Information}
*/
QBitmap QPixmap::mask() const
{
    return data ? data->mask() : QBitmap();
}

/*!
    Returns the default pixmap depth used by the application.

    On all platforms the depth of the primary screen will be returned.

    \note QGuiApplication must be created before calling this function.

    \sa depth(), QColormap::depth(), {QPixmap#Pixmap Information}{Pixmap Information}

*/
int QPixmap::defaultDepth()
{
    QScreen *primary = QGuiApplication::primaryScreen();
    if (Q_LIKELY(primary))
        return primary->depth();
    qWarning("QPixmap: QGuiApplication must be created before calling defaultDepth().");
    return 0;
}

/*!
    Detaches the pixmap from shared pixmap data.

    A pixmap is automatically detached by Qt whenever its contents are
    about to change. This is done in almost all QPixmap member
    functions that modify the pixmap (fill(), fromImage(),
    load(), etc.), and in QPainter::begin() on a pixmap.

    There are two exceptions in which detach() must be called
    explicitly, that is when calling the handle() or the
    x11PictureHandle() function (only available on X11). Otherwise,
    any modifications done using system calls, will be performed on
    the shared data.

    The detach() function returns immediately if there is just a
    single reference or if the pixmap has not been initialized yet.
*/
void QPixmap::detach()
{
    if (!data)
        return;

    // QPixmap.data member may be QRuntimePlatformPixmap so use handle() function to get
    // the actual underlying runtime pixmap data.
    QPlatformPixmap *pd = handle();
    QPlatformPixmap::ClassId id = pd->classId();
    if (id == QPlatformPixmap::RasterClass) {
        QRasterPlatformPixmap *rasterData = static_cast<QRasterPlatformPixmap*>(pd);
        rasterData->image.detach();
    }

    if (data->is_cached && data->ref.loadRelaxed() == 1)
        QImagePixmapCleanupHooks::executePlatformPixmapModificationHooks(data.data());

    if (data->ref.loadRelaxed() != 1) {
        *this = copy();
    }
    ++data->detach_no;
}

/*!
    \fn QPixmap QPixmap::fromImage(const QImage &image, Qt::ImageConversionFlags flags)

    Converts the given \a image to a pixmap using the specified \a
    flags to control the conversion.  The \a flags argument is a
    bitwise-OR of the \l{Qt::ImageConversionFlags}. Passing 0 for \a
    flags sets all the default options.

    In case of monochrome and 8-bit images, the image is first
    converted to a 32-bit pixmap and then filled with the colors in
    the color table. If this is too expensive an operation, you can
    use QBitmap::fromImage() instead.

    \sa fromImageReader(), toImage(), {QPixmap#Pixmap Conversion}{Pixmap Conversion}
*/
QPixmap QPixmap::fromImage(const QImage &image, Qt::ImageConversionFlags flags)
{
    if (image.isNull())
        return QPixmap();

    if (Q_UNLIKELY(!qobject_cast<QGuiApplication *>(QCoreApplication::instance()))) {
        qWarning("QPixmap::fromImage: QPixmap cannot be created without a QGuiApplication");
        return QPixmap();
    }

    std::unique_ptr<QPlatformPixmap> data(QGuiApplicationPrivate::platformIntegration()->createPlatformPixmap(QPlatformPixmap::PixmapType));
    data->fromImage(image, flags);
    return QPixmap(data.release());
}

/*!
    \fn QPixmap QPixmap::fromImage(QImage &&image, Qt::ImageConversionFlags flags)
    \since 5.3
    \overload

    Converts the given \a image to a pixmap without copying if possible.
*/


/*!
    \internal
*/
QPixmap QPixmap::fromImageInPlace(QImage &image, Qt::ImageConversionFlags flags)
{
    if (image.isNull())
        return QPixmap();

    if (Q_UNLIKELY(!qobject_cast<QGuiApplication *>(QCoreApplication::instance()))) {
        qWarning("QPixmap::fromImageInPlace: QPixmap cannot be created without a QGuiApplication");
        return QPixmap();
    }

    std::unique_ptr<QPlatformPixmap> data(QGuiApplicationPrivate::platformIntegration()->createPlatformPixmap(QPlatformPixmap::PixmapType));
    data->fromImageInPlace(image, flags);
    return QPixmap(data.release());
}

/*!
    \fn QPixmap QPixmap::fromImageReader(QImageReader *imageReader, Qt::ImageConversionFlags flags)

    Create a QPixmap from an image read directly from an \a imageReader.
    The \a flags argument is a bitwise-OR of the \l{Qt::ImageConversionFlags}.
    Passing 0 for \a flags sets all the default options.

    On some systems, reading an image directly to QPixmap can use less memory than
    reading a QImage to convert it to QPixmap.

    \sa fromImage(), toImage(), {QPixmap#Pixmap Conversion}{Pixmap Conversion}
*/
QPixmap QPixmap::fromImageReader(QImageReader *imageReader, Qt::ImageConversionFlags flags)
{
    if (Q_UNLIKELY(!qobject_cast<QGuiApplication *>(QCoreApplication::instance()))) {
        qWarning("QPixmap::fromImageReader: QPixmap cannot be created without a QGuiApplication");
        return QPixmap();
    }

    std::unique_ptr<QPlatformPixmap> data(QGuiApplicationPrivate::platformIntegration()->createPlatformPixmap(QPlatformPixmap::PixmapType));
    data->fromImageReader(imageReader, flags);
    return QPixmap(data.release());
}

/*!
  \internal
*/
QPlatformPixmap* QPixmap::handle() const
{
    return data.data();
}

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const QPixmap &r)
{
    QDebugStateSaver saver(dbg);
    dbg.resetFormat();
    dbg.nospace();
    dbg << "QPixmap(";
    if (r.isNull()) {
        dbg << "null";
    } else {
        dbg << r.size() << ",depth=" << r.depth()
            << ",devicePixelRatio=" << r.devicePixelRatio()
            << ",cacheKey=" << Qt::showbase << Qt::hex << r.cacheKey() << Qt::dec << Qt::noshowbase;
    }
    dbg << ')';
    return dbg;
}
#endif

QT_END_NAMESPACE
