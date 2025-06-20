/****************************************************************************
** Meta object code from reading C++ file 'qcborvalue.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/serialization/qcborvalue.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcborvalue.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QCborValueE_t {};
} // unnamed namespace

template <> constexpr inline auto QCborValue::qt_create_metaobjectdata<qt_meta_tag_ZN10QCborValueE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCborValue",
        "Type",
        "Integer",
        "ByteArray",
        "String",
        "Array",
        "Map",
        "Tag",
        "SimpleType",
        "False",
        "True",
        "Null",
        "Undefined",
        "Double",
        "DateTime",
        "Url",
        "RegularExpression",
        "Uuid",
        "Invalid"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Type'
        QtMocHelpers::EnumData<Type>(1, 1, QMC::EnumFlags{}).add({
            {    2, Type::Integer },
            {    3, Type::ByteArray },
            {    4, Type::String },
            {    5, Type::Array },
            {    6, Type::Map },
            {    7, Type::Tag },
            {    8, Type::SimpleType },
            {    9, Type::False },
            {   10, Type::True },
            {   11, Type::Null },
            {   12, Type::Undefined },
            {   13, Type::Double },
            {   14, Type::DateTime },
            {   15, Type::Url },
            {   16, Type::RegularExpression },
            {   17, Type::Uuid },
            {   18, Type::Invalid },
        }),
    };
    return QtMocHelpers::metaObjectData<QCborValue, qt_meta_tag_ZN10QCborValueE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCborValue::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QCborValueE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QCborValueE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QCborValueE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
