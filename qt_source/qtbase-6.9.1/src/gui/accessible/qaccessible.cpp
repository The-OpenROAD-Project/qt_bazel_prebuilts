// Copyright (C) 2020 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only
// Qt-Security score:critical reason:data-parser

#include "qaccessible.h"

#include "qaccessiblecache_p.h"
#include "qaccessibleplugin.h"
#include "qaccessibleobject.h"
#include "qaccessiblebridge.h"
#include <QtCore/qtextboundaryfinder.h>
#include <QtGui/qclipboard.h>
#include <QtGui/qguiapplication.h>
#include <QtGui/qtextcursor.h>
#include <private/qguiapplication_p.h>
#include <qpa/qplatformaccessibility.h>
#include <qpa/qplatformintegration.h>

#include <QtCore/qdebug.h>
#include <QtCore/qloggingcategory.h>
#include <QtCore/qmetaobject.h>
#include <QtCore/private/qmetaobject_p.h>
#include <QtCore/qhash.h>
#include <private/qfactoryloader_p.h>

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

Q_STATIC_LOGGING_CATEGORY(lcAccessibilityCore, "qt.accessibility.core");

/*!
    \class QAccessible
    \brief The QAccessible class provides enums and static functions
    related to accessibility.

    \ingroup accessibility
    \inmodule QtGui

    This class is part of \l {Accessibility for QWidget Applications}.

    Accessible applications can be used by people who are not able to
    use applications by conventional means.

    The functions in this class are used for communication between
    accessible applications (also called AT Servers) and
    accessibility tools (AT Clients), such as screen readers and
    braille displays. Clients and servers communicate in the following way:

    \list
    \li  \e{AT Servers} notify the clients about events through calls to the
        updateAccessibility() function.

    \li  \e{AT Clients} request information about the objects in the server.
        The QAccessibleInterface class is the core interface, and encapsulates
        this information in a pure virtual API. Implementations of the interface
        are provided by Qt through the queryAccessibleInterface() API.
    \endlist

    The communication between servers and clients is initialized by
    the setRootObject() function. Function pointers can be installed
    to replace or extend the default behavior of the static functions
    in QAccessible.

    Qt supports Microsoft Active Accessibility (MSAA), \macos
    Accessibility, and the Unix/X11 AT-SPI standard. Other backends
    can be supported using QAccessibleBridge.

    In the Unix/X11 AT-SPI implementation, applications become accessible
    when two conditions are met:
    \list
    \li org.a11y.Status.IsEnabled DBus property is true
    \li org.a11y.Status.ScreenReaderEnabled DBus property is true
    \endlist
    An alternative to setting the DBus AT-SPI properties is to set
    the QT_LINUX_ACCESSIBILITY_ALWAYS_ON environment variable.

    In addition to QAccessible's static functions, Qt offers one
    generic interface, QAccessibleInterface, that can be used to wrap
    all widgets and objects (e.g., QPushButton). This single
    interface provides all the metadata necessary for the assistive
    technologies. Qt provides implementations of this interface for
    its built-in widgets as plugins.

    When you develop custom widgets, you can create custom subclasses
    of QAccessibleInterface and distribute them as plugins (using
    QAccessiblePlugin) or compile them into the application.
    Likewise, Qt's predefined accessibility support can be built as
    plugin (the default) or directly into the Qt library. The main
    advantage of using plugins is that the accessibility classes are
    only loaded into memory if they are actually used; they don't
    slow down the common case where no assistive technology is being
    used.

    Qt also includes two convenience classes, QAccessibleObject and
    QAccessibleWidget, that inherit from QAccessibleInterface and
    provide the lowest common denominator of metadata (e.g., widget
    geometry, window title, basic help text). You can use them as
    base classes when wrapping your custom QObject or QWidget
    subclasses.

    \sa QAccessibleInterface
*/


/*!
    \class QAccessible::State

    \inmodule QtGui

    This structure defines bit flags that indicate
    the state of an accessible object. The values are:

    \value active                  The object is the active window or the active sub-element in a container (that would get focus when focusing the container).
    \value adjustable              The object represents an adjustable value, e.g. sliders.
    \value animated                The object's appearance changes frequently.
    \value busy                    The object cannot accept input at the moment.
    \value checkable               The object is checkable.
    \value checked                 The object's check box is checked.
    \value checkStateMixed         The third state of checkboxes (half checked in tri-state check boxes).
    \value collapsed               The object is collapsed, e.g. a closed listview item, or an iconified window.
    \value defaultButton           The object represents the default button in a dialog.
    \value defunct                 The object no longer exists.
    \value editable                The object has a text carret (and often implements the text interface).
    \value expandable              The object is expandable, mostly used for cells in a tree view.
    \value expanded                The object is expanded, currently its children are visible.
    \value extSelectable           The object supports extended selection.
    \value focusable               The object can receive focus. Only objects in the active window can receive focus.
    \value focused                 The object has keyboard focus.
    \value hasPopup                The object opens a popup.
    \value hotTracked              The object's appearance is sensitive to the mouse cursor position.
    \value invalid                 The object is no longer valid (because it has been deleted).
    \value invisible               The object is not visible to the user.
    \value linked                  The object is linked to another object, e.g. a hyperlink.
    \value marqueed                The object displays scrolling contents, e.g. a log view.
    \value modal                   The object blocks input from other objects.
    \value movable                 The object can be moved.
    \value multiLine               The object has multiple lines of text (word wrap), as opposed to a single line.
    \value multiSelectable         The object supports multiple selected items.
    \value offscreen               The object is clipped by the visible area. Objects that are off screen are also invisible.
    \value passwordEdit            The object is a password field, e.g. a line edit for entering a Password.
    \value playsSound              The object produces sound when interacted with.
    \value pressed                 The object is pressed.
    \value readOnly                The object can usually be edited, but is explicitly set to read-only.
    \value searchEdit              The object is a line edit that is the input for search queries.
    \value selectable              The object is selectable.
    \value selectableText          The object has text which can be selected. This is different from selectable which refers to the object's children.
    \value selected                The object is selected, this is independent of text selection.
    \value selfVoicing             The object describes itself through speech or sound.
    \value sizeable                The object can be resized, e.g. top-level windows.
    \value summaryElement          The object summarizes the state of the window and should be treated with priority.
    \value supportsAutoCompletion  The object has auto-completion, for example in line edits or combo boxes.
    \value traversed               The object is linked and has been visited.
    \value updatesFrequently       The object changes frequently and needs to be refreshed when accessing it.
    \value disabled                The object is unavailable to the user, e.g. a disabled widget.

    Implementations of QAccessibleInterface::state() return a combination
    of these flags.
*/

/*!
    \fn QAccessible::State::State()

    Constructs a new QAccessible::State with all states set to false.
*/

/*!
    \enum QAccessible::Event

    This enum type defines accessible event types.

    \omitvalue InvalidEvent                 \omit Internal: Used when creating subclasses of QAccessibleEvent. \endomit
    \value AcceleratorChanged               The keyboard accelerator for an action has been changed.
    \value ActionChanged                    An action has been changed.
    \value ActiveDescendantChanged
    \value Alert                            A system alert (e.g., a message from a QMessageBox)
    \value [since 6.8] Announcement         The announcement of a message is requested.
    \value AttributeChanged
    \value ContextHelpEnd                   Context help (QWhatsThis) for an object is finished.
    \value ContextHelpStart                 Context help (QWhatsThis) for an object is initiated.
    \value DefaultActionChanged             The default QAccessible::Action for the accessible
                                            object has changed.
    \value DescriptionChanged               The object's QAccessible::Description changed.
    \value DialogEnd                        A dialog (QDialog) has been hidden
    \value DialogStart                      A dialog (QDialog) has been set visible.
    \value DocumentContentChanged           The contents of a text document have changed.
    \value DocumentLoadComplete             A document has been loaded.
    \value DocumentLoadStopped              A document load has been stopped.
    \value DocumentReload                   A document reload has been initiated.
    \value DragDropEnd                      A drag and drop operation is about to finished.
    \value DragDropStart                    A drag and drop operation is about to be initiated.
    \value Focus                            An object has gained keyboard focus.
    \value ForegroundChanged                A window has been activated (i.e., a new window has
                                            gained focus on the desktop).
    \value HelpChanged                      The QAccessible::Help text property of an object has
                                            changed.
    \value HyperlinkEndIndexChanged         The end position of the display text for a hypertext
                                            link has changed.
    \value HyperlinkNumberOfAnchorsChanged  The number of anchors in a hypertext link has changed,
                                            perhaps because the display text has been split to
                                            provide more than one link.
    \value HyperlinkSelectedLinkChanged     The link for the selected hypertext link has changed.
    \value HyperlinkStartIndexChanged       The start position of the display text for a hypertext
                                            link has changed.
    \value HypertextChanged                 The display text for a hypertext link has changed.
    \value HypertextLinkActivated           A hypertext link has been activated, perhaps by being
                                            clicked or via a key press.
    \value HypertextLinkSelected            A hypertext link has been selected.
    \value HypertextNLinksChanged
    \value [since 6.8] IdentifierChanged    The identifier of an object has changed.
    \value LocationChanged                  An object's location on the screen has changed.
    \value MenuCommand                      A menu item is triggered.
    \value MenuEnd                          A menu has been closed (Qt uses PopupMenuEnd for all
                                            menus).
    \value MenuStart                        A menu has been opened on the menubar (Qt uses
                                            PopupMenuStart for all menus).
    \value NameChanged                      The QAccessible::Name property of an object has changed.
    \value ObjectAttributeChanged
    \value ObjectCreated                    A new object is created.
    \value ObjectDestroyed                  An object is deleted.
    \value ObjectHide                       An object is hidden; for example, with QWidget::hide().
                                            Any children the object that is hidden has do not send
                                            this event. It is not sent when an object is hidden as
                                            it is being obscured by others.
    \value ObjectReorder                    A layout or item view  has added, removed, or moved an
                                            object (Qt does not use this event).
    \value ObjectShow                       An object is displayed; for example, with
                                            QWidget::show().
    \value PageChanged
    \value ParentChanged                    An object's parent object changed.
    \value PopupMenuEnd                     A pop-up menu has closed.
    \value PopupMenuStart                   A pop-up menu has opened.
    \value ScrollingEnd                     A scrollbar scroll operation has ended (the mouse has
                                            released the slider handle).
    \value ScrollingStart                   A scrollbar scroll operation is about to start; this may
                                            be caused by a mouse press on the slider handle, for
                                            example.
    \value SectionChanged
    \value SelectionAdd                     An item has been added to the selection in an item view.
    \value SelectionRemove                  An item has been removed from an item view selection.
    \value Selection                        The selection has changed in a menu or item view.
    \value SelectionWithin                  Several changes to a selection has occurred in an item
                                            view.
    \value SoundPlayed                      A sound has been played by an object
    \omitvalue StateChanged                 \omit The QAccessible::State of an object has changed.
                                            This value is used internally for the QAccessibleStateChangeEvent. \endomit
    \value TableCaptionChanged              A table caption has been changed.
    \value TableColumnDescriptionChanged    The description of a table column, typically found in
                                            the column's header, has been changed.
    \value TableColumnHeaderChanged         A table column header has been changed.
    \omitvalue TableModelChanged            \omit The model providing data for a table has been changed. \endomit
    \value TableRowDescriptionChanged       The description of a table row, typically found in the
                                            row's header, has been changed.
    \value TableRowHeaderChanged            A table row header has been changed.
    \value TableSummaryChanged              The summary of a table has been changed.
    \omitvalue TextAttributeChanged
    \omitvalue TextCaretMoved               \omit The caret has moved in an editable widget.
                                            The caret represents the cursor position in an editable
                                            widget with the input focus. \endomit
    \value TextColumnChanged                A text column has been changed.
    \omitvalue TextInserted                 \omit Text has been inserted into an editable widget. \endomit
    \omitvalue TextRemoved                  \omit Text has been removed from an editable widget. \endomit
    \omitvalue TextSelectionChanged         \omit The selected text has changed in an editable widget. \endomit
    \omitvalue TextUpdated                  \omit The text has been update in an editable widget. \endomit
    \omitvalue ValueChanged                 \omit The QAccessible::Value of an object has changed. \endomit
    \value VisibleDataChanged

    The values for this enum are defined to be the same as those defined in the
    \l{AccessibleEventID.idl File Reference}{IAccessible2} and
    \l{Microsoft Active Accessibility Event Constants}{MSAA} specifications.
*/

