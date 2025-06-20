/****************************************************************************
** Meta object code from reading C++ file 'qtableview.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qtableview.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtableview.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QTableViewE_t {};
} // unnamed namespace

template <> constexpr inline auto QTableView::qt_create_metaobjectdata<qt_meta_tag_ZN10QTableViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTableView",
        "selectRow",
        "",
        "row",
        "selectColumn",
        "column",
        "hideRow",
        "hideColumn",
        "showRow",
        "showColumn",
        "resizeRowToContents",
        "resizeRowsToContents",
        "resizeColumnToContents",
        "resizeColumnsToContents",
        "sortByColumn",
        "Qt::SortOrder",
        "order",
        "setShowGrid",
        "show",
        "rowMoved",
        "oldIndex",
        "newIndex",
        "columnMoved",
        "rowResized",
        "oldHeight",
        "newHeight",
        "columnResized",
        "oldWidth",
        "newWidth",
        "rowCountChanged",
        "oldCount",
        "newCount",
        "columnCountChanged",
        "showGrid",
        "gridStyle",
        "Qt::PenStyle",
        "sortingEnabled",
        "wordWrap",
        "cornerButtonEnabled"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'selectRow'
        QtMocHelpers::SlotData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'selectColumn'
        QtMocHelpers::SlotData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'hideRow'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'hideColumn'
        QtMocHelpers::SlotData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'showRow'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'showColumn'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'resizeRowToContents'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'resizeRowsToContents'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resizeColumnToContents'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'resizeColumnsToContents'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'sortByColumn'
        QtMocHelpers::SlotData<void(int, Qt::SortOrder)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { 0x80000000 | 15, 16 },
        }}),
        // Slot 'setShowGrid'
        QtMocHelpers::SlotData<void(bool)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 },
        }}),
        // Slot 'rowMoved'
        QtMocHelpers::SlotData<void(int, int, int)>(19, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Int, 20 }, { QMetaType::Int, 21 },
        }}),
        // Slot 'columnMoved'
        QtMocHelpers::SlotData<void(int, int, int)>(22, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::Int, 20 }, { QMetaType::Int, 21 },
        }}),
        // Slot 'rowResized'
        QtMocHelpers::SlotData<void(int, int, int)>(23, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { QMetaType::Int, 24 }, { QMetaType::Int, 25 },
        }}),
        // Slot 'columnResized'
        QtMocHelpers::SlotData<void(int, int, int)>(26, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::Int, 27 }, { QMetaType::Int, 28 },
        }}),
        // Slot 'rowCountChanged'
        QtMocHelpers::SlotData<void(int, int)>(29, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 30 }, { QMetaType::Int, 31 },
        }}),
        // Slot 'columnCountChanged'
        QtMocHelpers::SlotData<void(int, int)>(32, 2, QMC::AccessProtected, QMetaType::Void, {{
            { QMetaType::Int, 30 }, { QMetaType::Int, 31 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'showGrid'
        QtMocHelpers::PropertyData<bool>(33, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'gridStyle'
        QtMocHelpers::PropertyData<Qt::PenStyle>(34, 0x80000000 | 35, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'sortingEnabled'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'wordWrap'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'cornerButtonEnabled'
        QtMocHelpers::PropertyData<bool>(38, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTableView, qt_meta_tag_ZN10QTableViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTableView::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QTableViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QTableViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QTableViewE_t>.metaTypes,
    nullptr
} };

void QTableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTableView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->selectRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->selectColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->hideRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->hideColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->showRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->showColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->resizeRowToContents((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->resizeRowsToContents(); break;
        case 8: _t->resizeColumnToContents((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->resizeColumnsToContents(); break;
        case 10: _t->sortByColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 11: _t->setShowGrid((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 12: _t->rowMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 13: _t->columnMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 14: _t->rowResized((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 15: _t->columnResized((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 16: _t->rowCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 17: _t->columnCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->showGrid(); break;
        case 1: *reinterpret_cast<Qt::PenStyle*>(_v) = _t->gridStyle(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isSortingEnabled(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->wordWrap(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isCornerButtonEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShowGrid(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setGridStyle(*reinterpret_cast<Qt::PenStyle*>(_v)); break;
        case 2: _t->setSortingEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setWordWrap(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setCornerButtonEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTableView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QTableViewE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractItemView::qt_metacast(_clname);
}

int QTableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
