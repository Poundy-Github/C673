"""
stk/db/lbl/camlabel.py
-------------------

Python library to access camera lables

 Sub-Scheme ADMS_ADMIN

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:22CET $
"""

# pylint: disable=C0103

# Import Python Modules ----------------------------------------------------------------------------------------------
from logging import warn

# Import STK Modules -------------------------------------------------------------------------------------------------
from stk.db.db_common import BaseDB, ERROR_TOLERANCE_NONE, DB_FUNC_NAME_LOWER, DB_FUNC_NAME_MAX, DB_FUNC_NAME_MIN, \
    SQLCEBaseDB, OracleBaseDB, SQLite3BaseDB
from stk.db.db_sql import GenericSQLStatementFactory, SQLBinaryExpr, SQLFuncExpr, SQLColumnExpr, SQLTableExpr, OP_EQ, \
    SQLLiteral, OP_AND, OP_LEQ, OP_AS, OP_GEQ

#====================================================================
# Constants
#====================================================================

# Table base names:
TABLE_NAME_FILE2HSM = "file2hsm"
TABLE_NAME_LBT_CFG = "labeltool_config"
TABLE_NAME_TMT = "ticket_master_table"
TABLE_NAME_RLT = "revision_log_table"

TABLE_NAME_FOD_CD = "mfc300_fod_cd"
TABLE_NAME_HLA_CD = "mfc300_hla_cd"
TABLE_NAME_LD_CD = "mfc300_ld_cd"
TABLE_NAME_PED_CD = "mfc300_ped_cd"
TABLE_NAME_POD_CD = "mfc300_pod_cd"
TABLE_NAME_PV_CD = "mfc300_pv_cd"
TABLE_NAME_SAC_CD = "mfc300_sac_cd"
TABLE_NAME_SR_CD = "mfc300_sr_cd"

TABLE_NAME_BASE = "mfc300"

TABEL_NAME_CD_POSTFIX = "_CD"
TABEL_NAME_LDSS_POSTFIX = "_LDSS"
TABLE_NAME_ALL_LDSS = "MFC300_%_LSDD"
TABEL_NAME_LDROI_POSTFIX = "_LDROI"

TABEL_NAME_ARC_POSTFIX = "_ARCHIVE"
TABEL_NAME_INF_POSTFIX = "_INTERFACE"

COL_NAME_FILE2HSM_TAN = "TAN"
COL_NAME_FILE2HSM_SOURCE_FILE_SH = "SOURCE_FILE_SH"
COL_NAME_FILE2HSM_SOURCE_FILEPATH = "SOURCE_FILEPATH"
COL_NAME_FILE2HSM_DESTINATION_FILEPATH = "DESTINATION_FILEPATH"
COL_NAME_FILE2HSM_STATUS = "STATUS"
COL_NAME_FILE2HSM_SOURCE_RECIDFILENAME = "SOURCE_RECIDFILENAME"
COL_NAME_FILE2HSM_DESTINATION_RECIDFILENAME = "DESTINATION_RECIDFILENAME"
COL_NAME_FILE2HSM_FILESIZE = "FILESIZE"
COL_NAME_FILE2HSM_GUID = "GUID"

COL_NAME_LBT_CFG_CONF_ID = "CONF_ID"
COL_NAME_LBT_CFG_LABEL_DESC_VERS = "LABEL_DESC_VERS"
COL_NAME_LBT_CFG_CONF_STATUS = "CONF_STATUS"
COL_NAME_LBT_CFG_ASSIGNED_CONF_ID = "ASSIGNED_CONF_ID"

