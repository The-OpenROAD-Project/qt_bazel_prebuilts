// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qsortfilterproxymodel.h"
#include "qitemselectionmodel.h"
#include <qsize.h>
#include <qdebug.h>
#include <qdatetime.h>
#include <qstringlist.h>
#include <private/qabstractitemmodel_p.h>
#include <private/qabstractproxymodel_p.h>
#include <private/qproperty_p.h>

#include <algorithm>

QT_BEGIN_NAMESPACE

using QModelIndexPairList = QList<std::pair<QModelIndex, QPersistentModelIndex>>;

struct QSortFilterProxyModelDataChanged
{
    QSortFilterProxyModelDataChanged(const QModelIndex &tl, const QModelIndex &br)
        : topLeft(tl), bottomRight(br) { }

    QModelIndex topLeft;
    QModelIndex bottomRight;
};

static inline QSet<int> qListToSet(const QList<int> &vector)
{
    return {vector.begin(), vector.end()};
}

class QSortFilterProxyModelLessThan
{
public:
    inline QSortFilterProxyModelLessThan(int column, const QModelIndex &parent,
                                       const QAbstractItemModel *source,
                                       const QSortFilterProxyModel *proxy)
        : sort_column(column), source_parent(parent), source_model(source), proxy_model(proxy) {}

    inline bool operator()(int r1, int r2) const
    {
        QModelIndex i1 = source_model->index(r1, sort_column, source_parent);
        QModelIndex i2 = source_model->index(r2, sort_column, source_parent);
        return proxy_model->lessThan(i1, i2);
    }

private:
    int sort_column;
    QModelIndex source_parent;
    const QAbstractItemModel *source_model;
    const QSortFilterProxyModel *proxy_model;
};

class QSortFilterProxyModelGreaterThan
{
public:
    inline QSortFilterProxyModelGreaterThan(int column, const QModelIndex &parent,
                                          const QAbstractItemModel *source,
                                          const QSortFilterProxyModel *proxy)
        : sort_column(column), source_parent(parent),
          source_model(source), proxy_model(proxy) {}

    inline bool operator()(int r1, int r2) const
    {
        QModelIndex i1 = source_model->index(r1, sort_column, source_parent);
        QModelIndex i2 = source_model->index(r2, sort_column, source_parent);
        return proxy_model->lessThan(i2, i1);
    }

private:
    int sort_column;
    QModelIndex source_parent;
    const QAbstractItemModel *source_model;
    const QSortFilterProxyModel *proxy_model;
};


//this struct is used to store what are the rows that are removed
//between a call to rowsAboutToBeRemoved and rowsRemoved
//it avoids readding rows to the mapping that are currently being removed
struct QRowsRemoval
{
    QRowsRemoval(const QModelIndex &parent_source, int start, int end) : parent_source(parent_source), start(start), end(end)
    {
    }

    QRowsRemoval() : start(-1), end(-1)
    {
    }

    bool contains(QModelIndex parent, int row) const
    {
        do {
            if (parent == parent_source)
                return row >= start && row <= end;
            row = parent.row();
            parent = parent.parent();
        } while (row >= 0);
        return false;
    }
private:
    QModelIndex parent_source;
    int start;
    int end;
};

class QSortFilterProxyModelPrivate : public QAbstractProxyModelPrivate
{
public:
    Q_DECLARE_PUBLIC(QSortFilterProxyModel)

    enum class Direction {
        Rows = 1,
        Columns = 2,
        All = Rows | Columns
    };

    struct Mapping {
        QList<int> source_rows;
        QList<int> source_columns;
        QList<int> proxy_rows;
        QList<int> proxy_columns;
        QList<QModelIndex> mapped_children;
        QModelIndex source_parent;
    };

    mutable QHash<QtPrivate::QModelIndexWrapper, Mapping*> source_index_mapping;

    void setSortCaseSensitivityForwarder(Qt::CaseSensitivity cs)
    {
        q_func()->setSortCaseSensitivity(cs);
    }
    void sortCaseSensitivityChangedForwarder(Qt::CaseSensitivity cs)
    {
        emit q_func()->sortCaseSensitivityChanged(cs);
    }

    void setSortRoleForwarder(int role) { q_func()->setSortRole(role); }
    void sortRoleChangedForwarder(int role) { emit q_func()->sortRoleChanged(role); }

    void setSortLocaleAwareForwarder(bool on) { q_func()->setSortLocaleAware(on); }
    void sortLocaleAwareChangedForwarder(bool on) { emit q_func()->sortLocaleAwareChanged(on); }

    void setFilterKeyColumnForwarder(int column) { q_func()->setFilterKeyColumn(column); }

    void setFilterRoleForwarder(int role) { q_func()->setFilterRole(role); }
    void filterRoleChangedForwarder(int role) { emit q_func()->filterRoleChanged(role); }

    void setRecursiveFilteringEnabledForwarder(bool recursive)
    {
        q_func()->setRecursiveFilteringEnabled(recursive);
    }
    void recursiveFilteringEnabledChangedForwarder(bool recursive)
    {
        emit q_func()->recursiveFilteringEnabledChanged(recursive);
    }

    void setAutoAcceptChildRowsForwarder(bool accept) { q_func()->setAutoAcceptChildRows(accept); }
    void autoAcceptChildRowsChangedForwarder(bool accept)
    {
        emit q_func()->autoAcceptChildRowsChanged(accept);
    }

    void setDynamicSortFilterForwarder(bool enable) { q_func()->setDynamicSortFilter(enable); }

    void setFilterCaseSensitivityForwarder(Qt::CaseSensitivity cs)
    {
        q_func()->setFilterCaseSensitivity(cs);
    }
    void filterCaseSensitivityChangedForwarder(Qt::CaseSensitivity cs)
    {
        emit q_func()->filterCaseSensitivityChanged(cs);
    }

    void setFilterRegularExpressionForwarder(const QRegularExpression &re)
    {
        q_func()->setFilterRegularExpression(re);
    }

    int source_sort_column = -1;
    int proxy_sort_column = -1;
    Qt::SortOrder sort_order = Qt::AscendingOrder;
    bool complete_insert = false;

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(
            QSortFilterProxyModelPrivate, Qt::CaseSensitivity, sort_casesensitivity,
            &QSortFilterProxyModelPrivate::setSortCaseSensitivityForwarder,
            &QSortFilterProxyModelPrivate::sortCaseSensitivityChangedForwarder, Qt::CaseSensitive)

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(QSortFilterProxyModelPrivate, int, sort_role,
                                       &QSortFilterProxyModelPrivate::setSortRoleForwarder,
                                       &QSortFilterProxyModelPrivate::sortRoleChangedForwarder,
                                       Qt::DisplayRole)

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(QSortFilterProxyModelPrivate, int, filter_column,
                                       &QSortFilterProxyModelPrivate::setFilterKeyColumnForwarder,
                                       0)

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(QSortFilterProxyModelPrivate, int, filter_role,
                                       &QSortFilterProxyModelPrivate::setFilterRoleForwarder,
                                       &QSortFilterProxyModelPrivate::filterRoleChangedForwarder,
                                       Qt::DisplayRole)

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(
            QSortFilterProxyModelPrivate, bool, sort_localeaware,
            &QSortFilterProxyModelPrivate::setSortLocaleAwareForwarder,
            &QSortFilterProxyModelPrivate::sortLocaleAwareChangedForwarder, false)

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(
            QSortFilterProxyModelPrivate, bool, filter_recursive,
            &QSortFilterProxyModelPrivate::setRecursiveFilteringEnabledForwarder,
            &QSortFilterProxyModelPrivate::recursiveFilteringEnabledChangedForwarder, false)

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(
            QSortFilterProxyModelPrivate, bool, accept_children,
            &QSortFilterProxyModelPrivate::setAutoAcceptChildRowsForwarder,
            &QSortFilterProxyModelPrivate::autoAcceptChildRowsChangedForwarder, false)

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(QSortFilterProxyModelPrivate, bool, dynamic_sortfilter,
                                       &QSortFilterProxyModelPrivate::setDynamicSortFilterForwarder,
                                       true)

    Q_OBJECT_COMPAT_PROPERTY_WITH_ARGS(
            QSortFilterProxyModelPrivate, Qt::CaseSensitivity, filter_casesensitive,
            &QSortFilterProxyModelPrivate::setFilterCaseSensitivityForwarder,
            &QSortFilterProxyModelPrivate::filterCaseSensitivityChangedForwarder, Qt::CaseSensitive)

    Q_OBJECT_COMPAT_PROPERTY(QSortFilterProxyModelPrivate, QRegularExpression,
                             filter_regularexpression,
                             &QSortFilterProxyModelPrivate::setFilterRegularExpressionForwarder)

    QModelIndex last_top_source;
    QRowsRemoval itemsBeingRemoved;

    QModelIndexPairList saved_persistent_indexes;
    QList<QPersistentModelIndex> saved_layoutChange_parents;

    std::array<QMetaObject::Connection, 18> sourceConnections;

    QHash<QtPrivate::QModelIndexWrapper, Mapping *>::const_iterator create_mapping(
        const QModelIndex &source_parent) const;
    QHash<QtPrivate::QModelIndexWrapper, Mapping *>::const_iterator create_mapping_recursive(
            const QModelIndex &source_parent) const;
    QModelIndex proxy_to_source(const QModelIndex &proxyIndex) const;
    QModelIndex source_to_proxy(const QModelIndex &sourceIndex) const;
    bool can_create_mapping(const QModelIndex &source_parent) const;

    void remove_from_mapping(const QModelIndex &source_parent);

    /*
     * Legacy: changing the pattern through a string does not change the
     * case sensitivity.
     */
    void set_filter_pattern(const QString &pattern)
    {
        QRegularExpression re = filter_regularexpression.valueBypassingBindings();
        const auto cs = re.patternOptions() & QRegularExpression::CaseInsensitiveOption;
        re.setPattern(pattern);
        re.setPatternOptions(cs);
        // This is a helper function, which is supposed to be called from a
        // more complicated context. Because of that, the caller is responsible
        // for calling notify() and removeBindingUnlessInWrapper(), if needed.
        filter_regularexpression.setValueBypassingBindings(re);
    }

    inline QHash<QtPrivate::QModelIndexWrapper, Mapping *>::const_iterator index_to_iterator(
        const QModelIndex &proxy_index) const
    {
        Q_ASSERT(proxy_index.isValid());
        Q_ASSERT(proxy_index.model() == q_func());
        const void *p = proxy_index.internalPointer();
        Q_ASSERT(p);
        QHash<QtPrivate::QModelIndexWrapper, Mapping *>::const_iterator it =
                source_index_mapping.constFind(static_cast<const Mapping*>(p)->source_parent);
        Q_ASSERT(it != source_index_mapping.constEnd());
        Q_ASSERT(it.value());
        return it;
    }

    inline QModelIndex create_index(int row, int column,
                                    QHash<QtPrivate::QModelIndexWrapper, Mapping*>::const_iterator it) const
    {
        return q_func()->createIndex(row, column, *it);
    }

    void _q_sourceDataChanged(const QModelIndex &source_top_left,
                              const QModelIndex &source_bottom_right,
                              const QList<int> &roles);
    void _q_sourceHeaderDataChanged(Qt::Orientation orientation, int start, int end);

    void _q_sourceAboutToBeReset();
    void _q_sourceReset();

    void _q_sourceLayoutAboutToBeChanged(const QList<QPersistentModelIndex> &sourceParents, QAbstractItemModel::LayoutChangeHint hint);
    void _q_sourceLayoutChanged(const QList<QPersistentModelIndex> &sourceParents, QAbstractItemModel::LayoutChangeHint hint);

    void _q_sourceRowsAboutToBeInserted(const QModelIndex &source_parent,
                                        int start, int end);
    void _q_sourceRowsInserted(const QModelIndex &source_parent,
                               int start, int end);
    void _q_sourceRowsAboutToBeRemoved(const QModelIndex &source_parent,
                                       int start, int end);
    void _q_sourceRowsRemoved(const QModelIndex &source_parent,
                              int start, int end);
    void _q_sourceRowsAboutToBeMoved(const QModelIndex &sourceParent,
                                     int sourceStart, int sourceEnd,
                                     const QModelIndex &destParent, int dest);
    void _q_sourceRowsMoved(const QModelIndex &sourceParent,
                            int sourceStart, int sourceEnd,
                            const QModelIndex &destParent, int dest);
    void _q_sourceColumnsAboutToBeInserted(const QModelIndex &source_parent,
                                           int start, int end);
    void _q_sourceColumnsInserted(const QModelIndex &source_parent,
                                  int start, int end);
    void _q_sourceColumnsAboutToBeRemoved(const QModelIndex &source_parent,
                                          int start, int end);
    void _q_sourceColumnsRemoved(const QModelIndex &source_parent,
                                 int start, int end);
    void _q_sourceColumnsAboutToBeMoved(const QModelIndex &sourceParent,
                                        int sourceStart, int sourceEnd,
                                        const QModelIndex &destParent, int dest);
    void _q_sourceColumnsMoved(const QModelIndex &sourceParent,
                               int sourceStart, int sourceEnd,
                               const QModelIndex &destParent, int dest);

    void _q_clearMapping();

    void sort();
    bool update_source_sort_column();
    int find_source_sort_column() const;
    void sort_source_rows(QList<int> &source_rows,
                          const QModelIndex &source_parent) const;
    QList<std::pair<int, QList<int>>> proxy_intervals_for_source_items_to_add(
        const QList<int> &proxy_to_source, const QList<int> &source_items,
        const QModelIndex &source_parent, Qt::Orientation orient) const;
    QList<std::pair<int, int>> proxy_intervals_for_source_items(
        const QList<int> &source_to_proxy, const QList<int> &source_items) const;
    void insert_source_items(
        QList<int> &source_to_proxy, QList<int> &proxy_to_source,
        const QList<int> &source_items, const QModelIndex &source_parent,
        Qt::Orientation orient, bool emit_signal = true);
    void remove_source_items(
        QList<int> &source_to_proxy, QList<int> &proxy_to_source,
        const QList<int> &source_items, const QModelIndex &source_parent,
        Qt::Orientation orient, bool emit_signal = true);
    void remove_proxy_interval(
        QList<int> &source_to_proxy, QList<int> &proxy_to_source,
        int proxy_start, int proxy_end, const QModelIndex &proxy_parent,
        Qt::Orientation orient, bool emit_signal = true);
    static inline void build_source_to_proxy_mapping(
        const QList<int> &proxy_to_source, QList<int> &source_to_proxy, int start = 0);
    void source_items_inserted(const QModelIndex &source_parent,
                               int start, int end, Qt::Orientation orient);
    void source_items_about_to_be_removed(const QModelIndex &source_parent,
                                          int start, int end, Qt::Orientation orient);
    void source_items_removed(const QModelIndex &source_parent,
                              int start, int end, Qt::Orientation orient);
    void proxy_item_range(
        const QList<int> &source_to_proxy, const QList<int> &source_items,
        int &proxy_low, int &proxy_high) const;

