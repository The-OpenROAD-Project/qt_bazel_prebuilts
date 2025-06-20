/****************************************************************************
** Meta object code from reading C++ file 'qlcdnumber.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qlcdnumber.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlcdnumber.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QLCDNumberE_t {};
} // unnamed namespace

template <> constexpr inline auto QLCDNumber::qt_create_metaobjectdata<qt_meta_tag_ZN10QLCDNumberE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QLCDNumber",
        "overflow",
        "",
        "display",
        "str",
        "num",
        "setHexMode",
        "setDecMode",
        "setOctMode",
        "setBinMode",
        "setSmallDecimalPoint",
        "smallDecimalPoint",
        "digitCount",
        "mode",
        "Mode",
        "segmentStyle",
        "SegmentStyle",
        "value",
        "intValue",
        "Hex",
        "Dec",
        "Oct",
        "Bin",
        "Outline",
        "Filled",
        "Flat"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'overflow'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'display'
        QtMocHelpers::SlotData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'display'
        QtMocHelpers::SlotData<void(int)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
        // Slot 'display'
        QtMocHelpers::SlotData<void(double)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 5 },
        }}),
        // Slot 'setHexMode'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setDecMode'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setOctMode'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setBinMode'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setSmallDecimalPoint'
        QtMocHelpers::SlotData<void(bool)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'smallDecimalPoint'
        QtMocHelpers::PropertyData<bool>(11, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'digitCount'
        QtMocHelpers::PropertyData<int>(12, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'mode'
        QtMocHelpers::PropertyData<Mode>(13, 0x80000000 | 14, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'segmentStyle'
        QtMocHelpers::PropertyData<SegmentStyle>(15, 0x80000000 | 16, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'value'
        QtMocHelpers::PropertyData<double>(17, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable),
        // property 'intValue'
        QtMocHelpers::PropertyData<int>(18, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Mode'
        QtMocHelpers::EnumData<Mode>(14, 14, QMC::EnumFlags{}).add({
            {   19, Mode::Hex },
            {   20, Mode::Dec },
            {   21, Mode::Oct },
            {   22, Mode::Bin },
        }),
        // enum 'SegmentStyle'
        QtMocHelpers::EnumData<SegmentStyle>(16, 16, QMC::EnumFlags{}).add({
            {   23, SegmentStyle::Outline },
            {   24, SegmentStyle::Filled },
            {   25, SegmentStyle::Flat },
        }),
    };
    return QtMocHelpers::metaObjectData<QLCDNumber, qt_meta_tag_ZN10QLCDNumberE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QLCDNumber::staticMetaObject = { {
    QMetaObject::SuperData::link<QFrame::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QLCDNumberE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QLCDNumberE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QLCDNumberE_t>.metaTypes,
    nullptr
} };

void QLCDNumber::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QLCDNumber *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->overflow(); break;
        case 1: _t->display((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->display((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->display((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->setHexMode(); break;
        case 5: _t->setDecMode(); break;
        case 6: _t->setOctMode(); break;
        case 7: _t->setBinMode(); break;
        case 8: _t->setSmallDecimalPoint((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QLCDNumber::*)()>(_a, &QLCDNumber::overflow, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->smallDecimalPoint(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->digitCount(); break;
        case 2: *reinterpret_cast<Mode*>(_v) = _t->mode(); break;
        case 3: *reinterpret_cast<SegmentStyle*>(_v) = _t->segmentStyle(); break;
        case 4: *reinterpret_cast<double*>(_v) = _t->value(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->intValue(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSmallDecimalPoint(*reinterpret_cast<bool*>(_v)); break;
        case 1: _t->setDigitCount(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setMode(*reinterpret_cast<Mode*>(_v)); break;
        case 3: _t->setSegmentStyle(*reinterpret_cast<SegmentStyle*>(_v)); break;
        case 4: _t->display(*reinterpret_cast<double*>(_v)); break;
        case 5: _t->display(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QLCDNumber::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLCDNumber::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QLCDNumberE_t>.strings))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int QLCDNumber::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QLCDNumber::overflow()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
