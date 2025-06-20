/****************************************************************************
** Meta object code from reading C++ file 'qaction.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qaction.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qaction.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7QActionE_t {};
} // unnamed namespace

template <> constexpr inline auto QAction::qt_create_metaobjectdata<qt_meta_tag_ZN7QActionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAction",
        "changed",
        "",
        "enabledChanged",
        "enabled",
        "checkableChanged",
        "checkable",
        "visibleChanged",
        "triggered",
        "checked",
        "hovered",
        "toggled",
        "trigger",
        "hover",
        "setChecked",
        "toggle",
        "setEnabled",
        "resetEnabled",
        "setDisabled",
        "b",
        "setVisible",
        "icon",
        "text",
        "iconText",
        "toolTip",
        "statusTip",
        "whatsThis",
        "font",
        "shortcut",
        "QKeySequence",
        "shortcutContext",
        "Qt::ShortcutContext",
        "autoRepeat",
        "visible",
        "menuRole",
        "MenuRole",
        "iconVisibleInMenu",
        "shortcutVisibleInContextMenu",
        "priority",
        "Priority",
        "NoRole",
        "TextHeuristicRole",
        "ApplicationSpecificRole",
        "AboutQtRole",
        "AboutRole",
        "PreferencesRole",
        "QuitRole",
        "LowPriority",
        "NormalPriority",
        "HighPriority"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'changed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'enabledChanged'
        QtMocHelpers::SignalData<void(bool)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Signal 'checkableChanged'
        QtMocHelpers::SignalData<void(bool)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 6 },
        }}),
        // Signal 'visibleChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'triggered'
        QtMocHelpers::SignalData<void(bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Signal 'triggered'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Signal 'hovered'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'toggled'
        QtMocHelpers::SignalData<void(bool)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'trigger'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'hover'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setChecked'
        QtMocHelpers::SlotData<void(bool)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'toggle'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setEnabled'
        QtMocHelpers::SlotData<void(bool)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Slot 'resetEnabled'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setDisabled'
        QtMocHelpers::SlotData<void(bool)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 19 },
        }}),
        // Slot 'setVisible'
        QtMocHelpers::SlotData<void(bool)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'checkable'
        QtMocHelpers::PropertyData<bool>(6, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 2),
        // property 'checked'
        QtMocHelpers::PropertyData<bool>(9, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'enabled'
        QtMocHelpers::PropertyData<bool>(4, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet | QMC::Final, 1),
        // property 'icon'
        QtMocHelpers::PropertyData<QIcon>(21, QMetaType::QIcon, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'text'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'iconText'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'toolTip'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'statusTip'
        QtMocHelpers::PropertyData<QString>(25, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'whatsThis'
        QtMocHelpers::PropertyData<QString>(26, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'font'
        QtMocHelpers::PropertyData<QFont>(27, QMetaType::QFont, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'shortcut'
        QtMocHelpers::PropertyData<QKeySequence>(28, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'shortcutContext'
        QtMocHelpers::PropertyData<Qt::ShortcutContext>(30, 0x80000000 | 31, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'autoRepeat'
        QtMocHelpers::PropertyData<bool>(32, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'visible'
        QtMocHelpers::PropertyData<bool>(33, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 3),
        // property 'menuRole'
        QtMocHelpers::PropertyData<MenuRole>(34, 0x80000000 | 35, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
        // property 'iconVisibleInMenu'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'shortcutVisibleInContextMenu'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'priority'
        QtMocHelpers::PropertyData<Priority>(38, 0x80000000 | 39, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'MenuRole'
        QtMocHelpers::EnumData<MenuRole>(35, 35, QMC::EnumFlags{}).add({
            {   40, MenuRole::NoRole },
            {   41, MenuRole::TextHeuristicRole },
            {   42, MenuRole::ApplicationSpecificRole },
            {   43, MenuRole::AboutQtRole },
            {   44, MenuRole::AboutRole },
            {   45, MenuRole::PreferencesRole },
            {   46, MenuRole::QuitRole },
        }),
        // enum 'Priority'
        QtMocHelpers::EnumData<Priority>(39, 39, QMC::EnumFlags{}).add({
            {   47, Priority::LowPriority },
            {   48, Priority::NormalPriority },
            {   49, Priority::HighPriority },
        }),
    };
    return QtMocHelpers::metaObjectData<QAction, qt_meta_tag_ZN7QActionE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAction::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QActionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QActionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7QActionE_t>.metaTypes,
    nullptr
} };

void QAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAction *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->changed(); break;
        case 1: _t->enabledChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->checkableChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->visibleChanged(); break;
        case 4: _t->triggered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->triggered(); break;
        case 6: _t->hovered(); break;
        case 7: _t->toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->trigger(); break;
        case 9: _t->hover(); break;
        case 10: _t->setChecked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->toggle(); break;
        case 12: _t->setEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 13: _t->resetEnabled(); break;
        case 14: _t->setDisabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 15: _t->setVisible((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAction::*)()>(_a, &QAction::changed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAction::*)(bool )>(_a, &QAction::enabledChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAction::*)(bool )>(_a, &QAction::checkableChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAction::*)()>(_a, &QAction::visibleChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAction::*)(bool )>(_a, &QAction::triggered, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAction::*)()>(_a, &QAction::hovered, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAction::*)(bool )>(_a, &QAction::toggled, 7))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isCheckable(); break;
        case 1: *reinterpret_cast<bool*>(_v) = _t->isChecked(); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->isEnabled(); break;
        case 3: *reinterpret_cast<QIcon*>(_v) = _t->icon(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 5: *reinterpret_cast<QString*>(_v) = _t->iconText(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->toolTip(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->statusTip(); break;
        case 8: *reinterpret_cast<QString*>(_v) = _t->whatsThis(); break;
        case 9: *reinterpret_cast<QFont*>(_v) = _t->font(); break;
        case 10: *reinterpret_cast<QKeySequence*>(_v) = _t->shortcut(); break;
        case 11: *reinterpret_cast<Qt::ShortcutContext*>(_v) = _t->shortcutContext(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->autoRepeat(); break;
        case 13: *reinterpret_cast<bool*>(_v) = _t->isVisible(); break;
        case 14: *reinterpret_cast<MenuRole*>(_v) = _t->menuRole(); break;
        case 15: *reinterpret_cast<bool*>(_v) = _t->isIconVisibleInMenu(); break;
        case 16: *reinterpret_cast<bool*>(_v) = _t->isShortcutVisibleInContextMenu(); break;
        case 17: *reinterpret_cast<Priority*>(_v) = _t->priority(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCheckable(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setChecked(*reinterpret_cast<bool*>(_v)); break;
        case 2: _t->setEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 3: _t->setIcon(*reinterpret_cast<QIcon*>(_v)); break;
        case 4: _t->setText(*reinterpret_cast<QString*>(_v)); break;
        case 5: _t->setIconText(*reinterpret_cast<QString*>(_v)); break;
        case 6: _t->setToolTip(*reinterpret_cast<QString*>(_v)); break;
        case 7: _t->setStatusTip(*reinterpret_cast<QString*>(_v)); break;
        case 8: _t->setWhatsThis(*reinterpret_cast<QString*>(_v)); break;
        case 9: _t->setFont(*reinterpret_cast<QFont*>(_v)); break;
        case 10: _t->setShortcut(*reinterpret_cast<QKeySequence*>(_v)); break;
        case 11: _t->setShortcutContext(*reinterpret_cast<Qt::ShortcutContext*>(_v)); break;
        case 12: _t->setAutoRepeat(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setVisible(*reinterpret_cast<bool*>(_v)); break;
        case 14: _t->setMenuRole(*reinterpret_cast<MenuRole*>(_v)); break;
        case 15: _t->setIconVisibleInMenu(*reinterpret_cast<bool*>(_v)); break;
        case 16: _t->setShortcutVisibleInContextMenu(*reinterpret_cast<bool*>(_v)); break;
        case 17: _t->setPriority(*reinterpret_cast<Priority*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 2: _t->resetEnabled(); break;
        default: break;
        }
    }
}

const QMetaObject *QAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QActionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void QAction::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QAction::enabledChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QAction::checkableChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QAction::visibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QAction::triggered(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 6
void QAction::hovered()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QAction::toggled(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}
QT_WARNING_POP
