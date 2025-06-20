/****************************************************************************
** Meta object code from reading C++ file 'qtabbar.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qtabbar.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtabbar.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7QTabBarE_t {};
} // unnamed namespace

template <> constexpr inline auto QTabBar::qt_create_metaobjectdata<qt_meta_tag_ZN7QTabBarE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTabBar",
        "currentChanged",
        "",
        "index",
        "tabCloseRequested",
        "tabMoved",
        "from",
        "to",
        "tabBarClicked",
        "tabBarDoubleClicked",
        "setCurrentIndex",
        "shape",
        "Shape",
        "currentIndex",
        "count",
        "drawBase",
        "iconSize",
        "elideMode",
        "Qt::TextElideMode",
        "usesScrollButtons",
        "tabsClosable",
        "selectionBehaviorOnRemove",
        "SelectionBehavior",
        "expanding",
        "movable",
        "documentMode",
        "autoHide",
        "changeCurrentOnDrag",
        "RoundedNorth",
        "RoundedSouth",
        "RoundedWest",
        "RoundedEast",
        "TriangularNorth",
        "TriangularSouth",
        "TriangularWest",
        "TriangularEast"
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
        // Signal 'tabMoved'
        QtMocHelpers::SignalData<void(int, int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 7 },
        }}),
        // Signal 'tabBarClicked'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'tabBarDoubleClicked'
        QtMocHelpers::SignalData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setCurrentIndex'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'shape'
        QtMocHelpers::PropertyData<Shape>(11, 0x80000000 | 12, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'currentIndex'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'count'
        QtMocHelpers::PropertyData<int>(14, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'drawBase'
        QtMocHelpers::PropertyData<bool>(15, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'iconSize'
        QtMocHelpers::PropertyData<QSize>(16, QMetaType::QSize, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'elideMode'
        QtMocHelpers::PropertyData<Qt::TextElideMode>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'usesScrollButtons'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'tabsClosable'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'selectionBehaviorOnRemove'
        QtMocHelpers::PropertyData<SelectionBehavior>(21, 0x80000000 | 22, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'expanding'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'movable'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'documentMode'
        QtMocHelpers::PropertyData<bool>(25, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoHide'
        QtMocHelpers::PropertyData<bool>(26, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'changeCurrentOnDrag'
        QtMocHelpers::PropertyData<bool>(27, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Shape'
        QtMocHelpers::EnumData<Shape>(12, 12, QMC::EnumFlags{}).add({
            {   28, Shape::RoundedNorth },
            {   29, Shape::RoundedSouth },
            {   30, Shape::RoundedWest },
            {   31, Shape::RoundedEast },
            {   32, Shape::TriangularNorth },
            {   33, Shape::TriangularSouth },
            {   34, Shape::TriangularWest },
            {   35, Shape::TriangularEast },
        }),
    };
    return QtMocHelpers::metaObjectData<QTabBar, qt_meta_tag_ZN7QTabBarE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTabBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QTabBarE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QTabBarE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7QTabBarE_t>.metaTypes,
    nullptr
} };

void QTabBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTabBar *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->tabCloseRequested((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->tabMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->tabBarClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->tabBarDoubleClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->setCurrentIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTabBar::*)(int )>(_a, &QTabBar::currentChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTabBar::*)(int )>(_a, &QTabBar::tabCloseRequested, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTabBar::*)(int , int )>(_a, &QTabBar::tabMoved, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTabBar::*)(int )>(_a, &QTabBar::tabBarClicked, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QTabBar::*)(int )>(_a, &QTabBar::tabBarDoubleClicked, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Shape*>(_v) = _t->shape(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->currentIndex(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->count(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->drawBase(); break;
        case 4: *reinterpret_cast<QSize*>(_v) = _t->iconSize(); break;
        case 5: *reinterpret_cast<Qt::TextElideMode*>(_v) = _t->elideMode(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->usesScrollButtons(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->tabsClosable(); break;
        case 8: *reinterpret_cast<SelectionBehavior*>(_v) = _t->selectionBehaviorOnRemove(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->expanding(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->isMovable(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->documentMode(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->autoHide(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->changeCurrentOnDrag(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShape(*reinterpret_cast<Shape*>(_v)); break;
        case 1: _t->setCurrentIndex(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setDrawBase(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setIconSize(*reinterpret_cast<QSize*>(_v)); break;
        case 5: _t->setElideMode(*reinterpret_cast<Qt::TextElideMode*>(_v)); break;
        case 6: _t->setUsesScrollButtons(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setTabsClosable(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setSelectionBehaviorOnRemove(*reinterpret_cast<SelectionBehavior*>(_v)); break;
        case 9: _t->setExpanding(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setMovable(*reinterpret_cast<bool*>(_v)); break;
        case 11: _t->setDocumentMode(*reinterpret_cast<bool*>(_v)); break;
        case 12: _t->setAutoHide(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setChangeCurrentOnDrag(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTabBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTabBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QTabBarE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QTabBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
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
void QTabBar::currentChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QTabBar::tabCloseRequested(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QTabBar::tabMoved(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QTabBar::tabBarClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QTabBar::tabBarDoubleClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
