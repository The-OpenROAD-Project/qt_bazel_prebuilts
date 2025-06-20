/****************************************************************************
** Meta object code from reading C++ file 'qpointingdevice.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qpointingdevice.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpointingdevice.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN23QPointingDeviceUniqueIdE_t {};
} // unnamed namespace

template <> constexpr inline auto QPointingDeviceUniqueId::qt_create_metaobjectdata<qt_meta_tag_ZN23QPointingDeviceUniqueIdE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPointingDeviceUniqueId",
        "numericId"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'numericId'
        QtMocHelpers::PropertyData<qint64>(1, QMetaType::LongLong, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPointingDeviceUniqueId, qt_meta_tag_ZN23QPointingDeviceUniqueIdE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPointingDeviceUniqueId::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QPointingDeviceUniqueIdE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN23QPointingDeviceUniqueIdE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN23QPointingDeviceUniqueIdE_t>.metaTypes,
    nullptr
} };

void QPointingDeviceUniqueId::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QPointingDeviceUniqueId *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<qint64*>(_v) = _t->numericId(); break;
        default: break;
        }
    }
}
namespace {
struct qt_meta_tag_ZN15QPointingDeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto QPointingDevice::qt_create_metaobjectdata<qt_meta_tag_ZN15QPointingDeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPointingDevice",
        "grabChanged",
        "",
        "grabber",
        "GrabTransition",
        "transition",
        "const QPointerEvent*",
        "event",
        "QEventPoint",
        "point",
        "pointerType",
        "PointerType",
        "maximumPoints",
        "buttonCount",
        "uniqueId",
        "QPointingDeviceUniqueId",
        "PointerTypes",
        "Unknown",
        "Generic",
        "Finger",
        "Pen",
        "Eraser",
        "Cursor",
        "AllPointerTypes",
        "GrabPassive",
        "UngrabPassive",
        "CancelGrabPassive",
        "OverrideGrabPassive",
        "GrabExclusive",
        "UngrabExclusive",
        "CancelGrabExclusive"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'grabChanged'
        QtMocHelpers::SignalData<void(QObject *, GrabTransition, const QPointerEvent *, const QEventPoint &) const>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 3 }, { 0x80000000 | 4, 5 }, { 0x80000000 | 6, 7 }, { 0x80000000 | 8, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'pointerType'
        QtMocHelpers::PropertyData<PointerType>(10, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'maximumPoints'
        QtMocHelpers::PropertyData<int>(12, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'buttonCount'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'uniqueId'
        QtMocHelpers::PropertyData<QPointingDeviceUniqueId>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'PointerTypes'
        QtMocHelpers::EnumData<PointerTypes>(16, 11, QMC::EnumIsScoped).add({
            {   17, PointerType::Unknown },
            {   18, PointerType::Generic },
            {   19, PointerType::Finger },
            {   20, PointerType::Pen },
            {   21, PointerType::Eraser },
            {   22, PointerType::Cursor },
            {   23, PointerType::AllPointerTypes },
        }),
        // enum 'GrabTransition'
        QtMocHelpers::EnumData<GrabTransition>(4, 4, QMC::EnumFlags{}).add({
            {   24, GrabTransition::GrabPassive },
            {   25, GrabTransition::UngrabPassive },
            {   26, GrabTransition::CancelGrabPassive },
            {   27, GrabTransition::OverrideGrabPassive },
            {   28, GrabTransition::GrabExclusive },
            {   29, GrabTransition::UngrabExclusive },
            {   30, GrabTransition::CancelGrabExclusive },
        }),
    };
    return QtMocHelpers::metaObjectData<QPointingDevice, qt_meta_tag_ZN15QPointingDeviceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPointingDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QInputDevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QPointingDeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QPointingDeviceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QPointingDeviceE_t>.metaTypes,
    nullptr
} };

void QPointingDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPointingDevice *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->grabChanged((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<GrabTransition>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<const QPointerEvent*>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QEventPoint>>(_a[4]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPointingDevice::*)(QObject * , GrabTransition , const QPointerEvent * , const QEventPoint & ) const>(_a, &QPointingDevice::grabChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<PointerType*>(_v) = _t->pointerType(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->maximumPoints(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->buttonCount(); break;
        case 3: *reinterpret_cast<QPointingDeviceUniqueId*>(_v) = _t->uniqueId(); break;
        default: break;
        }
    }
}

const QMetaObject *QPointingDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPointingDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QPointingDeviceE_t>.strings))
        return static_cast<void*>(this);
    return QInputDevice::qt_metacast(_clname);
}

int QPointingDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QInputDevice::qt_metacall(_c, _id, _a);
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
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QPointingDevice::grabChanged(QObject * _t1, GrabTransition _t2, const QPointerEvent * _t3, const QEventPoint & _t4)const
{
    QMetaObject::activate<void>(const_cast< QPointingDevice *>(this), &staticMetaObject, 0, nullptr, _t1, _t2, _t3, _t4);
}
QT_WARNING_POP
