/****************************************************************************
** Meta object code from reading C++ file 'qmenu.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qmenu.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmenu.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN5QMenuE_t {};
} // unnamed namespace

template <> constexpr inline auto QMenu::qt_create_metaobjectdata<qt_meta_tag_ZN5QMenuE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QMenu",
        "aboutToShow",
        "",
        "aboutToHide",
        "triggered",
        "QAction*",
        "action",
        "hovered",
        "internalDelayedPopup",
        "_q_actionTriggered",
        "_q_actionHovered",
        "_q_overrideMenuActionDestroyed",
        "_q_platformMenuAboutToShow",
        "tearOffEnabled",
        "title",
        "icon",
        "separatorsCollapsible",
        "toolTipsVisible"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'aboutToShow'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'aboutToHide'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'triggered'
        QtMocHelpers::SignalData<void(QAction *)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Signal 'hovered'
        QtMocHelpers::SignalData<void(QAction *)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 5, 6 },
        }}),
        // Slot 'internalDelayedPopup'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_actionTriggered'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_actionHovered'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_overrideMenuActionDestroyed'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_platformMenuAboutToShow'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'tearOffEnabled'
        QtMocHelpers::PropertyData<bool>(13, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'title'
        QtMocHelpers::PropertyData<QString>(14, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'icon'
        QtMocHelpers::PropertyData<QIcon>(15, QMetaType::QIcon, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'separatorsCollapsible'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'toolTipsVisible'
        QtMocHelpers::PropertyData<bool>(17, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QMenu, qt_meta_tag_ZN5QMenuE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5QMenuE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5QMenuE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN5QMenuE_t>.metaTypes,
    nullptr
} };

void QMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QMenu *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->aboutToShow(); break;
        case 1: _t->aboutToHide(); break;
        case 2: _t->triggered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 3: _t->hovered((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        case 4: _t->internalDelayedPopup(); break;
        case 5: _t->d_func()->_q_actionTriggered(); break;
        case 6: _t->d_func()->_q_actionHovered(); break;
        case 7: _t->d_func()->_q_overrideMenuActionDestroyed(); break;
        case 8: _t->d_func()->_q_platformMenuAboutToShow(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QMenu::*)()>(_a, &QMenu::aboutToShow, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QMenu::*)()>(_a, &QMenu::aboutToHide, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QMenu::*)(QAction * )>(_a, &QMenu::triggered, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QMenu::*)(QAction * )>(_a, &QMenu::hovered, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->isTearOffEnabled(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->title(); break;
        case 2: *reinterpret_cast<QIcon*>(_v) = _t->icon(); break;
        case 3: *reinterpret_cast<bool*>(_v) = _t->separatorsCollapsible(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->toolTipsVisible(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTearOffEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setTitle(*reinterpret_cast<QString*>(_v)); break;
        case 2: _t->setIcon(*reinterpret_cast<QIcon*>(_v)); break;
        case 3: _t->setSeparatorsCollapsible(*reinterpret_cast<bool*>(_v)); break;
        case 4: _t->setToolTipsVisible(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN5QMenuE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QMenu::aboutToShow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QMenu::aboutToHide()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QMenu::triggered(QAction * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QMenu::hovered(QAction * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
