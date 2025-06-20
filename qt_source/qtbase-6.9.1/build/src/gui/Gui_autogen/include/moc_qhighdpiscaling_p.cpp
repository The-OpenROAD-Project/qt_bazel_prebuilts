/****************************************************************************
** Meta object code from reading C++ file 'qhighdpiscaling_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qhighdpiscaling_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhighdpiscaling_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QHighDpiScalingE_t {};
} // unnamed namespace

template <> constexpr inline auto QHighDpiScaling::qt_create_metaobjectdata<qt_meta_tag_ZN15QHighDpiScalingE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QHighDpiScaling",
        "DpiAdjustmentPolicy",
        "Unset",
        "Enabled",
        "Disabled",
        "UpOnly"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'DpiAdjustmentPolicy'
        QtMocHelpers::EnumData<DpiAdjustmentPolicy>(1, 1, QMC::EnumIsScoped).add({
            {    2, DpiAdjustmentPolicy::Unset },
            {    3, DpiAdjustmentPolicy::Enabled },
            {    4, DpiAdjustmentPolicy::Disabled },
            {    5, DpiAdjustmentPolicy::UpOnly },
        }),
    };
    return QtMocHelpers::metaObjectData<QHighDpiScaling, qt_meta_tag_ZN15QHighDpiScalingE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QHighDpiScaling::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QHighDpiScalingE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QHighDpiScalingE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QHighDpiScalingE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
