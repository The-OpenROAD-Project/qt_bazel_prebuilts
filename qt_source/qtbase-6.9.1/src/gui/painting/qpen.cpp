// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
#include "qpen.h"
#include "qpen_p.h"
#include "qdatastream.h"
#include "qvariant.h"
#include "qbrush.h"

#include <qdebug.h>

QT_BEGIN_NAMESPACE

/*!
    \class QPen
    \inmodule QtGui
    \ingroup painting
    \ingroup shared


    \brief The QPen class defines how a QPainter should draw lines and outlines
    of shapes.

    A pen has a style(), width(), brush(), capStyle() and joinStyle().

    The pen style defines the line type. The brush is used to fill
    strokes generated with the pen. Use the QBrush class to specify
    fill styles.  The cap style determines the line end caps that can
    be drawn using QPainter, while the join style describes how joins
    between two lines are drawn. The pen width can be specified in
    both integer (width()) and floating point (widthF()) precision. A
    line width of zero indicates a cosmetic pen.  This means that the
    pen width is always drawn one pixel wide, independent of the \l
    {QPainter#Coordinate Transformations}{transformation} set on the
    painter.

    The various settings can easily be modified using the
    corresponding setStyle(), setWidth(), setBrush(), setCapStyle()
    and setJoinStyle() functions (note that the painter's pen must be
    reset when altering the pen's properties).

    For example:

    \snippet code/src_gui_painting_qpen.cpp 0

    which is equivalent to

    \snippet code/src_gui_painting_qpen.cpp 1

    The default pen is a solid black brush with 1 width, square
    cap style (Qt::SquareCap), and  bevel join style (Qt::BevelJoin).

    In addition QPen provides the color() and setColor()
    convenience functions to extract and set the color of the pen's
    brush, respectively. Pens may also be compared and streamed.

    For more information about painting in general, see the \l{Paint
    System} documentation.

    \section1 Pen Style

    Qt provides several built-in styles represented by the
    Qt::PenStyle enum:

    \table
    \row
    \li \inlineimage qpen-solid.png
    \li \inlineimage qpen-dash.png
    \li \inlineimage qpen-dot.png
    \row
    \li Qt::SolidLine
    \li Qt::DashLine
    \li Qt::DotLine
    \row
    \li \inlineimage qpen-dashdot.png
    \li \inlineimage qpen-dashdotdot.png
    \li \inlineimage qpen-custom.png
    \row
    \li Qt::DashDotLine
    \li Qt::DashDotDotLine
    \li Qt::CustomDashLine
    \endtable

    Simply use the setStyle() function to convert the pen style to
    either of the built-in styles, except the Qt::CustomDashLine style
    which we will come back to shortly. Setting the style to Qt::NoPen
    tells the painter to not draw lines or outlines. The default pen
    style is Qt::SolidLine.

    Since Qt 4.1 it is also possible to specify a custom dash pattern
    using the setDashPattern() function which implicitly converts the
    style of the pen to Qt::CustomDashLine. The pattern argument, a
    QList, must be specified as an even number of \l qreal entries
    where the entries 1, 3, 5... are the dashes and 2, 4, 6... are the
    spaces. For example, the custom pattern shown above is created
    using the following code:

    \snippet code/src_gui_painting_qpen.cpp 2

    Note that the dash pattern is specified in units of the pens
    width, e.g. a dash of length 5 in width 10 is 50 pixels long.

    The currently set dash pattern can be retrieved using the
    dashPattern() function. Use the isSolid() function to determine
    whether the pen has a solid fill, or not.

    \section1 Cap Style

    The cap style defines how the end points of lines are drawn using
    QPainter.  The cap style only apply to wide lines, i.e. when the
    width is 1 or greater. The Qt::PenCapStyle enum provides the
    following styles:

    \table
    \row
    \li \inlineimage qpen-square.png
    \li \inlineimage qpen-flat.png
    \li \inlineimage qpen-roundcap.png
    \row
    \li Qt::SquareCap
    \li Qt::FlatCap
    \li Qt::RoundCap
    \endtable

    The Qt::SquareCap style is a square line end that covers the end
    point and extends beyond it by half the line width. The
    Qt::FlatCap style is a square line end that does not cover the end
    point of the line. And the Qt::RoundCap style is a rounded line
    end covering the end point.

    The default is Qt::SquareCap.

    Whether or not end points are drawn when the pen width is 0 or 1
    depends on the cap style. Using Qt::SquareCap or Qt::RoundCap they
    are drawn, using Qt::FlatCap they are not drawn.

    \section1 Join Style

    The join style defines how joins between two connected lines can
    be drawn using QPainter. The join style only apply to wide lines,
    i.e. when the width is 1 or greater. The Qt::PenJoinStyle enum
    provides the following styles:

    \table
    \row
    \li \inlineimage qpen-bevel.png
    \li \inlineimage qpen-miter.png
    \li \inlineimage qpen-roundjoin.png
    \row
    \li Qt::BevelJoin
    \li Qt::MiterJoin
    \li Qt::RoundJoin
    \endtable

    The Qt::BevelJoin style fills the triangular notch between the two
    lines. The Qt::MiterJoin style extends the lines to meet at an
    angle. And the Qt::RoundJoin style fills a circular arc between
    the two lines.

    The default is Qt::BevelJoin.

    \image qpen-miterlimit.png

    When the Qt::MiterJoin style is applied, it is possible to use the
    setMiterLimit() function to specify how far the miter join can
    extend from the join point. The miterLimit() is used to reduce
    artifacts between line joins where the lines are close to
    parallel.

    The miterLimit() must be specified in units of the pens width,
    e.g. a miter limit of 5 in width 10 is 50 pixels long. The
    default miter limit is 2, i.e. twice the pen width in pixels.

    \table 100%
    \row
    \li \inlineimage qpen-demo.png
    \li \b {\l {painting/pathstroke}{The Path Stroking Example}}

    The Path Stroking example shows Qt's built-in dash patterns and shows
    how custom patterns can be used to extend the range of available
    patterns.
    \endtable

    \sa QPainter, QBrush, {painting/pathstroke}{Path Stroking Example},
        {Scribble Example}
*/

