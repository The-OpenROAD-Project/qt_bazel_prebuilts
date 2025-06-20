/****************************************************************************
** Meta object code from reading C++ file 'qplatformsharedgraphicscache.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qplatformsharedgraphicscache.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qplatformsharedgraphicscache.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN28QPlatformSharedGraphicsCacheE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformSharedGraphicsCache::qt_create_metaobjectdata<qt_meta_tag_ZN28QPlatformSharedGraphicsCacheE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformSharedGraphicsCache",
        "itemsMissing",
        "",
        "cacheId",
        "QList<quint32>",
        "itemIds",
        "itemsAvailable",
        "bufferId",
        "QList<QPoint>",
        "positionsInBuffer",
        "itemsInvalidated",
        "itemsUpdated"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'itemsMissing'
        QtMocHelpers::SignalData<void(const QByteArray &, const QList<quint32> &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 3 }, { 0x80000000 | 4, 5 },
        }}),
        // Signal 'itemsAvailable'
        QtMocHelpers::SignalData<void(const QByteArray &, void *, const QList<quint32> &, const QList<QPoint> &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 3 }, { QMetaType::VoidStar, 7 }, { 0x80000000 | 4, 5 }, { 0x80000000 | 8, 9 },
        }}),
        // Signal 'itemsInvalidated'
        QtMocHelpers::SignalData<void(const QByteArray &, const QList<quint32> &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 3 }, { 0x80000000 | 4, 5 },
        }}),
        // Signal 'itemsUpdated'
        QtMocHelpers::SignalData<void(const QByteArray &, void *, const QList<quint32> &, const QList<QPoint> &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 3 }, { QMetaType::VoidStar, 7 }, { 0x80000000 | 4, 5 }, { 0x80000000 | 8, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPlatformSharedGraphicsCache, qt_meta_tag_ZN28QPlatformSharedGraphicsCacheE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformSharedGraphicsCache::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QPlatformSharedGraphicsCacheE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QPlatformSharedGraphicsCacheE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN28QPlatformSharedGraphicsCacheE_t>.metaTypes,
    nullptr
} };

void QPlatformSharedGraphicsCache::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformSharedGraphicsCache *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->itemsMissing((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<quint32>>>(_a[2]))); break;
        case 1: _t->itemsAvailable((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<quint32>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QList<QPoint>>>(_a[4]))); break;
        case 2: _t->itemsInvalidated((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<quint32>>>(_a[2]))); break;
        case 3: _t->itemsUpdated((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<void*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<quint32>>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QList<QPoint>>>(_a[4]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<quint32> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QPoint> >(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<quint32> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<quint32> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 3:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QPoint> >(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<quint32> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformSharedGraphicsCache::*)(const QByteArray & , const QList<quint32> & )>(_a, &QPlatformSharedGraphicsCache::itemsMissing, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformSharedGraphicsCache::*)(const QByteArray & , void * , const QList<quint32> & , const QList<QPoint> & )>(_a, &QPlatformSharedGraphicsCache::itemsAvailable, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformSharedGraphicsCache::*)(const QByteArray & , const QList<quint32> & )>(_a, &QPlatformSharedGraphicsCache::itemsInvalidated, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformSharedGraphicsCache::*)(const QByteArray & , void * , const QList<quint32> & , const QList<QPoint> & )>(_a, &QPlatformSharedGraphicsCache::itemsUpdated, 3))
            return;
    }
}

const QMetaObject *QPlatformSharedGraphicsCache::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformSharedGraphicsCache::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QPlatformSharedGraphicsCacheE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPlatformSharedGraphicsCache::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QPlatformSharedGraphicsCache::itemsMissing(const QByteArray & _t1, const QList<quint32> & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QPlatformSharedGraphicsCache::itemsAvailable(const QByteArray & _t1, void * _t2, const QList<quint32> & _t3, const QList<QPoint> & _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 2
void QPlatformSharedGraphicsCache::itemsInvalidated(const QByteArray & _t1, const QList<quint32> & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QPlatformSharedGraphicsCache::itemsUpdated(const QByteArray & _t1, void * _t2, const QList<quint32> & _t3, const QList<QPoint> & _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2, _t3, _t4);
}
QT_WARNING_POP
