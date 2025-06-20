/****************************************************************************
** Meta object code from reading C++ file 'qwidget_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/kernel/qwidget_p.h"
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwidget_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14QWidgetPrivateE_t {};
} // unnamed namespace

template <> constexpr inline auto QWidgetPrivate::qt_create_metaobjectdata<qt_meta_tag_ZN14QWidgetPrivateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QWidgetPrivate",
        "DrawWidgetFlags",
        "DrawWidgetFlag",
        "DrawAsRoot",
        "DrawPaintOnScreen",
        "DrawRecursive",
        "DrawInvisible",
        "DontSubtractOpaqueChildren",
        "DontDrawOpaqueChildren",
        "DontDrawNativeChildren",
        "DontSetCompositionMode",
        "UseEffectRegionBounds",
        "Direction",
        "DirectionNorth",
        "DirectionEast",
        "DirectionSouth",
        "DirectionWest",
        "CloseMode",
        "CloseNoEvent",
        "CloseWithEvent",
        "CloseWithSpontaneousEvent"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'DrawWidgetFlags'
        QtMocHelpers::EnumData<DrawWidgetFlags>(1, 2, QMC::EnumFlags{}).add({
            {    3, DrawWidgetFlag::DrawAsRoot },
            {    4, DrawWidgetFlag::DrawPaintOnScreen },
            {    5, DrawWidgetFlag::DrawRecursive },
            {    6, DrawWidgetFlag::DrawInvisible },
            {    7, DrawWidgetFlag::DontSubtractOpaqueChildren },
            {    8, DrawWidgetFlag::DontDrawOpaqueChildren },
            {    9, DrawWidgetFlag::DontDrawNativeChildren },
            {   10, DrawWidgetFlag::DontSetCompositionMode },
            {   11, DrawWidgetFlag::UseEffectRegionBounds },
        }),
        // enum 'Direction'
        QtMocHelpers::EnumData<Direction>(12, 12, QMC::EnumFlags{}).add({
            {   13, Direction::DirectionNorth },
            {   14, Direction::DirectionEast },
            {   15, Direction::DirectionSouth },
            {   16, Direction::DirectionWest },
        }),
        // enum 'CloseMode'
        QtMocHelpers::EnumData<CloseMode>(17, 17, QMC::EnumFlags{}).add({
            {   18, CloseMode::CloseNoEvent },
            {   19, CloseMode::CloseWithEvent },
            {   20, CloseMode::CloseWithSpontaneousEvent },
        }),
    };
    return QtMocHelpers::metaObjectData<QWidgetPrivate, qt_meta_tag_ZN14QWidgetPrivateE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QWidgetPrivate::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QObjectPrivate>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QWidgetPrivateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QWidgetPrivateE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QWidgetPrivateE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
