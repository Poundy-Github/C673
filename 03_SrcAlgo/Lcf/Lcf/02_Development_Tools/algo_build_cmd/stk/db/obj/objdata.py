"""
stk/db/obj/objdata.py
-------------------

Classes for Database access of Object Labels for ACC.

 Sub-Scheme OBJ

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:39CET $
"""

# pylint: disable=C0103

# Import Python Modules ----------------------------------------------------------------------------------------------
import logging
import sys

# Import STK Modules -------------------------------------------------------------------------------------------------
from ..db_common import BaseDB, ERROR_TOLERANCE_NONE, DB_FUNC_NAME_MIN, DB_FUNC_NAME_MAX, DB_FUNC_NAME_LOWER, \
    DB_FUNC_NAME_UPPER, AdasDBNotImplemented, AdasDBError, SQLCEBaseDB, OracleBaseDB, SQLite3BaseDB
from ..db_sql import GenericSQLStatementFactory, SQLBinaryExpr, OP_EQ, SQLLiteral, OP_GT, OP_AND, OP_LT, \
    SQLColumnExpr, SQLTableExpr, SQLTernaryExpr, OP_INNER_JOIN, OP_ON, OP_LEQ, OP_GEQ, OP_BETWEEN, OP_OR, \
    SQLFuncExpr, OP_AS, OP_NOP, OP_USING


# Defines ------------------------------------------------------------------------------------------------------------

DEFAULT_ADMA_NAME = "adma"
LBL_STATE_UNLABLED = "unlabeled"
LBL_STATE_AUTO = "auto"
LBL_STATE_MANUAL = "manual"
LBL_STATE_REVIEWED = "reviewed"

#======================================================================================================================
# Table Definitions
#======================================================================================================================

# OBJ table names.
TABLE_NAME_ACC_LANE_REL = "OBJ_ACCLANERELATION"
TABLE_NAME_ACC_LANE_TYPES = "OBJ_ACCLANETYPES"
# TABLE_NAME_ADMIN_ATTRIB_STATES = "OBJ_ADMINATTRIBSTATES"
# TABLE_NAME_ADMINISTRATION = "OBJ_ADMINISTRATION"
TABLE_NAME_ASSOC_TYPE = "OBJ_ASSOCIATIONTYPES"
TABLE_NAME_OBJECT_CLASS = "OBJ_CLASSTYPES"
TABLE_NAME_DOCU_CAM_CALIB = "OBJ_DOCUCAMCALIB"
TABLE_NAME_EGO_KINEMATICS = "OBJ_EGOKINEMATICS"
TABLE_NAME_EGO_KINEMATICS_ADMA = "OBJ_EGOKINEMATICS_ADMA"
TABLE_NAME_KINEMATICS = "OBJ_KINEMATICS"
TABLE_NAME_ADMA_KINEMATICS = "OBJ_KINEMATICSADMA"
TABLE_NAME_OBJ_LBL_STATE = "OBJ_LBLSTATE"
TABLE_NAME_PROBS_CAM = "OBJ_PROBS_CAM"
TABLE_NAME_RECTANGULAR_OBJECT = "OBJ_RECTANGULAROBJECT"
TABLE_NAME_TEST_CASES = "OBJ_TESTCASES"
TABLE_NAME_TEST_CASE_TYPE = "OBJ_TESTCASETYPE"
TABLE_NAME_EGO_MOTION = "OBJ_EGOMOTION"

#======================================================================================================================
# Table Column definitions
#======================================================================================================================

# TABLE_NAME_RECTANGULAR_OBJECT = "OBJ_RectangularObject"
COL_NAME_RECT_OBJ_RECTOBJID = "RECTOBJID"
COL_NAME_RECT_OBJ_MEASID = "MEASID"
COL_NAME_RECT_OBJ_ASSOCTYPEID = "ASSOCTYPEID"
COL_NAME_RECT_OBJ_RECTOBJ_IS_DELETED = "RECTOBJ_IS_DELETED"
COL_NAME_RECT_OBJ_OBJCLASSID = "CLSID"
COL_NAME_RECT_OBJ_CLSLBLSTATEID = "CLSLBLSTATEID"
COL_NAME_RECT_OBJ_CLSLBLTIME = "CLSLBLTIME"
COL_NAME_RECT_OBJ_CLSLBLBY = "CLSLBLBY"
COL_NAME_RECT_OBJ_OBJWIDTH = "OBJWIDTH"
COL_NAME_RECT_OBJ_OBJLENGTH = "OBJLENGTH"
COL_NAME_RECT_OBJ_OBJHEIGHT = "OBJHEIGHT"
COL_NAME_RECT_OBJ_DIMLBLSTATEID = "DIMLBLSTATEID"
COL_NAME_RECT_OBJ_DIMLBLTIME = "DIMLBLTIME"
COL_NAME_RECT_OBJ_DIMLBLBY = "DIMLBLBY"
COL_NAME_RECT_OBJ_ZLAYER = "ZLAYER"
COL_NAME_RECT_OBJ_ZOVERGROUND = "ZOVERGROUND"
COL_NAME_RECT_OBJ_ZOLBLSTATEID = "ZOLBLSTATEID"
COL_NAME_RECT_OBJ_ZOLBLBY = "ZOLBLBY"
COL_NAME_RECT_OBJ_ZOLBLTIME = "ZOLBLTIME"
COL_NAME_RECT_OBJ_KINLBLSTATEID = "KINLBLSTATEID"
COL_NAME_RECT_OBJ_KINLBLMODTIME = "KINLBLTIME"
COL_NAME_RECT_OBJ_LBLBY = "KINLBLBY"

# TABLE_NAME_EGO_KINEMATICS = "Obj_EgoKinematics"
COL_NAME_EGO_KINEMATICS_MEASID = "MEASID"
COL_NAME_EGO_KINEMATICS_KINABSTS = "KINABSTS"
COL_NAME_EGO_KINEMATICS_VELOCITY = "VELOCITY"
COL_NAME_EGO_KINEMATICS_ACCELERATION = "ACCELERATION"
COL_NAME_EGO_KINEMATICS_YAWRATE = "YAWRATE"
COL_NAME_EGO_KINEMATICS_RADARCYCLEID = "RADARCYCLEID"

# TABLE_NAME_KINEMATICS = "Obj_Kinematics"
COL_NAME_KINEMATICS_KINABSTS = "KINABSTS"
COL_NAME_KINEMATICS_RECTOBJID = "RECTOBJID"
COL_NAME_KINEMATICS_RELDISTX = "RELDISTX"
COL_NAME_KINEMATICS_RELDISTY = "RELDISTY"
COL_NAME_KINEMATICS_RELVELX = "RELVELX"
COL_NAME_KINEMATICS_HEADINGOVERGND = "HEADINGOVERGND"

# TABLE_NAME_ADMA_KINEMATICS = "Obj_KinematicsADMA"
COL_NAME_ADMA_KINEMATICS_RECTOBJID = "RECTOBJID"
COL_NAME_ADMA_KINEMATICS_KINABSTS = "KINABSTS"
COL_NAME_ADMA_KINEMATICS_RELDISTX = "RELDISTX"
COL_NAME_ADMA_KINEMATICS_RELDISTY = "RELDISTY"
COL_NAME_ADMA_KINEMATICS_RELVELX = "RELVELX"
COL_NAME_ADMA_KINEMATICS_RELVELY = "RELVELY"
COL_NAME_ADMA_KINEMATICS_ARELX = "RELACCELX"
COL_NAME_ADMA_KINEMATICS_ARELY = "RELACCELY"
COL_NAME_ADMA_KINEMATICS_HEADINGOG = "HEADINGOVERGND"
COL_NAME_ADMA_KINEMATICS_ADMAOK = "ADMAVALID"

# TABLE_NAME_ASSOC_TYPE = "OBJ_AssociationTypes"
COL_NAME_ASSOC_TYPE_ASSOCTYPEID = "ASSOCTYPEID"
COL_NAME_ASSOC_TYPE_NAME = "NAME"
COL_NAME_ASSOC_TYPE_DESC = "DESCRIPTION"

# TABLE_NAME_TEST_CASES = "OBJ_TestCase"
COL_NAME_TEST_CASES_TESTCASEID = "TESTCASEID"
COL_NAME_TEST_CASES_TYPEID = "TESTCASETYPEID"
COL_NAME_TEST_CASES_RECTOBJID = "RECTOBJID"
COL_NAME_TEST_CASES_BEGINABSTS = "BEGINABSTS"
COL_NAME_TEST_CASES_ENDABSTS = "ENDABSTS"
COL_NAME_TEST_CASES_LBLSTATEID = "LBLSTATEID"
COL_NAME_TEST_CASES_LBLMODTIME = "LBLMODTIME"
COL_NAME_TEST_CASES_LBLBY = "LBLBY"

# TABLE_NAME_ACC_LANE_REL = "OBJ_AccLaneRelation"
COL_NAME_ACC_LANE_REL_ACCLANERELID = "ACCLANERELID"
COL_NAME_ACC_LANE_REL_RECTOBJID = "RECTOBJID"
COL_NAME_ACC_LANE_REL_BEGINABSTS = "BEGINABSTS"
COL_NAME_ACC_LANE_REL_ENDABSTS = "ENDABSTS"
COL_NAME_ACC_LANE_REL_LANEID = "LANEID"
COL_NAME_ACC_LANE_REL_LANEASSOCWEIGHT = "LANEASSOCWEIGHT"
COL_NAME_ACC_LANE_REL_LBLSTATEID = "LBLSTATEID"
COL_NAME_ACC_LANE_REL_LBLMODTIME = "LBLMODTIME"
COL_NAME_ACC_LANE_REL_LBLBY = "LBLBY"