/*!
  \internal
*/
QPenPrivate::QPenPrivate(const QBrush &_brush, qreal _width, Qt::PenStyle penStyle,
                         Qt::PenCapStyle _capStyle, Qt::PenJoinStyle _joinStyle)
    : dashOffset(0), miterLimit(2),
      cosmetic(false)
{
    width = _width;
    brush = _brush;
    style = penStyle;
    capStyle = _capStyle;
    joinStyle = _joinStyle;
}

static constexpr Qt::PenCapStyle qpen_default_cap = Qt::SquareCap;
static constexpr Qt::PenJoinStyle qpen_default_join = Qt::BevelJoin;

class QPenDataHolder
{
public:
    QPen::DataPtr pen;
    QPenDataHolder(const QBrush &brush, qreal width, Qt::PenStyle penStyle,
                   Qt::PenCapStyle penCapStyle, Qt::PenJoinStyle _joinStyle)
        : pen(new QPenPrivate(brush, width, penStyle, penCapStyle, _joinStyle))
    { }
    ~QPenDataHolder() = default;
    Q_DISABLE_COPY_MOVE(QPenDataHolder)
};

Q_GLOBAL_STATIC_WITH_ARGS(QPenDataHolder, defaultPenInstance,
                          (Qt::black, 1, Qt::SolidLine, qpen_default_cap, qpen_default_join))
Q_GLOBAL_STATIC_WITH_ARGS(QPenDataHolder, nullPenInstance,
                          (Qt::black, 1, Qt::NoPen, qpen_default_cap, qpen_default_join))

/*!
    Constructs a default black solid line pen with 1 width.
*/

QPen::QPen()
{
    d = defaultPenInstance()->pen;
}

/*!
    Constructs a black pen with 1 width and the given \a style.

    \sa setStyle()
*/

QPen::QPen(Qt::PenStyle style)
{
    if (style == Qt::NoPen) {
        d = nullPenInstance()->pen;
    } else {
        d = new QPenPrivate(Qt::black, 1, style, qpen_default_cap, qpen_default_join);
    }
}


