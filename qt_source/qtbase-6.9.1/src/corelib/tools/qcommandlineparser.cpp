// Copyright (C) 2013 Laszlo Papp <lpapp@kde.org>
// Copyright (C) 2013 David Faure <faure@kde.org>
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qcommandlineparser.h"

#include <qcoreapplication.h>
#include <private/qcoreapplication_p.h>
#include <qhash.h>
#include <qvarlengtharray.h>
#include <qlist.h>
#include <qdebug.h>
#if defined(Q_OS_WIN) && !defined(QT_BOOTSTRAPPED)
#  include <qt_windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>

QT_BEGIN_NAMESPACE

using namespace Qt::StringLiterals;

extern void Q_CORE_EXPORT qt_call_post_routines();

typedef QHash<QString, qsizetype> NameHash_t;

class QCommandLineParserPrivate
{
public:
    inline QCommandLineParserPrivate()
        : singleDashWordOptionMode(QCommandLineParser::ParseAsCompactedShortOptions),
          optionsAfterPositionalArgumentsMode(QCommandLineParser::ParseAsOptions),
          builtinVersionOption(false),
          builtinHelpOption(false),
          needsParsing(true)
    { }

    bool parse(const QStringList &args);
    void checkParsed(const char *method);
    QStringList aliases(const QString &name) const;
    QString helpText(bool includeQtOptions) const;
    bool registerFoundOption(const QString &optionName);
    bool parseOptionValue(const QString &optionName, const QString &argument,
                          QStringList::const_iterator *argumentIterator,
                          QStringList::const_iterator argsEnd);
    Q_NORETURN void showHelp(int exitCode, bool includeQtOptions);

    //! Error text set when parse() returns false
    QString errorText;

    //! The command line options used for parsing
    QList<QCommandLineOption> commandLineOptionList;

    //! Hash mapping option names to their offsets in commandLineOptionList and optionArgumentList.
    NameHash_t nameHash;

    //! Option values found (only for options with a value)
    QHash<qsizetype, QStringList> optionValuesHash;

    //! Names of options found on the command line.
    QStringList optionNames;

    //! Arguments which did not belong to any option.
    QStringList positionalArgumentList;

    //! Names of options which were unknown.
    QStringList unknownOptionNames;

    //! Application description
    QString description;

    //! Documentation for positional arguments
    struct PositionalArgumentDefinition
    {
        QString name;
        QString description;
        QString syntax;
    };
    QList<PositionalArgumentDefinition> positionalArgumentDefinitions;

    //! The parsing mode for "-abc"
    QCommandLineParser::SingleDashWordOptionMode singleDashWordOptionMode;

    //! How to parse "arg -option"
    QCommandLineParser::OptionsAfterPositionalArgumentsMode optionsAfterPositionalArgumentsMode;

    //! Whether addVersionOption was called
    bool builtinVersionOption;

    //! Whether addHelpOption was called
    bool builtinHelpOption;

    //! True if parse() needs to be called
    bool needsParsing;
};
Q_DECLARE_TYPEINFO(QCommandLineParserPrivate::PositionalArgumentDefinition, Q_RELOCATABLE_TYPE);

QStringList QCommandLineParserPrivate::aliases(const QString &optionName) const
{
    const NameHash_t::const_iterator it = nameHash.constFind(optionName);
    if (it == nameHash.cend()) {
        qWarning("QCommandLineParser: option not defined: \"%ls\"", qUtf16Printable(optionName));
        return QStringList();
    }
    return commandLineOptionList.at(*it).names();
}

