"""
stk/db/db_common.py
-------------------

Common function label database tables declarations

 ADAS_DB


:org:           Continental AG
:author:        Dominik Froehlich

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:48CET $
"""

# pylint: disable=E1101,E1103,C0103,R0201,W0201

# Import Python Modules -------------------------------------------------------
from os import path, stat, chmod
from stat import ST_MODE, S_IWRITE
from datetime import datetime
from time import timezone
from re import compile as reComp
from platform import release
import logging as log

try:
    from cx_Oracle import connect as cxConnect  # pylint: disable=W0611
except:  # pylint: disable=W0702
    cxConnect = None
from pyodbc import connect as pyConnect  # pylint: disable=W0611
from adodbapi import connect as adoConnect
from sqlite3 import connect as sqConnect

# Import STK Modules ----------------------------------------------------------
from stk.db.db_sql import GenericSQLStatementFactory, SQLColumnExpr, SQLDate, SQLBinaryExpr, OP_EQ, SQLLiteral, \
    SQLFuncExpr, SQLListExpr, SCHEMA_PREFIX_SEPARATOR, TABLE_PREFIX_SEPARATOR


# Defines ------------------------------------------------------------------------------------------------------------
DEFAULT_MASTER_SCHEMA_PREFIX = None
DEFAULT_MASTER_DSN = None  # CLEO is not used for Oracle 11g
DEFAULT_MASTER_DBQ = "racadmpe"  # use sqlnet.ora and ldap.ora instead of "lidb003:1521/cleo"
DEFAULT_MASTER_DRV_XP = "Oracle in instantclient11_1"  # Released for WinXP
DEFAULT_MASTER_DRV_W7 = "Oracle in instantclient_11_2" # Released for Win7 
DEFAULT_SLAVE_DATA_PROVIDER_XP = "Microsoft.SQLSERVER.MOBILE.OLEDB.3.0"     # Released for WinXP
DEFAULT_SLAVE_DATA_PROVIDER_W7 = "Microsoft.SQLSERVER.CE.OLEDB.3.5"         # Released for Win7 

if release() == 'XP':
    DEFAULT_MASTER_DRV = DEFAULT_MASTER_DRV_XP
    DEFAULT_SLAVE_DATA_PROVIDER = DEFAULT_SLAVE_DATA_PROVIDER_XP
else:
    DEFAULT_MASTER_DRV = DEFAULT_MASTER_DRV_W7
    DEFAULT_SLAVE_DATA_PROVIDER = DEFAULT_SLAVE_DATA_PROVIDER_W7

DEFAULT_DATETIME_FORMAT = "%Y-%m-%d %H:%M:%S"

ERROR_TOLERANCE_NONE = 0
ERROR_TOLERANCE_LOW = 1
ERROR_TOLERANCE_MED = 2
ERROR_TOLERANCE_HIGH = 3

DB_FUNC_NAME_MIN = "DB_FUNC_NAME_MIN"
DB_FUNC_NAME_MAX = "DB_FUNC_NAME_MAX"
DB_FUNC_NAME_AVG = "DB_FUNC_NAME_AVG"
DB_FUNC_NAME_LOWER = "DB_FUNC_NAME_LOWER"
DB_FUNC_NAME_UPPER = "DB_FUNC_NAME_UPPER"
DB_FUNC_NAME_GETDATE = 'DB_FUNC_NAME_GETDATE'

# Common Tables
TABLE_NAME_VERSION = "Versions"

COL_NAME_SUBSCHEMEPREF = "SUBSCHEMEPREF"
COL_NAME_SUBSCHEMEVERSION = "SUBSCHEMEVERSION"

# Roles
ROLE_DB_ADMIN = "ADMIN"
ROLE_DB_USER = "USER"

LAST_ROWID = ";SELECT last_insert_rowid()"

SQLITE_FILE_EXT = (".db", ".sqlite",)
SDF_FILE_EXT = (".sdf",)
# Functions -------------------------------------------------------------------


# Classes ------------------------------------------------------------------------------------------------------------

# try:
#     from exceptions import StandardError as _BaseException
# except ImportError:
#     # py3k
#     _BaseException = Exception


class AdasDBError(StandardError):
    """Base of all ConstraintDatabase errors"""
    pass


class AdasDBNotImplemented(AdasDBError):
    """Feature is not implemented"""
    pass


