/****************************************************************************
** Meta object code from reading C++ file 'qopengldebug.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/opengl/qopengldebug.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qopengldebug.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QOpenGLDebugLoggerE_t {};
} // unnamed namespace

template <> constexpr inline auto QOpenGLDebugLogger::qt_create_metaobjectdata<qt_meta_tag_ZN18QOpenGLDebugLoggerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QOpenGLDebugLogger",
        "messageLogged",
        "",
        "QOpenGLDebugMessage",
        "debugMessage",
        "logMessage",
        "startLogging",
        "LoggingMode",
        "loggingMode",
        "stopLogging",
        "_q_contextAboutToBeDestroyed",
        "AsynchronousLogging",
        "SynchronousLogging"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'messageLogged'
        QtMocHelpers::SignalData<void(const QOpenGLDebugMessage &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'logMessage'
        QtMocHelpers::SlotData<void(const QOpenGLDebugMessage &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'startLogging'
        QtMocHelpers::SlotData<void(LoggingMode)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Slot 'startLogging'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'stopLogging'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_contextAboutToBeDestroyed'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'loggingMode'
        QtMocHelpers::PropertyData<LoggingMode>(8, 0x80000000 | 7, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'LoggingMode'
        QtMocHelpers::EnumData<LoggingMode>(7, 7, QMC::EnumFlags{}).add({
            {   11, LoggingMode::AsynchronousLogging },
            {   12, LoggingMode::SynchronousLogging },
        }),
    };
    return QtMocHelpers::metaObjectData<QOpenGLDebugLogger, qt_meta_tag_ZN18QOpenGLDebugLoggerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QOpenGLDebugLogger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QOpenGLDebugLoggerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QOpenGLDebugLoggerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QOpenGLDebugLoggerE_t>.metaTypes,
    nullptr
} };

void QOpenGLDebugLogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QOpenGLDebugLogger *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->messageLogged((*reinterpret_cast< std::add_pointer_t<QOpenGLDebugMessage>>(_a[1]))); break;
        case 1: _t->logMessage((*reinterpret_cast< std::add_pointer_t<QOpenGLDebugMessage>>(_a[1]))); break;
        case 2: _t->startLogging((*reinterpret_cast< std::add_pointer_t<LoggingMode>>(_a[1]))); break;
        case 3: _t->startLogging(); break;
        case 4: _t->stopLogging(); break;
        case 5: _t->d_func()->_q_contextAboutToBeDestroyed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QOpenGLDebugMessage >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QOpenGLDebugMessage >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QOpenGLDebugLogger::*)(const QOpenGLDebugMessage & )>(_a, &QOpenGLDebugLogger::messageLogged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<LoggingMode*>(_v) = _t->loggingMode(); break;
        default: break;
        }
    }
}

const QMetaObject *QOpenGLDebugLogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QOpenGLDebugLogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QOpenGLDebugLoggerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QOpenGLDebugLogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QOpenGLDebugLogger::messageLogged(const QOpenGLDebugMessage & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