/*!
    \since 5.2
    \class QCommandLineParser
    \inmodule QtCore
    \ingroup tools

    \brief The QCommandLineParser class provides a means for handling the
    command line options.

    QCoreApplication provides the command-line arguments as a simple list of strings.
    QCommandLineParser provides the ability to define a set of options, parse the
    command-line arguments, and store which options have actually been used, as
    well as option values.

    Any argument that isn't an option (i.e. doesn't start with a \c{-}) is stored
    as a "positional argument".

    The parser handles short names, long names, more than one name for the same
    option, and option values.

    Options on the command line are recognized as starting with one or two
    \c{-} characters, followed by the option name.
    The option \c{-} (single dash alone) is a special case, often meaning standard
    input, and is not treated as an option. The parser will treat everything after the
    option \c{--} (double dash) as positional arguments.

    Short options are single letters. The option \c{v} would be specified by
    passing \c{-v} on the command line. In the default parsing mode, short options
    can be written in a compact form, for instance \c{-abc} is equivalent to \c{-a -b -c}.
    The parsing mode can be changed to ParseAsLongOptions, in which case \c{-abc}
    will be parsed as the long option \c{abc}.

    Long options are more than one letter long and cannot be compacted together.
    The long option \c{verbose} would be passed as \c{--verbose} or \c{-verbose}.

    Passing values to options can be done by using the assignment operator (\c{-v=value},
    \c{--verbose=value}), or with a space (\c{-v value}, \c{--verbose value}). This
    works even if the the value starts with a \c{-}.

    The parser does not support optional values - if an option is set to
    require a value, one must be present. If such an option is placed last
    and has no value, the option will be treated as if it had not been
    specified.

    The parser does not automatically support negating or disabling long options
    by using the format \c{--disable-option} or \c{--no-option}. However, it is
    possible to handle this case explicitly by making an option with \c{no-option}
    as one of its names, and handling the option explicitly.

    Example:
    \snippet code/src_corelib_tools_qcommandlineparser_main.cpp 0

    The three addOption() calls in the above example can be made more compact
    by using addOptions():
    \snippet code/src_corelib_tools_qcommandlineparser_main.cpp cxx11

    Known limitation: the parsing of Qt options inside QCoreApplication and subclasses
    happens before QCommandLineParser exists, so it can't take it into account. This
    means any option value that looks like a builtin Qt option will be treated by
    QCoreApplication as a builtin Qt option. Example: \c{--profile -reverse} will
    lead to QGuiApplication seeing the -reverse option set, and removing it from
    QCoreApplication::arguments() before QCommandLineParser defines the \c{profile}
    option and parses the command line.

    \section2 How to Use QCommandLineParser in Complex Applications

    In practice, additional error checking needs to be performed on the positional
    arguments and option values. For example, ranges of numbers should be checked.

    It is then advisable to introduce a function to do the command line parsing
    which takes a struct or class receiving the option values returning an
    object representing the result. The dnslookup example of the QtNetwork
    module illustrates this:

    \snippet dnslookup.h 0

    \snippet dnslookup.cpp 0

    In the main function, help should be printed to the standard output if the help option
    was passed and the application should return the exit code 0.

    If an error was detected, the error message should be printed to the standard
    error output and the application should return an exit code other than 0.

    \snippet dnslookup.cpp 1

    A special case to consider here are GUI applications on Windows and mobile
    platforms. These applications may not use the standard output or error channels
    since the output is either discarded or not accessible.

    On Windows, QCommandLineParser uses message boxes to display usage information
    and errors if no console window can be obtained. These message boxes can be omitted by setting
    the \c QT_COMMAND_LINE_PARSER_NO_GUI_MESSAGE_BOXES environment variable.

    For other platforms, it is recommended to display help texts and error messages
    using a QMessageBox. To preserve the formatting of the help text, rich text
    with \c <pre> elements should be used:

    \code

    switch (parseResult.statusCode) {
    case Status::Ok:
        break;
    case Status::Error: {
        QString errorMessage = parseResult.errorString.value_or(u"Unknown error occurred"_qs);
        QMessageBox::warning(0, QGuiApplication::applicationDisplayName(),
                             "<html><head/><body><h2>" + errorMessage + "</h2><pre>"
                             + parser.helpText() + "</pre></body></html>");
        return 1;
    }
    case Status::VersionRequested:
        QMessageBox::information(0, QGuiApplication::applicationDisplayName(),
                                 QGuiApplication::applicationDisplayName() + ' '
                                 + QCoreApplication::applicationVersion());
        return 0;
    case Status::HelpRequested:
        QMessageBox::warning(0, QGuiApplication::applicationDisplayName(),
                             "<html><head/><body><pre>"
                             + parser.helpText() + "</pre></body></html>");
        return 0;
    }
    \endcode

    However, this does not apply to the dnslookup example, because it is a
    console application.

    \sa QCommandLineOption, QCoreApplication
*/

/*!
    Constructs a command line parser object.
*/
QCommandLineParser::QCommandLineParser()
    : d(new QCommandLineParserPrivate)
{
}

/*!
    Destroys the command line parser object.
*/
QCommandLineParser::~QCommandLineParser()
{
    delete d;
}

/*!
    \enum QCommandLineParser::SingleDashWordOptionMode

    This enum describes the way the parser interprets command-line
    options that use a single dash followed by multiple letters, as \c{-abc}.

    \value ParseAsCompactedShortOptions \c{-abc} is interpreted as \c{-a -b -c},
    i.e. as three short options that have been compacted on the command-line,
    if none of the options take a value. If \c{a} takes a value, then it
    is interpreted as \c{-a bc}, i.e. the short option \c{a} followed by the value \c{bc}.
    This is typically used in tools that behave like compilers, in order
    to handle options such as \c{-DDEFINE=VALUE} or \c{-I/include/path}.
    This is the default parsing mode. New applications are recommended to
    use this mode.

    \value ParseAsLongOptions \c{-abc} is interpreted as \c{--abc},
    i.e. as the long option named \c{abc}. This is how Qt's own tools
    (uic, rcc...) have always been parsing arguments. This mode should be
    used for preserving compatibility in applications that were parsing
    arguments in such a way. There is an exception if the \c{a} option has the
    QCommandLineOption::ShortOptionStyle flag set, in which case it is still
    interpreted as \c{-a bc}.

    \sa setSingleDashWordOptionMode()
*/

