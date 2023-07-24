""" Python library to access Constraint Label database schema
db_cldata.py
-------------

documentation of db_cldata:

TODO

:org:           Continental AG
:author:        Sven Mertens

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:03CET $
"""

# Import Python Modules -----------------------------------------------------------------------------------------------
from datetime import datetime
#from sys import path as sp
#from os import path as op
import logging
import copy


# Set system path -----------------------------------------------------------------------------------------
'''
INCPATH = op.abspath(op.join(__file__, r"..\.."))
if INCPATH not in sp:
    sp.append(INCPATH)
del INCPATH
'''
# Import Local Python Modules -----------------------------------------------------------------------------------------
from stk.db.db_sql import SQLTableExpr, SQLBinaryExpr, SQLColumnExpr, OP_EQ, SQLIntegral, OP_LIKE, SQLString, \
    SQLFuncExpr, OP_AS, OP_IN, GenericSQLSelect
from stk.db.db_common import BaseDB, OracleBaseDB, SQLite3BaseDB, SQLCEBaseDB

from stk.util.trie import CTrie


#======================================================================================================================
# Constants
#======================================================================================================================

# Table base names:
TABLE_NAME_SIG_CONSIG = "CL_ConsSignals"
TABLE_NAME_SIG_SIGCON = "CL_SigConstraints"
TABLE_NAME_SIG_CONMAP = "CL_ConstraintMap"
TABLE_NAME_SIG_CONSET = "CL_ConstraintSets"
TABLE_NAME_SIG_TRIG = "CL_Triggers"

#  Column base names:
# TABLE_NAME_SIG_CONSIG:
COL_NAME_CONSIG_SIGNALID = "SIGNALID"
COL_NAME_CONSIG_NAME = "NAME"
COL_NAME_CONSIG_DERIVED = "DERIVED"
COL_NAME_CONSIG_STATE = "STATEID"
COL_NAME_CONSIG_MODTIME = "MODTIME"

# TABLE_NAME_SIG_SIGCON:
COL_NAME_SIGCON_CONSID = "CONSID"
COL_NAME_SIGCON_MEASID = "MEASID"
COL_NAME_SIGCON_TRIGGERID = "TRIGGERID"
COL_NAME_SIGCON_SIGNALID = "SIGNALID"
COL_NAME_SIGCON_BEGINTS = "BEGINTS"
COL_NAME_SIGCON_ENDTS = "ENDTS"
COL_NAME_SIGCON_UPPERTOL = "UPPERTOL"
COL_NAME_SIGCON_LOWERTOL = "LOWERTOL"
COL_NAME_SIGCON_COEFA = "COEFFA"
COL_NAME_SIGCON_COEFB = "COEFFB"
COL_NAME_SIGCON_MINSAMPLES = "MINSAMPLES"
COL_NAME_SIGCON_MAXSAMPLES = "MAXSAMPLES"

# TODO: check if this really is needed
COL_NAMES_SIGCON = [COL_NAME_SIGCON_CONSID,
                    COL_NAME_SIGCON_MEASID,
                    COL_NAME_SIGCON_TRIGGERID,
                    COL_NAME_SIGCON_SIGNALID,
                    COL_NAME_SIGCON_BEGINTS,
                    COL_NAME_SIGCON_ENDTS,
                    COL_NAME_SIGCON_UPPERTOL,
                    COL_NAME_SIGCON_LOWERTOL,
                    COL_NAME_SIGCON_COEFA,
                    COL_NAME_SIGCON_COEFB,
                    COL_NAME_SIGCON_MINSAMPLES,
                    COL_NAME_SIGCON_MAXSAMPLES]

INTEGER_NOT_NULL = 'INTEGER_NOT_NULL'
FLOAT_NOT_NULL = 'FLOAT_NOT_NULL'

SIGCON_TEMPLATE = {COL_NAME_SIGCON_CONSID: None,
                   COL_NAME_SIGCON_MEASID: None,
                   COL_NAME_SIGCON_TRIGGERID: None,
                   COL_NAME_SIGCON_SIGNALID: 'INT_OR_STR',
                   COL_NAME_SIGCON_BEGINTS: INTEGER_NOT_NULL,
                   COL_NAME_SIGCON_ENDTS: INTEGER_NOT_NULL,
                   COL_NAME_SIGCON_UPPERTOL: FLOAT_NOT_NULL,
                   COL_NAME_SIGCON_LOWERTOL: FLOAT_NOT_NULL,
                   COL_NAME_SIGCON_COEFA: FLOAT_NOT_NULL,
                   COL_NAME_SIGCON_COEFB: FLOAT_NOT_NULL,
                   COL_NAME_SIGCON_MINSAMPLES: INTEGER_NOT_NULL,
                   COL_NAME_SIGCON_MAXSAMPLES: INTEGER_NOT_NULL}

# TABLE_NAME_SIG_CONMAP:
COL_NAME_CONMAP_MAPID = "MAPID"
COL_NAME_CONMAP_SETID = "SETID"
COL_NAME_CONMAP_CONSID = "CONSID"

# TABLE_NAME_SIG_CONSET:
COL_NAME_CONSET_SETID = "SETID"
COL_NAME_CONSET_PARENTID = "PARENTID"
COL_NAME_CONSET_NAME = "NAME"
COL_NAME_CONSET_MEASID = "MEASID"
COL_NAME_CONSET_COMMENT = "COMMENT"
COL_NAME_CONSET_SETOP = "OPERANT"
COL_NAME_CONSET_MODTIME = "MODTIME"

# TABLE_NAME_SIG_TRIG:
COL_NAME_TRIGGERS_TRIGGERID = "TRIGGERID"
COL_NAME_TRIGGERS_PARENTID = "PARENTID"
COL_NAME_TRIGGERS_SIGNALID = "SIGNALID"
COL_NAME_TRIGGERS_VALUE = "VALUE"
COL_NAME_TRIGGERS_OPERANT = "OPERANT"
COL_NAME_TRIGGERS_COND = "CONDITION"
COL_NAME_TRIGGERS_USAGE = "USAGE"

