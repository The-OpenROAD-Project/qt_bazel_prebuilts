/****************************************************************************
** Meta object code from reading C++ file 'qhttpsocketengine_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/socket/qhttpsocketengine_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhttpsocketengine_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QHttpSocketEngineE_t {};
} // unnamed namespace

template <> constexpr inline auto QHttpSocketEngine::qt_create_metaobjectdata<qt_meta_tag_ZN17QHttpSocketEngineE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QHttpSocketEngine",
        "slotSocketConnected",
        "",
        "slotSocketDisconnected",
        "slotSocketReadNotification",
        "slotSocketBytesWritten",
        "slotSocketError",
        "QAbstractSocket::SocketError",
        "error",
        "slotSocketStateChanged",
        "QAbstractSocket::SocketState",
        "state",
        "emitPendingReadNotification",
        "emitPendingWriteNotification",
        "emitPendingConnectionNotification"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'slotSocketConnected'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slotSocketDisconnected'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slotSocketReadNotification'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slotSocketBytesWritten'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'slotSocketError'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Slot 'slotSocketStateChanged'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketState)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'emitPendingReadNotification'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'emitPendingWriteNotification'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'emitPendingConnectionNotification'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QHttpSocketEngine, qt_meta_tag_ZN17QHttpSocketEngineE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QHttpSocketEngine::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractSocketEngine::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QHttpSocketEngineE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QHttpSocketEngineE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QHttpSocketEngineE_t>.metaTypes,
    nullptr
} };

void QHttpSocketEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QHttpSocketEngine *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->slotSocketConnected(); break;
        case 1: _t->slotSocketDisconnected(); break;
        case 2: _t->slotSocketReadNotification(); break;
        case 3: _t->slotSocketBytesWritten(); break;
        case 4: _t->slotSocketError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 5: _t->slotSocketStateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 6: _t->emitPendingReadNotification(); break;
        case 7: _t->emitPendingWriteNotification(); break;
        case 8: _t->emitPendingConnectionNotification(); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

const QMetaObject *QHttpSocketEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHttpSocketEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QHttpSocketEngineE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractSocketEngine::qt_metacast(_clname);
}

int QHttpSocketEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSocketEngine::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
