/****************************************************************************
** Meta object code from reading C++ file 'qbuttongroup.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qbuttongroup.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qbuttongroup.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QButtonGroupE_t {};
} // unnamed namespace

template <> constexpr inline auto QButtonGroup::qt_create_metaobjectdata<qt_meta_tag_ZN12QButtonGroupE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QButtonGroup",
        "buttonClicked",
        "",
        "QAbstractButton*",
        "buttonPressed",
        "buttonReleased",
        "buttonToggled",
        "idClicked",
        "idPressed",
        "idReleased",
        "idToggled",
        "exclusive"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'buttonClicked'
        QtMocHelpers::SignalData<void(QAbstractButton *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'buttonPressed'
        QtMocHelpers::SignalData<void(QAbstractButton *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'buttonReleased'
        QtMocHelpers::SignalData<void(QAbstractButton *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'buttonToggled'
        QtMocHelpers::SignalData<void(QAbstractButton *, bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 }, { QMetaType::Bool, 2 },
        }}),
        // Signal 'idClicked'
        QtMocHelpers::SignalData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'idPressed'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'idReleased'
        QtMocHelpers::SignalData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'idToggled'
        QtMocHelpers::SignalData<void(int, bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 }, { QMetaType::Bool, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'exclusive'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QButtonGroup, qt_meta_tag_ZN12QButtonGroupE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QButtonGroup::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QButtonGroupE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QButtonGroupE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QButtonGroupE_t>.metaTypes,
    nullptr
} };

void QButtonGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QButtonGroup *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->buttonClicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 1: _t->buttonPressed((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 2: _t->buttonReleased((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 3: _t->buttonToggled((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 4: _t->idClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->idPressed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->idReleased((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->idToggled((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QButtonGroup::*)(QAbstractButton * )>(_a, &QButtonGroup::buttonClicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QButtonGroup::*)(QAbstractButton * )>(_a, &QButtonGroup::buttonPressed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QButtonGroup::*)(QAbstractButton * )>(_a, &QButtonGroup::buttonReleased, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QButtonGroup::*)(QAbstractButton * , bool )>(_a, &QButtonGroup::buttonToggled, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QButtonGroup::*)(int )>(_a, &QButtonGroup::idClicked, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QButtonGroup::*)(int )>(_a, &QButtonGroup::idPressed, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QButtonGroup::*)(int )>(_a, &QButtonGroup::idReleased, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QButtonGroup::*)(int , bool )>(_a, &QButtonGroup::idToggled, 7))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->exclusive(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setExclusive(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QButtonGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QButtonGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QButtonGroupE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QButtonGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
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
void QButtonGroup::buttonClicked(QAbstractButton * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QButtonGroup::buttonPressed(QAbstractButton * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QButtonGroup::buttonReleased(QAbstractButton * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QButtonGroup::buttonToggled(QAbstractButton * _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void QButtonGroup::idClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QButtonGroup::idPressed(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QButtonGroup::idReleased(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QButtonGroup::idToggled(int _t1, bool _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1, _t2);
}
QT_WARNING_POP