IDENT_STRING = "dbcl"


#TODO: how to initialize consTrie? rework trie/kid structure
KID_NAME_SETID = 'SetID'
KID_NAME_KIDIDS = 'KidIDs'

KID_VALUENAME_OPERANT = 'Operant'
KID_VALUENAME_CONSTRAINTS = 'Constraints'
KID_VALUENAME_SIGNALS = 'Signals'

KID_VALUENAME_COMP_RESULTS = 'Compare_results'
KID_VALUENAME_COMP_DETAILS = 'Compare_details'
KID_VALUENAME_COMP_SUM = 'Compare_summary'

SIGCON_DEFAULT_TRIGGER = 'Timestamp'


# --- this should go to db_common -------------------------------------------------------------------------------------
COL_NAME_LAST_ROWID = "ROWID"
STMT_LAST_ROWID_SQLITE = "last_insert_rowid"

#TODO: if define functions to return last inserted row id does not work, get GetGenericMaxValue working
DB_FUNC_NAME_MAX = "DB_FUNC_NAME_MAX"


CL_OP_AND = 0
CL_OP_OR = 1
CL_OP_XOR = 2
CL_OP_NAND = 3
CL_OP_NOR = 4

CL_OP_FUNC_MAP = {CL_OP_AND: 'not False in %s',
                  CL_OP_OR: 'True in %s',
                  CL_OP_XOR: '%s.count(True)==1',
                  CL_OP_NAND: 'False in %s',
                  CL_OP_NOR: 'not True in %s'}

CL_OP_NAME_MAP = {CL_OP_AND: 'AND',
                  CL_OP_OR: 'OR',
                  CL_OP_XOR: 'XOR',
                  CL_OP_NAND: 'NAND',
                  CL_OP_NOR: 'NOR'}

class BaseCLDBException(StandardError):
    """Base of all cl errors"""
    pass

#======================================================================================================================
# Constraint DB Libary Base Implementation
#======================================================================================================================

#TODO: change AddGenericData in db_common to return real rowcount
#-> that value can be used to check result, see Rev. 1.40

#TODO: force to build up foreign key connections, e.g. ConsSognal <-> SignalConstraint