COL_NAME_TMT_TICKET_ID = "TICKET_ID"
COL_NAME_TMT_TRACE_ID = "TRACE_ID"
COL_NAME_TMT_LABEL_DESC_VERS = "LABEL_DESC_VERS"
COL_NAME_TMT_RECMTFILENAME = "RECMTFILENAME"
COL_NAME_TMT_RECIDFILENAME = "RECIDFILENAME"
COL_NAME_TMT_SEQUENZMTTIMESTAMPSTART = "SEQUENZMTTIMESTAMPSTART"
COL_NAME_TMT_SEQUENZMTTIMESTAMPSTOP = "SEQUENZMTTIMESTAMPSTOP"
COL_NAME_TMT_ASSIGNED_TO_USERID = "ASSIGNED_TO_USERID"
COL_NAME_TMT_ASSIGNED_TIMESTAMP = "ASSIGNED_TIMESTAMP"
COL_NAME_TMT_WORK_STATUS = "WORK_STATUS"
COL_NAME_TMT_KOL = "KOL"
COL_NAME_TMT_DATATYPE_IDX = "DATATYPE_IDX"
COL_NAME_TMT_FRAMESELECTION = "FRAMESELECTION"
COL_NAME_TMT_WORK_STATUS_INFO = "WORK_STATUS_INFO"

# Generall collum names
COL_NAME_TAN = "TAN"
COL_NAME_REC_ID_FILE_NAME = "RecIdFileName"

# general rlt collums
COL_NAME_RLT_START_TIME_STAMP = "START_TIME_STAMP"
COL_NAME_RLT_STOP_TIME_STAMP = "STOP_TIME_STAMP"
COL_NAME_RLT_FINAL_TBL = "FINAL_TBL"
COL_NAME_RLT_TAN_FINAL_TBL = "TAN_FINAL_TBL"
COL_NAME_RLT_PROCESS = "PROCESS"
COL_NAME_RLT_TICKET_ID = "TICKET_ID"
COL_NAME_RLT_DESCRIPTION = "DESCRIPTION"
COL_NAME_RLT_FEEDBACK = "FEEDBACK"
COL_NAME_RLT_EVALT_VERSION = "EVALT_VERSION"
COL_NAME_RLT_ALGO_VERSION = "ALGO_VERSION"
COL_NAME_RLT_PRIORITY = "PRIORITY"

# general cd collums
COL_NAME_CD_SEQUENZMTTIMESTAMPSTART = "SEQUENZMTTIMESTAMPSTART"
COL_NAME_CD_START_CYCLE_ID = "CD_START_CYCLE_ID"
COL_NAME_CD_START_CYCLE_COUNTER = "CD_START_CYCLE_COUNTER"
COL_NAME_CD_SEQUENZMTTIMESTAMPSTOP = "SEQUENZMTTIMESTAMPSTOP"
COL_NAME_CD_STOP_CYCLE_ID = "CD_STOP_CYCLE_ID"
COL_NAME_CD_STOP_CYCLE_COUNTER = "CD_STOP_CYCLE_COUNTER"
COL_NAME_CD_GEN_CAR = "GEN_CAR"
COL_NAME_CD_GEN_TEST_SITE = "GEN_TEST_SITE"
COL_NAME_CD_GEN_CHRONO_RELEASE = "GEN_CHRONO_RELEASE"
COL_NAME_CD_GEN_KEYWORD = "GEN_KEYWORD"
COL_NAME_CD_GEN_SENSOR_TYPE = "GEN_SENSOR_TYPE"
COL_NAME_CD_GEN_SAMPLE = "GEN_SAMPLE"
COL_NAME_CD_GEN_SENSOR_NUMBER = "GEN_SENSOR_NUMBER"
COL_NAME_CD_CSF_CAR_LIGHT_SEVERAL = "CSF_CAR_LIGHT_SEVERAL"
COL_NAME_CD_CSF_WINDSCREEN = "CSF_WINDSCREEN"
COL_NAME_CD_CSF_IMAGE_TYPE = "CSF_IMAGE_TYPE"
COL_NAME_CD_GEN_CAR_MAKE = "GEN_CAR_MAKE"
COL_NAME_CD_GEN_CAR_TYPE = "GEN_CAR_TYPE"
COL_NAME_CD_GEN_CAR_OWNER = "GEN_CAR_OWNER"
COL_NAME_CD_START_DATATYPE = "CD_START_DATATYPE"
COL_NAME_CD_STOP_DATATYPE = "CD_STOP_DATATYPE"
COL_NAME_CD_SR_SEQ_SCENARIO = "SR_SEQUENCE_SCENARIO"

