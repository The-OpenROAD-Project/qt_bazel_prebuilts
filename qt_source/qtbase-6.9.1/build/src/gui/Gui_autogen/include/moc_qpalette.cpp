/****************************************************************************
** Meta object code from reading C++ file 'qpalette.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qpalette.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpalette.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QPaletteE_t {};
} // unnamed namespace

template <> constexpr inline auto QPalette::qt_create_metaobjectdata<qt_meta_tag_ZN8QPaletteE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPalette",
        "ColorGroup",
        "Active",
        "Disabled",
        "Inactive",
        "NColorGroups",
        "Current",
        "All",
        "Normal",
        "ColorRole",
        "WindowText",
        "Button",
        "Light",
        "Midlight",
        "Dark",
        "Mid",
        "Text",
        "BrightText",
        "ButtonText",
        "Base",
        "Window",
        "Shadow",
        "Highlight",
        "HighlightedText",
        "Link",
        "LinkVisited",
        "AlternateBase",
        "NoRole",
        "ToolTipBase",
        "ToolTipText",
        "PlaceholderText",
        "Accent",
        "NColorRoles"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ColorGroup'
        QtMocHelpers::EnumData<ColorGroup>(1, 1, QMC::EnumFlags{}).add({
            {    2, ColorGroup::Active },
            {    3, ColorGroup::Disabled },
            {    4, ColorGroup::Inactive },
            {    5, ColorGroup::NColorGroups },
            {    6, ColorGroup::Current },
            {    7, ColorGroup::All },
            {    8, ColorGroup::Normal },
        }),
        // enum 'ColorRole'
        QtMocHelpers::EnumData<ColorRole>(9, 9, QMC::EnumFlags{}).add({
            {   10, ColorRole::WindowText },
            {   11, ColorRole::Button },
            {   12, ColorRole::Light },
            {   13, ColorRole::Midlight },
            {   14, ColorRole::Dark },
            {   15, ColorRole::Mid },
            {   16, ColorRole::Text },
            {   17, ColorRole::BrightText },
            {   18, ColorRole::ButtonText },
            {   19, ColorRole::Base },
            {   20, ColorRole::Window },
            {   21, ColorRole::Shadow },
            {   22, ColorRole::Highlight },
            {   23, ColorRole::HighlightedText },
            {   24, ColorRole::Link },
            {   25, ColorRole::LinkVisited },
            {   26, ColorRole::AlternateBase },
            {   27, ColorRole::NoRole },
            {   28, ColorRole::ToolTipBase },
            {   29, ColorRole::ToolTipText },
            {   30, ColorRole::PlaceholderText },
            {   31, ColorRole::Accent },
            {   32, ColorRole::NColorRoles },
        }),
    };
    return QtMocHelpers::metaObjectData<QPalette, qt_meta_tag_ZN8QPaletteE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPalette::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QPaletteE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QPaletteE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QPaletteE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