/*!
    Constructs a solid line pen with 1 width and the given \a color.

    \sa setBrush(), setColor()
*/

QPen::QPen(const QColor &color)
{
    d = new QPenPrivate(color, 1, Qt::SolidLine, qpen_default_cap, qpen_default_join);
}


/*!
    \fn QPen::QPen(const QBrush &brush, qreal width, Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join)

    Constructs a pen with the specified \a brush, \a width, pen \a style,
    \a cap style and \a join style.

    \sa setBrush(), setWidth(), setStyle(), setCapStyle(), setJoinStyle()
*/

QPen::QPen(const QBrush &brush, qreal width, Qt::PenStyle s, Qt::PenCapStyle c, Qt::PenJoinStyle j)
{
    d = new QPenPrivate(brush, width, s, c, j);
}

/*!
    \fn QPen::QPen(const QPen &pen)

    Constructs a pen that is a copy of the given \a pen.
*/

QPen::QPen(const QPen &p) noexcept
    : d(p.d)
{
}


/*!
    \fn QPen::QPen(QPen &&pen)
    \since 5.4

    Constructs a pen that is moved from the given \a pen.

    The moved-from pen can only be assigned to, copied, or
    destroyed. Any other operation (prior to assignment) leads to
    undefined behavior.
*/

/*!
    Destroys the pen.
*/

QPen::~QPen() = default;

QT_DEFINE_QESDP_SPECIALIZATION_DTOR(QPenPrivate)

/*!
    \fn void QPen::detach()
    Detaches from shared pen data to make sure that this pen is the
    only one referring the data.

    If multiple pens share common data, this pen dereferences the data
    and gets a copy of the data. Nothing is done if there is just a
    single reference.
*/

void QPen::detach()
{
    d.detach();
}


/*!
    \fn QPen &QPen::operator=(const QPen &pen)

    Assigns the given \a pen to this pen and returns a reference to
    this pen.
*/

QPen &QPen::operator=(const QPen &p) noexcept
{
    QPen(p).swap(*this);
    return *this;
}

/*!
    \fn QPen &QPen::operator=(QPen &&other)

    Move-assigns \a other to this QPen instance.

    \since 5.2
*/

/*!
    \fn void QPen::swap(QPen &other)
    \since 4.8
    \memberswap{pen}
*/

/*!
    \overload
    \since 6.9

    Makes this pen a solid pen with the given color, and default
    cap and join styles, and returns a reference to \e this pen.
*/
QPen &QPen::operator=(QColor color)
{
    detach();
    d->brush = color;
    d->width = 1;
    d->style = Qt::SolidLine;
    d->capStyle = qpen_default_cap;
    d->joinStyle = qpen_default_join;

    return *this;
}

/*!
    \overload
    \since 6.9

    Makes this pen a solid, black pen with default cap and join styles,
    and returns a reference to \e this pen.
*/
QPen &QPen::operator=(Qt::PenStyle style)
{
    detach();
    if (style == Qt::NoPen) {
        d = nullPenInstance()->pen;
    } else {
        d->brush = Qt::black;
        d->width = 1;
        d->style = style;
        d->capStyle = qpen_default_cap;
        d->joinStyle = qpen_default_join;
    }
    return *this;
}

/*!
   Returns the pen as a QVariant.
*/
QPen::operator QVariant() const
{
    return QVariant::fromValue(*this);
}

/*!
    \fn Qt::PenStyle QPen::style() const

    Returns the pen style.

    \sa setStyle(), {QPen#Pen Style}{Pen Style}
*/
Qt::PenStyle QPen::style() const
{
    return d->style;
}
/*!
    \fn void QPen::setStyle(Qt::PenStyle style)

    Sets the pen style to the given \a style.

    See the \l Qt::PenStyle documentation for a list of the available
    styles. Since Qt 4.1 it is also possible to specify a custom dash
    pattern using the setDashPattern() function which implicitly
    converts the style of the pen to Qt::CustomDashLine.

    \note This function resets the dash offset to zero.

    \sa style(), {QPen#Pen Style}{Pen Style}
*/

