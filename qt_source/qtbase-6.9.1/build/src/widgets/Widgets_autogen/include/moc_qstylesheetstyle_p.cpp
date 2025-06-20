/****************************************************************************
** Meta object code from reading C++ file 'qstylesheetstyle_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/styles/qstylesheetstyle_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstylesheetstyle_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QStyleSheetStyleE_t {};
} // unnamed namespace

template <> constexpr inline auto QStyleSheetStyle::qt_create_metaobjectdata<qt_meta_tag_ZN16QStyleSheetStyleE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QStyleSheetStyle"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QStyleSheetStyle, qt_meta_tag_ZN16QStyleSheetStyleE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QStyleSheetStyle::staticMetaObject = { {
    QMetaObject::SuperData::link<QWindowsStyle::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QStyleSheetStyleE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QStyleSheetStyleE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QStyleSheetStyleE_t>.metaTypes,
    nullptr
} };

void QStyleSheetStyle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QStyleSheetStyle *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QStyleSheetStyle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStyleSheetStyle::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QStyleSheetStyleE_t>.strings))
        return static_cast<void*>(this);
    return QWindowsStyle::qt_metacast(_clname);
}

int QStyleSheetStyle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWindowsStyle::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN22QStyleSheetStyleCachesE_t {};
} // unnamed namespace

template <> constexpr inline auto QStyleSheetStyleCaches::qt_create_metaobjectdata<qt_meta_tag_ZN22QStyleSheetStyleCachesE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QStyleSheetStyleCaches",
        "objectDestroyed",
        "",
        "styleDestroyed"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'objectDestroyed'
        QtMocHelpers::SlotData<void(QObject *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 2 },
        }}),
        // Slot 'styleDestroyed'
        QtMocHelpers::SlotData<void(QObject *)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QStyleSheetStyleCaches, qt_meta_tag_ZN22QStyleSheetStyleCachesE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QStyleSheetStyleCaches::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QStyleSheetStyleCachesE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QStyleSheetStyleCachesE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22QStyleSheetStyleCachesE_t>.metaTypes,
    nullptr
} };

void QStyleSheetStyleCaches::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QStyleSheetStyleCaches *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->objectDestroyed((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        case 1: _t->styleDestroyed((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *QStyleSheetStyleCaches::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStyleSheetStyleCaches::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QStyleSheetStyleCachesE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QStyleSheetStyleCaches::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
