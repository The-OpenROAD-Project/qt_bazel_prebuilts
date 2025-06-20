/****************************************************************************
** Meta object code from reading C++ file 'qmainwindowlayout_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qmainwindowlayout_p.h"
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmainwindowlayout_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN22QDockWidgetGroupWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto QDockWidgetGroupWindow::qt_create_metaobjectdata<qt_meta_tag_ZN22QDockWidgetGroupWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDockWidgetGroupWindow",
        "resized",
        ""
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'resized'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDockWidgetGroupWindow, qt_meta_tag_ZN22QDockWidgetGroupWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDockWidgetGroupWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QDockWidgetGroupWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QDockWidgetGroupWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN22QDockWidgetGroupWindowE_t>.metaTypes,
    nullptr
} };

void QDockWidgetGroupWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDockWidgetGroupWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->resized(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDockWidgetGroupWindow::*)()>(_a, &QDockWidgetGroupWindow::resized, 0))
            return;
    }
}

const QMetaObject *QDockWidgetGroupWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDockWidgetGroupWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN22QDockWidgetGroupWindowE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QDockWidgetGroupWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QDockWidgetGroupWindow::resized()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN17QMainWindowLayoutE_t {};
} // unnamed namespace

template <> constexpr inline auto QMainWindowLayout::qt_create_metaobjectdata<qt_meta_tag_ZN17QMainWindowLayoutE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QMainWindowLayout",
        "updateGapIndicator",
        "",
        "tabChanged",
        "tabMoved",
        "from",
        "to"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'updateGapIndicator'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'tabChanged'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'tabMoved'
        QtMocHelpers::SlotData<void(int, int)>(4, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 5 }, { QMetaType::Int, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QMainWindowLayout, qt_meta_tag_ZN17QMainWindowLayoutE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QMainWindowLayout::staticMetaObject = { {
    QMetaObject::SuperData::link<QLayout::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QMainWindowLayoutE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QMainWindowLayoutE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QMainWindowLayoutE_t>.metaTypes,
    nullptr
} };

void QMainWindowLayout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QMainWindowLayout *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->updateGapIndicator(); break;
        case 1: _t->tabChanged(); break;
        case 2: _t->tabMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *QMainWindowLayout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMainWindowLayout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QMainWindowLayoutE_t>.strings))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QMainWindowLayoutSeparatorHelper<QMainWindowLayout>"))
        return static_cast< QMainWindowLayoutSeparatorHelper<QMainWindowLayout>*>(this);
    return QLayout::qt_metacast(_clname);
}

int QMainWindowLayout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLayout::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
