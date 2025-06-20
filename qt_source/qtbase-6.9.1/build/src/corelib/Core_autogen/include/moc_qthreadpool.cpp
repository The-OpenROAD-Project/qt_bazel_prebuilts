/****************************************************************************
** Meta object code from reading C++ file 'qthreadpool.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/thread/qthreadpool.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qthreadpool.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QThreadPoolE_t {};
} // unnamed namespace

template <> constexpr inline auto QThreadPool::qt_create_metaobjectdata<qt_meta_tag_ZN11QThreadPoolE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QThreadPool",
        "expiryTimeout",
        "maxThreadCount",
        "activeThreadCount",
        "stackSize",
        "threadPriority",
        "QThread::Priority"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'expiryTimeout'
        QtMocHelpers::PropertyData<int>(1, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maxThreadCount'
        QtMocHelpers::PropertyData<int>(2, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'activeThreadCount'
        QtMocHelpers::PropertyData<int>(3, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'stackSize'
        QtMocHelpers::PropertyData<uint>(4, QMetaType::UInt, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'threadPriority'
        QtMocHelpers::PropertyData<QThread::Priority>(5, 0x80000000 | 6, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QThreadPool, qt_meta_tag_ZN11QThreadPoolE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT static const QMetaObject::SuperData qt_meta_extradata_ZN11QThreadPoolE[] = {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    nullptr
};

Q_CONSTINIT const QMetaObject QThreadPool::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QThreadPoolE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QThreadPoolE_t>.data,
    qt_static_metacall,
    qt_meta_extradata_ZN11QThreadPoolE,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QThreadPoolE_t>.metaTypes,
    nullptr
} };

void QThreadPool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QThreadPool *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->expiryTimeout(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->maxThreadCount(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->activeThreadCount(); break;
        case 3: *reinterpret_cast<uint*>(_v) = _t->stackSize(); break;
        case 4: *reinterpret_cast<QThread::Priority*>(_v) = _t->threadPriority(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setExpiryTimeout(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setMaxThreadCount(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setStackSize(*reinterpret_cast<uint*>(_v)); break;
        case 4: _t->setThreadPriority(*reinterpret_cast<QThread::Priority*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QThreadPool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QThreadPool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QThreadPoolE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QThreadPool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
