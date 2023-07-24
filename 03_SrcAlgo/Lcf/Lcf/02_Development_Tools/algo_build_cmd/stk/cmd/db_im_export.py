"""
stk/cmd/db_im_export.py
-------------------

Databaes Import Export command Utility

:org:           Continental AG
:author:        Zaheer Ahmed
:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:31CET $
"""

"""
The command line syntax is as follows:
         e.g. usage with minimum param:
        -q RACADMPE -u "MyDatabaseUser"  -p MyDatabasePassword -c  "DEV_ARS4XX_ADMIN"
        -f D:\Sandboxes\STK_TESTING\04_Engineering\stk\db\sqlite_db\adas_db.sqlite
        -s oracle
        -d sqlite
        -w yes

"""
import os
import sys
import shutil
import platform
from optparse import OptionParser
from datetime import datetime

ModuleTestFolder = os.path.abspath(os.path.split(__file__)[0])
if ModuleTestFolder not in sys.path:
    sys.path.append(ModuleTestFolder)
PyLibFolder = os.path.abspath(os.path.join(os.path.split(__file__)[0], r"..\.."))
if PyLibFolder not in sys.path:
    sys.path.append(PyLibFolder)

import stk.db.db_common as dbc
from stk.db.db_connect import DBConnect
from stk.db.gbl import gbl
from stk.db.val import val
from stk.db.cat import cat
from stk.db.lbl import genlabel
from stk.db.par import par
from stk.db.obj import objdata
from stk.db import ERROR_TOLERANCE_NONE
from stk.db.db_sql import SQLBinaryExpr, OP_EQ, SQLLiteral, OP_AND, OP_IN
from stk.db.mdl.adas_db_def import PK, NAME, GBL, CAT, PAR, OBJ, LBL, VAL, COL_LIST, ADAS_DATABASE_MODULE_NAMES, \
    MODULE_TABLEINFOMAP, TABLE_NAME_FILES_INFO, TABLE_NAME_COLL_INFO, TABLE_NAME_LOCINFO_INFO, TABLE_NAME_KWMAP_INFO, \
    TABLE_NAME_COLLMAP_INFO, TABLE_NAME_VALUE_INFO, TABLE_NAME_EGO_KINEMATICS_INFO, TABLE_NAME_LABELS_INFO, \
    TABLE_NAME_RECTANGULAR_OBJECT_INFO, TABLE_NAME_ACC_LANE_REL_INFO, TABLE_NAME_KINEMATICS_INFO, \
    TABLE_NAME_ADMA_KINEMATICS_INFO, TABLE_NAME_TEST_CASES_INFO, EXCLUDE

from stk.db.val.val import TABLE_NAME_RESULT_IMAGE, TABLE_NAME_EVENT_IMAGE, COL_NAME_EVENT_IMG_IMAGE, \
    COL_NAME_RESIMG_IMAGE, COL_NAME_TR_ID, COL_NAME_TR_PARENT
from stk.db.cat.cat import COL_NAME_COLL_COLLID, COL_NAME_FILES_MEASID
from stk.db.obj.objdata import COL_NAME_RECT_OBJ_RECTOBJID
from stk.util.logger import Logger
from stk.val.testrun import TestRun
from stk.val.results import ValSaveLoadLevel
# Global defination of the variable
ORACLE = "oracle"
SQLITE = "sqlite"
SRC = "SRC"
DEST = "DEST"
MAX_PREPARED_RECORDS = 1000000
MAX_BATCH_MODE_LIMIT = 999

MODE_INFO = 15
MODE_DEBUG = 10
MODE = MODE_DEBUG

ADAS_DATABASE_MODULES = {GBL: gbl, CAT: cat, PAR: par, OBJ: objdata, LBL: genlabel, VAL: val}