class BaseDB():  # pylint: disable=R0902
    """Base implementation of the Database Interface"""

    #====================================================================
    # Handling of database
    #====================================================================

    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(), strIdent=""):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        self.table_prefix = table_prefix
        # connect to DB if db_connection is of type string, otherwise take over connection as usual
        self.db_connection = self._connect(db_connection) if type(db_connection) == str else db_connection
        self.sql_factory = sql_factory
        self.db_func_map = {}
        self.date_time_format = DEFAULT_DATETIME_FORMAT
        self.sub_scheme_version = None
        self.role = None
        self._strIdent = strIdent

        # used by execute() to extend table names with table prefixes
        self._tablePrefix = table_prefix
        self._tableRepl = reComp(r"(?P<name>(?i)\b(?<!')(((C(AT|L)|EBA|ENV|FCT|G(EN|BL)|OBJ|PAR|SIM|VAL)_)[_a-zA-Z]{4,}|"
                                 r"((MFC(3(00|D0)|400)|CSF2(00|65|XX))_[a-zA-Z]{2,4}_(CD|LD(ROI|SS))))\b)")
        self._funcParams = reComp(r"(\(.*\))")

    @property
    def strIdent(self):
        """return my own ident
        """
        return self._strIdent

    def _connect(self, connectionString):
        """connect to DB
        :param connectionString: full connection string
        :return: read made connection
        """
        cslower = connectionString.lower()
        if cslower.endswith(SQLITE_FILE_EXT) and path.isfile(connectionString) or cslower == ":memory:":
            try:
                if (not stat(connectionString)[ST_MODE] & S_IWRITE):
                    chmod(connectionString, S_IWRITE)
            except:  # pylint: disable=W0702
                pass
            return sqConnect(connectionString)
        elif cslower.startswith('data source=') and cslower.endswith(SDF_FILE_EXT):
            fn = connectionString[cslower.find("data source=") + 12:].partition(";")[0].strip()
            if (not stat(fn)[ST_MODE] & S_IWRITE):
                chmod(fn, S_IWRITE)
            return adoConnect(connectionString)
        else:
            # ex: DRIVER={Oracle in instantclient_11_2};DBQ=racadmpe;Uid=DEV_MFC31X_ADMIN;Pwd=MFC31X_ADMIN
            # init argument part, split up and use it for cxConnect
            if cxConnect is not None and "dbq" in cslower:
                argPart = {}
                for arg in connectionString.split(';'):
                    pPart = arg.split('=', 2)
                    argPart[pPart[0].strip().lower()] = pPart[1].strip()
                return cxConnect(argPart['uid'], argPart['pwd'], argPart['dbq'])
            else:
                return pyConnect(connectionString)


    def Initialize(self):
        """Initialize the database proxy"""
        pass

    def Terminate(self):
        """Terminate the database proxy"""
        if self.db_connection is not None:
            self.db_connection.close()

    def Commit(self):
        """Commit the pending transactions"""
        self.db_connection.commit()

    def Rollback(self):
        """Rollback the pending transactions"""
        self.db_connection.rollback()

    def Cursor(self):
        """Get the current cursor of DB: only use it if you *really* know what you're doing!!!
        """
        return self.db_connection.cursor()

    #====================================================================
    # Handling of generic data.
    #====================================================================

    def SelectGenericData(self, select_list=["*"], table_list=None, # pylint: disable-msg=W0102,R0913,R0914
                          where=None, group_by=None, having=None, order_by=None, distinct_rows=False):
        """Select generic data from a table.
        :param select_list: List of selected table columns.
        :param table_list: List of table names from which to select data.
        :param where: The additional condition that must hold for the scenarios to be returned.
        :param group_by: Expression defining the columns by which selected data is grouped.
        :param having: Expression defining the conditions that determine groups.
        :param order_by: Expression that defines the order of the returned records.
        :param distinct_rows: Set True, if only distinct rows shall be returned.
        :return: Returns the list of selected data.
        """
        record_list = []
        sql_select_stmt = self.sql_factory.GetSelectBuilder()
        sql_select_stmt.select_list = select_list
        sql_select_stmt.table_list = table_list
        sql_select_stmt.where_condition = where
        sql_select_stmt.group_by_list = group_by
        sql_select_stmt.having_condition = having
        sql_select_stmt.order_by_list = order_by
        sql_select_stmt.distinct_rows = distinct_rows
        stmt = str(sql_select_stmt)
        # fetch data
        cursor = self.db_connection.cursor()
        try:
            log.debug(stmt)
            cursor.execute(stmt)
            rows = cursor.fetchall()
            for row in rows:
                colindex = 0
                columns = {}
                for column in cursor.description:
                    columns[column[0].upper()] = row[colindex]
                    colindex = colindex + 1
                record_list.append(columns)
        except:
            log.error(stmt)
            raise
        finally:
            cursor.close()
        # done
        return record_list

    def SelectGenericDataCompact(self, select_list=["*"], table_list=None, # pylint: disable-msg=W0102,R0913,R0914
                                 where=None, group_by=None, having=None, order_by=None, distinct_rows=False):
        """Select generic data from a table.
        :param select_list: List of selected table columns.
        :param table_list: List of table names from which to select data.
        :param where: The additional condition that must hold for the scenarios to be returned.
        :param group_by: Expression defining the columns by which selected data is grouped.
        :param having: Expression defining the conditions that determine groups.
        :param order_by: Expression that defines the order of the returned records.
        :param distinct_rows: Set True, if only distinct rows shall be returned.
        :return: Returns the list of selected data.
        """
        sql_select_stmt = self.sql_factory.GetSelectBuilder()
        sql_select_stmt.select_list = select_list
        sql_select_stmt.table_list = table_list
        sql_select_stmt.where_condition = where
        sql_select_stmt.group_by_list = group_by
        sql_select_stmt.having_condition = having
        sql_select_stmt.order_by_list = order_by
        sql_select_stmt.distinct_rows = distinct_rows
        stmt = str(sql_select_stmt)
        # fetch data
        cursor = self.db_connection.cursor()
        try:
            log.debug(stmt)
            cursor.execute(stmt)
            rows = cursor.fetchall()
            field_list = []
            for column in cursor.description:
                field_list.append(column[0].upper())

        except:
            log.error(stmt)
            raise
        finally:
            cursor.close()

        # If the select is just for one column, cursor produces bad results.
        row_list = []
        if len(select_list) == 1 and select_list[0] != "*":
            for row in rows:
                item = []
                item.append(row[0])
                row_list.append(item)
        else:
            row_list = rows

        # done
        return [field_list, row_list]

    def AddGenericData(self, record, table_name):
        """Add generic data to database.
        :param record: The data record to be added to the database.
        :param table_name: The name of the table into which to add the data.
        """
        # build statement
        rowcount = 0
        sql_insert_stmt = self.sql_factory.GetInsertBuilder()
        sql_insert_stmt.table_name = table_name
        sql_insert_stmt.assign_items = record
        stmt = str(sql_insert_stmt)
        # insert data
        cursor = self.db_connection.cursor()
        try:
            log.debug(stmt)
            cursor.execute(stmt)
            # rowcount = cursor.rowcount
        except Exception, ex:
            log.error(stmt)
            log.error(str(ex))
            raise
        finally:
            cursor.close()
        return rowcount

    def UpdateGenericData(self, record, table_name, where=None):
        """Update an existing record in the database.
        :param record: The data to be updated.
        :param where: The condition to be fulfilled by the states to be updated.
        :return: Returns the number of affected rows.
        """
        sql_update_stmt = self.sql_factory.GetUpdateBuilder()
        sql_update_stmt.table_name = table_name
        sql_update_stmt.assign_items = record
        sql_update_stmt.where_condition = where
        stmt = str(sql_update_stmt)
        # update data
        rowcount = 0
        cursor = self.db_connection.cursor()
        try:
            log.debug(stmt)
            cursor.execute(stmt)
            # rowcount = cursor.rowcount
        except:
            log.error(stmt)
            raise
        finally:
            cursor.close()
        # done
        return rowcount

    def DeleteGenericData(self, table_name, where=None):
        """Delete records from a table.
        :param table_name: The name of the table to deleted the data from.
        :param where: The condition to be fulfilled by the states to be deleted.
        :return: Returns the number of affected rows.
        """
        sql_stmt = self.sql_factory.GetDeleteBuilder()
        sql_stmt.table_name = table_name
        sql_stmt.where_condition = where
        stmt = str(sql_stmt)
        # delete data
        rowcount = 0
        cursor = self.db_connection.cursor()
        try:
            log.debug(stmt)
            cursor.execute(stmt)
            # rowcount = cursor.rowcount      #was commented out, but e.g. used in cgeb_fctlabel -> ?
        except:
            log.error(stmt)
            raise AdasDBError()
        finally:
            cursor.close()
        # done
        return rowcount

    def execute(self, statement, incDesc=False):
        """Execute SQL statement(s). Multiple statements can be semicolon (;) separated
        :param statement: SQL query, supported statements: select, insert, update, delete, execute
        :param incDesc: include the description when doing a select as first row
        :return: returns all rows
        """

        if self._tablePrefix is not None:
            statement = self._tableRepl.sub(self._tablePrefix + r"\g<name>", statement)

        try:
            records = []
            cursor = self.db_connection.cursor()

            for stmt in statement.split(';'):
                if len(stmt) == 0:
                    continue

                log.debug(stmt)

                kw = stmt.split(' ', 1)[0].lower()

                cursor.execute(stmt)

                if kw in ("select", "pragma"):
                    if isinstance(records, int):
                        records = int(cursor.fetchone()[0])
                    else:
                        records = cursor.fetchall()
                        if incDesc:
                            records.insert(0, [desc[0] for desc in cursor.description])
                elif kw == "execute":
                    # remove 'execute ', find & remove brackets, split args, strip quotes and recombine
                    params = [ii.strip(" '") for ii in self._funcParams.findall(stmt[8:])[0].strip('()').split(',')]
                    records = cursor.callproc(stmt[0:stmt.find('(')].strip(), params)
                else:
                    records = cursor.rowcount
                    self.db_connection.commit()

        except Exception, ex:
            raise AdasDBError(stmt + ": " + str(ex))
        finally:
            cursor.close()

        # done
        return records

    #====================================================================
    # Table handling
    #====================================================================

    def GetQualifiedTableName(self, table_base_name):
        """Create the name of a table from its base name
        :param table_base_name: The base name of the table
        :return: Returns the full table name
        """
        table_name = table_base_name

        if self.table_prefix is not None:
            self.table_prefix = self.table_prefix.strip()
            if len(self.table_prefix) > 0:
                table_name = self.table_prefix + table_name
        # done
        return table_name

    #====================================================================
    # Conversion methods
    #====================================================================

    def ConvertTimestampToDate(self, timestamp):
        """ Convert a timestamp to a date-time of the database
        :param timestamp: The timestamp to convert
        :return: Returns the date-time expression
        """
        return SQLDate(datetime.fromtimestamp(timestamp).strftime(self.date_time_format))

    #====================================================================
    # Version methods
    #====================================================================

    def GetSubSchemeVersion(self, SubSchemeTag):
        """ Returns the version number of the component
        :param SubSchemeTag: Name of the subscheme
        """

        cond = SQLBinaryExpr(COL_NAME_SUBSCHEMEPREF, OP_EQ, SQLLiteral(SubSchemeTag))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VERSION)], where=cond)

        if len(entries) == 1:
            return entries[0][COL_NAME_SUBSCHEMEVERSION]
        else:
            raise AdasDBError("Cannot Resolve Version number of the componenent '%s' from table '%s' cannot be \
                               resolved because it is ambiguous." % (SubSchemeTag, TABLE_NAME_VERSION))


