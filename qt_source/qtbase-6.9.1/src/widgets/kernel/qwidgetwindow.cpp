// Copyright (C) 2020 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "private/qwindow_p.h"
#include "qwidgetwindow_p.h"
#include "qlayout.h"

#include "private/qwidget_p.h"
#include "private/qapplication_p.h"
#if QT_CONFIG(accessibility)
#include <QtGui/qaccessible.h>
#endif
#include <private/qwidgetrepaintmanager_p.h>
#include <qpa/qwindowsysteminterface_p.h>
#include <qpa/qplatformtheme.h>
#include <qpa/qplatformwindow.h>
#include <private/qgesturemanager_p.h>
#include <private/qhighdpiscaling_p.h>

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

Q_WIDGETS_EXPORT extern bool qt_tab_all_widgets();

Q_WIDGETS_EXPORT QWidget *qt_button_down = nullptr; // widget got last button-down

// popup control
QWidget *qt_popup_down = nullptr; // popup that contains the pressed widget
bool qt_popup_down_closed = false; // qt_popup_down has been closed

extern bool qt_try_modal(QWidget *widget, QEvent::Type type);

class QWidgetWindowPrivate : public QWindowPrivate
{
    Q_DECLARE_PUBLIC(QWidgetWindow)
public:
    void setVisible(bool visible) override
    {
        Q_Q(QWidgetWindow);
        qCDebug(lcWidgetShowHide) << "Setting visibility of" << q->widget()
               << "to" << visible << "via QWidgetWindowPrivate";

        if (QWidget *widget = q->widget()) {
            // If the widget's visible state is already matching the new QWindow
            // visible state we assume the widget has already synced up.
            if (visible != widget->isVisible())
                QWidgetPrivate::get(widget)->setVisible(visible);
        }

        // If we end up calling QWidgetPrivate::setVisible() above, we will
        // in most cases recurse back into setNativeWindowVisibility() to
        // update the QWindow state. But during QWidget::destroy() this is
        // not the case, as Qt::WA_WState_Created has been unset by the time
        // we check if we should call hide_helper(). We handle this case, as
        // well as the cases where we don't call QWidgetPrivate::setVisible(),
        // by syncing up the QWindow state here if needed.
        if (q->isVisible() != visible)
            QWindowPrivate::setVisible(visible);
    }

    QWindow *eventReceiver() override {
        Q_Q(QWidgetWindow);
        QWindow *w = q;
        while (w->parent() && qobject_cast<QWidgetWindow *>(w) && qobject_cast<QWidgetWindow *>(w->parent())) {
            w = w->parent();
        }
        return w;
    }

    void clearFocusObject() override
    {
        Q_Q(QWidgetWindow);
        QWidget *widget = q->widget();
        if (widget && widget->focusWidget())
            widget->focusWidget()->clearFocus();
    }

    void setFocusToTarget(FocusTarget target, Qt::FocusReason reason) override
    {
        Q_Q(QWidgetWindow);
        QWidget *widget = q->widget();
        if (!widget)
            return;

        switch (target) {
        case FocusTarget::Prev:
        case FocusTarget::Next: {
            QWidget *focusWidget = widget->focusWidget() ? widget->focusWidget() : widget;
            q->focusNextPrevChild(focusWidget, target == FocusTarget::Next);
            return;
        }
        case FocusTarget::First:
        case FocusTarget::Last: {
            QWidgetWindow::FocusWidgets fw = target == FocusTarget::First
                ? QWidgetWindow::FirstFocusWidget
                : QWidgetWindow::LastFocusWidget;
            if (QWidget *newFocusWidget = q->getFocusWidget(fw))
                newFocusWidget->setFocus(reason);
            break;
        }
        default:
            break;
        }
    }

    QRectF closestAcceptableGeometry(const QRectF &rect) const override;

    bool participatesInLastWindowClosed() const override;
    bool treatAsVisible() const override;
};

QRectF QWidgetWindowPrivate::closestAcceptableGeometry(const QRectF &rect) const
{
    Q_Q(const QWidgetWindow);
    const QWidget *widget = q->widget();
    if (!widget || !widget->isWindow() || !widget->hasHeightForWidth())
        return QRect();
    const QSize oldSize = rect.size().toSize();
    const QSize newSize = QLayout::closestAcceptableSize(widget, oldSize);
    if (newSize == oldSize)
        return QRectF();
    const int dw = newSize.width() - oldSize.width();
    const int dh = newSize.height() - oldSize.height();
    QRectF result = rect;
    const QRectF currentGeometry(widget->geometry());
    const qreal topOffset = result.top() - currentGeometry.top();
    const qreal bottomOffset = result.bottom() - currentGeometry.bottom();
    if (qAbs(topOffset) > qAbs(bottomOffset))
        result.setTop(result.top() - dh); // top edge drag
    else
        result.setBottom(result.bottom() + dh); // bottom edge drag
    const qreal leftOffset = result.left() - currentGeometry.left();
    const qreal rightOffset = result.right() - currentGeometry.right();
    if (qAbs(leftOffset) > qAbs(rightOffset))
        result.setLeft(result.left() - dw); // left edge drag
    else
        result.setRight(result.right() + dw); // right edge drag
    return result;
}

bool q_evaluateRhiConfig(const QWidget *w, QPlatformBackingStoreRhiConfig *outConfig, QSurface::SurfaceType *outType);

QWidgetWindow::QWidgetWindow(QWidget *widget)
    : QWindow(*new QWidgetWindowPrivate(), nullptr)
    , m_widget(widget)
{
    updateObjectName();
    if (!QCoreApplication::testAttribute(Qt::AA_ForceRasterWidgets)) {
        QSurface::SurfaceType type = QSurface::RasterSurface;
        if (q_evaluateRhiConfig(m_widget, nullptr, &type))
            setSurfaceType(type);
    }

    connect(widget, &QObject::objectNameChanged, this, &QWidgetWindow::updateObjectName);
    connect(this, &QWidgetWindow::screenChanged, this, &QWidgetWindow::handleScreenChange);
}

