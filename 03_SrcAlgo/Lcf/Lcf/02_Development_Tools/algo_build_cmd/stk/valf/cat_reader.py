"""
stk/valf/cat_reader
---------------

The component for reading mts batch play list.

:org:           Continental AG
:author:        Sorin Mogos

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:51CET $
"""

# pylint: disable=C0103

# Import Python Modules -------------------------------------------------------
from os import path, listdir
from sys import _getframe
from inspect import currentframe
from re import findall

# Import STK Modules ----------------------------------------------------------
from stk.db.cat import cat
from stk.valf import BaseComponentInterface
from stk.util.logger import Logger

# Defines ---------------------------------------------------------------------
VALF_DIR = path.dirname(path.abspath(currentframe().f_code.co_filename))

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------

# Main Entry Point ------------------------------------------------------------


class CATReader(BaseComponentInterface):
    """
    Observer class to handle Batch Play Lists provided by Catalog DB
    called by Process_Manager during the different states:
    - Initialize: read the catalog db list
    - LoadData: provide the next rec file name
    - PostInitialize, ProcessData to Terminate: dummy

    Ports used on bus "Global":
      - read "DataBaseObjects": not used anymore (set by db_connector)
      - read "DataBaseObjectsConnections": list of db connections providing the catalog (set by db_connector)
      - read "RecCatCollectionName": name of rec file list in catalog db (mandatory)
      - read "ExactMatch": if 'True' exact matching between the files given in the collection and the sim results (opt)
      - read "SimOutputPath": path to simulation output files (mandatory)
      - read "SimFileExt": opt. file extension of simulation files, default .csv
      - read "SimFileBaseName": opt. base name of simulation files
      - read "SimSelection": opt. list of indices to use only particular recordings (list starts with '0')
                             e.g. "[ 1, 3, 5, 7, 9]" or shorter "[(1,10,2)]" (syntax as in range() )
      - read 'IsFileComplete': check if file processing is finished (set by observer)
                               prevents setting "IsFinished" if set to True
      - read 'NextSection':
      - set  "CurrentCollectionNames": current DB collection of file
      - set  "CurrentFile": name of current sim output file
      - set  "CurrentSimFile": name of current rec file
      - set  "IsFinished": True if last file was provided
      - set  "FileCount": number of measurement files in catalog list
    """
    def __init__(self, data_manager, component_name, bus_name=["BUS_BASE"]):  # pylint: disable=W0102
        self.__bus_name = bus_name[0]
        self.__component_name = component_name
        self.__data_manager = data_manager

        self.__logger = Logger(self.__component_name)
        self.__logger.debug()

        self.__version = "$Revision: 1.1 $"

        self.__current_meas_file = ""
        self.__current_sim_file = ""

        self.__reader = None
        self.__meas_file_list = None
        self.__sim_file_list = None
        self.__sim_selection = None

        self.__cat_collection_name = None

        self.__exactMatch = None
        self.__db_bus = None
        self.__DataBaseObjects = None
        self.__DataBaseObjectsConnections = None

        self.__RecCatDB = None

    def Initialize(self):
        self.__logger.debug()

        self.__data_manager.RegisterDataPort("CurrentFile", None)
        self.__data_manager.RegisterDataPort("CurrentSimFile", None, self.__bus_name)
        self.__data_manager.RegisterDataPort("IsFinished", None)
        self.__data_manager.RegisterDataPort("FileCount", None)

        self.__data_manager.SetDataPort("IsFinished", False)

        # get the database object list
        self.__db_bus = self.__data_manager.GetDataPort("DBBus", self.__bus_name)
        if self.__db_bus is None:
            self.__db_bus = "DBBus#1"
        self.__DataBaseObjects = self.__data_manager.GetDataPort("DataBaseObjects", self.__db_bus)
        self.__DataBaseObjects.append(cat)

        # get the collection name
        self.__cat_collection_name = str(self.__data_manager.GetDataPort("RecCatCollectionName")).strip()
        if not self.__cat_collection_name:
            self.__logger.error("'RecCatCollectionName' port was not set.")
            return -1
        else:
            self.__logger.info("Using catalogue collection: '%s'." % str(self.__cat_collection_name))

        # Use and exact match or not
        self.__exactMatch = self.__data_manager.GetDataPort("ExactMatch", self.__bus_name)
        if self.__exactMatch is None:
            self.__logger.info("'ExactMatch' port was not set.")
        else:
            self.__logger.info("Using exact match for bin file search")

        # Use post selection of sim files if defined
        self.__sim_selection = self.__data_manager.GetDataPort("SimSelection")
        if self.__sim_selection is not None:
            self.__sim_selection = eval(self.__sim_selection)
            self.__logger.info("'SimSelection' set to %s." % str(self.__sim_selection))
        # Done
        return 0

    def PostInitialize(self):
        self.__logger.debug()

        # Get the database connection
        self.__DataBaseObjectsConnections = self.__data_manager.GetDataPort("DataBaseObjectsConnections",
                                                                            self.__db_bus)
        if self.__DataBaseObjectsConnections is None:
            self.__logger.error("'DataBaseObjectsConnections' port was not set.")
            return -1
        else:
            for connObject in self.__DataBaseObjectsConnections:
                if connObject.strIdent == cat.IDENT_STRING:
                    self.__RecCatDB = connObject
                    break

            if self.__RecCatDB is None:
                self.__logger.error("Database connection to recfile catalogue could not be established")

        # Get the collection ID
        try:
            collid = self.__RecCatDB.GetCollectionID(self.__cat_collection_name)
            if collid is not None:
                # read the files from the collection
                self.__reader = self.__RecCatDB.GetCollectionMeasurements(collid, recfile_paths=True)
            else:
                self.__logger.error("Collection with name %s not found" % (self.__cat_collection_name))
        except Exception, ex:  # pylint: disable=W0703
            self.__logger.error("Could not get collection id due to '%s'." % str(ex))
            return -1

        if len(self.__reader) == 0:
            self.__logger.warning("No recording entries found for '%s' collection." % self.__cat_collection_name)
            return -1

        self.__logger.info("%d recording file(s) have been found for '%s' collection." %
                           (len(self.__reader), self.__cat_collection_name))

        # select only particular rec files if configured
        # to run on HPC and for developing/debugging usage
        if self.__sim_selection is not None:
            rec_file_list = []
            for sel in self.__sim_selection:
                if type(sel) == tuple:
                    sub_list = slice(*sel)  # pylint: disable=W0142
                else:
                    sub_list = slice(sel, sel + 1)
                rec_add = self.__reader[sub_list]
                if len(rec_add) > 0:
                    rec_file_list.extend(rec_add)
                    self.__logger.debug("select rec index %s: %s" % (sel, rec_add))
            self.__logger.info("selected %s recording file(s) for '%s' collection." %
                               (len(rec_file_list), self.__cat_collection_name))
        else:
            rec_file_list = self.__reader

        sim_file_path = str(self.__data_manager.GetDataPort("SimOutputPath", self.__bus_name)).strip()
        if not sim_file_path:
            self.__logger.error("'SimOutputPath' port was not set.")
            return -1

        sim_file_ext_list = []
        sim_file_ext = self.__data_manager.GetDataPort("SimFileExt", self.__bus_name)
        if not sim_file_ext:
            sim_file_ext_list = ["csv"]
            self.__logger.warning("'SimFileExt' port was not set. Default used instead: '%s'" % sim_file_ext_list[0])
        elif type(sim_file_ext) == str:
            sim_file_ext_list = [sim_file_ext]
        elif type(sim_file_ext) == list:
            sim_file_ext_list = sim_file_ext
        else:
            self.__logger.error("Invalid sim file extension: '%s'!" % str(sim_file_ext))
            return -1

        sim_file_base_name = ""
        sim_file_base = self.__data_manager.GetDataPort("SimFileBaseName", self.__bus_name)
        if sim_file_base is not None:
            sim_file_base_name = sim_file_base

        sim_file_path = str(path.abspath(sim_file_path))
        if not path.isdir(sim_file_path):
            self.__logger.error("Simulation output path '%s' doesn't exist." % sim_file_path)
            return -1

        self.__meas_file_list = []
        self.__sim_file_list = []
        files_bin_dir = str(listdir(sim_file_path))

        for idx in xrange(len(rec_file_list)):
            file_name = path.splitext(path.split(str(rec_file_list[idx]))[1])[0]
            sim_file_path_list = []
            for file_ext in sim_file_ext_list:
                if file_ext[0] == ".":
                    file_ext = file_ext[1:]

                pattern = r"[\.\w\_\-\+]*%s+[\.\w\_\-\+]*%s.%s" % (file_name, sim_file_base_name, file_ext)
                matches = findall(pattern, files_bin_dir)

                if self.__exactMatch is True:
                    if (file_name + "." + file_ext) in matches:
                        sim_file_path_list.append(path.join(sim_file_path, (file_name + "." + file_ext)))
                else:
                    for match in matches:
                        sim_file_path_list.append(path.join(sim_file_path, match))

            if len(sim_file_path_list) > 0:
                self.__meas_file_list.extend([rec_file_list[idx]] * len(sim_file_path_list))
                self.__sim_file_list.extend(sim_file_path_list)
            else:
                self.__logger.warning("No simulation file found for '%s' with given extension: %s" %
                                      (rec_file_list[idx], str(sim_file_ext_list)))

        self.__logger.debug("simulation list has %i files" % len(self.__meas_file_list))

        if len(self.__meas_file_list) == 0:
            self.__logger.error("No simulation file found for '%s'" % self.__cat_collection_name)
            return -1

        self.__data_manager.SetDataPort("FileCount", len(self.__meas_file_list))

        self.__meas_file_list.reverse()
        self.__sim_file_list.reverse()

        return 0

    def LoadData(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        file_completed = self.__data_manager.GetDataPort('IsFileComplete', self.__bus_name)
        next_section_last = self.__data_manager.GetDataPort('NextSection', self.__bus_name)
        if file_completed is None:
            # Load full files
            # Load next measurement file
            self.__current_meas_file = self.__meas_file_list.pop()
            # Load next simulation file
            self.__current_sim_file = self.__sim_file_list.pop()

            if self.__cat_collection_name is not None:
                try:
                    colNames = self.__RecCatDB.GetMeasurementCollectionNames(self.__current_meas_file)
                    # Get collection names assigned to this recording
                    self.__data_manager.SetDataPort("CurrentCollectionNames",
                                                    colNames,
                                                    self.__bus_name)
                except Exception, ex:  # pylint: disable=W0703
                    self.__logger.warning("Could not get measurement collection names due to '%s'." % str(ex))

            if len(self.__meas_file_list) == 0:
                # Set next measurement file
                self.__data_manager.SetDataPort("CurrentFile", self.__current_meas_file)

                # Set next simulation file
                self.__data_manager.SetDataPort("CurrentSimFile", self.__current_sim_file, self.__bus_name)

                self.__logger.info("Loading file: '%s'" % self.__current_sim_file)

                self.__data_manager.SetDataPort("IsFinished", True)
                return 0
        else:
            if file_completed is False and next_section_last is True:
                if len(self.__meas_file_list) == 0:
                    # Final call
                    self.__data_manager.SetDataPort("IsFinished", True)
                    return 0
            elif file_completed is True and next_section_last is False:
                if len(self.__meas_file_list) == 0:
                    return 0
                # Load next measurement file
                self.__current_meas_file = self.__meas_file_list.pop()
                # Load next simulation file
                self.__current_sim_file = self.__sim_file_list.pop()
            elif file_completed is False and next_section_last is False:
                if len(self.__current_meas_file) == 0:
                # First run
                    self.__current_meas_file = self.__meas_file_list.pop()
                    # Load next simulation file
                    self.__current_sim_file = self.__sim_file_list.pop()

        # Set next measurement file
        self.__data_manager.SetDataPort("CurrentFile", self.__current_meas_file)

        # Set next simulation file
        self.__data_manager.SetDataPort("CurrentSimFile", self.__current_sim_file, self.__bus_name)

        self.__logger.info("Loading file: '%s'" % self.__current_sim_file)

        return 0

    def ProcessData(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def PostProcessData(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def PreTerminate(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def Terminate(self):
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

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
$Log: cat_reader.py  $
Revision 1.1 2021/12/13 17:59:51CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.12 2013/05/29 13:52:19CEST Mertens, Sven (uidv7805) 
adding pylint ignores locally,
removing isinstance (as explained)
- Added comments -  uidv7805 [May 29, 2013 1:52:19 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
add feature "SimSelection" to enter list of indices for particular bpl/cat list selection
--- Added comments ---  uidv8815 [May 22, 2013 5:57:00 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.10 2013/04/19 12:50:10CEST Hecker, Robert (heckerr)
Functionality revert to version 1.8.
--- Added comments ---  heckerr [Apr 19, 2013 12:50:10 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/04/12 14:46:57CEST Mertens, Sven (uidv7805)
enabling the use of a connection string on observer level.
Each of them is allowed to have an additional InputData in config,
e.g. ("connectionString", "DBQ=racadmpe;Uid=DEV_MFC31X_ADMIN;Pwd=MFC31X_ADMIN"),("dbPrefix", "DEV_MFC31X_ADMIN.").
--- Added comments ---  uidv7805 [Apr 12, 2013 2:46:57 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.8 2013/03/28 15:25:12CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:13 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/28 14:20:04CET Mertens, Sven (uidv7805)
pylint: solving some W0201 (Attribute %r defined outside __init__) errors
--- Added comments ---  uidv7805 [Mar 28, 2013 2:20:04 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/28 09:33:14CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:14 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.5 2013/03/01 10:23:22CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:22 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/28 08:12:18CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:18 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/26 20:18:04CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:18:05 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/20 08:21:25CET Hecker, Robert (heckerr)
Adapted to Pep8 Coding Style.
--- Added comments ---  heckerr [Feb 20, 2013 8:21:26 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 11:06:05CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.13 2012/08/22 09:35:31CEST Mogos, Sorin (mogoss)
* update: added optinal port 'ExactMatch' for exact matchng between the
files given in the collection and the simulation binaries
--- Added comments ---  mogoss [Aug 22, 2012 9:35:34 AM CEST]
Change Package : 155168:1 http://mks-psad:7002/im/viewissue?selection=155168
Revision 1.12 2012/07/20 13:38:52CEST Raedler-EXT, Guenther (uidt9430)
- improved parsing of sim_output folder. Use regex instead of glob.glob()
--- Added comments ---  uidt9430 [Jul 20, 2012 1:38:53 PM CEST]
Change Package : 136608:1 http://mks-psad:7002/im/viewissue?selection=136608
Revision 1.11 2012/04/24 11:59:40CEST Spruck, Jochen (spruckj)
Add the posibility to read in only export files with a defined post fix name to the recfilename
--- Added comments ---  spruckj [Apr 24, 2012 11:59:41 AM CEST]
Change Package : 98074:3 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.10 2011/10/31 11:40:12CET Mogos, Sorin (mogoss)
* change: changed stk library path
--- Added comments ---  mogoss [Oct 31, 2011 11:40:13 AM CET]
Change Package : 85403:1 http://mks-psad:7002/im/viewissue?selection=85403
Revision 1.9 2011/08/25 14:59:01CEST Sorin Mogos (mogoss)
* change: remove bpl related code
--- Added comments ---  mogoss [Aug 25, 2011 2:59:02 PM CEST]
Change Package : 75815:1 http://mks-psad:7002/im/viewissue?selection=75815
Revision 1.8 2011/08/12 17:43:39CEST Sorin Mogos (mogoss)
* update: added support for bpl file in case that it's set and  collection not specified
--- Added comments ---  mogoss [Aug 12, 2011 5:43:39 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.7 2011/08/11 13:30:49CEST Sorin Mogos (mogoss)
* fix: some database connection bug-fixes
* fix: improved error handling
--- Added comments ---  mogoss [Aug 11, 2011 1:30:49 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.6 2011/08/10 12:48:18CEST Sorin Mogos (mogoss)
* fix: unicode to ascii conversion for meas file
--- Added comments ---  mogoss [Aug 10, 2011 12:48:18 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
"""
