// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qloggingcategory.h"
#include "qcoreapplication.h"
#include "qreadwritelock.h"
#include "qsqldriver.h"
#include "qsqldriver_p.h"
#include "qsqldriverplugin.h"
#include "qsqlindex.h"
#include "QtCore/qapplicationstatic.h"
#include "private/qfactoryloader_p.h"
#include "private/qsqlnulldriver_p.h"
#include "qhash.h"
#include "qthread.h"

QT_BEGIN_NAMESPACE

Q_STATIC_LOGGING_CATEGORY(lcSqlDb, "qt.sql.qsqldatabase")

using namespace Qt::StringLiterals;

#define CHECK_QCOREAPPLICATION \
    if (Q_UNLIKELY(!QCoreApplication::instance())) { \
        qCWarning(lcSqlDb, "QSqlDatabase requires a QCoreApplication"); \
        return; \
    }
#define CHECK_QCOREAPPLICATION_RETVAL \
    if (Q_UNLIKELY(!QCoreApplication::instance())) { \
        qCWarning(lcSqlDb, "QSqlDatabase requires a QCoreApplication"); \
        return {}; \
    }

Q_GLOBAL_STATIC_WITH_ARGS(QFactoryLoader, loader,
                          (QSqlDriverFactoryInterface_iid, "/sqldrivers"_L1))

const char *QSqlDatabase::defaultConnection = "qt_sql_default_connection";

namespace {
    struct QtSqlGlobals
    {
        ~QtSqlGlobals();
        QSqlDatabase connection(const QString &key) const
        {
          QReadLocker locker(&lock);
          return connections.value(key);
        }
        bool connectionExists(const QString &key) const
        {
            QReadLocker locker(&lock);
            return connections.contains(key);
        }
        QStringList connectionNames() const
        {
            QReadLocker locker(&lock);
            return connections.keys();
        }
        mutable QReadWriteLock lock;
        QHash<QString, QSqlDriverCreatorBase*> registeredDrivers;
        QHash<QString, QSqlDatabase> connections;
    };
}
Q_APPLICATION_STATIC(QtSqlGlobals, s_sqlGlobals)

class QSqlDatabasePrivate
{
public:
    QSqlDatabasePrivate(QSqlDriver *dr):
        ref(1),
        driver(dr),
        port(-1)
    {
        precisionPolicy = QSql::LowPrecisionDouble;
    }
    QSqlDatabasePrivate(const QSqlDatabasePrivate &other);
    ~QSqlDatabasePrivate();
    void init(const QString& type);
    void copy(const QSqlDatabasePrivate *other);
    void disable();

    QAtomicInt ref;
    QSqlDriver* driver;
    QString dbname;
    QString uname;
    QString pword;
    QString hname;
    QString drvName;
    int port;
    QString connOptions;
    QString connName;
    QSql::NumericalPrecisionPolicy precisionPolicy;

    static QSqlDatabasePrivate *shared_null();
    static QSqlDatabase database(const QString& name, bool open);
    static void addDatabase(const QSqlDatabase &db, const QString & name);
    static void removeDatabase(const QString& name);
    static void invalidateDb(const QSqlDatabase &db, const QString &name, bool doWarn = true);
};

QSqlDatabasePrivate::QSqlDatabasePrivate(const QSqlDatabasePrivate &other) : ref(1)
{
    dbname = other.dbname;
    uname = other.uname;
    pword = other.pword;
    hname = other.hname;
    drvName = other.drvName;
    port = other.port;
    connOptions = other.connOptions;
    driver = other.driver;
    precisionPolicy = other.precisionPolicy;
    if (driver) {
        driver->setNumericalPrecisionPolicy(other.driver->numericalPrecisionPolicy());
        auto drvPriv = static_cast<QSqlDriverPrivate *>(QObjectPrivate::get(driver));
        drvPriv->connectionName = connName;
    }
}

QSqlDatabasePrivate::~QSqlDatabasePrivate()
{
    if (driver != shared_null()->driver)
        delete driver;
}

QtSqlGlobals::~QtSqlGlobals()
{
    qDeleteAll(registeredDrivers);
    for (const auto &[k, v] : std::as_const(connections).asKeyValueRange())
        QSqlDatabasePrivate::invalidateDb(v, k, false);
}

QSqlDatabasePrivate *QSqlDatabasePrivate::shared_null()
{
    static QSqlNullDriver dr;
    static QSqlDatabasePrivate n(&dr);
    return &n;
}

void QSqlDatabasePrivate::invalidateDb(const QSqlDatabase &db, const QString &name, bool doWarn)
{
    if (db.d->ref.loadRelaxed() != 1 && doWarn) {
        qCWarning(lcSqlDb, "QSqlDatabasePrivate::removeDatabase: connection '%ls' is still in use, "
                 "all queries will cease to work.", qUtf16Printable(name));
        db.d->disable();
        db.d->connName.clear();
    }
}

void QSqlDatabasePrivate::removeDatabase(const QString &name)
{
    CHECK_QCOREAPPLICATION
    QtSqlGlobals *sqlGlobals = s_sqlGlobals();
    QWriteLocker locker(&sqlGlobals->lock);

    if (!sqlGlobals->connections.contains(name))
        return;

    invalidateDb(sqlGlobals->connections.take(name), name);
}

