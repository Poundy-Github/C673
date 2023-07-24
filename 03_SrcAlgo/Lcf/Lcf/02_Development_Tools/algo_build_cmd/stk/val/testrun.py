"""
stk/val/testrun.py
-------------------

    Testrun API class and Testrun Manager implementation

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:45CET $
"""
from os import environ
from sys import _getframe
import logging

from stk.util.logger import Logger
import stk.valf.db_connector as db_con
from stk.db.gbl import gbl as db_gbl
from stk.db.val import val as db_val

from stk.db.val.val import COL_NAME_TR_ID, COL_NAME_TR_NAME, COL_NAME_TR_CHECKPOINT, COL_NAME_TR_DESC, \
    COL_NAME_TR_PARENT, COL_NAME_TR_TYPE_ID, COL_NAME_TR_USERID, COL_NAME_TR_COLL_NAME, \
    COL_NAME_RES_RESDESC_ID, COL_NAME_TR_PID
from stk.db.gbl.gbl import COL_NAME_USER_ID, COL_NAME_USER_LOGIN, COL_NAME_VO_TYPE_NAME, COL_NAME_USER_NAME

from stk.val.results import ValSaveLoadLevel, ValTestcase
from stk.valf import BaseComponentInterface as bci
from stk.valf import signal_defs as sd

# Defines ---------------------------------------------------------------------
NEW_TRUN_CFG_PORT_NAME = 'testruns'
TESTRUN_PORT_NAME = 'trun'

# Classes ---------------------------------------------------------------------