QWidgetWindow::~QWidgetWindow()
{
    // destroy while we are still alive
    destroy();

    if (!m_widget)
        return;

    QTLWExtra *topData = QWidgetPrivate::get(m_widget)->topData();
    Q_ASSERT(topData);

    // The QPlaformBackingStore may hold a reference to the window,
    // so the backingstore needs to be deleted first.
    topData->repaintManager.reset(nullptr);
    delete topData->backingStore;
    topData->backingStore = nullptr;
    topData->widgetTextures.clear();

    // Too late to do anything beyond this point
    topData->window = nullptr;
}

#if QT_CONFIG(accessibility)
QAccessibleInterface *QWidgetWindow::accessibleRoot() const
{
    if (m_widget)
        return QAccessible::queryAccessibleInterface(m_widget);
    return nullptr;
}
#endif

QObject *QWidgetWindow::focusObject() const
{
    QWidget *windowWidget = m_widget;
    if (!windowWidget)
        return nullptr;

    // A window can't have a focus object if it's being destroyed.
    if (QWidgetPrivate::get(windowWidget)->data.in_destructor)
        return nullptr;

    QWidget *widget = windowWidget->focusWidget();

    if (!widget)
        widget = windowWidget;

    QObject *focusObj = QWidgetPrivate::get(widget)->focusObject();
    if (focusObj)
        return focusObj;

    return widget;
}

void QWidgetWindow::setNativeWindowVisibility(bool visible)
{
    Q_D(QWidgetWindow);
    qCDebug(lcWidgetShowHide) << "Setting visibility of" << this
        << "to" << visible << "via QWidgetWindow::setNativeWindowVisibility";

    // Call base class setVisible() implementation to run the QWindow
    // visibility logic. Don't call QWidgetWindowPrivate::setVisible()
    // since that will recurse back into QWidget code.
    d->QWindowPrivate::setVisible(visible);
}

void QWidgetWindow::focusNextPrevChild(QWidget *widget, bool next)
{
    Q_ASSERT(widget);
    widget->focusNextPrevChild(next);
}

static inline bool shouldBePropagatedToWidget(QEvent *event)
{
    switch (event->type()) {
    // Handing show events to widgets would cause them to be triggered twice
    case QEvent::Show:
    case QEvent::Hide:
    case QEvent::Timer:
    case QEvent::DynamicPropertyChange:
    case QEvent::ChildAdded:
    case QEvent::ChildRemoved:
    case QEvent::Paint:
    case QEvent::Close: // Propagated manually in closeEvent
        return false;
    default:
        return true;
    }
}

bool QWidgetWindow::event(QEvent *event)
{
    if (!m_widget)
        return QWindow::event(event);

    switch (event->type()) {
    case QEvent::Enter:
    case QEvent::Leave:
        handleEnterLeaveEvent(event);
        return true;

    // these should not be sent to QWidget, the corresponding events
    // are sent by QApplicationPrivate::notifyActiveWindowChange()
    case QEvent::FocusIn:
        handleFocusInEvent(static_cast<QFocusEvent *>(event));
        Q_FALLTHROUGH();
    case QEvent::FocusOut: {
#if QT_CONFIG(accessibility)
        QAccessible::State state;
        state.active = true;
        QAccessibleStateChangeEvent ev(m_widget, state);
        QAccessible::updateAccessibility(&ev);
#endif
        return false; }

    case QEvent::FocusAboutToChange:
        if (QApplicationPrivate::focus_widget) {
            if (QApplicationPrivate::focus_widget->testAttribute(Qt::WA_InputMethodEnabled))
                QGuiApplication::inputMethod()->commit();

            QGuiApplication::forwardEvent(QApplicationPrivate::focus_widget, event);
        }
        return true;

    case QEvent::KeyPress:
    case QEvent::KeyRelease:
    case QEvent::ShortcutOverride:
        handleKeyEvent(static_cast<QKeyEvent *>(event));
        return true;

    case QEvent::MouseMove:
    case QEvent::MouseButtonPress:
    case QEvent::MouseButtonRelease:
    case QEvent::MouseButtonDblClick:
        handleMouseEvent(static_cast<QMouseEvent *>(event));
        return true;

    case QEvent::NonClientAreaMouseMove:
    case QEvent::NonClientAreaMouseButtonPress:
    case QEvent::NonClientAreaMouseButtonRelease:
    case QEvent::NonClientAreaMouseButtonDblClick:
        handleNonClientAreaMouseEvent(static_cast<QMouseEvent *>(event));
        return true;

    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
    case QEvent::TouchCancel:
        handleTouchEvent(static_cast<QTouchEvent *>(event));
        return true;

    case QEvent::Move:
        handleMoveEvent(static_cast<QMoveEvent *>(event));
        return true;

    case QEvent::Resize:
        handleResizeEvent(static_cast<QResizeEvent *>(event));
        return true;

#if QT_CONFIG(wheelevent)
    case QEvent::Wheel:
        handleWheelEvent(static_cast<QWheelEvent *>(event));
        return true;
#endif

#if QT_CONFIG(draganddrop)
    case QEvent::DragEnter:
        handleDragEnterEvent(static_cast<QDragEnterEvent *>(event));
        return true;
    case QEvent::DragMove:
        handleDragMoveEvent(static_cast<QDragMoveEvent *>(event));
        return true;
    case QEvent::DragLeave:
        handleDragLeaveEvent(static_cast<QDragLeaveEvent *>(event));
        return true;
    case QEvent::Drop:
        handleDropEvent(static_cast<QDropEvent *>(event));
        return true;
#endif

    case QEvent::Expose:
        handleExposeEvent(static_cast<QExposeEvent *>(event));
        return true;

    case QEvent::WindowStateChange:
        QWindow::event(event); // Update QWindow::Visibility and emit signals.
        handleWindowStateChangedEvent(static_cast<QWindowStateChangeEvent *>(event));
        return true;

    case QEvent::ThemeChange: {
        QEvent widgetEvent(QEvent::ThemeChange);
        QCoreApplication::forwardEvent(m_widget, &widgetEvent, event);
    }
        return true;

#if QT_CONFIG(tabletevent)
    case QEvent::TabletPress:
    case QEvent::TabletMove:
    case QEvent::TabletRelease:
        handleTabletEvent(static_cast<QTabletEvent *>(event));
        return true;
#endif

#ifndef QT_NO_GESTURES
    case QEvent::NativeGesture:
        handleGestureEvent(static_cast<QNativeGestureEvent *>(event));
        return true;
#endif

#ifndef QT_NO_CONTEXTMENU
    case QEvent::ContextMenu:
        handleContextMenuEvent(static_cast<QContextMenuEvent *>(event));
        return true;
#endif // QT_NO_CONTEXTMENU

    case QEvent::WindowBlocked:
        qt_button_down = nullptr;
        break;

    case QEvent::UpdateRequest:
        // This is not the same as an UpdateRequest for a QWidget. That just
        // syncs the backing store while here we also must mark as dirty.
        m_widget->repaint();
        return true;

    case QEvent::DevicePixelRatioChange:
        handleDevicePixelRatioChange();
        break;

    case QEvent::SafeAreaMarginsChange:
        QWidgetPrivate::get(m_widget)->updateContentsRect();
        break;

    default:
        break;
    }

    if (shouldBePropagatedToWidget(event) && QCoreApplication::forwardEvent(m_widget, event))
        return true;

    return QWindow::event(event);
}

