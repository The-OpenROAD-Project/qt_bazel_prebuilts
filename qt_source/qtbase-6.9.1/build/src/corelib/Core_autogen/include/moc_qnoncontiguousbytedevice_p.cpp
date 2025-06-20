/****************************************************************************
** Meta object code from reading C++ file 'qnoncontiguousbytedevice_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/io/qnoncontiguousbytedevice_p.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnoncontiguousbytedevice_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN24QNonContiguousByteDeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto QNonContiguousByteDevice::qt_create_metaobjectdata<qt_meta_tag_ZN24QNonContiguousByteDeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNonContiguousByteDevice",
        "readyRead",
        "",
        "readProgress",
        "current",
        "total"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'readyRead'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'readProgress'
        QtMocHelpers::SignalData<void(qint64, qint64)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 4 }, { QMetaType::LongLong, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNonContiguousByteDevice, qt_meta_tag_ZN24QNonContiguousByteDeviceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNonContiguousByteDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QNonContiguousByteDeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QNonContiguousByteDeviceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN24QNonContiguousByteDeviceE_t>.metaTypes,
    nullptr
} };

void QNonContiguousByteDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNonContiguousByteDevice *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->readyRead(); break;
        case 1: _t->readProgress((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QNonContiguousByteDevice::*)()>(_a, &QNonContiguousByteDevice::readyRead, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QNonContiguousByteDevice::*)(qint64 , qint64 )>(_a, &QNonContiguousByteDevice::readProgress, 1))
            return;
    }
}

const QMetaObject *QNonContiguousByteDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNonContiguousByteDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN24QNonContiguousByteDeviceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QNonContiguousByteDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QNonContiguousByteDevice::readyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QNonContiguousByteDevice::readProgress(qint64 _t1, qint64 _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}
namespace {
struct qt_meta_tag_ZN37QNonContiguousByteDeviceByteArrayImplE_t {};
} // unnamed namespace

template <> constexpr inline auto QNonContiguousByteDeviceByteArrayImpl::qt_create_metaobjectdata<qt_meta_tag_ZN37QNonContiguousByteDeviceByteArrayImplE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNonContiguousByteDeviceByteArrayImpl"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNonContiguousByteDeviceByteArrayImpl, qt_meta_tag_ZN37QNonContiguousByteDeviceByteArrayImplE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNonContiguousByteDeviceByteArrayImpl::staticMetaObject = { {
    QMetaObject::SuperData::link<QNonContiguousByteDevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN37QNonContiguousByteDeviceByteArrayImplE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN37QNonContiguousByteDeviceByteArrayImplE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN37QNonContiguousByteDeviceByteArrayImplE_t>.metaTypes,
    nullptr
} };

void QNonContiguousByteDeviceByteArrayImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNonContiguousByteDeviceByteArrayImpl *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QNonContiguousByteDeviceByteArrayImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNonContiguousByteDeviceByteArrayImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN37QNonContiguousByteDeviceByteArrayImplE_t>.strings))
        return static_cast<void*>(this);
    return QNonContiguousByteDevice::qt_metacast(_clname);
}

int QNonContiguousByteDeviceByteArrayImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNonContiguousByteDevice::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN38QNonContiguousByteDeviceRingBufferImplE_t {};
} // unnamed namespace

template <> constexpr inline auto QNonContiguousByteDeviceRingBufferImpl::qt_create_metaobjectdata<qt_meta_tag_ZN38QNonContiguousByteDeviceRingBufferImplE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNonContiguousByteDeviceRingBufferImpl"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNonContiguousByteDeviceRingBufferImpl, qt_meta_tag_ZN38QNonContiguousByteDeviceRingBufferImplE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNonContiguousByteDeviceRingBufferImpl::staticMetaObject = { {
    QMetaObject::SuperData::link<QNonContiguousByteDevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN38QNonContiguousByteDeviceRingBufferImplE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN38QNonContiguousByteDeviceRingBufferImplE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN38QNonContiguousByteDeviceRingBufferImplE_t>.metaTypes,
    nullptr
} };

void QNonContiguousByteDeviceRingBufferImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNonContiguousByteDeviceRingBufferImpl *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QNonContiguousByteDeviceRingBufferImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNonContiguousByteDeviceRingBufferImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN38QNonContiguousByteDeviceRingBufferImplE_t>.strings))
        return static_cast<void*>(this);
    return QNonContiguousByteDevice::qt_metacast(_clname);
}

int QNonContiguousByteDeviceRingBufferImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNonContiguousByteDevice::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN36QNonContiguousByteDeviceIoDeviceImplE_t {};
} // unnamed namespace

template <> constexpr inline auto QNonContiguousByteDeviceIoDeviceImpl::qt_create_metaobjectdata<qt_meta_tag_ZN36QNonContiguousByteDeviceIoDeviceImplE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNonContiguousByteDeviceIoDeviceImpl"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QNonContiguousByteDeviceIoDeviceImpl, qt_meta_tag_ZN36QNonContiguousByteDeviceIoDeviceImplE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNonContiguousByteDeviceIoDeviceImpl::staticMetaObject = { {
    QMetaObject::SuperData::link<QNonContiguousByteDevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN36QNonContiguousByteDeviceIoDeviceImplE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN36QNonContiguousByteDeviceIoDeviceImplE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN36QNonContiguousByteDeviceIoDeviceImplE_t>.metaTypes,
    nullptr
} };

void QNonContiguousByteDeviceIoDeviceImpl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QNonContiguousByteDeviceIoDeviceImpl *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QNonContiguousByteDeviceIoDeviceImpl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNonContiguousByteDeviceIoDeviceImpl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN36QNonContiguousByteDeviceIoDeviceImplE_t>.strings))
        return static_cast<void*>(this);
    return QNonContiguousByteDevice::qt_metacast(_clname);
}

int QNonContiguousByteDeviceIoDeviceImpl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QNonContiguousByteDevice::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN27QByteDeviceWrappingIoDeviceE_t {};
} // unnamed namespace

template <> constexpr inline auto QByteDeviceWrappingIoDevice::qt_create_metaobjectdata<qt_meta_tag_ZN27QByteDeviceWrappingIoDeviceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QByteDeviceWrappingIoDevice"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QByteDeviceWrappingIoDevice, qt_meta_tag_ZN27QByteDeviceWrappingIoDeviceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QByteDeviceWrappingIoDevice::staticMetaObject = { {
    QMetaObject::SuperData::link<QIODevice::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QByteDeviceWrappingIoDeviceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QByteDeviceWrappingIoDeviceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN27QByteDeviceWrappingIoDeviceE_t>.metaTypes,
    nullptr
} };

void QByteDeviceWrappingIoDevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QByteDeviceWrappingIoDevice *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QByteDeviceWrappingIoDevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QByteDeviceWrappingIoDevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QByteDeviceWrappingIoDeviceE_t>.strings))
        return static_cast<void*>(this);
    return QIODevice::qt_metacast(_clname);
}

int QByteDeviceWrappingIoDevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QIODevice::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
