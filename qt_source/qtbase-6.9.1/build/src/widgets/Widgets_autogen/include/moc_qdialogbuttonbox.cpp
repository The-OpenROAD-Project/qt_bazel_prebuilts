/****************************************************************************
** Meta object code from reading C++ file 'qdialogbuttonbox.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/widgets/qdialogbuttonbox.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qdialogbuttonbox.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16QDialogButtonBoxE_t {};
} // unnamed namespace

template <> constexpr inline auto QDialogButtonBox::qt_create_metaobjectdata<qt_meta_tag_ZN16QDialogButtonBoxE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDialogButtonBox",
        "clicked",
        "",
        "QAbstractButton*",
        "button",
        "accepted",
        "helpRequested",
        "rejected",
        "orientation",
        "Qt::Orientation",
        "standardButtons",
        "StandardButtons",
        "centerButtons",
        "StandardButton",
        "NoButton",
        "Ok",
        "Save",
        "SaveAll",
        "Open",
        "Yes",
        "YesToAll",
        "No",
        "NoToAll",
        "Abort",
        "Retry",
        "Ignore",
        "Close",
        "Cancel",
        "Discard",
        "Help",
        "Apply",
        "Reset",
        "RestoreDefaults"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'clicked'
        QtMocHelpers::SignalData<void(QAbstractButton *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'accepted'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'helpRequested'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rejected'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'orientation'
        QtMocHelpers::PropertyData<Qt::Orientation>(8, 0x80000000 | 9, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'standardButtons'
        QtMocHelpers::PropertyData<StandardButtons>(10, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'centerButtons'
        QtMocHelpers::PropertyData<bool>(12, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'StandardButtons'
        QtMocHelpers::EnumData<StandardButtons>(11, 13, QMC::EnumFlags{}).add({
            {   14, StandardButton::NoButton },
            {   15, StandardButton::Ok },
            {   16, StandardButton::Save },
            {   17, StandardButton::SaveAll },
            {   18, StandardButton::Open },
            {   19, StandardButton::Yes },
            {   20, StandardButton::YesToAll },
            {   21, StandardButton::No },
            {   22, StandardButton::NoToAll },
            {   23, StandardButton::Abort },
            {   24, StandardButton::Retry },
            {   25, StandardButton::Ignore },
            {   26, StandardButton::Close },
            {   27, StandardButton::Cancel },
            {   28, StandardButton::Discard },
            {   29, StandardButton::Help },
            {   30, StandardButton::Apply },
            {   31, StandardButton::Reset },
            {   32, StandardButton::RestoreDefaults },
        }),
    };
    return QtMocHelpers::metaObjectData<QDialogButtonBox, qt_meta_tag_ZN16QDialogButtonBoxE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDialogButtonBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDialogButtonBoxE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDialogButtonBoxE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QDialogButtonBoxE_t>.metaTypes,
    nullptr
} };

void QDialogButtonBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDialogButtonBox *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->clicked((*reinterpret_cast< std::add_pointer_t<QAbstractButton*>>(_a[1]))); break;
        case 1: _t->accepted(); break;
        case 2: _t->helpRequested(); break;
        case 3: _t->rejected(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDialogButtonBox::*)(QAbstractButton * )>(_a, &QDialogButtonBox::clicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDialogButtonBox::*)()>(_a, &QDialogButtonBox::accepted, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDialogButtonBox::*)()>(_a, &QDialogButtonBox::helpRequested, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDialogButtonBox::*)()>(_a, &QDialogButtonBox::rejected, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<Qt::Orientation*>(_v) = _t->orientation(); break;
        case 1: QtMocHelpers::assignFlags<StandardButtons>(_v, _t->standardButtons()); break;
        case 2: *reinterpret_cast<bool*>(_v) = _t->centerButtons(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setOrientation(*reinterpret_cast<Qt::Orientation*>(_v)); break;
        case 1: _t->setStandardButtons(*reinterpret_cast<StandardButtons*>(_v)); break;
        case 2: _t->setCenterButtons(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QDialogButtonBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDialogButtonBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDialogButtonBoxE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QDialogButtonBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QDialogButtonBox::clicked(QAbstractButton * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QDialogButtonBox::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QDialogButtonBox::helpRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QDialogButtonBox::rejected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
