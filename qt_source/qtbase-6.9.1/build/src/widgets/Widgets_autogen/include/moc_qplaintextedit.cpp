/****************************************************************************
** Meta object code from reading C++ file 'qplaintextedit.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qplaintextedit.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qplaintextedit.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14QPlainTextEditE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlainTextEdit::qt_create_metaobjectdata<qt_meta_tag_ZN14QPlainTextEditE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlainTextEdit",
        "textChanged",
        "",
        "undoAvailable",
        "b",
        "redoAvailable",
        "copyAvailable",
        "selectionChanged",
        "cursorPositionChanged",
        "updateRequest",
        "rect",
        "dy",
        "blockCountChanged",
        "newBlockCount",
        "modificationChanged",
        "setPlainText",
        "text",
        "cut",
        "copy",
        "paste",
        "undo",
        "redo",
        "clear",
        "selectAll",
        "insertPlainText",
        "appendPlainText",
        "appendHtml",
        "html",
        "centerCursor",
        "zoomIn",
        "range",
        "zoomOut",
        "inputMethodQuery",
        "QVariant",
        "Qt::InputMethodQuery",
        "query",
        "argument",
        "tabChangesFocus",
        "documentTitle",
        "undoRedoEnabled",
        "lineWrapMode",
        "LineWrapMode",
        "readOnly",
        "plainText",
        "overwriteMode",
        "tabStopDistance",
        "cursorWidth",
        "textInteractionFlags",
        "Qt::TextInteractionFlags",
        "blockCount",
        "maximumBlockCount",
        "backgroundVisible",
        "centerOnScroll",
        "placeholderText",
        "NoWrap",
        "WidgetWidth"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'textChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'undoAvailable'
        QtMocHelpers::SignalData<void(bool)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Signal 'redoAvailable'
        QtMocHelpers::SignalData<void(bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Signal 'copyAvailable'
        QtMocHelpers::SignalData<void(bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cursorPositionChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'updateRequest'
        QtMocHelpers::SignalData<void(const QRect &, int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 10 }, { QMetaType::Int, 11 },
        }}),
        // Signal 'blockCountChanged'
        QtMocHelpers::SignalData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Signal 'modificationChanged'
        QtMocHelpers::SignalData<void(bool)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'setPlainText'
        QtMocHelpers::SlotData<void(const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'cut'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'copy'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'paste'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'undo'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'redo'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectAll'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'insertPlainText'
        QtMocHelpers::SlotData<void(const QString &)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'appendPlainText'
        QtMocHelpers::SlotData<void(const QString &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Slot 'appendHtml'
        QtMocHelpers::SlotData<void(const QString &)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 27 },
        }}),
        // Slot 'centerCursor'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'zoomIn'
        QtMocHelpers::SlotData<void(int)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 30 },
        }}),
        // Slot 'zoomIn'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'zoomOut'
        QtMocHelpers::SlotData<void(int)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 30 },
        }}),
        // Slot 'zoomOut'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'inputMethodQuery'
        QtMocHelpers::MethodData<QVariant(Qt::InputMethodQuery, QVariant) const>(32, 2, QMC::AccessPublic, 0x80000000 | 33, {{
            { 0x80000000 | 34, 35 }, { 0x80000000 | 33, 36 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'tabChangesFocus'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'documentTitle'
        QtMocHelpers::PropertyData<QString>(38, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'undoRedoEnabled'
        QtMocHelpers::PropertyData<bool>(39, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lineWrapMode'
        QtMocHelpers::PropertyData<LineWrapMode>(40, 0x80000000 | 41, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'readOnly'
        QtMocHelpers::PropertyData<bool>(42, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'plainText'
        QtMocHelpers::PropertyData<QString>(43, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 0),
        // property 'overwriteMode'
        QtMocHelpers::PropertyData<bool>(44, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tabStopDistance'
        QtMocHelpers::PropertyData<qreal>(45, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'cursorWidth'
        QtMocHelpers::PropertyData<int>(46, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'textInteractionFlags'
        QtMocHelpers::PropertyData<Qt::TextInteractionFlags>(47, 0x80000000 | 48, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'blockCount'
        QtMocHelpers::PropertyData<int>(49, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'maximumBlockCount'
        QtMocHelpers::PropertyData<int>(50, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'backgroundVisible'
        QtMocHelpers::PropertyData<bool>(51, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'centerOnScroll'
        QtMocHelpers::PropertyData<bool>(52, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'placeholderText'
        QtMocHelpers::PropertyData<QString>(53, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'LineWrapMode'
        QtMocHelpers::EnumData<LineWrapMode>(41, 41, QMC::EnumFlags{}).add({
            {   54, LineWrapMode::NoWrap },
            {   55, LineWrapMode::WidgetWidth },
        }),
    };
    return QtMocHelpers::metaObjectData<QPlainTextEdit, qt_meta_tag_ZN14QPlainTextEditE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlainTextEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractScrollArea::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QPlainTextEditE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QPlainTextEditE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QPlainTextEditE_t>.metaTypes,
    nullptr
} };

void QPlainTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlainTextEdit *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->textChanged(); break;
        case 1: _t->undoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->redoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->copyAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->selectionChanged(); break;
        case 5: _t->cursorPositionChanged(); break;
        case 6: _t->updateRequest((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->blockCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->modificationChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->setPlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->cut(); break;
        case 11: _t->copy(); break;
        case 12: _t->paste(); break;
        case 13: _t->undo(); break;
        case 14: _t->redo(); break;
        case 15: _t->clear(); break;
        case 16: _t->selectAll(); break;
        case 17: _t->insertPlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->appendPlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->appendHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->centerCursor(); break;
        case 21: _t->zoomIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->zoomIn(); break;
        case 23: _t->zoomOut((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->zoomOut(); break;
        case 25: { QVariant _r = _t->inputMethodQuery((*reinterpret_cast< std::add_pointer_t<Qt::InputMethodQuery>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)()>(_a, &QPlainTextEdit::textChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)(bool )>(_a, &QPlainTextEdit::undoAvailable, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)(bool )>(_a, &QPlainTextEdit::redoAvailable, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)(bool )>(_a, &QPlainTextEdit::copyAvailable, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)()>(_a, &QPlainTextEdit::selectionChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)()>(_a, &QPlainTextEdit::cursorPositionChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)(const QRect & , int )>(_a, &QPlainTextEdit::updateRequest, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)(int )>(_a, &QPlainTextEdit::blockCountChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlainTextEdit::*)(bool )>(_a, &QPlainTextEdit::modificationChanged, 8))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->tabChangesFocus(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->documentTitle(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isUndoRedoEnabled(); break;
        case 3: *reinterpret_cast<LineWrapMode*>(_v) = _t->lineWrapMode(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isReadOnly(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->toPlainText(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->overwriteMode(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->tabStopDistance(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->cursorWidth(); break;
        case 9: *reinterpret_cast<Qt::TextInteractionFlags*>(_v) = _t->textInteractionFlags(); break;
        case 10: *reinterpret_cast<int*>(_v) = _t->blockCount(); break;
        case 11: *reinterpret_cast<int*>(_v) = _t->maximumBlockCount(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->backgroundVisible(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->centerOnScroll(); break;
        case 14: *reinterpret_cast<QString*>(_v) = _t->placeholderText(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTabChangesFocus(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setDocumentTitle(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setUndoRedoEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setLineWrapMode(*reinterpret_cast<LineWrapMode*>(_v)); break;
        case 4: _t->setReadOnly(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setPlainText(*reinterpret_cast<QString*>(_v)); break;
        case 6: _t->setOverwriteMode(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setTabStopDistance(*reinterpret_cast<qreal*>(_v)); break;
        case 8: _t->setCursorWidth(*reinterpret_cast<int*>(_v)); break;
        case 9: _t->setTextInteractionFlags(*reinterpret_cast<Qt::TextInteractionFlags*>(_v)); break;
        case 11: _t->setMaximumBlockCount(*reinterpret_cast<int*>(_v)); break;
        case 12: _t->setBackgroundVisible(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setCenterOnScroll(*reinterpret_cast<bool*>(_v)); break;
        case 14: _t->setPlaceholderText(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QPlainTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlainTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QPlainTextEditE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractScrollArea::qt_metacast(_clname);
}

int QPlainTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QPlainTextEdit::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QPlainTextEdit::undoAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QPlainTextEdit::redoAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QPlainTextEdit::copyAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QPlainTextEdit::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QPlainTextEdit::cursorPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QPlainTextEdit::updateRequest(const QRect & _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void QPlainTextEdit::blockCountChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QPlainTextEdit::modificationChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN24QPlainTextDocumentLayoutE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlainTextDocumentLayout::qt_create_metaobjectdata<qt_meta_tag_ZN24QPlainTextDocumentLayoutE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlainTextDocumentLayout",
        "cursorWidth"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'cursorWidth'
        QtMocHelpers::PropertyData<int>(1, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPlainTextDocumentLayout, qt_meta_tag_ZN24QPlainTextDocumentLayoutE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlainTextDocumentLayout::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTextDocumentLayout::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QPlainTextDocumentLayoutE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QPlainTextDocumentLayoutE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24QPlainTextDocumentLayoutE_t>.metaTypes,
    nullptr
} };

void QPlainTextDocumentLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlainTextDocumentLayout *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->cursorWidth(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCursorWidth(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QPlainTextDocumentLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlainTextDocumentLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QPlainTextDocumentLayoutE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractTextDocumentLayout::qt_metacast(_clname);
}

int QPlainTextDocumentLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTextDocumentLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