void QSqlDatabasePrivate::addDatabase(const QSqlDatabase &db, const QString &name)
{
    CHECK_QCOREAPPLICATION
    QtSqlGlobals *sqlGlobals = s_sqlGlobals();
    QWriteLocker locker(&sqlGlobals->lock);

    if (sqlGlobals->connections.contains(name)) {
        invalidateDb(sqlGlobals->connections.take(name), name);
        qCWarning(lcSqlDb, "QSqlDatabasePrivate::addDatabase: duplicate connection name '%ls', old "
                 "connection removed.", qUtf16Printable(name));
    }
    sqlGlobals->connections.insert(name, db);
    db.d->connName = name;
    auto drvPriv = static_cast<QSqlDriverPrivate *>(QObjectPrivate::get(db.d->driver));
    drvPriv->connectionName = name;
}

/*! \internal
*/
QSqlDatabase QSqlDatabasePrivate::database(const QString& name, bool open)
{
    CHECK_QCOREAPPLICATION_RETVAL
    QSqlDatabase db = s_sqlGlobals()->connection(name);
    if (!db.isValid())
        return db;
    if (db.driver()->thread() != QThread::currentThread()) {
        qCWarning(lcSqlDb, "QSqlDatabasePrivate::database: requested database does not belong to the calling thread.");
        return QSqlDatabase();
    }

    if (open && !db.isOpen()) {
        if (!db.open())
            qCWarning(lcSqlDb) << "QSqlDatabasePrivate::database: unable to open database:" << db.lastError().text();

    }
    return db;
}


/*! \internal
    Copies the connection data from \a other.
*/
void QSqlDatabasePrivate::copy(const QSqlDatabasePrivate *other)
{
    dbname = other->dbname;
    uname = other->uname;
    pword = other->pword;
    hname = other->hname;
    drvName = other->drvName;
    port = other->port;
    connOptions = other->connOptions;
    precisionPolicy = other->precisionPolicy;
    if (driver)
        driver->setNumericalPrecisionPolicy(other->driver->numericalPrecisionPolicy());
}

void QSqlDatabasePrivate::disable()
{
    if (driver != shared_null()->driver) {
        delete driver;
        driver = shared_null()->driver;
    }
}

/*!
    \class QSqlDriverCreatorBase
    \brief The QSqlDriverCreatorBase class is the base class for
    SQL driver factories.

    \ingroup database
    \inmodule QtSql

    Reimplement createObject() to return an instance of the specific
    QSqlDriver subclass that you want to provide.

    See QSqlDatabase::registerSqlDriver() for details.

    \sa QSqlDriverCreator
*/

/*!
    \fn QSqlDriverCreatorBase::~QSqlDriverCreatorBase()

    Destroys the SQL driver creator object.
*/
QSqlDriverCreatorBase::~QSqlDriverCreatorBase()
    = default;

/*!
    \fn QSqlDriver *QSqlDriverCreatorBase::createObject() const

    Reimplement this function to returns a new instance of a
    QSqlDriver subclass.
*/

/*!
    \class QSqlDriverCreator
    \brief The QSqlDriverCreator class is a template class that
    provides a SQL driver factory for a specific driver type.

    \ingroup database
    \inmodule QtSql

    QSqlDriverCreator<T> instantiates objects of type T, where T is a
    QSqlDriver subclass.

    See QSqlDatabase::registerSqlDriver() for details.
*/

/*!
    \fn template <class T> QSqlDriver *QSqlDriverCreator<T>::createObject() const
    \reimp
*/

