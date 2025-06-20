/****************************************************************************
** Meta object code from reading C++ file 'qcborstreamreader.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/serialization/qcborstreamreader.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcborstreamreader.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QCborStreamReaderE_t {};
} // unnamed namespace

template <> constexpr inline auto QCborStreamReader::qt_create_metaobjectdata<qt_meta_tag_ZN17QCborStreamReaderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCborStreamReader",
        "Type",
        "UnsignedInteger",
        "NegativeInteger",
        "ByteString",
        "ByteArray",
        "TextString",
        "String",
        "Array",
        "Map",
        "Tag",
        "SimpleType",
        "HalfFloat",
        "Float16",
        "Float",
        "Double",
        "Invalid",
        "StringResultCode",
        "EndOfString",
        "Ok",
        "Error"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Type'
        QtMocHelpers::EnumData<Type>(1, 1, QMC::EnumFlags{}).add({
            {    2, Type::UnsignedInteger },
            {    3, Type::NegativeInteger },
            {    4, Type::ByteString },
            {    5, Type::ByteArray },
            {    6, Type::TextString },
            {    7, Type::String },
            {    8, Type::Array },
            {    9, Type::Map },
            {   10, Type::Tag },
            {   11, Type::SimpleType },
            {   12, Type::HalfFloat },
            {   13, Type::Float16 },
            {   14, Type::Float },
            {   15, Type::Double },
            {   16, Type::Invalid },
        }),
        // enum 'StringResultCode'
        QtMocHelpers::EnumData<StringResultCode>(17, 17, QMC::EnumFlags{}).add({
            {   18, StringResultCode::EndOfString },
            {   19, StringResultCode::Ok },
            {   20, StringResultCode::Error },
        }),
    };
    return QtMocHelpers::metaObjectData<QCborStreamReader, qt_meta_tag_ZN17QCborStreamReaderE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCborStreamReader::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QCborStreamReaderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QCborStreamReaderE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QCborStreamReaderE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
