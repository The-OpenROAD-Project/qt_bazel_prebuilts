// Copyright (C) 2022 Intel Corporation.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcborvalue.h"
#include "qcborvalue_p.h"
#include "qdatastream.h"
#include "qcborarray.h"
#include "qcbormap.h"

#if QT_CONFIG(cborstreamreader)
#include "qcborstreamreader.h"
#endif

#if QT_CONFIG(cborstreamwriter)
#include "qcborstreamwriter.h"
#endif

#include <QtCore/qdebug.h>
#include <qendian.h>
#include <qlocale.h>
#include <qdatetime.h>
#include <qtimezone.h>
#include <private/qnumeric_p.h>
#include <private/qsimd_p.h>

#include <new>

QT_BEGIN_NAMESPACE

// Worst case memory allocation for a corrupt stream: 256 MB for 32-bit, 1 GB for 64-bit
static constexpr quint64 MaxAcceptableMemoryUse = (sizeof(void*) == 4 ? 256 : 1024) * 1024 * 1024;

// Internal limits to ensure we don't blow up the memory when parsing a corrupt
// (possibly crafted to exploit) CBOR stream. The recursion impacts both the
// maps/arrays we'll open when parsing and the thread's stack, as the parser is
// itself recursive. If someone really needs more than 1024 layers of nesting,
// they probably have a weird use-case for which custom parsing and
// serialisation code would make sense. The limit on element count is the
// preallocated limit: if the stream does actually have more elements, we will
// grow the container.
Q_DECL_UNUSED static constexpr int MaximumRecursionDepth = 1024;
Q_DECL_UNUSED static constexpr quint64 MaximumPreallocatedElementCount =
        MaxAcceptableMemoryUse / MaximumRecursionDepth / sizeof(QtCbor::Element) - 1;

/*!
    \class QCborValue
    \inmodule QtCore
    \ingroup cbor
    \ingroup qtserialization
    \reentrant
    \since 5.12

    \brief The QCborValue class encapsulates a value in CBOR.

    \compares strong

    This class can be used to hold one of the many types available in CBOR.
    CBOR is the Concise Binary Object Representation, a very compact form of
    binary data encoding that is a superset of JSON. It was created by the IETF
    Constrained RESTful Environments (CoRE) WG, which has used it in many
    new RFCs. It is meant to be used alongside the
    \l{RFC 7252}{CoAP protocol}.

    CBOR has three groups of built-in types:

    \list
      \li Basic types: integers, floating point (double), boolean, null, etc.
      \li String-like types: strings and byte arrays
      \li Containers: arrays and maps
    \endlist

    Additionally, CBOR supports a form of type extensibility by associating a
    "tag" to one of the above types to convey more information. For example, a
    UUID is represented by a tag and a byte array containing the 16 bytes of
    the UUID content. QCborValue supports creating and decoding several of those
    extended types directly with Qt classes (like QUuid).

    For the complete list, see \l QCborValue::Type. The type of a QCborValue can
    be queried using type() or one of the "isXxxx" functions.

    \section1 Extended types and tagged values

    A tagged value is a normal QCborValue that is paired with a number that
    is its tag. See \l QCborKnownTags for more information on what tags are in
    the API as well as the full, official list. Such combinations form extended
    types.

    QCborValue has support for certain extended types in the API, like URL
    (with \l QUrl) and UUID (with \l QUuid). Other extended types not supported
    in the API are represented by a QCborValue of \l {Type}{Tag} type. The tag
    can later be retrieved by tag() and the tagged value using taggedValue().

    In order to support future compatibility, QCborValues containing extended
    Qt types compare equal to the tag type of the same contents. In other
    words, the following expression is true:

    \snippet code/src_corelib_serialization_qcborvalue.cpp 0

    \section1 Undefined and null values

    QCborValue can contain a value of "null", which is not of any specific type.
    It resembles the C++ \c {std::nullptr_t} type, whose only possible value is
    \nullptr. QCborValue has a constructor taking such a type and creates a
    null QCborValue.

    Null values are used to indicate that an optional value is not present. In
    that aspect, it is similar to the C++ Standard Library type \c
    {std::optional} when that is disengaged. Unlike the C++ type, CBOR nulls
    are simply of type "Null" and it is not possible to determine what concrete
    type it is replacing.

    QCborValue can also be of the undefined type, which represents a value of
    "undefined". In fact, that is what the QCborValue default constructor
    creates.

    Undefined values are different from null values. While nulls are used to
    indicate an optional value that is not provided, Undefined is usually
    used to indicate that an expected value could not be provided, usually due
    to an error or a precondition that could not be satisfied.

    Such values are completely valid and may appear in CBOR streams, unlike
    JSON content and QJsonValue's undefined bit. But like QJsonValue's
    Undefined, it is returned by a CBOR container's value() or read-only
    operator[] for invalid look-ups (index out of range for QCborArray, or key
    not found for QCborMap). It is not possible to tell such a case apart from
    the value of Undefined, so if that is required, check the QCborArray size
    and use the QCborMap iterator API.

    \section1 Simple types

    CBOR supports additional simple types that, like Null and Undefined, carry
    no other value. They are called interchangeably "Simple Types" and "Simple
    Values". CBOR encodes booleans as two distinct types (one for \c true and
    one for \c false), but QCborValue has a convenience API for them.

    There are currently no other defined CBOR simple types. QCborValue supports
    them simply by their number with API like isSimpleType() and
    toSimpleType(), available for compatibility with future specifications
    before the Qt API can be updated. Their use before such a specification is
    discouraged, as other CBOR implementations may not support them fully.

    \section1 CBOR support

    QCborValue supports all CBOR features required to create canonical and
    strict streams. It implements almost all of the features specified in \l
    {RFC 7049}.

    The following table lists the CBOR features that QCborValue supports.

    \table
      \header \li Feature                        \li Support
      \row   \li Unsigned numbers                \li Yes (\l qint64 range)
      \row   \li Negative numbers                \li Yes (\l qint64 range)
      \row   \li Byte strings                    \li Yes
      \row   \li Text strings                    \li Yes
      \row   \li Chunked strings                 \li See below
      \row   \li Tags                            \li Yes (arbitrary)
      \row   \li Booleans                        \li Yes
      \row   \li Null                            \li Yes
      \row   \li Undefined                       \li Yes
      \row   \li Arbitrary simple values         \li Yes
      \row   \li Half-precision float (16-bit)   \li Yes
      \row   \li Single-precision float (32-bit) \li Yes
      \row   \li Double-precision float (64-bit) \li Yes
      \row   \li Infinities and NaN floating point \li Yes
      \row   \li Determinate-length arrays and maps \li Yes
      \row   \li Indeterminate-length arrays and maps \li Yes
      \row   \li Map key types other than strings and integers \li Yes (arbitrary)
    \endtable

    Integers in QCborValue are limited to the range of the \l qint64 type. That
    is, from -9,223,372,036,854,775,808 (-2\sup{63}) to
    9,223,372,036,854,775,807 (2\sup{63} - 1). CBOR itself can represent integer
    values outside of this range, which QCborValue does not support. When
    decoding a stream using fromCbor() containing one of those values,
    QCborValue will convert automatically to \l {Type}{Double}, but that may
    lose up to 11 bits of precision.

    fromCbor() is able to decode chunked strings, but will always merge the
    chunks together into a single QCborValue. For that reason, it always writes
    non-chunked strings when using toCbor() (which is required by the Canonical
    format anyway).

    QCborValue will always convert half- and single-precision floating point
    values in the CBOR stream to double-precision. The toCbor() function can
    take a parameter indicating to recreate them.

    \section1 QCborValueRef

    QCborValueRef is a helper class for QCborArray and QCborMap. It is the type
    you get when using one of the mutating APIs in those classes. Unlike
    QCborValue, new values can be assigned to that class. When that is done, the
    array or map it refers to will be modified with the new value. In all other
    aspects, its API is identical to QCborValue.

    \sa QCborArray, QCborMap, QCborStreamReader, QCborStreamWriter,
        QJsonValue, QJsonDocument, {Serialization Converter}, {Saving and Loading a Game}
        {Parsing and displaying CBOR data}
 */

/*!
    \class QCborParserError
    \inmodule QtCore
    \ingroup cbor
    \reentrant
    \since 5.12

    \brief The QCborParserError is used by QCborValue to report a parsing error.

    This class is used by \l {QCborValue::fromCbor(const QByteArray &ba,
    QCborParserError *error)} to report a parser error and the byte offset
    where the error was detected.

    \sa QCborValue, QCborError
 */

/*!
    \variable QCborParserError::offset

    This field contains the offset from the beginning of the data where the
    error was detected. The offset should point to the beginning of the item
    that contained the error, even if the error itself was elsewhere (for
    example, for UTF-8 decoding issues).

    \sa QCborValue::fromCbor()
 */

/*!
    \variable QCborParserError::error

    This field contains the error code that indicates what decoding problem was
    found.

    \sa QCborValue::fromCbor()
 */

/*!
    \fn QString QCborParserError::errorString() const

    Returns a string representation of the error code. This string is not
    translated.

    \sa QCborError::toString(), QCborValue::fromCbor()
 */

/*!
    \enum QCborValue::EncodingOption

    This enum is used in the options argument to toCbor(), modifying the
    behavior of the encoder.

    \omitvalue SortKeysInMaps
    \value NoTransformation (Default) Performs no transformations.
    \value UseFloat         Tells the encoder to use IEEE 754 single-precision floating point
                            (that is, \c float) whenever possible.
    \value UseFloat16       Tells the encoder to use IEEE 754 half-precision floating point
                            (that is, \c qfloat16), whenever possible. Implies \c UseFloat.
    \value UseIntegers      Tells the encoder to use integers whenever a value of type \l
                            {Type}{Double} contains an integer.

    The use of \c UseFloat16 is required to encode the stream in Canonical
    Format, but is not otherwise necessary.

    \sa toCbor()
 */

/*!
    \enum QCborValue::DiagnosticNotationOption

    This enum is used in the option argument to toDiagnosticNotation(), to
    modify the output format.

    \value Compact          Does not use any line-breaks, producing a compact representation.
    \value LineWrapped      Uses line-breaks, one QCborValue per line.
    \value ExtendedFormat   Uses some different options to represent values, not found in
                            RFC 7049. Those options are subject to change.

    Currently, \c ExtendedFormat will change how byte arrays are represented.
    Without it, they are always hex-encoded and without spaces. With it,
    QCborValue::toCbor() will either use hex with spaces, base64 or base64url
    encoding, depending on the context.

    \sa toDiagnosticNotation()
 */

/*!
    \enum QCborValue::Type

    This enum represents the QCborValue type. It is returned by the type()
    function.

    The CBOR built-in types are:

    \value Integer              \c qint64: An integer value
    \value ByteArray            \l QByteArray: a byte array ("byte string")
    \value String               \l QString: a Unicode string ("text string")
    \value Array                \l QCborArray: an array of QCborValues
    \value Map                  \l QCborMap: an associative container of QCborValues
    \value SimpleType           \l QCborSimpleType: one of several simple types/values
    \value False                \c bool: the simple type for value \c false
    \value True                 \c bool: the simple type for value \c true
    \value Null                 \c std::nullptr_t: the simple type for the null value
    \value Undefined            (no type) the simple type for the undefined value
    \value Double               \c double: a double-precision floating point
    \value Invalid              Not a valid value, this usually indicates a CBOR decoding error

    Additionally, QCborValue can represent extended types:

    \value Tag                  An unknown or unrecognized extended type, represented by its
                                tag (a \l QCborTag) and the tagged value (a QCborValue)
    \value DateTime             \l QDateTime: a date and time stamp
    \value Url                  \l QUrl: a URL or URI
    \value RegularExpression    \l QRegularExpression: the pattern of a regular expression
    \value Uuid                 \l QUuid: a UUID

    \sa type()
 */

/*!
    \fn QCborValue::QCborValue()

    Creates a QCborValue of the \l {Type}{Undefined} type.

    CBOR undefined values are used to indicate missing information, usually as
    a result of a previous operation that did not complete as expected. They
    are also used by the QCborArray and QCborMap API to indicate the searched
    item was not found.

    Undefined values are represented by the \l {QCborSimpleType}{Undefined
    simple type}. Because of that, QCborValues with undefined values will also
    return true for isSimpleType() and
    \c{isSimpleType(QCborSimpleType::Undefined)}.

    Undefined values are different from null values.

    QCborValue objects with undefined values are also different from invalid
    QCborValue objects. The API will not create invalid QCborValues, but they
    may exist as a result of a parsing error.

    \sa isUndefined(), isNull(), isSimpleType()
 */

/*!
    \fn QCborValue::QCborValue(Type t_)

    Creates a QCborValue of type \a t_. The value associated with such a type
    (if any) will be default constructed.

    \sa type()
 */

/*!
    \fn QCborValue::QCborValue(std::nullptr_t)

    Creates a QCborValue of the \l {Type}{Null} type.

    CBOR null values are used to indicate optional values that were not
    provided. They are distinct from undefined values, in that null values are
    usually not the result of an earlier error or problem.

    \sa isNull(), isUndefined(), isSimpleType()
 */

/*!
    \fn QCborValue::QCborValue(bool b)

    Creates a QCborValue with boolean value \a b. The value can later be
    retrieved using toBool().

    Internally, CBOR booleans are represented by a pair of types, one for true
    and one for false. For that reason, boolean QCborValues will return true
    for isSimpleType() and one of \c{isSimpleType(QCborSimpleType::False)} or
    \c{isSimpleType(QCborSimpleType::True)}.

    \sa toBool(), isBool(), isTrue(), isFalse(), isSimpleType()
 */

/*!
    \fn QCborValue::QCborValue(qint64 i)

    Creates a QCborValue with integer value \a i. The value can later be
    retrieved using toInteger().

    CBOR integer values are distinct from floating point values. Therefore,
    QCborValue objects with integers will compare differently to QCborValue
    objects containing floating-point, even if the values contained in the
    objects are equivalent.

    \sa toInteger(), isInteger(), isDouble()
 */

