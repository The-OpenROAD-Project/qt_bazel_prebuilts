// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qplatformtheme.h"

#include "qplatformtheme_p.h"

#include <QtCore/QVariant>
#include <QtCore/QStringList>
#include <QtCore/qfileinfo.h>
#include <qicon.h>
#include <qpalette.h>
#include <qtextformat.h>
#include <private/qiconloader_p.h>
#include <private/qguiapplication_p.h>
#include <qpa/qplatformintegration.h>
#include <qpa/qplatformdialoghelper.h>

#include <algorithm>

QT_BEGIN_NAMESPACE

/*!
    \class QPlatformTheme
    \since 5.0
    \internal
    \preliminary
    \ingroup qpa
    \brief The QPlatformTheme class allows customizing the UI based on themes.

    See the init_platform function in qguiapplication.cpp for the complete
    platform initialization process.
*/

/*!
    \enum QPlatformTheme::ThemeHint

    This enum describes the available theme hints.

    \value CursorFlashTime (int) Cursor flash time in ms, overriding
                                 QPlatformIntegration::styleHint.

    \value KeyboardInputInterval (int) Keyboard input interval in ms, overriding
                                 QPlatformIntegration::styleHint.

    \value MouseDoubleClickInterval (int) Mouse double click interval in ms,
                                    overriding QPlatformIntegration::styleHint.

    \value MouseDoubleClickDistance (int) The maximum distance in logical pixels which the mouse can travel
                        between clicks in order for the click sequence to be handled as a double click.
                        The default value is 5 logical pixels.

    \value MousePressAndHoldInterval (int) Mouse press and hold interval in ms,
                                    overriding QPlatformIntegration::styleHint.

    \value StartDragDistance (int) Start drag distance,
                             overriding QPlatformIntegration::styleHint.

    \value StartDragTime (int) Start drag time in ms,
                               overriding QPlatformIntegration::styleHint.

    \value WheelScrollLines (int) The number of lines to scroll a widget, when the mouse wheel is rotated.
                        The default value is 3.  \sa QApplication::wheelScrollLines()

    \value KeyboardAutoRepeatRate (int) Keyboard auto repeat rate,
                                  overriding QPlatformIntegration::styleHint.

    \value PasswordMaskDelay (int) Pass word mask delay in ms,
                                   overriding QPlatformIntegration::styleHint.

    \value StartDragVelocity (int) Velocity of a drag,
                                   overriding QPlatformIntegration::styleHint.

    \value TextCursorWidth  (int) Determines the width of the text cursor.

    \value DropShadow       (bool) Determines whether the drop shadow effect for
                            tooltips or whatsthis is enabled.

    \value MaximumScrollBarDragDistance (int) Determines the value returned by
                            QStyle::pixelMetric(PM_MaximumDragDistance)

    \value ToolButtonStyle (int) A value representing a Qt::ToolButtonStyle.

    \value ToolBarIconSize Icon size for tool bars.

    \value SystemIconThemeName (QString) Name of the icon theme.

    \value SystemIconFallbackThemeName (QString) Name of the fallback icon theme.

    \value IconThemeSearchPaths (QStringList) Search paths for icons.

    \value ItemViewActivateItemOnSingleClick (bool) Activate items by single click.

    \value StyleNames (QStringList) A list of preferred style names.

    \value WindowAutoPlacement (bool) A boolean value indicating whether Windows
                               (particularly dialogs) are placed by the system
                               (see _NET_WM_FULL_PLACEMENT in X11).

    \value DialogButtonBoxLayout (int) An integer representing a
                                 QDialogButtonBox::ButtonLayout value.

    \value DialogButtonBoxButtonsHaveIcons (bool) A boolean value indicating whether
                                            the buttons of a QDialogButtonBox should have icons.

    \value UseFullScreenForPopupMenu (bool) Pop menus can cover the full screen including task bar.

    \value KeyboardScheme (int) An integer value (enum KeyboardSchemes) specifying the
                           keyboard scheme.

    \value UiEffects (int) A flag value consisting of UiEffect values specifying the enabled UI animations.

    \value SpellCheckUnderlineStyle (int) A QTextCharFormat::UnderlineStyle specifying
                                    the underline style used misspelled words when spell checking.

    \value TabFocusBehavior (int) A Qt::TabFocusBehavior specifying
                         the behavior of focus change when tab key was pressed.
                         This enum value was added in Qt 5.5.

    \value DialogSnapToDefaultButton (bool) Whether the mouse should snap to the default button when a dialog
                                     becomes visible.

    \value ContextMenuOnMouseRelease (bool) Whether the context menu should be shown on mouse release.

    \value TouchDoubleTapDistance (int) The maximum distance in logical pixels which a touchpoint can travel
                        between taps in order for the tap sequence to be handled as a double tap.
                        The default value is double the MouseDoubleClickDistance, or 10 logical pixels
                        if that is not specified.

    \value ShowShortcutsInContextMenus (bool) Whether to display shortcut key sequences in context menus.

    \value InteractiveResizeAcrossScreens (bool) Whether using the whole virtual geometry of all the screens
                        as basis for the resize.
                        This enum value has been added in Qt 6.2.

    \value ShowDirectoriesFirst (bool) Whether directories should be shown
           first (before files) in file dialogs.
           This enum value was added in Qt 6.3.

    \value PreselectFirstFileInDirectory (bool) Whether the first file in a directory
           should be automatically selected when a file dialog opens.
           This enum value was added in Qt 6.3.

    \value ButtonPressKeys (QList<Qt::Key>) A list of keys that can be used to press buttons via keyboard input.

    \value SetFocusOnTouchRelease (bool) Whether focus objects (line edits etc) should receive
           input focus after a touch/mouse release.
           This enum value has been added in Qt 6.5.

    \value MouseCursorTheme (QString) Name of the mouse cursor theme.
           This enum value has been added in Qt 6.5.

    \value MouseCursorSize (QSize) Size of the mouse cursor.
           This enum value has been added in Qt 6.5.

    \sa themeHint(), QStyle::pixelMetric()
*/


