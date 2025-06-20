/****************************************************************************
** Meta object code from reading C++ file 'qlibrary.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/plugin/qlibrary.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlibrary.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8QLibraryE_t {};
} // unnamed namespace

template <> constexpr inline auto QLibrary::qt_create_metaobjectdata<qt_meta_tag_ZN8QLibraryE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QLibrary",
        "fileName",
        "loadHints",
        "LoadHints",
        "LoadHint",
        "ResolveAllSymbolsHint",
        "ExportExternalSymbolsHint",
        "LoadArchiveMemberHint",
        "PreventUnloadHint",
        "DeepBindHint"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'fileName'
        QtMocHelpers::PropertyData<QString>(1, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'loadHints'
        QtMocHelpers::PropertyData<LoadHints>(2, 0x80000000 | 3, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'LoadHint'
        QtMocHelpers::EnumData<LoadHint>(4, 4, QMC::EnumFlags{}).add({
            {    5, LoadHint::ResolveAllSymbolsHint },
            {    6, LoadHint::ExportExternalSymbolsHint },
            {    7, LoadHint::LoadArchiveMemberHint },
            {    8, LoadHint::PreventUnloadHint },
            {    9, LoadHint::DeepBindHint },
        }),
        // enum 'LoadHints'
        QtMocHelpers::EnumData<LoadHints>(3, 4, QMC::EnumFlags{}).add({
            {    5, LoadHint::ResolveAllSymbolsHint },
            {    6, LoadHint::ExportExternalSymbolsHint },
            {    7, LoadHint::LoadArchiveMemberHint },
            {    8, LoadHint::PreventUnloadHint },
            {    9, LoadHint::DeepBindHint },
        }),
    };
    return QtMocHelpers::metaObjectData<QLibrary, qt_meta_tag_ZN8QLibraryE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QLibrary::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QLibraryE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QLibraryE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8QLibraryE_t>.metaTypes,
    nullptr
} };

void QLibrary::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QLibrary *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->fileName(); break;
        case 1: QtMocHelpers::assignFlags<LoadHints>(_v, _t->loadHints()); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setFileName(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setLoadHints(*reinterpret_cast<LoadHints*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QLibrary::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLibrary::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8QLibraryE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QLibrary::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
