"""
stk/val/base_results.py
-------------------

Subpackage for Handling Basic Validation Results.

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:45CET $
"""
# Import Python Modules -------------------------------------------------------
import re
import logging
import warnings
# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------
import stk.db.gbl.gbl as db_gbl
import stk.db.val.val as db_val
import stk.db.cat.cat as db_cat

from stk.db.db_common import SQLite3BaseDB
from stk.db.val.val import COL_NAME_RES_ID, COL_NAME_RES_TESTRUN_ID, COL_NAME_RES_RESDESC_ID, \
    COL_NAME_RES_VALUE, COL_NAME_RES_MEASID, COL_NAME_RES_RESASSID, \
    COL_NAME_RESULTTYPE_NAME, COL_NAME_RESULTTYPE_DESC, COL_NAME_RESULTTYPE_CLASS, \
    COL_NAME_RESDESC_NAME, COL_NAME_RESDESC_COLLID, COL_NAME_RESDESC_RESTYPE_ID, \
    COL_NAME_RESDESC_UNIT_ID, COL_NAME_RESDESC_PARENT, COL_NAME_RESDESC_REFTAG, \
    COL_NAME_RESVAL_ID, COL_NAME_RESVAL_SUBID, COL_NAME_RESVAL_VALUE, \
    COL_NAME_RESIMG_ID, COL_NAME_RESIMG_IMAGE, COL_NAME_RESIMG_TITLE, COL_NAME_RESIMG_FORMAT, COL_NAME_RESDESC_ID, \
    COL_NAME_RESULTTYPE_ID, COL_NAME_RESDESC_DOORS_URL, COL_NAME_RESDESC_EXPECTRES, COL_NAME_RESDESC_DESCRIPTION

from stk.db.gbl.gbl import COL_NAME_UNIT_ID, COL_NAME_UNIT_NAME, COL_NAME_UNIT_TYPE, COL_NAME_UNIT_LABEL
from asmt import ValAssessment, ValAssessmentStates, ValAssessmentWorkFlows
from stk.db.gbl import GblUnits
from result_types import BaseUnit, BaseValue, ValueVector, Signal, Histogram, ValSaveLoadLevel
from stk.img import ValidationPlot
# from base_events import ValBaseEvent
from events import ValEventList
from stk.obj.ego import EgoMotion
from stk.util.helper import Sec2HmsString
# Import Local Python Modules -------------------------------------------------
#
# Class Implementations -------------------------------------------------------