class DbImportExport(object):  # pylint: disable=R0902, R0903
    """
        Db Export Utility Cclass
    """
    def __init__(self):
        self.__dbfile = None
        self.__destdbfile = None
        self.__masterdbdsn = None
        self.__masterdbdbq = None
        self.__masterdbuser = None
        self.__masterdbpassword = None
        self.__masterdbschemaprefix = None
        self.__srcdbschemaprefix = None
        self.__destdbschemaprefix = None
        self.__masterdbdrv = None
        self.__srcdb = None
        self.__destdb = None
        self.__overwrite = False
        self.__collection = None
        self.__trname = None
        self.__checkpoint = None
        self.__db_connector_ora = None
        self.__db_connector_sql = None
        self.__exclude = []
        self.__AdasConnection = {}
        self.__logger = Logger(self.__class__.__name__, level=MODE)

    def __Initialize(self):
        """
        Initialize Export process with Establishing connection and parsing argument
        """
        self.__ParseArguements()
        if platform.release() == "XP":
            self.__masterdbdrv = dbc.DEFAULT_MASTER_DRV_XP
        else:
            self.__masterdbdrv = dbc.DEFAULT_MASTER_DRV

        if not os.path.exists(os.path.join(ModuleTestFolder, r"output")):
            os.makedirs(os.path.join(ModuleTestFolder, r"output"))

        self.__destdbfile = os.path.abspath(os.path.join(ModuleTestFolder, r"output\adas_db.sqlite_out%s.sqlite" %
                                                         datetime.now().strftime("%d_%m_%Y_at_%H_%M_%S")))
        try:
            shutil.copyfile(self.__dbfile, self.__destdbfile)
        except  IOError, copy_error:
            self.__logger.error("copy error")
            self.__logger.error(copy_error)
            sys.exit()

        self.__db_connector_ora = DBConnect(dbq=self.__masterdbdbq,
                                            dsn=self.__masterdbdsn,
                                            user=self.__masterdbuser,
                                            pw=self.__masterdbpassword,
                                            master=self.__masterdbschemaprefix,
                                            drv=self.__masterdbdrv,
                                            tbl_prefix=None,
                                            error_tolerance=ERROR_TOLERANCE_NONE,
                                            use_cx_oracle=True)

        self.__db_connector_sql = DBConnect(db_file=self.__destdbfile, error_tolerance=ERROR_TOLERANCE_NONE)

        for key, value in ADAS_DATABASE_MODULES.items():
            src_dbConnectiobObj = self.__GetDbConnectionObject(self.__srcdb, value)
            dest_dbConnectiobObj = self.__GetDbConnectionObject(self.__destdb, value)

            self.__AdasConnection[key] = {SRC:  src_dbConnectiobObj,
                                          DEST: dest_dbConnectiobObj}

    def __Terminate(self):
        """
        Terminating method with closing database connections
        """
        for key in ADAS_DATABASE_MODULES.keys():

            if self.__srcdb == ORACLE and self.__destdb == SQLITE:
                self.__db_connector_ora.DisConnect(self.__AdasConnection[key][SRC])
                self.__db_connector_sql.DisConnect(self.__AdasConnection[key][DEST])
            elif self.__srcdb == SQLITE and self.__destdb == ORACLE:
                self.__db_connector_sql.DisConnect(self.__AdasConnection[key][SRC])
                self.__db_connector_ora.DisConnect(self.__AdasConnection[key][DEST])

    def __CheckDbConnections(self, src, dest):  # pylint: disable=R0201
        """
        Check the connection types for safety check to prevent accidental export in oracle
        @param src: Source databaase connection
        @type src: Oracle connection
        @param dest: desitnation databaase connection
        @type dest: sqlite connection no Oracle Type conneciton allowed for destination connection
        """
        if not (dbc.OracleBaseDB in src.__class__.__bases__ and dbc.OracleBaseDB not in dest.__class__.__bases__):
            raise StandardError("Wrong Database Connection")

    def __GetDbConnectionObject(self, conn_type, db_interface_module):
        """
        Create adas database module db connection
        @param conn_type: type of connection e.g. oracle or Sqlite
        @type conn_type: str
        @param db_interface_module: python module for Subschema of ADAS database
        @type db_interface_module: python module
        """
        if conn_type == ORACLE:
            return self.__db_connector_ora.Connect(db_interface_module)
        elif conn_type == SQLITE:
            return self.__db_connector_sql.Connect(db_interface_module)

        return None

    def __ParseArguements(self):
        """
        Parsing commandline arguements
        """
        optparser = OptionParser(usage="usage: %prog [options] command")
        optparser.add_option("-f", "--dbfile", dest="dbfile", help="The name of the Sqlite database file. ")
        optparser.add_option("-b", "--master-db-dsn", dest="masterdbdsn", help="The name of the DSN.")
        optparser.add_option("-q", "--master-db-dbq", dest="masterdbdbq", help="The name of the DBQ.")
        optparser.add_option("-u", "--master-db-user", dest="masterdbuser",
                             help="The name of the oracle database user.")
        optparser.add_option("-p", "--master-db-password", dest="masterdbpassword",
                             help="The name of the oracle database password.")
        optparser.add_option("-c", "--master-db-schema-prefix", dest="masterdbschemaprefix",
                             help="The name of the oracle database schema prefix.")
        optparser.add_option("-s", "--src-db", dest="srcdb",
                             help="The name of the source database e.g. oracle,sqlite")
        optparser.add_option("-d", "--dest-db", dest="destdb",
                             help="The name of the Destination database e.g. oracle,sqlite")

        optparser.add_option("-w", "--over-write", dest="overwite",
                             help="The name of the Destination database e.g. y/n,yes/no,True/False")
        optparser.add_option("-r", "--collection", dest="collection", help="Collection name to be import")
        optparser.add_option("-t", "--trname", dest="trname", help="Testrun to import export")
        optparser.add_option("-v", "--checkpoint", dest="checkpoint", help="Checkpoint")

        cmd_options = optparser.parse_args()

        self.__dbfile = cmd_options[0].dbfile

        self.__masterdbdsn = cmd_options[0].masterdbdsn
        self.__masterdbdbq = cmd_options[0].masterdbdbq
        self.__masterdbuser = cmd_options[0].masterdbuser

        self.__masterdbpassword = cmd_options[0].masterdbpassword
        self.__masterdbschemaprefix = cmd_options[0].masterdbschemaprefix

        self.__srcdb = cmd_options[0].srcdb
        self.__destdb = cmd_options[0].destdb
        self.__overwrite = cmd_options[0].overwite.lower()
        self.__overwrite = (self.__overwrite == "true" or
                            self.__overwrite == "yes" or
                            self.__overwrite == "y")
        self.__collection = cmd_options[0].collection
        self.__trname = cmd_options[0].trname
        self.__checkpoint = cmd_options[0].checkpoint
        db_fileprefix = ""
