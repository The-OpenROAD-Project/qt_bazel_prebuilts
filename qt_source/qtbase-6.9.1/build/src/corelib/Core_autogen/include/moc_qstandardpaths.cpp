/****************************************************************************
** Meta object code from reading C++ file 'qstandardpaths.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/io/qstandardpaths.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qstandardpaths.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN14QStandardPathsE_t {};
} // unnamed namespace

template <> constexpr inline auto QStandardPaths::qt_create_metaobjectdata<qt_meta_tag_ZN14QStandardPathsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QStandardPaths",
        "StandardLocation",
        "DesktopLocation",
        "DocumentsLocation",
        "FontsLocation",
        "ApplicationsLocation",
        "MusicLocation",
        "MoviesLocation",
        "PicturesLocation",
        "TempLocation",
        "HomeLocation",
        "AppLocalDataLocation",
        "CacheLocation",
        "GenericDataLocation",
        "RuntimeLocation",
        "ConfigLocation",
        "DownloadLocation",
        "GenericCacheLocation",
        "GenericConfigLocation",
        "AppDataLocation",
        "AppConfigLocation",
        "PublicShareLocation",
        "TemplatesLocation",
        "StateLocation",
        "GenericStateLocation",
        "LocateOptions",
        "LocateOption",
        "LocateFile",
        "LocateDirectory"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'StandardLocation'
        QtMocHelpers::EnumData<StandardLocation>(1, 1, QMC::EnumFlags{}).add({
            {    2, StandardLocation::DesktopLocation },
            {    3, StandardLocation::DocumentsLocation },
            {    4, StandardLocation::FontsLocation },
            {    5, StandardLocation::ApplicationsLocation },
            {    6, StandardLocation::MusicLocation },
            {    7, StandardLocation::MoviesLocation },
            {    8, StandardLocation::PicturesLocation },
            {    9, StandardLocation::TempLocation },
            {   10, StandardLocation::HomeLocation },
            {   11, StandardLocation::AppLocalDataLocation },
            {   12, StandardLocation::CacheLocation },
            {   13, StandardLocation::GenericDataLocation },
            {   14, StandardLocation::RuntimeLocation },
            {   15, StandardLocation::ConfigLocation },
            {   16, StandardLocation::DownloadLocation },
            {   17, StandardLocation::GenericCacheLocation },
            {   18, StandardLocation::GenericConfigLocation },
            {   19, StandardLocation::AppDataLocation },
            {   20, StandardLocation::AppConfigLocation },
            {   21, StandardLocation::PublicShareLocation },
            {   22, StandardLocation::TemplatesLocation },
            {   23, StandardLocation::StateLocation },
            {   24, StandardLocation::GenericStateLocation },
        }),
        // enum 'LocateOptions'
        QtMocHelpers::EnumData<LocateOptions>(25, 26, QMC::EnumFlags{}).add({
            {   27, LocateOption::LocateFile },
            {   28, LocateOption::LocateDirectory },
        }),
    };
    return QtMocHelpers::metaObjectData<QStandardPaths, qt_meta_tag_ZN14QStandardPathsE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QStandardPaths::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QStandardPathsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14QStandardPathsE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14QStandardPathsE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
