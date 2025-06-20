/****************************************************************************
** Meta object code from reading C++ file 'qabstractproxymodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/itemmodels/qabstractproxymodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractproxymodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QAbstractProxyModelE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractProxyModel::qt_create_metaobjectdata<qt_meta_tag_ZN19QAbstractProxyModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractProxyModel",
        "sourceModelChanged",
        "",
        "_q_sourceModelDestroyed",
        "_q_sourceModelRowsAboutToBeInserted",
        "QModelIndex",
        "_q_sourceModelRowsInserted",
        "_q_sourceModelRowsRemoved",
        "_q_sourceModelColumnsAboutToBeInserted",
        "_q_sourceModelColumnsInserted",
        "_q_sourceModelColumnsRemoved",
        "mapToSource",
        "proxyIndex",
        "mapFromSource",
        "sourceIndex",
        "mapSelectionToSource",
        "QItemSelection",
        "selection",
        "mapSelectionFromSource",
        "sourceModel",
        "QAbstractItemModel*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sourceModelChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_sourceModelDestroyed'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_sourceModelRowsAboutToBeInserted'
        QtMocHelpers::SlotData<void(QModelIndex, int, int)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 2 }, { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Slot '_q_sourceModelRowsInserted'
        QtMocHelpers::SlotData<void(QModelIndex, int, int)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 2 }, { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Slot '_q_sourceModelRowsRemoved'
        QtMocHelpers::SlotData<void(QModelIndex, int, int)>(7, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 2 }, { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Slot '_q_sourceModelColumnsAboutToBeInserted'
        QtMocHelpers::SlotData<void(QModelIndex, int, int)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 2 }, { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Slot '_q_sourceModelColumnsInserted'
        QtMocHelpers::SlotData<void(QModelIndex, int, int)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 2 }, { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Slot '_q_sourceModelColumnsRemoved'
        QtMocHelpers::SlotData<void(QModelIndex, int, int)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 5, 2 }, { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
        // Method 'mapToSource'
        QtMocHelpers::MethodData<QModelIndex(const QModelIndex &) const>(11, 2, QMC::AccessPublic, 0x80000000 | 5, {{
            { 0x80000000 | 5, 12 },
        }}),
        // Method 'mapFromSource'
        QtMocHelpers::MethodData<QModelIndex(const QModelIndex &) const>(13, 2, QMC::AccessPublic, 0x80000000 | 5, {{
            { 0x80000000 | 5, 14 },
        }}),
        // Method 'mapSelectionToSource'
        QtMocHelpers::MethodData<QItemSelection(const QItemSelection &) const>(15, 2, QMC::AccessPublic, 0x80000000 | 16, {{
            { 0x80000000 | 16, 17 },
        }}),
        // Method 'mapSelectionFromSource'
        QtMocHelpers::MethodData<QItemSelection(const QItemSelection &) const>(18, 2, QMC::AccessPublic, 0x80000000 | 16, {{
            { 0x80000000 | 16, 17 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'sourceModel'
        QtMocHelpers::PropertyData<QAbstractItemModel*>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractProxyModel, qt_meta_tag_ZN19QAbstractProxyModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractProxyModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractProxyModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractProxyModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QAbstractProxyModelE_t>.metaTypes,
    nullptr
} };

void QAbstractProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractProxyModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sourceModelChanged(QPrivateSignal()); break;
        case 1: _t->d_func()->_q_sourceModelDestroyed(); break;
        case 2: _t->d_func()->_q_sourceModelRowsAboutToBeInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->d_func()->_q_sourceModelRowsInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 4: _t->d_func()->_q_sourceModelRowsRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 5: _t->d_func()->_q_sourceModelColumnsAboutToBeInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 6: _t->d_func()->_q_sourceModelColumnsInserted((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->d_func()->_q_sourceModelColumnsRemoved((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: { QModelIndex _r = _t->mapToSource((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 9: { QModelIndex _r = _t->mapFromSource((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QModelIndex*>(_a[0]) = std::move(_r); }  break;
        case 10: { QItemSelection _r = _t->mapSelectionToSource((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QItemSelection*>(_a[0]) = std::move(_r); }  break;
        case 11: { QItemSelection _r = _t->mapSelectionFromSource((*reinterpret_cast< std::add_pointer_t<QItemSelection>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QItemSelection*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractProxyModel::*)(QPrivateSignal)>(_a, &QAbstractProxyModel::sourceModelChanged, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractItemModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QAbstractItemModel**>(_v) = _t->sourceModel(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSourceModel(*reinterpret_cast<QAbstractItemModel**>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableSourceModel(); break;
        default: break;
        }
    }
}

const QMetaObject *QAbstractProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractProxyModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int QAbstractProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QAbstractProxyModel::sourceModelChanged(QPrivateSignal _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
