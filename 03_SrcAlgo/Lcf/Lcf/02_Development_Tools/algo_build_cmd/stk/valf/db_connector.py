"""
stk/valf/db_connector.py
--------------------

The component for reading mts batch play list.

:org:           Continental AG
:author:        Spruck Jochen

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:52CET $
"""
# Import Python Modules -------------------------------------------------------
from sys import _getframe

# Import STK Modules ----------------------------------------------------------
from stk.db import cat, gbl, lbl, obj, val, par
from stk.db.lbl import camlabel as db_cam
from stk.db.lbl import genlabel as db_gen
from stk.util.logger import Logger
import stk.db.db_common as db_common
from stk.db.db_connect import DBConnect
from stk.valf import BaseComponentInterface

# Defines ---------------------------------------------------------------------
SDF_FILE_EXT = [".sdf"]
# Database modules
DBACC = "dbacc"
DBCAT = "dbcat"
DBOBJ = "dbobj"
DBENV = "dbenv"
DBGBL = "dbgbl"
DBVAL = "dbval"
DBLBL = "dblbl"
DBPAR = "dbpar"
DBCAM = "dbcam"

# common DBBUS#1 Portnames ----------------------------------------------------
MASTER_DB_DSN_PORT_NAME = "masterdbdsn"
MASTER_DB_DBQ_PORT_NAME = "masterdbdbq"
MASTER_DB_USR_PORT_NAME = "masterdbuser"
MASTER_DB_PW_PORT_NAME = "masterdbpassword"
MASTER_DB_DRV_PORT_NAME = "masterdbdrv"
MASTER_DB_SPX_PORT_NAME = "masterdbschemaprefix"
TABLE_DB_PX_PORT_NAME = "tableprefix"
MASTER_DB_USE_CX_PORT_NAME = "use_cx_oracle"

DATABASE_OBJECTS_CONN_PORT_NAME = "DatabaseObjectsConnections"
DB_FILE_PORT_NAME = "dbfile"

