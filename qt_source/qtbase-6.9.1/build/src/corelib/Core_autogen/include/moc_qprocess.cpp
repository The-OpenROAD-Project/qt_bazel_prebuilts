/****************************************************************************
** Meta object code from reading C++ file 'qprocess.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/io/qprocess.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qprocess.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QProcessE_t {};
} // unnamed namespace

template <> constexpr inline auto QProcess::qt_create_metaobjectdata<qt_meta_tag_ZN8QProcessE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QProcess",
        "started",
        "",
        "finished",
        "exitCode",
        "QProcess::ExitStatus",
        "exitStatus",
        "errorOccurred",
        "QProcess::ProcessError",
        "error",
        "stateChanged",
        "QProcess::ProcessState",
        "state",
        "readyReadStandardOutput",
        "readyReadStandardError",
        "terminate",
        "kill",
        "_q_canReadStandardOutput",
        "_q_canReadStandardError",
        "_q_canWrite",
        "_q_startupNotification",
        "_q_processDied",
        "ProcessError",
        "FailedToStart",
        "Crashed",
        "Timedout",
        "ReadError",
        "WriteError",
        "UnknownError",
        "ProcessState",
        "NotRunning",
        "Starting",
        "Running",
        "ProcessChannel",
        "StandardOutput",
        "StandardError",
        "ProcessChannelMode",
        "SeparateChannels",
        "MergedChannels",
        "ForwardedChannels",
        "ForwardedOutputChannel",
        "ForwardedErrorChannel",
        "InputChannelMode",
        "ManagedInputChannel",
        "ForwardedInputChannel",
        "ExitStatus",
        "NormalExit",
        "CrashExit"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finished'
        QtMocHelpers::SignalData<void(int, QProcess::ExitStatus)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'finished'
        QtMocHelpers::SignalData<void(int)>(3, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(QProcess::ProcessError)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(QProcess::ProcessState)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Signal 'readyReadStandardOutput'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'readyReadStandardError'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'terminate'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'kill'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_canReadStandardOutput'
        QtMocHelpers::SlotData<bool()>(17, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot '_q_canReadStandardError'
        QtMocHelpers::SlotData<bool()>(18, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot '_q_canWrite'
        QtMocHelpers::SlotData<bool()>(19, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot '_q_startupNotification'
        QtMocHelpers::SlotData<bool()>(20, 2, QMC::AccessPrivate, QMetaType::Bool),
        // Slot '_q_processDied'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ProcessError'
        QtMocHelpers::EnumData<ProcessError>(22, 22, QMC::EnumFlags{}).add({
            {   23, ProcessError::FailedToStart },
            {   24, ProcessError::Crashed },
            {   25, ProcessError::Timedout },
            {   26, ProcessError::ReadError },
            {   27, ProcessError::WriteError },
            {   28, ProcessError::UnknownError },
        }),
        // enum 'ProcessState'
        QtMocHelpers::EnumData<ProcessState>(29, 29, QMC::EnumFlags{}).add({
            {   30, ProcessState::NotRunning },
            {   31, ProcessState::Starting },
            {   32, ProcessState::Running },
        }),
        // enum 'ProcessChannel'
        QtMocHelpers::EnumData<ProcessChannel>(33, 33, QMC::EnumFlags{}).add({
            {   34, ProcessChannel::StandardOutput },
            {   35, ProcessChannel::StandardError },
        }),
        // enum 'ProcessChannelMode'
        QtMocHelpers::EnumData<ProcessChannelMode>(36, 36, QMC::EnumFlags{}).add({
            {   37, ProcessChannelMode::SeparateChannels },
            {   38, ProcessChannelMode::MergedChannels },
            {   39, ProcessChannelMode::ForwardedChannels },
            {   40, ProcessChannelMode::ForwardedOutputChannel },
            {   41, ProcessChannelMode::ForwardedErrorChannel },
        }),
        // enum 'InputChannelMode'
        QtMocHelpers::EnumData<InputChannelMode>(42, 42, QMC::EnumFlags{}).add({
            {   43, InputChannelMode::ManagedInputChannel },
            {   44, InputChannelMode::ForwardedInputChannel },
        }),
        // enum 'ExitStatus'
        QtMocHelpers::EnumData<ExitStatus>(45, 45, QMC::EnumFlags{}).add({
            {   46, ExitStatus::NormalExit },
            {   47, ExitStatus::CrashExit },
        }),
    };
    return QtMocHelpers::metaObjectData<QProcess, qt_meta_tag_ZN8QProcessE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QProcess::staticMetaObject = { {
    QMetaObject::SuperData::link<QIODevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QProcessE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QProcessE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QProcessE_t>.metaTypes,
    nullptr
} };

void QProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QProcess *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started(QPrivateSignal()); break;
        case 1: _t->finished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QProcess::ExitStatus>>(_a[2]))); break;
        case 2: _t->finished((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QProcess::ProcessError>>(_a[1]))); break;
        case 4: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QProcess::ProcessState>>(_a[1])), QPrivateSignal()); break;
        case 5: _t->readyReadStandardOutput(QPrivateSignal()); break;
        case 6: _t->readyReadStandardError(QPrivateSignal()); break;
        case 7: _t->terminate(); break;
        case 8: _t->kill(); break;
        case 9: { bool _r = _t->d_func()->_q_canReadStandardOutput();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->d_func()->_q_canReadStandardError();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: { bool _r = _t->d_func()->_q_canWrite();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: { bool _r = _t->d_func()->_q_startupNotification();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->d_func()->_q_processDied(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QProcess::*)(QPrivateSignal)>(_a, &QProcess::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QProcess::*)(int , QProcess::ExitStatus )>(_a, &QProcess::finished, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QProcess::*)(QProcess::ProcessError )>(_a, &QProcess::errorOccurred, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QProcess::*)(QProcess::ProcessState , QPrivateSignal)>(_a, &QProcess::stateChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QProcess::*)(QPrivateSignal)>(_a, &QProcess::readyReadStandardOutput, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QProcess::*)(QPrivateSignal)>(_a, &QProcess::readyReadStandardError, 6))
            return;
    }
}

const QMetaObject *QProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QProcessE_t>.strings))
        return static_cast<void*>(this);
    return QIODevice::qt_metacast(_clname);
}

int QProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QProcess::started(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QProcess::finished(int _t1, QProcess::ExitStatus _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 3
void QProcess::errorOccurred(QProcess::ProcessError _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QProcess::stateChanged(QProcess::ProcessState _t1, QPrivateSignal _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void QProcess::readyReadStandardOutput(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QProcess::readyReadStandardError(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
QT_WARNING_POP
