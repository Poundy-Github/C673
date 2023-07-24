"""
stk/db/par/__init__.py
-------------------

Classes for Database access of Global Definitions.

 Sub-Scheme GBL


:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:44CET $
"""

# pylint: disable=C0103

#======================================================================================================================
# Imports
#======================================================================================================================
# pylint: disable= F0401
from ..db_common import BaseDB, ERROR_TOLERANCE_NONE, DB_FUNC_NAME_MIN, DB_FUNC_NAME_MAX, AdasDBError, \
    ERROR_TOLERANCE_LOW, DB_FUNC_NAME_LOWER, SQLCEBaseDB, OracleBaseDB, SQLite3BaseDB
from ..db_sql import GenericSQLStatementFactory, SQLBinaryExpr, OP_EQ, SQLLiteral, SQLFuncExpr, OP_AND
# pylint: enable= F0401

#======================================================================================================================
# Constants
#======================================================================================================================

# Table base names:
TABLE_NAME_DESCRIPTION = "PAR_Description"
TABLE_NAME_CONFIGS = "PAR_Configs"
TABLE_NAME_CFGMAP = "PAR_CfgMap"
TABLE_NAME_VALUE = "PAR_Value"
TABLE_NAME_VALUEARCHIVE = "PAR_ValueArchive"

# Parameter Description Table
COL_NAME_DESC_ID = "PDID"
COL_NAME_DESC_NAME = "NAME"
COL_NAME_DESC_TYPE = "VTID"
COL_NAME_DESC_UNIT = "UNITID"

# Parameter Configs Table
COL_NAME_CFG_ID = "PCID"
COL_NAME_CFG_NAME = "CFGNAME"

# Parameter-Config Map Table
COL_NAME_PARCFG_MAP_ID = "PMID"
COL_NAME_PARCFG_MAP_PDID = "PDID"
COL_NAME_PARCFG_MAP_PCID = "PCID"

# Parameter Value Table
COL_NAME_PAR_VAL_ID = "PARID"
COL_NAME_PAR_VAL_MEASID = "MEASID"
COL_NAME_PAR_VAL_PMID = "PMID"
COL_NAME_PAR_VAL_USERID = "USERID"
COL_NAME_PAR_VAL_WFID = "WFID"
COL_NAME_PAR_VAL_TIMESTAMP = "MODDATE"
COL_NAME_PAR_VAL_VALUE = "VALUE"

# Default return value if no result is found.
COL_PAR_DEF_VAL = -1

# Database functions
DB_FUNC_NAME_GETDATE = 'DB_FUNC_NAME_GETDATE'

IDENT_STRING = "dbpar"

#======================================================================================================================
# Parameters DB Library Base Implementation
#======================================================================================================================


