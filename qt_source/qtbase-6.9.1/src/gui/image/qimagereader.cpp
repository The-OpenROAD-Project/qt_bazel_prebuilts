// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

//#define QIMAGEREADER_DEBUG

/*!
    \class QImageReader
    \brief The QImageReader class provides a format independent interface
    for reading images from files or other devices.

    \inmodule QtGui
    \reentrant
    \ingroup painting

    The most common way to read images is through QImage and QPixmap's
    constructors, or by calling QImage::load() and
    QPixmap::load(). QImageReader is a specialized class which gives
    you more control when reading images. For example, you can read an
    image into a specific size by calling setScaledSize(), and you can
    select a clip rect, effectively loading only parts of an image, by
    calling setClipRect(). Depending on the underlying support in the
    image format, this can save memory and speed up loading of images.

    To read an image, you start by constructing a QImageReader object.
    Pass either a file name or a device pointer, and the image format
    to QImageReader's constructor. You can then set several options,
    such as the clip rect (by calling setClipRect()) and scaled size
    (by calling setScaledSize()). canRead() returns the image if the
    QImageReader can read the image (i.e., the image format is
    supported and the device is open for reading). Call read() to read
    the image.

    If any error occurs when reading the image, read() will return a
    null QImage. You can then call error() to find the type of error
    that occurred, or errorString() to get a human readable
    description of what went wrong.

    \note QImageReader assumes exclusive control over the file or
    device that is assigned. Any attempts to modify the assigned file
    or device during the lifetime of the QImageReader object will
    yield undefined results.

    \section1 Formats

    Call supportedImageFormats() for a list of formats that
    QImageReader can read. QImageReader supports all built-in image
    formats, in addition to any image format plugins that support
    reading. Call supportedMimeTypes() to obtain a list of supported MIME
    types, which for example can be passed to QFileDialog::setMimeTypeFilters().

    QImageReader autodetects the image format by default, by looking at the
    provided (optional) format string, the file name suffix, and the data
    stream contents. You can enable or disable this feature, by calling
    setAutoDetectImageFormat().

    \section1 High Resolution Versions of Images

    It is possible to provide high resolution versions of images should a scaling
    between \e{device pixels} and \e{device independent pixels} be in effect.

    The high resolution version is marked by the suffix \c @2x on the base name.
    The image read will have its \e{device pixel ratio} set to a value of 2.

    This can be disabled by setting the environment variable
    \c QT_HIGHDPI_DISABLE_2X_IMAGE_LOADING.

    \sa QImageWriter, QImageIOHandler, QImageIOPlugin, QMimeDatabase, QColorSpace
    \sa QImage::devicePixelRatio(), QPixmap::devicePixelRatio(), QIcon, QPainter::drawPixmap(), QPainter::drawImage()
*/

/*!
    \enum QImageReader::ImageReaderError

    This enum describes the different types of errors that can occur
    when reading images with QImageReader.

    \value FileNotFoundError QImageReader was used with a file name,
    but not file was found with that name. This can also happen if the
    file name contained no extension, and the file with the correct
    extension is not supported by Qt.

    \value DeviceError QImageReader encountered a device error when
    reading the image. You can consult your particular device for more
    details on what went wrong.

    \value UnsupportedFormatError Qt does not support the requested
    image format.

    \value InvalidDataError The image data was invalid, and
    QImageReader was unable to read an image from it. The can happen
    if the image file is damaged.

    \value UnknownError An unknown error occurred. If you get this
    value after calling read(), it is most likely caused by a bug in
    QImageReader.
*/
#include "qimagereader.h"

#include <qbytearray.h>
#ifdef QIMAGEREADER_DEBUG
#include <qdebug.h>
#endif
#include <qfile.h>
#include <qfileinfo.h>
#include <qimage.h>
#include <qimageiohandler.h>
#include <qlist.h>
#include <qrect.h>
#include <qsize.h>
#include <qcolor.h>
#include <qvariant.h>

// factory loader
#include <qcoreapplication.h>
#include <private/qfactoryloader_p.h>
#include <QtCore/private/qlocking_p.h>

// for qt_getImageText
#include <private/qimage_p.h>

// image handlers
#include <private/qbmphandler_p.h>
#include <private/qppmhandler_p.h>
#include <private/qxbmhandler_p.h>
#include <private/qxpmhandler_p.h>
#ifndef QT_NO_IMAGEFORMAT_PNG
#include <private/qpnghandler_p.h>
#endif

#include <private/qimagereaderwriterhelpers_p.h>
#include <qtgui_tracepoints_p.h>

#include <algorithm>

QT_BEGIN_NAMESPACE

using namespace QImageReaderWriterHelpers;
using namespace Qt::StringLiterals;

Q_TRACE_POINT(qtgui, QImageReader_read_before_reading, QImageReader *reader, const QString &filename);
Q_TRACE_POINT(qtgui, QImageReader_read_after_reading, QImageReader *reader, bool result);

