/****************************************************************************
** Meta object code from reading C++ file 'qabstractanimation.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/animation/qabstractanimation.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractanimation.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QAbstractAnimationE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractAnimation::qt_create_metaobjectdata<qt_meta_tag_ZN18QAbstractAnimationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractAnimation",
        "finished",
        "",
        "stateChanged",
        "QAbstractAnimation::State",
        "newState",
        "oldState",
        "currentLoopChanged",
        "currentLoop",
        "directionChanged",
        "QAbstractAnimation::Direction",
        "start",
        "QAbstractAnimation::DeletionPolicy",
        "policy",
        "pause",
        "resume",
        "setPaused",
        "stop",
        "setCurrentTime",
        "msecs",
        "state",
        "State",
        "loopCount",
        "currentTime",
        "direction",
        "Direction",
        "duration",
        "Forward",
        "Backward",
        "Stopped",
        "Paused",
        "Running"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(QAbstractAnimation::State, QAbstractAnimation::State)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 }, { 0x80000000 | 4, 6 },
        }}),
        // Signal 'currentLoopChanged'
        QtMocHelpers::SignalData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Signal 'directionChanged'
        QtMocHelpers::SignalData<void(QAbstractAnimation::Direction)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 2 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(QAbstractAnimation::DeletionPolicy)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'pause'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resume'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setPaused'
        QtMocHelpers::SlotData<void(bool)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCurrentTime'
        QtMocHelpers::SlotData<void(int)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 19 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'state'
        QtMocHelpers::PropertyData<State>(20, 0x80000000 | 21, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 1),
        // property 'loopCount'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'currentTime'
        QtMocHelpers::PropertyData<int>(23, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'currentLoop'
        QtMocHelpers::PropertyData<int>(8, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Bindable, 2),
        // property 'direction'
        QtMocHelpers::PropertyData<Direction>(24, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 3),
        // property 'duration'
        QtMocHelpers::PropertyData<int>(26, QMetaType::Int, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Direction'
        QtMocHelpers::EnumData<Direction>(25, 25, QMC::EnumFlags{}).add({
            {   27, Direction::Forward },
            {   28, Direction::Backward },
        }),
        // enum 'State'
        QtMocHelpers::EnumData<State>(21, 21, QMC::EnumFlags{}).add({
            {   29, State::Stopped },
            {   30, State::Paused },
            {   31, State::Running },
        }),
    };
    return QtMocHelpers::metaObjectData<QAbstractAnimation, qt_meta_tag_ZN18QAbstractAnimationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractAnimation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractAnimationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractAnimationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QAbstractAnimationE_t>.metaTypes,
    nullptr
} };

void QAbstractAnimation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractAnimation *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QAbstractAnimation::State>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractAnimation::State>>(_a[2]))); break;
        case 2: _t->currentLoopChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->directionChanged((*reinterpret_cast< std::add_pointer_t<QAbstractAnimation::Direction>>(_a[1]))); break;
        case 4: _t->start((*reinterpret_cast< std::add_pointer_t<QAbstractAnimation::DeletionPolicy>>(_a[1]))); break;
        case 5: _t->start(); break;
        case 6: _t->pause(); break;
        case 7: _t->resume(); break;
        case 8: _t->setPaused((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->stop(); break;
        case 10: _t->setCurrentTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractAnimation::*)()>(_a, &QAbstractAnimation::finished, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractAnimation::*)(QAbstractAnimation::State , QAbstractAnimation::State )>(_a, &QAbstractAnimation::stateChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractAnimation::*)(int )>(_a, &QAbstractAnimation::currentLoopChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractAnimation::*)(QAbstractAnimation::Direction )>(_a, &QAbstractAnimation::directionChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<State*>(_v) = _t->state(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->loopCount(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->currentTime(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->currentLoop(); break;
        case 4: *reinterpret_cast<Direction*>(_v) = _t->direction(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->duration(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setLoopCount(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setCurrentTime(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setDirection(*reinterpret_cast<Direction*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableState(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableLoopCount(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCurrentTime(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCurrentLoop(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableDirection(); break;
        default: break;
        }
    }
}

const QMetaObject *QAbstractAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractAnimationE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QAbstractAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QAbstractAnimation::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QAbstractAnimation::stateChanged(QAbstractAnimation::State _t1, QAbstractAnimation::State _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QAbstractAnimation::currentLoopChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QAbstractAnimation::directionChanged(QAbstractAnimation::Direction _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN16QAnimationDriverE_t {};
} // unnamed namespace

template <> constexpr inline auto QAnimationDriver::qt_create_metaobjectdata<qt_meta_tag_ZN16QAnimationDriverE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAnimationDriver",
        "started",
        "",
        "stopped"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stopped'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAnimationDriver, qt_meta_tag_ZN16QAnimationDriverE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAnimationDriver::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QAnimationDriverE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QAnimationDriverE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QAnimationDriverE_t>.metaTypes,
    nullptr
} };

void QAnimationDriver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAnimationDriver *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->stopped(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAnimationDriver::*)()>(_a, &QAnimationDriver::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAnimationDriver::*)()>(_a, &QAnimationDriver::stopped, 1))
            return;
    }
}

const QMetaObject *QAnimationDriver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAnimationDriver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QAnimationDriverE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QAnimationDriver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QAnimationDriver::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QAnimationDriver::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
