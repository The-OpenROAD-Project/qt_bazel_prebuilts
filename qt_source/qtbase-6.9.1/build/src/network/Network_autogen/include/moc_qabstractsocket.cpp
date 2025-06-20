/****************************************************************************
** Meta object code from reading C++ file 'qabstractsocket.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/socket/qabstractsocket.h"
#include <QtNetwork/qauthenticator.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractsocket.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QAbstractSocketE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractSocket::qt_create_metaobjectdata<qt_meta_tag_ZN15QAbstractSocketE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractSocket",
        "hostFound",
        "",
        "connected",
        "disconnected",
        "stateChanged",
        "QAbstractSocket::SocketState",
        "errorOccurred",
        "QAbstractSocket::SocketError",
        "proxyAuthenticationRequired",
        "QNetworkProxy",
        "proxy",
        "QAuthenticator*",
        "authenticator",
        "_q_connectToNextAddress",
        "_q_startConnecting",
        "QHostInfo",
        "_q_abortConnectionAttempt",
        "_q_testConnection",
        "SocketType",
        "TcpSocket",
        "UdpSocket",
        "SctpSocket",
        "UnknownSocketType",
        "NetworkLayerProtocol",
        "IPv4Protocol",
        "IPv6Protocol",
        "AnyIPProtocol",
        "UnknownNetworkLayerProtocol",
        "SocketError",
        "ConnectionRefusedError",
        "RemoteHostClosedError",
        "HostNotFoundError",
        "SocketAccessError",
        "SocketResourceError",
        "SocketTimeoutError",
        "DatagramTooLargeError",
        "NetworkError",
        "AddressInUseError",
        "SocketAddressNotAvailableError",
        "UnsupportedSocketOperationError",
        "UnfinishedSocketOperationError",
        "ProxyAuthenticationRequiredError",
        "SslHandshakeFailedError",
        "ProxyConnectionRefusedError",
        "ProxyConnectionClosedError",
        "ProxyConnectionTimeoutError",
        "ProxyNotFoundError",
        "ProxyProtocolError",
        "OperationError",
        "SslInternalError",
        "SslInvalidUserDataError",
        "TemporaryError",
        "UnknownSocketError",
        "SocketState",
        "UnconnectedState",
        "HostLookupState",
        "ConnectingState",
        "ConnectedState",
        "BoundState",
        "ListeningState",
        "ClosingState",
        "SocketOption",
        "LowDelayOption",
        "KeepAliveOption",
        "MulticastTtlOption",
        "MulticastLoopbackOption",
        "TypeOfServiceOption",
        "SendBufferSizeSocketOption",
        "ReceiveBufferSizeSocketOption",
        "PathMtuSocketOption"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'hostFound'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'connected'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'disconnected'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(QAbstractSocket::SocketState)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 2 },
        }}),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(QAbstractSocket::SocketError)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 2 },
        }}),
        // Signal 'proxyAuthenticationRequired'
        QtMocHelpers::SignalData<void(const QNetworkProxy &, QAuthenticator *)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 }, { 0x80000000 | 12, 13 },
        }}),
        // Slot '_q_connectToNextAddress'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_startConnecting'
        QtMocHelpers::SlotData<void(const QHostInfo &)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 16, 2 },
        }}),
        // Slot '_q_abortConnectionAttempt'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_testConnection'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SocketType'
        QtMocHelpers::EnumData<SocketType>(19, 19, QMC::EnumFlags{}).add({
            {   20, SocketType::TcpSocket },
            {   21, SocketType::UdpSocket },
            {   22, SocketType::SctpSocket },
            {   23, SocketType::UnknownSocketType },
        }),
        // enum 'NetworkLayerProtocol'
        QtMocHelpers::EnumData<NetworkLayerProtocol>(24, 24, QMC::EnumFlags{}).add({
            {   25, NetworkLayerProtocol::IPv4Protocol },
            {   26, NetworkLayerProtocol::IPv6Protocol },
            {   27, NetworkLayerProtocol::AnyIPProtocol },
            {   28, NetworkLayerProtocol::UnknownNetworkLayerProtocol },
        }),
        // enum 'SocketError'
        QtMocHelpers::EnumData<SocketError>(29, 29, QMC::EnumFlags{}).add({
            {   30, SocketError::ConnectionRefusedError },
            {   31, SocketError::RemoteHostClosedError },
            {   32, SocketError::HostNotFoundError },
            {   33, SocketError::SocketAccessError },
            {   34, SocketError::SocketResourceError },
            {   35, SocketError::SocketTimeoutError },
            {   36, SocketError::DatagramTooLargeError },
            {   37, SocketError::NetworkError },
            {   38, SocketError::AddressInUseError },
            {   39, SocketError::SocketAddressNotAvailableError },
            {   40, SocketError::UnsupportedSocketOperationError },
            {   41, SocketError::UnfinishedSocketOperationError },
            {   42, SocketError::ProxyAuthenticationRequiredError },
            {   43, SocketError::SslHandshakeFailedError },
            {   44, SocketError::ProxyConnectionRefusedError },
            {   45, SocketError::ProxyConnectionClosedError },
            {   46, SocketError::ProxyConnectionTimeoutError },
            {   47, SocketError::ProxyNotFoundError },
            {   48, SocketError::ProxyProtocolError },
            {   49, SocketError::OperationError },
            {   50, SocketError::SslInternalError },
            {   51, SocketError::SslInvalidUserDataError },
            {   52, SocketError::TemporaryError },
            {   53, SocketError::UnknownSocketError },
        }),
        // enum 'SocketState'
        QtMocHelpers::EnumData<SocketState>(54, 54, QMC::EnumFlags{}).add({
            {   55, SocketState::UnconnectedState },
            {   56, SocketState::HostLookupState },
            {   57, SocketState::ConnectingState },
            {   58, SocketState::ConnectedState },
            {   59, SocketState::BoundState },
            {   60, SocketState::ListeningState },
            {   61, SocketState::ClosingState },
        }),
        // enum 'SocketOption'
        QtMocHelpers::EnumData<SocketOption>(62, 62, QMC::EnumFlags{}).add({
            {   63, SocketOption::LowDelayOption },
            {   64, SocketOption::KeepAliveOption },
            {   65, SocketOption::MulticastTtlOption },
            {   66, SocketOption::MulticastLoopbackOption },
            {   67, SocketOption::TypeOfServiceOption },
            {   68, SocketOption::SendBufferSizeSocketOption },
            {   69, SocketOption::ReceiveBufferSizeSocketOption },
            {   70, SocketOption::PathMtuSocketOption },
        }),
    };
    return QtMocHelpers::metaObjectData<QAbstractSocket, qt_meta_tag_ZN15QAbstractSocketE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QIODevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractSocketE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractSocketE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QAbstractSocketE_t>.metaTypes,
    nullptr
} };

void QAbstractSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractSocket *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->hostFound(); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 4: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 5: _t->proxyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 6: _t->d_func()->_q_connectToNextAddress(); break;
        case 7: _t->d_func()->_q_startConnecting((*reinterpret_cast< std::add_pointer_t<QHostInfo>>(_a[1]))); break;
        case 8: _t->d_func()->_q_abortConnectionAttempt(); break;
        case 9: _t->d_func()->_q_testConnection(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractSocket::*)()>(_a, &QAbstractSocket::hostFound, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSocket::*)()>(_a, &QAbstractSocket::connected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSocket::*)()>(_a, &QAbstractSocket::disconnected, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSocket::*)(QAbstractSocket::SocketState )>(_a, &QAbstractSocket::stateChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSocket::*)(QAbstractSocket::SocketError )>(_a, &QAbstractSocket::errorOccurred, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSocket::*)(const QNetworkProxy & , QAuthenticator * )>(_a, &QAbstractSocket::proxyAuthenticationRequired, 5))
            return;
    }
}

const QMetaObject *QAbstractSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractSocketE_t>.strings))
        return static_cast<void*>(this);
    return QIODevice::qt_metacast(_clname);
}

int QAbstractSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QAbstractSocket::hostFound()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QAbstractSocket::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QAbstractSocket::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QAbstractSocket::stateChanged(QAbstractSocket::SocketState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QAbstractSocket::errorOccurred(QAbstractSocket::SocketError _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QAbstractSocket::proxyAuthenticationRequired(const QNetworkProxy & _t1, QAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}
QT_WARNING_POP