static QImageIOHandler *createReadHandlerHelper(QIODevice *device,
                                                const QByteArray &format,
                                                bool autoDetectImageFormat,
                                                bool ignoresFormatAndExtension)
{
    if (!autoDetectImageFormat && format.isEmpty())
        return nullptr;

    QByteArray form = format.toLower();
    QImageIOHandler *handler = nullptr;
    QByteArray suffix;

#if QT_CONFIG(imageformatplugin)
    Q_CONSTINIT static QBasicMutex mutex;
    const auto locker = qt_scoped_lock(mutex);

    typedef QMultiMap<int, QString> PluginKeyMap;

    // check if we have plugins that support the image format
    auto l = QImageReaderWriterHelpers::pluginLoader();
    const PluginKeyMap keyMap = l->keyMap();

#ifdef QIMAGEREADER_DEBUG
    qDebug() << "QImageReader::createReadHandler( device =" << (void *)device << ", format =" << format << "),"
             << keyMap.uniqueKeys().size() << "plugins available: " << keyMap;
#endif

    int testFormatPluginIndex = -1;
#endif // QT_CONFIG(imageformatplugin)

    if (device && format.isEmpty() && autoDetectImageFormat && !ignoresFormatAndExtension) {
        // if there's no format, see if \a device is a file, and if so, find the file suffix
        if (QFile *file = qobject_cast<QFile *>(device)) {
            suffix = QFileInfo(file->fileName()).suffix().toLower().toLatin1();
#ifdef QIMAGEREADER_DEBUG
            qDebug() << "QImageReader::createReadHandler: device file suffix:" << suffix;
#endif
        }
    }

    QByteArray testFormat = !form.isEmpty() ? form : suffix;
    if (ignoresFormatAndExtension)
        testFormat = QByteArray();

#if QT_CONFIG(imageformatplugin)
    if (!testFormat.isEmpty()) {
        // Check first support for the given format name or suffix among our plugins' registered
        // formats. This allows plugins to override our built-in handlers.
        const qint64 pos = device ? device->pos() : 0;
        for (int testIndex : keyMap.keys(QLatin1StringView(testFormat))) {
            QImageIOPlugin *plugin = qobject_cast<QImageIOPlugin *>(l->instance(testIndex));
            if (plugin && plugin->capabilities(device, testFormat) & QImageIOPlugin::CanRead) {
#ifdef QIMAGEREADER_DEBUG
                qDebug() << "QImageReader::createReadHandler: format" << testFormat
                         << "recognized, the" << keyMap.values(testIndex) << "plugin can read this format.";
#endif
                handler = plugin->create(device, testFormat);
                testFormatPluginIndex = testIndex;
                break;
            }
        }
        if (device && !device->isSequential())
            device->seek(pos); // Should not have moved, but guard against buggy plugins
    }
#endif // QT_CONFIG(imageformatplugin)

    // if we don't have a handler yet, check if we have built-in support for
    // the format
    if (!handler && !testFormat.isEmpty()) {
        if (false) {
#ifndef QT_NO_IMAGEFORMAT_PNG
        } else if (testFormat == "png") {
            handler = new QPngHandler;
#endif
#ifndef QT_NO_IMAGEFORMAT_BMP
        } else if (testFormat == "bmp") {
            handler = new QBmpHandler;
        } else if (testFormat == "dib") {
            handler = new QBmpHandler(QBmpHandler::DibFormat);
#endif
#ifndef QT_NO_IMAGEFORMAT_XPM
        } else if (testFormat == "xpm") {
            handler = new QXpmHandler;
#endif
#ifndef QT_NO_IMAGEFORMAT_XBM
        } else if (testFormat == "xbm") {
            handler = new QXbmHandler;
            handler->setOption(QImageIOHandler::SubType, testFormat);
#endif
#ifndef QT_NO_IMAGEFORMAT_PPM
        } else if (testFormat == "pbm" || testFormat == "pbmraw" || testFormat == "pgm"
                   || testFormat == "pgmraw" || testFormat == "ppm" || testFormat == "ppmraw") {
            handler = new QPpmHandler;
            handler->setOption(QImageIOHandler::SubType, testFormat);
#endif
        }

#ifdef QIMAGEREADER_DEBUG
        if (handler)
            qDebug() << "QImageReader::createReadHandler: using the built-in handler for" << testFormat;
#endif
    }

#if QT_CONFIG(imageformatplugin)
    if (!handler && !testFormat.isEmpty() && autoDetectImageFormat) {
        // check if any other plugin supports the format name (they are not allowed to
        // read from the device yet).
        const qint64 pos = device ? device->pos() : 0;

        const int keyCount = keyMap.size();
        for (int i = 0; i < keyCount; ++i) {
            if (i != testFormatPluginIndex) {
                QImageIOPlugin *plugin = qobject_cast<QImageIOPlugin *>(l->instance(i));
                if (plugin && plugin->capabilities(device, testFormat) & QImageIOPlugin::CanRead) {
#ifdef QIMAGEREADER_DEBUG
                    qDebug() << "QImageReader::createReadHandler: the" << keyMap.values(i) << "plugin can read this format";
#endif
                    handler = plugin->create(device, testFormat);
                    break;
                }
            }
        }
        if (device && !device->isSequential())
            device->seek(pos);  // Should not have moved, but guard against buggy plugins
    }
#endif // QT_CONFIG(imageformatplugin)

    if (handler && device && !suffix.isEmpty()) {
        Q_ASSERT(qobject_cast<QFile *>(device));
        // We have a file claiming to be of a recognized format. Now confirm that
        // the handler also recognizes the file contents.
        const qint64 pos = device->pos();
        handler->setDevice(device);
        if (!form.isEmpty())
            handler->setFormat(form);
        bool canRead = handler->canRead();
        device->seek(pos);
        if (canRead) {
            // ok, we're done.
            return handler;
        }
#ifdef QIMAGEREADER_DEBUG
        qDebug() << "QImageReader::createReadHandler: the" << suffix << "handler can not read this file";
#endif
        // File may still be valid, just with wrong suffix, so fall back to
        // finding a handler based on contents, below.
        delete handler;
        handler = nullptr;
    }

#if QT_CONFIG(imageformatplugin)
    if (!handler && (autoDetectImageFormat || ignoresFormatAndExtension)) {
        // check if any of our plugins recognize the file from its contents.
        const qint64 pos = device ? device->pos() : 0;
        const int keyCount = keyMap.size();
        for (int i = 0; i < keyCount; ++i) {
            if (i != testFormatPluginIndex) {
                QImageIOPlugin *plugin = qobject_cast<QImageIOPlugin *>(l->instance(i));
                if (plugin && plugin->capabilities(device, QByteArray()) & QImageIOPlugin::CanRead) {
                    handler = plugin->create(device, testFormat);
#ifdef QIMAGEREADER_DEBUG
                    qDebug() << "QImageReader::createReadHandler: the" << keyMap.values(i) << "plugin can read this data";
#endif
                    break;
                }
            }
        }
        if (device && !device->isSequential())
            device->seek(pos);
    }
#endif // QT_CONFIG(imageformatplugin)

    if (!handler && (autoDetectImageFormat || ignoresFormatAndExtension)) {
        // check if any of our built-in handlers recognize the file from its
        // contents.
        int currentFormat = 0;
        if (!suffix.isEmpty()) {
            // If reading from a file with a suffix, start testing our
            // built-in handler for that suffix first.
            for (int i = 0; i < _qt_NumFormats; ++i) {
                if (_qt_BuiltInFormats[i].extension == suffix) {
                    currentFormat = i;
                    break;
                }
            }
        }

        QByteArray subType;
        int numFormats = _qt_NumFormats;
        while (device && numFormats >= 0) {
            const qint64 pos = device->pos();
            switch (currentFormat) {
#ifndef QT_NO_IMAGEFORMAT_PNG
            case _qt_PngFormat:
                if (QPngHandler::canRead(device))
                    handler = new QPngHandler;
                break;
#endif
#ifndef QT_NO_IMAGEFORMAT_BMP
            case _qt_BmpFormat:
                if (QBmpHandler::canRead(device))
                    handler = new QBmpHandler;
                break;
#endif
#ifndef QT_NO_IMAGEFORMAT_XPM
            case _qt_XpmFormat:
                if (QXpmHandler::canRead(device))
                    handler = new QXpmHandler;
                break;
#endif
#ifndef QT_NO_IMAGEFORMAT_PPM
            case _qt_PbmFormat:
            case _qt_PgmFormat:
            case _qt_PpmFormat:
                if (QPpmHandler::canRead(device, &subType)) {
                    handler = new QPpmHandler;
                    handler->setOption(QImageIOHandler::SubType, subType);
                }
                break;
#endif
#ifndef QT_NO_IMAGEFORMAT_XBM
            case _qt_XbmFormat:
                if (QXbmHandler::canRead(device))
                    handler = new QXbmHandler;
                break;
#endif
            default:
                break;
            }
            if (!device->isSequential())
                device->seek(pos);

            if (handler) {
#ifdef QIMAGEREADER_DEBUG
                qDebug("QImageReader::createReadHandler: the %s built-in handler can read this data",
                       _qt_BuiltInFormats[currentFormat].extension);
#endif
                break;
            }

            --numFormats;
            ++currentFormat;
            if (currentFormat >= _qt_NumFormats)
                currentFormat = 0;
        }
    }

    if (!handler) {
#ifdef QIMAGEREADER_DEBUG
        qDebug("QImageReader::createReadHandler: no handlers found. giving up.");
#endif
        // no handler: give up.
        return nullptr;
    }

    handler->setDevice(device);
    if (!form.isEmpty())
        handler->setFormat(form);
    return handler;
}

