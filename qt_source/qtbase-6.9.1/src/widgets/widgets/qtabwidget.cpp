// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qtabwidget.h"

#include "private/qapplication_p.h"
#include "private/qwidget_p.h"
#include "private/qtabbar_p.h"
#include "qapplication.h"
#include "qbitmap.h"
#include "qevent.h"
#include "qlayout.h"
#include "qstackedwidget.h"
#include "qstyle.h"
#include "qstyleoption.h"
#include "qstylepainter.h"
#include "qtabbar.h"
#include "qtoolbutton.h"

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

/*!
    \class QTabWidget
    \brief The QTabWidget class provides a stack of tabbed widgets.

    \ingroup organizers
    \ingroup basicwidgets
    \inmodule QtWidgets

    \image fusion-tabwidget.png

    A tab widget provides a tab bar (see QTabBar) and a "page area"
    that is used to display pages related to each tab. By default, the
    tab bar is shown above the page area, but different configurations
    are available (see \l{TabPosition}). Each tab is associated with a
    different widget (called a page). Only the current page is shown in
    the page area; all the other pages are hidden. The user can show a
    different page by clicking on its tab or by pressing its
    Alt+\e{letter} shortcut if it has one.

    The normal way to use QTabWidget is to do the following:
    \list 1
    \li Create a QTabWidget.
    \li Create a QWidget for each of the pages in the tab dialog, but
       do not specify parent widgets for them.
    \li Insert child widgets into the page widget, using layouts to
       position them as normal.
    \li Call addTab() or insertTab() to put the page widgets into the
       tab widget, giving each tab a suitable label with an optional
       keyboard shortcut.
    \endlist

    The position of the tabs is defined by \l tabPosition, their shape
    by \l tabShape.

    The signal currentChanged() is emitted when the user selects a
    page.

    The current page index is available as currentIndex(), the current
    page widget with currentWidget().  You can retrieve a pointer to a
    page widget with a given index using widget(), and can find the
    index position of a widget with indexOf(). Use setCurrentWidget()
    or setCurrentIndex() to show a particular page.

    You can change a tab's text and icon using setTabText() or
    setTabIcon(). A tab and its associated page can be removed with
    removeTab().

    Each tab is either enabled or disabled at any given time (see
    setTabEnabled()). If a tab is enabled, the tab text is drawn
    normally and the user can select that tab. If it is disabled, the
    tab is drawn in a different way and the user cannot select that
    tab. Note that even if a tab is disabled, the page can still be
    visible, for example if all of the tabs happen to be disabled.

    Tab widgets can be a very good way to split up a complex dialog.
    An alternative is to use a QStackedWidget for which you provide some
    means of navigating between pages, for example, a QToolBar or a
    QListWidget.

    Most of the functionality in QTabWidget is provided by a QTabBar
    (at the top, providing the tabs) and a QStackedWidget (most of the
    area, organizing the individual pages).

    \sa QTabBar, QStackedWidget, QToolBox, {Tab Dialog Example}
*/

/*!
    \enum QTabWidget::TabPosition

    This enum type defines where QTabWidget draws the tab row:

    \value North  The tabs are drawn above the pages.
    \value South  The tabs are drawn below the pages.
    \value West  The tabs are drawn to the left of the pages.
    \value East  The tabs are drawn to the right of the pages.
*/

/*!
    \enum QTabWidget::TabShape

    This enum type defines the shape of the tabs:
    \value Rounded  The tabs are drawn with a rounded look. This is the default
                    shape.
    \value Triangular  The tabs are drawn with a triangular look.
*/

/*!
    \fn void QTabWidget::currentChanged(int index)

    This signal is emitted whenever the current page index changes.
    The parameter is the new current page \a index position, or -1
    if there isn't a new one (for example, if there are no widgets
    in the QTabWidget)

    \sa currentWidget(), currentIndex
*/

/*!
    \fn void QTabWidget::tabCloseRequested(int index)
    \since 4.5

    This signal is emitted when the close button on a tab is clicked.
    The \a index is the index that should be removed.

    \sa setTabsClosable()
*/

/*!
    \fn void QTabWidget::tabBarClicked(int index)

    This signal is emitted when user clicks on a tab at an \a index.

    \a index refers to the tab clicked, or -1 if no tab is under the cursor.

    \since 5.2
*/

/*!
    \fn void QTabWidget::tabBarDoubleClicked(int index)

    This signal is emitted when the user double clicks on a tab at an \a index.

    \a index is the index of a clicked tab, or -1 if no tab is under the cursor.

    \since 5.2
*/

class QTabWidgetPrivate : public QWidgetPrivate
{
    Q_DECLARE_PUBLIC(QTabWidget)

public:
    QTabWidgetPrivate();
    ~QTabWidgetPrivate();
    void updateTabBarPosition();
    void showTab(int);
    void removeTab(int);
    void tabMoved(int from, int to);
    void init();
    bool isAutoHidden() const
    {
        // see QTabBarPrivate::autoHideTabs()
        return (tabs->autoHide() && tabs->count() <= 1);
    }

    void initBasicStyleOption(QStyleOptionTabWidgetFrame *option) const;

    QTabBar *tabs;
    QStackedWidget *stack;
    QRect panelRect;
    bool dirty;
    QTabWidget::TabPosition pos;
    QTabWidget::TabShape shape;
    QWidget *leftCornerWidget;
    QWidget *rightCornerWidget;
};

