// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#include "qcssparser_p.h"

#include <QtCore/qmap.h>
#include <qdebug.h>
#include <qicon.h>
#include <qcolor.h>
#include <qfont.h>
#include <qfileinfo.h>
#include <qfontmetrics.h>
#include <qbrush.h>
#include <qimagereader.h>
#include <qtextformat.h>

#include <QtCore/q20algorithm.h>

#ifndef QT_NO_CSSPARSER

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

QT_IMPL_METATYPE_EXTERN_TAGGED(QCss::BackgroundData, QCss__BackgroundData)
QT_IMPL_METATYPE_EXTERN_TAGGED(QCss::LengthData, QCss__LengthData)
QT_IMPL_METATYPE_EXTERN_TAGGED(QCss::BorderData, QCss__BorderData)

#include "qcssscanner.cpp"

using namespace QCss;

struct QCssKnownValue
{
    const char name[28];
    quint64 id;

    struct ByName;
};

struct QCssKnownValue::ByName
{
    constexpr bool operator()(const QCssKnownValue &lhs, const QCssKnownValue &rhs) const noexcept
    { return std::string_view{lhs.name} < std::string_view{rhs.name}; }
};
#if !defined(Q_CC_GNU_ONLY) || Q_CC_GNU >= 1000
#  define NOT_OLD_GCCs(...) __VA_ARGS__
#else
#  define NOT_OLD_GCCs(...) /* nothing */
#endif
#define CHECK_ARRAY_IS_SORTED(array, Num) \
    static_assert(std::size(array) == Num); \
    NOT_OLD_GCCs( \
    static_assert(q20::is_sorted(std::begin(array), std::end(array), \
                                 QCssKnownValue::ByName{})); \
    ) /* NOT_OLD_GCCs */ \
    /* end */

// This array is sorted alphabetically.
static constexpr QCssKnownValue properties[] = {
    { "-qt-background-role", QtBackgroundRole },
    { "-qt-block-indent", QtBlockIndent },
    { "-qt-fg-texture-cachekey", QtForegroundTextureCacheKey },
    { "-qt-foreground", QtForeground },
    { "-qt-line-height-type", QtLineHeightType },
    { "-qt-list-indent", QtListIndent },
    { "-qt-list-number-prefix", QtListNumberPrefix },
    { "-qt-list-number-suffix", QtListNumberSuffix },
    { "-qt-paragraph-type", QtParagraphType },
    { "-qt-stroke-color", QtStrokeColor },
    { "-qt-stroke-dasharray", QtStrokeDashArray },
    { "-qt-stroke-dashoffset", QtStrokeDashOffset },
    { "-qt-stroke-linecap", QtStrokeLineCap },
    { "-qt-stroke-linejoin", QtStrokeLineJoin },
    { "-qt-stroke-miterlimit", QtStrokeMiterLimit },
    { "-qt-stroke-width", QtStrokeWidth },
    { "-qt-style-features", QtStyleFeatures },
    { "-qt-table-type", QtTableType },
    { "-qt-user-state", QtUserState },
    { "accent-color", QtAccent },
    { "alternate-background-color", QtAlternateBackground },
    { "background", Background },
    { "background-attachment", BackgroundAttachment },
    { "background-clip", BackgroundClip },
    { "background-color", BackgroundColor },
    { "background-image", BackgroundImage },
    { "background-origin", BackgroundOrigin },
    { "background-position", BackgroundPosition },
    { "background-repeat", BackgroundRepeat },
    { "border", Border },
    { "border-bottom", BorderBottom },
    { "border-bottom-color", BorderBottomColor },
    { "border-bottom-left-radius", BorderBottomLeftRadius },
    { "border-bottom-right-radius", BorderBottomRightRadius },
    { "border-bottom-style", BorderBottomStyle },
    { "border-bottom-width", BorderBottomWidth },
    { "border-collapse", BorderCollapse },
    { "border-color", BorderColor },
    { "border-image", BorderImage },
    { "border-left", BorderLeft },
    { "border-left-color", BorderLeftColor },
    { "border-left-style", BorderLeftStyle },
    { "border-left-width", BorderLeftWidth },
    { "border-radius", BorderRadius },
    { "border-right", BorderRight },
    { "border-right-color", BorderRightColor },
    { "border-right-style", BorderRightStyle },
    { "border-right-width", BorderRightWidth },
    { "border-style", BorderStyles },
    { "border-top", BorderTop },
    { "border-top-color", BorderTopColor },
    { "border-top-left-radius", BorderTopLeftRadius },
    { "border-top-right-radius", BorderTopRightRadius },
    { "border-top-style", BorderTopStyle },
    { "border-top-width", BorderTopWidth },
    { "border-width", BorderWidth },
    { "bottom", Bottom },
    { "color", Color },
    { "float", Float },
    { "font", Font },
    { "font-family", FontFamily },
    { "font-kerning", FontKerning },
    { "font-size", FontSize },
    { "font-style", FontStyle },
    { "font-variant", FontVariant },
    { "font-weight", FontWeight },
    { "height", Height },
    { "icon", QtIcon },
    { "image", QtImage },
    { "image-position", QtImageAlignment },
    { "left", Left },
    { "letter-spacing", LetterSpacing },
    { "line-height", LineHeight },
    { "list-style", ListStyle },
    { "list-style-type", ListStyleType },
    { "margin" , Margin },
    { "margin-bottom", MarginBottom },
    { "margin-left", MarginLeft },
    { "margin-right", MarginRight },
    { "margin-top", MarginTop },
    { "max-height", MaximumHeight },
    { "max-width", MaximumWidth },
    { "min-height", MinimumHeight },
    { "min-width", MinimumWidth },
    { "outline", Outline },
    { "outline-bottom-left-radius", OutlineBottomLeftRadius },
    { "outline-bottom-right-radius", OutlineBottomRightRadius },
    { "outline-color", OutlineColor },
    { "outline-offset", OutlineOffset },
    { "outline-radius", OutlineRadius },
    { "outline-style", OutlineStyle },
    { "outline-top-left-radius", OutlineTopLeftRadius },
    { "outline-top-right-radius", OutlineTopRightRadius },
    { "outline-width", OutlineWidth },
    { "padding", Padding },
    { "padding-bottom", PaddingBottom },
    { "padding-left", PaddingLeft },
    { "padding-right", PaddingRight },
    { "padding-top", PaddingTop },
    { "page-break-after", PageBreakAfter },
    { "page-break-before", PageBreakBefore },
    { "placeholder-text-color", QtPlaceHolderTextColor },
    { "position", Position },
    { "right", Right },
    { "selection-background-color", QtSelectionBackground },
    { "selection-color", QtSelectionForeground },
    { "spacing", QtSpacing },
    { "subcontrol-origin", QtOrigin },
    { "subcontrol-position", QtPosition },
    { "text-align", TextAlignment },
    { "text-decoration", TextDecoration },
    { "text-decoration-color", TextDecorationColor },
    { "text-indent", TextIndent },
    { "text-transform", TextTransform },
    { "text-underline-style", TextUnderlineStyle },
    { "top", Top },
    { "vertical-align", VerticalAlignment },
    { "white-space", Whitespace },
    { "width", Width },
    { "word-spacing", WordSpacing }
};
CHECK_ARRAY_IS_SORTED(properties, size_t(NumProperties) - 1)

static constexpr QCssKnownValue values[] = {
    { "accent", Value_Accent },
    { "active", Value_Active },
    { "alternate-base", Value_AlternateBase },
    { "always", Value_Always },
    { "auto", Value_Auto },
    { "base", Value_Base },
    { "beveljoin", Value_BevelJoin},
    { "bold", Value_Bold },
    { "bottom", Value_Bottom },
    { "bright-text", Value_BrightText },
    { "button", Value_Button },
    { "button-text", Value_ButtonText },
    { "center", Value_Center },
    { "circle", Value_Circle },
    { "dark", Value_Dark },
    { "dashed", Value_Dashed },
    { "decimal", Value_Decimal },
    { "disabled", Value_Disabled },
    { "disc", Value_Disc },
    { "dot-dash", Value_DotDash },
    { "dot-dot-dash", Value_DotDotDash },
    { "dotted", Value_Dotted },
    { "double", Value_Double },
    { "flatcap", Value_FlatCap},
    { "groove", Value_Groove },
    { "highlight", Value_Highlight },
    { "highlighted-text", Value_HighlightedText },
    { "inset", Value_Inset },
    { "italic", Value_Italic },
    { "large", Value_Large },
    { "left", Value_Left },
    { "light", Value_Light },
    { "line-through", Value_LineThrough },
    { "link", Value_Link },
    { "link-visited", Value_LinkVisited },
    { "lower-alpha", Value_LowerAlpha },
    { "lower-roman", Value_LowerRoman },
    { "lowercase", Value_Lowercase },
    { "medium", Value_Medium },
    { "mid", Value_Mid },
    { "middle", Value_Middle },
    { "midlight", Value_Midlight },
    { "miterjoin", Value_MiterJoin},
    { "native", Value_Native },
    { "no-role", Value_NoRole },
    { "none", Value_None },
    { "normal", Value_Normal },
    { "nowrap", Value_NoWrap },
    { "oblique", Value_Oblique },
    { "off", Value_Off },
    { "on", Value_On },
    { "outset", Value_Outset },
    { "overline", Value_Overline },
    { "placeholder-text", Value_PlaceholderText },
    { "pre", Value_Pre },
    { "pre-line", Value_PreLine },
    { "pre-wrap", Value_PreWrap },
    { "ridge", Value_Ridge },
    { "right", Value_Right },
    { "roundcap", Value_RoundCap},
    { "roundjoin", Value_RoundJoin},
    { "selected", Value_Selected },
    { "shadow", Value_Shadow },
    { "small" , Value_Small },
    { "small-caps", Value_SmallCaps },
    { "solid", Value_Solid },
    { "square", Value_Square },
    { "squarecap", Value_SquareCap},
    { "sub", Value_Sub },
    { "super", Value_Super },
    { "svgmiterjoin", Value_SvgMiterJoin},
    { "text", Value_Text },
    { "tooltip-base", Value_ToolTipBase },
    { "tooltip-text", Value_ToolTipText },
    { "top", Value_Top },
    { "transparent", Value_Transparent },
    { "underline", Value_Underline },
    { "upper-alpha", Value_UpperAlpha },
    { "upper-roman", Value_UpperRoman },
    { "uppercase", Value_Uppercase },
    { "wave", Value_Wave },
    { "window", Value_Window },
    { "window-text", Value_WindowText },
    { "x-large", Value_XLarge },
    { "xx-large", Value_XXLarge }
};
CHECK_ARRAY_IS_SORTED(values, size_t(NumKnownValues) - 1)

//Map id to strings as they appears in the 'values' array above
static constexpr uchar indexOfId[] = {
    0, 46, 54, 47, 55, 56, 63, 38, 29, 83, 84, 28, 48, 7, 76, 52,
    32, 68, 69, 30, 58, 74, 8, 12, 43, 65, 21, 15, 19, 20, 22, 24, 57, 27, 51, 80, 40, 4, 3, 45, 75, 18, 13,
    66, 16, 35, 77, 36, 78, 64, 79, 37, 67, 23, 59, 42, 6, 60, 70, 82, 10, 31, 41, 14, 39, 71, 9, 11, 5, 81,
    62, 25, 26, 33, 34, 2, 44, 72, 73, 53, 0, 17, 1, 61, 50, 49 };

static_assert(std::size(indexOfId) == size_t(NumKnownValues));

QString Value::toString() const
{
    if (type == KnownIdentifier) {
        return QLatin1StringView(values[indexOfId[variant.toInt()]].name);
    } else {
        return variant.toString();
    }
}

static constexpr QCssKnownValue pseudos[] = {
    { "active", PseudoClass_Active },
    { "adjoins-item", PseudoClass_Item },
    { "alternate", PseudoClass_Alternate },
    { "bottom", PseudoClass_Bottom },
    { "checked", PseudoClass_Checked },
    { "closable", PseudoClass_Closable },
    { "closed", PseudoClass_Closed },
    { "default", PseudoClass_Default },
    { "disabled", PseudoClass_Disabled },
    { "edit-focus", PseudoClass_EditFocus },
    { "editable", PseudoClass_Editable },
    { "enabled", PseudoClass_Enabled },
    { "exclusive", PseudoClass_Exclusive },
    { "first", PseudoClass_First },
    { "flat", PseudoClass_Flat },
    { "floatable", PseudoClass_Floatable },
    { "focus", PseudoClass_Focus },
    { "has-children", PseudoClass_Children },
    { "has-siblings", PseudoClass_Sibling },
    { "horizontal", PseudoClass_Horizontal },
    { "hover", PseudoClass_Hover },
    { "indeterminate" , PseudoClass_Indeterminate },
    { "last", PseudoClass_Last },
    { "left", PseudoClass_Left },
    { "maximized", PseudoClass_Maximized },
    { "middle", PseudoClass_Middle },
    { "minimized", PseudoClass_Minimized },
    { "movable", PseudoClass_Movable },
    { "next-selected", PseudoClass_NextSelected },
    { "no-frame", PseudoClass_Frameless },
    { "non-exclusive", PseudoClass_NonExclusive },
    { "off", PseudoClass_Unchecked },
    { "on", PseudoClass_Checked },
    { "only-one", PseudoClass_OnlyOne },
    { "open", PseudoClass_Open },
    { "pressed", PseudoClass_Pressed },
    { "previous-selected", PseudoClass_PreviousSelected },
    { "read-only", PseudoClass_ReadOnly },
    { "right", PseudoClass_Right },
    { "selected", PseudoClass_Selected },
    { "top", PseudoClass_Top },
    { "unchecked" , PseudoClass_Unchecked },
    { "vertical", PseudoClass_Vertical },
    { "window", PseudoClass_Window }
};
CHECK_ARRAY_IS_SORTED(pseudos, size_t(NumPseudos) - 1)

