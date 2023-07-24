"""
stk/db/val/val.py
-------------------

Classes for Database access of Validation Results and Events.

 Sub-Scheme VAL


:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:55CET $
"""

# pylint: disable=C0103

# Import Python Modules -----------------------------------------------------------------------------------------------
import logging
from time import time
from datetime import datetime
import cx_Oracle

# Import STK Modules --------------------------------------------------------------------------------------------------
from ..db_common import BaseDB, ERROR_TOLERANCE_NONE, DB_FUNC_NAME_MIN, DB_FUNC_NAME_MAX, DB_FUNC_NAME_GETDATE, \
    DB_FUNC_NAME_LOWER, DB_FUNC_NAME_UPPER, AdasDBError, ERROR_TOLERANCE_LOW, ROLE_DB_ADMIN, SQLCEBaseDB, \
    OracleBaseDB, SQLite3BaseDB
from ..db_sql import GenericSQLStatementFactory, SQLBinaryExpr, OP_EQ, OP_IS, SQLLiteral, OP_AND, SQLFuncExpr, \
    SQLTableExpr, SQLJoinExpr, OP_INNER_JOIN, OP_OR, SQLColumnExpr, OP_LEFT_OUTER_JOIN, OP_AS, OP_IN, SQLNull

# Defines -------------------------------------------------------------------------------------------------------------
# Table base names:
TABLE_NAME_TESTRUN = "VAL_Testrun"
TABLE_NAME_VRKEY = "VAL_Keys"
TABLE_NAME_VRKEY_MAP = "VAL_ConstraintsMap"
TABLE_NAME_RESULT_DESC = "VAL_ResultDescriptor"
TABLE_NAME_RESULTTYPE = "VAL_ResultTypes"
TABLE_NAME_RESULT = "VAL_Result"
TABLE_NAME_RESULT_IMAGE = "VAL_ResultImage"
TABLE_NAME_RESULT_VALUES = "VAL_ResultValues"
TABLE_NAME_RESULT_MESSAGES = "VAL_ResultMessages"
TABLE_NAME_RESULT_LABEL_MAP = "VAL_ResultLabelMap"
TABLE_NAME_HIST = "VAL_Hist"

TABLE_NAME_ROAD_EVENTS = "VAL_EnvRoadEvents"

TABLE_NAME_EVENTTYPE = "VAL_EventTypes"
TABLE_NAME_EVENTS = "VAL_Events"
TABLE_NAME_EVENT_DETAILS = "VAL_EventDetails"
TABLE_NAME_EVENT_ATTR = "VAL_EventAttr"
TABLE_NAME_EVENT_ATTR_TYPES = "VAL_EventAttrTypes"
TABLE_NAME_EVENT_IMAGE = "VAL_EventImage"

TABLE_NAME_ASSESSMENT = "VAL_Assessment"
TABLE_NAME_EVENTS_VIEW = "VAL_View_Events"
TABLE_NAME_EVENTS_ATTRIBUTES_VIEW = "VAL_View_Events_Attributes"

# Testrun Table
COL_NAME_TR_ID = "TRID"
COL_NAME_TR_NAME = "NAME"
COL_NAME_TR_DESC = "DESCRIPTION"
COL_NAME_TR_START = "STARTTS"
COL_NAME_TR_END = "ENDTS"
COL_NAME_TR_CHECKPOINT = "CHECKPOINT"
COL_NAME_TR_USERID = "USERID"
COL_NAME_TR_TYPE_ID = "TYPEID"
COL_NAME_TR_PARENT = "PARENT"
COL_NAME_TR_COLL_NAME = "TESTDESIGN"
COL_NAME_TR_DELETED = "IS_DELETED"
COL_NAME_TR_TRUNLOCK = "IS_LOCKED"
COL_NAME_TR_PID = "PID"

# EventType Table
COL_NAME_EVENTTYPE_ID = "EVENTTYPEID"
COL_NAME_EVENTTYPE_NAME = "NAME"
COL_NAME_EVENTTYPE_DESC = "DESCRIPTION"
COL_NAME_EVENTTYPE_CLASSNAME = "CLASSNAME"

# Result Revision Key Table
COL_NAME_VRKEY_ID = "VAL_REV_KEY"
COL_NAME_VRKEY_NAME = "NAME"
COL_NAME_VRKEY_DESCRIPTION = "DESCRIPTION"

# Result Revision Key Mapping Table
COL_NAME_VRKEY_MAP_ID = "VAL_REV_KEY"
COL_NAME_VRKEY_MAP_RDID = "RDID"

# Result Descriptor Table
COL_NAME_RESDESC_ID = "RDID"
COL_NAME_RESDESC_NAME = "NAME"
COL_NAME_RESDESC_COLLID = "COLLID"
COL_NAME_RESDESC_RESTYPE_ID = "RESTYPEID"
COL_NAME_RESDESC_UNIT_ID = "UNITID"
COL_NAME_RESDESC_PARENT = "PARENT"
COL_NAME_RESDESC_REFTAG = "REFTAG"
COL_NAME_RESDESC_DOORS_URL = "DOORS_URL"
COL_NAME_RESDESC_EXPECTRES = "EXPECTRES"
COL_NAME_RESDESC_DESCRIPTION = "DESCRIPTION"

# ResultType Table
COL_NAME_RESULTTYPE_ID = "RESTYPEID"
COL_NAME_RESULTTYPE_NAME = "NAME"
COL_NAME_RESULTTYPE_DESC = "DESCRIPTION"
COL_NAME_RESULTTYPE_CLASS = "CLASSNAME"

# Result Table
COL_NAME_RES_ID = "RESID"
COL_NAME_RES_TESTRUN_ID = "TRID"
COL_NAME_RES_RESDESC_ID = "RDID"
COL_NAME_RES_VALUE = "VALUE"
COL_NAME_RES_MEASID = "MEASID"
COL_NAME_RES_RESASSID = "RESASSID"

# Result Image Table
COL_NAME_RESIMG_ID = "RESID"
COL_NAME_RESIMG_IMAGE = "IMAGE"
COL_NAME_RESIMG_TITLE = "TITLE"
COL_NAME_RESIMG_FORMAT = "FORMAT"

# Result Values  Table
COL_NAME_RESVAL_SUBID = "SUBID"
COL_NAME_RESVAL_ID = "RESID"
COL_NAME_RESVAL_VALUE = "VALUE"

# Result Messages  Table
COL_NAME_RESMESS_SUBID = "SUBID"
COL_NAME_RESMESS_ID = "RESID"
COL_NAME_RESMESS_MESS = "MESSAGE"


# Assessment  Table
COL_NAME_ASS_ID = "RESASSID"
COL_NAME_ASS_USER_ID = "USERID"
COL_NAME_ASS_COMMENT = "ASSCOMMENT"
COL_NAME_ASS_WFID = "WFID"
COL_NAME_ASS_DATE = "ASSDATE"
COL_NAME_ASS_ASSSTID = "ASSSTID"
COL_NAME_ASS_TRACKING_ID = "TRACKING_ID"

# Result Label Map Table
COL_NAME_RESLB_RESID = "RESID"
COL_NAME_RESLB_LBID = "LBID"

# Road evaluation table
COL_NAME_ROAD_EVALUATION_EVALID = "EVALID"
COL_NAME_ROAD_EVALUATION_TRID = "TRID"
COL_NAME_ROAD_EVALUATION_COLLID = "COLLID"
COL_NAME_ROAD_EVALUATION_MEASID = "MEASID"
COL_NAME_ROAD_EVALUATION_AREA = "AREA"

# Road events table
COL_NAME_ROAD_EVENTS_EVENTID = "EVENTID"
COL_NAME_ROAD_EVENTS_RESID = "RESID"
COL_NAME_ROAD_EVENTS_TIMESAMPLE = "TIMESAMPLE"
COL_NAME_ROAD_EVENTS_THRESHOLD = "THRESHOLD"
COL_NAME_ROAD_EVENTS_BEGINABSTS = "BEGINABSTS"
COL_NAME_ROAD_EVENTS_ENDABSTS = "ENDABSTS"

# AccSimAtomObjEvRectObjMap Table
COL_NAME_ACC_A_OBJ_EVENT_ROM_EVRECTOBJMAPID = "EVTRECTOBJOBJMAPID"
COL_NAME_ACC_A_OBJ_EVENT_ROM_SIMATOMOBJEVID = "SIMATOMOBJEVENTID"
COL_NAME_ACC_A_OBJ_EVENT_ROM_RECTOBJID = "RECTOBJID"

# AccSimAtomicObjEvent Table
COL_NAME_ACC_A_OBJ_EVENT_ATOMEVENTDESCID = "ATOMEVENTDESCID"
COL_NAME_ACC_A_OBJ_EVENT_OBJBININDEX = "OBJBININDEX"
COL_NAME_ACC_A_OBJ_EVENT_ATOMEVENTTIMESTAMP = "ATOMEVENTTIMESTAMP"
COL_NAME_ACC_A_OBJ_EVENT_OBJEVENTID = "OBJEVENTID"
COL_NAME_ACC_A_OBJ_EVENT_EGOSPDX = "EGOSPDX"
COL_NAME_ACC_A_OBJ_EVENT_EGOACCELX = "EGOACCELX"
COL_NAME_ACC_A_OBJ_EVENT_VDYRADIUS = "VDYRADIUS"
COL_NAME_ACC_A_OBJ_EVENT_OBJACCELX = "OBJACCELX"
COL_NAME_ACC_A_OBJ_EVENT_DISTX = "DISTX"
COL_NAME_ACC_A_OBJ_EVENT_RELSPDX = "RELSPDX"
COL_NAME_ACC_A_OBJ_EVENT_DISTY = "DISTY"
COL_NAME_ACC_A_OBJ_EVENT_RELSPDY = "RELSPDY"
COL_NAME_ACC_A_OBJ_EVENT_DISTYEGOPATH = "DISTYEGOPATH"
COL_NAME_ACC_A_OBJ_EVENT_DYNPROP = "DYNPROP"
COL_NAME_ACC_A_OBJ_EVENT_OBJCLASS = "OBJCLASS"

# Acc SimEvents Table
COL_NAME_ACC_EVENTS_SIMEVENTID = "SIMEVENTID"
COL_NAME_ACC_EVENTS_RESID = "RESID"
COL_NAME_ACC_EVENTS_BEGINABSTS = "BEGINABSTS"
COL_NAME_ACC_EVENTS_ENDABSTS = "ENDABSTS"
COL_NAME_ACC_EVENTS_STARTDRIVENDIST = "STARTDRIVENDIST"
COL_NAME_ACC_EVENTS_ENDDRIVENDIST = "ENDDRIVENDIST"

# Events Table
COL_NAME_EVENTS_SEID = "SEID"
COL_NAME_EVENTS_BEGINABSTS = "BEGINABSTS"
COL_NAME_EVENTS_ENDABSTS = "ENDABSTS"
COL_NAME_EVENTS_START_IDX = "START_IDX"
COL_NAME_EVENTS_STOP_IDX = "STOP_IDX"
COL_NAME_EVENTS_MEASID = "MEASID"
COL_NAME_EVENTS_TRID = "TRID"
COL_NAME_EVENTS_EVENTTYPEID = "EVENTTYPEID"
COL_NAME_EVENTS_RESASSID = "RESASSID"
COL_NAME_EVENTS_RDID = "RDID"

# Events View
COL_NAME_EVENTS_VIEW_ASSESSMENT = "ASSESSMENT"
COL_NAME_EVENTS_VIEW_SEID = "SEID"
COL_NAME_EVENTS_VIEW_BEGINABSTS = "BEGINABSTS"
COL_NAME_EVENTS_VIEW_ENDABSTS = "ENDABSTS"
COL_NAME_EVENTS_VIEW_START_IDX = "START_IDX"
COL_NAME_EVENTS_VIEW_STOP_IDX = "STOP_IDX"
COL_NAME_EVENTS_VIEW_MEASID = "MEASID"
COL_NAME_EVENTS_VIEW_TRID = "TRID"
COL_NAME_EVENTS_VIEW_EVENTTYPE = "EVENTTYPE"
COL_NAME_EVENTS_VIEW_CLASSNAME = "CLASSNAME"
COL_NAME_EVENTS_VIEW_FILE_NAME = "FILENAME"
COL_NAME_EVENTS_VIEW_COMMENT = "ASSCOMMENT"
COL_NAME_EVENTS_VIEW_RESASSID = "RESASSID"
COL_NAME_EVENTS_VIEW_ABSTS = "ABSTS"
COL_NAME_EVENTS_VIEW_NAME = "NAME"
COL_NAME_EVENTS_VIEW_ATTRID = "ATTRID"
COL_NAME_EVENTS_VIEW_VALUE = "VALUE"
COL_NAME_EVENTS_VIEW_ATTRTYPEID = "ATTRTYPEID"
COL_NAME_EVENTS_VIEW_RDID = "RDID"

# EventDetails Table
COL_NAME_EVENT_DET_EDID = "EDID"
COL_NAME_EVENT_DET_ABSTS = "ABSTS"
COL_NAME_EVENT_DET_SEID = "SEID"

# EventAttr Table
COL_NAME_EVENT_ATTR_ATTRID = "ATTRID"
COL_NAME_EVENT_ATTR_ATTRTYPEID = "ATTRTYPEID"
COL_NAME_EVENT_ATTR_VALUE = "VALUE"
COL_NAME_EVENT_ATTR_EDID = "EDID"

# Result Image Table
COL_NAME_EVENT_IMG_ATTRID = "ATTRID"
COL_NAME_EVENT_IMG_IMAGE = "IMAGE"
COL_NAME_EVENT_IMG_TITLE = "TITLE"
COL_NAME_EVENT_IMG_FORMAT = "FORMAT"

# EventAttrTypes
COL_NAME_EVENT_ATTR_TYPES_ATTRTYPEID = "ATTRTYPEID"
COL_NAME_EVENT_ATTR_TYPES_NAME = "NAME"
COL_NAME_EVENT_ATTR_TYPES_DESC = "DESCRIPTION"
COL_NAME_EVENT_ATTR_TYPES_UNITID = "UNITID"
COL_NAME_EVENT_ATTR_TYPES_PARENT = "PARENT"

# AccSimObjEvents Table
COL_NAME_ACC_OBJ_EVENTS_OBJEVENTID = "OBJEVENTID"
COL_NAME_ACC_OBJ_EVENTS_SIMEVENTID = "SIMEVENTID"
COL_NAME_ACC_OBJ_EVENTS_OBJEVENTTYPE = "OBJEVENTTYPE"
COL_NAME_ACC_OBJ_EVENTS_CRITICALITY = "CRITICALITY"

# AccSimObjEventTypes Table
COL_NAME_ACC_OBJ_EVENT_T_OBJEVENTTYPE = "OBJEVENTTYPE"
COL_NAME_ACC_OBJ_EVENT_T_NAME = "NAME"
COL_NAME_ACC_OBJ_EVENT_T_DESCRIPTION = "DESCRIPTION"

# Column result default value. Default return value if no result is found.
COL_RES_DEF_VAL = -1

# Testrun lock is supported with version 8.0
DELETE_LOCK_TRUN_FEATURE = 8
TRUN_LOCK_VALUE = 1
TRUN_UNLOCK_VALUE = 0
TRUN_IS_DELETED = 1
TRUN_IS_NOT_DELETED = 0

SUB_SCHEME_TAG = "VAL"

