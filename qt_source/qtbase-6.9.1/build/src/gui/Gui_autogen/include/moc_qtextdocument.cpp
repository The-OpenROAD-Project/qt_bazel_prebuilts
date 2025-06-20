/****************************************************************************
** Meta object code from reading C++ file 'qtextdocument.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/text/qtextdocument.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtextdocument.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QTextDocumentE_t {};
} // unnamed namespace

template <> constexpr inline auto QTextDocument::qt_create_metaobjectdata<qt_meta_tag_ZN13QTextDocumentE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTextDocument",
        "contentsChange",
        "",
        "from",
        "charsRemoved",
        "charsAdded",
        "contentsChanged",
        "undoAvailable",
        "redoAvailable",
        "undoCommandAdded",
        "modificationChanged",
        "m",
        "cursorPositionChanged",
        "QTextCursor",
        "cursor",
        "blockCountChanged",
        "newBlockCount",
        "baseUrlChanged",
        "url",
        "documentLayoutChanged",
        "undo",
        "redo",
        "appendUndoItem",
        "QAbstractUndoItem*",
        "setModified",
        "loadResource",
        "QVariant",
        "type",
        "name",
        "undoRedoEnabled",
        "modified",
        "pageSize",
        "defaultFont",
        "useDesignMetrics",
        "layoutEnabled",
        "size",
        "textWidth",
        "blockCount",
        "indentWidth",
        "defaultStyleSheet",
        "maximumBlockCount",
        "documentMargin",
        "baseUrl",
        "MarkdownFeatures",
        "MarkdownFeature",
        "MarkdownNoHTML",
        "MarkdownDialectCommonMark",
        "MarkdownDialectGitHub",
        "ResourceType",
        "UnknownResource",
        "HtmlResource",
        "ImageResource",
        "StyleSheetResource",
        "MarkdownResource",
        "UserResource"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'contentsChange'
        QtMocHelpers::SignalData<void(int, int, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Int, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'contentsChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'undoAvailable'
        QtMocHelpers::SignalData<void(bool)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'redoAvailable'
        QtMocHelpers::SignalData<void(bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'undoCommandAdded'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'modificationChanged'
        QtMocHelpers::SignalData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Signal 'cursorPositionChanged'
        QtMocHelpers::SignalData<void(const QTextCursor &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Signal 'blockCountChanged'
        QtMocHelpers::SignalData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Signal 'baseUrlChanged'
        QtMocHelpers::SignalData<void(const QUrl &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 18 },
        }}),
        // Signal 'documentLayoutChanged'
        QtMocHelpers::SignalData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'undo'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'redo'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'appendUndoItem'
        QtMocHelpers::SlotData<void(QAbstractUndoItem *)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 23, 2 },
        }}),
        // Slot 'setModified'
        QtMocHelpers::SlotData<void(bool)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Slot 'setModified'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Method 'loadResource'
        QtMocHelpers::MethodData<QVariant(int, const QUrl &)>(25, 2, QMC::AccessProtected, 0x80000000 | 26, {{
            { QMetaType::Int, 27 }, { QMetaType::QUrl, 28 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'undoRedoEnabled'
        QtMocHelpers::PropertyData<bool>(29, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'modified'
        QtMocHelpers::PropertyData<bool>(30, QMetaType::Bool, QMC::Readable | QMC::Writable | QMC::Scriptable | QMC::Stored | QMC::StdCppSet),
        // property 'pageSize'
        QtMocHelpers::PropertyData<QSizeF>(31, QMetaType::QSizeF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'defaultFont'
        QtMocHelpers::PropertyData<QFont>(32, QMetaType::QFont, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'useDesignMetrics'
        QtMocHelpers::PropertyData<bool>(33, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'layoutEnabled'
        QtMocHelpers::PropertyData<bool>(34, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'size'
        QtMocHelpers::PropertyData<QSizeF>(35, QMetaType::QSizeF, QMC::DefaultPropertyFlags),
        // property 'textWidth'
        QtMocHelpers::PropertyData<qreal>(36, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'blockCount'
        QtMocHelpers::PropertyData<int>(37, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'indentWidth'
        QtMocHelpers::PropertyData<qreal>(38, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'defaultStyleSheet'
        QtMocHelpers::PropertyData<QString>(39, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maximumBlockCount'
        QtMocHelpers::PropertyData<int>(40, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'documentMargin'
        QtMocHelpers::PropertyData<qreal>(41, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'baseUrl'
        QtMocHelpers::PropertyData<QUrl>(42, QMetaType::QUrl, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'MarkdownFeatures'
        QtMocHelpers::EnumData<MarkdownFeatures>(43, 44, QMC::EnumFlags{}).add({
            {   45, MarkdownFeature::MarkdownNoHTML },
            {   46, MarkdownFeature::MarkdownDialectCommonMark },
            {   47, MarkdownFeature::MarkdownDialectGitHub },
        }),
        // enum 'ResourceType'
        QtMocHelpers::EnumData<ResourceType>(48, 48, QMC::EnumFlags{}).add({
            {   49, ResourceType::UnknownResource },
            {   50, ResourceType::HtmlResource },
            {   51, ResourceType::ImageResource },
            {   52, ResourceType::StyleSheetResource },
            {   53, ResourceType::MarkdownResource },
            {   54, ResourceType::UserResource },
        }),
    };
    return QtMocHelpers::metaObjectData<QTextDocument, qt_meta_tag_ZN13QTextDocumentE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTextDocument::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QTextDocumentE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QTextDocumentE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QTextDocumentE_t>.metaTypes,
    nullptr
} };

void QTextDocument::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTextDocument *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->contentsChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->contentsChanged(); break;
        case 2: _t->undoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->redoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->undoCommandAdded(); break;
        case 5: _t->modificationChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->cursorPositionChanged((*reinterpret_cast< std::add_pointer_t<QTextCursor>>(_a[1]))); break;
        case 7: _t->blockCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->baseUrlChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 9: _t->documentLayoutChanged(); break;
        case 10: _t->undo(); break;
        case 11: _t->redo(); break;
        case 12: _t->appendUndoItem((*reinterpret_cast< std::add_pointer_t<QAbstractUndoItem*>>(_a[1]))); break;
        case 13: _t->setModified((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 14: _t->setModified(); break;
        case 15: { QVariant _r = _t->loadResource((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)(int , int , int )>(_a, &QTextDocument::contentsChange, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)()>(_a, &QTextDocument::contentsChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)(bool )>(_a, &QTextDocument::undoAvailable, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)(bool )>(_a, &QTextDocument::redoAvailable, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)()>(_a, &QTextDocument::undoCommandAdded, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)(bool )>(_a, &QTextDocument::modificationChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)(const QTextCursor & )>(_a, &QTextDocument::cursorPositionChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)(int )>(_a, &QTextDocument::blockCountChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)(const QUrl & )>(_a, &QTextDocument::baseUrlChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTextDocument::*)()>(_a, &QTextDocument::documentLayoutChanged, 9))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isUndoRedoEnabled(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isModified(); break;
        case 2: *reinterpret_cast<QSizeF*>(_v) = _t->pageSize(); break;
        case 3: *reinterpret_cast<QFont*>(_v) = _t->defaultFont(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->useDesignMetrics(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isLayoutEnabled(); break;
        case 6: *reinterpret_cast<QSizeF*>(_v) = _t->size(); break;
        case 7: *reinterpret_cast<qreal*>(_v) = _t->textWidth(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->blockCount(); break;
        case 9: *reinterpret_cast<qreal*>(_v) = _t->indentWidth(); break;
        case 10: *reinterpret_cast<QString*>(_v) = _t->defaultStyleSheet(); break;
        case 11: *reinterpret_cast<int*>(_v) = _t->maximumBlockCount(); break;
        case 12: *reinterpret_cast<qreal*>(_v) = _t->documentMargin(); break;
        case 13: *reinterpret_cast<QUrl*>(_v) = _t->baseUrl(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setUndoRedoEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setModified(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setPageSize(*reinterpret_cast<QSizeF*>(_v)); break;
        case 3: _t->setDefaultFont(*reinterpret_cast<QFont*>(_v)); break;
        case 4: _t->setUseDesignMetrics(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setLayoutEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setTextWidth(*reinterpret_cast<qreal*>(_v)); break;
        case 9: _t->setIndentWidth(*reinterpret_cast<qreal*>(_v)); break;
        case 10: _t->setDefaultStyleSheet(*reinterpret_cast<QString*>(_v)); break;
        case 11: _t->setMaximumBlockCount(*reinterpret_cast<int*>(_v)); break;
        case 12: _t->setDocumentMargin(*reinterpret_cast<qreal*>(_v)); break;
        case 13: _t->setBaseUrl(*reinterpret_cast<QUrl*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTextDocument::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTextDocument::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QTextDocumentE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QTextDocument::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QTextDocument::contentsChange(int _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}

// SIGNAL 1
void QTextDocument::contentsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QTextDocument::undoAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QTextDocument::redoAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QTextDocument::undoCommandAdded()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QTextDocument::modificationChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QTextDocument::cursorPositionChanged(const QTextCursor & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QTextDocument::blockCountChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QTextDocument::baseUrlChanged(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void QTextDocument::documentLayoutChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
