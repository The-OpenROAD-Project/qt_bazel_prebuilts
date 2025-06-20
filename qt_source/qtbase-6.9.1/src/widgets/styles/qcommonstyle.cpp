// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcommonstyle.h"
#include "qcommonstyle_p.h"

#include <qfile.h>
#if QT_CONFIG(itemviews)
#include <qabstractitemview.h>
#endif
#include <qapplication.h>
#include <private/qguiapplication_p.h>
#include <qpa/qplatformtheme.h>
#include <qbitmap.h>
#include <qcache.h>
#if QT_CONFIG(dockwidget)
#include <qdockwidget.h>
#endif
#include <qdrawutil.h>
#if QT_CONFIG(dialogbuttonbox)
#include <qdialogbuttonbox.h>
#endif
#if QT_CONFIG(formlayout)
#include <qformlayout.h>
#else
#include <qlayout.h>
#endif
#if QT_CONFIG(groupbox)
#include <qgroupbox.h>
#endif
#include <qmath.h>
#if QT_CONFIG(menu)
#include <qmenu.h>
#endif
#include <qpainter.h>
#include <qpaintengine.h>
#include <qpainterpath.h>
#include <qpainterstateguard.h>
#if QT_CONFIG(slider)
#include <qslider.h>
#endif
#include <qstyleoption.h>
#if QT_CONFIG(tabbar)
#include <qtabbar.h>
#endif
#if QT_CONFIG(tabwidget)
#include <qtabwidget.h>
#endif
#if QT_CONFIG(toolbar)
#include <qtoolbar.h>
#endif
#if QT_CONFIG(toolbutton)
#include <qtoolbutton.h>
#endif
#if QT_CONFIG(rubberband)
#include <qrubberband.h>
#endif
#if QT_CONFIG(treeview)
#include "qtreeview.h"
#endif
#include <private/qcommonstylepixmaps_p.h>
#include <private/qmath_p.h>
#include <qdebug.h>
#include <qtextformat.h>
#if QT_CONFIG(wizard)
#include <qwizard.h>
#endif
#if QT_CONFIG(filedialog)
#include <qsidebar_p.h>
#endif
#include <qfileinfo.h>
#include <qdir.h>
#if QT_CONFIG(settings)
#include <qsettings.h>
#endif
#include <qvariant.h>
#include <qpixmapcache.h>
#if QT_CONFIG(animation)
#include <private/qstyleanimation_p.h>
#endif

#include <qloggingcategory.h>

#include <limits.h>

#include <private/qtextengine_p.h>
#include <private/qstylehelper_p.h>

QT_BEGIN_NAMESPACE

Q_STATIC_LOGGING_CATEGORY(lcCommonStyle, "qt.widgets.commonstyle");

using namespace Qt::StringLiterals;

/*!
    \class QCommonStyle
    \brief The QCommonStyle class encapsulates the common Look and Feel of a GUI.

    \ingroup appearance
    \inmodule QtWidgets

    This abstract class implements some of the widget's look and feel
    that is common to all GUI styles provided and shipped as part of
    Qt.

    Since QCommonStyle inherits QStyle, all of its functions are fully documented
    in the QStyle documentation.
    \omit
    , although the
    extra functions that QCommonStyle provides, e.g.
    drawComplexControl(), drawControl(), drawPrimitive(),
    hitTestComplexControl(), subControlRect(), sizeFromContents(), and
    subElementRect() are documented here.
    \endomit

    \sa QStyle, QProxyStyle
*/

/*!
    Constructs a QCommonStyle.
*/
QCommonStyle::QCommonStyle()
    : QStyle(*new QCommonStylePrivate)
{ }

/*! \internal
*/
QCommonStyle::QCommonStyle(QCommonStylePrivate &dd)
    : QStyle(dd)
{ }

/*!
    Destroys the style.
*/
QCommonStyle::~QCommonStyle()
{ }


/*!
    \reimp
*/
void QCommonStyle::drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p,
                                 const QWidget *widget) const
{
    Q_D(const QCommonStyle);
    switch (pe) {
    case PE_FrameButtonBevel:
    case PE_FrameButtonTool:
        qDrawShadeRect(p, opt->rect, opt->palette,
                       opt->state & (State_Sunken | State_On), 1, 0);
        break;
    case PE_PanelButtonCommand:
    case PE_PanelButtonBevel:
    case PE_PanelButtonTool:
    case PE_IndicatorButtonDropDown:
        qDrawShadePanel(p, opt->rect, opt->palette,
                        opt->state & (State_Sunken | State_On), 1,
                        &opt->palette.brush(QPalette::Button));
        break;
    case PE_IndicatorItemViewItemCheck:
        proxy()->drawPrimitive(PE_IndicatorCheckBox, opt, p, widget);
        break;
    case PE_IndicatorCheckBox:
        if (opt->state & State_NoChange) {
            p->setPen(opt->palette.windowText().color());
            p->fillRect(opt->rect, opt->palette.brush(QPalette::Button));
            p->drawRect(opt->rect);
            p->drawLine(opt->rect.topLeft(), opt->rect.bottomRight());
        } else {
            qDrawShadePanel(p, opt->rect.x(), opt->rect.y(), opt->rect.width(), opt->rect.height(),
                            opt->palette, opt->state & (State_Sunken | State_On), 1,
                            &opt->palette.brush(QPalette::Button));
        }
        break;
    case PE_IndicatorRadioButton: {
        QRect ir = opt->rect;
        p->setPen(opt->palette.dark().color());
        p->drawArc(opt->rect, 0, 5760);
        if (opt->state & (State_Sunken | State_On)) {
            ir.adjust(2, 2, -2, -2);
            p->setBrush(opt->palette.windowText());
            p->drawEllipse(ir);
        }
        break; }
    case PE_FrameFocusRect:
        if (const QStyleOptionFocusRect *fropt = qstyleoption_cast<const QStyleOptionFocusRect *>(opt)) {
            QColor bg = fropt->backgroundColor;
            QColor color;
            if (bg.isValid()) {
                int h, s, v;
                bg.getHsv(&h, &s, &v);
                if (v >= 128)
                    color = Qt::black;
                else
                    color = Qt::white;
            } else {
                color = opt->palette.windowText().color();
            }
            const QRect focusRect = opt->rect.adjusted(1, 1, -1, -1);
            qDrawPlainRect(p, focusRect, color, 1);
        }
        break;
    case PE_IndicatorMenuCheckMark: {
        const int markW = opt->rect.width() > 7 ? 7 : opt->rect.width();
        const int markH = markW;
        int posX = opt->rect.x() + (opt->rect.width() - markW)/2 + 1;
        int posY = opt->rect.y() + (opt->rect.height() - markH)/2;

        QList<QLineF> a;
        a.reserve(markH);

        int i, xx, yy;
        xx = posX;
        yy = 3 + posY;
        for (i = 0; i < markW/2; ++i) {
            a << QLineF(xx, yy, xx, yy + 2);
            ++xx;
            ++yy;
        }
        yy -= 2;
        for (; i < markH; ++i) {
            a << QLineF(xx, yy, xx, yy + 2);
            ++xx;
            --yy;
        }
        if (!(opt->state & State_Enabled) && !(opt->state & State_On)) {
            QPainterStateGuard psg(p);
            p->translate(1, 1);
            p->setPen(opt->palette.light().color());
            p->drawLines(a);
        }
        p->setPen((opt->state & State_On) ? opt->palette.highlightedText().color() : opt->palette.text().color());
        p->drawLines(a);
        break; }
    case PE_Frame:
    case PE_FrameMenu:
        if (const QStyleOptionFrame *frame = qstyleoption_cast<const QStyleOptionFrame *>(opt)) {
            if (pe == PE_FrameMenu || (frame->state & State_Sunken) || (frame->state & State_Raised)) {
                qDrawShadePanel(p, frame->rect, frame->palette, frame->state & State_Sunken,
                                frame->lineWidth);
            } else {
                qDrawPlainRect(p, frame->rect, frame->palette.windowText().color(), frame->lineWidth);
            }
        }
        break;
#if QT_CONFIG(toolbar)
    case PE_PanelMenuBar:
        if (widget && qobject_cast<QToolBar *>(widget->parentWidget()))
            break;
        if (const QStyleOptionFrame *frame = qstyleoption_cast<const QStyleOptionFrame *>(opt)){
            qDrawShadePanel(p, frame->rect, frame->palette, false, frame->lineWidth,
                            &frame->palette.brush(QPalette::Button));

        }
        else if (const QStyleOptionToolBar *frame = qstyleoption_cast<const QStyleOptionToolBar *>(opt)){
            qDrawShadePanel(p, frame->rect, frame->palette, false, frame->lineWidth,
                            &frame->palette.brush(QPalette::Button));
        }

        break;
   case PE_PanelMenu:
        break;
    case PE_PanelToolBar:
       break;
#endif // QT_CONFIG(toolbar)
#if QT_CONFIG(progressbar)
    case PE_IndicatorProgressChunk:
        {
            bool vertical = false;
            if (const QStyleOptionProgressBar *pb = qstyleoption_cast<const QStyleOptionProgressBar *>(opt))
                vertical = !(pb->state & QStyle::State_Horizontal);
            if (!vertical) {
                p->fillRect(opt->rect.x(), opt->rect.y() + 3, opt->rect.width() -2, opt->rect.height() - 6,
                            opt->palette.brush(QPalette::Highlight));
            } else {
                p->fillRect(opt->rect.x() + 2, opt->rect.y(), opt->rect.width() -6, opt->rect.height() - 2,
                            opt->palette.brush(QPalette::Highlight));
            }
        }
        break;
#endif // QT_CONFIG(progressbar)
    case PE_IndicatorBranch: {
        static const int decoration_size = 9;
        int mid_h = opt->rect.x() + opt->rect.width() / 2;
        int mid_v = opt->rect.y() + opt->rect.height() / 2;
        int bef_h = mid_h;
        int bef_v = mid_v;
        int aft_h = mid_h;
        int aft_v = mid_v;
        if (opt->state & State_Children) {
            int delta = decoration_size / 2;
            bef_h -= delta;
            bef_v -= delta;
            aft_h += delta;
            aft_v += delta;
            p->drawLine(bef_h + 2, bef_v + 4, bef_h + 6, bef_v + 4);
            if (!(opt->state & State_Open))
                p->drawLine(bef_h + 4, bef_v + 2, bef_h + 4, bef_v + 6);
            QPen oldPen = p->pen();
            p->setPen(opt->palette.dark().color());
            p->drawRect(bef_h, bef_v, decoration_size - 1, decoration_size - 1);
            p->setPen(oldPen);
        }
        QBrush brush(opt->palette.dark().color(), Qt::Dense4Pattern);
        if (opt->state & State_Item) {
            if (opt->direction == Qt::RightToLeft)
                p->fillRect(opt->rect.left(), mid_v, bef_h - opt->rect.left(), 1, brush);
            else
                p->fillRect(aft_h, mid_v, opt->rect.right() - aft_h + 1, 1, brush);
        }
        if (opt->state & State_Sibling)
            p->fillRect(mid_h, aft_v, 1, opt->rect.bottom() - aft_v + 1, brush);
        if (opt->state & (State_Open | State_Children | State_Item | State_Sibling))
            p->fillRect(mid_h, opt->rect.y(), 1, bef_v - opt->rect.y(), brush);
        break; }
    case PE_FrameStatusBarItem:
        qDrawShadeRect(p, opt->rect, opt->palette, true, 1, 0, nullptr);
        break;
    case PE_IndicatorHeaderArrow:
        if (const QStyleOptionHeader *header = qstyleoption_cast<const QStyleOptionHeader *>(opt)) {
            QPen oldPen = p->pen();
            if (header->sortIndicator & QStyleOptionHeader::SortUp) {
                p->setPen(QPen(opt->palette.light(), 0));
                p->drawLine(opt->rect.x() + opt->rect.width(), opt->rect.y(),
                            opt->rect.x() + opt->rect.width() / 2, opt->rect.y() + opt->rect.height());
                p->setPen(QPen(opt->palette.dark(), 0));
                const QPoint points[] = {
                    QPoint(opt->rect.x() + opt->rect.width() / 2, opt->rect.y() + opt->rect.height()),
                    QPoint(opt->rect.x(), opt->rect.y()),
                    QPoint(opt->rect.x() + opt->rect.width(), opt->rect.y()),
                };
                p->drawPolyline(points, sizeof points / sizeof *points);
            } else if (header->sortIndicator & QStyleOptionHeader::SortDown) {
                p->setPen(QPen(opt->palette.light(), 0));
                const QPoint points[] = {
                    QPoint(opt->rect.x(), opt->rect.y() + opt->rect.height()),
                    QPoint(opt->rect.x() + opt->rect.width(), opt->rect.y() + opt->rect.height()),
                    QPoint(opt->rect.x() + opt->rect.width() / 2, opt->rect.y()),
                };
                p->drawPolyline(points, sizeof points / sizeof *points);
                p->setPen(QPen(opt->palette.dark(), 0));
                p->drawLine(opt->rect.x(), opt->rect.y() + opt->rect.height(),
                            opt->rect.x() + opt->rect.width() / 2, opt->rect.y());
            }
            p->setPen(oldPen);
        }
        break;
#if QT_CONFIG(tabbar)
    case PE_FrameTabBarBase:
        if (const QStyleOptionTabBarBase *tbb
                = qstyleoption_cast<const QStyleOptionTabBarBase *>(opt)) {
            QPainterStateGuard psg(p);
            switch (tbb->shape) {
            case QTabBar::RoundedNorth:
            case QTabBar::TriangularNorth:
                p->setPen(QPen(tbb->palette.light(), 0));
                p->drawLine(tbb->rect.topLeft(), tbb->rect.topRight());
                break;
            case QTabBar::RoundedWest:
            case QTabBar::TriangularWest:
                p->setPen(QPen(tbb->palette.light(), 0));
                p->drawLine(tbb->rect.topLeft(), tbb->rect.bottomLeft());
                break;
            case QTabBar::RoundedSouth:
            case QTabBar::TriangularSouth:
                p->setPen(QPen(tbb->palette.shadow(), 0));
                p->drawLine(tbb->rect.left(), tbb->rect.bottom(),
                            tbb->rect.right(), tbb->rect.bottom());
                p->setPen(QPen(tbb->palette.dark(), 0));
                p->drawLine(tbb->rect.left(), tbb->rect.bottom() - 1,
                            tbb->rect.right() - 1, tbb->rect.bottom() - 1);
                break;
            case QTabBar::RoundedEast:
            case QTabBar::TriangularEast:
                p->setPen(QPen(tbb->palette.dark(), 0));
                p->drawLine(tbb->rect.topRight(), tbb->rect.bottomRight());
                break;
            }
        }
        break;
    case PE_IndicatorTabClose: {
        if (d->tabBarcloseButtonIcon.isNull())
            d->tabBarcloseButtonIcon = proxy()->standardIcon(QStyle::SP_TabCloseButton, opt, widget);

        const int size = proxy()->pixelMetric(QStyle::PM_SmallIconSize, opt, widget);
        QIcon::Mode mode = opt->state & State_Enabled ?
                            (opt->state & State_Raised ? QIcon::Active : QIcon::Normal)
                            : QIcon::Disabled;
        if (!(opt->state & State_Raised)
            && !(opt->state & State_Sunken)
            && !(opt->state & QStyle::State_Selected))
            mode = QIcon::Disabled;

        QIcon::State state = opt->state & State_Sunken ? QIcon::On : QIcon::Off;
        QPixmap pixmap = d->tabBarcloseButtonIcon.pixmap(QSize(size, size), QStyleHelper::getDpr(p), mode, state);
        proxy()->drawItemPixmap(p, opt->rect, Qt::AlignCenter, pixmap);
        break;
    }
#else
    Q_UNUSED(d);
#endif // QT_CONFIG(tabbar)
    case PE_FrameTabWidget:
    case PE_FrameWindow:
        qDrawWinPanel(p, opt->rect, opt->palette, false, nullptr);
        break;
    case PE_FrameLineEdit:
        proxy()->drawPrimitive(PE_Frame, opt, p, widget);
        break;
#if QT_CONFIG(groupbox)
    case PE_FrameGroupBox:
        if (const QStyleOptionFrame *frame = qstyleoption_cast<const QStyleOptionFrame *>(opt)) {
            if (frame->features & QStyleOptionFrame::Flat) {
                QRect fr = frame->rect;
                QPoint p1(fr.x(), fr.y() + 1);
                QPoint p2(fr.x() + fr.width(), p1.y());
                qDrawShadeLine(p, p1, p2, frame->palette, true,
                               frame->lineWidth, frame->midLineWidth);
            } else {
                qDrawShadeRect(p, frame->rect.x(), frame->rect.y(), frame->rect.width(),
                               frame->rect.height(), frame->palette, true,
                               frame->lineWidth, frame->midLineWidth);
            }
        }
        break;
#endif // QT_CONFIG(groupbox)
#if QT_CONFIG(dockwidget)
    case PE_FrameDockWidget:
        if (const QStyleOptionFrame *frame = qstyleoption_cast<const QStyleOptionFrame *>(opt)) {
            int lw = frame->lineWidth;
            if (lw <= 0)
                lw = proxy()->pixelMetric(PM_DockWidgetFrameWidth, opt, widget);

            qDrawShadePanel(p, frame->rect, frame->palette, false, lw);
        }
        break;
#endif // QT_CONFIG(dockwidget)
#if QT_CONFIG(toolbar)
    case PE_IndicatorToolBarHandle: {
        QPainterStateGuard psg(p);
        p->translate(opt->rect.x(), opt->rect.y());
        if (opt->state & State_Horizontal) {
            int x = opt->rect.width() / 3;
            if (opt->direction == Qt::RightToLeft)
                x -= 2;
            if (opt->rect.height() > 4) {
                qDrawShadePanel(p, x, 2, 3, opt->rect.height() - 4,
                                opt->palette, false, 1, nullptr);
                qDrawShadePanel(p, x+3, 2, 3, opt->rect.height() - 4,
                                opt->palette, false, 1, nullptr);
            }
        } else {
            if (opt->rect.width() > 4) {
                int y = opt->rect.height() / 3;
                qDrawShadePanel(p, 2, y, opt->rect.width() - 4, 3,
                                opt->palette, false, 1, nullptr);
                qDrawShadePanel(p, 2, y+3, opt->rect.width() - 4, 3,
                                opt->palette, false, 1, nullptr);
            }
        }
        break;
    }
    case PE_IndicatorToolBarSeparator:
        {
            QPoint p1, p2;
            if (opt->state & State_Horizontal) {
                p1 = QPoint(opt->rect.width()/2, 0);
                p2 = QPoint(p1.x(), opt->rect.height());
            } else {
                p1 = QPoint(0, opt->rect.height()/2);
                p2 = QPoint(opt->rect.width(), p1.y());
            }
            qDrawShadeLine(p, p1, p2, opt->palette, 1, 1, 0);
            break;
        }
#endif // QT_CONFIG(toolbar)
#if QT_CONFIG(spinbox)
    case PE_IndicatorSpinPlus:
    case PE_IndicatorSpinMinus: {
        QRect r = opt->rect;
        int fw = proxy()->pixelMetric(PM_DefaultFrameWidth, opt, widget);
        QRect br = r.adjusted(fw, fw, -fw, -fw);
        int x = br.x();
        int y = br.y();
        int w = br.width();
        int h = br.height();
        QPainterStateGuard psg(p);
        const qreal devicePixelRatio = QStyleHelper::getDpr(p);
        if (!qFuzzyCompare(devicePixelRatio, qreal(1))) {
            const qreal inverseScale = qreal(1) / devicePixelRatio;
            p->scale(inverseScale, inverseScale);
            x = qRound(devicePixelRatio * x);
            y = qRound(devicePixelRatio * y);
            w = qRound(devicePixelRatio * w);
            h = qRound(devicePixelRatio * h);
            p->translate(0.5, 0.5);
        }
        int len = std::min(w, h);
        if (len & 1)
            ++len;
        int step = (len + 4) / 5;
        if (step & 1)
            ++step;
        const int step2 = step / 2;
        QPoint center(x + w / 2, y + h / 2);
        if (opt->state & State_Sunken) {
            center += QPoint(proxy()->pixelMetric(PM_ButtonShiftHorizontal, opt, widget),
                             proxy()->pixelMetric(PM_ButtonShiftVertical, opt, widget));
        }
        p->translate(center);
        p->fillRect(-len / 2, -step2, len, step, opt->palette.buttonText());
        if (pe == PE_IndicatorSpinPlus)
            p->fillRect(-step2, -len / 2, step, len, opt->palette.buttonText());
        break; }
    case PE_IndicatorSpinUp:
    case PE_IndicatorSpinDown: {
        QRect r = opt->rect;
        int fw = proxy()->pixelMetric(PM_DefaultFrameWidth, opt, widget);
        // QRect br = r.adjusted(fw, fw, -fw, -fw);
        int x = r.x();
        int y = r.y();
        int w = r.width();
        int h = r.height();
        QPainterStateGuard psg(p);
        const qreal devicePixelRatio = QStyleHelper::getDpr(p);
        if (!qFuzzyCompare(devicePixelRatio, qreal(1))) {
            const qreal inverseScale = qreal(1) / devicePixelRatio;
            p->scale(inverseScale, inverseScale);
            x = qRound(devicePixelRatio * x);
            y = qRound(devicePixelRatio * y);
            w = qRound(devicePixelRatio * w);
            h = qRound(devicePixelRatio * h);
            p->translate(0.5, 0.5);
        }
        int sw = w-4;
        if (sw < 3)
            break;
        else if (!(sw & 1))
            sw--;
        sw -= (sw / 7) * 2;        // Empty border
        int sh = sw/2 + 2;      // Must have empty row at foot of arrow

        int sx = x + w / 2 - sw / 2;
        int sy = y + h / 2 - sh / 2;

        if (pe == PE_IndicatorSpinUp && fw)
            --sy;

        int bsx = 0;
        int bsy = 0;
        if (opt->state & State_Sunken) {
            bsx = proxy()->pixelMetric(PM_ButtonShiftHorizontal, opt, widget);
            bsy = proxy()->pixelMetric(PM_ButtonShiftVertical, opt, widget);
        }
        p->translate(sx + bsx, sy + bsy);
        p->setPen(opt->palette.buttonText().color());
        p->setBrush(opt->palette.buttonText());
        if (pe == PE_IndicatorSpinDown) {
            const QPoint points[] = { QPoint(0, 1), QPoint(sw-1, 1), QPoint(sh-2, sh-1) };
            p->drawPolygon(points, sizeof points / sizeof *points);
        } else {
            const QPoint points[] = { QPoint(0, sh-1), QPoint(sw-1, sh-1), QPoint(sh-2, 1) };
            p->drawPolygon(points, sizeof points / sizeof *points);
        }
        break; }
#endif // QT_CONFIG(spinbox)
    case PE_PanelTipLabel: {
        const QBrush brush(opt->palette.toolTipBase());
        qDrawPlainRect(p, opt->rect, opt->palette.toolTipText().color(), 1, &brush);
        break;
    }
#if QT_CONFIG(tabbar)
    case PE_IndicatorTabTear:
        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(opt)) {
            bool rtl = tab->direction == Qt::RightToLeft;
            const bool horizontal = tab->rect.height() > tab->rect.width();
            const int margin = 4;
            QPainterPath path;

            if (horizontal) {
                QRect rect = tab->rect.adjusted(rtl ? margin : 0, 0, rtl ? 1 : -margin, 0);
                rect.setTop(rect.top() + ((tab->state & State_Selected) ? 1 : 3));
                rect.setBottom(rect.bottom() - ((tab->state & State_Selected) ? 0 : 2));

                path.moveTo(QPoint(rtl ? rect.right() : rect.left(), rect.top()));
                int count = 4;
                for (int jags = 1; jags <= count; ++jags, rtl = !rtl)
                    path.lineTo(QPoint(rtl ? rect.left() : rect.right(), rect.top() + jags * rect.height()/count));
            } else {
                QRect rect = tab->rect.adjusted(0, 0, 0, -margin);
                rect.setLeft(rect.left() + ((tab->state & State_Selected) ? 1 : 3));
                rect.setRight(rect.right() - ((tab->state & State_Selected) ? 0 : 2));

                path.moveTo(QPoint(rect.left(), rect.top()));
                int count = 4;
                for (int jags = 1; jags <= count; ++jags, rtl = !rtl)
                    path.lineTo(QPoint(rect.left() + jags * rect.width()/count, rtl ? rect.top() : rect.bottom()));
            }

            p->setPen(QPen(tab->palette.dark(), qreal(.8)));
            p->setBrush(tab->palette.window());
            p->setRenderHint(QPainter::Antialiasing);
            p->drawPath(path);
        }
        break;
#endif // QT_CONFIG(tabbar)
#if QT_CONFIG(lineedit)
    case PE_PanelLineEdit:
        if (const QStyleOptionFrame *panel = qstyleoption_cast<const QStyleOptionFrame *>(opt)) {
            p->fillRect(panel->rect.adjusted(panel->lineWidth, panel->lineWidth, -panel->lineWidth, -panel->lineWidth),
                        panel->palette.brush(QPalette::Base));

            if (panel->lineWidth > 0)
                proxy()->drawPrimitive(PE_FrameLineEdit, panel, p, widget);
        }
        break;
#endif // QT_CONFIG(lineedit)
#if QT_CONFIG(columnview)
    case PE_IndicatorColumnViewArrow: {
    if (const QStyleOptionViewItem *viewOpt = qstyleoption_cast<const QStyleOptionViewItem *>(opt)) {
        bool reverse = (viewOpt->direction == Qt::RightToLeft);
        QPainterStateGuard psg(p);
        QPainterPath path;
        int x = viewOpt->rect.x() + 1;
        int offset = (viewOpt->rect.height() / 3);
        int height = (viewOpt->rect.height()) - offset * 2;
        if (height % 2 == 1)
            --height;
        int x2 = x + height - 1;
        if (reverse) {
            x = viewOpt->rect.x() + viewOpt->rect.width() - 1;
            x2 = x - height + 1;
        }
        path.moveTo(x, viewOpt->rect.y() + offset);
        path.lineTo(x, viewOpt->rect.y() + offset + height);
        path.lineTo(x2, viewOpt->rect.y() + offset+height/2);
        path.closeSubpath();
        if (viewOpt->state & QStyle::State_Selected ) {
            if (viewOpt->showDecorationSelected) {
                QColor color = viewOpt->palette.color(QPalette::Active, QPalette::HighlightedText);
                p->setPen(color);
                p->setBrush(color);
            } else {
                QColor color = viewOpt->palette.color(QPalette::Active, QPalette::WindowText);
                p->setPen(color);
                p->setBrush(color);
            }

        } else {
            QColor color = viewOpt->palette.color(QPalette::Active, QPalette::Mid);
            p->setPen(color);
            p->setBrush(color);
        }
        p->drawPath(path);

        // draw the vertical and top triangle line
        if (!(viewOpt->state & QStyle::State_Selected)) {
            QPainterPath lines;
            lines.moveTo(x, viewOpt->rect.y() + offset);
            lines.lineTo(x, viewOpt->rect.y() + offset + height);
            lines.moveTo(x, viewOpt->rect.y() + offset);
            lines.lineTo(x2, viewOpt->rect.y() + offset+height/2);
            QColor color = viewOpt->palette.color(QPalette::Active, QPalette::Dark);
            p->setPen(color);
            p->drawPath(lines);
        }
    }
    break; }
#endif //QT_CONFIG(columnview)
    case PE_IndicatorItemViewItemDrop: {
        QRect rect = opt->rect;
        if (opt->rect.height() == 0)
            p->drawLine(rect.topLeft(), rect.topRight());
        else
            p->drawRect(rect);
        break; }
#if QT_CONFIG(itemviews)
    case PE_PanelItemViewRow:
        if (const QStyleOptionViewItem *vopt = qstyleoption_cast<const QStyleOptionViewItem *>(opt)) {
            QPalette::ColorGroup cg = (widget ? widget->isEnabled() : (vopt->state & QStyle::State_Enabled))
                                      ? QPalette::Normal : QPalette::Disabled;
            if (cg == QPalette::Normal && !(vopt->state & QStyle::State_Active))
                cg = QPalette::Inactive;

            if ((vopt->state & QStyle::State_Selected) && vopt->showDecorationSelected)
                p->fillRect(vopt->rect, vopt->palette.brush(cg, QPalette::Highlight));
            else if (vopt->features & QStyleOptionViewItem::Alternate)
                p->fillRect(vopt->rect, vopt->palette.brush(cg, QPalette::AlternateBase));
        }
        break;
    case PE_PanelItemViewItem:
        if (const QStyleOptionViewItem *vopt = qstyleoption_cast<const QStyleOptionViewItem *>(opt)) {
            QPalette::ColorGroup cg = (widget ? widget->isEnabled() : (vopt->state & QStyle::State_Enabled))
                                      ? QPalette::Normal : QPalette::Disabled;
            if (cg == QPalette::Normal && !(vopt->state & QStyle::State_Active))
                cg = QPalette::Inactive;

            if (vopt->showDecorationSelected && (vopt->state & QStyle::State_Selected)) {
                p->fillRect(vopt->rect, vopt->palette.brush(cg, QPalette::Highlight));
            } else {
                if (vopt->backgroundBrush.style() != Qt::NoBrush) {
                    QPointF oldBO = p->brushOrigin();
                    p->setBrushOrigin(vopt->rect.topLeft());
                    p->fillRect(vopt->rect, vopt->backgroundBrush);
                    p->setBrushOrigin(oldBO);
                }

                if (vopt->state & QStyle::State_Selected) {
                    QRect textRect = subElementRect(QStyle::SE_ItemViewItemText,  opt, widget);
                    p->fillRect(textRect, vopt->palette.brush(cg, QPalette::Highlight));
                }
            }
        }
        break;
#endif // QT_CONFIG(itemviews)
    case PE_PanelScrollAreaCorner: {
        const QBrush brush(opt->palette.brush(QPalette::Window));
        p->fillRect(opt->rect, brush);
        } break;
    case PE_IndicatorArrowUp:
    case PE_IndicatorArrowDown:
    case PE_IndicatorArrowRight:
    case PE_IndicatorArrowLeft:
        {
            const QRect &r = opt->rect;
            if (r.width() <= 1 || r.height() <= 1)
                break;
            int size = qMin(r.height(), r.width());
            QPixmap pixmap;
            const qreal dpr = QStyleHelper::getDpr(p);
            const QString pixmapName = QStyleHelper::uniqueName("$qt_ia-"_L1
                                                     % QLatin1StringView(metaObject()->className())
                                                     % HexString<uint>(pe),
                                             opt, QSize(size, size), dpr);
            if (!QPixmapCache::find(pixmapName, &pixmap)) {
                // dpr scaling does not work well on such small pixel sizes, do it on our own
                const int border = 1 * dpr;
                const int sizeDpr = size * dpr;
                int width = sizeDpr - 2 * border - 1;
                int height = width / 2;
                const int add = ((width & 1) == 1);
                if (pe == PE_IndicatorArrowRight || pe == PE_IndicatorArrowLeft)
                    std::swap(width, height);
                pixmap = styleCachePixmap(QSize(sizeDpr, sizeDpr), 1);

                std::array<QPointF, 4> poly;
                switch (pe) {
                    case PE_IndicatorArrowUp:
                        poly = {QPointF(0, height), QPointF(width, height),
                                QPointF(width / 2 + add, 0), QPointF(width / 2, 0)};
                        break;
                    case PE_IndicatorArrowDown:
                        poly = {QPointF(0, 0), QPointF(width, 0),
                                QPointF(width / 2 + add, height), QPointF(width / 2, height)};
                        break;
                    case PE_IndicatorArrowRight:
                        poly = {QPointF(0, 0), QPointF(0, height),
                                QPointF(width, height / 2 + add), QPointF(width, height / 2)};
                        break;
                    case PE_IndicatorArrowLeft:
                        poly = {QPointF(width, 0), QPointF(width, height),
                                QPointF(0, height / 2 + add), QPointF(0, height / 2)};
                        break;
                    default:
                        break;
                }

                QPainter imagePainter(&pixmap);
                imagePainter.translate((sizeDpr - width) / 2, (sizeDpr - height) / 2);
                if (opt->state & State_Sunken) {
                    const auto bsx = proxy()->pixelMetric(PM_ButtonShiftHorizontal, opt, widget);
                    const auto bsy = proxy()->pixelMetric(PM_ButtonShiftVertical, opt, widget);
                    imagePainter.translate(bsx, bsy);
                }
                imagePainter.setPen(opt->palette.buttonText().color());
                imagePainter.setBrush(opt->palette.buttonText());

                if (!(opt->state & State_Enabled)) {
                    const int ofs = qRound(1 * dpr);
                    imagePainter.translate(ofs, ofs);
                    imagePainter.setBrush(opt->palette.light());
                    imagePainter.setPen(opt->palette.light().color());
                    imagePainter.drawPolygon(poly.data(), int(poly.size()));
                    imagePainter.drawPoints(poly.data(), int(poly.size()));
                    imagePainter.translate(-ofs, -ofs);
                    imagePainter.setBrush(opt->palette.mid());
                    imagePainter.setPen(opt->palette.mid().color());
                }
                imagePainter.drawPolygon(poly.data(), int(poly.size()));
                // sometimes the corners are not drawn by drawPolygon for unknown reaons, so re-draw them again
                imagePainter.drawPoints(poly.data(), int(poly.size()));
                imagePainter.end();
                pixmap.setDevicePixelRatio(dpr);
                QPixmapCache::insert(pixmapName, pixmap);
            }
            int xOffset = r.x() + (r.width() - size)/2;
            int yOffset = r.y() + (r.height() - size)/2;
            p->drawPixmap(xOffset, yOffset, pixmap);
        }
        break;
    default:
        break;
    }
}

