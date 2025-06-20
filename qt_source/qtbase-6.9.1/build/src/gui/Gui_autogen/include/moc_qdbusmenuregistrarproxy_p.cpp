/****************************************************************************
** Meta object code from reading C++ file 'qdbusmenuregistrarproxy_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/platform/unix/dbusmenu/qdbusmenuregistrarproxy_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbusmenuregistrarproxy_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN27QDBusMenuRegistrarInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusMenuRegistrarInterface::qt_create_metaobjectdata<qt_meta_tag_ZN27QDBusMenuRegistrarInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusMenuRegistrarInterface",
        "GetMenuForWindow",
        "QDBusPendingReply<QString,QDBusObjectPath>",
        "",
        "windowId",
        "QDBusReply<QString>",
        "QDBusObjectPath&",
        "menuObjectPath",
        "RegisterWindow",
        "QDBusPendingReply<>",
        "QDBusObjectPath",
        "UnregisterWindow"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'GetMenuForWindow'
        QtMocHelpers::SlotData<QDBusPendingReply<QString,QDBusObjectPath>(uint)>(1, 3, QMC::AccessPublic, 0x80000000 | 2, {{
            { QMetaType::UInt, 4 },
        }}),
        // Slot 'GetMenuForWindow'
        QtMocHelpers::SlotData<QDBusReply<QString>(uint, QDBusObjectPath &)>(1, 3, QMC::AccessPublic, 0x80000000 | 5, {{
            { QMetaType::UInt, 4 }, { 0x80000000 | 6, 7 },
        }}),
        // Slot 'RegisterWindow'
        QtMocHelpers::SlotData<QDBusPendingReply<>(uint, const QDBusObjectPath &)>(8, 3, QMC::AccessPublic, 0x80000000 | 9, {{
            { QMetaType::UInt, 4 }, { 0x80000000 | 10, 7 },
        }}),
        // Slot 'UnregisterWindow'
        QtMocHelpers::SlotData<QDBusPendingReply<>(uint)>(11, 3, QMC::AccessPublic, 0x80000000 | 9, {{
            { QMetaType::UInt, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDBusMenuRegistrarInterface, qt_meta_tag_ZN27QDBusMenuRegistrarInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusMenuRegistrarInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QDBusMenuRegistrarInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QDBusMenuRegistrarInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN27QDBusMenuRegistrarInterfaceE_t>.metaTypes,
    nullptr
} };

void QDBusMenuRegistrarInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusMenuRegistrarInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QDBusPendingReply<QString,QDBusObjectPath> _r = _t->GetMenuForWindow((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QString,QDBusObjectPath>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QDBusReply<QString> _r = _t->GetMenuForWindow((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDBusObjectPath&>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusReply<QString>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<> _r = _t->RegisterWindow((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDBusObjectPath>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<> _r = _t->UnregisterWindow((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusObjectPath >(); break;
            }
            break;
        }
    }
}

const QMetaObject *QDBusMenuRegistrarInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusMenuRegistrarInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QDBusMenuRegistrarInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int QDBusMenuRegistrarInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
