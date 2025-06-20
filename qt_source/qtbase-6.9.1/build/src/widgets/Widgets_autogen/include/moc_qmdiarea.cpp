/****************************************************************************
** Meta object code from reading C++ file 'qmdiarea.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qmdiarea.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmdiarea.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QMdiAreaE_t {};
} // unnamed namespace

template <> constexpr inline auto QMdiArea::qt_create_metaobjectdata<qt_meta_tag_ZN8QMdiAreaE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QMdiArea",
        "subWindowActivated",
        "",
        "QMdiSubWindow*",
        "setActiveSubWindow",
        "window",
        "tileSubWindows",
        "cascadeSubWindows",
        "closeActiveSubWindow",
        "closeAllSubWindows",
        "activateNextSubWindow",
        "activatePreviousSubWindow",
        "setupViewport",
        "QWidget*",
        "viewport",
        "_q_deactivateAllWindows",
        "_q_processWindowStateChanged",
        "Qt::WindowStates",
        "_q_currentTabChanged",
        "_q_closeTab",
        "_q_moveTab",
        "background",
        "activationOrder",
        "WindowOrder",
        "viewMode",
        "ViewMode",
        "documentMode",
        "tabsClosable",
        "tabsMovable",
        "tabShape",
        "QTabWidget::TabShape",
        "tabPosition",
        "QTabWidget::TabPosition",
        "CreationOrder",
        "StackingOrder",
        "ActivationHistoryOrder",
        "SubWindowView",
        "TabbedView"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'subWindowActivated'
        QtMocHelpers::SignalData<void(QMdiSubWindow *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'setActiveSubWindow'
        QtMocHelpers::SlotData<void(QMdiSubWindow *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 5 },
        }}),
        // Slot 'tileSubWindows'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'cascadeSubWindows'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'closeActiveSubWindow'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'closeAllSubWindows'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'activateNextSubWindow'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'activatePreviousSubWindow'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setupViewport'
        QtMocHelpers::SlotData<void(QWidget *)>(12, 2, QMC::AccessProtected, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Slot '_q_deactivateAllWindows'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_processWindowStateChanged'
        QtMocHelpers::SlotData<void(Qt::WindowStates, Qt::WindowStates)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 17, 2 }, { 0x80000000 | 17, 2 },
        }}),
        // Slot '_q_currentTabChanged'
        QtMocHelpers::SlotData<void(int)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot '_q_closeTab'
        QtMocHelpers::SlotData<void(int)>(19, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot '_q_moveTab'
        QtMocHelpers::SlotData<void(int, int)>(20, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::Int, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'background'
        QtMocHelpers::PropertyData<QBrush>(21, QMetaType::QBrush, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'activationOrder'
        QtMocHelpers::PropertyData<WindowOrder>(22, 0x80000000 | 23, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'viewMode'
        QtMocHelpers::PropertyData<ViewMode>(24, 0x80000000 | 25, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'documentMode'
        QtMocHelpers::PropertyData<bool>(26, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tabsClosable'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tabsMovable'
        QtMocHelpers::PropertyData<bool>(28, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tabShape'
        QtMocHelpers::PropertyData<QTabWidget::TabShape>(29, 0x80000000 | 30, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'tabPosition'
        QtMocHelpers::PropertyData<QTabWidget::TabPosition>(31, 0x80000000 | 32, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'WindowOrder'
        QtMocHelpers::EnumData<WindowOrder>(23, 23, QMC::EnumFlags{}).add({
            {   33, WindowOrder::CreationOrder },
            {   34, WindowOrder::StackingOrder },
            {   35, WindowOrder::ActivationHistoryOrder },
        }),
        // enum 'ViewMode'
        QtMocHelpers::EnumData<ViewMode>(25, 25, QMC::EnumFlags{}).add({
            {   36, ViewMode::SubWindowView },
            {   37, ViewMode::TabbedView },
        }),
    };
    return QtMocHelpers::metaObjectData<QMdiArea, qt_meta_tag_ZN8QMdiAreaE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN8QMdiAreaE[] = {
    QMetaObject::SuperData::link<QTabWidget::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject QMdiArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractScrollArea::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QMdiAreaE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QMdiAreaE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN8QMdiAreaE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QMdiAreaE_t>.metaTypes,
    nullptr
} };

void QMdiArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QMdiArea *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->subWindowActivated((*reinterpret_cast< std::add_pointer_t<QMdiSubWindow*>>(_a[1]))); break;
        case 1: _t->setActiveSubWindow((*reinterpret_cast< std::add_pointer_t<QMdiSubWindow*>>(_a[1]))); break;
        case 2: _t->tileSubWindows(); break;
        case 3: _t->cascadeSubWindows(); break;
        case 4: _t->closeActiveSubWindow(); break;
        case 5: _t->closeAllSubWindows(); break;
        case 6: _t->activateNextSubWindow(); break;
        case 7: _t->activatePreviousSubWindow(); break;
        case 8: _t->setupViewport((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 9: _t->d_func()->_q_deactivateAllWindows(); break;
        case 10: _t->d_func()->_q_processWindowStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::WindowStates>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::WindowStates>>(_a[2]))); break;
        case 11: _t->d_func()->_q_currentTabChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->d_func()->_q_closeTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->d_func()->_q_moveTab((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QMdiArea::*)(QMdiSubWindow * )>(_a, &QMdiArea::subWindowActivated, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QBrush*>(_v) = _t->background(); break;
        case 1: *reinterpret_cast<WindowOrder*>(_v) = _t->activationOrder(); break;
        case 2: *reinterpret_cast<ViewMode*>(_v) = _t->viewMode(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->documentMode(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->tabsClosable(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->tabsMovable(); break;
        case 6: *reinterpret_cast<QTabWidget::TabShape*>(_v) = _t->tabShape(); break;
        case 7: *reinterpret_cast<QTabWidget::TabPosition*>(_v) = _t->tabPosition(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBackground(*reinterpret_cast<QBrush*>(_v)); break;
        case 1: _t->setActivationOrder(*reinterpret_cast<WindowOrder*>(_v)); break;
        case 2: _t->setViewMode(*reinterpret_cast<ViewMode*>(_v)); break;
        case 3: _t->setDocumentMode(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setTabsClosable(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setTabsMovable(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setTabShape(*reinterpret_cast<QTabWidget::TabShape*>(_v)); break;
        case 7: _t->setTabPosition(*reinterpret_cast<QTabWidget::TabPosition*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QMdiArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMdiArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QMdiAreaE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractScrollArea::qt_metacast(_clname);
}

int QMdiArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QMdiArea::subWindowActivated(QMdiSubWindow * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
