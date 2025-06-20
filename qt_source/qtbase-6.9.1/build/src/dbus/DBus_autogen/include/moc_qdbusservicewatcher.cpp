/****************************************************************************
** Meta object code from reading C++ file 'qdbusservicewatcher.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/dbus/qdbusservicewatcher.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbusservicewatcher.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QDBusServiceWatcherE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusServiceWatcher::qt_create_metaobjectdata<qt_meta_tag_ZN19QDBusServiceWatcherE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusServiceWatcher",
        "serviceRegistered",
        "",
        "service",
        "serviceUnregistered",
        "serviceOwnerChanged",
        "oldOwner",
        "newOwner",
        "_q_serviceOwnerChanged",
        "watchedServices",
        "watchMode",
        "WatchMode",
        "WatchModeFlag",
        "WatchForRegistration",
        "WatchForUnregistration",
        "WatchForOwnerChange"
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
            { QMetaType::QString, 3 }, { QMetaType::QString, 6 }, { QMetaType::QString, 7 },
        }}),
        // Slot '_q_serviceOwnerChanged'
        QtMocHelpers::SlotData<void(QString, QString, QString)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 2 }, { QMetaType::QString, 2 }, { QMetaType::QString, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'watchedServices'
        QtMocHelpers::PropertyData<QStringList>(9, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'watchMode'
        QtMocHelpers::PropertyData<WatchMode>(10, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'WatchMode'
        QtMocHelpers::EnumData<WatchMode>(11, 12, QMC::EnumFlags{}).add({
            {   13, WatchModeFlag::WatchForRegistration },
            {   14, WatchModeFlag::WatchForUnregistration },
            {   15, WatchModeFlag::WatchForOwnerChange },
        }),
    };
    return QtMocHelpers::metaObjectData<QDBusServiceWatcher, qt_meta_tag_ZN19QDBusServiceWatcherE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusServiceWatcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QDBusServiceWatcherE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QDBusServiceWatcherE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QDBusServiceWatcherE_t>.metaTypes,
    nullptr
} };

void QDBusServiceWatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusServiceWatcher *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->serviceRegistered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->serviceUnregistered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->serviceOwnerChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 3: _t->d_func()->_q_serviceOwnerChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDBusServiceWatcher::*)(const QString & )>(_a, &QDBusServiceWatcher::serviceRegistered, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusServiceWatcher::*)(const QString & )>(_a, &QDBusServiceWatcher::serviceUnregistered, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusServiceWatcher::*)(const QString & , const QString & , const QString & )>(_a, &QDBusServiceWatcher::serviceOwnerChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QStringList*>(_v) = _t->watchedServices(); break;
        case 1: QtMocHelpers::assignFlags<WatchMode>(_v, _t->watchMode()); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWatchedServices(*reinterpret_cast<QStringList*>(_v)); break;
        case 1: _t->setWatchMode(*reinterpret_cast<WatchMode*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableWatchedServices(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableWatchMode(); break;
        default: break;
        }
    }
}

const QMetaObject *QDBusServiceWatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusServiceWatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QDBusServiceWatcherE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QDBusServiceWatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QDBusServiceWatcher::serviceRegistered(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QDBusServiceWatcher::serviceUnregistered(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QDBusServiceWatcher::serviceOwnerChanged(const QString & _t1, const QString & _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