#====================================================================
# Interface helper functions
#====================================================================


class OracleBaseDB():
    """Oracle Implementation of rec file DB access
    """

    def __init__(self):
        """ Initialize Oracle Specific Database
        """
        self._dbType = "oracle"
        self._dbSpecifics = {"datetime": "SELECT TO_CHAR(systimestamp at time zone 'utc', 'YYYY-MM-DD "
                                         "HH24:MI:SS') AS DateTime FROM SYS.dual",
                             "tables": "SELECT TABLE_NAME AS NAME FROM ALL_TABLES WHERE TABLE_NAME LIKE "
                                       "'CL/_%' ESCAPE '/' ORDER BY TABLE_NAME"}
        # self.date_time_format = "%d.%m.%Y %H:%M:%S"

    def Initialize(self):
        """ Setup function names """
        self.db_func_map[DB_FUNC_NAME_MIN] = "MIN"
        self.db_func_map[DB_FUNC_NAME_MAX] = "MAX"
        self.db_func_map[DB_FUNC_NAME_LOWER] = "LOWER"
        self.db_func_map[DB_FUNC_NAME_UPPER] = "UPPER"
        self.SetCurrentUserRole()

    def GetCurrDateTimeExpr(self):
        """Get expression that returns current date/time of database"""
        return SQLColumnExpr(None, "CURRENT_DATE")

    def GetCurrDateTime(self):
        """Get the current date/time of the database.
        :return: Returns the current date time of the database
        """
        db_datetime = None
        sql_select_stmt = self.sql_factory.GetSelectBuilder()
        sql_select_stmt.select_list = [self.GetCurrDateTimeExpr()]
        sql_select_stmt.table_list = ["DUAL"]
        stmt = str(sql_select_stmt)
        cursor = self.db_connection.cursor()
        try:
            log.debug(stmt)
            cursor.execute(stmt)
            db_datetime = cursor.fetchone()[0]
        finally:
            cursor.close()
        # done
        return db_datetime

    def ConvertTimestampToDate(self, timestamp):
        """ Convert a timestamp to a date-time of the database
        :param timestamp: The timestamp to convert
        :return: Returns the date-time expression
        """
        exp = SQLDate(datetime.fromtimestamp(timestamp).strftime(self.date_time_format))
        return SQLFuncExpr("TO_DATE", SQLListExpr([exp, "'DD.MM.YYYY HH24:MI:SS'"]))

    def GetConnectString(self, dbdsn, dbdbq, dbuser, dbpassword, dbdriver=DEFAULT_MASTER_DRV):
        """Build the connection string for Oracle 11g"""
        connect_str = ""
        if dbdsn is not None:
            connect_str = "DSN=%s;" % dbdsn
        else:
            connect_str = "DRIVER={%s};" % dbdriver
        if dbdbq is not None:
            connect_str = connect_str + "DBQ=%s;" % dbdbq
        if dbuser is not None:
            connect_str = connect_str + "Uid=%s;" % dbuser
        if dbpassword is not None:
            connect_str = connect_str + "Pwd=%s;" % dbpassword
        return connect_str

    def SetCurrentUserRole(self):
        """ sets the role of current user """
        username = None
        stmt = "SELECT sys_context('USERENV', 'SESSION_USER') FROM dual"
        cursor = self.db_connection.cursor()

        try:
            log.debug(stmt)
            cursor.execute(stmt)
            username = cursor.fetchone()[0]
        finally:
            cursor.close()
        if username is not None:
            if ROLE_DB_ADMIN.lower() in username.lower():
                self.role = ROLE_DB_ADMIN
            else:
                self.role = ROLE_DB_USER