class QImageReaderPrivate
{
public:
    QImageReaderPrivate(QImageReader *qq);
    ~QImageReaderPrivate();

    // device
    QByteArray format;
    bool autoDetectImageFormat;
    bool ignoresFormatAndExtension;
    QIODevice *device;
    bool deleteDevice;
    QImageIOHandler *handler;
    bool initHandler();

    // image options
    QRect clipRect;
    QSize scaledSize;
    QRect scaledClipRect;
    int quality;
    QMap<QString, QString> text;
    void getText();
    enum {
        UsePluginDefault,
        ApplyTransform,
        DoNotApplyTransform
    } autoTransform;

    // error
    QImageReader::ImageReaderError imageReaderError;
    QString errorString;

    QImageReader *q;

    static int maxAlloc;
};

int QImageReaderPrivate::maxAlloc = 256; // 256 MB is enough for an 8K 64bpp image

/*!
    \internal
*/
QImageReaderPrivate::QImageReaderPrivate(QImageReader *qq)
    : autoDetectImageFormat(true), ignoresFormatAndExtension(false)
{
    device = nullptr;
    deleteDevice = false;
    handler = nullptr;
    quality = -1;
    imageReaderError = QImageReader::UnknownError;
    autoTransform = UsePluginDefault;

    q = qq;
}

/*!
    \internal
*/
QImageReaderPrivate::~QImageReaderPrivate()
{
    delete handler;
    if (deleteDevice)
        delete device;
}

/*!
    \internal
*/
bool QImageReaderPrivate::initHandler()
{
    if (handler)
        return true;

    // check some preconditions
    if (!device || (!deleteDevice && !device->isOpen() && !device->open(QIODevice::ReadOnly))) {
        imageReaderError = QImageReader::DeviceError;
        errorString = QImageReader::tr("Invalid device");
        return false;
    }

    // probe the file extension
    if (deleteDevice && !device->isOpen() && !device->open(QIODevice::ReadOnly) && autoDetectImageFormat) {
        Q_ASSERT(qobject_cast<QFile*>(device) != nullptr); // future-proofing; for now this should always be the case, so...
        QFile *file = static_cast<QFile *>(device);

        if (file->error() == QFileDevice::ResourceError) {
            // this is bad. we should abort the open attempt and note the failure.
            imageReaderError = QImageReader::DeviceError;
            errorString = file->errorString();
            return false;
        }

        QList<QByteArray> extensions = QImageReader::supportedImageFormats();
        if (!format.isEmpty()) {
            // Try the most probable extension first
            int currentFormatIndex = extensions.indexOf(format.toLower());
            if (currentFormatIndex > 0)
                extensions.swapItemsAt(0, currentFormatIndex);
        }

        int currentExtension = 0;

        QString fileName = file->fileName();
        bool fileIsOpen;

        do {
            file->setFileName(fileName + u'.'
                    + QLatin1StringView(extensions.at(currentExtension++).constData()));
            fileIsOpen = file->open(QIODevice::ReadOnly);
        } while (!fileIsOpen && currentExtension < extensions.size());

        if (!fileIsOpen) {
            imageReaderError = QImageReader::FileNotFoundError;
            errorString = QImageReader::tr("File not found");
            file->setFileName(fileName); // restore the old file name
            return false;
        }
    }

    // assign a handler
    if ((handler = createReadHandlerHelper(device, format, autoDetectImageFormat, ignoresFormatAndExtension)) == nullptr) {
        imageReaderError = QImageReader::UnsupportedFormatError;
        errorString = QImageReader::tr("Unsupported image format");
        return false;
    }
    return true;
}