# List of connectins used for option "UseAllConnections"
# db_cam is not supported for this option (GR)
ALL_CONNECTIONS = [cat, obj, gbl, val, par, db_gen]

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class DBConnector(BaseComponentInterface):
    """ DB Connector provides database connections for the connected observers 
        
        Each Observer could register the DB connections used for validation in the 
        Initialize method. The DBConnector collects all the registrations and opens the 
        connection. After that the DBConnector provides the connections which could be 
        read from the Observers in their PostInitialize function. 
         
    """
    def __init__(self, data_manager, component_name, bus_name=["BUS_BASE"]):
        self.__bus_name = bus_name[0]
        self.__component_name = component_name
        self.__data_manager = data_manager
        self.__logger = Logger(self.__component_name)
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        self.__version = "$Revision: 1.1 $"

        self.__DataBaseObjects = []
        self.__DataBaseObjectsConnections = []

        self.__errortolerance = db_common.ERROR_TOLERANCE_MED

    def Initialize(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        # get the database connections
        dbfile = self.__data_manager.GetDataPort("dbfile", self.__bus_name)
        masterdbdbq = self.__data_manager.GetDataPort(MASTER_DB_DBQ_PORT_NAME, self.__bus_name)
        masterdbdsn = None
        masterdbuser = None
        masterdbpassword = None
        masterdbdrv = None
        masterdbschemaprefix = None
        use_cx_oracle = False

        if not dbfile and not masterdbdbq:
            self.__logger.error("'dbfile' or '%s' port was not set." % MASTER_DB_DBQ_PORT_NAME)
            return - 1

        if dbfile is None:  # Check for Oracle database connection parameters
            masterdbdsn = self.__data_manager.GetDataPort(MASTER_DB_DSN_PORT_NAME, self.__bus_name)
            if not masterdbdsn:
                self.__logger.info("'%s' port was not set." % MASTER_DB_DSN_PORT_NAME)

            masterdbdbq = self.__data_manager.GetDataPort(MASTER_DB_DBQ_PORT_NAME, self.__bus_name)
            if not masterdbdbq:
                self.__logger.error("'%s' port was not set." % MASTER_DB_DBQ_PORT_NAME)
                return - 1

            masterdbuser = self.__data_manager.GetDataPort(MASTER_DB_USR_PORT_NAME, self.__bus_name)
            if not masterdbuser:
                self.__logger.error("'%s' port was not set." % MASTER_DB_USR_PORT_NAME)
                return - 1

            masterdbpassword = self.__data_manager.GetDataPort(MASTER_DB_PW_PORT_NAME, self.__bus_name)
            if not masterdbpassword:
                self.__logger.error("'%s' port was not set." % MASTER_DB_PW_PORT_NAME)
                return - 1

            masterdbdrv = self.__data_manager.GetDataPort(MASTER_DB_DRV_PORT_NAME, self.__bus_name)
            if not masterdbdrv:
                self.__logger.info("'%s' port was not set." % MASTER_DB_DRV_PORT_NAME)


            masterdbschemaprefix = self.__data_manager.GetDataPort(MASTER_DB_SPX_PORT_NAME, self.__bus_name)
            use_cx_oracle = self.__data_manager.GetDataPort(MASTER_DB_USE_CX_PORT_NAME, self.__bus_name)
            if not use_cx_oracle:
                use_cx_oracle = False

        tableprefix = self.__data_manager.GetDataPort(TABLE_DB_PX_PORT_NAME, self.__bus_name)

        # setup list with data base objects
        self.__data_manager.SetDataPort("DataBaseObjects", self.__DataBaseObjects, self.__bus_name)

        self.__db_connnector = DBConnect(dbq=masterdbdbq,
                                         dsn=masterdbdsn,
                                         user=masterdbuser,
                                         pw=masterdbpassword,
                                         master=masterdbschemaprefix,
                                         drv=masterdbdrv,
                                         tbl_prefix=tableprefix,
                                         db_file=dbfile,
                                         error_tolerance=self.__errortolerance,
                                         use_cx_oracle=use_cx_oracle)

        return 0

    def PostInitialize(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        obj_list = []

        # Is specified in the .cfg file, add all connections.
        use_all_connections = self.__data_manager.GetDataPort("UseAllConnections", self.__bus_name)

        if use_all_connections == 'True': # supports only DEV_XXX_ADMIN schemes. ALGO_DB_USER is not supported
            for con in ALL_CONNECTIONS:
                if con not in self.__DataBaseObjects:
                    self.__DataBaseObjects.append(con)

        # Establish database connection to all requested database objects.
        for LocDataBaseObject in self.__DataBaseObjects:

            if (obj_list.__contains__(LocDataBaseObject)):
                self.__logger.debug("DB Connection duplicate request")
            else:
                obj_list.append(LocDataBaseObject)
                try:
                    dbConnection = self.__db_connnector.Connect(LocDataBaseObject)
                except Exception, ex:
                    self.__logger.error("Could not initialize db connection due to '%s'" % str(ex))
                    return - 1

                if dbConnection is not None:
                    self.__DataBaseObjectsConnections.append(dbConnection)
                else:
                    self.__logger.error("Database connection not established for '%s'." % LocDataBaseObject.__name__)

        self.__data_manager.SetDataPort("DataBaseObjectsConnections",
                                        self.__DataBaseObjectsConnections,
                                        self.__bus_name)

        # Also provide the database connections as dict.
        self.__DatabaseObjectsConnectionsDict = {}
        for ConnectionObject in self.__DataBaseObjectsConnections:
            if isinstance(ConnectionObject, cat.BaseRecCatalogDB):
                self.__DatabaseObjectsConnectionsDict[DBCAT] = ConnectionObject
                continue
            if isinstance(ConnectionObject, obj.BaseObjDataDB):
                self.__DatabaseObjectsConnectionsDict[DBOBJ] = ConnectionObject
                continue
            if isinstance(ConnectionObject, gbl.BaseGblDB):
                self.__DatabaseObjectsConnectionsDict[DBGBL] = ConnectionObject
                continue
            if isinstance(ConnectionObject, val.BaseValResDB):
                self.__DatabaseObjectsConnectionsDict[DBVAL] = ConnectionObject
                continue
            if isinstance(ConnectionObject, db_gen.BaseGenLabelDB):
                self.__DatabaseObjectsConnectionsDict[DBLBL] = ConnectionObject
                continue
            if isinstance(ConnectionObject, db_cam.BaseCameraLabelDB):
                self.__DatabaseObjectsConnectionsDict[DBCAM] = ConnectionObject
                continue
            if isinstance(ConnectionObject, par.BaseParDB):
                self.__DatabaseObjectsConnectionsDict[DBPAR] = ConnectionObject
                continue

        self.__data_manager.SetDataPort("DatabaseObjectsConnectionsDict",
                                        self.__DatabaseObjectsConnectionsDict,
                                        self.__bus_name)

        return 0

    def LoadData(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def ProcessData(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def PostProcessData(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        # commit data to establish data base connection to all requested data base objects
        for dbConnection in self.__DataBaseObjectsConnections:
            if dbConnection is not None:
                dbConnection.Commit()
            else:
                self.__logger.error("Data base connection not established.")

        return 0

    def PreTerminate(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return 0

    def Terminate(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        # commit data to establish data base connection to all requested data base objects
        for dbConnection in self.__DataBaseObjectsConnections:
            if dbConnection is not None:
                self.__db_connnector.DisConnect(dbConnection)
            else:
                self.__logger.error("Data base connection not established.")

        return 0

    def GetComponentVersion(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        revision = self.__version.find("Revision: ")
        if revision > -1:
            version = self.__version[revision + 10:-2]
        else:
            version = 0.0

        return version

    def GetComponentName(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return self.__component_name

"""
CHANGE LOG:
-----------
$Log: db_connector.py  $
Revision 1.1 2021/12/13 17:59:52CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.26 2013/11/19 08:36:38CET Raedler, Guenther (uidt9430) 
- do not clear list of registered db connections for option "UseAllConnections"
- replaced sequential code by loop for this option
- Added comments -  uidt9430 [Nov 19, 2013 8:36:39 AM CET]
Change Package : 204971:1 http://mks-psad:7002/im/viewissue?selection=204971
Revision 1.25 2013/11/15 15:14:33CET Raedler, Guenther (uidt9430) 
- support Camera and Generic Labels DB connections
- added comments to UseAllConnections configuration option
--- Added comments ---  uidt9430 [Nov 15, 2013 3:14:33 PM CET]
Change Package : 204971:1 http://mks-psad:7002/im/viewissue?selection=204971
Revision 1.24 2013/09/19 10:44:13CEST Raedler, Guenther (uidt9430) 
- add new portname for the DB file
--- Added comments ---  uidt9430 [Sep 19, 2013 10:44:14 AM CEST]
Change Package : 197855:1 http://mks-psad:7002/im/viewissue?selection=197855
Revision 1.23 2013/05/29 15:23:48CEST Raedler, Guenther (uidt9430) 
- support cx oracle interface option
--- Added comments ---  uidt9430 [May 29, 2013 3:23:48 PM CEST]
Change Package : 184344:1 http://mks-psad:7002/im/viewissue?selection=184344
Revision 1.16 2013/04/23 14:18:41CEST Raedler, Guenther (uidt9430) 
- changed initial value of masterdbschemaprefix to fix problems with sqlite
--- Added comments ---  uidt9430 [Apr 23, 2013 2:18:42 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.15 2013/04/22 13:12:18CEST Hecker, Robert (heckerr) 
Revert back to last working version 1.11.1.1.
--- Added comments ---  heckerr [Apr 22, 2013 1:12:18 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.14 2013/04/12 14:56:51CEST Mertens, Sven (uidv7805) 
another upload due to MKS problems
--- Added comments ---  uidv7805 [Apr 12, 2013 2:56:51 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.13 2013/04/12 14:47:48CEST Mertens, Sven (uidv7805) 
enabling the use of a connection string on observer level.
Each of them is allowed to have an additional InputData in config,
e.g. ("connectionString", "DBQ=racadmpe;Uid=DEV_MFC31X_ADMIN;Pwd=MFC31X_ADMIN"),("dbPrefix", "DEV_MFC31X_ADMIN.").
--- Added comments ---  uidv7805 [Apr 12, 2013 2:47:48 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.12 2013/03/28 14:20:06CET Mertens, Sven (uidv7805)
pylint: solving some W0201 (Attribute %r defined outside __init__) errors
--- Added comments ---  uidv7805 [Mar 28, 2013 2:20:06 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.11 2013/03/28 09:33:16CET Mertens, Sven (uidv7805)
pylint: removing unused imports
Revision 1.10 2013/03/13 17:46:25CET Hecker, Robert (heckerr)
Added support for Camlablels.
--- Added comments ---  heckerr [Mar 13, 2013 5:46:26 PM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/03/06 12:44:49CET Raedler, Guenther (uidt9430)
- changed exclipse settings to follow peps8
--- Added comments ---  uidt9430 [Mar 6, 2013 12:44:49 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.7 2013/03/01 10:23:23CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:24 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/02/28 08:12:18CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:19 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/27 17:55:11CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:11 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/27 16:19:55CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:55 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/26 20:18:07CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:18:07 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/26 16:26:40CET Raedler, Guenther (uidt9430)
- use db_connnect to parse the arguments and open the connection
--- Added comments ---  uidt9430 [Feb 26, 2013 4:26:41 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 11:06:07CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.18 2012/04/17 12:38:48CEST Raedler-EXT, Guenther (uidt9430)
- upgrade for Oracle 11g
  * masterdsn is not mandatory for the new oracle database
  * support master driver as parameter for
- use common bus port names
--- Added comments ---  uidt9430 [Apr 17, 2012 12:38:50 PM CEST]
Change Package : 111588:1 http://mks-psad:7002/im/viewissue?selection=111588
Revision 1.17 2012/04/13 11:13:28CEST Spruck, Jochen (spruckj)
Use bus name from config file for the db connecter, to used different db connections
--- Added comments ---  spruckj [Apr 13, 2012 11:13:29 AM CEST]
Change Package : 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.16 2012/03/02 12:33:40CET Mogos, Sorin (mogoss)
* updade: added  pyodbc module
* update: imported db_valpar module
--- Added comments ---  mogoss [Mar 2, 2012 12:33:41 PM CET]
Change Package : 96336:1 http://mks-psad:7002/im/viewissue?selection=96336
Revision 1.15 2011/10/31 11:40:15CET Mogos, Sorin (mogoss)
* change: changed stk library path
--- Added comments ---  mogoss [Oct 31, 2011 11:40:15 AM CET]
Change Package : 85403:1 http://mks-psad:7002/im/viewissue?selection=85403
Revision 1.14 2011/09/19 10:14:27CEST Castell Christoph (uidt6394) (uidt6394)
Added label functionalitz and replaced db_file_path with self.__dbfile as db_file_path was not defined.
--- Added comments ---  uidt6394 [Sep 19, 2011 10:14:27 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.13 2011/08/12 17:39:22CEST Sorin Mogos (mogoss)
* change: changed the order of imported modules
--- Added comments ---  mogoss [Aug 12, 2011 5:39:22 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.12 2011/08/12 09:25:50CEST Sorin Mogos (mogoss)
* change: improved error handling
--- Added comments ---  mogoss [Aug 12, 2011 9:25:50 AM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.11 2011/08/11 13:30:49CEST Sorin Mogos (mogoss)
* fix: some database connection bug-fixes
* fix: improved error handling
--- Added comments ---  mogoss [Aug 11, 2011 1:30:49 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.10 2011/08/09 15:06:34CEST Sorin Mogos (mogoss)
* fix: corrected cat and stk libraries paths
--- Added comments ---  mogoss [Aug 9, 2011 3:06:36 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.9 2011/07/29 13:57:32CEST Sorin Mogos (mogoss)
* fixed paths for pylib and adas_database relative to the valf_db_connector instead of current directory
--- Added comments ---  mogoss [Jul 29, 2011 1:57:32 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.8 2011/07/28 11:59:56CEST Castell Christoph (uidt6394) (uidt6394)
File now uses config data port in order to decide if to import all connections.
--- Added comments ---  uidt6394 [Jul 28, 2011 11:59:56 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.7 2011/07/28 09:11:09CEST Castell Christoph (uidt6394) (uidt6394)
Made change to add all database objects if none are in list. Also added a
port wich provides the database connections to the plugin
modules in the form of a dict.
--- Added comments ---  uidt6394 [Jul 28, 2011 9:11:09 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.6 2011/07/20 18:32:55CEST Castell Christoph (uidt6394) (uidt6394)
Added PreTerminate() function.
--- Added comments ---  uidt6394 [Jul 20, 2011 6:32:55 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.5 2011/07/11 16:42:57CEST Spruck Jochen (spruckj) (spruckj)
restore include path of adas database
--- Added comments ---  spruckj [Jul 11, 2011 4:42:58 PM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.4 2011/07/06 10:32:31CEST Castell Christoph (uidt6394) (uidt6394)
Fixed logging bug.
--- Added comments ---  uidt6394 [Jul 6, 2011 10:32:31 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841

"""