#====================================================================
# Constraint DB Libary SQL Server Compact Implementation
#====================================================================


class SQLCEBaseDB():
    """SQL Server Compact Edition Implementation of rec file DB access"""
    def __init__(self):
        """Initialize SQL Server Compact Edition Database
        """
        self._dbType = "sqlCE"
        self._dbSpecifics = {"datetime": "SELECT CONVERT(NVARCHAR(19), DATEADD(hour, %d, GETDATE()), 120) "
                                         "AS DateTime" % (timezone / 3600),
                             "tables": "SELECT TABLE_NAME AS NAME FROM information_schema.tables WHERE "
                                       "(TABLE_TYPE LIKE 'TABLE' AND TABLE_NAME LIKE 'CL/_%' ESCAPE '/') "
                                       "ORDER BY TABLE_NAME"}

    def Initialize(self):
        """ Setup function names """
        self.db_func_map[DB_FUNC_NAME_MIN] = "MIN"
        self.db_func_map[DB_FUNC_NAME_MAX] = "MAX"
        self.db_func_map[DB_FUNC_NAME_LOWER] = "LOWER"
        self.db_func_map[DB_FUNC_NAME_UPPER] = "UPPER"

    def GetCurrDateTime(self):
        """Get the current date/time of the database.
        :return: Returns the current date time of the database
        """
        db_datetime = None
        sql_select_stmt = self.sql_factory.GetSelectBuilder()
        sql_select_stmt.select_list = [self.GetCurrDateTimeExpr()]
        # sql_select_stmt.table_list = ["DUAL"]
        stmt = str(sql_select_stmt)
        cursor = self.db_connection.cursor()
        try:
            log.debug(stmt)
            cursor.execute(stmt)
            db_datetime = cursor.fetchone()[0]
        finally:
            cursor.close()
        # done
        return db_datetime

    def GetCurrDateTimeExpr(self):
        """Get expression that returns current date/time of database"""
        return SQLFuncExpr("GETDATE")

    def ConvertTimestampToDate(self, timestamp):
        """ Convert a timestamp to a date-time of the database
        :param timestamp: The timestamp to convert
        :return: Returns the date-time expression
        """
        exp = SQLDate(datetime.fromtimestamp(timestamp).strftime(self.date_time_format))
        return SQLFuncExpr("TO_DATE", SQLListExpr([exp, "'DD.MM.YYYY HH24:MI:SS'"]))

    def GetConnectString(self, dbprovider, dbsource):
        """Build the connection string for SQL Server Compact

        Remark
          May be add SSCE: Default Lock Timeout=20000;
          May be add SSCE: Max Database Size=1024;

        """
        return "Provider=%s;Data Source=%s;" % (dbprovider, dbsource)


