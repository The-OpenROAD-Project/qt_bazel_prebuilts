/****************************************************************************
** Meta object code from reading C++ file 'qabstractslider.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qabstractslider.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractslider.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QAbstractSliderE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractSlider::qt_create_metaobjectdata<qt_meta_tag_ZN15QAbstractSliderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractSlider",
        "valueChanged",
        "",
        "value",
        "sliderPressed",
        "sliderMoved",
        "position",
        "sliderReleased",
        "rangeChanged",
        "min",
        "max",
        "actionTriggered",
        "action",
        "setValue",
        "setOrientation",
        "Qt::Orientation",
        "setRange",
        "minimum",
        "maximum",
        "singleStep",
        "pageStep",
        "sliderPosition",
        "tracking",
        "orientation",
        "invertedAppearance",
        "invertedControls",
        "sliderDown"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'valueChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'sliderPressed'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'sliderMoved'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Signal 'sliderReleased'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rangeChanged'
        QtMocHelpers::SignalData<void(int, int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 }, { QMetaType::Int, 10 },
        }}),
        // Signal 'actionTriggered'
        QtMocHelpers::SignalData<void(int)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 12 },
        }}),
        // Slot 'setValue'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot 'setOrientation'
        QtMocHelpers::SlotData<void(Qt::Orientation)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 2 },
        }}),
        // Slot 'setRange'
        QtMocHelpers::SlotData<void(int, int)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 }, { QMetaType::Int, 10 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'minimum'
        QtMocHelpers::PropertyData<int>(17, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maximum'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'singleStep'
        QtMocHelpers::PropertyData<int>(19, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'pageStep'
        QtMocHelpers::PropertyData<int>(20, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'value'
        QtMocHelpers::PropertyData<int>(3, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 0),
        // property 'sliderPosition'
        QtMocHelpers::PropertyData<int>(21, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'tracking'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'orientation'
        QtMocHelpers::PropertyData<Qt::Orientation>(23, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'invertedAppearance'
        QtMocHelpers::PropertyData<bool>(24, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'invertedControls'
        QtMocHelpers::PropertyData<bool>(25, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'sliderDown'
        QtMocHelpers::PropertyData<bool>(26, QMetaType::Bool, QMC::Readable | QMC::Writable | QMC::Scriptable | QMC::Stored | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractSlider, qt_meta_tag_ZN15QAbstractSliderE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractSliderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractSliderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QAbstractSliderE_t>.metaTypes,
    nullptr
} };

void QAbstractSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractSlider *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->sliderPressed(); break;
        case 2: _t->sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->sliderReleased(); break;
        case 4: _t->rangeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->actionTriggered((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<Qt::Orientation>>(_a[1]))); break;
        case 8: _t->setRange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractSlider::*)(int )>(_a, &QAbstractSlider::valueChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSlider::*)()>(_a, &QAbstractSlider::sliderPressed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSlider::*)(int )>(_a, &QAbstractSlider::sliderMoved, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSlider::*)()>(_a, &QAbstractSlider::sliderReleased, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSlider::*)(int , int )>(_a, &QAbstractSlider::rangeChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractSlider::*)(int )>(_a, &QAbstractSlider::actionTriggered, 5))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->minimum(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->maximum(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->singleStep(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->pageStep(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->value(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->sliderPosition(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->hasTracking(); break;
        case 7: *reinterpret_cast<Qt::Orientation*>(_v) = _t->orientation(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->invertedAppearance(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->invertedControls(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->isSliderDown(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMinimum(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setMaximum(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setSingleStep(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setPageStep(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setValue(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setSliderPosition(*reinterpret_cast<int*>(_v)); break;
        case 6: _t->setTracking(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setOrientation(*reinterpret_cast<Qt::Orientation*>(_v)); break;
        case 8: _t->setInvertedAppearance(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setInvertedControls(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setSliderDown(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QAbstractSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractSliderE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QAbstractSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
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
void QAbstractSlider::valueChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QAbstractSlider::sliderPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QAbstractSlider::sliderMoved(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QAbstractSlider::sliderReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QAbstractSlider::rangeChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void QAbstractSlider::actionTriggered(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}
QT_WARNING_POP
