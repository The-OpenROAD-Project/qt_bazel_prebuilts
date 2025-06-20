// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef QWINDOWSMENU_H
#define QWINDOWSMENU_H

#include "qtwindowsglobal.h"

#include <qpa/qplatformmenu.h>

#include <QtCore/qlist.h>

QT_BEGIN_NAMESPACE

class QDebug;

class QWindowsMenu;
class QWindowsMenuBar;
class QWindowsWindow;

class QWindowsMenuItem : public QPlatformMenuItem
{
    Q_OBJECT
public:
    explicit QWindowsMenuItem(QWindowsMenu *parentMenu = nullptr);
    ~QWindowsMenuItem() override;

    void setText(const QString &text) override;
    void setIcon(const QIcon &icon) override;
    void setMenu(QPlatformMenu *menu) override;
    void setVisible(bool isVisible) override;
    void setIsSeparator(bool isSeparator) override;
    void setFont(const QFont &) override {}
    void setRole(MenuRole) override {}
    void setCheckable(bool checkable) override;
    void setChecked(bool isChecked) override;
#ifndef QT_NO_SHORTCUT
    void setShortcut(const QKeySequence& shortcut) override;
#endif
    void setEnabled(bool enabled) override;
    void setIconSize(int size) override;

    const QWindowsMenu *parentMenu() const { return m_parentMenu; }
    QWindowsMenu *parentMenu() { return m_parentMenu; }
    HMENU parentMenuHandle() const;
    QWindowsMenu *subMenu() const { return m_subMenu; }
    UINT_PTR id() const { return m_id; }
    void setId(uint id) { m_id = id; }
    UINT state() const;
    QString text() const { return m_text; }
    QString nativeText() const;
    bool isVisible() const { return m_visible; }

    void insertIntoMenu(QWindowsMenu *menuItem, bool append, int index);
    bool removeFromMenu();

#ifndef QT_NO_DEBUG_STREAM
    void formatDebug(QDebug &d) const;
#endif

private:
    void updateBitmap();
    void freeBitmap();
    void updateText();
    void insertIntoMenuHelper(QWindowsMenu *menu, bool append, int index);

    QWindowsMenu *m_parentMenu = nullptr;
    QWindowsMenu *m_subMenu = nullptr;
    UINT_PTR m_id; // Windows Id sent as wParam with WM_COMMAND or submenu handle.
    QString m_text;
    QIcon m_icon;
    HBITMAP m_hbitmap = nullptr;
    int m_iconSize = 0;
    bool m_separator = false;
    bool m_visible = true;
    bool m_checkable = false;
    bool m_checked = false;
    bool m_enabled = true;
#if QT_CONFIG(shortcut)
    QKeySequence m_shortcut;
#endif
};

class QWindowsMenu : public QPlatformMenu
{
    Q_OBJECT
public:
    using MenuItems = QList<QWindowsMenuItem *>;

    QWindowsMenu();
    ~QWindowsMenu();

    void insertMenuItem(QPlatformMenuItem *menuItem, QPlatformMenuItem *before) override;
    void removeMenuItem(QPlatformMenuItem *menuItem) override;
    void syncMenuItem(QPlatformMenuItem *) override {}
    void syncSeparatorsCollapsible(bool) override {}

    void setText(const QString &text) override;
    void setIcon(const QIcon &icon) override;
    void setEnabled(bool enabled) override;
    bool isEnabled() const override { return m_enabled; }
    void setVisible(bool visible) override;

    QPlatformMenuItem *menuItemAt(int position) const override;
    QPlatformMenuItem *menuItemForTag(quintptr tag) const override;

    QPlatformMenuItem *createMenuItem() const override;
    QPlatformMenu *createSubMenu() const override;

    HMENU menuHandle() const { return m_hMenu; }
    UINT_PTR id() const { return reinterpret_cast<UINT_PTR>(m_hMenu); }
    QString text() const { return m_text; }
    const MenuItems &menuItems() const { return m_menuItems; }
    QWindowsMenuItem *itemForSubMenu(const QWindowsMenu *subMenu) const;

    const QWindowsMenuBar *parentMenuBar() const { return m_parentMenuBar; }
    HMENU parentMenuBarHandle() const;
    const QWindowsMenu *parentMenu() const { return m_parentMenu; }
    void setAsItemSubMenu(QWindowsMenuItem *item);
    void notifyRemoved(QWindowsMenuItem *item) { m_menuItems.removeOne(item); }
    HMENU parentMenuHandle() const;
    HMENU parentHandle() const;
    bool isVisible() const { return m_visible; }
    void insertIntoMenuBar(QWindowsMenuBar *bar, bool append, int index);
    bool removeFromParent();

#ifndef QT_NO_DEBUG_STREAM
    void formatDebug(QDebug &d) const;
#endif

protected:
    explicit QWindowsMenu(QWindowsMenu *parentMenu, HMENU menu);

private:
    QWindowsMenuBar *m_parentMenuBar = nullptr;
    QWindowsMenu *m_parentMenu = nullptr;
    MenuItems m_menuItems;
    HMENU m_hMenu = nullptr;
    QString m_text;
    QIcon m_icon;
    bool m_visible = true;
    bool m_enabled = true;
};

class QWindowsPopupMenu : public QWindowsMenu
{
    Q_OBJECT
public:
    QWindowsPopupMenu();

    static bool notifyTriggered(uint id);
    static bool notifyAboutToShow(HMENU hmenu);

    void showPopup(const QWindow *parentWindow, const QRect &targetRect, const QPlatformMenuItem *item) override;
    void dismiss() override {}

    bool trackPopupMenu(HWND windowHandle, int x, int y);
};

class QWindowsMenuBar : public QPlatformMenuBar
{
    Q_OBJECT
public:
    using Menus = QList<QWindowsMenu *>;

    QWindowsMenuBar();
    ~QWindowsMenuBar() override;

    void insertMenu(QPlatformMenu *menu, QPlatformMenu *before) override;
    void removeMenu(QPlatformMenu *menu) override;
    void syncMenu(QPlatformMenu *) override {}
    void handleReparent(QWindow *newParentWindow) override;

    QPlatformMenu *menuForTag(quintptr tag) const override;
    QPlatformMenu *createMenu() const override;

    HMENU menuBarHandle() const { return m_hMenuBar; }
    const Menus &menus() const { return m_menus; }
    bool notifyTriggered(uint id);
    bool notifyAboutToShow(HMENU hmenu);
    void notifyRemoved(QWindowsMenu *menu) { m_menus.removeOne(menu); }
    void redraw() const;

    void install(QWindowsWindow *window);

    static QWindowsMenuBar *menuBarOf(const QWindow *notYetCreatedWindow);

#ifndef QT_NO_DEBUG_STREAM
    void formatDebug(QDebug &d) const;
#endif

private:
    QWindowsWindow *platformWindow() const;
    void removeFromWindow();

    Menus m_menus;
    HMENU m_hMenuBar = nullptr;
};

#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug d, const QPlatformMenuItem *);
QDebug operator<<(QDebug d, const QPlatformMenu *);
QDebug operator<<(QDebug d, const QPlatformMenuBar *);
#endif // !QT_NO_DEBUG_STREAM

QT_END_NAMESPACE

#endif // QWINDOWSMENU_H
