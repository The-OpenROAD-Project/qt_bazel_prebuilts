/****************************************************************************
** Meta object code from reading C++ file 'qgraphicsscene.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/graphicsview/qgraphicsscene.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgraphicsscene.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14QGraphicsSceneE_t {};
} // unnamed namespace

template <> constexpr inline auto QGraphicsScene::qt_create_metaobjectdata<qt_meta_tag_ZN14QGraphicsSceneE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGraphicsScene",
        "changed",
        "",
        "QList<QRectF>",
        "region",
        "sceneRectChanged",
        "rect",
        "selectionChanged",
        "focusItemChanged",
        "QGraphicsItem*",
        "newFocus",
        "oldFocus",
        "Qt::FocusReason",
        "reason",
        "update",
        "invalidate",
        "SceneLayers",
        "layers",
        "advance",
        "clearSelection",
        "clear",
        "focusNextPrevChild",
        "next",
        "_q_emitUpdated",
        "_q_polishItems",
        "_q_processDirtyItems",
        "_q_updateScenePosDescendants",
        "backgroundBrush",
        "foregroundBrush",
        "itemIndexMethod",
        "ItemIndexMethod",
        "sceneRect",
        "bspTreeDepth",
        "palette",
        "font",
        "stickyFocus",
        "minimumRenderSize",
        "focusOnTouch",
        "BspTreeIndex",
        "NoIndex"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'changed'
        QtMocHelpers::SignalData<void(const QList<QRectF> &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'sceneRectChanged'
        QtMocHelpers::SignalData<void(const QRectF &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 6 },
        }}),
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusItemChanged'
        QtMocHelpers::SignalData<void(QGraphicsItem *, QGraphicsItem *, Qt::FocusReason)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 }, { 0x80000000 | 9, 11 }, { 0x80000000 | 12, 13 },
        }}),
        // Slot 'update'
        QtMocHelpers::SlotData<void(const QRectF &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 6 },
        }}),
        // Slot 'update'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'invalidate'
        QtMocHelpers::SlotData<void(const QRectF &, SceneLayers)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 6 }, { 0x80000000 | 16, 17 },
        }}),
        // Slot 'invalidate'
        QtMocHelpers::SlotData<void(const QRectF &)>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void, {{
            { QMetaType::QRectF, 6 },
        }}),
        // Slot 'invalidate'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'advance'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clearSelection'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'clear'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'focusNextPrevChild'
        QtMocHelpers::SlotData<bool(bool)>(21, 2, QMC::AccessProtected, QMetaType::Bool, {{
            { QMetaType::Bool, 22 },
        }}),
        // Slot '_q_emitUpdated'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_polishItems'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_processDirtyItems'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_updateScenePosDescendants'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'backgroundBrush'
        QtMocHelpers::PropertyData<QBrush>(27, QMetaType::QBrush, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'foregroundBrush'
        QtMocHelpers::PropertyData<QBrush>(28, QMetaType::QBrush, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'itemIndexMethod'
        QtMocHelpers::PropertyData<ItemIndexMethod>(29, 0x80000000 | 30, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'sceneRect'
        QtMocHelpers::PropertyData<QRectF>(31, QMetaType::QRectF, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'bspTreeDepth'
        QtMocHelpers::PropertyData<int>(32, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'palette'
        QtMocHelpers::PropertyData<QPalette>(33, QMetaType::QPalette, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'font'
        QtMocHelpers::PropertyData<QFont>(34, QMetaType::QFont, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'stickyFocus'
        QtMocHelpers::PropertyData<bool>(35, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'minimumRenderSize'
        QtMocHelpers::PropertyData<qreal>(36, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'focusOnTouch'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ItemIndexMethod'
        QtMocHelpers::EnumData<ItemIndexMethod>(30, 30, QMC::EnumFlags{}).add({
            {   38, ItemIndexMethod::BspTreeIndex },
            {   39, ItemIndexMethod::NoIndex },
        }),
    };
    return QtMocHelpers::metaObjectData<QGraphicsScene, qt_meta_tag_ZN14QGraphicsSceneE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGraphicsScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QGraphicsSceneE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QGraphicsSceneE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QGraphicsSceneE_t>.metaTypes,
    nullptr
} };

void QGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGraphicsScene *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->changed((*reinterpret_cast< std::add_pointer_t<QList<QRectF>>>(_a[1]))); break;
        case 1: _t->sceneRectChanged((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 2: _t->selectionChanged(); break;
        case 3: _t->focusItemChanged((*reinterpret_cast< std::add_pointer_t<QGraphicsItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QGraphicsItem*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<Qt::FocusReason>>(_a[3]))); break;
        case 4: _t->update((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 5: _t->update(); break;
        case 6: _t->invalidate((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<SceneLayers>>(_a[2]))); break;
        case 7: _t->invalidate((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1]))); break;
        case 8: _t->invalidate(); break;
        case 9: _t->advance(); break;
        case 10: _t->clearSelection(); break;
        case 11: _t->clear(); break;
        case 12: { bool _r = _t->focusNextPrevChild((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->d_func()->_q_emitUpdated(); break;
        case 14: _t->d_func()->_q_polishItems(); break;
        case 15: _t->d_func()->_q_processDirtyItems(); break;
        case 16: _t->d_func()->_q_updateScenePosDescendants(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QRectF> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScene::*)(const QList<QRectF> & )>(_a, &QGraphicsScene::changed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScene::*)(const QRectF & )>(_a, &QGraphicsScene::sceneRectChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScene::*)()>(_a, &QGraphicsScene::selectionChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGraphicsScene::*)(QGraphicsItem * , QGraphicsItem * , Qt::FocusReason )>(_a, &QGraphicsScene::focusItemChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QBrush*>(_v) = _t->backgroundBrush(); break;
        case 1: *reinterpret_cast<QBrush*>(_v) = _t->foregroundBrush(); break;
        case 2: *reinterpret_cast<ItemIndexMethod*>(_v) = _t->itemIndexMethod(); break;
        case 3: *reinterpret_cast<QRectF*>(_v) = _t->sceneRect(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->bspTreeDepth(); break;
        case 5: *reinterpret_cast<QPalette*>(_v) = _t->palette(); break;
        case 6: *reinterpret_cast<QFont*>(_v) = _t->font(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->stickyFocus(); break;
        case 8: *reinterpret_cast<qreal*>(_v) = _t->minimumRenderSize(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->focusOnTouch(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBackgroundBrush(*reinterpret_cast<QBrush*>(_v)); break;
        case 1: _t->setForegroundBrush(*reinterpret_cast<QBrush*>(_v)); break;
        case 2: _t->setItemIndexMethod(*reinterpret_cast<ItemIndexMethod*>(_v)); break;
        case 3: _t->setSceneRect(*reinterpret_cast<QRectF*>(_v)); break;
        case 4: _t->setBspTreeDepth(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setPalette(*reinterpret_cast<QPalette*>(_v)); break;
        case 6: _t->setFont(*reinterpret_cast<QFont*>(_v)); break;
        case 7: _t->setStickyFocus(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setMinimumRenderSize(*reinterpret_cast<qreal*>(_v)); break;
        case 9: _t->setFocusOnTouch(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QGraphicsSceneE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QGraphicsScene::changed(const QList<QRectF> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QGraphicsScene::sceneRectChanged(const QRectF & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QGraphicsScene::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QGraphicsScene::focusItemChanged(QGraphicsItem * _t1, QGraphicsItem * _t2, Qt::FocusReason _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2, _t3);
}
QT_WARNING_POP