# general ldroi collums
COL_NAME_LDROI_TIMESTAMP = "FRAMEMTLDROITIMESTAMP"
COL_NAME_LDROI_CYCLE_ID = "LDROI_CYCLE_ID"
COL_NAME_LDROI_CYCLE_COUNTER = "LDROI_CYCLE_COUNTER"
COL_NAME_LDROI_TRACK_ID = "ROI_TRACK_ID"
COL_NAME_LDROI_COORDINATE_X_1 = "ROI_COORDINATE_X_1"
COL_NAME_LDROI_COORDINATE_Y_1 = "ROI_COORDINATE_Y_1"
COL_NAME_LDROI_COORDINATE_X_2 = "ROI_COORDINATE_X_2"
COL_NAME_LDROI_COORDINATE_Y_2 = "ROI_COORDINATE_Y_2"
COL_NAME_LDROI_COORDINATE_X_3 = "ROI_COORDINATE_X_3"
COL_NAME_LDROI_COORDINATE_Y_3 = "ROI_COORDINATE_Y_3"
COL_NAME_LDROI_COORDINATE_X_4 = "ROI_COORDINATE_X_4"
COL_NAME_LDROI_COORDINATE_Y_4 = "ROI_COORDINATE_Y_4"
COL_NAME_LDROI_COORDINATE_X_5 = "ROI_COORDINATE_X_5"
COL_NAME_LDROI_COORDINATE_Y_5 = "ROI_COORDINATE_Y_5"
COL_NAME_LDROI_COORDINATE_X_6 = "ROI_COORDINATE_X_6"
COL_NAME_LDROI_COORDINATE_Y_7 = "ROI_COORDINATE_Y_6"
COL_NAME_LDROI_COORD_QUANTITY = "ROI_QUANTATY_OF_COORDINATES"
COL_NAME_LDROI_DATATYPE = "LDROI_DATATYPE"
COL_NAME_LDROI_BRAKE_LIGHTS = "BRAKE_LIGHTS"
COL_NAME_LDROI_CAM_BOTTOM = "CAM_OBJ_EDGE_VISIBILITY_BOTTOM"
COL_NAME_LDROI_CAM_LEFT = "CAM_OBJ_EDGE_VISIBILITY_LEFT"
COL_NAME_LDROI_CAM_RIGHT = "CAM_OBJ_EDGE_VISIBILITY_RIGHT"
COL_NAME_LDROI_CAM_TOP = "CAM_OBJ_EDGE_VISIBILITY_TOP"
COL_NAME_LDROI_CAM_SIGNAL = "CAM_OBJ_LIGHT_SIGNAL"
COL_NAME_LDROI_FOD_OBJ = "FOD_COVERED_OBJECT"
COL_NAME_LDROI_FOD_OBJ2 = "FOD_COVERED_OBJECT_2ND"
COL_NAME_LDROI_FOD_DIRECTION = "FOD_DIRECTION"
COL_NAME_LDROI_FOD_OBJ_FRAGMENT = "FOD_FRAGMENTARY_OBJECT"
COL_NAME_LDROI_FOD_PED = "FOD_PEDESTRIAN"
COL_NAME_LDROI_FOD_VIEW = "FOD_VIEW"
COL_NAME_LDROI_GEN_LANE = "GEN_LANE_OFFSET"
COL_NAME_LDROI_GEN_OBJ = "GEN_OBJECT_TYPE"
COL_NAME_LDROI_GEN_OBJ_MOVE = "GEN_OBJ_IS_MOVING_OVER_GROUND"
COL_NAME_LDROI_GEN_TARGET = "GEN_TARGET_TYPE"
COL_NAME_LDROI_OD_BOTTOM = "OD_COVERED_FROM_BOTTOM"
COL_NAME_LDROI_OD_LEFT = "OD_COVERED_FROM_LEFT"
COL_NAME_LDROI_OD_RIGHT = "OD_COVERED_FROM_RIGHT"
COL_NAME_LDROI_OD_TOP = "OD_COVERED_FROM_TOP"
COL_NAME_LDROI_OD_ACCESSORY = "PED_CARRY_ACCESSORY"
COL_NAME_LDROI_PED = "PED_GROUP"
COL_NAME_LDROI_PED_PED = "PED_PEDESTRIAN"
COL_NAME_LDROI_PED_VEHICLE = "PED_VEHICLE"
COL_NAME_LDROI_PED_INDICATOR = "TURN_INDICATOR"

