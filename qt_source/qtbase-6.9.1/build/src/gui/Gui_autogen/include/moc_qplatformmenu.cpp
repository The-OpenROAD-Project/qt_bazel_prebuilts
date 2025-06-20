/****************************************************************************
** Meta object code from reading C++ file 'qplatformmenu.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qplatformmenu.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qplatformmenu.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QPlatformMenuItemE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformMenuItem::qt_create_metaobjectdata<qt_meta_tag_ZN17QPlatformMenuItemE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformMenuItem",
        "activated",
        "",
        "hovered",
        "MenuRole",
        "NoRole",
        "TextHeuristicRole",
        "ApplicationSpecificRole",
        "AboutQtRole",
        "AboutRole",
        "PreferencesRole",
        "QuitRole",
        "CutRole",
        "CopyRole",
        "PasteRole",
        "SelectAllRole",
        "RoleCount"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activated'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'hovered'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'MenuRole'
        QtMocHelpers::EnumData<MenuRole>(4, 4, QMC::EnumFlags{}).add({
            {    5, MenuRole::NoRole },
            {    6, MenuRole::TextHeuristicRole },
            {    7, MenuRole::ApplicationSpecificRole },
            {    8, MenuRole::AboutQtRole },
            {    9, MenuRole::AboutRole },
            {   10, MenuRole::PreferencesRole },
            {   11, MenuRole::QuitRole },
            {   12, MenuRole::CutRole },
            {   13, MenuRole::CopyRole },
            {   14, MenuRole::PasteRole },
            {   15, MenuRole::SelectAllRole },
            {   16, MenuRole::RoleCount },
        }),
    };
    return QtMocHelpers::metaObjectData<QPlatformMenuItem, qt_meta_tag_ZN17QPlatformMenuItemE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformMenuItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QPlatformMenuItemE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QPlatformMenuItemE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QPlatformMenuItemE_t>.metaTypes,
    nullptr
} };

void QPlatformMenuItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformMenuItem *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activated(); break;
        case 1: _t->hovered(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformMenuItem::*)()>(_a, &QPlatformMenuItem::activated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformMenuItem::*)()>(_a, &QPlatformMenuItem::hovered, 1))
            return;
    }
}

const QMetaObject *QPlatformMenuItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformMenuItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QPlatformMenuItemE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPlatformMenuItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QPlatformMenuItem::activated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QPlatformMenuItem::hovered()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN13QPlatformMenuE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformMenu::qt_create_metaobjectdata<qt_meta_tag_ZN13QPlatformMenuE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformMenu",
        "aboutToShow",
        "",
        "aboutToHide",
        "MenuType",
        "DefaultMenu",
        "EditMenu"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'aboutToShow'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'aboutToHide'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'MenuType'
        QtMocHelpers::EnumData<MenuType>(4, 4, QMC::EnumFlags{}).add({
            {    5, MenuType::DefaultMenu },
            {    6, MenuType::EditMenu },
        }),
    };
    return QtMocHelpers::metaObjectData<QPlatformMenu, qt_meta_tag_ZN13QPlatformMenuE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPlatformMenuE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPlatformMenuE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QPlatformMenuE_t>.metaTypes,
    nullptr
} };

void QPlatformMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformMenu *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->aboutToShow(); break;
        case 1: _t->aboutToHide(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QPlatformMenu::*)()>(_a, &QPlatformMenu::aboutToShow, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QPlatformMenu::*)()>(_a, &QPlatformMenu::aboutToHide, 1))
            return;
    }
}

const QMetaObject *QPlatformMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QPlatformMenuE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPlatformMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QPlatformMenu::aboutToShow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QPlatformMenu::aboutToHide()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {
struct qt_meta_tag_ZN16QPlatformMenuBarE_t {};
} // unnamed namespace

template <> constexpr inline auto QPlatformMenuBar::qt_create_metaobjectdata<qt_meta_tag_ZN16QPlatformMenuBarE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QPlatformMenuBar"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QPlatformMenuBar, qt_meta_tag_ZN16QPlatformMenuBarE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QPlatformMenuBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QPlatformMenuBarE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QPlatformMenuBarE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QPlatformMenuBarE_t>.metaTypes,
    nullptr
} };

void QPlatformMenuBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QPlatformMenuBar *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QPlatformMenuBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPlatformMenuBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QPlatformMenuBarE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPlatformMenuBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
