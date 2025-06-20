/****************************************************************************
** Meta object code from reading C++ file 'qevdevmousehandler_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/platformsupport/input/evdevmouse/qevdevmousehandler_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qevdevmousehandler_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QEvdevMouseHandlerE_t {};
} // unnamed namespace

template <> constexpr inline auto QEvdevMouseHandler::qt_create_metaobjectdata<qt_meta_tag_ZN18QEvdevMouseHandlerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QEvdevMouseHandler",
        "handleMouseEvent",
        "",
        "x",
        "y",
        "abs",
        "Qt::MouseButtons",
        "buttons",
        "Qt::MouseButton",
        "button",
        "QEvent::Type",
        "type",
        "handleWheelEvent",
        "delta"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'handleMouseEvent'
        QtMocHelpers::SignalData<void(int, int, bool, Qt::MouseButtons, Qt::MouseButton, QEvent::Type)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Int, 4 }, { QMetaType::Bool, 5 }, { 0x80000000 | 6, 7 },
            { 0x80000000 | 8, 9 }, { 0x80000000 | 10, 11 },
        }}),
        // Signal 'handleWheelEvent'
        QtMocHelpers::SignalData<void(QPoint)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPoint, 13 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QEvdevMouseHandler, qt_meta_tag_ZN18QEvdevMouseHandlerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QEvdevMouseHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QEvdevMouseHandlerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QEvdevMouseHandlerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QEvdevMouseHandlerE_t>.metaTypes,
    nullptr
} };

void QEvdevMouseHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QEvdevMouseHandler *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->handleMouseEvent((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButtons>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<Qt::MouseButton>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QEvent::Type>>(_a[6]))); break;
        case 1: _t->handleWheelEvent((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QEvdevMouseHandler::*)(int , int , bool , Qt::MouseButtons , Qt::MouseButton , QEvent::Type )>(_a, &QEvdevMouseHandler::handleMouseEvent, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QEvdevMouseHandler::*)(QPoint )>(_a, &QEvdevMouseHandler::handleWheelEvent, 1))
            return;
    }
}

const QMetaObject *QEvdevMouseHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEvdevMouseHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QEvdevMouseHandlerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEvdevMouseHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QEvdevMouseHandler::handleMouseEvent(int _t1, int _t2, bool _t3, Qt::MouseButtons _t4, Qt::MouseButton _t5, QEvent::Type _t6)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3, _t4, _t5, _t6);
}

// SIGNAL 1
void QEvdevMouseHandler::handleWheelEvent(QPoint _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
