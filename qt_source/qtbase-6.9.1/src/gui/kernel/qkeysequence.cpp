// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qkeysequence.h"
#include "qkeysequence_p.h"
#include <qpa/qplatformtheme.h>
#include "private/qguiapplication_p.h"

#include "qdebug.h"
#include <QtCore/qhashfunctions.h>
#ifndef QT_NO_DATASTREAM
# include "qdatastream.h"
#endif
#include "qvariant.h"

#if defined(Q_OS_APPLE)
#include <QtCore/private/qcore_mac_p.h>
#endif

#include <algorithm>
#include <q20algorithm.h>

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

#if defined(Q_OS_APPLE) || defined(Q_QDOC)
Q_CONSTINIT static bool qt_sequence_no_mnemonics = true;
struct AppleSpecialKey {
    int key;
    ushort appleSymbol;
};

// Unicode code points for the glyphs associated with these keys
// Defined by Carbon headers but not anywhere in Cocoa
static constexpr int kShiftUnicode = 0x21E7;
static constexpr int kControlUnicode = 0x2303;
static constexpr int kOptionUnicode = 0x2325;
static constexpr int kCommandUnicode = 0x2318;

static constexpr AppleSpecialKey entries[] = {
    { Qt::Key_Escape, 0x238B },
    { Qt::Key_Tab, 0x21E5 },
    { Qt::Key_Backtab, 0x21E4 },
    { Qt::Key_Backspace, 0x232B },
    { Qt::Key_Return, 0x21B5 },
    { Qt::Key_Enter, 0x2324 },
    { Qt::Key_Delete, 0x2326 },
    { Qt::Key_Clear, 0x2327 },
    { Qt::Key_Home, 0x2196 },
    { Qt::Key_End, 0x2198 },
    { Qt::Key_Left, 0x2190 },
    { Qt::Key_Up, 0x2191 },
    { Qt::Key_Right, 0x2192 },
    { Qt::Key_Down, 0x2193 },
    { Qt::Key_PageUp, 0x21DE },
    { Qt::Key_PageDown, 0x21DF },
    { Qt::Key_Shift, kShiftUnicode },
    { Qt::Key_Control, kCommandUnicode },
    { Qt::Key_Meta, kControlUnicode },
    { Qt::Key_Alt, kOptionUnicode },
    { Qt::Key_CapsLock, 0x21EA },
    { Qt::Key_Eject, 0x23CF },
};

static constexpr bool operator<(const AppleSpecialKey &lhs, const AppleSpecialKey &rhs)
{
    return lhs.key < rhs.key;
}

static constexpr bool operator<(const AppleSpecialKey &lhs, int rhs)
{
    return lhs.key < rhs;
}

static constexpr bool operator<(int lhs, const AppleSpecialKey &rhs)
{
    return lhs < rhs.key;
}

static_assert(q20::is_sorted(std::begin(entries), std::end(entries)));

static QChar appleSymbolForQtKey(int key)
{
    const auto i = std::lower_bound(std::begin(entries), std::end(entries), key);
    if (i == std::end(entries) || key < *i)
        return QChar();
    ushort appleSymbol = i->appleSymbol;
    if (qApp->testAttribute(Qt::AA_MacDontSwapCtrlAndMeta)
            && (appleSymbol == kControlUnicode || appleSymbol == kCommandUnicode)) {
        if (appleSymbol == kControlUnicode)
            appleSymbol = kCommandUnicode;
        else
            appleSymbol = kControlUnicode;
    }

    return QChar(appleSymbol);
}

static int qtkeyForAppleSymbol(const QChar ch)
{
    const ushort unicode = ch.unicode();
    for (const AppleSpecialKey &entry : entries) {
        if (entry.appleSymbol == unicode) {
            int key = entry.key;
            if (qApp->testAttribute(Qt::AA_MacDontSwapCtrlAndMeta)
                    && (unicode == kControlUnicode || unicode == kCommandUnicode)) {
                if (unicode == kControlUnicode)
                    key = Qt::Key_Control;
                else
                    key = Qt::Key_Meta;
            }
            return key;
        }
    }
    return -1;
}

#else
Q_CONSTINIT static bool qt_sequence_no_mnemonics = false;
#endif

/*!
    \fn void qt_set_sequence_auto_mnemonic(bool b)
    \relates QKeySequence

    Specifies whether mnemonics for menu items, labels, etc., should
    be honored or not. On Windows and X11, this feature is
    on by default; on \macos, it is off. When this feature is off
    (that is, when \a b is false), QKeySequence::mnemonic() always
    returns an empty string.

    \note This function is not declared in any of Qt's header files.
    To use it in your application, declare the function prototype
    before calling it.

    \sa QShortcut
*/
void Q_GUI_EXPORT qt_set_sequence_auto_mnemonic(bool b) { qt_sequence_no_mnemonics = !b; }