QPointer<QWidget> qt_last_mouse_receiver = nullptr;

void QWidgetWindow::handleEnterLeaveEvent(QEvent *event)
{
    // Ignore all enter/leave events from QPA if we are not on the first-level context menu.
    // This prevents duplicated events on most platforms. Fake events will be delivered in
    // QWidgetWindow::handleMouseEvent(QMouseEvent *). Make an exception whether the widget
    // is already under mouse - let the mouse leave.
    if (QApplicationPrivate::inPopupMode() && m_widget != QApplication::activePopupWidget() && !m_widget->underMouse())
        return;

    if (event->type() == QEvent::Leave) {
        QWidget *enter = nullptr;
        // Check from window system event queue if the next queued enter targets a window
        // in the same window hierarchy (e.g. enter a child of this window). If so,
        // remove the enter event from queue and handle both in single dispatch.
        QWindowSystemInterfacePrivate::EnterEvent *systemEvent =
            static_cast<QWindowSystemInterfacePrivate::EnterEvent *>
            (QWindowSystemInterfacePrivate::peekWindowSystemEvent(QWindowSystemInterfacePrivate::Enter));
        const QPointF globalPosF = systemEvent ? systemEvent->globalPos : QPointF(QGuiApplicationPrivate::lastCursorPosition);
        if (systemEvent) {
            if (QWidgetWindow *enterWindow = qobject_cast<QWidgetWindow *>(systemEvent->enter))
            {
                QWindow *thisParent = this;
                QWindow *enterParent = enterWindow;
                while (thisParent->parent())
                    thisParent = thisParent->parent();
                while (enterParent->parent())
                    enterParent = enterParent->parent();
                if (thisParent == enterParent) {
                    QGuiApplicationPrivate::currentMouseWindow = enterWindow;
                    enter = enterWindow->widget();
                    QWindowSystemInterfacePrivate::removeWindowSystemEvent(systemEvent);
                }
            }
        }
        // Enter-leave between sibling widgets is ignored when there is a mousegrabber - this makes
        // both native and non-native widgets work similarly.
        // When mousegrabbing, leaves are only generated if leaving the parent window.
        if (!enter || !QWidget::mouseGrabber()) {
            // Preferred leave target is the last mouse receiver, unless it has native window,
            // in which case it is assumed to receive it's own leave event when relevant.
            QWidget *leave = m_widget;
            if (qt_last_mouse_receiver && !qt_last_mouse_receiver->internalWinId())
                leave = qt_last_mouse_receiver.data();
            QApplicationPrivate::dispatchEnterLeave(enter, leave, globalPosF);
            qt_last_mouse_receiver = enter;
        }
    } else {
        const QEnterEvent *ee = static_cast<QEnterEvent *>(event);
        QWidget *child = m_widget->childAt(ee->position());
        QWidget *receiver = child ? child : m_widget.data();
        QWidget *leave = nullptr;
        if (QApplicationPrivate::inPopupMode() && receiver == m_widget
                && qt_last_mouse_receiver != m_widget) {
            // This allows to deliver the leave event to the native widget
            // action on first-level menu.
            leave = qt_last_mouse_receiver;
        }
        QApplicationPrivate::dispatchEnterLeave(receiver, leave, ee->globalPosition());
        qt_last_mouse_receiver = receiver;
    }
}

QWidget *QWidgetWindow::getFocusWidget(FocusWidgets fw)
{
    QWidget *tlw = m_widget;
    QWidget *w = tlw->nextInFocusChain();

    QWidget *last = tlw;

    uint focus_flag = qt_tab_all_widgets() ? Qt::TabFocus : Qt::StrongFocus;

    while (w != tlw)
    {
        if (((w->focusPolicy() & focus_flag) == focus_flag)
            && w->isVisibleTo(m_widget) && w->isEnabled())
        {
            last = w;
            if (fw == FirstFocusWidget)
                break;
        }
        w = w->nextInFocusChain();
    }

    return last;
}