/*!
    \class QSqlDatabase
    \brief The QSqlDatabase class handles a connection to
    a database.

    \ingroup database

    \inmodule QtSql

    The QSqlDatabase class provides an interface for accessing a
    database through a connection. An instance of QSqlDatabase
    represents the connection. The connection provides access to the
    database via one of the \l{SQL Database Drivers#Supported
    Databases} {supported database drivers}, which are derived from
    QSqlDriver.  Alternatively, you can subclass your own database
    driver from QSqlDriver. See \l{How to Write Your Own Database
    Driver} for more information.
    A QSqlDatabase instance must only be accessed by the thread it
    was created in. Therefore you have to make sure to create them
    in the correct context. Alternatively you can change the context
    with QSqlDatabase::moveToThread().

    Create a connection (i.e., an instance of QSqlDatabase) by calling
    one of the static addDatabase() functions, where you specify
    \l{SQL Database Drivers#Supported Databases} {the driver or type
    of driver} to use (depending on the type of database)
    and a connection name. A connection is known by its own name,
    \e{not} by the name of the database it connects to. You can have
    multiple connections to one database. QSqlDatabase also supports
    the concept of a \e{default} connection, which is the unnamed
    connection. To create the default connection, don't pass the
    connection name argument when you call addDatabase().
    Subsequently, the default connection will be assumed if you call
    any static member function without specifying the connection name.
    The following snippet shows how to create and open a default connection
    to a PostgreSQL database:

    \snippet sqldatabase/sqldatabase.cpp 0

    Once the QSqlDatabase object has been created, set the connection
    parameters with setDatabaseName(), setUserName(), setPassword(),
    setHostName(), setPort(), and setConnectOptions(). Then call
    open() to activate the physical connection to the database. The
    connection is not usable until you open it.

    The connection defined above will be the \e{default} connection,
    because we didn't give a connection name to \l{QSqlDatabase::}
    {addDatabase()}. Subsequently, you can get the default connection
    by calling database() without the connection name argument:

    \snippet sqldatabase/sqldatabase.cpp 1

    QSqlDatabase is a value class. Changes made to a database
    connection via one instance of QSqlDatabase will affect other
    instances of QSqlDatabase that represent the same connection. Use
    cloneDatabase() to create an independent database connection based
    on an existing one.

    \warning It is highly recommended that you do not keep a copy of the
    QSqlDatabase around as a member of a class, as this will prevent the
    instance from being correctly cleaned up on shutdown. If you need to
    access an existing QSqlDatabase, it should be accessed with database().
    If you chose to have a QSqlDatabase member variable, this needs to be
    deleted before the QCoreApplication instance is deleted, otherwise it
    may lead to undefined behavior.

    If you create multiple database connections, specify a unique
    connection name for each one, when you call addDatabase(). Use
    database() with a connection name to get that connection. Use
    removeDatabase() with a connection name to remove a connection.
    QSqlDatabase outputs a warning if you try to remove a connection
    referenced by other QSqlDatabase objects. Use contains() to see if
    a given connection name is in the list of connections.

    \table
    \header
       \li {2,1}Some utility methods:
    \row
        \li tables()
         \li returns the list of tables
    \row
        \li primaryIndex()
        \li returns a table's primary index
    \row
        \li record()
        \li returns meta-information about a table's fields
    \row
        \li transaction()
        \li starts a transaction
    \row
        \li commit()
        \li saves and completes a transaction
    \row
        \li rollback()
        \li cancels a transaction
    \row
        \li hasFeature()
        \li checks if a driver supports transactions
    \row
        \li lastError()
        \li returns information about the last error
    \row
        \li drivers()
        \li returns the names of the available SQL drivers
    \row
        \li isDriverAvailable()
        \li checks if a particular driver is available
    \row
        \li registerSqlDriver()
        \li registers a custom-made driver
    \endtable

    \note When using transactions, you must start the
    transaction before you create your query.

    \sa QSqlDriver, QSqlQuery, {Qt SQL}, {Threads and the SQL Module}
*/

/*! \fn QSqlDatabase QSqlDatabase::addDatabase(const QString &type, const QString &connectionName)
    \threadsafe

    Adds a database to the list of database connections using the
    driver \a type and the connection name \a connectionName. If
    there already exists a database connection called \a
    connectionName, that connection is removed.

    The database connection is referred to by \a connectionName. The
    newly added database connection is returned.

    If \a type is not available or could not be loaded, isValid() returns \c false.

    If \a connectionName is not specified, the new connection becomes
    the default connection for the application, and subsequent calls
    to database() without the connection name argument will return the
    default connection. If a \a connectionName is provided here, use
    database(\a connectionName) to retrieve the connection.

    \warning If you add a connection with the same name as an existing
    connection, the new connection replaces the old one.  If you call
    this function more than once without specifying \a connectionName,
    the default connection will be the one replaced.

    Before using the connection, it must be initialized. e.g., call
    some or all of setDatabaseName(), setUserName(), setPassword(),
    setHostName(), setPort(), and setConnectOptions(), and, finally,
    open().

    \sa database(), removeDatabase(), {Threads and the SQL Module}
*/
QSqlDatabase QSqlDatabase::addDatabase(const QString &type, const QString &connectionName)
{
    QSqlDatabase db(type);
    QSqlDatabasePrivate::addDatabase(db, connectionName);
    return db;
}

/*!
    \threadsafe

    Returns the database connection called \a connectionName. The
    database connection must have been previously added with
    addDatabase(). If \a open is true (the default) and the database
    connection is not already open it is opened now. If no \a
    connectionName is specified the default connection is used. If \a
    connectionName does not exist in the list of databases, an invalid
    connection is returned.

    \sa isOpen(), {Threads and the SQL Module}
*/

QSqlDatabase QSqlDatabase::database(const QString& connectionName, bool open)
{
    return QSqlDatabasePrivate::database(connectionName, open);
}

/*!
    \threadsafe

    Removes the database connection \a connectionName from the list of
    database connections.

    \warning There should be no open queries on the database
    connection when this function is called, otherwise a resource leak
    will occur.

    Example:

    \snippet code/src_sql_kernel_qsqldatabase.cpp 0

    The correct way to do it:

    \snippet code/src_sql_kernel_qsqldatabase.cpp 1

    To remove the default connection, which may have been created with a
    call to addDatabase() not specifying a connection name, you can
    retrieve the default connection name by calling connectionName() on
    the database returned by database(). Note that if a default database
    hasn't been created an invalid database will be returned.

    \sa database(), connectionName(), {Threads and the SQL Module}
*/

void QSqlDatabase::removeDatabase(const QString& connectionName)
{
    QSqlDatabasePrivate::removeDatabase(connectionName);
}

