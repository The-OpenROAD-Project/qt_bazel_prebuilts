/****************************************************************************
** Meta object code from reading C++ file 'qkeysequence.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/gui/kernel/qkeysequence.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qkeysequence.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN12QKeySequenceE_t {};
} // unnamed namespace

template <> constexpr inline auto QKeySequence::qt_create_metaobjectdata<qt_meta_tag_ZN12QKeySequenceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "QKeySequence",
        "StandardKey",
        "UnknownKey",
        "HelpContents",
        "WhatsThis",
        "Open",
        "Close",
        "Save",
        "New",
        "Delete",
        "Cut",
        "Copy",
        "Paste",
        "Undo",
        "Redo",
        "Back",
        "Forward",
        "Refresh",
        "ZoomIn",
        "ZoomOut",
        "Print",
        "AddTab",
        "NextChild",
        "PreviousChild",
        "Find",
        "FindNext",
        "FindPrevious",
        "Replace",
        "SelectAll",
        "Bold",
        "Italic",
        "Underline",
        "MoveToNextChar",
        "MoveToPreviousChar",
        "MoveToNextWord",
        "MoveToPreviousWord",
        "MoveToNextLine",
        "MoveToPreviousLine",
        "MoveToNextPage",
        "MoveToPreviousPage",
        "MoveToStartOfLine",
        "MoveToEndOfLine",
        "MoveToStartOfBlock",
        "MoveToEndOfBlock",
        "MoveToStartOfDocument",
        "MoveToEndOfDocument",
        "SelectNextChar",
        "SelectPreviousChar",
        "SelectNextWord",
        "SelectPreviousWord",
        "SelectNextLine",
        "SelectPreviousLine",
        "SelectNextPage",
        "SelectPreviousPage",
        "SelectStartOfLine",
        "SelectEndOfLine",
        "SelectStartOfBlock",
        "SelectEndOfBlock",
        "SelectStartOfDocument",
        "SelectEndOfDocument",
        "DeleteStartOfWord",
        "DeleteEndOfWord",
        "DeleteEndOfLine",
        "InsertParagraphSeparator",
        "InsertLineSeparator",
        "SaveAs",
        "Preferences",
        "Quit",
        "FullScreen",
        "Deselect",
        "DeleteCompleteLine",
        "Backspace",
        "Cancel",
        "SequenceFormat",
        "NativeText",
        "PortableText",
        "SequenceMatch",
        "NoMatch",
        "PartialMatch",
        "ExactMatch"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'StandardKey'
        QtMocHelpers::EnumData<StandardKey>(1, 1, QMC::EnumFlags{}).add({
            {    2, StandardKey::UnknownKey },
            {    3, StandardKey::HelpContents },
            {    4, StandardKey::WhatsThis },
            {    5, StandardKey::Open },
            {    6, StandardKey::Close },
            {    7, StandardKey::Save },
            {    8, StandardKey::New },
            {    9, StandardKey::Delete },
            {   10, StandardKey::Cut },
            {   11, StandardKey::Copy },
            {   12, StandardKey::Paste },
            {   13, StandardKey::Undo },
            {   14, StandardKey::Redo },
            {   15, StandardKey::Back },
            {   16, StandardKey::Forward },
            {   17, StandardKey::Refresh },
            {   18, StandardKey::ZoomIn },
            {   19, StandardKey::ZoomOut },
            {   20, StandardKey::Print },
            {   21, StandardKey::AddTab },
            {   22, StandardKey::NextChild },
            {   23, StandardKey::PreviousChild },
            {   24, StandardKey::Find },
            {   25, StandardKey::FindNext },
            {   26, StandardKey::FindPrevious },
            {   27, StandardKey::Replace },
            {   28, StandardKey::SelectAll },
            {   29, StandardKey::Bold },
            {   30, StandardKey::Italic },
            {   31, StandardKey::Underline },
            {   32, StandardKey::MoveToNextChar },
            {   33, StandardKey::MoveToPreviousChar },
            {   34, StandardKey::MoveToNextWord },
            {   35, StandardKey::MoveToPreviousWord },
            {   36, StandardKey::MoveToNextLine },
            {   37, StandardKey::MoveToPreviousLine },
            {   38, StandardKey::MoveToNextPage },
            {   39, StandardKey::MoveToPreviousPage },
            {   40, StandardKey::MoveToStartOfLine },
            {   41, StandardKey::MoveToEndOfLine },
            {   42, StandardKey::MoveToStartOfBlock },
            {   43, StandardKey::MoveToEndOfBlock },
            {   44, StandardKey::MoveToStartOfDocument },
            {   45, StandardKey::MoveToEndOfDocument },
            {   46, StandardKey::SelectNextChar },
            {   47, StandardKey::SelectPreviousChar },
            {   48, StandardKey::SelectNextWord },
            {   49, StandardKey::SelectPreviousWord },
            {   50, StandardKey::SelectNextLine },
            {   51, StandardKey::SelectPreviousLine },
            {   52, StandardKey::SelectNextPage },
            {   53, StandardKey::SelectPreviousPage },
            {   54, StandardKey::SelectStartOfLine },
            {   55, StandardKey::SelectEndOfLine },
            {   56, StandardKey::SelectStartOfBlock },
            {   57, StandardKey::SelectEndOfBlock },
            {   58, StandardKey::SelectStartOfDocument },
            {   59, StandardKey::SelectEndOfDocument },
            {   60, StandardKey::DeleteStartOfWord },
            {   61, StandardKey::DeleteEndOfWord },
            {   62, StandardKey::DeleteEndOfLine },
            {   63, StandardKey::InsertParagraphSeparator },
            {   64, StandardKey::InsertLineSeparator },
            {   65, StandardKey::SaveAs },
            {   66, StandardKey::Preferences },
            {   67, StandardKey::Quit },
            {   68, StandardKey::FullScreen },
            {   69, StandardKey::Deselect },
            {   70, StandardKey::DeleteCompleteLine },
            {   71, StandardKey::Backspace },
            {   72, StandardKey::Cancel },
        }),
        // enum 'SequenceFormat'
        QtMocHelpers::EnumData<SequenceFormat>(73, 73, QMC::EnumFlags{}).add({
            {   74, SequenceFormat::NativeText },
            {   75, SequenceFormat::PortableText },
        }),
        // enum 'SequenceMatch'
        QtMocHelpers::EnumData<SequenceMatch>(76, 76, QMC::EnumFlags{}).add({
            {   77, SequenceMatch::NoMatch },
            {   78, SequenceMatch::PartialMatch },
            {   79, SequenceMatch::ExactMatch },
        }),
    };
    return QtMocHelpers::metaObjectData<QKeySequence, qt_meta_tag_ZN12QKeySequenceE_t>(QMC::PropertyAccessInStaticMetaCall, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject QKeySequence::staticMetaObject = { {
    nullptr,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QKeySequenceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12QKeySequenceE_t>.data,
    nullptr,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12QKeySequenceE_t>.metaTypes,
    nullptr
} };

QT_WARNING_POP