    QModelIndexPairList store_persistent_indexes() const;
    void update_persistent_indexes(const QModelIndexPairList &source_indexes);

    void filter_about_to_be_changed(const QModelIndex &source_parent = QModelIndex());
    void filter_changed(Direction dir, const QModelIndex &source_parent = QModelIndex());
    QSet<int> handle_filter_changed(
        QList<int> &source_to_proxy, QList<int> &proxy_to_source,
        const QModelIndex &source_parent, Qt::Orientation orient);

    void updateChildrenMapping(const QModelIndex &source_parent, Mapping *parent_mapping,
                               Qt::Orientation orient, int start, int end, int delta_item_count, bool remove);

    void _q_sourceModelDestroyed() override;

    bool needsReorder(const QList<int> &source_rows, const QModelIndex &source_parent) const;

    bool filterAcceptsRowInternal(int source_row, const QModelIndex &source_parent) const;
    bool recursiveChildAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    bool recursiveParentAcceptsRow(const QModelIndex &source_parent) const;
};

typedef QHash<QtPrivate::QModelIndexWrapper, QSortFilterProxyModelPrivate::Mapping *> IndexMap;

static bool operator&(QSortFilterProxyModelPrivate::Direction a, QSortFilterProxyModelPrivate::Direction b)
{
    return int(a) & int(b);
}

void QSortFilterProxyModelPrivate::_q_sourceModelDestroyed()
{
    QAbstractProxyModelPrivate::_q_sourceModelDestroyed();
    qDeleteAll(source_index_mapping);
    source_index_mapping.clear();
}

bool QSortFilterProxyModelPrivate::filterAcceptsRowInternal(int source_row, const QModelIndex &source_parent) const
{
    Q_Q(const QSortFilterProxyModel);

    if (q->filterAcceptsRow(source_row, source_parent))
        return true;

    // Go up the tree and accept this row if a parent is accepted
    if (accept_children && recursiveParentAcceptsRow(source_parent))
        return true;

    // Go down the tree and accept this row if a child is accepted
    if (filter_recursive && recursiveChildAcceptsRow(source_row, source_parent))
        return true;

    return false;
}

bool QSortFilterProxyModelPrivate::recursiveParentAcceptsRow(const QModelIndex &source_parent) const
{
    Q_Q(const QSortFilterProxyModel);

    if (source_parent.isValid()) {
        const QModelIndex index = source_parent.parent();

        if (q->filterAcceptsRow(source_parent.row(), index))
            return true;

        return recursiveParentAcceptsRow(index);
    }

    return false;
}

bool QSortFilterProxyModelPrivate::recursiveChildAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    Q_Q(const QSortFilterProxyModel);

    const int colCount = model->columnCount(source_parent);
    if (colCount == 0) // don't call index(row, 0) if there's no such column
        return false;

    const QModelIndex index = model->index(source_row, 0, source_parent);
    const int count = model->rowCount(index);

    for (int i = 0; i < count; ++i) {
        if (q->filterAcceptsRow(i, index))
            return true;

        if (recursiveChildAcceptsRow(i, index))
            return true;
    }

    return false;
}

void QSortFilterProxyModelPrivate::remove_from_mapping(const QModelIndex &source_parent)
{
    if (Mapping *m = source_index_mapping.take(source_parent)) {
        for (const QModelIndex &mappedIdx : std::as_const(m->mapped_children))
            remove_from_mapping(mappedIdx);
        delete m;
    }
}

void QSortFilterProxyModelPrivate::_q_clearMapping()
{
    // store the persistent indexes
    QModelIndexPairList source_indexes = store_persistent_indexes();

    qDeleteAll(source_index_mapping);
    source_index_mapping.clear();
    if (dynamic_sortfilter)
        source_sort_column = find_source_sort_column();

    // update the persistent indexes
    update_persistent_indexes(source_indexes);
}

IndexMap::const_iterator QSortFilterProxyModelPrivate::create_mapping(
    const QModelIndex &source_parent) const
{
    Q_Q(const QSortFilterProxyModel);

    IndexMap::const_iterator it = source_index_mapping.constFind(source_parent);
    if (it != source_index_mapping.constEnd()) // was mapped already
        return it;

    Mapping *m = new Mapping;

    int source_rows = model->rowCount(source_parent);
    m->source_rows.reserve(source_rows);
    for (int i = 0; i < source_rows; ++i) {
        if (filterAcceptsRowInternal(i, source_parent))
            m->source_rows.append(i);
    }
    int source_cols = model->columnCount(source_parent);
    m->source_columns.reserve(source_cols);
    for (int i = 0; i < source_cols; ++i) {
        if (q->filterAcceptsColumn(i, source_parent))
            m->source_columns.append(i);
    }

    sort_source_rows(m->source_rows, source_parent);
    m->proxy_rows.resize(source_rows);
    build_source_to_proxy_mapping(m->source_rows, m->proxy_rows);
    m->proxy_columns.resize(source_cols);
    build_source_to_proxy_mapping(m->source_columns, m->proxy_columns);

    m->source_parent = source_parent;

    if (source_parent.isValid()) {
        QModelIndex source_grand_parent = source_parent.parent();
        IndexMap::const_iterator it2 = create_mapping(source_grand_parent);
        Q_ASSERT(it2 != source_index_mapping.constEnd());
        it2.value()->mapped_children.append(source_parent);
    }

    it = IndexMap::const_iterator(source_index_mapping.insert(source_parent, m));
    Q_ASSERT(it != source_index_mapping.constEnd());
    Q_ASSERT(it.value());

    return it;
}

// Go up the tree, creating mappings, unless of course the parent is filtered out
IndexMap::const_iterator QSortFilterProxyModelPrivate::create_mapping_recursive(const QModelIndex &source_parent) const
{
    if (source_parent.isValid()) {
        const QModelIndex source_grand_parent = source_parent.parent();
        IndexMap::const_iterator it = source_index_mapping.constFind(source_grand_parent);
        IndexMap::const_iterator end = source_index_mapping.constEnd();
        if (it == end) {
            it = create_mapping_recursive(source_grand_parent);
            end = source_index_mapping.constEnd();
            if (it == end)
                return end;
        }
        Mapping *gm = it.value();
        if (gm->proxy_rows.at(source_parent.row()) == -1 ||
                gm->proxy_columns.at(source_parent.column()) == -1) {
            // Can't do, parent is filtered
            return end;
        }
    }
    return create_mapping(source_parent);
}

QModelIndex QSortFilterProxyModelPrivate::proxy_to_source(const QModelIndex &proxy_index) const
{
    if (!proxy_index.isValid())
        return QModelIndex(); // for now; we may want to be able to set a root index later
    if (proxy_index.model() != q_func()) {
        qWarning("QSortFilterProxyModel: index from wrong model passed to mapToSource");
        Q_ASSERT(!"QSortFilterProxyModel: index from wrong model passed to mapToSource");
        return QModelIndex();
    }
    IndexMap::const_iterator it = index_to_iterator(proxy_index);
    Mapping *m = it.value();
    if ((proxy_index.row() >= m->source_rows.size()) || (proxy_index.column() >= m->source_columns.size()))
        return QModelIndex();
    int source_row = m->source_rows.at(proxy_index.row());
    int source_col = m->source_columns.at(proxy_index.column());
    return model->index(source_row, source_col, it.key());
}

QModelIndex QSortFilterProxyModelPrivate::source_to_proxy(const QModelIndex &source_index) const
{
    if (!source_index.isValid())
        return QModelIndex(); // for now; we may want to be able to set a root index later
    if (source_index.model() != model) {
        qWarning("QSortFilterProxyModel: index from wrong model passed to mapFromSource");
        Q_ASSERT(!"QSortFilterProxyModel: index from wrong model passed to mapFromSource");
        return QModelIndex();
    }
    QModelIndex source_parent = source_index.parent();
    IndexMap::const_iterator it = create_mapping_recursive(source_parent);
    if (it == source_index_mapping.constEnd())
        return QModelIndex();
    Mapping *m = it.value();
    if ((source_index.row() >= m->proxy_rows.size()) || (source_index.column() >= m->proxy_columns.size()))
        return QModelIndex();
    int proxy_row = m->proxy_rows.at(source_index.row());
    int proxy_column = m->proxy_columns.at(source_index.column());
    if (proxy_row == -1 || proxy_column == -1)
        return QModelIndex();
    return create_index(proxy_row, proxy_column, it);
}

bool QSortFilterProxyModelPrivate::can_create_mapping(const QModelIndex &source_parent) const
{
    if (source_parent.isValid()) {
        QModelIndex source_grand_parent = source_parent.parent();
        IndexMap::const_iterator it = source_index_mapping.constFind(source_grand_parent);
        if (it == source_index_mapping.constEnd()) {
            // Don't care, since we don't have mapping for the grand parent
            return false;
        }
        Mapping *gm = it.value();
        if (gm->proxy_rows.at(source_parent.row()) == -1 ||
            gm->proxy_columns.at(source_parent.column()) == -1) {
            // Don't care, since parent is filtered
            return false;
        }
    }
    return true;
}

/*!
  \internal

  Sorts the existing mappings.
*/
void QSortFilterProxyModelPrivate::sort()
{
    Q_Q(QSortFilterProxyModel);
    emit q->layoutAboutToBeChanged(QList<QPersistentModelIndex>(), QAbstractItemModel::VerticalSortHint);
    QModelIndexPairList source_indexes = store_persistent_indexes();
    const auto end = source_index_mapping.constEnd();
    for (auto it = source_index_mapping.constBegin(); it != end; ++it) {
        const QModelIndex &source_parent = it.key();
        Mapping *m = it.value();
        sort_source_rows(m->source_rows, source_parent);
        build_source_to_proxy_mapping(m->source_rows, m->proxy_rows);
    }
    update_persistent_indexes(source_indexes);
    emit q->layoutChanged(QList<QPersistentModelIndex>(), QAbstractItemModel::VerticalSortHint);
}

/*!
  \internal

    update the source_sort_column according to the proxy_sort_column
    return true if the column was changed
*/
bool QSortFilterProxyModelPrivate::update_source_sort_column()
{
    int old_source_sort_column = source_sort_column;

    if (proxy_sort_column == -1) {
        source_sort_column = -1;
    } else {
        // We cannot use index mapping here because in case of a still-empty
        // proxy model there's no valid proxy index we could map to source.
        // So always use the root mapping directly instead.
        Mapping *m = create_mapping(QModelIndex()).value();
        if (proxy_sort_column < m->source_columns.size())
            source_sort_column = m->source_columns.at(proxy_sort_column);
        else
            source_sort_column = -1;
    }

    return old_source_sort_column != source_sort_column;
}

/*!
  \internal

  Find the source_sort_column without creating a full mapping and
  without updating anything.
*/
int QSortFilterProxyModelPrivate::find_source_sort_column() const
{
    if (proxy_sort_column == -1)
        return -1;

    const QModelIndex rootIndex;
    const int source_cols = model->columnCount();
    int accepted_columns = -1;

    Q_Q(const QSortFilterProxyModel);
    for (int i = 0; i < source_cols; ++i) {
        if (q->filterAcceptsColumn(i, rootIndex)) {
            if (++accepted_columns == proxy_sort_column)
                return i;
        }
    }

    return -1;
}

/*!
  \internal

  Sorts the given \a source_rows according to current sort column and order.
*/
void QSortFilterProxyModelPrivate::sort_source_rows(
    QList<int> &source_rows, const QModelIndex &source_parent) const
{
    Q_Q(const QSortFilterProxyModel);
    if (source_sort_column >= 0) {
        if (sort_order == Qt::AscendingOrder) {
            QSortFilterProxyModelLessThan lt(source_sort_column, source_parent, model, q);
            std::stable_sort(source_rows.begin(), source_rows.end(), lt);
        } else {
            QSortFilterProxyModelGreaterThan gt(source_sort_column, source_parent, model, q);
            std::stable_sort(source_rows.begin(), source_rows.end(), gt);
        }
    } else if (sort_order == Qt::AscendingOrder) {
        std::stable_sort(source_rows.begin(), source_rows.end(), std::less{});
    } else {
        std::stable_sort(source_rows.begin(), source_rows.end(), std::greater{});
    }
}

/*!
  \internal

  Given source-to-proxy mapping \a source_to_proxy and the set of
  source items \a source_items (which are part of that mapping),
  determines the corresponding proxy item intervals that should
  be removed from the proxy model.

  The result is a vector of pairs, where each pair represents a
  (start, end) tuple, sorted in ascending order.
*/
QList<std::pair<int, int>> QSortFilterProxyModelPrivate::proxy_intervals_for_source_items(
    const QList<int> &source_to_proxy, const QList<int> &source_items) const
{
    QList<std::pair<int, int>> proxy_intervals;
    if (source_items.isEmpty())
        return proxy_intervals;

    int source_items_index = 0;
    while (source_items_index < source_items.size()) {
        int first_proxy_item = source_to_proxy.at(source_items.at(source_items_index));
        Q_ASSERT(first_proxy_item != -1);
        int last_proxy_item = first_proxy_item;
        ++source_items_index;
        // Find end of interval
        while ((source_items_index < source_items.size())
               && (source_to_proxy.at(source_items.at(source_items_index)) == last_proxy_item + 1)) {
            ++last_proxy_item;
            ++source_items_index;
        }
        // Add interval to result
        proxy_intervals.emplace_back(first_proxy_item, last_proxy_item);
    }
    std::stable_sort(proxy_intervals.begin(), proxy_intervals.end());
    // Consolidate adjacent intervals
    for (int i = proxy_intervals.size()-1; i > 0; --i) {
        std::pair<int, int> &interval = proxy_intervals[i];
        std::pair<int, int> &preceeding_interval = proxy_intervals[i - 1];
        if (interval.first == preceeding_interval.second + 1) {
            preceeding_interval.second = interval.second;
            interval.first = interval.second = -1;
        }
    }
    proxy_intervals.removeIf([](std::pair<int, int> interval) { return interval.first < 0; });
    return proxy_intervals;
}

/*!
  \internal

  Given source-to-proxy mapping \a src_to_proxy and proxy-to-source mapping
  \a proxy_to_source, removes \a source_items from this proxy model.
  The corresponding proxy items are removed in intervals, so that the proper
  rows/columnsRemoved(start, end) signals will be generated.
*/
void QSortFilterProxyModelPrivate::remove_source_items(
    QList<int> &source_to_proxy, QList<int> &proxy_to_source,
    const QList<int> &source_items, const QModelIndex &source_parent,
    Qt::Orientation orient, bool emit_signal)
{
    Q_Q(QSortFilterProxyModel);
    QModelIndex proxy_parent = q->mapFromSource(source_parent);
    if (!proxy_parent.isValid() && source_parent.isValid()) {
        proxy_to_source.clear();
        return; // nothing to do (already removed)
    }

    const auto proxy_intervals = proxy_intervals_for_source_items(
        source_to_proxy, source_items);

    const auto end = proxy_intervals.rend();
    for (auto it = proxy_intervals.rbegin(); it != end; ++it) {
        const std::pair<int, int> &interval = *it;
        const int proxy_start = interval.first;
        const int proxy_end = interval.second;
        remove_proxy_interval(source_to_proxy, proxy_to_source, proxy_start, proxy_end,
                              proxy_parent, orient, emit_signal);
    }
}

