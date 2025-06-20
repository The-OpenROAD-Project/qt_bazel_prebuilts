// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qapplication.h"
#include "qdebug.h"
#include "qformlayout.h"
#include "qlabel.h"
#include "qlayout_p.h"
#include "qlayoutengine_p.h"
#include "qlist.h"
#include "qrect.h"
#include "qwidget.h"

QT_BEGIN_NAMESPACE

namespace QtPrivate {
// Fixed column matrix, stores items as [i11, i12, i21, i22...],
// with FORTRAN-style index operator(r, c).
template <class T, int NumColumns>
class FixedColumnMatrix {
public:
    typedef QList<T> Storage;

    FixedColumnMatrix() { }

    void clear() { m_storage.clear(); }

    const T &operator()(int r, int c) const { return m_storage[r * NumColumns + c]; }
    T &operator()(int r, int c) { return m_storage[r * NumColumns + c]; }

    int rowCount() const { return m_storage.size() / NumColumns; }
    void insertRow(int r, const T &value);
    void removeRow(int r);

    // Hmmpf.. Some things are faster that way.
    const Storage &storage() const { return m_storage; }

    static void storageIndexToPosition(int idx, int *rowPtr, int *colPtr);

private:
    Storage m_storage;
};

template <class T, int NumColumns>
void FixedColumnMatrix<T, NumColumns>::insertRow(int r, const T &value)
{
    typename Storage::iterator it = m_storage.begin();
    it += r * NumColumns;
    m_storage.insert(it, NumColumns, value);
}

template <class T, int NumColumns>
void FixedColumnMatrix<T, NumColumns>::removeRow(int r)
{
    m_storage.remove(r * NumColumns, NumColumns);
}

template <class T, int NumColumns>
void FixedColumnMatrix<T, NumColumns>::storageIndexToPosition(int idx, int *rowPtr, int *colPtr)
{
    *rowPtr = idx / NumColumns;
    *colPtr = idx % NumColumns;
}
} // namespace

// special values for unset fields; must not clash with values of FieldGrowthPolicy or
// RowWrapPolicy
const uint DefaultFieldGrowthPolicy = 255;
const uint DefaultRowWrapPolicy = 255;

// -- our data structure for our items
// This owns the QLayoutItem
struct QFormLayoutItem
{
    QFormLayoutItem(QLayoutItem* i) : item(i) { }
    ~QFormLayoutItem() { delete item; }

    // Wrappers
    QWidget *widget() const { return item->widget(); }
    QLayout *layout() const { return item->layout(); }

    bool hasHeightForWidth() const { return item->hasHeightForWidth(); }
    int heightForWidth(int width) const { return item->heightForWidth(width); }
    int minimumHeightForWidth(int width) const { return item->minimumHeightForWidth(width); }
    Qt::Orientations expandingDirections() const { return item->expandingDirections(); }
    QSizePolicy::ControlTypes controlTypes() const { return item->controlTypes(); }
    int vStretch() const { return widget() ? widget()->sizePolicy().verticalStretch() : 0; }

    void setGeometry(const QRect& r) { item->setGeometry(r); }
    QRect geometry() const { return item->geometry(); }

    void setVisible(bool on);
    bool isHidden() const { return !isVisible || (widget() && widget()->isHidden()); }

    // For use with FixedColumnMatrix
    bool operator==(const QFormLayoutItem& other) { return item == other.item; }

    QLayoutItem *item = nullptr;
    bool fullRow = false;
    bool isVisible = true;

    // set by updateSizes
    bool isHfw = false;
    QSize minSize;
    QSize sizeHint;
    QSize maxSize;

    // also set by updateSizes
    int sbsHSpace = -1; // only used for side by side, for the field item only (not label)
    int vSpace = -1; // This is the spacing to the item in the row above

    // set by setupVerticalLayoutData
    bool sideBySide = false;
    int vLayoutIndex = -1;

    // set by setupHorizontalLayoutData
    int layoutPos = -1;
    int layoutWidth = -1;
};

static void hideOrShowWidgetsInLayout(QLayout *layout, bool on)
{
    for (int i = 0; i < layout->count(); ++i) {
        QLayoutItem *item = layout->itemAt(i);
        if (QWidget *widget = item->widget())
            widget->setVisible(on);
        else if (item->layout())
            hideOrShowWidgetsInLayout(item->layout(), on);
    }
}

void QFormLayoutItem::setVisible(bool on)
{
    isVisible = on;
    // Explicitly hide the widget so that it loses focus and
    // doesn't automatically get shown again when this layout
    // hides and shows.
    if (widget()) {
        widget()->setVisible(on);
        return;
    }
    // Layouts can't be hidden, so we have to traverse the widgets
    // inside and hide all of them so that they also lose focus.
    if (layout())
        hideOrShowWidgetsInLayout(layout(), on);
}

class QFormLayoutPrivate : public QLayoutPrivate
{
    Q_DECLARE_PUBLIC(QFormLayout)

public:
    using ItemMatrix = QtPrivate::FixedColumnMatrix<QFormLayoutItem *, 2>;

    QFormLayoutPrivate();
    ~QFormLayoutPrivate() { }

    int insertRow(int row);
    void insertRows(int row, int count);
    void removeRow(int row);
    bool setItem(int row, QFormLayout::ItemRole role, QLayoutItem *item);
    void setLayout(int row, QFormLayout::ItemRole role, QLayout *layout);
    void setWidget(int row, QFormLayout::ItemRole role, QWidget *widget);

    void arrangeWidgets(const QList<QLayoutStruct> &layouts, QRect &rect);

    void updateSizes();

    void setupVerticalLayoutData(int width);
    void setupHorizontalLayoutData(int width);

    QStyle* getStyle() const;

    inline bool haveHfwCached(int width) const
    {
        return (hfw_width == width) || (width == sh_width && hfw_sh_height >= 0);
    }

    void recalcHFW(int w);
    void setupHfwLayoutData();

    uint fieldGrowthPolicy : 8;
    uint rowWrapPolicy : 8;
    uint has_hfw : 2;
    uint dirty : 2; // have we laid out yet?
    uint sizesDirty : 2; // have we (not) gathered layout item sizes?
    uint expandVertical : 1; // Do we expand vertically?
    uint expandHorizontal : 1; // Do we expand horizonally?
    Qt::Alignment labelAlignment;
    Qt::Alignment formAlignment;

    ItemMatrix m_matrix;
    QList<QFormLayoutItem *> m_things;

    int layoutWidth = -1;    // the last width that we called setupVerticalLayoutData on (for vLayouts)

    int hfw_width = -1;  // the last width we calculated HFW for
    int hfw_height = -1; // what that height was

    int hfw_sh_height = -1;  // the hfw for sh_width
    int hfw_sh_minheight = -1; // the minhfw for sh_width

    int min_width = -1;  // the width that gets turned into minSize (from updateSizes)
    int sh_width = -1;   // the width that gets turned into prefSize (from updateSizes)
    int thresh_width = QLAYOUTSIZE_MAX; // the width that we start splitting label/field pairs at (from updateSizes)
    QSize minSize;
    QSize prefSize;
    int formMaxWidth;
    void calcSizeHints();

    QList<QLayoutStruct> vLayouts; // set by setupVerticalLayoutData;
    int vLayoutCount;               // Number of rows we calculated in setupVerticalLayoutData
    int maxLabelWidth;              // the label width we calculated in setupVerticalLayoutData

    QList<QLayoutStruct> hfwLayouts;

    int hSpacing = -1;
    int vSpacing = -1;
    QLayoutItem* replaceAt(int index, QLayoutItem*) override;
};

QFormLayoutPrivate::QFormLayoutPrivate()
    : fieldGrowthPolicy(DefaultFieldGrowthPolicy),
      rowWrapPolicy(DefaultRowWrapPolicy), has_hfw(false), dirty(true), sizesDirty(true),
      expandVertical(0), expandHorizontal(0)
{
}

static Qt::Alignment fixedAlignment(Qt::Alignment alignment, Qt::LayoutDirection layoutDirection)
{
    if (layoutDirection == Qt::RightToLeft && alignment & Qt::AlignAbsolute) {
        // swap left and right, and eliminate absolute flag
        return Qt::Alignment((alignment & ~(Qt::AlignLeft | Qt::AlignRight | Qt::AlignAbsolute))
                             | ((alignment & Qt::AlignRight) ? Qt::AlignLeft : 0)
                             | ((alignment & Qt::AlignLeft) ? Qt::AlignRight : 0));
    } else {
        return alignment & ~Qt::AlignAbsolute;
    }
}

static int storageIndexFromLayoutItem(const QFormLayoutPrivate::ItemMatrix &m,
                                      QFormLayoutItem *item)
{
    if (item) {
        return m.storage().indexOf(item);
    } else {
        return -1;
    }
}

static void updateFormLayoutItem(QFormLayoutItem *item, int userVSpacing,
                                        QFormLayout::FieldGrowthPolicy fieldGrowthPolicy,
                                        bool fullRow)
{
    item->minSize = item->item->minimumSize();
    item->sizeHint = item->item->sizeHint();
    item->maxSize = item->item->maximumSize();

    if (!fullRow && (fieldGrowthPolicy == QFormLayout::FieldsStayAtSizeHint
                     || (fieldGrowthPolicy == QFormLayout::ExpandingFieldsGrow
                         && !(item->item->expandingDirections() & Qt::Horizontal))))
        item->maxSize.setWidth(item->sizeHint.width());

    item->isHfw = item->item->hasHeightForWidth();
    item->vSpace = userVSpacing;
}

