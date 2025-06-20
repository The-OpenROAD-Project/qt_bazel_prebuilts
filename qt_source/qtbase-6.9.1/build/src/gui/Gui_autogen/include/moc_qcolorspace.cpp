/****************************************************************************
** Meta object code from reading C++ file 'qcolorspace.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/painting/qcolorspace.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcolorspace.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QColorSpaceE_t {};
} // unnamed namespace

template <> constexpr inline auto QColorSpace::qt_create_metaobjectdata<qt_meta_tag_ZN11QColorSpaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QColorSpace",
        "NamedColorSpace",
        "SRgb",
        "SRgbLinear",
        "AdobeRgb",
        "DisplayP3",
        "ProPhotoRgb",
        "Bt2020",
        "Bt2100Pq",
        "Bt2100Hlg",
        "Primaries",
        "Custom",
        "DciP3D65",
        "TransferFunction",
        "Linear",
        "Gamma",
        "St2084",
        "Hlg",
        "TransformModel",
        "ThreeComponentMatrix",
        "ElementListProcessing",
        "ColorModel",
        "Undefined",
        "Rgb",
        "Gray",
        "Cmyk"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'NamedColorSpace'
        QtMocHelpers::EnumData<NamedColorSpace>(1, 1, QMC::EnumFlags{}).add({
            {    2, NamedColorSpace::SRgb },
            {    3, NamedColorSpace::SRgbLinear },
            {    4, NamedColorSpace::AdobeRgb },
            {    5, NamedColorSpace::DisplayP3 },
            {    6, NamedColorSpace::ProPhotoRgb },
            {    7, NamedColorSpace::Bt2020 },
            {    8, NamedColorSpace::Bt2100Pq },
            {    9, NamedColorSpace::Bt2100Hlg },
        }),
        // enum 'Primaries'
        QtMocHelpers::EnumData<Primaries>(10, 10, QMC::EnumIsScoped).add({
            {   11, Primaries::Custom },
            {    2, Primaries::SRgb },
            {    4, Primaries::AdobeRgb },
            {   12, Primaries::DciP3D65 },
            {    6, Primaries::ProPhotoRgb },
            {    7, Primaries::Bt2020 },
        }),
        // enum 'TransferFunction'
        QtMocHelpers::EnumData<TransferFunction>(13, 13, QMC::EnumIsScoped).add({
            {   11, TransferFunction::Custom },
            {   14, TransferFunction::Linear },
            {   15, TransferFunction::Gamma },
            {    2, TransferFunction::SRgb },
            {    6, TransferFunction::ProPhotoRgb },
            {    7, TransferFunction::Bt2020 },
            {   16, TransferFunction::St2084 },
            {   17, TransferFunction::Hlg },
        }),
        // enum 'TransformModel'
        QtMocHelpers::EnumData<TransformModel>(18, 18, QMC::EnumIsScoped).add({
            {   19, TransformModel::ThreeComponentMatrix },
            {   20, TransformModel::ElementListProcessing },
        }),
        // enum 'ColorModel'
        QtMocHelpers::EnumData<ColorModel>(21, 21, QMC::EnumIsScoped).add({
            {   22, ColorModel::Undefined },
            {   23, ColorModel::Rgb },
            {   24, ColorModel::Gray },
            {   25, ColorModel::Cmyk },
        }),
    };
    return QtMocHelpers::metaObjectData<QColorSpace, qt_meta_tag_ZN11QColorSpaceE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QColorSpace::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QColorSpaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QColorSpaceE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QColorSpaceE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
