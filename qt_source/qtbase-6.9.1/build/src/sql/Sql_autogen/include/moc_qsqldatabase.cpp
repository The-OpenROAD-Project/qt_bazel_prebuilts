/****************************************************************************
** Meta object code from reading C++ file 'qsqldatabase.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/sql/kernel/qsqldatabase.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsqldatabase.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QSqlDatabaseE_t {};
} // unnamed namespace

template <> constexpr inline auto QSqlDatabase::qt_create_metaobjectdata<qt_meta_tag_ZN12QSqlDatabaseE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSqlDatabase",
        "numericalPrecisionPolicy",
        "QSql::NumericalPrecisionPolicy"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'numericalPrecisionPolicy'
        QtMocHelpers::PropertyData<QSql::NumericalPrecisionPolicy>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSqlDatabase, qt_meta_tag_ZN12QSqlDatabaseE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSqlDatabase::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QSqlDatabaseE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QSqlDatabaseE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QSqlDatabaseE_t>.metaTypes,
    nullptr
} };

void QSqlDatabase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QSqlDatabase *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QSql::NumericalPrecisionPolicy*>(_v) = _t->numericalPrecisionPolicy(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNumericalPrecisionPolicy(*reinterpret_cast<QSql::NumericalPrecisionPolicy*>(_v)); break;
        default: break;
        }
    }
}
QT_WARNING_POP