QTabWidgetPrivate::QTabWidgetPrivate()
    : tabs(nullptr), stack(nullptr), dirty(true),
      pos(QTabWidget::North), shape(QTabWidget::Rounded),
      leftCornerWidget(nullptr), rightCornerWidget(nullptr)
{}

QTabWidgetPrivate::~QTabWidgetPrivate()
{}

void QTabWidgetPrivate::init()
{
    Q_Q(QTabWidget);

    stack = new QStackedWidget(q);
    stack->setObjectName("qt_tabwidget_stackedwidget"_L1);
    stack->setLineWidth(0);
    // hack so that QMacStyle::layoutSpacing() can detect tab widget pages
    stack->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred, QSizePolicy::TabWidget));

    QObjectPrivate::connect(stack, &QStackedWidget::widgetRemoved, this, &QTabWidgetPrivate::removeTab);
    QTabBar *tabBar = new QTabBar(q);
    tabBar->setObjectName("qt_tabwidget_tabbar"_L1);
    tabBar->setDrawBase(false);
    q->setTabBar(tabBar);

    q->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding,
                                 QSizePolicy::TabWidget));
#ifdef QT_KEYPAD_NAVIGATION
    if (QApplicationPrivate::keypadNavigationEnabled())
        q->setFocusPolicy(Qt::NoFocus);
    else
#endif
    q->setFocusPolicy(Qt::TabFocus);
    q->setFocusProxy(tabs);
    q->setTabPosition(static_cast<QTabWidget::TabPosition> (q->style()->styleHint(
                      QStyle::SH_TabWidget_DefaultTabPosition, nullptr, q )));

}

/*!
    \reimp
*/

bool QTabWidget::hasHeightForWidth() const
{
    Q_D(const QTabWidget);
    bool has = d->size_policy.hasHeightForWidth();
    if (!has && d->stack)
        has = d->stack->hasHeightForWidth();
    return has;
}

/*!
    \internal

    Initialize only time inexpensive parts of the style option
    for QTabWidget::setUpLayout()'s non-visible code path.
*/
void QTabWidgetPrivate::initBasicStyleOption(QStyleOptionTabWidgetFrame *option) const
{
    Q_Q(const QTabWidget);
    option->initFrom(q);

    if (q->documentMode())
        option->lineWidth = 0;
    else
        option->lineWidth = q->style()->pixelMetric(QStyle::PM_DefaultFrameWidth, nullptr, q);

    switch (pos) {
    case QTabWidget::North:
        option->shape = shape == QTabWidget::Rounded ? QTabBar::RoundedNorth
                                                     : QTabBar::TriangularNorth;
        break;
    case QTabWidget::South:
        option->shape = shape == QTabWidget::Rounded ? QTabBar::RoundedSouth
                                                     : QTabBar::TriangularSouth;
        break;
    case QTabWidget::West:
        option->shape = shape == QTabWidget::Rounded ? QTabBar::RoundedWest
                                                     : QTabBar::TriangularWest;
        break;
    case QTabWidget::East:
        option->shape = shape == QTabWidget::Rounded ? QTabBar::RoundedEast
                                                     : QTabBar::TriangularEast;
        break;
    }

    option->tabBarRect = q->tabBar()->geometry();
}

/*!
    Initialize \a option with the values from this QTabWidget. This method is useful
    for subclasses when they need a QStyleOptionTabWidgetFrame, but don't want to fill
    in all the information themselves.

    \sa QStyleOption::initFrom(), QTabBar::initStyleOption()
*/
void QTabWidget::initStyleOption(QStyleOptionTabWidgetFrame *option) const
{
    if (!option)
        return;

    Q_D(const QTabWidget);
    d->initBasicStyleOption(option);

    int exth = style()->pixelMetric(QStyle::PM_TabBarBaseHeight, nullptr, this);
    QSize t(0, d->stack->frameWidth());
    if (d->tabs->isVisibleTo(const_cast<QTabWidget *>(this))) {
        t = d->tabs->sizeHint();
        if (documentMode()) {
            if (tabPosition() == East || tabPosition() == West) {
                t.setHeight(height());
            } else {
                t.setWidth(width());
            }
        }
    }

    if (d->rightCornerWidget && d->rightCornerWidget->isVisible()) {
        const QSize rightCornerSizeHint = d->rightCornerWidget->sizeHint();
        const QSize bounds(rightCornerSizeHint.width(), t.height() - exth);
        option->rightCornerWidgetSize = rightCornerSizeHint.boundedTo(bounds);
    } else {
        option->rightCornerWidgetSize = QSize(0, 0);
    }

    if (d->leftCornerWidget && d->leftCornerWidget->isVisible()) {
        const QSize leftCornerSizeHint = d->leftCornerWidget->sizeHint();
        const QSize bounds(leftCornerSizeHint.width(), t.height() - exth);
        option->leftCornerWidgetSize = leftCornerSizeHint.boundedTo(bounds);
    } else {
        option->leftCornerWidgetSize = QSize(0, 0);
    }

    option->tabBarSize = t;

    QRect selectedTabRect = tabBar()->tabRect(tabBar()->currentIndex());
    selectedTabRect.moveTopLeft(selectedTabRect.topLeft() + option->tabBarRect.topLeft());
    option->selectedTabRect = selectedTabRect;
}

/*!
    Constructs a tabbed widget with parent \a parent.
*/
QTabWidget::QTabWidget(QWidget *parent)
    : QWidget(*new QTabWidgetPrivate, parent, { })
{
    Q_D(QTabWidget);
    d->init();
}


/*!
    Destroys the tabbed widget.
*/
QTabWidget::~QTabWidget()
{
}

