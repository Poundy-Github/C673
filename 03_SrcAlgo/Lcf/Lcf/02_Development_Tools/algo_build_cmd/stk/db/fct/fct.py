"""
stk/db/fct/fct.py
-------------------

Classes for Database access of FCT Label Tables.

 Sub-Scheme FCT


:org:           Continental AG
:author:        Sohaib Zafar

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:11CET $
"""

# pylint: disable=C0103

# Import Python Modules ----------------------------------------------------------------------------------------------
import logging

# Import STK Modules -------------------------------------------------------------------------------------------------
from ..db_common import BaseDB, ERROR_TOLERANCE_NONE, DB_FUNC_NAME_MIN, DB_FUNC_NAME_MAX, DB_FUNC_NAME_LOWER, \
    DB_FUNC_NAME_UPPER, AdasDBError, SQLCEBaseDB, AdasDBNotImplemented, OracleBaseDB, \
    SQLite3BaseDB
from ..db_sql import GenericSQLStatementFactory, SQLBinaryExpr, SQLFuncExpr, OP_EQ, OP_NEQ, SQLLiteral, OP_AND

#======================================================================================================================
# Constants
#======================================================================================================================
# Table base names:
TABLE_NAME_CRITICALITY = "FCT_CRITICALITY"
TABLE_NAME_EGOBEHAVIOUR = "FCT_EGOBEHAVIOUR"
TABLE_NAME_SCENARIO = "FCT_SCENARIO"
TABLE_NAME_ENVIRONMENT = "FCT_ENVIRONMENT"
TABLE_NAME_ENVIRONMENT_TYPE = "FCT_ENVIRONMENT_TYPE"

# Criticality Table
COL_NAME_CRITICALITY_CID = "CID"
COL_NAME_CRITICALITY_NAME = "NAME"
COL_NAME_CRITICALITY_DESC = "DESCRIPTION"

# EgoBehaviour Table
COL_NAME_EGOBEHAVIOUR_EBID = "EBID"
COL_NAME_EGOBEHAVIOUR_NAME = "NAME"
COL_NAME_EGOBEHAVIOUR_DESC = "DESCRIPTION"

# Environment Table
COL_NAME_ENVIRONMENT_ENVID = "ENVID"
COL_NAME_ENVIRONMENT_NAME = "NAME"
COL_NAME_ENVIRONMENT_ENVTYPEID = "ENVTYPEID"
COL_NAME_ENVIRONMENT_DESC = "DESCRIPTION"

# Environment Type Table
COL_NAME_ENVIRONMENT_TYPE_ENVTYPEID = "ENVTYPEID"
COL_NAME_ENVIRONMENT_TYPE_NAME = "NAME"
COL_NAME_ENVIRONMENT_TYPE_DESC = "DESCRIPTION"

# Scenario Table
COL_NAME_SCENARIO_SCENARIOID = "SCENARIOID"
COL_NAME_SCENARIO_MEASID = "MEASID"
COL_NAME_SCENARIO_STARTABSTS = "STARTABSTS"
COL_NAME_SCENARIO_ENDABSTS = "ENDABSTS"
COL_NAME_SCENARIO_LBLCOMMENT = "LBLCOMMENT"
COL_NAME_SCENARIO_ENV_INFRASTRUCTURE = "ENV_INFRASTRUCTURE"
COL_NAME_SCENARIO_ENV_LIGHT_CONDITION = "ENV_LIGHT_CONDITION"
COL_NAME_SCENARIO_ENV_WEATHER_CONDITION = "ENV_WEATHER_CONDITION"
COL_NAME_SCENARIO_ENV_DATAINTEGRITY = "ENV_DATAINTEGRITY"
COL_NAME_SCENARIO_LABELER_CRITICALITY = "LABELER_CRITICALITY"
COL_NAME_SCENARIO_VEHICLE_CRITICALITY = "VEHICLE_CRITICALITY"
COL_NAME_SCENARIO_DRIVER_CRITICALITY = "DRIVER_CRITICALITY"
COL_NAME_SCENARIO_LBLSTATEID = "LBLSTATEID"
COL_NAME_SCENARIO_LBLBY = "LBLBY"
COL_NAME_SCENARIO_LBLTIME = "LBLTIME"
COL_NAME_SCENARIO_PID = "PID"
COL_NAME_SCENARIO_RECTOBJID = "RECTOBJID"
COL_NAME_SCENARIO_EGO_BEHAVIOR = "EGO_BEHAVIOR"
COL_NAME_SCENARIO_REL_EGO_BEHAVIOR = "REL_EGO_BEHAVIOR"
COL_NAME_SCENARIO_OBJ_DYNAMIC = "OBJ_DYNAMIC"
COL_NAME_SCENARIO_OBJ_TYPE = "OBJ_TYPE"
COL_NAME_SCENARIO_OBJ_BEHAVIOR = "OBJ_BEHAVIOR"

