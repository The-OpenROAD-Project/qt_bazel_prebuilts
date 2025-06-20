/****************************************************************************
** Meta object code from reading C++ file 'qtoolbar.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qtoolbar.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtoolbar.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QToolBarE_t {};
} // unnamed namespace

template <> constexpr inline auto QToolBar::qt_create_metaobjectdata<qt_meta_tag_ZN8QToolBarE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QToolBar",
        "actionTriggered",
        "",
        "QAction*",
        "action",
        "movableChanged",
        "movable",
        "allowedAreasChanged",
        "Qt::ToolBarAreas",
        "allowedAreas",
        "orientationChanged",
        "Qt::Orientation",
        "orientation",
        "iconSizeChanged",
        "iconSize",
        "toolButtonStyleChanged",
        "Qt::ToolButtonStyle",
        "toolButtonStyle",
        "topLevelChanged",
        "topLevel",
        "visibilityChanged",
        "visible",
        "setIconSize",
        "setToolButtonStyle",
        "_q_toggleView",
        "_q_updateIconSize",
        "_q_updateToolButtonStyle",
        "floating",
        "floatable"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'actionTriggered'
        QtMocHelpers::SignalData<void(QAction *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'movableChanged'
        QtMocHelpers::SignalData<void(bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 6 },
        }}),
        // Signal 'allowedAreasChanged'
        QtMocHelpers::SignalData<void(Qt::ToolBarAreas)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'orientationChanged'
        QtMocHelpers::SignalData<void(Qt::Orientation)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Signal 'iconSizeChanged'
        QtMocHelpers::SignalData<void(const QSize &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSize, 14 },
        }}),
        // Signal 'toolButtonStyleChanged'
        QtMocHelpers::SignalData<void(Qt::ToolButtonStyle)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 17 },
        }}),
        // Signal 'topLevelChanged'
        QtMocHelpers::SignalData<void(bool)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Signal 'visibilityChanged'
        QtMocHelpers::SignalData<void(bool)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 21 },
        }}),
        // Slot 'setIconSize'
        QtMocHelpers::SlotData<void(const QSize &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSize, 14 },
        }}),
        // Slot 'setToolButtonStyle'
        QtMocHelpers::SlotData<void(Qt::ToolButtonStyle)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 17 },
        }}),
        // Slot '_q_toggleView'
        QtMocHelpers::SlotData<void(bool)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot '_q_updateIconSize'
        QtMocHelpers::SlotData<void(const QSize &)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QSize, 2 },
        }}),
        // Slot '_q_updateToolButtonStyle'
        QtMocHelpers::SlotData<void(Qt::ToolButtonStyle)>(26, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 16, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'movable'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'allowedAreas'
        QtMocHelpers::PropertyData<Qt::ToolBarAreas>(9, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
        // property 'orientation'
        QtMocHelpers::PropertyData<Qt::Orientation>(12, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 3),
        // property 'iconSize'
        QtMocHelpers::PropertyData<QSize>(14, QMetaType::QSize, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'toolButtonStyle'
        QtMocHelpers::PropertyData<Qt::ToolButtonStyle>(17, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 5),
        // property 'floating'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'floatable'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QToolBar, qt_meta_tag_ZN8QToolBarE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QToolBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QToolBarE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QToolBarE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QToolBarE_t>.metaTypes,
    nullptr
} };

void QToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QToolBar *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->actionTriggered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 1: _t->movableChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->allowedAreasChanged((*reinterpret_cast< std::add_pointer_t<Qt::ToolBarAreas>>(_a[1]))); break;
        case 3: _t->orientationChanged((*reinterpret_cast< std::add_pointer_t<Qt::Orientation>>(_a[1]))); break;
        case 4: _t->iconSizeChanged((*reinterpret_cast< std::add_pointer_t<QSize>>(_a[1]))); break;
        case 5: _t->toolButtonStyleChanged((*reinterpret_cast< std::add_pointer_t<Qt::ToolButtonStyle>>(_a[1]))); break;
        case 6: _t->topLevelChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->visibilityChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->setIconSize((*reinterpret_cast< std::add_pointer_t<QSize>>(_a[1]))); break;
        case 9: _t->setToolButtonStyle((*reinterpret_cast< std::add_pointer_t<Qt::ToolButtonStyle>>(_a[1]))); break;
        case 10: _t->d_func()->_q_toggleView((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->d_func()->_q_updateIconSize((*reinterpret_cast< std::add_pointer_t<QSize>>(_a[1]))); break;
        case 12: _t->d_func()->_q_updateToolButtonStyle((*reinterpret_cast< std::add_pointer_t<Qt::ToolButtonStyle>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QToolBar::*)(QAction * )>(_a, &QToolBar::actionTriggered, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QToolBar::*)(bool )>(_a, &QToolBar::movableChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QToolBar::*)(Qt::ToolBarAreas )>(_a, &QToolBar::allowedAreasChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QToolBar::*)(Qt::Orientation )>(_a, &QToolBar::orientationChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QToolBar::*)(const QSize & )>(_a, &QToolBar::iconSizeChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QToolBar::*)(Qt::ToolButtonStyle )>(_a, &QToolBar::toolButtonStyleChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QToolBar::*)(bool )>(_a, &QToolBar::topLevelChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QToolBar::*)(bool )>(_a, &QToolBar::visibilityChanged, 7))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isMovable(); break;
        case 1: *reinterpret_cast<Qt::ToolBarAreas*>(_v) = _t->allowedAreas(); break;
        case 2: *reinterpret_cast<Qt::Orientation*>(_v) = _t->orientation(); break;
        case 3: *reinterpret_cast<QSize*>(_v) = _t->iconSize(); break;
        case 4: *reinterpret_cast<Qt::ToolButtonStyle*>(_v) = _t->toolButtonStyle(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isFloating(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isFloatable(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMovable(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setAllowedAreas(*reinterpret_cast<Qt::ToolBarAreas*>(_v)); break;
        case 2: _t->setOrientation(*reinterpret_cast<Qt::Orientation*>(_v)); break;
        case 3: _t->setIconSize(*reinterpret_cast<QSize*>(_v)); break;
        case 4: _t->setToolButtonStyle(*reinterpret_cast<Qt::ToolButtonStyle*>(_v)); break;
        case 6: _t->setFloatable(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QToolBarE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QToolBar::actionTriggered(QAction * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QToolBar::movableChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QToolBar::allowedAreasChanged(Qt::ToolBarAreas _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QToolBar::orientationChanged(Qt::Orientation _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QToolBar::iconSizeChanged(const QSize & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QToolBar::toolButtonStyleChanged(Qt::ToolButtonStyle _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QToolBar::topLevelChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QToolBar::visibilityChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}
QT_WARNING_POP
