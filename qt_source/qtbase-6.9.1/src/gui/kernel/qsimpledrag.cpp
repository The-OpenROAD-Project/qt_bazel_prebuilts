// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qsimpledrag_p.h"

#include "qbitmap.h"
#include "qdrag.h"
#include "qpixmap.h"
#include "qevent.h"
#include "qfile.h"
#include "qguiapplication.h"
#include "qpoint.h"
#include "qbuffer.h"
#include "qimage.h"
#include "qdir.h"
#include "qimagereader.h"
#include "qimagewriter.h"
#include "qplatformscreen.h"
#include "qplatformwindow.h"

#include <QtCore/QEventLoop>
#include <QtCore/QDebug>
#include <QtCore/QLoggingCategory>

#include <private/qguiapplication_p.h>
#include <private/qdnd_p.h>

#include <private/qshapedpixmapdndwindow_p.h>
#include <private/qhighdpiscaling_p.h>

QT_BEGIN_NAMESPACE

Q_STATIC_LOGGING_CATEGORY(lcDnd, "qt.gui.dnd")

static QWindow* topLevelAt(const QPoint &pos)
{
    const QWindowList list = QGuiApplication::topLevelWindows();
    const auto crend = list.crend();
    for (auto it = list.crbegin(); it != crend; ++it) {
        QWindow *w = *it;
        if (w->isVisible() && w->handle() && w->geometry().contains(pos) && !qobject_cast<QShapedPixmapWindow*>(w))
            return w;
    }
    return nullptr;
}

/*!
    \class QBasicDrag
    \brief QBasicDrag is a base class for implementing platform drag and drop.
    \since 5.0
    \internal
    \ingroup qpa

    QBasicDrag implements QPlatformDrag::drag() by running a local event loop in which
    it tracks mouse movements and moves the drag icon (QShapedPixmapWindow) accordingly.
    It provides new virtuals allowing for querying whether the receiving window
    (within the Qt application or outside) accepts the drag and sets the state accordingly.
*/

QBasicDrag::QBasicDrag()
{
}

QBasicDrag::~QBasicDrag()
{
    delete m_drag_icon_window;
}

void QBasicDrag::enableEventFilter()
{
    qApp->installEventFilter(this);
}

void QBasicDrag::disableEventFilter()
{
    qApp->removeEventFilter(this);
}


static inline QPoint getNativeMousePos(QEvent *e, QWindow *window)
{
    return QHighDpi::toNativePixels(static_cast<QMouseEvent *>(e)->globalPosition().toPoint(), window);
}

bool QBasicDrag::eventFilter(QObject *o, QEvent *e)
{
    Q_UNUSED(o);

    if (!m_drag) {
        if (e->type() == QEvent::KeyRelease && static_cast<QKeyEvent*>(e)->key() == Qt::Key_Escape) {
            disableEventFilter();
            exitDndEventLoop();
            return true; // block the key release
        }
        return false;
    }

    switch (e->type()) {
        case QEvent::ShortcutOverride:
            // prevent accelerators from firing while dragging
            e->accept();
            return true;

        case QEvent::KeyPress:
        case QEvent::KeyRelease:
        {
            QKeyEvent *ke = static_cast<QKeyEvent *>(e);
            if (ke->key() == Qt::Key_Escape && e->type() == QEvent::KeyPress) {
                cancel();
                disableEventFilter();
                exitDndEventLoop();

            } else if (ke->modifiers() != QGuiApplication::keyboardModifiers()) {
                move(m_lastPos, QGuiApplication::mouseButtons(), ke->modifiers());
            }
            return true; // Eat all key events
        }

        case QEvent::MouseMove:
        {
            m_lastPos = getNativeMousePos(e, m_drag_icon_window);
            auto mouseMove = static_cast<QMouseEvent *>(e);
            move(m_lastPos, mouseMove->buttons(), mouseMove->modifiers());
            return true; // Eat all mouse move events
        }
        case QEvent::MouseButtonRelease:
        {
            QPointer<QObject> objGuard(o);
            disableEventFilter();
            if (canDrop()) {
                QPoint nativePosition = getNativeMousePos(e, m_drag_icon_window);
                auto mouseRelease = static_cast<QMouseEvent *>(e);
                drop(nativePosition, mouseRelease->buttons(), mouseRelease->modifiers());
            } else {
                cancel();
            }
            exitDndEventLoop();
            if (!objGuard)
                return true;

            // If a QShapedPixmapWindow (drag feedback) is being dragged along, the
            // mouse event's localPos() will be relative to that, which is useless.
            // We want a position relative to the window where the drag ends, if possible (?).
            // If there is no such window (belonging to this Qt application),
            // make the event relative to the window where the drag started. (QTBUG-66103)
            const QMouseEvent *release = static_cast<QMouseEvent *>(e);
            const QWindow *releaseWindow = topLevelAt(release->globalPosition().toPoint());
            qCDebug(lcDnd) << "mouse released over" << releaseWindow << "after drag from" << m_sourceWindow << "globalPos" << release->globalPosition().toPoint();
            if (!releaseWindow)
                releaseWindow = m_sourceWindow;
            QPointF releaseWindowPos = (releaseWindow ? releaseWindow->mapFromGlobal(release->globalPosition()) : release->globalPosition());
            QMouseEvent *newRelease = new QMouseEvent(release->type(),
                releaseWindowPos, releaseWindowPos, release->globalPosition(),
                release->button(), release->buttons(),
                release->modifiers(), release->source(), release->pointingDevice());
            QCoreApplication::postEvent(o, newRelease);
            return true; // defer mouse release events until drag event loop has returned
        }
        case QEvent::MouseButtonDblClick:
        case QEvent::Wheel:
            return true;
        default:
             break;
    }
    return false;
}