/*!
    \internal
*/
void QImageReaderPrivate::getText()
{
    if (text.isEmpty() && q->supportsOption(QImageIOHandler::Description))
        text = qt_getImageTextFromDescription(handler->option(QImageIOHandler::Description).toString());
}

/*!
    Constructs an empty QImageReader object. Before reading an image,
    call setDevice() or setFileName().
*/
QImageReader::QImageReader()
    : d(new QImageReaderPrivate(this))
{
}

/*!
    Constructs a QImageReader object with the device \a device and the
    image format \a format.
*/
QImageReader::QImageReader(QIODevice *device, const QByteArray &format)
    : d(new QImageReaderPrivate(this))
{
    d->device = device;
    d->format = format;
}

/*!
    Constructs a QImageReader object with the file name \a fileName
    and the image format \a format.

    \sa setFileName()
*/
QImageReader::QImageReader(const QString &fileName, const QByteArray &format)
    : QImageReader(new QFile(fileName), format)
{
    d->deleteDevice = true;
}

/*!
    Destructs the QImageReader object.
*/
QImageReader::~QImageReader()
{
    delete d;
}

/*!
    Sets the format QImageReader will use when reading images, to \a
    format. \a format is a case insensitive text string. Example:

    \snippet code/src_gui_image_qimagereader.cpp 0

    You can call supportedImageFormats() for the full list of formats
    QImageReader supports.

    \sa format()
*/
void QImageReader::setFormat(const QByteArray &format)
{
    d->format = format;
}

/*!
    Returns the format QImageReader uses for reading images.

    You can call this function after assigning a device to the
    reader to determine the format of the device. For example:

    \snippet code/src_gui_image_qimagereader.cpp 1

    If the reader cannot read any image from the device (e.g., there is no
    image there, or the image has already been read), or if the format is
    unsupported, this function returns an empty QByteArray().

    \sa setFormat(), supportedImageFormats()
*/
QByteArray QImageReader::format() const
{
    if (d->format.isEmpty()) {
        if (!d->initHandler())
            return QByteArray();
        return d->handler->canRead() ? d->handler->format() : QByteArray();
    }

    return d->format;
}

/*!
    If \a enabled is true, image format autodetection is enabled; otherwise,
    it is disabled. By default, autodetection is enabled.

    QImageReader uses an extensive approach to detecting the image format;
    firstly, if you pass a file name to QImageReader, it will attempt to
    detect the file extension if the given file name does not point to an
    existing file, by appending supported default extensions to the given file
    name, one at a time. It then uses the following approach to detect the
    image format:

    \list

    \li Image plugins are queried first, based on either the optional format
    string, or the file name suffix (if the source device is a file). No
    content detection is done at this stage. QImageReader will choose the
    first plugin that supports reading for this format.

    \li If no plugin supports the image format, Qt's built-in handlers are
    checked based on either the optional format string, or the file name
    suffix.

    \li If no capable plugins or built-in handlers are found, each plugin is
    tested by inspecting the content of the data stream.

    \li If no plugins could detect the image format based on data contents,
    each built-in image handler is tested by inspecting the contents.

    \li Finally, if all above approaches fail, QImageReader will report failure
    when trying to read the image.

    \endlist

    By disabling image format autodetection, QImageReader will only query the
    plugins and built-in handlers based on the format string (i.e., no file
    name extensions are tested).

    \sa QImageIOHandler::canRead(), QImageIOPlugin::capabilities()
*/
void QImageReader::setAutoDetectImageFormat(bool enabled)
{
    d->autoDetectImageFormat = enabled;
}

/*!
    Returns \c true if image format autodetection is enabled on this image
    reader; otherwise returns \c false. By default, autodetection is enabled.

    \sa setAutoDetectImageFormat()
*/
bool QImageReader::autoDetectImageFormat() const
{
    return d->autoDetectImageFormat;
}


/*!
    If \a ignored is set to true, then the image reader will ignore
    specified formats or file extensions and decide which plugin to
    use only based on the contents in the datastream.

    Setting this flag means that all image plugins gets loaded. Each
    plugin will read the first bytes in the image data and decide if
    the plugin is compatible or not.

    This also disables auto detecting the image format.

    \sa decideFormatFromContent()
*/

void QImageReader::setDecideFormatFromContent(bool ignored)
{
    d->ignoresFormatAndExtension = ignored;
}


/*!
    Returns whether the image reader should decide which plugin to use
    only based on the contents of the datastream rather than on the file
    extension.

    \sa setDecideFormatFromContent()
*/

bool QImageReader::decideFormatFromContent() const
{
    return d->ignoresFormatAndExtension;
}


/*!
    Sets QImageReader's device to \a device. If a device has already
    been set, the old device is removed from QImageReader and is
    otherwise left unchanged.

    If the device is not already open, QImageReader will attempt to
    open the device in \l {QIODeviceBase::}{ReadOnly} mode by calling
    open(). Note that this does not work for certain devices, such as
    QProcess, QTcpSocket and QUdpSocket, where more logic is required
    to open the device.

    \sa device(), setFileName()
*/
void QImageReader::setDevice(QIODevice *device)
{
    delete d->handler;
    d->handler = nullptr;
    if (d->device && d->deleteDevice)
        delete d->device;
    d->device = device;
    d->deleteDevice = false;
    d->text.clear();
}

/*!
    Returns the device currently assigned to QImageReader, or \nullptr
    if no device has been assigned.
*/
QIODevice *QImageReader::device() const
{
    return d->device;
}

