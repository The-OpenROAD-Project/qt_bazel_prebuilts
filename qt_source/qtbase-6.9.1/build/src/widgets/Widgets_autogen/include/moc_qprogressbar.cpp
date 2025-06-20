/****************************************************************************
** Meta object code from reading C++ file 'qprogressbar.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qprogressbar.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qprogressbar.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QProgressBarE_t {};
} // unnamed namespace

template <> constexpr inline auto QProgressBar::qt_create_metaobjectdata<qt_meta_tag_ZN12QProgressBarE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QProgressBar",
        "valueChanged",
        "",
        "value",
        "reset",
        "setRange",
        "minimum",
        "maximum",
        "setMinimum",
        "setMaximum",
        "setValue",
        "setOrientation",
        "Qt::Orientation",
        "text",
        "alignment",
        "Qt::Alignment",
        "textVisible",
        "orientation",
        "invertedAppearance",
        "textDirection",
        "Direction",
        "format",
        "TopToBottom",
        "BottomToTop"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'valueChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'reset'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setRange'
        QtMocHelpers::SlotData<void(int, int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'setMinimum'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'setMaximum'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'setValue'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'setOrientation'
        QtMocHelpers::SlotData<void(Qt::Orientation)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'minimum'
        QtMocHelpers::PropertyData<int>(6, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maximum'
        QtMocHelpers::PropertyData<int>(7, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'text'
        QtMocHelpers::PropertyData<QString>(13, QMetaType::QString, QMC::DefaultPropertyFlags),
        // property 'value'
        QtMocHelpers::PropertyData<int>(3, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'alignment'
        QtMocHelpers::PropertyData<Qt::Alignment>(14, 0x80000000 | 15, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'textVisible'
        QtMocHelpers::PropertyData<bool>(16, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'orientation'
        QtMocHelpers::PropertyData<Qt::Orientation>(17, 0x80000000 | 12, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'invertedAppearance'
        QtMocHelpers::PropertyData<bool>(18, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'textDirection'
        QtMocHelpers::PropertyData<Direction>(19, 0x80000000 | 20, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'format'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::Resettable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Direction'
        QtMocHelpers::EnumData<Direction>(20, 20, QMC::EnumFlags{}).add({
            {   22, Direction::TopToBottom },
            {   23, Direction::BottomToTop },
        }),
    };
    return QtMocHelpers::metaObjectData<QProgressBar, qt_meta_tag_ZN12QProgressBarE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QProgressBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QProgressBarE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QProgressBarE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QProgressBarE_t>.metaTypes,
    nullptr
} };

void QProgressBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QProgressBar *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->reset(); break;
        case 2: _t->setRange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 3: _t->setMinimum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->setValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setOrientation((*reinterpret_cast< std::add_pointer_t<Qt::Orientation>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QProgressBar::*)(int )>(_a, &QProgressBar::valueChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->minimum(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->maximum(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->text(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->value(); break;
        case 4: *reinterpret_cast<Qt::Alignment*>(_v) = _t->alignment(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->isTextVisible(); break;
        case 6: *reinterpret_cast<Qt::Orientation*>(_v) = _t->orientation(); break;
        case 7: *reinterpret_cast<bool*>(_v) = _t->invertedAppearance(); break;
        case 8: *reinterpret_cast<Direction*>(_v) = _t->textDirection(); break;
        case 9: *reinterpret_cast<QString*>(_v) = _t->format(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMinimum(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setMaximum(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setValue(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setAlignment(*reinterpret_cast<Qt::Alignment*>(_v)); break;
        case 5: _t->setTextVisible(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setOrientation(*reinterpret_cast<Qt::Orientation*>(_v)); break;
        case 7: _t->setInvertedAppearance(*reinterpret_cast<bool*>(_v)); break;
        case 8: _t->setTextDirection(*reinterpret_cast<Direction*>(_v)); break;
        case 9: _t->setFormat(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
if (_c == QMetaObject::ResetProperty) {
        switch (_id) {
        case 9: _t->resetFormat(); break;
        default: break;
        }
    }
}

const QMetaObject *QProgressBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QProgressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QProgressBarE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QProgressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QProgressBar::valueChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
