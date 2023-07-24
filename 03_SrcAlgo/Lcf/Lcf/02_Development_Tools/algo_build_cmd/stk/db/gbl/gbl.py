"""
stk/db/gbl/gbl.py
-------------------

Classes for Database access of Global Definition Tables.

 Sub-Scheme GBL


:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:17CET $
"""

# pylint: disable=C0103

# Import Python Modules ----------------------------------------------------------------------------------------------
import logging

# Import STK Modules -------------------------------------------------------------------------------------------------
from ..db_common import BaseDB, ERROR_TOLERANCE_NONE, DB_FUNC_NAME_MIN, DB_FUNC_NAME_MAX, DB_FUNC_NAME_LOWER, \
    DB_FUNC_NAME_UPPER, ERROR_TOLERANCE_LOW, AdasDBError, SQLCEBaseDB, AdasDBNotImplemented, OracleBaseDB, \
    SQLite3BaseDB
from ..db_sql import GenericSQLStatementFactory, SQLBinaryExpr, SQLFuncExpr, OP_EQ, SQLLiteral, OP_IS, OP_OR, \
    OP_AND, SQLColumnExpr, SQLTableExpr, OP_AS


#======================================================================================================================
# Constants
#======================================================================================================================

# Table base names:
TABLE_NAME_WORKFLOW = "GBL_Workflow"
TABLE_NAME_USERS = "GBL_Users"
TABLE_NAME_UNITS = "GBL_Units"
TABLE_NAME_TR_TYPE = "GBL_ValObserver"
TABLE_NAME_VALTYPES = "GBL_ValTypes"
TABLE_NAME_ASSESSMENT_STATE = "GBL_Assessment_State"
TABLE_NAME_PROJECT = "GBL_PROJECT"

# Workflow Table
COL_NAME_WORKFLOW_WFID = "WFID"
COL_NAME_WORKFLOW_NAME = "NAME"
COL_NAME_WORKFLOW_DESC = "DESCRIPTION"

# Assessment State Table
COL_NAME_ASSESSMENT_STATE_ASSID = "ASSSTID"
COL_NAME_ASSESSMENT_STATE_NAME = "NAME"
COL_NAME_ASSESSMENT_STATE_DESCRIPTION = "DESCRIPTION"
COL_NAME_ASSESSMENT_STATE_VALOBS_TYPEID = "VALOBS_TYPEID"
# User Table
COL_NAME_USER_ID = "USERID"
COL_NAME_USER_NAME = "NAME"
COL_NAME_USER_LOGIN = "LOGINNAME"

# Unit Table
COL_NAME_UNIT_ID = "UNITID"
COL_NAME_UNIT_NAME = "NAME"
COL_NAME_UNIT_TYPE = "TYPE"
COL_NAME_UNIT_LABEL = "LABEL"

# Testrun Type Table
COL_NAME_VO_TYPE_ID = "TYPEID"
COL_NAME_VO_TYPE_NAME = "NAME"
COL_NAME_VO_TYPE_DESC = "DESCRIPTION"

# Value Types Table
COL_NAME_VALTYPE_ID = "VTID"
COL_NAME_VALTYPE_NAME = "NAME"
COL_NAME_VALTYPE_DESC = "DESCRIPTION"

# Project Table
COL_NAME_PROJECT_PID = "PID"
COL_NAME_PROJECT_NAME = "NAME"
COL_NAME_PROJECT_DESC = "DESCRIPTION"

IDENT_STRING = "dbgbl"

#======================================================================================================================
# Constraint DB Libary Base Implementation
#======================================================================================================================


