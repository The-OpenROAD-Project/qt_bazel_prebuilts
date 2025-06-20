/****************************************************************************
** Meta object code from reading C++ file 'qwizard.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/widgets/dialogs/qwizard.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwizard.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7QWizardE_t {};
} // unnamed namespace

template <> constexpr inline auto QWizard::qt_create_metaobjectdata<qt_meta_tag_ZN7QWizardE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QWizard",
        "currentIdChanged",
        "",
        "id",
        "helpRequested",
        "customButtonClicked",
        "which",
        "pageAdded",
        "pageRemoved",
        "back",
        "next",
        "setCurrentId",
        "restart",
        "_q_emitCustomButtonClicked",
        "_q_updateButtonStates",
        "_q_handleFieldObjectDestroyed",
        "wizardStyle",
        "WizardStyle",
        "options",
        "WizardOptions",
        "titleFormat",
        "Qt::TextFormat",
        "subTitleFormat",
        "startId",
        "currentId",
        "ClassicStyle",
        "ModernStyle",
        "MacStyle",
        "AeroStyle",
        "NStyles",
        "WizardOption",
        "IndependentPages",
        "IgnoreSubTitles",
        "ExtendedWatermarkPixmap",
        "NoDefaultButton",
        "NoBackButtonOnStartPage",
        "NoBackButtonOnLastPage",
        "DisabledBackButtonOnLastPage",
        "HaveNextButtonOnLastPage",
        "HaveFinishButtonOnEarlyPages",
        "NoCancelButton",
        "CancelButtonOnLeft",
        "HaveHelpButton",
        "HelpButtonOnRight",
        "HaveCustomButton1",
        "HaveCustomButton2",
        "HaveCustomButton3",
        "NoCancelButtonOnLastPage"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'currentIdChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'helpRequested'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'customButtonClicked'
        QtMocHelpers::SignalData<void(int)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 },
        }}),
        // Signal 'pageAdded'
        QtMocHelpers::SignalData<void(int)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Signal 'pageRemoved'
        QtMocHelpers::SignalData<void(int)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'back'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'next'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setCurrentId'
        QtMocHelpers::SlotData<void(int)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'restart'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_emitCustomButtonClicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_updateButtonStates'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_handleFieldObjectDestroyed'
        QtMocHelpers::SlotData<void(QObject *)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QObjectStar, 2 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'wizardStyle'
        QtMocHelpers::PropertyData<WizardStyle>(16, 0x80000000 | 17, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'options'
        QtMocHelpers::PropertyData<WizardOptions>(18, 0x80000000 | 19, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'titleFormat'
        QtMocHelpers::PropertyData<Qt::TextFormat>(20, 0x80000000 | 21, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'subTitleFormat'
        QtMocHelpers::PropertyData<Qt::TextFormat>(22, 0x80000000 | 21, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet),
        // property 'startId'
        QtMocHelpers::PropertyData<int>(23, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'currentId'
        QtMocHelpers::PropertyData<int>(24, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'WizardStyle'
        QtMocHelpers::EnumData<WizardStyle>(17, 17, QMC::EnumFlags{}).add({
            {   25, WizardStyle::ClassicStyle },
            {   26, WizardStyle::ModernStyle },
            {   27, WizardStyle::MacStyle },
            {   28, WizardStyle::AeroStyle },
            {   29, WizardStyle::NStyles },
        }),
        // enum 'WizardOption'
        QtMocHelpers::EnumData<WizardOption>(30, 30, QMC::EnumFlags{}).add({
            {   31, WizardOption::IndependentPages },
            {   32, WizardOption::IgnoreSubTitles },
            {   33, WizardOption::ExtendedWatermarkPixmap },
            {   34, WizardOption::NoDefaultButton },
            {   35, WizardOption::NoBackButtonOnStartPage },
            {   36, WizardOption::NoBackButtonOnLastPage },
            {   37, WizardOption::DisabledBackButtonOnLastPage },
            {   38, WizardOption::HaveNextButtonOnLastPage },
            {   39, WizardOption::HaveFinishButtonOnEarlyPages },
            {   40, WizardOption::NoCancelButton },
            {   41, WizardOption::CancelButtonOnLeft },
            {   42, WizardOption::HaveHelpButton },
            {   43, WizardOption::HelpButtonOnRight },
            {   44, WizardOption::HaveCustomButton1 },
            {   45, WizardOption::HaveCustomButton2 },
            {   46, WizardOption::HaveCustomButton3 },
            {   47, WizardOption::NoCancelButtonOnLastPage },
        }),
        // enum 'WizardOptions'
        QtMocHelpers::EnumData<WizardOptions>(19, 30, QMC::EnumFlags{}).add({
            {   31, WizardOption::IndependentPages },
            {   32, WizardOption::IgnoreSubTitles },
            {   33, WizardOption::ExtendedWatermarkPixmap },
            {   34, WizardOption::NoDefaultButton },
            {   35, WizardOption::NoBackButtonOnStartPage },
            {   36, WizardOption::NoBackButtonOnLastPage },
            {   37, WizardOption::DisabledBackButtonOnLastPage },
            {   38, WizardOption::HaveNextButtonOnLastPage },
            {   39, WizardOption::HaveFinishButtonOnEarlyPages },
            {   40, WizardOption::NoCancelButton },
            {   41, WizardOption::CancelButtonOnLeft },
            {   42, WizardOption::HaveHelpButton },
            {   43, WizardOption::HelpButtonOnRight },
            {   44, WizardOption::HaveCustomButton1 },
            {   45, WizardOption::HaveCustomButton2 },
            {   46, WizardOption::HaveCustomButton3 },
            {   47, WizardOption::NoCancelButtonOnLastPage },
        }),
    };
    return QtMocHelpers::metaObjectData<QWizard, qt_meta_tag_ZN7QWizardE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QWizard::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QWizardE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QWizardE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7QWizardE_t>.metaTypes,
    nullptr
} };

void QWizard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QWizard *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->currentIdChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->helpRequested(); break;
        case 2: _t->customButtonClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->pageAdded((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->pageRemoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->back(); break;
        case 6: _t->next(); break;
        case 7: _t->setCurrentId((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->restart(); break;
        case 9: _t->d_func()->_q_emitCustomButtonClicked(); break;
        case 10: _t->d_func()->_q_updateButtonStates(); break;
        case 11: _t->d_func()->_q_handleFieldObjectDestroyed((*reinterpret_cast< std::add_pointer_t<QObject*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QWizard::*)(int )>(_a, &QWizard::currentIdChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWizard::*)()>(_a, &QWizard::helpRequested, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWizard::*)(int )>(_a, &QWizard::customButtonClicked, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWizard::*)(int )>(_a, &QWizard::pageAdded, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (QWizard::*)(int )>(_a, &QWizard::pageRemoved, 4))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<WizardStyle*>(_v) = _t->wizardStyle(); break;
        case 1: QtMocHelpers::assignFlags<WizardOptions>(_v, _t->options()); break;
        case 2: *reinterpret_cast<Qt::TextFormat*>(_v) = _t->titleFormat(); break;
        case 3: *reinterpret_cast<Qt::TextFormat*>(_v) = _t->subTitleFormat(); break;
        case 4: *reinterpret_cast<int*>(_v) = _t->startId(); break;
        case 5: *reinterpret_cast<int*>(_v) = _t->currentId(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setWizardStyle(*reinterpret_cast<WizardStyle*>(_v)); break;
        case 1: _t->setOptions(*reinterpret_cast<WizardOptions*>(_v)); break;
        case 2: _t->setTitleFormat(*reinterpret_cast<Qt::TextFormat*>(_v)); break;
        case 3: _t->setSubTitleFormat(*reinterpret_cast<Qt::TextFormat*>(_v)); break;
        case 4: _t->setStartId(*reinterpret_cast<int*>(_v)); break;
        case 5: _t->setCurrentId(*reinterpret_cast<int*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QWizard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWizard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7QWizardE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QWizard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QWizard::currentIdChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void QWizard::helpRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QWizard::customButtonClicked(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void QWizard::pageAdded(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void QWizard::pageRemoved(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
namespace {
struct qt_meta_tag_ZN11QWizardPageE_t {};
} // unnamed namespace

template <> constexpr inline auto QWizardPage::qt_create_metaobjectdata<qt_meta_tag_ZN11QWizardPageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QWizardPage",
        "completeChanged",
        "",
        "_q_maybeEmitCompleteChanged",
        "_q_updateCachedCompleteState",
        "title",
        "subTitle"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'completeChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot '_q_maybeEmitCompleteChanged'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot '_q_updateCachedCompleteState'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'title'
        QtMocHelpers::PropertyData<QString>(5, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
        // property 'subTitle'
        QtMocHelpers::PropertyData<QString>(6, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QWizardPage, qt_meta_tag_ZN11QWizardPageE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QWizardPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QWizardPageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QWizardPageE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11QWizardPageE_t>.metaTypes,
    nullptr
} };

void QWizardPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QWizardPage *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->completeChanged(); break;
        case 1: _t->d_func()->_q_maybeEmitCompleteChanged(); break;
        case 2: _t->d_func()->_q_updateCachedCompleteState(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QWizardPage::*)()>(_a, &QWizardPage::completeChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QString*>(_v) = _t->title(); break;
        case 1: *reinterpret_cast<QString*>(_v) = _t->subTitle(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast<QString*>(_v)); break;
        case 1: _t->setSubTitle(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *QWizardPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QWizardPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11QWizardPageE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QWizardPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QWizardPage::completeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