/*!
    Sets the file name of QImageReader to \a fileName. Internally,
    QImageReader will create a QFile object and open it in \l
    {QIODeviceBase::}{ReadOnly} mode, and use this when reading images.

    If \a fileName does not include a file extension (e.g., .png or .bmp),
    QImageReader will cycle through all supported extensions until it finds
    a matching file.

    \sa fileName(), setDevice(), supportedImageFormats()
*/
void QImageReader::setFileName(const QString &fileName)
{
    setDevice(new QFile(fileName));
    d->deleteDevice = true;
}

/*!
    If the currently assigned device is a QFile, or if setFileName()
    has been called, this function returns the name of the file
    QImageReader reads from. Otherwise (i.e., if no device has been
    assigned or the device is not a QFile), an empty QString is
    returned.

    \sa setFileName(), setDevice()
*/
QString QImageReader::fileName() const
{
    QFile *file = qobject_cast<QFile *>(d->device);
    return file ? file->fileName() : QString();
}

/*!
    Sets the quality setting of the image format to \a quality.

    Some image formats, in particular lossy ones, entail a tradeoff between a)
    visual quality of the resulting image, and b) decoding execution time.
    This function sets the level of that tradeoff for image formats that
    support it.

    In case of scaled image reading, the quality setting may also influence the
    tradeoff level between visual quality and execution speed of the scaling
    algorithm.

    The value range of \a quality depends on the image format. For example,
    the "jpeg" format supports a quality range from 0 (low visual quality) to
    100 (high visual quality).

    \sa quality() setScaledSize()
*/
void QImageReader::setQuality(int quality)
{
    d->quality = quality;
}

/*!
    Returns the quality setting of the image format.

    \sa setQuality()
*/
int QImageReader::quality() const
{
    return d->quality;
}


/*!
    Returns the size of the image, without actually reading the image
    contents.

    If the image format does not support this feature, this function returns
    an invalid size. Qt's built-in image handlers all support this feature,
    but custom image format plugins are not required to do so.

    \sa QImageIOHandler::ImageOption, QImageIOHandler::option(), QImageIOHandler::supportsOption()
*/
QSize QImageReader::size() const
{
    if (supportsOption(QImageIOHandler::Size))
        return d->handler->option(QImageIOHandler::Size).toSize();

    return QSize();
}

/*!
    Returns the format of the image, without actually reading the image
    contents. The format describes the image format \l QImageReader::read()
    returns, not the format of the actual image.

    If the image format does not support this feature, this function returns
    an invalid format.

    \sa QImageIOHandler::ImageOption, QImageIOHandler::option(), QImageIOHandler::supportsOption()
*/
QImage::Format QImageReader::imageFormat() const
{
    if (supportsOption(QImageIOHandler::ImageFormat))
        return (QImage::Format)d->handler->option(QImageIOHandler::ImageFormat).toInt();

    return QImage::Format_Invalid;
}

/*!
    Returns the text keys for this image. You can use
    these keys with text() to list the image text for
    a certain key.

    Support for this option is implemented through
    QImageIOHandler::Description.

    \sa text(), QImageWriter::setText(), QImage::textKeys()
*/
QStringList QImageReader::textKeys() const
{
    d->getText();
    return d->text.keys();
}

/*!
    Returns the image text associated with \a key.

    Support for this option is implemented through
    QImageIOHandler::Description.

    \sa textKeys(), QImageWriter::setText()
*/
QString QImageReader::text(const QString &key) const
{
    d->getText();
    return d->text.value(key);
}

/*!
    Sets the image clip rect (also known as the ROI, or Region Of
    Interest) to \a rect. The coordinates of \a rect are relative to
    the untransformed image size, as returned by size().

    \sa clipRect(), setScaledSize(), setScaledClipRect()
*/
void QImageReader::setClipRect(const QRect &rect)
{
    d->clipRect = rect;
}

/*!
    Returns the clip rect (also known as the ROI, or Region Of
    Interest) of the image. If no clip rect has been set, an invalid
    QRect is returned.

    \sa setClipRect()
*/
QRect QImageReader::clipRect() const
{
    return d->clipRect;
}

/*!
    Sets the scaled size of the image to \a size. The scaling is
    performed after the initial clip rect, but before the scaled clip
    rect is applied. The algorithm used for scaling depends on the
    image format. By default (i.e., if the image format does not
    support scaling), QImageReader will use QImage::scale() with
    Qt::SmoothScaling.

    If only one dimension is set in \a size, the other one will be
    computed from the image's \l {size()} {natural size} so as to
    maintain the aspect ratio.

    \sa scaledSize(), setClipRect(), setScaledClipRect()
*/
void QImageReader::setScaledSize(const QSize &size)
{
    d->scaledSize = size;
}

/*!
    Returns the scaled size of the image.

    \sa setScaledSize()
*/
QSize QImageReader::scaledSize() const
{
    return d->scaledSize;
}

/*!
    Sets the scaled clip rect to \a rect. The scaled clip rect is the
    clip rect (also known as ROI, or Region Of Interest) that is
    applied after the image has been scaled.

    \sa scaledClipRect(), setScaledSize()
*/
void QImageReader::setScaledClipRect(const QRect &rect)
{
    d->scaledClipRect = rect;
}

/*!
    Returns the scaled clip rect of the image.

    \sa setScaledClipRect()
*/
QRect QImageReader::scaledClipRect() const
{
    return d->scaledClipRect;
}

/*!
    Sets the background color to \a color.
    Image formats that support this operation are expected to
    initialize the background to \a color before reading an image.

    \sa backgroundColor(), read()
*/
void QImageReader::setBackgroundColor(const QColor &color)
{
    if (supportsOption(QImageIOHandler::BackgroundColor))
        d->handler->setOption(QImageIOHandler::BackgroundColor, color);
}

