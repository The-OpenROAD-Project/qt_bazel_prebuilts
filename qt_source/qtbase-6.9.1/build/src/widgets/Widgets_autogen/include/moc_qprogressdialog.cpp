/****************************************************************************
** Meta object code from reading C++ file 'qprogressdialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/dialogs/qprogressdialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qprogressdialog.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15QProgressDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto QProgressDialog::qt_create_metaobjectdata<qt_meta_tag_ZN15QProgressDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QProgressDialog",
        "canceled",
        "",
        "cancel",
        "reset",
        "setMaximum",
        "maximum",
        "setMinimum",
        "minimum",
        "setRange",
        "setValue",
        "progress",
        "setLabelText",
        "text",
        "setCancelButtonText",
        "setMinimumDuration",
        "ms",
        "forceShow",
        "_q_disconnectOnClose",
        "wasCanceled",
        "value",
        "autoReset",
        "autoClose",
        "minimumDuration",
        "labelText"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'canceled'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'cancel'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'reset'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setMaximum'
        QtMocHelpers::SlotData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Slot 'setMinimum'
        QtMocHelpers::SlotData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 },
        }}),
        // Slot 'setRange'
        QtMocHelpers::SlotData<void(int, int)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 8 }, { QMetaType::Int, 6 },
        }}),
        // Slot 'setValue'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 11 },
        }}),
        // Slot 'setLabelText'
        QtMocHelpers::SlotData<void(const QString &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 },
        }}),
        // Slot 'setCancelButtonText'
        QtMocHelpers::SlotData<void(const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 },
        }}),
        // Slot 'setMinimumDuration'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 16 },
        }}),
        // Slot 'forceShow'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessProtected, QMetaType::Void),
        // Slot '_q_disconnectOnClose'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'wasCanceled'
        QtMocHelpers::PropertyData<bool>(19, QMetaType::Bool, QMC::DefaultPropertyFlags),
        // property 'minimum'
        QtMocHelpers::PropertyData<int>(8, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'maximum'
        QtMocHelpers::PropertyData<int>(6, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'value'
        QtMocHelpers::PropertyData<int>(20, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoReset'
        QtMocHelpers::PropertyData<bool>(21, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'autoClose'
        QtMocHelpers::PropertyData<bool>(22, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'minimumDuration'
        QtMocHelpers::PropertyData<int>(23, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'labelText'
        QtMocHelpers::PropertyData<QString>(24, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QProgressDialog, qt_meta_tag_ZN15QProgressDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QProgressDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QProgressDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QProgressDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15QProgressDialogE_t>.metaTypes,
    nullptr
} };

void QProgressDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QProgressDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->canceled(); break;
        case 1: _t->cancel(); break;
        case 2: _t->reset(); break;
        case 3: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->setMinimum((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->setRange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->setValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->setLabelText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->setCancelButtonText((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->setMinimumDuration((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->forceShow(); break;
        case 11: _t->d_func()->_q_disconnectOnClose(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QProgressDialog::*)()>(_a, &QProgressDialog::canceled, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<bool*>(_v) = _t->wasCanceled(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->minimum(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->maximum(); break;
        case 3: *reinterpret_cast<int*>(_v) = _t->value(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->autoReset(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->autoClose(); break;
        case 6: *reinterpret_cast<int*>(_v) = _t->minimumDuration(); break;
        case 7: *reinterpret_cast<QString*>(_v) = _t->labelText(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1: _t->setMinimum(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setMaximum(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setValue(*reinterpret_cast<int*>(_v)); break;
        case 4: _t->setAutoReset(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setAutoClose(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setMinimumDuration(*reinterpret_cast<int*>(_v)); break;
        case 7: _t->setLabelText(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QProgressDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QProgressDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15QProgressDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QProgressDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
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
void QProgressDialog::canceled()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