class BaseCLDB(BaseDB):  # pylint: disable=R0904
    """Base implementation of the CL Database"""

    def __init__(self, db_connection, table_prefix):  # pylint: disable-msg=W0613
        """Initialize constraint database
        :param table_prefix: table / schema name prefix
        :param db_connection: database connection to be used
        :param sql_factory: unused, kept for backward compatibility
        :param sql_factory: unused, kept for backward compatibility
        :param error_tolerance: unused, kept for backward compatibility
        """
        BaseDB.__init__(self, db_connection, table_prefix, strIdent=IDENT_STRING)
        # self.error_tolerance = error_tolerance

    def getLastRowID(self, column_name, table_name):
        """function to return last rowid by executing last_rowid function
        !!! must be overwritten by derived DB classes depending on DB type !!!
        :return: autoincrement ID
        """
        logging.warning('Baseclass BaseCLDB has no clean implementation of function getLastRowID(). ' \
                        'That might lead to an ERROR!!!')

        if column_name is None or table_name is None:
            logging.error('When using the baseclass implementation column_name and table_name must be given.')

        # def GetGenericMaxValue(self, column_name, table_name):
        """Get maximum value of certain column in a table.
        :param column_name: The name of the column to take the maximum from. [str]
        :param table_name: The name of the table to take the maximum from. [str]

        :return max_value: Maximum value found.
        """
        sql_select_stmt = self.sql_factory.GetSelectBuilder()
        sql_select_stmt.select_list = [SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_MAX], column_name)]
        sql_select_stmt.table_list = [self.GetQualifiedTableName(table_name)]
        stmt = str(sql_select_stmt)
        # fetch max. value
        max_value = 0
        cursor = self.db_connection.cursor()
        try:
            logging.debug(stmt)
            cursor.execute(stmt)
            row = cursor.fetchone()
            if (row is not None) and (row[0] is not None):
                max_value = row[0]
        finally:
            cursor.close()
        # done
        return max_value

    #==================================================================================================================
    # Conversion methods
    #==================================================================================================================

    #TODO: these methods ever used?
    def _getOne(self, stmt):
        """returns only first row of SQL select execution
        :param stmt: select statement
        :return: fetchone() result
        """
        cursor = self.db_connection.cursor()
        try:
            cursor.execute(stmt)
            res = str(cursor.fetchone()[0])
        finally:
            cursor.close()
        # done
        return res

    def _getCol(self, stmt):
        """returns only first column of SQL select execution
        :param stmt: select statement
        :return: for row in fetchone([0]) result
        """
        cursor = self.db_connection.cursor()
        try:
            res = []
            for row in cursor.execute(stmt):
                res.append(str(row[0]))
        finally:
            cursor.close()
        # done
        return res

    #==================================================================================================================
    # Handling of special data
    #==================================================================================================================

    def getConstraints(self, consSet, measid):
        """returns related constraint sets for given ConstraintSet
        :param consSet: constraint set name or MeasID    #TODO: what means MeasID? = Cat_Files MeasID?
        :return: dict of constraint set hirarchy
        """
        # get initial constraint set
        cons = self.getConstraintSet(consSet, measid)

        if len(cons) == 0:
            raise BaseCLDBException("WARNING: no matching data found for ConstraintSet %s" % consSet)

        parent_id = cons[0][COL_NAME_CONSET_SETID]

        sigcons_list = self.getSigContraintsPerSet(parent_id)

        consTrie = CTrie(parent_id,
                         None,
                         [{KID_VALUENAME_OPERANT: cons[0][COL_NAME_CONSET_SETOP],
                           KID_VALUENAME_CONSTRAINTS: sigcons_list,
                           #KID_VALUENAME_SIGNALS: {},
                           KID_VALUENAME_COMP_RESULTS: {KID_VALUENAME_COMP_DETAILS: [],
                                                        KID_VALUENAME_COMP_SUM: None}}])
        # TODO: why here own ID also in allKidIDs?

        # get child constraint sets
        while len(cons) > 0:
            where = COL_NAME_CONSET_PARENTID + ' IN (%s)' % (", ".join([str(p[COL_NAME_CONSET_SETID]) for p in cons]))
            cons = self.getConstraintSet(where=where)

            for cc in cons:

                sigcons_list = self.getSigContraintsPerSet(cc[COL_NAME_CONSET_SETID])

                # consTrie.addKid(cc[0], cc[1], cc[2])
                # TODO: update to new dict structs
                consTrie.addKid(cc[COL_NAME_CONSET_SETID],
                                cc[COL_NAME_CONSET_PARENTID],
                                [{KID_VALUENAME_OPERANT: cc[COL_NAME_CONSET_SETOP],
                                  KID_VALUENAME_CONSTRAINTS: sigcons_list,
                                  #KID_VALUENAME_SIGNALS: {},
                                  KID_VALUENAME_COMP_RESULTS: {KID_VALUENAME_COMP_DETAILS: [],
                                                               KID_VALUENAME_COMP_SUM: None}}])

        return consTrie

    def addConstraints(self, set_name, meas_id, cons, operant, parent_id=None):
        """inserts new constraint(s) into DB
        :param set_name: name of constraint set to create [str]
        :param meas_id: measurement id to refer to
        :param signame: signal name to which constraint(s) belong
        :param cons: list of constraints to add, each consisting of
        [BeginTS, EndTS, UpperTol, LowerTol, CoeffA, CoeffB, MinSamples, MaxSamples, SigName]

        :param operant: operant constraints are connected with
        :return: SetID of just created constraint set
        """

        # check meas_id format
        if not isinstance(meas_id, int):
            raise BaseCLDBException("ERROR: meas_id given is no integer: %s" % str(meas_id))

        # add new signal constraint(s)
        consids = []
        for con in cons:

            # check signal ID
            sig = self.getConsSignal(con[COL_NAME_SIGCON_SIGNALID], select=[COL_NAME_CONSIG_SIGNALID])
            if len(sig) == 0:
                if isinstance(con[COL_NAME_SIGCON_SIGNALID], str):
                    sig_id = self.addConsSignal(con[COL_NAME_SIGCON_SIGNALID])
                    con[COL_NAME_SIGCON_SIGNALID] = sig_id
                else:
                    raise BaseCLDBException('SignalID %s missing in table %s'
                                            % (con[COL_NAME_SIGCON_SIGNALID], TABLE_NAME_SIG_CONSIG))

            # add constraint
            consids.append(self.addSigConstraint(con))

        # add new constraint set
        # TODO: add to set if set_name already exists?
        setid = self.addConstraintSet(set_name, operant, parent_id=parent_id, meas_id=meas_id)

        # add mappings
        for conid in consids:

            self.addConsMap(setid, conid)

        return setid

    #==================================================================================================================
    # Handling of file data
    #==================================================================================================================

    # --- Signal Constraint ---------------------------------------------------------------------------------------
    def addSigConstraint(self, data_dict):  #, col=None, colID=None):
        """Add a new signal constraint record to the database.
        :param col: column to use: either MeasID (CAT_FILES.MEASID) or TriggerID
        :param colID: id of column
        :param beginTS: BeginTimestamp of measurement: absolut if related to measID, relative if using triggerID
        :param endTS: EndTimestamp of measurement: length
        :param upperTol: upper value tolerance (+deviation)
        :param lowerTol: lower value tolerance (-deviation)
        :param coeffA: function coefficient A: y = Ax + B
        :param coeffB: function coefficient B: y = Ax + B
        :param minSamples: measurement samples which need to fit at minimum
        :param maxSamples: measurement samples which need to fit at maximum
        :return: ConsID of last added signal constraint
        """

        # check dict values
        for key in data_dict:
            if key not in COL_NAMES_SIGCON:
                logging.warning('Constraint column %s does not exist in table %s' % (key, TABLE_NAME_SIG_SIGCON))
            elif data_dict[key] is not None and data_dict[key] == SIGCON_TEMPLATE[key]:
                logging.warning('Constraint column %s has still its default value %s' % (key, data_dict[key]))
                raise BaseCLDBException('Constraint column %s has still its default value %s' % (key, data_dict[key]))

        self.AddGenericData(data_dict, TABLE_NAME_SIG_SIGCON)
        ident = self.getLastRowID()
        # self.Commit()
        return ident

    def updateSigConstraint(self, consID, signalID, col, colID, beginTs, endTs, upperTol, lowerTol, coeffA, coeffB,
                            minSamples, maxSamples):
        """Add a new signal constraint record to the database.
        :param consID: which constraints ID to update
        :param col: column to use: either MeasID (CAT_FILES.MEASID) or TriggerID
        :param colID: id of column
        :param beginTS: BeginTimestamp of measurement: absolut if related to measID, relative if using triggerID
        :param endTS: EndTimestamp of measurement: length
        :param upperTol: upper value tolerance (+deviation)
        :param lowerTol: lower value tolerance (-deviation)
        :param coeffA: function coefficient A: y = Ax + B
        :param coeffB: function coefficient B: y = Ax + B
        :param minSamples: measurement samples which need to fit at minimum
        :param maxSamples: measurement samples which need to fit at maximum
        :return: True if successfull / False if failed
        """
        x = self.UpdateGenericData({COL_NAME_SIGCON_SIGNALID: signalID, col: colID, COL_NAME_SIGCON_BEGINTS: beginTs,
                                    COL_NAME_SIGCON_ENDTS: endTs, COL_NAME_SIGCON_UPPERTOL: upperTol,
                                    COL_NAME_SIGCON_LOWERTOL: lowerTol, COL_NAME_SIGCON_COEFA: coeffA,
                                    COL_NAME_SIGCON_COEFB: coeffB, COL_NAME_SIGCON_MINSAMPLES: minSamples,
                                    COL_NAME_SIGCON_MAXSAMPLES: maxSamples},
                                   SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_SIGCON)),
                                   where=SQLBinaryExpr(SQLColumnExpr(COL_NAME_SIGCON_CONSID), OP_EQ,
                                                       SQLIntegral(consID)))
        if x > 0:
            self.Commit()
        return bool(x)

    def delSigConstraint(self, consID):
        """deletes a signal constraint record from DB
        :param consID: constraint ID to be deleted,
        :return: True if successfull / False if failed
        """
        x = self.DeleteGenericData(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_SIGCON)),
                                   SQLBinaryExpr(SQLColumnExpr(COL_NAME_SIGCON_CONSID), OP_EQ,
                                                 SQLIntegral(consID)))
        if x >= 0:
            self.Commit()
        return bool(x)

    def getEmptySigConstraint(self):
        """get empty constraint template to know structure
        :return empty constraint template [dict]
        """

        return copy.deepcopy(SIGCON_TEMPLATE)

    def getSigConstraint(self, consID):
        """retrieves details from a constraint
        :param consID: constraint ID
        :return: list of details
        """
        return self.SelectGenericData(table_list=[SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_SIGCON))],
                                      where=SQLBinaryExpr(SQLColumnExpr(self.GetQualifiedTableName(
                                                          TABLE_NAME_SIG_SIGCON), COL_NAME_SIGCON_CONSID), OP_EQ,
                                                          SQLIntegral(consID)))

    def getSigContraintsPerSet(self, set_id):
        """return all constraints that belong directly to a ConstrSet (without Kids)
        :param set_id: ConstraintSet ID [int]
        :return: list with all constraints [list of dicts]
        """

        cons_maps = self.getConsMap(set_id)

        sigcons_list = []
        for cons_map in cons_maps:
            sigcons = self.getSigConstraint(cons_map[COL_NAME_CONMAP_CONSID])[0]
            sigcons_list.append(sigcons)

        return sigcons_list

    # --- Constraint Signal ---------------------------------------------------------------------------------------
    def addConsSignal(self, signal_name, derived=0, cons_state='I'):
        """add a constraint signal name
        :param signal_name: the name of signal to add
        :param derived: wether the signal is derived
        :param cons_state: initial signal state
        :return: signalID of just added set
        """
        data_dict = {COL_NAME_CONSIG_NAME: signal_name,
                     COL_NAME_CONSIG_DERIVED: derived,
                     COL_NAME_CONSIG_STATE: cons_state,
                     COL_NAME_CONSIG_MODTIME: datetime.now().isoformat(' ')}

        self.AddGenericData(data_dict, SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONSIG)))
        ident = self.getLastRowID(None, None)
        # self.Commit()

        return ident

    def updateConsSignal(self, signalID, signal_name, derived=0, cons_state='I'):
        """add a constraint signal name
        :param signalID: which signal ID to update
        :param signal_name: the name of signal to add
        :param derived: wether the signal is derived
        :param cons_state: initial signal state
        :return: True if successfull / False if failed
        """
        x = self.UpdateGenericData({COL_NAME_CONSIG_NAME: signal_name, COL_NAME_CONSIG_DERIVED: derived,
                                   COL_NAME_CONSIG_STATE: cons_state,
                                   COL_NAME_CONSIG_MODTIME: datetime.now().isoformat(' ')},
                                   SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONSIG)),
                                   where=SQLBinaryExpr(SQLColumnExpr(COL_NAME_CONSIG_SIGNALID), OP_EQ,
                                                       SQLIntegral(signalID)))
        if x > 0:
            self.Commit()
        return bool(x)

    def delConsSignal(self, signal):
        """deletes a constraint signal by name or ID
        :param sig: ID or name of signal
        :return: True if successfull / False if failed
        """
        '''
        stmt = "DELETE FROM %s WHERE " % TABLE_NAME_SIG_CONSIG
        if isinstance(signal, str):
            stmt += COL_NAME_CONSIG_NAME + " LIKE '" + signal + "'"
        else:
            stmt += COL_NAME_CONSIG_SIGNALID + " = " + str(signal)
        '''

        stp = isinstance(signal, str)
        x = self.DeleteGenericData(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONSIG)),
                                   SQLBinaryExpr(SQLColumnExpr(COL_NAME_CONSIG_NAME), OP_LIKE, SQLString(signal))
                                   if stp else SQLBinaryExpr(SQLColumnExpr(COL_NAME_CONSIG_SIGNALID), OP_EQ,
                                                             SQLIntegral(signal)))
        if x >= 0:
            self.Commit()
        return bool(x)

    def getConsSignal(self, signal, select='*'):
        """retrieves details of signal(s)
        :param signal: ID [int] or name [str] of signal
        :return: list of details
        """

        # TODO: replace creation of where_condition?
        where_condition = ''
        if isinstance(signal, str):
            where_condition += COL_NAME_CONSIG_NAME + " LIKE '" + signal + "'"
        else:
            where_condition += COL_NAME_CONSIG_SIGNALID + " = " + str(signal)

        cons_signal = self.SelectGenericData(select,
                                             table_list=[self.GetQualifiedTableName(TABLE_NAME_SIG_CONSIG)],
                                             where=where_condition)

        return cons_signal

        # --- Constraint Map ------------------------------------------------------------------------------------------
    def addConsMap(self, setID, consID):
        """adds a constraint map
        :param setID: id of constraint set
        :param consID: id of signal constraint
        :return: added mapID
        """
        data_dict = {COL_NAME_CONMAP_SETID: setID,
                     COL_NAME_CONMAP_CONSID: consID}

        self.AddGenericData(data_dict, SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONMAP)))
        ident = self.getLastRowID()
        self.Commit()
        return ident

    def updateConsMap(self, mapID, setID, consID):
        """adds a constraint map
        :param mapID: which map ID to update
        :param setID: id of constraint set
        :param consID: id of signal constraint
        :return: True if successfull / False on failure
        """
        x = self.UpdateGenericData({COL_NAME_CONMAP_SETID: setID, COL_NAME_CONMAP_CONSID: consID},
                                   SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONMAP)),
                                   where=SQLBinaryExpr(SQLColumnExpr(COL_NAME_CONMAP_MAPID), OP_EQ,
                                                       SQLIntegral(mapID)))
        if x > 0:
            self.Commit()
        return bool(x)

    def delConsMap(self, mapID):
        """deletes a constraint map by id
        :param mapID: mapID to delete
        :return: True if successfull / False on failure
        """
        x = self.DeleteGenericData(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONMAP)),
                                   SQLBinaryExpr(SQLColumnExpr(COL_NAME_CONMAP_MAPID), OP_EQ, SQLIntegral(mapID)))
        if x >= 0:
            self.Commit()
        return x

    def getConsMap(self, colID, col=COL_NAME_CONMAP_SETID, select='*'):
        """gets a list of maps
        :param col: column to search on
        :param colID: id to search for
        :return: found maps
        """
        return self.SelectGenericData(select_list=select,
                                      table_list=[SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONMAP))],
                                      where=SQLBinaryExpr(SQLColumnExpr(self.GetQualifiedTableName(
                                      TABLE_NAME_SIG_CONMAP), col), OP_EQ, SQLIntegral(colID)))

        # --- Constraint Set ------------------------------------------------------------------------------------------
    def addConstraintSet(self, set_name, operant, parent_id=None, meas_id=None, comment=None):
        """adds a new constraint set
        :param set_name: name of set
        :param operant: operant for child members
        :param parent: parent constraint set ID
        :param comment: comment of set
        :return: id of just added constraint set
        """
        data_dict = {COL_NAME_CONSET_NAME: set_name,
                     COL_NAME_CONSET_SETOP: operant,
                     COL_NAME_CONSET_PARENTID: parent_id,
                     COL_NAME_CONSET_MEASID: meas_id,
                     COL_NAME_CONSET_COMMENT: comment,
                     COL_NAME_CONSET_MODTIME: datetime.now().isoformat(' ')}

        self.AddGenericData(data_dict, SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONSET)))
        ident = self.getLastRowID()
        # self.Commit()
        return ident

    def updateConstraintSet(self, setID, set_name, operant, parentID, comment):
        """adds a new constraint set
        :param setID: set id to update
        :param set_name: name of set
        :param operant: operant for child members
        :param parent: parent constraint set ID
        :param comment: comment of set
        :return: True if successfull / False if failed
        """
        stmt = "UPDATE %s SET %s = '%s', %s = %d, " % (TABLE_NAME_SIG_CONSET, COL_NAME_CONSET_NAME, set_name,
                                                       COL_NAME_CONSET_SETOP, operant)
        stmt += "%s = %d, %s = '%s', " % (COL_NAME_CONSET_PARENTID, parentID, COL_NAME_CONSET_COMMENT, comment)
        stmt += "%s = '%s' WHERE %s = %d" % (COL_NAME_CONSET_MODTIME, datetime.now().isoformat(' '),
                                             COL_NAME_CONSET_SETID, setID)
        return self.execute(stmt) > 0

    def delConstraintSet(self, consSet):
        """deletes a constraint set by it's ID or name
        :param cons_set: name or ID of constraint set
        :return: True if successfull / False if failed
        """
        ctp = isinstance(consSet, str)
        x = self.DeleteGenericData(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONSET)),
                                   SQLBinaryExpr(SQLColumnExpr(COL_NAME_CONSET_NAME), OP_LIKE, SQLString(consSet))
                                   if ctp else SQLBinaryExpr(SQLColumnExpr(COL_NAME_CONSET_SETID), OP_EQ,
                                                             SQLIntegral(consSet)))
        if x >= 0:
            self.Commit()
        return x

    def getConstraintSet(self, consSet=None, measid=None, where=None):
        """retrieves details of a constraint set by ID or name
        :param cons_set: name or ID of constraint set
        :return: list of details
        """
        where_condition = ''
        # TODO: rework building where_condition
        if consSet is not None:
            if isinstance(consSet, int):
                where_condition = COL_NAME_CONSET_SETID + " = " + str(consSet)
            else:
                # TODO: should work as well
                # where_condition = COL_NAME_CONSET_NAME + " = '" + consSet + "'"
                where_condition = COL_NAME_CONSET_NAME + " LIKE '" + consSet + "'"

        if measid is not None:
            if len(where_condition) > 0:
                where_condition += ' AND '
            where_condition += COL_NAME_CONSET_MEASID + " = " + str(measid)

        if where is not None:
            if len(where_condition) > 0:
                where_condition += ' AND '
            where_condition += where

        cons = self.SelectGenericData(table_list=[SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONSET))],
                                      where=where_condition)

        return cons

    def getConstraintSetIDs(self):
        """return IDs of all ConstraintSets listed in database
        :return: list of constraint set ids
        """
        ids = self.execute("SELECT %s from %s" % (COL_NAME_CONSET_SETID, TABLE_NAME_SIG_CONSET))

        # convert list of lists to list = flattening lists of lists
        ids = [item for sublist in ids for item in sublist]
        return ids

        # --- Triggers ------------------------------------------------------------------------------------------------
    def addTrigger(self, signalID, parentID, value, condition, operant, usage):
        """adds a new trigger
        :param signalID: link to a name = a signal name
        :param parentID: id of parent trigger
        :param value: value of trigger
        :param condition: to trigger on
        :param operant: operant for child members
        :param usage: on what the trigger should be used for
        :return: id of just added trigger
        """
        self.AddGenericData({COL_NAME_TRIGGERS_SIGNALID: signalID, COL_NAME_TRIGGERS_PARENTID: parentID,
                            COL_NAME_TRIGGERS_OPERANT: operant, COL_NAME_TRIGGERS_VALUE: value,
                            COL_NAME_TRIGGERS_COND: condition, COL_NAME_TRIGGERS_USAGE: usage},
                            SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_TRIG)))
        #TODO: replace STMT_LAST_ROWID_SQLITE
        ident = self.SelectGenericData(select_list=[SQLBinaryExpr(SQLFuncExpr(STMT_LAST_ROWID_SQLITE), OP_AS,
                                                                  COL_NAME_LAST_ROWID)])
        self.Commit()
        return ident

    def updateTrigger(self, triggerID, signalID, parentID, value, condition, operant, usage):
        """adds a new trigger
        :param triggerID: id of trigger to update
        :param signalID: link to a name, a signal name
        :param parentID: id of parent trigger
        :param value: value of trigger
        :param condition: to trigger on
        :param operant: operant for child members
        :param usage: on what the trigger should be used for
        :return: True if successfull / False if failed
        """
        x = self.UpdateGenericData({COL_NAME_TRIGGERS_SIGNALID: signalID, COL_NAME_TRIGGERS_PARENTID: parentID,
                                    COL_NAME_TRIGGERS_VALUE: value, COL_NAME_TRIGGERS_COND: condition,
                                    COL_NAME_TRIGGERS_OPERANT: operant, COL_NAME_TRIGGERS_USAGE: usage},
                                   SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_TRIG)),
                                   where=SQLBinaryExpr(SQLColumnExpr(COL_NAME_TRIGGERS_TRIGGERID), OP_EQ,
                                                        SQLIntegral(triggerID)))
        if x > 0:
            self.Commit()
        return bool(x)

    def delTrigger(self, trigger):
        """deletes a trigger by it's ID or signal name
        :param trigger: name or ID of trigger
        :return: True if successfull / False if failed
        """
        x = 0
        if isinstance(trigger, str):
            x = self.DeleteGenericData(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_TRIG)),
                                       SQLBinaryExpr(SQLColumnExpr(COL_NAME_TRIGGERS_SIGNALID), OP_IN,
                                                     GenericSQLSelect(
                                                     select_list=[SQLColumnExpr(COL_NAME_CONSIG_SIGNALID)],
                                       table_list=[SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_CONSIG))],
                                       where_condition=SQLBinaryExpr(SQLColumnExpr(COL_NAME_CONSIG_NAME), OP_LIKE,
                                                                     SQLString(trigger)))))
        else:
            x = self.DeleteGenericData(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_TRIG)),
                                                    SQLBinaryExpr(SQLColumnExpr(TABLE_NAME_SIG_TRIG),
                                                                  OP_EQ, SQLIntegral(trigger)))

        if x >= 0:
            self.Commit()
        return x

    def getTrigger(self, trigger):
        """retrieves details of a trigger by ID or signal name
        :param trigger: name or ID of trigger
        :return: list of details
        """
        '''
        stmt = "SELECT * FROM %s WHERE " % TABLE_NAME_SIG_TRIG
        if isinstance(trigger, str):
            stmt += "%s IN (SELECT %s FROM %s WHERE %s LIKE '%s')" % (COL_NAME_TRIGGERS_SIGNALID,
                    COL_NAME_CONSIG_SIGNALID, TABLE_NAME_SIG_CONSIG, COL_NAME_CONSIG_NAME, trigger)
        else:
            stmt += "%s = %d" % (COL_NAME_TRIGGERS_TRIGGERID, trigger)
        self.execute(stmt)
        '''

        if isinstance(trigger, str):
            return self.SelectGenericData(table_list=[SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_TRIG))],
                                          where=SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(
                                          TABLE_NAME_SIG_TRIG)), COL_NAME_CONSET_SETID), OP_IN, GenericSQLSelect(
                                              select_list=[SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(
                                                  TABLE_NAME_SIG_CONSIG)), COL_NAME_CONSIG_SIGNALID)],
                                              table_list=[SQLTableExpr(self.GetQualifiedTableName(
                                                  TABLE_NAME_SIG_TRIG))], where=SQLBinaryExpr(SQLTableExpr(
                                                      self.GetQualifiedTableName(TABLE_NAME_SIG_TRIG)), OP_LIKE,
                                                      SQLString(trigger)))))
        else:
            return self.SelectGenericData(table_list=[SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_SIG_TRIG))],
                                          where=SQLBinaryExpr(SQLColumnExpr(self.GetQualifiedTableName(
                                              TABLE_NAME_SIG_TRIG), COL_NAME_TRIGGERS_TRIGGERID), OP_EQ,
                                              SQLIntegral(trigger)))

