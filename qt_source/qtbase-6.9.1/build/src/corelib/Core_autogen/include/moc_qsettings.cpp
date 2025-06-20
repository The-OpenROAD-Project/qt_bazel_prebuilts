/****************************************************************************
** Meta object code from reading C++ file 'qsettings.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/io/qsettings.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qsettings.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QSettingsE_t {};
} // unnamed namespace

template <> constexpr inline auto QSettings::qt_create_metaobjectdata<qt_meta_tag_ZN9QSettingsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QSettings",
        "Status",
        "NoError",
        "AccessError",
        "FormatError",
        "Format",
        "NativeFormat",
        "IniFormat",
        "InvalidFormat",
        "CustomFormat1",
        "CustomFormat2",
        "CustomFormat3",
        "CustomFormat4",
        "CustomFormat5",
        "CustomFormat6",
        "CustomFormat7",
        "CustomFormat8",
        "CustomFormat9",
        "CustomFormat10",
        "CustomFormat11",
        "CustomFormat12",
        "CustomFormat13",
        "CustomFormat14",
        "CustomFormat15",
        "CustomFormat16",
        "Scope",
        "UserScope",
        "SystemScope"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Status'
        QtMocHelpers::EnumData<Status>(1, 1, QMC::EnumFlags{}).add({
            {    2, Status::NoError },
            {    3, Status::AccessError },
            {    4, Status::FormatError },
        }),
        // enum 'Format'
        QtMocHelpers::EnumData<Format>(5, 5, QMC::EnumFlags{}).add({
            {    6, Format::NativeFormat },
            {    7, Format::IniFormat },
            {    8, Format::InvalidFormat },
            {    9, Format::CustomFormat1 },
            {   10, Format::CustomFormat2 },
            {   11, Format::CustomFormat3 },
            {   12, Format::CustomFormat4 },
            {   13, Format::CustomFormat5 },
            {   14, Format::CustomFormat6 },
            {   15, Format::CustomFormat7 },
            {   16, Format::CustomFormat8 },
            {   17, Format::CustomFormat9 },
            {   18, Format::CustomFormat10 },
            {   19, Format::CustomFormat11 },
            {   20, Format::CustomFormat12 },
            {   21, Format::CustomFormat13 },
            {   22, Format::CustomFormat14 },
            {   23, Format::CustomFormat15 },
            {   24, Format::CustomFormat16 },
        }),
        // enum 'Scope'
        QtMocHelpers::EnumData<Scope>(25, 25, QMC::EnumFlags{}).add({
            {   26, Scope::UserScope },
            {   27, Scope::SystemScope },
        }),
    };
    return QtMocHelpers::metaObjectData<QSettings, qt_meta_tag_ZN9QSettingsE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QSettings::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSettingsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSettingsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QSettingsE_t>.metaTypes,
    nullptr
} };

void QSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QSettings *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QSettingsE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
