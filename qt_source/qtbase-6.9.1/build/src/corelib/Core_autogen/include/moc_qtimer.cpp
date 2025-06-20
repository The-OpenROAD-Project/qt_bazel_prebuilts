/****************************************************************************
** Meta object code from reading C++ file 'qtimer.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/kernel/qtimer.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtimer.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6QTimerE_t {};
} // unnamed namespace

template <> constexpr inline auto QTimer::qt_create_metaobjectdata<qt_meta_tag_ZN6QTimerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTimer",
        "timeout",
        "",
        "start",
        "msec",
        "stop",
        "singleShot",
        "interval",
        "remainingTime",
        "timerType",
        "Qt::TimerType",
        "active"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'timeout'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'start'
        QtMocHelpers::SlotData<void(int)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'singleShot'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'interval'
        QtMocHelpers::PropertyData<int>(7, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'remainingTime'
        QtMocHelpers::PropertyData<int>(8, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'timerType'
        QtMocHelpers::PropertyData<Qt::TimerType>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable),
        // property 'active'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Bindable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTimer, qt_meta_tag_ZN6QTimerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTimer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6QTimerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6QTimerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6QTimerE_t>.metaTypes,
    nullptr
} };

void QTimer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTimer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->timeout(QPrivateSignal()); break;
        case 1: _t->start((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->start(); break;
        case 3: _t->stop(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTimer::*)(QPrivateSignal)>(_a, &QTimer::timeout, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isSingleShot(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->interval(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->remainingTime(); break;
        case 3: *reinterpret_cast<Qt::TimerType*>(_v) = _t->timerType(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isActive(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSingleShot(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setInterval(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setTimerType(*reinterpret_cast<Qt::TimerType*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableSingleShot(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableInterval(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTimerType(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableActive(); break;
        default: break;
        }
    }
}

const QMetaObject *QTimer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTimer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6QTimerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QTimer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QTimer::timeout(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