/*!
    Returns the background color that's used when reading an image.
    If the image format does not support setting the background color
    an invalid color is returned.

    \sa setBackgroundColor(), read()
*/
QColor QImageReader::backgroundColor() const
{
    if (supportsOption(QImageIOHandler::BackgroundColor))
        return qvariant_cast<QColor>(d->handler->option(QImageIOHandler::BackgroundColor));
    return QColor();
}

/*!
    Returns \c true if the image format supports animation;
    otherwise, false is returned.

    \sa QMovie::supportedFormats()
*/
bool QImageReader::supportsAnimation() const
{
    if (supportsOption(QImageIOHandler::Animation))
        return d->handler->option(QImageIOHandler::Animation).toBool();
    return false;
}

/*!
    \since 5.4

    Returns the subtype of the image.
*/
QByteArray QImageReader::subType() const
{
    if (supportsOption(QImageIOHandler::SubType))
        return d->handler->option(QImageIOHandler::SubType).toByteArray();
    return QByteArray();
}

/*!
    \since 5.4

    Returns the list of subtypes supported by an image.
*/
QList<QByteArray> QImageReader::supportedSubTypes() const
{
    if (supportsOption(QImageIOHandler::SupportedSubTypes))
        return qvariant_cast<QList<QByteArray> >(d->handler->option(QImageIOHandler::SupportedSubTypes));
    return QList<QByteArray>();
}

/*!
    \since 5.5

    Returns the transformation metadata of the image, including image orientation. If the format
    does not support transformation metadata, QImageIOHandler::TransformationNone is returned.

    \sa setAutoTransform(), autoTransform()
*/
QImageIOHandler::Transformations QImageReader::transformation() const
{
    int option = QImageIOHandler::TransformationNone;
    if (supportsOption(QImageIOHandler::ImageTransformation))
        option = d->handler->option(QImageIOHandler::ImageTransformation).toInt();
    return QImageIOHandler::Transformations(option);
}

/*!
    \since 5.5

    Determines that images returned by read() should have transformation metadata automatically
    applied if \a enabled is \c true.

    \sa autoTransform(), transformation(), read()
*/
void QImageReader::setAutoTransform(bool enabled)
{
    d->autoTransform = enabled ? QImageReaderPrivate::ApplyTransform
                               : QImageReaderPrivate::DoNotApplyTransform;
}

/*!
    \since 5.5

    Returns \c true if the image handler will apply transformation metadata on read().

    \sa setAutoTransform(), transformation(), read()
*/
bool QImageReader::autoTransform() const
{
    switch (d->autoTransform) {
    case QImageReaderPrivate::ApplyTransform:
        return true;
    case QImageReaderPrivate::DoNotApplyTransform:
        return false;
    case QImageReaderPrivate::UsePluginDefault:
        Q_FALLTHROUGH();
    default:
        break;
    }
    return false;
}

/*!
    Returns \c true if an image can be read for the device (i.e., the
    image format is supported, and the device seems to contain valid
    data); otherwise returns \c false.

    canRead() is a lightweight function that only does a quick test to
    see if the image data is valid. read() may still return false
    after canRead() returns \c true, if the image data is corrupt.

    \note A QMimeDatabase lookup is normally a better approach than this
    function for identifying potentially non-image files or data.

    For images that support animation, canRead() returns \c false when
    all frames have been read.

    \sa read(), supportedImageFormats(), QMimeDatabase
*/
bool QImageReader::canRead() const
{
    if (!d->initHandler())
        return false;

    return d->handler->canRead();
}

/*!
    Reads an image from the device. On success, the image that was
    read is returned; otherwise, a null QImage is returned. You can
    then call error() to find the type of error that occurred, or
    errorString() to get a human readable description of the error.

    For image formats that support animation, calling read()
    repeatedly will return the next frame. When all frames have been
    read, a null image will be returned.

    \sa canRead(), supportedImageFormats(), supportsAnimation(), QMovie
*/
QImage QImageReader::read()
{
    // Because failed image reading might have side effects, we explicitly
    // return a null image instead of the image we've just created.
    QImage image;
    return read(&image) ? image : QImage();
}

extern void qt_imageTransform(QImage &src, QImageIOHandler::Transformations orient);