/*!
    \enum QAccessible::Role

    This enum defines the role of an accessible object. The roles are:

    \value AlertMessage     An object that is used to alert the user.
    \value Animation        An object that displays an animation.
    \value Application      The application's main window.
    \value Assistant        An object that provides interactive help.
    \value [since 6.9] BlockQuote       A section of content that is quoted from another source.
    \value Border           An object that represents a border.
    \value ButtonDropDown   A button that drops down a list of items.
    \value ButtonDropGrid   A button that drops down a grid.
    \value ButtonMenu       A button that drops down a menu.
    \value Canvas           An object that displays graphics that the user can interact with.
    \value Caret            An object that represents the system caret (text cursor).
    \value Cell             A cell in a table.
    \value Chart            An object that displays a graphical representation of data.
    \value CheckBox         An object that represents an option that can be checked or unchecked. Some options provide a "mixed" state, e.g. neither checked nor unchecked.
    \value Client           The client area in a window.
    \value Clock            A clock displaying time.
    \value ColorChooser     A dialog that lets the user choose a color.
    \value Column           A column of cells, usually within a table.
    \value ColumnHeader     A header for a column of data.
    \value ComboBox         A list of choices that the user can select from.
    \value ComplementaryContent A part of the document or web page that is complementary to the main content, usually a landmark (see WAI-ARIA).
    \value Cursor           An object that represents the mouse cursor.
    \value Desktop          The object represents the desktop or workspace.
    \value Dial             An object that represents a dial or knob.
    \value Dialog           A dialog box.
    \value Document         A document, for example in an office application.
    \value EditableText     Editable text such as a line or text edit.
    \value Equation         An object that represents a mathematical equation.
    \value Footer           A footer in a page (usually in documents).
    \value Form             A web form containing controls.
    \value Graphic          A graphic or picture, e.g. an icon.
    \value Grip             A grip that the user can drag to change the size of widgets.
    \value Grouping         An object that represents a logical grouping of other objects.
    \value Heading          A heading in a document.
    \value HelpBalloon      An object that displays help in a separate, short lived window.
    \value HotkeyField      A hotkey field that allows the user to enter a key sequence.
    \value Indicator        An indicator that represents a current value or item.
    \value LayeredPane      An object that can contain layered children, e.g. in a stack.
    \value Link             A link to something else.
    \value List             A list of items, from which the user can select one or more items.
    \value ListItem         An item in a list of items.
    \value MenuBar          A menu bar from which menus are opened by the user.
    \value MenuItem         An item in a menu or menu bar.
    \value NoRole           The object has no role. This usually indicates an invalid object.
    \value Note             A section whose content is parenthetic or ancillary to the main content of the resource.
    \value Notification     An object that represents a notification (e.g. in the system tray). This role only has an effect on Linux.
    \value PageTab          A page tab that the user can select to switch to a different page in a dialog.
    \value PageTabList      A list of page tabs.
    \value Paragraph        A paragraph of text (usually found in documents).
    \value Pane             A generic container.
    \value PopupMenu        A menu which lists options that the user can select to perform an action.
    \value ProgressBar      The object displays the progress of an operation in progress.
    \value PropertyPage     A property page where the user can change options and settings.
    \value Button           A button.
    \value RadioButton      An object that represents an option that is mutually exclusive with other options.
    \value Row              A row of cells, usually within a table.
    \value RowHeader        A header for a row of data.
    \value ScrollBar        A scroll bar, which allows the user to scroll the visible area.
    \value Section          A section (in a document).
    \value Separator        A separator that divides space into logical areas.
    \value Slider           A slider that allows the user to select a value within a given range.
    \value Sound            An object that represents a sound.
    \value SpinBox          A spin box widget that allows the user to enter a value within a given range.
    \value Splitter         A splitter distributing available space between its child widgets.
    \value StaticText       Static text, such as labels for other widgets.
    \value StatusBar        A status bar.
    \value Table            A table representing data in a grid of rows and columns.
    \value Terminal         A terminal or command line interface.
    \value TitleBar         The title bar caption of a window.
    \value ToolBar          A tool bar, which groups widgets that the user accesses frequently.
    \value ToolTip          A tool tip which provides information about other objects.
    \value Tree             A list of items in a tree structure.
    \value TreeItem         An item in a tree structure.
    \value UserRole         The first value to be used for user defined roles.
    \value WebDocument      HTML document, usually in a browser.
    \value Whitespace       Blank space between other objects.
    \value Window           A top level window.
*/

/*!
    \enum QAccessible::RelationFlag

    This enum type defines bit flags that can be combined to indicate
    the relationship between two accessible objects. It is used by
    the relations() function, which returns a list of all the related
    interfaces of the calling object, together with the relations
    for each object.

    Each entry in the list is a std::pair where the \c second member stores
    the relation type(s) between the \c returned object represented by the
    \c first member and the \c origin (the caller) interface/object.

    In the table below, the \c returned object refers to the object in
    the returned list, and the \c origin object is the one represented
    by the calling interface.

    \value Label                        The \c returned object is the label for the \c origin object.
    \value Labelled                     The \c returned object is labelled by the \c origin object.
    \value Controller                   The \c returned object controls the \c origin object.
    \value Controlled                   The \c returned object is controlled by the \c origin object.
    \value [since 6.6] DescriptionFor   The \c returned object provides a description for the \c origin object.
    \value [since 6.6] Described        The \c returned object is described by the \c origin object.
    \value [since 6.6] FlowsFrom        Content logically flows from the \c returned object to the \c origin object.
    \value [since 6.6] FlowsTo          Content logically flows to the \c returned object from the \c origin object.
    \value AllRelations                 Used as a mask to specify that we are interesting in information
                                        about all relations

    Implementations of relations() return a combination of these flags.
    Some values are mutually exclusive.
*/

/*!
    \enum QAccessible::Text

    This enum specifies string information that an accessible object
    returns.

    \value Name                    The name of the object. This can be used both
                                   as an identifier or a short description by
                                   accessible clients.
    \value Description             A short text describing the object.
    \value Value                   The value of the object.
    \value Help                    A longer text giving information about how to use the object.
    \value Accelerator             The keyboard shortcut that executes the object's default action.
    \value UserText                The first value to be used for user defined text.
    \value [since 6.8] Identifier  An identifier for the object for e.g. UI tests.
    \omitvalue DebugDescription
*/

/*! \enum QAccessible::TextBoundaryType
    This enum describes different types of text boundaries. It follows the IAccessible2 API and is used in the \l QAccessibleTextInterface.

    \value CharBoundary         Use individual characters as boundary.
    \value WordBoundary         Use words as boundaries.
    \value SentenceBoundary     Use sentences as boundary.
    \value ParagraphBoundary    Use paragraphs as boundary.
    \value LineBoundary         Use newlines as boundary.
    \value NoBoundary           No boundary (use the whole text).

    \sa QAccessibleTextInterface
*/

/*! \enum QAccessible::Attribute
    This enum describes different types of attributes used by the
    \l QAccessibleAttributesInterface.
    \since 6.8

    These attributes are comparable to the concept of properties/(object)
    attributes found in ARIA, AT-SPI2, IAccessible, UIA and NSAccessibility
    and are mapped to their platform counterpart where applicable.

    Each attribute is handled as a key-value pair, with the values of this
    enumeration being used as keys.

    Attribute values are represented in a \l QVariant. The type of the value
    stored in the \l QVariant is fixed and specified below for each of the
    attribute types.

    \value Custom               value type: \a QHash<QString, QString>
                                The \a Custom attribute is special in that
                                it can effectively represent multiple attributes at
                                once, since it itself is a \l QHash used to represent
                                key-value pairs.
                                For platforms supporting custom key-value pairs for
                                attributes, those set in the \a Custom attribute
                                are bridged to the platform layer without applying any
                                translation to platform-specific attributes. In general,
                                the other, more strongly typed attributes should be used.
                                This attribute can e.g. be used for prototyping
                                before officially adding an official new enumeration value
                                for a specific feature.
    \value Level                value type: \a int
                                Defines the hierarchical level of an element within a structure,
                                e.g. the heading level of a heading. This attribute conceptually
                                matches the "aria-level" property in ARIA.

    \sa QAccessibleAttributesInterface
*/

/*! \enum QAccessible::AnnouncementPoliteness
    This enum describes the priority for announcements used by the
    \l QAccessibleAnnouncementEvent.
    \since 6.8

    With \a QAccessible::AnouncementPoliteness::Polite, assistive technologies
    should announce the message at the next graceful opportunity such as at the
    end of speaking the current sentence or when the user pauses typing.

    When specifying \a QAccessible::AnouncementPoliteness::Assertive, assistive
    technologies should notify the user immediately.

    Because an interruption might disorient users or cause them to not complete
    their current task, \a QAccessible::AnouncementPoliteness::Assertive should
    not be used unless the interruption is imperative.

    \value Polite      The announcement has normal priority.
    \value Assertive   The announcement has high priority and should notify
                       the user immediately, even if that means interrupting the user's
                       current task.

    \sa QAccessibleAnnouncementEvent
*/


/*!
    \enum QAccessible::InterfaceType

    \l QAccessibleInterface supports several sub interfaces.
    In order to provide more information about some objects, their accessible
    representation should implement one or more of these interfaces.

    \note When subclassing one of these interfaces, \l QAccessibleInterface::interface_cast() needs to be implemented.

    \value TextInterface            For text that supports selections or is more than one line. Simple labels do not need to implement this interface.
    \omitvalue EditableTextInterface    \omit For text that can be edited by the user. \endomit
    \value ValueInterface           For objects that are used to manipulate a value, for example slider or scroll bar.
    \value ActionInterface          For interactive objects that allow the user to trigger an action. Basically everything that allows for example mouse interaction.
    \omitvalue ImageInterface       \omit For objects that represent an image. This interface is generally less important. \endomit
    \value TableInterface           For lists, tables and trees.
    \value TableCellInterface       For cells in a TableInterface object.
    \value HyperlinkInterface       For hyperlink nodes (usually embedded as children of text nodes)
    \value [since 6.5] SelectionInterface For non-text objects that support selection of child objects.
    \value [since 6.8] AttributesInterface For objects that support object-specific attributes.

    \sa QAccessibleInterface::interface_cast(), QAccessibleTextInterface, QAccessibleValueInterface, QAccessibleActionInterface, QAccessibleTableInterface, QAccessibleTableCellInterface, QAccessibleSelectionInterface, QAccessibleAttributesInterface
*/

#if QT_CONFIG(accessibility)

/*!
    Destroys the QAccessibleInterface.
*/
QAccessibleInterface::~QAccessibleInterface()
{
}

/*!
    \typedef QAccessible::Id

    Synonym for unsigned, used by the QAccessibleInterface cache.
*/


/* accessible widgets plugin discovery stuff */
Q_GLOBAL_STATIC_WITH_ARGS(QFactoryLoader, acLoader,
    (QAccessibleFactoryInterface_iid, "/accessible"_L1))
typedef QHash<QString, QAccessiblePlugin*> QAccessiblePluginsHash;
Q_GLOBAL_STATIC(QAccessiblePluginsHash, qAccessiblePlugins)

// FIXME turn this into one global static struct
Q_GLOBAL_STATIC(QList<QAccessible::InterfaceFactory>, qAccessibleFactories)
Q_GLOBAL_STATIC(QList<QAccessible::ActivationObserver *>, qAccessibleActivationObservers)

QAccessible::UpdateHandler QAccessible::updateHandler = nullptr;
QAccessible::RootObjectHandler QAccessible::rootObjectHandler = nullptr;

static bool cleanupAdded = false;

static QPlatformAccessibility *platformAccessibility()
{
    QPlatformIntegration *pfIntegration = QGuiApplicationPrivate::platformIntegration();
    return pfIntegration ? pfIntegration->accessibility() : nullptr;
}

/*!
    \fn QAccessible::QAccessible()
    \internal

    This class is purely a collection of enums and static functions,
    it is not supposed to be instantiated.
*/


/*!
    \internal
*/
void QAccessible::cleanup()
{
    if (QPlatformAccessibility *pfAccessibility = platformAccessibility())
        pfAccessibility->cleanup();
}

static void qAccessibleCleanup()
{
    qAccessibleActivationObservers()->clear();
    qAccessibleFactories()->clear();
}

/*!
    \typedef QAccessible::InterfaceFactory

    This is a typedef for a pointer to a function with the following
    signature:

    \snippet code/src_gui_accessible_qaccessible.cpp 1

    The function receives a QString and a QObject pointer, where the
    QString is the key identifying the interface. The QObject is used
    to pass on to the QAccessibleInterface so that it can hold a reference
    to it.

    If the key and the QObject does not have a corresponding
    QAccessibleInterface, \nullptr will be returned.

    Installed factories are called by queryAccessibilityInterface() until
    one provides an interface.
*/

/*!
    \typedef QAccessible::UpdateHandler

    \internal

    A function pointer type. Use a function with this prototype to install
    your own update function.

    The function is called by updateAccessibility().
*/

/*!
    \typedef QAccessible::RootObjectHandler

    \internal

    A function pointer type. Use a function with this prototype to install
    your own root object handler.

    The function is called by setRootObject().
*/


/*!
    Installs the InterfaceFactory \a factory. The last factory added
    is the first one used by queryAccessibleInterface().
*/
void QAccessible::installFactory(InterfaceFactory factory)
{
    if (!factory)
        return;

    if (!cleanupAdded) {
        qAddPostRoutine(qAccessibleCleanup);
        cleanupAdded = true;
    }
    if (qAccessibleFactories()->contains(factory))
        return;
    qAccessibleFactories()->append(factory);
}

/*!
    Removes \a factory from the list of installed InterfaceFactories.
*/
void QAccessible::removeFactory(InterfaceFactory factory)
{
    qAccessibleFactories()->removeAll(factory);
}

/*!
    \internal

    Installs the given \a handler as the function to be used by
    updateAccessibility(), and returns the previously installed
    handler.
*/
QAccessible::UpdateHandler QAccessible::installUpdateHandler(UpdateHandler handler)
{
    UpdateHandler old = updateHandler;
    updateHandler = handler;
    return old;
}

/*!
    \internal

    Installs the given \a handler as the function to be used by setRootObject(),
    and returns the previously installed handler.
*/
QAccessible::RootObjectHandler QAccessible::installRootObjectHandler(RootObjectHandler handler)
{
    RootObjectHandler old = rootObjectHandler;
    rootObjectHandler = handler;
    return old;
}

