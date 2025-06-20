/****************************************************************************
** Meta object code from reading C++ file 'qnetworkinterface.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/kernel/qnetworkinterface.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkinterface.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QNetworkInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkInterface::qt_create_metaobjectdata<qt_meta_tag_ZN17QNetworkInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkInterface",
        "InterfaceFlags",
        "InterfaceFlag",
        "IsUp",
        "IsRunning",
        "CanBroadcast",
        "IsLoopBack",
        "IsPointToPoint",
        "CanMulticast",
        "InterfaceType",
        "Loopback",
        "Virtual",
        "Ethernet",
        "Slip",
        "CanBus",
        "Ppp",
        "Fddi",
        "Wifi",
        "Ieee80211",
        "Phonet",
        "Ieee802154",
        "SixLoWPAN",
        "Ieee80216",
        "Ieee1394",
        "Unknown"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'InterfaceFlags'
        QtMocHelpers::EnumData<InterfaceFlags>(1, 2, QMC::EnumFlags{}).add({
            {    3, InterfaceFlag::IsUp },
            {    4, InterfaceFlag::IsRunning },
            {    5, InterfaceFlag::CanBroadcast },
            {    6, InterfaceFlag::IsLoopBack },
            {    7, InterfaceFlag::IsPointToPoint },
            {    8, InterfaceFlag::CanMulticast },
        }),
        // enum 'InterfaceType'
        QtMocHelpers::EnumData<InterfaceType>(9, 9, QMC::EnumFlags{}).add({
            {   10, InterfaceType::Loopback },
            {   11, InterfaceType::Virtual },
            {   12, InterfaceType::Ethernet },
            {   13, InterfaceType::Slip },
            {   14, InterfaceType::CanBus },
            {   15, InterfaceType::Ppp },
            {   16, InterfaceType::Fddi },
            {   17, InterfaceType::Wifi },
            {   18, InterfaceType::Ieee80211 },
            {   19, InterfaceType::Phonet },
            {   20, InterfaceType::Ieee802154 },
            {   21, InterfaceType::SixLoWPAN },
            {   22, InterfaceType::Ieee80216 },
            {   23, InterfaceType::Ieee1394 },
            {   24, InterfaceType::Unknown },
        }),
    };
    return QtMocHelpers::metaObjectData<QNetworkInterface, qt_meta_tag_ZN17QNetworkInterfaceE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkInterface::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QNetworkInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QNetworkInterfaceE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QNetworkInterfaceE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
