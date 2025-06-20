/****************************************************************************
** Meta object code from reading C++ file 'qwidgettextcontrol_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qwidgettextcontrol_p.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwidgettextcontrol_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QWidgetTextControlE_t {};
} // unnamed namespace

template <> constexpr inline auto QWidgetTextControl::qt_create_metaobjectdata<qt_meta_tag_ZN18QWidgetTextControlE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QWidgetTextControl",
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
        "updateRequest",
        "rect",
        "documentSizeChanged",
        "blockCountChanged",
        "newBlockCount",
        "visibilityRequest",
        "microFocusChanged",
        "linkActivated",
        "link",
        "linkHovered",
        "blockMarkerHovered",
        "QTextBlock",
        "block",
        "modificationChanged",
        "m",
        "setPlainText",
        "text",
        "setMarkdown",
        "setHtml",
        "cut",
        "copy",
        "paste",
        "QClipboard::Mode",
        "mode",
        "undo",
        "redo",
        "clear",
        "selectAll",
        "insertPlainText",
        "insertHtml",
        "append",
        "appendHtml",
        "html",
        "appendPlainText",
        "adjustSize",
        "_q_deleteSelected",
        "_q_copyLink",
        "loadResource",
        "QVariant",
        "type",
        "name",
        "overwriteMode",
        "acceptRichText",
        "cursorWidth",
        "textInteractionFlags",
        "Qt::TextInteractionFlags",
        "openExternalLinks",
        "ignoreUnusedNavigationEvents"
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
        // Signal 'updateRequest'
        QtMocHelpers::SignalData<void(const QRectF &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 13 },
        }}),
        // Signal 'updateRequest'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Signal 'documentSizeChanged'
        QtMocHelpers::SignalData<void(const QSizeF &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSizeF, 2 },
        }}),
        // Signal 'blockCountChanged'
        QtMocHelpers::SignalData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Signal 'visibilityRequest'
        QtMocHelpers::SignalData<void(const QRectF &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 13 },
        }}),
        // Signal 'microFocusChanged'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'linkActivated'
        QtMocHelpers::SignalData<void(const QString &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 20 },
        }}),
        // Signal 'linkHovered'
        QtMocHelpers::SignalData<void(const QString &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'blockMarkerHovered'
        QtMocHelpers::SignalData<void(const QTextBlock &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 23, 24 },
        }}),
        // Signal 'modificationChanged'
        QtMocHelpers::SignalData<void(bool)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 26 },
        }}),
        // Slot 'setPlainText'
        QtMocHelpers::SlotData<void(const QString &)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 28 },
        }}),
        // Slot 'setMarkdown'
        QtMocHelpers::SlotData<void(const QString &)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 28 },
        }}),
        // Slot 'setHtml'
        QtMocHelpers::SlotData<void(const QString &)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 28 },
        }}),
        // Slot 'cut'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'copy'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'paste'
        QtMocHelpers::SlotData<void(QClipboard::Mode)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 34, 35 },
        }}),
        // Slot 'paste'
        QtMocHelpers::SlotData<void()>(33, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'undo'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'redo'
        QtMocHelpers::SlotData<void()>(37, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectAll'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'insertPlainText'
        QtMocHelpers::SlotData<void(const QString &)>(40, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 28 },
        }}),
        // Slot 'insertHtml'
        QtMocHelpers::SlotData<void(const QString &)>(41, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 28 },
        }}),
        // Slot 'append'
        QtMocHelpers::SlotData<void(const QString &)>(42, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 28 },
        }}),
        // Slot 'appendHtml'
        QtMocHelpers::SlotData<void(const QString &)>(43, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 44 },
        }}),
        // Slot 'appendPlainText'
        QtMocHelpers::SlotData<void(const QString &)>(45, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 28 },
        }}),
        // Slot 'adjustSize'
        QtMocHelpers::SlotData<void()>(46, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_deleteSelected'
        QtMocHelpers::SlotData<void()>(47, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_copyLink'
        QtMocHelpers::SlotData<void()>(48, 2, QMC::AccessPrivate, QMetaType::Void),
        // Method 'loadResource'
        QtMocHelpers::MethodData<QVariant(int, const QUrl &)>(49, 2, QMC::AccessPublic, 0x80000000 | 50, {{
            { QMetaType::Int, 51 }, { QMetaType::QUrl, 52 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'html'
        QtMocHelpers::PropertyData<QString>(44, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 0),
        // property 'overwriteMode'
        QtMocHelpers::PropertyData<bool>(53, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'acceptRichText'
        QtMocHelpers::PropertyData<bool>(54, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'cursorWidth'
        QtMocHelpers::PropertyData<int>(55, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'textInteractionFlags'
        QtMocHelpers::PropertyData<Qt::TextInteractionFlags>(56, 0x80000000 | 57, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'openExternalLinks'
        QtMocHelpers::PropertyData<bool>(58, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'ignoreUnusedNavigationEvents'
        QtMocHelpers::PropertyData<bool>(59, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QWidgetTextControl, qt_meta_tag_ZN18QWidgetTextControlE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QWidgetTextControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QInputControl::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QWidgetTextControlE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QWidgetTextControlE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QWidgetTextControlE_t>.metaTypes,
    nullptr
} };

void QWidgetTextControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QWidgetTextControl *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->textChanged(); break;
        case 1: _t->undoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->redoAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->currentCharFormatChanged((*reinterpret_cast< std::add_pointer_t<QTextCharFormat>>(_a[1]))); break;
        case 4: _t->copyAvailable((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->selectionChanged(); break;
        case 6: _t->cursorPositionChanged(); break;
        case 7: _t->updateRequest((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 8: _t->updateRequest(); break;
        case 9: _t->documentSizeChanged((*reinterpret_cast< std::add_pointer_t<QSizeF>>(_a[1]))); break;
        case 10: _t->blockCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->visibilityRequest((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 12: _t->microFocusChanged(); break;
        case 13: _t->linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->linkHovered((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->blockMarkerHovered((*reinterpret_cast< std::add_pointer_t<QTextBlock>>(_a[1]))); break;
        case 16: _t->modificationChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 17: _t->setPlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->setMarkdown((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->setHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->cut(); break;
        case 21: _t->copy(); break;
        case 22: _t->paste((*reinterpret_cast< std::add_pointer_t<QClipboard::Mode>>(_a[1]))); break;
        case 23: _t->paste(); break;
        case 24: _t->undo(); break;
        case 25: _t->redo(); break;
        case 26: _t->clear(); break;
        case 27: _t->selectAll(); break;
        case 28: _t->insertPlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 29: _t->insertHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 30: _t->append((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 31: _t->appendHtml((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 32: _t->appendPlainText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 33: _t->adjustSize(); break;
        case 34: _t->d_func()->_q_deleteSelected(); break;
        case 35: _t->d_func()->_q_copyLink(); break;
        case 36: { QVariant _r = _t->loadResource((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)()>(_a, &QWidgetTextControl::textChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(bool )>(_a, &QWidgetTextControl::undoAvailable, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(bool )>(_a, &QWidgetTextControl::redoAvailable, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(const QTextCharFormat & )>(_a, &QWidgetTextControl::currentCharFormatChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(bool )>(_a, &QWidgetTextControl::copyAvailable, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)()>(_a, &QWidgetTextControl::selectionChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)()>(_a, &QWidgetTextControl::cursorPositionChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(const QRectF & )>(_a, &QWidgetTextControl::updateRequest, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(const QSizeF & )>(_a, &QWidgetTextControl::documentSizeChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(int )>(_a, &QWidgetTextControl::blockCountChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(const QRectF & )>(_a, &QWidgetTextControl::visibilityRequest, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)()>(_a, &QWidgetTextControl::microFocusChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(const QString & )>(_a, &QWidgetTextControl::linkActivated, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(const QString & )>(_a, &QWidgetTextControl::linkHovered, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(const QTextBlock & )>(_a, &QWidgetTextControl::blockMarkerHovered, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWidgetTextControl::*)(bool )>(_a, &QWidgetTextControl::modificationChanged, 16))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->toHtml(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->overwriteMode(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->acceptRichText(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->cursorWidth(); break;
        case 4: *reinterpret_cast<Qt::TextInteractionFlags*>(_v) = _t->textInteractionFlags(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->openExternalLinks(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->ignoreUnusedNavigationEvents(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHtml(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setOverwriteMode(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setAcceptRichText(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setCursorWidth(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setTextInteractionFlags(*reinterpret_cast<Qt::TextInteractionFlags*>(_v)); break;
        case 5: _t->setOpenExternalLinks(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setIgnoreUnusedNavigationEvents(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QWidgetTextControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWidgetTextControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QWidgetTextControlE_t>.strings))
        return static_cast<void*>(this);
    return QInputControl::qt_metacast(_clname);
}

int QWidgetTextControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QInputControl::qt_metacall(_c, _id, _a);
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
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QWidgetTextControl::textChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QWidgetTextControl::undoAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QWidgetTextControl::redoAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QWidgetTextControl::currentCharFormatChanged(const QTextCharFormat & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QWidgetTextControl::copyAvailable(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QWidgetTextControl::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QWidgetTextControl::cursorPositionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QWidgetTextControl::updateRequest(const QRectF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 9
void QWidgetTextControl::documentSizeChanged(const QSizeF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void QWidgetTextControl::blockCountChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void QWidgetTextControl::visibilityRequest(const QRectF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void QWidgetTextControl::microFocusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void QWidgetTextControl::linkActivated(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}

// SIGNAL 14
void QWidgetTextControl::linkHovered(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1);
}

// SIGNAL 15
void QWidgetTextControl::blockMarkerHovered(const QTextBlock & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1);
}

// SIGNAL 16
void QWidgetTextControl::modificationChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN28QUnicodeControlCharacterMenuE_t {};
} // unnamed namespace

template <> constexpr inline auto QUnicodeControlCharacterMenu::qt_create_metaobjectdata<qt_meta_tag_ZN28QUnicodeControlCharacterMenuE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QUnicodeControlCharacterMenu",
        "menuActionTriggered",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'menuActionTriggered'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QUnicodeControlCharacterMenu, qt_meta_tag_ZN28QUnicodeControlCharacterMenuE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QUnicodeControlCharacterMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QUnicodeControlCharacterMenuE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QUnicodeControlCharacterMenuE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN28QUnicodeControlCharacterMenuE_t>.metaTypes,
    nullptr
} };

void QUnicodeControlCharacterMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QUnicodeControlCharacterMenu *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->menuActionTriggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *QUnicodeControlCharacterMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QUnicodeControlCharacterMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QUnicodeControlCharacterMenuE_t>.strings))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int QUnicodeControlCharacterMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