IDENT_STRING = "dbval"
# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class BaseValResDB(BaseDB):   # pylint: disable=R0904
    """Base implementation of the Rec File Database"""
    #====================================================================
    # Constraint DB Libary Interface for public use
    #====================================================================

    #====================================================================
    # Handling of database
    #====================================================================

    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(), error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize constraint database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseDB.__init__(self, db_connection, table_prefix, sql_factory, IDENT_STRING)
        self.sync_slave_reload_all = False
        self.error_tolerance = error_tolerance

    def Initialize(self):
        """Initialize the database proxy"""
        # Setup function names
        BaseDB.Initialize(self)
        self.db_func_map[DB_FUNC_NAME_MIN] = "MIN"
        self.db_func_map[DB_FUNC_NAME_MAX] = "MAX"
        self.db_func_map[DB_FUNC_NAME_GETDATE] = "GETDATE()"
        self.db_func_map[DB_FUNC_NAME_LOWER] = "LOWER"
        self.db_func_map[DB_FUNC_NAME_UPPER] = "UPPER"
        self.sub_scheme_version = self.GetSubSchemeVersion(SUB_SCHEME_TAG)

    def Terminate(self):
        """Terminate the database proxy"""
        BaseDB.Terminate(self)

    # --- TESTRUN Table. --------------------------------------------------
    def AddTestRun(self, testrun, replace=False):  # pylint: disable=R0912
        """Add a new testrun to the database.
        :param testrun: The testrun dictionary
        :param replace: Replace
        :return: Returns the testrun ID.
        """
        try:
            cond = self.__GetTestrunCondition(name=testrun[COL_NAME_TR_NAME],
                                              check_point=testrun[COL_NAME_TR_CHECKPOINT],
                                              tr_type=testrun[COL_NAME_TR_TYPE_ID],
                                              pid=testrun[COL_NAME_TR_PID])
        except StandardError, ex:
            raise AdasDBError("Can't create testrun condition. Error: '%s'" % (ex))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)], where=cond)

        if COL_NAME_TR_COLL_NAME not in testrun:
            testrun[COL_NAME_TR_COLL_NAME] = ''

        if len(entries) == 1 and replace is True:
            stored_tr_uid = int(entries[0][COL_NAME_TR_USERID])
            current_uid = int(testrun[COL_NAME_TR_USERID])
            if(stored_tr_uid != current_uid):
                msg = "For the checkpoint '" + testrun[COL_NAME_TR_CHECKPOINT]
                msg += "' a Testrun '%s' has already been created in" % testrun[COL_NAME_TR_NAME]
                msg += "the validation result database by another user (user_id %d)" % stored_tr_uid
                raise AdasDBError(msg)

            trid = int(entries[0][COL_NAME_TR_ID])
            if self.DeleteTestRun(tr_id=trid) != -1:
                self.Commit()
                logging.debug(str("Testrun '%s' deleted." % testrun[COL_NAME_TR_NAME]))
                self.AddGenericData(testrun, self.GetQualifiedTableName(TABLE_NAME_TESTRUN))
                entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)],
                                                 where=cond)
                if len(entries) == 1:
                    trid = entries[0][COL_NAME_TR_ID]
                else:
                    raise AdasDBError("Testrun name '%s' cannot be added. " % (testrun[COL_NAME_TR_NAME]))
            else:
                return trid
        elif len(entries) <= 0:
            self.AddGenericData(testrun, self.GetQualifiedTableName(TABLE_NAME_TESTRUN))
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)], where=cond)
            if len(entries) == 1:
                trid = entries[0][COL_NAME_TR_ID]
            else:
                raise AdasDBError("Testrun name '%s' cannot be added. " % (testrun[COL_NAME_TR_NAME]))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Testrun '%s' exists already in the validation result database" % testrun[COL_NAME_TR_NAME]
                raise AdasDBError(tmp)
            else:
                tmp = "Testrun '%s' already exists in the validation result database." % testrun[COL_NAME_TR_NAME]
                logging.warn(tmp)
                if len(entries) == 1:
                    trid = entries[0][COL_NAME_TR_ID]
                elif len(entries) > 1:
                    tmp = "Testrun name '%s' " % (testrun[COL_NAME_TR_NAME])
                    tmp += "cannot be resolved because it is ambiguous. (%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return int(trid)

    def UpdateTestRun(self, testrun, where=None):
        """Update existing testrun records.
        :param testrun: The testrun record update.
        :param where: The condition to be fulfilled by the workflow to the updated.
        :return: Returns the number of affected workflow.
        """
        rowcount = 0

        if where is None:
            where = self.__GetTestrunCondition(name=testrun[COL_NAME_TR_NAME], delete_status=0)

        if (testrun is not None) and (len(testrun) != 0):
            rowcount = self.UpdateGenericData(testrun, self.GetQualifiedTableName(TABLE_NAME_TESTRUN), where)
        # done
        return rowcount

    def DeleteTestRun(self, name=None, checkpoint=None, type_id=None, user_id=None, tr_id=None, recursive=False):
        """Delete existing testrun records.
        :param name: name of the testrun to delete
        :param checkpoint: corresponding checkpoint
        :param type_id: Type of the testrun
        :param user_id: user ID of the testrun
        :param tr_id: Testrun ID - If given, the parameter name, checkpoint, typeid and user_id will be neglegted.
        :param recursive: delete the child testruns as well - optional argument
        :return: Returns the number of affected workflow.
        """
        rowcount = 0
        if tr_id is None:
            tr_id = self.GetTestRunId(name, checkpoint, type_id, user_id)

        if self.sub_scheme_version < DELETE_LOCK_TRUN_FEATURE or self.role == ROLE_DB_ADMIN:
            # Support for old version of VAL db
            rowcount = 0
            if tr_id is None:
                tr_id = self.GetTestRunId(name, checkpoint, type_id, user_id)

            for testrun in self.GetTestRunIdsForParent(tr_id):
                rowcount += self.DeleteTestRun(tr_id=testrun, recursive=rowcount)

            rowcount += self.__DeleteAllResultsOfTestRun(tr_id)
            self.Commit()

            if rowcount != -1:
                cond = self.__GetTestrunCondition(tr_id=tr_id)
                rowcount += self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_TESTRUN), where=cond)
            # done
            return rowcount
        else:
            if recursive:
                trids = self.GetTestRunIdsForParent(id)
                if len(trids) > 0:
                    for trid in trids:
                        self.DeleteTestRun(tr_id=trid, recursive=True)
                else:
                    self.DeleteTestRun(tr_id=tr_id, recursive=False)

            if self.__IsTestRunLock(tr_id):
                raise AdasDBError("Testrun id = '%d' is Locked and in the validation result database" % id)

            testrun = self.GetTestRun(tr_id=tr_id)
            testrun.pop(COL_NAME_TR_START)
            testrun.pop(COL_NAME_TR_END)
            # check if the test run is not already deleted
            if testrun[COL_NAME_TR_DELETED] == TRUN_IS_NOT_DELETED:
                testrun[COL_NAME_TR_DELETED] = TRUN_IS_DELETED
                cond = cond = self.__GetTestrunCondition(tr_id=tr_id, delete_status=0)
                self.UpdateGenericData(testrun, self.GetQualifiedTableName(TABLE_NAME_TESTRUN), where=cond)
                return 1

    def RestoreTestRun(self, name=None, checkpoint=None, type_id=None, user_id=None, tr_id=None, recursive=False):
        """ Restore a deleted TestRun
        :param name: Name of the testrun
        :param checkpoint: checkpoint name
        :param type_id: Oberserver Type ID
        :param user_id: User Identifier
        :param tr_id: Testrun ID
        :param rescursive: If True, process child testruns as well
        """
        # rowcount = 0
        if self.role != ROLE_DB_ADMIN:
            raise AdasDBError("Inssufficient Priviliage to Restore TestRUN")
        if tr_id is None:
            testrun = self.GetTestRun(name=name, checkpoint=checkpoint, type_id=type_id, user_id=user_id)
            tr_id = testrun[COL_NAME_TR_ID]
        else:
            # cond = self.__GetTestrunCondition(name, checkpoint, type, user_id, delete_status=1)
            testrun = self.GetTestRun(tr_id=tr_id)
        if recursive:
            trids = self.GetTestRunIdsForParent(tr_id, delete_status=1)
            if len(trids) > 0:
                for _tr_id in trids:
                    self.RestoreTestRun(tr_id=_tr_id, recursive=True)
            else:
                self.RestoreTestRun(tr_id=tr_id, recursive=False)

        cond = self.__GetTestrunCondition(tr_id=tr_id, delete_status=1)
        testrun = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)], where=cond)
        if len(testrun) == 1:
            testrun = testrun[0]
            testrun.pop(COL_NAME_TR_START)
            testrun.pop(COL_NAME_TR_END)
            testrun[COL_NAME_TR_DELETED] = 0
            self.UpdateGenericData(testrun, self.GetQualifiedTableName(TABLE_NAME_TESTRUN), where=cond)
        else:
            raise AdasDBError("Testrun name cannot be restore due to ambigious data in TestRun table. ")
            # rowcount += self.DeleteTestRun(tr_id=testrun, recursive=rowcount)

    def GetTestRunLock(self, name=None, checkpoint=None, type_id=None, user_id=None, tr_id=None):
        """Check lock status for the given TestRun ID
        :param trid: Testrun id
        :return: boolean status if lock value is None-Zero return True else return False
        """
        if tr_id is None:
            tr_id = self.GetTestRunId(name, checkpoint, type_id, user_id)
        return int(self.__IsTestRunLock(tr_id))

    def UpdateTestRunLock(self, name=None,
                          checkpoint=None,
                          type_id=None,
                          user_id=None,
                          tr_id=None,
                          recursive=False,
                          lock=None,
                          unlock=None):
        """Set TESTRUN Lock or unLock
        :param lock: Testrun id
        :return: unlockstatus if lock value is None-Zero return True else return False
        """
        # pylint: disable=R0913
        testrun = None
        if self.sub_scheme_version < DELETE_LOCK_TRUN_FEATURE:
            raise AdasDBError("The Lock system is only available in dbval ver>= %d" % (DELETE_LOCK_TRUN_FEATURE))

        if tr_id is None:
            testrun = self.GetTestRun(name=name, checkpoint=checkpoint, type_id=type_id, user_id=user_id)
            tr_id = testrun[COL_NAME_TR_ID]
        else:
            testrun = self.GetTestRun(tr_id=tr_id)

        if recursive:
            trids = self.GetTestRunIdsForParent(tr_id)
            if len(trids) > 0:
                for trid in trids:
                    self.UpdateTestRunLock(tr_id=trid, recursive=True, lock=lock, unlock=unlock)
            else:
                self.UpdateTestRunLock(tr_id=tr_id, recursive=False, lock=lock, unlock=unlock)
        testrun.pop(COL_NAME_TR_START)
        testrun.pop(COL_NAME_TR_END)
        if lock is not None and unlock is None:
            testrun[COL_NAME_TR_TRUNLOCK] = TRUN_LOCK_VALUE
        if lock is None and unlock is not None:
            testrun[COL_NAME_TR_TRUNLOCK] = TRUN_UNLOCK_VALUE

        if (lock is not None and unlock is not None) or (lock is None and unlock is None):
            raise AdasDBError("Testrun Lock request is ambigious \
                               because both flag are set to True or False for TRUN ID %d " % (tr_id))
        else:
            cond = self.__GetTestrunCondition(tr_id=tr_id)
            self.UpdateGenericData(testrun, self.GetQualifiedTableName(TABLE_NAME_TESTRUN), where=cond)

    def __IsTestRunLock(self, tr_id):
        """Check lock status for the given TestRun ID
        :param tr_id: Testrun id
        :return: boolean status if lock value is None-Zero return True else return False
        """
        if self.sub_scheme_version < DELETE_LOCK_TRUN_FEATURE:
            raise AdasDBError("The Lock system is only available in dbval ver>= %d" % (DELETE_LOCK_TRUN_FEATURE))
        else:
            testrun = self.GetTestRun(tr_id=tr_id)
            if testrun[COL_NAME_TR_TRUNLOCK] != 0:
                return True
            else:
                return False
        # done

    def __DeleteAllResultsOfTestRun(self, tr_id=None):
        """Delete existing results of a testrun.
        :param tr_id: The testrun id to delete.
        :return: Returns the number of affected eventtypes.

        @todo: Don't delete the testrun if any assessment was made
        """
        rowcount = 0
        results = self.GetResultIds(tr_id)
        for row in results:
            record = {}
            resid = int(row[0])

            assessment_id = self.GetResult(tr_id=tr_id, res_id=resid)[COL_NAME_RES_RESASSID]
            if assessment_id is not None:
                self.DeleteAssessment(assessment_id)
            # deletes all images
            record[COL_NAME_RESIMG_ID] = resid
            rowcount += self.DeleteResultImage(record)
            # delete all Result Messages
            record[COL_NAME_RESMESS_ID] = resid
            rowcount += self.DeleteResultMessage(record)
            # delete all Result Values
            record[COL_NAME_RESVAL_ID] = resid
            rowcount += self.DeleteResultValue(record)
            # delete label links
            rowcount += self.DeleteResultLabel(resid)
            # delete road events
            rowcount += self.DeleteRoadEvent(resid)
            self.Commit()

        resx = {}
        resx[COL_NAME_RES_TESTRUN_ID] = tr_id
        rowcount += self.DeleteResult(resx)

        # delete all the events
        events = self.GetEvents(trid=tr_id)
        for row in events:
            seid = row[COL_NAME_EVENTS_SEID]
            assessment_id = row[COL_NAME_EVENTS_RESASSID]
            self.DeleteEvent(seid)
            # delete all assessments
            rowcount += self.DeleteAssessment(assessment_id)

        # done
        return rowcount

    def GetAllTestruns(self, name=None, checkpoint=None, type_id=None,
                       user_id=None, tr_id=None, proj_id=None, delete_status=0):
        """ Get all testruns by Name and optional Checkpoint, TestRunType or UserID
        :param name: Name of the testrun
        :param checkpoint: Checkpoint Name
        :param type_id: Checkpoint Name
        :param user_id: User Identifier
        :param tr_id: Testrun Identifier
        :param proj_id: Project id
        :param delete_status: 0/1 - not/ deleted
        :return: Testrun record
        """
        record = {}

        cond = self.__GetTestrunCondition(name, checkpoint, type_id, user_id, tr_id, delete_status, pid=proj_id)
        orderby = [COL_NAME_TR_START]
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)],
                                         where=cond, order_by=orderby)
        if len(entries) <= 0:
            logging.warn(str("testrun with name '%s' does not exist in the validation result database." % name))
        else:
            record = entries
        # done
        return record

    def GetSeidsForTestrun(self, tr_id, measids):
        """ Get all SEIDs for the specified testrun and measid
        :return: seid's record
        """
        columns = [COL_NAME_EVENTS_VIEW_SEID]
        cond = self.__GetEventCondition(trid=tr_id, measid=measids)
        entries = self.SelectGenericData(distinct_rows=True, select_list=columns,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS_VIEW)],
                                         where=cond)
        if len(entries) <= 0:
            tmp = "There are no seids for testrun '%s'" % (str(tr_id))
            tmp += "and measid '%s' in the validation result database." % (str(measids))
            logging.warn(tmp)
        # done
        return entries

    def GetMeasidsForTestrun(self, tr_id):
        """ Get all MEASIDs for the specified testrun
        :return: measid's record
        """
        columns = [COL_NAME_EVENTS_VIEW_MEASID, COL_NAME_EVENTS_VIEW_FILE_NAME]
        orderby = [COL_NAME_EVENTS_VIEW_FILE_NAME]
        cond = self.__GetTestrunCondition(tr_id=tr_id)
        entries = self.SelectGenericData(distinct_rows=True, select_list=columns,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS_VIEW)],
                                         where=cond, order_by=orderby)
        if len(entries) <= 0:
            logging.warn(str("There are no measids for testrun '%s' in the validation result database." % str(tr_id)))
        # done
        return entries

    def GetTestRun(self, name=None, checkpoint=None, type_id=None, user_id=None, tr_id=None, parent_id=None, pid=None):
        """ Get a testrun by Name and optional Checkpoint, TestRunType or UserID
        :param name: Name of the testrun
        :param checkpoint: Checkpoint Name
        :param type_id: Checkpoint Name
        :param user_id: User Identifier
        :param tr_id: Testrun Identifier
        :return: Testrun record
        """
        record = {}

        cond = self.__GetTestrunCondition(name=name, check_point=checkpoint,
                                          tr_type=type_id, user_id=user_id, tr_id=tr_id,
                                          parent_id=parent_id, pid=pid)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)], where=cond)
        if len(entries) <= 0:
            msg = "testrun with name '%s' does not exist in the val result database for the current user" % name
            logging.warn(str(msg))
        elif len(entries) > 1:
            logging.warn(str("testrun with name '%s' cannot be resolved because it is ambiguous. (%s)" %
                             (name, str(len(entries)))))
        else:
            record = entries[0]
        # done
        return record

    def GetTestRunIdsForParent(self, parent_id, delete_status=0):
        """ Get the testruns for a given parent id
        :param parent_id: Parent ID of the Test run
        :return: Returns a list of testrun Id taking the parent ID as parent
        """
        try:
            parent_id = int(parent_id)
        except:
            raise AdasDBError("Parent_id is not an integer")

        id_list = []
        cond = self.__GetTestRunParentCondition(parent_id, delete_status)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)], where=cond)
        for rec in entries:
            id_list.append(int(rec[COL_NAME_TR_ID]))

        return id_list

    def GetTestRunId(self, name, checkpoint=None, type_id=None, user_id=None, parent_id=None):
        """ Get a testrun by Name and optional Checkpoint, TestRunType or UserID
        :param name: Name of the testrun
        :param checkpoint: Checkpoint Name
        :param type_id: Validation Observer ID
        :param user_id: User Identifier
        :return: Testrun ID
        """
        record = self.GetTestRun(name=name, checkpoint=checkpoint, type_id=type_id,
                                 user_id=user_id, parent_id=parent_id)
        if COL_NAME_TR_ID in record:
            return int(record[COL_NAME_TR_ID])

        return - 1

    def GetDeletedTestRunIds(self, name=None, checkpoint=None, pid=None, limit=10):
        """
        Get all Parent Test Run given with limited no. of record for testrun
        :param limit: limit to return no. of testrun ids since deletetion takes long time
        :type limit: int
        :return: List of testrun Ids
        """

        if self.role == ROLE_DB_ADMIN and self.sub_scheme_version >= DELETE_LOCK_TRUN_FEATURE:
            cond_del = self.__GetTestrunCondition(name=name, check_point=checkpoint,
                                                  pid=pid, delete_status=1)
#            cond_par = SQLBinaryExpr(COL_NAME_TR_PARENT, OP_IS, "NULL")
#            cond = SQLBinaryExpr(cond_del, OP_AND, cond_par)
            cond = cond_del
            entries = self.SelectGenericData(select_list=[COL_NAME_TR_ID],
                                                   table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)],
                                                   where=cond)
            record = []
            for entry in entries:
                record.append(entry[COL_NAME_TR_ID])

            if limit > 0 and len(record) > limit:
                record = record[:limit]

            childs = []
            for rec in record:
                childs += self.__GetChildTestRunId(rec, delete_status=1, recursive=True)
            return list(set(record + childs))
#            return record
        else:
            raise AdasDBError("Cannot executed due to inssufficient privilage contact Administrator")

    def __GetChildTestRunId(self, parent_id, delete_status=0, recursive=True):
        """ Get the testruns for a given parent id
        :param parent_id: Parent ID of the Test run
        :return: Returns a list of testrun Id taking the parent ID as parent
        """

        trid = self.GetTestRunIdsForParent(parent_id, delete_status=delete_status)
        if not recursive:
            return trid
        else:
            for tr in trid:
                return trid + self.__GetChildTestRunId(tr, delete_status=delete_status, recursive=recursive)
            return trid

    def __GetTestRunParentCondition(self, parent_id, delete_status=0):
        """ Get the parent condition of a testrun
        :param parent_id: Parent ID of the Test run
        :return: Returns the condition expression
        """
        cond = SQLBinaryExpr(COL_NAME_TR_PARENT, OP_EQ, SQLLiteral(parent_id))
        if self.sub_scheme_version >= DELETE_LOCK_TRUN_FEATURE:
            cond_del = SQLBinaryExpr(COL_NAME_TR_DELETED, OP_EQ, delete_status)
            cond = SQLBinaryExpr(cond, OP_AND, cond_del)
        return cond

    def __GetTestrunCondition(self, name=None, check_point=None, tr_type=None, user_id=None,
                              tr_id=None, delete_status=0, parent_id=None, pid=None):
        """Get the condition expression to access the testrun.
        :param name: Name of the testrun (optional)
        :param check_point: checkpoint (optional)
        :param tr_type: Testrun type id (optional)
        :param user_id: User ID (optional)
        :param tr_id: Test run ID. If set, other setting will neglected
        :param delete: Flag to add delete condition for newer version support to set condition for undelete testrun
        :return: Returns the condition expression
        """
        # pylint: disable=R0912,R0913
        cond = None

        if tr_id is not None:
            cond = SQLBinaryExpr(COL_NAME_TR_ID, OP_EQ, tr_id)
        else:
            if name is not None:
                cond_name = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                      COL_NAME_TR_NAME),
                                          OP_EQ,
                                          SQLLiteral(name.lower()))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_name)
                else:
                    cond = cond_name
            if check_point is not None:
                cond_cp = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                    COL_NAME_TR_CHECKPOINT),
                                        OP_EQ,
                                        SQLLiteral(check_point.lower()))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_cp)
                else:
                    cond = cond_cp
            if tr_type is not None:
                cond_cp = SQLBinaryExpr(COL_NAME_TR_TYPE_ID, OP_EQ, tr_type)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_cp)
                else:
                    cond = cond_cp
            if user_id is not None:
                cond_cp = SQLBinaryExpr(COL_NAME_TR_USERID, OP_EQ, user_id)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_cp)
                else:
                    cond = cond_cp
            if parent_id is not None:
                cond_pt = SQLBinaryExpr(COL_NAME_TR_PARENT, OP_EQ, parent_id)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_pt)
                else:
                    cond = cond_pt
            if pid is not None:
                cond_pid = SQLBinaryExpr(COL_NAME_TR_PID, OP_EQ, pid)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_pid)
                else:
                    cond = cond_pid

            if self.sub_scheme_version >= DELETE_LOCK_TRUN_FEATURE and delete_status is not None:
                cond_del = SQLBinaryExpr(COL_NAME_TR_DELETED, OP_EQ, delete_status)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_del)
                else:
                    cond = cond_del
        return cond

    def GetFilteredResultsTypesDetailsAssessment(self, tr_id,
                                                 meas_id=None,
                                                 res_id=None,
                                                 predef_filter_str=None,
                                                 filter_str=None,
                                                 how_many=None):
        """Get the Results from VAL_RESULTS.
        :param trid: Testrun id
        :param measid: Measurement id (optional)
        :param res_id: result id (optional)
        :param predef_filter_str: prepared predefined filter list (optional)
        :param filter_str: prepared filter list (optional)
        :param how_many: how many rows should be retrieved (if not set - all rows to be retrieved)
        :return: time, results : Returns the duration and the list of selected results
        """
        # pylint: disable=W0613
# select rt.name        as res_type,
#       rd.rdid,
#       rd.name        as res_descriptor,
#       re.value,
#       gu.name        as unit,
#       cf.recfileid   as filename,
#       re.resassid    as assessment
# from DEV_ARS4XX_ADMIN.val_result re
# inner join DEV_ARS4XX_ADMIN.val_testrun tr on tr.trid = re.trid
# inner join DEV_ARS4XX_ADMIN.val_resultdescriptor rd on rd.rdid = re.rdid
# inner join DEV_ARS4XX_ADMIN.val_resulttypes rt on rt.restypeid = rd.restypeid
# inner join DEV_ARS4XX_ADMIN.cat_files cf on cf.measid = re.measid
# inner join DEV_ARS4XX_ADMIN.gbl_units gu on gu.unitid = rd.unitid
# where tr.typeid = 10 and tr.trid = 1095
# order by re.measid

        start_time = time()
        columns = ["rt." + COL_NAME_RESULTTYPE_NAME + " AS Res_type",
                   "re." + COL_NAME_RES_ID,
                   "rd." + COL_NAME_RESDESC_NAME + " AS Res_descriptor",
                   "re." + COL_NAME_RES_VALUE,
                   "rd." + COL_NAME_RESDESC_UNIT_ID + " AS Unit",
                   "re." + COL_NAME_RES_MEASID + " AS Filename",
                   "re." + COL_NAME_RES_RESASSID + " AS Assessment"]

        orderby = ["re." + COL_NAME_RES_MEASID]
        tables = []
        join = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RESULT) + " re")
        join_1 = SQLJoinExpr(join,
                             OP_INNER_JOIN,
                             SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TESTRUN) + " tr"),
                             "tr." + COL_NAME_TR_ID + " = re." + COL_NAME_RES_TESTRUN_ID)
        join_2 = SQLJoinExpr(join_1,
                             OP_INNER_JOIN,
                             SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC) + " rd"),
                             "rd." + COL_NAME_RESDESC_ID + " = re." + COL_NAME_RES_RESDESC_ID)
        join_3 = SQLJoinExpr(join_2,
                             OP_INNER_JOIN,
                             SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE) + " rt"),
                             "rt." + COL_NAME_RESULTTYPE_ID + " = rd." + COL_NAME_RESDESC_RESTYPE_ID)

        tables.append(join_3)

        cond = []
        if cond == []:
            cond = SQLBinaryExpr("re." + COL_NAME_RES_TESTRUN_ID, OP_EQ, tr_id)
        if meas_id is not None:
            cond_cp = SQLBinaryExpr("re." + COL_NAME_RES_MEASID, OP_EQ, meas_id)
            cond = SQLBinaryExpr(cond, OP_AND, cond_cp)
        if res_id is not None:
            cond_cp = SQLBinaryExpr("re." + COL_NAME_RES_ID, OP_EQ, res_id)
            cond = SQLBinaryExpr(cond, OP_AND, cond_cp)

        entries = self.SelectGenericData(distinct_rows=True, select_list=columns,
                                         table_list=tables, where=cond, order_by=orderby)
        elapsed_time = time() - start_time
        return elapsed_time, entries

    def GetFilteredEventTypesDetailsAttributesAssessment(self, trid,
                                                         measid=None,
                                                         seid=None,
                                                         predef_filter_str=None,
                                                         filter_str=None,
                                                         how_many=None):
        """Get the events attributes for the assessment from the VAL_VIEW_EVENTS_ATRIBUTES.
        :param trid: Testrun id
        :param measid: Measurement id (optional)
        :param seid: seid (optional)
        :param predef_filter_str: prepared predefined filter list (optional)
        :param filter_str: prepared filter list (optional)
        :param how_many: how many rows should be retrieved (if not set - all rows to be retrieved)
        :return: time, events : Returns the duration and the list of selected events
        """
        # pylint: disable=W0613,R0912

