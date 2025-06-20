/****************************************************************************
** Meta object code from reading C++ file 'qmimetype.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/mimetypes/qmimetype.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmimetype.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9QMimeTypeE_t {};
} // unnamed namespace

template <> constexpr inline auto QMimeType::qt_create_metaobjectdata<qt_meta_tag_ZN9QMimeTypeE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QMimeType",
        "inherits",
        "",
        "mimeTypeName",
        "valid",
        "isDefault",
        "name",
        "comment",
        "genericIconName",
        "iconName",
        "globPatterns",
        "parentMimeTypes",
        "allAncestors",
        "aliases",
        "suffixes",
        "preferredSuffix",
        "filterString"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'inherits'
        QtMocHelpers::MethodData<bool(const QString &) const>(1, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'valid'
        QtMocHelpers::PropertyData<bool>(4, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'isDefault'
        QtMocHelpers::PropertyData<bool>(5, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'comment'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'genericIconName'
        QtMocHelpers::PropertyData<QString>(8, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'iconName'
        QtMocHelpers::PropertyData<QString>(9, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'globPatterns'
        QtMocHelpers::PropertyData<QStringList>(10, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'parentMimeTypes'
        QtMocHelpers::PropertyData<QStringList>(11, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'allAncestors'
        QtMocHelpers::PropertyData<QStringList>(12, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'aliases'
        QtMocHelpers::PropertyData<QStringList>(13, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'suffixes'
        QtMocHelpers::PropertyData<QStringList>(14, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'preferredSuffix'
        QtMocHelpers::PropertyData<QString>(15, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'filterString'
        QtMocHelpers::PropertyData<QString>(16, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QMimeType, qt_meta_tag_ZN9QMimeTypeE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QMimeType::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QMimeTypeE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QMimeTypeE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QMimeTypeE_t>.metaTypes,
    nullptr
} };

void QMimeType::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QMimeType *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = _t->inherits((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isValid(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isDefault(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->comment(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->genericIconName(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->iconName(); break;
        case 6: *reinterpret_cast<QStringList*>(_v) = _t->globPatterns(); break;
        case 7: *reinterpret_cast<QStringList*>(_v) = _t->parentMimeTypes(); break;
        case 8: *reinterpret_cast<QStringList*>(_v) = _t->allAncestors(); break;
        case 9: *reinterpret_cast<QStringList*>(_v) = _t->aliases(); break;
        case 10: *reinterpret_cast<QStringList*>(_v) = _t->suffixes(); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->preferredSuffix(); break;
        case 12: *reinterpret_cast<QString*>(_v) = _t->filterString(); break;
        default: break;
        }
    }
}
QT_WARNING_POP
