/****************************************************************************
** Meta object code from reading C++ file 'qcalendarwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qcalendarwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcalendarwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QCalendarWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto QCalendarWidget::qt_create_metaobjectdata<qt_meta_tag_ZN15QCalendarWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCalendarWidget",
        "selectionChanged",
        "",
        "clicked",
        "date",
        "activated",
        "currentPageChanged",
        "year",
        "month",
        "setSelectedDate",
        "setDateRange",
        "min",
        "max",
        "setCurrentPage",
        "setGridVisible",
        "show",
        "setNavigationBarVisible",
        "visible",
        "showNextMonth",
        "showPreviousMonth",
        "showNextYear",
        "showPreviousYear",
        "showSelectedDate",
        "showToday",
        "_q_slotShowDate",
        "_q_slotChangeDate",
        "changeMonth",
        "_q_editingFinished",
        "_q_prevMonthClicked",
        "_q_nextMonthClicked",
        "_q_yearEditingFinished",
        "_q_yearClicked",
        "_q_monthChanged",
        "QAction*",
        "act",
        "selectedDate",
        "minimumDate",
        "maximumDate",
        "firstDayOfWeek",
        "Qt::DayOfWeek",
        "gridVisible",
        "selectionMode",
        "SelectionMode",
        "horizontalHeaderFormat",
        "HorizontalHeaderFormat",
        "verticalHeaderFormat",
        "VerticalHeaderFormat",
        "navigationBarVisible",
        "dateEditEnabled",
        "dateEditAcceptDelay",
        "NoHorizontalHeader",
        "SingleLetterDayNames",
        "ShortDayNames",
        "LongDayNames",
        "NoVerticalHeader",
        "ISOWeekNumbers",
        "NoSelection",
        "SingleSelection"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'selectionChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'clicked'
        QtMocHelpers::SignalData<void(QDate)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 4 },
        }}),
        // Signal 'activated'
        QtMocHelpers::SignalData<void(QDate)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 4 },
        }}),
        // Signal 'currentPageChanged'
        QtMocHelpers::SignalData<void(int, int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { QMetaType::Int, 8 },
        }}),
        // Slot 'setSelectedDate'
        QtMocHelpers::SlotData<void(QDate)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 4 },
        }}),
        // Slot 'setDateRange'
        QtMocHelpers::SlotData<void(QDate, QDate)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 11 }, { QMetaType::QDate, 12 },
        }}),
        // Slot 'setCurrentPage'
        QtMocHelpers::SlotData<void(int, int)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 }, { QMetaType::Int, 8 },
        }}),
        // Slot 'setGridVisible'
        QtMocHelpers::SlotData<void(bool)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 15 },
        }}),
        // Slot 'setNavigationBarVisible'
        QtMocHelpers::SlotData<void(bool)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 17 },
        }}),
        // Slot 'showNextMonth'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showPreviousMonth'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showNextYear'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showPreviousYear'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showSelectedDate'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'showToday'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_slotShowDate'
        QtMocHelpers::SlotData<void(QDate)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QDate, 4 },
        }}),
        // Slot '_q_slotChangeDate'
        QtMocHelpers::SlotData<void(QDate)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QDate, 4 },
        }}),
        // Slot '_q_slotChangeDate'
        QtMocHelpers::SlotData<void(QDate, bool)>(25, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QDate, 4 }, { QMetaType::Bool, 26 },
        }}),
        // Slot '_q_editingFinished'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_prevMonthClicked'
        QtMocHelpers::SlotData<void()>(28, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_nextMonthClicked'
        QtMocHelpers::SlotData<void()>(29, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_yearEditingFinished'
        QtMocHelpers::SlotData<void()>(30, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_yearClicked'
        QtMocHelpers::SlotData<void()>(31, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_monthChanged'
        QtMocHelpers::SlotData<void(QAction *)>(32, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 33, 34 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'selectedDate'
        QtMocHelpers::PropertyData<QDate>(35, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'minimumDate'
        QtMocHelpers::PropertyData<QDate>(36, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'maximumDate'
        QtMocHelpers::PropertyData<QDate>(37, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'firstDayOfWeek'
        QtMocHelpers::PropertyData<Qt::DayOfWeek>(38, 0x80000000 | 39, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'gridVisible'
        QtMocHelpers::PropertyData<bool>(40, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'selectionMode'
        QtMocHelpers::PropertyData<SelectionMode>(41, 0x80000000 | 42, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'horizontalHeaderFormat'
        QtMocHelpers::PropertyData<HorizontalHeaderFormat>(43, 0x80000000 | 44, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'verticalHeaderFormat'
        QtMocHelpers::PropertyData<VerticalHeaderFormat>(45, 0x80000000 | 46, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'navigationBarVisible'
        QtMocHelpers::PropertyData<bool>(47, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'dateEditEnabled'
        QtMocHelpers::PropertyData<bool>(48, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'dateEditAcceptDelay'
        QtMocHelpers::PropertyData<int>(49, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'HorizontalHeaderFormat'
        QtMocHelpers::EnumData<HorizontalHeaderFormat>(44, 44, QMC::EnumFlags{}).add({
            {   50, HorizontalHeaderFormat::NoHorizontalHeader },
            {   51, HorizontalHeaderFormat::SingleLetterDayNames },
            {   52, HorizontalHeaderFormat::ShortDayNames },
            {   53, HorizontalHeaderFormat::LongDayNames },
        }),
        // enum 'VerticalHeaderFormat'
        QtMocHelpers::EnumData<VerticalHeaderFormat>(46, 46, QMC::EnumFlags{}).add({
            {   54, VerticalHeaderFormat::NoVerticalHeader },
            {   55, VerticalHeaderFormat::ISOWeekNumbers },
        }),
        // enum 'SelectionMode'
        QtMocHelpers::EnumData<SelectionMode>(42, 42, QMC::EnumFlags{}).add({
            {   56, SelectionMode::NoSelection },
            {   57, SelectionMode::SingleSelection },
        }),
    };
    return QtMocHelpers::metaObjectData<QCalendarWidget, qt_meta_tag_ZN15QCalendarWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCalendarWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QCalendarWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QCalendarWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QCalendarWidgetE_t>.metaTypes,
    nullptr
} };

void QCalendarWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QCalendarWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->selectionChanged(); break;
        case 1: _t->clicked((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 2: _t->activated((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 3: _t->currentPageChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->setSelectedDate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 5: _t->setDateRange((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDate>>(_a[2]))); break;
        case 6: _t->setCurrentPage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 7: _t->setGridVisible((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->setNavigationBarVisible((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->showNextMonth(); break;
        case 10: _t->showPreviousMonth(); break;
        case 11: _t->showNextYear(); break;
        case 12: _t->showPreviousYear(); break;
        case 13: _t->showSelectedDate(); break;
        case 14: _t->showToday(); break;
        case 15: _t->d_func()->_q_slotShowDate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 16: _t->d_func()->_q_slotChangeDate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 17: _t->d_func()->_q_slotChangeDate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 18: _t->d_func()->_q_editingFinished(); break;
        case 19: _t->d_func()->_q_prevMonthClicked(); break;
        case 20: _t->d_func()->_q_nextMonthClicked(); break;
        case 21: _t->d_func()->_q_yearEditingFinished(); break;
        case 22: _t->d_func()->_q_yearClicked(); break;
        case 23: _t->d_func()->_q_monthChanged((*reinterpret_cast< std::add_pointer_t<QAction*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 23:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAction* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QCalendarWidget::*)()>(_a, &QCalendarWidget::selectionChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCalendarWidget::*)(QDate )>(_a, &QCalendarWidget::clicked, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCalendarWidget::*)(QDate )>(_a, &QCalendarWidget::activated, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QCalendarWidget::*)(int , int )>(_a, &QCalendarWidget::currentPageChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QDate*>(_v) = _t->selectedDate(); break;
        case 1: *reinterpret_cast<QDate*>(_v) = _t->minimumDate(); break;
        case 2: *reinterpret_cast<QDate*>(_v) = _t->maximumDate(); break;
        case 3: *reinterpret_cast<Qt::DayOfWeek*>(_v) = _t->firstDayOfWeek(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->isGridVisible(); break;
        case 5: *reinterpret_cast<SelectionMode*>(_v) = _t->selectionMode(); break;
        case 6: *reinterpret_cast<HorizontalHeaderFormat*>(_v) = _t->horizontalHeaderFormat(); break;
        case 7: *reinterpret_cast<VerticalHeaderFormat*>(_v) = _t->verticalHeaderFormat(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->isNavigationBarVisible(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->isDateEditEnabled(); break;
        case 10: *reinterpret_cast<int*>(_v) = _t->dateEditAcceptDelay(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSelectedDate(*reinterpret_cast<QDate*>(_v)); break;
        case 1: _t->setMinimumDate(*reinterpret_cast<QDate*>(_v)); break;
        case 2: _t->setMaximumDate(*reinterpret_cast<QDate*>(_v)); break;
        case 3: _t->setFirstDayOfWeek(*reinterpret_cast<Qt::DayOfWeek*>(_v)); break;
        case 4: _t->setGridVisible(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setSelectionMode(*reinterpret_cast<SelectionMode*>(_v)); break;
        case 6: _t->setHorizontalHeaderFormat(*reinterpret_cast<HorizontalHeaderFormat*>(_v)); break;
        case 7: _t->setVerticalHeaderFormat(*reinterpret_cast<VerticalHeaderFormat*>(_v)); break;
        case 8: _t->setNavigationBarVisible(*reinterpret_cast<bool*>(_v)); break;
        case 9: _t->setDateEditEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 10: _t->setDateEditAcceptDelay(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 1: _t->clearMinimumDate(); break;
        case 2: _t->clearMaximumDate(); break;
        default: break;
        }
    }
}

const QMetaObject *QCalendarWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCalendarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QCalendarWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QCalendarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
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
void QCalendarWidget::selectionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QCalendarWidget::clicked(QDate _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QCalendarWidget::activated(QDate _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QCalendarWidget::currentPageChanged(int _t1, int _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2);
}
QT_WARNING_POP
