/****************************************************************************
** Meta object code from reading C++ file 'qapplication.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/kernel/qapplication.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qapplication.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QApplicationE_t {};
} // unnamed namespace

template <> constexpr inline auto QApplication::qt_create_metaobjectdata<qt_meta_tag_ZN12QApplicationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QApplication",
        "focusChanged",
        "",
        "QWidget*",
        "old",
        "now",
        "setStyleSheet",
        "sheet",
        "setAutoSipEnabled",
        "enabled",
        "closeAllWindows",
        "aboutQt",
        "cursorFlashTime",
        "doubleClickInterval",
        "keyboardInputInterval",
        "wheelScrollLines",
        "startDragTime",
        "startDragDistance",
        "styleSheet",
        "autoSipEnabled"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'focusChanged'
        QtMocHelpers::SignalData<void(QWidget *, QWidget *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 },
        }}),
        // Slot 'setStyleSheet'
        QtMocHelpers::SlotData<void(const QString &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'setAutoSipEnabled'
        QtMocHelpers::SlotData<void(const bool)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 9 },
        }}),
        // Slot 'closeAllWindows'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'aboutQt'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'cursorFlashTime'
        QtMocHelpers::PropertyData<int>(12, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'doubleClickInterval'
        QtMocHelpers::PropertyData<int>(13, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'keyboardInputInterval'
        QtMocHelpers::PropertyData<int>(14, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'wheelScrollLines'
        QtMocHelpers::PropertyData<int>(15, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'startDragTime'
        QtMocHelpers::PropertyData<int>(16, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'startDragDistance'
        QtMocHelpers::PropertyData<int>(17, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'styleSheet'
        QtMocHelpers::PropertyData<QString>(18, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoSipEnabled'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QApplication, qt_meta_tag_ZN12QApplicationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QApplication::staticMetaObject = { {
    QMetaObject::SuperData::link<QGuiApplication::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QApplicationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QApplicationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QApplicationE_t>.metaTypes,
    nullptr
} };

void QApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QApplication *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->focusChanged((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[2]))); break;
        case 1: _t->setStyleSheet((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->setAutoSipEnabled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->closeAllWindows(); break;
        case 4: _t->aboutQt(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QApplication::*)(QWidget * , QWidget * )>(_a, &QApplication::focusChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->cursorFlashTime(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->doubleClickInterval(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->keyboardInputInterval(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->wheelScrollLines(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->startDragTime(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->startDragDistance(); break;
        case 6: *reinterpret_cast<QString*>(_v) = _t->styleSheet(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->autoSipEnabled(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCursorFlashTime(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setDoubleClickInterval(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setKeyboardInputInterval(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setWheelScrollLines(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setStartDragTime(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setStartDragDistance(*reinterpret_cast<int*>(_v)); break;
        case 6: _t->setStyleSheet(*reinterpret_cast<QString*>(_v)); break;
        case 7: _t->setAutoSipEnabled(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QApplicationE_t>.strings))
        return static_cast<void*>(this);
    return QGuiApplication::qt_metacast(_clname);
}

int QApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGuiApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QApplication::focusChanged(QWidget * _t1, QWidget * _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}
QT_WARNING_POP
