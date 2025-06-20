// Copyright (C) 2022 The Qt Company Ltd.
// Copyright (C) 2020 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Giuseppe D'Angelo <giuseppe.dangelo@kdab.com>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qabstractitemmodel.h"
#include <private/qabstractitemmodel_p.h>
#include <qdatastream.h>
#include <qstringlist.h>
#include <qsize.h>
#include <qmimedata.h>
#include <qdebug.h>
#include <qlist.h>
#if QT_CONFIG(regularexpression)
#  include <qregularexpression.h>
#endif
#include <qstack.h>
#include <qmap.h>
#include <qbitarray.h>
#include <qdatetime.h>
#include <qloggingcategory.h>

#include <functional>

#include <limits.h>

QT_BEGIN_NAMESPACE

Q_STATIC_LOGGING_CATEGORY(lcCheckIndex, "qt.core.qabstractitemmodel.checkindex")
Q_STATIC_LOGGING_CATEGORY(lcReset, "qt.core.qabstractitemmodel.reset")

QT_IMPL_METATYPE_EXTERN(QModelIndexList)

QPersistentModelIndexData *QPersistentModelIndexData::create(const QModelIndex &index)
{
    Q_ASSERT(index.isValid()); // we will _never_ insert an invalid index in the list
    QPersistentModelIndexData *d = nullptr;
    QAbstractItemModel *model = const_cast<QAbstractItemModel *>(index.model());
    QMultiHash<QtPrivate::QModelIndexWrapper, QPersistentModelIndexData *> &indexes = model->d_func()->persistent.indexes;
    const auto it = indexes.constFind(index);
    if (it != indexes.cend()) {
        d = (*it);
    } else {
        d = new QPersistentModelIndexData(index);
        indexes.insert(index, d);
    }
    Q_ASSERT(d);
    return d;
}

void QPersistentModelIndexData::destroy(QPersistentModelIndexData *data)
{
    Q_ASSERT(data);
    Q_ASSERT(data->ref.loadRelaxed() == 0);
    QAbstractItemModel *model = const_cast<QAbstractItemModel *>(data->index.model());
    // a valid persistent model index with a null model pointer can only happen if the model was destroyed
    if (model) {
        QAbstractItemModelPrivate *p = model->d_func();
        Q_ASSERT(p);
        p->removePersistentIndexData(data);
    }
    delete data;
}

/*!
    \class QModelRoleData
    \inmodule QtCore
    \since 6.0
    \ingroup model-view
    \brief The QModelRoleData class holds a role and the data associated to that role.

    QModelRoleData objects store an item role (which is a value from the
    Qt::ItemDataRole enumeration, or an arbitrary integer for a custom role)
    as well as the data associated with that role.

    A QModelRoleData object is typically created by views or delegates,
    setting which role they want to fetch the data for. The object
    is then passed to models (see QAbstractItemModel::multiData()),
    which populate the data corresponding to the role stored. Finally,
    the view visualizes the data retrieved from the model.

    \sa {Model/View Programming}, QModelRoleDataSpan
*/

/*!
    \fn QModelRoleData::QModelRoleData(int role) noexcept

    Constructs a QModelRoleData object for the given \a role.

    \sa Qt::ItemDataRole
*/

/*!
    \fn int QModelRoleData::role() const noexcept

    Returns the role held by this object.

    \sa Qt::ItemDataRole
*/

/*!
    \fn const QVariant &QModelRoleData::data() const noexcept

    Returns the data held by this object.

    \sa setData()
*/

/*!
    \fn QVariant &QModelRoleData::data() noexcept

    Returns the data held by this object as a modifiable reference.

    \sa setData()
*/

/*!
    \fn template <typename T> void QModelRoleData::setData(T &&value)

    Sets the data held by this object to \a value.
    \a value must be of a datatype which can be stored in a QVariant.

    \sa data(), clearData(), Q_DECLARE_METATYPE
*/

/*!
    \fn void QModelRoleData::clearData() noexcept

    Clears the data held by this object. Note that the role is
    unchanged; only the data is cleared.

    \sa data()
*/

/*!
    \class QModelRoleDataSpan
    \inmodule QtCore
    \since 6.0
    \ingroup model-view
    \brief The QModelRoleDataSpan class provides a span over QModelRoleData objects.

    A QModelRoleDataSpan is used as an abstraction over an array of
    QModelRoleData objects.

    Like a view, QModelRoleDataSpan provides a small object (pointer
    and size) that can be passed to functions that need to examine the
    contents of the array. A QModelRoleDataSpan can be constructed from
    any array-like sequence (plain arrays, QVector, std::vector,
    QVarLengthArray, and so on). Moreover, it does not own the
    sequence, which must therefore be kept alive longer than any
    QModelRoleDataSpan objects referencing it.

    Unlike a view, QModelRoleDataSpan is a span, so it allows for
    modifications to the underlying elements.

    QModelRoleDataSpan's main use case is making it possible
    for a model to return the data corresponding to different roles
    in one call.

    In order to draw one element from a model, a view (through its
    delegates) will generally request multiple roles for the same index
    by calling \c{data()} as many times as needed:

    \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 13

    QModelRoleDataSpan allows a view to request the same data
    using just one function call.

    This is achieved by having the view prepare a suitable array of
    QModelRoleData objects, each initialized with the role that should
    be fetched. The array is then wrapped in a QModelRoleDataSpan
    object, which is then passed to a model's \c{multiData()} function.

    \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 14

    Views are encouraged to store the array of QModelRoleData objects
    (and, possibly, the corresponding span) and re-use it in subsequent
    calls to the model. This allows to reduce the memory allocations
    related with creating and returning QVariant objects.

    Finally, given a QModelRoleDataSpan object, the model's
    responsibility is to fill in the data corresponding to each role in
    the span. How this is done depends on the concrete model class.
    Here's a sketch of a possible implementation that iterates over the
    span and uses \c{setData()} on each element:

    \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 15

    \sa {Model/View Programming}, QAbstractItemModel::multiData()
*/

/*!
    \fn QModelRoleDataSpan::QModelRoleDataSpan() noexcept

    Constructs an empty QModelRoleDataSpan. Its data() will be set to
    \nullptr, and its length to zero.
*/

/*!
    \fn QModelRoleDataSpan::QModelRoleDataSpan(QModelRoleData &modelRoleData) noexcept

    Constructs an QModelRoleDataSpan spanning over \a modelRoleData,
    seen as a 1-element array.
*/

/*!
    \fn QModelRoleDataSpan::QModelRoleDataSpan(QModelRoleData *modelRoleData, qsizetype len)

    Constructs an QModelRoleDataSpan spanning over the array beginning
    at \a modelRoleData and with length \a len.

    \note The array must be kept alive as long as this object has not
    been destructed.
*/

/*!
    \fn template <typename Container, QModelRoleDataSpan::if_compatible_container<Container> = true> QModelRoleDataSpan::QModelRoleDataSpan(Container &c) noexcept

    Constructs an QModelRoleDataSpan spanning over the container \a c,
    which can be any contiguous container of QModelRoleData objects.
    For instance, it can be a \c{QVector<QModelRoleData>},
    a \c{std::array<QModelRoleData, 10>} and so on.

    \note The container must be kept alive as long as this object has not
    been destructed.
*/

/*!
    \fn qsizetype QModelRoleDataSpan::size() const noexcept

    Returns the length of the span represented by this object.
*/

/*!
    \fn qsizetype QModelRoleDataSpan::length() const noexcept

    Returns the length of the span represented by this object.
*/

/*!
    \fn QModelRoleData *QModelRoleDataSpan::data() const noexcept

    Returns a pointer to the beginning of the span represented by this
    object.
*/

/*!
    \fn QModelRoleData *QModelRoleDataSpan::begin() const noexcept

    Returns a pointer to the beginning of the span represented by this
    object.
*/

/*!
    \fn QModelRoleData *QModelRoleDataSpan::end() const noexcept

    Returns a pointer to the imaginary element one past the end of the
    span represented by this object.
*/

/*!
    \fn QModelRoleData &QModelRoleDataSpan::operator[](qsizetype index) const

    Returns a modifiable reference to the QModelRoleData at position
    \a index in the span.

    \note \a index must be a valid index for this span (0 <= \a index < size()).
*/

/*!
    \fn const QVariant *QModelRoleDataSpan::dataForRole(int role) const

    Returns the data associated with the first QModelRoleData in the
    span that has its role equal to \a role. If such a QModelRoleData
    object does not exist, the behavior is undefined.

    \note Avoid calling this function from the model's side, as a
    model cannot possibly know in advance which roles are in a given
    QModelRoleDataSpan. This function is instead suitable for views and
    delegates, which have control over the roles in the span.

    \sa QModelRoleData::data()
*/

/*!
  \class QPersistentModelIndex
  \inmodule QtCore
  \ingroup shared

  \brief The QPersistentModelIndex class is used to locate data in a data model.

  \ingroup model-view
  \compares strong
  \compareswith strong QModelIndex
  \endcompareswith

  A QPersistentModelIndex is a model index that can be stored by an
  application, and later used to access information in a model.
  Unlike the QModelIndex class, it is safe to store a
  QPersistentModelIndex since the model will ensure that references
  to items will continue to be valid as long as they can be accessed
  by the model.

  It is good practice to check that persistent model indexes are valid
  before using them.

  \note You cannot store a QStandardItemModel's  QPersistentModelIndex
  in one of the model's items.

  \sa {Model/View Programming}, QModelIndex, QAbstractItemModel
*/

/*!
    \fn QPersistentModelIndex::QPersistentModelIndex(QPersistentModelIndex &&other)

    Move-constructs a QPersistentModelIndex instance, making it point at the same
    object that \a other was pointing to.

    \since 5.2
*/

/*!
    \fn QPersistentModelIndex &QPersistentModelIndex::operator=(QPersistentModelIndex &&other)

    Move-assigns \a other to this QPersistentModelIndex instance.

    \since 5.2
*/


/*!
  \fn QPersistentModelIndex::QPersistentModelIndex()

  \internal
*/

QPersistentModelIndex::QPersistentModelIndex()
    : d(nullptr)
{
}

/*!
  \fn QPersistentModelIndex::QPersistentModelIndex(const QPersistentModelIndex &other)

  Creates a new QPersistentModelIndex that is a copy of the \a other persistent
  model index.
*/

QPersistentModelIndex::QPersistentModelIndex(const QPersistentModelIndex &other)
    : d(other.d)
{
    if (d) d->ref.ref();
}

/*!
    Creates a new QPersistentModelIndex that is a copy of the model \a index.
*/

QPersistentModelIndex::QPersistentModelIndex(const QModelIndex &index)
    : d(nullptr)
{
    if (index.isValid()) {
        d = QPersistentModelIndexData::create(index);
        d->ref.ref();
    }
}

/*!
    \fn QPersistentModelIndex::~QPersistentModelIndex()

    \internal
*/

QPersistentModelIndex::~QPersistentModelIndex()
{
    if (d && !d->ref.deref()) {
        QPersistentModelIndexData::destroy(d);
        d = nullptr;
    }
}

/*!
    \fn bool QPersistentModelIndex::operator==(const QPersistentModelIndex &lhs, const QPersistentModelIndex &rhs)
    Returns \c{true} if \a lhs persistent model index is equal to the \a rhs
    persistent model index; otherwise returns \c{false}.

    The internal data pointer, row, column, and model values in the persistent
    model index are used when comparing with another persistent model index.
*/

/*!
    \fn bool QPersistentModelIndex::operator!=(const QPersistentModelIndex &lhs, const QPersistentModelIndex &rhs)
    \since 4.2

    Returns \c{true} if \a lhs persistent model index is not equal to the \a rhs
    persistent model index; otherwise returns \c{false}.
*/
bool comparesEqual(const QPersistentModelIndex &lhs, const QPersistentModelIndex &rhs) noexcept
{
    if (lhs.d && rhs.d)
        return lhs.d->index == rhs.d->index;
    return lhs.d == rhs.d;
}

/*!
    \fn bool QPersistentModelIndex::operator<(const QPersistentModelIndex &lhs, const QPersistentModelIndex &rhs)
    \since 4.1

    Returns \c{true} if \a lhs persistent model index is smaller than the \a rhs
    persistent model index; otherwise returns \c{false}.

    The internal data pointer, row, column, and model values in the persistent
    model index are used when comparing with another persistent model index.
*/
Qt::strong_ordering compareThreeWay(const QPersistentModelIndex &lhs,
                                    const QPersistentModelIndex &rhs) noexcept
{
    if (lhs.d && rhs.d)
        return compareThreeWay(lhs.d->index, rhs.d->index);

    using Qt::totally_ordered_wrapper;
    return compareThreeWay(totally_ordered_wrapper{lhs.d}, totally_ordered_wrapper{rhs.d});
}

Qt::strong_ordering compareThreeWay(const QPersistentModelIndex &lhs,
                                    const QModelIndex &rhs) noexcept
{
    return compareThreeWay(lhs.d ? lhs.d->index : QModelIndex{}, rhs);
}

/*!
    Sets the persistent model index to refer to the same item in a model
    as the \a other persistent model index.
*/

QPersistentModelIndex &QPersistentModelIndex::operator=(const QPersistentModelIndex &other)
{
    if (d == other.d)
        return *this;
    if (d && !d->ref.deref())
        QPersistentModelIndexData::destroy(d);
    d = other.d;
    if (d) d->ref.ref();
    return *this;
}
/*!
    \fn void QPersistentModelIndex::swap(QPersistentModelIndex &other)
    \since 5.0
    \memberswap{persistent modelindex}
*/

/*!
    Sets the persistent model index to refer to the same item in a model
    as the \a other model index.
*/

QPersistentModelIndex &QPersistentModelIndex::operator=(const QModelIndex &other)
{
    if (d && !d->ref.deref())
        QPersistentModelIndexData::destroy(d);
    if (other.isValid()) {
        d = QPersistentModelIndexData::create(other);
        if (d) d->ref.ref();
    } else {
        d = nullptr;
    }
    return *this;
}

/*!
  \fn QPersistentModelIndex::operator QModelIndex() const

  Cast operator that returns a QModelIndex.
*/

QPersistentModelIndex::operator QModelIndex() const
{
    if (d)
        return d->index;
    return QModelIndex();
}

/*!
    \fn bool QPersistentModelIndex::operator==(const QPersistentModelIndex &lhs, const QModelIndex &rhs)
    Returns \c{true} if \a lhs persistent model index refers to the same location as
    the \a rhs model index; otherwise returns \c{false}.

    The internal data pointer, row, column, and model values in the persistent
    model index are used when comparing with another model index.
 */

/*!
    \fn bool QPersistentModelIndex::operator!=(const QPersistentModelIndex &lhs, const QModelIndex &rhs)

    Returns \c{true} if \a lhs persistent model index does not refer to the same
    location as the \a rhs model index; otherwise returns \c{false}.
*/

bool comparesEqual(const QPersistentModelIndex &lhs, const QModelIndex &rhs) noexcept
{
    if (lhs.d)
        return lhs.d->index == rhs;
    return !rhs.isValid();
}

/*!
    \fn int QPersistentModelIndex::row() const

    Returns the row this persistent model index refers to.
*/

int QPersistentModelIndex::row() const
{
    if (d)
        return d->index.row();
    return -1;
}

/*!
    \fn int QPersistentModelIndex::column() const

    Returns the column this persistent model index refers to.
*/

int QPersistentModelIndex::column() const
{
    if (d)
        return d->index.column();
    return -1;
}

/*!
    \fn void *QPersistentModelIndex::internalPointer() const

    \internal

    Returns a \c{void} \c{*} pointer used by the model to associate the index with
    the internal data structure.
*/

void *QPersistentModelIndex::internalPointer() const
{
    if (d)
        return d->index.internalPointer();
    return nullptr;
}

/*!
    \fn const void *QPersistentModelIndex::constInternalPointer() const
    \since 6.0
    \internal

    Returns a \c{const void} \c{*} pointer used by the model to
    associate the index with the internal data structure.
*/

const void *QPersistentModelIndex::constInternalPointer() const
{
    if (d)
        return d->index.constInternalPointer();
    return nullptr;
}