/*!
    \fn int QTabWidget::addTab(QWidget *page, const QString &label)

    Adds a tab with the given \a page and \a label to the tab widget,
    and returns the index of the tab in the tab bar. Ownership of \a page
    is passed on to the QTabWidget.

    If the tab's \a label contains an ampersand, the letter following
    the ampersand is used as a shortcut for the tab, e.g. if the
    label is "Bro\&wse" then Alt+W becomes a shortcut which will
    move the focus to this tab.

    \note If you call addTab() after show(), the layout system will try
    to adjust to the changes in its widgets hierarchy and may cause
    flicker. To prevent this, you can set the QWidget::updatesEnabled
    property to false prior to changes; remember to set the property
    to true when the changes are done, making the widget receive paint
    events again.

    \sa insertTab()
*/
int QTabWidget::addTab(QWidget *child, const QString &label)
{
    return insertTab(-1, child, label);
}


/*!
    \fn int QTabWidget::addTab(QWidget *page, const QIcon &icon, const QString &label)
    \overload

    Adds a tab with the given \a page, \a icon, and \a label to the tab
    widget, and returns the index of the tab in the tab bar. Ownership
    of \a page is passed on to the QTabWidget.

    This function is the same as addTab(), but with an additional \a
    icon.
*/
int QTabWidget::addTab(QWidget *child, const QIcon& icon, const QString &label)
{
    return insertTab(-1, child, icon, label);
}


/*!
    \fn int QTabWidget::insertTab(int index, QWidget *page, const QString &label)

    Inserts a tab with the given \a label and \a page into the tab
    widget at the specified \a index, and returns the index of the
    inserted tab in the tab bar. Ownership of \a page is passed on to the
    QTabWidget.

    The label is displayed in the tab and may vary in appearance depending
    on the configuration of the tab widget.

    If the tab's \a label contains an ampersand, the letter following
    the ampersand is used as a shortcut for the tab, e.g. if the
    label is "Bro\&wse" then Alt+W becomes a shortcut which will
    move the focus to this tab.

    If \a index is out of range, the tab is simply appended.
    Otherwise it is inserted at the specified position.

    If the QTabWidget was empty before this function is called, the
    new page becomes the current page. Inserting a new tab at an index
    less than or equal to the current index will increment the current
    index, but keep the current page.

    \note If you call insertTab() after show(), the layout system will try
    to adjust to the changes in its widgets hierarchy and may cause
    flicker. To prevent this, you can set the QWidget::updatesEnabled
    property to false prior to changes; remember to set the property
    to true when the changes are done, making the widget receive paint
    events again.

    \sa addTab()
*/
int QTabWidget::insertTab(int index, QWidget *w, const QString &label)
{
    return insertTab(index, w, QIcon(), label);
}


/*!
    \fn int QTabWidget::insertTab(int index, QWidget *page, const QIcon& icon, const QString &label)
    \overload

    Inserts a tab with the given \a label, \a page, and \a icon into
    the tab widget at the specified \a index, and returns the index of the
    inserted tab in the tab bar. Ownership of \a page is passed on to the
    QTabWidget.

    This function is the same as insertTab(), but with an additional
    \a icon.
*/
int QTabWidget::insertTab(int index, QWidget *w, const QIcon& icon, const QString &label)
{
    Q_D(QTabWidget);
    if (!w)
        return -1;
    index = d->stack->insertWidget(index, w);
    d->tabs->insertTab(index, icon, label);
    setUpLayout();
    tabInserted(index);

    return index;
}


/*!
    Defines a new \a label for the page at position \a index's tab.

    If the provided text contains an ampersand character ('&'), a
    shortcut is automatically created for it. The character that
    follows the '&' will be used as the shortcut key. Any previous
    shortcut will be overwritten, or cleared if no shortcut is defined
    by the text. See the \l {QShortcut#mnemonic}{QShortcut}
    documentation for details (to display an actual ampersand, use
    '&&').

*/
void QTabWidget::setTabText(int index, const QString &label)
{
    Q_D(QTabWidget);
    d->tabs->setTabText(index, label);
    setUpLayout();
}

/*!
    Returns the label text for the tab on the page at position \a index.
*/

QString QTabWidget::tabText(int index) const
{
    Q_D(const QTabWidget);
    return d->tabs->tabText(index);
}

/*!
    Sets the \a icon for the tab at position \a index.
*/
void QTabWidget::setTabIcon(int index, const QIcon &icon)
{
    Q_D(QTabWidget);
    d->tabs->setTabIcon(index, icon);
    setUpLayout();
}

/*!
    Returns the icon for the tab on the page at position \a index.
*/

QIcon QTabWidget::tabIcon(int index) const
{
    Q_D(const QTabWidget);
    return d->tabs->tabIcon(index);
}

/*!
    Returns \c true if the page at position \a index is enabled; otherwise returns \c false.

    \sa setTabEnabled(), QWidget::isEnabled()
*/

bool QTabWidget::isTabEnabled(int index) const
{
    Q_D(const QTabWidget);
    return d->tabs->isTabEnabled(index);
}

/*!
    If \a enable is true, the page at position \a index is enabled; otherwise the page at
    position \a index is disabled. The page's tab is redrawn appropriately.

    QTabWidget uses QWidget::setEnabled() internally, rather than
    keeping a separate flag.

    Note that even a disabled tab/page may be visible. If the page is
    visible already, QTabWidget will not hide it; if all the pages are
    disabled, QTabWidget will show one of them.

    \sa isTabEnabled(), QWidget::setEnabled()
*/

