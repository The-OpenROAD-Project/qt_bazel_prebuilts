/****************************************************************************
** Meta object code from reading C++ file 'qprintpreviewwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/printsupport/widgets/qprintpreviewwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qprintpreviewwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QPrintPreviewWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QPrintPreviewWidget::qt_create_metaobjectdata<qt_meta_tag_ZN19QPrintPreviewWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPrintPreviewWidget",
        "paintRequested",
        "",
        "QPrinter*",
        "printer",
        "previewChanged",
        "print",
        "zoomIn",
        "zoom",
        "zoomOut",
        "setZoomFactor",
        "zoomFactor",
        "setOrientation",
        "QPageLayout::Orientation",
        "orientation",
        "setViewMode",
        "ViewMode",
        "viewMode",
        "setZoomMode",
        "ZoomMode",
        "zoomMode",
        "setCurrentPage",
        "pageNumber",
        "fitToWidth",
        "fitInView",
        "setLandscapeOrientation",
        "setPortraitOrientation",
        "setSinglePageViewMode",
        "setFacingPagesViewMode",
        "setAllPagesViewMode",
        "updatePreview",
        "_q_fit",
        "_q_updateCurrentPage"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'paintRequested'
        QtMocHelpers::SignalData<void(QPrinter *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'previewChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'print'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'zoomIn'
        QtMocHelpers::SlotData<void(qreal)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 8 },
        }}),
        // Slot 'zoomIn'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'zoomOut'
        QtMocHelpers::SlotData<void(qreal)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 8 },
        }}),
        // Slot 'zoomOut'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'setZoomFactor'
        QtMocHelpers::SlotData<void(qreal)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QReal, 11 },
        }}),
        // Slot 'setOrientation'
        QtMocHelpers::SlotData<void(QPageLayout::Orientation)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Slot 'setViewMode'
        QtMocHelpers::SlotData<void(ViewMode)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 16, 17 },
        }}),
        // Slot 'setZoomMode'
        QtMocHelpers::SlotData<void(ZoomMode)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 19, 20 },
        }}),
        // Slot 'setCurrentPage'
        QtMocHelpers::SlotData<void(int)>(21, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 22 },
        }}),
        // Slot 'fitToWidth'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'fitInView'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setLandscapeOrientation'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setPortraitOrientation'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSinglePageViewMode'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setFacingPagesViewMode'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setAllPagesViewMode'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'updatePreview'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_fit'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_updateCurrentPage'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPrintPreviewWidget, qt_meta_tag_ZN19QPrintPreviewWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPrintPreviewWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QPrintPreviewWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QPrintPreviewWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QPrintPreviewWidgetE_t>.metaTypes,
    nullptr
} };

void QPrintPreviewWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPrintPreviewWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->paintRequested((*reinterpret_cast< std::add_pointer_t<QPrinter*>>(_a[1]))); break;
        case 1: _t->previewChanged(); break;
        case 2: _t->print(); break;
        case 3: _t->zoomIn((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 4: _t->zoomIn(); break;
        case 5: _t->zoomOut((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 6: _t->zoomOut(); break;
        case 7: _t->setZoomFactor((*reinterpret_cast< std::add_pointer_t<qreal>>(_a[1]))); break;
        case 8: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<QPageLayout::Orientation>>(_a[1]))); break;
        case 9: _t->setViewMode((*reinterpret_cast< std::add_pointer_t<ViewMode>>(_a[1]))); break;
        case 10: _t->setZoomMode((*reinterpret_cast< std::add_pointer_t<ZoomMode>>(_a[1]))); break;
        case 11: _t->setCurrentPage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->fitToWidth(); break;
        case 13: _t->fitInView(); break;
        case 14: _t->setLandscapeOrientation(); break;
        case 15: _t->setPortraitOrientation(); break;
        case 16: _t->setSinglePageViewMode(); break;
        case 17: _t->setFacingPagesViewMode(); break;
        case 18: _t->setAllPagesViewMode(); break;
        case 19: _t->updatePreview(); break;
        case 20: _t->d_func()->_q_fit(); break;
        case 21: _t->d_func()->_q_updateCurrentPage(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPageLayout::Orientation >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPrintPreviewWidget::*)(QPrinter * )>(_a, &QPrintPreviewWidget::paintRequested, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPrintPreviewWidget::*)()>(_a, &QPrintPreviewWidget::previewChanged, 1))
            return;
    }
}

const QMetaObject *QPrintPreviewWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPrintPreviewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QPrintPreviewWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QPrintPreviewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void QPrintPreviewWidget::paintRequested(QPrinter * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QPrintPreviewWidget::previewChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
