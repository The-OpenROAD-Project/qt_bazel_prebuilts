/****************************************************************************
** Meta object code from reading C++ file 'qdbusconnection_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/dbus/qdbusconnection_p.h"
#include <QtDBus/private/qdbuspendingcall_p.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbusconnection_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN22QDBusConnectionPrivateE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusConnectionPrivate::qt_create_metaobjectdata<qt_meta_tag_ZN22QDBusConnectionPrivateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusConnectionPrivate",
        "dispatchStatusChanged",
        "",
        "spyHooksFinished",
        "QDBusMessage",
        "msg",
        "messageNeedsSending",
        "QDBusPendingCallPrivate*",
        "pcall",
        "timeout",
        "serviceOwnerChanged",
        "name",
        "oldOwner",
        "newOwner",
        "callWithCallbackFailed",
        "QDBusError",
        "error",
        "message",
        "setDispatchEnabled",
        "enable",
        "doDispatch",
        "socketRead",
        "qintptr",
        "socketWrite",
        "objectDestroyed",
        "o",
        "relaySignal",
        "obj",
        "const QMetaObject*",
        "signalId",
        "QVariantList",
        "args",
        "serviceOwnerChangedNoLock",
        "registerServiceNoLock",
        "serviceName",
        "unregisterServiceNoLock",
        "handleDBusDisconnection"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dispatchStatusChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'spyHooksFinished'
        QtMocHelpers::SignalData<void(const QDBusMessage &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'messageNeedsSending'
        QtMocHelpers::SignalData<void(QDBusPendingCallPrivate *, void *, int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { QMetaType::VoidStar, 5 }, { QMetaType::Int, 9 },
        }}),
        // Signal 'messageNeedsSending'
        QtMocHelpers::SignalData<void(QDBusPendingCallPrivate *, void *)>(6, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { QMetaType::VoidStar, 5 },
        }}),
        // Signal 'serviceOwnerChanged'
        QtMocHelpers::SignalData<void(const QString &, const QString &, const QString &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::QString, 12 }, { QMetaType::QString, 13 },
        }}),
        // Signal 'callWithCallbackFailed'
        QtMocHelpers::SignalData<void(const QDBusError &, const QDBusMessage &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 }, { 0x80000000 | 4, 17 },
        }}),
        // Slot 'setDispatchEnabled'
        QtMocHelpers::SlotData<void(bool)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'doDispatch'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'socketRead'
        QtMocHelpers::SlotData<void(qintptr)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 22, 2 },
        }}),
        // Slot 'socketWrite'
        QtMocHelpers::SlotData<void(qintptr)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 22, 2 },
        }}),
        // Slot 'objectDestroyed'
        QtMocHelpers::SlotData<void(QObject *)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 25 },
        }}),
        // Slot 'relaySignal'
        QtMocHelpers::SlotData<void(QObject *, const QMetaObject *, int, const QVariantList &)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 27 }, { 0x80000000 | 28, 2 }, { QMetaType::Int, 29 }, { 0x80000000 | 30, 31 },
        }}),
        // Slot 'serviceOwnerChangedNoLock'
        QtMocHelpers::SlotData<void(const QString &, const QString &, const QString &)>(32, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::QString, 12 }, { QMetaType::QString, 13 },
        }}),
        // Slot 'registerServiceNoLock'
        QtMocHelpers::SlotData<void(const QString &)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 34 },
        }}),
        // Slot 'unregisterServiceNoLock'
        QtMocHelpers::SlotData<void(const QString &)>(35, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 34 },
        }}),
        // Slot 'handleDBusDisconnection'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDBusConnectionPrivate, qt_meta_tag_ZN22QDBusConnectionPrivateE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusConnectionPrivate::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QDBusConnectionPrivateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QDBusConnectionPrivateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22QDBusConnectionPrivateE_t>.metaTypes,
    nullptr
} };

void QDBusConnectionPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusConnectionPrivate *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dispatchStatusChanged(); break;
        case 1: _t->spyHooksFinished((*reinterpret_cast< std::add_pointer_t<QDBusMessage>>(_a[1]))); break;
        case 2: _t->messageNeedsSending((*reinterpret_cast< std::add_pointer_t<QDBusPendingCallPrivate*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->messageNeedsSending((*reinterpret_cast< std::add_pointer_t<QDBusPendingCallPrivate*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2]))); break;
        case 4: _t->serviceOwnerChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 5: _t->callWithCallbackFailed((*reinterpret_cast< std::add_pointer_t<QDBusError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDBusMessage>>(_a[2]))); break;
        case 6: _t->setDispatchEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->doDispatch(); break;
        case 8: _t->socketRead((*reinterpret_cast< std::add_pointer_t<qintptr>>(_a[1]))); break;
        case 9: _t->socketWrite((*reinterpret_cast< std::add_pointer_t<qintptr>>(_a[1]))); break;
        case 10: _t->objectDestroyed((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        case 11: _t->relaySignal((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<const QMetaObject*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[4]))); break;
        case 12: _t->serviceOwnerChangedNoLock((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 13: _t->registerServiceNoLock((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->unregisterServiceNoLock((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->handleDBusDisconnection(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusMessage >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusError >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusMessage >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionPrivate::*)()>(_a, &QDBusConnectionPrivate::dispatchStatusChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionPrivate::*)(const QDBusMessage & )>(_a, &QDBusConnectionPrivate::spyHooksFinished, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionPrivate::*)(QDBusPendingCallPrivate * , void * , int )>(_a, &QDBusConnectionPrivate::messageNeedsSending, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionPrivate::*)(const QString & , const QString & , const QString & )>(_a, &QDBusConnectionPrivate::serviceOwnerChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionPrivate::*)(const QDBusError & , const QDBusMessage & )>(_a, &QDBusConnectionPrivate::callWithCallbackFailed, 5))
            return;
    }
}

const QMetaObject *QDBusConnectionPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusConnectionPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QDBusConnectionPrivateE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QDBusConnectionPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void QDBusConnectionPrivate::dispatchStatusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QDBusConnectionPrivate::spyHooksFinished(const QDBusMessage & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QDBusConnectionPrivate::messageNeedsSending(QDBusPendingCallPrivate * _t1, void * _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3);
}

// SIGNAL 4
void QDBusConnectionPrivate::serviceOwnerChanged(const QString & _t1, const QString & _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2, _t3);
}

// SIGNAL 5
void QDBusConnectionPrivate::callWithCallbackFailed(const QDBusError & _t1, const QDBusMessage & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}
QT_WARNING_POP