#        for key, value in EXCLUDE.items():
#            if key.upper() in self.__masterdbschemaprefix.upper():
#                self.__exclude = value
#                db_fileprefix = key
#                break
        if self.__dbfile is None:
            self.__dbfile = os.path.abspath(os.path.join(os.path.join(PyLibFolder, r"stk\db\sqlite_db"),
                                                         db_fileprefix.lower() + "adas_db.sqlite"))
        if self.__destdb == ORACLE:
            self.__logger.error("If you are sure to export data into Oracle DB then comment this check and run again")
            sys.exit()

    def ExportData(self):
        """
        Main function of DB Export
        """
        start_date = datetime.now()
        self.__logger.info("Starting Export at %s" % start_date.strftime("%d-%m-%Y %H:%M:%S"))
        self.__Initialize()
        if self.__collection is None and self.__trname is None:
#            Export Everything !
            self.__ExportEverything(replace=self.__overwrite)

        else:
            if self.__collection is not None:
                self.__CopyModule(self.__AdasConnection[GBL][SRC], self.__AdasConnection[GBL][DEST],
                                  MODULE_TABLEINFOMAP[GBL], self.__overwrite)
                _, measids = self.__ExportDataForCollection(self.__collection, replace=self.__overwrite)
                self.__ExportDataForParameter(measids, replace=self.__overwrite)
                self.__ExportDataForObject(measids, replace=self.__overwrite)
                self.__ExportDataForLabel(measids, replace=self.__overwrite)

            if self.__trname is not None:
                src_catdb = self.__AdasConnection[CAT][SRC]
                src_valdb = self.__AdasConnection[VAL][SRC]
                src_gbldb = self.__AdasConnection[GBL][SRC]
                dest_valdb = self.__AdasConnection[VAL][DEST]
                dest_gbldb = self.__AdasConnection[GBL][DEST]
                tr_records = src_valdb.GetTestRun(name=self.__trname, checkpoint=self.__checkpoint)
                if type(tr_records) is dict:
                    tr_records = [tr_records]
                for tr in tr_records:
                    testrun = TestRun(replace=True)
                    testrun.Load(src_valdb, src_gbldb, src_catdb, testrun_id=tr[COL_NAME_TR_ID],
                                 level=ValSaveLoadLevel.VAL_DB_LEVEL_ALL)
                    testrun.Save(dest_valdb, dest_gbldb, level=ValSaveLoadLevel.VAL_DB_LEVEL_ALL)

            self.__AdasConnection[GBL][DEST].Commit()
        self.__Terminate()
        end_date = datetime.now()
        duration = end_date - start_date
        self.__logger.info("Export Finshed with Total Duration = %s "
                           % ((str(duration))))
        print "exit"

    def __ExportDataForCollection(self, coll_name, replace=False):
        """
        Db Export specfic to Collection for CAT module
        @param coll_name: collection name
        @type coll_name: str
        @param replace: flag to replace the existing data or not
        @type replace: boolean
        """
        #        Copy Global
        src_catdb = self.__AdasConnection[CAT][SRC]
        dest_catdb = self.__AdasConnection[CAT][DEST]
        self.__CheckDbConnections(src_catdb, dest_catdb)
        par_collid = src_catdb.GetCollectionID(coll_name)

        if replace:
            init_cat_tab_infos = self.__GetModuleTableWithNoColumn(CAT, [COL_NAME_FILES_MEASID, COL_NAME_COLL_COLLID])
            self.__CopyTable(src_catdb, dest_catdb, init_cat_tab_infos, replace=replace)

        measids = list(set(src_catdb.GetCollectionMeasurements(par_collid)))
        collids = list(set([par_collid] + src_catdb.GetCollections(par_collid)))

        self.__CopyRecords(src_catdb, dest_catdb, TABLE_NAME_FILES_INFO,
                           COL_NAME_FILES_MEASID, measids, replace=replace, batch_mode=True)
        self.__CopyRecords(src_catdb, dest_catdb, TABLE_NAME_LOCINFO_INFO,
                           COL_NAME_FILES_MEASID, measids, replace=replace, batch_mode=True)
        self.__CopyRecords(src_catdb, dest_catdb, TABLE_NAME_KWMAP_INFO,
                           COL_NAME_FILES_MEASID, measids, replace=replace, batch_mode=True)

        self.__CopyRecords(src_catdb, dest_catdb, TABLE_NAME_COLL_INFO,
                           COL_NAME_COLL_COLLID, collids, replace=replace, batch_mode=True)
        self.__CopyRecords(src_catdb, dest_catdb, TABLE_NAME_COLLMAP_INFO,
                           COL_NAME_COLL_COLLID, collids, replace=replace, batch_mode=True)

        return collids, measids

    def __ExportDataForParameter(self, measids, replace=False):
        """
        Db Export specfic to measurements for PAR module
        @param measids: list of measurement ids
        @type measids: list
        @param replace: flag to replace the existing data or nor
        @type replace: boolean
        """
        src_pardb = self.__AdasConnection[PAR][SRC]
        dest_pardb = self.__AdasConnection[PAR][DEST]
        self.__CheckDbConnections(src_pardb, dest_pardb)
        if replace:
            init_par_tab_infos = self.__GetModuleTableWithNoColumn(PAR, [COL_NAME_FILES_MEASID])
            self.__CopyTable(src_pardb, dest_pardb, init_par_tab_infos, replace=replace)

        self.__CopyRecords(src_pardb, dest_pardb, TABLE_NAME_VALUE_INFO, COL_NAME_FILES_MEASID,
                           measids, replace=replace, batch_mode=True)

    def __ExportDataForObject(self, measids, replace=False):
        """
         Db Export specfic to measurements for OBJ module
        @param measids: list of measurement ids
        @type measids: list
        @param replace: flag to replace the existing data or nor
        @type replace: boolean
        """
        src_objdb = self.__AdasConnection[OBJ][SRC]
        dest_objdb = self.__AdasConnection[OBJ][DEST]
        self.__CheckDbConnections(src_objdb, dest_objdb)
        if replace:
            init_obj_tab_infos = self.__GetModuleTableWithNoColumn(OBJ, [COL_NAME_FILES_MEASID,
                                                                         COL_NAME_RECT_OBJ_RECTOBJID])
