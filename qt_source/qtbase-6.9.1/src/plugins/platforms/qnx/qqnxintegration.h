// Copyright (C) 2011 - 2013 BlackBerry Limited. All rights reserved.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QQNXINTEGRATION_H
#define QQNXINTEGRATION_H

#include <qpa/qplatformintegration.h>
#include <private/qtguiglobal_p.h>
#include <QtCore/qhash.h>
#include <QtCore/qmutex.h>

#include <screen/screen.h>
#include <QtCore/QLoggingCategory>

#if QT_CONFIG(opengl)
#include <EGL/egl.h>
#endif

QT_BEGIN_NAMESPACE

Q_DECLARE_LOGGING_CATEGORY(lcQpaQnx);
Q_DECLARE_LOGGING_CATEGORY(lcQpaGLContext);

class QQnxScreenEventThread;
class QQnxFileDialogHelper;
class QQnxNativeInterface;
class QQnxWindow;
class QQnxScreen;
class QQnxScreenEventHandler;
class QQnxNavigatorEventHandler;
class QQnxAbstractNavigator;
class QQnxAbstractVirtualKeyboard;
class QQnxServices;

class QSimpleDrag;
class QQnxInputContext;

#if QT_CONFIG(qqnx_pps)
class QQnxNavigatorEventNotifier;
class QQnxButtonEventNotifier;
#endif

#if !defined(QT_NO_CLIPBOARD)
class QQnxClipboard;
#endif

using QQnxWindowMapper = QHash<screen_window_t, QWindow *>;

class QQnxIntegration : public QPlatformIntegration
{
public:
    enum Option { // Options to be passed on command line.
        NoOptions = 0x0,
        FullScreenApplication = 0x1,
        RootWindow = 0x2,
        AlwaysFlushScreenContext = 0x4,
        SurfacelessEGLContext = 0x8,
        Desktop = 0x10
    };
    Q_DECLARE_FLAGS(Options, Option)
    explicit QQnxIntegration(const QStringList &paramList);
    ~QQnxIntegration();

    static QQnxIntegration *instance() { return ms_instance; }

    bool hasCapability(QPlatformIntegration::Capability cap) const override;

    QPlatformWindow *createForeignWindow(QWindow *window, WId nativeHandle) const override;
    QPlatformWindow *createPlatformWindow(QWindow *window) const override;
    QPlatformBackingStore *createPlatformBackingStore(QWindow *window) const override;

#if QT_CONFIG(opengl)
    EGLDisplay eglDisplay() const { return m_eglDisplay; }
    QPlatformOpenGLContext *createPlatformOpenGLContext(QOpenGLContext *context) const override;
#endif

    QPlatformInputContext *inputContext() const override;

    void moveToScreen(QWindow *window, int screen);

    bool supportsNavigatorEvents() const;

    QAbstractEventDispatcher *createEventDispatcher() const override;

    QPlatformFontDatabase *fontDatabase() const override { return m_fontDatabase; }

    QPlatformNativeInterface *nativeInterface() const override;

#if !defined(QT_NO_CLIPBOARD)
    QPlatformClipboard *clipboard() const override;
#endif
#if QT_CONFIG(draganddrop)
    QPlatformDrag *drag() const override;
#endif
    QVariant styleHint(StyleHint hint) const override;

    QPlatformServices *services() const override;

    QWindow *window(screen_window_t qnxWindow) const;

    QQnxScreen *screenForNative(screen_display_t qnxScreen) const;

    void createDisplay(screen_display_t display, bool isPrimary);
    void removeDisplay(QQnxScreen *screen);
    QQnxScreen *primaryDisplay() const;
    Options options() const;
    screen_context_t screenContext();
    QByteArray screenContextId();

    QQnxNavigatorEventHandler *navigatorEventHandler();

private:
    void createDisplays();
    void destroyDisplays();

    void addWindow(screen_window_t qnxWindow, QWindow *window);
    void removeWindow(screen_window_t qnxWindow);
    QList<screen_display_t *> sortDisplays(screen_display_t *displays,
                                          int displayCount);

    screen_context_t m_screenContext;
    QByteArray m_screenContextId;
    QQnxScreenEventThread *m_screenEventThread;
    QQnxNavigatorEventHandler *m_navigatorEventHandler;
    QQnxAbstractVirtualKeyboard *m_virtualKeyboard;
    QQnxInputContext *m_inputContext;
#if QT_CONFIG(qqnx_pps)
    QQnxNavigatorEventNotifier *m_navigatorEventNotifier;
    QQnxButtonEventNotifier *m_buttonsNotifier;
#endif
    QPlatformInputContext *m_qpaInputContext;
    mutable QQnxServices *m_services = nullptr;
    QPlatformFontDatabase *m_fontDatabase;
    mutable QAbstractEventDispatcher *m_eventDispatcher;
    QQnxNativeInterface *m_nativeInterface;
    QList<QQnxScreen*> m_screens;
    QQnxScreenEventHandler *m_screenEventHandler;
#if !defined(QT_NO_CLIPBOARD)
    mutable QQnxClipboard* m_clipboard;
#endif
    QQnxAbstractNavigator *m_navigator;
#if QT_CONFIG(draganddrop)
    QSimpleDrag *m_drag;
#endif
    QQnxWindowMapper m_windowMapper;
    mutable QMutex m_windowMapperMutex;

    Options m_options;

#if QT_CONFIG(opengl)
    EGLDisplay m_eglDisplay;
    void createEglDisplay();
    void destroyEglDisplay();
#endif

    static QQnxIntegration *ms_instance;

    friend class QQnxWindow;
};

QT_END_NAMESPACE

#endif // QQNXINTEGRATION_H
