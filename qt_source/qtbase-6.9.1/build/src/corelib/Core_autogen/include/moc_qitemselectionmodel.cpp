/****************************************************************************
** Meta object code from reading C++ file 'qitemselectionmodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/itemmodels/qitemselectionmodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qitemselectionmodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QItemSelectionModelE_t {};
} // unnamed namespace

template <> constexpr inline auto QItemSelectionModel::qt_create_metaobjectdata<qt_meta_tag_ZN19QItemSelectionModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QItemSelectionModel",
        "selectionChanged",
        "",
        "QItemSelection",
        "selected",
        "deselected",
        "currentChanged",
        "QModelIndex",
        "current",
        "previous",
        "currentRowChanged",
        "currentColumnChanged",
        "modelChanged",
        "QAbstractItemModel*",
        "model",
        "setCurrentIndex",
        "index",
        "QItemSelectionModel::SelectionFlags",
        "command",
        "select",
        "selection",
        "clear",
        "reset",
        "clearSelection",
        "clearCurrentIndex",
        "isSelected",
        "isRowSelected",
        "row",
        "parent",
        "isColumnSelected",
        "column",
        "rowIntersectsSelection",
        "columnIntersectsSelection",
        "selectedRows",
        "QModelIndexList",
        "selectedColumns",
        "hasSelection",
        "currentIndex",
        "selectedIndexes",
        "SelectionFlags",
        "SelectionFlag",
        "NoUpdate",
        "Clear",
        "Select",
        "Deselect",
        "Toggle",
        "Current",
        "Rows",
        "Columns",
        "SelectCurrent",
        "ToggleCurrent",
        "ClearAndSelect"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void(const QItemSelection &, const QItemSelection &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 },
        }}),
        // Signal 'currentChanged'
        QtMocHelpers::SignalData<void(const QModelIndex &, const QModelIndex &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 },
        }}),
        // Signal 'currentRowChanged'
        QtMocHelpers::SignalData<void(const QModelIndex &, const QModelIndex &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 },
        }}),
        // Signal 'currentColumnChanged'
        QtMocHelpers::SignalData<void(const QModelIndex &, const QModelIndex &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 },
        }}),
        // Signal 'modelChanged'
        QtMocHelpers::SignalData<void(QAbstractItemModel *)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Slot 'setCurrentIndex'
        QtMocHelpers::SlotData<void(const QModelIndex &, QItemSelectionModel::SelectionFlags)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 16 }, { 0x80000000 | 17, 18 },
        }}),
        // Slot 'select'
        QtMocHelpers::SlotData<void(const QModelIndex &, QItemSelectionModel::SelectionFlags)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 16 }, { 0x80000000 | 17, 18 },
        }}),
        // Slot 'select'
        QtMocHelpers::SlotData<void(const QItemSelection &, QItemSelectionModel::SelectionFlags)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { 0x80000000 | 17, 18 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'reset'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clearSelection'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clearCurrentIndex'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'isSelected'
        QtMocHelpers::MethodData<bool(const QModelIndex &) const>(25, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 7, 16 },
        }}),
        // Method 'isRowSelected'
        QtMocHelpers::MethodData<bool(int, const QModelIndex &) const>(26, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 27 }, { 0x80000000 | 7, 28 },
        }}),
        // Method 'isRowSelected'
        QtMocHelpers::MethodData<bool(int) const>(26, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::Int, 27 },
        }}),
        // Method 'isColumnSelected'
        QtMocHelpers::MethodData<bool(int, const QModelIndex &) const>(29, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 30 }, { 0x80000000 | 7, 28 },
        }}),
        // Method 'isColumnSelected'
        QtMocHelpers::MethodData<bool(int) const>(29, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::Int, 30 },
        }}),
        // Method 'rowIntersectsSelection'
        QtMocHelpers::MethodData<bool(int, const QModelIndex &) const>(31, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 27 }, { 0x80000000 | 7, 28 },
        }}),
        // Method 'rowIntersectsSelection'
        QtMocHelpers::MethodData<bool(int) const>(31, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::Int, 27 },
        }}),
        // Method 'columnIntersectsSelection'
        QtMocHelpers::MethodData<bool(int, const QModelIndex &) const>(32, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 30 }, { 0x80000000 | 7, 28 },
        }}),
        // Method 'columnIntersectsSelection'
        QtMocHelpers::MethodData<bool(int) const>(32, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::Int, 30 },
        }}),
        // Method 'selectedRows'
        QtMocHelpers::MethodData<QModelIndexList(int) const>(33, 2, QMC::AccessPublic, 0x80000000 | 34, {{
            { QMetaType::Int, 30 },
        }}),
        // Method 'selectedRows'
        QtMocHelpers::MethodData<QModelIndexList() const>(33, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 34),
        // Method 'selectedColumns'
        QtMocHelpers::MethodData<QModelIndexList(int) const>(35, 2, QMC::AccessPublic, 0x80000000 | 34, {{
            { QMetaType::Int, 27 },
        }}),
        // Method 'selectedColumns'
        QtMocHelpers::MethodData<QModelIndexList() const>(35, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 34),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'model'
        QtMocHelpers::PropertyData<QAbstractItemModel*>(14, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 4),
        // property 'hasSelection'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::Readable | QMC::Scriptable, 0),
        // property 'currentIndex'
        QtMocHelpers::PropertyData<QModelIndex>(37, 0x80000000 | 7, QMC::Readable | QMC::Scriptable | QMC::EnumOrFlag, 1),
        // property 'selection'
        QtMocHelpers::PropertyData<QItemSelection>(20, 0x80000000 | 3, QMC::Readable | QMC::Scriptable | QMC::EnumOrFlag, 0),
        // property 'selectedIndexes'
        QtMocHelpers::PropertyData<QModelIndexList>(38, 0x80000000 | 34, QMC::Readable | QMC::Scriptable | QMC::EnumOrFlag, 0),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SelectionFlags'
        QtMocHelpers::EnumData<SelectionFlags>(39, 40, QMC::EnumFlags{}).add({
            {   41, SelectionFlag::NoUpdate },
            {   42, SelectionFlag::Clear },
            {   43, SelectionFlag::Select },
            {   44, SelectionFlag::Deselect },
            {   45, SelectionFlag::Toggle },
            {   46, SelectionFlag::Current },
            {   47, SelectionFlag::Rows },
            {   48, SelectionFlag::Columns },
            {   49, SelectionFlag::SelectCurrent },
            {   50, SelectionFlag::ToggleCurrent },
            {   51, SelectionFlag::ClearAndSelect },
        }),
    };
    return QtMocHelpers::metaObjectData<QItemSelectionModel, qt_meta_tag_ZN19QItemSelectionModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QItemSelectionModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QItemSelectionModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QItemSelectionModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QItemSelectionModelE_t>.metaTypes,
    nullptr
} };

void QItemSelectionModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QItemSelectionModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[2]))); break;
        case 1: _t->currentChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 2: _t->currentRowChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 3: _t->currentColumnChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 4: _t->modelChanged((*reinterpret_cast< std::add_pointer_t<QAbstractItemModel*>>(_a[1]))); break;
        case 5: _t->setCurrentIndex((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelectionModel::SelectionFlags>>(_a[2]))); break;
        case 6: _t->select((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelectionModel::SelectionFlags>>(_a[2]))); break;
        case 7: _t->select((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QItemSelectionModel::SelectionFlags>>(_a[2]))); break;
        case 8: _t->clear(); break;
        case 9: _t->reset(); break;
        case 10: _t->clearSelection(); break;
        case 11: _t->clearCurrentIndex(); break;
        case 12: { bool _r = _t->isSelected((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: { bool _r = _t->isRowSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->isRowSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->isColumnSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { bool _r = _t->isColumnSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 17: { bool _r = _t->rowIntersectsSelection((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: { bool _r = _t->rowIntersectsSelection((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 19: { bool _r = _t->columnIntersectsSelection((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 20: { bool _r = _t->columnIntersectsSelection((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 21: { QModelIndexList _r = _t->selectedRows((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QModelIndexList*>(_a[0]) = std::move(_r); }  break;
        case 22: { QModelIndexList _r = _t->selectedRows();
            if (_a[0]) *reinterpret_cast< QModelIndexList*>(_a[0]) = std::move(_r); }  break;
        case 23: { QModelIndexList _r = _t->selectedColumns((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QModelIndexList*>(_a[0]) = std::move(_r); }  break;
        case 24: { QModelIndexList _r = _t->selectedColumns();
            if (_a[0]) *reinterpret_cast< QModelIndexList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractItemModel* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QItemSelection >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QItemSelectionModel::*)(const QItemSelection & , const QItemSelection & )>(_a, &QItemSelectionModel::selectionChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QItemSelectionModel::*)(const QModelIndex & , const QModelIndex & )>(_a, &QItemSelectionModel::currentChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QItemSelectionModel::*)(const QModelIndex & , const QModelIndex & )>(_a, &QItemSelectionModel::currentRowChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QItemSelectionModel::*)(const QModelIndex & , const QModelIndex & )>(_a, &QItemSelectionModel::currentColumnChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QItemSelectionModel::*)(QAbstractItemModel * )>(_a, &QItemSelectionModel::modelChanged, 4))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractItemModel* >(); break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
        case 4:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QModelIndexList >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QAbstractItemModel**>(_v) = _t->model(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->hasSelection(); break;
        case 2: *reinterpret_cast<QModelIndex*>(_v) = _t->currentIndex(); break;
        case 3: *reinterpret_cast<QItemSelection*>(_v) = _t->selection(); break;
        case 4: *reinterpret_cast<QModelIndexList*>(_v) = _t->selectedIndexes(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setModel(*reinterpret_cast<QAbstractItemModel**>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableModel(); break;
        default: break;
        }
    }
}

const QMetaObject *QItemSelectionModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QItemSelectionModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QItemSelectionModelE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QItemSelectionModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QItemSelectionModel::selectionChanged(const QItemSelection & _t1, const QItemSelection & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QItemSelectionModel::currentChanged(const QModelIndex & _t1, const QModelIndex & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QItemSelectionModel::currentRowChanged(const QModelIndex & _t1, const QModelIndex & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QItemSelectionModel::currentColumnChanged(const QModelIndex & _t1, const QModelIndex & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void QItemSelectionModel::modelChanged(QAbstractItemModel * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