class BaseParDB(BaseDB):  # pylint: disable= R0904
    """Base implementation of the Par File Database"""
    #====================================================================
    # Parameters DB Library Interface for public use
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
        :param sql_factory: The SQL statement factory to be used
        """
        BaseDB.__init__(self, db_connection, table_prefix, sql_factory, IDENT_STRING)
        self.sync_slave_reload_all = False
        self.error_tolerance = error_tolerance

    def Initialize(self):
        """Initialize the database proxy"""
        # Setup function names
        BaseDB.Initialize(self)
        self.db_func_map[DB_FUNC_NAME_MIN] = "MIN"   # pylint: disable= E1101
        self.db_func_map[DB_FUNC_NAME_MAX] = "MAX"   # pylint: disable= E1101
        self.db_func_map[DB_FUNC_NAME_GETDATE] = "GETDATE()"   # pylint: disable= E1101

    def Terminate(self):
        """Terminate the database proxy"""
        BaseDB.Terminate(self)

    # --- Parameters Description Table. ----------------------------------------------
    def AddParameterDescription(self, param, type_id, unit_id):
        """Add a new parameter description to the database.
        :param param: The parameter description NAME
        :param type_id: The parameter type ID
        :param unit_id: The parameter unit ID
        :return: Returns the new parameter description ID
        """
        if param is None:
            raise AdasDBError("Parameter description name is not set.")
        if type_id is None:
            raise AdasDBError("Parameter description type is not set.")
        if unit_id is None:
            raise AdasDBError("Parameter description unit is not set.")

        pardesc = {}
        pardesc[COL_NAME_DESC_ID] = None
        pardesc[COL_NAME_DESC_NAME] = param
        pardesc[COL_NAME_DESC_TYPE] = type_id
        pardesc[COL_NAME_DESC_UNIT] = unit_id

        pdid = self.GetParameterDescriptionID(param)
        if pdid is None:
            self.AddGenericData(pardesc, self.GetQualifiedTableName(TABLE_NAME_DESCRIPTION))  # pylint: disable= E1101
            pdid = self.GetParameterDescriptionID(param)
            return pdid
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Parameter description '%s' exists already in the validation parameter database." % param
                raise AdasDBError(tmp)
            else:
                return pdid

    def UpdateParameterDescription(self, param, type_id, unit_id):
        """Update an already existing parameter description into the database.
        :param param: The parameter description NAME
        :param type_id: The parameter type ID
        :param unit_id: The parameter unit ID
        :return: Returns the parameter description ID
        """
        if param is None:
            raise AdasDBError("Parameter description name is not set.")
        if type_id is None:
            raise AdasDBError("Parameter description type is not set.")
        if unit_id is None:
            raise AdasDBError("Parameter description unit is not set.")

        pardesc = {}
        pardesc[COL_NAME_DESC_ID] = None
        pardesc[COL_NAME_DESC_NAME] = param
        pardesc[COL_NAME_DESC_TYPE] = type_id
        pardesc[COL_NAME_DESC_UNIT] = unit_id

        pdid = self.GetParameterDescriptionID(param)
        if pdid is None:
            raise AdasDBError("Parameter description '%s' doesn't exists in the validation parameter database." %
                              param)
        else:
            pardesc[COL_NAME_DESC_ID] = pdid
            # pylint: disable= E1101
            return self.UpdateGenericData(pardesc, self.GetQualifiedTableName(TABLE_NAME_DESCRIPTION),
                                          where=self.__GetParameterDescriptionCondition(param))
            # pylint: enable= E1101

    def DeleteParameterDescription(self, param):
        """Add a new parameter description to the database.
        :param param: The parameter description NAME
        :return: Returns the number of affected rows
        """
        if param is None:
            raise AdasDBError("Parameter description name is not set.")
        # pylint: disable= E1101
        return self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_DESCRIPTION),
                                      where=self.__GetParameterDescriptionCondition(param))
        # pylint: enable= E1101

    def GetParameterDescriptionID(self, param):
        """Get a parameter description ID from the database.
        :param param: The parameter description NAME
        :return: Returns the parameter description ID
        """
        if param is None:
            raise AdasDBError("Parameter description name is not set.")
        # pylint: disable= E1101
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_DESCRIPTION)],
                                         where=self.__GetParameterDescriptionCondition(param))
        # pylint: enable= E1101
        if len(entries) <= 0:
            return None
        elif len(entries) == 1:
            return entries[0][COL_NAME_DESC_ID]
        elif len(entries) > 1:
            tmp = "Parameter description '%s' cannot be resolved because it is ambiguous. (%s)" % (param, entries)
            raise AdasDBError(tmp)

    def GetParameterDescription(self, param):
        """Get a parameter description from the database.
        :param param: The parameter description NAME
        :return: Returns the parameter description record
        """
        if param is None:
            raise AdasDBError("Parameter description name is not set.")
        # pylint: disable= E1101
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_DESCRIPTION)],
                                         where=self.__GetParameterDescriptionCondition(param))
        # pylint: enable= E1101
        if len(entries) <= 0:
            return None
        elif len(entries) == 1:
            return entries[0]
        else:
            tmp = "Parameter description '%s' cannot be resolved because it is ambiguous. (%s)" % (param, entries)
            raise AdasDBError(tmp)

    def __GetParameterDescriptionCondition(self, name=None, type_id=None, unit_id=None, pdid=None):
        """Get the condition expression to access the testrun.
        :param name: Name of the parameter description (optional)
        :param type_id: Type of the parameter description (optional)
        :param unit_id: Unit of the parameter description (optional)
        :param pdid: Parameter description ID. If set, the other settings will neglected.
        return Returns the condition expression for selecting parameter descriptions
        """
        cond = None

        if pdid is not None:
            cond = SQLBinaryExpr(COL_NAME_DESC_ID, OP_EQ, SQLLiteral(pdid))
        else:
            if name is not None:
                # pylint: disable= E1101
                cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                 COL_NAME_DESC_NAME),
                                     OP_EQ, SQLLiteral(name.lower()))
                # pylint: enable= E1101
            if type_id is not None:
                cond_type = SQLBinaryExpr(COL_NAME_DESC_TYPE, OP_EQ, SQLLiteral(type_id))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_type)
                else:
                    cond = cond_type

            if unit_id is not None:
                cond_unit = SQLBinaryExpr(COL_NAME_DESC_UNIT, OP_EQ, SQLLiteral(unit_id))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_unit)
                else:
                    cond = cond_unit

        return cond

    # --- Parameter Configs Table. ---------------------------------------------------
    def AddConfig(self, config):
        """Add a new parameter config to the database.
        :param config: The parameter config NAME
        :return: Returns the new parameter config ID
        """
        if config is None:
            raise AdasDBError("Parameter config name is not set.")

        parcfg = {}
        parcfg[COL_NAME_CFG_ID] = None
        parcfg[COL_NAME_CFG_NAME] = config

        pcid = self.GetConfigID(config)
        if pcid is None:
            self.AddGenericData(parcfg, self.GetQualifiedTableName(TABLE_NAME_CONFIGS))  # pylint: disable= E1101
            pcid = self.GetConfigID(config)
            return pcid
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("Parameter config '%s' exists already in the validation parameter database." %
                                  config)
            else:
                return pcid

    def DeleteConfig(self, config):
        """Add a new parameter description to the database.
        :param config: The parameter config NAME
        :return: Returns the number of affected rows
        """
        if config is None:
            raise AdasDBError("Parameter config name is not set.")
        # pylint: disable= E1101
        return self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_CONFIGS),
                                      where=self.__GetConfigCondition(name=config))
        # pylint: enable= E1101

    def GetConfigID(self, config):
        """Get a parameter config ID from the database.
        :param config: The parameter config NAME
        :return: Returns the parameter config ID
        """
        if config is None:
            raise AdasDBError("Parameter config name is not set.")
        # pylint: disable= E1101
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_CONFIGS)],
                                         where=self.__GetConfigCondition(name=config))
        # pylint: enable= E1101
        if len(entries) <= 0:
            return None
        elif len(entries) == 1:
            return entries[0][COL_NAME_CFG_ID]
        elif len(entries) > 1:
            tmp = "Parameter config '%s' cannot be resolved because it is ambiguous. (%s)" % (config, entries)
            raise AdasDBError(tmp)

    def __GetConfigCondition(self, name=None, cid=None):
        """Get the condition expression to access the testrun.
        :param name: Name of the parameter config(optional)
        :param id: Parameter config ID. If set, the other settings will neglected.
        return Returns the condition expression for selecting parameter configs
        """
        cond = None

        if cid is not None:
            cond = SQLBinaryExpr(COL_NAME_CFG_ID, OP_EQ, SQLLiteral(cid))
        else:
            if name is not None:
                # pylint: disable= E1101
                cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                 COL_NAME_CFG_NAME), OP_EQ, SQLLiteral(name.lower()))
                # pylint: enable= E1101
        return cond

    # --- Parameter Config Map Table. ----------------------------------------------------
    def AddParameterConfigMap(self, config_id, par_id):
        """Add a new parameter config mapping to the database.
        :param config_id: The parameter config ID
        :param par_id: The parameter description ID
        :return: Returns the parameter config map ID
        """
        if config_id is None:
            raise AdasDBError("Parameter config identifier is not set.")
        if par_id is None:
            raise AdasDBError("Parameter description identifier is not set.")

        parcfgmap = {}
        parcfgmap[COL_NAME_PARCFG_MAP_ID] = None
        parcfgmap[COL_NAME_PARCFG_MAP_PDID] = par_id
        parcfgmap[COL_NAME_PARCFG_MAP_PCID] = config_id

        pmid = self.GetParameterConfigMapID(config_id, par_id)
        if pmid is None:
            # pylint: disable= E1101
            self.AddGenericData(parcfgmap, self.GetQualifiedTableName(TABLE_NAME_CFGMAP))
            # pylint: enable= E1101
            pmid = self.GetParameterConfigMapID(config_id, par_id)
            return pmid
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Parameter config mapping [%s|%s] " % (config_id, par_id)
                tmp += "exists already in the validation parameter database."
                raise AdasDBError(tmp)
            else:
                return pmid

    def DeleteParameterConfigMap(self, config_id, par_id):
        """Delete a parameter config mapping from the database.
        :param config_id: The parameter config ID
        :param par_id: The parameter description ID
        :return: Returns the number of affected rows
        """
        if config_id is None:
            raise AdasDBError("Parameter config identifier is not set.")
        if par_id is None:
            raise AdasDBError("Parameter description identifier is not set.")
        # pylint: disable= E1101
        return self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_CFGMAP),
                                      where=self.__GetParameterConfigMapCondition(config_id, par_id))
        # pylint: enable= E1101

    def GetParameterConfigMapID(self, config_id, par_id):
        """Get a parameter config mapping identifier from the database.
        :param config_id: The parameter config ID
        :param par_id: The parameter description ID
        :return: Returns the parameter config map ID
        """
        if config_id is None:
            raise AdasDBError("Parameter config identifier is not set.")
        if par_id is None:
            raise AdasDBError("Parameter description identifier is not set.")
        # pylint: disable= E1101
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_CFGMAP)],
                                         where=self.__GetParameterConfigMapCondition(config_id, par_id))
        # pylint: enable= E1101
        if len(entries) <= 0:
            return None
        elif len(entries) == 1:
            return entries[0][COL_NAME_PARCFG_MAP_ID]
        elif len(entries) > 1:
            tmp = "Parameter config mapping [%s|%s] " % (config_id, par_id)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)

    def __GetParameterConfigMapCondition(self, config_id=None, par_id=None, pcmid=None):  # pylint: disable= R0201
        """Get the condition expression to access the testrun.
        :param config_id: The parameter config ID
        :param par_id: The parameter description ID
        :param pcmid: Parameter config ID. If set, the other settings will neglected.
        return Returns the condition expression for selecting parameter config mappings
        """
        cond = None

        if pcmid is not None:
            cond = SQLBinaryExpr(COL_NAME_PARCFG_MAP_ID, OP_EQ, SQLLiteral(pcmid))
        else:
            if config_id is not None:
                cond = SQLBinaryExpr(COL_NAME_PARCFG_MAP_PCID, OP_EQ, SQLLiteral(config_id))

            if par_id is not None:
                cond_par = SQLBinaryExpr(COL_NAME_PARCFG_MAP_PDID, OP_EQ, SQLLiteral(par_id))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_par)
                else:
                    cond = cond_par

        return cond

    # --- Parameter Values Table. ----------------------------------------------------
    def AddParameterValue(self, measid, pmid, userid, wfid, value):
        """Add a new parameter value to the database.
        :param measid: The measurement file ID
        :param pmid: The parameter config map ID
        :param userid: The user ID
        :param wfid: The workflow ID
        :param value: The parameter value
        :return: Returns the parameter value ID
        """
        if measid is None:
            raise AdasDBError("Parameter measurement file identifier is not set.")
        if pmid is None:
            raise AdasDBError("Parameter config map is not set.")
        if userid is None:
            raise AdasDBError("Parameter user identifier is not set.")
        if wfid is None:
            raise AdasDBError("Parameter workflow identifier is not set.")
        if value is None:
            raise AdasDBError("Parameter value is not set.")

        parval = {}
        parval[COL_NAME_PAR_VAL_ID] = None
        parval[COL_NAME_PAR_VAL_MEASID] = measid
        parval[COL_NAME_PAR_VAL_PMID] = pmid
        parval[COL_NAME_PAR_VAL_USERID] = userid
        parval[COL_NAME_PAR_VAL_WFID] = wfid
        # Remark: Don't put NULL for the timestamp, because the timestamp column is NULLABLE
        # Leave it out of the query and it will be auto-completed with the current TIMESTAMP
        # parval[COL_NAME_PAR_VAL_TIMESTAMP] = CURRENT_TIMESTAMP
        parval[COL_NAME_PAR_VAL_VALUE] = value

        parid = self.GetParameterValueID(measid, pmid)
        if parid is None:
            # pylint: disable= E1101
            self.AddGenericData(parval, self.GetQualifiedTableName(TABLE_NAME_VALUE))
            # pylint: enable= E1101
            parid = self.GetParameterValueID(measid, pmid)
            return parid
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                tmp = "Parameter value [%s|%s|%s|%s] " % (measid, pmid, userid, wfid)
                tmp += "exists already in the validation parameter database."
                raise AdasDBError(tmp)
            else:
                return parid

    def UpdateParameterValue(self, measid, pmid, userid, wfid, value):
        """Update a parameter value into the database.
        :param measid: The measurement file ID
        :param pmid: The parameter config map ID
        :param userid: The user ID
        :param wfid: The workflow ID
        :param value: The parameter value
        :return: Returns the parameter value ID
        """
        if measid is None:
            raise AdasDBError("Parameter measurement file identifier is not set.")
        if pmid is None:
            raise AdasDBError("Parameter config map is not set.")
        if userid is None:
            raise AdasDBError("Parameter user identifier is not set.")
        if wfid is None:
            raise AdasDBError("Parameter workflow identifier is not set.")
        if value is None:
            raise AdasDBError("Parameter value is not set.")

        parval = {}
        parval[COL_NAME_PAR_VAL_ID] = None
        parval[COL_NAME_PAR_VAL_MEASID] = measid
        parval[COL_NAME_PAR_VAL_PMID] = pmid
        parval[COL_NAME_PAR_VAL_USERID] = userid
        parval[COL_NAME_PAR_VAL_WFID] = wfid
        # Remark: Don't put NULL for the timestamp, because the timestamp column is NULLABLE
        # Leave it out of the query and it will be auto-completed with the current TIMESTAMP
        # pylint: disable= E1101
        parval[COL_NAME_PAR_VAL_TIMESTAMP] = self.GetCurrDateTimeExpr()
        # pylint: enable= E1101
        parval[COL_NAME_PAR_VAL_VALUE] = value

        parid = self.GetParameterValueID(measid, pmid)
        if parid is None:
            tmp = "Parameter value [%s|%s|%s|%s] " % (measid, pmid, userid, wfid)
            tmp += "doesn't exists in the validation parameter database."
            raise AdasDBError(tmp)
        else:
            parval[COL_NAME_PAR_VAL_ID] = parid
            # pylint: disable= E1101
            return self.UpdateGenericData(parval,
                                          self.GetQualifiedTableName(TABLE_NAME_VALUE),
                                          where=self.__GetParameterValueCondition(measid, pmid))
            # pylint: enable= E1101

    def DeleteParameterValue(self, measid, pmid):
        """Delete a parameter value from the database.
        :param measid: The measurement file ID
        :param pmid: The parameter config map ID
        :return: Returns the number of affected rows
        """
        if measid is None:
            raise AdasDBError("Parameter measurement file identifier is not set.")
        if pmid is None:
            raise AdasDBError("Parameter config map is not set.")
        # pylint: disable= E1101
        return self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_VALUE),
                                      where=self.__GetParameterValueCondition(measid, pmid))
        # pylint: enable= E1101

    def GetParameterValue(self, measid, pmid):
        """Get a parameter value from the database.
        :param measid: The measurement file ID
        :param pmid: The parameter config map ID
        :return: Returns the parameter value
        """
        if measid is None:
            raise AdasDBError("Parameter measurement file identifier is not set.")
        if pmid is None:
            raise AdasDBError("Parameter config map is not set.")
        # pylint: disable= E1101
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VALUE)],
                                         where=self.__GetParameterValueCondition(measid, pmid))
        # pylint: enable= E1101
        if len(entries) <= 0:
            return None
        elif len(entries) == 1:
            return entries[0][COL_NAME_PAR_VAL_VALUE]
        elif len(entries) > 1:
            tmp = "Parameter value [%s|%s|%s] " % (measid, pmid, entries)
            tmp += "cannot be resolved because it is ambiguous."
            raise AdasDBError(tmp)

    def GetParameterWorkflowID(self, measid, pmid):
        """Get a parameter workflow ID from the database.
        :param measid: The measurement file ID
        :param pmid: The parameter config map ID
        :return: Returns the parameter workflow id
        """
        if measid is None:
            raise AdasDBError("Parameter measurement file identifier is not set.")
        if pmid is None:
            raise AdasDBError("Parameter config map is not set.")
        # pylint: disable= E1101
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VALUE)],
                                         where=self.__GetParameterValueCondition(measid, pmid))
        # pylint: enable= E1101
        if len(entries) <= 0:
            return None
        elif len(entries) == 1:
            return entries[0][COL_NAME_PAR_VAL_WFID]
        elif len(entries) > 1:
            tmp = "Parameter value [%s|%s|%s] " % (measid, pmid, entries)
            tmp += "cannot be resolved because it is ambiguous."
            raise AdasDBError(tmp)

    def GetParameterValueID(self, measid, pmid):
        """Get a parameter value ID from the database.
        :param measid: The measurement file ID
        :param pmid: The parameter config map ID
        :return: Returns the parameter value ID
        """
        if measid is None:
            raise AdasDBError("Parameter measurement file identifier is not set.")
        if pmid is None:
            raise AdasDBError("Parameter config map is not set.")
        # pylint: disable= E1101
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VALUE)],
                                         where=self.__GetParameterValueCondition(measid, pmid))
        # pylint: enable= E1101
        if len(entries) <= 0:
            return None
        elif len(entries) == 1:
            return entries[0][COL_NAME_PAR_VAL_ID]
        elif len(entries) > 1:
            tmp = "Parameter value [%s|%s|%s] " % (measid, pmid, entries)
            tmp += "cannot be resolved because it is ambiguous."
            raise AdasDBError(tmp)

    def __GetParameterValueCondition(self, measid=None, pmid=None, userid=None, wfid=None, pvid=None):
        # pylint: disable= R0201
        """Get the condition expression to access the parameter value.
        :param measid: The measurement file ID (optional)
        :param pmid: The parameter config map ID (optional)
        :param userid: The parameter user ID (optional)
        :param wfid: The parameter workflow ID (optional)
        :param pvid: Parameter value ID. If set, the other settings will neglected.
        return Returns the condition expression
        """
        cond = None

        if pvid is not None:
            cond = SQLBinaryExpr(COL_NAME_PAR_VAL_ID, OP_EQ, SQLLiteral(pvid))
        else:
            if measid is not None:
                cond = SQLBinaryExpr(COL_NAME_PAR_VAL_MEASID, OP_EQ, SQLLiteral(measid))

            if pmid is not None:
                cond_pmid = SQLBinaryExpr(COL_NAME_PAR_VAL_PMID, OP_EQ, SQLLiteral(pmid))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_pmid)
                else:
                    cond = cond_pmid

            if userid is not None:
                cond_userid = SQLBinaryExpr(COL_NAME_PAR_VAL_USERID, OP_EQ, SQLLiteral(userid))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_userid)
                else:
                    cond = cond_userid

            if wfid is not None:
                cond_wfid = SQLBinaryExpr(COL_NAME_PAR_VAL_WFID, OP_EQ, SQLLiteral(wfid))
                if cond is not None:
                    cond = SQLBinaryExpr(cond, OP_AND, cond_wfid)
                else:
                    cond = cond_wfid

        return cond

    # --- Utilities Functions --------------------------------------------------------

    # --- Parameter Configuration Functions ------------------------------------------
    def AddParameterDescriptionToConfig(self, config, param):
        """Add a parameter description to a parameter configuration
        :param config: The parameter configuration NAME
        :param param: The parameter description NAME
        :return: Returns the config-parameter map ID
        """
        par_id = self.GetParameterDescriptionID(param)
        config_id = self.GetConfigID(config)
        return self.AddParameterConfigMap(config_id, par_id)

    def DeleteParameterDescriptionFromConfig(self, config, param):
        """Delete a parameter description from a parameter configuration
        :param config: The parameter configuration NAME
        :param param: The parameter description NAME
        :return: Returns the number of affected rows
        """
        par_id = self.GetParameterDescriptionID(param)
        config_id = self.GetConfigID(config)
        return self.DeleteParameterConfigMap(config_id, par_id)

    def GetParameterConfigMapIDUsingNames(self, config, param):
        """Get a parameter config identifier using config and parameter descriptions names
        :param config: The parameter config NAME
        :param param: The parameter description NAME
        :return: Returns the parameter config map ID
        """
        par_id = self.GetParameterDescriptionID(param)
        config_id = self.GetConfigID(config)
        return self.GetParameterConfigMapID(config_id, par_id)

    # --- Parameter Value Functions --------------------------------------------------
    def AddParameterValueToMeasId(self, measid, config, param, userid, wfid, value):
        """Add a new parameter value for a file
        :param measid: The measurement file ID
        :param config: The parameter config NAME
        :param param: The parameter description NAME
        :param userid: The user ID
        :param wfid: The workflow ID
        :param value: The parameter value
        :return: Returns the new parameter value ID
        """
        par_id = self.GetParameterDescriptionID(param)
        config_id = self.GetConfigID(config)
        pmid = self.GetParameterConfigMapID(config_id, par_id)
        return self.AddParameterValue(measid, pmid, userid, wfid, value)

    def UpdateParameterValueOfMeasId(self, measid, config, param, userid, wfid, value):
        """Update a parameter value associated to a file
        :param measid: The measurement file ID
        :param config: The parameter config NAME
        :param param: The parameter description NAME
        :param userid: The user ID
        :param wfid: The workflow ID
        :param value: The parameter value
        :return: Returns the parameter value ID
        """
        par_id = self.GetParameterDescriptionID(param)
        config_id = self.GetConfigID(config)
        pmid = self.GetParameterConfigMapID(config_id, par_id)
        return self.UpdateParameterValue(measid, pmid, userid, wfid, value)

    def DeleteParameterValueFromMeasId(self, measid, config, param):
        """Delete parameter value associated to a file
        :param measid: The measurement file ID
        :param config: The parameter config NAME
        :param param: The parameter description NAME
        :return: Returns the number of affected rows
        """
        par_id = self.GetParameterDescriptionID(param)
        config_id = self.GetConfigID(config)
        pmid = self.GetParameterConfigMapID(config_id, par_id)
        return self.DeleteParameterValue(measid, pmid)

    def GetParameterValueOfMeasId(self, measid, config, param):
        """Get parameter value associated to a file
        :param measid: The measurement file ID
        :param config: The parameter config NAME
        :param param: The parameter description NAME
        :return: Returns the parameter value
        """
        par_id = self.GetParameterDescriptionID(param)
        config_id = self.GetConfigID(config)
        pmid = self.GetParameterConfigMapID(config_id, par_id)
        return self.GetParameterValue(measid, pmid)

    def GetParameterWorkflowIdOfMeasId(self, measid, config, param):
        """Get parameter Workflow associated to a file
        :param measid: The measurement file ID
        :param config: The parameter config NAME
        :param param: The parameter description NAME
        :return: Returns the parameter workflowid
        """
        par_id = self.GetParameterDescriptionID(param)
        config_id = self.GetConfigID(config)
        pmid = self.GetParameterConfigMapID(config_id, par_id)
        return self.GetParameterWorkflowID(measid, pmid)


#====================================================================
# Parameters DB Library SQL Server Compact Implementation
#====================================================================
class SQLCEParDB(BaseParDB, SQLCEBaseDB):  # pylint: disable= R0904
    """SQL Server Compact Edition Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseParDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLCEBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseParDB.Initialize(self)
        SQLCEBaseDB.Initialize(self)