void QTabWidget::setTabEnabled(int index, bool enable)
{
    Q_D(QTabWidget);
    d->tabs->setTabEnabled(index, enable);
    if (QWidget *widget = d->stack->widget(index))
        widget->setEnabled(enable);
}

/*!
    Returns true if the page at position \a index is visible; otherwise returns false.

    \sa setTabVisible()
    \since 5.15
*/

bool QTabWidget::isTabVisible(int index) const
{
    Q_D(const QTabWidget);
    return d->tabs->isTabVisible(index);
}

/*!
    If \a visible is true, the page at position \a index is visible; otherwise the page at
    position \a index is hidden. The page's tab is redrawn appropriately.

    \sa isTabVisible()
    \since 5.15
*/

void QTabWidget::setTabVisible(int index, bool visible)
{
    Q_D(QTabWidget);
    QWidget *widget = d->stack->widget(index);
    bool currentVisible = d->tabs->isTabVisible(d->tabs->currentIndex());
    d->tabs->setTabVisible(index, visible);
    if (!visible) {
        if (widget)
            widget->setVisible(false);
    } else if (!currentVisible) {
        setCurrentIndex(index);
        if (widget)
            widget->setVisible(true);
    }
    setUpLayout();
}

/*!
  \fn void QTabWidget::setCornerWidget(QWidget *widget, Qt::Corner corner)

  Sets the given \a widget to be shown in the specified \a corner of the
  tab widget. The geometry of the widget is determined based on the widget's
  sizeHint() and the style().

  Only the horizontal element of the \a corner will be used.

  Passing \nullptr shows no widget in the corner.

  Any previously set corner widget is hidden.

  All widgets set here will be deleted by the tab widget when it is
  destroyed unless you separately reparent the widget after setting
  some other corner widget (or \nullptr).

  Note: Corner widgets are designed for \l North and \l South tab positions;
  other orientations are known to not work properly.

  \sa cornerWidget(), setTabPosition()
*/
void QTabWidget::setCornerWidget(QWidget * widget, Qt::Corner corner)
{
    Q_D(QTabWidget);
    if (widget && widget->parentWidget() != this)
        widget->setParent(this);

    if (corner & Qt::TopRightCorner) {
        if (d->rightCornerWidget)
            d->rightCornerWidget->hide();
        d->rightCornerWidget = widget;
    } else {
        if (d->leftCornerWidget)
            d->leftCornerWidget->hide();
        d->leftCornerWidget = widget;
    }
    setUpLayout();
}

/*!
    Returns the widget shown in the \a corner of the tab widget or \nullptr.
*/
QWidget * QTabWidget::cornerWidget(Qt::Corner corner) const
{
    Q_D(const QTabWidget);
    if (corner & Qt::TopRightCorner)
        return d->rightCornerWidget;
    return d->leftCornerWidget;
}

/*!
   Removes the tab at position \a index from this stack of widgets.
   The page widget itself is not deleted.

   \sa addTab(), insertTab()
*/
void QTabWidget::removeTab(int index)
{
    Q_D(QTabWidget);
    if (QWidget *w = d->stack->widget(index))
        d->stack->removeWidget(w);
}

/*!
    Returns a pointer to the page currently being displayed by the tab
    dialog. The tab dialog does its best to make sure that this value
    is never 0 (but if you try hard enough, it can be).

    \sa currentIndex(), setCurrentWidget()
*/

QWidget * QTabWidget::currentWidget() const
{
    Q_D(const QTabWidget);
    return d->stack->currentWidget();
}

/*!
    Makes \a widget the current widget. The \a widget used must be a page in
    this tab widget.

    \sa addTab(), setCurrentIndex(), currentWidget()
 */
void QTabWidget::setCurrentWidget(QWidget *widget)
{
    Q_D(const QTabWidget);
    d->tabs->setCurrentIndex(indexOf(widget));
}


/*!
    \property QTabWidget::currentIndex
    \brief the index position of the current tab page

    The current index is -1 if there is no current widget.

    By default, this property contains a value of -1 because there are initially
    no tabs in the widget.
*/

int QTabWidget::currentIndex() const
{
    Q_D(const QTabWidget);
    return d->tabs->currentIndex();
}

void QTabWidget::setCurrentIndex(int index)
{
    Q_D(QTabWidget);
    d->tabs->setCurrentIndex(index);
}


/*!
    Returns the index position of the page occupied by the widget \a
    w, or -1 if the widget cannot be found.
*/
int QTabWidget::indexOf(const QWidget *w) const
{
    Q_D(const QTabWidget);
    return d->stack->indexOf(w);
}


/*!
    \reimp
*/
void QTabWidget::resizeEvent(QResizeEvent *e)
{
    QWidget::resizeEvent(e);
    setUpLayout();
}

/*!
    Replaces the dialog's QTabBar heading with the tab bar \a tb. Note
    that this must be called \e before any tabs have been added, or
    the behavior is undefined.

    \sa tabBar()
*/
void QTabWidget::setTabBar(QTabBar* tb)
{
    Q_D(QTabWidget);
    Q_ASSERT(tb);

    if (tb->parentWidget() != this) {
        tb->setParent(this);
        tb->show();
    }
    delete d->tabs;
    d->tabs = tb;
    setFocusProxy(d->tabs);
    QObjectPrivate::connect(d->tabs, &QTabBar::currentChanged,
                            d, &QTabWidgetPrivate::showTab);
    QObjectPrivate::connect(d->tabs, &QTabBar::tabMoved,
                            d, &QTabWidgetPrivate::tabMoved);
    connect(d->tabs, &QTabBar::tabBarClicked,
            this, &QTabWidget::tabBarClicked);
    connect(d->tabs, &QTabBar::tabBarDoubleClicked,
            this, &QTabWidget::tabBarDoubleClicked);
    if (d->tabs->tabsClosable())
        connect(d->tabs, &QTabBar::tabCloseRequested,
                this, &QTabWidget::tabCloseRequested);
    tb->setExpanding(!documentMode());
    setUpLayout();
}