/*!
  \internal

  Given source-to-proxy mapping \a source_to_proxy and proxy-to-source mapping
  \a proxy_to_source, removes items from \a proxy_start to \a proxy_end
  (inclusive) from this proxy model.
*/
void QSortFilterProxyModelPrivate::remove_proxy_interval(
    QList<int> &source_to_proxy, QList<int> &proxy_to_source, int proxy_start, int proxy_end,
    const QModelIndex &proxy_parent, Qt::Orientation orient, bool emit_signal)
{
    Q_Q(QSortFilterProxyModel);
    if (emit_signal) {
        if (orient == Qt::Vertical)
            q->beginRemoveRows(proxy_parent, proxy_start, proxy_end);
        else
            q->beginRemoveColumns(proxy_parent, proxy_start, proxy_end);
    }

    // Remove items from proxy-to-source mapping
    for (int i = proxy_start; i <= proxy_end; ++i)
        source_to_proxy[proxy_to_source.at(i)] = -1;
    proxy_to_source.remove(proxy_start, proxy_end - proxy_start + 1);

    build_source_to_proxy_mapping(proxy_to_source, source_to_proxy, proxy_start);

    if (emit_signal) {
        if (orient == Qt::Vertical)
            q->endRemoveRows();
        else
            q->endRemoveColumns();
    }
}

/*!
  \internal

  Given proxy-to-source mapping \a proxy_to_source and a set of
  unmapped source items \a source_items, determines the proxy item
  intervals at which the subsets of source items should be inserted
  (but does not actually add them to the mapping).

  The result is a vector of pairs, each pair representing a tuple (start,
  items), where items is a vector containing the (sorted) source items that
  should be inserted at that proxy model location.
*/
QList<std::pair<int, QList<int>>> QSortFilterProxyModelPrivate::proxy_intervals_for_source_items_to_add(
    const QList<int> &proxy_to_source, const QList<int> &source_items,
    const QModelIndex &source_parent, Qt::Orientation orient) const
{
    Q_Q(const QSortFilterProxyModel);
    QList<std::pair<int, QList<int>>> proxy_intervals;
    if (source_items.isEmpty())
        return proxy_intervals;

    int proxy_low = 0;
    int proxy_item = 0;
    int source_items_index = 0;
    bool compare = (orient == Qt::Vertical && source_sort_column >= 0 && dynamic_sortfilter);
    while (source_items_index < source_items.size()) {
        QList<int> source_items_in_interval;
        int first_new_source_item = source_items.at(source_items_index);
        source_items_in_interval.append(first_new_source_item);
        ++source_items_index;

        // Find proxy item at which insertion should be started
        int proxy_high = proxy_to_source.size() - 1;
        QModelIndex i1 = compare ? model->index(first_new_source_item, source_sort_column, source_parent) : QModelIndex();
        while (proxy_low <= proxy_high) {
            proxy_item = (proxy_low + proxy_high) / 2;
            if (compare) {
                QModelIndex i2 = model->index(proxy_to_source.at(proxy_item), source_sort_column, source_parent);
                if ((sort_order == Qt::AscendingOrder) ? q->lessThan(i1, i2) : q->lessThan(i2, i1))
                    proxy_high = proxy_item - 1;
                else
                    proxy_low = proxy_item + 1;
            } else {
                if (first_new_source_item < proxy_to_source.at(proxy_item))
                    proxy_high = proxy_item - 1;
                else
                    proxy_low = proxy_item + 1;
            }
        }
        proxy_item = proxy_low;

        // Find the sequence of new source items that should be inserted here
        if (proxy_item >= proxy_to_source.size()) {
            for ( ; source_items_index < source_items.size(); ++source_items_index)
                source_items_in_interval.append(source_items.at(source_items_index));
        } else {
            i1 = compare ? model->index(proxy_to_source.at(proxy_item), source_sort_column, source_parent) : QModelIndex();
            for ( ; source_items_index < source_items.size(); ++source_items_index) {
                int new_source_item = source_items.at(source_items_index);
                if (compare) {
                    QModelIndex i2 = model->index(new_source_item, source_sort_column, source_parent);
                    if ((sort_order == Qt::AscendingOrder) ? q->lessThan(i1, i2) : q->lessThan(i2, i1))
                        break;
                } else {
                    if (proxy_to_source.at(proxy_item) < new_source_item)
                        break;
                }
                source_items_in_interval.append(new_source_item);
            }
        }

        // Add interval to result
        proxy_intervals.emplace_back(proxy_item, std::move(source_items_in_interval));
    }
    return proxy_intervals;
}

/*!
  \internal

  Given source-to-proxy mapping \a source_to_proxy and proxy-to-source mapping
  \a proxy_to_source, inserts the given \a source_items into this proxy model.
  The source items are inserted in intervals (based on some sorted order), so
  that the proper rows/columnsInserted(start, end) signals will be generated.
*/
void QSortFilterProxyModelPrivate::insert_source_items(
    QList<int> &source_to_proxy, QList<int> &proxy_to_source,
    const QList<int> &source_items, const QModelIndex &source_parent,
    Qt::Orientation orient, bool emit_signal)
{
    Q_Q(QSortFilterProxyModel);
    QModelIndex proxy_parent = q->mapFromSource(source_parent);
    if (!proxy_parent.isValid() && source_parent.isValid())
        return; // nothing to do (source_parent is not mapped)

    const auto proxy_intervals = proxy_intervals_for_source_items_to_add(
        proxy_to_source, source_items, source_parent, orient);

    const auto end = proxy_intervals.rend();
    for (auto it = proxy_intervals.rbegin(); it != end; ++it) {
        const std::pair<int, QList<int>> &interval = *it;
        const int proxy_start = interval.first;
        const QList<int> &source_items = interval.second;
        const int proxy_end = proxy_start + source_items.size() - 1;

        if (emit_signal) {
            if (orient == Qt::Vertical)
                q->beginInsertRows(proxy_parent, proxy_start, proxy_end);
            else
                q->beginInsertColumns(proxy_parent, proxy_start, proxy_end);
        }

        // TODO: use the range QList::insert() overload once it is implemented (QTBUG-58633).
        proxy_to_source.insert(proxy_start, source_items.size(), 0);
        std::copy(source_items.cbegin(), source_items.cend(), proxy_to_source.begin() + proxy_start);

        build_source_to_proxy_mapping(proxy_to_source, source_to_proxy, proxy_start);

        if (emit_signal) {
            if (orient == Qt::Vertical)
                q->endInsertRows();
            else
                q->endInsertColumns();
        }
    }
}

/*!
  \internal

  Handles source model items insertion (columnsInserted(), rowsInserted()).
  Determines
  1) which of the inserted items to also insert into proxy model (filtering),
  2) where to insert the items into the proxy model (sorting),
  then inserts those items.
  The items are inserted into the proxy model in intervals (based on
  sorted order), so that the proper rows/columnsInserted(start, end)
  signals will be generated.
*/
void QSortFilterProxyModelPrivate::source_items_inserted(
    const QModelIndex &source_parent, int start, int end, Qt::Orientation orient)
{
    Q_Q(QSortFilterProxyModel);
    if ((start < 0) || (end < 0))
        return;
    IndexMap::const_iterator it = source_index_mapping.constFind(source_parent);
    if (it == source_index_mapping.constEnd()) {
        if (!can_create_mapping(source_parent))
            return;
        it = create_mapping(source_parent);
        Mapping *m = it.value();
        QModelIndex proxy_parent = q->mapFromSource(source_parent);
        if (m->source_rows.size() > 0) {
            q->beginInsertRows(proxy_parent, 0, m->source_rows.size() - 1);
            q->endInsertRows();
        }
        if (m->source_columns.size() > 0) {
            q->beginInsertColumns(proxy_parent, 0, m->source_columns.size() - 1);
            q->endInsertColumns();
        }
        return;
    }

    Mapping *m = it.value();
    QList<int> &source_to_proxy = (orient == Qt::Vertical) ? m->proxy_rows : m->proxy_columns;
    QList<int> &proxy_to_source = (orient == Qt::Vertical) ? m->source_rows : m->source_columns;

    int delta_item_count = end - start + 1;
    int old_item_count = source_to_proxy.size();

    updateChildrenMapping(source_parent, m, orient, start, end, delta_item_count, false);

    // Expand source-to-proxy mapping to account for new items
    if (start < 0 || start > source_to_proxy.size()) {
        qWarning("QSortFilterProxyModel: invalid inserted rows reported by source model");
        remove_from_mapping(source_parent);
        return;
    }
    source_to_proxy.insert(start, delta_item_count, -1);

    if (start < old_item_count) {
        // Adjust existing "stale" indexes in proxy-to-source mapping
        int proxy_count = proxy_to_source.size();
        for (int proxy_item = 0; proxy_item < proxy_count; ++proxy_item) {
            int source_item = proxy_to_source.at(proxy_item);
            if (source_item >= start)
                proxy_to_source.replace(proxy_item, source_item + delta_item_count);
        }
        build_source_to_proxy_mapping(proxy_to_source, source_to_proxy);
    }

    // Figure out which items to add to mapping based on filter
    QList<int> source_items;
    for (int i = start; i <= end; ++i) {
        if ((orient == Qt::Vertical)
            ? filterAcceptsRowInternal(i, source_parent)
            : q->filterAcceptsColumn(i, source_parent)) {
            source_items.append(i);
        }
    }

    if (model->rowCount(source_parent) == delta_item_count) {
        // Items were inserted where there were none before.
        // If it was new rows make sure to create mappings for columns so that a
        // valid mapping can be retrieved later and vice-versa.

        QList<int> &orthogonal_proxy_to_source = (orient == Qt::Horizontal) ? m->source_rows : m->source_columns;
        QList<int> &orthogonal_source_to_proxy = (orient == Qt::Horizontal) ? m->proxy_rows : m->proxy_columns;

        if (orthogonal_source_to_proxy.isEmpty()) {
            const int ortho_end = (orient == Qt::Horizontal) ? model->rowCount(source_parent) : model->columnCount(source_parent);

            orthogonal_source_to_proxy.resize(ortho_end);

            for (int ortho_item = 0; ortho_item < ortho_end; ++ortho_item) {
                if ((orient == Qt::Horizontal) ? filterAcceptsRowInternal(ortho_item, source_parent)
                        : q->filterAcceptsColumn(ortho_item, source_parent)) {
                    orthogonal_proxy_to_source.append(ortho_item);
                }
            }
            if (orient == Qt::Horizontal) {
                // We're reacting to columnsInserted, but we've just inserted new rows. Sort them.
                sort_source_rows(orthogonal_proxy_to_source, source_parent);
            }
            build_source_to_proxy_mapping(orthogonal_proxy_to_source, orthogonal_source_to_proxy);
        }
    }

    // Sort and insert the items
    if (orient == Qt::Vertical) // Only sort rows
        sort_source_rows(source_items, source_parent);
    insert_source_items(source_to_proxy, proxy_to_source, source_items, source_parent, orient);
}

/*!
  \internal

  Handles source model items removal
  (columnsAboutToBeRemoved(), rowsAboutToBeRemoved()).
*/
void QSortFilterProxyModelPrivate::source_items_about_to_be_removed(
    const QModelIndex &source_parent, int start, int end, Qt::Orientation orient)
{
    if ((start < 0) || (end < 0))
        return;
    IndexMap::const_iterator it = source_index_mapping.constFind(source_parent);
    if (it == source_index_mapping.constEnd()) {
        // Don't care, since we don't have mapping for this index
        return;
    }

    Mapping *m = it.value();
    QList<int> &source_to_proxy = (orient == Qt::Vertical) ? m->proxy_rows : m->proxy_columns;
    QList<int> &proxy_to_source = (orient == Qt::Vertical) ? m->source_rows : m->source_columns;

    // figure out which items to remove
    QList<int> source_items_to_remove;
    int proxy_count = proxy_to_source.size();
    for (int proxy_item = 0; proxy_item < proxy_count; ++proxy_item) {
        int source_item = proxy_to_source.at(proxy_item);
        if ((source_item >= start) && (source_item <= end))
            source_items_to_remove.append(source_item);
    }

    remove_source_items(source_to_proxy, proxy_to_source, source_items_to_remove,
                        source_parent, orient);
}

/*!
  \internal

  Handles source model items removal (columnsRemoved(), rowsRemoved()).
*/
void QSortFilterProxyModelPrivate::source_items_removed(
    const QModelIndex &source_parent, int start, int end, Qt::Orientation orient)
{
    if ((start < 0) || (end < 0))
        return;
    IndexMap::const_iterator it = source_index_mapping.constFind(source_parent);
    if (it == source_index_mapping.constEnd()) {
        // Don't care, since we don't have mapping for this index
        return;
    }

    Mapping *m = it.value();
    QList<int> &source_to_proxy = (orient == Qt::Vertical) ? m->proxy_rows : m->proxy_columns;
    QList<int> &proxy_to_source = (orient == Qt::Vertical) ? m->source_rows : m->source_columns;

    if (end >= source_to_proxy.size())
        end = source_to_proxy.size() - 1;

    // Shrink the source-to-proxy mapping to reflect the new item count
    int delta_item_count = end - start + 1;
    source_to_proxy.remove(start, delta_item_count);

    int proxy_count = proxy_to_source.size();
    if (proxy_count > source_to_proxy.size()) {
        // mapping is in an inconsistent state -- redo the whole mapping
        qWarning("QSortFilterProxyModel: inconsistent changes reported by source model");
        Q_Q(QSortFilterProxyModel);
        q->beginResetModel();
        remove_from_mapping(source_parent);
        q->endResetModel();
        return;
    }

    // Adjust "stale" indexes in proxy-to-source mapping
    for (int proxy_item = 0; proxy_item < proxy_count; ++proxy_item) {
        int source_item = proxy_to_source.at(proxy_item);
        if (source_item >= start) {
            Q_ASSERT(source_item - delta_item_count >= 0);
            proxy_to_source.replace(proxy_item, source_item - delta_item_count);
        }
    }
    build_source_to_proxy_mapping(proxy_to_source, source_to_proxy);

    updateChildrenMapping(source_parent, m, orient, start, end, delta_item_count, true);

}