#            obj_init = [TABLE_NAME_CONFIGS, TABLE_NAME_DESCRIPTION, TABLE_NAME_CFGMAP]
            self.__CopyTable(src_objdb, dest_objdb, init_obj_tab_infos, replace=replace)
        self.__CopyRecords(src_objdb, dest_objdb, TABLE_NAME_RECTANGULAR_OBJECT_INFO,
                           COL_NAME_FILES_MEASID, measids, replace=replace, batch_mode=True)
        self.__CopyRecords(src_objdb, dest_objdb, TABLE_NAME_EGO_KINEMATICS_INFO,
                           COL_NAME_FILES_MEASID, measids, replace=replace, batch_mode=False)
        rect_objids = []
        for measid in measids:
            rect_objids += [rectobj[COL_NAME_RECT_OBJ_RECTOBJID] for rectobj in src_objdb.GetRectObjectIds(measid)]
        self.__CopyRecords(src_objdb, dest_objdb, TABLE_NAME_RECTANGULAR_OBJECT_INFO,
                           COL_NAME_RECT_OBJ_RECTOBJID, rect_objids, replace=replace, batch_mode=True)
        self.__CopyRecords(src_objdb, dest_objdb, TABLE_NAME_ACC_LANE_REL_INFO,
                           COL_NAME_RECT_OBJ_RECTOBJID, rect_objids, replace=replace, batch_mode=True)
        self.__CopyRecords(src_objdb, dest_objdb, TABLE_NAME_KINEMATICS_INFO,
                           COL_NAME_RECT_OBJ_RECTOBJID, rect_objids, replace=replace, batch_mode=False)
        self.__CopyRecords(src_objdb, dest_objdb, TABLE_NAME_ADMA_KINEMATICS_INFO,
                           COL_NAME_RECT_OBJ_RECTOBJID, rect_objids, replace=replace, batch_mode=False)
        self.__CopyRecords(src_objdb, dest_objdb, TABLE_NAME_TEST_CASES_INFO,
                           COL_NAME_RECT_OBJ_RECTOBJID, rect_objids, replace=replace, batch_mode=True)

    def __ExportDataForLabel(self, measids, replace=False):
        """
         Db Export specfic to measurements for LBL module
        @param measids: list for measurement ids
        @type measids: list
        @param replace: flag to replace the existing label data or nor
        @type replace: boolean
        """
        src_lbldb = self.__AdasConnection[LBL][SRC]
        dest_lbltdb = self.__AdasConnection[LBL][DEST]
        if replace:
            init_lbl_tab_infos = self.__GetModuleTableWithNoColumn(LBL, [COL_NAME_FILES_MEASID])
            self.__CopyTable(src_lbldb, dest_lbltdb, init_lbl_tab_infos, replace=replace)
            self.__CopyTable(src_lbldb, dest_lbltdb, init_lbl_tab_infos, replace=replace)

        self.__CopyRecords(src_lbldb, dest_lbltdb, TABLE_NAME_LABELS_INFO, COL_NAME_FILES_MEASID,
                           measids, replace=replace)

    def __ExportTestRun(self, src_db, dest_db, trid, replace=False):
        """
        Function to export testrun without using db api
        @param src_db: source database
        @type src_db: oracle db connection
        @param dest_db: destination datbase
        @type dest_db: sqlite database
        @param trid: testrun Id
        @type trid: int
        @param replace: flag to replace the existing testrun data i.e. delete previous existing testrun
        @type replace: boolean
        """
        pass

    def __CopyRecords(self, src_db, dest_db, table_info, column_name, ids, replace=False, batch_mode=False):
        """
        Copy records for list of ids from src database to destination database
        @param src_db: source database
        @type src_db: oracle db connection
        @param dest_db: destination datbase
        @type dest_db: sqlite database
        @param table_info: Table structure information from db model module
        @type table_info: dict
        @param column_name: name of the column correspoind to IDs
        @type column_name: str
        @param ids: list of id
        @type ids: list
        @param replace: flag to replace the existing reocrd or not
        @type replace: boolean
        """
        self.__CheckDbConnections(src_db, dest_db)
        total_records = []
        batch_ids = []
        cond = None
        for entry in ids:
            if batch_mode:
                if len(batch_ids) <= MAX_BATCH_MODE_LIMIT:
                    batch_ids.append(entry)
                    continue
                else:
                    cond = SQLBinaryExpr(column_name, OP_IN, str(tuple(batch_ids)))
                    batch_ids = []
                if cond is None:
                    cond = SQLBinaryExpr(column_name, OP_IN, str(tuple(batch_ids)))
                    batch_ids = []
            else:
                cond = SQLBinaryExpr(column_name, OP_EQ, entry)

            current_records = src_db.SelectGenericData(table_list=[src_db.GetQualifiedTableName(table_info[NAME])],
                                                       where=cond)
            total_records += current_records
            if replace and len(current_records) > 0:
                dest_db.DeleteGenericData(dest_db.GetQualifiedTableName(table_info[NAME]), where=cond)
            if len(total_records) > MAX_PREPARED_RECORDS or len(current_records) == 0:
                self.__AddGenericPareparedData(dest_db, total_records, table_info, del_existing_record=not replace)
                total_records = []

        if len(ids) <= MAX_BATCH_MODE_LIMIT and batch_mode:
            current_records = src_db.SelectGenericData(table_list=[src_db.GetQualifiedTableName(table_info[NAME])],
                                                       where=cond)
            total_records += current_records
            if replace and len(current_records) > 0:
                dest_db.DeleteGenericData(dest_db.GetQualifiedTableName(table_info[NAME]), where=cond)
            if len(total_records) > MAX_PREPARED_RECORDS or len(current_records) == 0:
                self.__AddGenericPareparedData(dest_db, total_records, table_info, del_existing_record=not replace)

    def __CopyRecords1(self, src_db, dest_db, table_info, column_name, ids, replace=False, batch_mode=False):
        """
        Copy records for list of ids from src database to destination database
        @param src_db: source database
        @type src_db: oracle db connection
        @param dest_db: destination datbase
        @type dest_db: sqlite database
        @param table_info: Table structure information from db model module
        @type table_info: dict
        @param column_name: name of the column correspoind to IDs
        @type column_name: str
        @param ids: list of id
        @type ids: list
        @param replace: flag to replace the existing reocrd or not
        @type replace: boolean
        """
        self.__CheckDbConnections(src_db, dest_db)
        total_records = []
        batch_ids = []
        cond = None
        for entry in ids:
            if batch_mode:
                if len(batch_ids) <= MAX_BATCH_MODE_LIMIT:
                    batch_ids.append(entry)
                    continue
                else:
                    cond = SQLBinaryExpr(column_name, OP_IN, str(tuple(batch_ids)))
                    batch_ids = []
                if cond is None:
                    cond = SQLBinaryExpr(column_name, OP_IN, str(tuple(batch_ids)))
                    batch_ids = []
            else:
                cond = SQLBinaryExpr(column_name, OP_EQ, entry)

            current_records = src_db.SelectGenericData(table_list=[src_db.GetQualifiedTableName(table_info[NAME])],
                                                       where=cond)
            total_records += current_records
            if replace and len(current_records) > 0:
                dest_db.DeleteGenericData(dest_db.GetQualifiedTableName(table_info[NAME]), where=cond)
            if len(total_records) > MAX_PREPARED_RECORDS or len(current_records) == 0:
                self.__AddGenericPareparedData(dest_db, total_records, table_info, del_existing_record=not replace)
                total_records = []

        if len(ids) <= MAX_BATCH_MODE_LIMIT and batch_mode:
            current_records = src_db.SelectGenericData(table_list=[src_db.GetQualifiedTableName(table_info[NAME])],
                                                       where=cond)
            total_records += current_records
            if replace and len(current_records) > 0:
                dest_db.DeleteGenericData(dest_db.GetQualifiedTableName(table_info[NAME]), where=cond)
            if len(total_records) > MAX_PREPARED_RECORDS or len(current_records) == 0:
                self.__AddGenericPareparedData(dest_db, total_records, table_info, del_existing_record=not replace)

    def __AddGenericPareparedData(self, dest_conn, records, table_info, del_existing_record=False):
        """
        Add Generic function using prepared statement to insert record in bulk
        @param dest_conn: destination datbase
        @type dest_conn: sqlite database
        @param records: list of record
        @type records: list
        @param table_info: table info from adase_db_def model
        @type table_info: dict
        @param del_existing_record: flag to delete existing record
        @type del_existing_record: boolean
        """
        if len(records) > 0:
            col_list = records[0].keys()
            if len(col_list) > 0:
                stmt = 'INSERT INTO %s (' % str(dest_conn.GetQualifiedTableName(table_info[NAME]))
                vals = " VALUES("
                for i in range(len(col_list)):
                    stmt += " %s," % col_list[i]
                    vals += " :%s," % str(i + 1)
                stmt = stmt[:-1] + " )"
                vals = vals[:-1] + " )"
                stmt = stmt + vals
                values = []
                for record in records:
                    if del_existing_record:
                        self.__DeleteExistingRecord(dest_conn, record, table_info)

                    if table_info[NAME].lower() == TABLE_NAME_RESULT_IMAGE.lower():
                        record[COL_NAME_RESIMG_IMAGE] = buffer(record[COL_NAME_RESIMG_IMAGE].read())
