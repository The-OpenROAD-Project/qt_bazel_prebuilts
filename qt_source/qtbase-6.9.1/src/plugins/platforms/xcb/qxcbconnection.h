// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#pragma once

#include <xcb/xcb.h>
#include <xcb/randr.h>

#include <QtCore/QTimer>
#include <QtGui/qpointingdevice.h>
#include <QtGui/private/qtguiglobal_p.h>
#include "qxcbexport.h"
#include <QHash>
#include <QList>
#include <qpa/qwindowsysteminterface.h>
#include <QtCore/QLoggingCategory>
#include <QtCore/private/qglobal_p.h>

#include "qxcbeventqueue.h"
#include "qxcbconnection_basic.h"

#if QT_CONFIG(tabletevent)
#include <QTabletEvent>
#endif

QT_BEGIN_NAMESPACE

Q_DECLARE_LOGGING_CATEGORY(lcQpaXInput)
Q_DECLARE_LOGGING_CATEGORY(lcQpaXInputEvents)
Q_DECLARE_LOGGING_CATEGORY(lcQpaScreen)
Q_DECLARE_LOGGING_CATEGORY(lcQpaEvents)
Q_DECLARE_LOGGING_CATEGORY(lcQpaPeeker)
Q_DECLARE_LOGGING_CATEGORY(lcQpaKeyboard)
Q_DECLARE_LOGGING_CATEGORY(lcQpaClipboard)
Q_DECLARE_LOGGING_CATEGORY(lcQpaXDnd)
Q_DECLARE_LOGGING_CATEGORY(lcQpaEventReader)

class QXcbVirtualDesktop;
class QXcbScreen;
class QXcbWindow;
class QXcbDrag;
class QXcbKeyboard;
class QXcbScrollingDevice;
class QXcbScrollingDevicePrivate;
class QXcbClipboard;
class QXcbWMSupport;
class QXcbNativeInterface;
class QXcbSystemTrayTracker;
class QXcbGlIntegration;

class QXcbWindowEventListener
{
public:
    virtual ~QXcbWindowEventListener() {}
    virtual bool handleNativeEvent(xcb_generic_event_t *) { return false; }

    virtual void handleExposeEvent(const xcb_expose_event_t *) {}
    virtual void handleClientMessageEvent(const xcb_client_message_event_t *) {}
    virtual void handleConfigureNotifyEvent(const xcb_configure_notify_event_t *) {}
    virtual void handleMapNotifyEvent(const xcb_map_notify_event_t *) {}
    virtual void handleUnmapNotifyEvent(const xcb_unmap_notify_event_t *) {}
    virtual void handleDestroyNotifyEvent(const xcb_destroy_notify_event_t *) {}
    virtual void handleButtonPressEvent(const xcb_button_press_event_t *) {}
    virtual void handleButtonReleaseEvent(const xcb_button_release_event_t *) {}
    virtual void handleMotionNotifyEvent(const xcb_motion_notify_event_t *) {}
    virtual void handleEnterNotifyEvent(const xcb_enter_notify_event_t *) {}
    virtual void handleLeaveNotifyEvent(const xcb_leave_notify_event_t *) {}
    virtual void handleFocusInEvent(const xcb_focus_in_event_t *) {}
    virtual void handleFocusOutEvent(const xcb_focus_out_event_t *) {}
    virtual void handlePropertyNotifyEvent(const xcb_property_notify_event_t *) {}
    virtual void handleXIMouseEvent(xcb_ge_event_t *, Qt::MouseEventSource = Qt::MouseEventNotSynthesized) {}
    virtual void handleXIEnterLeave(xcb_ge_event_t *) {}
    virtual QXcbWindow *toWindow() { return nullptr; }
};

typedef QHash<xcb_window_t, QXcbWindowEventListener *> WindowMapper;

class QXcbSyncWindowRequest : public QEvent
{
public:
    QXcbSyncWindowRequest(QXcbWindow *w) : QEvent(QEvent::Type(QEvent::User + 1)), m_window(w) { }

    QXcbWindow *window() const { return m_window; }
    void invalidate();

private:
    QXcbWindow *m_window;
};

class Q_XCB_EXPORT QXcbConnection : public QXcbBasicConnection
{
    Q_OBJECT
public:
    QXcbConnection(QXcbNativeInterface *nativeInterface, bool canGrabServer, xcb_visualid_t defaultVisualId, const char *displayName = nullptr);
    ~QXcbConnection();

