/****************************************************************************
** Meta object code from reading C++ file 'qscroller.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/util/qscroller.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qscroller.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QScrollerE_t {};
} // unnamed namespace

template <> constexpr inline auto QScroller::qt_create_metaobjectdata<qt_meta_tag_ZN9QScrollerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QScroller",
        "stateChanged",
        "",
        "QScroller::State",
        "newstate",
        "scrollerPropertiesChanged",
        "QScrollerProperties",
        "setScrollerProperties",
        "prop",
        "scrollTo",
        "pos",
        "scrollTime",
        "ensureVisible",
        "rect",
        "xmargin",
        "ymargin",
        "resendPrepareEvent",
        "state",
        "State",
        "scrollerProperties",
        "Inactive",
        "Pressed",
        "Dragging",
        "Scrolling"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(QScroller::State)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'scrollerPropertiesChanged'
        QtMocHelpers::SignalData<void(const QScrollerProperties &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 2 },
        }}),
        // Slot 'setScrollerProperties'
        QtMocHelpers::SlotData<void(const QScrollerProperties &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 6, 8 },
        }}),
        // Slot 'scrollTo'
        QtMocHelpers::SlotData<void(const QPointF &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 10 },
        }}),
        // Slot 'scrollTo'
        QtMocHelpers::SlotData<void(const QPointF &, int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPointF, 10 }, { QMetaType::Int, 11 },
        }}),
        // Slot 'ensureVisible'
        QtMocHelpers::SlotData<void(const QRectF &, qreal, qreal)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 13 }, { QMetaType::QReal, 14 }, { QMetaType::QReal, 15 },
        }}),
        // Slot 'ensureVisible'
        QtMocHelpers::SlotData<void(const QRectF &, qreal, qreal, int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRectF, 13 }, { QMetaType::QReal, 14 }, { QMetaType::QReal, 15 }, { QMetaType::Int, 11 },
        }}),
        // Slot 'resendPrepareEvent'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'state'
        QtMocHelpers::PropertyData<State>(17, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::EnumOrFlag, 0),
        // property 'scrollerProperties'
        QtMocHelpers::PropertyData<QScrollerProperties>(19, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'State'
        QtMocHelpers::EnumData<State>(18, 18, QMC::EnumFlags{}).add({
            {   20, State::Inactive },
            {   21, State::Pressed },
            {   22, State::Dragging },
            {   23, State::Scrolling },
        }),
    };
    return QtMocHelpers::metaObjectData<QScroller, qt_meta_tag_ZN9QScrollerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QScroller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QScrollerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QScrollerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QScrollerE_t>.metaTypes,
    nullptr
} };

void QScroller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QScroller *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<QScroller::State>>(_a[1]))); break;
        case 1: _t->scrollerPropertiesChanged((*reinterpret_cast< std::add_pointer_t<QScrollerProperties>>(_a[1]))); break;
        case 2: _t->setScrollerProperties((*reinterpret_cast< std::add_pointer_t<QScrollerProperties>>(_a[1]))); break;
        case 3: _t->scrollTo((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1]))); break;
        case 4: _t->scrollTo((*reinterpret_cast< std::add_pointer_t<QPointF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 5: _t->ensureVisible((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3]))); break;
        case 6: _t->ensureVisible((*reinterpret_cast< std::add_pointer_t<QRectF>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<qreal>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 7: _t->resendPrepareEvent(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QScroller::*)(QScroller::State )>(_a, &QScroller::stateChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QScroller::*)(const QScrollerProperties & )>(_a, &QScroller::scrollerPropertiesChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<State*>(_v) = _t->state(); break;
        case 1: *reinterpret_cast<QScrollerProperties*>(_v) = _t->scrollerProperties(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setScrollerProperties(*reinterpret_cast<QScrollerProperties*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QScroller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QScroller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QScrollerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QScroller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QScroller::stateChanged(QScroller::State _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QScroller::scrollerPropertiesChanged(const QScrollerProperties & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