/*!
    \class QAccessible::ActivationObserver
    \internal

    Interface to listen to activation or deactivation of the accessibility framework.
    \sa installActivationObserver()
*/

QAccessible::ActivationObserver::~ActivationObserver()
{
}

/*!
    \internal

    Install \a observer to get notified of activation or deactivation (global accessibility has been enabled or disabled).
*/
void QAccessible::installActivationObserver(QAccessible::ActivationObserver *observer)
{
    if (!observer)
        return;

    if (!cleanupAdded) {
        qAddPostRoutine(qAccessibleCleanup);
        cleanupAdded = true;
    }
    if (qAccessibleActivationObservers()->contains(observer))
        return;
    qAccessibleActivationObservers()->append(observer);
}

/*!
    \internal

    Remove an \a observer to no longer get notified of state changes.
    \sa installActivationObserver()
*/
void QAccessible::removeActivationObserver(ActivationObserver *observer)
{
    qAccessibleActivationObservers()->removeAll(observer);
}

/*!
    If a QAccessibleInterface implementation exists for the given \a object,
    this function returns a pointer to the implementation; otherwise it
    returns \nullptr.

    The function calls all installed factory functions (from most
    recently installed to least recently installed) until one is found
    that provides an interface for the class of \a object. If no
    factory can provide an accessibility implementation for the class
    the function loads installed accessibility plugins, and tests if
    any of the plugins can provide the implementation.

    If no implementation for the object's class is available, the
    function tries to find an implementation for the object's parent
    class, using the above strategy.

    All interfaces are managed by an internal cache and should not be deleted.
*/
QAccessibleInterface *QAccessible::queryAccessibleInterface(QObject *object)
{
    if (!object)
        return nullptr;

    if (Id id = QAccessibleCache::instance()->idForObject(object))
        return QAccessibleCache::instance()->interfaceForId(id);

    // Create a QAccessibleInterface for the object class. Start by the most
    // derived class and walk up the class hierarchy.
    const QMetaObject *mo = object->metaObject();
    const auto *objectPriv = QObjectPrivate::get(object);
    /*
     We do not want to cache each and every QML metaobject (Button_QMLTYPE_124,
     Button_QMLTYPE_125, etc.). Those dynamic metaobjects shouldn't have an
     accessible interface in any case. Instead, we start the whole checking
     with the first non-dynamic meta-object. To avoid potential regressions
     in other areas of Qt that also use dynamic metaobjects, we only do this
     for objects that are QML-related (approximated by checking whether they
     have ddata set).
    */
    const bool qmlRelated = !objectPriv->isDeletingChildren &&
                            objectPriv->declarativeData;
    while (qmlRelated && mo) {
        auto mop = QMetaObjectPrivate::get(mo);
        if (!mop || !(mop->flags & DynamicMetaObject))
            break;

        mo = mo->superClass();
    };
    while (mo) {
        const QString cn = QLatin1StringView(mo->className());

        // Check if the class has a InterfaceFactory installed.
        for (int i = qAccessibleFactories()->size(); i > 0; --i) {
            InterfaceFactory factory = qAccessibleFactories()->at(i - 1);
            if (QAccessibleInterface *iface = factory(cn, object)) {
                QAccessibleCache::instance()->insert(object, iface);
                Q_ASSERT(QAccessibleCache::instance()->containsObject(object));
                return iface;
            }
        }
        // Find a QAccessiblePlugin (factory) for the class name. If there's
        // no entry in the cache try to create it using the plugin loader.
        if (!qAccessiblePlugins()->contains(cn)) {
            QAccessiblePlugin *factory = nullptr; // 0 means "no plugin found". This is cached as well.
            const int index = acLoader()->indexOf(cn);
            if (index != -1)
                factory = qobject_cast<QAccessiblePlugin *>(acLoader()->instance(index));
            qAccessiblePlugins()->insert(cn, factory);
        }

        // At this point the cache should contain a valid factory pointer or 0:
        Q_ASSERT(qAccessiblePlugins()->contains(cn));
        QAccessiblePlugin *factory = qAccessiblePlugins()->value(cn);
        if (factory) {
            QAccessibleInterface *result = factory->create(cn, object);
            if (result) {
                QAccessibleCache::instance()->insert(object, result);
                Q_ASSERT(QAccessibleCache::instance()->containsObject(object));
            }
            return result;
        }
        mo = mo->superClass();
    }

    if (object == qApp) {
        QAccessibleInterface *appInterface = new QAccessibleApplication;
        QAccessibleCache::instance()->insert(object, appInterface);
        Q_ASSERT(QAccessibleCache::instance()->containsObject(qApp));
        return appInterface;
    }

    return nullptr;
}

/*!
    \brief Call this function to ensure that manually created interfaces
    are properly memory managed.

    Must only be called exactly once per interface \a iface.
    This is implicitly called when calling queryAccessibleInterface,
    calling this function is only required when QAccessibleInterfaces
    are instantiated with the "new" operator. This is not recommended,
    whenever possible use the default functions and let \l queryAccessibleInterface()
    take care of this.

    When it is necessary to reimplement the QAccessibleInterface::child() function
    and returning the child after constructing it, this function needs to be called.
 */
QAccessible::Id QAccessible::registerAccessibleInterface(QAccessibleInterface *iface)
{
    Q_ASSERT(iface);
    return QAccessibleCache::instance()->insert(iface->object(), iface);
}

/*!
    Removes the interface belonging to this \a id from the cache and
    deletes it. The id becomes invalid an may be re-used by the
    cache.
*/
void QAccessible::deleteAccessibleInterface(Id id)
{
    QAccessibleCache::instance()->deleteInterface(id);
}

/*!
    Returns the unique ID for the QAccessibleInterface \a iface.
*/
QAccessible::Id QAccessible::uniqueId(QAccessibleInterface *iface)
{
    Id id = QAccessibleCache::instance()->idForInterface(iface);
    if (!id)
        id = registerAccessibleInterface(iface);
    return id;
}

/*!
    Returns the QAccessibleInterface belonging to the \a id.

    Returns \nullptr if the id is invalid.
*/
QAccessibleInterface *QAccessible::accessibleInterface(Id id)
{
    return QAccessibleCache::instance()->interfaceForId(id);
}


/*!
    Returns \c true if the platform requested accessibility information.

    This function will return false until a tool such as a screen reader
    accessed the accessibility framework. It is still possible to use
    \l QAccessible::queryAccessibleInterface() even if accessibility is not
    active. But there will be no notifications sent to the platform.

    It is recommended to use this function to prevent expensive notifications
    via updateAccessibility() when they are not needed.
*/
bool QAccessible::isActive()
{
    if (QPlatformAccessibility *pfAccessibility = platformAccessibility())
        return pfAccessibility->isActive();
    return false;
}

/*!
    \internal
*/
void QAccessible::setActive(bool active)
{
    for (int i = 0; i < qAccessibleActivationObservers()->size() ;++i)
        qAccessibleActivationObservers()->at(i)->accessibilityActiveChanged(active);
}


/*!
  Sets the root object of the accessible objects of this application
  to \a object.  All other accessible objects are reachable using object
  navigation from the root object.

  Normally, it isn't necessary to call this function, because Qt sets
  the QApplication object as the root object immediately before the
  event loop is entered in QApplication::exec().

  Use QAccessible::installRootObjectHandler() to redirect the function
  call to a customized handler function.

  \sa queryAccessibleInterface()
*/
void QAccessible::setRootObject(QObject *object)
{
    if (rootObjectHandler) {
        rootObjectHandler(object);
        return;
    }

    if (QPlatformAccessibility *pfAccessibility = platformAccessibility())
        pfAccessibility->setRootObject(object);
}

/*!
  Notifies about a change that might be relevant for accessibility clients.

  \a event provides details about the change. These include the source
  of the change and the nature of the change.  The \a event should
  contain enough information give meaningful notifications.

  For example, the type \c ValueChange indicates that the position of
  a slider has been changed.

  Call this function whenever the state of your accessible object or
  one of its sub-elements has been changed either programmatically
  (e.g. by calling QLabel::setText()) or by user interaction.

  If there are no accessibility tools listening to this event, the
  performance penalty for calling this function is small, but if
  determining the parameters of the call is expensive you can test
  QAccessible::isActive() to avoid unnecessary computation.
*/
void QAccessible::updateAccessibility(QAccessibleEvent *event)
{
    // NOTE: Querying for the accessibleInterface below will result in
    // resolving and caching the interface, which in some cases will
    // cache the wrong information as updateAccessibility is called
    // during construction of widgets. If you see cases where the
    // cache seems wrong, this call is "to blame", but the code that
    // caches dynamic data should be updated to handle change events.
    QAccessibleInterface *iface = event->accessibleInterface();
    if (isActive() && iface) {
        if (event->type() == QAccessible::TableModelChanged) {
            if (iface->tableInterface())
                iface->tableInterface()->modelChange(static_cast<QAccessibleTableModelChangeEvent*>(event));
        }
    }

    if (updateHandler) {
        updateHandler(event);
        return;
    }

    if (QPlatformAccessibility *pfAccessibility = platformAccessibility())
        pfAccessibility->notifyAccessibilityUpdate(event);
}

/*!
    \internal
    \brief getBoundaries is a helper function to find the accessible text boundaries for QTextCursor based documents.
    \param documentCursor a valid cursor bound to the document (not null). It needs to ba at the position to look for the boundary
    \param boundaryType the type of boundary to find
    \return the boundaries as pair
*/
std::pair< int, int > QAccessible::qAccessibleTextBoundaryHelper(const QTextCursor &offsetCursor, TextBoundaryType boundaryType)
{
    Q_ASSERT(!offsetCursor.isNull());

    QTextCursor endCursor = offsetCursor;
    endCursor.movePosition(QTextCursor::End);
    int characterCount = endCursor.position();

    std::pair<int, int> result;
    QTextCursor cursor = offsetCursor;
    switch (boundaryType) {
    case CharBoundary:
        result.first = cursor.position();
        cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
        result.second = cursor.position();
        break;
    case WordBoundary:
        cursor.movePosition(QTextCursor::StartOfWord, QTextCursor::MoveAnchor);
        result.first = cursor.position();
        cursor.movePosition(QTextCursor::EndOfWord, QTextCursor::KeepAnchor);
        result.second = cursor.position();
        break;
    case SentenceBoundary: {
        // QCursor does not provide functionality to move to next sentence.
        // We therefore find the current block, then go through the block using
        // QTextBoundaryFinder and find the sentence the \offset represents
        cursor.movePosition(QTextCursor::StartOfBlock, QTextCursor::MoveAnchor);
        result.first = cursor.position();
        cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
        result.second = cursor.position();
        QString blockText = cursor.selectedText();
        const int offsetWithinBlockText = offsetCursor.position() - result.first;
        QTextBoundaryFinder sentenceFinder(QTextBoundaryFinder::Sentence, blockText);
        sentenceFinder.setPosition(offsetWithinBlockText);
        int prevBoundary = offsetWithinBlockText;
        int nextBoundary = offsetWithinBlockText;
        if (!(sentenceFinder.boundaryReasons() & QTextBoundaryFinder::StartOfItem))
            prevBoundary = sentenceFinder.toPreviousBoundary();
        nextBoundary = sentenceFinder.toNextBoundary();
        if (nextBoundary != -1)
            result.second = result.first + nextBoundary;
        if (prevBoundary != -1)
            result.first += prevBoundary;
        break; }
    case LineBoundary:
        cursor.movePosition(QTextCursor::StartOfLine, QTextCursor::MoveAnchor);
        result.first = cursor.position();
        cursor.movePosition(QTextCursor::EndOfLine, QTextCursor::KeepAnchor);
        result.second = cursor.position();
        break;
    case ParagraphBoundary:
        cursor.movePosition(QTextCursor::StartOfBlock, QTextCursor::MoveAnchor);
        result.first = cursor.position();
        cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
        result.second = cursor.position();
        break;
    case NoBoundary:
        result.first = 0;
        result.second = characterCount;
        break;
    }
    return result;
}