/*!
  \internal
  updates the mapping of the children when inserting or removing items
*/
void QSortFilterProxyModelPrivate::updateChildrenMapping(const QModelIndex &source_parent, Mapping *parent_mapping,
                                                         Qt::Orientation orient, int start, int end, int delta_item_count, bool remove)
{
    // see if any mapped children should be (re)moved
    QList<std::pair<QModelIndex, Mapping *>> moved_source_index_mappings;
    auto it2 = parent_mapping->mapped_children.begin();
    for ( ; it2 != parent_mapping->mapped_children.end();) {
        const QModelIndex source_child_index = *it2;
        const int pos = (orient == Qt::Vertical)
                        ? source_child_index.row()
                        : source_child_index.column();
        if (pos < start) {
            // not affected
            ++it2;
        } else if (remove && pos <= end) {
            // in the removed interval
            it2 = parent_mapping->mapped_children.erase(it2);
            remove_from_mapping(source_child_index);
        } else {
            // below the removed items -- recompute the index
            QModelIndex new_index;
            const int newpos = remove ? pos - delta_item_count : pos + delta_item_count;
            if (orient == Qt::Vertical) {
                new_index = model->index(newpos,
                                         source_child_index.column(),
                                         source_parent);
            } else {
                new_index = model->index(source_child_index.row(),
                                         newpos,
                                         source_parent);
            }
            *it2 = new_index;
            ++it2;

            // update mapping
            Mapping *cm = source_index_mapping.take(source_child_index);
            Q_ASSERT(cm);
            // we do not reinsert right away, because the new index might be identical with another, old index
            moved_source_index_mappings.emplace_back(new_index, cm);
        }
    }

    // reinsert moved, mapped indexes
    for (auto &pair : std::as_const(moved_source_index_mappings)) {
        pair.second->source_parent = pair.first;
        source_index_mapping.insert(pair.first, pair.second);
    }
}

/*!
  \internal
*/
void QSortFilterProxyModelPrivate::proxy_item_range(
    const QList<int> &source_to_proxy, const QList<int> &source_items,
    int &proxy_low, int &proxy_high) const
{
    proxy_low = INT_MAX;
    proxy_high = INT_MIN;
    for (int i = 0; i < source_items.size(); ++i) {
        int proxy_item = source_to_proxy.at(source_items.at(i));
        Q_ASSERT(proxy_item != -1);
        if (proxy_item < proxy_low)
            proxy_low = proxy_item;
        if (proxy_item > proxy_high)
            proxy_high = proxy_item;
    }
}

/*!
  \internal
*/
void QSortFilterProxyModelPrivate::build_source_to_proxy_mapping(
    const QList<int> &proxy_to_source, QList<int> &source_to_proxy, int start)
{
    if (start == 0)
        source_to_proxy.fill(-1);
    const int proxy_count = proxy_to_source.size();
    for (int i = start; i < proxy_count; ++i)
        source_to_proxy[proxy_to_source.at(i)] = i;
}

/*!
  \internal

  Maps the persistent proxy indexes to source indexes and
  returns the list of source indexes.
*/
QModelIndexPairList QSortFilterProxyModelPrivate::store_persistent_indexes() const
{
    Q_Q(const QSortFilterProxyModel);
    QModelIndexPairList source_indexes;
    source_indexes.reserve(persistent.indexes.size());
    for (const QPersistentModelIndexData *data : std::as_const(persistent.indexes)) {
        const QModelIndex &proxy_index = data->index;
        QModelIndex source_index = q->mapToSource(proxy_index);
        source_indexes.emplace_back(proxy_index, source_index);
    }
    return source_indexes;
}

/*!
  \internal

  Maps \a source_indexes to proxy indexes and stores those
  as persistent indexes.
*/
void QSortFilterProxyModelPrivate::update_persistent_indexes(
        const QModelIndexPairList &source_indexes)
{
    Q_Q(QSortFilterProxyModel);
    QModelIndexList from, to;
    const int numSourceIndexes = source_indexes.size();
    from.reserve(numSourceIndexes);
    to.reserve(numSourceIndexes);
    for (const auto &indexPair : source_indexes) {
        const QPersistentModelIndex &source_index = indexPair.second;
        const QModelIndex &old_proxy_index = indexPair.first;
        create_mapping(source_index.parent());
        QModelIndex proxy_index = q->mapFromSource(source_index);
        from << old_proxy_index;
        to << proxy_index;
    }
    q->changePersistentIndexList(from, to);
}

/*!
  \internal

  Updates the source_index mapping in case it's invalid and we
  need it because we have a valid filter
*/
void QSortFilterProxyModelPrivate::filter_about_to_be_changed(const QModelIndex &source_parent)
{
    if (!filter_regularexpression.valueBypassingBindings().pattern().isEmpty()
        && source_index_mapping.constFind(source_parent) == source_index_mapping.constEnd()) {
        create_mapping(source_parent);
    }
}


/*!
  \internal

  Updates the proxy model (adds/removes rows) based on the
  new filter.
*/
void QSortFilterProxyModelPrivate::filter_changed(Direction dir, const QModelIndex &source_parent)
{
    IndexMap::const_iterator it = source_index_mapping.constFind(source_parent);
    if (it == source_index_mapping.constEnd())
        return;
    Mapping *m = it.value();
    const QSet<int> rows_removed = (dir & Direction::Rows) ? handle_filter_changed(m->proxy_rows, m->source_rows, source_parent, Qt::Vertical) : QSet<int>();
    const QSet<int> columns_removed = (dir & Direction::Columns) ? handle_filter_changed(m->proxy_columns, m->source_columns, source_parent, Qt::Horizontal) : QSet<int>();

    // We need to iterate over a copy of m->mapped_children because otherwise it may be changed by other code, invalidating
    // the iterator it2.
    // The m->mapped_children vector can be appended to with indexes which are no longer filtered
    // out (in create_mapping) when this function recurses for child indexes.
    const QList<QModelIndex> mappedChildren = m->mapped_children;
    QList<int> indexesToRemove;
    for (int i = 0; i < mappedChildren.size(); ++i) {
        const QModelIndex &source_child_index = mappedChildren.at(i);
        if (rows_removed.contains(source_child_index.row()) || columns_removed.contains(source_child_index.column())) {
            indexesToRemove.push_back(i);
            remove_from_mapping(source_child_index);
        } else {
            filter_changed(dir, source_child_index);
        }
    }
    QList<int>::const_iterator removeIt = indexesToRemove.constEnd();
    const QList<int>::const_iterator removeBegin = indexesToRemove.constBegin();

    // We can't just remove these items from mappedChildren while iterating above and then
    // do something like m->mapped_children = mappedChildren, because mapped_children might
    // be appended to in create_mapping, and we would lose those new items.
    // Because they are always appended in create_mapping, we can still remove them by
    // position here.
    while (removeIt != removeBegin) {
        --removeIt;
        m->mapped_children.remove(*removeIt);
    }
}

/*!
  \internal
  returns the removed items indexes
*/
QSet<int> QSortFilterProxyModelPrivate::handle_filter_changed(
    QList<int> &source_to_proxy, QList<int> &proxy_to_source,
    const QModelIndex &source_parent, Qt::Orientation orient)
{
    Q_Q(QSortFilterProxyModel);
    // Figure out which mapped items to remove
    QList<int> source_items_remove;
    for (int i = 0; i < proxy_to_source.size(); ++i) {
        const int source_item = proxy_to_source.at(i);
        if ((orient == Qt::Vertical)
            ? !filterAcceptsRowInternal(source_item, source_parent)
            : !q->filterAcceptsColumn(source_item, source_parent)) {
            // This source item does not satisfy the filter, so it must be removed
            source_items_remove.append(source_item);
        }
    }
    // Figure out which non-mapped items to insert
    QList<int> source_items_insert;
    int source_count = source_to_proxy.size();
    for (int source_item = 0; source_item < source_count; ++source_item) {
        if (source_to_proxy.at(source_item) == -1) {
            if ((orient == Qt::Vertical)
                ? filterAcceptsRowInternal(source_item, source_parent)
                : q->filterAcceptsColumn(source_item, source_parent)) {
                // This source item satisfies the filter, so it must be added
                source_items_insert.append(source_item);
            }
        }
    }
    if (!source_items_remove.isEmpty() || !source_items_insert.isEmpty()) {
        // Do item removal and insertion
        remove_source_items(source_to_proxy, proxy_to_source,
                            source_items_remove, source_parent, orient);
        if (orient == Qt::Vertical)
            sort_source_rows(source_items_insert, source_parent);
        insert_source_items(source_to_proxy, proxy_to_source,
                            source_items_insert, source_parent, orient);
    }
    return qListToSet(source_items_remove);
}

bool QSortFilterProxyModelPrivate::needsReorder(const QList<int> &source_rows, const QModelIndex &source_parent) const
{
    Q_Q(const QSortFilterProxyModel);
    Q_ASSERT(source_sort_column != -1);
    const int proxyRowCount = q->rowCount(source_to_proxy(source_parent));
    // If any modified proxy row no longer passes lessThan(previous, current) or lessThan(current, next) then we need to reorder.
    return std::any_of(source_rows.begin(), source_rows.end(),
            [this, q, proxyRowCount, source_parent](int sourceRow) -> bool {
        const QModelIndex sourceIndex = model->index(sourceRow, source_sort_column, source_parent);
        const QModelIndex proxyIndex = source_to_proxy(sourceIndex);
        Q_ASSERT(proxyIndex.isValid()); // caller ensured source_rows were not filtered out
        if (proxyIndex.row() > 0) {
            const QModelIndex prevProxyIndex = q->sibling(proxyIndex.row() - 1, proxy_sort_column, proxyIndex);
            const QModelIndex prevSourceIndex = proxy_to_source(prevProxyIndex);
            if (sort_order == Qt::AscendingOrder ? q->lessThan(sourceIndex, prevSourceIndex) : q->lessThan(prevSourceIndex, sourceIndex))
                return true;
        }
        if (proxyIndex.row() < proxyRowCount - 1) {
            const QModelIndex nextProxyIndex = q->sibling(proxyIndex.row() + 1, proxy_sort_column, proxyIndex);
            const QModelIndex nextSourceIndex = proxy_to_source(nextProxyIndex);
            if (sort_order == Qt::AscendingOrder ? q->lessThan(nextSourceIndex, sourceIndex) : q->lessThan(sourceIndex, nextSourceIndex))
                return true;
        }
        return false;
    });
}

void QSortFilterProxyModelPrivate::_q_sourceDataChanged(const QModelIndex &source_top_left,
                                                        const QModelIndex &source_bottom_right,
                                                        const QList<int> &roles)
{
    Q_Q(QSortFilterProxyModel);
    if (!source_top_left.isValid() || !source_bottom_right.isValid())
        return;

    std::vector<QSortFilterProxyModelDataChanged> data_changed_list;
    data_changed_list.emplace_back(source_top_left, source_bottom_right);

    // Do check parents if the filter role have changed and we are recursive
    if (filter_recursive && (roles.isEmpty() || roles.contains(filter_role))) {
        QModelIndex source_parent = source_top_left.parent();

        while (source_parent.isValid()) {
            data_changed_list.emplace_back(source_parent, source_parent);
            source_parent = source_parent.parent();
        }
    }

    for (const QSortFilterProxyModelDataChanged &data_changed : data_changed_list) {
        const QModelIndex &source_top_left = data_changed.topLeft;
        const QModelIndex &source_bottom_right = data_changed.bottomRight;
        const QModelIndex source_parent = source_top_left.parent();

        bool change_in_unmapped_parent = false;
        IndexMap::const_iterator it = source_index_mapping.constFind(source_parent);
        if (it == source_index_mapping.constEnd()) {
            // We don't have mapping for this index, so we cannot know how things
            // changed (in case the change affects filtering) in order to forward
            // the change correctly.
            // But we can at least forward the signal "as is", if the row isn't
            // filtered out, this is better than nothing.
            it = create_mapping_recursive(source_parent);
            if (it == source_index_mapping.constEnd())
                continue;
            change_in_unmapped_parent = true;
        }

        Mapping *m = it.value();

        // Figure out how the source changes affect us
        QList<int> source_rows_remove;
        QList<int> source_rows_insert;
        QList<int> source_rows_change;
        QList<int> source_rows_resort;
        int end = qMin(source_bottom_right.row(), m->proxy_rows.size() - 1);
        for (int source_row = source_top_left.row(); source_row <= end; ++source_row) {
            if (dynamic_sortfilter && !change_in_unmapped_parent) {
                if (m->proxy_rows.at(source_row) != -1) {
                    if (!filterAcceptsRowInternal(source_row, source_parent)) {
                        // This source row no longer satisfies the filter, so it must be removed
                        source_rows_remove.append(source_row);
                    } else if (source_sort_column >= source_top_left.column() && source_sort_column <= source_bottom_right.column()) {
                        // This source row has changed in a way that may affect sorted order
                        source_rows_resort.append(source_row);
                    } else {
                        // This row has simply changed, without affecting filtering nor sorting
                        source_rows_change.append(source_row);
                    }
                } else {
                    if (!itemsBeingRemoved.contains(source_parent, source_row) && filterAcceptsRowInternal(source_row, source_parent)) {
                        // This source row now satisfies the filter, so it must be added
                        source_rows_insert.append(source_row);
                    }
                }
            } else {
                if (m->proxy_rows.at(source_row) != -1)
                    source_rows_change.append(source_row);
            }
        }

        if (!source_rows_remove.isEmpty()) {
            remove_source_items(m->proxy_rows, m->source_rows,
                                source_rows_remove, source_parent, Qt::Vertical);
            QSet<int> source_rows_remove_set = qListToSet(source_rows_remove);
            QList<QModelIndex>::iterator childIt = m->mapped_children.end();
            while (childIt != m->mapped_children.begin()) {
                --childIt;
                const QModelIndex source_child_index = *childIt;
                if (source_rows_remove_set.contains(source_child_index.row())) {
                    childIt = m->mapped_children.erase(childIt);
                    remove_from_mapping(source_child_index);
                }
            }
        }

        if (!source_rows_resort.isEmpty()) {
            if (needsReorder(source_rows_resort, source_parent)) {
                // Re-sort the rows of this level
                QList<QPersistentModelIndex> parents;
                parents << q->mapFromSource(source_parent);
                emit q->layoutAboutToBeChanged(parents, QAbstractItemModel::VerticalSortHint);
                QModelIndexPairList source_indexes = store_persistent_indexes();
                remove_source_items(m->proxy_rows, m->source_rows, source_rows_resort,
                        source_parent, Qt::Vertical, false);
                sort_source_rows(source_rows_resort, source_parent);
                insert_source_items(m->proxy_rows, m->source_rows, source_rows_resort,
                        source_parent, Qt::Vertical, false);
                update_persistent_indexes(source_indexes);
                emit q->layoutChanged(parents, QAbstractItemModel::VerticalSortHint);
            }
            // Make sure we also emit dataChanged for the rows
            source_rows_change += source_rows_resort;
        }

        if (!source_rows_change.isEmpty()) {
            // Find the proxy row range
            int proxy_start_row;
            int proxy_end_row;
            proxy_item_range(m->proxy_rows, source_rows_change,
                             proxy_start_row, proxy_end_row);
            // ### Find the proxy column range also
            if (proxy_end_row >= 0) {
                // the row was accepted, but some columns might still be filtered out
                int source_left_column = source_top_left.column();
                while (source_left_column < source_bottom_right.column()
                       && m->proxy_columns.at(source_left_column) == -1)
                    ++source_left_column;
                if (m->proxy_columns.at(source_left_column) != -1) {
                    const QModelIndex proxy_top_left = create_index(
                        proxy_start_row, m->proxy_columns.at(source_left_column), it);
                    int source_right_column = source_bottom_right.column();
                    while (source_right_column > source_top_left.column()
                           && m->proxy_columns.at(source_right_column) == -1)
                        --source_right_column;
                    if (m->proxy_columns.at(source_right_column) != -1) {
                        const QModelIndex proxy_bottom_right = create_index(
                            proxy_end_row, m->proxy_columns.at(source_right_column), it);
                        emit q->dataChanged(proxy_top_left, proxy_bottom_right, roles);
                    }
                }
            }
        }

        if (!source_rows_insert.isEmpty()) {
            sort_source_rows(source_rows_insert, source_parent);
            insert_source_items(m->proxy_rows, m->source_rows,
                                source_rows_insert, source_parent, Qt::Vertical);
        }
    }
}

