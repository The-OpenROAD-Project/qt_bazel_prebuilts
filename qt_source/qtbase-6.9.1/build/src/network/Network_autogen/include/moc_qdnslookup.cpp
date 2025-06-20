/****************************************************************************
** Meta object code from reading C++ file 'qdnslookup.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/kernel/qdnslookup.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdnslookup.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN24QDnsTlsAssociationRecordE_t {};
} // unnamed namespace

template <> constexpr inline auto QDnsTlsAssociationRecord::qt_create_metaobjectdata<qt_meta_tag_ZN24QDnsTlsAssociationRecordE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDnsTlsAssociationRecord",
        "RegisterEnumClassesUnscoped",
        "false",
        "CertificateUsage",
        "CertificateAuthorityConstrait",
        "ServiceCertificateConstraint",
        "TrustAnchorAssertion",
        "DomainIssuedCertificate",
        "PrivateUse",
        "PKIX_TA",
        "PKIX_EE",
        "DANE_TA",
        "DANE_EE",
        "PrivCert",
        "Selector",
        "FullCertificate",
        "SubjectPublicKeyInfo",
        "Cert",
        "SPKI",
        "PrivSel",
        "MatchingType",
        "Exact",
        "Sha256",
        "Sha512",
        "PrivMatch"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'CertificateUsage'
        QtMocHelpers::EnumData<CertificateUsage>(3, 3, QMC::EnumIsScoped).add({
            {    4, CertificateUsage::CertificateAuthorityConstrait },
            {    5, CertificateUsage::ServiceCertificateConstraint },
            {    6, CertificateUsage::TrustAnchorAssertion },
            {    7, CertificateUsage::DomainIssuedCertificate },
            {    8, CertificateUsage::PrivateUse },
            {    9, CertificateUsage::PKIX_TA },
            {   10, CertificateUsage::PKIX_EE },
            {   11, CertificateUsage::DANE_TA },
            {   12, CertificateUsage::DANE_EE },
            {   13, CertificateUsage::PrivCert },
        }),
        // enum 'Selector'
        QtMocHelpers::EnumData<Selector>(14, 14, QMC::EnumIsScoped).add({
            {   15, Selector::FullCertificate },
            {   16, Selector::SubjectPublicKeyInfo },
            {    8, Selector::PrivateUse },
            {   17, Selector::Cert },
            {   18, Selector::SPKI },
            {   19, Selector::PrivSel },
        }),
        // enum 'MatchingType'
        QtMocHelpers::EnumData<MatchingType>(20, 20, QMC::EnumIsScoped).add({
            {   21, MatchingType::Exact },
            {   22, MatchingType::Sha256 },
            {   23, MatchingType::Sha512 },
            {    8, MatchingType::PrivateUse },
            {   24, MatchingType::PrivMatch },
        }),
    };
    QtMocHelpers::UintData qt_constructors {};
    QtMocHelpers::ClassInfos qt_classinfo({
            {    1,    2 },
    });
    return QtMocHelpers::metaObjectData<QDnsTlsAssociationRecord, qt_meta_tag_ZN24QDnsTlsAssociationRecordE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums, qt_constructors, qt_classinfo);
}
Q_CONSTINIT const QMetaObject QDnsTlsAssociationRecord::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QDnsTlsAssociationRecordE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QDnsTlsAssociationRecordE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24QDnsTlsAssociationRecordE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN10QDnsLookupE_t {};
} // unnamed namespace

template <> constexpr inline auto QDnsLookup::qt_create_metaobjectdata<qt_meta_tag_ZN10QDnsLookupE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDnsLookup",
        "finished",
        "",
        "nameChanged",
        "name",
        "typeChanged",
        "QDnsLookup::Type",
        "type",
        "nameserverChanged",
        "QHostAddress",
        "nameserver",
        "nameserverPortChanged",
        "port",
        "nameserverProtocolChanged",
        "QDnsLookup::Protocol",
        "protocol",
        "abort",
        "lookup",
        "error",
        "Error",
        "authenticData",
        "errorString",
        "Type",
        "nameserverPort",
        "nameserverProtocol",
        "Protocol",
        "NoError",
        "ResolverError",
        "OperationCancelledError",
        "InvalidRequestError",
        "InvalidReplyError",
        "ServerFailureError",
        "ServerRefusedError",
        "NotFoundError",
        "TimeoutError",
        "A",
        "AAAA",
        "ANY",
        "CNAME",
        "MX",
        "NS",
        "PTR",
        "SRV",
        "TLSA",
        "TXT",
        "Standard",
        "DnsOverTls"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'nameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'typeChanged'
        QtMocHelpers::SignalData<void(QDnsLookup::Type)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'nameserverChanged'
        QtMocHelpers::SignalData<void(const QHostAddress &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Signal 'nameserverPortChanged'
        QtMocHelpers::SignalData<void(quint16)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UShort, 12 },
        }}),
        // Signal 'nameserverProtocolChanged'
        QtMocHelpers::SignalData<void(QDnsLookup::Protocol)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
        // Slot 'abort'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'lookup'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'error'
        QtMocHelpers::PropertyData<Error>(18, 0x80000000 | 19, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'authenticData'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags, 0),
        // property 'errorString'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable, 1),
        // property 'type'
        QtMocHelpers::PropertyData<Type>(7, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 2),
        // property 'nameserver'
        QtMocHelpers::PropertyData<QHostAddress>(10, 0x80000000 | 9, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 3),
        // property 'nameserverPort'
        QtMocHelpers::PropertyData<quint16>(23, QMetaType::UShort, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable, 4),
        // property 'nameserverProtocol'
        QtMocHelpers::PropertyData<Protocol>(24, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 5),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Error'
        QtMocHelpers::EnumData<Error>(19, 19, QMC::EnumFlags{}).add({
            {   26, Error::NoError },
            {   27, Error::ResolverError },
            {   28, Error::OperationCancelledError },
            {   29, Error::InvalidRequestError },
            {   30, Error::InvalidReplyError },
            {   31, Error::ServerFailureError },
            {   32, Error::ServerRefusedError },
            {   33, Error::NotFoundError },
            {   34, Error::TimeoutError },
        }),
        // enum 'Type'
        QtMocHelpers::EnumData<Type>(22, 22, QMC::EnumFlags{}).add({
            {   35, Type::A },
            {   36, Type::AAAA },
            {   37, Type::ANY },
            {   38, Type::CNAME },
            {   39, Type::MX },
            {   40, Type::NS },
            {   41, Type::PTR },
            {   42, Type::SRV },
            {   43, Type::TLSA },
            {   44, Type::TXT },
        }),
        // enum 'Protocol'
        QtMocHelpers::EnumData<Protocol>(25, 25, QMC::EnumFlags{}).add({
            {   45, Protocol::Standard },
            {   46, Protocol::DnsOverTls },
        }),
    };
    return QtMocHelpers::metaObjectData<QDnsLookup, qt_meta_tag_ZN10QDnsLookupE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDnsLookup::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QDnsLookupE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QDnsLookupE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QDnsLookupE_t>.metaTypes,
    nullptr
} };

void QDnsLookup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDnsLookup *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->nameChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->typeChanged((*reinterpret_cast< std::add_pointer_t<QDnsLookup::Type>>(_a[1]))); break;
        case 3: _t->nameserverChanged((*reinterpret_cast< std::add_pointer_t<QHostAddress>>(_a[1]))); break;
        case 4: _t->nameserverPortChanged((*reinterpret_cast< std::add_pointer_t<quint16>>(_a[1]))); break;
        case 5: _t->nameserverProtocolChanged((*reinterpret_cast< std::add_pointer_t<QDnsLookup::Protocol>>(_a[1]))); break;
        case 6: _t->abort(); break;
        case 7: _t->lookup(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDnsLookup::*)()>(_a, &QDnsLookup::finished, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDnsLookup::*)(const QString & )>(_a, &QDnsLookup::nameChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDnsLookup::*)(QDnsLookup::Type )>(_a, &QDnsLookup::typeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDnsLookup::*)(const QHostAddress & )>(_a, &QDnsLookup::nameserverChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDnsLookup::*)(quint16 )>(_a, &QDnsLookup::nameserverPortChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDnsLookup::*)(QDnsLookup::Protocol )>(_a, &QDnsLookup::nameserverProtocolChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Error*>(_v) = _t->error(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isAuthenticData(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->errorString(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 4: *reinterpret_cast<Type*>(_v) = _t->type(); break;
        case 5: *reinterpret_cast<QHostAddress*>(_v) = _t->nameserver(); break;
        case 6: *reinterpret_cast<quint16*>(_v) = _t->nameserverPort(); break;
        case 7: *reinterpret_cast<Protocol*>(_v) = _t->nameserverProtocol(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 3: _t->setName(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setType(*reinterpret_cast<Type*>(_v)); break;
        case 5: _t->setNameserver(*reinterpret_cast<QHostAddress*>(_v)); break;
        case 6: _t->setNameserverPort(*reinterpret_cast<quint16*>(_v)); break;
        case 7: _t->setNameserverProtocol(*reinterpret_cast<Protocol*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableName(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableType(); break;
        case 5: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableNameserver(); break;
        case 6: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableNameserverPort(); break;
        case 7: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableNameserverProtocol(); break;
        default: break;
        }
    }
}

const QMetaObject *QDnsLookup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDnsLookup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QDnsLookupE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QDnsLookup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QDnsLookup::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QDnsLookup::nameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QDnsLookup::typeChanged(QDnsLookup::Type _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QDnsLookup::nameserverChanged(const QHostAddress & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QDnsLookup::nameserverPortChanged(quint16 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QDnsLookup::nameserverProtocolChanged(QDnsLookup::Protocol _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
