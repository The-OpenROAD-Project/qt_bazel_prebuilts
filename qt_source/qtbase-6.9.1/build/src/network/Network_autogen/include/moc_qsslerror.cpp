/****************************************************************************
** Meta object code from reading C++ file 'qsslerror.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/ssl/qsslerror.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsslerror.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QSslErrorE_t {};
} // unnamed namespace

template <> constexpr inline auto QSslError::qt_create_metaobjectdata<qt_meta_tag_ZN9QSslErrorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSslError",
        "SslError",
        "NoError",
        "UnableToGetIssuerCertificate",
        "UnableToDecryptCertificateSignature",
        "UnableToDecodeIssuerPublicKey",
        "CertificateSignatureFailed",
        "CertificateNotYetValid",
        "CertificateExpired",
        "InvalidNotBeforeField",
        "InvalidNotAfterField",
        "SelfSignedCertificate",
        "SelfSignedCertificateInChain",
        "UnableToGetLocalIssuerCertificate",
        "UnableToVerifyFirstCertificate",
        "CertificateRevoked",
        "InvalidCaCertificate",
        "PathLengthExceeded",
        "InvalidPurpose",
        "CertificateUntrusted",
        "CertificateRejected",
        "SubjectIssuerMismatch",
        "AuthorityIssuerSerialNumberMismatch",
        "NoPeerCertificate",
        "HostNameMismatch",
        "NoSslSupport",
        "CertificateBlacklisted",
        "CertificateStatusUnknown",
        "OcspNoResponseFound",
        "OcspMalformedRequest",
        "OcspMalformedResponse",
        "OcspInternalError",
        "OcspTryLater",
        "OcspSigRequred",
        "OcspUnauthorized",
        "OcspResponseCannotBeTrusted",
        "OcspResponseCertIdUnknown",
        "OcspResponseExpired",
        "OcspStatusUnknown",
        "UnspecifiedError"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SslError'
        QtMocHelpers::EnumData<SslError>(1, 1, QMC::EnumFlags{}).add({
            {    2, SslError::NoError },
            {    3, SslError::UnableToGetIssuerCertificate },
            {    4, SslError::UnableToDecryptCertificateSignature },
            {    5, SslError::UnableToDecodeIssuerPublicKey },
            {    6, SslError::CertificateSignatureFailed },
            {    7, SslError::CertificateNotYetValid },
            {    8, SslError::CertificateExpired },
            {    9, SslError::InvalidNotBeforeField },
            {   10, SslError::InvalidNotAfterField },
            {   11, SslError::SelfSignedCertificate },
            {   12, SslError::SelfSignedCertificateInChain },
            {   13, SslError::UnableToGetLocalIssuerCertificate },
            {   14, SslError::UnableToVerifyFirstCertificate },
            {   15, SslError::CertificateRevoked },
            {   16, SslError::InvalidCaCertificate },
            {   17, SslError::PathLengthExceeded },
            {   18, SslError::InvalidPurpose },
            {   19, SslError::CertificateUntrusted },
            {   20, SslError::CertificateRejected },
            {   21, SslError::SubjectIssuerMismatch },
            {   22, SslError::AuthorityIssuerSerialNumberMismatch },
            {   23, SslError::NoPeerCertificate },
            {   24, SslError::HostNameMismatch },
            {   25, SslError::NoSslSupport },
            {   26, SslError::CertificateBlacklisted },
            {   27, SslError::CertificateStatusUnknown },
            {   28, SslError::OcspNoResponseFound },
            {   29, SslError::OcspMalformedRequest },
            {   30, SslError::OcspMalformedResponse },
            {   31, SslError::OcspInternalError },
            {   32, SslError::OcspTryLater },
            {   33, SslError::OcspSigRequred },
            {   34, SslError::OcspUnauthorized },
            {   35, SslError::OcspResponseCannotBeTrusted },
            {   36, SslError::OcspResponseCertIdUnknown },
            {   37, SslError::OcspResponseExpired },
            {   38, SslError::OcspStatusUnknown },
            {   39, SslError::UnspecifiedError },
        }),
    };
    return QtMocHelpers::metaObjectData<QSslError, qt_meta_tag_ZN9QSslErrorE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSslError::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSslErrorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSslErrorE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QSslErrorE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