void QSortFilterProxyModelPrivate::_q_sourceHeaderDataChanged(Qt::Orientation orientation,
                                                           int start, int end)
{
    Q_ASSERT(start <= end);

    Q_Q(QSortFilterProxyModel);
    Mapping *m = create_mapping(QModelIndex()).value();

    const QList<int> &source_to_proxy = (orientation == Qt::Vertical) ? m->proxy_rows : m->proxy_columns;

    QList<int> proxy_positions;
    proxy_positions.reserve(end - start + 1);
    {
        Q_ASSERT(source_to_proxy.size() > end);
        QList<int>::const_iterator it = source_to_proxy.constBegin() + start;
        const QList<int>::const_iterator endIt = source_to_proxy.constBegin() + end + 1;
        for ( ; it != endIt; ++it) {
            if (*it != -1)
                proxy_positions.push_back(*it);
        }
    }

    std::sort(proxy_positions.begin(), proxy_positions.end());

    int last_index = 0;
    const int numItems = proxy_positions.size();
    while (last_index < numItems) {
        const int proxyStart = proxy_positions.at(last_index);
        int proxyEnd = proxyStart;
        ++last_index;
        for (int i = last_index; i < numItems; ++i) {
            if (proxy_positions.at(i) == proxyEnd + 1) {
                ++last_index;
                ++proxyEnd;
            } else {
                break;
            }
        }
        emit q->headerDataChanged(orientation, proxyStart, proxyEnd);
    }
}

void QSortFilterProxyModelPrivate::_q_sourceAboutToBeReset()
{
    Q_Q(QSortFilterProxyModel);
    q->beginResetModel();
}

void QSortFilterProxyModelPrivate::_q_sourceReset()
{
    Q_Q(QSortFilterProxyModel);
    invalidatePersistentIndexes();
    _q_clearMapping();
    // All internal structures are deleted in clear()
    q->endResetModel();
    if (update_source_sort_column() && dynamic_sortfilter)
        sort();
}

void QSortFilterProxyModelPrivate::_q_sourceLayoutAboutToBeChanged(const QList<QPersistentModelIndex> &sourceParents, QAbstractItemModel::LayoutChangeHint hint)
{
    Q_Q(QSortFilterProxyModel);
    Q_UNUSED(hint); // We can't forward Hint because we might filter additional rows or columns
    saved_persistent_indexes.clear();

    saved_layoutChange_parents.clear();
    for (const QPersistentModelIndex &parent : sourceParents) {
        if (!parent.isValid()) {
            saved_layoutChange_parents << QPersistentModelIndex();
            continue;
        }
        const QModelIndex mappedParent = q->mapFromSource(parent);
        // Might be filtered out.
        if (mappedParent.isValid())
            saved_layoutChange_parents << mappedParent;
    }

    // All parents filtered out.
    if (!sourceParents.isEmpty() && saved_layoutChange_parents.isEmpty())
        return;

    emit q->layoutAboutToBeChanged(saved_layoutChange_parents);
    if (persistent.indexes.isEmpty())
        return;

    saved_persistent_indexes = store_persistent_indexes();
}

void QSortFilterProxyModelPrivate::_q_sourceLayoutChanged(const QList<QPersistentModelIndex> &sourceParents, QAbstractItemModel::LayoutChangeHint hint)
{
    Q_Q(QSortFilterProxyModel);
    Q_UNUSED(hint); // We can't forward Hint because we might filter additional rows or columns

    if (!sourceParents.isEmpty() && saved_layoutChange_parents.isEmpty())
        return;

    // Optimize: We only actually have to clear the mapping related to the contents of
    // sourceParents, not everything.
    qDeleteAll(source_index_mapping);
    source_index_mapping.clear();

    update_persistent_indexes(saved_persistent_indexes);
    saved_persistent_indexes.clear();

    if (dynamic_sortfilter)
        source_sort_column = find_source_sort_column();

    emit q->layoutChanged(saved_layoutChange_parents);
    saved_layoutChange_parents.clear();
}

void QSortFilterProxyModelPrivate::_q_sourceRowsAboutToBeInserted(
    const QModelIndex &source_parent, int start, int end)
{
    Q_UNUSED(start);
    Q_UNUSED(end);

    const bool toplevel = !source_parent.isValid();
    const bool recursive_accepted = filter_recursive && !toplevel && filterAcceptsRowInternal(source_parent.row(), source_parent.parent());
    //Force the creation of a mapping now, even if it's empty.
    //We need it because the proxy can be accessed at the moment it emits rowsAboutToBeInserted in insert_source_items
    if (!filter_recursive || toplevel || recursive_accepted) {
        if (can_create_mapping(source_parent))
            create_mapping(source_parent);
        if (filter_recursive)
            complete_insert = true;
    } else {
        // The row could have been rejected or the parent might be not yet known... let's try to discover it
        QModelIndex top_source_parent = source_parent;
        QModelIndex parent = source_parent.parent();
        QModelIndex grandParent = parent.parent();

        while (parent.isValid() && !filterAcceptsRowInternal(parent.row(), grandParent)) {
            top_source_parent = parent;
            parent = grandParent;
            grandParent = parent.parent();
        }

        last_top_source = top_source_parent;
    }
}

void QSortFilterProxyModelPrivate::_q_sourceRowsInserted(
    const QModelIndex &source_parent, int start, int end)
{
    if (!filter_recursive || complete_insert) {
        if (filter_recursive)
            complete_insert = false;
        source_items_inserted(source_parent, start, end, Qt::Vertical);
        if (update_source_sort_column() && dynamic_sortfilter) //previous call to update_source_sort_column may fail if the model has no column.
            sort();                      // now it should succeed so we need to make sure to sort again
        return;
    }

    if (filter_recursive) {
        bool accept = false;

        for (int row = start; row <= end; ++row) {
            if (filterAcceptsRowInternal(row, source_parent)) {
                accept = true;
                break;
            }
        }

        if (!accept) // the new rows have no descendants that match the filter, filter them out.
            return;

        // last_top_source should now become visible
        _q_sourceDataChanged(last_top_source, last_top_source, QList<int>());
    }
}

void QSortFilterProxyModelPrivate::_q_sourceRowsAboutToBeRemoved(
    const QModelIndex &source_parent, int start, int end)
{
    itemsBeingRemoved = QRowsRemoval(source_parent, start, end);
    source_items_about_to_be_removed(source_parent, start, end,
                                     Qt::Vertical);
}

void QSortFilterProxyModelPrivate::_q_sourceRowsRemoved(
    const QModelIndex &source_parent, int start, int end)
{
    itemsBeingRemoved = QRowsRemoval();
    source_items_removed(source_parent, start, end, Qt::Vertical);

    if (filter_recursive) {
        // Find out if removing this visible row means that some ascendant
        // row can now be hidden.
        // We go up until we find a row that should still be visible
        // and then make QSFPM re-evaluate the last one we saw before that, to hide it.

        QModelIndex to_hide;
        QModelIndex source_ascendant = source_parent;

        while (source_ascendant.isValid()) {
            if (filterAcceptsRowInternal(source_ascendant.row(), source_ascendant.parent()))
                break;

            to_hide = source_ascendant;
            source_ascendant = source_ascendant.parent();
        }

        if (to_hide.isValid())
            _q_sourceDataChanged(to_hide, to_hide, QList<int>());
    }
}

void QSortFilterProxyModelPrivate::_q_sourceRowsAboutToBeMoved(
    const QModelIndex &sourceParent, int /* sourceStart */, int /* sourceEnd */, const QModelIndex &destParent, int /* dest */)
{
    // Because rows which are contiguous in the source model might not be contiguous
    // in the proxy due to sorting, the best thing we can do here is be specific about what
    // parents are having their children changed.
    // Optimize: Emit move signals if the proxy is not sorted. Will need to account for rows
    // being filtered out though.

    QList<QPersistentModelIndex> parents;
    parents << sourceParent;
    if (sourceParent != destParent)
        parents << destParent;
    _q_sourceLayoutAboutToBeChanged(parents, QAbstractItemModel::NoLayoutChangeHint);
}

void QSortFilterProxyModelPrivate::_q_sourceRowsMoved(
    const QModelIndex &sourceParent, int /* sourceStart */, int /* sourceEnd */, const QModelIndex &destParent, int /* dest */)
{
    QList<QPersistentModelIndex> parents;
    parents << sourceParent;
    if (sourceParent != destParent)
        parents << destParent;
    _q_sourceLayoutChanged(parents, QAbstractItemModel::NoLayoutChangeHint);
}

void QSortFilterProxyModelPrivate::_q_sourceColumnsAboutToBeInserted(
    const QModelIndex &source_parent, int start, int end)
{
    Q_UNUSED(start);
    Q_UNUSED(end);
    //Force the creation of a mapping now, even if it's empty.
    //We need it because the proxy can be accessed at the moment it emits columnsAboutToBeInserted in insert_source_items
    if (can_create_mapping(source_parent))
        create_mapping(source_parent);
}

void QSortFilterProxyModelPrivate::_q_sourceColumnsInserted(
    const QModelIndex &source_parent, int start, int end)
{
    Q_Q(const QSortFilterProxyModel);
    source_items_inserted(source_parent, start, end, Qt::Horizontal);

    if (source_parent.isValid())
        return; //we sort according to the root column only
    if (source_sort_column == -1) {
        //we update the source_sort_column depending on the proxy_sort_column
        if (update_source_sort_column() && dynamic_sortfilter)
            sort();
    } else {
        if (start <= source_sort_column)
            source_sort_column += end - start + 1;

        proxy_sort_column = q->mapFromSource(model->index(0,source_sort_column, source_parent)).column();
    }
}

void QSortFilterProxyModelPrivate::_q_sourceColumnsAboutToBeRemoved(
    const QModelIndex &source_parent, int start, int end)
{
    source_items_about_to_be_removed(source_parent, start, end,
                                     Qt::Horizontal);
}

void QSortFilterProxyModelPrivate::_q_sourceColumnsRemoved(
    const QModelIndex &source_parent, int start, int end)
{
    Q_Q(const QSortFilterProxyModel);
    source_items_removed(source_parent, start, end, Qt::Horizontal);

    if (source_parent.isValid())
        return; //we sort according to the root column only
    if (start <= source_sort_column) {
        if (end < source_sort_column)
            source_sort_column -= end - start + 1;
        else
            source_sort_column = -1;
    }

    if (source_sort_column >= 0)
        proxy_sort_column = q->mapFromSource(model->index(0,source_sort_column, source_parent)).column();
    else
        proxy_sort_column = -1;
}

void QSortFilterProxyModelPrivate::_q_sourceColumnsAboutToBeMoved(
    const QModelIndex &sourceParent, int /* sourceStart */, int /* sourceEnd */, const QModelIndex &destParent, int /* dest */)
{
    QList<QPersistentModelIndex> parents;
    parents << sourceParent;
    if (sourceParent != destParent)
        parents << destParent;
    _q_sourceLayoutAboutToBeChanged(parents, QAbstractItemModel::NoLayoutChangeHint);
}

void QSortFilterProxyModelPrivate::_q_sourceColumnsMoved(
    const QModelIndex &sourceParent, int /* sourceStart */, int /* sourceEnd */, const QModelIndex &destParent, int /* dest */)
{
    QList<QPersistentModelIndex> parents;
    parents << sourceParent;
    if (sourceParent != destParent)
        parents << destParent;
    _q_sourceLayoutChanged(parents, QAbstractItemModel::NoLayoutChangeHint);
}

