/****************************************************************************
** Meta object code from reading C++ file 'qslider.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qslider.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qslider.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7QSliderE_t {};
} // unnamed namespace

template <> constexpr inline auto QSlider::qt_create_metaobjectdata<qt_meta_tag_ZN7QSliderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSlider",
        "tickPosition",
        "TickPosition",
        "tickInterval",
        "NoTicks",
        "TicksAbove",
        "TicksLeft",
        "TicksBelow",
        "TicksRight",
        "TicksBothSides"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'tickPosition'
        QtMocHelpers::PropertyData<TickPosition>(1, 0x80000000 | 2, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'tickInterval'
        QtMocHelpers::PropertyData<int>(3, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'TickPosition'
        QtMocHelpers::EnumData<TickPosition>(2, 2, QMC::EnumFlags{}).add({
            {    4, TickPosition::NoTicks },
            {    5, TickPosition::TicksAbove },
            {    6, TickPosition::TicksLeft },
            {    7, TickPosition::TicksBelow },
            {    8, TickPosition::TicksRight },
            {    9, TickPosition::TicksBothSides },
        }),
    };
    return QtMocHelpers::metaObjectData<QSlider, qt_meta_tag_ZN7QSliderE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractSlider::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QSliderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QSliderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7QSliderE_t>.metaTypes,
    nullptr
} };

void QSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSlider *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<TickPosition*>(_v) = _t->tickPosition(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->tickInterval(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTickPosition(*reinterpret_cast<TickPosition*>(_v)); break;
        case 1: _t->setTickInterval(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QSliderE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractSlider::qt_metacast(_clname);
}

int QSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSlider::qt_metacall(_c, _id, _a);
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