class SQLite3BaseDB():
    """Oracle Implementation of rec file DB access"""
    def __init__(self):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        self._dbType = "sqlite"
        self._dbSpecifics = {"datetime": "SELECT strftime('%Y-%m-%d %H:%M:%S','now') as DateTime",
                             "tables": "SELECT name FROM sqlite_master WHERE type='table' AND NAME LIKE "
                                       "'CL/_%' ESCAPE '/' ORDER BY name"}

    def Initialize(self):
        """ Setup function names """
        self.db_func_map[DB_FUNC_NAME_MIN] = "MIN"
        self.db_func_map[DB_FUNC_NAME_MAX] = "MAX"
        self.db_func_map[DB_FUNC_NAME_LOWER] = "LOWER"
        self.db_func_map[DB_FUNC_NAME_UPPER] = "UPPER"
        self.role = ROLE_DB_ADMIN

    def GetCurrDateTimeExpr(self):
        """Get expression that returns current date/time of database"""
        return SQLColumnExpr(None, "CURRENT_TIMESTAMP")

    def GetCurrDateTime(self):
        """Get the current date/time of the database.
        :return: Returns the current date time of the database
        """
        db_datetime = None
        sql_select_stmt = self.sql_factory.GetSelectBuilder()
        sql_select_stmt.select_list = [self.GetCurrDateTimeExpr()]
        stmt = str(sql_select_stmt)
        cursor = self.db_connection.cursor()
        try:
            log.debug(stmt)
            cursor.execute(stmt)
            db_datetime = cursor.fetchone()[0]
        finally:
            cursor.close()
        # done
        return db_datetime

    def GetConnectString(self, dbprovider, dbsource):  # pylint: disable=W0613
        """Build the connection string for SQL Lite
        """
        # return "%s;" % dbsource    #does not work, problem with ;
        return dbsource

#====================================================================
# Connection string initialization
#====================================================================


def GetOracleConnectString(dbdsn, dbdbq, dbuser, dbpassword, dbdriver=DEFAULT_MASTER_DRV):
    """Build the connection string for Oracle 11g"""
    connect_str = ""
    if dbdsn is not None:
        connect_str = "DSN=%s;" % dbdsn
    else:
        connect_str = "DRIVER={%s};" % dbdriver
    if dbdbq is not None:
        connect_str = connect_str + "DBQ=%s;" % dbdbq
    if dbuser is not None:
        connect_str = connect_str + "Uid=%s;" % dbuser
    if dbpassword is not None:
        connect_str = connect_str + "Pwd=%s;" % dbpassword
    return connect_str


def GetSQLCEConnectString(dbprovider, dbsource):
    """Build the connection string for SQL Server Compact

    Remark
      May be add SSCE: Default Lock Timeout=20000;
      May be add SSCE: Max Database Size=1024;
    """
    return "Provider=%s;Data Source=%s;" % (dbprovider, dbsource)


def GetSQLite3ConnectString(dbsource):
    """Build the connection string for SQL Lite.
    only file names are supported: http://www.connectionstrings.com/
    """
    return dbsource

#====================================================================
# Table prefix
#====================================================================


