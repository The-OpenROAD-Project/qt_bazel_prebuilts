/****************************************************************************
** Meta object code from reading C++ file 'qeventloop.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/kernel/qeventloop.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qeventloop.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QEventLoopE_t {};
} // unnamed namespace

template <> constexpr inline auto QEventLoop::qt_create_metaobjectdata<qt_meta_tag_ZN10QEventLoopE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QEventLoop",
        "exit",
        "",
        "returnCode",
        "quit",
        "ProcessEventsFlags",
        "ProcessEventsFlag",
        "AllEvents",
        "ExcludeUserInputEvents",
        "ExcludeSocketNotifiers",
        "WaitForMoreEvents",
        "X11ExcludeTimers",
        "EventLoopExec",
        "DialogExec",
        "ApplicationExec"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'exit'
        QtMocHelpers::SlotData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'exit'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'quit'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ProcessEventsFlags'
        QtMocHelpers::EnumData<ProcessEventsFlags>(5, 6, QMC::EnumFlags{}).add({
            {    7, ProcessEventsFlag::AllEvents },
            {    8, ProcessEventsFlag::ExcludeUserInputEvents },
            {    9, ProcessEventsFlag::ExcludeSocketNotifiers },
            {   10, ProcessEventsFlag::WaitForMoreEvents },
            {   11, ProcessEventsFlag::X11ExcludeTimers },
            {   12, ProcessEventsFlag::EventLoopExec },
            {   13, ProcessEventsFlag::DialogExec },
            {   14, ProcessEventsFlag::ApplicationExec },
        }),
    };
    return QtMocHelpers::metaObjectData<QEventLoop, qt_meta_tag_ZN10QEventLoopE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QEventLoop::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QEventLoopE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QEventLoopE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QEventLoopE_t>.metaTypes,
    nullptr
} };

void QEventLoop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QEventLoop *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->exit((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->exit(); break;
        case 2: _t->quit(); break;
        default: ;
        }
    }
}

const QMetaObject *QEventLoop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEventLoop::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QEventLoopE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEventLoop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
