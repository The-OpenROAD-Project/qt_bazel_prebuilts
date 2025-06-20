/****************************************************************************
** Meta object code from reading C++ file 'qlayout.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/kernel/qlayout.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlayout.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7QLayoutE_t {};
} // unnamed namespace

template <> constexpr inline auto QLayout::qt_create_metaobjectdata<qt_meta_tag_ZN7QLayoutE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QLayout",
        "spacing",
        "contentsMargins",
        "QMargins",
        "sizeConstraint",
        "SizeConstraint",
        "SetDefaultConstraint",
        "SetNoConstraint",
        "SetMinimumSize",
        "SetFixedSize",
        "SetMaximumSize",
        "SetMinAndMaxSize"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'spacing'
        QtMocHelpers::PropertyData<int>(1, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'contentsMargins'
        QtMocHelpers::PropertyData<QMargins>(2, 0x80000000 | 3, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'sizeConstraint'
        QtMocHelpers::PropertyData<SizeConstraint>(4, 0x80000000 | 5, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SizeConstraint'
        QtMocHelpers::EnumData<SizeConstraint>(5, 5, QMC::EnumFlags{}).add({
            {    6, SizeConstraint::SetDefaultConstraint },
            {    7, SizeConstraint::SetNoConstraint },
            {    8, SizeConstraint::SetMinimumSize },
            {    9, SizeConstraint::SetFixedSize },
            {   10, SizeConstraint::SetMaximumSize },
            {   11, SizeConstraint::SetMinAndMaxSize },
        }),
    };
    return QtMocHelpers::metaObjectData<QLayout, qt_meta_tag_ZN7QLayoutE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QLayout::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QLayoutE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QLayoutE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7QLayoutE_t>.metaTypes,
    nullptr
} };

void QLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QLayout *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->spacing(); break;
        case 1: *reinterpret_cast<QMargins*>(_v) = _t->contentsMargins(); break;
        case 2: *reinterpret_cast<SizeConstraint*>(_v) = _t->sizeConstraint(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpacing(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setContentsMargins(*reinterpret_cast<QMargins*>(_v)); break;
        case 2: _t->setSizeConstraint(*reinterpret_cast<SizeConstraint*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 1: _t->unsetContentsMargins(); break;
        default: break;
        }
    }
}

const QMetaObject *QLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QLayoutE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QLayoutItem"))
        return static_cast< QLayoutItem*>(this);
    return QObject::qt_metacast(_clname);
}

int QLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
