/****************************************************************************
** Meta object code from reading C++ file 'qfontvariableaxis.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/text/qfontvariableaxis.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfontvariableaxis.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QFontVariableAxisE_t {};
} // unnamed namespace

template <> constexpr inline auto QFontVariableAxis::qt_create_metaobjectdata<qt_meta_tag_ZN17QFontVariableAxisE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFontVariableAxis",
        "tag",
        "name",
        "minimumValue",
        "maximumValue",
        "defaultValue"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
        // property 'tag'
        QtMocHelpers::PropertyData<QByteArray>(1, QMetaType::QByteArray, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'name'
        QtMocHelpers::PropertyData<QString>(2, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'minimumValue'
        QtMocHelpers::PropertyData<qreal>(3, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'maximumValue'
        QtMocHelpers::PropertyData<qreal>(4, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Constant),
        // property 'defaultValue'
        QtMocHelpers::PropertyData<qreal>(5, QMetaType::QReal, QMC::DefaultPropertyFlags | QMC::Constant),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QFontVariableAxis, qt_meta_tag_ZN17QFontVariableAxisE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFontVariableAxis::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QFontVariableAxisE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QFontVariableAxisE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QFontVariableAxisE_t>.metaTypes,
    nullptr
} };

void QFontVariableAxis::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = reinterpret_cast<QFontVariableAxis *>(_o);
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QByteArray*>(_v) = _t->tagString(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast<qreal*>(_v) = _t->minimumValue(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->maximumValue(); break;
        case 4: *reinterpret_cast<qreal*>(_v) = _t->defaultValue(); break;
        default: break;
        }
    }
}
QT_WARNING_POP
