"""
stk/db/lbl/genlabel.py
-------------------

Classes for Database access of Generic Lables.

 Sub-Scheme LB and ADM_ADMIN

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:22CET $
"""

# pylint: disable=C0103,R0904

#======================================================================================================================
# Imports
#======================================================================================================================
from logging import warn, debug

from stk.db.db_common import BaseDB, ERROR_TOLERANCE_NONE, DB_FUNC_NAME_MIN, DB_FUNC_NAME_MAX, DB_FUNC_NAME_LOWER, \
    ERROR_TOLERANCE_LOW, AdasDBError, SQLCEBaseDB, OracleBaseDB, SQLite3BaseDB
from stk.db.db_sql import GenericSQLSelect, GenericSQLStatementFactory, SQLBinaryExpr, SQLFuncExpr, \
    OP_EQ, SQLLiteral, SQLColumnExpr, SQLTableExpr, OP_AS, OP_AND, SQLJoinExpr, OP_INNER_JOIN, EXPR_ORDER_BY


#======================================================================================================================
# Constants
#======================================================================================================================

# Table base names:
TABLE_NAME_LABELS = "LB_Labels"
TABLE_NAME_ATTRIBUTE_NAMES = "LB_AttributeNames"
TABLE_NAME_ATTRIBUTES = "LB_Attributes"
TABLE_NAME_STATES = "LB_States"
TABLE_NAME_TYPES = "LB_Types"
TABLE_NAME_RECTOBJIDMAP = "LB_RectObjIDMap"
TABLE_NAME_ADDINFO = "LB_AdditionalInfo"

COL_NAME_LABELS_LBID = "LBID"
COL_NAME_LABELS_ABSTS = "ABSTS"
COL_NAME_LABELS_TYPEID = "TYPEID"
COL_NAME_LABELS_WFID = "WFID"
COL_NAME_LABELS_STATEID = "STATEID"
COL_NAME_LABELS_MEASID = "MEASID"
COL_NAME_LABELS_USERID = "USERID"
COL_NAME_LABELS_MODDATE = "MODDATE"

COL_NAME_ATTRIBUTES_LBATTRID = "LBATTRID"
COL_NAME_ATTRIBUTES_LBID = "LBID"
COL_NAME_ATTRIBUTES_LBATTNAMEID = "LBATTNAMEID"
COL_NAME_ATTRIBUTES_UNITID = "UNITID"
COL_NAME_ATTRIBUTES_VTID = "VTID"
COL_NAME_ATTRIBUTES_VALUE = "VALUE"

COL_NAME_ATTR_NAMES_LBATTNAMEID = "LBATTNAMEID"
COL_NAME_ATTR_NAMES_NAME = "NAME"

COL_NAME_STATES_STATEID = "STATEID"
COL_NAME_STATES_NAME = "NAME"
COL_NAME_STATES_DESC = "DESCRIPTION"
COL_NAME_STATES_VALUE = "VALUE"
COL_NAME_STATES_TYPEID = "TYPEID"

COL_NAME_TYPES_TYPEID = "TYPEID"
COL_NAME_TYPES_NAME = "NAME"
COL_NAME_TYPES_DESC = "DESCRIPTION"
COL_NAME_TYPES_PARENT = "PARENT"

COL_NAME_RECTOBJIDMAP_RECTOBJIDMAPID = "RECTOBJIDMAPID"
COL_NAME_RECTOBJIDMAP_RECTOBJID = "RECTOBJID"
COL_NAME_RECTOBJIDMAP_LBID = "LBID"

COL_NAME_INFO_ID = "LBID"
COL_NAME_INFO_DESC = "DESCRIPTION"

IDENT_STRING = "dblbl"

#======================================================================================================================
# Constraint DB Libary Base Implementation
#======================================================================================================================


