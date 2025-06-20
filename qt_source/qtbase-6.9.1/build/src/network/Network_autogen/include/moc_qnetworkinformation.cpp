/****************************************************************************
** Meta object code from reading C++ file 'qnetworkinformation.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/kernel/qnetworkinformation.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkinformation.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QNetworkInformationE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkInformation::qt_create_metaobjectdata<qt_meta_tag_ZN19QNetworkInformationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkInformation",
        "RegisterEnumClassesUnscoped",
        "false",
        "reachabilityChanged",
        "",
        "QNetworkInformation::Reachability",
        "newReachability",
        "isBehindCaptivePortalChanged",
        "state",
        "transportMediumChanged",
        "QNetworkInformation::TransportMedium",
        "current",
        "isMeteredChanged",
        "isMetered",
        "reachability",
        "Reachability",
        "isBehindCaptivePortal",
        "transportMedium",
        "TransportMedium",
        "Unknown",
        "Disconnected",
        "Local",
        "Site",
        "Online",
        "Ethernet",
        "Cellular",
        "WiFi",
        "Bluetooth",
        "Features",
        "Feature",
        "CaptivePortal",
        "Metered"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'reachabilityChanged'
        QtMocHelpers::SignalData<void(QNetworkInformation::Reachability)>(3, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Signal 'isBehindCaptivePortalChanged'
        QtMocHelpers::SignalData<void(bool)>(7, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 8 },
        }}),
        // Signal 'transportMediumChanged'
        QtMocHelpers::SignalData<void(QNetworkInformation::TransportMedium)>(9, 4, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Signal 'isMeteredChanged'
        QtMocHelpers::SignalData<void(bool)>(12, 4, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 13 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'reachability'
        QtMocHelpers::PropertyData<Reachability>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'isBehindCaptivePortal'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags, 1),
        // property 'transportMedium'
        QtMocHelpers::PropertyData<TransportMedium>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 2),
        // property 'isMetered'
        QtMocHelpers::PropertyData<bool>(13, QMetaType::Bool, QMC::DefaultPropertyFlags, 3),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Reachability'
        QtMocHelpers::EnumData<Reachability>(15, 15, QMC::EnumIsScoped).add({
            {   19, Reachability::Unknown },
            {   20, Reachability::Disconnected },
            {   21, Reachability::Local },
            {   22, Reachability::Site },
            {   23, Reachability::Online },
        }),
        // enum 'TransportMedium'
        QtMocHelpers::EnumData<TransportMedium>(18, 18, QMC::EnumIsScoped).add({
            {   19, TransportMedium::Unknown },
            {   24, TransportMedium::Ethernet },
            {   25, TransportMedium::Cellular },
            {   26, TransportMedium::WiFi },
            {   27, TransportMedium::Bluetooth },
        }),
        // enum 'Features'
        QtMocHelpers::EnumData<Features>(28, 29, QMC::EnumIsScoped).add({
            {   15, Feature::Reachability },
            {   30, Feature::CaptivePortal },
            {   18, Feature::TransportMedium },
            {   31, Feature::Metered },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<QNetworkInformation, qt_meta_tag_ZN19QNetworkInformationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QNetworkInformation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QNetworkInformationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QNetworkInformationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QNetworkInformationE_t>.metaTypes,
    nullptr
} };

void QNetworkInformation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkInformation *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->reachabilityChanged((*reinterpret_cast< std::add_pointer_t<QNetworkInformation::Reachability>>(_a[1]))); break;
        case 1: _t->isBehindCaptivePortalChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->transportMediumChanged((*reinterpret_cast< std::add_pointer_t<QNetworkInformation::TransportMedium>>(_a[1]))); break;
        case 3: _t->isMeteredChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QNetworkInformation::*)(QNetworkInformation::Reachability )>(_a, &QNetworkInformation::reachabilityChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkInformation::*)(bool )>(_a, &QNetworkInformation::isBehindCaptivePortalChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkInformation::*)(QNetworkInformation::TransportMedium )>(_a, &QNetworkInformation::transportMediumChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkInformation::*)(bool )>(_a, &QNetworkInformation::isMeteredChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Reachability*>(_v) = _t->reachability(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isBehindCaptivePortal(); break;
        case 2: *reinterpret_cast<TransportMedium*>(_v) = _t->transportMedium(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isMetered(); break;
        default: break;
        }
    }
}

const QMetaObject *QNetworkInformation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkInformation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QNetworkInformationE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QNetworkInformation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QNetworkInformation::reachabilityChanged(QNetworkInformation::Reachability _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QNetworkInformation::isBehindCaptivePortalChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QNetworkInformation::transportMediumChanged(QNetworkInformation::TransportMedium _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QNetworkInformation::isMeteredChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
