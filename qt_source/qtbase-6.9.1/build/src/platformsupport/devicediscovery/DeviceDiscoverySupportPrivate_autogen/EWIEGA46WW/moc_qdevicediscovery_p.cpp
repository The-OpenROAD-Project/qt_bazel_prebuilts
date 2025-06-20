/****************************************************************************
** Meta object code from reading C++ file 'qdevicediscovery_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/platformsupport/devicediscovery/qdevicediscovery_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdevicediscovery_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QDeviceDiscoveryE_t {};
} // unnamed namespace

template <> constexpr inline auto QDeviceDiscovery::qt_create_metaobjectdata<qt_meta_tag_ZN16QDeviceDiscoveryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDeviceDiscovery",
        "deviceDetected",
        "",
        "deviceNode",
        "deviceRemoved",
        "QDeviceType",
        "Device_Unknown",
        "Device_Mouse",
        "Device_Touchpad",
        "Device_Touchscreen",
        "Device_Keyboard",
        "Device_DRM",
        "Device_DRM_PrimaryGPU",
        "Device_Tablet",
        "Device_Joystick",
        "Device_InputMask",
        "Device_VideoMask"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'deviceDetected'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'deviceRemoved'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'QDeviceType'
        QtMocHelpers::EnumData<QDeviceType>(5, 5, QMC::EnumFlags{}).add({
            {    6, QDeviceType::Device_Unknown },
            {    7, QDeviceType::Device_Mouse },
            {    8, QDeviceType::Device_Touchpad },
            {    9, QDeviceType::Device_Touchscreen },
            {   10, QDeviceType::Device_Keyboard },
            {   11, QDeviceType::Device_DRM },
            {   12, QDeviceType::Device_DRM_PrimaryGPU },
            {   13, QDeviceType::Device_Tablet },
            {   14, QDeviceType::Device_Joystick },
            {   15, QDeviceType::Device_InputMask },
            {   16, QDeviceType::Device_VideoMask },
        }),
    };
    return QtMocHelpers::metaObjectData<QDeviceDiscovery, qt_meta_tag_ZN16QDeviceDiscoveryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDeviceDiscovery::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDeviceDiscoveryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDeviceDiscoveryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QDeviceDiscoveryE_t>.metaTypes,
    nullptr
} };

void QDeviceDiscovery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDeviceDiscovery *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->deviceDetected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->deviceRemoved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDeviceDiscovery::*)(const QString & )>(_a, &QDeviceDiscovery::deviceDetected, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDeviceDiscovery::*)(const QString & )>(_a, &QDeviceDiscovery::deviceRemoved, 1))
            return;
    }
}

const QMetaObject *QDeviceDiscovery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDeviceDiscovery::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDeviceDiscoveryE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QDeviceDiscovery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QDeviceDiscovery::deviceDetected(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QDeviceDiscovery::deviceRemoved(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