/*!
    \fn QCborValue::QCborValue(double d)

    Creates a QCborValue with floating point value \a d. The value can later be
    retrieved using toDouble().

    CBOR floating point values are distinct from integer values. Therefore,
    QCborValue objects with integers will compare differently to QCborValue
    objects containing floating-point, even if the values contained in the
    objects are equivalent.

    \sa toDouble(), isDouble(), isInteger()
 */

/*!
    \fn QCborValue::QCborValue(QCborSimpleType st)

    Creates a QCborValue of simple type \a st. The type can later be retrieved
    using toSimpleType() as well as isSimpleType(st).

    CBOR simple types are types that do not have any associated value, like
    C++'s \c{std::nullptr_t} type, whose only possible value is \nullptr.

    If \a st is \c{QCborSimpleType::Null}, the resulting QCborValue will be of
    the \l{Type}{Null} type and similarly for \c{QCborSimpleType::Undefined}.
    If \a st is \c{QCborSimpleType::False} or \c{QCborSimpleType::True}, the
    created QCborValue will be a boolean containing a value of false or true,
    respectively.

    This function can be used with simple types not defined in the API. For
    example, to create a QCborValue with simple type 12, one could write:

    \snippet code/src_corelib_serialization_qcborvalue.cpp 1

    Simple types should not be used until a specification for them has been
    published, since other implementations may not support them properly.
    Simple type values 24 to 31 are reserved and must not be used.

    isSimpleType(), isNull(), isUndefined(), isTrue(), isFalse()
 */

/*!
    \fn QCborValue::QCborValue(QCborKnownTags tag, const QCborValue &taggedValue)
    \overload

    Creates a QCborValue for the extended type represented by the tag value \a
    tag, tagging value \a taggedValue. The tag can later be retrieved using
    tag() and the tagged value using taggedValue().

    \sa isTag(), tag(), taggedValue(), QCborKnownTags
 */

/*!
    \fn QCborValue::~QCborValue()

    Disposes of the current QCborValue object and frees any associated resources.
 */

/*!
    \fn QCborValue::QCborValue(QCborValue &&other)
    \overload

    Moves the contents of the \a other QCborValue object into this one and frees
    the resources of this one.
 */

/*!
    \fn QCborValue &&QCborValue::operator=(QCborValue &&other)
    \overload

    Moves the contents of the \a other QCborValue object into this one and frees
    the resources of this one. Returns a reference to this object.
 */

/*!
    \fn void QCborValue::swap(QCborValue &other)
    \memberswap{value}
 */

/*!
    \fn QCborValue::Type QCborValue::type() const

    Returns the type of this QCborValue. The type can also later be retrieved by one
    of the "isXxx" functions.

    \sa isInteger(), isByteArray(), isString(), isArray(), isMap(),
        isTag(), isFalse(), isTrue(), isBool(), isNull(), isUndefined, isDouble(),
        isDateTime(), isUrl(), isRegularExpression(), isUuid()
 */

/*!
    \fn bool QCborValue::isInteger() const

    Returns true if this QCborValue is of the integer type. The integer value
    can be retrieved using toInteger().

    \sa type(), toInteger()
 */

/*!
    \fn bool QCborValue::isByteArray() const

    Returns true if this QCborValue is of the byte array type. The byte array
    value can be retrieved using toByteArray().

    \sa type(), toByteArray()
 */

/*!
    \fn bool QCborValue::isString() const

    Returns true if this QCborValue is of the string type. The string value
    can be retrieved using toString().

    \sa type(), toString()
 */

/*!
    \fn bool QCborValue::isArray() const

    Returns true if this QCborValue is of the array type. The array value can
    be retrieved using toArray().

    \sa type(), toArray()
 */

/*!
    \fn bool QCborValue::isMap() const

    Returns true if this QCborValue is of the map type. The map value can be
    retrieved using toMap().

    \sa type(), toMap()
 */

/*!
    \fn bool QCborValue::isTag() const

    Returns true if this QCborValue is of the tag type. The tag value can be
    retrieved using tag() and the tagged value using taggedValue().

    This function also returns true for extended types that the API
    recognizes. For code that handles extended types directly before the Qt API
    is updated to support them, it is possible to recreate the tag + tagged
    value pair by using taggedValue().

    \sa type(), tag(), taggedValue(), taggedValue()
 */

/*!
    \fn bool QCborValue::isFalse() const

    Returns true if this QCborValue is a boolean with false value. This
    function exists because, internally, CBOR booleans are stored as two
    separate types, one for true and one for false.

    \sa type(), isBool(), isTrue(), toBool()
 */

/*!
    \fn bool QCborValue::isTrue() const

    Returns true if this QCborValue is a boolean with true value. This
    function exists because, internally, CBOR booleans are stored as two
    separate types, one for false and one for true.

    \sa type(), isBool(), isFalse(), toBool()
 */

/*!
    \fn bool QCborValue::isBool() const

    Returns true if this QCborValue is a boolean. The value can be retrieved
    using toBool().

    \sa type(), toBool(), isTrue(), isFalse()
 */

/*!
    \fn bool QCborValue::isUndefined() const

    Returns true if this QCborValue is of the undefined type.

    CBOR undefined values are used to indicate missing information, usually as
    a result of a previous operation that did not complete as expected. They
    are also used by the QCborArray and QCborMap API to indicate the searched
    item was not found.

    Undefined values are distinct from null values.

    QCborValue objects with undefined values are also different from invalid
    QCborValue objects. The API will not create invalid QCborValues, but they
    may exist as a result of a parsing error.

    \sa type(), isNull(), isInvalid()
 */

/*!
    \fn bool QCborValue::isNull() const

    Returns true if this QCborValue is of the null type.

    CBOR null values are used to indicate optional values that were not
    provided. They are distinct from undefined values, in that null values are
    usually not the result of an earlier error or problem.

    Null values are distinct from undefined values and from invalid QCborValue
    objects. The API will not create invalid QCborValues, but they may exist as
    a result of a parsing error.

    \sa type(), isUndefined(), isInvalid()
 */

/*!
    \fn bool QCborValue::isDouble() const

    Returns true if this QCborValue is of the floating-point type. The value
    can be retrieved using toDouble().

    \sa type(), toDouble()
 */

/*!
    \fn bool QCborValue::isDateTime() const

    Returns true if this QCborValue is of the date/time type. The value can be
    retrieved using toDateTime(). Date/times are extended types that use the
    tag \l{QCborKnownTags}{DateTime}.

    Additionally, when decoding from a CBOR stream, QCborValue will interpret
    tags of value \l{QCborKnownTags}{UnixTime_t} and convert them to the
    equivalent date/time.

    \sa type(), toDateTime()
 */

/*!
    \fn bool QCborValue::isUrl() const

    Returns true if this QCborValue is of the URL type. The URL value
    can be retrieved using toUrl().

    \sa type(), toUrl()
 */

/*!
    \fn bool QCborValue::isRegularExpression() const

    Returns true if this QCborValue contains a regular expression's pattern.
    The pattern can be retrieved using toRegularExpression().

    \sa type(), toRegularExpression()
 */

/*!
    \fn bool QCborValue::isUuid() const

    Returns true if this QCborValue contains a UUID. The value can be retrieved
    using toUuid().

    \sa type(), toUuid()
 */

/*!
    \fn bool QCborValue::isInvalid() const

    Returns true if this QCborValue is not of any valid type. Invalid
    QCborValues are distinct from those with undefined values and they usually
    represent a decoding error.

    \sa isUndefined(), isNull()
 */

/*!
    \fn bool QCborValue::isContainer() const

    This convenience function returns true if the QCborValue is either an array
    or a map.

    \sa isArray(), isMap()
 */

/*!
    \fn bool QCborValue::isSimpleType() const

    Returns true if this QCborValue is of one of the CBOR simple types. The
    type itself can later be retrieved using type(), even for types that don't have an
    enumeration in the API. They can also be checked with the
    \l{isSimpleType(QCborSimpleType)} overload.

    \sa QCborSimpleType, isSimpleType(QCborSimpleType), toSimpleType()
 */

/*!
    \fn bool QCborValue::isSimpleType(QCborSimpleType st) const
    \overload

    Returns true if this QCborValue is of a simple type and toSimpleType()
    would return \a st, false otherwise. This function can be used to check for
    any CBOR simple type, even those for which there is no enumeration in the
    API. For example, for the simple type of value 12, you could write:

    \snippet code/src_corelib_serialization_qcborvalue.cpp 2

    \sa QCborValue::QCborValue(QCborSimpleType), isSimpleType(), isFalse(),
        isTrue(), isNull, isUndefined(), toSimpleType()
 */

/*!
    \fn QCborSimpleType QCborValue::toSimpleType(QCborSimpleType defaultValue) const

    Returns the simple type this QCborValue is of, if it is a simple type. If
    it is not a simple type, it returns \a defaultValue.

    The following types are simple types and this function will return the
    listed values:

    \table
      \row \li QCborValue::False        \li QCborSimpleType::False
      \row \li QCborValue::True         \li QCborSimpleType::True
      \row \li QCborValue::Null         \li QCborSimpleType::Null
      \row \li QCborValue::Undefined    \li QCborSimpleType::Undefined
    \endtable

    \sa type(), isSimpleType(), isBool(), isTrue(), isFalse(), isTrue(),
        isNull(), isUndefined()
 */

/*!
    \fn qint64 QCborValue::toInteger(qint64 defaultValue) const

    Returns the integer value stored in this QCborValue, if it is of the
    integer type. If it is of the Double type, this function returns the
    floating point value converted to integer. In any other case, it returns \a
    defaultValue.

    \sa isInteger(), isDouble(), toDouble()
 */

/*!
    \fn bool QCborValue::toBool(bool defaultValue) const

    Returns the boolean value stored in this QCborValue, if it is of a boolean
    type. Otherwise, it returns \a defaultValue.

    \sa isBool(), isTrue(), isFalse()
 */

/*!
    \fn double QCborValue::toDouble(double defaultValue) const

    Returns the floating point value stored in this QCborValue, if it is of the
    Double type. If it is of the Integer type, this function returns the
    integer value converted to double. In any other case, it returns \a
    defaultValue.

    \sa isDouble(), isInteger(), toInteger()
 */

using namespace QtCbor;

static QCborContainerPrivate *assignContainer(QCborContainerPrivate *&d, QCborContainerPrivate *x)
{
    if (d == x)
        return d;
    if (d)
        d->deref();
    if (x)
        x->ref.ref();
    return d = x;
}

static QCborValue::Type convertToExtendedType(QCborContainerPrivate *d)
{
    qint64 tag = d->elements.at(0).value;
    auto &e = d->elements[1];
    const ByteData *b = d->byteData(e);

    auto replaceByteData = [&](const char *buf, qsizetype len, Element::ValueFlags f) {
        d->data.clear();
        d->usedData = 0;
        e.flags = Element::HasByteData | f;
        e.value = d->addByteData(buf, len);
    };

    switch (tag) {
#if QT_CONFIG(datestring)
    case qint64(QCborKnownTags::DateTimeString):
    case qint64(QCborKnownTags::UnixTime_t): {
        QDateTime dt;
        if (tag == qint64(QCborKnownTags::DateTimeString) && b &&
            e.type == QCborValue::String && (e.flags & Element::StringIsUtf16) == 0) {
            // The data is supposed to be US-ASCII. If it isn't (contains UTF-8),
            // QDateTime::fromString will fail anyway.
            dt = QDateTime::fromString(b->asLatin1(), Qt::ISODateWithMs);
        } else if (tag == qint64(QCborKnownTags::UnixTime_t)) {
            qint64 msecs;
            bool ok = false;
            if (e.type == QCborValue::Integer) {
#if QT_POINTER_SIZE == 8
                // we don't have a fast 64-bit qMulOverflow implementation on
                // 32-bit architectures.
                ok = !qMulOverflow(e.value, qint64(1000), &msecs);
#else
                static const qint64 Limit = std::numeric_limits<qint64>::max() / 1000;
                ok = (e.value > -Limit && e.value < Limit);
                if (ok)
                    msecs = e.value * 1000;
#endif
            } else if (e.type == QCborValue::Double) {
                ok = convertDoubleTo(round(e.fpvalue() * 1000), &msecs);
            }
            if (ok)
                dt = QDateTime::fromMSecsSinceEpoch(msecs, QTimeZone::UTC);
        }
        if (dt.isValid()) {
            QByteArray text = dt.toString(Qt::ISODateWithMs).toLatin1();
            if (!text.isEmpty()) {
                replaceByteData(text, text.size(), Element::StringIsAscii);
                e.type = QCborValue::String;
                d->elements[0].value = qint64(QCborKnownTags::DateTimeString);
                return QCborValue::DateTime;
            }
        }
        break;
    }
#endif

#ifndef QT_BOOTSTRAPPED
    case qint64(QCborKnownTags::Url):
        if (e.type == QCborValue::String) {
            if (b) {
                // normalize to a short (decoded) form, so as to save space
                QUrl url(e.flags & Element::StringIsUtf16 ?
                             b->asQStringRaw() :
                             b->toUtf8String(), QUrl::StrictMode);
                if (url.isValid()) {
                    QByteArray encoded = url.toString(QUrl::DecodeReserved).toUtf8();
                    replaceByteData(encoded, encoded.size(), {});
                }
            }
            return QCborValue::Url;
        }
        break;
#endif // QT_BOOTSTRAPPED

#if QT_CONFIG(regularexpression)
    case quint64(QCborKnownTags::RegularExpression):
        if (e.type == QCborValue::String) {
            // no normalization is necessary
            return QCborValue::RegularExpression;
        }
        break;
#endif // QT_CONFIG(regularexpression)

    case qint64(QCborKnownTags::Uuid):
        if (e.type == QCborValue::ByteArray) {
            // force the size to 16
            char buf[sizeof(QUuid)] = {};
            if (b)
                memcpy(buf, b->byte(), qMin(sizeof(buf), size_t(b->len)));
            replaceByteData(buf, sizeof(buf), {});

            return QCborValue::Uuid;
        }
        break;
    }

    // no enriching happened
    return QCborValue::Tag;
}

