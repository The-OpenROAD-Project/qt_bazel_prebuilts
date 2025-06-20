/****************************************************************************
** Meta object code from reading C++ file 'qundogroup.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/util/qundogroup.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qundogroup.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QUndoGroupE_t {};
} // unnamed namespace

template <> constexpr inline auto QUndoGroup::qt_create_metaobjectdata<qt_meta_tag_ZN10QUndoGroupE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QUndoGroup",
        "activeStackChanged",
        "",
        "QUndoStack*",
        "stack",
        "indexChanged",
        "idx",
        "cleanChanged",
        "clean",
        "canUndoChanged",
        "canUndo",
        "canRedoChanged",
        "canRedo",
        "undoTextChanged",
        "undoText",
        "redoTextChanged",
        "redoText",
        "undo",
        "redo",
        "setActiveStack"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activeStackChanged'
        QtMocHelpers::SignalData<void(QUndoStack *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'indexChanged'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Signal 'cleanChanged'
        QtMocHelpers::SignalData<void(bool)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 8 },
        }}),
        // Signal 'canUndoChanged'
        QtMocHelpers::SignalData<void(bool)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 10 },
        }}),
        // Signal 'canRedoChanged'
        QtMocHelpers::SignalData<void(bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 12 },
        }}),
        // Signal 'undoTextChanged'
        QtMocHelpers::SignalData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Signal 'redoTextChanged'
        QtMocHelpers::SignalData<void(const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'undo'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'redo'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setActiveStack'
        QtMocHelpers::SlotData<void(QUndoStack *)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QUndoGroup, qt_meta_tag_ZN10QUndoGroupE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QUndoGroup::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QUndoGroupE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QUndoGroupE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QUndoGroupE_t>.metaTypes,
    nullptr
} };

void QUndoGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QUndoGroup *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activeStackChanged((*reinterpret_cast< std::add_pointer_t<QUndoStack*>>(_a[1]))); break;
        case 1: _t->indexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->cleanChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->canUndoChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->canRedoChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->undoTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->redoTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->undo(); break;
        case 8: _t->redo(); break;
        case 9: _t->setActiveStack((*reinterpret_cast< std::add_pointer_t<QUndoStack*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QUndoGroup::*)(QUndoStack * )>(_a, &QUndoGroup::activeStackChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QUndoGroup::*)(int )>(_a, &QUndoGroup::indexChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QUndoGroup::*)(bool )>(_a, &QUndoGroup::cleanChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QUndoGroup::*)(bool )>(_a, &QUndoGroup::canUndoChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QUndoGroup::*)(bool )>(_a, &QUndoGroup::canRedoChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QUndoGroup::*)(const QString & )>(_a, &QUndoGroup::undoTextChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QUndoGroup::*)(const QString & )>(_a, &QUndoGroup::redoTextChanged, 6))
            return;
    }
}

const QMetaObject *QUndoGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QUndoGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QUndoGroupE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QUndoGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}

// SIGNAL 0
void QUndoGroup::activeStackChanged(QUndoStack * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QUndoGroup::indexChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QUndoGroup::cleanChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QUndoGroup::canUndoChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QUndoGroup::canRedoChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QUndoGroup::undoTextChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QUndoGroup::redoTextChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
QT_WARNING_POP
