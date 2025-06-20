/****************************************************************************
** Meta object code from reading C++ file 'qsocks5socketengine_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/socket/qsocks5socketengine_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsocks5socketengine_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QSocks5SocketEngineE_t {};
} // unnamed namespace

template <> constexpr inline auto QSocks5SocketEngine::qt_create_metaobjectdata<qt_meta_tag_ZN19QSocks5SocketEngineE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSocks5SocketEngine",
        "_q_controlSocketConnected",
        "",
        "_q_controlSocketReadNotification",
        "_q_controlSocketErrorOccurred",
        "QAbstractSocket::SocketError",
        "_q_udpSocketReadNotification",
        "_q_controlSocketBytesWritten",
        "_q_emitPendingReadNotification",
        "_q_emitPendingWriteNotification",
        "_q_emitPendingConnectionNotification",
        "_q_controlSocketDisconnected",
        "_q_controlSocketStateChanged",
        "QAbstractSocket::SocketState"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot '_q_controlSocketConnected'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_controlSocketReadNotification'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_controlSocketErrorOccurred'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 2 },
        }}),
        // Slot '_q_udpSocketReadNotification'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_controlSocketBytesWritten'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_emitPendingReadNotification'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_emitPendingWriteNotification'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_emitPendingConnectionNotification'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_controlSocketDisconnected'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_controlSocketStateChanged'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketState)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 13, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSocks5SocketEngine, qt_meta_tag_ZN19QSocks5SocketEngineE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSocks5SocketEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractSocketEngine::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QSocks5SocketEngineE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QSocks5SocketEngineE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QSocks5SocketEngineE_t>.metaTypes,
    nullptr
} };

void QSocks5SocketEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSocks5SocketEngine *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->d_func()->_q_controlSocketConnected(); break;
        case 1: _t->d_func()->_q_controlSocketReadNotification(); break;
        case 2: _t->d_func()->_q_controlSocketErrorOccurred((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 3: _t->d_func()->_q_udpSocketReadNotification(); break;
        case 4: _t->d_func()->_q_controlSocketBytesWritten(); break;
        case 5: _t->d_func()->_q_emitPendingReadNotification(); break;
        case 6: _t->d_func()->_q_emitPendingWriteNotification(); break;
        case 7: _t->d_func()->_q_emitPendingConnectionNotification(); break;
        case 8: _t->d_func()->_q_controlSocketDisconnected(); break;
        case 9: _t->d_func()->_q_controlSocketStateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

const QMetaObject *QSocks5SocketEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSocks5SocketEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QSocks5SocketEngineE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractSocketEngine::qt_metacast(_clname);
}

int QSocks5SocketEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSocketEngine::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
