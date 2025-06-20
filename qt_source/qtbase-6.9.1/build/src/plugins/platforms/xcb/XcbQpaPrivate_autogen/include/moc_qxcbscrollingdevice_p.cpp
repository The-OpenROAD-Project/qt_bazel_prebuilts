/****************************************************************************
** Meta object code from reading C++ file 'qxcbscrollingdevice_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../src/plugins/platforms/xcb/qxcbscrollingdevice_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qxcbscrollingdevice_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN19QXcbScrollingDeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto QXcbScrollingDevice::qt_create_metaobjectdata<qt_meta_tag_ZN19QXcbScrollingDeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QXcbScrollingDevice"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QXcbScrollingDevice, qt_meta_tag_ZN19QXcbScrollingDeviceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QXcbScrollingDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QPointingDevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QXcbScrollingDeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QXcbScrollingDeviceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QXcbScrollingDeviceE_t>.metaTypes,
    nullptr
} };

void QXcbScrollingDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QXcbScrollingDevice *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QXcbScrollingDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QXcbScrollingDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QXcbScrollingDeviceE_t>.strings))
        return static_cast<void*>(this);
    return QPointingDevice::qt_metacast(_clname);
}

int QXcbScrollingDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPointingDevice::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