/*!
    Returns a list of all the available database drivers.

    \sa registerSqlDriver()
*/

QStringList QSqlDatabase::drivers()
{
    CHECK_QCOREAPPLICATION_RETVAL
    QStringList list;

    if (QFactoryLoader *fl = loader()) {
        typedef QMultiMap<int, QString> PluginKeyMap;

        const PluginKeyMap keyMap = fl->keyMap();
        for (const QString &val : keyMap) {
            if (!list.contains(val))
                list << val;
        }
    }

    QtSqlGlobals *sqlGlobals = s_sqlGlobals();
    QReadLocker locker(&sqlGlobals->lock);
    const auto &dict = sqlGlobals->registeredDrivers;
    for (const auto &[k, _] : dict.asKeyValueRange()) {
        if (!list.contains(k))
            list << k;
    }

    return list;
}

/*!
    This function registers a new SQL driver called \a name, within
    the SQL framework. This is useful if you have a custom SQL driver
    and don't want to compile it as a plugin.

    Example:
    \snippet code/src_sql_kernel_qsqldatabase_snippet.cpp 2

    QSqlDatabase takes ownership of the \a creator pointer, so you
    mustn't delete it yourself.

    \sa drivers()
*/
void QSqlDatabase::registerSqlDriver(const QString& name, QSqlDriverCreatorBase *creator)
{
    CHECK_QCOREAPPLICATION
    QtSqlGlobals *sqlGlobals = s_sqlGlobals();
    QWriteLocker locker(&sqlGlobals->lock);
    delete sqlGlobals->registeredDrivers.take(name);
    if (creator)
        sqlGlobals->registeredDrivers.insert(name, creator);
}

/*!
    \threadsafe

    Returns \c true if the list of database connections contains \a
    connectionName; otherwise returns \c false.

    \sa connectionNames(), database(), {Threads and the SQL Module}
*/

bool QSqlDatabase::contains(const QString& connectionName)
{
    CHECK_QCOREAPPLICATION_RETVAL
    return s_sqlGlobals()->connectionExists(connectionName);
}

/*!
    \threadsafe

    Returns a list containing the names of all connections.

    \sa contains(), database(), {Threads and the SQL Module}
*/
QStringList QSqlDatabase::connectionNames()
{
    CHECK_QCOREAPPLICATION_RETVAL
    return s_sqlGlobals()->connectionNames();
}

/*!
    \overload

    Creates a QSqlDatabase connection that uses the driver referred
    to by \a type. If the \a type is not recognized, the database
    connection will have no functionality.

    The currently available driver types are:

    \table
    \header \li Driver Type \li Description
    \row \li QDB2     \li IBM DB2
    \row \li QIBASE   \li Borland InterBase Driver
    \row \li QMYSQL   \li MySQL Driver
    \row \li QOCI     \li Oracle Call Interface Driver
    \row \li QODBC    \li ODBC Driver (includes Microsoft SQL Server)
    \row \li QPSQL    \li PostgreSQL Driver
    \row \li QSQLITE  \li SQLite version 3 or above
    \row \li QMIMER  \li Mimer SQL 11 or above
    \endtable

    Additional third party drivers, including your own custom
    drivers, can be loaded dynamically.

    \sa {SQL Database Drivers}, registerSqlDriver(), drivers()
*/

QSqlDatabase::QSqlDatabase(const QString &type)
   : d(new QSqlDatabasePrivate(nullptr))
{
    d->init(type);
}

/*!
    \overload

    Creates a database connection using the given \a driver.
*/

QSqlDatabase::QSqlDatabase(QSqlDriver *driver)
    : d(new QSqlDatabasePrivate(driver))
{
}

/*!
    Creates an empty, invalid QSqlDatabase object. Use addDatabase(),
    removeDatabase(), and database() to get valid QSqlDatabase
    objects.
*/
QSqlDatabase::QSqlDatabase()
    : d(QSqlDatabasePrivate::shared_null())
{
    d->ref.ref();
}

/*!
    Creates a copy of \a other.
*/
QSqlDatabase::QSqlDatabase(const QSqlDatabase &other)
{
    d = other.d;
    d->ref.ref();
}

/*!
    Assigns \a other to this object.
*/
QSqlDatabase &QSqlDatabase::operator=(const QSqlDatabase &other)
{
    qAtomicAssign(d, other.d);
    return *this;
}

/*!
    \internal

    Create the actual driver instance \a type.
*/

void QSqlDatabasePrivate::init(const QString &type)
{
    CHECK_QCOREAPPLICATION
    drvName = type;

    if (!driver) {
        QtSqlGlobals *sqlGlobals = s_sqlGlobals();
        QReadLocker locker(&sqlGlobals->lock);
        const auto &dict = sqlGlobals->registeredDrivers;
        auto it = dict.find(type);
        if (it != dict.end())
            driver = it.value()->createObject();
    }

    if (!driver && loader())
        driver = qLoadPlugin<QSqlDriver, QSqlDriverPlugin>(loader(), type);

    if (!driver) {
        qCWarning(lcSqlDb,
                  "QSqlDatabase: can not load requested driver '%ls', available drivers: %ls",
                  qUtf16Printable(type), qUtf16Printable(QSqlDatabase::drivers().join(u' ')));
        if (QCoreApplication::instance() == nullptr)
            qCWarning(lcSqlDb, "QSqlDatabase: an instance of QCoreApplication is required for loading driver plugins");
        driver = shared_null()->driver;
    }
}

