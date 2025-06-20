/****************************************************************************
** Meta object code from reading C++ file 'qstylehints.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qstylehints.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstylehints.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11QStyleHintsE_t {};
} // unnamed namespace

template <> constexpr inline auto QStyleHints::qt_create_metaobjectdata<qt_meta_tag_ZN11QStyleHintsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QStyleHints",
        "cursorFlashTimeChanged",
        "",
        "cursorFlashTime",
        "keyboardInputIntervalChanged",
        "keyboardInputInterval",
        "mouseDoubleClickIntervalChanged",
        "mouseDoubleClickInterval",
        "mousePressAndHoldIntervalChanged",
        "mousePressAndHoldInterval",
        "startDragDistanceChanged",
        "startDragDistance",
        "startDragTimeChanged",
        "startDragTime",
        "tabFocusBehaviorChanged",
        "Qt::TabFocusBehavior",
        "tabFocusBehavior",
        "useHoverEffectsChanged",
        "useHoverEffects",
        "showShortcutsInContextMenusChanged",
        "contextMenuTriggerChanged",
        "Qt::ContextMenuTrigger",
        "contextMenuTrigger",
        "wheelScrollLinesChanged",
        "scrollLines",
        "mouseQuickSelectionThresholdChanged",
        "threshold",
        "colorSchemeChanged",
        "Qt::ColorScheme",
        "colorScheme",
        "fontSmoothingGamma",
        "keyboardAutoRepeatRate",
        "keyboardAutoRepeatRateF",
        "passwordMaskCharacter",
        "passwordMaskDelay",
        "setFocusOnTouchRelease",
        "showIsFullScreen",
        "showIsMaximized",
        "showShortcutsInContextMenus",
        "startDragVelocity",
        "useRtlExtensions",
        "singleClickActivation",
        "wheelScrollLines",
        "mouseQuickSelectionThreshold",
        "mouseDoubleClickDistance",
        "touchDoubleTapDistance"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'cursorFlashTimeChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'keyboardInputIntervalChanged'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Signal 'mouseDoubleClickIntervalChanged'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Signal 'mousePressAndHoldIntervalChanged'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 9 },
        }}),
        // Signal 'startDragDistanceChanged'
        QtMocHelpers::SignalData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
        // Signal 'startDragTimeChanged'
        QtMocHelpers::SignalData<void(int)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 13 },
        }}),
        // Signal 'tabFocusBehaviorChanged'
        QtMocHelpers::SignalData<void(Qt::TabFocusBehavior)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Signal 'useHoverEffectsChanged'
        QtMocHelpers::SignalData<void(bool)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 },
        }}),
        // Signal 'showShortcutsInContextMenusChanged'
        QtMocHelpers::SignalData<void(bool)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
        // Signal 'contextMenuTriggerChanged'
        QtMocHelpers::SignalData<void(Qt::ContextMenuTrigger)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Signal 'wheelScrollLinesChanged'
        QtMocHelpers::SignalData<void(int)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 24 },
        }}),
        // Signal 'mouseQuickSelectionThresholdChanged'
        QtMocHelpers::SignalData<void(int)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 26 },
        }}),
        // Signal 'colorSchemeChanged'
        QtMocHelpers::SignalData<void(Qt::ColorScheme)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 28, 29 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'cursorFlashTime'
        QtMocHelpers::PropertyData<int>(3, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Final, 0),
        // property 'fontSmoothingGamma'
        QtMocHelpers::PropertyData<qreal>(30, QMetaType::QReal, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'keyboardAutoRepeatRate'
        QtMocHelpers::PropertyData<int>(31, QMetaType::Int, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'keyboardAutoRepeatRateF'
        QtMocHelpers::PropertyData<qreal>(32, QMetaType::QReal, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'keyboardInputInterval'
        QtMocHelpers::PropertyData<int>(5, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Final, 1),
        // property 'mouseDoubleClickInterval'
        QtMocHelpers::PropertyData<int>(7, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Final, 2),
        // property 'mousePressAndHoldInterval'
        QtMocHelpers::PropertyData<int>(9, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Final, 3),
        // property 'passwordMaskCharacter'
        QtMocHelpers::PropertyData<QChar>(33, QMetaType::QChar, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'passwordMaskDelay'
        QtMocHelpers::PropertyData<int>(34, QMetaType::Int, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'setFocusOnTouchRelease'
        QtMocHelpers::PropertyData<bool>(35, QMetaType::Bool, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'showIsFullScreen'
        QtMocHelpers::PropertyData<bool>(36, QMetaType::Bool, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'showIsMaximized'
        QtMocHelpers::PropertyData<bool>(37, QMetaType::Bool, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'showShortcutsInContextMenus'
        QtMocHelpers::PropertyData<bool>(38, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 8),
        // property 'contextMenuTrigger'
        QtMocHelpers::PropertyData<Qt::ContextMenuTrigger>(22, 0x80000000 | 21, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Final, 9),
        // property 'startDragDistance'
        QtMocHelpers::PropertyData<int>(11, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Final, 4),
        // property 'startDragTime'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Final, 5),
        // property 'startDragVelocity'
        QtMocHelpers::PropertyData<int>(39, QMetaType::Int, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'useRtlExtensions'
        QtMocHelpers::PropertyData<bool>(40, QMetaType::Bool, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'tabFocusBehavior'
        QtMocHelpers::PropertyData<Qt::TabFocusBehavior>(16, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Final, 6),
        // property 'singleClickActivation'
        QtMocHelpers::PropertyData<bool>(41, QMetaType::Bool, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'useHoverEffects'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 7),
        // property 'wheelScrollLines'
        QtMocHelpers::PropertyData<int>(42, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Final, 10),
        // property 'mouseQuickSelectionThreshold'
        QtMocHelpers::PropertyData<int>(43, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::Final, 11),
        // property 'mouseDoubleClickDistance'
        QtMocHelpers::PropertyData<int>(44, QMetaType::Int, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'touchDoubleTapDistance'
        QtMocHelpers::PropertyData<int>(45, QMetaType::Int, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant | QMC::Final),
        // property 'colorScheme'
        QtMocHelpers::PropertyData<Qt::ColorScheme>(29, 0x80000000 | 28, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::EnumOrFlag | QMC::StdCppSet | QMC::Final, 12),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QStyleHints, qt_meta_tag_ZN11QStyleHintsE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QStyleHints::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QStyleHintsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QStyleHintsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QStyleHintsE_t>.metaTypes,
    nullptr
} };

void QStyleHints::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QStyleHints *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->cursorFlashTimeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->keyboardInputIntervalChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->mouseDoubleClickIntervalChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->mousePressAndHoldIntervalChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->startDragDistanceChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->startDragTimeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->tabFocusBehaviorChanged((*reinterpret_cast< std::add_pointer_t<Qt::TabFocusBehavior>>(_a[1]))); break;
        case 7: _t->useHoverEffectsChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->showShortcutsInContextMenusChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->contextMenuTriggerChanged((*reinterpret_cast< std::add_pointer_t<Qt::ContextMenuTrigger>>(_a[1]))); break;
        case 10: _t->wheelScrollLinesChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->mouseQuickSelectionThresholdChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->colorSchemeChanged((*reinterpret_cast< std::add_pointer_t<Qt::ColorScheme>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(int )>(_a, &QStyleHints::cursorFlashTimeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(int )>(_a, &QStyleHints::keyboardInputIntervalChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(int )>(_a, &QStyleHints::mouseDoubleClickIntervalChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(int )>(_a, &QStyleHints::mousePressAndHoldIntervalChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(int )>(_a, &QStyleHints::startDragDistanceChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(int )>(_a, &QStyleHints::startDragTimeChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(Qt::TabFocusBehavior )>(_a, &QStyleHints::tabFocusBehaviorChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(bool )>(_a, &QStyleHints::useHoverEffectsChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(bool )>(_a, &QStyleHints::showShortcutsInContextMenusChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(Qt::ContextMenuTrigger )>(_a, &QStyleHints::contextMenuTriggerChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(int )>(_a, &QStyleHints::wheelScrollLinesChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(int )>(_a, &QStyleHints::mouseQuickSelectionThresholdChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QStyleHints::*)(Qt::ColorScheme )>(_a, &QStyleHints::colorSchemeChanged, 12))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->cursorFlashTime(); break;
        case 1: *reinterpret_cast<qreal*>(_v) = _t->fontSmoothingGamma(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->keyboardAutoRepeatRate(); break;
        case 3: *reinterpret_cast<qreal*>(_v) = _t->keyboardAutoRepeatRateF(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->keyboardInputInterval(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->mouseDoubleClickInterval(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->mousePressAndHoldInterval(); break;
        case 7: *reinterpret_cast<QChar*>(_v) = _t->passwordMaskCharacter(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->passwordMaskDelay(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->setFocusOnTouchRelease(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->showIsFullScreen(); break;
        case 11: *reinterpret_cast<bool*>(_v) = _t->showIsMaximized(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->showShortcutsInContextMenus(); break;
        case 13: *reinterpret_cast<Qt::ContextMenuTrigger*>(_v) = _t->contextMenuTrigger(); break;
        case 14: *reinterpret_cast<int*>(_v) = _t->startDragDistance(); break;
        case 15: *reinterpret_cast<int*>(_v) = _t->startDragTime(); break;
        case 16: *reinterpret_cast<int*>(_v) = _t->startDragVelocity(); break;
        case 17: *reinterpret_cast<bool*>(_v) = _t->useRtlExtensions(); break;
        case 18: *reinterpret_cast<Qt::TabFocusBehavior*>(_v) = _t->tabFocusBehavior(); break;
        case 19: *reinterpret_cast<bool*>(_v) = _t->singleClickActivation(); break;
        case 20: *reinterpret_cast<bool*>(_v) = _t->useHoverEffects(); break;
        case 21: *reinterpret_cast<int*>(_v) = _t->wheelScrollLines(); break;
        case 22: *reinterpret_cast<int*>(_v) = _t->mouseQuickSelectionThreshold(); break;
        case 23: *reinterpret_cast<int*>(_v) = _t->mouseDoubleClickDistance(); break;
        case 24: *reinterpret_cast<int*>(_v) = _t->touchDoubleTapDistance(); break;
        case 25: *reinterpret_cast<Qt::ColorScheme*>(_v) = _t->colorScheme(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 12: _t->setShowShortcutsInContextMenus(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setContextMenuTrigger(*reinterpret_cast<Qt::ContextMenuTrigger*>(_v)); break;
        case 20: _t->setUseHoverEffects(*reinterpret_cast<bool*>(_v)); break;
        case 22: _t->setMouseQuickSelectionThreshold(*reinterpret_cast<int*>(_v)); break;
        case 25: _t->setColorScheme(*reinterpret_cast<Qt::ColorScheme*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 25: _t->unsetColorScheme(); break;
        default: break;
        }
    }
}

const QMetaObject *QStyleHints::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStyleHints::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QStyleHintsE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QStyleHints::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void QStyleHints::cursorFlashTimeChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QStyleHints::keyboardInputIntervalChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QStyleHints::mouseDoubleClickIntervalChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QStyleHints::mousePressAndHoldIntervalChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QStyleHints::startDragDistanceChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void QStyleHints::startDragTimeChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QStyleHints::tabFocusBehaviorChanged(Qt::TabFocusBehavior _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QStyleHints::useHoverEffectsChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QStyleHints::showShortcutsInContextMenusChanged(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void QStyleHints::contextMenuTriggerChanged(Qt::ContextMenuTrigger _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void QStyleHints::wheelScrollLinesChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void QStyleHints::mouseQuickSelectionThresholdChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 11, nullptr, _t1);
}

// SIGNAL 12
void QStyleHints::colorSchemeChanged(Qt::ColorScheme _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}
QT_WARNING_POP