/*
   Iterate over all the controls and gather their size information
   (min, sizeHint and max). Also work out what the spacing between
   pairs of controls should be, and figure out the min and sizeHint
   widths.
*/
void QFormLayoutPrivate::updateSizes()
{
    Q_Q(QFormLayout);

    if (sizesDirty) {
        QFormLayout::RowWrapPolicy wrapPolicy = q->rowWrapPolicy();
        bool wrapAllRows = (wrapPolicy == QFormLayout::WrapAllRows);
        bool dontWrapRows = (wrapPolicy == QFormLayout::DontWrapRows);
        int rr = m_matrix.rowCount();

        has_hfw = false;

        // If any control can expand, so can this layout
        // Wrapping doesn't affect expansion, though, just the minsize
        bool expandH = false;
        bool expandV = false;

        QFormLayoutItem *prevLbl = nullptr;
        QFormLayoutItem *prevFld = nullptr;

        QWidget *parent = q->parentWidget();
        QStyle *style = parent ? parent->style() : nullptr;

        int userVSpacing = q->verticalSpacing();
        int userHSpacing = wrapAllRows ? 0 : q->horizontalSpacing();

        int maxMinLblWidth = 0;
        int maxMinFldWidth = 0; // field with label
        int maxMinIfldWidth = 0; // independent field

        int maxShLblWidth = 0;
        int maxShFldWidth = 0;
        int maxShIfldWidth = 0;

        for (int i = 0; i < rr; ++i) {
            QFormLayoutItem *label = m_matrix(i, 0);
            QFormLayoutItem *field = m_matrix(i, 1);

            // Skip empty rows
            if (!label && !field)
                continue;

            if (label) {
                updateFormLayoutItem(label, userVSpacing, q->fieldGrowthPolicy(), false);
                if (label->isHfw)
                    has_hfw = true;
                Qt::Orientations o = label->expandingDirections();

                if (o & Qt::Vertical)
                    expandV = true;
                if (o & Qt::Horizontal)
                    expandH = true;
            }
            if (field) {
                updateFormLayoutItem(field, userVSpacing, q->fieldGrowthPolicy(), !label && field->fullRow);
                field->sbsHSpace = (!label && field->fullRow) ? 0 : userHSpacing;
                if (field->isHfw)
                    has_hfw = true;

                Qt::Orientations o = field->expandingDirections();

                if (o & Qt::Vertical)
                    expandV = true;
                if (o & Qt::Horizontal)
                    expandH = true;
            }

            // See if we need to calculate default spacings
            if ((userHSpacing < 0 || userVSpacing < 0) && style) {
                QSizePolicy::ControlTypes lbltypes =
                    QSizePolicy::ControlTypes(label ? label->controlTypes() : QSizePolicy::DefaultType);
                QSizePolicy::ControlTypes fldtypes =
                    QSizePolicy::ControlTypes(field ? field->controlTypes() : QSizePolicy::DefaultType);

                // VSpacing
                if (userVSpacing < 0) {
                    if (wrapAllRows) {
                        // label spacing is to a previous item
                        QFormLayoutItem *lbltop = prevFld ? prevFld : prevLbl;
                        // field spacing is to the label (or a previous item)
                        QFormLayoutItem *fldtop = label ? label : lbltop;
                        QSizePolicy::ControlTypes lbltoptypes =
                            QSizePolicy::ControlTypes(lbltop ? lbltop->controlTypes() : QSizePolicy::DefaultType);
                        QSizePolicy::ControlTypes fldtoptypes =
                            QSizePolicy::ControlTypes(fldtop ? fldtop->controlTypes() : QSizePolicy::DefaultType);
                        if (label && lbltop)
                            label->vSpace = style->combinedLayoutSpacing(lbltoptypes, lbltypes, Qt::Vertical, nullptr, parent);
                        if (field && fldtop)
                            field->vSpace = style->combinedLayoutSpacing(fldtoptypes, fldtypes, Qt::Vertical, nullptr, parent);
                    } else {
                        // Side by side..  we have to also consider the spacings to empty cells, which can strangely be more than
                        // non empty cells..
                        QFormLayoutItem *lbltop = prevLbl ? prevLbl : prevFld;
                        QFormLayoutItem *fldtop = prevFld;
                        QSizePolicy::ControlTypes lbltoptypes =
                            QSizePolicy::ControlTypes(lbltop ? lbltop->controlTypes() : QSizePolicy::DefaultType);
                        QSizePolicy::ControlTypes fldtoptypes =
                            QSizePolicy::ControlTypes(fldtop ? fldtop->controlTypes() : QSizePolicy::DefaultType);

                        // To be compatible to QGridLayout, we have to compare solitary labels & fields with both predecessors
                        if (label && !label->isHidden()) {
                            if (!field) {
                                int lblspacing = style->combinedLayoutSpacing(lbltoptypes, lbltypes, Qt::Vertical, nullptr, parent);
                                int fldspacing = style->combinedLayoutSpacing(fldtoptypes, lbltypes, Qt::Vertical, nullptr, parent);
                                label->vSpace = qMax(lblspacing, fldspacing);
                            } else {
                                label->vSpace = style->combinedLayoutSpacing(lbltoptypes, lbltypes, Qt::Vertical, nullptr, parent);
                            }
                        }

                        if (field && !field->isHidden()) {
                            // check spacing against both the previous label and field
                            if (!label) {
                                int lblspacing = style->combinedLayoutSpacing(lbltoptypes, fldtypes, Qt::Vertical, nullptr, parent);
                                int fldspacing = style->combinedLayoutSpacing(fldtoptypes, fldtypes, Qt::Vertical, nullptr, parent);
                                field->vSpace = qMax(lblspacing, fldspacing);
                            } else {
                                field->vSpace = style->combinedLayoutSpacing(fldtoptypes, fldtypes, Qt::Vertical, nullptr, parent);
                            }
                        }
                    }
                }

                // HSpacing
                // hard-coded the left and right control types so that all the rows have the same
                // inter-column spacing (otherwise the right column isn't always left aligned)
                if (userHSpacing < 0 && !wrapAllRows && (label || !field->fullRow) && field)
                    field->sbsHSpace = style->combinedLayoutSpacing(QSizePolicy::Label, QSizePolicy::LineEdit, Qt::Horizontal, nullptr, parent);
            }

            // Now update our min/sizehint widths
            // We choose to put the spacing in the field side in sbs, so
            // the right edge of the labels will align, but fields may
            // be a little ragged.. since different controls may have
            // different appearances, a slight raggedness in the left
            // edges of fields can be tolerated.
            // (Note - field->sbsHSpace is 0 for WrapAllRows mode)
            if (label) {
                maxMinLblWidth = qMax(maxMinLblWidth, label->minSize.width());
                maxShLblWidth = qMax(maxShLblWidth, label->sizeHint.width());
            }
            if (field) {
                if (field->fullRow) {
                    maxMinIfldWidth = qMax(maxMinIfldWidth, field->minSize.width());
                    maxShIfldWidth = qMax(maxShIfldWidth, field->sizeHint.width());
                } else {
                    maxMinFldWidth = qMax(maxMinFldWidth, field->minSize.width() + field->sbsHSpace);
                    maxShFldWidth = qMax(maxShFldWidth, field->sizeHint.width() + field->sbsHSpace);
                }
            }

            prevLbl = label;
            prevFld = field;
        }

        // Now, finally update the min/sizeHint widths
        if (wrapAllRows) {
            sh_width = qMax(maxShLblWidth, qMax(maxShIfldWidth, maxShFldWidth));
            min_width = qMax(maxMinLblWidth, qMax(maxMinIfldWidth, maxMinFldWidth));
            // in two line, we don't care as much about the threshold width
            thresh_width = 0;
        } else if (dontWrapRows) {
            // This is just the max widths glommed together
            sh_width = qMax(maxShLblWidth + maxShFldWidth, maxShIfldWidth);
            min_width = qMax(maxMinLblWidth + maxMinFldWidth, maxMinIfldWidth);
            thresh_width = QWIDGETSIZE_MAX;
        } else {
            // This is just the max widths glommed together
            sh_width = qMax(maxShLblWidth + maxShFldWidth, maxShIfldWidth);
            // min width needs to be the min when everything is wrapped,
            // otherwise we'll never get set with a width that causes wrapping
            min_width = qMax(maxMinLblWidth, qMax(maxMinIfldWidth, maxMinFldWidth));
            // We split a pair at label sh + field min (### for now..)
            thresh_width = maxShLblWidth + maxMinFldWidth;
        }

        // Update the expansions
        expandVertical = expandV;
        expandHorizontal = expandH;
    }
    sizesDirty = false;
}

void QFormLayoutPrivate::recalcHFW(int w)
{
    setupHfwLayoutData();

    int h = 0;
    int mh = 0;

    for (int r = 0; r < vLayoutCount; ++r) {
        int spacing = hfwLayouts.at(r).spacing;
        h += hfwLayouts.at(r).sizeHint + spacing;
        mh += hfwLayouts.at(r).minimumSize + spacing;
    }

    if (sh_width > 0 && sh_width == w) {
        hfw_sh_height = qMin(QLAYOUTSIZE_MAX, h);
        hfw_sh_minheight = qMin(QLAYOUTSIZE_MAX, mh);
    } else {
        hfw_width = w;
        hfw_height = qMin(QLAYOUTSIZE_MAX, h);
    }
}

