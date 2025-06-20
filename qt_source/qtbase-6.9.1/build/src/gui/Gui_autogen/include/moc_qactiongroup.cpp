/****************************************************************************
** Meta object code from reading C++ file 'qactiongroup.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qactiongroup.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qactiongroup.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QActionGroupE_t {};
} // unnamed namespace

template <> constexpr inline auto QActionGroup::qt_create_metaobjectdata<qt_meta_tag_ZN12QActionGroupE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QActionGroup",
        "triggered",
        "",
        "QAction*",
        "hovered",
        "setEnabled",
        "setDisabled",
        "b",
        "setVisible",
        "setExclusive",
        "setExclusionPolicy",
        "ExclusionPolicy",
        "policy",
        "_q_actionTriggered",
        "_q_actionHovered",
        "_q_actionChanged",
        "exclusionPolicy",
        "QActionGroup::ExclusionPolicy",
        "enabled",
        "visible",
        "None",
        "Exclusive",
        "ExclusiveOptional"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'triggered'
        QtMocHelpers::SignalData<void(QAction *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Signal 'hovered'
        QtMocHelpers::SignalData<void(QAction *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 2 },
        }}),
        // Slot 'setEnabled'
        QtMocHelpers::SlotData<void(bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'setDisabled'
        QtMocHelpers::SlotData<void(bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 7 },
        }}),
        // Slot 'setVisible'
        QtMocHelpers::SlotData<void(bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'setExclusive'
        QtMocHelpers::SlotData<void(bool)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'setExclusionPolicy'
        QtMocHelpers::SlotData<void(ExclusionPolicy)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 11, 12 },
        }}),
        // Slot '_q_actionTriggered'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_actionHovered'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_actionChanged'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'exclusionPolicy'
        QtMocHelpers::PropertyData<QActionGroup::ExclusionPolicy>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'visible'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ExclusionPolicy'
        QtMocHelpers::EnumData<ExclusionPolicy>(11, 11, QMC::EnumIsScoped).add({
            {   20, ExclusionPolicy::None },
            {   21, ExclusionPolicy::Exclusive },
            {   22, ExclusionPolicy::ExclusiveOptional },
        }),
    };
    return QtMocHelpers::metaObjectData<QActionGroup, qt_meta_tag_ZN12QActionGroupE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QActionGroup::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QActionGroupE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QActionGroupE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QActionGroupE_t>.metaTypes,
    nullptr
} };

void QActionGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QActionGroup *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->triggered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 1: _t->hovered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 2: _t->setEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->setDisabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->setVisible((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->setExclusive((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->setExclusionPolicy((*reinterpret_cast< std::add_pointer_t<ExclusionPolicy>>(_a[1]))); break;
        case 7: _t->_q_actionTriggered(); break;
        case 8: _t->_q_actionHovered(); break;
        case 9: _t->_q_actionChanged(); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QActionGroup::*)(QAction * )>(_a, &QActionGroup::triggered, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QActionGroup::*)(QAction * )>(_a, &QActionGroup::hovered, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QActionGroup::ExclusionPolicy*>(_v) = _t->exclusionPolicy(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isEnabled(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isVisible(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setExclusionPolicy(*reinterpret_cast<QActionGroup::ExclusionPolicy*>(_v)); break;
        case 1: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setVisible(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QActionGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QActionGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QActionGroupE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QActionGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QActionGroup::triggered(QAction * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QActionGroup::hovered(QAction * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
