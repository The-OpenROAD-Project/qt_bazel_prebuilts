/****************************************************************************
** Meta object code from reading C++ file 'qtimeline.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/tools/qtimeline.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtimeline.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QTimeLineE_t {};
} // unnamed namespace

template <> constexpr inline auto QTimeLine::qt_create_metaobjectdata<qt_meta_tag_ZN9QTimeLineE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTimeLine",
        "valueChanged",
        "",
        "x",
        "frameChanged",
        "stateChanged",
        "QTimeLine::State",
        "newState",
        "finished",
        "start",
        "resume",
        "stop",
        "setPaused",
        "paused",
        "setCurrentTime",
        "msec",
        "toggleDirection",
        "duration",
        "updateInterval",
        "currentTime",
        "direction",
        "Direction",
        "loopCount",
        "easingCurve",
        "QEasingCurve"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'valueChanged'
        QtMocHelpers::SignalData<void(qreal)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 3 },
        }}),
        // Signal 'frameChanged'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(QTimeLine::State)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 7 },
        }}),
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'start'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resume'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setPaused'
        QtMocHelpers::SlotData<void(bool)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 13 },
        }}),
        // Slot 'setCurrentTime'
        QtMocHelpers::SlotData<void(int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 },
        }}),
        // Slot 'toggleDirection'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'duration'
        QtMocHelpers::PropertyData<int>(17, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'updateInterval'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'currentTime'
        QtMocHelpers::PropertyData<int>(19, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'direction'
        QtMocHelpers::PropertyData<Direction>(20, 0x80000000 | 21, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable),
        // property 'loopCount'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'easingCurve'
        QtMocHelpers::PropertyData<QEasingCurve>(23, 0x80000000 | 24, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTimeLine, qt_meta_tag_ZN9QTimeLineE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTimeLine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTimeLineE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTimeLineE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QTimeLineE_t>.metaTypes,
    nullptr
} };

void QTimeLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTimeLine *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1])), QPrivateSignal()); break;
        case 1: _t->frameChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])), QPrivateSignal()); break;
        case 2: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QTimeLine::State>>(_a[1])), QPrivateSignal()); break;
        case 3: _t->finished(QPrivateSignal()); break;
        case 4: _t->start(); break;
        case 5: _t->resume(); break;
        case 6: _t->stop(); break;
        case 7: _t->setPaused((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->setCurrentTime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->toggleDirection(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTimeLine::*)(qreal , QPrivateSignal)>(_a, &QTimeLine::valueChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTimeLine::*)(int , QPrivateSignal)>(_a, &QTimeLine::frameChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTimeLine::*)(QTimeLine::State , QPrivateSignal)>(_a, &QTimeLine::stateChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTimeLine::*)(QPrivateSignal)>(_a, &QTimeLine::finished, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->duration(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->updateInterval(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->currentTime(); break;
        case 3: *reinterpret_cast<Direction*>(_v) = _t->direction(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->loopCount(); break;
        case 5: *reinterpret_cast<QEasingCurve*>(_v) = _t->easingCurve(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDuration(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setUpdateInterval(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setCurrentTime(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setDirection(*reinterpret_cast<Direction*>(_v)); break;
        case 4: _t->setLoopCount(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setEasingCurve(*reinterpret_cast<QEasingCurve*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableDuration(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableUpdateInterval(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCurrentTime(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableDirection(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableLoopCount(); break;
        case 5: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableEasingCurve(); break;
        default: break;
        }
    }
}

const QMetaObject *QTimeLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTimeLine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTimeLineE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QTimeLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
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
void QTimeLine::valueChanged(qreal _t1, QPrivateSignal _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QTimeLine::frameChanged(int _t1, QPrivateSignal _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QTimeLine::stateChanged(QTimeLine::State _t1, QPrivateSignal _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QTimeLine::finished(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