/*!
    Destroys the object and frees any allocated resources.

    \note When the last connection is destroyed, the destructor
    implicitly calls close() to release the database connection.

    \sa close()
*/

QSqlDatabase::~QSqlDatabase()
{
    if (!d->ref.deref()) {
        close();
        delete d;
    }
}

/*!
    Executes a SQL statement on the database and returns a QSqlQuery
    object. Use lastError() to retrieve error information. If \a
    query is empty, an empty, invalid query is returned and
    lastError() is not affected.

    \sa QSqlQuery, lastError()
    \deprecated [6.6] Use QSqlQuery::exec() instead.
*/
#if QT_DEPRECATED_SINCE(6, 6)
QSqlQuery QSqlDatabase::exec(const QString & query) const
{
    QSqlQuery r(d->driver->createResult());
    if (!query.isEmpty()) {
        r.exec(query);
        d->driver->setLastError(r.lastError());
    }
    return r;
}
#endif

/*!
    Opens the database connection using the current connection
    values. Returns \c true on success; otherwise returns \c false. Error
    information can be retrieved using lastError().

    \sa lastError(), setDatabaseName(), setUserName(), setPassword(),
        setHostName(), setPort(), setConnectOptions()
*/

bool QSqlDatabase::open()
{
    return d->driver->open(d->dbname, d->uname, d->pword, d->hname,
                            d->port, d->connOptions);
}

/*!
    \overload

    Opens the database connection using the given \a user name and \a
    password. Returns \c true on success; otherwise returns \c false. Error
    information can be retrieved using the lastError() function.

    This function does not store the password it is given. Instead,
    the password is passed directly to the driver for opening the
    connection and it is then discarded.

    \sa lastError()
*/

bool QSqlDatabase::open(const QString& user, const QString& password)
{
    setUserName(user);
    return d->driver->open(d->dbname, user, password, d->hname,
                            d->port, d->connOptions);
}

/*!
    Closes the database connection, freeing any resources acquired, and
    invalidating any existing QSqlQuery objects that are used with the
    database.

    This will also affect copies of this QSqlDatabase object.

    \sa removeDatabase()
*/

void QSqlDatabase::close()
{
    d->driver->close();
}

/*!
    Returns \c true if the database connection is currently open;
    otherwise returns \c false.
*/

bool QSqlDatabase::isOpen() const
{
    return d->driver->isOpen();
}

/*!
    Returns \c true if there was an error opening the database
    connection; otherwise returns \c false. Error information can be
    retrieved using the lastError() function.
*/

bool QSqlDatabase::isOpenError() const
{
    return d->driver->isOpenError();
}

/*!
  Begins a transaction on the database if the driver supports
  transactions. Returns \c{true} if the operation succeeded.
  Otherwise it returns \c{false}.

  \sa QSqlDriver::hasFeature(), commit(), rollback()
*/
bool QSqlDatabase::transaction()
{
    if (!d->driver->hasFeature(QSqlDriver::Transactions))
        return false;
    return d->driver->beginTransaction();
}

/*!
  Commits a transaction to the database if the driver supports
  transactions and a transaction() has been started. Returns \c{true}
  if the operation succeeded. Otherwise it returns \c{false}.

  \note For some databases, the commit will fail and return \c{false}
  if there is an \l{QSqlQuery::isActive()} {active query} using the
  database for a \c{SELECT}. Make the query \l{QSqlQuery::isActive()}
  {inactive} before doing the commit.

  Call lastError() to get information about errors.

  \sa QSqlQuery::isActive(), QSqlDriver::hasFeature(), rollback()
*/
bool QSqlDatabase::commit()
{
    if (!d->driver->hasFeature(QSqlDriver::Transactions))
        return false;
    return d->driver->commitTransaction();
}

/*!
  Rolls back a transaction on the database, if the driver supports
  transactions and a transaction() has been started. Returns \c{true}
  if the operation succeeded. Otherwise it returns \c{false}.

  \note For some databases, the rollback will fail and return
  \c{false} if there is an \l{QSqlQuery::isActive()} {active query}
  using the database for a \c{SELECT}. Make the query
  \l{QSqlQuery::isActive()} {inactive} before doing the rollback.

  Call lastError() to get information about errors.

  \sa QSqlQuery::isActive(), QSqlDriver::hasFeature(), commit()
*/
bool QSqlDatabase::rollback()
{
    if (!d->driver->hasFeature(QSqlDriver::Transactions))
        return false;
    return d->driver->rollbackTransaction();
}

