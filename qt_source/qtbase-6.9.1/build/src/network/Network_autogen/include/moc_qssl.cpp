/****************************************************************************
** Meta object code from reading C++ file 'qssl.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/ssl/qssl.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qssl.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN4QSslE_t {};
} // unnamed namespace

template <> constexpr inline auto QSsl::qt_create_metaobjectdata<qt_meta_tag_ZN4QSslE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSsl",
        "KeyType",
        "PrivateKey",
        "PublicKey",
        "EncodingFormat",
        "Pem",
        "Der",
        "KeyAlgorithm",
        "Opaque",
        "Rsa",
        "Dsa",
        "Ec",
        "Dh",
        "AlternativeNameEntryType",
        "EmailEntry",
        "DnsEntry",
        "IpAddressEntry",
        "SslProtocol",
        "TlsV1_0",
        "TlsV1_1",
        "TlsV1_2",
        "AnyProtocol",
        "SecureProtocols",
        "TlsV1_0OrLater",
        "TlsV1_1OrLater",
        "TlsV1_2OrLater",
        "DtlsV1_0",
        "DtlsV1_0OrLater",
        "DtlsV1_2",
        "DtlsV1_2OrLater",
        "TlsV1_3",
        "TlsV1_3OrLater",
        "UnknownProtocol",
        "SslOption",
        "SslOptionDisableEmptyFragments",
        "SslOptionDisableSessionTickets",
        "SslOptionDisableCompression",
        "SslOptionDisableServerNameIndication",
        "SslOptionDisableLegacyRenegotiation",
        "SslOptionDisableSessionSharing",
        "SslOptionDisableSessionPersistence",
        "SslOptionDisableServerCipherPreference",
        "AlertLevel",
        "Warning",
        "Fatal",
        "Unknown",
        "AlertType",
        "CloseNotify",
        "UnexpectedMessage",
        "BadRecordMac",
        "RecordOverflow",
        "DecompressionFailure",
        "HandshakeFailure",
        "NoCertificate",
        "BadCertificate",
        "UnsupportedCertificate",
        "CertificateRevoked",
        "CertificateExpired",
        "CertificateUnknown",
        "IllegalParameter",
        "UnknownCa",
        "AccessDenied",
        "DecodeError",
        "DecryptError",
        "ExportRestriction",
        "ProtocolVersion",
        "InsufficientSecurity",
        "InternalError",
        "InappropriateFallback",
        "UserCancelled",
        "NoRenegotiation",
        "MissingExtension",
        "UnsupportedExtension",
        "CertificateUnobtainable",
        "UnrecognizedName",
        "BadCertificateStatusResponse",
        "BadCertificateHashValue",
        "UnknownPskIdentity",
        "CertificateRequired",
        "NoApplicationProtocol",
        "UnknownAlertMessage",
        "ImplementedClass",
        "Key",
        "Certificate",
        "Socket",
        "DiffieHellman",
        "EllipticCurve",
        "Dtls",
        "DtlsCookie",
        "SupportedFeature",
        "CertificateVerification",
        "ClientSideAlpn",
        "ServerSideAlpn",
        "Ocsp",
        "Psk",
        "SessionTicket",
        "Alerts"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'KeyType'
        QtMocHelpers::EnumData<KeyType>(1, 1, QMC::EnumFlags{}).add({
            {    2, KeyType::PrivateKey },
            {    3, KeyType::PublicKey },
        }),
        // enum 'EncodingFormat'
        QtMocHelpers::EnumData<EncodingFormat>(4, 4, QMC::EnumFlags{}).add({
            {    5, EncodingFormat::Pem },
            {    6, EncodingFormat::Der },
        }),
        // enum 'KeyAlgorithm'
        QtMocHelpers::EnumData<KeyAlgorithm>(7, 7, QMC::EnumFlags{}).add({
            {    8, KeyAlgorithm::Opaque },
            {    9, KeyAlgorithm::Rsa },
            {   10, KeyAlgorithm::Dsa },
            {   11, KeyAlgorithm::Ec },
            {   12, KeyAlgorithm::Dh },
        }),
        // enum 'AlternativeNameEntryType'
        QtMocHelpers::EnumData<AlternativeNameEntryType>(13, 13, QMC::EnumFlags{}).add({
            {   14, AlternativeNameEntryType::EmailEntry },
            {   15, AlternativeNameEntryType::DnsEntry },
            {   16, AlternativeNameEntryType::IpAddressEntry },
        }),
        // enum 'SslProtocol'
        QtMocHelpers::EnumData<SslProtocol>(17, 17, QMC::EnumFlags{}).add({
            {   18, SslProtocol::TlsV1_0 },
            {   19, SslProtocol::TlsV1_1 },
            {   20, SslProtocol::TlsV1_2 },
            {   21, SslProtocol::AnyProtocol },
            {   22, SslProtocol::SecureProtocols },
            {   23, SslProtocol::TlsV1_0OrLater },
            {   24, SslProtocol::TlsV1_1OrLater },
            {   25, SslProtocol::TlsV1_2OrLater },
            {   26, SslProtocol::DtlsV1_0 },
            {   27, SslProtocol::DtlsV1_0OrLater },
            {   28, SslProtocol::DtlsV1_2 },
            {   29, SslProtocol::DtlsV1_2OrLater },
            {   30, SslProtocol::TlsV1_3 },
            {   31, SslProtocol::TlsV1_3OrLater },
            {   32, SslProtocol::UnknownProtocol },
        }),
        // enum 'SslOption'
        QtMocHelpers::EnumData<SslOption>(33, 33, QMC::EnumFlags{}).add({
            {   34, SslOption::SslOptionDisableEmptyFragments },
            {   35, SslOption::SslOptionDisableSessionTickets },
            {   36, SslOption::SslOptionDisableCompression },
            {   37, SslOption::SslOptionDisableServerNameIndication },
            {   38, SslOption::SslOptionDisableLegacyRenegotiation },
            {   39, SslOption::SslOptionDisableSessionSharing },
            {   40, SslOption::SslOptionDisableSessionPersistence },
            {   41, SslOption::SslOptionDisableServerCipherPreference },
        }),
        // enum 'AlertLevel'
        QtMocHelpers::EnumData<AlertLevel>(42, 42, QMC::EnumIsScoped).add({
            {   43, AlertLevel::Warning },
            {   44, AlertLevel::Fatal },
            {   45, AlertLevel::Unknown },
        }),
        // enum 'AlertType'
        QtMocHelpers::EnumData<AlertType>(46, 46, QMC::EnumIsScoped).add({
            {   47, AlertType::CloseNotify },
            {   48, AlertType::UnexpectedMessage },
            {   49, AlertType::BadRecordMac },
            {   50, AlertType::RecordOverflow },
            {   51, AlertType::DecompressionFailure },
            {   52, AlertType::HandshakeFailure },
            {   53, AlertType::NoCertificate },
            {   54, AlertType::BadCertificate },
            {   55, AlertType::UnsupportedCertificate },
            {   56, AlertType::CertificateRevoked },
            {   57, AlertType::CertificateExpired },
            {   58, AlertType::CertificateUnknown },
            {   59, AlertType::IllegalParameter },
            {   60, AlertType::UnknownCa },
            {   61, AlertType::AccessDenied },
            {   62, AlertType::DecodeError },
            {   63, AlertType::DecryptError },
            {   64, AlertType::ExportRestriction },
            {   65, AlertType::ProtocolVersion },
            {   66, AlertType::InsufficientSecurity },
            {   67, AlertType::InternalError },
            {   68, AlertType::InappropriateFallback },
            {   69, AlertType::UserCancelled },
            {   70, AlertType::NoRenegotiation },
            {   71, AlertType::MissingExtension },
            {   72, AlertType::UnsupportedExtension },
            {   73, AlertType::CertificateUnobtainable },
            {   74, AlertType::UnrecognizedName },
            {   75, AlertType::BadCertificateStatusResponse },
            {   76, AlertType::BadCertificateHashValue },
            {   77, AlertType::UnknownPskIdentity },
            {   78, AlertType::CertificateRequired },
            {   79, AlertType::NoApplicationProtocol },
            {   80, AlertType::UnknownAlertMessage },
        }),
        // enum 'ImplementedClass'
        QtMocHelpers::EnumData<ImplementedClass>(81, 81, QMC::EnumIsScoped).add({
            {   82, ImplementedClass::Key },
            {   83, ImplementedClass::Certificate },
            {   84, ImplementedClass::Socket },
            {   85, ImplementedClass::DiffieHellman },
            {   86, ImplementedClass::EllipticCurve },
            {   87, ImplementedClass::Dtls },
            {   88, ImplementedClass::DtlsCookie },
        }),
        // enum 'SupportedFeature'
        QtMocHelpers::EnumData<SupportedFeature>(89, 89, QMC::EnumIsScoped).add({
            {   90, SupportedFeature::CertificateVerification },
            {   91, SupportedFeature::ClientSideAlpn },
            {   92, SupportedFeature::ServerSideAlpn },
            {   93, SupportedFeature::Ocsp },
            {   94, SupportedFeature::Psk },
            {   95, SupportedFeature::SessionTicket },
            {   96, SupportedFeature::Alerts },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN4QSslE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN4QSslE =
    QSsl::qt_create_metaobjectdata<qt_meta_tag_ZN4QSslE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN4QSslE =
    qt_staticMetaObjectContent_ZN4QSslE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN4QSslE =
    qt_staticMetaObjectContent_ZN4QSslE.relocatingData;

Q_CONSTINIT const QMetaObject QSsl::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN4QSslE.stringdata,
    qt_staticMetaObjectStaticContent_ZN4QSslE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN4QSslE.metaTypes,
    nullptr
} };

QT_WARNING_POP