#if QT_CONFIG(toolbutton)
static void drawArrow(const QStyle *style, const QStyleOptionToolButton *toolbutton,
                      const QRect &rect, QPainter *painter, const QWidget *widget = nullptr)
{
    QStyle::PrimitiveElement pe;
    switch (toolbutton->arrowType) {
    case Qt::LeftArrow:
        pe = QStyle::PE_IndicatorArrowLeft;
        break;
    case Qt::RightArrow:
        pe = QStyle::PE_IndicatorArrowRight;
        break;
    case Qt::UpArrow:
        pe = QStyle::PE_IndicatorArrowUp;
        break;
    case Qt::DownArrow:
        pe = QStyle::PE_IndicatorArrowDown;
        break;
    default:
        return;
    }
    QStyleOption arrowOpt = *toolbutton;
    arrowOpt.rect = rect;
    style->drawPrimitive(pe, &arrowOpt, painter, widget);
}
#endif // QT_CONFIG(toolbutton)

static QSizeF viewItemTextLayout(QTextLayout &textLayout, int lineWidth, int maxHeight = -1, int *lastVisibleLine = nullptr)
{
    if (lastVisibleLine)
        *lastVisibleLine = -1;
    qreal height = 0;
    qreal widthUsed = 0;
    textLayout.beginLayout();
    int i = 0;
    while (true) {
        QTextLine line = textLayout.createLine();
        if (!line.isValid())
            break;
        line.setLineWidth(lineWidth);
        line.setPosition(QPointF(0, height));
        height += line.height();
        widthUsed = qMax(widthUsed, line.naturalTextWidth());
        // we assume that the height of the next line is the same as the current one
        if (maxHeight > 0 && lastVisibleLine && height + line.height() > maxHeight) {
            const QTextLine nextLine = textLayout.createLine();
            *lastVisibleLine = nextLine.isValid() ? i : -1;
            break;
        }
        ++i;
    }
    textLayout.endLayout();
    return QSizeF(widthUsed, height);
}

QString QCommonStylePrivate::calculateElidedText(const QString &text, const QTextOption &textOption,
                                                 const QFont &font, const QRect &textRect, const Qt::Alignment valign,
                                                 Qt::TextElideMode textElideMode, int flags,
                                                 bool lastVisibleLineShouldBeElided, QPointF *paintStartPosition) const
{
    QTextLayout textLayout(text, font);
    textLayout.setTextOption(textOption);

    // In AlignVCenter mode when more than one line is displayed and the height only allows
    // some of the lines it makes no sense to display those. From a users perspective it makes
    // more sense to see the start of the text instead something inbetween.
    const bool vAlignmentOptimization = paintStartPosition && valign.testFlag(Qt::AlignVCenter);

    int lastVisibleLine = -1;
    viewItemTextLayout(textLayout, textRect.width(), vAlignmentOptimization ? textRect.height() : -1, &lastVisibleLine);

    const QRectF boundingRect = textLayout.boundingRect();
    // don't care about LTR/RTL here, only need the height
    const QRect layoutRect = QStyle::alignedRect(Qt::LayoutDirectionAuto, valign,
                                                 boundingRect.size().toSize(), textRect);

    if (paintStartPosition)
        *paintStartPosition = QPointF(textRect.x(), layoutRect.top());

    QString ret;
    qreal height = 0;
    const int lineCount = textLayout.lineCount();
    for (int i = 0; i < lineCount; ++i) {
        const QTextLine line = textLayout.lineAt(i);
        height += line.height();

        // above visible rect
        if (height + layoutRect.top() <= textRect.top()) {
            if (paintStartPosition)
                paintStartPosition->ry() += line.height();
            continue;
        }

        const int start = line.textStart();
        const int length = line.textLength();
        const bool drawElided = line.naturalTextWidth() > textRect.width();
        bool elideLastVisibleLine = lastVisibleLine == i;
        if (!drawElided && i + 1 < lineCount && lastVisibleLineShouldBeElided) {
            const QTextLine nextLine = textLayout.lineAt(i + 1);
            const int nextHeight = height + nextLine.height() / 2;
            // elide when less than the next half line is visible
            if (nextHeight + layoutRect.top() > textRect.height() + textRect.top())
                elideLastVisibleLine = true;
        }

        QString text = textLayout.text().mid(start, length);
        if (drawElided || elideLastVisibleLine) {
            if (elideLastVisibleLine) {
                if (text.endsWith(QChar::LineSeparator))
                    text.chop(1);
                text += QChar(0x2026);
            }
            Q_DECL_UNINITIALIZED const QStackTextEngine engine(text, font);
            ret += engine.elidedText(textElideMode, textRect.width(), flags);

            // no newline for the last line (last visible or real)
            // sometimes drawElided is true but no eliding is done so the text ends
            // with QChar::LineSeparator - don't add another one. This happened with
            // arabic text in the testcase for QTBUG-72805
            if (i < lineCount - 1 &&
                !ret.endsWith(QChar::LineSeparator))
                ret += QChar::LineSeparator;
        } else {
            ret += text;
        }

        // below visible text, can stop
        if ((height + layoutRect.top() >= textRect.bottom()) ||
                (lastVisibleLine >= 0 && lastVisibleLine == i))
            break;
    }
    return ret;
}

#if QT_CONFIG(itemviews)

QSize QCommonStylePrivate::viewItemSize(const QStyleOptionViewItem *option, int role) const
{
    const QWidget *widget = option->widget;
    switch (role) {
    case Qt::CheckStateRole:
        if (option->features & QStyleOptionViewItem::HasCheckIndicator)
            return QSize(proxyStyle->pixelMetric(QStyle::PM_IndicatorWidth, option, widget),
                         proxyStyle->pixelMetric(QStyle::PM_IndicatorHeight, option, widget));
        break;
    case Qt::DisplayRole:
        if (option->features & QStyleOptionViewItem::HasDisplay) {
            QTextOption textOption;
            textOption.setWrapMode(QTextOption::WordWrap);
            QTextLayout textLayout(option->text, option->font);
            textLayout.setTextOption(textOption);
            const bool wrapText = option->features & QStyleOptionViewItem::WrapText;
            const int textMargin = proxyStyle->pixelMetric(QStyle::PM_FocusFrameHMargin, option, widget) + 1;
            QRect bounds = option->rect;
            switch (option->decorationPosition) {
            case QStyleOptionViewItem::Left:
            case QStyleOptionViewItem::Right: {
                if (wrapText && bounds.isValid()) {
                    int width = bounds.width() - 2 * textMargin;
                    if (option->features & QStyleOptionViewItem::HasDecoration)
                        width -= option->decorationSize.width() + 2 * textMargin;
                    bounds.setWidth(width);
                } else
                    bounds.setWidth(QFIXED_MAX);
                break;
            }
            case QStyleOptionViewItem::Top:
            case QStyleOptionViewItem::Bottom: {
                int width;
                if (wrapText) {
                    if (bounds.isValid())
                        width = bounds.width() - 2 * textMargin;
                    else if (option->features & QStyleOptionViewItem::HasDecoration)
                        width = option->decorationSize.width();
                    else
                        width = 0;
                } else {
                    width = QFIXED_MAX;
                }
                bounds.setWidth(width);
                break;
            }
            default:
                break;
            }

            if (wrapText && option->features & QStyleOptionViewItem::HasCheckIndicator)
                bounds.setWidth(bounds.width() - proxyStyle->pixelMetric(QStyle::PM_IndicatorWidth, option, widget) - 2 * textMargin);

            const int lineWidth = bounds.width();
            const QSizeF size = viewItemTextLayout(textLayout, lineWidth);
            return QSize(qCeil(size.width()) + 2 * textMargin, qCeil(size.height()));
        }
        break;
    case Qt::DecorationRole:
        if (option->features & QStyleOptionViewItem::HasDecoration) {
            return option->decorationSize;
        }
        break;
    default:
        break;
    }

    return QSize(0, 0);
}

void QCommonStylePrivate::viewItemDrawText(QPainter *p, const QStyleOptionViewItem *option, const QRect &rect) const
{
    const QWidget *widget = option->widget;
    const int textMargin = proxyStyle->pixelMetric(QStyle::PM_FocusFrameHMargin, nullptr, widget) + 1;

    QRect textRect = rect.adjusted(textMargin, 0, -textMargin, 0); // remove width padding
    const bool wrapText = option->features & QStyleOptionViewItem::WrapText;
    QTextOption textOption;
    textOption.setWrapMode(wrapText ? QTextOption::WordWrap : QTextOption::ManualWrap);
    textOption.setTextDirection(option->direction);
    textOption.setAlignment(QStyle::visualAlignment(option->direction, option->displayAlignment));

    QPointF paintPosition;
    const QString newText = calculateElidedText(option->text, textOption,
                                                option->font, textRect, option->displayAlignment,
                                                option->textElideMode, 0,
                                                true, &paintPosition);

    QTextLayout textLayout(newText, option->font);
    textLayout.setTextOption(textOption);
    viewItemTextLayout(textLayout, textRect.width());
    textLayout.draw(p, paintPosition);
}

/*! \internal
    compute the position for the different component of an item (pixmap, text, checkbox)

    Set sizehint to false to layout the elements inside opt->rect. Set sizehint to true to ignore
   opt->rect and return rectangles in infinite space

    Code duplicated in QItemDelegate::doLayout
*/
void QCommonStylePrivate::viewItemLayout(const QStyleOptionViewItem *opt,  QRect *checkRect,
                                         QRect *pixmapRect, QRect *textRect, bool sizehint) const
{
    Q_ASSERT(checkRect && pixmapRect && textRect);
    *pixmapRect = QRect(QPoint(0, 0), viewItemSize(opt, Qt::DecorationRole));
    *textRect = QRect(QPoint(0, 0), viewItemSize(opt, Qt::DisplayRole));
    *checkRect = QRect(QPoint(0, 0), viewItemSize(opt, Qt::CheckStateRole));

    const QWidget *widget = opt->widget;
    const bool hasCheck = checkRect->isValid();
    const bool hasPixmap = pixmapRect->isValid();
    const bool hasText = textRect->isValid();
    const bool hasMargin = (hasText | hasPixmap | hasCheck);
    const int frameHMargin = hasMargin ?
                proxyStyle->pixelMetric(QStyle::PM_FocusFrameHMargin, opt, widget) + 1 : 0;
    const int textMargin = hasText ? frameHMargin : 0;
    const int pixmapMargin = hasPixmap ? frameHMargin : 0;
    const int checkMargin = hasCheck ? frameHMargin : 0;
    const int x = opt->rect.left();
    const int y = opt->rect.top();
    int w, h;

    if (textRect->height() == 0 && (!hasPixmap || !sizehint)) {
        //if there is no text, we still want to have a decent height for the item sizeHint and the editor size
        textRect->setHeight(opt->fontMetrics.height());
    }

    QSize pm(0, 0);
    if (hasPixmap) {
        pm = pixmapRect->size();
        pm.rwidth() += 2 * pixmapMargin;
    }
    if (sizehint) {
        h = qMax(checkRect->height(), qMax(textRect->height(), pm.height()));
        if (opt->decorationPosition == QStyleOptionViewItem::Left
            || opt->decorationPosition == QStyleOptionViewItem::Right) {
            w = textRect->width() + pm.width();
        } else {
            w = qMax(textRect->width(), pm.width());
        }
    } else {
        w = opt->rect.width();
        h = opt->rect.height();
    }

    int cw = 0;
    QRect check;
    if (hasCheck) {
        cw = checkRect->width() + 2 * checkMargin;
        if (sizehint) w += cw;
        if (opt->direction == Qt::RightToLeft) {
            check.setRect(x + w - cw, y, cw, h);
        } else {
            check.setRect(x, y, cw, h);
        }
    }

    QRect display;
    QRect decoration;
    switch (opt->decorationPosition) {
    case QStyleOptionViewItem::Top: {
        if (hasPixmap)
            pm.setHeight(pm.height() + pixmapMargin); // add space
        h = sizehint ? textRect->height() : h - pm.height();

        if (opt->direction == Qt::RightToLeft) {
            decoration.setRect(x, y, w - cw, pm.height());
            display.setRect(x, y + pm.height(), w - cw, h);
        } else {
            decoration.setRect(x + cw, y, w - cw, pm.height());
            display.setRect(x + cw, y + pm.height(), w - cw, h);
        }
        break; }
    case QStyleOptionViewItem::Bottom: {
        if (hasText)
            textRect->setHeight(textRect->height() + textMargin); // add space
        h = sizehint ? textRect->height() + pm.height() : h;

        if (opt->direction == Qt::RightToLeft) {
            display.setRect(x, y, w - cw, textRect->height());
            decoration.setRect(x, y + textRect->height(), w - cw, h - textRect->height());
        } else {
            display.setRect(x + cw, y, w - cw, textRect->height());
            decoration.setRect(x + cw, y + textRect->height(), w - cw, h - textRect->height());
        }
        break; }
    case QStyleOptionViewItem::Left: {
        if (opt->direction == Qt::LeftToRight) {
            decoration.setRect(x + cw, y, pm.width(), h);
            display.setRect(decoration.right() + 1, y, w - pm.width() - cw, h);
        } else {
            display.setRect(x, y, w - pm.width() - cw, h);
            decoration.setRect(display.right() + 1, y, pm.width(), h);
        }
        break; }
    case QStyleOptionViewItem::Right: {
        if (opt->direction == Qt::LeftToRight) {
            display.setRect(x + cw, y, w - pm.width() - cw, h);
            decoration.setRect(display.right() + 1, y, pm.width(), h);
        } else {
            decoration.setRect(x, y, pm.width(), h);
            display.setRect(decoration.right() + 1, y, w - pm.width() - cw, h);
        }
        break; }
    default:
        qCWarning(lcCommonStyle, "doLayout: decoration position is invalid");
        decoration = *pixmapRect;
        break;
    }

    if (!sizehint) { // we only need to do the internal layout if we are going to paint
        *checkRect = QStyle::alignedRect(opt->direction, Qt::AlignCenter,
                                         checkRect->size(), check);
        *pixmapRect = QStyle::alignedRect(opt->direction, opt->decorationAlignment,
                                          pixmapRect->size(), decoration);
        // the textRect takes up all remaining size
        *textRect = display;
    } else {
        *checkRect = check;
        *pixmapRect = decoration;
        *textRect = display;
    }
}
#endif // QT_CONFIG(itemviews)

#if QT_CONFIG(toolbutton)
QString QCommonStylePrivate::toolButtonElideText(const QStyleOptionToolButton *option,
                                                 const QRect &textRect, int flags) const
{
    if (option->fontMetrics.horizontalAdvance(option->text) <= textRect.width())
        return option->text;

    QString text = option->text;
    text.replace(u'\n', QChar::LineSeparator);
    QTextOption textOption;
    textOption.setWrapMode(QTextOption::ManualWrap);
    textOption.setTextDirection(option->direction);

    return calculateElidedText(text, textOption,
                               option->font, textRect, Qt::AlignTop,
                               Qt::ElideMiddle, flags,
                               false, nullptr);
}
#endif // QT_CONFIG(toolbutton)

#if QT_CONFIG(tabbar)
/*! \internal
    Compute the textRect and the pixmapRect from the opt rect

    Uses the same computation than in QTabBar::tabSizeHint
 */
void QCommonStylePrivate::tabLayout(const QStyleOptionTab *opt, const QWidget *widget, QRect *textRect, QRect *iconRect) const
{
    Q_ASSERT(textRect);
    Q_ASSERT(iconRect);
    QRect tr = opt->rect;
    bool verticalTabs = opt->shape == QTabBar::RoundedEast
                        || opt->shape == QTabBar::RoundedWest
                        || opt->shape == QTabBar::TriangularEast
                        || opt->shape == QTabBar::TriangularWest;
    if (verticalTabs)
        tr.setRect(0, 0, tr.height(), tr.width()); // 0, 0 as we will have a translate transform

    int verticalShift = proxyStyle->pixelMetric(QStyle::PM_TabBarTabShiftVertical, opt, widget);
    int horizontalShift = proxyStyle->pixelMetric(QStyle::PM_TabBarTabShiftHorizontal, opt, widget);
    int hpadding = proxyStyle->pixelMetric(QStyle::PM_TabBarTabHSpace, opt, widget) / 2;
    int vpadding = proxyStyle->pixelMetric(QStyle::PM_TabBarTabVSpace, opt, widget) / 2;
    if (opt->shape == QTabBar::RoundedSouth || opt->shape == QTabBar::TriangularSouth)
        verticalShift = -verticalShift;
    tr.adjust(hpadding, verticalShift - vpadding, horizontalShift - hpadding, vpadding);
    bool selected = opt->state & QStyle::State_Selected;
    if (selected) {
        tr.setTop(tr.top() - verticalShift);
        tr.setRight(tr.right() - horizontalShift);
    }

    // left widget
    if (!opt->leftButtonSize.isEmpty()) {
        tr.setLeft(tr.left() + 4 +
            (verticalTabs ? opt->leftButtonSize.height() : opt->leftButtonSize.width()));
    }
    // right widget
    if (!opt->rightButtonSize.isEmpty()) {
        tr.setRight(tr.right() - 4 -
            (verticalTabs ? opt->rightButtonSize.height() : opt->rightButtonSize.width()));
    }

    // icon
    if (!opt->icon.isNull()) {
        QSize iconSize = opt->iconSize;
        if (!iconSize.isValid()) {
            int iconExtent = proxyStyle->pixelMetric(QStyle::PM_SmallIconSize, opt, widget);
            iconSize = QSize(iconExtent, iconExtent);
        }
        QSize tabIconSize = opt->icon.actualSize(iconSize,
                        (opt->state & QStyle::State_Enabled) ? QIcon::Normal : QIcon::Disabled,
                        (opt->state & QStyle::State_Selected) ? QIcon::On : QIcon::Off);
        // High-dpi icons do not need adjustment; make sure tabIconSize is not larger than iconSize
        tabIconSize = QSize(qMin(tabIconSize.width(), iconSize.width()), qMin(tabIconSize.height(), iconSize.height()));

        const int offsetX = (iconSize.width() - tabIconSize.width()) / 2;
        *iconRect = QRect(tr.left() + offsetX, tr.center().y() - tabIconSize.height() / 2,
                          tabIconSize.width(), tabIconSize.height());
        if (!verticalTabs)
            *iconRect = QStyle::visualRect(opt->direction, opt->rect, *iconRect);
        tr.setLeft(tr.left() + tabIconSize.width() + 4);
    }

    if (!verticalTabs)
        tr = QStyle::visualRect(opt->direction, opt->rect, tr);

    *textRect = tr;
}
#endif // QT_CONFIG(tabbar)

#if QT_CONFIG(animation)
/*! \internal */
QStyleAnimation * QCommonStylePrivate::animation(const QObject *target) const
{
    return animations.value(target);
}

/*! \internal */
void QCommonStylePrivate::startAnimation(QStyleAnimation *animation) const
{
    Q_Q(const QCommonStyle);
    const auto target = animation->target();
    stopAnimation(target);
    QObject::connect(animation, &QStyleAnimation::destroyed,
                     q, [this, target]() { removeAnimation(target); });
    animations.insert(target, animation);
    animation->start();
}

/*! \internal */
void QCommonStylePrivate::stopAnimation(const QObject *target) const
{
    QStyleAnimation *animation = animations.take(target);
    if (animation) {
        animation->stop();
        delete animation;
    }
}

/*! \internal */
void QCommonStylePrivate::removeAnimation(const QObject *target) const
{
    animations.remove(target);
}
#endif

/*!
  \reimp
*/
void QCommonStyle::drawControl(ControlElement element, const QStyleOption *opt,
                               QPainter *p, const QWidget *widget) const
{
    Q_D(const QCommonStyle);
    switch (element) {

    case CE_PushButton:
        if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            proxy()->drawControl(CE_PushButtonBevel, btn, p, widget);
            QStyleOptionButton subopt = *btn;
            subopt.rect = subElementRect(SE_PushButtonContents, btn, widget);
            proxy()->drawControl(CE_PushButtonLabel, &subopt, p, widget);
            if (btn->state & State_HasFocus) {
                QStyleOptionFocusRect fropt;
                fropt.QStyleOption::operator=(*btn);
                fropt.rect = subElementRect(SE_PushButtonFocusRect, btn, widget);
                proxy()->drawPrimitive(PE_FrameFocusRect, &fropt, p, widget);
            }
        }
        break;
    case CE_PushButtonBevel:
        if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            QRect br = btn->rect;
            int dbi = proxy()->pixelMetric(PM_ButtonDefaultIndicator, btn, widget);
            if (btn->features & QStyleOptionButton::DefaultButton)
                proxy()->drawPrimitive(PE_FrameDefaultButton, opt, p, widget);
            if (btn->features & QStyleOptionButton::AutoDefaultButton)
                br.setCoords(br.left() + dbi, br.top() + dbi, br.right() - dbi, br.bottom() - dbi);
            if (!(btn->features & (QStyleOptionButton::Flat | QStyleOptionButton::CommandLinkButton))
                || btn->state & (State_Sunken | State_On)
                || (btn->features & QStyleOptionButton::CommandLinkButton && btn->state & State_MouseOver)) {
                QStyleOptionButton tmpBtn = *btn;
                tmpBtn.rect = br;
                proxy()->drawPrimitive(PE_PanelButtonCommand, &tmpBtn, p, widget);
            }
            if (btn->features & QStyleOptionButton::HasMenu) {
                int mbi = proxy()->pixelMetric(PM_MenuButtonIndicator, btn, widget);
                QRect ir = btn->rect;
                QStyleOptionButton newBtn = *btn;
                newBtn.rect = QRect(ir.right() - mbi - 2, ir.height()/2 - mbi/2 + 3, mbi - 6, mbi - 6);
                newBtn.rect = visualRect(btn->direction, br, newBtn.rect);
                proxy()->drawPrimitive(PE_IndicatorArrowDown, &newBtn, p, widget);
            }
        }
        break;
 case CE_PushButtonLabel:
        if (const QStyleOptionButton *button = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            QRect textRect = button->rect;
            int tf = Qt::AlignVCenter | Qt::TextShowMnemonic;
            if (!proxy()->styleHint(SH_UnderlineShortcut, button, widget))
                tf |= Qt::TextHideMnemonic;

            if (button->features & QStyleOptionButton::HasMenu) {
                int indicatorSize = proxy()->pixelMetric(PM_MenuButtonIndicator, button, widget);
                if (button->direction == Qt::LeftToRight)
                    textRect = textRect.adjusted(0, 0, -indicatorSize, 0);
                else
                    textRect = textRect.adjusted(indicatorSize, 0, 0, 0);
            }

            if (!button->icon.isNull()) {
                //Center both icon and text
                QIcon::Mode mode = button->state & State_Enabled ? QIcon::Normal : QIcon::Disabled;
                if (mode == QIcon::Normal && button->state & State_HasFocus)
                    mode = QIcon::Active;
                QIcon::State state = QIcon::Off;
                if (button->state & State_On)
                    state = QIcon::On;

                QPixmap pixmap = button->icon.pixmap(button->iconSize, QStyleHelper::getDpr(p), mode, state);
                int pixmapWidth = pixmap.width() / pixmap.devicePixelRatio();
                int pixmapHeight = pixmap.height() / pixmap.devicePixelRatio();
                int labelWidth = pixmapWidth;
                int labelHeight = pixmapHeight;
                int iconSpacing = 4;//### 4 is currently hardcoded in QPushButton::sizeHint()
                if (!button->text.isEmpty()) {
                    int textWidth = button->fontMetrics.boundingRect(opt->rect, tf, button->text).width();
                    labelWidth += (textWidth + iconSpacing);
                }

                QRect iconRect = QRect(textRect.x() + (textRect.width() - labelWidth) / 2,
                                       textRect.y() + (textRect.height() - labelHeight) / 2,
                                       pixmapWidth, pixmapHeight);

                iconRect = visualRect(button->direction, textRect, iconRect);

                if (button->direction == Qt::RightToLeft)
                    textRect.setRight(iconRect.left() - iconSpacing / 2);
                else
                    textRect.setLeft(iconRect.left() + iconRect.width() + iconSpacing / 2);

                // qt_format_text reverses again when  painter->layoutDirection is also RightToLeft
                if (p->layoutDirection() == button->direction)
                    tf |= Qt::AlignLeft;
                else
                    tf |= Qt::AlignRight;

                if (button->state & (State_On | State_Sunken))
                    iconRect.translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, opt, widget),
                                       proxy()->pixelMetric(PM_ButtonShiftVertical, opt, widget));
                p->drawPixmap(iconRect, pixmap);
            } else {
                tf |= Qt::AlignHCenter;
            }
            if (button->state & (State_On | State_Sunken))
                textRect.translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, opt, widget),
                             proxy()->pixelMetric(PM_ButtonShiftVertical, opt, widget));

            proxy()->drawItemText(p, textRect, tf, button->palette, (button->state & State_Enabled),
                         button->text, QPalette::ButtonText);
        }
        break;
    case CE_RadioButton:
    case CE_CheckBox:
        if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            bool isRadio = (element == CE_RadioButton);
            QStyleOptionButton subopt = *btn;
            subopt.rect = subElementRect(isRadio ? SE_RadioButtonIndicator
                                                 : SE_CheckBoxIndicator, btn, widget);
            proxy()->drawPrimitive(isRadio ? PE_IndicatorRadioButton : PE_IndicatorCheckBox,
                          &subopt, p, widget);
            subopt.rect = subElementRect(isRadio ? SE_RadioButtonContents
                                                 : SE_CheckBoxContents, btn, widget);
            proxy()->drawControl(isRadio ? CE_RadioButtonLabel : CE_CheckBoxLabel, &subopt, p, widget);
            if (btn->state & State_HasFocus) {
                QStyleOptionFocusRect fropt;
                fropt.QStyleOption::operator=(*btn);
                fropt.rect = subElementRect(isRadio ? SE_RadioButtonFocusRect
                                                    : SE_CheckBoxFocusRect, btn, widget);
                proxy()->drawPrimitive(PE_FrameFocusRect, &fropt, p, widget);
            }
        }
        break;
    case CE_RadioButtonLabel:
    case CE_CheckBoxLabel:
        if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            int alignment = visualAlignment(btn->direction, Qt::AlignLeft | Qt::AlignVCenter);

            if (!proxy()->styleHint(SH_UnderlineShortcut, btn, widget))
                alignment |= Qt::TextHideMnemonic;
            QPixmap pix;
            QRect textRect = btn->rect;
            if (!btn->icon.isNull()) {
                pix = btn->icon.pixmap(btn->iconSize, QStyleHelper::getDpr(p), btn->state & State_Enabled ? QIcon::Normal : QIcon::Disabled);
                proxy()->drawItemPixmap(p, btn->rect, alignment, pix);
                if (btn->direction == Qt::RightToLeft)
                    textRect.setRight(textRect.right() - btn->iconSize.width() - 4);
                else
                    textRect.setLeft(textRect.left() + btn->iconSize.width() + 4);
            }
            if (!btn->text.isEmpty()){
                proxy()->drawItemText(p, textRect, alignment | Qt::TextShowMnemonic,
                    btn->palette, btn->state & State_Enabled, btn->text, QPalette::WindowText);
            }
        }
        break;
#if QT_CONFIG(menu)
    case CE_MenuScroller: {
        QStyleOption arrowOpt = *opt;
        arrowOpt.state |= State_Enabled;
        proxy()->drawPrimitive(((opt->state & State_DownArrow) ? PE_IndicatorArrowDown : PE_IndicatorArrowUp),
                    &arrowOpt, p, widget);
        break; }
    case CE_MenuTearoff:
        if (opt->state & State_Selected)
            p->fillRect(opt->rect, opt->palette.brush(QPalette::Highlight));
        else
            p->fillRect(opt->rect, opt->palette.brush(QPalette::Button));
        p->setPen(QPen(opt->palette.dark().color(), 1, Qt::DashLine));
        p->drawLine(opt->rect.x() + 2, opt->rect.y() + opt->rect.height() / 2 - 1,
                    opt->rect.x() + opt->rect.width() - 4,
                    opt->rect.y() + opt->rect.height() / 2 - 1);
        p->setPen(QPen(opt->palette.light().color(), 1, Qt::DashLine));
        p->drawLine(opt->rect.x() + 2, opt->rect.y() + opt->rect.height() / 2,
                    opt->rect.x() + opt->rect.width() - 4, opt->rect.y() + opt->rect.height() / 2);
        break;
#endif // QT_CONFIG(menu)
#if QT_CONFIG(menubar)
    case CE_MenuBarItem:
        if (const QStyleOptionMenuItem *mbi = qstyleoption_cast<const QStyleOptionMenuItem *>(opt)) {
            int alignment = Qt::AlignCenter | Qt::TextShowMnemonic | Qt::TextDontClip
                           | Qt::TextSingleLine;
            if (!proxy()->styleHint(SH_UnderlineShortcut, mbi, widget))
                alignment |= Qt::TextHideMnemonic;
            int iconExtent = proxy()->pixelMetric(PM_SmallIconSize, opt, widget);
            QPixmap pix = mbi->icon.pixmap(QSize(iconExtent, iconExtent), QStyleHelper::getDpr(p), (mbi->state & State_Enabled) ? QIcon::Normal : QIcon::Disabled);
            if (!pix.isNull())
                proxy()->drawItemPixmap(p,mbi->rect, alignment, pix);
            else
                proxy()->drawItemText(p, mbi->rect, alignment, mbi->palette, mbi->state & State_Enabled,
                             mbi->text, QPalette::ButtonText);
        }
        break;
    case CE_MenuBarEmptyArea:
        if (widget && !widget->testAttribute(Qt::WA_NoSystemBackground))
            p->eraseRect(opt->rect);
        break;
