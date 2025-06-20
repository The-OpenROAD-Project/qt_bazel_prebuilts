// Copyright (C) 2013 BlackBerry Limited. All rights reserved.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#undef QT_NO_FOREACH // this file contains unported legacy Q_FOREACH uses

#include "qqnxglobal.h"

#include "qqnxintegration.h"
#include "qqnxscreeneventthread.h"
#include "qqnxnativeinterface.h"
#include "qqnxrasterbackingstore.h"
#include "qqnxscreen.h"
#include "qqnxscreeneventhandler.h"
#include "qqnxwindow.h"
#include "qqnxnavigatoreventhandler.h"
#include "qqnxabstractnavigator.h"
#include "qqnxabstractvirtualkeyboard.h"
#include "qqnxservices.h"

#include "qqnxforeignwindow.h"
#include "qqnxrasterwindow.h"
#if !defined(QT_NO_OPENGL)
#include "qqnxeglwindow.h"
#endif

#if QT_CONFIG(qqnx_pps)
#include "qqnxnavigatorpps.h"
#include "qqnxnavigatoreventnotifier.h"
#include "qqnxvirtualkeyboardpps.h"
#endif

#if QT_CONFIG(qqnx_pps)
#  include "qqnxbuttoneventnotifier.h"
#  include "qqnxclipboard.h"
#endif

#if QT_CONFIG(qqnx_imf)
#  include "qqnxinputcontext_imf.h"
#else
#  include "qqnxinputcontext_noimf.h"
#endif

#include <qpa/qplatforminputcontextfactory_p.h>
#include <qpa/qplatforminputcontext.h>

#include "private/qgenericunixfontdatabase_p.h"
#include "private/qgenericunixeventdispatcher_p.h"

#include <qpa/qplatformwindow.h>
#include <qpa/qwindowsysteminterface.h>

#include <QtGui/private/qguiapplication_p.h>
#include <QtGui/private/qrhibackingstore_p.h>

#if !defined(QT_NO_OPENGL)
#include "qqnxglcontext.h"
#include <QtGui/QOpenGLContext>
#endif

#include <private/qsimpledrag_p.h>

#include <QtCore/QDebug>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonArray>
#include <QtCore/QFile>
#include <errno.h>

QT_BEGIN_NAMESPACE

// Q_LOGGING_CATEGORY(lcQpaQnx, "qt.qpa.qnx");

using namespace Qt::StringLiterals;

QQnxIntegration *QQnxIntegration::ms_instance;

static inline QQnxIntegration::Options parseOptions(const QStringList &paramList)
{
    QQnxIntegration::Options options = QQnxIntegration::NoOptions;
    if (!paramList.contains("no-fullscreen"_L1)) {
        options |= QQnxIntegration::FullScreenApplication;
    }

    if (paramList.contains("flush-screen-context"_L1)) {
        options |= QQnxIntegration::AlwaysFlushScreenContext;
    }

    if (paramList.contains("rootwindow"_L1)) {
        options |= QQnxIntegration::RootWindow;
    }

    if (!paramList.contains("disable-EGL_KHR_surfaceless_context"_L1)) {
        options |= QQnxIntegration::SurfacelessEGLContext;
    }

    if (paramList.contains("desktop"_L1)) {
        options |= QQnxIntegration::Desktop;
    }

    return options;
}

static inline int getContextCapabilities(const QStringList &paramList)
{
    constexpr auto contextCapabilitiesPrefix = "screen-context-capabilities="_L1;
    int contextCapabilities = SCREEN_APPLICATION_CONTEXT;
    for (const QString &param : paramList) {
        if (param.startsWith(contextCapabilitiesPrefix)) {
            auto value = QStringView{param}.mid(contextCapabilitiesPrefix.length());
            bool ok = false;
            contextCapabilities = value.toInt(&ok, 0);
            if (!ok)
                contextCapabilities = SCREEN_APPLICATION_CONTEXT;
        }
    }
    return contextCapabilities;
}

