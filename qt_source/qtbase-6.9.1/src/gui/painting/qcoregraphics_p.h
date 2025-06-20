// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QCOREGRAPHICS_P_H
#define QCOREGRAPHICS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/private/qcore_mac_p.h>

#include <QtGui/private/qtguiglobal_p.h>
#include <QtGui/qicon.h>
#include <QtGui/qpalette.h>
#include <QtGui/qregion.h>

#include <CoreGraphics/CoreGraphics.h>

#if defined(__OBJC__)
# if defined(Q_OS_MACOS)
#  include <AppKit/AppKit.h>
# elif defined(QT_PLATFORM_UIKIT)
#  include <UIKit/UIKit.h>
# endif
#endif

QT_BEGIN_NAMESPACE

Q_GUI_EXPORT CGBitmapInfo qt_mac_bitmapInfoForImage(const QImage &image);

#ifdef QT_PLATFORM_UIKIT
Q_GUI_EXPORT QImage qt_mac_toQImage(const UIImage *image, QSizeF size);
#endif

#ifdef Q_OS_MACOS
Q_GUI_EXPORT QPixmap qt_mac_toQPixmap(const NSImage *image, const QSizeF &size);

QT_END_NAMESPACE

// @compatibility_alias doesn't work with categories or their methods
#define imageFromQImage QT_MANGLE_NAMESPACE(imageFromQImage)
#define imageFromQIcon QT_MANGLE_NAMESPACE(imageFromQIcon)

@interface NSImage (QtExtras)
+ (instancetype)imageFromQImage:(const QT_PREPEND_NAMESPACE(QImage) &)image;
+ (instancetype)imageFromQIcon:(const QT_PREPEND_NAMESPACE(QIcon) &)icon;
+ (instancetype)imageFromQIcon:(const QT_PREPEND_NAMESPACE(QIcon) &)icon withSize:(int)size;
+ (instancetype)imageFromQIcon:(const QT_PREPEND_NAMESPACE(QIcon) &)icon
                                            withSize:(int)size
                                            withMode:(QT_PREPEND_NAMESPACE(QIcon)::Mode)mode
                                           withState:(QT_PREPEND_NAMESPACE(QIcon)::State)state;
@end
QT_BEGIN_NAMESPACE

#endif
Q_GUI_EXPORT CGImageRef qt_mac_toCGImage(const QImage &qImage);
Q_GUI_EXPORT CGImageRef qt_mac_toCGImageMask(const QImage &qImage);
Q_GUI_EXPORT QImage qt_mac_toQImage(CGImageRef image);

Q_GUI_EXPORT void qt_mac_drawCGImage(CGContextRef inContext, const CGRect *inBounds, CGImageRef inImage);

Q_GUI_EXPORT void qt_mac_clip_cg(CGContextRef hd, const QRegion &rgn, CGAffineTransform *orig_xform);

#ifdef Q_OS_MACOS
Q_GUI_EXPORT QColor qt_mac_toQColor(const NSColor *color);
Q_GUI_EXPORT QBrush qt_mac_toQBrush(const NSColor *color, QPalette::ColorGroup colorGroup = QPalette::Normal);
#endif
Q_GUI_EXPORT QColor qt_mac_toQColor(CGColorRef color);
Q_GUI_EXPORT QBrush qt_mac_toQBrush(CGColorRef color);

class Q_GUI_EXPORT QMacCGContext
{
public:
    QMacCGContext() = default;
    QMacCGContext(QPaintDevice *pdev);
    QMacCGContext(QPainter *p);

    operator CGContextRef() { return context; }

private:
    void initialize(QPaintDevice *paintDevice);
    void initialize(const QImage *, QPainter *painter = nullptr);
    QCFType<CGContextRef> context;
};

QT_END_NAMESPACE

#endif // QCOREGRAPHICS_P_H
