/****************************************************************************
** Meta object code from reading C++ file 'qdbusplatformmenu_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/platform/unix/dbusmenu/qdbusplatformmenu_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbusplatformmenu_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21QDBusPlatformMenuItemE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusPlatformMenuItem::qt_create_metaobjectdata<qt_meta_tag_ZN21QDBusPlatformMenuItemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusPlatformMenuItem"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDBusPlatformMenuItem, qt_meta_tag_ZN21QDBusPlatformMenuItemE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusPlatformMenuItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformMenuItem::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QDBusPlatformMenuItemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QDBusPlatformMenuItemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QDBusPlatformMenuItemE_t>.metaTypes,
    nullptr
} };

void QDBusPlatformMenuItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusPlatformMenuItem *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QDBusPlatformMenuItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusPlatformMenuItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QDBusPlatformMenuItemE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformMenuItem::qt_metacast(_clname);
}

int QDBusPlatformMenuItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformMenuItem::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN17QDBusPlatformMenuE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusPlatformMenu::qt_create_metaobjectdata<qt_meta_tag_ZN17QDBusPlatformMenuE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusPlatformMenu",
        "updated",
        "",
        "revision",
        "dbusId",
        "propertiesUpdated",
        "QDBusMenuItemList",
        "updatedProps",
        "QDBusMenuItemKeysList",
        "removedProps",
        "popupRequested",
        "id",
        "timestamp"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'updated'
        QtMocHelpers::SignalData<void(uint, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::UInt, 3 }, { QMetaType::Int, 4 },
        }}),
        // Signal 'propertiesUpdated'
        QtMocHelpers::SignalData<void(QDBusMenuItemList, QDBusMenuItemKeysList)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 }, { 0x80000000 | 8, 9 },
        }}),
        // Signal 'popupRequested'
        QtMocHelpers::SignalData<void(int, uint)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 }, { QMetaType::UInt, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDBusPlatformMenu, qt_meta_tag_ZN17QDBusPlatformMenuE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusPlatformMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformMenu::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QDBusPlatformMenuE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QDBusPlatformMenuE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QDBusPlatformMenuE_t>.metaTypes,
    nullptr
} };

void QDBusPlatformMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusPlatformMenu *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->updated((*reinterpret_cast< std::add_pointer_t<uint>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->propertiesUpdated((*reinterpret_cast< std::add_pointer_t<QDBusMenuItemList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDBusMenuItemKeysList>>(_a[2]))); break;
        case 2: _t->popupRequested((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<uint>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusMenuItemKeysList >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusMenuItemList >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDBusPlatformMenu::*)(uint , int )>(_a, &QDBusPlatformMenu::updated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusPlatformMenu::*)(QDBusMenuItemList , QDBusMenuItemKeysList )>(_a, &QDBusPlatformMenu::propertiesUpdated, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDBusPlatformMenu::*)(int , uint )>(_a, &QDBusPlatformMenu::popupRequested, 2))
            return;
    }
}

const QMetaObject *QDBusPlatformMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusPlatformMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QDBusPlatformMenuE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformMenu::qt_metacast(_clname);
}

int QDBusPlatformMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QDBusPlatformMenu::updated(uint _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QDBusPlatformMenu::propertiesUpdated(QDBusMenuItemList _t1, QDBusMenuItemKeysList _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QDBusPlatformMenu::popupRequested(int _t1, uint _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}
QT_WARNING_POP