/*!
    \since 4.1
    \class QSortFilterProxyModel
    \inmodule QtCore
    \brief The QSortFilterProxyModel class provides support for sorting and
    filtering data passed between another model and a view.

    \ingroup model-view

    QSortFilterProxyModel can be used for sorting items, filtering out items,
    or both. The model transforms the structure of a source model by mapping
    the model indexes it supplies to new indexes, corresponding to different
    locations, for views to use. This approach allows a given source model to
    be restructured as far as views are concerned without requiring any
    transformations on the underlying data, and without duplicating the data in
    memory.

    Let's assume that we want to sort and filter the items provided by a custom
    model. The code to set up the model and the view, \e without sorting and
    filtering, would look like this:

    \snippet qsortfilterproxymodel-details/main.cpp 1

    To add sorting and filtering support to \c MyItemModel, we need to create
    a QSortFilterProxyModel, call setSourceModel() with the \c MyItemModel as
    argument, and install the QSortFilterProxyModel on the view:

    \snippet qsortfilterproxymodel-details/main.cpp 0
    \snippet qsortfilterproxymodel-details/main.cpp 2

    At this point, neither sorting nor filtering is enabled; the original data
    is displayed in the view. Any changes made through the
    QSortFilterProxyModel are applied to the original model.

    The QSortFilterProxyModel acts as a wrapper for the original model. If you
    need to convert source \l{QModelIndex}es to sorted/filtered model indexes
    or vice versa, use mapToSource(), mapFromSource(), mapSelectionToSource(),
    and mapSelectionFromSource().

    \note By default, the model dynamically re-sorts and re-filters data
    whenever the original model changes. This behavior can be changed by
    setting the \l{QSortFilterProxyModel::dynamicSortFilter}{dynamicSortFilter}
    property.

    The \l{itemviews/basicsortfiltermodel}{Basic Sort/Filter Model} and
    \l{itemviews/customsortfiltermodel}{Custom Sort/Filter Model} examples
    illustrate how to use QSortFilterProxyModel to perform basic sorting and
    filtering and how to subclass it to implement custom behavior.

    \section1 Sorting

    QTableView and QTreeView have a
    \l{QTreeView::sortingEnabled}{sortingEnabled} property that controls
    whether the user can sort the view by clicking the view's horizontal
    header. For example:

    \snippet qsortfilterproxymodel-details/main.cpp 3

    When this feature is on (the default is off), clicking on a header section
    sorts the items according to that column. By clicking repeatedly, the user
    can alternate between ascending and descending order.

    \image qsortfilterproxymodel-sorting.png A sorted QTreeView

    Behind the scene, the view calls the sort() virtual function on the model
    to reorder the data in the model. To make your data sortable, you can
    either implement sort() in your model, or use a QSortFilterProxyModel to
    wrap your model -- QSortFilterProxyModel provides a generic sort()
    reimplementation that operates on the sortRole() (Qt::DisplayRole by
    default) of the items and that understands several data types, including
    \c int, QString, and QDateTime. For hierarchical models, sorting is applied
    recursively to all child items. String comparisons are case sensitive by
    default; this can be changed by setting the \l{QSortFilterProxyModel::}
    {sortCaseSensitivity} property.

    Custom sorting behavior is achieved by subclassing
    QSortFilterProxyModel and reimplementing lessThan(), which is
    used to compare items. For example:

    \snippet ../widgets/itemviews/customsortfiltermodel/mysortfilterproxymodel.cpp 5

    (This code snippet comes from the
    \l{itemviews/customsortfiltermodel}{Custom Sort/Filter Model}
    example.)

    An alternative approach to sorting is to disable sorting on the view and to
    impose a certain order to the user. This is done by explicitly calling
    sort() with the desired column and order as arguments on the
    QSortFilterProxyModel (or on the original model if it implements sort()).
    For example:

    \snippet qsortfilterproxymodel-details/main.cpp 4

    QSortFilterProxyModel can be sorted by column -1, in which case it returns
    to the sort order of the underlying source model.

    \note \l sortColumn() returns the most recently used sort column.
    The default value is -1, which means that this proxy model does not sort.
    Also, note that \l sort() sets the \l sortColumn() to the most recently
    used sort column.

    \section1 Filtering

    In addition to sorting, QSortFilterProxyModel can be used to hide items
    that do not match a certain filter. The filter is specified using a QRegularExpression
    object and is applied to the filterRole() (Qt::DisplayRole by default) of
    each item, for a given column. The QRegularExpression object can be used to match a
    regular expression, a wildcard pattern, or a fixed string. For example:

    \snippet qsortfilterproxymodel-details/main.cpp 5

    For hierarchical models, the filter is applied recursively to all children.
    If a parent item doesn't match the filter, none of its children will be
    shown.

    A common use case is to let the user specify the filter regular expression,
    wildcard pattern, or fixed string in a QLineEdit and to connect the
    \l{QLineEdit::textChanged()}{textChanged()} signal to setFilterRegularExpression(),
    setFilterWildcard(), or setFilterFixedString() to reapply the filter.

    Custom filtering behavior can be achieved by reimplementing the
    filterAcceptsRow() and filterAcceptsColumn() functions. For
    example (from the \l{itemviews/customsortfiltermodel}
    {Custom Sort/Filter Model} example), the following implementation ignores
    the \l{QSortFilterProxyModel::filterKeyColumn}{filterKeyColumn} property
    and performs filtering on columns 0, 1, and 2:

    \snippet ../widgets/itemviews/customsortfiltermodel/mysortfilterproxymodel.cpp 3

    (This code snippet comes from the
    \l{itemviews/customsortfiltermodel}{Custom Sort/Filter Model}
    example.)

    If you are working with large amounts of filtering and have to invoke
    invalidateFilter() repeatedly, using beginResetModel() / endResetModel() may
    be more efficient, depending on the implementation of your model. However,
    beginResetModel() / endResetModel() returns the
    proxy model to its original state, losing selection information, and will
    cause the proxy model to be repopulated.

    \section1 Subclassing

    Since QAbstractProxyModel and its subclasses are derived from
    QAbstractItemModel, much of the same advice about subclassing normal models
    also applies to proxy models. In addition, it is worth noting that many of
    the default implementations of functions in this class are written so that
    they call the equivalent functions in the relevant source model. This
    simple proxying mechanism may need to be overridden for source models with
    more complex behavior; for example, if the source model provides a custom
    hasChildren() implementation, you should also provide one in the proxy
    model.

    \note Some general guidelines for subclassing models are available in the
    \l{Model Subclassing Reference}.

    \sa QAbstractProxyModel, QAbstractItemModel, {Model/View Programming},
    {Basic Sort/Filter Model Example}, {Custom Sort/Filter Model Example}, QIdentityProxyModel
*/

/*!
    Constructs a sorting filter model with the given \a parent.
*/

QSortFilterProxyModel::QSortFilterProxyModel(QObject *parent)
    : QAbstractProxyModel(*new QSortFilterProxyModelPrivate, parent)
{
    Q_D(QSortFilterProxyModel);
    QObjectPrivate::connect(this, &QAbstractItemModel::modelReset, d,
                            &QSortFilterProxyModelPrivate::_q_clearMapping);
}

/*!
    Destroys this sorting filter model.
*/
QSortFilterProxyModel::~QSortFilterProxyModel()
{
    Q_D(QSortFilterProxyModel);
    qDeleteAll(d->source_index_mapping);
    d->source_index_mapping.clear();
}

/*!
  \reimp
*/
void QSortFilterProxyModel::setSourceModel(QAbstractItemModel *sourceModel)
{
    Q_D(QSortFilterProxyModel);

    if (sourceModel == d->model)
        return;

    beginResetModel();

    if (d->model) {
        for (const QMetaObject::Connection &connection : std::as_const(d->sourceConnections))
            disconnect(connection);
    }

    // same as in _q_sourceReset()
    d->invalidatePersistentIndexes();
    d->_q_clearMapping();

    QAbstractProxyModel::setSourceModel(sourceModel);

    d->sourceConnections = std::array<QMetaObject::Connection, 18>{
        QObjectPrivate::connect(d->model, &QAbstractItemModel::dataChanged, d,
                                &QSortFilterProxyModelPrivate::_q_sourceDataChanged),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::headerDataChanged, d,
                                &QSortFilterProxyModelPrivate::_q_sourceHeaderDataChanged),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::rowsAboutToBeInserted, d,
                                &QSortFilterProxyModelPrivate::_q_sourceRowsAboutToBeInserted),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::rowsInserted, d,
                                &QSortFilterProxyModelPrivate::_q_sourceRowsInserted),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::columnsAboutToBeInserted, d,
                                &QSortFilterProxyModelPrivate::_q_sourceColumnsAboutToBeInserted),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::columnsInserted, d,
                                &QSortFilterProxyModelPrivate::_q_sourceColumnsInserted),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::rowsAboutToBeRemoved, d,
                                &QSortFilterProxyModelPrivate::_q_sourceRowsAboutToBeRemoved),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::rowsRemoved, d,
                                &QSortFilterProxyModelPrivate::_q_sourceRowsRemoved),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::columnsAboutToBeRemoved, d,
                                &QSortFilterProxyModelPrivate::_q_sourceColumnsAboutToBeRemoved),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::columnsRemoved, d,
                                &QSortFilterProxyModelPrivate::_q_sourceColumnsRemoved),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::rowsAboutToBeMoved, d,
                                &QSortFilterProxyModelPrivate::_q_sourceRowsAboutToBeMoved),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::rowsMoved, d,
                                &QSortFilterProxyModelPrivate::_q_sourceRowsMoved),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::columnsAboutToBeMoved, d,
                                &QSortFilterProxyModelPrivate::_q_sourceColumnsAboutToBeMoved),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::columnsMoved, d,
                                &QSortFilterProxyModelPrivate::_q_sourceColumnsMoved),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::layoutAboutToBeChanged, d,
                                &QSortFilterProxyModelPrivate::_q_sourceLayoutAboutToBeChanged),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::layoutChanged, d,
                                &QSortFilterProxyModelPrivate::_q_sourceLayoutChanged),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::modelAboutToBeReset, d,
                                &QSortFilterProxyModelPrivate::_q_sourceAboutToBeReset),

        QObjectPrivate::connect(d->model, &QAbstractItemModel::modelReset, d,
                                &QSortFilterProxyModelPrivate::_q_sourceReset)
    };
    endResetModel();
    if (d->update_source_sort_column() && d->dynamic_sortfilter)
        d->sort();
}

/*!
    \reimp
*/
QModelIndex QSortFilterProxyModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_D(const QSortFilterProxyModel);
    if (row < 0 || column < 0)
        return QModelIndex();

    QModelIndex source_parent = mapToSource(parent); // parent is already mapped at this point
    IndexMap::const_iterator it = d->create_mapping(source_parent); // but make sure that the children are mapped
    if (it.value()->source_rows.size() <= row || it.value()->source_columns.size() <= column)
        return QModelIndex();

    return d->create_index(row, column, it);
}

/*!
  \reimp
*/
QModelIndex QSortFilterProxyModel::parent(const QModelIndex &child) const
{
    Q_D(const QSortFilterProxyModel);
    if (!d->indexValid(child))
        return QModelIndex();
    IndexMap::const_iterator it = d->index_to_iterator(child);
    Q_ASSERT(it != d->source_index_mapping.constEnd());
    QModelIndex source_parent = it.key();
    QModelIndex proxy_parent = mapFromSource(source_parent);
    return proxy_parent;
}

/*!
  \reimp
*/
QModelIndex QSortFilterProxyModel::sibling(int row, int column, const QModelIndex &idx) const
{
    Q_D(const QSortFilterProxyModel);
    if (!d->indexValid(idx))
        return QModelIndex();

    const IndexMap::const_iterator it = d->index_to_iterator(idx);
    if (it.value()->source_rows.size() <= row || it.value()->source_columns.size() <= column)
        return QModelIndex();

    return d->create_index(row, column, it);
}

/*!
  \reimp
*/
int QSortFilterProxyModel::rowCount(const QModelIndex &parent) const
{
    Q_D(const QSortFilterProxyModel);
    QModelIndex source_parent = mapToSource(parent);
    if (parent.isValid() && !source_parent.isValid())
        return 0;
    IndexMap::const_iterator it = d->create_mapping(source_parent);
    return it.value()->source_rows.size();
}

/*!
  \reimp
*/
int QSortFilterProxyModel::columnCount(const QModelIndex &parent) const
{
    Q_D(const QSortFilterProxyModel);
    QModelIndex source_parent = mapToSource(parent);
    if (parent.isValid() && !source_parent.isValid())
        return 0;
    IndexMap::const_iterator it = d->create_mapping(source_parent);
    return it.value()->source_columns.size();
}

/*!
  \reimp
*/
bool QSortFilterProxyModel::hasChildren(const QModelIndex &parent) const
{
    Q_D(const QSortFilterProxyModel);
    QModelIndex source_parent = mapToSource(parent);
    if (parent.isValid() && !source_parent.isValid())
        return false;
    if (!d->model->hasChildren(source_parent))
        return false;

    if (d->model->canFetchMore(source_parent))
        return true; //we assume we might have children that can be fetched

    QSortFilterProxyModelPrivate::Mapping *m = d->create_mapping(source_parent).value();
    return m->source_rows.size() != 0 && m->source_columns.size() != 0;
}

/*!
  \reimp
*/
QVariant QSortFilterProxyModel::data(const QModelIndex &index, int role) const
{
    Q_D(const QSortFilterProxyModel);
    QModelIndex source_index = mapToSource(index);
    if (index.isValid() && !source_index.isValid())
        return QVariant();
    return d->model->data(source_index, role);
}

/*!
  \reimp
*/
bool QSortFilterProxyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_D(QSortFilterProxyModel);
    QModelIndex source_index = mapToSource(index);
    if (index.isValid() && !source_index.isValid())
        return false;
    return d->model->setData(source_index, value, role);
}

/*!
  \reimp
*/
QVariant QSortFilterProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    Q_D(const QSortFilterProxyModel);
    IndexMap::const_iterator it = d->create_mapping(QModelIndex());
    if (it.value()->source_rows.size() * it.value()->source_columns.size() > 0)
        return QAbstractProxyModel::headerData(section, orientation, role);
    int source_section;
    if (orientation == Qt::Vertical) {
        if (section < 0 || section >= it.value()->source_rows.size())
            return QVariant();
        source_section = it.value()->source_rows.at(section);
    } else {
        if (section < 0 || section >= it.value()->source_columns.size())
            return QVariant();
        source_section = it.value()->source_columns.at(section);
    }
    return d->model->headerData(source_section, orientation, role);
}

/*!
  \reimp
*/
bool QSortFilterProxyModel::setHeaderData(int section, Qt::Orientation orientation,
                                          const QVariant &value, int role)
{
    Q_D(QSortFilterProxyModel);
    IndexMap::const_iterator it = d->create_mapping(QModelIndex());
    if (it.value()->source_rows.size() * it.value()->source_columns.size() > 0)
        return QAbstractProxyModel::setHeaderData(section, orientation, value, role);
    int source_section;
    if (orientation == Qt::Vertical) {
        if (section < 0 || section >= it.value()->source_rows.size())
            return false;
        source_section = it.value()->source_rows.at(section);
    } else {
        if (section < 0 || section >= it.value()->source_columns.size())
            return false;
        source_section = it.value()->source_columns.at(section);
    }
    return d->model->setHeaderData(source_section, orientation, value, role);
}

/*!
  \reimp
*/
QMimeData *QSortFilterProxyModel::mimeData(const QModelIndexList &indexes) const
{
    Q_D(const QSortFilterProxyModel);
    QModelIndexList source_indexes;
    source_indexes.reserve(indexes.size());
    for (const QModelIndex &idx : indexes)
        source_indexes << mapToSource(idx);
    return d->model->mimeData(source_indexes);
}

/*!
  \reimp
*/
QStringList QSortFilterProxyModel::mimeTypes() const
{
    Q_D(const QSortFilterProxyModel);
    return d->model->mimeTypes();
}

/*!
  \reimp
*/
Qt::DropActions QSortFilterProxyModel::supportedDropActions() const
{
    Q_D(const QSortFilterProxyModel);
    return d->model->supportedDropActions();
}

// Qt6: remove unnecessary reimplementation
/*!
  \reimp
*/
bool QSortFilterProxyModel::dropMimeData(const QMimeData *data, Qt::DropAction action,
                                         int row, int column, const QModelIndex &parent)
{
    return QAbstractProxyModel::dropMimeData(data, action, row, column, parent);
}

/*!
  \reimp
*/
bool QSortFilterProxyModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_D(QSortFilterProxyModel);
    if (row < 0 || count <= 0)
        return false;
    QModelIndex source_parent = mapToSource(parent);
    if (parent.isValid() && !source_parent.isValid())
        return false;
    QSortFilterProxyModelPrivate::Mapping *m = d->create_mapping(source_parent).value();
    if (row > m->source_rows.size())
        return false;
    int source_row = (row >= m->source_rows.size()
                      ? m->proxy_rows.size()
                      : m->source_rows.at(row));
    return d->model->insertRows(source_row, count, source_parent);
}

