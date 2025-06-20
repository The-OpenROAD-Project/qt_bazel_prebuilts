/****************************************************************************
** Meta object code from reading C++ file 'qxcbeventdispatcher.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/platforms/xcb/qxcbeventdispatcher.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxcbeventdispatcher.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN23QXcbUnixEventDispatcherE_t {};
} // unnamed namespace

template <> constexpr inline auto QXcbUnixEventDispatcher::qt_create_metaobjectdata<qt_meta_tag_ZN23QXcbUnixEventDispatcherE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QXcbUnixEventDispatcher"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QXcbUnixEventDispatcher, qt_meta_tag_ZN23QXcbUnixEventDispatcherE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QXcbUnixEventDispatcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QEventDispatcherUNIX::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QXcbUnixEventDispatcherE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QXcbUnixEventDispatcherE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23QXcbUnixEventDispatcherE_t>.metaTypes,
    nullptr
} };

void QXcbUnixEventDispatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QXcbUnixEventDispatcher *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QXcbUnixEventDispatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXcbUnixEventDispatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QXcbUnixEventDispatcherE_t>.strings))
        return static_cast<void*>(this);
    return QEventDispatcherUNIX::qt_metacast(_clname);
}

int QXcbUnixEventDispatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QEventDispatcherUNIX::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN23QXcbGlibEventDispatcherE_t {};
} // unnamed namespace

template <> constexpr inline auto QXcbGlibEventDispatcher::qt_create_metaobjectdata<qt_meta_tag_ZN23QXcbGlibEventDispatcherE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QXcbGlibEventDispatcher"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QXcbGlibEventDispatcher, qt_meta_tag_ZN23QXcbGlibEventDispatcherE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QXcbGlibEventDispatcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QEventDispatcherGlib::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QXcbGlibEventDispatcherE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QXcbGlibEventDispatcherE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23QXcbGlibEventDispatcherE_t>.metaTypes,
    nullptr
} };

void QXcbGlibEventDispatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QXcbGlibEventDispatcher *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QXcbGlibEventDispatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXcbGlibEventDispatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QXcbGlibEventDispatcherE_t>.strings))
        return static_cast<void*>(this);
    return QEventDispatcherGlib::qt_metacast(_clname);
}

int QXcbGlibEventDispatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QEventDispatcherGlib::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