QQnxIntegration::QQnxIntegration(const QStringList &paramList)
    : QPlatformIntegration()
    , m_screenContextId(256, 0)
    , m_screenEventThread(0)
    , m_navigatorEventHandler(new QQnxNavigatorEventHandler())
    , m_virtualKeyboard(0)
    , m_inputContext(0)
#if QT_CONFIG(qqnx_pps)
    , m_navigatorEventNotifier(0)
    , m_buttonsNotifier(new QQnxButtonEventNotifier())
#endif
    , m_qpaInputContext(0)
    , m_fontDatabase(new QGenericUnixFontDatabase())
    , m_eventDispatcher(createUnixEventDispatcher())
    , m_nativeInterface(new QQnxNativeInterface(this))
    , m_screenEventHandler(new QQnxScreenEventHandler(this))
#if !defined(QT_NO_CLIPBOARD)
    , m_clipboard(0)
#endif
    , m_navigator(0)
#if QT_CONFIG(draganddrop)
    , m_drag(new QSimpleDrag())
#endif
#if QT_CONFIG(opengl)
    , m_eglDisplay(EGL_NO_DISPLAY)
#endif
{
    ms_instance = this;
    m_options = parseOptions(paramList);
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;

    // Open connection to QNX composition manager
    if (screen_create_context(&m_screenContext, getContextCapabilities(paramList))) {
        qFatal("%s - Screen: Failed to create screen context - Error: %s (%i)",
               Q_FUNC_INFO, strerror(errno), errno);
    }
    screen_get_context_property_cv(m_screenContext,
                                   SCREEN_PROPERTY_ID,
                                   m_screenContextId.size(),
                                   m_screenContextId.data());
    m_screenContextId.resize(strlen(m_screenContextId.constData()));

#if QT_CONFIG(qqnx_pps)
    // Create/start navigator event notifier
    m_navigatorEventNotifier = new QQnxNavigatorEventNotifier(m_navigatorEventHandler);

    // delay invocation of start() to the time the event loop is up and running
    // needed to have the QThread internals of the main thread properly initialized
    QMetaObject::invokeMethod(m_navigatorEventNotifier, "start", Qt::QueuedConnection);
#endif

#if QT_CONFIG(opengl)
    createEglDisplay();
#endif

    // Create/start event thread
    m_screenEventThread = new QQnxScreenEventThread(m_screenContext);
    m_screenEventHandler->setScreenEventThread(m_screenEventThread);
    m_screenEventThread->start();

    m_qpaInputContext = QPlatformInputContextFactory::create();

#if QT_CONFIG(qqnx_pps)
    if (!m_qpaInputContext) {
        // Create/start the keyboard class.
        m_virtualKeyboard = new QQnxVirtualKeyboardPps();

        // delay invocation of start() to the time the event loop is up and running
        // needed to have the QThread internals of the main thread properly initialized
        QMetaObject::invokeMethod(m_virtualKeyboard, "start", Qt::QueuedConnection);
    }
#endif

#if QT_CONFIG(qqnx_pps)
    m_navigator = new QQnxNavigatorPps();
#endif

    createDisplays();

    if (m_virtualKeyboard) {
        // TODO check if we need to do this for all screens or only the primary one
        QObject::connect(m_virtualKeyboard, SIGNAL(heightChanged(int)),
                         primaryDisplay(), SLOT(keyboardHeightChanged(int)));

#if QT_CONFIG(qqnx_pps)
        // Set up the input context
        m_inputContext = new QQnxInputContext(this, *m_virtualKeyboard);
#if QT_CONFIG(qqnx_imf)
        m_screenEventHandler->addScreenEventFilter(m_inputContext);
#endif
#endif
    }

#if QT_CONFIG(qqnx_pps)
    // delay invocation of start() to the time the event loop is up and running
    // needed to have the QThread internals of the main thread properly initialized
    QMetaObject::invokeMethod(m_buttonsNotifier, "start", Qt::QueuedConnection);
#endif
}

