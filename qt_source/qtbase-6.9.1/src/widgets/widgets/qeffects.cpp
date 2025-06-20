// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qapplication.h"
#include "qdebug.h"
#include "qeffects_p.h"
#include "qelapsedtimer.h"
#include "qevent.h"
#include "qimage.h"
#include "qpainter.h"
#include "qscreen.h"
#include "qpixmap.h"
#include "qpointer.h"
#include "qtimer.h"
#include "qwidget.h"
#include "private/qwidget_p.h"
#include "qwindow.h"


QT_BEGIN_NAMESPACE

struct DeleteLater
{
    void operator()(QObject *o) const
    {
        if (o)
            o->deleteLater();
    }
};

/*
  Internal class QAlphaWidget.

  The QAlphaWidget is shown while the animation lasts
  and displays the pixmap resulting from the alpha blending.
*/

class QAlphaWidget: public QWidget, private QEffects
{
    Q_OBJECT
public:
    QAlphaWidget(QWidget* w, Qt::WindowFlags f = { });
    ~QAlphaWidget();

    void run(int time);

protected:
    void paintEvent(QPaintEvent* e) override;
    void closeEvent(QCloseEvent*) override;
    void alphaBlend();
    bool eventFilter(QObject *, QEvent *) override;

protected slots:
    void render();

private:
    QPixmap pm;
    double alpha;
    QImage backImage;
    QImage frontImage;
    QImage mixedImage;
    QPointer<QWidget> widget;
    int duration;
    int elapsed;
    bool showWidget;
    QTimer anim;
    QElapsedTimer checkTime;
};

static std::unique_ptr<QAlphaWidget, DeleteLater> q_blend;

/*
  Constructs a QAlphaWidget.
*/
QAlphaWidget::QAlphaWidget(QWidget* w, Qt::WindowFlags f)
    : QWidget(nullptr, f)
{
    QWidgetPrivate::get(this)->setScreen(w->screen());
#ifndef Q_OS_WIN
    setEnabled(false);
#endif
    setAttribute(Qt::WA_NoSystemBackground, true);
    widget = w;
    alpha = 0;
}

QAlphaWidget::~QAlphaWidget()
{
#if defined(Q_OS_WIN)
    // Restore user-defined opacity value
    if (widget)
        widget->setWindowOpacity(1);
#endif
}

/*
  \reimp
*/
void QAlphaWidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawPixmap(0, 0, pm);
}

/*
  Starts the alphablending animation.
  The animation will take about \a time ms
*/
void QAlphaWidget::run(int time)
{
    duration = time;

    if (duration < 0)
        duration = 150;

    if (!widget)
        return;

    elapsed = 0;
    checkTime.start();

    showWidget = true;
#if defined(Q_OS_WIN)
    qApp->installEventFilter(this);
    widget->setWindowOpacity(0.0);
    widget->show();
    connect(&anim, &QTimer::timeout, this, &QAlphaWidget::render);
    anim.start(1);
#else
    //This is roughly equivalent to calling setVisible(true) without actually showing the widget
    widget->setAttribute(Qt::WA_WState_ExplicitShowHide, true);
    widget->setAttribute(Qt::WA_WState_Hidden, false);

    qApp->installEventFilter(this);

    move(widget->geometry().x(),widget->geometry().y());
    resize(widget->size().width(), widget->size().height());

    frontImage = widget->grab().toImage();
    backImage = QGuiApplication::primaryScreen()->grabWindow(0,
                                widget->geometry().x(), widget->geometry().y(),
                                widget->geometry().width(), widget->geometry().height()).toImage();

    if (!backImage.isNull() && checkTime.elapsed() < duration / 2) {
        mixedImage = backImage.copy();
        pm = QPixmap::fromImage(mixedImage);
        show();
        setEnabled(false);

        connect(&anim, &QTimer::timeout, this, &QAlphaWidget::render);
        anim.start(1);
    } else {
       duration = 0;
       render();
    }
#endif
}

/*
  \reimp
*/
bool QAlphaWidget::eventFilter(QObject *o, QEvent *e)
{
    switch (e->type()) {
    case QEvent::Move:
        if (o != widget)
            break;
        move(widget->geometry().x(),widget->geometry().y());
        update();
        break;
    case QEvent::Hide:
    case QEvent::Close:
       if (o != widget)
           break;
       Q_FALLTHROUGH();
    case QEvent::MouseButtonPress:
    case QEvent::MouseButtonDblClick:
        showWidget = false;
        render();
        break;
    case QEvent::KeyPress: {
#ifndef QT_NO_SHORTCUT
       QKeyEvent *ke = static_cast<QKeyEvent *>(e);
       if (ke->matches(QKeySequence::Cancel)) {
           showWidget = false;
       } else
#endif
       {
           duration = 0;
       }
       render();
       break;
    }
    default:
       break;
    }
    return QWidget::eventFilter(o, e);
}

