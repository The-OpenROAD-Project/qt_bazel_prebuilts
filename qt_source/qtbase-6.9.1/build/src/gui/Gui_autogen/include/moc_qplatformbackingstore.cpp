/****************************************************************************
** Meta object code from reading C++ file 'qplatformbackingstore.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/painting/qplatformbackingstore.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qplatformbackingstore.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN30QPlatformBackingStoreRhiConfigE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformBackingStoreRhiConfig::qt_create_metaobjectdata<qt_meta_tag_ZN30QPlatformBackingStoreRhiConfigE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformBackingStoreRhiConfig",
        "Api",
        "OpenGL",
        "Metal",
        "Vulkan",
        "D3D11",
        "D3D12",
        "Null"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Api'
        QtMocHelpers::EnumData<Api>(1, 1, QMC::EnumFlags{}).add({
            {    2, Api::OpenGL },
            {    3, Api::Metal },
            {    4, Api::Vulkan },
            {    5, Api::D3D11 },
            {    6, Api::D3D12 },
            {    7, Api::Null },
        }),
    };
    return QtMocHelpers::metaObjectData<QPlatformBackingStoreRhiConfig, qt_meta_tag_ZN30QPlatformBackingStoreRhiConfigE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformBackingStoreRhiConfig::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN30QPlatformBackingStoreRhiConfigE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN30QPlatformBackingStoreRhiConfigE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN30QPlatformBackingStoreRhiConfigE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN20QPlatformTextureListE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformTextureList::qt_create_metaobjectdata<qt_meta_tag_ZN20QPlatformTextureListE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformTextureList",
        "locked",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'locked'
        QtMocHelpers::SignalData<void(bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPlatformTextureList, qt_meta_tag_ZN20QPlatformTextureListE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformTextureList::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QPlatformTextureListE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QPlatformTextureListE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20QPlatformTextureListE_t>.metaTypes,
    nullptr
} };

void QPlatformTextureList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformTextureList *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->locked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformTextureList::*)(bool )>(_a, &QPlatformTextureList::locked, 0))
            return;
    }
}

const QMetaObject *QPlatformTextureList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformTextureList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QPlatformTextureListE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPlatformTextureList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QPlatformTextureList::locked(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
