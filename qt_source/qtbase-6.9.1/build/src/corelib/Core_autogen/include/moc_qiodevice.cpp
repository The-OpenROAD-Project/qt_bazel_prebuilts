/****************************************************************************
** Meta object code from reading C++ file 'qiodevice.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/io/qiodevice.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qiodevice.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QIODeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto QIODevice::qt_create_metaobjectdata<qt_meta_tag_ZN9QIODeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QIODevice",
        "readyRead",
        "",
        "channelReadyRead",
        "channel",
        "bytesWritten",
        "bytes",
        "channelBytesWritten",
        "aboutToClose",
        "readChannelFinished"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'readyRead'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'channelReadyRead'
        QtMocHelpers::SignalData<void(int)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 },
        }}),
        // Signal 'bytesWritten'
        QtMocHelpers::SignalData<void(qint64)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 6 },
        }}),
        // Signal 'channelBytesWritten'
        QtMocHelpers::SignalData<void(int, qint64)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 4 }, { QMetaType::LongLong, 6 },
        }}),
        // Signal 'aboutToClose'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'readChannelFinished'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QIODevice, qt_meta_tag_ZN9QIODeviceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QIODevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QIODeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QIODeviceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QIODeviceE_t>.metaTypes,
    nullptr
} };

void QIODevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QIODevice *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->readyRead(); break;
        case 1: _t->channelReadyRead((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->bytesWritten((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 3: _t->channelBytesWritten((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        case 4: _t->aboutToClose(); break;
        case 5: _t->readChannelFinished(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QIODevice::*)()>(_a, &QIODevice::readyRead, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIODevice::*)(int )>(_a, &QIODevice::channelReadyRead, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIODevice::*)(qint64 )>(_a, &QIODevice::bytesWritten, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIODevice::*)(int , qint64 )>(_a, &QIODevice::channelBytesWritten, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIODevice::*)()>(_a, &QIODevice::aboutToClose, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIODevice::*)()>(_a, &QIODevice::readChannelFinished, 5))
            return;
    }
}

const QMetaObject *QIODevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIODevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QIODeviceE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QIODeviceBase"))
        return static_cast< QIODeviceBase*>(this);
    return QObject::qt_metacast(_clname);
}

int QIODevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QIODevice::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QIODevice::channelReadyRead(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QIODevice::bytesWritten(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QIODevice::channelBytesWritten(int _t1, qint64 _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}

// SIGNAL 4
void QIODevice::aboutToClose()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QIODevice::readChannelFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
