/****************************************************************************
** Meta object code from reading C++ file 'qnetworkaccessmanager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qnetworkaccessmanager.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkaccessmanager.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21QNetworkAccessManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkAccessManager::qt_create_metaobjectdata<qt_meta_tag_ZN21QNetworkAccessManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkAccessManager",
        "proxyAuthenticationRequired",
        "",
        "QNetworkProxy",
        "proxy",
        "QAuthenticator*",
        "authenticator",
        "authenticationRequired",
        "QNetworkReply*",
        "reply",
        "finished",
        "encrypted",
        "sslErrors",
        "QList<QSslError>",
        "errors",
        "preSharedKeyAuthenticationRequired",
        "QSslPreSharedKeyAuthenticator*",
        "supportedSchemesImplementation",
        "_q_replySslErrors",
        "_q_replyPreSharedKeyAuthenticationRequired"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'proxyAuthenticationRequired'
        QtMocHelpers::SignalData<void(const QNetworkProxy &, QAuthenticator *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'authenticationRequired'
        QtMocHelpers::SignalData<void(QNetworkReply *, QAuthenticator *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'finished'
        QtMocHelpers::SignalData<void(QNetworkReply *)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'encrypted'
        QtMocHelpers::SignalData<void(QNetworkReply *)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'sslErrors'
        QtMocHelpers::SignalData<void(QNetworkReply *, const QList<QSslError> &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 }, { 0x80000000 | 13, 14 },
        }}),
        // Signal 'preSharedKeyAuthenticationRequired'
        QtMocHelpers::SignalData<void(QNetworkReply *, QSslPreSharedKeyAuthenticator *)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 }, { 0x80000000 | 16, 6 },
        }}),
        // Slot 'supportedSchemesImplementation'
        QtMocHelpers::SlotData<QStringList() const>(17, 2, QMC::AccessProtected, QMetaType::QStringList),
        // Slot '_q_replySslErrors'
        QtMocHelpers::SlotData<void(QList<QSslError>)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 13, 2 },
        }}),
        // Slot '_q_replyPreSharedKeyAuthenticationRequired'
        QtMocHelpers::SlotData<void(QSslPreSharedKeyAuthenticator *)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 16, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNetworkAccessManager, qt_meta_tag_ZN21QNetworkAccessManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkAccessManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkAccessManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkAccessManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QNetworkAccessManagerE_t>.metaTypes,
    nullptr
} };

void QNetworkAccessManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkAccessManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->proxyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 1: _t->authenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 2: _t->finished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 3: _t->encrypted((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 4: _t->sslErrors((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[2]))); break;
        case 5: _t->preSharedKeyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[2]))); break;
        case 6: { QStringList _r = _t->supportedSchemesImplementation();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->d_func()->_q_replySslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1]))); break;
        case 8: _t->d_func()->_q_replyPreSharedKeyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslPreSharedKeyAuthenticator* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslPreSharedKeyAuthenticator* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QNetworkAccessManager::*)(const QNetworkProxy & , QAuthenticator * )>(_a, &QNetworkAccessManager::proxyAuthenticationRequired, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkAccessManager::*)(QNetworkReply * , QAuthenticator * )>(_a, &QNetworkAccessManager::authenticationRequired, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkAccessManager::*)(QNetworkReply * )>(_a, &QNetworkAccessManager::finished, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkAccessManager::*)(QNetworkReply * )>(_a, &QNetworkAccessManager::encrypted, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkAccessManager::*)(QNetworkReply * , const QList<QSslError> & )>(_a, &QNetworkAccessManager::sslErrors, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkAccessManager::*)(QNetworkReply * , QSslPreSharedKeyAuthenticator * )>(_a, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, 5))
            return;
    }
}

const QMetaObject *QNetworkAccessManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkAccessManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkAccessManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QNetworkAccessManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QNetworkAccessManager::proxyAuthenticationRequired(const QNetworkProxy & _t1, QAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QNetworkAccessManager::authenticationRequired(QNetworkReply * _t1, QAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QNetworkAccessManager::finished(QNetworkReply * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QNetworkAccessManager::encrypted(QNetworkReply * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QNetworkAccessManager::sslErrors(QNetworkReply * _t1, const QList<QSslError> & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void QNetworkAccessManager::preSharedKeyAuthenticationRequired(QNetworkReply * _t1, QSslPreSharedKeyAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}
QT_WARNING_POP
