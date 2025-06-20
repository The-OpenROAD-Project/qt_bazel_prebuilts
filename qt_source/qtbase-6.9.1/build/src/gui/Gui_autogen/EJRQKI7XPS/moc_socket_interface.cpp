/****************************************************************************
** Meta object code from reading C++ file 'socket_interface.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../socket_interface.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'socket_interface.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN27OrgA11yAtspiSocketInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto OrgA11yAtspiSocketInterface::qt_create_metaobjectdata<qt_meta_tag_ZN27OrgA11yAtspiSocketInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "OrgA11yAtspiSocketInterface",
        "Available",
        "",
        "Embed",
        "QDBusPendingReply<QSpiObjectReference>",
        "QSpiObjectReference",
        "plug",
        "Unembed",
        "QDBusPendingReply<>"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'Available'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'Embed'
        QtMocHelpers::SlotData<QDBusPendingReply<QSpiObjectReference>(const QSpiObjectReference &)>(3, 2, QMC::AccessPublic, 0x80000000 | 4, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Slot 'Unembed'
        QtMocHelpers::SlotData<QDBusPendingReply<>(const QSpiObjectReference &)>(7, 2, QMC::AccessPublic, 0x80000000 | 8, {{
            { 0x80000000 | 5, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<OrgA11yAtspiSocketInterface, qt_meta_tag_ZN27OrgA11yAtspiSocketInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject OrgA11yAtspiSocketInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QDBusAbstractInterface::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27OrgA11yAtspiSocketInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27OrgA11yAtspiSocketInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN27OrgA11yAtspiSocketInterfaceE_t>.metaTypes,
    nullptr
} };

void OrgA11yAtspiSocketInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<OrgA11yAtspiSocketInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->Available(); break;
        case 1: { QDBusPendingReply<QSpiObjectReference> _r = _t->Embed((*reinterpret_cast< std::add_pointer_t<QSpiObjectReference>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<QSpiObjectReference>*>(_a[0]) = std::move(_r); }  break;
        case 2: { QDBusPendingReply<> _r = _t->Unembed((*reinterpret_cast< std::add_pointer_t<QSpiObjectReference>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSpiObjectReference >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QSpiObjectReference >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (OrgA11yAtspiSocketInterface::*)()>(_a, &OrgA11yAtspiSocketInterface::Available, 0))
            return;
    }
}

const QMetaObject *OrgA11yAtspiSocketInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrgA11yAtspiSocketInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27OrgA11yAtspiSocketInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int OrgA11yAtspiSocketInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void OrgA11yAtspiSocketInterface::Available()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