#if QT_CONFIG(cborstreamwriter)
static void writeDoubleToCbor(QCborStreamWriter &writer, double d, QCborValue::EncodingOptions opt)
{
    if (qt_is_nan(d)) {
        if (opt & QCborValue::UseFloat) {
#ifndef QT_BOOTSTRAPPED
            if ((opt & QCborValue::UseFloat16) == QCborValue::UseFloat16)
                return writer.append(std::numeric_limits<qfloat16>::quiet_NaN());
#endif
            return writer.append(std::numeric_limits<float>::quiet_NaN());
        }
        return writer.append(qt_qnan());
    }

    if (qt_is_inf(d)) {
        d = d > 0 ? qt_inf() : -qt_inf();
    } else if (opt & QCborValue::UseIntegers) {
        quint64 i;
        if (convertDoubleTo(d, &i)) {
            if (d < 0)
                return writer.append(QCborNegativeInteger(i));
            return writer.append(i);
        }
    }

    if (opt & QCborValue::UseFloat) {
        float f = float(d);
        if (f == d) {
            // no data loss, we could use float
#ifndef QT_BOOTSTRAPPED
            if ((opt & QCborValue::UseFloat16) == QCborValue::UseFloat16) {
                qfloat16 f16 = qfloat16(f);
                if (f16 == f)
                    return writer.append(f16);
            }
#endif

            return writer.append(f);
        }
    }

    writer.append(d);
}
#endif // QT_CONFIG(cborstreamwriter)

static inline int typeOrder(QCborValue::Type e1, QCborValue::Type  e2)
{
    auto comparable = [](QCborValue::Type type) {
        if (type >= 0x10000)        // see QCborValue::isTag_helper()
            return QCborValue::Tag;
        return type;
    };
    return comparable(e1) - comparable(e2);
}

QCborContainerPrivate::~QCborContainerPrivate()
{
    // delete our elements
    for (Element &e : elements) {
        if (e.flags & Element::IsContainer)
            e.container->deref();
    }
}

void QCborContainerPrivate::compact()
{
    if (usedData > data.size() / 2)
        return;

    // 50% savings if we recreate the byte data
    QByteArray newData;
    QByteArray::size_type newUsedData = 0;
    // Compact only elements that have byte data.
    // Nested containers will be compacted when their data changes.
    for (auto &e : elements) {
        if (e.flags & Element::HasByteData) {
            if (const ByteData *b = byteData(e))
                e.value = addByteDataImpl(newData, newUsedData, b->byte(), b->len);
        }
    }
    data = newData;
    usedData = newUsedData;
}

QCborContainerPrivate *QCborContainerPrivate::clone(QCborContainerPrivate *d, qsizetype reserved)
{
    if (!d) {
        d = new QCborContainerPrivate;
    } else {
        // in case QList::reserve throws
        QExplicitlySharedDataPointer u(new QCborContainerPrivate(*d));
        if (reserved >= 0) {
            u->elements.reserve(reserved);
            u->compact();
        }

        d = u.take();
        d->ref.storeRelaxed(0);

        for (auto &e : std::as_const(d->elements)) {
            if (e.flags & Element::IsContainer)
                e.container->ref.ref();
        }
    }
    return d;
}

QCborContainerPrivate *QCborContainerPrivate::detach(QCborContainerPrivate *d, qsizetype reserved)
{
    if (!d || d->ref.loadRelaxed() != 1)
        return clone(d, reserved);
    return d;
}

/*!
  Prepare for an insertion at position \a index

  Detaches and ensures there are at least index entries in the array, padding
  with Undefined as needed.
*/
QCborContainerPrivate *QCborContainerPrivate::grow(QCborContainerPrivate *d, qsizetype index)
{
    Q_ASSERT(index >= 0);
    d = detach(d, index + 1);
    Q_ASSERT(d);
    qsizetype j = d->elements.size();
    while (j++ < index)
        d->append(Undefined());
    return d;
}

// Copies or moves \a value into element at position \a e. If \a disp is
// CopyContainer, then this function increases the reference count of the
// container, but otherwise leaves it unmodified. If \a disp is MoveContainer,
// then it transfers ownership (move semantics) and the caller must set
// value.container back to nullptr.
void QCborContainerPrivate::replaceAt_complex(Element &e, const QCborValue &value, ContainerDisposition disp)
{
    if (value.n < 0) {
        // This QCborValue is an array, map, or tagged value (container points
        // to itself).

        // detect self-assignment
        if (Q_UNLIKELY(this == value.container)) {
            Q_ASSERT(ref.loadRelaxed() >= 2);
            if (disp == MoveContainer)
                ref.deref();    // not deref() because it can't drop to 0
            QCborContainerPrivate *d = QCborContainerPrivate::clone(this);
            d->elements.detach();
            d->ref.storeRelaxed(1);
            e.container = d;
        } else {
            e.container = value.container;
            if (disp == CopyContainer)
                e.container->ref.ref();
        }

        e.type = value.type();
        e.flags = Element::IsContainer;
    } else {
        // String data, copy contents
        e = value.container->elements.at(value.n);

        // Copy string data, if any
        if (const ByteData *b = value.container->byteData(value.n)) {
            const auto flags = e.flags;
            // The element e has an invalid e.value, because it is copied from
            // value. It means that calling compact() will trigger an assertion
            // or just silently corrupt the data.
            // Temporarily unset the Element::HasByteData flag in order to skip
            // the element e in the call to compact().
            e.flags = e.flags & ~Element::HasByteData;
            if (this == value.container) {
                const QByteArray valueData = b->toByteArray();
                compact();
                e.value = addByteData(valueData, valueData.size());
            } else {
                compact();
                e.value = addByteData(b->byte(), b->len);
            }
            // restore the flags
            e.flags = flags;
        }

        if (disp == MoveContainer)
            value.container->deref();
    }
}

// in qstring.cpp
void qt_to_latin1_unchecked(uchar *dst, const char16_t *uc, qsizetype len);

Q_NEVER_INLINE void QCborContainerPrivate::appendAsciiString(QStringView s)
{
    qsizetype len = s.size();
    QtCbor::Element e;
    e.value = addByteData(nullptr, len);
    e.type = QCborValue::String;
    e.flags = Element::HasByteData | Element::StringIsAscii;
    elements.append(e);

    char *ptr = data.data() + e.value + sizeof(ByteData);
    uchar *l = reinterpret_cast<uchar *>(ptr);
    qt_to_latin1_unchecked(l, s.utf16(), len);
}

void QCborContainerPrivate::appendNonAsciiString(QStringView s)
{
    appendByteData(reinterpret_cast<const char *>(s.utf16()), s.size() * 2,
                   QCborValue::String, QtCbor::Element::StringIsUtf16);
}

QCborValue QCborContainerPrivate::extractAt_complex(Element e)
{
    // create a new container for the returned value, containing the byte data
    // from this element, if it's worth it
    Q_ASSERT(e.flags & Element::HasByteData);
    auto b = byteData(e);
    auto container = new QCborContainerPrivate;

    if (b->len + qsizetype(sizeof(*b)) < data.size() / 4) {
        // make a shallow copy of the byte data
        container->appendByteData(b->byte(), b->len, e.type, e.flags);
        usedData -= b->len + qsizetype(sizeof(*b));
        compact();
    } else {
        // just share with the original byte data
        container->data = data;
        container->elements.reserve(1);
        container->elements.append(e);
    }

    return makeValue(e.type, 0, container);
}

// Similar to QStringIterator::next() but returns malformed surrogate pair
// itself when one is detected, and returns the length in UTF-8.
static auto nextUtf32Character(const char16_t *&ptr, const char16_t *end) noexcept
{
    Q_ASSERT(ptr != end);
    struct R {
        char32_t c;
        qsizetype len = 1;  // in UTF-8 code units (bytes)
    } r = { *ptr++ };

    if (r.c < 0x0800) {
        if (r.c >= 0x0080)
            ++r.len;
    } else if (!QChar::isHighSurrogate(r.c) || ptr == end) {
        r.len += 2;
    } else {
        r.len += 3;
        r.c = QChar::surrogateToUcs4(r.c, *ptr++);
    }

    return r;
}

static qsizetype stringLengthInUtf8(const char16_t *ptr, const char16_t *end) noexcept
{
    qsizetype len = 0;
    while (ptr < end)
        len += nextUtf32Character(ptr, end).len;
    return len;
}

static int compareStringsInUtf8(QStringView lhs, QStringView rhs, Comparison mode) noexcept
{
    if (mode == Comparison::ForEquality)
        return lhs == rhs ? 0 : 1;

    // The UTF-16 length is *usually* comparable, but not always. There are
    // pathological cases where they can be wrong, so we need to compare as if
    // we were doing it in UTF-8. That includes the case of UTF-16 surrogate
    // pairs, because qstring.cpp sorts them before U+E000-U+FFFF.
    int diff = 0;
    qsizetype len1 = 0;
    qsizetype len2 = 0;
    const char16_t *src1 = lhs.utf16();
    const char16_t *src2 = rhs.utf16();
    const char16_t *end1 = src1 + lhs.size();
    const char16_t *end2 = src2 + rhs.size();

    // first, scan until we find a difference (if any)
    do {
        auto r1 = nextUtf32Character(src1, end1);
        auto r2 = nextUtf32Character(src2, end2);
        len1 += r1.len;
        len2 += r2.len;
        diff = int(r1.c) - int(r2.c);       // no underflow due to limited range
    } while (src1 < end1 && src2 < end2 && diff == 0);

    // compute the full length past this first difference
    len1 += stringLengthInUtf8(src1, end1);
    len2 += stringLengthInUtf8(src2, end2);
    if (len1 == len2)
        return diff;
    return len1 < len2 ? -1 : 1;
}

static int compareStringsInUtf8(QUtf8StringView lhs, QStringView rhs, Comparison mode) noexcept
{
    // CBOR requires that the shortest of the two strings be sorted first, so
    // we have to calculate the UTF-8 length of the UTF-16 string while
    // comparing. Unlike the UTF-32 comparison above, we convert the UTF-16
    // string to UTF-8 so we only need to decode one string.

    const qsizetype len1 = lhs.size();
    const auto src1 = reinterpret_cast<const uchar *>(lhs.data());
    const char16_t *src2 = rhs.utf16();
    const char16_t *const end2 = src2 + rhs.size();

    // Compare the two strings until we find a difference.
    int diff = 0;
    qptrdiff idx1 = 0;
    qsizetype len2 = 0;
    do {
        uchar utf8[4];      // longest possible Unicode character in UTF-8
        uchar *ptr = utf8;
        char16_t uc = *src2++;
        int r = QUtf8Functions::toUtf8<QUtf8BaseTraits>(uc, ptr, src2, end2);
        Q_UNUSED(r);    // ignore failure to encode proper UTF-16 surrogates

        qptrdiff n = ptr - utf8;
        len2 += n;
        if (len1 - idx1 < n)
            return -1;      // lhs is definitely shorter
        diff = memcmp(src1 + idx1, utf8, n);
        idx1 += n;
    } while (diff == 0 && idx1 < len1 && src2 < end2);

    if (mode == Comparison::ForEquality && diff)
        return diff;
    if ((idx1 == len1) != (src2 == end2)) {
        // One of the strings ended earlier than the other
        return idx1 == len1 ? -1 : 1;
    }

    // We found a difference and neither string ended, so continue calculating
    // the UTF-8 length of rhs.
    len2 += stringLengthInUtf8(src2, end2);

    if (len1 != len2)
        return len1 < len2 ? -1 : 1;
    return diff;
}

static int compareStringsInUtf8(QStringView lhs, QUtf8StringView rhs, Comparison mode) noexcept
{
    return -compareStringsInUtf8(rhs, lhs, mode);
}

QT_WARNING_DISABLE_MSVC(4146)   // unary minus operator applied to unsigned type, result still unsigned
static int compareContainer(const QCborContainerPrivate *c1, const QCborContainerPrivate *c2,
                            Comparison mode) noexcept;
static int compareElementNoData(const Element &e1, const Element &e2) noexcept
{
    Q_ASSERT(e1.type == e2.type);

    if (e1.type == QCborValue::Integer) {
        // CBOR sorting order is 0, 1, 2, ..., INT64_MAX, -1, -2, -3, ... INT64_MIN
        // So we transform:
        //  0           ->      0
        //  1           ->      1
        //  INT64_MAX   ->      INT64_MAX
        //  -1          ->      INT64_MAX + 1 = INT64_MAX - (-1)
        //  -2          ->      INT64_MAX + 2 = INT64_MAX - (-2)
        //  INT64_MIN   ->      UINT64_MAX = INT64_MAX - INT64_MIN
        // Note how the unsigned arithmetic is well defined in C++ (it's
        // always performed modulo 2^64).
        auto makeSortable = [](qint64 v) {
            quint64 u = quint64(v);
            if (v < 0)
                return quint64(std::numeric_limits<qint64>::max()) + (-u);
            return u;
        };
        quint64 u1 = makeSortable(e1.value);
        quint64 u2 = makeSortable(e2.value);
        if (u1 < u2)
            return -1;
        if (u1 > u2)
            return 1;
    }

    if (e1.type == QCborValue::Tag || e1.type == QCborValue::Double) {
        // Perform unsigned comparisons for the tag value and floating point
        quint64 u1 = quint64(e1.value);
        quint64 u2 = quint64(e2.value);
        if (u1 != u2)
            return u1 < u2 ? -1 : 1;
    }

    // Any other type is equal at this point:
    // - simple types carry no value
    // - empty strings, arrays and maps
    return 0;
}