# TABLE_NAME_TEST_CASE_TYPE = "OBJ_TestCaseType"
COL_NAME_TEST_CASE_TYPE_ID = "TESTCASETYPEID"
COL_NAME_TEST_CASE_TYPE_NAME = "NAME"
COL_NAME_TEST_CASE_TYPE_DESCRIPTION = "DESCRIPTION"

# TABLE_NAME_OBJ_LBL_STATE = "OBJ_LBLSTATE"
COL_NAME_LBL_STATE_LBL_STATE_ID = "LBLSTATEID"
COL_NAME_LBL_STATE_NAME = "NAME"
COL_NAME_LBL_STATE_DESCRIPTION = "DESCRIPTION"

# TABLE_NAME_ACC_LANE_TYPES = "OBJ_ACCLANETYPES"
COL_NAME_LANE_TYPES_LANE_ID = "LANEID"
COL_NAME_LANE_TYPES_LANE_NAME = "LANENAME"
COL_NAME_LANE_TYPES_DESCRIPTION = "DESCRIPTION"

# TABLE_NAME_OBJECT_CLASS = "OBJ_CLASSTYPES"
COL_NAME_OBJECT_CLASS_CLS_ID = "CLSID"
COL_NAME_OBJECT_CLASS_CLASS_NAME = "CLASSNAME"
COL_NAME_OBJECT_CLASS_DESCRIPTION = "DESCRIPTION"

# TABLE_NAME_EGO_KINEMATICS_ADMA = "OBJ_EGOKINEMATICS_ADMA"
COL_NAME_EGO_ADMA_MEASID = "MEASID"
COL_NAME_EGO_ADMA_KINABSTS = "KINABSTS"
COL_NAME_EGO_ADMA_VELOCITY_X = "VELOCITY_X"
COL_NAME_EGO_ADMA_VELOCITY_Y = "VELOCITY_Y"
COL_NAME_EGO_ADMA_VELOCITY_Z = "VELOCITY_Z"
COL_NAME_EGO_ADMA_ACCELERATION = "ACCELERATION"
COL_NAME_EGO_ADMA_YAWRATE = "YAWRATE"
COL_NAME_EGO_ADMA_PITCH = "PITCH"
COL_NAME_EGO_ADMA_ROLL = "ROLL"
COL_NAME_EGO_ADMA_SUMDIST = "SUMDIST"
COL_NAME_EGO_ADMA_SUMYAW = "SUMYAW"

# TABLE_NAME_PROBS_CAM = "OBJ_PROBS_CAM"
COL_NAME_PROBSCAM_ABSTS = "ABSTS"
COL_NAME_PROBSCAM_RECTOBJID = "RECTOBJID"
COL_NAME_PROBSCAM_OCCLUDED = "OCCLUDED"

COL_NAME_BEGIN_TS = "BeginAbsTS"
COL_NAME_END_TS = "EndAbsTS"

PATH_SEPARATOR = "/"

# Test cases
TEST_CASE_TYPE_APPROACH = "approach"
TEST_CASE_TYPE_CUTIN = "cutin"
TEST_CASE_TYPE_CUTOUT = "cutout"

IDENT_STRING = "dbobj"


class BaseObjDataDB(BaseDB):
    """Base implementation of the OBJ Data Database"""
    #====================================================================
    # Constraint DB Libary Interface for public use
    #====================================================================

    #====================================================================
    # Handling of database
    #====================================================================
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize constraint database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseDB.__init__(self, db_connection, table_prefix, sql_factory, IDENT_STRING)
        self.sync_slave_reload_all = False
        self.error_tolerance = error_tolerance
        # self.__logger = Logger(self.__class__.__name__)

        self.__object_map = {}

    def Initialize(self):
        """Initialize the database proxy"""
        # Setup function names
        BaseDB.Initialize(self)
        self.db_func_map[DB_FUNC_NAME_MIN] = "MIN"
        self.db_func_map[DB_FUNC_NAME_MAX] = "MAX"
        self.db_func_map[DB_FUNC_NAME_LOWER] = "LOWER"
        self.db_func_map[DB_FUNC_NAME_UPPER] = "UPPER"

    def Terminate(self):
        """Terminate the database proxy"""
        BaseDB.Terminate(self)

    def AddAdmaKinematics(self, adma_kin_map):
        """
        Add a new set of data into the ADMAObjKinematics table.
        """
        try:
            self.AddGenericData(adma_kin_map, self.GetQualifiedTableName(TABLE_NAME_ADMA_KINEMATICS))
        except (StandardError):
            logging.error(str(StandardError))
            return False

        return True

    def AddTestCase(self, rect_obj_id, test_case_type, begin_ts, end_ts, user_id, lb_state=LBL_STATE_AUTO):
        """ Add a test case to the OBJ_TestCases table.
        :param rect_obj_i: The rectangular object id.
        :param test_case_type: The test case type.
        :param begin_ts: The start time.
        :param end_ts: The end time.
        :param user_id: User according global user table
        """
        if self.HasTestCase(rect_obj_id, test_case_type):
            logging.warning("AddTestCase() failed as rect object has a test case.")
            return

        test_case_type_id = self.GetTestCaseTypeID(test_case_type)
        label_state_id = self.GetLabelStateId(lb_state)
        # userid           =  self.GetUser(login = os.environ["USERNAME"])

        test_case_map = {}
        tcid = self.__GetNextID(TABLE_NAME_TEST_CASES, COL_NAME_TEST_CASES_TESTCASEID)
        test_case_map[COL_NAME_TEST_CASES_TESTCASEID] = tcid
        test_case_map[COL_NAME_TEST_CASES_TYPEID] = test_case_type_id
        test_case_map[COL_NAME_TEST_CASES_RECTOBJID] = rect_obj_id
        test_case_map[COL_NAME_TEST_CASES_BEGINABSTS] = begin_ts
        test_case_map[COL_NAME_TEST_CASES_ENDABSTS] = end_ts
        test_case_map[COL_NAME_TEST_CASES_LBLSTATEID] = label_state_id
        test_case_map[COL_NAME_TEST_CASES_LBLBY] = user_id