/*!
    \fn quintptr QPersistentModelIndex::internalId() const

    \internal

    Returns a \c{quintptr} used by the model to associate the index with
    the internal data structure.
*/

quintptr QPersistentModelIndex::internalId() const
{
    if (d)
        return d->index.internalId();
    return 0;
}

/*!
    Returns the parent QModelIndex for this persistent index, or an invalid
    QModelIndex if it has no parent.

    \sa sibling(), model()
*/
QModelIndex QPersistentModelIndex::parent() const
{
    if (d)
        return d->index.parent();
    return QModelIndex();
}

/*!
    Returns the sibling at \a row and \a column or an invalid QModelIndex if
    there is no sibling at this position.

    \sa parent()
*/

QModelIndex QPersistentModelIndex::sibling(int row, int column) const
{
    if (d)
        return d->index.sibling(row, column);
    return QModelIndex();
}

/*!
    Returns the data for the given \a role for the item referred to by the
    index, or a default-constructed QVariant if this persistent model index
    is \l{isValid()}{invalid}.

    \sa Qt::ItemDataRole, QAbstractItemModel::setData()
*/
QVariant QPersistentModelIndex::data(int role) const
{
    if (d)
        return d->index.data(role);
    return QVariant();
}


/*!
    Populates the given \a roleDataSpan for the item referred to by the
    index.

    \since 6.0
    \sa Qt::ItemDataRole, QAbstractItemModel::setData()
*/
void QPersistentModelIndex::multiData(QModelRoleDataSpan roleDataSpan) const
{
    if (d)
        d->index.multiData(roleDataSpan);
}

/*!
    \since 4.2

    Returns the flags for the item referred to by the index.
*/
Qt::ItemFlags QPersistentModelIndex::flags() const
{
    if (d)
        return d->index.flags();
    return { };
}

/*!
    Returns the model that the index belongs to.
*/
const QAbstractItemModel *QPersistentModelIndex::model() const
{
    if (d)
        return d->index.model();
    return nullptr;
}

/*!
    \fn bool QPersistentModelIndex::isValid() const

    Returns \c{true} if this persistent model index is valid; otherwise returns
    \c{false}.

    A valid index belongs to a model, and has non-negative row and column
    numbers.

    \sa model(), row(), column()
*/

bool QPersistentModelIndex::isValid() const
{
    return d && d->index.isValid();
}

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const QModelIndex &idx)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "QModelIndex(" << idx.row() << ',' << idx.column()
                  << ',' << idx.internalPointer() << ',' << idx.model() << ')';
    return dbg;
}

QDebug operator<<(QDebug dbg, const QPersistentModelIndex &idx)
{
    if (idx.d)
        dbg << idx.d->index;
    else
        dbg << QModelIndex();
    return dbg;
}
#endif

class QEmptyItemModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit QEmptyItemModel(QObject *parent = nullptr) : QAbstractItemModel(parent) {}
    QModelIndex index(int, int, const QModelIndex &) const override { return QModelIndex(); }
    QModelIndex parent(const QModelIndex &) const override { return QModelIndex(); }
    int rowCount(const QModelIndex &) const override { return 0; }
    int columnCount(const QModelIndex &) const override { return 0; }
    bool hasChildren(const QModelIndex &) const override { return false; }
    QVariant data(const QModelIndex &, int) const override { return QVariant(); }
};

Q_GLOBAL_STATIC(QEmptyItemModel, qEmptyModel)


QAbstractItemModelPrivate::QAbstractItemModelPrivate()
    : QObjectPrivate()
{
}

QAbstractItemModelPrivate::~QAbstractItemModelPrivate()
{
}

QAbstractItemModel *QAbstractItemModelPrivate::staticEmptyModel()
{
    return qEmptyModel();
}

void QAbstractItemModelPrivate::invalidatePersistentIndexes()
{
    for (QPersistentModelIndexData *data : std::as_const(persistent.indexes))
        data->index = QModelIndex();
    persistent.indexes.clear();
}

/*!
    \internal
    Clean the QPersistentModelIndex relative to the index if there is one.
    To be used before an index is invalided
*/
void QAbstractItemModelPrivate::invalidatePersistentIndex(const QModelIndex &index) {
    const auto it = persistent.indexes.constFind(index);
    if (it != persistent.indexes.cend()) {
        QPersistentModelIndexData *data = *it;
        persistent.indexes.erase(it);
        data->index = QModelIndex();
    }
}

using DefaultRoleNames = QHash<int, QByteArray>;
Q_GLOBAL_STATIC(DefaultRoleNames, qDefaultRoleNames,
    {
        { Qt::DisplayRole,    "display"    },
        { Qt::DecorationRole, "decoration" },
        { Qt::EditRole,       "edit"       },
        { Qt::ToolTipRole,    "toolTip"    },
        { Qt::StatusTipRole,  "statusTip"  },
        { Qt::WhatsThisRole,  "whatsThis"  },
    })

const QHash<int,QByteArray> &QAbstractItemModelPrivate::defaultRoleNames()
{
    return *qDefaultRoleNames();
}

bool QAbstractItemModelPrivate::isVariantLessThan(const QVariant &left, const QVariant &right,
                                                  Qt::CaseSensitivity cs, bool isLocaleAware)
{
    if (left.userType() == QMetaType::UnknownType)
        return false;
    if (right.userType() == QMetaType::UnknownType)
        return true;
    switch (left.userType()) {
    case QMetaType::Int:
        return left.toInt() < right.toInt();
    case QMetaType::UInt:
        return left.toUInt() < right.toUInt();
    case QMetaType::LongLong:
        return left.toLongLong() < right.toLongLong();
    case QMetaType::ULongLong:
        return left.toULongLong() < right.toULongLong();
    case QMetaType::Float:
        return left.toFloat() < right.toFloat();
    case QMetaType::Double:
        return left.toDouble() < right.toDouble();
    case QMetaType::QChar:
        return left.toChar() < right.toChar();
    case QMetaType::QDate:
        return left.toDate() < right.toDate();
    case QMetaType::QTime:
        return left.toTime() < right.toTime();
    case QMetaType::QDateTime:
        return left.toDateTime() < right.toDateTime();
    case QMetaType::QString:
    default:
        if (isLocaleAware)
            return left.toString().localeAwareCompare(right.toString()) < 0;
        else
            return left.toString().compare(right.toString(), cs) < 0;
    }
}


static uint typeOfVariant(const QVariant &value)
{
    //return 0 for integer, 1 for floating point and 2 for other
    switch (value.userType()) {
        case QMetaType::Bool:
        case QMetaType::Int:
        case QMetaType::UInt:
        case QMetaType::LongLong:
        case QMetaType::ULongLong:
        case QMetaType::QChar:
        case QMetaType::Short:
        case QMetaType::UShort:
        case QMetaType::UChar:
        case QMetaType::ULong:
        case QMetaType::Long:
            return 0;
        case QMetaType::Double:
        case QMetaType::Float:
            return 1;
        default:
            return 2;
    }
}

/*!
    \internal
    Return \c{true} if \a value contains a numerical type.

    This function is used by our Q{Tree,Widget,Table}WidgetModel classes to sort.
*/
bool QAbstractItemModelPrivate::variantLessThan(const QVariant &v1, const QVariant &v2)
{
    switch(qMax(typeOfVariant(v1), typeOfVariant(v2)))
    {
    case 0: //integer type
        return v1.toLongLong() < v2.toLongLong();
    case 1: //floating point
        return v1.toReal() < v2.toReal();
    default:
        return v1.toString().localeAwareCompare(v2.toString()) < 0;
    }
}

void QAbstractItemModelPrivate::removePersistentIndexData(QPersistentModelIndexData *data)
{
    if (data->index.isValid()) {
        int removed = persistent.indexes.remove(data->index);
        Q_ASSERT_X(removed == 1, "QPersistentModelIndex::~QPersistentModelIndex",
                   "persistent model indexes corrupted"); //maybe the index was somewhat invalid?
        // This assert may happen if the model use changePersistentIndex in a way that could result on two
        // QPersistentModelIndex pointing to the same index.
        Q_UNUSED(removed);
    }
    // make sure our optimization still works
    for (int i = persistent.moved.size() - 1; i >= 0; --i) {
        int idx = persistent.moved.at(i).indexOf(data);
        if (idx >= 0)
            persistent.moved[i].remove(idx);
    }
    // update the references to invalidated persistent indexes
    for (int i = persistent.invalidated.size() - 1; i >= 0; --i) {
        int idx = persistent.invalidated.at(i).indexOf(data);
        if (idx >= 0)
            persistent.invalidated[i].remove(idx);
    }

}

void QAbstractItemModelPrivate::rowsAboutToBeInserted(const QModelIndex &parent,
                                                      int first, int last)
{
    Q_Q(QAbstractItemModel);
    Q_UNUSED(last);
    QList<QPersistentModelIndexData *> persistent_moved;
    if (first < q->rowCount(parent)) {
        for (auto *data : std::as_const(persistent.indexes)) {
            const QModelIndex &index = data->index;
            if (index.row() >= first && index.isValid() && index.parent() == parent) {
                persistent_moved.append(data);
            }
        }
    }
    persistent.moved.push(persistent_moved);
}

void QAbstractItemModelPrivate::rowsInserted(const QModelIndex &parent,
                                             int first, int last)
{
    const QList<QPersistentModelIndexData *> persistent_moved = persistent.moved.pop();
    const int count = (last - first) + 1; // it is important to only use the delta, because the change could be nested
    for (auto *data : persistent_moved) {
        QModelIndex old = data->index;
        persistent.indexes.erase(persistent.indexes.constFind(old));
        data->index = q_func()->index(old.row() + count, old.column(), parent);
        if (data->index.isValid()) {
            persistent.insertMultiAtEnd(data->index, data);
        } else {
            qWarning() << "QAbstractItemModel::endInsertRows:  Invalid index (" << old.row() + count << ',' << old.column() << ") in model" << q_func();
        }
    }
}

void QAbstractItemModelPrivate::itemsAboutToBeMoved(const QModelIndex &srcParent, int srcFirst, int srcLast, const QModelIndex &destinationParent, int destinationChild, Qt::Orientation orientation)
{
    QList<QPersistentModelIndexData *> persistent_moved_explicitly;
    QList<QPersistentModelIndexData *> persistent_moved_in_source;
    QList<QPersistentModelIndexData *> persistent_moved_in_destination;

    const bool sameParent = (srcParent == destinationParent);
    const bool movingUp = (srcFirst > destinationChild);

    for (auto *data : std::as_const(persistent.indexes)) {
        const QModelIndex &index = data->index;
        const QModelIndex &parent = index.parent();
        const bool isSourceIndex = (parent == srcParent);
        const bool isDestinationIndex = (parent == destinationParent);

        int childPosition;
        if (orientation == Qt::Vertical)
            childPosition = index.row();
        else
            childPosition = index.column();

        if (!index.isValid() || !(isSourceIndex || isDestinationIndex ) )
            continue;

        if (!sameParent && isDestinationIndex) {
            if (childPosition >= destinationChild)
                persistent_moved_in_destination.append(data);
            continue;
        }

        if (sameParent && movingUp && childPosition < destinationChild)
            continue;

        if (sameParent && !movingUp && childPosition < srcFirst )
            continue;

        if (!sameParent && childPosition < srcFirst)
            continue;

        if (sameParent && (childPosition > srcLast) && (childPosition >= destinationChild ))
            continue;

        if ((childPosition <= srcLast) && (childPosition >= srcFirst)) {
            persistent_moved_explicitly.append(data);
        } else {
            persistent_moved_in_source.append(data);
        }
    }
    persistent.moved.push(persistent_moved_explicitly);
    persistent.moved.push(persistent_moved_in_source);
    persistent.moved.push(persistent_moved_in_destination);
}

/*!
  \internal

  Moves persistent indexes \a indexes by amount \a change. The change will be either a change in row value or a change in
  column value depending on the value of \a orientation. The indexes may also be moved to a different parent if \a parent
  differs from the existing parent for the index.
*/
void QAbstractItemModelPrivate::movePersistentIndexes(const QList<QPersistentModelIndexData *> &indexes, int change,
                                                      const QModelIndex &parent, Qt::Orientation orientation)
{
    for (auto *data : indexes) {
        int row = data->index.row();
        int column = data->index.column();

        if (Qt::Vertical == orientation)
            row += change;
        else
            column += change;

        persistent.indexes.erase(persistent.indexes.constFind(data->index));
        data->index = q_func()->index(row, column, parent);
        if (data->index.isValid()) {
            persistent.insertMultiAtEnd(data->index, data);
        } else {
            qWarning() << "QAbstractItemModel::endMoveRows:  Invalid index (" << row << "," << column << ") in model" << q_func();
        }
    }
}

void QAbstractItemModelPrivate::itemsMoved(const QModelIndex &sourceParent, int sourceFirst, int sourceLast, const QModelIndex &destinationParent, int destinationChild, Qt::Orientation orientation)
{
    const QList<QPersistentModelIndexData *> moved_in_destination = persistent.moved.pop();
    const QList<QPersistentModelIndexData *> moved_in_source = persistent.moved.pop();
    const QList<QPersistentModelIndexData *> moved_explicitly = persistent.moved.pop();

    const bool sameParent = (sourceParent == destinationParent);
    const bool movingUp = (sourceFirst > destinationChild);

    const int explicit_change = (!sameParent || movingUp) ? destinationChild - sourceFirst : destinationChild - sourceLast - 1 ;
    const int source_change = (!sameParent || !movingUp) ? -1*(sourceLast - sourceFirst + 1) : sourceLast - sourceFirst + 1 ;
    const int destination_change = sourceLast - sourceFirst + 1;

    movePersistentIndexes(moved_explicitly, explicit_change, destinationParent, orientation);
    movePersistentIndexes(moved_in_source, source_change, sourceParent, orientation);
    movePersistentIndexes(moved_in_destination, destination_change, destinationParent, orientation);
}

void QAbstractItemModelPrivate::rowsAboutToBeRemoved(const QModelIndex &parent,
                                                     int first, int last)
{
    QList<QPersistentModelIndexData *> persistent_moved;
    QList<QPersistentModelIndexData *> persistent_invalidated;
    // find the persistent indexes that are affected by the change, either by being in the removed subtree
    // or by being on the same level and below the removed rows
    for (auto *data : std::as_const(persistent.indexes)) {
        bool level_changed = false;
        QModelIndex current = data->index;
        while (current.isValid()) {
            QModelIndex current_parent = current.parent();
            if (current_parent == parent) { // on the same level as the change
                if (!level_changed && current.row() > last) // below the removed rows
                    persistent_moved.append(data);
                else if (current.row() <= last && current.row() >= first) // in the removed subtree
                    persistent_invalidated.append(data);
                break;
            }
            current = current_parent;
            level_changed = true;
        }
    }

    persistent.moved.push(persistent_moved);
    persistent.invalidated.push(persistent_invalidated);
}

void QAbstractItemModelPrivate::rowsRemoved(const QModelIndex &parent,
                                            int first, int last)
{
    const QList<QPersistentModelIndexData *> persistent_moved = persistent.moved.pop();
    const int count = (last - first) + 1; // it is important to only use the delta, because the change could be nested
    for (auto *data : persistent_moved) {
        QModelIndex old = data->index;
        persistent.indexes.erase(persistent.indexes.constFind(old));
        data->index = q_func()->index(old.row() - count, old.column(), parent);
        if (data->index.isValid()) {
            persistent.insertMultiAtEnd(data->index, data);
        } else {
            qWarning() << "QAbstractItemModel::endRemoveRows:  Invalid index (" << old.row() - count << ',' << old.column() << ") in model" << q_func();
        }
    }
    const QList<QPersistentModelIndexData *> persistent_invalidated = persistent.invalidated.pop();
    for (auto *data : persistent_invalidated) {
        auto pit = persistent.indexes.constFind(data->index);
        if (pit != persistent.indexes.cend())
            persistent.indexes.erase(pit);
        data->index = QModelIndex();
    }
}

void QAbstractItemModelPrivate::columnsAboutToBeInserted(const QModelIndex &parent,
                                                         int first, int last)
{
    Q_Q(QAbstractItemModel);
    Q_UNUSED(last);
    QList<QPersistentModelIndexData *> persistent_moved;
    if (first < q->columnCount(parent)) {
        for (auto *data : std::as_const(persistent.indexes)) {
            const QModelIndex &index = data->index;
            if (index.column() >= first && index.isValid() && index.parent() == parent)
                persistent_moved.append(data);
        }
    }
    persistent.moved.push(persistent_moved);
}

