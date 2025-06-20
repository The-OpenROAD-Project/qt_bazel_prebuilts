/****************************************************************************
** Meta object code from reading C++ file 'qsignalmapper.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/kernel/qsignalmapper.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsignalmapper.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QSignalMapperE_t {};
} // unnamed namespace

template <> constexpr inline auto QSignalMapper::qt_create_metaobjectdata<qt_meta_tag_ZN13QSignalMapperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSignalMapper",
        "mappedInt",
        "",
        "mappedString",
        "mappedObject",
        "map",
        "sender"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'mappedInt'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 2 },
        }}),
        // Signal 'mappedString'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'mappedObject'
        QtMocHelpers::SignalData<void(QObject *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 2 },
        }}),
        // Slot 'map'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'map'
        QtMocHelpers::SlotData<void(QObject *)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QSignalMapper, qt_meta_tag_ZN13QSignalMapperE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSignalMapper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSignalMapperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSignalMapperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QSignalMapperE_t>.metaTypes,
    nullptr
} };

void QSignalMapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSignalMapper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->mappedInt((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->mappedString((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->mappedObject((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        case 3: _t->map(); break;
        case 4: _t->map((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QSignalMapper::*)(int )>(_a, &QSignalMapper::mappedInt, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSignalMapper::*)(const QString & )>(_a, &QSignalMapper::mappedString, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QSignalMapper::*)(QObject * )>(_a, &QSignalMapper::mappedObject, 2))
            return;
    }
}

const QMetaObject *QSignalMapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSignalMapper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSignalMapperE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSignalMapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void QSignalMapper::mappedInt(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QSignalMapper::mappedString(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QSignalMapper::mappedObject(QObject * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