Qt::DropAction QBasicDrag::drag(QDrag *o)
{
    m_drag = o;
    m_executed_drop_action = Qt::IgnoreAction;
    m_can_drop = false;

    startDrag();
    m_eventLoop = new QEventLoop;
    m_eventLoop->exec();
    delete m_eventLoop;
    m_eventLoop = nullptr;
    m_drag = nullptr;
    endDrag();

    return m_executed_drop_action;
}

void QBasicDrag::cancelDrag()
{
    if (m_eventLoop) {
        cancel();
        m_eventLoop->quit();
    }
}

void QBasicDrag::startDrag()
{
    QPoint pos;
#ifndef QT_NO_CURSOR
    pos = QCursor::pos();
    static constexpr QGuiApplicationPrivate::QLastCursorPosition uninitializedCursorPosition;
    if (pos == uninitializedCursorPosition) {
        // ### fixme: no mouse pos registered. Get pos from touch...
        pos = QPoint();
    }
#endif
    m_lastPos = pos;
    recreateShapedPixmapWindow(m_screen, pos);
    enableEventFilter();
}

void QBasicDrag::endDrag()
{
}

void QBasicDrag::recreateShapedPixmapWindow(QScreen *screen, const QPoint &pos)
{
    delete m_drag_icon_window;
    // ### TODO Check if its really necessary to have m_drag_icon_window
    // when QDrag is used without a pixmap - QDrag::setPixmap()
    m_drag_icon_window = new QShapedPixmapWindow(screen);

    m_drag_icon_window->setUseCompositing(m_useCompositing);
    m_drag_icon_window->setPixmap(m_drag->pixmap());
    m_drag_icon_window->setHotspot(m_drag->hotSpot());
    m_drag_icon_window->updateGeometry(pos);
    m_drag_icon_window->setVisible(true);
}

void QBasicDrag::cancel()
{
    disableEventFilter();
    restoreCursor();
    m_drag_icon_window->setVisible(false);
}

/*!
  Move the drag label to \a globalPos, which is
  interpreted in device independent coordinates. Typically called from reimplementations of move().
 */

void QBasicDrag::moveShapedPixmapWindow(const QPoint &globalPos)
{
    if (m_drag)
        m_drag_icon_window->updateGeometry(globalPos);
}

void QBasicDrag::drop(const QPoint &, Qt::MouseButtons, Qt::KeyboardModifiers)
{
    disableEventFilter();
    restoreCursor();
    m_drag_icon_window->setVisible(false);
}

void  QBasicDrag::exitDndEventLoop()
{
    if (m_eventLoop && m_eventLoop->isRunning())
        m_eventLoop->exit();
}

void QBasicDrag::updateCursor(Qt::DropAction action)
{
#ifndef QT_NO_CURSOR
    Qt::CursorShape cursorShape = Qt::ForbiddenCursor;
    if (canDrop()) {
        switch (action) {
        case Qt::CopyAction:
            cursorShape = Qt::DragCopyCursor;
            break;
        case Qt::LinkAction:
            cursorShape = Qt::DragLinkCursor;
            break;
        default:
            cursorShape = Qt::DragMoveCursor;
            break;
        }
    }

    QPixmap pixmap = m_drag->dragCursor(action);

    if (!m_dndHasSetOverrideCursor) {
        QCursor newCursor = !pixmap.isNull() ? QCursor(pixmap) : QCursor(cursorShape);
        QGuiApplication::setOverrideCursor(newCursor);
        m_dndHasSetOverrideCursor = true;
    } else {
        QCursor *cursor = QGuiApplication::overrideCursor();
        if (!cursor) {
            QGuiApplication::changeOverrideCursor(pixmap.isNull() ? QCursor(cursorShape) : QCursor(pixmap));
        } else {
            if (!pixmap.isNull()) {
                if (cursor->pixmap().cacheKey() != pixmap.cacheKey())
                    QGuiApplication::changeOverrideCursor(QCursor(pixmap));
            } else if (cursorShape != cursor->shape()) {
                QGuiApplication::changeOverrideCursor(QCursor(cursorShape));
            }
        }
    }
#endif
    updateAction(action);
}

