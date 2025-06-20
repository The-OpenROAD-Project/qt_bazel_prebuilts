/****************************************************************************
** Meta object code from reading C++ file 'qvalidator.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/util/qvalidator.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qvalidator.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN10QValidatorE_t {};
} // unnamed namespace

template <> constexpr inline auto QValidator::qt_create_metaobjectdata<qt_meta_tag_ZN10QValidatorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QValidator",
        "changed",
        "",
        "State",
        "Invalid",
        "Intermediate",
        "Acceptable"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'changed'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'State'
        QtMocHelpers::EnumData<State>(3, 3, QMC::EnumFlags{}).add({
            {    4, State::Invalid },
            {    5, State::Intermediate },
            {    6, State::Acceptable },
        }),
    };
    return QtMocHelpers::metaObjectData<QValidator, qt_meta_tag_ZN10QValidatorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QValidator::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QValidatorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QValidatorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN10QValidatorE_t>.metaTypes,
    nullptr
} };

void QValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QValidator *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->changed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QValidator::*)()>(_a, &QValidator::changed, 0))
            return;
    }
}

const QMetaObject *QValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN10QValidatorE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QValidator::changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {
struct qt_meta_tag_ZN13QIntValidatorE_t {};
} // unnamed namespace

template <> constexpr inline auto QIntValidator::qt_create_metaobjectdata<qt_meta_tag_ZN13QIntValidatorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QIntValidator",
        "bottomChanged",
        "",
        "bottom",
        "topChanged",
        "top"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'bottomChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'topChanged'
        QtMocHelpers::SignalData<void(int)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 5 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'bottom'
        QtMocHelpers::PropertyData<int>(3, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'top'
        QtMocHelpers::PropertyData<int>(5, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QIntValidator, qt_meta_tag_ZN13QIntValidatorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QIntValidator::staticMetaObject = { {
    QMetaObject::SuperData::link<QValidator::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QIntValidatorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QIntValidatorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13QIntValidatorE_t>.metaTypes,
    nullptr
} };

void QIntValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QIntValidator *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->bottomChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->topChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QIntValidator::*)(int )>(_a, &QIntValidator::bottomChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QIntValidator::*)(int )>(_a, &QIntValidator::topChanged, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->bottom(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->top(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBottom(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setTop(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QIntValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QIntValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13QIntValidatorE_t>.strings))
        return static_cast<void*>(this);
    return QValidator::qt_metacast(_clname);
}

int QIntValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QValidator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QIntValidator::bottomChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QIntValidator::topChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN16QDoubleValidatorE_t {};
} // unnamed namespace

template <> constexpr inline auto QDoubleValidator::qt_create_metaobjectdata<qt_meta_tag_ZN16QDoubleValidatorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QDoubleValidator",
        "bottomChanged",
        "",
        "bottom",
        "topChanged",
        "top",
        "decimalsChanged",
        "decimals",
        "notationChanged",
        "QDoubleValidator::Notation",
        "notation",
        "Notation",
        "StandardNotation",
        "ScientificNotation"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'bottomChanged'
        QtMocHelpers::SignalData<void(double)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'topChanged'
        QtMocHelpers::SignalData<void(double)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 5 },
        }}),
        // Signal 'decimalsChanged'
        QtMocHelpers::SignalData<void(int)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Signal 'notationChanged'
        QtMocHelpers::SignalData<void(QDoubleValidator::Notation)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'bottom'
        QtMocHelpers::PropertyData<double>(3, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'top'
        QtMocHelpers::PropertyData<double>(5, QMetaType::Double, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'decimals'
        QtMocHelpers::PropertyData<int>(7, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'notation'
        QtMocHelpers::PropertyData<Notation>(10, 0x80000000 | 11, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 3),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Notation'
        QtMocHelpers::EnumData<Notation>(11, 11, QMC::EnumFlags{}).add({
            {   12, Notation::StandardNotation },
            {   13, Notation::ScientificNotation },
        }),
    };
    return QtMocHelpers::metaObjectData<QDoubleValidator, qt_meta_tag_ZN16QDoubleValidatorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QDoubleValidator::staticMetaObject = { {
    QMetaObject::SuperData::link<QValidator::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDoubleValidatorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDoubleValidatorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16QDoubleValidatorE_t>.metaTypes,
    nullptr
} };

void QDoubleValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QDoubleValidator *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->bottomChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->topChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->decimalsChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->notationChanged((*reinterpret_cast< std::add_pointer_t<QDoubleValidator::Notation>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QDoubleValidator::*)(double )>(_a, &QDoubleValidator::bottomChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDoubleValidator::*)(double )>(_a, &QDoubleValidator::topChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDoubleValidator::*)(int )>(_a, &QDoubleValidator::decimalsChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QDoubleValidator::*)(QDoubleValidator::Notation )>(_a, &QDoubleValidator::notationChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<double*>(_v) = _t->bottom(); break;
        case 1: *reinterpret_cast<double*>(_v) = _t->top(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->decimals(); break;
        case 3: *reinterpret_cast<Notation*>(_v) = _t->notation(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setBottom(*reinterpret_cast<double*>(_v)); break;
        case 1: _t->setTop(*reinterpret_cast<double*>(_v)); break;
        case 2: _t->setDecimals(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setNotation(*reinterpret_cast<Notation*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QDoubleValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDoubleValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16QDoubleValidatorE_t>.strings))
        return static_cast<void*>(this);
    return QValidator::qt_metacast(_clname);
}

int QDoubleValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QValidator::qt_metacall(_c, _id, _a);
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
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QDoubleValidator::bottomChanged(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QDoubleValidator::topChanged(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void QDoubleValidator::decimalsChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QDoubleValidator::notationChanged(QDoubleValidator::Notation _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN27QRegularExpressionValidatorE_t {};
} // unnamed namespace

template <> constexpr inline auto QRegularExpressionValidator::qt_create_metaobjectdata<qt_meta_tag_ZN27QRegularExpressionValidatorE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QRegularExpressionValidator",
        "regularExpressionChanged",
        "",
        "re",
        "setRegularExpression",
        "regularExpression"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'regularExpressionChanged'
        QtMocHelpers::SignalData<void(const QRegularExpression &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRegularExpression, 3 },
        }}),
        // Slot 'setRegularExpression'
        QtMocHelpers::SlotData<void(const QRegularExpression &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QRegularExpression, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'regularExpression'
        QtMocHelpers::PropertyData<QRegularExpression>(5, QMetaType::QRegularExpression, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QRegularExpressionValidator, qt_meta_tag_ZN27QRegularExpressionValidatorE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QRegularExpressionValidator::staticMetaObject = { {
    QMetaObject::SuperData::link<QValidator::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QRegularExpressionValidatorE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QRegularExpressionValidatorE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN27QRegularExpressionValidatorE_t>.metaTypes,
    nullptr
} };

void QRegularExpressionValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QRegularExpressionValidator *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->regularExpressionChanged((*reinterpret_cast< std::add_pointer_t<QRegularExpression>>(_a[1]))); break;
        case 1: _t->setRegularExpression((*reinterpret_cast< std::add_pointer_t<QRegularExpression>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QRegularExpressionValidator::*)(const QRegularExpression & )>(_a, &QRegularExpressionValidator::regularExpressionChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QRegularExpression*>(_v) = _t->regularExpression(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRegularExpression(*reinterpret_cast<QRegularExpression*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QRegularExpressionValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRegularExpressionValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN27QRegularExpressionValidatorE_t>.strings))
        return static_cast<void*>(this);
    return QValidator::qt_metacast(_clname);
}

int QRegularExpressionValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QValidator::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
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
void QRegularExpressionValidator::regularExpressionChanged(const QRegularExpression & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