/*!
    \class QAccessibleInterface
    \brief The QAccessibleInterface class defines an interface that exposes information
    about accessible objects.

    \ingroup accessibility
    \inmodule QtGui

    This class is part of \l {Accessibility for QWidget Applications}.

    Accessibility tools (also called AT Clients), such as screen readers
    or braille displays, require high-level information about
    accessible objects in an application. Accessible objects provide
    specialized input and output methods, making it possible for users
    to use accessibility tools with enabled applications (AT Servers).

    Every element that the user needs to interact with or react to is
    an accessible object, and should provide this information. These
    are mainly visual objects, such as widgets and widget elements, but
    can also be content, such as sounds.

    The AT client uses three basic concepts to acquire information
    about any accessible object in an application:
    \list
    \li \e Properties The client can read information about
    accessible objects. In some cases the client can also modify these
    properties; such as text in a line edit.
    \li \e Actions The client can invoke actions like pressing a button
    or .
    \li \e{Relationships and Navigation} The client can traverse from one
    accessible object to another, using the relationships between objects.
    \endlist

    The QAccessibleInterface defines the API for these three concepts.

    \section1 Relationships and Navigation

    The functions childCount() and indexOfChild() return the number of
    children of an accessible object and the index a child object has
    in its parent. The childAt() function returns a child QAccessibleInterface
    that is found at a position. The child does not have to be a direct
    child. This allows bypassing intermediate layers when the parent already knows the
    top-most child. childAt() is used for hit testing (finding the object
    under the mouse).

    The relations() function provides information about the relations an
    object has to other objects, and parent() and child() allows
    traversing from one object to another object.

    \section1 Properties

    The central property of an accessible objects is what role() it
    has. Different objects can have the same role, e.g. both the "Add
    line" element in a scroll bar and the \c OK button in a dialog have
    the same role, "button". The role implies what kind of
    interaction the user can perform with the user interface element.

    An object's state() property is a combination of different state
    flags and can describe both how the object's state differs from a
    "normal" state, e.g. it might be unavailable, and also how it
    behaves, e.g. it might be selectable.

    The text() property provides textual information about the object.
    An object usually has a name, but can provide extended information
    such as a description, help text, or information about any
    keyboard accelerators it provides. Some objects allow changing the
    text() property through the setText() function, but this
    information is in most cases read-only.

    The rect() property provides information about the geometry of an
    accessible object. This information is usually only available for
    visual objects.

    \section1 Interfaces

    To enable the user to interact with an accessible object the
    object must implement QAccessibleActionInterface in addition to
    QAccessibleInterface.
    Objects that support selections can define actions to change the selection.

    There are several other interfaces that should be implemented as required.
    QAccessibleTextInterface should be used for bigger texts edits such as document views.
    This interface should not be implemented for labels/single line edits.

    For sliders, scrollbars and other numerical value selectors QAccessibleValueInterface
    should be implemented.

    Lists, tables and trees should implement QAccessibleTableInterface.

    \sa QAccessible, QAccessibleActionInterface, QAccessibleTextInterface, QAccessibleValueInterface, QAccessibleTableInterface
*/

/*!
    \fn bool QAccessibleInterface::isValid() const

    Returns \c true if all the data necessary to use this interface
    implementation is valid (e.g. all pointers are non-null);
    otherwise returns \c false.

    \sa object()
*/

/*!
    \fn QObject *QAccessibleInterface::object() const

    Returns a pointer to the QObject this interface implementation provides
    information for.

    \sa isValid()
*/

/*!
    \fn int QAccessibleInterface::childCount() const

    Returns the number of children that belong to this object. A child
    can provide accessibility information on its own (e.g. a child
    widget), or be a sub-element of this accessible object.

    All objects provide this information.

    \sa indexOfChild()
*/

/*!
    \fn int QAccessibleInterface::indexOfChild(const QAccessibleInterface *child) const

    Returns the 0-based index of the object \a child in this object's
    children list, or -1 if \a child is not a child of this object.

    All objects provide this information about their children.

    \sa childCount()
*/

/*!
    Returns the meaningful relations to other widgets. Usually this will not return parent/child
    relations, unless they are handled in a specific way such as in tree views.
    It will typically return the labelled-by and label relations.

    It is possible to filter the relations by using the optional parameter \a match.
    It should never return itself.

    \sa parent(), child()
*/
QList<std::pair<QAccessibleInterface*, QAccessible::Relation>>
QAccessibleInterface::relations(QAccessible::Relation match) const
{
    Q_UNUSED(match);
    return { };
}

/*!
    Returns the object that has the keyboard focus.

    The object returned can be any descendant, including itself.
*/
QAccessibleInterface *QAccessibleInterface::focusChild() const
{
    return nullptr;
}

/*!
    \fn QAccessibleInterface *QAccessibleInterface::childAt(int x, int y) const

    Returns the QAccessibleInterface of a child that contains the screen coordinates (\a x, \a y).
    If there are no children at this position this function returns \nullptr.
    The returned accessible must be a child, but not necessarily a direct child.

    This function is only reliable for visible objects (invisible
    object might not be laid out correctly).

    All visual objects provide this information.

    A default implementation is provided for objects inheriting QAccessibleObject. This will iterate
    over all children. If the widget manages its children (e.g. a table) it will be more efficient
    to write a specialized implementation.

    \sa rect()
*/

/*!
    \fn QAccessibleInterface* QAccessibleInterface::parent() const

    Returns the QAccessibleInterface of the parent in the accessible object hierarchy.

    Returns \nullptr if no parent exists (e.g. for the top level application object).

    \sa child()
*/

/*!
    \fn QAccessibleInterface* QAccessibleInterface::child(int index) const

    Returns the accessible child with index \a index.
    0-based index. The number of children of an object can be checked with childCount.

    Returns \nullptr when asking for an invalid child (e.g. when the child became invalid in the meantime).

    \sa childCount(), parent()
*/

/*!
    \fn QString QAccessibleInterface::text(QAccessible::Text t) const

    Returns the value of the text property \a t of the object.

    The \l QAccessible::Name is a string used by clients to identify, find, or
    announce an accessible object for the user. All objects must have
    a name that is unique within their container. The name can be
    used differently by clients, so the name should both give a
    short description of the object and be unique.

    An accessible object's \l QAccessible::Description provides textual information
    about an object's visual appearance. The description is primarily
    used to provide greater context for vision-impaired users, but is
    also used for context searching or other applications. Not all
    objects have a description. An "OK" button would not need a
    description, but a tool button that shows a picture of a smiley
    would.

    The \l QAccessible::Value of an accessible object represents visual information
    contained by the object, e.g. the text in a line edit. Usually,
    the value can be modified by the user. Not all objects have a
    value, e.g. static text labels don't, and some objects have a
    state that already is the value, e.g. toggle buttons.

    The \l QAccessible::Help text provides information about the function and
    usage of an accessible object. Not all objects provide this
    information.

    The \l QAccessible::Accelerator is a keyboard shortcut that activates the
    object's default action. A keyboard shortcut is the underlined
    character in the text of a menu, menu item or widget, and is
    either the character itself, or a combination of this character
    and a modifier key like Alt, Ctrl or Shift. Command controls like
    tool buttons also have shortcut keys and usually display them in
    their tooltip.

    The \l QAccessible::Identifier can be explicitly set to provide an
    ID to assistive technologies. This can be especially useful for UI tests.
    If no identifier has been explicitly set, the identifier is set by the
    respective interface to an ID based on \l QObject::objectName or its
    class name and \l QObject::objectName or class name of the parents
    in its parents chain.

    All objects provide a string for \l QAccessible::Name.

    \sa role(), state()
*/

/*!
    \fn void QAccessibleInterface::setText(QAccessible::Text t, const QString &text)

    Sets the text property \a t of the object to \a text.

    Note that the text properties of most objects are read-only
    so calling this function might have no effect.

    \sa text()
*/

/*!
    \fn QRect QAccessibleInterface::rect() const

    Returns the geometry of the object. The geometry is in screen coordinates.

    This function is only reliable for visible objects (invisible
    objects might not be laid out correctly).

    All visual objects provide this information.

    \sa childAt()
*/

/*!
    \fn QAccessible::Role QAccessibleInterface::role() const

    Returns the role of the object.
    The role of an object is usually static.

    All accessible objects have a role.

    \sa text(), state()
*/

/*!
    \fn QAccessible::State QAccessibleInterface::state() const

    Returns the current state of the object.
    The returned value is a combination of the flags in
    the QAccessible::StateFlag enumeration.

    All accessible objects have a state.

    \sa text(), role()
*/

/*!
    Returns the accessible's foreground color if applicable or an invalid QColor.

    \sa backgroundColor()
*/
QColor QAccessibleInterface::foregroundColor() const
{
    return QColor();
}

/*!
    Returns the accessible's background color if applicable or an invalid QColor.

    \sa foregroundColor()
*/
QColor QAccessibleInterface::backgroundColor() const
{
    return QColor();
}

/*!
    \fn QAccessibleTextInterface *QAccessibleInterface::textInterface()
*/

/*!
    \fn QAccessibleTextInterface *QAccessibleInterface::editableTextInterface()
    \internal
*/

/*!
    \fn QAccessibleValueInterface *QAccessibleInterface::valueInterface()
*/

/*!
    \fn QAccessibleTableInterface *QAccessibleInterface::tableInterface()
*/

/*!
    \fn QAccessibleTableCellInterface *QAccessibleInterface::tableCellInterface()
*/

/*!
    \fn QAccessibleActionInterface *QAccessibleInterface::actionInterface()
*/

/*!
    \fn QAccessibleImageInterface *QAccessibleInterface::imageInterface()
    \internal
*/

/*!
    \fn QAccessibleSelectionInterface *QAccessibleInterface::selectionInterface()
    \since 6.5
*/

/*!
    \class QAccessibleEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleEvent class is the base class for accessibility notifications.

    This class is used with \l QAccessible::updateAccessibility().

    The event type is one of the values of \l QAccessible::Event.
    There are a number of subclasses that should be used to provide more details about the
    event.

    For example to notify about a focus change when re-implementing QWidget::setFocus,
    the event could be used as follows:
    \snippet code/src_gui_accessible_qaccessible.cpp 2

    To enable in process screen readers, all events must be sent after the change has happened.
*/

/*! \fn QAccessibleEvent::QAccessibleEvent(QObject *object, QAccessible::Event type)

    Constructs a QAccessibleEvent to notify that \a object has changed.
    The event \a type describes what changed.
*/

/*! \fn QAccessibleEvent::QAccessibleEvent(QAccessibleInterface *interface, QAccessible::Event type)

    Constructs a QAccessibleEvent to notify that \a interface has changed.
    The event \a type describes what changed.
    Use this function if you already have a QAccessibleInterface or no QObject, otherwise consider
    the overload taking a \l QObject parameter as it might be cheaper.
*/

/*!
  Destroys the event.
*/
QAccessibleEvent::~QAccessibleEvent()
{
}

/*! \fn QAccessible::Event QAccessibleEvent::type() const
  Returns the event type.
*/

/*! \fn QObject* QAccessibleEvent::object() const
  Returns the event object.
*/

/*! \fn void QAccessibleEvent::setChild(int child)
  Sets the child index to \a child.
*/

/*! \fn int QAccessibleEvent::child() const
  Returns the child index.
*/

/*!
    \internal
    Returns the uniqueId of the QAccessibleInterface represented by this event.

    In case the object() function returns \nullptr, this is the only way to access the
    interface.
*/
QAccessible::Id QAccessibleEvent::uniqueId() const
{
    if (!m_object)
        return m_uniqueId;
    QAccessibleInterface *iface = QAccessible::queryAccessibleInterface(m_object);
    if (!iface)
        return 0;
    if (m_child != -1) {
        iface = iface->child(m_child);
        if (Q_UNLIKELY(!iface)) {
            qCWarning(lcAccessibilityCore) << "Invalid child in QAccessibleEvent:" << m_object << "child:" << m_child;
            return 0;
        }
    }
    return QAccessible::uniqueId(iface);
}

/*!
    \class QAccessibleValueChangeEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleValueChangeEvent describes a change in value for an accessible object.

    It contains the new value.

    This class is used with \l QAccessible::updateAccessibility().
*/

/*! \fn QAccessibleValueChangeEvent::QAccessibleValueChangeEvent(QObject *object, const QVariant &value)

    Constructs a new QAccessibleValueChangeEvent for \a object.
    The event contains the new \a value.
*/
/*! \fn QAccessibleValueChangeEvent::QAccessibleValueChangeEvent(QAccessibleInterface *iface, const QVariant &val)

    Constructs a new QAccessibleValueChangeEvent for \a iface.
    The event contains the new value \a val.
*/

/*! \fn void QAccessibleValueChangeEvent::setValue(const QVariant & value)

    Sets the new \a value for this event.
*/
/*!
    \fn QVariant QAccessibleValueChangeEvent::value() const

    Returns the new value of the accessible object of this event.
*/
/*!
    \internal
*/
QAccessibleValueChangeEvent::~QAccessibleValueChangeEvent()
{
}

/*!
    \class QAccessibleStateChangeEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleStateChangeEvent notfies the accessibility framework
    that the state of an object has changed.

    This class is used with \l QAccessible::updateAccessibility().

    \sa QAccessibleInterface::state()
*/
/*! \fn QAccessibleStateChangeEvent::QAccessibleStateChangeEvent(QObject *object, QAccessible::State state)

    Constructs a new QAccessibleStateChangeEvent for \a object.
    The difference to the object's previous state is in \a state.
*/
/*!
    \fn QAccessibleStateChangeEvent::QAccessibleStateChangeEvent(QAccessibleInterface *iface, QAccessible::State state)

    Constructs a new QAccessibleStateChangeEvent.
    \a iface is the interface associated with the event
    \a state is the state of the accessible object.
*/
/*!
    \fn QAccessible::State QAccessibleStateChangeEvent::changedStates() const
    \brief Returns the states that have been changed.

    Keep in mind that the returned states are the ones that have changed.
    To find out about the state of an object, use QAccessibleInterface::state().

    For example, if an object used to have the focus but loses it,
    the object's state will have focused set to \c false. This event on the
    other hand tells about the change and has focused set to \c true since
    the focus state is changed from \c true to \c false.
*/
/*!
    \internal
*/
QAccessibleStateChangeEvent::~QAccessibleStateChangeEvent()
{
}

/*!
    \class QAccessibleTableModelChangeEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleTableModelChangeEvent signifies a change in a table, list, or tree where cells
    are added or removed.
    If the change affected a number of rows, firstColumn and lastColumn will return -1.
    Likewise for columns, the row functions may return -1.

    This class is used with \l QAccessible::updateAccessibility().
*/

