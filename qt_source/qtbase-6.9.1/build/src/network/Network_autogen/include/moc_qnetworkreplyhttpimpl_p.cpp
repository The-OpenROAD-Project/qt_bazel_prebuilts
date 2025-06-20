/****************************************************************************
** Meta object code from reading C++ file 'qnetworkreplyhttpimpl_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qnetworkreplyhttpimpl_p.h"
#include <QtNetwork/QSslError>
#include <QtNetwork/QAuthenticator>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnetworkreplyhttpimpl_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21QNetworkReplyHttpImplE_t {};
} // unnamed namespace

template <> constexpr inline auto QNetworkReplyHttpImpl::qt_create_metaobjectdata<qt_meta_tag_ZN21QNetworkReplyHttpImplE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNetworkReplyHttpImpl",
        "startHttpRequest",
        "",
        "abortHttpRequest",
        "readBufferSizeChanged",
        "size",
        "readBufferFreed",
        "startHttpRequestSynchronously",
        "haveUploadData",
        "pos",
        "dataArray",
        "dataAtEnd",
        "dataSize",
        "_q_startOperation",
        "_q_cacheLoadReadyRead",
        "_q_bufferOutgoingData",
        "_q_bufferOutgoingDataFinished",
        "_q_transferTimedOut",
        "_q_finished",
        "_q_error",
        "QNetworkReply::NetworkError",
        "replyDownloadData",
        "replyFinished",
        "replyDownloadProgressSlot",
        "httpAuthenticationRequired",
        "QHttpNetworkRequest",
        "QAuthenticator*",
        "httpError",
        "replyEncrypted",
        "replySslErrors",
        "QList<QSslError>",
        "bool*",
        "QList<QSslError>*",
        "replySslConfigurationChanged",
        "QSslConfiguration",
        "replyPreSharedKeyAuthenticationRequiredSlot",
        "QSslPreSharedKeyAuthenticator*",
        "proxyAuthenticationRequired",
        "QNetworkProxy",
        "proxy",
        "auth",
        "resetUploadDataSlot",
        "r",
        "wantUploadDataSlot",
        "sentUploadDataSlot",
        "uploadByteDeviceReadyReadSlot",
        "emitReplyUploadProgress",
        "_q_cacheSaveDeviceAboutToClose",
        "_q_metaDataChanged",
        "onRedirected",
        "followRedirect"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'startHttpRequest'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'abortHttpRequest'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'readBufferSizeChanged'
        QtMocHelpers::SignalData<void(qint64)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 5 },
        }}),
        // Signal 'readBufferFreed'
        QtMocHelpers::SignalData<void(qint64)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 5 },
        }}),
        // Signal 'startHttpRequestSynchronously'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'haveUploadData'
        QtMocHelpers::SignalData<void(const qint64, const QByteArray &, bool, qint64)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 9 }, { QMetaType::QByteArray, 10 }, { QMetaType::Bool, 11 }, { QMetaType::LongLong, 12 },
        }}),
        // Slot '_q_startOperation'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_cacheLoadReadyRead'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_bufferOutgoingData'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_bufferOutgoingDataFinished'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_transferTimedOut'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_finished'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_error'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError, const QString &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 2 }, { QMetaType::QString, 2 },
        }}),
        // Slot 'replyDownloadData'
        QtMocHelpers::SlotData<void(QByteArray)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 2 },
        }}),
        // Slot 'replyFinished'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'replyDownloadProgressSlot'
        QtMocHelpers::SlotData<void(qint64, qint64)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 2 }, { QMetaType::LongLong, 2 },
        }}),
        // Slot 'httpAuthenticationRequired'
        QtMocHelpers::SlotData<void(const QHttpNetworkRequest &, QAuthenticator *)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 25, 2 }, { 0x80000000 | 26, 2 },
        }}),
        // Slot 'httpError'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError, const QString &)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 2 }, { QMetaType::QString, 2 },
        }}),
        // Slot 'replyEncrypted'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'replySslErrors'
        QtMocHelpers::SlotData<void(const QList<QSslError> &, bool *, QList<QSslError> *)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 30, 2 }, { 0x80000000 | 31, 2 }, { 0x80000000 | 32, 2 },
        }}),
        // Slot 'replySslConfigurationChanged'
        QtMocHelpers::SlotData<void(const QSslConfiguration &)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 34, 2 },
        }}),
        // Slot 'replyPreSharedKeyAuthenticationRequiredSlot'
        QtMocHelpers::SlotData<void(QSslPreSharedKeyAuthenticator *)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 36, 2 },
        }}),
        // Slot 'proxyAuthenticationRequired'
        QtMocHelpers::SlotData<void(const QNetworkProxy &, QAuthenticator *)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 38, 39 }, { 0x80000000 | 26, 40 },
        }}),
        // Slot 'resetUploadDataSlot'
        QtMocHelpers::SlotData<void(bool *)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 31, 42 },
        }}),
        // Slot 'wantUploadDataSlot'
        QtMocHelpers::SlotData<void(qint64)>(43, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 2 },
        }}),
        // Slot 'sentUploadDataSlot'
        QtMocHelpers::SlotData<void(qint64, qint64)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 2 }, { QMetaType::LongLong, 2 },
        }}),
        // Slot 'uploadByteDeviceReadyReadSlot'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'emitReplyUploadProgress'
        QtMocHelpers::SlotData<void(qint64, qint64)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 2 }, { QMetaType::LongLong, 2 },
        }}),
        // Slot '_q_cacheSaveDeviceAboutToClose'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_metaDataChanged'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onRedirected'
        QtMocHelpers::SlotData<void(const QUrl &, int, int)>(49, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 2 }, { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Slot 'followRedirect'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNetworkReplyHttpImpl, qt_meta_tag_ZN21QNetworkReplyHttpImplE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNetworkReplyHttpImpl::staticMetaObject = { {
    QMetaObject::SuperData::link<QNetworkReply::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkReplyHttpImplE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkReplyHttpImplE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QNetworkReplyHttpImplE_t>.metaTypes,
    nullptr
} };

void QNetworkReplyHttpImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNetworkReplyHttpImpl *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->startHttpRequest(); break;
        case 1: _t->abortHttpRequest(); break;
        case 2: _t->readBufferSizeChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 3: _t->readBufferFreed((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 4: _t->startHttpRequestSynchronously(); break;
        case 5: _t->haveUploadData((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[4]))); break;
        case 6: _t->d_func()->_q_startOperation(); break;
        case 7: _t->d_func()->_q_cacheLoadReadyRead(); break;
        case 8: _t->d_func()->_q_bufferOutgoingData(); break;
        case 9: _t->d_func()->_q_bufferOutgoingDataFinished(); break;
        case 10: _t->d_func()->_q_transferTimedOut(); break;
        case 11: _t->d_func()->_q_finished(); break;
        case 12: _t->d_func()->_q_error((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 13: _t->d_func()->replyDownloadData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 14: _t->d_func()->replyFinished(); break;
        case 15: _t->d_func()->replyDownloadProgressSlot((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 16: _t->d_func()->httpAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QHttpNetworkRequest>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 17: _t->d_func()->httpError((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 18: _t->d_func()->replyEncrypted(); break;
        case 19: _t->d_func()->replySslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QSslError>*>>(_a[3]))); break;
        case 20: _t->d_func()->replySslConfigurationChanged((*reinterpret_cast< std::add_pointer_t<QSslConfiguration>>(_a[1]))); break;
        case 21: _t->d_func()->replyPreSharedKeyAuthenticationRequiredSlot((*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[1]))); break;
        case 22: _t->d_func()->proxyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 23: _t->d_func()->resetUploadDataSlot((*reinterpret_cast< std::add_pointer_t<bool*>>(_a[1]))); break;
        case 24: _t->d_func()->wantUploadDataSlot((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 25: _t->d_func()->sentUploadDataSlot((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 26: _t->d_func()->uploadByteDeviceReadyReadSlot(); break;
        case 27: _t->d_func()->emitReplyUploadProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 28: _t->d_func()->_q_cacheSaveDeviceAboutToClose(); break;
        case 29: _t->d_func()->_q_metaDataChanged(); break;
        case 30: _t->d_func()->onRedirected((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 31: _t->d_func()->followRedirect(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 16:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QHttpNetworkRequest >(); break;
            }
            break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 20:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslConfiguration >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslPreSharedKeyAuthenticator* >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkProxy >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QNetworkReplyHttpImpl::*)()>(_a, &QNetworkReplyHttpImpl::startHttpRequest, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkReplyHttpImpl::*)()>(_a, &QNetworkReplyHttpImpl::abortHttpRequest, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkReplyHttpImpl::*)(qint64 )>(_a, &QNetworkReplyHttpImpl::readBufferSizeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkReplyHttpImpl::*)(qint64 )>(_a, &QNetworkReplyHttpImpl::readBufferFreed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkReplyHttpImpl::*)()>(_a, &QNetworkReplyHttpImpl::startHttpRequestSynchronously, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNetworkReplyHttpImpl::*)(const qint64 , const QByteArray & , bool , qint64 )>(_a, &QNetworkReplyHttpImpl::haveUploadData, 5))
            return;
    }
}

const QMetaObject *QNetworkReplyHttpImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNetworkReplyHttpImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QNetworkReplyHttpImplE_t>.strings))
        return static_cast<void*>(this);
    return QNetworkReply::qt_metacast(_clname);
}

int QNetworkReplyHttpImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNetworkReply::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}

// SIGNAL 0
void QNetworkReplyHttpImpl::startHttpRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QNetworkReplyHttpImpl::abortHttpRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QNetworkReplyHttpImpl::readBufferSizeChanged(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QNetworkReplyHttpImpl::readBufferFreed(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QNetworkReplyHttpImpl::startHttpRequestSynchronously()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QNetworkReplyHttpImpl::haveUploadData(const qint64 _t1, const QByteArray & _t2, bool _t3, qint64 _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2, _t3, _t4);
}
QT_WARNING_POP