# general ldss collums
COL_NAME_LDSS_TIMESTAMP_START = "FRAMEMTLDSSTIMESTAMPSTART"
COL_NAME_LDSS_TIMESTAMP_STOP = "FRAMEMTLDSSTIMESTAMPSTOP"
COL_NAME_LDSS_PED_NO_PEDESTRIAN = "PED_NO_PEDESTRIAN"
COL_NAME_LDSS_PED_PEDS = "PED_PEDESTRIAN_S"
COL_NAME_LDSS_CSF_CHANGING_LIGHT = "CSF_CHANGING_LIGHT_CONDITIONS"
COL_NAME_LDSS_CSF_CONTAMINATION = "CSF_CONTAMINATION"
COL_NAME_LDSS_CSF_LIGHT = "CSF_LIGHT_CONDITIONS"
COL_NAME_LDSS_CSF_SUN = "CSF_SUN_POSITION"
COL_NAME_LDSS_GEN_COUNTRY = "GEN_COUNTRY"
COL_NAME_LDSS_GEN_SPEED = "GEN_EGO_SPEED"
COL_NAME_LDSS_GEN_ROAD = "GEN_ROAD_TYPE"
COL_NAME_LDSS_GEN_ROADWORKS = "GEN_ROAD_WORKS"
COL_NAME_LDSS_GEN_SPECIAL_WEATHER = "GEN_SPECIAL_WEATHER_CONDITIONS"
COL_NAME_LDSS_GEN_STATE = "GEN_STATE"
COL_NAME_LDSS_GEN_STREET = "GEN_STREET_CONDITIONS"
COL_NAME_LDSS_GEN_TUNNEL = "GEN_TUNNEL"
COL_NAME_LDSS_GEN_WEATHER = "GEN_WEATHER"
COL_NAME_LDSS_START_CYCLE = "LDSS_START_CYCLE_COUNTER"
COL_NAME_LDSS_START_CYCLE_ID = "LDSS_START_CYCLE_ID"
COL_NAME_LDSS_START_DTYPE = "LDSS_START_DATATYPE"
COL_NAME_LDSS_STOP_CYCLE = "LDSS_STOP_CYCLE_COUNTER"
COL_NAME_LDSS_STOP_CYCLE_ID = "LDSS_STOP_CYCLE_ID"
COL_NAME_LDSS_STOP_DTYPE = "LDSS_STOP_DATATYPE"
COL_NAME_LDSS_OD_BC = "OD_BC_ALL_LABELED"
COL_NAME_LDSS_OD_BIKE = "OD_BIKE_ALL_LABELED"
COL_NAME_LDSS_OD_MB = "OD_MB_ALL_LABELED"
COL_NAME_LDSS_OD_MC = "OD_MC_ALL_LABELED"
COL_NAME_LDSS_OD_PED = "OD_PED_ALL_LABELED"
COL_NAME_LDSS_OD_UNKN = "OD_UNKN_ALL_LABELED"
COL_NAME_LDSS_OD_VEHICLE = "OD_VEHICLE_ALL_LABELED"

# consts
DEFAULD_TIMESTAMP_THRESHOLD = 61000

IDENT_STRING = "dbcam"


# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class BaseCameraLabelDB(BaseDB):  # pylint: disable=R0904
    """Base implementation of the camera label Database"""
    #====================================================================
    # Constraint DB Libary Interface for public use
    #====================================================================

    #====================================================================
    # Handling of database
    #====================================================================

    def __init__(self, db_connection, table_prefix, sql_factory, error_tolerance, **kwargs):
        """Initialize constraint database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseDB.__init__(self, db_connection, table_prefix, sql_factory, IDENT_STRING)
        self.sync_slave_reload_all = False
        self.error_tolerance = error_tolerance

        self._tableNames = None
        self._tableBasis = None
        self.setTableNames(kwargs.get('tableBase', 'MFC400'),
                           kwargs.get('component', 'SOD'),
                           kwargs.get('labelState', ''))

    @property
    def tableNames(self):
        """property to retrieve table names to be able to reference against
        """
        return self._tableNames

    def setTableNames(self, tableBase, component, labelState=""):
        """sets the table names, if there should be a need to change
        :param tableBase: basis, e.g. mfc400
        :param component: subcomponent of table name, e.g. SR, SOD, etc.
        :param labelState: either '' or 'interface' or 'archive'
        """
        self._tableBasis = (tableBase.upper(), component.upper(), labelState.upper())
        baseName = self._tableBasis[0] + "_" + self._tableBasis[1] + "_%s"
        if self._tableBasis[2] not in (None, ""):
            baseName += "_" + self._tableBasis[2]
        self._tableNames = (baseName % "CD", baseName % "LDROI", baseName % "LDSS")

    def __GetCameraTable(self, component, label_type, label_state):
        """Get the camera table name
        :param component: The component name ped, fod, pod ..
        :param label_type: The label type, cd, ldss, ldroi
        :param label_state: The normal, interface, archive
        :return: Returns the condition expression
        """
        base_name = self._tableBasis[0] + "_"
        base_name += (self._tableBasis[1] if component is None else component.upper()) + "_"
        base_name += self._tableBasis[2] if label_type is None else label_type.upper()

        if label_state == "interface":
            base_name += "_" + "INTERFACE"
        elif label_state == "archive":
            base_name += "_" + "ARCHIVE"
        elif label_state not in ("normal", "", None):
            warn("Label state is wrong! No such kind of labels: %s" % label_state)

        return base_name

    def __GetBaseCameraLabelCondition(self, recfilename, component, label_type, label_state):
        """Get the base camera table condition
        :param recfilename: The name of the recfile
        :param component: The component name ped, fod, pod ..
        :param label_type: The label type, cd, ldss, ldroi
        :param label_state: The normal, interface, archive
        :return: Returns the condition expression
        """
        table = self.__GetCameraTable(component, label_type, label_state)

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(table)),
                                         COL_NAME_REC_ID_FILE_NAME, True)), OP_EQ, SQLLiteral(recfilename.lower()))

        return cond

    def GetCameraLabels(self, recfilename, component=None, label_type=None, label_state=None, where=None):
        """Get camera label records.
        :param recfilename: The name of the recfile
        :param component: The component name ped, fod, pod ..
        :param label_type: The label type, cd, ldss, ldroi
        :param label_state: The normal, interface, archive
        :return: Returns the label record.
        """
        record = []

        table = self.__GetCameraTable(component, label_type, label_state)

        cond = self.__GetBaseCameraLabelCondition(recfilename, component, label_type, label_state)

        if where is not None:
            cond = SQLBinaryExpr(cond, OP_AND, where)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(table)], where=cond)
        if len(entries) <= 0:
            warn("No labeles found for table %s" % table)
        else:
            record = entries
        # done
        return record

    def GetCameraLabelsAtTs(self, recfilename, timestamp, component=None, label_type=None, label_state=None):
        """Get camera label records at timestamp.
        :param recfilename: The name of the recfile
        :param timestamp: search all labels at this timestamp
        :param component: The component name ped, fod, pod ..
        :param label_type: The label type, cd, ldss, ldroi
        :param label_state: The normal, interface, archive
        :return: Returns the label record.
        """
        record = []

        table = self.__GetCameraTable(component, label_type, label_state)

        cond = SQLBinaryExpr(self.__GetBaseCameraLabelCondition(recfilename, component, label_type, label_state),
                             OP_AND,
                             SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(table)),
                                                       COL_NAME_LDROI_TIMESTAMP, True)), OP_EQ, timestamp))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(table)], where=cond)
        if len(entries) <= 0:
            warn("No labeles found for table %s at timestamp %s and recfile %s" %
                 (table, timestamp, recfilename))
        else:
            record = entries

        return record

    def GetCameraLabelsPrevTs(self, recfilename, timestamp, component=None, label_type=None, label_state=None,
                              timestamp_threshold=DEFAULD_TIMESTAMP_THRESHOLD):
        """Get camera label records for previous step from timestamp.
        :param recfilename: The name of the recfile
        :param timestamp: search all labels at this timestamp
        :param component: The component name ped, fod, pod ..
        :param label_type: The label type, cd, ldss, ldroi
        :param label_state: The normal, interface, archive
        :return: Returns the label record, if a label is found within a threshold value, otherwise retern None.
        """
        record = []

        table = self.__GetCameraTable(component, label_type, label_state)
        # select max(ifc."FrameMtLDROITimeStamp") from sautners."MFC300_PED_LDROI_INTERFACE" ifc
        # where ifc."RecIdFileName" = 'Continuous_2011.09.11_at_16.27.29.rec' and
        # ifc."FrameMtLDROITimeStamp" <= 168318175
        # order by ifc."FrameMtLDROITimeStamp" desc

        timestampcol = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(table)), COL_NAME_LDROI_TIMESTAMP, True)

        cond = SQLBinaryExpr(self.__GetBaseCameraLabelCondition(recfilename, component, label_type, label_state),
                             OP_AND,
                             SQLBinaryExpr(timestampcol, OP_LEQ, timestamp))

        select = [SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_MAX], timestampcol),
                                OP_AS, COL_NAME_LDROI_TIMESTAMP)]

        order_expr = [timestampcol]

        entries = self.SelectGenericData(select_list=select, table_list=[self.GetQualifiedTableName(table)],
                                         where=cond, order_by=order_expr)
        prev_timestamp = None
        if len(entries) <= 0:
            warn("No labeles with lower timestamp %s found for table %s and recording %s" %
                 (timestamp, table, recfilename))
        else:
            prev_timestamp = entries[0][COL_NAME_LDROI_TIMESTAMP.upper()]

        if prev_timestamp is not None and (timestamp - prev_timestamp < timestamp_threshold):
            record = self.GetCameraLabelsAtTs(recfilename, prev_timestamp, component, label_type, label_state)
        else:
            record = None

        return record

    def GetCameraLabelsNextTs(self, recfilename, timestamp, component=None, label_type=None, label_state=None,
                              timestamp_threshold=DEFAULD_TIMESTAMP_THRESHOLD):
        """Get camera label records for next step from timestamp.
        :param recfilename: The name of the recfile
        :param timestamp: search all labels at this timestamp
        :param component: The component name ped, fod, pod ..
        :param label_type: The label type, cd, ldss, ldroi
        :param label_state: The normal, interface, archive
        :return: Returns the label record, if a label is found within a threshold value, otherwise retern None.
        """
        record = []

        table = self.__GetCameraTable(component, label_type, label_state)
        # select max(ifc."FrameMtLDROITimeStamp") from sautners."MFC300_PED_LDROI_INTERFACE" ifc
        # where ifc."RecIdFileName" = 'Continuous_2011.09.11_at_16.27.29.rec' and
        # ifc."FrameMtLDROITimeStamp" <= 168318175
        # order by ifc."FrameMtLDROITimeStamp" desc

        timestampcol = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(table)), COL_NAME_LDROI_TIMESTAMP, True)

        cond = SQLBinaryExpr(self.__GetBaseCameraLabelCondition(recfilename, component, label_type, label_state),
                             OP_AND,
                             SQLBinaryExpr(timestampcol, OP_GEQ, timestamp))

        select = [SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_MAX], timestampcol),
                  OP_AS, COL_NAME_LDROI_TIMESTAMP)]

        order_expr = [timestampcol]

        entries = self.SelectGenericData(select_list=select, table_list=[self.GetQualifiedTableName(table)],
                                         where=cond, order_by=order_expr)
        prev_timestamp = None
        if len(entries) <= 0:
            warn("No labeles with higher timestamp %s found for table %s and recording %s" %
                 (timestamp, table, recfilename))
        else:
            prev_timestamp = entries[0][COL_NAME_LDROI_TIMESTAMP.upper()]

        if prev_timestamp is not None and (timestamp - prev_timestamp < timestamp_threshold):
            record = self.GetCameraLabelsAtTs(recfilename, prev_timestamp, component, label_type, label_state)
        else:
            record = None

        return record

    def GetRoiTrackIds(self, recfilename, component=None, label_type=None, label_state=None):
        """Get camera label records for next step from timestamp.
        :param recfilename: The name of the recfile
        :param component: The component name ped, fod, pod ..
        :param label_type: The label type, cd, ldss, ldroi
        :param label_state: The normal, interface, archive
        :return: Returns the label trackids.
        """
        record = None

        table = self.__GetCameraTable(component, label_type, label_state)

        cond = self.__GetBaseCameraLabelCondition(recfilename, component, label_type, label_state)

        trackidcol = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(table)), COL_NAME_LDROI_TRACK_ID, True)

        select = [SQLBinaryExpr(trackidcol, OP_AS, COL_NAME_LDROI_TRACK_ID)]

        entries = self.SelectGenericData(select_list=select, table_list=[self.GetQualifiedTableName(table)],
                                         where=cond, order_by=[trackidcol], distinct_rows=True)
        if len(entries) <= 0:
            warn("No labeles found for table %s" % table)
        else:
            record = []
            for item in entries:
                record.append(int(item[COL_NAME_LDROI_TRACK_ID]))
        # done
        return record

    def GetObjectWithTrackId(self, recfilename, track_id, component=None, label_type=None, label_state=None):
        """Get camera label records for next step from timestamp.
        :param recfilename: The name of the recfile
        :param track_id: The labeled object track id
        :param component: The component name ped, fod, pod ..
        :param label_type: The label type, cd, ldss, ldroi
        :param label_state: The normal, interface, archive
        :return: Returns the label trackids.
        """
        record = None

        table = self.__GetCameraTable(component, label_type, label_state)

        trackidcol = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(table)), COL_NAME_LDROI_TRACK_ID, True)

        timestampcol = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(table)), COL_NAME_LDROI_TIMESTAMP, True)

        cond = self.__GetBaseCameraLabelCondition(recfilename, component, label_type, label_state)

        cond = SQLBinaryExpr(cond,
                             OP_AND,
                             SQLBinaryExpr(trackidcol, OP_EQ, track_id))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(table)],
                                         where=cond, order_by=[timestampcol])
        if len(entries) <= 0:
            warn("No labeles found for table %s" % table)
        else:
            record = entries

        # done
        return record

    def Initialize(self):
        """Initialize the database proxy"""
        # Setup function names
        BaseDB.Initialize(self)
        self.db_func_map[DB_FUNC_NAME_MIN] = "MIN"
        self.db_func_map[DB_FUNC_NAME_MAX] = "MAX"

    def Terminate(self):
        """Terminate the database proxy"""
        BaseDB.Terminate(self)


#====================================================================
# Constraint DB Libary SQL Server Compact Implementation
#====================================================================
class SQLCECameraLabelDB(BaseCameraLabelDB, SQLCEBaseDB):  # pylint: disable=R0904
    """SQL Server Compact Edition Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE, **kwargs):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseCameraLabelDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance, **kwargs)
        SQLCEBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseCameraLabelDB.Initialize(self)
        SQLCEBaseDB.Initialize(self)


