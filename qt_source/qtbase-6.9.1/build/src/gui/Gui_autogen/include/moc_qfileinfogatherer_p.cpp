/****************************************************************************
** Meta object code from reading C++ file 'qfileinfogatherer_p.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/itemmodels/qfileinfogatherer_p.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qfileinfogatherer_p.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN17QFileInfoGathererE_t {};
} // unnamed namespace

template <> constexpr inline auto QFileInfoGatherer::qt_create_metaobjectdata<qt_meta_tag_ZN17QFileInfoGathererE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QFileInfoGatherer",
        "updates",
        "",
        "directory",
        "QList<std::pair<QString,QFileInfo>>",
        "newListOfFiles",
        "listOfFiles",
        "nameResolved",
        "fileName",
        "resolvedName",
        "directoryLoaded",
        "path",
        "list",
        "directoryPath",
        "fetchExtendedInformation",
        "files",
        "updateFile",
        "setResolveSymlinks",
        "enable",
        "setIconProvider",
        "QAbstractFileIconProvider*",
        "provider",
        "driveAdded",
        "driveRemoved"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'updates'
        QtMocHelpers::SignalData<void(const QString &, const QList<std::pair<QString,QFileInfo>> &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { 0x80000000 | 4, 1 },
        }}),
        // Signal 'newListOfFiles'
        QtMocHelpers::SignalData<void(const QString &, const QStringList &) const>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 }, { QMetaType::QStringList, 6 },
        }}),
        // Signal 'nameResolved'
        QtMocHelpers::SignalData<void(const QString &, const QString &) const>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 8 }, { QMetaType::QString, 9 },
        }}),
        // Signal 'directoryLoaded'
        QtMocHelpers::SignalData<void(const QString &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 },
        }}),
        // Slot 'list'
        QtMocHelpers::SlotData<void(const QString &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 13 },
        }}),
        // Slot 'fetchExtendedInformation'
        QtMocHelpers::SlotData<void(const QString &, const QStringList &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 }, { QMetaType::QStringList, 15 },
        }}),
        // Slot 'updateFile'
        QtMocHelpers::SlotData<void(const QString &)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 11 },
        }}),
        // Slot 'setResolveSymlinks'
        QtMocHelpers::SlotData<void(bool)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 18 },
        }}),
        // Slot 'setIconProvider'
        QtMocHelpers::SlotData<void(QAbstractFileIconProvider *)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 20, 21 },
        }}),
        // Slot 'driveAdded'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'driveRemoved'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<QFileInfoGatherer, qt_meta_tag_ZN17QFileInfoGathererE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QFileInfoGatherer::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QFileInfoGathererE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QFileInfoGathererE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN17QFileInfoGathererE_t>.metaTypes,
    nullptr
} };

void QFileInfoGatherer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<QFileInfoGatherer *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->updates((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QList<std::pair<QString,QFileInfo>>>>(_a[2]))); break;
        case 1: _t->newListOfFiles((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 2: _t->nameResolved((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->directoryLoaded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->list((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->fetchExtendedInformation((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 6: _t->updateFile((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->setResolveSymlinks((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->setIconProvider((*reinterpret_cast< std::add_pointer_t<QAbstractFileIconProvider*>>(_a[1]))); break;
        case 9: _t->driveAdded(); break;
        case 10: _t->driveRemoved(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (QFileInfoGatherer::*)(const QString & , const QList<std::pair<QString,QFileInfo>> & )>(_a, &QFileInfoGatherer::updates, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFileInfoGatherer::*)(const QString & , const QStringList & ) const>(_a, &QFileInfoGatherer::newListOfFiles, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFileInfoGatherer::*)(const QString & , const QString & ) const>(_a, &QFileInfoGatherer::nameResolved, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (QFileInfoGatherer::*)(const QString & )>(_a, &QFileInfoGatherer::directoryLoaded, 3))
            return;
    }
}

const QMetaObject *QFileInfoGatherer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QFileInfoGatherer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN17QFileInfoGathererE_t>.strings))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int QFileInfoGatherer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QFileInfoGatherer::updates(const QString & _t1, const QList<std::pair<QString,QFileInfo>> & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void QFileInfoGatherer::newListOfFiles(const QString & _t1, const QStringList & _t2)const
{
    QMetaObject::activate<void>(const_cast< QFileInfoGatherer *>(this), &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void QFileInfoGatherer::nameResolved(const QString & _t1, const QString & _t2)const
{
    QMetaObject::activate<void>(const_cast< QFileInfoGatherer *>(this), &staticMetaObject, 2, nullptr, _t1, _t2);
}

// SIGNAL 3
void QFileInfoGatherer::directoryLoaded(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}
QT_WARNING_POP