/*!
    Sets the parsing mode to \a singleDashWordOptionMode.
    This must be called before process() or parse().
*/
void QCommandLineParser::setSingleDashWordOptionMode(QCommandLineParser::SingleDashWordOptionMode singleDashWordOptionMode)
{
    d->singleDashWordOptionMode = singleDashWordOptionMode;
}

/*!
    \enum QCommandLineParser::OptionsAfterPositionalArgumentsMode

    This enum describes the way the parser interprets options that
    occur after positional arguments.

    \value ParseAsOptions \c{application argument --opt -t} is interpreted as setting
    the options \c{opt} and \c{t}, just like \c{application --opt -t argument} would do.
    This is the default parsing mode. In order to specify that \c{--opt} and \c{-t}
    are positional arguments instead, the user can use \c{--}, as in
    \c{application argument -- --opt -t}.

    \value ParseAsPositionalArguments \c{application argument --opt} is interpreted as
    having two positional arguments, \c{argument} and \c{--opt}.
    This mode is useful for executables that aim to launch other executables
    (e.g. wrappers, debugging tools, etc.) or that support internal commands
    followed by options for the command. \c{argument} is the name of the command,
    and all options occurring after it can be collected and parsed by another
    command line parser, possibly in another executable.

    \sa setOptionsAfterPositionalArgumentsMode()

    \since 5.6
*/

/*!
    Sets the parsing mode to \a parsingMode.
    This must be called before process() or parse().
    \since 5.6
*/
void QCommandLineParser::setOptionsAfterPositionalArgumentsMode(QCommandLineParser::OptionsAfterPositionalArgumentsMode parsingMode)
{
    d->optionsAfterPositionalArgumentsMode = parsingMode;
}

/*!
    Adds the option \a option to look for while parsing.

    Returns \c true if adding the option was successful; otherwise returns \c false.

    Adding the option fails if there is no name attached to the option, or
    the option has a name that clashes with an option name added before.
 */
bool QCommandLineParser::addOption(const QCommandLineOption &option)
{
    const QStringList optionNames = option.names();

    if (!optionNames.isEmpty()) {
        for (const QString &name : optionNames) {
            if (d->nameHash.contains(name)) {
                qWarning() << "QCommandLineParser: already having an option named" << name;
                return false;
            }
        }

        d->commandLineOptionList.append(option);

        const qsizetype offset = d->commandLineOptionList.size() - 1;
        for (const QString &name : optionNames)
            d->nameHash.insert(name, offset);

        return true;
    }

    return false;
}

/*!
    \since 5.4

    Adds the options to look for while parsing. The options are specified by
    the parameter \a options.

    Returns \c true if adding all of the options was successful; otherwise
    returns \c false.

    See the documentation for addOption() for when this function may fail.
*/
bool QCommandLineParser::addOptions(const QList<QCommandLineOption> &options)
{
    // should be optimized (but it's no worse than what was possible before)
    bool result = true;
    for (QList<QCommandLineOption>::const_iterator it = options.begin(), end = options.end(); it != end; ++it)
        result &= addOption(*it);
    return result;
}

/*!
    Adds the \c{-v} / \c{--version} option, which displays the version string of the application.

    This option is handled automatically by QCommandLineParser.

    You can set the actual version string by using QCoreApplication::setApplicationVersion().

    Returns the option instance, which can be used to call isSet().
*/
QCommandLineOption QCommandLineParser::addVersionOption()
{
    QCommandLineOption opt(QStringList() << QStringLiteral("v") << QStringLiteral("version"), tr("Displays version information."));
    addOption(opt);
    d->builtinVersionOption = true;
    return opt;
}

/*!
    Adds help options to the command-line parser.

    The options specified for this command-line are described by \c{-h} or
    \c{--help}. On Windows, the alternative \c{-?} is also supported. The option
    \c{--help-all} extends that to include generic Qt options, not defined by
    this command, in the output.

    These options are handled automatically by QCommandLineParser.

    Remember to use setApplicationDescription() to set the application
    description, which will be displayed when this option is used.

    Example:
    \snippet code/src_corelib_tools_qcommandlineparser_main.cpp 0

    Returns the option instance, which can be used to call isSet().
*/
QCommandLineOption QCommandLineParser::addHelpOption()
{
    QCommandLineOption opt(QStringList()
#ifdef Q_OS_WIN
                << QStringLiteral("?")
#endif
                << QStringLiteral("h")
                << QStringLiteral("help"), tr("Displays help on commandline options."));
    addOption(opt);
    QCommandLineOption optHelpAll(QStringLiteral("help-all"),
                                  tr("Displays help, including generic Qt options."));
    addOption(optHelpAll);
    d->builtinHelpOption = true;
    return opt;
}

/*!
    Sets the application \a description shown by helpText().
*/
void QCommandLineParser::setApplicationDescription(const QString &description)
{
    d->description = description;
}

/*!
    Returns the application description set in setApplicationDescription().
*/
QString QCommandLineParser::applicationDescription() const
{
    return d->description;
}