#if QT_CONFIG(shortcut)
// Table of key bindings. It must be sorted on key sequence:
// The integer value of VK_KEY | Modifier Keys (e.g., VK_META, and etc.)
// A priority of 1 indicates that this is the primary key binding when multiple are defined.

enum KeyPlatform {
    KB_Win = (1 << QPlatformTheme::WindowsKeyboardScheme),
    KB_Mac = (1 << QPlatformTheme::MacKeyboardScheme),
    KB_X11 = (1 << QPlatformTheme::X11KeyboardScheme),
    KB_KDE = (1 << QPlatformTheme::KdeKeyboardScheme),
    KB_Gnome = (1 << QPlatformTheme::GnomeKeyboardScheme),
    KB_CDE = (1 << QPlatformTheme::CdeKeyboardScheme),
    KB_All = 0xffff
};

const QKeyBinding QPlatformThemePrivate::keyBindings[] = {
    //   StandardKey                            Priority    Key Sequence                            Platforms
    {QKeySequence::HelpContents,            1,          Qt::CTRL | Qt::Key_Question,            KB_Mac},
    {QKeySequence::HelpContents,            0,          Qt::Key_F1,                             KB_Win | KB_X11},
    {QKeySequence::WhatsThis,               1,          Qt::SHIFT | Qt::Key_F1,                 KB_All},
    {QKeySequence::Open,                    1,          Qt::CTRL | Qt::Key_O,                   KB_All},
    {QKeySequence::Close,                   0,          Qt::CTRL | Qt::Key_F4,                  KB_Mac},
    {QKeySequence::Close,                   1,          Qt::CTRL | Qt::Key_F4,                  KB_Win},
    {QKeySequence::Close,                   1,          Qt::CTRL | Qt::Key_W,                   KB_Mac},
    {QKeySequence::Close,                   0,          Qt::CTRL | Qt::Key_W,                   KB_Win | KB_X11},
    {QKeySequence::Save,                    1,          Qt::CTRL | Qt::Key_S,                   KB_All},
    {QKeySequence::New,                     1,          Qt::CTRL | Qt::Key_N,                   KB_All},
    {QKeySequence::Delete,                  0,          Qt::CTRL | Qt::Key_D,                   KB_X11}, //emacs (line edit only)
    {QKeySequence::Delete,                  1,          Qt::Key_Delete,                         KB_All},
    {QKeySequence::Delete,                  0,          Qt::META | Qt::Key_D,                   KB_Mac},
    {QKeySequence::Cut,                     1,          Qt::CTRL | Qt::Key_X,                   KB_All},
    {QKeySequence::Cut,                     0,          Qt::SHIFT | Qt::Key_Delete,             KB_Win | KB_X11}, //## Check if this should work on mac
    {QKeySequence::Cut,                     0,          Qt::Key_F20,                            KB_X11}, //Cut on sun keyboards
    {QKeySequence::Cut,                     0,          Qt::META | Qt::Key_K,                   KB_Mac},
    {QKeySequence::Copy,                    0,          Qt::CTRL | Qt::Key_Insert,              KB_X11 | KB_Win},
    {QKeySequence::Copy,                    1,          Qt::CTRL | Qt::Key_C,                   KB_All},
    {QKeySequence::Copy,                    0,          Qt::Key_F16,                            KB_X11}, //Copy on sun keyboards
    {QKeySequence::Paste,                   0,          Qt::CTRL | Qt::SHIFT | Qt::Key_Insert,  KB_X11},
    {QKeySequence::Paste,                   1,          Qt::CTRL | Qt::Key_V,                   KB_All},
    {QKeySequence::Paste,                   0,          Qt::SHIFT | Qt::Key_Insert,             KB_Win | KB_X11},
    {QKeySequence::Paste,                   0,          Qt::Key_F18,                            KB_X11}, //Paste on sun keyboards
    {QKeySequence::Paste,                   0,          Qt::META | Qt::Key_Y,                   KB_Mac},
    {QKeySequence::Undo,                    0,          Qt::ALT  | Qt::Key_Backspace,           KB_Win},
    {QKeySequence::Undo,                    1,          Qt::CTRL | Qt::Key_Z,                   KB_All},
    {QKeySequence::Undo,                    0,          Qt::Key_F14,                            KB_X11}, //Undo on sun keyboards
    {QKeySequence::Redo,                    0,          Qt::ALT  | Qt::SHIFT | Qt::Key_Backspace,KB_Win},
    {QKeySequence::Redo,                    0,          Qt::CTRL | Qt::SHIFT | Qt::Key_Z,       KB_Mac},
    {QKeySequence::Redo,                    0,          Qt::CTRL | Qt::SHIFT | Qt::Key_Z,       KB_Win | KB_X11},
    {QKeySequence::Redo,                    1,          Qt::CTRL | Qt::Key_Y,                   KB_Win},
    {QKeySequence::Back,                    1,          Qt::ALT  | Qt::Key_Left,                KB_Win | KB_X11},
    {QKeySequence::Back,                    0,          Qt::CTRL | Qt::Key_Left,                KB_Mac},
    {QKeySequence::Back,                    1,          Qt::CTRL | Qt::Key_BracketLeft,         KB_Mac},
    {QKeySequence::Back,                    0,          Qt::Key_Backspace,                      KB_Win},
    {QKeySequence::Forward,                 1,          Qt::ALT  | Qt::Key_Right,               KB_Win | KB_X11},
    {QKeySequence::Forward,                 0,          Qt::CTRL | Qt::Key_Right,               KB_Mac},
    {QKeySequence::Forward,                 1,          Qt::CTRL | Qt::Key_BracketRight,        KB_Mac},
    {QKeySequence::Forward,                 0,          Qt::SHIFT | Qt::Key_Backspace,          KB_Win},
    {QKeySequence::Refresh,                 1,          Qt::CTRL | Qt::Key_R,                   KB_Gnome | KB_Mac},
    {QKeySequence::Refresh,                 0,          Qt::Key_F5,                             KB_Win | KB_X11},
    {QKeySequence::ZoomIn,                  1,          Qt::CTRL | Qt::Key_Plus,                KB_All},
    {QKeySequence::ZoomOut,                 1,          Qt::CTRL | Qt::Key_Minus,               KB_All},
    {QKeySequence::Print,                   1,          Qt::CTRL | Qt::Key_P,                   KB_All},
    {QKeySequence::AddTab,                  1,          Qt::CTRL | Qt::SHIFT | Qt::Key_N,       KB_KDE},
    {QKeySequence::AddTab,                  0,          Qt::CTRL | Qt::Key_T,                   KB_All},
    {QKeySequence::NextChild,               0,          Qt::CTRL | Qt::Key_F6,                  KB_Win},
    {QKeySequence::NextChild,               0,          Qt::CTRL | Qt::Key_Tab,                 KB_Mac}, //different priority from above
    {QKeySequence::NextChild,               1,          Qt::CTRL | Qt::Key_Tab,                 KB_Win | KB_X11},
    {QKeySequence::NextChild,               1,          Qt::CTRL | Qt::Key_BraceRight,          KB_Mac},
    {QKeySequence::NextChild,               0,          Qt::CTRL | Qt::Key_Comma,               KB_KDE},
    {QKeySequence::NextChild,               0,          Qt::Key_Forward,                        KB_All},
    {QKeySequence::PreviousChild,           0,          Qt::CTRL | Qt::SHIFT | Qt::Key_F6,      KB_Win},
    {QKeySequence::PreviousChild,           0,          Qt::CTRL | Qt::SHIFT | Qt::Key_Backtab, KB_Mac },//different priority from above
    {QKeySequence::PreviousChild,           1,          Qt::CTRL | Qt::SHIFT | Qt::Key_Backtab, KB_Win | KB_X11},
    {QKeySequence::PreviousChild,           1,          Qt::CTRL | Qt::Key_BraceLeft,           KB_Mac},
    {QKeySequence::PreviousChild,           0,          Qt::CTRL | Qt::Key_Period,              KB_KDE},
    {QKeySequence::PreviousChild,           0,          Qt::Key_Back,                           KB_All},
    {QKeySequence::Find,                    0,          Qt::CTRL | Qt::Key_F,                   KB_All},
    {QKeySequence::FindNext,                0,          Qt::CTRL | Qt::Key_G,                   KB_Win},
    {QKeySequence::FindNext,                1,          Qt::CTRL | Qt::Key_G,                   KB_Gnome | KB_Mac},
    {QKeySequence::FindNext,                1,          Qt::Key_F3,                             KB_Win},
    {QKeySequence::FindNext,                0,          Qt::Key_F3,                             KB_X11},
    {QKeySequence::FindPrevious,            0,          Qt::CTRL | Qt::SHIFT | Qt::Key_G,       KB_Win},
    {QKeySequence::FindPrevious,            1,          Qt::CTRL | Qt::SHIFT | Qt::Key_G,       KB_Gnome | KB_Mac},
    {QKeySequence::FindPrevious,            1,          Qt::SHIFT | Qt::Key_F3,                 KB_Win},
    {QKeySequence::FindPrevious,            0,          Qt::SHIFT | Qt::Key_F3,                 KB_X11},
    {QKeySequence::Replace,                 0,          Qt::CTRL | Qt::Key_R,                   KB_KDE},
    {QKeySequence::Replace,                 0,          Qt::CTRL | Qt::Key_H,                   KB_Gnome},
    {QKeySequence::Replace,                 0,          Qt::CTRL | Qt::Key_H,                   KB_Win},
    {QKeySequence::SelectAll,               1,          Qt::CTRL | Qt::Key_A,                   KB_All},
    {QKeySequence::Bold,                    1,          Qt::CTRL | Qt::Key_B,                   KB_All},
    {QKeySequence::Italic,                  0,          Qt::CTRL | Qt::Key_I,                   KB_All},
    {QKeySequence::Underline,               1,          Qt::CTRL | Qt::Key_U,                   KB_All},
    {QKeySequence::MoveToNextChar,          1,          Qt::Key_Right,                          KB_All},
    {QKeySequence::MoveToNextChar,          0,          Qt::META | Qt::Key_F,                   KB_Mac},
    {QKeySequence::MoveToPreviousChar,      1,          Qt::Key_Left,                           KB_All},
    {QKeySequence::MoveToPreviousChar,      0,          Qt::META | Qt::Key_B,                   KB_Mac},
    {QKeySequence::MoveToNextWord,          0,          Qt::ALT  | Qt::Key_Right,               KB_Mac},
    {QKeySequence::MoveToNextWord,          0,          Qt::CTRL | Qt::Key_Right,               KB_Win | KB_X11},
    {QKeySequence::MoveToPreviousWord,      0,          Qt::ALT  | Qt::Key_Left,                KB_Mac},
    {QKeySequence::MoveToPreviousWord,      0,          Qt::CTRL | Qt::Key_Left,                KB_Win | KB_X11},
    {QKeySequence::MoveToNextLine,          1,          Qt::Key_Down,                           KB_All},
    {QKeySequence::MoveToNextLine,          0,          Qt::META | Qt::Key_N,                   KB_Mac},
    {QKeySequence::MoveToPreviousLine,      1,          Qt::Key_Up,                             KB_All},
    {QKeySequence::MoveToPreviousLine,      0,          Qt::META | Qt::Key_P,                   KB_Mac},
    {QKeySequence::MoveToNextPage,          0,          Qt::META | Qt::Key_PageDown,            KB_Mac},
    {QKeySequence::MoveToNextPage,          0,          Qt::META | Qt::Key_Down,                KB_Mac},
    {QKeySequence::MoveToNextPage,          0,          Qt::META | Qt::Key_V,                   KB_Mac},
    {QKeySequence::MoveToNextPage,          0,          Qt::ALT  | Qt::Key_PageDown,            KB_Mac },
    {QKeySequence::MoveToNextPage,          1,          Qt::Key_PageDown,                       KB_All},
    {QKeySequence::MoveToPreviousPage,      0,          Qt::META | Qt::Key_PageUp,              KB_Mac},
    {QKeySequence::MoveToPreviousPage,      0,          Qt::META | Qt::Key_Up,                  KB_Mac},
    {QKeySequence::MoveToPreviousPage,      0,          Qt::ALT  | Qt::Key_PageUp,              KB_Mac },
    {QKeySequence::MoveToPreviousPage,      1,          Qt::Key_PageUp,                         KB_All},
    {QKeySequence::MoveToStartOfLine,       0,          Qt::META | Qt::Key_Left,                KB_Mac},
    {QKeySequence::MoveToStartOfLine,       0,          Qt::CTRL | Qt::Key_Left,                KB_Mac },
    {QKeySequence::MoveToStartOfLine,       0,          Qt::Key_Home,                           KB_Win | KB_X11},
    {QKeySequence::MoveToEndOfLine,         0,          Qt::META | Qt::Key_Right,               KB_Mac},
    {QKeySequence::MoveToEndOfLine,         0,          Qt::CTRL | Qt::Key_Right,               KB_Mac },
    {QKeySequence::MoveToEndOfLine,         0,          Qt::Key_End,                            KB_Win | KB_X11},
    {QKeySequence::MoveToEndOfLine,         0,          Qt::CTRL | Qt::Key_E,                   KB_X11},
    {QKeySequence::MoveToStartOfBlock,      0,          Qt::META | Qt::Key_A,                   KB_Mac},
    {QKeySequence::MoveToStartOfBlock,      1,          Qt::ALT  | Qt::Key_Up,                  KB_Mac}, //mac only
    {QKeySequence::MoveToEndOfBlock,        0,          Qt::META | Qt::Key_E,                   KB_Mac},
    {QKeySequence::MoveToEndOfBlock,        1,          Qt::ALT  | Qt::Key_Down,                KB_Mac}, //mac only
    {QKeySequence::MoveToStartOfDocument,   1,          Qt::CTRL | Qt::Key_Up,                  KB_Mac},
    {QKeySequence::MoveToStartOfDocument,   0,          Qt::CTRL | Qt::Key_Home,                KB_Win | KB_X11},
    {QKeySequence::MoveToStartOfDocument,   0,          Qt::Key_Home,                           KB_Mac},
    {QKeySequence::MoveToEndOfDocument,     1,          Qt::CTRL | Qt::Key_Down,                KB_Mac},
    {QKeySequence::MoveToEndOfDocument,     0,          Qt::CTRL | Qt::Key_End,                 KB_Win | KB_X11},
    {QKeySequence::MoveToEndOfDocument,     0,          Qt::Key_End,                            KB_Mac},
    {QKeySequence::SelectNextChar,          0,          Qt::SHIFT | Qt::Key_Right,              KB_All},
    {QKeySequence::SelectPreviousChar,      0,          Qt::SHIFT | Qt::Key_Left,               KB_All},
    {QKeySequence::SelectNextWord,          0,          Qt::ALT  | Qt::SHIFT | Qt::Key_Right,   KB_Mac},
    {QKeySequence::SelectNextWord,          0,          Qt::CTRL | Qt::SHIFT | Qt::Key_Right,   KB_Win | KB_X11},
    {QKeySequence::SelectPreviousWord,      0,          Qt::ALT  | Qt::SHIFT | Qt::Key_Left,    KB_Mac},
    {QKeySequence::SelectPreviousWord,      0,          Qt::CTRL | Qt::SHIFT | Qt::Key_Left,    KB_Win | KB_X11},
    {QKeySequence::SelectNextLine,          0,          Qt::SHIFT | Qt::Key_Down,               KB_All},
    {QKeySequence::SelectPreviousLine,      0,          Qt::SHIFT | Qt::Key_Up,                 KB_All},
    {QKeySequence::SelectNextPage,          0,          Qt::SHIFT | Qt::Key_PageDown,           KB_All},
    {QKeySequence::SelectPreviousPage,      0,          Qt::SHIFT | Qt::Key_PageUp,             KB_All},
    {QKeySequence::SelectStartOfLine,       0,          Qt::META | Qt::SHIFT | Qt::Key_Left,    KB_Mac},
    {QKeySequence::SelectStartOfLine,       1,          Qt::CTRL | Qt::SHIFT | Qt::Key_Left,    KB_Mac },
    {QKeySequence::SelectStartOfLine,       0,          Qt::SHIFT | Qt::Key_Home,               KB_Win | KB_X11},
    {QKeySequence::SelectEndOfLine,         0,          Qt::META | Qt::SHIFT | Qt::Key_Right,   KB_Mac},
    {QKeySequence::SelectEndOfLine,         1,          Qt::CTRL | Qt::SHIFT | Qt::Key_Right,   KB_Mac },
    {QKeySequence::SelectEndOfLine,         0,          Qt::SHIFT | Qt::Key_End,                KB_Win | KB_X11},
    {QKeySequence::SelectStartOfBlock,      1,          Qt::ALT  | Qt::SHIFT | Qt::Key_Up,      KB_Mac}, //mac only
    {QKeySequence::SelectStartOfBlock,      0,          Qt::META | Qt::SHIFT | Qt::Key_A,       KB_Mac},
    {QKeySequence::SelectEndOfBlock,        1,          Qt::ALT  | Qt::SHIFT | Qt::Key_Down,    KB_Mac}, //mac only
    {QKeySequence::SelectEndOfBlock,        0,          Qt::META | Qt::SHIFT | Qt::Key_E,       KB_Mac},
    {QKeySequence::SelectStartOfDocument,   1,          Qt::CTRL | Qt::SHIFT | Qt::Key_Up,      KB_Mac},
    {QKeySequence::SelectStartOfDocument,   0,          Qt::CTRL | Qt::SHIFT | Qt::Key_Home,    KB_Win | KB_X11},
    {QKeySequence::SelectStartOfDocument,   0,          Qt::SHIFT | Qt::Key_Home,               KB_Mac},
    {QKeySequence::SelectEndOfDocument,     1,          Qt::CTRL | Qt::SHIFT | Qt::Key_Down,    KB_Mac},
    {QKeySequence::SelectEndOfDocument,     0,          Qt::CTRL | Qt::SHIFT | Qt::Key_End,     KB_Win | KB_X11},
    {QKeySequence::SelectEndOfDocument,     0,          Qt::SHIFT | Qt::Key_End,                KB_Mac},
    {QKeySequence::DeleteStartOfWord,       0,          Qt::ALT  | Qt::Key_Backspace,           KB_Mac},
    {QKeySequence::DeleteStartOfWord,       0,          Qt::CTRL | Qt::Key_Backspace,           KB_X11 | KB_Win},
    {QKeySequence::DeleteEndOfWord,         0,          Qt::ALT  | Qt::Key_Delete,              KB_Mac},
    {QKeySequence::DeleteEndOfWord,         0,          Qt::CTRL | Qt::Key_Delete,              KB_X11 | KB_Win},
    {QKeySequence::DeleteEndOfLine,         0,          Qt::CTRL | Qt::Key_K,                   KB_X11}, //emacs (line edit only)
    {QKeySequence::InsertParagraphSeparator,0,          Qt::Key_Enter,                          KB_All},
    {QKeySequence::InsertParagraphSeparator,0,          Qt::Key_Return,                         KB_All},
    {QKeySequence::InsertLineSeparator,     0,          Qt::META | Qt::Key_Enter,               KB_Mac},
    {QKeySequence::InsertLineSeparator,     0,          Qt::META | Qt::Key_Return,              KB_Mac},
    {QKeySequence::InsertLineSeparator,     0,          Qt::SHIFT | Qt::Key_Enter,              KB_All},
    {QKeySequence::InsertLineSeparator,     0,          Qt::SHIFT | Qt::Key_Return,             KB_All},
    {QKeySequence::InsertLineSeparator,     0,          Qt::META | Qt::Key_O,                   KB_Mac},
    {QKeySequence::SaveAs,                  0,          Qt::CTRL | Qt::SHIFT | Qt::Key_S,       KB_All},
    {QKeySequence::Preferences,             0,          Qt::CTRL | Qt::Key_Comma,               KB_Mac},
    {QKeySequence::Preferences,             0,          Qt::CTRL | Qt::SHIFT | Qt::Key_Comma,   KB_KDE},
    {QKeySequence::Quit,                    0,          Qt::CTRL | Qt::Key_Q,                   KB_X11 | KB_Gnome | KB_KDE | KB_Mac},
    {QKeySequence::FullScreen,              1,          Qt::META | Qt::CTRL | Qt::Key_F,        KB_Mac},
    {QKeySequence::FullScreen,              0,          Qt::ALT  | Qt::Key_Enter,               KB_Win},
    {QKeySequence::FullScreen,              0,          Qt::CTRL | Qt::SHIFT | Qt::Key_F,       KB_KDE},
    {QKeySequence::FullScreen,              1,          Qt::Key_F11,                            KB_Win | KB_Gnome | KB_KDE},
    {QKeySequence::Deselect,                0,          Qt::CTRL | Qt::SHIFT | Qt::Key_A,       KB_X11},
    {QKeySequence::DeleteCompleteLine,      0,          Qt::CTRL | Qt::Key_U,                   KB_X11},
    {QKeySequence::Backspace,               1,          Qt::Key_Backspace,                      KB_Mac},
    {QKeySequence::Backspace,               0,          Qt::META | Qt::Key_H,                   KB_Mac},
    {QKeySequence::Cancel,                  0,          Qt::Key_Escape,                         KB_All},
    {QKeySequence::Cancel,                  0,          Qt::CTRL | Qt::Key_Period,              KB_Mac}
};

