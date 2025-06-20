/****************************************************************************
** Meta object code from reading C++ file 'qsslserver.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/ssl/qsslserver.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsslserver.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QSslServerE_t {};
} // unnamed namespace

template <> constexpr inline auto QSslServer::qt_create_metaobjectdata<qt_meta_tag_ZN10QSslServerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSslServer",
        "sslErrors",
        "",
        "QSslSocket*",
        "socket",
        "QList<QSslError>",
        "errors",
        "peerVerifyError",
        "QSslError",
        "error",
        "errorOccurred",
        "QAbstractSocket::SocketError",
        "preSharedKeyAuthenticationRequired",
        "QSslPreSharedKeyAuthenticator*",
        "authenticator",
        "alertSent",
        "QSsl::AlertLevel",
        "level",
        "QSsl::AlertType",
        "type",
        "description",
        "alertReceived",
        "handshakeInterruptedOnError",
        "startedEncryptionHandshake"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sslErrors'
        QtMocHelpers::SignalData<void(QSslSocket *, const QList<QSslError> &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'peerVerifyError'
        QtMocHelpers::SignalData<void(QSslSocket *, const QSslError &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 8, 9 },
        }}),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(QSslSocket *, QAbstractSocket::SocketError)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 11, 9 },
        }}),
        // Signal 'preSharedKeyAuthenticationRequired'
        QtMocHelpers::SignalData<void(QSslSocket *, QSslPreSharedKeyAuthenticator *)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 13, 14 },
        }}),
        // Signal 'alertSent'
        QtMocHelpers::SignalData<void(QSslSocket *, QSsl::AlertLevel, QSsl::AlertType, const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 16, 17 }, { 0x80000000 | 18, 19 }, { QMetaType::QString, 20 },
        }}),
        // Signal 'alertReceived'
        QtMocHelpers::SignalData<void(QSslSocket *, QSsl::AlertLevel, QSsl::AlertType, const QString &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 16, 17 }, { 0x80000000 | 18, 19 }, { QMetaType::QString, 20 },
        }}),
        // Signal 'handshakeInterruptedOnError'
        QtMocHelpers::SignalData<void(QSslSocket *, const QSslError &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 8, 9 },
        }}),
        // Signal 'startedEncryptionHandshake'
        QtMocHelpers::SignalData<void(QSslSocket *)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSslServer, qt_meta_tag_ZN10QSslServerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSslServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpServer::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QSslServerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QSslServerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QSslServerE_t>.metaTypes,
    nullptr
} };

void QSslServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSslServer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sslErrors((*reinterpret_cast< std::add_pointer_t<QSslSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[2]))); break;
        case 1: _t->peerVerifyError((*reinterpret_cast< std::add_pointer_t<QSslSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSslError>>(_a[2]))); break;
        case 2: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QSslSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[2]))); break;
        case 3: _t->preSharedKeyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QSslSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[2]))); break;
        case 4: _t->alertSent((*reinterpret_cast< std::add_pointer_t<QSslSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSsl::AlertLevel>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSsl::AlertType>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 5: _t->alertReceived((*reinterpret_cast< std::add_pointer_t<QSslSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSsl::AlertLevel>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QSsl::AlertType>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 6: _t->handshakeInterruptedOnError((*reinterpret_cast< std::add_pointer_t<QSslSocket*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSslError>>(_a[2]))); break;
        case 7: _t->startedEncryptionHandshake((*reinterpret_cast< std::add_pointer_t<QSslSocket*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslSocket* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslSocket* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslSocket* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslPreSharedKeyAuthenticator* >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslSocket* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslSocket* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslSocket* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslSocket* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslSocket* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QSslServer::*)(QSslSocket * , const QList<QSslError> & )>(_a, &QSslServer::sslErrors, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslServer::*)(QSslSocket * , const QSslError & )>(_a, &QSslServer::peerVerifyError, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslServer::*)(QSslSocket * , QAbstractSocket::SocketError )>(_a, &QSslServer::errorOccurred, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslServer::*)(QSslSocket * , QSslPreSharedKeyAuthenticator * )>(_a, &QSslServer::preSharedKeyAuthenticationRequired, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslServer::*)(QSslSocket * , QSsl::AlertLevel , QSsl::AlertType , const QString & )>(_a, &QSslServer::alertSent, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslServer::*)(QSslSocket * , QSsl::AlertLevel , QSsl::AlertType , const QString & )>(_a, &QSslServer::alertReceived, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslServer::*)(QSslSocket * , const QSslError & )>(_a, &QSslServer::handshakeInterruptedOnError, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslServer::*)(QSslSocket * )>(_a, &QSslServer::startedEncryptionHandshake, 7))
            return;
    }
}

const QMetaObject *QSslServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSslServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QSslServerE_t>.strings))
        return static_cast<void*>(this);
    return QTcpServer::qt_metacast(_clname);
}

int QSslServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QSslServer::sslErrors(QSslSocket * _t1, const QList<QSslError> & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QSslServer::peerVerifyError(QSslSocket * _t1, const QSslError & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QSslServer::errorOccurred(QSslSocket * _t1, QAbstractSocket::SocketError _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QSslServer::preSharedKeyAuthenticationRequired(QSslSocket * _t1, QSslPreSharedKeyAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void QSslServer::alertSent(QSslSocket * _t1, QSsl::AlertLevel _t2, QSsl::AlertType _t3, const QString & _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 5
void QSslServer::alertReceived(QSslSocket * _t1, QSsl::AlertLevel _t2, QSsl::AlertType _t3, const QString & _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 6
void QSslServer::handshakeInterruptedOnError(QSslSocket * _t1, const QSslError & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void QSslServer::startedEncryptionHandshake(QSslSocket * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}
QT_WARNING_POP