/*!
    \class QKeySequence
    \brief The QKeySequence class encapsulates a key sequence as used
    by shortcuts.

    \ingroup shared
    \inmodule QtGui


    In its most common form, a key sequence describes a combination of
    keys that must be used together to perform some action. Key sequences
    are used with QAction objects to specify which keyboard shortcuts can
    be used to trigger actions.

    Key sequences can be constructed for use as keyboard shortcuts in
    three different ways:

    \list
    \li For standard shortcuts, a \l{QKeySequence::StandardKey}{standard key}
       can be used to request the platform-specific key sequence associated
       with each shortcut.
    \li For custom shortcuts, human-readable strings such as "Ctrl+X" can
       be used, and these can be translated into the appropriate shortcuts
       for users of different languages. Translations are made in the
       "QShortcut" context.
    \li For hard-coded shortcuts, integer key codes can be specified with
       a combination of values defined by the Qt::Key and Qt::KeyboardModifier
       enum values. Each key code consists of a single Qt::Key value and zero
       or more modifiers, such as Qt::ShiftModifier, Qt::ControlModifier,
       Qt::AltModifier and Qt::MetaModifier.
    \endlist

    For example, \uicontrol{Ctrl P} might be a sequence used as a shortcut for
    printing a document, and can be specified in any of the following
    ways:

    \snippet code/src_gui_kernel_qkeysequence.cpp 0

    Note that, for letters, the case used in the specification string
    does not matter. In the above examples, the user does not need to
    hold down the \uicontrol{Shift} key to activate a shortcut specified
    with "Ctrl+P". However, for other keys, the use of \uicontrol{Shift} as
    an unspecified extra modifier key can lead to confusion for users
    of an application whose keyboards have different layouts to those
    used by the developers. See the \l{Keyboard Layout Issues} section
    below for more details.

    It is preferable to use standard shortcuts where possible.
    When creating key sequences for non-standard shortcuts, you should use
    human-readable strings in preference to hard-coded integer values.

    QKeySequence object can be serialized to human-readable strings with the
    toString() function.

    An alternative way to specify hard-coded key codes is to use the Unicode
    code point of the character; for example, 'A' gives the same key sequence
    as Qt::Key_A.

    \note On Apple platforms, references to "Ctrl", Qt::CTRL, Qt::Key_Control
    and Qt::ControlModifier correspond to the \uicontrol Command keys on the
    Macintosh keyboard, and references to "Meta", Qt::META, Qt::Key_Meta and
    Qt::MetaModifier correspond to the \uicontrol Control keys. In effect,
    developers can use the same shortcut descriptions across all platforms,
    and their applications will automatically work as expected on Apple platforms.

    \section1 Standard Shortcuts

    QKeySequence defines many \l{QKeySequence::StandardKey} {standard
    keyboard shortcuts} to reduce the amount of effort required when
    setting up actions in a typical application. The table below shows
    some common key sequences that are often used for these standard
    shortcuts by applications on four widely-used platforms.  Note
    that on Apple platforms, the \uicontrol Ctrl value corresponds to the \uicontrol
    Command keys on the Macintosh keyboard, and the \uicontrol Meta value
    corresponds to the \uicontrol Control keys.

    \table
    \header \li StandardKey      \li Windows                              \li Apple platforms          \li KDE Plasma   \li GNOME
    \row    \li HelpContents     \li F1                                   \li Ctrl+?                   \li F1           \li F1
    \row    \li WhatsThis        \li Shift+F1                             \li Shift+F1                 \li Shift+F1     \li Shift+F1
    \row    \li Open             \li Ctrl+O                               \li Ctrl+O                   \li Ctrl+O       \li Ctrl+O
    \row    \li Close            \li Ctrl+F4, Ctrl+W                      \li Ctrl+W, Ctrl+F4          \li Ctrl+W       \li Ctrl+W
    \row    \li Save             \li Ctrl+S                               \li Ctrl+S                   \li Ctrl+S       \li Ctrl+S
    \row    \li Quit             \li                                      \li Ctrl+Q                   \li Ctrl+Q       \li Ctrl+Q
    \row    \li SaveAs           \li Ctrl+Shift+S                         \li Ctrl+Shift+S             \li Ctrl+Shift+S \li Ctrl+Shift+S
    \row    \li New              \li Ctrl+N                               \li Ctrl+N                   \li Ctrl+N       \li Ctrl+N
    \row    \li Delete           \li Del                                  \li Forward Delete, Meta+D   \li Del, Ctrl+D  \li Del, Ctrl+D
    \row    \li Cut              \li Ctrl+X, Shift+Del                    \li Ctrl+X, Meta+K           \li Ctrl+X, F20, Shift+Del \li Ctrl+X, F20, Shift+Del
    \row    \li Copy             \li Ctrl+C, Ctrl+Ins                     \li Ctrl+C                   \li Ctrl+C, F16, Ctrl+Ins  \li Ctrl+C, F16, Ctrl+Ins
    \row    \li Paste            \li Ctrl+V, Shift+Ins                    \li Ctrl+V, Meta+Y           \li Ctrl+V, F18, Shift+Ins \li Ctrl+V, F18, Shift+Ins
    \row    \li Preferences      \li                                      \li Ctrl+,                   \li Ctrl+Shift+, \li
    \row    \li Undo             \li Ctrl+Z, Alt+Backspace                \li Ctrl+Z                   \li Ctrl+Z, F14  \li Ctrl+Z, F14
    \row    \li Redo             \li Ctrl+Y, Shift+Ctrl+Z, Alt+Shift+Backspace \li Ctrl+Shift+Z        \li Ctrl+Shift+Z \li Ctrl+Shift+Z
    \row    \li Back             \li Alt+Left, Backspace                  \li Ctrl+[                   \li Alt+Left     \li Alt+Left
    \row    \li Forward          \li Alt+Right, Shift+Backspace           \li Ctrl+]                   \li Alt+Right    \li Alt+Right
    \row    \li Refresh          \li F5                                   \li F5                       \li F5           \li Ctrl+R, F5
    \row    \li ZoomIn           \li Ctrl+Plus                            \li Ctrl+Plus                \li Ctrl+Plus    \li Ctrl+Plus
    \row    \li ZoomOut          \li Ctrl+Minus                           \li Ctrl+Minus               \li Ctrl+Minus   \li Ctrl+Minus
    \row    \li FullScreen       \li F11, Alt+Enter                       \li Ctrl+Meta+F              \li F11, Ctrl+Shift+F \li Ctrl+F11
    \row    \li Print            \li Ctrl+P                               \li Ctrl+P                   \li Ctrl+P       \li Ctrl+P
    \row    \li AddTab           \li Ctrl+T                               \li Ctrl+T                   \li Ctrl+Shift+N, Ctrl+T \li Ctrl+T
    \row    \li NextChild        \li Ctrl+Tab, Forward, Ctrl+F6           \li Ctrl+}, Forward, Ctrl+Tab \li Ctrl+Tab, Forward, Ctrl+Comma \li Ctrl+Tab, Forward
    \row    \li PreviousChild    \li Ctrl+Shift+Tab, Back, Ctrl+Shift+F6  \li Ctrl+{, Back, Ctrl+Shift+Tab \li Ctrl+Shift+Tab, Back, Ctrl+Period \li Ctrl+Shift+Tab, Back
    \row    \li Find             \li Ctrl+F                               \li Ctrl+F                   \li Ctrl+F         \li Ctrl+F
    \row    \li FindNext         \li F3, Ctrl+G                           \li Ctrl+G                   \li F3             \li Ctrl+G, F3
    \row    \li FindPrevious     \li Shift+F3, Ctrl+Shift+G               \li Ctrl+Shift+G             \li Shift+F3       \li Ctrl+Shift+G, Shift+F3
    \row    \li Replace          \li Ctrl+H                               \li (none)                   \li Ctrl+R         \li Ctrl+H
    \row    \li SelectAll        \li Ctrl+A                               \li Ctrl+A                   \li Ctrl+A         \li Ctrl+A
    \row    \li Deselect         \li                                      \li                          \li Ctrl+Shift+A   \li Ctrl+Shift+A
    \row    \li Bold             \li Ctrl+B                               \li Ctrl+B                   \li Ctrl+B         \li Ctrl+B
    \row    \li Italic           \li Ctrl+I                               \li Ctrl+I                   \li Ctrl+I         \li Ctrl+I
    \row    \li Underline        \li Ctrl+U                               \li Ctrl+U                   \li Ctrl+U         \li Ctrl+U
    \row    \li MoveToNextChar       \li Right                            \li Right, Meta+F            \li Right          \li Right
    \row    \li MoveToPreviousChar   \li Left                             \li Left, Meta+B             \li Left           \li Left
    \row    \li MoveToNextWord       \li Ctrl+Right                       \li Alt+Right                \li Ctrl+Right     \li Ctrl+Right
    \row    \li MoveToPreviousWord   \li Ctrl+Left                        \li Alt+Left                 \li Ctrl+Left      \li Ctrl+Left
    \row    \li MoveToNextLine       \li Down                             \li Down, Meta+N             \li Down           \li Down
    \row    \li MoveToPreviousLine   \li Up                               \li Up, Meta+P               \li Up             \li Up
    \row    \li MoveToNextPage       \li PgDown                           \li PgDown, Alt+PgDown, Meta+Down, Meta+PgDown, Meta+V \li PgDown \li PgDown
    \row    \li MoveToPreviousPage   \li PgUp                             \li PgUp, Alt+PgUp, Meta+Up, Meta+PgUp        \li PgUp   \li PgUp
    \row    \li MoveToStartOfLine    \li Home                             \li Ctrl+Left, Meta+Left   \li Home            \li Home
    \row    \li MoveToEndOfLine      \li End                              \li Ctrl+Right, Meta+Right \li End, Ctrl+E     \li End, Ctrl+E
    \row    \li MoveToStartOfBlock   \li (none)                           \li Alt+Up, Meta+A         \li (none)          \li (none)
    \row    \li MoveToEndOfBlock     \li (none)                           \li Alt+Down, Meta+E       \li (none)          \li (none)
    \row    \li MoveToStartOfDocument\li Ctrl+Home                        \li Ctrl+Up, Home          \li Ctrl+Home       \li Ctrl+Home
    \row    \li MoveToEndOfDocument  \li Ctrl+End                         \li Ctrl+Down, End         \li Ctrl+End        \li Ctrl+End
    \row    \li SelectNextChar       \li Shift+Right                      \li Shift+Right            \li Shift+Right     \li Shift+Right
    \row    \li SelectPreviousChar   \li Shift+Left                       \li Shift+Left             \li Shift+Left      \li Shift+Left
    \row    \li SelectNextWord       \li Ctrl+Shift+Right                 \li Alt+Shift+Right        \li Ctrl+Shift+Right \li Ctrl+Shift+Right
    \row    \li SelectPreviousWord   \li Ctrl+Shift+Left                  \li Alt+Shift+Left         \li Ctrl+Shift+Left \li Ctrl+Shift+Left
    \row    \li SelectNextLine       \li Shift+Down                       \li Shift+Down             \li Shift+Down     \li Shift+Down
    \row    \li SelectPreviousLine   \li Shift+Up                         \li Shift+Up               \li Shift+Up       \li Shift+Up
    \row    \li SelectNextPage       \li Shift+PgDown                     \li Shift+PgDown           \li Shift+PgDown   \li Shift+PgDown
    \row    \li SelectPreviousPage   \li Shift+PgUp                       \li Shift+PgUp             \li Shift+PgUp     \li Shift+PgUp
    \row    \li SelectStartOfLine    \li Shift+Home                       \li Ctrl+Shift+Left        \li Shift+Home     \li Shift+Home
    \row    \li SelectEndOfLine      \li Shift+End                        \li Ctrl+Shift+Right       \li Shift+End      \li Shift+End
    \row    \li SelectStartOfBlock   \li (none)                           \li Alt+Shift+Up, Meta+Shift+A \li (none)     \li (none)
    \row    \li SelectEndOfBlock     \li (none)                           \li Alt+Shift+Down, Meta+Shift+E \li (none)   \li (none)
    \row    \li SelectStartOfDocument\li Ctrl+Shift+Home                  \li Ctrl+Shift+Up, Shift+Home          \li Ctrl+Shift+Home\li Ctrl+Shift+Home
    \row    \li SelectEndOfDocument  \li Ctrl+Shift+End                   \li Ctrl+Shift+Down, Shift+End        \li Ctrl+Shift+End \li Ctrl+Shift+End
    \row    \li DeleteStartOfWord    \li Ctrl+Backspace                   \li Alt+Backspace          \li Ctrl+Backspace \li Ctrl+Backspace
    \row    \li DeleteEndOfWord      \li Ctrl+Del                         \li (none)                 \li Ctrl+Del       \li Ctrl+Del
    \row    \li DeleteEndOfLine      \li (none)                           \li (none)                 \li Ctrl+K         \li Ctrl+K
    \row    \li DeleteCompleteLine   \li (none)                           \li (none)                 \li Ctrl+U         \li Ctrl+U
    \row    \li InsertParagraphSeparator     \li Enter                    \li Enter                  \li Enter          \li Enter
    \row    \li InsertLineSeparator          \li Shift+Enter              \li Meta+Enter, Meta+O     \li Shift+Enter    \li Shift+Enter
    \row    \li Backspace             \li (none)                          \li Delete, Meta+H         \li (none)         \li (none)
    \row    \li Cancel                \li Escape                          \li Escape, Ctrl+.         \li Escape         \li Escape
    \endtable

    Note that, since the key sequences used for the standard shortcuts differ
    between platforms, you still need to test your shortcuts on each platform
    to ensure that you do not unintentionally assign the same key sequence to
    many actions.

    \section1 Keyboard Layout Issues

    Many key sequence specifications are chosen by developers based on the
    layout of certain types of keyboard, rather than choosing keys that
    represent the first letter of an action's name, such as \uicontrol{Ctrl S}
    ("Ctrl+S") or \uicontrol{Ctrl C} ("Ctrl+C").
    Additionally, because certain symbols can only be entered with the
    help of modifier keys on certain keyboard layouts, key sequences intended
    for use with one keyboard layout may map to a different key, map to no
    keys at all, or require an additional modifier key to be used on
    different keyboard layouts.

    For example, the shortcuts, \uicontrol{Ctrl plus} and \uicontrol{Ctrl minus}, are often
    used as shortcuts for zoom operations in graphics applications, and these
    may be specified as "Ctrl++" and "Ctrl+-" respectively. However, the way
    these shortcuts are specified and interpreted depends on the keyboard layout.
    Users of Norwegian keyboards will note that the \uicontrol{+} and \uicontrol{-} keys
    are not adjacent on the keyboard, but will still be able to activate both
    shortcuts without needing to press the \uicontrol{Shift} key. However, users
    with British keyboards will need to hold down the \uicontrol{Shift} key
    to enter the \uicontrol{+} symbol, making the shortcut effectively the same as
    "Ctrl+Shift+=".

    Although some developers might resort to fully specifying all the modifiers
    they use on their keyboards to activate a shortcut, this will also result
    in unexpected behavior for users of different keyboard layouts.

    For example, a developer using a British keyboard may decide to specify
    "Ctrl+Shift+=" as the key sequence in order to create a shortcut that
    coincidentally behaves in the same way as \uicontrol{Ctrl plus}. However, the
    \uicontrol{=} key needs to be accessed using the \uicontrol{Shift} key on Norwegian
    keyboard, making the required shortcut effectively \uicontrol{Ctrl Shift Shift =}
    (an impossible key combination).

    As a result, both human-readable strings and hard-coded key codes
    can both be problematic to use when specifying a key sequence that
    can be used on a variety of different keyboard layouts. Only the
    use of \l{QKeySequence::StandardKey} {standard shortcuts}
    guarantees that the user will be able to use the shortcuts that
    the developer intended.

    Despite this, we can address this issue by ensuring that human-readable
    strings are used, making it possible for translations of key sequences to
    be made for users of different languages. This approach will be successful
    for users whose keyboards have the most typical layout for the language
    they are using.

    \section1 GNU Emacs Style Key Sequences

    Key sequences similar to those used in \l{http://www.gnu.org/software/emacs/}{GNU Emacs}, allowing up to four
    key codes, can be created by using the multiple argument constructor,
    or by passing a human-readable string of comma-separated key sequences.

    For example, the key sequence, \uicontrol{Ctrl X} followed by \uicontrol{Ctrl C}, can
    be specified using either of the following ways:

    \snippet code/src_gui_kernel_qkeysequence.cpp 1

    \warning A QApplication instance must have been constructed before a
             QKeySequence is created; otherwise, your application may crash.

    \sa QShortcut
*/

