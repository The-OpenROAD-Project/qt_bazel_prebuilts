/****************************************************************************
** Meta object code from reading C++ file 'qabstractprintdialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/printsupport/dialogs/qabstractprintdialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qabstractprintdialog.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN20QAbstractPrintDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto QAbstractPrintDialog::qt_create_metaobjectdata<qt_meta_tag_ZN20QAbstractPrintDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QAbstractPrintDialog",
        "PrintDialogOption",
        "PrintToFile",
        "PrintSelection",
        "PrintPageRange",
        "PrintShowPageSize",
        "PrintCollateCopies",
        "PrintCurrentPage",
        "PrintDialogOptions"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'PrintDialogOption'
        QtMocHelpers::EnumData<PrintDialogOption>(1, 1, QMC::EnumFlags{}).add({
            {    2, PrintDialogOption::PrintToFile },
            {    3, PrintDialogOption::PrintSelection },
            {    4, PrintDialogOption::PrintPageRange },
            {    5, PrintDialogOption::PrintShowPageSize },
            {    6, PrintDialogOption::PrintCollateCopies },
            {    7, PrintDialogOption::PrintCurrentPage },
        }),
        // enum 'PrintDialogOptions'
        QtMocHelpers::EnumData<PrintDialogOptions>(8, 1, QMC::EnumFlags{}).add({
            {    2, PrintDialogOption::PrintToFile },
            {    3, PrintDialogOption::PrintSelection },
            {    4, PrintDialogOption::PrintPageRange },
            {    5, PrintDialogOption::PrintShowPageSize },
            {    6, PrintDialogOption::PrintCollateCopies },
            {    7, PrintDialogOption::PrintCurrentPage },
        }),
    };
    return QtMocHelpers::metaObjectData<QAbstractPrintDialog, qt_meta_tag_ZN20QAbstractPrintDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QAbstractPrintDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QAbstractPrintDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QAbstractPrintDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN20QAbstractPrintDialogE_t>.metaTypes,
    nullptr
} };

void QAbstractPrintDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QAbstractPrintDialog *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *QAbstractPrintDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAbstractPrintDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN20QAbstractPrintDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QAbstractPrintDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