void QBasicDrag::restoreCursor()
{
#ifndef QT_NO_CURSOR
    if (m_dndHasSetOverrideCursor) {
        QGuiApplication::restoreOverrideCursor();
        m_dndHasSetOverrideCursor = false;
    }
#endif
}

static inline QPoint fromNativeGlobalPixels(const QPoint &point)
{
#ifndef QT_NO_HIGHDPISCALING
    QPoint res = point;
    if (QHighDpiScaling::isActive()) {
        for (const QScreen *s : std::as_const(QGuiApplicationPrivate::screen_list)) {
            if (s->handle()->geometry().contains(point)) {
                res = QHighDpi::fromNativePixels(point, s);
                break;
            }
        }
    }
    return res;
#else
    return point;
#endif
}

/*!
    \class QSimpleDrag
    \brief QSimpleDrag implements QBasicDrag for Drag and Drop operations within the Qt Application itself.
    \since 5.0
    \internal
    \ingroup qpa

    The class checks whether the receiving window is a window of the Qt application
    and sets the state accordingly. It does not take windows of other applications
    into account.
*/

QSimpleDrag::QSimpleDrag()
{
}

void QSimpleDrag::startDrag()
{
    setExecutedDropAction(Qt::IgnoreAction);

    QBasicDrag::startDrag();
    // Here we can be fairly sure that QGuiApplication::mouseButtons/keyboardModifiers() will
    // contain sensible values as startDrag() normally is called from mouse event handlers
    // by QDrag::exec(). A better API would be if we could pass something like "input device
    // pointer" to QDrag::exec(). My guess is that something like that might be required for
    // QTBUG-52430.
    m_sourceWindow = topLevelAt(QCursor::pos());
    m_windowUnderCursor = m_sourceWindow;
    if (m_sourceWindow) {
        auto nativePixelPos = QHighDpi::toNativePixels(QCursor::pos(), m_sourceWindow);
        move(nativePixelPos, QGuiApplication::mouseButtons(), QGuiApplication::keyboardModifiers());
    } else {
        setCanDrop(false);
        updateCursor(Qt::IgnoreAction);
    }

    qCDebug(lcDnd) << "drag began from" << m_sourceWindow << "cursor pos" << QCursor::pos() << "can drop?" << canDrop();
}

static void sendDragLeave(QWindow *window)
{
    QWindowSystemInterface::handleDrag(window, nullptr, QPoint(), Qt::IgnoreAction, { }, { });
}

void QSimpleDrag::cancel()
{
    QBasicDrag::cancel();
    if (drag() && m_sourceWindow) {
        sendDragLeave(m_sourceWindow);
        m_sourceWindow = nullptr;
    }
}

void QSimpleDrag::move(const QPoint &nativeGlobalPos, Qt::MouseButtons buttons,
                       Qt::KeyboardModifiers modifiers)
{
    QPoint globalPos = fromNativeGlobalPixels(nativeGlobalPos);
    moveShapedPixmapWindow(globalPos);
    QWindow *window = topLevelAt(globalPos);

    if (!window || window != m_windowUnderCursor) {
        if (m_windowUnderCursor)
            sendDragLeave(m_windowUnderCursor);
        m_windowUnderCursor = window;
        if (!window) {
            // QSimpleDrag supports only in-process dnd, we can't drop anywhere else.
            setCanDrop(false);
            updateCursor(Qt::IgnoreAction);
            return;
        }
    }

    const QPoint pos = nativeGlobalPos - window->handle()->geometry().topLeft();
    const QPlatformDragQtResponse qt_response = QWindowSystemInterface::handleDrag(
                window, drag()->mimeData(), pos, drag()->supportedActions(),
                buttons, modifiers);

    setCanDrop(qt_response.isAccepted());
    updateCursor(qt_response.acceptedAction());
}

void QSimpleDrag::drop(const QPoint &nativeGlobalPos, Qt::MouseButtons buttons,
                       Qt::KeyboardModifiers modifiers)
{
    QPoint globalPos = fromNativeGlobalPixels(nativeGlobalPos);

    QBasicDrag::drop(nativeGlobalPos, buttons, modifiers);
    QWindow *window = topLevelAt(globalPos);
    if (!window)
        return;

    const QPoint pos = nativeGlobalPos - window->handle()->geometry().topLeft();
    const QPlatformDropQtResponse response = QWindowSystemInterface::handleDrop(
                window, drag()->mimeData(), pos, drag()->supportedActions(),
                buttons, modifiers);
    if (response.isAccepted()) {
        setExecutedDropAction(response.acceptedAction());
    } else {
        setExecutedDropAction(Qt::IgnoreAction);
    }
}

QT_END_NAMESPACE