void QPen::setStyle(Qt::PenStyle s)
{
    if (d->style == s)
        return;
    detach();
    d->style = s;
    d->dashPattern.clear();
    d->dashOffset = 0;
}

/*!
    Returns the dash pattern of this pen.

    \sa style(), isSolid()
 */
QList<qreal> QPen::dashPattern() const
{
    if (d->style == Qt::SolidLine || d->style == Qt::NoPen) {
        return QList<qreal>();
    } else if (d->dashPattern.isEmpty()) {
        const qreal space = 2;
        const qreal dot = 1;
        const qreal dash = 4;

        switch (d->style) {
        case Qt::DashLine:
            d->dashPattern.reserve(2);
            d->dashPattern << dash << space;
            break;
        case Qt::DotLine:
            d->dashPattern.reserve(2);
            d->dashPattern << dot << space;
            break;
        case Qt::DashDotLine:
            d->dashPattern.reserve(4);
            d->dashPattern << dash << space << dot << space;
            break;
        case Qt::DashDotDotLine:
            d->dashPattern.reserve(6);
            d->dashPattern << dash << space << dot << space << dot << space;
            break;
        default:
            break;
        }
    }
    return d->dashPattern;
}

/*!
    Sets the dash pattern for this pen to the given \a pattern. This
    implicitly converts the style of the pen to Qt::CustomDashLine.

    The pattern must be specified as an even number of positive entries
    where the entries 1, 3, 5... are the dashes and 2, 4, 6... are the
    spaces. For example:

    \table 100%
    \row
    \li \inlineimage qpen-custom.png
    \li
    \snippet code/src_gui_painting_qpen.cpp 3
    \endtable

    The dash pattern is specified in units of the pens width; e.g. a
    dash of length 5 in width 10 is 50 pixels long. Note that a pen
    with zero width is equivalent to a cosmetic pen with a width of 1
    pixel.

    Each dash is also subject to cap styles so a dash of 1 with square
    cap set will extend 0.5 pixels out in each direction resulting in
    a total width of 2.

    Note that the default cap style is Qt::SquareCap, meaning that a
    square line end covers the end point and extends beyond it by half
    the line width.

    \sa setStyle(), dashPattern(), setCapStyle(), setCosmetic()
 */
void QPen::setDashPattern(const QList<qreal> &pattern)
{
    if (pattern.isEmpty())
        return;
    detach();

    d->dashPattern = pattern;
    d->style = Qt::CustomDashLine;

    if ((d->dashPattern.size() % 2) == 1) {
        qWarning("QPen::setDashPattern: Pattern not of even length");
        d->dashPattern << 1;
    }
}


/*!
    Returns the dash offset for the pen.

    \sa setDashOffset()
*/
qreal QPen::dashOffset() const
{
    return d->dashOffset;
}
/*!
    Sets the dash offset (the starting point on the dash pattern) for this pen
    to the \a offset specified. The offset is measured in terms of the units used
    to specify the dash pattern.

    \table
    \row \li \inlineimage qpen-dashpattern.png
    \li For example, a pattern where each stroke is four units long, followed by a gap
    of two units, will begin with the stroke when drawn as a line.

    However, if the dash offset is set to 4.0, any line drawn will begin with the gap.
    Values of the offset up to 4.0 will cause part of the stroke to be drawn first,
    and values of the offset between 4.0 and 6.0 will cause the line to begin with
    part of the gap.
    \endtable

    \note This implicitly converts the style of the pen to Qt::CustomDashLine.
*/
void QPen::setDashOffset(qreal offset)
{
    if (qFuzzyCompare(offset, d->dashOffset))
        return;
    detach();
    d->dashOffset = offset;
    if (d->style != Qt::CustomDashLine) {
        d->dashPattern = dashPattern();
        d->style = Qt::CustomDashLine;
    }
}

/*!
    Returns the miter limit of the pen. The miter limit is only
    relevant when the join style is set to Qt::MiterJoin.

    \sa setMiterLimit(), {QPen#Join Style}{Join Style}
*/
qreal QPen::miterLimit() const
{
    return d->miterLimit;
}