const uint QPlatformThemePrivate::numberOfKeyBindings = sizeof(QPlatformThemePrivate::keyBindings)/(sizeof(QKeyBinding));
#endif

QPlatformThemePrivate::QPlatformThemePrivate()
        : systemPalette(nullptr)
{ }

QPlatformThemePrivate::~QPlatformThemePrivate()
{
    delete systemPalette;
}

Q_GUI_EXPORT QPalette qt_fusionPalette()
{
    auto theme = QGuiApplicationPrivate::platformTheme();
    const bool darkAppearance = theme
                              ? theme->colorScheme() == Qt::ColorScheme::Dark
                              : false;
    const QColor windowText = darkAppearance ? QColor(240, 240, 240) : Qt::black;
    const QColor backGround = darkAppearance ? QColor(50, 50, 50) : QColor(239, 239, 239);
    const QColor light = backGround.lighter(150);
    const QColor mid = (backGround.darker(130));
    const QColor midLight = mid.lighter(110);
    const QColor base = darkAppearance ? backGround.darker(140) : Qt::white;
    const QColor disabledBase(backGround);
    const QColor dark = backGround.darker(150);
    const QColor darkDisabled = QColor(209, 209, 209).darker(110);
    const QColor text = darkAppearance ? windowText : Qt::black;
    const QColor highlight = QColor(48, 140, 198);
    const QColor hightlightedText = darkAppearance ? windowText : Qt::white;
    const QColor disabledText = darkAppearance ? QColor(130, 130, 130) : QColor(190, 190, 190);
    const QColor button = backGround;
    const QColor shadow = dark.darker(135);
    const QColor disabledShadow = shadow.lighter(150);
    const QColor disabledHighlight(145, 145, 145);
    QColor placeholder = text;
    placeholder.setAlpha(128);

    QPalette fusionPalette(windowText, backGround, light, dark, mid, text, base);
    fusionPalette.setBrush(QPalette::Midlight, midLight);
    fusionPalette.setBrush(QPalette::Button, button);
    fusionPalette.setBrush(QPalette::Shadow, shadow);
    fusionPalette.setBrush(QPalette::HighlightedText, hightlightedText);

    fusionPalette.setBrush(QPalette::Disabled, QPalette::Text, disabledText);
    fusionPalette.setBrush(QPalette::Disabled, QPalette::WindowText, disabledText);
    fusionPalette.setBrush(QPalette::Disabled, QPalette::ButtonText, disabledText);
    fusionPalette.setBrush(QPalette::Disabled, QPalette::Base, disabledBase);
    fusionPalette.setBrush(QPalette::Disabled, QPalette::Dark, darkDisabled);
    fusionPalette.setBrush(QPalette::Disabled, QPalette::Shadow, disabledShadow);

    fusionPalette.setBrush(QPalette::Active, QPalette::Highlight, highlight);
    fusionPalette.setBrush(QPalette::Inactive, QPalette::Highlight, highlight);
    fusionPalette.setBrush(QPalette::Disabled, QPalette::Highlight, disabledHighlight);

    fusionPalette.setBrush(QPalette::Active, QPalette::Accent, highlight);
    fusionPalette.setBrush(QPalette::Inactive, QPalette::Accent, highlight);
    fusionPalette.setBrush(QPalette::Disabled, QPalette::Accent, disabledHighlight);

    fusionPalette.setBrush(QPalette::PlaceholderText, placeholder);

    // Use a more legible light blue on dark backgrounds than the default Qt::blue.
    if (darkAppearance)
        fusionPalette.setBrush(QPalette::Link, highlight);

    return fusionPalette;
}

