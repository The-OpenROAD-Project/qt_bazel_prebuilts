/****************************************************************************
** Meta object code from reading C++ file 'qtuiohandler_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/generic/tuiotouch/qtuiohandler_p.h"
#include "qoscmessage_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtuiohandler_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QTuioHandlerE_t {};
} // unnamed namespace

template <> constexpr inline auto QTuioHandler::qt_create_metaobjectdata<qt_meta_tag_ZN12QTuioHandlerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTuioHandler",
        "processPackets",
        "",
        "process2DCurSource",
        "QOscMessage",
        "message",
        "process2DCurAlive",
        "process2DCurSet",
        "process2DCurFseq",
        "process2DObjSource",
        "process2DObjAlive",
        "process2DObjSet",
        "process2DObjFseq"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'processPackets'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'process2DCurSource'
        QtMocHelpers::SlotData<void(const QOscMessage &)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'process2DCurAlive'
        QtMocHelpers::SlotData<void(const QOscMessage &)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'process2DCurSet'
        QtMocHelpers::SlotData<void(const QOscMessage &)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'process2DCurFseq'
        QtMocHelpers::SlotData<void(const QOscMessage &)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'process2DObjSource'
        QtMocHelpers::SlotData<void(const QOscMessage &)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'process2DObjAlive'
        QtMocHelpers::SlotData<void(const QOscMessage &)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'process2DObjSet'
        QtMocHelpers::SlotData<void(const QOscMessage &)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Slot 'process2DObjFseq'
        QtMocHelpers::SlotData<void(const QOscMessage &)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTuioHandler, qt_meta_tag_ZN12QTuioHandlerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTuioHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTuioHandlerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTuioHandlerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QTuioHandlerE_t>.metaTypes,
    nullptr
} };

void QTuioHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTuioHandler *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->processPackets(); break;
        case 1: _t->process2DCurSource((*reinterpret_cast< std::add_pointer_t<QOscMessage>>(_a[1]))); break;
        case 2: _t->process2DCurAlive((*reinterpret_cast< std::add_pointer_t<QOscMessage>>(_a[1]))); break;
        case 3: _t->process2DCurSet((*reinterpret_cast< std::add_pointer_t<QOscMessage>>(_a[1]))); break;
        case 4: _t->process2DCurFseq((*reinterpret_cast< std::add_pointer_t<QOscMessage>>(_a[1]))); break;
        case 5: _t->process2DObjSource((*reinterpret_cast< std::add_pointer_t<QOscMessage>>(_a[1]))); break;
        case 6: _t->process2DObjAlive((*reinterpret_cast< std::add_pointer_t<QOscMessage>>(_a[1]))); break;
        case 7: _t->process2DObjSet((*reinterpret_cast< std::add_pointer_t<QOscMessage>>(_a[1]))); break;
        case 8: _t->process2DObjFseq((*reinterpret_cast< std::add_pointer_t<QOscMessage>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *QTuioHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTuioHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTuioHandlerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QTuioHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