/*!
    Sets the miter limit of this pen to the given \a limit.

    \image qpen-miterlimit.png

    The miter limit describes how far a miter join can extend from the
    join point. This is used to reduce artifacts between line joins
    where the lines are close to parallel.

    This value does only have effect when the pen style is set to
    Qt::MiterJoin. The value is specified in units of the pen's width,
    e.g. a miter limit of 5 in width 10 is 50 pixels long. The default
    miter limit is 2, i.e. twice the pen width in pixels.

    \sa miterLimit(), setJoinStyle(), {QPen#Join Style}{Join Style}
*/
void QPen::setMiterLimit(qreal limit)
{
    detach();
    d->miterLimit = limit;
}


/*!
    \fn qreal QPen::width() const

    Returns the pen width with integer precision.

    \sa setWidth(), widthF()
*/

int QPen::width() const
{
    return qRound(d->width);
}

/*!
    \fn qreal QPen::widthF() const

    Returns the pen width with floating point precision.

    \sa setWidthF(), width()
*/
qreal QPen::widthF() const
{
    return d->width;
}

/*!
    \fn QPen::setWidth(int width)

    Sets the pen width to the given \a width in pixels with integer
    precision.

    A line width of zero indicates a cosmetic pen. This means that the
    pen width is always drawn one pixel wide, independent of the \l
    {QPainter#Coordinate Transformations}{transformation} set on the
    painter.

    Setting a pen width with a negative value is not supported.

    \sa setWidthF(), width()
*/
void QPen::setWidth(int width)
{
    if (width < 0 || width >= (1 << 15)) {
        qWarning("QPen::setWidth: Setting a pen width that is out of range");
        return;
    }
    if ((qreal)width == d->width)
        return;
    detach();
    d->width = width;
}

/*!
    Sets the pen width to the given \a width in pixels with floating point
    precision.

    A line width of zero indicates a cosmetic pen. This means that the
    pen width is always drawn one pixel wide, independent of the \l
    {QPainter#Coordinate Transformations}{transformation} on the
    painter.

    Setting a pen width with a negative value is not supported.

    \sa setWidth(), widthF()
*/

void QPen::setWidthF(qreal width)
{
    if (width < 0.f || width >= (1 << 15)) {
        qWarning("QPen::setWidthF: Setting a pen width that is out of range");
        return;
    }
    if (qAbs(d->width - width) < 0.00000001f)
        return;
    detach();
    d->width = width;
}


/*!
    Returns the pen's cap style.

    \sa setCapStyle(), {QPen#Cap Style}{Cap Style}
*/
Qt::PenCapStyle QPen::capStyle() const
{
    return d->capStyle;
}

/*!
    \fn void QPen::setCapStyle(Qt::PenCapStyle style)

    Sets the pen's cap style to the given \a style. The default value
    is Qt::SquareCap.

    \sa capStyle(), {QPen#Cap Style}{Cap Style}
*/

void QPen::setCapStyle(Qt::PenCapStyle c)
{
    if (d->capStyle == c)
        return;
    detach();
    d->capStyle = c;
}

/*!
    Returns the pen's join style.

    \sa setJoinStyle(), {QPen#Join Style}{Join Style}
*/
Qt::PenJoinStyle QPen::joinStyle() const
{
    return d->joinStyle;
}

/*!
    \fn void QPen::setJoinStyle(Qt::PenJoinStyle style)

    Sets the pen's join style to the given \a style. The default value
    is Qt::BevelJoin.

    \sa joinStyle(), {QPen#Join Style}{Join Style}
*/

void QPen::setJoinStyle(Qt::PenJoinStyle j)
{
    if (d->joinStyle == j)
        return;
    detach();
    d->joinStyle = j;
}

/*!
    \fn const QColor &QPen::color() const

    Returns the color of this pen's brush.

    \sa brush(), setColor()
*/
QColor QPen::color() const
{
    return d->brush.color();
}

/*!
    \fn void QPen::setColor(const QColor &color)

    Sets the color of this pen's brush to the given \a color.

    \sa setBrush(), color()
*/

