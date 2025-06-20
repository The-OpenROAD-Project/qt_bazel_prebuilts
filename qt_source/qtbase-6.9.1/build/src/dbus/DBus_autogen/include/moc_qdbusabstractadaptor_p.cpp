/****************************************************************************
** Meta object code from reading C++ file 'qdbusabstractadaptor_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/dbus/qdbusabstractadaptor_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdbusabstractadaptor_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21QDBusAdaptorConnectorE_t {};
} // unnamed namespace

template <> constexpr inline auto QDBusAdaptorConnector::qt_create_metaobjectdata<qt_meta_tag_ZN21QDBusAdaptorConnectorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDBusAdaptorConnector",
        "relaySignal",
        "",
        "obj",
        "const QMetaObject*",
        "metaObject",
        "sid",
        "QVariantList",
        "args",
        "relaySlot",
        "polish"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'relaySignal'
        QtMocHelpers::SignalData<void(QObject *, const QMetaObject *, int, const QVariantList &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 3 }, { 0x80000000 | 4, 5 }, { QMetaType::Int, 6 }, { 0x80000000 | 7, 8 },
        }}),
        // Slot 'relaySlot'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'polish'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDBusAdaptorConnector, qt_meta_tag_ZN21QDBusAdaptorConnectorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDBusAdaptorConnector::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QDBusAdaptorConnectorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QDBusAdaptorConnectorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QDBusAdaptorConnectorE_t>.metaTypes,
    nullptr
} };

void QDBusAdaptorConnector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDBusAdaptorConnector *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->relaySignal((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<const QMetaObject*>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[4]))); break;
        case 1: _t->relaySlot(QMethodRawArguments{ _a }); break;
        case 2: _t->polish(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDBusAdaptorConnector::*)(QObject * , const QMetaObject * , int , const QVariantList & )>(_a, &QDBusAdaptorConnector::relaySignal, 0))
            return;
    }
}

const QMetaObject *QDBusAdaptorConnector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDBusAdaptorConnector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QDBusAdaptorConnectorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QDBusAdaptorConnector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void QDBusAdaptorConnector::relaySignal(QObject * _t1, const QMetaObject * _t2, int _t3, const QVariantList & _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2, _t3, _t4);
}
QT_WARNING_POP