class ValTestcase(object):
    """ Testcase Class
        # Result descriptor tree stored inside the database
        # the links a build by a parent relation
        RD(1): VAL_TESTCASE
        |
        \-> RD(3): Testcase result 1
        \-> RD(4): Testcase result 2
        \-> RD(2): VAL_TESTCASE_SUB_MEASRES -- for measurement results
            |
            \-> RD(5) file result 1
            \-> RD(6) file result 2
        \-> RD(7): VAL_TESTCASE_SUB_EVENTS -- for event results
            \-> RD(8) event description
        #
        # Result tree example with two measurements
        TR -> Res(1) -> RD(1)
           -> Res(2) -> RD(3)
           -> Res(3) -> RD(4)
           -> Res(4) -> RD(5) -> measid(0)
           -> Res(5) -> RD(5) -> measid(1)
           -> Res(6) -> RD(6) -> measid(0)
           -> Res(7) -> RD(6) -> measid(1)
           ...
           -> Res(8) -> RD(7)
    """
    TESTCASE_TYPE = "VAL_TESTCASE"
    TESTCASE_UNIT = "none"
    SUB_MEASRES = "VAL_TESTCASE_SUB_MEASRES"
    SUB_EVENTS = "VAL_TESTCASE_SUB_EVENTS"
    TEST_STEP = "VAL_TESTSTEP"

    MEAS_DIST_PROCESS = SUB_MEASRES + "_DIST_PROC"
    MEAS_TIME_PROCESS = SUB_MEASRES + "_TIME_PROC"

    def __init__(self, name=None, coll_id=None, specification_tag=None,
                 doors_url="", exp_res="", desc=""):
        """ initialize base class for the testcase prepare all locals

        :param name: Testcase Name e.g. "ALN EOL State"
        :type name: String
        :param coll_id: Testcase Collection Identifier
        :type coll_id: int
        :param specification_tag: Doors Specification ID also known as Test Case identifier
                                  e.g. "ACC_TC_001_001", "ALN_TC_004_005"
        :type specification_tag: String
        :param doors_url: Doors URL link to Test case specification
            e.g. "doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-M-0001cbf1"
        :type doors_url: String
        :param exp_res: Expected result e.g. "average error < .053"
        :type exp_res: String
        :param desc: Description text of the Testcase
        :type desc: String


        """
        self.__testresults = []  # List of Testcase Results
        self.__measresults = []  # List of File Results
        self.__teststeps = []  # List of teststeps
        self.__teststep_ids = []  # List of rdid only for teststeps
        self.__events = ValEventList()  # Class managing events
        self.__name = name  # Unique Testcase Name
        self.__spec_tag = specification_tag  # Specification ID (Doors)
        self.__coll_id = coll_id
        self.__coll_name = None
        self.__rd_id = None
        self.__rd_meas_sub_id = None
        self.__rd_ev_sub_id = None
        self.__doors_url = doors_url
        self.__exp_res = exp_res
        self.__desc = desc
        self.__asses = None
        self.__total_time = float(0)
        self.__total_dist = float(0)
        self.__mesdist_ressname = None
        self.__mestime_ressname = None

    def __str__(self):
        """ return string text summary of the testcase
        """
        txt = "Testcase: '" + self.__name + "' DoorsId: '" + self.__spec_tag + "' \n"
        for res in self.GetResults(None):
            txt += str(res)
        return txt

    def GetName(self):
        """ Get the Name of the testcase e.g. "Dropin Rate", "EOL initialzation"

        :return: name of the test case as String e.g. "ALN EOL State"
        """

        return self.__name

    def GetSpecTag(self):
        """
        Get Doors ID of the testcase also known as Test Case identifier e.g. "ACC_TC_001_001"

        :return: Specification tag as String
        """
        return self.__spec_tag

    def GetCollectionName(self):
        """
        Get Collectionname associated with Testcase e.g. "ARS400_acc_endurance"

        :return: Collection as String
        """
        return self.__coll_name

    def GetDoorsURL(self):
        """
        Get Doors URL
        e.g. "doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-M-0001cbf1"

        :return: DOORS URL as String
        """
        return self.__doors_url

    def GetExpectedResult(self):
        """
        Get Expected Result of the testcase
        e.g. "average error < .053" , "dropin rate< 1.55"

        :return: Expected result of the testcase as String
        """
        return self.__exp_res

    def GetDescription(self):
        """
        Get Testcase Description text
        :return: Test case Description as String
        """
        return self.__desc

    def GetTestSteps(self):
        """
        Get list of teststeps under the current Testcase

        :return: List of objects whic are instance of ValTestStep class
        """
        return self.__teststeps

    def GetAssessment(self):
        """
        Get Assessment of the testcase which evaluated based on the Assessment of TestSteps
        The testcase Assessment is not Stored or Loaded from Database
        """
        if len(self.__teststeps) > 0:
            self.__asses = self.__EvaluateAssessment()
        else:
            self.__asses = ValAssessment(user_id=None,
                                         wf_state=ValAssessmentWorkFlows.ASS_WF_AUTO,
                                         ass_state=ValAssessmentStates.NOT_ASSESSED,
                                         ass_comment="Couldnt Evaluated Assessment because"
                                         + "teststep are not loaded or available",
                                         issue="Issues to be assigned in invidual Teststeps if needed")
        return self.__asses

    def __EvaluateAssessment(self):
        """
        Automatic Assessment evaluate function for TestCase
        """
        ts_ass_states = []
        asses_state = ValAssessmentStates.NOT_ASSESSED
        comment = ""
        for teststep in self.__teststeps:
            assess = teststep.GetAssessment()
            if assess is None:
                ts_ass_states.append(ValAssessmentStates.NOT_ASSESSED)
                comment += "teststep: %s has no Assessment available\n" % teststep.GetName()
            else:
                if assess.GetAssesmentState() == ValAssessmentStates.FAILED:
                    comment += "teststep: %s is Failed\n" % teststep.GetName()
                elif assess.GetAssesmentState() == ValAssessmentStates.NOT_ASSESSED:
                    comment += "teststep: %s is Not Assessed\n" % teststep.GetName()
                elif assess.GetAssesmentState() == ValAssessmentStates.INVESTIGATE:
                    comment += "teststep: %s has pending investigation\n" % teststep.GetName()
                elif assess.GetAssesmentState() == ValAssessmentStates.PASSED:
                    comment += "teststep: %s is Passed\n" % teststep.GetName()
                else:
                    comment += "teststep: %s Assessment is Unkown \n" % teststep.GetName()
                    ts_ass_states.append(ValAssessmentStates.FAILED)
                ts_ass_states.append(assess.GetAssesmentState())

        if ValAssessmentStates.FAILED in ts_ass_states:
            asses_state = ValAssessmentStates.FAILED
        elif ValAssessmentStates.NOT_ASSESSED in ts_ass_states:
            asses_state = ValAssessmentStates.NOT_ASSESSED
        elif ValAssessmentStates.INVESTIGATE in ts_ass_states:
            asses_state = ValAssessmentStates.INVESTIGATE
        else:
            asses_state = ValAssessmentStates.PASSED

        return ValAssessment(user_id=None,
                             wf_state=ValAssessmentWorkFlows.ASS_WF_AUTO,
                             ass_state=asses_state,
                             ass_comment=comment,
                             issue="Issues to be assigned in invidual Teststeps if needed")

    def __IsSubType(self, dbi_val, rdid):  # pylint: disable=R0201
        """ Is the result descriptor a sub-type

        :param dbi_val: Validation Database interface
        :type dbi_val: database interface object which is instance of OracleValResDB or  SQLite3ValResDB
                        to target Databsae oracle or sqlite respectively
        :param rdid: Result Descriptor Identifier to be checked
        :type rdid: int
        :return: True on match otherwise False
        """
        sub_type_list = [ValTestcase.SUB_MEASRES, ValTestcase.SUB_EVENTS]

        rec_rd = dbi_val.GetResultDescriptorWithId(rdid)
        if rec_rd is not None:
            type_name = rec_rd["TYPE_" + COL_NAME_RESULTTYPE_NAME]
            if  type_name in sub_type_list:
                return True
        return False

    def Load(self,
             dbi_val, dbi_gbl, dbi_cat,
             testrun_id,
             obs_name=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
             cons_key=None,
             rd_id=None):
        # pylint: disable=R0201, R0912, R0913, R0915, W0613
        """ Load the testcase settings from database
            Note: Events and File results under the testcase are loaded seperately
            with Addtional Load methods LoadEvents() and LoadFileResults() respectively

        :param dbi_val: Validation Database interface
        :type dbi_val: database interface object which is instance of OracleValResDB or  SQLite3ValResDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_gbl: Global Database interface
        :type dbi_gbl:  database interface object which is instance of  OracleGblDB or SQLite3GblDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_cat: Catalog Database interface
        :type dbi_cat: database interface object which is instance of OracleRecCatalogDB or  OracleRecCatalogDB
                        to target Databsae oracle or sqlite respectively
        :param obs_name: Observer Name e.g. "ACC_DROPIN_OBSERVER"
        :type obs_name:  String
        :param level: Database load/store level e.g.ValSaveLoadLevel.VAL_DB_LEVEL_INFO default is VAL_DB_LEVEL_BASIC
                      VAL_DB_LEVEL_BASIC --> Load only Test case basic information
                                          e.g. specfication doors url and test case name, tese case result
                                               expected result
                      VAL_DB_LEVEL_INFO --> include load of VAL_DB_LEVEL_BASIC and additionally load
                                            TestSteps under the given Testcase
                                          and their assessment
                      VAL_DB_LEVEL_ALL --> include load of VAL_DB_LEVEL_INFO and additionally load
                                          plot, images and complete detail associated with test case result
        :type level: int
        :param cons_key: contraint key for future purpose
        :param rd_id: Result Descriptor Identifier for direct load (optional)
        :type rd_id: string
        :return: True for sucessful Load, False for Failed Load
                Exception will be thrown incase of insufficient mandatory parameter
        """
        if self.__CheckDBI(dbi_val, dbi_gbl, dbi_cat) is False:
            return False

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_1:
            if rd_id is not None:
                self.__rd_id = rd_id
                if self.__name is None or self.__coll_id is None or self.__spec_tag is None:
                    rd_rec = dbi_val.GetResultDescriptorWithId(self.__rd_id)
                    if COL_NAME_RESDESC_NAME in rd_rec:
                        self.__name = rd_rec[COL_NAME_RESDESC_NAME]
                        self.__coll_id = rd_rec[COL_NAME_RESDESC_COLLID]
                        self.__spec_tag = rd_rec[COL_NAME_RESDESC_REFTAG]
                        self.__doors_url = rd_rec[COL_NAME_RESDESC_DOORS_URL]
                        self.__exp_res = rd_rec[COL_NAME_RESDESC_EXPECTRES]
                        self.__desc = rd_rec[COL_NAME_RESDESC_DESCRIPTION]

            else:
                rd_rec = dbi_val.GetResultDescriptor(self.__coll_id, self.__name,
                                                     ev_type_name=self.TESTCASE_TYPE)
                if len(rd_rec) == 1:
                    rd_rec = rd_rec[0]
                    self.__rd_id = rd_rec[COL_NAME_RESDESC_ID]
                    self.__spec_tag = rd_rec[COL_NAME_RESDESC_REFTAG]
                    self.__doors_url = rd_rec[COL_NAME_RESDESC_DOORS_URL]
                    self.__exp_res = rd_rec[COL_NAME_RESDESC_EXPECTRES]
                    self.__desc = rd_rec[COL_NAME_RESDESC_DESCRIPTION]

            if self.__mesdist_ressname is None:
                self.__mesdist_ressname = self.__name

            if self.__mestime_ressname is None:
                self.__mestime_ressname = self.__name

            if self.__coll_name is None:
                self.__coll_name = dbi_cat.GetCollectionName(self.__coll_id)

            if self.__rd_id is None:
                logging.error("Testcase unknown, check the settings")
                return False

            rd_list = dbi_val.GetResulsDescriptorChildList(self.__rd_id)
            self.__testresults = []
            for rdid in rd_list:
                rd_rec = dbi_val.GetResultDescriptorWithId(rdid)
                try:
                    if self.__IsSubType(dbi_val, rdid) is False and\
                    rd_rec[COL_NAME_RESULTTYPE_CLASS] is not "ValTestStep":
                        res = ValResult()
                        if res.Load(dbi_val, dbi_gbl, testrun_id, self.__coll_id, rd_id=rdid,
                                    obs_name=obs_name, level=level, cons_key=cons_key) is True:
                            self.__testresults.append(res)
                except StandardError:
                    pass

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_3:
            if rd_id is not None:
                self.__rd_id = rd_id
            else:
                self.__rd_id = dbi_val.GetResultDescriptorId(self.__coll_id, self.__name,
                                                             ev_type_name=self.TESTCASE_TYPE)
            rd_list = dbi_val.GetResulsDescriptorChildList(self.__rd_id)

            # clean up the existing list of testcase results
            self.__teststep_ids = []
            self.__testresults = []

            for rdid in rd_list:
                try:
                    rd = dbi_val.GetResultDescriptorWithId(rdid)
                    rd_type_name = rd["TYPE_" + COL_NAME_RESULTTYPE_NAME]
                    if self.SUB_MEASRES in rd_type_name:  # Don't add result for meas file sub Struct
                        self.__rd_meas_sub_id = rdid  # Sub Struct. for File Result Descriptors
                    elif  self.SUB_EVENTS in rd_type_name:
                        self.__rd_ev_sub_id = rdid  # Sub Struct. for Event Result Descriptors
                    elif rd[COL_NAME_RESULTTYPE_CLASS] == "ValTestStep":
                        self.__teststep_ids.append(rdid)
                    else:
                        res = ValResult()
                        res.Load(dbi_val, dbi_gbl, testrun_id, self.__coll_id, rd_id=rdid,
                                 obs_name=obs_name, level=level, cons_key=cons_key)
                        self.__testresults.append(res)
                except StandardError:
                    pass

            self.__total_dist = dbi_val.GetTestRunSumValue(testrun_id, self.__mesdist_ressname,
                                                           self.MEAS_DIST_PROCESS, [self.__coll_id],
                                                           meas_id=None)
            self.__total_time = dbi_val.GetTestRunSumValue(testrun_id, self.__mestime_ressname,
                                                           self.MEAS_TIME_PROCESS, [self.__coll_id],
                                                           meas_id=None)
            self.LoadTestSteps(dbi_val, dbi_gbl, dbi_cat, testrun_id, coll_id=self.__coll_id,
                               obs_name=obs_name, level=level)
        return True

    def LoadFileResults(self,
                        dbi_val, dbi_gbl, dbi_cat,
                        testrun_id,
                        obs_name=None,
                        level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
                        cons_key=None):
        """ Load the file results under the testcase from database

        :param dbi_val: Validation Database interface
        :type dbi_val: database interface object which is instance of OracleValResDB or  SQLite3ValResDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_gbl: Global Database interface
        :type dbi_gbl:  database interface object which is instance of  OracleGblDB or SQLite3GblDB
                        target Databsae oracle or sqlite respectively
        :param dbi_cat: Catalog Database interface
        :type dbi_cat: database interface object which is instance of OracleRecCatalogDB or  OracleRecCatalogDB
                        to target Databsae oracle or sqlite respectively
        :param testrun_id: Testrun Identifier
        :type testrun_id: int
        :param obs_name: Observer Name  e.g. "ACC_DROPIN_OBSERVER"
        :type obs_name: string
        :param level: Database load/store level e.g.ValSaveLoadLevel.VAL_DB_LEVEL_INFO default is VAL_DB_LEVEL_BASIC
                      VAL_DB_LEVEL_BASIC --> Load only basic information
                                          e.g. specfication tag(if exist) doors url(if exist),result name,
                                          result value, expected result(if exist)
                      VAL_DB_LEVEL_INFO --> include load of VAL_DB_LEVEL_BASIC and additionally load
                                            its assessments
                      VAL_DB_LEVEL_ALL --> include load of VAL_DB_LEVEL_INFO and additionally load
                                          Plots images and array of result values i.e. complete
                                          detail measurement results
        :type  level: int
        :param cons_key: contraint key for future purpose
        """
        if self.__CheckDBI(dbi_val, dbi_gbl, dbi_cat) is False:
            return False

        # load measurement ids and name of the collection
        rec_files = dbi_cat.GetCollectionMeasurements(self.__coll_id, False, True, True)

        # clean up the existing list of files results
        self.__measresults = []

        if self.__rd_meas_sub_id is not None:
            rd_list = dbi_val.GetResulsDescriptorChildList(self.__rd_meas_sub_id)
            for rdid in rd_list:
                for mid in rec_files.itervalues():
                    try:
                        res = ValResult()
                        if res.Load(dbi_val, dbi_gbl, testrun_id, self.__coll_id, meas_id=mid, rd_id=rdid,
                                    obs_name=obs_name, level=level,
                                    cons_key=cons_key):
                            self.__measresults.append(res)
                    except StandardError:
                        pass
        return True

    def LoadEvents(self, dbi_val, dbi_gbl, dbi_cat, testrun_id,
                   obs_name=None, level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC, cons_key=None,
                   event_search_path=None, event_filter=None, beginabsts=None, endabsts=None,
                   asmt_state=None, filter_cond=None):
        # pylint: disable= R0913
        """
        Load Events Under the test case

        :param dbi_val: Validation Database interface
        :type dbi_val: database interface object which is instance of OracleValResDB or  SQLite3ValResDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_gbl: Global Database interface
        :type dbi_gbl:  database interface object which is instance of  OracleGblDB or SQLite3GblDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_cat: Catalog Database interface
        :type dbi_cat: database interface object which is instance of OracleRecCatalogDB or  OracleRecCatalogDB
                        to target Databsae oracle or sqlite respectively
        :param testrun_id: Testrun Identifier
        :type testrun_id: int
        :param obs_name: Observer Name  e.g. "ACC_DROPIN_OBSERVER"
        :type obs_name: string
        :param level: Database load/store level e.g.ValSaveLoadLevel.VAL_DB_LEVEL_INFO default is VAL_DB_LEVEL_BASIC
                      VAL_DB_LEVEL_BASIC --> Load only basic information of Events
                      VAL_DB_LEVEL_INFO --> include load of VAL_DB_LEVEL_BASIC and additionally load
                                            its assessments
                      VAL_DB_LEVEL_ALL --> include load of VAL_DB_LEVEL_INFO and additionally load
                                          all the Event Attributes values
        :param cons_key: For Future Purpose
        :param event_search_path: Mandatory parameter for Directory path where python Module
                                  containing Event Classes defination
        :type event_search_path: string
        :param event_filter: Instance of ValEventFilter class used to apply complex
                            filter criteria on Event Attribute values, Assessment state,
                            BeginAbsts, Endabsts time stamps
                            Read Documentation of ValEventFilter Class for futher details
                            Default value None which makes depending on basic filter criteria parameters given below
        :type event_filter: ValEventFilter
        :param beginabsts: basic filter criteria to load event(s) with given Begin Timestamp
        :type beginabsts: int
        :param endabsts: basic filter criteria of End Timestamp of to load event(s)
                         which has End Timestamp to specific value
        :type endabsts: int
        :param asmt_state: Basic Filter criteria to Load Event having Specific
                            Assessment state e.g. "Invalid", "Not Assessed"
        :type asmt_state: string
        :param filter_cond: Filter map name is written in Filter config XML file e.g. "Dropout_rate_filter"
                            parameter event_filter must be set as prerequiste which manages the Complex Filter
        :type filter_cond: String

        Note: If the event_filter, beginabsts, endabsts, asmt_state and filter_cond are None
                then No Filter criteria will be applied and All the Events Under testcase will be loaded
        """

        if self.__CheckDBI(dbi_val, dbi_gbl, dbi_cat) is False:
            return False

        if event_search_path is not None:
#             Class managing events
            self.__events = ValEventList(event_search_path, event_filter)

        return self.__events.Load(dbi_val, dbi_gbl, testrun_id, self.__coll_id, None, self.__rd_ev_sub_id,
                                  obs_name, level, beginabsts, endabsts, asmt_state, filter_cond, cons_key)

    def LoadTestSteps(self, dbi_val, dbi_gbl, dbi_cat, testrun_id, coll_id=None, obs_name=None,
                      level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC):
        """
        Load TestSteps under the current test case

        :param dbi_val: Validation Database interface
        :type dbi_val: database interface object which is instance of OracleValResDB or  SQLite3ValResDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_gbl: Global Database interface
        :type dbi_gbl:  database interface object which is instance of  OracleGblDB or SQLite3GblDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_cat: Catalog Database interface
        :type dbi_cat: database interface object which is instance of OracleRecCatalogDB or  OracleRecCatalogDB
                        to target Databsae oracle or sqlite respectively
        :param testrun_id: Testrun Identifier
        :type testrun_id: int
        :param obs_name: Observer Name  e.g. "ACC_DROPIN_OBSERVER"
        :type obs_name: string
        :param level: Database load/store level e.g.ValSaveLoadLevel.VAL_DB_LEVEL_INFO default is VAL_DB_LEVEL_BASIC
                      VAL_DB_LEVEL_BASIC --> Load only basic information
                                          e.g. specfication tag(if exist) doors url(if exist),Test step name,
                                          TestStep value, expected result(if exist)
                      VAL_DB_LEVEL_INFO --> include load of VAL_DB_LEVEL_BASIC and additionally load
                                            its assessments

                      VAL_DB_LEVEL_ALL --> include load of VAL_DB_LEVEL_INFO and additionally load
                                          Plots images and array of the Test Step i.e. complete detail of Test Step
        """

        if self.__CheckDBI(dbi_val, dbi_gbl, dbi_cat) is False:
            return False
        self.__teststeps = []
        for tstep_id in self.__teststep_ids:
            ts = ValTestStep()
            ts.Load(dbi_val, dbi_gbl, testrun_id, coll_id=coll_id, rd_id=tstep_id,
                    obs_name=obs_name, level=level)
            self.__teststeps.append(ts)

    def Save(self,
             dbi_val,
             dbi_gbl,
             testrun_id,
             obs_name=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
             cons_key=None):
        # pylint: disable= R0912
        """ Save the TestCase to the database using the given load/store level

        :param dbi_val: Validation Database interface
        :type dbi_val: database interface object which is instance of OracleValResDB or  SQLite3ValResDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_gbl: Global Database interface
        :type dbi_gbl:  database interface object which is instance of  OracleGblDB or SQLite3GblDB
                        to target Databsae oracle or sqlite respectively
        :param dbi_cat: Catalog Database interface
        :type dbi_cat: database interface object which is instance of OracleRecCatalogDB or  OracleRecCatalogDB
                        to target Databsae oracle or sqlite respectively
        :param testrun_id: Testrun Identifier
        :type testrun_id: int
        :param obs_name: Observer Name  e.g. "ACC_DROPIN_OBSERVER"
        :type obs_name: string
        :param level: Database load/store level e.g.ValSaveLoadLevel.VAL_DB_LEVEL_INFO default is VAL_DB_LEVEL_BASIC
                      VAL_DB_LEVEL_BASIC --> Save only basic information
                                          e.g. specfication tag(if exist) doors url(if exist),Test steps,
                                          expected result(if exist), TestCase results
                      VAL_DB_LEVEL_INFO --> include save of VAL_DB_LEVEL_BASIC and additionally load
                                            its assessments Test Steps and Test Case results
                      VAL_DB_LEVEL_ALL --> include Save operation of VAL_DB_LEVEL_INFO and additionally save
                                          Plots images and array of the Test Case results, TesSteps
                                          and Also save File results and their plot,images
                                          i.e. complete detail Result data which includes under Test
                                          Case including the Assessment
        :param cons_key: For Future Purpose

        """
        if self.__CheckDBI(dbi_val, dbi_gbl, None) is False:
            return False

        # load the result descriptor. If not exist, generate a new one
        self.__rd_id = dbi_val.GetResultDescriptorId(self.__coll_id, self.__name, ev_type_name=self.TESTCASE_TYPE)
        if self.__rd_id is None:
            unit_id = dbi_gbl.GetUnitIdByName(self.TESTCASE_UNIT)
            if self.GetSpecTag() == "":
                raise StandardError("Door ID is mandatory e.g. EM_TC_001_001")
            else:
                if self.__CheckTestCaseSpecTag(self.__spec_tag) is False:
                    raise StandardError("Door ID is Not matching Standard format e.g. EM_TC_001_001")

            self.__rd_id = dbi_val.AddResultDescriptor(self.TESTCASE_TYPE, self.__name,
                                                       self.__coll_id, unit_id,
                                                       self.__spec_tag, None,
                                                       self.__doors_url, self.__exp_res,
                                                       self.__desc)

        # Sub Results for the Measurements
        res_type_id = dbi_val.GetResultTypeId(self.SUB_MEASRES)
        if res_type_id is None:
            result_type = {COL_NAME_RESULTTYPE_NAME: self.SUB_MEASRES,
                           COL_NAME_RESULTTYPE_DESC: 'Measurement Specific Substruct',
                           COL_NAME_RESULTTYPE_CLASS: 'None'}
            dbi_val.AddResultType(result_type)
            res_type_id = dbi_val.GetResultTypeId(self.SUB_MEASRES)

        rd_id_meas_sub = dbi_val.GetResultDescriptorId(self.__coll_id, self.__name, ev_type_id=res_type_id)
        if rd_id_meas_sub is None:
            unit_id = dbi_gbl.GetUnitIdByName(self.TESTCASE_UNIT)
            rd_id_meas_sub = dbi_val.AddResultDescriptor(self.SUB_MEASRES, self.__name,
                                                         self.__coll_id, unit_id,
                                                         None, self.__rd_id)
        # Sub Events for the Measurements
        if len(self.__events.GetEvents()) > 0:
            ev_type_id = dbi_val.GetResultTypeId(self.SUB_EVENTS)
            if ev_type_id is None:
                result_type = {COL_NAME_RESULTTYPE_NAME: self.SUB_EVENTS,
                               COL_NAME_RESULTTYPE_DESC: 'Measurement Specific Events',
                               COL_NAME_RESULTTYPE_CLASS: 'None'}
                dbi_val.AddResultType(result_type)
                ev_type_id = dbi_val.GetResultTypeId(self.SUB_EVENTS)

            rd_id_ev_sub = dbi_val.GetResultDescriptorId(self.__coll_id, self.__name, ev_type_id=ev_type_id)
            if rd_id_ev_sub is None:
                unit_id = dbi_gbl.GetUnitIdByName(self.TESTCASE_UNIT)
                rd_id_ev_sub = dbi_val.AddResultDescriptor(self.SUB_EVENTS,
                                                           self.__name,
                                                           self.__coll_id,
                                                           unit_id,
                                                           None, self.__rd_id)
        if level & ValSaveLoadLevel.VAL_DB_LEVEL_2:
            # Save a default result to get the link to the testrun
            res = ValResult(self.__name, self.TESTCASE_TYPE, None, self.TESTCASE_UNIT, self.__spec_tag, 0)
            res.Save(dbi_val, dbi_gbl, testrun_id, self.__coll_id, None, obs_name, None, level, cons_key)

            for tc_res in self.__testresults:
                tc_res.Save(dbi_val, dbi_gbl,
                            testrun_id, self.__coll_id, None,
                            obs_name, self.__rd_id, level, cons_key)
            for test_step in self.__teststeps:
                test_step.Save(dbi_val, dbi_gbl, testrun_id, self.__coll_id, obs_name=obs_name,
                               parent_id=self.__rd_id, level=level, cons_key=cons_key)

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_3:
            # save the measurements specific sub results
            for meas_res in self.__measresults:
                meas_res.Save(dbi_val, dbi_gbl,
                              testrun_id, self.__coll_id, None,
                              obs_name, rd_id_meas_sub, level, cons_key)
            # save the events
            if len(self.__events.GetEvents()) > 0:
                self.__events.Save(dbi_val, dbi_gbl, testrun_id, self.__coll_id,
                                   obs_name, rd_id_ev_sub, level, cons_key)

    def AddResult(self, result):
        """ Add a new result to the Testcase
        """

        if issubclass(result.__class__, ValResult):
            self.__testresults.append(result)
        else:
            raise StandardError("Instance of ValResult was expected in arguement")

    def AddMeasResult(self, result):
        """ add a new result for a measurement
        The result is normally available on development level and takes measurement specific results

        :param result: Result of type ValResult containing value which
                       could be ValidationPlot, Histogram, image, ValueVector, BaseValue
        :type result:    ValResult
        Note: Read the Documentation of ValResult Class
        """
        if issubclass(result.__class__, ValResult):
            self.__measresults.append(result)

    def GetResults(self, measid=None):
        """ Get the results of the Testcase

        :param measid: Measurement ID if measid provide then only list of results(MeasResult) specific to measid return
                       otherwise List of TestCaseResult will be return
        :type measid: int
        """
        res_list = []
        if measid is not None:
            for tc_res in self.__measresults:
                if tc_res.GetMeasId() == measid:
                    res_list.append(tc_res)
            return res_list
        else:
            return self.__testresults

    def AddEvent(self, event):
        """ Add a new event result to the Testcase """
        return self.__events.AddEvent(event)

    def GetEvents(self, measid=None):
        """ Get the events of the Testcase
        :param measid: Measurement ID
        """
        event_list = []

        if measid is None or measid == -1:
            return self.__events.GetEvents()
        else:
            for tc_event in self.__events.GetEvents():
                event_meas_id = tc_event.GetMeasId()
                if int(event_meas_id) == int(measid):
                    event_list.append(tc_event)

        return event_list

    def AddTestStep(self, test_step):
        """
        Add TestSTep to Test case
        :param test_step: object of teststep class
        :type test_step: ValTestStep
        """
        if isinstance(test_step, ValTestStep):
            self.__teststeps.append(test_step)
        else:
            raise StandardError("Instance of ValTestStep was expected in arguement")

    def AddMeasDistTimeProcess(self, measid, ego_motion=None, distance=None, time=None):
        """
        Add DistanceTimeProcess for measurement under each test case. The total Time and
        Distance processed under each test will be Available as additional TestcaseResult
        on Loading the testcase

        :param ego_motion: instance of EgoMotion Class. if the arguement is passed then
                            it has Precedence over distance, time arguement will be ignore
        :type ego_motion: EgoMotion
        :param time: Time Process(Seconds) will be used if ego_motion is not provided
        :type time: int
        :param distance: Distance Process(Kilometer) will be used if ego_motion is not provided
        :type distance: int
        """
        if ego_motion is not None:
            if isinstance(ego_motion, EgoMotion):
                # Get Total Time in Seconds
                _, _, _, _, time = ego_motion.GetCycleTimeStatistic()
                # Get Total Distance  and converted into KiloMeter
                distance = ego_motion.GetDrivenDistance() / 1000