void QPen::setColor(const QColor &c)
{
    detach();
    d->brush = QBrush(c);
}


/*!
    Returns the brush used to fill strokes generated with this pen.
*/
QBrush QPen::brush() const
{
    return d->brush;
}

/*!
    Sets the brush used to fill strokes generated with this pen to the given
    \a brush.

    \sa brush(), setColor()
*/
void QPen::setBrush(const QBrush &brush)
{
    detach();
    d->brush = brush;
}


/*!
    Returns \c true if the pen has a solid fill, otherwise false.

    \sa style(), dashPattern()
*/
bool QPen::isSolid() const
{
    return d->brush.style() == Qt::SolidPattern;
}


/*!
    Returns \c true if the pen is cosmetic; otherwise returns \c false.

    Cosmetic pens are used to draw strokes that have a constant width
    regardless of any transformations applied to the QPainter they are
    used with. Drawing a shape with a cosmetic pen ensures that its
    outline will have the same thickness at different scale factors.

    A zero width pen is cosmetic by default.

    \sa setCosmetic(), widthF()
*/

bool QPen::isCosmetic() const
{
    return (d->cosmetic == true) || d->width == 0;
}


/*!
    Sets this pen to cosmetic or non-cosmetic, depending on the value of
    \a cosmetic.

    \sa isCosmetic()
*/

void QPen::setCosmetic(bool cosmetic)
{
    detach();
    d->cosmetic = cosmetic;
}

/*!
    \internal
*/
bool QPen::isSolidDefaultLine() const noexcept
{
    return d->style == Qt::SolidLine && d->width == 1
        && d->capStyle == qpen_default_cap && d->joinStyle == qpen_default_join
        && qFuzzyCompare(d->dashOffset, 0) && qFuzzyCompare(d->miterLimit, 2)
        && d->cosmetic == false;
}

/*!
    \fn bool QPen::operator!=(const QPen &pen) const

    Returns \c true if the pen is different from the given \a pen;
    otherwise false. Two pens are different if they have different
    styles, widths or colors.

    \sa operator==()
*/

/*!
    \fn bool QPen::operator==(const QPen &pen) const

    Returns \c true if the pen is equal to the given \a pen; otherwise
    false. Two pens are equal if they have equal styles, widths and
    colors.

    \sa operator!=()
*/

bool QPen::operator==(const QPen &p) const
{
    return (p.d == d)
        || (p.d->style == d->style
            && p.d->capStyle == d->capStyle
            && p.d->joinStyle == d->joinStyle
            && p.d->width == d->width
            && p.d->miterLimit == d->miterLimit
            && (d->style != Qt::CustomDashLine
                || (qFuzzyCompare(p.d->dashOffset, d->dashOffset) &&
                    p.d->dashPattern == d->dashPattern))
            && p.d->brush == d->brush
            && p.d->cosmetic == d->cosmetic);
}

/*!
    \internal
*/
bool QPen::doCompareEqualColor(QColor rhs) const noexcept
{
    return d->brush == rhs && isSolidDefaultLine();
}

/*!
    \internal
*/
bool QPen::doCompareEqualStyle(Qt::PenStyle rhs) const
{
    if (rhs == Qt::NoPen)
        return style() == Qt::NoPen;
    return *this == QPen(rhs); // ### optimize (allocates)
}

/*!
    \fn bool QPen::isDetached()

    \internal
*/

bool QPen::isDetached()
{
    return d->ref.loadRelaxed() == 1;
}


/*****************************************************************************
  QPen stream functions
 *****************************************************************************/
#ifndef QT_NO_DATASTREAM
/*!
    \fn QDataStream &operator<<(QDataStream &stream, const QPen &pen)
    \relates QPen

    Writes the given \a pen to the given \a stream and returns a reference to
    the \a stream.

    \sa {Serializing Qt Data Types}
*/