/*!
    Returns the current QTabBar.

    \sa setTabBar()
*/
QTabBar* QTabWidget::tabBar() const
{
    Q_D(const QTabWidget);
    return d->tabs;
}

/*
    Ensures that the selected tab's page is visible and appropriately
    sized.
*/

void QTabWidgetPrivate::showTab(int index)
{
    Q_Q(QTabWidget);
    if (index < stack->count() && index >= 0)
        stack->setCurrentIndex(index);
    emit q->currentChanged(index);
}

void QTabWidgetPrivate::removeTab(int index)
{
    Q_Q(QTabWidget);
    tabs->removeTab(index);
    q->setUpLayout();
    q->tabRemoved(index);
}

void QTabWidgetPrivate::tabMoved(int from, int to)
{
    const QSignalBlocker blocker(stack);
    QWidget *w = stack->widget(from);
    stack->removeWidget(w);
    stack->insertWidget(to, w);
}

/*
    Set up the layout.
    Get subrect from the current style, and set the geometry for the
    stack widget, tab bar and corner widgets.
*/
void QTabWidget::setUpLayout(bool onlyCheck)
{
    Q_D(QTabWidget);
    if (onlyCheck && !d->dirty)
        return; // nothing to do

    if (!isVisible()) {
        // this must be done immediately, because QWidgetItem relies on it (even if !isVisible())
        QStyleOptionTabWidgetFrame basicOption;
        d->initBasicStyleOption(&basicOption);
        d->setLayoutItemMargins(QStyle::SE_TabWidgetLayoutItem, &basicOption);
        d->dirty = true;
        return; // we'll do it later
    }

    QStyleOptionTabWidgetFrame option;
    initStyleOption(&option);
    d->setLayoutItemMargins(QStyle::SE_TabWidgetLayoutItem, &option);

    QRect tabRect = style()->subElementRect(QStyle::SE_TabWidgetTabBar, &option, this);
    d->panelRect = style()->subElementRect(QStyle::SE_TabWidgetTabPane, &option, this);
    QRect contentsRect = style()->subElementRect(QStyle::SE_TabWidgetTabContents, &option, this);
    QRect leftCornerRect = style()->subElementRect(QStyle::SE_TabWidgetLeftCorner, &option, this);
    QRect rightCornerRect = style()->subElementRect(QStyle::SE_TabWidgetRightCorner, &option, this);

    d->tabs->setGeometry(tabRect);
    d->stack->setGeometry(contentsRect);
    if (d->leftCornerWidget && d->leftCornerWidget->isVisible())
        d->leftCornerWidget->setGeometry(leftCornerRect);
    if (d->rightCornerWidget && d->rightCornerWidget->isVisible())
        d->rightCornerWidget->setGeometry(rightCornerRect);

    if (!onlyCheck)
        update();
    updateGeometry();
}

/*!
    \internal
*/
static inline QSize basicSize(
    bool horizontal, const QSize &lc, const QSize &rc, const QSize &s, const QSize &t)
{
    return horizontal
        ? QSize(qMax(s.width(), t.width() + rc.width() + lc.width()),
                s.height() + (qMax(rc.height(), qMax(lc.height(), t.height()))))
        : QSize(s.width() + (qMax(rc.width(), qMax(lc.width(), t.width()))),
                qMax(s.height(), t.height() + rc.height() + lc.height()));
}

/*!
    \reimp
*/
QSize QTabWidget::sizeHint() const
{
    Q_D(const QTabWidget);
    QSize lc(0, 0), rc(0, 0);
    QStyleOptionTabWidgetFrame opt;
    initStyleOption(&opt);
    opt.state = QStyle::State_None;

    if (d->leftCornerWidget && d->leftCornerWidget->isVisible())
        lc = d->leftCornerWidget->sizeHint();
    if (d->rightCornerWidget  && d->rightCornerWidget->isVisible())
        rc = d->rightCornerWidget->sizeHint();
    if (!d->dirty) {
        QTabWidget *that = const_cast<QTabWidget*>(this);
        that->setUpLayout(true);
    }
    QSize s;
    for (int i=0; i< d->stack->count(); ++i) {
        if (const QWidget* w = d->stack->widget(i)) {
            if (d->tabs->isTabVisible(i))
                s = s.expandedTo(w->sizeHint());
        }
    }
    QSize t;
    if (!d->isAutoHidden()) {
        t = d->tabs->sizeHint();
        if (usesScrollButtons())
            t = t.boundedTo(QSize(200,200));
        else
            t = t.boundedTo(QGuiApplication::primaryScreen()->virtualGeometry().size());
    }

    QSize sz = basicSize(d->pos == North || d->pos == South, lc, rc, s, t);

    return style()->sizeFromContents(QStyle::CT_TabWidget, &opt, sz, this);
}