# SELECT DISTINCT SEID, q1.BEGINABSTS, q1.ENDABSTS, q1.FILENAME, q1.EVENTTYPE, q1.ASSESSMENT
# FROM DEV_ARS34X_ADMIN.VAL_View_Events_Attributes Q1
# INNER JOIN
#    (SELECT * FROM VAL_EVENTDETAILS evd
#    INNER JOIN DEV_ARS34X_ADMIN.VAL_EventAttr ea ON ea.EDID = evd.EDID
#    INNER JOIN DEV_ARS34X_ADMIN.VAL_EventAttrTypes eat ON ea.ATTRTYPEID =
#     eat.ATTRTYPEID  AND eat.NAME = 'distx' AND ea.VALUE > 95) Q2
# ON Q1.SEID = Q2.SEID
# INNER JOIN
#    (SELECT * FROM VAL_EVENTDETAILS evd
#    INNER JOIN DEV_ARS34X_ADMIN.VAL_EventAttr ea ON ea.EDID = evd.EDID
#    INNER JOIN DEV_ARS34X_ADMIN.VAL_EventAttrTypes eat ON ea.ATTRTYPEID =
#    eat.ATTRTYPEID  AND eat.NAME = 'vehspeed' AND ea.VALUE > 33.5) Q3
# ON Q1.SEID = Q3.SEID
# WHERE (TRID = 2741) And (assessment = 'Valid')  ORDER BY SEID;

        start_time = time()
        columns = [COL_NAME_EVENTS_VIEW_SEID, "Q1." +
                   COL_NAME_EVENTS_VIEW_BEGINABSTS,
                   COL_NAME_EVENTS_VIEW_ENDABSTS,
                   COL_NAME_EVENTS_VIEW_FILE_NAME,
                   COL_NAME_EVENTS_VIEW_EVENTTYPE,
                   #   COL_NAME_EVENTS_VIEW_CLASSNAME,
                   COL_NAME_EVENTS_VIEW_ASSESSMENT]
        orderby = [COL_NAME_EVENTS_VIEW_SEID]
        tables = []
        join = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_EVENTS_ATTRIBUTES_VIEW) + " Q1")

        no = 0
        for _filter in filter_str:
            if _filter.GetType() == 'attribute':
                no += 1
                values = _filter.GetValues()
                sel_stmt = "(SELECT * FROM " + self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS) + \
                           " evd INNER JOIN " + self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR) + \
                           " ea ON  ea.EDID = evd.EDID " + " INNER JOIN " + \
                           self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR_TYPES) + \
                           " eat ON ea.ATTRTYPEID = eat.ATTRTYPEID  AND eat.NAME = '" + \
                           str(_filter.GetName())
                sel_stmt += "' AND ea.VALUE "  # > 22.22 and ea.value < 40) j2 on j1.edid = j2.edid
                if str(_filter.GetOperator()) == 'Between':
                    sel_stmt = sel_stmt + "> " + str(values[0]) + " AND ea.VALUE < " + str(values[1])
                else:
                    sel_stmt = sel_stmt + str(_filter.GetOperator()) + " " + str(values[0])
                sel_stmt = sel_stmt + ") Q" + str(no + 1)

                join = SQLJoinExpr(join,
                                   OP_INNER_JOIN,
                                   sel_stmt,
                                   "Q1.SEID = Q" + str(no + 1) + ".SEID")
        tables.append(join)

        cond = []
        if cond == []:
            cond = SQLBinaryExpr(COL_NAME_EVENTS_TRID, OP_EQ, trid)
        if measid is not None:
            cond_cp = SQLBinaryExpr(COL_NAME_EVENTS_MEASID, OP_EQ, measid)
            cond = SQLBinaryExpr(cond, OP_AND, cond_cp)
        if seid is not None:
            cond_cp = SQLBinaryExpr(COL_NAME_EVENTS_SEID, OP_EQ, seid)
            cond = SQLBinaryExpr(cond, OP_AND, cond_cp)

        tmp_filter = {}
        for _filter in filter_str:
            if _filter.GetType() == 'assessment':
                cond_stmt = "(" + str(_filter.GetName()) + str(_filter.GetOperator()) + ")"
                if _filter.GetName() in tmp_filter:
                    tmp_filter[_filter.GetName()].append(cond_stmt)
                else:
                    tmp_filter[_filter.GetName()] = []
                    tmp_filter[_filter.GetName()].append(cond_stmt)

        for _filter in tmp_filter:
            cond_or = []
            for ix in xrange(len(tmp_filter[_filter])):
                if ix == 0:
                    cond_or = str(tmp_filter[_filter][ix])
                else:
                    cond_or = SQLBinaryExpr(cond_or, OP_OR, str(tmp_filter[_filter][ix]))

            cond = SQLBinaryExpr(cond, OP_AND, cond_or)

        if isinstance(predef_filter_str, SQLBinaryExpr):
            cond = SQLBinaryExpr(cond, OP_AND, predef_filter_str)

        entries = self.SelectGenericData(distinct_rows=True, select_list=columns,
                                         table_list=tables, where=cond, order_by=orderby)
        elapsed_time = time() - start_time
        return elapsed_time, entries

    def GetEventsInfoForExportToCsv(self, trid):
        """Get the events information for the export to CSV from the VAL_VIEW_EVENTS_ATRIBUTES.
        :param seids: the list of event ids
        :return: events_infos : the list of the selected informations
        """
        columns = ["Q1." + COL_NAME_EVENTS_VIEW_SEID,
                   "Q1." + COL_NAME_EVENTS_VIEW_BEGINABSTS,
                   "Q1." + COL_NAME_EVENTS_VIEW_ENDABSTS,
                   "Q1." + COL_NAME_EVENTS_VIEW_FILE_NAME,
                   "Q1." + COL_NAME_EVENTS_VIEW_NAME,
                   "Q1." + COL_NAME_EVENTS_VIEW_VALUE]

        orderby = ["Q1." + COL_NAME_EVENTS_VIEW_SEID]

        tables = []
        attr_list = "('distx','disty','vrelx','rectobjid')"
        sel_stmt = self.GetQualifiedTableName(TABLE_NAME_EVENTS_ATTRIBUTES_VIEW) + " Q1" + \
            " INNER JOIN ( SELECT * FROM " + self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS) + \
            " evd INNER JOIN " + self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR) + " ea ON  ea.EDID = evd.EDID " + \
            " INNER JOIN " + self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR_TYPES) + \
            " eat ON ea.ATTRTYPEID = eat.ATTRTYPEID  AND eat.NAME IN " + attr_list + ") Q2 ON Q1.SEID = Q2.SEID "

        cond = " TRID = " + str(trid) + " AND Q1.NAME IN " + attr_list

        tables.append(sel_stmt)
        entries = self.SelectGenericData(distinct_rows=True, select_list=columns, table_list=tables,
                                         where=cond, order_by=orderby)
        return entries

    # --- EVENTDETAILS Table ---------------------------------------------
    def AddEventDetails(self, seid, absts):
        """
        Add detail entry to the event
        :param seid: Event Id
        :type seid: int
        :param absts: Absolute Timestamp
        :type absts: int
        :return: edid: Event Detail Id
        :type: edid: int
        """

        if seid is None or absts is None:
            raise AdasDBError("Seid or absts are not integers.")

        edid = self.GetEventDetailsId(seid=seid, absts=absts)
        if edid is None:
            details = {}
            details[COL_NAME_EVENT_DET_ABSTS] = absts
            details[COL_NAME_EVENTS_SEID] = seid
            self.AddGenericData(details, self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS))

            cond = self.__GetEventDetailsCondition(seid=seid, absts=absts)
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS)],
                                             where=cond)

            if len(entries) == 1:
                edid = entries[0][COL_NAME_EVENT_DET_EDID]
            else:
                tmp = "Timestamp '%s' " % (details[COL_NAME_EVENT_DET_ABSTS])
                tmp += "for '%s' Event cannot be added." % (details[COL_NAME_EVENTS_SEID])
                raise AdasDBError(tmp)

        # done
        return int(edid)

    def GetEventDetails(self, edid=None, seid=None, absts=None):
        """
        Get Event detail data
        :param edid: Event Detail ID --> Mandatory parameter
        :type edid: int
        :param seid: Event id  --> Mandatory parameter
        :type seid: int
        :param absts: Abolute Timestamp  --> Mandatory parameter
        :type absts: int
        :return record: Record of Event Detail
        :type record: list of dict
        """

        if (edid is None) and (seid is None) and (absts is None):
            raise AdasDBError("Seid, absts, edid not defined")

        records = []
        cond = self.__GetEventDetailsCondition(edid, seid, absts)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS)], where=cond)

        if len(entries) >= 1:
            records = entries

        return records

    def GetEventDetailsId(self, edid=None, seid=None, absts=None):
        """
        Get Event Detail id i.e. edid
        :param edid: Event Detail Id
        :type edid: int
        :param seid: Event Id
        :type seid: int
        :param absts: Absolute Time stamp
        :type absts: int
        :return edid: list of all detail Ids
        : type edid: list
        """
        entries = self.GetEventDetails(edid=edid, seid=seid, absts=absts)

        if len(entries) == 1:
            edid = entries[0][COL_NAME_EVENT_DET_EDID]
        elif len(entries) > 1:
            edid = []
            for item in entries:
                edid.append(item[COL_NAME_EVENT_DET_EDID])
        else:
            edid = None

        return edid

    def GetEventDetailsTimestamps(self, seid=None, globs=False):
        """
        Get Timestamps list of event details
        :param seid: Event Id
        :type seid: int
        :param globs: Flag for Global Attribute
        :type globs: boolean
        :return timestamps: list of all timestamp
        :type timestamps: list
        """
        if seid is None:
            raise AdasDBError("Seid not defined")
        if globs:
            absts = -1
        else:
            absts = None

        entries = self.GetEventDetails(seid=seid, absts=absts)
        if len(entries) == 1:
            timestamps = entries[0][COL_NAME_EVENT_DET_ABSTS]
        elif len(entries) > 1:
            timestamps = []
            for item in entries:
                if not globs and item[COL_NAME_EVENT_DET_ABSTS] != -1:
                    timestamps.append(item[COL_NAME_EVENT_DET_ABSTS])
        else:
            timestamps = []

        # done
        return timestamps

    def GetEventDetailsAttributes(self, seid, timestamps=None, attribute_name=None):
        """
        Get Attribute Data for an Event
        :param seid: Event id
        :type seid: int
        :param timestamps: Absolute Timestamp
        :type timestamps: int
        :param attribute_name: attribute name
        :type attribute_name: string
        :return entries: Record contain Attribute name, value and timestamps
        :type entries: list of dict
        """
        columns = [COL_NAME_EVENT_DET_ABSTS, COL_NAME_EVENT_ATTR_TYPES_NAME, COL_NAME_EVENT_ATTR_VALUE]

        tables = []

        cond = self.__GetEventDetailsCondition(seid=seid, absts=timestamps)

        if attribute_name is not None:
            cond_attr = SQLBinaryExpr(COL_NAME_EVENT_ATTR_TYPES_NAME, OP_EQ, SQLLiteral(attribute_name))
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_attr)

        tblDetails = self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS)
        tblEventAttr = self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR)
        tblEventDet = self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS)
        tblAttrTypes = self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR_TYPES)

        ValEventAttrJoin = SQLJoinExpr(SQLTableExpr(tblDetails),
                                       OP_INNER_JOIN,
                                       SQLTableExpr(tblEventAttr),
                                       SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblEventDet),
                                                                   COL_NAME_EVENT_DET_EDID),
                                                     OP_EQ,
                                                     SQLColumnExpr(SQLTableExpr(tblEventAttr),
                                                                   COL_NAME_EVENT_DET_EDID)))

        tables.append(SQLJoinExpr(SQLTableExpr(ValEventAttrJoin),
                                  OP_INNER_JOIN,
                                  SQLTableExpr(tblAttrTypes),
                                  SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblEventAttr),
                                                              COL_NAME_EVENT_ATTR_ATTRTYPEID),
                                                OP_EQ,
                                                SQLColumnExpr(SQLTableExpr(tblAttrTypes),
                                                              COL_NAME_EVENT_ATTR_TYPES_ATTRTYPEID))))

        orderby = [COL_NAME_EVENT_DET_ABSTS, COL_NAME_EVENT_ATTR_TYPES_NAME]
        entries = self.SelectGenericData(select_list=columns, table_list=tables, where=cond, order_by=orderby)
        return entries

    def DeleteEventDetails(self, seid):
        """Delete all event details and the attributes assigned to this event details
        :param edid: event details id
        """
        rowcount = 0

        try:
            seid = int(seid)
        except:
            raise AdasDBError("Seid is not a integer.")

        cond = self.__GetEventDetailsCondition(seid=seid)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS)], where=cond)

#        if self.error_tolerance < ERROR_TOLERANCE_LOW:
#            if len(entries) == 0:
#                raise AdasDBError("No record found for SEID: %s." % seid)

        # loop over all details assigned to the event seid
        for entry in entries:
            edid = entry[COL_NAME_EVENT_DET_EDID]
            self.DeleteEventAttributes(edid)
            cond = self.__GetEventDetailsCondition(seid=seid, edid=edid)
            self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS), where=cond)
            rowcount += 1
        # done
        return rowcount

    def __GetEventDetailsCondition(self, edid=None, seid=None, absts=None):  # pylint: disable=R0201
        """ Get Event Details Condition selection statement
        :param attrid: Attribute Identifier
        :param attrtypeid: Attribute Type Identifier
        :param edid: Event Description Identifier
        :param seid: SEID
        :param absts: Absolute Timestamp
        :return: Selection Statement
        """
        cond = None

        if edid is not None:
            cond = SQLBinaryExpr(COL_NAME_EVENT_DET_EDID, OP_EQ, edid)
        else:
            if seid is not None:
                cond_seid = SQLBinaryExpr(COL_NAME_EVENTS_SEID, OP_EQ, seid)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_seid)
                else:
                    cond = cond_seid

            if absts is not None:
                cond_rel = SQLBinaryExpr(COL_NAME_EVENT_DET_ABSTS, OP_EQ, SQLLiteral(absts))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_rel)
                else:
                    cond = cond_rel

        return cond

    # --- EVENTATTR Table ---------------------------------------------
    def AddEventAttribute(self, attribute, getattrid=False):
        """
        Add Attribute Data
        :param attribute: attribute Record
        :type attribute: dict
        :param getattrid: flag to return attribute id for newly insert data
        :type getattrid: int
        :return attrid: Attribute Id
        :type attrid: if getattrid is false return type is None if getattrid is true return type is int

        """
        attrid = None

        if((COL_NAME_EVENT_ATTR_ATTRTYPEID not in attribute) or
           (COL_NAME_EVENT_ATTR_EDID not in attribute) or
           (COL_NAME_EVENT_ATTR_VALUE not in attribute)):
            raise AdasDBError("AddEventAttribute: attribute not completly setted.")

        self.AddGenericData(attribute, self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR))

        if getattrid is True:
            entries = self.GetEventAttribute(edid=attribute[COL_NAME_EVENT_DET_EDID],
                                             value=attribute[COL_NAME_EVENT_ATTR_VALUE],
                                             attrtypeid=attribute[COL_NAME_EVENT_ATTR_ATTRTYPEID])

            if len(entries) == 1:
                attrid = entries[0][COL_NAME_EVENT_ATTR_ATTRID]
            elif len(entries) <= 0:
                raise AdasDBError("Event attribute cannot be added.")
            elif len(entries) > 1:
                logging.warn("Event attribute cannot be resolved because it is ambiguous.")

        return attrid

    def GetEventAttribute(self, attrid=None, edid=None, attrtypeid=None, value=None, attrname=None):
        """
        Get Event Attribute Data based on criteria depending on the passed parameter
        :param attrid: attibute ID
        :type attrid: int
        :param edid: event detail id
        :type edid: int
        :param attrtypeid: attribute type id
        :type attrtypeid: int
        :param value: attribute value
        :type value: float
        :param attrname: attribute name
        :type attrname: string
        :return entries: records contain attribute data
        :type entries: list of dictionary
        """

        if attrname is not None:
            attrtypeid = self.GetEventAttributeTypeId(attrname.lower())

        cond = self.__GetEventAttributeCondition(attrid, attrtypeid, edid, value)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR)], where=cond)

        # done
        return entries

    def GetEventAttributeId(self, attribute_name=None, attrid=None, edid=None, attrtypeid=None, value=None):
        """
        Get Attribute Id with criteria based on parameter passed
        :param attribute_name: name of attribute
        :type attribute_name: string
        :param attrid: attribute id
        :type attrid: int
        :param edid: event detail id
        :type edid: int
        :param attrtypeid: attribute type id
        :type attrtypeid: int
        :param value: attribtue value
        :type value: float
        :return attribute_id: attribute id
        :type attribute_id: int
        """

        attribute_id = None
        entries = self.GetEventAttribute(attrid=attrid, edid=edid,
                                         attrtypeid=attrtypeid, value=value,
                                         attrname=attribute_name)

        if len(entries) == 1:
            attribute_id = entries[0][COL_NAME_EVENT_ATTR_ATTRID]
        return attribute_id

    def DeleteEventAttributes(self, edid):
        """Delete all the attributes with the event details id
        :param edid: event details id
        """
        rowcount = 0

        cond = self.__GetEventAttributeCondition(edid=edid)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR)], where=cond)
        for entry in entries:
            attrid = entry[COL_NAME_EVENT_ATTR_ATTRID]
            rowcount += self.DeleteEventImage(attrid=attrid)
            cond = self.__GetEventAttributeCondition(attrid=attrid)
            rowcount += self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR), where=cond)
        # done
        return rowcount

    def UpdateEventAttribute(self, attrid, value):
        """
        Update Value of an attribute
        :param attrid: attribute  id
        :type attrid: int
        :param value: attribute value
        :type value: flaot
        """
        attribute = {}
        attribute[COL_NAME_EVENT_ATTR_VALUE] = value

        where = self.__GetEventAttributeCondition(attrid=attrid)

        rowcount = self.UpdateGenericData(attribute, self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR), where)
        self.Commit()

        return rowcount

    def __GetEventAttributeCondition(self, attrid=None, attrtypeid=None, edid=None, value=None):
        """ Get Event Arrtibute Condition selection statement
        :param attrid: Attribute Identifier
        :param attrtypeid: Attribute Type Identifier
        :param edid: Event Description Identifier
        :param value: Event Attribute Value
        :return: Selection Statement
        """
        # pylint: disable=R0201
        cond = None

        if attrid is not None:
            cond = SQLBinaryExpr(COL_NAME_EVENT_ATTR_ATTRID, OP_EQ, attrid)
        else:
            if attrtypeid is not None:
                cond_e = SQLBinaryExpr(COL_NAME_EVENT_ATTR_TYPES_ATTRTYPEID, OP_EQ, attrtypeid)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_e)
                else:
                    cond = cond_e

            if edid is not None:
                cond_e = SQLBinaryExpr(COL_NAME_EVENT_DET_EDID, OP_EQ, edid)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_e)
                else:
                    cond = cond_e
            if value is not None:
                cond_v = SQLBinaryExpr(COL_NAME_EVENT_ATTR_VALUE, OP_EQ, SQLLiteral(value))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_v)
                else:
                    cond = cond_v

        # done
        return cond

    # --- EVENTATTRTYPES Table ---------------------------------------------
    def AddEventAttributeType(self, attribute_type):
        """
        Add new Attribute Type
        :param attribute_type: dictionary of a reocrd to be insert
        :type attribute_type: dict
        :return atrttype_id: attribute type id
        :type atrttype_id: int
        """
        try:
            attribute_type[COL_NAME_EVENT_ATTR_TYPES_NAME] = attribute_type[COL_NAME_EVENT_ATTR_TYPES_NAME].lower()
            attribute_type_name = attribute_type[COL_NAME_EVENT_ATTR_TYPES_NAME]
        except:
            raise AdasDBError("AddEventAttributeType: Is not a dictionary")

        atrttype_id = self.GetEventAttributeTypeId(attribute_type_name)

        if atrttype_id is None:
            self.AddGenericData(attribute_type, self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR_TYPES))
            entries = self.GetEventAttributeType(attribute_type_name)
            if len(entries) == 1:
                atrttype_id = entries[0][COL_NAME_EVENT_ATTR_TYPES_ATTRTYPEID]
            elif len(entries) > 1:
                raise AdasDBError("Attribute Type is ambiguous in the database. (%s)" % attribute_type_name)
            else:
                raise AdasDBError("Event attribute type name '%s' cannot be added. " % (attribute_type_name))

        return atrttype_id

    def GetEventAttributeType(self, name=None):
        """
        Get Attribute Type record for Given attribute Name
        :param name: attribute name
        :tyep name: string
        :return entries: record containing attribute type data. list contain only one element
        :type entries: list
        """

        if name is not None and not isinstance(name, str):
            raise AdasDBError("GetEventAttributeType: name is not a string.")

        cond = self.__GetEventAttributeTypeCondition(name)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR_TYPES)],
                                         where=cond)

        if len(entries) <= 0:
            logging.warn(str("Event attribute '%s' does not exist in the validation database." % name))

        return entries

    def GetEventAttributeTypeId(self, name):
        """
        Get Attribute Id for a given Name
        :param name: attribute name
        :type name: string
        :return attrtype_id: Attribute type id
        :type attrtype_id: int
        """
        attrtype_id = None
        entries = self.GetEventAttributeType(name)

        if len(entries) == 1:
            attrtype = entries[0]
            attrtype_id = attrtype[COL_NAME_EVENT_ATTR_TYPES_ATTRTYPEID]
        elif len(entries) > 1:
            raise AdasDBError("Attribute Type is ambiguous in the database. (%s)" % name)

        return attrtype_id

    def GetEventAttributeTypeIdsForParent(self, parent_id):
        id_list = []
        try:
            parent_id = int(parent_id)
        except:
            raise AdasDBError("Parent id is not an integer.")

        cond = self.__GetEventAttributeTypeCondition(parent=parent_id)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR_TYPES)],
                                         where=cond)

        for types in entries:
            id_list.append(types[COL_NAME_EVENT_ATTR_TYPES_ATTRTYPEID])

        return id_list

    def __GetEventAttributeTypeCondition(self, name=None, parent=None):
        cond = None
        if name is not None:
            cond = SQLBinaryExpr(COL_NAME_EVENT_ATTR_TYPES_NAME, OP_EQ, SQLLiteral(name.lower()))

        if parent is not None:
            cond_p = SQLBinaryExpr(COL_NAME_EVENT_ATTR_TYPES_PARENT, OP_EQ, parent)
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_p)
            else:
                cond = cond_p

        # done
        return cond

    # --- EVENTIMAGE Table ---------------------------------------------
    def AddEventImage(self, event_img):
        """Add a new image to the database.
        :param res_img: The result assessment - resid is mandatory as it is the primary key
        :return: Returns the number of affected rows.
        """
        # event_image = {}

        if not isinstance(event_img[COL_NAME_EVENT_IMG_IMAGE], buffer):
            raise AdasDBError('AddEventImage: Image ist not a buffer!')

        rowcount = 0
        cond = self.__GetEventImageCondition(event_img[COL_NAME_EVENT_IMG_ATTRID])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_IMAGE)], where=cond)
        if len(entries) <= 0:
            stmt = 'INSERT INTO ' + str(self.GetQualifiedTableName(TABLE_NAME_EVENT_IMAGE))
            stmt += " (%s," % (COL_NAME_EVENT_IMG_ATTRID)
            stmt += "%s," % (COL_NAME_EVENT_IMG_TITLE)
            stmt += "%s," % (COL_NAME_EVENT_IMG_FORMAT)
            stmt += "%s)" % (COL_NAME_EVENT_IMG_IMAGE)
            stmt += " VALUES('%s'," % (event_img[COL_NAME_EVENT_IMG_ATTRID])
            stmt += "'%s'," % (event_img[COL_NAME_EVENT_IMG_TITLE])
            stmt += "'%s', :1)" % (event_img[COL_NAME_EVENT_IMG_FORMAT])
            cursor = self.db_connection.cursor()
            try:
                logging.debug(stmt)
                cursor.execute(stmt, (event_img[COL_NAME_EVENT_IMG_IMAGE],))
                rowcount = cursor.rowcount
            except:
                logging.error(stmt)
                raise
            finally:
                cursor.close()

        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Image for Attrid ID '%s' " % event_img[COL_NAME_EVENT_IMG_ATTRID]
                tmp += "exists already in the validation result database"
                raise AdasDBError(tmp)
            else:
                tmp = "Image for Result ID '%s' " % event_img[COL_NAME_EVENT_IMG_ATTRID]
                tmp += "exists already in the validation result database"
                logging.warn(tmp)
                if len(entries) == 1:
                    # id = entries[0][COL_NAME_EVENT_IMG_ATTRID]
                    pass
                elif len(entries) > 1:
                    raise AdasDBError("Image for result ID cannot be found because it is ambiguous. (%s)" % entries)
        # done
        return rowcount

    def GetEventImage(self, attrid):
        """Get existing event image.
        :param attrid: attribute ID
        :return: Record if exist
        """
        record = {}
        cond = self.__GetEventImageCondition(attrid)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENT_IMAGE)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Image for Result ID '%s' does not exist in the validation result database." % attrid))
        elif len(entries) > 1:
            logging.warn(str("Image for Result '%s' cannot be found because it is ambiguous. (%s)" %
                             (attrid, entries)))
        else:
            record = entries[0]
        # done
        return record

    def UpdateEventImage(self):
        pass

    def DeleteEventImage(self, attrid):
        """Delete existing event image records.
        :param res_img: The event image record to delete.
        :return: Returns the number of affected assessments.
        """
        if attrid is not None:
            cond = self.__GetEventImageCondition(attrid)

        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_EVENT_IMAGE), where=cond)
        # done
        return rowcount

    def __GetEventImageCondition(self, attrid):  # pylint: disable=R0201
        """Get the condition expression to access the event image
        :param res_id: attrid
        :return: Returns the condition expression
        """
        return SQLBinaryExpr(COL_NAME_EVENT_IMG_ATTRID, OP_EQ, SQLLiteral(attrid))

    def GetEventImagePlotSeq(self, seid, attr_type, plot=False):  # pylint: disable=W0613