QQnxIntegration::~QQnxIntegration()
{
    qCDebug(lcQpaQnx) << "Platform plugin shutdown begin";
    delete m_nativeInterface;

#if QT_CONFIG(draganddrop)
    // Destroy the drag object
    delete m_drag;
#endif

#if !defined(QT_NO_CLIPBOARD)
    // Delete the clipboard
    delete m_clipboard;
#endif

    // Stop/destroy navigator event notifier
#if QT_CONFIG(qqnx_pps)
    delete m_navigatorEventNotifier;
#endif
    delete m_navigatorEventHandler;

    // Stop/destroy screen event thread
    delete m_screenEventThread;

    // In case the event-dispatcher was never transferred to QCoreApplication
    delete m_eventDispatcher;

    delete m_screenEventHandler;

    // Destroy all displays
    destroyDisplays();

    // Close connection to QNX composition manager
    screen_destroy_context(m_screenContext);

#if QT_CONFIG(opengl)
    destroyEglDisplay();
#endif

#if QT_CONFIG(qqnx_pps)
    // Destroy the hardware button notifier
    delete m_buttonsNotifier;

    // Destroy input context
    delete m_inputContext;
#endif
    delete m_qpaInputContext;

    // Destroy the keyboard class.
    delete m_virtualKeyboard;

    // Destroy services class
    delete m_services;

    // Destroy navigator interface
    delete m_navigator;

    ms_instance = nullptr;

    qCDebug(lcQpaQnx) << "Platform plugin shutdown end";
}

bool QQnxIntegration::hasCapability(QPlatformIntegration::Capability cap) const
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;
    switch (cap) {
    case MultipleWindows:
    case ForeignWindows:
    case ThreadedPixmaps:
        return true;
#if !defined(QT_NO_OPENGL)
    case OpenGL:
    case ThreadedOpenGL:
    case BufferQueueingOpenGL:
        return true;
#endif
    default:
        return QPlatformIntegration::hasCapability(cap);
    }
}

QPlatformWindow *QQnxIntegration::createForeignWindow(QWindow *window, WId nativeHandle) const
{
    screen_window_t screenWindow = reinterpret_cast<screen_window_t>(nativeHandle);
    if (this->window(screenWindow)) {
        qWarning() << "QWindow already created for foreign window"
                   << screenWindow;
        return nullptr;
    }

    return new QQnxForeignWindow(window, m_screenContext, screenWindow);
}

QPlatformWindow *QQnxIntegration::createPlatformWindow(QWindow *window) const
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;
    QSurface::SurfaceType surfaceType = window->surfaceType();
    const bool needRootWindow = options() & RootWindow;
    switch (surfaceType) {
    case QSurface::RasterSurface:
        return new QQnxRasterWindow(window, m_screenContext, needRootWindow);
#if !defined(QT_NO_OPENGL)
    case QSurface::OpenGLSurface:
        return new QQnxEglWindow(window, m_screenContext, needRootWindow);
#endif
    default:
        qFatal("QQnxWindow: unsupported window API");
    }
    return 0;
}

QPlatformBackingStore *QQnxIntegration::createPlatformBackingStore(QWindow *window) const
{
    QSurface::SurfaceType surfaceType = window->surfaceType();
    qCDebug(lcQpaQnx) << Q_FUNC_INFO << surfaceType;
    switch (surfaceType) {
    case QSurface::RasterSurface:
        return new QQnxRasterBackingStore(window);
#if !defined(QT_NO_OPENGL)
    // Return a QRhiBackingStore for non-raster surface windows
    case QSurface::OpenGLSurface:
        return new QRhiBackingStore(window);
#endif
    default:
        return nullptr;
    }
}