/*
  \reimp
*/
void QAlphaWidget::closeEvent(QCloseEvent *e)
{
    e->accept();
    if (!q_blend)
        return;

    showWidget = false;
    render();

    QWidget::closeEvent(e);
}

/*
  Render alphablending for the time elapsed.

  Show the blended widget and free all allocated source
  if the blending is finished.
*/
void QAlphaWidget::render()
{
    int tempel = checkTime.elapsed();
    if (elapsed >= tempel)
        elapsed++;
    else
        elapsed = tempel;

    if (duration != 0)
        alpha = tempel / double(duration);
    else
        alpha = 1;

#if defined(Q_OS_WIN)
    if (alpha >= 1 || !showWidget) {
        anim.stop();
        qApp->removeEventFilter(this);
        widget->setWindowOpacity(1);
        q_blend.reset();
    } else {
        widget->setWindowOpacity(alpha);
    }
#else
    if (alpha >= 1 || !showWidget) {
        anim.stop();
        qApp->removeEventFilter(this);

        if (widget) {
            if (!showWidget) {
                widget->hide();
            } else {
                //Since we are faking the visibility of the widget
                //we need to unset the hidden state on it before calling show
                widget->setAttribute(Qt::WA_WState_Hidden, true);
                widget->show();
                lower();
            }
        }
        q_blend.reset();
    } else {
        alphaBlend();
        pm = QPixmap::fromImage(mixedImage);
        repaint();
    }
#endif // defined(Q_OS_WIN)
}

/*
  Calculate an alphablended image.
*/
void QAlphaWidget::alphaBlend()
{
    const int a = qRound(alpha*256);
    const int ia = 256 - a;

    const int sw = frontImage.width();
    const int sh = frontImage.height();
    const qsizetype bpl = frontImage.bytesPerLine();
    switch(frontImage.depth()) {
    case 32:
        {
            uchar *mixed_data = mixedImage.bits();
            const uchar *back_data = backImage.bits();
            const uchar *front_data = frontImage.bits();

            for (int sy = 0; sy < sh; sy++) {
                quint32* mixed = (quint32*)mixed_data;
                const quint32* back = (const quint32*)back_data;
                const quint32* front = (const quint32*)front_data;
                for (int sx = 0; sx < sw; sx++) {
                    quint32 bp = back[sx];
                    quint32 fp = front[sx];

                    mixed[sx] =  qRgb((qRed(bp)*ia + qRed(fp)*a)>>8,
                                      (qGreen(bp)*ia + qGreen(fp)*a)>>8,
                                      (qBlue(bp)*ia + qBlue(fp)*a)>>8);
                }
                mixed_data += bpl;
                back_data += bpl;
                front_data += bpl;
            }
            break;
        }
    default:
        break;
    }
}

/*
  Internal class QRollEffect

  The QRollEffect widget is shown while the animation lasts
  and displays a scrolling pixmap.
*/

class QRollEffect : public QWidget, private QEffects
{
    Q_OBJECT
public:
    QRollEffect(QWidget* w, Qt::WindowFlags f, DirFlags orient);

    void run(int time);

protected:
    void paintEvent(QPaintEvent*) override;
    void closeEvent(QCloseEvent*) override;

private slots:
    void scroll();

private:
    QPointer<QWidget> widget;

    int currentHeight;
    int currentWidth;
    int totalHeight;
    int totalWidth;

    int duration;
    int elapsed;
    bool done;
    bool showWidget;
    int orientation;

    QTimer anim;
    QElapsedTimer checkTime;

    QPixmap pm;
};

static std::unique_ptr<QRollEffect, DeleteLater> q_roll;

/*
  Construct a QRollEffect widget.
*/
QRollEffect::QRollEffect(QWidget* w, Qt::WindowFlags f, DirFlags orient)
    : QWidget(nullptr, f), orientation(orient)
{
    QWidgetPrivate::get(this)->setScreen(w->screen());
#ifndef Q_OS_WIN
    setEnabled(false);
#endif

    widget = w;
    Q_ASSERT(widget);

    setAttribute(Qt::WA_NoSystemBackground, true);

    if (widget->testAttribute(Qt::WA_Resized)) {
        totalWidth = widget->width();
        totalHeight = widget->height();
    } else {
        totalWidth = widget->sizeHint().width();
        totalHeight = widget->sizeHint().height();
    }

    currentHeight = totalHeight;
    currentWidth = totalWidth;

    if (orientation & (RightScroll|LeftScroll))
        currentWidth = 0;
    if (orientation & (DownScroll|UpScroll))
        currentHeight = 0;

    pm = widget->grab();
}

/*
  \reimp
*/
void QRollEffect::paintEvent(QPaintEvent*)
{
    int x = orientation & RightScroll ? qMin(0, currentWidth - totalWidth) : 0;
    int y = orientation & DownScroll ? qMin(0, currentHeight - totalHeight) : 0;

    QPainter p(this);
    p.drawPixmap(x, y, pm);
}