class BaseGenLabelDB(BaseDB):
    """Base implementation of the Rec File Database"""
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
    # Handling of label state
    #====================================================================
    def AddState(self, state):
        """Add state to database.
        :param state: The state record.
        :return: Returns the state ID.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_STATES_NAME),
                             OP_EQ, SQLLiteral(state[COL_NAME_STATES_NAME].lower()))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_STATES)], where=cond)
        if len(entries) <= 0:
            stateid = self._GetNextID(TABLE_NAME_STATES, COL_NAME_STATES_STATEID)
            state[COL_NAME_STATES_STATEID] = stateid
            self.AddGenericData(state, self.GetQualifiedTableName(TABLE_NAME_STATES))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("state '%s' exists already in the generic label database" %
                                  state[COL_NAME_STATES_NAME])
            else:
                warn("state '%s' already exists in the generic label database." %
                     state[COL_NAME_STATES_NAME])
                if len(entries) == 1:
                    stateid = entries[0][COL_NAME_STATES_STATEID]
                elif len(entries) > 1:
                    raise AdasDBError("state name '%s' cannot be resolved because it is ambiguous. (%s)" %
                                      (state[COL_NAME_STATES_NAME], entries))
        # done
        return stateid

    def UpdateState(self, state, where=None):
        """Update existing state records.
        :param keyword: The state record update.
        :param where: The condition to be fulfilled by the state to the updated.
        :return: Returns the number of affected state.
        """
        rowcount = 0

        if where is None:
            where = SQLBinaryExpr(COL_NAME_STATES_STATEID, OP_EQ, SQLLiteral(state[COL_NAME_STATES_STATEID]))

        if (state is not None) and (len(state) != 0):
            rowcount = self.UpdateGenericData(state, self.GetQualifiedTableName(TABLE_NAME_STATES), where)
        # done
        return rowcount

    def DeleteState(self, state):
        """Delete existing state records.
        :param keyword: The state record update.
        :return: Returns the number of affected state.
        """
        rowcount = 0
        if (state is not None) and (len(state) != 0):
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_STATES_NAME),
                                 OP_EQ, SQLLiteral(state[COL_NAME_STATES_NAME].lower()))
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_STATES), where=cond)
        # done
        return rowcount

    def GetState(self, name):
        """Get existing state records.
        :param name: The state name.
        :return: Returns the state record.
        """
        record = {}
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_STATES_NAME),
                             OP_EQ, SQLLiteral(name.lower()))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_STATES)], where=cond)
        if len(entries) <= 0:
            warn("State with name '%s' does not exists in the generic label database." % name)
        elif len(entries) > 1:
            warn("State with name '%s' cannot be resolved because it is ambiguous. (%s)" % (name, entries))
        else:
            record = entries[0]
        # done
        return record

    def GetStateID(self, name):
        """Get the label state ID.
        :param name: The name of the state.
        :return: Returns the id of the state.
        """

        stateid = None
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_STATES_NAME), OP_EQ,
                             SQLLiteral(name.lower()))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_STATES)], where=cond)
        if len(entries) == 1:
            stateid = entries[0][COL_NAME_STATES_STATEID]
        elif len(entries) <= 0:
            raise AdasDBError("State '%s' doesn't exists in the generic label database." % name)
        else:
            raise AdasDBError("State name '%s' cannot be resolved because it is ambiguous. (%s)" % (name, entries))
        # done
        return stateid

    def GetStateValue(self, stateid):
        """Delete existing state records.
        :param stateid: The stateid.
        :return: Returns the value of the state.
        """
        statevalue = None
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_STATES_STATEID),
                             OP_EQ, SQLLiteral(stateid))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_STATES)], where=cond)
        if len(entries) == 1:
            statevalue = entries[0][COL_NAME_STATES_VALUE]
        elif len(entries) <= 0:
            raise AdasDBError("State with id '%s' doesn't exists in the generic label database." % stateid)
        else:
            raise AdasDBError("State with id '%s' cannot be resolved because it is ambiguous. (%s)" %
                              (stateid, entries))
        # done
        return statevalue

    def GetStateName(self, stateid):
        """Delete existing state records.
        :param stateid: The stateid.
        :return: Returns the name of the state.
        """
        statevalue = None
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_STATES_STATEID),
                             OP_EQ,
                             SQLLiteral(stateid))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_STATES)], where=cond)
        if len(entries) == 1:
            statevalue = entries[0][COL_NAME_STATES_NAME]
        elif len(entries) <= 0:
            raise AdasDBError("State with id '%s' doesn't exists in the generic label database." % stateid)
        else:
            raise AdasDBError("State with id '%s' cannot be resolved because it is ambiguous. (%s)" %
                              (stateid, entries))
        # done
        return statevalue

    def _GetParrentStateNamesUValues(self, ChildTypeID):
        """Get all existing states Names records of the parent of with ChildTypeID.
        :return: Returns the state Names and values record.
        """
        record = {}
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_TYPES_TYPEID),
                             OP_EQ,
                             SQLLiteral(ChildTypeID))
        ParentTypeID = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TYPES)],
                                              where=cond)[0][COL_NAME_TYPES_PARENT]

        if ParentTypeID is not None:
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_STATES_TYPEID),
                                 OP_EQ,
                                 SQLLiteral(ParentTypeID))

            select_list = []
            select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                             COL_NAME_STATES_NAME),
                                             OP_AS,
                                             COL_NAME_STATES_NAME))
            select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                             COL_NAME_STATES_VALUE),
                                             OP_AS,
                                             COL_NAME_STATES_VALUE))

            ParentEntries = self.SelectGenericData(select_list=select_list,
                                                   table_list=[self.GetQualifiedTableName(TABLE_NAME_STATES)],
                                                   where=cond)
            record = ParentEntries
        else:
            warn("Label type with ID '%s' has no parent." % (ChildTypeID))

        return record

    def GetStateNamesUValues(self, TypeID):
        """Get all existing states Names records.
        :return: Returns the types Names record.
        """
        record = {}

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_STATES_TYPEID),
                             OP_EQ,
                             SQLLiteral(TypeID))

        select_list = []
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                                       COL_NAME_STATES_NAME),
                                         OP_AS,
                                         COL_NAME_STATES_NAME))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                                       COL_NAME_STATES_VALUE),
                                         OP_AS,
                                         COL_NAME_STATES_VALUE))

        entries = self.SelectGenericData(select_list=select_list,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_STATES)],
                                         where=cond)
        if len(entries) <= 0:
            record = self._GetParrentStateNamesUValues(TypeID)
            if len(record) <= 0:
                warn("Label type with ID '%s' is not assigned too any state in the generic label database." %
                     (TypeID))
        else:
            record = self._GetParrentStateNamesUValues(TypeID)
            if len(record) != 0:
                record.update(entries)
            else:
                record = entries
        # done
        return record

    #====================================================================
    # Handling of label types
    #====================================================================
    def AddType(self, recType):
        """Add type to database.
        :param recType: The type record.
        :return: Returns the type ID.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_TYPES_NAME),
                             OP_EQ,
                             SQLLiteral(recType[COL_NAME_TYPES_NAME].lower()))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TYPES)], where=cond)
        if len(entries) <= 0:
            typeid = self._GetNextID(TABLE_NAME_TYPES, COL_NAME_TYPES_TYPEID)
            recType[COL_NAME_TYPES_TYPEID] = typeid
            self.AddGenericData(recType, self.GetQualifiedTableName(TABLE_NAME_TYPES))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("type '%s' exists already in the generic label database" %
                                  recType[COL_NAME_TYPES_NAME])
            else:
                warn("type '%s' already exists in the generic label database." % recType[COL_NAME_TYPES_NAME])
                if len(entries) == 1:
                    typeid = entries[0][COL_NAME_TYPES_TYPEID]
                elif len(entries) > 1:
                    raise AdasDBError("type name '%s' cannot be resolved because it is ambiguous. (%s)" %
                                      (recType[COL_NAME_TYPES_NAME], entries))
        # done
        return typeid

    def UpdateType(self, recType, where=None):
        """Update existing type records.
        :param recType: The type record update.
        :param where: The condition to be fulfilled by the type to the updated.
        :return: Returns the number of affected type.
        """
        rowcount = 0

        if where is None:
            where = SQLBinaryExpr(COL_NAME_TYPES_TYPEID, OP_EQ, SQLLiteral(recType[COL_NAME_TYPES_TYPEID]))

        if (recType is not None) and (len(recType) != 0):
            rowcount = self.UpdateGenericData(recType, self.GetQualifiedTableName(TABLE_NAME_TYPES), where)
        # done
        return rowcount

    def DeleteType(self, recType):
        """Delete existing type records.
        :param recType: The type record update.
        :return: Returns the number of affected type.
        """
        rowcount = 0
        if (recType is not None) and (len(recType) != 0):
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_TYPES_NAME),
                                 OP_EQ, SQLLiteral(recType[COL_NAME_TYPES_NAME].lower()))
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_TYPES), where=cond)
        # done
        return rowcount

    def GetType(self, name):
        """Get existing type records.
        :param name: The type name.
        :return: Returns the type record.
        """
        record = {}
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_TYPES_NAME),
                             OP_EQ, SQLLiteral(name.lower()))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TYPES)], where=cond)
        if len(entries) <= 0:
            warn("Type with name '%s' does not exists in the generic label database." % name)
        elif len(entries) > 1:
            warn("Type with name '%s' cannot be resolved because it is ambiguous. (%s)" % (name, entries))
        else:
            record = entries[0]
        # done
        return record

    def GetTypeNameWithID(self, TypeID):
        """Get existing type Name.
        :param TypeID: The type ID.
        :return: Returns the type name.
        """
        record = {}
        cond = SQLBinaryExpr(COL_NAME_TYPES_TYPEID, OP_EQ, SQLLiteral(TypeID))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_TYPES)], where=cond)
        if len(entries) <= 0:
            warn("Type with TypeID '%s' does not exists in the generic label database." % TypeID)
        elif len(entries) > 1:
            warn("Type with TypeID '%s' cannot be resolved because it is ambiguous. (%s)" % (TypeID, entries))
        else:
            record = entries[0]
        # done
        return record

    def GetTypesNames(self, parent_name=None):
        """Get all existing types Names records.
        :param parent_name: if parent name is set get all Typenames with this parent name
        :return: Returns the types Names record.
        """
        record = {}

        select_list = []
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TYPES)),
                                                       COL_NAME_TYPES_NAME), OP_AS, COL_NAME_TYPES_NAME))

        if parent_name is None:
            entries = self.SelectGenericData(select_list=select_list,
                                             table_list=[self.GetQualifiedTableName(TABLE_NAME_TYPES)])
        else:
            # get the parent id
            parent_id = self.GetType(parent_name)[COL_NAME_TYPES_TYPEID]

            cond = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TYPES)),
                                               COL_NAME_TYPES_PARENT), OP_EQ, SQLLiteral(parent_id))

            entries = self.SelectGenericData(select_list=select_list,
                                             table_list=[self.GetQualifiedTableName(TABLE_NAME_TYPES)], where=cond)

        if len(entries) <= 0:
            warn("Types does not exists in the generic label database.")
        else:
            record = entries
        # done
        return record

    #====================================================================
    # Handling of label attributes
    #====================================================================
    def __GetAttibuteCondition(self, labelid, att_name_id=None):
        """Get the condition expression to access the attribut record
        :param labelid: the label id
        :param att_name_id: the attibute name id
        :return: Returns the condition expression
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_ATTRIBUTES_LBID), OP_EQ,
                             SQLLiteral(labelid))

        if att_name_id is not None:
            cond_name = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                      COL_NAME_ATTRIBUTES_LBATTNAMEID), OP_EQ, SQLLiteral(att_name_id))
            cond = SQLBinaryExpr(cond, OP_AND, cond_name)

        return cond

    def AddAttribute(self, attribute):
        """Add attribute to database.
        :param attribute: The attribute record.
        :return: Returns the attribute ID.
        """

        cond = self.__GetAttibuteCondition(attribute[COL_NAME_ATTRIBUTES_LBID],
                                           attribute[COL_NAME_ATTRIBUTES_LBATTNAMEID])

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTES)], where=cond)
        if len(entries) <= 0:
            attributeid = self._GetNextID(TABLE_NAME_ATTRIBUTES, COL_NAME_ATTRIBUTES_LBATTRID)
            attribute[COL_NAME_ATTRIBUTES_LBATTRID] = attributeid
            self.AddGenericData(attribute, self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTES))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("attribute '%s' exists already in the generic label database" %
                                  attribute[COL_NAME_ATTRIBUTES_LBATTNAMEID])
            else:
                warn("attribute '%s' already exists in the generic label database." %
                     attribute[COL_NAME_ATTRIBUTES_LBATTNAMEID])
                if len(entries) == 1:
                    attributeid = entries[0][COL_NAME_ATTRIBUTES_LBATTRID]
                elif len(entries) > 1:
                    raise AdasDBError("attribute name '%s' cannot be resolved because it is ambiguous. (%s)" %
                                      (attribute[COL_NAME_ATTRIBUTES_LBATTNAMEID], entries))
        # done
        return attributeid

    def AddAttributeToLabelId(self, LabelID, name, value, value_type_id=None, value_unit_id=None):
        """Add attribute to database and link it to label with id.
        :param LabelID: the label id.
        :param name: the name of the attibute
        :param value: The value of the attribute
        :param value_type: The type of the value (float, int, ..)
        :param value_unit: The unit of the value (m/s, m, s, rad, deg...)
        :return: Returns the id of the added attibute
        """
        attributeid = -1
        label = self.GetDetailedGenericLabel(LabelID)
        if len(label) > 0:
            attr_name = self.GetAttributeName(name)
            # if name does not exits add attibute name
            if len(attr_name) == 0:
                attr_name_id = self.AddAttributeName(name)
            else:
                attr_name_id = attr_name[COL_NAME_ATTR_NAMES_LBATTNAMEID]

            attribute = {}
            attribute[COL_NAME_ATTRIBUTES_LBID] = LabelID
            attribute[COL_NAME_ATTRIBUTES_LBATTNAMEID] = attr_name_id
            attribute[COL_NAME_ATTRIBUTES_VALUE] = value
            if value_type_id is not None:
                attribute[COL_NAME_ATTRIBUTES_VTID] = value_type_id
            if value_unit_id is not None:
                attribute[COL_NAME_ATTRIBUTES_UNITID] = value_unit_id

            attributeid = self.AddAttribute(attribute)
        else:
            warn("label id '%s' does not exists in the generic label database." % LabelID)
        return attributeid

    def UpdateAttribute(self, attribute, where=None):
        """Update existing attribute records.
        :param keyword: The attribute record update.
        :param where: The condition to be fulfilled by the attribute to the updated.
        :return: Returns the number of affected attribute.
        """
        rowcount = 0

        if (attribute is not None) and (len(attribute) != 0):
            rowcount = self.UpdateGenericData(attribute, self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTES), where)
        # done
        return rowcount

    def DeleteAttribute(self, attribute):
        """Delete existing attribute records.
        :param keyword: The attribute record update.
        :return: Returns the number of affected attribute.
        """
        rowcount = 0
        if (attribute is not None) and (len(attribute) != 0):
            cond = self.__GetAttibuteCondition(attribute[COL_NAME_ATTRIBUTES_LBID],
                                               attribute[COL_NAME_ATTRIBUTES_LBATTNAMEID])
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTES), where=cond)
        # done
        return rowcount

    def GetAttributeWithName(self, LabelID, name):
        """Get existing attribute records.
        :param LabelID: The LabelID.
        :param name: The attribute name.
        :return: Returns the attribute record.
        """
        record = {}
        tables = []
        tblAttr = self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTES)
        tblAttrNames = self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTE_NAMES)
        tables.append(SQLJoinExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTES)),
                                  OP_INNER_JOIN,
                                  SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTE_NAMES)),
                                  SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblAttr),
                                                              COL_NAME_ATTRIBUTES_LBATTNAMEID),
                                                OP_EQ,
                                                SQLColumnExpr(SQLTableExpr(tblAttrNames),
                                                              COL_NAME_ATTR_NAMES_LBATTNAMEID))))

        cond = SQLBinaryExpr(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblAttr),
                                                         COL_NAME_ATTRIBUTES_LBID), OP_EQ, SQLLiteral(LabelID)),
                             OP_AND,
                             SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblAttrNames), COL_NAME_ATTRIBUTES_LBID),
                             OP_EQ, SQLLiteral(name.lower())))

        select_list = []
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblAttrNames),
                                                       COL_NAME_ATTR_NAMES_NAME),
                                         OP_AS, COL_NAME_ATTR_NAMES_NAME))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblAttr),
                                                       COL_NAME_ATTRIBUTES_UNITID),
                                         OP_AS, COL_NAME_ATTRIBUTES_UNITID))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblAttr),
                                                       COL_NAME_ATTRIBUTES_VTID),
                                         OP_AS, COL_NAME_ATTRIBUTES_VTID))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblAttr),
                                         COL_NAME_ATTRIBUTES_VALUE),
                           OP_AS, COL_NAME_ATTRIBUTES_VALUE))

        entries = self.SelectGenericData(table_list=tables, where=cond)
        if len(entries) <= 0:
            warn("Attribute with name '%s' does not exists in the generic label database." % name)
        elif len(entries) > 1:
            warn("Attribute with name '%s' cannot be resolved because it is ambiguous. (%s)" % (name, entries))
        else:
            record = entries[0]
        # done
        return record

    def GetAttributes(self, LabelID):
        """Get existing attribute records.
        :param labelid: The labelid.
        :return: Returns the attribute record.
        """
        record = {}
        # check if label exists
        label = self.GetGenericLabel(LabelID)
        if (len(label) >= 0):

            cond = self.__GetAttibuteCondition(LabelID)

            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTES)],
                                             where=cond)
            if len(entries) <= 0:
                warn("Attribute with label id '%s' does not exists in the generic label database." % LabelID)
            else:
                record = entries
        else:
            warn("Label with id '%s' does not exists in the generic label database" % (LabelID))
        # done
        return record

    #====================================================================
    # Handling of label attribute Names
    #====================================================================
    def AddAttributeName(self, name):
        """Add attribute to database.
        :param name: The attribute Name
        :return: Returns the attribute ID.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                             COL_NAME_ATTR_NAMES_NAME), OP_EQ, SQLLiteral(name.lower()))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTE_NAMES)],
                                         where=cond)
        attr_name = {}
        if len(entries) <= 0:
            attr_name_id = self._GetNextID(TABLE_NAME_ATTRIBUTE_NAMES, COL_NAME_ATTR_NAMES_LBATTNAMEID)
            attr_name[COL_NAME_ATTR_NAMES_NAME] = name
            attr_name[COL_NAME_ATTR_NAMES_LBATTNAMEID] = attr_name_id
            self.AddGenericData(attr_name, self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTE_NAMES))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("attribute name '%s' exists already in the generic label database" % name)
            else:
                warn("attribute name '%s' already exists in the generic label database." % name)
                if len(entries) == 1:
                    attr_name_id = entries[0][COL_NAME_ATTR_NAMES_LBATTNAMEID]
                elif len(entries) > 1:
                    raise AdasDBError("attribute name '%s' cannot be resolved because it is ambiguous. (%s)" %
                                      (name, entries))
        # done
        return attr_name_id

    def UpdateAttributeName(self, attribute, where=None):
        """Update existing attribute Name records.
        :param keyword: The attribute record update.
        :param where: The condition to be fulfilled by the attribute to the updated.
        :return: Returns the number of affected attribute.
        """
        rowcount = 0

        if (attribute is not None) and (len(attribute) != 0):
            rowcount = self.UpdateGenericData(attribute, self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTE_NAMES), where)
        # done
        return rowcount

    def DeleteAttributeName(self, attribute):
        """Delete existing attribute Name records.
        :param keyword: The attribute record update.
        :return: Returns the number of affected attribute.
        """
        rowcount = 0
        if (attribute is not None) and (len(attribute) != 0):
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             TABLE_NAME_ATTRIBUTE_NAMES),
                                 OP_EQ, SQLLiteral(attribute[COL_NAME_ATTR_NAMES_NAME].lower()))
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTES), where=cond)
        # done
        return rowcount

    def GetAttributeName(self, name):
        """Get existing attribute Name records.
        :param name: The attribute name.
        :return: Returns the attribute record.
        """
        record = {}
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_ATTR_NAMES_NAME),
                             OP_EQ, SQLLiteral(name.lower()))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ATTRIBUTE_NAMES)],
                                         where=cond)
        if len(entries) <= 0:
            warn("Attribute name '%s' does not exists in the generic label database." % name)
        elif len(entries) > 1:
            warn("Attribute name '%s' cannot be resolved because it is ambiguous. (%s)" % (name, entries))
        else:
            record = entries[0]
        # done
        return record

    #====================================================================
    # Handling of generic labels
    #====================================================================
    def AddGenericLabel(self, label):
        """Add label to database.
        :param label: The label record.
        :return: Returns the label ID.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_LABELS_ABSTS),
                             OP_EQ,
                             SQLLiteral(label[COL_NAME_LABELS_ABSTS]))

        # and meas id
        cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_LABELS_MEASID, OP_EQ, label[COL_NAME_LABELS_MEASID]),
                             OP_AND,
                             cond)
        # and typeid
        cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_LABELS_TYPEID, OP_EQ, label[COL_NAME_LABELS_TYPEID]),
                             OP_AND,
                             cond)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_LABELS)], where=cond)
        if len(entries) <= 0:
            labelid = self._GetNextID(TABLE_NAME_LABELS, COL_NAME_LABELS_LBID)
            label[COL_NAME_LABELS_LBID] = labelid
            self.AddGenericData(label, self.GetQualifiedTableName(TABLE_NAME_LABELS))
        else:
            tmp = "Label with TS '%s' exists already in the generic label database" % label[COL_NAME_LABELS_ABSTS]
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                warn(tmp)
                if len(entries) == 1:
                    labelid = entries[0][COL_NAME_ATTRIBUTES_LBID]
                elif len(entries) > 1:
                    tmp = "Label with TS '%s' " % (label[COL_NAME_LABELS_ABSTS])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return labelid

    def AddGenericRecordingLabel(self, label):
        """Add label a label for the recording to database, the timestamp for recording labels is always -1.
        :param label: The label record.
        :return: Returns the label ID.
        """
        # state id
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_LABELS_STATEID),
                             OP_EQ,
                             SQLLiteral(label[COL_NAME_LABELS_STATEID]))

        # and meas id
        cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_LABELS_MEASID, OP_EQ, label[COL_NAME_LABELS_MEASID]),
                             OP_AND,
                             cond)
        # and typeid
        cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_LABELS_TYPEID, OP_EQ, label[COL_NAME_LABELS_TYPEID]),
                             OP_AND,
                             cond)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_LABELS)], where=cond)
        if len(entries) <= 0:
            labelid = self._GetNextID(TABLE_NAME_LABELS, COL_NAME_LABELS_LBID)
            label[COL_NAME_LABELS_LBID] = labelid
            label[COL_NAME_LABELS_ABSTS] = -1
            self.AddGenericData(label, self.GetQualifiedTableName(TABLE_NAME_LABELS))
        else:
            tmp = "Label with state '%s', " % (label[COL_NAME_LABELS_STATEID])
            tmp += "type '%s' and " % (label[COL_NAME_LABELS_TYPEID])
            tmp += "measid '%s' exists " % (label[COL_NAME_LABELS_MEASID])
            tmp += "already in the generic label database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                warn(tmp)
                if len(entries) == 1:
                    labelid = entries[0][COL_NAME_ATTRIBUTES_LBID]
                elif len(entries) > 1:
                    tmp = "Label with state '%s', " % (label[COL_NAME_LABELS_STATEID])
                    tmp += "type '%s' " % (label[COL_NAME_LABELS_TYPEID])
                    tmp += "and measid '%s' " % (label[COL_NAME_LABELS_MEASID])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return labelid

    def UpdateGenericLabel(self, label, where=None):
        """Update existing label records.
        :param label: The label record update.
        :param where: The condition to be fulfilled by the label to the updated.
        :return: Returns the number of affected label.
        """
        rowcount = 0

        if (label is not None) and (len(label) != 0):
            rowcount = self.UpdateGenericData(label, self.GetQualifiedTableName(TABLE_NAME_LABELS), where)
        # done
        return rowcount

    def DeleteGenericLabel(self, label):
        """Delete existing label records.
        :param label: The label record update.
        :return: Returns the number of affected label.
        """
        rowcount = 0
        if (label is not None) and (len(label) != 0):
            if label[COL_NAME_LABELS_LBID] is not None:
                cond = SQLBinaryExpr(COL_NAME_LABELS_LBID, OP_EQ, label[COL_NAME_LABELS_LBID])
            else:
                cond = SQLBinaryExpr(COL_NAME_LABELS_ABSTS, OP_EQ, label[COL_NAME_LABELS_ABSTS])

            # and meas id
            cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_LABELS_MEASID, OP_EQ, label[COL_NAME_LABELS_MEASID]),
                                 OP_AND,
                                 cond)
            # and typeid
            cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_LABELS_TYPEID, OP_EQ, label[COL_NAME_LABELS_TYPEID]),
                                 OP_AND,
                                 cond)

            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_LABELS), where=cond)
        # done
        return rowcount

    def DeleteGenericLabelWithLabelID(self, LabelID):
        """Delete existing and attributes label records with label id
        @param LabelID
        :return: Returns the number of affected label.
        """

        # Delete Attributes
        attributes = self.GetAttributes(LabelID)
        for attribute in attributes:
            self.DeleteAttribute(attribute)
        # Delete Label
        rowcount = self.DeleteGenericLabel(self.GetGenericLabel(LabelID))

        # done
        return rowcount

    def GetGenericLabel(self, LabelID):
        """Get existing generic label record.
        :param LabelID: The id of the label.
        :return: Returns the label record.
        """
        record = {}
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LABELS_LBID),
                             OP_EQ, SQLLiteral(LabelID))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_LABELS)], where=cond)
        if len(entries) <= 0:
            warn("Label with ID '%s' does not exists in the generic label database." % LabelID)
        elif len(entries) > 1:
            warn("Label with ID '%s' cannot be resolved because it is ambiguous. (%s)" % (LabelID, entries))
        else:
            record = entries[0]
        # done
        return record

    def GetDetailedGenericLabel(self, LabelID):
        """Get existing detailed generic label record.
        :param LabelID: The id of the label.
        :return: Returns the label record.
        """
        record = {}

        tables = []

        tblLab = self.GetQualifiedTableName(TABLE_NAME_LABELS)

        TypeJoin = SQLJoinExpr(SQLTableExpr(tblLab),
                               OP_INNER_JOIN,
                               SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TYPES)),
                               SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblLab),
                                                           COL_NAME_LABELS_TYPEID),
                               OP_EQ,
                               SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TYPES)),
                                             COL_NAME_TYPES_TYPEID)))

        tables.append(SQLJoinExpr(SQLTableExpr(TypeJoin),
                                  OP_INNER_JOIN,
                                  SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                  SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblLab), COL_NAME_LABELS_STATEID),
                                  OP_EQ,
                                  SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                                COL_NAME_STATES_STATEID))))

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LABELS)),
                                                       COL_NAME_LABELS_LBID)),
                             OP_EQ,
                             SQLLiteral(LabelID))

        select_list = []
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LABELS)),
                                                       COL_NAME_LABELS_ABSTS), OP_AS, COL_NAME_LABELS_ABSTS))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TYPES)),
                                                       COL_NAME_TYPES_NAME), OP_AS, "TYPE"))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                                       COL_NAME_STATES_NAME), OP_AS, "STATE"))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                                       COL_NAME_STATES_VALUE), OP_AS, COL_NAME_STATES_VALUE))

        entries = self.SelectGenericData(select_list=select_list, table_list=tables, where=cond)
        if len(entries) <= 0:
            warn("Label with ID '%s' does not exists in the generic label database." % LabelID)
        elif len(entries) > 1:
            warn("Label with ID '%s' cannot be resolved because it is ambiguous. (%s)" % (LabelID, entries))
        else:
            record = entries[0]
        # done
        return record

    def GetGenericLabelsIDsWithMeasIDAndType(self, MeasID, TypeName=None):
        """Get the Label Id with MEAS ID.
        :param Meas: ID The rec file meas ID.
        :param TypeName: The name of the label type.
        :return: Returns the label ID's.
        """
        labelids = None

        tables = []
        tblLabels = self.GetQualifiedTableName(TABLE_NAME_LABELS)
        tblTypes = self.GetQualifiedTableName(TABLE_NAME_TYPES)
        tables.append(SQLJoinExpr(SQLTableExpr(tblLabels),
                                  OP_INNER_JOIN,
                                  SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TYPES)),
                                  SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblLabels), COL_NAME_LABELS_TYPEID),
                                                OP_EQ,
                                                SQLColumnExpr(SQLTableExpr(tblTypes),
                                                              COL_NAME_TYPES_TYPEID))))

        if TypeName is None:
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_LABELS_MEASID), OP_EQ, SQLLiteral(MeasID))
        else:
            cond = SQLBinaryExpr(SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                               COL_NAME_LABELS_MEASID), OP_EQ, SQLLiteral(MeasID)),
                                 OP_AND,
                                 SQLBinaryExpr(COL_NAME_TYPES_NAME, OP_EQ, SQLLiteral(TypeName)))

        entries = self.SelectGenericData(table_list=tables, where=cond)

        if len(entries) <= 0:
            tmp = "Label with meas id '%s' " % (MeasID)
            tmp += "and type '%s' " % (TypeName)
            tmp += "doesn't exists in the generic label database."
            warn(tmp)
        else:
            labelids = []
            for item in range(len(entries)):
                labelids.append(entries[item][COL_NAME_LABELS_LBID])
        # done
        return labelids

    def GetGenericLabelsStateValues(self, MeasID, TypeName):
        """Get the State values of labels with with MEAS ID and type name.
        :param Meas: ID The rec file meas ID.
        :param TypeName: The name of the label type.
        :return: Returns the state values/names and timestamps.
        """
        states = None

        tables = []

        LABEL_TYPE_JOIN = "LabelTypeJoin"
        tblLab = self.GetQualifiedTableName(TABLE_NAME_LABELS)
        tblTypes = self.GetQualifiedTableName(TABLE_NAME_TYPES)
        tables.append(SQLJoinExpr(SQLTableExpr(tblLab),
                                  OP_INNER_JOIN,
                                  SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_TYPES)),
                                  SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblLab), COL_NAME_LABELS_TYPEID),
                                                OP_EQ,
                                                SQLColumnExpr(SQLTableExpr(tblTypes), COL_NAME_TYPES_TYPEID))))

        cond = SQLBinaryExpr(SQLBinaryExpr(SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                         COL_NAME_LABELS_MEASID), OP_EQ, SQLLiteral(MeasID)),
                                           OP_AND,
                                           SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblTypes), COL_NAME_TYPES_NAME),
                                                         OP_EQ,
                                                         SQLLiteral(TypeName))),
                             EXPR_ORDER_BY,
                             SQLColumnExpr(SQLTableExpr(tblLab), COL_NAME_LABELS_ABSTS))

        subselect = GenericSQLSelect(table_list=tables, where_condition=cond)

        tables = []
        tables.append(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)))
        tables.append(SQLTableExpr(SQLBinaryExpr("(", subselect, ")"), table_alias=LABEL_TYPE_JOIN))

        cond = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                           COL_NAME_STATES_STATEID),
                             OP_EQ,
                             SQLColumnExpr(SQLTableExpr(LABEL_TYPE_JOIN), COL_NAME_LABELS_STATEID))

        select_list = []
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(LABEL_TYPE_JOIN),
                                         COL_NAME_LABELS_ABSTS), OP_AS, COL_NAME_LABELS_ABSTS))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                                       COL_NAME_STATES_NAME), OP_AS, COL_NAME_STATES_NAME))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_STATES)),
                                                       COL_NAME_STATES_VALUE), OP_AS, COL_NAME_STATES_VALUE))
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(LABEL_TYPE_JOIN),
                                                       COL_NAME_LABELS_STATEID), OP_AS, COL_NAME_LABELS_STATEID))

        entries = self.SelectGenericData(select_list=select_list, table_list=tables, where=cond)

        if len(entries) <= 0:
            tmp = "Label with meas id '%s' " % (MeasID)
            tmp += "and type '%s' " % (TypeName)
            tmp += "doesn't exists in the generic label database."
            warn(tmp)
        else:
            states = entries
        # done
        return states

    def GetGenericLabelsStateValueAtTS(self, MeasID, TypeName, AbsTS, interpolate=False):
        """Get the State values of labels with with MEAS ID and type name at abs timestamp.
        :param Meas: ID The rec file meas ID.
        :param TypeName: The name of the label type.
        :param AbsTS: The absolute timestamp.
        :return: Returns the state values/names label AbsTS.
        """
        state = None
        states = self.GetGenericLabelsStateValues(MeasID, TypeName)
        if states is not None:
            if AbsTS >= states[len(states) - 1][COL_NAME_LABELS_ABSTS]:
                return states[len(states) - 1]
            for StateIndex in range(len(states) - 1):
                if((AbsTS >= states[StateIndex][COL_NAME_LABELS_ABSTS]) and
                   (AbsTS <= states[StateIndex + 1][COL_NAME_LABELS_ABSTS])):
                    if((interpolate is False) or
                       (states[StateIndex][COL_NAME_STATES_VALUE] is None) or
                       (states[StateIndex + 1][COL_NAME_STATES_VALUE] is None)):
                        return states[StateIndex]
                    else:
                        ValueInt = (states[StateIndex][COL_NAME_STATES_VALUE] +
                                    (AbsTS - states[StateIndex][COL_NAME_LABELS_ABSTS]) *
                                    (states[StateIndex + 1][COL_NAME_STATES_VALUE] -
                                    states[StateIndex][COL_NAME_STATES_VALUE]) /
                                    (states[StateIndex + 1][COL_NAME_LABELS_ABSTS] -
                                    states[StateIndex][COL_NAME_LABELS_ABSTS]))
                        ret_value = states[StateIndex]
                        ret_value[COL_NAME_STATES_VALUE] = ValueInt
                        return ret_value

        return state

    def GetGenericLabelType(self, LabelID):
        """Get the Label Type ID with Label Id.
        :param LabelID: The label id.
        :return: Returns the label type ID.
        """
        typeid = None
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_LABELS)], where=cond)
        if len(entries) == 1:
            typeid = entries[0][COL_NAME_LABELS_WFID]
        elif len(entries) <= 0:
            raise AdasDBError("Label with id '%s' doesn't exists in the generic label database." % LabelID)
        else:
            tmp = "Label with id '%s' cannot be resolved because it is ambiguous. (%s)" % (LabelID, entries)
            raise AdasDBError(tmp)
        # done
        return typeid

    def SetGenericLabelType(self, LabelID, TypeID):
        """Set the Label Type ID with Label Id.
        :param LabelID: The label id.
        :param TypeID: The label Type ID.
        :return: Returns the number of affected label.
        """
        # rowcount = 0

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        settings = {}
        settings[COL_NAME_LABELS_TYPEID] = TypeID
        rowcount = self.UpdateGenericData(settings, self.GetQualifiedTableName(TABLE_NAME_LABELS), where=cond)
        # done
        return rowcount

    def GetGenericLabelWorkflow(self, LabelID):
        """Get the Label workflow ID with Label Id.
        :param LabelID: The label id.
        :return: Returns the label workflow ID.
        """
        workflowid = None
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_LABELS)], where=cond)
        if len(entries) == 1:
            workflowid = entries[0][COL_NAME_LABELS_WFID]
        elif len(entries) <= 0:
            raise AdasDBError("Label with id '%s' doesn't exists in the generic label database." % LabelID)
        else:
            tmp = "Label with id '%s' cannot be resolved because it is ambiguous. (%s)" % (LabelID, entries)
            raise AdasDBError(tmp)
        # done
        return workflowid

    def SetGenericLabelWorkflow(self, LabelID, WorkflowID):
        """Set the Label workflow ID with Label Id.
        :param LabelID: The label id.
        :param WorkflowID: The label id.
        :return: Returns the number of affected label.
        """
        # rowcount = 0

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        settings = {}
        settings[COL_NAME_LABELS_WFID] = WorkflowID
        rowcount = self.UpdateGenericData(settings, self.GetQualifiedTableName(TABLE_NAME_LABELS), where=cond)
        # done
        return rowcount

    def GetGenericLabelState(self, LabelID):
        """Get the Label state ID with Label Id.
        :param LabelID: The label id.
        :return: Returns the label state ID.
        """
        stateid = None
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                             COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_LABELS)], where=cond)
        if len(entries) == 1:
            stateid = entries[0][COL_NAME_LABELS_STATEID]
        elif len(entries) <= 0:
            raise AdasDBError("Label with id '%s' doesn't exists in the generic label database." % LabelID)
        else:
            tmp = "Label with id '%s' cannot be resolved because it is ambiguous. (%s)" % (LabelID, entries)
            raise AdasDBError(tmp)
        # done
        return stateid

    def SetGenericLabelState(self, LabelID, StateID):
        """Get the Label state ID with Label Id.
        :param LabelID: The label id.
        :param StateID: The state id.
        :return: Returns the number of affected label.
        """
        # rowcount = 0

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        settings = {}
        settings[COL_NAME_LABELS_STATEID] = StateID
        rowcount = self.UpdateGenericData(settings, self.GetQualifiedTableName(TABLE_NAME_LABELS), where=cond)
        # done
        return rowcount

    def GetGenericLabelUser(self, LabelID):
        """Get the Label user ID with Label Id.
        :param LabelID: The label id.
        :return: Returns the label user ID.
        """
        userid = None
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                             COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_LABELS)], where=cond)
        if len(entries) == 1:
            userid = entries[0][COL_NAME_LABELS_USERID]
        elif len(entries) <= 0:
            raise AdasDBError("Label with id '%s' doesn't exists in the generic label database." % LabelID)
        else:
            tmp = "Label with id '%s' cannot be resolved because it is ambiguous. (%s)" % (LabelID, entries)
            raise AdasDBError(tmp)
        # done
        return userid

    def SetGenericLabelUser(self, LabelID, UserID):
        """Set the Label user ID with Label Id.
        :param LabelID: The label id.
        :param UserID: The user id.
        :return: Returns the number of affected label.
        """
        # rowcount = 0

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        settings = {}
        settings[COL_NAME_LABELS_USERID] = UserID
        rowcount = self.UpdateGenericData(settings, self.GetQualifiedTableName(TABLE_NAME_LABELS), where=cond)
        # done
        return rowcount

    def SetGenericLabelTimestamp(self, LabelID, Timestamp):
        """Set the Label user ID with Label Id.
        :param LabelID: The label id.
        :param Timestamp: The Timestamp.
        :return: Returns the number of affected label.
        """
        # rowcount = 0

        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LABELS_LBID), OP_EQ, SQLLiteral(LabelID))
        settings = {}
        settings[COL_NAME_LABELS_ABSTS] = Timestamp
        rowcount = self.UpdateGenericData(settings, self.GetQualifiedTableName(TABLE_NAME_LABELS), where=cond)
        # done
        return rowcount

    #====================================================================
    # Handling of rect object map
    #====================================================================
    def AddLabelRectObjMap(self, LabelRectObjMap):
        """Add LabelRectObjMap to database.
        :param LabelRectObjMap: The Rect Obj to Label Map record.
        :return: Returns the LabelRectObjMap ID.
        """
        cond = SQLBinaryExpr(SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                       COL_NAME_RECTOBJIDMAP_RECTOBJID),
                                           OP_EQ, SQLLiteral(LabelRectObjMap[COL_NAME_RECTOBJIDMAP_RECTOBJID])),
                             OP_AND,
                             SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                       COL_NAME_RECTOBJIDMAP_LBID),
                                           OP_EQ, SQLLiteral(LabelRectObjMap[COL_NAME_RECTOBJIDMAP_LBID])))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP)], where=cond)
        if len(entries) <= 0:
            rectobjidmapid = self._GetNextID(TABLE_NAME_RECTOBJIDMAP, COL_NAME_RECTOBJIDMAP_RECTOBJIDMAPID)
            LabelRectObjMap[COL_NAME_RECTOBJIDMAP_RECTOBJIDMAPID] = rectobjidmapid
            self.AddGenericData(LabelRectObjMap, self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP))
        else:
            tmp = "LabelRectObjMap '%s' " % LabelRectObjMap[COL_NAME_RECTOBJIDMAP_RECTOBJIDMAPID]
            tmp += "exists already in the generic label database"
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                warn(tmp)
                if len(entries) == 1:
                    rectobjidmapid = entries[0][COL_NAME_RECTOBJIDMAP_RECTOBJIDMAPID]
                elif len(entries) > 1:
                    tmp = "LabelRectObjMap name '%s' " % (LabelRectObjMap[COL_NAME_RECTOBJIDMAP_RECTOBJIDMAPID])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return rectobjidmapid

    def UpdateLabelRectObjMap(self, LabelRectObjMap, where=None):
        """Update existing LabelRectObjMap records.
        :param keyword: The LabelRectObjMap record update.
        :param where: The condition to be fulfilled by the LabelRectObjMap to the updated.
        :return: Returns the number of affected LabelRectObjMap.
        """
        rowcount = 0

        if (LabelRectObjMap is not None) and (len(LabelRectObjMap) != 0):
            rowcount = self.UpdateGenericData(LabelRectObjMap,
                                              self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP), where)
        # done
        return rowcount

    def DeleteLabelRectObjMap(self, LabelRectObjMap):
        """Delete existing LabelRectObjMap records.
        :param keyword: The LabelRectObjMap record update.
        :return: Returns the number of affected LabelRectObjMap.
        """
        rowcount = 0
        if (LabelRectObjMap is not None) and (len(LabelRectObjMap) != 0):
            cond = SQLBinaryExpr(SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                               COL_NAME_RECTOBJIDMAP_RECTOBJID),
                                 OP_EQ, SQLLiteral(LabelRectObjMap[COL_NAME_RECTOBJIDMAP_RECTOBJID])),
                                 OP_AND,
                                 SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                           COL_NAME_RECTOBJIDMAP_LBID),
                                               OP_EQ, SQLLiteral(LabelRectObjMap[COL_NAME_RECTOBJIDMAP_LBID])))
            rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP), where=cond)
        # done
        return rowcount

    def GetLabelRectObjMap(self, LabelID, RectObjID):
        """Get LabelRectObjMap existing attribute records.
        :param LabelID: The Label Id.
        :param RectObjID: The Rect Obj Id.
        :return: Returns the LabelRectObjMap record.
        """
        record = {}
        cond = SQLBinaryExpr(SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                       COL_NAME_RECTOBJIDMAP_LBID), OP_EQ, SQLLiteral(LabelID)),
                             OP_AND,
                             SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                       COL_NAME_RECTOBJIDMAP_RECTOBJID), OP_EQ, SQLLiteral(RectObjID)))

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP)], where=cond)
        if len(entries) <= 0:
            tmp = "LabelRectObjMap with LabelID '%s' " % (LabelID)
            tmp += "and RectObjID '%s' " % (RectObjID)
            tmp += "does not exists in the generic label database."
            warn(tmp)
        elif len(entries) > 1:
            tmp = "LabelRectObjMap with LabelID '%s' " % (LabelID)
            tmp += "and RectObjID '%s' " % (RectObjID)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            warn(tmp)
        else:
            record = entries[0]
        # done
        return record

    def GetRectObjIdsLinkedToLabel(self, LabelID):
        """Get Rect Objects Linked to Label with ID.
        :param LabelID: The Label ID.
        :return: Returns the Rect Obj Id(s) linked to the Label.
        """
        record = {}
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_RECTOBJIDMAP_LBID), OP_EQ, SQLLiteral(LabelID))

        select_list = []
        tblRect = self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP)
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblRect),
                                                       COL_NAME_RECTOBJIDMAP_RECTOBJID),
                                         OP_AS, COL_NAME_RECTOBJIDMAP_RECTOBJID))

        entries = self.SelectGenericData(select_list=select_list,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP)],
                                         where=cond)
        if len(entries) <= 0:
            warn("LabelID with name '%s' does not exists in the generic label database." % LabelID)
        elif len(entries) >= 1:
            record = entries
        # done
        return record

    def GetLabelIdsLinkedToRectObj(self, RectObjID):
        """Get Labels Linked to Rect Obje with ID.
        :param RectObjID: The Rect Object ID.
        :return: Returns the Label Id(s) linked to the RectObjeID.
        """
        record = {}
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_RECTOBJIDMAP_RECTOBJID),
                             OP_EQ, SQLLiteral(RectObjID))

        select_list = []
        tblRect = self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP)
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblRect),
                                                       COL_NAME_RECTOBJIDMAP_LBID),
                                         OP_AS, COL_NAME_RECTOBJIDMAP_LBID))

        entries = self.SelectGenericData(select_list=select_list,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_RECTOBJIDMAP)],
                                         where=cond)
        if len(entries) <= 0:
            warn("RectObjID with name '%s' does not exists in the generic label database." % RectObjID)
        elif len(entries) >= 1:
            record = entries
        # done
        return record

    #====================================================================
    # Handling of workflow
    #====================================================================
    def AddAdditionalInfo(self, lbid, desc):
        """Add Additional Info for an exitsting label.
        :param lbid: Label ID
        :param desc: Info Text
        """
        cond = self.__GetAddLabelInfoCondition(lbid)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_LABELS)], where=cond)

        if len(entries) <= 0:
            raise AdasDBError("Label with ID '%i' doesn't exist in the generic label database" % lbid)
        else:
            if desc is None or desc == "":
                raise AdasDBError("Additional Text Info is not defined")

            rec = {COL_NAME_INFO_ID: lbid, COL_NAME_INFO_DESC: desc}
            self.AddGenericData(rec, self.GetQualifiedTableName(TABLE_NAME_ADDINFO))

        # done

    def UpdateAdditionalInfo(self, lbid, desc):
        """Update existing label info  records.
        :param lbid: The Label ID record update.
        :param where: The condition to be fulfilled by the workflow to the updated.
        :return: Returns the number of affected workflow.
        """
        cond = self.__GetAddLabelInfoCondition(lbid)

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ADDINFO)], where=cond)
        if len(entries) == 0:
            raise AdasDBError("Additional Info for Label with ID '%i' doesn't exist in the generic label database.",
                              lbid)
        elif len(entries) > 1:
            raise AdasDBError("Additional Info for Label with ID '%i' cannot be resolved because it is ambiguous.",
                              lbid)

        rec = {COL_NAME_INFO_ID: lbid, COL_NAME_INFO_DESC: desc}
        rowcount = self.UpdateGenericData(rec, self.GetQualifiedTableName(TABLE_NAME_ADDINFO), where=cond)
        return rowcount

    def DeleteAdditionalInfo(self, lbid):
        """Delete existing label info.
        :param lbid: Label ID
        :return: Returns the number of affected label info entries
        """
        cond = self.__GetAddLabelInfoCondition(lbid)
        rowcount = self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_ADDINFO), where=cond)
        return rowcount

    def GetAdditionalInfo(self, lbid):
        """Get existing addional info of label.
        :param lbid:  Label ID
        :return: Returns the workflow record.
        """
        cond = self.__GetAddLabelInfoCondition(lbid)
        return self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_ADDINFO)], where=cond)

    def __GetAddLabelInfoCondition(self, lbid):  # pylint: disable=R0201
        """Get the condition expression to access the additional label
        :param lbid: Label ID
        :return: Returns the condition expression
        """
        return SQLBinaryExpr(COL_NAME_INFO_ID, OP_EQ, SQLLiteral(lbid))

    #====================================================================
    # generic labels test code
    #====================================================================
    def TestGenLabel(self):
        """ Testcode for generic label """
        pass
#        type = {}
#        type = self.GetType("Type2")
#        self.DeleteType(type)
#        type[COL_NAME_TYPES_NAME] = "Type1"
#        self.AddType(type)
#        type = self.GetType("Type1")
#        type[COL_NAME_TYPES_NAME] = "Type2"
#        self.UpdateType(type)
#
#        state = {}
#        state = self.GetState("State2")
#        if COL_NAME_STATES_STATEID in state:
#            self.DeleteState(state)
#        state[COL_NAME_STATES_NAME] = "State1"
#        state[COL_NAME_STATES_TYPEID] = type[COL_NAME_TYPES_TYPEID]
#        self.AddState(state)
#        state = self.GetState("State1")
#        state[COL_NAME_STATES_NAME] = "State2"
#        state[COL_NAME_STATES_VALUE] = "5"
#        self.UpdateState(state)
#        state = {}
#        state[COL_NAME_STATES_NAME] = "State1"
#        state[COL_NAME_STATES_VALUE] = "1"
#        state[COL_NAME_STATES_TYPEID] = type[COL_NAME_TYPES_TYPEID]
#        self.AddState(state)
#        stateid = self.GetStateID("State1")
#
#        print stateid
# #        print self.__GenLabelDB.GetStateValue(stateid)
# #        print self.__GenLabelDB.GetStateName(stateid)
#
#
#
#        attrib = {}
#        attrib = self.GetAttribute("Attrib2")
#        self.DeleteAttribute(attrib)
#        attrib[COL_NAME_ATTRIBUTES_ATTRTYPE] = "Attrib1"
#        attrib[COL_NAME_ATTRIBUTES_LBID] = "100"
#        self.AddAttribute(attrib)
#        attrib = self.GetAttribute("Attrib1")
#        attrib[COL_NAME_ATTRIBUTES_ATTRTYPE] = "Attrib2"
#        self.UpdateAttribute(attrib)
# #
# #        attrib = {}
# #        attrib = self.__GenLabelDB.GetAttribute("Attrib2")
# #        self.__GenLabelDB.DeleteAttribute(attrib)
# #        attrib[genlabel.COL_NAME_ATTRIBUTES_ATTRTYPE] = "Attrib1"
# #        attrib[genlabel.COL_NAME_ATTRIBUTES_LBID] = "100"
# #        self.__GenLabelDB.AddAttribute(attrib)
# #        attrib = self.__GenLabelDB.GetAttribute("Attrib1")
# #        attrib[genlabel.COL_NAME_ATTRIBUTES_ATTRTYPE] = "Attrib2"
# #        self.__GenLabelDB.UpdateAttribute(attrib)
# #
#        label = {}
#        type = self.GetType("Type2")
#        # workflow = self.GetWorkflow("Test2")
#
#        labelids = self.GetGenericLabelsIDsWithMeasIDAndType("1","Type2")
#        if labelids is not None:
#            for item in range(len(labelids)):
#                label = self.GetGenericLabel(labelids[item])
#                self.DeleteGenericLabel(label)
#
#        label[COL_NAME_LABELS_ABSTS] = "111111"
#        label[COL_NAME_LABELS_TYPEID] = type[COL_NAME_TYPES_TYPEID]
#        label[COL_NAME_LABELS_MEASID] = "1"
#        label[COL_NAME_LABELS_WFID] = 0; #workflow[COL_NAME_WORKFLOW_WFID]
#        label[COL_NAME_LABELS_USERID] = 0
#        label[COL_NAME_LABELS_STATEID] = stateid
#        label[COL_NAME_LABELS_MODDATE] = datetime.datetime.today()
#        self.AddGenericLabel(label)
#        labelids = self.GetGenericLabelsIDsWithMeasIDAndType("1","Type2")
#        label_id = labelids[0]
# #        label = self.__GenLabelDB.GetGenericLabel(labelids[0])
# #        label[genlabel.COL_NAME_LABELS_ABSTS] = "222222"
# #        self.__GenLabelDB.UpdateGenericLabel(label)
# #
# #        labelids = self.__GenLabelDB.GetGenericLabelsIDsWithMeasIDAndType("1","Type2")
# #        label = self.__GenLabelDB.GetGenericLabel(labelids[0])
# #        label[genlabel.COL_NAME_LABELS_STATEID] =  self.__GenLabelDB.GetStateID("State2")
# #        label[genlabel.COL_NAME_LABELS_ABSTS] = "10000"
# #        self.__GenLabelDB.AddGenericLabel(label)
#
# #        print self.__GenLabelDB.GetGenericLabelsStateValues("1","Type2")
# #        print self.__GenLabelDB.GetGenericLabelsStateValueAtTS("1","Type2",9999)
# #        print self.__GenLabelDB.GetGenericLabelsStateValueAtTS("1","Type2",10000)
# #        print self.__GenLabelDB.GetGenericLabelsStateValueAtTS("1","Type2",12000)
# #        print self.__GenLabelDB.GetGenericLabelsStateValueAtTS("1","Type2",222000,True)
# #        print self.__GenLabelDB.GetGenericLabelsStateValueAtTS("1","Type2",222222)
# #        print self.__GenLabelDB.GetGenericLabelsStateValueAtTS("1","Type2",444444)
#
# #        wf = self.__GenLabelDB.GetGenericLabelWorkflow(labelids[0])
# #        self.__GenLabelDB.SetGenericLabelWorkflow(labelids[0],wf+1)
# #
# #        ty = self.__GenLabelDB.GetGenericLabelType(labelids[0])
# #        self.__GenLabelDB.SetGenericLabelType(labelids[0],ty+1)
# #        self.__GenLabelDB.SetGenericLabelType(labelids[0],ty-1)
# #
# #        st = self.__GenLabelDB.GetGenericLabelState(labelids[0])
# #        self.__GenLabelDB.SetGenericLabelState(labelids[0],st+1)
# #
# #        us = self.__GenLabelDB.GetGenericLabelUser(labelids[0])
# #        self.__GenLabelDB.SetGenericLabelUser(labelids[0],us+1)
#
# #        RectObjIdMap = {}
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_LBID] = 2
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_RECTOBJID] = 2
# #        self.__GenLabelDB.DeleteLabelRectObjMap(RectObjIdMap)
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_LBID] = 3
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_RECTOBJID] = 4
# #        self.__GenLabelDB.DeleteLabelRectObjMap(RectObjIdMap)
# #
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_LBID] = 1
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_RECTOBJID] = 2
# #        self.__GenLabelDB.AddLabelRectObjMap(RectObjIdMap)
# #        RectObjIdMap = self.__GenLabelDB.GetLabelRectObjMap(1,2)
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_LBID] = 2
# #        cond = genlabel.SQLBinaryExpr(genlabel.SQLFuncExpr(self.__
# #        GenLabelDB.db_func_map[genlabel.DB_FUNC_NAME_LOWER], genlabel.COL_NAME_RECTOBJIDMAP_RECTOBJIDMAPID),
# #                                       OP_EQ,
# #                                       genlabel.SQLLiteral(RectObjIdMap[genlabel.
# #                                       COL_NAME_RECTOBJIDMAP_RECTOBJIDMAPID]))
# #        self.__GenLabelDB.UpdateLabelRectObjMap(RectObjIdMap, where=cond)
# #
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_LBID] = 3
# #        RectObjIdMap[genlabel.COL_NAME_RECTOBJIDMAP_RECTOBJID] =4
# #        self.__GenLabelDB.AddLabelRectObjMap(RectObjIdMap)
# #        print self.__GenLabelDB.GetRectObjIdsLinkedToLabel(2)
# #        print self.__GenLabelDB.GetLabelIdsLinkedToRectObj(4)
#        self.AddAdditionalInfo(label_id,"test text")
#        self.UpdateAdditionalInfo(label_id, "neuer test text")
#        print self.GetAdditionalInfo(label_id)
#        self.DeleteAdditionalInfo(label_id)

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
            debug(stmt)
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
class SQLCEGenLabelDB(BaseGenLabelDB, SQLCEBaseDB):
    """SQL Server Compact Edition Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseGenLabelDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLCEBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseGenLabelDB.Initialize(self)
        SQLCEBaseDB.Initialize(self)