/*!
  \reimp
*/
bool QSortFilterProxyModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    Q_D(QSortFilterProxyModel);
    if (column < 0|| count <= 0)
        return false;
    QModelIndex source_parent = mapToSource(parent);
    if (parent.isValid() && !source_parent.isValid())
        return false;
    QSortFilterProxyModelPrivate::Mapping *m = d->create_mapping(source_parent).value();
    if (column > m->source_columns.size())
        return false;
    int source_column = (column >= m->source_columns.size()
                         ? m->proxy_columns.size()
                         : m->source_columns.at(column));
    return d->model->insertColumns(source_column, count, source_parent);
}

/*!
  \reimp
*/
bool QSortFilterProxyModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_D(QSortFilterProxyModel);
    if (row < 0 || count <= 0)
        return false;
    QModelIndex source_parent = mapToSource(parent);
    if (parent.isValid() && !source_parent.isValid())
        return false;
    QSortFilterProxyModelPrivate::Mapping *m = d->create_mapping(source_parent).value();
    if (row + count > m->source_rows.size())
        return false;
    if ((count == 1)
        || ((d->source_sort_column < 0) && (m->proxy_rows.size() == m->source_rows.size()))) {
        int source_row = m->source_rows.at(row);
        return d->model->removeRows(source_row, count, source_parent);
    }
    // remove corresponding source intervals
    // ### if this proves to be slow, we can switch to single-row removal
    QList<int> rows;
    rows.reserve(count);
    for (int i = row; i < row + count; ++i)
        rows.append(m->source_rows.at(i));
    std::sort(rows.begin(), rows.end());

    int pos = rows.size() - 1;
    bool ok = true;
    while (pos >= 0) {
        const int source_end = rows.at(pos--);
        int source_start = source_end;
        while ((pos >= 0) && (rows.at(pos) == (source_start - 1))) {
            --source_start;
            --pos;
        }
        ok = ok && d->model->removeRows(source_start, source_end - source_start + 1,
                                        source_parent);
    }
    return ok;
}

/*!
  \reimp
*/
bool QSortFilterProxyModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    Q_D(QSortFilterProxyModel);
    if (column < 0 || count <= 0)
        return false;
    QModelIndex source_parent = mapToSource(parent);
    if (parent.isValid() && !source_parent.isValid())
        return false;
    QSortFilterProxyModelPrivate::Mapping *m = d->create_mapping(source_parent).value();
    if (column + count > m->source_columns.size())
        return false;
    if ((count == 1) || (m->proxy_columns.size() == m->source_columns.size())) {
        int source_column = m->source_columns.at(column);
        return d->model->removeColumns(source_column, count, source_parent);
    }
    // remove corresponding source intervals
    QList<int> columns;
    columns.reserve(count);
    for (int i = column; i < column + count; ++i)
        columns.append(m->source_columns.at(i));

    int pos = columns.size() - 1;
    bool ok = true;
    while (pos >= 0) {
        const int source_end = columns.at(pos--);
        int source_start = source_end;
        while ((pos >= 0) && (columns.at(pos) == (source_start - 1))) {
            --source_start;
            --pos;
        }
        ok = ok && d->model->removeColumns(source_start, source_end - source_start + 1,
                                           source_parent);
    }
    return ok;
}

/*!
  \reimp
*/
void QSortFilterProxyModel::fetchMore(const QModelIndex &parent)
{
    QAbstractProxyModel::fetchMore(parent);
}

/*!
  \reimp
*/
bool QSortFilterProxyModel::canFetchMore(const QModelIndex &parent) const
{
    return QAbstractProxyModel::canFetchMore(parent);
}

/*!
  \reimp
*/
Qt::ItemFlags QSortFilterProxyModel::flags(const QModelIndex &index) const
{
    return QAbstractProxyModel::flags(index);
}

/*!
  \reimp
*/
QModelIndex QSortFilterProxyModel::buddy(const QModelIndex &index) const
{
    Q_D(const QSortFilterProxyModel);
    if (!d->indexValid(index))
        return QModelIndex();
    QModelIndex source_index = mapToSource(index);
    QModelIndex source_buddy = d->model->buddy(source_index);
    if (source_index == source_buddy)
        return index;
    return mapFromSource(source_buddy);
}

/*!
  \reimp
*/
QModelIndexList QSortFilterProxyModel::match(const QModelIndex &start, int role,
                                             const QVariant &value, int hits,
                                             Qt::MatchFlags flags) const
{
    return QAbstractProxyModel::match(start, role, value, hits, flags);
}

/*!
  \reimp
*/
QSize QSortFilterProxyModel::span(const QModelIndex &index) const
{
    Q_D(const QSortFilterProxyModel);
    QModelIndex source_index = mapToSource(index);
    if (index.isValid() && !source_index.isValid())
        return QSize();
    return d->model->span(source_index);
}

/*!
    \reimp
    Sorts the model by \a column in the given \a order.
    If the sort \a column is less than zero, the model will be sorted by source model row
    in the given \a order.

    \sa sortColumn()
*/
void QSortFilterProxyModel::sort(int column, Qt::SortOrder order)
{
    Q_D(QSortFilterProxyModel);
    if (d->dynamic_sortfilter && d->proxy_sort_column == column && d->sort_order == order)
        return;
    d->sort_order = order;
    d->proxy_sort_column = column;
    d->update_source_sort_column();
    d->sort();
}

/*!
    \since 4.5
    \return the column currently used for sorting

    This returns the most recently used sort column. The default value is -1,
    which means that this proxy model does not sort.

    \sa sort()
*/
int QSortFilterProxyModel::sortColumn() const
{
    Q_D(const QSortFilterProxyModel);
    return d->proxy_sort_column;
}

/*!
    \since 4.5
    \return the order currently used for sorting

    This returns the most recently used sort order. The default value is
    Qt::AscendingOrder.

    \sa sort()
*/
Qt::SortOrder QSortFilterProxyModel::sortOrder() const
{
    Q_D(const QSortFilterProxyModel);
    return d->sort_order;
}

/*!
    \since 5.12
    \property QSortFilterProxyModel::filterRegularExpression
    \brief the QRegularExpression used to filter the contents of the source model

    Setting this property through the QRegularExpression overload overwrites the
    current \l{QSortFilterProxyModel::filterCaseSensitivity}{filterCaseSensitivity}.
    By default, the QRegularExpression is an empty string matching all contents.

    If no QRegularExpression or an empty string is set, everything in the source
    model will be accepted.

    \note Setting this property propagates the case sensitivity of the new
    regular expression to the \l filterCaseSensitivity property, and so breaks
    its binding. Likewise explicitly setting \l filterCaseSensitivity changes
    the case sensitivity of the current regular expression, thereby breaking
    its binding.

    \sa filterCaseSensitivity, setFilterWildcard(), setFilterFixedString()
*/
QRegularExpression QSortFilterProxyModel::filterRegularExpression() const
{
    Q_D(const QSortFilterProxyModel);
    return d->filter_regularexpression;
}

QBindable<QRegularExpression> QSortFilterProxyModel::bindableFilterRegularExpression()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<QRegularExpression>(&d->filter_regularexpression);
}

void QSortFilterProxyModel::setFilterRegularExpression(const QRegularExpression &regularExpression)
{
    Q_D(QSortFilterProxyModel);
    const QScopedPropertyUpdateGroup guard;
    const bool regExpChanged =
            regularExpression != d->filter_regularexpression.valueBypassingBindings();
    d->filter_regularexpression.removeBindingUnlessInWrapper();
    d->filter_casesensitive.removeBindingUnlessInWrapper();
    const Qt::CaseSensitivity cs = d->filter_casesensitive.valueBypassingBindings();
    d->filter_about_to_be_changed();
    const Qt::CaseSensitivity updatedCs =
            regularExpression.patternOptions() & QRegularExpression::CaseInsensitiveOption
            ? Qt::CaseInsensitive : Qt::CaseSensitive;
    d->filter_regularexpression.setValueBypassingBindings(regularExpression);
    if (cs != updatedCs)
        d->filter_casesensitive.setValueBypassingBindings(updatedCs);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    // Do not change the evaluation logic, but notify only if the regular
    // expression has actually changed.
    if (regExpChanged)
        d->filter_regularexpression.notify();
    if (cs != updatedCs)
        d->filter_casesensitive.notify();
}

/*!
    \property QSortFilterProxyModel::filterKeyColumn
    \brief the column where the key used to filter the contents of the
    source model is read from.

    The default value is 0. If the value is -1, the keys will be read
    from all columns.
*/
int QSortFilterProxyModel::filterKeyColumn() const
{
    Q_D(const QSortFilterProxyModel);
    return d->filter_column;
}

void QSortFilterProxyModel::setFilterKeyColumn(int column)
{
    // While introducing new bindable properties, we still update the value
    // unconditionally (even if it didn't really change), and call the
    // filter_about_to_be_changed()/filter_changed() methods, so that we do
    // not break any code. However we do notify the observing bindings only
    // if the column has actually changed
    Q_D(QSortFilterProxyModel);
    d->filter_column.removeBindingUnlessInWrapper();
    d->filter_about_to_be_changed();
    const auto oldColumn = d->filter_column.valueBypassingBindings();
    d->filter_column.setValueBypassingBindings(column);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    if (oldColumn != column)
        d->filter_column.notify();
}

QBindable<int> QSortFilterProxyModel::bindableFilterKeyColumn()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<int>(&d->filter_column);
}

/*!
    \property QSortFilterProxyModel::filterCaseSensitivity

    \brief the case sensitivity of the QRegularExpression pattern used to filter the
    contents of the source model.

    By default, the filter is case sensitive.

    \note Setting this property propagates the new case sensitivity to the
    \l filterRegularExpression property, and so breaks its binding. Likewise
    explicitly setting \l filterRegularExpression changes the current case
    sensitivity, thereby breaking its binding.

    \sa filterRegularExpression, sortCaseSensitivity
*/

/*!
    \since 5.15
    \fn void QSortFilterProxyModel::filterCaseSensitivityChanged(Qt::CaseSensitivity filterCaseSensitivity)
    \brief This signal is emitted when the case sensitivity of the filter
           changes to \a filterCaseSensitivity.
 */
Qt::CaseSensitivity QSortFilterProxyModel::filterCaseSensitivity() const
{
    Q_D(const QSortFilterProxyModel);
    return d->filter_casesensitive;
}

void QSortFilterProxyModel::setFilterCaseSensitivity(Qt::CaseSensitivity cs)
{
    Q_D(QSortFilterProxyModel);
    d->filter_casesensitive.removeBindingUnlessInWrapper();
    d->filter_regularexpression.removeBindingUnlessInWrapper();
    if (cs == d->filter_casesensitive)
        return;

    const QScopedPropertyUpdateGroup guard;
    QRegularExpression::PatternOptions options =
            d->filter_regularexpression.value().patternOptions();
    options.setFlag(QRegularExpression::CaseInsensitiveOption, cs == Qt::CaseInsensitive);
    d->filter_casesensitive.setValueBypassingBindings(cs);

    d->filter_about_to_be_changed();
    QRegularExpression re = d->filter_regularexpression;
    re.setPatternOptions(options);
    d->filter_regularexpression.setValueBypassingBindings(re);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    d->filter_regularexpression.notify();
    d->filter_casesensitive.notify();
}

QBindable<Qt::CaseSensitivity> QSortFilterProxyModel::bindableFilterCaseSensitivity()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<Qt::CaseSensitivity>(&d->filter_casesensitive);
}

/*!
    \since 4.2
    \property QSortFilterProxyModel::sortCaseSensitivity
    \brief the case sensitivity setting used for comparing strings when sorting

    By default, sorting is case sensitive.

    \sa filterCaseSensitivity, lessThan()
*/

/*!
    \since 5.15
    \fn void QSortFilterProxyModel::sortCaseSensitivityChanged(Qt::CaseSensitivity sortCaseSensitivity)
    \brief This signal is emitted when the case sensitivity for sorting
           changes to \a sortCaseSensitivity.
*/
Qt::CaseSensitivity QSortFilterProxyModel::sortCaseSensitivity() const
{
    Q_D(const QSortFilterProxyModel);
    return d->sort_casesensitivity;
}

void QSortFilterProxyModel::setSortCaseSensitivity(Qt::CaseSensitivity cs)
{
    Q_D(QSortFilterProxyModel);
    d->sort_casesensitivity.removeBindingUnlessInWrapper();
    if (d->sort_casesensitivity == cs)
        return;

    d->sort_casesensitivity.setValueBypassingBindings(cs);
    d->sort();
    d->sort_casesensitivity.notify(); // also emits a signal
}

QBindable<Qt::CaseSensitivity> QSortFilterProxyModel::bindableSortCaseSensitivity()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<Qt::CaseSensitivity>(&d->sort_casesensitivity);
}

/*!
    \since 4.3
    \property QSortFilterProxyModel::isSortLocaleAware
    \brief the local aware setting used for comparing strings when sorting

    By default, sorting is not local aware.

    \sa sortCaseSensitivity, lessThan()
*/

/*!
    \since 5.15
    \fn void QSortFilterProxyModel::sortLocaleAwareChanged(bool sortLocaleAware)
    \brief This signal is emitted when the locale aware setting
           changes to \a sortLocaleAware.
*/
bool QSortFilterProxyModel::isSortLocaleAware() const
{
    Q_D(const QSortFilterProxyModel);
    return d->sort_localeaware;
}

void QSortFilterProxyModel::setSortLocaleAware(bool on)
{
    Q_D(QSortFilterProxyModel);
    d->sort_localeaware.removeBindingUnlessInWrapper();
    if (d->sort_localeaware == on)
        return;

    d->sort_localeaware.setValueBypassingBindings(on);
    d->sort();
    d->sort_localeaware.notify(); // also emits a signal
}

QBindable<bool> QSortFilterProxyModel::bindableIsSortLocaleAware()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<bool>(&d->sort_localeaware);
}

/*!
    \since 5.12

    Sets the regular expression used to filter the contents
    of the source model to \a pattern.

    This method should be preferred for new code as it will use
    QRegularExpression internally.

    This method will reset the regular expression options
    but respect case sensitivity.

    \note Calling this method updates the regular expression, thereby breaking
    the binding for \l filterRegularExpression. However it has no effect on the
    \l filterCaseSensitivity bindings.

    \sa setFilterCaseSensitivity(), setFilterWildcard(), setFilterFixedString(), filterRegularExpression()
*/
void QSortFilterProxyModel::setFilterRegularExpression(const QString &pattern)
{
    Q_D(QSortFilterProxyModel);
    d->filter_regularexpression.removeBindingUnlessInWrapper();
    d->filter_about_to_be_changed();
    d->set_filter_pattern(pattern);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    d->filter_regularexpression.notify();
}

