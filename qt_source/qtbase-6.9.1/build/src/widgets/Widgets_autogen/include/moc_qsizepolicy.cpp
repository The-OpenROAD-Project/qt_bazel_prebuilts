/****************************************************************************
** Meta object code from reading C++ file 'qsizepolicy.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/kernel/qsizepolicy.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsizepolicy.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QSizePolicyE_t {};
} // unnamed namespace

template <> constexpr inline auto QSizePolicy::qt_create_metaobjectdata<qt_meta_tag_ZN11QSizePolicyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSizePolicy",
        "Policy",
        "Fixed",
        "Minimum",
        "Maximum",
        "Preferred",
        "MinimumExpanding",
        "Expanding",
        "Ignored",
        "ControlTypes",
        "ControlType",
        "DefaultType",
        "ButtonBox",
        "CheckBox",
        "ComboBox",
        "Frame",
        "GroupBox",
        "Label",
        "Line",
        "LineEdit",
        "PushButton",
        "RadioButton",
        "Slider",
        "SpinBox",
        "TabWidget",
        "ToolButton"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Policy'
        QtMocHelpers::EnumData<Policy>(1, 1, QMC::EnumFlags{}).add({
            {    2, Policy::Fixed },
            {    3, Policy::Minimum },
            {    4, Policy::Maximum },
            {    5, Policy::Preferred },
            {    6, Policy::MinimumExpanding },
            {    7, Policy::Expanding },
            {    8, Policy::Ignored },
        }),
        // enum 'ControlTypes'
        QtMocHelpers::EnumData<ControlTypes>(9, 10, QMC::EnumFlags{}).add({
            {   11, ControlType::DefaultType },
            {   12, ControlType::ButtonBox },
            {   13, ControlType::CheckBox },
            {   14, ControlType::ComboBox },
            {   15, ControlType::Frame },
            {   16, ControlType::GroupBox },
            {   17, ControlType::Label },
            {   18, ControlType::Line },
            {   19, ControlType::LineEdit },
            {   20, ControlType::PushButton },
            {   21, ControlType::RadioButton },
            {   22, ControlType::Slider },
            {   23, ControlType::SpinBox },
            {   24, ControlType::TabWidget },
            {   25, ControlType::ToolButton },
        }),
    };
    return QtMocHelpers::metaObjectData<QSizePolicy, qt_meta_tag_ZN11QSizePolicyE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSizePolicy::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QSizePolicyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QSizePolicyE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QSizePolicyE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
