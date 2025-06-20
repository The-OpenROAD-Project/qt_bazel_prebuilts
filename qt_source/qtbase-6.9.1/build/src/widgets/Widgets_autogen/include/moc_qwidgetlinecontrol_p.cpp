/****************************************************************************
** Meta object code from reading C++ file 'qwidgetlinecontrol_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qwidgetlinecontrol_p.h"
#include <QtGui/qscreen.h>
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwidgetlinecontrol_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QWidgetLineControlE_t {};
} // unnamed namespace

template <> constexpr inline auto QWidgetLineControl::qt_create_metaobjectdata<qt_meta_tag_ZN18QWidgetLineControlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QWidgetLineControl",
        "cursorPositionChanged",
        "",
        "selectionChanged",
        "displayTextChanged",
        "textChanged",
        "textEdited",
        "resetInputContext",
        "updateMicroFocus",
        "accepted",
        "editingFinished",
        "updateNeeded",
        "inputRejected",
        "_q_deleteSelected"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'cursorPositionChanged'
        QtMocHelpers::SignalData<void(int, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'displayTextChanged'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'textChanged'
        QtMocHelpers::SignalData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'textEdited'
        QtMocHelpers::SignalData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'resetInputContext'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'updateMicroFocus'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'accepted'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'editingFinished'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'updateNeeded'
        QtMocHelpers::SignalData<void(const QRect &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 2 },
        }}),
        // Signal 'inputRejected'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_deleteSelected'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QWidgetLineControl, qt_meta_tag_ZN18QWidgetLineControlE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QWidgetLineControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QInputControl::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QWidgetLineControlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QWidgetLineControlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QWidgetLineControlE_t>.metaTypes,
    nullptr
} };

void QWidgetLineControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QWidgetLineControl *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->cursorPositionChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->selectionChanged(); break;
        case 2: _t->displayTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->resetInputContext(); break;
        case 6: _t->updateMicroFocus(); break;
        case 7: _t->accepted(); break;
        case 8: _t->editingFinished(); break;
        case 9: _t->updateNeeded((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1]))); break;
        case 10: _t->inputRejected(); break;
        case 11: _t->_q_deleteSelected(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)(int , int )>(_a, &QWidgetLineControl::cursorPositionChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)()>(_a, &QWidgetLineControl::selectionChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)(const QString & )>(_a, &QWidgetLineControl::displayTextChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)(const QString & )>(_a, &QWidgetLineControl::textChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)(const QString & )>(_a, &QWidgetLineControl::textEdited, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)()>(_a, &QWidgetLineControl::resetInputContext, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)()>(_a, &QWidgetLineControl::updateMicroFocus, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)()>(_a, &QWidgetLineControl::accepted, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)()>(_a, &QWidgetLineControl::editingFinished, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)(const QRect & )>(_a, &QWidgetLineControl::updateNeeded, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetLineControl::*)()>(_a, &QWidgetLineControl::inputRejected, 10))
            return;
    }
}

const QMetaObject *QWidgetLineControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWidgetLineControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QWidgetLineControlE_t>.strings))
        return static_cast<void*>(this);
    return QInputControl::qt_metacast(_clname);
}

int QWidgetLineControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QInputControl::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QWidgetLineControl::cursorPositionChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QWidgetLineControl::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QWidgetLineControl::displayTextChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QWidgetLineControl::textChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QWidgetLineControl::textEdited(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QWidgetLineControl::resetInputContext()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QWidgetLineControl::updateMicroFocus()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QWidgetLineControl::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QWidgetLineControl::editingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QWidgetLineControl::updateNeeded(const QRect & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void QWidgetLineControl::inputRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
