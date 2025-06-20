/****************************************************************************
** Meta object code from reading C++ file 'qspidbuscache_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/accessible/linux/qspidbuscache_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qspidbuscache_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QSpiDBusCacheE_t {};
} // unnamed namespace

template <> constexpr inline auto QSpiDBusCache::qt_create_metaobjectdata<qt_meta_tag_ZN13QSpiDBusCacheE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSpiDBusCache",
        "AddAccessible",
        "",
        "QSpiAccessibleCacheItem",
        "nodeAdded",
        "RemoveAccessible",
        "QSpiObjectReference",
        "nodeRemoved",
        "GetItems",
        "QSpiAccessibleCacheArray"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'AddAccessible'
        QtMocHelpers::SignalData<void(const QSpiAccessibleCacheItem &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'RemoveAccessible'
        QtMocHelpers::SignalData<void(const QSpiObjectReference &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Slot 'GetItems'
        QtMocHelpers::SlotData<QSpiAccessibleCacheArray()>(8, 2, QMC::AccessPublic, 0x80000000 | 9),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSpiDBusCache, qt_meta_tag_ZN13QSpiDBusCacheE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSpiDBusCache::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSpiDBusCacheE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSpiDBusCacheE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QSpiDBusCacheE_t>.metaTypes,
    nullptr
} };

void QSpiDBusCache::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSpiDBusCache *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->AddAccessible((*reinterpret_cast< std::add_pointer_t<QSpiAccessibleCacheItem>>(_a[1]))); break;
        case 1: _t->RemoveAccessible((*reinterpret_cast< std::add_pointer_t<QSpiObjectReference>>(_a[1]))); break;
        case 2: { QSpiAccessibleCacheArray _r = _t->GetItems();
            if (_a[0]) *reinterpret_cast< QSpiAccessibleCacheArray*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSpiAccessibleCacheItem >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSpiObjectReference >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QSpiDBusCache::*)(const QSpiAccessibleCacheItem & )>(_a, &QSpiDBusCache::AddAccessible, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSpiDBusCache::*)(const QSpiObjectReference & )>(_a, &QSpiDBusCache::RemoveAccessible, 1))
            return;
    }
}

const QMetaObject *QSpiDBusCache::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSpiDBusCache::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSpiDBusCacheE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSpiDBusCache::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QSpiDBusCache::AddAccessible(const QSpiAccessibleCacheItem & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QSpiDBusCache::RemoveAccessible(const QSpiObjectReference & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