class OracleCameraLabelDB(BaseCameraLabelDB, OracleBaseDB):  # pylint: disable=R0904
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE, **kwargs):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseCameraLabelDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance, **kwargs)
        OracleBaseDB.__init__(self)

        # self.date_time_format = "TO_DATE('%d.%m.%Y %H:%M:%S','DD.MM.YYYY HH24:MI:SS')"
        self.date_time_format = "%d.%m.%Y %H:%M:%S"

    def Initialize(self):
        """Initialize the database proxy"""
        BaseCameraLabelDB.Initialize(self)
        OracleBaseDB.Initialize(self)


class SQLite3CameraLabelDB(BaseCameraLabelDB, SQLite3BaseDB):  # pylint: disable=R0904
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE, **kwargs):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseCameraLabelDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance, **kwargs)
        SQLite3BaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseCameraLabelDB.Initialize(self)
        SQLite3BaseDB.Initialize(self)


""" Python library to access camera lables

$Log: camlabel.py  $
Revision 1.1 2021/12/13 17:56:22CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/lbl/project.pj
Revision 1.20 2013/08/07 11:05:22CEST Mertens, Sven (uidv7805) 
changed header info from genlabel to camlabel
- Added comments -  uidv7805 [Aug 7, 2013 11:05:22 AM CEST]
Change Package : 192785:1 http://mks-psad:7002/im/viewissue?selection=192785
Revision 1.19 2013/08/02 15:39:35CEST Mertens, Sven (uidv7805)
bugfixing recidfilename define
Revision 1.18 2013/06/25 15:35:43CEST Mertens, Sven (uidv7805)
fixing defines to be capital letters as well as column names to be consistent
--- Added comments ---  uidv7805 [Jun 25, 2013 3:35:44 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.17 2013/06/20 15:24:35CEST Mertens, Sven (uidv7805)
1) as initial DB base names can be set via init or setTableNames,
they should be optional by methods now.
2) adding additional defines for label columns specific for SOD;
maybe we should think about moving them seperatly as there
could be hundreds throughout lbl db.
--- Added comments ---  uidv7805 [Jun 20, 2013 3:24:35 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.16 2013/06/13 13:06:45CEST Mertens, Sven (uidv7805)
alignment of table base name,
method setTableNames must be used when going via observers as BaseDB interface is limited.
__GetCameraTable is using this basis then.
--- Added comments ---  uidv7805 [Jun 13, 2013 1:06:45 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.15 2013/04/26 15:39:07CEST Mertens, Sven (uidv7805)
resolving some pep8 / pylint errors
--- Added comments ---  uidv7805 [Apr 26, 2013 3:39:08 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.14 2013/04/26 10:46:01CEST Mertens, Sven (uidv7805)
moving strIdent
Revision 1.13 2013/04/26 10:05:40CEST Mertens, Sven (uidv7805)
added init params for table base like MFC400 and function prefix
as well as a getter for the table names
--- Added comments ---  uidv7805 [Apr 26, 2013 10:05:41 AM CEST]
Change Package : 179495:4 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.12 2013/04/25 14:35:10CEST Mertens, Sven (uidv7805)
epydoc adaptation to colon instead of at
--- Added comments ---  uidv7805 [Apr 25, 2013 2:35:11 PM CEST]
Change Package : 179495:2 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.11 2013/04/19 13:38:59CEST Hecker, Robert (heckerr)
Functionality reverted to revision 1.9.
--- Added comments ---  heckerr [Apr 19, 2013 1:38:59 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.10 2013/04/12 14:37:01CEST Mertens, Sven (uidv7805)
adding a short representation used by db_connector.PostInitialize
--- Added comments ---  uidv7805 [Apr 12, 2013 2:37:02 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.9 2013/04/02 10:24:57CEST Mertens, Sven (uidv7805)
pylint: E0213, E1123, E9900, E9904, E1003, E9905, E1103
--- Added comments ---  uidv7805 [Apr 2, 2013 10:24:58 AM CEST]
Change Package : 176171:9 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.8 2013/03/27 11:37:21CET Mertens, Sven (uidv7805)
pep8 & pylint: rowalignment and error correction
Revision 1.7 2013/03/26 16:19:22CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:23 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/13 17:52:59CET Hecker, Robert (heckerr)
Added needed changes for Zhang.
--- Added comments ---  heckerr [Mar 13, 2013 5:52:59 PM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.5 2013/02/28 08:12:16CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:16 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/27 16:19:53CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:53 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/19 14:07:28CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:28 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/13 09:43:56CET Hecker, Robert (heckerr)
Added missing import.
--- Added comments ---  heckerr [Feb 13, 2013 9:43:56 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 09:58:40CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/db/lbl/project.pj
------------------------------------------------------------------------------
-- From ETK/ADAS_DB Archive
------------------------------------------------------------------------------
Revision 1.3 2012/10/12 08:45:55CEST Spruck, Jochen (spruckj)
add special camera table defines
--- Added comments ---  spruckj [Oct 12, 2012 8:45:55 AM CEST]
Change Package : 93947:1 http://mks-psad:7002/im/viewissue?selection=93947
Revision 1.2 2012/10/12 08:40:46CEST Spruck, Jochen (spruckj)
add revision log tabel
Revision 1.1 2012/04/27 12:18:29CEST Spruck, Jochen (spruckj)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
PED_PedestrianRecognition/05_Testing/05_Test_Environment/algo/ped_reqtests/valf_tests/adas_database/lb/project.pj
"""