static int compareElementRecursive(const QCborContainerPrivate *c1, const Element &e1,
                                   const QCborContainerPrivate *c2, const Element &e2,
                                   Comparison mode) noexcept
{
    int cmp = typeOrder(e1.type, e2.type);
    if (cmp != 0)
        return cmp;

    if ((e1.flags & Element::IsContainer) || (e2.flags & Element::IsContainer))
        return compareContainer(e1.flags & Element::IsContainer ? e1.container : nullptr,
                                e2.flags & Element::IsContainer ? e2.container : nullptr, mode);

    // string data?
    const ByteData *b1 = c1 ? c1->byteData(e1) : nullptr;
    const ByteData *b2 = c2 ? c2->byteData(e2) : nullptr;
    if (b1 || b2) {
        auto len1 = b1 ? b1->len : 0;
        auto len2 = b2 ? b2->len : 0;
        if (len1 == 0 || len2 == 0)
            return len1 < len2 ? -1 : len1 == len2 ? 0 : 1;

        // we definitely have data from this point forward
        Q_ASSERT(b1);
        Q_ASSERT(b2);

        // Officially with CBOR, we sort first the string with the shortest
        // UTF-8 length. Since US-ASCII is just a subset of UTF-8, its length
        // is the UTF-8 length. But the UTF-16 length may not be directly
        // comparable.
        if ((e1.flags & Element::StringIsUtf16) && (e2.flags & Element::StringIsUtf16))
            return compareStringsInUtf8(b1->asStringView(), b2->asStringView(), mode);

        if (!(e1.flags & Element::StringIsUtf16) && !(e2.flags & Element::StringIsUtf16)) {
            // Neither is UTF-16, so lengths are comparable too
            // (this case includes byte arrays too)
            if (len1 == len2) {
                if (mode == Comparison::ForEquality) {
                    // GCC optimizes this to __memcmpeq(); Clang to bcmp()
                    return memcmp(b1->byte(), b2->byte(), size_t(len1)) == 0 ? 0 : 1;
                }
                return memcmp(b1->byte(), b2->byte(), size_t(len1));
            }
            return len1 < len2 ? -1 : 1;
        }

        // Only one is UTF-16
        if (e1.flags & Element::StringIsUtf16)
            return compareStringsInUtf8(b1->asStringView(), b2->asUtf8StringView(), mode);
        else
            return compareStringsInUtf8(b1->asUtf8StringView(), b2->asStringView(), mode);
    }

    return compareElementNoData(e1, e2);
}

static int compareContainer(const QCborContainerPrivate *c1, const QCborContainerPrivate *c2,
                            Comparison mode) noexcept
{
    auto len1 = c1 ? c1->elements.size() : 0;
    auto len2 = c2 ? c2->elements.size() : 0;
    if (len1 != len2) {
        // sort the shorter container first
        return len1 < len2 ? -1 : 1;
    }

    for (qsizetype i = 0; i < len1; ++i) {
        const Element &e1 = c1->elements.at(i);
        const Element &e2 = c2->elements.at(i);
        int cmp = compareElementRecursive(c1, e1, c2, e2, mode);
        if (cmp)
            return cmp;
    }

    return 0;
}

inline int QCborContainerPrivate::compareElement_helper(const QCborContainerPrivate *c1, Element e1,
                                                        const QCborContainerPrivate *c2, Element e2,
                                                        Comparison mode) noexcept
{
    return compareElementRecursive(c1, e1, c2, e2, mode);
}

/*!
    \fn bool QCborValue::operator==(const QCborValue &lhs, const QCborValue &rhs)

    Compares \a lhs and \a rhs, and returns true if they hold the same
    contents, false otherwise. If each QCborValue contains an array or map, the
    comparison is recursive to elements contained in them.

    For more information on CBOR equality in Qt, see, compare().

    \sa compare(), QCborValue::operator==(), QCborMap::operator==(),
        operator!=(), operator<()
 */

/*!
    \fn bool QCborValue::operator!=(const QCborValue &lhs, const QCborValue &rhs)

    Compares \a lhs and \a rhs, and returns true if contents differ,
    false otherwise. If each QCborValue contains an array or map, the comparison
    is recursive to elements contained in them.

    For more information on CBOR equality in Qt, see, QCborValue::compare().

    \sa compare(), QCborValue::operator==(), QCborMap::operator==(),
        operator==(), operator<()
 */
bool comparesEqual(const QCborValue &lhs,
                   const QCborValue &rhs) noexcept
{
    Element e1 = QCborContainerPrivate::elementFromValue(lhs);
    Element e2 = QCborContainerPrivate::elementFromValue(rhs);
    return compareElementRecursive(lhs.container, e1, rhs.container, e2,
                                   Comparison::ForEquality) == 0;
}

/*!
    \fn bool QCborValue::operator<(const QCborValue &lhs, const QCborValue &rhs)

    Compares \a lhs and \a rhs, and returns true if \a lhs should be
    sorted before \a rhs, false otherwise. If each QCborValue contains an
    array or map, the comparison is recursive to elements contained in them.

    For more information on CBOR sorting order, see QCborValue::compare().

    \sa compare(), QCborValue::operator==(), QCborMap::operator==(),
        operator==(), operator!=()
 */

/*!
    \fn bool QCborValue::operator<=(const QCborValue &lhs, const QCborValue &rhs)

    Compares \a lhs and \a rhs, and returns true if \a lhs should be
    sorted before \a rhs or is being equal to \a rhs, false otherwise.
    If each QCborValue contains an array or map, the comparison is recursive
    to elements contained in them.

    For more information on CBOR sorting order, see QCborValue::compare().

    \sa compare(), QCborValue::operator<(), QCborMap::operator==(),
        operator==(), operator!=()
*/

/*!
    \fn bool QCborValue::operator>(const QCborValue &lhs, const QCborValue &rhs)

    Compares \a lhs and \a rhs, and returns true if \a lhs should be
    sorted after \a rhs, false otherwise. If each QCborValue contains an
    array or map, the comparison is recursive to elements contained in them.

    For more information on CBOR sorting order, see QCborValue::compare().

    \sa compare(), QCborValue::operator>=(), QCborMap::operator==(),
        operator==(), operator!=()
*/

/*!
    \fn bool QCborValue::operator>=(const QCborValue &lhs, const QCborValue &rhs)

    Compares \a lhs and \a rhs, and returns true if \a lhs should be
    sorted after \a rhs or is being equal to \a rhs, false otherwise.
    If each QCborValue contains an array or map, the comparison is recursive
    to elements contained in them.

    For more information on CBOR sorting order, see QCborValue::compare().

    \sa compare(), QCborValue::operator>(), QCborMap::operator==(),
        operator==(), operator!=()
*/

/*!
    Compares this value and \a other, and returns an integer that indicates
    whether this value should be sorted prior to (if the result is negative) or
    after \a other (if the result is positive). If this function returns 0, the
    two values are equal and hold the same contents.

    If each QCborValue contains an array or map, the comparison is recursive to
    elements contained in them.

    \section3 Extended types

    QCborValue compares equal a QCborValue containing an extended type, like
    \l{Type}{Url} and \l{Type}{Url} and its equivalent tagged representation.
    So, for example, the following expression is true:

    \snippet code/src_corelib_serialization_qcborvalue.cpp 3

    Do note that Qt types like \l QUrl and \l QDateTime will normalize and
    otherwise modify their arguments. The expression above is true only because
    the string on the right side is the normalized value that the QCborValue on
    the left would take. If, for example, the "https" part were uppercase in
    both sides, the comparison would fail. For information on normalizations
    performed by QCborValue, please consult the documentation of the
    constructor taking the Qt type in question.

    \section3 Sorting order

    Sorting order in CBOR is defined in
    \l{RFC 7049, section 3.9}, which
    discusses the sorting of keys in a map when following the Canonical
    encoding. According to the specification, "sorting is performed on the
    bytes of the representation of the key data items" and lists as
    consequences that:

    \list
      \li "If two keys have different lengths, the shorter one sorts earlier;"
      \li "If two keys have the same length, the one with the lower value in
          (byte-wise) lexical order sorts earlier."
    \endlist

    This results in surprising sorting of QCborValues, where the result of this
    function is different from that which would later be retrieved by comparing the
    contained elements. For example, the QCborValue containing string "zzz"
    sorts before the QCborValue with string "foobar", even though when
    comparing as \l{QString::compare()}{QStrings} or
    \l{QByteArray}{QByteArrays} the "zzz" sorts after "foobar"
    (dictionary order).

    The specification does not clearly indicate what sorting order should be
    done for values of different types (it says sorting should not pay
    "attention to the 3/5 bit splitting for major types"). QCborValue makes the
    assumption that types should be sorted too. The numeric values of the
    QCborValue::Type enumeration are in that order, with the exception of the
    extended types, which compare as their tagged equivalents.

    \note Sorting order is preliminary and is subject to change. Applications
    should not depend on the order returned by this function for the time
    being.

    \sa QCborArray::compare(), QCborMap::compare(), operator==()
 */
int QCborValue::compare(const QCborValue &other) const
{
    Element e1 = QCborContainerPrivate::elementFromValue(*this);
    Element e2 = QCborContainerPrivate::elementFromValue(other);
    return compareElementRecursive(container, e1, other.container, e2, Comparison::ForOrdering);
}

bool comparesEqual(const QCborArray &lhs, const QCborArray &rhs) noexcept
{
    return compareContainer(lhs.d.constData(), rhs.d.constData(), Comparison::ForEquality) == 0;
}

int QCborArray::compare(const QCborArray &other) const noexcept
{
    return compareContainer(d.data(), other.d.data(), Comparison::ForOrdering);
}

bool QCborArray::comparesEqual_helper(const QCborArray &lhs, const QCborValue &rhs) noexcept
{
    if (typeOrder(QCborValue::Array, rhs.type()))
        return false;
    return compareContainer(lhs.d.constData(), rhs.container, Comparison::ForEquality) == 0;
}

Qt::strong_ordering
QCborArray::compareThreeWay_helper(const QCborArray &lhs, const QCborValue &rhs) noexcept
{
    int c = typeOrder(QCborValue::Array, rhs.type());
    if (c == 0)
        c = compareContainer(lhs.d.constData(), rhs.container, Comparison::ForOrdering);
    return Qt::compareThreeWay(c, 0);
}

bool comparesEqual(const QCborMap &lhs, const QCborMap &rhs) noexcept
{
    return compareContainer(lhs.d.constData(), rhs.d.constData(), Comparison::ForEquality) == 0;
}

int QCborMap::compare(const QCborMap &other) const noexcept
{
    return compareContainer(d.data(), other.d.data(), Comparison::ForOrdering);
}

bool QCborMap::comparesEqual_helper(const QCborMap &lhs, const QCborValue &rhs) noexcept
{
    if (typeOrder(QCborValue::Map, rhs.type()))
        return false;
    return compareContainer(lhs.d.constData(), rhs.container, Comparison::ForEquality) == 0;
}

Qt::strong_ordering
QCborMap::compareThreeWay_helper(const QCborMap &lhs, const QCborValue &rhs) noexcept
{
    int c = typeOrder(QCborValue::Map, rhs.type());
    if (c == 0)
        c = compareContainer(lhs.d.constData(), rhs.container, Comparison::ForOrdering);
    return Qt::compareThreeWay(c, 0);
}

#if QT_CONFIG(cborstreamwriter)
static void encodeToCbor(QCborStreamWriter &writer, const QCborContainerPrivate *d, qsizetype idx,
                         QCborValue::EncodingOptions opt)
{
    if (idx == -QCborValue::Array || idx == -QCborValue::Map) {
        bool isArray = (idx == -QCborValue::Array);
        qsizetype len = d ? d->elements.size() : 0;
        if (isArray)
            writer.startArray(quint64(len));
        else
            writer.startMap(quint64(len) / 2);

        for (idx = 0; idx < len; ++idx)
            encodeToCbor(writer, d, idx, opt);

        if (isArray)
            writer.endArray();
        else
            writer.endMap();
    } else if (idx < 0) {
        Q_ASSERT_X(d != nullptr, "QCborValue", "Unexpected null container");
        if (d->elements.size() != 2) {
            // invalid state!
            qWarning("QCborValue: invalid tag state; are you encoding something that was improperly decoded?");
            return;
        }

        // write the tag and the tagged element
        writer.append(QCborTag(d->elements.at(0).value));
        encodeToCbor(writer, d, 1, opt);
    } else {
        Q_ASSERT_X(d != nullptr, "QCborValue", "Unexpected null container");
        // just one element
        auto e = d->elements.at(idx);
        const ByteData *b = d->byteData(idx);
        switch (e.type) {
        case QCborValue::Integer:
            return writer.append(qint64(e.value));

        case QCborValue::ByteArray:
            if (b)
                return writer.appendByteString(b->byte(), b->len);
            return writer.appendByteString("", 0);

        case QCborValue::String:
            if (b) {
                if (e.flags & Element::StringIsUtf16)
                    return writer.append(b->asStringView());
                return writer.appendTextString(b->byte(), b->len);
            }
            return writer.append(QLatin1StringView());

        case QCborValue::Array:
        case QCborValue::Map:
        case QCborValue::Tag:
            // recurse
            return encodeToCbor(writer,
                                e.flags & Element::IsContainer ? e.container : nullptr,
                                -qsizetype(e.type), opt);

        case QCborValue::SimpleType:
        case QCborValue::False:
        case QCborValue::True:
        case QCborValue::Null:
        case QCborValue::Undefined:
            break;

        case QCborValue::Double:
            return writeDoubleToCbor(writer, e.fpvalue(), opt);

        case QCborValue::Invalid:
            return;

        case QCborValue::DateTime:
        case QCborValue::Url:
        case QCborValue::RegularExpression:
        case QCborValue::Uuid:
            // recurse as tag
            return encodeToCbor(writer, e.container, -QCborValue::Tag, opt);
        }

        // maybe it's a simple type
        int simpleType = e.type - QCborValue::SimpleType;
        if (unsigned(simpleType) < 0x100)
            return writer.append(QCborSimpleType(simpleType));

        // if we got here, we've got an unknown type
        qWarning("QCborValue: found unknown type 0x%x", e.type);
    }
}
#endif // QT_CONFIG(cborstreamwriter)

#if QT_CONFIG(cborstreamreader)
// confirm that our basic Types match QCborStreamReader::Types
static_assert(int(QCborValue::Integer) == int(QCborStreamReader::UnsignedInteger));
static_assert(int(QCborValue::ByteArray) == int(QCborStreamReader::ByteArray));
static_assert(int(QCborValue::String) == int(QCborStreamReader::String));
static_assert(int(QCborValue::Array) == int(QCborStreamReader::Array));
static_assert(int(QCborValue::Map) == int(QCborStreamReader::Map));
static_assert(int(QCborValue::Tag) == int(QCborStreamReader::Tag));