class TestRun(object):  # pylint: disable= R0902
    """ Testrun Class supporting the interface to the result database """

    def __init__(self, name=None, desc=None, checkpoint=None, user=None,
                 obs_name=None, test_collection=None, parent=None, replace=False, proj_name=None):
        # pylint: disable= R0913
        """ constructor of the testrun class
        :param name: Name of the Testrun
        :param desc: Description of the Testrun
        :param checkpoint: Checkpoint to be tested
        :param user: Testers login name
        :param obs_name: Observer name
        :param test_collection: Collection used to run the tests
        :param parent: Parent testrun Identifier
        """
        self.__name = name
        self.__desc = desc
        self.__checkpoint = checkpoint
        self.__user = user
        self.__user_id = None
        self.__obs_name = obs_name
        self.__obs_type_id = None
        self.__test_collection = test_collection
        self.__parent_id = parent
        self.__child_tr = []
        self.__tr_id = None
        self.__testcase_list = []
        self.__replace = replace
        self.__proj_name = proj_name
        self.__pid = None
        self.__user_name = None
        self.__processed_files = None
        self.__processed_time = None
        self.__processed_distance = None

    def __str__(self):
        """ return string text summary of the testrun
        """
        txt = "Testrun: " + str(self.__name) + \
              " CP: " + str(self.__checkpoint)
        return txt

    def Load(self,
             dbi_val,
             dbi_gbl,
             dbi_cat,
             testrun_id=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC):
        # pylint: disable= R0912
        """ Load the testrun from database
        :param dbi_val: Validation Database interface
        :param dbi_gbl: Global Database interface
        :param dbi_cat: Catalog Database interface
        :param testrun_id: Testrun Identifier
        :param level: Database load/store level
        """
        if not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            logging.error("VAL Database interface undefined")
            return False

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False

        if self.__tr_id is not None:
            testrun_id = self.__tr_id

        # check if testrun exists
        if testrun_id is None:
            if self.__proj_name is not None:
                self.__pid = dbi_gbl.GetProjectId(self.__proj_name)
                if self.__pid is None:
                    raise StandardError("Project Name %s doesnt exist in the databse") % self.__proj_name
            else:
                raise StandardError("Project name is mandatory")
        tr_rec = dbi_val.GetTestRun(self.__name, self.__checkpoint,
                                    self.__obs_type_id, self.__user_id,
                                    testrun_id, self.__parent_id, self.__pid)

        if COL_NAME_TR_ID in tr_rec:
            self.__tr_id = tr_rec[COL_NAME_TR_ID]
            self.__name = tr_rec[COL_NAME_TR_NAME]
            self.__desc = tr_rec[COL_NAME_TR_DESC]
            self.__checkpoint = tr_rec[COL_NAME_TR_CHECKPOINT]
            self.__user_id = tr_rec[COL_NAME_TR_USERID]
            self.__obs_type_id = tr_rec[COL_NAME_TR_TYPE_ID]
            self.__test_collection = tr_rec[COL_NAME_TR_COLL_NAME]

            self.__parent_id = tr_rec[COL_NAME_TR_PARENT]
            self.__pid = tr_rec[COL_NAME_TR_PID]
            self.__proj_name = dbi_gbl.GetProjectName(self.__pid)

            rec = dbi_gbl.GetValObserverType(type_id=self.__obs_type_id)
            if COL_NAME_VO_TYPE_NAME in rec:
                self.__obs_name = rec[COL_NAME_VO_TYPE_NAME]

            rec = dbi_gbl.GetUser(user_id=self.__user_id)
            if COL_NAME_USER_LOGIN in rec:
                self.__user = rec[COL_NAME_USER_LOGIN]
                self.__user_name = rec[COL_NAME_USER_NAME]
            self.__child_tr = []
            for ctr_id in dbi_val.GetTestRunIdsForParent(self.__tr_id):
                tr = TestRun()
                if tr.Load(dbi_val, dbi_gbl, dbi_cat, ctr_id) is True:
                    self.__child_tr.append(tr)
                else:
                    logging.error("Testrun could not be loaded with all child testruns")
                    return False

            if level & ValSaveLoadLevel.VAL_DB_LEVEL_2:
                self.__testcase_list = []
                rd_info = dbi_val.GetResultDescriptorInfoForTestrun(self.__name, self.__checkpoint,
                                                                    ValTestcase.TESTCASE_TYPE)

                for item in rd_info:
                    rd_id = item[COL_NAME_RES_RESDESC_ID]
                    tc = ValTestcase()
                    if tc.Load(dbi_val, dbi_gbl, dbi_cat, self.__tr_id,
                               level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
                               rd_id=rd_id) is True:
                        self.__testcase_list.append(tc)
        else:
            logging.error("Testrun with give id does not exist")
            return False

        return True

    def Save(self,
             dbi_val,
             dbi_gbl,
             parent_id=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC):
        # pylint: disable= R0912
        """ Save the Testrun to the data using the given load/store level
        :param dbi_val: Validation Database interface
        :param dbi_gbl: Global Database interface
        :param replace: Replace the existing testrun
        :param level: Database load/store level
        """
        if not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            logging.error("VAL Database interface undefined")
            return False

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False

        # load oberserver type and user identifiers
        if self.__obs_type_id is None:
            self.__obs_type_id = dbi_gbl.GetValObserverTypeId(self.__obs_name)
            if self.__obs_type_id is None:
                logging.error("Observer Type does not exist in the GBL database. Contact the DB Admin")
                return False

        if self.__user_id is None:
            if self.__user is None:
                self.__user = environ["USERNAME"]
            user_rec = dbi_gbl.GetUser(login=self.__user)
            if COL_NAME_USER_ID in user_rec:
                self.__user_id = user_rec[COL_NAME_USER_ID]
                self.__user_name = user_rec[COL_NAME_USER_NAME]

        if self.__desc is None or self.__desc == "":
            self.__desc = str(self)

        if self.__proj_name is not None:
            self.__pid = dbi_gbl.GetProjectId(self.__proj_name)
            if self.__pid is None:
                raise StandardError("Project Name %s doesnt exist in the databse") % self.__proj_name

        else:
