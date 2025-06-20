/****************************************************************************
** Meta object code from reading C++ file 'qstackedlayout.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/kernel/qstackedlayout.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstackedlayout.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14QStackedLayoutE_t {};
} // unnamed namespace

template <> constexpr inline auto QStackedLayout::qt_create_metaobjectdata<qt_meta_tag_ZN14QStackedLayoutE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QStackedLayout",
        "widgetRemoved",
        "",
        "index",
        "currentChanged",
        "widgetAdded",
        "setCurrentIndex",
        "setCurrentWidget",
        "QWidget*",
        "w",
        "currentIndex",
        "stackingMode",
        "StackingMode",
        "StackOne",
        "StackAll"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'widgetRemoved'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'currentChanged'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'widgetAdded'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setCurrentIndex'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setCurrentWidget'
        QtMocHelpers::SlotData<void(QWidget *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'currentIndex'
        QtMocHelpers::PropertyData<int>(10, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'stackingMode'
        QtMocHelpers::PropertyData<StackingMode>(11, 0x80000000 | 12, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'StackingMode'
        QtMocHelpers::EnumData<StackingMode>(12, 12, QMC::EnumFlags{}).add({
            {   13, StackingMode::StackOne },
            {   14, StackingMode::StackAll },
        }),
    };
    return QtMocHelpers::metaObjectData<QStackedLayout, qt_meta_tag_ZN14QStackedLayoutE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QStackedLayout::staticMetaObject = { {
    QMetaObject::SuperData::link<QLayout::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QStackedLayoutE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QStackedLayoutE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QStackedLayoutE_t>.metaTypes,
    nullptr
} };

void QStackedLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QStackedLayout *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->widgetRemoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->currentChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->widgetAdded((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->setCurrentIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setCurrentWidget((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QStackedLayout::*)(int )>(_a, &QStackedLayout::widgetRemoved, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStackedLayout::*)(int )>(_a, &QStackedLayout::currentChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStackedLayout::*)(int )>(_a, &QStackedLayout::widgetAdded, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->currentIndex(); break;
        case 1: *reinterpret_cast<StackingMode*>(_v) = _t->stackingMode(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentIndex(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setStackingMode(*reinterpret_cast<StackingMode*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QStackedLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStackedLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QStackedLayoutE_t>.strings))
        return static_cast<void*>(this);
    return QLayout::qt_metacast(_clname);
}

int QStackedLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLayout::qt_metacall(_c, _id, _a);
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
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QStackedLayout::widgetRemoved(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QStackedLayout::currentChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QStackedLayout::widgetAdded(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