/*!
    Sets the connection's database name to \a name. To have effect,
    the database name must be set \e{before} the connection is
    \l{open()} {opened}.  Alternatively, you can close() the
    connection, set the database name, and call open() again.  \note
    The \e{database name} is not the \e{connection name}. The
    connection name must be passed to addDatabase() at connection
    object create time.

    For the QSQLITE driver, if the database name specified does not
    exist, then it will create the file for you unless the
    QSQLITE_OPEN_READONLY option is set.

    Additionally, \a name can be set to \c ":memory:" which will
    create a temporary database which is only available for the
    lifetime of the application.

    For the QOCI (Oracle) driver, the database name is the TNS
    Service Name.

    For the QODBC driver, the \a name can either be a DSN, a DSN
    filename (in which case the file must have a \c .dsn extension),
    or a connection string.

    For example, Microsoft Access users can use the following
    connection string to open an \c .mdb file directly, instead of
    having to create a DSN entry in the ODBC manager:

    \snippet code/src_sql_kernel_qsqldatabase.cpp 3

    There is no default value.

    \sa databaseName(), setUserName(), setPassword(), setHostName(),
        setPort(), setConnectOptions(), open()
*/

void QSqlDatabase::setDatabaseName(const QString& name)
{
    if (isValid())
        d->dbname = name;
}

/*!
    Sets the connection's user name to \a name. To have effect, the
    user name must be set \e{before} the connection is \l{open()}
    {opened}.  Alternatively, you can close() the connection, set the
    user name, and call open() again.

    There is no default value.

    \sa userName(), setDatabaseName(), setPassword(), setHostName(),
        setPort(), setConnectOptions(), open()
*/

void QSqlDatabase::setUserName(const QString& name)
{
    if (isValid())
        d->uname = name;
}

/*!
    Sets the connection's password to \a password. To have effect, the
    password must be set \e{before} the connection is \l{open()}
    {opened}.  Alternatively, you can close() the connection, set the
    password, and call open() again.

    There is no default value.

    \warning This function stores the password in plain text within
    Qt. Use the open() call that takes a password as parameter to
    avoid this behavior.

    \sa password(), setUserName(), setDatabaseName(), setHostName(),
        setPort(), setConnectOptions(), open()
*/

void QSqlDatabase::setPassword(const QString& password)
{
    if (isValid())
        d->pword = password;
}

/*!
    Sets the connection's host name to \a host. To have effect, the
    host name must be set \e{before} the connection is \l{open()}
    {opened}.  Alternatively, you can close() the connection, set the
    host name, and call open() again.

    There is no default value.

    \sa hostName(), setUserName(), setPassword(), setDatabaseName(),
        setPort(), setConnectOptions(), open()
*/

void QSqlDatabase::setHostName(const QString& host)
{
    if (isValid())
        d->hname = host;
}

/*!
    Sets the connection's port number to \a port. To have effect, the
    port number must be set \e{before} the connection is \l{open()}
    {opened}.  Alternatively, you can close() the connection, set the
    port number, and call open() again..

    There is no default value.

    \sa port(), setUserName(), setPassword(), setHostName(),
        setDatabaseName(), setConnectOptions(), open()
*/

void QSqlDatabase::setPort(int port)
{
    if (isValid())
        d->port = port;
}

/*!
    Returns the connection's database name, which may be empty.
    \note The database name is not the connection name.

    \sa setDatabaseName()
*/
QString QSqlDatabase::databaseName() const
{
    return d->dbname;
}

/*!
    Returns the connection's user name; it may be empty.

    \sa setUserName()
*/
QString QSqlDatabase::userName() const
{
    return d->uname;
}

/*!
    Returns the connection's password. An empty string will be returned
    if the password was not set with setPassword(), and if the password
    was given in the open() call, or if no password was used.
*/
QString QSqlDatabase::password() const
{
    return d->pword;
}

/*!
    Returns the connection's host name; it may be empty.

    \sa setHostName()
*/
QString QSqlDatabase::hostName() const
{
    return d->hname;
}

/*!
    Returns the connection's driver name.

    \sa addDatabase(), driver()
*/
QString QSqlDatabase::driverName() const
{
    return d->drvName;
}

/*!
    Returns the connection's port number. The value is undefined if
    the port number has not been set.

    \sa setPort()
*/
int QSqlDatabase::port() const
{
    return d->port;
}

/*!
    Returns the database driver used to access the database
    connection.

    \sa addDatabase(), drivers()
*/

QSqlDriver* QSqlDatabase::driver() const
{
    return d->driver;
}

/*!
    Returns information about the last error that occurred on the
    database.

    Failures that occur in conjunction with an individual query are
    reported by QSqlQuery::lastError().

    \sa QSqlError, QSqlQuery::lastError()
*/

QSqlError QSqlDatabase::lastError() const
{
    return d->driver->lastError();
}


/*!
    Returns a list of the database's tables, system tables and views,
    as specified by the parameter \a type.

    \sa primaryIndex(), record()
*/

QStringList QSqlDatabase::tables(QSql::TableType type) const
{
    return d->driver->tables(type);
}

/*!
    Returns the primary index for table \a tablename. If no primary
    index exists, an empty QSqlIndex is returned.

    \note Some drivers, such as the \l {QPSQL Case Sensitivity}{QPSQL}
    driver, may may require you to pass \a tablename in lower case if
    the table was not quoted when created. See the
    \l{sql-driver.html}{Qt SQL driver} documentation for more information.

    \sa tables(), record()
*/