#======================================================================================================================
# Constraint DB Libary: kept for backward compatibility
#======================================================================================================================


class SQLCEBaseCLDB(BaseCLDB, SQLCEBaseDB):  # pylint: disable=R0904
    """kept for backward compatibility
    """
    def __init__(self, db_connection, table_prefix=None, sql_factory=None,  # pylint: disable-msg=W0613
                 error_tolerance=None):  # pylint: disable-msg=W0613
        """init base and specifics
        """
        BaseCLDB.__init__(self, db_connection, table_prefix)
        SQLCEBaseDB.__init__(self)


class OracleBaseCLDB(BaseCLDB, OracleBaseDB):  # pylint: disable=R0904
    """kept for backward compatibility
    """
    def __init__(self, db_connection, table_prefix=None, sql_factory=None,  # pylint: disable-msg=W0613
                 error_tolerance=None):  # pylint: disable-msg=W0613
        """init base and specifics
        """
        BaseCLDB.__init__(self, db_connection, table_prefix)
        OracleBaseDB.__init__(self)

    def getLastRowID(self, column_name=None, table_name=None):
        '''not implemented yet, try something like:
        insert into YourTable values (...)
        select scope_identity()
        alternative:
        If you are using SQL Server 2005 or later, you can use the OUTPUT clause.
        '''

        logging.warning('OracleBaseCLDB has no implementation of function getLastRowID(). ' \
                        'That might lead to an ERROR!!!')

        return None