static constexpr QCssKnownValue origins[] = {
    { "border", Origin_Border },
    { "content", Origin_Content },
    { "margin", Origin_Margin }, // not in css
    { "padding", Origin_Padding }
};
CHECK_ARRAY_IS_SORTED(origins, size_t(NumKnownOrigins) - 1)

static constexpr QCssKnownValue repeats[] = {
    { "no-repeat", Repeat_None },
    { "repeat-x", Repeat_X },
    { "repeat-xy", Repeat_XY },
    { "repeat-y", Repeat_Y }
};
CHECK_ARRAY_IS_SORTED(repeats, size_t(NumKnownRepeats) - 1)

static constexpr QCssKnownValue tileModes[] = {
    { "repeat", TileMode_Repeat },
    { "round", TileMode_Round },
    { "stretch", TileMode_Stretch },
};
CHECK_ARRAY_IS_SORTED(tileModes, size_t(NumKnownTileModes) - 1)

static constexpr QCssKnownValue positions[] = {
    { "absolute", PositionMode_Absolute },
    { "fixed", PositionMode_Fixed },
    { "relative", PositionMode_Relative },
    { "static", PositionMode_Static }
};
CHECK_ARRAY_IS_SORTED(positions, size_t(NumKnownPositionModes) - 1)

static constexpr QCssKnownValue attachments[] = {
    { "fixed", Attachment_Fixed },
    { "scroll", Attachment_Scroll }
};
CHECK_ARRAY_IS_SORTED(attachments, size_t(NumKnownAttachments) - 1)

static constexpr QCssKnownValue styleFeatures[] = {
    { "background-color", StyleFeature_BackgroundColor },
    { "background-gradient", StyleFeature_BackgroundGradient },
    { "none", StyleFeature_None }
};
CHECK_ARRAY_IS_SORTED(styleFeatures, size_t(NumKnownStyleFeatures) - 1)

static bool operator<(const QString &name, const QCssKnownValue &prop)
{
    return QString::compare(name, QLatin1StringView(prop.name), Qt::CaseInsensitive) < 0;
}

static bool operator<(const QCssKnownValue &prop, const QString &name)
{
    return QString::compare(QLatin1StringView(prop.name), name, Qt::CaseInsensitive) < 0;
}

#undef CHECK_ARRAY_IS_SORTED
#undef NOT_OLD_GCCs

static quint64 findKnownValue(const QString &name, const QCssKnownValue *start, int numValues)
{
    const QCssKnownValue *end = start + (numValues - 1);
    const QCssKnownValue *prop = std::lower_bound(start, end, name);
    if ((prop == end) || (name < *prop))
        return 0;
    return prop->id;
}

