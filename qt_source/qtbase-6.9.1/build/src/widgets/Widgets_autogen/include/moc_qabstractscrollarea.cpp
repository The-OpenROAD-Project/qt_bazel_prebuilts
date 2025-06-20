/****************************************************************************
** Meta object code from reading C++ file 'qabstractscrollarea.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qabstractscrollarea.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractscrollarea.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QAbstractScrollAreaE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractScrollArea::qt_create_metaobjectdata<qt_meta_tag_ZN19QAbstractScrollAreaE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractScrollArea",
        "_q_hslide",
        "",
        "_q_vslide",
        "_q_showOrHideScrollBars",
        "verticalScrollBarPolicy",
        "Qt::ScrollBarPolicy",
        "horizontalScrollBarPolicy",
        "sizeAdjustPolicy",
        "SizeAdjustPolicy",
        "AdjustIgnored",
        "AdjustToContentsOnFirstShow",
        "AdjustToContents"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot '_q_hslide'
        QtMocHelpers::SlotData<void(int)>(1, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot '_q_vslide'
        QtMocHelpers::SlotData<void(int)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Slot '_q_showOrHideScrollBars'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'verticalScrollBarPolicy'
        QtMocHelpers::PropertyData<Qt::ScrollBarPolicy>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'horizontalScrollBarPolicy'
        QtMocHelpers::PropertyData<Qt::ScrollBarPolicy>(7, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'sizeAdjustPolicy'
        QtMocHelpers::PropertyData<SizeAdjustPolicy>(8, 0x80000000 | 9, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SizeAdjustPolicy'
        QtMocHelpers::EnumData<SizeAdjustPolicy>(9, 9, QMC::EnumFlags{}).add({
            {   10, SizeAdjustPolicy::AdjustIgnored },
            {   11, SizeAdjustPolicy::AdjustToContentsOnFirstShow },
            {   12, SizeAdjustPolicy::AdjustToContents },
        }),
    };
    return QtMocHelpers::metaObjectData<QAbstractScrollArea, qt_meta_tag_ZN19QAbstractScrollAreaE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractScrollArea::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractScrollAreaE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractScrollAreaE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QAbstractScrollAreaE_t>.metaTypes,
    nullptr
} };

void QAbstractScrollArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractScrollArea *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->d_func()->_q_hslide((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->d_func()->_q_vslide((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->d_func()->_q_showOrHideScrollBars(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Qt::ScrollBarPolicy*>(_v) = _t->verticalScrollBarPolicy(); break;
        case 1: *reinterpret_cast<Qt::ScrollBarPolicy*>(_v) = _t->horizontalScrollBarPolicy(); break;
        case 2: *reinterpret_cast<SizeAdjustPolicy*>(_v) = _t->sizeAdjustPolicy(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVerticalScrollBarPolicy(*reinterpret_cast<Qt::ScrollBarPolicy*>(_v)); break;
        case 1: _t->setHorizontalScrollBarPolicy(*reinterpret_cast<Qt::ScrollBarPolicy*>(_v)); break;
        case 2: _t->setSizeAdjustPolicy(*reinterpret_cast<SizeAdjustPolicy*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QAbstractScrollArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractScrollArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QAbstractScrollAreaE_t>.strings))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int QAbstractScrollArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