#endif // QT_CONFIG(menubar)
#if QT_CONFIG(progressbar)
    case CE_ProgressBar:
        if (const QStyleOptionProgressBar *pb
                = qstyleoption_cast<const QStyleOptionProgressBar *>(opt)) {
            QStyleOptionProgressBar subopt = *pb;
            subopt.rect = subElementRect(SE_ProgressBarGroove, pb, widget);
            proxy()->drawControl(CE_ProgressBarGroove, &subopt, p, widget);
            subopt.rect = subElementRect(SE_ProgressBarContents, pb, widget);
            proxy()->drawControl(CE_ProgressBarContents, &subopt, p, widget);
            if (pb->textVisible) {
                subopt.rect = subElementRect(SE_ProgressBarLabel, pb, widget);
                proxy()->drawControl(CE_ProgressBarLabel, &subopt, p, widget);
            }
        }
        break;
    case CE_ProgressBarGroove:
        if (opt->rect.isValid())
            qDrawShadePanel(p, opt->rect, opt->palette, true, 1,
                            &opt->palette.brush(QPalette::Window));
        break;
    case CE_ProgressBarLabel:
        if (const QStyleOptionProgressBar *pb = qstyleoption_cast<const QStyleOptionProgressBar *>(opt)) {
            const bool vertical = !(pb->state & QStyle::State_Horizontal);
            if (!vertical) {
                QPalette::ColorRole textRole = QPalette::NoRole;
                if ((pb->textAlignment & Qt::AlignCenter) && pb->textVisible
                    && ((qint64(pb->progress) - qint64(pb->minimum)) * 2 >= (qint64(pb->maximum) - qint64(pb->minimum)))) {
                    textRole = QPalette::HighlightedText;
                    //Draw text shadow, This will increase readability when the background of same color
                    QRect shadowRect(pb->rect);
                    shadowRect.translate(1,1);
                    QColor shadowColor = (pb->palette.color(textRole).value() <= 128)
                       ? QColor(255,255,255,160) : QColor(0,0,0,160);
                    QPalette shadowPalette = pb->palette;
                    shadowPalette.setColor(textRole, shadowColor);
                    proxy()->drawItemText(p, shadowRect, Qt::AlignCenter | Qt::TextSingleLine, shadowPalette,
                                 pb->state & State_Enabled, pb->text, textRole);
                }
                proxy()->drawItemText(p, pb->rect, Qt::AlignCenter | Qt::TextSingleLine, pb->palette,
                             pb->state & State_Enabled, pb->text, textRole);
            }
        }
        break;
    case CE_ProgressBarContents:
        if (const QStyleOptionProgressBar *pb = qstyleoption_cast<const QStyleOptionProgressBar *>(opt)) {

            QRect rect = pb->rect;
            const bool vertical = !(pb->state & QStyle::State_Horizontal);
            const bool inverted = pb->invertedAppearance;
            qint64 minimum = qint64(pb->minimum);
            qint64 maximum = qint64(pb->maximum);
            qint64 progress = qint64(pb->progress);

            QTransform m;

            if (vertical) {
                rect = QRect(rect.y(), rect.x(), rect.height(), rect.width()); // flip width and height
                m.rotate(90);
                m.translate(0, -(rect.height() + rect.y()*2));
            }

            QPalette pal2 = pb->palette;
            // Correct the highlight color if it is the same as the background
            if (pal2.highlight() == pal2.window())
                pal2.setColor(QPalette::Highlight, pb->palette.color(QPalette::Active,
                                                                     QPalette::Highlight));
            bool reverse = ((!vertical && (pb->direction == Qt::RightToLeft)) || vertical);
            if (inverted)
                reverse = !reverse;
            int w = rect.width();
            if (pb->minimum == 0 && pb->maximum == 0) {
                // draw busy indicator
                int x = (progress - minimum) % (w * 2);
                if (x > w)
                    x = 2 * w - x;
                x = reverse ? rect.right() - x : x + rect.x();
                p->setPen(QPen(pal2.highlight().color(), 4));
                p->drawLine(x, rect.y(), x, rect.height());
            } else {
                const int unit_width = proxy()->pixelMetric(PM_ProgressBarChunkWidth, pb, widget);
                if (!unit_width)
                    return;

                int u;
                if (unit_width > 1)
                    u = ((rect.width() + unit_width) / unit_width);
                else
                    u = w / unit_width;
                qint64 p_v = progress - minimum;
                qint64 t_s = (maximum - minimum) ? (maximum - minimum) : qint64(1);

                if (u > 0 && p_v >= INT_MAX / u && t_s >= u) {
                    // scale down to something usable.
                    p_v /= u;
                    t_s /= u;
                }

                // nu < tnu, if last chunk is only a partial chunk
                int tnu, nu;
                tnu = nu = p_v * u / t_s;

                if (nu * unit_width > w)
                    --nu;

                // Draw nu units out of a possible u of unit_width
                // width, each a rectangle bordered by background
                // color, all in a sunken panel with a percentage text
                // display at the end.
                int x = 0;
                int x0 = reverse ? rect.right() - ((unit_width > 1) ? unit_width : 0)
                                 : rect.x();

                QStyleOptionProgressBar pbBits = *pb;
                pbBits.rect = rect;
                pbBits.palette = pal2;
                int myY = pbBits.rect.y();
                int myHeight = pbBits.rect.height();
                pbBits.state &= QStyle::State_Horizontal;  // all other is irrelevant here
                for (int i = 0; i < nu; ++i) {
                    pbBits.rect.setRect(x0 + x, myY, unit_width, myHeight);
                    pbBits.rect = m.mapRect(QRectF(pbBits.rect)).toRect();
                    proxy()->drawPrimitive(PE_IndicatorProgressChunk, &pbBits, p, widget);
                    x += reverse ? -unit_width : unit_width;
                }

                // Draw the last partial chunk to fill up the
                // progress bar entirely
                if (nu < tnu) {
                    int pixels_left = w - (nu * unit_width);
                    int offset = reverse ? x0 + x + unit_width-pixels_left : x0 + x;
                    pbBits.rect.setRect(offset, myY, pixels_left, myHeight);
                    pbBits.rect = m.mapRect(QRectF(pbBits.rect)).toRect();
                    proxy()->drawPrimitive(PE_IndicatorProgressChunk, &pbBits, p, widget);
                }
            }
        }
        break;
#endif // QT_CONFIG(progressbar)
    case CE_HeaderLabel:
        if (const QStyleOptionHeader *header = qstyleoption_cast<const QStyleOptionHeader *>(opt)) {
            QRect rect = header->rect;
            if (!header->icon.isNull()) {
                int iconExtent = proxy()->pixelMetric(PM_SmallIconSize, opt, widget);
                QPixmap pixmap
                    = header->icon.pixmap(QSize(iconExtent, iconExtent), QStyleHelper::getDpr(p), (header->state & State_Enabled) ? QIcon::Normal : QIcon::Disabled);
                int pixw = pixmap.width() / pixmap.devicePixelRatio();

                QRect aligned = alignedRect(header->direction, header->iconAlignment, pixmap.size() / pixmap.devicePixelRatio(), rect);
                QRect inter = aligned.intersected(rect);
                p->drawPixmap(inter.x(), inter.y(), pixmap,
                              inter.x() - aligned.x(), inter.y() - aligned.y(),
                              aligned.width() * pixmap.devicePixelRatio(),
                              pixmap.height() * pixmap.devicePixelRatio());

                const int margin = proxy()->pixelMetric(QStyle::PM_HeaderMargin, opt, widget);
                if (header->direction == Qt::LeftToRight)
                    rect.setLeft(rect.left() + pixw + margin);
                else
                    rect.setRight(rect.right() - pixw - margin);
            }
            QFontMetrics fm(header->fontMetrics);
            if (header->state & QStyle::State_On) {
                QFont fnt = p->font();
                // the font already has a weight set; don't override that
                if (!(fnt.resolveMask() & QFont::WeightResolved)) {
                    fnt.setBold(true);
                    p->setFont(fnt);
                    fm = QFontMetrics((p->font()));
                }
            }
            QString text = header->text;
            if (const QStyleOptionHeaderV2 *headerV2 = qstyleoption_cast<const QStyleOptionHeaderV2 *>(header)) {
                if (headerV2->textElideMode != Qt::ElideNone)
                    text = fm.elidedText(header->text, headerV2->textElideMode, rect.width());
            }
            proxy()->drawItemText(p, rect, header->textAlignment, header->palette,
                                  header->state.testFlag(State_Enabled), text, QPalette::ButtonText);
        }
        break;
#if QT_CONFIG(toolbutton)
    case CE_ToolButtonLabel:
        if (const QStyleOptionToolButton *toolbutton
                = qstyleoption_cast<const QStyleOptionToolButton *>(opt)) {
            QRect rect = toolbutton->rect;
            int shiftX = 0;
            int shiftY = 0;
            if (toolbutton->state & (State_Sunken | State_On)) {
                shiftX = proxy()->pixelMetric(PM_ButtonShiftHorizontal, toolbutton, widget);
                shiftY = proxy()->pixelMetric(PM_ButtonShiftVertical, toolbutton, widget);
            }
            // Arrow type always overrules and is always shown
            bool hasArrow = toolbutton->features & QStyleOptionToolButton::Arrow;
            if (((!hasArrow && toolbutton->icon.isNull()) && !toolbutton->text.isEmpty())
                || toolbutton->toolButtonStyle == Qt::ToolButtonTextOnly) {
                int alignment = Qt::AlignCenter | Qt::TextShowMnemonic;
                if (!proxy()->styleHint(SH_UnderlineShortcut, opt, widget))
                    alignment |= Qt::TextHideMnemonic;
                rect.translate(shiftX, shiftY);
                p->setFont(toolbutton->font);
                const QString text = d->toolButtonElideText(toolbutton, rect, alignment);
                proxy()->drawItemText(p, rect, alignment, toolbutton->palette,
                             opt->state & State_Enabled, text,
                             QPalette::ButtonText);
            } else {
                QPixmap pm;
                QSize pmSize = toolbutton->iconSize;
                if (!toolbutton->icon.isNull()) {
                    QIcon::State state = toolbutton->state & State_On ? QIcon::On : QIcon::Off;
                    QIcon::Mode mode;
                    if (!(toolbutton->state & State_Enabled))
                        mode = QIcon::Disabled;
                    else if ((opt->state & State_MouseOver) && (opt->state & State_AutoRaise))
                        mode = QIcon::Active;
                    else
                        mode = QIcon::Normal;
                    pm = toolbutton->icon.pixmap(toolbutton->rect.size().boundedTo(toolbutton->iconSize), QStyleHelper::getDpr(p),
                                                 mode, state);
                    pmSize = pm.size() / pm.devicePixelRatio();
                }

                if (toolbutton->toolButtonStyle != Qt::ToolButtonIconOnly) {
                    p->setFont(toolbutton->font);
                    QRect pr = rect,
                    tr = rect;
                    int alignment = Qt::TextShowMnemonic;
                    if (!proxy()->styleHint(SH_UnderlineShortcut, opt, widget))
                        alignment |= Qt::TextHideMnemonic;

                    if (toolbutton->toolButtonStyle == Qt::ToolButtonTextUnderIcon) {
                        pr.setHeight(pmSize.height() + 4); //### 4 is currently hardcoded in QToolButton::sizeHint()
                        tr.adjust(0, pr.height() - 1, 0, -1);
                        pr.translate(shiftX, shiftY);
                        if (!hasArrow) {
                            proxy()->drawItemPixmap(p, pr, Qt::AlignCenter, pm);
                        } else {
                            drawArrow(proxy(), toolbutton, pr, p, widget);
                        }
                        alignment |= Qt::AlignCenter;
                    } else {
                        pr.setWidth(pmSize.width() + 4); //### 4 is currently hardcoded in QToolButton::sizeHint()
                        tr.adjust(pr.width(), 0, 0, 0);
                        pr.translate(shiftX, shiftY);
                        if (!hasArrow) {
                            proxy()->drawItemPixmap(p, QStyle::visualRect(opt->direction, rect, pr), Qt::AlignCenter, pm);
                        } else {
                            drawArrow(proxy(), toolbutton, pr, p, widget);
                        }
                        alignment |= Qt::AlignLeft | Qt::AlignVCenter;
                    }
                    tr.translate(shiftX, shiftY);
                    const QString text = d->toolButtonElideText(toolbutton, tr, alignment);
                    proxy()->drawItemText(p, QStyle::visualRect(opt->direction, rect, tr), alignment, toolbutton->palette,
                                 toolbutton->state & State_Enabled, text,
                                 QPalette::ButtonText);
                } else {
                    rect.translate(shiftX, shiftY);
                    if (hasArrow) {
                        drawArrow(proxy(), toolbutton, rect, p, widget);
                    } else {
                        proxy()->drawItemPixmap(p, rect, Qt::AlignCenter, pm);
                    }
                }
            }
        }
        break;
#endif // QT_CONFIG(toolbutton)
#if QT_CONFIG(toolbox)
    case CE_ToolBoxTab:
        if (const QStyleOptionToolBox *tb = qstyleoption_cast<const QStyleOptionToolBox *>(opt)) {
            proxy()->drawControl(CE_ToolBoxTabShape, tb, p, widget);
            proxy()->drawControl(CE_ToolBoxTabLabel, tb, p, widget);
        }
        break;
    case CE_ToolBoxTabShape:
        if (const QStyleOptionToolBox *tb = qstyleoption_cast<const QStyleOptionToolBox *>(opt)) {
            p->setPen(tb->palette.mid().color().darker(150));
            int d = 20 + tb->rect.height() - 3;
            if (tb->direction != Qt::RightToLeft) {
                const QPoint points[] = {
                    QPoint(-1, tb->rect.height() + 1),
                    QPoint(-1, 1),
                    QPoint(tb->rect.width() - d, 1),
                    QPoint(tb->rect.width() - 20, tb->rect.height() - 2),
                    QPoint(tb->rect.width() - 1, tb->rect.height() - 2),
                    QPoint(tb->rect.width() - 1, tb->rect.height() + 1),
                    QPoint(-1, tb->rect.height() + 1),
                };
                p->drawPolygon(points, sizeof points / sizeof *points);
            } else {
                const QPoint points[] = {
                    QPoint(tb->rect.width(), tb->rect.height() + 1),
                    QPoint(tb->rect.width(), 1),
                    QPoint(d - 1, 1),
                    QPoint(20 - 1, tb->rect.height() - 2),
                    QPoint(0, tb->rect.height() - 2),
                    QPoint(0, tb->rect.height() + 1),
                    QPoint(tb->rect.width(), tb->rect.height() + 1),
                };
                p->drawPolygon(points, sizeof points / sizeof *points);
            }
            p->setPen(tb->palette.light().color());
            if (tb->direction != Qt::RightToLeft) {
                p->drawLine(0, 2, tb->rect.width() - d, 2);
                p->drawLine(tb->rect.width() - d - 1, 2, tb->rect.width() - 21, tb->rect.height() - 1);
                p->drawLine(tb->rect.width() - 20, tb->rect.height() - 1,
                            tb->rect.width(), tb->rect.height() - 1);
            } else {
                p->drawLine(tb->rect.width() - 1, 2, d - 1, 2);
                p->drawLine(d, 2, 20, tb->rect.height() - 1);
                p->drawLine(19, tb->rect.height() - 1,
                            -1, tb->rect.height() - 1);
            }
            p->setBrush(Qt::NoBrush);
        }
        break;
#endif // QT_CONFIG(toolbox)
#if QT_CONFIG(tabbar)
    case CE_TabBarTab:
        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(opt)) {
            proxy()->drawControl(CE_TabBarTabShape, tab, p, widget);
            proxy()->drawControl(CE_TabBarTabLabel, tab, p, widget);
        }
        break;
    case CE_TabBarTabShape:
        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(opt)) {
            QPainterStateGuard psg(p);
            QRect rect(tab->rect);
            bool selected = tab->state & State_Selected;
            bool onlyOne = tab->position == QStyleOptionTab::OnlyOneTab;
            int tabOverlap = onlyOne ? 0 : proxy()->pixelMetric(PM_TabBarTabOverlap, opt, widget);

            if (!selected) {
                switch (tab->shape) {
                case QTabBar::TriangularNorth:
                    rect.adjust(0, 0, 0, -tabOverlap);
                    if (!selected)
                        rect.adjust(1, 1, -1, 0);
                    break;
                case QTabBar::TriangularSouth:
                    rect.adjust(0, tabOverlap, 0, 0);
                    if (!selected)
                        rect.adjust(1, 0, -1, -1);
                    break;
                case QTabBar::TriangularEast:
                    rect.adjust(tabOverlap, 0, 0, 0);
                    if (!selected)
                        rect.adjust(0, 1, -1, -1);
                    break;
                case QTabBar::TriangularWest:
                    rect.adjust(0, 0, -tabOverlap, 0);
                    if (!selected)
                        rect.adjust(1, 1, 0, -1);
                    break;
                default:
                    break;
                }
            }

            p->setPen(QPen(tab->palette.windowText(), 0));
            if (selected) {
                p->setBrush(tab->palette.base());
            } else {
                if (widget && widget->parentWidget())
                    p->setBrush(widget->parentWidget()->palette().window());
                else
                    p->setBrush(tab->palette.window());
            }

            int y;
            int x;
            QPolygon a(10);
            switch (tab->shape) {
            case QTabBar::TriangularNorth:
            case QTabBar::TriangularSouth: {
                a.setPoint(0, 0, -1);
                a.setPoint(1, 0, 0);
                y = rect.height() - 2;
                x = y / 3;
                a.setPoint(2, x++, y - 1);
                ++x;
                a.setPoint(3, x++, y++);
                a.setPoint(4, x, y);

                int i;
                int right = rect.width() - 1;
                for (i = 0; i < 5; ++i)
                    a.setPoint(9 - i, right - a.point(i).x(), a.point(i).y());
                if (tab->shape == QTabBar::TriangularNorth)
                    for (i = 0; i < 10; ++i)
                        a.setPoint(i, a.point(i).x(), rect.height() - 1 - a.point(i).y());

                a.translate(rect.left(), rect.top());
                p->setRenderHint(QPainter::Antialiasing);
                p->translate(0, 0.5);

                QPainterPath path;
                path.addPolygon(a);
                p->drawPath(path);
                break; }
            case QTabBar::TriangularEast:
            case QTabBar::TriangularWest: {
                a.setPoint(0, -1, 0);
                a.setPoint(1, 0, 0);
                x = rect.width() - 2;
                y = x / 3;
                a.setPoint(2, x - 1, y++);
                ++y;
                a.setPoint(3, x++, y++);
                a.setPoint(4, x, y);
                int i;
                int bottom = rect.height() - 1;
                for (i = 0; i < 5; ++i)
                    a.setPoint(9 - i, a.point(i).x(), bottom - a.point(i).y());
                if (tab->shape == QTabBar::TriangularWest)
                    for (i = 0; i < 10; ++i)
                        a.setPoint(i, rect.width() - 1 - a.point(i).x(), a.point(i).y());
                a.translate(rect.left(), rect.top());
                p->setRenderHint(QPainter::Antialiasing);
                p->translate(0.5, 0);
                QPainterPath path;
                path.addPolygon(a);
                p->drawPath(path);
                break; }
            default:
                break;
            }
        }
        break;
    case CE_ToolBoxTabLabel:
        if (const QStyleOptionToolBox *tb = qstyleoption_cast<const QStyleOptionToolBox *>(opt)) {
            bool enabled = tb->state & State_Enabled;
            bool selected = tb->state & State_Selected;
            int iconExtent = proxy()->pixelMetric(QStyle::PM_SmallIconSize, tb, widget);
            QPixmap pm = tb->icon.pixmap(QSize(iconExtent, iconExtent), QStyleHelper::getDpr(p),
                                         enabled ? QIcon::Normal : QIcon::Disabled);

            QRect cr = subElementRect(QStyle::SE_ToolBoxTabContents, tb, widget);
            QRect tr, ir;
            int ih = 0;
            if (pm.isNull()) {
                tr = cr;
                tr.adjust(4, 0, -8, 0);
            } else {
                int iw = pm.width() / pm.devicePixelRatio() + 4;
                ih = pm.height()/ pm.devicePixelRatio();
                ir = QRect(cr.left() + 4, cr.top(), iw + 2, ih);
                tr = QRect(ir.right(), cr.top(), cr.width() - ir.right() - 4, cr.height());
            }

            if (selected && proxy()->styleHint(QStyle::SH_ToolBox_SelectedPageTitleBold, tb, widget)) {
                QFont f(p->font());
                f.setBold(true);
                p->setFont(f);
            }

            QString txt = tb->fontMetrics.elidedText(tb->text, Qt::ElideRight, tr.width());

            if (ih)
                p->drawPixmap(ir.left(), (tb->rect.height() - ih) / 2, pm);

            int alignment = Qt::AlignLeft | Qt::AlignVCenter | Qt::TextShowMnemonic;
            if (!proxy()->styleHint(QStyle::SH_UnderlineShortcut, tb, widget))
                alignment |= Qt::TextHideMnemonic;
            proxy()->drawItemText(p, tr, alignment, tb->palette, enabled, txt, QPalette::ButtonText);

            if (!txt.isEmpty() && opt->state & State_HasFocus) {
                QStyleOptionFocusRect opt;
                opt.rect = tr;
                opt.palette = tb->palette;
                opt.state = QStyle::State_None;
                proxy()->drawPrimitive(QStyle::PE_FrameFocusRect, &opt, p, widget);
            }
        }
        break;
    case CE_TabBarTabLabel:
        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(opt)) {
            QRect tr = tab->rect;
            bool verticalTabs = tab->shape == QTabBar::RoundedEast
                                || tab->shape == QTabBar::RoundedWest
                                || tab->shape == QTabBar::TriangularEast
                                || tab->shape == QTabBar::TriangularWest;

            int alignment = Qt::AlignCenter | Qt::TextShowMnemonic;
            if (!proxy()->styleHint(SH_UnderlineShortcut, opt, widget))
                alignment |= Qt::TextHideMnemonic;

            QPainterStateGuard psg(p, QPainterStateGuard::InitialState::NoSave);
            if (verticalTabs) {
                psg.save();
                int newX, newY, newRot;
                if (tab->shape == QTabBar::RoundedEast || tab->shape == QTabBar::TriangularEast) {
                    newX = tr.width() + tr.x();
                    newY = tr.y();
                    newRot = 90;
                } else {
                    newX = tr.x();
                    newY = tr.y() + tr.height();
                    newRot = -90;
                }
                QTransform m = QTransform::fromTranslate(newX, newY);
                m.rotate(newRot);
                p->setTransform(m, true);
            }
            QRect iconRect;
            d->tabLayout(tab, widget, &tr, &iconRect);

            // compute tr again, unless tab is moving, because the style may override subElementRect
            if (tab->position != QStyleOptionTab::TabPosition::Moving)
                tr = proxy()->subElementRect(SE_TabBarTabText, opt, widget);

            if (!tab->icon.isNull()) {
                QPixmap tabIcon = tab->icon.pixmap(tab->iconSize, QStyleHelper::getDpr(p),
                                                   (tab->state & State_Enabled) ? QIcon::Normal
                                                                                : QIcon::Disabled,
                                                   (tab->state & State_Selected) ? QIcon::On
                                                                                 : QIcon::Off);
                p->drawPixmap(iconRect.x(), iconRect.y(), tabIcon);
            }

            proxy()->drawItemText(p, tr, alignment, tab->palette, tab->state & State_Enabled, tab->text,
                                  widget ? widget->foregroundRole() : QPalette::WindowText);
            if (verticalTabs)
                psg.restore();

            if (tab->state & State_HasFocus) {
                const int OFFSET = 1 + pixelMetric(PM_DefaultFrameWidth, opt, widget);

                int x1, x2;
                x1 = tab->rect.left();
                x2 = tab->rect.right() - 1;

                QStyleOptionFocusRect fropt;
                fropt.QStyleOption::operator=(*tab);
                fropt.rect.setRect(x1 + 1 + OFFSET, tab->rect.y() + OFFSET,
                                   x2 - x1 - 2*OFFSET, tab->rect.height() - 2*OFFSET);
                drawPrimitive(PE_FrameFocusRect, &fropt, p, widget);
            }
        }
        break;
#endif // QT_CONFIG(tabbar)
#if QT_CONFIG(sizegrip)
    case CE_SizeGrip: {
        QPainterStateGuard psg(p);
        int x, y, w, h;
        opt->rect.getRect(&x, &y, &w, &h);

        int sw = qMin(h, w);
        if (h > w)
            p->translate(0, h - w);
        else
            p->translate(w - h, 0);

        int sx = x;
        int sy = y;
        int s = sw / 3;

        Qt::Corner corner;
        if (const QStyleOptionSizeGrip *sgOpt = qstyleoption_cast<const QStyleOptionSizeGrip *>(opt))
            corner = sgOpt->corner;
        else if (opt->direction == Qt::RightToLeft)
            corner = Qt::BottomLeftCorner;
        else
            corner = Qt::BottomRightCorner;

        if (corner == Qt::BottomLeftCorner) {
            sx = x + sw;
            for (int i = 0; i < 4; ++i) {
                p->setPen(opt->palette.light().color());
                p->drawLine(x, sy - 1 , sx + 1, sw);
                p->setPen(opt->palette.dark().color());
                p->drawLine(x, sy, sx, sw);
                p->setPen(opt->palette.dark().color());
                p->drawLine(x, sy + 1, sx - 1, sw);
                sx -= s;
                sy += s;
            }
        } else if (corner == Qt::BottomRightCorner) {
            for (int i = 0; i < 4; ++i) {
                p->setPen(opt->palette.light().color());
                p->drawLine(sx - 1, sw, sw, sy - 1);
                p->setPen(opt->palette.dark().color());
                p->drawLine(sx, sw, sw, sy);
                p->setPen(opt->palette.dark().color());
                p->drawLine(sx + 1, sw, sw, sy + 1);
                sx += s;
                sy += s;
            }
        } else if (corner == Qt::TopRightCorner) {
            sy = y + sw;
            for (int i = 0; i < 4; ++i) {
                p->setPen(opt->palette.light().color());
                p->drawLine(sx - 1, y, sw, sy + 1);
                p->setPen(opt->palette.dark().color());
                p->drawLine(sx, y, sw, sy);
                p->setPen(opt->palette.dark().color());
                p->drawLine(sx + 1, y, sw, sy - 1);
                sx += s;
                sy -= s;
            }
        } else if (corner == Qt::TopLeftCorner) {
            for (int i = 0; i < 4; ++i) {
                p->setPen(opt->palette.light().color());
                p->drawLine(x, sy - 1, sx - 1, y);
                p->setPen(opt->palette.dark().color());
                p->drawLine(x, sy, sx, y);
                p->setPen(opt->palette.dark().color());
                p->drawLine(x, sy + 1, sx + 1, y);
                sx += s;
                sy += s;
            }
        }
        break; }
#endif // QT_CONFIG(sizegrip)
#if QT_CONFIG(rubberband)
    case CE_RubberBand: {
        if (const QStyleOptionRubberBand *rbOpt = qstyleoption_cast<const QStyleOptionRubberBand *>(opt)) {
            QPixmap tiledPixmap(16, 16);
            QPainter pixmapPainter(&tiledPixmap);
            pixmapPainter.setPen(Qt::NoPen);
            pixmapPainter.setBrush(Qt::Dense4Pattern);
            pixmapPainter.setBackground(QBrush(opt->palette.base()));
            pixmapPainter.setBackgroundMode(Qt::OpaqueMode);
            pixmapPainter.drawRect(0, 0, tiledPixmap.width(), tiledPixmap.height());
            pixmapPainter.end();
            // ### workaround for borked XRENDER
            tiledPixmap = QPixmap::fromImage(tiledPixmap.toImage());

            QPainterStateGuard psg(p);
            QRect r = opt->rect;
            QStyleHintReturnMask mask;
            if (proxy()->styleHint(QStyle::SH_RubberBand_Mask, opt, widget, &mask))
                p->setClipRegion(mask.region);
            p->drawTiledPixmap(r.x(), r.y(), r.width(), r.height(), tiledPixmap);
            p->setPen(opt->palette.color(QPalette::Active, QPalette::WindowText));
            p->setBrush(Qt::NoBrush);
            p->drawRect(r.adjusted(0, 0, -1, -1));
            if (rbOpt->shape == QRubberBand::Rectangle)
                p->drawRect(r.adjusted(3, 3, -4, -4));
        }
        break; }
#endif // QT_CONFIG(rubberband)
#if QT_CONFIG(dockwidget)
    case CE_DockWidgetTitle:
        if (const QStyleOptionDockWidget *dwOpt = qstyleoption_cast<const QStyleOptionDockWidget *>(opt)) {
            QRect r = dwOpt->rect.adjusted(0, 0, -1, -1);
            if (dwOpt->movable) {
                p->setPen(dwOpt->palette.color(QPalette::Dark));
                p->drawRect(r);
            }

            if (!dwOpt->title.isEmpty()) {
                const bool verticalTitleBar = dwOpt->verticalTitleBar;

                QPainterStateGuard psg(p, QPainterStateGuard::InitialState::NoSave);
                if (verticalTitleBar) {
                    psg.save();
                    r = r.transposed();

                    p->translate(r.left(), r.top() + r.width());
                    p->rotate(-90);
                    p->translate(-r.left(), -r.top());
                }

                const int indent = p->fontMetrics().descent();
                proxy()->drawItemText(p, r.adjusted(indent + 1, 1, -indent - 1, -1),
                              Qt::AlignLeft | Qt::AlignVCenter | Qt::TextHideMnemonic, dwOpt->palette,
                              dwOpt->state & State_Enabled, dwOpt->title,
                              QPalette::WindowText);
            }
        }
        break;
#endif // QT_CONFIG(dockwidget)
    case CE_Header:
        if (const QStyleOptionHeader *header = qstyleoption_cast<const QStyleOptionHeader *>(opt)) {
            QRegion clipRegion = p->clipRegion();
            p->setClipRect(opt->rect);
            proxy()->drawControl(CE_HeaderSection, header, p, widget);
            // opt can be a QStyleOptionHeaderV2 and we must pass it to the subcontrol drawings
            QStyleOptionHeaderV2 subopt;
            QStyleOptionHeader &v1Copy = subopt;
            if (auto v2 = qstyleoption_cast<const QStyleOptionHeaderV2 *>(opt))
                subopt = *v2;
            else
                v1Copy = *header;
            subopt.rect = subElementRect(SE_HeaderLabel, header, widget);
            if (subopt.rect.isValid())
                proxy()->drawControl(CE_HeaderLabel, &subopt, p, widget);
            if (header->sortIndicator != QStyleOptionHeader::None) {
                subopt.rect = subElementRect(SE_HeaderArrow, opt, widget);
                proxy()->drawPrimitive(PE_IndicatorHeaderArrow, &subopt, p, widget);
            }
            p->setClipRegion(clipRegion);
        }
        break;
    case CE_FocusFrame:
            p->fillRect(opt->rect, opt->palette.windowText());
        break;
    case CE_HeaderSection:
            qDrawShadePanel(p, opt->rect, opt->palette,
                        opt->state & State_Sunken, 1,
                        &opt->palette.brush(QPalette::Button));
        break;
    case CE_HeaderEmptyArea:
            p->fillRect(opt->rect, opt->palette.window());
        break;
#if QT_CONFIG(combobox)
    case CE_ComboBoxLabel:
        if (const QStyleOptionComboBox *cb = qstyleoption_cast<const QStyleOptionComboBox *>(opt)) {
            QRect editRect = proxy()->subControlRect(CC_ComboBox, cb, SC_ComboBoxEditField, widget);
            QPainterStateGuard psg(p);
            p->setClipRect(editRect);
            if (!cb->currentIcon.isNull()) {
                QIcon::Mode mode = cb->state & State_Enabled ? QIcon::Normal
                                                             : QIcon::Disabled;
                QPixmap pixmap = cb->currentIcon.pixmap(cb->iconSize, QStyleHelper::getDpr(p), mode);
                QRect iconRect(editRect);
                iconRect.setWidth(cb->iconSize.width() + 4);
                iconRect = alignedRect(cb->direction,
                                       Qt::AlignLeft | Qt::AlignVCenter,
                                       iconRect.size(), editRect);
                if (cb->editable)
                    p->fillRect(iconRect, opt->palette.brush(QPalette::Base));
                proxy()->drawItemPixmap(p, iconRect, Qt::AlignCenter, pixmap);

                if (cb->direction == Qt::RightToLeft)
                    editRect.translate(-4 - cb->iconSize.width(), 0);
                else
                    editRect.translate(cb->iconSize.width() + 4, 0);
            }
            if (!cb->currentText.isEmpty() && !cb->editable) {
                // keep in sync with QLineEditPrivate::horizontalMargin = 2
                proxy()->drawItemText(p, editRect.adjusted(2, 0, -2, 0),
                             visualAlignment(cb->direction, cb->textAlignment),
                             cb->palette, cb->state & State_Enabled, cb->currentText);
            }
        }
        break;
#endif // QT_CONFIG(combobox)
#if QT_CONFIG(toolbar)
    case CE_ToolBar:
        if (const QStyleOptionToolBar *toolBar = qstyleoption_cast<const QStyleOptionToolBar *>(opt)) {
            // Compatibility with styles that use PE_PanelToolBar
            QStyleOptionFrame frame;
            frame.QStyleOption::operator=(*toolBar);
            frame.lineWidth = toolBar->lineWidth;
            frame.midLineWidth = toolBar->midLineWidth;
            proxy()->drawPrimitive(PE_PanelToolBar, opt, p, widget);

            if (widget && qobject_cast<QToolBar *>(widget->parentWidget()))
                break;
            qDrawShadePanel(p, toolBar->rect, toolBar->palette, false, toolBar->lineWidth,
                            &toolBar->palette.brush(QPalette::Button));
        }
        break;
#endif // QT_CONFIG(toolbar)
    case CE_ColumnViewGrip: {
        // draw background gradients
        QLinearGradient g(0, 0, opt->rect.width(), 0);
        g.setColorAt(0, opt->palette.color(QPalette::Active, QPalette::Mid));
        g.setColorAt(0.5, Qt::white);
        p->fillRect(QRect(0, 0, opt->rect.width(), opt->rect.height()), g);

        // draw the two lines
        QPen pen(p->pen());
        pen.setWidth(opt->rect.width()/20);
        pen.setColor(opt->palette.color(QPalette::Active, QPalette::Dark));
        p->setPen(pen);

        int line1starting = opt->rect.width()*8 / 20;
        int line2starting = opt->rect.width()*13 / 20;
        int top = opt->rect.height()*20/75;
        int bottom = opt->rect.height() - 1 - top;
        p->drawLine(line1starting, top, line1starting, bottom);
        p->drawLine(line2starting, top, line2starting, bottom);
        }
        break;