#if !defined(QT_NO_OPENGL)
QPlatformOpenGLContext *QQnxIntegration::createPlatformOpenGLContext(QOpenGLContext *context) const
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;

    // Get color channel sizes from window format
    QSurfaceFormat format = context->format();
    int alphaSize = format.alphaBufferSize();
    int redSize = format.redBufferSize();
    int greenSize = format.greenBufferSize();
    int blueSize = format.blueBufferSize();

    // Check if all channels are don't care
    if (alphaSize == -1 && redSize == -1 && greenSize == -1 && blueSize == -1) {
        // Set color channels based on depth of window's screen
        QQnxScreen *screen = static_cast<QQnxScreen*>(context->screen()->handle());
        int depth = screen->depth();
        if (depth == 32) {
            // SCREEN_FORMAT_RGBA8888
            alphaSize = 8;
            redSize = 8;
            greenSize = 8;
            blueSize = 8;
        } else {
            // SCREEN_FORMAT_RGB565
            alphaSize = 0;
            redSize = 5;
            greenSize = 6;
            blueSize = 5;
        }
    } else {
        // Choose best match based on supported pixel formats
        if (alphaSize <= 0 && redSize <= 5 && greenSize <= 6 && blueSize <= 5) {
            // SCREEN_FORMAT_RGB565
            alphaSize = 0;
            redSize = 5;
            greenSize = 6;
            blueSize = 5;
        } else {
            // SCREEN_FORMAT_RGBA8888
            alphaSize = 8;
            redSize = 8;
            greenSize = 8;
            blueSize = 8;
        }
    }

    // Update color channel sizes in window format
    format.setAlphaBufferSize(alphaSize);
    format.setRedBufferSize(redSize);
    format.setGreenBufferSize(greenSize);
    format.setBlueBufferSize(blueSize);
    context->setFormat(format);

    QQnxGLContext *ctx = new QQnxGLContext(context->format(), context->shareHandle());
    return ctx;
}
#endif

QPlatformInputContext *QQnxIntegration::inputContext() const
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;
    if (m_qpaInputContext)
        return m_qpaInputContext;
    return m_inputContext;
}

void QQnxIntegration::moveToScreen(QWindow *window, int screen)
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO << "w =" << window << ", s =" << screen;

    // get platform window used by widget
    QQnxWindow *platformWindow = static_cast<QQnxWindow *>(window->handle());

    // lookup platform screen by index
    QQnxScreen *platformScreen = m_screens.at(screen);

    // move the platform window to the platform screen
    platformWindow->setScreen(platformScreen);
}

QAbstractEventDispatcher *QQnxIntegration::createEventDispatcher() const
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;

    // We transfer ownersip of the event-dispatcher to QtCoreApplication
    QAbstractEventDispatcher *eventDispatcher = m_eventDispatcher;
    m_eventDispatcher = 0;

    return eventDispatcher;
}

QPlatformNativeInterface *QQnxIntegration::nativeInterface() const
{
    return m_nativeInterface;
}

#if !defined(QT_NO_CLIPBOARD)
QPlatformClipboard *QQnxIntegration::clipboard() const
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;

#if QT_CONFIG(qqnx_pps)
    if (!m_clipboard)
        m_clipboard = new QQnxClipboard;
#endif
    return m_clipboard;
}
#endif

#if QT_CONFIG(draganddrop)
QPlatformDrag *QQnxIntegration::drag() const
{
    return m_drag;
}
#endif

QVariant QQnxIntegration::styleHint(QPlatformIntegration::StyleHint hint) const
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;
    if ((hint == ShowIsFullScreen) && (m_options & FullScreenApplication))
        return true;

    return QPlatformIntegration::styleHint(hint);
}

QPlatformServices * QQnxIntegration::services() const
{
    // Create services handling class
    if (m_navigator && !m_services)
        m_services = new QQnxServices(m_navigator);

    return m_services;
}

QWindow *QQnxIntegration::window(screen_window_t qnxWindow) const
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;
    QMutexLocker locker(&m_windowMapperMutex);
    Q_UNUSED(locker);
    return m_windowMapper.value(qnxWindow, 0);
}

void QQnxIntegration::addWindow(screen_window_t qnxWindow, QWindow *window)
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;
    QMutexLocker locker(&m_windowMapperMutex);
    Q_UNUSED(locker);
    m_windowMapper.insert(qnxWindow, window);
}

void QQnxIntegration::removeWindow(screen_window_t qnxWindow)
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;
    QMutexLocker locker(&m_windowMapperMutex);
    Q_UNUSED(locker);
    m_windowMapper.remove(qnxWindow);
}

/*!
  Get display ID for given \a display

  Returns -1 for failure, otherwise returns display ID
 */