void QPlatformThemePrivate::initializeSystemPalette()
{
    Q_ASSERT(!systemPalette);
    systemPalette = new QPalette(qt_fusionPalette());
}

QPlatformTheme::QPlatformTheme()
    : d_ptr(new QPlatformThemePrivate)
{

}

QPlatformTheme::QPlatformTheme(QPlatformThemePrivate *priv)
    : d_ptr(priv)
{ }

QPlatformTheme::~QPlatformTheme()
{

}

bool QPlatformTheme::usePlatformNativeDialog(DialogType type) const
{
    Q_UNUSED(type);
    return false;
}

QPlatformDialogHelper *QPlatformTheme::createPlatformDialogHelper(DialogType type) const
{
    Q_UNUSED(type);
    return nullptr;
}

Qt::ColorScheme QPlatformTheme::colorScheme() const
{
    return Qt::ColorScheme::Unknown;
}

void QPlatformTheme::requestColorScheme(Qt::ColorScheme scheme)
{
    Q_UNUSED(scheme);
}

const QPalette *QPlatformTheme::palette(Palette type) const
{
    Q_D(const QPlatformTheme);
    if (type == QPlatformTheme::SystemPalette) {
        if (!d->systemPalette)
            const_cast<QPlatformTheme *>(this)->d_ptr->initializeSystemPalette();
        return d->systemPalette;
    }
    return nullptr;
}