/*!
    \enum QKeySequence::SequenceMatch

    \value NoMatch The key sequences are different; not even partially
    matching.
    \value PartialMatch The key sequences match partially, but are not
    the same.
    \value ExactMatch The key sequences are the same.
*/

/*!
    \enum QKeySequence::SequenceFormat

    \value NativeText The key sequence as a platform specific string.
    This means that it will be shown translated and on Apple platforms it will
    resemble a key sequence from the menu bar. This enum is best used when you
    want to display the string to the user.

    \value PortableText The key sequence is given in a "portable" format,
    suitable for reading and writing to a file. In many cases, it will look
    similar to the native text on Windows and X11.
*/

static constexpr struct {
    int key;
    const char name[25];
} keyname[] = {
    //: This and all following "incomprehensible" strings in QShortcut context
    //: are key names. Please use the localized names appearing on actual
    //: keyboards or whatever is commonly used.
    { Qt::Key_Space,        QT_TRANSLATE_NOOP("QShortcut", "Space") },
    { Qt::Key_Escape,       QT_TRANSLATE_NOOP("QShortcut", "Esc") },
    { Qt::Key_Tab,          QT_TRANSLATE_NOOP("QShortcut", "Tab") },
    { Qt::Key_Backtab,      QT_TRANSLATE_NOOP("QShortcut", "Backtab") },
    { Qt::Key_Backspace,    QT_TRANSLATE_NOOP("QShortcut", "Backspace") },
    { Qt::Key_Return,       QT_TRANSLATE_NOOP("QShortcut", "Return") },
    { Qt::Key_Enter,        QT_TRANSLATE_NOOP("QShortcut", "Enter") },
    { Qt::Key_Insert,       QT_TRANSLATE_NOOP("QShortcut", "Ins") },
    { Qt::Key_Delete,       QT_TRANSLATE_NOOP("QShortcut", "Del") },
    { Qt::Key_Pause,        QT_TRANSLATE_NOOP("QShortcut", "Pause") },
    { Qt::Key_Print,        QT_TRANSLATE_NOOP("QShortcut", "Print") },
    { Qt::Key_SysReq,       QT_TRANSLATE_NOOP("QShortcut", "SysReq") },
    { Qt::Key_Home,         QT_TRANSLATE_NOOP("QShortcut", "Home") },
    { Qt::Key_End,          QT_TRANSLATE_NOOP("QShortcut", "End") },
    { Qt::Key_Left,         QT_TRANSLATE_NOOP("QShortcut", "Left") },
    { Qt::Key_Up,           QT_TRANSLATE_NOOP("QShortcut", "Up") },
    { Qt::Key_Right,        QT_TRANSLATE_NOOP("QShortcut", "Right") },
    { Qt::Key_Down,         QT_TRANSLATE_NOOP("QShortcut", "Down") },
    { Qt::Key_PageUp,       QT_TRANSLATE_NOOP("QShortcut", "PgUp") },
    { Qt::Key_PageDown,     QT_TRANSLATE_NOOP("QShortcut", "PgDown") },
    { Qt::Key_CapsLock,     QT_TRANSLATE_NOOP("QShortcut", "CapsLock") },
    { Qt::Key_NumLock,      QT_TRANSLATE_NOOP("QShortcut", "NumLock") },
    { Qt::Key_ScrollLock,   QT_TRANSLATE_NOOP("QShortcut", "ScrollLock") },
    { Qt::Key_Menu,         QT_TRANSLATE_NOOP("QShortcut", "Menu") },
    { Qt::Key_Help,         QT_TRANSLATE_NOOP("QShortcut", "Help") },

    // Special keys
    // Includes multimedia, launcher, lan keys ( bluetooth, wireless )
    // window navigation
    { Qt::Key_Back,                       QT_TRANSLATE_NOOP("QShortcut", "Back") },
    { Qt::Key_Forward,                    QT_TRANSLATE_NOOP("QShortcut", "Forward") },
    { Qt::Key_Stop,                       QT_TRANSLATE_NOOP("QShortcut", "Stop") },
    { Qt::Key_Refresh,                    QT_TRANSLATE_NOOP("QShortcut", "Refresh") },
    { Qt::Key_VolumeDown,                 QT_TRANSLATE_NOOP("QShortcut", "Volume Down") },
    { Qt::Key_VolumeMute,                 QT_TRANSLATE_NOOP("QShortcut", "Volume Mute") },
    { Qt::Key_VolumeUp,                   QT_TRANSLATE_NOOP("QShortcut", "Volume Up") },
    { Qt::Key_BassBoost,                  QT_TRANSLATE_NOOP("QShortcut", "Bass Boost") },
    { Qt::Key_BassUp,                     QT_TRANSLATE_NOOP("QShortcut", "Bass Up") },
    { Qt::Key_BassDown,                   QT_TRANSLATE_NOOP("QShortcut", "Bass Down") },
    { Qt::Key_TrebleUp,                   QT_TRANSLATE_NOOP("QShortcut", "Treble Up") },
    { Qt::Key_TrebleDown,                 QT_TRANSLATE_NOOP("QShortcut", "Treble Down") },
    { Qt::Key_MediaPlay,                  QT_TRANSLATE_NOOP("QShortcut", "Media Play") },
    { Qt::Key_MediaStop,                  QT_TRANSLATE_NOOP("QShortcut", "Media Stop") },
    { Qt::Key_MediaPrevious,              QT_TRANSLATE_NOOP("QShortcut", "Media Previous") },
    { Qt::Key_MediaNext,                  QT_TRANSLATE_NOOP("QShortcut", "Media Next") },
    { Qt::Key_MediaRecord,                QT_TRANSLATE_NOOP("QShortcut", "Media Record") },
    //: Media player pause button
    { Qt::Key_MediaPause,                 QT_TRANSLATE_NOOP("QShortcut", "Media Pause") },
    //: Media player button to toggle between playing and paused
    { Qt::Key_MediaTogglePlayPause,       QT_TRANSLATE_NOOP("QShortcut", "Toggle Media Play/Pause") },
    { Qt::Key_HomePage,                   QT_TRANSLATE_NOOP("QShortcut", "Home Page") },
    { Qt::Key_Favorites,                  QT_TRANSLATE_NOOP("QShortcut", "Favorites") },
    { Qt::Key_Search,                     QT_TRANSLATE_NOOP("QShortcut", "Search") },
    { Qt::Key_Standby,                    QT_TRANSLATE_NOOP("QShortcut", "Standby") },
    { Qt::Key_OpenUrl,                    QT_TRANSLATE_NOOP("QShortcut", "Open URL") },
    { Qt::Key_LaunchMail,                 QT_TRANSLATE_NOOP("QShortcut", "Launch Mail") },
    { Qt::Key_LaunchMedia,                QT_TRANSLATE_NOOP("QShortcut", "Launch Media") },
    { Qt::Key_Launch0,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (0)") },
    { Qt::Key_Launch1,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (1)") },
    { Qt::Key_Launch2,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (2)") },
    { Qt::Key_Launch3,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (3)") },
    { Qt::Key_Launch4,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (4)") },
    { Qt::Key_Launch5,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (5)") },
    { Qt::Key_Launch6,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (6)") },
    { Qt::Key_Launch7,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (7)") },
    { Qt::Key_Launch8,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (8)") },
    { Qt::Key_Launch9,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (9)") },
    { Qt::Key_LaunchA,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (A)") },
    { Qt::Key_LaunchB,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (B)") },
    { Qt::Key_LaunchC,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (C)") },
    { Qt::Key_LaunchD,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (D)") },
    { Qt::Key_LaunchE,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (E)") },
    { Qt::Key_LaunchF,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (F)") },
    { Qt::Key_LaunchG,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (G)") },
    { Qt::Key_LaunchH,                    QT_TRANSLATE_NOOP("QShortcut", "Launch (H)") },
    { Qt::Key_MonBrightnessUp,            QT_TRANSLATE_NOOP("QShortcut", "Monitor Brightness Up") },
    { Qt::Key_MonBrightnessDown,          QT_TRANSLATE_NOOP("QShortcut", "Monitor Brightness Down") },
    { Qt::Key_KeyboardLightOnOff,         QT_TRANSLATE_NOOP("QShortcut", "Keyboard Light On/Off") },
    { Qt::Key_KeyboardBrightnessUp,       QT_TRANSLATE_NOOP("QShortcut", "Keyboard Brightness Up") },
    { Qt::Key_KeyboardBrightnessDown,     QT_TRANSLATE_NOOP("QShortcut", "Keyboard Brightness Down") },
    { Qt::Key_PowerOff,                   QT_TRANSLATE_NOOP("QShortcut", "Power Off") },
    { Qt::Key_WakeUp,                     QT_TRANSLATE_NOOP("QShortcut", "Wake Up") },
    { Qt::Key_Eject,                      QT_TRANSLATE_NOOP("QShortcut", "Eject") },
    { Qt::Key_ScreenSaver,                QT_TRANSLATE_NOOP("QShortcut", "Screensaver") },
    { Qt::Key_WWW,                        QT_TRANSLATE_NOOP("QShortcut", "WWW") },
    { Qt::Key_Sleep,                      QT_TRANSLATE_NOOP("QShortcut", "Sleep") },
    { Qt::Key_LightBulb,                  QT_TRANSLATE_NOOP("QShortcut", "LightBulb") },
    { Qt::Key_Shop,                       QT_TRANSLATE_NOOP("QShortcut", "Shop") },
    { Qt::Key_History,                    QT_TRANSLATE_NOOP("QShortcut", "History") },
    { Qt::Key_AddFavorite,                QT_TRANSLATE_NOOP("QShortcut", "Add Favorite") },
    { Qt::Key_HotLinks,                   QT_TRANSLATE_NOOP("QShortcut", "Hot Links") },
    { Qt::Key_BrightnessAdjust,           QT_TRANSLATE_NOOP("QShortcut", "Adjust Brightness") },
    { Qt::Key_Finance,                    QT_TRANSLATE_NOOP("QShortcut", "Finance") },
    { Qt::Key_Community,                  QT_TRANSLATE_NOOP("QShortcut", "Community") },
    { Qt::Key_AudioRewind,                QT_TRANSLATE_NOOP("QShortcut", "Media Rewind") },
    { Qt::Key_BackForward,                QT_TRANSLATE_NOOP("QShortcut", "Back Forward") },
    { Qt::Key_ApplicationLeft,            QT_TRANSLATE_NOOP("QShortcut", "Application Left") },
    { Qt::Key_ApplicationRight,           QT_TRANSLATE_NOOP("QShortcut", "Application Right") },
    { Qt::Key_Book,                       QT_TRANSLATE_NOOP("QShortcut", "Book") },
    { Qt::Key_CD,                         QT_TRANSLATE_NOOP("QShortcut", "CD") },
    { Qt::Key_Calculator,                 QT_TRANSLATE_NOOP("QShortcut", "Calculator") },
    { Qt::Key_Calendar,                   QT_TRANSLATE_NOOP("QShortcut", "Calendar") },
    { Qt::Key_Clear,                      QT_TRANSLATE_NOOP("QShortcut", "Clear") },
    { Qt::Key_ClearGrab,                  QT_TRANSLATE_NOOP("QShortcut", "Clear Grab") },
    { Qt::Key_Close,                      QT_TRANSLATE_NOOP("QShortcut", "Close") },
    { Qt::Key_ContrastAdjust,             QT_TRANSLATE_NOOP("QShortcut", "Adjust contrast") },
    { Qt::Key_Copy,                       QT_TRANSLATE_NOOP("QShortcut", "Copy") },
    { Qt::Key_Cut,                        QT_TRANSLATE_NOOP("QShortcut", "Cut") },
    { Qt::Key_Display,                    QT_TRANSLATE_NOOP("QShortcut", "Display") },
    { Qt::Key_DOS,                        QT_TRANSLATE_NOOP("QShortcut", "DOS") },
    { Qt::Key_Documents,                  QT_TRANSLATE_NOOP("QShortcut", "Documents") },
    { Qt::Key_Excel,                      QT_TRANSLATE_NOOP("QShortcut", "Spreadsheet") },
    { Qt::Key_Explorer,                   QT_TRANSLATE_NOOP("QShortcut", "Browser") },
    { Qt::Key_Game,                       QT_TRANSLATE_NOOP("QShortcut", "Game") },
    { Qt::Key_Go,                         QT_TRANSLATE_NOOP("QShortcut", "Go") },
    { Qt::Key_iTouch,                     QT_TRANSLATE_NOOP("QShortcut", "iTouch") },
    { Qt::Key_LogOff,                     QT_TRANSLATE_NOOP("QShortcut", "Logoff") },
    { Qt::Key_Market,                     QT_TRANSLATE_NOOP("QShortcut", "Market") },
    { Qt::Key_Meeting,                    QT_TRANSLATE_NOOP("QShortcut", "Meeting") },
    { Qt::Key_Memo,                       QT_TRANSLATE_NOOP("QShortcut", "Memo") },
    { Qt::Key_MenuKB,                     QT_TRANSLATE_NOOP("QShortcut", "Keyboard Menu") },
    { Qt::Key_MenuPB,                     QT_TRANSLATE_NOOP("QShortcut", "Menu PB") },
    { Qt::Key_MySites,                    QT_TRANSLATE_NOOP("QShortcut", "My Sites") },
    { Qt::Key_News,                       QT_TRANSLATE_NOOP("QShortcut", "News") },
    { Qt::Key_OfficeHome,                 QT_TRANSLATE_NOOP("QShortcut", "Home Office") },
    { Qt::Key_Option,                     QT_TRANSLATE_NOOP("QShortcut", "Option") },
    { Qt::Key_Paste,                      QT_TRANSLATE_NOOP("QShortcut", "Paste") },
    { Qt::Key_Phone,                      QT_TRANSLATE_NOOP("QShortcut", "Phone") },
    { Qt::Key_Reply,                      QT_TRANSLATE_NOOP("QShortcut", "Reply") },
    { Qt::Key_Reload,                     QT_TRANSLATE_NOOP("QShortcut", "Reload") },
    { Qt::Key_RotateWindows,              QT_TRANSLATE_NOOP("QShortcut", "Rotate Windows") },
    { Qt::Key_RotationPB,                 QT_TRANSLATE_NOOP("QShortcut", "Rotation PB") },
    { Qt::Key_RotationKB,                 QT_TRANSLATE_NOOP("QShortcut", "Rotation KB") },
    { Qt::Key_Save,                       QT_TRANSLATE_NOOP("QShortcut", "Save") },
    { Qt::Key_Send,                       QT_TRANSLATE_NOOP("QShortcut", "Send") },
    { Qt::Key_Spell,                      QT_TRANSLATE_NOOP("QShortcut", "Spellchecker") },
    { Qt::Key_SplitScreen,                QT_TRANSLATE_NOOP("QShortcut", "Split Screen") },
    { Qt::Key_Support,                    QT_TRANSLATE_NOOP("QShortcut", "Support") },
    { Qt::Key_TaskPane,                   QT_TRANSLATE_NOOP("QShortcut", "Task Panel") },
    { Qt::Key_Terminal,                   QT_TRANSLATE_NOOP("QShortcut", "Terminal") },
    { Qt::Key_ToDoList,                   QT_TRANSLATE_NOOP("QShortcut", "To-do list") },
    { Qt::Key_Tools,                      QT_TRANSLATE_NOOP("QShortcut", "Tools") },
    { Qt::Key_Travel,                     QT_TRANSLATE_NOOP("QShortcut", "Travel") },
    { Qt::Key_Video,                      QT_TRANSLATE_NOOP("QShortcut", "Video") },
    { Qt::Key_Word,                       QT_TRANSLATE_NOOP("QShortcut", "Word Processor") },
    { Qt::Key_Xfer,                       QT_TRANSLATE_NOOP("QShortcut", "XFer") },
    { Qt::Key_ZoomIn,                     QT_TRANSLATE_NOOP("QShortcut", "Zoom In") },
    { Qt::Key_ZoomOut,                    QT_TRANSLATE_NOOP("QShortcut", "Zoom Out") },
    { Qt::Key_Away,                       QT_TRANSLATE_NOOP("QShortcut", "Away") },
    { Qt::Key_Messenger,                  QT_TRANSLATE_NOOP("QShortcut", "Messenger") },
    { Qt::Key_WebCam,                     QT_TRANSLATE_NOOP("QShortcut", "WebCam") },
    { Qt::Key_MailForward,                QT_TRANSLATE_NOOP("QShortcut", "Mail Forward") },
    { Qt::Key_Pictures,                   QT_TRANSLATE_NOOP("QShortcut", "Pictures") },
    { Qt::Key_Music,                      QT_TRANSLATE_NOOP("QShortcut", "Music") },
    { Qt::Key_Battery,                    QT_TRANSLATE_NOOP("QShortcut", "Battery") },
    { Qt::Key_Bluetooth,                  QT_TRANSLATE_NOOP("QShortcut", "Bluetooth") },
    { Qt::Key_WLAN,                       QT_TRANSLATE_NOOP("QShortcut", "Wireless") },
    { Qt::Key_UWB,                        QT_TRANSLATE_NOOP("QShortcut", "Ultra Wide Band") },
    { Qt::Key_AudioForward,               QT_TRANSLATE_NOOP("QShortcut", "Media Fast Forward") },
    { Qt::Key_AudioRepeat,                QT_TRANSLATE_NOOP("QShortcut", "Audio Repeat") },
    { Qt::Key_AudioRandomPlay,            QT_TRANSLATE_NOOP("QShortcut", "Audio Random Play") },
    { Qt::Key_Subtitle,                   QT_TRANSLATE_NOOP("QShortcut", "Subtitle") },
    { Qt::Key_AudioCycleTrack,            QT_TRANSLATE_NOOP("QShortcut", "Audio Cycle Track") },
    { Qt::Key_Time,                       QT_TRANSLATE_NOOP("QShortcut", "Time") },
    { Qt::Key_Hibernate,                  QT_TRANSLATE_NOOP("QShortcut", "Hibernate") },
    { Qt::Key_View,                       QT_TRANSLATE_NOOP("QShortcut", "View") },
    { Qt::Key_TopMenu,                    QT_TRANSLATE_NOOP("QShortcut", "Top Menu") },
    { Qt::Key_PowerDown,                  QT_TRANSLATE_NOOP("QShortcut", "Power Down") },
    { Qt::Key_Suspend,                    QT_TRANSLATE_NOOP("QShortcut", "Suspend") },

    { Qt::Key_MicMute,                    QT_TRANSLATE_NOOP("QShortcut", "Microphone Mute") },

    { Qt::Key_Red,                        QT_TRANSLATE_NOOP("QShortcut", "Red") },
    { Qt::Key_Green,                      QT_TRANSLATE_NOOP("QShortcut", "Green") },
    { Qt::Key_Yellow,                     QT_TRANSLATE_NOOP("QShortcut", "Yellow") },
    { Qt::Key_Blue,                       QT_TRANSLATE_NOOP("QShortcut", "Blue") },

    { Qt::Key_ChannelUp,                  QT_TRANSLATE_NOOP("QShortcut", "Channel Up") },
    { Qt::Key_ChannelDown,                QT_TRANSLATE_NOOP("QShortcut", "Channel Down") },

    { Qt::Key_Guide,                      QT_TRANSLATE_NOOP("QShortcut", "Guide") },
    { Qt::Key_Info,                       QT_TRANSLATE_NOOP("QShortcut", "Info") },
    { Qt::Key_Settings,                   QT_TRANSLATE_NOOP("QShortcut", "Settings") },

    { Qt::Key_MicVolumeUp,                QT_TRANSLATE_NOOP("QShortcut", "Microphone Volume Up") },
    { Qt::Key_MicVolumeDown,              QT_TRANSLATE_NOOP("QShortcut", "Microphone Volume Down") },

    { Qt::Key_New,                        QT_TRANSLATE_NOOP("QShortcut", "New") },
    { Qt::Key_Open,                       QT_TRANSLATE_NOOP("QShortcut", "Open") },
    { Qt::Key_Find,                       QT_TRANSLATE_NOOP("QShortcut", "Find") },
    { Qt::Key_Undo,                       QT_TRANSLATE_NOOP("QShortcut", "Undo") },
    { Qt::Key_Redo,                       QT_TRANSLATE_NOOP("QShortcut", "Redo") },

    // --------------------------------------------------------------
    // More consistent namings
    { Qt::Key_Print,        QT_TRANSLATE_NOOP("QShortcut", "Print Screen") },
    { Qt::Key_PageUp,       QT_TRANSLATE_NOOP("QShortcut", "Page Up") },
    { Qt::Key_PageDown,     QT_TRANSLATE_NOOP("QShortcut", "Page Down") },
    { Qt::Key_CapsLock,     QT_TRANSLATE_NOOP("QShortcut", "Caps Lock") },
    { Qt::Key_NumLock,      QT_TRANSLATE_NOOP("QShortcut", "Num Lock") },
    { Qt::Key_NumLock,      QT_TRANSLATE_NOOP("QShortcut", "Number Lock") },
    { Qt::Key_ScrollLock,   QT_TRANSLATE_NOOP("QShortcut", "Scroll Lock") },
    { Qt::Key_Insert,       QT_TRANSLATE_NOOP("QShortcut", "Insert") },
    { Qt::Key_Delete,       QT_TRANSLATE_NOOP("QShortcut", "Delete") },
    { Qt::Key_Escape,       QT_TRANSLATE_NOOP("QShortcut", "Escape") },
    { Qt::Key_SysReq,       QT_TRANSLATE_NOOP("QShortcut", "System Request") },

    // --------------------------------------------------------------
    // Keypad navigation keys
    { Qt::Key_Select,       QT_TRANSLATE_NOOP("QShortcut", "Select") },
    { Qt::Key_Yes,          QT_TRANSLATE_NOOP("QShortcut", "Yes") },
    { Qt::Key_No,           QT_TRANSLATE_NOOP("QShortcut", "No") },

    // --------------------------------------------------------------
    // Device keys
    { Qt::Key_Context1,         QT_TRANSLATE_NOOP("QShortcut", "Context1") },
    { Qt::Key_Context2,         QT_TRANSLATE_NOOP("QShortcut", "Context2") },
    { Qt::Key_Context3,         QT_TRANSLATE_NOOP("QShortcut", "Context3") },
    { Qt::Key_Context4,         QT_TRANSLATE_NOOP("QShortcut", "Context4") },
    //: Button to start a call (note: a separate button is used to end the call)
    { Qt::Key_Call,             QT_TRANSLATE_NOOP("QShortcut", "Call") },
    //: Button to end a call (note: a separate button is used to start the call)
    { Qt::Key_Hangup,           QT_TRANSLATE_NOOP("QShortcut", "Hangup") },
    //: Button that will hang up if we're in call, or make a call if we're not.
    { Qt::Key_ToggleCallHangup, QT_TRANSLATE_NOOP("QShortcut", "Toggle Call/Hangup") },
    { Qt::Key_Flip,             QT_TRANSLATE_NOOP("QShortcut", "Flip") },
    //: Button to trigger voice dialing
    { Qt::Key_VoiceDial,        QT_TRANSLATE_NOOP("QShortcut", "Voice Dial") },
    //: Button to redial the last number called
    { Qt::Key_LastNumberRedial, QT_TRANSLATE_NOOP("QShortcut", "Last Number Redial") },
    //: Button to trigger the camera shutter (take a picture)
    { Qt::Key_Camera,           QT_TRANSLATE_NOOP("QShortcut", "Camera Shutter") },
    //: Button to focus the camera
    { Qt::Key_CameraFocus,      QT_TRANSLATE_NOOP("QShortcut", "Camera Focus") },

    // --------------------------------------------------------------
    // Japanese keyboard support
    { Qt::Key_Kanji,            QT_TRANSLATE_NOOP("QShortcut", "Kanji") },
    { Qt::Key_Muhenkan,         QT_TRANSLATE_NOOP("QShortcut", "Muhenkan") },
    { Qt::Key_Henkan,           QT_TRANSLATE_NOOP("QShortcut", "Henkan") },
    { Qt::Key_Romaji,           QT_TRANSLATE_NOOP("QShortcut", "Romaji") },
    { Qt::Key_Hiragana,         QT_TRANSLATE_NOOP("QShortcut", "Hiragana") },
    { Qt::Key_Katakana,         QT_TRANSLATE_NOOP("QShortcut", "Katakana") },
    { Qt::Key_Hiragana_Katakana,QT_TRANSLATE_NOOP("QShortcut", "Hiragana Katakana") },
    { Qt::Key_Zenkaku,          QT_TRANSLATE_NOOP("QShortcut", "Zenkaku") },
    { Qt::Key_Hankaku,          QT_TRANSLATE_NOOP("QShortcut", "Hankaku") },
    { Qt::Key_Zenkaku_Hankaku,  QT_TRANSLATE_NOOP("QShortcut", "Zenkaku Hankaku") },
    { Qt::Key_Touroku,          QT_TRANSLATE_NOOP("QShortcut", "Touroku") },
    { Qt::Key_Massyo,           QT_TRANSLATE_NOOP("QShortcut", "Massyo") },
    { Qt::Key_Kana_Lock,        QT_TRANSLATE_NOOP("QShortcut", "Kana Lock") },
    { Qt::Key_Kana_Shift,       QT_TRANSLATE_NOOP("QShortcut", "Kana Shift") },
    { Qt::Key_Eisu_Shift,       QT_TRANSLATE_NOOP("QShortcut", "Eisu Shift") },
    { Qt::Key_Eisu_toggle,      QT_TRANSLATE_NOOP("QShortcut", "Eisu toggle") },
    { Qt::Key_Codeinput,        QT_TRANSLATE_NOOP("QShortcut", "Code input") },
    { Qt::Key_MultipleCandidate,QT_TRANSLATE_NOOP("QShortcut", "Multiple Candidate") },
    { Qt::Key_PreviousCandidate,QT_TRANSLATE_NOOP("QShortcut", "Previous Candidate") },

    // --------------------------------------------------------------
    // Korean keyboard support
    { Qt::Key_Hangul,          QT_TRANSLATE_NOOP("QShortcut", "Hangul") },
    { Qt::Key_Hangul_Start,    QT_TRANSLATE_NOOP("QShortcut", "Hangul Start") },
    { Qt::Key_Hangul_End,      QT_TRANSLATE_NOOP("QShortcut", "Hangul End") },
    { Qt::Key_Hangul_Hanja,    QT_TRANSLATE_NOOP("QShortcut", "Hangul Hanja") },
    { Qt::Key_Hangul_Jamo,     QT_TRANSLATE_NOOP("QShortcut", "Hangul Jamo") },
    { Qt::Key_Hangul_Romaja,   QT_TRANSLATE_NOOP("QShortcut", "Hangul Romaja") },
    { Qt::Key_Hangul_Jeonja,   QT_TRANSLATE_NOOP("QShortcut", "Hangul Jeonja") },
    { Qt::Key_Hangul_Banja,    QT_TRANSLATE_NOOP("QShortcut", "Hangul Banja") },
    { Qt::Key_Hangul_PreHanja, QT_TRANSLATE_NOOP("QShortcut", "Hangul PreHanja") },
    { Qt::Key_Hangul_PostHanja,QT_TRANSLATE_NOOP("QShortcut", "Hangul PostHanja") },
    { Qt::Key_Hangul_Special,  QT_TRANSLATE_NOOP("QShortcut", "Hangul Special") },

    // --------------------------------------------------------------
    // Miscellaneous keys
    { Qt::Key_Cancel,  QT_TRANSLATE_NOOP("QShortcut", "Cancel") },
    { Qt::Key_Printer,  QT_TRANSLATE_NOOP("QShortcut", "Printer") },
    { Qt::Key_Execute,  QT_TRANSLATE_NOOP("QShortcut", "Execute") },
    { Qt::Key_Play,  QT_TRANSLATE_NOOP("QShortcut", "Play") },
    { Qt::Key_Zoom,  QT_TRANSLATE_NOOP("QShortcut", "Zoom") },
    { Qt::Key_Exit,  QT_TRANSLATE_NOOP("QShortcut", "Exit") },
    { Qt::Key_TouchpadToggle,  QT_TRANSLATE_NOOP("QShortcut", "Touchpad Toggle") },
    { Qt::Key_TouchpadOn,  QT_TRANSLATE_NOOP("QShortcut", "Touchpad On") },
    { Qt::Key_TouchpadOff,  QT_TRANSLATE_NOOP("QShortcut", "Touchpad Off") },
    { Qt::Key_Shift,  QT_TRANSLATE_NOOP("QShortcut", "Shift") },
    { Qt::Key_Control,  QT_TRANSLATE_NOOP("QShortcut", "Control") },
    { Qt::Key_Alt,  QT_TRANSLATE_NOOP("QShortcut", "Alt") },
    { Qt::Key_Meta,  QT_TRANSLATE_NOOP("QShortcut", "Meta") },

};
static constexpr int numKeyNames = sizeof keyname / sizeof *keyname;

/*!
    \enum QKeySequence::StandardKey
    \since 4.2

    This enum represent standard key bindings. They can be used to
    assign platform dependent keyboard shortcuts to a QAction.

    Note that the key bindings are platform dependent. The currently
    bound shortcuts can be queried using keyBindings().

    \value AddTab           Add new tab.
    \value Back             Navigate back.
    \value Backspace        Delete previous character.
    \value Bold             Bold text.
    \value Close            Close document/tab.
    \value Copy             Copy.
    \value Cut              Cut.
    \value Delete           Delete.
    \value DeleteEndOfLine          Delete end of line.
    \value DeleteEndOfWord          Delete word from the end of the cursor.
    \value DeleteStartOfWord        Delete the beginning of a word up to the cursor.
    \value DeleteCompleteLine       Delete the entire line.
    \value Find             Find in document.
    \value FindNext         Find next result.
    \value FindPrevious     Find previous result.
    \value Forward          Navigate forward.
    \value HelpContents     Open help contents.
    \value InsertLineSeparator      Insert a new line.
    \value InsertParagraphSeparator Insert a new paragraph.
    \value Italic           Italic text.
    \value MoveToEndOfBlock         Move cursor to end of block. This shortcut is only used on Apple platforms.
    \value MoveToEndOfDocument      Move cursor to end of document.
    \value MoveToEndOfLine          Move cursor to end of line.
    \value MoveToNextChar           Move cursor to next character.
    \value MoveToNextLine           Move cursor to next line.
    \value MoveToNextPage           Move cursor to next page.
    \value MoveToNextWord           Move cursor to next word.
    \value MoveToPreviousChar       Move cursor to previous character.
    \value MoveToPreviousLine       Move cursor to previous line.
    \value MoveToPreviousPage       Move cursor to previous page.
    \value MoveToPreviousWord       Move cursor to previous word.
    \value MoveToStartOfBlock       Move cursor to start of a block. This shortcut is only used on Apple platforms.
    \value MoveToStartOfDocument    Move cursor to start of document.
    \value MoveToStartOfLine        Move cursor to start of line.
    \value New              Create new document.
    \value NextChild        Navigate to next tab or child window.
    \value Open             Open document.
    \value Paste            Paste.
    \value Preferences      Open the preferences dialog.
    \value PreviousChild    Navigate to previous tab or child window.
    \value Print            Print document.
    \value Quit             Quit the application.
    \value Redo             Redo.
    \value Refresh          Refresh or reload current document.
    \value Replace          Find and replace.
    \value SaveAs           Save document after prompting the user for a file name.
    \value Save             Save document.
    \value SelectAll        Select all text.
    \value Deselect         Deselect text. Since 5.1
    \value SelectEndOfBlock         Extend selection to the end of a text block. This shortcut is only used on Apple platforms.
    \value SelectEndOfDocument      Extend selection to end of document.
    \value SelectEndOfLine          Extend selection to end of line.
    \value SelectNextChar           Extend selection to next character.
    \value SelectNextLine           Extend selection to next line.
    \value SelectNextPage           Extend selection to next page.
    \value SelectNextWord           Extend selection to next word.
    \value SelectPreviousChar       Extend selection to previous character.
    \value SelectPreviousLine       Extend selection to previous line.
    \value SelectPreviousPage       Extend selection to previous page.
    \value SelectPreviousWord       Extend selection to previous word.
    \value SelectStartOfBlock       Extend selection to the start of a text block. This shortcut is only used on Apple platforms.
    \value SelectStartOfDocument    Extend selection to start of document.
    \value SelectStartOfLine        Extend selection to start of line.
    \value Underline        Underline text.
    \value Undo             Undo.
    \value UnknownKey       Unbound key.
    \value WhatsThis        Activate "what's this".
    \value ZoomIn           Zoom in.
    \value ZoomOut          Zoom out.
    \value FullScreen       Toggle the window state to/from full screen.
    \value Cancel           Cancel the current operation.
*/

/*!
    \fn QKeySequence &QKeySequence::operator=(QKeySequence &&other)

    Move-assigns \a other to this QKeySequence instance.

    \since 5.2
*/

/*!
    \since 4.2

    Constructs a QKeySequence object for the given \a key.
    The result will depend on the currently running platform.

    The resulting object will be based on the first element in the
    list of key bindings for the \a key.
*/
QKeySequence::QKeySequence(StandardKey key)
{
    const QList <QKeySequence> bindings = keyBindings(key);
    //pick only the first/primary shortcut from current bindings
    if (!bindings.isEmpty()) {
        d = bindings.constFirst().d;
        d->ref.ref();
    }
    else
        d = new QKeySequencePrivate();
}


/*!
    Constructs an empty key sequence.
*/
QKeySequence::QKeySequence()
{
    Q_CONSTINIT static QKeySequencePrivate shared_empty;
    d = &shared_empty;
    d->ref.ref();
}

/*!
    Creates a key sequence from the \a key string, based on \a format.

    For example "Ctrl+O" gives CTRL+'O'. The strings "Ctrl",
    "Shift", "Alt" and "Meta" are recognized, as well as their
    translated equivalents in the "QShortcut" context (using
    QObject::tr()).

    Up to four key codes may be entered by separating them with
    commas, e.g. "Alt+X,Ctrl+S,Q".

    This constructor is typically used with \l{QObject::tr()}{tr}(), so
    that shortcut keys can be replaced in translations:

    \snippet code/src_gui_kernel_qkeysequence.cpp 2

    Note the "File|Open" translator comment. It is by no means
    necessary, but it provides some context for the human translator.
*/
QKeySequence::QKeySequence(const QString &key, QKeySequence::SequenceFormat format)
{
    d = new QKeySequencePrivate();
    assign(key, format);
}

static_assert(QKeySequencePrivate::MaxKeyCount == 4, "Change docs and ctor impl below");
/*!
    Constructs a key sequence with up to 4 keys \a k1, \a k2,
    \a k3 and \a k4.

    The key codes are listed in Qt::Key and can be combined with
    modifiers (see Qt::KeyboardModifier) such as Qt::ShiftModifier,
    Qt::ControlModifier, Qt::AltModifier, or Qt::MetaModifier.
*/
QKeySequence::QKeySequence(int k1, int k2, int k3, int k4)
{
    d = new QKeySequencePrivate();
    d->key[0] = k1;
    d->key[1] = k2;
    d->key[2] = k3;
    d->key[3] = k4;
}

/*!
    Constructs a key sequence with up to 4 keys \a k1, \a k2,
    \a k3 and \a k4.

    \sa QKeyCombination
*/
QKeySequence::QKeySequence(QKeyCombination k1, QKeyCombination k2, QKeyCombination k3, QKeyCombination k4)
    : QKeySequence(k1.toCombined(), k2.toCombined(), k3.toCombined(), k4.toCombined())
{
}

/*!
    Copy constructor. Makes a copy of \a keysequence.
 */
QKeySequence::QKeySequence(const QKeySequence& keysequence)
    : d(keysequence.d)
{
    d->ref.ref();
}

/*!
    \since 4.2

    Returns a list of key bindings for the given \a key.
    The result of calling this function will vary based on the target platform.
    The first element of the list indicates the primary shortcut for the given platform.
    If the result contains more than one result, these can
    be considered alternative shortcuts on the same platform for the given \a key.
*/
QList<QKeySequence> QKeySequence::keyBindings(StandardKey key)
{
    return QGuiApplicationPrivate::platformTheme()->keyBindings(key);
}

/*!
    Destroys the key sequence.
 */
QKeySequence::~QKeySequence()
{
    if (!d->ref.deref())
        delete d;
}

/*!
    \internal
    KeySequences should never be modified, but rather just created.
    Internally though we do need to modify to keep pace in event
    delivery.
*/

void QKeySequence::setKey(QKeyCombination key, int index)
{
    Q_ASSERT_X(index >= 0 && index < QKeySequencePrivate::MaxKeyCount, "QKeySequence::setKey", "index out of range");
    qAtomicDetach(d);
    d->key[index] = key.toCombined();
}

static_assert(QKeySequencePrivate::MaxKeyCount == 4, "Change docs below");
/*!
    Returns the number of keys in the key sequence.
    The maximum is 4.
 */
int QKeySequence::count() const
{
    return int(std::distance(d->key, std::find(d->key, d->key + QKeySequencePrivate::MaxKeyCount, 0)));
}


/*!
    Returns \c true if the key sequence is empty; otherwise returns
    false.
*/
bool QKeySequence::isEmpty() const
{
    return !d->key[0];
}


/*!
    Returns the shortcut key sequence for the mnemonic in \a text,
    or an empty key sequence if no mnemonics are found.

    For example, mnemonic("E&xit") returns \c{Qt::ALT+Qt::Key_X},
    mnemonic("&Quit") returns \c{ALT+Key_Q}, and mnemonic("Quit")
    returns an empty QKeySequence.
*/
QKeySequence QKeySequence::mnemonic(const QString &text)
{
    QKeySequence ret;

    if (qt_sequence_no_mnemonics)
        return ret;

    bool found = false;
    qsizetype p = 0;
    while (p >= 0) {
        p = text.indexOf(u'&', p) + 1;
        if (p <= 0 || p >= (int)text.size())
            break;
        if (text.at(p) != u'&') {
            QChar c = text.at(p);
            if (c.isPrint()) {
                if (!found) {
                    c = c.toUpper();
                    ret = QKeySequence(QKeyCombination(Qt::ALT, Qt::Key(c.unicode())));
#ifdef QT_NO_DEBUG
                    return ret;
#else
                    found = true;
                } else {
                    qWarning("QKeySequence::mnemonic: \"%s\" contains multiple occurrences of '&'", qPrintable(text));
#endif
                }
            }
        }
        p++;
    }
    return ret;
}

/*!
    \fn int QKeySequence::assign(const QString &keys)

    Adds the given \a keys to the key sequence. \a keys may
    contain up to four key codes, provided they are separated by a
    comma; for example, "Alt+X,Ctrl+S,Z". The return value is the
    number of key codes added.
    \a keys should be in NativeText format.
*/
int QKeySequence::assign(const QString &ks)
{
    return assign(ks, NativeText);
}

/*!
    \fn int QKeySequence::assign(const QString &keys, QKeySequence::SequenceFormat format)
    \since 4.7

    Adds the given \a keys to the key sequence (based on \a format).
    \a keys may contain up to four key codes, provided they are
    separated by a comma; for example, "Alt+X,Ctrl+S,Z". The return
    value is the number of key codes added.
*/
int QKeySequence::assign(const QString &ks, QKeySequence::SequenceFormat format)
{
    QString keyseq = ks;
    int n = 0;
    qsizetype p = 0, diff = 0;

    // Run through the whole string, but stop
    // if we have MaxKeyCount keys before the end.
    while (keyseq.size() && n < QKeySequencePrivate::MaxKeyCount) {
        // We MUST use something to separate each sequence, and space
        // does not cut it, since some of the key names have space
        // in them.. (Let's hope no one translate with a comma in it:)
        p = keyseq.indexOf(u',');
        if (-1 != p) {
            if (p == keyseq.size() - 1) { // Last comma 'Ctrl+,'
                p = -1;
            } else {
                if (u',' == keyseq.at(p+1)) // e.g. 'Ctrl+,, Shift+,,'
                    p++;
                if (u' ' == keyseq.at(p+1)) { // Space after comma
                    diff = 1;
                    p++;
                } else {
                    diff = 0;
                }
            }
        }
        QString part = keyseq.left(-1 == p ? keyseq.size() : p - diff);
        keyseq = keyseq.right(-1 == p ? 0 : keyseq.size() - (p + 1));
        d->key[n] = QKeySequencePrivate::decodeString(std::move(part), format).toCombined();
        ++n;
    }
    return n;
}

struct QModifKeyName {
    QModifKeyName() { }
    QModifKeyName(int q, QChar n) : qt_key(q), name(n) { }
    QModifKeyName(int q, const QString &n) : qt_key(q), name(n) { }
    int qt_key;
    QString name;
};
Q_DECLARE_TYPEINFO(QModifKeyName, Q_RELOCATABLE_TYPE);

Q_GLOBAL_STATIC(QList<QModifKeyName>, globalModifs)
Q_GLOBAL_STATIC(QList<QModifKeyName>, globalPortableModifs)

QKeyCombination QKeySequencePrivate::decodeString(QString accel, QKeySequence::SequenceFormat format)
{
    Q_ASSERT(!accel.isEmpty());

    int ret = 0;
    accel = std::move(accel).toLower();
    bool nativeText = (format == QKeySequence::NativeText);

    QList<QModifKeyName> *gmodifs;
    if (nativeText) {
        gmodifs = globalModifs();
        if (gmodifs->isEmpty()) {
#if defined(Q_OS_APPLE)
            const bool dontSwap = qApp->testAttribute(Qt::AA_MacDontSwapCtrlAndMeta);
            if (dontSwap)
                *gmodifs << QModifKeyName(Qt::META, QChar(kCommandUnicode));
            else
                *gmodifs << QModifKeyName(Qt::CTRL, QChar(kCommandUnicode));
            *gmodifs << QModifKeyName(Qt::ALT, QChar(kOptionUnicode));
            if (dontSwap)
                *gmodifs << QModifKeyName(Qt::CTRL, QChar(kControlUnicode));
            else
                *gmodifs << QModifKeyName(Qt::META, QChar(kControlUnicode));
            *gmodifs << QModifKeyName(Qt::SHIFT, QChar(kShiftUnicode));
#endif
            *gmodifs << QModifKeyName(Qt::CTRL, u"ctrl+"_s)
                     << QModifKeyName(Qt::SHIFT, u"shift+"_s)
                     << QModifKeyName(Qt::ALT, u"alt+"_s)
                     << QModifKeyName(Qt::META, u"meta+"_s)
                     << QModifKeyName(Qt::KeypadModifier, u"num+"_s);
        }
    } else {
        gmodifs = globalPortableModifs();
        if (gmodifs->isEmpty()) {
            *gmodifs << QModifKeyName(Qt::CTRL, u"ctrl+"_s)
                     << QModifKeyName(Qt::SHIFT, u"shift+"_s)
                     << QModifKeyName(Qt::ALT, u"alt+"_s)
                     << QModifKeyName(Qt::META, u"meta+"_s)
                     << QModifKeyName(Qt::KeypadModifier, u"num+"_s);
        }
    }


    QList<QModifKeyName> modifs;
    if (nativeText) {
        modifs << QModifKeyName(Qt::CTRL, QCoreApplication::translate("QShortcut", "Ctrl").toLower().append(u'+'))
               << QModifKeyName(Qt::SHIFT, QCoreApplication::translate("QShortcut", "Shift").toLower().append(u'+'))
               << QModifKeyName(Qt::ALT, QCoreApplication::translate("QShortcut", "Alt").toLower().append(u'+'))
               << QModifKeyName(Qt::META, QCoreApplication::translate("QShortcut", "Meta").toLower().append(u'+'))
               << QModifKeyName(Qt::KeypadModifier, QCoreApplication::translate("QShortcut", "Num").toLower().append(u'+'));
    }
    modifs += *gmodifs; // Test non-translated ones last

    QString sl = accel;
#if defined(Q_OS_APPLE)
    for (int i = 0; i < modifs.size(); ++i) {
        const QModifKeyName &mkf = modifs.at(i);
        if (sl.contains(mkf.name)) {
            ret |= mkf.qt_key;
            accel.remove(mkf.name);
            sl = accel;
        }
    }
    if (accel.isEmpty()) // Incomplete, like for "Meta+Shift+"
        return Qt::Key_unknown;
#endif

    int singlePlus = -1;
    qsizetype i = 0;
    qsizetype lastI = 0;
    while ((i = sl.indexOf(u'+', i + 1)) != -1) {
        QStringView sub = QStringView{ sl }.mid(lastI, i - lastI + 1);
        while (sub.size() > 1 && sub.at(0) == u' ') {
            sub = sub.mid(1);
            ++lastI;
        }

        // If we get here the shortcuts contains at least one '+'. We break up
        // along the following strategy:
        //      Meta+Ctrl++   ( "Meta+", "Ctrl+", "+" )
        //      Super+Shift+A ( "Super+", "Shift+" )
        //      4+3+2=1       ( "4+", "3+" )
        // In other words, everything we try to handle HAS to be a modifier
        // except for a single '+' at the end of the string.

        // Only '+' can have length 1.
        if (sub.size() == 1) {
            // Make sure we only encounter a single '+' at the end of the accel
            if (singlePlus >= 0)
                return Qt::Key_unknown;
            singlePlus = lastI;
        } else {

            const auto identifyModifier = [&](QStringView sub) {
                for (int j = 0; j < modifs.size(); ++j) {
                    const QModifKeyName &mkf = modifs.at(j);
                    if (sub == mkf.name) {
                        ret |= mkf.qt_key;
                        return true; // Shortcut, since if we find another it would/should just be a dup
                    }
                }
                return false;
            };

            bool validModifier = identifyModifier(sub);

            if (!validModifier) {
                // Try harder with slower code that trims spaces
                const QString cleanedSub = sub.toString().remove(u' ');
                validModifier = identifyModifier(cleanedSub);
            }
            if (!validModifier)
                return Qt::Key_unknown;
        }
        lastI = i + 1;
    }

    qsizetype p = accel.lastIndexOf(u'+', singlePlus > 0 ? singlePlus - 1 : accel.size() - 1);
    QStringView accelRef(accel);
    if (p > 0)
        accelRef = accelRef.mid(p + 1);

    while (accelRef.size() > 1 && accelRef.at(0) == u' ')
        accelRef = accelRef.mid(1);
    while (accelRef.size() > 1 && accelRef.endsWith(u' '))
        accelRef.chop(1);

    int fnum = 0;
    if (accelRef.isEmpty())
        return Qt::Key_unknown;
    else if (accelRef.size() == 1) {
#if defined(Q_OS_APPLE)
        int qtKey = qtkeyForAppleSymbol(accelRef.at(0));
        if (qtKey != -1) {
            ret |= qtKey;
        } else
#endif
        {
            ret |= accelRef.at(0).toUpper().unicode();
        }
    } else if (accelRef.at(0) == u'f' && (fnum = accelRef.mid(1).toInt()) >= 1 && fnum <= 35) {
        ret |= Qt::Key_F1 + fnum - 1;
    } else {
        // For NativeText, check the translation table first,
        // if we don't find anything then try it out with just the untranlated stuff.
        // PortableText will only try the untranlated table.
        bool found = false;
        for (int tran = 0; tran < 2; ++tran) {
            if (!nativeText)
                ++tran;
            for (int i = 0; i < numKeyNames; ++i) {
                QString keyName(tran == 0
                                ? QCoreApplication::translate("QShortcut", keyname[i].name)
                                : QString::fromLatin1(keyname[i].name));
                if (accelRef == std::move(keyName).toLower()) {
                    ret |= keyname[i].key;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        // We couldn't translate the key.
        if (!found)
            return Qt::Key_unknown;
    }
    return QKeyCombination::fromCombined(ret);
}

static inline void addKey(QString &str, const QString &theKey, QKeySequence::SequenceFormat format)
{
    if (!str.isEmpty()) {
        if (format == QKeySequence::NativeText) {
            //: Key separator in shortcut string
            str += QCoreApplication::translate("QShortcut", "+");
        } else {
            str += u'+';
        }
    }

    str += theKey;
}

QString QKeySequencePrivate::encodeString(QKeyCombination keyCombination, QKeySequence::SequenceFormat format)
{
    bool nativeText = (format == QKeySequence::NativeText);
    QString s;

    const auto key = keyCombination.key();

    // Handle -1 (Invalid Key) and Qt::Key_unknown gracefully
    if (keyCombination.toCombined() == -1 || key == Qt::Key_unknown)
        return s;

    const auto modifiers = keyCombination.keyboardModifiers();

#if defined(Q_OS_APPLE)
    if (nativeText) {
        // On Apple platforms the order (by default) is Meta, Alt, Shift, Control.
        // If the AA_MacDontSwapCtrlAndMeta is enabled, then the order
        // is Ctrl, Alt, Shift, Meta. The appleSymbolForQtKey helper does this swap
        // for us, which means that we have to adjust our order here.
        // The upshot is a lot more infrastructure to keep the number of
        // if tests down and the code relatively clean.
        static constexpr int ModifierOrder[] = { Qt::META, Qt::ALT, Qt::SHIFT, Qt::CTRL, 0 };
        static constexpr int QtKeyOrder[] = { Qt::Key_Meta, Qt::Key_Alt, Qt::Key_Shift, Qt::Key_Control, 0 };
        static constexpr int DontSwapModifierOrder[] = { Qt::CTRL, Qt::ALT, Qt::SHIFT, Qt::META, 0 };
        static constexpr int DontSwapQtKeyOrder[] = { Qt::Key_Control, Qt::Key_Alt, Qt::Key_Shift, Qt::Key_Meta, 0 };
        const int *modifierOrder;
        const int *qtkeyOrder;
        if (qApp->testAttribute(Qt::AA_MacDontSwapCtrlAndMeta)) {
            modifierOrder = DontSwapModifierOrder;
            qtkeyOrder = DontSwapQtKeyOrder;
        } else {
            modifierOrder = ModifierOrder;
            qtkeyOrder = QtKeyOrder;
        }

        for (int i = 0; modifierOrder[i] != 0; ++i) {
            if (modifiers & modifierOrder[i])
                s += appleSymbolForQtKey(qtkeyOrder[i]);
        }
    } else
#endif
    {
        // On other systems the order is Meta, Control, Alt, Shift
        if (modifiers & Qt::MetaModifier)
            s = nativeText ? QCoreApplication::translate("QShortcut", "Meta") : QString::fromLatin1("Meta");
        if (modifiers & Qt::ControlModifier)
            addKey(s, nativeText ? QCoreApplication::translate("QShortcut", "Ctrl") : QString::fromLatin1("Ctrl"), format);
        if (modifiers & Qt::AltModifier)
            addKey(s, nativeText ? QCoreApplication::translate("QShortcut", "Alt") : QString::fromLatin1("Alt"), format);
        if (modifiers & Qt::ShiftModifier)
            addKey(s, nativeText ? QCoreApplication::translate("QShortcut", "Shift") : QString::fromLatin1("Shift"), format);
    }
    if (modifiers & Qt::KeypadModifier)
        addKey(s, nativeText ? QCoreApplication::translate("QShortcut", "Num") : QString::fromLatin1("Num"), format);

    QString keyName = QKeySequencePrivate::keyName(key, format);

#if defined(Q_OS_APPLE)
    if (nativeText)
        s += keyName;
    else
#endif
    addKey(s, keyName, format);
    return s;
}

/*!
    \internal
    Returns the text representation of the key \a key, which can be used i.e.
    when the sequence is serialized. This does not take modifiers into account
    (see encodeString() for a version that does).

    This static method is used by encodeString() and by the D-Bus menu exporter.
*/
QString QKeySequencePrivate::keyName(Qt::Key key, QKeySequence::SequenceFormat format)
{
    bool nativeText = (format == QKeySequence::NativeText);
    QString p;

    if (key && key < Qt::Key_Escape && key != Qt::Key_Space) {
        if (!QChar::requiresSurrogates(key)) {
            p = QChar::fromUcs2(key).toUpper();
        } else {
            p += QChar(QChar::highSurrogate(key));
            p += QChar(QChar::lowSurrogate(key));
        }
    } else if (key >= Qt::Key_F1 && key <= Qt::Key_F35) {
            p = nativeText ? QCoreApplication::translate("QShortcut", "F%1").arg(key - Qt::Key_F1 + 1)
                           : QString::fromLatin1("F%1").arg(key - Qt::Key_F1 + 1);
    } else if (key) {
        int i=0;
#if defined(Q_OS_APPLE)
        if (nativeText) {
            QChar ch = appleSymbolForQtKey(key);
            if (!ch.isNull())
                p = ch;
            else
                goto NonSymbol;
        } else
#endif
        {
#if defined(Q_OS_APPLE)
NonSymbol:
#endif
            while (i < numKeyNames) {
                if (key == keyname[i].key) {
                    p = nativeText ? QCoreApplication::translate("QShortcut", keyname[i].name)
                                   : QString::fromLatin1(keyname[i].name);
                    break;
                }
                ++i;
            }
            // If we can't find the actual translatable keyname,
            // fall back on the unicode representation of it...
            // Or else characters like Qt::Key_aring may not get displayed
            // (Really depends on you locale)
            if (i >= numKeyNames) {
                if (!QChar::requiresSurrogates(key)) {
                    p = QChar::fromUcs2(key).toUpper();
                } else {
                    p += QChar(QChar::highSurrogate(key));
                    p += QChar(QChar::lowSurrogate(key));
                }
            }
        }
    }
    return p;
}
/*!
    Matches the sequence with \a seq. Returns ExactMatch if
    successful, PartialMatch if \a seq matches incompletely,
    and NoMatch if the sequences have nothing in common.
    Returns NoMatch if \a seq is shorter.
*/
QKeySequence::SequenceMatch QKeySequence::matches(const QKeySequence &seq) const
{
    uint userN = count(),
          seqN = seq.count();

    if (userN > seqN)
        return NoMatch;

    // If equal in length, we have a potential ExactMatch sequence,
    // else we already know it can only be partial.
    SequenceMatch match = (userN == seqN ? ExactMatch : PartialMatch);

    for (uint i = 0; i < userN; ++i) {
        QKeyCombination userKey = (*this)[i],
                    sequenceKey = seq[i];
        if (userKey != sequenceKey)
            return NoMatch;
    }
    return match;
}

/*!
   Returns the key sequence as a QVariant
*/
QKeySequence::operator QVariant() const
{
    return QVariant::fromValue(*this);
}

/*!
    Returns a reference to the element at position \a index in the key
    sequence. This can only be used to read an element.
 */
QKeyCombination QKeySequence::operator[](uint index) const
{
    Q_ASSERT_X(index < QKeySequencePrivate::MaxKeyCount, "QKeySequence::operator[]", "index out of range");
    return QKeyCombination::fromCombined(d->key[index]);
}


/*!
    Assignment operator. Assigns the \a other key sequence to this
    object.
 */
QKeySequence &QKeySequence::operator=(const QKeySequence &other)
{
    qAtomicAssign(d, other.d);
    return *this;
}

/*!
    \fn void QKeySequence::swap(QKeySequence &other)
    \since 4.8
    \memberswap{key sequence}
*/

/*!
    \fn bool QKeySequence::operator!=(const QKeySequence &other) const

    Returns \c true if this key sequence is not equal to the \a other
    key sequence; otherwise returns \c false.
*/


/*!
    Returns \c true if this key sequence is equal to the \a other
    key sequence; otherwise returns \c false.
 */
bool QKeySequence::operator==(const QKeySequence &other) const
{
    return (d->key[0] == other.d->key[0] &&
            d->key[1] == other.d->key[1] &&
            d->key[2] == other.d->key[2] &&
            d->key[3] == other.d->key[3]);
}

/*!
    \since 5.6
    \qhashold{QKeySequence}
*/
size_t qHash(const QKeySequence &key, size_t seed) noexcept
{
    return qHashRange(key.d->key, key.d->key + QKeySequencePrivate::MaxKeyCount, seed);
}

/*!
    Provides an arbitrary comparison of this key sequence and
    \a other key sequence. All that is guaranteed is that the
    operator returns \c false if both key sequences are equal and
    that (ks1 \< ks2) == !( ks2 \< ks1) if the key sequences
    are not equal.

    This function is useful in some circumstances, for example
    if you want to use QKeySequence objects as keys in a QMap.

    \sa operator==(), operator!=(), operator>(), operator<=(), operator>=()
*/
bool QKeySequence::operator< (const QKeySequence &other) const
{
    return std::lexicographical_compare(d->key, d->key + QKeySequencePrivate::MaxKeyCount,
                                        other.d->key, other.d->key + QKeySequencePrivate::MaxKeyCount);
}

/*!
    \fn bool QKeySequence::operator> (const QKeySequence &other) const

    Returns \c true if this key sequence is larger than the \a other key
    sequence; otherwise returns \c false.

    \sa operator==(), operator!=(), operator<(), operator<=(), operator>=()
*/

/*!
    \fn bool QKeySequence::operator<= (const QKeySequence &other) const

    Returns \c true if this key sequence is smaller or equal to the
    \a other key sequence; otherwise returns \c false.

    \sa operator==(), operator!=(), operator<(), operator>(), operator>=()
*/

/*!
    \fn bool QKeySequence::operator>= (const QKeySequence &other) const

    Returns \c true if this key sequence is larger or equal to the
    \a other key sequence; otherwise returns \c false.

    \sa operator==(), operator!=(), operator<(), operator>(), operator<=()
*/

/*!
    \internal
*/
bool QKeySequence::isDetached() const
{
    return d->ref.loadRelaxed() == 1;
}

/*!
    \since 4.1

    Return a string representation of the key sequence,
    based on \a format.

    For example, the value Qt::CTRL+Qt::Key_O results in "Ctrl+O".
    If the key sequence has multiple key codes, each is separated
    by commas in the string returned, such as "Alt+X, Ctrl+Y, Z".
    The strings, "Ctrl", "Shift", etc. are translated using
    QObject::tr() in the "QShortcut" context.

    If the key sequence has no keys, an empty string is returned.

    On Apple platforms, the string returned resembles the sequence that is
    shown in the menu bar if \a format is
    QKeySequence::NativeText; otherwise, the string uses the
    "portable" format, suitable for writing to a file.

    \sa fromString()
*/
QString QKeySequence::toString(SequenceFormat format) const
{
    QString finalString;
    // A standard string, with no translation or anything like that. In some ways it will
    // look like our latin case on Windows and X11
    int end = count();
    for (int i = 0; i < end; ++i) {
        finalString += d->encodeString(QKeyCombination::fromCombined(d->key[i]), format);
        finalString += ", "_L1;
    }
    finalString.truncate(finalString.size() - 2);
    return finalString;
}

/*!
    \since 4.1

    Return a QKeySequence from the string \a str based on \a format.

    \sa toString()
*/
QKeySequence QKeySequence::fromString(const QString &str, SequenceFormat format)
{
    return QKeySequence(str, format);
}

/*!
    \since 5.1

    Return a list of QKeySequence from the string \a str based on \a format.

    \sa fromString()
    \sa listToString()
*/
QList<QKeySequence> QKeySequence::listFromString(const QString &str, SequenceFormat format)
{
    QList<QKeySequence> result;

    const QStringList strings = str.split("; "_L1);
    result.reserve(strings.size());
    for (const QString &string : strings) {
        result << fromString(string, format);
    }

    return result;
}

/*!
    \since 5.1

    Return a string representation of \a list based on \a format.

    \sa toString()
    \sa listFromString()
*/
QString QKeySequence::listToString(const QList<QKeySequence> &list, SequenceFormat format)
{
    QString result;

    for (const QKeySequence &sequence : list) {
        result += sequence.toString(format);
        result += "; "_L1;
    }
    result.truncate(result.size() - 2);

    return result;
}

/*****************************************************************************
  QKeySequence stream functions
 *****************************************************************************/
#if !defined(QT_NO_DATASTREAM)
/*!
    \fn QDataStream &operator<<(QDataStream &stream, const QKeySequence &sequence)
    \relates QKeySequence

    Writes the key \a sequence to the \a stream.

    \sa{Serializing Qt Data Types}{Format of the QDataStream operators}
*/
QDataStream &operator<<(QDataStream &s, const QKeySequence &keysequence)
{
    static_assert(QKeySequencePrivate::MaxKeyCount == 4, "Forgot to adapt QDataStream &operator<<(QDataStream &s, const QKeySequence &keysequence) to new QKeySequence::MaxKeyCount");
    const bool extended = s.version() >= 5 && keysequence.count() > 1;
    s << quint32(extended ? 4 : 1) << quint32(keysequence.d->key[0]);
    if (extended) {
        s << quint32(keysequence.d->key[1])
          << quint32(keysequence.d->key[2])
          << quint32(keysequence.d->key[3]);
    }
    return s;
}


/*!
    \fn QDataStream &operator>>(QDataStream &stream, QKeySequence &sequence)
    \relates QKeySequence

    Reads a key sequence from the \a stream into the key \a sequence.

    \sa{Serializing Qt Data Types}{Format of the QDataStream operators}
*/
QDataStream &operator>>(QDataStream &s, QKeySequence &keysequence)
{
    const quint32 MaxKeys = QKeySequencePrivate::MaxKeyCount;
    quint32 c;
    s >> c;
    quint32 keys[MaxKeys] = {0};
    for (uint i = 0; i < qMin(c, MaxKeys); ++i) {
        if (s.atEnd()) {
            qWarning("Premature EOF while reading QKeySequence");
            return s;
        }
        s >> keys[i];
    }
    qAtomicDetach(keysequence.d);
    std::copy(keys, keys + MaxKeys, QT_MAKE_CHECKED_ARRAY_ITERATOR(keysequence.d->key, MaxKeys));
    return s;
}

#endif //QT_NO_DATASTREAM

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const QKeySequence &p)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace() << "QKeySequence(" << p.toString() << ')';
    return dbg;
}
#endif

/*!
    \typedef QKeySequence::DataPtr
    \internal
*/

 /*!
    \fn DataPtr &QKeySequence::data_ptr()
    \internal
*/

QT_END_NAMESPACE

#include "moc_qkeysequence.cpp"