void QAbstractItemModelPrivate::columnsInserted(const QModelIndex &parent,
                                                int first, int last)
{
    const QList<QPersistentModelIndexData *> persistent_moved = persistent.moved.pop();
    const int count = (last - first) + 1; // it is important to only use the delta, because the change could be nested
    for (auto *data : persistent_moved) {
        QModelIndex old = data->index;
        persistent.indexes.erase(persistent.indexes.constFind(old));
        data->index = q_func()->index(old.row(), old.column() + count, parent);
        if (data->index.isValid()) {
            persistent.insertMultiAtEnd(data->index, data);
        } else {
            qWarning() << "QAbstractItemModel::endInsertColumns:  Invalid index (" << old.row() << ',' << old.column() + count << ") in model" << q_func();
        }
    }
}

void QAbstractItemModelPrivate::columnsAboutToBeRemoved(const QModelIndex &parent,
                                                        int first, int last)
{
    QList<QPersistentModelIndexData *> persistent_moved;
    QList<QPersistentModelIndexData *> persistent_invalidated;
    // find the persistent indexes that are affected by the change, either by being in the removed subtree
    // or by being on the same level and to the right of the removed columns
    for (auto *data : std::as_const(persistent.indexes)) {
        bool level_changed = false;
        QModelIndex current = data->index;
        while (current.isValid()) {
            QModelIndex current_parent = current.parent();
            if (current_parent == parent) { // on the same level as the change
                if (!level_changed && current.column() > last) // right of the removed columns
                    persistent_moved.append(data);
                else if (current.column() <= last && current.column() >= first) // in the removed subtree
                    persistent_invalidated.append(data);
                break;
            }
            current = current_parent;
            level_changed = true;
        }
    }

    persistent.moved.push(persistent_moved);
    persistent.invalidated.push(persistent_invalidated);

}

void QAbstractItemModelPrivate::columnsRemoved(const QModelIndex &parent,
                                               int first, int last)
{
    const QList<QPersistentModelIndexData *> persistent_moved = persistent.moved.pop();
    const int count = (last - first) + 1; // it is important to only use the delta, because the change could be nested
    for (auto *data : persistent_moved) {
        QModelIndex old = data->index;
        persistent.indexes.erase(persistent.indexes.constFind(old));
        data->index = q_func()->index(old.row(), old.column() - count, parent);
        if (data->index.isValid()) {
            persistent.insertMultiAtEnd(data->index, data);
        } else {
            qWarning() << "QAbstractItemModel::endRemoveColumns:  Invalid index (" << old.row() << ',' << old.column() - count << ") in model" << q_func();
        }
    }
    const QList<QPersistentModelIndexData *> persistent_invalidated = persistent.invalidated.pop();
    for (auto *data : persistent_invalidated) {
        auto index = persistent.indexes.constFind(data->index);
        if (index != persistent.indexes.constEnd())
            persistent.indexes.erase(index);
        data->index = QModelIndex();
    }
}

/*!
    \since 4.8

    This slot is called just after the internal data of a model is cleared
    while it is being reset.

    This slot is provided the convenience of subclasses of concrete proxy
    models, such as subclasses of QSortFilterProxyModel which maintain extra
    data.

    \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 12

    \note Due to a mistake, this slot is missing in Qt 5.0.

    \sa modelAboutToBeReset(), modelReset()
*/
void QAbstractItemModel::resetInternalData()
{

}

/*!
    \class QModelIndex
    \inmodule QtCore

    \brief The QModelIndex class is used to locate data in a data model.

    \ingroup model-view

    \compares strong

    This class is used as an index into item models derived from
    QAbstractItemModel. The index is used by item views, delegates, and
    selection models to locate an item in the model.

    New QModelIndex objects are created by the model using the
    QAbstractItemModel::createIndex() function. An \e invalid model index can
    be constructed with the QModelIndex constructor. Invalid indexes are often
    used as parent indexes when referring to top-level items in a model.

    Model indexes refer to items in models, and contain all the information
    required to specify their locations in those models. Each index is located
    in a given row and column, and may have a parent index; use row(),
    column(), and parent() to obtain this information. Each top-level item in a
    model is represented by a model index that does not have a parent index -
    in this case, parent() will return an invalid model index, equivalent to an
    index constructed with the zero argument form of the QModelIndex()
    constructor.

    To obtain a model index that refers to an existing item in a model, call
    QAbstractItemModel::index() with the required row and column values, and
    the model index of the parent. When referring to top-level items in a
    model, supply QModelIndex() as the parent index.

    The model() function returns the model that the index references as a
    QAbstractItemModel. The child() function is used to examine items held
    under the index in the model. The sibling() function allows you to traverse
    items in the model on the same level as the index.

    \note Model indexes should be used immediately and then discarded. You
    should not rely on indexes to remain valid after calling model functions
    that change the structure of the model or delete items. If you need to
    keep a model index over time use a QPersistentModelIndex.

    \sa {Model/View Programming}, QPersistentModelIndex, QAbstractItemModel
*/

/*!
    \fn QModelIndex::QModelIndex()

    Creates a new empty model index. This type of model index is used to
    indicate that the position in the model is invalid.

    \sa isValid(), QAbstractItemModel
*/

/*!
    \fn QModelIndex::QModelIndex(int row, int column, void *data, const QAbstractItemModel *model)

    \internal

    Creates a new model index at the given \a row and \a column,
    pointing to some \a data.
*/

/*!
    \fn int QModelIndex::row() const

    Returns the row this model index refers to.
*/


/*!
    \fn int QModelIndex::column() const

    Returns the column this model index refers to.
*/


/*!
    \fn void *QModelIndex::internalPointer() const

    Returns a \c{void} \c{*} pointer used by the model to associate
    the index with the internal data structure.

    \sa QAbstractItemModel::createIndex()
*/

/*!
    \fn const void *QModelIndex::constInternalPointer() const

    Returns a \c{const void} \c{*} pointer used by the model to associate
    the index with the internal data structure.

    \sa QAbstractItemModel::createIndex()
*/

/*!
    \fn quintptr QModelIndex::internalId() const

    Returns a \c{quintptr} used by the model to associate
    the index with the internal data structure.

    \sa QAbstractItemModel::createIndex()
*/

/*!
    \fn bool QModelIndex::isValid() const

    Returns \c{true} if this model index is valid; otherwise returns \c{false}.

    A valid index belongs to a model, and has non-negative row and column
    numbers.

    \sa model(), row(), column()
*/

/*!
    \fn const QAbstractItemModel *QModelIndex::model() const

    Returns a pointer to the model containing the item that this index
    refers to.

    A const pointer to the model is returned because calls to non-const
    functions of the model might invalidate the model index and possibly
    crash your application.
*/

/*!
    \fn QModelIndex QModelIndex::sibling(int row, int column) const

    Returns the sibling at \a row and \a column. If there is no sibling at this
    position, an invalid QModelIndex is returned.

    \sa parent(), siblingAtColumn(), siblingAtRow()
*/

/*!
    \fn QModelIndex QModelIndex::siblingAtColumn(int column) const

    Returns the sibling at \a column for the current row. If there is no sibling
    at this position, an invalid QModelIndex is returned.

    \sa sibling(), siblingAtRow()
    \since 5.11
*/

/*!
    \fn QModelIndex QModelIndex::siblingAtRow(int row) const

    Returns the sibling at \a row for the current column. If there is no sibling
    at this position, an invalid QModelIndex is returned.

    \sa sibling(), siblingAtColumn()
    \since 5.11
*/

/*!
    \fn QVariant QModelIndex::data(int role) const

    Returns the data for the given \a role for the item referred to by the
    index, or a default-constructed QVariant if this model index is
    \l{isValid()}{invalid}.
*/

/*!
    \fn void QModelIndex::multiData(QModelRoleDataSpan roleDataSpan) const
    \since 6.0

    Populates the given \a roleDataSpan for the item referred to by the
    index.
*/

/*!
    \fn Qt::ItemFlags QModelIndex::flags() const
    \since 4.2

    Returns the flags for the item referred to by the index.
*/

/*!
    \fn bool QModelIndex::operator==(const QModelIndex &lhs, const QModelIndex &rhs)

    Returns \c{true} if \a lhs model index refers to the same location as the
    \a rhs model index; otherwise returns \c{false}.

    The internal data pointer, row, column, and model values are used when
    comparing with another model index.
*/

/*!
    \fn bool QModelIndex::operator!=(const QModelIndex &lhs, const QModelIndex &rhs)

    Returns \c{true} if \a lhs model index does not refer to the same location as
    the \a rhs model index; otherwise returns \c{false}.
*/

/*!
    \fn QModelIndex QModelIndex::parent() const

    Returns the parent of the model index, or QModelIndex() if it has no
    parent.

    \sa sibling(), model()
*/

/*!
    \class QAbstractItemModel
    \inmodule QtCore

    \brief The QAbstractItemModel class provides the abstract interface for
    item model classes.

    \ingroup model-view


    The QAbstractItemModel class defines the standard interface that item
    models must use to be able to interoperate with other components in the
    model/view architecture. It is not supposed to be instantiated directly.
    Instead, you should subclass it to create new models.

    The QAbstractItemModel class is one of the \l{Model/View Classes}
    and is part of Qt's \l{Model/View Programming}{model/view framework}. It
    can be used as the underlying data model for the item view elements in
    QML or the item view classes in the Qt Widgets module.

    If you need a model to use with an item view such as QML's List View
    element or the C++ widgets QListView or QTableView, you should consider
    subclassing QAbstractListModel or QAbstractTableModel instead of this class.

    The underlying data model is exposed to views and delegates as a hierarchy
    of tables. If you do not make use of the hierarchy, then the model is a
    simple table of rows and columns. Each item has a unique index specified by
    a QModelIndex.

    \image modelindex-no-parent.png

    Every item of data that can be accessed via a model has an associated model
    index. You can obtain this model index using the index() function. Each
    index may have a sibling() index; child items have a parent() index.

    Each item has a number of data elements associated with it and they can be
    retrieved by specifying a role (see \l Qt::ItemDataRole) to the model's
    data() function. Data for all available roles can be obtained at the same
    time using the itemData() function.

    Data for each role is set using a particular \l Qt::ItemDataRole. Data for
    individual roles are set individually with setData(), or they can be set
    for all roles with setItemData().

    Items can be queried with flags() (see \l Qt::ItemFlag) to see if they can
    be selected, dragged, or manipulated in other ways.

    If an item has child objects, hasChildren() returns \c{true} for the
    corresponding index.

    The model has a rowCount() and a columnCount() for each level of the
    hierarchy. Rows and columns can be inserted and removed with insertRows(),
    insertColumns(), removeRows(), and removeColumns().

    The model emits signals to indicate changes. For example, dataChanged() is
    emitted whenever items of data made available by the model are changed.
    Changes to the headers supplied by the model cause headerDataChanged() to
    be emitted. If the structure of the underlying data changes, the model can
    emit layoutChanged() to indicate to any attached views that they should
    redisplay any items shown, taking the new structure into account.

    The items available through the model can be searched for particular data
    using the match() function.

    To sort the model, you can use sort().


    \section1 Subclassing

    \note Some general guidelines for subclassing models are available in the
    \l{Model Subclassing Reference}.

    When subclassing QAbstractItemModel, at the very least you must implement
    index(), parent(), rowCount(), columnCount(), and data(). These functions
    are used in all read-only models, and form the basis of editable models.

    You can also reimplement hasChildren() to provide special behavior for
    models where the implementation of rowCount() is expensive. This makes it
    possible for models to restrict the amount of data requested by views, and
    can be used as a way to implement lazy population of model data.

    To enable editing in your model, you must also implement setData(), and
    reimplement flags() to ensure that \c ItemIsEditable is returned.  You can
    also reimplement headerData() and setHeaderData() to control the way the
    headers for your model are presented.

    The dataChanged() and headerDataChanged() signals must be emitted
    explicitly when reimplementing the setData() and setHeaderData() functions,
    respectively.

    Custom models need to create model indexes for other components to use. To
    do this, call createIndex() with suitable row and column numbers for the
    item, and an identifier for it, either as a pointer or as an integer value.
    The combination of these values must be unique for each item. Custom models
    typically use these unique identifiers in other reimplemented functions to
    retrieve item data and access information about the item's parents and
    children. See the \l{Simple Tree Model Example} for more information about
    unique identifiers.

    It is not necessary to support every role defined in Qt::ItemDataRole.
    Depending on the type of data contained within a model, it may only be
    useful to implement the data() function to return valid information for
    some of the more common roles. Most models provide at least a textual
    representation of item data for the Qt::DisplayRole, and well-behaved
    models should also provide valid information for the Qt::ToolTipRole and
    Qt::WhatsThisRole. Supporting these roles enables models to be used with
    standard Qt views. However, for some models that handle highly-specialized
    data, it may be appropriate to provide data only for user-defined roles.

    Models that provide interfaces to resizable data structures can provide
    implementations of insertRows(), removeRows(), insertColumns(),and
    removeColumns(). When implementing these functions, it is important to
    notify any connected views about changes to the model's dimensions both
    \e before and \e after they occur:

    \list
        \li An insertRows() implementation must call beginInsertRows() \e before
           inserting new rows into the data structure, and endInsertRows()
           \e{immediately afterwards}.
        \li An insertColumns() implementation must call beginInsertColumns()
           \e before inserting new columns into the data structure, and
           endInsertColumns() \e{immediately afterwards}.
        \li A removeRows() implementation must call beginRemoveRows() \e before
           the rows are removed from the data structure, and endRemoveRows()
           \e{immediately afterwards}.
        \li A removeColumns() implementation must call beginRemoveColumns()
           \e before the columns are removed from the data structure, and
           endRemoveColumns() \e{immediately afterwards}.
    \endlist

    The \e private signals that these functions emit give attached components
    the chance to take action before any data becomes unavailable. The
    encapsulation of the insert and remove operations with these begin and end
    functions also enables the model to manage \l{QPersistentModelIndex}
    {persistent model indexes} correctly. \b{If you want selections to be
    handled properly, you must ensure that you call these functions.} If you
    insert or remove an item with children, you do not need to call these
    functions for the child items. In other words, the parent item will take
    care of its child items.

    To create models that populate incrementally, you can reimplement
    fetchMore() and canFetchMore(). If the reimplementation of fetchMore() adds
    rows to the model, \l{QAbstractItemModel::}{beginInsertRows()} and
    \l{QAbstractItemModel::}{endInsertRows()} must be called.

    \include models.qdocinc {thread-safety-section1}{QAbstractItemModel}

    \sa {Model Classes}, {Model Subclassing Reference}, QModelIndex,
        QAbstractItemView, {Using drag and drop with item views},
        {Simple Tree Model Example}, {Editable Tree Model Example},
        {Fetch More Example}
*/

/*!
    \fn QModelIndex QAbstractItemModel::index(int row, int column, const QModelIndex &parent) const = 0

    Returns the index of the item in the model specified by the given \a row,
    \a column and \a parent index.

    When reimplementing this function in a subclass, call createIndex() to
    generate model indexes that other components can use to refer to items in
    your model.

    \sa createIndex()
*/

/*!
    \fn bool QAbstractItemModel::insertColumn(int column, const QModelIndex &parent)

    Inserts a single column before the given \a column in the child items of
    the \a parent specified.

    Returns \c{true} if the column is inserted; otherwise returns \c{false}.

    \sa insertColumns(), insertRow(), removeColumn()
*/

/*!
    \fn bool QAbstractItemModel::insertRow(int row, const QModelIndex &parent)

    Inserts a single row before the given \a row in the child items of the
    \a parent specified.

    \note This function calls the virtual method insertRows.

    Returns \c{true} if the row is inserted; otherwise returns \c{false}.

    \sa insertRows(), insertColumn(), removeRow()
*/