/*!
    Defines an additional argument to the application, for the benefit of the help text.

    The argument \a name and \a description will appear under the \c{Arguments:} section
    of the help. If \a syntax is specified, it will be appended to the Usage line, otherwise
    the \a name will be appended.

    Example:
    \snippet code/src_corelib_tools_qcommandlineparser.cpp 2

    \sa addHelpOption(), helpText()
*/
void QCommandLineParser::addPositionalArgument(const QString &name, const QString &description, const QString &syntax)
{
    QCommandLineParserPrivate::PositionalArgumentDefinition arg;
    arg.name = name;
    arg.description = description;
    arg.syntax = syntax.isEmpty() ? name : syntax;
    d->positionalArgumentDefinitions.append(arg);
}

/*!
    Clears the definitions of additional arguments from the help text.

    This is only needed for the special case of tools which support multiple commands
    with different options. Once the actual command has been identified, the options
    for this command can be defined, and the help text for the command can be adjusted
    accordingly.

    Example:
    \snippet code/src_corelib_tools_qcommandlineparser.cpp 3
*/
void QCommandLineParser::clearPositionalArguments()
{
    d->positionalArgumentDefinitions.clear();
}

/*!
    Parses the command line \a arguments.

    Most programs don't need to call this, a simple call to process() is enough.

    parse() is more low-level, and only does the parsing. The application will have to
    take care of the error handling, using errorText() if parse() returns \c false.
    This can be useful for instance to show a graphical error message in graphical programs.

    Calling parse() instead of process() can also be useful in order to ignore unknown
    options temporarily, because more option definitions will be provided later on
    (depending on one of the arguments), before calling process().

    Don't forget that \a arguments must start with the name of the executable (ignored, though).

    Returns \c false in case of a parse error (unknown option or missing value); returns \c true otherwise.

    \sa process()
*/
bool QCommandLineParser::parse(const QStringList &arguments)
{
    return d->parse(arguments);
}

/*!
    Returns a translated error text for the user.
    This should only be called when parse() returns \c false.
*/
QString QCommandLineParser::errorText() const
{
    if (!d->errorText.isEmpty())
        return d->errorText;
    if (d->unknownOptionNames.size() == 1)
        return tr("Unknown option '%1'.").arg(d->unknownOptionNames.constFirst());
    if (d->unknownOptionNames.size() > 1)
        return tr("Unknown options: %1.").arg(d->unknownOptionNames.join(QStringLiteral(", ")));
    return QString();
}

#if defined(Q_OS_WIN) && !defined(QT_BOOTSTRAPPED)
// Return whether to use a message box. Use handles if a console can be obtained
// or we are run with redirected handles (for example, by QProcess).
static inline bool displayMessageBox()
{
    if (GetConsoleWindow()
        || qEnvironmentVariableIsSet("QT_COMMAND_LINE_PARSER_NO_GUI_MESSAGE_BOXES"))
        return false;
    STARTUPINFO startupInfo;
    startupInfo.cb = sizeof(STARTUPINFO);
    GetStartupInfo(&startupInfo);
    return !(startupInfo.dwFlags & STARTF_USESTDHANDLES);
}
#endif // Q_OS_WIN && !QT_BOOTSTRAPPED

/*!
    \enum QCommandLineParser::MessageType
    \since 6.9

    The enum is used to specify the type of the message and how it will be shown
    to the users.

    \value Information Used to show information messages. The message
           will be printed to \c {stdout}.
    \value Error Used to show error messages. The message will be printed
           to \c {stderr}.

    \sa showMessageAndExit()
*/

/*!
    \since 6.9

    Displays a \a message, and exits the application with the given \a exitCode.

    The \a message will usually be printed directly to \c{stdout} or \c{stderr} according
    to the given \a type, or the message may be shown in a message box under Windows when
    necessary, with an information icon or error icon according to the given \a type
    (set the \c{QT_COMMAND_LINE_PARSER_NO_GUI_MESSAGE_BOXES} environment variable if
    you don't want the message box).

    It's the same message display method used by showHelp, showVersion and the builtin
    options (\c{--version} if addVersionOption was called and \c{--help} / \c{--help-all}
    if addHelpOption was called).

    \sa addVersionOption(), showHelp(), showVersion(), QCommandLineParser::MessageType
*/
[[noreturn]] void QCommandLineParser::showMessageAndExit(MessageType type, const QString &message, int exitCode)
{
#if defined(Q_OS_WIN) && !defined(QT_BOOTSTRAPPED)
    if (displayMessageBox()) {
        const UINT flags = MB_OK | MB_TOPMOST | MB_SETFOREGROUND
            | (type == MessageType::Information ? MB_ICONINFORMATION : MB_ICONERROR);
        QString title;
        if (QCoreApplication::instance())
            title = QCoreApplication::instance()->property("applicationDisplayName").toString();
        if (title.isEmpty())
            title = QCoreApplication::applicationName();
        MessageBoxW(0, reinterpret_cast<const wchar_t *>(message.utf16()),
                    reinterpret_cast<const wchar_t *>(title.utf16()), flags);
        qt_call_post_routines();
        ::exit(exitCode);
    }
#endif // Q_OS_WIN && !QT_BOOTSTRAPPED
    fputs(qPrintable(message), type == MessageType::Information ? stdout : stderr);
    qt_call_post_routines();
    ::exit(exitCode);
}