static int getIdOfDisplay(screen_display_t display)
{
    int displayId;
    if (screen_get_display_property_iv(display,
                                       SCREEN_PROPERTY_ID,
                                       &displayId) == 0) {
        return displayId;
    }
    return -1;
}

/*!
  Read JSON configuration file for the QNX display order

  Returns true if file was read successfully and fills \a requestedDisplays
 */
static bool getRequestedDisplays(QJsonArray &requestedDisplays)
{
   // Check if display configuration file is provided
    QByteArray json = qgetenv("QT_QPA_QNX_DISPLAY_CONFIG");
    if (json.isEmpty())
        return false;

    // Check if configuration file exists
    QFile file(QString::fromUtf8(json));
    if (!file.open(QFile::ReadOnly)) {
        qWarning() << "Could not open config file" << json << "for reading";
        return false;
    }

    // Read config file and check it's json
    const QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    if (!doc.isObject()) {
        qWarning() << "Invalid config file" << json
                   << "- no top-level JSON object";
        return false;
    }

    // Read the requested display order
    const QJsonObject object = doc.object();
    requestedDisplays = object.value("displayOrder"_L1).toArray();

    return true;
}

/*!
  Match \a availableDisplays with display order defined in a json file
  pointed to by QT_QPA_QNX_DISPLAY_CONFIG. Display order must use same
  identifiers as defined for displays in graphics.conf. Number of
  available displays must be specified in \a displayCount

  An example configuration is below:
  \badcode
    {
      "displayOrder": [ 3, 1 ]
    }
  \endcode

  Returns ordered list of displays. If no order was specified, returns
  displays in the same order as in the original list.
*/
QList<screen_display_t *> QQnxIntegration::sortDisplays(screen_display_t *availableDisplays, int displayCount)
{
    // Intermediate list for sorting
    QList<screen_display_t *> allDisplays;
    for (int i = 0; i < displayCount; i++)
        allDisplays.append(&availableDisplays[i]);

    // Read requested display order if available
    QJsonArray requestedDisplays;
    if (!getRequestedDisplays(requestedDisplays))
        return allDisplays;

    // Go through all the requested displays IDs
    QList<screen_display_t *> orderedDisplays;
    for (const QJsonValue &value : std::as_const(requestedDisplays)) {
        int requestedValue = value.toInt();

        // Move all displays with matching ID from the intermediate list
        // to the beginning of the ordered list
        for (auto it = allDisplays.begin(), end = allDisplays.end(); it != end; ++it) {
            screen_display_t *display = *it;
            if (getIdOfDisplay(*display) == requestedValue) {
                orderedDisplays.append(display);
                allDisplays.erase(it);
                break;
            }
        }
    }

    // Place all unordered displays to the end of list
    orderedDisplays.append(allDisplays);

    return orderedDisplays;
}

void QQnxIntegration::createDisplays()
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;
    // Query number of displays
    int displayCount = 0;
    int result = screen_get_context_property_iv(m_screenContext, SCREEN_PROPERTY_DISPLAY_COUNT,
                                                &displayCount);
    Q_SCREEN_CRITICALERROR(result, "Failed to query display count");

    if (Q_UNLIKELY(displayCount < 1)) {
        // Never happens, even if there's no display, libscreen returns 1
        qFatal("QQnxIntegration: displayCount=%d", displayCount);
    }

    // Get all displays
    screen_display_t *displays = (screen_display_t *)alloca(sizeof(screen_display_t) * displayCount);
    result = screen_get_context_property_pv(m_screenContext, SCREEN_PROPERTY_DISPLAYS,
                                            (void **)displays);
    QList<screen_display_t *> orderedDisplays = sortDisplays(displays, displayCount);
    Q_SCREEN_CRITICALERROR(result, "Failed to query displays");

    // If it's primary, we create a QScreen for it even if it's not attached
    // since Qt will dereference QGuiApplication::primaryScreen()
    createDisplay(*orderedDisplays[0], /*isPrimary=*/true);

    for (int i=1; i<displayCount; i++) {
        int isAttached = 1;
        result = screen_get_display_property_iv(*orderedDisplays[i], SCREEN_PROPERTY_ATTACHED,
                                                &isAttached);
        Q_SCREEN_CHECKERROR(result, "Failed to query display attachment");

        if (!isAttached) {
            qCDebug(lcQpaQnx) << "Skipping non-attached display " << i;
            continue;
        }

        qCDebug(lcQpaQnx) << "Creating screen for display " << i;

        createDisplay(*orderedDisplays[i], /*isPrimary=*/false);
    } // of displays iteration
}

