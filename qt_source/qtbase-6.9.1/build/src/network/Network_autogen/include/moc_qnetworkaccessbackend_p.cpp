/****************************************************************************
** Meta object code from reading C++ file 'qnetworkaccessbackend_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qnetworkaccessbackend_p.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkaccessbackend_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21QNetworkAccessBackendE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkAccessBackend::qt_create_metaobjectdata<qt_meta_tag_ZN21QNetworkAccessBackendE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkAccessBackend",
        "readyRead",
        "",
        "finished",
        "error",
        "QNetworkReply::NetworkError",
        "code",
        "errorString",
        "proxyAuthenticationRequired",
        "QNetworkProxy",
        "proxy",
        "QAuthenticator*",
        "auth",
        "authenticationRequired",
        "metaDataChanged",
        "redirectionRequested",
        "destination",
        "TargetType",
        "Networked",
        "Local",
        "SecurityFeature",
        "None",
        "TLS",
        "IOFeature",
        "ZeroCopy",
        "NeedResetableUpload",
        "SupportsSynchronousMode"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'readyRead'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'finished'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'error'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError, const QString &)>(4, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 5, 6 }, { QMetaType::QString, 7 },
        }}),
        // Slot 'proxyAuthenticationRequired'
        QtMocHelpers::SlotData<void(const QNetworkProxy &, QAuthenticator *)>(8, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'authenticationRequired'
        QtMocHelpers::SlotData<void(QAuthenticator *)>(13, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot 'metaDataChanged'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'redirectionRequested'
        QtMocHelpers::SlotData<void(const QUrl &)>(15, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::QUrl, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'TargetType'
        QtMocHelpers::EnumData<TargetType>(17, 17, QMC::EnumIsScoped).add({
            {   18, TargetType::Networked },
            {   19, TargetType::Local },
        }),
        // enum 'SecurityFeature'
        QtMocHelpers::EnumData<SecurityFeature>(20, 20, QMC::EnumIsScoped).add({
            {   21, SecurityFeature::None },
            {   22, SecurityFeature::TLS },
        }),
        // enum 'IOFeature'
        QtMocHelpers::EnumData<IOFeature>(23, 23, QMC::EnumIsScoped).add({
            {   21, IOFeature::None },
            {   24, IOFeature::ZeroCopy },
            {   25, IOFeature::NeedResetableUpload },
            {   26, IOFeature::SupportsSynchronousMode },
        }),
    };
    return QtMocHelpers::metaObjectData<QNetworkAccessBackend, qt_meta_tag_ZN21QNetworkAccessBackendE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkAccessBackend::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkAccessBackendE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkAccessBackendE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QNetworkAccessBackendE_t>.metaTypes,
    nullptr
} };

void QNetworkAccessBackend::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkAccessBackend *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->readyRead(); break;
        case 1: _t->finished(); break;
        case 2: _t->error((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->proxyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 4: _t->authenticationRequired((*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[1]))); break;
        case 5: _t->metaDataChanged(); break;
        case 6: _t->redirectionRequested((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
}

const QMetaObject *QNetworkAccessBackend::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkAccessBackend::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkAccessBackendE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QNetworkAccessBackend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN28QNetworkAccessBackendFactoryE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkAccessBackendFactory::qt_create_metaobjectdata<qt_meta_tag_ZN28QNetworkAccessBackendFactoryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkAccessBackendFactory"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNetworkAccessBackendFactory, qt_meta_tag_ZN28QNetworkAccessBackendFactoryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkAccessBackendFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QNetworkAccessBackendFactoryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QNetworkAccessBackendFactoryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN28QNetworkAccessBackendFactoryE_t>.metaTypes,
    nullptr
} };

void QNetworkAccessBackendFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkAccessBackendFactory *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QNetworkAccessBackendFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkAccessBackendFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QNetworkAccessBackendFactoryE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QNetworkAccessBackendFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