#       TimeStamp for LBLMODTIME will be current Time by default from Database

        try:
            self.AddGenericData(test_case_map, self.GetQualifiedTableName(TABLE_NAME_TEST_CASES))
            self.Commit()
        except (StandardError):
            logging.error(str(StandardError))
            sys.exit(-1)
        return tcid

    def AddObservationTime(self, observation_time):
        """Add new observation time to database.
        :param observation_time: The observation time record.
        :return: Returns the object relation ID.
        """
        """
        observation_time[COL_NAME_OBSERVATIONTIMEID] = self.__get_next_observation_time_id()
        self.SelectGenericData(observation_time, self.GetQualifiedTableName(TABLE_NAME_OBSERVATION_TIME))

        return observation_time[COL_NAME_OBSERVATIONTIMEID]
        """
        raise AdasDBNotImplemented()

    def AddObjectKinematicState(self, kinematic_state):
        """Add new object kinematic state to database.
        :param kinematic_state: The object kinematgic state record.
        :return: Returns the object relation ID.
        """
        """
        self.AddGenericData(kinematic_state, self.GetQualifiedTableName(TABLE_NAME_OBJECT_KINEMATIC_STATE))
        return (kinematic_state[COL_NAME_RECTOBJID], kinematic_state[COL_NAME_TIMESTAMP])
        """
        raise AdasDBNotImplemented()

    def AddRectangularObject(self, obj):
        """Adds new object to database.
        :param obj: The general object record.
        :return: Returns the object ID.
        """
        try:
            db_object_id = self.__GetDbRectObjectId(obj[COL_NAME_RECT_OBJ_RECTOBJID])
            if db_object_id is not None:
                return db_object_id
        except:
            pass

        object_id = self.__GetNextRectObjectId()
        try:
            self.__object_map[obj[COL_NAME_RECT_OBJ_RECTOBJID]] = object_id
        except:
            pass

        obj[COL_NAME_RECT_OBJ_RECTOBJID] = object_id
        self.AddGenericData(obj, self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT))

        # done
        return object_id

    def addEgoKinematicsAdma(self, adma):
        """adds a new entry to table OBJ_EGOKINEMATICS_ADMA
        :param adma: adma data to be added (dict of values)
        :return: success status (True/False)
        """
        return self.__addSimpleData(TABLE_NAME_EGO_KINEMATICS_ADMA, adma)

    def addProbsCam(self, prob):
        """adds a new entry to table OBJ_PROBS_CAM
        :param prob: camera properties to be added (dict of values)
        :return: success status (True/False)
        """
        return self.__addSimpleData(TABLE_NAME_PROBS_CAM, prob)

    def __addSimpleData(self, table, data):
        """adds data to a table without the need for additional checks
        :param table: name of table
        :param data: dict of data
        """
        try:
            stmt = "INSERT INTO %s (" % table
            cols = []
            vals = []
            for kk in data.keys():
                cols.append(kk)
                vals.append(str(data[kk]) if type(data[kk]) != str else ("'%s'" % data[kk]))
            stmt += ", ".join(cols) + ") VALUES (" + ", ".join(vals) + ")"
            return self.execute(stmt) > 0
        except:
            return False

    def DeleteAdmaKinematics(self, rect_obj_id):
        """ Deletes a data range form the AdmaObjKinematics table based on RECTOBJID.
        :param rect_obj_id: The identiyer of the rectangular object.
        """
        condition = SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_RECTOBJID, OP_EQ, SQLLiteral(rect_obj_id))
        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_ADMA_KINEMATICS), condition)
        return rowcount

    def DeleteAdmaKinRectObj(self, rectobj_id):
        """ Deletes a RECTOBJID. Confirms that the rectangular object is of kinematic type before deletion.
        :param rect_obj_id: The identiyer of the rectangular object.
        """
        kin_table = self.GetRectObjectKinematics(rectobj_id)

        if len(kin_table) > 0:
            logging.error("Error: Failed to delete kinematics prior to rect obj delete. '%s'." % rectobj_id)
            sys.exit(0)

        condition = SQLBinaryExpr(COL_NAME_RECT_OBJ_RECTOBJID, OP_EQ, SQLLiteral(rectobj_id))
        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT), condition)
        return rowcount

    def GetAdmaKinRange(self, kinabsts1, kinabsts2, select_list=['*']):
        """ Selects a data range form the AdmaObjKinematics table based on KINABSTS.
        """
        condition = SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_KINABSTS,
                                  OP_GT, SQLLiteral(kinabsts1))
        condition = SQLBinaryExpr(condition, OP_AND,
                                  SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_KINABSTS, OP_LT, SQLLiteral(kinabsts2)))

        adma_obj_kinematics_list = self.SelectGenericData(select_list,
                                                          [self.GetQualifiedTableName(TABLE_NAME_ADMA_KINEMATICS)],
                                                          condition)

        return adma_obj_kinematics_list

    def GetAdmaAssociatedTypeId(self):
        """ Selects associated type for adma name.
        """
        condition = SQLBinaryExpr(COL_NAME_ASSOC_TYPE_NAME, OP_EQ, SQLLiteral(DEFAULT_ADMA_NAME))
        adma_id_list = self.SelectGenericData([COL_NAME_ASSOC_TYPE_ASSOCTYPEID],
                                              [self.GetQualifiedTableName(TABLE_NAME_ASSOC_TYPE)],
                                              condition)
        if not adma_id_list:
            return None

        adma_id = adma_id_list[0][COL_NAME_ASSOC_TYPE_ASSOCTYPEID]
        return adma_id

    def GetAdmaRectObjId(self, meas_id):
        """ Selects the rectangular object which has ADMA info associated.
        :param meas_id: The MeasId key from the 'Files' table.
        """
        adma_rectobj_id = None
        adma_id = self.GetAdmaAssociatedTypeId()

        if adma_id is not None:
            condition = SQLBinaryExpr(COL_NAME_ASSOC_TYPE_ASSOCTYPEID, OP_EQ, SQLLiteral(adma_id))
            condition = SQLBinaryExpr(condition, OP_AND, SQLBinaryExpr(COL_NAME_RECT_OBJ_MEASID,
                                                                       OP_EQ, SQLLiteral(meas_id)))
            adma_rectangular_obj_list = self.SelectGenericData([COL_NAME_RECT_OBJ_RECTOBJID],
                                                               [self.GetQualifiedTableName(
                                                                TABLE_NAME_RECTANGULAR_OBJECT)], condition)

            if len(adma_rectangular_obj_list):
                adma_rectobj_id = adma_rectangular_obj_list[0][COL_NAME_RECT_OBJ_RECTOBJID]
            else:
                logging.error("No adma rectobj id found for MEASID '%s'." % meas_id)
        else:
            logging.error("Associated Type not found for Adma")

        return adma_rectobj_id

    def GetApproachLabelForRect(self, rect_id):
        """ Gets the approach label for a given rect_id.
        :param rect_id: The RectId key from the 'Obj_RectangularObject' table.
        :return: Time sorted list of approach lables.
        """
        # First get the test case id for approach.
        test_case_typeid = self.GetTestCaseTypeID("approach")

        # Get the approach labels.
        select_list = [COL_NAME_TEST_CASES_TESTCASEID,
                       COL_NAME_TEST_CASES_TYPEID,
                       COL_NAME_TEST_CASES_RECTOBJID,
                       COL_NAME_TEST_CASES_BEGINABSTS,
                       COL_NAME_TEST_CASES_ENDABSTS]

        condition = SQLBinaryExpr(COL_NAME_TEST_CASES_RECTOBJID, OP_EQ, SQLLiteral(rect_id))
        condition = SQLBinaryExpr(condition,
                                  OP_AND,
                                  SQLBinaryExpr(COL_NAME_TEST_CASES_TYPEID, OP_EQ, SQLLiteral(test_case_typeid)))

        approach_label_list = self.SelectGenericData(select_list,
                                                     [self.GetQualifiedTableName(TABLE_NAME_TEST_CASES)],
                                                     condition)

        if len(approach_label_list):
            # Found approach
            pass
        else:
            logging.error("No approach found for RectID '%s'." % rect_id)
            return []

        return approach_label_list[0]

    def GetCollectionIds(self, meas_id):
        """ Selects the collection id(s) from the 'CAT_CollectionsMap' table.
        :param meas_id: The MeasId key from the 'CAT_Files' table.
        :return: The id(s) list (str) of the collection(s).
        """
        """
        condition = SQLBinaryExpr(COL_NAME_COLLMAP_MEASID, OP_EQ, SQLLiteral(meas_id))
        collection_id_list = self.db.select_generic_data([COL_NAME_COLLMAP_COLLID],
                                                         [self.db.get_qualified_table_name(TABLE_NAME_COLLMAP)],
                                                         condition)

        if len(collection_id_list):
            pass # All OK.
        else:
            logging.error("No collection id found for MEASID '%s'." % meas_id)
            sys.exit(0)

        return collection_id_list
        """
        raise AdasDBNotImplemented()

    def GetObjectId(self, measid):
        """Gets object id from database.
        :param measid: The measurement id.
        :return: Returns the object id list.
        """
        """
        objectid_list = []
        condition = SQLBinaryExpr(COL_NAME_MEASID, OP_EQ, measid)
        select_list = [COL_NAME_RECTOBJID]
        objectid_map_list = self.SelectGenericData(select_list,
                                                  [self.GetQualifiedTableName(TABLE_NAME_OBSERVATION_TIME)],
                                                  condition,
                                                  distinct_rows=True)

        for object_map in objectid_map_list:
            objectid_list.append(object_map[COL_NAME_RECTOBJID])

        return objectid_list
        """
        raise AdasDBNotImplemented()

    def GetObservationTime(self, measid, observation_timeid=None):
        """Gets observation time list from database.
        :param measid: The measurement id.
        :param observation_timeid: The observation time id.
        :return: Returns the observation time list.
        """
        """
        select_list = [COL_NAME_OBSERVATIONTIMEID, COL_NAME_RECTOBJID,
                       COL_NAME_OBSBEGINTIMESTAMP, COL_NAME_OBSENDTIMESTAMP]
        condition = SQLBinaryExpr(COL_NAME_MEASID, OP_EQ, SQLLiteral(measid))
        if observation_timeid is not None:
            observation_time_condition = SQLBinaryExpr(COL_NAME_OBSERVATIONTIMEID,
                                                       OP_EQ, SQLLiteral(observation_timeid))
            condition = SQLBinaryExpr(condition, OP_AND, observation_time_condition)
            select_list = [COL_NAME_RECTOBJID, COL_NAME_OBSBEGINTIMESTAMP, COL_NAME_OBSENDTIMESTAMP]

        observation_time_list = self.SelectGenericData(select_list,
                                                       [self.GetQualifiedTableName(TABLE_NAME_OBSERVATION_TIME)],
                                                       condition, distinct_rows = True)

        return observation_time_list
        """
        raise AdasDBNotImplemented()

    def GetLabeledObjectKinematics(self, measid, kinabsts):
        """Gets object kinematics  by a given timestamp and measurement id.
        :param rect_obj_id: The rectangular object id.
        :return: Returns the object kinematics list.
        """

        RECT_OBJ_RECTOBJID = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                                           COL_NAME_RECT_OBJ_RECTOBJID)
        KINEMATICS_RECTOBJID = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)),
                                             COL_NAME_KINEMATICS_RECTOBJID)

        select_list = [KINEMATICS_RECTOBJID,
                       COL_NAME_KINEMATICS_KINABSTS,
                       COL_NAME_KINEMATICS_RELDISTX,
                       COL_NAME_KINEMATICS_RELDISTY,
                       COL_NAME_KINEMATICS_RELVELX]

        join_expr = SQLTernaryExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                                   OP_INNER_JOIN,
                                   SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)),
                                   OP_ON,
                                   SQLBinaryExpr(RECT_OBJ_RECTOBJID, OP_EQ, KINEMATICS_RECTOBJID))

        condition = SQLBinaryExpr(COL_NAME_RECT_OBJ_MEASID,
                                  OP_EQ,
                                  SQLLiteral(measid))

        where_expr = SQLBinaryExpr(condition, OP_AND, SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_KINABSTS, OP_EQ,
                                                                    SQLLiteral(kinabsts)))

        obj_kinematic_list = self.SelectGenericData(select_list, table_list=[join_expr], where=where_expr)

        return obj_kinematic_list

    def GetLabeledLaneAssociationForMeasId(self, measid, lblstateid=None, select_list=['*']):

        condition = SQLBinaryExpr(COL_NAME_RECT_OBJ_MEASID,
                                  OP_EQ,
                                  SQLLiteral(measid))

        if lblstateid is not None:
            where_expr = SQLBinaryExpr(condition,
                                       OP_AND,
                                       SQLBinaryExpr(COL_NAME_ACC_LANE_REL_LBLSTATEID,
                                       OP_EQ, SQLLiteral(lblstateid)))
        else:
            where_expr = condition

        RECT_OBJ_RECTOBJID = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                                           COL_NAME_RECT_OBJ_RECTOBJID)
        ACC_LANE_RECTOBJID = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_ACC_LANE_REL)),
                                           COL_NAME_ACC_LANE_REL_RECTOBJID)

        join_expr = SQLTernaryExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_ACC_LANE_REL)),
                                   OP_INNER_JOIN,
                                   SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                                   OP_ON,
                                   SQLBinaryExpr(RECT_OBJ_RECTOBJID, OP_EQ, ACC_LANE_RECTOBJID))

        lane_association_list = self.SelectGenericData(select_list, table_list=[join_expr], where=where_expr)

        return lane_association_list

    def GetLabeledLaneAssociation(self, rectobjid, startTimestamp=None, stopTimestamp=None,
                                  laneid=None, lblstate=None, select_list=['*']):
        """Gets lane association at  kinematics from database.
        :param rectobjid: The rectangular object id.
        :param timestamp: The timestamp.
        :return: Returns acclanerelid, rectobjid, lblstateid, beginabsts, endabsts.
        """
        condition = self.__GetLabeledLaneAssociationCondition(rectobjid, startTimestamp,
                                                              stopTimestamp, laneid, lblstate)

        lane_association_list = self.SelectGenericData(select_list,
                                                       [self.GetQualifiedTableName(TABLE_NAME_ACC_LANE_REL)],
                                                       where=condition)

        return lane_association_list

    def __GetLabeledLaneAssociationCondition(self, rectobjid, startTimestamp=None,
                                             stopTimestamp=None, laneid=None, lblstate=None):

        cond = SQLBinaryExpr(COL_NAME_ACC_LANE_REL_RECTOBJID, OP_EQ, SQLLiteral(rectobjid))

        if startTimestamp is not None and stopTimestamp is None:
            condition2 = SQLBinaryExpr(COL_NAME_ACC_LANE_REL_BEGINABSTS, OP_LEQ, SQLLiteral(startTimestamp))
            condition3 = SQLBinaryExpr(COL_NAME_ACC_LANE_REL_ENDABSTS, OP_GEQ, SQLLiteral(startTimestamp))
            condition23 = SQLBinaryExpr(condition2, OP_AND, condition3)
            cond = SQLBinaryExpr(cond, OP_AND, condition23)

        if startTimestamp is not None and stopTimestamp is not None:
            betweenCondition1 = SQLTernaryExpr(COL_NAME_ACC_LANE_REL_BEGINABSTS, OP_BETWEEN,
                                               SQLLiteral(startTimestamp), OP_AND, SQLLiteral(stopTimestamp))
            betweenCondition2 = SQLTernaryExpr(COL_NAME_ACC_LANE_REL_ENDABSTS, OP_BETWEEN, SQLLiteral(startTimestamp),
                                               OP_AND, SQLLiteral(stopTimestamp))
            betweenCondition3 = SQLTernaryExpr(COL_NAME_ACC_LANE_REL_BEGINABSTS, OP_LEQ, SQLLiteral(startTimestamp),
                                               OP_AND, SQLBinaryExpr(COL_NAME_ACC_LANE_REL_ENDABSTS, OP_GEQ,
                                               SQLLiteral(stopTimestamp)))

            condition2 = SQLTernaryExpr(betweenCondition1, OP_OR, betweenCondition2, OP_OR, betweenCondition3)
            cond = SQLBinaryExpr(cond, OP_AND, condition2)

        if laneid is not None:
            condition4 = SQLBinaryExpr(COL_NAME_ACC_LANE_REL_LANEID, OP_EQ, SQLLiteral(laneid))
            cond = SQLBinaryExpr(cond, OP_AND, condition4)

        if lblstate is not None:
            condition5 = SQLBinaryExpr(COL_NAME_ACC_LANE_REL_LBLSTATEID, OP_EQ, lblstate)
            cond = SQLBinaryExpr(cond, OP_AND, condition5)

        return cond

    def GetRadKinRange(self, kinabsts1, kinabsts2, select_list=['*']):
        """ Selects a data range form the ObjKinematics table based on KINABSTS.
        """

        condition = SQLBinaryExpr(COL_NAME_KINEMATICS_KINABSTS, OP_GT, SQLLiteral(kinabsts1))
        condition = SQLBinaryExpr(condition, OP_AND, SQLBinaryExpr(COL_NAME_KINEMATICS_KINABSTS,
                                                                   OP_LT, SQLLiteral(kinabsts2)))

        obj_kinematics_list = self.SelectGenericData(select_list,
                                                     [self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)],
                                                     condition)

        return obj_kinematics_list

    def GetEgoKinematics(self, measid):
        """ Get ego kinematics for a measurement file.
        :param measid: The measid.
        """
        select_list = ['*']
        condition = SQLBinaryExpr(COL_NAME_EGO_KINEMATICS_MEASID, OP_EQ, SQLLiteral(measid))
        ego_kinematics_list = self.SelectGenericData(select_list,
                                                     [self.GetQualifiedTableName(TABLE_NAME_EGO_KINEMATICS)],
                                                     condition, order_by=[COL_NAME_EGO_KINEMATICS_KINABSTS])

        return ego_kinematics_list

    def GetRectObjectKinematics(self, rect_obj_id, select_list=['*'], start_kineabsts=None,
                                stop_kineabsts=None, orderby=None):
        """ Selects kinematics from database for a rectangular object.
        :param rect_obj_id: The rectangular object id.
        :param select_list: Selected Columns (default ALL)
        :return: Returns the object kinematics as a dict list.
        """
        obj_record = self.GetRectObjectByRectObjId(rect_obj_id)
        obj_kinematic_list = []

        if obj_record is not None and len(obj_record) == 1:
            adma_id = self.GetAdmaAssociatedTypeId()
            if adma_id is not None and obj_record[0][COL_NAME_RECT_OBJ_ASSOCTYPEID] == adma_id:
                condition = SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_RECTOBJID, OP_EQ, SQLLiteral(rect_obj_id))
                if start_kineabsts is not None and stop_kineabsts is not None:
                    condition2 = SQLTernaryExpr(COL_NAME_KINEMATICS_KINABSTS, OP_BETWEEN,
                                                SQLLiteral(start_kineabsts), OP_AND, SQLLiteral(stop_kineabsts))
                    condition = SQLBinaryExpr(condition, OP_AND, condition2)
                if orderby is not None:
                    obj_kinematic_list = self. SelectGenericData(select_list,
                                                                 [self.GetQualifiedTableName(
                                                                  TABLE_NAME_ADMA_KINEMATICS)],
                                                                 condition,
                                                                 order_by=orderby)
                else:
                    obj_kinematic_list = self. SelectGenericData(select_list,
                                                                 [self.GetQualifiedTableName(
                                                                  TABLE_NAME_ADMA_KINEMATICS)],
                                                                 condition)
            else:
                condition = SQLBinaryExpr(COL_NAME_KINEMATICS_RECTOBJID, OP_EQ, SQLLiteral(rect_obj_id))
                if start_kineabsts is not None and stop_kineabsts is not None:
                    condition2 = SQLTernaryExpr(COL_NAME_KINEMATICS_KINABSTS, OP_BETWEEN,
                                                SQLLiteral(start_kineabsts), OP_AND, SQLLiteral(stop_kineabsts))
                    condition = SQLBinaryExpr(condition, OP_AND, condition2)
                if orderby is not None:
                    obj_kinematic_list = self. SelectGenericData(select_list,
                                                                 [self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)],
                                                                 condition,
                                                                 order_by=orderby)
                else:
                    obj_kinematic_list = self. SelectGenericData(select_list,
                                                                 [self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)],
                                                                 condition)

        return obj_kinematic_list

    def GetRectObjectKinematicsArray(self, rect_obj_id, select_list=['*']):
        """ Selects kinematics from database for a rectangular object.

        If the rectangular object is an ADMA object, the data of adma kinematic table will be returned

        :param rect_obj_id: The rectangular object id.
        :param select_list: Selected Columns (default ALL)
        :return: Returns the object kinematics as a header and 2D array.
        """
        obj_record = self.GetRectObjectByRectObjId(rect_obj_id)

        obj_kinematic_list = []

        if obj_record is not None and len(obj_record) == 1:
            adma_id = self.GetAdmaAssociatedTypeId()
            if adma_id is not None and obj_record[0][COL_NAME_RECT_OBJ_ASSOCTYPEID] == adma_id:
                condition = SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_RECTOBJID, OP_EQ, SQLLiteral(rect_obj_id))
                obj_kinematic_list = self. SelectGenericDataCompact(select_list,
                                                                    [self.GetQualifiedTableName(
                                                                     TABLE_NAME_ADMA_KINEMATICS)],
                                                                    condition)
            else:
                condition = SQLBinaryExpr(COL_NAME_KINEMATICS_RECTOBJID, OP_EQ, SQLLiteral(rect_obj_id))
                obj_kinematic_list = self. SelectGenericDataCompact(select_list,
                                                                    [self.GetQualifiedTableName(
                                                                     TABLE_NAME_KINEMATICS)],
                                                                    condition)

        return obj_kinematic_list

    def GetRectObjectKinematicsBeginEnd(self, rect_obj_id):
        """Gets object kinematics from database.
        :param rect_obj_id: The rectangular object id.
        :return: Returns the object kinematics map.
        """
        object_kinematics_map = {}
        object_kinematics_map["BeginTS"] = None
        object_kinematics_map["EndTS"] = None

        obj_kinematic_list = self.GetRectObjectKinematics(rect_obj_id)

        if len(obj_kinematic_list) > 0:
            object_kinematics_map["BeginTS"] = obj_kinematic_list[0]
            object_kinematics_map["EndTS"] = obj_kinematic_list[-1]
            if len(object_kinematics_map):
                return object_kinematics_map
        return None

    def GetRectObjectStartEndTime(self, rect_obj_id):
        """ Get the start and end time for a particular rectangular object.
        :param rect_obj_id: The rectangular object id.
        :return: The start and end times.
        """
        obj_kin_map = self.GetRectObjectKinematicsBeginEnd(rect_obj_id)
        start_time = obj_kin_map["BeginTS"][COL_NAME_KINEMATICS_KINABSTS]
        end_time = obj_kin_map["EndTS"][COL_NAME_KINEMATICS_KINABSTS]
        return start_time, end_time

    def __RectObjDelCondition(self, cond, incl_deleted):
        """ extend the given condition with the the condition for deleted rect objects """
        if incl_deleted is False:
            cond_del = SQLBinaryExpr(COL_NAME_RECT_OBJ_RECTOBJ_IS_DELETED, OP_EQ, 0)
            if cond is not None:
                return SQLBinaryExpr(cond, OP_AND, cond_del)
            else:
                return cond_del
        else:
            return cond

    def GetRectObjectsForMeasId(self, meas_id, incl_deleted=False):
        """ Selects all the kinematics info for all rectangular objects in file.
        :param meas_id: The meas_id.
        :return: List of RectangularObjects with BeginAbsTs, EndAbsTs and ClassID for the selected file
        """
        object_rect_map = {}
        object_rect_map[COL_NAME_BEGIN_TS] = None
        object_rect_map[COL_NAME_END_TS] = None

        min_exp = SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_MIN],
                              SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)),
                                            COL_NAME_KINEMATICS_KINABSTS))
        max_exp = SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_MAX],
                              SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)),
                                            COL_NAME_KINEMATICS_KINABSTS))

        min_exp = SQLBinaryExpr(min_exp, OP_AS, COL_NAME_BEGIN_TS)
        max_exp = SQLBinaryExpr(max_exp, OP_AS, COL_NAME_END_TS)

        select_list = [SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(
                                                                TABLE_NAME_RECTANGULAR_OBJECT)),
                                                   COL_NAME_RECT_OBJ_RECTOBJID), OP_AS, COL_NAME_RECT_OBJ_RECTOBJID),
                       SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(
                                                                TABLE_NAME_RECTANGULAR_OBJECT)),
                                                   COL_NAME_RECT_OBJ_OBJCLASSID), OP_AS, COL_NAME_RECT_OBJ_OBJCLASSID),
                       min_exp, max_exp]

        col1 = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                             COL_NAME_RECT_OBJ_RECTOBJID)
        col2 = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)),
                             COL_NAME_KINEMATICS_RECTOBJID)

        join_expr = SQLTernaryExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                                   OP_INNER_JOIN,
                                   SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)),
                                   OP_ON,
                                   SQLBinaryExpr(col1, OP_EQ, col2))

        col1 = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                             COL_NAME_RECT_OBJ_MEASID)
        condition = SQLBinaryExpr(col1, OP_EQ, SQLLiteral(meas_id))

        condition = self.__RectObjDelCondition(condition, incl_deleted)

        group = [SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                               COL_NAME_RECT_OBJ_RECTOBJID),
                 SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                               COL_NAME_RECT_OBJ_OBJCLASSID)]

        obj_rect_list = self.SelectGenericData(select_list, [join_expr], condition,
                                               group, order_by=[COL_NAME_BEGIN_TS])

        return obj_rect_list

    def GetRectObjectIds(self, measid, incl_deleted=False):
        """ Gets rectangular object id's from database.
        :param measid: The measurement id.
        :return: Returns the object id record list.
        """
        select_list = [COL_NAME_RECT_OBJ_RECTOBJID]

        condition = SQLBinaryExpr(COL_NAME_RECT_OBJ_MEASID, OP_EQ, SQLLiteral(measid))
        condition = self.__RectObjDelCondition(condition, incl_deleted)
        object_id_list = self.SelectGenericData(select_list,
                                                [self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)],
                                                condition)

        return object_id_list

    def GetRectObjects(self, measid, incl_deleted=False):
        """Gets rectangular object id from database.
        :param measid: The measurement id.
        :return: Returns the object record list.
        """
        select_list = [COL_NAME_RECT_OBJ_RECTOBJID,
                       COL_NAME_RECT_OBJ_OBJCLASSID,
                       COL_NAME_RECT_OBJ_ASSOCTYPEID,
                       COL_NAME_RECT_OBJ_OBJWIDTH,
                       COL_NAME_RECT_OBJ_OBJLENGTH,
                       COL_NAME_RECT_OBJ_OBJHEIGHT,
                       COL_NAME_RECT_OBJ_ZLAYER,
                       COL_NAME_RECT_OBJ_KINLBLSTATEID]

        condition = SQLBinaryExpr(COL_NAME_RECT_OBJ_MEASID, OP_EQ, SQLLiteral(measid))

        # include only not deleted rect objects
        condition = self.__RectObjDelCondition(condition, incl_deleted)
        if incl_deleted:
            select_list.append(COL_NAME_RECT_OBJ_RECTOBJ_IS_DELETED)

        object_record_list = self.SelectGenericData(select_list,
                                                    [self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)],
                                                    condition)
        return object_record_list

    def GetRectObjectByRectObjId(self, rect_obj_id, select=None, incl_deleted=False):
        """Gets the retangular object data for the given id.
        :param rect_obj_id: ID if the rectangular object
        :param select_list: User sepecific selections
        :param incl_deleted: Query also deleted object. If yes, an additions column will be included indicating the
        status
        :return: Returns the object data
        """
        if select is None:
            select = [COL_NAME_RECT_OBJ_RECTOBJID, COL_NAME_RECT_OBJ_OBJCLASSID,
                      COL_NAME_RECT_OBJ_ASSOCTYPEID, COL_NAME_RECT_OBJ_OBJWIDTH,
                      COL_NAME_RECT_OBJ_OBJLENGTH, COL_NAME_RECT_OBJ_OBJHEIGHT,
                      COL_NAME_RECT_OBJ_ZLAYER, COL_NAME_RECT_OBJ_KINLBLSTATEID]

        condition = SQLBinaryExpr(COL_NAME_RECT_OBJ_RECTOBJID, OP_EQ, SQLLiteral(rect_obj_id))
        # include only not deleted rect objects
        condition = self.__RectObjDelCondition(condition, incl_deleted)
        if incl_deleted:
            select.append(COL_NAME_RECT_OBJ_RECTOBJ_IS_DELETED)

        object_record = self.SelectGenericData(select,
                                               [self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)],
                                               condition)
        return object_record

    def GetTestCaseName(self, meas_id):
        """ Selects the test case name from the 'TestCase' table.
        :param meas_id: The MeasId key from the 'Files' table.
        :return: The name (str) of the test case.
        """
        """ remove this function or find somebody who uses it (then correct it)
        condition = SQLBinaryExpr(COL_NAME_TEST_CASE_MEASID, OP_EQ, SQLLiteral(meas_id))
        test_case_list = self.SelectGenericData([COL_NAME_TEST_CASE_NAME],
                                                [self.GetQualifiedTableName(TABLE_NAME_TEST_CASE)], condition)

        test_case = None

        if len(test_case_list):
            test_case = test_case_list[0][COL_NAME_TEST_CASE_NAME]
        else:
            logging.error("No test case found for MEASID '%s'." % meas_id)
            sys.exit(0)

        return test_case
        """
        return None

    def GetTestCaseTypeID(self, test_case_name):
        """ Selects the test case typeid from the 'Obj_TestCaseType' table.
        :param name: The name key. (e.g. "cutin", "approach", ...)
        :return: The typeid (int) of the test case.
        """
        condition = SQLBinaryExpr(COL_NAME_TEST_CASE_TYPE_NAME, OP_EQ, SQLLiteral(test_case_name))
        test_case_id_list = self.SelectGenericData([COL_NAME_TEST_CASE_TYPE_ID],
                                                   [self.GetQualifiedTableName(TABLE_NAME_TEST_CASE_TYPE)], condition)

        test_case_type_id = None

        if len(test_case_id_list):
            test_case_type_id = test_case_id_list[0][COL_NAME_TEST_CASE_TYPE_ID]
        else:
            logging.info("No test case id found for test case name '%s'." % test_case_name)

        return test_case_type_id

    def GetTestCasesForRecFile(self, recfile_id, testcase_name):
        """ Generic Function to get Test case for the given test case id
        :param recfile_id: The recrFileID aka measid from CAT_Files table
        :param testcase_name: e.g. ooi, cutin Test Case name to get Test Case id to get lable list
        """
        test_case_typeid = self.GetTestCaseTypeID(testcase_name)

        # Get the cutin labels.
        select_list = [COL_NAME_TEST_CASES_TESTCASEID,
                       COL_NAME_TEST_CASES_TYPEID,
                       COL_NAME_TEST_CASES_RECTOBJID,
                       COL_NAME_TEST_CASES_BEGINABSTS,
                       COL_NAME_TEST_CASES_ENDABSTS]

        join_expr = SQLTernaryExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TEST_CASES)),
                                   OP_INNER_JOIN,
                                   SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_RECTANGULAR_OBJECT)),
                                   OP_NOP,
                                   SQLFuncExpr(OP_USING, COL_NAME_RECT_OBJ_RECTOBJID))

        condition = SQLBinaryExpr(COL_NAME_RECT_OBJ_MEASID, OP_EQ, SQLLiteral(recfile_id))
        condition = SQLBinaryExpr(condition, OP_AND,
                                  SQLBinaryExpr(COL_NAME_TEST_CASES_TYPEID, OP_EQ, SQLLiteral(test_case_typeid)))

        label_list = self.SelectGenericData(select_list, table_list=[join_expr], where=condition)

        if len(label_list) > 0:
            # Found some cutin testcases
            for testcase in label_list:
                testcase['obj_kinematics'] = []
                # get obj kinematics for testcase begints and endts
                select_list = [COL_NAME_KINEMATICS_RELDISTX, COL_NAME_KINEMATICS_RELDISTY, COL_NAME_KINEMATICS_RELVELX]
                condition1 = SQLBinaryExpr(COL_NAME_KINEMATICS_RECTOBJID, OP_EQ,
                                           SQLLiteral(testcase[COL_NAME_RECT_OBJ_RECTOBJID]))
                condition2 = SQLBinaryExpr(COL_NAME_KINEMATICS_KINABSTS, OP_EQ,
                                           SQLLiteral(testcase[COL_NAME_TEST_CASES_BEGINABSTS]))
                condition3 = SQLBinaryExpr(COL_NAME_KINEMATICS_KINABSTS, OP_EQ,
                                           SQLLiteral(testcase[COL_NAME_TEST_CASES_ENDABSTS]))
                condition23 = SQLBinaryExpr(condition2, OP_OR, condition3)
                condition = SQLBinaryExpr(condition1, OP_AND, condition23)
                testcase_obj_kinematics = self.SelectGenericData(select_list,
                                                                 [self.GetQualifiedTableName(TABLE_NAME_KINEMATICS)],
                                                                 where=condition)
                testcase['obj_kinematics'] = testcase_obj_kinematics
        else:
            logging.info("No " + testcase_name + " testcase found for RecFile '%s'." % recfile_id)

        return label_list

    def getEgoKinematicsAdma(self, measid, kinabsts):
        """gets the ego kinematics entry
        :param measid: measurement ID
        :param kinabsts: absolute timestamp
        :return: dict of values
        """
        stmt = "SELECT %s, %s, " % (COL_NAME_EGO_ADMA_VELOCITY_X, COL_NAME_EGO_ADMA_VELOCITY_Y)
        stmt += "%s, %s, " % (COL_NAME_EGO_ADMA_VELOCITY_Z, COL_NAME_EGO_ADMA_ACCELERATION)
        stmt += "%s, %s, %s, " % (COL_NAME_EGO_ADMA_YAWRATE, COL_NAME_EGO_ADMA_PITCH, COL_NAME_EGO_ADMA_ROLL)
        stmt += "%s, %s" % (COL_NAME_EGO_ADMA_SUMDIST, COL_NAME_EGO_ADMA_SUMYAW)
        if measid is None:
            stmt += ", %s" % (COL_NAME_EGO_ADMA_MEASID)
        if kinabsts is None:
            stmt += ", %s" % (COL_NAME_EGO_ADMA_KINABSTS)
        stmt += " FROM %s" % (TABLE_NAME_EGO_KINEMATICS_ADMA)
        if (measid or kinabsts) is not None:
            stmt += " WHERE "
        if measid is not None:
            stmt += "%s " % (COL_NAME_EGO_ADMA_MEASID)
            if type(measid) == list:
                stmt += "IN (%s)" % (", ".join(map(str, measid)))
            else:
                stmt += "= %d" % (measid)
        if kinabsts is not None:
            if measid is not None:
                stmt += " AND "
            stmt += "%s " % (COL_NAME_EGO_ADMA_KINABSTS)
            if type(kinabsts) == list:
                stmt += "IN (%s)" % (", ".join(map(str, kinabsts)))
            else:
                stmt += "= %d" % (kinabsts)
        return self.__getSimpleData(stmt)

    def getProbsCam(self, absts, recId):
        """gets the camera property (occlude factor)
        :param absts: absolute timestamp
        :param recId: rectangular object ID
        :return: dict of values
        """
        stmt = "SELECT %s" % (COL_NAME_PROBSCAM_OCCLUDED)
        if absts is None:
            stmt += ", %s" % (COL_NAME_PROBSCAM_ABSTS)
        if recId is None:
            stmt += ", %s" % (COL_NAME_PROBSCAM_RECTOBJID)
        stmt += " FROM %s" % (TABLE_NAME_PROBS_CAM)
        if (absts or recId) is not None:
            stmt += " WHERE "
        if absts is not None:
            stmt += "%s " % (COL_NAME_PROBSCAM_ABSTS)
            if type(absts) == list:
                stmt += "IN (%s)" % (", ".join(map(str, absts)))
            else:
                stmt += "= %d" % (absts)
        if recId is not None:
            if absts is not None:
                stmt += " AND "
            stmt += "%s " % (COL_NAME_PROBSCAM_RECTOBJID)
            if type(recId) == list:
                stmt += "IN (%s)" % (", ".join(map(str, recId)))
            else:
                stmt += "= %d" % (recId)
        return self.__getSimpleData(stmt)

    def __getSimpleData(self, stmt):
        """returns array of data in dict
        :param stmt: statement to execute
        """
        tot = []
        res = {}
        data = self.execute(stmt, True)
        desc = data.pop(0)
        ll = len(desc)
        for dd in data:
            for ii in range(ll):
                res[desc[ii]] = dd[ii]
            tot.append(res)
        return tot

    def HasTestCase(self, rect_id, test_case_type):
        """ Checks if there is an approach label for a given rect_id.
        :param rect_id: The RectId key from the 'Obj_RectangularObject' table.
        :param test_case_type: The test case type as a string.
        :return: bool.
        """
        # First get the test case id for approach.
        test_case_typeid = self.GetTestCaseTypeID(test_case_type)

        # Get the approach labels.
        select_list = [COL_NAME_TEST_CASES_TESTCASEID,
                       COL_NAME_TEST_CASES_TYPEID,
                       COL_NAME_TEST_CASES_RECTOBJID,
                       COL_NAME_TEST_CASES_BEGINABSTS,
                       COL_NAME_TEST_CASES_ENDABSTS]

        condition = SQLBinaryExpr(COL_NAME_TEST_CASES_RECTOBJID, OP_EQ, SQLLiteral(rect_id))
        condition = SQLBinaryExpr(condition, OP_AND,
                                  SQLBinaryExpr(COL_NAME_TEST_CASES_TYPEID, OP_EQ, SQLLiteral(test_case_typeid)))

        approach_label_list = self.SelectGenericData(select_list,
                                                     [self.GetQualifiedTableName(TABLE_NAME_TEST_CASES)],
                                                     condition)

        if len(approach_label_list):
            # Found approach
            return True
        else:
            return False

    def HasAdmaRectangularObjectId(self, meas_id):
        """ Selects the rectangular object which has ADMA info associated.
        :param meas_id: The MeasId key from the 'Files' table.
        """
        ret_val = False
        adma_id = self.GetAdmaAssociatedTypeId()

        if adma_id is not None:
            condition = SQLBinaryExpr(COL_NAME_ASSOC_TYPE_ASSOCTYPEID, OP_EQ, SQLLiteral(adma_id))
            condition = SQLBinaryExpr(condition, OP_AND, SQLBinaryExpr(COL_NAME_RECT_OBJ_MEASID,
                                                                       OP_EQ, SQLLiteral(meas_id)))
            adma_rectangular_obj_list = self.SelectGenericData([COL_NAME_RECT_OBJ_RECTOBJID],
                                                               [self.GetQualifiedTableName(
                                                                TABLE_NAME_RECTANGULAR_OBJECT)],
                                                               condition)

            if len(adma_rectangular_obj_list):
                ret_val = True
        else:
            logging.error("Associated Type not found for Adma")

        return ret_val

    def IsAdmaAssociatedTypeId(self):
        """ Selects associated type for adma name.
        """
        condition = SQLBinaryExpr(COL_NAME_ASSOC_TYPE_NAME, OP_EQ, SQLLiteral(DEFAULT_ADMA_NAME))
        adma_id_list = self.SelectGenericData([COL_NAME_ASSOC_TYPE_ASSOCTYPEID],
                                              [self.GetQualifiedTableName(TABLE_NAME_ASSOC_TYPE)], condition)
        if not adma_id_list:
            return False
        return True

    def GetLabelStateId(self, name):
        """ Get lable state id for given label state name
        :param name: label state name e.g. auto manual
        """
        condition = SQLBinaryExpr(COL_NAME_LBL_STATE_NAME, OP_EQ, SQLLiteral(name))
        lbl_state_id = self.SelectGenericData([COL_NAME_LBL_STATE_LBL_STATE_ID],
                                              [self.GetQualifiedTableName(TABLE_NAME_OBJ_LBL_STATE)], condition)
        if len(lbl_state_id) == 1:
            lbl_state_id = lbl_state_id[0][COL_NAME_LBL_STATE_LBL_STATE_ID]
        else:
            logging.error("No Label state id or Ambigious found for label state'%s'." % name)
            sys.exit(0)
        return lbl_state_id

    def GetLabelClassId(self, classname):
        """ Get lable class id for given label class name
        :param classname: label state name e.g. car truck
        """
        condition = SQLBinaryExpr(COL_NAME_OBJECT_CLASS_CLASS_NAME, OP_EQ, SQLLiteral(classname))
        clsid = self.SelectGenericData([COL_NAME_OBJECT_CLASS_CLS_ID],
                                       [self.GetQualifiedTableName(TABLE_NAME_OBJECT_CLASS)], condition)
        if len(clsid) == 1:
            clsid = clsid[0][COL_NAME_OBJECT_CLASS_CLS_ID]
        else:
            logging.error("No Object Class Label id or Ambigious found for label state'%s'." % classname)
            sys.exit(0)
        return clsid

    def GetObjectAssociationTypeId(self, name):
        """ Get object Association id for given name
        :param name: association name e.g. adma, rect
        """
        condition = SQLBinaryExpr(COL_NAME_ASSOC_TYPE_NAME, OP_EQ, SQLLiteral(name))
        assoc_type = self.SelectGenericData([COL_NAME_ASSOC_TYPE_ASSOCTYPEID],
                                            [self.GetQualifiedTableName(TABLE_NAME_ASSOC_TYPE)], condition)
        if len(assoc_type) == 1:
            assoc_type = assoc_type[0][COL_NAME_ASSOC_TYPE_ASSOCTYPEID]
        else:
            self.__logger.error("No Object Association type id or Ambigious found for object association state'%s'."
                                % name)
            sys.exit(0)
        return assoc_type

    def GetObjectLaneTypeId(self, lane_name):
        condition = SQLBinaryExpr(COL_NAME_LANE_TYPES_LANE_NAME, OP_EQ, SQLLiteral(lane_name))
        lane_type = self.SelectGenericData([COL_NAME_LANE_TYPES_LANE_ID],
                                           [self.GetQualifiedTableName(TABLE_NAME_ACC_LANE_TYPES)], condition)
        if len(lane_type) == 1:
            lane_type = lane_type[0][COL_NAME_LANE_TYPES_LANE_ID]
        else:
            self.__logger.error("No Object Lane type id or Ambigious found for lane name '%s'." % lane_name)
            sys.exit(0)
        return lane_type