# SELECT IMAGE
# FROM VAL_EventDetails
# INNER JOIN VAL_EventAttr ON (VAL_EventDetails.EDID = VAL_EventAttr.EDID)
# INNER JOIN VAL_EventAttrTypes ON (VAL_EventAttr.ATTRTYPEID = VAL_EventAttrTypes.ATTRTYPEID)
# LEFT JOIN VAL_EVENTIMAGE ON (VAL_EVENTIMAGE.ATTRID = VAL_EventAttr.ATTRID)
# WHERE (SEID = 4430) AND (NAME = 'video_seq_file') AND (ABSTS = '-1') ORDER BY ABSTS

        columns = [COL_NAME_EVENT_IMG_IMAGE]
        # columns = ["*"]

        tables = []

        cond = SQLBinaryExpr(COL_NAME_EVENT_DET_SEID, OP_EQ, seid)

        cond_att = SQLBinaryExpr(COL_NAME_EVENT_ATTR_TYPES_NAME, OP_EQ, SQLLiteral(attr_type))

        cond = SQLBinaryExpr(cond, OP_AND, cond_att)
        cond_absts = SQLBinaryExpr(COL_NAME_EVENT_DET_ABSTS, OP_EQ, -1)
        cond = SQLBinaryExpr(cond, OP_AND, cond_absts)

        tblEventDet = self.GetQualifiedTableName(TABLE_NAME_EVENT_DETAILS)
        tblEventAttr = self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR)
        tblAttrTypes = self.GetQualifiedTableName(TABLE_NAME_EVENT_ATTR_TYPES)
        tblImg = self.GetQualifiedTableName(TABLE_NAME_EVENT_IMAGE)

        join = SQLJoinExpr(SQLTableExpr(tblEventDet),
                           OP_INNER_JOIN,
                           SQLTableExpr(tblEventAttr),
                           SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblEventDet),
                                                       COL_NAME_EVENT_DET_EDID),
                                         OP_EQ,
                                         SQLColumnExpr(SQLTableExpr(tblEventAttr),
                                                       COL_NAME_EVENT_ATTR_EDID)))

        join_1 = SQLJoinExpr(SQLTableExpr(join),
                             OP_INNER_JOIN,
                             SQLTableExpr(tblAttrTypes),
                             SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblEventAttr),
                                                         COL_NAME_EVENT_ATTR_ATTRTYPEID),
                                           OP_EQ,
                                           SQLColumnExpr(SQLTableExpr(tblAttrTypes),
                                                         COL_NAME_EVENT_ATTR_TYPES_ATTRTYPEID)))

        join_2 = SQLJoinExpr(SQLTableExpr(join_1),
                             OP_LEFT_OUTER_JOIN,
                             SQLTableExpr(tblImg),
                             SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblImg),
                                                         COL_NAME_EVENT_IMG_ATTRID),
                                           OP_EQ,
                                           SQLColumnExpr(SQLTableExpr(tblEventAttr),
                                                         COL_NAME_EVENT_ATTR_ATTRID)))

        tables.append(join_2)

        # orderby = [COL_NAME_EVENT_DET_absts]
        # entries = self.SelectGenericData(select_list=columns, table_list=tables,
        #                                 where=cond, order_by=orderby,
        #                                 how_many = how_many)
        entries = self.SelectGenericData(select_list=columns, table_list=tables, where=cond)

        return entries

    # --- EVENTS Table ----------------------------------------------------
    def AddEvent(self, event, replace=False):    # pylint: disable=R0912, R0915
        """Add a new sim event to the database.
        :param event: The testrun dictionary
        :return: Returns the event ID.
        """
        seid = None
        try:
            cond = self.__GetEventCondition(event_type_id=event[COL_NAME_EVENTS_EVENTTYPEID],
                                            trid=event[COL_NAME_EVENTS_TRID],
                                            measid=event[COL_NAME_EVENTS_MEASID],
                                            beginabsts=event[COL_NAME_EVENTS_BEGINABSTS],
                                            endabsts=event[COL_NAME_EVENTS_ENDABSTS],
                                            start_idx=event[COL_NAME_EVENTS_START_IDX],
                                            stop_idx=event[COL_NAME_EVENTS_STOP_IDX])
        except Exception, ex:
            raise AdasDBError("Couldn't generate EventCondition. %s" % str(ex))

        if event[COL_NAME_EVENTS_BEGINABSTS] > event[COL_NAME_EVENTS_ENDABSTS]:
            tmp = "'%s' Event cannot be added, " % (event[COL_NAME_EVENTS_EVENTTYPEID])
            tmp += "start timestamp '%s' " % (event[COL_NAME_EVENTS_BEGINABSTS])
            tmp += "is greater than stop timestamp '%s'" % (event[COL_NAME_EVENTS_ENDABSTS])
            raise AdasDBError(tmp)

        if event[COL_NAME_EVENTS_START_IDX] > event[COL_NAME_EVENTS_STOP_IDX]:
            tmp = "'%s' Event cannot be added, " % (event[COL_NAME_EVENTS_EVENTTYPEID])
            tmp += "start index '%s' is greater " % (event[COL_NAME_EVENTS_START_IDX])
            tmp += "than stop index '%s'" % (event[COL_NAME_EVENTS_STOP_IDX])
            raise AdasDBError(tmp)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS)], where=cond)
        if len(entries) == 1 and replace is True:
            seid = entries[0][COL_NAME_EVENTS_SEID]
            if self.DeleteEvent(seid=seid) is not None:
                self.Commit()
                tmp = "Event from timestamp '%s' " % (event[COL_NAME_EVENTS_BEGINABSTS])
                tmp += "to timestamp '%s' deleted." % (event[COL_NAME_EVENTS_ENDABSTS])
                logging.debug(tmp)
                self.AddGenericData(event, self.GetQualifiedTableName(TABLE_NAME_EVENTS))
                entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS)],
                                                 where=cond)
                if len(entries) == 1:
                    seid = entries[0][COL_NAME_EVENTS_SEID]
                else:
                    tmp = "Event from timestamp '%s' " % (event[COL_NAME_EVENTS_BEGINABSTS])
                    tmp += "to timestamp '%s' cannot be added." % (event[COL_NAME_EVENTS_ENDABSTS])
                    raise AdasDBError(tmp)
            else:
                return seid
        elif len(entries) <= 0:
            self.AddGenericData(event, self.GetQualifiedTableName(TABLE_NAME_EVENTS))
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS)], where=cond)

            if len(entries) == 1:
                seid = entries[0][COL_NAME_EVENTS_SEID]
            else:
                tmp = "'%s' Event from " % (event[COL_NAME_EVENTS_EVENTTYPEID])
                tmp += "'%s' to " % (event[COL_NAME_EVENTS_BEGINABSTS])
                tmp += "'%s' cannot be added." % (event[COL_NAME_EVENTS_ENDABSTS])
                raise AdasDBError(tmp)
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("Event exists already in the validation result database")
            else:
                logging.warn("Event already exists in the validation result database.")
                if len(entries) == 1:
                    seid = entries[0][COL_NAME_EVENTS_SEID]
                elif len(entries) > 1:
                    tmp = "Event from '%s' " % (event[COL_NAME_EVENTS_BEGINABSTS])
                    tmp += "to '%s' " % (event[COL_NAME_EVENTS_BEGINABSTS])
                    tmp += "cannot be resolved because it is ambiguous."
                    raise AdasDBError(tmp)

        return seid

    def GetMeasidForSeid(self, seid):

        columns = [COL_NAME_EVENTS_VIEW_MEASID]
        cond = self.__GetEventCondition(table_name=TABLE_NAME_EVENTS_VIEW, seid=seid)
        entries = self.SelectGenericData(select_list=columns,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS_VIEW)], where=cond)
        return entries[0][COL_NAME_EVENTS_VIEW_MEASID]

    def GetEventsAttributesView(self, seid=None, trid=None, measid=None,
                                beginabsts=None, endabsts=None, start_idx=None,
                                stop_idx=None, assessment=None, eventtype=None, rdid=None, cond=None):
        entries = []
        if cond is None:
            cond = self.__GetEventCondition(table_name=TABLE_NAME_EVENTS_VIEW,
                                            seid=seid, trid=trid, measid=measid,
                                            beginabsts=beginabsts, endabsts=endabsts,
                                            start_idx=start_idx, stop_idx=stop_idx,
                                            assessment=assessment, eventtype=eventtype, rdid=rdid)

        if cond is not None:
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(
                                                         TABLE_NAME_EVENTS_ATTRIBUTES_VIEW)], where=cond)

        # done
        return entries

    def GetEventTypesView(self, trid=None):
        entries = []
        cond = self.__GetEventCondition(table_name=TABLE_NAME_EVENTS_VIEW, trid=trid)

        columns = [COL_NAME_EVENTS_VIEW_EVENTTYPE]
        if cond is not None:
            entries = self.SelectGenericData(distinct_rows=True,
                                             select_list=columns,
                                             table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS_VIEW)],
                                             where=cond)
        # done
        return entries

    def GetEventsView(self, seid=None, trid=None, measid=None, beginabsts=None,
                      endabsts=None, start_idx=None, stop_idx=None,
                      assessment=None, eventtype=None, rdid=None, cond=None):
        # pylint: disable=R0913
        entries = []
        if cond is None:
            cond = self.__GetEventCondition(table_name=TABLE_NAME_EVENTS_VIEW,
                                            seid=seid, trid=trid, measid=measid,
                                            beginabsts=beginabsts, endabsts=endabsts,
                                            start_idx=start_idx, stop_idx=stop_idx,
                                            assessment=assessment,
                                            eventtype=eventtype, rdid=rdid)

        if cond is not None:
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS_VIEW)],
                                             where=cond)

        # done
        return entries

    def GetEvents(self, seid=None, trid=None, event_type_id=None, measid=None,
                  beginabsts=None, endabsts=None, start_idx=None, stop_idx=None,
                  resass_id=None):
        """ Get Event from Val_Events Table
        :param seid:
        :param trid:
        :param event_type-id:
        :param measid:
        :param beginabsts:
        :param endabsts:
        :param start_idx:
        :param stop_idx
        :param resass_id:
        :return: Returns the Event record
        """
        # pylint: disable=R0913
        entries = []
        cond = self.__GetEventCondition(seid=seid, trid=trid,
                                        event_type_id=event_type_id, measid=measid,
                                        beginabsts=beginabsts, endabsts=endabsts,
                                        start_idx=start_idx, stop_idx=stop_idx,
                                        resass_id=resass_id)

        if cond is not None:
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTS)], where=cond)

        # done
        return entries

    def UpdateEvent(self, event, where=None):
        """Update existing event records.
        :param event: The event record update.
        :param where:
        :return: Returns the number of affected result descriptors.
        """
        rowcount = None

        if not isinstance(event, dict):
            raise AdasDBError("UpdateEvent: event is not a dictionary!")

        if where is None:
            try:
                where = self.__GetEventCondition(seid=event[COL_NAME_EVENTS_SEID])
            except KeyError, ex:
                raise AdasDBError("Couldn't generate EventCondition. %s" % str(ex))

        if (event is not None) and (len(event) != 0):
            rowcount = self.UpdateGenericData(event, self.GetQualifiedTableName(TABLE_NAME_EVENTS), where)
        # done
        return rowcount

    def DeleteEvent(self, seid):
        """Delete existing event record.
        :param seid: The event record update.
        :return: Returns the number of affected result descriptors.
        """
        try:
            seid = int(seid)
        except:
            raise AdasDBError("Seid is not an Integer")

        rowcount = 0
        # Delete the event details container
        try:
            rowcount += self.DeleteEventDetails(seid)
            # Delete the event
            cond = self.__GetEventCondition(seid=seid)
            self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_EVENTS), where=cond)
            rowcount += 1
        except:
            raise AdasDBError("Event with seid '%i' cannot be deleted." % seid)

        return rowcount

    def __GetEventCondition(self, table_name=None, seid=None, trid=None,
                            event_type_id=None, measid=None, beginabsts=None,
                            endabsts=None, start_idx=None, stop_idx=None,
                            resass_id=None, assessment=None, eventtype=None, rdid=None):
        """Get the condition expression to access the simeevnt.
        :param seid:
        :param trid:
        :param event_type_id:
        :param measid:
        :param beginabsts:
        :param endabsts:
        :param start_idx:
        :param stop_idx:
        :param resass_id:
        :return: Returns the condition expression
        """
        # pylint: disable=R0912, R0913, R0914, R0915
        cond = None

        if table_name is None:
            table_name = TABLE_NAME_EVENTS

        if seid is not None:
            cond = SQLBinaryExpr(COL_NAME_EVENTS_SEID, OP_EQ, seid)
        else:
            if trid is not None:
                cond_tr = SQLBinaryExpr(COL_NAME_EVENTS_TRID, OP_EQ, trid)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_tr)
                else:
                    cond = cond_tr

            if event_type_id is not None:
                cond_ev = SQLBinaryExpr(COL_NAME_EVENTS_EVENTTYPEID, OP_EQ, event_type_id)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_ev)
                else:
                    cond = cond_ev

            if beginabsts is not None:
                cond_b = SQLBinaryExpr(COL_NAME_EVENTS_BEGINABSTS, OP_EQ, beginabsts)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_b)
                else:
                    cond = cond_b

            if endabsts is not None:
                cond_e = SQLBinaryExpr(COL_NAME_EVENTS_ENDABSTS, OP_EQ, endabsts)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_e)
                else:
                    cond = cond_e

            if measid is not None:
                cond_m = SQLBinaryExpr(COL_NAME_EVENTS_MEASID, OP_EQ, measid)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_m)
                else:
                    cond = cond_m

            if start_idx is not None:
                cond_si = SQLBinaryExpr(COL_NAME_EVENTS_START_IDX, OP_EQ, start_idx)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_si)
                else:
                    cond = cond_si

            if stop_idx is not None:
                cond_sp = SQLBinaryExpr(COL_NAME_EVENTS_STOP_IDX, OP_EQ, stop_idx)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_sp)
                else:
                    cond = cond_sp

            if resass_id is not None:
                cond_r = SQLBinaryExpr(COL_NAME_EVENTS_RESASSID, OP_EQ, resass_id)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_r)
                else:
                    cond = cond_r

            if assessment is not None:
                cond_ass = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                     COL_NAME_EVENTS_VIEW_ASSESSMENT),
                                         OP_EQ, SQLLiteral(assessment.lower()))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_ass)
                else:
                    cond = cond_ass

            if eventtype is not None:
                cond_evt = SQLBinaryExpr(COL_NAME_EVENTS_VIEW_EVENTTYPE, OP_EQ, SQLLiteral(eventtype))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_evt)
                else:
                    cond = cond_evt

            if rdid is not None:
                cond_rd = SQLBinaryExpr(COL_NAME_EVENTS_VIEW_RDID, OP_EQ, rdid)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_rd)
                else:
                    cond = cond_rd
        return cond

    # --- EVENTTYPE Table. --------------------------------------------------
    def AddEventType(self, event_type):
        """Add a new event type to the database.
        :param event_type: The event type dictionary
        :return: Returns the event type ID.
        """
        try:
            cond = self.__GetEventTypeCondition(None, event_type[COL_NAME_EVENTTYPE_CLASSNAME])
        except StandardError, ex:
            raise AdasDBError("Can't create eventtype condition. Error: '%s'" % (ex))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTTYPE)], where=cond)
        if len(entries) <= 0:
            if COL_NAME_EVENTTYPE_NAME not in event_type:
                event_type[COL_NAME_EVENTTYPE_NAME] = 'auto generated name'

            if COL_NAME_EVENTTYPE_DESC not in event_type:
                event_type[COL_NAME_EVENTTYPE_DESC] = 'auto generated description'

            self.AddGenericData(event_type, self.GetQualifiedTableName(TABLE_NAME_EVENTTYPE))
            etid = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTTYPE)],
                                          where=cond)[0][COL_NAME_EVENTTYPE_ID]
        else:
            tmp = "Event type '%s' " % event_type[COL_NAME_EVENTTYPE_NAME]
            tmp += "exists already in the validation database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    etid = entries[0][COL_NAME_EVENTTYPE_ID]
                elif len(entries) > 1:
                    tmp = "Event type name '%s' " % (event_type[COL_NAME_TR_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return int(etid)

    def GetEventType(self, event_type_id=None, name=None, class_name=None):
        """Get existing event type records.
        :param name: - The event type name.
        :param class_name: The event Class Name
        :return: Returns the event type record.
        """
        record = {}
        try:
            if event_type_id is not None:
                event_type_id = int(event_type_id)
        except:
            raise AdasDBError("Eventtype ID is not an integer.")

        if class_name is None and event_type_id is None:
            raise AdasDBError("Classname and eventtype id are None of event_type_id is not an integer.")

        # if event_type_id is None:
            # if not isinstance(event_type_id, (int, float, long)):
        #    raise AdasDBError("event_type_id is not an integer.")

        cond = self.__GetEventTypeCondition(event_type_id, class_name, name)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EVENTTYPE)], where=cond)
        if len(entries) <= 0:
            logging.info(str("Event type '%s' does not exist in the validation result database." % name))
        elif len(entries) > 1:
            logging.warn(str("Event type '%s' cannot be resolved because it is ambiguous. (%s)" % (name, entries)))
        else:
            record = entries[0]
        # done
        return record

    def GetEventTypeId(self, class_name=None, name=None):
        """ Get the EventType ID
        :param name: Event Type Name
        :param class_name: The event Class Name
        :return: Returns the Event Type IDcondition expression
        """
        eventtype = self.GetEventType(class_name=class_name, name=name)
        if COL_NAME_EVENTTYPE_ID in eventtype:
            return int(eventtype[COL_NAME_EVENTTYPE_ID])
        else:
            return None

    def UpdateEventType(self, event_type, where=None):
        """Update existing event type records.
        :param event_type: The event type record update.
        :param where: The condition to be fulfilled by the event type to the updated.
        :return: Returns the number of affected event types.
        """
        rowcount = None
        if not isinstance(event_type, dict):
            raise AdasDBError("event_type parameter is not a dictionary!")

        if COL_NAME_EVENTTYPE_CLASSNAME not in event_type:
            raise AdasDBError("UpdateEventType: classname not set.")

        if where is None:
            where = self.__GetEventTypeCondition(None, class_name=event_type[COL_NAME_EVENTTYPE_CLASSNAME])

        if (event_type is not None) and (len(event_type) != 0):
            rowcount = self.UpdateGenericData(event_type, self.GetQualifiedTableName(TABLE_NAME_EVENTTYPE), where)
        # done
        return rowcount

    def DeleteEventType(self, event_type):
        """Delete existing event type records.
        :param event_type: - The event type record to delete.
        :return: Returns the number of affected eventtypes.
        """
        rowcount = None
        if not isinstance(event_type, dict):
            raise AdasDBError("event_type parameter is not a dictionary!")

        if (event_type is not None) and (len(event_type) != 0):
            try:
                cond = self.__GetEventTypeCondition(class_name=event_type[COL_NAME_EVENTTYPE_CLASSNAME])
            except:
                raise AdasDBError("DeleteEventType: Couldn't generate EventTypeCondition.")

            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_EVENTTYPE), where=cond)
        # done
        return rowcount

    def __GetEventTypeCondition(self, event_type_id=None, class_name=None, name=None):
        """Get the condition expression to access the event type record
        :param name: Event Type ID
        :return: Returns the condition expression
        """
        cond = None
        if event_type_id is not None:
            cond = SQLBinaryExpr(COL_NAME_EVENTTYPE_ID, OP_EQ, event_type_id)
        else:
            if class_name is not None:
                cond_class = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                       COL_NAME_EVENTTYPE_CLASSNAME),
                                           OP_EQ, SQLLiteral(class_name.lower()))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_class)
                else:
                    cond = cond_class

            if name is not None:
                cond_name = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                      COL_NAME_EVENTTYPE_NAME),
                                          OP_EQ, SQLLiteral(name.lower()))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_name)
                else:
                    cond = cond_name

        return cond

    # --- RESULTTYPE Table. --------------------------------------------------
    def AddResultType(self, result_type):
        """Add a new result type to the database.
        :param result_type: The result type dictionary
        :return: Returns the testrun ID.
        """
        cond = self.__GetResultTypeCondition(result_type[COL_NAME_RESULTTYPE_NAME])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE)], where=cond)
        if len(entries) <= 0:
            self.AddGenericData(result_type, self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE))
            rtid = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE)],
                                          where=cond)[0][COL_NAME_RESULTTYPE_ID]
        else:
            tmp = "Result type '%s' " % result_type[COL_NAME_RESULTTYPE_NAME]
            tmp += "exists already in the validation result database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    rtid = entries[0][COL_NAME_RESULTTYPE_ID]
                elif len(entries) > 1:
                    tmp = "Result type name '%s' " % (result_type[COL_NAME_RESULTTYPE_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return int(rtid)

    def UpdateResultType(self, result_type, where=None):
        """Update existing result type records.
        :param result_type: The result type record update.
        :param where: The condition to be fulfilled by the result type to the updated.
        :return: Returns the number of affected result types.
        """
        rowcount = 0

        if where is None:
            where = self.__GetResultTypeCondition(result_type[COL_NAME_RESULTTYPE_NAME])

        if (result_type is not None) and (len(result_type) != 0):
            rowcount = self.UpdateGenericData(result_type, self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE), where)
        # done
        return rowcount

    def DeleteResultType(self, result_type):
        """Delete existing result type records.
        :param result_type: - The result type record to delete.
        :return: Returns the number of affected resulttypes.
        """
        rowcount = 0
        if (result_type is not None) and (len(result_type) != 0):
            cond = self.__GetResultTypeCondition(result_type[COL_NAME_RESULTTYPE_NAME])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE), where=cond)
        # done
        return rowcount

    def GetResultType(self, name):
        """Get existing result type records.
        :param name: - The result type name.
        :return: Returns the result type record.
        """
        record = {}
        cond = self.__GetResultTypeCondition(name)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE)], where=cond)
        if len(entries) <= 0:
            tmp = "Result type with name '%s' " % name
            tmp += "does not exist in the validation result database."
            logging.info(tmp)
        elif len(entries) > 1:
            tmp = "Result type with name '%s' " % (name)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            logging.warn(tmp)
        else:
            record = entries[0]
        # done
        return record

    def GetResultTypeId(self, name):
        """ Get the resultType ID
        :param name: result Type Name
        :return: Returns the result Type IDcondition expression
        """
        resulttype = self.GetResultType(name)
        if COL_NAME_RESULTTYPE_ID in resulttype:
            return int(resulttype[COL_NAME_RESULTTYPE_ID])
        else:
            return None

    def GetResultTypeById(self, res_id):
        """ Get the resultType ID
        :param name: result Type Name
        :return: Returns the result Type IDcondition expression
        """
        cond = self.__GetResultTypeCondition(res_id=res_id)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE)], where=cond)
        if len(entries) == 1:
            return entries[0]
        else:
            tmp = "Result Type does not exist in the reult database"
            if self.error_tolerance <= ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            logging.warn(tmp)

    def __GetResultTypeCondition(self, name=None, res_id=None):
        """Get the condition expression to access the result type record
        :param name: result Type ID
        :return: Returns the condition expression
        """
        if res_id is not None:
            return SQLBinaryExpr(COL_NAME_RESULTTYPE_ID, OP_EQ, res_id)
        else:
            return SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_RESULTTYPE_NAME),
                                 OP_EQ, SQLLiteral(name.lower()))

    # --- KEYS Table. ----------------------------------------------------------
    def AddValRevKey(self, name, description):
        """Add a new result revision key to the database.
        :param name: Result revision key Name.
        :param description: Result revision key Description.
        :return: Returns the new result revision key ID.
        """
        tr_id = None
        rec = {}
        rec[COL_NAME_VRKEY_NAME] = name
        rec[COL_NAME_VRKEY_DESCRIPTION] = description

        entries = self.GetValRevKey(name)
        if len(entries) <= 0:
            self.AddGenericData(rec, self.GetQualifiedTableName(TABLE_NAME_VRKEY))
        else:
            tmp = "Result revision key '%s' " % rec[COL_NAME_VRKEY_NAME]
            tmp += "exists already in the validation result database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    tr_id = entries[0][COL_NAME_VRKEY_ID]
                elif len(entries) > 1:
                    tmp = "Result revision key '%s' " % (rec[COL_NAME_VRKEY_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)

        # done
        return tr_id

    def DeleteValRevKey(self, name):
        """Delete existing result revision key records.
        :param name: Result revision key Name.
        :return: Returns the number of affected records.
        """
        rowcount = 0
        if (name is not None) and (len(name) != 0):
            entries = self.GetValRevKey(name)
            if len(entries) == 1:
                # delete revision key mapping if exists
                val_rev_key = entries[0][COL_NAME_VRKEY_ID]
                self.DeleteValRevKeyConstraint(val_rev_key)

                # delete revision key if exists
                cond = self.__GetValRevKeyCondition(val_rev_key, None)
                rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_VRKEY), where=cond)

        # done
        return rowcount

    def UpdateValRevKey(self, rec, where=None):
        """Update existing Result revision key record.
        :param rec: The Result revision key record.
        :param where: The condition to be fulfilled by the result type to the updated.
        :return: Returns the number of affected records.
        """
        rowcount = 0
        if (rec is not None) and (len(rec) != 0):
            if where is None:
                where = self.__GetValRevKeyCondition(rec[COL_NAME_VRKEY_ID], None)
            rowcount = self.UpdateGenericData(rec, self.GetQualifiedTableName(TABLE_NAME_VRKEY), where)

        # done
        return rowcount

    def GetValRevKey(self, name):
        """Get existing result revision key records.
        :param name: Result revision key Name.
        :return: Returns the result revision key records.
        """
        # entries = {}
        cond = self.__GetValRevKeyCondition(None, name)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VRKEY)], where=cond)
        if len(entries) <= 0:
            tmp = "Result Revision Key with name '%s' " % (name)
            tmp += "does not exist in the validation result database."
            logging.warn(tmp)
        elif len(entries) > 1:
            tmp = "Result Revision Key with name '%s' " % (name)
            tmp += "cannot be resolved because it is ambiguous. (%s)" % (entries)
            logging.warn(tmp)

        # done
        return entries

    def GetValRevKeyId(self, name):
        """Get existing result revision key record ID.
        :param name: Result revision key Name.
        :return: Returns the ID of the found result revision key.
        """
        kid = None
        entries = self.GetValRevKey(name)
        if len(entries) == 1:
            kid = entries[0][COL_NAME_VRKEY_ID]

        # done
        return kid

    def __GetValRevKeyCondition(self, val_rev_key=None, name=None):
        """Get the condition expression to access the result record
        :param id: Result revision key ID.
        :param name: Result revision key Name.
        :return: Returns the condition expression.
        """
        cond = None
        if val_rev_key is not None:
            cond = SQLBinaryExpr(COL_NAME_VRKEY_ID, OP_EQ, SQLLiteral(val_rev_key))

        if name is not None:
            cond_lb = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                COL_NAME_VRKEY_NAME),
                                    OP_EQ,
                                    SQLLiteral(name.lower()))
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_lb)
            else:
                cond = cond_lb

        # done
        return cond

    # --- CONSTRAINTSMAP Table. ---------------------------------------------------
    def AddValRevKeyConstraint(self, val_rev_key, rdid):
        """Add a new result revision key - result descriptor record to the database.
        :param val_rev_key: The result revision key ID
        :param rdid: The result descriptor ID
        """
        rec = {}
        rec[COL_NAME_VRKEY_MAP_ID] = val_rev_key
        rec[COL_NAME_VRKEY_MAP_RDID] = rdid

        entries = self.GetValRevKeyConstraint(val_rev_key, rdid)
        if len(entries) <= 0:
            self.AddGenericData(rec, self.GetQualifiedTableName(TABLE_NAME_VRKEY_MAP))
        else:
            tmp = "Link for Result revision key ID '%s' " % (val_rev_key)
            tmp += "and Result descriptor ID '%s' " % (rdid)
            tmp += "exists already in the validation result database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
        # done

    def DeleteValRevKeyConstraint(self, val_rev_key=None, rdid=None):
        """Delete existing result revision key - result descriptor record.
        :param val_rev_key: The result revision key ID (optional)
        :param rdid: The result descriptor ID (optional)
        :return: Returns the number of affected records.
        """
        # rowcount = 0
        cond = self.__GetValRevKeyConstraintCondition(val_rev_key, rdid)
        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_VRKEY_MAP), where=cond)

        # done
        return rowcount

    def GetValRevKeyConstraint(self, val_rev_key=None, rdid=None):
        """Get existing result revision key - result descriptor records.
        :param val_rev_key: The result revision key ID (optional)
        :param rdid: The result descriptor ID (optional)
        :return: Records if exists
        """
        # entries = {}
        cond = self.__GetValRevKeyConstraintCondition(val_rev_key, rdid)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VRKEY_MAP)], where=cond)
        if len(entries) <= 0:
            tmp = "Value for Result revision key ID '%s' " % (val_rev_key)
            tmp += "and Result descriptor ID '%s' " % (rdid)
            tmp += "doesn't exists in the validation result database"
            logging.warn(tmp)

        # done
        return entries

    def __GetValRevKeyConstraintCondition(self, val_rev_key=None, rdid=None):
        """Get the condition expression to access the result record
        :param val_rev_key: The result revision key ID (optional)
        :param rdid: The result descriptor ID (optional)
        :return: Returns the condition expression
        """

        # pylint: disable=R0201
        cond = None
        if val_rev_key is not None:
            cond = SQLBinaryExpr(COL_NAME_VRKEY_MAP_ID, OP_EQ, SQLLiteral(val_rev_key))

        if rdid is not None:
            cond_lb = SQLBinaryExpr(COL_NAME_VRKEY_MAP_RDID, OP_EQ, SQLLiteral(rdid))
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_lb)
            else:
                cond = cond_lb

        # done
        return cond

    # --- RESULT_DESC Table. --------------------------------------------------
    def AddResultDescriptor(self, rdtype, name, collect_id, unit_id, ref_tag=None, parent=None,
                            doors_url="", exp_res="", desc=""):
        """Add a new result descriptor to the database.
        :param rdtype: Descriptor type
        :param name: Descriptor Name
        :param collect_id: Collection ID from CAT
        :param unit: Unit ID from GBL
        :return: Returns the result descriptor ID.
        """

        # pylint: disable=R0913
        res_des = {}
        res_des[COL_NAME_RESDESC_NAME] = name
        res_des[COL_NAME_RESDESC_COLLID] = collect_id
        res_des[COL_NAME_RESDESC_UNIT_ID] = unit_id
        res_des[COL_NAME_RESDESC_PARENT] = parent
        res_des[COL_NAME_RESDESC_DOORS_URL] = doors_url
        res_des[COL_NAME_RESDESC_EXPECTRES] = exp_res
        res_des[COL_NAME_RESDESC_DESCRIPTION] = desc

        if ref_tag is None:
            res_des[COL_NAME_RESDESC_REFTAG] = ''
        else:
            res_des[COL_NAME_RESDESC_REFTAG] = ref_tag
        ev = self.GetResultType(rdtype)
        if COL_NAME_RESULTTYPE_ID in ev:
            res_des[COL_NAME_RESDESC_RESTYPE_ID] = ev[COL_NAME_RESULTTYPE_ID]
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Result Type '%s' " % rdtype
                tmp += "doesn't exist in the validation result database. "
                tmp += "Define a new one before adding the result descriptor"
                raise AdasDBError(tmp)
            else:
                tmp = "Result Type '%s' " % rdtype
                tmp += "doesn't exist in the validation result database. "
                tmp += "A new one without a description is generated"
                logging.info(tmp)
                ev = {}
                ev[COL_NAME_RESULTTYPE_NAME] = rdtype
                ev[COL_NAME_RESULTTYPE_DESC] = 'auto generated type - change description'
                res_des[COL_NAME_RESDESC_RESTYPE_ID] = self.AddResultType(ev)

        rdid = self.__AddResultDescriptor(res_des)
        return rdid

    def __AddResultDescriptor(self, res_desc):
        """Add a new result descriptor to the database.
        :param res_desc: The result descrition dictionary - name, collid and resulttype id are mandatory
        :return: Returns the result descriptor ID.
        """
        cond = self.__GetResDescCondition(res_desc[COL_NAME_RESDESC_COLLID],
                                          res_desc[COL_NAME_RESDESC_NAME],
                                          res_desc[COL_NAME_RESDESC_RESTYPE_ID])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC)], where=cond)
        if len(entries) <= 0:
            res_desc[COL_NAME_RESDESC_ID] = None
            self.AddGenericData(res_desc, self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC))
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC)],
                                             where=cond)
            if len(entries) == 1:
                return entries[0][COL_NAME_RESDESC_ID]
            else:
                raise AdasDBError("Result Descriptor could not be added ")
        else:
            tmp = "Result Descriptor '%s' " % res_desc[COL_NAME_RESDESC_NAME]
            tmp += "exists already in the validation result database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    rdid = entries[0][COL_NAME_RESDESC_ID]
                elif len(entries) > 1:
                    tmp = "Result Descriptor name '%s' " % (res_desc[COL_NAME_RESDESC_NAME])
                    tmp += "cannot be resolved because it is ambiguous."
                    tmp += " (%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return rdid

    def DeleteResultDescriptor(self, res_desc):
        """Delete existing result type records.
        :param res_desc: The result descrition record to delete.
        :return: Returns the number of affected resulttypes.
        """
        if (res_desc is not None) and (len(res_desc) != 0):
            cond = self.__GetResDescCondition(res_desc[COL_NAME_RESDESC_COLLID],
                                              res_desc[COL_NAME_RESDESC_NAME],
                                              res_desc[COL_NAME_RESDESC_RESTYPE_ID])
        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC), where=cond)
        # done
        return rowcount

    def GetResultDescriptor(self, coll_id, name, ev_type_id=None, ev_type_name=None):
        """Get existing result type records.
        :param name: The result descriptor name.
        :param coll_id: The collection id (testcase).
        :param ev_type_id: The result type identifier.
        :return: Returns the result type record.
        """
        record = {}
        if ev_type_id is None and ev_type_name is not None:
            ev_type_id = self.GetResultTypeId(ev_type_name)

        if name is None:
            logging.error("Result Descriptor name is undefined. Check the source code")

        cond = self.__GetResDescCondition(coll_id, name, ev_type_id)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC)], where=cond)
        if len(entries) <= 0:
            tmp = "Result Descriptor with name '%s' " % (name)
            tmp += "in collection '%s' " % (coll_id)
            tmp += "does not exist in the validation result database."
            logging.info(tmp)
        else:
            record = entries

        # done
        return record

    def GetResultDescriptorWithId(self, rd_id):
        """Get existing result type records.
        :param rd_id: Result descriptor id
        :return: Returns the result descriptor record.
        """
        record = {}
        if rd_id is None:
            logging.warn("Result Descriptor id not defined")
            return record

        tblnamed = self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC)
        tblnamer = self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE)

        cond = SQLBinaryExpr(COL_NAME_RESDESC_ID, OP_EQ, rd_id)
        tables = []
        tables.append(SQLJoinExpr(SQLTableExpr(tblnamed),
                                  OP_INNER_JOIN,
                                  SQLTableExpr(tblnamer),
                                  SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed), COL_NAME_RESDESC_RESTYPE_ID),
                                                OP_EQ,
                                                SQLColumnExpr(SQLTableExpr(tblnamer), COL_NAME_RESULTTYPE_ID))))
        select_list = []
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed),
                                                       COL_NAME_RESDESC_NAME),
                                         OP_AS, COL_NAME_RESDESC_NAME))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed),
                                                       COL_NAME_RESDESC_COLLID),
                                         OP_AS, COL_NAME_RESDESC_COLLID))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed),
                                                       COL_NAME_RESDESC_REFTAG),
                                         OP_AS, COL_NAME_RESDESC_REFTAG))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamer),
                                                       COL_NAME_RESULTTYPE_NAME),
                                         OP_AS, "TYPE_" + COL_NAME_RESULTTYPE_NAME))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamer),
                                                       COL_NAME_RESULTTYPE_CLASS),
                                         OP_AS, COL_NAME_RESULTTYPE_CLASS))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed),
                                                       COL_NAME_RESDESC_UNIT_ID),
                                         OP_AS, COL_NAME_RESDESC_UNIT_ID))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed),
                                                       COL_NAME_RESDESC_PARENT),
                                         OP_AS, COL_NAME_RESDESC_PARENT))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed),
                                                       COL_NAME_RESDESC_DOORS_URL),
                                         OP_AS, COL_NAME_RESDESC_DOORS_URL))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed),
                                                       COL_NAME_RESDESC_EXPECTRES),
                                         OP_AS, COL_NAME_RESDESC_EXPECTRES))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblnamed),
                                                       COL_NAME_RESDESC_DESCRIPTION),
                                         OP_AS, COL_NAME_RESDESC_DESCRIPTION))

        entries = self.SelectGenericData(select_list=select_list, table_list=tables, where=cond)
        if len(entries) <= 0:
            logging.debug(str("Result Descriptor with id '%s' does not exist in the validation result database." %
                              rd_id))
        elif len(entries) > 1:
            logging.warn(str("Result Descriptor with id '%s' cannot be resolved because it is ambiguous. (%s)" %
                             (rd_id)))
        else:
            record = entries[0]
        # done
        return record

    def GetResultDescriptorId(self, coll_id, name, ev_type_id=None, ev_type_name=None):
        """ Get the Result Descriptor ID
        :param coll_id: Collection ID
        :param name: Name of the Descriptor
        :param ev_type_id: Event Type ID (optional)
        :param ev_type_name: Name of the Event Type (optional)
        """
        if name is None:
            tmp = "Result Descriptor with name '%s' " % name
            tmp += "does not exist in the validation result database."
            logging.warn(tmp)

        result = self.GetResultDescriptor(coll_id, name, ev_type_id, ev_type_name)
        if len(result) <= 0:
            tmp = "Result Descriptor with name '%s' " % name
            tmp += "does not exist in the validation result database."
            logging.info(tmp)
        elif len(result) > 1:
            tmp = "Result Descriptor with name '%s' " % (name)
            tmp += "cannot be resolved because it is ambiguous."
            tmp += " (%s)" % (result)
            logging.warn(tmp)
        else:
            return result[0][COL_NAME_RESDESC_ID]
        return None

    def GetResultDescriptorIdList(self, name, coll_id_list, ev_type_id=None, ev_type_name=None):
        """ Get the List of Result Descriptor IDs
        :param name: Name of the Descriptor
        :param coll_id_list: List of Collections
        :param ev_type_id: Event Type ID (optional)
        :param ev_type_name: Name of the Event Type (optional)
        """
        result = []
        select_list = [COL_NAME_RESDESC_ID]
        if ev_type_id is None and ev_type_name is not None:
            ev_type_id = self.GetResultTypeId(ev_type_name)

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                             COL_NAME_RESDESC_NAME),
                             OP_EQ,
                             SQLLiteral(name.lower()))

        if ev_type_id is not None:
            query = ','.join(str(n) for n in coll_id_list)
            cond_col = SQLBinaryExpr(COL_NAME_RESDESC_COLLID, OP_IN, "(%s)" % query)
            cond = SQLBinaryExpr(cond, OP_AND, cond_col)
        else:
            raise AdasDBError("Event type %s not defined" % (ev_type_name))

        entries = self.SelectGenericData(select_list,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC)],
                                         where=cond)

        for res in entries:
            result.append(res[COL_NAME_RESDESC_ID])

        return result

    def GetResultDescriptorInfoForTestrun(self, tr_name=None, tr_checkpoint=None,
                                          res_type_name=None, select_list=None, where=None, incl_del=False):
        """ Get the List of Result Descriptor IDs

        select * from val_resulttypes rt
            inner join val_resultdescriptor rd on rd.restypeid = rt.restypeid
            inner join val_result vr on vr.rdid = rd.rdid
            inner join val_testrun tr on tr.trid = vr.trid where rt.name = 'VAL_TESTCASE' and tr.is_deleted=0;

        :param tr_name: Name of the Testrun
        :param tr_checkpoint: Testrun checkpoint
        :param ev_type_id: Event Type ID (optional)
        :param ev_type_name: Name of the Event Type (optional)
        :param select_list: customized select list
        :param where: customized where condition overwrites the given parameters
        :param incl_del: include the deleted testruns as well. By default, the current valid TR will be returned
        """

        # pylint: disable=R0914
        ALIAS_TABLE_NAME_RESULT_DESC = 'rd'
        ALIAS_TABLE_NAME_RESULT_TYPE = 'rt'
        ALIAS_TABLE_NAME_RESULT = 'vr'
        ALIAS_TABLE_NAME_TESTRUN = 'tr'

        tbl_tr = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TESTRUN), ALIAS_TABLE_NAME_TESTRUN)
        tbl_rd = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC), ALIAS_TABLE_NAME_RESULT_DESC)
        tbl_rt = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RESULTTYPE), ALIAS_TABLE_NAME_RESULT_TYPE)
        tbl_vr = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RESULT), ALIAS_TABLE_NAME_RESULT)
        col_rt_id = SQLColumnExpr(ALIAS_TABLE_NAME_RESULT_TYPE, COL_NAME_RESULTTYPE_ID)
        col_rt_name = SQLColumnExpr(ALIAS_TABLE_NAME_RESULT_TYPE, COL_NAME_RESULTTYPE_NAME)
        col_rd_name = SQLColumnExpr(ALIAS_TABLE_NAME_RESULT_DESC, COL_NAME_RESDESC_NAME)
        col_rd_rt_id = SQLColumnExpr(ALIAS_TABLE_NAME_RESULT_DESC, COL_NAME_RESDESC_RESTYPE_ID)
        col_rd_id = SQLColumnExpr(ALIAS_TABLE_NAME_RESULT_DESC, COL_NAME_RESDESC_ID)
        col_vr_rd_id = SQLColumnExpr(ALIAS_TABLE_NAME_RESULT, COL_NAME_RES_RESDESC_ID)
        col_tr_id = SQLColumnExpr(ALIAS_TABLE_NAME_TESTRUN, COL_NAME_TR_ID)
        col_tr_cp = SQLColumnExpr(ALIAS_TABLE_NAME_TESTRUN, COL_NAME_TR_CHECKPOINT)
        col_tr_name = SQLColumnExpr(ALIAS_TABLE_NAME_TESTRUN, COL_NAME_TR_NAME)
        col_vr_tr_id = SQLColumnExpr(ALIAS_TABLE_NAME_RESULT, COL_NAME_RES_TESTRUN_ID)
        col_vr_tr_del = SQLColumnExpr(ALIAS_TABLE_NAME_TESTRUN, COL_NAME_TR_DELETED)

        tables = []

        join1 = SQLJoinExpr(tbl_rt, OP_INNER_JOIN, tbl_rd, SQLBinaryExpr(col_rt_id, OP_EQ, col_rd_rt_id))
        join2 = SQLJoinExpr(join1, OP_INNER_JOIN, tbl_vr, SQLBinaryExpr(col_rd_id, OP_EQ, col_vr_rd_id))
        join3 = SQLJoinExpr(join2, OP_INNER_JOIN, tbl_tr, SQLBinaryExpr(col_tr_id, OP_EQ, col_vr_tr_id))
        tables.append(join3)

        if select_list is None:
            select_list = [SQLBinaryExpr(col_rd_id, OP_AS, COL_NAME_RES_RESDESC_ID),
                           SQLBinaryExpr(col_rd_name, OP_AS, COL_NAME_RESDESC_NAME),
                           SQLBinaryExpr(col_tr_id, OP_AS, COL_NAME_RES_TESTRUN_ID),
                           SQLBinaryExpr(col_tr_cp, OP_AS, COL_NAME_TR_CHECKPOINT),
                           SQLBinaryExpr(col_tr_name, OP_AS, "TR_" + COL_NAME_TR_NAME),
                           SQLBinaryExpr(col_rt_name, OP_AS, "RT_" + COL_NAME_RESULTTYPE_NAME)]

        if where is None:
            cond = None
            if res_type_name is not None:
                cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], col_rt_name),
                                     OP_EQ, SQLLiteral(res_type_name.lower()))
            if tr_name is not None:
                cond_name = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], col_tr_name),
                                          OP_EQ, SQLLiteral(tr_name.lower()))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_name)
            if tr_checkpoint is not None:
                cond_cp = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], col_tr_cp),
                                        OP_EQ, SQLLiteral(tr_checkpoint.lower()))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_cp)

            where = cond

        if incl_del is False:
            cond_del = SQLBinaryExpr(col_vr_tr_del, OP_EQ, 0)
            where = SQLBinaryExpr(where, OP_AND, cond_del)

        entries = self.SelectGenericData(select_list,
                                         table_list=tables,
                                         where=where)

        return entries

    def GetResultDescriptorList(self, coll_id, name=None, ev_type_name=None):
        """ Return a list of descriptor names for the given collection and the optional event type
        :param coll_id: The collection id (testcase).
        :param name: Name of the result descriptors (optional)
        :param ev_type_name: The event type name (Image, MAX, MIN, ...)
        :return: Returns l list if descriptor names
        """
        rdlist = []

        if ev_type_name is not None:
            ev_type_id = self.GetResultTypeId(ev_type_name)
            if ev_type_id is None:
                return rdlist

        else:
            ev_type_id = None

        cond = self.__GetResDescCondition(coll_id, name, ev_type_id)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC)], where=cond)
        if len(entries) <= 0:
            tmp = "Result Descriptor for TC '%i' with " % (coll_id)
            tmp += "name '%s' " % (name)
            tmp += "does not exist in the validation result database."
            if name is None:
                logging.info(tmp)
            else:
                logging.info(tmp)
        else:
            for rec in entries:
                desc = rec[COL_NAME_RESDESC_NAME]
                if desc not in rdlist:
                    rdlist.append(rec[COL_NAME_RESDESC_NAME])

        return rdlist

    def GetResulsDescriptorChildList(self, rd_id):
        """ Return a list of child descriptor id's for given parent descriptor id
        :param rd_id: The parrent restult descriptor id.
        :return: Returns l list if descriptor id's
        """
        rdlist = []

        cond = SQLBinaryExpr(COL_NAME_RESDESC_PARENT, OP_EQ, rd_id)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC)], where=cond)
        if len(entries) <= 0:
            tmp = "Result Descriptor(s) with parent rd_id '%i' " % (rd_id)
            tmp += "does not exist in the validation result database."
            logging.warn(tmp)
        else:
            for rec in entries:
                desc = rec[COL_NAME_RESDESC_ID]
                if desc not in rdlist:
                    rdlist.append(rec[COL_NAME_RESDESC_ID])

        return rdlist

    def __GetResDescCondition(self, coll_id, name=None, result_type_id=None, ref_tag=None):
        """Get the condition expression to access the result descriptors.
        :param coll_id: Collection ID (Testcase ID)
        :param name: Name of the result descriptors (optional)
        :param result_type_id: eventtype id (optional)
        :return: Returns the condition expression
        """
        cond = SQLBinaryExpr(COL_NAME_RESDESC_COLLID, OP_EQ, SQLLiteral(coll_id))

        if name is not None:
            cond_name = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                      COL_NAME_RESDESC_NAME),
                                      OP_EQ,
                                      SQLLiteral(name.lower()))
            cond = SQLBinaryExpr(cond, OP_AND, cond_name)

        if result_type_id is not None:
            cond_ev_type = SQLBinaryExpr(COL_NAME_RESDESC_RESTYPE_ID, OP_EQ, result_type_id)
            cond = SQLBinaryExpr(cond, OP_AND, cond_ev_type)

        if ref_tag is not None:
            cond_ref_tag = SQLBinaryExpr(COL_NAME_RESDESC_REFTAG, OP_EQ, SQLLiteral(ref_tag))
            cond = SQLBinaryExpr(cond, OP_AND, cond_ref_tag)
        return cond

    def UpdateResultDescriptor(self, res_desc, where=None):
        """Update existing result descriptor records.
        :param res_desc: The result descrition record update.
        :param where: The condition to be fulfilled by the result descriptor to the updated.
        :return: Returns the number of affected result descriptors.
        """
        rowcount = 0

        if where is None:
            where = self.__GetResDescCondition(res_desc[COL_NAME_RESDESC_COLLID],
                                               res_desc[COL_NAME_RESDESC_NAME],
                                               res_desc[COL_NAME_RESDESC_RESTYPE_ID])

        if (res_desc is not None) and (len(res_desc) != 0):
            rowcount = self.UpdateGenericData(res_desc, self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC), where)
        # done
        return rowcount

    # --- Test Result. --------------------------------------------------
    def AddTestResultWithResDesc(self, tr_id, rd_id, meas_id=None, data=None,
                                 image=None, image_title=None, labels=None):
        """ Add a new Testresult for the Testrun, the Testcase and MeasId to the database
        :param tr_id: Testrun
        :param rd_id: Result descriptor id
        :param meas_id: Meas File Identifier (Catalog)
        :param data: Array of Result Values (optional)
        :param image: Result Image (optional)
        :param image_title: Title of the Result Image (optional)
        :param labels: Array of Labels Identifiers to be linked to the result (optional)
        :return: Return the new Testresult Identifier.
        """
        result_id = None

        if data is None and image is None and labels is None or rd_id is None:
            msg = "No data to be stored: TR:%s" % (tr_id)
            if meas_id is not None:
                msg += str(", MEASID: %s" % meas_id)
            logging.info(msg)
            return result_id

        return self.__BaseAddTestResult(tr_id, rd_id, meas_id, data, image, image_title, labels)

    def AddTestResult(self, tr_id, coll_id, name, ev_type, meas_id=None,
                      data=None, image=None, image_title=None, labels=None):
        """ Add a new Testresult for the Testrun, the Testcase and MeasId to the database
        :param tr_id: Testrun
        :param coll_id: Collection or Testcase Identifier (Catalog)
        :param name: Result Name
        :param ev_type: Result Type
        :param meas_id: Meas File Identifier (Catalog)
        :param data: Array of Result Values (optional)
        :param image: Result Image (optional)
        :param image_title: Title of the Result Image (optional)
        :param labels: Array of Labels Identifiers to be linked to the result (optional)
        :return: Return the new Testresult Identifier.
        """

        # pylint: disable=R0913
        result_id = None

        try:
            rd_id = self.GetResultDescriptorId(coll_id, name, ev_type_name=ev_type)
        except StandardError:
            msg = "No Result Descriptor found: TR:%s, COLLID:%s, Name:'%s', EV:%s" % (tr_id, coll_id, name, ev_type)
            if meas_id is not None:
                msg += str(", MEASID: %s" % meas_id)
            logging.info(msg)
            return result_id

        if data is None and image is None and labels is None or rd_id is None:
            msg = "No data to be stored: TR:%s, COLLID:%sma, Name:'%s', EV:%s" % (tr_id, coll_id, name, ev_type)
            if meas_id is not None:
                msg += str(", MEASID: %s" % meas_id)
            logging.info(msg)
            return result_id

        return self.__BaseAddTestResult(tr_id, rd_id, meas_id, data, image, image_title, labels)

    def __BaseAddTestResult(self, tr_id, rd_id, meas_id=None, data=None, image=None, image_title=None, labels=None):
        """ Basic Add a new Testresult for the Testrun, the Testcase and MeasId to the database
        :param tr_id: Testrun
        :param rd_id: Result descriptor id
        :param meas_id: Meas File Identifier (Catalog)
        :param data: Array of Result Values (optional)
        :param image: Result Image (optional)
        :param image_title: Title of the Result Image (optional)
        :param labels: Array of Labels Identifiers to be linked to the result (optional)
        :return: Return the new Testresult Identifier.
        """
        result_id = None
        if rd_id is not None:
            res = {}
            res[COL_NAME_RES_RESDESC_ID] = rd_id
            res[COL_NAME_RES_TESTRUN_ID] = tr_id
            if meas_id is not None and meas_id > -1:
                res[COL_NAME_RES_MEASID] = meas_id

            # Store a single value directly to the result
            if data is not None and len(data) == 1:
                res[COL_NAME_RES_VALUE] = data[0]

            result_id = self.AddResult(res)

            if data is not None and len(data) > 1:
                res_dat = {}
                res_dat[COL_NAME_RESVAL_ID] = result_id
                for i in range(len(data)):
                    res_dat[COL_NAME_RESVAL_SUBID] = i
                    res_dat[COL_NAME_RESVAL_VALUE] = data[i]
                    self.AddResultValue(res_dat)

            # Add the image
            if image is not None:
                res_img = {}
                res_img[COL_NAME_RESIMG_ID] = result_id
                res_img[COL_NAME_RESIMG_IMAGE] = image
                res_img[COL_NAME_RESIMG_TITLE] = ''
                res_img[COL_NAME_RESIMG_FORMAT] = 'png'
                if image_title is not None:
                    if len(image_title) >= 60:
                        image_title = image_title.replace(' ', '')
                        image_title = image_title.replace('.', '')
                        image_title = image_title.replace(':', '')
                        image_title = image_title.replace('(', '')
                        image_title = image_title.replace(')', '')
                        image_title = image_title[:59]
                    res_img[COL_NAME_RESIMG_TITLE] = image_title
                self.AddResultImage(res_img)

        return result_id

    def AddResult(self, result):
        """Add a new result descriptor to the database.
        :param result: The result dictionary - trid, rdid, measid are mandatory
        :return: Returns the result ID.
        """
        if COL_NAME_RES_MEASID in result:
            meas_id = result[COL_NAME_RES_MEASID]
        else:
            meas_id = None

        cond = self.__GetResultCondition(result[COL_NAME_RES_TESTRUN_ID],
                                         result[COL_NAME_RES_RESDESC_ID],
                                         meas_id)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT)], where=cond)
        if len(entries) <= 0:
            rid = self.AddGenericData(result, self.GetQualifiedTableName(TABLE_NAME_RESULT))
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT)], where=cond)
            if len(entries) == 1:
                return entries[0][COL_NAME_RES_ID]
            else:
                szMsg = "Result for testrun '%s', " % (result[COL_NAME_RES_TESTRUN_ID])
                szMsg += "Result Descriptor '%s' " % (result[COL_NAME_RES_RESDESC_ID])
                szMsg += "and MeasID '%s' " % (result[COL_NAME_RES_MEASID])
                szMsg += "exists already in the validation result database"
                raise AdasDBError(szMsg)
        else:
            szMsg = "Result for testrun '%s', " % (result[COL_NAME_RES_TESTRUN_ID])
            szMsg += "Result Descriptor '%s' " % (result[COL_NAME_RES_RESDESC_ID])
            szMsg += "and MeasID '%s' " % (result[COL_NAME_RES_MEASID])
            szMsg += "exists already in the validation result database"

            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(szMsg)
            else:
                logging.warn(szMsg)
                if len(entries) == 1:
                    rid = entries[0][COL_NAME_RES_ID]
                elif len(entries) > 1:
                    raise AdasDBError("Specific result cannot be found because it is ambiguous. (%s)" % entries)
        # done
        return rid

    def DeleteResult(self, result):
        """Delete existing result records.
        :param res_desc: The result descrition record to delete.
        :return: Returns the number of affected eventtypes.
        """
        if (result is not None) and (len(result) != 0):
            measid = None
            rdid = None
            if COL_NAME_RES_RESDESC_ID in result:
                rdid = result[COL_NAME_RES_RESDESC_ID]
            if COL_NAME_RES_MEASID in result:
                measid = result[COL_NAME_RES_MEASID]

            cond = self.__GetResultCondition(result[COL_NAME_RES_TESTRUN_ID], rdid, measid)

        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RESULT), where=cond)
        # done
        return rowcount

    def GetResult(self, tr_id, rd_id=None, meas_id=None, res_id=None):
        """Get existing result records.
        :param tr_id: Testrun ID
        :param rd_id: Result descriptor ID (optional)
        :param meas_id: Measurement file ID (optional)
        :param res_id: Result ID(optional, if this is the the other arguments are ignored)
        """
        record = {}
        if res_id is None:
            cond = self.__GetResultCondition(tr_id, rd_id, meas_id)
        else:
            cond = SQLBinaryExpr(COL_NAME_RES_ID, OP_EQ, SQLLiteral(res_id))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Result for testrun  '%s' does not exist in the validation result database." % tr_id))
        elif len(entries) > 1:
            record = entries
        else:
            record = entries[0]
        # done
        return record

    def GetResultIds(self, tr_id, rd_id=None, meas_id=None):
        """Get existing result ids.
        :param tr_id: Testrun ID
        :param rd_id: Result descriptor ID (optional)
        :param meas_id: Measurement file ID (optional)
        """
        cond = self.__GetResultCondition(tr_id, rd_id, meas_id)
        select_list = [COL_NAME_RES_ID]
        _, entries = self.SelectGenericDataCompact(select_list,
                                                   [self.GetQualifiedTableName(TABLE_NAME_RESULT)],
                                                   where=cond)
        if len(entries) <= 0:
            logging.warn(str("Result for testrun  '%s' does not exist in the validation result database." % tr_id))

        # done
        return entries

    def __GetResultCondition(self, tr_id, rd_id=None, meas_id=None):
        """Get the condition expression to access the result record
        :param tr_id: Testrun ID
        :param rd_id: Result descriptor ID (optional)
        :param meas_id: Measurement file ID (optional)
        :return: Returns the condition expression
        """

        # pylint: disable=R0201
        cond = SQLBinaryExpr(COL_NAME_RES_TESTRUN_ID, OP_EQ, tr_id)

        if rd_id is not None:
            cond_rd = SQLBinaryExpr(COL_NAME_RES_RESDESC_ID, OP_EQ, rd_id)
            cond = SQLBinaryExpr(cond, OP_AND, cond_rd)

        if meas_id is not None:
            cond_mid = SQLBinaryExpr(COL_NAME_RES_MEASID, OP_EQ, meas_id)
            cond = SQLBinaryExpr(cond, OP_AND, cond_mid)

        return cond

    def UpdateResult(self, result, where=None):
        """Update existing result record.
        :param result: The result record update.
        :param where: The condition to be fulfilled by the result to the updated.
        :return: Returns the number of affected result descriptors.
        """
        rowcount = 0

        if where is None:
            where = self.__GetResultCondition(result[COL_NAME_RES_TESTRUN_ID],
                                              result[COL_NAME_RES_RESDESC_ID],
                                              result[COL_NAME_RES_MEASID])

        if (result is not None) and (len(result) != 0):
            rowcount = self.UpdateGenericData(result, self.GetQualifiedTableName(TABLE_NAME_RESULT), where)
        # done
        return rowcount

    # --- ASSESSMENT Table. --------------------------------------------------
    def AddAssessment(self, assessment):
        """Add a new assesssment record to the database.
        :return: Returns the result ID.
        """
        assstid = None
        try:
            if assessment[COL_NAME_ASS_WFID] is None or assessment[COL_NAME_ASS_USER_ID] is None:
                raise AdasDBError("AddAssessment arguments are not sufficient")

            if COL_NAME_ASS_ASSSTID in assessment:
                assstid = assessment[COL_NAME_ASS_ASSSTID]
                # if not isinstance(assessment[COL_NAME_ASS_ASSSTID], (int, float, long)):
                #    raise AdasDBError
        except:
            raise AdasDBError("AddAssessment: wfid or user id or assessment not set or not integers.")

        try:
            self.AddGenericData(assessment, self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT))

            assid = self._GetNextID(TABLE_NAME_ASSESSMENT, COL_NAME_ASS_ID) - 1
            cond = self.__GetAssessmentCondition(assid=assid,
                                                 wfid=assessment[COL_NAME_ASS_WFID],
                                                 user_id=assessment[COL_NAME_ASS_USER_ID],
                                                 asscomment=assessment[COL_NAME_ASS_COMMENT],
                                                 assstid=assstid)

            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT)],
                                             where=cond)
        except StandardError, ex:
            raise AdasDBError("Assessment cannot be added due error:%s" % str(ex))

        if len(entries) < 0:
            raise AdasDBError("Assessment for ID cannot be added")
        elif len(entries) > 1:
            raise AdasDBError("Assessment for ID cannot be found because it is ambiguous. (%s)" % entries)
        elif len(entries) == 1:
            assid = entries[0][COL_NAME_ASS_ID]
        # done
        return assid

    def DeleteAssessment(self, assessment_id):
        """Delete existing result assessment records.
        :param assessment: The assessment record to delete.
        :return: Returns the number of affected assessments.
        """
