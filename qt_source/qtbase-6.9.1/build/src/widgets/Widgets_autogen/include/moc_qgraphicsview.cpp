/****************************************************************************
** Meta object code from reading C++ file 'qgraphicsview.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/graphicsview/qgraphicsview.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicsview.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QGraphicsViewE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsView::qt_create_metaobjectdata<qt_meta_tag_ZN13QGraphicsViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsView",
        "rubberBandChanged",
        "",
        "viewportRect",
        "fromScenePoint",
        "toScenePoint",
        "updateScene",
        "QList<QRectF>",
        "rects",
        "invalidateScene",
        "rect",
        "QGraphicsScene::SceneLayers",
        "layers",
        "updateSceneRect",
        "setupViewport",
        "QWidget*",
        "widget",
        "_q_setViewportCursor",
        "_q_unsetViewportCursor",
        "backgroundBrush",
        "foregroundBrush",
        "interactive",
        "sceneRect",
        "alignment",
        "Qt::Alignment",
        "renderHints",
        "QPainter::RenderHints",
        "dragMode",
        "DragMode",
        "cacheMode",
        "CacheMode",
        "transformationAnchor",
        "ViewportAnchor",
        "resizeAnchor",
        "viewportUpdateMode",
        "ViewportUpdateMode",
        "rubberBandSelectionMode",
        "Qt::ItemSelectionMode",
        "optimizationFlags",
        "OptimizationFlags",
        "NoAnchor",
        "AnchorViewCenter",
        "AnchorUnderMouse",
        "CacheModeFlag",
        "CacheNone",
        "CacheBackground",
        "NoDrag",
        "ScrollHandDrag",
        "RubberBandDrag",
        "FullViewportUpdate",
        "MinimalViewportUpdate",
        "SmartViewportUpdate",
        "NoViewportUpdate",
        "BoundingRectViewportUpdate",
        "OptimizationFlag",
        "DontSavePainterState",
        "DontAdjustForAntialiasing",
        "IndirectPainting"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'rubberBandChanged'
        QtMocHelpers::SignalData<void(QRect, QPointF, QPointF)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRect, 3 }, { QMetaType::QPointF, 4 }, { QMetaType::QPointF, 5 },
        }}),
        // Slot 'updateScene'
        QtMocHelpers::SlotData<void(const QList<QRectF> &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Slot 'invalidateScene'
        QtMocHelpers::SlotData<void(const QRectF &, QGraphicsScene::SceneLayers)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 10 }, { 0x80000000 | 11, 12 },
        }}),
        // Slot 'invalidateScene'
        QtMocHelpers::SlotData<void(const QRectF &)>(9, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QRectF, 10 },
        }}),
        // Slot 'invalidateScene'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'updateSceneRect'
        QtMocHelpers::SlotData<void(const QRectF &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 10 },
        }}),
        // Slot 'setupViewport'
        QtMocHelpers::SlotData<void(QWidget *)>(14, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Slot '_q_setViewportCursor'
        QtMocHelpers::SlotData<void(const QCursor &)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QCursor, 2 },
        }}),
        // Slot '_q_unsetViewportCursor'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'backgroundBrush'
        QtMocHelpers::PropertyData<QBrush>(19, QMetaType::QBrush, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'foregroundBrush'
        QtMocHelpers::PropertyData<QBrush>(20, QMetaType::QBrush, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'interactive'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'sceneRect'
        QtMocHelpers::PropertyData<QRectF>(22, QMetaType::QRectF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'alignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(23, 0x80000000 | 24, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'renderHints'
        QtMocHelpers::PropertyData<QPainter::RenderHints>(25, 0x80000000 | 26, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'dragMode'
        QtMocHelpers::PropertyData<DragMode>(27, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'cacheMode'
        QtMocHelpers::PropertyData<CacheMode>(29, 0x80000000 | 30, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'transformationAnchor'
        QtMocHelpers::PropertyData<ViewportAnchor>(31, 0x80000000 | 32, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'resizeAnchor'
        QtMocHelpers::PropertyData<ViewportAnchor>(33, 0x80000000 | 32, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'viewportUpdateMode'
        QtMocHelpers::PropertyData<ViewportUpdateMode>(34, 0x80000000 | 35, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'rubberBandSelectionMode'
        QtMocHelpers::PropertyData<Qt::ItemSelectionMode>(36, 0x80000000 | 37, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'optimizationFlags'
        QtMocHelpers::PropertyData<OptimizationFlags>(38, 0x80000000 | 39, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ViewportAnchor'
        QtMocHelpers::EnumData<ViewportAnchor>(32, 32, QMC::EnumFlags{}).add({
            {   40, ViewportAnchor::NoAnchor },
            {   41, ViewportAnchor::AnchorViewCenter },
            {   42, ViewportAnchor::AnchorUnderMouse },
        }),
        // enum 'CacheMode'
        QtMocHelpers::EnumData<CacheMode>(30, 43, QMC::EnumFlags{}).add({
            {   44, CacheModeFlag::CacheNone },
            {   45, CacheModeFlag::CacheBackground },
        }),
        // enum 'DragMode'
        QtMocHelpers::EnumData<DragMode>(28, 28, QMC::EnumFlags{}).add({
            {   46, DragMode::NoDrag },
            {   47, DragMode::ScrollHandDrag },
            {   48, DragMode::RubberBandDrag },
        }),
        // enum 'ViewportUpdateMode'
        QtMocHelpers::EnumData<ViewportUpdateMode>(35, 35, QMC::EnumFlags{}).add({
            {   49, ViewportUpdateMode::FullViewportUpdate },
            {   50, ViewportUpdateMode::MinimalViewportUpdate },
            {   51, ViewportUpdateMode::SmartViewportUpdate },
            {   52, ViewportUpdateMode::NoViewportUpdate },
            {   53, ViewportUpdateMode::BoundingRectViewportUpdate },
        }),
        // enum 'OptimizationFlags'
        QtMocHelpers::EnumData<OptimizationFlags>(39, 54, QMC::EnumFlags{}).add({
            {   55, OptimizationFlag::DontSavePainterState },
            {   56, OptimizationFlag::DontAdjustForAntialiasing },
            {   57, OptimizationFlag::IndirectPainting },
        }),
    };
    return QtMocHelpers::metaObjectData<QGraphicsView, qt_meta_tag_ZN13QGraphicsViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN13QGraphicsViewE[] = {
    QMetaObject::SuperData::link<QPainter::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject QGraphicsView::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractScrollArea::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QGraphicsViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QGraphicsViewE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN13QGraphicsViewE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QGraphicsViewE_t>.metaTypes,
    nullptr
} };

void QGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->rubberBandChanged((*reinterpret_cast< std::add_pointer_t<QRect>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[3]))); break;
        case 1: _t->updateScene((*reinterpret_cast< std::add_pointer_t<QList<QRectF>>>(_a[1]))); break;
        case 2: _t->invalidateScene((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsScene::SceneLayers>>(_a[2]))); break;
        case 3: _t->invalidateScene((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 4: _t->invalidateScene(); break;
        case 5: _t->updateSceneRect((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 6: _t->setupViewport((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 7: _t->d_func()->_q_setViewportCursor((*reinterpret_cast< std::add_pointer_t<QCursor>>(_a[1]))); break;
        case 8: _t->d_func()->_q_unsetViewportCursor(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QRectF> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsView::*)(QRect , QPointF , QPointF )>(_a, &QGraphicsView::rubberBandChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QBrush*>(_v) = _t->backgroundBrush(); break;
        case 1: *reinterpret_cast<QBrush*>(_v) = _t->foregroundBrush(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isInteractive(); break;
        case 3: *reinterpret_cast<QRectF*>(_v) = _t->sceneRect(); break;
        case 4: *reinterpret_cast<Qt::Alignment*>(_v) = _t->alignment(); break;
        case 5: QtMocHelpers::assignFlags<QPainter::RenderHints>(_v, _t->renderHints()); break;
        case 6: *reinterpret_cast<DragMode*>(_v) = _t->dragMode(); break;
        case 7: QtMocHelpers::assignFlags<CacheMode>(_v, _t->cacheMode()); break;
        case 8: *reinterpret_cast<ViewportAnchor*>(_v) = _t->transformationAnchor(); break;
        case 9: *reinterpret_cast<ViewportAnchor*>(_v) = _t->resizeAnchor(); break;
        case 10: *reinterpret_cast<ViewportUpdateMode*>(_v) = _t->viewportUpdateMode(); break;
        case 11: *reinterpret_cast<Qt::ItemSelectionMode*>(_v) = _t->rubberBandSelectionMode(); break;
        case 12: QtMocHelpers::assignFlags<OptimizationFlags>(_v, _t->optimizationFlags()); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBackgroundBrush(*reinterpret_cast<QBrush*>(_v)); break;
        case 1: _t->setForegroundBrush(*reinterpret_cast<QBrush*>(_v)); break;
        case 2: _t->setInteractive(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setSceneRect(*reinterpret_cast<QRectF*>(_v)); break;
        case 4: _t->setAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        case 5: _t->setRenderHints(*reinterpret_cast<QPainter::RenderHints*>(_v)); break;
        case 6: _t->setDragMode(*reinterpret_cast<DragMode*>(_v)); break;
        case 7: _t->setCacheMode(*reinterpret_cast<CacheMode*>(_v)); break;
        case 8: _t->setTransformationAnchor(*reinterpret_cast<ViewportAnchor*>(_v)); break;
        case 9: _t->setResizeAnchor(*reinterpret_cast<ViewportAnchor*>(_v)); break;
        case 10: _t->setViewportUpdateMode(*reinterpret_cast<ViewportUpdateMode*>(_v)); break;
        case 11: _t->setRubberBandSelectionMode(*reinterpret_cast<Qt::ItemSelectionMode*>(_v)); break;
        case 12: _t->setOptimizationFlags(*reinterpret_cast<OptimizationFlags*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QGraphicsViewE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractScrollArea::qt_metacast(_clname);
}

int QGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsView::rubberBandChanged(QRect _t1, QPointF _t2, QPointF _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
