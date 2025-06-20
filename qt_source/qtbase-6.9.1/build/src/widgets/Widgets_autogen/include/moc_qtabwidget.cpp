/****************************************************************************
** Meta object code from reading C++ file 'qtabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qtabwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtabwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QTabWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QTabWidget::qt_create_metaobjectdata<qt_meta_tag_ZN10QTabWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTabWidget",
        "currentChanged",
        "",
        "index",
        "tabCloseRequested",
        "tabBarClicked",
        "tabBarDoubleClicked",
        "setCurrentIndex",
        "setCurrentWidget",
        "QWidget*",
        "widget",
        "tabPosition",
        "TabPosition",
        "tabShape",
        "TabShape",
        "currentIndex",
        "count",
        "iconSize",
        "elideMode",
        "Qt::TextElideMode",
        "usesScrollButtons",
        "documentMode",
        "tabsClosable",
        "movable",
        "tabBarAutoHide",
        "North",
        "South",
        "West",
        "East",
        "Rounded",
        "Triangular"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'currentChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'tabCloseRequested'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'tabBarClicked'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'tabBarDoubleClicked'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setCurrentIndex'
        QtMocHelpers::SlotData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setCurrentWidget'
        QtMocHelpers::SlotData<void(QWidget *)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'tabPosition'
        QtMocHelpers::PropertyData<TabPosition>(11, 0x80000000 | 12, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'tabShape'
        QtMocHelpers::PropertyData<TabShape>(13, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'currentIndex'
        QtMocHelpers::PropertyData<int>(15, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'count'
        QtMocHelpers::PropertyData<int>(16, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'iconSize'
        QtMocHelpers::PropertyData<QSize>(17, QMetaType::QSize, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'elideMode'
        QtMocHelpers::PropertyData<Qt::TextElideMode>(18, 0x80000000 | 19, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'usesScrollButtons'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'documentMode'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tabsClosable'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'movable'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tabBarAutoHide'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'TabPosition'
        QtMocHelpers::EnumData<TabPosition>(12, 12, QMC::EnumFlags{}).add({
            {   25, TabPosition::North },
            {   26, TabPosition::South },
            {   27, TabPosition::West },
            {   28, TabPosition::East },
        }),
        // enum 'TabShape'
        QtMocHelpers::EnumData<TabShape>(14, 14, QMC::EnumFlags{}).add({
            {   29, TabShape::Rounded },
            {   30, TabShape::Triangular },
        }),
    };
    return QtMocHelpers::metaObjectData<QTabWidget, qt_meta_tag_ZN10QTabWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTabWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QTabWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QTabWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QTabWidgetE_t>.metaTypes,
    nullptr
} };

void QTabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTabWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->tabCloseRequested((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->tabBarClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->tabBarDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setCurrentIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->setCurrentWidget((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTabWidget::*)(int )>(_a, &QTabWidget::currentChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTabWidget::*)(int )>(_a, &QTabWidget::tabCloseRequested, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTabWidget::*)(int )>(_a, &QTabWidget::tabBarClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTabWidget::*)(int )>(_a, &QTabWidget::tabBarDoubleClicked, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<TabPosition*>(_v) = _t->tabPosition(); break;
        case 1: *reinterpret_cast<TabShape*>(_v) = _t->tabShape(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->currentIndex(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->count(); break;
        case 4: *reinterpret_cast<QSize*>(_v) = _t->iconSize(); break;
        case 5: *reinterpret_cast<Qt::TextElideMode*>(_v) = _t->elideMode(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->usesScrollButtons(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->documentMode(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->tabsClosable(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->isMovable(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->tabBarAutoHide(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTabPosition(*reinterpret_cast<TabPosition*>(_v)); break;
        case 1: _t->setTabShape(*reinterpret_cast<TabShape*>(_v)); break;
        case 2: _t->setCurrentIndex(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setIconSize(*reinterpret_cast<QSize*>(_v)); break;
        case 5: _t->setElideMode(*reinterpret_cast<Qt::TextElideMode*>(_v)); break;
        case 6: _t->setUsesScrollButtons(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setDocumentMode(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setTabsClosable(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setMovable(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setTabBarAutoHide(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QTabWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QTabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QTabWidget::currentChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QTabWidget::tabCloseRequested(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QTabWidget::tabBarClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QTabWidget::tabBarDoubleClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
