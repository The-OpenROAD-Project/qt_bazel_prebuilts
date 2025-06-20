/****************************************************************************
** Meta object code from reading C++ file 'qtreeview.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qtreeview.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtreeview.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QTreeViewE_t {};
} // unnamed namespace

template <> constexpr inline auto QTreeView::qt_create_metaobjectdata<qt_meta_tag_ZN9QTreeViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTreeView",
        "expanded",
        "",
        "QModelIndex",
        "index",
        "collapsed",
        "hideColumn",
        "column",
        "showColumn",
        "expand",
        "collapse",
        "resizeColumnToContents",
        "sortByColumn",
        "Qt::SortOrder",
        "order",
        "expandAll",
        "expandRecursively",
        "depth",
        "collapseAll",
        "expandToDepth",
        "columnResized",
        "oldSize",
        "newSize",
        "columnCountChanged",
        "oldCount",
        "newCount",
        "columnMoved",
        "reexpand",
        "rowsRemoved",
        "parent",
        "first",
        "last",
        "verticalScrollbarValueChanged",
        "value",
        "autoExpandDelay",
        "indentation",
        "rootIsDecorated",
        "uniformRowHeights",
        "itemsExpandable",
        "sortingEnabled",
        "animated",
        "allColumnsShowFocus",
        "wordWrap",
        "headerHidden",
        "expandsOnDoubleClick"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'expanded'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'collapsed'
        QtMocHelpers::SignalData<void(const QModelIndex &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'hideColumn'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'showColumn'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'expand'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'collapse'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'resizeColumnToContents'
        QtMocHelpers::SlotData<void(int)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'sortByColumn'
        QtMocHelpers::SlotData<void(int, Qt::SortOrder)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { 0x80000000 | 13, 14 },
        }}),
        // Slot 'expandAll'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'expandRecursively'
        QtMocHelpers::SlotData<void(const QModelIndex &, int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 17 },
        }}),
        // Slot 'expandRecursively'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(16, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'collapseAll'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'expandToDepth'
        QtMocHelpers::SlotData<void(int)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 17 },
        }}),
        // Slot 'columnResized'
        QtMocHelpers::SlotData<void(int, int, int)>(20, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { QMetaType::Int, 21 }, { QMetaType::Int, 22 },
        }}),
        // Slot 'columnCountChanged'
        QtMocHelpers::SlotData<void(int, int)>(23, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 24 }, { QMetaType::Int, 25 },
        }}),
        // Slot 'columnMoved'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'reexpand'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot 'rowsRemoved'
        QtMocHelpers::SlotData<void(const QModelIndex &, int, int)>(28, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 3, 29 }, { QMetaType::Int, 30 }, { QMetaType::Int, 31 },
        }}),
        // Slot 'verticalScrollbarValueChanged'
        QtMocHelpers::SlotData<void(int)>(32, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 33 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'autoExpandDelay'
        QtMocHelpers::PropertyData<int>(34, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'indentation'
        QtMocHelpers::PropertyData<int>(35, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'rootIsDecorated'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'uniformRowHeights'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'itemsExpandable'
        QtMocHelpers::PropertyData<bool>(38, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'sortingEnabled'
        QtMocHelpers::PropertyData<bool>(39, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'animated'
        QtMocHelpers::PropertyData<bool>(40, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'allColumnsShowFocus'
        QtMocHelpers::PropertyData<bool>(41, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'wordWrap'
        QtMocHelpers::PropertyData<bool>(42, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'headerHidden'
        QtMocHelpers::PropertyData<bool>(43, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'expandsOnDoubleClick'
        QtMocHelpers::PropertyData<bool>(44, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTreeView, qt_meta_tag_ZN9QTreeViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTreeView::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTreeViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTreeViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QTreeViewE_t>.metaTypes,
    nullptr
} };

void QTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTreeView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->expanded((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 1: _t->collapsed((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->hideColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->showColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->expand((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 5: _t->collapse((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 6: _t->resizeColumnToContents((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->sortByColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 8: _t->expandAll(); break;
        case 9: _t->expandRecursively((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->expandRecursively((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 11: _t->collapseAll(); break;
        case 12: _t->expandToDepth((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->columnResized((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 14: _t->columnCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 15: _t->columnMoved(); break;
        case 16: _t->reexpand(); break;
        case 17: _t->rowsRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 18: _t->verticalScrollbarValueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTreeView::*)(const QModelIndex & )>(_a, &QTreeView::expanded, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeView::*)(const QModelIndex & )>(_a, &QTreeView::collapsed, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->autoExpandDelay(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->indentation(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->rootIsDecorated(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->uniformRowHeights(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->itemsExpandable(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isSortingEnabled(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isAnimated(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->allColumnsShowFocus(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->wordWrap(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->isHeaderHidden(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->expandsOnDoubleClick(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setAutoExpandDelay(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setIndentation(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setRootIsDecorated(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setUniformRowHeights(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setItemsExpandable(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setSortingEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setAnimated(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setAllColumnsShowFocus(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setWordWrap(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setHeaderHidden(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setExpandsOnDoubleClick(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 1: _t->resetIndentation(); break;
        default: break;
        }
    }
}

const QMetaObject *QTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTreeViewE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractItemView::qt_metacast(_clname);
}

int QTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QTreeView::expanded(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QTreeView::collapsed(const QModelIndex & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