/*!
    \reimp

    Returns a suitable minimum size for the tab widget.
*/
QSize QTabWidget::minimumSizeHint() const
{
    Q_D(const QTabWidget);
    QSize lc(0, 0), rc(0, 0);

    if (d->leftCornerWidget && d->leftCornerWidget->isVisible())
        lc = d->leftCornerWidget->minimumSizeHint();
    if (d->rightCornerWidget && d->rightCornerWidget->isVisible())
        rc = d->rightCornerWidget->minimumSizeHint();
    if (!d->dirty) {
        QTabWidget *that = const_cast<QTabWidget*>(this);
        that->setUpLayout(true);
    }
    QSize s(d->stack->minimumSizeHint());
    QSize t;
    if (!d->isAutoHidden())
        t = d->tabs->minimumSizeHint();

    QSize sz = basicSize(d->pos == North || d->pos == South, lc, rc, s, t);

    QStyleOptionTabWidgetFrame opt;
    initStyleOption(&opt);
    opt.palette = palette();
    opt.state = QStyle::State_None;
    return style()->sizeFromContents(QStyle::CT_TabWidget, &opt, sz, this);
}

/*!
    \reimp
*/
int QTabWidget::heightForWidth(int width) const
{
    Q_D(const QTabWidget);
    QStyleOptionTabWidgetFrame opt;
    initStyleOption(&opt);
    opt.state = QStyle::State_None;

    QSize zero(0,0);
    const QSize padding = style()->sizeFromContents(QStyle::CT_TabWidget, &opt, zero, this);

    QSize lc(0, 0), rc(0, 0);
    if (d->leftCornerWidget && d->leftCornerWidget->isVisible())
        lc = d->leftCornerWidget->sizeHint();
    if (d->rightCornerWidget && d->rightCornerWidget->isVisible())
        rc = d->rightCornerWidget->sizeHint();
    if (!d->dirty) {
        QTabWidget *that = const_cast<QTabWidget*>(this);
        that->setUpLayout(true);
    }
    QSize t;
    if (!d->isAutoHidden()) {
        t = d->tabs->sizeHint();
        if (usesScrollButtons())
            t = t.boundedTo(QSize(200,200));
        else
            t = t.boundedTo(QGuiApplication::primaryScreen()->virtualSize());
    }

    const bool tabIsHorizontal = (d->pos == North || d->pos == South);
    const int contentsWidth = width - padding.width();
    int stackWidth = contentsWidth;
    if (!tabIsHorizontal)
        stackWidth -= qMax(t.width(), qMax(lc.width(), rc.width()));

    int stackHeight = d->stack->heightForWidth(stackWidth);
    QSize s(stackWidth, stackHeight);

    QSize contentSize = basicSize(tabIsHorizontal, lc, rc, s, t);
    return (contentSize + padding).height();
}


/*!
    \reimp
 */
void QTabWidget::showEvent(QShowEvent *)
{
    setUpLayout();
}

void QTabWidgetPrivate::updateTabBarPosition()
{
    Q_Q(QTabWidget);
    switch (pos) {
    case QTabWidget::North:
        tabs->setShape(shape == QTabWidget::Rounded ? QTabBar::RoundedNorth
                                                    : QTabBar::TriangularNorth);
        break;
    case QTabWidget::South:
        tabs->setShape(shape == QTabWidget::Rounded ? QTabBar::RoundedSouth
                                                    : QTabBar::TriangularSouth);
        break;
    case QTabWidget::West:
        tabs->setShape(shape == QTabWidget::Rounded ? QTabBar::RoundedWest
                                                    : QTabBar::TriangularWest);
        break;
    case QTabWidget::East:
        tabs->setShape(shape == QTabWidget::Rounded ? QTabBar::RoundedEast
                                                    : QTabBar::TriangularEast);
        break;
    }
    q->setUpLayout();
}

/*!
    \property QTabWidget::tabPosition
    \brief the position of the tabs in this tab widget

    Possible values for this property are described by the TabPosition
    enum.

    By default, this property is set to \l North.

    \sa TabPosition
*/
QTabWidget::TabPosition QTabWidget::tabPosition() const
{
    Q_D(const QTabWidget);
    return d->pos;
}

void QTabWidget::setTabPosition(TabPosition pos)
{
    Q_D(QTabWidget);
    if (d->pos == pos)
        return;
    d->pos = pos;
    d->updateTabBarPosition();
}

/*!
    \property QTabWidget::tabsClosable
    \brief whether close buttons are automatically added to each tab.

    \since 4.5

    \sa QTabBar::tabsClosable()
*/
bool QTabWidget::tabsClosable() const
{
    return tabBar()->tabsClosable();
}

void QTabWidget::setTabsClosable(bool closeable)
{
    if (tabsClosable() == closeable)
        return;

    tabBar()->setTabsClosable(closeable);
    if (closeable)
        connect(tabBar(), SIGNAL(tabCloseRequested(int)),
                this, SIGNAL(tabCloseRequested(int)));
    else
        disconnect(tabBar(), SIGNAL(tabCloseRequested(int)),
                  this, SIGNAL(tabCloseRequested(int)));
    setUpLayout();
}

/*!
    \property QTabWidget::movable
    \brief This property holds whether the user can move the tabs
    within the tabbar area.

    \since 4.5

    By default, this property is \c false;
*/

bool QTabWidget::isMovable() const
{
    return tabBar()->isMovable();
}

void QTabWidget::setMovable(bool movable)
{
    tabBar()->setMovable(movable);
}

/*!
    \property QTabWidget::tabShape
    \brief the shape of the tabs in this tab widget

    Possible values for this property are QTabWidget::Rounded
    (default) or QTabWidget::Triangular.

    \sa TabShape
*/

