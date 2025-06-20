/****************************************************************************
** Meta object code from reading C++ file 'qlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qlistwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlistwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QListWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QListWidget::qt_create_metaobjectdata<qt_meta_tag_ZN11QListWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QListWidget",
        "itemPressed",
        "",
        "QListWidgetItem*",
        "item",
        "itemClicked",
        "itemDoubleClicked",
        "itemActivated",
        "itemEntered",
        "itemChanged",
        "currentItemChanged",
        "current",
        "previous",
        "currentTextChanged",
        "currentText",
        "currentRowChanged",
        "currentRow",
        "itemSelectionChanged",
        "scrollToItem",
        "const QListWidgetItem*",
        "QAbstractItemView::ScrollHint",
        "hint",
        "clear",
        "count",
        "sortingEnabled"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'itemPressed'
        QtMocHelpers::SignalData<void(QListWidgetItem *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemClicked'
        QtMocHelpers::SignalData<void(QListWidgetItem *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemDoubleClicked'
        QtMocHelpers::SignalData<void(QListWidgetItem *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemActivated'
        QtMocHelpers::SignalData<void(QListWidgetItem *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemEntered'
        QtMocHelpers::SignalData<void(QListWidgetItem *)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'itemChanged'
        QtMocHelpers::SignalData<void(QListWidgetItem *)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'currentItemChanged'
        QtMocHelpers::SignalData<void(QListWidgetItem *, QListWidgetItem *)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 11 }, { 0x80000000 | 3, 12 },
        }}),
        // Signal 'currentTextChanged'
        QtMocHelpers::SignalData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Signal 'currentRowChanged'
        QtMocHelpers::SignalData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Signal 'itemSelectionChanged'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'scrollToItem'
        QtMocHelpers::SlotData<void(const QListWidgetItem *, QAbstractItemView::ScrollHint)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 19, 4 }, { 0x80000000 | 20, 21 },
        }}),
        // Slot 'scrollToItem'
        QtMocHelpers::SlotData<void(const QListWidgetItem *)>(18, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { 0x80000000 | 19, 4 },
        }}),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'count'
        QtMocHelpers::PropertyData<int>(23, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'currentRow'
        QtMocHelpers::PropertyData<int>(16, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 8),
        // property 'sortingEnabled'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QListWidget, qt_meta_tag_ZN11QListWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QListView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QListWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QListWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QListWidgetE_t>.metaTypes,
    nullptr
} };

void QListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QListWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->itemPressed((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 1: _t->itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 2: _t->itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 3: _t->itemActivated((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 4: _t->itemEntered((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 5: _t->itemChanged((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 6: _t->currentItemChanged((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[2]))); break;
        case 7: _t->currentTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->itemSelectionChanged(); break;
        case 10: _t->scrollToItem((*reinterpret_cast< std::add_pointer_t<const QListWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QAbstractItemView::ScrollHint>>(_a[2]))); break;
        case 11: _t->scrollToItem((*reinterpret_cast< std::add_pointer_t<const QListWidgetItem*>>(_a[1]))); break;
        case 12: _t->clear(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(QListWidgetItem * )>(_a, &QListWidget::itemPressed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(QListWidgetItem * )>(_a, &QListWidget::itemClicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(QListWidgetItem * )>(_a, &QListWidget::itemDoubleClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(QListWidgetItem * )>(_a, &QListWidget::itemActivated, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(QListWidgetItem * )>(_a, &QListWidget::itemEntered, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(QListWidgetItem * )>(_a, &QListWidget::itemChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(QListWidgetItem * , QListWidgetItem * )>(_a, &QListWidget::currentItemChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(const QString & )>(_a, &QListWidget::currentTextChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)(int )>(_a, &QListWidget::currentRowChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QListWidget::*)()>(_a, &QListWidget::itemSelectionChanged, 9))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->count(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->currentRow(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isSortingEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setCurrentRow(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setSortingEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QListWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QListView::qt_metacast(_clname);
}

int QListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QListWidget::itemPressed(QListWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QListWidget::itemClicked(QListWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QListWidget::itemDoubleClicked(QListWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QListWidget::itemActivated(QListWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QListWidget::itemEntered(QListWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QListWidget::itemChanged(QListWidgetItem * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QListWidget::currentItemChanged(QListWidgetItem * _t1, QListWidgetItem * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void QListWidget::currentTextChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QListWidget::currentRowChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void QListWidget::itemSelectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