/*!
    Sets the wildcard expression used to filter the contents
    of the source model to the given \a pattern.

    This method will reset the regular expression options
    but respect case sensitivity.

    \note Calling this method updates the regular expression, thereby breaking
    the binding for \l filterRegularExpression. However it has no effect on the
    \l filterCaseSensitivity bindings.

    \sa setFilterCaseSensitivity(), setFilterRegularExpression(), setFilterFixedString(), filterRegularExpression()
*/
void QSortFilterProxyModel::setFilterWildcard(const QString &pattern)
{
    Q_D(QSortFilterProxyModel);
    d->filter_regularexpression.removeBindingUnlessInWrapper();
    d->filter_about_to_be_changed();
    d->set_filter_pattern(QRegularExpression::wildcardToRegularExpression(
            pattern, QRegularExpression::UnanchoredWildcardConversion));
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    d->filter_regularexpression.notify();
}

/*!
    Sets the fixed string used to filter the contents
    of the source model to the given \a pattern.

    This method will reset the regular expression options
    but respect case sensitivity.

    \note Calling this method updates the regular expression, thereby breaking
    the binding for \l filterRegularExpression. However it has no effect on the
    \l filterCaseSensitivity bindings.

    \sa setFilterCaseSensitivity(), setFilterRegularExpression(), setFilterWildcard(), filterRegularExpression()
*/
void QSortFilterProxyModel::setFilterFixedString(const QString &pattern)
{
    Q_D(QSortFilterProxyModel);
    d->filter_regularexpression.removeBindingUnlessInWrapper();
    d->filter_about_to_be_changed();
    d->set_filter_pattern(QRegularExpression::escape(pattern));
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    d->filter_regularexpression.notify();
}

/*!
    \since 4.2
    \property QSortFilterProxyModel::dynamicSortFilter
    \brief whether the proxy model is dynamically sorted and filtered
    whenever the contents of the source model change

    Note that you should not update the source model through the proxy
    model when dynamicSortFilter is true. For instance, if you set the
    proxy model on a QComboBox, then using functions that update the
    model, e.g., \l{QComboBox::}{addItem()}, will not work as
    expected. An alternative is to set dynamicSortFilter to false and
    call \l{QSortFilterProxyModel::}{sort()} after adding items to the
    QComboBox.

    The default value is true.

    \sa sortColumn()
*/
bool QSortFilterProxyModel::dynamicSortFilter() const
{
    Q_D(const QSortFilterProxyModel);
    return d->dynamic_sortfilter;
}

void QSortFilterProxyModel::setDynamicSortFilter(bool enable)
{
    // While introducing new bindable properties, we still update the value
    // unconditionally (even if it didn't really change), and call the
    // sort() method, so that we do not break any code.
    // However we do notify the observing bindings only if the value has
    // actually changed.
    Q_D(QSortFilterProxyModel);
    d->dynamic_sortfilter.removeBindingUnlessInWrapper();
    const bool valueChanged = d->dynamic_sortfilter.value() != enable;
    d->dynamic_sortfilter.setValueBypassingBindings(enable);
    if (enable)
        d->sort();
    if (valueChanged)
        d->dynamic_sortfilter.notify();
}

QBindable<bool> QSortFilterProxyModel::bindableDynamicSortFilter()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<bool>(&d->dynamic_sortfilter);
}

/*!
    \since 4.2
    \property QSortFilterProxyModel::sortRole
    \brief the item role that is used to query the source model's data when
           sorting items.

    The default value is Qt::DisplayRole.

    \sa lessThan()
*/

/*!
    \since 5.15
    \fn void QSortFilterProxyModel::sortRoleChanged(int sortRole)
    \brief This signal is emitted when the sort role changes to \a sortRole.
*/
int QSortFilterProxyModel::sortRole() const
{
    Q_D(const QSortFilterProxyModel);
    return d->sort_role;
}

void QSortFilterProxyModel::setSortRole(int role)
{
    Q_D(QSortFilterProxyModel);
    d->sort_role.removeBindingUnlessInWrapper();
    if (d->sort_role.valueBypassingBindings() == role)
        return;
    d->sort_role.setValueBypassingBindings(role);
    d->sort();
    d->sort_role.notify(); // also emits a signal
}

QBindable<int> QSortFilterProxyModel::bindableSortRole()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<int>(&d->sort_role);
}

/*!
    \since 4.2
    \property QSortFilterProxyModel::filterRole
    \brief the item role that is used to query the source model's data when
           filtering items.

    The default value is Qt::DisplayRole.

    \sa filterAcceptsRow()
*/

/*!
    \since 5.15
    \fn void QSortFilterProxyModel::filterRoleChanged(int filterRole)
    \brief This signal is emitted when the filter role changes to \a filterRole.
*/
int QSortFilterProxyModel::filterRole() const
{
    Q_D(const QSortFilterProxyModel);
    return d->filter_role;
}

void QSortFilterProxyModel::setFilterRole(int role)
{
    Q_D(QSortFilterProxyModel);
    d->filter_role.removeBindingUnlessInWrapper();
    if (d->filter_role.valueBypassingBindings() == role)
        return;
    d->filter_about_to_be_changed();
    d->filter_role.setValueBypassingBindings(role);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    d->filter_role.notify(); // also emits a signal
}

QBindable<int> QSortFilterProxyModel::bindableFilterRole()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<int>(&d->filter_role);
}

/*!
    \since 5.10
    \property QSortFilterProxyModel::recursiveFilteringEnabled
    \brief whether the filter to be applied recursively on children, and for
    any matching child, its parents will be visible as well.

    The default value is false.

    \sa autoAcceptChildRows
    \sa filterAcceptsRow()
*/

/*!
    \since 5.15
    \fn void QSortFilterProxyModel::recursiveFilteringEnabledChanged(bool recursiveFilteringEnabled)
    \brief This signal is emitted when the recursive filter setting is changed
           to \a recursiveFilteringEnabled.
*/
bool QSortFilterProxyModel::isRecursiveFilteringEnabled() const
{
    Q_D(const QSortFilterProxyModel);
    return d->filter_recursive;
}

void QSortFilterProxyModel::setRecursiveFilteringEnabled(bool recursive)
{
    Q_D(QSortFilterProxyModel);
    d->filter_recursive.removeBindingUnlessInWrapper();
    if (d->filter_recursive == recursive)
        return;
    d->filter_about_to_be_changed();
    d->filter_recursive.setValueBypassingBindings(recursive);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    d->filter_recursive.notify(); // also emits a signal
}

QBindable<bool> QSortFilterProxyModel::bindableRecursiveFilteringEnabled()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<bool>(&d->filter_recursive);
}

/*!
    \since 6.0
    \property QSortFilterProxyModel::autoAcceptChildRows
    \brief if true the proxy model will not filter out children of accepted
    rows, even if they themselves would be filtered out otherwise.

    The default value is false.

    \sa recursiveFilteringEnabled
    \sa filterAcceptsRow()
*/

/*!
    \since 6.0
    \fn void QSortFilterProxyModel::autoAcceptChildRowsChanged(bool autoAcceptChildRows)

    \brief This signals is emitted when the value of the \a autoAcceptChildRows property is changed.

    \sa autoAcceptChildRows
*/
bool QSortFilterProxyModel::autoAcceptChildRows() const
{
    Q_D(const QSortFilterProxyModel);
    return d->accept_children;
}

void QSortFilterProxyModel::setAutoAcceptChildRows(bool accept)
{
    Q_D(QSortFilterProxyModel);
    d->accept_children.removeBindingUnlessInWrapper();
    if (d->accept_children == accept)
        return;

    d->filter_about_to_be_changed();
    d->accept_children.setValueBypassingBindings(accept);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
    d->accept_children.notify(); // also emits a signal
}

QBindable<bool> QSortFilterProxyModel::bindableAutoAcceptChildRows()
{
    Q_D(QSortFilterProxyModel);
    return QBindable<bool>(&d->accept_children);
}

/*!
   \since 4.3

    Invalidates the current sorting and filtering.

    \sa invalidateFilter()
*/
void QSortFilterProxyModel::invalidate()
{
    Q_D(QSortFilterProxyModel);
    emit layoutAboutToBeChanged();
    d->_q_clearMapping();
    emit layoutChanged();
}

/*!
   \since 6.9

   Prepares a change of the filter.

   This function should be called if you are implementing custom filtering
   (e.g. filterAcceptsRow()), and your filter parameter is about to be changed.

    \snippet ../widgets/itemviews/customsortfiltermodel/mysortfilterproxymodel.cpp 2

    \sa invalidateFilter(), invalidateColumnsFilter(), invalidateRowsFilter()
*/

void QSortFilterProxyModel::beginFilterChange()
{
    Q_D(QSortFilterProxyModel);
    d->create_mapping({});
}

/*!
   \since 4.3

   Invalidates the current filtering.

   This function should be called if you are implementing custom filtering
   (e.g. filterAcceptsRow()), and your filter parameters have changed.

   Before your filter parameters change, call beginFilterChange().

   \snippet ../widgets/itemviews/customsortfiltermodel/mysortfilterproxymodel.cpp 2

   \sa invalidate(), invalidateColumnsFilter(), invalidateRowsFilter(),
       beginFilterChange()
*/
void QSortFilterProxyModel::invalidateFilter()
{
    Q_D(QSortFilterProxyModel);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::All);
}

/*!
   \since 6.0

   Invalidates the current filtering for the columns.

   This function should be called if you are implementing custom filtering
   (by filterAcceptsColumn()), and your filter parameters have changed.
   This differs from invalidateFilter() in that it will not invoke
   filterAcceptsRow(), but only filterAcceptsColumn(). You can use this
   instead of invalidateFilter() if you want to hide or show a column where
   the rows don't change.

   Before your filter parameters change, call beginFilterChange().

   \sa invalidate(), invalidateRowsFilter(), beginFilterChange()
*/
void QSortFilterProxyModel::invalidateColumnsFilter()
{
    Q_D(QSortFilterProxyModel);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Columns);
}

/*!
   \since 6.0

   Invalidates the current filtering for the rows.

   This function should be called if you are implementing custom filtering
   (by filterAcceptsRow()), and your filter parameters have changed.
   This differs from invalidateFilter() in that it will not invoke
   filterAcceptsColumn(), but only filterAcceptsRow(). You can use this
   instead of invalidateFilter() if you want to hide or show a row where
   the columns don't change.

   Before your filter parameters change, call beginFilterChange().

   \sa invalidate(), invalidateFilter(), invalidateColumnsFilter()
*/
void QSortFilterProxyModel::invalidateRowsFilter()
{
    Q_D(QSortFilterProxyModel);
    d->filter_changed(QSortFilterProxyModelPrivate::Direction::Rows);
}

/*!
    Returns \c true if the value of the item referred to by the given
    index \a source_left is less than the value of the item referred to by
    the given index \a source_right, otherwise returns \c false.

    This function is used as the < operator when sorting, and handles
    the following QVariant types:

    \list
    \li QMetaType::Int
    \li QMetaType::UInt
    \li QMetaType::LongLong
    \li QMetaType::ULongLong
    \li QMetaType::Float
    \li QMetaType::Double
    \li QMetaType::QChar
    \li QMetaType::QDate
    \li QMetaType::QTime
    \li QMetaType::QDateTime
    \li QMetaType::QString
    \endlist

    Any other type will be converted to a QString using
    QVariant::toString().

    Comparison of \l{QString}s is case sensitive by default; this can
    be changed using the \l {QSortFilterProxyModel::sortCaseSensitivity}
    {sortCaseSensitivity} property.

    By default, the Qt::DisplayRole associated with the
    \l{QModelIndex}es is used for comparisons. This can be changed by
    setting the \l {QSortFilterProxyModel::sortRole} {sortRole} property.

    \note The indices passed in correspond to the source model.

    \sa sortRole, sortCaseSensitivity, dynamicSortFilter
*/
bool QSortFilterProxyModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
{
    Q_D(const QSortFilterProxyModel);
    const QVariant l = source_left.data(d->sort_role);
    const QVariant r = source_right.data(d->sort_role);
    return QAbstractItemModelPrivate::isVariantLessThan(l, r, d->sort_casesensitivity, d->sort_localeaware);
}

/*!
    Returns \c true if the item in the row indicated by the given \a source_row
    and \a source_parent should be included in the model; otherwise returns
    false.

    The default implementation returns \c true if the value held by the relevant item
    matches the filter string, wildcard string or regular expression.

    \note By default, the Qt::DisplayRole is used to determine if the row
    should be accepted or not. This can be changed by setting the
    \l{QSortFilterProxyModel::filterRole}{filterRole} property.

    \sa filterAcceptsColumn(), setFilterFixedString(), setFilterRegularExpression(), setFilterWildcard()
*/
bool QSortFilterProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    Q_D(const QSortFilterProxyModel);

    if (d->filter_regularexpression.value().pattern().isEmpty())
        return true;

    int column_count = d->model->columnCount(source_parent);
    if (d->filter_column == -1) {
        for (int column = 0; column < column_count; ++column) {
            QModelIndex source_index = d->model->index(source_row, column, source_parent);
            QString key = d->model->data(source_index, d->filter_role).toString();
            if (key.contains(d->filter_regularexpression.value()))
                return true;
        }
        return false;
    }

    if (d->filter_column >= column_count) // the column may not exist
        return true;
    QModelIndex source_index = d->model->index(source_row, d->filter_column, source_parent);
    QString key = d->model->data(source_index, d->filter_role).toString();
    return key.contains(d->filter_regularexpression.value());
}

/*!
    Returns \c true if the item in the column indicated by the given \a source_column
    and \a source_parent should be included in the model; otherwise returns \c false.

    \note The default implementation always returns \c true. You must reimplement this
    method to get the described behavior.

    \sa filterAcceptsRow(), setFilterFixedString(), setFilterRegularExpression(), setFilterWildcard()
*/
bool QSortFilterProxyModel::filterAcceptsColumn(int source_column, const QModelIndex &source_parent) const
{
    Q_UNUSED(source_column);
    Q_UNUSED(source_parent);
    return true;
}

/*!
   Returns the source model index corresponding to the given \a
   proxyIndex from the sorting filter model.

   \sa mapFromSource()
*/
QModelIndex QSortFilterProxyModel::mapToSource(const QModelIndex &proxyIndex) const
{
    Q_D(const QSortFilterProxyModel);
    return d->proxy_to_source(proxyIndex);
}

/*!
    Returns the model index in the QSortFilterProxyModel given the \a
    sourceIndex from the source model.

    \sa mapToSource()
*/
QModelIndex QSortFilterProxyModel::mapFromSource(const QModelIndex &sourceIndex) const
{
    Q_D(const QSortFilterProxyModel);
    return d->source_to_proxy(sourceIndex);
}

/*!
  \reimp
*/
QItemSelection QSortFilterProxyModel::mapSelectionToSource(const QItemSelection &proxySelection) const
{
    return QAbstractProxyModel::mapSelectionToSource(proxySelection);
}

/*!
  \reimp
*/
QItemSelection QSortFilterProxyModel::mapSelectionFromSource(const QItemSelection &sourceSelection) const
{
    return QAbstractProxyModel::mapSelectionFromSource(sourceSelection);
}

QT_END_NAMESPACE

#include "moc_qsortfilterproxymodel.cpp"