void QWidgetWindow::handleFocusInEvent(QFocusEvent *e)
{
    QWidget *focusWidget = nullptr;
    if (e->reason() == Qt::BacktabFocusReason)
        focusWidget = getFocusWidget(LastFocusWidget);
    else if (e->reason() == Qt::TabFocusReason)
        focusWidget = getFocusWidget(FirstFocusWidget);

    if (focusWidget != nullptr)
        focusWidget->setFocus();
}

void QWidgetWindow::handleNonClientAreaMouseEvent(QMouseEvent *e)
{
    QApplication::forwardEvent(m_widget, e);
}

void QWidgetWindow::handleMouseEvent(QMouseEvent *event)
{
    Q_D(QWidgetWindow);

    // Event delivery can potentially result in window re-creation (QTBUG-132912)
    // so we need QPointer to avoid a dangling d below
    QPointer<QWidgetWindow> self = this;

    if (auto *activePopupWidget = QApplication::activePopupWidget()) {
        QPointF mapped = event->position();
        if (activePopupWidget != m_widget)
            mapped = activePopupWidget->mapFromGlobal(event->globalPosition());
        bool releaseAfter = false;
        QWidget *popupChild = activePopupWidget->childAt(mapped);

        if (activePopupWidget != qt_popup_down) {
            qt_button_down = nullptr;
            qt_popup_down = nullptr;
        }

        switch (event->type()) {
        case QEvent::MouseButtonPress:
        case QEvent::MouseButtonDblClick:
            qt_button_down = popupChild;
            qt_popup_down = activePopupWidget;
            qt_popup_down_closed = false;
            break;
        case QEvent::MouseButtonRelease:
            releaseAfter = true;
            break;
        default:
            break; // nothing for mouse move
        }

        if (activePopupWidget->isEnabled()) {
            // deliver event
            QPointer<QWidget> receiver = activePopupWidget;
            QPointF widgetPos = mapped;
            if (qt_button_down)
                receiver = qt_button_down;
            else if (popupChild)
                receiver = popupChild;
            if (receiver != activePopupWidget)
                widgetPos = receiver->mapFromGlobal(event->globalPosition());

            const bool reallyUnderMouse = activePopupWidget->rect().contains(mapped.toPoint());
            const bool underMouse = activePopupWidget->underMouse();
            if (underMouse != reallyUnderMouse) {
                if (reallyUnderMouse) {
                    const QPoint receiverMapped = receiver->mapFromGlobal(event->globalPosition().toPoint());
                    // Prevent negative mouse position on enter event - this event
                    // should be properly handled in "handleEnterLeaveEvent()".
                    if (receiverMapped.x() >= 0 && receiverMapped.y() >= 0) {
                        QApplicationPrivate::dispatchEnterLeave(receiver, nullptr, event->globalPosition());
                        qt_last_mouse_receiver = receiver;
                    }
                } else {
                    QApplicationPrivate::dispatchEnterLeave(nullptr, qt_last_mouse_receiver, event->globalPosition());
                    qt_last_mouse_receiver = receiver;
                    receiver = activePopupWidget;
                }
            }

            if ((event->type() != QEvent::MouseButtonPress) || !(QMutableSinglePointEvent::isDoubleClick(event))) {
                // if the widget that was pressed is gone, then deliver move events without buttons
                const auto buttons = event->type() == QEvent::MouseMove && qt_popup_down_closed
                                   ? Qt::NoButton : event->buttons();
                QMouseEvent e(event->type(), widgetPos, event->scenePosition(), event->globalPosition(),
                              event->button(), buttons, event->modifiers(),
                              event->source(), event->pointingDevice());
                e.setTimestamp(event->timestamp());
                QApplicationPrivate::sendMouseEvent(receiver, &e, receiver, receiver->window(), &qt_button_down, qt_last_mouse_receiver);
                qt_last_mouse_receiver = receiver;
            }
        } else {
            // close disabled popups when a mouse button is pressed or released
            switch (event->type()) {
            case QEvent::MouseButtonPress:
            case QEvent::MouseButtonDblClick:
            case QEvent::MouseButtonRelease:
                activePopupWidget->close();
                break;
            default:
                break;
            }
        }

        if (QApplication::activePopupWidget() != activePopupWidget
            && QApplicationPrivate::replayMousePress
            && QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::ReplayMousePressOutsidePopup).toBool()) {
            if (m_widget->windowType() != Qt::Popup)
                qt_button_down = nullptr;
            if (event->type() == QEvent::MouseButtonPress) {
                // the popup disappeared: replay the mouse press event to whatever is behind it
                QWidget *w = QApplication::widgetAt(event->globalPosition().toPoint());
                if (w && !QApplicationPrivate::isBlockedByModal(w)) {
                    // activate window of the widget under mouse pointer
                    if (!w->isActiveWindow()) {
                        w->activateWindow();
                        w->window()->raise();
                    }

                    if (auto win = qt_widget_private(w)->windowHandle(QWidgetPrivate::WindowHandleMode::Closest)) {
                        const QRect globalGeometry = win->isTopLevel()
                        ? win->geometry()
                        : QRect(win->mapToGlobal(QPoint(0, 0)), win->size());
                        if (globalGeometry.contains(event->globalPosition().toPoint())) {
                            // Use postEvent() to ensure the local QEventLoop terminates when called from QMenu::exec()
                            const QPoint localPos = win->mapFromGlobal(event->globalPosition().toPoint());
                            QMouseEvent *e = new QMouseEvent(QEvent::MouseButtonPress, localPos, localPos, event->globalPosition().toPoint(),
                                                             event->button(), event->buttons(), event->modifiers(), event->source());
                            QCoreApplicationPrivate::setEventSpontaneous(e, true);
                            e->setTimestamp(event->timestamp());
                            QCoreApplication::postEvent(win, e);
                        }
                    }
                }
            }
            QApplicationPrivate::replayMousePress = false;
        }

        if (releaseAfter) {
            qt_button_down = nullptr;
            qt_popup_down_closed = false;
            qt_popup_down = nullptr;
        }
        return;
    }

    qt_popup_down_closed = false;
    // modal event handling
    if (QApplicationPrivate::instance()->modalState() && !qt_try_modal(m_widget, event->type()))
        return;

    // which child should have it?
    QWidget *widget = m_widget->childAt(event->position());
    QPointF mapped = event->position();

    if (!widget)
        widget = m_widget;

    const bool initialPress = event->buttons() == event->button();
    if (event->type() == QEvent::MouseButtonPress && initialPress)
        qt_button_down = widget;

    QWidget *receiver = QApplicationPrivate::pickMouseReceiver(m_widget, event->scenePosition(), &mapped, event->type(), event->buttons(),
                                                               qt_button_down, widget);
    if (!receiver)
        return;

    if (d->isPopup() && receiver->window()->windowHandle() != this) {
        receiver = widget;
        mapped = event->position().toPoint();
    }

    if ((event->type() != QEvent::MouseButtonPress) || !QMutableSinglePointEvent::isDoubleClick(event)) {

        // The preceding statement excludes MouseButtonPress events which caused
        // creation of a MouseButtonDblClick event. QTBUG-25831
        QMouseEvent translated(event->type(), mapped, event->scenePosition(), event->globalPosition(),
                               event->button(), event->buttons(), event->modifiers(),
                               event->source(), event->pointingDevice());
        translated.setTimestamp(event->timestamp());
        QApplicationPrivate::sendMouseEvent(receiver, &translated, widget, m_widget,
                                            &qt_button_down, qt_last_mouse_receiver);
        event->setAccepted(translated.isAccepted());
    }

    if (self.isNull())
        return;