#if QT_CONFIG(itemviews)
    case CE_ItemViewItem:
        if (const QStyleOptionViewItem *vopt = qstyleoption_cast<const QStyleOptionViewItem *>(opt)) {
            QPainterStateGuard psg(p);
            // the style calling this might want to clip, so respect any region already set
            const QRegion clipRegion = p->hasClipping() ? (p->clipRegion() & opt->rect) : opt->rect;
            p->setClipRegion(clipRegion);

            QRect checkRect = proxy()->subElementRect(SE_ItemViewItemCheckIndicator, vopt, widget);
            QRect iconRect = proxy()->subElementRect(SE_ItemViewItemDecoration, vopt, widget);
            QRect textRect = proxy()->subElementRect(SE_ItemViewItemText, vopt, widget);

            // draw the background
            proxy()->drawPrimitive(PE_PanelItemViewItem, opt, p, widget);

            // draw the check mark
            if (vopt->features & QStyleOptionViewItem::HasCheckIndicator) {
                QStyleOptionViewItem option(*vopt);
                option.rect = checkRect;
                option.state = option.state & ~QStyle::State_HasFocus;

                switch (vopt->checkState) {
                case Qt::Unchecked:
                    option.state |= QStyle::State_Off;
                    break;
                case Qt::PartiallyChecked:
                    option.state |= QStyle::State_NoChange;
                    break;
                case Qt::Checked:
                    option.state |= QStyle::State_On;
                    break;
                }
                proxy()->drawPrimitive(QStyle::PE_IndicatorItemViewItemCheck, &option, p, widget);
            }

            // draw the icon
            QIcon::Mode mode = QIcon::Normal;
            if (!(vopt->state & QStyle::State_Enabled))
                mode = QIcon::Disabled;
            else if (vopt->state & QStyle::State_Selected)
                mode = QIcon::Selected;
            QIcon::State state = vopt->state & QStyle::State_Open ? QIcon::On : QIcon::Off;
            vopt->icon.paint(p, iconRect, vopt->decorationAlignment, mode, state);

            // draw the text
            if (!vopt->text.isEmpty()) {
                QPalette::ColorGroup cg = vopt->state & QStyle::State_Enabled
                                      ? QPalette::Normal : QPalette::Disabled;
                if (cg == QPalette::Normal && !(vopt->state & QStyle::State_Active))
                    cg = QPalette::Inactive;

                if (vopt->state & QStyle::State_Selected) {
                    p->setPen(vopt->palette.color(cg, QPalette::HighlightedText));
                } else {
                    p->setPen(vopt->palette.color(cg, QPalette::Text));
                }
                if (vopt->state & QStyle::State_Editing) {
                    p->setPen(vopt->palette.color(cg, QPalette::Text));
                    p->drawRect(textRect.adjusted(0, 0, -1, -1));
                }

                d->viewItemDrawText(p, vopt, textRect);
            }

            // draw the focus rect
             if (vopt->state & QStyle::State_HasFocus) {
                QStyleOptionFocusRect o;
                o.QStyleOption::operator=(*vopt);
                o.rect = proxy()->subElementRect(SE_ItemViewItemFocusRect, vopt, widget);
                o.state |= QStyle::State_KeyboardFocusChange;
                o.state |= QStyle::State_Item;
                QPalette::ColorGroup cg = (vopt->state & QStyle::State_Enabled)
                              ? QPalette::Normal : QPalette::Disabled;
                o.backgroundColor = vopt->palette.color(cg, (vopt->state & QStyle::State_Selected)
                                             ? QPalette::Highlight : QPalette::Window);
                proxy()->drawPrimitive(QStyle::PE_FrameFocusRect, &o, p, widget);
            }
        }
        break;

#endif // QT_CONFIG(itemviews)
#ifndef QT_NO_FRAME
    case CE_ShapedFrame:
        if (const QStyleOptionFrame *f = qstyleoption_cast<const QStyleOptionFrame *>(opt)) {
            int frameShape  = f->frameShape;
            int frameShadow = QFrame::Plain;
            if (f->state & QStyle::State_Sunken) {
                frameShadow = QFrame::Sunken;
            } else if (f->state & QStyle::State_Raised) {
                frameShadow = QFrame::Raised;
            }

            int lw = f->lineWidth;
            int mlw = f->midLineWidth;
            QPalette::ColorRole foregroundRole = QPalette::WindowText;
            if (widget)
                foregroundRole = widget->foregroundRole();

            switch (frameShape) {
            case QFrame::Box:
                if (frameShadow == QFrame::Plain) {
                    qDrawPlainRect(p, f->rect, f->palette.color(foregroundRole), lw);
                } else {
                    qDrawShadeRect(p, f->rect, f->palette, frameShadow == QFrame::Sunken, lw, mlw);
                }
                break;
            case QFrame::StyledPanel:
                //keep the compatibility with Qt 4.4 if there is a proxy style.
                //be sure to call drawPrimitive(QStyle::PE_Frame) on the proxy style
                if (widget) {
                    widget->style()->drawPrimitive(QStyle::PE_Frame, opt, p, widget);
                } else {
                    proxy()->drawPrimitive(QStyle::PE_Frame, opt, p, widget);
                }
                break;
            case QFrame::Panel:
                if (frameShadow == QFrame::Plain) {
                    qDrawPlainRect(p, f->rect, f->palette.color(foregroundRole), lw);
                } else {
                    qDrawShadePanel(p, f->rect, f->palette, frameShadow == QFrame::Sunken, lw);
                }
                break;
            case QFrame::WinPanel:
                if (frameShadow == QFrame::Plain) {
                    qDrawPlainRect(p, f->rect, f->palette.color(foregroundRole), lw);
                } else {
                    qDrawWinPanel(p, f->rect, f->palette, frameShadow == QFrame::Sunken);
                }
                break;
            case QFrame::HLine:
            case QFrame::VLine: {
                QPoint p1, p2;
                if (frameShape == QFrame::HLine) {
                    p1 = QPoint(opt->rect.x(), opt->rect.y() + opt->rect.height() / 2);
                    p2 = QPoint(opt->rect.x() + opt->rect.width(), p1.y());
                } else {
                    p1 = QPoint(opt->rect.x() + opt->rect.width() / 2, opt->rect.y());
                    p2 = QPoint(p1.x(), p1.y() + opt->rect.height());
                }
                if (frameShadow == QFrame::Plain) {
                    QPen oldPen = p->pen();
                    p->setPen(QPen(opt->palette.brush(foregroundRole), lw));
                    p->drawLine(p1, p2);
                    p->setPen(oldPen);
                } else {
                    qDrawShadeLine(p, p1, p2, f->palette, frameShadow == QFrame::Sunken, lw, mlw);
                }
                break;
                }
            }
        }
        break;
#endif
    default:
        break;
    }
#if !QT_CONFIG(tabbar) && !QT_CONFIG(itemviews)
    Q_UNUSED(d);
#endif
}

