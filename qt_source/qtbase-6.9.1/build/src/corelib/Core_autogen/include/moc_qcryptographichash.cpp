/****************************************************************************
** Meta object code from reading C++ file 'qcryptographichash.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/corelib/tools/qcryptographichash.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qcryptographichash.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN18QCryptographicHashE_t {};
} // unnamed namespace

template <> constexpr inline auto QCryptographicHash::qt_create_metaobjectdata<qt_meta_tag_ZN18QCryptographicHashE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QCryptographicHash",
        "Algorithm",
        "Md4",
        "Md5",
        "Sha1",
        "Sha224",
        "Sha256",
        "Sha384",
        "Sha512",
        "Keccak_224",
        "Keccak_256",
        "Keccak_384",
        "Keccak_512",
        "RealSha3_224",
        "RealSha3_256",
        "RealSha3_384",
        "RealSha3_512",
        "Sha3_224",
        "Sha3_256",
        "Sha3_384",
        "Sha3_512",
        "Blake2b_160",
        "Blake2b_256",
        "Blake2b_384",
        "Blake2b_512",
        "Blake2s_128",
        "Blake2s_160",
        "Blake2s_224",
        "Blake2s_256",
        "NumAlgorithms"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'Algorithm'
        QtMocHelpers::EnumData<Algorithm>(1, 1, QMC::EnumFlags{}).add({
            {    2, Algorithm::Md4 },
            {    3, Algorithm::Md5 },
            {    4, Algorithm::Sha1 },
            {    5, Algorithm::Sha224 },
            {    6, Algorithm::Sha256 },
            {    7, Algorithm::Sha384 },
            {    8, Algorithm::Sha512 },
            {    9, Algorithm::Keccak_224 },
            {   10, Algorithm::Keccak_256 },
            {   11, Algorithm::Keccak_384 },
            {   12, Algorithm::Keccak_512 },
            {   13, Algorithm::RealSha3_224 },
            {   14, Algorithm::RealSha3_256 },
            {   15, Algorithm::RealSha3_384 },
            {   16, Algorithm::RealSha3_512 },
            {   17, Algorithm::Sha3_224 },
            {   18, Algorithm::Sha3_256 },
            {   19, Algorithm::Sha3_384 },
            {   20, Algorithm::Sha3_512 },
            {   21, Algorithm::Blake2b_160 },
            {   22, Algorithm::Blake2b_256 },
            {   23, Algorithm::Blake2b_384 },
            {   24, Algorithm::Blake2b_512 },
            {   25, Algorithm::Blake2s_128 },
            {   26, Algorithm::Blake2s_160 },
            {   27, Algorithm::Blake2s_224 },
            {   28, Algorithm::Blake2s_256 },
            {   29, Algorithm::NumAlgorithms },
        }),
    };
    return QtMocHelpers::metaObjectData<QCryptographicHash, qt_meta_tag_ZN18QCryptographicHashE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QCryptographicHash::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QCryptographicHashE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN18QCryptographicHashE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN18QCryptographicHashE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