class OracleGenLabelDB(BaseGenLabelDB, OracleBaseDB):
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseGenLabelDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        OracleBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseGenLabelDB.Initialize(self)
        OracleBaseDB.Initialize(self)


class SQLite3GenLabelDB(BaseGenLabelDB, SQLite3BaseDB):
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None, sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseGenLabelDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLite3BaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseGenLabelDB.Initialize(self)
        SQLite3BaseDB.Initialize(self)


"""
$Log: genlabel.py  $
Revision 1.1 2021/12/13 17:56:22CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/lbl/project.pj
Revision 1.19 2013/05/29 13:26:51CEST Mertens, Sven (uidv7805) 
removing pylint errors locally
- Added comments -  uidv7805 [May 29, 2013 1:26:51 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.18 2013/04/26 15:39:13CEST Mertens, Sven (uidv7805)
resolving some pep8 / pylint errors
--- Added comments ---  uidv7805 [Apr 26, 2013 3:39:13 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.17 2013/04/26 10:46:05CEST Mertens, Sven (uidv7805)
moving strIdent
Revision 1.16 2013/04/25 14:35:15CEST Mertens, Sven (uidv7805)
epydoc adaptation to colon instead of at
Revision 1.14 2013/04/12 14:37:10CEST Mertens, Sven (uidv7805)
adding a short representation used by db_connector.PostInitialize
Revision 1.13 2013/04/02 10:25:02CEST Mertens, Sven (uidv7805)
pylint: E0213, E1123, E9900, E9904, E1003, E9905, E1103
--- Added comments ---  uidv7805 [Apr 2, 2013 10:25:03 AM CEST]
Change Package : 176171:9 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.12 2013/03/27 11:37:23CET Mertens, Sven (uidv7805)
pep8 & pylint: rowalignment and error correction
Revision 1.11 2013/03/26 16:19:29CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:29 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/03/22 08:24:29CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
Revision 1.9 2013/03/21 17:22:37CET Mertens, Sven (uidv7805)
solving some pylint warnings / errors
--- Added comments ---  uidv7805 [Mar 21, 2013 5:22:37 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/04 07:47:35CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 4, 2013 7:47:36 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2013/02/28 08:12:23CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:24 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/02/27 17:55:12CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:13 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/27 16:19:59CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:59 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/26 20:10:28CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:10:28 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.3 2013/02/19 14:07:29CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:29 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/11 10:10:00CET Raedler, Guenther (uidt9430)
- fixed wrong intension in comment section
--- Added comments ---  uidt9430 [Feb 11, 2013 10:10:03 AM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 09:58:41CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/db/lbl/project.pj
------------------------------------------------------------------------------
-- From ETK/ADAS_DB Archive
------------------------------------------------------------------------------

Revision 1.14 2012/10/19 10:47:25CEST Hammernik-EXT, Dmitri (uidu5219)
bugfix
--- Added comments ---  uidu5219 [Oct 19, 2012 10:47:26 AM CEST]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.13 2012/10/19 10:27:23CEST Hammernik-EXT, Dmitri (uidu5219)
- added aditional return value in GetGenericLabelsStateValues function
--- Added comments ---  uidu5219 [Oct 19, 2012 10:27:25 AM CEST]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.12 2012/10/12 08:29:35CEST Spruck, Jochen (spruckj)
- Update Get Type names function, get all types names with parent xyz
- Delete generic label if label id is given
- Add delete generic labal with all attributs for a given label id
--- Added comments ---  spruckj [Oct 12, 2012 8:29:35 AM CEST]
Change Package : 93947:1 http://mks-psad:7002/im/viewissue?selection=93947
Revision 1.11 2012/03/20 11:12:40CET Spruck, Jochen (spruckj)
Add label attribute support
--- Added comments ---  spruckj [Mar 20, 2012 11:12:40 AM CET]
Change Package : 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.10 2012/02/06 08:23:39CET Raedler-EXT, Guenther (uidt9430)
- cast new ID as integer value
--- Added comments ---  uidt9430 [Feb 6, 2012 8:23:40 AM CET]
Change Package : 95134:1 http://mks-psad:7002/im/viewissue?selection=95134
Revision 1.9 2011/09/09 08:16:35CEST Spruck, Jochen (spruckj)
lower of MeasID is not needed
--- Added comments ---  spruckj [Sep 9, 2011 8:16:35 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.8 2011/09/06 09:58:27CEST Spruck Jochen (spruckj) (spruckj)
- show error only in case of on record found
- lower the meas id
--- Added comments ---  spruckj [Sep 6, 2011 9:58:27 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.7 2011/08/30 09:38:07CEST Spruck Jochen (spruckj) (spruckj)
Remove some typing errors
--- Added comments ---  spruckj [Aug 30, 2011 9:38:07 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.6 2011/08/08 10:19:17CEST Raedler Guenther (uidt9430) (uidt9430)
-- removed unused GetDateTime method
-- added Additional Label Info Handling
-- Changed Testcode
--- Added comments ---  uidt9430 [Aug 8, 2011 10:19:18 AM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.5 2011/07/15 10:01:36CEST Spruck Jochen (spruckj) (spruckj)
Add generic label type parent support
--- Added comments ---  spruckj [Jul 15, 2011 10:01:36 AM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.4 2011/07/11 13:32:27CEST Spruck Jochen (spruckj) (spruckj)
Set generic label abs timestamp bug fix, wrong column
--- Added comments ---  spruckj [Jul 11, 2011 1:32:27 PM CEST]
Change Package : 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.3 2011/07/04 15:17:53CEST Raedler Guenther (uidt9430) (uidt9430)
-- moved workflow into global (GBL) schema
-- added parent column for label types
--- Added comments ---  uidt9430 [Jul 4, 2011 3:17:53 PM CEST]
Change Package : 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.2 2011/07/01 12:52:29CEST Spruck Jochen (spruckj) (spruckj)
Update label interface module
--- Added comments ---  spruckj [Jul 1, 2011 12:52:29 PM CEST]
Change Package : 46866:8 http://mks-psad:7002/im/viewissue?selection=46866
Revision 1.1 2011/06/16 17:49:26CEST Spruck Jochen (spruckj) (spruckj)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/VDY_VehicleDynamics/05_Testing/05_Test_Environment/algo/vdy_req_test/valf_tests/
    adas_database/lb/project.pj
"""