class BaseGblDB(BaseDB):
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
    # Handling of workflow
    #====================================================================
    def AddWorkflow(self, workflow):
        """Add workflow state to database.
        :param workflow: The workflow record.
        :return: Returns the workflow ID.
        """
        cond = self.__GetWorkflowCondition(workflow[COL_NAME_WORKFLOW_NAME])

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_WORKFLOW)], where=cond)
        if len(entries) <= 0:
            wfid = self._GetNextID(TABLE_NAME_WORKFLOW, COL_NAME_WORKFLOW_WFID)
            workflow[COL_NAME_WORKFLOW_WFID] = wfid
            self.AddGenericData(workflow, self.GetQualifiedTableName(TABLE_NAME_WORKFLOW))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Workflow '%s' exists already in the generic label database" % workflow[COL_NAME_WORKFLOW_NAME]
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    wfid = entries[0][COL_NAME_WORKFLOW_WFID]
                elif len(entries) > 1:
                    tmp = "Worflow name '%s' " % (workflow[COL_NAME_WORKFLOW_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return wfid

    def UpdateWorkflow(self, workflow, where=None):
        """Update existing workflow records.
        :param keyword: The workflow record update.
        :param where: The condition to be fulfilled by the workflow to the updated.
        :return: Returns the number of affected workflow.
        """
        rowcount = 0

        if where is None:
            where = self.__GetWorkflowCondition(workflow[COL_NAME_WORKFLOW_NAME])

        if (workflow is not None) and (len(workflow) != 0):
            rowcount = self.UpdateGenericData(workflow, self.GetQualifiedTableName(TABLE_NAME_WORKFLOW), where)
        # done
        return rowcount

    def DeleteWorkflow(self, workflow):
        """Delete existing workflow records.
        :param keyword: The workflow record update.
        :return: Returns the number of affected workflow.
        """
        rowcount = 0
        if (workflow is not None) and (len(workflow) != 0):
            cond = self.__GetWorkflowCondition(workflow[COL_NAME_WORKFLOW_NAME])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_WORKFLOW), where=cond)
        # done
        return rowcount

    def GetWorkflow(self, name):
        """Get existing workflow records.
        :param name: The workflow name.
        :return: Returns the workflow record.
        """
        record = {}
        cond = self.__GetWorkflowCondition(name)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_WORKFLOW)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Worflow with name '%s' does not exists in the global  database." % name))
        elif len(entries) > 1:
            logging.warn(str("Worflow with name '%s' cannot be resolved because it is ambiguous. (%s)" %
                             (name, entries)))
        else:
            record = entries[0]
        # done
        return record

    def __GetWorkflowCondition(self, name):
        """Get the condition expression to access the workflow.
        :param name: Name of the workflow
        :param check_point: checkpoint
        :return: Returns the condition expression
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                             COL_NAME_WORKFLOW_NAME), OP_EQ, SQLLiteral(name.lower()))

        return cond

    #====================================================================
    # Handling of assessment
    #====================================================================
    def AddAssessmentState(self, ass_state):
        """Add workflow state to database.
        :param ass_state: The AssessmentState record to be added.
        :return: Returns the AssessmentState ID.
        """
        obs_type_id = None
        if COL_NAME_ASSESSMENT_STATE_VALOBS_TYPEID in ass_state:
            obs_type_id = ass_state[COL_NAME_ASSESSMENT_STATE_VALOBS_TYPEID]
        cond = self.__GetAssessmentStateCondition(name=ass_state[COL_NAME_ASSESSMENT_STATE_NAME],
                                                  observer_type_id=obs_type_id)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT_STATE)],
                                         where=cond)
        if len(entries) <= 0:
#            ass_state_id = self._GetNextID(TABLE_NAME_ASSESSMENT_STATE, COL_NAME_ASSESSMENT_STATE_ASSID)
#            ass_state[COL_NAME_ASSESSMENT_STATE_ASSID] = ass_state_id
            self.AddGenericData(ass_state, self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT_STATE))

            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT_STATE)],
                                             where=cond)
            if len(entries) == 1:
                ass_state_id = entries[0][COL_NAME_ASSESSMENT_STATE_ASSID]
            else:
                tmp = "Assessment State name '%s' " % (ass_state[COL_NAME_ASSESSMENT_STATE_NAME])
                tmp += "cannot be added to database. "
                tmp += "(%s)" % (entries)
                raise AdasDBError(tmp)
        else:
            tmp = "Assessment State '%s' " % ass_state[COL_NAME_ASSESSMENT_STATE_NAME]
            tmp += "exists already in the generic label database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    ass_state_id = entries[0][COL_NAME_ASSESSMENT_STATE_ASSID]
                elif len(entries) > 1:
                    tmp = "Assessment State name '%s' " % (ass_state[COL_NAME_ASSESSMENT_STATE_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return ass_state_id

    def GetAssessmentState(self, name=None, assstid=None, observer_type_id=None):
        """Get existing workflow records.
        :param name: The workflow name.
        :return: Returns the workflow record.
        """
        cond = self.__GetAssessmentStateCondition(name=name, assstid=assstid, observer_type_id=observer_type_id)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ASSESSMENT_STATE)],
                                         where=cond)
        if len(entries) <= 0:
            logging.warn(str("Assessment with name '%s' does not exists in the global  database." % name))
        return entries

    def GetAssessmentStateId(self, name, observer_type_id=None):
        """Get existing workflow records.
        :param name: The workflow name.
        :return: Returns the workflow record.
        """
        assstid = None
        entries = self.GetAssessmentState(name=name, observer_type_id=observer_type_id)
        # done
        if len(entries) == 1:
            return int(entries[0][COL_NAME_ASSESSMENT_STATE_ASSID])
        elif len(entries) > 1:
            tmp = "Assessment with name '%s' " % (name)
            tmp += "for ObserverID %s " % (str(observer_type_id))
            tmp += "cannot be resolved because it is ambiguous."
            raise AdasDBError(tmp)
        else:
            return assstid

    def __GetAssessmentStateCondition(self, name=None, assstid=None, observer_type_id=None):
        """Get the condition expression to access the workflow.
        :param name: Name of the workflow
        :param assstid: Assessment State Identifier
        :param check_point: checkpoint
        :return: Returns the condition expression
        """
        cond = None
        if assstid is not None:
            cond = SQLBinaryExpr(COL_NAME_ASSESSMENT_STATE_ASSID, OP_EQ, assstid)
        else:
            if name is not None:
                cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                 COL_NAME_ASSESSMENT_STATE_NAME),
                                     OP_EQ, SQLLiteral(name.lower()))

            if observer_type_id is not None:
                cond_obs1 = SQLBinaryExpr(COL_NAME_ASSESSMENT_STATE_VALOBS_TYPEID, OP_EQ, observer_type_id)
                cond_obs2 = SQLBinaryExpr(COL_NAME_ASSESSMENT_STATE_VALOBS_TYPEID, OP_IS, 'null')
                cond_obs = SQLBinaryExpr(cond_obs1, OP_OR, cond_obs2)
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_obs)
                else:
                    cond = cond_obs
        return cond

    #====================================================================
    # Handling of Users
    #====================================================================
    def AddUser(self, user):
        """Add user to database.
        :param user: The user record.
        :return: Returns the user ID.
        """
        cond = self.__GetUserCondition(user[COL_NAME_USER_NAME])

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_USERS)], where=cond)
        if len(entries) <= 0:
            uid = self._GetNextID(TABLE_NAME_USERS, COL_NAME_USER_ID)
            user[COL_NAME_USER_ID] = uid
            self.AddGenericData(user, self.GetQualifiedTableName(TABLE_NAME_USERS))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("User '%s' exists already in the global database" % user[COL_NAME_USER_NAME])
            else:
                logging.warn(str("User '%s' already exists in the global database." % user[COL_NAME_USER_NAME]))
                if len(entries) == 1:
                    uid = entries[0][COL_NAME_USER_ID]
                elif len(entries) > 1:
                    tmp = "User name '%s' " % (user[COL_NAME_USER_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return uid

    def UpdateUser(self, user, where=None):
        """Update existing user records.
        :param user: The user record update.
        :param where: The condition to be fulfilled by the user to the updated.
        :return: Returns the number of affected user.
        """
        rowcount = 0

        if where is None:
            where = self.__GetUserCondition(user[COL_NAME_USER_NAME])

        if (user is not None) and (len(user) != 0):
            rowcount = self.UpdateGenericData(user, self.GetQualifiedTableName(TABLE_NAME_USERS), where)
        # done
        return rowcount

    def DeleteUser(self, user):
        """Delete existing user records.
        :param user: The user record update.
        :return: Returns the number of affected user.
        """
        rowcount = 0
        if (user is not None) and (len(user) != 0):
            cond = self.__GetUserCondition(user[COL_NAME_USER_NAME])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_USERS), where=cond)
        # done
        return rowcount

    def GetUser(self, name=None, login=None, user_id=None):
        """Get existing user records.
        :param name: The user name.
        :param login: windows login name
        :param user_id: user identifier, if set, the other parameters are unused
        :return: Returns the user record.
        """
        record = {}
        cond = self.__GetUserCondition(name, login, user_id)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_USERS)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("User with name '%s' does not exists in the global  database." % name))
        elif len(entries) > 1:
            logging.warn(str("User with name '%s' cannot be resolved because it is ambiguous. (%s)" % (name, entries)))
        else:
            record = entries[0]
        # done
        return record

    def GetAllUsers(self):
        """Get all existing user names.
        :return: Returns the user name list.
        """
        record = []

        select_list = []
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_USERS)),
                                                       COL_NAME_USER_NAME), OP_AS, COL_NAME_USER_NAME))

        entries = self.SelectGenericData(select_list=select_list,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_USERS)])
        if len(entries) <= 0:
            logging.warn("No Users defined in database.")
        else:
            for item in entries:
                record.append(item[COL_NAME_USER_NAME])
        # done
        return record

    def __GetUserCondition(self, name=None, login=None, user_id=None):
        """Get the condition expression to access the user record.
        :param name: Name of the user
        :param login: windows login name
        :param user_id: user identifier
        :return: Returns the condition expression
        """
        cond = None

        if user_id is not None:
            cond = SQLBinaryExpr(COL_NAME_USER_ID, OP_EQ, user_id)

        else:
            if name is not None:
                cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                 COL_NAME_USER_NAME),
                                     OP_EQ, SQLLiteral(name.lower()))

            if login is not None:
                cond_ln = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                    COL_NAME_USER_LOGIN),
                                        OP_EQ, SQLLiteral(login.lower()))

                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_ln)
                else:
                    cond = cond_ln
        return cond

    #====================================================================
    # Handling of Units
    #====================================================================
    def AddUnit(self, unit):
        """Add unit to database.
        :param unit: The unit record.
        :return: Returns the unit ID.
        """
        cond = self.__GetUnitCondition(unit[COL_NAME_UNIT_NAME])

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_UNITS)], where=cond)
        if len(entries) <= 0:
            uid = self._GetNextID(TABLE_NAME_UNITS, COL_NAME_UNIT_ID)
            unit[COL_NAME_UNIT_ID] = uid
            self.AddGenericData(unit, self.GetQualifiedTableName(TABLE_NAME_UNITS))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("Unit '%s' exists already in the global database" % unit[COL_NAME_UNIT_NAME])
            else:
                logging.warn(str("Unit '%s' already exists in the global database." % unit[COL_NAME_UNIT_NAME]))
                if len(entries) == 1:
                    uid = entries[0][COL_NAME_UNIT_ID]
                elif len(entries) > 1:
                    tmp = "Unit '%s' " % (unit[COL_NAME_UNIT_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return uid

    def UpdateUnit(self, unit, where=None):
        """Update existing unit records.
        :param unit: The unit record update.
        :param where: The condition to be fulfilled by the unit to the updated.
        :return: Returns the number of affected units.
        """
        rowcount = 0

        if where is None:
            where = self.__GetUnitCondition(unit[COL_NAME_USER_NAME])

        if (unit is not None) and (len(unit) != 0):
            rowcount = self.UpdateGenericData(unit, self.GetQualifiedTableName(TABLE_NAME_UNITS), where)
        # done
        return rowcount

    def DeleteUnit(self, unit):
        """Delete existing unit records.
        :param unit: The unit record update.
        :return: Returns the number of affected units.
        """
        rowcount = 0
        if (unit is not None) and (len(unit) != 0):
            cond = self.__GetUnitCondition(unit[COL_NAME_USER_NAME])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_UNITS), where=cond)
        # done
        return rowcount

    def GetUnit(self, name=None, uid=None):
        """Get existing unit records.
        :param name: The unit name (optional)
        :param uid: The unit Identifier (optional)
        :return: Returns the unit record.
        """
        record = None
        cond = self.__GetUnitCondition(name, uid)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_UNITS)], where=cond)
        if len(entries) <= 0:
            logging.debug(str("Unit with name '%s' does not exists in the global  database." % name))
        elif len(entries) > 1:
            logging.warn(str("Unit with name '%s' cannot be resolved because it is ambiguous. (%s)" % (name, entries)))
        else:
            record = entries[0]
        # done
        return record

    def GetUnitIdByName(self, name):
        """Get the Unit Id by the given name
        :param name: Name of the unit
        """
        record = self.GetUnit(name=name)
        if record is not None:
            return record[COL_NAME_UNIT_ID]
        else:
            raise AdasDBError("Unit with name '%s' does not exists in the global  database." % name)

    def __GetUnitCondition(self, name=None, uid=None):
        """Get the condition expression to access the unit.
        :param name: Name of the workflow
        :return: Returns the condition expression
        """
        if name is not None:
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                 COL_NAME_UNIT_NAME), OP_EQ, SQLLiteral(name.lower()))
        elif uid is not None:
            cond = SQLBinaryExpr(COL_NAME_UNIT_ID, OP_EQ, SQLLiteral(uid))
        return cond

    def GetTableData(self, table, columns=None):
        """ Get table data and return it in a format suitable for display. Double array.
        :param table: The table name
        :param columns: List of columns to be selected.
        :return: Table data. Field list array and Table data double array.
        """
        if columns is not None:
            select_list = columns
        else:
            select_list = '*'

        table_data = self.SelectGenericDataCompact(select_list, [self.GetQualifiedTableName(table)])
        return table_data

    def GetSelectData(self, table, columns, field_select, comparitor, value, sort):
        """ Get table data and return it in a format suitable for display. Double array.
        :param table: The table name
        :param columns: List of columns to be selected.
        :param field_select: The field to perform the qurey on.
        :param comparitor: The comparitor eg. ==, >
        :param value: The value to compare with.
        :return: Table data. Field list array and Table data double array.
        """
        cond = SQLBinaryExpr(field_select, comparitor, SQLLiteral(value))

        table_data = self.SelectGenericDataCompact(columns, [self.GetQualifiedTableName(table)],
                                                   where=cond)  # , order_by=[sort])
        return table_data

    #====================================================================
    # Handling of Validation Observer Types
    #====================================================================
    def AddValObserverType(self, tr_type):
        """Add a new test run type to the database.
        :param tr_type: The testrun type dictionary
        :return: Returns the testrun ID.
        """
        tr_type_id = None
        cond = self.__GetValObserverTypeCondition(tr_type[COL_NAME_VO_TYPE_NAME])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TR_TYPE)], where=cond)
        if len(entries) <= 0:
            tr_type_id = self._GetNextID(TABLE_NAME_TR_TYPE, COL_NAME_VO_TYPE_ID)
            tr_type[COL_NAME_VO_TYPE_ID] = tr_type_id
            self.AddGenericData(tr_type, self.GetQualifiedTableName(TABLE_NAME_TR_TYPE))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Event type '%s' exists already in the validation result database" % \
                      tr_type[COL_NAME_VO_TYPE_NAME]
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    tr_type_id = entries[0][COL_NAME_VO_TYPE_ID]
                elif len(entries) > 1:
                    tmp = "Event type name '%s' " % (type[COL_NAME_VO_TYPE_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return tr_type_id

    def UpdateValObserverType(self, tr_type, where=None):
        """Update existing test run type records.
        :param tr_type: The test run type record update.
        :param where: The condition to be fulfilled by the event type to the updated.
        :return: Returns the number of affected event types.
        """
        rowcount = 0

        if where is None:
            where = self.__GetValObserverTypeCondition(tr_type[COL_NAME_VO_TYPE_NAME])

        if (tr_type is not None) and (len(tr_type) != 0):
            rowcount = self.UpdateGenericData(tr_type, self.GetQualifiedTableName(TABLE_NAME_TR_TYPE), where)
        # done
        return rowcount

    def DeleteValObserverType(self, tr_type):
        """Delete existing event type records.
        :param tr_type: - The testrun type record to delete.
        :return: Returns the number of affected eventtypes.
        """
        rowcount = 0
        if (tr_type is not None) and (len(tr_type) != 0):
            cond = self.__GetValObserverTypeCondition(tr_type[COL_NAME_VO_TYPE_NAME])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_TR_TYPE), where=cond)
        # done
        return rowcount

    def GetValObserverType(self, name=None, type_id=None):
        """Get existing event type records.
        :param name: - The event type name.
        :return: Returns the event type record.
        """
        record = {}
        cond = self.__GetValObserverTypeCondition(name, type_id)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TR_TYPE)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Observer Type with name '%s' does not exist in the GBL database." % name))
        elif len(entries) > 1:
            record = entries
        else:
            record = entries[0]
        # done
        return record

    def GetValObserverTypeId(self, name):
        """ Get the EventType ID
        :param name: Event Type Name
        :return: Returns the Event Type IDcondition expression
        """
        tr_type = self.GetValObserverType(name)
        if COL_NAME_VO_TYPE_ID in tr_type:
            return int(tr_type[COL_NAME_VO_TYPE_ID])
        else:
            return None

    def __GetValObserverTypeCondition(self, name, type_id=None):
        """Get the condition expression to access the testrun type record
        :param name: Testrun Name
        :return: Returns the condition expression
        """
        cond = None
        if name is not None:
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_VO_TYPE_NAME),
                                 OP_EQ, SQLLiteral(name.lower()))
        if type_id is not None:
            cond_type = SQLBinaryExpr(COL_NAME_VO_TYPE_ID, OP_EQ, type_id)
            if cond is None:
                cond = cond_type
            else:
                cond = SQLBinaryExpr(cond, OP_AND, cond_type)
        return cond

    #====================================================================
    # Handling of Validation Value Types
    #====================================================================
    def AddValueType(self, type_name, desc):
        """Add a new value type to the database.
        :param type_name: The value type NAME
        :param desc: The value type DESCRIPTION
        :return: Returns the value type ID.
        """

        # check the function input parameters
        if type_name is None:
            raise AdasDBError("Value type name is not set!")
        if desc is None:
            raise AdasDBError("Value type description is not set!")

        # create record dictionary
        valuetype = {}
        valuetype[COL_NAME_VALTYPE_ID] = 0
        valuetype[COL_NAME_VALTYPE_NAME] = type_name
        valuetype[COL_NAME_VALTYPE_DESC] = desc

        # create and execute insert sql query
        cond = self.__GetValueTypeCondition(valuetype[COL_NAME_VALTYPE_NAME])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VALTYPES)], where=cond)
        if len(entries) <= 0:
            vtid = self._GetNextID(TABLE_NAME_VALTYPES, COL_NAME_VALTYPE_ID)
            valuetype[COL_NAME_VALTYPE_ID] = vtid
            self.AddGenericData(valuetype, self.GetQualifiedTableName(TABLE_NAME_VALTYPES))
            return vtid
        else:
            tmp = "Value type '%s' exists already in the validation result database" % valuetype[COL_NAME_VALTYPE_NAME]
            raise AdasDBError(tmp)

    def UpdateValueType(self, type_name, desc):
        """Add a new value type to the database.
        :param type_name: The value type NAME
        :param desc: The value type DESCRIPTION
        :return: Returns the value type ID.
        """

        # check the function input parameters
        if type_name is None:
            raise AdasDBError("Value type name is not set!")
        if desc is None:
            raise AdasDBError("Value type description is not set!")

        # create record dictionary
        valuetype = {}
        valuetype[COL_NAME_VALTYPE_ID] = 0
        valuetype[COL_NAME_VALTYPE_NAME] = type_name
        valuetype[COL_NAME_VALTYPE_DESC] = desc

        # create and execute insert sql query
        cond = self.__GetValueTypeCondition(valuetype[COL_NAME_VALTYPE_NAME])
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VALTYPES)], where=cond)
        if len(entries) == 1:
            val_type_id = entries[0][COL_NAME_VALTYPE_ID]
            cond = self.__GetValueTypeCondition(type_id=val_type_id)
            valuetype[COL_NAME_VALTYPE_ID] = val_type_id
            self.UpdateGenericData(valuetype, self.GetQualifiedTableName(TABLE_NAME_VALTYPES), where=cond)
            return val_type_id
        else:
            tmp = "Value type '%s' doesn't exist in the validation result database" % valuetype[COL_NAME_VALTYPE_NAME]
            raise AdasDBError(tmp)

    def DeleteValueType(self, type_name):
        """Delete existing value type record.
        :param type_name: - The value type record to delete.
        :return: Returns the number of affected rows.
        """
        if type_name is None:
            raise AdasDBError("Value type name is not set!")

        # rowcount = 0
        cond = self.__GetValueTypeCondition(type_name)
        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_VALTYPES), where=cond)
        return rowcount

    def GetValueType(self, type_name):
        """Get existing event value record.
        :param type_name: - The value type NAME
        :return: Returns the value type record.
        """
        record = {}
        cond = self.__GetValueTypeCondition(type_name)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VALTYPES)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Value type with name '%s' does not exist in the validation result database." % type))
        elif len(entries) > 1:
            logging.warn(str("Value type with name '%s' cannot be resolved because it is ambiguous. (%s)" %
                             (type, entries)))
        else:
            record = entries[0]

        return record

    def GetValueTypeId(self, type_name):
        """ Get the EventType ID
        :param type_name: - The value type NAME
        :return: Returns the value type identifier number
        """
        value_type = self.GetValueType(type_name)
        if COL_NAME_VALTYPE_ID in value_type:
            return int(value_type[COL_NAME_VALTYPE_ID])
        else:
            return None

    def __GetValueTypeCondition(self, type_name=None, type_id=None):
        """Get the condition expression to access the value type record
        :param type_name: The value type NAME
        :return: Returns the condition expression
        """
        cond = None

        if type_id is not None:
            cond = SQLBinaryExpr(COL_NAME_VALTYPE_ID, OP_EQ, SQLLiteral(type_id))
        else:
            if type_name is not None:
                cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                 COL_NAME_VALTYPE_NAME),
                                     OP_EQ, SQLLiteral(type_name.lower()))

        return cond

    def AddProject(self, proj_name, desc):
        """Add a new value type to the database.
        :param proj_name: The Project NAME
        :param desc: Prjoect DESCRIPTION
        :return: Returns the project ID.
        """
        # check the function input parameters
        if proj_name is None:
            raise AdasDBError("Project name is not set!")
        if desc is None:
            raise AdasDBError("Project description is not set!")

        # create record dictionary
        project = {}
        project[COL_NAME_PROJECT_PID] = 0
        project[COL_NAME_PROJECT_NAME] = proj_name
        project[COL_NAME_PROJECT_DESC] = desc

        # create and execute insert sql query
        entries = self.GetProjectId(proj_name)
        if entries is None:
            pid = self._GetNextID(TABLE_NAME_PROJECT, COL_NAME_PROJECT_PID)
            project[COL_NAME_PROJECT_PID] = pid
            self.AddGenericData(project, self.GetQualifiedTableName(TABLE_NAME_PROJECT))
            return pid
        else:
            tmp = "Project with name '%s' exists already in the validation result database" % proj_name[proj_name]
            raise AdasDBError(tmp)

    def GetProjectName(self, pid):
        """
        Get project name corresponding to project ID
        :param pid:  project ID
        :type pid: int
        """
        cond = SQLBinaryExpr(COL_NAME_PROJECT_PID, OP_EQ, pid)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_PROJECT)],
                                         where=cond)
        if len(entries) == 1:
            record = entries[0][COL_NAME_PROJECT_NAME]
        else:
            logging.warn(str("Project with id '%s' does not exist or ambiguous in " +
                             "the validation database." % str(pid)))
            record = None
        return record

    def GetAllProjectName(self):
        """
        Get All the project name from database
        """
        record = []
        entries = self.SelectGenericData(select_list=[COL_NAME_PROJECT_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_PROJECT)]
                                         )
        for row in entries:
            record.append(row[COL_NAME_PROJECT_NAME])
        return record

    def GetProjectId(self, proj_name):
        """
        Get Project Id of the prjoect name 847
        :param proj_name: name of the project e.g. ARS400
        :type proj_name: str
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_PROJECT_NAME),
                             OP_EQ, SQLLiteral(proj_name.lower()))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_PROJECT)], where=cond)
        if len(entries) <= 0:
            logging.warn(str("Project with name '%s' does not exist in the validation result database." % proj_name))
            record = None
        elif len(entries) > 1:
            logging.warn(str("Project with name '%s' cannot be resolved because it is ambiguous. (%s)" %
                             (proj_name, entries)))
            record = entries
        else:
            record = entries[0][COL_NAME_PROJECT_PID]
        return record

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


