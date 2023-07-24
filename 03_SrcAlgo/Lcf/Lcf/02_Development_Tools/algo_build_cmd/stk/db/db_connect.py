"""
stk/db/db_connect.py
--------------------

Provides the database interface for the requested package object

e.g stk.db.cat.cat

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:48CET $
"""
# Import Python Modules -------------------------------------------------------
from stat import ST_MODE, S_IWRITE
from inspect import currentframe, getmembers, isclass
from os import path, stat, chmod
from pyodbc import connect as pyConnect
from adodbapi import connect as adoConnect
from sqlite3 import connect as sqConnect

try:
    from cx_Oracle import connect as cxConnect  # pylint: disable=W0611
except:
    print "cx_oracle is not installed on the machine"

# try:
DB_SUPPORT_IMAGE = True
# except:
#     import odbc
#     DB_SUPPORT_IMAGE = False


# Import STK Modules ----------------------------------------------------------
from .db_common import ERROR_TOLERANCE_NONE, OracleBaseDB, SQLite3BaseDB, GetOracleConnectString, GetFullTablePrefix, \
    GetSQLCEConnectString, GetSQLite3ConnectString
from ..util.helper import ListFolders
from ..util.logger import Logger
from ..valf import PluginManager


# Defines ---------------------------------------------------------------------
SDF_FILE_EXT = [".sdf"]

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class DBConnect(object):
    def __init__(self,
                 dbq="racadmpe",
                 dsn='CLEO',
                 user=None,
                 pw=None,
                 master=None,
                 drv=None,
                 tbl_prefix=None,
                 db_file=None,
                 error_tolerance=ERROR_TOLERANCE_NONE,
                 use_cx_oracle=False):
        """ Init DB Connector Class

            Supports
                - Oracle DB Connections
                - SQLite3 DB Connections
                - SQL Server Compact Edition Connections
            @param dbq: Database TSN (default: racadmpe)
            @param dsn: User or System DSN registered on the local machine (default: CLEO)
            @param user: Database User
            @param pw: Password
            @param master: Master Schema Prefix  (i.e. DEV_ARS31x_ADMIN)
            @param tbl_prefix: Table Prefix
            @param db_file: Database File for SQLite3 Connections
            @param error_tolerance: Error Tolerance for the DB interface
            @param use_cx_oracle: Use the cx Oracle interface 

        """
        self.__dbfile = db_file
        self.__dbprovider = None
        self.__masterdbdsn = dsn
        self.__masterdbdbq = dbq
        self.__masterdbuser = user
        self.__masterdbdrv = drv
        self.__masterdbpassword = pw
        self.__masterdbschemaprefix = master
        self.__tableprefix = tbl_prefix
        self.__use_cx_oracle = use_cx_oracle
        self.__logger = Logger(self.__class__.__name__)
        self.__errortolerance = error_tolerance
        self.__db_dir = path.abspath(path.join(path.dirname(currentframe().f_code.co_filename)))
        self.__db_file_connect = None

    def Connect(self, db_sub):

        dbConnection = None
        try:
            dbConnection = self.__InitDbConnection(db_sub)
        except Exception, ex:
            self.__logger.error("Could not initialize db connection due to '%s'" % str(ex))
            return None

        return dbConnection

    def DisConnect(self, dbConnection):
        try:
            dbConnection.Terminate()
        except Exception, ex:
            self.__logger.error("Could not close db connection due to '%s'" % str(ex))

    def __GetBaseDBPlugInFolders(self, head_dir):

        plugin_folder_list = []
        for folder_path in ListFolders(head_dir):
            plugin_folder_list.append(folder_path)

        return plugin_folder_list

    def __GetMatchPlugInClass(self, cls, module):
        """ Return the plugin class supported by the given module

            @param cls:    Class supporting the plugin
            @param module: Module containing the plugin class
        """

        # get all folders to search
        plugin_folder_list = []
        for folder_path in ListFolders(self.__db_dir):
            plugin_folder_list.append(folder_path)

        # find all modules implementing the plugin
        plugin_manager = PluginManager(plugin_folder_list, cls)
        plugin_list = plugin_manager.get_plugin_class_list(remove_duplicates=True)

        # match the plugin and the module
        for _, obj in getmembers(module):  # load all members of the given object
            if isclass(obj):  # if type class
                for plugin in plugin_list:  # compare with the supported plugins
                    if plugin['name'] == obj.__name__:  # if plugin found the object, open the connection
                        return obj
        return None

    def __InitDbConnection(self, DataBaseObject):

        db = None

        if self.__dbfile is None:
            db_obj = self.__GetMatchPlugInClass(OracleBaseDB, DataBaseObject)
            if db_obj is not None:
                if self.__masterdbdrv:
                    connect_str = GetOracleConnectString(self.__masterdbdsn,
                                                         self.__masterdbdbq,
                                                         self.__masterdbuser,
                                                         self.__masterdbpassword,
                                                         self.__masterdbdrv)
                else:
                    connect_str = GetOracleConnectString(self.__masterdbdsn,
                                                         self.__masterdbdbq,
                                                         self.__masterdbuser,
                                                         self.__masterdbpassword)

                self.__logger.debug("Connect to database '%s'" % connect_str)
                if self.__use_cx_oracle:
                    db_connection = cxConnect(self.__masterdbuser,
                                              self.__masterdbpassword,
                                              self.__masterdbdbq)
                else:
                    db_connection = pyConnect(connect_str)