#====================================================================
# Parameters DB Library Oracle Implementation
#====================================================================
class OracleParDB(BaseParDB, OracleBaseDB):  # pylint: disable= R0904
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseParDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        OracleBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseParDB.Initialize(self)
        OracleBaseDB.Initialize(self)


#====================================================================
# Parameters DB Library SQLite 3 Implementation
#====================================================================
class SQLite3ParDB(BaseParDB, SQLite3BaseDB):  # pylint: disable= R0904
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseParDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLite3BaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseParDB.Initialize(self)
        SQLite3BaseDB.Initialize(self)

"""
$Log: par.py  $
Revision 1.1 2021/12/13 17:56:44CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/par/project.pj
Revision 1.16 2013/11/25 14:39:36CET Ahmed, Zaheer (uidu7634) 
fixed pep8 and pylint errors
Added GetParameterDescription functio to return record
- Added comments -  uidu7634 [Nov 25, 2013 2:39:36 PM CET]
Change Package : 192744:1 http://mks-psad:7002/im/viewissue?selection=192744
Revision 1.15 2013/07/29 08:44:41CEST Raedler, Guenther (uidt9430)
- revert changes of rev. 1.14
--- Added comments ---  uidt9430 [Jul 29, 2013 8:44:42 AM CEST]
Change Package : 191735:1 http://mks-psad:7002/im/viewissue?selection=191735
Revision 1.14 2013/07/04 15:01:47CEST Mertens, Sven (uidv7805)
providing tableSpace to BaseDB for what sub-schema space each module is intended to be responsible
--- Added comments ---  uidv7805 [Jul 4, 2013 3:01:47 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.13 2013/04/26 10:46:10CEST Mertens, Sven (uidv7805)
moving strIdent
--- Added comments ---  uidv7805 [Apr 26, 2013 10:46:11 AM CEST]
Change Package : 179495:4 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.12 2013/04/25 14:35:13CEST Mertens, Sven (uidv7805)
epydoc adaptation to colon instead of at
Revision 1.11 2013/04/19 13:37:15CEST Hecker, Robert (heckerr)
Functionality reverted to revision 1.9.
--- Added comments ---  heckerr [Apr 19, 2013 1:37:16 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.10 2013/04/12 14:37:06CEST Mertens, Sven (uidv7805)
adding a short representation used by db_connector.PostInitialize
--- Added comments ---  uidv7805 [Apr 12, 2013 2:37:07 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.9 2013/04/03 08:02:18CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:18 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/04/02 10:05:34CEST Raedler, Guenther (uidt9430)
- use logging for all log messages again
- use specific indeitifier names
- removed some pylint warnings
--- Added comments ---  uidt9430 [Apr 2, 2013 10:05:34 AM CEST]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.7 2013/03/26 16:19:38CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:39 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/21 17:22:39CET Mertens, Sven (uidv7805)
solving some pylint warnings / errors
--- Added comments ---  uidv7805 [Mar 21, 2013 5:22:40 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.5 2013/03/04 07:47:26CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 4, 2013 7:47:28 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/28 08:12:22CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:22 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/27 16:19:58CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:59 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/19 14:07:31CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:32 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 09:59:24CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/db/par/project.pj
Revision 1.5 2012/04/13 09:16:23CEST Spruck, Jochen (spruckj)
- If the parameter is updated, update the timestamp
- Add GetParameterWorkflowID function
- Add GetParameterWorkflowIdOfMeasId function
--- Added comments ---  spruckj [Apr 13, 2012 9:16:23 AM CEST]
Change Package : 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.4 2012/03/09 11:40:19CET Farcas-EXT, Florian Radu (uidu4753)
Changed the return type for GetParameterValueOfMeasId for be value instead of record
--- Added comments ---  uidu4753 [Mar 9, 2012 11:40:19 AM CET]
Change Package : 100439:1 http://mks-psad:7002/im/viewissue?selection=100439
Revision 1.3 2012/03/05 10:29:08CET Farcas-EXT, Florian Radu (uidu4753)
Corrected id return value
--- Added comments ---  uidu4753 [Mar 5, 2012 10:29:08 AM CET]
Change Package : 100439:1 http://mks-psad:7002/im/viewissue?selection=100439
Revision 1.2 2012/02/29 10:33:47CET Farcas-EXT, Florian Radu (uidu4753)
Corrected the timestamp usage and the comments
--- Added comments ---  uidu4753 [Feb 29, 2012 10:33:47 AM CET]
Change Package : 100439:1 http://mks-psad:7002/im/viewissue?selection=100439
Revision 1.1 2012/02/28 16:39:24CET Farcas-EXT, Florian Radu (uidu4753)
Initial revision
Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/05_Testing/05_Test_Environment/algo/
    ars301_req_test/valf_tests/adas_database/par/project.pj
"""
