/****************************************************************************
** Meta object code from reading C++ file 'qsslsocket.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/ssl/qsslsocket.h"
#include <QtNetwork/qsslpresharedkeyauthenticator.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsslsocket.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QSslSocketE_t {};
} // unnamed namespace

template <> constexpr inline auto QSslSocket::qt_create_metaobjectdata<qt_meta_tag_ZN10QSslSocketE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSslSocket",
        "encrypted",
        "",
        "peerVerifyError",
        "QSslError",
        "error",
        "sslErrors",
        "QList<QSslError>",
        "errors",
        "modeChanged",
        "QSslSocket::SslMode",
        "newMode",
        "encryptedBytesWritten",
        "totalBytes",
        "preSharedKeyAuthenticationRequired",
        "QSslPreSharedKeyAuthenticator*",
        "authenticator",
        "newSessionTicketReceived",
        "alertSent",
        "QSsl::AlertLevel",
        "level",
        "QSsl::AlertType",
        "type",
        "description",
        "alertReceived",
        "handshakeInterruptedOnError",
        "startClientEncryption",
        "startServerEncryption",
        "ignoreSslErrors",
        "_q_connectedSlot",
        "_q_hostFoundSlot",
        "_q_disconnectedSlot",
        "_q_stateChangedSlot",
        "QAbstractSocket::SocketState",
        "_q_errorSlot",
        "QAbstractSocket::SocketError",
        "_q_readyReadSlot",
        "_q_channelReadyReadSlot",
        "_q_bytesWrittenSlot",
        "_q_channelBytesWrittenSlot",
        "_q_readChannelFinishedSlot",
        "_q_flushWriteBuffer",
        "_q_flushReadBuffer",
        "_q_resumeImplementation",
        "SslMode",
        "UnencryptedMode",
        "SslClientMode",
        "SslServerMode",
        "PeerVerifyMode",
        "VerifyNone",
        "QueryPeer",
        "VerifyPeer",
        "AutoVerifyPeer"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'encrypted'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'peerVerifyError'
        QtMocHelpers::SignalData<void(const QSslError &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'sslErrors'
        QtMocHelpers::SignalData<void(const QList<QSslError> &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'modeChanged'
        QtMocHelpers::SignalData<void(QSslSocket::SslMode)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Signal 'encryptedBytesWritten'
        QtMocHelpers::SignalData<void(qint64)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 13 },
        }}),
        // Signal 'preSharedKeyAuthenticationRequired'
        QtMocHelpers::SignalData<void(QSslPreSharedKeyAuthenticator *)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Signal 'newSessionTicketReceived'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'alertSent'
        QtMocHelpers::SignalData<void(QSsl::AlertLevel, QSsl::AlertType, const QString &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 19, 20 }, { 0x80000000 | 21, 22 }, { QMetaType::QString, 23 },
        }}),
        // Signal 'alertReceived'
        QtMocHelpers::SignalData<void(QSsl::AlertLevel, QSsl::AlertType, const QString &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 19, 20 }, { 0x80000000 | 21, 22 }, { QMetaType::QString, 23 },
        }}),
        // Signal 'handshakeInterruptedOnError'
        QtMocHelpers::SignalData<void(const QSslError &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'startClientEncryption'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startServerEncryption'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'ignoreSslErrors'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_connectedSlot'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_hostFoundSlot'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_disconnectedSlot'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_stateChangedSlot'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketState)>(32, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 33, 2 },
        }}),
        // Slot '_q_errorSlot'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(34, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 35, 2 },
        }}),
        // Slot '_q_readyReadSlot'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_channelReadyReadSlot'
        QtMocHelpers::SlotData<void(int)>(37, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot '_q_bytesWrittenSlot'
        QtMocHelpers::SlotData<void(qint64)>(38, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::LongLong, 2 },
        }}),
        // Slot '_q_channelBytesWrittenSlot'
        QtMocHelpers::SlotData<void(int, qint64)>(39, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::LongLong, 2 },
        }}),
        // Slot '_q_readChannelFinishedSlot'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_flushWriteBuffer'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_flushReadBuffer'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_resumeImplementation'
        QtMocHelpers::SlotData<void()>(43, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SslMode'
        QtMocHelpers::EnumData<SslMode>(44, 44, QMC::EnumFlags{}).add({
            {   45, SslMode::UnencryptedMode },
            {   46, SslMode::SslClientMode },
            {   47, SslMode::SslServerMode },
        }),
        // enum 'PeerVerifyMode'
        QtMocHelpers::EnumData<PeerVerifyMode>(48, 48, QMC::EnumFlags{}).add({
            {   49, PeerVerifyMode::VerifyNone },
            {   50, PeerVerifyMode::QueryPeer },
            {   51, PeerVerifyMode::VerifyPeer },
            {   52, PeerVerifyMode::AutoVerifyPeer },
        }),
    };
    return QtMocHelpers::metaObjectData<QSslSocket, qt_meta_tag_ZN10QSslSocketE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSslSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QSslSocketE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QSslSocketE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QSslSocketE_t>.metaTypes,
    nullptr
} };

void QSslSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSslSocket *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->encrypted(); break;
        case 1: _t->peerVerifyError((*reinterpret_cast< std::add_pointer_t<QSslError>>(_a[1]))); break;
        case 2: _t->sslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1]))); break;
        case 3: _t->modeChanged((*reinterpret_cast< std::add_pointer_t<QSslSocket::SslMode>>(_a[1]))); break;
        case 4: _t->encryptedBytesWritten((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 5: _t->preSharedKeyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[1]))); break;
        case 6: _t->newSessionTicketReceived(); break;
        case 7: _t->alertSent((*reinterpret_cast< std::add_pointer_t<QSsl::AlertLevel>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSsl::AlertType>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 8: _t->alertReceived((*reinterpret_cast< std::add_pointer_t<QSsl::AlertLevel>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSsl::AlertType>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 9: _t->handshakeInterruptedOnError((*reinterpret_cast< std::add_pointer_t<QSslError>>(_a[1]))); break;
        case 10: _t->startClientEncryption(); break;
        case 11: _t->startServerEncryption(); break;
        case 12: _t->ignoreSslErrors(); break;
        case 13: _t->d_func()->_q_connectedSlot(); break;
        case 14: _t->d_func()->_q_hostFoundSlot(); break;
        case 15: _t->d_func()->_q_disconnectedSlot(); break;
        case 16: _t->d_func()->_q_stateChangedSlot((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 17: _t->d_func()->_q_errorSlot((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 18: _t->d_func()->_q_readyReadSlot(); break;
        case 19: _t->d_func()->_q_channelReadyReadSlot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->d_func()->_q_bytesWrittenSlot((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 21: _t->d_func()->_q_channelBytesWrittenSlot((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 22: _t->d_func()->_q_readChannelFinishedSlot(); break;
        case 23: _t->d_func()->_q_flushWriteBuffer(); break;
        case 24: _t->d_func()->_q_flushReadBuffer(); break;
        case 25: _t->d_func()->_q_resumeImplementation(); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)()>(_a, &QSslSocket::encrypted, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)(const QSslError & )>(_a, &QSslSocket::peerVerifyError, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)(const QList<QSslError> & )>(_a, &QSslSocket::sslErrors, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)(QSslSocket::SslMode )>(_a, &QSslSocket::modeChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)(qint64 )>(_a, &QSslSocket::encryptedBytesWritten, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)(QSslPreSharedKeyAuthenticator * )>(_a, &QSslSocket::preSharedKeyAuthenticationRequired, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)()>(_a, &QSslSocket::newSessionTicketReceived, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)(QSsl::AlertLevel , QSsl::AlertType , const QString & )>(_a, &QSslSocket::alertSent, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)(QSsl::AlertLevel , QSsl::AlertType , const QString & )>(_a, &QSslSocket::alertReceived, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSslSocket::*)(const QSslError & )>(_a, &QSslSocket::handshakeInterruptedOnError, 9))
            return;
    }
}

const QMetaObject *QSslSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSslSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QSslSocketE_t>.strings))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int QSslSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void QSslSocket::encrypted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QSslSocket::peerVerifyError(const QSslError & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QSslSocket::sslErrors(const QList<QSslError> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QSslSocket::modeChanged(QSslSocket::SslMode _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QSslSocket::encryptedBytesWritten(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QSslSocket::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QSslSocket::newSessionTicketReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QSslSocket::alertSent(QSsl::AlertLevel _t1, QSsl::AlertType _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2, _t3);
}

// SIGNAL 8
void QSslSocket::alertReceived(QSsl::AlertLevel _t1, QSsl::AlertType _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2, _t3);
}

// SIGNAL 9
void QSslSocket::handshakeInterruptedOnError(const QSslError & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}
QT_WARNING_POP
