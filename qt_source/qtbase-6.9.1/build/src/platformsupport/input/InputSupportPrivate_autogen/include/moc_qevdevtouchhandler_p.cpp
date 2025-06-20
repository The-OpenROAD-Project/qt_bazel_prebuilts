/****************************************************************************
** Meta object code from reading C++ file 'qevdevtouchhandler_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/platformsupport/input/evdevtouch/qevdevtouchhandler_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qevdevtouchhandler_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN24QEvdevTouchScreenHandlerE_t {};
} // unnamed namespace

template <> constexpr inline auto QEvdevTouchScreenHandler::qt_create_metaobjectdata<qt_meta_tag_ZN24QEvdevTouchScreenHandlerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QEvdevTouchScreenHandler",
        "touchPointsUpdated",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'touchPointsUpdated'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QEvdevTouchScreenHandler, qt_meta_tag_ZN24QEvdevTouchScreenHandlerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QEvdevTouchScreenHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QEvdevTouchScreenHandlerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QEvdevTouchScreenHandlerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24QEvdevTouchScreenHandlerE_t>.metaTypes,
    nullptr
} };

void QEvdevTouchScreenHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QEvdevTouchScreenHandler *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->touchPointsUpdated(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QEvdevTouchScreenHandler::*)()>(_a, &QEvdevTouchScreenHandler::touchPointsUpdated, 0))
            return;
    }
}

const QMetaObject *QEvdevTouchScreenHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEvdevTouchScreenHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QEvdevTouchScreenHandlerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEvdevTouchScreenHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QEvdevTouchScreenHandler::touchPointsUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN30QEvdevTouchScreenHandlerThreadE_t {};
} // unnamed namespace

template <> constexpr inline auto QEvdevTouchScreenHandlerThread::qt_create_metaobjectdata<qt_meta_tag_ZN30QEvdevTouchScreenHandlerThreadE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QEvdevTouchScreenHandlerThread",
        "touchDeviceRegistered",
        "",
        "notifyTouchDeviceRegistered"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'touchDeviceRegistered'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'notifyTouchDeviceRegistered'
        QtMocHelpers::MethodData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QEvdevTouchScreenHandlerThread, qt_meta_tag_ZN30QEvdevTouchScreenHandlerThreadE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QEvdevTouchScreenHandlerThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QDaemonThread::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN30QEvdevTouchScreenHandlerThreadE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN30QEvdevTouchScreenHandlerThreadE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN30QEvdevTouchScreenHandlerThreadE_t>.metaTypes,
    nullptr
} };

void QEvdevTouchScreenHandlerThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QEvdevTouchScreenHandlerThread *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->touchDeviceRegistered(); break;
        case 1: _t->notifyTouchDeviceRegistered(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QEvdevTouchScreenHandlerThread::*)()>(_a, &QEvdevTouchScreenHandlerThread::touchDeviceRegistered, 0))
            return;
    }
}

const QMetaObject *QEvdevTouchScreenHandlerThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEvdevTouchScreenHandlerThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN30QEvdevTouchScreenHandlerThreadE_t>.strings))
        return static_cast<void*>(this);
    return QDaemonThread::qt_metacast(_clname);
}

int QEvdevTouchScreenHandlerThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDaemonThread::qt_metacall(_c, _id, _a);
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
void QEvdevTouchScreenHandlerThread::touchDeviceRegistered()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
