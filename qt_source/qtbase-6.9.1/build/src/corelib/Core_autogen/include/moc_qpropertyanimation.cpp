/****************************************************************************
** Meta object code from reading C++ file 'qpropertyanimation.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/animation/qpropertyanimation.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpropertyanimation.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QPropertyAnimationE_t {};
} // unnamed namespace

template <> constexpr inline auto QPropertyAnimation::qt_create_metaobjectdata<qt_meta_tag_ZN18QPropertyAnimationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPropertyAnimation",
        "propertyName",
        "targetObject"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'propertyName'
        QtMocHelpers::PropertyData<QByteArray>(1, QMetaType::QByteArray, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
        // property 'targetObject'
        QtMocHelpers::PropertyData<QObject*>(2, QMetaType::QObjectStar, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Bindable),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPropertyAnimation, qt_meta_tag_ZN18QPropertyAnimationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPropertyAnimation::staticMetaObject = { {
    QMetaObject::SuperData::link<QVariantAnimation::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QPropertyAnimationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QPropertyAnimationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QPropertyAnimationE_t>.metaTypes,
    nullptr
} };

void QPropertyAnimation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPropertyAnimation *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QByteArray*>(_v) = _t->propertyName(); break;
        case 1: *reinterpret_cast<QObject**>(_v) = _t->targetObject(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPropertyName(*reinterpret_cast<QByteArray*>(_v)); break;
        case 1: _t->setTargetObject(*reinterpret_cast<QObject**>(_v)); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindablePropertyName(); break;
        case 1: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableTargetObject(); break;
        default: break;
        }
    }
}

const QMetaObject *QPropertyAnimation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPropertyAnimation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QPropertyAnimationE_t>.strings))
        return static_cast<void*>(this);
    return QVariantAnimation::qt_metacast(_clname);
}

int QPropertyAnimation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVariantAnimation::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
