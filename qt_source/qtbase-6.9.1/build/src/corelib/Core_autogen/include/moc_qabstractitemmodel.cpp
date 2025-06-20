/****************************************************************************
** Meta object code from reading C++ file 'qabstractitemmodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/itemmodels/qabstractitemmodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractitemmodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QAbstractItemModelE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractItemModel::qt_create_metaobjectdata<qt_meta_tag_ZN18QAbstractItemModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractItemModel",
        "dataChanged",
        "",
        "QModelIndex",
        "topLeft",
        "bottomRight",
        "QList<int>",
        "roles",
        "headerDataChanged",
        "Qt::Orientation",
        "orientation",
        "first",
        "last",
        "layoutChanged",
        "QList<QPersistentModelIndex>",
        "parents",
        "QAbstractItemModel::LayoutChangeHint",
        "hint",
        "layoutAboutToBeChanged",
        "rowsAboutToBeInserted",
        "parent",
        "rowsInserted",
        "rowsAboutToBeRemoved",
        "rowsRemoved",
        "columnsAboutToBeInserted",
        "columnsInserted",
        "columnsAboutToBeRemoved",
        "columnsRemoved",
        "modelAboutToBeReset",
        "modelReset",
        "rowsAboutToBeMoved",
        "sourceParent",
        "sourceStart",
        "sourceEnd",
        "destinationParent",
        "destinationRow",
        "rowsMoved",
        "columnsAboutToBeMoved",
        "destinationColumn",
        "columnsMoved",
        "submit",
        "revert",
        "resetInternalData",
        "hasIndex",
        "row",
        "column",
        "index",
        "child",
        "sibling",
        "idx",
        "rowCount",
        "columnCount",
        "hasChildren",
        "data",
        "QVariant",
        "role",
        "setData",
        "value",
        "headerData",
        "section",
        "insertRows",
        "count",
        "insertColumns",
        "removeRows",
        "removeColumns",
        "moveRows",
        "sourceRow",
        "destinationChild",
        "moveColumns",
        "sourceColumn",
        "insertRow",
        "insertColumn",
        "removeRow",
        "removeColumn",
        "moveRow",
        "moveColumn",
        "fetchMore",
        "canFetchMore",
        "flags",
        "Qt::ItemFlags",
        "sort",
        "Qt::SortOrder",
        "order",
        "match",
        "QModelIndexList",
        "start",
        "hits",
        "Qt::MatchFlags",
        "LayoutChangeHint",
        "NoLayoutChangeHint",
        "VerticalSortHint",
        "HorizontalSortHint",
        "CheckIndexOption",
        "NoOption",
        "IndexIsValid",
        "DoNotUseParent",
        "ParentIsInvalid"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dataChanged'
        QtMocHelpers::SignalData<void(const QModelIndex &, const QModelIndex &, const QList<int> &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 }, { 0x80000000 | 6, 7 },
        }}),
        // Signal 'dataChanged'
        QtMocHelpers::SignalData<void(const QModelIndex &, const QModelIndex &)>(1, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 },
        }}),
        // Signal 'headerDataChanged'
        QtMocHelpers::SignalData<void(Qt::Orientation, int, int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'layoutChanged'
        QtMocHelpers::SignalData<void(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 15 }, { 0x80000000 | 16, 17 },
        }}),
        // Signal 'layoutChanged'
        QtMocHelpers::SignalData<void(const QList<QPersistentModelIndex> &)>(13, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
        // Signal 'layoutChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Signal 'layoutAboutToBeChanged'
        QtMocHelpers::SignalData<void(const QList<QPersistentModelIndex> &, QAbstractItemModel::LayoutChangeHint)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 14, 15 }, { 0x80000000 | 16, 17 },
        }}),
        // Signal 'layoutAboutToBeChanged'
        QtMocHelpers::SignalData<void(const QList<QPersistentModelIndex> &)>(18, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 14, 15 },
        }}),
        // Signal 'layoutAboutToBeChanged'
        QtMocHelpers::SignalData<void()>(18, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Signal 'rowsAboutToBeInserted'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'rowsInserted'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'rowsAboutToBeRemoved'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'rowsRemoved'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'columnsAboutToBeInserted'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'columnsInserted'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'columnsAboutToBeRemoved'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int)>(26, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'columnsRemoved'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 }, { QMetaType::Int, 11 }, { QMetaType::Int, 12 },
        }}),
        // Signal 'modelAboutToBeReset'
        QtMocHelpers::SignalData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'modelReset'
        QtMocHelpers::SignalData<void()>(29, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rowsAboutToBeMoved'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int, const QModelIndex &, int)>(30, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 31 }, { QMetaType::Int, 32 }, { QMetaType::Int, 33 }, { 0x80000000 | 3, 34 },
            { QMetaType::Int, 35 },
        }}),
        // Signal 'rowsMoved'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int, const QModelIndex &, int)>(36, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 31 }, { QMetaType::Int, 32 }, { QMetaType::Int, 33 }, { 0x80000000 | 3, 34 },
            { QMetaType::Int, 35 },
        }}),
        // Signal 'columnsAboutToBeMoved'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int, const QModelIndex &, int)>(37, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 31 }, { QMetaType::Int, 32 }, { QMetaType::Int, 33 }, { 0x80000000 | 3, 34 },
            { QMetaType::Int, 38 },
        }}),
        // Signal 'columnsMoved'
        QtMocHelpers::SignalData<void(const QModelIndex &, int, int, const QModelIndex &, int)>(39, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 31 }, { QMetaType::Int, 32 }, { QMetaType::Int, 33 }, { 0x80000000 | 3, 34 },
            { QMetaType::Int, 38 },
        }}),
        // Slot 'submit'
        QtMocHelpers::SlotData<bool()>(40, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'revert'
        QtMocHelpers::SlotData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resetInternalData'
        QtMocHelpers::SlotData<void()>(42, 2, QMC::AccessProtected, QMetaType::Void),
        // Method 'hasIndex'
        QtMocHelpers::MethodData<bool(int, int, const QModelIndex &) const>(43, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 45 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'hasIndex'
        QtMocHelpers::MethodData<bool(int, int) const>(43, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 45 },
        }}),
        // Method 'index'
        QtMocHelpers::MethodData<QModelIndex(int, int, const QModelIndex &) const>(46, 2, QMC::AccessPublic, 0x80000000 | 3, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 45 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'index'
        QtMocHelpers::MethodData<QModelIndex(int, int) const>(46, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 3, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 45 },
        }}),
        // Method 'parent'
        QtMocHelpers::MethodData<QModelIndex(const QModelIndex &) const>(20, 2, QMC::AccessPublic, 0x80000000 | 3, {{
            { 0x80000000 | 3, 47 },
        }}),
        // Method 'sibling'
        QtMocHelpers::MethodData<QModelIndex(int, int, const QModelIndex &) const>(48, 2, QMC::AccessPublic, 0x80000000 | 3, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 45 }, { 0x80000000 | 3, 49 },
        }}),
        // Method 'rowCount'
        QtMocHelpers::MethodData<int(const QModelIndex &) const>(50, 2, QMC::AccessPublic, QMetaType::Int, {{
            { 0x80000000 | 3, 20 },
        }}),
        // Method 'rowCount'
        QtMocHelpers::MethodData<int() const>(50, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Int),
        // Method 'columnCount'
        QtMocHelpers::MethodData<int(const QModelIndex &) const>(51, 2, QMC::AccessPublic, QMetaType::Int, {{
            { 0x80000000 | 3, 20 },
        }}),
        // Method 'columnCount'
        QtMocHelpers::MethodData<int() const>(51, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Int),
        // Method 'hasChildren'
        QtMocHelpers::MethodData<bool(const QModelIndex &) const>(52, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 20 },
        }}),
        // Method 'hasChildren'
        QtMocHelpers::MethodData<bool() const>(52, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool),
        // Method 'data'
        QtMocHelpers::MethodData<QVariant(const QModelIndex &, int) const>(53, 2, QMC::AccessPublic, 0x80000000 | 54, {{
            { 0x80000000 | 3, 46 }, { QMetaType::Int, 55 },
        }}),
        // Method 'data'
        QtMocHelpers::MethodData<QVariant(const QModelIndex &) const>(53, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 54, {{
            { 0x80000000 | 3, 46 },
        }}),
        // Method 'setData'
        QtMocHelpers::MethodData<bool(const QModelIndex &, const QVariant &, int)>(56, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 46 }, { 0x80000000 | 54, 57 }, { QMetaType::Int, 55 },
        }}),
        // Method 'setData'
        QtMocHelpers::MethodData<bool(const QModelIndex &, const QVariant &)>(56, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Bool, {{
            { 0x80000000 | 3, 46 }, { 0x80000000 | 54, 57 },
        }}),
        // Method 'headerData'
        QtMocHelpers::MethodData<QVariant(int, Qt::Orientation, int) const>(58, 2, QMC::AccessPublic, 0x80000000 | 54, {{
            { QMetaType::Int, 59 }, { 0x80000000 | 9, 10 }, { QMetaType::Int, 55 },
        }}),
        // Method 'headerData'
        QtMocHelpers::MethodData<QVariant(int, Qt::Orientation) const>(58, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 54, {{
            { QMetaType::Int, 59 }, { 0x80000000 | 9, 10 },
        }}),
        // Method 'insertRows'
        QtMocHelpers::RevisionedMethodData<bool(int, int, const QModelIndex &)>(60, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 61 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'insertRows'
        QtMocHelpers::RevisionedMethodData<bool(int, int)>(60, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 61 },
        }}),
        // Method 'insertColumns'
        QtMocHelpers::RevisionedMethodData<bool(int, int, const QModelIndex &)>(62, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 45 }, { QMetaType::Int, 61 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'insertColumns'
        QtMocHelpers::RevisionedMethodData<bool(int, int)>(62, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 45 }, { QMetaType::Int, 61 },
        }}),
        // Method 'removeRows'
        QtMocHelpers::RevisionedMethodData<bool(int, int, const QModelIndex &)>(63, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 61 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'removeRows'
        QtMocHelpers::RevisionedMethodData<bool(int, int)>(63, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 44 }, { QMetaType::Int, 61 },
        }}),
        // Method 'removeColumns'
        QtMocHelpers::RevisionedMethodData<bool(int, int, const QModelIndex &)>(64, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 45 }, { QMetaType::Int, 61 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'removeColumns'
        QtMocHelpers::RevisionedMethodData<bool(int, int)>(64, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 45 }, { QMetaType::Int, 61 },
        }}),
        // Method 'moveRows'
        QtMocHelpers::RevisionedMethodData<bool(const QModelIndex &, int, int, const QModelIndex &, int)>(65, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { 0x80000000 | 3, 31 }, { QMetaType::Int, 66 }, { QMetaType::Int, 61 }, { 0x80000000 | 3, 34 },
            { QMetaType::Int, 67 },
        }}),
        // Method 'moveColumns'
        QtMocHelpers::RevisionedMethodData<bool(const QModelIndex &, int, int, const QModelIndex &, int)>(68, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { 0x80000000 | 3, 31 }, { QMetaType::Int, 69 }, { QMetaType::Int, 61 }, { 0x80000000 | 3, 34 },
            { QMetaType::Int, 67 },
        }}),
        // Method 'insertRow'
        QtMocHelpers::RevisionedMethodData<bool(int, const QModelIndex &)>(70, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 44 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'insertRow'
        QtMocHelpers::RevisionedMethodData<bool(int)>(70, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 44 },
        }}),
        // Method 'insertColumn'
        QtMocHelpers::RevisionedMethodData<bool(int, const QModelIndex &)>(71, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 45 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'insertColumn'
        QtMocHelpers::RevisionedMethodData<bool(int)>(71, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 45 },
        }}),
        // Method 'removeRow'
        QtMocHelpers::RevisionedMethodData<bool(int, const QModelIndex &)>(72, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 44 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'removeRow'
        QtMocHelpers::RevisionedMethodData<bool(int)>(72, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 44 },
        }}),
        // Method 'removeColumn'
        QtMocHelpers::RevisionedMethodData<bool(int, const QModelIndex &)>(73, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 45 }, { 0x80000000 | 3, 20 },
        }}),
        // Method 'removeColumn'
        QtMocHelpers::RevisionedMethodData<bool(int)>(73, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Bool, {{
            { QMetaType::Int, 45 },
        }}),
        // Method 'moveRow'
        QtMocHelpers::RevisionedMethodData<bool(const QModelIndex &, int, const QModelIndex &, int)>(74, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { 0x80000000 | 3, 31 }, { QMetaType::Int, 66 }, { 0x80000000 | 3, 34 }, { QMetaType::Int, 67 },
        }}),
        // Method 'moveColumn'
        QtMocHelpers::RevisionedMethodData<bool(const QModelIndex &, int, const QModelIndex &, int)>(75, 2, QMC::AccessPublic, 0x604, QMetaType::Bool, {{
            { 0x80000000 | 3, 31 }, { QMetaType::Int, 69 }, { 0x80000000 | 3, 34 }, { QMetaType::Int, 67 },
        }}),
        // Method 'fetchMore'
        QtMocHelpers::MethodData<void(const QModelIndex &)>(76, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 20 },
        }}),
        // Method 'canFetchMore'
        QtMocHelpers::MethodData<bool(const QModelIndex &) const>(77, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { 0x80000000 | 3, 20 },
        }}),
        // Method 'flags'
        QtMocHelpers::MethodData<Qt::ItemFlags(const QModelIndex &) const>(78, 2, QMC::AccessPublic, 0x80000000 | 79, {{
            { 0x80000000 | 3, 46 },
        }}),
        // Method 'sort'
        QtMocHelpers::RevisionedMethodData<void(int, Qt::SortOrder)>(80, 2, QMC::AccessPublic, 0x604, QMetaType::Void, {{
            { QMetaType::Int, 45 }, { 0x80000000 | 81, 82 },
        }}),
        // Method 'sort'
        QtMocHelpers::RevisionedMethodData<void(int)>(80, 2, QMC::AccessPublic | QMC::MethodCloned, 0x604, QMetaType::Void, {{
            { QMetaType::Int, 45 },
        }}),
        // Method 'match'
        QtMocHelpers::MethodData<QModelIndexList(const QModelIndex &, int, const QVariant &, int, Qt::MatchFlags) const>(83, 2, QMC::AccessPublic, 0x80000000 | 84, {{
            { 0x80000000 | 3, 85 }, { QMetaType::Int, 55 }, { 0x80000000 | 54, 57 }, { QMetaType::Int, 86 },
            { 0x80000000 | 87, 78 },
        }}),
        // Method 'match'
        QtMocHelpers::MethodData<QModelIndexList(const QModelIndex &, int, const QVariant &, int) const>(83, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 84, {{
            { 0x80000000 | 3, 85 }, { QMetaType::Int, 55 }, { 0x80000000 | 54, 57 }, { QMetaType::Int, 86 },
        }}),
        // Method 'match'
        QtMocHelpers::MethodData<QModelIndexList(const QModelIndex &, int, const QVariant &) const>(83, 2, QMC::AccessPublic | QMC::MethodCloned, 0x80000000 | 84, {{
            { 0x80000000 | 3, 85 }, { QMetaType::Int, 55 }, { 0x80000000 | 54, 57 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'LayoutChangeHint'
        QtMocHelpers::EnumData<LayoutChangeHint>(88, 88, QMC::EnumFlags{}).add({
            {   89, LayoutChangeHint::NoLayoutChangeHint },
            {   90, LayoutChangeHint::VerticalSortHint },
            {   91, LayoutChangeHint::HorizontalSortHint },
        }),
        // enum 'CheckIndexOption'
        QtMocHelpers::EnumData<CheckIndexOption>(92, 92, QMC::EnumIsScoped).add({
            {   93, CheckIndexOption::NoOption },
            {   94, CheckIndexOption::IndexIsValid },
            {   95, CheckIndexOption::DoNotUseParent },
            {   96, CheckIndexOption::ParentIsInvalid },
        }),
    };
    return QtMocHelpers::metaObjectData<QAbstractItemModel, qt_meta_tag_ZN18QAbstractItemModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractItemModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractItemModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractItemModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QAbstractItemModelE_t>.metaTypes,
    nullptr
} };

void QAbstractItemModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractItemModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QList<int>>>(_a[3]))); break;
        case 1: _t->dataChanged((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 2: _t->headerDataChanged((*reinterpret_cast< std::add_pointer_t<Qt::Orientation>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->layoutChanged((*reinterpret_cast< std::add_pointer_t<QList<QPersistentModelIndex>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractItemModel::LayoutChangeHint>>(_a[2]))); break;
        case 4: _t->layoutChanged((*reinterpret_cast< std::add_pointer_t<QList<QPersistentModelIndex>>>(_a[1]))); break;
        case 5: _t->layoutChanged(); break;
        case 6: _t->layoutAboutToBeChanged((*reinterpret_cast< std::add_pointer_t<QList<QPersistentModelIndex>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractItemModel::LayoutChangeHint>>(_a[2]))); break;
        case 7: _t->layoutAboutToBeChanged((*reinterpret_cast< std::add_pointer_t<QList<QPersistentModelIndex>>>(_a[1]))); break;
        case 8: _t->layoutAboutToBeChanged(); break;
        case 9: _t->rowsAboutToBeInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])), QPrivateSignal()); break;
        case 10: _t->rowsInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])), QPrivateSignal()); break;
        case 11: _t->rowsAboutToBeRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])), QPrivateSignal()); break;
        case 12: _t->rowsRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])), QPrivateSignal()); break;
        case 13: _t->columnsAboutToBeInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])), QPrivateSignal()); break;
        case 14: _t->columnsInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])), QPrivateSignal()); break;
        case 15: _t->columnsAboutToBeRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])), QPrivateSignal()); break;
        case 16: _t->columnsRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])), QPrivateSignal()); break;
        case 17: _t->modelAboutToBeReset(QPrivateSignal()); break;
        case 18: _t->modelReset(QPrivateSignal()); break;
        case 19: _t->rowsAboutToBeMoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])), QPrivateSignal()); break;
        case 20: _t->rowsMoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])), QPrivateSignal()); break;
        case 21: _t->columnsAboutToBeMoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])), QPrivateSignal()); break;
        case 22: _t->columnsMoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])), QPrivateSignal()); break;
        case 23: { bool _r = _t->submit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 24: _t->revert(); break;
        case 25: _t->resetInternalData(); break;
        case 26: { bool _r = _t->hasIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: { bool _r = _t->hasIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: { QModelIndex _r = _t->index((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 29: { QModelIndex _r = _t->index((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 30: { QModelIndex _r = _t->parent((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 31: { QModelIndex _r = _t->sibling((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 32: { int _r = _t->rowCount((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 33: { int _r = _t->rowCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 34: { int _r = _t->columnCount((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 35: { int _r = _t->columnCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 36: { bool _r = _t->hasChildren((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 37: { bool _r = _t->hasChildren();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 38: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 39: { QVariant _r = _t->data((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 40: { bool _r = _t->setData((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 41: { bool _r = _t->setData((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 42: { QVariant _r = _t->headerData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::Orientation>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 43: { QVariant _r = _t->headerData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::Orientation>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 44: { bool _r = _t->insertRows((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 45: { bool _r = _t->insertRows((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 46: { bool _r = _t->insertColumns((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 47: { bool _r = _t->insertColumns((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 48: { bool _r = _t->removeRows((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 49: { bool _r = _t->removeRows((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 50: { bool _r = _t->removeColumns((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 51: { bool _r = _t->removeColumns((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 52: { bool _r = _t->moveRows((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 53: { bool _r = _t->moveColumns((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 54: { bool _r = _t->insertRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 55: { bool _r = _t->insertRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 56: { bool _r = _t->insertColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 57: { bool _r = _t->insertColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 58: { bool _r = _t->removeRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 59: { bool _r = _t->removeRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 60: { bool _r = _t->removeColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 61: { bool _r = _t->removeColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 62: { bool _r = _t->moveRow((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 63: { bool _r = _t->moveColumn((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 64: _t->fetchMore((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 65: { bool _r = _t->canFetchMore((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 66: { Qt::ItemFlags _r = _t->flags((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Qt::ItemFlags*>(_a[0]) = std::move(_r); }  break;
        case 67: _t->sort((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::SortOrder>>(_a[2]))); break;
        case 68: _t->sort((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 69: { QModelIndexList _r = _t->match((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<Qt::MatchFlags>>(_a[5])));
            if (_a[0]) *reinterpret_cast< QModelIndexList*>(_a[0]) = std::move(_r); }  break;
        case 70: { QModelIndexList _r = _t->match((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QModelIndexList*>(_a[0]) = std::move(_r); }  break;
        case 71: { QModelIndexList _r = _t->match((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3])));
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
            case 2:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<int> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , const QModelIndex & , const QList<int> & )>(_a, &QAbstractItemModel::dataChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(Qt::Orientation , int , int )>(_a, &QAbstractItemModel::headerDataChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QList<QPersistentModelIndex> & , QAbstractItemModel::LayoutChangeHint )>(_a, &QAbstractItemModel::layoutChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QList<QPersistentModelIndex> & , QAbstractItemModel::LayoutChangeHint )>(_a, &QAbstractItemModel::layoutAboutToBeChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , QPrivateSignal)>(_a, &QAbstractItemModel::rowsAboutToBeInserted, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , QPrivateSignal)>(_a, &QAbstractItemModel::rowsInserted, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , QPrivateSignal)>(_a, &QAbstractItemModel::rowsAboutToBeRemoved, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , QPrivateSignal)>(_a, &QAbstractItemModel::rowsRemoved, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , QPrivateSignal)>(_a, &QAbstractItemModel::columnsAboutToBeInserted, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , QPrivateSignal)>(_a, &QAbstractItemModel::columnsInserted, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , QPrivateSignal)>(_a, &QAbstractItemModel::columnsAboutToBeRemoved, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , QPrivateSignal)>(_a, &QAbstractItemModel::columnsRemoved, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(QPrivateSignal)>(_a, &QAbstractItemModel::modelAboutToBeReset, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(QPrivateSignal)>(_a, &QAbstractItemModel::modelReset, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , const QModelIndex & , int , QPrivateSignal)>(_a, &QAbstractItemModel::rowsAboutToBeMoved, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , const QModelIndex & , int , QPrivateSignal)>(_a, &QAbstractItemModel::rowsMoved, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , const QModelIndex & , int , QPrivateSignal)>(_a, &QAbstractItemModel::columnsAboutToBeMoved, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractItemModel::*)(const QModelIndex & , int , int , const QModelIndex & , int , QPrivateSignal)>(_a, &QAbstractItemModel::columnsMoved, 22))
            return;
    }
}

const QMetaObject *QAbstractItemModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractItemModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractItemModelE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QAbstractItemModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 72)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 72;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 72)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 72;
    }
    return _id;
}

// SIGNAL 0
void QAbstractItemModel::dataChanged(const QModelIndex & _t1, const QModelIndex & _t2, const QList<int> & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}

// SIGNAL 2
void QAbstractItemModel::headerDataChanged(Qt::Orientation _t1, int _t2, int _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3);
}

// SIGNAL 3
void QAbstractItemModel::layoutChanged(const QList<QPersistentModelIndex> & _t1, QAbstractItemModel::LayoutChangeHint _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 6
void QAbstractItemModel::layoutAboutToBeChanged(const QList<QPersistentModelIndex> & _t1, QAbstractItemModel::LayoutChangeHint _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 9
void QAbstractItemModel::rowsAboutToBeInserted(const QModelIndex & _t1, int _t2, int _t3, QPrivateSignal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 10
void QAbstractItemModel::rowsInserted(const QModelIndex & _t1, int _t2, int _t3, QPrivateSignal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 11
void QAbstractItemModel::rowsAboutToBeRemoved(const QModelIndex & _t1, int _t2, int _t3, QPrivateSignal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 12
void QAbstractItemModel::rowsRemoved(const QModelIndex & _t1, int _t2, int _t3, QPrivateSignal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 13
void QAbstractItemModel::columnsAboutToBeInserted(const QModelIndex & _t1, int _t2, int _t3, QPrivateSignal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 14
void QAbstractItemModel::columnsInserted(const QModelIndex & _t1, int _t2, int _t3, QPrivateSignal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 15
void QAbstractItemModel::columnsAboutToBeRemoved(const QModelIndex & _t1, int _t2, int _t3, QPrivateSignal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 15, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 16
void QAbstractItemModel::columnsRemoved(const QModelIndex & _t1, int _t2, int _t3, QPrivateSignal _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 17
void QAbstractItemModel::modelAboutToBeReset(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 17, nullptr, _t1);
}

// SIGNAL 18
void QAbstractItemModel::modelReset(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 18, nullptr, _t1);
}

// SIGNAL 19
void QAbstractItemModel::rowsAboutToBeMoved(const QModelIndex & _t1, int _t2, int _t3, const QModelIndex & _t4, int _t5, QPrivateSignal _t6)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 19, nullptr, _t1, _t2, _t3, _t4, _t5, _t6);
}

// SIGNAL 20
void QAbstractItemModel::rowsMoved(const QModelIndex & _t1, int _t2, int _t3, const QModelIndex & _t4, int _t5, QPrivateSignal _t6)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 20, nullptr, _t1, _t2, _t3, _t4, _t5, _t6);
}

// SIGNAL 21
void QAbstractItemModel::columnsAboutToBeMoved(const QModelIndex & _t1, int _t2, int _t3, const QModelIndex & _t4, int _t5, QPrivateSignal _t6)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 21, nullptr, _t1, _t2, _t3, _t4, _t5, _t6);
}

// SIGNAL 22
void QAbstractItemModel::columnsMoved(const QModelIndex & _t1, int _t2, int _t3, const QModelIndex & _t4, int _t5, QPrivateSignal _t6)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 22, nullptr, _t1, _t2, _t3, _t4, _t5, _t6);
}
namespace {
struct qt_meta_tag_ZN19QAbstractTableModelE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractTableModel::qt_create_metaobjectdata<qt_meta_tag_ZN19QAbstractTableModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractTableModel"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractTableModel, qt_meta_tag_ZN19QAbstractTableModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractTableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractTableModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractTableModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QAbstractTableModelE_t>.metaTypes,
    nullptr
} };

void QAbstractTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractTableModel *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QAbstractTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractTableModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int QAbstractTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN18QAbstractListModelE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractListModel::qt_create_metaobjectdata<qt_meta_tag_ZN18QAbstractListModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractListModel"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractListModel, qt_meta_tag_ZN18QAbstractListModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractListModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractListModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QAbstractListModelE_t>.metaTypes,
    nullptr
} };

void QAbstractListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractListModel *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QAbstractListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QAbstractListModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int QAbstractListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
