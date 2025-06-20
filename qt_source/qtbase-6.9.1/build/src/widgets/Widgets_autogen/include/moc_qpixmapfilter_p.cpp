/****************************************************************************
** Meta object code from reading C++ file 'qpixmapfilter_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/effects/qpixmapfilter_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpixmapfilter_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QPixmapFilterE_t {};
} // unnamed namespace

template <> constexpr inline auto QPixmapFilter::qt_create_metaobjectdata<qt_meta_tag_ZN13QPixmapFilterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPixmapFilter"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPixmapFilter, qt_meta_tag_ZN13QPixmapFilterE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPixmapFilter::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPixmapFilterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPixmapFilterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QPixmapFilterE_t>.metaTypes,
    nullptr
} };

void QPixmapFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPixmapFilter *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QPixmapFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPixmapFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPixmapFilterE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPixmapFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN24QPixmapConvolutionFilterE_t {};
} // unnamed namespace

template <> constexpr inline auto QPixmapConvolutionFilter::qt_create_metaobjectdata<qt_meta_tag_ZN24QPixmapConvolutionFilterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPixmapConvolutionFilter"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPixmapConvolutionFilter, qt_meta_tag_ZN24QPixmapConvolutionFilterE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPixmapConvolutionFilter::staticMetaObject = { {
    QMetaObject::SuperData::link<QPixmapFilter::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QPixmapConvolutionFilterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QPixmapConvolutionFilterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24QPixmapConvolutionFilterE_t>.metaTypes,
    nullptr
} };

void QPixmapConvolutionFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPixmapConvolutionFilter *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QPixmapConvolutionFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPixmapConvolutionFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QPixmapConvolutionFilterE_t>.strings))
        return static_cast<void*>(this);
    return QPixmapFilter::qt_metacast(_clname);
}

int QPixmapConvolutionFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPixmapFilter::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN17QPixmapBlurFilterE_t {};
} // unnamed namespace

template <> constexpr inline auto QPixmapBlurFilter::qt_create_metaobjectdata<qt_meta_tag_ZN17QPixmapBlurFilterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPixmapBlurFilter"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPixmapBlurFilter, qt_meta_tag_ZN17QPixmapBlurFilterE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPixmapBlurFilter::staticMetaObject = { {
    QMetaObject::SuperData::link<QPixmapFilter::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QPixmapBlurFilterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QPixmapBlurFilterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QPixmapBlurFilterE_t>.metaTypes,
    nullptr
} };

void QPixmapBlurFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPixmapBlurFilter *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QPixmapBlurFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPixmapBlurFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QPixmapBlurFilterE_t>.strings))
        return static_cast<void*>(this);
    return QPixmapFilter::qt_metacast(_clname);
}

int QPixmapBlurFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPixmapFilter::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN21QPixmapColorizeFilterE_t {};
} // unnamed namespace

template <> constexpr inline auto QPixmapColorizeFilter::qt_create_metaobjectdata<qt_meta_tag_ZN21QPixmapColorizeFilterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPixmapColorizeFilter"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPixmapColorizeFilter, qt_meta_tag_ZN21QPixmapColorizeFilterE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPixmapColorizeFilter::staticMetaObject = { {
    QMetaObject::SuperData::link<QPixmapFilter::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QPixmapColorizeFilterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QPixmapColorizeFilterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QPixmapColorizeFilterE_t>.metaTypes,
    nullptr
} };

void QPixmapColorizeFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPixmapColorizeFilter *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QPixmapColorizeFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPixmapColorizeFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QPixmapColorizeFilterE_t>.strings))
        return static_cast<void*>(this);
    return QPixmapFilter::qt_metacast(_clname);
}

int QPixmapColorizeFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPixmapFilter::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN23QPixmapDropShadowFilterE_t {};
} // unnamed namespace

template <> constexpr inline auto QPixmapDropShadowFilter::qt_create_metaobjectdata<qt_meta_tag_ZN23QPixmapDropShadowFilterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPixmapDropShadowFilter"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPixmapDropShadowFilter, qt_meta_tag_ZN23QPixmapDropShadowFilterE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPixmapDropShadowFilter::staticMetaObject = { {
    QMetaObject::SuperData::link<QPixmapFilter::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QPixmapDropShadowFilterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QPixmapDropShadowFilterE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23QPixmapDropShadowFilterE_t>.metaTypes,
    nullptr
} };

void QPixmapDropShadowFilter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPixmapDropShadowFilter *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QPixmapDropShadowFilter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPixmapDropShadowFilter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QPixmapDropShadowFilterE_t>.strings))
        return static_cast<void*>(this);
    return QPixmapFilter::qt_metacast(_clname);
}

int QPixmapDropShadowFilter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPixmapFilter::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
