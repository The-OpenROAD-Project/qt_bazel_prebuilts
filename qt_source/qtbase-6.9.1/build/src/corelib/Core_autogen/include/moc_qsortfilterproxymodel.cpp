/****************************************************************************
** Meta object code from reading C++ file 'qsortfilterproxymodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/itemmodels/qsortfilterproxymodel.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsortfilterproxymodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21QSortFilterProxyModelE_t {};
} // unnamed namespace

template <> constexpr inline auto QSortFilterProxyModel::qt_create_metaobjectdata<qt_meta_tag_ZN21QSortFilterProxyModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSortFilterProxyModel",
        "dynamicSortFilterChanged",
        "",
        "dynamicSortFilter",
        "filterCaseSensitivityChanged",
        "Qt::CaseSensitivity",
        "filterCaseSensitivity",
        "sortCaseSensitivityChanged",
        "sortCaseSensitivity",
        "sortLocaleAwareChanged",
        "sortLocaleAware",
        "sortRoleChanged",
        "sortRole",
        "filterRoleChanged",
        "filterRole",
        "recursiveFilteringEnabledChanged",
        "recursiveFilteringEnabled",
        "autoAcceptChildRowsChanged",
        "autoAcceptChildRows",
        "setFilterRegularExpression",
        "pattern",
        "regularExpression",
        "setFilterWildcard",
        "setFilterFixedString",
        "invalidate",
        "filterRegularExpression",
        "filterKeyColumn",
        "isSortLocaleAware"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dynamicSortFilterChanged'
        QtMocHelpers::SignalData<void(bool)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 },
        }}),
        // Signal 'filterCaseSensitivityChanged'
        QtMocHelpers::SignalData<void(Qt::CaseSensitivity)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Signal 'sortCaseSensitivityChanged'
        QtMocHelpers::SignalData<void(Qt::CaseSensitivity)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 8 },
        }}),
        // Signal 'sortLocaleAwareChanged'
        QtMocHelpers::SignalData<void(bool)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 10 },
        }}),
        // Signal 'sortRoleChanged'
        QtMocHelpers::SignalData<void(int)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 12 },
        }}),
        // Signal 'filterRoleChanged'
        QtMocHelpers::SignalData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 14 },
        }}),
        // Signal 'recursiveFilteringEnabledChanged'
        QtMocHelpers::SignalData<void(bool)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 16 },
        }}),
        // Signal 'autoAcceptChildRowsChanged'
        QtMocHelpers::SignalData<void(bool)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 },
        }}),
        // Slot 'setFilterRegularExpression'
        QtMocHelpers::SlotData<void(const QString &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 20 },
        }}),
        // Slot 'setFilterRegularExpression'
        QtMocHelpers::SlotData<void(const QRegularExpression &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRegularExpression, 21 },
        }}),
        // Slot 'setFilterWildcard'
        QtMocHelpers::SlotData<void(const QString &)>(22, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 20 },
        }}),
        // Slot 'setFilterFixedString'
        QtMocHelpers::SlotData<void(const QString &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 20 },
        }}),
        // Slot 'invalidate'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'filterRegularExpression'
        QtMocHelpers::PropertyData<QRegularExpression>(25, QMetaType::QRegularExpression, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'filterKeyColumn'
        QtMocHelpers::PropertyData<int>(26, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'dynamicSortFilter'
        QtMocHelpers::PropertyData<bool>(3, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'filterCaseSensitivity'
        QtMocHelpers::PropertyData<Qt::CaseSensitivity>(6, 0x80000000 | 5, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 1),
        // property 'sortCaseSensitivity'
        QtMocHelpers::PropertyData<Qt::CaseSensitivity>(8, 0x80000000 | 5, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable, 2),
        // property 'isSortLocaleAware'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Bindable, 3),
        // property 'sortRole'
        QtMocHelpers::PropertyData<int>(12, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable, 4),
        // property 'filterRole'
        QtMocHelpers::PropertyData<int>(14, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable, 5),
        // property 'recursiveFilteringEnabled'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable, 6),
        // property 'autoAcceptChildRows'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable, 7),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSortFilterProxyModel, qt_meta_tag_ZN21QSortFilterProxyModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSortFilterProxyModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractProxyModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QSortFilterProxyModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QSortFilterProxyModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QSortFilterProxyModelE_t>.metaTypes,
    nullptr
} };

void QSortFilterProxyModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSortFilterProxyModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dynamicSortFilterChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->filterCaseSensitivityChanged((*reinterpret_cast< std::add_pointer_t<Qt::CaseSensitivity>>(_a[1]))); break;
        case 2: _t->sortCaseSensitivityChanged((*reinterpret_cast< std::add_pointer_t<Qt::CaseSensitivity>>(_a[1]))); break;
        case 3: _t->sortLocaleAwareChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->sortRoleChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->filterRoleChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->recursiveFilteringEnabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 7: _t->autoAcceptChildRowsChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->setFilterRegularExpression((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->setFilterRegularExpression((*reinterpret_cast< std::add_pointer_t<QRegularExpression>>(_a[1]))); break;
        case 10: _t->setFilterWildcard((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: _t->setFilterFixedString((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 12: _t->invalidate(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QSortFilterProxyModel::*)(bool )>(_a, &QSortFilterProxyModel::dynamicSortFilterChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSortFilterProxyModel::*)(Qt::CaseSensitivity )>(_a, &QSortFilterProxyModel::filterCaseSensitivityChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSortFilterProxyModel::*)(Qt::CaseSensitivity )>(_a, &QSortFilterProxyModel::sortCaseSensitivityChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSortFilterProxyModel::*)(bool )>(_a, &QSortFilterProxyModel::sortLocaleAwareChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSortFilterProxyModel::*)(int )>(_a, &QSortFilterProxyModel::sortRoleChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSortFilterProxyModel::*)(int )>(_a, &QSortFilterProxyModel::filterRoleChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSortFilterProxyModel::*)(bool )>(_a, &QSortFilterProxyModel::recursiveFilteringEnabledChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSortFilterProxyModel::*)(bool )>(_a, &QSortFilterProxyModel::autoAcceptChildRowsChanged, 7))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QRegularExpression*>(_v) = _t->filterRegularExpression(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->filterKeyColumn(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->dynamicSortFilter(); break;
        case 3: *reinterpret_cast<Qt::CaseSensitivity*>(_v) = _t->filterCaseSensitivity(); break;
        case 4: *reinterpret_cast<Qt::CaseSensitivity*>(_v) = _t->sortCaseSensitivity(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isSortLocaleAware(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->sortRole(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->filterRole(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->isRecursiveFilteringEnabled(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->autoAcceptChildRows(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFilterRegularExpression(*reinterpret_cast<QRegularExpression*>(_v)); break;
        case 1: _t->setFilterKeyColumn(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setDynamicSortFilter(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setFilterCaseSensitivity(*reinterpret_cast<Qt::CaseSensitivity*>(_v)); break;
        case 4: _t->setSortCaseSensitivity(*reinterpret_cast<Qt::CaseSensitivity*>(_v)); break;
        case 5: _t->setSortLocaleAware(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setSortRole(*reinterpret_cast<int*>(_v)); break;
        case 7: _t->setFilterRole(*reinterpret_cast<int*>(_v)); break;
        case 8: _t->setRecursiveFilteringEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setAutoAcceptChildRows(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableFilterRegularExpression(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableFilterKeyColumn(); break;
        case 2: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableDynamicSortFilter(); break;
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableFilterCaseSensitivity(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableSortCaseSensitivity(); break;
        case 5: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableIsSortLocaleAware(); break;
        case 6: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableSortRole(); break;
        case 7: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableFilterRole(); break;
        case 8: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableRecursiveFilteringEnabled(); break;
        case 9: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableAutoAcceptChildRows(); break;
        default: break;
        }
    }
}

const QMetaObject *QSortFilterProxyModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSortFilterProxyModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QSortFilterProxyModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractProxyModel::qt_metacast(_clname);
}

int QSortFilterProxyModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractProxyModel::qt_metacall(_c, _id, _a);
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
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QSortFilterProxyModel::dynamicSortFilterChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QSortFilterProxyModel::filterCaseSensitivityChanged(Qt::CaseSensitivity _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QSortFilterProxyModel::sortCaseSensitivityChanged(Qt::CaseSensitivity _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QSortFilterProxyModel::sortLocaleAwareChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QSortFilterProxyModel::sortRoleChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QSortFilterProxyModel::filterRoleChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QSortFilterProxyModel::recursiveFilteringEnabledChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QSortFilterProxyModel::autoAcceptChildRowsChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}
QT_WARNING_POP