#if QT_VERSION < QT_VERSION_CHECK(7, 0, 0)
    if (
#else
    if (event->isAccepted() &&
#endif
            (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonRelease))
        d->maybeSynthesizeContextMenuEvent(event);
}

void QWidgetWindow::handleTouchEvent(QTouchEvent *event)
{
    if (event->type() == QEvent::TouchCancel) {
        QApplicationPrivate::translateTouchCancel(event->pointingDevice(), event->timestamp());
        event->accept();
    } else if (QApplication::activePopupWidget()) {
        // Ignore touch events for popups. This will cause QGuiApplication to synthesise mouse
        // events instead, which QWidgetWindow::handleMouseEvent will forward correctly:
        event->ignore();
    } else {
        event->setAccepted(QApplicationPrivate::translateRawTouchEvent(m_widget, event));
    }
}

void QWidgetWindow::handleKeyEvent(QKeyEvent *event)
{
    if (QApplicationPrivate::instance()->modalState() && !qt_try_modal(m_widget, event->type()))
        return;

    QObject *receiver = QWidget::keyboardGrabber();
    if (auto *popup = QApplication::activePopupWidget(); !receiver && popup) {
        QWidget *popupFocusWidget = popup->focusWidget();
        receiver = popupFocusWidget ? popupFocusWidget : popup;
    }
    if (!receiver)
        receiver = focusObject();
    QGuiApplication::forwardEvent(receiver, event);
}

bool QWidgetWindow::updateSize()
{
    bool changed = false;
    if (m_widget->testAttribute(Qt::WA_OutsideWSRange))
        return changed;
    if (m_widget->testAttribute(Qt::WA_DontShowOnScreen))
        return changed;

    if (m_widget->data->crect.size() != geometry().size()) {
        changed = true;
        m_widget->data->crect.setSize(geometry().size());
    }

    updateMargins();
    return changed;
}

void QWidgetWindow::updateMargins()
{
    // QTBUG-79147 (Windows): Bail out on resize events after closing a dialog
    // and destroying the platform window which would clear the margins.
    QTLWExtra *te = m_widget->d_func()->topData();
    if (te->window == nullptr || te->window->handle() == nullptr)
        return;
    const QMargins margins = frameMargins();
    te->posIncludesFrame= false;
    te->frameStrut.setCoords(margins.left(), margins.top(), margins.right(), margins.bottom());
    m_widget->data->fstrut_dirty = false;
}

static void sendChangeRecursively(QWidget *widget, QEvent::Type type)
{
    QEvent e(type);
    QCoreApplication::sendEvent(widget, &e);
    QWidgetPrivate *d = QWidgetPrivate::get(widget);
    for (int i = 0; i < d->children.size(); ++i) {
        QWidget *w = qobject_cast<QWidget *>(d->children.at(i));
        if (w)
            sendChangeRecursively(w, type);
    }
}

void QWidgetWindow::handleScreenChange()
{
    // Send an event recursively to the widget and its children.
    sendChangeRecursively(m_widget, QEvent::ScreenChangeInternal);

    // Invalidate the backing store buffer and schedule repaint
    scheduleRepaint();
}

void QWidgetWindow::handleDevicePixelRatioChange()
{
    // Send an event recursively to the widget and its children.
    sendChangeRecursively(m_widget, QEvent::DevicePixelRatioChange);

    // Invalidate the backing store buffer and schedule repaint
    scheduleRepaint();
}