#    def GetUser(self, name=None, login=None):
#        """Get existing user records.
#        :param name: The user name.
#        :return: Returns the user record.
#        """
#        record = {}
#        cond = None
#
#        if name is not None:
#            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
#                                             gbldb.COL_NAME_USER_NAME), OP_EQ, SQLLiteral(name.lower()))
#        if login is not None:
#            cond_ln = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
#                                                gbldb.COL_NAME_USER_LOGIN), OP_EQ, SQLLiteral(login.lower()))
#            if cond is not None:
#                cond = SQLBinaryExpr (cond, OP_AND, cond_ln)
#            else:
#                cond = cond_ln
#
#        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(gbldb.TABLE_NAME_USERS)], where=cond)
#        if len(entries) <= 0:
#            warning("User with name '%s' does not exists in the global  database." % name)
#        elif len(entries) > 1:
#            warning("User with name '%s' cannot be resolved because it is ambiguous. (%s)" %(name, entries))
#        else:
#            record = entries[0]
#        # done
#        return record

    #====================================================================
    # Interface helper functions
    #====================================================================
    def __GetDbRectObjectId(self, object_id):
        return self.__object_map.get(object_id)

    def __GetNextID(self, table_name, col_name):
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
                next_id = row[0] + 1
        except:
            raise AdasDBError("Error while getting next id: '%s'" % stmt)
        finally:
            cursor.close()
        # done
        return next_id

    def __GetNextRectObjectId(self):
        """Get the next available rectangular object ID
        :return: Returns the next available rectangular object ID.
        """
        return self.__GetNextID(TABLE_NAME_RECTANGULAR_OBJECT, COL_NAME_RECT_OBJ_RECTOBJID)
        """
        sql_select_stmt = self.sql_factory.get_select_builder()
        sql_select_stmt.select_list = [SQLFuncExpr(self.db.get_max_func_name(), COL_NAME_RECT_OBJ_RECTOBJID)]
        sql_select_stmt.table_list = [self.db.get_qualified_table_name(TABLE_NAME_RECTANGULAR_OBJECT)]
        stmt = str(sql_select_stmt)
        # fetch max. rect_object_id
        next_rect_object_id = 0
        cursor = self.db_connection.cursor()
        try:
            cursor.execute(stmt)
            row = cursor.fetchone()
            if (row != None) and (row[0] != None):
                next_rect_object_id = int(row[0]) + 1
        except:
            raise AdasDBError("Error while getting next rectangular object id: '%s'" % stmt)
        finally:
            cursor.close()
        # done
        return next_rect_object_id
        """


