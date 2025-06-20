/****************************************************************************
** Meta object code from reading C++ file 'qfont.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/text/qfont.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfont.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN5QFontE_t {};
} // unnamed namespace

template <> constexpr inline auto QFont::qt_create_metaobjectdata<qt_meta_tag_ZN5QFontE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFont",
        "StyleHint",
        "Helvetica",
        "SansSerif",
        "Times",
        "Serif",
        "Courier",
        "TypeWriter",
        "OldEnglish",
        "Decorative",
        "System",
        "AnyStyle",
        "Cursive",
        "Monospace",
        "Fantasy",
        "StyleStrategy",
        "PreferDefault",
        "PreferBitmap",
        "PreferDevice",
        "PreferOutline",
        "ForceOutline",
        "PreferMatch",
        "PreferQuality",
        "PreferAntialias",
        "NoAntialias",
        "NoSubpixelAntialias",
        "PreferNoShaping",
        "ContextFontMerging",
        "PreferTypoLineMetrics",
        "NoFontMerging",
        "HintingPreference",
        "PreferDefaultHinting",
        "PreferNoHinting",
        "PreferVerticalHinting",
        "PreferFullHinting",
        "Weight",
        "Thin",
        "ExtraLight",
        "Light",
        "Normal",
        "Medium",
        "DemiBold",
        "Bold",
        "ExtraBold",
        "Black",
        "Style",
        "StyleNormal",
        "StyleItalic",
        "StyleOblique",
        "Stretch",
        "AnyStretch",
        "UltraCondensed",
        "ExtraCondensed",
        "Condensed",
        "SemiCondensed",
        "Unstretched",
        "SemiExpanded",
        "Expanded",
        "ExtraExpanded",
        "UltraExpanded",
        "Capitalization",
        "MixedCase",
        "AllUppercase",
        "AllLowercase",
        "SmallCaps",
        "Capitalize",
        "SpacingType",
        "PercentageSpacing",
        "AbsoluteSpacing",
        "ResolveProperties",
        "NoPropertiesResolved",
        "FamilyResolved",
        "SizeResolved",
        "StyleHintResolved",
        "StyleStrategyResolved",
        "WeightResolved",
        "StyleResolved",
        "UnderlineResolved",
        "OverlineResolved",
        "StrikeOutResolved",
        "FixedPitchResolved",
        "StretchResolved",
        "KerningResolved",
        "CapitalizationResolved",
        "LetterSpacingResolved",
        "WordSpacingResolved",
        "HintingPreferenceResolved",
        "StyleNameResolved",
        "FamiliesResolved",
        "FeaturesResolved",
        "VariableAxesResolved",
        "AllPropertiesResolved"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'StyleHint'
        QtMocHelpers::EnumData<StyleHint>(1, 1, QMC::EnumFlags{}).add({
            {    2, StyleHint::Helvetica },
            {    3, StyleHint::SansSerif },
            {    4, StyleHint::Times },
            {    5, StyleHint::Serif },
            {    6, StyleHint::Courier },
            {    7, StyleHint::TypeWriter },
            {    8, StyleHint::OldEnglish },
            {    9, StyleHint::Decorative },
            {   10, StyleHint::System },
            {   11, StyleHint::AnyStyle },
            {   12, StyleHint::Cursive },
            {   13, StyleHint::Monospace },
            {   14, StyleHint::Fantasy },
        }),
        // enum 'StyleStrategy'
        QtMocHelpers::EnumData<StyleStrategy>(15, 15, QMC::EnumFlags{}).add({
            {   16, StyleStrategy::PreferDefault },
            {   17, StyleStrategy::PreferBitmap },
            {   18, StyleStrategy::PreferDevice },
            {   19, StyleStrategy::PreferOutline },
            {   20, StyleStrategy::ForceOutline },
            {   21, StyleStrategy::PreferMatch },
            {   22, StyleStrategy::PreferQuality },
            {   23, StyleStrategy::PreferAntialias },
            {   24, StyleStrategy::NoAntialias },
            {   25, StyleStrategy::NoSubpixelAntialias },
            {   26, StyleStrategy::PreferNoShaping },
            {   27, StyleStrategy::ContextFontMerging },
            {   28, StyleStrategy::PreferTypoLineMetrics },
            {   29, StyleStrategy::NoFontMerging },
        }),
        // enum 'HintingPreference'
        QtMocHelpers::EnumData<HintingPreference>(30, 30, QMC::EnumFlags{}).add({
            {   31, HintingPreference::PreferDefaultHinting },
            {   32, HintingPreference::PreferNoHinting },
            {   33, HintingPreference::PreferVerticalHinting },
            {   34, HintingPreference::PreferFullHinting },
        }),
        // enum 'Weight'
        QtMocHelpers::EnumData<Weight>(35, 35, QMC::EnumFlags{}).add({
            {   36, Weight::Thin },
            {   37, Weight::ExtraLight },
            {   38, Weight::Light },
            {   39, Weight::Normal },
            {   40, Weight::Medium },
            {   41, Weight::DemiBold },
            {   42, Weight::Bold },
            {   43, Weight::ExtraBold },
            {   44, Weight::Black },
        }),
        // enum 'Style'
        QtMocHelpers::EnumData<Style>(45, 45, QMC::EnumFlags{}).add({
            {   46, Style::StyleNormal },
            {   47, Style::StyleItalic },
            {   48, Style::StyleOblique },
        }),
        // enum 'Stretch'
        QtMocHelpers::EnumData<Stretch>(49, 49, QMC::EnumFlags{}).add({
            {   50, Stretch::AnyStretch },
            {   51, Stretch::UltraCondensed },
            {   52, Stretch::ExtraCondensed },
            {   53, Stretch::Condensed },
            {   54, Stretch::SemiCondensed },
            {   55, Stretch::Unstretched },
            {   56, Stretch::SemiExpanded },
            {   57, Stretch::Expanded },
            {   58, Stretch::ExtraExpanded },
            {   59, Stretch::UltraExpanded },
        }),
        // enum 'Capitalization'
        QtMocHelpers::EnumData<Capitalization>(60, 60, QMC::EnumFlags{}).add({
            {   61, Capitalization::MixedCase },
            {   62, Capitalization::AllUppercase },
            {   63, Capitalization::AllLowercase },
            {   64, Capitalization::SmallCaps },
            {   65, Capitalization::Capitalize },
        }),
        // enum 'SpacingType'
        QtMocHelpers::EnumData<SpacingType>(66, 66, QMC::EnumFlags{}).add({
            {   67, SpacingType::PercentageSpacing },
            {   68, SpacingType::AbsoluteSpacing },
        }),
        // enum 'ResolveProperties'
        QtMocHelpers::EnumData<ResolveProperties>(69, 69, QMC::EnumFlags{}).add({
            {   70, ResolveProperties::NoPropertiesResolved },
            {   71, ResolveProperties::FamilyResolved },
            {   72, ResolveProperties::SizeResolved },
            {   73, ResolveProperties::StyleHintResolved },
            {   74, ResolveProperties::StyleStrategyResolved },
            {   75, ResolveProperties::WeightResolved },
            {   76, ResolveProperties::StyleResolved },
            {   77, ResolveProperties::UnderlineResolved },
            {   78, ResolveProperties::OverlineResolved },
            {   79, ResolveProperties::StrikeOutResolved },
            {   80, ResolveProperties::FixedPitchResolved },
            {   81, ResolveProperties::StretchResolved },
            {   82, ResolveProperties::KerningResolved },
            {   83, ResolveProperties::CapitalizationResolved },
            {   84, ResolveProperties::LetterSpacingResolved },
            {   85, ResolveProperties::WordSpacingResolved },
            {   86, ResolveProperties::HintingPreferenceResolved },
            {   87, ResolveProperties::StyleNameResolved },
            {   88, ResolveProperties::FamiliesResolved },
            {   89, ResolveProperties::FeaturesResolved },
            {   90, ResolveProperties::VariableAxesResolved },
            {   91, ResolveProperties::AllPropertiesResolved },
        }),
    };
    return QtMocHelpers::metaObjectData<QFont, qt_meta_tag_ZN5QFontE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFont::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5QFontE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5QFontE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5QFontE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
