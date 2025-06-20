/****************************************************************************
** Meta object code from reading C++ file 'qpainter.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/painting/qpainter.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpainter.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QPainterE_t {};
} // unnamed namespace

template <> constexpr inline auto QPainter::qt_create_metaobjectdata<qt_meta_tag_ZN8QPainterE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPainter",
        "RenderHint",
        "Antialiasing",
        "TextAntialiasing",
        "SmoothPixmapTransform",
        "VerticalSubpixelPositioning",
        "LosslessImageRendering",
        "NonCosmeticBrushPatterns",
        "RenderHints"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'RenderHint'
        QtMocHelpers::EnumData<RenderHint>(1, 1, QMC::EnumFlags{}).add({
            {    2, RenderHint::Antialiasing },
            {    3, RenderHint::TextAntialiasing },
            {    4, RenderHint::SmoothPixmapTransform },
            {    5, RenderHint::VerticalSubpixelPositioning },
            {    6, RenderHint::LosslessImageRendering },
            {    7, RenderHint::NonCosmeticBrushPatterns },
        }),
        // enum 'RenderHints'
        QtMocHelpers::EnumData<RenderHints>(8, 1, QMC::EnumFlags{}).add({
            {    2, RenderHint::Antialiasing },
            {    3, RenderHint::TextAntialiasing },
            {    4, RenderHint::SmoothPixmapTransform },
            {    5, RenderHint::VerticalSubpixelPositioning },
            {    6, RenderHint::LosslessImageRendering },
            {    7, RenderHint::NonCosmeticBrushPatterns },
        }),
    };
    return QtMocHelpers::metaObjectData<QPainter, qt_meta_tag_ZN8QPainterE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPainter::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QPainterE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QPainterE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QPainterE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
