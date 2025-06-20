/****************************************************************************
** Meta object code from reading C++ file 'qtreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qtreewidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtreewidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QTreeWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QTreeWidget::qt_create_metaobjectdata<qt_meta_tag_ZN11QTreeWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTreeWidget",
        "itemPressed",
        "",
        "QTreeWidgetItem*",
        "item",
        "column",
        "itemClicked",
        "itemDoubleClicked",
        "itemActivated",
        "itemEntered",
        "itemChanged",
        "itemExpanded",
        "itemCollapsed",
        "currentItemChanged",
        "current",
        "previous",
        "itemSelectionChanged",
        "scrollToItem",
        "const QTreeWidgetItem*",
        "QAbstractItemView::ScrollHint",
        "hint",
        "expandItem",
        "collapseItem",
        "clear",
        "columnCount",
        "topLevelItemCount"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'itemPressed'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *, int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'itemClicked'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *, int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'itemDoubleClicked'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *, int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'itemActivated'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *, int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'itemEntered'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *, int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'itemChanged'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *, int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { QMetaType::Int, 5 },
        }}),
        // Signal 'itemExpanded'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemCollapsed'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'currentItemChanged'
        QtMocHelpers::SignalData<void(QTreeWidgetItem *, QTreeWidgetItem *)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 14 }, { 0x80000000 | 3, 15 },
        }}),
        // Signal 'itemSelectionChanged'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'scrollToItem'
        QtMocHelpers::SlotData<void(const QTreeWidgetItem *, QAbstractItemView::ScrollHint)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 4 }, { 0x80000000 | 19, 20 },
        }}),
        // Slot 'scrollToItem'
        QtMocHelpers::SlotData<void(const QTreeWidgetItem *)>(17, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 18, 4 },
        }}),
        // Slot 'expandItem'
        QtMocHelpers::SlotData<void(const QTreeWidgetItem *)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 4 },
        }}),
        // Slot 'collapseItem'
        QtMocHelpers::SlotData<void(const QTreeWidgetItem *)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 4 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'columnCount'
        QtMocHelpers::PropertyData<int>(24, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'topLevelItemCount'
        QtMocHelpers::PropertyData<int>(25, QMetaType::Int, QMC::DefaultPropertyFlags),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTreeWidget, qt_meta_tag_ZN11QTreeWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTreeWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QTreeWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QTreeWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QTreeWidgetE_t>.metaTypes,
    nullptr
} };

void QTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTreeWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->itemPressed((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 1: _t->itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->itemActivated((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->itemEntered((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->itemChanged((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->itemExpanded((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1]))); break;
        case 7: _t->itemCollapsed((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1]))); break;
        case 8: _t->currentItemChanged((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[2]))); break;
        case 9: _t->itemSelectionChanged(); break;
        case 10: _t->scrollToItem((*reinterpret_cast< std::add_pointer_t<const QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractItemView::ScrollHint>>(_a[2]))); break;
        case 11: _t->scrollToItem((*reinterpret_cast< std::add_pointer_t<const QTreeWidgetItem*>>(_a[1]))); break;
        case 12: _t->expandItem((*reinterpret_cast< std::add_pointer_t<const QTreeWidgetItem*>>(_a[1]))); break;
        case 13: _t->collapseItem((*reinterpret_cast< std::add_pointer_t<const QTreeWidgetItem*>>(_a[1]))); break;
        case 14: _t->clear(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * , int )>(_a, &QTreeWidget::itemPressed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * , int )>(_a, &QTreeWidget::itemClicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * , int )>(_a, &QTreeWidget::itemDoubleClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * , int )>(_a, &QTreeWidget::itemActivated, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * , int )>(_a, &QTreeWidget::itemEntered, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * , int )>(_a, &QTreeWidget::itemChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * )>(_a, &QTreeWidget::itemExpanded, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * )>(_a, &QTreeWidget::itemCollapsed, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)(QTreeWidgetItem * , QTreeWidgetItem * )>(_a, &QTreeWidget::currentItemChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTreeWidget::*)()>(_a, &QTreeWidget::itemSelectionChanged, 9))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->columnCount(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->topLevelItemCount(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setColumnCount(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QTreeWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QTreeView::qt_metacast(_clname);
}

int QTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
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
void QTreeWidget::itemPressed(QTreeWidgetItem * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QTreeWidget::itemClicked(QTreeWidgetItem * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QTreeWidget::itemDoubleClicked(QTreeWidgetItem * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QTreeWidget::itemActivated(QTreeWidgetItem * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void QTreeWidget::itemEntered(QTreeWidgetItem * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void QTreeWidget::itemChanged(QTreeWidgetItem * _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void QTreeWidget::itemExpanded(QTreeWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QTreeWidget::itemCollapsed(QTreeWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QTreeWidget::currentItemChanged(QTreeWidgetItem * _t1, QTreeWidgetItem * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1, _t2);
}

// SIGNAL 9
void QTreeWidget::itemSelectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