# 			Commented Additional function to support ARSXXX projects which is not valid MFCXXX
#            for project_name in dbi_gbl.GetAllProjectName():
#                if project_name.upper() in self.__name.upper():
#                    self.__proj_name = project_name
#                    break
#            if self.__proj_name is not None:
#                self.__pid = dbi_gbl.GetProjectId(self.__proj_name)
#            else:
#                raise StandardError("Project Name is mandatory for TestRun e.g. ARS400, MFC400")
            raise StandardError("Project Name is mandatory for TestRun e.g. ARS400, MFC400")

        tr_rec = {COL_NAME_TR_NAME: self.__name,
                  COL_NAME_TR_DESC: self.__desc,
                  COL_NAME_TR_CHECKPOINT: self.__checkpoint,
                  COL_NAME_TR_COLL_NAME: self.__test_collection,
                  COL_NAME_TR_USERID: self.__user_id,
                  COL_NAME_TR_TYPE_ID: self.__obs_type_id,
                  COL_NAME_TR_PID: self.__pid
                  }

        # overwrite parentid --> parent might be new
        if parent_id is not None:
            tr_rec[COL_NAME_TR_PARENT] = parent_id
            self.__parent_id = parent_id

        elif self.__parent_id is not None:
            tr_rec[COL_NAME_TR_PARENT] = self.__parent_id

        self.__tr_id = dbi_val.AddTestRun(tr_rec, self.__replace)

            # save all child testrun recursive
        for tr in self.__child_tr:
            if self.GetProjectName() == tr.GetProjectName():
                tr.Save(dbi_val, dbi_gbl, self.__tr_id)
            else:
                raise StandardError("Child testrun project must same as its Parent Testrun")

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_4:
            pass

        return True

    def AddChildTestRun(self, child_object):
        """ Add a child testrun
        :param testrun_id: Testrun Identifier
        """
        self.__child_tr.append(child_object)

    def AddTestCase(self, testcase):
        """Add test cases
        param test_cases in a list    """

        if isinstance(testcase, ValTestcase):
            self.__testcase_list.append(testcase)

    def GetChildTestRuns(self):
        """ Get the list of child testruns
        """
        return self.__child_tr

    def GetTestcases(self, inc_child_tr=True):
        """ Get the list of child testruns
        """
        if inc_child_tr:
            tc_list = []
            for tc in self.__testcase_list:
                tc_list.append(tc)
            for ctr in self.GetChildTestRuns():
                for tc in ctr.GetTestcases():
                    tc_list.append(tc)
            return tc_list

        else:
            return self.__testcase_list

    def GetTestCase(self, name=None, spectag=None):
        """
        Get TestCase by Name or TestCaseIdentifier/DOORS Id

        :param name: TestCase Name
        :type name: String
        :return: Instance of ValTestCase
        """
        for tc in self.__testcase_list:
            if name is not None and spectag is None:
                if tc.GetName() == name:
                    return tc
            elif name is None and spectag is not None:
                if tc.GetSpecTag() == spectag:
                    return tc
            elif name is not None and spectag is not None:
                if tc.GetName() == name and tc.GetSpecTag() == spectag:
                    return tc
        return None

    def GetId(self):
        """ Return the Testrun ID of the DB
        An error log will be generated, if it is not set
        """
        if self.__tr_id is None:
            logging.error("Testrun ID is None")
        return self.__tr_id

    def GetName(self):
        """ Return the Testrun Name of the DB
        An error log will be generated, if it is not set
        """
        if self.__name is None:
            logging.error("Testrun Name is None")
        return self.__name

    def GetCheckpoint(self):
        """ Return the Testrun checkpoint label
        An error log will be generated, if it is not set
        """
        if self.__checkpoint is None:
            logging.error("Testrun Name is None")
        return self.__checkpoint

    def GetCollectionName(self):
        """ Return the Testrun Collection Name
        An error log will be generated, if it is not set
        """
        if self.__test_collection is None:
            logging.error("Collection Name is None")
        return self.__test_collection

    def GetObserverName(self):
        """ Return the Testrun Observer Name
        An error log will be generated, if it is not set
        """
        if self.__obs_name is None:
            logging.error("Observer Name is None")
        return self.__obs_name

    def SetReplace(self, replace):
        """ Set Testrun  replace flag of the test run
        """
        self.__replace = replace

    def GetProjectName(self):
        """
        Get project name of the test run
        """
        return self.__proj_name

    @property
    def name(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: Name of Testrun
        :rtype:  string
        """
        return self.GetName()

    @property
    def checkpoint(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: Checkpoint Name.
        :rtype:  string
        """
        return self.GetCheckpoint()

    @property
    def description(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: Description of the Testrun
        :rtype:  string
        """
        return self.__desc

    @property
    def project(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: ProjectName
        :rtype:  string
        """
        return self.GetProjectName()

    @property
    def id(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: ID of Testrun
        :rtype:  string
        """
        return str(self.GetId())

    @property
    def test_cases(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: List of Testcases
        :rtype:  list[`TestCase`,...]
        """
        return self.GetTestcases()



class TestRunManager(bci):  # pylint: disable= R0902
    """ TestrunManager Plugin using the Testrun Class
    """

    def __init__(self, data_manager, component_name, bus_name=["BASE_BUS"]):  # pylint: disable= W0102
        """ Contructor """
        self.__bus_name = bus_name[0]
        self.__component_name = component_name
        self.__data_manager = data_manager
        self.__version = "$Revision: 1.1 $"
        self.__logger = Logger(self.__class__.__name__)

        # database
        self.__valResDB = None
        self.__gblDB = None
        self.__DataBaseObjects = None
        self.__DataBaseObjectsConnections = None

        # signals from Databus
        self.__checkpoint = None
        self.__checkpoint_ref = None
        self.__userName = None
        self.__new_testruns = None
        self.__collection_name = None
        self.__main_test_run = None
        self.__proj_name = None

    # --- Framework functions. --------------------------------------------------
    def Initialize(self):
        """ Initialize. Called once. """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        # get the database object list
        self.__DataBaseObjects = self.__data_manager.GetDataPort("DataBaseObjects", "DBBus#1")
        if self.__DataBaseObjects is None:
            self.__logger.info("'DataBaseObjects' port was not set.")
        else:
            # set the requested data base objects to the connection list
            self.__DataBaseObjects.append(db_gbl)
            self.__DataBaseObjects.append(db_val)
        return bci.RET_VAL_OK

    def PostInitialize(self):
        """ PostInitialize. Called once. """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        self.__DataBaseObjectsConnections = self.__data_manager.GetDataPort(db_con.DATABASE_OBJECTS_CONN_PORT_NAME,
                                                                            "DBBus#1")

        if not self.__DataBaseObjectsConnections:
            self.__logger.warning(db_con.DATABASE_OBJECTS_CONN_PORT_NAME + " port was not set.")
        else:
            for connObject in self.__DataBaseObjectsConnections:
                if connObject.strIdent == db_val.IDENT_STRING:
                    self.__valResDB = connObject
                elif connObject.strIdent == db_gbl.IDENT_STRING:
                    self.__gblDB = connObject

        if self.__valResDB is None:
            self.__logger.error("Database connection to validation results could not be established")
        if self.__gblDB is None:
            self.__logger.error("Database connection to global could not be established")

        ret = self.__ProcessTestRuns()
        self.__data_manager.SetDataPort(TESTRUN_PORT_NAME, self.__main_test_run)
        return ret

    def LoadData(self):
        """ LoadData. Called for each file. """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return bci.RET_VAL_OK

    def ProcessData(self):
        """ ProcessData. Called for each file. """
        self.__logger.info(str(_getframe().f_code.co_name) + "()" + " called.")
        return bci.RET_VAL_OK

    def PostProcessData(self):
        """ PostProcessData. Called for each file. """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return bci.RET_VAL_OK

    def PreTerminate(self):
        """ PreTerminate. Called once. """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return bci.RET_VAL_OK

    def Terminate(self):
        """ Terminate. Called once. """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        self.__new_testruns = None
        self.__main_test_run = None
        return bci.RET_VAL_OK

    def __ProcessTestRuns(self):
        """ Process given testrun structure
        """
        ret = bci.RET_VAL_OK
        self.__checkpoint = self.__data_manager.GetDataPort(sd.SWVERSION_PORT_NAME)
        self.__checkpoint_ref = self.__data_manager.GetDataPort(sd.SWVERSION_REG_PORT_NAME)
        self.__proj_name = self.__data_manager.GetDataPort("ProjectName")
        self.__collection_name = self.__data_manager.GetDataPort(sd.COLLECTION_NAME_PORT_NAME)
        self.__new_testruns = self.__data_manager.GetDataPort(NEW_TRUN_CFG_PORT_NAME, self.__bus_name)
        save_to_db = self.__data_manager.GetDataPort(sd.SAVE_RESULT_IN_DB)
        # self.__readTestRunConfig()
        main_test_run = self.__DecodeTestRunConfig(self.__new_testruns)

        if save_to_db is None:
            save_to_db = True

        if main_test_run is not None and save_to_db is True:
            if main_test_run.Save(self.__valResDB, self.__gblDB) is True:
                self.__valResDB.Commit()
            else:
                self.__logger.error("Root Testrun could not be saved. Check error log")
                ret = bci.RET_VAL_ERROR

        self.__main_test_run = main_test_run

        return ret

    def __DecodeTestRunConfig(self, testrun_list):
        """ Decode the Testrun Configuration list
        :param testrun_list: List of testrun Configuration items
        """
        root_tr = None
        parent_key_names = {}
        tr_dict = {}

        for item in testrun_list:
            key = item['cfg_name']
            is_active = bool(item['active'] == 'True')
            name = item['tr_name']
            val_obs_name = item['val_obs_name']
            parent_key = item['parent_cfg_name']
            level = int(item['level'])
            use_ref = bool(item['use_ref'] == 'True')
            replace = bool(item['replace'] == 'True')

            if is_active:
                cp = self.__checkpoint
                if use_ref:
                    cp = self.__checkpoint_ref

                tr = TestRun(name=name, desc="", checkpoint=cp,
                             user=environ["USERNAME"], obs_name=val_obs_name,
                             test_collection=self.__collection_name, parent=None, replace=replace,
                             proj_name=self.__proj_name)
                # add the testrun to the dictionary
                if key not in tr_dict:
                    tr_dict[key] = tr
                    parent_key_names[key] = parent_key
                else:
                    self.__logger.error(" The testrun name key is already in use. Check your config file")

                # check the root testrun
                if level == 0:
                    if root_tr is None:
                        root_tr = tr
                    else:
                        self.__logger.error(" The root testrun is defined twice. Check your config file")
                        raise

        # map the testruns
        for key, tr in tr_dict.iteritems():
            if parent_key_names[key] is not None and tr is not root_tr:
                if key in tr_dict:
                    tr_dict[parent_key_names[key]].AddChildTestRun(tr)
                else:
                    self.__logger.error("Parent name key not found: '%s'. Check your config file" % key)
                    raise

        return root_tr

"""
CHANGE LOG:
-----------
$Log: testrun.py  $
Revision 1.1 2021/12/13 17:59:45CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/val/project.pj
Revision 1.19 2013/12/15 21:22:04CET Hecker, Robert (heckerr) 
Corrected Description
- Added comments -  heckerr [Dec 15, 2013 9:22:05 PM CET]
Change Package : 210873:1 http://mks-psad:7002/im/viewissue?selection=210873
Revision 1.18 2013/12/15 20:23:54CET Hecker, Robert (heckerr)
Added Interface for AlgoTestReport.
--- Added comments ---  heckerr [Dec 15, 2013 8:23:54 PM CET]
Change Package : 210873:1 http://mks-psad:7002/im/viewissue?selection=210873
Revision 1.17 2013/11/25 09:41:46CET Ahmed-EXT, Zaheer (uidu7634)
Get Testcases more procise with arguement to get testcases including childs tr or the testcase from current testrun
improve GetTestCase function with additional creteria of DOORS ID to get specific testcase
--- Added comments ---  uidu7634 [Nov 25, 2013 9:41:47 AM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.16 2013/11/11 15:20:54CET Ahmed-EXT, Zaheer (uidu7634)
fix pep8 and pylint
Added GetTestCase(name) function to get test name by given name
Revision 1.15 2013/11/05 15:09:05CET Ahmed-EXT, Zaheer (uidu7634)
LoadLevel testcases set to Basic for Testrun.Load()
Commented extraction of ProjectName  from Testrun name functionality
--- Added comments ---  uidu7634 [Nov 5, 2013 3:09:05 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.14 2013/11/04 10:27:52CET Ahmed-EXT, Zaheer (uidu7634)
Pep8 fix
--- Added comments ---  uidu7634 [Nov 4, 2013 10:27:52 AM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.13 2013/10/31 17:50:33CET Ahmed-EXT, Zaheer (uidu7634)
Added support for Project ID as manadatory field in Testrun and TestManager class
Revision 1.12 2013/10/30 19:46:41CET Hecker, Robert (heckerr)
Removed indirect usage of logging module.
--- Added comments ---  heckerr [Oct 30, 2013 7:46:41 PM CET]
Change Package : 204155:1 http://mks-psad:7002/im/viewissue?selection=204155
Revision 1.11 2013/10/01 10:36:22CEST Raedler, Guenther (uidt9430)
- added new option to save the testruns into the DB
- set dataport with main testrun
--- Added comments ---  uidt9430 [Oct 1, 2013 10:36:22 AM CEST]
Change Package : 197855:1 http://mks-psad:7002/im/viewissue?selection=197855
Revision 1.10 2013/08/07 12:53:36CEST Ahmed-EXT, Zaheer (uidu7634)
GetObserverName and GetCollectionName function Added into TestRun Class
--- Added comments ---  uidu7634 [Aug 7, 2013 12:53:36 PM CEST]
Change Package : 192688:1 http://mks-psad:7002/im/viewissue?selection=192688
Revision 1.9 2013/07/25 10:08:47CEST Raedler, Guenther (uidt9430)
- use testrun name and checkpoint for database selection
--- Added comments ---  uidt9430 [Jul 25, 2013 10:08:48 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.8 2013/07/15 09:53:28CEST Raedler, Guenther (uidt9430)
- add a Testcase to the testrun
--- Added comments ---  uidt9430 [Jul 15, 2013 9:53:28 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.7 2013/05/23 11:41:17CEST Mertens, Sven (uidv7805)
aligning imports and stk.db connections
--- Added comments ---  uidv7805 [May 23, 2013 11:41:18 AM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.6 2013/05/13 14:50:49CEST Ahmed-EXT, Zaheer (uidu7634)
Fixed reloading bug and create testrun without replacement to mantain hirachechal tree
added SetReplace method
--- Added comments ---  uidu7634 [May 13, 2013 2:50:50 PM CEST]
Change Package : 178419:4 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.5 2013/05/07 12:53:12CEST Ahmed-EXT, Zaheer (uidu7634)
Changes according to new structure of test run manager input config
--- Added comments ---  uidu7634 [May 7, 2013 12:53:12 PM CEST]
Change Package : 178419:4 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.4 2013/05/03 14:10:23CEST Ahmed-EXT, Zaheer (uidu7634)
Changes according to TestRunManager Apporach Added replace flag for invidual checkpoint entry
--- Added comments ---  uidu7634 [May 3, 2013 2:10:23 PM CEST]
Change Package : 178419:2 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.3 2013/04/23 15:00:17CEST Raedler, Guenther (uidt9430)
- implemented parser for testrun manager
- fixed minor errors in testrun class
--- Added comments ---  uidt9430 [Apr 23, 2013 3:00:18 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.2 2013/04/22 16:33:27CEST Raedler, Guenther (uidt9430)
- added new class testrun
- added usage of testrun class in testrun manager
--- Added comments ---  uidt9430 [Apr 22, 2013 4:33:27 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.1 2013/04/16 13:08:46CEST Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/05_Testing/05_Test_Environment/algo/stk/val/project.pj
"""