#                db_connection.setautocommit(0)
                db = db_obj(db_connection,
                            table_prefix=GetFullTablePrefix(self.__masterdbschemaprefix, self.__tableprefix),
                            error_tolerance=self.__errortolerance)
        else:
            if not path.isfile(self.__dbfile):
                self.__logger.error("Database file '%s' does not exist." % self.__dbfile)
                return - 1
            try:
                # remove read-only attribute
                file_attr = stat(self.__dbfile)[ST_MODE]
                if (not file_attr & S_IWRITE):
                    self.__logger.debug("Fixing read only database file: '%s'" % path.split(self.__dbfile)[1])
                    chmod(self.__dbfile, S_IWRITE)
            except:
                pass

            _, fileext = path.splitext(self.__dbfile)
            if fileext in SDF_FILE_EXT:
                db_obj = self.__GetMatchPlugInClass(SQLite3BaseDB, DataBaseObject)
                if db_obj is not None:
                    connect_str = GetSQLCEConnectString(self.__dbprovider, self.__dbfile)
                    self.__logger.debug("Connect to database '%s'" % connect_str)
                    db_connection = adoConnect(connect_str)
                    db = db_obj(db_connection,
                                table_prefix=GetFullTablePrefix(self.__masterdbschemaprefix, self.__tableprefix),
                                error_tolerance=self.__errortolerance)
            else:
                db_obj = self.__GetMatchPlugInClass(SQLite3BaseDB, DataBaseObject)
                if db_obj is not None:
                    connect_str = GetSQLite3ConnectString(self.__dbfile)
                    self.__logger.debug("Connect to database '%s'" % connect_str)
                    if self.__db_file_connect is None:
                        db_connection = sqConnect(connect_str)
                        db_connection.text_factory = str
                        self.__db_file_connect = db_connection
                    else:
                        db_connection = self.__db_file_connect

                    db = db_obj(db_connection,
                                table_prefix=GetFullTablePrefix(self.__masterdbschemaprefix, self.__tableprefix),
                                error_tolerance=self.__errortolerance)
        if db is not None:
            db.Initialize()

        return db
"""
CHANGE LOG:
-----------
$Log: db_connect.py  $
Revision 1.1 2021/12/13 17:55:48CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/project.pj
Revision 1.16 2013/05/29 15:21:27CEST Raedler, Guenther (uidt9430) 
- support cx oracle interface support
- Added comments -  uidt9430 [May 29, 2013 3:21:27 PM CEST]
Change Package : 184344:1 http://mks-psad:7002/im/viewissue?selection=184344
Revision 1.15 2013/04/19 13:32:04CEST Hecker, Robert (heckerr) 
Functionality reverted to revision1.11.
--- Added comments ---  heckerr [Apr 19, 2013 1:32:04 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.14 2013/04/15 12:08:42CEST Mertens, Sven (uidv7805) 
small bugfixes
--- Added comments ---  uidv7805 [Apr 15, 2013 12:08:43 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.13 2013/04/12 15:42:35CEST Mertens, Sven (uidv7805)
fix: missing self on own method call
--- Added comments ---  uidv7805 [Apr 12, 2013 3:42:35 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.12 2013/04/12 15:01:18CEST Mertens, Sven (uidv7805)
minor DB connection update due to VALF connection change
Revision 1.11 2013/04/03 08:02:16CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:17 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/03/27 13:51:25CET Mertens, Sven (uidv7805)
pylint: bugfixing and error reduction
--- Added comments ---  uidv7805 [Mar 27, 2013 1:51:26 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.9 2013/03/27 11:37:25CET Mertens, Sven (uidv7805)
pep8 & pylint: rowalignment and error correction
--- Added comments ---  uidv7805 [Mar 27, 2013 11:37:25 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/26 16:19:35CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:36 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/07 07:21:23CET Raedler, Guenther (uidt9430)
- removed some more pep8
--- Added comments ---  uidt9430 [Mar 7, 2013 7:21:23 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.6 2013/03/06 12:44:48CET Raedler, Guenther (uidt9430)
- changed exclipse settings to follow peps8
--- Added comments ---  uidt9430 [Mar 6, 2013 12:44:49 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.4 2013/03/04 07:47:32CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 4, 2013 7:47:33 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/27 13:59:46CET Hecker, Robert (heckerr)
Some changes regarding Pep8
--- Added comments ---  heckerr [Feb 27, 2013 1:59:47 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/26 16:23:25CET Raedler, Guenther (uidt9430)
- use only a single connection for the sqlite db
- add error tolerance to connector
--- Added comments ---  uidt9430 [Feb 26, 2013 4:23:25 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/19 14:08:42CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/db/project.pj
"""