    QXcbConnection *connection() const { return const_cast<QXcbConnection *>(this); }
    QXcbEventQueue *eventQueue() const { return m_eventQueue; }

    const QList<QXcbVirtualDesktop *> &virtualDesktops() const { return m_virtualDesktops; }
    const QList<QXcbScreen *> &screens() const { return m_screens; }
    QXcbVirtualDesktop *primaryVirtualDesktop() const {
        return m_virtualDesktops.value(primaryScreenNumber());
    }
    QXcbScreen *primaryScreen() const;

    const xcb_format_t *formatForDepth(uint8_t depth) const;

    bool imageNeedsEndianSwap() const
    {
        if (!hasShm())
            return false; // The non-Shm path does its own swapping
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
        return setup()->image_byte_order != XCB_IMAGE_ORDER_MSB_FIRST;
#else
        return setup()->image_byte_order != XCB_IMAGE_ORDER_LSB_FIRST;
#endif
    }

    QXcbKeyboard *keyboard() const { return m_keyboard; }

#ifndef QT_NO_CLIPBOARD
    QXcbClipboard *clipboard() const { return m_clipboard; }
#endif
#if QT_CONFIG(draganddrop)
    QXcbDrag *drag() const { return m_drag; }
#endif

    QXcbWMSupport *wmSupport() const { return m_wmSupport.data(); }
    xcb_window_t rootWindow();
    xcb_window_t clientLeader();

    bool hasDefaultVisualId() const { return m_defaultVisualId != UINT_MAX; }
    xcb_visualid_t defaultVisualId() const { return m_defaultVisualId; }

    void sync();

    void handleXcbError(xcb_generic_error_t *error);
    void printXcbError(const char *message, xcb_generic_error_t *error);
    void handleXcbEvent(xcb_generic_event_t *event);
    void printXcbEvent(const QLoggingCategory &log, const char *message,
                       xcb_generic_event_t *event) const;

    void addWindowEventListener(xcb_window_t id, QXcbWindowEventListener *eventListener);
    void removeWindowEventListener(xcb_window_t id);
    QXcbWindowEventListener *windowEventListenerFromId(xcb_window_t id);
    QXcbWindow *platformWindowFromId(xcb_window_t id);

    inline xcb_timestamp_t time() const { return m_time; }
    inline void setTime(xcb_timestamp_t t) { if (timeGreaterThan(t, m_time)) m_time = t; }

    inline xcb_timestamp_t netWmUserTime() const { return m_netWmUserTime; }
    inline void setNetWmUserTime(xcb_timestamp_t t) { if (timeGreaterThan(t, m_netWmUserTime)) m_netWmUserTime = t; }

    xcb_timestamp_t getTimestamp();
    xcb_window_t selectionOwner(xcb_atom_t atom) const;
    xcb_window_t qtSelectionOwner();

    void setButtonState(Qt::MouseButton button, bool down);
    Qt::MouseButtons buttonState() const { return m_buttonState; }
    Qt::MouseButton button() const { return m_button; }
    Qt::MouseButton translateMouseButton(xcb_button_t s);

    QXcbWindow *focusWindow() const { return m_focusWindow; }
    void setFocusWindow(QWindow *);
    QXcbWindow *mouseGrabber() const { return m_mouseGrabber; }
    void setMouseGrabber(QXcbWindow *);
    QXcbWindow *mousePressWindow() const { return m_mousePressWindow; }
    void setMousePressWindow(QXcbWindow *);

    QByteArray startupId() const;
    void setStartupId(const QByteArray &nextId);

    void grabServer();
    void ungrabServer();

    QString windowManagerName() const;

    QXcbNativeInterface *nativeInterface() const { return m_nativeInterface; }

    QXcbSystemTrayTracker *systemTrayTracker() const;

    Qt::MouseButtons queryMouseButtons() const;

    bool isUserInputEvent(xcb_generic_event_t *event) const;

    void xi2SelectStateEvents();
    void xi2SelectDeviceEvents(xcb_window_t window);
    bool xi2SetMouseGrabEnabled(xcb_window_t w, bool grab);

    Qt::MouseButton xiToQtMouseButton(uint32_t b);
    void xi2UpdateScrollingDevices();
    bool isTouchScreen(int id);

