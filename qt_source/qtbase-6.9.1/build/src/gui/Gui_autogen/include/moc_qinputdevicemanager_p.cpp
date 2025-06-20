/****************************************************************************
** Meta object code from reading C++ file 'qinputdevicemanager_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qinputdevicemanager_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qinputdevicemanager_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QInputDeviceManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto QInputDeviceManager::qt_create_metaobjectdata<qt_meta_tag_ZN19QInputDeviceManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QInputDeviceManager",
        "deviceListChanged",
        "",
        "QInputDeviceManager::DeviceType",
        "type",
        "cursorPositionChangeRequested",
        "pos"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'deviceListChanged'
        QtMocHelpers::SignalData<void(QInputDeviceManager::DeviceType)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'cursorPositionChangeRequested'
        QtMocHelpers::SignalData<void(const QPoint &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPoint, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QInputDeviceManager, qt_meta_tag_ZN19QInputDeviceManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QInputDeviceManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QInputDeviceManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QInputDeviceManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QInputDeviceManagerE_t>.metaTypes,
    nullptr
} };

void QInputDeviceManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QInputDeviceManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->deviceListChanged((*reinterpret_cast< std::add_pointer_t<QInputDeviceManager::DeviceType>>(_a[1]))); break;
        case 1: _t->cursorPositionChangeRequested((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QInputDeviceManager::DeviceType >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QInputDeviceManager::*)(QInputDeviceManager::DeviceType )>(_a, &QInputDeviceManager::deviceListChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QInputDeviceManager::*)(const QPoint & )>(_a, &QInputDeviceManager::cursorPositionChangeRequested, 1))
            return;
    }
}

const QMetaObject *QInputDeviceManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QInputDeviceManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QInputDeviceManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QInputDeviceManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QInputDeviceManager::deviceListChanged(QInputDeviceManager::DeviceType _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QInputDeviceManager::cursorPositionChangeRequested(const QPoint & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
