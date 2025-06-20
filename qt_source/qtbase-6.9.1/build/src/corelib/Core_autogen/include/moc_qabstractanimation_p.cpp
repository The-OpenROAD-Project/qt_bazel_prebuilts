/****************************************************************************
** Meta object code from reading C++ file 'qabstractanimation_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/animation/qabstractanimation_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractanimation_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN23QDefaultAnimationDriverE_t {};
} // unnamed namespace

template <> constexpr inline auto QDefaultAnimationDriver::qt_create_metaobjectdata<qt_meta_tag_ZN23QDefaultAnimationDriverE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDefaultAnimationDriver",
        "startTimer",
        "",
        "stopTimer"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'startTimer'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'stopTimer'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDefaultAnimationDriver, qt_meta_tag_ZN23QDefaultAnimationDriverE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDefaultAnimationDriver::staticMetaObject = { {
    QMetaObject::SuperData::link<QAnimationDriver::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QDefaultAnimationDriverE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QDefaultAnimationDriverE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23QDefaultAnimationDriverE_t>.metaTypes,
    nullptr
} };

void QDefaultAnimationDriver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDefaultAnimationDriver *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->startTimer(); break;
        case 1: _t->stopTimer(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QDefaultAnimationDriver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDefaultAnimationDriver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QDefaultAnimationDriverE_t>.strings))
        return static_cast<void*>(this);
    return QAnimationDriver::qt_metacast(_clname);
}

int QDefaultAnimationDriver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAnimationDriver::qt_metacall(_c, _id, _a);
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
namespace {
struct qt_meta_tag_ZN23QAbstractAnimationTimerE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractAnimationTimer::qt_create_metaobjectdata<qt_meta_tag_ZN23QAbstractAnimationTimerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractAnimationTimer"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractAnimationTimer, qt_meta_tag_ZN23QAbstractAnimationTimerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractAnimationTimer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QAbstractAnimationTimerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QAbstractAnimationTimerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23QAbstractAnimationTimerE_t>.metaTypes,
    nullptr
} };

void QAbstractAnimationTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractAnimationTimer *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QAbstractAnimationTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractAnimationTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QAbstractAnimationTimerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QAbstractAnimationTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN13QUnifiedTimerE_t {};
} // unnamed namespace

template <> constexpr inline auto QUnifiedTimer::qt_create_metaobjectdata<qt_meta_tag_ZN13QUnifiedTimerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QUnifiedTimer",
        "startTimers",
        "",
        "stopTimer"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'startTimers'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'stopTimer'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QUnifiedTimer, qt_meta_tag_ZN13QUnifiedTimerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QUnifiedTimer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QUnifiedTimerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QUnifiedTimerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QUnifiedTimerE_t>.metaTypes,
    nullptr
} };

void QUnifiedTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QUnifiedTimer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->startTimers(); break;
        case 1: _t->stopTimer(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QUnifiedTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QUnifiedTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QUnifiedTimerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QUnifiedTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
namespace {
struct qt_meta_tag_ZN15QAnimationTimerE_t {};
} // unnamed namespace

template <> constexpr inline auto QAnimationTimer::qt_create_metaobjectdata<qt_meta_tag_ZN15QAnimationTimerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAnimationTimer",
        "startAnimations",
        "",
        "stopTimer"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'startAnimations'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'stopTimer'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAnimationTimer, qt_meta_tag_ZN15QAnimationTimerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAnimationTimer::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractAnimationTimer::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAnimationTimerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAnimationTimerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QAnimationTimerE_t>.metaTypes,
    nullptr
} };

void QAnimationTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAnimationTimer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->startAnimations(); break;
        case 1: _t->stopTimer(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QAnimationTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAnimationTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAnimationTimerE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractAnimationTimer::qt_metacast(_clname);
}

int QAnimationTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractAnimationTimer::qt_metacall(_c, _id, _a);
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
