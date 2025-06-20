/****************************************************************************
** Meta object code from reading C++ file 'qwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qwindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7QWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto QWindow::qt_create_metaobjectdata<qt_meta_tag_ZN7QWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QWindow",
        "screenChanged",
        "",
        "QScreen*",
        "screen",
        "modalityChanged",
        "Qt::WindowModality",
        "modality",
        "windowStateChanged",
        "Qt::WindowState",
        "windowState",
        "windowTitleChanged",
        "title",
        "xChanged",
        "arg",
        "yChanged",
        "widthChanged",
        "heightChanged",
        "minimumWidthChanged",
        "minimumHeightChanged",
        "maximumWidthChanged",
        "maximumHeightChanged",
        "safeAreaMarginsChanged",
        "QMargins",
        "visibleChanged",
        "visibilityChanged",
        "QWindow::Visibility",
        "visibility",
        "activeChanged",
        "contentOrientationChanged",
        "Qt::ScreenOrientation",
        "orientation",
        "focusObjectChanged",
        "object",
        "opacityChanged",
        "opacity",
        "transientParentChanged",
        "QWindow*",
        "transientParent",
        "requestActivate",
        "setVisible",
        "visible",
        "show",
        "hide",
        "showMinimized",
        "showMaximized",
        "showFullScreen",
        "showNormal",
        "close",
        "raise",
        "lower",
        "startSystemResize",
        "Qt::Edges",
        "edges",
        "startSystemMove",
        "setTitle",
        "setX",
        "setY",
        "setWidth",
        "setHeight",
        "setGeometry",
        "posx",
        "posy",
        "w",
        "h",
        "rect",
        "setMinimumWidth",
        "setMinimumHeight",
        "setMaximumWidth",
        "setMaximumHeight",
        "alert",
        "msec",
        "requestUpdate",
        "_q_clearAlert",
        "flags",
        "Qt::WindowFlags",
        "x",
        "y",
        "width",
        "height",
        "minimumWidth",
        "minimumHeight",
        "maximumWidth",
        "maximumHeight",
        "active",
        "Visibility",
        "contentOrientation",
        "Hidden",
        "AutomaticVisibility",
        "Windowed",
        "Minimized",
        "Maximized",
        "FullScreen",
        "AncestorMode",
        "ExcludeTransients",
        "IncludeTransients"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'screenChanged'
        QtMocHelpers::SignalData<void(QScreen *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'modalityChanged'
        QtMocHelpers::SignalData<void(Qt::WindowModality)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'windowStateChanged'
        QtMocHelpers::SignalData<void(Qt::WindowState)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Signal 'windowTitleChanged'
        QtMocHelpers::RevisionedSignalData<void(const QString &)>(11, 2, QMC::AccessPublic, 0x202, QMetaType::Void, {{
            { QMetaType::QString, 12 },
        }}),
        // Signal 'xChanged'
        QtMocHelpers::SignalData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'yChanged'
        QtMocHelpers::SignalData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'widthChanged'
        QtMocHelpers::SignalData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'heightChanged'
        QtMocHelpers::SignalData<void(int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'minimumWidthChanged'
        QtMocHelpers::SignalData<void(int)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'minimumHeightChanged'
        QtMocHelpers::SignalData<void(int)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'maximumWidthChanged'
        QtMocHelpers::SignalData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'maximumHeightChanged'
        QtMocHelpers::SignalData<void(int)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'safeAreaMarginsChanged'
        QtMocHelpers::RevisionedSignalData<void(QMargins)>(22, 2, QMC::AccessPublic, 0x609, QMetaType::Void, {{
            { 0x80000000 | 23, 14 },
        }}),
        // Signal 'visibleChanged'
        QtMocHelpers::SignalData<void(bool)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 14 },
        }}),
        // Signal 'visibilityChanged'
        QtMocHelpers::RevisionedSignalData<void(QWindow::Visibility)>(25, 2, QMC::AccessPublic, 0x201, QMetaType::Void, {{
            { 0x80000000 | 26, 27 },
        }}),
        // Signal 'activeChanged'
        QtMocHelpers::RevisionedSignalData<void()>(28, 2, QMC::AccessPublic, 0x201, QMetaType::Void),
        // Signal 'contentOrientationChanged'
        QtMocHelpers::SignalData<void(Qt::ScreenOrientation)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 30, 31 },
        }}),
        // Signal 'focusObjectChanged'
        QtMocHelpers::SignalData<void(QObject *)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 33 },
        }}),
        // Signal 'opacityChanged'
        QtMocHelpers::RevisionedSignalData<void(qreal)>(34, 2, QMC::AccessPublic, 0x201, QMetaType::Void, {{
            { QMetaType::QReal, 35 },
        }}),
        // Signal 'transientParentChanged'
        QtMocHelpers::RevisionedSignalData<void(QWindow *)>(36, 2, QMC::AccessPublic, 0x20d, QMetaType::Void, {{
            { 0x80000000 | 37, 38 },
        }}),
        // Slot 'requestActivate'
        QtMocHelpers::RevisionedSlotData<void()>(39, 2, QMC::AccessPublic, 0x201, QMetaType::Void),
        // Slot 'setVisible'
        QtMocHelpers::SlotData<void(bool)>(40, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 41 },
        }}),
        // Slot 'show'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'hide'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showMinimized'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showMaximized'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showFullScreen'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showNormal'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'close'
        QtMocHelpers::SlotData<bool()>(48, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'raise'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'lower'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startSystemResize'
        QtMocHelpers::SlotData<bool(Qt::Edges)>(51, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 52, 53 },
        }}),
        // Slot 'startSystemMove'
        QtMocHelpers::SlotData<bool()>(54, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'setTitle'
        QtMocHelpers::SlotData<void(const QString &)>(55, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'setX'
        QtMocHelpers::SlotData<void(int)>(56, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'setY'
        QtMocHelpers::SlotData<void(int)>(57, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'setWidth'
        QtMocHelpers::SlotData<void(int)>(58, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'setHeight'
        QtMocHelpers::SlotData<void(int)>(59, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Slot 'setGeometry'
        QtMocHelpers::SlotData<void(int, int, int, int)>(60, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 61 }, { QMetaType::Int, 62 }, { QMetaType::Int, 63 }, { QMetaType::Int, 64 },
        }}),
        // Slot 'setGeometry'
        QtMocHelpers::SlotData<void(const QRect &)>(60, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 65 },
        }}),
        // Slot 'setMinimumWidth'
        QtMocHelpers::SlotData<void(int)>(66, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 63 },
        }}),
        // Slot 'setMinimumHeight'
        QtMocHelpers::SlotData<void(int)>(67, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 64 },
        }}),
        // Slot 'setMaximumWidth'
        QtMocHelpers::SlotData<void(int)>(68, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 63 },
        }}),
        // Slot 'setMaximumHeight'
        QtMocHelpers::SlotData<void(int)>(69, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 64 },
        }}),
        // Slot 'alert'
        QtMocHelpers::RevisionedSlotData<void(int)>(70, 2, QMC::AccessPublic, 0x201, QMetaType::Void, {{
            { QMetaType::Int, 71 },
        }}),
        // Slot 'requestUpdate'
        QtMocHelpers::RevisionedSlotData<void()>(72, 2, QMC::AccessPublic, 0x203, QMetaType::Void),
        // Slot '_q_clearAlert'
        QtMocHelpers::SlotData<void()>(73, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'title'
        QtMocHelpers::PropertyData<QString>(12, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'modality'
        QtMocHelpers::PropertyData<Qt::WindowModality>(7, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
        // property 'flags'
        QtMocHelpers::PropertyData<Qt::WindowFlags>(74, 0x80000000 | 75, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'x'
        QtMocHelpers::PropertyData<int>(76, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'y'
        QtMocHelpers::PropertyData<int>(77, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'width'
        QtMocHelpers::PropertyData<int>(78, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'height'
        QtMocHelpers::PropertyData<int>(79, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'minimumWidth'
        QtMocHelpers::PropertyData<int>(80, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'minimumHeight'
        QtMocHelpers::PropertyData<int>(81, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
        // property 'maximumWidth'
        QtMocHelpers::PropertyData<int>(82, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'maximumHeight'
        QtMocHelpers::PropertyData<int>(83, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 11),
        // property 'visible'
        QtMocHelpers::PropertyData<bool>(41, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 13),
        // property 'active'
        QtMocHelpers::PropertyData<bool>(84, QMetaType::Bool, QMC::DefaultPropertyFlags, 15, 0x201),
        // property 'visibility'
        QtMocHelpers::PropertyData<Visibility>(27, 0x80000000 | 85, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 14, 0x201),
        // property 'contentOrientation'
        QtMocHelpers::PropertyData<Qt::ScreenOrientation>(86, 0x80000000 | 30, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag, 16),
        // property 'opacity'
        QtMocHelpers::PropertyData<qreal>(35, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 18, 0x201),
        // property 'transientParent'
        QtMocHelpers::PropertyData<QWindow*>(38, 0x80000000 | 37, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 19, 0x20d),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Visibility'
        QtMocHelpers::EnumData<Visibility>(85, 85, QMC::EnumFlags{}).add({
            {   87, Visibility::Hidden },
            {   88, Visibility::AutomaticVisibility },
            {   89, Visibility::Windowed },
            {   90, Visibility::Minimized },
            {   91, Visibility::Maximized },
            {   92, Visibility::FullScreen },
        }),
        // enum 'AncestorMode'
        QtMocHelpers::EnumData<AncestorMode>(93, 93, QMC::EnumFlags{}).add({
            {   94, AncestorMode::ExcludeTransients },
            {   95, AncestorMode::IncludeTransients },
        }),
    };
    return QtMocHelpers::metaObjectData<QWindow, qt_meta_tag_ZN7QWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7QWindowE_t>.metaTypes,
    nullptr
} };

void QWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->screenChanged((*reinterpret_cast< std::add_pointer_t<QScreen*>>(_a[1]))); break;
        case 1: _t->modalityChanged((*reinterpret_cast< std::add_pointer_t<Qt::WindowModality>>(_a[1]))); break;
        case 2: _t->windowStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::WindowState>>(_a[1]))); break;
        case 3: _t->windowTitleChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->xChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->yChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->widthChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->heightChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->minimumWidthChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->minimumHeightChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->maximumWidthChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->maximumHeightChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->safeAreaMarginsChanged((*reinterpret_cast< std::add_pointer_t<QMargins>>(_a[1]))); break;
        case 13: _t->visibleChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->visibilityChanged((*reinterpret_cast< std::add_pointer_t<QWindow::Visibility>>(_a[1]))); break;
        case 15: _t->activeChanged(); break;
        case 16: _t->contentOrientationChanged((*reinterpret_cast< std::add_pointer_t<Qt::ScreenOrientation>>(_a[1]))); break;
        case 17: _t->focusObjectChanged((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        case 18: _t->opacityChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 19: _t->transientParentChanged((*reinterpret_cast< std::add_pointer_t<QWindow*>>(_a[1]))); break;
        case 20: _t->requestActivate(); break;
        case 21: _t->setVisible((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 22: _t->show(); break;
        case 23: _t->hide(); break;
        case 24: _t->showMinimized(); break;
        case 25: _t->showMaximized(); break;
        case 26: _t->showFullScreen(); break;
        case 27: _t->showNormal(); break;
        case 28: { bool _r = _t->close();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 29: _t->raise(); break;
        case 30: _t->lower(); break;
        case 31: { bool _r = _t->startSystemResize((*reinterpret_cast< std::add_pointer_t<Qt::Edges>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 32: { bool _r = _t->startSystemMove();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 33: _t->setTitle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 34: _t->setX((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 35: _t->setY((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 36: _t->setWidth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 37: _t->setHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 38: _t->setGeometry((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 39: _t->setGeometry((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 40: _t->setMinimumWidth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 41: _t->setMinimumHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 42: _t->setMaximumWidth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 43: _t->setMaximumHeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 44: _t->alert((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 45: _t->requestUpdate(); break;
        case 46: _t->d_func()->_q_clearAlert(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWindow* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(QScreen * )>(_a, &QWindow::screenChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(Qt::WindowModality )>(_a, &QWindow::modalityChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(Qt::WindowState )>(_a, &QWindow::windowStateChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(const QString & )>(_a, &QWindow::windowTitleChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(int )>(_a, &QWindow::xChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(int )>(_a, &QWindow::yChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(int )>(_a, &QWindow::widthChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(int )>(_a, &QWindow::heightChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(int )>(_a, &QWindow::minimumWidthChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(int )>(_a, &QWindow::minimumHeightChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(int )>(_a, &QWindow::maximumWidthChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(int )>(_a, &QWindow::maximumHeightChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(QMargins )>(_a, &QWindow::safeAreaMarginsChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(bool )>(_a, &QWindow::visibleChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(QWindow::Visibility )>(_a, &QWindow::visibilityChanged, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)()>(_a, &QWindow::activeChanged, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(Qt::ScreenOrientation )>(_a, &QWindow::contentOrientationChanged, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(QObject * )>(_a, &QWindow::focusObjectChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(qreal )>(_a, &QWindow::opacityChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWindow::*)(QWindow * )>(_a, &QWindow::transientParentChanged, 19))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 16:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWindow* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->title(); break;
        case 1: *reinterpret_cast<Qt::WindowModality*>(_v) = _t->modality(); break;
        case 2: *reinterpret_cast<Qt::WindowFlags*>(_v) = _t->flags(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->x(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->y(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->width(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->height(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->minimumWidth(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->minimumHeight(); break;
        case 9: *reinterpret_cast<int*>(_v) = _t->maximumWidth(); break;
        case 10: *reinterpret_cast<int*>(_v) = _t->maximumHeight(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->isVisible(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->isActive(); break;
        case 13: *reinterpret_cast<Visibility*>(_v) = _t->visibility(); break;
        case 14: *reinterpret_cast<Qt::ScreenOrientation*>(_v) = _t->contentOrientation(); break;
        case 15: *reinterpret_cast<qreal*>(_v) = _t->opacity(); break;
        case 16: *reinterpret_cast<QWindow**>(_v) = _t->QWindow::d_func()->transientParent; break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setModality(*reinterpret_cast<Qt::WindowModality*>(_v)); break;
        case 2: _t->setFlags(*reinterpret_cast<Qt::WindowFlags*>(_v)); break;
        case 3: _t->setX(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setY(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setWidth(*reinterpret_cast<int*>(_v)); break;
        case 6: _t->setHeight(*reinterpret_cast<int*>(_v)); break;
        case 7: _t->setMinimumWidth(*reinterpret_cast<int*>(_v)); break;
        case 8: _t->setMinimumHeight(*reinterpret_cast<int*>(_v)); break;
        case 9: _t->setMaximumWidth(*reinterpret_cast<int*>(_v)); break;
        case 10: _t->setMaximumHeight(*reinterpret_cast<int*>(_v)); break;
        case 11: _t->setVisible(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setVisibility(*reinterpret_cast<Visibility*>(_v)); break;
        case 14: _t->reportContentOrientationChange(*reinterpret_cast<Qt::ScreenOrientation*>(_v)); break;
        case 15: _t->setOpacity(*reinterpret_cast<qreal*>(_v)); break;
        case 16: _t->QWindow::d_func()->setTransientParent(*reinterpret_cast<QWindow**>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QWindowE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QSurface"))
        return static_cast< QSurface*>(this);
    return QObject::qt_metacast(_clname);
}

int QWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void QWindow::screenChanged(QScreen * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QWindow::modalityChanged(Qt::WindowModality _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QWindow::windowStateChanged(Qt::WindowState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QWindow::windowTitleChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QWindow::xChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QWindow::yChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QWindow::widthChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QWindow::heightChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QWindow::minimumWidthChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void QWindow::minimumHeightChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void QWindow::maximumWidthChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void QWindow::maximumHeightChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void QWindow::safeAreaMarginsChanged(QMargins _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void QWindow::visibleChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void QWindow::visibilityChanged(QWindow::Visibility _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void QWindow::activeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void QWindow::contentOrientationChanged(Qt::ScreenOrientation _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}

// SIGNAL 17
void QWindow::focusObjectChanged(QObject * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void QWindow::opacityChanged(qreal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void QWindow::transientParentChanged(QWindow * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1);
}
QT_WARNING_POP
