/****************************************************************************
** Meta object code from reading C++ file 'qtextedit.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qtextedit.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtextedit.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QTextEditE_t {};
} // unnamed namespace

template <> constexpr inline auto QTextEdit::qt_create_metaobjectdata<qt_meta_tag_ZN9QTextEditE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTextEdit",
        "textChanged",
        "",
        "undoAvailable",
        "b",
        "redoAvailable",
        "currentCharFormatChanged",
        "QTextCharFormat",
        "format",
        "copyAvailable",
        "selectionChanged",
        "cursorPositionChanged",
        "setFontPointSize",
        "s",
        "setFontFamily",
        "fontFamily",
        "setFontWeight",
        "w",
        "setFontUnderline",
        "setFontItalic",
        "setTextColor",
        "c",
        "setTextBackgroundColor",
        "setCurrentFont",
        "f",
        "setAlignment",
        "Qt::Alignment",
        "a",
        "setPlainText",
        "text",
        "setHtml",
        "setMarkdown",
        "markdown",
        "setText",
        "cut",
        "copy",
        "paste",
        "undo",
        "redo",
        "clear",
        "selectAll",
        "insertPlainText",
        "insertHtml",
        "append",
        "scrollToAnchor",
        "name",
        "zoomIn",
        "range",
        "zoomOut",
        "loadResource",
        "QVariant",
        "type",
        "inputMethodQuery",
        "Qt::InputMethodQuery",
        "query",
        "argument",
        "autoFormatting",
        "AutoFormatting",
        "tabChangesFocus",
        "documentTitle",
        "undoRedoEnabled",
        "lineWrapMode",
        "LineWrapMode",
        "lineWrapColumnOrWidth",
        "readOnly",
        "html",
        "plainText",
        "overwriteMode",
        "tabStopDistance",
        "acceptRichText",
        "cursorWidth",
        "textInteractionFlags",
        "Qt::TextInteractionFlags",
        "document",
        "QTextDocument*",
        "placeholderText",
        "NoWrap",
        "WidgetWidth",
        "FixedPixelWidth",
        "FixedColumnWidth",
        "AutoFormattingFlag",
        "AutoNone",
        "AutoBulletList",
        "AutoAll"
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
        // Signal 'currentCharFormatChanged'
        QtMocHelpers::SignalData<void(const QTextCharFormat &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Signal 'copyAvailable'
        QtMocHelpers::SignalData<void(bool)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cursorPositionChanged'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setFontPointSize'
        QtMocHelpers::SlotData<void(qreal)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 13 },
        }}),
        // Slot 'setFontFamily'
        QtMocHelpers::SlotData<void(const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 15 },
        }}),
        // Slot 'setFontWeight'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'setFontUnderline'
        QtMocHelpers::SlotData<void(bool)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Slot 'setFontItalic'
        QtMocHelpers::SlotData<void(bool)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Slot 'setTextColor'
        QtMocHelpers::SlotData<void(const QColor &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 21 },
        }}),
        // Slot 'setTextBackgroundColor'
        QtMocHelpers::SlotData<void(const QColor &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 21 },
        }}),
        // Slot 'setCurrentFont'
        QtMocHelpers::SlotData<void(const QFont &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QFont, 24 },
        }}),
        // Slot 'setAlignment'
        QtMocHelpers::SlotData<void(Qt::Alignment)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 26, 27 },
        }}),
        // Slot 'setPlainText'
        QtMocHelpers::SlotData<void(const QString &)>(28, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'setHtml'
        QtMocHelpers::SlotData<void(const QString &)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'setMarkdown'
        QtMocHelpers::SlotData<void(const QString &)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 32 },
        }}),
        // Slot 'setText'
        QtMocHelpers::SlotData<void(const QString &)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'cut'
        QtMocHelpers::SlotData<void()>(34, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'copy'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'paste'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'undo'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'redo'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectAll'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'insertPlainText'
        QtMocHelpers::SlotData<void(const QString &)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'insertHtml'
        QtMocHelpers::SlotData<void(const QString &)>(42, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'append'
        QtMocHelpers::SlotData<void(const QString &)>(43, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 29 },
        }}),
        // Slot 'scrollToAnchor'
        QtMocHelpers::SlotData<void(const QString &)>(44, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 45 },
        }}),
        // Slot 'zoomIn'
        QtMocHelpers::SlotData<void(int)>(46, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 47 },
        }}),
        // Slot 'zoomIn'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'zoomOut'
        QtMocHelpers::SlotData<void(int)>(48, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 47 },
        }}),
        // Slot 'zoomOut'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'loadResource'
        QtMocHelpers::MethodData<QVariant(int, const QUrl &)>(49, 2, QMC::AccessPublic, 0x80000000 | 50, {{
            { QMetaType::Int, 51 }, { QMetaType::QUrl, 45 },
        }}),
        // Method 'inputMethodQuery'
        QtMocHelpers::MethodData<QVariant(Qt::InputMethodQuery, QVariant) const>(52, 2, QMC::AccessPublic, 0x80000000 | 50, {{
            { 0x80000000 | 53, 54 }, { 0x80000000 | 50, 55 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'autoFormatting'
        QtMocHelpers::PropertyData<AutoFormatting>(56, 0x80000000 | 57, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'tabChangesFocus'
        QtMocHelpers::PropertyData<bool>(58, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'documentTitle'
        QtMocHelpers::PropertyData<QString>(59, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'undoRedoEnabled'
        QtMocHelpers::PropertyData<bool>(60, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'lineWrapMode'
        QtMocHelpers::PropertyData<LineWrapMode>(61, 0x80000000 | 62, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'lineWrapColumnOrWidth'
        QtMocHelpers::PropertyData<int>(63, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'readOnly'
        QtMocHelpers::PropertyData<bool>(64, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'markdown'
        QtMocHelpers::PropertyData<QString>(32, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'html'
        QtMocHelpers::PropertyData<QString>(65, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 0),
        // property 'plainText'
        QtMocHelpers::PropertyData<QString>(66, QMetaType::QString, QMC::Readable | QMC::Writable | QMC::Scriptable | QMC::Stored | QMC::StdCppSet),
        // property 'overwriteMode'
        QtMocHelpers::PropertyData<bool>(67, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tabStopDistance'
        QtMocHelpers::PropertyData<qreal>(68, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'acceptRichText'
        QtMocHelpers::PropertyData<bool>(69, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'cursorWidth'
        QtMocHelpers::PropertyData<int>(70, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'textInteractionFlags'
        QtMocHelpers::PropertyData<Qt::TextInteractionFlags>(71, 0x80000000 | 72, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'document'
        QtMocHelpers::PropertyData<QTextDocument*>(73, 0x80000000 | 74, QMC::Readable | QMC::Writable | QMC::Scriptable | QMC::Stored | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'placeholderText'
        QtMocHelpers::PropertyData<QString>(75, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'LineWrapMode'
        QtMocHelpers::EnumData<LineWrapMode>(62, 62, QMC::EnumFlags{}).add({
            {   76, LineWrapMode::NoWrap },
            {   77, LineWrapMode::WidgetWidth },
            {   78, LineWrapMode::FixedPixelWidth },
            {   79, LineWrapMode::FixedColumnWidth },
        }),
        // enum 'AutoFormatting'
        QtMocHelpers::EnumData<AutoFormatting>(57, 80, QMC::EnumFlags{}).add({
            {   81, AutoFormattingFlag::AutoNone },
            {   82, AutoFormattingFlag::AutoBulletList },
            {   83, AutoFormattingFlag::AutoAll },
        }),
    };
    return QtMocHelpers::metaObjectData<QTextEdit, qt_meta_tag_ZN9QTextEditE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTextEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractScrollArea::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTextEditE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTextEditE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QTextEditE_t>.metaTypes,
    nullptr
} };

void QTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTextEdit *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->textChanged(); break;
        case 1: _t->undoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->redoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->currentCharFormatChanged((*reinterpret_cast< std::add_pointer_t<QTextCharFormat>>(_a[1]))); break;
        case 4: _t->copyAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->selectionChanged(); break;
        case 6: _t->cursorPositionChanged(); break;
        case 7: _t->setFontPointSize((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 8: _t->setFontFamily((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->setFontWeight((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->setFontUnderline((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->setFontItalic((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->setTextColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 13: _t->setTextBackgroundColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 14: _t->setCurrentFont((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 15: _t->setAlignment((*reinterpret_cast< std::add_pointer_t<Qt::Alignment>>(_a[1]))); break;
        case 16: _t->setPlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->setHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->setMarkdown((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->setText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->cut(); break;
        case 21: _t->copy(); break;
        case 22: _t->paste(); break;
        case 23: _t->undo(); break;
        case 24: _t->redo(); break;
        case 25: _t->clear(); break;
        case 26: _t->selectAll(); break;
        case 27: _t->insertPlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 28: _t->insertHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->append((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->scrollToAnchor((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->zoomIn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 32: _t->zoomIn(); break;
        case 33: _t->zoomOut((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 34: _t->zoomOut(); break;
        case 35: { QVariant _r = _t->loadResource((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 36: { QVariant _r = _t->inputMethodQuery((*reinterpret_cast< std::add_pointer_t<Qt::InputMethodQuery>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTextEdit::*)()>(_a, &QTextEdit::textChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextEdit::*)(bool )>(_a, &QTextEdit::undoAvailable, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextEdit::*)(bool )>(_a, &QTextEdit::redoAvailable, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextEdit::*)(const QTextCharFormat & )>(_a, &QTextEdit::currentCharFormatChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextEdit::*)(bool )>(_a, &QTextEdit::copyAvailable, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextEdit::*)()>(_a, &QTextEdit::selectionChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextEdit::*)()>(_a, &QTextEdit::cursorPositionChanged, 6))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 15:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTextDocument* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: QtMocHelpers::assignFlags<AutoFormatting>(_v, _t->autoFormatting()); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->tabChangesFocus(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->documentTitle(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->isUndoRedoEnabled(); break;
        case 4: *reinterpret_cast<LineWrapMode*>(_v) = _t->lineWrapMode(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->lineWrapColumnOrWidth(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isReadOnly(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->toMarkdown(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->toHtml(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->toPlainText(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->overwriteMode(); break;
        case 11: *reinterpret_cast<qreal*>(_v) = _t->tabStopDistance(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->acceptRichText(); break;
        case 13: *reinterpret_cast<int*>(_v) = _t->cursorWidth(); break;
        case 14: *reinterpret_cast<Qt::TextInteractionFlags*>(_v) = _t->textInteractionFlags(); break;
        case 15: *reinterpret_cast<QTextDocument**>(_v) = _t->document(); break;
        case 16: *reinterpret_cast<QString*>(_v) = _t->placeholderText(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAutoFormatting(*reinterpret_cast<AutoFormatting*>(_v)); break;
        case 1: _t->setTabChangesFocus(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setDocumentTitle(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setUndoRedoEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setLineWrapMode(*reinterpret_cast<LineWrapMode*>(_v)); break;
        case 5: _t->setLineWrapColumnOrWidth(*reinterpret_cast<int*>(_v)); break;
        case 6: _t->setReadOnly(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setMarkdown(*reinterpret_cast<QString*>(_v)); break;
        case 8: _t->setHtml(*reinterpret_cast<QString*>(_v)); break;
        case 9: _t->setPlainText(*reinterpret_cast<QString*>(_v)); break;
        case 10: _t->setOverwriteMode(*reinterpret_cast<bool*>(_v)); break;
        case 11: _t->setTabStopDistance(*reinterpret_cast<qreal*>(_v)); break;
        case 12: _t->setAcceptRichText(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setCursorWidth(*reinterpret_cast<int*>(_v)); break;
        case 14: _t->setTextInteractionFlags(*reinterpret_cast<Qt::TextInteractionFlags*>(_v)); break;
        case 15: _t->setDocument(*reinterpret_cast<QTextDocument**>(_v)); break;
        case 16: _t->setPlaceholderText(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTextEditE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractScrollArea::qt_metacast(_clname);
}

int QTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 37)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 37;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 37)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 37;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void QTextEdit::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QTextEdit::undoAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QTextEdit::redoAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QTextEdit::currentCharFormatChanged(const QTextCharFormat & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QTextEdit::copyAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QTextEdit::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QTextEdit::cursorPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
