/****************************************************************************
** Meta object code from reading C++ file 'qhttpthreaddelegate_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/access/qhttpthreaddelegate_p.h"
#include <QtNetwork/QSslError>
#include <QtNetwork/QNetworkProxy>
#include <QtNetwork/QAuthenticator>
#include <QtCore/qmetatype.h>
#include <QtCore/QSharedPointer>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpthreaddelegate_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QHttpThreadDelegateE_t {};
} // unnamed namespace

template <> constexpr inline auto QHttpThreadDelegate::qt_create_metaobjectdata<qt_meta_tag_ZN19QHttpThreadDelegateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QHttpThreadDelegate",
        "authenticationRequired",
        "",
        "QHttpNetworkRequest",
        "request",
        "QAuthenticator*",
        "proxyAuthenticationRequired",
        "QNetworkProxy",
        "encrypted",
        "sslErrors",
        "QList<QSslError>",
        "bool*",
        "QList<QSslError>*",
        "sslConfigurationChanged",
        "QSslConfiguration",
        "preSharedKeyAuthenticationRequired",
        "QSslPreSharedKeyAuthenticator*",
        "socketStartedConnecting",
        "requestSent",
        "downloadMetaData",
        "QHttpHeaders",
        "QSharedPointer<char>",
        "downloadProgress",
        "downloadData",
        "error",
        "QNetworkReply::NetworkError",
        "downloadFinished",
        "redirected",
        "url",
        "httpStatus",
        "maxRedirectsRemainig",
        "startRequest",
        "abortRequest",
        "readBufferSizeChanged",
        "size",
        "readBufferFreed",
        "startRequestSynchronously",
        "readyReadSlot",
        "finishedSlot",
        "finishedWithErrorSlot",
        "errorCode",
        "detail",
        "synchronousFinishedSlot",
        "synchronousFinishedWithErrorSlot",
        "headerChangedSlot",
        "synchronousHeaderChangedSlot",
        "dataReadProgressSlot",
        "done",
        "total",
        "cacheCredentialsSlot",
        "authenticator",
        "encryptedSlot",
        "sslErrorsSlot",
        "errors",
        "preSharedKeyAuthenticationRequiredSlot",
        "synchronousAuthenticationRequiredSlot",
        "synchronousProxyAuthenticationRequiredSlot"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'authenticationRequired'
        QtMocHelpers::SignalData<void(const QHttpNetworkRequest &, QAuthenticator *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 2 },
        }}),
        // Signal 'proxyAuthenticationRequired'
        QtMocHelpers::SignalData<void(const QNetworkProxy &, QAuthenticator *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 2 }, { 0x80000000 | 5, 2 },
        }}),
        // Signal 'encrypted'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sslErrors'
        QtMocHelpers::SignalData<void(const QList<QSslError> &, bool *, QList<QSslError> *)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 2 }, { 0x80000000 | 11, 2 }, { 0x80000000 | 12, 2 },
        }}),
        // Signal 'sslConfigurationChanged'
        QtMocHelpers::SignalData<void(const QSslConfiguration &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 2 },
        }}),
        // Signal 'preSharedKeyAuthenticationRequired'
        QtMocHelpers::SignalData<void(QSslPreSharedKeyAuthenticator *)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 2 },
        }}),
        // Signal 'socketStartedConnecting'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'requestSent'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'downloadMetaData'
        QtMocHelpers::SignalData<void(const QHttpHeaders &, int, const QString &, bool, QSharedPointer<char>, qint64, qint64, bool, bool)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 2 }, { QMetaType::Int, 2 }, { QMetaType::QString, 2 }, { QMetaType::Bool, 2 },
            { 0x80000000 | 21, 2 }, { QMetaType::LongLong, 2 }, { QMetaType::LongLong, 2 }, { QMetaType::Bool, 2 },
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'downloadProgress'
        QtMocHelpers::SignalData<void(qint64, qint64)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 2 }, { QMetaType::LongLong, 2 },
        }}),
        // Signal 'downloadData'
        QtMocHelpers::SignalData<void(const QByteArray &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 2 },
        }}),
        // Signal 'error'
        QtMocHelpers::SignalData<void(QNetworkReply::NetworkError, const QString &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 25, 2 }, { QMetaType::QString, 2 },
        }}),
        // Signal 'downloadFinished'
        QtMocHelpers::SignalData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'redirected'
        QtMocHelpers::SignalData<void(const QUrl &, int, int)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 28 }, { QMetaType::Int, 29 }, { QMetaType::Int, 30 },
        }}),
        // Slot 'startRequest'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'abortRequest'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'readBufferSizeChanged'
        QtMocHelpers::SlotData<void(qint64)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 34 },
        }}),
        // Slot 'readBufferFreed'
        QtMocHelpers::SlotData<void(qint64)>(35, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 34 },
        }}),
        // Slot 'startRequestSynchronously'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'readyReadSlot'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'finishedSlot'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'finishedWithErrorSlot'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError, const QString &)>(39, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 25, 40 }, { QMetaType::QString, 41 },
        }}),
        // Slot 'finishedWithErrorSlot'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError)>(39, 2, QMC::AccessProtected | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 25, 40 },
        }}),
        // Slot 'synchronousFinishedSlot'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'synchronousFinishedWithErrorSlot'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError, const QString &)>(43, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 25, 40 }, { QMetaType::QString, 41 },
        }}),
        // Slot 'synchronousFinishedWithErrorSlot'
        QtMocHelpers::SlotData<void(QNetworkReply::NetworkError)>(43, 2, QMC::AccessProtected | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 25, 40 },
        }}),
        // Slot 'headerChangedSlot'
        QtMocHelpers::SlotData<void()>(44, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'synchronousHeaderChangedSlot'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'dataReadProgressSlot'
        QtMocHelpers::SlotData<void(qint64, qint64)>(46, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::LongLong, 47 }, { QMetaType::LongLong, 48 },
        }}),
        // Slot 'cacheCredentialsSlot'
        QtMocHelpers::SlotData<void(const QHttpNetworkRequest &, QAuthenticator *)>(49, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 50 },
        }}),
        // Slot 'encryptedSlot'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'sslErrorsSlot'
        QtMocHelpers::SlotData<void(const QList<QSslError> &)>(52, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 10, 53 },
        }}),
        // Slot 'preSharedKeyAuthenticationRequiredSlot'
        QtMocHelpers::SlotData<void(QSslPreSharedKeyAuthenticator *)>(54, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 16, 50 },
        }}),
        // Slot 'synchronousAuthenticationRequiredSlot'
        QtMocHelpers::SlotData<void(const QHttpNetworkRequest &, QAuthenticator *)>(55, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 2 },
        }}),
        // Slot 'synchronousProxyAuthenticationRequiredSlot'
        QtMocHelpers::SlotData<void(const QNetworkProxy &, QAuthenticator *)>(56, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 7, 2 }, { 0x80000000 | 5, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QHttpThreadDelegate, qt_meta_tag_ZN19QHttpThreadDelegateE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QHttpThreadDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QHttpThreadDelegateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QHttpThreadDelegateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QHttpThreadDelegateE_t>.metaTypes,
    nullptr
} };

void QHttpThreadDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QHttpThreadDelegate *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->authenticationRequired((*reinterpret_cast< std::add_pointer_t<QHttpNetworkRequest>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 1: _t->proxyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 2: _t->encrypted(); break;
        case 3: _t->sslErrors((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<QSslError>*>>(_a[3]))); break;
        case 4: _t->sslConfigurationChanged((*reinterpret_cast< std::add_pointer_t<QSslConfiguration>>(_a[1]))); break;
        case 5: _t->preSharedKeyAuthenticationRequired((*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[1]))); break;
        case 6: _t->socketStartedConnecting(); break;
        case 7: _t->requestSent(); break;
        case 8: _t->downloadMetaData((*reinterpret_cast< std::add_pointer_t<QHttpHeaders>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QSharedPointer<char>>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[9]))); break;
        case 9: _t->downloadProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 10: _t->downloadData((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 11: _t->error((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: _t->downloadFinished(); break;
        case 13: _t->redirected((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 14: _t->startRequest(); break;
        case 15: _t->abortRequest(); break;
        case 16: _t->readBufferSizeChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 17: _t->readBufferFreed((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 18: _t->startRequestSynchronously(); break;
        case 19: _t->readyReadSlot(); break;
        case 20: _t->finishedSlot(); break;
        case 21: _t->finishedWithErrorSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 22: _t->finishedWithErrorSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1]))); break;
        case 23: _t->synchronousFinishedSlot(); break;
        case 24: _t->synchronousFinishedWithErrorSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 25: _t->synchronousFinishedWithErrorSlot((*reinterpret_cast< std::add_pointer_t<QNetworkReply::NetworkError>>(_a[1]))); break;
        case 26: _t->headerChangedSlot(); break;
        case 27: _t->synchronousHeaderChangedSlot(); break;
        case 28: _t->dataReadProgressSlot((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 29: _t->cacheCredentialsSlot((*reinterpret_cast< std::add_pointer_t<QHttpNetworkRequest>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 30: _t->encryptedSlot(); break;
        case 31: _t->sslErrorsSlot((*reinterpret_cast< std::add_pointer_t<QList<QSslError>>>(_a[1]))); break;
        case 32: _t->preSharedKeyAuthenticationRequiredSlot((*reinterpret_cast< std::add_pointer_t<QSslPreSharedKeyAuthenticator*>>(_a[1]))); break;
        case 33: _t->synchronousAuthenticationRequiredSlot((*reinterpret_cast< std::add_pointer_t<QHttpNetworkRequest>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
        case 34: _t->synchronousProxyAuthenticationRequiredSlot((*reinterpret_cast< std::add_pointer_t<QNetworkProxy>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAuthenticator*>>(_a[2]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QHttpNetworkRequest >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkProxy >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslConfiguration >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslPreSharedKeyAuthenticator* >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 25:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 29:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QHttpNetworkRequest >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QSslError> >(); break;
            }
            break;
        case 32:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSslPreSharedKeyAuthenticator* >(); break;
            }
            break;
        case 33:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QHttpNetworkRequest >(); break;
            }
            break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkProxy >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(const QHttpNetworkRequest & , QAuthenticator * )>(_a, &QHttpThreadDelegate::authenticationRequired, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(const QNetworkProxy & , QAuthenticator * )>(_a, &QHttpThreadDelegate::proxyAuthenticationRequired, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)()>(_a, &QHttpThreadDelegate::encrypted, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(const QList<QSslError> & , bool * , QList<QSslError> * )>(_a, &QHttpThreadDelegate::sslErrors, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(const QSslConfiguration & )>(_a, &QHttpThreadDelegate::sslConfigurationChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(QSslPreSharedKeyAuthenticator * )>(_a, &QHttpThreadDelegate::preSharedKeyAuthenticationRequired, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)()>(_a, &QHttpThreadDelegate::socketStartedConnecting, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)()>(_a, &QHttpThreadDelegate::requestSent, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(const QHttpHeaders & , int , const QString & , bool , QSharedPointer<char> , qint64 , qint64 , bool , bool )>(_a, &QHttpThreadDelegate::downloadMetaData, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(qint64 , qint64 )>(_a, &QHttpThreadDelegate::downloadProgress, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(const QByteArray & )>(_a, &QHttpThreadDelegate::downloadData, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(QNetworkReply::NetworkError , const QString & )>(_a, &QHttpThreadDelegate::error, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)()>(_a, &QHttpThreadDelegate::downloadFinished, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (QHttpThreadDelegate::*)(const QUrl & , int , int )>(_a, &QHttpThreadDelegate::redirected, 13))
            return;
    }
}

const QMetaObject *QHttpThreadDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpThreadDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QHttpThreadDelegateE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QHttpThreadDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void QHttpThreadDelegate::authenticationRequired(const QHttpNetworkRequest & _t1, QAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QHttpThreadDelegate::proxyAuthenticationRequired(const QNetworkProxy & _t1, QAuthenticator * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QHttpThreadDelegate::encrypted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QHttpThreadDelegate::sslErrors(const QList<QSslError> & _t1, bool * _t2, QList<QSslError> * _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2, _t3);
}

// SIGNAL 4
void QHttpThreadDelegate::sslConfigurationChanged(const QSslConfiguration & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QHttpThreadDelegate::preSharedKeyAuthenticationRequired(QSslPreSharedKeyAuthenticator * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QHttpThreadDelegate::socketStartedConnecting()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QHttpThreadDelegate::requestSent()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QHttpThreadDelegate::downloadMetaData(const QHttpHeaders & _t1, int _t2, const QString & _t3, bool _t4, QSharedPointer<char> _t5, qint64 _t6, qint64 _t7, bool _t8, bool _t9)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2, _t3, _t4, _t5, _t6, _t7, _t8, _t9);
}

// SIGNAL 9
void QHttpThreadDelegate::downloadProgress(qint64 _t1, qint64 _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2);
}

// SIGNAL 10
void QHttpThreadDelegate::downloadData(const QByteArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void QHttpThreadDelegate::error(QNetworkReply::NetworkError _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1, _t2);
}

// SIGNAL 12
void QHttpThreadDelegate::downloadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void QHttpThreadDelegate::redirected(const QUrl & _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1, _t2, _t3);
}
namespace {
struct qt_meta_tag_ZN41QNonContiguousByteDeviceThreadForwardImplE_t {};
} // unnamed namespace

template <> constexpr inline auto QNonContiguousByteDeviceThreadForwardImpl::qt_create_metaobjectdata<qt_meta_tag_ZN41QNonContiguousByteDeviceThreadForwardImplE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNonContiguousByteDeviceThreadForwardImpl",
        "wantData",
        "",
        "processedData",
        "pos",
        "amount",
        "resetData",
        "bool*",
        "b",
        "haveDataSlot",
        "dataArray",
        "dataAtEnd",
        "dataSize"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'wantData'
        QtMocHelpers::SignalData<void(qint64)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 2 },
        }}),
        // Signal 'processedData'
        QtMocHelpers::SignalData<void(qint64, qint64)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 4 }, { QMetaType::LongLong, 5 },
        }}),
        // Signal 'resetData'
        QtMocHelpers::SignalData<void(bool *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Slot 'haveDataSlot'
        QtMocHelpers::SlotData<void(qint64, const QByteArray &, bool, qint64)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 4 }, { QMetaType::QByteArray, 10 }, { QMetaType::Bool, 11 }, { QMetaType::LongLong, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNonContiguousByteDeviceThreadForwardImpl, qt_meta_tag_ZN41QNonContiguousByteDeviceThreadForwardImplE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNonContiguousByteDeviceThreadForwardImpl::staticMetaObject = { {
    QMetaObject::SuperData::link<QNonContiguousByteDevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN41QNonContiguousByteDeviceThreadForwardImplE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN41QNonContiguousByteDeviceThreadForwardImplE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN41QNonContiguousByteDeviceThreadForwardImplE_t>.metaTypes,
    nullptr
} };

void QNonContiguousByteDeviceThreadForwardImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNonContiguousByteDeviceThreadForwardImpl *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->wantData((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 1: _t->processedData((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 2: _t->resetData((*reinterpret_cast< std::add_pointer_t<bool*>>(_a[1]))); break;
        case 3: _t->haveDataSlot((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[4]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QNonContiguousByteDeviceThreadForwardImpl::*)(qint64 )>(_a, &QNonContiguousByteDeviceThreadForwardImpl::wantData, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNonContiguousByteDeviceThreadForwardImpl::*)(qint64 , qint64 )>(_a, &QNonContiguousByteDeviceThreadForwardImpl::processedData, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNonContiguousByteDeviceThreadForwardImpl::*)(bool * )>(_a, &QNonContiguousByteDeviceThreadForwardImpl::resetData, 2))
            return;
    }
}

const QMetaObject *QNonContiguousByteDeviceThreadForwardImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNonContiguousByteDeviceThreadForwardImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN41QNonContiguousByteDeviceThreadForwardImplE_t>.strings))
        return static_cast<void*>(this);
    return QNonContiguousByteDevice::qt_metacast(_clname);
}

int QNonContiguousByteDeviceThreadForwardImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNonContiguousByteDevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QNonContiguousByteDeviceThreadForwardImpl::wantData(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QNonContiguousByteDeviceThreadForwardImpl::processedData(qint64 _t1, qint64 _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QNonContiguousByteDeviceThreadForwardImpl::resetData(bool * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