QTabWidget::TabShape QTabWidget::tabShape() const
{
    Q_D(const QTabWidget);
    return d->shape;
}

void QTabWidget::setTabShape(TabShape s)
{
    Q_D(QTabWidget);
    if (d->shape == s)
        return;
    d->shape = s;
    d->updateTabBarPosition();
}

/*!
    \reimp
 */
bool QTabWidget::event(QEvent *ev)
{
    if (ev->type() == QEvent::LayoutRequest)
        setUpLayout();
    return QWidget::event(ev);
}

/*!
    \reimp
 */
void QTabWidget::changeEvent(QEvent *ev)
{
    if (ev->type() == QEvent::StyleChange
#ifdef Q_OS_MAC
            || ev->type() == QEvent::MacSizeChange
#endif
            )
        setUpLayout();
    QWidget::changeEvent(ev);
}


/*!
    \reimp
 */
void QTabWidget::keyPressEvent(QKeyEvent *e)
{
    Q_D(QTabWidget);
    if (((e->key() == Qt::Key_Tab || e->key() == Qt::Key_Backtab) &&
          count() > 1 && e->modifiers() & Qt::ControlModifier)
#ifdef QT_KEYPAD_NAVIGATION
          || QApplicationPrivate::keypadNavigationEnabled() && (e->key() == Qt::Key_Left || e->key() == Qt::Key_Right) && count() > 1
#endif
       ) {
        int pageCount = d->tabs->count();
        int page = currentIndex();
        int dx = (e->key() == Qt::Key_Backtab || e->modifiers() & Qt::ShiftModifier) ? -1 : 1;
#ifdef QT_KEYPAD_NAVIGATION
        if (QApplicationPrivate::keypadNavigationEnabled() && (e->key() == Qt::Key_Left || e->key() == Qt::Key_Right))
            dx = e->key() == (isRightToLeft() ? Qt::Key_Right : Qt::Key_Left) ? -1 : 1;
#endif
        for (int pass = 0; pass < pageCount; ++pass) {
            page+=dx;
            if (page < 0
#ifdef QT_KEYPAD_NAVIGATION
                && !e->isAutoRepeat()
#endif
               ) {
                page = count() - 1;
            } else if (page >= pageCount
#ifdef QT_KEYPAD_NAVIGATION
                       && !e->isAutoRepeat()
#endif
                      ) {
                page = 0;
            }
            if (d->tabs->isTabEnabled(page) && d->tabs->isTabVisible(page)) {
                setCurrentIndex(page);
                break;
            }
        }
        if (!QApplication::focusWidget())
            d->tabs->setFocus();
    } else {
        e->ignore();
    }
}

/*!
    Returns the tab page at index position \a index or \nullptr if the
    \a index is out of range.
*/
QWidget *QTabWidget::widget(int index) const
{
    Q_D(const QTabWidget);
    return d->stack->widget(index);
}

/*!
    \property QTabWidget::count
    \brief the number of tabs in the tab bar

    By default, this property contains a value of 0.
*/
int QTabWidget::count() const
{
    Q_D(const QTabWidget);
    return d->tabs->count();
}

#if QT_CONFIG(tooltip)
/*!
    Sets the tab tool tip for the page at position \a index to \a tip.

    \sa tabToolTip()
*/
void QTabWidget::setTabToolTip(int index, const QString & tip)
{
    Q_D(QTabWidget);
    d->tabs->setTabToolTip(index, tip);
}

/*!
    Returns the tab tool tip for the page at position \a index or
    an empty string if no tool tip has been set.

    \sa setTabToolTip()
*/
QString QTabWidget::tabToolTip(int index) const
{
    Q_D(const QTabWidget);
    return d->tabs->tabToolTip(index);
}
#endif // QT_CONFIG(tooltip)

#if QT_CONFIG(whatsthis)
/*!
    \since 4.1

    Sets the What's This help text for the page at position \a index
    to \a text.
*/
void QTabWidget::setTabWhatsThis(int index, const QString &text)
{
    Q_D(QTabWidget);
    d->tabs->setTabWhatsThis(index, text);
}

/*!
    \since 4.1

    Returns the What's This help text for the page at position \a index,
    or an empty string if no help text has been set.
*/
QString QTabWidget::tabWhatsThis(int index) const
{
    Q_D(const QTabWidget);
    return d->tabs->tabWhatsThis(index);
}
#endif // QT_CONFIG(whatsthis)

/*!
  This virtual handler is called after a new tab was added or
  inserted at position \a index.

  \sa tabRemoved()
 */
void QTabWidget::tabInserted(int index)
{
    Q_UNUSED(index);
}

/*!
  This virtual handler is called after a tab was removed from
  position \a index.

  \sa tabInserted()
 */
void QTabWidget::tabRemoved(int index)
{
    Q_UNUSED(index);
}

