/****************************************************************************
** Meta object code from reading C++ file 'qhttpnetworkreply_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qhttpnetworkreply_p.h"
#include <QtNetwork/QSslError>
#include <QtNetwork/QNetworkProxy>
#include <QtNetwork/QAuthenticator>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpnetworkreply_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QHttpNetworkReplyE_t {};
} // unnamed namespace

template <> constexpr inline auto QHttpNetworkReply::qt_create_metaobjectdata<qt_meta_tag_ZN17QHttpNetworkReplyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QHttpNetworkReply",
        "encrypted",
        "",
        "sslErrors",
        "QList<QSslError>",
        "errors",
        "preSharedKeyAuthenticationRequired",
        "QSslPreSharedKeyAuthenticator*",
        "authenticator",
        "socketStartedConnecting",
        "requestSent",
        "readyRead",
        "finished",
        "finishedWithError",
        "QNetworkReply::NetworkError",
        "errorCode",
        "detail",
        "headerChanged",
        "dataReadProgress",
        "done",
        "total",
        "dataSendProgress",
        "cacheCredentials",
        "QHttpNetworkRequest",
        "request",
        "QAuthenticator*",
        "proxyAuthenticationRequired",
        "QNetworkProxy",
        "proxy",
        "authenticationRequired",
        "redirected",
        "url",
        "httpStatus",
        "maxRedirectsRemaining"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'encrypted'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sslErrors'
        QtMocHelpers::SignalData<void(const QList<QSslError> &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'preSharedKeyAuthenticationRequired'
        QtMocHelpers::SignalData<void(QSslPreSharedKeyAuthenticator *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'socketStartedConnecting'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'requestSent'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'readyRead'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finishedWithError'
        QtMocHelpers::SignalData<void(QNetworkReply::NetworkError, const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 15 }, { QMetaType::QString, 16 },
        }}),
        // Signal 'finishedWithError'
        QtMocHelpers::SignalData<void(QNetworkReply::NetworkError)>(13, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
        // Signal 'headerChanged'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'dataReadProgress'
        QtMocHelpers::SignalData<void(qint64, qint64)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 19 }, { QMetaType::LongLong, 20 },
        }}),
        // Signal 'dataSendProgress'
        QtMocHelpers::SignalData<void(qint64, qint64)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 19 }, { QMetaType::LongLong, 20 },
        }}),
        // Signal 'cacheCredentials'
        QtMocHelpers::SignalData<void(const QHttpNetworkRequest &, QAuthenticator *)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 23, 24 }, { 0x80000000 | 25, 8 },
        }}),
        // Signal 'proxyAuthenticationRequired'
        QtMocHelpers::SignalData<void(const QNetworkProxy &, QAuthenticator *)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 27, 28 }, { 0x80000000 | 25, 8 },
        }}),
        // Signal 'authenticationRequired'
        QtMocHelpers::SignalData<void(const QHttpNetworkRequest &, QAuthenticator *)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 23, 24 }, { 0x80000000 | 25, 8 },
        }}),
        // Signal 'redirected'
        QtMocHelpers::SignalData<void(const QUrl &, int, int)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 31 }, { QMetaType::Int, 32 }, { QMetaType::Int, 33 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QHttpNetworkReply, qt_meta_tag_ZN17QHttpNetworkReplyE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QHttpNetworkReply::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QHttpNetworkReplyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QHttpNetworkReplyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QHttpNetworkReplyE_t>.metaTypes,
    nullptr
} };

void QHttpNetworkReply::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QHttpNetworkReply *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->encrypted(); break;
        case 1: _t->sslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1]))); break;
        case 2: _t->preSharedKeyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[1]))); break;
        case 3: _t->socketStartedConnecting(); break;
        case 4: _t->requestSent(); break;
        case 5: _t->readyRead(); break;
        case 6: _t->finished(); break;
        case 7: _t->finishedWithError((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->finishedWithError((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1]))); break;
        case 9: _t->headerChanged(); break;
        case 10: _t->dataReadProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 11: _t->dataSendProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 12: _t->cacheCredentials((*reinterpret_cast< std::add_pointer_t<QHttpNetworkRequest>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 13: _t->proxyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 14: _t->authenticationRequired((*reinterpret_cast< std::add_pointer_t<QHttpNetworkRequest>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 15: _t->redirected((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslPreSharedKeyAuthenticator* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QHttpNetworkRequest >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QHttpNetworkRequest >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)()>(_a, &QHttpNetworkReply::encrypted, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(const QList<QSslError> & )>(_a, &QHttpNetworkReply::sslErrors, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(QSslPreSharedKeyAuthenticator * )>(_a, &QHttpNetworkReply::preSharedKeyAuthenticationRequired, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)()>(_a, &QHttpNetworkReply::socketStartedConnecting, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)()>(_a, &QHttpNetworkReply::requestSent, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)()>(_a, &QHttpNetworkReply::readyRead, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)()>(_a, &QHttpNetworkReply::finished, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(QNetworkReply::NetworkError , const QString & )>(_a, &QHttpNetworkReply::finishedWithError, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)()>(_a, &QHttpNetworkReply::headerChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(qint64 , qint64 )>(_a, &QHttpNetworkReply::dataReadProgress, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(qint64 , qint64 )>(_a, &QHttpNetworkReply::dataSendProgress, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(const QHttpNetworkRequest & , QAuthenticator * )>(_a, &QHttpNetworkReply::cacheCredentials, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(const QNetworkProxy & , QAuthenticator * )>(_a, &QHttpNetworkReply::proxyAuthenticationRequired, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(const QHttpNetworkRequest & , QAuthenticator * )>(_a, &QHttpNetworkReply::authenticationRequired, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpNetworkReply::*)(const QUrl & , int , int )>(_a, &QHttpNetworkReply::redirected, 15))
            return;
    }
}

const QMetaObject *QHttpNetworkReply::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpNetworkReply::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QHttpNetworkReplyE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QHttpNetworkHeader"))
        return static_cast< QHttpNetworkHeader*>(this);
    return QObject::qt_metacast(_clname);
}

int QHttpNetworkReply::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void QHttpNetworkReply::encrypted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QHttpNetworkReply::sslErrors(const QList<QSslError> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QHttpNetworkReply::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QHttpNetworkReply::socketStartedConnecting()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QHttpNetworkReply::requestSent()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QHttpNetworkReply::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QHttpNetworkReply::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QHttpNetworkReply::finishedWithError(QNetworkReply::NetworkError _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2);
}

// SIGNAL 9
void QHttpNetworkReply::headerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void QHttpNetworkReply::dataReadProgress(qint64 _t1, qint64 _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1, _t2);
}

// SIGNAL 11
void QHttpNetworkReply::dataSendProgress(qint64 _t1, qint64 _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1, _t2);
}

// SIGNAL 12
void QHttpNetworkReply::cacheCredentials(const QHttpNetworkRequest & _t1, QAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1, _t2);
}

// SIGNAL 13
void QHttpNetworkReply::proxyAuthenticationRequired(const QNetworkProxy & _t1, QAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1, _t2);
}

// SIGNAL 14
void QHttpNetworkReply::authenticationRequired(const QHttpNetworkRequest & _t1, QAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1, _t2);
}

// SIGNAL 15
void QHttpNetworkReply::redirected(const QUrl & _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