/*! \enum QAccessibleTableModelChangeEvent::ModelChangeType
    This enum describes the different types of changes in the table model.
    \value ModelReset      The model has been reset, all previous knowledge about the model is now invalid.
    \value DataChanged     No cells have been added or removed, but the data of the specified cell range is invalid.
    \value RowsInserted    New rows have been inserted.
    \value ColumnsInserted New columns have been inserted.
    \value RowsRemoved     Rows have been removed.
    \value ColumnsRemoved  Columns have been removed.
*/
/*! \fn QAccessibleTableModelChangeEvent::QAccessibleTableModelChangeEvent(QObject *object, ModelChangeType changeType)

    Constructs a new QAccessibleTableModelChangeEvent for \a object of with \a changeType.
*/
/*! \fn int QAccessibleTableModelChangeEvent::firstColumn() const

    Returns the first changed column.
*/
/*! \fn int QAccessibleTableModelChangeEvent::firstRow() const

    Returns the first changed row.
*/
/*! \fn int QAccessibleTableModelChangeEvent::lastColumn() const

    Returns the last changed column.
*/
/*! \fn int QAccessibleTableModelChangeEvent::lastRow() const

    Returns the last changed row.
*/
/*! \fn QAccessibleTableModelChangeEvent::ModelChangeType QAccessibleTableModelChangeEvent::modelChangeType() const

    Returns the type of change.
*/
/*! \fn void QAccessibleTableModelChangeEvent::setFirstColumn(int column)

    Sets the first changed \a column.
*/
/*! \fn void QAccessibleTableModelChangeEvent::setFirstRow(int row)

    Sets the first changed \a row.
*/
/*! \fn void QAccessibleTableModelChangeEvent::setLastColumn(int column)

    Sets the last changed \a column.
*/
/*! \fn void QAccessibleTableModelChangeEvent::setLastRow(int row)

    Sets the last changed \a row.
*/
/*! \fn void QAccessibleTableModelChangeEvent::setModelChangeType(ModelChangeType changeType)

    Sets the type of change to \a changeType.
*/
/*!
    \fn QAccessibleTableModelChangeEvent::QAccessibleTableModelChangeEvent(QAccessibleInterface *iface, ModelChangeType changeType)

    Constructs a new QAccessibleTableModelChangeEvent for interface \a iface with a model
    change type \a changeType.
*/
/*!
    \internal
*/
QAccessibleTableModelChangeEvent::~QAccessibleTableModelChangeEvent()
{
}
/*!
    \class QAccessibleTextCursorEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleTextCursorEvent class notifies of cursor movements.

    This class is used with \l QAccessible::updateAccessibility().
*/
/*! \fn QAccessibleTextCursorEvent::QAccessibleTextCursorEvent(QObject *object, int cursorPos)

    Create a new QAccessibleTextCursorEvent for \a object.
    The \a cursorPos is the new cursor position.
*/
/*! \fn int QAccessibleTextCursorEvent::cursorPosition() const

    Returns the cursor position.
*/
/*! \fn void QAccessibleTextCursorEvent::setCursorPosition(int position)

    Sets the cursor \a position for this event.
*/
/*!
    \internal
*/
QAccessibleTextCursorEvent::~QAccessibleTextCursorEvent()
{
}


/*!
    \fn QAccessibleTextCursorEvent::QAccessibleTextCursorEvent(QAccessibleInterface *iface, int cursorPos)

    Create a new QAccessibleTextCursorEvent for \a iface,
    The \a cursorPos is the new cursor position.
*/

/*!
    \class QAccessibleTextInsertEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleTextInsertEvent class notifies of text being inserted.

    This class is used with \l QAccessible::updateAccessibility().
*/
/*! \fn QAccessibleTextInsertEvent::QAccessibleTextInsertEvent(QObject *object, int position, const QString &text)

    Constructs a new QAccessibleTextInsertEvent event for \a object.
    The \a text has been inserted at \a position.
    By default, it is assumed that the cursor has moved to the end
    of the selection. If that is not the case, one needs to manually
    set it with \l QAccessibleTextCursorEvent::setCursorPosition() for this event.
*/
/*! \fn int QAccessibleTextInsertEvent::changePosition() const

    Returns the position where the text was inserted.
*/
/*! \fn QString QAccessibleTextInsertEvent::textInserted() const

    Returns the text that has been inserted.
*/
/*!
    \internal
*/
QAccessibleTextInsertEvent::~QAccessibleTextInsertEvent()
{
}


/*!
    \class QAccessibleTextRemoveEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleTextRemoveEvent class notifies of text being deleted.

    This class is used with \l QAccessible::updateAccessibility().
*/
/*! \fn QAccessibleTextRemoveEvent::QAccessibleTextRemoveEvent(QObject *object, int position, const QString &text)

    Constructs a new QAccessibleTextRemoveEvent event for \a object.
    The \a text has been removed at \a position.
    By default it is assumed that the cursor has moved to \a position.
    If that is not the case, one needs to manually
    set it with \l QAccessibleTextCursorEvent::setCursorPosition() for this event.
*/
/*! \fn QAccessibleTextRemoveEvent::QAccessibleTextRemoveEvent(QAccessibleInterface *iface, int position, const QString &text)

    Constructs a new QAccessibleTextRemoveEvent event for \a iface.
    The \a text has been removed at \a position.
    By default it is assumed that the cursor has moved to \a position.
    If that is not the case, one needs to manually
    set it with \l QAccessibleTextCursorEvent::setCursorPosition() for this event.
*/

/*! \fn int QAccessibleTextRemoveEvent::changePosition() const

    Returns the position where the text was removed.
*/
/*! \fn QString QAccessibleTextRemoveEvent::textRemoved() const

    Returns the text that has been removed.
*/
/*!
    \internal
*/
QAccessibleTextRemoveEvent::~QAccessibleTextRemoveEvent()
{
}

/*!
   \fn QAccessibleTextSelectionEvent::QAccessibleTextSelectionEvent(QAccessibleInterface *iface, int start, int end)

   Constructs a new QAccessibleTextSelectionEvent for \a iface. The new selection this
   event notifies about is from position \a start to \a end.
*/

/*!
     \fn QAccessibleTextInsertEvent::QAccessibleTextInsertEvent(QAccessibleInterface *iface, int position, const QString &text)

     Constructs a new QAccessibleTextInsertEvent event for \a iface. The \a text has been inserted
     at \a position.
*/

/*!
     \fn inline QAccessibleTextUpdateEvent::QAccessibleTextUpdateEvent(QAccessibleInterface *iface, int position, const QString &oldText,
         const QString &text)

     Constructs a new QAccessibleTextUpdateEvent for \a iface. The text change takes place at
     \a position where the \a oldText was removed and \a text inserted instead.

*/



/*!
    \class QAccessibleTextUpdateEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleTextUpdateEvent class notifies about text changes.
    This is for accessibles that support editable text such as line edits.
    This event occurs for example when a portion of selected text
    gets replaced by pasting a new text or in override mode of editors.

    This class is used with \l QAccessible::updateAccessibility().
*/
/*! \fn QAccessibleTextUpdateEvent::QAccessibleTextUpdateEvent(QObject *object, int position, const QString &oldText, const QString &text)

    Constructs a new QAccessibleTextUpdateEvent for \a object.
    The text change takes place at \a position where the \a oldText was removed and \a text inserted instead.
*/
/*! \fn int QAccessibleTextUpdateEvent::changePosition() const

    Returns where the change took place.
*/
/*! \fn QString QAccessibleTextUpdateEvent::textInserted() const

    Returns the inserted text.
*/
/*! \fn QString QAccessibleTextUpdateEvent::textRemoved() const

    Returns the removed text.
*/
/*!
    \internal
*/
QAccessibleTextUpdateEvent::~QAccessibleTextUpdateEvent()
{
}


/*!
    \class QAccessibleTextSelectionEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief QAccessibleTextSelectionEvent signals a change in the text selection of an object.

    This class is used with \l QAccessible::updateAccessibility().
*/
/*! \fn QAccessibleTextSelectionEvent::QAccessibleTextSelectionEvent(QObject *object, int start, int end)

    Constructs a new QAccessibleTextSelectionEvent for \a object.
    The new selection this event notifies about is from position \a start to \a end.
*/
/*! \fn int QAccessibleTextSelectionEvent::selectionEnd() const

    Returns the position of the last selected character.
*/
/*! \fn int QAccessibleTextSelectionEvent::selectionStart() const

    Returns the position of the first selected character.
*/
/*! \fn void QAccessibleTextSelectionEvent::setSelection(int start, int end)

    Sets the selection for this event from position \a start to \a end.
*/
/*!
    \internal
*/
QAccessibleTextSelectionEvent::~QAccessibleTextSelectionEvent()
{
}

/*!
    \since 6.8
    \class QAccessibleAnnouncementEvent
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleAnnouncementEvent is used to request the announcement
    of a given message by assistive technologies.

    This class is used with \l QAccessible::updateAccessibility().
*/

/*! \fn QAccessibleAnnouncementEvent::QAccessibleAnnouncementEvent(QObject *object, const QString &message)

    Constructs a new QAccessibleAnnouncementEvent event for \a object
    to request the announcement of \a message with politeness
    \l QAccessible::AnnouncementPoliteness::Polite.

    \l QAccessibleAnnouncementEvent::setPoliteness can be used to adjust the politeness.
*/

/*! \fn QAccessibleAnnouncementEvent::QAccessibleAnnouncementEvent(QAccessibleInterface *iface, const QString &message)

    Constructs a new QAccessibleAnnouncementEvent event for \a iface
    to request the announcement of \a message with politeness
    \l QAccessible::AnnouncementPoliteness::Polite.

    \l QAccessibleAnnouncementEvent::setPoliteness can be used to adjust the politeness.
*/

/*! \fn QString QAccessibleAnnouncementEvent::message() const

    Returns the message.
*/

/*! \fn QAccessible::AnnouncementPoliteness QAccessibleAnnouncementEvent::politeness() const

    Returns the politeness.
*/

/*! \fn void QAccessibleAnnouncementEvent::setPoliteness(QAccessible::AnnouncementPoliteness politeness)

    Sets the politeness with which the announcement will be requested to \a politeness.
*/


/*!
    \internal
*/
QAccessibleAnnouncementEvent::~QAccessibleAnnouncementEvent()
{
}

/*!
    Returns the QAccessibleInterface associated with the event.
*/
QAccessibleInterface *QAccessibleEvent::accessibleInterface() const
{
    if (m_object == nullptr)
        return QAccessible::accessibleInterface(m_uniqueId);

    QAccessibleInterface *iface = QAccessible::queryAccessibleInterface(m_object);
    if (!iface || !iface->isValid())
        return nullptr;

    if (m_child >= 0) {
        QAccessibleInterface *child = iface->child(m_child);
        if (child) {
            iface = child;
        } else {
            qCWarning(lcAccessibilityCore) << "Cannot create accessible child interface for object: " << m_object << " index: " << m_child;
        }
    }
    return iface;
}

/*!
    Returns the window associated with the underlying object.
    For instance, QAccessibleWidget reimplements this and returns
    the windowHandle() of the QWidget.

    It is used on some platforms to be able to notify the AT client about
    state changes.
    The backend will traverse up all ancestors until it finds a window.
    (This means that at least one interface among the ancestors should
    return a valid QWindow pointer).

    The default implementation returns \nullptr.
  */
QWindow *QAccessibleInterface::window() const
{
    return nullptr;
}

/*!
    \internal
    Method to allow extending this class without breaking binary compatibility.
    The actual behavior and format of \a data depends on \a id argument
    which must be defined if the class is to be extended with another virtual
    function.
    Currently, this is unused.
*/
void QAccessibleInterface::virtual_hook(int /*id*/, void * /*data*/)
{
}

/*!
    \fn void *QAccessibleInterface::interface_cast(QAccessible::InterfaceType type)

    Returns a specialized accessibility interface \a type from the
    generic QAccessibleInterface.

    This function must be reimplemented when providing more
    information about a widget or object through the specialized
    interfaces. For example a line edit should implement the
    QAccessibleTextInterface.

    \sa QAccessible::InterfaceType, QAccessibleTextInterface,
    QAccessibleValueInterface, QAccessibleActionInterface,
    QAccessibleTableInterface, QAccessibleTableCellInterface
*/

/*! \internal */
const char *qAccessibleRoleString(QAccessible::Role role)
{
    if (role >= QAccessible::UserRole)
         role = QAccessible::UserRole;
    static int roleEnum = QAccessible::staticMetaObject.indexOfEnumerator("Role");
    return QAccessible::staticMetaObject.enumerator(roleEnum).valueToKey(role);
}

/*! \internal */
const char *qAccessibleEventString(QAccessible::Event event)
{
    static int eventEnum = QAccessible::staticMetaObject.indexOfEnumerator("Event");
    return QAccessible::staticMetaObject.enumerator(eventEnum).valueToKey(event);
}

