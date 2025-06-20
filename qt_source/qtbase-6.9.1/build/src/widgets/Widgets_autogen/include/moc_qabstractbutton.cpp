/****************************************************************************
** Meta object code from reading C++ file 'qabstractbutton.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qabstractbutton.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractbutton.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QAbstractButtonE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractButton::qt_create_metaobjectdata<qt_meta_tag_ZN15QAbstractButtonE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractButton",
        "pressed",
        "",
        "released",
        "clicked",
        "checked",
        "toggled",
        "setIconSize",
        "size",
        "animateClick",
        "click",
        "toggle",
        "setChecked",
        "text",
        "icon",
        "iconSize",
        "shortcut",
        "QKeySequence",
        "checkable",
        "autoRepeat",
        "autoExclusive",
        "autoRepeatDelay",
        "autoRepeatInterval",
        "down"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'pressed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'released'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'clicked'
        QtMocHelpers::SignalData<void(bool)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 },
        }}),
        // Signal 'clicked'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Signal 'toggled'
        QtMocHelpers::SignalData<void(bool)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 5 },
        }}),
        // Slot 'setIconSize'
        QtMocHelpers::SlotData<void(const QSize &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QSize, 8 },
        }}),
        // Slot 'animateClick'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'click'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'toggle'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setChecked'
        QtMocHelpers::SlotData<void(bool)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'text'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'icon'
        QtMocHelpers::PropertyData<QIcon>(14, QMetaType::QIcon, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'iconSize'
        QtMocHelpers::PropertyData<QSize>(15, QMetaType::QSize, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'shortcut'
        QtMocHelpers::PropertyData<QKeySequence>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'checkable'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'checked'
        QtMocHelpers::PropertyData<bool>(5, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 4),
        // property 'autoRepeat'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoExclusive'
        QtMocHelpers::PropertyData<bool>(20, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoRepeatDelay'
        QtMocHelpers::PropertyData<int>(21, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoRepeatInterval'
        QtMocHelpers::PropertyData<int>(22, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'down'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::Readable | QMC::Writable | QMC::Scriptable | QMC::Stored | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QAbstractButton, qt_meta_tag_ZN15QAbstractButtonE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractButtonE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractButtonE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QAbstractButtonE_t>.metaTypes,
    nullptr
} };

void QAbstractButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractButton *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->pressed(); break;
        case 1: _t->released(); break;
        case 2: _t->clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->clicked(); break;
        case 4: _t->toggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 5: _t->setIconSize((*reinterpret_cast< std::add_pointer_t<QSize>>(_a[1]))); break;
        case 6: _t->animateClick(); break;
        case 7: _t->click(); break;
        case 8: _t->toggle(); break;
        case 9: _t->setChecked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QAbstractButton::*)()>(_a, &QAbstractButton::pressed, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractButton::*)()>(_a, &QAbstractButton::released, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractButton::*)(bool )>(_a, &QAbstractButton::clicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QAbstractButton::*)(bool )>(_a, &QAbstractButton::toggled, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 1: *reinterpret_cast<QIcon*>(_v) = _t->icon(); break;
        case 2: *reinterpret_cast<QSize*>(_v) = _t->iconSize(); break;
        case 3: *reinterpret_cast<QKeySequence*>(_v) = _t->shortcut(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isCheckable(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isChecked(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->autoRepeat(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->autoExclusive(); break;
        case 8: *reinterpret_cast<int*>(_v) = _t->autoRepeatDelay(); break;
        case 9: *reinterpret_cast<int*>(_v) = _t->autoRepeatInterval(); break;
        case 10: *reinterpret_cast<bool*>(_v) = _t->isDown(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setIcon(*reinterpret_cast<QIcon*>(_v)); break;
        case 2: _t->setIconSize(*reinterpret_cast<QSize*>(_v)); break;
        case 3: _t->setShortcut(*reinterpret_cast<QKeySequence*>(_v)); break;
        case 4: _t->setCheckable(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setChecked(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setAutoRepeat(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setAutoExclusive(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setAutoRepeatDelay(*reinterpret_cast<int*>(_v)); break;
        case 9: _t->setAutoRepeatInterval(*reinterpret_cast<int*>(_v)); break;
        case 10: _t->setDown(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QAbstractButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QAbstractButtonE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QAbstractButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QAbstractButton::pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QAbstractButton::released()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QAbstractButton::clicked(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 4
void QAbstractButton::toggled(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