#         try:
#             assessment_id = int(assessment_id)
#         except:
#             raise AdasDBError("DeleteAssessment: assessment_id is not an integer.")

        cond = self.__GetAssessmentCondition(assid=assessment_id)
        return self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT), where=cond)
        # done

    def GetAssessment(self, assid=None, assstid=None, asscomment=None, wfid=None, userid=None):
        """Get existing result assessment records.
        :param assid: Assessment ID
        :param assstid: Assessment State Identifier
        :return: Record if exist
        """
        try:
            cond = self.__GetAssessmentCondition(assid=assid, wfid=wfid, asscomment=asscomment,
                                                 user_id=userid, assstid=assstid)

            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT)],
                                             where=cond)
        except:
            raise AdasDBError("Assessment could not retrieved. Please check the parameters")

        if len(entries) <= 0:
            logging.warn(str("Assessment ID '%s' does not exist in the validation result database." % assid))
        else:
            return entries

        # done
        return []

    def GetAssessmentId(self, assstid=None, asscomment=None, wfid=None, userid=None):
        """ Get the Assessment Identifier
        :param assstid: Assessment State Identifier
        :param asscomment: Assessment comment
        :param wfid: WorkFlow Identifier
        :param userid: User Identifier
        """
        assid = []
        entries = self.GetAssessment(assstid=assstid, asscomment=asscomment, wfid=wfid, userid=userid)

        if len(entries) > 1:
            for item in entries:
                assid.append(item[COL_NAME_ASS_ID])
        elif len(entries) == 1:
            assid = entries[0][COL_NAME_ASS_ID]

        return assid

    def UpdateAssessment(self, assessment, where=None):
        """Update existing result accessment record.
        :param res_ass: The result assesment record update.
        :param where: The condition to be fulfilled by the result assessment to the updated.
        :return: Returns the number of affected assessments descriptors.
        """
        rowcount = None
        if not isinstance(assessment, dict):
            raise AdasDBError("UpdateAssessment: assessment id is not a dict.")

        if COL_NAME_ASS_ID not in assessment:
            raise AdasDBError("UpdateAssessment: Assessment id not set.")

        if where is None:
            where = self.__GetAssessmentCondition(assessment[COL_NAME_ASS_ID])

        if (assessment is not None) and (len(assessment) != 0):
            rowcount = self.UpdateGenericData(assessment, self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT), where)
        # done
        self.Commit()
        return rowcount

    def __GetAssessmentCondition(self, assid=None, user_id=None, asscomment=None,
                                 wfid=None, assdate=None, assstid=None):
        """Get the condition expression to access the assesment record
        :param assid: Assessment ID
        :return: Returns the condition expression
        """

        # pylint: disable=R0201, R0912
        cond = None

        if assid is None:
            cond = SQLBinaryExpr(COL_NAME_ASS_ID, OP_IS, SQLNull())
        else:
            cond = SQLBinaryExpr(COL_NAME_ASS_ID, OP_EQ, assid)

        if user_id is not None:
            cond_user = SQLBinaryExpr(COL_NAME_ASS_USER_ID, OP_EQ, user_id)
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_user)
            else:
                cond = cond_user

        if asscomment is not None:
            cond_com = SQLBinaryExpr(COL_NAME_ASS_COMMENT, OP_EQ, SQLLiteral(asscomment))
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_com)
            else:
                cond = cond_com

        if wfid is not None:
            cond_wfid = SQLBinaryExpr(COL_NAME_ASS_WFID, OP_EQ, wfid)
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_wfid)
            else:
                cond = cond_wfid

        if assdate is not None:
            cond_date = SQLBinaryExpr(COL_NAME_ASS_DATE, OP_EQ, SQLLiteral(assdate))
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_date)
            else:
                cond = cond_date

        if assstid is not None:
            cond_ass = SQLBinaryExpr(COL_NAME_ASS_ASSSTID, OP_EQ, assstid)
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_ass)
            else:
                cond = cond_ass

        return cond

    # --- IMAGE Table. --------------------------------------------------
    def AddResultImage(self, res_img):
        """Add a new image to the database.
        :param res_img: The result assessment - resid is mandatory as it is the primary key
        :return: Returns the number of affected rows.
        """
        rowcount = 0
        cond = self.__GetResultImgCondition(res_img[COL_NAME_RESIMG_ID])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_IMAGE)], where=cond)
        if len(entries) <= 0:
            stmt = 'INSERT INTO '
            stmt += str(self.GetQualifiedTableName(TABLE_NAME_RESULT_IMAGE))
            stmt += " (%s," % (COL_NAME_RESIMG_ID)
            stmt += "%s," % (COL_NAME_RESIMG_TITLE)
            stmt += "%s," % (COL_NAME_RESIMG_FORMAT)
            stmt += "%s)" % (COL_NAME_RESIMG_IMAGE)
            stmt += " VALUES('%s'," % (res_img[COL_NAME_RESIMG_ID],)
            stmt += "'%s'," % (res_img[COL_NAME_RESIMG_TITLE])
            stmt += "'%s', :1)" % (res_img[COL_NAME_RESIMG_FORMAT])
            cursor = self.db_connection.cursor()
            try:
                logging.debug(stmt)
                cursor.execute(stmt, (res_img[COL_NAME_RESIMG_IMAGE],))
                rowcount = cursor.rowcount
            except:
                logging.error(stmt)
                raise
            finally:
                cursor.close()

        else:
            tmp = "Image for Result ID '%s' " % res_img[COL_NAME_RESIMG_ID]
            tmp += "exists already in the validation result database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    # ident = entries[0][COL_NAME_RESIMG_ID]
                    pass
                elif len(entries) > 1:
                    raise AdasDBError("Image for result ID cannot be found because it is ambiguous. (%s)" % entries)
        # done
        return rowcount

    def DeleteResultImage(self, res_img):
        """Delete existing result image records.
        :param res_img: The result image record to delete.
        :return: Returns the number of affected assessments.
        """
        if (res_img is not None) and (len(res_img) != 0):
            cond = self.__GetResultImgCondition(res_img[COL_NAME_RESIMG_ID])

        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RESULT_IMAGE), where=cond)
        # done
        return rowcount

    def GetResultImage(self, res_id):
        """Get existing result assessment records.
        :param res_id: Result ID
        :return: Record if exist
        """
        record = {}
        cond = self.__GetResultImgCondition(res_id)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_IMAGE)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Image for Result ID '%s' does not exist in the validation result database." % res_id))
        elif len(entries) > 1:
            logging.warn(str("Image for Result '%s' cannot be found because it is ambiguous. (%s)" %
                             (res_id, str(entries))))
        else:
            record = entries[0]
        # done
        return record

    def GetImage(self, tr_id, name, ev_type, coll_id, meas_id=None):
        """ Get Image and Title
        :param tr_id: Testrun
        :param name: Name of the Result
        :param ev_type: Name of the event type
        :param coll_id: Collection or Testcase Identifier (Catalog)
        :param meas_id: Meas File Identifier (Catalog) (optional)
        :return: Return the buffer of image data and the title
        """
        select = [COL_NAME_RES_ID]

        if meas_id == -1:
            meas_id = None

        rd_id = self.GetResultDescriptorId(coll_id, name, ev_type_name=ev_type)
        cond = self.__GetResultCondition(tr_id, rd_id, meas_id)
        entries = self.SelectGenericData(select, table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT)],
                                         where=cond)

        if entries is not None and len(entries) == 1:
            res_id = entries[0][COL_NAME_RES_ID]
            result = self.GetResultImage(res_id)
            if COL_NAME_RESIMG_IMAGE in result:
                return buffer(result[COL_NAME_RESIMG_IMAGE]), result[COL_NAME_RESIMG_TITLE]

        return None, ""

    def __GetResultImgCondition(self, res_id):
        """Get the condition expression to access the result record
        :param res_id: Result ID
        :return: Returns the condition expression
        """

        # pylint: disable=R0201
        return SQLBinaryExpr(COL_NAME_RESIMG_ID, OP_EQ, SQLLiteral(res_id))

    # --- RESULT_MESSAGES Table. --------------------------------------------------
    def AddResultMessage(self, res_val):
        """Add a new result message record to the database.
        :param res_val: The result message - resid and index are mandatory as they are the primary keys
        :return: Returns the result ID.
        """
        cond = self.__GetResultMessageCondition(res_val[COL_NAME_RESMESS_ID], res_val[COL_NAME_RESMESS_SUBID])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_MESSAGES)],
                                         where=cond)
        if len(entries) <= 0:
            self.AddGenericData(res_val, self.GetQualifiedTableName(TABLE_NAME_RESULT_MESSAGES))
        else:
            tmp = "Message for Result ID '%s' " % (res_val[COL_NAME_RESMESS_ID])
            tmp += "and Index '%s' " % (res_val[COL_NAME_RESMESS_SUBID])
            tmp += "exists already in the validation result database"

            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
        # done

    def DeleteResultMessage(self, res_val):
        """Delete existing result message record(s).
        :param res_desc: The result assessment record to delete.
        :return: Returns the number of affected records.
        """
        rowcount = 0
        if (res_val is not None) and (len(res_val) != 0):
            if COL_NAME_RESMESS_SUBID in res_val:
                cond = self.__GetResultMessageCondition(res_val[COL_NAME_RESMESS_ID], res_val[COL_NAME_RESMESS_SUBID])
            else:
                cond = self.__GetResultMessageCondition(res_val[COL_NAME_RESMESS_ID])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RESULT_MESSAGES), where=cond)

        # done
        return rowcount

    def GetListOfResultMessages(self, res_id, sub_id=None):
        """Get existing result assessment records.
        :param res_id: Result ID
        :param sub_id: Sub identifier
        :return: Record if exist
        """
        record = {}
        cond = self.__GetResultMessageCondition(res_id, sub_id)
        select_list = [COL_NAME_RESMESS_MESS]
        sort = [COL_NAME_RESMESS_SUBID]
        entries = self.SelectGenericDataCompact(select_list,
                                                table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_MESSAGES)],
                                                where=cond, order_by=sort)
        if len(entries) <= 0:
            tmp = "Message for Result ID '%s' " % (res_id)
            tmp += "and Index '%s' " % (sub_id)
            tmp += "exists already in the validation result database"
            logging.warn(tmp)
        else:
            if len(entries) > 0:
                res_list = []
                for i in range(len(entries[1])):
                    res_list.append(entries[1][i][0])

            record = res_list
        # done
        return record

    def GetArrayOfResultMessages(self, res_id):
        """ Get array of result messages.
        :param res_id: Result ID
        :return: Array with result messages. Empty array if none found.
        """
        record = self.GetListOfResultMessages(res_id)

        message_array = []

        for item in record:
            message_array.append(item)

        return message_array

    def GetResultMessages(self, tr_id, name, ev_type, coll_id, meas_id=None):
        """ Add the sum of messages
        :param tr_id: Testrun
        :param name: Name of the Result
        :param ev_type: Name of the event type
        :param coll_id: Collection or Testcase Identifier (Catalog)
        :param meas_id: Meas File Identifier (Catalog) (optional)
        :return: Return the sum of the Testmessages
        """
        select = [COL_NAME_RES_ID, COL_NAME_RESMESS_MESS]

        rd_id = self.GetResultDescriptorId(coll_id, name, ev_type_name=ev_type)
        if rd_id is None:
            return None
        cond = self.__GetResultCondition(tr_id, rd_id, meas_id)
        entries = self.SelectGenericData(select, table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT)],
                                         where=cond)

        if len(entries) == 1:
            result_list = self.GetListOfResults(entries[0][COL_NAME_RES_ID])
            if len(result_list):
                return result_list
            return [entries[0][COL_NAME_RESMESS_MESS]]
        else:
            return None

    def __GetResultMessageCondition(self, res_id, idx=None):
        """Get the condition expression to access the result record
        :param res_id: Result ID
        :param idx: Index (optional)
        :return: Returns the condition expression
        """
        # pylint: disable=R0201
        cond = SQLBinaryExpr(COL_NAME_RESMESS_ID, OP_EQ, SQLLiteral(res_id))

        if idx is not None:
            cond_mid = SQLBinaryExpr(COL_NAME_RESMESS_SUBID, OP_EQ, SQLLiteral(idx))
            cond = SQLBinaryExpr(cond, OP_AND, cond_mid)

        return cond

    # --- RESULT_VALUES Table. --------------------------------------------------
    def AddResultValue(self, res_val):
        """Add a new result value record to the database.
        :param res_val: The result value - resid and index are mandatory as they are the primary keys
        :return: Returns the result ID.
        """
        cond = self.__GetResultValueCondition(res_val[COL_NAME_RESVAL_ID], res_val[COL_NAME_RESVAL_SUBID])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_VALUES)], where=cond)
        if len(entries) <= 0:
            self.AddGenericData(res_val, self.GetQualifiedTableName(TABLE_NAME_RESULT_VALUES))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Value for Result ID '%s' " % (res_val[COL_NAME_RESVAL_ID])
                tmp += "and Index '%s' " % (res_val[COL_NAME_RESVAL_SUBID])
                tmp += "exists already in the validation result database"
                raise AdasDBError(tmp)
            else:
                tmp = "Value for Result ID '%s' " % (res_val[COL_NAME_RESVAL_ID])
                tmp += "and Index '%s' " % (res_val[COL_NAME_RESVAL_SUBID])
                tmp += "exists already in the validation result database"
                logging.warn(tmp)
        # done

    def DeleteResultValue(self, res_val):
        """Delete existing result value record(s).
        :param res_desc: The result assessment record to delete.
        :return: Returns the number of affected records.
        """
        rowcount = 0
        if (res_val is not None) and (len(res_val) != 0):
            if COL_NAME_RESVAL_SUBID in res_val:
                cond = self.__GetResultValueCondition(res_val[COL_NAME_RESVAL_ID], res_val[COL_NAME_RESVAL_SUBID])
            else:
                cond = self.__GetResultValueCondition(res_val[COL_NAME_RESVAL_ID])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RESULT_VALUES), where=cond)

        # done
        return rowcount

    def GetListOfResults(self, res_id, sub_id=None):
        """Get existing result assessment records.
        :param res_id: Result ID
        :param sub_id: Sub identifier
        :return: Record if exist
        """
        record = []
        cond = self.__GetResultValueCondition(res_id, sub_id)
        select_list = [COL_NAME_RESVAL_VALUE]
        sort = [COL_NAME_RESVAL_SUBID]
        entries = self.SelectGenericDataCompact(select_list,
                                                table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_VALUES)],
                                                where=cond,
                                                order_by=sort)
        if len(entries) <= 0:
            tmp = "Value for Result ID '%s' and Index '%s' " % (res_id, sub_id)
            tmp += "exists already in the validation result database"
            logging.warn(tmp)
        else:
            if len(entries) > 0:
                res_list = []
                for i in range(len(entries[1])):
                    res_list.append(entries[1][i][0])

            record = res_list
        # done
        return record

    def GetResultValues(self, tr_id, name=None, ev_type=None, coll_id=None, meas_id=None, rd_id=None):
        """ Add the sum of values
        :param tr_id: Testrun
        :param name: Name of the Result
        :param ev_type: Name of the event type
        :param coll_id: Collection or Testcase Identifier (Catalog)
        :param meas_id: Meas File Identifier (Catalog) (optional)
        :param rd_id: Result descriptor id
        :return: Return the sum of the Testvalues
        """
        select = [COL_NAME_RES_ID, COL_NAME_RES_VALUE]

        if rd_id is None:
            rd_id = self.GetResultDescriptorId(coll_id, name, ev_type_name=ev_type)

        if rd_id is None:
            return None

        cond = self.__GetResultCondition(tr_id, rd_id, meas_id)
        entries = self.SelectGenericData(select, table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT)],
                                         where=cond)

        if len(entries) == 1:
            result_list = self.GetListOfResults(entries[0][COL_NAME_RES_ID])
            if len(result_list):
                return result_list
            return [entries[0][COL_NAME_RES_VALUE]]
        else:
            return None

    def __GetResultValueCondition(self, res_id, idx=None):
        """Get the condition expression to access the result record
        :param res_id: Result ID
        :param idx: Index (optional)
        :return: Returns the condition expression
        """
        # pylint: disable=R0201
        cond = SQLBinaryExpr(COL_NAME_RESVAL_ID, OP_EQ, SQLLiteral(res_id))

        if idx is not None:
            cond_mid = SQLBinaryExpr(COL_NAME_RESVAL_SUBID, OP_EQ, SQLLiteral(idx))
            cond = SQLBinaryExpr(cond, OP_AND, cond_mid)

        return cond

    # --- RESULT_LABEL Table. --------------------------------------------------
    def AddResultLabel(self, res_id, lb_id):
        """Add a new result - label map record to the database.
        :param res_id: The result id
        :param lb_id: The label id
        """
        cond = self.__GetResultLabelMapCondition(res_id, lb_id)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_LABEL_MAP)],
                                         where=cond)

        res_val = {}
        res_val[COL_NAME_RESLB_RESID] = res_id
        res_val[COL_NAME_RESLB_LBID] = lb_id

        if len(entries) <= 0:
            self.AddGenericData(res_val, self.GetQualifiedTableName(TABLE_NAME_RESULT_LABEL_MAP))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Link for Result ID '%s' and Label '%s' " % (res_id, lb_id)
                tmp += "exists already in the validation result database"
                raise AdasDBError(tmp)
            else:
                tmp = "Link for Result ID '%s' and Label '%s' " % (res_id, lb_id)
                tmp += "exists already in the validation result database"
                logging.warn(tmp)
        # done

    def DeleteResultLabel(self, res_id=None, lb_id=None):
        """Delete existing result to label map.
        :param res_id: The result id (optional)
        :param lb_id: The label id (optional)
        :return: Returns the number of affected records.
        """
        cond = self.__GetResultLabelMapCondition(res_id, lb_id)
        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RESULT_LABEL_MAP), where=cond)

        # done
        return rowcount

    def GetResultLabel(self, res_id=None, lb_id=None):
        """Get existing result assessment records.
        :param res_id: The result id (optional)
        :param lb_id: The label id (optional)
        :return: Record if exist
        """
        record = {}
        cond = self.__GetResultLabelMapCondition(res_id, lb_id)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_LABEL_MAP)],
                                         where=cond)
        if len(entries) <= 0:
            tmp = "Value for Result ID '%s' and Index '%s' " % (res_id, lb_id)
            tmp += "exists already in the validation result database"
            logging.warn(tmp)
        else:
            record = entries
        # done
        return record

    def __GetResultLabelMapCondition(self, res_id=None, lb_id=None):
        """Get the condition expression to access the result record
        :param res_id: Result ID (optional)
        :param lb_id:  Label ID (optional)
        :return: Returns the condition expression
        """
        # pylint: disable=R0201
        cond = None

        if res_id is not None:
            cond = SQLBinaryExpr(COL_NAME_RESVAL_ID, OP_EQ, SQLLiteral(res_id))

        if lb_id is not None:
            cond_lb = SQLBinaryExpr(COL_NAME_RESLB_LBID, OP_EQ, SQLLiteral(lb_id))
            if cond is not None:
                cond = SQLBinaryExpr(cond, OP_AND, cond_lb)
            else:
                cond = cond_lb
        return cond

    # --- VALIDATION RESULT COMMON METHODS ------------------------------------------------------------------
    def GetTestRunSumValue(self, tr_id, name, ev_type, coll_id_list, meas_id=None):
        """ Add the sum of values
        :param tr_id: Testrun
        :param name: Name of the Result
        :param ev_type: Name of the event type
        :param coll_id_list: List of Collections or Testcase Identifiers (Catalog)
        :param meas_id: Meas File Identifier (Catalog) if specific COLLID is given
        :return: Return the sum of the Testvalues
        """
        expr = "SUM(%s)" % COL_NAME_RES_VALUE
        select = [expr]
        table_list = [self.GetQualifiedTableName(TABLE_NAME_RESULT)]

        if len(coll_id_list) == 1:
            rd_id = self.GetResultDescriptorId(coll_id_list[0], name, ev_type_name=ev_type)
            cond = self.__GetResultCondition(tr_id, rd_id, meas_id)
        else:
            cond = self.__GetResultCondition(tr_id)
            res_desc_list = self.GetResultDescriptorIdList(name, coll_id_list, ev_type_name=ev_type)
            where_in = ','.join(str(n) for n in res_desc_list)
            cond_rd = SQLBinaryExpr(COL_NAME_RES_RESDESC_ID, OP_IN, "(%s)" % where_in)
            cond = SQLBinaryExpr(cond, OP_AND, cond_rd)

        entries = self.SelectGenericData(select, table_list, where=cond)
        if len(entries) == 1:
            return entries[0][expr]
        else:
            return 0

    # --- HISTOGRAM (RESULT_MESSAGES, RESULT_VALUES)Table. --------------------------------------------------
    def AddHistogram(self, resid, columns, values):
        """ Writes a histogram to the RESULT_MESSAGES and RESULT_VALUES tables
        :param resid: The results id to which the histogram data is linked.
        :param columns: Array type variable containing the column information
        :param values: Array type variable containing the value information
        """
        columns_dict = {}
        values_dict = {}
        for idx in xrange(len(columns)):
            columns_dict[COL_NAME_RESMESS_ID] = resid
            columns_dict[COL_NAME_RESMESS_SUBID] = idx
            columns_dict[COL_NAME_RESMESS_MESS] = columns[idx]
            self.AddResultMessage(columns_dict)
            values_dict[COL_NAME_RESVAL_ID] = resid
            values_dict[COL_NAME_RESVAL_SUBID] = idx
            values_dict[COL_NAME_RESVAL_VALUE] = values[idx]
            self.AddResultValue(values_dict)
        self.Commit()

    def DeleteHistogram(self, resid):
        """ Deletes the histogram is in the database based on trid and name.
        :param resid: The result id.
        :return: The number of entries deleted.
        """
        res_val = {}
        res_val[COL_NAME_RESMESS_ID] = resid
        res_val[COL_NAME_RESVAL_ID] = resid

        self.DeleteResultMessage(res_val)
        entries = self.DeleteResultValue(res_val)
        return entries

    def GetHistogramm(self, resid):
        """ Gets the histogram using statistics from all the files used with trid
        :param resid: Result id
        :return: array_histogram: 2D array containing the bins columns and values.
        """
        res_columns = self.GetArrayOfResultMessages(resid)
        res_values = self.GetListOfResults(resid)

        return [res_columns, res_values]

    # --- ROAD_EVALUATION Tables. --------------------------------------------------
    def AddRoadEvent(self, record):
        """ Writes a single event line in the road event table
        :param record: dictionnary type variable containing the event information
        """
        cond_1 = SQLBinaryExpr(record[COL_NAME_ROAD_EVENTS_RESID], OP_EQ, COL_NAME_ROAD_EVENTS_RESID)
        cond_2 = SQLBinaryExpr(record[COL_NAME_ROAD_EVENTS_TIMESAMPLE], OP_EQ, COL_NAME_ROAD_EVENTS_TIMESAMPLE)
        cond_3 = SQLBinaryExpr(record[COL_NAME_ROAD_EVENTS_THRESHOLD], OP_EQ, COL_NAME_ROAD_EVENTS_THRESHOLD)
        cond_4 = SQLBinaryExpr(record[COL_NAME_ROAD_EVENTS_BEGINABSTS], OP_EQ, COL_NAME_ROAD_EVENTS_BEGINABSTS)
        cond_5 = SQLBinaryExpr(record[COL_NAME_ROAD_EVENTS_ENDABSTS], OP_EQ, COL_NAME_ROAD_EVENTS_ENDABSTS)
        cond1 = SQLBinaryExpr(cond_1, OP_AND, cond_2)
        cond2 = SQLBinaryExpr(cond_3, OP_AND, cond_4)
        cond3 = SQLBinaryExpr(cond1, OP_AND, cond2)
        cond = SQLBinaryExpr(cond3, OP_AND, cond_5)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ROAD_EVENTS)], where=cond)
        if len(entries) != 0:
            logging.info('Event already in the database')
        else:
            record[COL_NAME_ROAD_EVENTS_EVENTID] = None
            self.AddGenericData(record, self.GetQualifiedTableName(TABLE_NAME_ROAD_EVENTS))
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ROAD_EVENTS)],
                                             where=cond)
            if len(entries) == 1:
                return entries[0][COL_NAME_ROAD_EVENTS_EVENTID]
            else:
                raise AdasDBError("Roadevent could not be added ")
        return 0

    def GetListOfEvents(self, res_id):
        record = []
        cond = SQLBinaryExpr(int(res_id), OP_EQ, COL_NAME_ROAD_EVENTS_RESID)
        entries = self.SelectGenericData(select_list=[COL_NAME_ROAD_EVENTS_EVENTID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_ROAD_EVENTS)],
                                         where=cond)
        for i in xrange(0, len(entries)):
            record.append(entries[i][COL_NAME_ROAD_EVENTS_EVENTID])

        return record

    def DeleteRoadEvent(self, res_id=None):
        """Delete existing rresult to label map.
        :param res_id: The result id (optional)
        :return: Returns the number of affected records.
        """
        cond = SQLBinaryExpr(COL_NAME_ROAD_EVENTS_RESID, OP_EQ, res_id)

        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_ROAD_EVENTS), where=cond)

        # done
        return rowcount
    #==========================================================================
    # Functions for generating the pdf report based on the road estimation
    # validation information available in the database
    #==========================================================================

    def GetRoadNumberOfSWVersionsWithCollid(self, collid, test_run_name):
        """ Returns the list of checkpoints for a given collid and test run name
        :param collid: the collection id
        :param test_run_name: the test run name
        :return: SW_list: the software list
        """
        SW_list = []
        # First we get the RDID list: the list of result descriptors having collid as COLLID
        RDid_list = []
        cond = SQLBinaryExpr(collid, OP_EQ, COL_NAME_RESDESC_COLLID)
        entries = self.SelectGenericData(select_list=[COL_NAME_RESDESC_ID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT_DESC)],
                                         where=cond)
        for i in xrange(0, len(entries)):
            RDid_list.append(entries[i][COL_NAME_RESDESC_ID])
        # Now we look for all the elements in VAL_Result having RDID. We take out the list of TRID.
        TRid_list = []
        for i in xrange(0, len(RDid_list)):
            cond = SQLBinaryExpr(RDid_list[i], OP_EQ, COL_NAME_RES_RESDESC_ID)
            entries = self.SelectGenericData(select_list=[COL_NAME_RES_TESTRUN_ID],
                                             table_list=[self.GetQualifiedTableName(TABLE_NAME_RESULT)],
                                             where=cond)
            for j in xrange(0, len(entries)):
                TRid_list.append(entries[j][COL_NAME_RES_TESTRUN_ID])
        # Finnally, we get the sw names using the TRID list
        TRid_list = list(set(TRid_list))
        pre_cond = SQLBinaryExpr(COL_NAME_TR_NAME, OP_EQ, SQLLiteral(test_run_name))
        for i in xrange(0, len(TRid_list)):
            cond1 = SQLBinaryExpr(TRid_list[i], OP_EQ, COL_NAME_TR_ID)
            cond = SQLBinaryExpr(pre_cond, OP_AND, cond1)
            entries = self.SelectGenericData(select_list=[COL_NAME_TR_CHECKPOINT],
                                             table_list=[self.GetQualifiedTableName(TABLE_NAME_TESTRUN)],
                                             where=cond)
            for j in xrange(0, len(entries)):
                SW_list.append(entries[j][COL_NAME_TR_CHECKPOINT])
        # done
        return SW_list

    #====================================================================
    # Interface helper functions
    #====================================================================
    def _GetNextID(self, table_name, col_name):
        """Get the next ID of a column
        :param table_name: The name of the table.
        :param col_name: The name of the column to get the next ID. The column type must be integral
        :return: Returns the next available ID.
        """
        sql_select_stmt = self.sql_factory.GetSelectBuilder()
        sql_select_stmt.select_list = [SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_MAX], col_name)]
        sql_select_stmt.table_list = [self.GetQualifiedTableName(table_name)]
        stmt = str(sql_select_stmt)
        # fetch max. signal_constraint_id
        next_id = 0
        cursor = self.db_connection.cursor()
        try:
            logging.debug(stmt)
            cursor.execute(stmt)
            row = cursor.fetchone()
            if (row is not None) and (row[0] is not None):
                next_id = int(row[0]) + 1
        finally:
            cursor.close()
        # done
        return next_id


