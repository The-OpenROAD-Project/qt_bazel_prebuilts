/****************************************************************************
** Meta object code from reading C++ file 'qabstractitemview.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qabstractitemview.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractitemview.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QAbstractItemViewE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractItemView::qt_create_metaobjectdata<qt_meta_tag_ZN17QAbstractItemViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractItemView",
        "pressed",
        "",
        "QModelIndex",
        "index",
        "clicked",
        "doubleClicked",
        "activated",
        "entered",
        "viewportEntered",
        "iconSizeChanged",
        "size",
        "reset",
        "setRootIndex",
        "doItemsLayout",
        "selectAll",
        "edit",
        "clearSelection",
        "setCurrentIndex",
        "scrollToTop",
        "scrollToBottom",
        "update",
        "dataChanged",
        "topLeft",
        "bottomRight",
        "QList<int>",
        "roles",
        "rowsInserted",
        "parent",
        "start",
        "end",
        "rowsAboutToBeRemoved",
        "selectionChanged",
        "QItemSelection",
        "selected",
        "deselected",
        "currentChanged",
        "current",
        "previous",
        "updateEditorData",
        "updateEditorGeometries",
        "updateGeometries",
        "verticalScrollbarAction",
        "action",
        "horizontalScrollbarAction",
        "verticalScrollbarValueChanged",
        "value",
        "horizontalScrollbarValueChanged",
        "closeEditor",
        "QWidget*",
        "editor",
        "QAbstractItemDelegate::EndEditHint",
        "hint",
        "commitData",
        "editorDestroyed",
        "autoScroll",
        "autoScrollMargin",
        "editTriggers",
        "EditTriggers",
        "tabKeyNavigation",
        "showDropIndicator",
        "dragEnabled",
        "dragDropOverwriteMode",
        "dragDropMode",
        "DragDropMode",
        "defaultDropAction",
        "Qt::DropAction",
        "alternatingRowColors",
        "selectionMode",
        "SelectionMode",
        "selectionBehavior",
        "SelectionBehavior",
        "iconSize",
        "textElideMode",
        "Qt::TextElideMode",
        "verticalScrollMode",
        "ScrollMode",
        "horizontalScrollMode",
        "updateThreshold",
        "NoSelection",
        "SingleSelection",
        "MultiSelection",
        "ExtendedSelection",
        "ContiguousSelection",
        "SelectItems",
        "SelectRows",
        "SelectColumns",
        "ScrollHint",
        "EnsureVisible",
        "PositionAtTop",
        "PositionAtBottom",
        "PositionAtCenter",
        "EditTrigger",
        "NoEditTriggers",
        "CurrentChanged",
        "DoubleClicked",
        "SelectedClicked",
        "EditKeyPressed",
        "AnyKeyPressed",
        "AllEditTriggers",
        "ScrollPerItem",
        "ScrollPerPixel",
        "NoDragDrop",
        "DragOnly",
        "DropOnly",
        "DragDrop",
        "InternalMove"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'pressed'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'clicked'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'doubleClicked'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'activated'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'entered'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'viewportEntered'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'iconSizeChanged'
        QtMocHelpers::SignalData<void(const QSize &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSize, 11 },
        }}),
        // Slot 'reset'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setRootIndex'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'doItemsLayout'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectAll'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'edit'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'clearSelection'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCurrentIndex'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'scrollToTop'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'scrollToBottom'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'update'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'dataChanged'
        QtMocHelpers::SlotData<void(const QModelIndex &, const QModelIndex &, const QList<int> &)>(22, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 3, 23 }, { 0x80000000 | 3, 24 }, { 0x80000000 | 25, 26 },
        }}),
        // Slot 'dataChanged'
        QtMocHelpers::SlotData<void(const QModelIndex &, const QModelIndex &)>(22, 2, QMC::AccessProtected | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 23 }, { 0x80000000 | 3, 24 },
        }}),
        // Slot 'rowsInserted'
        QtMocHelpers::SlotData<void(const QModelIndex &, int, int)>(27, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 3, 28 }, { QMetaType::Int, 29 }, { QMetaType::Int, 30 },
        }}),
        // Slot 'rowsAboutToBeRemoved'
        QtMocHelpers::SlotData<void(const QModelIndex &, int, int)>(31, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 3, 28 }, { QMetaType::Int, 29 }, { QMetaType::Int, 30 },
        }}),
        // Slot 'selectionChanged'
        QtMocHelpers::SlotData<void(const QItemSelection &, const QItemSelection &)>(32, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 33, 34 }, { 0x80000000 | 33, 35 },
        }}),
        // Slot 'currentChanged'
        QtMocHelpers::SlotData<void(const QModelIndex &, const QModelIndex &)>(36, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 3, 37 }, { 0x80000000 | 3, 38 },
        }}),
        // Slot 'updateEditorData'
        QtMocHelpers::SlotData<void()>(39, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'updateEditorGeometries'
        QtMocHelpers::SlotData<void()>(40, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'updateGeometries'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'verticalScrollbarAction'
        QtMocHelpers::SlotData<void(int)>(42, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 43 },
        }}),
        // Slot 'horizontalScrollbarAction'
        QtMocHelpers::SlotData<void(int)>(44, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 43 },
        }}),
        // Slot 'verticalScrollbarValueChanged'
        QtMocHelpers::SlotData<void(int)>(45, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 46 },
        }}),
        // Slot 'horizontalScrollbarValueChanged'
        QtMocHelpers::SlotData<void(int)>(47, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 46 },
        }}),
        // Slot 'closeEditor'
        QtMocHelpers::SlotData<void(QWidget *, QAbstractItemDelegate::EndEditHint)>(48, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 49, 50 }, { 0x80000000 | 51, 52 },
        }}),
        // Slot 'commitData'
        QtMocHelpers::SlotData<void(QWidget *)>(53, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 49, 50 },
        }}),
        // Slot 'editorDestroyed'
        QtMocHelpers::SlotData<void(QObject *)>(54, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::QObjectStar, 50 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'autoScroll'
        QtMocHelpers::PropertyData<bool>(55, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoScrollMargin'
        QtMocHelpers::PropertyData<int>(56, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'editTriggers'
        QtMocHelpers::PropertyData<EditTriggers>(57, 0x80000000 | 58, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'tabKeyNavigation'
        QtMocHelpers::PropertyData<bool>(59, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'showDropIndicator'
        QtMocHelpers::PropertyData<bool>(60, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'dragEnabled'
        QtMocHelpers::PropertyData<bool>(61, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'dragDropOverwriteMode'
        QtMocHelpers::PropertyData<bool>(62, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'dragDropMode'
        QtMocHelpers::PropertyData<DragDropMode>(63, 0x80000000 | 64, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'defaultDropAction'
        QtMocHelpers::PropertyData<Qt::DropAction>(65, 0x80000000 | 66, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'alternatingRowColors'
        QtMocHelpers::PropertyData<bool>(67, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'selectionMode'
        QtMocHelpers::PropertyData<SelectionMode>(68, 0x80000000 | 69, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'selectionBehavior'
        QtMocHelpers::PropertyData<SelectionBehavior>(70, 0x80000000 | 71, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'iconSize'
        QtMocHelpers::PropertyData<QSize>(72, QMetaType::QSize, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'textElideMode'
        QtMocHelpers::PropertyData<Qt::TextElideMode>(73, 0x80000000 | 74, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'verticalScrollMode'
        QtMocHelpers::PropertyData<ScrollMode>(75, 0x80000000 | 76, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'horizontalScrollMode'
        QtMocHelpers::PropertyData<ScrollMode>(77, 0x80000000 | 76, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'updateThreshold'
        QtMocHelpers::PropertyData<int>(78, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SelectionMode'
        QtMocHelpers::EnumData<SelectionMode>(69, 69, QMC::EnumFlags{}).add({
            {   79, SelectionMode::NoSelection },
            {   80, SelectionMode::SingleSelection },
            {   81, SelectionMode::MultiSelection },
            {   82, SelectionMode::ExtendedSelection },
            {   83, SelectionMode::ContiguousSelection },
        }),
        // enum 'SelectionBehavior'
        QtMocHelpers::EnumData<SelectionBehavior>(71, 71, QMC::EnumFlags{}).add({
            {   84, SelectionBehavior::SelectItems },
            {   85, SelectionBehavior::SelectRows },
            {   86, SelectionBehavior::SelectColumns },
        }),
        // enum 'ScrollHint'
        QtMocHelpers::EnumData<ScrollHint>(87, 87, QMC::EnumFlags{}).add({
            {   88, ScrollHint::EnsureVisible },
            {   89, ScrollHint::PositionAtTop },
            {   90, ScrollHint::PositionAtBottom },
            {   91, ScrollHint::PositionAtCenter },
        }),
        // enum 'EditTriggers'
        QtMocHelpers::EnumData<EditTriggers>(58, 92, QMC::EnumFlags{}).add({
            {   93, EditTrigger::NoEditTriggers },
            {   94, EditTrigger::CurrentChanged },
            {   95, EditTrigger::DoubleClicked },
            {   96, EditTrigger::SelectedClicked },
            {   97, EditTrigger::EditKeyPressed },
            {   98, EditTrigger::AnyKeyPressed },
            {   99, EditTrigger::AllEditTriggers },
        }),
        // enum 'ScrollMode'
        QtMocHelpers::EnumData<ScrollMode>(76, 76, QMC::EnumFlags{}).add({
            {  100, ScrollMode::ScrollPerItem },
            {  101, ScrollMode::ScrollPerPixel },
        }),
        // enum 'DragDropMode'
        QtMocHelpers::EnumData<DragDropMode>(64, 64, QMC::EnumFlags{}).add({
            {  102, DragDropMode::NoDragDrop },
            {  103, DragDropMode::DragOnly },
            {  104, DragDropMode::DropOnly },
            {  105, DragDropMode::DragDrop },
            {  106, DragDropMode::InternalMove },
        }),
    };
    return QtMocHelpers::metaObjectData<QAbstractItemView, qt_meta_tag_ZN17QAbstractItemViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractItemView::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractScrollArea::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QAbstractItemViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QAbstractItemViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QAbstractItemViewE_t>.metaTypes,
    nullptr
} };

void QAbstractItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractItemView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->pressed((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 3: _t->activated((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 4: _t->entered((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 5: _t->viewportEntered(); break;
        case 6: _t->iconSizeChanged((*reinterpret_cast< std::add_pointer_t<QSize>>(_a[1]))); break;
        case 7: _t->reset(); break;
        case 8: _t->setRootIndex((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 9: _t->doItemsLayout(); break;
        case 10: _t->selectAll(); break;
        case 11: _t->edit((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 12: _t->clearSelection(); break;
        case 13: _t->setCurrentIndex((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 14: _t->scrollToTop(); break;
        case 15: _t->scrollToBottom(); break;
        case 16: _t->update((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 17: _t->dataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[3]))); break;
        case 18: _t->dataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 19: _t->rowsInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 20: _t->rowsAboutToBeRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 21: _t->selectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 22: _t->currentChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 23: _t->updateEditorData(); break;
        case 24: _t->updateEditorGeometries(); break;
        case 25: _t->updateGeometries(); break;
        case 26: _t->verticalScrollbarAction((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->horizontalScrollbarAction((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->verticalScrollbarValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->horizontalScrollbarValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->closeEditor((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractItemDelegate::EndEditHint>>(_a[2]))); break;
        case 31: _t->commitData((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 32: _t->editorDestroyed((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 17:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        case 30:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        case 31:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemView::*)(const QModelIndex & )>(_a, &QAbstractItemView::pressed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemView::*)(const QModelIndex & )>(_a, &QAbstractItemView::clicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemView::*)(const QModelIndex & )>(_a, &QAbstractItemView::doubleClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemView::*)(const QModelIndex & )>(_a, &QAbstractItemView::activated, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemView::*)(const QModelIndex & )>(_a, &QAbstractItemView::entered, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemView::*)()>(_a, &QAbstractItemView::viewportEntered, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemView::*)(const QSize & )>(_a, &QAbstractItemView::iconSizeChanged, 6))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->hasAutoScroll(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->autoScrollMargin(); break;
        case 2: QtMocHelpers::assignFlags<EditTriggers>(_v, _t->editTriggers()); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->tabKeyNavigation(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->showDropIndicator(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->dragEnabled(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->dragDropOverwriteMode(); break;
        case 7: *reinterpret_cast<DragDropMode*>(_v) = _t->dragDropMode(); break;
        case 8: *reinterpret_cast<Qt::DropAction*>(_v) = _t->defaultDropAction(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->alternatingRowColors(); break;
        case 10: *reinterpret_cast<SelectionMode*>(_v) = _t->selectionMode(); break;
        case 11: *reinterpret_cast<SelectionBehavior*>(_v) = _t->selectionBehavior(); break;
        case 12: *reinterpret_cast<QSize*>(_v) = _t->iconSize(); break;
        case 13: *reinterpret_cast<Qt::TextElideMode*>(_v) = _t->textElideMode(); break;
        case 14: *reinterpret_cast<ScrollMode*>(_v) = _t->verticalScrollMode(); break;
        case 15: *reinterpret_cast<ScrollMode*>(_v) = _t->horizontalScrollMode(); break;
        case 16: *reinterpret_cast<int*>(_v) = _t->updateThreshold(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAutoScroll(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setAutoScrollMargin(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setEditTriggers(*reinterpret_cast<EditTriggers*>(_v)); break;
        case 3: _t->setTabKeyNavigation(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setDropIndicatorShown(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setDragEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setDragDropOverwriteMode(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setDragDropMode(*reinterpret_cast<DragDropMode*>(_v)); break;
        case 8: _t->setDefaultDropAction(*reinterpret_cast<Qt::DropAction*>(_v)); break;
        case 9: _t->setAlternatingRowColors(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setSelectionMode(*reinterpret_cast<SelectionMode*>(_v)); break;
        case 11: _t->setSelectionBehavior(*reinterpret_cast<SelectionBehavior*>(_v)); break;
        case 12: _t->setIconSize(*reinterpret_cast<QSize*>(_v)); break;
        case 13: _t->setTextElideMode(*reinterpret_cast<Qt::TextElideMode*>(_v)); break;
        case 14: _t->setVerticalScrollMode(*reinterpret_cast<ScrollMode*>(_v)); break;
        case 15: _t->setHorizontalScrollMode(*reinterpret_cast<ScrollMode*>(_v)); break;
        case 16: _t->setUpdateThreshold(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 14: _t->resetVerticalScrollMode(); break;
        case 15: _t->resetHorizontalScrollMode(); break;
        default: break;
        }
    }
}

const QMetaObject *QAbstractItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QAbstractItemViewE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractScrollArea::qt_metacast(_clname);
}

int QAbstractItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 33)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 33;
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
void QAbstractItemView::pressed(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QAbstractItemView::clicked(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QAbstractItemView::doubleClicked(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QAbstractItemView::activated(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QAbstractItemView::entered(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QAbstractItemView::viewportEntered()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QAbstractItemView::iconSizeChanged(const QSize & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}
QT_WARNING_POP
