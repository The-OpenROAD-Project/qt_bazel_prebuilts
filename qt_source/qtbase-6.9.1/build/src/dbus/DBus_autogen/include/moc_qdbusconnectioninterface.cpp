/****************************************************************************
** Meta object code from reading C++ file 'qdbusconnectioninterface.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/dbus/qdbusconnectioninterface.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbusconnectioninterface.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN24QDBusConnectionInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusConnectionInterface::qt_create_metaobjectdata<qt_meta_tag_ZN24QDBusConnectionInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusConnectionInterface",
        "serviceRegistered",
        "",
        "service",
        "serviceUnregistered",
        "serviceOwnerChanged",
        "name",
        "oldOwner",
        "newOwner",
        "callWithCallbackFailed",
        "QDBusError",
        "error",
        "QDBusMessage",
        "call",
        "NameAcquired",
        "NameLost",
        "NameOwnerChanged",
        "registeredServiceNames",
        "QDBusReply<QStringList>",
        "activatableServiceNames",
        "isServiceRegistered",
        "QDBusReply<bool>",
        "serviceName",
        "serviceOwner",
        "QDBusReply<QString>",
        "unregisterService",
        "registerService",
        "QDBusReply<QDBusConnectionInterface::RegisterServiceReply>",
        "ServiceQueueOptions",
        "qoption",
        "ServiceReplacementOptions",
        "roption",
        "servicePid",
        "QDBusReply<uint>",
        "serviceUid",
        "startService",
        "QDBusReply<void>",
        "DontQueueService",
        "QueueService",
        "ReplaceExistingService",
        "DontAllowReplacement",
        "AllowReplacement",
        "RegisterServiceReply",
        "ServiceNotRegistered",
        "ServiceRegistered",
        "ServiceQueued"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'serviceRegistered'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'serviceUnregistered'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'serviceOwnerChanged'
        QtMocHelpers::SignalData<void(const QString &, const QString &, const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 }, { QMetaType::QString, 7 }, { QMetaType::QString, 8 },
        }}),
        // Signal 'callWithCallbackFailed'
        QtMocHelpers::SignalData<void(const QDBusError &, const QDBusMessage &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 }, { 0x80000000 | 12, 13 },
        }}),
        // Signal 'NameAcquired'
        QtMocHelpers::SignalData<void(const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'NameLost'
        QtMocHelpers::SignalData<void(const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'NameOwnerChanged'
        QtMocHelpers::SignalData<void(const QString &, const QString &, const QString &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::QString, 2 }, { QMetaType::QString, 2 },
        }}),
        // Slot 'registeredServiceNames'
        QtMocHelpers::SlotData<QDBusReply<QStringList>() const>(17, 2, QMC::AccessPublic, 0x80000000 | 18),
        // Slot 'activatableServiceNames'
        QtMocHelpers::SlotData<QDBusReply<QStringList>() const>(19, 2, QMC::AccessPublic, 0x80000000 | 18),
        // Slot 'isServiceRegistered'
        QtMocHelpers::SlotData<QDBusReply<bool>(const QString &) const>(20, 2, QMC::AccessPublic, 0x80000000 | 21, {{
            { QMetaType::QString, 22 },
        }}),
        // Slot 'serviceOwner'
        QtMocHelpers::SlotData<QDBusReply<QString>(const QString &) const>(23, 2, QMC::AccessPublic, 0x80000000 | 24, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'unregisterService'
        QtMocHelpers::SlotData<QDBusReply<bool>(const QString &)>(25, 2, QMC::AccessPublic, 0x80000000 | 21, {{
            { QMetaType::QString, 22 },
        }}),
        // Slot 'registerService'
        QtMocHelpers::SlotData<QDBusReply<QDBusConnectionInterface::RegisterServiceReply>(const QString &, ServiceQueueOptions, ServiceReplacementOptions)>(26, 2, QMC::AccessPublic, 0x80000000 | 27, {{
            { QMetaType::QString, 22 }, { 0x80000000 | 28, 29 }, { 0x80000000 | 30, 31 },
        }}),
        // Slot 'registerService'
        QtMocHelpers::SlotData<QDBusReply<QDBusConnectionInterface::RegisterServiceReply>(const QString &, ServiceQueueOptions)>(26, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 27, {{
            { QMetaType::QString, 22 }, { 0x80000000 | 28, 29 },
        }}),
        // Slot 'registerService'
        QtMocHelpers::SlotData<QDBusReply<QDBusConnectionInterface::RegisterServiceReply>(const QString &)>(26, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 27, {{
            { QMetaType::QString, 22 },
        }}),
        // Slot 'servicePid'
        QtMocHelpers::SlotData<QDBusReply<uint>(const QString &) const>(32, 2, QMC::AccessPublic, 0x80000000 | 33, {{
            { QMetaType::QString, 22 },
        }}),
        // Slot 'serviceUid'
        QtMocHelpers::SlotData<QDBusReply<uint>(const QString &) const>(34, 2, QMC::AccessPublic, 0x80000000 | 33, {{
            { QMetaType::QString, 22 },
        }}),
        // Slot 'startService'
        QtMocHelpers::SlotData<QDBusReply<void>(const QString &)>(35, 2, QMC::AccessPublic, 0x80000000 | 36, {{
            { QMetaType::QString, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'registeredServiceNames'
        QtMocHelpers::PropertyData<QDBusReply<QStringList>>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'activatableServiceNames'
        QtMocHelpers::PropertyData<QDBusReply<QStringList>>(19, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ServiceQueueOptions'
        QtMocHelpers::EnumData<ServiceQueueOptions>(28, 28, QMC::EnumFlags{}).add({
            {   37, ServiceQueueOptions::DontQueueService },
            {   38, ServiceQueueOptions::QueueService },
            {   39, ServiceQueueOptions::ReplaceExistingService },
        }),
        // enum 'ServiceReplacementOptions'
        QtMocHelpers::EnumData<ServiceReplacementOptions>(30, 30, QMC::EnumFlags{}).add({
            {   40, ServiceReplacementOptions::DontAllowReplacement },
            {   41, ServiceReplacementOptions::AllowReplacement },
        }),
        // enum 'RegisterServiceReply'
        QtMocHelpers::EnumData<RegisterServiceReply>(42, 42, QMC::EnumFlags{}).add({
            {   43, RegisterServiceReply::ServiceNotRegistered },
            {   44, RegisterServiceReply::ServiceRegistered },
            {   45, RegisterServiceReply::ServiceQueued },
        }),
    };
    return QtMocHelpers::metaObjectData<QDBusConnectionInterface, qt_meta_tag_ZN24QDBusConnectionInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusConnectionInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QDBusConnectionInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QDBusConnectionInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24QDBusConnectionInterfaceE_t>.metaTypes,
    nullptr
} };

void QDBusConnectionInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusConnectionInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->serviceRegistered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->serviceUnregistered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->serviceOwnerChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 3: _t->callWithCallbackFailed((*reinterpret_cast< std::add_pointer_t<QDBusError>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDBusMessage>>(_a[2]))); break;
        case 4: _t->NameAcquired((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->NameLost((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->NameOwnerChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 7: { QDBusReply<QStringList> _r = _t->registeredServiceNames();
            if (_a[0]) *reinterpret_cast< QDBusReply<QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 8: { QDBusReply<QStringList> _r = _t->activatableServiceNames();
            if (_a[0]) *reinterpret_cast< QDBusReply<QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 9: { QDBusReply<bool> _r = _t->isServiceRegistered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusReply<bool>*>(_a[0]) = std::move(_r); }  break;
        case 10: { QDBusReply<QString> _r = _t->serviceOwner((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusReply<QString>*>(_a[0]) = std::move(_r); }  break;
        case 11: { QDBusReply<bool> _r = _t->unregisterService((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusReply<bool>*>(_a[0]) = std::move(_r); }  break;
        case 12: { QDBusReply<QDBusConnectionInterface::RegisterServiceReply> _r = _t->registerService((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ServiceQueueOptions>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<ServiceReplacementOptions>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusReply<QDBusConnectionInterface::RegisterServiceReply>*>(_a[0]) = std::move(_r); }  break;
        case 13: { QDBusReply<QDBusConnectionInterface::RegisterServiceReply> _r = _t->registerService((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<ServiceQueueOptions>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusReply<QDBusConnectionInterface::RegisterServiceReply>*>(_a[0]) = std::move(_r); }  break;
        case 14: { QDBusReply<QDBusConnectionInterface::RegisterServiceReply> _r = _t->registerService((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusReply<QDBusConnectionInterface::RegisterServiceReply>*>(_a[0]) = std::move(_r); }  break;
        case 15: { QDBusReply<uint> _r = _t->servicePid((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusReply<uint>*>(_a[0]) = std::move(_r); }  break;
        case 16: { QDBusReply<uint> _r = _t->serviceUid((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusReply<uint>*>(_a[0]) = std::move(_r); }  break;
        case 17: { QDBusReply<void> _r = _t->startService((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusReply<void>*>(_a[0]) = std::move(_r); }  break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusError >(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusMessage >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionInterface::*)(const QString & )>(_a, &QDBusConnectionInterface::serviceRegistered, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionInterface::*)(const QString & )>(_a, &QDBusConnectionInterface::serviceUnregistered, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionInterface::*)(const QString & , const QString & , const QString & )>(_a, &QDBusConnectionInterface::serviceOwnerChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionInterface::*)(const QDBusError & , const QDBusMessage & )>(_a, &QDBusConnectionInterface::callWithCallbackFailed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionInterface::*)(const QString & )>(_a, &QDBusConnectionInterface::NameAcquired, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionInterface::*)(const QString & )>(_a, &QDBusConnectionInterface::NameLost, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusConnectionInterface::*)(const QString & , const QString & , const QString & )>(_a, &QDBusConnectionInterface::NameOwnerChanged, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QDBusReply<QStringList>*>(_v) = _t->registeredServiceNames(); break;
        case 1: *reinterpret_cast<QDBusReply<QStringList>*>(_v) = _t->activatableServiceNames(); break;
        default: break;
        }
    }
}

const QMetaObject *QDBusConnectionInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusConnectionInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QDBusConnectionInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int QDBusConnectionInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QDBusConnectionInterface::serviceRegistered(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QDBusConnectionInterface::serviceUnregistered(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QDBusConnectionInterface::serviceOwnerChanged(const QString & _t1, const QString & _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3);
}

// SIGNAL 3
void QDBusConnectionInterface::callWithCallbackFailed(const QDBusError & _t1, const QDBusMessage & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void QDBusConnectionInterface::NameAcquired(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QDBusConnectionInterface::NameLost(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QDBusConnectionInterface::NameOwnerChanged(const QString & _t1, const QString & _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
