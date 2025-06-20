/****************************************************************************
** Meta object code from reading C++ file 'qdevicediscovery_udev_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/platformsupport/devicediscovery/qdevicediscovery_udev_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdevicediscovery_udev_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20QDeviceDiscoveryUDevE_t {};
} // unnamed namespace

template <> constexpr inline auto QDeviceDiscoveryUDev::qt_create_metaobjectdata<qt_meta_tag_ZN20QDeviceDiscoveryUDevE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDeviceDiscoveryUDev",
        "handleUDevNotification",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'handleUDevNotification'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDeviceDiscoveryUDev, qt_meta_tag_ZN20QDeviceDiscoveryUDevE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDeviceDiscoveryUDev::staticMetaObject = { {
    QMetaObject::SuperData::link<QDeviceDiscovery::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QDeviceDiscoveryUDevE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QDeviceDiscoveryUDevE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20QDeviceDiscoveryUDevE_t>.metaTypes,
    nullptr
} };

void QDeviceDiscoveryUDev::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDeviceDiscoveryUDev *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->handleUDevNotification(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QDeviceDiscoveryUDev::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDeviceDiscoveryUDev::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QDeviceDiscoveryUDevE_t>.strings))
        return static_cast<void*>(this);
    return QDeviceDiscovery::qt_metacast(_clname);
}

int QDeviceDiscoveryUDev::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDeviceDiscovery::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