/*!
    \fn void QTabWidget::paintEvent(QPaintEvent *event)

    Paints the tab widget's tab bar in response to the paint \a event.
*/
void QTabWidget::paintEvent(QPaintEvent *)
{
    Q_D(QTabWidget);
    if (documentMode()) {
        if (d->tabs->drawBase()) {
            QStylePainter p(this, tabBar());
            if (QWidget *w = cornerWidget(Qt::TopLeftCorner); w && w->isVisible()) {
                QStyleOptionTabBarBase opt;
                QTabBarPrivate::initStyleBaseOption(&opt, tabBar(), w->size());
                opt.rect.moveLeft(w->x() + opt.rect.x());
                opt.rect.moveTop(w->y() + opt.rect.y());
                p.drawPrimitive(QStyle::PE_FrameTabBarBase, opt);
            }
            if (QWidget *w = cornerWidget(Qt::TopRightCorner); w && w->isVisible()) {
                QStyleOptionTabBarBase opt;
                QTabBarPrivate::initStyleBaseOption(&opt, tabBar(), w->size());
                opt.rect.moveLeft(w->x() + opt.rect.x());
                opt.rect.moveTop(w->y() + opt.rect.y());
                p.drawPrimitive(QStyle::PE_FrameTabBarBase, opt);
            }
        }
        return;
    }
    QStylePainter p(this);

    QStyleOptionTabWidgetFrame opt;
    initStyleOption(&opt);
    opt.rect = d->panelRect;
    p.drawPrimitive(QStyle::PE_FrameTabWidget, opt);
}

/*!
    \property QTabWidget::iconSize
    \brief The size for icons in the tab bar
    \since 4.2

    The default value is style-dependent. This is the maximum size
    that the icons will have. Icons are not scaled up if they are of
    smaller size.

    \sa QTabBar::iconSize
*/
QSize QTabWidget::iconSize() const
{
    return d_func()->tabs->iconSize();
}

void QTabWidget::setIconSize(const QSize &size)
{
    d_func()->tabs->setIconSize(size);
}

/*!
    \property QTabWidget::elideMode
    \brief how to elide text in the tab bar
    \since 4.2

    This property controls how items are elided when there is not
    enough space to show them for a given tab bar size.

    By default the value is style dependent.

    \sa QTabBar::elideMode, usesScrollButtons, QStyle::SH_TabBar_ElideMode
*/
Qt::TextElideMode QTabWidget::elideMode() const
{
    return d_func()->tabs->elideMode();
}

void QTabWidget::setElideMode(Qt::TextElideMode mode)
{
    d_func()->tabs->setElideMode(mode);
}

/*!
    \property QTabWidget::usesScrollButtons
    \brief Whether or not a tab bar should use buttons to scroll tabs when it
    has many tabs.
    \since 4.2

    When there are too many tabs in a tab bar for its size, the tab bar can either choose
    to expand its size or to add buttons that allow you to scroll through the tabs.

    By default the value is style dependent.

    \sa elideMode, QTabBar::usesScrollButtons, QStyle::SH_TabBar_PreferNoArrows
*/
bool QTabWidget::usesScrollButtons() const
{
    return d_func()->tabs->usesScrollButtons();
}

void QTabWidget::setUsesScrollButtons(bool useButtons)
{
    d_func()->tabs->setUsesScrollButtons(useButtons);
}

/*!
    \property QTabWidget::documentMode
    \brief Whether or not the tab widget is rendered in a mode suitable for document
     pages. This is the same as document mode on \macos.
    \since 4.5

    When this property is set the tab widget frame is not rendered. This mode is useful
    for showing document-type pages where the page covers most of the tab widget
    area.

    \sa elideMode, QTabBar::documentMode, QTabBar::usesScrollButtons, QStyle::SH_TabBar_PreferNoArrows
*/
bool QTabWidget::documentMode() const
{
    Q_D(const QTabWidget);
    // QStyleSheetStyle could query documentMode during creation of our QTabBar.
    return d->tabs ? d->tabs->documentMode() : false;
}

void QTabWidget::setDocumentMode(bool enabled)
{
    Q_D(QTabWidget);
    d->tabs->setDocumentMode(enabled);
    d->tabs->setExpanding(!enabled);
    d->tabs->setDrawBase(enabled);
    setUpLayout();
}

/*!
    \property QTabWidget::tabBarAutoHide
    \brief If true, the tab bar is automatically hidden when it contains less
    than 2 tabs.
    \since 5.4

    By default, this property is false.

    \sa QWidget::visible
*/

bool QTabWidget::tabBarAutoHide() const
{
    Q_D(const QTabWidget);
    return d->tabs->autoHide();
}

void QTabWidget::setTabBarAutoHide(bool enabled)
{
    Q_D(QTabWidget);
    return d->tabs->setAutoHide(enabled);
}

/*!
    Removes all the pages, but does not delete them. Calling this function
    is equivalent to calling removeTab() until the tab widget is empty.
*/
void QTabWidget::clear()
{
    Q_D(QTabWidget);
    Q_ASSERT(d->stack->layout());
    d->stack->layout()->setEnabled(false);
    d->stack->setUpdatesEnabled(false);
    d->tabs->setUpdatesEnabled(false);

    int c = count();
    while (c)
        removeTab(--c);

    d->tabs->setUpdatesEnabled(true);
    d->stack->setUpdatesEnabled(true);
    d->stack->layout()->setEnabled(true);
    d->stack->layout()->activate();
}

QTabBar::Shape _q_tb_tabBarShapeFrom(QTabWidget::TabShape shape, QTabWidget::TabPosition position)
{
    const bool rounded = (shape == QTabWidget::Rounded);
    if (position == QTabWidget::North)
        return rounded ? QTabBar::RoundedNorth : QTabBar::TriangularNorth;
    if (position == QTabWidget::South)
        return rounded ? QTabBar::RoundedSouth : QTabBar::TriangularSouth;
    if (position == QTabWidget::East)
        return rounded ? QTabBar::RoundedEast : QTabBar::TriangularEast;
    if (position == QTabWidget::West)
        return rounded ? QTabBar::RoundedWest : QTabBar::TriangularWest;
    return QTabBar::RoundedNorth;
}

QT_END_NAMESPACE

#include "moc_qtabwidget.cpp"