#                        dest_conn.AddResultImage(record)
                    elif table_info[NAME].lower() == TABLE_NAME_EVENT_IMAGE.lower():
                        record[COL_NAME_EVENT_IMG_IMAGE] = buffer(record[COL_NAME_EVENT_IMG_IMAGE].read())
#                        dest_conn.AddEventImage(record)
                    values.append(tuple(record.values()))
                if len(values) > 0:
                    dest_cursor = dest_conn.db_connection.cursor()
                    try:
                        dest_cursor.executemany(stmt, values)
                    except Exception, stm_exec_error:
                        self.__logger.error(stmt)
                        self.__logger.error(stm_exec_error)
                        raise
                    finally:
                        dest_cursor.close()

    def __ExportEverything(self, replace=False):
        """
        Export whole db schema instead of specific collection or testrun
        @param replace: flag to replace existing record in the the destination database
        @type replace: boolean
        """
        for mod_name in ADAS_DATABASE_MODULE_NAMES:
            if MODULE_TABLEINFOMAP[mod_name] is not None:
#                self.__DeleteModuleTablesRecord(self.__AdasConnection[mod_name][DEST], MODULE_TABLEINFOMAP[mod_name])
                self.__CopyModule(self.__AdasConnection[mod_name][SRC], self.__AdasConnection[mod_name][DEST],
                                  MODULE_TABLEINFOMAP[mod_name], replace=replace)

    def __CopyModule(self, src_connection, dest_connection, table_infolist, replace=False):
        """
        Copy Database modules (e.g. cat val gbl subschemas)
        @param src_connection: db connection object of the source database
        @type src_connection: dbc.OracleBaseDB
        @param dest_connection: db connection of the desitnation database
        @type dest_connection: dbc.SQLite3BaseDB
        @param table_infolist: list of schema info from adase_db_def model defination
        @type table_infolist: list
        @param replace: flag to replace existing record in database
        @type replace: boolean
        """
        self.__CheckDbConnections(src_connection, dest_connection)
        for table_info in table_infolist:
            self.__logger.info("Copying... %s" % table_info[NAME])
            self.__CopyTable(src_connection, dest_connection, [table_info], replace=replace)
            self.__logger.info(" Copy Done...")
        self.__AdasConnection[GBL][DEST].Commit()

    def __CopyTable(self, src_connection, dest_connection, table_infolist, replace=False):  # pylint: disable=R0912
        """
        Copy whole table records from source to destination database
        @param src_connection: db connection object of the source database
        @type src_connection: dbc.OracleBaseDB
        @param dest_connection: db connection of the desitnation database
        @type dest_connection: dbc.SQLite3BaseDB
        @param table_infolist: list of schema info from adase_db_def model defination
        @type table_infolist: list
        @param replace: flag to replace existing record in database
        @type replace: boolean
        """
        self.__CheckDbConnections(src_connection, dest_connection)
        for table_info in table_infolist:
            if replace:
                self.__logger.debug("All record for ... %s will be replace" % table_info[NAME])
                dest_connection.DeleteGenericData(dest_connection.GetQualifiedTableName(table_info[NAME]))
            if "ARCHIVE".lower() in table_info[NAME].lower():
                continue
            if table_info[NAME] in self.__exclude:
                continue
            src_cursor = src_connection.db_connection.cursor()
            stmt = "Select * from %s" % src_connection.GetQualifiedTableName(table_info[NAME])
            try:
                src_cursor.execute(stmt)
                while(True):
                    if table_info[NAME] in [TABLE_NAME_RESULT_IMAGE, TABLE_NAME_EVENT_IMAGE]:
                        rows = [src_cursor.fetchone()]

                    else:
                        rows = src_cursor.fetchmany(MAX_PREPARED_RECORDS)
                    record_list = []
                    if len(rows) > 0 and rows[0] is not None:
                        for row in rows:
                            colindex = 0
                            columns = {}
                            for column in src_cursor.description:
                                columns[column[0].upper()] = row[colindex]
                                colindex = colindex + 1
                            record_list.append(columns)
                        self.__AddGenericPareparedData(dest_connection, record_list, table_info,
                                                       del_existing_record=not replace)
                    else:
                        break
