/****************************************************************************
** Meta object code from reading C++ file 'qdatawidgetmapper.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/itemviews/qdatawidgetmapper.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdatawidgetmapper.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QDataWidgetMapperE_t {};
} // unnamed namespace

template <> constexpr inline auto QDataWidgetMapper::qt_create_metaobjectdata<qt_meta_tag_ZN17QDataWidgetMapperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDataWidgetMapper",
        "currentIndexChanged",
        "",
        "index",
        "revert",
        "submit",
        "toFirst",
        "toLast",
        "toNext",
        "toPrevious",
        "setCurrentIndex",
        "setCurrentModelIndex",
        "QModelIndex",
        "currentIndex",
        "orientation",
        "Qt::Orientation",
        "submitPolicy",
        "SubmitPolicy",
        "AutoSubmit",
        "ManualSubmit"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'currentIndexChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'revert'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'submit'
        QtMocHelpers::SlotData<bool()>(5, 2, QMC::AccessPublic, QMetaType::Bool),
        // Slot 'toFirst'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toLast'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toNext'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toPrevious'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCurrentIndex'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setCurrentModelIndex'
        QtMocHelpers::SlotData<void(const QModelIndex &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'currentIndex'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'orientation'
        QtMocHelpers::PropertyData<Qt::Orientation>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'submitPolicy'
        QtMocHelpers::PropertyData<SubmitPolicy>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'SubmitPolicy'
        QtMocHelpers::EnumData<SubmitPolicy>(17, 17, QMC::EnumFlags{}).add({
            {   18, SubmitPolicy::AutoSubmit },
            {   19, SubmitPolicy::ManualSubmit },
        }),
    };
    return QtMocHelpers::metaObjectData<QDataWidgetMapper, qt_meta_tag_ZN17QDataWidgetMapperE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDataWidgetMapper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QDataWidgetMapperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QDataWidgetMapperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QDataWidgetMapperE_t>.metaTypes,
    nullptr
} };

void QDataWidgetMapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDataWidgetMapper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->revert(); break;
        case 2: { bool _r = _t->submit();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->toFirst(); break;
        case 4: _t->toLast(); break;
        case 5: _t->toNext(); break;
        case 6: _t->toPrevious(); break;
        case 7: _t->setCurrentIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->setCurrentModelIndex((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDataWidgetMapper::*)(int )>(_a, &QDataWidgetMapper::currentIndexChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->currentIndex(); break;
        case 1: *reinterpret_cast<Qt::Orientation*>(_v) = _t->orientation(); break;
        case 2: *reinterpret_cast<SubmitPolicy*>(_v) = _t->submitPolicy(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentIndex(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setOrientation(*reinterpret_cast<Qt::Orientation*>(_v)); break;
        case 2: _t->setSubmitPolicy(*reinterpret_cast<SubmitPolicy*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QDataWidgetMapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDataWidgetMapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QDataWidgetMapperE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QDataWidgetMapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
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
void QDataWidgetMapper::currentIndexChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
