/****************************************************************************
** Meta object code from reading C++ file 'qtextformat.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/text/qtextformat.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtextformat.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QTextFormatE_t {};
} // unnamed namespace

template <> constexpr inline auto QTextFormat::qt_create_metaobjectdata<qt_meta_tag_ZN11QTextFormatE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTextFormat",
        "FormatType",
        "InvalidFormat",
        "BlockFormat",
        "CharFormat",
        "ListFormat",
        "FrameFormat",
        "UserFormat",
        "Property",
        "ObjectIndex",
        "CssFloat",
        "LayoutDirection",
        "OutlinePen",
        "BackgroundBrush",
        "ForegroundBrush",
        "BackgroundImageUrl",
        "BlockAlignment",
        "BlockTopMargin",
        "BlockBottomMargin",
        "BlockLeftMargin",
        "BlockRightMargin",
        "TextIndent",
        "TabPositions",
        "BlockIndent",
        "LineHeight",
        "LineHeightType",
        "BlockNonBreakableLines",
        "BlockTrailingHorizontalRulerWidth",
        "HeadingLevel",
        "BlockQuoteLevel",
        "BlockCodeLanguage",
        "BlockCodeFence",
        "BlockMarker",
        "FirstFontProperty",
        "FontCapitalization",
        "FontLetterSpacing",
        "FontWordSpacing",
        "FontStyleHint",
        "FontStyleStrategy",
        "FontKerning",
        "FontHintingPreference",
        "FontFamilies",
        "FontStyleName",
        "FontLetterSpacingType",
        "FontStretch",
        "FontFamily",
        "FontPointSize",
        "FontSizeAdjustment",
        "FontSizeIncrement",
        "FontWeight",
        "FontItalic",
        "FontUnderline",
        "FontOverline",
        "FontStrikeOut",
        "FontFixedPitch",
        "FontPixelSize",
        "LastFontProperty",
        "TextUnderlineColor",
        "TextVerticalAlignment",
        "TextOutline",
        "TextUnderlineStyle",
        "TextToolTip",
        "TextSuperScriptBaseline",
        "TextSubScriptBaseline",
        "TextBaselineOffset",
        "IsAnchor",
        "AnchorHref",
        "AnchorName",
        "OldFontLetterSpacingType",
        "OldFontStretch",
        "OldTextUnderlineColor",
        "OldFontFamily",
        "ObjectType",
        "ListStyle",
        "ListIndent",
        "ListNumberPrefix",
        "ListNumberSuffix",
        "ListStart",
        "FrameBorder",
        "FrameMargin",
        "FramePadding",
        "FrameWidth",
        "FrameHeight",
        "FrameTopMargin",
        "FrameBottomMargin",
        "FrameLeftMargin",
        "FrameRightMargin",
        "FrameBorderBrush",
        "FrameBorderStyle",
        "TableColumns",
        "TableColumnWidthConstraints",
        "TableCellSpacing",
        "TableCellPadding",
        "TableHeaderRowCount",
        "TableBorderCollapse",
        "TableCellRowSpan",
        "TableCellColumnSpan",
        "TableCellTopPadding",
        "TableCellBottomPadding",
        "TableCellLeftPadding",
        "TableCellRightPadding",
        "TableCellTopBorder",
        "TableCellBottomBorder",
        "TableCellLeftBorder",
        "TableCellRightBorder",
        "TableCellTopBorderStyle",
        "TableCellBottomBorderStyle",
        "TableCellLeftBorderStyle",
        "TableCellRightBorderStyle",
        "TableCellTopBorderBrush",
        "TableCellBottomBorderBrush",
        "TableCellLeftBorderBrush",
        "TableCellRightBorderBrush",
        "ImageName",
        "ImageTitle",
        "ImageAltText",
        "ImageWidth",
        "ImageHeight",
        "ImageQuality",
        "ImageMaxWidth",
        "FullWidthSelection",
        "PageBreakPolicy",
        "UserProperty",
        "ObjectTypes",
        "NoObject",
        "ImageObject",
        "TableObject",
        "TableCellObject",
        "UserObject"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'FormatType'
        QtMocHelpers::EnumData<FormatType>(1, 1, QMC::EnumFlags{}).add({
            {    2, FormatType::InvalidFormat },
            {    3, FormatType::BlockFormat },
            {    4, FormatType::CharFormat },
            {    5, FormatType::ListFormat },
            {    6, FormatType::FrameFormat },
            {    7, FormatType::UserFormat },
        }),
        // enum 'Property'
        QtMocHelpers::EnumData<Property>(8, 8, QMC::EnumFlags{}).add({
            {    9, Property::ObjectIndex },
            {   10, Property::CssFloat },
            {   11, Property::LayoutDirection },
            {   12, Property::OutlinePen },
            {   13, Property::BackgroundBrush },
            {   14, Property::ForegroundBrush },
            {   15, Property::BackgroundImageUrl },
            {   16, Property::BlockAlignment },
            {   17, Property::BlockTopMargin },
            {   18, Property::BlockBottomMargin },
            {   19, Property::BlockLeftMargin },
            {   20, Property::BlockRightMargin },
            {   21, Property::TextIndent },
            {   22, Property::TabPositions },
            {   23, Property::BlockIndent },
            {   24, Property::LineHeight },
            {   25, Property::LineHeightType },
            {   26, Property::BlockNonBreakableLines },
            {   27, Property::BlockTrailingHorizontalRulerWidth },
            {   28, Property::HeadingLevel },
            {   29, Property::BlockQuoteLevel },
            {   30, Property::BlockCodeLanguage },
            {   31, Property::BlockCodeFence },
            {   32, Property::BlockMarker },
            {   33, Property::FirstFontProperty },
            {   34, Property::FontCapitalization },
            {   35, Property::FontLetterSpacing },
            {   36, Property::FontWordSpacing },
            {   37, Property::FontStyleHint },
            {   38, Property::FontStyleStrategy },
            {   39, Property::FontKerning },
            {   40, Property::FontHintingPreference },
            {   41, Property::FontFamilies },
            {   42, Property::FontStyleName },
            {   43, Property::FontLetterSpacingType },
            {   44, Property::FontStretch },
            {   45, Property::FontFamily },
            {   46, Property::FontPointSize },
            {   47, Property::FontSizeAdjustment },
            {   48, Property::FontSizeIncrement },
            {   49, Property::FontWeight },
            {   50, Property::FontItalic },
            {   51, Property::FontUnderline },
            {   52, Property::FontOverline },
            {   53, Property::FontStrikeOut },
            {   54, Property::FontFixedPitch },
            {   55, Property::FontPixelSize },
            {   56, Property::LastFontProperty },
            {   57, Property::TextUnderlineColor },
            {   58, Property::TextVerticalAlignment },
            {   59, Property::TextOutline },
            {   60, Property::TextUnderlineStyle },
            {   61, Property::TextToolTip },
            {   62, Property::TextSuperScriptBaseline },
            {   63, Property::TextSubScriptBaseline },
            {   64, Property::TextBaselineOffset },
            {   65, Property::IsAnchor },
            {   66, Property::AnchorHref },
            {   67, Property::AnchorName },
            {   68, Property::OldFontLetterSpacingType },
            {   69, Property::OldFontStretch },
            {   70, Property::OldTextUnderlineColor },
            {   71, Property::OldFontFamily },
            {   72, Property::ObjectType },
            {   73, Property::ListStyle },
            {   74, Property::ListIndent },
            {   75, Property::ListNumberPrefix },
            {   76, Property::ListNumberSuffix },
            {   77, Property::ListStart },
            {   78, Property::FrameBorder },
            {   79, Property::FrameMargin },
            {   80, Property::FramePadding },
            {   81, Property::FrameWidth },
            {   82, Property::FrameHeight },
            {   83, Property::FrameTopMargin },
            {   84, Property::FrameBottomMargin },
            {   85, Property::FrameLeftMargin },
            {   86, Property::FrameRightMargin },
            {   87, Property::FrameBorderBrush },
            {   88, Property::FrameBorderStyle },
            {   89, Property::TableColumns },
            {   90, Property::TableColumnWidthConstraints },
            {   91, Property::TableCellSpacing },
            {   92, Property::TableCellPadding },
            {   93, Property::TableHeaderRowCount },
            {   94, Property::TableBorderCollapse },
            {   95, Property::TableCellRowSpan },
            {   96, Property::TableCellColumnSpan },
            {   97, Property::TableCellTopPadding },
            {   98, Property::TableCellBottomPadding },
            {   99, Property::TableCellLeftPadding },
            {  100, Property::TableCellRightPadding },
            {  101, Property::TableCellTopBorder },
            {  102, Property::TableCellBottomBorder },
            {  103, Property::TableCellLeftBorder },
            {  104, Property::TableCellRightBorder },
            {  105, Property::TableCellTopBorderStyle },
            {  106, Property::TableCellBottomBorderStyle },
            {  107, Property::TableCellLeftBorderStyle },
            {  108, Property::TableCellRightBorderStyle },
            {  109, Property::TableCellTopBorderBrush },
            {  110, Property::TableCellBottomBorderBrush },
            {  111, Property::TableCellLeftBorderBrush },
            {  112, Property::TableCellRightBorderBrush },
            {  113, Property::ImageName },
            {  114, Property::ImageTitle },
            {  115, Property::ImageAltText },
            {  116, Property::ImageWidth },
            {  117, Property::ImageHeight },
            {  118, Property::ImageQuality },
            {  119, Property::ImageMaxWidth },
            {  120, Property::FullWidthSelection },
            {  121, Property::PageBreakPolicy },
            {  122, Property::UserProperty },
        }),
        // enum 'ObjectTypes'
        QtMocHelpers::EnumData<ObjectTypes>(123, 123, QMC::EnumFlags{}).add({
            {  124, ObjectTypes::NoObject },
            {  125, ObjectTypes::ImageObject },
            {  126, ObjectTypes::TableObject },
            {  127, ObjectTypes::TableCellObject },
            {  128, ObjectTypes::UserObject },
        }),
    };
    return QtMocHelpers::metaObjectData<QTextFormat, qt_meta_tag_ZN11QTextFormatE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTextFormat::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QTextFormatE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QTextFormatE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QTextFormatE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
