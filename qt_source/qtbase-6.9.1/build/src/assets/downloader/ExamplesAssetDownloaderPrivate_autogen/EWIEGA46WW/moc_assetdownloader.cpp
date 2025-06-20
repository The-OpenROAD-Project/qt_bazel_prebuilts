/****************************************************************************
** Meta object code from reading C++ file 'assetdownloader.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/assets/downloader/assetdownloader.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'assetdownloader.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6Assets10Downloader15AssetDownloaderE_t {};
} // unnamed namespace

template <> constexpr inline auto Assets::Downloader::AssetDownloader::qt_create_metaobjectdata<qt_meta_tag_ZN6Assets10Downloader15AssetDownloaderE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Assets::Downloader::AssetDownloader",
        "started",
        "",
        "finished",
        "success",
        "progressChanged",
        "progressValue",
        "progressMaximum",
        "progressText",
        "localDownloadDirChanged",
        "url",
        "downloadBaseChanged",
        "preferredLocalDownloadDirChanged",
        "offlineAssetsFilePathChanged",
        "jsonFileNameChanged",
        "zipFileNameChanged",
        "start",
        "networkErrors",
        "sslErrors",
        "downloadBase",
        "preferredLocalDownloadDir",
        "offlineAssetsFilePath",
        "jsonFileName",
        "zipFileName",
        "localDownloadDir"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'finished'
        QtMocHelpers::SignalData<void(bool)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 4 },
        }}),
        // Signal 'progressChanged'
        QtMocHelpers::SignalData<void(int, int, const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 7 }, { QMetaType::QString, 8 },
        }}),
        // Signal 'localDownloadDirChanged'
        QtMocHelpers::SignalData<void(const QUrl &)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 10 },
        }}),
        // Signal 'downloadBaseChanged'
        QtMocHelpers::SignalData<void(const QUrl &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 2 },
        }}),
        // Signal 'preferredLocalDownloadDirChanged'
        QtMocHelpers::SignalData<void(const QUrl &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 10 },
        }}),
        // Signal 'offlineAssetsFilePathChanged'
        QtMocHelpers::SignalData<void(const QUrl &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QUrl, 2 },
        }}),
        // Signal 'jsonFileNameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Signal 'zipFileNameChanged'
        QtMocHelpers::SignalData<void(const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 2 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'networkErrors'
        QtMocHelpers::MethodData<QStringList() const>(17, 2, QMC::AccessPublic, QMetaType::QStringList),
        // Method 'sslErrors'
        QtMocHelpers::MethodData<QStringList() const>(18, 2, QMC::AccessPublic, QMetaType::QStringList),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'downloadBase'
        QtMocHelpers::PropertyData<QUrl>(19, QMetaType::QUrl, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'preferredLocalDownloadDir'
        QtMocHelpers::PropertyData<QUrl>(20, QMetaType::QUrl, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'offlineAssetsFilePath'
        QtMocHelpers::PropertyData<QUrl>(21, QMetaType::QUrl, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'jsonFileName'
        QtMocHelpers::PropertyData<QString>(22, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'zipFileName'
        QtMocHelpers::PropertyData<QString>(23, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'localDownloadDir'
        QtMocHelpers::PropertyData<QUrl>(24, QMetaType::QUrl, QMC::DefaultPropertyFlags, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<AssetDownloader, qt_meta_tag_ZN6Assets10Downloader15AssetDownloaderE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Assets::Downloader::AssetDownloader::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6Assets10Downloader15AssetDownloaderE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6Assets10Downloader15AssetDownloaderE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6Assets10Downloader15AssetDownloaderE_t>.metaTypes,
    nullptr
} };

void Assets::Downloader::AssetDownloader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<AssetDownloader *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->finished((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->progressChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 3: _t->localDownloadDirChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 4: _t->downloadBaseChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 5: _t->preferredLocalDownloadDirChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 6: _t->offlineAssetsFilePathChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 7: _t->jsonFileNameChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->zipFileNameChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->start(); break;
        case 10: { QStringList _r = _t->networkErrors();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 11: { QStringList _r = _t->sslErrors();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)()>(_a, &AssetDownloader::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)(bool )>(_a, &AssetDownloader::finished, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)(int , int , const QString & )>(_a, &AssetDownloader::progressChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)(const QUrl & )>(_a, &AssetDownloader::localDownloadDirChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)(const QUrl & )>(_a, &AssetDownloader::downloadBaseChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)(const QUrl & )>(_a, &AssetDownloader::preferredLocalDownloadDirChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)(const QUrl & )>(_a, &AssetDownloader::offlineAssetsFilePathChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)(const QString & )>(_a, &AssetDownloader::jsonFileNameChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (AssetDownloader::*)(const QString & )>(_a, &AssetDownloader::zipFileNameChanged, 8))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QUrl*>(_v) = _t->downloadBase(); break;
        case 1: *reinterpret_cast<QUrl*>(_v) = _t->preferredLocalDownloadDir(); break;
        case 2: *reinterpret_cast<QUrl*>(_v) = _t->offlineAssetsFilePath(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->jsonFileName(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->zipFileName(); break;
        case 5: *reinterpret_cast<QUrl*>(_v) = _t->localDownloadDir(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDownloadBase(*reinterpret_cast<QUrl*>(_v)); break;
        case 1: _t->setPreferredLocalDownloadDir(*reinterpret_cast<QUrl*>(_v)); break;
        case 2: _t->setOfflineAssetsFilePath(*reinterpret_cast<QUrl*>(_v)); break;
        case 3: _t->setJsonFileName(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setZipFileName(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Assets::Downloader::AssetDownloader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Assets::Downloader::AssetDownloader::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6Assets10Downloader15AssetDownloaderE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Assets::Downloader::AssetDownloader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Assets::Downloader::AssetDownloader::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Assets::Downloader::AssetDownloader::finished(bool _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Assets::Downloader::AssetDownloader::progressChanged(int _t1, int _t2, const QString & _t3)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3);
}

// SIGNAL 3
void Assets::Downloader::AssetDownloader::localDownloadDirChanged(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void Assets::Downloader::AssetDownloader::downloadBaseChanged(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void Assets::Downloader::AssetDownloader::preferredLocalDownloadDirChanged(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void Assets::Downloader::AssetDownloader::offlineAssetsFilePathChanged(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void Assets::Downloader::AssetDownloader::jsonFileNameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}

// SIGNAL 8
void Assets::Downloader::AssetDownloader::zipFileNameChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}
QT_WARNING_POP