static inline double integerOutOfRange(const QCborStreamReader &reader)
{
    Q_ASSERT(reader.isInteger());
    if (reader.isUnsignedInteger()) {
        quint64 v = reader.toUnsignedInteger();
        if (qint64(v) < 0)
            return double(v);
    } else {
        quint64 v = quint64(reader.toNegativeInteger());
        if (qint64(v - 1) < 0)
            return -double(v);
    }

    // result is in range
    return 0;
}

static Element decodeBasicValueFromCbor(QCborStreamReader &reader)
{
    Element e = {};

    switch (reader.type()) {
    case QCborStreamReader::UnsignedInteger:
    case QCborStreamReader::NegativeInteger:
        if (double d = integerOutOfRange(reader)) {
            e.type = QCborValue::Double;
            qToUnaligned(d, &e.value);
        } else {
            e.type = QCborValue::Integer;
            e.value = reader.toInteger();
        }
        break;
    case QCborStreamReader::SimpleType:
        e.type = QCborValue::Type(quint8(reader.toSimpleType()) + 0x100);
        break;
    case QCborStreamReader::Float16:
        e.type = QCborValue::Double;
        qToUnaligned(double(reader.toFloat16()), &e.value);
        break;
    case QCborStreamReader::Float:
        e.type = QCborValue::Double;
        qToUnaligned(double(reader.toFloat()), &e.value);
        break;
    case QCborStreamReader::Double:
        e.type = QCborValue::Double;
        qToUnaligned(reader.toDouble(), &e.value);
        break;

    default:
        Q_UNREACHABLE();
    }

    reader.next();
    return e;
}

// Clamp allocation to avoid crashing due to corrupt stream. This also
// ensures we never overflow qsizetype. The returned length is doubled for Map
// entries to account for key-value pairs.
static qsizetype clampedContainerLength(const QCborStreamReader &reader)
{
    if (!reader.isLengthKnown())
        return 0;
    int mapShift = reader.isMap() ? 1 : 0;
    quint64 shiftedMaxElements = MaximumPreallocatedElementCount >> mapShift;
    qsizetype len = qsizetype(qMin(reader.length(), shiftedMaxElements));
    return len << mapShift;
}

static inline QCborContainerPrivate *createContainerFromCbor(QCborStreamReader &reader, int remainingRecursionDepth)
{
    if (Q_UNLIKELY(remainingRecursionDepth == 0)) {
        QCborContainerPrivate::setErrorInReader(reader, { QCborError::NestingTooDeep });
        return nullptr;
    }

    QCborContainerPrivate *d = nullptr;
    {
        // in case QList::reserve throws
        QExplicitlySharedDataPointer u(new QCborContainerPrivate);
        if (qsizetype len = clampedContainerLength(reader))
            u->elements.reserve(len);
        d = u.take();
    }

    reader.enterContainer();
    if (reader.lastError() != QCborError::NoError) {
        d->elements.clear();
        return d;
    }

    while (reader.hasNext() && reader.lastError() == QCborError::NoError)
        d->decodeValueFromCbor(reader, remainingRecursionDepth - 1);

    if (reader.lastError() == QCborError::NoError)
        reader.leaveContainer();
    else
        d->elements.squeeze();

    return d;
}

static QCborValue taggedValueFromCbor(QCborStreamReader &reader, int remainingRecursionDepth)
{
    if (Q_UNLIKELY(remainingRecursionDepth == 0)) {
        QCborContainerPrivate::setErrorInReader(reader, { QCborError::NestingTooDeep });
        return QCborValue::Invalid;
    }

    auto d = new QCborContainerPrivate;
    d->append(reader.toTag());
    reader.next();

    if (reader.lastError() == QCborError::NoError) {
        // decode tagged value
        d->decodeValueFromCbor(reader, remainingRecursionDepth - 1);
    }

    QCborValue::Type type;
    if (reader.lastError() == QCborError::NoError) {
        // post-process to create our extended types
        type = convertToExtendedType(d);
    } else {
        // decoding error
        type = QCborValue::Invalid;
    }

    // note: may return invalid state!
    return QCborContainerPrivate::makeValue(type, -1, d);
}

// in qcborstream.cpp
extern void qt_cbor_stream_set_error(QCborStreamReaderPrivate *d, QCborError error);
inline void QCborContainerPrivate::setErrorInReader(QCborStreamReader &reader, QCborError error)
{
    qt_cbor_stream_set_error(reader.d.get(), error);
}

extern QCborStreamReader::StringResultCode qt_cbor_append_string_chunk(QCborStreamReader &reader, QByteArray *data);

void QCborContainerPrivate::decodeStringFromCbor(QCborStreamReader &reader)
{
    if (reader.lastError() != QCborError::NoError)
        return;

    qsizetype rawlen = reader.currentStringChunkSize();
    QByteArray::size_type len = rawlen;
    if (rawlen < 0)
        return;                     // error
    if (len != rawlen) {
        // truncation
        setErrorInReader(reader, { QCborError::DataTooLarge });
        return;
    }

    auto resetSize = qScopeGuard([this, oldSize = data.size()] {
        data.resize(oldSize);
        if (oldSize < data.capacity() / 2)
            data.squeeze();
    });

    Element e = {};
    e.type = QCborValue::Type(reader.type());
    if (len || !reader.isLengthKnown()) {
        // The use of size_t means none of the operations here can overflow because
        // all inputs are less than half SIZE_MAX.
        constexpr size_t EstimatedOverhead = 16;
        constexpr size_t MaxMemoryIncrement = 16384;
        size_t offset = data.size();

        // add space for aligned ByteData (this can't overflow)
        offset += sizeof(QtCbor::ByteData) + alignof(QtCbor::ByteData);
        offset &= ~(alignof(QtCbor::ByteData) - 1);
        if (offset > size_t(QByteArray::maxSize())) {
            // overflow
            setErrorInReader(reader, { QCborError::DataTooLarge });
            return;
        }

        // and calculate the size we want to have
        size_t newCapacity = offset + len;          // can't overflow
        if (size_t(len) > MaxMemoryIncrement - EstimatedOverhead) {
            // there's a non-zero chance that we won't need this memory at all,
            // so capa how much we allocate
            newCapacity = offset + MaxMemoryIncrement - EstimatedOverhead;
        }
        if (newCapacity > size_t(QByteArray::maxSize())) {
            // this may cause an allocation failure
            newCapacity = QByteArray::maxSize();
        }
        if (newCapacity > size_t(data.capacity()))
            data.reserve(newCapacity);
        data.resize(offset + sizeof(QtCbor::ByteData));
        e.value = offset;
        e.flags = Element::HasByteData;
    }

    // read chunks
    bool isAscii = (e.type == QCborValue::String);
    QCborStreamReader::StringResultCode status = qt_cbor_append_string_chunk(reader, &data);
    while (status == QCborStreamReader::Ok) {
        if (e.type == QCborValue::String && len) {
            // verify UTF-8 string validity
            auto utf8result = QUtf8::isValidUtf8(QByteArrayView(data).last(len));
            if (!utf8result.isValidUtf8) {
                setErrorInReader(reader, { QCborError::InvalidUtf8String });
                return;
            }
            isAscii = isAscii && utf8result.isValidAscii;
        }

        rawlen = reader.currentStringChunkSize();
        len = rawlen;
        if (len == rawlen) {
            status = qt_cbor_append_string_chunk(reader, &data);
        } else {
            // error
            setErrorInReader(reader, { QCborError::DataTooLarge });
            return;
        }
    }

    // update size
    if (status == QCborStreamReader::EndOfString && e.flags & Element::HasByteData) {
        Q_ASSERT(data.isDetached());
        const char *ptr = data.constData() + e.value;
        auto b = new (const_cast<char *>(ptr)) ByteData;
        b->len = data.size() - e.value - int(sizeof(*b));
        usedData += b->len;

        if (isAscii) {
            // set the flag if it is US-ASCII only (as it often is)
            Q_ASSERT(e.type == QCborValue::String);
            e.flags |= Element::StringIsAscii;
        }

        // check that this UTF-8 text string can be loaded onto a QString
        if (e.type == QCborValue::String) {
            if (Q_UNLIKELY(b->len > QString::maxSize())) {
                setErrorInReader(reader, { QCborError::DataTooLarge });
                return;
            }
        }
    }

    if (status == QCborStreamReader::EndOfString) {
        elements.append(e);
        resetSize.dismiss();
    }
}

void QCborContainerPrivate::decodeValueFromCbor(QCborStreamReader &reader, int remainingRecursionDepth)
{
    QCborStreamReader::Type t = reader.type();
    switch (t) {
    case QCborStreamReader::UnsignedInteger:
    case QCborStreamReader::NegativeInteger:
    case QCborStreamReader::SimpleType:
    case QCborStreamReader::Float16:
    case QCborStreamReader::Float:
    case QCborStreamReader::Double:
        elements.append(decodeBasicValueFromCbor(reader));
        break;

    case QCborStreamReader::ByteArray:
    case QCborStreamReader::String:
        decodeStringFromCbor(reader);
        break;

    case QCborStreamReader::Array:
    case QCborStreamReader::Map:
        return append(makeValue(t == QCborStreamReader::Array ? QCborValue::Array : QCborValue::Map, -1,
                                createContainerFromCbor(reader, remainingRecursionDepth),
                                MoveContainer));

    case QCborStreamReader::Tag:
        return append(taggedValueFromCbor(reader, remainingRecursionDepth));

    case QCborStreamReader::Invalid:
        return;                 // probably a decode error
    }
}
#endif // QT_CONFIG(cborstreamreader)

/*!
    Creates a QCborValue with byte array value \a ba. The value can later be
    retrieved using toByteArray().

    \sa toByteArray(), isByteArray(), isString()
 */
QCborValue::QCborValue(const QByteArray &ba)
    : n(0), container(new QCborContainerPrivate), t(ByteArray)
{
    container->appendByteData(ba.constData(), ba.size(), t);
    container->ref.storeRelaxed(1);
}

/*!
    Creates a QCborValue with string value \a s. The value can later be
    retrieved using toString().

    \sa toString(), isString(), isByteArray()
 */
QCborValue::QCborValue(const QString &s) : QCborValue(qToStringViewIgnoringNull(s)) {}

/*!
    Creates a QCborValue with string value \a s. The value can later be
    retrieved using toString().

    \sa toString(), isString(), isByteArray()
*/
QCborValue::QCborValue(QStringView s)
    : n(0), container(new QCborContainerPrivate), t(String)
{
    container->append(s);
    container->ref.storeRelaxed(1);
}

/*!
    \overload

    Creates a QCborValue with the Latin-1 string viewed by \a s.
    The value can later be retrieved using toString().

    \sa toString(), isString(), isByteArray()
 */
QCborValue::QCborValue(QLatin1StringView s)
    : n(0), container(new QCborContainerPrivate), t(String)
{
    container->append(s);
    container->ref.storeRelaxed(1);
}

/*!
    \fn QCborValue::QCborValue(const QCborArray &a)
    \fn QCborValue::QCborValue(QCborArray &&a)

    Creates a QCborValue with the array \a a. The array can later be retrieved
    using toArray().

    \sa toArray(), isArray(), isMap()
 */
QCborValue::QCborValue(const QCborArray &a)
    : n(-1), container(a.d.data()), t(Array)
{
    if (container)
        container->ref.ref();
}

/*!
    \fn QCborValue::QCborValue(const QCborMap &m)
    \fn QCborValue::QCborValue(QCborMap &&m)

    Creates a QCborValue with the map \a m. The map can later be retrieved
    using toMap().

    \sa toMap(), isMap(), isArray()
 */
QCborValue::QCborValue(const QCborMap &m)
    : n(-1), container(m.d.data()), t(Map)
{
    if (container)
        container->ref.ref();
}

/*!
    \fn QCborValue::QCborValue(QCborTag tag, const QCborValue &tv)
    \fn QCborValue::QCborValue(QCborKnownTags tag, const QCborValue &tv)

    Creates a QCborValue for the extended type represented by the tag value \a
    tag, tagging value \a tv. The tag can later be retrieved using tag() and
    the tagged value using taggedValue().

    \sa isTag(), tag(), taggedValue(), QCborKnownTags
 */
QCborValue::QCborValue(QCborTag tag, const QCborValue &tv)
    : n(-1), container(new QCborContainerPrivate), t(Tag)
{
    container->ref.storeRelaxed(1);
    container->append(tag);
    container->append(tv);
    t = convertToExtendedType(container);
}

/*!
    Copies the contents of \a other into this object.
 */
QCborValue::QCborValue(const QCborValue &other) noexcept
    : n(other.n), container(other.container), t(other.t)
{
    if (container)
        container->ref.ref();
}

#if QT_CONFIG(datestring)
/*!
    Creates a QCborValue object of the date/time extended type and containing
    the value represented by \a dt. The value can later be retrieved using
    toDateTime().

    The CBOR date/time types are extension types using tags: either a string
    (in ISO date format) tagged as a \l{QCborKnownTags}{DateTime} or a number
    (of seconds since the start of 1970, UTC) tagged as a
    \l{QCborKnownTags}{UnixTime_t}. When parsing CBOR streams, QCborValue will
    convert \l{QCborKnownTags}{UnixTime_t} to the string-based type.

    \sa toDateTime(), isDateTime(), taggedValue()
 */
QCborValue::QCborValue(const QDateTime &dt)
    : QCborValue(QCborKnownTags::DateTimeString, dt.toString(Qt::ISODateWithMs).toLatin1())
{
    // change types
    t = DateTime;
    container->elements[1].type = String;
}
#endif

#ifndef QT_BOOTSTRAPPED
/*!
    Creates a QCborValue object of the URL extended type and containing the
    value represented by \a url. The value can later be retrieved using toUrl().

    The CBOR URL type is an extended type represented by a string tagged as an
    \l{QCborKnownTags}{Url}.

    \sa toUrl(), isUrl(), taggedValue()
 */
QCborValue::QCborValue(const QUrl &url)
    : QCborValue(QCborKnownTags::Url, url.toString(QUrl::DecodeReserved).toUtf8())
{
    // change types
    t = Url;
    container->elements[1].type = String;
}