def GetFullTablePrefix(schema_prefix, base_table_prefix):
    """ Determine the table prefix from a schema prefix and a base table prefix
    :param schema_prefix: The prefix of the database schema (may be None)
    :param base_table_prefix: The base prefix of the data base tables in the schema (may be None)
    """
    table_prefix = None
    if schema_prefix is not None:
        table_prefix = schema_prefix + SCHEMA_PREFIX_SEPARATOR
    if base_table_prefix is not None:
        if table_prefix is not None:
            table_prefix = "%s%s%s" % (table_prefix, base_table_prefix, TABLE_PREFIX_SEPARATOR)
        else:
            table_prefix = "%s%s" % (base_table_prefix, TABLE_PREFIX_SEPARATOR)
    return table_prefix

"""
CHANGE LOG:
-----------
$Log: db_common.py  $
Revision 1.1 2021/12/13 17:55:48CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/project.pj
Revision 1.42 2013/07/29 09:15:05CEST Raedler, Guenther (uidt9430) 
- revert unexpected changes
- removed __del__ method an BaseDB class as not needed. The connections are closed by the connector class. Terminate() method creates unexpected errors
- left pylint error fixes and regex definition as discussed
- Added comments -  uidt9430 [Jul 29, 2013 9:15:05 AM CEST]
Change Package : 191735:1 http://mks-psad:7002/im/viewissue?selection=191735
Revision 1.41 2013/07/17 09:33:50CEST Mertens, Sven (uidv7805) 
regex fix: adding apostroph exclude
--- Added comments ---  uidv7805 [Jul 17, 2013 9:33:50 AM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.40 2013/07/04 16:12:04CEST Mertens, Sven (uidv7805)
adding one more method from DB specific classes to db_common
--- Added comments ---  uidv7805 [Jul 4, 2013 4:12:05 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.39 2013/07/04 14:58:14CEST Mertens, Sven (uidv7805)
added functionality from Oracle-, SQLCE- and SQLite3BaseDB to BaseDB
to remove these class dependencies and providing DB specific things in BaseDB instead.
--- Added comments ---  uidv7805 [Jul 4, 2013 2:58:14 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.38 2013/06/25 13:24:40CEST Mertens, Sven (uidv7805)
adjustment for regex table expression needed
--- Added comments ---  uidv7805 [Jun 25, 2013 1:24:41 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.37 2013/06/24 17:13:20CEST Skerl, Anne (uid19464)
*bugfix identifying Windows version
--- Added comments ---  uid19464 [Jun 24, 2013 5:13:20 PM CEST]
Change Package : 178419:6 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.36 2013/06/24 16:56:57CEST Skerl, Anne (uid19464)
*add driver for SQL Sercer Compact Edition 3.5 for sdf-files at Windows7 (used for CGEB-Labels)
*switch default db drivers depending on Windows version
--- Added comments ---  uid19464 [Jun 24, 2013 4:56:57 PM CEST]
Change Package : 178419:6 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.35 2013/06/21 13:56:00CEST Mertens, Sven (uidv7805)
for interim purposes sqlite should be able to connect to :memory: as well (missing)
--- Added comments ---  uidv7805 [Jun 21, 2013 1:56:00 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.34 2013/06/14 13:00:10CEST Mertens, Sven (uidv7805)
adding __del__ method to ensure DB is closed
--- Added comments ---  uidv7805 [Jun 14, 2013 1:00:10 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.33 2013/06/13 15:24:22CEST Mertens, Sven (uidv7805)
Adding possibility to take over connection string.
As new ECU-SIL observer should be on multi processing functionality,
removes the need for involved components and DB classes can be used more directly.
Backwardcompatibility is preserved.
--- Added comments ---  uidv7805 [Jun 13, 2013 3:24:22 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.32 2013/06/06 11:22:22CEST Bratoi, Bogdan-Horia (uidu8192)
- corrected the date_time_format in the init of OracleBaseDB
--- Added comments ---  uidu8192 [Jun 6, 2013 11:22:22 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.31 2013/05/29 15:20:31CEST Raedler, Guenther (uidt9430)
- provide cursor for database procedure calls (required in the LD validation)
--- Added comments ---  uidt9430 [May 29, 2013 3:20:31 PM CEST]
Change Package : 184344:1 http://mks-psad:7002/im/viewissue?selection=184344
Revision 1.30 2013/05/29 14:45:48CEST Mertens, Sven (uidv7805)
making cxOracle connection optional via connectionString's DBQ option which is oracle specific
--- Added comments ---  uidv7805 [May 29, 2013 2:45:48 PM CEST]
Change Package : 179495:8 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.29 2013/05/29 09:10:04CEST Mertens, Sven (uidv7805)
adding local pylint ignores
--- Added comments ---  uidv7805 [May 29, 2013 9:10:05 AM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.28 2013/05/24 10:51:24CEST Mertens, Sven (uidv7805)
bugfixing connection problem
--- Added comments ---  uidv7805 [May 24, 2013 10:51:24 AM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.27 2013/05/23 09:14:23CEST Mertens, Sven (uidv7805)
fixing wrong intention
--- Added comments ---  uidv7805 [May 23, 2013 9:14:23 AM CEST]
Change Package : 179495:8 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.26 2013/05/23 06:41:13CEST Mertens, Sven (uidv7805)
new function dbConnect to be able to ease connection setup
--- Added comments ---  uidv7805 [May 23, 2013 6:41:13 AM CEST]
Change Package : 179495:8 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.25 2013/04/26 13:46:57CEST Mertens, Sven (uidv7805)
fixed a raise as tested from unittest
--- Added comments ---  uidv7805 [Apr 26, 2013 1:46:58 PM CEST]
Change Package : 180829:2 http://mks-psad:7002/im/viewissue?selection=180829
Revision 1.24 2013/04/26 10:46:08CEST Mertens, Sven (uidv7805)
moving strIdent
--- Added comments ---  uidv7805 [Apr 26, 2013 10:46:08 AM CEST]
Change Package : 179495:4 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.23 2013/04/25 15:12:39CEST Mertens, Sven (uidv7805)
added column description header to execute
--- Added comments ---  uidv7805 [Apr 25, 2013 3:12:39 PM CEST]
Change Package : 179495:2 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.22 2013/04/19 13:36:30CEST Hecker, Robert (heckerr)
functionality reverted to revision 1.19.
--- Added comments ---  heckerr [Apr 19, 2013 1:36:31 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.21 2013/04/12 15:01:15CEST Mertens, Sven (uidv7805)
minor DB connection update due to VALF connection change
--- Added comments ---  uidv7805 [Apr 12, 2013 3:01:16 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.20 2013/04/11 14:32:53CEST Ahmed-EXT, Zaheer (uidu7634)
Fixed Schema prefix bug for SQLite DB support
--- Added comments ---  uidu7634 [Apr 11, 2013 2:32:53 PM CEST]
Change Package : 178419:2 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.19 2013/04/05 11:17:42CEST Hospes, Gerd-Joachim (uidv8815)
fix documentation
--- Added comments ---  uidv8815 [Apr 5, 2013 11:17:42 AM CEST]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.18 2013/04/03 08:02:13CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:13 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.17 2013/03/28 14:43:10CET Mertens, Sven (uidv7805)
pylint: resolving some R0904, R0913, R0914, W0107
--- Added comments ---  uidv7805 [Mar 28, 2013 2:43:10 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.16 2013/03/28 11:10:54CET Mertens, Sven (uidv7805)
pylint: last unused import removed
--- Added comments ---  uidv7805 [Mar 28, 2013 11:10:54 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.15 2013/03/28 09:33:21CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:21 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.14 2013/03/26 16:19:38CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
Revision 1.13 2013/03/26 13:00:22CET Mertens, Sven (uidv7805)
reverting error for keyword argument spaces
--- Added comments ---  uidv7805 [Mar 26, 2013 1:00:22 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.12 2013/03/26 11:53:20CET Mertens, Sven (uidv7805)
reworking imports on cat, cl and db_common to start testing with.
--- Added comments ---  uidv7805 [Mar 26, 2013 11:53:21 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.11 2013/03/22 15:07:19CET Mertens, Sven (uidv7805)
additional support for call proc (cx_Oracle) added
--- Added comments ---  uidv7805 [Mar 22, 2013 3:07:19 PM CET]
Change Package : 176171:9 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.10 2013/03/15 10:01:19CET Mertens, Sven (uidv7805)
added addConstraint method to add new constrain set with details
--- Added comments ---  uidv7805 [Mar 15, 2013 10:01:19 AM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.9 2013/03/14 11:35:00CET Mertens, Sven (uidv7805)
adding execute for being able to submit SQL queries
--- Added comments ---  uidv7805 [Mar 14, 2013 11:35:00 AM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.8 2013/03/07 07:17:00CET Raedler, Guenther (uidt9430)
- added function to load the subscheme version
- added function to set the current user role
--- Added comments ---  uidt9430 [Mar 7, 2013 7:17:00 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.7 2013/03/04 07:47:33CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 4, 2013 7:47:34 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/02/27 13:59:46CET Hecker, Robert (heckerr)
Some changes regarding Pep8
--- Added comments ---  heckerr [Feb 27, 2013 1:59:46 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/26 20:11:54CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:11:54 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.4 2013/02/26 16:21:43CET Raedler, Guenther (uidt9430)
- added additional exception message for AddGenericData
--- Added comments ---  uidt9430 [Feb 26, 2013 4:21:43 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.3 2013/02/19 14:07:56CET Raedler, Guenther (uidt9430)
- define common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:56 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/12 08:19:50CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm
/STK_ScriptingToolKit/04_Engineering/stk/db/project.pj
------------------------------------------------------------------------------
-- From CGEB Archive
------------------------------------------------------------------------------
Revision 1.16 2012/05/02 07:55:37CEST Raedler-EXT, Guenther (uidt9430)
- changed driver default name
--- Added comments ---  uidt9430 [May 2, 2012 7:55:39 AM CEST]
Change Package : 111588:1 http://mks-psad:7002/im/viewissue?selection=111588
Revision 1.15 2012/04/25 10:13:36CEST Raedler-EXT, Guenther (uidt9430)
- set driver for Win7 as default (SimuClients)
- add XP driver definition (current workstations)
--- Added comments ---  uidt9430 [Apr 25, 2012 10:13:37 AM CEST]
Change Package : 111588:1 http://mks-psad:7002/im/viewissue?selection=111588
Revision 1.14 2012/04/17 12:44:26CEST Raedler-EXT, Guenther (uidt9430)
- upgrade for oracle 11g
* define new connection parameters
* support driver instead of dsn
--- Added comments ---  uidt9430 [Apr 17, 2012 12:44:30 PM CEST]
Change Package : 111588:1 http://mks-psad:7002/im/viewissue?selection=111588
Revision 1.13 2011/10/07 14:24:30CEST Castell, Christoph (uidt6394)
Fixed bug bz commenting out rowcount in DeleteGenericData function.
--- Added comments ---  uidt6394 [Oct 7, 2011 2:24:31 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.12 2011/07/19 09:37:35CEST Skerl Anne (uid19464) (uid19464)
*uncomment rowcount in DeleteGenericData
--- Added comments ---  uid19464 [Jul 19, 2011 9:37:36 AM CEST]
Change Package : 38933:9 http://mks-psad:7002/im/viewissue?selection=38933
Revision 1.11 2011/07/04 13:14:52CEST Raedler Guenther (uidt9430) (uidt9430)
-- added new method to get table data more efficiently
--- Added comments ---  uidt9430 [Jul 4, 2011 1:14:53 PM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.10 2011/01/21 14:12:46CET Skerl Anne (uid19464) (uid19464)
*add comment: GetSQLite3ConnectString does not take ";" at the end
--- Added comments ---  uid19464 [Jan 21, 2011 2:12:46 PM CET]
Change Package : 38933:6 http://mks-psad:7002/im/viewissue?selection=38933
Revision 1.9 2010/11/18 17:32:07CET Dominik Froehlich (froehlichd1)
* change: added special date time format string to Oracle DB catalog class
--- Added comments ---  froehlichd1 [Nov 18, 2010 5:32:08 PM CET]
Change Package : 45990:34 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.8 2010/11/18 17:11:15CET Dominik Froehlich (froehlichd1)
* fix: corrected GetFullTablePrefix
* change: set default schema prefix to None
--- Added comments ---  froehlichd1 [Nov 18, 2010 5:11:15 PM CET]
Change Package : 45990:33 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.7 2010/11/18 14:47:29CET Dominik Froehlich (froehlichd1)
* fix: fixed computation of table/schema prefixes
* use one prefix that includes the separators
Revision 1.6 2010/11/10 10:56:36CET Dominik Froehlich (froehlichd1)
* change: removed default table prefixes
* change: full support of 'no table prefix'
Revision 1.5 2010/10/27 10:32:00CEST Skerl Anne (uid19464) (uid19464)
*add close database connection in terminate call
--- Added comments ---  uid19464 [Oct 27, 2010 10:32:00 AM CEST]
Change Package : 38933:4 http://mks-psad:7002/im/viewissue?selection=38933
Revision 1.4 2010/07/14 11:56:56CEST Dominik Froehlich (froehlichd1)
* update
--- Added comments ---  froehlichd1 [Jul 14, 2010 11:56:56 AM CEST]
Change Package : 45990:20 http://fras236:8002/im/viewissue?selection=45990
Revision 1.3 2010/06/25 14:22:12CEST Dominik Froehlich (dfroehlich)
* update
--- Added comments ---  dfroehlich [2010/06/25 12:22:12Z]
Change Package : 45990:3 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.2 2010/06/18 16:01:23CEST Dominik Froehlich (dfroehlich)
* update
--- Added comments ---  dfroehlich [2010/06/18 14:01:23Z]
Change Package : 45990:2 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.1 2009/10/08 12:27:41CEST rthiel
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/Base_CGEB
/06_Algorithm/04_Engineering/02_Development_Tools/scripts/project.pj
Revision 1.6 2009/09/21 14:28:51CEST Dominik Froehlich (dfroehlich)
Improved import for oracle db:

* support of data-time strings
* support of transactions
* extended info during import
--- Added comments ---  dfroehlich [2009/09/21 12:28:51Z]
Change Package : 30406:7 http://LISS014:6001/im/viewissue?selection=30406
Revision 1.5 2009/08/10 10:41:41CEST Dominik Froehlich (dfroehlich)
* various bug-fixes
--- Added comments ---  dfroehlich [2009/08/10 08:41:41Z]
Change Package : 27675:10 http://LISS014:6001/im/viewissue?selection=27675
Revision 1.4 2009/06/17 19:02:07CEST dfroehlich
* change: intermediate version of new simulation report
--- Added comments ---  dfroehlich [2009/06/17 17:02:07Z]
Change Package : 27675:1 http://LISS014:6001/im/viewissue?selection=27675
Revision 1.3 2009/06/16 11:13:34CEST dfroehlich
* fix: various SQL changes
--- Added comments ---  dfroehlich [2009/06/16 09:13:34Z]
Change Package : 21107:4 http://LISS014:6001/im/viewissue?selection=21107
Revision 1.2 2009/05/28 15:01:48CEST dfroehlich
fix: fixed event import and table init
--- Added comments ---  dfroehlich [2009/05/28 13:01:48Z]
Change Package : 21107:3 http://LISS014:6001/im/viewissue?selection=21107
Revision 1.1 2009/05/14 18:20:22CEST dfroehlich
Initial revision
Member added to project /nfs/projekte1/customer/Base_ARS3xx_ISF1xx/
3_development/7_tools/evaluation_scripts/kcm/project.pj
"""