QSqlIndex QSqlDatabase::primaryIndex(const QString& tablename) const
{
    return d->driver->primaryIndex(tablename);
}


/*!
    Returns a QSqlRecord populated with the names of all the fields in
    the table (or view) called \a tablename. The order in which the
    fields appear in the record is undefined. If no such table (or
    view) exists, an empty record is returned.

    \note Some drivers, such as the \l {QPSQL Case Sensitivity}{QPSQL}
    driver, may may require you to pass \a tablename in lower case if
    the table was not quoted when created. See the
    \l{sql-driver.html}{Qt SQL driver} documentation for more information.
*/

QSqlRecord QSqlDatabase::record(const QString& tablename) const
{
    return d->driver->record(tablename);
}


/*!
    Sets database-specific \a options. This must be done before the
    connection is opened, otherwise it has no effect. Another possibility
    is to close the connection, call QSqlDatabase::setConnectOptions(),
    and open() the connection again.

    The format of the \a options string is a semicolon separated list
    of option names or option=value pairs. The options depend on the
    database client used and are described for each plugin in the
    \l{sql-driver.html}{SQL Database Drivers} page.

    Examples:
    \snippet code/src_sql_kernel_qsqldatabase.cpp 4

    Refer to the client library documentation for more information
    about the different options.

    \sa connectOptions()
*/

void QSqlDatabase::setConnectOptions(const QString &options)
{
    if (isValid())
        d->connOptions = options;
}

/*!
    Returns the connection options string used for this connection.
    The string may be empty.

    \sa setConnectOptions()
 */
QString QSqlDatabase::connectOptions() const
{
    return d->connOptions;
}

/*!
    Returns \c true if a driver called \a name is available; otherwise
    returns \c false.

    \sa drivers()
*/

bool QSqlDatabase::isDriverAvailable(const QString& name)
{
    return drivers().contains(name);
}

/*! \fn QSqlDatabase QSqlDatabase::addDatabase(QSqlDriver* driver, const QString& connectionName)
    \overload

    This overload is useful when you want to create a database
    connection with a \l{QSqlDriver} {driver} you instantiated
    yourself. It might be your own database driver, or you might just
    need to instantiate one of the Qt drivers yourself. If you do
    this, it is recommended that you include the driver code in your
    application. For example, you can create a PostgreSQL connection
    with your own QPSQL driver like this:

    \snippet code/src_sql_kernel_qsqldatabase_snippet.cpp 6

    The above code sets up a PostgreSQL connection and instantiates a
    QPSQLDriver object. Next, addDatabase() is called to add the
    connection to the known connections so that it can be used by the
    Qt SQL classes. When a driver is instantiated with a connection
    handle (or set of handles), Qt assumes that you have already
    opened the database connection.

    \note We assume that \c qtdir is the directory where Qt is
    installed. This will pull in the code that is needed to use the
    PostgreSQL client library and to instantiate a QPSQLDriver object,
    assuming that you have the PostgreSQL headers somewhere in your
    include search path.

    Remember that you must link your application against the database
    client library. Make sure the client library is in your linker's
    search path, and add lines like these to your \c{.pro} file:

    \snippet code/src_sql_kernel_qsqldatabase_snippet.cpp 7

    The method described works for all the supplied drivers.  The only
    difference will be in the driver constructor arguments.  Here is a
    table of the drivers included with Qt, their source code files,
    and their constructor arguments:

    \table
    \header \li Driver \li Class name \li Constructor arguments \li File to include
    \row
    \li QPSQL
    \li QPSQLDriver
    \li PGconn *connection
    \li \c qsql_psql.cpp
    \row
    \li QMYSQL
    \li QMYSQLDriver
    \li MYSQL *connection
    \li \c qsql_mysql.cpp
    \row
    \li QOCI
    \li QOCIDriver
    \li OCIEnv *environment, OCISvcCtx *serviceContext
    \li \c qsql_oci.cpp
    \row
    \li QODBC
    \li QODBCDriver
    \li SQLHANDLE environment, SQLHANDLE connection
    \li \c qsql_odbc.cpp
    \row
    \li QDB2
    \li QDB2
    \li SQLHANDLE environment, SQLHANDLE connection
    \li \c qsql_db2.cpp
    \row
    \li QSQLITE
    \li QSQLiteDriver
    \li sqlite *connection
    \li \c qsql_sqlite.cpp
    \row
    \li QMIMER
    \li QMimerSQLDriver
    \li MimerSession *connection
    \li \c qsql_mimer.cpp
    \row
    \li QIBASE
    \li QIBaseDriver
    \li isc_db_handle connection
    \li \c qsql_ibase.cpp
    \endtable

    \warning Adding a database connection with the same connection
    name as an existing connection, causes the existing connection to
    be replaced by the new one.

    \warning The SQL framework takes ownership of the \a driver. It
    must not be deleted. To remove the connection, use
    removeDatabase().

    \sa drivers()
*/
QSqlDatabase QSqlDatabase::addDatabase(QSqlDriver* driver, const QString& connectionName)
{
    QSqlDatabase db(driver);
    QSqlDatabasePrivate::addDatabase(db, connectionName);
    return db;
}

