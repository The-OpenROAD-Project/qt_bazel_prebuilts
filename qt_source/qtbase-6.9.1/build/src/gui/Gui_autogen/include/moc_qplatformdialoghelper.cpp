/****************************************************************************
** Meta object code from reading C++ file 'qplatformdialoghelper.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qplatformdialoghelper.h"
#include <QFont>
#include <QColor>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qplatformdialoghelper.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN21QPlatformDialogHelperE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformDialogHelper::qt_create_metaobjectdata<qt_meta_tag_ZN21QPlatformDialogHelperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformDialogHelper",
        "accept",
        "",
        "reject",
        "StandardButtons",
        "StandardButton",
        "NoButton",
        "Ok",
        "Save",
        "SaveAll",
        "Open",
        "Yes",
        "YesToAll",
        "No",
        "NoToAll",
        "Abort",
        "Retry",
        "Ignore",
        "Close",
        "Cancel",
        "Discard",
        "Help",
        "Apply",
        "Reset",
        "RestoreDefaults",
        "FirstButton",
        "LastButton",
        "LowestBit",
        "HighestBit",
        "ButtonRole",
        "InvalidRole",
        "AcceptRole",
        "RejectRole",
        "DestructiveRole",
        "ActionRole",
        "HelpRole",
        "YesRole",
        "NoRole",
        "ResetRole",
        "ApplyRole",
        "NRoles",
        "RoleMask",
        "AlternateRole",
        "Stretch",
        "Reverse",
        "EOL",
        "ButtonLayout",
        "UnknownLayout",
        "WinLayout",
        "MacLayout",
        "KdeLayout",
        "GnomeLayout",
        "AndroidLayout"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'accept'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'reject'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'StandardButtons'
        QtMocHelpers::EnumData<StandardButtons>(4, 5, QMC::EnumFlags{}).add({
            {    6, StandardButton::NoButton },
            {    7, StandardButton::Ok },
            {    8, StandardButton::Save },
            {    9, StandardButton::SaveAll },
            {   10, StandardButton::Open },
            {   11, StandardButton::Yes },
            {   12, StandardButton::YesToAll },
            {   13, StandardButton::No },
            {   14, StandardButton::NoToAll },
            {   15, StandardButton::Abort },
            {   16, StandardButton::Retry },
            {   17, StandardButton::Ignore },
            {   18, StandardButton::Close },
            {   19, StandardButton::Cancel },
            {   20, StandardButton::Discard },
            {   21, StandardButton::Help },
            {   22, StandardButton::Apply },
            {   23, StandardButton::Reset },
            {   24, StandardButton::RestoreDefaults },
            {   25, StandardButton::FirstButton },
            {   26, StandardButton::LastButton },
            {   27, StandardButton::LowestBit },
            {   28, StandardButton::HighestBit },
        }),
        // enum 'ButtonRole'
        QtMocHelpers::EnumData<ButtonRole>(29, 29, QMC::EnumFlags{}).add({
            {   30, ButtonRole::InvalidRole },
            {   31, ButtonRole::AcceptRole },
            {   32, ButtonRole::RejectRole },
            {   33, ButtonRole::DestructiveRole },
            {   34, ButtonRole::ActionRole },
            {   35, ButtonRole::HelpRole },
            {   36, ButtonRole::YesRole },
            {   37, ButtonRole::NoRole },
            {   38, ButtonRole::ResetRole },
            {   39, ButtonRole::ApplyRole },
            {   40, ButtonRole::NRoles },
            {   41, ButtonRole::RoleMask },
            {   42, ButtonRole::AlternateRole },
            {   43, ButtonRole::Stretch },
            {   44, ButtonRole::Reverse },
            {   45, ButtonRole::EOL },
        }),
        // enum 'ButtonLayout'
        QtMocHelpers::EnumData<ButtonLayout>(46, 46, QMC::EnumFlags{}).add({
            {   47, ButtonLayout::UnknownLayout },
            {   48, ButtonLayout::WinLayout },
            {   49, ButtonLayout::MacLayout },
            {   50, ButtonLayout::KdeLayout },
            {   51, ButtonLayout::GnomeLayout },
            {   52, ButtonLayout::AndroidLayout },
        }),
    };
    return QtMocHelpers::metaObjectData<QPlatformDialogHelper, qt_meta_tag_ZN21QPlatformDialogHelperE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformDialogHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QPlatformDialogHelperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QPlatformDialogHelperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QPlatformDialogHelperE_t>.metaTypes,
    nullptr
} };

void QPlatformDialogHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformDialogHelper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->accept(); break;
        case 1: _t->reject(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformDialogHelper::*)()>(_a, &QPlatformDialogHelper::accept, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformDialogHelper::*)()>(_a, &QPlatformDialogHelper::reject, 1))
            return;
    }
}

const QMetaObject *QPlatformDialogHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformDialogHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QPlatformDialogHelperE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPlatformDialogHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QPlatformDialogHelper::accept()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QPlatformDialogHelper::reject()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN19QColorDialogOptionsE_t {};
} // unnamed namespace

template <> constexpr inline auto QColorDialogOptions::qt_create_metaobjectdata<qt_meta_tag_ZN19QColorDialogOptionsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QColorDialogOptions",
        "ColorDialogOptions",
        "ColorDialogOption",
        "ShowAlphaChannel",
        "NoButtons",
        "DontUseNativeDialog",
        "NoEyeDropperButton"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ColorDialogOptions'
        QtMocHelpers::EnumData<ColorDialogOptions>(1, 2, QMC::EnumFlags{}).add({
            {    3, ColorDialogOption::ShowAlphaChannel },
            {    4, ColorDialogOption::NoButtons },
            {    5, ColorDialogOption::DontUseNativeDialog },
            {    6, ColorDialogOption::NoEyeDropperButton },
        }),
    };
    return QtMocHelpers::metaObjectData<QColorDialogOptions, qt_meta_tag_ZN19QColorDialogOptionsE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QColorDialogOptions::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QColorDialogOptionsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19QColorDialogOptionsE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19QColorDialogOptionsE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN26QPlatformColorDialogHelperE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformColorDialogHelper::qt_create_metaobjectdata<qt_meta_tag_ZN26QPlatformColorDialogHelperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformColorDialogHelper",
        "currentColorChanged",
        "",
        "color",
        "colorSelected"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'currentColorChanged'
        QtMocHelpers::SignalData<void(const QColor &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 3 },
        }}),
        // Signal 'colorSelected'
        QtMocHelpers::SignalData<void(const QColor &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QColor, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPlatformColorDialogHelper, qt_meta_tag_ZN26QPlatformColorDialogHelperE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformColorDialogHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformDialogHelper::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QPlatformColorDialogHelperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QPlatformColorDialogHelperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN26QPlatformColorDialogHelperE_t>.metaTypes,
    nullptr
} };

void QPlatformColorDialogHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformColorDialogHelper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentColorChanged((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 1: _t->colorSelected((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformColorDialogHelper::*)(const QColor & )>(_a, &QPlatformColorDialogHelper::currentColorChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformColorDialogHelper::*)(const QColor & )>(_a, &QPlatformColorDialogHelper::colorSelected, 1))
            return;
    }
}

const QMetaObject *QPlatformColorDialogHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformColorDialogHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN26QPlatformColorDialogHelperE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformDialogHelper::qt_metacast(_clname);
}

int QPlatformColorDialogHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformDialogHelper::qt_metacall(_c, _id, _a);
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
void QPlatformColorDialogHelper::currentColorChanged(const QColor & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QPlatformColorDialogHelper::colorSelected(const QColor & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN18QFontDialogOptionsE_t {};
} // unnamed namespace

template <> constexpr inline auto QFontDialogOptions::qt_create_metaobjectdata<qt_meta_tag_ZN18QFontDialogOptionsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFontDialogOptions",
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
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'FontDialogOptions'
        QtMocHelpers::EnumData<FontDialogOptions>(1, 2, QMC::EnumFlags{}).add({
            {    3, FontDialogOption::NoButtons },
            {    4, FontDialogOption::DontUseNativeDialog },
            {    5, FontDialogOption::ScalableFonts },
            {    6, FontDialogOption::NonScalableFonts },
            {    7, FontDialogOption::MonospacedFonts },
            {    8, FontDialogOption::ProportionalFonts },
        }),
    };
    return QtMocHelpers::metaObjectData<QFontDialogOptions, qt_meta_tag_ZN18QFontDialogOptionsE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFontDialogOptions::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QFontDialogOptionsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QFontDialogOptionsE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QFontDialogOptionsE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN25QPlatformFontDialogHelperE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformFontDialogHelper::qt_create_metaobjectdata<qt_meta_tag_ZN25QPlatformFontDialogHelperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformFontDialogHelper",
        "currentFontChanged",
        "",
        "font",
        "fontSelected"
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
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPlatformFontDialogHelper, qt_meta_tag_ZN25QPlatformFontDialogHelperE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformFontDialogHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformDialogHelper::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QPlatformFontDialogHelperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QPlatformFontDialogHelperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN25QPlatformFontDialogHelperE_t>.metaTypes,
    nullptr
} };

void QPlatformFontDialogHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformFontDialogHelper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentFontChanged((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 1: _t->fontSelected((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformFontDialogHelper::*)(const QFont & )>(_a, &QPlatformFontDialogHelper::currentFontChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformFontDialogHelper::*)(const QFont & )>(_a, &QPlatformFontDialogHelper::fontSelected, 1))
            return;
    }
}

const QMetaObject *QPlatformFontDialogHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformFontDialogHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QPlatformFontDialogHelperE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformDialogHelper::qt_metacast(_clname);
}

int QPlatformFontDialogHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformDialogHelper::qt_metacall(_c, _id, _a);
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
void QPlatformFontDialogHelper::currentFontChanged(const QFont & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QPlatformFontDialogHelper::fontSelected(const QFont & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN18QFileDialogOptionsE_t {};
} // unnamed namespace

template <> constexpr inline auto QFileDialogOptions::qt_create_metaobjectdata<qt_meta_tag_ZN18QFileDialogOptionsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFileDialogOptions",
        "ViewMode",
        "Detail",
        "List",
        "FileMode",
        "AnyFile",
        "ExistingFile",
        "Directory",
        "ExistingFiles",
        "DirectoryOnly",
        "AcceptMode",
        "AcceptOpen",
        "AcceptSave",
        "DialogLabel",
        "LookIn",
        "FileName",
        "FileType",
        "Accept",
        "Reject",
        "DialogLabelCount",
        "FileDialogOptions",
        "FileDialogOption",
        "ShowDirsOnly",
        "DontResolveSymlinks",
        "DontConfirmOverwrite",
        "DontUseNativeDialog",
        "ReadOnly",
        "HideNameFilterDetails",
        "DontUseCustomDirectoryIcons"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'ViewMode'
        QtMocHelpers::EnumData<ViewMode>(1, 1, QMC::EnumFlags{}).add({
            {    2, ViewMode::Detail },
            {    3, ViewMode::List },
        }),
        // enum 'FileMode'
        QtMocHelpers::EnumData<FileMode>(4, 4, QMC::EnumFlags{}).add({
            {    5, FileMode::AnyFile },
            {    6, FileMode::ExistingFile },
            {    7, FileMode::Directory },
            {    8, FileMode::ExistingFiles },
            {    9, FileMode::DirectoryOnly },
        }),
        // enum 'AcceptMode'
        QtMocHelpers::EnumData<AcceptMode>(10, 10, QMC::EnumFlags{}).add({
            {   11, AcceptMode::AcceptOpen },
            {   12, AcceptMode::AcceptSave },
        }),
        // enum 'DialogLabel'
        QtMocHelpers::EnumData<DialogLabel>(13, 13, QMC::EnumFlags{}).add({
            {   14, DialogLabel::LookIn },
            {   15, DialogLabel::FileName },
            {   16, DialogLabel::FileType },
            {   17, DialogLabel::Accept },
            {   18, DialogLabel::Reject },
            {   19, DialogLabel::DialogLabelCount },
        }),
        // enum 'FileDialogOptions'
        QtMocHelpers::EnumData<FileDialogOptions>(20, 21, QMC::EnumFlags{}).add({
            {   22, FileDialogOption::ShowDirsOnly },
            {   23, FileDialogOption::DontResolveSymlinks },
            {   24, FileDialogOption::DontConfirmOverwrite },
            {   25, FileDialogOption::DontUseNativeDialog },
            {   26, FileDialogOption::ReadOnly },
            {   27, FileDialogOption::HideNameFilterDetails },
            {   28, FileDialogOption::DontUseCustomDirectoryIcons },
        }),
    };
    return QtMocHelpers::metaObjectData<QFileDialogOptions, qt_meta_tag_ZN18QFileDialogOptionsE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFileDialogOptions::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QFileDialogOptionsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QFileDialogOptionsE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QFileDialogOptionsE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN25QPlatformFileDialogHelperE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformFileDialogHelper::qt_create_metaobjectdata<qt_meta_tag_ZN25QPlatformFileDialogHelperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformFileDialogHelper",
        "fileSelected",
        "",
        "file",
        "filesSelected",
        "QList<QUrl>",
        "files",
        "currentChanged",
        "path",
        "directoryEntered",
        "directory",
        "filterSelected",
        "filter"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'fileSelected'
        QtMocHelpers::SignalData<void(const QUrl &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 3 },
        }}),
        // Signal 'filesSelected'
        QtMocHelpers::SignalData<void(const QList<QUrl> &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Signal 'currentChanged'
        QtMocHelpers::SignalData<void(const QUrl &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 8 },
        }}),
        // Signal 'directoryEntered'
        QtMocHelpers::SignalData<void(const QUrl &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 10 },
        }}),
        // Signal 'filterSelected'
        QtMocHelpers::SignalData<void(const QString &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 12 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPlatformFileDialogHelper, qt_meta_tag_ZN25QPlatformFileDialogHelperE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformFileDialogHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformDialogHelper::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QPlatformFileDialogHelperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QPlatformFileDialogHelperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN25QPlatformFileDialogHelperE_t>.metaTypes,
    nullptr
} };

void QPlatformFileDialogHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformFileDialogHelper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->fileSelected((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 1: _t->filesSelected((*reinterpret_cast< std::add_pointer_t<QList<QUrl>>>(_a[1]))); break;
        case 2: _t->currentChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 3: _t->directoryEntered((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 4: _t->filterSelected((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QUrl> >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformFileDialogHelper::*)(const QUrl & )>(_a, &QPlatformFileDialogHelper::fileSelected, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformFileDialogHelper::*)(const QList<QUrl> & )>(_a, &QPlatformFileDialogHelper::filesSelected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformFileDialogHelper::*)(const QUrl & )>(_a, &QPlatformFileDialogHelper::currentChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformFileDialogHelper::*)(const QUrl & )>(_a, &QPlatformFileDialogHelper::directoryEntered, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformFileDialogHelper::*)(const QString & )>(_a, &QPlatformFileDialogHelper::filterSelected, 4))
            return;
    }
}

const QMetaObject *QPlatformFileDialogHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformFileDialogHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN25QPlatformFileDialogHelperE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformDialogHelper::qt_metacast(_clname);
}

int QPlatformFileDialogHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformDialogHelper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QPlatformFileDialogHelper::fileSelected(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QPlatformFileDialogHelper::filesSelected(const QList<QUrl> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QPlatformFileDialogHelper::currentChanged(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QPlatformFileDialogHelper::directoryEntered(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QPlatformFileDialogHelper::filterSelected(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN21QMessageDialogOptionsE_t {};
} // unnamed namespace

template <> constexpr inline auto QMessageDialogOptions::qt_create_metaobjectdata<qt_meta_tag_ZN21QMessageDialogOptionsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QMessageDialogOptions",
        "Options",
        "Option",
        "DontUseNativeDialog",
        "StandardIcon",
        "NoIcon",
        "Information",
        "Warning",
        "Critical",
        "Question"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Options'
        QtMocHelpers::EnumData<Options>(1, 2, QMC::EnumIsScoped).add({
            {    3, Option::DontUseNativeDialog },
        }),
        // enum 'StandardIcon'
        QtMocHelpers::EnumData<StandardIcon>(4, 4, QMC::EnumFlags{}).add({
            {    5, StandardIcon::NoIcon },
            {    6, StandardIcon::Information },
            {    7, StandardIcon::Warning },
            {    8, StandardIcon::Critical },
            {    9, StandardIcon::Question },
        }),
    };
    return QtMocHelpers::metaObjectData<QMessageDialogOptions, qt_meta_tag_ZN21QMessageDialogOptionsE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QMessageDialogOptions::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QMessageDialogOptionsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN21QMessageDialogOptionsE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN21QMessageDialogOptionsE_t>.metaTypes,
    nullptr
} };

namespace {
struct qt_meta_tag_ZN28QPlatformMessageDialogHelperE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformMessageDialogHelper::qt_create_metaobjectdata<qt_meta_tag_ZN28QPlatformMessageDialogHelperE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformMessageDialogHelper",
        "clicked",
        "",
        "QPlatformDialogHelper::StandardButton",
        "button",
        "QPlatformDialogHelper::ButtonRole",
        "role",
        "checkBoxStateChanged",
        "Qt::CheckState",
        "state"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'clicked'
        QtMocHelpers::SignalData<void(QPlatformDialogHelper::StandardButton, QPlatformDialogHelper::ButtonRole)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 5, 6 },
        }}),
        // Signal 'checkBoxStateChanged'
        QtMocHelpers::SignalData<void(Qt::CheckState)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 8, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPlatformMessageDialogHelper, qt_meta_tag_ZN28QPlatformMessageDialogHelperE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformMessageDialogHelper::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlatformDialogHelper::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QPlatformMessageDialogHelperE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QPlatformMessageDialogHelperE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN28QPlatformMessageDialogHelperE_t>.metaTypes,
    nullptr
} };

void QPlatformMessageDialogHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformMessageDialogHelper *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< std::add_pointer_t<QPlatformDialogHelper::StandardButton>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QPlatformDialogHelper::ButtonRole>>(_a[2]))); break;
        case 1: _t->checkBoxStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::CheckState>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPlatformDialogHelper::ButtonRole >(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPlatformDialogHelper::StandardButton >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformMessageDialogHelper::*)(QPlatformDialogHelper::StandardButton , QPlatformDialogHelper::ButtonRole )>(_a, &QPlatformMessageDialogHelper::clicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformMessageDialogHelper::*)(Qt::CheckState )>(_a, &QPlatformMessageDialogHelper::checkBoxStateChanged, 1))
            return;
    }
}

const QMetaObject *QPlatformMessageDialogHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformMessageDialogHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN28QPlatformMessageDialogHelperE_t>.strings))
        return static_cast<void*>(this);
    return QPlatformDialogHelper::qt_metacast(_clname);
}

int QPlatformMessageDialogHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlatformDialogHelper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QPlatformMessageDialogHelper::clicked(QPlatformDialogHelper::StandardButton _t1, QPlatformDialogHelper::ButtonRole _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QPlatformMessageDialogHelper::checkBoxStateChanged(Qt::CheckState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