#if QT_CONFIG(regularexpression)
/*!
    Creates a QCborValue object of the regular expression pattern extended type
    and containing the value represented by \a rx. The value can later be retrieved
    using toRegularExpression().

    The CBOR regular expression type is an extended type represented by a
    string tagged as an \l{QCborKnownTags}{RegularExpression}. Note that CBOR
    regular expressions only store the patterns, so any flags that the
    QRegularExpression object may carry will be lost.

    \sa toRegularExpression(), isRegularExpression(), taggedValue()
 */
QCborValue::QCborValue(const QRegularExpression &rx)
    : QCborValue(QCborKnownTags::RegularExpression, rx.pattern())
{
    // change type
    t = RegularExpression;
}
#endif // QT_CONFIG(regularexpression)

/*!
    Creates a QCborValue object of the UUID extended type and containing the
    value represented by \a uuid. The value can later be retrieved using
    toUuid().

    The CBOR UUID type is an extended type represented by a byte array tagged
    as an \l{QCborKnownTags}{Uuid}.

    \sa toUuid(), isUuid(), taggedValue()
 */
QCborValue::QCborValue(const QUuid &uuid)
    : QCborValue(QCborKnownTags::Uuid, uuid.toRfc4122())
{
    // change our type
    t = Uuid;
}
#endif

// destructor
void QCborValue::dispose()
{
    container->deref();
}

/*!
    Replaces the contents of this QCborObject with a copy of \a other.
 */
QCborValue &QCborValue::operator=(const QCborValue &other) noexcept
{
    n = other.n;
    assignContainer(container, other.container);
    t = other.t;
    return *this;
}

/*!
    Returns the tag of this extended QCborValue object, if it is of the tag
    type, \a defaultValue otherwise.

    CBOR represents extended types by associating a number (the tag) with a
    stored representation. This function returns that number. To retrieve the
    representation, use taggedValue().

    \sa isTag(), taggedValue(), isDateTime(), isUrl(), isRegularExpression(), isUuid()
 */
QCborTag QCborValue::tag(QCborTag defaultValue) const
{
    return isTag() && container && container->elements.size() == 2 ?
                QCborTag(container->elements.at(0).value) : defaultValue;
}

/*!
    Returns the tagged value of this extended QCborValue object, if it is of
    the tag type, \a defaultValue otherwise.

    CBOR represents extended types by associating a number (the tag) with a
    stored representation. This function returns that representation. To
    retrieve the tag, use tag().

    \sa isTag(), tag(), isDateTime(), isUrl(), isRegularExpression(), isUuid()
 */
QCborValue QCborValue::taggedValue(const QCborValue &defaultValue) const
{
    return isTag() && container && container->elements.size() == 2 ?
                container->valueAt(1) : defaultValue;
}

/*!
    Returns the byte array value stored in this QCborValue, if it is of the byte
    array type. Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to
    QByteArray.

    \sa isByteArray(), isString(), toString()
 */
QByteArray QCborValue::toByteArray(const QByteArray &defaultValue) const
{
    if (!container || !isByteArray())
        return defaultValue;

    Q_ASSERT(n >= 0);
    return container->byteArrayAt(n);
}

/*!
    Returns the string value stored in this QCborValue, if it is of the string
    type. Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to
    QString.

    \sa isString(), isByteArray(), toByteArray()
 */
QString QCborValue::toString(const QString &defaultValue) const
{
    if (!container || !isString())
        return defaultValue;

    Q_ASSERT(n >= 0);
    return container->stringAt(n);
}

#if QT_CONFIG(datestring)
/*!
    Returns the date/time value stored in this QCborValue, if it is of the
    date/time extended type. Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to
    QDateTime.

    \sa isDateTime(), isTag(), taggedValue()
 */
QDateTime QCborValue::toDateTime(const QDateTime &defaultValue) const
{
    if (!container || !isDateTime() || container->elements.size() != 2)
        return defaultValue;

    Q_ASSERT(n == -1);
    const ByteData *byteData = container->byteData(1);
    if (!byteData)
        return defaultValue; // date/times are never empty, so this must be invalid

    // Our data must be US-ASCII.
    Q_ASSERT((container->elements.at(1).flags & Element::StringIsUtf16) == 0);
    return QDateTime::fromString(byteData->asLatin1(), Qt::ISODateWithMs);
}
#endif

#ifndef QT_BOOTSTRAPPED
/*!
    Returns the URL value stored in this QCborValue, if it is of the URL
    extended type. Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to QUrl.

    \sa isUrl(), isTag(), taggedValue()
 */
QUrl QCborValue::toUrl(const QUrl &defaultValue) const
{
    if (!container || !isUrl() || container->elements.size() != 2)
        return defaultValue;

    Q_ASSERT(n == -1);
    const ByteData *byteData = container->byteData(1);
    if (!byteData)
        return QUrl();  // valid, empty URL

    return QUrl::fromEncoded(byteData->asByteArrayView());
}

#if QT_CONFIG(regularexpression)
/*!
    Returns the regular expression value stored in this QCborValue, if it is of
    the regular expression pattern extended type. Otherwise, it returns \a
    defaultValue.

    Note that this function performs no conversion from other types to
    QRegularExpression.

    \sa isRegularExpression(), isTag(), taggedValue()
 */
QRegularExpression QCborValue::toRegularExpression(const QRegularExpression &defaultValue) const
{
    if (!container || !isRegularExpression() || container->elements.size() != 2)
        return defaultValue;

    Q_ASSERT(n == -1);
    return QRegularExpression(container->stringAt(1));
}
#endif // QT_CONFIG(regularexpression)

/*!
    Returns the UUID value stored in this QCborValue, if it is of the UUID
    extended type. Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to QUuid.

    \sa isUuid(), isTag(), taggedValue()
 */
QUuid QCborValue::toUuid(const QUuid &defaultValue) const
{
    if (!container || !isUuid() || container->elements.size() != 2)
        return defaultValue;

    Q_ASSERT(n == -1);
    const ByteData *byteData = container->byteData(1);
    if (!byteData)
        return defaultValue; // UUIDs must always be 16 bytes, so this must be invalid

    return QUuid::fromRfc4122(byteData->asByteArrayView());
}
#endif

/*!
    \fn QCborArray QCborValue::toArray() const
    \fn QCborArray QCborValue::toArray(const QCborArray &defaultValue) const

    Returns the array value stored in this QCborValue, if it is of the array
    type. Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to
    QCborArray.

    \sa isArray(), isByteArray(), isMap(), isContainer(), toMap()
 */

/*!
    \fn QCborArray QCborValueRef::toArray() const
    \fn QCborArray QCborValueRef::toArray(const QCborArray &defaultValue) const
    \internal

    Returns the array value stored in this QCborValue, if it is of the array
    type. Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to
    QCborArray.

    \sa isArray(), isByteArray(), isMap(), isContainer(), toMap()
 */
QCborArray QCborValue::toArray() const
{
    return toArray(QCborArray());
}

QCborArray QCborValue::toArray(const QCborArray &defaultValue) const
{
    if (!isArray())
        return defaultValue;
    QCborContainerPrivate *dd = nullptr;
    Q_ASSERT(n == -1 || container == nullptr);
    if (n < 0)
        dd = container;
    // return QCborArray(*dd); but that's UB if dd is nullptr
    return dd ? QCborArray(*dd) : QCborArray();
}

/*!
    \fn QCborMap QCborValue::toMap() const
    \fn QCborMap QCborValue::toMap(const QCborMap &defaultValue) const

    Returns the map value stored in this QCborValue, if it is of the map type.
    Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to
    QCborMap.

    \sa isMap(), isArray(), isContainer(), toArray()
 */

/*!
    \fn QCborMap QCborValueRef::toMap() const
    \fn QCborMap QCborValueRef::toMap(const QCborMap &defaultValue) const
    \internal

    Returns the map value stored in this QCborValue, if it is of the map type.
    Otherwise, it returns \a defaultValue.

    Note that this function performs no conversion from other types to
    QCborMap.

    \sa isMap(), isArray(), isContainer(), toArray()
 */
QCborMap QCborValue::toMap() const
{
    return toMap(QCborMap());
}

QCborMap QCborValue::toMap(const QCborMap &defaultValue) const
{
    if (!isMap())
        return defaultValue;
    QCborContainerPrivate *dd = nullptr;
    Q_ASSERT(n == -1 || container == nullptr);
    if (n < 0)
        dd = container;
    // return QCborMap(*dd); but that's UB if dd is nullptr
    return dd ? QCborMap(*dd) : QCborMap();
}

/*!
    If this QCborValue is a QCborMap, searches elements for the value whose key
    matches \a key. If there's no key matching \a key in the map or if this
    QCborValue object is not a map, returns the undefined value.

    This function is equivalent to:

    \snippet code/src_corelib_serialization_qcborvalue.cpp 4

    \sa operator[](qint64), QCborMap::operator[], QCborMap::value(),
        QCborMap::find()
 */
const QCborValue QCborValue::operator[](const QString &key) const
{
    return QCborContainerPrivate::findCborMapKey(*this, qToStringViewIgnoringNull(key));
}

/*!
    \overload

    If this QCborValue is a QCborMap, searches elements for the value whose key
    matches \a key. If there's no key matching \a key in the map or if this
    QCborValue object is not a map, returns the undefined value.

    This function is equivalent to:

    \snippet code/src_corelib_serialization_qcborvalue.cpp 5

    \sa operator[](qint64), QCborMap::operator[], QCborMap::value(),
        QCborMap::find()
 */
const QCborValue QCborValue::operator[](QLatin1StringView key) const
{
    return QCborContainerPrivate::findCborMapKey(*this, key);
}

/*!
    \overload

    If this QCborValue is a QCborMap, searches elements for the value whose key
    matches \a key. If this is a QCborArray, returns the element whose index is
    \a key. If there's no matching value in the array or map, or if this
    QCborValue object is not an array or map, returns the undefined value.

    \sa operator[], QCborMap::operator[], QCborMap::value(),
        QCborMap::find(), QCborArray::operator[], QCborArray::at()
 */
const QCborValue QCborValue::operator[](qint64 key) const
{
    if (isArray() && container && quint64(key) < quint64(container->elements.size()))
        return container->valueAt(key);
    return QCborContainerPrivate::findCborMapKey(*this, key);
}

static bool shouldArrayRemainArray(qint64 key, QCborValue::Type t, QCborContainerPrivate *container)
{
    constexpr qint64 LargeKey = 0x10000;
    if (t != QCborValue::Array)
        return false;
    if (key < 0)
        return false;           // negative keys can't be an array index
    if (key < LargeKey)
        return true;

    // Only convert to map if key is greater than array size + 1
    qsizetype currentSize = container ? container->elements.size() : 0;
    return key <= currentSize;
}

/*!
  \internal
 */
static void convertArrayToMap(QCborContainerPrivate *&array)
{
    if (Q_LIKELY(!array || array->elements.isEmpty()))
        return;

    // The Q_LIKELY and the qWarning mark the rest of this function as unlikely
    qWarning("Using CBOR array as map forced conversion");

    qsizetype size = array->elements.size();
    QCborContainerPrivate *map = QCborContainerPrivate::detach(array, size * 2);
    map->elements.resize(size * 2);

    // this may be an in-place copy, so we have to do it from the end
    auto dst = map->elements.begin();
    auto src = array->elements.constBegin();
    for (qsizetype i = size - 1; i >= 0; --i) {
        Q_ASSERT(src->type != QCborValue::Invalid);
        dst[i * 2 + 1] = src[i];
    }
    for (qsizetype i = 0; i < size; ++i)
        dst[i * 2] = { i, QCborValue::Integer };

    // update reference counts
    assignContainer(array, map);
}

/*!
  \internal
 */
static QCborContainerPrivate *maybeGrow(QCborContainerPrivate *container, qsizetype index)
{
    auto replace = QCborContainerPrivate::grow(container, index);
    Q_ASSERT(replace);
    if (replace->elements.size() == index)
        replace->append(Undefined());
    else
        Q_ASSERT(replace->elements.size() > index);
    return assignContainer(container, replace);
}

template <typename KeyType> inline QCborValueRef
QCborContainerPrivate::findOrAddMapKey(QCborValue &self, KeyType key)
{
    // we need a map, so convert if necessary
    if (self.isArray())
        convertArrayToMap(self.container);
    else if (!self.isMap())
        self = QCborValue(QCborValue::Map);
    self.t = QCborValue::Map;
    self.n = -1;

    QCborValueRef result = findOrAddMapKey<KeyType>(self.container, key);
    assignContainer(self.container, result.d);
    return result;
}

template<typename KeyType> QCborValueRef
QCborContainerPrivate::findOrAddMapKey(QCborValueRef self, KeyType key)
{
    auto &e = self.d->elements[self.i];

    // we need a map, so convert if necessary
    if (e.type == QCborValue::Array) {
        convertArrayToMap(e.container);
    } else if (e.type != QCborValue::Map) {
        if (e.flags & QtCbor::Element::IsContainer)
            e.container->deref();
        e.container = nullptr;
    }
    e.flags = QtCbor::Element::IsContainer;
    e.type = QCborValue::Map;

    QCborValueRef result = findOrAddMapKey<KeyType>(e.container, key);
    assignContainer(e.container, result.d);
    return result;
}

/*!
    Returns a QCborValueRef that can be used to read or modify the entry in
    this, as a map, with the given \a key. When this QCborValue is a QCborMap,
    this function is equivalent to the matching operator[] on that map.

    Before returning the reference: if this QCborValue was an array, it is first
    converted to a map (so that \c{map[i]} is \c{array[i]} for each index, \c i,
    with valid \c{array[i]}); otherwise, if it was not a map it will be
    over-written with an empty map.

    \sa operator[](qint64), QCborMap::operator[], QCborMap::value(),
        QCborMap::find()
 */
QCborValueRef QCborValue::operator[](const QString &key)
{
    return QCborContainerPrivate::findOrAddMapKey(*this, qToStringViewIgnoringNull(key));
}