    bool startSystemMoveResizeForTouch(xcb_window_t window, int edges);
    void abortSystemMoveResize(xcb_window_t window);
    bool isDuringSystemMoveResize() const;
    void setDuringSystemMoveResize(bool during);

    bool canGrab() const { return m_canGrabServer; }

    QXcbGlIntegration *glIntegration() const;

    void flush() { xcb_flush(xcb_connection()); }
    void processXcbEvents(QEventLoop::ProcessEventsFlags flags);

    QTimer &focusInTimer() { return m_focusInTimer; }

protected:
    bool event(QEvent *e) override;

private:
    void xrandrSelectEvents();
    QXcbScreen* findScreenForCrtc(xcb_window_t rootWindow, xcb_randr_crtc_t crtc) const;
    QXcbScreen* findScreenForOutput(xcb_window_t rootWindow, xcb_randr_output_t output) const;
    QXcbVirtualDesktop* virtualDesktopForRootWindow(xcb_window_t rootWindow) const;
    void updateScreens(const xcb_randr_notify_event_t *event);
    bool checkOutputIsPrimary(xcb_window_t rootWindow, xcb_randr_output_t output);
    void updateScreen(QXcbScreen *screen, const xcb_randr_output_change_t &outputChange);
    QXcbScreen *createScreen(QXcbVirtualDesktop *virtualDesktop,
                             const xcb_randr_output_change_t &outputChange,
                             xcb_randr_get_output_info_reply_t *outputInfo);
    void destroyScreen(QXcbScreen *screen);
    void initializeScreens(bool initialized);
    void initializeScreensWithoutXRandR(xcb_screen_iterator_t *it, int screenNumber, QXcbScreen **primaryScreen);
    void initializeScreensFromOutput(xcb_screen_iterator_t *it, int screenNumber, QXcbScreen **primaryScreen);

    QXcbVirtualDesktop* virtualDesktopForNumber(int n) const;
    QXcbScreen* findScreenForMonitorInfo(const QList<QPlatformScreen *> &screens, xcb_randr_monitor_info_t *monitorInfo);
    void initializeScreensFromMonitor(xcb_screen_iterator_t *it, int screenNumber, QXcbScreen **primaryScreen, bool initialized);

    bool compressEvent(xcb_generic_event_t *event) const;
    inline bool timeGreaterThan(xcb_timestamp_t a, xcb_timestamp_t b) const
    { return static_cast<int32_t>(a - b) > 0 || b == XCB_CURRENT_TIME; }

    void xi2SetupSlavePointerDevice(void *info, bool removeExisting = true, QPointingDevice *master = nullptr);
    void xi2SetupDevices();
    // TODO get rid of this: store minimal necessary info in a subclass of QPointingDevicePrivate
    struct TouchDeviceData {
        QPointingDevice *qtTouchDevice = nullptr;
        QHash<int, QWindowSystemInterface::TouchPoint> touchPoints;
        QHash<int, QPointF> pointPressedPosition; // in screen coordinates where each point was pressed
        struct ValuatorClassInfo {
            double min = 0;
            double max = 0;
            int number = -1;
            QXcbAtom::Atom label;
        };
        QList<ValuatorClassInfo> valuatorInfo;

