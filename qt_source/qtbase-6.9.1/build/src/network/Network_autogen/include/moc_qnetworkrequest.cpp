/****************************************************************************
** Meta object code from reading C++ file 'qnetworkrequest.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qnetworkrequest.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkrequest.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QNetworkRequestE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkRequest::qt_create_metaobjectdata<qt_meta_tag_ZN15QNetworkRequestE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkRequest",
        "KnownHeaders",
        "ContentTypeHeader",
        "ContentLengthHeader",
        "LocationHeader",
        "LastModifiedHeader",
        "CookieHeader",
        "SetCookieHeader",
        "ContentDispositionHeader",
        "UserAgentHeader",
        "ServerHeader",
        "IfModifiedSinceHeader",
        "ETagHeader",
        "IfMatchHeader",
        "IfNoneMatchHeader",
        "NumKnownHeaders"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'KnownHeaders'
        QtMocHelpers::EnumData<KnownHeaders>(1, 1, QMC::EnumFlags{}).add({
            {    2, KnownHeaders::ContentTypeHeader },
            {    3, KnownHeaders::ContentLengthHeader },
            {    4, KnownHeaders::LocationHeader },
            {    5, KnownHeaders::LastModifiedHeader },
            {    6, KnownHeaders::CookieHeader },
            {    7, KnownHeaders::SetCookieHeader },
            {    8, KnownHeaders::ContentDispositionHeader },
            {    9, KnownHeaders::UserAgentHeader },
            {   10, KnownHeaders::ServerHeader },
            {   11, KnownHeaders::IfModifiedSinceHeader },
            {   12, KnownHeaders::ETagHeader },
            {   13, KnownHeaders::IfMatchHeader },
            {   14, KnownHeaders::IfNoneMatchHeader },
            {   15, KnownHeaders::NumKnownHeaders },
        }),
    };
    return QtMocHelpers::metaObjectData<QNetworkRequest, qt_meta_tag_ZN15QNetworkRequestE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkRequest::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QNetworkRequestE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QNetworkRequestE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QNetworkRequestE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