/*!
    \overload

    Returns a QCborValueRef that can be used to read or modify the entry in
    this, as a map, with the given \a key. When this QCborValue is a QCborMap,
    this function is equivalent to the matching operator[] on that map.

    Before returning the reference: if this QCborValue was an array, it is first
    converted to a map (so that \c{map[i]} is \c{array[i]} for each index, \c i,
    with valid \c{array[i]}); otherwise, if it was not a map it will be
    over-written with an empty map.

    \sa operator[](qint64), QCborMap::operator[], QCborMap::value(),
        QCborMap::find()
 */
QCborValueRef QCborValue::operator[](QLatin1StringView key)
{
    return QCborContainerPrivate::findOrAddMapKey(*this, key);
}

/*!
    \overload

    Returns a QCborValueRef that can be used to read or modify the entry in
    this, as a map or array, with the given \a key. When this QCborValue is a
    QCborMap or, for 0 <= key < 0x10000, a QCborArray, this function is
    equivalent to the matching operator[] on that map or array.

    Before returning the reference: if this QCborValue was an array but the key
    is out of range, the array is first converted to a map (so that \c{map[i]}
    is \c{array[i]} for each index, \c i, with valid \c{array[i]}); otherwise,
    if it was not a map it will be over-written with an empty map.

    \sa operator[], QCborMap::operator[], QCborMap::value(),
        QCborMap::find(), QCborArray::operator[], QCborArray::at()
 */
QCborValueRef QCborValue::operator[](qint64 key)
{
    if (shouldArrayRemainArray(key, t, container)) {
        container = maybeGrow(container, key);
        return { container, qsizetype(key) };
    }
    return QCborContainerPrivate::findOrAddMapKey(*this, key);
}

#if QT_CONFIG(cborstreamreader)
/*!
    Decodes one item from the CBOR stream found in \a reader and returns the
    equivalent representation. This function is recursive: if the item is a map
    or array, it will decode all items found in that map or array, until the
    outermost object is finished.

    This function need not be used on the root element of a \l
    QCborStreamReader. For example, the following code illustrates how to skip
    the CBOR signature tag from the beginning of a file:

    \snippet code/src_corelib_serialization_qcborvalue.cpp 6

    The returned value may be partially complete and indistinguishable from a
    valid QCborValue even if the decoding failed. To determine if there was an
    error, check if \l{QCborStreamReader::lastError()}{reader.lastError()} is
    indicating an error condition. This function stops decoding immediately
    after the first error.

    \sa toCbor(), toDiagnosticNotation(), toVariant(), toJsonValue()
 */
QCborValue QCborValue::fromCbor(QCborStreamReader &reader)
{
    QCborValue result;
    auto t = reader.type();
    if (reader.lastError() != QCborError::NoError)
        t = QCborStreamReader::Invalid;

    switch (t) {
    // basic types, no container needed:
    case QCborStreamReader::UnsignedInteger:
    case QCborStreamReader::NegativeInteger:
    case QCborStreamReader::SimpleType:
    case QCborStreamReader::Float16:
    case QCborStreamReader::Float:
    case QCborStreamReader::Double: {
        Element e = decodeBasicValueFromCbor(reader);
        result.n = e.value;
        result.t = e.type;
        break;
    }

    case QCborStreamReader::Invalid:
        result.t = QCborValue::Invalid;
        break;              // probably a decode error

    // strings
    case QCborStreamReader::ByteArray:
    case QCborStreamReader::String:
        result.n = 0;
        result.t = reader.isString() ? String : ByteArray;
        result.container = new QCborContainerPrivate;
        result.container->ref.ref();
        result.container->decodeStringFromCbor(reader);
        break;

    // containers
    case QCborStreamReader::Array:
    case QCborStreamReader::Map:
        result.n = -1;
        result.t = reader.isArray() ? Array : Map;
        result.container = createContainerFromCbor(reader, MaximumRecursionDepth);
        break;

    // tag
    case QCborStreamReader::Tag:
        result = taggedValueFromCbor(reader, MaximumRecursionDepth);
        break;
    }

    return result;
}

/*!
    \overload

    Decodes one item from the CBOR stream found in the byte array \a ba and
    returns the equivalent representation. This function is recursive: if the
    item is a map or array, it will decode all items found in that map or
    array, until the outermost object is finished.

    This function stores the error state, if any, in the object pointed to by
    \a error, along with the offset of where the error occurred. If no error
    happened, it stores \l{QCborError}{NoError} in the error state and the
    number of bytes that it consumed (that is, it stores the offset for the
    first unused byte). Using that information makes it possible to parse
    further data that may exist in the same byte array.

    The returned value may be partially complete and indistinguishable from a
    valid QCborValue even if the decoding failed. To determine if there was an
    error, check if there was an error stored in \a error. This function stops
    decoding immediately after the first error.

    \sa toCbor(), toDiagnosticNotation(), toVariant(), toJsonValue()
 */
QCborValue QCborValue::fromCbor(const QByteArray &ba, QCborParserError *error)
{
    QCborStreamReader reader(ba);
    QCborValue result = fromCbor(reader);
    if (error) {
        error->error = reader.lastError();
        error->offset = reader.currentOffset();
    }
    return result;
}

/*!
    \fn QCborValue QCborValue::fromCbor(const char *data, qsizetype len, QCborParserError *error)
    \fn QCborValue QCborValue::fromCbor(const quint8 *data, qsizetype len, QCborParserError *error)
    \overload

    Converts \a len bytes of \a data to a QByteArray and then calls the
    overload of this function that accepts a QByteArray, also passing \a error,
    if provided.
*/
#endif // QT_CONFIG(cborstreamreader)

#if QT_CONFIG(cborstreamwriter)
/*!
    Encodes this QCborValue object to its CBOR representation, using the
    options specified in \a opt, and return the byte array containing that
    representation.

    This function will not fail, except if this QCborValue or any of the
    contained items, if this is a map or array, are invalid. Invalid types are
    not produced normally by the API, but can result from decoding errors.

    By default, this function performs no transformation on the values in the
    QCborValue, writing all floating point directly as double-precision (\c
    double) types. If the \l{EncodingOption}{UseFloat} option is specified, it
    will use single precision (\c float) for any floating point value for which
    there's no loss of precision in using that representation. That includes
    infinities and NaN values.

    Similarly, if \l{EncodingOption}{UseFloat16} is specified, this function
    will try to use half-precision (\c qfloat16) floating point if the
    conversion to that results in no loss of precision. This is always true for
    infinities and NaN.

    If \l{EncodingOption}{UseIntegers} is specified, it will use integers for
    any floating point value that contains an actual integer.

    \sa fromCbor(), fromVariant(), fromJsonValue()
 */
QByteArray QCborValue::toCbor(EncodingOptions opt) const
{
    QByteArray result;
    QCborStreamWriter writer(&result);
    toCbor(writer, opt);
    return result;
}

/*!
    \overload

    Encodes this QCborValue object to its CBOR representation, using the
    options specified in \a opt, to the writer specified by \a writer. The same
    writer can be used by multiple QCborValues, for example, in order to encode
    different elements in a larger array.

    This function will not fail, except if this QCborValue or any of the
    contained items, if this is a map or array, are invalid. Invalid types are
    not produced normally by the API, but can result from decoding errors.

    By default, this function performs no transformation on the values in the
    QCborValue, writing all floating point directly as double-precision
    (binary64) types. If the \l{EncodingOption}{UseFloat} option is
    specified, it will use single precision (binary32) for any floating point
    value for which there's no loss of precision in using that representation.
    That includes infinities and NaN values.

    Similarly, if \l{EncodingOption}{UseFloat16} is specified, this function
    will try to use half-precision (binary16) floating point if the conversion
    to that results in no loss of precision. This is always true for infinities
    and NaN.

    If \l{EncodingOption}{UseIntegers} is specified, it will use integers
    for any floating point value that contains an actual integer.

    \sa fromCbor(), fromVariant(), fromJsonValue()
 */
Q_NEVER_INLINE void QCborValue::toCbor(QCborStreamWriter &writer, EncodingOptions opt) const
{
    if (isContainer() || isTag())
        return encodeToCbor(writer, container, -type(), opt);
    if (container)
        return encodeToCbor(writer, container, n, opt);

    // very simple types
    if (isSimpleType())
        return writer.append(toSimpleType());

    switch (type()) {
    case Integer:
        return writer.append(n);

    case Double:
        return writeDoubleToCbor(writer, fp_helper(), opt);

    case Invalid:
        return;

    case SimpleType:
    case False:
    case True:
    case Null:
    case Undefined:
        // handled by "if (isSimpleType())"
        Q_UNREACHABLE();
        break;

    case ByteArray:
        // Byte array with no container is empty
        return writer.appendByteString("", 0);

    case String:
        // String with no container is empty
        return writer.appendTextString("", 0);

    case Array:
    case Map:
    case Tag:
        // handled by "if (isContainer() || isTag())"
        Q_UNREACHABLE();
        break;

    case DateTime:
    case Url:
    case RegularExpression:
    case Uuid:
        // not possible
        Q_UNREACHABLE();
        break;
    }
}

#  if QT_VERSION < QT_VERSION_CHECK(7, 0, 0) && !defined(QT_BOOTSTRAPPED)
void QCborValueRef::toCbor(QCborStreamWriter &writer, QCborValue::EncodingOptions opt)
{
    concrete().toCbor(writer, opt);
}
#  endif
#endif // QT_CONFIG(cborstreamwriter)

void QCborValueRef::assign(QCborValueRef that, const QCborValue &other)
{
    that.d->replaceAt(that.i, other);
}

void QCborValueRef::assign(QCborValueRef that, QCborValue &&other)
{
    that.d->replaceAt(that.i, other, QCborContainerPrivate::MoveContainer);
}

void QCborValueRef::assign(QCborValueRef that, const QCborValueRef other)
{
    // ### optimize?
    that = other.concrete();
}

bool QCborValueConstRef::concreteBoolean(QCborValueConstRef self, bool defaultValue) noexcept
{
    QtCbor::Element e = self.d->elements.at(self.i);
    if (e.type != QCborValue::False && e.type != QCborValue::True)
        return defaultValue;
    return e.type == QCborValue::True;
}

double QCborValueConstRef::concreteDouble(QCborValueConstRef self, double defaultValue) noexcept
{
    QtCbor::Element e = self.d->elements.at(self.i);
    if (e.type == QCborValue::Integer)
        return e.value;
    if (e.type != QCborValue::Double)
        return defaultValue;
    return e.fpvalue();
}

qint64 QCborValueConstRef::concreteIntegral(QCborValueConstRef self, qint64 defaultValue) noexcept
{
    QtCbor::Element e = self.d->elements.at(self.i);
    QCborValue::Type t = e.type;
    if (t == QCborValue::Double)
        return e.fpvalue();
    if (t != QCborValue::Integer)
        return defaultValue;
    return e.value;
}

QByteArray QCborValueConstRef::concreteByteArray(QCborValueConstRef self,
                                                 const QByteArray &defaultValue)
{
    QtCbor::Element e = self.d->elements.at(self.i);
    if (e.type != QCborValue::ByteArray)
        return defaultValue;
    return self.d->byteArrayAt(self.i);
}

QString QCborValueConstRef::concreteString(QCborValueConstRef self, const QString &defaultValue)
{
    QtCbor::Element e = self.d->elements.at(self.i);
    if (e.type != QCborValue::String)
        return defaultValue;
    return self.d->stringAt(self.i);
}

bool
QCborValueConstRef::comparesEqual_helper(QCborValueConstRef lhs, QCborValueConstRef rhs) noexcept
{
    QtCbor::Element e1 = lhs.d->elements.at(lhs.i);
    QtCbor::Element e2 = rhs.d->elements.at(rhs.i);
    return compareElementRecursive(lhs.d, e1, rhs.d, e2, Comparison::ForEquality) == 0;
}

Qt::strong_ordering
QCborValueConstRef::compareThreeWay_helper(QCborValueConstRef lhs, QCborValueConstRef rhs) noexcept
{
    QtCbor::Element e1 = lhs.d->elements.at(lhs.i);
    QtCbor::Element e2 = rhs.d->elements.at(rhs.i);
    int c = compareElementRecursive(lhs.d, e1, rhs.d, e2, Comparison::ForOrdering);
    return Qt::compareThreeWay(c, 0);
}

bool
QCborValueConstRef::comparesEqual_helper(QCborValueConstRef lhs, const QCborValue &rhs) noexcept
{
    QtCbor::Element e1 = lhs.d->elements.at(lhs.i);
    QtCbor::Element e2 = QCborContainerPrivate::elementFromValue(rhs);
    return compareElementRecursive(lhs.d, e1, rhs.container, e2, Comparison::ForEquality) == 0;
}

Qt::strong_ordering
QCborValueConstRef::compareThreeWay_helper(QCborValueConstRef lhs, const QCborValue &rhs) noexcept
{
    QtCbor::Element e1 = lhs.d->elements.at(lhs.i);
    QtCbor::Element e2 = QCborContainerPrivate::elementFromValue(rhs);
    int c = compareElementRecursive(lhs.d, e1, rhs.container, e2, Comparison::ForOrdering);
    return Qt::compareThreeWay(c, 0);
}

bool QCborArray::comparesEqual_helper(const QCborArray &lhs, QCborValueConstRef rhs) noexcept
{
    QtCbor::Element e2 = rhs.d->elements.at(rhs.i);
    if (typeOrder(QCborValue::Array, e2.type))
        return false;
    return compareContainer(lhs.d.constData(), e2.container, Comparison::ForEquality) == 0;
}

Qt::strong_ordering
QCborArray::compareThreeWay_helper(const QCborArray &lhs, QCborValueConstRef rhs) noexcept
{
    QtCbor::Element e2 = rhs.d->elements.at(rhs.i);
    int c = typeOrder(QCborValue::Array, e2.type);
    if (c == 0)
        c = compareContainer(lhs.d.constData(), e2.container, Comparison::ForOrdering);
    return Qt::compareThreeWay(c, 0);
}

bool QCborMap::comparesEqual_helper(const QCborMap &lhs, QCborValueConstRef rhs) noexcept
{
    QtCbor::Element e2 = rhs.d->elements.at(rhs.i);
    if (typeOrder(QCborValue::Array, e2.type))
        return false;
    return compareContainer(lhs.d.constData(), e2.container, Comparison::ForEquality) == 0;
}

