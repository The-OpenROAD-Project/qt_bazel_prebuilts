/****************************************************************************
** Meta object code from reading C++ file 'qvariantanimation.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/animation/qvariantanimation.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qvariantanimation.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QVariantAnimationE_t {};
} // unnamed namespace

template <> constexpr inline auto QVariantAnimation::qt_create_metaobjectdata<qt_meta_tag_ZN17QVariantAnimationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QVariantAnimation",
        "valueChanged",
        "",
        "QVariant",
        "value",
        "startValue",
        "endValue",
        "currentValue",
        "duration",
        "easingCurve",
        "QEasingCurve"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'valueChanged'
        QtMocHelpers::SignalData<void(const QVariant &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'startValue'
        QtMocHelpers::PropertyData<QVariant>(5, 0x80000000 | 3, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'endValue'
        QtMocHelpers::PropertyData<QVariant>(6, 0x80000000 | 3, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'currentValue'
        QtMocHelpers::PropertyData<QVariant>(7, 0x80000000 | 3, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'duration'
        QtMocHelpers::PropertyData<int>(8, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'easingCurve'
        QtMocHelpers::PropertyData<QEasingCurve>(9, 0x80000000 | 10, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Bindable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QVariantAnimation, qt_meta_tag_ZN17QVariantAnimationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QVariantAnimation::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractAnimation::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QVariantAnimationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QVariantAnimationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QVariantAnimationE_t>.metaTypes,
    nullptr
} };

void QVariantAnimation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QVariantAnimation *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QVariantAnimation::*)(const QVariant & )>(_a, &QVariantAnimation::valueChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QVariant*>(_v) = _t->startValue(); break;
        case 1: *reinterpret_cast<QVariant*>(_v) = _t->endValue(); break;
        case 2: *reinterpret_cast<QVariant*>(_v) = _t->currentValue(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->duration(); break;
        case 4: *reinterpret_cast<QEasingCurve*>(_v) = _t->easingCurve(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setStartValue(*reinterpret_cast<QVariant*>(_v)); break;
        case 1: _t->setEndValue(*reinterpret_cast<QVariant*>(_v)); break;
        case 3: _t->setDuration(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setEasingCurve(*reinterpret_cast<QEasingCurve*>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 3: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableDuration(); break;
        case 4: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableEasingCurve(); break;
        default: break;
        }
    }
}

const QMetaObject *QVariantAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QVariantAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QVariantAnimationE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractAnimation::qt_metacast(_clname);
}

int QVariantAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
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
void QVariantAnimation::valueChanged(const QVariant & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
