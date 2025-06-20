/****************************************************************************
** Meta object code from reading C++ file 'qsqltablemodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/sql/models/qsqltablemodel.h"
#include <QtSql/qsqlrecord.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsqltablemodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14QSqlTableModelE_t {};
} // unnamed namespace

template <> constexpr inline auto QSqlTableModel::qt_create_metaobjectdata<qt_meta_tag_ZN14QSqlTableModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSqlTableModel",
        "primeInsert",
        "",
        "row",
        "QSqlRecord&",
        "record",
        "beforeInsert",
        "beforeUpdate",
        "beforeDelete",
        "select",
        "selectRow",
        "submit",
        "revert",
        "submitAll",
        "revertAll"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'primeInsert'
        QtMocHelpers::SignalData<void(int, QSqlRecord &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { 0x80000000 | 4, 5 },
        }}),
        // Signal 'beforeInsert'
        QtMocHelpers::SignalData<void(QSqlRecord &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'beforeUpdate'
        QtMocHelpers::SignalData<void(int, QSqlRecord &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 }, { 0x80000000 | 4, 5 },
        }}),
        // Signal 'beforeDelete'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'select'
        QtMocHelpers::SlotData<bool()>(9, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'selectRow'
        QtMocHelpers::SlotData<bool(int)>(10, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'submit'
        QtMocHelpers::SlotData<bool()>(11, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'revert'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'submitAll'
        QtMocHelpers::SlotData<bool()>(13, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'revertAll'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSqlTableModel, qt_meta_tag_ZN14QSqlTableModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSqlTableModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlQueryModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QSqlTableModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QSqlTableModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QSqlTableModelE_t>.metaTypes,
    nullptr
} };

void QSqlTableModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSqlTableModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->primeInsert((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSqlRecord&>>(_a[2]))); break;
        case 1: _t->beforeInsert((*reinterpret_cast< std::add_pointer_t<QSqlRecord&>>(_a[1]))); break;
        case 2: _t->beforeUpdate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSqlRecord&>>(_a[2]))); break;
        case 3: _t->beforeDelete((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: { bool _r = _t->select();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->selectRow((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->submit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->revert(); break;
        case 8: { bool _r = _t->submitAll();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->revertAll(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QSqlTableModel::*)(int , QSqlRecord & )>(_a, &QSqlTableModel::primeInsert, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSqlTableModel::*)(QSqlRecord & )>(_a, &QSqlTableModel::beforeInsert, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSqlTableModel::*)(int , QSqlRecord & )>(_a, &QSqlTableModel::beforeUpdate, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSqlTableModel::*)(int )>(_a, &QSqlTableModel::beforeDelete, 3))
            return;
    }
}

const QMetaObject *QSqlTableModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSqlTableModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QSqlTableModelE_t>.strings))
        return static_cast<void*>(this);
    return QSqlQueryModel::qt_metacast(_clname);
}

int QSqlTableModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QSqlTableModel::primeInsert(int _t1, QSqlRecord & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QSqlTableModel::beforeInsert(QSqlRecord & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QSqlTableModel::beforeUpdate(int _t1, QSqlRecord & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QSqlTableModel::beforeDelete(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