const QFont *QPlatformTheme::font(Font type) const
{
    Q_UNUSED(type);
    return nullptr;
}

/*!
    \brief Return a pixmap for \a standardPixmap, at the given \a size.

    The implementation should not take system DPR into account, and
    always return a pixmap with a DPR of 1. It's up to the consumer
    to account for DPR and request a pixmap of the right size.
*/
QPixmap QPlatformTheme::standardPixmap(StandardPixmap standardPixmap, const QSizeF &size) const
{
    Q_UNUSED(standardPixmap);
    Q_UNUSED(size);
    // TODO Should return QCommonStyle pixmaps?
    return QPixmap();
}

/*!
    \brief Return an icon for \a fileInfo, observing \a iconOptions.

    This function is queried by QFileIconProvider and similar classes to obtain
    an icon for a file. If it does not return a non-null icon, fileIconPixmap()
    is queried for a specific size.

    \since 5.8
*/

QIcon QPlatformTheme::fileIcon(const QFileInfo &fileInfo, QPlatformTheme::IconOptions iconOptions) const
{
    Q_UNUSED(fileInfo);
    Q_UNUSED(iconOptions);
    // TODO Should return QCommonStyle pixmaps?
    return QIcon();
}

QVariant QPlatformTheme::themeHint(ThemeHint hint) const
{
    // For theme hints which mirror platform integration style hints, query
    // the platform integration. The base QPlatformIntegration::styleHint()
    // function will in turn query QPlatformTheme::defaultThemeHint() if there
    // is no custom value.
    switch (hint) {
    case QPlatformTheme::CursorFlashTime:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::CursorFlashTime);
    case QPlatformTheme::KeyboardInputInterval:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::KeyboardInputInterval);
    case QPlatformTheme::KeyboardAutoRepeatRate:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::KeyboardAutoRepeatRate);
    case QPlatformTheme::MouseDoubleClickInterval:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::MouseDoubleClickInterval);
    case QPlatformTheme::StartDragDistance:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::StartDragDistance);
    case QPlatformTheme::StartDragTime:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::StartDragTime);
    case QPlatformTheme::StartDragVelocity:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::StartDragVelocity);
    case QPlatformTheme::PasswordMaskDelay:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::PasswordMaskDelay);
    case QPlatformTheme::PasswordMaskCharacter:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::PasswordMaskCharacter);
    case QPlatformTheme::MousePressAndHoldInterval:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::MousePressAndHoldInterval);
    case QPlatformTheme::ItemViewActivateItemOnSingleClick:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::ItemViewActivateItemOnSingleClick);
    case QPlatformTheme::UiEffects:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::UiEffects);
    case QPlatformTheme::ShowShortcutsInContextMenus:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::ShowShortcutsInContextMenus);
    case QPlatformTheme::SetFocusOnTouchRelease:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::SetFocusOnTouchRelease);
    case QPlatformTheme::FlickStartDistance:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::FlickStartDistance);
    case QPlatformTheme::FlickMaximumVelocity:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::FlickMaximumVelocity);
    case QPlatformTheme::FlickDeceleration:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::FlickDeceleration);
    case QPlatformTheme::UnderlineShortcut:
        return QGuiApplicationPrivate::platformIntegration()->styleHint(QPlatformIntegration::UnderlineShortcut);
    default:
        return QPlatformTheme::defaultThemeHint(hint);
    }
}