#====================================================================
# Constraint DB Libary SQL Server Compact Implementation
#====================================================================
class SQLCEObjDataDB(BaseObjDataDB, SQLCEBaseDB):
    """SQL Server Compact Edition Implementation of OBJ Data DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseObjDataDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLCEBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseObjDataDB.Initialize(self)
        SQLCEBaseDB.Initialize(self)


class OracleObjDataDB(BaseObjDataDB, OracleBaseDB):
    """Oracle Implementation of OBJ Data  DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseObjDataDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        OracleBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseObjDataDB.Initialize(self)
        OracleBaseDB.Initialize(self)


class SQLite3ObjDataDB(BaseObjDataDB, SQLite3BaseDB):
    """Oracle Implementation of OBJ Data DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseObjDataDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLite3BaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseObjDataDB.Initialize(self)
        SQLite3BaseDB.Initialize(self)

"""
$Log: objdata.py  $
Revision 1.1 2021/12/13 17:56:39CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/obj/project.pj
Revision 1.21 2013/08/23 11:05:57CEST Ahmed, Zaheer (uidu7634) 
Fixed pep8 and pylint issues Added  GetLabelClassId GetObjectAssociationTypeId GetObjectLaneTypeId
- Added comments -  uidu7634 [Aug 23, 2013 11:05:57 AM CEST]
Change Package : 190321:1 http://mks-psad:7002/im/viewissue?selection=190321
Revision 1.20 2013/07/17 15:00:34CEST Raedler, Guenther (uidt9430)
- revert changes of BaseDB class
--- Added comments ---  uidt9430 [Jul 17, 2013 3:00:34 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.19 2013/07/10 09:42:43CEST Raedler, Guenther (uidt9430)
- fixed error for user specific selections in method GetRectObjectByRectObjId()
- added documentation
--- Added comments ---  uidt9430 [Jul 10, 2013 9:42:43 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.18 2013/07/04 15:01:30CEST Mertens, Sven (uidv7805)
providing tableSpace to BaseDB for what sub-schema space each module is intended to be responsible
--- Added comments ---  uidv7805 [Jul 4, 2013 3:01:30 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.17 2013/05/27 08:17:33CEST Raedler, Guenther (uidt9430)
- return condition in all cases
--- Added comments ---  uidt9430 [May 27, 2013 8:17:33 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.16 2013/05/27 08:12:39CEST Raedler, Guenther (uidt9430)
- added new condition to use only not deleted rect objects for the validation
- added new column COL_NAME_RECT_OBJ_RECTOBJ_IS_DELETED if all RectObjects are requested
--- Added comments ---  uidt9430 [May 27, 2013 8:12:39 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.15 2013/04/30 15:48:01CEST Mertens, Sven (uidv7805)
adding select columns when parameter are None
--- Added comments ---  uidv7805 [Apr 30, 2013 3:48:02 PM CEST]
Change Package : 179495:5 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.14 2013/04/26 15:39:06CEST Mertens, Sven (uidv7805)
resolving some pep8 / pylint errors
--- Added comments ---  uidv7805 [Apr 26, 2013 3:39:07 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.13 2013/04/26 10:46:06CEST Mertens, Sven (uidv7805)
moving strIdent
--- Added comments ---  uidv7805 [Apr 26, 2013 10:46:06 AM CEST]
Change Package : 179495:4 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.12 2013/04/25 14:36:51CEST Mertens, Sven (uidv7805)
epydoc adaptation: change from at to colon,
new functions for add and delete for addtional tables added
--- Added comments ---  uidv7805 [Apr 25, 2013 2:36:52 PM CEST]
Change Package : 179495:2 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.11 2013/04/19 13:37:58CEST Hecker, Robert (heckerr)
Functionality reverted to revision 1.9.
--- Added comments ---  heckerr [Apr 19, 2013 1:37:58 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.10 2013/04/12 14:37:00CEST Mertens, Sven (uidv7805)
adding a short representation used by db_connector.PostInitialize
--- Added comments ---  uidv7805 [Apr 12, 2013 2:37:00 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.9 2013/04/02 10:04:24CEST Raedler, Guenther (uidt9430)
- use logging for all log messages again
- use specific indeitifier names
--- Added comments ---  uidt9430 [Apr 2, 2013 10:04:24 AM CEST]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.8 2013/03/26 16:19:32CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:32 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/21 17:22:38CET Mertens, Sven (uidv7805)
solving some pylint warnings / errors
--- Added comments ---  uidv7805 [Mar 21, 2013 5:22:38 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/02/28 08:12:19CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:20 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/27 17:55:11CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:12 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/27 16:19:56CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:56 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/26 20:10:30CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:10:30 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/19 14:07:30CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:31 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 09:58:59CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/db/obj/project.pj
------------------------------------------------------------------------------
-- From ETK/ADAS_DB Archive
------------------------------------------------------------------------------
Revision 1.27 2012/10/19 10:34:55CEST Hammernik-EXT, Dmitri (uidu5219)
- removed wrong setted comments
- added GetLabeledLaneAssociation und changed GetLabeledLaneAssociationForMeasId
--- Added comments ---  uidu5219 [Oct 19, 2012 10:34:56 AM CEST]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.26 2012/10/19 08:10:01CEST Ahmed-EXT, Zaheer (uidu7634)
add table and column def OBJ_LBL_STATE and OBJ_ACCLANETYPES
add support function to get LabelStateId and USERID for LBLBY
add column def for labling info  in OBJ_TEST_CASES and ACC_Lane_Relation
updated AddTestCase fucntion
--- Added comments ---  uidu7634 [Oct 19, 2012 8:10:04 AM CEST]
Change Package : 153893:1 http://mks-psad:7002/im/viewissue?selection=153893
Revision 1.25 2012/08/24 10:44:50CEST Ahmed-EXT, Zaheer (uidu7634)
Removed Following Tables:
- Obj_AccLaneRelationLblState
- Obj_ClassLblState
- Obj_DimLblState
- Obj_KinematicLblState

Added Following Tables:

- OBJ_LblState

Add New column def for TABLE_NAME_RECTANGULAR_OBJECT
- RectObj_Is_Deleted
- CLSLBLTIME
- CLSLBLBY
- DIMLBLBSTATEID
- DIMLBLTIME
- DIMLBLBY
- Z0LBLSTATEID
- Z0LBLBY
- Z0LBLTIME
- KINLBLTIME
- KINLBLBY

Remove column def for TABLE_NAME_RECTANGULAR_OBJECT
- LBLMODTIME
- LBLBY
- BEGINOBJABSSTS
- ENDOBJABSTS

Removed Duplicating Column Def for TABLE_NAME_RECTANGULAR_OBJECT
Fix empty list return for GetApproachLabelForRect() when no lable found
Changed select_list for new colum  in GetRectObjects()
Changed select_list for new colum  in GetRectObjectByRectObjId()
--- Added comments ---  uidu7634 [Aug 24, 2012 10:44:54 AM CEST]
Change Package : 153893:1 http://mks-psad:7002/im/viewissue?selection=153893
Revision 1.24 2012/05/16 13:33:53CEST Hammernik-EXT, Dmitri (uidu5219)
- Removed GetCutinTestCasesForRecFile -> use more generic method (GetTestCasesForRecFile)
- added additional parameter in GeLabeledLaneAssociation
--- Added comments ---  uidu5219 [May 16, 2012 1:33:53 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.23 2012/05/02 14:53:52CEST Hielscher, Patrick (uidt6110)
Added new functions GetLabeledObjectByLane, GetRectObjectKinematicsSortByKinabsts and GetTestCasesForRecFile
--- Added comments ---  uidt6110 [May 2, 2012 2:53:54 PM CEST]
Change Package : 94404:1 http://mks-psad:7002/im/viewissue?selection=94404
Revision 1.22 2012/03/16 15:22:19CET Hammernik-EXT, Dmitri (uidu5219)
- added new function GetLabeledLaneAssociationForMeasid
--- Added comments ---  uidu5219 [Mar 16, 2012 3:22:19 PM CET]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.21 2012/03/16 10:03:54CET Hammernik-EXT, Dmitri (uidu5219)
- changed GetLabeledLaneAssociation
--- Added comments ---  uidu5219 [Mar 16, 2012 10:03:57 AM CET]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.20 2012/03/05 10:33:16CET Raedler-EXT, Guenther (uidt9430)
- added new functions for lane association
- changed return value of GetLabeledObjectKinematics()
--- Added comments ---  uidt9430 [Mar 5, 2012 10:33:16 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.19 2012/03/02 16:24:43CET Hielscher, Patrick (uidt6110)
Add new function GetLabeledLaneAssociationForRectObjID
--- Added comments ---  uidt6110 [Mar 2, 2012 4:24:43 PM CET]
Change Package : 94393:2 http://mks-psad:7002/im/viewissue?selection=94393
Revision 1.18 2012/02/06 16:35:54CET Hammernik-EXT, Dmitri (uidu5219)
- add new column to selectlist in GetLabeledLaneassociation
--- Added comments ---  uidu5219 [Feb 6, 2012 4:35:55 PM CET]
Change Package : 91989:2 http://mks-psad:7002/im/viewissue?selection=91989
Revision 1.17 2012/02/06 08:23:24CET Raedler Guenther (uidt9430) (uidt9430)
- cast new ID as integer value
--- Added comments ---  uidt9430 [Feb 6, 2012 8:23:25 AM CET]
Change Package : 95134:1 http://mks-psad:7002/im/viewissue?selection=95134
Revision 1.16 2011/12/15 09:41:11CET Hanel, Nele (haneln)
fixed GetLabeledObjectKinematics(self, measid, kinabsts)
added GetLabeledLaneAssociation(self, rectobjid, timestamp)
--- Added comments ---  haneln [Dec 15, 2011 9:41:12 AM CET]
Change Package : 88881:2 http://mks-psad:7002/im/viewissue?selection=88881
Revision 1.15 2011/11/16 11:04:27CET Bogne-EXT, Claude (uidu3860)
- fixed error due to uninitialized parameter
--- Added comments ---  uidu3860 [Nov 16, 2011 11:04:28 AM CET]
Change Package : 78562:1 http://mks-psad:7002/im/viewissue?selection=78562
Revision 1.14 2011/11/14 11:46:24CET Castell Christoph (uidt6394) (uidt6394)
Added GetEgoKinematics(self, measid) function and table definition.
--- Added comments ---  uidt6394 [Nov 14, 2011 11:46:24 AM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.13 2011/11/08 10:44:36CET Raedler Guenther (uidt9430) (uidt9430)
- use new methods to get the kinematics of an rectobject
--- Added comments ---  uidt9430 [Nov 8, 2011 10:44:36 AM CET]
Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.12 2011/11/08 10:30:57CET Raedler Guenther (uidt9430) (uidt9430)
-
Revision 1.11 2011/10/04 13:09:18CEST Raedler Guenther (uidt9430) (uidt9430)
- fixed error in 'goup by' query option
--- Added comments ---  uidt9430 [Oct 4, 2011 1:09:18 PM CEST]
Change Package : 62766:1 http://mks-psad:7002/im/viewissue?selection=62766
Revision 1.10 2011/09/08 10:07:28CEST Castell Christoph (uidt6394) (uidt6394)
Added GetNextID() for AddTestCase() function.
--- Added comments ---  uidt6394 [Sep 8, 2011 10:07:28 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.9 2011/08/29 13:43:51CEST Castell Christoph (uidt6394) (uidt6394)
Fixed logging class bug.
--- Added comments ---  uidt6394 [Aug 29, 2011 1:43:51 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.8 2011/08/25 10:03:09CEST Castell Christoph (uidt6394) (uidt6394)
Removed duplicate functions and corrected naming.
--- Added comments ---  uidt6394 [Aug 25, 2011 10:03:09 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.7 2011/08/23 13:59:56CEST Castell Christoph (uidt6394) (uidt6394)
Tidy up of function list. Removal of duplicate function.
--- Added comments ---  uidt6394 [Aug 23, 2011 1:59:56 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.6 2011/08/23 13:37:46CEST Raedler Guenther (uidt9430) (uidt9430)
-- added function to get the rect objects for a defined measid
-- added functions to get the kinematic data for a rect object
--- Added comments ---  uidt9430 [Aug 23, 2011 1:37:46 PM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.5 2011/07/15 10:47:39CEST Raedler Guenther (uidt9430) (uidt9430)
- renamed base classes to avoid conflicts in namings
--- Added comments ---  uidt9430 [Jul 15, 2011 10:47:39 AM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.4 2011/07/12 15:52:11CEST Hanel Nele (haneln) (haneln)
add get function for cutin testcases
--- Added comments ---  haneln [Jul 12, 2011 3:52:11 PM CEST]
Change Package : 70482:1 http://mks-psad:7002/im/viewissue?selection=70482
Revision 1.3 2011/06/21 15:33:44CEST Castell Christoph (uidt6394) (uidt6394)
Re-introduced approach functions.
--- Added comments ---  uidt6394 [Jun 21, 2011 3:33:44 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.2 2011/06/20 16:34:36CEST Hanel Nele (haneln) (haneln)
add interface for object test case type id
--- Added comments ---  haneln [Jun 20, 2011 4:34:36 PM CEST]
Change Package : 70482:1 http://mks-psad:7002/im/viewissue?selection=70482
Revision 1.1 2011/06/20 11:15:43CEST Raedler Guenther (uidt9430) (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/EM_EnvironmentModel/05_Testing/05_Test_Environment/algo/
em_req_test/valf_tests/adas_database/obj/project.pj
"""
