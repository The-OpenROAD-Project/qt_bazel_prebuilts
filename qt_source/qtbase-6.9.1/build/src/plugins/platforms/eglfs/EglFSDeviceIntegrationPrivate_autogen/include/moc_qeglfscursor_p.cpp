/****************************************************************************
** Meta object code from reading C++ file 'qeglfscursor_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/platforms/eglfs/api/qeglfscursor_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qeglfscursor_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN26QEglFSCursorDeviceListenerE_t {};
} // unnamed namespace

template <> constexpr inline auto QEglFSCursorDeviceListener::qt_create_metaobjectdata<qt_meta_tag_ZN26QEglFSCursorDeviceListenerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QEglFSCursorDeviceListener",
        "onDeviceListChanged",
        "",
        "QInputDeviceManager::DeviceType",
        "type"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onDeviceListChanged'
        QtMocHelpers::SlotData<void(QInputDeviceManager::DeviceType)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QEglFSCursorDeviceListener, qt_meta_tag_ZN26QEglFSCursorDeviceListenerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QEglFSCursorDeviceListener::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QEglFSCursorDeviceListenerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QEglFSCursorDeviceListenerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN26QEglFSCursorDeviceListenerE_t>.metaTypes,
    nullptr
} };

void QEglFSCursorDeviceListener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QEglFSCursorDeviceListener *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onDeviceListChanged((*reinterpret_cast< std::add_pointer_t<QInputDeviceManager::DeviceType>>(_a[1]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QInputDeviceManager::DeviceType >(); break;
            }
            break;
        }
    }
}

const QMetaObject *QEglFSCursorDeviceListener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEglFSCursorDeviceListener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QEglFSCursorDeviceListenerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QEglFSCursorDeviceListener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
namespace {
struct qt_meta_tag_ZN12QEglFSCursorE_t {};
} // unnamed namespace

template <> constexpr inline auto QEglFSCursor::qt_create_metaobjectdata<qt_meta_tag_ZN12QEglFSCursorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QEglFSCursor"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QEglFSCursor, qt_meta_tag_ZN12QEglFSCursorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QEglFSCursor::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformCursor::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QEglFSCursorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QEglFSCursorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QEglFSCursorE_t>.metaTypes,
    nullptr
} };

void QEglFSCursor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QEglFSCursor *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QEglFSCursor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QEglFSCursor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QEglFSCursorE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformCursor::qt_metacast(_clname);
}

int QEglFSCursor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformCursor::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