/*
    Schedules a repaint in response to screen or DPR changes

    Normally these changes will come with a corresponding expose
    event following the change, but to guarantee that we refresh
    the widget based on the new properties we also schedule our
    own repaint.

    Note that we do not do a synchronous repaint here, as the system
    hasn't asked us to repaint just yet, it just informed us about
    the new window state.
*/
void QWidgetWindow::scheduleRepaint()
{
    if (!screen())
        return;

    if (!m_widget->isVisible() || !m_widget->updatesEnabled() || !m_widget->rect().isValid())
        return;

    QTLWExtra *tlwExtra = m_widget->window()->d_func()->maybeTopData();
    if (tlwExtra && tlwExtra->backingStore) {
        tlwExtra->repaintManager->markDirty(m_widget->rect(), m_widget,
            QWidgetRepaintManager::UpdateLater, QWidgetRepaintManager::BufferInvalid);
    }
}

// Store normal geometry used for saving application settings.
void QWidgetWindow::updateNormalGeometry()
{
    QTLWExtra *tle = m_widget->d_func()->maybeTopData();
    if (!tle)
        return;
     // Ask platform window, default to widget geometry.
    QRect normalGeometry;
    if (const QPlatformWindow *pw = handle())
        normalGeometry = QHighDpi::fromNativePixels(pw->normalGeometry(), this);
    if (!normalGeometry.isValid() && !(m_widget->windowState() & ~Qt::WindowActive))
        normalGeometry = m_widget->geometry();
    if (normalGeometry.isValid())
        tle->normalGeometry = normalGeometry;
}

void QWidgetWindow::handleMoveEvent(QMoveEvent *event)
{
    if (m_widget->testAttribute(Qt::WA_OutsideWSRange))
        return;
    if (m_widget->testAttribute(Qt::WA_DontShowOnScreen))
        return;

    auto oldPosition = m_widget->data->crect.topLeft();
    auto newPosition = geometry().topLeft();

    if (!m_widget->isWindow()) {
        if (auto *nativeParent = m_widget->nativeParentWidget())
            newPosition = m_widget->parentWidget()->mapFrom(nativeParent, newPosition);
    }

    bool changed = newPosition != oldPosition;

    if (changed)
        m_widget->data->crect.moveTopLeft(newPosition);

    updateMargins(); // FIXME: Only do when changed?

    if (changed) {
        QMoveEvent widgetEvent(newPosition, oldPosition);
        QGuiApplication::forwardEvent(m_widget, &widgetEvent, event);
    }
}

void QWidgetWindow::handleResizeEvent(QResizeEvent *event)
{
    auto oldRect = m_widget->rect();

    if (updateSize()) {
        QGuiApplication::forwardEvent(m_widget, event);

        if (m_widget->d_func()->shouldPaintOnScreen()) {
            QRegion dirtyRegion = m_widget->rect();
            if (m_widget->testAttribute(Qt::WA_StaticContents))
                dirtyRegion -= oldRect;
            m_widget->d_func()->syncBackingStore(dirtyRegion);
        } else {
            m_widget->d_func()->syncBackingStore();
        }
    }
}

void QWidgetWindow::closeEvent(QCloseEvent *event)
{
    Q_D(QWidgetWindow);
    if (qt_popup_down == m_widget) {
        qt_popup_down = nullptr;
        qt_popup_down_closed = true;
    }
    bool accepted = m_widget->d_func()->handleClose(d->inClose ? QWidgetPrivate::CloseWithEvent
                                                                  : QWidgetPrivate::CloseWithSpontaneousEvent);
    event->setAccepted(accepted);
}

bool QWidgetWindowPrivate::participatesInLastWindowClosed() const
{
    Q_Q(const QWidgetWindow);

    // For historical reasons WA_QuitOnClose has been closely tied
    // to the lastWindowClosed signal, since the default behavior
    // is to quit the application after emitting lastWindowClosed.
    // ### Qt 7: Rename this attribute, or decouple behavior.
    if (!q->widget()->testAttribute(Qt::WA_QuitOnClose))
        return false;

    return QWindowPrivate::participatesInLastWindowClosed();
}

bool QWidgetWindowPrivate::treatAsVisible() const
{
    Q_Q(const QWidgetWindow);

    // Widget windows may have Qt::WA_DontShowOnScreen, in which case the
    // QQWidget will be visible, but the corresponding QWindow will not.
    // Since the lastWindowClosed logic relies on checking whether the
    // closed window was visible, and if there are any remaining visible
    // windows, we need to reflect the QWidget state, not the QWindow one.
    return q->widget()->isVisible();
}

#if QT_CONFIG(wheelevent)

void QWidgetWindow::handleWheelEvent(QWheelEvent *event)
{
    if (QApplicationPrivate::instance()->modalState() && !qt_try_modal(m_widget, event->type()))
        return;

    QWidget *rootWidget = m_widget;
    QPointF pos = event->position();

    // Use proper popup window for wheel event. Some QPA sends the wheel
    // event to the root menu, so redirect it to the proper popup window.
    QWidget *activePopupWidget = QApplication::activePopupWidget();
    if (activePopupWidget && activePopupWidget != m_widget) {
        rootWidget = activePopupWidget;
        pos = rootWidget->mapFromGlobal(event->globalPosition());
    }

    // which child should have it?
    QWidget *widget = rootWidget->childAt(pos);

    if (!widget)
        widget = rootWidget;

    QPointF mapped = widget->mapFrom(rootWidget, pos);

    QWheelEvent translated(mapped, event->globalPosition(), event->pixelDelta(), event->angleDelta(),
                           event->buttons(), event->modifiers(), event->phase(), event->inverted(),
                           event->source(), event->pointingDevice());
    translated.setTimestamp(event->timestamp());
    QGuiApplication::forwardEvent(widget, &translated, event);
}

#endif // QT_CONFIG(wheelevent)

#if QT_CONFIG(draganddrop)

static QWidget *findDnDTarget(QWidget *parent, const QPoint &pos)
{
    // Find a target widget under mouse that accepts drops (QTBUG-22987).
    QWidget *widget = parent->childAt(pos);
    if (!widget)
        widget = parent;
    for ( ; widget && !widget->isWindow() && !widget->acceptDrops(); widget = widget->parentWidget()) ;
    if (widget && !widget->acceptDrops())
        widget = nullptr;
    return widget;
}

