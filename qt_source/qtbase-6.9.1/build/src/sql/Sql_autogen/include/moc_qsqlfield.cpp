/****************************************************************************
** Meta object code from reading C++ file 'qsqlfield.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/sql/kernel/qsqlfield.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsqlfield.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QSqlFieldE_t {};
} // unnamed namespace

template <> constexpr inline auto QSqlField::qt_create_metaobjectdata<qt_meta_tag_ZN9QSqlFieldE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSqlField",
        "value",
        "QVariant",
        "defaultValue",
        "name",
        "tableName",
        "metaType",
        "QMetaType",
        "requiredStatus",
        "RequiredStatus",
        "readOnly",
        "generated",
        "autoValue",
        "length",
        "precision"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'value'
        QtMocHelpers::PropertyData<QVariant>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'defaultValue'
        QtMocHelpers::PropertyData<QVariant>(3, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(4, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tableName'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'metaType'
        QtMocHelpers::PropertyData<QMetaType>(6, 0x80000000 | 7, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'requiredStatus'
        QtMocHelpers::PropertyData<RequiredStatus>(8, 0x80000000 | 9, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'readOnly'
        QtMocHelpers::PropertyData<bool>(10, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'generated'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoValue'
        QtMocHelpers::PropertyData<bool>(12, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'length'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'precision'
        QtMocHelpers::PropertyData<int>(14, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSqlField, qt_meta_tag_ZN9QSqlFieldE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSqlField::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSqlFieldE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSqlFieldE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QSqlFieldE_t>.metaTypes,
    nullptr
} };

void QSqlField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QSqlField *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QVariant*>(_v) = _t->value(); break;
        case 1: *reinterpret_cast<QVariant*>(_v) = _t->defaultValue(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->tableName(); break;
        case 4: *reinterpret_cast<QMetaType*>(_v) = _t->metaType(); break;
        case 5: *reinterpret_cast<RequiredStatus*>(_v) = _t->requiredStatus(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->isReadOnly(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->isGenerated(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->isAutoValue(); break;
        case 9: *reinterpret_cast<int*>(_v) = _t->length(); break;
        case 10: *reinterpret_cast<int*>(_v) = _t->precision(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setValue(*reinterpret_cast<QVariant*>(_v)); break;
        case 1: _t->setDefaultValue(*reinterpret_cast<QVariant*>(_v)); break;
        case 2: _t->setName(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setTableName(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setMetaType(*reinterpret_cast<QMetaType*>(_v)); break;
        case 5: _t->setRequiredStatus(*reinterpret_cast<RequiredStatus*>(_v)); break;
        case 6: _t->setReadOnly(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setGenerated(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setAutoValue(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setLength(*reinterpret_cast<int*>(_v)); break;
        case 10: _t->setPrecision(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}
QT_WARNING_POP
