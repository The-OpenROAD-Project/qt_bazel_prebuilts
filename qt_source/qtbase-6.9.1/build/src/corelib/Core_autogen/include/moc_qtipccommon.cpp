/****************************************************************************
** Meta object code from reading C++ file 'qtipccommon.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/ipc/qtipccommon.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtipccommon.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QNativeIpcKeyE_t {};
} // unnamed namespace

template <> constexpr inline auto QNativeIpcKey::qt_create_metaobjectdata<qt_meta_tag_ZN13QNativeIpcKeyE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QNativeIpcKey",
        "Type",
        "SystemV",
        "PosixRealtime",
        "Windows"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Type'
        QtMocHelpers::EnumData<Type>(1, 1, QMC::EnumIsScoped).add({
            {    2, Type::SystemV },
            {    3, Type::PosixRealtime },
            {    4, Type::Windows },
        }),
    };
    return QtMocHelpers::metaObjectData<QNativeIpcKey, qt_meta_tag_ZN13QNativeIpcKeyE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QNativeIpcKey::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QNativeIpcKeyE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QNativeIpcKeyE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QNativeIpcKeyE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
