// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#pragma once

#include "qxcbglintegration.h"

#include "qxcbeglwindow.h"

#include <QtGui/QOpenGLContext>
#include <qpa/qplatformopenglcontext.h>
#include <QtGui/qpa/qplatformscreen.h>
#include <QtGui/QScreen>

#include "qxcbscreen.h"

#include "qxcbeglinclude.h"

QT_BEGIN_NAMESPACE

class QXcbEglNativeInterfaceHandler;

class QXcbEglIntegration : public QXcbGlIntegration
                         , public QNativeInterface::Private::QEGLIntegration
{
public:
    QXcbEglIntegration();
    ~QXcbEglIntegration();

    bool initialize(QXcbConnection *connection) override;

    QXcbWindow *createWindow(QWindow *window) const override;
    QPlatformOpenGLContext *createPlatformOpenGLContext(QOpenGLContext *context) const override;
    QOpenGLContext *createOpenGLContext(EGLContext context, EGLDisplay display, QOpenGLContext *shareContext) const override;
    QPlatformOffscreenSurface *createPlatformOffscreenSurface(QOffscreenSurface *surface) const override;

    bool supportsThreadedOpenGL() const override { return true; }

    EGLDisplay eglDisplay() const { return m_egl_display; }

    bool usingPlatformDisplay() const { return m_using_platform_display; }

    xcb_visualid_t getCompatibleVisualId(xcb_screen_t *screen, EGLConfig config) const;
private:
    QXcbConnection *m_connection;
    EGLDisplay m_egl_display;
    bool m_using_platform_display;

    QScopedPointer<QXcbEglNativeInterfaceHandler> m_native_interface_handler;
};

QT_END_NAMESPACE
