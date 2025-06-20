/****************************************************************************
** Meta object code from reading C++ file 'properties_interface.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../properties_interface.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'properties_interface.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN37OrgFreedesktopDBusPropertiesInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto OrgFreedesktopDBusPropertiesInterface::qt_create_metaobjectdata<qt_meta_tag_ZN37OrgFreedesktopDBusPropertiesInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "OrgFreedesktopDBusPropertiesInterface",
        "PropertiesChanged",
        "",
        "interface_name",
        "QVariantMap",
        "changed_properties",
        "invalidated_properties",
        "Get",
        "QDBusPendingReply<QDBusVariant>",
        "property_name",
        "GetAll",
        "QDBusPendingReply<QVariantMap>",
        "Set",
        "QDBusPendingReply<>",
        "QDBusVariant",
        "value"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'PropertiesChanged'
        QtMocHelpers::SignalData<void(const QString &, const QVariantMap &, const QStringList &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 4, 5 }, { QMetaType::QStringList, 6 },
        }}),
        // Slot 'Get'
        QtMocHelpers::SlotData<QDBusPendingReply<QDBusVariant>(const QString &, const QString &)>(7, 2, QMC::AccessPublic, 0x80000000 | 8, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 9 },
        }}),
        // Slot 'GetAll'
        QtMocHelpers::SlotData<QDBusPendingReply<QVariantMap>(const QString &)>(10, 2, QMC::AccessPublic, 0x80000000 | 11, {{
            { QMetaType::QString, 3 },
        }}),
        // Slot 'Set'
        QtMocHelpers::SlotData<QDBusPendingReply<>(const QString &, const QString &, const QDBusVariant &)>(12, 2, QMC::AccessPublic, 0x80000000 | 13, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 9 }, { 0x80000000 | 14, 15 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<OrgFreedesktopDBusPropertiesInterface, qt_meta_tag_ZN37OrgFreedesktopDBusPropertiesInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject OrgFreedesktopDBusPropertiesInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN37OrgFreedesktopDBusPropertiesInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN37OrgFreedesktopDBusPropertiesInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN37OrgFreedesktopDBusPropertiesInterfaceE_t>.metaTypes,
    nullptr
} };

void OrgFreedesktopDBusPropertiesInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<OrgFreedesktopDBusPropertiesInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->PropertiesChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariantMap>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[3]))); break;
        case 1: { QDBusPendingReply<QDBusVariant> _r = _t->Get((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QDBusVariant>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<QVariantMap> _r = _t->GetAll((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QVariantMap>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<> _r = _t->Set((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QDBusVariant>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusVariant >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (OrgFreedesktopDBusPropertiesInterface::*)(const QString & , const QVariantMap & , const QStringList & )>(_a, &OrgFreedesktopDBusPropertiesInterface::PropertiesChanged, 0))
            return;
    }
}

const QMetaObject *OrgFreedesktopDBusPropertiesInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrgFreedesktopDBusPropertiesInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN37OrgFreedesktopDBusPropertiesInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgFreedesktopDBusPropertiesInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void OrgFreedesktopDBusPropertiesInterface::PropertiesChanged(const QString & _t1, const QVariantMap & _t2, const QStringList & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