#ifndef QT_NO_DEBUG_STREAM
/*! \internal */
Q_GUI_EXPORT QDebug operator<<(QDebug d, const QAccessibleInterface *iface)
{
    QDebugStateSaver saver(d);
    if (!iface) {
        d << "QAccessibleInterface(null)";
        return d;
    }
    d.nospace();
    d << "QAccessibleInterface(" << Qt::hex << (const void *) iface << Qt::dec;
    if (iface->isValid()) {
        d << " name=" << iface->text(QAccessible::Name) << ' ';
        d << "role=" << qAccessibleRoleString(iface->role()) << ' ';
        if (iface->childCount())
            d << "childc=" << iface->childCount() << ' ';
        if (iface->object()) {
            d << "obj=" << iface->object();
        }
        QStringList stateStrings;
        QAccessible::State st = iface->state();
        if (st.focusable)
            stateStrings << u"focusable"_s;
        if (st.focused)
            stateStrings << u"focused"_s;
        if (st.selected)
            stateStrings << u"selected"_s;
        if (st.invisible)
            stateStrings << u"invisible"_s;

        if (!stateStrings.isEmpty())
            d << stateStrings.join(u'|');

        if (!st.invisible)
            d << "rect=" << iface->rect();

    } else {
        d << " invalid";
    }
    d << ')';
    return d;
}

/*! \internal */
QDebug operator<<(QDebug d, const QAccessibleEvent &ev)
{
    QDebugStateSaver saver(d);
    d.nospace() << "QAccessibleEvent(";
    if (ev.object()) {
        d.nospace() << "object=" << Qt::hex << ev.object() << Qt::dec;
        d.nospace() << "child=" << ev.child();
    } else {
        d.nospace() << "no object, uniqueId=" << ev.uniqueId();
    }
    d << " event=" << qAccessibleEventString(ev.type());
    if (ev.type() == QAccessible::StateChanged) {
        QAccessible::State changed = static_cast<const QAccessibleStateChangeEvent*>(&ev)->changedStates();
        d << "State changed:";
        if (changed.disabled) d << "disabled";
        if (changed.selected) d << "selected";
        if (changed.focusable) d << "focusable";
        if (changed.focused) d << "focused";
        if (changed.pressed) d << "pressed";
        if (changed.checkable) d << "checkable";
        if (changed.checked) d << "checked";
        if (changed.checkStateMixed) d << "checkStateMixed";
        if (changed.readOnly) d << "readOnly";
        if (changed.hotTracked) d << "hotTracked";
        if (changed.defaultButton) d << "defaultButton";
        if (changed.expanded) d << "expanded";
        if (changed.collapsed) d << "collapsed";
        if (changed.busy) d << "busy";
        if (changed.expandable) d << "expandable";
        if (changed.marqueed) d << "marqueed";
        if (changed.animated) d << "animated";
        if (changed.invisible) d << "invisible";
        if (changed.offscreen) d << "offscreen";
        if (changed.sizeable) d << "sizeable";
        if (changed.movable) d << "movable";
        if (changed.selfVoicing) d << "selfVoicing";
        if (changed.selectable) d << "selectable";
        if (changed.linked) d << "linked";
        if (changed.traversed) d << "traversed";
        if (changed.multiSelectable) d << "multiSelectable";
        if (changed.extSelectable) d << "extSelectable";
        if (changed.passwordEdit) d << "passwordEdit"; // used to be Protected
        if (changed.hasPopup) d << "hasPopup";
        if (changed.modal) d << "modal";

        // IA2 - we chose to not add some IA2 states for now
        // Below the ones that seem helpful
        if (changed.active) d << "active";
        if (changed.invalid) d << "invalid"; // = defunct
        if (changed.editable) d << "editable";
        if (changed.multiLine) d << "multiLine";
        if (changed.selectableText) d << "selectableText";
        if (changed.supportsAutoCompletion) d << "supportsAutoCompletion";

    }
    d << ')';
    return d;
}
#endif // QT_NO_DEBUGSTREAM

/*!
    \class QAccessibleTextInterface
    \inmodule QtGui

    \ingroup accessibility

    \brief The QAccessibleTextInterface class implements support for text handling.

    This interface corresponds to the IAccessibleText interface.
    It should be implemented for widgets that display more text than a plain label.
    Labels should be represented by only \l QAccessibleInterface
    and return their text as name (\l QAccessibleInterface::text() with \l QAccessible::Name as type).
    The QAccessibleTextInterface is typically for text that a screen reader
    might want to read line by line, and for widgets that support text selection and input.
    This interface is, for example, implemented for QLineEdit.

    \l{IAccessible2 Specification}
*/

/*!

    Destroys the QAccessibleTextInterface.
*/
QAccessibleTextInterface::~QAccessibleTextInterface()
{
}

/*!
    \fn void QAccessibleTextInterface::addSelection(int startOffset, int endOffset)

    Select the text from \a startOffset to \a endOffset.
    The \a startOffset is the first character that will be selected.
    The \a endOffset is the first character that will not be selected.

    When the object supports multiple selections (e.g. in a word processor),
    this adds a new selection, otherwise it replaces the previous selection.

    The selection will be \a endOffset - \a startOffset characters long.
*/

/*!
    \fn QString QAccessibleTextInterface::attributes(int offset, int *startOffset, int *endOffset) const

    Returns the text attributes at the position \a offset.
    In addition the range of the attributes is returned in \a startOffset and \a endOffset.
*/

/*!
    \fn int QAccessibleTextInterface::cursorPosition() const

    Returns the current cursor position.
*/

/*!
    \fn QRect QAccessibleTextInterface::characterRect(int offset) const

    Returns the position and size of the character at position \a offset in screen coordinates.
*/

/*!
    \fn int QAccessibleTextInterface::selectionCount() const

    Returns the number of selections in this text.
*/

/*!
    \fn int QAccessibleTextInterface::offsetAtPoint(const QPoint &point) const

    Returns the offset of the character at the \a point in screen coordinates.
*/

/*!
    \fn void QAccessibleTextInterface::selection(int selectionIndex, int *startOffset, int *endOffset) const

    Returns a selection. The size of the selection is returned in \a startOffset and \a endOffset.
    If there is no selection both \a startOffset and \a endOffset are \nullptr.

    The accessibility APIs support multiple selections. For most widgets though, only one selection
    is supported with \a selectionIndex equal to 0.
*/

/*!
    \fn QString QAccessibleTextInterface::text(int startOffset, int endOffset) const

    Returns the text from \a startOffset to \a endOffset.
    The \a startOffset is the first character that will be returned.
    The \a endOffset is the first character that will not be returned.
*/

/*!
    \internal
    Helper for finding line breaks in textBeforeOffset/textAtOffset/textAfterOffset.
    \a beforeAtAfter is the line we look for. -1 for before, 0 for at and 1 for after.
*/
static QString textLineBoundary(int beforeAtAfter, const QString &text, int offset, int *startOffset, int *endOffset)
{
    Q_ASSERT(beforeAtAfter >= -1 && beforeAtAfter <= 1);
    Q_ASSERT(*startOffset == -1 && *endOffset == -1);
    int length = text.size();
    Q_ASSERT(offset >= 0 && offset <= length);

    // move offset into the right range (if asking for line before or after
    if (beforeAtAfter == 1) {
        offset = text.indexOf(QChar::LineFeed, qMin(offset, length - 1));
        if (offset < 0)
            return QString(); // after the last line comes nothing
        ++offset; // move after the newline
    } else if (beforeAtAfter == -1) {
        offset = text.lastIndexOf(QChar::LineFeed, qMax(offset - 1, 0));
        if (offset < 0)
            return QString(); // before first line comes nothing
    }

    if (offset > 0)
        *startOffset = text.lastIndexOf(QChar::LineFeed, offset - 1);
    ++*startOffset; // move to the char after the newline (0 if lastIndexOf returned -1)

    *endOffset = text.indexOf(QChar::LineFeed, qMin(offset, length - 1)) + 1; // include newline char
    if (*endOffset <= 0 || *endOffset > length)
        *endOffset = length; // if the text doesn't end with a newline it ends at length

    return text.mid(*startOffset, *endOffset - *startOffset);
}

/*!
    Returns the text item of type \a boundaryType that is close to offset \a offset
    and sets \a startOffset and \a endOffset values to the start and end positions
    of that item; returns an empty string if there is no such an item.
    Sets \a startOffset and \a endOffset values to -1 on error.

    This default implementation is provided for small text edits. A word processor or
    text editor should provide their own efficient implementations. This function makes no
    distinction between paragraphs and lines.

    \note this function can not take the cursor position into account. By convention
    an \a offset of -2 means that this function should use the cursor position as offset.
    Thus an offset of -2 must be converted to the cursor position before calling this
    function.
    An offset of -1 is used for the text length and custom implementations of this function
    have to return the result as if the length was passed in as offset.
*/
QString QAccessibleTextInterface::textBeforeOffset(int offset, QAccessible::TextBoundaryType boundaryType,
                                                   int *startOffset, int *endOffset) const
{
    const QString txt = text(0, characterCount());

    if (offset == -1)
        offset = txt.size();

    *startOffset = *endOffset = -1;
    if (txt.isEmpty() || offset <= 0 || offset > txt.size())
        return QString();

    // type initialized just to silence a compiler warning [-Werror=maybe-uninitialized]
    QTextBoundaryFinder::BoundaryType type = QTextBoundaryFinder::Grapheme;
    switch (boundaryType) {
    case QAccessible::CharBoundary:
        type = QTextBoundaryFinder::Grapheme;
        break;
    case QAccessible::WordBoundary:
        type = QTextBoundaryFinder::Word;
        break;
    case QAccessible::SentenceBoundary:
        type = QTextBoundaryFinder::Sentence;
        break;
    case QAccessible::LineBoundary:
    case QAccessible::ParagraphBoundary:
        // Lines can not use QTextBoundaryFinder since Line there means any potential line-break.
        return textLineBoundary(-1, txt, offset, startOffset, endOffset);
    case QAccessible::NoBoundary:
        // return empty, this function currently only supports single lines, so there can be no line before
        return QString();
    default:
        Q_UNREACHABLE();
    }

    // keep behavior in sync with QTextCursor::movePosition()!

    QTextBoundaryFinder boundary(type, txt);
    boundary.setPosition(offset);

    do {
        if ((boundary.boundaryReasons() & (QTextBoundaryFinder::StartOfItem | QTextBoundaryFinder::EndOfItem)))
            break;
    } while (boundary.toPreviousBoundary() > 0);
    Q_ASSERT(boundary.position() >= 0);
    *endOffset = boundary.position();

    while (boundary.toPreviousBoundary() > 0) {
        if ((boundary.boundaryReasons() & (QTextBoundaryFinder::StartOfItem | QTextBoundaryFinder::EndOfItem)))
            break;
    }
    Q_ASSERT(boundary.position() >= 0);
    *startOffset = boundary.position();

    return txt.mid(*startOffset, *endOffset - *startOffset);
}

/*!
    Returns the text item of type \a boundaryType that is right after offset \a offset
    and sets \a startOffset and \a endOffset values to the start and end positions
    of that item; returns an empty string if there is no such an item.
    Sets \a startOffset and \a endOffset values to -1 on error.

    This default implementation is provided for small text edits. A word processor or
    text editor should provide their own efficient implementations. This function makes no
    distinction between paragraphs and lines.

    \note this function can not take the cursor position into account. By convention
    an \a offset of -2 means that this function should use the cursor position as offset.
    Thus an offset of -2 must be converted to the cursor position before calling this
    function.
    An offset of -1 is used for the text length and custom implementations of this function
    have to return the result as if the length was passed in as offset.
*/
QString QAccessibleTextInterface::textAfterOffset(int offset, QAccessible::TextBoundaryType boundaryType,
                                                  int *startOffset, int *endOffset) const
{
    const QString txt = text(0, characterCount());

    if (offset == -1)
        offset = txt.size();

    *startOffset = *endOffset = -1;
    if (txt.isEmpty() || offset < 0 || offset >= txt.size())
        return QString();

    // type initialized just to silence a compiler warning [-Werror=maybe-uninitialized]
    QTextBoundaryFinder::BoundaryType type = QTextBoundaryFinder::Grapheme;
    switch (boundaryType) {
    case QAccessible::CharBoundary:
        type = QTextBoundaryFinder::Grapheme;
        break;
    case QAccessible::WordBoundary:
        type = QTextBoundaryFinder::Word;
        break;
    case QAccessible::SentenceBoundary:
        type = QTextBoundaryFinder::Sentence;
        break;
    case QAccessible::LineBoundary:
    case QAccessible::ParagraphBoundary:
        // Lines can not use QTextBoundaryFinder since Line there means any potential line-break.
        return textLineBoundary(1, txt, offset, startOffset, endOffset);
    case QAccessible::NoBoundary:
        // return empty, this function currently only supports single lines, so there can be no line after
        return QString();
    default:
        Q_UNREACHABLE();
    }

    // keep behavior in sync with QTextCursor::movePosition()!

    QTextBoundaryFinder boundary(type, txt);
    boundary.setPosition(offset);

    while (true) {
        int toNext = boundary.toNextBoundary();
        if ((boundary.boundaryReasons() & (QTextBoundaryFinder::StartOfItem | QTextBoundaryFinder::EndOfItem)))
            break;
        if (toNext < 0 || toNext >= txt.size())
            break; // not found, the boundary might not exist
    }
    Q_ASSERT(boundary.position() <= txt.size());
    *startOffset = boundary.position();

    while (true) {
        int toNext = boundary.toNextBoundary();
        if ((boundary.boundaryReasons() & (QTextBoundaryFinder::StartOfItem | QTextBoundaryFinder::EndOfItem)))
            break;
        if (toNext < 0 || toNext >= txt.size())
            break; // not found, the boundary might not exist
    }
    Q_ASSERT(boundary.position() <= txt.size());
    *endOffset = boundary.position();

    if ((*startOffset == -1) || (*endOffset == -1) || (*startOffset == *endOffset)) {
        *endOffset = -1;
        *startOffset = -1;
    }

    return txt.mid(*startOffset, *endOffset - *startOffset);
}

