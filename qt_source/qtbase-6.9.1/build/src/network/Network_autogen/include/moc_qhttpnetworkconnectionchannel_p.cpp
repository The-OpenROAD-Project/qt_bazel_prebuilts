/****************************************************************************
** Meta object code from reading C++ file 'qhttpnetworkconnectionchannel_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qhttpnetworkconnectionchannel_p.h"
#include <QtNetwork/QSslError>
#include <QtNetwork/QNetworkProxy>
#include <QtNetwork/QAuthenticator>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpnetworkconnectionchannel_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN29QHttpNetworkConnectionChannelE_t {};
} // unnamed namespace

template <> constexpr inline auto QHttpNetworkConnectionChannel::qt_create_metaobjectdata<qt_meta_tag_ZN29QHttpNetworkConnectionChannelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QHttpNetworkConnectionChannel",
        "_q_receiveReply",
        "",
        "_q_bytesWritten",
        "bytes",
        "_q_readyRead",
        "_q_disconnected",
        "_q_connected_abstract_socket",
        "QAbstractSocket*",
        "socket",
        "_q_connected_local_socket",
        "QLocalSocket*",
        "_q_connected",
        "_q_error",
        "QAbstractSocket::SocketError",
        "_q_proxyAuthenticationRequired",
        "QNetworkProxy",
        "proxy",
        "QAuthenticator*",
        "auth",
        "_q_uploadDataReadyRead",
        "_q_encrypted",
        "_q_sslErrors",
        "QList<QSslError>",
        "errors",
        "_q_preSharedKeyAuthenticationRequired",
        "QSslPreSharedKeyAuthenticator*",
        "_q_encryptedBytesWritten"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot '_q_receiveReply'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot '_q_bytesWritten'
        QtMocHelpers::SlotData<void(qint64)>(3, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::LongLong, 4 },
        }}),
        // Slot '_q_readyRead'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot '_q_disconnected'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot '_q_connected_abstract_socket'
        QtMocHelpers::SlotData<void(QAbstractSocket *)>(7, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot '_q_connected_local_socket'
        QtMocHelpers::SlotData<void(QLocalSocket *)>(10, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 11, 9 },
        }}),
        // Slot '_q_connected'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot '_q_error'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(13, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Slot '_q_proxyAuthenticationRequired'
        QtMocHelpers::SlotData<void(const QNetworkProxy &, QAuthenticator *)>(15, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 16, 17 }, { 0x80000000 | 18, 19 },
        }}),
        // Slot '_q_uploadDataReadyRead'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot '_q_encrypted'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot '_q_sslErrors'
        QtMocHelpers::SlotData<void(const QList<QSslError> &)>(22, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 23, 24 },
        }}),
        // Slot '_q_preSharedKeyAuthenticationRequired'
        QtMocHelpers::SlotData<void(QSslPreSharedKeyAuthenticator *)>(25, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 26, 2 },
        }}),
        // Slot '_q_encryptedBytesWritten'
        QtMocHelpers::SlotData<void(qint64)>(27, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::LongLong, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QHttpNetworkConnectionChannel, qt_meta_tag_ZN29QHttpNetworkConnectionChannelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QHttpNetworkConnectionChannel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN29QHttpNetworkConnectionChannelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN29QHttpNetworkConnectionChannelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN29QHttpNetworkConnectionChannelE_t>.metaTypes,
    nullptr
} };

void QHttpNetworkConnectionChannel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QHttpNetworkConnectionChannel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->_q_receiveReply(); break;
        case 1: _t->_q_bytesWritten((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 2: _t->_q_readyRead(); break;
        case 3: _t->_q_disconnected(); break;
        case 4: _t->_q_connected_abstract_socket((*reinterpret_cast< std::add_pointer_t<QAbstractSocket*>>(_a[1]))); break;
        case 5: _t->_q_connected_local_socket((*reinterpret_cast< std::add_pointer_t<QLocalSocket*>>(_a[1]))); break;
        case 6: _t->_q_connected(); break;
        case 7: _t->_q_error((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 8: _t->_q_proxyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 9: _t->_q_uploadDataReadyRead(); break;
        case 10: _t->_q_encrypted(); break;
        case 11: _t->_q_sslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1]))); break;
        case 12: _t->_q_preSharedKeyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[1]))); break;
        case 13: _t->_q_encryptedBytesWritten((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket* >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QLocalSocket* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkProxy >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslPreSharedKeyAuthenticator* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *QHttpNetworkConnectionChannel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpNetworkConnectionChannel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN29QHttpNetworkConnectionChannelE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QHttpNetworkConnectionChannel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