#====================================================================
# Constraint DB Libary SQL Server Compact Implementation
#====================================================================
class SQLCEValResDB(BaseValResDB, SQLCEBaseDB):   # pylint: disable=R0904
    """SQL Server Compact Edition Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseValResDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLCEBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseValResDB.Initialize(self)
        SQLCEBaseDB.Initialize(self)


class OracleValResDB(BaseValResDB, OracleBaseDB):   # pylint: disable=R0904
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseValResDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        OracleBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseValResDB.Initialize(self)
        OracleBaseDB.Initialize(self)


class SQLite3ValResDB(BaseValResDB, SQLite3BaseDB):   # pylint: disable=R0904
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseValResDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLite3BaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseValResDB.Initialize(self)
        SQLite3BaseDB.Initialize(self)

"""
$Log: val.py  $
Revision 1.1 2021/12/13 17:56:55CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/val/project.pj
Revision 1.46 2013/12/09 18:05:52CET Ahmed, Zaheer (uidu7634) 
Added Tracking ID  Column def for Val_Assement table
- Added comments -  uidu7634 [Dec 9, 2013 6:05:53 PM CET]
Change Package : 210017:3 http://mks-psad:7002/im/viewissue?selection=210017
Revision 1.45 2013/12/05 15:57:05CET Ahmed-EXT, Zaheer (uidu7634) 
Improve GetDeletedTestrun function and fixed bugs
Revision 1.44 2013/11/28 12:32:42CET Ahmed-EXT, Zaheer (uidu7634)
Improve doc string
pep8 pylint fix
added new function GetDeletedTestRunIds()
--- Added comments ---  uidu7634 [Nov 28, 2013 12:32:42 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.43 2013/11/26 14:49:06CET Bratoi-EXT, Bogdan-Horia (uidu8192)
Project_id and filter implementation
--- Added comments ---  uidu8192 [Nov 26, 2013 2:49:07 PM CET]
Change Package : 193409:1 http://mks-psad:7002/im/viewissue?selection=193409
Revision 1.42 2013/10/31 17:26:57CET Ahmed-EXT, Zaheer (uidu7634)
Project Id column added into VAL_TESTRUN table changes made to support the coumn into db interface function
--- Added comments ---  uidu7634 [Oct 31, 2013 5:26:57 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.41 2013/09/09 16:38:41CEST Raedler, Guenther (uidt9430)
- return only valid testruns by default. As option, all TR could be returned.
--- Added comments ---  uidt9430 [Sep 9, 2013 4:38:41 PM CEST]
Change Package : 196718:1 http://mks-psad:7002/im/viewissue?selection=196718
Revision 1.40 2013/08/26 15:26:38CEST Ahmed-EXT, Zaheer (uidu7634)
Fixed ViewEvent column
--- Added comments ---  uidu7634 [Aug 26, 2013 3:26:38 PM CEST]
Change Package : 192688:1 http://mks-psad:7002/im/viewissue?selection=192688
Revision 1.39 2013/08/05 14:42:35CEST Raedler, Guenther (uidt9430)
- add new param cond to event view queries
- fixed cx_oracle failure when adding the path of a file as blop
--- Added comments ---  uidt9430 [Aug 5, 2013 2:42:36 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.38 2013/07/25 10:06:15CEST Raedler, Guenther (uidt9430)
- added new conditions to select testruns
--- Added comments ---  uidt9430 [Jul 25, 2013 10:06:16 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.37 2013/07/17 15:00:36CEST Raedler, Guenther (uidt9430)
- revert changes of BaseDB class
--- Added comments ---  uidt9430 [Jul 17, 2013 3:00:37 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.36 2013/07/15 13:58:27CEST Raedler, Guenther (uidt9430)
- added new column rdid into val_events table
--- Added comments ---  uidt9430 [Jul 15, 2013 1:58:27 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.35 2013/07/09 11:24:50CEST Raedler, Guenther (uidt9430)
- added new column rdid to val_events table
--- Added comments ---  uidt9430 [Jul 9, 2013 11:24:50 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.34 2013/07/04 15:01:49CEST Mertens, Sven (uidv7805)
providing tableSpace to BaseDB for what sub-schema space each module is intended to be responsible
--- Added comments ---  uidv7805 [Jul 4, 2013 3:01:49 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.33 2013/07/04 07:56:34CEST Bratoi, Bogdan-Horia (uidu8192)
- first results implementation
--- Added comments ---  uidu8192 [Jul 4, 2013 7:56:34 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.32 2013/06/05 16:20:01CEST Raedler, Guenther (uidt9430)
- fixed error when storing images to sqlite
- abort when a testrun exists for another user
- add new column class_name in function GetResultDescriptorWithId()
--- Added comments ---  uidt9430 [Jun 5, 2013 4:20:01 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.31 2013/05/02 09:15:51CEST Bratoi, Bogdan-Horia (uidu8192)
- update of GetTestrunCondition
--- Added comments ---  uidu8192 [May 2, 2013 9:15:51 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.30 2013/04/26 15:39:11CEST Mertens, Sven (uidv7805)
resolving some pep8 / pylint errors
--- Added comments ---  uidv7805 [Apr 26, 2013 3:39:12 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.29 2013/04/26 13:23:34CEST Mertens, Sven (uidv7805)
as row is specified to allow nulls, None type of Python should be able to reflect this
--- Added comments ---  uidv7805 [Apr 26, 2013 1:23:35 PM CEST]
Change Package : 180829:1 http://mks-psad:7002/im/viewissue?selection=180829
Revision 1.28 2013/04/26 10:46:02CEST Mertens, Sven (uidv7805)
moving strIdent
--- Added comments ---  uidv7805 [Apr 26, 2013 10:46:04 AM CEST]
Change Package : 179495:4 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.27 2013/04/25 14:37:14CEST Mertens, Sven (uidv7805)
epydoc adaptation to colon instead of at
--- Added comments ---  uidv7805 [Apr 25, 2013 2:37:14 PM CEST]
Change Package : 179495:2 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.26 2013/04/25 08:28:33CEST Bratoi, Bogdan-Horia (uidu8192)
- merging the 1.24 changes
--- Added comments ---  uidu8192 [Apr 25, 2013 8:28:33 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.25 2013/04/25 08:19:18CEST Bratoi, Bogdan-Horia (uidu8192)
- changes in GetAllTestruns - adding delete_status as parameter
--- Added comments ---  uidu8192 [Apr 25, 2013 8:19:18 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.21.1.1 2013/04/16 11:35:21CEST Raedler, Guenther (uidt9430)
- added new function GetResultTypeById()
- fixed some errors due to pylint fixes (usage of list)
- fixed some typos
--- Added comments ---  uidt9430 [Apr 16, 2013 11:35:22 AM CEST]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.21 2013/04/11 14:33:56CEST Ahmed-EXT, Zaheer (uidu7634)
Fixed bugs for SQLite db support for delete test run
--- Added comments ---  uidu7634 [Apr 11, 2013 2:33:57 PM CEST]
Change Package : 178419:2 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.20 2013/04/03 08:17:14CEST Mertens, Sven (uidv7805)
pep8: removing format errors
--- Added comments ---  uidv7805 [Apr 3, 2013 8:17:14 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.19 2013/04/03 08:02:17CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:18 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.18 2013/04/02 10:06:57CEST Raedler, Guenther (uidt9430)
- use logging for all log messages again
- use specific indeitifier names
- removed some pylint warnings
--- Added comments ---  uidt9430 [Apr 2, 2013 10:06:57 AM CEST]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.17 2013/03/28 15:25:14CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:14 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.16 2013/03/27 17:34:03CET Mertens, Sven (uidv7805)
id --> ident as id is a reserved word
--- Added comments ---  uidv7805 [Mar 27, 2013 5:34:04 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.15 2013/03/27 11:37:23CET Mertens, Sven (uidv7805)
pep8 & pylint: rowalignment and error correction
--- Added comments ---  uidv7805 [Mar 27, 2013 11:37:23 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.14 2013/03/27 09:04:33CET Mertens, Sven (uidv7805)
pylint: reorg of imports, rename of some variables
--- Added comments ---  uidv7805 [Mar 27, 2013 9:04:34 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.13 2013/03/26 16:19:27CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:27 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.12 2013/03/22 08:24:28CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
Revision 1.11 2013/03/21 17:22:36CET Mertens, Sven (uidv7805)
solving some pylint warnings / errors
--- Added comments ---  uidv7805 [Mar 21, 2013 5:22:36 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/03/21 16:25:29CET Hecker, Robert (heckerr)
Added needed parameters, because class_name is not all the time unique.
--- Added comments ---  heckerr [Mar 21, 2013 4:25:29 PM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/03/08 08:39:19CET Raedler, Guenther (uidt9430)
- fixed module test errors
--- Added comments ---  uidt9430 [Mar 8, 2013 8:39:19 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.8 2013/03/07 07:19:43CET Raedler, Guenther (uidt9430)
- replaced id with tr_id for all testrun related methods
- support delete flag and lock flag for testruns
- merged latest changes from etk/adas_db
- fixed some pep8 warnings
--- Added comments ---  uidt9430 [Mar 7, 2013 7:19:43 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.7 2013/03/02 20:50:20CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 2, 2013 8:50:20 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/03/01 18:41:19CET Hecker, Robert (heckerr)
Updated regarding Pep8 Styleguide.
--- Added comments ---  heckerr [Mar 1, 2013 6:41:24 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/27 19:57:33CET Hecker, Robert (heckerr)
Update regarding Pep8 (partly)
--- Added comments ---  heckerr [Feb 27, 2013 7:57:33 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/26 20:10:26CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:10:26 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.3 2013/02/26 16:15:08CET Raedler, Guenther (uidt9430)
- renamed relts in absts
- raise error if id is not an integer (support module test)
- don't mix up return of list and dict for event related methods
- removed testcode
--- Added comments ---  uidt9430 [Feb 26, 2013 4:15:08 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/19 14:07:33CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:33 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 09:59:38CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/db/val/project.pj
------------------------------------------------------------------------------
-- From ETK/ADAS_DB Archive
------------------------------------------------------------------------------
Revision 1.56 2012/11/26 14:49:46CET Bratoi, Bogdan-Horia (uidu8192)
- removed GetResultId function
- added an parameter to GetEventImagePlotSeq function
--- Added comments ---  uidu8192 [Nov 26, 2012 2:49:47 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.55 2012/11/26 11:02:07CET Bratoi, Bogdan-Horia (uidu8192)
- small bug fix
--- Added comments ---  uidu8192 [Nov 26, 2012 11:02:07 AM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.54 2012/11/26 10:08:50CET Bratoi, Bogdan-Horia (uidu8192)
- changed the GetEventImagePlotSeq function
--- Added comments ---  uidu8192 [Nov 26, 2012 10:08:52 AM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.53 2012/11/23 12:20:11CET Bratoi, Bogdan-Horia (uidu8192)
- Changes in the GetFilteredEventTypesDetailsAttributesAssessment function
--- Added comments ---  uidu8192 [Nov 23, 2012 12:20:11 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.52 2012/11/22 14:51:17CET Hammernik-EXT, Dmitri (uidu5219)
- changed default measid when adding new result without definiton for measid
--- Added comments ---  uidu5219 [Nov 22, 2012 2:51:20 PM CET]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.51 2012/11/15 09:54:38CET Hammernik-EXT, Dmitri (uidu5219)
- bugfixes in delete histogramm and read histogramm in/from database
- defined new function GetResultId
- removed commets in UpdateResult
- bugfix delete testrun -> added function to delete message
--- Added comments ---  uidu5219 [Nov 15, 2012 9:54:40 AM CET]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.50 2012/11/06 15:36:35CET Bratoi, Bogdan-Horia (uidu8192)
-bugfix in GetEventDetailsAttributes
--- Added comments ---  uidu8192 [Nov 6, 2012 3:36:35 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.49 2012/11/06 15:13:43CET Bratoi, Bogdan-Horia (uidu8192)
- added UpdateEvent Attribute method and changed GetEventAttributeId
--- Added comments ---  uidu8192 [Nov 6, 2012 3:13:45 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.48 2012/11/06 09:04:08CET Hammernik-EXT, Dmitri (uidu5219)
- changed AddEventAttribute method
- small changes
--- Added comments ---  uidu5219 [Nov 6, 2012 9:04:14 AM CET]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.47 2012/11/05 13:47:47CET Bratoi, Bogdan-Horia (uidu8192)
- added some functions and updates of the filtering feature for the assessment tool
--- Added comments ---  uidu8192 [Nov 5, 2012 1:47:50 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.46 2012/10/23 14:32:50CEST Bratoi, Bogdan-Horia (uidu8192)
- updated the filter implementation of the Assessment tool
--- Added comments ---  uidu8192 [Oct 23, 2012 2:32:55 PM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.44 2012/10/16 18:03:29CEST Hammernik-EXT, Dmitri (uidu5219)
- bugfix: deleting of the assessment was changed
- column COL_NAME_ASS_ASSESSMENT was changed in COL_NAME_ASS_ASSSTID
--- Added comments ---  uidu5219 [Oct 16, 2012 6:03:29 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.43 2012/10/10 19:31:44CEST Hammernik-EXT, Dmitri (uidu5219)
- added new function for val_view_events_attributes
- renamed some columnames
--- Added comments ---  uidu5219 [Oct 10, 2012 7:31:47 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.42 2012/10/10 10:18:11CEST Hammernik-EXT, Dmitri (uidu5219)
- bugfixes: changed columnames for views
--- Added comments ---  uidu5219 [Oct 10, 2012 10:18:12 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.41 2012/10/09 14:29:22CEST Hammernik-EXT, Dmitri (uidu5219)
- added functionality to add an event image
- bugfixes: primery/foreign key of a table could be of type integer, float, long
- improved functions for accessing val tables with val_gui
--- Added comments ---  uidu5219 [Oct 9, 2012 2:29:24 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.38.1.11 2012/07/18 08:52:21CEST Hammernik-EXT, Dmitri (uidu5219)
- bugfixes in Assessment, Eventdetails and Events table methods
--- Added comments ---  uidu5219 [Jul 18, 2012 8:52:21 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.38.1.10 2012/07/02 14:20:42CEST Hammernik-EXT, Dmitri (uidu5219)
- changed val_assessment methods
- bugfixes
--- Added comments ---  uidu5219 [Jul 2, 2012 2:20:43 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.38.1.9 2012/06/29 10:58:06CEST Spruck, Jochen (spruckj)
add test run id for if event is added
--- Added comments ---  spruckj [Jun 29, 2012 10:58:06 AM CEST]
Change Package : 98074:5 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.38.1.8 2012/06/18 14:42:28CEST Spruck, Jochen (spruckj)
Some small bug fixes du to introduction of events
--- Added comments ---  spruckj [Jun 18, 2012 2:42:28 PM CEST]
Change Package : 98074:3 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.38.1.7 2012/06/05 14:10:24CEST Hammernik-EXT, Dmitri (uidu5219)
- bugfixes
--- Added comments ---  uidu5219 [Jun 5, 2012 2:10:25 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.38.1.6 2012/06/01 13:55:46CEST Spruck, Jochen (spruckj)
Change during renaming EventType to ResultType
--- Added comments ---  spruckj [Jun 1, 2012 1:55:46 PM CEST]
Change Package : 98074:3 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.38.1.5 2012/05/30 08:50:28CEST Hammernik-EXT, Dmitri (uidu5219)
- added function for update event
- added functions to add/ get/ update assessment
--- Added comments ---  uidu5219 [May 30, 2012 8:50:30 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.38.1.2 2012/05/15 10:36:42CEST Hammernik-EXT, Dmitri (uidu5219)
update
--- Added comments ---  uidu5219 [May 15, 2012 10:36:42 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.38 2012/03/06 16:20:39CET Raedler-EXT, Guenther (uidt9430)
- extended interface to get result values by descriptor id
--- Added comments ---  uidt9430 [Mar 6, 2012 4:20:39 PM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.37 2012/03/05 10:38:06CET Raedler-EXT, Guenther (uidt9430)
- fixed error for functions returning the id when adding items
--- Added comments ---  uidt9430 [Mar 5, 2012 10:38:06 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.36 2012/03/02 11:51:01CET Raedler-EXT, Guenther (uidt9430)
- use trigger for road events
- fixed error in GetListOfResults()
- removed GetArrayOfResultValues() as not needed
--- Added comments ---  uidt9430 [Mar 2, 2012 11:51:01 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.35 2012/03/02 09:28:03CET Farcas-EXT, Florian Radu (uidu4753)
Added return value for functions that don't use GetNextID()
--- Added comments ---  uidu4753 [Mar 2, 2012 9:28:03 AM CET]
Change Package : 100437:1 http://mks-psad:7002/im/viewissue?selection=100437
Revision 1.34 2012/03/01 14:00:05CET Ibrouchene-EXT, Nassim (uidt5589)
Updated road event functions.
--- Added comments ---  uidt5589 [Mar 1, 2012 2:00:06 PM CET]
Change Package : 94467:1 http://mks-psad:7002/im/viewissue?selection=94467
Revision 1.33 2012/02/28 16:41:38CET Farcas-EXT, Florian Radu (uidu4753)
Update DB interface
--- Added comments ---  uidu4753 [Feb 28, 2012 4:41:38 PM CET]
Change Package : 100439:1 http://mks-psad:7002/im/viewissue?selection=100439
Revision 1.32 2012/02/07 16:34:02CET Raedler-EXT, Guenther (uidt9430)
- changed interface to support new column in VAL_Testrun
--- Added comments ---  uidt9430 [Feb 7, 2012 4:34:02 PM CET]
Change Package : 88154:1 http://mks-psad:7002/im/viewissue?selection=88154
Revision 1.31 2012/02/07 12:02:33CET Raedler Guenther (uidt9430) (uidt9430)
- cast new ID as integer value
Revision 1.30 2011/12/01 11:36:35CET Farcas-EXT, Florian Radu (uidu4753)
Corrected a typo in the name of AddResultDescriptor function
--- Added comments ---  uidu4753 [Dec 1, 2011 11:36:36 AM CET]
Change Package : 83163:1 http://mks-psad:7002/im/viewissue?selection=83163
Revision 1.29 2011/12/01 11:30:04CET Farcas-EXT, Florian Radu (uidu4753)
Added DB access functions for KEYS and CONSTRAINTSMAP tables
--- Added comments ---  uidu4753 [Dec 1, 2011 11:30:05 AM CET]
Change Package : 83163:1 http://mks-psad:7002/im/viewissue?selection=83163
Revision 1.28 2011/11/15 15:51:49CET Raedler-EXT, Guenther (uidt9430)
-- extension to delete of testrun recursively (by given parent id)
-- support to delete road events
--- Added comments ---  uidt9430 [Nov 15, 2011 3:51:50 PM CET]
Change Package : 76661:1 http://mks-psad:7002/im/viewissue?selection=76661
Revision 1.27 2011/10/19 08:17:32CEST Raedler Guenther (uidt9430) (uidt9430)
- reduce image filename if it exceeds the limit of 60 characters
--- Added comments ---  uidt9430 [Oct 19, 2011 8:17:32 AM CEST]
Change Package : 78376:5 http://mks-psad:7002/im/viewissue?selection=78376
Revision 1.26 2011/10/18 11:55:59CEST Ibrouchene Nassim (uidt5589) (uidt5589)
Updated the name of the road events table
--- Added comments ---  uidt5589 [Oct 18, 2011 11:56:00 AM CEST]
Change Package : 78373:1 http://mks-psad:7002/im/viewissue?selection=78373
Revision 1.25 2011/10/10 11:18:50CEST Raedler Guenther (uidt9430) (uidt9430)
- store format of image into DB
--- Added comments ---  uidt9430 [Oct 10, 2011 11:18:51 AM CEST]
Change Package : 78376:6 http://mks-psad:7002/im/viewissue?selection=78376
Revision 1.24 2011/09/22 13:24:16CEST Raedler Guenther (uidt9430) (uidt9430)
- fixed error if no image could be loaded
--- Added comments ---  uidt9430 [Sep 22, 2011 1:24:16 PM CEST]
Change Package : 78376:3 http://mks-psad:7002/im/viewissue?selection=78376
Revision 1.23 2011/09/09 08:16:05CEST Spruck Jochen (spruckj) (spruckj)
Get also the validation results wiht option res_id
--- Added comments ---  spruckj [Sep 9, 2011 8:16:05 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.22 2011/09/07 08:11:58CEST Raedler Guenther (uidt9430) (uidt9430)
-- return emtpy list if descriptor is not defined
--- Added comments ---  uidt9430 [Sep 7, 2011 8:11:59 AM CEST]
Change Package : 67780:6 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.21 2011/09/06 10:24:32CEST Spruck Jochen (spruckj) (spruckj)
Add GetResulsDescriptorChildList funktion
--- Added comments ---  spruckj [Sep 6, 2011 10:24:32 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.20 2011/09/05 12:49:08CEST Castell Christoph (uidt6394) (uidt6394)
Fixed bug with COL_NAME_ACC_A_OBJ_EVENT_ROM_EVRECTOBJMAPID.
--- Added comments ---  uidt6394 [Sep 5, 2011 12:49:08 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.19 2011/09/05 11:01:11CEST Castell Christoph (uidt6394) (uidt6394)
Added ACC tabel definitions.
--- Added comments ---  uidt6394 [Sep 5, 2011 11:01:11 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.18 2011/09/02 07:52:28CEST Raedler Guenther (uidt9430) (uidt9430)
-- replaced warning by error messsage changed the message text in GetResultDescriptor()
--- Added comments ---  uidt9430 [Sep 2, 2011 7:52:28 AM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.17 2011/09/01 09:06:36CEST Raedler Guenther (uidt9430) (uidt9430)
-- added documentation
--- Added comments ---  uidt9430 [Sep 1, 2011 9:06:36 AM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.16 2011/08/30 09:39:29CEST Spruck Jochen (spruckj) (spruckj)
-Add function to get Result descriptor main values function for rd_id
-Add function to add Result values with parameter rd_id
--- Added comments ---  spruckj [Aug 30, 2011 9:39:29 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.15 2011/08/30 09:20:56CEST Castell Christoph (uidt6394) (uidt6394)
Added support for ResultMessages and Histograms.
--- Added comments ---  uidt6394 [Aug 30, 2011 9:20:56 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.14 2011/08/29 17:29:52CEST Castell Christoph (uidt6394) (uidt6394)
Layout changes.
--- Added comments ---  uidt6394 [Aug 29, 2011 5:29:52 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.12 2011/08/25 17:04:45CEST Ibrouchene Nassim (uidt5589) (uidt5589)
fixed some import issues used for the road estimation.
--- Added comments ---  uidt5589 [Aug 25, 2011 5:04:45 PM CEST]
Change Package : 69072:2 http://mks-psad:7002/im/viewissue?selection=69072
Revision 1.11 2011/08/25 14:49:12CEST Ibrouchene Nassim (uidt5589) (uidt5589)
Updated the functions used for the road estimation
--- Added comments ---  uidt5589 [Aug 25, 2011 2:49:12 PM CEST]
Change Package : 69072:2 http://mks-psad:7002/im/viewissue?selection=69072
Revision 1.10 2011/08/11 10:52:42CEST Raedler Guenther (uidt9430) (uidt9430)
-- added some checks
--- Added comments ---  uidt9430 [Aug 11, 2011 10:52:42 AM CEST]
Change Package : 67780:5 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.9 2011/08/02 12:32:18CEST Castell Christoph (uidt6394) (uidt6394)
Added HasHistoram() and DeleteHistogram() functions.
--- Added comments ---  uidt6394 [Aug 2, 2011 12:32:19 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.8 2011/08/01 12:37:45CEST Castell Christoph (uidt6394) (uidt6394)
Fixed GetHistogram() function.
--- Added comments ---  uidt6394 [Aug 1, 2011 12:37:45 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.7 2011/08/01 11:32:02CEST Castell Christoph (uidt6394) (uidt6394)
Added Histogram table and Road tables from Nassim.
--- Added comments ---  uidt6394 [Aug 1, 2011 11:32:03 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.6 2011/07/28 10:59:05CEST Raedler Guenther (uidt9430) (uidt9430)
-- updated methods
-- support storage and laod of result arrays
--- Added comments ---  uidt9430 [Jul 28, 2011 10:59:06 AM CEST]
Change Package : 67780:5 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.5 2011/07/19 16:28:12CEST Raedler Guenther (uidt9430) (uidt9430)
-- fixed some errors
Revision 1.4 2011/07/19 16:25:38CEST Raedler Guenther (uidt9430) (uidt9430)
-- fixed some errors
Revision 1.3 2011/07/19 16:08:17CEST Raedler Guenther (uidt9430) (uidt9430)
-- added support of tesrun replace
Revision 1.2 2011/07/19 09:42:10CEST Raedler Guenther (uidt9430) (uidt9430)
- updated interface functions
- fixed errors
--- Added comments ---  uidt9430 [Jul 19, 2011 9:42:10 AM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.1 2011/07/01 07:07:09CEST Raedler Guenther (uidt9430) (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/EM_EnvironmentModel/05_Testing/05_Test_Environment/algo/em_req_test/valf_tests/
    adas_database/val/project.pj
"""