QDataStream &operator<<(QDataStream &s, const QPen &p)
{
    if (s.version() < 3) {
        s << (quint8)p.style();
    } else if (s.version() < QDataStream::Qt_4_3) {
        s << (quint8)(uint(p.style()) | uint(p.capStyle()) | uint(p.joinStyle()));
    } else {
        s << (quint16)(uint(p.style()) | uint(p.capStyle()) | uint(p.joinStyle()));
        s << (bool)(p.d->cosmetic);
    }

    if (s.version() < 7) {
        s << (quint8)p.width();
        s << p.color();
    } else {
        s << double(p.widthF());
        s << p.brush();
        s << double(p.miterLimit());
        if (sizeof(qreal) == sizeof(double)) {
            s << p.dashPattern();
        } else {
            // ensure that we write doubles here instead of streaming the pattern
            // directly; otherwise, platforms that redefine qreal might generate
            // data that cannot be read on other platforms.
            QList<qreal> pattern = p.dashPattern();
            s << quint32(pattern.size());
            for (int i = 0; i < pattern.size(); ++i)
                s << double(pattern.at(i));
        }
        if (s.version() >= 9)
            s << double(p.dashOffset());
        if (s.version() >= QDataStream::Qt_5_0)
            s << bool(qFuzzyIsNull(p.widthF()));
    }
    return s;
}

/*!
    \fn QDataStream &operator>>(QDataStream &stream, QPen &pen)
    \relates QPen

    Reads a pen from the given \a stream into the given \a pen and
    returns a reference to the \a stream.

    \sa {Serializing Qt Data Types}
*/

QDataStream &operator>>(QDataStream &s, QPen &p)
{
    quint16 style;
    quint8 width8 = 0;
    double width = 0;
    QColor color;
    QBrush brush;
    double miterLimit = 2;
    QList<qreal> dashPattern;
    double dashOffset = 0;
    bool cosmetic = false;
    bool defaultWidth;
    if (s.version() < QDataStream::Qt_4_3) {
        quint8 style8;
        s >> style8;
        style = style8;
    } else {
        s >> style;
        s >> cosmetic;
    }
    if (s.version() < 7) {
        s >> width8;
        s >> color;
        brush = color;
        width = width8;
    } else {
        s >> width;
        s >> brush;
        s >> miterLimit;
        if (sizeof(qreal) == sizeof(double)) {
            s >> dashPattern;
        } else {
            quint32 numDashes;
            s >> numDashes;
            double dash;
            dashPattern.reserve(numDashes);
            for (quint32 i = 0; i < numDashes; ++i) {
                s >> dash;
                dashPattern << dash;
            }
        }
        if (s.version() >= 9)
            s >> dashOffset;
    }

    if (s.version() >= QDataStream::Qt_5_0) {
        s >> defaultWidth;
    }

    p.detach();
    p.d->width = width;
    p.d->brush = brush;
    p.d->style = Qt::PenStyle(style & Qt::MPenStyle);
    p.d->capStyle = Qt::PenCapStyle(style & Qt::MPenCapStyle);
    p.d->joinStyle = Qt::PenJoinStyle(style & Qt::MPenJoinStyle);
    p.d->dashPattern = dashPattern;
    p.d->miterLimit = miterLimit;
    p.d->dashOffset = dashOffset;
    p.d->cosmetic = cosmetic;

    return s;
}
#endif //QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const QPen &p)
{
    const char *PEN_STYLES[] = {
        "NoPen",
        "SolidLine",
        "DashLine",
        "DotLine",
        "DashDotLine",
        "DashDotDotLine",
        "CustomDashLine"
    };

    QDebugStateSaver saver(dbg);
    dbg.nospace() << "QPen(" << p.width() << ',' << p.brush()
                  << ',' << PEN_STYLES[p.style()] << ',' << int(p.capStyle())
                  << ',' << int(p.joinStyle()) << ',' << p.dashPattern()
                  << ',' << p.dashOffset()
                  << ',' << p.miterLimit() << ')';
    return dbg;
}
#endif

/*!
    \fn DataPtr &QPen::data_ptr()
    \internal
*/

/*!
    \typedef QPen::DataPtr

    \internal
*/

QT_END_NAMESPACE

#undef QT_COMPILING_QPEN
