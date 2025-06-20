/****************************************************************************
** Meta object code from reading C++ file 'qsharedmemory.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/ipc/qsharedmemory.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsharedmemory.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QSharedMemoryE_t {};
} // unnamed namespace

template <> constexpr inline auto QSharedMemory::qt_create_metaobjectdata<qt_meta_tag_ZN13QSharedMemoryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSharedMemory",
        "AccessMode",
        "ReadOnly",
        "ReadWrite",
        "SharedMemoryError",
        "NoError",
        "PermissionDenied",
        "InvalidSize",
        "KeyError",
        "AlreadyExists",
        "NotFound",
        "LockError",
        "OutOfResources",
        "UnknownError"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'AccessMode'
        QtMocHelpers::EnumData<AccessMode>(1, 1, QMC::EnumFlags{}).add({
            {    2, AccessMode::ReadOnly },
            {    3, AccessMode::ReadWrite },
        }),
        // enum 'SharedMemoryError'
        QtMocHelpers::EnumData<SharedMemoryError>(4, 4, QMC::EnumFlags{}).add({
            {    5, SharedMemoryError::NoError },
            {    6, SharedMemoryError::PermissionDenied },
            {    7, SharedMemoryError::InvalidSize },
            {    8, SharedMemoryError::KeyError },
            {    9, SharedMemoryError::AlreadyExists },
            {   10, SharedMemoryError::NotFound },
            {   11, SharedMemoryError::LockError },
            {   12, SharedMemoryError::OutOfResources },
            {   13, SharedMemoryError::UnknownError },
        }),
    };
    return QtMocHelpers::metaObjectData<QSharedMemory, qt_meta_tag_ZN13QSharedMemoryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSharedMemory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSharedMemoryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSharedMemoryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QSharedMemoryE_t>.metaTypes,
    nullptr
} };

void QSharedMemory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSharedMemory *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QSharedMemory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSharedMemory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QSharedMemoryE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSharedMemory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
