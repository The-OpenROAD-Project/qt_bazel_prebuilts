/****************************************************************************
** Meta object code from reading C++ file 'tasktree.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/assets/downloader/tasking/tasktree.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tasktree.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7Tasking13TaskInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto Tasking::TaskInterface::qt_create_metaobjectdata<qt_meta_tag_ZN7Tasking13TaskInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Tasking::TaskInterface",
        "done",
        "",
        "DoneResult",
        "result"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'done'
        QtMocHelpers::SignalData<void(DoneResult)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<TaskInterface, qt_meta_tag_ZN7Tasking13TaskInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Tasking::TaskInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking13TaskInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking13TaskInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7Tasking13TaskInterfaceE_t>.metaTypes,
    nullptr
} };

void Tasking::TaskInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TaskInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->done((*reinterpret_cast< std::add_pointer_t<DoneResult>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (TaskInterface::*)(DoneResult )>(_a, &TaskInterface::done, 0))
            return;
    }
}

const QMetaObject *Tasking::TaskInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tasking::TaskInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking13TaskInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tasking::TaskInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Tasking::TaskInterface::done(DoneResult _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN7Tasking8TaskTreeE_t {};
} // unnamed namespace

template <> constexpr inline auto Tasking::TaskTree::qt_create_metaobjectdata<qt_meta_tag_ZN7Tasking8TaskTreeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Tasking::TaskTree",
        "started",
        "",
        "done",
        "DoneWith",
        "result",
        "asyncCountChanged",
        "count",
        "progressValueChanged",
        "value"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'done'
        QtMocHelpers::SignalData<void(DoneWith)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'asyncCountChanged'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Signal 'progressValueChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<TaskTree, qt_meta_tag_ZN7Tasking8TaskTreeE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Tasking::TaskTree::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking8TaskTreeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking8TaskTreeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7Tasking8TaskTreeE_t>.metaTypes,
    nullptr
} };

void Tasking::TaskTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TaskTree *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->done((*reinterpret_cast< std::add_pointer_t<DoneWith>>(_a[1]))); break;
        case 2: _t->asyncCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->progressValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (TaskTree::*)()>(_a, &TaskTree::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (TaskTree::*)(DoneWith )>(_a, &TaskTree::done, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (TaskTree::*)(int )>(_a, &TaskTree::asyncCountChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (TaskTree::*)(int )>(_a, &TaskTree::progressValueChanged, 3))
            return;
    }
}

const QMetaObject *Tasking::TaskTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tasking::TaskTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7Tasking8TaskTreeE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Tasking::TaskTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void Tasking::TaskTree::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Tasking::TaskTree::done(DoneWith _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Tasking::TaskTree::asyncCountChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Tasking::TaskTree::progressValueChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN7TaskingE_t {};
} // unnamed namespace

template <> constexpr inline auto Tasking::qt_create_metaobjectdata<qt_meta_tag_ZN7TaskingE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Tasking",
        "WorkflowPolicy",
        "StopOnError",
        "ContinueOnError",
        "StopOnSuccess",
        "ContinueOnSuccess",
        "StopOnSuccessOrError",
        "FinishAllAndSuccess",
        "FinishAllAndError",
        "SetupResult",
        "Continue",
        "StopWithSuccess",
        "StopWithError",
        "DoneResult",
        "Success",
        "Error",
        "DoneWith",
        "Cancel",
        "CallDoneIf",
        "SuccessOrError"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'WorkflowPolicy'
        QtMocHelpers::EnumData<WorkflowPolicy>(1, 1, QMC::EnumIsScoped).add({
            {    2, WorkflowPolicy::StopOnError },
            {    3, WorkflowPolicy::ContinueOnError },
            {    4, WorkflowPolicy::StopOnSuccess },
            {    5, WorkflowPolicy::ContinueOnSuccess },
            {    6, WorkflowPolicy::StopOnSuccessOrError },
            {    7, WorkflowPolicy::FinishAllAndSuccess },
            {    8, WorkflowPolicy::FinishAllAndError },
        }),
        // enum 'SetupResult'
        QtMocHelpers::EnumData<SetupResult>(9, 9, QMC::EnumIsScoped).add({
            {   10, SetupResult::Continue },
            {   11, SetupResult::StopWithSuccess },
            {   12, SetupResult::StopWithError },
        }),
        // enum 'DoneResult'
        QtMocHelpers::EnumData<DoneResult>(13, 13, QMC::EnumIsScoped).add({
            {   14, DoneResult::Success },
            {   15, DoneResult::Error },
        }),
        // enum 'DoneWith'
        QtMocHelpers::EnumData<DoneWith>(16, 16, QMC::EnumIsScoped).add({
            {   14, DoneWith::Success },
            {   15, DoneWith::Error },
            {   17, DoneWith::Cancel },
        }),
        // enum 'CallDoneIf'
        QtMocHelpers::EnumData<CallDoneIf>(18, 18, QMC::EnumIsScoped).add({
            {   19, CallDoneIf::SuccessOrError },
            {   14, CallDoneIf::Success },
            {   15, CallDoneIf::Error },
        }),
    };
    return QtMocHelpers::metaObjectData<void, qt_meta_tag_ZN7TaskingE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}

static constexpr auto qt_staticMetaObjectContent_ZN7TaskingE =
    Tasking::qt_create_metaobjectdata<qt_meta_tag_ZN7TaskingE_t>();
static constexpr auto qt_staticMetaObjectStaticContent_ZN7TaskingE =
    qt_staticMetaObjectContent_ZN7TaskingE.staticData;
static constexpr auto qt_staticMetaObjectRelocatingContent_ZN7TaskingE =
    qt_staticMetaObjectContent_ZN7TaskingE.relocatingData;

Q_CONSTINIT const QMetaObject Tasking::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent_ZN7TaskingE.stringdata,
    qt_staticMetaObjectStaticContent_ZN7TaskingE.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent_ZN7TaskingE.metaTypes,
    nullptr
} };

QT_WARNING_POP
