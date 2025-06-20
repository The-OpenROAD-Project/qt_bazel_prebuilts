/****************************************************************************
** Meta object code from reading C++ file 'qpermissions.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/kernel/qpermissions.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpermissions.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QLocationPermissionE_t {};
} // unnamed namespace

template <> constexpr inline auto QLocationPermission::qt_create_metaobjectdata<qt_meta_tag_ZN19QLocationPermissionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QLocationPermission",
        "Accuracy",
        "Approximate",
        "Precise",
        "Availability",
        "WhenInUse",
        "Always"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Accuracy'
        QtMocHelpers::EnumData<Accuracy>(1, 1, QMC::EnumFlags{}).add({
            {    2, Accuracy::Approximate },
            {    3, Accuracy::Precise },
        }),
        // enum 'Availability'
        QtMocHelpers::EnumData<Availability>(4, 4, QMC::EnumFlags{}).add({
            {    5, Availability::WhenInUse },
            {    6, Availability::Always },
        }),
    };
    return QtMocHelpers::metaObjectData<QLocationPermission, qt_meta_tag_ZN19QLocationPermissionE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QLocationPermission::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QLocationPermissionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QLocationPermissionE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QLocationPermissionE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN19QCalendarPermissionE_t {};
} // unnamed namespace

template <> constexpr inline auto QCalendarPermission::qt_create_metaobjectdata<qt_meta_tag_ZN19QCalendarPermissionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCalendarPermission",
        "AccessMode",
        "ReadOnly",
        "ReadWrite"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'AccessMode'
        QtMocHelpers::EnumData<AccessMode>(1, 1, QMC::EnumFlags{}).add({
            {    2, AccessMode::ReadOnly },
            {    3, AccessMode::ReadWrite },
        }),
    };
    return QtMocHelpers::metaObjectData<QCalendarPermission, qt_meta_tag_ZN19QCalendarPermissionE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCalendarPermission::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QCalendarPermissionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QCalendarPermissionE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QCalendarPermissionE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN19QContactsPermissionE_t {};
} // unnamed namespace

template <> constexpr inline auto QContactsPermission::qt_create_metaobjectdata<qt_meta_tag_ZN19QContactsPermissionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QContactsPermission",
        "AccessMode",
        "ReadOnly",
        "ReadWrite"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'AccessMode'
        QtMocHelpers::EnumData<AccessMode>(1, 1, QMC::EnumFlags{}).add({
            {    2, AccessMode::ReadOnly },
            {    3, AccessMode::ReadWrite },
        }),
    };
    return QtMocHelpers::metaObjectData<QContactsPermission, qt_meta_tag_ZN19QContactsPermissionE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QContactsPermission::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QContactsPermissionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QContactsPermissionE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QContactsPermissionE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN20QBluetoothPermissionE_t {};
} // unnamed namespace

template <> constexpr inline auto QBluetoothPermission::qt_create_metaobjectdata<qt_meta_tag_ZN20QBluetoothPermissionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QBluetoothPermission",
        "CommunicationModes",
        "CommunicationMode",
        "Access",
        "Advertise",
        "Default"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'CommunicationModes'
        QtMocHelpers::EnumData<CommunicationModes>(1, 2, QMC::EnumFlags{}).add({
            {    3, CommunicationMode::Access },
            {    4, CommunicationMode::Advertise },
            {    5, CommunicationMode::Default },
        }),
    };
    return QtMocHelpers::metaObjectData<QBluetoothPermission, qt_meta_tag_ZN20QBluetoothPermissionE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QBluetoothPermission::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QBluetoothPermissionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QBluetoothPermissionE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20QBluetoothPermissionE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
