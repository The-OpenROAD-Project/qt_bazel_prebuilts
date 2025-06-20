/****************************************************************************
** Meta object code from reading C++ file 'qxdgnotificationproxy_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/platform/unix/dbustray/qxdgnotificationproxy_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxdgnotificationproxy_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN25QXdgNotificationInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto QXdgNotificationInterface::qt_create_metaobjectdata<qt_meta_tag_ZN25QXdgNotificationInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QXdgNotificationInterface",
        "ActionInvoked",
        "",
        "id",
        "action_key",
        "NotificationClosed",
        "reason",
        "closeNotification",
        "QDBusPendingReply<>",
        "getCapabilities",
        "QDBusPendingReply<QStringList>",
        "getServerInformation",
        "QDBusPendingReply<QString,QString,QString,QString>",
        "QDBusReply<QString>",
        "QString&",
        "vendor",
        "version",
        "specVersion",
        "notify",
        "QDBusPendingReply<uint>",
        "appName",
        "replacesId",
        "appIcon",
        "summary",
        "body",
        "actions",
        "QVariantMap",
        "hints",
        "timeout"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'ActionInvoked'
        QtMocHelpers::SignalData<void(uint, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'NotificationClosed'
        QtMocHelpers::SignalData<void(uint, uint)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 3 }, { QMetaType::UInt, 6 },
        }}),
        // Slot 'closeNotification'
        QtMocHelpers::SlotData<QDBusPendingReply<>(uint)>(7, 2, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::UInt, 3 },
        }}),
        // Slot 'getCapabilities'
        QtMocHelpers::SlotData<QDBusPendingReply<QStringList>()>(9, 2, QMC::AccessPublic, 0x80000000 | 10),
        // Slot 'getServerInformation'
        QtMocHelpers::SlotData<QDBusPendingReply<QString,QString,QString,QString>()>(11, 2, QMC::AccessPublic, 0x80000000 | 12),
        // Slot 'getServerInformation'
        QtMocHelpers::SlotData<QDBusReply<QString>(QString &, QString &, QString &)>(11, 2, QMC::AccessPublic, 0x80000000 | 13, {{
            { 0x80000000 | 14, 15 }, { 0x80000000 | 14, 16 }, { 0x80000000 | 14, 17 },
        }}),
        // Slot 'notify'
        QtMocHelpers::SlotData<QDBusPendingReply<uint>(const QString &, uint, const QString &, const QString &, const QString &, const QStringList &, const QVariantMap &, int)>(18, 2, QMC::AccessPublic, 0x80000000 | 19, {{
            { QMetaType::QString, 20 }, { QMetaType::UInt, 21 }, { QMetaType::QString, 22 }, { QMetaType::QString, 23 },
            { QMetaType::QString, 24 }, { QMetaType::QStringList, 25 }, { 0x80000000 | 26, 27 }, { QMetaType::Int, 28 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QXdgNotificationInterface, qt_meta_tag_ZN25QXdgNotificationInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QXdgNotificationInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QXdgNotificationInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QXdgNotificationInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN25QXdgNotificationInterfaceE_t>.metaTypes,
    nullptr
} };

void QXdgNotificationInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QXdgNotificationInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->ActionInvoked((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->NotificationClosed((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 2: { QDBusPendingReply<> _r = _t->closeNotification((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<QStringList> _r = _t->getCapabilities();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QStringList>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QDBusPendingReply<QString,QString,QString,QString> _r = _t->getServerInformation();
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QString,QString,QString,QString>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QDBusReply<QString> _r = _t->getServerInformation((*reinterpret_cast< std::add_pointer_t<QString&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString&>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusReply<QString>*>(_a[0]) = std::move(_r); }  break;
        case 6: { QDBusPendingReply<uint> _r = _t->notify((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[8])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<uint>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QXdgNotificationInterface::*)(uint , const QString & )>(_a, &QXdgNotificationInterface::ActionInvoked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QXdgNotificationInterface::*)(uint , uint )>(_a, &QXdgNotificationInterface::NotificationClosed, 1))
            return;
    }
}

const QMetaObject *QXdgNotificationInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXdgNotificationInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QXdgNotificationInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int QXdgNotificationInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QXdgNotificationInterface::ActionInvoked(uint _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QXdgNotificationInterface::NotificationClosed(uint _t1, uint _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}
QT_WARNING_POP