Qt::strong_ordering
QCborMap::compareThreeWay_helper(const QCborMap &lhs, QCborValueConstRef rhs) noexcept
{
    QtCbor::Element e2 = rhs.d->elements.at(rhs.i);
    int c = typeOrder(QCborValue::Map, e2.type);
    if (c == 0)
        c = compareContainer(lhs.d.constData(), e2.container, Comparison::ForOrdering);
    return Qt::compareThreeWay(c, 0);
}

QCborValue QCborValueConstRef::concrete(QCborValueConstRef self) noexcept
{
    return self.d->valueAt(self.i);
}

QCborValue::Type QCborValueConstRef::concreteType(QCborValueConstRef self) noexcept
{
    return self.d->elements.at(self.i).type;
}

const QCborValue QCborValueConstRef::operator[](const QString &key) const
{
    const QCborValue item = d->valueAt(i);
    return item[key];
}

const QCborValue QCborValueConstRef::operator[](const QLatin1StringView key) const
{
    const QCborValue item = d->valueAt(i);
    return item[key];
}

const QCborValue QCborValueConstRef::operator[](qint64 key) const
{
    const QCborValue item = d->valueAt(i);
    return item[key];
}

#if QT_VERSION < QT_VERSION_CHECK(7, 0, 0) && !defined(QT_BOOTSTRAPPED)
QCborValue QCborValueRef::concrete(QCborValueRef self) noexcept
{
    return self.d->valueAt(self.i);
}

QCborValue::Type QCborValueRef::concreteType(QCborValueRef self) noexcept
{
    return self.d->elements.at(self.i).type;
}

/*!
    If this QCborValueRef refers to a QCborMap, searches elements for the value
    whose key matches \a key. If there's no key matching \a key in the map or if
    this QCborValueRef object is not a map, returns the undefined value.

    This function is equivalent to:

    \code
      value.toMap().value(key);
    \endcode

    \sa operator[](qint64), QCborMap::operator[], QCborMap::value(),
        QCborMap::find()
 */
const QCborValue QCborValueRef::operator[](const QString &key) const
{
    return QCborValueConstRef::operator[](key);
}

/*!
    \overload

    If this QCborValueRef refers to a QCborMap, searches elements for the value
    whose key matches \a key. If there's no key matching \a key in the map or if
    this QCborValueRef object is not a map, returns the undefined value.

    This function is equivalent to:

    \code
      value.toMap().value(key);
    \endcode

    \sa operator[](qint64), QCborMap::operator[], QCborMap::value(),
        QCborMap::find()
 */
const QCborValue QCborValueRef::operator[](QLatin1StringView key) const
{
    return QCborValueConstRef::operator[](key);
}

/*!
   \overload

    If this QCborValueRef refers to a QCborMap, searches elements for the value
    whose key matches \a key. If this is a QCborArray, returns the element whose
    index is \a key. If there's no matching value in the array or map, or if
    this QCborValueRef object is not an array or map, returns the undefined
    value.

    \sa operator[], QCborMap::operator[], QCborMap::value(),
        QCborMap::find(), QCborArray::operator[], QCborArray::at()
 */
const QCborValue QCborValueRef::operator[](qint64 key) const
{
    return QCborValueConstRef::operator[](key);
}

/*!
    Returns a QCborValueRef that can be used to read or modify the entry in
    this, as a map, with the given \a key. When this QCborValueRef refers to a
    QCborMap, this function is equivalent to the matching operator[] on that
    map.

    Before returning the reference: if the QCborValue referenced was an array,
    it is first converted to a map (so that \c{map[i]} is \c{array[i]} for each
    index, \c i, with valid \c{array[i]}); otherwise, if it was not a map it
    will be over-written with an empty map.

    \sa operator[](qint64), QCborMap::operator[], QCborMap::value(),
        QCborMap::find()
 */
QCborValueRef QCborValueRef::operator[](const QString &key)
{
    return QCborContainerPrivate::findOrAddMapKey(*this, qToStringViewIgnoringNull(key));
}

/*!
    \overload

    Returns a QCborValueRef that can be used to read or modify the entry in
    this, as a map, with the given \a key. When this QCborValue is a QCborMap,
    this function is equivalent to the matching operator[] on that map.

    Before returning the reference: if the QCborValue referenced was an array,
    it is first converted to a map (so that \c{map[i]} is \c{array[i]} for each
    index, \c i, with valid \c{array[i]}); otherwise, if it was not a map it
    will be over-written with an empty map.

    \sa operator[](qint64), QCborMap::operator[], QCborMap::value(),
        QCborMap::find()
 */
QCborValueRef QCborValueRef::operator[](QLatin1StringView key)
{
    return QCborContainerPrivate::findOrAddMapKey(*this, key);
}

/*!
    \overload

    Returns a QCborValueRef that can be used to read or modify the entry in
    this, as a map or array, with the given \a key. When this QCborValue is a
    QCborMap or, for 0 <= key < 0x10000, a QCborArray, this function is
    equivalent to the matching operator[] on that map or array.

    Before returning the reference: if the QCborValue referenced was an array
    but the key is out of range, the array is first converted to a map (so that
    \c{map[i]} is \c{array[i]} for each index, \c i, with valid \c{array[i]});
    otherwise, if it was not a map it will be over-written with an empty map.

    \sa operator[], QCborMap::operator[], QCborMap::value(),
        QCborMap::find(), QCborArray::operator[], QCborArray::at()
 */
QCborValueRef QCborValueRef::operator[](qint64 key)
{
    auto &e = d->elements[i];
    if (shouldArrayRemainArray(key, e.type, e.container)) {
        e.container = maybeGrow(e.container, key);
        e.flags |= QtCbor::Element::IsContainer;
        return { e.container, qsizetype(key) };
    }
    return QCborContainerPrivate::findOrAddMapKey(*this, key);
}
#endif // < Qt 7

inline QCborArray::QCborArray(QCborContainerPrivate &dd) noexcept
    : d(&dd)
{
}

inline QCborMap::QCborMap(QCborContainerPrivate &dd) noexcept
    : d(&dd)
{
}

size_t qHash(const QCborValue &value, size_t seed)
{
    switch (value.type()) {
    case QCborValue::Integer:
        return qHash(value.toInteger(), seed);
    case QCborValue::ByteArray:
        return qHash(value.toByteArray(), seed);
    case QCborValue::String:
        return qHash(value.toString(), seed);
    case QCborValue::Array:
        return qHash(value.toArray(), seed);
    case QCborValue::Map:
        return qHash(value.toMap(), seed);
    case QCborValue::Tag: {
        QtPrivate::QHashCombine hash;
        seed = hash(seed, value.tag());
        seed = hash(seed, value.taggedValue());
        return seed;
    }
    case QCborValue::SimpleType:
        break;
    case QCborValue::False:
        return qHash(false, seed);
    case QCborValue::True:
        return qHash(true, seed);
    case QCborValue::Null:
        return qHash(nullptr, seed);
    case QCborValue::Undefined:
        return seed;
    case QCborValue::Double:
        return qHash(value.toDouble(), seed);
#if QT_CONFIG(datestring)
    case QCborValue::DateTime:
        return qHash(value.toDateTime(), seed);
#endif
#ifndef QT_BOOTSTRAPPED
    case QCborValue::Url:
        return qHash(value.toUrl(), seed);
#  if QT_CONFIG(regularexpression)
    case QCborValue::RegularExpression:
        return qHash(value.toRegularExpression(), seed);
#  endif
    case QCborValue::Uuid:
        return qHash(value.toUuid(), seed);
#endif
    case QCborValue::Invalid:
        return seed;
    default:
        break;
    }

    Q_ASSERT(value.isSimpleType());
    return qHash(value.toSimpleType(), seed);
}

Q_CORE_EXPORT const char *qt_cbor_simpletype_id(QCborSimpleType st)
{
    switch (st) {
    case QCborSimpleType::False:
        return "False";
    case QCborSimpleType::True:
        return "True";
    case QCborSimpleType::Null:
        return "Null";
    case QCborSimpleType::Undefined:
        return "Undefined";
    }
    return nullptr;
}

Q_CORE_EXPORT const char *qt_cbor_tag_id(QCborTag tag)
{
    // Casting to QCborKnownTags's underlying type will make the comparison
    // below fail if the tag value is out of range.
    auto n = std::underlying_type<QCborKnownTags>::type(tag);
    if (QCborTag(n) == tag) {
        switch (QCborKnownTags(n)) {
        case QCborKnownTags::DateTimeString:
            return "DateTimeString";
        case QCborKnownTags::UnixTime_t:
            return "UnixTime_t";
        case QCborKnownTags::PositiveBignum:
            return "PositiveBignum";
        case QCborKnownTags::NegativeBignum:
            return "NegativeBignum";
        case QCborKnownTags::Decimal:
            return "Decimal";
        case QCborKnownTags::Bigfloat:
            return "Bigfloat";
        case QCborKnownTags::COSE_Encrypt0:
            return "COSE_Encrypt0";
        case QCborKnownTags::COSE_Mac0:
            return "COSE_Mac0";
        case QCborKnownTags::COSE_Sign1:
            return "COSE_Sign1";
        case QCborKnownTags::ExpectedBase64url:
            return "ExpectedBase64url";
        case QCborKnownTags::ExpectedBase64:
            return "ExpectedBase64";
        case QCborKnownTags::ExpectedBase16:
            return "ExpectedBase16";
        case QCborKnownTags::EncodedCbor:
            return "EncodedCbor";
        case QCborKnownTags::Url:
            return "Url";
        case QCborKnownTags::Base64url:
            return "Base64url";
        case QCborKnownTags::Base64:
            return "Base64";
        case QCborKnownTags::RegularExpression:
            return "RegularExpression";
        case QCborKnownTags::MimeMessage:
            return "MimeMessage";
        case QCborKnownTags::Uuid:
            return "Uuid";
        case QCborKnownTags::COSE_Encrypt:
            return "COSE_Encrypt";
        case QCborKnownTags::COSE_Mac:
            return "COSE_Mac";
        case QCborKnownTags::COSE_Sign:
            return "COSE_Sign";
        case QCborKnownTags::Signature:
            return "Signature";
        }
    }
    return nullptr;
}

#if !defined(QT_NO_DEBUG_STREAM)
static QDebug debugContents(QDebug &dbg, const QCborValue &v)
{
    switch (v.type()) {
    case QCborValue::Integer:
        return dbg << v.toInteger();
    case QCborValue::ByteArray:
        return dbg << "QByteArray(" << v.toByteArray() << ')';
    case QCborValue::String:
        return dbg << v.toString();
    case QCborValue::Array:
        return dbg << v.toArray();
    case QCborValue::Map:
        return dbg << v.toMap();
    case QCborValue::Tag: {
        QCborTag tag = v.tag();
        const char *id = qt_cbor_tag_id(tag);
        if (id)
            dbg.nospace() << "QCborKnownTags::" << id << ", ";
        else
            dbg.nospace() << "QCborTag(" << quint64(tag) << "), ";
        return dbg << v.taggedValue();
    }
    case QCborValue::SimpleType:
        break;
    case QCborValue::True:
        return dbg << true;
    case QCborValue::False:
        return dbg << false;
    case QCborValue::Null:
        return dbg << "nullptr";
    case QCborValue::Undefined:
        return dbg;
    case QCborValue::Double: {
        qint64 i;
        if (convertDoubleTo(v.toDouble(), &i))
            return dbg << i << ".0";
        else
            return dbg << v.toDouble();
    }
#if QT_CONFIG(datestring)
    case QCborValue::DateTime:
        return dbg << v.toDateTime();
#endif
#ifndef QT_BOOTSTRAPPED
    case QCborValue::Url:
        return dbg << v.toUrl();
#if QT_CONFIG(regularexpression)
    case QCborValue::RegularExpression:
        return dbg << v.toRegularExpression();
#endif
    case QCborValue::Uuid:
        return dbg << v.toUuid();
#endif
    case QCborValue::Invalid:
        return dbg << "<invalid>";
    default:
        break;
    }
    if (v.isSimpleType())
        return dbg << v.toSimpleType();
    return dbg << "<unknown type 0x" << Qt::hex << int(v.type()) << Qt::dec << '>';
}
QDebug operator<<(QDebug dbg, const QCborValue &v)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "QCborValue(";
    return debugContents(dbg, v) << ')';
}

QDebug operator<<(QDebug dbg, QCborSimpleType st)
{
    QDebugStateSaver saver(dbg);
    const char *id = qt_cbor_simpletype_id(st);
    if (id)
        return dbg.nospace() << "QCborSimpleType::" << id;

    return dbg.nospace() << "QCborSimpleType(" << uint(st) << ')';
}

QDebug operator<<(QDebug dbg, QCborTag tag)
{
    QDebugStateSaver saver(dbg);
    const char *id = qt_cbor_tag_id(tag);
    dbg.nospace() << "QCborTag(";
    if (id)
        dbg.nospace() << "QCborKnownTags::" << id;
    else
        dbg.nospace() << quint64(tag);

    return dbg << ')';
}

QDebug operator<<(QDebug dbg, QCborKnownTags tag)
{
    QDebugStateSaver saver(dbg);
    const char *id = qt_cbor_tag_id(QCborTag(int(tag)));
    if (id)
        return dbg.nospace() << "QCborKnownTags::" << id;

    return dbg.nospace() << "QCborKnownTags(" << int(tag) << ')';
}
#endif

#ifndef QT_NO_DATASTREAM
#if QT_CONFIG(cborstreamwriter)
QDataStream &operator<<(QDataStream &stream, const QCborValue &value)
{
    stream << QCborValue(value).toCbor();
    return stream;
}
#endif

QDataStream &operator>>(QDataStream &stream, QCborValue &value)
{
    QByteArray buffer;
    stream >> buffer;
    QCborParserError parseError{};
    value = QCborValue::fromCbor(buffer, &parseError);
    if (parseError.error)
        stream.setStatus(QDataStream::ReadCorruptData);
    return stream;
}
#endif


QT_END_NAMESPACE

#include "qcborarray.cpp"
#include "qcbormap.cpp"

#ifndef QT_NO_QOBJECT
#include "moc_qcborvalue.cpp"
#endif