/*!
    \internal

    Sends \a event to \a widget.

    Also called from dragMoveEvent(), in which case \a event is-a
    QDragMoveEvent only, not a full QDragEnterEvent, which is why this function
    takes \a event as a QDragMoveEvent and not, as one would expect,
    QDragEnterEvent (downcast would be UB).
*/
void QWidgetWindow::handleDragEnterEvent(QDragMoveEvent *event, QWidget *widget)
{
    Q_ASSERT(m_dragTarget == nullptr);
    if (!widget)
        widget = findDnDTarget(m_widget, event->position().toPoint());
    if (!widget) {
        event->ignore();
        return;
    }
    m_dragTarget = widget;

    const QPoint mapped = widget->mapFromGlobal(m_widget->mapToGlobal(event->position().toPoint()));
    QDragEnterEvent translated(mapped, event->possibleActions(), event->mimeData(),
                               event->buttons(), event->modifiers());
    QGuiApplication::forwardEvent(m_dragTarget, &translated, event);
    event->setAccepted(translated.isAccepted());
    event->setDropAction(translated.dropAction());
}

void QWidgetWindow::handleDragMoveEvent(QDragMoveEvent *event)
{
    QPointer<QWidget> widget = findDnDTarget(m_widget, event->position().toPoint());
    if (!widget) {
        event->ignore();
        if (m_dragTarget) { // Send DragLeave to previous
            QDragLeaveEvent leaveEvent;
            QWidget *dragTarget = m_dragTarget;
            m_dragTarget = nullptr;
            QGuiApplication::forwardEvent(dragTarget, &leaveEvent, event);
        }
    } else {
        const QPoint mapped = widget->mapFromGlobal(m_widget->mapToGlobal(event->position().toPoint()));
        QDragMoveEvent translated(mapped, event->possibleActions(), event->mimeData(),
                                  event->buttons(), event->modifiers());

        if (widget == m_dragTarget) { // Target widget unchanged: Send DragMove
            translated.setDropAction(event->dropAction());
            translated.setAccepted(event->isAccepted());
            QGuiApplication::forwardEvent(m_dragTarget, &translated, event);
        } else {
            if (m_dragTarget) { // Send DragLeave to previous
                QDragLeaveEvent leaveEvent;
                QWidget *dragTarget = m_dragTarget;
                m_dragTarget = nullptr;
                QGuiApplication::forwardEvent(dragTarget, &leaveEvent, event);
            }
            // widget might have been deleted when handling the leaveEvent
            if (widget) {
                // Send DragEnter to new widget.
                handleDragEnterEvent(event, widget);
                // Handling 'DragEnter' should suffice for the application.
                translated.setDropAction(event->dropAction());
                translated.setAccepted(event->isAccepted());
                // The drag enter event is always immediately followed by a drag move event,
                // see QDragEnterEvent documentation.
                if (m_dragTarget)
                    QGuiApplication::forwardEvent(m_dragTarget, &translated, event);
            }
        }
        event->setAccepted(translated.isAccepted());
        event->setDropAction(translated.dropAction());
    }
}

void QWidgetWindow::handleDragLeaveEvent(QDragLeaveEvent *event)
{
    if (m_dragTarget) {
        QWidget *dragTarget = m_dragTarget;
        m_dragTarget = nullptr;
        QGuiApplication::forwardEvent(dragTarget, event);
    }
}

void QWidgetWindow::handleDropEvent(QDropEvent *event)
{
    if (Q_UNLIKELY(m_dragTarget.isNull())) {
        qWarning() << m_widget << ": No drag target set.";
        event->ignore();
        return;
    }
    const QPoint mapped = m_dragTarget->mapFromGlobal(m_widget->mapToGlobal(event->position().toPoint()));
    QDropEvent translated(mapped, event->possibleActions(), event->mimeData(), event->buttons(), event->modifiers());
    QWidget *dragTarget = m_dragTarget;
    m_dragTarget = nullptr;
    QGuiApplication::forwardEvent(dragTarget, &translated, event);
    event->setAccepted(translated.isAccepted());
    event->setDropAction(translated.dropAction());
}

#endif // QT_CONFIG(draganddrop)

void QWidgetWindow::handleExposeEvent(QExposeEvent *event)
{
    if (m_widget->testAttribute(Qt::WA_DontShowOnScreen))
        return; // Ignore for widgets that fake exposure

    QWidgetPrivate *wPriv = m_widget->d_func();
    const bool exposed = isExposed();

    // We might get an expose event from the platform as part of
    // closing the window from ~QWidget, to support animated close
    // transitions. But at that point we no longer have a widget
    // subclass to draw a new frame, so skip the expose event.
    if (exposed && wPriv->data.in_destructor)
        return;

    if (wPriv->childrenHiddenByWState) {
        // If widgets has been previously hidden by window state change event
        // and they aren't yet shown...
        if (exposed) {
            // If the window becomes exposed...
            if (!wPriv->childrenShownByExpose) {
                // ... and they haven't been shown by this function yet - show it.
                wPriv->showChildren(true);
                QShowEvent showEvent;
                QCoreApplication::forwardEvent(m_widget, &showEvent, event);
                wPriv->childrenShownByExpose = true;
            }
        } else {
            // If the window becomes not exposed...
            if (wPriv->childrenShownByExpose) {
                // ... and child widgets was previously shown by the expose event - hide widgets again.
                // This is a workaround, because sometimes when window is minimized programmatically,
                // the QPA can notify that the window is exposed after changing window state to minimized
                // and then, the QPA can send next expose event with null exposed region (not exposed).
                wPriv->hideChildren(true);
                QHideEvent hideEvent;
                QCoreApplication::forwardEvent(m_widget, &hideEvent, event);
                wPriv->childrenShownByExpose = false;
            }
        }
    }

    if (exposed) {
        // QTBUG-39220, QTBUG-58575: set all (potentially fully obscured parent widgets) mapped.
        m_widget->setAttribute(Qt::WA_Mapped);
        for (QWidget *p = m_widget->parentWidget(); p && !p->testAttribute(Qt::WA_Mapped); p = p->parentWidget())
            p->setAttribute(Qt::WA_Mapped);
        if (!event->m_region.isNull())
            wPriv->syncBackingStore(event->m_region);
    } else {
        m_widget->setAttribute(Qt::WA_Mapped, false);
    }
}