/*!
    \fn QModelIndex QAbstractItemModel::parent(const QModelIndex &index) const = 0

    Returns the parent of the model item with the given \a index. If the item
    has no parent, an invalid QModelIndex is returned.

    A common convention used in models that expose tree data structures is that
    only items in the first column have children. For that case, when
    reimplementing this function in a subclass the column of the returned
    QModelIndex would be 0.

    When reimplementing this function in a subclass, be careful to avoid
    calling QModelIndex member functions, such as QModelIndex::parent(), since
    indexes belonging to your model will simply call your implementation,
    leading to infinite recursion.

    \sa createIndex()
*/

/*!
    \fn bool QAbstractItemModel::removeColumn(int column, const QModelIndex &parent)

    Removes the given \a column from the child items of the \a parent
    specified.

    Returns \c{true} if the column is removed; otherwise returns \c{false}.

    \sa removeColumns(), removeRow(), insertColumn()
*/

/*!
    \fn bool QAbstractItemModel::removeRow(int row, const QModelIndex &parent)

    Removes the given \a row from the child items of the \a parent specified.

    Returns \c{true} if the row is removed; otherwise returns \c{false}.

    This is a convenience function that calls removeRows(). The
    QAbstractItemModel implementation of removeRows() does nothing.

    \sa removeRows(), removeColumn(), insertRow()
*/

/*!
    \fn bool QAbstractItemModel::moveRow(const QModelIndex &sourceParent, int sourceRow, const QModelIndex &destinationParent, int destinationChild)

    On models that support this, moves \a sourceRow from \a sourceParent to \a destinationChild under
    \a destinationParent.

    Returns \c{true} if the rows were successfully moved; otherwise returns
    \c{false}.

    \sa moveRows(), moveColumn()
*/

/*!
    \fn bool QAbstractItemModel::moveColumn(const QModelIndex &sourceParent, int sourceColumn, const QModelIndex &destinationParent, int destinationChild)

    On models that support this, moves \a sourceColumn from \a sourceParent to \a destinationChild under
    \a destinationParent.

    Returns \c{true} if the columns were successfully moved; otherwise returns
    \c{false}.

    \sa moveColumns(), moveRow()
*/


/*!
    \fn void QAbstractItemModel::headerDataChanged(Qt::Orientation orientation, int first, int last)

    This signal is emitted whenever a header is changed. The \a orientation
    indicates whether the horizontal or vertical header has changed. The
    sections in the header from the \a first to the \a last need to be updated.

    When reimplementing the setHeaderData() function, this signal must be
    emitted explicitly.

    If you are changing the number of columns or rows you do not need to emit
    this signal, but use the begin/end functions (refer to the section on
    subclassing in the QAbstractItemModel class description for details).

    \sa headerData(), setHeaderData(), dataChanged()
*/


/*!
    \enum QAbstractItemModel::LayoutChangeHint

    This enum describes the way the model changes layout.

    \value NoLayoutChangeHint   No hint is available.
    \value VerticalSortHint     Rows are being sorted.
    \value HorizontalSortHint   Columns are being sorted.

    Note that VerticalSortHint and HorizontalSortHint carry the meaning that
    items are being moved within the same parent, not moved to a different
    parent in the model, and not filtered out or in.
*/

/*!
    \fn void QAbstractItemModel::layoutAboutToBeChanged(const QList<QPersistentModelIndex> &parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint)
    \since 5.0

    This signal is emitted just before the layout of a model is changed.
    Components connected to this signal use it to adapt to changes in the
    model's layout.

    Subclasses should update any persistent model indexes after emitting
    layoutAboutToBeChanged().

    The optional \a parents parameter is used to give a more specific notification
    about what parts of the layout of the model are changing. An empty list indicates
    a change to the layout of the entire model. The order of elements in the \a parents list is not significant. The optional \a hint parameter is used
    to give a hint about what is happening while the model is relayouting.

    \sa layoutChanged(), changePersistentIndex()
*/

/*!
    \fn void QAbstractItemModel::layoutChanged(const QList<QPersistentModelIndex> &parents = QList<QPersistentModelIndex>(), QAbstractItemModel::LayoutChangeHint hint = QAbstractItemModel::NoLayoutChangeHint)
    \since 5.0

    This signal is emitted whenever the layout of items exposed by the model
    has changed; for example, when the model has been sorted. When this signal
    is received by a view, it should update the layout of items to reflect this
    change.

    When subclassing QAbstractItemModel or QAbstractProxyModel, ensure that you
    emit layoutAboutToBeChanged() before changing the order of items or
    altering the structure of the data you expose to views, and emit
    layoutChanged() after changing the layout.

    The optional \a parents parameter is used to give a more specific notification
    about what parts of the layout of the model are changing. An empty list indicates
    a change to the layout of the entire model. The order of elements in the \a parents list is not significant. The optional \a hint parameter is used
    to give a hint about what is happening while the model is relayouting.

    Subclasses should update any persistent model indexes before emitting
    layoutChanged(). In other words, when the structure changes:

    \list
        \li  emit layoutAboutToBeChanged
        \li  Remember the QModelIndex that will change
        \li  Update your internal data
        \li  Call changePersistentIndex()
        \li  emit layoutChanged
    \endlist

    \sa layoutAboutToBeChanged(), dataChanged(), headerDataChanged(), modelReset(),
        changePersistentIndex()
*/

/*!
    Constructs an abstract item model with the given \a parent.
*/
QAbstractItemModel::QAbstractItemModel(QObject *parent)
    : QObject(*new QAbstractItemModelPrivate, parent)
{
}

/*!
  \internal
*/
QAbstractItemModel::QAbstractItemModel(QAbstractItemModelPrivate &dd, QObject *parent)
    : QObject(dd, parent)
{
}

/*!
    Destroys the abstract item model.
*/
QAbstractItemModel::~QAbstractItemModel()
{
    d_func()->invalidatePersistentIndexes();
}


/*!
    \fn int QAbstractItemModel::rowCount(const QModelIndex &parent) const

    Returns the number of rows under the given \a parent. When the parent is
    valid it means that rowCount is returning the number of children of parent.

    \note When implementing a table based model, rowCount() should return 0
    when the parent is valid.

    \sa columnCount()
*/

/*!
    \fn int QAbstractItemModel::columnCount(const QModelIndex &parent) const

    Returns the number of columns for the children of the given \a parent.

    In most subclasses, the number of columns is independent of the \a parent.

    For example:

    \code
    int MyModel::columnCount(const QModelIndex &parent) const
    {
        Q_UNUSED(parent);
        return 3;
    }
    \endcode

    \note When implementing a table based model, columnCount() should return 0
    when the parent is valid.

    \sa rowCount()
*/

/*!
    \fn void QAbstractItemModel::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles = QList<int>())

    This signal is emitted whenever the data in an existing item changes.

    If the items are of the same parent, the affected ones are those between
    \a topLeft and \a bottomRight inclusive. If the items do not have the same
    parent, the behavior is undefined.

    When reimplementing the setData() function, this signal must be emitted
    explicitly.

    The optional \a roles argument can be used to specify which data roles have actually
    been modified. An empty vector in the roles argument means that all roles should be
    considered modified. The order of elements in the roles argument does not have any
    relevance.

    \sa headerDataChanged(), setData(), layoutChanged()
*/

/*!
    \fn void QAbstractItemModel::rowsInserted(const QModelIndex &parent, int first, int last)

    This signal is emitted after rows have been inserted into the
    model. The new items are those between \a first and \a last
    inclusive, under the given \a parent item.

    \note Components connected to this signal use it to adapt to changes in the
    model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa insertRows(), beginInsertRows()
*/

/*!
    \fn void QAbstractItemModel::rowsAboutToBeInserted(const QModelIndex &parent, int start, int end)

    This signal is emitted just before rows are inserted into the model. The
    new items will be positioned between \a start and \a end inclusive, under
    the given \a parent item.

    \note Components connected to this signal use it to adapt to changes
    in the model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa insertRows(), beginInsertRows()
*/

/*!
    \fn void QAbstractItemModel::rowsRemoved(const QModelIndex &parent, int first, int last)

    This signal is emitted after rows have been removed from the model. The
    removed items are those between \a first and \a last inclusive, under the
    given \a parent item.

    \note Components connected to this signal use it to adapt to changes
    in the model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa removeRows(), beginRemoveRows()
*/

/*!
    \fn void QAbstractItemModel::rowsAboutToBeRemoved(const QModelIndex &parent, int first, int last)

    This signal is emitted just before rows are removed from the model. The
    items that will be removed are those between \a first and \a last inclusive,
    under the given \a parent item.

    \note Components connected to this signal use it to adapt to changes
    in the model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa removeRows(), beginRemoveRows()
*/

/*!
    \fn void QAbstractItemModel::rowsMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow)
    \since 4.6

    This signal is emitted after rows have been moved within the
    model. The items between \a sourceStart and \a sourceEnd
    inclusive, under the given \a sourceParent item have been moved to \a destinationParent
    starting at the row \a destinationRow.

    \b{Note:} Components connected to this signal use it to adapt to changes
    in the model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa beginMoveRows()
*/

/*!
    \fn void QAbstractItemModel::rowsAboutToBeMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationRow)
    \since 4.6

    This signal is emitted just before rows are moved within the
    model. The items that will be moved are those between \a sourceStart and \a sourceEnd
    inclusive, under the given \a sourceParent item. They will be moved to \a destinationParent
    starting at the row \a destinationRow.

    \b{Note:} Components connected to this signal use it to adapt to changes
    in the model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa beginMoveRows()
*/

/*!
    \fn void QAbstractItemModel::columnsMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn)
    \since 4.6

    This signal is emitted after columns have been moved within the
    model. The items between \a sourceStart and \a sourceEnd
    inclusive, under the given \a sourceParent item have been moved to \a destinationParent
    starting at the column \a destinationColumn.

    \b{Note:} Components connected to this signal use it to adapt to changes
    in the model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa beginMoveRows()
*/

/*!
    \fn void QAbstractItemModel::columnsAboutToBeMoved(const QModelIndex &sourceParent, int sourceStart, int sourceEnd, const QModelIndex &destinationParent, int destinationColumn)
    \since 4.6

    This signal is emitted just before columns are moved within the
    model. The items that will be moved are those between \a sourceStart and \a sourceEnd
    inclusive, under the given \a sourceParent item. They will be moved to \a destinationParent
    starting at the column \a destinationColumn.

    \b{Note:} Components connected to this signal use it to adapt to changes
    in the model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa beginMoveRows()
*/

/*!
    \fn void QAbstractItemModel::columnsInserted(const QModelIndex &parent, int first, int last)

    This signal is emitted after columns have been inserted into the model. The
    new items are those between \a first and \a last inclusive, under the given
    \a parent item.

    \note Components connected to this signal use it to adapt to changes in the
    model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa insertColumns(), beginInsertColumns()
*/

/*!
    \fn void QAbstractItemModel::columnsAboutToBeInserted(const QModelIndex &parent, int first, int last)

    This signal is emitted just before columns are inserted into the model. The
    new items will be positioned between \a first and \a last inclusive, under
    the given \a parent item.

    \note Components connected to this signal use it to adapt to changes in the
    model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa insertColumns(), beginInsertColumns()
*/

/*!
    \fn void QAbstractItemModel::columnsRemoved(const QModelIndex &parent, int first, int last)

    This signal is emitted after columns have been removed from the model.
    The removed items are those between \a first and \a last inclusive,
    under the given \a parent item.

    \note Components connected to this signal use it to adapt to changes in
    the model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa removeColumns(), beginRemoveColumns()
*/

/*!
    \fn void QAbstractItemModel::columnsAboutToBeRemoved(const QModelIndex &parent, int first, int last)

    This signal is emitted just before columns are removed from the model. The
    items to be removed are those between \a first and \a last inclusive, under
    the given \a parent item.

    \note Components connected to this signal use it to adapt to changes in the
    model's dimensions. It can only be emitted by the QAbstractItemModel
    implementation, and cannot be explicitly emitted in subclass code.

    \sa removeColumns(), beginRemoveColumns()
*/

/*!
    Returns \c{true} if the model returns a valid QModelIndex for \a row and
    \a column with \a parent, otherwise returns \c{false}.
*/
bool QAbstractItemModel::hasIndex(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || column < 0)
        return false;
    return row < rowCount(parent) && column < columnCount(parent);
}


/*!
    Returns \c{true} if \a parent has any children; otherwise returns \c{false}.

    Use rowCount() on the parent to find out the number of children.

    Note that it is undefined behavior to report that a particular index hasChildren
    with this method if the same index has the flag Qt::ItemNeverHasChildren set.

    \sa parent(), index()
*/
bool QAbstractItemModel::hasChildren(const QModelIndex &parent) const
{
    return (rowCount(parent) > 0) && (columnCount(parent) > 0);
}

/*!
    \fn QModelIndex QAbstractItemModel::sibling(int row, int column, const QModelIndex &index) const

    Returns the sibling at \a row and \a column for the item at \a index, or an
    invalid QModelIndex if there is no sibling at that location.

    sibling() is just a convenience function that finds the item's parent, and
    uses it to retrieve the index of the child item in the specified \a row and
    \a column.

    This method can optionally be overridden for implementation-specific optimization.

    \sa index(), QModelIndex::row(), QModelIndex::column()
*/
QModelIndex QAbstractItemModel::sibling(int row, int column, const QModelIndex &idx) const
{
    return (row == idx.row() && column == idx.column()) ? idx : index(row, column, parent(idx));
}


/*!
    Returns a map with values for all predefined roles in the model for the
    item at the given \a index.

    Reimplement this function if you want to extend the default behavior of
    this function to include custom roles in the map.

    \sa Qt::ItemDataRole, data()
*/
QMap<int, QVariant> QAbstractItemModel::itemData(const QModelIndex &index) const
{
    QMap<int, QVariant> roles;
    for (int i = 0; i < Qt::UserRole; ++i) {
        QVariant variantData = data(index, i);
        if (variantData.isValid())
            roles.insert(i, variantData);
    }
    return roles;
}

/*!
    Sets the \a role data for the item at \a index to \a value.

    Returns \c{true} if successful; otherwise returns \c{false}.

    The dataChanged() signal should be emitted if the data was successfully
    set.

    The base class implementation returns \c{false}. This function and data() must
    be reimplemented for editable models.

    \sa Qt::ItemDataRole, data(), itemData()
*/
bool QAbstractItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(index);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return false;
}

/*!
    \since 6.0
    Removes the data stored in all the roles for the given \a index.
    Returns \c{true} if successful; otherwise returns \c{false}.
    The dataChanged() signal should be emitted if the data was successfully
    removed.
    The base class implementation returns \c{false}
    \sa data(), itemData(), setData(), setItemData()
*/
bool QAbstractItemModel::clearItemData(const QModelIndex &index)
{
    Q_UNUSED(index);
    return false;
}

/*!
    \fn QVariant QAbstractItemModel::data(const QModelIndex &index, int role) const = 0

    Returns the data stored under the given \a role for the item referred to
    by the \a index.

    \note If you do not have a value to return, return an \b invalid
    (default-constructed) QVariant.

    \sa Qt::ItemDataRole, setData(), headerData()
*/

/*!
    Sets the role data for the item at \a index to the associated value in
    \a roles, for every Qt::ItemDataRole.

    Returns \c{true} if successful; otherwise returns \c{false}.

    Roles that are not in \a roles will not be modified.

    \sa setData(), data(), itemData()
*/
bool QAbstractItemModel::setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles)
{
    // ### TODO: Consider change the semantics of this function,
    // or deprecating/removing it altogether.
    //
    // For instance, it should try setting *all* the data
    // in \a roles, and not bail out at the first setData that returns
    // false. It should also have a transactional approach.
    for (auto it = roles.begin(), e = roles.end(); it != e; ++it) {
        if (!setData(index, it.value(), it.key()))
            return false;
    }
    return true;
}

/*!
    Returns the list of allowed MIME types. By default, the built-in
    models and views use an internal MIME type:
    \c{application/x-qabstractitemmodeldatalist}.

    When implementing drag and drop support in a custom model, if you
    will return data in formats other than the default internal MIME
    type, reimplement this function to return your list of MIME types.

    If you reimplement this function in your custom model, you must
    also reimplement the member functions that call it: mimeData() and
    dropMimeData().

    \sa mimeData(), dropMimeData()
*/
QStringList QAbstractItemModel::mimeTypes() const
{
    QStringList types;
    types << QStringLiteral("application/x-qabstractitemmodeldatalist");
    return types;
}

