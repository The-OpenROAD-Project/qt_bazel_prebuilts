/****************************************************************************
** Meta object code from reading C++ file 'qlistview.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qlistview.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlistview.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QListViewE_t {};
} // unnamed namespace

template <> constexpr inline auto QListView::qt_create_metaobjectdata<qt_meta_tag_ZN9QListViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QListView",
        "indexesMoved",
        "",
        "QModelIndexList",
        "indexes",
        "movement",
        "Movement",
        "flow",
        "Flow",
        "isWrapping",
        "resizeMode",
        "ResizeMode",
        "layoutMode",
        "LayoutMode",
        "spacing",
        "gridSize",
        "viewMode",
        "ViewMode",
        "modelColumn",
        "uniformItemSizes",
        "batchSize",
        "wordWrap",
        "selectionRectVisible",
        "itemAlignment",
        "Qt::Alignment",
        "Static",
        "Free",
        "Snap",
        "LeftToRight",
        "TopToBottom",
        "Fixed",
        "Adjust",
        "SinglePass",
        "Batched",
        "ListMode",
        "IconMode"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'indexesMoved'
        QtMocHelpers::SignalData<void(const QModelIndexList &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'movement'
        QtMocHelpers::PropertyData<Movement>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'flow'
        QtMocHelpers::PropertyData<Flow>(7, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'isWrapping'
        QtMocHelpers::PropertyData<bool>(9, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'resizeMode'
        QtMocHelpers::PropertyData<ResizeMode>(10, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'layoutMode'
        QtMocHelpers::PropertyData<LayoutMode>(12, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'spacing'
        QtMocHelpers::PropertyData<int>(14, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'gridSize'
        QtMocHelpers::PropertyData<QSize>(15, QMetaType::QSize, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'viewMode'
        QtMocHelpers::PropertyData<ViewMode>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'modelColumn'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'uniformItemSizes'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'batchSize'
        QtMocHelpers::PropertyData<int>(20, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'wordWrap'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'selectionRectVisible'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'itemAlignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(23, 0x80000000 | 24, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Movement'
        QtMocHelpers::EnumData<Movement>(6, 6, QMC::EnumFlags{}).add({
            {   25, Movement::Static },
            {   26, Movement::Free },
            {   27, Movement::Snap },
        }),
        // enum 'Flow'
        QtMocHelpers::EnumData<Flow>(8, 8, QMC::EnumFlags{}).add({
            {   28, Flow::LeftToRight },
            {   29, Flow::TopToBottom },
        }),
        // enum 'ResizeMode'
        QtMocHelpers::EnumData<ResizeMode>(11, 11, QMC::EnumFlags{}).add({
            {   30, ResizeMode::Fixed },
            {   31, ResizeMode::Adjust },
        }),
        // enum 'LayoutMode'
        QtMocHelpers::EnumData<LayoutMode>(13, 13, QMC::EnumFlags{}).add({
            {   32, LayoutMode::SinglePass },
            {   33, LayoutMode::Batched },
        }),
        // enum 'ViewMode'
        QtMocHelpers::EnumData<ViewMode>(17, 17, QMC::EnumFlags{}).add({
            {   34, ViewMode::ListMode },
            {   35, ViewMode::IconMode },
        }),
    };
    return QtMocHelpers::metaObjectData<QListView, qt_meta_tag_ZN9QListViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QListView::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemView::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QListViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QListViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QListViewE_t>.metaTypes,
    nullptr
} };

void QListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QListView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->indexesMoved((*reinterpret_cast< std::add_pointer_t<QModelIndexList>>(_a[1]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QModelIndexList >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QListView::*)(const QModelIndexList & )>(_a, &QListView::indexesMoved, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Movement*>(_v) = _t->movement(); break;
        case 1: *reinterpret_cast<Flow*>(_v) = _t->flow(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isWrapping(); break;
        case 3: *reinterpret_cast<ResizeMode*>(_v) = _t->resizeMode(); break;
        case 4: *reinterpret_cast<LayoutMode*>(_v) = _t->layoutMode(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->spacing(); break;
        case 6: *reinterpret_cast<QSize*>(_v) = _t->gridSize(); break;
        case 7: *reinterpret_cast<ViewMode*>(_v) = _t->viewMode(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->modelColumn(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->uniformItemSizes(); break;
        case 10: *reinterpret_cast<int*>(_v) = _t->batchSize(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->wordWrap(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->isSelectionRectVisible(); break;
        case 13: *reinterpret_cast<Qt::Alignment*>(_v) = _t->itemAlignment(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMovement(*reinterpret_cast<Movement*>(_v)); break;
        case 1: _t->setFlow(*reinterpret_cast<Flow*>(_v)); break;
        case 2: _t->setWrapping(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setResizeMode(*reinterpret_cast<ResizeMode*>(_v)); break;
        case 4: _t->setLayoutMode(*reinterpret_cast<LayoutMode*>(_v)); break;
        case 5: _t->setSpacing(*reinterpret_cast<int*>(_v)); break;
        case 6: _t->setGridSize(*reinterpret_cast<QSize*>(_v)); break;
        case 7: _t->setViewMode(*reinterpret_cast<ViewMode*>(_v)); break;
        case 8: _t->setModelColumn(*reinterpret_cast<int*>(_v)); break;
        case 9: _t->setUniformItemSizes(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setBatchSize(*reinterpret_cast<int*>(_v)); break;
        case 11: _t->setWordWrap(*reinterpret_cast<bool*>(_v)); break;
        case 12: _t->setSelectionRectVisible(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setItemAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QListView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QListViewE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractItemView::qt_metacast(_clname);
}

int QListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QListView::indexesMoved(const QModelIndexList & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