IDENT_STRING = "dbfct"

#======================================================================================================================
# Constraint DB Libary Base Implementation
#======================================================================================================================


class BaseFctDB(BaseDB):
    """Base implementation of the Rec File Database"""
    #====================================================================
    # Constraint DB Libary Interface for public use
    #====================================================================

    #====================================================================
    # Handling of database
    #====================================================================

    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
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
        self.db_func_map[DB_FUNC_NAME_LOWER] = "LOWER"
        self.db_func_map[DB_FUNC_NAME_UPPER] = "UPPER"

    def Terminate(self):
        """Terminate the database proxy"""
        BaseDB.Terminate(self)

    #====================================================================
    # Handling of Criticality
    #====================================================================
    def AddCriticality(self, criticality):
        """Add criticality state to database.
        :param criticality: The criticality record.
        :return: Returns the criticality ID.
        """
        entries = self.GetCriticality(criticality[COL_NAME_CRITICALITY_NAME].upper())
        if len(entries) <= 0:
            criticality[COL_NAME_CRITICALITY_NAME] = criticality[COL_NAME_CRITICALITY_NAME].upper()
            self.AddGenericData(criticality, self.GetQualifiedTableName(TABLE_NAME_CRITICALITY))
        else:
            tmp = "Criticality name '%s' " % (criticality[COL_NAME_CRITICALITY_NAME])
            tmp += "already exists in the database."
            raise AdasDBError(tmp)
        cid = self.__GetCriticalityID(criticality[COL_NAME_CRITICALITY_NAME].upper())
        return cid

    def UpdateCriticality(self, criticality, where=None):
        """Update existing criticality records.
        :param keyword: The criticality record update.
        :param where: The condition to be fulfilled by the criticality to the updated, by default based on ID.
        :return: Returns the number of affected criticality.
        """
        rowcount = 0
        if where is None:
            where = SQLBinaryExpr(COL_NAME_CRITICALITY_CID, OP_EQ, criticality[COL_NAME_CRITICALITY_CID])
        if (criticality is not None) and (len(criticality) != 0):
            rowcount = self.UpdateGenericData(criticality, self.GetQualifiedTableName(TABLE_NAME_CRITICALITY), where)
        return rowcount

    def DeleteCriticality(self, criticality):
        """Delete existing criticality records.
        :param keyword: The criticality record update.
        :return: Returns the number of affected criticality.
        """
        rowcount = 0
        if (criticality is not None) and (len(criticality) != 0):
            cond = self.__GetCriticalityCondition(criticality[COL_NAME_CRITICALITY_NAME].upper())
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_CRITICALITY), where=cond)
        return rowcount

    def GetCriticality(self, name):
        """Get existing criticality records.
        :param name: The criticality name.
        :return: Returns the criticality record.
        """
        record = {}
        cond = self.__GetCriticalityCondition(name)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_CRITICALITY)], where=cond)
        if len(entries) <= 0:
            logging.info(str("Criticality with name '%s' does not exists in the FCT  database." % name))
        elif len(entries) > 1:
            logging.warn(str("Criticality with name '%s' cannot be resolved because it is ambiguous." % (name)))
            record = entries
        else:
            record = entries[0]
        return record

    def __GetCriticalityID(self, name):
        """Get existing criticality records.
        :param name: The criticality name.
        :return: Returns the criticality record.
        """
        record = self.GetCriticality(name)
        if COL_NAME_CRITICALITY_CID in record:
            return record[COL_NAME_CRITICALITY_CID]
        else:
            return None

    def __GetCriticalityCondition(self, name):
        """Get the condition expression to access the criticality.
        :param name: Name of the criticality
        :param check_point: checkpoint
        :return: Returns the condition expression
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_UPPER],
                             COL_NAME_CRITICALITY_NAME), OP_EQ, SQLLiteral(name.upper()))
        return cond

    #====================================================================
    # Handling of Ego Behaviour
    #====================================================================
    def AddEgoBehaviour(self, EgoBehaviour):
        """Add EgoBehaviour state to database.
        :param EgoBehaviour: The EgoBehaviour record.
        :return: Returns the EgoBehaviour ID.
        """
        entries = self.GetEgoBehaviour(EgoBehaviour[COL_NAME_EGOBEHAVIOUR_NAME].lower())
        if len(entries) <= 0:
            EgoBehaviour[COL_NAME_EGOBEHAVIOUR_NAME] = EgoBehaviour[COL_NAME_EGOBEHAVIOUR_NAME].lower()
            self.AddGenericData(EgoBehaviour, self.GetQualifiedTableName(TABLE_NAME_EGOBEHAVIOUR))
        else:
            tmp = "Ego Behaviour name '%s' " % (EgoBehaviour[COL_NAME_EGOBEHAVIOUR_NAME])
            tmp += "already exists in the database. "
            raise AdasDBError(tmp)
        ebid = self.GetEgoBehaviourID(EgoBehaviour[COL_NAME_CRITICALITY_NAME].lower())
        return ebid

    def UpdateEgoBehaviour(self, EgoBehaviour, where=None):
        """Update existing EgoBehaviour records.
        :param keyword: The EgoBehaviour record update.
        :param where: The condition to be fulfilled by the EgoBehaviour to the updated, by default based on ID.
        :return: Returns the number of affected EgoBehaviour.
        """
        rowcount = 0
        if where is None:
            where = SQLBinaryExpr(COL_NAME_EGOBEHAVIOUR_EBID, OP_EQ, EgoBehaviour[COL_NAME_EGOBEHAVIOUR_EBID])
        if (EgoBehaviour is not None) and (len(EgoBehaviour) != 0):
            rowcount = self.UpdateGenericData(EgoBehaviour, self.GetQualifiedTableName(TABLE_NAME_EGOBEHAVIOUR), where)
        return rowcount

    def DeleteEgoBehaviour(self, EgoBehaviour):
        """Delete existing EgoBehaviour records.
        :param keyword: The EgoBehaviour record update.
        :return: Returns the number of affected EgoBehaviour.
        """
        rowcount = 0
        if (EgoBehaviour is not None) and (len(EgoBehaviour) != 0):
            cond = self.__GetEgoBehaviourCondition(EgoBehaviour[COL_NAME_EGOBEHAVIOUR_NAME])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_EGOBEHAVIOUR), where=cond)
        return rowcount

    def GetEgoBehaviour(self, name):
        """Get existing EgoBehaviour records.
        :param name: The EgoBehaviour name.
        :return: Returns the EgoBehaviour record.
        """
        record = {}
        cond = self.__GetEgoBehaviourCondition(name)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EGOBEHAVIOUR)], where=cond)
        if len(entries) <= 0:
            logging.info(str("EgoBehaviour with name '%s' does not exists in the FCT  database." % name))
        elif len(entries) > 1:
            logging.warn(str("EgoBehaviour with name '%s' cannot be resolved because it is ambiguous. (%s)" %
                             (name, entries)))
            record = entries
        else:
            record = entries[0]
        return record

    def GetEgoBehaviorNames(self):
        """Get all existing EgoBehaviour names.
        :return: Returns the EgoBehaviour record names.
        """
        record_name = []
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_EGOBEHAVIOUR)])
        if len(entries) <= 0:
            logging.warn(str("EgoBehaviours do not exist in the FCT  database."))
        else:
            for i in range(0, len(entries)):
                record_name.append(entries[i][COL_NAME_EGOBEHAVIOUR_NAME])
        return record_name

    def GetEgoBehaviourID(self, name):
        """Get existing EgoBehaviour records.
        :param name: The EgoBehaviour name.
        :return: Returns the EgoBehaviour record.
        """
        record = self.GetEgoBehaviour(name)
        if COL_NAME_EGOBEHAVIOUR_EBID in record:
            return record[COL_NAME_EGOBEHAVIOUR_EBID]
        else:
            return None

    def __GetEgoBehaviourCondition(self, name):
        """Get the condition expression to access the EgoBehaviour.
        :param name: Name of the EgoBehaviour
        :param check_point: checkpoint
        :return: Returns the condition expression
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                             COL_NAME_CRITICALITY_NAME), OP_EQ, SQLLiteral(name.lower()))
        return cond

    #====================================================================
    # Handling of Environment
    #====================================================================
    def GetEnvironmentNamesforType(self, envtypeid):
        """Get existing Environment names.
        :param envtypeid: The Environment name.
        :return: Returns the Environment names related to an environment type.
        """
        record_name = []
        cond = SQLFuncExpr(COL_NAME_ENVIRONMENT_ENVTYPEID, OP_EQ, envtypeid)
        entries = self.SelectGenericData(select_list=[COL_NAME_ENVIRONMENT_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_ENVIRONMENT)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Environment with type id '%s' does not exists in the FCT  database." % envtypeid))
        else:
            for i in range(0, len(entries)):
                record_name.append(entries[i][COL_NAME_ENVIRONMENT_NAME])
        return record_name

    def GetEnvironmentID(self, name):
        """Get existing Environment ID.
        :param name: The Environment name.
        :return: Returns the Environment ID.
        """
        cond = self.__GetEnvironmentCondition(name)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ENVIRONMENT)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Environment with name '%s' does not exists in the FCT  database." % name))
        elif len(entries) > 1:
            logging.warn(str("Environment with name '%s' cannot be resolved because it is ambiguous." % (name)))
        else:
            record_id = entries[0][COL_NAME_ENVIRONMENT_ENVID]
        return record_id

    def __GetEnvironmentCondition(self, name):
        """Get the condition expression to access the EgoBehaviour.
        :param envtypeid: Name of the Environment
        :param check_point: checkpoint
        :return: Returns the condition expression
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                             COL_NAME_ENVIRONMENT_NAME), OP_EQ, SQLLiteral(name.lower()))
        return cond

    #====================================================================
    # Handling of Scenario
    #====================================================================
    def AddScenario(self, scenario):
        """Add Scenario state to database.
        :param Scenario: The Scenario record.
        :return: Returns the Scenario ID.
        """
        if scenario[COL_NAME_SCENARIO_STARTABSTS] >= scenario[COL_NAME_SCENARIO_ENDABSTS]:
            tmp = "(TimeIntegrityError) Scenario Begin Timestamp is not less than the Scenario End timestamp."
            raise AdasDBError(tmp)
        cond = self.__GetScenarioCondition(scenario[COL_NAME_SCENARIO_MEASID])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_SCENARIO)], where=cond)
        if len(entries) <= 0:
            self.AddGenericData(scenario, self.GetQualifiedTableName(TABLE_NAME_SCENARIO))
        else:
            tmp = "Measurement '%s' exists already in the generic label database" % scenario[COL_NAME_SCENARIO_MEASID]
            logging.info(tmp)
            overlap = self.__CheckOverlap(scenario, entries)
            if overlap is 0:
                self.AddGenericData(scenario, self.GetQualifiedTableName(TABLE_NAME_SCENARIO))
            else:
                tmp = "'%s' " % (scenario)
                tmp += "\n Scenario cannot be added to generic label database because the time range is overlapping \
                        with %s existing Scenario(s). " % (overlap)
                logging.warn(tmp)
                return -overlap
        scenario_id = self.__GetScenarioID(scenario)
        return scenario_id

    def __CheckOverlap(self, scenario, entries):
        """ Checking the time overlap of new and existing scenario in the label database related to same measurement
        :return: Returns the number of existing scenarios affected by the new Scenario
        """
        overlap = 0
        for i in range(0, len(entries)):
            if (scenario[COL_NAME_SCENARIO_MEASID] == entries[i][COL_NAME_SCENARIO_MEASID]):
                if ((scenario[COL_NAME_SCENARIO_STARTABSTS] >= entries[i][COL_NAME_SCENARIO_STARTABSTS] and
                     scenario[COL_NAME_SCENARIO_STARTABSTS] <= entries[i][COL_NAME_SCENARIO_ENDABSTS])
                    or (scenario[COL_NAME_SCENARIO_ENDABSTS] >= entries[i][COL_NAME_SCENARIO_STARTABSTS] and
                        scenario[COL_NAME_SCENARIO_ENDABSTS] <= entries[i][COL_NAME_SCENARIO_ENDABSTS])
                    or (entries[i][COL_NAME_SCENARIO_STARTABSTS] >= scenario[COL_NAME_SCENARIO_STARTABSTS] and
                        entries[i][COL_NAME_SCENARIO_STARTABSTS] <= scenario[COL_NAME_SCENARIO_ENDABSTS])
                    or (entries[i][COL_NAME_SCENARIO_ENDABSTS] >= scenario[COL_NAME_SCENARIO_STARTABSTS] and
                        entries[i][COL_NAME_SCENARIO_ENDABSTS] <= scenario[COL_NAME_SCENARIO_ENDABSTS])):
                    overlap = overlap + 1
                else:
                    pass
            else:
                tmp = "\n The check for overlap doesn't deal with the same measurement."
                raise AdasDBError(tmp)
        return overlap

    def UpdateScenario(self, scenario, where=None, updated_start=None, updated_end=None):
        """Update existing Scenario records.
        :param keyword: The Scenario record update.
        :param where: The condition to be fulfilled by the Scenario to the updated.
        :return: Returns the number of affected Scenario.
        """
        rowcount = 0
        cond1 = self.__GetScenarioCondition(scenario[COL_NAME_SCENARIO_MEASID])
        cond2 = SQLBinaryExpr(COL_NAME_SCENARIO_SCENARIOID, OP_NEQ, self.__GetScenarioID(scenario))
        cond = SQLBinaryExpr(cond1, OP_AND, cond2)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_SCENARIO)], where=cond)
        if where is None:
            where = self.__GetScenarioCondition(scenario[COL_NAME_SCENARIO_MEASID],
                                                scenario[COL_NAME_SCENARIO_STARTABSTS],
                                                scenario[COL_NAME_SCENARIO_ENDABSTS])
        if updated_start is not None:
            scenario[COL_NAME_SCENARIO_STARTABSTS] = updated_start
        if updated_end is not None:
            scenario[COL_NAME_SCENARIO_ENDABSTS] = updated_end
        if scenario[COL_NAME_SCENARIO_STARTABSTS] >= scenario[COL_NAME_SCENARIO_ENDABSTS]:
            tmp = "(TimeIntegrityError) Scenario Begin Timestamp is not less than the Scenario End timestamp."
            raise AdasDBError(tmp)
        if (scenario is not None) and (len(scenario) != 0):
            overlap = self.__CheckOverlap(scenario, entries)
            if overlap is 0:
                rowcount = self.UpdateGenericData(scenario, self.GetQualifiedTableName(TABLE_NAME_SCENARIO), where)
            else:
                tmp = "'%s' " % (scenario)
                tmp += "\n Scenario cannot be added to generic label database because the time range is overlapping \
                        with %s other existing Scenario(s). " % (overlap)
                raise AdasDBError(tmp)
        return rowcount

    def DeleteScenario(self, scenario):
        """Delete existing Scenario records.
        :param keyword: The Scenario record update.
        :return: Returns the number of affected Scenario.
        """
        rowcount = 0
        if (scenario is not None) and (len(scenario) != 0):
            if scenario[COL_NAME_SCENARIO_SCENARIOID] in scenario and \
                    (scenario[COL_NAME_SCENARIO_SCENARIOID] is not None):
                cond = SQLBinaryExpr(COL_NAME_SCENARIO_SCENARIOID, OP_EQ, scenario[COL_NAME_SCENARIO_SCENARIOID])
            else:
                cond = self.__GetScenarioCondition(scenario[COL_NAME_SCENARIO_MEASID],
                                                   scenario[COL_NAME_SCENARIO_STARTABSTS],
                                                   scenario[COL_NAME_SCENARIO_ENDABSTS])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_SCENARIO), where=cond)
        return rowcount

    def GetScenario(self, meas_id, start=None, end=None):
        """Get existing Scenario records.
        :param meas_id: The measurement id.
        :param start: The Scenario Start Timestamp.
        :param end: The The Scenario End Timestamp.
        :return: Returns the Scenario record.
        """
        record = {}
        if start is None or end is None:
            cond = self.__GetScenarioCondition(meas_id)
        else:
            cond = self.__GetScenarioCondition(meas_id, start, end)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_SCENARIO)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Scenario with meas_id '%s' does not exists in the FCT  database." % meas_id))
        elif len(entries) > 1:
            logging.warn(str("Scenario with meas_id '%s' cannot be resolved because it is ambiguous." % (meas_id)))
        else:
            record = entries[0]
        return record

    def __GetScenarioCondition(self, meas_id, start=None, end=None):
        """Get the condition expression to access the Scenario.
        :param meas_id: ID of the Measurement
        :return: Returns the condition expression
        """
        if start is None or end is None:
            cond = SQLBinaryExpr(COL_NAME_SCENARIO_MEASID, OP_EQ, meas_id)
        else:
            cond1 = SQLBinaryExpr(COL_NAME_SCENARIO_STARTABSTS, OP_EQ, SQLLiteral(start))
            cond2 = SQLBinaryExpr(COL_NAME_SCENARIO_ENDABSTS, OP_EQ, SQLLiteral(end))
            cond3 = SQLBinaryExpr(COL_NAME_SCENARIO_MEASID, OP_EQ, SQLLiteral(meas_id))
            cond_tmp = SQLBinaryExpr(cond1, OP_AND, cond2)
            cond = SQLBinaryExpr(cond_tmp, OP_AND, cond3)
        return cond

    def __GetScenarioID(self, scenario):
        """ Get existing Scenario ID
        """
        meas_id = scenario[COL_NAME_SCENARIO_MEASID]
        start = scenario[COL_NAME_SCENARIO_STARTABSTS]
        end = scenario[COL_NAME_SCENARIO_ENDABSTS]
        record = self.GetScenario(meas_id, start, end)
        if COL_NAME_SCENARIO_SCENARIOID in record:
            return record[COL_NAME_SCENARIO_SCENARIOID]
        else:
            return None

#====================================================================
# Constraint DB Libary SQL Server Compact Implementation
#====================================================================


class SQLCEFctDB(BaseFctDB, SQLCEBaseDB):
    """SQL Server Compact Edition Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseFctDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLCEBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseFctDB.Initialize(self)
        SQLCEBaseDB.Initialize(self)

    def GetTableNames(self):
        """ Get a list of table names for the database.
        :return: table_name_list
        """
        # To be implemeted.
        raise AdasDBNotImplemented("Method GetTableNames not implemented for SQL Server Compact Edition.")

    def GetColumnNames(self, table_name):
        """ Get a list of column names for a given table name.
        :param table_name: The name of the table.
        :return: column_name_list
        """
        raise AdasDBNotImplemented("Method GetColumnNames not implemented for SQL Server Compact Edition.")