/*!
  \reimp
*/
QRect QCommonStyle::subElementRect(SubElement sr, const QStyleOption *opt,
                                   const QWidget *widget) const
{
    Q_D(const QCommonStyle);
    QRect r;
    switch (sr) {
    case SE_PushButtonContents:
        if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            int dx1, dx2;
            dx1 = proxy()->pixelMetric(PM_DefaultFrameWidth, btn, widget);
            if (btn->features & QStyleOptionButton::AutoDefaultButton)
                dx1 += proxy()->pixelMetric(PM_ButtonDefaultIndicator, btn, widget);
            dx2 = dx1 * 2;
            r.setRect(opt->rect.x() + dx1, opt->rect.y() + dx1, opt->rect.width() - dx2,
                      opt->rect.height() - dx2);
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;
    case SE_PushButtonFocusRect:
        if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            int dbw1 = 0, dbw2 = 0;
            if (btn->features & QStyleOptionButton::AutoDefaultButton){
                dbw1 = proxy()->pixelMetric(PM_ButtonDefaultIndicator, btn, widget);
                dbw2 = dbw1 * 2;
            }

            int dfw1 = proxy()->pixelMetric(PM_DefaultFrameWidth, btn, widget) + 1,
                dfw2 = dfw1 * 2;

            r.setRect(btn->rect.x() + dfw1 + dbw1, btn->rect.y() + dfw1 + dbw1,
                      btn->rect.width() - dfw2 - dbw2, btn->rect.height()- dfw2 - dbw2);
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;
    case SE_PushButtonBevel:
        {
            r = opt->rect;
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;
    case SE_CheckBoxIndicator:
        {
            int h = proxy()->pixelMetric(PM_IndicatorHeight, opt, widget);
            r.setRect(opt->rect.x(), opt->rect.y() + ((opt->rect.height() - h) / 2),
                      proxy()->pixelMetric(PM_IndicatorWidth, opt, widget), h);
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;

    case SE_CheckBoxContents:
        {
            // Deal with the logical first, then convert it back to screen coords.
            QRect ir = visualRect(opt->direction, opt->rect,
                                  subElementRect(SE_CheckBoxIndicator, opt, widget));
            int spacing = proxy()->pixelMetric(PM_CheckBoxLabelSpacing, opt, widget);
            r.setRect(ir.right() + spacing, opt->rect.y(), opt->rect.width() - ir.width() - spacing,
                      opt->rect.height());
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;

    case SE_CheckBoxFocusRect:
        if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            if (btn->icon.isNull() && btn->text.isEmpty()) {
                r = subElementRect(SE_CheckBoxIndicator, opt, widget);
                r.adjust(1, 1, -1, -1);
                break;
            }
            // As above, deal with the logical first, then convert it back to screen coords.
            QRect cr = visualRect(btn->direction, btn->rect,
                                  subElementRect(SE_CheckBoxContents, btn, widget));

            QRect iconRect, textRect;
            if (!btn->text.isEmpty()) {
                textRect = itemTextRect(opt->fontMetrics, cr, Qt::AlignAbsolute | Qt::AlignLeft
                                        | Qt::AlignVCenter | Qt::TextShowMnemonic,
                                        btn->state & State_Enabled, btn->text);
            }
            if (!btn->icon.isNull()) {
                iconRect = itemPixmapRect(cr, Qt::AlignAbsolute | Qt::AlignLeft | Qt::AlignVCenter
                                        | Qt::TextShowMnemonic,
                                   btn->icon.pixmap(btn->iconSize, QStyleHelper::getDpr(widget), QIcon::Normal));
                if (!textRect.isEmpty())
                    textRect.translate(iconRect.right() + 4, 0);
            }
            r = iconRect | textRect;
            r.adjust(-3, -2, 3, 2);
            r = r.intersected(btn->rect);
            r = visualRect(btn->direction, btn->rect, r);
        }
        break;

    case SE_RadioButtonIndicator:
        {
            int h = proxy()->pixelMetric(PM_ExclusiveIndicatorHeight, opt, widget);
            r.setRect(opt->rect.x(), opt->rect.y() + ((opt->rect.height() - h) / 2),
                    proxy()->pixelMetric(PM_ExclusiveIndicatorWidth, opt, widget), h);
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;

    case SE_RadioButtonContents:
        {
            QRect ir = visualRect(opt->direction, opt->rect,
                                  subElementRect(SE_RadioButtonIndicator, opt, widget));
            int spacing = proxy()->pixelMetric(PM_RadioButtonLabelSpacing, opt, widget);
            r.setRect(ir.left() + ir.width() + spacing, opt->rect.y(), opt->rect.width() - ir.width() - spacing,
                      opt->rect.height());
            r = visualRect(opt->direction, opt->rect, r);
            break;
        }

    case SE_RadioButtonFocusRect:
        if (const QStyleOptionButton *btn = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            if (btn->icon.isNull() && btn->text.isEmpty()) {
                r = subElementRect(SE_RadioButtonIndicator, opt, widget);
                r.adjust(1, 1, -1, -1);
                break;
            }
            QRect cr = visualRect(btn->direction, btn->rect,
                                  subElementRect(SE_RadioButtonContents, opt, widget));

            QRect iconRect, textRect;
            if (!btn->text.isEmpty()){
                textRect = itemTextRect(opt->fontMetrics, cr, Qt::AlignAbsolute | Qt::AlignLeft | Qt::AlignVCenter
                                 | Qt::TextShowMnemonic, btn->state & State_Enabled, btn->text);
            }
            if (!btn->icon.isNull()) {
                iconRect = itemPixmapRect(cr, Qt::AlignAbsolute | Qt::AlignLeft | Qt::AlignVCenter | Qt::TextShowMnemonic,
                                   btn->icon.pixmap(btn->iconSize, QStyleHelper::getDpr(widget), QIcon::Normal));
                if (!textRect.isEmpty())
                    textRect.translate(iconRect.right() + 4, 0);
            }
            r = iconRect | textRect;
            r.adjust(-3, -2, 3, 2);
            r = r.intersected(btn->rect);
            r = visualRect(btn->direction, btn->rect, r);
        }
        break;
#if QT_CONFIG(slider)
    case SE_SliderFocusRect:
        if (const QStyleOptionSlider *slider = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            int tickOffset = proxy()->pixelMetric(PM_SliderTickmarkOffset, slider, widget);
            int thickness  = proxy()->pixelMetric(PM_SliderControlThickness, slider, widget);
            if (slider->orientation == Qt::Horizontal)
                r.setRect(0, tickOffset - 1, slider->rect.width(), thickness + 2);
            else
                r.setRect(tickOffset - 1, 0, thickness + 2, slider->rect.height());
            r = r.intersected(slider->rect);
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;
#endif // QT_CONFIG(slider)
#if QT_CONFIG(progressbar)
    case SE_ProgressBarGroove:
    case SE_ProgressBarContents:
    case SE_ProgressBarLabel:
        if (const QStyleOptionProgressBar *pb = qstyleoption_cast<const QStyleOptionProgressBar *>(opt)) {
            int textw = 0;
            const bool vertical = !(pb->state & QStyle::State_Horizontal);
            if (!vertical) {
                if (pb->textVisible)
                    textw = qMax(pb->fontMetrics.horizontalAdvance(pb->text), pb->fontMetrics.horizontalAdvance("100%"_L1)) + 6;
            }

            if ((pb->textAlignment & Qt::AlignCenter) == 0) {
                if (sr != SE_ProgressBarLabel)
                    r.setCoords(pb->rect.left(), pb->rect.top(),
                                pb->rect.right() - textw, pb->rect.bottom());
                else
                    r.setCoords(pb->rect.right() - textw, pb->rect.top(),
                                pb->rect.right(), pb->rect.bottom());
            } else {
                r = pb->rect;
            }
            r = visualRect(pb->direction, pb->rect, r);
        }
        break;
#endif // QT_CONFIG(progressbar)
#if QT_CONFIG(combobox)
    case SE_ComboBoxFocusRect:
        if (const QStyleOptionComboBox *cb = qstyleoption_cast<const QStyleOptionComboBox *>(opt)) {
            int margin = cb->frame ? 3 : 0;
            r.setRect(opt->rect.left() + margin, opt->rect.top() + margin,
                      opt->rect.width() - 2*margin - 16, opt->rect.height() - 2*margin);
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;
#endif // QT_CONFIG(combobox)
#if QT_CONFIG(toolbox)
    case SE_ToolBoxTabContents:
        r = opt->rect;
        r.adjust(0, 0, -30, 0);
        break;
#endif // QT_CONFIG(toolbox)
    case SE_HeaderLabel: {
        int margin = proxy()->pixelMetric(QStyle::PM_HeaderMargin, opt, widget);
        r.setRect(opt->rect.x() + margin, opt->rect.y() + margin,
                  opt->rect.width() - margin * 2, opt->rect.height() - margin * 2);

        if (const QStyleOptionHeader *header = qstyleoption_cast<const QStyleOptionHeader *>(opt)) {
            // Subtract width needed for arrow, if there is one
            if (header->sortIndicator != QStyleOptionHeader::None) {
                if (opt->state & State_Horizontal)
                    r.setWidth(r.width() - (opt->rect.height() / 2) - (margin * 2));
                else
                    r.setHeight(r.height() - (opt->rect.width() / 2) - (margin * 2));
            }
        }
        r = visualRect(opt->direction, opt->rect, r);
        break; }
    case SE_HeaderArrow: {
        int h = opt->rect.height();
        int w = opt->rect.width();
        int x = opt->rect.x();
        int y = opt->rect.y();
        int margin = proxy()->pixelMetric(QStyle::PM_HeaderMargin, opt, widget);

        if (opt->state & State_Horizontal) {
            int horiz_size = h / 2;
            r.setRect(x + w - margin * 2 - horiz_size, y + 5,
                      horiz_size, h - margin * 2 - 5);
        } else {
            int vert_size = w / 2;
            r.setRect(x + 5, y + h - margin * 2 - vert_size,
                      w - margin * 2 - 5, vert_size);
        }
        r = visualRect(opt->direction, opt->rect, r);
        break; }

    case SE_RadioButtonClickRect:
        r = subElementRect(SE_RadioButtonFocusRect, opt, widget);
        r |= subElementRect(SE_RadioButtonIndicator, opt, widget);
        break;
    case SE_CheckBoxClickRect:
        r = subElementRect(SE_CheckBoxFocusRect, opt, widget);
        r |= subElementRect(SE_CheckBoxIndicator, opt, widget);
        break;
#if QT_CONFIG(tabwidget)
    case SE_TabWidgetTabBar:
        if (const QStyleOptionTabWidgetFrame *twf
                = qstyleoption_cast<const QStyleOptionTabWidgetFrame *>(opt)) {
            r.setSize(twf->tabBarSize);
            const uint alingMask = Qt::AlignLeft | Qt::AlignRight | Qt::AlignHCenter;
            switch (twf->shape) {
            case QTabBar::RoundedNorth:
            case QTabBar::TriangularNorth:
                // Constrain the size now, otherwise, center could get off the page
                // This of course repeated for all the other directions
                r.setWidth(qMin(r.width(), twf->rect.width()
                                            - twf->leftCornerWidgetSize.width()
                                            - twf->rightCornerWidgetSize.width()));
                switch (proxy()->styleHint(SH_TabBar_Alignment, twf, widget) & alingMask) {
                default:
                case Qt::AlignLeft:
                    r.moveTopLeft(QPoint(twf->leftCornerWidgetSize.width(), 0));
                    break;
                case Qt::AlignHCenter:
                    r.moveTopLeft(QPoint(twf->rect.center().x() - qRound(r.width() / 2.0f)
                                         + (twf->leftCornerWidgetSize.width() / 2)
                                         - (twf->rightCornerWidgetSize.width() / 2), 0));
                    break;
                case Qt::AlignRight:
                    r.moveTopLeft(QPoint(twf->rect.width() - twf->tabBarSize.width()
                                         - twf->rightCornerWidgetSize.width(), 0));
                    break;
                }
                r = visualRect(twf->direction, twf->rect, r);
                break;
            case QTabBar::RoundedSouth:
            case QTabBar::TriangularSouth:
                r.setWidth(qMin(r.width(), twf->rect.width()
                                            - twf->leftCornerWidgetSize.width()
                                            - twf->rightCornerWidgetSize.width()));
                switch (proxy()->styleHint(SH_TabBar_Alignment, twf, widget) & alingMask) {
                default:
                case Qt::AlignLeft:
                    r.moveTopLeft(QPoint(twf->leftCornerWidgetSize.width(),
                                         twf->rect.height() - twf->tabBarSize.height()));
                    break;
                case Qt::AlignHCenter:
                    r.moveTopLeft(QPoint(twf->rect.center().x() - qRound(r.width() / 2.0f)
                                         + (twf->leftCornerWidgetSize.width() / 2)
                                         - (twf->rightCornerWidgetSize.width() / 2),
                                         twf->rect.height() - twf->tabBarSize.height()));
                    break;
                case Qt::AlignRight:
                    r.moveTopLeft(QPoint(twf->rect.width() - twf->tabBarSize.width()
                                         - twf->rightCornerWidgetSize.width(),
                                         twf->rect.height() - twf->tabBarSize.height()));
                    break;
                }
                r = visualRect(twf->direction, twf->rect, r);
                break;
            case QTabBar::RoundedEast:
            case QTabBar::TriangularEast:
                r.setHeight(qMin(r.height(), twf->rect.height()
                                            - twf->leftCornerWidgetSize.height()
                                            - twf->rightCornerWidgetSize.height()));
                switch (proxy()->styleHint(SH_TabBar_Alignment, twf, widget) & alingMask) {
                default:
                case Qt::AlignLeft:
                    r.moveTopLeft(QPoint(twf->rect.width() - twf->tabBarSize.width(),
                                         twf->leftCornerWidgetSize.height()));
                    break;
                case Qt::AlignHCenter:
                    r.moveTopLeft(QPoint(twf->rect.width() - twf->tabBarSize.width(),
                                         twf->rect.center().y() - r.height() / 2));
                    break;
                case Qt::AlignRight:
                    r.moveTopLeft(QPoint(twf->rect.width() - twf->tabBarSize.width(),
                                         twf->rect.height() - twf->tabBarSize.height()
                                         - twf->rightCornerWidgetSize.height()));
                    break;
                }
                break;
            case QTabBar::RoundedWest:
            case QTabBar::TriangularWest:
                r.setHeight(qMin(r.height(), twf->rect.height()
                                             - twf->leftCornerWidgetSize.height()
                                             - twf->rightCornerWidgetSize.height()));
                switch (proxy()->styleHint(SH_TabBar_Alignment, twf, widget) & alingMask) {
                default:
                case Qt::AlignLeft:
                    r.moveTopLeft(QPoint(0, twf->leftCornerWidgetSize.height()));
                    break;
                case Qt::AlignHCenter:
                    r.moveTopLeft(QPoint(0, twf->rect.center().y() - r.height() / 2));
                    break;
                case Qt::AlignRight:
                    r.moveTopLeft(QPoint(0, twf->rect.height() - twf->tabBarSize.height()
                                         - twf->rightCornerWidgetSize.height()));
                    break;
                }
                break;
            }
        }
        break;
    case SE_TabWidgetTabPane:
    case SE_TabWidgetTabContents:
        if (const QStyleOptionTabWidgetFrame *twf = qstyleoption_cast<const QStyleOptionTabWidgetFrame *>(opt)) {
            QStyleOptionTab tabopt;
            tabopt.shape = twf->shape;
            int overlap = proxy()->pixelMetric(PM_TabBarBaseOverlap, &tabopt, widget);
            if (twf->lineWidth == 0)
                overlap = 0;
            switch (twf->shape) {
            case QTabBar::RoundedNorth:
            case QTabBar::TriangularNorth:
                r = QRect(QPoint(0,qMax(twf->tabBarSize.height() - overlap, 0)),
                          QSize(twf->rect.width(), qMin(twf->rect.height() - twf->tabBarSize.height() + overlap, twf->rect.height())));
                break;
            case QTabBar::RoundedSouth:
            case QTabBar::TriangularSouth:
                r = QRect(QPoint(0,0), QSize(twf->rect.width(), qMin(twf->rect.height() - twf->tabBarSize.height() + overlap, twf->rect.height())));
                break;
            case QTabBar::RoundedEast:
            case QTabBar::TriangularEast:
                r = QRect(QPoint(0, 0), QSize(qMin(twf->rect.width() - twf->tabBarSize.width() + overlap, twf->rect.width()), twf->rect.height()));
                break;
            case QTabBar::RoundedWest:
            case QTabBar::TriangularWest:
                r = QRect(QPoint(qMax(twf->tabBarSize.width() - overlap, 0), 0),
                          QSize(qMin(twf->rect.width() - twf->tabBarSize.width() + overlap, twf->rect.width()), twf->rect.height()));
                break;
            }
            if (sr == SE_TabWidgetTabContents && twf->lineWidth > 0)
               r.adjust(2, 2, -2, -2);
        }
        break;
    case SE_TabWidgetLeftCorner:
        if (const QStyleOptionTabWidgetFrame *twf = qstyleoption_cast<const QStyleOptionTabWidgetFrame *>(opt)) {
            QRect paneRect = subElementRect(SE_TabWidgetTabPane, twf, widget);
            switch (twf->shape) {
            case QTabBar::RoundedNorth:
            case QTabBar::TriangularNorth:
                r = QRect(QPoint(paneRect.x(), paneRect.y() - twf->leftCornerWidgetSize.height()),
                          twf->leftCornerWidgetSize);
                break;
            case QTabBar::RoundedSouth:
            case QTabBar::TriangularSouth:
                r = QRect(QPoint(paneRect.x(), paneRect.height()), twf->leftCornerWidgetSize);
               break;
            default:
               break;
            }
           r = visualRect(twf->direction, twf->rect, r);
        }
        break;
   case SE_TabWidgetRightCorner:
       if (const QStyleOptionTabWidgetFrame *twf = qstyleoption_cast<const QStyleOptionTabWidgetFrame *>(opt)) {
           QRect paneRect = subElementRect(SE_TabWidgetTabPane, twf, widget);
           switch (twf->shape) {
           case QTabBar::RoundedNorth:
           case QTabBar::TriangularNorth:
                r = QRect(QPoint(paneRect.width() - twf->rightCornerWidgetSize.width(),
                                 paneRect.y() - twf->rightCornerWidgetSize.height()),
                          twf->rightCornerWidgetSize);
               break;
           case QTabBar::RoundedSouth:
           case QTabBar::TriangularSouth:
                r = QRect(QPoint(paneRect.width() - twf->rightCornerWidgetSize.width(),
                                 paneRect.height()), twf->rightCornerWidgetSize);
               break;
           default:
               break;
           }
           r = visualRect(twf->direction, twf->rect, r);
        }
        break;
    case SE_TabBarTabText:
        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(opt)) {
            QRect dummyIconRect;
            d->tabLayout(tab, widget, &r, &dummyIconRect);
        }
        break;
    case SE_TabBarTabLeftButton:
    case SE_TabBarTabRightButton:
        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(opt)) {
            bool selected = tab->state & State_Selected;
            int verticalShift = proxy()->pixelMetric(QStyle::PM_TabBarTabShiftVertical, tab, widget);
            int horizontalShift = proxy()->pixelMetric(QStyle::PM_TabBarTabShiftHorizontal, tab, widget);
            int hpadding = proxy()->pixelMetric(QStyle::PM_TabBarTabHSpace, opt, widget) / 2;
            hpadding = qMax(hpadding, 4); //workaround KStyle returning 0 because they workaround an old bug in Qt

            bool verticalTabs = tab->shape == QTabBar::RoundedEast
                    || tab->shape == QTabBar::RoundedWest
                    || tab->shape == QTabBar::TriangularEast
                    || tab->shape == QTabBar::TriangularWest;

            QRect tr = tab->rect;
            if (tab->shape == QTabBar::RoundedSouth || tab->shape == QTabBar::TriangularSouth)
                verticalShift = -verticalShift;
            if (verticalTabs) {
                qSwap(horizontalShift, verticalShift);
                horizontalShift *= -1;
                verticalShift *= -1;
            }
            if (tab->shape == QTabBar::RoundedWest || tab->shape == QTabBar::TriangularWest)
                horizontalShift = -horizontalShift;

            tr.adjust(0, 0, horizontalShift, verticalShift);
            if (selected)
            {
                tr.setBottom(tr.bottom() - verticalShift);
                tr.setRight(tr.right() - horizontalShift);
            }

            QSize size = (sr == SE_TabBarTabLeftButton) ? tab->leftButtonSize : tab->rightButtonSize;
            int w = size.width();
            int h = size.height();
            int midHeight = static_cast<int>(qCeil(float(tr.height() - h) / 2));
            int midWidth = ((tr.width() - w) / 2);

            bool atTheTop = true;
            switch (tab->shape) {
            case QTabBar::RoundedWest:
            case QTabBar::TriangularWest:
                atTheTop = (sr == SE_TabBarTabLeftButton);
                break;
            case QTabBar::RoundedEast:
            case QTabBar::TriangularEast:
                atTheTop = (sr == SE_TabBarTabRightButton);
                break;
            default:
                if (sr == SE_TabBarTabLeftButton)
                    r = QRect(tab->rect.x() + hpadding, midHeight, w, h);
                else
                    r = QRect(tab->rect.right() - w - hpadding, midHeight, w, h);
                r = visualRect(tab->direction, tab->rect, r);
            }
            if (verticalTabs) {
                if (atTheTop)
                    r = QRect(midWidth, tr.y() + tab->rect.height() - hpadding - h, w, h);
                else
                    r = QRect(midWidth, tr.y() + hpadding, w, h);
            }
        }

        break;
#endif // QT_CONFIG(tabwidget)
#if QT_CONFIG(tabbar)
    case SE_TabBarTearIndicator:
        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(opt)) {
            switch (tab->shape) {
            case QTabBar::RoundedNorth:
            case QTabBar::TriangularNorth:
            case QTabBar::RoundedSouth:
            case QTabBar::TriangularSouth:
                r.setRect(tab->rect.left(), tab->rect.top(), 8, opt->rect.height());
                break;
            case QTabBar::RoundedWest:
            case QTabBar::TriangularWest:
            case QTabBar::RoundedEast:
            case QTabBar::TriangularEast:
                r.setRect(tab->rect.left(), tab->rect.top(), opt->rect.width(), 8);
                break;
            default:
                break;
            }
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;
    case SE_TabBarScrollLeftButton: {
        const bool vertical = opt->rect.width() < opt->rect.height();
        const Qt::LayoutDirection ld = widget->layoutDirection();
        const int buttonWidth = proxy()->pixelMetric(QStyle::PM_TabBarScrollButtonWidth, nullptr, widget);
        const int buttonOverlap = proxy()->pixelMetric(QStyle::PM_TabBar_ScrollButtonOverlap, nullptr, widget);

        r = vertical ? QRect(0, opt->rect.height() - (buttonWidth * 2) + buttonOverlap, opt->rect.width(), buttonWidth)
            : QStyle::visualRect(ld, opt->rect, QRect(opt->rect.width() - (buttonWidth * 2) + buttonOverlap, 0, buttonWidth, opt->rect.height()));
        break; }
    case SE_TabBarScrollRightButton: {
        const bool vertical = opt->rect.width() < opt->rect.height();
        const Qt::LayoutDirection ld = widget->layoutDirection();
        const int buttonWidth = proxy()->pixelMetric(QStyle::PM_TabBarScrollButtonWidth, nullptr, widget);

        r = vertical ? QRect(0, opt->rect.height() - buttonWidth, opt->rect.width(), buttonWidth)
            : QStyle::visualRect(ld, opt->rect, QRect(opt->rect.width() - buttonWidth, 0, buttonWidth, opt->rect.height()));
        break; }
#endif
    case SE_TreeViewDisclosureItem:
        r = opt->rect;
        break;
    case SE_LineEditContents:
        if (const QStyleOptionFrame *f = qstyleoption_cast<const QStyleOptionFrame *>(opt)) {
            r = f->rect.adjusted(f->lineWidth, f->lineWidth, -f->lineWidth, -f->lineWidth);
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;
    case SE_FrameContents:
        if (const QStyleOptionFrame *f = qstyleoption_cast<const QStyleOptionFrame *>(opt)) {
            int fw = proxy()->pixelMetric(PM_DefaultFrameWidth, f, widget);
            r = opt->rect.adjusted(fw, fw, -fw, -fw);
            r = visualRect(opt->direction, opt->rect, r);
        }
        break;
    case SE_ShapedFrameContents:
        if (const QStyleOptionFrame *f = qstyleoption_cast<const QStyleOptionFrame *>(opt)) {
            int frameShape  = f->frameShape;
            int frameShadow = QFrame::Plain;
            if (f->state & QStyle::State_Sunken) {
                frameShadow = QFrame::Sunken;
            } else if (f->state & QStyle::State_Raised) {
                frameShadow = QFrame::Raised;
            }

            int frameWidth = 0;

            switch (frameShape) {
            case QFrame::NoFrame:
                frameWidth = 0;
                break;

            case QFrame::Box:
            case QFrame::HLine:
            case QFrame::VLine:
                switch (frameShadow) {
                case QFrame::Plain:
                    frameWidth = f->lineWidth;
                    break;
                case QFrame::Raised:
                case QFrame::Sunken:
                    frameWidth = (short)(f->lineWidth*2 + f->midLineWidth);
                    break;
                }
                break;

            case QFrame::StyledPanel:
                //keep the compatibility with Qt 4.4 if there is a proxy style.
                //be sure to call drawPrimitive(QStyle::SE_FrameContents) on the proxy style
                if (widget)
                    return widget->style()->subElementRect(QStyle::SE_FrameContents, opt, widget);
                else
                    return subElementRect(QStyle::SE_FrameContents, opt, widget);

            case QFrame::WinPanel:
                frameWidth = 2;
                break;

            case QFrame::Panel:
                switch (frameShadow) {
                case QFrame::Plain:
                case QFrame::Raised:
                case QFrame::Sunken:
                    frameWidth = f->lineWidth;
                    break;
                }
                break;
            }
            r = f->rect.adjusted(frameWidth, frameWidth, -frameWidth, -frameWidth);
        }
        break;
#if QT_CONFIG(dockwidget)
    case SE_DockWidgetCloseButton:
    case SE_DockWidgetFloatButton:
    case SE_DockWidgetTitleBarText:
    case SE_DockWidgetIcon: {
        int iconSize = proxy()->pixelMetric(PM_SmallIconSize, opt, widget);
        int buttonMargin = proxy()->pixelMetric(PM_DockWidgetTitleBarButtonMargin, opt, widget);
        int margin = proxy()->pixelMetric(QStyle::PM_DockWidgetTitleMargin, opt, widget);
        QRect rect = opt->rect;

        const QStyleOptionDockWidget *dwOpt
            = qstyleoption_cast<const QStyleOptionDockWidget*>(opt);
        bool canClose = dwOpt == nullptr ? true : dwOpt->closable;
        bool canFloat = dwOpt == nullptr ? false : dwOpt->floatable;

        const bool verticalTitleBar = dwOpt && dwOpt->verticalTitleBar;

        // If this is a vertical titlebar, we transpose and work as if it was
        // horizontal, then transpose again.

        if (verticalTitleBar)
            rect = rect.transposed();

        do {

            int right = rect.right();
            int left = rect.left();

            QRect closeRect;
            if (canClose) {
                QSize sz = proxy()->standardIcon(QStyle::SP_TitleBarCloseButton,
                                        opt, widget).actualSize(QSize(iconSize, iconSize));
                sz += QSize(buttonMargin, buttonMargin);
                if (verticalTitleBar)
                    sz = sz.transposed();
                closeRect = QRect(right - sz.width(),
                                    rect.center().y() - sz.height()/2,
                                    sz.width(), sz.height());
                right = closeRect.left() - 1;
            }
            if (sr == SE_DockWidgetCloseButton) {
                r = closeRect;
                break;
            }

            QRect floatRect;
            if (canFloat) {
                QSize sz = proxy()->standardIcon(QStyle::SP_TitleBarNormalButton,
                                        opt, widget).actualSize(QSize(iconSize, iconSize));
                sz += QSize(buttonMargin, buttonMargin);
                if (verticalTitleBar)
                    sz = sz.transposed();
                floatRect = QRect(right - sz.width(),
                                    rect.center().y() - sz.height()/2,
                                    sz.width(), sz.height());
                right = floatRect.left() - 1;
            }
            if (sr == SE_DockWidgetFloatButton) {
                r = floatRect;
                break;
            }

            QRect iconRect;
            if (const QDockWidget *dw = qobject_cast<const QDockWidget*>(widget)) {
                QIcon icon;
                if (dw->isFloating())
                    icon = dw->windowIcon();
                if (!icon.isNull()
                        && icon.cacheKey() != QApplication::windowIcon().cacheKey()) {
                    QSize sz = icon.actualSize(QSize(r.height(), r.height()));
                    if (verticalTitleBar)
                        sz = sz.transposed();
                    iconRect = QRect(left, rect.center().y() - sz.height()/2,
                                        sz.width(), sz.height());
                    left = iconRect.right() + margin;
                }
            }
            if (sr == SE_DockWidgetIcon) {
                r = iconRect;
                break;
            }

            QRect textRect = QRect(left, rect.top(),
                                    right - left, rect.height());
            if (sr == SE_DockWidgetTitleBarText) {
                r = textRect;
                break;
            }

        } while (false);

        if (verticalTitleBar) {
            r = QRect(rect.left() + r.top() - rect.top(),
                        rect.top() + rect.right() - r.right(),
                        r.height(), r.width());
        } else {
            r = visualRect(opt->direction, rect, r);
        }
        break;
    }
#endif
#if QT_CONFIG(itemviews)
    case SE_ItemViewItemCheckIndicator:
        if (!qstyleoption_cast<const QStyleOptionViewItem *>(opt)) {
            r = subElementRect(SE_CheckBoxIndicator, opt, widget);
            break;
        }
        Q_FALLTHROUGH();
    case SE_ItemViewItemDecoration:
    case SE_ItemViewItemText:
    case SE_ItemViewItemFocusRect:
        if (const QStyleOptionViewItem *vopt = qstyleoption_cast<const QStyleOptionViewItem *>(opt)) {
            if (!d->isViewItemCached(*vopt)) {
                d->viewItemLayout(vopt, &d->checkRect, &d->decorationRect, &d->displayRect, false);
                if (d->cachedOption) {
                    delete d->cachedOption;
                    d->cachedOption = nullptr;
                }
                d->cachedOption = new QStyleOptionViewItem(*vopt);
            }
            if (sr == SE_ItemViewItemCheckIndicator)
                r = d->checkRect;
            else if (sr == SE_ItemViewItemDecoration)
                r = d->decorationRect;
            else if (sr == SE_ItemViewItemText || sr == SE_ItemViewItemFocusRect)
                r = d->displayRect;
                               }
        break;
#endif // QT_CONFIG(itemviews)
#if QT_CONFIG(toolbar)
    case SE_ToolBarHandle:
        if (const QStyleOptionToolBar *tbopt = qstyleoption_cast<const QStyleOptionToolBar *>(opt)) {
            if (tbopt->features & QStyleOptionToolBar::Movable) {
                ///we need to access the widget here because the style option doesn't
                //have all the information we need (ie. the layout's margin)
                const QToolBar *tb = qobject_cast<const QToolBar*>(widget);
                const QMargins margins = tb && tb->layout() ? tb->layout()->contentsMargins() : QMargins(2, 2, 2, 2);
                const int handleExtent = proxy()->pixelMetric(QStyle::PM_ToolBarHandleExtent, opt, tb);
                if (tbopt->state & QStyle::State_Horizontal) {
                    r = QRect(margins.left(), margins.top(),
                              handleExtent,
                              tbopt->rect.height() - (margins.top() + margins.bottom()));
                    r = QStyle::visualRect(tbopt->direction, tbopt->rect, r);
                } else {
                    r = QRect(margins.left(), margins.top(),
                              tbopt->rect.width() - (margins.left() + margins.right()),
                              handleExtent);
                }
            }
        }
        break;
#endif // QT_CONFIG(toolbar)
    default:
        break;
    }
    return r;
#if !QT_CONFIG(tabwidget) && !QT_CONFIG(itemviews)
    Q_UNUSED(d);
#endif
}

#if QT_CONFIG(dial)

// in lieu of std::array, minimal API
template <int N>
struct StaticPolygonF
{
    QPointF data[N];

    constexpr int size() const { return N; }
    constexpr const QPointF *cbegin() const { return data; }
    constexpr const QPointF &operator[](int idx) const { return data[idx]; }
};

static StaticPolygonF<3> calcArrow(const QStyleOptionSlider *dial, qreal &a)
{
    int width = dial->rect.width();
    int height = dial->rect.height();
    int r = qMin(width, height) / 2;
    int currentSliderPosition = dial->upsideDown ? dial->sliderPosition : (dial->maximum - dial->sliderPosition);

    if (dial->maximum == dial->minimum)
        a = Q_PI / 2;
    else if (dial->dialWrapping)
        a = Q_PI * 3 / 2 - (currentSliderPosition - dial->minimum) * 2 * Q_PI
            / (dial->maximum - dial->minimum);
    else
        a = (Q_PI * 8 - (currentSliderPosition - dial->minimum) * 10 * Q_PI
            / (dial->maximum - dial->minimum)) / 6;

    int xc = width / 2 + dial->rect.left();
    int yc = height / 2 + dial->rect.top();

    int len = r - QStyleHelper::calcBigLineSize(r) - 5;
    if (len < 5)
        len = 5;
    int back = len / 2;

    StaticPolygonF<3> arrow = {{
        QPointF(0.5 + xc + len * qCos(a),
                0.5 + yc - len * qSin(a)),
        QPointF(0.5 + xc + back * qCos(a + Q_PI * 5 / 6),
                0.5 + yc - back * qSin(a + Q_PI * 5 / 6)),
        QPointF(0.5 + xc + back * qCos(a - Q_PI * 5 / 6),
                0.5 + yc - back * qSin(a - Q_PI * 5 / 6)),
    }};
    return arrow;
}

#endif // QT_CONFIG(dial)

/*!
  \reimp
*/
void QCommonStyle::drawComplexControl(ComplexControl cc, const QStyleOptionComplex *opt,
                                      QPainter *p, const QWidget *widget) const
{
    switch (cc) {
#if QT_CONFIG(slider)
    case CC_Slider:
        if (const QStyleOptionSlider *slider = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            if (slider->subControls == SC_SliderTickmarks) {
                int tickOffset = proxy()->pixelMetric(PM_SliderTickmarkOffset, slider, widget);
                int ticks = slider->tickPosition;
                int thickness = proxy()->pixelMetric(PM_SliderControlThickness, slider, widget);
                int len = proxy()->pixelMetric(PM_SliderLength, slider, widget);
                int available = proxy()->pixelMetric(PM_SliderSpaceAvailable, slider, widget);
                int interval = slider->tickInterval;
                if (interval <= 0) {
                    interval = slider->singleStep;
                    if (QStyle::sliderPositionFromValue(slider->minimum, slider->maximum, interval,
                                                        available)
                        - QStyle::sliderPositionFromValue(slider->minimum, slider->maximum,
                                                          0, available) < 3)
                        interval = slider->pageStep;
                }
                if (!interval)
                    interval = 1;
                int fudge = len / 2;
                int pos;
                // Since there is no subrect for tickmarks do a translation here.
                QPainterStateGuard psg(p);
                p->translate(slider->rect.x(), slider->rect.y());
                p->setPen(slider->palette.windowText().color());
                int v = slider->minimum;
                while (v <= slider->maximum + 1) {
                    if (v == slider->maximum + 1 && interval == 1)
                        break;
                    const int v_ = qMin(v, slider->maximum);
                    pos = QStyle::sliderPositionFromValue(slider->minimum, slider->maximum,
                                                          v_, available) + fudge;
                    if (slider->orientation == Qt::Horizontal) {
                        if (ticks & QSlider::TicksAbove)
                            p->drawLine(pos, 0, pos, tickOffset - 2);
                        if (ticks & QSlider::TicksBelow)
                            p->drawLine(pos, tickOffset + thickness + 1, pos,
                                        slider->rect.height()-1);
                    } else {
                        if (ticks & QSlider::TicksAbove)
                            p->drawLine(0, pos, tickOffset - 2, pos);
                        if (ticks & QSlider::TicksBelow)
                            p->drawLine(tickOffset + thickness + 1, pos,
                                        slider->rect.width()-1, pos);
                    }
                    // in the case where maximum is max int
                    int nextInterval = v + interval;
                    if (nextInterval < v)
                        break;
                    v = nextInterval;
                }
            }
        }
        break;
#endif // QT_CONFIG(slider)
#if QT_CONFIG(scrollbar)
    case CC_ScrollBar:
        if (const QStyleOptionSlider *scrollbar = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            // Make a copy here and reset it for each primitive.
            QStyleOptionSlider newScrollbar = *scrollbar;
            State saveFlags = scrollbar->state;

            if (scrollbar->subControls & SC_ScrollBarSubLine) {
                newScrollbar.state = saveFlags;
                newScrollbar.rect = proxy()->subControlRect(cc, &newScrollbar, SC_ScrollBarSubLine, widget);
                if (newScrollbar.rect.isValid()) {
                    if (!(scrollbar->activeSubControls & SC_ScrollBarSubLine))
                        newScrollbar.state &= ~(State_Sunken | State_MouseOver);
                    proxy()->drawControl(CE_ScrollBarSubLine, &newScrollbar, p, widget);
                }
            }
            if (scrollbar->subControls & SC_ScrollBarAddLine) {
                newScrollbar.rect = scrollbar->rect;
                newScrollbar.state = saveFlags;
                newScrollbar.rect = proxy()->subControlRect(cc, &newScrollbar, SC_ScrollBarAddLine, widget);
                if (newScrollbar.rect.isValid()) {
                    if (!(scrollbar->activeSubControls & SC_ScrollBarAddLine))
                        newScrollbar.state &= ~(State_Sunken | State_MouseOver);
                    proxy()->drawControl(CE_ScrollBarAddLine, &newScrollbar, p, widget);
                }
            }
            if (scrollbar->subControls & SC_ScrollBarSubPage) {
                newScrollbar.rect = scrollbar->rect;
                newScrollbar.state = saveFlags;
                newScrollbar.rect = proxy()->subControlRect(cc, &newScrollbar, SC_ScrollBarSubPage, widget);
                if (newScrollbar.rect.isValid()) {
                    if (!(scrollbar->activeSubControls & SC_ScrollBarSubPage))
                        newScrollbar.state &= ~(State_Sunken | State_MouseOver);
                    proxy()->drawControl(CE_ScrollBarSubPage, &newScrollbar, p, widget);
                }
            }
            if (scrollbar->subControls & SC_ScrollBarAddPage) {
                newScrollbar.rect = scrollbar->rect;
                newScrollbar.state = saveFlags;
                newScrollbar.rect = proxy()->subControlRect(cc, &newScrollbar, SC_ScrollBarAddPage, widget);
                if (newScrollbar.rect.isValid()) {
                    if (!(scrollbar->activeSubControls & SC_ScrollBarAddPage))
                        newScrollbar.state &= ~(State_Sunken | State_MouseOver);
                    proxy()->drawControl(CE_ScrollBarAddPage, &newScrollbar, p, widget);
                }
            }
            if (scrollbar->subControls & SC_ScrollBarFirst) {
                newScrollbar.rect = scrollbar->rect;
                newScrollbar.state = saveFlags;
                newScrollbar.rect = proxy()->subControlRect(cc, &newScrollbar, SC_ScrollBarFirst, widget);
                if (newScrollbar.rect.isValid()) {
                    if (!(scrollbar->activeSubControls & SC_ScrollBarFirst))
                        newScrollbar.state &= ~(State_Sunken | State_MouseOver);
                    proxy()->drawControl(CE_ScrollBarFirst, &newScrollbar, p, widget);
                }
            }
            if (scrollbar->subControls & SC_ScrollBarLast) {
                newScrollbar.rect = scrollbar->rect;
                newScrollbar.state = saveFlags;
                newScrollbar.rect = proxy()->subControlRect(cc, &newScrollbar, SC_ScrollBarLast, widget);
                if (newScrollbar.rect.isValid()) {
                    if (!(scrollbar->activeSubControls & SC_ScrollBarLast))
                        newScrollbar.state &= ~(State_Sunken | State_MouseOver);
                    proxy()->drawControl(CE_ScrollBarLast, &newScrollbar, p, widget);
                }
            }
            if (scrollbar->subControls & SC_ScrollBarSlider) {
                newScrollbar.rect = scrollbar->rect;
                newScrollbar.state = saveFlags;
                newScrollbar.rect = proxy()->subControlRect(cc, &newScrollbar, SC_ScrollBarSlider, widget);
                if (newScrollbar.rect.isValid()) {
                    if (!(scrollbar->activeSubControls & SC_ScrollBarSlider))
                        newScrollbar.state &= ~(State_Sunken | State_MouseOver);
                    proxy()->drawControl(CE_ScrollBarSlider, &newScrollbar, p, widget);

                    if (scrollbar->state & State_HasFocus) {
                        QStyleOptionFocusRect fropt;
                        fropt.QStyleOption::operator=(newScrollbar);
                        fropt.rect.setRect(newScrollbar.rect.x() + 2, newScrollbar.rect.y() + 2,
                                           newScrollbar.rect.width() - 5,
                                           newScrollbar.rect.height() - 5);
                        proxy()->drawPrimitive(PE_FrameFocusRect, &fropt, p, widget);
                    }
                }
            }
        }
        break;
#endif // QT_CONFIG(scrollbar)
#if QT_CONFIG(spinbox)
    case CC_SpinBox:
        if (const QStyleOptionSpinBox *sb = qstyleoption_cast<const QStyleOptionSpinBox *>(opt)) {
            QStyleOptionSpinBox copy = *sb;
            PrimitiveElement pe;

            if (sb->frame && (sb->subControls & SC_SpinBoxFrame)) {
                QRect r = proxy()->subControlRect(CC_SpinBox, sb, SC_SpinBoxFrame, widget);
                qDrawWinPanel(p, r, sb->palette, true);
            }

            if (sb->subControls & SC_SpinBoxUp) {
                copy.subControls = SC_SpinBoxUp;
                QPalette pal2 = sb->palette;
                if (!(sb->stepEnabled & QAbstractSpinBox::StepUpEnabled)) {
                    pal2.setCurrentColorGroup(QPalette::Disabled);
                    copy.state &= ~State_Enabled;
                }

                copy.palette = pal2;

                if (sb->activeSubControls == SC_SpinBoxUp && (sb->state & State_Sunken)) {
                    copy.state |= State_On;
                    copy.state |= State_Sunken;
                } else {
                    copy.state |= State_Raised;
                    copy.state &= ~State_Sunken;
                }
                pe = (sb->buttonSymbols == QAbstractSpinBox::PlusMinus ? PE_IndicatorSpinPlus
                      : PE_IndicatorSpinUp);

                copy.rect = proxy()->subControlRect(CC_SpinBox, sb, SC_SpinBoxUp, widget);
                proxy()->drawPrimitive(PE_PanelButtonBevel, &copy, p, widget);
                copy.rect.adjust(3, 0, -4, 0);
                proxy()->drawPrimitive(pe, &copy, p, widget);
            }

            if (sb->subControls & SC_SpinBoxDown) {
                copy.subControls = SC_SpinBoxDown;
                copy.state = sb->state;
                QPalette pal2 = sb->palette;
                if (!(sb->stepEnabled & QAbstractSpinBox::StepDownEnabled)) {
                    pal2.setCurrentColorGroup(QPalette::Disabled);
                    copy.state &= ~State_Enabled;
                }
                copy.palette = pal2;

                if (sb->activeSubControls == SC_SpinBoxDown && (sb->state & State_Sunken)) {
                    copy.state |= State_On;
                    copy.state |= State_Sunken;
                } else {
                    copy.state |= State_Raised;
                    copy.state &= ~State_Sunken;
                }
                pe = (sb->buttonSymbols == QAbstractSpinBox::PlusMinus ? PE_IndicatorSpinMinus
                      : PE_IndicatorSpinDown);

                copy.rect = proxy()->subControlRect(CC_SpinBox, sb, SC_SpinBoxDown, widget);
                proxy()->drawPrimitive(PE_PanelButtonBevel, &copy, p, widget);
                copy.rect.adjust(3, 0, -4, 0);
                proxy()->drawPrimitive(pe, &copy, p, widget);
            }
        }
        break;
#endif // QT_CONFIG(spinbox)
#if QT_CONFIG(toolbutton)
    case CC_ToolButton:
        if (const QStyleOptionToolButton *toolbutton
            = qstyleoption_cast<const QStyleOptionToolButton *>(opt)) {
            QRect button, menuarea;
            button = proxy()->subControlRect(cc, toolbutton, SC_ToolButton, widget);
            menuarea = proxy()->subControlRect(cc, toolbutton, SC_ToolButtonMenu, widget);

            State bflags = toolbutton->state & ~State_Sunken;

            if (bflags & State_AutoRaise) {
                if (!(bflags & State_MouseOver) || !(bflags & State_Enabled)) {
                    bflags &= ~State_Raised;
                }
            }
            State mflags = bflags;
            if (toolbutton->state & State_Sunken) {
                if (toolbutton->activeSubControls & SC_ToolButton)
                    bflags |= State_Sunken;
                mflags |= State_Sunken;
            }

            QStyleOption tool = *toolbutton;
            if (toolbutton->subControls & SC_ToolButton) {
                if (bflags & (State_Sunken | State_On | State_Raised)) {
                    tool.rect = button;
                    tool.state = bflags;
                    proxy()->drawPrimitive(PE_PanelButtonTool, &tool, p, widget);
                }
            }

            if (toolbutton->state & State_HasFocus) {
                QStyleOptionFocusRect fr;
                fr.QStyleOption::operator=(*toolbutton);
                fr.rect.adjust(3, 3, -3, -3);
                if (toolbutton->features & QStyleOptionToolButton::MenuButtonPopup)
                    fr.rect.adjust(0, 0, -proxy()->pixelMetric(QStyle::PM_MenuButtonIndicator,
                                                      toolbutton, widget), 0);
                proxy()->drawPrimitive(PE_FrameFocusRect, &fr, p, widget);
            }
            QStyleOptionToolButton label = *toolbutton;
            label.state = bflags;
            int fw = proxy()->pixelMetric(PM_DefaultFrameWidth, opt, widget);
            label.rect = button.adjusted(fw, fw, -fw, -fw);
            proxy()->drawControl(CE_ToolButtonLabel, &label, p, widget);

            if (toolbutton->subControls & SC_ToolButtonMenu) {
                tool.rect = menuarea;
                tool.state = mflags;
                if (mflags & (State_Sunken | State_On | State_Raised))
                    proxy()->drawPrimitive(PE_IndicatorButtonDropDown, &tool, p, widget);
                proxy()->drawPrimitive(PE_IndicatorArrowDown, &tool, p, widget);
            } else if (toolbutton->features & QStyleOptionToolButton::HasMenu) {
                int mbi = proxy()->pixelMetric(PM_MenuButtonIndicator, toolbutton, widget);
                QRect ir = toolbutton->rect;
                QStyleOptionToolButton newBtn = *toolbutton;
                newBtn.rect = QRect(ir.right() + 5 - mbi, ir.y() + ir.height() - mbi + 4, mbi - 6, mbi - 6);
                newBtn.rect = visualRect(toolbutton->direction, button, newBtn.rect);
                proxy()->drawPrimitive(PE_IndicatorArrowDown, &newBtn, p, widget);
            }
        }
        break;
#endif // QT_CONFIG(toolbutton)
    case CC_TitleBar:
        if (const QStyleOptionTitleBar *tb = qstyleoption_cast<const QStyleOptionTitleBar *>(opt)) {
            QRect ir;
            if (opt->subControls & SC_TitleBarLabel) {
                QColor left = tb->palette.highlight().color();
                QColor right = tb->palette.base().color();

                QBrush fillBrush(left);
                if (left != right) {
                    QPoint p1(tb->rect.x(), tb->rect.top() + tb->rect.height()/2);
                    QPoint p2(tb->rect.right(), tb->rect.top() + tb->rect.height()/2);
                    QLinearGradient lg(p1, p2);
                    lg.setColorAt(0, left);
                    lg.setColorAt(1, right);
                    fillBrush = lg;
                }

                p->fillRect(opt->rect, fillBrush);

                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarLabel, widget);

                p->setPen(tb->palette.highlightedText().color());
                p->drawText(ir.x() + 2, ir.y(), ir.width() - 2, ir.height(),
                            Qt::AlignLeft | Qt::AlignVCenter | Qt::TextSingleLine, tb->text);
            }

            bool down = false;
            QPixmap pm;

            QStyleOption tool = *tb;
            if (tb->subControls & SC_TitleBarCloseButton && tb->titleBarFlags & Qt::WindowSystemMenuHint) {
                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarCloseButton, widget);
                down = tb->activeSubControls & SC_TitleBarCloseButton && (opt->state & State_Sunken);
                if ((tb->titleBarFlags & Qt::WindowType_Mask) == Qt::Tool
#if QT_CONFIG(dockwidget)
                    || qobject_cast<const QDockWidget *>(widget)
#endif
                    )
                    pm = proxy()->standardIcon(SP_DockWidgetCloseButton, &tool, widget).pixmap(QSize(10, 10), QStyleHelper::getDpr(p));
                else
                    pm = proxy()->standardIcon(SP_TitleBarCloseButton, &tool, widget).pixmap(QSize(10, 10), QStyleHelper::getDpr(p));
                tool.rect = ir;
                tool.state = down ? State_Sunken : State_Raised;
                proxy()->drawPrimitive(PE_PanelButtonTool, &tool, p, widget);

                QPainterStateGuard psg(p, down ? QPainterStateGuard::InitialState::Save
                                               : QPainterStateGuard::InitialState::NoSave);
                if (down)
                    p->translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, tb, widget),
                                 proxy()->pixelMetric(PM_ButtonShiftVertical, tb, widget));
                proxy()->drawItemPixmap(p, ir, Qt::AlignCenter, pm);
            }

            if (tb->subControls & SC_TitleBarMaxButton
                    && tb->titleBarFlags & Qt::WindowMaximizeButtonHint
                    && !(tb->titleBarState & Qt::WindowMaximized)) {
                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarMaxButton, widget);

                down = tb->activeSubControls & SC_TitleBarMaxButton && (opt->state & State_Sunken);
                pm = proxy()->standardIcon(SP_TitleBarMaxButton, &tool, widget).pixmap(QSize(10, 10), QStyleHelper::getDpr(p));
                tool.rect = ir;
                tool.state = down ? State_Sunken : State_Raised;
                proxy()->drawPrimitive(PE_PanelButtonTool, &tool, p, widget);

                QPainterStateGuard psg(p, down ? QPainterStateGuard::InitialState::Save
                                               : QPainterStateGuard::InitialState::NoSave);
                if (down)
                    p->translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, tb, widget),
                                 proxy()->pixelMetric(PM_ButtonShiftVertical, tb, widget));
                proxy()->drawItemPixmap(p, ir, Qt::AlignCenter, pm);
            }

            if (tb->subControls & SC_TitleBarMinButton
                    && tb->titleBarFlags & Qt::WindowMinimizeButtonHint
                    && !(tb->titleBarState & Qt::WindowMinimized)) {
                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarMinButton, widget);
                down = tb->activeSubControls & SC_TitleBarMinButton && (opt->state & State_Sunken);
                pm = proxy()->standardIcon(SP_TitleBarMinButton, &tool, widget).pixmap(QSize(10, 10), QStyleHelper::getDpr(p));
                tool.rect = ir;
                tool.state = down ? State_Sunken : State_Raised;
                proxy()->drawPrimitive(PE_PanelButtonTool, &tool, p, widget);

                QPainterStateGuard psg(p, down ? QPainterStateGuard::InitialState::Save
                                               : QPainterStateGuard::InitialState::NoSave);
                if (down)
                    p->translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, tb, widget),
                                 proxy()->pixelMetric(PM_ButtonShiftVertical, tb, widget));
                proxy()->drawItemPixmap(p, ir, Qt::AlignCenter, pm);
            }

            bool drawNormalButton = (tb->subControls & SC_TitleBarNormalButton)
                                    && (((tb->titleBarFlags & Qt::WindowMinimizeButtonHint)
                                    && (tb->titleBarState & Qt::WindowMinimized))
                                    || ((tb->titleBarFlags & Qt::WindowMaximizeButtonHint)
                                    && (tb->titleBarState & Qt::WindowMaximized)));

            if (drawNormalButton) {
                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarNormalButton, widget);
                down = tb->activeSubControls & SC_TitleBarNormalButton && (opt->state & State_Sunken);
                pm = proxy()->standardIcon(SP_TitleBarNormalButton, &tool, widget).pixmap(QSize(10, 10), QStyleHelper::getDpr(p));
                tool.rect = ir;
                tool.state = down ? State_Sunken : State_Raised;
                proxy()->drawPrimitive(PE_PanelButtonTool, &tool, p, widget);

                QPainterStateGuard psg(p, down ? QPainterStateGuard::InitialState::Save
                                               : QPainterStateGuard::InitialState::NoSave);
                if (down)
                    p->translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, tb, widget),
                                 proxy()->pixelMetric(PM_ButtonShiftVertical, tb, widget));
                proxy()->drawItemPixmap(p, ir, Qt::AlignCenter, pm);
            }

            if (tb->subControls & SC_TitleBarShadeButton
                    && tb->titleBarFlags & Qt::WindowShadeButtonHint
                    && !(tb->titleBarState & Qt::WindowMinimized)) {
                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarShadeButton, widget);
                down = (tb->activeSubControls & SC_TitleBarShadeButton && (opt->state & State_Sunken));
                pm = proxy()->standardIcon(SP_TitleBarShadeButton, &tool, widget).pixmap(QSize(10, 10), QStyleHelper::getDpr(p));
                tool.rect = ir;
                tool.state = down ? State_Sunken : State_Raised;
                proxy()->drawPrimitive(PE_PanelButtonTool, &tool, p, widget);

                QPainterStateGuard psg(p, down ? QPainterStateGuard::InitialState::Save
                                               : QPainterStateGuard::InitialState::NoSave);
                if (down)
                    p->translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, tb, widget),
                                 proxy()->pixelMetric(PM_ButtonShiftVertical, tb, widget));
                proxy()->drawItemPixmap(p, ir, Qt::AlignCenter, pm);
            }

            if (tb->subControls & SC_TitleBarUnshadeButton
                    && tb->titleBarFlags & Qt::WindowShadeButtonHint
                    && tb->titleBarState & Qt::WindowMinimized) {
                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarUnshadeButton, widget);

                down = tb->activeSubControls & SC_TitleBarUnshadeButton  && (opt->state & State_Sunken);
                pm = proxy()->standardIcon(SP_TitleBarUnshadeButton, &tool, widget).pixmap(QSize(10, 10), QStyleHelper::getDpr(p));
                tool.rect = ir;
                tool.state = down ? State_Sunken : State_Raised;
                proxy()->drawPrimitive(PE_PanelButtonTool, &tool, p, widget);

                QPainterStateGuard psg(p, down ? QPainterStateGuard::InitialState::Save
                                               : QPainterStateGuard::InitialState::NoSave);
                if (down)
                    p->translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, tb, widget),
                                 proxy()->pixelMetric(PM_ButtonShiftVertical, tb, widget));
                proxy()->drawItemPixmap(p, ir, Qt::AlignCenter, pm);
            }
            if (tb->subControls & SC_TitleBarContextHelpButton
                    && tb->titleBarFlags & Qt::WindowContextHelpButtonHint) {
                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarContextHelpButton, widget);

                down = tb->activeSubControls & SC_TitleBarContextHelpButton  && (opt->state & State_Sunken);
                pm = proxy()->standardIcon(SP_TitleBarContextHelpButton, &tool, widget).pixmap(QSize(10, 10), QStyleHelper::getDpr(p));
                tool.rect = ir;
                tool.state = down ? State_Sunken : State_Raised;
                proxy()->drawPrimitive(PE_PanelButtonTool, &tool, p, widget);

                QPainterStateGuard psg(p, down ? QPainterStateGuard::InitialState::Save
                                               : QPainterStateGuard::InitialState::NoSave);
                if (down)
                    p->translate(proxy()->pixelMetric(PM_ButtonShiftHorizontal, tb, widget),
                                 proxy()->pixelMetric(PM_ButtonShiftVertical, tb, widget));
                proxy()->drawItemPixmap(p, ir, Qt::AlignCenter, pm);
            }
            if (tb->subControls & SC_TitleBarSysMenu && tb->titleBarFlags & Qt::WindowSystemMenuHint) {
                ir = proxy()->subControlRect(CC_TitleBar, tb, SC_TitleBarSysMenu, widget);
                if (!tb->icon.isNull()) {
                    tb->icon.paint(p, ir);
                } else {
                    int iconSize = proxy()->pixelMetric(PM_SmallIconSize, tb, widget);
                    pm = proxy()->standardIcon(SP_TitleBarMenuButton, &tool, widget).pixmap(QSize(iconSize, iconSize), QStyleHelper::getDpr(p));
                    tool.rect = ir;
                    proxy()->drawItemPixmap(p, ir, Qt::AlignCenter, pm);
                }
            }
        }
        break;
#if QT_CONFIG(dial)
    case CC_Dial:
        if (const QStyleOptionSlider *dial = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            // OK, this is more a port of things over
            QPainterStateGuard psg(p);

            // avoid dithering
            if (p->paintEngine()->hasFeature(QPaintEngine::Antialiasing))
                p->setRenderHint(QPainter::Antialiasing);

            int width = dial->rect.width();
            int height = dial->rect.height();
            qreal r = qMin(width, height) / 2;
            qreal d_ = r / 6;
            qreal dx = dial->rect.x() + d_ + (width - 2 * r) / 2 + 1;
            qreal dy = dial->rect.y() + d_ + (height - 2 * r) / 2 + 1;
            QRect br = QRect(int(dx), int(dy), int(r * 2 - 2 * d_ - 2), int(r * 2 - 2 * d_ - 2));

            QPalette pal = opt->palette;
            // draw notches
            if (dial->subControls & QStyle::SC_DialTickmarks) {
                p->setPen(pal.windowText().color());
                p->drawLines(QStyleHelper::calcLines(dial));
            }

            if (dial->state & State_Enabled) {
                p->setBrush(pal.brush(QPalette::ColorRole(proxy()->styleHint(SH_Dial_BackgroundRole,
                                                                    dial, widget))));
                p->setPen(Qt::NoPen);
                p->drawEllipse(br);
                p->setBrush(Qt::NoBrush);
            }
            p->setPen(pal.dark().color());
            p->drawArc(br, 60 * 16, 180 * 16);
            p->setPen(pal.light().color());
            p->drawArc(br, 240 * 16, 180 * 16);

            qreal a;
            const StaticPolygonF<3> arrow = calcArrow(dial, a);

            p->setPen(Qt::NoPen);
            p->setBrush(pal.button());
            p->drawPolygon(arrow.cbegin(), arrow.size());

            a = QStyleHelper::angle(QPointF(width / 2, height / 2), arrow[0]);
            p->setBrush(Qt::NoBrush);

            if (a <= 0 || a > 200) {
                p->setPen(pal.light().color());
                p->drawLine(arrow[2], arrow[0]);
                p->drawLine(arrow[1], arrow[2]);
                p->setPen(pal.dark().color());
                p->drawLine(arrow[0], arrow[1]);
            } else if (a > 0 && a < 45) {
                p->setPen(pal.light().color());
                p->drawLine(arrow[2], arrow[0]);
                p->setPen(pal.dark().color());
                p->drawLine(arrow[1], arrow[2]);
                p->drawLine(arrow[0], arrow[1]);
            } else if (a >= 45 && a < 135) {
                p->setPen(pal.dark().color());
                p->drawLine(arrow[2], arrow[0]);
                p->drawLine(arrow[1], arrow[2]);
                p->setPen(pal.light().color());
                p->drawLine(arrow[0], arrow[1]);
            } else if (a >= 135 && a < 200) {
                p->setPen(pal.dark().color());
                p->drawLine(arrow[2], arrow[0]);
                p->setPen(pal.light().color());
                p->drawLine(arrow[0], arrow[1]);
                p->drawLine(arrow[1], arrow[2]);
            }

            // draw focus rect around the dial
            QStyleOptionFocusRect fropt;
            fropt.rect = dial->rect;
            fropt.state = dial->state;
            fropt.palette = dial->palette;
            if (fropt.state & QStyle::State_HasFocus) {
                br.adjust(0, 0, 2, 2);
                if (dial->subControls & SC_DialTickmarks) {
                    int r = qMin(width, height) / 2;
                    br.translate(-r / 6, - r / 6);
                    br.setWidth(br.width() + r / 3);
                    br.setHeight(br.height() + r / 3);
                }
                fropt.rect = br.adjusted(-2, -2, 2, 2);
                proxy()->drawPrimitive(QStyle::PE_FrameFocusRect, &fropt, p, widget);
            }
        }
        break;
