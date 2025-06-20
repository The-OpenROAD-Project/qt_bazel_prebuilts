/****************************************************************************
** Meta object code from reading C++ file 'qfuturewatcher.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/thread/qfuturewatcher.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfuturewatcher.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QFutureWatcherBaseE_t {};
} // unnamed namespace

template <> constexpr inline auto QFutureWatcherBase::qt_create_metaobjectdata<qt_meta_tag_ZN18QFutureWatcherBaseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFutureWatcherBase",
        "started",
        "",
        "finished",
        "canceled",
        "paused",
        "suspending",
        "suspended",
        "resumed",
        "resultReadyAt",
        "resultIndex",
        "resultsReadyAt",
        "beginIndex",
        "endIndex",
        "progressRangeChanged",
        "minimum",
        "maximum",
        "progressValueChanged",
        "progressValue",
        "progressTextChanged",
        "progressText",
        "cancel",
        "setSuspended",
        "suspend",
        "resume",
        "toggleSuspended",
        "setPaused",
        "pause",
        "togglePaused"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'canceled'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'paused'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'suspending'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'suspended'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resumed'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resultReadyAt'
        QtMocHelpers::SignalData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 10 },
        }}),
        // Signal 'resultsReadyAt'
        QtMocHelpers::SignalData<void(int, int)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 12 }, { QMetaType::Int, 13 },
        }}),
        // Signal 'progressRangeChanged'
        QtMocHelpers::SignalData<void(int, int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Signal 'progressValueChanged'
        QtMocHelpers::SignalData<void(int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 18 },
        }}),
        // Signal 'progressTextChanged'
        QtMocHelpers::SignalData<void(const QString &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 20 },
        }}),
        // Slot 'cancel'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSuspended'
        QtMocHelpers::SlotData<void(bool)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 23 },
        }}),
        // Slot 'suspend'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resume'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggleSuspended'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setPaused'
        QtMocHelpers::SlotData<void(bool)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 },
        }}),
        // Slot 'pause'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'togglePaused'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QFutureWatcherBase, qt_meta_tag_ZN18QFutureWatcherBaseE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFutureWatcherBase::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QFutureWatcherBaseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QFutureWatcherBaseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QFutureWatcherBaseE_t>.metaTypes,
    nullptr
} };

void QFutureWatcherBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QFutureWatcherBase *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->finished(); break;
        case 2: _t->canceled(); break;
        case 3: _t->paused(); break;
        case 4: _t->suspending(); break;
        case 5: _t->suspended(); break;
        case 6: _t->resumed(); break;
        case 7: _t->resultReadyAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->resultsReadyAt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->progressRangeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->progressValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->progressTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->cancel(); break;
        case 13: _t->setSuspended((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->suspend(); break;
        case 15: _t->resume(); break;
        case 16: _t->toggleSuspended(); break;
        case 17: _t->setPaused((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 18: _t->pause(); break;
        case 19: _t->togglePaused(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)()>(_a, &QFutureWatcherBase::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)()>(_a, &QFutureWatcherBase::finished, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)()>(_a, &QFutureWatcherBase::canceled, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)()>(_a, &QFutureWatcherBase::paused, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)()>(_a, &QFutureWatcherBase::suspending, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)()>(_a, &QFutureWatcherBase::suspended, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)()>(_a, &QFutureWatcherBase::resumed, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)(int )>(_a, &QFutureWatcherBase::resultReadyAt, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)(int , int )>(_a, &QFutureWatcherBase::resultsReadyAt, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)(int , int )>(_a, &QFutureWatcherBase::progressRangeChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)(int )>(_a, &QFutureWatcherBase::progressValueChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFutureWatcherBase::*)(const QString & )>(_a, &QFutureWatcherBase::progressTextChanged, 11))
            return;
    }
}

const QMetaObject *QFutureWatcherBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFutureWatcherBase::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QFutureWatcherBaseE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QFutureWatcherBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void QFutureWatcherBase::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QFutureWatcherBase::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QFutureWatcherBase::canceled()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QFutureWatcherBase::paused()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QFutureWatcherBase::suspending()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QFutureWatcherBase::suspended()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QFutureWatcherBase::resumed()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QFutureWatcherBase::resultReadyAt(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QFutureWatcherBase::resultsReadyAt(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2);
}

// SIGNAL 9
void QFutureWatcherBase::progressRangeChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2);
}

// SIGNAL 10
void QFutureWatcherBase::progressValueChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void QFutureWatcherBase::progressTextChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}
QT_WARNING_POP
