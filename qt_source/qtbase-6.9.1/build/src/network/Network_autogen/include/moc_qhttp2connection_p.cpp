/****************************************************************************
** Meta object code from reading C++ file 'qhttp2connection_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qhttp2connection_p.h"
#include <QtNetwork/QSslError>
#include <QtNetwork/QNetworkProxy>
#include <QtNetwork/QAuthenticator>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttp2connection_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QHttp2StreamE_t {};
} // unnamed namespace

template <> constexpr inline auto QHttp2Stream::qt_create_metaobjectdata<qt_meta_tag_ZN12QHttp2StreamE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QHttp2Stream",
        "headersReceived",
        "",
        "HPack::HttpHeader",
        "headers",
        "endStream",
        "headersUpdated",
        "errorOccurred",
        "Http2::Http2Error",
        "errorCode",
        "errorString",
        "stateChanged",
        "QHttp2Stream::State",
        "newState",
        "promisedStreamReceived",
        "newStreamID",
        "uploadBlocked",
        "dataReceived",
        "data",
        "rstFrameReceived",
        "bytesWritten",
        "uploadDeviceError",
        "uploadFinished",
        "sendRST_STREAM",
        "sendHEADERS",
        "priority",
        "sendDATA",
        "payload",
        "QIODevice*",
        "device",
        "QNonContiguousByteDevice*",
        "sendWINDOW_UPDATE",
        "delta",
        "maybeResumeUpload",
        "uploadDeviceReadChannelFinished",
        "uploadDeviceDestroyed",
        "State",
        "Idle",
        "ReservedRemote",
        "Open",
        "HalfClosedLocal",
        "HalfClosedRemote",
        "Closed"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'headersReceived'
        QtMocHelpers::SignalData<void(const HPack::HttpHeader &, bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 5 },
        }}),
        // Signal 'headersUpdated'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(Http2::Http2Error, const QString &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 }, { QMetaType::QString, 10 },
        }}),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(QHttp2Stream::State)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Signal 'promisedStreamReceived'
        QtMocHelpers::SignalData<void(quint32)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 15 },
        }}),
        // Signal 'uploadBlocked'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'dataReceived'
        QtMocHelpers::SignalData<void(const QByteArray &, bool)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 18 }, { QMetaType::Bool, 5 },
        }}),
        // Signal 'rstFrameReceived'
        QtMocHelpers::SignalData<void(quint32)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 9 },
        }}),
        // Signal 'bytesWritten'
        QtMocHelpers::SignalData<void(qint64)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 20 },
        }}),
        // Signal 'uploadDeviceError'
        QtMocHelpers::SignalData<void(const QString &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 10 },
        }}),
        // Signal 'uploadFinished'
        QtMocHelpers::SignalData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sendRST_STREAM'
        QtMocHelpers::SlotData<bool(Http2::Http2Error)>(23, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot 'sendHEADERS'
        QtMocHelpers::SlotData<bool(const HPack::HttpHeader &, bool, quint8)>(24, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 5 }, { QMetaType::UChar, 25 },
        }}),
        // Slot 'sendHEADERS'
        QtMocHelpers::SlotData<bool(const HPack::HttpHeader &, bool)>(24, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Bool, 5 },
        }}),
        // Slot 'sendDATA'
        QtMocHelpers::SlotData<bool(const QByteArray &, bool)>(26, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QByteArray, 27 }, { QMetaType::Bool, 5 },
        }}),
        // Slot 'sendDATA'
        QtMocHelpers::SlotData<bool(QIODevice *, bool)>(26, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 28, 29 }, { QMetaType::Bool, 5 },
        }}),
        // Slot 'sendDATA'
        QtMocHelpers::SlotData<bool(QNonContiguousByteDevice *, bool)>(26, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 30, 29 }, { QMetaType::Bool, 5 },
        }}),
        // Slot 'sendWINDOW_UPDATE'
        QtMocHelpers::SlotData<void(quint32)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 32 },
        }}),
        // Slot 'maybeResumeUpload'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'uploadDeviceReadChannelFinished'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'uploadDeviceDestroyed'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'State'
        QtMocHelpers::EnumData<State>(36, 36, QMC::EnumIsScoped).add({
            {   37, State::Idle },
            {   38, State::ReservedRemote },
            {   39, State::Open },
            {   40, State::HalfClosedLocal },
            {   41, State::HalfClosedRemote },
            {   42, State::Closed },
        }),
    };
    return QtMocHelpers::metaObjectData<QHttp2Stream, qt_meta_tag_ZN12QHttp2StreamE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QHttp2Stream::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QHttp2StreamE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QHttp2StreamE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QHttp2StreamE_t>.metaTypes,
    nullptr
} };

void QHttp2Stream::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QHttp2Stream *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->headersReceived((*reinterpret_cast< std::add_pointer_t<HPack::HttpHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->headersUpdated(); break;
        case 2: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<Http2::Http2Error>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QHttp2Stream::State>>(_a[1]))); break;
        case 4: _t->promisedStreamReceived((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 5: _t->uploadBlocked(); break;
        case 6: _t->dataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 7: _t->rstFrameReceived((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 8: _t->bytesWritten((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 9: _t->uploadDeviceError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->uploadFinished(); break;
        case 11: { bool _r = _t->sendRST_STREAM((*reinterpret_cast< std::add_pointer_t<Http2::Http2Error>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->sendHEADERS((*reinterpret_cast< std::add_pointer_t<HPack::HttpHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<quint8>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->sendHEADERS((*reinterpret_cast< std::add_pointer_t<HPack::HttpHeader>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->sendDATA((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->sendDATA((*reinterpret_cast< std::add_pointer_t<QIODevice*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->sendDATA((*reinterpret_cast< std::add_pointer_t<QNonContiguousByteDevice*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->sendWINDOW_UPDATE((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 18: _t->maybeResumeUpload(); break;
        case 19: _t->uploadDeviceReadChannelFinished(); break;
        case 20: _t->uploadDeviceDestroyed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QIODevice* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)(const HPack::HttpHeader & , bool )>(_a, &QHttp2Stream::headersReceived, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)()>(_a, &QHttp2Stream::headersUpdated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)(Http2::Http2Error , const QString & )>(_a, &QHttp2Stream::errorOccurred, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)(QHttp2Stream::State )>(_a, &QHttp2Stream::stateChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)(quint32 )>(_a, &QHttp2Stream::promisedStreamReceived, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)()>(_a, &QHttp2Stream::uploadBlocked, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)(const QByteArray & , bool )>(_a, &QHttp2Stream::dataReceived, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)(quint32 )>(_a, &QHttp2Stream::rstFrameReceived, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)(qint64 )>(_a, &QHttp2Stream::bytesWritten, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)(const QString & )>(_a, &QHttp2Stream::uploadDeviceError, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Stream::*)()>(_a, &QHttp2Stream::uploadFinished, 10))
            return;
    }
}

const QMetaObject *QHttp2Stream::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttp2Stream::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QHttp2StreamE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QHttp2Stream::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void QHttp2Stream::headersReceived(const HPack::HttpHeader & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QHttp2Stream::headersUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QHttp2Stream::errorOccurred(Http2::Http2Error _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QHttp2Stream::stateChanged(QHttp2Stream::State _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QHttp2Stream::promisedStreamReceived(quint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QHttp2Stream::uploadBlocked()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QHttp2Stream::dataReceived(const QByteArray & _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void QHttp2Stream::rstFrameReceived(quint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QHttp2Stream::bytesWritten(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void QHttp2Stream::uploadDeviceError(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void QHttp2Stream::uploadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
namespace {
struct qt_meta_tag_ZN16QHttp2ConnectionE_t {};
} // unnamed namespace

template <> constexpr inline auto QHttp2Connection::qt_create_metaobjectdata<qt_meta_tag_ZN16QHttp2ConnectionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QHttp2Connection",
        "newIncomingStream",
        "",
        "QHttp2Stream*",
        "stream",
        "newPromisedStream",
        "errorReceived",
        "connectionClosed",
        "settingsFrameReceived",
        "pingFrameReceived",
        "QHttp2Connection::PingState",
        "state",
        "errorOccurred",
        "Http2::Http2Error",
        "errorCode",
        "errorString",
        "receivedGOAWAY",
        "lastStreamID",
        "receivedEND_STREAM",
        "streamID",
        "incomingStreamErrorOccured",
        "CreateStreamError",
        "error",
        "sendPing",
        "QByteArrayView",
        "data",
        "handleReadyRead",
        "handleConnectionClosure",
        "MaxConcurrentStreamsReached",
        "StreamIdsExhausted",
        "ReceivedGOAWAY",
        "UnknownError"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'newIncomingStream'
        QtMocHelpers::SignalData<void(QHttp2Stream *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'newPromisedStream'
        QtMocHelpers::SignalData<void(QHttp2Stream *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'errorReceived'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'connectionClosed'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'settingsFrameReceived'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'pingFrameReceived'
        QtMocHelpers::SignalData<void(QHttp2Connection::PingState)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(Http2::Http2Error, const QString &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 }, { QMetaType::QString, 15 },
        }}),
        // Signal 'receivedGOAWAY'
        QtMocHelpers::SignalData<void(Http2::Http2Error, quint32)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 }, { QMetaType::UInt, 17 },
        }}),
        // Signal 'receivedEND_STREAM'
        QtMocHelpers::SignalData<void(quint32)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 19 },
        }}),
        // Signal 'incomingStreamErrorOccured'
        QtMocHelpers::SignalData<void(CreateStreamError)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Slot 'sendPing'
        QtMocHelpers::SlotData<bool()>(23, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'sendPing'
        QtMocHelpers::SlotData<bool(QByteArrayView)>(23, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 24, 25 },
        }}),
        // Slot 'handleReadyRead'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'handleConnectionClosure'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'CreateStreamError'
        QtMocHelpers::EnumData<CreateStreamError>(21, 21, QMC::EnumIsScoped).add({
            {   28, CreateStreamError::MaxConcurrentStreamsReached },
            {   29, CreateStreamError::StreamIdsExhausted },
            {   30, CreateStreamError::ReceivedGOAWAY },
            {   31, CreateStreamError::UnknownError },
        }),
    };
    return QtMocHelpers::metaObjectData<QHttp2Connection, qt_meta_tag_ZN16QHttp2ConnectionE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QHttp2Connection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QHttp2ConnectionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QHttp2ConnectionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QHttp2ConnectionE_t>.metaTypes,
    nullptr
} };

void QHttp2Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QHttp2Connection *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->newIncomingStream((*reinterpret_cast< std::add_pointer_t<QHttp2Stream*>>(_a[1]))); break;
        case 1: _t->newPromisedStream((*reinterpret_cast< std::add_pointer_t<QHttp2Stream*>>(_a[1]))); break;
        case 2: _t->errorReceived(); break;
        case 3: _t->connectionClosed(); break;
        case 4: _t->settingsFrameReceived(); break;
        case 5: _t->pingFrameReceived((*reinterpret_cast< std::add_pointer_t<QHttp2Connection::PingState>>(_a[1]))); break;
        case 6: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<Http2::Http2Error>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->receivedGOAWAY((*reinterpret_cast< std::add_pointer_t<Http2::Http2Error>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint32>>(_a[2]))); break;
        case 8: _t->receivedEND_STREAM((*reinterpret_cast< std::add_pointer_t<quint32>>(_a[1]))); break;
        case 9: _t->incomingStreamErrorOccured((*reinterpret_cast< std::add_pointer_t<CreateStreamError>>(_a[1]))); break;
        case 10: { bool _r = _t->sendPing();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->sendPing((*reinterpret_cast< std::add_pointer_t<QByteArrayView>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->handleReadyRead(); break;
        case 13: _t->handleConnectionClosure(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QHttp2Stream* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QHttp2Stream* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)(QHttp2Stream * )>(_a, &QHttp2Connection::newIncomingStream, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)(QHttp2Stream * )>(_a, &QHttp2Connection::newPromisedStream, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)()>(_a, &QHttp2Connection::errorReceived, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)()>(_a, &QHttp2Connection::connectionClosed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)()>(_a, &QHttp2Connection::settingsFrameReceived, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)(QHttp2Connection::PingState )>(_a, &QHttp2Connection::pingFrameReceived, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)(Http2::Http2Error , const QString & )>(_a, &QHttp2Connection::errorOccurred, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)(Http2::Http2Error , quint32 )>(_a, &QHttp2Connection::receivedGOAWAY, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)(quint32 )>(_a, &QHttp2Connection::receivedEND_STREAM, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttp2Connection::*)(CreateStreamError )>(_a, &QHttp2Connection::incomingStreamErrorOccured, 9))
            return;
    }
}

const QMetaObject *QHttp2Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttp2Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QHttp2ConnectionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QHttp2Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QHttp2Connection::newIncomingStream(QHttp2Stream * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QHttp2Connection::newPromisedStream(QHttp2Stream * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QHttp2Connection::errorReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QHttp2Connection::connectionClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QHttp2Connection::settingsFrameReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QHttp2Connection::pingFrameReceived(QHttp2Connection::PingState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QHttp2Connection::errorOccurred(Http2::Http2Error _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void QHttp2Connection::receivedGOAWAY(Http2::Http2Error _t1, quint32 _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2);
}

// SIGNAL 8
void QHttp2Connection::receivedEND_STREAM(quint32 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void QHttp2Connection::incomingStreamErrorOccured(CreateStreamError _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}
QT_WARNING_POP