/*
  \reimp
*/
void QRollEffect::closeEvent(QCloseEvent *e)
{
    e->accept();
    if (done)
        return;

    showWidget = false;
    done = true;
    scroll();

    QWidget::closeEvent(e);
}

/*
  Start the animation.

  The animation will take about \a time ms, or is
  calculated if \a time is negative
*/
void QRollEffect::run(int time)
{
    if (!widget)
        return;

    duration  = time;
    elapsed = 0;

    if (duration < 0) {
        int dist = 0;
        if (orientation & (RightScroll|LeftScroll))
            dist += totalWidth - currentWidth;
        if (orientation & (DownScroll|UpScroll))
            dist += totalHeight - currentHeight;
        duration = qMin(qMax(dist/3, 50), 120);
    }

    connect(&anim, &QTimer::timeout, this, &QRollEffect::scroll);

    move(widget->geometry().x(),widget->geometry().y());
    resize(qMin(currentWidth, totalWidth), qMin(currentHeight, totalHeight));

    //This is roughly equivalent to calling setVisible(true) without actually showing the widget
    widget->setAttribute(Qt::WA_WState_ExplicitShowHide, true);
    widget->setAttribute(Qt::WA_WState_Hidden, false);

    show();
    setEnabled(false);

    showWidget = true;
    done = false;
    anim.start(1);
    checkTime.start();
}

/*
  Roll according to the time elapsed.
*/
void QRollEffect::scroll()
{
    if (!done && widget) {
        int tempel = checkTime.elapsed();
        if (elapsed >= tempel)
            elapsed++;
        else
            elapsed = tempel;

        if (currentWidth != totalWidth) {
            currentWidth = totalWidth * (elapsed/duration)
                + (2 * totalWidth * (elapsed%duration) + duration)
                / (2 * duration);
            // equiv. to int((totalWidth*elapsed) / duration + 0.5)
        }
        if (currentHeight != totalHeight) {
            currentHeight = totalHeight * (elapsed/duration)
                + (2 * totalHeight * (elapsed%duration) + duration)
                / (2 * duration);
            // equiv. to int((totalHeight*elapsed) / duration + 0.5)
        }
        done = (currentHeight >= totalHeight) &&
               (currentWidth >= totalWidth);

        int w = totalWidth;
        int h = totalHeight;
        int x = widget->geometry().x();
        int y = widget->geometry().y();

        if (orientation & RightScroll || orientation & LeftScroll)
            w = qMin(currentWidth, totalWidth);
        if (orientation & DownScroll || orientation & UpScroll)
            h = qMin(currentHeight, totalHeight);

        setUpdatesEnabled(false);
        if (orientation & UpScroll)
            y = widget->geometry().y() + qMax(0, totalHeight - currentHeight);
        if (orientation & LeftScroll)
            x = widget->geometry().x() + qMax(0, totalWidth - currentWidth);
        if (orientation & UpScroll || orientation & LeftScroll)
            move(x, y);

        resize(w, h);
        setUpdatesEnabled(true);
        repaint();
    }
    if (done || !widget) {
        anim.stop();
        if (widget) {
            if (!showWidget) {
#ifdef Q_OS_WIN
                setEnabled(true);
                setFocus();
#endif
                widget->hide();
            } else {
                //Since we are faking the visibility of the widget
                //we need to unset the hidden state on it before calling show
                widget->setAttribute(Qt::WA_WState_Hidden, true);
                widget->show();
                lower();
            }
        }
        q_roll.reset();
    }
}

/*
    Scroll widget \a w in \a time ms. \a orient may be 1 (vertical), 2
    (horizontal) or 3 (diagonal).
*/
void qScrollEffect(QWidget* w, QEffects::DirFlags orient, int time)
{
    q_roll.reset();

    if (!w)
        return;

    QCoreApplication::sendPostedEvents(w, QEvent::Move);
    QCoreApplication::sendPostedEvents(w, QEvent::Resize);
    Qt::WindowFlags flags = Qt::ToolTip;

    // those can be popups - they would steal the focus, but are disabled
    q_roll.reset(new QRollEffect(w, flags, orient));
    q_roll->run(time);
}

/*
    Fade in widget \a w in \a time ms.
*/
void qFadeEffect(QWidget* w, int time)
{
    q_blend.reset();

    if (!w)
        return;

    QCoreApplication::sendPostedEvents(w, QEvent::Move);
    QCoreApplication::sendPostedEvents(w, QEvent::Resize);

    Qt::WindowFlags flags = Qt::ToolTip;

    // those can be popups - they would steal the focus, but are disabled
    q_blend.reset(new QAlphaWidget(w, flags));

    q_blend->run(time);
}

QT_END_NAMESPACE

/*
  Delete this after timeout
*/

#include "qeffects.moc"