/*!
    Processes the command line \a arguments.

    In addition to parsing the options (like parse()), this function also handles the builtin
    options and handles errors.

    The builtin options are \c{--version} if addVersionOption was called and
    \c{--help} / \c{--help-all} if addHelpOption was called.

    When invoking one of these options, or when an error happens (for instance an unknown option was
    passed), the current process will then stop, using the exit() function.

    \sa QCoreApplication::arguments(), parse()
 */
void QCommandLineParser::process(const QStringList &arguments)
{
    if (!d->parse(arguments)) {
        showMessageAndExit(MessageType::Error,
                           QCoreApplication::applicationName() + ": "_L1 + errorText() + u'\n',
                           EXIT_FAILURE);
    }

    if (d->builtinVersionOption && isSet(QStringLiteral("version")))
        showVersion();

    if (d->builtinHelpOption && isSet(QStringLiteral("help")))
        d->showHelp(EXIT_SUCCESS, false);

    if (d->builtinHelpOption && isSet(QStringLiteral("help-all")))
        d->showHelp(EXIT_SUCCESS, true);
}

/*!
    \overload

    The command line is obtained from the QCoreApplication instance \a app.
 */
void QCommandLineParser::process(const QCoreApplication &app)
{
    // QCoreApplication::arguments() is static, but the app instance must exist so we require it as parameter
    Q_UNUSED(app);
    process(QCoreApplication::arguments());
}

void QCommandLineParserPrivate::checkParsed(const char *method)
{
    if (needsParsing)
        qWarning("QCommandLineParser: call process() or parse() before %s", method);
}

/*!
    \internal
    Looks up the option \a optionName (found on the command line) and register it as found.
    Returns \c true on success.
 */
bool QCommandLineParserPrivate::registerFoundOption(const QString &optionName)
{
    if (nameHash.contains(optionName)) {
        optionNames.append(optionName);
        return true;
    } else {
        unknownOptionNames.append(optionName);
        return false;
    }
}

/*!
    \internal
    \brief Parse the value for a given option, if it was defined to expect one.

    The value is taken from the next argument, or after the equal sign in \a argument.

    \param optionName the short option name
    \param argument the argument from the command line currently parsed. Only used for -k=value parsing.
    \param argumentIterator iterator to the currently parsed argument. Incremented if the next argument contains the value.
    \param argsEnd args.end(), to check if ++argumentIterator goes out of bounds
    Returns \c true on success.
 */
bool QCommandLineParserPrivate::parseOptionValue(const QString &optionName, const QString &argument,
                                                 QStringList::const_iterator *argumentIterator, QStringList::const_iterator argsEnd)
{
    const QLatin1Char assignChar('=');
    const NameHash_t::const_iterator nameHashIt = nameHash.constFind(optionName);
    if (nameHashIt != nameHash.constEnd()) {
        const qsizetype assignPos = argument.indexOf(assignChar);
        const NameHash_t::mapped_type optionOffset = *nameHashIt;
        const QCommandLineOption &option = commandLineOptionList.at(optionOffset);
        if (option.flags() & QCommandLineOption::IgnoreOptionsAfter) {
            *argumentIterator = argsEnd;
            return true;
        }
        const bool withValue = !option.valueName().isEmpty();
        if (withValue) {
            if (assignPos == -1) {
                ++(*argumentIterator);
                if (*argumentIterator == argsEnd) {
                    errorText = QCommandLineParser::tr("Missing value after '%1'.").arg(argument);
                    return false;
                }
                optionValuesHash[optionOffset].append(*(*argumentIterator));
            } else {
                optionValuesHash[optionOffset].append(argument.mid(assignPos + 1));
            }
        } else {
            if (assignPos != -1) {
                errorText = QCommandLineParser::tr("Unexpected value after '%1'.").arg(argument.left(assignPos));
                return false;
            }
        }
    }
    return true;
}

/*!
    \internal

    Parse the list of arguments \a args, and fills in
    optionNames, optionValuesHash, unknownOptionNames, positionalArguments, and errorText.

    Any results from a previous parse operation are removed.

    The parser will not look for further options once it encounters the option
    \c{--}; this does not include when \c{--} follows an option that requires a value.
 */
