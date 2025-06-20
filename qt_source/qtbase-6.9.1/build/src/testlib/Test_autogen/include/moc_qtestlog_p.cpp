/****************************************************************************
** Meta object code from reading C++ file 'qtestlog_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/testlib/qtestlog_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtestlog_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QTestLogE_t {};
} // unnamed namespace

template <> constexpr inline auto QTestLog::qt_create_metaobjectdata<qt_meta_tag_ZN8QTestLogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTestLog",
        "LogMode",
        "Plain",
        "XML",
        "LightXML",
        "JUnitXML",
        "CSV",
        "TeamCity",
        "TAP"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'LogMode'
        QtMocHelpers::EnumData<LogMode>(1, 1, QMC::EnumFlags{}).add({
            {    2, LogMode::Plain },
            {    3, LogMode::XML },
            {    4, LogMode::LightXML },
            {    5, LogMode::JUnitXML },
            {    6, LogMode::CSV },
            {    7, LogMode::TeamCity },
            {    8, LogMode::TAP },
        }),
    };
    return QtMocHelpers::metaObjectData<QTestLog, qt_meta_tag_ZN8QTestLogE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTestLog::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QTestLogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QTestLogE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QTestLogE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
