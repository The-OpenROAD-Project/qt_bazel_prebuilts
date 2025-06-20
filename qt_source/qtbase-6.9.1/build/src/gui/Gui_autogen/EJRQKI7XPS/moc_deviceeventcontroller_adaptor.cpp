/****************************************************************************
** Meta object code from reading C++ file 'deviceeventcontroller_adaptor.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../deviceeventcontroller_adaptor.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deviceeventcontroller_adaptor.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN28DeviceEventControllerAdaptorE_t {};
} // unnamed namespace

template <> constexpr inline auto DeviceEventControllerAdaptor::qt_create_metaobjectdata<qt_meta_tag_ZN28DeviceEventControllerAdaptorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DeviceEventControllerAdaptor",
        "D-Bus Interface",
        "org.a11y.atspi.DeviceEventController",
        "D-Bus Introspection",
        "  <interface name=\"org.a11y.atspi.DeviceEventController\">\n    <"
        "method name=\"NotifyListenersSync\">\n      <arg direction=\"in\" "
        "type=\"(uinnisb)\" name=\"event\"/>\n      <arg direction=\"out\" "
        "type=\"b\"/>\n      <annotation value=\"QSpiDeviceEvent\" name=\"o"
        "rg.qtproject.QtDBus.QtTypeName.In0\"/>\n    </method>\n    <method"
        " name=\"NotifyListenersAsync\">\n      <arg direction=\"in\" type="
        "\"(uinnisb)\" name=\"event\"/>\n      <annotation value=\"QSpiDevi"
        "ceEvent\" name=\"org.qtproject.QtDBus.QtTypeName.In0\"/>\n    </me"
        "thod>\n  </interface>\n",
        "NotifyListenersAsync",
        "",
        "QSpiDeviceEvent",
        "event",
        "NotifyListenersSync"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'NotifyListenersAsync'
        QtMocHelpers::SlotData<void(const QSpiDeviceEvent &)>(5, 6, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Slot 'NotifyListenersSync'
        QtMocHelpers::SlotData<bool(const QSpiDeviceEvent &)>(9, 6, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 7, 8 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
            {    3,    4 },
    });
    return QtMocHelpers::metaObjectData<DeviceEventControllerAdaptor, qt_meta_tag_ZN28DeviceEventControllerAdaptorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject DeviceEventControllerAdaptor::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractAdaptor::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28DeviceEventControllerAdaptorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28DeviceEventControllerAdaptorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN28DeviceEventControllerAdaptorE_t>.metaTypes,
    nullptr
} };

void DeviceEventControllerAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DeviceEventControllerAdaptor *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->NotifyListenersAsync((*reinterpret_cast< std::add_pointer_t<QSpiDeviceEvent>>(_a[1]))); break;
        case 1: { bool _r = _t->NotifyListenersSync((*reinterpret_cast< std::add_pointer_t<QSpiDeviceEvent>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSpiDeviceEvent >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSpiDeviceEvent >(); break;
            }
            break;
        }
    }
}

const QMetaObject *DeviceEventControllerAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceEventControllerAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28DeviceEventControllerAdaptorE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int DeviceEventControllerAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