bool QCommandLineParserPrivate::parse(const QStringList &args)
{
    needsParsing = false;
    bool error = false;

    const QLatin1Char dashChar('-');
    const QLatin1Char assignChar('=');

    bool forcePositional = false;
    errorText.clear();
    positionalArgumentList.clear();
    optionNames.clear();
    unknownOptionNames.clear();
    optionValuesHash.clear();

    if (args.isEmpty()) {
        qWarning("QCommandLineParser: argument list cannot be empty, it should contain at least the executable name");
        return false;
    }

    QStringList::const_iterator argumentIterator = args.begin();
    ++argumentIterator; // skip executable name

    for (; argumentIterator != args.end() ; ++argumentIterator) {
        QString argument = *argumentIterator;

        if (forcePositional) {
            positionalArgumentList.append(argument);
        } else if (argument.startsWith("--"_L1)) {
            if (argument.size() > 2) {
                QString optionName = argument.mid(2).section(assignChar, 0, 0);
                if (registerFoundOption(optionName)) {
                    if (!parseOptionValue(optionName, argument, &argumentIterator, args.end()))
                        error = true;
                } else {
                    error = true;
                }
            } else {
                forcePositional = true;
            }
        } else if (argument.startsWith(dashChar)) {
            if (argument.size() == 1) { // single dash ("stdin")
                positionalArgumentList.append(argument);
                continue;
            }
            switch (singleDashWordOptionMode) {
            case QCommandLineParser::ParseAsCompactedShortOptions:
            {
                QString optionName;
                bool valueFound = false;
                for (int pos = 1 ; pos < argument.size(); ++pos) {
                    optionName = argument.mid(pos, 1);
                    if (!registerFoundOption(optionName)) {
                        error = true;
                    } else {
                        const NameHash_t::const_iterator nameHashIt = nameHash.constFind(optionName);
                        Q_ASSERT(nameHashIt != nameHash.constEnd()); // checked by registerFoundOption
                        const NameHash_t::mapped_type optionOffset = *nameHashIt;
                        const bool withValue = !commandLineOptionList.at(optionOffset).valueName().isEmpty();
                        if (withValue) {
                            if (pos + 1 < argument.size()) {
                                if (argument.at(pos + 1) == assignChar)
                                    ++pos;
                                optionValuesHash[optionOffset].append(argument.mid(pos + 1));
                                valueFound = true;
                            }
                            break;
                        }
                        if (pos + 1 < argument.size() && argument.at(pos + 1) == assignChar)
                            break;
                    }
                }
                if (!valueFound && !parseOptionValue(optionName, argument, &argumentIterator, args.end()))
                    error = true;
                break;
            }
            case QCommandLineParser::ParseAsLongOptions:
            {
                if (argument.size() > 2) {
                    const QString possibleShortOptionStyleName = argument.mid(1, 1);
                    const auto shortOptionIt = nameHash.constFind(possibleShortOptionStyleName);
                    if (shortOptionIt != nameHash.constEnd()) {
                        const auto &arg = commandLineOptionList.at(*shortOptionIt);
                        if (arg.flags() & QCommandLineOption::ShortOptionStyle) {
                            registerFoundOption(possibleShortOptionStyleName);
                            optionValuesHash[*shortOptionIt].append(argument.mid(2));
                            break;
                        }
                    }
                }
                const QString optionName = argument.mid(1).section(assignChar, 0, 0);
                if (registerFoundOption(optionName)) {
                    if (!parseOptionValue(optionName, argument, &argumentIterator, args.end()))
                        error = true;
                } else {
                    error = true;
                }
                break;
            }
            }
        } else {
            positionalArgumentList.append(argument);
            if (optionsAfterPositionalArgumentsMode == QCommandLineParser::ParseAsPositionalArguments)
                forcePositional = true;
        }
        if (argumentIterator == args.end())
            break;
    }
    return !error;
}

/*!
    Checks whether the option \a name was passed to the application.

    Returns \c true if the option \a name was set, false otherwise.

    The name provided can be any long or short name of any option that was
    added with addOption(). All the options names are treated as being
    equivalent. If the name is not recognized or that option was not present,
    false is returned.

    Example:
    \snippet code/src_corelib_tools_qcommandlineparser.cpp 0
 */

bool QCommandLineParser::isSet(const QString &name) const
{
    d->checkParsed("isSet");
    if (d->optionNames.contains(name))
        return true;
    const QStringList aliases = d->aliases(name);
    for (const QString &optionName : std::as_const(d->optionNames)) {
        if (aliases.contains(optionName))
            return true;
    }
    return false;
}

/*!
    Returns the option value found for the given option name \a optionName, or
    an empty string if not found.

    The name provided can be any long or short name of any option that was
    added with addOption(). All the option names are treated as being
    equivalent. If the name is not recognized or that option was not present, an
    empty string is returned.

    For options found by the parser, the last value found for
    that option is returned. If the option wasn't specified on the command line,
    the default value is returned.

    If the option does not take a value, a warning is printed, and an empty string is returned.

    \sa values(), QCommandLineOption::setDefaultValue(), QCommandLineOption::setDefaultValues()
 */

QString QCommandLineParser::value(const QString &optionName) const
{
    d->checkParsed("value");
    const QStringList valueList = values(optionName);

    if (!valueList.isEmpty())
        return valueList.last();

    return QString();
}

/*!
    Returns a list of option values found for the given option name \a
    optionName, or an empty list if not found.

    The name provided can be any long or short name of any option that was
    added with addOption(). All the options names are treated as being
    equivalent. If the name is not recognized or that option was not present, an
    empty list is returned.

    For options found by the parser, the list will contain an entry for
    each time the option was encountered by the parser. If the option wasn't
    specified on the command line, the default values are returned.

    An empty list is returned if the option does not take a value.

    \sa value(), QCommandLineOption::setDefaultValue(), QCommandLineOption::setDefaultValues()
 */