class SQLCEGblDB(BaseGblDB, SQLCEBaseDB):
    """SQL Server Compact Edition Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseGblDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLCEBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseGblDB.Initialize(self)
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


class OracleGblDB(BaseGblDB, OracleBaseDB):
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseGblDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        OracleBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseGblDB.Initialize(self)
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


class SQLite3GblDB(BaseGblDB, SQLite3BaseDB):
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseGblDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLite3BaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseGblDB.Initialize(self)
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

"""
$Log: gbl.py  $
Revision 1.1 2021/12/13 17:56:17CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/gbl/project.pj
Revision 1.24 2013/11/05 15:16:52CET Ahmed, Zaheer (uidu7634) 
Added GetAllProjectName function to list all projects registered in Database
- Added comments -  uidu7634 [Nov 5, 2013 3:16:53 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.23 2013/10/31 17:25:11CET Ahmed-EXT, Zaheer (uidu7634) 
Added GBL_PROJECT table defination and db interface functions
--- Added comments ---  uidu7634 [Oct 31, 2013 5:25:11 PM CET]
Change Package : 203293:1 http://mks-psad:7002/im/viewissue?selection=203293
Revision 1.22 2013/07/29 08:41:42CEST Raedler, Guenther (uidt9430)
- revert changes of rev. 1.21
--- Added comments ---  uidt9430 [Jul 29, 2013 8:41:43 AM CEST]
Change Package : 191735:1 http://mks-psad:7002/im/viewissue?selection=191735
Revision 1.21 2013/07/04 15:01:48CEST Mertens, Sven (uidv7805)
providing tableSpace to BaseDB for what sub-schema space each module is intended to be responsible
--- Added comments ---  uidv7805 [Jul 4, 2013 3:01:48 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.20 2013/04/26 10:46:07CEST Mertens, Sven (uidv7805)
moving strIdent
--- Added comments ---  uidv7805 [Apr 26, 2013 10:46:07 AM CEST]
Change Package : 179495:4 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.19 2013/04/25 14:35:14CEST Mertens, Sven (uidv7805)
epydoc adaptation to colon instead of at
--- Added comments ---  uidv7805 [Apr 25, 2013 2:35:15 PM CEST]
Change Package : 179495:2 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.18 2013/04/23 14:02:53CEST Raedler, Guenther (uidt9430)
- added additional option (user_id) to get user information - GetUser()
- extendend __GetUserCondition() accordingly
--- Added comments ---  uidt9430 [Apr 23, 2013 2:02:53 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.17 2013/04/19 13:40:08CEST Hecker, Robert (heckerr)
Functionality reverted to revision 1.13.
--- Added comments ---  heckerr [Apr 19, 2013 1:40:09 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.16 2013/04/15 12:08:42CEST Mertens, Sven (uidv7805)
small bugfixes
--- Added comments ---  uidv7805 [Apr 15, 2013 12:08:42 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.15 2013/04/12 14:37:07CEST Mertens, Sven (uidv7805)
adding a short representation used by db_connector.PostInitialize
--- Added comments ---  uidv7805 [Apr 12, 2013 2:37:08 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.14 2013/04/03 08:17:13CEST Mertens, Sven (uidv7805)
pep8: removing format errors
--- Added comments ---  uidv7805 [Apr 3, 2013 8:17:13 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.13 2013/04/02 10:03:04CEST Raedler, Guenther (uidt9430)
- use logging for all log messages again
- use specific identifier names
- removed pylint warnings
--- Added comments ---  uidt9430 [Apr 2, 2013 10:03:05 AM CEST]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.12 2013/03/28 15:25:19CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:20 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.11 2013/03/27 11:37:25CET Mertens, Sven (uidv7805)
pep8 & pylint: rowalignment and error correction
--- Added comments ---  uidv7805 [Mar 27, 2013 11:37:26 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/03/26 16:19:36CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:37 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.9 2013/03/21 17:22:39CET Mertens, Sven (uidv7805)
solving some pylint warnings / errors
--- Added comments ---  uidv7805 [Mar 21, 2013 5:22:39 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/04 07:47:30CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 4, 2013 7:47:31 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2013/02/28 08:12:11CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:12 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/02/27 16:19:52CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:53 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/26 20:10:34CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:10:34 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.4 2013/02/26 16:18:05CET Raedler, Guenther (uidt9430)
- add assessment state method
- renamed observer_type into observer_type_id
--- Added comments ---  uidt9430 [Feb 26, 2013 4:18:05 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.3 2013/02/20 09:38:53CET Raedler, Guenther (uidt9430)
- fixed wrong number of arguments
--- Added comments ---  uidt9430 [Feb 20, 2013 9:38:53 AM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/19 14:07:26CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:27 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 09:57:29CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/db/gbl/project.pj
------------------------------------------------------------------------------
-- From ETK/ADAS_DB Archive
------------------------------------------------------------------------------
Revision 1.24 2012/11/08 10:25:32CET Bratoi, Bogdan-Horia (uidu8192)
- Changing the GetValObserverType - adding the Type_id as parameter
--- Added comments ---  uidu8192 [Nov 8, 2012 10:25:35 AM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.23 2012/11/05 13:53:51CET Bratoi, Bogdan-Horia (uidu8192)
- Adding the observer type in the GBL_ASSESSMENT_STATE
--- Added comments ---  uidu8192 [Nov 5, 2012 1:53:56 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.22 2012/10/17 13:16:06CEST Bratoi, Bogdan-Horia (uidu8192)
Updated the GetValObserverType function
--- Added comments ---  uidu8192 [Oct 17, 2012 1:16:09 PM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.21 2012/10/17 11:36:29CEST Ahmed-EXT, Zaheer (uidu7634)
Redefine GBL_Assessment_State table and column definations
Fixed int type cast
--- Added comments ---  uidu7634 [Oct 17, 2012 11:36:31 AM CEST]
Change Package : 153893:1 http://mks-psad:7002/im/viewissue?selection=153893
Revision 1.20 2012/10/09 14:33:35CEST Hammernik-EXT, Dmitri (uidu5219)
- added new table functions for gbl_assessment_state
--- Added comments ---  uidu5219 [Oct 9, 2012 2:33:37 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.19 2012/03/22 11:47:36CET Raedler-EXT, Guenther (uidt9430)
- fixed error when reading column definition from ADMIN tables
- fixed some typos
--- Added comments ---  uidt9430 [Mar 22, 2012 11:47:37 AM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.18 2012/03/02 11:18:55CET Bratoi Bogdan-Horia (uidu8192) (uidu8192)
Changed GetTables for Oracle DB supporting all users
--- Added comments ---  uidu8192 [Mar 2, 2012 11:18:55 AM CET]
Change Package : 100767:1 http://mks-psad:7002/im/viewissue?selection=100767
Revision 1.17 2012/02/28 16:41:38CET Farcas-EXT, Florian Radu (uidu4753)
Update DB interface
--- Added comments ---  uidu4753 [Feb 28, 2012 4:41:38 PM CET]
Change Package : 100439:1 http://mks-psad:7002/im/viewissue?selection=100439
Revision 1.16 2012/02/06 08:23:00CET Raedler-EXT, Guenther (uidt9430)
- cast new ID as integer value
--- Added comments ---  uidt9430 [Feb 6, 2012 8:23:01 AM CET]
Change Package : 95134:1 http://mks-psad:7002/im/viewissue?selection=95134
Revision 1.15 2011/09/08 17:00:57CEST Castell, Christoph (uidt6394)
Added GetSelectData() function. Needs to be completed.
--- Added comments ---  uidt6394 [Sep 8, 2011 5:00:58 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.14 2011/09/06 10:01:13CEST Spruck Jochen (spruckj) (spruckj)
Remove some typing erros in error logging
--- Added comments ---  spruckj [Sep 6, 2011 10:01:13 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.13 2011/09/06 09:56:53CEST Spruck Jochen (spruckj) (spruckj)
Remove some typing errors
--- Added comments ---  spruckj [Sep 6, 2011 9:56:53 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.12 2011/09/05 15:24:51CEST Castell Christoph (uidt6394) (uidt6394)
Fixed bug in GetUnitIdByName().
--- Added comments ---  uidt6394 [Sep 5, 2011 3:24:51 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.11 2011/09/05 14:00:48CEST Castell Christoph (uidt6394) (uidt6394)
Changed default return type of GetUnit() to None.
--- Added comments ---  uidt6394 [Sep 5, 2011 2:00:48 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.10 2011/09/01 09:09:41CEST Raedler Guenther (uidt9430) (uidt9430)
-- added function GetUnitIdByName
--- Added comments ---  uidt9430 [Sep 1, 2011 9:09:42 AM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.9 2011/08/29 17:02:46CEST Ibrouchene Nassim (uidt5589) (uidt5589)
Added column TYPE in Unit table
--- Added comments ---  uidt5589 [Aug 29, 2011 5:02:47 PM CEST]
Change Package : 69072:2 http://mks-psad:7002/im/viewissue?selection=69072
Revision 1.8 2011/08/25 17:08:27CEST Ibrouchene Nassim (uidt5589) (uidt5589)
Fixed an issue with the AddUnit() : wrong column names.
--- Added comments ---  uidt5589 [Aug 25, 2011 5:08:27 PM CEST]
Change Package : 69072:2 http://mks-psad:7002/im/viewissue?selection=69072
Revision 1.7 2011/08/09 12:42:49CEST Castell Christoph (uidt6394) (uidt6394)
GetColumnNames() for Oracle.
--- Added comments ---  uidt6394 [Aug 9, 2011 12:42:49 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.6 2011/08/09 11:23:51CEST Castell Christoph (uidt6394) (uidt6394)
Changed GetTableNames() functions so that both return a list of table names. (not a dict)
--- Added comments ---  uidt6394 [Aug 9, 2011 11:23:51 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.5 2011/08/09 10:23:05CEST Castell Christoph (uidt6394) (uidt6394)
Implemented GetTableNames() for Oracle.
Revision 1.4 2011/07/19 11:46:53CEST Raedler Guenther (uidt9430) (uidt9430)
-- fixed some errors
-- added validation oberserver support
--- Added comments ---  uidt9430 [Jul 19, 2011 11:46:53 AM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.3 2011/07/12 16:15:28CEST Spruck Jochen (spruckj) (spruckj)
Add get all users function
--- Added comments ---  spruckj [Jul 12, 2011 4:15:28 PM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.2 2011/07/04 13:17:11CEST Raedler Guenther (uidt9430) (uidt9430)
-- added new table functions and testcode
--- Added comments ---  uidt9430 [Jul 4, 2011 1:17:12 PM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.1 2011/07/01 14:55:56CEST Raedler Guenther (uidt9430) (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/EM_EnvironmentModel/05_Testing/05_Test_Environment/algo/em_req_test/valf_tests/
    adas_database/gbl/project.pj
"""