        // Stuff that is relevant only for touchpads
        QPointF firstPressedPosition;        // in screen coordinates where the first point was pressed
        QPointF firstPressedNormalPosition;  // device coordinates (0 to 1, 0 to 1) where the first point was pressed
        QSizeF size;                         // device size in mm
        bool providesTouchOrientation = false;
    };
    TouchDeviceData *populateTouchDevices(void *info, QXcbScrollingDevicePrivate *scrollingDeviceP, bool *used = nullptr);
    TouchDeviceData *touchDeviceForId(int id);
    void xi2HandleEvent(xcb_ge_event_t *event);
    void xi2HandleGesturePinchEvent(void *event);
    void xi2HandleGestureSwipeEvent(void *event);
    void xi2HandleHierarchyEvent(void *event);
    void xi2HandleDeviceChangedEvent(void *event);
    void xi2ProcessTouch(void *xiDevEvent, QXcbWindow *platformWindow);
#if QT_CONFIG(tabletevent)
    // TODO get rid of this: store minimal necessary info in a subclass of QXcbScrollingDevice (some tablets can scroll)
    struct TabletData {
        int deviceId = 0;
        QString name;
        QPointingDevice::PointerType pointerType = QPointingDevice::PointerType::Unknown;
        QInputDevice::DeviceType tool = QInputDevice::DeviceType::Stylus;
        Qt::MouseButtons buttons;
        qint64 serialId = 0;
        bool inProximity = false;
        struct ValuatorClassInfo {
            double minVal = 0;
            double maxVal = 0;
            double curVal = 0;
            int number = -1;
        };
        QHash<int, ValuatorClassInfo> valuatorInfo;
    };
    friend class QTypeInfo<TabletData>;
    friend class QTypeInfo<TabletData::ValuatorClassInfo>;
    bool xi2HandleTabletEvent(const void *event, TabletData *tabletData);
    void xi2ReportTabletEvent(const void *event, TabletData *tabletData);
    QList<TabletData> m_tabletData;
    TabletData *tabletDataForDevice(int id);
#endif // QT_CONFIG(tabletevent)
    void xi2HandleScrollEvent(void *event, const QPointingDevice *scrollingDevice);
    void xi2UpdateScrollingDevice(QInputDevice *scrollingDevice);
    QXcbScrollingDevice *scrollingDeviceForId(int id);

    static bool xi2GetValuatorValueIfSet(const void *event, int valuatorNum, double *value);

    QHash<int, TouchDeviceData> m_touchDevices;

    struct StartSystemMoveResizeInfo {
        xcb_window_t window = XCB_NONE;
        uint16_t deviceid;
        uint32_t pointid;
        int edges;
    } m_startSystemMoveResizeInfo;
    bool m_duringSystemMoveResize;

    const bool m_canGrabServer;
    const xcb_visualid_t m_defaultVisualId;

    QList<QXcbVirtualDesktop *> m_virtualDesktops;
    QList<QXcbScreen *> m_screens;

    xcb_timestamp_t m_time = XCB_CURRENT_TIME;
    xcb_timestamp_t m_netWmUserTime = XCB_CURRENT_TIME;

    QXcbKeyboard *m_keyboard = nullptr;
#ifndef QT_NO_CLIPBOARD
    QXcbClipboard *m_clipboard = nullptr;
#endif
#if QT_CONFIG(draganddrop)
    QXcbDrag *m_drag = nullptr;
#endif
    QScopedPointer<QXcbWMSupport> m_wmSupport;
    QXcbNativeInterface *m_nativeInterface = nullptr;

    QXcbEventQueue *m_eventQueue = nullptr;

    WindowMapper m_mapper;

    Qt::MouseButtons m_buttonState;
    Qt::MouseButton m_button = Qt::NoButton;

    QXcbWindow *m_focusWindow = nullptr;
    QXcbWindow *m_mouseGrabber = nullptr;
    QXcbWindow *m_mousePressWindow = nullptr;

#if QT_CONFIG(gestures)
    qreal m_lastPinchScale = 0;
#endif

    xcb_window_t m_clientLeader = 0;
    QByteArray m_startupId;
    QXcbSystemTrayTracker *m_systemTrayTracker = nullptr;
    mutable QXcbGlIntegration *m_glIntegration = nullptr;
    mutable bool m_glIntegrationInitialized = false;
    bool m_xiGrab = false;
    QList<int> m_xiMasterPointerIds;
    QList<int> m_xiSlavePointerIds;

    xcb_window_t m_qtSelectionOwner = 0;

    friend class QXcbEventQueue;

    QTimer m_focusInTimer;

};
#if QT_CONFIG(tabletevent)
Q_DECLARE_TYPEINFO(QXcbConnection::TabletData::ValuatorClassInfo, Q_PRIMITIVE_TYPE);
Q_DECLARE_TYPEINFO(QXcbConnection::TabletData, Q_RELOCATABLE_TYPE);
#endif

class QXcbConnectionGrabber
{
public:
    Q_NODISCARD_CTOR QXcbConnectionGrabber(QXcbConnection *connection);
    ~QXcbConnectionGrabber();
    void release();
private:
    QXcbConnection *m_connection;
};

// The xcb_send_event() requires all events to have 32 bytes. It calls memcpy() on the
// passed in event. If the passed in event is less than 32 bytes, memcpy() reaches into
// unrelated memory.
template <typename T>
struct alignas(32) q_padded_xcb_event : T { };

QT_END_NAMESPACE
