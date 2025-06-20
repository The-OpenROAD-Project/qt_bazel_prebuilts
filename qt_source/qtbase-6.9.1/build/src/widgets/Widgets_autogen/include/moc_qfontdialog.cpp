/****************************************************************************
** Meta object code from reading C++ file 'qfontdialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/dialogs/qfontdialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfontdialog.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QFontDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto QFontDialog::qt_create_metaobjectdata<qt_meta_tag_ZN11QFontDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFontDialog",
        "currentFontChanged",
        "",
        "font",
        "fontSelected",
        "currentFont",
        "options",
        "FontDialogOptions",
        "FontDialogOption",
        "NoButtons",
        "DontUseNativeDialog",
        "ScalableFonts",
        "NonScalableFonts",
        "MonospacedFonts",
        "ProportionalFonts"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'currentFontChanged'
        QtMocHelpers::SignalData<void(const QFont &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QFont, 3 },
        }}),
        // Signal 'fontSelected'
        QtMocHelpers::SignalData<void(const QFont &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QFont, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'currentFont'
        QtMocHelpers::PropertyData<QFont>(5, QMetaType::QFont, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'options'
        QtMocHelpers::PropertyData<FontDialogOptions>(6, 0x80000000 | 7, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'FontDialogOption'
        QtMocHelpers::EnumData<FontDialogOption>(8, 8, QMC::EnumFlags{}).add({
            {    9, FontDialogOption::NoButtons },
            {   10, FontDialogOption::DontUseNativeDialog },
            {   11, FontDialogOption::ScalableFonts },
            {   12, FontDialogOption::NonScalableFonts },
            {   13, FontDialogOption::MonospacedFonts },
            {   14, FontDialogOption::ProportionalFonts },
        }),
    };
    return QtMocHelpers::metaObjectData<QFontDialog, qt_meta_tag_ZN11QFontDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFontDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QFontDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QFontDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QFontDialogE_t>.metaTypes,
    nullptr
} };

void QFontDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QFontDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentFontChanged((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 1: _t->fontSelected((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QFontDialog::*)(const QFont & )>(_a, &QFontDialog::currentFontChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFontDialog::*)(const QFont & )>(_a, &QFontDialog::fontSelected, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QFont*>(_v) = _t->currentFont(); break;
        case 1: *reinterpret_cast<FontDialogOptions*>(_v) = _t->options(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentFont(*reinterpret_cast<QFont*>(_v)); break;
        case 1: _t->setOptions(*reinterpret_cast<FontDialogOptions*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QFontDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFontDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QFontDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QFontDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QFontDialog::currentFontChanged(const QFont & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QFontDialog::fontSelected(const QFont & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