/*!
    Returns the text item of type \a boundaryType at offset \a offset
    and sets \a startOffset and \a endOffset values to the start and end positions
    of that item; returns an empty string if there is no such an item.
    Sets \a startOffset and \a endOffset values to -1 on error.

    This default implementation is provided for small text edits. A word processor or
    text editor should provide their own efficient implementations. This function makes no
    distinction between paragraphs and lines.

    \note this function can not take the cursor position into account. By convention
    an \a offset of -2 means that this function should use the cursor position as offset.
    Thus an offset of -2 must be converted to the cursor position before calling this
    function.
    An offset of -1 is used for the text length and custom implementations of this function
    have to return the result as if the length was passed in as offset.
*/
QString QAccessibleTextInterface::textAtOffset(int offset, QAccessible::TextBoundaryType boundaryType,
                                               int *startOffset, int *endOffset) const
{
    const QString txt = text(0, characterCount());

    if (offset == -1)
        offset = txt.size();

    *startOffset = *endOffset = -1;
    if (txt.isEmpty() || offset < 0 || offset > txt.size())
        return QString();

    if (offset == txt.size() && boundaryType == QAccessible::CharBoundary)
        return QString();

    // type initialized just to silence a compiler warning [-Werror=maybe-uninitialized]
    QTextBoundaryFinder::BoundaryType type = QTextBoundaryFinder::Grapheme;
    switch (boundaryType) {
    case QAccessible::CharBoundary:
        type = QTextBoundaryFinder::Grapheme;
        break;
    case QAccessible::WordBoundary:
        type = QTextBoundaryFinder::Word;
        break;
    case QAccessible::SentenceBoundary:
        type = QTextBoundaryFinder::Sentence;
        break;
    case QAccessible::LineBoundary:
    case QAccessible::ParagraphBoundary:
        // Lines can not use QTextBoundaryFinder since Line there means any potential line-break.
        return textLineBoundary(0, txt, offset, startOffset, endOffset);
    case QAccessible::NoBoundary:
        *startOffset = 0;
        *endOffset = txt.size();
        return txt;
    default:
        Q_UNREACHABLE();
    }

    // keep behavior in sync with QTextCursor::movePosition()!

    QTextBoundaryFinder boundary(type, txt);
    boundary.setPosition(offset);

    do {
        if ((boundary.boundaryReasons() & (QTextBoundaryFinder::StartOfItem | QTextBoundaryFinder::EndOfItem)))
            break;
    } while (boundary.toPreviousBoundary() > 0);
    Q_ASSERT(boundary.position() >= 0);
    *startOffset = boundary.position();

    while (boundary.toNextBoundary() < txt.size()) {
        if ((boundary.boundaryReasons() & (QTextBoundaryFinder::StartOfItem | QTextBoundaryFinder::EndOfItem)))
            break;
    }
    Q_ASSERT(boundary.position() <= txt.size());
    *endOffset = boundary.position();

    return txt.mid(*startOffset, *endOffset - *startOffset);
}

/*!
    \fn void QAccessibleTextInterface::removeSelection(int selectionIndex)

    Clears the selection with index \a selectionIndex.
*/

/*!
    \fn void QAccessibleTextInterface::setCursorPosition(int position)

    Moves the cursor to \a position.
*/

/*!
    \fn void QAccessibleTextInterface::setSelection(int selectionIndex, int startOffset, int endOffset)

    Set the selection \a selectionIndex to the range from \a startOffset to \a endOffset.

    \sa addSelection(), removeSelection()
*/

/*!
    \fn int QAccessibleTextInterface::characterCount() const

    Returns the length of the text (total size including spaces).
*/

/*!
    \fn void QAccessibleTextInterface::scrollToSubstring(int startIndex, int endIndex)

    Ensures that the text between \a startIndex and \a endIndex is visible.
*/

/*!
    \class QAccessibleEditableTextInterface
    \ingroup accessibility
    \inmodule QtGui

    \brief The QAccessibleEditableTextInterface class implements support for objects with editable text.

    When implementing this interface you will almost certainly also want to implement \l QAccessibleTextInterface.

    \sa QAccessibleInterface

    \l{IAccessible2 Specification}
*/

/*!

    Destroys the QAccessibleEditableTextInterface.
*/
QAccessibleEditableTextInterface::~QAccessibleEditableTextInterface()
{
}

/*!
    \fn void QAccessibleEditableTextInterface::deleteText(int startOffset, int endOffset)

    Deletes the text from \a startOffset to \a endOffset.
*/

/*!
    \fn void QAccessibleEditableTextInterface::insertText(int offset, const QString &text)

    Inserts \a text at position \a offset.
*/

/*!
    \fn void QAccessibleEditableTextInterface::replaceText(int startOffset, int endOffset, const QString &text)

    Removes the text from \a startOffset to \a endOffset and instead inserts \a text.
*/

/*!
    \class QAccessibleValueInterface
    \inmodule QtGui
    \ingroup accessibility

    \brief The QAccessibleValueInterface class implements support for objects that manipulate a value.

    This interface should be implemented by accessible objects that represent a value.
    Examples are spinner, slider, dial and scroll bar.

    Instead of forcing the user to deal with the individual parts of the widgets, this interface
    gives an easier approach to the kind of widget it represents.

    Usually this interface is implemented by classes that also implement \l QAccessibleInterface.

    \l{IAccessible2 Specification}
*/

/*!
    Destroys the QAccessibleValueInterface.

*/
QAccessibleValueInterface::~QAccessibleValueInterface()
{
}

/*!
    \fn QVariant QAccessibleValueInterface::currentValue() const

    Returns the current value of the widget. This is usually a double or int.
    \sa setCurrentValue()
*/

/*!
    \fn void QAccessibleValueInterface::setCurrentValue(const QVariant &value)

    Sets the \a value. If the desired \a value is out of the range of permissible values,
    this call will be ignored.

    \sa currentValue(), minimumValue(), maximumValue()
*/

/*!
    \fn QVariant QAccessibleValueInterface::maximumValue() const

    Returns the maximum value this object accepts.
    \sa minimumValue(), currentValue()
*/

/*!
    \fn QVariant QAccessibleValueInterface::minimumValue() const

    Returns the minimum value this object accepts.
    \sa maximumValue(), currentValue()
*/

/*!
    \fn QVariant QAccessibleValueInterface::minimumStepSize() const

    Returns the minimum step size for the accessible.
    This is the smallest increment that makes sense when changing the value.
    When programmatically changing the value it should always be a multiple
    of the minimum step size.

    Some tools use this value even when the setCurrentValue does not
    perform any action. Progress bars for example are read-only but
    should return their range divided by 100.
*/

/*!
    \class QAccessibleImageInterface
    \inmodule QtGui
    \ingroup accessibility
    \internal
    \preliminary

    \brief The QAccessibleImageInterface class implements support for
    the IAccessibleImage interface.

    \l{IAccessible2 Specification}
*/

/*!
    Destroys the QAccessibleImageInterface.
*/
QAccessibleImageInterface::~QAccessibleImageInterface()
{
}

/*!
    \class QAccessibleTableCellInterface
    \inmodule QtGui
    \ingroup accessibility

    \brief The QAccessibleTableCellInterface class implements support for
    the IAccessibleTable2 Cell interface.

    \l{IAccessible2 Specification}
*/

/*!

    Destroys the QAccessibleTableCellInterface.
*/
QAccessibleTableCellInterface::~QAccessibleTableCellInterface()
{
}

/*!
    \fn virtual int QAccessibleTableCellInterface::columnExtent() const

    Returns the number of columns occupied by this cell accessible.
*/

/*!
    \fn virtual QList<QAccessibleInterface*> QAccessibleTableCellInterface::columnHeaderCells() const

    Returns the column headers as an array of cell accessibles.
*/

/*!
    \fn virtual int QAccessibleTableCellInterface::columnIndex() const

    Translates this cell accessible into the corresponding column index.
*/

/*!
    \fn virtual int QAccessibleTableCellInterface::rowExtent() const

    Returns the number of rows occupied by this cell accessible.
*/

/*!
    \fn virtual QList<QAccessibleInterface*> QAccessibleTableCellInterface::rowHeaderCells() const

    Returns the row headers as an array of cell accessibles.
*/

/*!
    \fn virtual int QAccessibleTableCellInterface::rowIndex() const

    Translates this cell accessible into the corresponding row index.
*/

/*!
    \fn virtual bool QAccessibleTableCellInterface::isSelected() const

    Returns a boolean value indicating whether this cell is selected.
*/

/*!
    \fn virtual QAccessibleInterface *QAccessibleTableCellInterface::table() const

    Returns the QAccessibleInterface of the table containing this cell.
*/


/*!
    \class QAccessibleTableInterface
    \inmodule QtGui
    \ingroup accessibility

    \brief The QAccessibleTableInterface class implements support for
    the IAccessibleTable2 interface.

    \l{IAccessible2 Specification}
*/

/*!

    Destroys the QAccessibleTableInterface.
*/
QAccessibleTableInterface::~QAccessibleTableInterface()
{
}

/*!
    \fn virtual QAccessibleInterface *QAccessibleTableInterface::cellAt(int row, int column) const

    Returns the cell at the specified \a row and \a column in the table.
*/

/*!
    \fn virtual QAccessibleInterface *QAccessibleTableInterface::caption() const

    Returns the caption for the table.
*/

/*!
    \fn virtual QString QAccessibleTableInterface::columnDescription(int column) const

    Returns the description text of the specified \a column in the table.
*/

/*!
    \fn virtual int QAccessibleTableInterface::columnCount() const

    Returns the total number of columns in table.
*/

/*!
    \fn virtual int QAccessibleTableInterface::rowCount() const

    Returns the total number of rows in table.
*/

/*!
    \fn virtual int QAccessibleTableInterface::selectedCellCount() const

    Returns the total number of selected cells.
*/

/*!
    \fn virtual int QAccessibleTableInterface::selectedColumnCount() const

    Returns the total number of selected columns.
*/

/*!
    \fn virtual int QAccessibleTableInterface::selectedRowCount() const

    Returns the total number of selected rows.
*/

/*!
    \fn virtual QString QAccessibleTableInterface::rowDescription(int row) const

    Returns the description text of the specified \a row in the table.
*/

/*!
    \fn virtual QList<int> QAccessibleTableInterface::selectedCells() const

    Returns the list of selected cell (by their index as \l QAccessibleInterface::child() accepts).
*/

/*!
    \fn virtual QList<int> QAccessibleTableInterface::selectedColumns() const

    Returns the list of currently selected columns.
*/

/*!
    \fn virtual QList<int> QAccessibleTableInterface::selectedRows() const

    Returns the list of currently selected rows.
*/

/*!
    \fn virtual QAccessibleInterface *QAccessibleTableInterface::summary() const

    Returns a QAccessibleInterface that represents a summary of the table.
    This function may return 0 if no such interface exists.
*/

/*!
    \fn virtual bool QAccessibleTableInterface::isColumnSelected(int column) const

    Returns a boolean value indicating whether the specified \a column is completely selected.
*/

/*!
    \fn virtual bool QAccessibleTableInterface::isRowSelected(int row) const

    Returns a boolean value indicating whether the specified \a row is completely selected.
*/

/*!
    \fn virtual bool QAccessibleTableInterface::selectRow(int row)

    Selects \a row. This function might unselect all previously selected rows.
    Returns \c true if the selection was successful.
*/

/*!
    \fn virtual bool QAccessibleTableInterface::selectColumn(int column)

    Selects \a column. This function might unselect all previously selected columns.
    Returns \c true if the selection was successful.
*/

/*!
    \fn virtual bool QAccessibleTableInterface::unselectRow(int row)

    Unselects \a row, leaving other selected rows selected (if any).
    Returns \c true if the selection was successful.
*/

/*!
    \fn virtual bool QAccessibleTableInterface::unselectColumn(int column)

    Unselects \a column, leaving other selected columns selected (if any).
    Returns \c true if the selection was successful.
*/

/*!
    \fn virtual void QAccessibleTableInterface::modelChange(QAccessibleTableModelChangeEvent *event)

    Informs about a change in the model's layout.
    The \a event contains the details.
    \sa QAccessibleTableModelChangeEvent
*/


/*!
    \class QAccessibleActionInterface
    \inmodule QtGui
    \ingroup accessibility

    \brief The QAccessibleActionInterface class implements support for
    invocable actions in the interface.

    Accessible objects should implement the action interface if they support user interaction.
    Usually this interface is implemented by classes that also implement \l QAccessibleInterface.

    The supported actions should use the predefined actions offered in this class unless they do not
    fit a predefined action. In that case a custom action can be added.

    When subclassing QAccessibleActionInterface you need to provide a list of actionNames which
    is the primary means to discover the available actions. Action names are never localized.
    In order to present actions to the user there are two functions that need to return localized versions
    of the name and give a description of the action. For the predefined action names use
    \l QAccessibleActionInterface::localizedActionName() and \l QAccessibleActionInterface::localizedActionDescription()
    to return their localized counterparts.

    In general you should use one of the predefined action names, unless describing an action that does not fit these:
    \table
    \header \li Action name         \li Description
    \row    \li \l toggleAction()   \li toggles the item (checkbox, radio button, switch, ...)
    \row    \li \l decreaseAction() \li decrease the value of the accessible (e.g. spinbox)
    \row    \li \l increaseAction() \li increase the value of the accessible (e.g. spinbox)
    \row    \li \l pressAction()    \li press or click or activate the accessible (should correspond to clicking the object with the mouse)
    \row    \li \l setFocusAction() \li set the focus to this accessible
    \row    \li \l showMenuAction() \li show a context menu, corresponds to right-clicks
    \endtable

    In order to invoke the action, \l doAction() is called with an action name.

    Most widgets will simply implement \l pressAction(). This is what happens when the widget is activated by
    being clicked, space pressed or similar.

    \l{IAccessible2 Specification}
*/

