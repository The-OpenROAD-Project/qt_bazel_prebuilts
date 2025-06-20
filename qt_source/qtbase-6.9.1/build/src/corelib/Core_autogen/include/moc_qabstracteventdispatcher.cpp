/****************************************************************************
** Meta object code from reading C++ file 'qabstracteventdispatcher.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/kernel/qabstracteventdispatcher.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstracteventdispatcher.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN24QAbstractEventDispatcherE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractEventDispatcher::qt_create_metaobjectdata<qt_meta_tag_ZN24QAbstractEventDispatcherE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractEventDispatcher",
        "aboutToBlock",
        "",
        "awake"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'aboutToBlock'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'awake'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractEventDispatcher, qt_meta_tag_ZN24QAbstractEventDispatcherE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractEventDispatcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QAbstractEventDispatcherE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QAbstractEventDispatcherE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24QAbstractEventDispatcherE_t>.metaTypes,
    nullptr
} };

void QAbstractEventDispatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractEventDispatcher *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->aboutToBlock(); break;
        case 1: _t->awake(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractEventDispatcher::*)()>(_a, &QAbstractEventDispatcher::aboutToBlock, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractEventDispatcher::*)()>(_a, &QAbstractEventDispatcher::awake, 1))
            return;
    }
}

const QMetaObject *QAbstractEventDispatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractEventDispatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QAbstractEventDispatcherE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QAbstractEventDispatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void QAbstractEventDispatcher::aboutToBlock()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QAbstractEventDispatcher::awake()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN26QAbstractEventDispatcherV2E_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractEventDispatcherV2::qt_create_metaobjectdata<qt_meta_tag_ZN26QAbstractEventDispatcherV2E_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractEventDispatcherV2"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractEventDispatcherV2, qt_meta_tag_ZN26QAbstractEventDispatcherV2E_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractEventDispatcherV2::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractEventDispatcher::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QAbstractEventDispatcherV2E_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QAbstractEventDispatcherV2E_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN26QAbstractEventDispatcherV2E_t>.metaTypes,
    nullptr
} };

void QAbstractEventDispatcherV2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractEventDispatcherV2 *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QAbstractEventDispatcherV2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractEventDispatcherV2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QAbstractEventDispatcherV2E_t>.strings))
        return static_cast<void*>(this);
    return QAbstractEventDispatcher::qt_metacast(_clname);
}

int QAbstractEventDispatcherV2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractEventDispatcher::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
