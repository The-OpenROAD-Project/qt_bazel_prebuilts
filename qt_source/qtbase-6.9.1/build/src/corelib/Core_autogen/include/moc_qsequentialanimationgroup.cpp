/****************************************************************************
** Meta object code from reading C++ file 'qsequentialanimationgroup.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/animation/qsequentialanimationgroup.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QProperty>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsequentialanimationgroup.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN25QSequentialAnimationGroupE_t {};
} // unnamed namespace

template <> constexpr inline auto QSequentialAnimationGroup::qt_create_metaobjectdata<qt_meta_tag_ZN25QSequentialAnimationGroupE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSequentialAnimationGroup",
        "currentAnimationChanged",
        "",
        "QAbstractAnimation*",
        "current",
        "_q_uncontrolledAnimationFinished",
        "currentAnimation"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'currentAnimationChanged'
        QtMocHelpers::SignalData<void(QAbstractAnimation *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot '_q_uncontrolledAnimationFinished'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'currentAnimation'
        QtMocHelpers::PropertyData<QAbstractAnimation*>(6, 0x80000000 | 3, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Bindable, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSequentialAnimationGroup, qt_meta_tag_ZN25QSequentialAnimationGroupE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSequentialAnimationGroup::staticMetaObject = { {
    QMetaObject::SuperData::link<QAnimationGroup::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QSequentialAnimationGroupE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QSequentialAnimationGroupE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN25QSequentialAnimationGroupE_t>.metaTypes,
    nullptr
} };

void QSequentialAnimationGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSequentialAnimationGroup *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentAnimationChanged((*reinterpret_cast< std::add_pointer_t<QAbstractAnimation*>>(_a[1]))); break;
        case 1: _t->d_func()->_q_uncontrolledAnimationFinished(); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractAnimation* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QSequentialAnimationGroup::*)(QAbstractAnimation * )>(_a, &QSequentialAnimationGroup::currentAnimationChanged, 0))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractAnimation* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QAbstractAnimation**>(_v) = _t->currentAnimation(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::BindableProperty) {
        switch (_id) {
        case 0: *static_cast<QUntypedBindable *>(_a[0]) = _t->bindableCurrentAnimation(); break;
        default: break;
        }
    }
}

const QMetaObject *QSequentialAnimationGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSequentialAnimationGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QSequentialAnimationGroupE_t>.strings))
        return static_cast<void*>(this);
    return QAnimationGroup::qt_metacast(_clname);
}

int QSequentialAnimationGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAnimationGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QSequentialAnimationGroup::currentAnimationChanged(QAbstractAnimation * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
