/****************************************************************************
** Meta object code from reading C++ file 'qfilesystemmodel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/itemmodels/qfilesystemmodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfilesystemmodel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QFileSystemModelE_t {};
} // unnamed namespace

template <> constexpr inline auto QFileSystemModel::qt_create_metaobjectdata<qt_meta_tag_ZN16QFileSystemModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFileSystemModel",
        "rootPathChanged",
        "",
        "newPath",
        "fileRenamed",
        "path",
        "oldName",
        "newName",
        "directoryLoaded",
        "resolveSymlinks",
        "readOnly",
        "nameFilterDisables",
        "options",
        "Options",
        "Option",
        "DontWatchForChanges",
        "DontResolveSymlinks",
        "DontUseCustomDirectoryIcons"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'rootPathChanged'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'fileRenamed'
        QtMocHelpers::SignalData<void(const QString &, const QString &, const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 }, { QMetaType::QString, 6 }, { QMetaType::QString, 7 },
        }}),
        // Signal 'directoryLoaded'
        QtMocHelpers::SignalData<void(const QString &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'resolveSymlinks'
        QtMocHelpers::PropertyData<bool>(9, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'readOnly'
        QtMocHelpers::PropertyData<bool>(10, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'nameFilterDisables'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'options'
        QtMocHelpers::PropertyData<Options>(12, 0x80000000 | 13, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Option'
        QtMocHelpers::EnumData<Option>(14, 14, QMC::EnumFlags{}).add({
            {   15, Option::DontWatchForChanges },
            {   16, Option::DontResolveSymlinks },
            {   17, Option::DontUseCustomDirectoryIcons },
        }),
    };
    return QtMocHelpers::metaObjectData<QFileSystemModel, qt_meta_tag_ZN16QFileSystemModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFileSystemModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QFileSystemModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QFileSystemModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QFileSystemModelE_t>.metaTypes,
    nullptr
} };

void QFileSystemModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QFileSystemModel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->rootPathChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->fileRenamed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 2: _t->directoryLoaded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QFileSystemModel::*)(const QString & )>(_a, &QFileSystemModel::rootPathChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFileSystemModel::*)(const QString & , const QString & , const QString & )>(_a, &QFileSystemModel::fileRenamed, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFileSystemModel::*)(const QString & )>(_a, &QFileSystemModel::directoryLoaded, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->resolveSymlinks(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isReadOnly(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->nameFilterDisables(); break;
        case 3: *reinterpret_cast<Options*>(_v) = _t->options(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setResolveSymlinks(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setReadOnly(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setNameFilterDisables(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setOptions(*reinterpret_cast<Options*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QFileSystemModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFileSystemModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QFileSystemModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int QFileSystemModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QFileSystemModel::rootPathChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QFileSystemModel::fileRenamed(const QString & _t1, const QString & _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2, _t3);
}

// SIGNAL 2
void QFileSystemModel::directoryLoaded(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