/*!
    Returns an object that contains serialized items of data corresponding to
    the list of \a indexes specified. The format used to describe the encoded
    data is obtained from the mimeTypes() function. This default implementation
    uses the default MIME type returned by the default implementation of
    mimeTypes(). If you reimplement mimeTypes() in your custom model to return
    more MIME types, reimplement this function to make use of them.

    If the list of \a indexes is empty, or there are no supported MIME types,
    \nullptr is returned rather than a serialized empty list.

    \sa mimeTypes(), dropMimeData()
*/
QMimeData *QAbstractItemModel::mimeData(const QModelIndexList &indexes) const
{
    if (indexes.size() <= 0)
        return nullptr;
    QStringList types = mimeTypes();
    if (types.isEmpty())
        return nullptr;
    QMimeData *data = new QMimeData();
    QString format = types.at(0);
    QByteArray encoded;
    QDataStream stream(&encoded, QDataStream::WriteOnly);
    encodeData(indexes, stream);
    data->setData(format, encoded);
    return data;
}

/*!
    Returns \c{true} if a model can accept a drop of the \a data. This
    default implementation only checks if \a data has at least one format
    in the list of mimeTypes() and if \a action is among the
    model's supportedDropActions().

    Reimplement this function in your custom model, if you want to
    test whether the \a data can be dropped at \a row, \a column,
    \a parent with \a action. If you don't need that test, it is not
    necessary to reimplement this function.

    \sa dropMimeData(), {Using drag and drop with item views}
 */
bool QAbstractItemModel::canDropMimeData(const QMimeData *data, Qt::DropAction action,
                                         int row, int column,
                                         const QModelIndex &parent) const
{
    Q_UNUSED(row);
    Q_UNUSED(column);
    Q_UNUSED(parent);

    if (!(action & supportedDropActions()))
        return false;

    const QStringList modelTypes = mimeTypes();
    for (int i = 0; i < modelTypes.size(); ++i) {
        if (data->hasFormat(modelTypes.at(i)))
            return true;
    }
    return false;
}

/*!
    Handles the \a data supplied by a drag and drop operation that ended with
    the given \a action.

    Returns \c{true} if the data and action were handled by the model; otherwise
    returns \c{false}.

    The specified \a row, \a column and \a parent indicate the location of an
    item in the model where the operation ended. It is the responsibility of
    the model to complete the action at the correct location.

    For instance, a drop action on an item in a QTreeView can result in new
    items either being inserted as children of the item specified by \a row,
    \a column, and \a parent, or as siblings of the item.

    When \a row and \a column are -1 it means that the dropped data should be
    considered as dropped directly on \a parent. Usually this will mean
    appending the data as child items of \a parent. If \a row and \a column are
    greater than or equal zero, it means that the drop occurred just before the
    specified \a row and \a column in the specified \a parent.

    The mimeTypes() member is called to get the list of acceptable MIME types.
    This default implementation assumes the default implementation of mimeTypes(),
    which returns a single default MIME type. If you reimplement mimeTypes() in
    your custom model to return multiple MIME types, you must reimplement this
    function to make use of them.

    \sa supportedDropActions(), canDropMimeData(), {Using drag and drop with item views}
*/
bool QAbstractItemModel::dropMimeData(const QMimeData *data, Qt::DropAction action,
                                      int row, int column, const QModelIndex &parent)
{
    // check if the action is supported
    if (!data || !(action == Qt::CopyAction || action == Qt::MoveAction))
        return false;
    // check if the format is supported
    QStringList types = mimeTypes();
    if (types.isEmpty())
        return false;
    QString format = types.at(0);
    if (!data->hasFormat(format))
        return false;
    if (row > rowCount(parent))
        row = rowCount(parent);
    if (row == -1)
        row = rowCount(parent);
    if (column == -1)
        column = 0;
    // decode and insert
    QByteArray encoded = data->data(format);
    QDataStream stream(&encoded, QDataStream::ReadOnly);
    return decodeData(row, column, parent, stream);
}

/*!
    \since 4.2

    Returns the drop actions supported by this model.

    The default implementation returns Qt::CopyAction. Reimplement this
    function if you wish to support additional actions. You must also
    reimplement the dropMimeData() function to handle the additional
    operations.

    \sa dropMimeData(), Qt::DropActions, {Using drag and drop with item
    views}
*/
Qt::DropActions QAbstractItemModel::supportedDropActions() const
{
    return Qt::CopyAction;
}

/*!
    Returns the actions supported by the data in this model.

    The default implementation returns supportedDropActions(). Reimplement
    this function if you wish to support additional actions.

    supportedDragActions() is used by QAbstractItemView::startDrag() as the
    default values when a drag occurs.

    \sa Qt::DropActions, {Using drag and drop with item views}
*/
Qt::DropActions QAbstractItemModel::supportedDragActions() const
{
    return supportedDropActions();
}

/*!
    \note The base class implementation of this function does nothing and
    returns \c{false}.

    On models that support this, inserts \a count rows into the model before
    the given \a row. Items in the new row will be children of the item
    represented by the \a parent model index.

    If \a row is 0, the rows are prepended to any existing rows in the parent.

    If \a row is rowCount(), the rows are appended to any existing rows in the
    parent.

    If \a parent has no children, a single column with \a count rows is
    inserted.

    Returns \c{true} if the rows were successfully inserted; otherwise returns
    \c{false}.

    If you implement your own model, you can reimplement this function if you
    want to support insertions. Alternatively, you can provide your own API for
    altering the data. In either case, you will need to call
    beginInsertRows() and endInsertRows() to notify other components that the
    model has changed.

    \sa insertColumns(), removeRows(), beginInsertRows(), endInsertRows()
*/
bool QAbstractItemModel::insertRows(int, int, const QModelIndex &)
{
    return false;
}

/*!
    On models that support this, inserts \a count new columns into the model
    before the given \a column. The items in each new column will be children
    of the item represented by the \a parent model index.

    If \a column is 0, the columns are prepended to any existing columns.

    If \a column is columnCount(), the columns are appended to any existing
    columns.

    If \a parent has no children, a single row with \a count columns is
    inserted.

    Returns \c{true} if the columns were successfully inserted; otherwise returns
    \c{false}.

    The base class implementation does nothing and returns \c{false}.

    If you implement your own model, you can reimplement this function if you
    want to support insertions. Alternatively, you can provide your own API for
    altering the data.

    \sa insertRows(), removeColumns(), beginInsertColumns(), endInsertColumns()
*/
bool QAbstractItemModel::insertColumns(int, int, const QModelIndex &)
{
    return false;
}

/*!
    On models that support this, removes \a count rows starting with the given
    \a row under parent \a parent from the model.

    Returns \c{true} if the rows were successfully removed; otherwise returns
    \c{false}.

    The base class implementation does nothing and returns \c{false}.

    If you implement your own model, you can reimplement this function if you
    want to support removing. Alternatively, you can provide your own API for
    altering the data.

    \sa removeRow(), removeColumns(), insertColumns(), beginRemoveRows(),
        endRemoveRows()
*/
bool QAbstractItemModel::removeRows(int, int, const QModelIndex &)
{
    return false;
}

/*!
    On models that support this, removes \a count columns starting with the
    given \a column under parent \a parent from the model.

    Returns \c{true} if the columns were successfully removed; otherwise returns
    \c{false}.

    The base class implementation does nothing and returns \c{false}.

    If you implement your own model, you can reimplement this function if you
    want to support removing. Alternatively, you can provide your own API for
    altering the data.

    \sa removeColumn(), removeRows(), insertColumns(), beginRemoveColumns(),
        endRemoveColumns()
*/
bool QAbstractItemModel::removeColumns(int, int, const QModelIndex &)
{
    return false;
}

/*!
    On models that support this, moves \a count rows starting with the given
    \a sourceRow under parent \a sourceParent to row \a destinationChild under
    parent \a destinationParent.

    Returns \c{true} if the rows were successfully moved; otherwise returns
    \c{false}.

    The base class implementation does nothing and returns \c{false}.

    If you implement your own model, you can reimplement this function if you
    want to support moving. Alternatively, you can provide your own API for
    altering the data.

    \sa beginMoveRows(), endMoveRows()
*/
bool QAbstractItemModel::moveRows(const QModelIndex &, int , int , const QModelIndex &, int)
{
    return false;
}

/*!
    On models that support this, moves \a count columns starting with the given
    \a sourceColumn under parent \a sourceParent to column \a destinationChild under
    parent \a destinationParent.

    Returns \c{true} if the columns were successfully moved; otherwise returns
    \c{false}.

    The base class implementation does nothing and returns \c{false}.

    If you implement your own model, you can reimplement this function if you
    want to support moving. Alternatively, you can provide your own API for
    altering the data.

    \sa beginMoveColumns(), endMoveColumns()
*/
bool QAbstractItemModel::moveColumns(const QModelIndex &, int , int , const QModelIndex &, int)
{
    return false;
}

/*!
    Fetches any available data for the items with the parent specified by the
    \a parent index.

    Reimplement this if you are populating your model incrementally.

    The default implementation does nothing.

    \sa canFetchMore()
*/
void QAbstractItemModel::fetchMore(const QModelIndex &)
{
    // do nothing
}

/*!
    Returns \c{true} if there is more data available for \a parent; otherwise
    returns \c{false}.

    The default implementation always returns \c{false}.

    If canFetchMore() returns \c true, the fetchMore() function should
    be called. This is the behavior of QAbstractItemView, for example.

    \sa fetchMore()
*/
bool QAbstractItemModel::canFetchMore(const QModelIndex &) const
{
    return false;
}

/*!
    Returns the item flags for the given \a index.

    The base class implementation returns a combination of flags that enables
    the item (\c ItemIsEnabled) and allows it to be selected
    (\c ItemIsSelectable).

    \sa Qt::ItemFlags
*/
Qt::ItemFlags QAbstractItemModel::flags(const QModelIndex &index) const
{
    Q_D(const QAbstractItemModel);
    if (!d->indexValid(index))
        return { };

    return Qt::ItemIsSelectable|Qt::ItemIsEnabled;
}

/*!
    Sorts the model by \a column in the given \a order.

    The base class implementation does nothing.
*/
void QAbstractItemModel::sort(int column, Qt::SortOrder order)
{
    Q_UNUSED(column);
    Q_UNUSED(order);
    // do nothing
}

/*!
    Returns a model index for the buddy of the item represented by \a index.
    When the user wants to edit an item, the view will call this function to
    check whether another item in the model should be edited instead. Then, the
    view will construct a delegate using the model index returned by the buddy
    item.

    The default implementation of this function has each item as its own buddy.
*/
QModelIndex QAbstractItemModel::buddy(const QModelIndex &index) const
{
    return index;
}

/*!
    Returns a list of indexes for the items in the column of the \a start index
    where data stored under the given \a role matches the specified \a value.
    The way the search is performed is defined by the \a flags given. The list
    that is returned may be empty. Note also that the order of results in the
    list may not correspond to the order in the model, if for example a proxy
    model is used. The order of the results cannot be relied upon.

    The search begins from the \a start index, and continues until the number
    of matching data items equals \a hits, the search reaches the last row, or
    the search reaches \a start again - depending on whether \c MatchWrap is
    specified in \a flags. If you want to search for all matching items, use
    \a hits = -1.

    By default, this function will perform a wrapping, string-based comparison
    on all items, searching for items that begin with the search term specified
    by \a value.

    \note The default implementation of this function only searches columns.
    Reimplement this function to include a different search behavior.
*/
QModelIndexList QAbstractItemModel::match(const QModelIndex &start, int role,
                                          const QVariant &value, int hits,
                                          Qt::MatchFlags flags) const
{
    QModelIndexList result;
    uint matchType = (flags & Qt::MatchTypeMask).toInt();
    Qt::CaseSensitivity cs = flags & Qt::MatchCaseSensitive ? Qt::CaseSensitive : Qt::CaseInsensitive;
    bool recurse = flags.testAnyFlag(Qt::MatchRecursive);
    bool wrap = flags.testAnyFlag(Qt::MatchWrap);
    bool allHits = (hits == -1);
    QString text; // only convert to a string if it is needed
#if QT_CONFIG(regularexpression)
    QRegularExpression rx; // only create it if needed
#endif
    const int column = start.column();
    QModelIndex p = parent(start);
    int from = start.row();
    int to = rowCount(p);

    // iterates twice if wrapping
    for (int i = 0; (wrap && i < 2) || (!wrap && i < 1); ++i) {
        for (int r = from; (r < to) && (allHits || result.size() < hits); ++r) {
            QModelIndex idx = index(r, column, p);
            if (!idx.isValid())
                 continue;
            QVariant v = data(idx, role);
            // QVariant based matching
            if (matchType == Qt::MatchExactly) {
                if (value == v)
                    result.append(idx);
            } else { // QString or regular expression based matching
#if QT_CONFIG(regularexpression)
                if (matchType == Qt::MatchRegularExpression) {
                    if (rx.pattern().isEmpty()) {
                        if (value.userType() == QMetaType::QRegularExpression) {
                            rx = value.toRegularExpression();
                        } else {
                            rx.setPattern(value.toString());
                            if (cs == Qt::CaseInsensitive)
                                rx.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
                        }
                    }
                } else if (matchType == Qt::MatchWildcard) {
                    if (rx.pattern().isEmpty()) {
                        const QString pattern = QRegularExpression::wildcardToRegularExpression(value.toString(), QRegularExpression::NonPathWildcardConversion);
                        rx.setPattern(pattern);
                    }
                    if (cs == Qt::CaseInsensitive)
                        rx.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
                } else
#endif
                {
                    if (text.isEmpty()) // lazy conversion
                        text = value.toString();
                }

                QString t = v.toString();
                switch (matchType) {
#if QT_CONFIG(regularexpression)
                case Qt::MatchRegularExpression:
                    Q_FALLTHROUGH();
                case Qt::MatchWildcard:
                    if (t.contains(rx))
                        result.append(idx);
                    break;
#endif
                case Qt::MatchStartsWith:
                    if (t.startsWith(text, cs))
                        result.append(idx);
                    break;
                case Qt::MatchEndsWith:
                    if (t.endsWith(text, cs))
                        result.append(idx);
                    break;
                case Qt::MatchFixedString:
                    if (t.compare(text, cs) == 0)
                        result.append(idx);
                    break;
                case Qt::MatchContains:
                default:
                    if (t.contains(text, cs))
                        result.append(idx);
                }
            }
            if (recurse) {
                const auto parent = column != 0 ? idx.sibling(idx.row(), 0) : idx;
                if (hasChildren(parent)) { // search the hierarchy
                    result += match(index(0, column, parent), role,
                                    (text.isEmpty() ? value : text),
                                    (allHits ? -1 : hits - result.size()), flags);
                }
            }
        }
        // prepare for the next iteration
        from = 0;
        to = start.row();
    }
    return result;
}

/*!
    Returns the row and column span of the item represented by \a index.

    \note Currently, span is not used.
*/

QSize QAbstractItemModel::span(const QModelIndex &) const
{
    return QSize(1, 1);
}

/*!
    \since 4.6

    Returns the model's role names.

    The default role names set by Qt are:

    \table
    \header
    \li Qt Role
    \li QML Role Name
    \row
    \li Qt::DisplayRole
    \li display
    \row
    \li Qt::DecorationRole
    \li decoration
    \row
    \li Qt::EditRole
    \li edit
    \row
    \li Qt::ToolTipRole
    \li toolTip
    \row
    \li Qt::StatusTipRole
    \li statusTip
    \row
    \li Qt::WhatsThisRole
    \li whatsThis
    \endtable
*/
QHash<int,QByteArray> QAbstractItemModel::roleNames() const
{
    // if the return value ever becomes dependent on *this, also change the following overrides:
    // - QFileSystemModel
    // - QConcatenateTablesProxyModel
    return QAbstractItemModelPrivate::defaultRoleNames();
}

/*!
    Lets the model know that it should submit cached information to permanent
    storage. This function is typically used for row editing.

    Returns \c{true} if there is no error; otherwise returns \c{false}.

    \sa revert()
*/

