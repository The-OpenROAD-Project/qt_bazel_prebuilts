/****************************************************************************
** Meta object code from reading C++ file 'qdbuserror.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/dbus/qdbuserror.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbuserror.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QDBusErrorE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusError::qt_create_metaobjectdata<qt_meta_tag_ZN10QDBusErrorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusError",
        "ErrorType",
        "NoError",
        "Other",
        "Failed",
        "NoMemory",
        "ServiceUnknown",
        "NoReply",
        "BadAddress",
        "NotSupported",
        "LimitsExceeded",
        "AccessDenied",
        "NoServer",
        "Timeout",
        "NoNetwork",
        "AddressInUse",
        "Disconnected",
        "InvalidArgs",
        "UnknownMethod",
        "TimedOut",
        "InvalidSignature",
        "UnknownInterface",
        "UnknownObject",
        "UnknownProperty",
        "PropertyReadOnly",
        "InternalError",
        "InvalidService",
        "InvalidObjectPath",
        "InvalidInterface",
        "InvalidMember",
        "LastErrorType"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ErrorType'
        QtMocHelpers::EnumData<ErrorType>(1, 1, QMC::EnumFlags{}).add({
            {    2, ErrorType::NoError },
            {    3, ErrorType::Other },
            {    4, ErrorType::Failed },
            {    5, ErrorType::NoMemory },
            {    6, ErrorType::ServiceUnknown },
            {    7, ErrorType::NoReply },
            {    8, ErrorType::BadAddress },
            {    9, ErrorType::NotSupported },
            {   10, ErrorType::LimitsExceeded },
            {   11, ErrorType::AccessDenied },
            {   12, ErrorType::NoServer },
            {   13, ErrorType::Timeout },
            {   14, ErrorType::NoNetwork },
            {   15, ErrorType::AddressInUse },
            {   16, ErrorType::Disconnected },
            {   17, ErrorType::InvalidArgs },
            {   18, ErrorType::UnknownMethod },
            {   19, ErrorType::TimedOut },
            {   20, ErrorType::InvalidSignature },
            {   21, ErrorType::UnknownInterface },
            {   22, ErrorType::UnknownObject },
            {   23, ErrorType::UnknownProperty },
            {   24, ErrorType::PropertyReadOnly },
            {   25, ErrorType::InternalError },
            {   26, ErrorType::InvalidService },
            {   27, ErrorType::InvalidObjectPath },
            {   28, ErrorType::InvalidInterface },
            {   29, ErrorType::InvalidMember },
            {   30, ErrorType::LastErrorType },
        }),
    };
    return QtMocHelpers::metaObjectData<QDBusError, qt_meta_tag_ZN10QDBusErrorE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusError::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QDBusErrorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QDBusErrorE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QDBusErrorE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