void QFormLayoutPrivate::setupHfwLayoutData()
{
    Q_Q(QFormLayout);
    // setupVerticalLayoutData must be called before this
    // setupHorizontalLayoutData must also be called before this
    // copies non hfw data into hfw
    // then updates size and min


    // Note: QGridLayout doesn't call minimumHeightForWidth,
    // but instead uses heightForWidth for both min and sizeHint.
    // For the common case where minimumHeightForWidth just calls
    // heightForWidth, we do the calculation twice, which can be
    // very expensive for word wrapped QLabels/QTextEdits, for example.
    // So we just use heightForWidth as well.
    int i;
    int rr = m_matrix.rowCount();

    hfwLayouts.clear();
    hfwLayouts.resize(vLayoutCount);
    for (i = 0; i < vLayoutCount; ++i)
        hfwLayouts[i] = vLayouts.at(i);

    for (i = 0; i < rr; ++i) {
        QFormLayoutItem *label = m_matrix(i, 0);
        QFormLayoutItem *field = m_matrix(i, 1);

        // ignore rows with only hidden items
        if (!q->isRowVisible(i))
            continue;

        if (label && label->vLayoutIndex > -1) {
            if (label->isHfw) {
                // We don't check sideBySide here, since a label is only
                // ever side by side with its field
                int hfw = label->heightForWidth(label->layoutWidth);
                hfwLayouts[label->vLayoutIndex].minimumSize = hfw;
                hfwLayouts[label->vLayoutIndex].sizeHint = hfw;
            } else {
                // Reset these here, so the field can do a qMax below (the previous value may have
                // been the fields non-hfw values, which are often larger than hfw)
                hfwLayouts[label->vLayoutIndex].sizeHint = label->sizeHint.height();
                hfwLayouts[label->vLayoutIndex].minimumSize = label->minSize.height();
            }
        }

        if (field && field->vLayoutIndex > -1) {
            int hfw = field->isHfw ? field->heightForWidth(field->layoutWidth) : 0;
            int h = field->isHfw ? hfw : field->sizeHint.height();
            int mh = field->isHfw ? hfw : field->minSize.height();

            if (field->sideBySide) {
                int oh = hfwLayouts.at(field->vLayoutIndex).sizeHint;
                int omh = hfwLayouts.at(field->vLayoutIndex).minimumSize;

                hfwLayouts[field->vLayoutIndex].sizeHint = qMax(h, oh);
                hfwLayouts[field->vLayoutIndex].minimumSize = qMax(mh, omh);
            } else {
                hfwLayouts[field->vLayoutIndex].sizeHint = h;
                hfwLayouts[field->vLayoutIndex].minimumSize = mh;
            }
        }
    }
}

/*
  Given up to four items involved in a vertical spacing calculation
  (two rows * two columns), return the max vertical spacing for the
  row containing item1 (which may also include item2)
  We assume parent and item1 are not null.

  If a particular row is split, then the spacings for that row and
  the following row are affected, and this function should be
  called with recalculate = true for both rows (note: only rows with both
  a label and a field can be split).

  In particular:

  1) the split label's row vspace needs to be changed to qMax(label/prevLabel, label/prevField)
    [call with item1 = label, item2 = null, prevItem1 & prevItem2 as before]
  2) the split field's row vspace needs to be changed to the label/field spacing
    [call with item1 = field, item2 = null, prevItem1 = label, prevItem2 = null]

 [if the next row has one item, 'item']
  3a) the following row's vspace needs to be changed to item/field spacing (would
      previously been the qMax(item/label, item/field) spacings)
    [call with item1 = item, item2 = null, prevItem1 = field, prevItem2 = null]

  [if the next row has two items, 'label2' and 'field2']
  3b) the following row's vspace needs to be changed to be qMax(field/label2, field/field2) spacing
    [call with item1 = label2, item2 = field2, prevItem1 = field, prevItem2 = null]

  In the (common) non split case, we can just use the precalculated vspace (possibly qMaxed between
  label and field).

  If recalculate is true, we expect:
  -  parent != null
  -  item1 != null
  -  item2 can be null
  -  prevItem1 can be null
  -  if item2 is not null, prevItem2 will be null (e.g. steps 1 or 3 above)
  -  if prevItem1 is null, prevItem2 will be null
*/
static inline int spacingHelper(QWidget* parent, QStyle *style, int userVSpacing, bool recalculate, QFormLayoutItem* item1, QFormLayoutItem* item2, QFormLayoutItem* prevItem1, QFormLayoutItem *prevItem2)
{
    int spacing = userVSpacing;
    if (spacing < 0) {
        if (!recalculate) {
            if (item1)
                spacing = item1->vSpace;
            if (item2)
                spacing = qMax(spacing, item2->vSpace);
        } else {
            if (style && prevItem1) {
                QSizePolicy::ControlTypes itemtypes =
                    QSizePolicy::ControlTypes(item1 ? item1->controlTypes() : QSizePolicy::DefaultType);
                int spacing2 = 0;

                spacing = style->combinedLayoutSpacing(itemtypes, prevItem1->controlTypes(), Qt::Vertical, nullptr, parent);

                // At most of one of item2 and prevItem2 will be nonnull
                if (item2)
                    spacing2 = style->combinedLayoutSpacing(item2->controlTypes(), prevItem1->controlTypes(), Qt::Vertical, nullptr, parent);
                else if (prevItem2)
                    spacing2 = style->combinedLayoutSpacing(itemtypes, prevItem2->controlTypes(), Qt::Vertical, nullptr, parent);

                spacing = qMax(spacing, spacing2);
            }
        }
    } else {
        if (prevItem1) {
            QWidget *wid = prevItem1->item->widget();
            if (wid)
                spacing = qMax(spacing, prevItem1->geometry().top() - wid->geometry().top() );
        }
        if (prevItem2) {
            QWidget *wid = prevItem2->item->widget();
            if (wid)
                spacing = qMax(spacing, prevItem2->geometry().top() - wid->geometry().top() );
        }
    }
    return qMax(spacing, 0);
}

static inline void initLayoutStruct(QLayoutStruct& sl, QFormLayoutItem* item)
{
    sl.init(item->vStretch(), item->minSize.height());
    sl.sizeHint = item->sizeHint.height();
    sl.maximumSize = item->maxSize.height();
    sl.expansive = (item->expandingDirections() & Qt::Vertical);
    sl.empty = false;
}

