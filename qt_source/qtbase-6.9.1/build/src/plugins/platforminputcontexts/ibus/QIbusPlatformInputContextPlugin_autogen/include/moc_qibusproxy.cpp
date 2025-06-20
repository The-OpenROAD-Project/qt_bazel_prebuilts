/****************************************************************************
** Meta object code from reading C++ file 'qibusproxy.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/platforminputcontexts/ibus/qibusproxy.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qibusproxy.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QIBusProxyE_t {};
} // unnamed namespace

template <> constexpr inline auto QIBusProxy::qt_create_metaobjectdata<qt_meta_tag_ZN10QIBusProxyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QIBusProxy",
        "GlobalEngineChanged",
        "",
        "engine_name",
        "CreateInputContext",
        "QDBusPendingReply<QDBusObjectPath>",
        "name",
        "Exit",
        "QDBusPendingReply<>",
        "restart",
        "Ping",
        "QDBusPendingReply<QDBusVariant>",
        "QDBusVariant",
        "data",
        "RegisterComponent",
        "components",
        "GetProperty",
        "QDBusPendingCall",
        "method",
        "GlobalEngine",
        "getGlobalEngine",
        "QIBusEngineDesc",
        "globalEngineChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'GlobalEngineChanged'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'CreateInputContext'
        QtMocHelpers::SlotData<QDBusPendingReply<QDBusObjectPath>(const QString &)>(4, 2, QMC::AccessPublic, 0x80000000 | 5, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'Exit'
        QtMocHelpers::SlotData<QDBusPendingReply<>(bool)>(7, 2, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'Ping'
        QtMocHelpers::SlotData<QDBusPendingReply<QDBusVariant>(const QDBusVariant &)>(10, 2, QMC::AccessPublic, 0x80000000 | 11, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Slot 'RegisterComponent'
        QtMocHelpers::SlotData<QDBusPendingReply<>(const QDBusVariant &)>(14, 2, QMC::AccessPublic, 0x80000000 | 8, {{
            { 0x80000000 | 12, 15 },
        }}),
        // Slot 'GetProperty'
        QtMocHelpers::SlotData<QDBusPendingCall(const QString)>(16, 2, QMC::AccessPublic, 0x80000000 | 17, {{
            { QMetaType::QString, 18 },
        }}),
        // Slot 'GlobalEngine'
        QtMocHelpers::SlotData<QDBusPendingCall()>(19, 2, QMC::AccessPublic, 0x80000000 | 17),
        // Slot 'getGlobalEngine'
        QtMocHelpers::SlotData<QIBusEngineDesc()>(20, 2, QMC::AccessPublic, 0x80000000 | 21),
        // Slot 'globalEngineChanged'
        QtMocHelpers::SlotData<void(const QString &)>(22, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QIBusProxy, qt_meta_tag_ZN10QIBusProxyE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QIBusProxy::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QIBusProxyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QIBusProxyE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QIBusProxyE_t>.metaTypes,
    nullptr
} };

void QIBusProxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QIBusProxy *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->GlobalEngineChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: { QDBusPendingReply<QDBusObjectPath> _r = _t->CreateInputContext((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QDBusObjectPath>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<> _r = _t->Exit((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<QDBusVariant> _r = _t->Ping((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QDBusVariant>*>(_a[0]) = std::move(_r); }  break;
        case 4: { QDBusPendingReply<> _r = _t->RegisterComponent((*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 5: { QDBusPendingCall _r = _t->GetProperty((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingCall*>(_a[0]) = std::move(_r); }  break;
        case 6: { QDBusPendingCall _r = _t->GlobalEngine();
            if (_a[0]) *reinterpret_cast< QDBusPendingCall*>(_a[0]) = std::move(_r); }  break;
        case 7: { QIBusEngineDesc _r = _t->getGlobalEngine();
            if (_a[0]) *reinterpret_cast< QIBusEngineDesc*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->globalEngineChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QIBusProxy::*)(const QString & )>(_a, &QIBusProxy::GlobalEngineChanged, 0))
            return;
    }
}

const QMetaObject *QIBusProxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIBusProxy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QIBusProxyE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int QIBusProxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QIBusProxy::GlobalEngineChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