QStringList QCommandLineParser::values(const QString &optionName) const
{
    d->checkParsed("values");
    auto it = d->nameHash.constFind(optionName);
    if (it != d->nameHash.cend()) {
        const qsizetype optionOffset = *it;
        QStringList values = d->optionValuesHash.value(optionOffset);
        if (values.isEmpty()) {
            const auto &option = d->commandLineOptionList.at(optionOffset);
            if (option.valueName().isEmpty()) {
                qWarning("QCommandLineParser: option not expecting values: \"%ls\"",
                         qUtf16Printable(optionName));
            }
            values = option.defaultValues();
        }
        return values;
    }

    qWarning("QCommandLineParser: option not defined: \"%ls\"", qUtf16Printable(optionName));
    return QStringList();
}

/*!
    \overload
    Checks whether the \a option was passed to the application.

    Returns \c true if the \a option was set, false otherwise.

    This is the recommended way to check for options with no values.

    Example:
    \snippet code/src_corelib_tools_qcommandlineparser.cpp 1
*/
bool QCommandLineParser::isSet(const QCommandLineOption &option) const
{
    // option.names() might be empty if the constructor failed
    const auto names = option.names();
    return !names.isEmpty() && isSet(names.first());
}

/*!
    \overload
    Returns the option value found for the given \a option, or
    an empty string if not found.

    For options found by the parser, the last value found for
    that option is returned. If the option wasn't specified on the command line,
    the default value is returned.

    An empty string is returned if the option does not take a value.

    \sa values(), QCommandLineOption::setDefaultValue(), QCommandLineOption::setDefaultValues()
*/
QString QCommandLineParser::value(const QCommandLineOption &option) const
{
    return value(option.names().constFirst());
}

/*!
    \overload
    Returns a list of option values found for the given \a option,
    or an empty list if not found.

    For options found by the parser, the list will contain an entry for
    each time the option was encountered by the parser. If the option wasn't
    specified on the command line, the default values are returned.

    An empty list is returned if the option does not take a value.

    \sa value(), QCommandLineOption::setDefaultValue(), QCommandLineOption::setDefaultValues()
*/
QStringList QCommandLineParser::values(const QCommandLineOption &option) const
{
    return values(option.names().constFirst());
}

/*!
    Returns a list of positional arguments.

    These are all of the arguments that were not recognized as part of an
    option.
 */

QStringList QCommandLineParser::positionalArguments() const
{
    d->checkParsed("positionalArguments");
    return d->positionalArgumentList;
}

/*!
    Returns a list of option names that were found.

    This returns a list of all the recognized option names found by the
    parser, in the order in which they were found. For any long options
    that were in the form {--option=value}, the value part will have been
    dropped.

    The names in this list do not include the preceding dash characters.
    Names may appear more than once in this list if they were encountered
    more than once by the parser.

    Any entry in the list can be used with value() or with
    values() to get any relevant option values.
 */

QStringList QCommandLineParser::optionNames() const
{
    d->checkParsed("optionNames");
    return d->optionNames;
}

/*!
    Returns a list of unknown option names.

    This list will include both long an short name options that were not
    recognized. For any long options that were in the form {--option=value},
    the value part will have been dropped and only the long name is added.

    The names in this list do not include the preceding dash characters.
    Names may appear more than once in this list if they were encountered
    more than once by the parser.

    \sa optionNames()
 */

QStringList QCommandLineParser::unknownOptionNames() const
{
    d->checkParsed("unknownOptionNames");
    return d->unknownOptionNames;
}

/*!
    Displays the version information from QCoreApplication::applicationVersion(),
    and exits the application.
    This is automatically triggered by the --version option, but can also
    be used to display the version when not using process().
    The exit code is set to EXIT_SUCCESS (0).

    \sa addVersionOption()
    \since 5.4
*/
Q_NORETURN void QCommandLineParser::showVersion()
{
    showMessageAndExit(MessageType::Information,
                       QCoreApplication::applicationName() + u' '
                       + QCoreApplication::applicationVersion() + u'\n',
                       EXIT_SUCCESS);
}

/*!
    Displays the help information, and exits the application.
    This is automatically triggered by the --help option, but can also
    be used to display the help when the user is not invoking the
    application correctly.
    The exit code is set to \a exitCode. It should be set to 0 if the
    user requested to see the help, and to any other value in case of
    an error.

    \sa helpText(), showMessageAndExit()
*/
Q_NORETURN void QCommandLineParser::showHelp(int exitCode)
{
    d->showHelp(exitCode, false);
}

Q_NORETURN void QCommandLineParserPrivate::showHelp(int exitCode, bool includeQtOptions)
{
    QCommandLineParser::showMessageAndExit(QCommandLineParser::MessageType::Information,
                                           helpText(includeQtOptions),
                                           exitCode);
}

/*!
    Returns a string containing the complete help information.

    \sa showHelp()
*/
QString QCommandLineParser::helpText() const
{
    return d->helpText(false);
}

