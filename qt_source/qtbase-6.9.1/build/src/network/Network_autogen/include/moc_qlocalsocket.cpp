/****************************************************************************
** Meta object code from reading C++ file 'qlocalsocket.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/network/socket/qlocalsocket.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlocalsocket.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QLocalSocketE_t {};
} // unnamed namespace

template <> constexpr inline auto QLocalSocket::qt_create_metaobjectdata<qt_meta_tag_ZN12QLocalSocketE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QLocalSocket",
        "connected",
        "",
        "disconnected",
        "errorOccurred",
        "QLocalSocket::LocalSocketError",
        "socketError",
        "stateChanged",
        "QLocalSocket::LocalSocketState",
        "socketState",
        "_q_stateChanged",
        "QAbstractSocket::SocketState",
        "_q_errorOccurred",
        "QAbstractSocket::SocketError",
        "_q_connectToSocket",
        "_q_abortConnectionAttempt",
        "socketOptions",
        "SocketOptions",
        "SocketOption",
        "NoOptions",
        "AbstractNamespaceOption"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'connected'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'disconnected'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(QLocalSocket::LocalSocketError)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(QLocalSocket::LocalSocketState)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Slot '_q_stateChanged'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketState)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 11, 2 },
        }}),
        // Slot '_q_errorOccurred'
        QtMocHelpers::SlotData<void(QAbstractSocket::SocketError)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 13, 2 },
        }}),
        // Slot '_q_connectToSocket'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_abortConnectionAttempt'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'socketOptions'
        QtMocHelpers::PropertyData<SocketOptions>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SocketOptions'
        QtMocHelpers::EnumData<SocketOptions>(17, 18, QMC::EnumFlags{}).add({
            {   19, SocketOption::NoOptions },
            {   20, SocketOption::AbstractNamespaceOption },
        }),
    };
    return QtMocHelpers::metaObjectData<QLocalSocket, qt_meta_tag_ZN12QLocalSocketE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QLocalSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QIODevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QLocalSocketE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QLocalSocketE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QLocalSocketE_t>.metaTypes,
    nullptr
} };

void QLocalSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QLocalSocket *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QLocalSocket::LocalSocketError>>(_a[1]))); break;
        case 3: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QLocalSocket::LocalSocketState>>(_a[1]))); break;
        case 4: _t->d_func()->_q_stateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketState>>(_a[1]))); break;
        case 5: _t->d_func()->_q_errorOccurred((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 6: _t->d_func()->_q_connectToSocket(); break;
        case 7: _t->d_func()->_q_abortConnectionAttempt(); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QLocalSocket::*)()>(_a, &QLocalSocket::connected, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLocalSocket::*)()>(_a, &QLocalSocket::disconnected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLocalSocket::*)(QLocalSocket::LocalSocketError )>(_a, &QLocalSocket::errorOccurred, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLocalSocket::*)(QLocalSocket::LocalSocketState )>(_a, &QLocalSocket::stateChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::assignFlags<SocketOptions>(_v, _t->socketOptions()); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSocketOptions(*reinterpret_cast<SocketOptions*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableSocketOptions(); break;
        default: break;
        }
    }
}

const QMetaObject *QLocalSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLocalSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QLocalSocketE_t>.strings))
        return static_cast<void*>(this);
    return QIODevice::qt_metacast(_clname);
}

int QLocalSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QLocalSocket::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QLocalSocket::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QLocalSocket::errorOccurred(QLocalSocket::LocalSocketError _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QLocalSocket::stateChanged(QLocalSocket::LocalSocketState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
