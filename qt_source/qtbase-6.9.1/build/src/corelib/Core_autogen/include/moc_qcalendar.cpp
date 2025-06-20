/****************************************************************************
** Meta object code from reading C++ file 'qcalendar.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/time/qcalendar.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcalendar.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QCalendarE_t {};
} // unnamed namespace

template <> constexpr inline auto QCalendar::qt_create_metaobjectdata<qt_meta_tag_ZN9QCalendarE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCalendar",
        "System",
        "Gregorian",
        "Julian",
        "Milankovic",
        "Jalali",
        "IslamicCivil",
        "Last",
        "User"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'System'
        QtMocHelpers::EnumData<System>(1, 1, QMC::EnumIsScoped).add({
            {    2, System::Gregorian },
            {    3, System::Julian },
            {    4, System::Milankovic },
            {    5, System::Jalali },
            {    6, System::IslamicCivil },
            {    7, System::Last },
            {    8, System::User },
        }),
    };
    return QtMocHelpers::metaObjectData<QCalendar, qt_meta_tag_ZN9QCalendarE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCalendar::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QCalendarE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QCalendarE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QCalendarE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