bool QAbstractItemModel::submit()
{
    return true;
}

/*!
    Lets the model know that it should discard cached information. This
    function is typically used for row editing.

    \sa submit()
*/

void QAbstractItemModel::revert()
{
    // do nothing
}

/*!
    Returns the data for the given \a role and \a section in the header with
    the specified \a orientation.

    For horizontal headers, the section number corresponds to the column
    number. Similarly, for vertical headers, the section number corresponds to
    the row number.

    \sa Qt::ItemDataRole, setHeaderData(), QHeaderView
*/

QVariant QAbstractItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_UNUSED(orientation);
    if (role == Qt::DisplayRole)
        return section + 1;
    return QVariant();
}

/*!
    Sets the data for the given \a role and \a section in the header with the
    specified \a orientation to the \a value supplied.

    Returns \c{true} if the header's data was updated; otherwise returns \c{false}.

    When reimplementing this function, the headerDataChanged() signal must be
    emitted explicitly.

    \sa Qt::ItemDataRole, headerData()
*/

bool QAbstractItemModel::setHeaderData(int section, Qt::Orientation orientation,
                                       const QVariant &value, int role)
{
    Q_UNUSED(section);
    Q_UNUSED(orientation);
    Q_UNUSED(value);
    Q_UNUSED(role);
    return false;
}

/*!
    \fn QModelIndex QAbstractItemModel::createIndex(int row, int column, const void *ptr) const

    Creates a model index for the given \a row and \a column with the internal
    pointer \a ptr.

    When using a QSortFilterProxyModel, its indexes have their own internal
    pointer. It is not advisable to access this internal pointer outside of the
    model. Use the data() function instead.

    This function provides a consistent interface that model subclasses must
    use to create model indexes.
*/

/*!
    \fn QModelIndex QAbstractItemModel::createIndex(int row, int column, quintptr id) const

    Creates a model index for the given \a row and \a column with the internal
    identifier, \a id.

    This function provides a consistent interface that model subclasses must
    use to create model indexes.

    \sa QModelIndex::internalId()
*/

/*!
  \internal
*/
void QAbstractItemModel::encodeData(const QModelIndexList &indexes, QDataStream &stream) const
{
    for (const auto &index : indexes)
        stream << index.row() << index.column() << itemData(index);
}

/*!
  \internal
 */
bool QAbstractItemModel::decodeData(int row, int column, const QModelIndex &parent,
                                    QDataStream &stream)
{
    int top = INT_MAX;
    int left = INT_MAX;
    int bottom = 0;
    int right = 0;
    QList<int> rows, columns;
    QList<QMap<int, QVariant>> data;

    while (!stream.atEnd()) {
        int r, c;
        QMap<int, QVariant> v;
        stream >> r >> c >> v;
        rows.append(r);
        columns.append(c);
        data.append(v);
        top = qMin(r, top);
        left = qMin(c, left);
        bottom = qMax(r, bottom);
        right = qMax(c, right);
    }

    // insert the dragged items into the table, use a bit array to avoid overwriting items,
    // since items from different tables can have the same row and column
    int dragRowCount = 0;
    int dragColumnCount = right - left + 1;

    // Compute the number of continuous rows upon insertion and modify the rows to match
    QList<int> rowsToInsert(bottom + 1);
    for (int i = 0; i < rows.size(); ++i)
        rowsToInsert[rows.at(i)] = 1;
    for (int i = 0; i < rowsToInsert.size(); ++i) {
        if (rowsToInsert.at(i) == 1){
            rowsToInsert[i] = dragRowCount;
            ++dragRowCount;
        }
    }
    for (int i = 0; i < rows.size(); ++i)
        rows[i] = top + rowsToInsert.at(rows.at(i));

    QBitArray isWrittenTo(dragRowCount * dragColumnCount);

    // make space in the table for the dropped data
    int colCount = columnCount(parent);
    if (colCount == 0) {
        insertColumns(colCount, dragColumnCount - colCount, parent);
        colCount = columnCount(parent);
    }
    insertRows(row, dragRowCount, parent);

    row = qMax(0, row);
    column = qMax(0, column);

    QList<QPersistentModelIndex> newIndexes(data.size());
    // set the data in the table
    for (int j = 0; j < data.size(); ++j) {
        int relativeRow = rows.at(j) - top;
        int relativeColumn = columns.at(j) - left;
        int destinationRow = relativeRow + row;
        int destinationColumn = relativeColumn + column;
        int flat = (relativeRow * dragColumnCount) + relativeColumn;
        // if the item was already written to, or we just can't fit it in the table, create a new row
        if (destinationColumn >= colCount || isWrittenTo.testBit(flat)) {
            destinationColumn = qBound(column, destinationColumn, colCount - 1);
            destinationRow = row + dragRowCount;
            insertRows(row + dragRowCount, 1, parent);
            flat = (dragRowCount * dragColumnCount) + relativeColumn;
            isWrittenTo.resize(++dragRowCount * dragColumnCount);
        }
        if (!isWrittenTo.testBit(flat)) {
            newIndexes[j] = index(destinationRow, destinationColumn, parent);
            isWrittenTo.setBit(flat);
        }
    }

    for(int k = 0; k < newIndexes.size(); k++) {
        if (newIndexes.at(k).isValid())
            setItemData(newIndexes.at(k), data.at(k));
    }

    return true;
}

/*!
    Begins a row insertion operation.

    When reimplementing insertRows() in a subclass, you must call this function
    \e before inserting data into the model's underlying data store.

    The \a parent index corresponds to the parent into which the new rows are
    inserted; \a first and \a last are the row numbers that the new rows will
    have after they have been inserted.

    \table 80%
    \row
        \li  \inlineimage modelview-begin-insert-rows.png Inserting rows
        \li  Specify the first and last row numbers for the span of rows you
            want to insert into an item in a model.

            For example, as shown in the diagram, we insert three rows before
            row 2, so \a first is 2 and \a last is 4:

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 0

            This inserts the three new rows as rows 2, 3, and 4.
    \row
        \li  \inlineimage modelview-begin-append-rows.png Appending rows
        \li  To append rows, insert them after the last row.

            For example, as shown in the diagram, we append two rows to a
            collection of 4 existing rows (ending in row 3), so \a first is 4
            and \a last is 5:

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 1

            This appends the two new rows as rows 4 and 5.
    \endtable

    \note This function emits the rowsAboutToBeInserted() signal which
    connected views (or proxies) must handle before the data is inserted.
    Otherwise, the views may end up in an invalid state.
    \sa endInsertRows()
*/
void QAbstractItemModel::beginInsertRows(const QModelIndex &parent, int first, int last)
{
    Q_ASSERT(first >= 0);
    Q_ASSERT(first <= rowCount(parent)); // == is allowed, to insert at the end
    Q_ASSERT(last >= first);
    Q_D(QAbstractItemModel);
    d->changes.push(QAbstractItemModelPrivate::Change(parent, first, last));
    emit rowsAboutToBeInserted(parent, first, last, QPrivateSignal());
    d->rowsAboutToBeInserted(parent, first, last);
}

/*!
    Ends a row insertion operation.

    When reimplementing insertRows() in a subclass, you must call this function
    \e after inserting data into the model's underlying data store.

    \sa beginInsertRows()
*/
void QAbstractItemModel::endInsertRows()
{
    Q_D(QAbstractItemModel);
    QAbstractItemModelPrivate::Change change = d->changes.pop();
    d->rowsInserted(change.parent, change.first, change.last);
    emit rowsInserted(change.parent, change.first, change.last, QPrivateSignal());
}

/*!
    Begins a row removal operation.

    When reimplementing removeRows() in a subclass, you must call this
    function \e before removing data from the model's underlying data store.

    The \a parent index corresponds to the parent from which the new rows are
    removed; \a first and \a last are the row numbers of the rows to be
    removed.

    \table 80%
    \row
        \li  \inlineimage modelview-begin-remove-rows.png Removing rows
        \li  Specify the first and last row numbers for the span of rows you
            want to remove from an item in a model.

            For example, as shown in the diagram, we remove the two rows from
            row 2 to row 3, so \a first is 2 and \a last is 3:

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 2
    \endtable

    \note This function emits the rowsAboutToBeRemoved() signal which connected
    views (or proxies) must handle before the data is removed. Otherwise, the
    views may end up in an invalid state.

    \sa endRemoveRows()
*/
void QAbstractItemModel::beginRemoveRows(const QModelIndex &parent, int first, int last)
{
    Q_ASSERT(first >= 0);
    Q_ASSERT(last >= first);
    Q_ASSERT(last < rowCount(parent));
    Q_D(QAbstractItemModel);
    d->changes.push(QAbstractItemModelPrivate::Change(parent, first, last));
    emit rowsAboutToBeRemoved(parent, first, last, QPrivateSignal());
    d->rowsAboutToBeRemoved(parent, first, last);
}

/*!
    Ends a row removal operation.

    When reimplementing removeRows() in a subclass, you must call this function
    \e after removing data from the model's underlying data store.

    \sa beginRemoveRows()
*/
void QAbstractItemModel::endRemoveRows()
{
    Q_D(QAbstractItemModel);
    QAbstractItemModelPrivate::Change change = d->changes.pop();
    d->rowsRemoved(change.parent, change.first, change.last);
    emit rowsRemoved(change.parent, change.first, change.last, QPrivateSignal());
}

/*!
    Returns whether a move operation is valid.

    A move operation is not allowed if it moves a continuous range of rows to a destination within
    itself, or if it attempts to move a row to one of its own descendants.

    \internal
*/
bool QAbstractItemModelPrivate::allowMove(const QModelIndex &srcParent, int start, int end, const QModelIndex &destinationParent, int destinationStart, Qt::Orientation orientation)
{
    // Don't move the range within itself.
    if (destinationParent == srcParent)
        return !(destinationStart >= start && destinationStart <= end + 1);

    QModelIndex destinationAncestor = destinationParent;
    int pos = (Qt::Vertical == orientation) ? destinationAncestor.row() : destinationAncestor.column();
    forever {
        if (destinationAncestor == srcParent) {
            if (pos >= start && pos <= end)
                return false;
            break;
        }

        if (!destinationAncestor.isValid())
          break;

        pos = (Qt::Vertical == orientation) ? destinationAncestor.row() : destinationAncestor.column();
        destinationAncestor = destinationAncestor.parent();
    }

    return true;
}

/*!
    \internal

    see QTBUG-94546
 */
void QAbstractItemModelPrivate::executePendingOperations() const { }

/*!
    \since 4.6

    Begins a row move operation.

    When reimplementing a subclass, this method simplifies moving
    entities in your model. This method is responsible for moving
    persistent indexes in the model, which you would otherwise be
    required to do yourself. Using beginMoveRows and endMoveRows
    is an alternative to emitting layoutAboutToBeChanged and
    layoutChanged directly along with changePersistentIndex.

    The \a sourceParent index corresponds to the parent from which the
    rows are moved; \a sourceFirst and \a sourceLast are the first and last
    row numbers of the rows to be moved. The \a destinationParent index
    corresponds to the parent into which those rows are moved. The \a
    destinationChild is the row to which the rows will be moved.  That
    is, the index at row \a sourceFirst in \a sourceParent will become
    row \a destinationChild in \a destinationParent, followed by all other
    rows up to \a sourceLast.

    However, when moving rows down in the same parent (\a sourceParent
    and \a destinationParent are equal), the rows will be placed before the
    \a destinationChild index. That is, if you wish to move rows 0 and 1 so
    they will become rows 1 and 2, \a destinationChild should be 3. In this
    case, the new index for the source row \c i (which is between
    \a sourceFirst and \a sourceLast) is equal to
    \c {(destinationChild-sourceLast-1+i)}.

    Note that if \a sourceParent and \a destinationParent are the same,
    you must ensure that the \a destinationChild is not within the range
    of \a sourceFirst and \a sourceLast + 1.  You must also ensure that you
    do not attempt to move a row to one of its own children or ancestors.
    This method returns \c{false} if either condition is true, in which case you
    should abort your move operation.

    \table 80%
    \row
        \li  \inlineimage modelview-move-rows-1.png Moving rows to another parent
        \li  Specify the first and last row numbers for the span of rows in
            the source parent you want to move in the model. Also specify
            the row in the destination parent to move the span to.

            For example, as shown in the diagram, we move three rows from
            row 2 to 4 in the source, so \a sourceFirst is 2 and \a sourceLast is 4.
            We move those items to above row 2 in the destination, so \a destinationChild is 2.

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 6

            This moves the three rows rows 2, 3, and 4 in the source to become 2, 3 and 4 in
            the destination. Other affected siblings are displaced accordingly.
    \row
        \li  \inlineimage modelview-move-rows-2.png Moving rows to append to another parent
        \li  To append rows to another parent, move them to after the last row.

            For example, as shown in the diagram, we move three rows to a
            collection of 6 existing rows (ending in row 5), so \a destinationChild is 6:

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 7

            This moves the target rows to the end of the target parent as 6, 7 and 8.
    \row
        \li  \inlineimage modelview-move-rows-3.png Moving rows in the same parent up
        \li  To move rows within the same parent, specify the row to move them to.

            For example, as shown in the diagram, we move one item from row 2 to row 0,
            so \a sourceFirst and \a sourceLast are 2 and \a destinationChild is 0.

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 8

            Note that other rows may be displaced accordingly. Note also that when moving
            items within the same parent you should not attempt invalid or no-op moves. In
            the above example, item 2 is at row 2 before the move, so it cannot be moved
            to row 2 (where it is already) or row 3 (no-op as row 3 means above row 3, where
            it is already)

    \row
        \li  \inlineimage modelview-move-rows-4.png Moving rows in the same parent down
        \li  To move rows within the same parent, specify the row to move them to.

            For example, as shown in the diagram, we move one item from row 2 to row 4,
            so \a sourceFirst and \a sourceLast are 2 and \a destinationChild is 4.

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 9

            Note that other rows may be displaced accordingly.
    \endtable

    \sa endMoveRows()
*/
bool QAbstractItemModel::beginMoveRows(const QModelIndex &sourceParent, int sourceFirst, int sourceLast, const QModelIndex &destinationParent, int destinationChild)
{
    Q_ASSERT(sourceFirst >= 0);
    Q_ASSERT(sourceLast >= sourceFirst);
    Q_ASSERT(destinationChild >= 0);
    Q_D(QAbstractItemModel);

    if (!d->allowMove(sourceParent, sourceFirst, sourceLast, destinationParent, destinationChild, Qt::Vertical)) {
        return false;
    }

    QAbstractItemModelPrivate::Change sourceChange(sourceParent, sourceFirst, sourceLast);
    sourceChange.needsAdjust = sourceParent.isValid() && sourceParent.row() >= destinationChild && sourceParent.parent() == destinationParent;
    d->changes.push(sourceChange);
    int destinationLast = destinationChild + (sourceLast - sourceFirst);
    QAbstractItemModelPrivate::Change destinationChange(destinationParent, destinationChild, destinationLast);
    destinationChange.needsAdjust = destinationParent.isValid() && destinationParent.row() >= sourceLast && destinationParent.parent() == sourceParent;
    d->changes.push(destinationChange);

    emit rowsAboutToBeMoved(sourceParent, sourceFirst, sourceLast, destinationParent, destinationChild, QPrivateSignal());
    d->itemsAboutToBeMoved(sourceParent, sourceFirst, sourceLast, destinationParent, destinationChild, Qt::Vertical);
    return true;
}

/*!
    Ends a row move operation.

    When implementing a subclass, you must call this
    function \e after moving data within the model's underlying data
    store.

    \sa beginMoveRows()

    \since 4.6
*/
void QAbstractItemModel::endMoveRows()
{
    Q_D(QAbstractItemModel);

    QAbstractItemModelPrivate::Change insertChange = d->changes.pop();
    QAbstractItemModelPrivate::Change removeChange = d->changes.pop();

    QModelIndex adjustedSource = removeChange.parent;
    QModelIndex adjustedDestination = insertChange.parent;

    const int numMoved = removeChange.last - removeChange.first + 1;
    if (insertChange.needsAdjust)
      adjustedDestination = createIndex(adjustedDestination.row() - numMoved, adjustedDestination.column(), adjustedDestination.internalPointer());

    if (removeChange.needsAdjust)
      adjustedSource = createIndex(adjustedSource.row() + numMoved, adjustedSource.column(), adjustedSource.internalPointer());

    d->itemsMoved(adjustedSource, removeChange.first, removeChange.last, adjustedDestination, insertChange.first, Qt::Vertical);

    emit rowsMoved(adjustedSource, removeChange.first, removeChange.last, adjustedDestination, insertChange.first, QPrivateSignal());
}

