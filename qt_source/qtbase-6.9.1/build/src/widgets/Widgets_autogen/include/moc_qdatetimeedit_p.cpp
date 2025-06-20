/****************************************************************************
** Meta object code from reading C++ file 'qdatetimeedit_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qdatetimeedit_p.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdatetimeedit_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14QCalendarPopupE_t {};
} // unnamed namespace

template <> constexpr inline auto QCalendarPopup::qt_create_metaobjectdata<qt_meta_tag_ZN14QCalendarPopupE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCalendarPopup",
        "activated",
        "",
        "date",
        "newDateSelected",
        "newDate",
        "hidingCalendar",
        "oldDate",
        "resetButton",
        "dateSelected",
        "dateSelectionChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activated'
        QtMocHelpers::SignalData<void(QDate)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 3 },
        }}),
        // Signal 'newDateSelected'
        QtMocHelpers::SignalData<void(QDate)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 5 },
        }}),
        // Signal 'hidingCalendar'
        QtMocHelpers::SignalData<void(QDate)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 7 },
        }}),
        // Signal 'resetButton'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'dateSelected'
        QtMocHelpers::SlotData<void(QDate)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QDate, 3 },
        }}),
        // Slot 'dateSelectionChanged'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QCalendarPopup, qt_meta_tag_ZN14QCalendarPopupE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCalendarPopup::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QCalendarPopupE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QCalendarPopupE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QCalendarPopupE_t>.metaTypes,
    nullptr
} };

void QCalendarPopup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QCalendarPopup *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activated((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 1: _t->newDateSelected((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 2: _t->hidingCalendar((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 3: _t->resetButton(); break;
        case 4: _t->dateSelected((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 5: _t->dateSelectionChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QCalendarPopup::*)(QDate )>(_a, &QCalendarPopup::activated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCalendarPopup::*)(QDate )>(_a, &QCalendarPopup::newDateSelected, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCalendarPopup::*)(QDate )>(_a, &QCalendarPopup::hidingCalendar, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCalendarPopup::*)()>(_a, &QCalendarPopup::resetButton, 3))
            return;
    }
}

const QMetaObject *QCalendarPopup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCalendarPopup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QCalendarPopupE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QCalendarPopup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QCalendarPopup::activated(QDate _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QCalendarPopup::newDateSelected(QDate _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QCalendarPopup::hidingCalendar(QDate _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QCalendarPopup::resetButton()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
