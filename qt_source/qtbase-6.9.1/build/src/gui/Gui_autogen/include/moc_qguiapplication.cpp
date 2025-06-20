/****************************************************************************
** Meta object code from reading C++ file 'qguiapplication.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qguiapplication.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qguiapplication.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QGuiApplicationE_t {};
} // unnamed namespace

template <> constexpr inline auto QGuiApplication::qt_create_metaobjectdata<qt_meta_tag_ZN15QGuiApplicationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QGuiApplication",
        "fontDatabaseChanged",
        "",
        "screenAdded",
        "QScreen*",
        "screen",
        "screenRemoved",
        "primaryScreenChanged",
        "lastWindowClosed",
        "focusObjectChanged",
        "focusObject",
        "focusWindowChanged",
        "QWindow*",
        "focusWindow",
        "applicationStateChanged",
        "Qt::ApplicationState",
        "state",
        "layoutDirectionChanged",
        "Qt::LayoutDirection",
        "direction",
        "commitDataRequest",
        "QSessionManager&",
        "sessionManager",
        "saveStateRequest",
        "applicationDisplayNameChanged",
        "paletteChanged",
        "pal",
        "fontChanged",
        "font",
        "setBadgeNumber",
        "number",
        "_q_updateFocusObject",
        "object",
        "windowIcon",
        "applicationDisplayName",
        "desktopFileName",
        "layoutDirection",
        "platformName",
        "quitOnLastWindowClosed",
        "primaryScreen"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'fontDatabaseChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'screenAdded'
        QtMocHelpers::SignalData<void(QScreen *)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'screenRemoved'
        QtMocHelpers::SignalData<void(QScreen *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'primaryScreenChanged'
        QtMocHelpers::SignalData<void(QScreen *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'lastWindowClosed'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusObjectChanged'
        QtMocHelpers::SignalData<void(QObject *)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 10 },
        }}),
        // Signal 'focusWindowChanged'
        QtMocHelpers::SignalData<void(QWindow *)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 13 },
        }}),
        // Signal 'applicationStateChanged'
        QtMocHelpers::SignalData<void(Qt::ApplicationState)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 15, 16 },
        }}),
        // Signal 'layoutDirectionChanged'
        QtMocHelpers::SignalData<void(Qt::LayoutDirection)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 18, 19 },
        }}),
        // Signal 'commitDataRequest'
        QtMocHelpers::SignalData<void(QSessionManager &)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Signal 'saveStateRequest'
        QtMocHelpers::SignalData<void(QSessionManager &)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 21, 22 },
        }}),
        // Signal 'applicationDisplayNameChanged'
        QtMocHelpers::SignalData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'paletteChanged'
        QtMocHelpers::SignalData<void(const QPalette &)>(25, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QPalette, 26 },
        }}),
        // Signal 'fontChanged'
        QtMocHelpers::SignalData<void(const QFont &)>(27, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QFont, 28 },
        }}),
        // Slot 'setBadgeNumber'
        QtMocHelpers::SlotData<void(qint64)>(29, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 30 },
        }}),
        // Slot '_q_updateFocusObject'
        QtMocHelpers::SlotData<void(QObject *)>(31, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QObjectStar, 32 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'windowIcon'
        QtMocHelpers::PropertyData<QIcon>(33, QMetaType::QIcon, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'applicationDisplayName'
        QtMocHelpers::PropertyData<QString>(34, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 11),
        // property 'desktopFileName'
        QtMocHelpers::PropertyData<QString>(35, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'layoutDirection'
        QtMocHelpers::PropertyData<Qt::LayoutDirection>(36, 0x80000000 | 18, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 8),
        // property 'platformName'
        QtMocHelpers::PropertyData<QString>(37, QMetaType::QString, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::Constant),
        // property 'quitOnLastWindowClosed'
        QtMocHelpers::PropertyData<bool>(38, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'primaryScreen'
        QtMocHelpers::PropertyData<QScreen*>(39, 0x80000000 | 4, QMC::Readable | QMC::Designable | QMC::Scriptable | QMC::EnumOrFlag, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QGuiApplication, qt_meta_tag_ZN15QGuiApplicationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QGuiApplication::staticMetaObject = { {
    QMetaObject::SuperData::link<QCoreApplication::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGuiApplicationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGuiApplicationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QGuiApplicationE_t>.metaTypes,
    nullptr
} };

void QGuiApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QGuiApplication *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->fontDatabaseChanged(); break;
        case 1: _t->screenAdded((*reinterpret_cast< std::add_pointer_t<QScreen*>>(_a[1]))); break;
        case 2: _t->screenRemoved((*reinterpret_cast< std::add_pointer_t<QScreen*>>(_a[1]))); break;
        case 3: _t->primaryScreenChanged((*reinterpret_cast< std::add_pointer_t<QScreen*>>(_a[1]))); break;
        case 4: _t->lastWindowClosed(); break;
        case 5: _t->focusObjectChanged((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        case 6: _t->focusWindowChanged((*reinterpret_cast< std::add_pointer_t<QWindow*>>(_a[1]))); break;
        case 7: _t->applicationStateChanged((*reinterpret_cast< std::add_pointer_t<Qt::ApplicationState>>(_a[1]))); break;
        case 8: _t->layoutDirectionChanged((*reinterpret_cast< std::add_pointer_t<Qt::LayoutDirection>>(_a[1]))); break;
        case 9: _t->commitDataRequest((*reinterpret_cast< std::add_pointer_t<QSessionManager&>>(_a[1]))); break;
        case 10: _t->saveStateRequest((*reinterpret_cast< std::add_pointer_t<QSessionManager&>>(_a[1]))); break;
        case 11: _t->applicationDisplayNameChanged(); break;
        case 12: _t->paletteChanged((*reinterpret_cast< std::add_pointer_t<QPalette>>(_a[1]))); break;
        case 13: _t->fontChanged((*reinterpret_cast< std::add_pointer_t<QFont>>(_a[1]))); break;
        case 14: _t->setBadgeNumber((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 15: _t->d_func()->_q_updateFocusObject((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)()>(_a, &QGuiApplication::fontDatabaseChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(QScreen * )>(_a, &QGuiApplication::screenAdded, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(QScreen * )>(_a, &QGuiApplication::screenRemoved, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(QScreen * )>(_a, &QGuiApplication::primaryScreenChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)()>(_a, &QGuiApplication::lastWindowClosed, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(QObject * )>(_a, &QGuiApplication::focusObjectChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(QWindow * )>(_a, &QGuiApplication::focusWindowChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(Qt::ApplicationState )>(_a, &QGuiApplication::applicationStateChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(Qt::LayoutDirection )>(_a, &QGuiApplication::layoutDirectionChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(QSessionManager & )>(_a, &QGuiApplication::commitDataRequest, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(QSessionManager & )>(_a, &QGuiApplication::saveStateRequest, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)()>(_a, &QGuiApplication::applicationDisplayNameChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(const QPalette & )>(_a, &QGuiApplication::paletteChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (QGuiApplication::*)(const QFont & )>(_a, &QGuiApplication::fontChanged, 13))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QIcon*>(_v) = _t->windowIcon(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->applicationDisplayName(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->desktopFileName(); break;
        case 3: *reinterpret_cast<Qt::LayoutDirection*>(_v) = _t->layoutDirection(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->platformName(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->quitOnLastWindowClosed(); break;
        case 6: *reinterpret_cast<QScreen**>(_v) = _t->primaryScreen(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWindowIcon(*reinterpret_cast<QIcon*>(_v)); break;
        case 1: _t->setApplicationDisplayName(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setDesktopFileName(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setLayoutDirection(*reinterpret_cast<Qt::LayoutDirection*>(_v)); break;
        case 5: _t->setQuitOnLastWindowClosed(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QGuiApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGuiApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QGuiApplicationE_t>.strings))
        return static_cast<void*>(this);
    return QCoreApplication::qt_metacast(_clname);
}

int QGuiApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCoreApplication::qt_metacall(_c, _id, _a);
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
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QGuiApplication::fontDatabaseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGuiApplication::screenAdded(QScreen * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QGuiApplication::screenRemoved(QScreen * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QGuiApplication::primaryScreenChanged(QScreen * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QGuiApplication::lastWindowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QGuiApplication::focusObjectChanged(QObject * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void QGuiApplication::focusWindowChanged(QWindow * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void QGuiApplication::applicationStateChanged(Qt::ApplicationState _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void QGuiApplication::layoutDirectionChanged(Qt::LayoutDirection _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void QGuiApplication::commitDataRequest(QSessionManager & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}

// SIGNAL 10
void QGuiApplication::saveStateRequest(QSessionManager & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 10, nullptr, _t1);
}

// SIGNAL 11
void QGuiApplication::applicationDisplayNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void QGuiApplication::paletteChanged(const QPalette & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 12, nullptr, _t1);
}

// SIGNAL 13
void QGuiApplication::fontChanged(const QFont & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 13, nullptr, _t1);
}
QT_WARNING_POP
