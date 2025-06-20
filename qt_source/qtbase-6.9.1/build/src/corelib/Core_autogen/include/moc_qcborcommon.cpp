/****************************************************************************
** Meta object code from reading C++ file 'qcborcommon.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/serialization/qcborcommon.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcborcommon.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QCborErrorE_t {};
} // unnamed namespace

template <> constexpr inline auto QCborError::qt_create_metaobjectdata<qt_meta_tag_ZN10QCborErrorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCborError",
        "Code",
        "UnknownError",
        "AdvancePastEnd",
        "InputOutputError",
        "GarbageAtEnd",
        "EndOfFile",
        "UnexpectedBreak",
        "UnknownType",
        "IllegalType",
        "IllegalNumber",
        "IllegalSimpleType",
        "InvalidUtf8String",
        "DataTooLarge",
        "NestingTooDeep",
        "UnsupportedType",
        "NoError"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Code'
        QtMocHelpers::EnumData<Code>(1, 1, QMC::EnumFlags{}).add({
            {    2, Code::UnknownError },
            {    3, Code::AdvancePastEnd },
            {    4, Code::InputOutputError },
            {    5, Code::GarbageAtEnd },
            {    6, Code::EndOfFile },
            {    7, Code::UnexpectedBreak },
            {    8, Code::UnknownType },
            {    9, Code::IllegalType },
            {   10, Code::IllegalNumber },
            {   11, Code::IllegalSimpleType },
            {   12, Code::InvalidUtf8String },
            {   13, Code::DataTooLarge },
            {   14, Code::NestingTooDeep },
            {   15, Code::UnsupportedType },
            {   16, Code::NoError },
        }),
    };
    return QtMocHelpers::metaObjectData<QCborError, qt_meta_tag_ZN10QCborErrorE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCborError::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QCborErrorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QCborErrorE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QCborErrorE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
