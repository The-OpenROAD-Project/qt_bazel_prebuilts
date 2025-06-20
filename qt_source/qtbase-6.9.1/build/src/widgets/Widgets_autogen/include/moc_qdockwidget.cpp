/****************************************************************************
** Meta object code from reading C++ file 'qdockwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qdockwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdockwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QDockWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QDockWidget::qt_create_metaobjectdata<qt_meta_tag_ZN11QDockWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDockWidget",
        "featuresChanged",
        "",
        "QDockWidget::DockWidgetFeatures",
        "features",
        "topLevelChanged",
        "topLevel",
        "allowedAreasChanged",
        "Qt::DockWidgetAreas",
        "allowedAreas",
        "visibilityChanged",
        "visible",
        "dockLocationChanged",
        "Qt::DockWidgetArea",
        "area",
        "floating",
        "DockWidgetFeatures",
        "windowTitle",
        "dockLocation",
        "DockWidgetFeature",
        "DockWidgetClosable",
        "DockWidgetMovable",
        "DockWidgetFloatable",
        "DockWidgetVerticalTitleBar",
        "DockWidgetFeatureMask",
        "NoDockWidgetFeatures",
        "Reserved"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'featuresChanged'
        QtMocHelpers::SignalData<void(QDockWidget::DockWidgetFeatures)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'topLevelChanged'
        QtMocHelpers::SignalData<void(bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 6 },
        }}),
        // Signal 'allowedAreasChanged'
        QtMocHelpers::SignalData<void(Qt::DockWidgetAreas)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
        // Signal 'visibilityChanged'
        QtMocHelpers::SignalData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 11 },
        }}),
        // Signal 'dockLocationChanged'
        QtMocHelpers::SignalData<void(Qt::DockWidgetArea)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'floating'
        QtMocHelpers::PropertyData<bool>(15, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'features'
        QtMocHelpers::PropertyData<DockWidgetFeatures>(4, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'allowedAreas'
        QtMocHelpers::PropertyData<Qt::DockWidgetAreas>(9, 0x80000000 | 8, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 2),
        // property 'windowTitle'
        QtMocHelpers::PropertyData<QString>(17, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'dockLocation'
        QtMocHelpers::PropertyData<Qt::DockWidgetArea>(18, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 4),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'DockWidgetFeatures'
        QtMocHelpers::EnumData<DockWidgetFeatures>(16, 19, QMC::EnumFlags{}).add({
            {   20, DockWidgetFeature::DockWidgetClosable },
            {   21, DockWidgetFeature::DockWidgetMovable },
            {   22, DockWidgetFeature::DockWidgetFloatable },
            {   23, DockWidgetFeature::DockWidgetVerticalTitleBar },
            {   24, DockWidgetFeature::DockWidgetFeatureMask },
            {   25, DockWidgetFeature::NoDockWidgetFeatures },
            {   26, DockWidgetFeature::Reserved },
        }),
    };
    return QtMocHelpers::metaObjectData<QDockWidget, qt_meta_tag_ZN11QDockWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDockWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QDockWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QDockWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QDockWidgetE_t>.metaTypes,
    nullptr
} };

void QDockWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDockWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->featuresChanged((*reinterpret_cast< std::add_pointer_t<QDockWidget::DockWidgetFeatures>>(_a[1]))); break;
        case 1: _t->topLevelChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->allowedAreasChanged((*reinterpret_cast< std::add_pointer_t<Qt::DockWidgetAreas>>(_a[1]))); break;
        case 3: _t->visibilityChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->dockLocationChanged((*reinterpret_cast< std::add_pointer_t<Qt::DockWidgetArea>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDockWidget::*)(QDockWidget::DockWidgetFeatures )>(_a, &QDockWidget::featuresChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDockWidget::*)(bool )>(_a, &QDockWidget::topLevelChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDockWidget::*)(Qt::DockWidgetAreas )>(_a, &QDockWidget::allowedAreasChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDockWidget::*)(bool )>(_a, &QDockWidget::visibilityChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDockWidget::*)(Qt::DockWidgetArea )>(_a, &QDockWidget::dockLocationChanged, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isFloating(); break;
        case 1: QtMocHelpers::assignFlags<DockWidgetFeatures>(_v, _t->features()); break;
        case 2: *reinterpret_cast<Qt::DockWidgetAreas*>(_v) = _t->allowedAreas(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->windowTitle(); break;
        case 4: *reinterpret_cast<Qt::DockWidgetArea*>(_v) = _t->dockLocation(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFloating(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setFeatures(*reinterpret_cast<DockWidgetFeatures*>(_v)); break;
        case 2: _t->setAllowedAreas(*reinterpret_cast<Qt::DockWidgetAreas*>(_v)); break;
        case 3: _t->setWindowTitle(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setDockLocation(*reinterpret_cast<Qt::DockWidgetArea*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QDockWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDockWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QDockWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QDockWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QDockWidget::featuresChanged(QDockWidget::DockWidgetFeatures _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QDockWidget::topLevelChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QDockWidget::allowedAreasChanged(Qt::DockWidgetAreas _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QDockWidget::visibilityChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QDockWidget::dockLocationChanged(Qt::DockWidgetArea _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
