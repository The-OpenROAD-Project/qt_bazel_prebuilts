/****************************************************************************
** Meta object code from reading C++ file 'qtablewidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qtablewidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtablewidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QTableWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QTableWidget::qt_create_metaobjectdata<qt_meta_tag_ZN12QTableWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTableWidget",
        "itemPressed",
        "",
        "QTableWidgetItem*",
        "item",
        "itemClicked",
        "itemDoubleClicked",
        "itemActivated",
        "itemEntered",
        "itemChanged",
        "currentItemChanged",
        "current",
        "previous",
        "itemSelectionChanged",
        "cellPressed",
        "row",
        "column",
        "cellClicked",
        "cellDoubleClicked",
        "cellActivated",
        "cellEntered",
        "cellChanged",
        "currentCellChanged",
        "currentRow",
        "currentColumn",
        "previousRow",
        "previousColumn",
        "scrollToItem",
        "const QTableWidgetItem*",
        "QAbstractItemView::ScrollHint",
        "hint",
        "insertRow",
        "insertColumn",
        "removeRow",
        "removeColumn",
        "clear",
        "clearContents",
        "rowCount",
        "columnCount"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'itemPressed'
        QtMocHelpers::SignalData<void(QTableWidgetItem *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemClicked'
        QtMocHelpers::SignalData<void(QTableWidgetItem *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemDoubleClicked'
        QtMocHelpers::SignalData<void(QTableWidgetItem *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemActivated'
        QtMocHelpers::SignalData<void(QTableWidgetItem *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemEntered'
        QtMocHelpers::SignalData<void(QTableWidgetItem *)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemChanged'
        QtMocHelpers::SignalData<void(QTableWidgetItem *)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'currentItemChanged'
        QtMocHelpers::SignalData<void(QTableWidgetItem *, QTableWidgetItem *)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 11 }, { 0x80000000 | 3, 12 },
        }}),
        // Signal 'itemSelectionChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'cellPressed'
        QtMocHelpers::SignalData<void(int, int)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Signal 'cellClicked'
        QtMocHelpers::SignalData<void(int, int)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Signal 'cellDoubleClicked'
        QtMocHelpers::SignalData<void(int, int)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Signal 'cellActivated'
        QtMocHelpers::SignalData<void(int, int)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Signal 'cellEntered'
        QtMocHelpers::SignalData<void(int, int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Signal 'cellChanged'
        QtMocHelpers::SignalData<void(int, int)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 }, { QMetaType::Int, 16 },
        }}),
        // Signal 'currentCellChanged'
        QtMocHelpers::SignalData<void(int, int, int, int)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 23 }, { QMetaType::Int, 24 }, { QMetaType::Int, 25 }, { QMetaType::Int, 26 },
        }}),
        // Slot 'scrollToItem'
        QtMocHelpers::SlotData<void(const QTableWidgetItem *, QAbstractItemView::ScrollHint)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 4 }, { 0x80000000 | 29, 30 },
        }}),
        // Slot 'scrollToItem'
        QtMocHelpers::SlotData<void(const QTableWidgetItem *)>(27, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 28, 4 },
        }}),
        // Slot 'insertRow'
        QtMocHelpers::SlotData<void(int)>(31, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 },
        }}),
        // Slot 'insertColumn'
        QtMocHelpers::SlotData<void(int)>(32, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'removeRow'
        QtMocHelpers::SlotData<void(int)>(33, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 15 },
        }}),
        // Slot 'removeColumn'
        QtMocHelpers::SlotData<void(int)>(34, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(35, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clearContents'
        QtMocHelpers::SlotData<void()>(36, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'rowCount'
        QtMocHelpers::PropertyData<int>(37, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'columnCount'
        QtMocHelpers::PropertyData<int>(38, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTableWidget, qt_meta_tag_ZN12QTableWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTableWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTableWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTableWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QTableWidgetE_t>.metaTypes,
    nullptr
} };

void QTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTableWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->itemPressed((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 1: _t->itemClicked((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 2: _t->itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 3: _t->itemActivated((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 4: _t->itemEntered((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 5: _t->itemChanged((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1]))); break;
        case 6: _t->currentItemChanged((*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTableWidgetItem*>>(_a[2]))); break;
        case 7: _t->itemSelectionChanged(); break;
        case 8: _t->cellPressed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 9: _t->cellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 10: _t->cellDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 11: _t->cellActivated((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 12: _t->cellEntered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->cellChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 14: _t->currentCellChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 15: _t->scrollToItem((*reinterpret_cast< std::add_pointer_t<const QTableWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractItemView::ScrollHint>>(_a[2]))); break;
        case 16: _t->scrollToItem((*reinterpret_cast< std::add_pointer_t<const QTableWidgetItem*>>(_a[1]))); break;
        case 17: _t->insertRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->insertColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->removeRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->removeColumn((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->clear(); break;
        case 22: _t->clearContents(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(QTableWidgetItem * )>(_a, &QTableWidget::itemPressed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(QTableWidgetItem * )>(_a, &QTableWidget::itemClicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(QTableWidgetItem * )>(_a, &QTableWidget::itemDoubleClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(QTableWidgetItem * )>(_a, &QTableWidget::itemActivated, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(QTableWidgetItem * )>(_a, &QTableWidget::itemEntered, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(QTableWidgetItem * )>(_a, &QTableWidget::itemChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(QTableWidgetItem * , QTableWidgetItem * )>(_a, &QTableWidget::currentItemChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)()>(_a, &QTableWidget::itemSelectionChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(int , int )>(_a, &QTableWidget::cellPressed, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(int , int )>(_a, &QTableWidget::cellClicked, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(int , int )>(_a, &QTableWidget::cellDoubleClicked, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(int , int )>(_a, &QTableWidget::cellActivated, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(int , int )>(_a, &QTableWidget::cellEntered, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(int , int )>(_a, &QTableWidget::cellChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTableWidget::*)(int , int , int , int )>(_a, &QTableWidget::currentCellChanged, 14))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->rowCount(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->columnCount(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRowCount(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setColumnCount(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QTableWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int QTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 23)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 23;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QTableWidget::itemPressed(QTableWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QTableWidget::itemClicked(QTableWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QTableWidget::itemDoubleClicked(QTableWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QTableWidget::itemActivated(QTableWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QTableWidget::itemEntered(QTableWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QTableWidget::itemChanged(QTableWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QTableWidget::currentItemChanged(QTableWidgetItem * _t1, QTableWidgetItem * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void QTableWidget::itemSelectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QTableWidget::cellPressed(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2);
}

// SIGNAL 9
void QTableWidget::cellClicked(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1, _t2);
}

// SIGNAL 10
void QTableWidget::cellDoubleClicked(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1, _t2);
}

// SIGNAL 11
void QTableWidget::cellActivated(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1, _t2);
}

// SIGNAL 12
void QTableWidget::cellEntered(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1, _t2);
}

// SIGNAL 13
void QTableWidget::cellChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1, _t2);
}

// SIGNAL 14
void QTableWidget::currentCellChanged(int _t1, int _t2, int _t3, int _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 14, nullptr, _t1, _t2, _t3, _t4);
}
QT_WARNING_POP