class SQLite3BaseCLDB(BaseCLDB, SQLite3BaseDB):  # pylint: disable=R0904
    """kept for backward compatibility
    """
    def __init__(self, db_connection, table_prefix=None, sql_factory=None,  # pylint: disable-msg=W0613
                 error_tolerance=None):  # pylint: disable-msg=W0613
        """init base and specifics
        """
        BaseCLDB.__init__(self, db_connection, table_prefix)
        SQLite3BaseDB.__init__(self)

    def getLastRowID(self, column_name=None, table_name=None):
        """return last rowid by executing last_rowid function
        :param column_name, table_name: just to have same signature
        :return: autoincrement ID
        """
        id_dict = self.SelectGenericData(select_list=[SQLBinaryExpr(SQLFuncExpr(STMT_LAST_ROWID_SQLITE), OP_AS,
                                                                    COL_NAME_LAST_ROWID)])
        return id_dict[0][COL_NAME_LAST_ROWID]

"""
CHANGE LOG:
-----------
$Log: cl.py  $
Revision 1.1 2021/12/13 17:56:03CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/cl/project.pj
Revision 1.46 2013/12/10 15:28:48CET Skerl, Anne (uid19464) 
*add CL_OP_NAME_MAP for ucv._getCompareResultDetails() to get all compare results of trie
- Added comments -  uid19464 [Dec 10, 2013 3:28:49 PM CET]
Change Package : 198254:5 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.45 2013/12/09 18:45:03CET Skerl, Anne (uid19464) 
*pep8
--- Added comments ---  uid19464 [Dec 9, 2013 6:45:03 PM CET]
Change Package : 198254:6 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.44 2013/12/09 17:07:44CET Skerl, Anne (uid19464)
*bugfix at getConstraints()
*change interface of addSigConstraint() to use dict
--- Added comments ---  uid19464 [Dec 9, 2013 5:07:45 PM CET]
Change Package : 198254:6 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.43 2013/12/02 14:38:31CET Skerl, Anne (uid19464)
*update cl to return integer at getLastRowID
--- Added comments ---  uid19464 [Dec 2, 2013 2:38:32 PM CET]
Change Package : 198254:4 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.42 2013/11/29 16:41:49CET Skerl, Anne (uid19464)
*pep8
--- Added comments ---  uid19464 [Nov 29, 2013 4:41:49 PM CET]
Change Package : 198254:3 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.41 2013/11/29 14:55:07CET Skerl, Anne (uid19464)
*several bugfixes, e.g. AddGenericData does not return rowcount
*make it nicer
--- Added comments ---  uid19464 [Nov 29, 2013 2:55:07 PM CET]
Change Package : 198254:3 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.40 2013/11/26 13:34:00CET Skerl, Anne (uid19464)
*change structure of trie values
*change addConstraints: add parent_id, way to write to ConsMap, return value
*add: getSigContraintsPerSet
--- Added comments ---  uid19464 [Nov 26, 2013 1:34:00 PM CET]
Change Package : 198254:2 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.39 2013/11/21 15:39:23CET Skerl, Anne (uid19464)
*comment out some unused imports
*implement logical operations for combining constraints
*add compare result to Trie structure
*change addConstraints() to allow writing of constraints for different constraints
--- Added comments ---  uid19464 [Nov 21, 2013 3:39:24 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.38 2013/11/18 17:00:38CET Skerl, Anne (uid19464)
*add: SIGCON_DEFAULT_TRIGGER = 'Timestamp'
*change: use only measid inside cl, not recfilename
*remove: getSigConstraintDict(), not needed any more
--- Added comments ---  uid19464 [Nov 18, 2013 5:00:38 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.37 2013/11/13 18:31:06CET Skerl, Anne (uid19464)
*change: getConstraints(self, consSet) -> getConstraints(self, consSet, measid),
         getConstraintSet(self, consSet) -> getConstraintSet(self, consSet=None, measid=None, where=None)
*change: write values of Trie kids as list of dicts
--- Added comments ---  uid19464 [Nov 13, 2013 6:31:07 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.36 2013/11/11 10:52:19CET Skerl, Anne (uid19464)
*rework: addConstraints() and connected add-methods
*rework: use getLastRowID() depending on DB format
--- Added comments ---  uid19464 [Nov 11, 2013 10:52:19 AM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.35 2013/11/08 14:58:03CET Skerl, Anne (uid19464)
*bugfix: repair wrong line formats after merge
--- Added comments ---  uid19464 [Nov 8, 2013 2:58:03 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.34 2013/11/08 14:43:52CET Skerl, Anne (uid19464)
*merged with Rev. 1.23, remove plain SQL by statements from db_common.py
--- Added comments ---  uid19464 [Nov 8, 2013 2:43:53 PM CET]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.33 2013/10/25 12:33:16CEST Skerl, Anne (uid19464)
*add: constant definitions COL_NAMES_SIGCON, CL_OP_xxx
*add: SQLite3RecCatalogDB
*add: methods getSigConstraintDict, getConstraintSetIDs(self)
*change: getConsMap to use different select
--- Added comments ---  uid19464 [Oct 25, 2013 12:33:17 PM CEST]
Change Package : 198254:1 http://mks-psad:7002/im/viewissue?selection=198254
Revision 1.32 2013/07/29 12:57:38CEST Raedler, Guenther (uidt9430)
- revert changes of rev. 1.30 and 1.31
- removed unused methods
--- Added comments ---  uidt9430 [Jul 29, 2013 12:57:38 PM CEST]
Change Package : 191735:1 http://mks-psad:7002/im/viewissue?selection=191735
Revision 1.31 2013/07/04 16:10:25CEST Mertens, Sven (uidv7805)
removing unneeded methods from db_common
--- Added comments ---  uidv7805 [Jul 4, 2013 4:10:26 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.30 2013/07/04 15:01:47CEST Mertens, Sven (uidv7805)
providing tableSpace to BaseDB for what sub-schema space each module is intended to be responsible
--- Added comments ---  uidv7805 [Jul 4, 2013 3:01:47 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.29 2013/04/26 13:31:51CEST Mertens, Sven (uidv7805)
testing MKS bug
--- Added comments ---  uidv7805 [Apr 26, 2013 1:31:51 PM CEST]
Change Package : 179495:5 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.28 2013/04/26 10:46:11CEST Mertens, Sven (uidv7805)
moving strIdent
Revision 1.27 2013/04/25 15:31:37CEST Mertens, Sven (uidv7805)
_connection --> db_connection
Revision 1.26 2013/04/25 14:35:12CEST Mertens, Sven (uidv7805)
epydoc adaptation to colon instead of at
Revision 1.25 2013/04/12 14:37:05CEST Mertens, Sven (uidv7805)
adding a short representation used by db_connector.PostInitialize
--- Added comments ---  uidv7805 [Apr 12, 2013 2:37:06 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.24 2013/04/10 17:29:56CEST Mertens, Sven (uidv7805)
rewind to SQL statements, no more dependancy to db_sql
Revision 1.23 2013/04/05 11:17:40CEST Hospes, Gerd-Joachim (uidv8815)
fix documentation
--- Added comments ---  uidv8815 [Apr 5, 2013 11:17:41 AM CEST]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.22 2013/03/28 11:10:55CET Mertens, Sven (uidv7805)
pylint: last unused import removed
--- Added comments ---  uidv7805 [Mar 28, 2013 11:10:56 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.21 2013/03/27 11:37:27CET Mertens, Sven (uidv7805)
pep8 & pylint: rowalignment and error correction
Revision 1.20 2013/03/26 16:19:40CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:40 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.19 2013/03/26 13:00:21CET Mertens, Sven (uidv7805)
reverting error for keyword argument spaces
--- Added comments ---  uidv7805 [Mar 26, 2013 1:00:21 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.18 2013/03/26 11:53:20CET Mertens, Sven (uidv7805)
reworking imports on cat, cl and db_common to start testing with.
--- Added comments ---  uidv7805 [Mar 26, 2013 11:53:20 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.17 2013/03/21 17:22:40CET Mertens, Sven (uidv7805)
solving some pylint warnings / errors
Revision 1.16 2013/03/15 10:01:18CET Mertens, Sven (uidv7805)
added addConstraint method to add new constrain set with details
--- Added comments ---  uidv7805 [Mar 15, 2013 10:01:18 AM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.15 2013/03/14 11:34:21CET Mertens, Sven (uidv7805)
using new execute function instead (for testing)
--- Added comments ---  uidv7805 [Mar 14, 2013 11:34:21 AM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.14 2013/03/14 09:21:52CET Mertens, Sven (uidv7805)
adding OP_AS to next column...
--- Added comments ---  uidv7805 [Mar 14, 2013 9:21:52 AM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.13 2013/03/14 08:34:12CET Mertens, Sven (uidv7805)
trying to use as operator to distinguish column name
--- Added comments ---  uidv7805 [Mar 14, 2013 8:34:12 AM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.12 2013/03/13 16:27:55CET Mertens, Sven (uidv7805)
testing COL_NAME instead of SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME)), COL_NAME)
--- Added comments ---  uidv7805 [Mar 13, 2013 4:27:56 PM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.11 2013/03/13 15:44:00CET Mertens, Sven (uidv7805)
lower case column defines are needed, anyway.
--- Added comments ---  uidv7805 [Mar 13, 2013 3:44:00 PM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.10 2013/03/13 15:10:01CET Mertens, Sven (uidv7805)
serving keyError 'CONSID'
--- Added comments ---  uidv7805 [Mar 13, 2013 3:10:01 PM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.9 2013/03/13 13:48:01CET Mertens, Sven (uidv7805)
changes done
--- Added comments ---  uidv7805 [Mar 13, 2013 1:48:01 PM CET]
Change Package : 176171:8 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.8 2013/03/06 10:21:19CET Mertens, Sven (uidv7805)
done, pep8 styling
--- Added comments ---  uidv7805 [Mar 6, 2013 10:21:19 AM CET]
Change Package : 176171:7 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.7 2013/03/05 12:55:39CET Mertens, Sven (uidv7805)
adaptation done
--- Added comments ---  uidv7805 [Mar 5, 2013 12:55:40 PM CET]
Change Package : 176171:4 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.6 2013/03/04 07:47:22CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 4, 2013 7:47:24 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/03/01 10:29:35CET Mertens, Sven (uidv7805)
bugfixing STK imports
--- Added comments ---  uidv7805 [Mar 1, 2013 10:29:35 AM CET]
Change Package : 176171:2 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.4 2013/02/28 17:02:47CET Mertens, Sven (uidv7805)
first working version of constraint related things
--- Added comments ---  uidv7805 [Feb 28, 2013 5:02:47 PM CET]
Change Package : 176171:1 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.1 2013/02/21 12:39:43CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/db/cl/project.pj
"""