class OracleFctDB(BaseFctDB, OracleBaseDB):
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseFctDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        OracleBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseFctDB.Initialize(self)
        OracleBaseDB.Initialize(self)

    def GetTableNames(self):
        """ Get a list of table names for the database.
        :return: table_name_list
        """
        select_list = ["TABLE_NAME"]
        pref = self.table_prefix.replace('.', '')
        cond = SQLBinaryExpr("OWNER", OP_EQ, SQLLiteral(pref))
        table_name_list_dict = self.SelectGenericData(select_list, ["ALL_TABLES"], where=cond)

        table_name_list = []
        for table_name_dict in table_name_list_dict:
            table_name_list.append(table_name_dict["TABLE_NAME"])
        return table_name_list

    def GetColumnNames(self, table_name):
        """ Get a list of column names for a given table name.
        :param table_name: The name of the table.
        :return: column_name_list
        """
        # SELECT column_name FROM all_tab_cols where table_name ='OBJ_KINEMATICS'
        select_list = ["column_name"]
        cond1 = SQLBinaryExpr("table_name", OP_EQ, SQLLiteral(table_name))
        pref = self.table_prefix.replace('.', '')
        cond2 = SQLBinaryExpr("OWNER", OP_EQ, SQLLiteral(pref))
        cond = SQLBinaryExpr(cond1, OP_AND, cond2)
        column_name_list_dict = self.SelectGenericData(select_list, ["all_tab_cols"], where=cond)
        column_name_list = []
        for column_name_dict in column_name_list_dict:
            column_name_list.append(column_name_dict["COLUMN_NAME"])
        return column_name_list