QVariant QPlatformTheme::defaultThemeHint(ThemeHint hint)
{
    switch (hint) {
    case QPlatformTheme::CursorFlashTime:
        return QVariant(1000);
    case QPlatformTheme::KeyboardInputInterval:
        return QVariant(400);
    case QPlatformTheme::KeyboardAutoRepeatRate:
        return QVariant(30);
    case QPlatformTheme::MouseDoubleClickInterval:
        return QVariant(400);
    case QPlatformTheme::StartDragDistance:
        return QVariant(10);
    case QPlatformTheme::StartDragTime:
        return QVariant(500);
    case QPlatformTheme::PasswordMaskDelay:
        return QVariant(int(0));
    case QPlatformTheme::PasswordMaskCharacter:
        return QVariant(QChar(u'\x25CF'));
    case QPlatformTheme::StartDragVelocity:
        return QVariant(int(0)); // no limit
    case QPlatformTheme::UseFullScreenForPopupMenu:
        return QVariant(false);
    case QPlatformTheme::WindowAutoPlacement:
        return QVariant(false);
    case QPlatformTheme::DialogButtonBoxLayout:
        return QVariant(int(0));
    case QPlatformTheme::DialogButtonBoxButtonsHaveIcons:
        return QVariant(false);
    case QPlatformTheme::ItemViewActivateItemOnSingleClick:
        return QVariant(false);
    case QPlatformTheme::ToolButtonStyle:
        return QVariant(int(Qt::ToolButtonIconOnly));
    case QPlatformTheme::ToolBarIconSize:
        return QVariant(int(0));
    case QPlatformTheme::SystemIconThemeName:
    case QPlatformTheme::SystemIconFallbackThemeName:
        return QVariant(QString());
    case QPlatformTheme::IconThemeSearchPaths:
        return QVariant(QStringList());
    case QPlatformTheme::IconFallbackSearchPaths:
        return QVariant(QStringList());
    case QPlatformTheme::StyleNames:
        return QVariant(QStringList());
    case QPlatformTheme::ShowShortcutsInContextMenus:
        return QVariant(true);
    case TextCursorWidth:
        return QVariant(1);
    case DropShadow:
        return QVariant(false);
    case MaximumScrollBarDragDistance:
        return QVariant(-1);
    case KeyboardScheme:
        return QVariant(int(WindowsKeyboardScheme));
    case UiEffects:
        return QVariant(int(0));
    case SpellCheckUnderlineStyle:
        return QVariant(int(QTextCharFormat::WaveUnderline));
    case TabFocusBehavior:
        return QVariant(int(Qt::TabFocusAllControls));
    case IconPixmapSizes:
        return QVariant::fromValue(QList<int>());
    case DialogSnapToDefaultButton:
    case ContextMenuOnMouseRelease:
        return QVariant(false);
    case MousePressAndHoldInterval:
        return QVariant(800);
    case MouseDoubleClickDistance:
        {
            bool ok = false;
            const int dist = qEnvironmentVariableIntValue("QT_DBL_CLICK_DIST", &ok);
            return QVariant(ok ? dist : 5);
        }
    case WheelScrollLines:
        return QVariant(3);
    case TouchDoubleTapDistance:
        {
            bool ok = false;
            int dist = qEnvironmentVariableIntValue("QT_DBL_TAP_DIST", &ok);
            if (!ok)
                dist = defaultThemeHint(MouseDoubleClickDistance).toInt(&ok) * 2;
            return QVariant(ok ? dist : 10);
        }
    case MouseQuickSelectionThreshold:
        return QVariant(10);
    case InteractiveResizeAcrossScreens:
        return true;
    case ShowDirectoriesFirst:
        return true;
    case PreselectFirstFileInDirectory:
        return false;
    case ButtonPressKeys:
        return QVariant::fromValue(QList<Qt::Key>({ Qt::Key_Space, Qt::Key_Select }));
    case SetFocusOnTouchRelease:
        return false;
    case FlickStartDistance:
        return QVariant(15);
    case FlickMaximumVelocity:
        return QVariant(2500);
    case FlickDeceleration:
        return QVariant(1500);
    case MenuBarFocusOnAltPressRelease:
        return false;
    case MouseCursorTheme:
        return QVariant(QString());
    case MouseCursorSize:
        return QVariant(QSize(16, 16));
    case UnderlineShortcut:
        return true;
    case ShowIconsInMenus:
        return true;
    case PreferFileIconFromTheme:
        return false;
    }

    return QVariant();
}

