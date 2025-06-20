/****************************************************************************
** Meta object code from reading C++ file 'qsqlquery.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/sql/kernel/qsqlquery.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsqlquery.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QSqlQueryE_t {};
} // unnamed namespace

template <> constexpr inline auto QSqlQuery::qt_create_metaobjectdata<qt_meta_tag_ZN9QSqlQueryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSqlQuery",
        "forwardOnly",
        "positionalBindingEnabled",
        "numericalPrecisionPolicy",
        "QSql::NumericalPrecisionPolicy"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'forwardOnly'
        QtMocHelpers::PropertyData<bool>(1, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'positionalBindingEnabled'
        QtMocHelpers::PropertyData<bool>(2, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'numericalPrecisionPolicy'
        QtMocHelpers::PropertyData<QSql::NumericalPrecisionPolicy>(3, 0x80000000 | 4, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSqlQuery, qt_meta_tag_ZN9QSqlQueryE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSqlQuery::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSqlQueryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSqlQueryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QSqlQueryE_t>.metaTypes,
    nullptr
} };

void QSqlQuery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QSqlQuery *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isForwardOnly(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isPositionalBindingEnabled(); break;
        case 2: *reinterpret_cast<QSql::NumericalPrecisionPolicy*>(_v) = _t->numericalPrecisionPolicy(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setForwardOnly(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setPositionalBindingEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setNumericalPrecisionPolicy(*reinterpret_cast<QSql::NumericalPrecisionPolicy*>(_v)); break;
        default: break;
        }
    }
}
QT_WARNING_POP