/*!

    Destroys the QAccessibleActionInterface.
*/
QAccessibleActionInterface::~QAccessibleActionInterface()
{
}

/*!
    \fn QStringList QAccessibleActionInterface::actionNames() const

    Returns the list of actions supported by this accessible object.
    The actions returned should be in preferred order,
    i.e. the action that the user most likely wants to trigger should be returned first,
    while the least likely action should be returned last.

    The list does only contain actions that can be invoked.
    It won't return disabled actions, or actions associated with disabled UI controls.

    The list can be empty.

    Note that this list is not localized. For a localized representation re-implement \l localizedActionName()
    and \l localizedActionDescription()

    \sa doAction(), localizedActionName(), localizedActionDescription()
*/

/*!
    \fn QString QAccessibleActionInterface::localizedActionName(const QString &actionName) const

    Returns a localized action name of \a actionName.

    For custom actions this function has to be re-implemented.
    When using one of the default names, you can call this function in QAccessibleActionInterface
    to get the localized string.

    \sa actionNames(), localizedActionDescription()
*/

/*!
    \fn QString QAccessibleActionInterface::localizedActionDescription(const QString &actionName) const

    Returns a localized action description of the action \a actionName.

    When using one of the default names, you can call this function in QAccessibleActionInterface
    to get the localized string.

    \sa actionNames(), localizedActionName()
*/

/*!
    \fn void QAccessibleActionInterface::doAction(const QString &actionName)

    Invokes the action specified by \a actionName.
    Note that \a actionName is the non-localized name as returned by \l actionNames()
    This function is usually implemented by calling the same functions
    that other user interaction, such as clicking the object, would trigger.

    \sa actionNames()
*/

/*!
    \fn QStringList QAccessibleActionInterface::keyBindingsForAction(const QString &actionName) const

    Returns a list of the keyboard shortcuts available for invoking the action named \a actionName.

    This is important to let users learn alternative ways of using the application by emphasizing the keyboard.

    \sa actionNames()
*/


struct QAccessibleActionStrings
{
    QAccessibleActionStrings() :
        pressAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Press"))),
        increaseAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Increase"))),
        decreaseAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Decrease"))),
        showMenuAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "ShowMenu"))),
        setFocusAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "SetFocus"))),
        toggleAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Toggle"))),
        scrollLeftAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Scroll Left"))),
        scrollRightAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Scroll Right"))),
        scrollUpAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Scroll Up"))),
        scrollDownAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Scroll Down"))),
        previousPageAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Previous Page"))),
        nextPageAction(QStringLiteral(QT_TRANSLATE_NOOP("QAccessibleActionInterface", "Next Page")))
    {}

    const QString pressAction;
    const QString increaseAction;
    const QString decreaseAction;
    const QString showMenuAction;
    const QString setFocusAction;
    const QString toggleAction;
    const QString scrollLeftAction;
    const QString scrollRightAction;
    const QString scrollUpAction;
    const QString scrollDownAction;
    const QString previousPageAction;
    const QString nextPageAction;

    QString localizedDescription(const QString &actionName)
    {
        if (actionName == pressAction)
            return QAccessibleActionInterface::tr("Triggers the action");
        else if (actionName == increaseAction)
            return QAccessibleActionInterface::tr("Increase the value");
        else if (actionName == decreaseAction)
            return QAccessibleActionInterface::tr("Decrease the value");
        else if (actionName == showMenuAction)
            return QAccessibleActionInterface::tr("Shows the menu");
        else if (actionName == setFocusAction)
            return QAccessibleActionInterface::tr("Sets the focus");
        else if (actionName == toggleAction)
            return QAccessibleActionInterface::tr("Toggles the state");
        else if (actionName == scrollLeftAction)
            return QAccessibleActionInterface::tr("Scrolls to the left");
        else if (actionName == scrollRightAction)
            return QAccessibleActionInterface::tr("Scrolls to the right");
        else if (actionName == scrollUpAction)
            return QAccessibleActionInterface::tr("Scrolls up");
        else if (actionName == scrollDownAction)
            return QAccessibleActionInterface::tr("Scrolls down");
        else if (actionName == previousPageAction)
            return QAccessibleActionInterface::tr("Goes back a page");
        else if (actionName == nextPageAction)
            return QAccessibleActionInterface::tr("Goes to the next page");


        return QString();
    }
};

Q_GLOBAL_STATIC(QAccessibleActionStrings, accessibleActionStrings)

QString QAccessibleActionInterface::localizedActionName(const QString &actionName) const
{
    return QAccessibleActionInterface::tr(qPrintable(actionName));
}

QString QAccessibleActionInterface::localizedActionDescription(const QString &actionName) const
{
    return accessibleActionStrings()->localizedDescription(actionName);
}

/*!
    Returns the name of the press default action.
    \sa actionNames(), localizedActionName()
  */
const QString &QAccessibleActionInterface::pressAction()
{
    return accessibleActionStrings()->pressAction;
}

/*!
    Returns the name of the increase default action.
    \sa actionNames(), localizedActionName()
  */
const QString &QAccessibleActionInterface::increaseAction()
{
    return accessibleActionStrings()->increaseAction;
}

/*!
    Returns the name of the decrease default action.
    \sa actionNames(), localizedActionName()
  */
const QString &QAccessibleActionInterface::decreaseAction()
{
    return accessibleActionStrings()->decreaseAction;
}

/*!
    Returns the name of the show menu default action.
    \sa actionNames(), localizedActionName()
  */
const QString &QAccessibleActionInterface::showMenuAction()
{
    return accessibleActionStrings()->showMenuAction;
}

/*!
    Returns the name of the set focus default action.
    \sa actionNames(), localizedActionName()
  */
const QString &QAccessibleActionInterface::setFocusAction()
{
    return accessibleActionStrings()->setFocusAction;
}

/*!
    Returns the name of the toggle default action.
    \sa actionNames(), localizedActionName()
  */
const QString &QAccessibleActionInterface::toggleAction()
{
    return accessibleActionStrings()->toggleAction;
}

/*!
    Returns the name of the scroll left default action.
    \sa actionNames(), localizedActionName()
  */
QString QAccessibleActionInterface::scrollLeftAction()
{
    return accessibleActionStrings()->scrollLeftAction;
}

/*!
    Returns the name of the scroll right default action.
    \sa actionNames(), localizedActionName()
  */
QString QAccessibleActionInterface::scrollRightAction()
{
    return accessibleActionStrings()->scrollRightAction;
}

/*!
    Returns the name of the scroll up default action.
    \sa actionNames(), localizedActionName()
  */
QString QAccessibleActionInterface::scrollUpAction()
{
    return accessibleActionStrings()->scrollUpAction;
}

/*!
    Returns the name of the scroll down default action.
    \sa actionNames(), localizedActionName()
  */
QString QAccessibleActionInterface::scrollDownAction()
{
    return accessibleActionStrings()->scrollDownAction;
}

/*!
    Returns the name of the previous page default action.
    \sa actionNames(), localizedActionName()
  */
QString QAccessibleActionInterface::previousPageAction()
{
    return accessibleActionStrings()->previousPageAction;
}

/*!
    Returns the name of the next page default action.
    \sa actionNames(), localizedActionName()
  */
QString QAccessibleActionInterface::nextPageAction()
{
    return accessibleActionStrings()->nextPageAction;
}


/*!
    \since 6.5
    \class QAccessibleSelectionInterface
    \inmodule QtGui
    \ingroup accessibility

    \brief The QAccessibleSelectionInterface class implements support for
    selection handling.

    It provides methods for both, retrieving the current selection
    as well as modifying the selection.

    Only selections of direct children are supported.
*/

/*!

    Destroys the QAccessibleSelectionInterface.
*/
QAccessibleSelectionInterface::~QAccessibleSelectionInterface()
{
}

/*!
    \fn virtual int QAccessibleSelectionInterface::selectedItemCount() const

    Returns the total number of selected accessible items.
*/

/*!
    \fn virtual QList<QAccessibleInterface *> QAccessibleSelectionInterface::selectedItems() const

    Returns the list of selected accessible items.
*/

/*!
    Returns the selected accessible item at index \a selectionIndex in the selection.

    Note that the index refers to the n-th selected accessible item (i.e. the index in the current selection),
    which generally differs from the index that would be passed to \l QAccessibleInterface::child()
    in order to retrieve the same item.

    The default implementation uses \a selectionIndex to retrieve the item from the list
    of selected items retrieved by \l QAccessibleSelectionInterface::selectedItems().

    In particular for implementations dealing with many selected items, reimplementing
    this method in a more efficient way may be desirable for performance reasons.
*/
QAccessibleInterface* QAccessibleSelectionInterface::selectedItem(int selectionIndex) const
{
    QList<QAccessibleInterface*> items = selectedItems();
    if (selectionIndex < 0 || selectionIndex > items.length() -1) {
        qCWarning(lcAccessibilityCore) << "Selection index" << selectionIndex << "out of range.";
        return nullptr;
    }

    return items.at(selectionIndex);
}

/*!
    Returns whether \a childItem is part of the current selection.

    The default implementation checks whether \a childItem is contained
    in the list of items retrieved by \l QAccessibleSelectionInterface::selectedItems.
*/
bool QAccessibleSelectionInterface::isSelected(QAccessibleInterface *childItem) const
{
    return selectedItems().contains(childItem);
}

/*!
    \fn virtual bool QAccessibleSelectionInterface::select(QAccessibleInterface *childItem)

    Adds \a childItem to the selection.
    Returns whether \a childItem has actually been added to the selection.

    For implementations that only allow single selections,
    this may replace the current selection.
*/

/*!
    \fn virtual bool QAccessibleSelectionInterface::unselect(QAccessibleInterface *childItem)

    Removes \a childItem from the selection.

    Returns whether the accessible item has actually been removed from the selection.
*/

/*!
    \fn virtual bool QAccessibleSelectionInterface::selectAll()

    Selects all accessible child items.

    Returns whether all accessible child items have actually been added to the selection.
*/

/*!
    \fn virtual bool QAccessibleSelectionInterface::clear()

    Unselects all accessible child items.

    Returns whether all accessible child items have actually been removed from the selection,
    i.e. whether the selection is empty after this method has been called.
*/


/*!
    \since 6.8
    \class QAccessibleAttributesInterface
    \inmodule QtGui
    \ingroup accessibility

 \brief The QAccessibleAttributesInterface class implements support for
 reporting attributes for an accessible object.

 Attributes are key-value pairs. Values are stored in \l QVariant.

 The \l QAccessible::Attribute enumeration describes the available keys and
 documents which type to use for the value of each key.

 While the text-specific attributes handled by \l QAccessibleTextInterface::attributes
 are specific to objects implementing text and are specific to a specific text
 position/offset, the attributes handled by the \l QAccessibleAttributesInterface
 can be used for objects of any role and apply for the whole object.

 Classes already implementing \l QAccessibleTextInterface for text-specific attrtibutes
 may want to implement \l QAccessibleAttributesInterface in addition for object-specific
 attributes.
*/

/*!

 Destroys the QAccessibleAttributesInterface.
*/
QAccessibleAttributesInterface::~QAccessibleAttributesInterface()
{
}

/*!
    \fn QList<QAccessible::Attribute> QAccessibleAttributesInterface::attributeKeys() const

 Returns the keys of all attributes the object supports. The \l QAccessible::Attribute
 enumeration describes available keys.
*/

/*!
    \fn QVariant QAccessibleAttributesInterface::attributeValue(QAccessible::Attribute key) const

 Returns the value of the attribute \a key of this object.

 If the attribute is set for this object, a value of the type documented for the
 given key in the documentation of the \l QAccessible::Attribute enumeration is
 returned in the \l QVariant.

 Otherwise, an invalid \l QVariant is returned.
*/

/*! \internal */
QString qAccessibleLocalizedActionDescription(const QString &actionName)
{
    return accessibleActionStrings()->localizedDescription(actionName);
}

/*!
    \internal
    \fn QString QAccessibleHyperlinkInterface::anchor() const

    The logical/human readable name of the hyperlink
*/

/*!
    \internal
    \fn QString QAccessibleHyperlinkInterface::anchorTarget() const

    The target url of the hyperlink
*/

/*!
    \internal
    \fn int QAccessibleHyperlinkInterface::startIndex() const

    Returns the start index that will refer to the first character in the text where the hyperlink
    begins. The index corresponds to the index that the QAccessibleTextInterface needs in order
    to find the start of the hyperlink.

*/

/*!
    \internal
    \fn int QAccessibleHyperlinkInterface::endIndex() const

    Returns the end index that will refer to the first character in the text where the hyperlink
    begins. The index corresponds to the index that the QAccessibleTextInterface needs in order
    to find the end of the hyperlink.
*/

QAccessibleHyperlinkInterface::~QAccessibleHyperlinkInterface()
{

}

#endif // QT_CONFIG(accessibility)

QT_END_NAMESPACE

#include "moc_qaccessible_base.cpp"
