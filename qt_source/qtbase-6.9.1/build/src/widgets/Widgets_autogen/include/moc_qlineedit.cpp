/****************************************************************************
** Meta object code from reading C++ file 'qlineedit.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qlineedit.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlineedit.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QLineEditE_t {};
} // unnamed namespace

template <> constexpr inline auto QLineEdit::qt_create_metaobjectdata<qt_meta_tag_ZN9QLineEditE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QLineEdit",
        "textChanged",
        "",
        "textEdited",
        "cursorPositionChanged",
        "returnPressed",
        "editingFinished",
        "selectionChanged",
        "inputRejected",
        "setText",
        "clear",
        "selectAll",
        "undo",
        "redo",
        "cut",
        "copy",
        "paste",
        "inputMethodQuery",
        "QVariant",
        "Qt::InputMethodQuery",
        "property",
        "argument",
        "inputMask",
        "text",
        "maxLength",
        "frame",
        "echoMode",
        "EchoMode",
        "displayText",
        "cursorPosition",
        "alignment",
        "Qt::Alignment",
        "modified",
        "hasSelectedText",
        "selectedText",
        "dragEnabled",
        "readOnly",
        "undoAvailable",
        "redoAvailable",
        "acceptableInput",
        "placeholderText",
        "cursorMoveStyle",
        "Qt::CursorMoveStyle",
        "clearButtonEnabled",
        "ActionPosition",
        "LeadingPosition",
        "TrailingPosition",
        "Normal",
        "NoEcho",
        "Password",
        "PasswordEchoOnEdit"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'textChanged'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'textEdited'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'cursorPositionChanged'
        QtMocHelpers::SignalData<void(int, int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Signal 'returnPressed'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'editingFinished'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'inputRejected'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setText'
        QtMocHelpers::SlotData<void(const QString &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectAll'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'undo'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'redo'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'cut'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'copy'
        QtMocHelpers::SlotData<void() const>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'paste'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'inputMethodQuery'
        QtMocHelpers::MethodData<QVariant(Qt::InputMethodQuery, QVariant) const>(17, 2, QMC::AccessPublic, 0x80000000 | 18, {{
            { 0x80000000 | 19, 20 }, { 0x80000000 | 18, 21 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'inputMask'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'text'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 0),
        // property 'maxLength'
        QtMocHelpers::PropertyData<int>(24, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'frame'
        QtMocHelpers::PropertyData<bool>(25, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'echoMode'
        QtMocHelpers::PropertyData<EchoMode>(26, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'displayText'
        QtMocHelpers::PropertyData<QString>(28, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'cursorPosition'
        QtMocHelpers::PropertyData<int>(29, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'alignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(30, 0x80000000 | 31, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'modified'
        QtMocHelpers::PropertyData<bool>(32, QMetaType::Bool, QMC::Readable | QMC::Writable | QMC::Scriptable | QMC::Stored | QMC::StdCppSet),
        // property 'hasSelectedText'
        QtMocHelpers::PropertyData<bool>(33, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'selectedText'
        QtMocHelpers::PropertyData<QString>(34, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'dragEnabled'
        QtMocHelpers::PropertyData<bool>(35, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'readOnly'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'undoAvailable'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'redoAvailable'
        QtMocHelpers::PropertyData<bool>(38, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'acceptableInput'
        QtMocHelpers::PropertyData<bool>(39, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'placeholderText'
        QtMocHelpers::PropertyData<QString>(40, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'cursorMoveStyle'
        QtMocHelpers::PropertyData<Qt::CursorMoveStyle>(41, 0x80000000 | 42, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'clearButtonEnabled'
        QtMocHelpers::PropertyData<bool>(43, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ActionPosition'
        QtMocHelpers::EnumData<ActionPosition>(44, 44, QMC::EnumFlags{}).add({
            {   45, ActionPosition::LeadingPosition },
            {   46, ActionPosition::TrailingPosition },
        }),
        // enum 'EchoMode'
        QtMocHelpers::EnumData<EchoMode>(27, 27, QMC::EnumFlags{}).add({
            {   47, EchoMode::Normal },
            {   48, EchoMode::NoEcho },
            {   49, EchoMode::Password },
            {   50, EchoMode::PasswordEchoOnEdit },
        }),
    };
    return QtMocHelpers::metaObjectData<QLineEdit, qt_meta_tag_ZN9QLineEditE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QLineEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QLineEditE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QLineEditE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QLineEditE_t>.metaTypes,
    nullptr
} };

void QLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QLineEdit *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->textEdited((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->cursorPositionChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->returnPressed(); break;
        case 4: _t->editingFinished(); break;
        case 5: _t->selectionChanged(); break;
        case 6: _t->inputRejected(); break;
        case 7: _t->setText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->clear(); break;
        case 9: _t->selectAll(); break;
        case 10: _t->undo(); break;
        case 11: _t->redo(); break;
        case 12: _t->cut(); break;
        case 13: _t->copy(); break;
        case 14: _t->paste(); break;
        case 15: { QVariant _r = _t->inputMethodQuery((*reinterpret_cast< std::add_pointer_t<Qt::InputMethodQuery>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QLineEdit::*)(const QString & )>(_a, &QLineEdit::textChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLineEdit::*)(const QString & )>(_a, &QLineEdit::textEdited, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLineEdit::*)(int , int )>(_a, &QLineEdit::cursorPositionChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLineEdit::*)()>(_a, &QLineEdit::returnPressed, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLineEdit::*)()>(_a, &QLineEdit::editingFinished, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLineEdit::*)()>(_a, &QLineEdit::selectionChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QLineEdit::*)()>(_a, &QLineEdit::inputRejected, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->inputMask(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->maxLength(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->hasFrame(); break;
        case 4: *reinterpret_cast<EchoMode*>(_v) = _t->echoMode(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->displayText(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->cursorPosition(); break;
        case 7: *reinterpret_cast<Qt::Alignment*>(_v) = _t->alignment(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->isModified(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->hasSelectedText(); break;
        case 10: *reinterpret_cast<QString*>(_v) = _t->selectedText(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->dragEnabled(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->isReadOnly(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->isUndoAvailable(); break;
        case 14: *reinterpret_cast<bool*>(_v) = _t->isRedoAvailable(); break;
        case 15: *reinterpret_cast<bool*>(_v) = _t->hasAcceptableInput(); break;
        case 16: *reinterpret_cast<QString*>(_v) = _t->placeholderText(); break;
        case 17: *reinterpret_cast<Qt::CursorMoveStyle*>(_v) = _t->cursorMoveStyle(); break;
        case 18: *reinterpret_cast<bool*>(_v) = _t->isClearButtonEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setInputMask(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setText(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setMaxLength(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setFrame(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setEchoMode(*reinterpret_cast<EchoMode*>(_v)); break;
        case 6: _t->setCursorPosition(*reinterpret_cast<int*>(_v)); break;
        case 7: _t->setAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        case 8: _t->setModified(*reinterpret_cast<bool*>(_v)); break;
        case 11: _t->setDragEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 12: _t->setReadOnly(*reinterpret_cast<bool*>(_v)); break;
        case 16: _t->setPlaceholderText(*reinterpret_cast<QString*>(_v)); break;
        case 17: _t->setCursorMoveStyle(*reinterpret_cast<Qt::CursorMoveStyle*>(_v)); break;
        case 18: _t->setClearButtonEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QLineEditE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void QLineEdit::textChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QLineEdit::textEdited(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QLineEdit::cursorPositionChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QLineEdit::returnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QLineEdit::editingFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QLineEdit::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QLineEdit::inputRejected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