/*!
    Begins a column insertion operation.

    When reimplementing insertColumns() in a subclass, you must call this
    function \e before inserting data into the model's underlying data store.

    The \a parent index corresponds to the parent into which the new columns
    are inserted; \a first and \a last are the column numbers of the new
    columns will have after they have been inserted.

    \table 80%
    \row
        \li  \inlineimage modelview-begin-insert-columns.png Inserting columns
        \li  Specify the first and last column numbers for the span of columns
            you want to insert into an item in a model.

            For example, as shown in the diagram, we insert three columns
            before column 4, so \a first is 4 and \a last is 6:

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 3

            This inserts the three new columns as columns 4, 5, and 6.
    \row
        \li  \inlineimage modelview-begin-append-columns.png Appending columns
        \li  To append columns, insert them after the last column.

            For example, as shown in the diagram, we append three columns to a
            collection of six existing columns (ending in column 5), so
            \a first is 6 and \a last is 8:

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 4

            This appends the two new columns as columns 6, 7, and 8.
    \endtable

    \note This function emits the columnsAboutToBeInserted() signal which
    connected views (or proxies) must handle before the data is inserted.
    Otherwise, the views may end up in an invalid state.

    \sa endInsertColumns()
*/
void QAbstractItemModel::beginInsertColumns(const QModelIndex &parent, int first, int last)
{
    Q_ASSERT(first >= 0);
    Q_ASSERT(first <= columnCount(parent)); // == is allowed, to insert at the end
    Q_ASSERT(last >= first);
    Q_D(QAbstractItemModel);
    d->changes.push(QAbstractItemModelPrivate::Change(parent, first, last));
    emit columnsAboutToBeInserted(parent, first, last, QPrivateSignal());
    d->columnsAboutToBeInserted(parent, first, last);
}

/*!
    Ends a column insertion operation.

    When reimplementing insertColumns() in a subclass, you must call this
    function \e after inserting data into the model's underlying data
    store.

    \sa beginInsertColumns()
*/
void QAbstractItemModel::endInsertColumns()
{
    Q_D(QAbstractItemModel);
    QAbstractItemModelPrivate::Change change = d->changes.pop();
    d->columnsInserted(change.parent, change.first, change.last);
    emit columnsInserted(change.parent, change.first, change.last, QPrivateSignal());
}

/*!
    Begins a column removal operation.

    When reimplementing removeColumns() in a subclass, you must call this
    function \e before removing data from the model's underlying data store.

    The \a parent index corresponds to the parent from which the new columns
    are removed; \a first and \a last are the column numbers of the first and
    last columns to be removed.

    \table 80%
    \row
        \li  \inlineimage modelview-begin-remove-columns.png Removing columns
        \li  Specify the first and last column numbers for the span of columns
            you want to remove from an item in a model.

            For example, as shown in the diagram, we remove the three columns
            from column 4 to column 6, so \a first is 4 and \a last is 6:

            \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 5
    \endtable

    \note This function emits the columnsAboutToBeRemoved() signal which
    connected views (or proxies) must handle before the data is removed.
    Otherwise, the views may end up in an invalid state.

    \sa endRemoveColumns()
*/
void QAbstractItemModel::beginRemoveColumns(const QModelIndex &parent, int first, int last)
{
    Q_ASSERT(first >= 0);
    Q_ASSERT(last >= first);
    Q_ASSERT(last < columnCount(parent));
    Q_D(QAbstractItemModel);
    d->changes.push(QAbstractItemModelPrivate::Change(parent, first, last));
    emit columnsAboutToBeRemoved(parent, first, last, QPrivateSignal());
    d->columnsAboutToBeRemoved(parent, first, last);
}

/*!
    Ends a column removal operation.

    When reimplementing removeColumns() in a subclass, you must call this
    function \e after removing data from the model's underlying data store.

    \sa beginRemoveColumns()
*/
void QAbstractItemModel::endRemoveColumns()
{
    Q_D(QAbstractItemModel);
    QAbstractItemModelPrivate::Change change = d->changes.pop();
    d->columnsRemoved(change.parent, change.first, change.last);
    emit columnsRemoved(change.parent, change.first, change.last, QPrivateSignal());
}

/*!
    Begins a column move operation.

    When reimplementing a subclass, this method simplifies moving
    entities in your model. This method is responsible for moving
    persistent indexes in the model, which you would otherwise be
    required to do yourself. Using beginMoveColumns and endMoveColumns
    is an alternative to emitting layoutAboutToBeChanged and
    layoutChanged directly along with changePersistentIndex.

    The \a sourceParent index corresponds to the parent from which the
    columns are moved; \a sourceFirst and \a sourceLast are the first and last
    column numbers of the columns to be moved. The \a destinationParent index
    corresponds to the parent into which those columns are moved. The \a
    destinationChild is the column to which the columns will be moved.  That
    is, the index at column \a sourceFirst in \a sourceParent will become
    column \a destinationChild in \a destinationParent, followed by all other
    columns up to \a sourceLast.

    However, when moving columns down in the same parent (\a sourceParent
    and \a destinationParent are equal), the columns will be placed before the
    \a destinationChild index. That is, if you wish to move columns 0 and 1 so
    they will become columns 1 and 2, \a destinationChild should be 3. In this
    case, the new index for the source column \c i (which is between
    \a sourceFirst and \a sourceLast) is equal to
    \c {(destinationChild-sourceLast-1+i)}.

    Note that if \a sourceParent and \a destinationParent are the same,
    you must ensure that the \a destinationChild is not within the range
    of \a sourceFirst and \a sourceLast + 1.  You must also ensure that you
    do not attempt to move a column to one of its own children or ancestors.
    This method returns \c{false} if either condition is true, in which case you
    should abort your move operation.

    \sa endMoveColumns()

    \since 4.6
*/
bool QAbstractItemModel::beginMoveColumns(const QModelIndex &sourceParent, int sourceFirst, int sourceLast, const QModelIndex &destinationParent, int destinationChild)
{
    Q_ASSERT(sourceFirst >= 0);
    Q_ASSERT(sourceLast >= sourceFirst);
    Q_ASSERT(destinationChild >= 0);
    Q_D(QAbstractItemModel);

    if (!d->allowMove(sourceParent, sourceFirst, sourceLast, destinationParent, destinationChild, Qt::Horizontal)) {
        return false;
    }

    QAbstractItemModelPrivate::Change sourceChange(sourceParent, sourceFirst, sourceLast);
    sourceChange.needsAdjust = sourceParent.isValid() && sourceParent.row() >= destinationChild && sourceParent.parent() == destinationParent;
    d->changes.push(sourceChange);
    int destinationLast = destinationChild + (sourceLast - sourceFirst);
    QAbstractItemModelPrivate::Change destinationChange(destinationParent, destinationChild, destinationLast);
    destinationChange.needsAdjust = destinationParent.isValid() && destinationParent.row() >= sourceLast && destinationParent.parent() == sourceParent;
    d->changes.push(destinationChange);

    emit columnsAboutToBeMoved(sourceParent, sourceFirst, sourceLast, destinationParent, destinationChild, QPrivateSignal());
    d->itemsAboutToBeMoved(sourceParent, sourceFirst, sourceLast, destinationParent, destinationChild, Qt::Horizontal);
    return true;
}

/*!
    Ends a column move operation.

    When implementing a subclass, you must call this
    function \e after moving data within the model's underlying data
    store.

    \sa beginMoveColumns()

    \since 4.6
*/
void QAbstractItemModel::endMoveColumns()
{
    Q_D(QAbstractItemModel);

    QAbstractItemModelPrivate::Change insertChange = d->changes.pop();
    QAbstractItemModelPrivate::Change removeChange = d->changes.pop();

    QModelIndex adjustedSource = removeChange.parent;
    QModelIndex adjustedDestination = insertChange.parent;

    const int numMoved = removeChange.last - removeChange.first + 1;
    if (insertChange.needsAdjust)
      adjustedDestination = createIndex(adjustedDestination.row(), adjustedDestination.column() - numMoved, adjustedDestination.internalPointer());

    if (removeChange.needsAdjust)
      adjustedSource = createIndex(adjustedSource.row(), adjustedSource.column() + numMoved, adjustedSource.internalPointer());

    d->itemsMoved(adjustedSource, removeChange.first, removeChange.last, adjustedDestination, insertChange.first, Qt::Horizontal);
    emit columnsMoved(adjustedSource, removeChange.first, removeChange.last, adjustedDestination, insertChange.first, QPrivateSignal());
}

/*!
    Begins a model reset operation.

    A reset operation resets the model to its current state in any attached views.

    \note Any views attached to this model will be reset as well.

    When a model is reset it means that any previous data reported from the
    model is now invalid and has to be queried for again. This also means that
    the current item and any selected items will become invalid.

    When a model radically changes its data it can sometimes be easier to just
    call this function rather than emit dataChanged() to inform other
    components when the underlying data source, or its structure, has changed.

    You must call this function before resetting any internal data structures in your model
    or proxy model.

    This function emits the signal modelAboutToBeReset().

    \sa modelAboutToBeReset(), modelReset(), endResetModel()
    \since 4.6
*/
void QAbstractItemModel::beginResetModel()
{
    Q_D(QAbstractItemModel);
    if (d->resetting) {
        qWarning() << "beginResetModel called on" << this << "without calling endResetModel first";
        // Warn, but don't return early in case user code relies on the incorrect behavior.
    }

    qCDebug(lcReset) << "beginResetModel called; about to emit modelAboutToBeReset";
    d->resetting = true;
    emit modelAboutToBeReset(QPrivateSignal());
}

/*!
    Completes a model reset operation.

    You must call this function after resetting any internal data structure in your model
    or proxy model.

    This function emits the signal modelReset().

    \sa beginResetModel()
    \since 4.6
*/
void QAbstractItemModel::endResetModel()
{
    Q_D(QAbstractItemModel);
    if (!d->resetting) {
        qWarning() << "endResetModel called on" << this << "without calling beginResetModel first";
        // Warn, but don't return early in case user code relies on the incorrect behavior.
    }

    qCDebug(lcReset) << "endResetModel called; about to emit modelReset";
    d->invalidatePersistentIndexes();
    resetInternalData();
    d->resetting = false;
    emit modelReset(QPrivateSignal());
}

/*!
    Changes the QPersistentModelIndex that is equal to the given \a from model
    index to the given \a to model index.

    If no persistent model index equal to the given \a from model index was
    found, nothing is changed.

    \sa persistentIndexList(), changePersistentIndexList()
*/
void QAbstractItemModel::changePersistentIndex(const QModelIndex &from, const QModelIndex &to)
{
    Q_D(QAbstractItemModel);
    if (d->persistent.indexes.isEmpty())
        return;
    // find the data and reinsert it sorted
    const auto it = d->persistent.indexes.constFind(from);
    if (it != d->persistent.indexes.cend()) {
        QPersistentModelIndexData *data = *it;
        d->persistent.indexes.erase(it);
        data->index = to;
        if (to.isValid())
            d->persistent.insertMultiAtEnd(to, data);
    }
}

/*!
    \since 4.1

    Changes the {QPersistentModelIndex}es that are equal to the indexes in the
    given \a from model index list to the given \a to model index list.

    If no persistent model indexes equal to the indexes in the given \a from
    model index list are found, nothing is changed.

    \sa persistentIndexList(), changePersistentIndex()
*/
void QAbstractItemModel::changePersistentIndexList(const QModelIndexList &from,
                                                   const QModelIndexList &to)
{
    Q_D(QAbstractItemModel);
    if (d->persistent.indexes.isEmpty())
        return;
    QList<QPersistentModelIndexData *> toBeReinserted;
    toBeReinserted.reserve(to.size());
    for (int i = 0; i < from.size(); ++i) {
        if (from.at(i) == to.at(i))
            continue;
        const auto it = d->persistent.indexes.constFind(from.at(i));
        if (it != d->persistent.indexes.cend()) {
            QPersistentModelIndexData *data = *it;
            d->persistent.indexes.erase(it);
            data->index = to.at(i);
            if (data->index.isValid())
                toBeReinserted << data;
        }
    }

    for (auto *data : std::as_const(toBeReinserted))
        d->persistent.insertMultiAtEnd(data->index, data);
}

/*!
    \since 4.2

    Returns the list of indexes stored as persistent indexes in the model.
*/
QModelIndexList QAbstractItemModel::persistentIndexList() const
{
    Q_D(const QAbstractItemModel);
    QModelIndexList result;
    result.reserve(d->persistent.indexes.size());
    for (auto *data : std::as_const(d->persistent.indexes))
        result.append(data->index);
    return result;
}

/*!
    \enum QAbstractItemModel::CheckIndexOption
    \since 5.11

    This enum can be used to control the checks performed by
    QAbstractItemModel::checkIndex().

    \value NoOption No check options are specified.

    \value IndexIsValid The model index passed to
    QAbstractItemModel::checkIndex() is checked to be a valid model index.

    \value DoNotUseParent Does not perform any check
    involving the usage of the parent of the index passed to
    QAbstractItemModel::checkIndex().

    \value ParentIsInvalid The parent of the model index
    passed to QAbstractItemModel::checkIndex() is checked to be an invalid
    model index. If both this option and DoNotUseParent
    are specified, then this option is ignored.
*/

/*!
    \since 5.11

    This function checks whether \a index is a legal model index for
    this model. A legal model index is either an invalid model index, or a
    valid model index for which all the following holds:

    \list

    \li the index' model is \c{this};
    \li the index' row is greater or equal than zero;
    \li the index' row is less than the row count for the index' parent;
    \li the index' column is greater or equal than zero;
    \li the index' column is less than the column count for the index' parent.

    \endlist

    The \a options argument may change some of these checks. If \a options
    contains \c{IndexIsValid}, then \a index must be a valid
    index; this is useful when reimplementing functions such as \l{data()} or
    \l{setData()}, which expect valid indexes.

    If \a options contains \c{DoNotUseParent}, then the
    checks that would call \l{parent()} are omitted; this allows calling this
    function from a \l{parent()} reimplementation (otherwise, this would result
    in endless recursion and a crash).

    If \a options does not contain \c{DoNotUseParent}, and it
    contains \c{ParentIsInvalid}, then an additional check is
    performed: the parent index is checked for not being valid. This is useful
    when implementing flat models such as lists or tables, where no model index
    should have a valid parent index.

    This function returns true if all the checks succeeded, and false otherwise.
    This allows to use the function in \l{Q_ASSERT} and similar other debugging
    mechanisms. If some check failed, a warning message will be printed in the
    \c{qt.core.qabstractitemmodel.checkindex} logging category, containing
    some information that may be useful for debugging the failure.

    \note This function is a debugging helper for implementing your own item
    models. When developing complex models, as well as when building
    complicated model hierarchies (e.g. using proxy models), it is useful to
    call this function in order to catch bugs relative to illegal model indices
    (as defined above) accidentally passed to some QAbstractItemModel API.

    \warning Note that it's undefined behavior to pass illegal indices to item
    models, so applications must refrain from doing so, and not rely on any
    "defensive" programming that item models could employ to handle illegal
    indexes gracefully.

    \sa QModelIndex
*/
bool QAbstractItemModel::checkIndex(const QModelIndex &index, CheckIndexOptions options) const
{
    if (!index.isValid()) {
        if (options & CheckIndexOption::IndexIsValid) {
            qCWarning(lcCheckIndex) << "Index" << index << "is not valid (expected valid)";
            return false;
        }
        return true;
    }

    if (index.model() != this) {
        qCWarning(lcCheckIndex) << "Index" << index
                                << "is for model" << index.model()
                                << "which is different from this model" << this;
        return false;
    }

    if (index.row() < 0) {
        qCWarning(lcCheckIndex) << "Index" << index
                                << "has negative row" << index.row();
        return false;
    }

    if (index.column() < 0) {
        qCWarning(lcCheckIndex) << "Index" << index
                                << "has negative column" << index.column();
        return false;
    }

    if (!(options & CheckIndexOption::DoNotUseParent)) {
        const QModelIndex parentIndex = index.parent();
        if (options & CheckIndexOption::ParentIsInvalid) {
            if (parentIndex.isValid()) {
                qCWarning(lcCheckIndex) << "Index" << index
                                        << "has valid parent" << parentIndex
                                        << "(expected an invalid parent)";
                return false;
            }
        }

        const int rc = rowCount(parentIndex);
        if (index.row() >= rc) {
            qCWarning(lcCheckIndex) << "Index" << index
                                    << "has out of range row" << index.row()
                                    << "rowCount() is" << rc;
            return false;
        }

        const int cc = columnCount(parentIndex);
        if (index.column() >= cc) {
            qCWarning(lcCheckIndex) << "Index" << index
                                    << "has out of range column" << index.column()
                                    << "columnCount() is" << cc;
            return false;

        }
    }

    return true;
}