static QString wrapText(const QString &names, int optionNameMaxWidth, const QString &description)
{
    const auto nl = u'\n';
    const auto indentation = "  "_L1;

    // In case the list of option names is very long, wrap it as well
    int nameIndex = 0;
    auto nextNameSection = [&]() {
        QString section = names.mid(nameIndex, optionNameMaxWidth);
        nameIndex += section.size();
        return section;
    };

    QString text;
    qsizetype lineStart = 0;
    qsizetype lastBreakable = -1;
    const int max = 79 - (indentation.size() + optionNameMaxWidth + 1);
    int x = 0;
    const qsizetype len = description.size();

    for (qsizetype i = 0; i < len; ++i) {
        ++x;
        const QChar c = description.at(i);
        if (c.isSpace())
            lastBreakable = i;

        qsizetype breakAt = -1;
        qsizetype nextLineStart = -1;
        if (x > max && lastBreakable != -1) {
            // time to break and we know where
            breakAt = lastBreakable;
            nextLineStart = lastBreakable + 1;
        } else if ((x > max - 1 && lastBreakable == -1) || i == len - 1) {
            // time to break but found nowhere [-> break here], or end of last line
            breakAt = i + 1;
            nextLineStart = breakAt;
        } else if (c == nl) {
            // forced break
            breakAt = i;
            nextLineStart = i + 1;
        }

        if (breakAt != -1) {
            const qsizetype numChars = breakAt - lineStart;
            //qDebug() << "breakAt=" << description.at(breakAt) << "breakAtSpace=" << breakAtSpace << lineStart << "to" << breakAt << description.mid(lineStart, numChars);
            text += indentation + nextNameSection().leftJustified(optionNameMaxWidth) + u' ';
            text += QStringView{description}.mid(lineStart, numChars) + nl;
            x = 0;
            lastBreakable = -1;
            lineStart = nextLineStart;
            if (lineStart < len && description.at(lineStart).isSpace())
                ++lineStart; // don't start a line with a space
            i = lineStart;
        }
    }

    while (nameIndex < names.size()) {
        text += indentation + nextNameSection() + nl;
    }

    return text;
}

QString QCommandLineParserPrivate::helpText(bool includeQtOptions) const
{
    const QLatin1Char nl('\n');
    QString text;
    QString usage;
    // executable name
    usage += qApp ? QStringView(QCoreApplication::arguments().constFirst())
                  : QStringView(u"<executable_name>");
    QList<QCommandLineOption> options = commandLineOptionList;
    if (includeQtOptions && qApp)
        qApp->d_func()->addQtOptions(&options);
    if (!options.isEmpty())
        usage += u' ' + QCommandLineParser::tr("[options]");
    for (const PositionalArgumentDefinition &arg : positionalArgumentDefinitions)
        usage += u' ' + arg.syntax;
    text += QCommandLineParser::tr("Usage: %1").arg(usage) + nl;
    if (!description.isEmpty())
        text += description + nl;
    text += nl;
    if (!options.isEmpty())
        text += QCommandLineParser::tr("Options:") + nl;

    QStringList optionNameList;
    optionNameList.reserve(options.size());
    qsizetype longestOptionNameString = 0;
    for (const QCommandLineOption &option : std::as_const(options)) {
        if (option.flags() & QCommandLineOption::HiddenFromHelp)
            continue;
        const QStringList optionNames = option.names();
        QString optionNamesString;
        for (const QString &optionName : optionNames) {
            const int numDashes = optionName.size() == 1 ? 1 : 2;
            optionNamesString += QLatin1StringView("--", numDashes) + optionName + ", "_L1;
        }
        if (!optionNames.isEmpty())
            optionNamesString.chop(2); // remove trailing ", "
        const auto valueName = option.valueName();
        if (!valueName.isEmpty())
            optionNamesString += " <"_L1 + valueName + u'>';
        optionNameList.append(optionNamesString);
        longestOptionNameString = qMax(longestOptionNameString, optionNamesString.size());
    }

    for (const PositionalArgumentDefinition &arg : positionalArgumentDefinitions)
        longestOptionNameString = qMax(longestOptionNameString, arg.name.size());

    ++longestOptionNameString;
    const int optionNameMaxWidth = qMin(50, int(longestOptionNameString));
    auto optionNameIterator = optionNameList.cbegin();
    for (const QCommandLineOption &option : std::as_const(options)) {
        if (option.flags() & QCommandLineOption::HiddenFromHelp)
            continue;
        text += wrapText(*optionNameIterator, optionNameMaxWidth, option.description());
        ++optionNameIterator;
    }
    if (!positionalArgumentDefinitions.isEmpty()) {
        if (!options.isEmpty())
            text += nl;
        text += QCommandLineParser::tr("Arguments:") + nl;
        for (const PositionalArgumentDefinition &arg : positionalArgumentDefinitions)
            text += wrapText(arg.name, optionNameMaxWidth, arg.description);
    }
    return text;
}

QT_END_NAMESPACE