/*!
    \overload

    Reads an image from the device into \a image, which must point to a
    QImage. Returns \c true on success; otherwise, returns \c false.

    If \a image has same format and size as the image data that is about to be
    read, this function may not need to allocate a new image before
    reading. Because of this, it can be faster than the other read() overload,
    which always constructs a new image; especially when reading several
    images with the same format and size.

    \snippet code/src_gui_image_qimagereader.cpp 2

    For image formats that support animation, calling read() repeatedly will
    return the next frame. When all frames have been read, a null image will
    be returned.

    \sa canRead(), supportedImageFormats(), supportsAnimation(), QMovie
*/
bool QImageReader::read(QImage *image)
{
    if (!image) {
        qWarning("QImageReader::read: cannot read into null pointer");
        return false;
    }

    if (!d->initHandler())
        return false;

    QSize scaledSize = d->scaledSize;
    if ((scaledSize.width() <= 0 && scaledSize.height() > 0) ||
        (scaledSize.height() <= 0 && scaledSize.width() > 0)) {
        // if only one dimension is given, let's try to calculate the second one
        // based on the original image size and maintaining the aspect ratio
        if (const QSize originalSize = size(); !originalSize.isEmpty()) {
            if (scaledSize.width() <= 0) {
                const auto ratio = qreal(scaledSize.height()) / originalSize.height();
                scaledSize.setWidth(qRound(originalSize.width() * ratio));
            } else {
                const auto ratio = qreal(scaledSize.width()) / originalSize.width();
                scaledSize.setHeight(qRound(originalSize.height() * ratio));
            }
        }
    }

    const bool supportScaledSize = supportsOption(QImageIOHandler::ScaledSize) && scaledSize.isValid();
    const bool supportClipRect = supportsOption(QImageIOHandler::ClipRect) && !d->clipRect.isNull();
    const bool supportScaledClipRect = supportsOption(QImageIOHandler::ScaledClipRect) && !d->scaledClipRect.isNull();

    // set the handler specific options.
    if (supportScaledSize) {
        if (supportClipRect || d->clipRect.isNull()) {
            // Only enable the ScaledSize option if there is no clip rect, or
            // if the handler also supports ClipRect.
            d->handler->setOption(QImageIOHandler::ScaledSize, scaledSize);
        }
    }
    if (supportClipRect)
        d->handler->setOption(QImageIOHandler::ClipRect, d->clipRect);
    if (supportScaledClipRect)
        d->handler->setOption(QImageIOHandler::ScaledClipRect, d->scaledClipRect);
    if (supportsOption(QImageIOHandler::Quality))
        d->handler->setOption(QImageIOHandler::Quality, d->quality);

    // read the image
    QString filename = fileName();
    if (Q_TRACE_ENABLED(QImageReader_read_before_reading)) {
        Q_TRACE(QImageReader_read_before_reading, this, filename.isEmpty() ? u"unknown"_s : filename);
    }

    const bool result = d->handler->read(image);

    Q_TRACE(QImageReader_read_after_reading, this, result);

    if (!result) {
        d->imageReaderError = InvalidDataError;
        d->errorString = QImageReader::tr("Unable to read image data");
        return false;
    }

    // provide default implementations for any unsupported image
    // options
    if (supportClipRect) {
        if (supportScaledSize) {
            if (supportScaledClipRect) {
                // all features are supported by the handler; nothing to do.
            } else {
                // the image is already scaled, so apply scaled clipping.
                if (!d->scaledClipRect.isNull())
                    *image = image->copy(d->scaledClipRect);
            }
        } else {
            if (supportScaledClipRect) {
                // supports scaled clipping but not scaling, most
                // likely a broken handler.
            } else {
                if (scaledSize.isValid()) {
                    *image = image->scaled(scaledSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                }
                if (d->scaledClipRect.isValid()) {
                    *image = image->copy(d->scaledClipRect);
                }
            }
        }
    } else {
        if (supportScaledSize && d->clipRect.isNull()) {
            if (supportScaledClipRect) {
                // nothing to do (ClipRect is ignored!)
            } else {
                // provide all workarounds.
                if (d->scaledClipRect.isValid()) {
                    *image = image->copy(d->scaledClipRect);
                }
            }
        } else {
            if (supportScaledClipRect) {
                // this makes no sense; a handler that supports
                // ScaledClipRect but not ScaledSize is broken, and we
                // can't work around it.
            } else {
                // provide all workarounds.
                if (d->clipRect.isValid())
                    *image = image->copy(d->clipRect);
                if (scaledSize.isValid())
                    *image = image->scaled(scaledSize, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
                if (d->scaledClipRect.isValid())
                    *image = image->copy(d->scaledClipRect);
            }
        }
    }

    // successful read; check for "@Nx" file name suffix and set device pixel ratio.
    static bool disableNxImageLoading = !qEnvironmentVariableIsEmpty("QT_HIGHDPI_DISABLE_2X_IMAGE_LOADING");
    if (!disableNxImageLoading) {
        const QByteArray suffix = QFileInfo(filename).baseName().right(3).toLatin1();
        if (suffix.size() == 3 && suffix[0] == '@' && suffix[1] >= '2' && suffix[1] <= '9' && suffix[2] == 'x')
            image->setDevicePixelRatio(suffix[1] - '0');
    }
    if (autoTransform())
        qt_imageTransform(*image, transformation());

    return true;
}

/*!
   For image formats that support animation, this function steps over the
   current image, returning true if successful or false if there is no
   following image in the animation.

   The default implementation calls read(), then discards the resulting
   image, but the image handler may have a more efficient way of implementing
   this operation.

   \sa jumpToImage(), QImageIOHandler::jumpToNextImage()
*/
bool QImageReader::jumpToNextImage()
{
    if (!d->initHandler())
        return false;
    return d->handler->jumpToNextImage();
}

/*!
   For image formats that support animation, this function skips to the image
   whose sequence number is \a imageNumber, returning true if successful
   or false if the corresponding image cannot be found.

   The next call to read() will attempt to read this image.

   \sa jumpToNextImage(), QImageIOHandler::jumpToImage()
*/
bool QImageReader::jumpToImage(int imageNumber)
{
    if (!d->initHandler())
        return false;
    return d->handler->jumpToImage(imageNumber);
}

/*!
    For image formats that support animation, this function returns the number
    of times the animation should loop. If this function returns -1, it can
    either mean the animation should loop forever, or that an error occurred.
    If an error occurred, canRead() will return false.

    \sa supportsAnimation(), QImageIOHandler::loopCount(), canRead()
*/
int QImageReader::loopCount() const
{
    if (!d->initHandler())
        return -1;
    return d->handler->loopCount();
}

/*!
    For image formats that support animation, this function returns the total
    number of images in the animation. If the format does not support
    animation, 0 is returned.

    This function returns -1 if an error occurred.

    \sa supportsAnimation(), QImageIOHandler::imageCount(), canRead()
*/
int QImageReader::imageCount() const
{
    if (!d->initHandler())
        return -1;
    return d->handler->imageCount();
}

/*!
    For image formats that support animation, this function returns the number
    of milliseconds to wait until displaying the next frame in the animation.
    If the image format doesn't support animation, 0 is returned.

    This function returns -1 if an error occurred.

    \sa supportsAnimation(), QImageIOHandler::nextImageDelay(), canRead()
*/
int QImageReader::nextImageDelay() const
{
    if (!d->initHandler())
        return -1;
    return d->handler->nextImageDelay();
}

/*!
    For image formats that support animation, this function returns the
    sequence number of the current frame. If the image format doesn't support
    animation, 0 is returned.

    This function returns -1 if an error occurred.

    \sa supportsAnimation(), QImageIOHandler::currentImageNumber(), canRead()
*/
int QImageReader::currentImageNumber() const
{
    if (!d->initHandler())
        return -1;
    return d->handler->currentImageNumber();
}

/*!
    For image formats that support animation, this function returns
    the rect for the current frame. Otherwise, a null rect is returned.

    \sa supportsAnimation(), QImageIOHandler::currentImageRect()
*/
QRect QImageReader::currentImageRect() const
{
    if (!d->initHandler())
        return QRect();
    return d->handler->currentImageRect();
}

/*!
    Returns the type of error that occurred last.

    \sa ImageReaderError, errorString()
*/
QImageReader::ImageReaderError QImageReader::error() const
{
    return d->imageReaderError;
}

/*!
    Returns a human readable description of the last error that
    occurred.

    \sa error()
*/
QString QImageReader::errorString() const
{
    if (d->errorString.isEmpty())
        return QImageReader::tr("Unknown error");
    return d->errorString;
}

/*!
    Returns \c true if the reader supports \a option; otherwise returns
    false.

    Different image formats support different options. Call this function to
    determine whether a certain option is supported by the current format. For
    example, the PNG format allows you to embed text into the image's metadata
    (see text()), and the BMP format allows you to determine the image's size
    without loading the whole image into memory (see size()).

    \snippet code/src_gui_image_qimagereader.cpp 3

    \sa QImageWriter::supportsOption()
*/
bool QImageReader::supportsOption(QImageIOHandler::ImageOption option) const
{
    if (!d->initHandler())
        return false;
    return d->handler->supportsOption(option);
}

/*!
    If supported, this function returns the image format of the file
    \a fileName. Otherwise, an empty string is returned.
*/
QByteArray QImageReader::imageFormat(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return QByteArray();

    return imageFormat(&file);
}

/*!
    If supported, this function returns the image format of the device
    \a device. Otherwise, an empty string is returned.

    \sa QImageReader::autoDetectImageFormat()
*/
QByteArray QImageReader::imageFormat(QIODevice *device)
{
    QByteArray format;
    QImageIOHandler *handler = createReadHandlerHelper(device, format, /* autoDetectImageFormat = */ true, false);
    if (handler) {
        if (handler->canRead())
            format = handler->format();
        delete handler;
    }
    return format;
}

/*!
    Returns the list of image formats supported by QImageReader.

    By default, Qt can read the following formats:

    \table
    \header \li Format \li MIME type                    \li Description
    \row    \li BMP    \li image/bmp                    \li Windows Bitmap
    \row    \li GIF    \li image/gif                    \li Graphic Interchange Format (optional)
    \row    \li JPG    \li image/jpeg                   \li Joint Photographic Experts Group
    \row    \li PNG    \li image/png                    \li Portable Network Graphics
    \row    \li PBM    \li image/x-portable-bitmap      \li Portable Bitmap
    \row    \li PGM    \li image/x-portable-graymap     \li Portable Graymap
    \row    \li PPM    \li image/x-portable-pixmap      \li Portable Pixmap
    \row    \li XBM    \li image/x-xbitmap              \li X11 Bitmap
    \row    \li XPM    \li image/x-xpixmap              \li X11 Pixmap
    \row    \li SVG    \li image/svg+xml                \li Scalable Vector Graphics
    \endtable

    Reading and writing SVG files is supported through the \l{Qt SVG} module.
    The \l{Qt Image Formats} module provides support for additional image formats.

    Note that the QCoreApplication instance must be created before this function is
    called.

    \sa setFormat(), QImageWriter::supportedImageFormats(), QImageIOPlugin
*/

QList<QByteArray> QImageReader::supportedImageFormats()
{
    return QImageReaderWriterHelpers::supportedImageFormats(QImageReaderWriterHelpers::CanRead);
}

/*!
    Returns the list of MIME types supported by QImageReader.

    Note that the QApplication instance must be created before this function is
    called.

    \sa supportedImageFormats(), QImageWriter::supportedMimeTypes()
*/

QList<QByteArray> QImageReader::supportedMimeTypes()
{
    return QImageReaderWriterHelpers::supportedMimeTypes(QImageReaderWriterHelpers::CanRead);
}

/*!
    \since 5.12

    Returns the list of image formats corresponding to \a mimeType.

    Note that the QGuiApplication instance must be created before this function is
    called.

    \sa supportedImageFormats(), supportedMimeTypes()
*/

QList<QByteArray> QImageReader::imageFormatsForMimeType(const QByteArray &mimeType)
{
    return QImageReaderWriterHelpers::imageFormatsForMimeType(mimeType,
                                                              QImageReaderWriterHelpers::CanRead);
}

/*!
    \since 6.0

    Returns the current allocation limit, in megabytes.

    \sa setAllocationLimit()
*/
int QImageReader::allocationLimit()
{
    static int envLimit = []() {
        bool ok = false;
        int res = qEnvironmentVariableIntValue("QT_IMAGEIO_MAXALLOC", &ok);
        return ok ? res : -1;
    }();

    return envLimit >= 0 ? envLimit : QImageReaderPrivate::maxAlloc;
}

/*!
    \since 6.0

    Sets the allocation limit to \a mbLimit megabytes. Images that would
    require a QImage memory allocation above this limit will be rejected.
    If \a mbLimit is 0, the allocation size check will be disabled.

    This limit helps applications avoid unexpectedly large memory usage from
    loading corrupt image files. It is normally not needed to change it. The
    default limit is large enough for all commonly used image sizes.

    At runtime, this value may be overridden by the environment variable \c QT_IMAGEIO_MAXALLOC.

    \note The memory requirements are calculated for a minimum of 32 bits per pixel, since Qt will
    typically convert an image to that depth when it is used in GUI. This means that the effective
    allocation limit is significantly smaller than \a mbLimit when reading 1 bpp and 8 bpp images.

    \sa allocationLimit()
*/
void QImageReader::setAllocationLimit(int mbLimit)
{
    if (mbLimit >= 0)
        QImageReaderPrivate::maxAlloc = mbLimit;
}

QT_END_NAMESPACE
