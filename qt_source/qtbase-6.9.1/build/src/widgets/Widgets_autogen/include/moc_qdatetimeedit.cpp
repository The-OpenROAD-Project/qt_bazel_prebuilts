/****************************************************************************
** Meta object code from reading C++ file 'qdatetimeedit.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qdatetimeedit.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdatetimeedit.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN13QDateTimeEditE_t {};
} // unnamed namespace

template <> constexpr inline auto QDateTimeEdit::qt_create_metaobjectdata<qt_meta_tag_ZN13QDateTimeEditE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDateTimeEdit",
        "dateTimeChanged",
        "",
        "dateTime",
        "timeChanged",
        "time",
        "dateChanged",
        "date",
        "setDateTime",
        "setDate",
        "setTime",
        "_q_resetButton",
        "maximumDateTime",
        "minimumDateTime",
        "maximumDate",
        "minimumDate",
        "maximumTime",
        "minimumTime",
        "currentSection",
        "Section",
        "displayedSections",
        "Sections",
        "displayFormat",
        "calendarPopup",
        "currentSectionIndex",
        "sectionCount",
        "timeSpec",
        "Qt::TimeSpec",
        "timeZone",
        "QTimeZone",
        "NoSection",
        "AmPmSection",
        "MSecSection",
        "SecondSection",
        "MinuteSection",
        "HourSection",
        "DaySection",
        "MonthSection",
        "YearSection",
        "TimeSections_Mask",
        "DateSections_Mask"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dateTimeChanged'
        QtMocHelpers::SignalData<void(const QDateTime &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDateTime, 3 },
        }}),
        // Signal 'timeChanged'
        QtMocHelpers::SignalData<void(QTime)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QTime, 5 },
        }}),
        // Signal 'dateChanged'
        QtMocHelpers::SignalData<void(QDate)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 7 },
        }}),
        // Slot 'setDateTime'
        QtMocHelpers::SlotData<void(const QDateTime &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDateTime, 3 },
        }}),
        // Slot 'setDate'
        QtMocHelpers::SlotData<void(QDate)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 7 },
        }}),
        // Slot 'setTime'
        QtMocHelpers::SlotData<void(QTime)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QTime, 5 },
        }}),
        // Slot '_q_resetButton'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'dateTime'
        QtMocHelpers::PropertyData<QDateTime>(3, QMetaType::QDateTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 0),
        // property 'date'
        QtMocHelpers::PropertyData<QDate>(7, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'time'
        QtMocHelpers::PropertyData<QTime>(5, QMetaType::QTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'maximumDateTime'
        QtMocHelpers::PropertyData<QDateTime>(12, QMetaType::QDateTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'minimumDateTime'
        QtMocHelpers::PropertyData<QDateTime>(13, QMetaType::QDateTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'maximumDate'
        QtMocHelpers::PropertyData<QDate>(14, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'minimumDate'
        QtMocHelpers::PropertyData<QDate>(15, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'maximumTime'
        QtMocHelpers::PropertyData<QTime>(16, QMetaType::QTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'minimumTime'
        QtMocHelpers::PropertyData<QTime>(17, QMetaType::QTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
        // property 'currentSection'
        QtMocHelpers::PropertyData<Section>(18, 0x80000000 | 19, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'displayedSections'
        QtMocHelpers::PropertyData<Sections>(20, 0x80000000 | 21, QMC::DefaultPropertyFlags | QMC::EnumOrFlag),
        // property 'displayFormat'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'calendarPopup'
        QtMocHelpers::PropertyData<bool>(23, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'currentSectionIndex'
        QtMocHelpers::PropertyData<int>(24, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'sectionCount'
        QtMocHelpers::PropertyData<int>(25, QMetaType::Int, QMC::DefaultPropertyFlags),
        // property 'timeSpec'
        QtMocHelpers::PropertyData<Qt::TimeSpec>(26, 0x80000000 | 27, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'timeZone'
        QtMocHelpers::PropertyData<QTimeZone>(28, 0x80000000 | 29, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Section'
        QtMocHelpers::EnumData<Section>(19, 19, QMC::EnumFlags{}).add({
            {   30, Section::NoSection },
            {   31, Section::AmPmSection },
            {   32, Section::MSecSection },
            {   33, Section::SecondSection },
            {   34, Section::MinuteSection },
            {   35, Section::HourSection },
            {   36, Section::DaySection },
            {   37, Section::MonthSection },
            {   38, Section::YearSection },
            {   39, Section::TimeSections_Mask },
            {   40, Section::DateSections_Mask },
        }),
        // enum 'Sections'
        QtMocHelpers::EnumData<Sections>(21, 19, QMC::EnumFlags{}).add({
            {   30, Section::NoSection },
            {   31, Section::AmPmSection },
            {   32, Section::MSecSection },
            {   33, Section::SecondSection },
            {   34, Section::MinuteSection },
            {   35, Section::HourSection },
            {   36, Section::DaySection },
            {   37, Section::MonthSection },
            {   38, Section::YearSection },
            {   39, Section::TimeSections_Mask },
            {   40, Section::DateSections_Mask },
        }),
    };
    return QtMocHelpers::metaObjectData<QDateTimeEdit, qt_meta_tag_ZN13QDateTimeEditE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDateTimeEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractSpinBox::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QDateTimeEditE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QDateTimeEditE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QDateTimeEditE_t>.metaTypes,
    nullptr
} };

void QDateTimeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDateTimeEdit *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dateTimeChanged((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 1: _t->timeChanged((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 2: _t->dateChanged((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 3: _t->setDateTime((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 4: _t->setDate((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 5: _t->setTime((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        case 6: _t->d_func()->_q_resetButton(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDateTimeEdit::*)(const QDateTime & )>(_a, &QDateTimeEdit::dateTimeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDateTimeEdit::*)(QTime )>(_a, &QDateTimeEdit::timeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDateTimeEdit::*)(QDate )>(_a, &QDateTimeEdit::dateChanged, 2))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QDateTime*>(_v) = _t->dateTime(); break;
        case 1: *reinterpret_cast<QDate*>(_v) = _t->date(); break;
        case 2: *reinterpret_cast<QTime*>(_v) = _t->time(); break;
        case 3: *reinterpret_cast<QDateTime*>(_v) = _t->maximumDateTime(); break;
        case 4: *reinterpret_cast<QDateTime*>(_v) = _t->minimumDateTime(); break;
        case 5: *reinterpret_cast<QDate*>(_v) = _t->maximumDate(); break;
        case 6: *reinterpret_cast<QDate*>(_v) = _t->minimumDate(); break;
        case 7: *reinterpret_cast<QTime*>(_v) = _t->maximumTime(); break;
        case 8: *reinterpret_cast<QTime*>(_v) = _t->minimumTime(); break;
        case 9: *reinterpret_cast<Section*>(_v) = _t->currentSection(); break;
        case 10: QtMocHelpers::assignFlags<Sections>(_v, _t->displayedSections()); break;
        case 11: *reinterpret_cast<QString*>(_v) = _t->displayFormat(); break;
        case 12: *reinterpret_cast<bool*>(_v) = _t->calendarPopup(); break;
        case 13: *reinterpret_cast<int*>(_v) = _t->currentSectionIndex(); break;
        case 14: *reinterpret_cast<int*>(_v) = _t->sectionCount(); break;
        case 15: *reinterpret_cast<Qt::TimeSpec*>(_v) = _t->timeSpec(); break;
        case 16: *reinterpret_cast<QTimeZone*>(_v) = _t->timeZone(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDateTime(*reinterpret_cast<QDateTime*>(_v)); break;
        case 1: _t->setDate(*reinterpret_cast<QDate*>(_v)); break;
        case 2: _t->setTime(*reinterpret_cast<QTime*>(_v)); break;
        case 3: _t->setMaximumDateTime(*reinterpret_cast<QDateTime*>(_v)); break;
        case 4: _t->setMinimumDateTime(*reinterpret_cast<QDateTime*>(_v)); break;
        case 5: _t->setMaximumDate(*reinterpret_cast<QDate*>(_v)); break;
        case 6: _t->setMinimumDate(*reinterpret_cast<QDate*>(_v)); break;
        case 7: _t->setMaximumTime(*reinterpret_cast<QTime*>(_v)); break;
        case 8: _t->setMinimumTime(*reinterpret_cast<QTime*>(_v)); break;
        case 9: _t->setCurrentSection(*reinterpret_cast<Section*>(_v)); break;
        case 11: _t->setDisplayFormat(*reinterpret_cast<QString*>(_v)); break;
        case 12: _t->setCalendarPopup(*reinterpret_cast<bool*>(_v)); break;
        case 13: _t->setCurrentSectionIndex(*reinterpret_cast<int*>(_v)); break;
        case 15: _t->setTimeSpec(*reinterpret_cast<Qt::TimeSpec*>(_v)); break;
        case 16: _t->setTimeZone(*reinterpret_cast<QTimeZone*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 3: _t->clearMaximumDateTime(); break;
        case 4: _t->clearMinimumDateTime(); break;
        case 5: _t->clearMaximumDate(); break;
        case 6: _t->clearMinimumDate(); break;
        case 7: _t->clearMaximumTime(); break;
        case 8: _t->clearMinimumTime(); break;
        default: break;
        }
    }
}

const QMetaObject *QDateTimeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDateTimeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QDateTimeEditE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractSpinBox::qt_metacast(_clname);
}

int QDateTimeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void QDateTimeEdit::dateTimeChanged(const QDateTime & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QDateTimeEdit::timeChanged(QTime _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QDateTimeEdit::dateChanged(QDate _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN9QTimeEditE_t {};
} // unnamed namespace

template <> constexpr inline auto QTimeEdit::qt_create_metaobjectdata<qt_meta_tag_ZN9QTimeEditE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QTimeEdit",
        "userTimeChanged",
        "",
        "time"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'userTimeChanged'
        QtMocHelpers::SignalData<void(QTime)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QTime, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'time'
        QtMocHelpers::PropertyData<QTime>(3, QMetaType::QTime, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QTimeEdit, qt_meta_tag_ZN9QTimeEditE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QTimeEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QDateTimeEdit::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTimeEditE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTimeEditE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QTimeEditE_t>.metaTypes,
    nullptr
} };

void QTimeEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QTimeEdit *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->userTimeChanged((*reinterpret_cast< std::add_pointer_t<QTime>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QTimeEdit::*)(QTime )>(_a, &QTimeEdit::userTimeChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QTime*>(_v) = _t->time(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTime(*reinterpret_cast<QTime*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QTimeEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTimeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QTimeEditE_t>.strings))
        return static_cast<void*>(this);
    return QDateTimeEdit::qt_metacast(_clname);
}

int QTimeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDateTimeEdit::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QTimeEdit::userTimeChanged(QTime _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN9QDateEditE_t {};
} // unnamed namespace

template <> constexpr inline auto QDateEdit::qt_create_metaobjectdata<qt_meta_tag_ZN9QDateEditE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDateEdit",
        "userDateChanged",
        "",
        "date"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'userDateChanged'
        QtMocHelpers::SignalData<void(QDate)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'date'
        QtMocHelpers::PropertyData<QDate>(3, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet | QMC::User, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QDateEdit, qt_meta_tag_ZN9QDateEditE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDateEdit::staticMetaObject = { {
    QMetaObject::SuperData::link<QDateTimeEdit::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QDateEditE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QDateEditE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9QDateEditE_t>.metaTypes,
    nullptr
} };

void QDateEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDateEdit *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->userDateChanged((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDateEdit::*)(QDate )>(_a, &QDateEdit::userDateChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QDate*>(_v) = _t->date(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDate(*reinterpret_cast<QDate*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QDateEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDateEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9QDateEditE_t>.strings))
        return static_cast<void*>(this);
    return QDateTimeEdit::qt_metacast(_clname);
}

int QDateEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDateTimeEdit::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QDateEdit::userDateChanged(QDate _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