#                distance = ego_motion.GetCycleTimeStatistic() / 1000
            else:
                raise StandardError("Instance of EgoMotion was expected in arguement")

        if self.__mesdist_ressname is None:
            self.__mesdist_ressname = self.__name

        if self.__mestime_ressname is None:
            self.__mestime_ressname = self.__name

        if distance is not None:
            dist_res = ValResult(name=self.__mesdist_ressname, res_type=self.MEAS_DIST_PROCESS, meas_id=measid,
                                 unit=GblUnits.UNIT_L_M, tag="", parent=None)
            dist_res.SetValue(BaseValue("", BaseUnit(GblUnits.UNIT_L_M, label="km"), distance))
#           dist_res.SetValue(distance)
            self.AddMeasResult(dist_res)
            self.__total_dist += distance

        if time is not None:
            time_res = ValResult(name=self.__mestime_ressname, res_type=self.MEAS_TIME_PROCESS, meas_id=measid,
                                 unit=GblUnits.UNIT_L_S, tag="", parent=None)
            time_res.SetValue(BaseValue("", BaseUnit(GblUnits.UNIT_L_S, label="s"), time))
#            time_res.SetValue(time)
            self.AddMeasResult(time_res)
            self.__total_time += time

    def  GetMeasDistanceProcess(self, measid):
        """
        Get Distance Prcoess for specfic to measurement in Kilometer return Int

        :param measid: measurement Id
        :type measid: int
        :return value: if exist Distance Value return distance in KM otherwise None
        """
        for meas_res in self.__measresults:
            if meas_res.GetType() == self.MEAS_DIST_PROCESS and meas_res.GetName() == self.__name and\
            meas_res.GetMeasId() == measid:
                if type(meas_res.GetValue()) == BaseValue:
                    return meas_res.GetValue().GetValue()
        return None

    def  GetMeasTimeProcess(self, measid):
        """
        Get Time Prcoess for specfic to measurement in Seconds  as Int and  String
        representing duration format HH:MM:SS which
        useful for support reporting

        :param measid: measurement Id
        :type measid: int
        :return: if exist Time process(second) Value and duration format
                 HH:MM:SS e.g. 124, "00:2:04" otherwise return None,None
        """
        for meas_res in self.__measresults:
            if meas_res.GetType() == self.MEAS_TIME_PROCESS and meas_res.GetName() == self.__name and\
             meas_res.GetMeasId() == measid:
                if type(meas_res.GetValue()) == BaseValue:
                    return meas_res.GetValue().GetValue(), \
                    Sec2HmsString(meas_res.GetValue().GetValue())
        return None, None

    def GetMeasResult(self, measid=None, name=None):
        """
        Get Measurement Result list with following filter Criteria on result name and measurementId:
        if both arguement (measid, name) are passed --> return result with specific name and measurement Id
        if only measid is passed --> return All results specific to measurement Id
        if only name is passed   --> return Result with specific name for All measurement Id
        if no argument is passed --> Return all the measurement Results under the current test case i.e. No filter
        Don't use GetMeasResult() to Get Distance and Time process for measid under testcase
        Use GetMeasTimeProcess() GetMeasDistanceProcess()
        :param measid: measurement Id
        :type measid: int
        :param name: Result Name e.g. "EOL_STD_ERROR", "ACC_OBJ_TESTCASE_LANE_ID"
        :param type: String
        :return: list of ValResult
        """

        meas_results = []
        for meas_res in self.__measresults:
            type = meas_res.GetType()
            not_dist_time = (type not in self.MEAS_DIST_PROCESS + self.MEAS_TIME_PROCESS)
            if measid is not None and name is not None:
                if meas_res.GetMeasId() == measid and meas_res.GetName() == name and not_dist_time:
                    meas_results.append(meas_res)
            elif measid is not None and name is None:
                if meas_res.GetMeasId() == measid and not_dist_time:
                    meas_results.append(meas_res)
            elif measid is None and name is not None:
                if meas_res.GetName() == name and not_dist_time:
                    meas_results.append(meas_res)
            else:
                if not_dist_time:
                    meas_results.append(meas_res)
        return meas_results

    def GetDistanceProcess(self):
        """
        Get The total Driven Distance for the test case

        :return: Total Distance in Kilometer
        :type return: Int
        """
        return self.__total_dist

    def GetTimeProcess(self):
        """
        Get The total Time processed for the test case

        :return: Total Time in Second as Integer and Duration in as String with format HH:MM:SS
         :type return: Int, String
        """
        return self.__total_time, Sec2HmsString(self.__total_time)

    def __CheckDBI(self, dbi_val, dbi_gbl, dbi_cat):
        """ Check the Database interface

        :param dbi_val: Validation Database interface
        :param dbi_gbl: Global Database interface
        :param dbi_cat: Catalog Database interface
        """
        # pylint: disable= R0201
        if dbi_val is not None and not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            logging.error("VAL Database interface undefined")
            return False

        if dbi_gbl is not None and not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False

        if dbi_cat is not None and not issubclass(dbi_cat.__class__, db_cat.BaseRecCatalogDB):
            logging.error("CAT Database interface undefined")
            return False

        return True

    def __CheckTestCaseSpecTag(self, tag):
        """
        Check if the specification tag is matching DOORS format

        :param tag: Doors ID
        :type tag: String
        """
        # pylint: disable= R0201
        #                  1        2   3  4   5   6   7  8   9   10  11
        pattern = "((^[a-z]{2,3}_[a-z]{2,3}|^[a-z]{2,3}))_TC_(\d{3})(_)(\d{3})$"
        rg = re.compile(pattern, re.IGNORECASE | re.DOTALL)
        match = rg.search(tag)
        if match:
            return True
        else:
            return False

    @property
    def test_steps(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: List of Teststeps
        :rtype:  list[`TestStep`,...]
        """
        return self.__teststeps

    @property
    def name(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: Name of the TestCase
        :rtype:  string
        """
        return self.GetName()

    @property
    def description(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: Description of the TestCase
        :rtype:  string
        """
        return self.GetDescription()

    @property
    def id(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: Id of the TestCase
        :rtype:  string
        """
        return self.GetSpecTag()

    @property
    def collection(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: CollectionName of the Testcase
        :rtype:  string
        """
        return self.GetCollectionName()


class ValResult():  # pylint: disable= R0902
    """ Base class for testresults
    """
    def __init__(self, name=None, res_type=None, meas_id=None, unit=None, tag="",
                 parent=None, doors_url="", exp_res="", desc=""):
        # pylint: disable= R0913
        """ Inialize Result Class

        :param name: Result Name (Unique Identifier, Signal, Image, ...)
        :param res_type: Result Type (Distance, KPI, Image Plot, ...)
        :param meas_id: Measurement Identifier
        :param unit: Unit Name (Meter, ...)
        :param tag: Reference Tag (link to doors testspecification)
        :param parent: Parent Result (support to link results to a testcase)
        """
        self.__name = name
        self.__type = res_type
        self.__unit = unit
        self.__value = None
        self.__ref_tag = tag
        self.__parent = parent
        self.__assessment = None
        self.__rd_id = None
        self.__meas_id = meas_id
        self.__coll_id = None
        self.__unit_rec = None
        self.__class_name = None
        self.__id = None
        self.__coll_name = None
        self.__doors_url = doors_url
        self.__exp_res = exp_res
        self.__desc = desc

    def __str__(self):
        """ Basic Result Info as string """
        txt = "Result: "
        txt += self.__name
        if self.__assessment is not None:
            txt += " ASMT: " + str(self.__assessment)
        return txt + "\n"

    def GetName(self):
        """ Get the Name of the testcase """
        return self.__name

    def GetSpecTag(self):
        """
        Get Sepcification Identifier
        """
        return self.__ref_tag

    def GetDescription(self):
        """
        Get Description text of the result
        """
        return self.__desc

    def GetExpectedResult(self):
        """
        Get Expected Result
        """
        return self.__exp_res

    def GetDoorsURL(self):
        """
        Get Doors URLS
        """
        return self.__doors_url

    def GetCollectionName(self):
        """
        Get Collection
        """
        return self.__coll_name

    def Load(self,
             dbi_val,
             dbi_gbl,
             testrun_id,
             coll_id=None,
             meas_id=None,
             rd_id=None,
             obs_name=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
             cons_key=None):
        # pylint: disable= R0912, R0913, R0914, R0915, W0613
        """ Load the result

        :param dbi_val: Validation Database interface
        :param dbi_gbl: Global Database interface
        :param testrun_id: Testrun Identifier
        :param coll_id: collection Identifier
        :param meas_id: Measurement Identifier
        :param rd_id: Result Descriptor Identifier
        :param obs_name: Observer Name
        :param level: Database load/store level
        :param cons_key: contraint key
        """
        ret = False

        if not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            logging.error("VAL Database interface undefined")
            return False

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return False

        if rd_id is None:
            self.__rd_id = dbi_val.GetResultDescriptorId(coll_id, self.__name, ev_type_name=self.__type)
        else:
            self.__rd_id = rd_id

        if self.__meas_id is not None:
            meas_id = self.__meas_id

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_1:
            # load the result description and unit information
            rd_rec = dbi_val.GetResultDescriptorWithId(self.__rd_id)
            if COL_NAME_RESDESC_NAME in rd_rec:
                self.__name = rd_rec[COL_NAME_RESDESC_NAME]
                self.__type = rd_rec["TYPE_" + COL_NAME_RESULTTYPE_NAME]
                self.__coll_id = rd_rec[COL_NAME_RESDESC_COLLID]
                self.__parent = rd_rec[COL_NAME_RESDESC_PARENT]
                self.__ref_tag = rd_rec[COL_NAME_RESDESC_REFTAG]
                self.__class_name = rd_rec[COL_NAME_RESULTTYPE_CLASS]
                self.__doors_url = rd_rec[COL_NAME_RESDESC_DOORS_URL]
                self.__exp_res = rd_rec[COL_NAME_RESDESC_EXPECTRES]
                self.__desc = rd_rec[COL_NAME_RESDESC_DESCRIPTION]
                unit_id = rd_rec[COL_NAME_RESDESC_UNIT_ID]
                self.__unit_rec = dbi_gbl.GetUnit(uid=unit_id)
                self.__unit = self.__unit_rec[COL_NAME_UNIT_NAME]
                if level < ValSaveLoadLevel.VAL_DB_LEVEL_2:
                    ret = True

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_2:
            res_rec = dbi_val.GetResult(testrun_id, self.__rd_id, meas_id)
            if COL_NAME_RES_VALUE in res_rec:
                self.__value = res_rec[COL_NAME_RES_VALUE]
                self.__meas_id = res_rec[COL_NAME_RES_MEASID]
                self.__id = res_rec[COL_NAME_RES_ID]
                ass_id = res_rec[COL_NAME_RES_RESASSID]
                if level < ValSaveLoadLevel.VAL_DB_LEVEL_3:
                    ret = True

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_3:
            # load the assessment
            try:
                if ass_id is not None:
                    ass = ValAssessment()
                    ass.Load(ass_id, dbi_val, dbi_gbl, obs_name)
                    self.__assessment = ass

                if level < ValSaveLoadLevel.VAL_DB_LEVEL_4:
                    ret = True

            except StandardError:
                pass
        if level & ValSaveLoadLevel.VAL_DB_LEVEL_4:
            if self.__value is not None:
                if str(self.__class_name) == "None":
                    ret = True
                elif self.__class_name == 'BaseValue':
                    self.__value = BaseValue("", BaseUnit(self.__unit, "", None), self.__value)
                    ret = True
                elif self.__class_name == 'ValueVector':
                    if self.__id is not None:
                        values = dbi_val.GetListOfResults(self.__id)
                        min_rg = values[0]
                        max_rg = values[1]
                        val_vec = values[2:]
                        unit = BaseUnit(self.__unit)
                        self.__value = ValueVector(self.__name, unit, val_vec, min_rg, max_rg)
                        ret = True
                elif self.__class_name == 'Histogram':
                    if self.__id is not None:
                        values = dbi_val.GetListOfResults(self.__id)

                        i = 0
                        j = 0
                        hist_x = [0] * int(len(values) / 2)
                        hist_y = [0] * int(len(values) / 2)
                        while i < len(values):
                            hist_x[j] = values[i]
                            hist_y[j] = values[i + 1]
                            j += 1
                            i += 2
                        unit = BaseUnit(self.__unit)
                        self.__value = Histogram(self.__name, unit)
                        self.__value.SetValue(zip(hist_x, hist_y))
                        ret = True
                elif self.__class_name == 'ValidationPlot':
                    if self.__id is not None:
                        values = dbi_val.GetListOfResults(self.__id)
                        width = values[0]
                        heigth = values[1]
                        img_rec = dbi_val.GetResultImage(self.__id)
                        if COL_NAME_RESIMG_IMAGE in img_rec:
                            title = img_rec[COL_NAME_RESIMG_TITLE]
                            img_data = img_rec[COL_NAME_RESIMG_IMAGE]
                            val_plt = ValidationPlot(title=title, width=width, height=heigth)
                            val_plt.SetImageDataBuffer(img_data)
                            self.__value = val_plt
                            ret = True
        return ret

    def Save(self,
             dbi_val,
             dbi_gbl,
             testrun_id,
             coll_id,
             meas_id=None,
             obs_name=None,
             parent_id=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
             cons_key=None):
        # pylint: disable= R0912, R0913, R0914, R0915, W0613
        """ Save the result

        :param dbi_val: VAL DB interface
        :param dbi_gbl: GBL DB interface
        :param testrun_id: Testrun identifier
        :param coll_id: CAT Collection ID
        :param meas_id: Measurement Identifier
        :param obs_name: Observer Name (registered in GBL)
        :param level: Save level,
                - VAL_DB_LEVEL_STRUCT: Result Descriptor only,
                - VAL_DB_LEVEL_BASIC: Result Descriptor and result,
                - VAL_DB_LEVEL_INFO: Result Descriptor, Result and Assessment
                - VAL_DB_LEVEL_ALL: Result with images and all messages
        :param cons_key: contraint key -- for future use
        """
        res = False
        msg = None
        if not issubclass(dbi_val.__class__, db_val.BaseValResDB):
            logging.error("VAL Database interface undefined")
            return res

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            logging.error("GBL Database interface undefined")
            return res

        if self.__unit is None:
            logging.error("Unit is not defined for the result")

        unit_id = dbi_gbl.GetUnitIdByName(self.__unit)
        if unit_id is None:
            logging.error("Unit is not defined in the GBL Database")
            return res

        if self.__meas_id is not None:
            meas_id = self.__meas_id

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_1:
            if dbi_val.GetResultTypeId(self.__type) is None:
                if self.__class_name is not None:
                    cls_name = self.__class_name
                else:
                    cls_name = "None"
                res_type = {COL_NAME_RESULTTYPE_NAME: self.__type, COL_NAME_RESULTTYPE_DESC: "",
                            COL_NAME_RESULTTYPE_CLASS: cls_name}
                dbi_val.AddResultType(res_type)

            self.__rd_id = dbi_val.GetResultDescriptorId(coll_id, self.__name, ev_type_name=self.__type)

            if self.__rd_id is None:
                # use the parent id of the testcase
                if self.__parent is None:
                    self.__parent = parent_id
                # generate a new descriptor
                self.__rd_id = dbi_val.AddResultDescriptor(self.__type, self.__name, coll_id, unit_id,
                                                           self.__ref_tag, self.__parent,
                                                           self.__doors_url, self.__exp_res,
                                                           self.__desc)

                if level < ValSaveLoadLevel.VAL_DB_LEVEL_2:
                    res = True

        if level & ValSaveLoadLevel.VAL_DB_LEVEL_2:
            ass_id = None
            # if an assessement exists, save it
            if level & ValSaveLoadLevel.VAL_DB_LEVEL_3:
                if self.__assessment is not None:
                    self.__assessment.Save(dbi_val, dbi_gbl, obs_name)
                    ass_id = self.__assessment.GetId()

            # check if the result is already in the DB
            res_rec = dbi_val.GetResult(testrun_id, self.__rd_id, meas_id)
            if COL_NAME_RES_ID not in res_rec:
                res_rec = {COL_NAME_RES_TESTRUN_ID: testrun_id,
                           COL_NAME_RES_RESDESC_ID: self.__rd_id,
                           COL_NAME_RES_MEASID: meas_id}
                if ass_id is not None:
                    res_rec[COL_NAME_RES_RESASSID] = ass_id
                res = self.__SaveResultValues(dbi_val, res_rec)
            else:
                # update the result only with new assessment results
                if ass_id is not None:
                    res_rec[COL_NAME_RES_RESASSID] = ass_id
                    dbi_val.UpdateResult(res_rec)
                    res = True
                else:
                    msg = "Result %s could not be stored. Its already in the Database" % self.GetName()

        if res is True:
            dbi_val.Commit()
            dbi_gbl.Commit()
        else:
            if msg is None:
                logging.error("Result %s could not be stored", self.GetName())
            else:
                logging.error(msg)

        return res

    def __SaveResultValues(self, dbi_val, res_rec):  # pylint: disable= R0912, R0915
        """ Save the results """
        res = False

        if self.__value is None:
            res = True
            res_rec[COL_NAME_RES_VALUE] = 0.0
            dbi_val.AddResult(res_rec)
            res = True
        elif isinstance(self.__value, Signal):
            # not supported
            res = False
        elif isinstance(self.__value, ValueVector):
            if len(self.__value) > 400:
                logging.warning("Length Value Vector %s is too high, please check the design",
                                self.__value.GetName())
            val = self.__value.GetValue()
            if val is not None:
                res_rec[COL_NAME_RES_VALUE] = len(val)
                result_id = dbi_val.AddResult(res_rec)
                res_dat = {COL_NAME_RESVAL_ID: result_id}

                # First store min and max of range
                res_dat[COL_NAME_RESVAL_SUBID] = 0
                res_dat[COL_NAME_RESVAL_VALUE] = self.__value.GetRangeMin()
                dbi_val.AddResultValue(res_dat)
                res_dat[COL_NAME_RESVAL_SUBID] = 1
                res_dat[COL_NAME_RESVAL_VALUE] = self.__value.GetRangeMax()
                dbi_val.AddResultValue(res_dat)

                # store all values
                for i in range(len(val)):
                    res_dat[COL_NAME_RESVAL_SUBID] = i + 2
                    res_dat[COL_NAME_RESVAL_VALUE] = val[i]
                    dbi_val.AddResultValue(res_dat)

            res = True
        elif isinstance(self.__value, ValidationPlot):
            val_plot = self.__value
            img_data = val_plot.GetPlotDataBuffer()  # pylint: disable=E1103
            res_rec[COL_NAME_RES_VALUE] = 0
            result_id = dbi_val.AddResult(res_rec)
            res_dat = {COL_NAME_RESVAL_ID: result_id}

            # store additional data containing the figure sizes
            if val_plot.GetWidth() is not None:  # pylint: disable=E1103
                res_dat[COL_NAME_RESVAL_SUBID] = 0
                res_dat[COL_NAME_RESVAL_VALUE] = val_plot.GetWidth()  # pylint: disable=E1103
                dbi_val.AddResultValue(res_dat)
            if val_plot.GetHeight() is not None:  # pylint: disable=E1103
                res_dat[COL_NAME_RESVAL_SUBID] = 1
                res_dat[COL_NAME_RESVAL_VALUE] = val_plot.GetHeight()  # pylint: disable=E1103
                dbi_val.AddResultValue(res_dat)

            # Add the image
            if img_data is not None:
                res_img = {}
                res_img[COL_NAME_RESIMG_ID] = result_id
                res_img[COL_NAME_RESIMG_IMAGE] = img_data
                title = val_plot.GetTitle()  # pylint: disable=E1103
                if title is None:
                    # create a new title
                    title = self.__name
                    if self.__meas_id is not None:
                        title += "_%d" % self.__meas_id
                res_img[COL_NAME_RESIMG_TITLE] = title
                res_img[COL_NAME_RESIMG_FORMAT] = 'png'
                dbi_val.AddResultImage(res_img)
            res = True
        elif isinstance(self.__value, Histogram):
            val = self.__value.GetValue()

            if val is not None:
                res_rec[COL_NAME_RES_VALUE] = len(val)
                result_id = dbi_val.AddResult(res_rec)
                res_dat = {COL_NAME_RESVAL_ID: result_id}
                i = 0
                for xy in val:
                    res_dat[COL_NAME_RESVAL_SUBID] = i
                    res_dat[COL_NAME_RESVAL_VALUE] = xy[0]
                    dbi_val.AddResultValue(res_dat)
                    res_dat[COL_NAME_RESVAL_SUBID] = i + 1
                    res_dat[COL_NAME_RESVAL_VALUE] = xy[1]
                    dbi_val.AddResultValue(res_dat)
                    i += 2
            res = True
        elif isinstance(self.__value, BaseValue):
            val = self.__value.GetValue()
            if val is not None:
                res_rec[COL_NAME_RES_VALUE] = val
                dbi_val.AddResult(res_rec)
                res = True
            else:
                logging.error("Result %s could not be stored, value not defined", self.__value.GetName())
        elif isinstance(self.__value, ValidationPlot):
            res = True

        return res

    def GetType(self):
        """ Get the Result Name
        """
        return self.__type

    def GetUnit(self):
        """ Get the Result Unit
        """
        return self.__unit

    def GetUnitLabel(self):
        """ Get the Unit Label
        """
        if self.__unit_rec is not None:
            return self.__unit_rec[COL_NAME_UNIT_LABEL]
        return ""

    def SetValue(self, value):
        """ Set Result Value Object of the result

        """
        res = False
        if type(value) is BaseValue:
            res = True
            self.__class_name = "BaseValue"
        elif type(value) is ValueVector:
            res = True
            self.__class_name = "ValueVector"
        elif type(value) is Histogram:
            res = True
            self.__class_name = "Histogram"
#        elif isinstance(value, Signal):
#            res = True
        elif type(value) is ValidationPlot:
            res = True
            self.__class_name = "ValidationPlot"
        else:
            value = BaseValue("", BaseUnit(self.__unit, "", None), value)
            res = True
            self.__class_name = "BaseValue"

        if res is True:
            self.__value = value
        else:
            logging.error("result type is not supported")

        return res

    def GetValue(self):
        """ return the value object of the result
        """
        return self.__value

    def GetMeasId(self):
        """ Get the Measid of the result """
        return self.__meas_id

    def AddAssessment(self, assessment):
        """ Add Assessment Instance to the result

        :param assessment: Assessment instance
        :return: True if passed, False on Error
        """
        if not issubclass(assessment.__class__, ValAssessment):
            logging.error("Not a Assessment Class Instance")
            return False

        self.__assessment = assessment
        return True

    def GetAssessment(self):
        """ Return the Assessment

        :return: Assessment instance
        """
        return self.__assessment

    def GetResultId(self):
        """ Get the Result ID

        :return: Return the Result ID of the Database or None
        """
        return self.__id

    def GetResultDescriptorId(self):
        """ Get the Result Descriptor ID

        :return: Return the ResultDescriptor ID of the Database or None
        """
        return self.__rd_id


class ValTestStep(ValResult):
    """
    Classs to ValTestStep
    """
    PASSED = 'Passed'
    """
    :cvar: Predefined test_result (passed)
    :type: string
    """
    FAILED = 'Failed'
    """
    :cvar: Predefined test_result (failed)
    :type: string
    """
    SUSPECT = 'TO BE VERIFIED'
    """
    :cvar: Predefined test_result (to be verified)
    :type: string
    """
    def __init__(self, name=None, res_type=ValTestcase.TEST_STEP,
                 unit=None, tag="", parent=None, doors_url="", exp_res="", desc=""):
        # pylint: disable= R0913

        ValResult.__init__(self, name=name, res_type=res_type, unit=unit, tag=tag, parent=parent,
                           doors_url=doors_url, exp_res=exp_res, desc=desc)

    def Load(self,
             dbi_val,
             dbi_gbl,
             testrun_id,
             coll_id=None,
             rd_id=None,
             obs_name=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC,
             cons_key=None):
        # pylint: disable= R0913, W0221
        """ Load the ValTestSTep

        :param dbi_val: Validation Database interface
        :param dbi_gbl: Global Database interface
        :param testrun_id: Testrun Identifier
        :param coll_id: collection Identifier
        :param meas_id: Measurement Identifier
        :param rd_id: Result Descriptor Identifier
        :param obs_name: Observer Name
        :param level: Database load / store level
        :param cons_key: contraint key
        """

        ValResult.Load(self, dbi_val, dbi_gbl, testrun_id,
                       coll_id=coll_id, rd_id=rd_id, obs_name=obs_name,
                       level=level,
                       cons_key=cons_key)

    def Save(self, dbi_val, dbi_gbl, testrun_id, coll_id, obs_name=None, parent_id=None,
             level=ValSaveLoadLevel.VAL_DB_LEVEL_BASIC, cons_key=None):
        # pylint: disable= R0913, W0221
        """ Save the TestStep

        :param dbi_val: VAL DB interface
        :param dbi_gbl: GBL DB interface
        :param testrun_id: Testrun identifier
        :param coll_id: CAT Collection ID
        :param meas_id: Measurement Identifier
        :param obs_name: Observer Name (registered in GBL)
        :param level: Save level,
                - VAL_DB_LEVEL_STRUCT: Result Descriptor only,
                - VAL_DB_LEVEL_BASIC: Result Descriptor and result,
                - VAL_DB_LEVEL_INFO: Result Descriptor, Result and Assessment
                - VAL_DB_LEVEL_ALL: Result with images and all messages
        :param cons_key: contraint key -- for future use
        """

        if self.GetSpecTag() == "":
            raise StandardError("Door ID e.g. EM_TC_001_001 is mandatory")

        if self.GetExpectedResult() == "":
            raise StandardError("Expected result data is mandatory e.g. angle> 30")

        if dbi_val.GetResultTypeId(self.GetType()) is None:
            res_type = {COL_NAME_RESULTTYPE_NAME: self.GetType(),
                        COL_NAME_RESULTTYPE_DESC: "automatic Added result type for ValTestStep",
                        COL_NAME_RESULTTYPE_CLASS: "ValTestStep"}
            dbi_val.AddResultType(res_type)
        if self.__CheckTestStepSpecTag(self.GetSpecTag()) is False:
            raise StandardError("Door ID is Not matching Standard format  e.g. ACC_TC_001_001-01")
        ValResult.Save(self, dbi_val, dbi_gbl, testrun_id, coll_id, obs_name=obs_name,
                       parent_id=parent_id, level=level,
                       cons_key=cons_key)

    def __CheckTestStepSpecTag(self, tag):  # pylint: disable= R0201
        """
        Check if the specification tag is matching DOORS format

        :param tag: Doors ID
        :type tag: Str
        """
#                       1        2   3  4   5   6   7  8   9   10  11 12  13   14
        pattern = "((^[a-z]{2,3}_[a-z]{2,3}|^[a-z]{2,3}))_TC_(\d{3})(_)(\d{3})(-)(\d{2})$"

        rg = re.compile(pattern, re.IGNORECASE | re.DOTALL)
        match = rg.search(tag)
        if match is not None:
            return True
        else:
            return False

    def GetValue(self):
        value = ValResult.GetValue(self)
        if isinstance(value, BaseValue):
            return value.GetValue()
        else:
            return value

# #    These Function are supressed for ValTestStep from its parent because it doenst make sense for TestSteps
    def GetMeasId(self):
        """
        Supressing the Parent class method which are not valid
        """
        raise StandardError("GetMeasId is not valid Method for ValTestStep Class")

    @property
    def test_result(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: test_result (as string)
        :rtype:  object of Type `ValAssessmentStates`
        """
        return self.GetAssessment().GetAssesmentState()

    @property
    def id(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: id
        :rtype:  string
        """
        return self.GetSpecTag()

    @property
    def name(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: Name of TestStep
        :rtype:  string
        """
        return self.GetName()

    @property
    def exp_result(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: expected result
        :rtype:  string
        """
        return self.GetExpectedResult()

    @property
    def meas_result(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: measured result in Testcase
        :rtype:  string
        """
        return str(self.GetValue())

    @property
    def asmt(self):
        """
        AlgoTestReport Interface overloaded attribute.

        :return: Assessment
        :rtype:  object of Type `ValAssessment`
        """
        return str(self.GetAssessment())


"""
CHANGE LOG:
-----------
$Log: results.py  $
Revision 1.1 2021/12/13 17:59:45CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/val/project.pj
Revision 1.23 2013/12/15 20:27:35CET Hecker, Robert (heckerr) 
Added AlgoTestReport Interface.
- Added comments -  heckerr [Dec 15, 2013 8:27:36 PM CET]
Change Package : 210873:1 http://mks-psad:7002/im/viewissue?selection=210873
Revision 1.22 2013/12/11 16:31:11CET Bratoi-EXT, Bogdan-Horia (uidu8192)
- adding a function
--- Added comments ---  uidu8192 [Dec 11, 2013 4:31:12 PM CET]
Change Package : 193409:1 http://mks-psad:7002/im/viewissue?selection=193409
Revision 1.21 2013/12/09 18:16:07CET Ahmed-EXT, Zaheer (uidu7634)
pep8 fix
--- Added comments ---  uidu7634 [Dec 9, 2013 6:16:07 PM CET]
Change Package : 210017:3 http://mks-psad:7002/im/viewissue?selection=210017
Revision 1.20 2013/12/09 18:07:13CET Ahmed-EXT, Zaheer (uidu7634)
Added GetAssessment() for ValTestcase and automatic evaluation of Assessment
Rollbacked Testcase result
--- Added comments ---  uidu7634 [Dec 9, 2013 6:07:14 PM CET]
Change Package : 210017:3 http://mks-psad:7002/im/viewissue?selection=210017
Revision 1.19 2013/11/28 12:29:40CET Ahmed-EXT, Zaheer (uidu7634)
Bug fix for oracle Exceeding Distand Time process result descriptor
modification in testcase structure to make Distance and Time process not the part of
standard  Measurement Result
--- Added comments ---  uidu7634 [Nov 28, 2013 12:29:40 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.18 2013/11/25 09:39:57CET Ahmed-EXT, Zaheer (uidu7634)
Fixed bug for Level3 Load and Distance evaluation from EgoMotion object
--- Added comments ---  uidu7634 [Nov 25, 2013 9:39:58 AM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.17 2013/11/18 15:55:40CET Ahmed-EXT, Zaheer (uidu7634)
Buf fixed for LoadTestStep under Testcase Load
--- Added comments ---  uidu7634 [Nov 18, 2013 3:55:41 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.16 2013/11/11 15:16:47CET Ahmed-EXT, Zaheer (uidu7634)
Fix pylint and pep8
testresult is deprecrated and replace by ValTestStep
Improved Documentation format
--- Added comments ---  uidu7634 [Nov 11, 2013 3:16:47 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.15 2013/11/11 08:30:14CET Ahmed-EXT, Zaheer (uidu7634)
Added GetMeasResult()
Deprecated  GetResult() --> use new function GetMeasResult() or GetTestSteps()
Remove total time and distance procoess saving
Fixed bug in ValResult.Load() --> Level4 with class_name "None" should return True without anything
--- Added comments ---  uidu7634 [Nov 11, 2013 8:30:15 AM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.14 2013/11/06 16:49:03CET Ahmed-EXT, Zaheer (uidu7634)
Added Functionality of Time and Distance process on testcase and meas level
--- Added comments ---  uidu7634 [Nov 6, 2013 4:49:03 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.13 2013/11/05 15:13:55CET Ahmed-EXT, Zaheer (uidu7634)
Fixed Regular Expression check for ValTestStep and ValTestCase
Improved Documentation
Revision 1.12 2013/11/04 10:27:42CET Ahmed-EXT, Zaheer (uidu7634)
Added DOORS ID format standard check in ValTestStep and ValTestCase class
Revision 1.11 2013/10/31 17:46:07CET Ahmed-EXT, Zaheer (uidu7634)
Added ValTestStep
Added functionality of Door URL expected result and Description support in ValTestcase and ValResult classes
--- Added comments ---  uidu7634 [Oct 31, 2013 5:46:07 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.10 2013/10/30 19:39:23CET Hecker, Robert (heckerr)
Removed indirect logging usage.
--- Added comments ---  heckerr [Oct 30, 2013 7:39:23 PM CET]
Change Package : 204154:1 http://mks-psad:7002/im/viewissue?selection=204154
Revision 1.9 2013/10/25 16:26:25CEST Hospes, Gerd-Joachim (uidv8815)
remove 'import stk' and replace missing dependencies
--- Added comments ---  uidv8815 [Oct 25, 2013 4:26:25 PM CEST]
Change Package : 203191:1 http://mks-psad:7002/im/viewissue?selection=203191
Revision 1.8 2013/09/10 10:06:36CEST Ahmed-EXT, Zaheer (uidu7634)
GetEvents function modified to support filter eventlist for measid
SetValue() method changed fix ambigous Resultvalues instance changed isInstance() --> type()
--- Added comments ---  uidu7634 [Sep 10, 2013 10:06:36 AM CEST]
Change Package : 196580:1 http://mks-psad:7002/im/viewissue?selection=196580
Revision 1.7 2013/08/21 13:24:39CEST Ahmed-EXT, Zaheer (uidu7634)
bug fixed for GetAssessment method return statement missing
pep8 and pylint fix
--- Added comments ---  uidu7634 [Aug 21, 2013 1:24:39 PM CEST]
Change Package : 192688:1 http://mks-psad:7002/im/viewissue?selection=192688
Revision 1.6 2013/07/29 13:03:18CEST Raedler, Guenther (uidt9430)
- check sub structure type to avoid warnings
--- Added comments ---  uidt9430 [Jul 29, 2013 1:03:18 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.5 2013/07/10 09:32:17CEST Raedler, Guenther (uidt9430)
- added basic support of testcase events
- added methods AddEvent(), GetEvents(), LoadEvents()
- moved ValSaveLoadLevel() into result_types.py
Note: VAL database update is required (new column rdid in VAL_Events table)
--- Added comments ---  uidt9430 [Jul 10, 2013 9:32:18 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.4 2013/06/05 16:28:47CEST Raedler, Guenther (uidt9430)
- added support of loading and storing result_types BaseValue, ValueVector, ValidationPlot, Histogram
- improved error handling
--- Added comments ---  uidt9430 [Jun 5, 2013 4:28:47 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.3 2013/05/29 09:10:33CEST Raedler, Guenther (uidt9430)
- bug fix of GetValue()
- minor preparations
--- Added comments ---  uidt9430 [May 29, 2013 9:10:34 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.2 2013/04/22 16:31:03CEST Raedler, Guenther (uidt9430)
- changed docu tags
- load testcase with given rd_id
--- Added comments ---  uidt9430 [Apr 22, 2013 4:31:04 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.1 2013/04/22 13:01:01CEST Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/val/project.pj
"""
