/****************************************************************************
** Meta object code from reading C++ file 'qinputmethod.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qinputmethod.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qinputmethod.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QInputMethodE_t {};
} // unnamed namespace

template <> constexpr inline auto QInputMethod::qt_create_metaobjectdata<qt_meta_tag_ZN12QInputMethodE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QInputMethod",
        "cursorRectangleChanged",
        "",
        "anchorRectangleChanged",
        "keyboardRectangleChanged",
        "inputItemClipRectangleChanged",
        "visibleChanged",
        "animatingChanged",
        "localeChanged",
        "inputDirectionChanged",
        "Qt::LayoutDirection",
        "newDirection",
        "show",
        "hide",
        "update",
        "Qt::InputMethodQueries",
        "queries",
        "reset",
        "commit",
        "invokeAction",
        "Action",
        "a",
        "cursorPosition",
        "cursorRectangle",
        "anchorRectangle",
        "keyboardRectangle",
        "inputItemClipRectangle",
        "visible",
        "animating",
        "locale",
        "inputDirection",
        "Click",
        "ContextMenu"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'cursorRectangleChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'anchorRectangleChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'keyboardRectangleChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'inputItemClipRectangleChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'visibleChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'animatingChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'localeChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'inputDirectionChanged'
        QtMocHelpers::SignalData<void(Qt::LayoutDirection)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'show'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'hide'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'update'
        QtMocHelpers::SlotData<void(Qt::InputMethodQueries)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Slot 'reset'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'commit'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'invokeAction'
        QtMocHelpers::SlotData<void(Action, int)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 21 }, { QMetaType::Int, 22 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'cursorRectangle'
        QtMocHelpers::PropertyData<QRectF>(23, QMetaType::QRectF, QMC::DefaultPropertyFlags, 0),
        // property 'anchorRectangle'
        QtMocHelpers::PropertyData<QRectF>(24, QMetaType::QRectF, QMC::DefaultPropertyFlags, 1),
        // property 'keyboardRectangle'
        QtMocHelpers::PropertyData<QRectF>(25, QMetaType::QRectF, QMC::DefaultPropertyFlags, 2),
        // property 'inputItemClipRectangle'
        QtMocHelpers::PropertyData<QRectF>(26, QMetaType::QRectF, QMC::DefaultPropertyFlags, 3),
        // property 'visible'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags, 4),
        // property 'animating'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags, 5),
        // property 'locale'
        QtMocHelpers::PropertyData<QLocale>(29, QMetaType::QLocale, QMC::DefaultPropertyFlags, 6),
        // property 'inputDirection'
        QtMocHelpers::PropertyData<Qt::LayoutDirection>(30, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 7),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Action'
        QtMocHelpers::EnumData<Action>(20, 20, QMC::EnumFlags{}).add({
            {   31, Action::Click },
            {   32, Action::ContextMenu },
        }),
    };
    return QtMocHelpers::metaObjectData<QInputMethod, qt_meta_tag_ZN12QInputMethodE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QInputMethod::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QInputMethodE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QInputMethodE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QInputMethodE_t>.metaTypes,
    nullptr
} };

void QInputMethod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QInputMethod *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->cursorRectangleChanged(); break;
        case 1: _t->anchorRectangleChanged(); break;
        case 2: _t->keyboardRectangleChanged(); break;
        case 3: _t->inputItemClipRectangleChanged(); break;
        case 4: _t->visibleChanged(); break;
        case 5: _t->animatingChanged(); break;
        case 6: _t->localeChanged(); break;
        case 7: _t->inputDirectionChanged((*reinterpret_cast< std::add_pointer_t<Qt::LayoutDirection>>(_a[1]))); break;
        case 8: _t->show(); break;
        case 9: _t->hide(); break;
        case 10: _t->update((*reinterpret_cast< std::add_pointer_t<Qt::InputMethodQueries>>(_a[1]))); break;
        case 11: _t->reset(); break;
        case 12: _t->commit(); break;
        case 13: _t->invokeAction((*reinterpret_cast< std::add_pointer_t<Action>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QInputMethod::*)()>(_a, &QInputMethod::cursorRectangleChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QInputMethod::*)()>(_a, &QInputMethod::anchorRectangleChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QInputMethod::*)()>(_a, &QInputMethod::keyboardRectangleChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QInputMethod::*)()>(_a, &QInputMethod::inputItemClipRectangleChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QInputMethod::*)()>(_a, &QInputMethod::visibleChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QInputMethod::*)()>(_a, &QInputMethod::animatingChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QInputMethod::*)()>(_a, &QInputMethod::localeChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QInputMethod::*)(Qt::LayoutDirection )>(_a, &QInputMethod::inputDirectionChanged, 7))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QRectF*>(_v) = _t->cursorRectangle(); break;
        case 1: *reinterpret_cast<QRectF*>(_v) = _t->anchorRectangle(); break;
        case 2: *reinterpret_cast<QRectF*>(_v) = _t->keyboardRectangle(); break;
        case 3: *reinterpret_cast<QRectF*>(_v) = _t->inputItemClipRectangle(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isVisible(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isAnimating(); break;
        case 6: *reinterpret_cast<QLocale*>(_v) = _t->locale(); break;
        case 7: *reinterpret_cast<Qt::LayoutDirection*>(_v) = _t->inputDirection(); break;
        default: break;
        }
    }
}

const QMetaObject *QInputMethod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QInputMethod::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QInputMethodE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QInputMethod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QInputMethod::cursorRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QInputMethod::anchorRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QInputMethod::keyboardRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QInputMethod::inputItemClipRectangleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QInputMethod::visibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QInputMethod::animatingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QInputMethod::localeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QInputMethod::inputDirectionChanged(Qt::LayoutDirection _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}
QT_WARNING_POP