#endif // QT_CONFIG(dial)
#if QT_CONFIG(groupbox)
    case CC_GroupBox:
        if (const QStyleOptionGroupBox *groupBox = qstyleoption_cast<const QStyleOptionGroupBox *>(opt)) {
            // Draw frame
            QRect textRect = proxy()->subControlRect(CC_GroupBox, opt, SC_GroupBoxLabel, widget);
            QRect checkBoxRect = proxy()->subControlRect(CC_GroupBox, opt, SC_GroupBoxCheckBox, widget);
            if (groupBox->subControls & QStyle::SC_GroupBoxFrame) {
                QStyleOptionFrame frame;
                frame.QStyleOption::operator=(*groupBox);
                frame.features = groupBox->features;
                frame.lineWidth = groupBox->lineWidth;
                frame.midLineWidth = groupBox->midLineWidth;
                frame.rect = proxy()->subControlRect(CC_GroupBox, opt, SC_GroupBoxFrame, widget);
                QPainterStateGuard psg(p);
                QRegion region(groupBox->rect);
                if (!groupBox->text.isEmpty()) {
                    bool ltr = groupBox->direction == Qt::LeftToRight;
                    QRect finalRect;
                    if (groupBox->subControls & QStyle::SC_GroupBoxCheckBox) {
                        finalRect = checkBoxRect.united(textRect);
                        finalRect.adjust(ltr ? -4 : 0, 0, ltr ? 0 : 4, 0);
                    } else {
                        finalRect = textRect;
                    }
                    region -= finalRect;
                }
                p->setClipRegion(region);
                proxy()->drawPrimitive(PE_FrameGroupBox, &frame, p, widget);
            }

            // Draw title
            if ((groupBox->subControls & QStyle::SC_GroupBoxLabel) && !groupBox->text.isEmpty()) {
                QColor textColor = groupBox->textColor;
                if (textColor.isValid())
                    p->setPen(textColor);
                int alignment = int(groupBox->textAlignment);
                if (!proxy()->styleHint(QStyle::SH_UnderlineShortcut, opt, widget))
                    alignment |= Qt::TextHideMnemonic;

                proxy()->drawItemText(p, textRect,  Qt::TextShowMnemonic | Qt::AlignHCenter | alignment,
                             groupBox->palette, groupBox->state & State_Enabled, groupBox->text,
                             textColor.isValid() ? QPalette::NoRole : QPalette::WindowText);

                if (groupBox->state & State_HasFocus) {
                    QStyleOptionFocusRect fropt;
                    fropt.QStyleOption::operator=(*groupBox);
                    fropt.rect = textRect;
                    proxy()->drawPrimitive(PE_FrameFocusRect, &fropt, p, widget);
                }
            }

            // Draw checkbox
            if (groupBox->subControls & SC_GroupBoxCheckBox) {
                QStyleOptionButton box;
                box.QStyleOption::operator=(*groupBox);
                box.rect = checkBoxRect;
                proxy()->drawPrimitive(PE_IndicatorCheckBox, &box, p, widget);
            }
        }
        break;
#endif // QT_CONFIG(groupbox)
#if QT_CONFIG(mdiarea)
    case CC_MdiControls:
        {
            QStyleOptionButton btnOpt;
            btnOpt.QStyleOption::operator=(*opt);
            btnOpt.state &= ~State_MouseOver;
            int bsx = 0;
            int bsy = 0;
            const int buttonIconMetric = proxy()->pixelMetric(PM_TitleBarButtonIconSize, &btnOpt, widget);
            const QSize buttonIconSize(buttonIconMetric, buttonIconMetric);
            if (opt->subControls & QStyle::SC_MdiCloseButton) {
                if (opt->activeSubControls & QStyle::SC_MdiCloseButton && (opt->state & State_Sunken)) {
                    btnOpt.state |= State_Sunken;
                    btnOpt.state &= ~State_Raised;
                    bsx = proxy()->pixelMetric(PM_ButtonShiftHorizontal, opt, widget);
                    bsy = proxy()->pixelMetric(PM_ButtonShiftVertical, opt, widget);
                } else {
                    btnOpt.state |= State_Raised;
                    btnOpt.state &= ~State_Sunken;
                    bsx = 0;
                    bsy = 0;
                }
                btnOpt.rect = proxy()->subControlRect(CC_MdiControls, opt, SC_MdiCloseButton, widget);
                proxy()->drawPrimitive(PE_PanelButtonCommand, &btnOpt, p, widget);
                QPixmap pm = proxy()->standardIcon(SP_TitleBarCloseButton).pixmap(buttonIconSize, QStyleHelper::getDpr(p));
                proxy()->drawItemPixmap(p, btnOpt.rect.translated(bsx, bsy), Qt::AlignCenter, pm);
            }
            if (opt->subControls & QStyle::SC_MdiNormalButton) {
                if (opt->activeSubControls & QStyle::SC_MdiNormalButton && (opt->state & State_Sunken)) {
                    btnOpt.state |= State_Sunken;
                    btnOpt.state &= ~State_Raised;
                    bsx = proxy()->pixelMetric(PM_ButtonShiftHorizontal, opt, widget);
                    bsy = proxy()->pixelMetric(PM_ButtonShiftVertical, opt, widget);
                } else {
                    btnOpt.state |= State_Raised;
                    btnOpt.state &= ~State_Sunken;
                    bsx = 0;
                    bsy = 0;
                }
                btnOpt.rect = proxy()->subControlRect(CC_MdiControls, opt, SC_MdiNormalButton, widget);
                proxy()->drawPrimitive(PE_PanelButtonCommand, &btnOpt, p, widget);
                QPixmap pm = proxy()->standardIcon(SP_TitleBarNormalButton).pixmap(buttonIconSize, QStyleHelper::getDpr(p));
                proxy()->drawItemPixmap(p, btnOpt.rect.translated(bsx, bsy), Qt::AlignCenter, pm);
            }
            if (opt->subControls & QStyle::SC_MdiMinButton) {
                if (opt->activeSubControls & QStyle::SC_MdiMinButton && (opt->state & State_Sunken)) {
                    btnOpt.state |= State_Sunken;
                    btnOpt.state &= ~State_Raised;
                    bsx = proxy()->pixelMetric(PM_ButtonShiftHorizontal, opt, widget);
                    bsy = proxy()->pixelMetric(PM_ButtonShiftVertical, opt, widget);
                } else {
                    btnOpt.state |= State_Raised;
                    btnOpt.state &= ~State_Sunken;
                    bsx = 0;
                    bsy = 0;
                }
                btnOpt.rect = proxy()->subControlRect(CC_MdiControls, opt, SC_MdiMinButton, widget);
                proxy()->drawPrimitive(PE_PanelButtonCommand, &btnOpt, p, widget);
                QPixmap pm = proxy()->standardIcon(SP_TitleBarMinButton).pixmap(buttonIconSize, QStyleHelper::getDpr(p));
                proxy()->drawItemPixmap(p, btnOpt.rect.translated(bsx, bsy), Qt::AlignCenter, pm);
            }
        }
        break;
#endif // QT_CONFIG(mdiarea)
    default:
        qCWarning(lcCommonStyle, "QCommonStyle::drawComplexControl: Control %d not handled", cc);
    }
}

/*!
    \reimp
*/
QStyle::SubControl QCommonStyle::hitTestComplexControl(ComplexControl cc, const QStyleOptionComplex *opt,
                                                 const QPoint &pt, const QWidget *widget) const
{
    SubControl sc = SC_None;
    switch (cc) {
#if QT_CONFIG(slider)
    case CC_Slider:
        if (const QStyleOptionSlider *slider = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            QRect r = proxy()->subControlRect(cc, slider, SC_SliderHandle, widget);
            if (r.isValid() && r.contains(pt)) {
                sc = SC_SliderHandle;
            } else {
                r = proxy()->subControlRect(cc, slider, SC_SliderGroove ,widget);
                if (r.isValid() && r.contains(pt))
                    sc = SC_SliderGroove;
            }
        }
        break;
#endif // QT_CONFIG(slider)
#if QT_CONFIG(scrollbar)
    case CC_ScrollBar:
        if (const QStyleOptionSlider *scrollbar = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            QRect r;
            uint ctrl = SC_ScrollBarAddLine;
            while (ctrl <= SC_ScrollBarGroove) {
                r = proxy()->subControlRect(cc, scrollbar, QStyle::SubControl(ctrl), widget);
                if (r.isValid() && r.contains(pt)) {
                    sc = QStyle::SubControl(ctrl);
                    break;
                }
                ctrl <<= 1;
            }
        }
        break;
#endif // QT_CONFIG(scrollbar)
#if QT_CONFIG(toolbutton)
    case CC_ToolButton:
        if (const QStyleOptionToolButton *toolbutton = qstyleoption_cast<const QStyleOptionToolButton *>(opt)) {
            QRect r;
            uint ctrl = SC_ToolButton;
            while (ctrl <= SC_ToolButtonMenu) {
                r = proxy()->subControlRect(cc, toolbutton, QStyle::SubControl(ctrl), widget);
                if (r.isValid() && r.contains(pt)) {
                    sc = QStyle::SubControl(ctrl);
                    break;
                }
                ctrl <<= 1;
            }
        }
        break;
#endif // QT_CONFIG(toolbutton)
#if QT_CONFIG(spinbox)
    case CC_SpinBox:
        if (const QStyleOptionSpinBox *spinbox = qstyleoption_cast<const QStyleOptionSpinBox *>(opt)) {
            QRect r;
            uint ctrl = SC_SpinBoxUp;
            while (ctrl <= SC_SpinBoxEditField) {
                r = proxy()->subControlRect(cc, spinbox, QStyle::SubControl(ctrl), widget);
                if (r.isValid() && r.contains(pt)) {
                    sc = QStyle::SubControl(ctrl);
                    break;
                }
                ctrl <<= 1;
            }
        }
        break;
#endif // QT_CONFIG(spinbox)
    case CC_TitleBar:
        if (const QStyleOptionTitleBar *tb = qstyleoption_cast<const QStyleOptionTitleBar *>(opt)) {
            QRect r;
            uint ctrl = SC_TitleBarSysMenu;

            while (ctrl <= SC_TitleBarLabel) {
                r = proxy()->subControlRect(cc, tb, QStyle::SubControl(ctrl), widget);
                if (r.isValid() && r.contains(pt)) {
                    sc = QStyle::SubControl(ctrl);
                    break;
                }
                ctrl <<= 1;
            }
        }
        break;
#if QT_CONFIG(combobox)
    case CC_ComboBox:
        if (const QStyleOptionComboBox *cb = qstyleoption_cast<const QStyleOptionComboBox *>(opt)) {
            QRect r;
            uint ctrl = SC_ComboBoxArrow;  // Start here and go down.
            while (ctrl > 0) {
                r = proxy()->subControlRect(cc, cb, QStyle::SubControl(ctrl), widget);
                if (r.isValid() && r.contains(pt)) {
                    sc = QStyle::SubControl(ctrl);
                    break;
                }
                ctrl >>= 1;
            }
        }
        break;
#endif // QT_CONFIG(combobox)
#if QT_CONFIG(groupbox)
    case CC_GroupBox:
        if (const QStyleOptionGroupBox *groupBox = qstyleoption_cast<const QStyleOptionGroupBox *>(opt)) {
            QRect r;
            uint ctrl = SC_GroupBoxCheckBox;
            while (ctrl <= SC_GroupBoxFrame) {
                r = proxy()->subControlRect(cc, groupBox, QStyle::SubControl(ctrl), widget);
                if (r.isValid() && r.contains(pt)) {
                    sc = QStyle::SubControl(ctrl);
                    break;
                }
                ctrl <<= 1;
            }
        }
        break;
#endif // QT_CONFIG(groupbox)
    case CC_MdiControls:
        {
            QRect r;
            uint ctrl = SC_MdiMinButton;
            while (ctrl <= SC_MdiCloseButton) {
                r = proxy()->subControlRect(CC_MdiControls, opt, QStyle::SubControl(ctrl), widget);
                if (r.isValid() && r.contains(pt) && (opt->subControls & ctrl)) {
                    sc = QStyle::SubControl(ctrl);
                    return sc;
                }
                ctrl <<= 1;
            }
        }
        break;
    default:
        qCWarning(lcCommonStyle, "QCommonStyle::hitTestComplexControl: Case %d not handled", cc);
    }
    return sc;
}

/*!
    \reimp
*/
QRect QCommonStyle::subControlRect(ComplexControl cc, const QStyleOptionComplex *opt,
                                   SubControl sc, const QWidget *widget) const
{
    QRect ret;
    switch (cc) {
#if QT_CONFIG(slider)
    case CC_Slider:
        if (const QStyleOptionSlider *slider = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            int tickOffset = proxy()->pixelMetric(PM_SliderTickmarkOffset, slider, widget);
            int thickness = proxy()->pixelMetric(PM_SliderControlThickness, slider, widget);

            switch (sc) {
            case SC_SliderHandle: {
                int sliderPos = 0;
                int len = proxy()->pixelMetric(PM_SliderLength, slider, widget);
                bool horizontal = slider->orientation == Qt::Horizontal;
                sliderPos = sliderPositionFromValue(slider->minimum, slider->maximum,
                                                    slider->sliderPosition,
                                                    (horizontal ? slider->rect.width()
                                                                : slider->rect.height()) - len,
                                                    slider->upsideDown);
                if (horizontal)
                    ret.setRect(slider->rect.x() + sliderPos, slider->rect.y() + tickOffset, len, thickness);
                else
                    ret.setRect(slider->rect.x() + tickOffset, slider->rect.y() + sliderPos, thickness, len);
                break; }
            case SC_SliderGroove:
                if (slider->orientation == Qt::Horizontal)
                    ret.setRect(slider->rect.x(), slider->rect.y() + tickOffset,
                                slider->rect.width(), thickness);
                else
                    ret.setRect(slider->rect.x() + tickOffset, slider->rect.y(),
                                thickness, slider->rect.height());
                break;
            default:
                break;
            }
            ret = visualRect(slider->direction, slider->rect, ret);
        }
        break;
#endif // QT_CONFIG(slider)
#if QT_CONFIG(scrollbar)
    case CC_ScrollBar:
        if (const QStyleOptionSlider *scrollbar = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            const QRect scrollBarRect = scrollbar->rect;
            int sbextent = 0;
            if (!proxy()->styleHint(SH_ScrollBar_Transient, scrollbar, widget))
                sbextent = proxy()->pixelMetric(PM_ScrollBarExtent, scrollbar, widget);
            int maxlen = ((scrollbar->orientation == Qt::Horizontal) ?
                          scrollBarRect.width() : scrollBarRect.height()) - (sbextent * 2);
            int sliderlen;

            // calculate slider length
            if (scrollbar->maximum != scrollbar->minimum) {
                uint range = scrollbar->maximum - scrollbar->minimum;
                sliderlen = (qint64(scrollbar->pageStep) * maxlen) / (range + scrollbar->pageStep);

                int slidermin = proxy()->pixelMetric(PM_ScrollBarSliderMin, scrollbar, widget);
                if (sliderlen < slidermin || range > INT_MAX / 2)
                    sliderlen = slidermin;
                if (sliderlen > maxlen)
                    sliderlen = maxlen;
            } else {
                sliderlen = maxlen;
            }

            int sliderstart = sbextent + sliderPositionFromValue(scrollbar->minimum,
                                                                 scrollbar->maximum,
                                                                 scrollbar->sliderPosition,
                                                                 maxlen - sliderlen,
                                                                 scrollbar->upsideDown);

            switch (sc) {
            case SC_ScrollBarSubLine:            // top/left button
                if (scrollbar->orientation == Qt::Horizontal) {
                    int buttonWidth = qMin(scrollBarRect.width() / 2, sbextent);
                    ret.setRect(0, 0, buttonWidth, scrollBarRect.height());
                } else {
                    int buttonHeight = qMin(scrollBarRect.height() / 2, sbextent);
                    ret.setRect(0, 0, scrollBarRect.width(), buttonHeight);
                }
                break;
            case SC_ScrollBarAddLine:            // bottom/right button
                if (scrollbar->orientation == Qt::Horizontal) {
                    int buttonWidth = qMin(scrollBarRect.width()/2, sbextent);
                    ret.setRect(scrollBarRect.width() - buttonWidth, 0, buttonWidth, scrollBarRect.height());
                } else {
                    int buttonHeight = qMin(scrollBarRect.height()/2, sbextent);
                    ret.setRect(0, scrollBarRect.height() - buttonHeight, scrollBarRect.width(), buttonHeight);
                }
                break;
            case SC_ScrollBarSubPage:            // between top/left button and slider
                if (scrollbar->orientation == Qt::Horizontal)
                    ret.setRect(sbextent, 0, sliderstart - sbextent, scrollBarRect.height());
                else
                    ret.setRect(0, sbextent, scrollBarRect.width(), sliderstart - sbextent);
                break;
            case SC_ScrollBarAddPage:            // between bottom/right button and slider
                if (scrollbar->orientation == Qt::Horizontal)
                    ret.setRect(sliderstart + sliderlen, 0,
                                maxlen - sliderstart - sliderlen + sbextent, scrollBarRect.height());
                else
                    ret.setRect(0, sliderstart + sliderlen, scrollBarRect.width(),
                                maxlen - sliderstart - sliderlen + sbextent);
                break;
            case SC_ScrollBarGroove:
                if (scrollbar->orientation == Qt::Horizontal)
                    ret.setRect(sbextent, 0, scrollBarRect.width() - sbextent * 2,
                                scrollBarRect.height());
                else
                    ret.setRect(0, sbextent, scrollBarRect.width(),
                                scrollBarRect.height() - sbextent * 2);
                break;
            case SC_ScrollBarSlider:
                if (scrollbar->orientation == Qt::Horizontal)
                    ret.setRect(sliderstart, 0, sliderlen, scrollBarRect.height());
                else
                    ret.setRect(0, sliderstart, scrollBarRect.width(), sliderlen);
                break;
            default:
                break;
            }
            ret = visualRect(scrollbar->direction, scrollBarRect, ret);
        }
        break;
#endif // QT_CONFIG(scrollbar)
#if QT_CONFIG(spinbox)
    case CC_SpinBox:
        if (const QStyleOptionSpinBox *spinbox = qstyleoption_cast<const QStyleOptionSpinBox *>(opt)) {
            QSize bs;
            int fw = spinbox->frame ? proxy()->pixelMetric(PM_SpinBoxFrameWidth, spinbox, widget) : 0;
            bs.setHeight(qMax(8, spinbox->rect.height()/2 - fw));
            // 1.6 -approximate golden mean
            bs.setWidth(qMax(16, qMin(bs.height() * 8 / 5, spinbox->rect.width() / 4)));
            int y = fw + spinbox->rect.y();
            int x, lx, rx;
            x = spinbox->rect.x() + spinbox->rect.width() - fw - bs.width();
            lx = fw;
            rx = x - fw;
            switch (sc) {
            case SC_SpinBoxUp:
                if (spinbox->buttonSymbols == QAbstractSpinBox::NoButtons)
                    return QRect();
                ret = QRect(x, y, bs.width(), bs.height());
                break;
            case SC_SpinBoxDown:
                if (spinbox->buttonSymbols == QAbstractSpinBox::NoButtons)
                    return QRect();

                ret = QRect(x, y + bs.height(), bs.width(), bs.height());
                break;
            case SC_SpinBoxEditField:
                if (spinbox->buttonSymbols == QAbstractSpinBox::NoButtons) {
                    ret = QRect(lx, fw, spinbox->rect.width() - 2*fw, spinbox->rect.height() - 2*fw);
                } else {
                    ret = QRect(lx, fw, rx, spinbox->rect.height() - 2*fw);
                }
                break;
            case SC_SpinBoxFrame:
                ret = spinbox->rect;
                break;
            default:
                break;
            }
            ret = visualRect(spinbox->direction, spinbox->rect, ret);
        }
        break;
#endif // Qt_NO_SPINBOX
#if QT_CONFIG(toolbutton)
    case CC_ToolButton:
        if (const QStyleOptionToolButton *tb = qstyleoption_cast<const QStyleOptionToolButton *>(opt)) {
            int mbi = proxy()->pixelMetric(PM_MenuButtonIndicator, tb, widget);
            ret = tb->rect;
            switch (sc) {
            case SC_ToolButton:
                if ((tb->features
                     & (QStyleOptionToolButton::MenuButtonPopup | QStyleOptionToolButton::PopupDelay))
                    == QStyleOptionToolButton::MenuButtonPopup)
                    ret.adjust(0, 0, -mbi, 0);
                break;
            case SC_ToolButtonMenu:
                if ((tb->features
                     & (QStyleOptionToolButton::MenuButtonPopup | QStyleOptionToolButton::PopupDelay))
                    == QStyleOptionToolButton::MenuButtonPopup)
                    ret.adjust(ret.width() - mbi, 0, 0, 0);
                break;
            default:
                break;
            }
            ret = visualRect(tb->direction, tb->rect, ret);
        }
        break;
#endif // QT_CONFIG(toolbutton)
#if QT_CONFIG(combobox)
    case CC_ComboBox:
        if (const QStyleOptionComboBox *cb = qstyleoption_cast<const QStyleOptionComboBox *>(opt)) {
            const qreal dpi = QStyleHelper::dpi(opt);
            const int x = cb->rect.x(), y = cb->rect.y(), wi = cb->rect.width(), he = cb->rect.height();
            const int margin = cb->frame ? qRound(QStyleHelper::dpiScaled(3, dpi)) : 0;
            const int bmarg = cb->frame ? qRound(QStyleHelper::dpiScaled(2, dpi)) : 0;
            const int xpos = x + wi - bmarg - qRound(QStyleHelper::dpiScaled(16, dpi));


            switch (sc) {
            case SC_ComboBoxFrame:
                ret = cb->rect;
                break;
            case SC_ComboBoxArrow:
                ret.setRect(xpos, y + bmarg, qRound(QStyleHelper::dpiScaled(16, opt)), he - 2*bmarg);
                break;
            case SC_ComboBoxEditField:
                ret.setRect(x + margin, y + margin, wi - 2 * margin - qRound(QStyleHelper::dpiScaled(16, dpi)), he - 2 * margin);
                break;
            case SC_ComboBoxListBoxPopup:
                ret = cb->rect;
                break;
            default:
                break;
            }
            ret = visualRect(cb->direction, cb->rect, ret);
        }
        break;
#endif // QT_CONFIG(combobox)
    case CC_TitleBar:
        if (const QStyleOptionTitleBar *tb = qstyleoption_cast<const QStyleOptionTitleBar *>(opt)) {
            const int controlMargin = 2;
            const int controlHeight = tb->rect.height() - controlMargin *2;
            const int delta = controlHeight + controlMargin;
            int offset = 0;

            bool isMinimized = tb->titleBarState & Qt::WindowMinimized;
            bool isMaximized = tb->titleBarState & Qt::WindowMaximized;

            switch (sc) {
            case SC_TitleBarLabel:
                if (tb->titleBarFlags & (Qt::WindowTitleHint | Qt::WindowSystemMenuHint)) {
                    ret = tb->rect;
                    if (tb->titleBarFlags & Qt::WindowSystemMenuHint)
                        ret.adjust(delta, 0, -delta, 0);
                    if (tb->titleBarFlags & Qt::WindowMinimizeButtonHint)
                        ret.adjust(0, 0, -delta, 0);
                    if (tb->titleBarFlags & Qt::WindowMaximizeButtonHint)
                        ret.adjust(0, 0, -delta, 0);
                    if (tb->titleBarFlags & Qt::WindowShadeButtonHint)
                        ret.adjust(0, 0, -delta, 0);
                    if (tb->titleBarFlags & Qt::WindowContextHelpButtonHint)
                        ret.adjust(0, 0, -delta, 0);
                }
                break;
            case SC_TitleBarContextHelpButton:
                if (tb->titleBarFlags & Qt::WindowContextHelpButtonHint)
                    offset += delta;
                Q_FALLTHROUGH();
            case SC_TitleBarMinButton:
                if (!isMinimized && (tb->titleBarFlags & Qt::WindowMinimizeButtonHint))
                    offset += delta;
                else if (sc == SC_TitleBarMinButton)
                    break;
                Q_FALLTHROUGH();
            case SC_TitleBarNormalButton:
                if (isMinimized && (tb->titleBarFlags & Qt::WindowMinimizeButtonHint))
                    offset += delta;
                else if (isMaximized && (tb->titleBarFlags & Qt::WindowMaximizeButtonHint))
                    offset += delta;
                else if (sc == SC_TitleBarNormalButton)
                    break;
                Q_FALLTHROUGH();
            case SC_TitleBarMaxButton:
                if (!isMaximized && (tb->titleBarFlags & Qt::WindowMaximizeButtonHint))
                    offset += delta;
                else if (sc == SC_TitleBarMaxButton)
                    break;
                Q_FALLTHROUGH();
            case SC_TitleBarShadeButton:
                if (!isMinimized && (tb->titleBarFlags & Qt::WindowShadeButtonHint))
                    offset += delta;
                else if (sc == SC_TitleBarShadeButton)
                    break;
                Q_FALLTHROUGH();
            case SC_TitleBarUnshadeButton:
                if (isMinimized && (tb->titleBarFlags & Qt::WindowShadeButtonHint))
                    offset += delta;
                else if (sc == SC_TitleBarUnshadeButton)
                    break;
                Q_FALLTHROUGH();
            case SC_TitleBarCloseButton:
                if (tb->titleBarFlags & Qt::WindowSystemMenuHint)
                    offset += delta;
                else if (sc == SC_TitleBarCloseButton)
                    break;
                ret.setRect(tb->rect.right() - offset, tb->rect.top() + controlMargin,
                            controlHeight, controlHeight);
                break;
            case SC_TitleBarSysMenu:
                if (tb->titleBarFlags & Qt::WindowSystemMenuHint) {
                    ret.setRect(tb->rect.left() + controlMargin, tb->rect.top() + controlMargin,
                                controlHeight, controlHeight);
                }
                break;
            default:
                break;
            }
            ret = visualRect(tb->direction, tb->rect, ret);
        }
        break;
#if QT_CONFIG(groupbox)
    case CC_GroupBox: {
        if (const QStyleOptionGroupBox *groupBox = qstyleoption_cast<const QStyleOptionGroupBox *>(opt)) {
            switch (sc) {
            case SC_GroupBoxFrame:
            case SC_GroupBoxContents: {
                int topMargin = 0;
                int topHeight = 0;
                int verticalAlignment = proxy()->styleHint(SH_GroupBox_TextLabelVerticalAlignment, groupBox, widget);
                bool hasCheckBox = groupBox->subControls & QStyle::SC_GroupBoxCheckBox;
                if (groupBox->text.size() || hasCheckBox) {
                    int checkBoxHeight = hasCheckBox ? proxy()->pixelMetric(PM_IndicatorHeight, groupBox, widget) : 0;
                    topHeight = qMax(groupBox->fontMetrics.height(), checkBoxHeight);
                    if (verticalAlignment & Qt::AlignVCenter)
                        topMargin = topHeight / 2;
                    else if (verticalAlignment & Qt::AlignTop)
                        topMargin = topHeight + proxy()->pixelMetric(PM_FocusFrameVMargin, groupBox, widget);
                }

                QRect frameRect = groupBox->rect;
                frameRect.setTop(topMargin);

                if (sc == SC_GroupBoxFrame) {
                    ret = frameRect;
                    break;
                }

                int frameWidth = 0;
                if ((groupBox->features & QStyleOptionFrame::Flat) == 0)
                    frameWidth = proxy()->pixelMetric(PM_DefaultFrameWidth, groupBox, widget);
                ret = frameRect.adjusted(frameWidth, frameWidth + topHeight - topMargin,
                                         -frameWidth, -frameWidth);
                break;
            }
            case SC_GroupBoxCheckBox:
            case SC_GroupBoxLabel: {
                QFontMetrics fontMetrics = groupBox->fontMetrics;
                int th = fontMetrics.height();
                int tw = fontMetrics.size(Qt::TextShowMnemonic, groupBox->text + u' ').width();
                int marg = (groupBox->features & QStyleOptionFrame::Flat) ? 0 : 8;
                ret = groupBox->rect.adjusted(marg, 0, -marg, 0);

                int indicatorWidth = proxy()->pixelMetric(PM_IndicatorWidth, opt, widget);
                int indicatorHeight = proxy()->pixelMetric(PM_IndicatorHeight, opt, widget);
                int indicatorSpace = proxy()->pixelMetric(PM_CheckBoxLabelSpacing, opt, widget) - 1;
                bool hasCheckBox = groupBox->subControls & QStyle::SC_GroupBoxCheckBox;
                int checkBoxWidth = hasCheckBox ? (indicatorWidth + indicatorSpace) : 0;
                int checkBoxHeight = hasCheckBox ? indicatorHeight : 0;

                int h = qMax(th, checkBoxHeight);
                ret.setHeight(h);

                // Adjusted rect for label + indicatorWidth + indicatorSpace
                QRect totalRect = alignedRect(groupBox->direction, groupBox->textAlignment,
                                              QSize(tw + checkBoxWidth, h), ret);

                // Adjust totalRect if checkbox is set
                if (hasCheckBox) {
                    bool ltr = groupBox->direction == Qt::LeftToRight;
                    int left = 0;
                    // Adjust for check box
                    if (sc == SC_GroupBoxCheckBox) {
                        left = ltr ? totalRect.left() : (totalRect.right() - indicatorWidth);
                        int top = totalRect.top() + (h - checkBoxHeight) / 2;
                        totalRect.setRect(left, top, indicatorWidth, indicatorHeight);
                    // Adjust for label
                    } else {
                        left = ltr ? (totalRect.left() + checkBoxWidth - 2) : totalRect.left();
                        int top = totalRect.top() + (h - th) / 2;
                        totalRect.setRect(left, top, totalRect.width() - checkBoxWidth, th);
                    }
                }
                ret = totalRect;
                break;
            }
            default:
                break;
            }
        }
        break;
    }
#endif // QT_CONFIG(groupbox)
#if QT_CONFIG(mdiarea)
    case CC_MdiControls:
    {
        int numSubControls = 0;
        if (opt->subControls & SC_MdiCloseButton)
            ++numSubControls;
        if (opt->subControls & SC_MdiMinButton)
            ++numSubControls;
        if (opt->subControls & SC_MdiNormalButton)
            ++numSubControls;
        if (numSubControls == 0)
            break;

        int buttonWidth = opt->rect.width() / numSubControls - 1;
        int offset = 0;
        switch (sc) {
        case SC_MdiCloseButton:
            // Only one sub control, no offset needed.
            if (numSubControls == 1)
                break;
            offset += buttonWidth + 2;
            Q_FALLTHROUGH();
        case SC_MdiNormalButton:
            // No offset needed if
            // 1) There's only one sub control
            // 2) We have a close button and a normal button (offset already added in SC_MdiClose)
            if (numSubControls == 1 || (numSubControls == 2 && !(opt->subControls & SC_MdiMinButton)))
                break;
            if (opt->subControls & SC_MdiNormalButton)
                offset += buttonWidth;
            break;
        default:
            break;
        }

        // Subtract one pixel if we only have one sub control. At this point
        // buttonWidth is the actual width + 1 pixel margin, but we don't want the
        // margin when there are no other controllers.
        if (numSubControls == 1)
            --buttonWidth;
        ret = QRect(offset, 0, buttonWidth, opt->rect.height());
        break;
    }
#endif // QT_CONFIG(mdiarea)
     default:
        qCWarning(lcCommonStyle, "QCommonStyle::subControlRect: Case %d not handled", cc);
    }
#if !QT_CONFIG(slider) && !QT_CONFIG(spinbox) && !QT_CONFIG(toolbutton) && !QT_CONFIG(groupbox)
    Q_UNUSED(widget);
#endif
    return ret;
}