void QWidgetWindow::handleWindowStateChangedEvent(QWindowStateChangeEvent *event)
{
    // QWindow does currently not know 'active'.
    Qt::WindowStates eventState = event->oldState();
    Qt::WindowStates widgetState = m_widget->windowState();
    Qt::WindowStates windowState = windowStates();
    if (widgetState & Qt::WindowActive)
        eventState |= Qt::WindowActive;

    // Determine the new widget state, remember maximized/full screen
    // during minimized.
    if (windowState & Qt::WindowMinimized) {
        widgetState |= Qt::WindowMinimized;
    } else {
        widgetState = windowState | (widgetState & Qt::WindowActive);
        if (windowState) // Maximized or FullScreen
            updateNormalGeometry();
    }

    // Sent event if the state changed (that is, it is not triggered by
    // QWidget::setWindowState(), which also sends an event to the widget).
    if (widgetState != Qt::WindowStates::Int(m_widget->data->window_state)) {
        m_widget->data->window_state = uint(widgetState);
        QWindowStateChangeEvent widgetEvent(eventState);
        QGuiApplication::forwardEvent(m_widget, &widgetEvent, event);
    }
}

bool QWidgetWindow::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
    return m_widget->nativeEvent(eventType, message, result);
}

#if QT_CONFIG(tabletevent)
void QWidgetWindow::handleTabletEvent(QTabletEvent *event)
{
    static QPointer<QWidget> qt_tablet_target = nullptr;

    QWidget *widget = qt_tablet_target;

    if (!widget) {
        widget = m_widget->childAt(event->position());
        if (!widget)
            widget = m_widget;
        if (event->type() == QEvent::TabletPress)
            qt_tablet_target = widget;
    }

    if (widget) {
        QPointF delta = event->globalPosition() - event->globalPosition().toPoint();
        QPointF mapped = widget->mapFromGlobal(event->globalPosition().toPoint()) + delta;
        QTabletEvent ev(event->type(), event->pointingDevice(), mapped, event->globalPosition(),
                        event->pressure(), event->xTilt(), event->yTilt(), event->tangentialPressure(),
                        event->rotation(), event->z(), event->modifiers(), event->button(), event->buttons());
        ev.setTimestamp(event->timestamp());
        ev.setAccepted(false);
        QGuiApplication::forwardEvent(widget, &ev, event);
        event->setAccepted(ev.isAccepted());
    }

    if (event->type() == QEvent::TabletRelease && event->buttons() == Qt::NoButton)
        qt_tablet_target = nullptr;
}
#endif // QT_CONFIG(tabletevent)

#ifndef QT_NO_GESTURES
void QWidgetWindow::handleGestureEvent(QNativeGestureEvent *e)
{
    // copy-pasted code to find correct widget follows:
    QObject *receiver = nullptr;
    if (auto *popup = QApplication::activePopupWidget()) {
        QWidget *popupFocusWidget = popup->focusWidget();
        receiver = popupFocusWidget ? popupFocusWidget : popup;
    }
    if (!receiver)
        receiver = QApplication::widgetAt(e->globalPosition().toPoint());
    if (!receiver)
        receiver = m_widget; // last resort

    QApplication::forwardEvent(receiver, e);
}
#endif // QT_NO_GESTURES

#ifndef QT_NO_CONTEXTMENU
void QWidgetWindow::handleContextMenuEvent(QContextMenuEvent *e)
{
    QWidget *receiver = qt_last_mouse_receiver.get();
    QPoint pos = e->pos();
    QPoint globalPos = e->globalPos();

    // Keyboard-originating context menu events are delivered to the focus widget,
    // independently of event position.
    if (e->reason() == QContextMenuEvent::Keyboard) {
        receiver = QWidget::keyboardGrabber();
        if (!receiver) {
            if (QApplication::activePopupWidget()) {
                receiver = (QApplication::activePopupWidget()->focusWidget()
                            ? QApplication::activePopupWidget()->focusWidget()
                            : QApplication::activePopupWidget());
            } else if (QApplication::focusWidget()) {
                receiver = QApplication::focusWidget();
            } else {
                receiver = m_widget;
            }
        }
        if (Q_LIKELY(receiver)) {
            pos = receiver->inputMethodQuery(Qt::ImCursorRectangle).toRect().center();
            globalPos = receiver->mapToGlobal(pos);
        }
    } else if (Q_LIKELY(receiver)) {
        pos = receiver->mapFromGlobal(e->globalPos());
    }

    if (receiver && receiver->isEnabled()) {
        QContextMenuEvent widgetEvent(e->reason(), pos, globalPos, e->modifiers());
        QGuiApplication::forwardEvent(receiver, &widgetEvent, e);
    }
}
#endif // QT_NO_CONTEXTMENU

void QWidgetWindow::updateObjectName()
{
    QString name = m_widget->objectName();
    if (name.isEmpty())
        name = QString::fromUtf8(m_widget->metaObject()->className()) + "Class"_L1;
    name += "Window"_L1;
    setObjectName(name);
}

QT_END_NAMESPACE

#include "moc_qwidgetwindow_p.cpp"