/*!
    \since 6.0

    Fills the \a roleDataSpan with the requested data for the given \a index.

    The default implementation will call simply data() for each role in
    the span. A subclass can reimplement this function to provide data
    to views more efficiently:

    \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 15

    In the snippet above, \c{index} is the same for the entire call.
    This means that accessing to the necessary data structures in order
    to retrieve the information for \c{index} can be done only once
    (hoisting the relevant code out of the loop).

    The usage of QModelRoleData::setData(), or similarly
    QVariant::setValue(), is encouraged over constructing a QVariant
    separately and  using a plain assignment operator; this is
    because the former allow to re-use the memory already allocated for
    the QVariant object stored inside a QModelRoleData, while the latter
    always allocates the new variant and then destroys the old one.

    Note that views may call multiData() with spans that have been used
    in previous calls, and therefore may already contain some data.
    Therefore, it is imperative that if the model cannot return the
    data for a given role, then it must clear the data in the
    corresponding QModelRoleData object. This can be done by calling
    QModelRoleData::clearData(), or similarly by setting a default
    constructed QVariant, and so on. Failure to clear the data will
    result in the view believing that the "old" data is meant to be
    used for the corresponding role.

    Finally, in order to avoid code duplication, a subclass may also
    decide to reimplement data() in terms of multiData(), by supplying
    a span of just one element:

    \snippet code/src_corelib_kernel_qabstractitemmodel.cpp 16

    \note Models are not allowed to modify the roles in the span, or
    to rearrange the span elements. Doing so results in undefined
    behavior.

    \note It is illegal to pass an invalid model index to this function.

    \sa QModelRoleDataSpan, data()
*/
void QAbstractItemModel::multiData(const QModelIndex &index, QModelRoleDataSpan roleDataSpan) const
{
    Q_ASSERT(checkIndex(index, CheckIndexOption::IndexIsValid));

    for (QModelRoleData &d : roleDataSpan)
        d.setData(data(index, d.role()));
}

/*!
    \class QAbstractTableModel
    \inmodule QtCore
    \brief The QAbstractTableModel class provides an abstract model that can be
    subclassed to create table models.

    \ingroup model-view

    QAbstractTableModel provides a standard interface for models that represent
    their data as a two-dimensional array of items. It is not used directly,
    but must be subclassed.

    Since the model provides a more specialized interface than
    QAbstractItemModel, it is not suitable for use with tree views, although it
    can be used to provide data to a QListView. If you need to represent a
    simple list of items, and only need a model to contain a single column of
    data, subclassing the QAbstractListModel may be more appropriate.

    The rowCount() and columnCount() functions return the dimensions of the
    table. To retrieve a model index corresponding to an item in the model, use
    index() and provide only the row and column numbers.

    \section1 Subclassing

    When subclassing QAbstractTableModel, you must implement rowCount(),
    columnCount(), and data(). Default implementations of the index() and
    parent() functions are provided by QAbstractTableModel.
    Well behaved models will also implement headerData().

    Editable models need to implement setData(), and implement flags() to
    return a value containing
    \l{Qt::ItemFlags}{Qt::ItemIsEditable}.

    Models that provide interfaces to resizable data structures can
    provide implementations of insertRows(), removeRows(), insertColumns(),
    and removeColumns(). When implementing these functions, it is
    important to call the appropriate functions so that all connected views
    are aware of any changes:

    \list
    \li An insertRows() implementation must call beginInsertRows()
       \e before inserting new rows into the data structure, and it must
       call endInsertRows() \e{immediately afterwards}.
    \li An insertColumns() implementation must call beginInsertColumns()
       \e before inserting new columns into the data structure, and it must
       call endInsertColumns() \e{immediately afterwards}.
    \li A removeRows() implementation must call beginRemoveRows()
       \e before the rows are removed from the data structure, and it must
       call endRemoveRows() \e{immediately afterwards}.
    \li A removeColumns() implementation must call beginRemoveColumns()
       \e before the columns are removed from the data structure, and it must
       call endRemoveColumns() \e{immediately afterwards}.
    \endlist

    \note Some general guidelines for subclassing models are available in the
    \l{Model Subclassing Reference}.

    \include models.qdocinc {thread-safety-section1}{QAbstractTableModel}

    \sa {Model Classes}, QAbstractItemModel, QAbstractListModel
*/

/*!
    Constructs an abstract table model for the given \a parent.
*/

QAbstractTableModel::QAbstractTableModel(QObject *parent)
    : QAbstractItemModel(parent)
{

}

/*!
    \internal

    Constructs an abstract table model with \a dd and the given \a parent.
*/

QAbstractTableModel::QAbstractTableModel(QAbstractItemModelPrivate &dd, QObject *parent)
    : QAbstractItemModel(dd, parent)
{

}

/*!
    Destroys the abstract table model.
*/

QAbstractTableModel::~QAbstractTableModel()
{

}

/*!
    \fn QModelIndex QAbstractTableModel::index(int row, int column, const QModelIndex &parent = QModelIndex()) const

    Returns the index of the data in \a row and \a column with \a parent.

    \sa parent()
*/

QModelIndex QAbstractTableModel::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

/*!
    \fn QModelIndex QAbstractTableModel::parent(const QModelIndex &index) const

    Returns the parent of the model item with the given \a index.

    \sa index(), hasChildren()
*/

QModelIndex QAbstractTableModel::parent(const QModelIndex &) const
{
    return QModelIndex();
}

/*!
    \reimp
*/
QModelIndex QAbstractTableModel::sibling(int row, int column, const QModelIndex &) const
{
    return index(row, column);
}

bool QAbstractTableModel::hasChildren(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return rowCount(parent) > 0 && columnCount(parent) > 0;
    return false;
}

/*!
    \reimp
 */
Qt::ItemFlags QAbstractTableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags f = QAbstractItemModel::flags(index);
    if (index.isValid())
        f |= Qt::ItemNeverHasChildren;
    return f;
}

/*!
    \class QAbstractListModel
    \inmodule QtCore
    \brief The QAbstractListModel class provides an abstract model that can be
    subclassed to create one-dimensional list models.

    \ingroup model-view

    QAbstractListModel provides a standard interface for models that represent
    their data as a simple non-hierarchical sequence of items. It is not used
    directly, but must be subclassed.

    Since the model provides a more specialized interface than
    QAbstractItemModel, it is not suitable for use with tree views; you will
    need to subclass QAbstractItemModel if you want to provide a model for
    that purpose. If you need to use a number of list models to manage data,
    it may be more appropriate to subclass QAbstractTableModel instead.

    Simple models can be created by subclassing this class and implementing
    the minimum number of required functions. For example, we could implement
    a simple read-only QStringList-based model that provides a list of strings
    to a QListView widget. In such a case, we only need to implement the
    rowCount() function to return the number of items in the list, and the
    data() function to retrieve items from the list.

    Since the model represents a one-dimensional structure, the rowCount()
    function returns the total number of items in the model. The columnCount()
    function is implemented for interoperability with all kinds of views, but
    by default informs views that the model contains only one column.

    \section1 Subclassing

    When subclassing QAbstractListModel, you must provide implementations
    of the rowCount() and data() functions. Well behaved models also provide
    a headerData() implementation.

    If your model is used within QML and requires roles other than the
    default ones provided by the roleNames() function, you must override it.

    For editable list models, you must also provide an implementation of
    setData(), and implement the flags() function so that it returns a value
    containing \l{Qt::ItemFlags}{Qt::ItemIsEditable}.

    Note that QAbstractListModel provides a default implementation of
    columnCount() that informs views that there is only a single column
    of items in this model.

    Models that provide interfaces to resizable list-like data structures
    can provide implementations of insertRows() and removeRows(). When
    implementing these functions, it is important to call the appropriate
    functions so that all connected views are aware of any changes:

    \list
    \li An insertRows() implementation must call beginInsertRows()
       \e before inserting new rows into the data structure, and it must
       call endInsertRows() \e{immediately afterwards}.
    \li A removeRows() implementation must call beginRemoveRows()
       \e before the rows are removed from the data structure, and it must
       call endRemoveRows() \e{immediately afterwards}.
    \endlist

    \note Some general guidelines for subclassing models are available in the
    \l{Model Subclassing Reference}.

    \sa {Model Classes}, {Model Subclassing Reference}, QAbstractItemView,
        QAbstractTableModel
*/

/*!
    Constructs an abstract list model with the given \a parent.
*/

QAbstractListModel::QAbstractListModel(QObject *parent)
    : QAbstractItemModel(parent)
{

}

/*!
    \internal

    Constructs an abstract list model with \a dd and the given \a parent.
*/

QAbstractListModel::QAbstractListModel(QAbstractItemModelPrivate &dd, QObject *parent)
    : QAbstractItemModel(dd, parent)
{

}

/*!
    Destroys the abstract list model.
*/

QAbstractListModel::~QAbstractListModel()
{

}

/*!
    \fn QModelIndex QAbstractListModel::index(int row, int column, const QModelIndex &parent = QModelIndex()) const

    Returns the index of the data in \a row and \a column with \a parent.

    \sa parent()
*/

QModelIndex QAbstractListModel::index(int row, int column, const QModelIndex &parent) const
{
    return hasIndex(row, column, parent) ? createIndex(row, column) : QModelIndex();
}

/*!
    Returns the parent of the model item with the given \a index.

    \sa index(), hasChildren()
*/

QModelIndex QAbstractListModel::parent(const QModelIndex & /* index */) const
{
    return QModelIndex();
}

/*!
    \reimp
*/
QModelIndex QAbstractListModel::sibling(int row, int column, const QModelIndex &) const
{
    return index(row, column);
}

/*!
    \reimp
 */
Qt::ItemFlags QAbstractListModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags f = QAbstractItemModel::flags(index);
    if (index.isValid())
        f |= Qt::ItemNeverHasChildren;
    return f;
}

/*!
    \internal

    Returns the number of columns in the list with the given \a parent.

    \sa rowCount()
*/

int QAbstractListModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 1;
}

bool QAbstractListModel::hasChildren(const QModelIndex &parent) const
{
    return parent.isValid() ? false : (rowCount() > 0);
}

/*!
    \typedef QModelIndexList
    \relates QModelIndex

    Synonym for QList<QModelIndex>.
*/

/*!
  \reimp
*/
bool QAbstractTableModel::dropMimeData(const QMimeData *data, Qt::DropAction action,
                                       int row, int column, const QModelIndex &parent)
{
    if (!data || !(action == Qt::CopyAction || action == Qt::MoveAction))
        return false;

    QStringList types = mimeTypes();
    if (types.isEmpty())
        return false;
    QString format = types.at(0);
    if (!data->hasFormat(format))
        return false;

    QByteArray encoded = data->data(format);
    QDataStream stream(&encoded, QDataStream::ReadOnly);

    // if the drop is on an item, replace the data in the items
    if (parent.isValid() && row == -1 && column == -1) {
        int top = INT_MAX;
        int left = INT_MAX;
        QList<int> rows, columns;
        QList<QMap<int, QVariant>> data;

        while (!stream.atEnd()) {
            int r, c;
            QMap<int, QVariant> v;
            stream >> r >> c >> v;
            rows.append(r);
            columns.append(c);
            data.append(v);
            top = qMin(r, top);
            left = qMin(c, left);
        }

        for (int i = 0; i < data.size(); ++i) {
            int r = (rows.at(i) - top) + parent.row();
            int c = (columns.at(i) - left) + parent.column();
            if (hasIndex(r, c))
                setItemData(index(r, c), data.at(i));
        }

        return true;
    }

    // otherwise insert new rows for the data
    return decodeData(row, column, parent, stream);
}

/*!
  \reimp
*/
bool QAbstractListModel::dropMimeData(const QMimeData *data, Qt::DropAction action,
                                      int row, int column, const QModelIndex &parent)
{
    if (!data || !(action == Qt::CopyAction || action == Qt::MoveAction))
        return false;

    QStringList types = mimeTypes();
    if (types.isEmpty())
        return false;
    QString format = types.at(0);
    if (!data->hasFormat(format))
        return false;

    QByteArray encoded = data->data(format);
    QDataStream stream(&encoded, QDataStream::ReadOnly);

    // if the drop is on an item, replace the data in the items
    if (parent.isValid() && row == -1 && column == -1) {
        int top = INT_MAX;
        int left = INT_MAX;
        QList<int> rows, columns;
        QList<QMap<int, QVariant>> data;

        while (!stream.atEnd()) {
            int r, c;
            QMap<int, QVariant> v;
            stream >> r >> c >> v;
            rows.append(r);
            columns.append(c);
            data.append(v);
            top = qMin(r, top);
            left = qMin(c, left);
        }

        for (int i = 0; i < data.size(); ++i) {
            int r = (rows.at(i) - top) + parent.row();
            if (columns.at(i) == left && hasIndex(r, 0))
                setItemData(index(r), data.at(i));
        }

        return true;
    }

    if (row == -1)
        row = rowCount(parent);

    // otherwise insert new rows for the data
    return decodeData(row, column, parent, stream);
}

/*!
    \fn QAbstractItemModel::modelAboutToBeReset()
    \since 4.2

    This signal is emitted when beginResetModel() is called, before the model's internal
    state (e.g. persistent model indexes) has been invalidated.

    \sa beginResetModel(), modelReset()
*/

/*!
    \fn QAbstractItemModel::modelReset()
    \since 4.1

    This signal is emitted when endResetModel() is called, after the
    model's internal state (e.g. persistent model indexes) has been invalidated.

    Note that if a model is reset it should be considered that all information
    previously retrieved from it is invalid. This includes but is not limited
    to the rowCount() and columnCount(), flags(), data retrieved through data(),
    and roleNames().

    \sa endResetModel(), modelAboutToBeReset()
*/

/*!
    \fn bool QModelIndex::operator<(const QModelIndex &lhs, const QModelIndex &rhs)
    \since 4.1

    Returns \c{true} if \a lhs model index is smaller than the \a rhs
    model index; otherwise returns \c{false}.

    The less than calculation is not directly useful to developers - the way that indexes
    with different parents compare is not defined. This operator only exists so that the
    class can be used with QMap.
*/

/*!
    \fn size_t qHash(const QPersistentModelIndex &key, size_t seed)
    \since 5.0
    \qhashold{QPersistentModelIndex}
*/


/*!
    \internal
    QMultiHash::insert inserts the value before the old value. and find() return the new value.
    We need insertMultiAtEnd because we don't want to overwrite the old one, which should be removed later

    There should be only one instance QPersistentModelIndexData per index, but in some intermediate state there may be
    severals of PersistantModelIndex pointing to the same index, but one is already updated, and the other one is not.
    This make sure than when updating the first one we don't overwrite the second one in the hash, and the second one
    will be updated right later.
 */
void QAbstractItemModelPrivate::Persistent::insertMultiAtEnd(const QModelIndex& key, QPersistentModelIndexData *data)
{
    auto newIt = indexes.insert(key, data);
    auto it = newIt;
    ++it;
    while (it != indexes.end() && it.key() == key) {
        qSwap(*newIt,*it);
        newIt = it;
        ++it;
    }
}

QT_END_NAMESPACE

#include "moc_qabstractitemmodel.cpp"
#include "qabstractitemmodel.moc"