void QQnxIntegration::createDisplay(screen_display_t display, bool isPrimary)
{
    QQnxScreen *screen = new QQnxScreen(m_screenContext, display, isPrimary);
    m_screens.append(screen);
    QWindowSystemInterface::handleScreenAdded(screen);
    screen->adjustOrientation();

    QObject::connect(m_screenEventHandler, SIGNAL(newWindowCreated(void*)),
                     screen, SLOT(newWindowCreated(void*)));
    QObject::connect(m_screenEventHandler, SIGNAL(windowClosed(void*)),
                     screen, SLOT(windowClosed(void*)));

    QObject::connect(m_navigatorEventHandler, SIGNAL(rotationChanged(int)), screen, SLOT(setRotation(int)));
    QObject::connect(m_navigatorEventHandler, SIGNAL(windowGroupActivated(QByteArray)), screen, SLOT(activateWindowGroup(QByteArray)));
    QObject::connect(m_navigatorEventHandler, SIGNAL(windowGroupDeactivated(QByteArray)), screen, SLOT(deactivateWindowGroup(QByteArray)));
    QObject::connect(m_navigatorEventHandler, SIGNAL(windowGroupStateChanged(QByteArray,Qt::WindowState)),
            screen, SLOT(windowGroupStateChanged(QByteArray,Qt::WindowState)));
}

void QQnxIntegration::removeDisplay(QQnxScreen *screen)
{
    Q_CHECK_PTR(screen);
    Q_ASSERT(m_screens.contains(screen));
    m_screens.removeAll(screen);
    QWindowSystemInterface::handleScreenRemoved(screen);
}

void QQnxIntegration::destroyDisplays()
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;

    Q_FOREACH (QQnxScreen *screen, m_screens) {
        QWindowSystemInterface::handleScreenRemoved(screen);
    }
    m_screens.clear();
}

QQnxScreen *QQnxIntegration::screenForNative(screen_display_t qnxScreen) const
{
    Q_FOREACH (QQnxScreen *screen, m_screens) {
        if (screen->nativeDisplay() == qnxScreen)
            return screen;
    }

    return 0;
}

QQnxScreen *QQnxIntegration::primaryDisplay() const
{
    return m_screens.first();
}

QQnxIntegration::Options QQnxIntegration::options() const
{
    return m_options;
}

screen_context_t QQnxIntegration::screenContext()
{
    return m_screenContext;
}

QByteArray QQnxIntegration::screenContextId()
{
    return m_screenContextId;
}

QQnxNavigatorEventHandler *QQnxIntegration::navigatorEventHandler()
{
    return m_navigatorEventHandler;
}

bool QQnxIntegration::supportsNavigatorEvents() const
{
    // If QQNX_PPS is defined then we have navigator
    return m_navigator != 0;
}

#if QT_CONFIG(opengl)
void QQnxIntegration::createEglDisplay()
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;

    // Initialize connection to EGL
    m_eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (Q_UNLIKELY(m_eglDisplay == EGL_NO_DISPLAY))
        qFatal("QQnxiIntegration: failed to obtain EGL display: %x", eglGetError());

    EGLBoolean eglResult = eglInitialize(m_eglDisplay, 0, 0);
    if (Q_UNLIKELY(eglResult != EGL_TRUE))
        qFatal("QQnxIntegration: failed to initialize EGL display, err=%d", eglGetError());
}

void QQnxIntegration::destroyEglDisplay()
{
    qCDebug(lcQpaQnx) << Q_FUNC_INFO;

    // Close connection to EGL
    eglTerminate(m_eglDisplay);
}
#endif

QT_END_NAMESPACE