#                    break  # for test
            except Exception, src_stmt_exec:
                self.__logger.error(stmt)
                self.__logger.error(src_stmt_exec)
                raise
            finally:
                src_cursor.close()

#    def __CopyTable(self, src_connection, dest_connection, table_infolist, replace=False):
#        self.__CheckDbConnections(src_connection, dest_connection)
#        for table_info in table_infolist:
#            if replace:
#                self.__logger.debug("All record for ... %s will be replace" % table_info[NAME])
#                dest_connection.DeleteGenericData(dest_connection.GetQualifiedTableName(table_info[NAME]))
#
#            if "ARCHIVE".lower() in table_info[NAME].lower():
#                continue
#            src_cursor = src_connection.db_connection.cursor()
#            dest_cursor = dest_connection.db_connection.cursor()
#            stmt = "Select * from %s" % src_connection.GetQualifiedTableName(table_info[NAME])
#            try:
#                src_cursor.execute(stmt)
#    #            rows = src_cursor.fetchall()
#                while(True):
#                    row = src_cursor.fetchone()
#                    if row == None:
#                        break
#                    else:
#                        colindex = 0
#                        columns = {}
#                        for column in src_cursor.description:
#                            columns[ column[ 0 ].upper() ] = row[ colindex ]
#                            colindex = colindex + 1
#                        record = columns
#                        if not replace:
#                            self.__DeleteExistingRecord(dest_connection, record, table_info)
#                        if table_info[NAME].lower() == TABLE_NAME_RESULT_IMAGE.lower():
#                            record[COL_NAME_RESIMG_IMAGE] = buffer(record[COL_NAME_RESIMG_IMAGE])
#                            self.__AdasConnection[VAL][DEST].AddResultImage(record)
#                        elif table_info[NAME].lower() == TABLE_NAME_EVENT_IMAGE.lower():
#                            record[COL_NAME_EVENT_IMG_IMAGE] = buffer(record[COL_NAME_EVENT_IMG_IMAGE])
#                            self.__AdasConnection[VAL][DEST].AddEventImage(record)
#                        else:
#                            dest_connection.AddGenericData(record,
#                                                           dest_connection.GetQualifiedTableName(table_info[NAME]))
#            except Exception, e:
#                print stmt
#                print e
#                raise
#            finally:
#                src_cursor.close()
#                dest_cursor.close()

    def __GetModuleTableWithNoColumn(self, module_name, col_list):  # pylint: disable=R0201
        """
        Get the list of tables which doesnt contain the columns specified in col_list
        @param module_name: subschema name e.g. CAT VAL GBL
        @type module_name: str
        @param col_list: list of column name
        @type col_list: list
        """
        init_tables_infolist = []
        if MODULE_TABLEINFOMAP[module_name] is not None:
            for table_info in MODULE_TABLEINFOMAP[module_name]:
                found = False
                for column_name in col_list:
                    if column_name in table_info[COL_LIST]:
                        found = True
                        break
                if not found:
                    init_tables_infolist.append(table_info)

        return init_tables_infolist

    def __DeleteModuleTablesRecord(self, dest_connection, table_infolist):  # pylint: disable=R0201
        """
        Clean all the record from tables from destination database
        @param dest_connection: db connection of the desitnation database
        @type dest_connection: dbc.SQLite3BaseDB
        @param table_infolist: list of schema info from adase_db_def model defination
        @type table_infolist: list
        """
        for table_info in table_infolist:
            dest_cursor = dest_connection.db_connection.cursor()
            stmt = "Delete from %s" % dest_connection.GetQualifiedTableName(table_info[NAME])
            try:
                dest_cursor.execute(stmt)
            except Exception, del_exec:
                print stmt
                print del_exec
                raise
            finally:
                dest_cursor.close()

    def __DeleteExistingRecord(self, dest_connection, record, table_info):  # pylint: disable=R0201
        """
        Delete the record in the destination database if exist
        @param dest_connection: db connection of the desitnation database
        @type dest_connection: dbc.SQLite3BaseDB
        @param record: record in dictionary to be delete
        @type record: dict
        @param table_info: table information from db model defination
        @type table_info: dict
        """
        condition = None
        if len(table_info[PK] > 0):
            for pk_col in table_info[PK]:
                if condition is not None:
                    condition = SQLBinaryExpr(condition, OP_AND,
                                              SQLBinaryExpr(pk_col, OP_EQ, SQLLiteral(record[pk_col])))
                else:
                    condition = SQLBinaryExpr(pk_col, OP_EQ, SQLLiteral(record[pk_col]))
        else:
            for col_name, value in record.iteritems():
                if col_name not in [COL_NAME_RESIMG_IMAGE, COL_NAME_EVENT_IMG_IMAGE]:
                    if condition is not None:
                        condition = SQLBinaryExpr(condition, OP_AND, SQLBinaryExpr(col_name, OP_EQ, SQLLiteral(value)))
                    else:
                        condition = SQLBinaryExpr(col_name, OP_EQ, SQLLiteral(value))
        if len(dest_connection.SelectGenericData(table_list=[dest_connection.GetQualifiedTableName(table_info[NAME])],
                                                 where=condition) > 0):
            return dest_connection.DeleteGenericData(table_info[NAME], condition)
        else:
            return 0

if __name__ == '__main__':

    db_imp_exp = DbImportExport()  # pylint: disable=C0103
    db_imp_exp.ExportData()

"""
CHANGE LOG:
-----------
$Log: db_im_export.py  $
Revision 1.1 2021/12/13 17:55:31CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.1 2013/11/18 10:27:33CET Ahmed, Zaheer (uidu7634) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/cmd/project.pj

"""
