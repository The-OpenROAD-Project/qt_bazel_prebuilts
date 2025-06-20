/****************************************************************************
** Meta object code from reading C++ file 'qimage.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/image/qimage.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qimage.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6QImageE_t {};
} // unnamed namespace

template <> constexpr inline auto QImage::qt_create_metaobjectdata<qt_meta_tag_ZN6QImageE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QImage",
        "Format",
        "Format_Invalid",
        "Format_Mono",
        "Format_MonoLSB",
        "Format_Indexed8",
        "Format_RGB32",
        "Format_ARGB32",
        "Format_ARGB32_Premultiplied",
        "Format_RGB16",
        "Format_ARGB8565_Premultiplied",
        "Format_RGB666",
        "Format_ARGB6666_Premultiplied",
        "Format_RGB555",
        "Format_ARGB8555_Premultiplied",
        "Format_RGB888",
        "Format_RGB444",
        "Format_ARGB4444_Premultiplied",
        "Format_RGBX8888",
        "Format_RGBA8888",
        "Format_RGBA8888_Premultiplied",
        "Format_BGR30",
        "Format_A2BGR30_Premultiplied",
        "Format_RGB30",
        "Format_A2RGB30_Premultiplied",
        "Format_Alpha8",
        "Format_Grayscale8",
        "Format_RGBX64",
        "Format_RGBA64",
        "Format_RGBA64_Premultiplied",
        "Format_Grayscale16",
        "Format_BGR888",
        "Format_RGBX16FPx4",
        "Format_RGBA16FPx4",
        "Format_RGBA16FPx4_Premultiplied",
        "Format_RGBX32FPx4",
        "Format_RGBA32FPx4",
        "Format_RGBA32FPx4_Premultiplied",
        "Format_CMYK8888",
        "NImageFormats"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Format'
        QtMocHelpers::EnumData<Format>(1, 1, QMC::EnumFlags{}).add({
            {    2, Format::Format_Invalid },
            {    3, Format::Format_Mono },
            {    4, Format::Format_MonoLSB },
            {    5, Format::Format_Indexed8 },
            {    6, Format::Format_RGB32 },
            {    7, Format::Format_ARGB32 },
            {    8, Format::Format_ARGB32_Premultiplied },
            {    9, Format::Format_RGB16 },
            {   10, Format::Format_ARGB8565_Premultiplied },
            {   11, Format::Format_RGB666 },
            {   12, Format::Format_ARGB6666_Premultiplied },
            {   13, Format::Format_RGB555 },
            {   14, Format::Format_ARGB8555_Premultiplied },
            {   15, Format::Format_RGB888 },
            {   16, Format::Format_RGB444 },
            {   17, Format::Format_ARGB4444_Premultiplied },
            {   18, Format::Format_RGBX8888 },
            {   19, Format::Format_RGBA8888 },
            {   20, Format::Format_RGBA8888_Premultiplied },
            {   21, Format::Format_BGR30 },
            {   22, Format::Format_A2BGR30_Premultiplied },
            {   23, Format::Format_RGB30 },
            {   24, Format::Format_A2RGB30_Premultiplied },
            {   25, Format::Format_Alpha8 },
            {   26, Format::Format_Grayscale8 },
            {   27, Format::Format_RGBX64 },
            {   28, Format::Format_RGBA64 },
            {   29, Format::Format_RGBA64_Premultiplied },
            {   30, Format::Format_Grayscale16 },
            {   31, Format::Format_BGR888 },
            {   32, Format::Format_RGBX16FPx4 },
            {   33, Format::Format_RGBA16FPx4 },
            {   34, Format::Format_RGBA16FPx4_Premultiplied },
            {   35, Format::Format_RGBX32FPx4 },
            {   36, Format::Format_RGBA32FPx4 },
            {   37, Format::Format_RGBA32FPx4_Premultiplied },
            {   38, Format::Format_CMYK8888 },
            {   39, Format::NImageFormats },
        }),
    };
    return QtMocHelpers::metaObjectData<QImage, qt_meta_tag_ZN6QImageE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QImage::staticMetaObject = { {
    QtPrivate::MetaObjectForType<QPaintDevice>::value,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6QImageE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6QImageE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6QImageE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