/*! \reimp */
int QCommonStyle::pixelMetric(PixelMetric m, const QStyleOption *opt, const QWidget *widget) const
{
    int ret;

    switch (m) {
    case PM_FocusFrameVMargin:
    case PM_FocusFrameHMargin:
        ret = 2;
        break;
    case PM_MenuBarVMargin:
    case PM_MenuBarHMargin:
        ret = 0;
        break;
    case PM_TitleBarHeight:
    {
        if (const QStyleOptionTitleBar *tb = qstyleoption_cast<const QStyleOptionTitleBar *>(opt)) {
            if ((tb->titleBarFlags & Qt::WindowType_Mask) == Qt::Tool) {
                ret = qMax(widget ? widget->fontMetrics().height() : opt->fontMetrics.height(), 16);
#if QT_CONFIG(dockwidget)
            } else if (qobject_cast<const QDockWidget*>(widget)) {
                ret = qMax(widget->fontMetrics().height(), int(QStyleHelper::dpiScaled(13, opt)));
#endif
            } else {
                ret = qMax(widget ? widget->fontMetrics().height() : opt->fontMetrics.height(), 18);
            }
        } else {
            ret = int(QStyleHelper::dpiScaled(18., opt));
        }
        break;
    }
    case PM_TitleBarButtonSize:
        ret = int(QStyleHelper::dpiScaled(16., opt));
        break;
    case PM_TitleBarButtonIconSize:
        ret = int(QStyleHelper::dpiScaled(16., opt));
        break;

    case PM_ScrollBarSliderMin:
        ret = int(QStyleHelper::dpiScaled(9., opt));
        break;

    case PM_ButtonMargin:
        ret = int(QStyleHelper::dpiScaled(6., opt));
        break;

    case PM_DockWidgetTitleBarButtonMargin:
        ret = int(QStyleHelper::dpiScaled(2., opt));
        break;

    case PM_ButtonDefaultIndicator:
        ret = 0;
        break;

    case PM_MenuButtonIndicator:
        ret = int(QStyleHelper::dpiScaled(12, opt));
        break;

    case PM_ButtonShiftHorizontal:
    case PM_ButtonShiftVertical:

    case PM_DefaultFrameWidth:
        ret = 2;
        break;

    case PM_ComboBoxFrameWidth:
    case PM_SpinBoxFrameWidth:
    case PM_MenuPanelWidth:
    case PM_TabBarBaseOverlap:
    case PM_TabBarBaseHeight:
        ret = proxy()->pixelMetric(PM_DefaultFrameWidth, opt, widget);
        break;

    case PM_MdiSubWindowFrameWidth:
        ret = int(QStyleHelper::dpiScaled(4, opt));
        break;

    case PM_MdiSubWindowMinimizedWidth:
        ret = int(QStyleHelper::dpiScaled(196, opt));
        break;

#if QT_CONFIG(scrollbar)
    case PM_ScrollBarExtent:
        if (qstyleoption_cast<const QStyleOptionSlider *>(opt))
            ret = 16;
        else
            ret = int(QStyleHelper::dpiScaled(16, opt));
        break;
#endif
    case PM_MaximumDragDistance:
        ret = QGuiApplicationPrivate::platformTheme()->themeHint(QPlatformTheme::MaximumScrollBarDragDistance).toInt();
        break;

#if QT_CONFIG(slider)
    case PM_SliderThickness:
        ret = int(QStyleHelper::dpiScaled(16, opt));
        break;

    case PM_SliderTickmarkOffset:
        if (const QStyleOptionSlider *sl = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            int space = (sl->orientation == Qt::Horizontal) ? sl->rect.height()
                                                            : sl->rect.width();
            int thickness = proxy()->pixelMetric(PM_SliderControlThickness, sl, widget);
            int ticks = sl->tickPosition;

            if (ticks == QSlider::TicksBothSides)
                ret = (space - thickness) / 2;
            else if (ticks == QSlider::TicksAbove)
                ret = space - thickness;
            else
                ret = 0;
        } else {
            ret = 0;
        }
        break;

    case PM_SliderSpaceAvailable:
        if (const QStyleOptionSlider *sl = qstyleoption_cast<const QStyleOptionSlider *>(opt)) {
            if (sl->orientation == Qt::Horizontal)
                ret = sl->rect.width() - proxy()->pixelMetric(PM_SliderLength, sl, widget);
            else
                ret = sl->rect.height() - proxy()->pixelMetric(PM_SliderLength, sl, widget);
        } else {
            ret = 0;
        }
        break;
#endif // QT_CONFIG(slider)
#if QT_CONFIG(dockwidget)
    case PM_DockWidgetSeparatorExtent:
        ret = int(QStyleHelper::dpiScaled(6, opt));
        break;

    case PM_DockWidgetHandleExtent:
        ret = int(QStyleHelper::dpiScaled(8, opt));
        break;
    case PM_DockWidgetTitleMargin:
        ret = 0;
        break;
    case PM_DockWidgetFrameWidth:
        ret = int(QStyleHelper::dpiScaled(1, opt));
        break;
#endif // QT_CONFIG(dockwidget)

    case PM_SpinBoxSliderHeight:
    case PM_MenuBarPanelWidth:
        ret = 2;
        break;

    case PM_MenuBarItemSpacing:
        ret = 0;
        break;

#if QT_CONFIG(toolbar)
    case PM_ToolBarFrameWidth:
        ret = 1;
        break;

    case PM_ToolBarItemMargin:
        ret = 0;
        break;

    case PM_ToolBarItemSpacing:
        ret = int(QStyleHelper::dpiScaled(4, opt));
        break;

    case PM_ToolBarHandleExtent:
        ret = int(QStyleHelper::dpiScaled(8, opt));
        break;

    case PM_ToolBarSeparatorExtent:
        ret = int(QStyleHelper::dpiScaled(6, opt));
        break;

    case PM_ToolBarExtensionExtent:
        ret = int(QStyleHelper::dpiScaled(12, opt));
        break;
#endif // QT_CONFIG(toolbar)

#if QT_CONFIG(tabbar)
    case PM_TabBarTabOverlap:
        ret = 3;
        break;

    case PM_TabBarTabHSpace:
        ret = int(QStyleHelper::dpiScaled(24, opt));
        break;

    case PM_TabBarTabShiftHorizontal:
        ret = 0;
        break;

    case PM_TabBarTabShiftVertical:
        ret = 2;
        break;

    case PM_TabBarTabVSpace:
    {
        const QStyleOptionTab *tb = qstyleoption_cast<const QStyleOptionTab *>(opt);
        if (tb && (tb->shape == QTabBar::RoundedNorth || tb->shape == QTabBar::RoundedSouth
                   || tb->shape == QTabBar::RoundedWest || tb->shape == QTabBar::RoundedEast))
            ret = 8;
        else
            if (tb && (tb->shape == QTabBar::TriangularWest || tb->shape == QTabBar::TriangularEast))
                ret = 3;
            else
                ret = 2;
        break;
    }
#endif

    case PM_ProgressBarChunkWidth:
        ret = 9;
        break;

    case PM_IndicatorWidth:
        ret = int(QStyleHelper::dpiScaled(13, opt));
        break;

    case PM_IndicatorHeight:
        ret = int(QStyleHelper::dpiScaled(13, opt));
        break;

    case PM_ExclusiveIndicatorWidth:
        ret = int(QStyleHelper::dpiScaled(12, opt));
        break;

    case PM_ExclusiveIndicatorHeight:
        ret = int(QStyleHelper::dpiScaled(12, opt));
        break;

    case PM_MenuTearoffHeight:
        ret = int(QStyleHelper::dpiScaled(10, opt));
        break;

    case PM_MenuScrollerHeight:
        ret = int(QStyleHelper::dpiScaled(10, opt));
        break;

    case PM_MenuDesktopFrameWidth:
    case PM_MenuHMargin:
    case PM_MenuVMargin:
        ret = 0;
        break;

    case PM_HeaderMargin:
        ret = int(QStyleHelper::dpiScaled(4, opt));
        break;
    case PM_HeaderMarkSize:
        ret = int(QStyleHelper::dpiScaled(16, opt));
        break;
    case PM_HeaderGripMargin:
        ret = int(QStyleHelper::dpiScaled(4, opt));
        break;
    case PM_HeaderDefaultSectionSizeHorizontal:
        ret = int(QStyleHelper::dpiScaled(100, opt));
        break;
    case PM_HeaderDefaultSectionSizeVertical:
        ret = int(QStyleHelper::dpiScaled(30, opt));
        break;
    case PM_TabBarScrollButtonWidth:
        ret = int(QStyleHelper::dpiScaled(16, opt));
        break;
    case PM_LayoutLeftMargin:
    case PM_LayoutTopMargin:
    case PM_LayoutRightMargin:
    case PM_LayoutBottomMargin:
    {
        bool isWindow = false;
        if (opt) {
            isWindow = (opt->state & State_Window);
        } else if (widget) {
            isWindow = widget->isWindow();
        }
        ret = int(QStyleHelper::dpiScaled(isWindow ? 11 : 9, opt));
        break;
    }
    case PM_LayoutHorizontalSpacing:
    case PM_LayoutVerticalSpacing:
        ret = int(QStyleHelper::dpiScaled(6, opt));
        break;

    case PM_ToolBarIconSize:
        ret = 0;
        if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme())
            ret = theme->themeHint(QPlatformTheme::ToolBarIconSize).toInt();
        if (ret <= 0)
            ret =  int(QStyleHelper::dpiScaled(24, opt));
        break;

    case PM_TabBarIconSize:
        ret = proxy()->pixelMetric(PM_SmallIconSize, opt, widget);
        break;
    case PM_ListViewIconSize:
#if QT_CONFIG(filedialog)
        if (qobject_cast<const QSidebar *>(widget))
            ret = int(QStyleHelper::dpiScaled(24., opt));
        else
#endif
            ret = proxy()->pixelMetric(PM_SmallIconSize, opt, widget);
        break;

    case PM_ButtonIconSize:
    case PM_SmallIconSize:
        ret = int(QStyleHelper::dpiScaled(16, opt));
        break;
    case PM_IconViewIconSize:
        ret = proxy()->pixelMetric(PM_LargeIconSize, opt, widget);
        break;
    case PM_LineEditIconSize:
        ret = proxy()->pixelMetric(PM_SmallIconSize, opt, widget);
        break;
    case PM_LineEditIconMargin:
        ret = proxy()->pixelMetric(PM_LineEditIconSize, opt, widget) / 4;
        break;

    case PM_LargeIconSize:
        ret = int(QStyleHelper::dpiScaled(32, opt));
        break;

    case PM_ToolTipLabelFrameWidth:
        ret = 1;
        break;
    case PM_CheckBoxLabelSpacing:
    case PM_RadioButtonLabelSpacing:
        ret = int(QStyleHelper::dpiScaled(6, opt));
        break;
    case PM_SizeGripSize:
        ret = int(QStyleHelper::dpiScaled(13, opt));
        break;
    case PM_MessageBoxIconSize:
#ifdef Q_OS_MAC
        if (QGuiApplication::desktopSettingsAware()) {
            ret = 64; // No DPI scaling, it's handled elsewhere.
        } else
#endif
        {
            ret = int(QStyleHelper::dpiScaled(32, opt));
        }
        break;
    case PM_TextCursorWidth:
        ret = QGuiApplicationPrivate::platformTheme()->themeHint(QPlatformTheme::TextCursorWidth).toInt();
        break;
    case PM_TabBar_ScrollButtonOverlap:
        ret = 1;
        break;
    case PM_TabCloseIndicatorWidth:
    case PM_TabCloseIndicatorHeight:
        ret = int(QStyleHelper::dpiScaled(16, opt));
        break;
    case PM_ScrollView_ScrollBarSpacing:
        ret = 2 * proxy()->pixelMetric(PM_DefaultFrameWidth, opt, widget);
        break;
    case PM_ScrollView_ScrollBarOverlap:
        ret = 0;
        break;
    case PM_SubMenuOverlap:
        ret = -proxy()->pixelMetric(QStyle::PM_MenuPanelWidth, opt, widget);
        break;
    case PM_TreeViewIndentation:
        ret = int(QStyleHelper::dpiScaled(20, opt));
        break;
    default:
        ret = 0;
        break;
    }

    return ret;
}

/*!
    \reimp
*/
QSize QCommonStyle::sizeFromContents(ContentsType contentsType, const QStyleOption *opt,
                                     const QSize &contentsSize, const QWidget *widget) const
{
    Q_D(const QCommonStyle);
    QSize size(contentsSize);
    switch (contentsType) {
    case CT_PushButton:
        if (const auto *buttonOpt = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            int width = contentsSize.width();
            int height = contentsSize.height();
            const int buttonMargin = proxy()->pixelMetric(PM_ButtonMargin, buttonOpt, widget);
            const int defaultFrameWidth = proxy()->pixelMetric(PM_DefaultFrameWidth, buttonOpt, widget) * 2;
            width += buttonMargin + defaultFrameWidth;
            height += buttonMargin + defaultFrameWidth;
            if (buttonOpt->features.testFlag(QStyleOptionButton::AutoDefaultButton)) {
                const int buttonIndicator = proxy()->pixelMetric(PM_ButtonDefaultIndicator,
                                                                 buttonOpt,
                                                                 widget) * 2;
                width += buttonIndicator;
                height += buttonIndicator;
            }
            size = QSize(width, height);
        }
        break;
    case CT_RadioButton:
    case CT_CheckBox:
        if (const auto *buttonOpt = qstyleoption_cast<const QStyleOptionButton *>(opt)) {
            const bool isRadio = (contentsType == CT_RadioButton);

            const int width = proxy()->pixelMetric(isRadio ? PM_ExclusiveIndicatorWidth
                                        : PM_IndicatorWidth, buttonOpt, widget);
            const int height = proxy()->pixelMetric(isRadio ? PM_ExclusiveIndicatorHeight
                                        : PM_IndicatorHeight, buttonOpt, widget);

            int margins = 0;

            // we add 4 pixels for label margins
            if (!buttonOpt->icon.isNull() || !buttonOpt->text.isEmpty()) {
                margins = 4 + proxy()->pixelMetric(isRadio ? PM_RadioButtonLabelSpacing
                                                  : PM_CheckBoxLabelSpacing, opt, widget);
            }

            size += QSize(width + margins, 4);
            size.setHeight(qMax(size.height(), height));
        }
        break;
#if QT_CONFIG(menu)
    case CT_MenuItem:
        if (const auto *menuItemOpt = qstyleoption_cast<const QStyleOptionMenuItem *>(opt)) {
            const bool checkable = menuItemOpt->menuHasCheckableItems;
            const int maxpmw = menuItemOpt->maxIconWidth;
            int width = size.width();
            int height;
            if (menuItemOpt->menuItemType == QStyleOptionMenuItem::Separator) {
                width = 10;
                height = 2;
            } else {
                height =  menuItemOpt->fontMetrics.height() + 8;
                if (!menuItemOpt->icon.isNull()) {
                    int iconExtent = proxy()->pixelMetric(PM_SmallIconSize, opt, widget);
                    height = qMax(height,
                                  menuItemOpt->icon.actualSize(QSize(iconExtent,
                                                                  iconExtent)).height() + 4);
                }
            }
            if (menuItemOpt->text.contains(u'\t'))
                width += 12;
            if (maxpmw > 0)
                width += maxpmw + 6;
            if (checkable && maxpmw < 20)
                width += 20 - maxpmw;
            if (checkable || maxpmw > 0)
                width += 2;
            width += 12;
            size = QSize(width, height);
        }
        break;
#endif // QT_CONFIG(menu)
#if QT_CONFIG(toolbutton)
    case CT_ToolButton:
        size = QSize(size.width() + 6, size.height() + 5);
        break;
#endif // QT_CONFIG(toolbutton)
#if QT_CONFIG(combobox)
    case CT_ComboBox:
        if (const auto *comboBoxOpt = qstyleoption_cast<const QStyleOptionComboBox *>(opt)) {
            const int frameWidth = comboBoxOpt->frame ? proxy()->pixelMetric(PM_ComboBoxFrameWidth,
                                                                             opt,
                                                                             widget) * 2 : 0;
            const int textMargins = 2 * (proxy()->pixelMetric(PM_FocusFrameHMargin, opt, widget) + 1);

            // QItemDelegate::sizeHint expands the textMargins two times, thus the 2*textMargins...
            const int other = qMax(23, 2 * textMargins
                                   + proxy()->pixelMetric(QStyle::PM_ScrollBarExtent,
                                                          opt, widget));

            size = QSize(size.width() + frameWidth + other, size.height() + frameWidth);
        }
        break;
#endif // QT_CONFIG(combobox)
    case CT_HeaderSection:
        if (const auto *headerOpt = qstyleoption_cast<const QStyleOptionHeader *>(opt)) {
            const bool nullIcon = headerOpt->icon.isNull();
            const int margin = proxy()->pixelMetric(QStyle::PM_HeaderMargin, headerOpt, widget);
            const int iconSize = nullIcon ? 0 : proxy()->pixelMetric(QStyle::PM_SmallIconSize,
                                                                     headerOpt,
                                                                     widget);
            const QSize textSize = headerOpt->fontMetrics.size(0, headerOpt->text);
            size.setHeight(margin + qMax(iconSize, textSize.height()) + margin);
            size.setWidth((nullIcon ? 0 : margin) + iconSize
                        + (headerOpt->text.isNull() ? 0 : margin) + textSize.width() + margin);
            if (headerOpt->sortIndicator != QStyleOptionHeader::None) {
                const int margin = proxy()->pixelMetric(QStyle::PM_HeaderMargin, headerOpt, widget);
                if (headerOpt->orientation == Qt::Horizontal)
                    size.rwidth() += size.height() + margin;
                else
                    size.rheight() += size.width() + margin;
            }
        }
        break;
    case CT_TabWidget:
        size += QSize(4, 4);
        break;
    case CT_LineEdit:
        if (const auto *frameOpt = qstyleoption_cast<const QStyleOptionFrame *>(opt))
            size += QSize(2 * frameOpt->lineWidth, 2 * frameOpt->lineWidth);
        break;
#if QT_CONFIG(groupbox)
    case CT_GroupBox:
        if (const auto *groupBoxOpt = qstyleoption_cast<const QStyleOptionGroupBox *>(opt))
            size += QSize(groupBoxOpt->features.testFlag(QStyleOptionFrame::Flat) ? 0 : 16, 0);
        break;
#endif // QT_CONFIG(groupbox)
    case CT_MdiControls:
        if (const auto *styleOpt = qstyleoption_cast<const QStyleOptionComplex *>(opt)) {
            const int buttonSize = proxy()->pixelMetric(PM_TitleBarButtonSize, styleOpt, widget);
            int width = 1;
            if (styleOpt->subControls & SC_MdiMinButton)
                width += buttonSize + 1;
            if (styleOpt->subControls & SC_MdiNormalButton)
                width += buttonSize + 1;
            if (styleOpt->subControls & SC_MdiCloseButton)
                width += buttonSize + 1;
            size = QSize(width, buttonSize);
        } else {
            const int buttonSize = proxy()->pixelMetric(PM_TitleBarButtonSize, opt, widget);
            size = QSize(1 + 3 * (buttonSize + 1), buttonSize);
        }
        break;
#if QT_CONFIG(itemviews)
    case CT_ItemViewItem:
        if (const auto *viewItemOpt = qstyleoption_cast<const QStyleOptionViewItem *>(opt)) {
            QRect decorationRect, displayRect, checkRect;
            d->viewItemLayout(viewItemOpt, &checkRect, &decorationRect, &displayRect, true);
            size = (decorationRect|displayRect|checkRect).size();
            if (decorationRect.isValid() && size.height() == decorationRect.height())
                size.rheight() += 2; // Prevent icons from overlapping.
        }
        break;
#else
        Q_UNUSED(d);
#endif // QT_CONFIG(itemviews)
#if QT_CONFIG(spinbox)
    case CT_SpinBox:
        if (const auto *spinBoxOpt = qstyleoption_cast<const QStyleOptionSpinBox *>(opt)) {
            const int frameWidth = spinBoxOpt->frame
                ? proxy()->pixelMetric(PM_SpinBoxFrameWidth, spinBoxOpt, widget)
                : 0;
            size += QSize(2 * frameWidth, 2 * frameWidth);
            const bool hasButtons = (spinBoxOpt->buttonSymbols != QAbstractSpinBox::NoButtons);
            if (hasButtons) {
                const auto height = qMax(8, size.height() / 2 - frameWidth);
                const auto buttonWidth = qMax(16, qMin(height * 8 / 5, size.width() / 3));
                size.rwidth() += buttonWidth;
            }
        }
        break;
#endif
    case CT_ScrollBar:
    case CT_MenuBar:
    case CT_Menu:
    case CT_MenuBarItem:
    case CT_Slider:
    case CT_ProgressBar:
    case CT_TabBarTab:
        // just return the contentsSize for now
        Q_FALLTHROUGH();
    default:
        break;
    }
    return size;
}


/*! \reimp */
int QCommonStyle::styleHint(StyleHint sh, const QStyleOption *opt, const QWidget *widget,
                            QStyleHintReturn *hret) const
{
    int ret = 0;

    switch (sh) {
    case SH_Menu_KeyboardSearch:
        ret = false;
        break;
    case SH_Slider_AbsoluteSetButtons:
        ret = Qt::MiddleButton;
        break;
    case SH_Slider_PageSetButtons:
        ret = Qt::LeftButton;
        break;
    case SH_ScrollBar_ContextMenu:
        ret = true;
        break;
#if QT_CONFIG(dialogbuttonbox)
    case SH_DialogButtons_DefaultButton:  // This value not used anywhere.
        ret = QDialogButtonBox::AcceptRole;
        break;
#endif
#if QT_CONFIG(groupbox)
    case SH_GroupBox_TextLabelVerticalAlignment:
        ret = Qt::AlignVCenter;
        break;

    case SH_GroupBox_TextLabelColor:
        ret = opt ? int(opt->palette.color(QPalette::Text).rgba()) : 0;
        break;
#endif // QT_CONFIG(groupbox)

    case SH_ListViewExpand_SelectMouseType:
    case SH_TabBar_SelectMouseType:
        ret = QEvent::MouseButtonPress;
        break;


    case SH_TabBar_Alignment:
        ret = Qt::AlignLeft;
        break;

    case SH_Header_ArrowAlignment:
        ret = Qt::AlignRight | Qt::AlignVCenter;
        break;

    case SH_TitleBar_AutoRaise:
        ret = false;
        break;

    case SH_Menu_SubMenuPopupDelay:
        ret = 256;
        break;

    case SH_Menu_SloppySubMenus:
        ret = true;
        break;

    case SH_Menu_SubMenuUniDirection:
        ret = false;
        break;
    case SH_Menu_SubMenuUniDirectionFailCount:
        ret = 1;
        break;
    case SH_Menu_SubMenuSloppySelectOtherActions:
        ret = true;
        break;
    case SH_Menu_SubMenuSloppyCloseTimeout:
        ret = 1000;
        break;
    case SH_Menu_SubMenuResetWhenReenteringParent:
        ret = false;
        break;
    case SH_Menu_SubMenuDontStartSloppyOnLeave:
        ret = false;
        break;

    case SH_ProgressDialog_TextLabelAlignment:
        ret = Qt::AlignCenter;
        break;

    case SH_BlinkCursorWhenTextSelected:
#if defined(Q_OS_DARWIN)
        ret = 0;
#else
        ret = 1;
#endif
        break;

    case SH_Table_GridLineColor:
        if (opt)
            ret = opt->palette.color(QPalette::Mid).rgba();
        else
            ret = -1;
        break;
    case SH_LineEdit_PasswordCharacter: {
        const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme();
        const QPlatformTheme::ThemeHint hintType = QPlatformTheme::PasswordMaskCharacter;
        const QVariant hint = theme ? theme->themeHint(hintType) : QPlatformTheme::defaultThemeHint(hintType);
        ret = hint.toChar().unicode();
        break;
    }
    case SH_LineEdit_PasswordMaskDelay:
        ret = QGuiApplicationPrivate::platformTheme()->themeHint(QPlatformTheme::PasswordMaskDelay).toInt();
        break;
    case SH_ToolBox_SelectedPageTitleBold:
        ret = 1;
        break;

    case SH_UnderlineShortcut: {
        const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme();
        ret = theme ? theme->themeHint(QPlatformTheme::UnderlineShortcut).toInt()
                    : QPlatformTheme::defaultThemeHint(QPlatformTheme::UnderlineShortcut).toInt();
        break;
    }

    case SH_SpinBox_ClickAutoRepeatRate:
        ret = 150;
        break;

    case SH_SpinBox_ClickAutoRepeatThreshold:
        ret = 500;
        break;

    case SH_SpinBox_KeyPressAutoRepeatRate:
        ret = 75;
        break;

    case SH_Menu_SelectionWrap:
        ret = true;
        break;

    case SH_Menu_FillScreenWithScroll:
        ret = true;
        break;

    case SH_ToolTipLabel_Opacity:
        ret = 255;
        break;

    case SH_Button_FocusPolicy:
        ret = Qt::StrongFocus;
        break;

    case SH_MessageBox_UseBorderForButtonSpacing:
        ret = 0;
        break;

    case SH_ToolButton_PopupDelay:
        ret = 600;
        break;

    case SH_FocusFrame_Mask:
        ret = 1;
        if (widget) {
            if (QStyleHintReturnMask *mask = qstyleoption_cast<QStyleHintReturnMask*>(hret)) {
                mask->region = widget->rect();
                const int vmargin = proxy()->pixelMetric(QStyle::PM_FocusFrameVMargin, opt, widget);
                const int hmargin = proxy()->pixelMetric(QStyle::PM_FocusFrameHMargin, opt, widget);
                mask->region -= QRect(widget->rect().adjusted(hmargin, vmargin, -hmargin, -vmargin));
            }
        }
        break;
#if QT_CONFIG(rubberband)
    case SH_RubberBand_Mask:
        if (const QStyleOptionRubberBand *rbOpt = qstyleoption_cast<const QStyleOptionRubberBand *>(opt)) {
            ret = 0;
            if (rbOpt->shape == QRubberBand::Rectangle) {
                ret = true;
                if (QStyleHintReturnMask *mask = qstyleoption_cast<QStyleHintReturnMask*>(hret)) {
                    mask->region = opt->rect;
                    const int margin = proxy()->pixelMetric(PM_DefaultFrameWidth, opt, widget) * 2;
                    mask->region -= opt->rect.adjusted(margin, margin, -margin, -margin);
                }
            }
        }
        break;
#endif // QT_CONFIG(rubberband)
    case SH_SpinControls_DisableOnBounds:
        ret = 1;
        break;

    case SH_Dial_BackgroundRole:
        ret = QPalette::Window;
        break;

    case SH_ComboBox_LayoutDirection:
        ret = opt ? opt->direction : Qt::LeftToRight;
        break;

    case SH_ItemView_EllipsisLocation:
        ret = Qt::AlignTrailing;
        break;

    case SH_ItemView_ShowDecorationSelected:
        ret = false;
        break;

    case SH_ItemView_ActivateItemOnSingleClick:
        ret = 0;
        if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme())
            ret = theme->themeHint(QPlatformTheme::ItemViewActivateItemOnSingleClick).toBool() ? 1 : 0;
        break;
    case SH_TitleBar_ModifyNotification:
        ret = true;
        break;
    case SH_ScrollBar_RollBetweenButtons:
        ret = false;
        break;
    case SH_TabBar_ElideMode:
        ret = Qt::ElideNone;
        break;
#if QT_CONFIG(dialogbuttonbox)
    case SH_DialogButtonLayout:
        ret = QDialogButtonBox::WinLayout;
        if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme())
            ret = theme->themeHint(QPlatformTheme::DialogButtonBoxLayout).toInt();
        break;
#endif
    case SH_ComboBox_PopupFrameStyle:
        ret = QFrame::StyledPanel | QFrame::Plain;
        break;
    case SH_MessageBox_TextInteractionFlags:
        ret = Qt::LinksAccessibleByMouse;
        break;
    case SH_DialogButtonBox_ButtonsHaveIcons:
        ret = 0;
        if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme())
            ret = theme->themeHint(QPlatformTheme::DialogButtonBoxButtonsHaveIcons).toBool() ? 1 : 0;
        break;
    case SH_MessageBox_CenterButtons:
        ret = true;
        break;
    case SH_ItemView_MovementWithoutUpdatingSelection:
        ret = true;
        break;
    case SH_FocusFrame_AboveWidget:
        ret = false;
        break;
#if QT_CONFIG(tabwidget)
    case SH_TabWidget_DefaultTabPosition:
        ret = QTabWidget::North;
        break;
#endif
    case SH_ToolBar_Movable:
        ret = true;
        break;
    case SH_TextControl_FocusIndicatorTextCharFormat:
        ret = true;
        if (QStyleHintReturnVariant *vret = qstyleoption_cast<QStyleHintReturnVariant*>(hret)) {
            QPen outline(opt->palette.color(QPalette::Text), 1, Qt::DotLine);
            QTextCharFormat fmt;
            fmt.setProperty(QTextFormat::OutlinePen, outline);
            vret->variant = fmt;
        }
        break;
#if QT_CONFIG(wizard)
    case SH_WizardStyle:
        ret = QWizard::ClassicStyle;
        break;
#endif
#if QT_CONFIG(formlayout)
    case SH_FormLayoutWrapPolicy:
        ret = QFormLayout::DontWrapRows;
        break;
    case SH_FormLayoutFieldGrowthPolicy:
        ret = QFormLayout::AllNonFixedFieldsGrow;
        break;
#endif
    case SH_FormLayoutFormAlignment:
        ret = Qt::AlignLeft | Qt::AlignTop;
        break;
    case SH_FormLayoutLabelAlignment:
        ret = Qt::AlignLeft;
        break;
    case SH_ItemView_ArrowKeysNavigateIntoChildren:
        ret = false;
        break;
    case SH_ItemView_DrawDelegateFrame:
        ret = 0;
        break;
#if QT_CONFIG(tabbar)
    case SH_TabBar_CloseButtonPosition:
        ret = QTabBar::RightSide;
        break;
    case SH_TabBar_ChangeCurrentDelay:
        ret = 500;
        break;
#endif
    case SH_DockWidget_ButtonsHaveFrame:
        ret = true;
        break;
    case SH_ToolButtonStyle:
        ret = 0;
        if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme())
            ret = theme->themeHint(QPlatformTheme::ToolButtonStyle).toInt();
        break;
    case SH_RequestSoftwareInputPanel:
        ret = RSIP_OnMouseClick;
        break;
    case SH_ScrollBar_Transient:
        ret = false;
        break;
    case SH_Menu_SupportsSections:
        ret = false;
        break;
#if QT_CONFIG(tooltip)
    case SH_ToolTip_WakeUpDelay:
        ret = 700;
        break;
    case SH_ToolTip_FallAsleepDelay:
        ret = 2000;
        break;
#endif
    case SH_Widget_Animate:
    // TODO Qt6: move this code in the SH_Widget_Animation_Duration case
    // and replace false with 0 and true with 200.
#if QT_CONFIG(treeview)
        if (qobject_cast<const QTreeView*>(widget)) {
            ret = false;
        } else
#endif
            {
            ret = true;
        }
        break;
    case SH_Splitter_OpaqueResize:
        ret = true;
        break;
#if QT_CONFIG(itemviews)
    case SH_ItemView_ScrollMode:
        ret = QAbstractItemView::ScrollPerItem;
        break;
#endif
    case SH_TitleBar_ShowToolTipsOnButtons:
        ret = true;
        break;
    case SH_Widget_Animation_Duration:
        ret = styleHint(SH_Widget_Animate, opt, widget, hret) ? 200 : 0;
        break;
    case SH_ComboBox_AllowWheelScrolling:
        ret = true;
        break;
    case SH_SpinBox_ButtonsInsideFrame:
        ret = true;
        break;
    case SH_SpinBox_StepModifier:
        ret = Qt::ControlModifier;
        break;
    case SH_TabBar_AllowWheelScrolling:
        ret = true;
        break;
    case SH_SpinBox_SelectOnStep:
        ret = true;
        break;
    case SH_EtchDisabledText:
    case SH_DitherDisabledText:
    case SH_ScrollBar_MiddleClickAbsolutePosition:
    case SH_ScrollBar_ScrollWhenPointerLeavesControl:
    case SH_Slider_SnapToValue:
    case SH_Slider_SloppyKeyEvents:
    case SH_ProgressDialog_CenterCancelButton:
    case SH_PrintDialog_RightAlignButtons:
    case SH_MainWindow_SpaceBelowMenuBar:
    case SH_FontDialog_SelectAssociatedText:
    case SH_Menu_AllowActiveAndDisabled:
    case SH_Menu_SpaceActivatesItem:
    case SH_ScrollView_FrameOnlyAroundContents:
    case SH_ComboBox_ListMouseTracking:
    case SH_Menu_MouseTracking:
    case SH_MenuBar_MouseTracking:
    case SH_ItemView_ChangeHighlightOnFocus:
    case SH_Widget_ShareActivation:
    case SH_Workspace_FillSpaceOnMaximize:
    case SH_ComboBox_Popup:
    case SH_TitleBar_NoBorder:
    case SH_Slider_StopMouseOverSlider:
    case SH_RichText_FullWidthSelection:
    case SH_Menu_Scrollable:
    case SH_TabBar_PreferNoArrows:
    case SH_ScrollBar_LeftClickAbsolutePosition:
    case SH_SpinBox_AnimateButton:
    case SH_DrawMenuBarSeparator:
    case SH_WindowFrame_Mask:
    case SH_ToolTip_Mask:
    case SH_Menu_Mask:
    case SH_Menu_FlashTriggeredItem:
    case SH_Menu_FadeOutOnHide:
    case SH_ItemView_PaintAlternatingRowColorsForEmptyArea:
    case SH_ComboBox_UseNativePopup:
    case SH_Table_AlwaysDrawLeftTopGridLines:
        ret = false;
        break;
    case SH_MenuBar_AltKeyNavigation:
        if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme())
            ret = theme->themeHint(QPlatformTheme::MenuBarFocusOnAltPressRelease).toBool();
        break;
    case SH_CustomBase:
        // Added to get compiler errors when a style hint is missing
        ret = false;
        break;
    }

    return ret;
}

#if QT_CONFIG(imageformat_xpm)
static QPixmap cachedPixmapFromXPM(const char * const *xpm)
{
    QPixmap result;
    const QString tag = QString::asprintf("xpm:0x%p", static_cast<const void*>(xpm));
    if (!QPixmapCache::find(tag, &result)) {
        result = QPixmap(xpm);
        QPixmapCache::insert(tag, result);
    }
    return result;
}

static inline QPixmap titleBarMenuCachedPixmapFromXPM() { return cachedPixmapFromXPM(qt_menu_xpm); }
#endif // QT_CONFIG(imageformat_xpm)