static inline bool isInheritable(Property propertyId)
{
    switch (propertyId) {
    case Font:
    case FontKerning:
    case FontFamily:
    case FontSize:
    case FontStyle:
    case FontWeight:
    case TextIndent:
    case Whitespace:
    case ListStyleType:
    case ListStyle:
    case TextAlignment:
    case FontVariant:
    case TextTransform:
    case LineHeight:
    case LetterSpacing:
    case WordSpacing:
        return true;
    default:
        break;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////
// Value Extractor
ValueExtractor::ValueExtractor(const QList<Declaration> &decls, const QPalette &pal)
: declarations(decls), adjustment(0), fontExtracted(false), pal(pal)
{
}

LengthData ValueExtractor::lengthValue(const Value& v)
{
    const QString str = v.variant.toString();
    QStringView s(str);
    LengthData data;
    data.unit = LengthData::None;
    if (s.endsWith(u"px", Qt::CaseInsensitive))
        data.unit = LengthData::Px;
    else if (s.endsWith(u"ex", Qt::CaseInsensitive))
        data.unit = LengthData::Ex;
    else if (s.endsWith(u"em", Qt::CaseInsensitive))
        data.unit = LengthData::Em;

    if (data.unit != LengthData::None)
        s.chop(2);
    else if (v.type == Value::Percentage)
        data.unit = LengthData::Percent;

    data.number = s.toDouble();
    return data;
}

static int lengthValueFromData(const LengthData& data, const QFont& f)
{
    const int scale = (data.unit == LengthData::Ex ? QFontMetrics(f).xHeight()
                      : data.unit == LengthData::Em ? QFontMetrics(f).height() : 1);
    // raised lower limit due to the implementation of qRound()
    return qRound(qBound(double(INT_MIN) + 0.1, scale * data.number, double(INT_MAX)));
}

QTextLength ValueExtractor::textLength(const Declaration &decl)
{
    const LengthData data = lengthValue(decl.d->values.at(0));
    if (data.unit == LengthData::Percent)
        return QTextLength(QTextLength::PercentageLength, data.number);

    return QTextLength(QTextLength::FixedLength, lengthValueFromData(data, f));
}

int ValueExtractor::lengthValue(const Declaration &decl)
{
    if (decl.d->parsed.isValid())
        return  lengthValueFromData(qvariant_cast<LengthData>(decl.d->parsed), f);
    if (decl.d->values.size() < 1)
        return 0;
    LengthData data = lengthValue(decl.d->values.at(0));
    decl.d->parsed = QVariant::fromValue<LengthData>(data);
    return lengthValueFromData(data,f);
}

void ValueExtractor::lengthValues(const Declaration &decl, int *m)
{
    if (decl.d->parsed.isValid()) {
        QList<QVariant> v = decl.d->parsed.toList();
        Q_ASSERT(v.size() == 4);
        for (int i = 0; i < 4; i++)
            m[i] = lengthValueFromData(qvariant_cast<LengthData>(v.at(i)), f);
        return;
    }

    LengthData datas[4];
    int i;
    for (i = 0; i < qMin(decl.d->values.size(), 4); i++)
        datas[i] = lengthValue(decl.d->values[i]);

    if (i == 0) {
        LengthData zero = {0.0, LengthData::None};
        datas[0] = datas[1] = datas[2] = datas[3] = zero;
    } else if (i == 1) {
        datas[3] = datas[2] = datas[1] = datas[0];
    } else if (i == 2) {
        datas[2] = datas[0];
        datas[3] = datas[1];
    } else if (i == 3) {
        datas[3] = datas[1];
    }

    QList<QVariant> v;
    v.reserve(4);
    for (i = 0; i < 4; i++) {
        v += QVariant::fromValue<LengthData>(datas[i]);
        m[i] = lengthValueFromData(datas[i], f);
    }
    decl.d->parsed = v;
}

bool ValueExtractor::extractGeometry(int *w, int *h, int *minw, int *minh, int *maxw, int *maxh)
{
    extractFont();
    bool hit = false;
    for (int i = 0; i < declarations.size(); i++) {
        const Declaration &decl = declarations.at(i);
        switch (decl.d->propertyId) {
        case Width: *w = lengthValue(decl); break;
        case Height: *h = lengthValue(decl); break;
        case MinimumWidth: *minw = lengthValue(decl); break;
        case MinimumHeight: *minh = lengthValue(decl); break;
        case MaximumWidth: *maxw = lengthValue(decl); break;
        case MaximumHeight: *maxh = lengthValue(decl); break;
        default: continue;
        }
        hit = true;
    }

    return hit;
}

bool ValueExtractor::extractPosition(int *left, int *top, int *right, int *bottom, QCss::Origin *origin,
                                     Qt::Alignment *position, QCss::PositionMode *mode, Qt::Alignment *textAlignment)
{
    extractFont();
    bool hit = false;
    for (int i = 0; i < declarations.size(); i++) {
        const Declaration &decl = declarations.at(i);
        switch (decl.d->propertyId) {
        case Left: *left = lengthValue(decl); break;
        case Top: *top = lengthValue(decl); break;
        case Right: *right = lengthValue(decl); break;
        case Bottom: *bottom = lengthValue(decl); break;
        case QtOrigin: *origin = decl.originValue(); break;
        case QtPosition: *position = decl.alignmentValue(); break;
        case TextAlignment: *textAlignment = decl.alignmentValue(); break;
        case Position: *mode = decl.positionValue(); break;
        default: continue;
        }
        hit = true;
    }

    return hit;
}

bool ValueExtractor::extractBox(int *margins, int *paddings, int *spacing)
{
    extractFont();
    bool hit = false;
    for (int i = 0; i < declarations.size(); i++) {
        const Declaration &decl = declarations.at(i);
        switch (decl.d->propertyId) {
        case PaddingLeft: paddings[LeftEdge] = lengthValue(decl); break;
        case PaddingRight: paddings[RightEdge] = lengthValue(decl); break;
        case PaddingTop: paddings[TopEdge] = lengthValue(decl); break;
        case PaddingBottom: paddings[BottomEdge] = lengthValue(decl); break;
        case Padding: lengthValues(decl, paddings); break;

        case MarginLeft: margins[LeftEdge] = lengthValue(decl); break;
        case MarginRight: margins[RightEdge] = lengthValue(decl); break;
        case MarginTop: margins[TopEdge] = lengthValue(decl); break;
        case MarginBottom: margins[BottomEdge] = lengthValue(decl); break;
        case Margin: lengthValues(decl, margins); break;
        case QtSpacing: if (spacing) *spacing = lengthValue(decl); break;

        default: continue;
        }
        hit = true;
    }

    return hit;
}

int ValueExtractor::extractStyleFeatures()
{
    int features = StyleFeature_None;
    for (int i = 0; i < declarations.size(); i++) {
        const Declaration &decl = declarations.at(i);
        if (decl.d->propertyId == QtStyleFeatures)
            features = decl.styleFeaturesValue();
    }
    return features;
}

QSize ValueExtractor::sizeValue(const Declaration &decl)
{
    if (decl.d->parsed.isValid()) {
        QList<QVariant> v = decl.d->parsed.toList();
        return QSize(lengthValueFromData(qvariant_cast<LengthData>(v.at(0)), f),
                     lengthValueFromData(qvariant_cast<LengthData>(v.at(1)), f));
    }

    LengthData x[2] = { {0, LengthData::None }, {0, LengthData::None} };
    if (decl.d->values.size() > 0)
        x[0] = lengthValue(decl.d->values.at(0));
    if (decl.d->values.size() > 1)
        x[1] = lengthValue(decl.d->values.at(1));
    else
        x[1] = x[0];
    QList<QVariant> v;
    v << QVariant::fromValue<LengthData>(x[0]) << QVariant::fromValue<LengthData>(x[1]);
    decl.d->parsed = v;
    return QSize(lengthValueFromData(x[0], f), lengthValueFromData(x[1], f));
}

void ValueExtractor::sizeValues(const Declaration &decl, QSize *radii)
{
    radii[0] = sizeValue(decl);
    for (int i = 1; i < 4; i++)
        radii[i] = radii[0];
}

bool ValueExtractor::extractBorder(int *borders, QBrush *colors, BorderStyle *styles,
                                   QSize *radii)
{
    extractFont();
    bool hit = false;
    for (int i = 0; i < declarations.size(); i++) {
        const Declaration &decl = declarations.at(i);
        switch (decl.d->propertyId) {
        case BorderLeftWidth: borders[LeftEdge] = lengthValue(decl); break;
        case BorderRightWidth: borders[RightEdge] = lengthValue(decl); break;
        case BorderTopWidth: borders[TopEdge] = lengthValue(decl); break;
        case BorderBottomWidth: borders[BottomEdge] = lengthValue(decl); break;
        case BorderWidth: lengthValues(decl, borders); break;

        case BorderLeftColor: colors[LeftEdge] = decl.brushValue(pal); break;
        case BorderRightColor: colors[RightEdge] = decl.brushValue(pal); break;
        case BorderTopColor: colors[TopEdge] = decl.brushValue(pal); break;
        case BorderBottomColor: colors[BottomEdge] = decl.brushValue(pal); break;
        case BorderColor: decl.brushValues(colors, pal); break;

        case BorderTopStyle: styles[TopEdge] = decl.styleValue(); break;
        case BorderBottomStyle: styles[BottomEdge] = decl.styleValue(); break;
        case BorderLeftStyle: styles[LeftEdge] = decl.styleValue(); break;
        case BorderRightStyle: styles[RightEdge] = decl.styleValue(); break;
        case BorderStyles:  decl.styleValues(styles); break;

        case BorderTopLeftRadius: radii[0] = sizeValue(decl); break;
        case BorderTopRightRadius: radii[1] = sizeValue(decl); break;
        case BorderBottomLeftRadius: radii[2] = sizeValue(decl); break;
        case BorderBottomRightRadius: radii[3] = sizeValue(decl); break;
        case BorderRadius: sizeValues(decl, radii); break;

        case BorderLeft:
            borderValue(decl, &borders[LeftEdge], &styles[LeftEdge], &colors[LeftEdge]);
            break;
        case BorderTop:
            borderValue(decl, &borders[TopEdge], &styles[TopEdge], &colors[TopEdge]);
            break;
        case BorderRight:
            borderValue(decl, &borders[RightEdge], &styles[RightEdge], &colors[RightEdge]);
            break;
        case BorderBottom:
            borderValue(decl, &borders[BottomEdge], &styles[BottomEdge], &colors[BottomEdge]);
            break;
        case Border:
            borderValue(decl, &borders[LeftEdge], &styles[LeftEdge], &colors[LeftEdge]);
            borders[TopEdge] = borders[RightEdge] = borders[BottomEdge] = borders[LeftEdge];
            styles[TopEdge] = styles[RightEdge] = styles[BottomEdge] = styles[LeftEdge];
            colors[TopEdge] = colors[RightEdge] = colors[BottomEdge] = colors[LeftEdge];
            break;

        default: continue;
        }
        hit = true;
    }

    return hit;
}

bool ValueExtractor::extractOutline(int *borders, QBrush *colors, BorderStyle *styles,
                                   QSize *radii, int *offsets)
{
    extractFont();
    bool hit = false;
    for (int i = 0; i < declarations.size(); i++) {
        const Declaration &decl = declarations.at(i);
        switch (decl.d->propertyId) {
        case OutlineWidth: lengthValues(decl, borders); break;
        case OutlineColor: decl.brushValues(colors, pal); break;
        case OutlineStyle:  decl.styleValues(styles); break;

        case OutlineTopLeftRadius: radii[0] = sizeValue(decl); break;
        case OutlineTopRightRadius: radii[1] = sizeValue(decl); break;
        case OutlineBottomLeftRadius: radii[2] = sizeValue(decl); break;
        case OutlineBottomRightRadius: radii[3] = sizeValue(decl); break;
        case OutlineRadius: sizeValues(decl, radii); break;
        case OutlineOffset: lengthValues(decl, offsets); break;

        case Outline:
            borderValue(decl, &borders[LeftEdge], &styles[LeftEdge], &colors[LeftEdge]);
            borders[TopEdge] = borders[RightEdge] = borders[BottomEdge] = borders[LeftEdge];
            styles[TopEdge] = styles[RightEdge] = styles[BottomEdge] = styles[LeftEdge];
            colors[TopEdge] = colors[RightEdge] = colors[BottomEdge] = colors[LeftEdge];
            break;

        default: continue;
        }
        hit = true;
    }

    return hit;
}

static Qt::Alignment parseAlignment(const QCss::Value *values, int count)
{
    Qt::Alignment a[2] = { { }, { } };
    for (int i = 0; i < qMin(2, count); i++) {
        if (values[i].type != Value::KnownIdentifier)
            break;
        switch (values[i].variant.toInt()) {
        case Value_Left: a[i] = Qt::AlignLeft; break;
        case Value_Right: a[i] = Qt::AlignRight; break;
        case Value_Top: a[i] = Qt::AlignTop; break;
        case Value_Bottom: a[i] = Qt::AlignBottom; break;
        case Value_Center: a[i] = Qt::AlignCenter; break;
        default: break;
        }
    }

    if (a[0] == Qt::AlignCenter && a[1] != 0 && a[1] != Qt::AlignCenter)
        a[0] = (a[1] == Qt::AlignLeft || a[1] == Qt::AlignRight) ? Qt::AlignVCenter : Qt::AlignHCenter;
    if ((a[1] == 0 || a[1] == Qt::AlignCenter) && a[0] != Qt::AlignCenter)
        a[1] = (a[0] == Qt::AlignLeft || a[0] == Qt::AlignRight) ? Qt::AlignVCenter : Qt::AlignHCenter;
    return a[0] | a[1];
}

static ColorData parseColorValue(QCss::Value v)
{
    if (v.type == Value::Identifier || v.type == Value::String) {
        v.variant.convert(QMetaType::fromType<QColor>());
        v.type = Value::Color;
    }

    if (v.type == Value::Color)
        return qvariant_cast<QColor>(v.variant);

    if (v.type == Value::KnownIdentifier && v.variant.toInt() == Value_Transparent)
        return QColor(Qt::transparent);

    if (v.type != Value::Function)
        return ColorData();

    QStringList lst = v.variant.toStringList();
    if (lst.size() != 2)
        return ColorData();

    const QString &identifier = lst.at(0);
    if ((identifier.compare("palette"_L1, Qt::CaseInsensitive)) == 0) {
        static_assert((Value_LastColorRole - Value_FirstColorRole + 1) == QPalette::ColorRole::NColorRoles);

        int role = findKnownValue(lst.at(1).trimmed(), values, NumKnownValues);
        if (role >= Value_FirstColorRole && role <= Value_LastColorRole)
            return (QPalette::ColorRole)(role-Value_FirstColorRole);

        return ColorData();
    }

    const bool rgb = identifier.startsWith("rgb"_L1);
    const bool hsv = !rgb && identifier.startsWith("hsv"_L1);
    const bool hsl = !rgb && !hsv && identifier.startsWith("hsl"_L1);

    if (!rgb && !hsv && !hsl)
        return ColorData();

    const bool hasAlpha = identifier.size() == 4 && identifier.at(3) == u'a';
    if (identifier.size() > 3 && !hasAlpha)
        return ColorData();

    Parser p(lst.at(1));
    if (!p.testExpr())
        return ColorData();

    QList<QCss::Value> colorDigits;
    if (!p.parseExpr(&colorDigits))
        return ColorData();
    const int tokenCount = colorDigits.size();

    for (int i = 0; i < qMin(tokenCount, 7); i += 2) {
        if (colorDigits.at(i).type == Value::Percentage) {
            const qreal maxRange = (rgb || i != 0) ? 255. : 359.;
            colorDigits[i].variant = colorDigits.at(i).variant.toReal() * (maxRange / 100.);
            colorDigits[i].type = Value::Number;
        } else if (colorDigits.at(i).type != Value::Number) {
            return ColorData();
        }
    }


    if (tokenCount < 5)
        return ColorData();

    if (hasAlpha && tokenCount != 7) {
        qWarning("QCssParser::parseColorValue: Specified color with alpha value but no alpha given: '%s'", qPrintable(lst.join(u' ')));
        return ColorData();
    }
    if (!hasAlpha && tokenCount != 5) {
        qWarning("QCssParser::parseColorValue: Specified color without alpha value but alpha given: '%s'", qPrintable(lst.join(u' ')));
        return ColorData();
    }

    int v1 = colorDigits.at(0).variant.toInt();
    int v2 = colorDigits.at(2).variant.toInt();
    int v3 = colorDigits.at(4).variant.toInt();
    int alpha = 255;
    if (tokenCount == 7) {
        int alphaValue = colorDigits.at(6).variant.toInt();
        if (alphaValue <= 1)
            alpha = colorDigits.at(6).variant.toReal() * 255.;
        else
            alpha = alphaValue;
    }

    if (rgb)
        return QColor::fromRgb(v1, v2, v3, alpha);
    if (hsv)
        return QColor::fromHsv(v1, v2, v3, alpha);
    return QColor::fromHsl(v1, v2, v3, alpha);
}

static QColor colorFromData(const ColorData& c, const QPalette &pal)
{
    if (c.type == ColorData::Color) {
        return c.color;
    } else if (c.type == ColorData::Role) {
        return pal.color(c.role);
    }
    return QColor();
}

static BrushData parseBrushValue(const QCss::Value &v, const QPalette &pal)
{
    ColorData c = parseColorValue(v);
    if (c.type == ColorData::Color) {
        return QBrush(c.color);
    } else if (c.type == ColorData::Role) {
        return c.role;
    }

    if (v.type != Value::Function)
        return BrushData();

    QStringList lst = v.variant.toStringList();
    if (lst.size() != 2)
        return BrushData();

    QStringList gradFuncs;
    gradFuncs << "qlineargradient"_L1 << "qradialgradient"_L1 << "qconicalgradient"_L1 << "qgradient"_L1;
    int gradType = -1;

    if ((gradType = gradFuncs.indexOf(lst.at(0).toLower())) == -1)
        return BrushData();

    QHash<QString, qreal> vars;
    QList<QGradientStop> stops;

    int spread = -1;
    QStringList spreads;
    spreads << "pad"_L1 << "reflect"_L1 << "repeat"_L1;

    int coordinateMode = -1;
    QStringList coordinateModes;
    coordinateModes << "logical"_L1 << "stretchtodevice"_L1 << "objectbounding"_L1 << "object"_L1;

    bool dependsOnThePalette = false;
    Parser parser(lst.at(1));
    while (parser.hasNext()) {
        parser.skipSpace();
        if (!parser.test(IDENT))
            return BrushData();
        QString attr = parser.lexem();
        parser.skipSpace();
        if (!parser.test(COLON))
            return BrushData();
        parser.skipSpace();
        if (attr.compare("stop"_L1, Qt::CaseInsensitive) == 0) {
            QCss::Value stop, color;
            parser.next();
            if (!parser.parseTerm(&stop)) return BrushData();
            parser.skipSpace();
            parser.next();
            if (!parser.parseTerm(&color)) return BrushData();
            ColorData cd = parseColorValue(color);
            if (cd.type == ColorData::Role)
                dependsOnThePalette = true;
            stops.append(QGradientStop(stop.variant.toReal(), colorFromData(cd, pal)));
        } else {
            parser.next();
            QCss::Value value;
            (void)parser.parseTerm(&value);
            if (attr.compare("spread"_L1, Qt::CaseInsensitive) == 0)
                spread = spreads.indexOf(value.variant.toString());
            else if (attr.compare("coordinatemode"_L1, Qt::CaseInsensitive) == 0)
                coordinateMode = coordinateModes.indexOf(value.variant.toString());
            else
                vars[attr] = value.variant.toReal();
        }
        parser.skipSpace();
        (void)parser.test(COMMA);
    }

    if (gradType == 0) {
        QLinearGradient lg(vars.value("x1"_L1), vars.value("y1"_L1),
                           vars.value("x2"_L1), vars.value("y2"_L1));
        lg.setCoordinateMode(coordinateMode < 0 ? QGradient::ObjectBoundingMode : QGradient::CoordinateMode(coordinateMode));
        lg.setStops(stops);
        if (spread != -1)
            lg.setSpread(QGradient::Spread(spread));
        BrushData bd = QBrush(lg);
        if (dependsOnThePalette)
            bd.type = BrushData::DependsOnThePalette;
        return bd;
    }

    if (gradType == 1) {
        QRadialGradient rg(vars.value("cx"_L1), vars.value("cy"_L1),
                           vars.value("radius"_L1), vars.value("fx"_L1),
                           vars.value("fy"_L1));
        rg.setCoordinateMode(coordinateMode < 0 ? QGradient::ObjectBoundingMode : QGradient::CoordinateMode(coordinateMode));
        rg.setStops(stops);
        if (spread != -1)
            rg.setSpread(QGradient::Spread(spread));
        BrushData bd = QBrush(rg);
        if (dependsOnThePalette)
            bd.type = BrushData::DependsOnThePalette;
        return bd;
    }

    if (gradType == 2) {
        QConicalGradient cg(vars.value("cx"_L1), vars.value("cy"_L1), vars.value("angle"_L1));
        cg.setCoordinateMode(coordinateMode < 0 ? QGradient::ObjectBoundingMode : QGradient::CoordinateMode(coordinateMode));
        cg.setStops(stops);
        if (spread != -1)
            cg.setSpread(QGradient::Spread(spread));
        BrushData bd = QBrush(cg);
        if (dependsOnThePalette)
            bd.type = BrushData::DependsOnThePalette;
        return bd;
    }

    return BrushData();
}

static QBrush brushFromData(const BrushData& c, const QPalette &pal)
{
    if (c.type == BrushData::Role) {
        return pal.color(c.role);
    } else {
        return c.brush;
    }
}

static BorderStyle parseStyleValue(const QCss::Value &v)
{
    if (v.type == Value::KnownIdentifier) {
        switch (v.variant.toInt()) {
        case Value_None:
            return BorderStyle_None;
        case Value_Dotted:
            return BorderStyle_Dotted;
        case Value_Dashed:
            return BorderStyle_Dashed;
        case Value_Solid:
            return BorderStyle_Solid;
        case Value_Double:
            return BorderStyle_Double;
        case Value_DotDash:
            return BorderStyle_DotDash;
        case Value_DotDotDash:
            return BorderStyle_DotDotDash;
        case Value_Groove:
            return BorderStyle_Groove;
        case Value_Ridge:
            return BorderStyle_Ridge;
        case Value_Inset:
            return BorderStyle_Inset;
        case Value_Outset:
            return BorderStyle_Outset;
        case Value_Native:
            return BorderStyle_Native;
        default:
            break;
        }
    }

    return BorderStyle_Unknown;
}

void ValueExtractor::borderValue(const Declaration &decl, int *width, QCss::BorderStyle *style, QBrush *color)
{
    if (decl.d->parsed.isValid()) {
        BorderData data = qvariant_cast<BorderData>(decl.d->parsed);
        *width = lengthValueFromData(data.width, f);
        *style = data.style;
        *color = data.color.type != BrushData::Invalid ? brushFromData(data.color, pal) : QBrush(QColor());
        return;
    }

    *width = 0;
    *style = BorderStyle_None;
    *color = QColor();

    if (decl.d->values.isEmpty())
        return;

    BorderData data;
    data.width.number = 0;
    data.width.unit = LengthData::None;
    data.style = BorderStyle_None;

    int i = 0;
    if (decl.d->values.at(i).type == Value::Length || decl.d->values.at(i).type == Value::Number) {
        data.width = lengthValue(decl.d->values.at(i));
        *width = lengthValueFromData(data.width, f);
        if (++i >= decl.d->values.size()) {
            decl.d->parsed = QVariant::fromValue<BorderData>(data);
            return;
        }
    }

    data.style = parseStyleValue(decl.d->values.at(i));
    if (data.style != BorderStyle_Unknown) {
        *style = data.style;
        if (++i >= decl.d->values.size()) {
            decl.d->parsed = QVariant::fromValue<BorderData>(data);
            return;
        }
    } else {
        data.style = BorderStyle_None;
    }

     data.color = parseBrushValue(decl.d->values.at(i), pal);
    if (data.color.type != BrushData::Invalid) {
        *color = brushFromData(data.color, pal);
        if (data.color.type != BrushData::DependsOnThePalette)
            decl.d->parsed = QVariant::fromValue<BorderData>(data);
    }
}

static void parseShorthandBackgroundProperty(const QList<QCss::Value> &values, BrushData *brush, QString *image, Repeat *repeat, Qt::Alignment *alignment, const QPalette &pal)
{
    *brush = BrushData();
    *image = QString();
    *repeat = Repeat_XY;
    *alignment = Qt::AlignTop | Qt::AlignLeft;

    for (int i = 0; i < values.size(); ++i) {
        const QCss::Value &v = values.at(i);
        if (v.type == Value::Uri) {
            *image = v.variant.toString();
            continue;
        } else if (v.type == Value::KnownIdentifier && v.variant.toInt() == Value_None) {
            *image = QString();
            continue;
        } else if (v.type == Value::KnownIdentifier && v.variant.toInt() == Value_Transparent) {
            *brush = QBrush(Qt::transparent);
        }

        Repeat repeatAttempt = static_cast<Repeat>(findKnownValue(v.variant.toString(),
                                                   repeats, NumKnownRepeats));
        if (repeatAttempt != Repeat_Unknown) {
            *repeat = repeatAttempt;
            continue;
        }

        if (v.type == Value::KnownIdentifier) {
            const int start = i;
            int count = 1;
            if (i < values.size() - 1
                && values.at(i + 1).type == Value::KnownIdentifier) {
                ++i;
                ++count;
            }
            Qt::Alignment a = parseAlignment(values.constData() + start, count);
            if (int(a) != 0) {
                *alignment = a;
                continue;
            }
            i -= count - 1;
        }

        *brush = parseBrushValue(v, pal);
    }
}

bool ValueExtractor::extractBackground(QBrush *brush, QString *image, Repeat *repeat,
                                       Qt::Alignment *alignment, Origin *origin, Attachment *attachment,
                                       Origin *clip)
{
    bool hit = false;
    for (int i = 0; i < declarations.size(); ++i) {
        const Declaration &decl = declarations.at(i);
        if (decl.d->values.isEmpty())
            continue;
        const QCss::Value &val = decl.d->values.at(0);
        switch (decl.d->propertyId) {
            case BackgroundColor:
                    *brush = decl.brushValue();
                break;
            case BackgroundImage:
                if (val.type == Value::Uri)
                    *image = val.variant.toString();
                break;
            case BackgroundRepeat:
                if (decl.d->parsed.isValid()) {
                    *repeat = static_cast<Repeat>(decl.d->parsed.toInt());
                } else {
                    *repeat = static_cast<Repeat>(findKnownValue(val.variant.toString(),
                                                  repeats, NumKnownRepeats));
                    decl.d->parsed = *repeat;
                }
                break;
            case BackgroundPosition:
                *alignment = decl.alignmentValue();
                break;
            case BackgroundOrigin:
                *origin = decl.originValue();
                break;
            case BackgroundClip:
                *clip = decl.originValue();
                break;
            case Background:
                if (decl.d->parsed.isValid()) {
                    BackgroundData data = qvariant_cast<BackgroundData>(decl.d->parsed);
                    *brush = brushFromData(data.brush, pal);
                    *image = data.image;
                    *repeat = data.repeat;
                    *alignment = data.alignment;
                } else {
                    BrushData brushData;
                    parseShorthandBackgroundProperty(decl.d->values, &brushData, image, repeat, alignment, pal);
                    *brush = brushFromData(brushData, pal);
                    if (brushData.type != BrushData::DependsOnThePalette) {
                        BackgroundData data = { brushData, *image, *repeat, *alignment };
                        decl.d->parsed = QVariant::fromValue<BackgroundData>(data);
                    }
                }
                break;
            case BackgroundAttachment:
                *attachment = decl.attachmentValue();
                break;
            default: continue;
        }
        hit = true;
    }
    return hit;
}

static bool setFontSizeFromValue(QCss::Value value, QFont *font, int *fontSizeAdjustment)
{
    if (value.type == Value::KnownIdentifier) {
        bool valid = true;
        switch (value.variant.toInt()) {
            case Value_Small: *fontSizeAdjustment = -1; break;
            case Value_Medium: *fontSizeAdjustment = 0; break;
            case Value_Large: *fontSizeAdjustment = 1; break;
            case Value_XLarge: *fontSizeAdjustment = 2; break;
            case Value_XXLarge: *fontSizeAdjustment = 3; break;
            default: valid = false; break;
        }
        return valid;
    }
    if (value.type != Value::Length)
        return false;

    bool valid = false;
    QString s = value.variant.toString();
    if (s.endsWith("pt"_L1, Qt::CaseInsensitive)) {
        s.chop(2);
        value.variant = s;
        if (value.variant.convert(QMetaType::fromType<qreal>())) {
            font->setPointSizeF(qBound(qreal(0), value.variant.toReal(), qreal(1 << 24) - 1));
            valid = true;
        }
    } else if (s.endsWith("px"_L1, Qt::CaseInsensitive)) {
        s.chop(2);
        value.variant = s;
        if (value.variant.convert(QMetaType::fromType<qreal>())) {
            font->setPixelSize(qBound(0, value.variant.toInt(), (1 << 24) - 1));
            valid = true;
        }
    }
    return valid;
}

static bool setFontStyleFromValue(const QCss::Value &value, QFont *font)
{
    if (value.type != Value::KnownIdentifier)
        return false ;
    switch (value.variant.toInt()) {
        case Value_Normal: font->setStyle(QFont::StyleNormal); return true;
        case Value_Italic: font->setStyle(QFont::StyleItalic); return true;
        case Value_Oblique: font->setStyle(QFont::StyleOblique); return true;
        default: break;
    }
    return false;
}

static bool setFontKerningFromValue(const QCss::Value &value, QFont *font)
{
    if (value.type != Value::KnownIdentifier)
        return false ;
    switch (value.variant.toInt()) {
        case Value_Normal: font->setKerning(true); return true;
        case Value_None: font->setKerning(false); return true;
        case Value_Auto: return true;
        default: break;
    }
    return false;
}

static bool setFontWeightFromValue(const QCss::Value &value, QFont *font)
{
    if (value.type == Value::KnownIdentifier) {
        switch (value.variant.toInt()) {
            case Value_Normal: font->setWeight(QFont::Normal); return true;
            case Value_Bold: font->setWeight(QFont::Bold); return true;
            default: break;
        }
        return false;
    }
    if (value.type != Value::Number)
        return false;
    // .toInt() would call qRound64() and might overflow the long long there
    font->setWeight(QFont::Weight(qRound(qBound(0.0, value.variant.toDouble(), 1001.0))));
    return true;
}

/** \internal
 * parse the font family from the values (starting from index \a start)
 * and set it the \a font
 * The function returns \c true if a family was extracted.
 */
static bool setFontFamilyFromValues(const QList<QCss::Value> &values, QFont *font, int start = 0)
{
    QString family;
    QStringList families;
    bool shouldAddSpace = false;
    for (int i = start; i < values.size(); ++i) {
        const QCss::Value &v = values.at(i);
        if (v.type == Value::TermOperatorComma) {
            families << family;
            family.clear();
            shouldAddSpace = false;
            continue;
        }
        const QString str = v.variant.toString();
        if (str.isEmpty())
            break;
        if (shouldAddSpace)
            family += u' ';
        family += str;
        shouldAddSpace = true;
    }
    if (!family.isEmpty())
        families << family;
    if (families.isEmpty())
        return false;
    font->setFamilies(families);
    return true;
}

static void setTextDecorationFromValues(const QList<QCss::Value> &values, QFont *font)
{
    for (int i = 0; i < values.size(); ++i) {
        if (values.at(i).type != Value::KnownIdentifier)
            continue;
        switch (values.at(i).variant.toInt()) {
            case Value_Underline: font->setUnderline(true); break;
            case Value_Overline: font->setOverline(true); break;
            case Value_LineThrough: font->setStrikeOut(true); break;
            case Value_None:
                font->setUnderline(false);
                font->setOverline(false);
                font->setStrikeOut(false);
                break;
            default: break;
        }
    }
}

static void setLetterSpacingFromValue(const QCss::Value &value, QFont *font)
{
    QString s = value.variant.toString();
    qreal val;
    bool ok = false;
    if (s.endsWith("em"_L1, Qt::CaseInsensitive)) {
        s.chop(2);
        val = s.toDouble(&ok);
        if (ok)
            font->setLetterSpacing(QFont::PercentageSpacing, (val + 1.0) * 100);
    } else if (s.endsWith("px"_L1, Qt::CaseInsensitive)) {
        s.chop(2);
        val = s.toDouble(&ok);
        if (ok)
            font->setLetterSpacing(QFont::AbsoluteSpacing, val);
    }
}

static void setWordSpacingFromValue(const QCss::Value &value, QFont *font)
{
    QString s = value.variant.toString();
    if (s.endsWith("px"_L1, Qt::CaseInsensitive)) {
        s.chop(2);
        qreal val;
        bool ok = false;
        val = s.toDouble(&ok);
        if (ok)
            font->setWordSpacing(val);
    }
}

static void parseShorthandFontProperty(const QList<QCss::Value> &values, QFont *font, int *fontSizeAdjustment)
{
    font->setStyle(QFont::StyleNormal);
    font->setWeight(QFont::Normal);
    *fontSizeAdjustment = -255;

    int i = 0;
    while (i < values.size()) {
        if (setFontStyleFromValue(values.at(i), font)
            || setFontWeightFromValue(values.at(i), font))
            ++i;
        else
            break;
    }

    if (i < values.size()) {
        setFontSizeFromValue(values.at(i), font, fontSizeAdjustment);
        ++i;
    }

    if (i < values.size()) {
        setFontFamilyFromValues(values, font, i);
    }
}

static void setFontVariantFromValue(const QCss::Value &value, QFont *font)
{
    if (value.type == Value::KnownIdentifier) {
        switch (value.variant.toInt()) {
            case Value_Normal: font->setCapitalization(QFont::MixedCase); break;
            case Value_SmallCaps: font->setCapitalization(QFont::SmallCaps); break;
            default: break;
        }
    }
}

static void setTextTransformFromValue(const QCss::Value &value, QFont *font)
{
    if (value.type == Value::KnownIdentifier) {
        switch (value.variant.toInt()) {
            case Value_None: font->setCapitalization(QFont::MixedCase); break;
            case Value_Uppercase: font->setCapitalization(QFont::AllUppercase); break;
            case Value_Lowercase: font->setCapitalization(QFont::AllLowercase); break;
            default: break;
        }
    }
}

bool ValueExtractor::extractFont(QFont *font, int *fontSizeAdjustment)
{
    if (fontExtracted) {
        *font = f;
        *fontSizeAdjustment = adjustment;
        return fontExtracted == 1;
    }

    bool hit = false;
    for (int i = 0; i < declarations.size(); ++i) {
        const Declaration &decl = declarations.at(i);
        if (decl.d->values.isEmpty())
            continue;
        const QCss::Value &val = decl.d->values.at(0);
        switch (decl.d->propertyId) {
            case FontSize: setFontSizeFromValue(val, font, fontSizeAdjustment); break;
            case FontStyle: setFontStyleFromValue(val, font); break;
            case FontWeight: setFontWeightFromValue(val, font); break;
            case FontFamily: setFontFamilyFromValues(decl.d->values, font); break;
            case FontKerning: setFontKerningFromValue(val, font); break;
            case TextDecoration: setTextDecorationFromValues(decl.d->values, font); break;
            case Font: parseShorthandFontProperty(decl.d->values, font, fontSizeAdjustment); break;
            case FontVariant: setFontVariantFromValue(val, font); break;
            case TextTransform: setTextTransformFromValue(val, font); break;
            case LetterSpacing: setLetterSpacingFromValue(val, font); break;
            case WordSpacing: setWordSpacingFromValue(val, font); break;
            default: continue;
        }
        hit = true;
    }

    f = *font;
    adjustment = *fontSizeAdjustment;
    fontExtracted = hit ? 1 : 2;
    return hit;
}

bool ValueExtractor::extractPalette(QBrush *foreground,
                                    QBrush *selectedForeground,
                                    QBrush *selectedBackground,
                                    QBrush *alternateBackground,
                                    QBrush *placeHolderTextForeground,
                                    QBrush *accent)
{
    bool hit = false;
    for (int i = 0; i < declarations.size(); ++i) {
        const Declaration &decl = declarations.at(i);
        switch (decl.d->propertyId) {
        case Color: *foreground = decl.brushValue(pal); break;
        case QtSelectionForeground: *selectedForeground = decl.brushValue(pal); break;
        case QtSelectionBackground: *selectedBackground = decl.brushValue(pal); break;
        case QtAlternateBackground: *alternateBackground = decl.brushValue(pal); break;
        case QtPlaceHolderTextColor: *placeHolderTextForeground = decl.brushValue(pal); break;
        case QtAccent: *accent = decl.brushValue(pal); break;
        default: continue;
        }
        hit = true;
    }
    return hit;
}

void ValueExtractor::extractFont()
{
    if (fontExtracted)
        return;
    int dummy = -255;
    extractFont(&f, &dummy);
}

bool ValueExtractor::extractImage(QIcon *icon, Qt::Alignment *a, QSize *size)
{
    bool hit = false;
    for (int i = 0; i < declarations.size(); ++i) {
        const Declaration &decl = declarations.at(i);
        switch (decl.d->propertyId) {
        case QtImage:
            *icon = decl.iconValue();
            if (decl.d->values.size() > 0 && decl.d->values.at(0).type == Value::Uri) {
                // try to pull just the size from the image...
                QImageReader imageReader(decl.d->values.at(0).variant.toString());
                if ((*size = imageReader.size()).isNull()) {
                    // but we'll have to load the whole image if the
                    // format doesn't support just reading the size
                    *size = imageReader.read().size();
                }
            }
            break;
        case QtImageAlignment: *a = decl.alignmentValue();  break;
        default: continue;
        }
        hit = true;
    }
    return hit;
}

bool ValueExtractor::extractIcon(QIcon *icon, QSize *size)
{
    // Find last declaration that specifies an icon
    const auto declaration = std::find_if(
                declarations.rbegin(), declarations.rend(),
                [](const Declaration &decl) { return decl.d->propertyId == QtIcon; });
    if (declaration == declarations.rend())
        return false;

    *icon = declaration->iconValue();

    // If the value contains a URI, try to get the size of the icon
    if (declaration->d->values.isEmpty())
        return true;

    const auto &propertyValue = declaration->d->values.constFirst();
    if (propertyValue.type != Value::Uri)
        return true;

    // First try to read just the size from the image without loading it
    const QString url(propertyValue.variant.toString());
    QImageReader imageReader(url);
    *size = imageReader.size();
    if (!size->isNull())
        return true;

    // Get the size by loading the image instead
    *size = imageReader.read().size();
    return true;
}

///////////////////////////////////////////////////////////////////////////////
// Declaration
QColor Declaration::colorValue(const QPalette &pal) const
{
    if (d->values.size() != 1)
        return QColor();

    if (d->parsed.isValid()) {
        switch (d->parsed.typeId()) {
        case qMetaTypeId<QColor>():
            return qvariant_cast<QColor>(d->parsed);
        case qMetaTypeId<int>():
            return pal.color((QPalette::ColorRole)(d->parsed.toInt()));
        case qMetaTypeId<QList<QVariant>>():
            if (d->parsed.toList().size() == 1) {
                auto parsedList = d->parsed.toList();
                const auto &value = parsedList.at(0);
                return qvariant_cast<QColor>(value);
            }
            break;
        }
    }

    ColorData color = parseColorValue(d->values.at(0));
    if (color.type == ColorData::Role) {
        d->parsed = QVariant::fromValue<int>(color.role);
        return pal.color((QPalette::ColorRole)(color.role));
    } else {
        d->parsed = QVariant::fromValue<QColor>(color.color);
        return color.color;
    }
}

QBrush Declaration::brushValue(const QPalette &pal) const
{
    if (d->values.size() != 1)
        return QBrush();

    if (d->parsed.isValid()) {
        if (d->parsed.userType() == QMetaType::QBrush)
            return qvariant_cast<QBrush>(d->parsed);
        if (d->parsed.userType() == QMetaType::Int)
            return pal.color((QPalette::ColorRole)(d->parsed.toInt()));
    }

    BrushData data = parseBrushValue(d->values.at(0), pal);

    if (data.type == BrushData::Role) {
        d->parsed = QVariant::fromValue<int>(data.role);
        return pal.color((QPalette::ColorRole)(data.role));
    } else {
        if (data.type != BrushData::DependsOnThePalette)
            d->parsed = QVariant::fromValue<QBrush>(data.brush);
        return data.brush;
    }
}

void Declaration::brushValues(QBrush *c, const QPalette &pal) const
{
    int needParse = 0x1f; // bits 0..3 say if we should parse the corresponding value.
                          // the bit 4 say we need to update d->parsed
    int i = 0;
    if (d->parsed.isValid()) {
        needParse = 0;
        Q_ASSERT(d->parsed.metaType() == QMetaType::fromType<QList<QVariant>>());
        QList<QVariant> v = d->parsed.toList();
        for (i = 0; i < qMin(v.size(), 4); i++) {
            if (v.at(i).userType() == QMetaType::QBrush) {
                c[i] = qvariant_cast<QBrush>(v.at(i));
            } else if (v.at(i).userType() == QMetaType::Int) {
                c[i] = pal.color((QPalette::ColorRole)(v.at(i).toInt()));
            } else {
                needParse |= (1<<i);
            }
        }
    }
    if (needParse != 0) {
        QList<QVariant> v;
        for (i = 0; i < qMin(d->values.size(), 4); i++) {
            if (!(needParse & (1<<i)))
                continue;
            BrushData data = parseBrushValue(d->values.at(i), pal);
            if (data.type == BrushData::Role) {
                v += QVariant::fromValue<int>(data.role);
                c[i] = pal.color((QPalette::ColorRole)(data.role));
            } else {
                if (data.type != BrushData::DependsOnThePalette) {
                    v += QVariant::fromValue<QBrush>(data.brush);
                } else {
                    v += QVariant();
                }
                c[i] = data.brush;
            }
        }
        if (needParse & 0x10)
            d->parsed = v;
    }
    if (i == 0) c[0] = c[1] = c[2] = c[3] = QBrush();
    else if (i == 1) c[3] = c[2] = c[1] = c[0];
    else if (i == 2) c[2] = c[0], c[3] = c[1];
    else if (i == 3) c[3] = c[1];
}

bool Declaration::realValue(qreal *real, const char *unit) const
{
    if (d->values.size() != 1)
        return false;
    const Value &v = d->values.at(0);
    if (unit && v.type != Value::Length)
        return false;
    const QString str = v.variant.toString();
    QStringView s(str);
    if (unit) {
        const QLatin1StringView unitStr(unit);
        if (!s.endsWith(unitStr, Qt::CaseInsensitive))
            return false;
        s.chop(unitStr.size());
    }
    bool ok = false;
    qreal val = s.toDouble(&ok);
    if (ok)
        *real = val;
    return ok;
}

static bool intValueHelper(const QCss::Value &v, int *i, const char *unit)
{
    if (unit && v.type != Value::Length)
        return false;
    const QString str = v.variant.toString();
    QStringView s(str);
    if (unit) {
        const QLatin1StringView unitStr(unit);
        if (!s.endsWith(unitStr, Qt::CaseInsensitive))
            return false;
        s.chop(unitStr.size());
    }
    bool ok = false;
    int val = s.toInt(&ok);
    if (ok)
        *i = val;
    return ok;
}

bool Declaration::intValue(int *i, const char *unit) const
{
    if (d->values.size() != 1)
        return false;
    return intValueHelper(d->values.at(0), i, unit);
}

QSize Declaration::sizeValue() const
{
    if (d->parsed.isValid())
        return qvariant_cast<QSize>(d->parsed);

    int x[2] = { 0, 0 };
    const int count = d->values.size();
    for (int i = 0; i < count; ++i) {
        if (i > 1) {
            qWarning("QCssParser::sizeValue: Too many values provided");
            break;
        }
        const auto &value = d->values.at(i);
        const QString valueString = value.variant.toString();
        if (valueString.endsWith(u"pt", Qt::CaseInsensitive)) {
            intValueHelper(value, &x[i], "pt");
            // according to https://www.w3.org/TR/css3-values/#absolute-lengths
            // 1pt = 1/72th of 1 inch, and 1px = 1/96th of 1 inch
            x[i] = (x[i] * 72) / 96;
        } else {
            // by default we use 'px'
            intValueHelper(value, &x[i], "px");
        }
    }
    if (count == 1)
        x[1] = x[0];
    QSize size(x[0], x[1]);
    d->parsed = QVariant::fromValue<QSize>(size);
    return size;
}

QRect Declaration::rectValue() const
{
    if (d->values.size() != 1)
        return QRect();

    if (d->parsed.isValid())
        return qvariant_cast<QRect>(d->parsed);

    const QCss::Value &v = d->values.at(0);
    if (v.type != Value::Function)
        return QRect();
    const QStringList func = v.variant.toStringList();
    if (func.size() != 2 || func.at(0).compare("rect"_L1) != 0)
        return QRect();
    const auto args = QStringView{func[1]}.split(u' ', Qt::SkipEmptyParts);
    if (args.size() != 4)
        return QRect();
    QRect rect(args[0].toInt(), args[1].toInt(), args[2].toInt(), args[3].toInt());
    d->parsed = QVariant::fromValue<QRect>(rect);
    return rect;
}

void Declaration::colorValues(QColor *c, const QPalette &pal) const
{
    int i;
    if (d->parsed.isValid()) {
        QList<QVariant> v = d->parsed.toList();
        for (i = 0; i < qMin(d->values.size(), 4); i++) {
            if (v.at(i).userType() == QMetaType::QColor) {
                c[i] = qvariant_cast<QColor>(v.at(i));
            } else {
                c[i] = pal.color((QPalette::ColorRole)(v.at(i).toInt()));
            }
        }
    } else {
        QList<QVariant> v;
        for (i = 0; i < qMin(d->values.size(), 4); i++) {
            ColorData color = parseColorValue(d->values.at(i));
            if (color.type == ColorData::Role) {
                v += QVariant::fromValue<int>(color.role);
                c[i] = pal.color((QPalette::ColorRole)(color.role));
            } else {
                v += QVariant::fromValue<QColor>(color.color);
                c[i] = color.color;
            }
        }
        d->parsed = v;
    }

    if (i == 0) c[0] = c[1] = c[2] = c[3] = QColor();
    else if (i == 1) c[3] = c[2] = c[1] = c[0];
    else if (i == 2) c[2] = c[0], c[3] = c[1];
    else if (i == 3) c[3] = c[1];
}

BorderStyle Declaration::styleValue() const
{
    if (d->values.size() != 1)
        return BorderStyle_None;
    return parseStyleValue(d->values.at(0));
}

void Declaration::styleValues(BorderStyle *s) const
{
    int i;
    for (i = 0; i < qMin(d->values.size(), 4); i++)
        s[i] = parseStyleValue(d->values.at(i));
    if (i == 0) s[0] = s[1] = s[2] = s[3] = BorderStyle_None;
    else if (i == 1) s[3] = s[2] = s[1] = s[0];
    else if (i == 2) s[2] = s[0], s[3] = s[1];
    else if (i == 3) s[3] = s[1];
}

Repeat Declaration::repeatValue() const
{
    if (d->parsed.isValid())
        return static_cast<Repeat>(d->parsed.toInt());
    if (d->values.size() != 1)
        return Repeat_Unknown;
    int v = findKnownValue(d->values.at(0).variant.toString(),
                   repeats, NumKnownRepeats);
    d->parsed = v;
    return static_cast<Repeat>(v);
}

Origin Declaration::originValue() const
{
    if (d->parsed.isValid())
        return static_cast<Origin>(d->parsed.toInt());
    if (d->values.size() != 1)
        return Origin_Unknown;
    int v = findKnownValue(d->values.at(0).variant.toString(),
                               origins, NumKnownOrigins);
    d->parsed = v;
    return static_cast<Origin>(v);
}

PositionMode Declaration::positionValue() const
{
    if (d->parsed.isValid())
        return static_cast<PositionMode>(d->parsed.toInt());
    if (d->values.size() != 1)
        return PositionMode_Unknown;
    int v = findKnownValue(d->values.at(0).variant.toString(),
                           positions, NumKnownPositionModes);
    d->parsed = v;
    return static_cast<PositionMode>(v);
}

Attachment Declaration::attachmentValue() const
{
    if (d->parsed.isValid())
        return static_cast<Attachment>(d->parsed.toInt());
    if (d->values.size() != 1)
        return Attachment_Unknown;
    int v = findKnownValue(d->values.at(0).variant.toString(),
                           attachments, NumKnownAttachments);
    d->parsed = v;
    return static_cast<Attachment>(v);
}

int Declaration::styleFeaturesValue() const
{
    Q_ASSERT(d->propertyId == QtStyleFeatures);
    if (d->parsed.isValid())
        return d->parsed.toInt();
    int features = StyleFeature_None;
    for (int i = 0; i < d->values.size(); i++) {
        features |= static_cast<int>(findKnownValue(d->values.value(i).variant.toString(),
                                     styleFeatures, NumKnownStyleFeatures));
    }
    d->parsed = features;
    return features;
}

QString Declaration::uriValue() const
{
    if (d->values.isEmpty() || d->values.at(0).type != Value::Uri)
        return QString();
    return d->values.at(0).variant.toString();
}

Qt::Alignment Declaration::alignmentValue() const
{
    if (d->parsed.isValid())
        return Qt::Alignment(d->parsed.toInt());
    if (d->values.isEmpty() || d->values.size() > 2)
        return Qt::AlignLeft | Qt::AlignTop;

    Qt::Alignment v = parseAlignment(d->values.constData(), d->values.size());
    d->parsed = int(v);
    return v;
}

void Declaration::borderImageValue(QString *image, int *cuts,
                                   TileMode *h, TileMode *v) const
{
    const DeclarationData *d = this->d.data(); // make it const and shadow d
    *image = uriValue();
    for (int i = 0; i < 4; i++)
        cuts[i] = -1;
    *h = *v = TileMode_Stretch;

    if (d->values.size() < 2)
        return;

    if (d->values.at(1).type == Value::Number) { // cuts!
        int i;
        for (i = 0; i < qMin(d->values.size()-1, 4); i++) {
            const Value& v = d->values.at(i+1);
            if (v.type != Value::Number)
                break;
            cuts[i] = v.variant.toString().toInt();
            if (cuts[i] < 0) {
                qWarning("Declaration::borderImageValue: Invalid cut value %d at position %d",
                         cuts[i], i);
                cuts[0] = cuts[1] = cuts[2] = cuts[3] = -1;
                i = 4;
                break;
            }
        }
        if (i == 0) cuts[0] = cuts[1] = cuts[2] = cuts[3] = 0;
        else if (i == 1) cuts[3] = cuts[2] = cuts[1] = cuts[0];
        else if (i == 2) cuts[2] = cuts[0], cuts[3] = cuts[1];
        else if (i == 3) cuts[3] = cuts[1];
    }

    if (d->values.last().type == Value::Identifier) {
        *v = static_cast<TileMode>(findKnownValue(d->values.last().variant.toString(),
                                      tileModes, NumKnownTileModes));
    }
    if (d->values[d->values.size() - 2].type == Value::Identifier) {
        *h = static_cast<TileMode>
                (findKnownValue(d->values[d->values.size()-2].variant.toString(),
                                        tileModes, NumKnownTileModes));
    } else
        *h = *v;
}

bool Declaration::borderCollapseValue() const
{
    if (d->values.size() != 1)
        return false;
    else
        return d->values.at(0).toString() == "collapse"_L1;
}

QList<qreal> Declaration::dashArray() const
{
    if (d->propertyId != Property::QtStrokeDashArray || d->values.empty())
        return QList<qreal>();

    bool isValid = true;
    QList<qreal> dashes;
    for (int i = 0; i < d->values.size(); i++) {
        Value v = d->values[i];
        // Separators must be at odd indices and Numbers at even indices.
        bool isValidSeparator = (i & 1) && v.type == Value::TermOperatorComma;
        bool isValidNumber = !(i & 1) && v.type == Value::Number;
        if (!isValidNumber && !isValidSeparator) {
            isValid = false;
            break;
        } else if (isValidNumber) {
            bool ok;
            dashes.append(v.variant.toReal(&ok));
            if (!ok) {
                isValid = false;
                break;
            }
        }
    }

    isValid &= !(dashes.size() & 1);
    return isValid ? dashes : QList<qreal>();
}

QIcon Declaration::iconValue() const
{
    if (d->parsed.isValid())
        return qvariant_cast<QIcon>(d->parsed);

    QIcon icon;
    for (int i = 0; i < d->values.size();) {
        const Value &value = d->values.at(i++);
        if (value.type != Value::Uri)
            break;
        QString uri = value.variant.toString();
        QIcon::Mode mode = QIcon::Normal;
        QIcon::State state = QIcon::Off;
        for (int j = 0; j < 2; j++) {
            if (i != d->values.size() && d->values.at(i).type == Value::KnownIdentifier) {
                switch (d->values.at(i).variant.toInt()) {
                case Value_Disabled: mode = QIcon::Disabled; break;
                case Value_Active: mode = QIcon::Active; break;
                case Value_Selected: mode = QIcon::Selected; break;
                case Value_Normal: mode = QIcon::Normal; break;
                case Value_On: state = QIcon::On; break;
                case Value_Off: state = QIcon::Off; break;
                default: break;
                }
                ++i;
            } else {
                break;
            }
        }

        // QIcon is soo broken
        if (icon.isNull())
            icon = QIcon(uri);
        else
            icon.addPixmap(uri, mode, state);

        if (i == d->values.size())
            break;

        if (d->values.at(i).type == Value::TermOperatorComma)
            i++;
    }

    d->parsed = QVariant::fromValue<QIcon>(icon);
    return icon;
}

///////////////////////////////////////////////////////////////////////////////
// Selector
int Selector::specificity() const
{
    int val = 0;
    for (int i = 0; i < basicSelectors.size(); ++i) {
        const BasicSelector &sel = basicSelectors.at(i);
        if (!sel.elementName.isEmpty())
            val += 1;

        val += (sel.pseudos.size() + sel.attributeSelectors.size()) * 0x10;
        val += sel.ids.size() * 0x100;
    }
    return val;
}

QString Selector::pseudoElement() const
{
    const BasicSelector& bs = basicSelectors.last();
    if (!bs.pseudos.isEmpty() && bs.pseudos.at(0).type == PseudoClass_Unknown)
        return bs.pseudos.at(0).name;
    return QString();
}

quint64 Selector::pseudoClass(quint64 *negated) const
{
    const BasicSelector& bs = basicSelectors.last();
    if (bs.pseudos.isEmpty())
        return PseudoClass_Unspecified;
    quint64 pc = PseudoClass_Unknown;
    for (int i = !pseudoElement().isEmpty(); i < bs.pseudos.size(); i++) {
        const Pseudo &pseudo = bs.pseudos.at(i);
        if (pseudo.type == PseudoClass_Unknown)
            return PseudoClass_Unknown;
        if (!pseudo.negated)
            pc |= pseudo.type;
        else if (negated)
            *negated |= pseudo.type;
    }
    return pc;
}

///////////////////////////////////////////////////////////////////////////////
// StyleSheet
void StyleSheet::buildIndexes(Qt::CaseSensitivity nameCaseSensitivity)
{
    QList<StyleRule> universals;
    for (int i = 0; i < styleRules.size(); ++i) {
        const StyleRule &rule = styleRules.at(i);
        QList<Selector> universalsSelectors;
        for (int j = 0; j < rule.selectors.size(); ++j) {
            const Selector& selector = rule.selectors.at(j);

            if (selector.basicSelectors.isEmpty())
                continue;

            if (selector.basicSelectors.at(0).relationToNext == BasicSelector::NoRelation) {
                if (selector.basicSelectors.size() != 1)
                    continue;
            } else if (selector.basicSelectors.size() <= 1) {
                continue;
            }

            const BasicSelector &sel = selector.basicSelectors.at(selector.basicSelectors.size() - 1);

            if (!sel.ids.isEmpty()) {
                StyleRule nr;
                nr.selectors += selector;
                nr.declarations = rule.declarations;
                nr.order = i;
                idIndex.insert(sel.ids.at(0), nr);
            } else if (!sel.elementName.isEmpty()) {
                StyleRule nr;
                nr.selectors += selector;
                nr.declarations = rule.declarations;
                nr.order = i;
                QString name = sel.elementName;
                if (nameCaseSensitivity == Qt::CaseInsensitive)
                    name = std::move(name).toLower();
                nameIndex.insert(name, nr);
            } else {
                universalsSelectors += selector;
            }
        }
        if (!universalsSelectors.isEmpty()) {
            StyleRule nr;
            nr.selectors = universalsSelectors;
            nr.declarations = rule.declarations;
            nr.order = i;
            universals << nr;
        }
    }
    styleRules = universals;
}

///////////////////////////////////////////////////////////////////////////////
// StyleSelector
StyleSelector::~StyleSelector()
{
}

bool StyleSelector::nodeNameEquals(NodePtr node, const QString& nodeName) const
{
    return nodeNames(node).contains(nodeName, nameCaseSensitivity);
}

QStringList StyleSelector::nodeIds(NodePtr node) const
{
    return QStringList(attributeValue(node, QCss::AttributeSelector{"id"_L1, {}, AttributeSelector::NoMatch}));
}

bool StyleSelector::selectorMatches(const Selector &selector, NodePtr node)
{
    if (selector.basicSelectors.isEmpty())
        return false;

    if (selector.basicSelectors.at(0).relationToNext == BasicSelector::NoRelation) {
        if (selector.basicSelectors.size() != 1)
            return false;
        return basicSelectorMatches(selector.basicSelectors.at(0), node);
    }
    if (selector.basicSelectors.size() <= 1)
        return false;

    int i = selector.basicSelectors.size() - 1;
    node = duplicateNode(node);
    bool match = true;

    BasicSelector sel = selector.basicSelectors.at(i);
    do {
        match = basicSelectorMatches(sel, node);
        if (!match) {
            if (i == selector.basicSelectors.size() - 1) // first element must always match!
                break;
            if (sel.relationToNext != BasicSelector::MatchNextSelectorIfAncestor &&
                sel.relationToNext != BasicSelector::MatchNextSelectorIfIndirectAdjecent)
                break;
        }

        if (match || (sel.relationToNext != BasicSelector::MatchNextSelectorIfAncestor &&
                      sel.relationToNext != BasicSelector::MatchNextSelectorIfIndirectAdjecent))
            --i;

        if (i < 0)
            break;

        sel = selector.basicSelectors.at(i);
        if (sel.relationToNext == BasicSelector::MatchNextSelectorIfAncestor
            || sel.relationToNext == BasicSelector::MatchNextSelectorIfParent) {

            NodePtr nextParent = parentNode(node);
            freeNode(node);
            node = nextParent;
        } else if (sel.relationToNext == BasicSelector::MatchNextSelectorIfDirectAdjecent
                  || sel.relationToNext == BasicSelector::MatchNextSelectorIfIndirectAdjecent) {
            NodePtr previousSibling = previousSiblingNode(node);
            freeNode(node);
            node = previousSibling;
        }
        if (isNullNode(node)) {
            match = false;
            break;
        }
   } while (i >= 0 && (match || sel.relationToNext == BasicSelector::MatchNextSelectorIfAncestor
                             || sel.relationToNext == BasicSelector::MatchNextSelectorIfIndirectAdjecent));

    freeNode(node);

    return match;
}

bool StyleSelector::basicSelectorMatches(const BasicSelector &sel, NodePtr node)
{
    if (!sel.attributeSelectors.isEmpty()) {
        if (!hasAttributes(node))
            return false;

        for (int i = 0; i < sel.attributeSelectors.size(); ++i) {
            const QCss::AttributeSelector &a = sel.attributeSelectors.at(i);

            const QString attrValue = attributeValue(node, a);
            if (attrValue.isNull())
                return false;

            switch (a.valueMatchCriterium) {
            case QCss::AttributeSelector::NoMatch:
                break;
            case QCss::AttributeSelector::MatchEqual:
                if (attrValue != a.value)
                    return false;
                break;
            case QCss::AttributeSelector::MatchIncludes: {
                const auto lst = QStringView{attrValue}.tokenize(u' ');
                bool found = false;
                for (auto s : lst) {
                    if (s == a.value) {
                        found = true;
                        break;
                    }
                }
                if (!found)
                    return false;
                break;
            }
            case QCss::AttributeSelector::MatchDashMatch: {
                const QString dashPrefix = a.value + u'-';
                if (attrValue != a.value && !attrValue.startsWith(dashPrefix))
                    return false;
                break;
            }
            case QCss::AttributeSelector::MatchBeginsWith:
                if (!attrValue.startsWith(a.value))
                    return false;
                break;
            case QCss::AttributeSelector::MatchEndsWith:
                if (!attrValue.endsWith(a.value))
                    return false;
                break;
            case QCss::AttributeSelector::MatchContains:
                if (!attrValue.contains(a.value))
                    return false;
                break;
            }
        }
    }

    if (!sel.elementName.isEmpty()
        && !nodeNameEquals(node, sel.elementName))
            return false;

    if (!sel.ids.isEmpty()
        && sel.ids != nodeIds(node))
            return false;

    return true;
}

void StyleSelector::matchRule(NodePtr node, const StyleRule &rule, StyleSheetOrigin origin,
                               int depth, QMultiMap<uint, StyleRule> *weightedRules)
{
    for (int j = 0; j < rule.selectors.size(); ++j) {
        const Selector& selector = rule.selectors.at(j);
        if (selectorMatches(selector, node)) {
            uint weight = rule.order
                        + selector.specificity() *0x100
                        + (uint(origin) + depth)*0x100000;
            StyleRule newRule = rule;
            if (rule.selectors.size() > 1) {
                newRule.selectors.resize(1);
                newRule.selectors[0] = selector;
            }
            //We might have rules with the same weight if they came from a rule with several selectors
            weightedRules->insert(weight, newRule);
        }
    }
}

// Returns style rules that are in ascending order of specificity
// Each of the StyleRule returned will contain exactly one Selector
QList<StyleRule> StyleSelector::styleRulesForNode(NodePtr node)
{
    QList<StyleRule> rules;
    if (styleSheets.isEmpty())
        return rules;

    QMultiMap<uint, StyleRule> weightedRules; // (spec, rule) that will be sorted below

    //prune using indexed stylesheet
    for (int sheetIdx = 0; sheetIdx < styleSheets.size(); ++sheetIdx) {
        const StyleSheet &styleSheet = styleSheets.at(sheetIdx);
        for (int i = 0; i < styleSheet.styleRules.size(); ++i) {
            matchRule(node, styleSheet.styleRules.at(i), styleSheet.origin, styleSheet.depth, &weightedRules);
        }

        if (!styleSheet.idIndex.isEmpty()) {
            QStringList ids = nodeIds(node);
            for (int i = 0; i < ids.size(); i++) {
                const QString &key = ids.at(i);
                QMultiHash<QString, StyleRule>::const_iterator it = styleSheet.idIndex.constFind(key);
                while (it != styleSheet.idIndex.constEnd() && it.key() == key) {
                    matchRule(node, it.value(), styleSheet.origin, styleSheet.depth, &weightedRules);
                    ++it;
                }
            }
        }
        if (!styleSheet.nameIndex.isEmpty()) {
            QStringList names = nodeNames(node);
            for (int i = 0; i < names.size(); i++) {
                QString name = names.at(i);
                if (nameCaseSensitivity == Qt::CaseInsensitive)
                    name = std::move(name).toLower();
                QMultiHash<QString, StyleRule>::const_iterator it = styleSheet.nameIndex.constFind(name);
                while (it != styleSheet.nameIndex.constEnd() && it.key() == name) {
                    matchRule(node, it.value(), styleSheet.origin, styleSheet.depth, &weightedRules);
                    ++it;
                }
            }
        }
        if (!medium.isEmpty()) {
            for (int i = 0; i < styleSheet.mediaRules.size(); ++i) {
                if (styleSheet.mediaRules.at(i).media.contains(medium, Qt::CaseInsensitive)) {
                    for (int j = 0; j < styleSheet.mediaRules.at(i).styleRules.size(); ++j) {
                        matchRule(node, styleSheet.mediaRules.at(i).styleRules.at(j), styleSheet.origin,
                               styleSheet.depth, &weightedRules);
                    }
                }
            }
        }
    }

    rules.reserve(weightedRules.size());
    QMultiMap<uint, StyleRule>::const_iterator it = weightedRules.constBegin();
    for ( ; it != weightedRules.constEnd() ; ++it)
        rules += *it;

    return rules;
}

// for qtexthtmlparser which requires just the declarations with Enabled state
// and without pseudo elements
QList<Declaration> StyleSelector::declarationsForNode(NodePtr node, const char *extraPseudo)
{
    QList<Declaration> decls;
    QList<StyleRule> rules = styleRulesForNode(node);
    for (int i = 0; i < rules.size(); i++) {
        const Selector& selector = rules.at(i).selectors.at(0);
        const QString pseudoElement = selector.pseudoElement();

        if (extraPseudo && pseudoElement == QLatin1StringView(extraPseudo)) {
            decls += rules.at(i).declarations;
            continue;
        }

        if (!pseudoElement.isEmpty()) // skip rules with pseudo elements
            continue;
        quint64 pseudoClass = selector.pseudoClass();
        if (pseudoClass == PseudoClass_Enabled || pseudoClass == PseudoClass_Unspecified)
            decls += rules.at(i).declarations;
    }
    return decls;
}

static inline bool isHexDigit(const char c)
{
    return (c >= '0' && c <= '9')
           || (c >= 'a' && c <= 'f')
           || (c >= 'A' && c <= 'F')
           ;
}

QString Scanner::preprocess(const QString &input, bool *hasEscapeSequences)
{
    QString output = input;

    if (hasEscapeSequences)
        *hasEscapeSequences = false;

    int i = 0;
    while (i < output.size()) {
        if (output.at(i) == u'\\') {

            ++i;
            // test for unicode hex escape
            int hexCount = 0;
            const int hexStart = i;
            while (i < output.size()
                   && isHexDigit(output.at(i).toLatin1())
                   && hexCount < 7) {
                ++hexCount;
                ++i;
            }
            if (hexCount == 0) {
                if (hasEscapeSequences)
                    *hasEscapeSequences = true;
                continue;
            }

            hexCount = qMin(hexCount, 6);
            bool ok = false;
            const char16_t code = QStringView{output}.mid(hexStart, hexCount).toUShort(&ok, 16);
            if (ok) {
                output.replace(hexStart - 1, hexCount + 1, code);
                i = hexStart;
            } else {
                i = hexStart;
            }
        } else {
            ++i;
        }
    }
    return output;
}

int QCssScanner_Generated::handleCommentStart()
{
    while (pos < input.size() - 1) {
        if (input.at(pos) == u'*' && input.at(pos + 1) == u'/') {
            pos += 2;
            break;
        }
        ++pos;
    }
    return S;
}

void Scanner::scan(const QString &preprocessedInput, QList<Symbol> *symbols)
{
    QCssScanner_Generated scanner(preprocessedInput);
    Symbol sym;
    int tok = scanner.lex();
    while (tok != -1) {
        sym.token = static_cast<QCss::TokenType>(tok);
        sym.text = scanner.input;
        sym.start = scanner.lexemStart;
        sym.len = scanner.lexemLength;
        symbols->append(sym);
        tok = scanner.lex();
    }
}

QString Symbol::lexem() const
{
    QString result;
    if (len > 0)
        result.reserve(len);
    for (int i = 0; i < len; ++i) {
        if (text.at(start + i) == u'\\' && i < len - 1)
            ++i;
        result += text.at(start + i);
    }
    return result;
}

Parser::Parser(const QString &css, bool isFile)
{
    init(css, isFile);
}

Parser::Parser()
{
    index = 0;
    errorIndex = -1;
    hasEscapeSequences = false;
}

void Parser::init(const QString &css, bool isFile)
{
    QString styleSheet = css;
    if (isFile) {
        QFile file(css);
        if (file.open(QFile::ReadOnly)) {
            sourcePath = QFileInfo(styleSheet).absolutePath() + u'/';
            QTextStream stream(&file);
            styleSheet = stream.readAll();
        } else {
            qWarning() << "QCss::Parser - Failed to load file " << css;
            styleSheet.clear();
        }
    } else {
        sourcePath.clear();
    }

    hasEscapeSequences = false;
    symbols.clear();
    symbols.reserve(8);
    Scanner::scan(Scanner::preprocess(styleSheet, &hasEscapeSequences), &symbols);
    index = 0;
    errorIndex = -1;
}

bool Parser::parse(StyleSheet *styleSheet, Qt::CaseSensitivity nameCaseSensitivity)
{
    if (testTokenAndEndsWith(ATKEYWORD_SYM, "charset"_L1)) {
        while (test(S) || test(CDO) || test(CDC)) {}
        if (!next(STRING)) return false;
        if (!next(SEMICOLON)) return false;
    }

    while (test(S) || test(CDO) || test(CDC)) {}

    while (testImport()) {
        ImportRule rule;
        if (!parseImport(&rule)) return false;
        styleSheet->importRules.append(rule);
        while (test(S) || test(CDO) || test(CDC)) {}
    }

    do {
        if (testMedia()) {
            MediaRule rule;
            if (!parseMedia(&rule)) return false;
            styleSheet->mediaRules.append(rule);
        } else if (testPage()) {
            PageRule rule;
            if (!parsePage(&rule)) return false;
            styleSheet->pageRules.append(rule);
        } else if (testAnimation()) {
            AnimationRule rule;
            if (!parseAnimation(&rule)) return false;
            styleSheet->animationRules.append(rule);
        } else if (testRuleset()) {
            StyleRule rule;
            if (!parseRuleset(&rule)) return false;
            styleSheet->styleRules.append(rule);
        } else if (test(ATKEYWORD_SYM)) {
            if (!until(RBRACE)) return false;
        } else if (hasNext()) {
            return false;
        }
        while (test(S) || test(CDO) || test(CDC)) {}
    } while (hasNext());
    styleSheet->buildIndexes(nameCaseSensitivity);
    return true;
}

Symbol Parser::errorSymbol()
{
    if (errorIndex == -1) return Symbol();
    return symbols.at(errorIndex);
}

static inline void removeOptionalQuotes(QString *str)
{
    if (!str->startsWith(u'\'') && !str->startsWith(u'\"'))
        return;
    str->remove(0, 1);
    str->chop(1);
}

bool Parser::parseImport(ImportRule *importRule)
{
    skipSpace();

    if (test(STRING)) {
        importRule->href = lexem();
    } else {
        if (!testAndParseUri(&importRule->href)) return false;
    }
    removeOptionalQuotes(&importRule->href);

    skipSpace();

    if (testMedium()) {
        if (!parseMedium(&importRule->media)) return false;

        while (test(COMMA)) {
            skipSpace();
            if (!parseNextMedium(&importRule->media)) return false;
        }
    }

    if (!next(SEMICOLON)) return false;

    skipSpace();
    return true;
}

bool Parser::parseMedia(MediaRule *mediaRule)
{
    do {
        skipSpace();
        if (!parseNextMedium(&mediaRule->media)) return false;
    } while (test(COMMA));

    if (!next(LBRACE)) return false;
    skipSpace();

    while (testRuleset()) {
        StyleRule rule;
        if (!parseRuleset(&rule)) return false;
        mediaRule->styleRules.append(rule);
    }

    if (!next(RBRACE)) return false;
    skipSpace();
    return true;
}

bool Parser::parseMedium(QStringList *media)
{
    media->append(lexem());
    skipSpace();
    return true;
}

bool Parser::parsePage(PageRule *pageRule)
{
    skipSpace();

    if (testPseudoPage())
        if (!parsePseudoPage(&pageRule->selector)) return false;

    skipSpace();
    if (!next(LBRACE)) return false;

    do {
        skipSpace();
        Declaration decl;
        if (!parseNextDeclaration(&decl)) return false;
        if (!decl.isEmpty())
            pageRule->declarations.append(decl);
    } while (test(SEMICOLON));

    if (!next(RBRACE)) return false;
    skipSpace();
    return true;
}

bool Parser::parsePseudoPage(QString *selector)
{
    if (!next(IDENT)) return false;
    *selector = lexem();
    return true;
}

bool Parser::parseNextOperator(Value *value)
{
    if (!hasNext()) return true;
    switch (next()) {
        case SLASH: value->type = Value::TermOperatorSlash; skipSpace(); break;
        case COMMA: value->type = Value::TermOperatorComma; skipSpace(); break;
        default: prev(); break;
    }
    return true;
}

bool Parser::parseAnimation(AnimationRule *animationRule)
{
    skipSpace();
    if (!test(IDENT)) return false;

    animationRule->animName = lexem();

    if (!next(LBRACE)) return false;
    skipSpace();

    while (test(PERCENTAGE) || test(IDENT)) {
        AnimationRule::AnimationRuleSet set;
        if (lookup() == PERCENTAGE) {
            QString name = lexem();
            name.removeLast();
            float keyFrame = name.toFloat() / 100;
            set.keyFrame = keyFrame;
        } else if (lookup() == IDENT) {
            QString name;
            if (parseElementName(&name)) {
                if (name == QStringLiteral("from"))
                    set.keyFrame = 0;
                else if (name == QStringLiteral("to"))
                    set.keyFrame = 1;
            }
        }

        skipSpace();
        if (!next(LBRACE)) return false;
        const int declarationStart = index;

        do {
            skipSpace();
            Declaration decl;
            const int rewind = index;
            if (!parseNextDeclaration(&decl)) {
                index = rewind;
                const bool foundSemicolon = until(SEMICOLON);
                const int semicolonIndex = index;

                index = declarationStart;
                const bool foundRBrace = until(RBRACE);

                if (foundSemicolon && semicolonIndex < index) {
                    decl = Declaration();
                    index = semicolonIndex - 1;
                } else {
                    skipSpace();
                    return foundRBrace;
                }
            }
            if (!decl.isEmpty())
                set.declarations.append(decl);
        } while (test(SEMICOLON));

        if (!next(RBRACE)) return false;
        skipSpace();
        animationRule->ruleSets.append(set);
    }

    if (!next(RBRACE)) return false;
    skipSpace();

    return true;
}

bool Parser::parseCombinator(BasicSelector::Relation *relation)
{
    *relation = BasicSelector::NoRelation;
    if (lookup() == S) {
        *relation = BasicSelector::MatchNextSelectorIfAncestor;
        skipSpace();
    } else {
        prev();
    }
    if (test(PLUS)) {
        *relation = BasicSelector::MatchNextSelectorIfDirectAdjecent;
    } else if (test(GREATER)) {
        *relation = BasicSelector::MatchNextSelectorIfParent;
    } else if (test(TILDE)) {
        *relation = BasicSelector::MatchNextSelectorIfIndirectAdjecent;
    }
    skipSpace();
    return true;
}

bool Parser::parseProperty(Declaration *decl)
{
    decl->d->property = lexem();
    decl->d->propertyId = static_cast<Property>(findKnownValue(decl->d->property, properties, NumProperties));
    decl->d->inheritable = isInheritable(decl->d->propertyId);
    skipSpace();
    return true;
}

bool Parser::parseRuleset(StyleRule *styleRule)
{
    Selector sel;
    if (!parseSelector(&sel)) return false;
    styleRule->selectors.append(sel);

    while (test(COMMA)) {
        skipSpace();
        Selector sel;
        if (!parseNextSelector(&sel)) return false;
        styleRule->selectors.append(sel);
    }

    skipSpace();
    if (!next(LBRACE)) return false;
    const int declarationStart = index;

    do {
        skipSpace();
        Declaration decl;
        const int rewind = index;
        if (!parseNextDeclaration(&decl)) {
            index = rewind;
            const bool foundSemicolon = until(SEMICOLON);
            const int semicolonIndex = index;

            index = declarationStart;
            const bool foundRBrace = until(RBRACE);

            if (foundSemicolon && semicolonIndex < index) {
                decl = Declaration();
                index = semicolonIndex - 1;
            } else {
                skipSpace();
                return foundRBrace;
            }
        }
        if (!decl.isEmpty())
            styleRule->declarations.append(decl);
    } while (test(SEMICOLON));

    if (!next(RBRACE)) return false;
    skipSpace();
    return true;
}

bool Parser::parseSelector(Selector *sel)
{
    BasicSelector basicSel;
    if (!parseSimpleSelector(&basicSel)) return false;
    while (testCombinator()) {
        if (!parseCombinator(&basicSel.relationToNext)) return false;

        if (!testSimpleSelector()) break;
        sel->basicSelectors.append(basicSel);

        basicSel = BasicSelector();
        if (!parseSimpleSelector(&basicSel)) return false;
    }
    sel->basicSelectors.append(basicSel);
    return true;
}

bool Parser::parseSimpleSelector(BasicSelector *basicSel)
{
    int minCount = 0;
    if (lookupElementName()) {
        if (!parseElementName(&basicSel->elementName)) return false;
    } else {
        prev();
        minCount = 1;
    }
    bool onceMore;
    int count = 0;
    do {
        onceMore = false;
        if (test(HASH)) {
            QString theid = lexem();
            // chop off leading #
            theid.remove(0, 1);
            basicSel->ids.append(theid);
            onceMore = true;
        } else if (testClass()) {
            onceMore = true;
            AttributeSelector a;
            a.name = "class"_L1;
            a.valueMatchCriterium = AttributeSelector::MatchIncludes;
            if (!parseClass(&a.value)) return false;
            basicSel->attributeSelectors.append(a);
        } else if (testAttrib()) {
            onceMore = true;
            AttributeSelector a;
            if (!parseAttrib(&a)) return false;
            basicSel->attributeSelectors.append(a);
        } else if (testPseudo()) {
            onceMore = true;
            Pseudo ps;
            if (!parsePseudo(&ps)) return false;
            basicSel->pseudos.append(ps);
        }
        if (onceMore) ++count;
    } while (onceMore);
    return count >= minCount;
}

bool Parser::parseClass(QString *name)
{
    if (!next(IDENT)) return false;
    *name = lexem();
    return true;
}

bool Parser::parseElementName(QString *name)
{
    switch (lookup()) {
        case STAR: name->clear(); break;
        case IDENT: *name = lexem(); break;
        default: return false;
    }
    return true;
}

bool Parser::parseAttrib(AttributeSelector *attr)
{
    skipSpace();
    if (!next(IDENT)) return false;
    attr->name = lexem();
    skipSpace();

    if (test(EQUAL)) {
        attr->valueMatchCriterium = AttributeSelector::MatchEqual;
    } else if (test(INCLUDES)) {
        attr->valueMatchCriterium = AttributeSelector::MatchIncludes;
    } else if (test(DASHMATCH)) {
        attr->valueMatchCriterium = AttributeSelector::MatchDashMatch;
    } else if (test(BEGINSWITH)) {
        attr->valueMatchCriterium = AttributeSelector::MatchBeginsWith;
    } else if (test(ENDSWITH)) {
        attr->valueMatchCriterium = AttributeSelector::MatchEndsWith;
    } else if (test(CONTAINS)) {
        attr->valueMatchCriterium = AttributeSelector::MatchContains;
    } else {
        return next(RBRACKET);
    }

    skipSpace();

    if (!test(IDENT) && !test(STRING)) return false;
    attr->value = unquotedLexem();

    skipSpace();
    return next(RBRACKET);
}

bool Parser::parsePseudo(Pseudo *pseudo)
{
    (void)test(COLON);
    pseudo->negated = test(EXCLAMATION_SYM);
    if (test(IDENT)) {
        pseudo->name = lexem();
        pseudo->type = static_cast<quint64>(findKnownValue(pseudo->name, pseudos, NumPseudos));
        return true;
    }
    if (!next(FUNCTION)) return false;
    pseudo->function = lexem();
    // chop off trailing parenthesis
    pseudo->function.chop(1);
    skipSpace();
    if (!test(IDENT)) return false;
    pseudo->name = lexem();
    skipSpace();
    return next(RPAREN);
}

bool Parser::parseNextDeclaration(Declaration *decl)
{
    if (!testProperty())
        return true; // not an error!
    if (!parseProperty(decl)) return false;
    if (!next(COLON)) return false;
    skipSpace();
    if (!parseNextExpr(&decl->d->values)) return false;
    if (testPrio())
        if (!parsePrio(decl)) return false;
    return true;
}

bool Parser::testPrio()
{
    const int rewind = index;
    if (!test(EXCLAMATION_SYM)) return false;
    skipSpace();
    if (!test(IDENT)) {
        index = rewind;
        return false;
    }
    if (lexem().compare("important"_L1, Qt::CaseInsensitive) != 0) {
        index = rewind;
        return false;
    }
    return true;
}

bool Parser::parsePrio(Declaration *declaration)
{
    declaration->d->important = true;
    skipSpace();
    return true;
}

bool Parser::parseExpr(QList<Value> *values)
{
    Value val;
    if (!parseTerm(&val)) return false;
    values->append(val);
    bool onceMore;
    do {
        onceMore = false;
        val = Value();
        if (!parseNextOperator(&val)) return false;
        if (val.type != QCss::Value::Unknown)
            values->append(val);
        if (testTerm()) {
            onceMore = true;
            val = Value();
            if (!parseTerm(&val)) return false;
            values->append(val);
        }
    } while (onceMore);
    return true;
}

bool Parser::testTerm()
{
    return test(PLUS) || test(MINUS)
           || test(NUMBER)
           || test(PERCENTAGE)
           || test(LENGTH)
           || test(STRING)
           || test(IDENT)
           || testHexColor()
           || testFunction();
}

bool Parser::parseTerm(Value *value)
{
    QString str = lexem();
    bool haveUnary = false;
    if (lookup() == PLUS || lookup() == MINUS) {
        haveUnary = true;
        if (!hasNext()) return false;
        next();
        str += lexem();
    }

    value->variant = str;
    value->type = QCss::Value::String;
    switch (lookup()) {
        case NUMBER:
            value->type = Value::Number;
            value->variant.convert(QMetaType::fromType<double>());
            break;
        case PERCENTAGE:
            value->type = Value::Percentage;
            str.chop(1); // strip off %
            value->variant = str;
            break;
        case LENGTH:
            value->type = Value::Length;
            break;

        case STRING:
            if (haveUnary) return false;
            value->type = Value::String;
            str.chop(1);
            str.remove(0, 1);
            value->variant = str;
            break;
        case IDENT: {
            if (haveUnary) return false;
            value->type = Value::Identifier;
            const int theid = findKnownValue(str, values, NumKnownValues);
            if (theid != 0) {
                value->type = Value::KnownIdentifier;
                value->variant = theid;
            }
            break;
        }
        default: {
            if (haveUnary) return false;
            prev();
            if (testHexColor()) {
                QColor col;
                if (!parseHexColor(&col)) return false;
                value->type = Value::Color;
                value->variant = col;
            } else if (testFunction()) {
                QString name, args;
                if (!parseFunction(&name, &args)) return false;
                if (name == "url"_L1) {
                    value->type = Value::Uri;
                    removeOptionalQuotes(&args);
                    if (QFileInfo(args).isRelative() && !sourcePath.isEmpty()) {
                        args.prepend(sourcePath);
                    }
                    value->variant = args;
                } else {
                    value->type = Value::Function;
                    value->variant = QStringList() << name << args;
                }
            } else {
                return recordError();
            }
            return true;
        }
    }
    skipSpace();
    return true;
}

bool Parser::parseFunction(QString *name, QString *args)
{
    *name = lexem();
    name->chop(1);
    // until(RPAREN) needs FUNCTION token at index-1 to work properly
    int start = index;
    skipSpace();
    std::swap(start, index);
    if (!until(RPAREN)) return false;
    for (int i = start; i < index - 1; ++i)
        args->append(symbols.at(i).lexem());
    /*
    if (!nextExpr(&arguments)) return false;
    if (!next(RPAREN)) return false;
    */
    skipSpace();
    return true;
}

bool Parser::parseHexColor(QColor *col)
{
    *col = QColor::fromString(lexem());
    if (!col->isValid()) {
        qWarning("QCssParser::parseHexColor: Unknown color name '%s'",lexem().toLatin1().constData());
        return false;
    }
    skipSpace();
    return true;
}

bool Parser::testAndParseUri(QString *uri)
{
    const int rewind = index;
    if (!testFunction()) return false;

    QString name, args;
    if (!parseFunction(&name, &args)) {
        index = rewind;
        return false;
    }
    if (name.compare("url"_L1, Qt::CaseInsensitive) != 0) {
        index = rewind;
        return false;
    }
    *uri = args;
    removeOptionalQuotes(uri);
    return true;
}

bool Parser::testSimpleSelector()
{
    return testElementName()
           || (test(HASH))
           || testClass()
           || testAttrib()
           || testPseudo();
}

bool Parser::next(QCss::TokenType t)
{
    if (hasNext() && next() == t)
        return true;
    return recordError();
}

bool Parser::test(QCss::TokenType t)
{
    if (index >= symbols.size())
        return false;
    if (symbols.at(index).token == t) {
        ++index;
        return true;
    }
    return false;
}

QString Parser::unquotedLexem() const
{
    QString s = lexem();
    if (lookup() == STRING) {
        s.chop(1);
        s.remove(0, 1);
    }
    return s;
}

QString Parser::lexemUntil(QCss::TokenType t)
{
    QString lexem;
    while (hasNext() && next() != t)
        lexem += symbol().lexem();
    return lexem;
}

bool Parser::until(QCss::TokenType target, QCss::TokenType target2)
{
    int braceCount = 0;
    int brackCount = 0;
    int parenCount = 0;
    if (index) {
        switch(symbols.at(index-1).token) {
        case LBRACE: ++braceCount; break;
        case LBRACKET: ++brackCount; break;
        case FUNCTION:
        case LPAREN: ++parenCount; break;
        default: ;
        }
    }
    while (index < symbols.size()) {
        QCss::TokenType t = symbols.at(index++).token;
        switch (t) {
        case LBRACE: ++braceCount; break;
        case RBRACE: --braceCount; break;
        case LBRACKET: ++brackCount; break;
        case RBRACKET: --brackCount; break;
        case FUNCTION:
        case LPAREN: ++parenCount; break;
        case RPAREN: --parenCount; break;
        default: break;
        }
        if ((t == target || (target2 != NONE && t == target2))
            && braceCount <= 0
            && brackCount <= 0
            && parenCount <= 0)
            return true;

        if (braceCount < 0 || brackCount < 0 || parenCount < 0) {
            --index;
            break;
        }
    }
    return false;
}

bool Parser::testTokenAndEndsWith(QCss::TokenType t, QLatin1StringView str)
{
    if (!test(t)) return false;
    if (!lexem().endsWith(str, Qt::CaseInsensitive)) {
        prev();
        return false;
    }
    return true;
}

QT_END_NAMESPACE
#endif // QT_NO_CSSPARSER