void QFormLayoutPrivate::setupVerticalLayoutData(int width)
{
    Q_Q(QFormLayout);

    // Early out if we have no changes that would cause a change in vertical layout
    if ((width == layoutWidth || (width >= thresh_width && layoutWidth >= thresh_width)) && !dirty && !sizesDirty)
        return;

    layoutWidth = width;

    int rr = m_matrix.rowCount();
    int vidx = 1;
    QFormLayout::RowWrapPolicy rowWrapPolicy = q->rowWrapPolicy();
    bool wrapAllRows = (rowWrapPolicy == QFormLayout::WrapAllRows);
    bool addTopBottomStretch = true;

    vLayouts.clear();
    vLayouts.resize((2 * rr) + 2); // a max, some may be unused

    QStyle *style = nullptr;

    int userVSpacing = q->verticalSpacing();

    if (userVSpacing < 0) {
        if (QWidget *widget = q->parentWidget())
            style = widget->style();
    }

    // make sure our sizes are up to date
    updateSizes();

    // Grab the widest label width here
    // This might be different from the value computed during
    // sizeHint/minSize, since we don't count label/field pairs that
    // are split.
    maxLabelWidth = 0;
    if (!wrapAllRows) {
        for (int i = 0; i < rr; ++i) {
            const QFormLayoutItem *label = m_matrix(i, 0);
            const QFormLayoutItem *field = m_matrix(i, 1);
            if (label && (label->sizeHint.width() + (field ? field->minSize.width() : 0) <= width))
                maxLabelWidth = qMax(maxLabelWidth, label->sizeHint.width());
        }
    } else {
        maxLabelWidth = width;
    }

    QFormLayoutItem *prevItem1 = nullptr;
    QFormLayoutItem *prevItem2 = nullptr;
    bool prevRowSplit = false;

    for (int i = 0; i < rr; ++i) {
        QFormLayoutItem *label = m_matrix(i, 0);
        QFormLayoutItem *field = m_matrix(i, 1);

        // Ignore empty rows or rows with only hidden items,
        // and invalidate their position in the layout.
        if (!q->isRowVisible(i)) {
            if (label)
                label->vLayoutIndex = -1;
            if (field)
                field->vLayoutIndex = -1;
            continue;
        }

        QSize min1;
        QSize min2;
        QSize sh1;
        QSize sh2;
        if (label) {
            min1 = label->minSize;
            sh1 = label->sizeHint;
        }
        if (field) {
            min2 = field->minSize;
            sh2 = field->sizeHint;
        }

        // In separate lines, we make a vLayout for everything that isn't null
        // in side by side, we only separate label/field if we're going to wrap it
        bool splitSideBySide = (rowWrapPolicy == QFormLayout::WrapLongRows)
                                && ((maxLabelWidth < sh1.width()) || (width < (maxLabelWidth + min2.width())));

        if (wrapAllRows || splitSideBySide) {
            if (label) {
                initLayoutStruct(vLayouts[vidx], label);

                if (vidx > 1)
                    vLayouts[vidx - 1].spacing = spacingHelper(q->parentWidget(), style, userVSpacing, splitSideBySide || prevRowSplit, label, nullptr, prevItem1, prevItem2);

                label->vLayoutIndex = vidx;
                label->sideBySide = false;

                prevItem1 = label;
                prevItem2 = nullptr;

                if (vLayouts[vidx].stretch > 0)
                    addTopBottomStretch = false;

                ++vidx;
            }

            if (field) {
                initLayoutStruct(vLayouts[vidx], field);

                if (vidx > 1)
                    vLayouts[vidx - 1].spacing = spacingHelper(q->parentWidget(), style, userVSpacing, splitSideBySide || prevRowSplit, field, nullptr, prevItem1, prevItem2);

                field->vLayoutIndex = vidx;
                field->sideBySide = false;

                prevItem1 = field;
                prevItem2 = nullptr;

                if (vLayouts[vidx].stretch > 0)
                    addTopBottomStretch = false;

                ++vidx;
            }

            prevRowSplit = splitSideBySide;
        } else {
            // we're in side by side mode, and we have enough space to do that
            QSize max1(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
            QSize max2(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);

            int stretch1 = 0;
            int stretch2 = 0;
            bool expanding = false;

            if (label) {
                max1 = label->maxSize;
                if (label->expandingDirections() & Qt::Vertical)
                    expanding = true;

                label->sideBySide = (field != nullptr);
                label->vLayoutIndex = vidx;
                stretch1 = label->vStretch();
            }

            if (field) {
                max2 = field->maxSize;
                if (field->expandingDirections() & Qt::Vertical)
                    expanding = true;

                field->sideBySide = (label || !field->fullRow);
                field->vLayoutIndex = vidx;
                stretch2 = field->vStretch();
            }

            vLayouts[vidx].init(qMax(stretch1, stretch2), qMax(min1.height(), min2.height()));
            vLayouts[vidx].sizeHint = qMax(sh1.height(), sh2.height());
            vLayouts[vidx].maximumSize = qMin(max1.height(), max2.height());
            vLayouts[vidx].expansive = expanding || (vLayouts[vidx].stretch > 0);
            vLayouts[vidx].empty = false;

            if (vLayouts[vidx].expansive)
                addTopBottomStretch = false;

            if (vidx > 1)
                vLayouts[vidx - 1].spacing = spacingHelper(q->parentWidget(), style, userVSpacing, prevRowSplit, label, field, prevItem1, prevItem2);

            if (label) {
                prevItem1 = label;
                prevItem2 = field;
            } else {
                prevItem1 = field;
                prevItem2 = nullptr;
            }

            prevRowSplit = false;
            ++vidx;
        }
    }

    if (addTopBottomStretch) {
        Qt::Alignment formAlignment = q->formAlignment();

        if (!(formAlignment & Qt::AlignBottom)) {
            // AlignTop (default if unspecified) or AlignVCenter: We add a stretch at the bottom
            vLayouts[vidx].init(1, 0);
            vLayouts[vidx].expansive = true;
            ++vidx;
        }

        if (formAlignment & (Qt::AlignVCenter | Qt::AlignBottom)) {
            // AlignVCenter or AlignBottom: We add a stretch at the top
            vLayouts[0].init(1, 0);
            vLayouts[0].expansive = true;
        } else {
            vLayouts[0].init(0, 0);
        }
    } else {
        vLayouts[0].init(0, 0);
    }

    vLayoutCount = vidx;
    dirty = false;
}

void QFormLayoutPrivate::setupHorizontalLayoutData(int width)
{
    Q_Q(QFormLayout);

    // requires setupVerticalLayoutData to be called first

    int fieldMaxWidth = 0;

    int rr = m_matrix.rowCount();
    bool wrapAllRows = (q->rowWrapPolicy() == QFormLayout::WrapAllRows);

    for (int i = 0; i < rr; ++i) {
        QFormLayoutItem *label = m_matrix(i, 0);
        QFormLayoutItem *field = m_matrix(i, 1);

        // Totally ignore empty rows...
        if (!label && !field)
            continue;

        if (label) {
            // if there is a field, and we're side by side, we use maxLabelWidth
            // otherwise we just use the sizehint
            label->layoutWidth = (field && label->sideBySide) ? maxLabelWidth : label->sizeHint.width();
            label->layoutPos = 0;
        }

        if (field) {
            // This is the default amount allotted to fields in sbs
            int fldwidth = width - maxLabelWidth - field->sbsHSpace;

            // If we've split a row, we still decide to align
            // the field with all the other field if it will fit
            // Fields in sbs mode get the remnants of the maxLabelWidth
            if (!field->sideBySide) {
                if (wrapAllRows || (!label && field->fullRow) || field->sizeHint.width() > fldwidth) {
                    field->layoutWidth = width;
                    field->layoutPos = 0;
                } else {
                    field->layoutWidth = fldwidth;
                    field->layoutPos = width - fldwidth;
                }
            } else {
                // We're sbs, so we should have a label
                field->layoutWidth = fldwidth;
                field->layoutPos = width - fldwidth;
            }

            fieldMaxWidth = qMax(fieldMaxWidth, field->maxSize.width());
        }
    }

    formMaxWidth = maxLabelWidth + fieldMaxWidth;
}

void QFormLayoutPrivate::calcSizeHints()
{
    Q_Q(QFormLayout);

    int leftMargin, topMargin, rightMargin, bottomMargin;
    q->getContentsMargins(&leftMargin, &topMargin, &rightMargin, &bottomMargin);

    updateSizes();
    setupVerticalLayoutData(QLAYOUTSIZE_MAX);
    // Don't need to call setupHorizontal here

    int h = topMargin + bottomMargin;
    int mh = topMargin + bottomMargin;

    // The following are set in updateSizes
    int w = sh_width + leftMargin + rightMargin;
    int mw = min_width + leftMargin + rightMargin;

    for (int i = 0; i < vLayoutCount; ++i) {
        int spacing = vLayouts.at(i).spacing;
        h += vLayouts.at(i).sizeHint + spacing;
        mh += vLayouts.at(i).minimumSize + spacing;
    }

    minSize.rwidth() = qMin(mw, QLAYOUTSIZE_MAX);
    minSize.rheight() = qMin(mh, QLAYOUTSIZE_MAX);
    prefSize.rwidth() = qMin(w, QLAYOUTSIZE_MAX);
    prefSize.rheight() = qMin(h, QLAYOUTSIZE_MAX);
}

int QFormLayoutPrivate::insertRow(int row)
{
    int rowCnt = m_matrix.rowCount();
    if (uint(row) > uint(rowCnt))
        row = rowCnt;

    insertRows(row, 1);
    return row;
}

void QFormLayoutPrivate::insertRows(int row, int count)
{
    while (count > 0) {
        m_matrix.insertRow(row, 0);
        --count;
    }
}

void QFormLayoutPrivate::removeRow(int row)
{
    if (uint(row) < uint(m_matrix.rowCount()))
        m_matrix.removeRow(row);
}

bool QFormLayoutPrivate::setItem(int row, QFormLayout::ItemRole role, QLayoutItem *item)
{
    const bool fullRow = role == QFormLayout::SpanningRole;
    const int column =  role == QFormLayout::SpanningRole ? 1 : static_cast<int>(role);
    if (Q_UNLIKELY(uint(row) >= uint(m_matrix.rowCount()) || uint(column) > 1U)) {
        qWarning("QFormLayoutPrivate::setItem: Invalid cell (%d, %d)", row, column);
        return false;
    }

    if (!item)
        return false;

    if (Q_UNLIKELY(m_matrix(row, column))) {
        qWarning("QFormLayoutPrivate::setItem: Cell (%d, %d) already occupied", row, column);
        return false;
    }

    QFormLayoutItem *i = new QFormLayoutItem(item);
    i->fullRow = fullRow;
    m_matrix(row, column) = i;

    m_things.append(i);
    return true;
}

void QFormLayoutPrivate::setLayout(int row, QFormLayout::ItemRole role, QLayout *layout)
{
    if (layout) {
        Q_Q(QFormLayout);
        if (q->adoptLayout(layout))
            setItem(row, role, layout);
    }
}

void QFormLayoutPrivate::setWidget(int row, QFormLayout::ItemRole role, QWidget *widget)
{
    if (widget) {
        Q_Q(QFormLayout);
        q->addChildWidget(widget);
        QWidgetItem *item = QLayoutPrivate::createWidgetItem(q, widget);
        if (!setItem(row, role, item))
            delete item;
    }
}

QStyle* QFormLayoutPrivate::getStyle() const
{
    Q_Q(const QFormLayout);

    // ### cache
    if (QWidget *parentWidget = q->parentWidget())
        return parentWidget->style();
    else
        return QApplication::style();
}

QLayoutItem* QFormLayoutPrivate::replaceAt(int index, QLayoutItem *newitem)
{
    Q_Q(QFormLayout);
    if (!newitem)
        return nullptr;
    const int storageIndex = storageIndexFromLayoutItem(m_matrix, m_things.value(index));
    if (Q_UNLIKELY(storageIndex == -1)) {
        // ### Qt6 - fix warning too when this class becomes public
        qWarning("QFormLayoutPrivate::replaceAt: Invalid index %d", index);
        return nullptr;
    }

    int row, col;
    QFormLayoutPrivate::ItemMatrix::storageIndexToPosition(storageIndex, &row, &col);
    Q_ASSERT(m_matrix(row, col));

    QFormLayoutItem *item = m_matrix(row, col);
    Q_ASSERT(item);

    QLayoutItem *olditem = item->item;
    item->item = newitem;

    q->invalidate();
    return olditem;
}

/*!
    \class QFormLayout
    \since 4.4
    \brief The QFormLayout class manages forms of input widgets and their associated labels.

    \ingroup geomanagement
    \inmodule QtWidgets

    QFormLayout is a convenience layout class that lays out its
    children in a two-column form. The left column consists of labels
    and the right column consists of "field" widgets (line editors,
    spin boxes, etc.).

    Traditionally, such two-column form layouts were achieved using
    QGridLayout. QFormLayout is a higher-level alternative that
    provides the following advantages:

    \list
    \li \b{Adherence to the different platform's look and feel guidelines.}

        For example, the
        \l{http://developer.apple.com/library/mac/#documentation/UserExperience/Conceptual/AppleHIGuidelines/Intro/Intro.html}{\macos Aqua} and KDE guidelines specify that the
        labels should be right-aligned, whereas Windows and GNOME
        applications normally use left-alignment.

    \li \b{Support for wrapping long rows.}

       For devices with small displays, QFormLayout can be set to
       \l{WrapLongRows}{wrap long rows}, or even to
       \l{WrapAllRows}{wrap all rows}.

    \li \b{Convenient API for creating label--field pairs.}

       The addRow() overload that takes a QString and a QWidget *
       creates a QLabel behind the scenes and automatically set up
       its buddy. We can then write code like this:

    \snippet code/src_gui_kernel_qformlayout.cpp 0

       Compare this with the following code, written using QGridLayout:

    \snippet code/src_gui_kernel_qformlayout.cpp 1
    \endlist

    The table below shows the default appearance in different styles.

    \table
    \header
        \li QCommonStyle derived styles (except QPlastiqueStyle)
        \li QMacStyle
        \li QPlastiqueStyle
        \li Qt Extended styles
    \row
        \li \inlineimage qformlayout-win.png
        \li \inlineimage qformlayout-mac.png
        \li \inlineimage qformlayout-kde.png
        \li \inlineimage qformlayout-qpe.png
    \row
        \li Traditional style used for Windows, GNOME, and earlier
           versions of KDE. Labels are left aligned, and expanding
           fields grow to fill the available space. (This normally
           corresponds to what we would get using a two-column
           QGridLayout.)
        \li Style based on the
           \l{http://developer.apple.com/library/mac/#documentation/UserExperience/Conceptual/AppleHIGuidelines/Intro/Intro.html}{\macos Aqua} guidelines. Labels are right-aligned,
           the fields don't grow beyond their size hint, and the
           form is horizontally centered.
        \li Recommended style for
           KDE applications. Similar to MacStyle, except that the form
           is left-aligned and all fields grow to fill the available
           space.
        \li Default style for Qt Extended styles. Labels are right-aligned,
           expanding fields grow to fill the available space, and row
           wrapping is enabled for long lines.
    \endtable

    The form styles can be also be overridden individually by calling
    setLabelAlignment(), setFormAlignment(), setFieldGrowthPolicy(),
    and setRowWrapPolicy().  For example, to simulate the form layout
    appearance of QMacStyle on all platforms, but with left-aligned
    labels, you could write:

    \snippet code/src_gui_kernel_qformlayout.cpp 2

    \sa QGridLayout, QBoxLayout, QStackedLayout
*/


/*!
    \enum QFormLayout::FieldGrowthPolicy

    This enum specifies the different policies that can be used to
    control the way in which the form's fields grow.

    \value FieldsStayAtSizeHint
           The fields never grow beyond their
           \l{QWidgetItem::sizeHint()}{effective size hint}. This is
           the default for QMacStyle.

    \value ExpandingFieldsGrow
           Fields with an horizontal \l{QSizePolicy}{size policy} of
           \l{QSizePolicy::}{Expanding} or
           \l{QSizePolicy::}{MinimumExpanding} will grow to fill the
           available space. The other fields will not grow beyond
           their effective size hint. This is the default policy for
           Plastique.

    \value AllNonFixedFieldsGrow
           All fields with a size policy that allows them to grow
           will grow to fill the available space. This is the default
           policy for most styles.

    \sa fieldGrowthPolicy
*/

/*!
    \enum QFormLayout::RowWrapPolicy

    This enum specifies the different policies that can be used to
    control the way in which the form's rows wrap.

    \value DontWrapRows
           Fields are always laid out next to their label.  This is
           the default policy for all styles except Qt Extended styles.

    \value WrapLongRows
           Labels are given enough horizontal space to fit the widest label,
           and the rest of the space is given to the fields. If the minimum
           size of a field pair is wider than the available space, the field
           is wrapped to the next line.  This is the default policy for
           Qt Extended styles.

    \value WrapAllRows
           Fields are always laid out below their label.

    \sa rowWrapPolicy
*/

/*!
    \enum QFormLayout::ItemRole

    This enum specifies the types of widgets (or other layout items)
    that may appear in a row.

    \value LabelRole A label widget.
    \value FieldRole A field widget.
    \value SpanningRole A widget that spans label and field columns.

    \sa itemAt(), getItemPosition()
*/

/*!

    \class QFormLayout::TakeRowResult

    \brief Contains the result of a QFormLayout::takeRow() call.
    \inmodule QtWidgets
    \since 5.8
    \sa QFormLayout::takeRow()
*/

/*!
    \variable QFormLayout::TakeRowResult::labelItem

    Contains the layout item corresponding to the label of the row.
*/

/*!
    \variable QFormLayout::TakeRowResult::fieldItem

    Contains the layout item corresponding to the field of the row.
*/

/*!
    Constructs a new form layout with the given \a parent widget.

    The layout is set directly as the top-level layout for \a parent.
    There can be only one top-level layout for a widget. It is returned
    by QWidget::layout().

    \sa QWidget::setLayout()
*/
QFormLayout::QFormLayout(QWidget *parent)
    : QLayout(*new QFormLayoutPrivate, nullptr, parent)
{
}

/*!
    Destroys the form layout.
*/
QFormLayout::~QFormLayout()
{
    Q_D(QFormLayout);

    /*
        The clearing and destruction order here is important. We start by clearing
        m_things so that QLayout and the rest of the world know that we don't babysit
        the layout items anymore and don't care if they are destroyed.
    */
    d->m_things.clear();
    qDeleteAll(d->m_matrix.storage());
    d->m_matrix.clear();
}

/*!
    Adds a new row to the bottom of this form layout, with the given
    \a label and \a field.

    \sa insertRow()
*/
void QFormLayout::addRow(QWidget *label, QWidget *field)
{
    insertRow(-1, label, field);
}

/*!
    \overload
*/
void QFormLayout::addRow(QWidget *label, QLayout *field)
{
    insertRow(-1, label, field);
}

/*!
    \overload

    This overload automatically creates a QLabel behind the scenes
    with \a labelText as its text. The \a field is set as the new
    QLabel's \l{QLabel::setBuddy()}{buddy}.
*/
void QFormLayout::addRow(const QString &labelText, QWidget *field)
{
    insertRow(-1, labelText, field);
}

/*!
    \overload

    This overload automatically creates a QLabel behind the scenes
    with \a labelText as its text.
*/
void QFormLayout::addRow(const QString &labelText, QLayout *field)
{
    insertRow(-1, labelText, field);
}

/*!
    \overload

    Adds the specified \a widget at the end of this form layout. The
    \a widget spans both columns.
*/
void QFormLayout::addRow(QWidget *widget)
{
    insertRow(-1, widget);
}

/*!
    \overload

    Adds the specified \a layout at the end of this form layout. The
    \a layout spans both columns.
*/
void QFormLayout::addRow(QLayout *layout)
{
    insertRow(-1, layout);
}

/*!
    Inserts a new row at position \a row in this form layout, with
    the given \a label and \a field. If \a row is out of bounds, the
    new row is added at the end.

    \sa addRow()
*/
void QFormLayout::insertRow(int row, QWidget *label, QWidget *field)
{
    Q_D(QFormLayout);
    if ((label && !d->checkWidget(label)) || (field && !d->checkWidget(field)))
        return;

    row = d->insertRow(row);
    if (label)
        d->setWidget(row, LabelRole, label);
    if (field)
        d->setWidget(row, FieldRole, field);
    invalidate();
}

/*!
    \overload
*/
void QFormLayout::insertRow(int row, QWidget *label, QLayout *field)
{
    Q_D(QFormLayout);
    if ((label && !d->checkWidget(label)) || (field && !d->checkLayout(field)))
        return;

    row = d->insertRow(row);
    if (label)
        d->setWidget(row, LabelRole, label);
    if (field)
        d->setLayout(row, FieldRole, field);
    invalidate();
}

/*!
    \overload

    This overload automatically creates a QLabel behind the scenes
    with \a labelText as its text. The \a field is set as the new
    QLabel's \l{QLabel::setBuddy()}{buddy}.
*/
void QFormLayout::insertRow(int row, const QString &labelText, QWidget *field)
{
    Q_D(QFormLayout);
    if (field && !d->checkWidget(field))
        return;

    QLabel *label = nullptr;
    if (!labelText.isEmpty()) {
        label = new QLabel(labelText);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(field);
#endif
    }
    insertRow(row, label, field);
}

/*!
    \overload

    This overload automatically creates a QLabel behind the scenes
    with \a labelText as its text.
*/
void QFormLayout::insertRow(int row, const QString &labelText, QLayout *field)
{
    Q_D(QFormLayout);
    if (field && !d->checkLayout(field))
        return;

    insertRow(row, labelText.isEmpty() ? nullptr : new QLabel(labelText), field);
}

/*!
    \overload

    Inserts the specified \a widget at position \a row in this form
    layout. The \a widget spans both columns. If \a row is out of
    bounds, the widget is added at the end.
*/
void QFormLayout::insertRow(int row, QWidget *widget)
{
    Q_D(QFormLayout);
    if (!d->checkWidget(widget))
        return;

    row = d->insertRow(row);
    d->setWidget(row, SpanningRole, widget);
    invalidate();
}

/*!
    \overload

    Inserts the specified \a layout at position \a row in this form
    layout. The \a layout spans both columns. If \a row is out of
    bounds, the widget is added at the end.
*/
void QFormLayout::insertRow(int row, QLayout *layout)
{
    Q_D(QFormLayout);
    if (!d->checkLayout(layout))
        return;

    row = d->insertRow(row);
    d->setLayout(row, SpanningRole, layout);
    invalidate();
}

static QLayoutItem *ownershipCleanedItem(QFormLayoutItem *item, QFormLayout *layout)
{
    if (!item)
        return nullptr;

    // grab ownership back from the QFormLayoutItem
    QLayoutItem *i = item->item;
    item->item = nullptr;
    delete item;

    if (QLayout *l = i->layout()) {
        // sanity check in case the user passed something weird to QObject::setParent()
        if (l->parent() == layout)
            l->setParent(nullptr);
    }

    return i;
}

static void clearAndDestroyQLayoutItem(QLayoutItem *item)
{
    if (Q_LIKELY(item)) {
        delete item->widget();
        if (QLayout *layout = item->layout()) {
            while (QLayoutItem *child = layout->takeAt(0))
                clearAndDestroyQLayoutItem(child);
        }
        delete item;
    }
}

/*!
    \since 5.8

    Deletes row \a row from this form layout.

    \a row must be non-negative and less than rowCount().

    After this call, rowCount() is decremented by one. All widgets and
    nested layouts that occupied this row are deleted. That includes both
    the field widget(s) and the label, if any. All following rows are shifted
    up one row and the freed vertical space is redistributed amongst the remaining rows.

    You can use this function to undo a previous addRow() or insertRow():
    \snippet code/src_gui_kernel_qformlayout.cpp 3

    If you want to remove the row from the layout without deleting the widgets, use takeRow() instead.

    \sa takeRow()
*/
void QFormLayout::removeRow(int row)
{
    TakeRowResult result = takeRow(row);
    clearAndDestroyQLayoutItem(result.labelItem);
    clearAndDestroyQLayoutItem(result.fieldItem);
}

/*!
    \since 5.8

    \overload

    Deletes the row corresponding to \a widget from this form layout.

    After this call, rowCount() is decremented by one. All widgets and
    nested layouts that occupied this row are deleted. That includes both
    the field widget(s) and the label, if any. All following rows are shifted
    up one row and the freed vertical space is redistributed amongst the remaining rows.

    You can use this function to undo a previous addRow() or insertRow():
    \snippet code/src_gui_kernel_qformlayout.cpp 4

    If you want to remove the row from the layout without deleting the widgets, use takeRow() instead.

    \sa takeRow()
*/
void QFormLayout::removeRow(QWidget *widget)
{
    TakeRowResult result = takeRow(widget);
    clearAndDestroyQLayoutItem(result.labelItem);
    clearAndDestroyQLayoutItem(result.fieldItem);
}

/*!
    \since 5.8

    \overload

    Deletes the row corresponding to \a layout from this form layout.

    After this call, rowCount() is decremented by one. All widgets and
    nested layouts that occupied this row are deleted. That includes both
    the field widget(s) and the label, if any. All following rows are shifted
    up one row and the freed vertical space is redistributed amongst the remaining rows.

    You can use this function to undo a previous addRow() or insertRow():
    \snippet code/src_gui_kernel_qformlayout.cpp 5

    If you want to remove the row from the form layout without deleting the inserted layout,
    use takeRow() instead.

    \sa takeRow()
*/
void QFormLayout::removeRow(QLayout *layout)
{
    TakeRowResult result = takeRow(layout);
    clearAndDestroyQLayoutItem(result.labelItem);
    clearAndDestroyQLayoutItem(result.fieldItem);
}

/*!
    \since 5.8

    Removes the specified \a row from this form layout.

    \a row must be non-negative and less than rowCount().

    \note This function doesn't delete anything.

    After this call, rowCount() is decremented by one. All following rows are shifted
    up one row and the freed vertical space is redistributed amongst the remaining rows.

    You can use this function to undo a previous addRow() or insertRow():
    \snippet code/src_gui_kernel_qformlayout.cpp 6

    If you want to remove the row from the layout and delete the widgets, use removeRow() instead.

    \return A structure containing both the widget and
    corresponding label layout items

    \sa removeRow()
*/
QFormLayout::TakeRowResult QFormLayout::takeRow(int row)
{
    Q_D(QFormLayout);

    if (Q_UNLIKELY(!(uint(row) < uint(d->m_matrix.rowCount())))) {
        qWarning("QFormLayout::takeRow: Invalid row %d", row);
        return TakeRowResult();
    }

    QFormLayoutItem *label = d->m_matrix(row, 0);
    QFormLayoutItem *field = d->m_matrix(row, 1);

    d->m_things.removeOne(label);
    d->m_things.removeOne(field);
    d->m_matrix.removeRow(row);

    invalidate();

    TakeRowResult result;
    result.labelItem = ownershipCleanedItem(label, this);
    result.fieldItem = ownershipCleanedItem(field, this);
    return result;
}

/*!
    \since 5.8

    \overload

    Removes the specified \a widget from this form layout.

    \note This function doesn't delete anything.

    After this call, rowCount() is decremented by one. All following rows are shifted
    up one row and the freed vertical space is redistributed amongst the remaining rows.

    \snippet code/src_gui_kernel_qformlayout.cpp 7

    If you want to remove the row from the layout and delete the widgets, use removeRow() instead.

    \return A structure containing both the widget and
    corresponding label layout items

    \sa removeRow()
*/
QFormLayout::TakeRowResult QFormLayout::takeRow(QWidget *widget)
{
    Q_D(QFormLayout);
    if (Q_UNLIKELY(!d->checkWidget(widget)))
        return TakeRowResult();

    int row;
    ItemRole role;
    getWidgetPosition(widget, &row, &role);

    if (Q_UNLIKELY(row < 0)) {
        qWarning("QFormLayout::takeRow: Invalid widget");
        return TakeRowResult();
    }

    return takeRow(row);
}

/*!
    \since 5.8

    \overload

    Removes the specified \a layout from this form layout.

    \note This function doesn't delete anything.

    After this call, rowCount() is decremented by one. All following rows are shifted
    up one row and the freed vertical space is redistributed amongst the remaining rows.

    \snippet code/src_gui_kernel_qformlayout.cpp 8

    If you want to remove the row from the form layout and delete the inserted layout,
    use removeRow() instead.

    \return A structure containing both the widget and
    corresponding label layout items

    \sa removeRow()
*/
QFormLayout::TakeRowResult QFormLayout::takeRow(QLayout *layout)
{
    Q_D(QFormLayout);
    if (Q_UNLIKELY(!d->checkLayout(layout)))
        return TakeRowResult();

    int row;
    ItemRole role;
    getLayoutPosition(layout, &row, &role);

    if (Q_UNLIKELY(row < 0)) {
        qWarning("QFormLayout::takeRow: Invalid layout");
        return TakeRowResult();
    }

    return takeRow(row);
}

/*!
    \reimp
*/
void QFormLayout::addItem(QLayoutItem *item)
{
    Q_D(QFormLayout);

    int row = d->insertRow(d->m_matrix.rowCount());
    d->setItem(row, FieldRole, item);
    invalidate();
}

/*!
    \reimp
*/
int QFormLayout::count() const
{
    Q_D(const QFormLayout);
    return d->m_things.size();
}

/*!
    \reimp
*/
QLayoutItem *QFormLayout::itemAt(int index) const
{
    Q_D(const QFormLayout);
    if (QFormLayoutItem *formItem = d->m_things.value(index))
        return formItem->item;
    return nullptr;
}

/*!
    \reimp
*/
QLayoutItem *QFormLayout::takeAt(int index)
{
    Q_D(QFormLayout);

    const int storageIndex = storageIndexFromLayoutItem(d->m_matrix, d->m_things.value(index));
    if (Q_UNLIKELY(storageIndex == -1)) {
        qWarning("QFormLayout::takeAt: Invalid index %d", index);
        return nullptr;
    }

    int row, col;
    QFormLayoutPrivate::ItemMatrix::storageIndexToPosition(storageIndex, &row, &col);
    Q_ASSERT(d->m_matrix(row, col));

    QFormLayoutItem *item = d->m_matrix(row, col);
    Q_ASSERT(item);
    d->m_things.removeAt(index);
    d->m_matrix(row, col) = 0;

    invalidate();

    return ownershipCleanedItem(item, this);
}

/*!
    \reimp
*/
Qt::Orientations QFormLayout::expandingDirections() const
{
    Q_D(const QFormLayout);
    QFormLayoutPrivate *e = const_cast<QFormLayoutPrivate *>(d);
    e->updateSizes();

    Qt::Orientations o;
    if (e->expandHorizontal)
        o = Qt::Horizontal;
    if (e->expandVertical)
        o |= Qt::Vertical;
    return o;
}

/*!
    \reimp
*/
bool QFormLayout::hasHeightForWidth() const
{
    Q_D(const QFormLayout);
    QFormLayoutPrivate *e = const_cast<QFormLayoutPrivate *>(d);
    e->updateSizes();
    return (d->has_hfw || rowWrapPolicy() == WrapLongRows);
}

/*!
    \reimp
*/
int QFormLayout::heightForWidth(int width) const
{
    Q_D(const QFormLayout);
    if (!hasHeightForWidth())
        return -1;

    int leftMargin, topMargin, rightMargin, bottomMargin;
    getContentsMargins(&leftMargin, &topMargin, &rightMargin, &bottomMargin);

    int targetWidth = width - leftMargin - rightMargin;

    if (!d->haveHfwCached(targetWidth)) {
        QFormLayoutPrivate *dat = const_cast<QFormLayoutPrivate *>(d);
        dat->setupVerticalLayoutData(targetWidth);
        dat->setupHorizontalLayoutData(targetWidth);
        dat->recalcHFW(targetWidth);
    }
    if (targetWidth == d->sh_width)
        return d->hfw_sh_height + topMargin + bottomMargin;
    else
        return d->hfw_height + topMargin + bottomMargin;
}

/*!
    \reimp
*/
void QFormLayout::setGeometry(const QRect &rect)
{
    Q_D(QFormLayout);
    if (d->dirty || rect != geometry()) {
        QRect cr = rect;
        int leftMargin, topMargin, rightMargin, bottomMargin;
        getContentsMargins(&leftMargin, &topMargin, &rightMargin, &bottomMargin);
        cr.adjust(+leftMargin, +topMargin, -rightMargin, -bottomMargin);

        bool hfw = hasHeightForWidth();
        d->setupVerticalLayoutData(cr.width());
        d->setupHorizontalLayoutData(cr.width());
        if (hfw && (!d->haveHfwCached(cr.width()) || d->hfwLayouts.size() != d->vLayoutCount))
            d->recalcHFW(cr.width());
        if (hfw) {
            qGeomCalc(d->hfwLayouts, 0, d->vLayoutCount, cr.y(), cr.height());
            d->arrangeWidgets(d->hfwLayouts, cr);
        } else {
            qGeomCalc(d->vLayouts, 0, d->vLayoutCount, cr.y(), cr.height());
            d->arrangeWidgets(d->vLayouts, cr);
        }
        QLayout::setGeometry(rect);
    }
}

/*!
    \reimp
*/
QSize QFormLayout::sizeHint() const
{
    Q_D(const QFormLayout);
    if (!d->prefSize.isValid()) {
        QFormLayoutPrivate *dat = const_cast<QFormLayoutPrivate *>(d);
        dat->calcSizeHints();
    }
    return d->prefSize;
}

/*!
    \reimp
*/
QSize QFormLayout::minimumSize() const
{
    // ### fix minimumSize if hfw
    Q_D(const QFormLayout);
    if (!d->minSize.isValid()) {
        QFormLayoutPrivate *dat = const_cast<QFormLayoutPrivate *>(d);
        dat->calcSizeHints();
    }
    return d->minSize;
}

/*!
    \reimp
*/
void QFormLayout::invalidate()
{
    Q_D(QFormLayout);
    d->dirty = true;
    d->sizesDirty = true;
    d->minSize = QSize();
    d->prefSize = QSize();
    d->formMaxWidth = -1;
    d->hfw_width = -1;
    d->sh_width = -1;
    d->layoutWidth = -1;
    d->hfw_sh_height = -1;
    QLayout::invalidate();
}

/*!
    Returns the number of rows in the form.

    \sa QLayout::count()
*/
int QFormLayout::rowCount() const
{
    Q_D(const QFormLayout);
    return d->m_matrix.rowCount();
}

/*!
    Returns the layout item in the given \a row with the specified \a
    role (column). Returns \nullptr if there is no such item.

    \sa QLayout::itemAt(), setItem()
*/
QLayoutItem *QFormLayout::itemAt(int row, ItemRole role) const
{
    Q_D(const QFormLayout);
    if (uint(row) >= uint(d->m_matrix.rowCount()))
        return nullptr;
    switch (role) {
    case SpanningRole:
        if (QFormLayoutItem *item = d->m_matrix(row, 1))
            if (item->fullRow)
                return item->item;
        break;
    case LabelRole:
    case FieldRole:
        if (QFormLayoutItem *item = d->m_matrix(row, (role == LabelRole) ? 0 : 1))
            return item->item;
        break;
    }
    return nullptr;
}

/*!
    Retrieves the row and role (column) of the item at the specified
    \a index. If \a index is out of bounds, *\a rowPtr is set to -1;
    otherwise the row is stored in *\a rowPtr and the role is stored
    in *\a rolePtr.

    \sa itemAt(), count(), getLayoutPosition(), getWidgetPosition()
*/
void QFormLayout::getItemPosition(int index, int *rowPtr, ItemRole *rolePtr) const
{
    Q_D(const QFormLayout);
    int col = -1;
    int row = -1;

    const int storageIndex = storageIndexFromLayoutItem(d->m_matrix, d->m_things.value(index));
    if (storageIndex != -1)
        QFormLayoutPrivate::ItemMatrix::storageIndexToPosition(storageIndex, &row, &col);

    if (rowPtr)
        *rowPtr = row;
    if (rolePtr && row != -1) {
        const bool spanning = col == 1 && d->m_matrix(row, col)->fullRow;
        if (spanning) {
            *rolePtr = SpanningRole;
        } else {
            *rolePtr = ItemRole(col);
        }
    }
}

/*!
    Retrieves the row and role (column) of the specified child \a
    layout. If \a layout is not in the form layout, *\a rowPtr is set
    to -1; otherwise the row is stored in *\a rowPtr and the role is stored
    in *\a rolePtr.
*/
void QFormLayout::getLayoutPosition(QLayout *layout, int *rowPtr, ItemRole *rolePtr) const
{
    int n = count();
    int index = 0;
    while (index < n) {
        if (itemAt(index) == layout)
            break;
        ++index;
    }
    getItemPosition(index, rowPtr, rolePtr);
}

/*!
    Retrieves the row and role (column) of the specified \a widget in
    the layout. If \a widget is not in the layout, *\a rowPtr is set
    to -1; otherwise the row is stored in *\a rowPtr and the role is stored
    in *\a rolePtr.

    \sa getItemPosition(), itemAt()
*/
void QFormLayout::getWidgetPosition(QWidget *widget, int *rowPtr, ItemRole *rolePtr) const
{
    getItemPosition(indexOf(widget), rowPtr, rolePtr);
}

// ### eliminate labelForField()

/*!
    Returns the label associated with the given \a field.

    \sa itemAt()
*/
QWidget *QFormLayout::labelForField(QWidget *field) const
{
    Q_D(const QFormLayout);

    int row;
    ItemRole role = LabelRole;

    getWidgetPosition(field, &row, &role);

    if (row != -1 && role == FieldRole) {
        if (QFormLayoutItem *label = d->m_matrix(row, LabelRole))
            return label->widget();
    }
    return nullptr;
}

/*!
    \overload
*/
QWidget *QFormLayout::labelForField(QLayout *field) const
{
    Q_D(const QFormLayout);

    int row;
    ItemRole role;

    getLayoutPosition(field, &row, &role);

    if (row != -1 && role == FieldRole) {
        if (QFormLayoutItem *label = d->m_matrix(row, LabelRole))
            return label->widget();
    }
    return nullptr;
}

/*!
    \property QFormLayout::fieldGrowthPolicy
    \brief the way in which the form's fields grow

    The default value depends on the widget or application style. For
    QMacStyle, the default is FieldsStayAtSizeHint; for QCommonStyle
    derived styles (like Plastique and Windows), the default
    is ExpandingFieldsGrow; for Qt Extended styles, the default is
    AllNonFixedFieldsGrow.

    If none of the fields can grow and the form is resized, extra
    space is distributed according to the current
    \l{formAlignment}{form alignment}.

    \sa formAlignment, rowWrapPolicy
*/

void QFormLayout::setFieldGrowthPolicy(FieldGrowthPolicy policy)
{
    Q_D(QFormLayout);
    if (FieldGrowthPolicy(d->fieldGrowthPolicy) != policy) {
        d->fieldGrowthPolicy = policy;
        invalidate();
    }
}

QFormLayout::FieldGrowthPolicy QFormLayout::fieldGrowthPolicy() const
{
    Q_D(const QFormLayout);
    if (d->fieldGrowthPolicy == DefaultFieldGrowthPolicy) {
        return QFormLayout::FieldGrowthPolicy(d->getStyle()->styleHint(QStyle::SH_FormLayoutFieldGrowthPolicy));
    } else {
        return QFormLayout::FieldGrowthPolicy(d->fieldGrowthPolicy);
    }
}

/*!
    \property QFormLayout::rowWrapPolicy
    \brief the way in which the form's rows wrap

    The default value depends on the widget or application style. For
    Qt Extended styles, the default is WrapLongRows;
    for the other styles, the default is DontWrapRows.

    If you want to display each label above its associated field
    (instead of next to it), set this property to WrapAllRows.

    \sa fieldGrowthPolicy
*/

void QFormLayout::setRowWrapPolicy(RowWrapPolicy policy)
{
    Q_D(QFormLayout);
    if (RowWrapPolicy(d->rowWrapPolicy) != policy) {
        d->rowWrapPolicy = policy;
        invalidate();
    }
}

QFormLayout::RowWrapPolicy QFormLayout::rowWrapPolicy() const
{
    Q_D(const QFormLayout);
    if (d->rowWrapPolicy == DefaultRowWrapPolicy) {
        return QFormLayout::RowWrapPolicy(d->getStyle()->styleHint(QStyle::SH_FormLayoutWrapPolicy));
    } else {
        return QFormLayout::RowWrapPolicy(d->rowWrapPolicy);
    }
}

/*!
    \property QFormLayout::labelAlignment
    \brief the horizontal alignment of the labels

    The default value depends on the widget or application style. For
    QCommonStyle derived styles, except for QPlastiqueStyle, the
    default is Qt::AlignLeft; for the other styles, the default is
    Qt::AlignRight.

    \sa formAlignment
*/

void QFormLayout::setLabelAlignment(Qt::Alignment alignment)
{
    Q_D(QFormLayout);
    if (d->labelAlignment != alignment) {
        d->labelAlignment = alignment;
        invalidate();
    }
}

Qt::Alignment QFormLayout::labelAlignment() const
{
    Q_D(const QFormLayout);
    if (!d->labelAlignment) {
        return Qt::Alignment(d->getStyle()->styleHint(QStyle::SH_FormLayoutLabelAlignment));
    } else {
        return d->labelAlignment;
    }
}

/*!
    \property QFormLayout::formAlignment
    \brief the alignment of the form layout's contents within the layout's geometry

    The default value depends on the widget or application style. For
    QMacStyle, the default is Qt::AlignHCenter | Qt::AlignTop; for the
    other styles, the default is Qt::AlignLeft | Qt::AlignTop.

    \sa labelAlignment, rowWrapPolicy
*/

void QFormLayout::setFormAlignment(Qt::Alignment alignment)
{
    Q_D(QFormLayout);
    if (d->formAlignment != alignment) {
        d->formAlignment = alignment;
        invalidate();
    }
}

Qt::Alignment QFormLayout::formAlignment() const
{
    Q_D(const QFormLayout);
    if (!d->formAlignment) {
        return Qt::Alignment(d->getStyle()->styleHint(QStyle::SH_FormLayoutFormAlignment));
    } else {
        return d->formAlignment;
    }
}

/*!
    \property QFormLayout::horizontalSpacing
    \brief the spacing between widgets that are laid out side by side

    By default, if no value is explicitly set, the layout's horizontal
    spacing is inherited from the parent layout, or from the style settings
    for the parent widget.

    \sa verticalSpacing, QStyle::pixelMetric(), {QStyle::}{PM_LayoutHorizontalSpacing}
*/
void QFormLayout::setHorizontalSpacing(int spacing)
{
    Q_D(QFormLayout);
    if (spacing != d->hSpacing) {
        d->hSpacing = spacing;
        invalidate();
    }
}

int QFormLayout::horizontalSpacing() const
{
    Q_D(const QFormLayout);
    if (d->hSpacing >= 0) {
        return d->hSpacing;
    } else {
        return qSmartSpacing(this, QStyle::PM_LayoutHorizontalSpacing);
    }
}

/*!
    \property QFormLayout::verticalSpacing
    \brief the spacing between widgets that are laid out vertically

    By default, if no value is explicitly set, the layout's vertical spacing is
    inherited from the parent layout, or from the style settings for the parent
    widget.

    \sa horizontalSpacing, QStyle::pixelMetric(), {QStyle::}{PM_LayoutHorizontalSpacing}
*/
void QFormLayout::setVerticalSpacing(int spacing)
{
    Q_D(QFormLayout);
    if (spacing != d->vSpacing) {
        d->vSpacing = spacing;
        invalidate();
    }
}

int QFormLayout::verticalSpacing() const
{
    Q_D(const QFormLayout);
    if (d->vSpacing >= 0) {
        return d->vSpacing;
    } else {
        return qSmartSpacing(this, QStyle::PM_LayoutVerticalSpacing);
    }
}

/*!
    This function sets both the vertical and horizontal spacing to
    \a spacing.

    \sa setVerticalSpacing(), setHorizontalSpacing()
*/
void QFormLayout::setSpacing(int spacing)
{
    Q_D(QFormLayout);
    d->vSpacing = d->hSpacing = spacing;
    invalidate();
}

/*!
    If the vertical spacing is equal to the horizontal spacing,
    this function returns that value; otherwise it returns -1.

    \sa setSpacing(), verticalSpacing(), horizontalSpacing()
*/
int QFormLayout::spacing() const
{
    int hSpacing = horizontalSpacing();
    if (hSpacing == verticalSpacing()) {
        return hSpacing;
    } else {
        return -1;
    }
}

void QFormLayoutPrivate::arrangeWidgets(const QList<QLayoutStruct> &layouts, QRect &rect)
{
    Q_Q(QFormLayout);

    int i;
    const int rr = m_matrix.rowCount();
    QWidget *w = q->parentWidget();
    Qt::LayoutDirection layoutDirection = w ? w->layoutDirection() : QGuiApplication::layoutDirection();

    Qt::Alignment formAlignment = fixedAlignment(q->formAlignment(), layoutDirection);
    int leftOffset = 0;
    int delta = rect.width() - formMaxWidth;
    if (formAlignment & (Qt::AlignHCenter | Qt::AlignRight) && delta > 0) {
        leftOffset = delta;
        if (formAlignment & Qt::AlignHCenter)
            leftOffset >>= 1;
    }

    for (i = 0; i < rr; ++i) {
        QFormLayoutItem *label = m_matrix(i, 0);
        QFormLayoutItem *field = m_matrix(i, 1);

        if (!q->isRowVisible(i))
            continue;

        if (label && label->vLayoutIndex > -1) {
            int height = layouts.at(label->vLayoutIndex).size;
            if ((label->expandingDirections() & Qt::Vertical) == 0) {
                /*
                    If the field on the right-hand side is tall,
                    we want the label to be top-aligned, but not too
                    much. So we introduce a 7 / 4 factor so that it
                    gets some extra pixels at the top.
                */
                height = qMin(height,
                              qMin(label->sizeHint.height() * 7 / 4,
                                   label->maxSize.height()));
            }

            QSize sz(qMin(label->layoutWidth, label->sizeHint.width()), height);
            int x = leftOffset + rect.x() + label->layoutPos;
            const auto fAlign = fixedAlignment(q->labelAlignment(), layoutDirection);
            if (fAlign & Qt::AlignRight)
                x += label->layoutWidth - sz.width();
            else if (fAlign & Qt::AlignHCenter)
                x += label->layoutWidth / 2 - sz.width() / 2;
            QPoint p(x, layouts.at(label->vLayoutIndex).pos);
            // ### expansion & sizepolicy stuff

            label->setGeometry(QStyle::visualRect(layoutDirection, rect, QRect(p, sz)));
        }

        if (field && field->vLayoutIndex > -1) {
            QSize sz(field->layoutWidth, layouts.at(field->vLayoutIndex).size);
            QPoint p(field->layoutPos + leftOffset + rect.x(), layouts.at(field->vLayoutIndex).pos);
/*
            if ((field->widget() && field->widget()->sizePolicy().horizontalPolicy() & (QSizePolicy::GrowFlag | QSizePolicy::ExpandFlag | QSizePolicy::IgnoreFlag))
                || (field->layout() && sz.width() < field->maxSize.width())) {
                sz.rwidth() = field->layoutWidth;
            }
*/
            if (field->maxSize.isValid())
                sz = sz.boundedTo(field->maxSize);

            field->setGeometry(QStyle::visualRect(layoutDirection, rect, QRect(p, sz)));
        }
    }
}

/*!
    Sets the widget in the given \a row for the given \a role to \a widget, extending the
    layout with empty rows if necessary.

    If the cell is already occupied, the \a widget is not inserted and an error message is
    sent to the console.

    \b{Note:} For most applications, addRow() or insertRow() should be used instead of setWidget().

    \sa setLayout()
*/
void QFormLayout::setWidget(int row, ItemRole role, QWidget *widget)
{
    Q_D(QFormLayout);
    int rowCnt = rowCount();
    if (row >= rowCnt)
        d->insertRows(rowCnt, row - rowCnt + 1);
    d->setWidget(row, role, widget);
}

/*!
    Sets the sub-layout in the given \a row for the given \a role to \a layout, extending the
    form layout with empty rows if necessary.

    If the cell is already occupied, the \a layout is not inserted and an error message is
    sent to the console.

    \b{Note:} For most applications, addRow() or insertRow() should be used instead of setLayout().

    \sa setWidget()
*/
void QFormLayout::setLayout(int row, ItemRole role, QLayout *layout)
{
    Q_D(QFormLayout);
    int rowCnt = rowCount();
    if (row >= rowCnt)
        d->insertRows(rowCnt, row - rowCnt + 1);
    d->setLayout(row, role, layout);
}

/*!
    Sets the item in the given \a row for the given \a role to \a item, extending the
    layout with empty rows if necessary.

    If the cell is already occupied, the \a item is not inserted and an error message is
    sent to the console.
    The \a item spans both columns.

    \warning Do not use this function to add child layouts or child
    widget items. Use setLayout() or setWidget() instead.

    \sa setLayout()
*/
void QFormLayout::setItem(int row, ItemRole role, QLayoutItem *item)
{
    Q_D(QFormLayout);
    int rowCnt = rowCount();
    if (row >= rowCnt)
        d->insertRows(rowCnt, row - rowCnt + 1);
    d->setItem(row, role, item);
}

/*!
    \since 6.4

    Shows the row \a row if \a on is true, otherwise hides the row.

    \a row must be non-negative and less than rowCount().

    \sa removeRow(), takeRow()
*/
void QFormLayout::setRowVisible(int row, bool on)
{
    Q_D(QFormLayout);
    QFormLayoutItem *label = d->m_matrix(row, 0);
    QFormLayoutItem *field = d->m_matrix(row, 1);
    bool change = false;
    if (label) {
        change = label->isVisible != on;
        label->setVisible(on);
    }
    if (field) {
        change |= field->isVisible != on;
        field->setVisible(on);
    }
    if (change)
        invalidate();
}

/*!
    \since 6.4

    \overload

    Shows the row corresponding to \a widget if \a on is true,
    otherwise hides the row.

    \sa removeRow(), takeRow()
*/
void QFormLayout::setRowVisible(QWidget *widget, bool on)
{
    Q_D(QFormLayout);
    if (Q_UNLIKELY(!d->checkWidget(widget)))
        return;

    int row;
    ItemRole role;
    getWidgetPosition(widget, &row, &role);

    if (Q_UNLIKELY(row < 0)) {
        qWarning("QFormLayout::setRowVisible: Invalid widget");
        return;
    }

    setRowVisible(row, on);
}

/*!
    \since 6.4

    \overload

    Shows the row corresponding to \a layout if \a on is true,
    otherwise hides the row.

    \sa removeRow(), takeRow()
*/
void QFormLayout::setRowVisible(QLayout *layout, bool on)
{
    Q_D(QFormLayout);
    if (Q_UNLIKELY(!d->checkLayout(layout)))
        return;

    int row;
    ItemRole role;
    getLayoutPosition(layout, &row, &role);

    if (Q_UNLIKELY(row < 0)) {
        qWarning("QFormLayout::setRowVisible: Invalid layout");
        return;
    }

    setRowVisible(row, on);
}

/*!
    \since 6.4

    Returns true if some items in the row \a row are visible,
    otherwise returns false.
*/
bool QFormLayout::isRowVisible(int row) const
{
    Q_D(const QFormLayout);
    QFormLayoutItem *label = d->m_matrix(row, 0);
    QFormLayoutItem *field = d->m_matrix(row, 1);

    int visibleItemCount = 2;
    if (!label || label->isHidden() || (label->widget() && label->widget()->isHidden()))
        --visibleItemCount;
    if (!field || field->isHidden() || (field->widget() && field->widget()->isHidden()))
        --visibleItemCount;

    return visibleItemCount > 0;
}

/*!
    \since 6.4
    \overload

    Returns true if some items in the row corresponding to \a widget
    are visible, otherwise returns false.
*/
bool QFormLayout::isRowVisible(QWidget *widget) const
{
    Q_D(const QFormLayout);
    if (Q_UNLIKELY(!d->checkWidget(widget)))
        return false;
    int row;
    ItemRole role;
    getWidgetPosition(widget, &row, &role);

    if (Q_UNLIKELY(row < 0)) {
        qWarning("QFormLayout::takeRow: Invalid widget");
        return false;
    }

    return isRowVisible(row);
}

/*!
    \since 6.4
    \overload

    Returns true if some items in the row corresponding to \a layout
    are visible, otherwise returns false.
*/
bool QFormLayout::isRowVisible(QLayout *layout) const
{
    Q_D(const QFormLayout);
    if (Q_UNLIKELY(!d->checkLayout(layout)))
        return false;
    int row;
    ItemRole role;
    getLayoutPosition(layout, &row, &role);

    if (Q_UNLIKELY(row < 0)) {
        qWarning("QFormLayout::takeRow: Invalid layout");
        return false;
    }

    return isRowVisible(row);
}

/*!
     \internal
 */

void QFormLayout::resetFieldGrowthPolicy()
{
    Q_D(QFormLayout);
    d->fieldGrowthPolicy = DefaultFieldGrowthPolicy;
}

/*!
     \internal
 */

void QFormLayout::resetRowWrapPolicy()
{
    Q_D(QFormLayout);
    d->rowWrapPolicy = DefaultRowWrapPolicy;
}

/*!
     \internal
 */

void QFormLayout::resetFormAlignment()
{
    Q_D(QFormLayout);
    d->formAlignment = { };
}

/*!
     \internal
 */

void QFormLayout::resetLabelAlignment()
{
    Q_D(QFormLayout);
    d->labelAlignment = { };
}

#if 0
void QFormLayout::dump() const
{
    Q_D(const QFormLayout);
    for (int i = 0; i < rowCount(); ++i) {
        for (int j = 0; j < 2; ++j) {
            qDebug("m_matrix(%d, %d) = %p", i, j, d->m_matrix(i, j));
        }
    }
    for (int i = 0; i < d->m_things.count(); ++i)
        qDebug("m_things[%d] = %p", i, d->m_things.at(i));
}
#endif

QT_END_NAMESPACE

#include "moc_qformlayout.cpp"