#if QT_CONFIG(imageformat_png)
static constexpr QLatin1StringView iconResourcePrefix() noexcept { return ":/qt-project.org/styles/commonstyle/images/"_L1; }
static constexpr QLatin1StringView iconPngSuffix() noexcept { return ".png"_L1; }

template <typename T>
static void addIconFiles(QStringView prefix, std::initializer_list<T> sizes, QIcon &icon,
                         QIcon::Mode mode = QIcon::Normal, QIcon::State state = QIcon::Off)
{
    const auto fullPrefix = iconResourcePrefix() + prefix;
    for (int size : sizes)
        icon.addFile(fullPrefix + QString::number(size) + iconPngSuffix(),
                     QSize(size, size), mode, state);
}

static constexpr auto dockTitleIconSizes = {10, 16, 20, 32, 48, 64};
static constexpr auto titleBarSizes = {16, 32, 48};
static constexpr auto toolBarExtHSizes = {8, 16, 32, 128};
static constexpr auto toolBarExtVSizes = {5, 10, 20, 80};
static constexpr auto pngIconSizes = {16, 32, 128};
#endif // imageformat_png

/*! \reimp */
QPixmap QCommonStyle::standardPixmap(StandardPixmap sp, const QStyleOption *option,
                                     const QWidget *widget) const
{
    Q_D(const QCommonStyle);
    QIcon icon;

    icon = d->iconFromWindowsTheme(sp, option, widget);
    if (!icon.isNull())
        return icon.pixmap(QSize(16, 16), QStyleHelper::getDpr(widget));

    icon = d->iconFromApplicationTheme(sp, option, widget);
    if (!icon.isNull())
        return icon.pixmap(QSize(16, 16), QStyleHelper::getDpr(widget));

    icon = d->iconFromMacTheme(sp, option, widget);
    if (!icon.isNull())
        return icon.pixmap(QSize(16, 16), QStyleHelper::getDpr(widget));

    icon = d->iconFromResourceTheme(sp, option, widget);
    if (!icon.isNull())
        return icon.pixmap(QSize(16, 16), QStyleHelper::getDpr(widget));

#ifndef QT_NO_IMAGEFORMAT_XPM
    switch (sp) {
    case QStyle::SP_ToolBarHorizontalExtensionButton:
        if (d->rtl(option)) {
            auto im = QImage(tb_extension_arrow_h_xpm).convertToFormat(QImage::Format_ARGB32).flipped(Qt::Horizontal);
            return QPixmap::fromImage(std::move(im));
        }
        return cachedPixmapFromXPM(tb_extension_arrow_h_xpm);
    case QStyle::SP_ToolBarVerticalExtensionButton:
        return cachedPixmapFromXPM(tb_extension_arrow_v_xpm);
    case QStyle::SP_FileDialogStart:
        return cachedPixmapFromXPM(filedialog_start_xpm);
    case QStyle::SP_FileDialogEnd:
        return cachedPixmapFromXPM(filedialog_end_xpm);
    case QStyle::SP_TitleBarMenuButton:
        return titleBarMenuCachedPixmapFromXPM();
    case QStyle::SP_TitleBarShadeButton:
        return cachedPixmapFromXPM(qt_shade_xpm);
    case QStyle::SP_TitleBarUnshadeButton:
        return cachedPixmapFromXPM(qt_unshade_xpm);
    case QStyle::SP_TitleBarNormalButton:
        return cachedPixmapFromXPM(qt_normalizeup_xpm);
    case QStyle::SP_TitleBarMinButton:
        return cachedPixmapFromXPM(qt_minimize_xpm);
    case QStyle::SP_TitleBarMaxButton:
        return cachedPixmapFromXPM(qt_maximize_xpm);
    case QStyle::SP_TitleBarCloseButton:
        return cachedPixmapFromXPM(qt_close_xpm);
    case QStyle::SP_TitleBarContextHelpButton:
        return cachedPixmapFromXPM(qt_help_xpm);
    case QStyle::SP_DockWidgetCloseButton:
        return cachedPixmapFromXPM(dock_widget_close_xpm);
    case QStyle::SP_MessageBoxInformation:
        return cachedPixmapFromXPM(information_xpm);
    case QStyle::SP_MessageBoxWarning:
        return cachedPixmapFromXPM(warning_xpm);
    case QStyle::SP_MessageBoxCritical:
        return cachedPixmapFromXPM(critical_xpm);
    case QStyle::SP_MessageBoxQuestion:
        return cachedPixmapFromXPM(question_xpm);
    default:
        break;
    }
#endif //QT_NO_IMAGEFORMAT_XPM

    return QPixmap();
}

QIcon QCommonStylePrivate::iconFromWindowsTheme(QCommonStyle::StandardPixmap standardIcon,
                                                const QStyleOption *option,
                                                const QWidget *widget) const
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QIcon icon;
#ifdef Q_OS_WIN
    switch (standardIcon) {
    case QStyle::SP_DriveCDIcon:
    case QStyle::SP_DriveDVDIcon:
    case QStyle::SP_DriveNetIcon:
    case QStyle::SP_DriveHDIcon:
    case QStyle::SP_DriveFDIcon:
    case QStyle::SP_FileIcon:
    case QStyle::SP_FileLinkIcon:
    case QStyle::SP_DesktopIcon:
    case QStyle::SP_ComputerIcon:
    case QStyle::SP_VistaShield:
    case QStyle::SP_MessageBoxInformation:
    case QStyle::SP_MessageBoxWarning:
    case QStyle::SP_MessageBoxCritical:
    case QStyle::SP_MessageBoxQuestion:
        if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme()) {
            QPlatformTheme::StandardPixmap sp = static_cast<QPlatformTheme::StandardPixmap>(standardIcon);
            const auto dpr = QStyleHelper::getDpr(widget);
            const QList<QSize> sizes = theme->themeHint(QPlatformTheme::IconPixmapSizes).value<QList<QSize>>();
            for (const QSize &size : sizes) {
                QPixmap pixmap = theme->standardPixmap(sp, size * dpr);
                pixmap.setDevicePixelRatio(dpr);
                icon.addPixmap(pixmap, QIcon::Normal);
            }
        }
        break;
    case QStyle::SP_DirIcon:
    case QStyle::SP_DirLinkIcon:
        if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme()) {
            QPlatformTheme::StandardPixmap spOff = static_cast<QPlatformTheme::StandardPixmap>(standardIcon);
            QPlatformTheme::StandardPixmap spOn = standardIcon == QStyle::SP_DirIcon ? QPlatformTheme::DirOpenIcon
                                                                                     : QPlatformTheme::DirLinkOpenIcon;
            const auto dpr = QStyleHelper::getDpr(widget);
            const QList<QSize> sizes = theme->themeHint(QPlatformTheme::IconPixmapSizes).value<QList<QSize>>();
            for (const QSize &size : sizes) {
                const QSizeF pixSize = size * dpr;
                QPixmap pixmap = theme->standardPixmap(spOff, pixSize);
                pixmap.setDevicePixelRatio(dpr);
                icon.addPixmap(pixmap, QIcon::Normal, QIcon::Off);
                pixmap = theme->standardPixmap(spOn, pixSize);
                pixmap.setDevicePixelRatio(dpr);
                icon.addPixmap(pixmap, QIcon::Normal, QIcon::On);
            }
        }
        break;
    default:
        break;
    }
#else
    Q_UNUSED(standardIcon)
#endif
    return icon;
}

QIcon QCommonStylePrivate::iconFromApplicationTheme(QCommonStyle::StandardPixmap standardIcon,
                                                    const QStyleOption *option,
                                                    const QWidget *widget) const
{
    if (QGuiApplication::desktopSettingsAware() && !QIcon::themeName().isEmpty()) {
        switch (standardIcon) {
        case QStyle::SP_DirHomeIcon:
            return QIcon::fromTheme("user-home"_L1);
        case QStyle::SP_MessageBoxInformation:
            return QIcon::fromTheme("dialog-information"_L1);
        case QStyle::SP_MessageBoxWarning:
            return QIcon::fromTheme("dialog-warning"_L1);
        case QStyle::SP_MessageBoxCritical:
            return QIcon::fromTheme("dialog-error"_L1);
        case QStyle::SP_MessageBoxQuestion:
            return QIcon::fromTheme("dialog-question"_L1);
        case QStyle::SP_DialogOpenButton:
        case QStyle::SP_DirOpenIcon:
            return QIcon::fromTheme("folder-open"_L1);
        case QStyle::SP_DialogSaveButton:
            return QIcon::fromTheme("document-save"_L1);
        case QStyle::SP_DialogApplyButton:
            return QIcon::fromTheme("dialog-ok-apply"_L1);
        case QStyle::SP_DialogYesButton:
        case QStyle::SP_DialogOkButton:
            return QIcon::fromTheme("dialog-ok"_L1);
        case QStyle::SP_DialogDiscardButton:
            return QIcon::fromTheme("edit-delete"_L1);
        case QStyle::SP_DialogResetButton:
            return QIcon::fromTheme("edit-clear"_L1);
        case QStyle::SP_DialogHelpButton:
            return QIcon::fromTheme("help-contents"_L1);
        case QStyle::SP_FileIcon:
            return QIcon::fromTheme("text-x-generic"_L1);
        case QStyle::SP_DirClosedIcon:
        case QStyle::SP_DirIcon:
            return QIcon::fromTheme("folder"_L1);
        case QStyle::SP_DriveFDIcon:
            return QIcon::fromTheme("floppy_unmount"_L1);
        case QStyle::SP_ComputerIcon:
            return QIcon::fromTheme("computer"_L1, QIcon::fromTheme("system"_L1));
        case QStyle::SP_DesktopIcon:
            return QIcon::fromTheme("user-desktop"_L1);
        case QStyle::SP_TrashIcon:
            return QIcon::fromTheme("user-trash"_L1);
        case QStyle::SP_DriveCDIcon:
        case QStyle::SP_DriveDVDIcon:
            return QIcon::fromTheme("media-optical"_L1);
        case QStyle::SP_DriveHDIcon:
            return QIcon::fromTheme("drive-harddisk"_L1);
        case QStyle::SP_FileDialogToParent:
            return QIcon::fromTheme("go-up"_L1);
        case QStyle::SP_FileDialogNewFolder:
            return QIcon::fromTheme("folder-new"_L1);
        case QStyle::SP_ArrowUp:
            return QIcon::fromTheme("go-up"_L1);
        case QStyle::SP_ArrowDown:
            return QIcon::fromTheme("go-down"_L1);
        case QStyle::SP_ArrowRight:
            return QIcon::fromTheme("go-next"_L1);
        case QStyle::SP_ArrowLeft:
            return QIcon::fromTheme("go-previous"_L1);
        case QStyle::SP_DialogNoButton:
        case QStyle::SP_DialogCancelButton:
            return QIcon::fromTheme("dialog-cancel"_L1, QIcon::fromTheme("process-stop"_L1));
        case QStyle::SP_DialogCloseButton:
            return QIcon::fromTheme("window-close"_L1);
        case QStyle::SP_FileDialogDetailedView:
            return QIcon::fromTheme("view-list-details"_L1);
        case QStyle::SP_FileDialogListView:
            return QIcon::fromTheme("view-list-icons"_L1);
        case QStyle::SP_BrowserReload:
            return QIcon::fromTheme("view-refresh"_L1);
        case QStyle::SP_BrowserStop:
            return QIcon::fromTheme("process-stop"_L1);
        case QStyle::SP_MediaPlay:
            return QIcon::fromTheme("media-playback-start"_L1);
        case QStyle::SP_MediaPause:
            return QIcon::fromTheme("media-playback-pause"_L1);
        case QStyle::SP_MediaStop:
            return QIcon::fromTheme("media-playback-stop"_L1);
        case QStyle::SP_MediaSeekForward:
            return QIcon::fromTheme("media-seek-forward"_L1);
        case QStyle::SP_MediaSeekBackward:
            return QIcon::fromTheme("media-seek-backward"_L1);
        case QStyle::SP_MediaSkipForward:
            return QIcon::fromTheme("media-skip-forward"_L1);
        case QStyle::SP_MediaSkipBackward:
            return QIcon::fromTheme("media-skip-backward"_L1);
        case QStyle::SP_MediaVolume:
            return QIcon::fromTheme("audio-volume-medium"_L1);
        case QStyle::SP_MediaVolumeMuted:
            return QIcon::fromTheme("audio-volume-muted"_L1);
        case QStyle::SP_ArrowForward:
            return iconFromApplicationTheme(rtl(option) ? QStyle::SP_ArrowLeft
                                                        : QStyle::SP_ArrowRight,
                                            option, widget);
        case QStyle::SP_ArrowBack:
            return iconFromApplicationTheme(rtl(option) ? QStyle::SP_ArrowRight
                                                        : QStyle::SP_ArrowLeft,
                                            option, widget);
        case QStyle::SP_DirLinkIcon:
        case QStyle::SP_FileLinkIcon: {
                const auto si = (standardIcon == QStyle::SP_DirLinkIcon)
                    ? QStyle::SP_DirIcon : QStyle::SP_FileIcon;
                QIcon icon;
                const QIcon linkIcon = QIcon::fromTheme("emblem-symbolic-link"_L1);
                const QIcon baseIcon = iconFromApplicationTheme(si, option, widget);
                if (!linkIcon.isNull() || !baseIcon.isNull()) {
                    const auto sizes = baseIcon.availableSizes(QIcon::Normal, QIcon::Off);
                    const auto dpr = QStyleHelper::getDpr(widget);
                    for (const auto size : sizes) {
                        QPixmap basePixmap = baseIcon.pixmap(size, dpr);
                        QPixmap linkPixmap = linkIcon.pixmap(size / 2, dpr);
                        QPainter painter(&basePixmap);
                        const auto w = size.width() / 2;
                        painter.drawPixmap(w, w, linkPixmap);
                        icon.addPixmap(basePixmap);
                    }
                }
                return icon;
            }
            break;
        case QStyle::SP_LineEditClearButton: {
            const QString directionalThemeName = rtl(option)
                ? QStringLiteral("edit-clear-locationbar-ltr") : QStringLiteral("edit-clear-locationbar-rtl");
            if (QIcon::hasThemeIcon(directionalThemeName))
                return QIcon::fromTheme(directionalThemeName);
            const QString themeName = QStringLiteral("edit-clear");
            if (QIcon::hasThemeIcon(themeName))
                return QIcon::fromTheme(themeName);
            break;
        }
        default:
            break;
        }
    } // if (QGuiApplication::desktopSettingsAware() && !QIcon::themeName().isEmpty())

    return {};
}

QIcon QCommonStylePrivate::iconFromMacTheme(QCommonStyle::StandardPixmap standardIcon,
                                            const QStyleOption *option,
                                            const QWidget *widget) const
{
#ifdef Q_OS_DARWIN
    Q_Q(const QCommonStyle);
    if (QGuiApplication::desktopSettingsAware()) {
        switch (standardIcon) {
        case QStyle::SP_DirIcon: {
            // A rather special case
            QIcon closeIcon = q->standardIcon(QStyle::SP_DirClosedIcon, option, widget);
            QIcon openIcon = q->standardIcon(QStyle::SP_DirOpenIcon, option, widget);
            closeIcon.addPixmap(openIcon.pixmap(16, 16), QIcon::Normal, QIcon::On);
            closeIcon.addPixmap(openIcon.pixmap(32, 32), QIcon::Normal, QIcon::On);
            closeIcon.addPixmap(openIcon.pixmap(64, 64), QIcon::Normal, QIcon::On);
            closeIcon.addPixmap(openIcon.pixmap(128, 128), QIcon::Normal, QIcon::On);
            return closeIcon;
        }

        case QStyle::SP_TitleBarNormalButton:
        case QStyle::SP_TitleBarCloseButton: {
            QIcon titleBarIcon;
            constexpr auto imagesPrefix = ":/qt-project.org/styles/macstyle/images/"_L1;
            const auto namePrefix = standardIcon == QStyle::SP_TitleBarCloseButton
                              ? "closedock-"_L1
                              : "dockdock-"_L1;
            for (const auto size : dockTitleIconSizes) {
                titleBarIcon.addFile(imagesPrefix + namePrefix + "macstyle-"_L1 + QString::number(size)
                                     + iconPngSuffix(), QSize(size, size), QIcon::Normal, QIcon::Off);
                titleBarIcon.addFile(imagesPrefix + namePrefix + "down-macstyle-"_L1 + QString::number(size)
                                     + iconPngSuffix(), QSize(size, size), QIcon::Normal, QIcon::On);
            }
            return titleBarIcon;
        }

        case QStyle::SP_MessageBoxQuestion:
        case QStyle::SP_MessageBoxInformation:
        case QStyle::SP_MessageBoxWarning:
        case QStyle::SP_MessageBoxCritical:
        case QStyle::SP_DesktopIcon:
        case QStyle::SP_TrashIcon:
        case QStyle::SP_ComputerIcon:
        case QStyle::SP_DriveFDIcon:
        case QStyle::SP_DriveHDIcon:
        case QStyle::SP_DriveCDIcon:
        case QStyle::SP_DriveDVDIcon:
        case QStyle::SP_DriveNetIcon:
        case QStyle::SP_DirOpenIcon:
        case QStyle::SP_DirClosedIcon:
        case QStyle::SP_DirLinkIcon:
        case QStyle::SP_FileLinkIcon:
        case QStyle::SP_FileIcon:
            if (const QPlatformTheme *theme = QGuiApplicationPrivate::platformTheme()) {
                QPlatformTheme::StandardPixmap sp = static_cast<QPlatformTheme::StandardPixmap>(standardIcon);
                QIcon retIcon;
                const QList<QSize> sizes = theme->themeHint(QPlatformTheme::IconPixmapSizes).value<QList<QSize> >();
                for (const QSize &size : sizes) {
                    QPixmap mainIcon;
                    const QString cacheKey = "qt_mac_constructQIconFromIconRef"_L1 + QString::number(standardIcon) + QString::number(size.width());
                    if (standardIcon >= QStyle::SP_CustomBase) {
                        mainIcon = theme->standardPixmap(sp, QSizeF(size));
                    } else if (QPixmapCache::find(cacheKey, &mainIcon) == false) {
                        mainIcon = theme->standardPixmap(sp, QSizeF(size));
                        QPixmapCache::insert(cacheKey, mainIcon);
                    }

                    retIcon.addPixmap(mainIcon);
                }
                return retIcon;
            }

        default:
            break;
        }
    } // if (QGuiApplication::desktopSettingsAware())
#else // Q_OS_DARWIN
    Q_UNUSED(standardIcon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
#endif // Q_OS_DARWIN
    return {};
}

QIcon QCommonStylePrivate::iconFromResourceTheme(QCommonStyle::StandardPixmap standardIcon,
                                                 const QStyleOption *option,
                                                 const QWidget *widget) const
{
    Q_Q(const QCommonStyle);
    QIcon icon;
#ifndef QT_NO_IMAGEFORMAT_PNG
    switch (standardIcon) {
    case QStyle::SP_MessageBoxInformation:
        addIconFiles(u"information-", pngIconSizes, icon);
        break;
    case QStyle::SP_MessageBoxWarning:
        addIconFiles(u"warning-", pngIconSizes, icon);
        break;
    case QStyle::SP_MessageBoxCritical:
        addIconFiles(u"critical-", pngIconSizes, icon);
        break;
    case QStyle::SP_MessageBoxQuestion:
        addIconFiles(u"question-", pngIconSizes, icon);
        break;
    case QStyle::SP_FileDialogStart:
        addIconFiles(u"filedialog_start-", pngIconSizes, icon);
        break;
    case QStyle::SP_FileDialogEnd:
        addIconFiles(u"filedialog_end-", pngIconSizes, icon);
        break;
    case QStyle::SP_TitleBarMinButton:
        addIconFiles(u"titlebar-min-", titleBarSizes, icon);
        break;
    case QStyle::SP_TitleBarMaxButton:
        addIconFiles(u"titlebar-max-", titleBarSizes, icon);
        break;
    case QStyle::SP_TitleBarShadeButton:
        addIconFiles(u"titlebar-shade-", titleBarSizes, icon);
        break;
    case QStyle::SP_TitleBarUnshadeButton:
        addIconFiles(u"titlebar-unshade-", titleBarSizes, icon);
        break;
    case QStyle::SP_TitleBarContextHelpButton:
        addIconFiles(u"titlebar-contexthelp-", titleBarSizes, icon);
        break;
     case QStyle::SP_FileDialogNewFolder:
        addIconFiles(u"newdirectory-", pngIconSizes, icon);
        break;
    case QStyle::SP_FileDialogBack:
        return q->proxy()->standardIcon(QStyle::SP_ArrowBack, option, widget);
    case QStyle::SP_FileDialogToParent:
        return q->proxy()->standardIcon(QStyle::SP_ArrowUp, option, widget);
    case QStyle::SP_FileDialogDetailedView:
        addIconFiles(u"viewdetailed-", pngIconSizes, icon);
        break;
    case QStyle::SP_FileDialogInfoView:
        addIconFiles(u"fileinfo-", pngIconSizes, icon);
        break;
    case QStyle::SP_FileDialogContentsView:
        addIconFiles(u"filecontents-", pngIconSizes, icon);
        break;
    case QStyle::SP_FileDialogListView:
        addIconFiles(u"viewlist-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogOkButton:
        addIconFiles(u"standardbutton-ok-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogCancelButton:
        addIconFiles(u"standardbutton-cancel-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogHelpButton:
        addIconFiles(u"standardbutton-help-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogOpenButton:
        addIconFiles(u"standardbutton-open-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogSaveButton:
        addIconFiles(u"standardbutton-save-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogCloseButton:
        addIconFiles(u"standardbutton-close-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogApplyButton:
        addIconFiles(u"standardbutton-apply-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogResetButton:
        addIconFiles(u"standardbutton-clear-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogDiscardButton:
        addIconFiles(u"standardbutton-delete-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogYesButton:
        addIconFiles(u"standardbutton-yes-", pngIconSizes, icon);
        break;
    case QStyle::SP_DialogNoButton:
        addIconFiles(u"standardbutton-no-", pngIconSizes, icon);
        break;
    case QStyle::SP_CommandLink:
    case QStyle::SP_ArrowForward:
        return q->proxy()->standardIcon(rtl(option) ? QStyle::SP_ArrowLeft
                                                    : QStyle::SP_ArrowRight,
                                        option, widget);
    case QStyle::SP_ArrowBack:
        return q->proxy()->standardIcon(rtl(option) ? QStyle::SP_ArrowRight
                                                    : QStyle::SP_ArrowLeft,
                                        option, widget);
    case QStyle::SP_ArrowLeft:
        addIconFiles(u"left-", pngIconSizes, icon);
        break;
    case QStyle::SP_ArrowRight:
        addIconFiles(u"right-", pngIconSizes, icon);
        break;
    case QStyle::SP_ArrowUp:
        addIconFiles(u"up-", pngIconSizes, icon);
        break;
    case QStyle::SP_ArrowDown:
        addIconFiles(u"down-", pngIconSizes, icon);
        break;
   case QStyle::SP_DirHomeIcon:
   case QStyle::SP_DirIcon:
        addIconFiles(u"dirclosed-", pngIconSizes, icon, QIcon::Normal, QIcon::Off);
        addIconFiles(u"diropen-", pngIconSizes, icon, QIcon::Normal, QIcon::On);
        break;
    case QStyle::SP_DirOpenIcon:
        addIconFiles(u"diropen-", pngIconSizes, icon);
        break;
    case QStyle::SP_DirClosedIcon:
        addIconFiles(u"dirclosed-", pngIconSizes, icon);
        break;
    case QStyle::SP_DirLinkIcon:
        addIconFiles(u"dirlink-", pngIconSizes, icon);
        break;
    case QStyle::SP_DriveCDIcon:
        addIconFiles(u"cdr-", pngIconSizes, icon);
        break;
    case QStyle::SP_DriveFDIcon:
        addIconFiles(u"floppy-", pngIconSizes, icon);
        break;
    case QStyle::SP_DriveHDIcon:
        addIconFiles(u"harddrive-", pngIconSizes, icon);
        break;
    case QStyle::SP_DriveDVDIcon:
        addIconFiles(u"dvd-", pngIconSizes, icon);
        break;
    case QStyle::SP_DriveNetIcon:
        addIconFiles(u"networkdrive-", pngIconSizes, icon);
        break;
    case QStyle::SP_FileIcon:
        addIconFiles(u"file-", pngIconSizes, icon);
        break;
    case QStyle::SP_FileLinkIcon:
        addIconFiles(u"filelink-", pngIconSizes, icon);
        break;
    case QStyle::SP_DesktopIcon:
        addIconFiles(u"desktop-", {16, 32}, icon);
        break;
    case QStyle::SP_TrashIcon:
        addIconFiles(u"trash-", pngIconSizes, icon);
        break;
    case QStyle::SP_ComputerIcon:
        addIconFiles(u"computer-", {16, 32}, icon);
        break;
    case QStyle::SP_BrowserReload:
        addIconFiles(u"refresh-", {24, 32}, icon);
        break;
    case QStyle::SP_BrowserStop:
        addIconFiles(u"stop-", {24, 32}, icon);
        break;
    case QStyle::SP_MediaPlay:
        addIconFiles(u"media-play-", pngIconSizes, icon);
        break;
    case QStyle::SP_MediaPause:
        addIconFiles(u"media-pause-", pngIconSizes, icon);
        break;
    case QStyle::SP_MediaStop:
        addIconFiles(u"media-stop-", pngIconSizes, icon);
        break;
    case QStyle::SP_MediaSeekForward:
        addIconFiles(u"media-seek-forward-", pngIconSizes, icon);
        break;
    case QStyle::SP_MediaSeekBackward:
        addIconFiles(u"media-seek-backward-", pngIconSizes, icon);
        break;
    case QStyle::SP_MediaSkipForward:
        addIconFiles(u"media-skip-forward-", pngIconSizes, icon);
        break;
    case QStyle::SP_MediaSkipBackward:
        addIconFiles(u"media-skip-backward-", pngIconSizes, icon);
        break;
    case QStyle::SP_MediaVolume:
        addIconFiles(u"media-volume-", {16}, icon);
        break;
    case QStyle::SP_MediaVolumeMuted:
        addIconFiles(u"media-volume-muted-", {16}, icon);
        break;
    case QStyle::SP_TitleBarCloseButton:
    case QStyle::SP_DockWidgetCloseButton:
        addIconFiles(u"closedock-", dockTitleIconSizes, icon);
        break;
    case QStyle::SP_TitleBarMenuButton:
#  ifndef QT_NO_IMAGEFORMAT_XPM
        icon.addPixmap(titleBarMenuCachedPixmapFromXPM());
#  endif
        icon.addFile(":/qt-project.org/qmessagebox/images/qtlogo-64.png"_L1);
        break;
    case QStyle::SP_TitleBarNormalButton:
        addIconFiles(u"normalizedockup-", dockTitleIconSizes, icon);
        break;
    case QStyle::SP_ToolBarHorizontalExtensionButton:
        addIconFiles(rtl(option) ? u"toolbar-ext-h-rtl-" : u"toolbar-ext-h-", toolBarExtHSizes, icon);
        break;
    case QStyle::SP_ToolBarVerticalExtensionButton:
        addIconFiles(u"toolbar-ext-v-", toolBarExtVSizes, icon);
        break;
    case QStyle::SP_TabCloseButton:
        addIconFiles(u"standardbutton-closetab-", pngIconSizes, icon, QIcon::Normal, QIcon::Off);
        addIconFiles(u"standardbutton-closetab-down-", pngIconSizes, icon, QIcon::Normal, QIcon::On);
        addIconFiles(u"standardbutton-closetab-hover-", pngIconSizes, icon, QIcon::Active, QIcon::Off);
        break;
    case QStyle::SP_LineEditClearButton:
        addIconFiles(u"cleartext-", pngIconSizes, icon);
        break;
    default:
        break;
    }
#else // QT_NO_IMAGEFORMAT_PNG
    Q_UNUSED(standardIcon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
#endif // QT_NO_IMAGEFORMAT_PNG
    return icon;
}


/*!
    \internal
*/
QIcon QCommonStyle::standardIcon(StandardPixmap standardIcon, const QStyleOption *option,
                                 const QWidget *widget) const
{
    Q_D(const QCommonStyle);
    QIcon icon;

    icon = d->iconFromWindowsTheme(standardIcon, option, widget);
    if (!icon.isNull())
        return icon;

    icon = d->iconFromApplicationTheme(standardIcon, option, widget);
    if (!icon.isNull())
        return icon;

    icon = d->iconFromMacTheme(standardIcon, option, widget);
    if (!icon.isNull())
        return icon;

    icon = d->iconFromResourceTheme(standardIcon, option, widget);
    if (!icon.isNull())
        return icon;

#ifndef QT_NO_IMAGEFORMAT_XPM
    switch (standardIcon) {
    case QStyle::SP_TitleBarMenuButton:
        icon.addPixmap(titleBarMenuCachedPixmapFromXPM());
        break;
    default:
        break;
    }
    if (!icon.isNull())
        return icon;
#endif
    icon = proxy()->standardPixmap(standardIcon, option, widget);
    return icon;
}

static inline uint qt_intensity(uint r, uint g, uint b)
{
    // 30% red, 59% green, 11% blue
    return (77 * r + 150 * g + 28 * b) / 255;
}

/*! \reimp */
QPixmap QCommonStyle::generatedIconPixmap(QIcon::Mode iconMode, const QPixmap &pixmap,
                                          const QStyleOption *opt) const
{
    switch (iconMode) {
    case QIcon::Disabled: {
        QImage im = pixmap.toImage().convertToFormat(QImage::Format_ARGB32);

        // Create a colortable based on the background (black -> bg -> white)
        QColor bg = opt->palette.color(QPalette::Disabled, QPalette::Window);
        int red = bg.red();
        int green = bg.green();
        int blue = bg.blue();
        uchar reds[256], greens[256], blues[256];
        for (int i=0; i<128; ++i) {
            reds[i]   = uchar((red   * (i<<1)) >> 8);
            greens[i] = uchar((green * (i<<1)) >> 8);
            blues[i]  = uchar((blue  * (i<<1)) >> 8);
        }
        for (int i=0; i<128; ++i) {
            reds[i+128]   = uchar(qMin(red   + (i << 1), 255));
            greens[i+128] = uchar(qMin(green + (i << 1), 255));
            blues[i+128]  = uchar(qMin(blue  + (i << 1), 255));
        }

        int intensity = qt_intensity(red, green, blue);
        const int factor = 191;

        // High intensity colors needs dark shifting in the color table, while
        // low intensity colors needs light shifting. This is to increase the
        // perceived contrast.
        if ((red - factor > green && red - factor > blue)
            || (green - factor > red && green - factor > blue)
            || (blue - factor > red && blue - factor > green))
            intensity = qMin(255, intensity + 91);
        else if (intensity <= 128)
            intensity -= 51;

        for (int y=0; y<im.height(); ++y) {
            QRgb *scanLine = (QRgb*)im.scanLine(y);
            for (int x=0; x<im.width(); ++x) {
                QRgb pixel = *scanLine;
                // Calculate color table index, taking intensity adjustment
                // and a magic offset into account.
                uint ci = uint(qGray(pixel)/3 + (130 - intensity / 3));
                *scanLine = qRgba(reds[ci], greens[ci], blues[ci], qAlpha(pixel));
                ++scanLine;
            }
        }

        return QPixmap::fromImage(std::move(im));
    }
    case QIcon::Selected: {
        QImage img = pixmap.toImage().convertToFormat(QImage::Format_ARGB32_Premultiplied);
        QColor color = opt->palette.color(QPalette::Normal, QPalette::Highlight);
        color.setAlphaF(0.3f);
        QPainter painter(&img);
        painter.setCompositionMode(QPainter::CompositionMode_SourceAtop);
        painter.fillRect(0, 0, img.width(), img.height(), color);
        painter.end();
        return QPixmap::fromImage(std::move(img)); }
    case QIcon::Active:
        return pixmap;
    default:
        break;
    }
    return pixmap;
}

/*!
  \reimp
*/
int QCommonStyle::layoutSpacing(QSizePolicy::ControlType /* control1 */, QSizePolicy::ControlType /* control2 */,
                          Qt::Orientation /* orientation */, const QStyleOption * /* option */,
                          const QWidget * /* widget */) const
{
    return -1;
}

/*!
  \reimp
*/
void QCommonStyle::polish(QPalette &pal)
{
    QStyle::polish(pal);
    QCachedPainter::cleanupPixmapCache();
}

/*!
    \reimp
 */
void QCommonStyle::polish(QWidget *widget)
{
    QStyle::polish(widget);
}

/*!
    \reimp
 */
void QCommonStyle::unpolish(QWidget *widget)
{
    QStyle::unpolish(widget);
}

/*!
  \reimp
*/
void QCommonStyle::polish(QApplication *app)
{
    QStyle::polish(app);
}

/*!
    \reimp
 */
void QCommonStyle::unpolish(QApplication *application)
{
    Q_D(const QCommonStyle);
    d->tabBarcloseButtonIcon = QIcon();
    QStyle::unpolish(application);
}


QT_END_NAMESPACE

#include "moc_qcommonstyle.cpp"