QPlatformMenuItem *QPlatformTheme::createPlatformMenuItem() const
{
    return nullptr;
}

QPlatformMenu *QPlatformTheme::createPlatformMenu() const
{
    return nullptr;
}

QPlatformMenuBar *QPlatformTheme::createPlatformMenuBar() const
{
    return nullptr;
}

#ifndef QT_NO_SYSTEMTRAYICON
/*!
   Factory function for QSystemTrayIcon. This function will return 0 if the platform
   integration does not support creating any system tray icon.
*/
QPlatformSystemTrayIcon *QPlatformTheme::createPlatformSystemTrayIcon() const
{
    return nullptr;
}
#endif

/*!
   Factory function for the QIconEngine used by QIcon::fromTheme(). By default this
   function returns a QIconLoaderEngine, but subclasses can reimplement it to
   provide their own.

   It is especially useful to benefit from some platform specific facilities or
   optimizations like an inter-process cache in systems mostly built with Qt.

   \since 5.1
*/
QIconEngine *QPlatformTheme::createIconEngine(const QString &iconName) const
{
    return new QIconLoaderEngine(iconName);
}

#if QT_CONFIG(shortcut)
// mixed-mode predicate: all of these overloads are actually needed (but not all for every compiler)
struct ByStandardKey {
    typedef bool result_type;

    bool operator()(QKeySequence::StandardKey lhs, QKeySequence::StandardKey rhs) const
    { return lhs < rhs; }

    bool operator()(const QKeyBinding& lhs, const QKeyBinding& rhs) const
    { return operator()(lhs.standardKey, rhs.standardKey); }

    bool operator()(QKeySequence::StandardKey lhs, const QKeyBinding& rhs) const
    { return operator()(lhs, rhs.standardKey); }

    bool operator()(const QKeyBinding& lhs, QKeySequence::StandardKey rhs) const
    { return operator()(lhs.standardKey, rhs); }
};