/*!
    Returns \c true if the QSqlDatabase has a valid driver.

    Example:
    \snippet code/src_sql_kernel_qsqldatabase.cpp 8
*/
bool QSqlDatabase::isValid() const
{
    return d->driver && d->driver != d->shared_null()->driver;
}

/*!
    Clones the database connection \a other and stores it as \a
    connectionName. All the settings from the original database, e.g.
    databaseName(), hostName(), etc., are copied across. Does nothing
    if \a other is an invalid database. Returns the newly created
    database connection.

    \note The new connection has not been opened. Before using the new
    connection, you must call open().

    \reentrant
*/
QSqlDatabase QSqlDatabase::cloneDatabase(const QSqlDatabase &other, const QString &connectionName)
{
    if (!other.isValid())
        return QSqlDatabase();

    QSqlDatabase db(other.driverName());
    db.d->copy(other.d);
    QSqlDatabasePrivate::addDatabase(db, connectionName);
    return db;
}

/*!
    \since 5.13
    \overload

    Clones the database connection \a other and stores it as \a
    connectionName. All the settings from the original database, e.g.
    databaseName(), hostName(), etc., are copied across. Does nothing
    if \a other is an invalid database. Returns the newly created
    database connection.

    \note The new connection has not been opened. Before using the new
    connection, you must call open().

    This overload is useful when cloning the database in another thread to the
    one that is used by the database represented by \a other.
*/

QSqlDatabase QSqlDatabase::cloneDatabase(const QString &other, const QString &connectionName)
{
    CHECK_QCOREAPPLICATION_RETVAL
    return cloneDatabase(s_sqlGlobals()->connection(other), connectionName);
}

/*!
    Returns the connection name, which may be empty.  \note The
    connection name is not the \l{databaseName()} {database name}.

    \sa addDatabase()
*/
QString QSqlDatabase::connectionName() const
{
    return d->connName;
}

/*!
    \property QSqlDatabase::numericalPrecisionPolicy
    \since 6.8

    This property holds the default numerical precision policy used by
    queries created on this database connection.

    Note: Drivers that don't support fetching numerical values with low
    precision will ignore the precision policy. You can use
    QSqlDriver::hasFeature() to find out whether a driver supports this
    feature.

    Note: Setting the default precision policy to \a precisionPolicy
    doesn't affect any currently active queries.

    \sa QSql::NumericalPrecisionPolicy, QSqlQuery::numericalPrecisionPolicy,
        QSqlDriver::numericalPrecisionPolicy
*/
/*!
    Sets \l numericalPrecisionPolicy to \a precisionPolicy.
 */
void QSqlDatabase::setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy precisionPolicy)
{
    if (driver())
        driver()->setNumericalPrecisionPolicy(precisionPolicy);
    d->precisionPolicy = precisionPolicy;
}

/*!
    Returns the \l numericalPrecisionPolicy.
*/
QSql::NumericalPrecisionPolicy QSqlDatabase::numericalPrecisionPolicy() const
{
    if (driver())
        return driver()->numericalPrecisionPolicy();
    else
        return d->precisionPolicy;
}

/*!
    \since 6.8

    Changes the thread affinity for QSqlDatabase and its associated driver.
    This function returns \c true when the function succeeds. Event processing
    will continue in the \a targetThread.

    During this operation you have to make sure that there is no QSqlQuery
    bound to this instance otherwise the QSqlDatabase will not be moved to
    the given thread and the function returns \c false.

    Since the associated driver is derived from QObject, all constraints for
    moving a QObject to another thread also apply to this function.

    \sa QObject::moveToThread(), {Threads and the SQL Module}
*/
bool QSqlDatabase::moveToThread(QThread *targetThread)
{
    if (auto drv = driver()) {
        if (drv != QSqlDatabasePrivate::shared_null()->driver) {
            // two instances are alive - the one here and the one in dbDict()
            if (d->ref.loadRelaxed() > 2) {
                qWarning("QSqlDatabasePrivate::moveToThread: connection '%ls' is still in use "
                         "in the current thread.", qUtf16Printable(d->connName));
                return false;
            }
            return drv->moveToThread(targetThread);
        }
    }
    return false;
}

/*!
    \since 6.8

    Returns a pointer to the associated QThread instance.
*/
QThread *QSqlDatabase::thread() const
{
    if (auto drv = driver())
        return drv->thread();
    return nullptr;
}


#ifndef QT_NO_DEBUG_STREAM
QDebug operator<<(QDebug dbg, const QSqlDatabase &d)
{
    QDebugStateSaver saver(dbg);
    dbg.nospace();
    dbg.noquote();
    if (!d.isValid()) {
        dbg << "QSqlDatabase(invalid)";
        return dbg;
    }

    dbg << "QSqlDatabase(driver=\"" << d.driverName() << "\", database=\""
        << d.databaseName() << "\", host=\"" << d.hostName() << "\", port=" << d.port()
        << ", user=\"" << d.userName() << "\", open=" << d.isOpen() << ')';
    return dbg;
}
#endif

QT_END_NAMESPACE

#include "moc_qsqldatabase.cpp"