class SQLite3FctDB(BaseFctDB, SQLite3BaseDB):
    """SQLite Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseFctDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLite3BaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseFctDB.Initialize(self)
        SQLite3BaseDB.Initialize(self)

    def GetTableNames(self):
        """ Get a list of table names for the database.
        :return: table_name_list
        """
        select_list = ["name"]
        condition = SQLBinaryExpr("type", OP_EQ, SQLLiteral("table"))
        table_name_list_dict = self.SelectGenericData(select_list,
                                                      [self.GetQualifiedTableName("sqlite_master")],
                                                      condition)
        table_name_list = []
        for table_name_dict in table_name_list_dict:
            table_name_list.append(table_name_dict["NAME"])
        return table_name_list

    def GetColumnNames(self, table_name):
        """ Get a list of column names for a given table name.
        :return: column_name_list
        """
        # SELECT sql FROM sqlite_master WHERE tbl_name = 'table_name' AND type = 'table'
        # select_list = ["sql"]
        # cond1 = SQLBinaryExpr("tbl_name", OP_EQ, SQLLiteral(table_name))
        # cond2 = SQLBinaryExpr(SQLBinaryExpr("type", OP_EQ, SQLLiteral("table")), OP_AND, cond1)
        # column_name_list_dict = self.SelectGenericData(select_list,
        #                                              [self.GetQualifiedTableName("sqlite_master")],
        #                                              cond2)
        # Need to test. Did not work!

        column_name_list = []
        cursor = self.db_connection.cursor()
        stmt = "select * from " + self.GetQualifiedTableName(table_name)
        try:
            logging.debug(stmt)
            conn = cursor.connection
            cursor = conn.execute(stmt)
            # rowcount = cursor.rowcount
            for i in cursor.description:
                column_name_list.append(i[0])
        except:
            logging.error(stmt)
            raise
        finally:
            cursor.close()

        return column_name_list