/*!
   Returns the key sequence that should be used for a standard action.

  \since 5.2
 */
QList<QKeySequence> QPlatformTheme::keyBindings(QKeySequence::StandardKey key) const
{
    const uint platform = QPlatformThemePrivate::currentKeyPlatforms();
    QList <QKeySequence> list;

    std::pair<const QKeyBinding *, const QKeyBinding *> range =
        std::equal_range(QPlatformThemePrivate::keyBindings,
                         QPlatformThemePrivate::keyBindings + QPlatformThemePrivate::numberOfKeyBindings,
                         key, ByStandardKey());

    for (const QKeyBinding *it = range.first; it < range.second; ++it) {
        if (!(it->platform & platform))
            continue;

        uint shortcut = it->shortcut.toCombined();

        if (it->priority > 0)
            list.prepend(QKeySequence(shortcut));
        else
            list.append(QKeySequence(shortcut));
    }

    return list;
}
#endif

/*!
   Returns the text of a standard \a button.

  \since 5.3
  \sa QPlatformDialogHelper::StandardButton
 */

QString QPlatformTheme::standardButtonText(int button) const
{
    return QPlatformTheme::defaultStandardButtonText(button);
}

#if QT_CONFIG(shortcut)
/*!
   Returns the mnemonic that should be used for a standard \a button.

  \since 5.9
  \sa QPlatformDialogHelper::StandardButton
 */

QKeySequence QPlatformTheme::standardButtonShortcut(int button) const
{
    Q_UNUSED(button);
    return QKeySequence();
}
#endif // QT_CONFIG(shortcut)

QString QPlatformTheme::defaultStandardButtonText(int button)
{
    switch (button) {
    case QPlatformDialogHelper::Ok:
        return QCoreApplication::translate("QPlatformTheme", "OK");
    case QPlatformDialogHelper::Save:
        return QCoreApplication::translate("QPlatformTheme", "Save");
    case QPlatformDialogHelper::SaveAll:
        return QCoreApplication::translate("QPlatformTheme", "Save All");
    case QPlatformDialogHelper::Open:
        return QCoreApplication::translate("QPlatformTheme", "Open");
    case QPlatformDialogHelper::Yes:
        return QCoreApplication::translate("QPlatformTheme", "&Yes");
    case QPlatformDialogHelper::YesToAll:
        return QCoreApplication::translate("QPlatformTheme", "Yes to &All");
    case QPlatformDialogHelper::No:
        return QCoreApplication::translate("QPlatformTheme", "&No");
    case QPlatformDialogHelper::NoToAll:
        return QCoreApplication::translate("QPlatformTheme", "N&o to All");
    case QPlatformDialogHelper::Abort:
        return QCoreApplication::translate("QPlatformTheme", "Abort");
    case QPlatformDialogHelper::Retry:
        return QCoreApplication::translate("QPlatformTheme", "Retry");
    case QPlatformDialogHelper::Ignore:
        return QCoreApplication::translate("QPlatformTheme", "Ignore");
    case QPlatformDialogHelper::Close:
        return QCoreApplication::translate("QPlatformTheme", "Close");
    case QPlatformDialogHelper::Cancel:
        return QCoreApplication::translate("QPlatformTheme", "Cancel");
    case QPlatformDialogHelper::Discard:
        return QCoreApplication::translate("QPlatformTheme", "Discard");
    case QPlatformDialogHelper::Help:
        return QCoreApplication::translate("QPlatformTheme", "Help");
    case QPlatformDialogHelper::Apply:
        return QCoreApplication::translate("QPlatformTheme", "Apply");
    case QPlatformDialogHelper::Reset:
        return QCoreApplication::translate("QPlatformTheme", "Reset");
    case QPlatformDialogHelper::RestoreDefaults:
        return QCoreApplication::translate("QPlatformTheme", "Restore Defaults");
    default:
        break;
    }
    return QString();
}

QString QPlatformTheme::removeMnemonics(const QString &original)
{
    const auto mnemonicInParentheses = [](QStringView text) {
        /* Format of mnemonics to remove is /\(&[^&]\)/ but accept full-width
           forms of ( and ) as equivalent, for cross-platform compatibility with
           MS (and consequent behavior of translators, see QTBUG-110829).
        */
        Q_ASSERT(text.size() == 4); // Caller's responsibility.
        constexpr QChar wideOpen = u'\uff08', wideClose = u'\uff09';
        if (!text.startsWith(u'(') && !text.startsWith(wideOpen))
            return false;
        if (text[1] != u'&' || text[2] == u'&')
            return false;
        return text.endsWith(u')') || text.endsWith(wideClose);
    };
    QString returnText(original.size(), u'\0');
    int finalDest = 0;
    QStringView text(original);
    while (!text.isEmpty()) {
        if (text.startsWith(u'&')) {
            text = text.sliced(1);
            if (text.isEmpty())
                break;
        } else if (text.size() >= 4 && mnemonicInParentheses(text.first(4))) {
            // Advance over the matched mnemonic:
            text = text.sliced(4);
            // Also strip any leading space before it:
            while (finalDest > 0 && returnText.at(finalDest - 1).isSpace())
                --finalDest;
            continue;
        }
        returnText[finalDest] = text.front();
        text = text.sliced(1);
        ++finalDest;
    }
    returnText.truncate(finalDest);
    return returnText;
}

unsigned QPlatformThemePrivate::currentKeyPlatforms()
{
    const uint keyboardScheme = QGuiApplicationPrivate::platformTheme()->themeHint(QPlatformTheme::KeyboardScheme).toInt();
    unsigned result = 1u << keyboardScheme;
#if QT_CONFIG(shortcut)
    if (keyboardScheme == QPlatformTheme::KdeKeyboardScheme
        || keyboardScheme == QPlatformTheme::GnomeKeyboardScheme
        || keyboardScheme == QPlatformTheme::CdeKeyboardScheme)
        result |= KB_X11;
#endif
    return result;
}

QString QPlatformTheme::name() const
{
    return d_func()->name;
}

QT_END_NAMESPACE

#include "moc_qplatformtheme.cpp"
