/****************************************************************************
** Meta object code from reading C++ file 'qdbusconnection.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/dbus/qdbusconnection.h"
#include <QtDBus/qdbuspendingcall.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbusconnection.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QDBusConnectionE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusConnection::qt_create_metaobjectdata<qt_meta_tag_ZN15QDBusConnectionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusConnection",
        "BusType",
        "SessionBus",
        "SystemBus",
        "ActivationBus",
        "RegisterOptions",
        "RegisterOption",
        "ExportAdaptors",
        "ExportScriptableSlots",
        "ExportScriptableSignals",
        "ExportScriptableProperties",
        "ExportScriptableInvokables",
        "ExportScriptableContents",
        "ExportNonScriptableSlots",
        "ExportNonScriptableSignals",
        "ExportNonScriptableProperties",
        "ExportNonScriptableInvokables",
        "ExportNonScriptableContents",
        "ExportAllSlots",
        "ExportAllSignals",
        "ExportAllProperties",
        "ExportAllInvokables",
        "ExportAllContents",
        "ExportAllSignal",
        "ExportChildObjects",
        "UnregisterMode",
        "UnregisterNode",
        "UnregisterTree"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'BusType'
        QtMocHelpers::EnumData<BusType>(1, 1, QMC::EnumFlags{}).add({
            {    2, BusType::SessionBus },
            {    3, BusType::SystemBus },
            {    4, BusType::ActivationBus },
        }),
        // enum 'RegisterOptions'
        QtMocHelpers::EnumData<RegisterOptions>(5, 6, QMC::EnumFlags{}).add({
            {    7, RegisterOption::ExportAdaptors },
            {    8, RegisterOption::ExportScriptableSlots },
            {    9, RegisterOption::ExportScriptableSignals },
            {   10, RegisterOption::ExportScriptableProperties },
            {   11, RegisterOption::ExportScriptableInvokables },
            {   12, RegisterOption::ExportScriptableContents },
            {   13, RegisterOption::ExportNonScriptableSlots },
            {   14, RegisterOption::ExportNonScriptableSignals },
            {   15, RegisterOption::ExportNonScriptableProperties },
            {   16, RegisterOption::ExportNonScriptableInvokables },
            {   17, RegisterOption::ExportNonScriptableContents },
            {   18, RegisterOption::ExportAllSlots },
            {   19, RegisterOption::ExportAllSignals },
            {   20, RegisterOption::ExportAllProperties },
            {   21, RegisterOption::ExportAllInvokables },
            {   22, RegisterOption::ExportAllContents },
            {   23, RegisterOption::ExportAllSignal },
            {   24, RegisterOption::ExportChildObjects },
        }),
        // enum 'UnregisterMode'
        QtMocHelpers::EnumData<UnregisterMode>(25, 25, QMC::EnumFlags{}).add({
            {   26, UnregisterMode::UnregisterNode },
            {   27, UnregisterMode::UnregisterTree },
        }),
    };
    return QtMocHelpers::metaObjectData<QDBusConnection, qt_meta_tag_ZN15QDBusConnectionE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusConnection::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QDBusConnectionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QDBusConnectionE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QDBusConnectionE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
