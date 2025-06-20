/****************************************************************************
** Meta object code from reading C++ file 'qdbustrayicon_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/platform/unix/dbustray/qdbustrayicon_p.h"
#include <QtDBus/QDBusError>
#include <private/qdbusplatformmenu_p.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbustrayicon_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QDBusTrayIconE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusTrayIcon::qt_create_metaobjectdata<qt_meta_tag_ZN13QDBusTrayIconE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusTrayIcon",
        "categoryChanged",
        "",
        "statusChanged",
        "arg",
        "tooltipChanged",
        "iconChanged",
        "attention",
        "menuChanged",
        "attentionTimerExpired",
        "actionInvoked",
        "id",
        "action",
        "notificationClosed",
        "reason",
        "watcherServiceRegistered",
        "serviceName",
        "category",
        "status",
        "tooltip",
        "iconName",
        "icon",
        "isRequestingAttention",
        "attentionTitle",
        "attentionMessage",
        "attentionIconName",
        "attentionIcon",
        "menu",
        "QDBusPlatformMenu*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'categoryChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'statusChanged'
        QtMocHelpers::SignalData<void(QString)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Signal 'tooltipChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'iconChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'attention'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'menuChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'attentionTimerExpired'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'actionInvoked'
        QtMocHelpers::SlotData<void(uint, const QString &)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::UInt, 11 }, { QMetaType::QString, 12 },
        }}),
        // Slot 'notificationClosed'
        QtMocHelpers::SlotData<void(uint, uint)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::UInt, 11 }, { QMetaType::UInt, 14 },
        }}),
        // Slot 'watcherServiceRegistered'
        QtMocHelpers::SlotData<void(const QString &)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'category'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags, 0),
        // property 'status'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags, 1),
        // property 'tooltip'
        QtMocHelpers::PropertyData<QString>(19, QMetaType::QString, QMC::DefaultPropertyFlags, 2),
        // property 'iconName'
        QtMocHelpers::PropertyData<QString>(20, QMetaType::QString, QMC::DefaultPropertyFlags, 3),
        // property 'icon'
        QtMocHelpers::PropertyData<QIcon>(21, QMetaType::QIcon, QMC::DefaultPropertyFlags, 3),
        // property 'isRequestingAttention'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'attentionTitle'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags, 4),
        // property 'attentionMessage'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags, 4),
        // property 'attentionIconName'
        QtMocHelpers::PropertyData<QString>(25, QMetaType::QString, QMC::DefaultPropertyFlags, 4),
        // property 'attentionIcon'
        QtMocHelpers::PropertyData<QIcon>(26, QMetaType::QIcon, QMC::DefaultPropertyFlags, 4),
        // property 'menu'
        QtMocHelpers::PropertyData<QDBusPlatformMenu*>(27, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 5),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDBusTrayIcon, qt_meta_tag_ZN13QDBusTrayIconE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusTrayIcon::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformSystemTrayIcon::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QDBusTrayIconE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QDBusTrayIconE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QDBusTrayIconE_t>.metaTypes,
    nullptr
} };

void QDBusTrayIcon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusTrayIcon *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->categoryChanged(); break;
        case 1: _t->statusChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->tooltipChanged(); break;
        case 3: _t->iconChanged(); break;
        case 4: _t->attention(); break;
        case 5: _t->menuChanged(); break;
        case 6: _t->attentionTimerExpired(); break;
        case 7: _t->actionInvoked((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 8: _t->notificationClosed((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        case 9: _t->watcherServiceRegistered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDBusTrayIcon::*)()>(_a, &QDBusTrayIcon::categoryChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusTrayIcon::*)(QString )>(_a, &QDBusTrayIcon::statusChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusTrayIcon::*)()>(_a, &QDBusTrayIcon::tooltipChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusTrayIcon::*)()>(_a, &QDBusTrayIcon::iconChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusTrayIcon::*)()>(_a, &QDBusTrayIcon::attention, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusTrayIcon::*)()>(_a, &QDBusTrayIcon::menuChanged, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->category(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->status(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->tooltip(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->iconName(); break;
        case 4: *reinterpret_cast<QIcon*>(_v) = _t->icon(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isRequestingAttention(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->attentionTitle(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->attentionMessage(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->attentionIconName(); break;
        case 9: *reinterpret_cast<QIcon*>(_v) = _t->attentionIcon(); break;
        case 10: *reinterpret_cast<QDBusPlatformMenu**>(_v) = _t->menu(); break;
        default: break;
        }
    }
}

const QMetaObject *QDBusTrayIcon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusTrayIcon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QDBusTrayIconE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformSystemTrayIcon::qt_metacast(_clname);
}

int QDBusTrayIcon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformSystemTrayIcon::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QDBusTrayIcon::categoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QDBusTrayIcon::statusChanged(QString _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QDBusTrayIcon::tooltipChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QDBusTrayIcon::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QDBusTrayIcon::attention()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QDBusTrayIcon::menuChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
