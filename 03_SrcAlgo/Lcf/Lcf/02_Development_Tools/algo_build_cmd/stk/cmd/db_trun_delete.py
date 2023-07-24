"""
stk/cmd/db_im_export.py
-------------------

Databaes Import Export command Utility

:org:           Continental AG
:author:        Zaheer Ahmed
:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:32CET $
"""

"""
--------------------------------------------------------------------------------------
                                   MANUAL FOR USAGE
--------------------------------------------------------------------------------------
NOTE: Only DB Admin has the privilage to execute this script

The command line syntax is as follows:

-f path_to_dbs_qliteFile
-q RACADMPE -u MyDatabaseuser -p MyDatabasePassword -c MyDatabaseMasterSCHEMA
-l max_no_trun_to_delete -t testrun_name -v checkpoint -n project_name

if sqlite file path and oracle connection arguement both are passed then
sqlite database has higher precedence over oracle database

FOR specific Testrun use the following additional arguement to narrow the filter criteria
-t testrun_name -v checkpoint -n project_name

otherwise limit no. of testrun will be deleted randomly along their childs recursively

FOR limiting max no. of testrun to delete use -l it will delete the limited testrun along with child testrun
If limit arguement is not passed the default value 10 will be taken.
Following are the example values passed
-l -1 --> Delete all the deleted testrun from database
-l 20 --> Delete all the 20 deleted testrun from database along with their child testruns

"""

import platform
import os
import sys
from optparse import OptionParser
from datetime import datetime
PyLibFolder = os.path.abspath(os.path.join(os.path.split(__file__)[0], r"..\.."))
if PyLibFolder not in sys.path:
    sys.path.append(PyLibFolder)

import stk.db.db_common as dbc
from stk.db.db_connect import DBConnect
from stk.db.gbl import gbl
from stk.db.val import val
from stk.db import ERROR_TOLERANCE_NONE
from stk.db.db_sql import SQLBinaryExpr, OP_EQ

from stk.db.mdl.adas_db_def import NAME, GBL, VAL, TRUN_DATA_SETTING, \
    TABLE_NAME_RESULT_INFO, TABLE_NAME_EVENTS_INFO, TABLE_NAME_EVENT_DETAILS_INFO, \
    TABLE_NAME_EVENT_ATTR_INFO

from stk.db.val.val import COL_NAME_TR_ID, COL_NAME_RES_ID, COL_NAME_RES_RESASSID, \
    COL_NAME_EVENTS_SEID, COL_NAME_EVENTS_RESASSID, COL_NAME_EVENT_DET_EDID, COL_NAME_EVENT_IMG_ATTRID
from stk.util.logger import Logger
# Global defination of the variable

MODE_INFO = 15
MODE_DEBUG = 10
MODE = MODE_INFO
ADAS_DATABASE_MODULES = {GBL: gbl, VAL: val}


class DbTestRunDelete(object):  # pylint: disable=R0902, R0903
    """
        Db TestRun Data Delete Utility Class
    """
    def __init__(self):

        self.__dbfile = None
        self.__masterdbdsn = None
        self.__masterdbdbq = None
        self.__masterdbuser = None
        self.__masterdbpassword = None
        self.__masterdbschemaprefix = None
        self.__db_connector = None
        self.__masterdbdrv = None
        self.__trname = None
        self.__checkpoint = None
        self.__projname = None
        self.__limit = 10
        self.__trids = []
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

        if self.__dbfile is None:
            self.__db_connector = DBConnect(dbq=self.__masterdbdbq,
                                            dsn=self.__masterdbdsn,
                                            user=self.__masterdbuser,
                                            pw=self.__masterdbpassword,
                                            master=self.__masterdbschemaprefix,
                                            drv=self.__masterdbdrv,
                                            tbl_prefix=None,
                                            error_tolerance=ERROR_TOLERANCE_NONE,
                                            use_cx_oracle=True)
        else:
            self.__db_connector = DBConnect(db_file=self.__dbfile,
                                            error_tolerance=ERROR_TOLERANCE_NONE)

        for key, value in ADAS_DATABASE_MODULES.items():
            dbConnectiobObj = self.__db_connector.Connect(value)
            self.__AdasConnection[key] = dbConnectiobObj

    def __Terminate(self):
        """
        Terminating method with closing database connections
        """
        for key in ADAS_DATABASE_MODULES.keys():
            if key in self.__AdasConnection:
                self.__db_connector.DisConnect(self.__AdasConnection[key])

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
        optparser.add_option("-l", "--limit", dest="limit",
                             help="MAX no. of parent testrun deleted e.g. default:10, -1 all deleted testrun")
        optparser.add_option("-t", "--trname", dest="trname", help="Testrun to import export")
        optparser.add_option("-v", "--checkpoint", dest="checkpoint", help="Checkpoint")
        optparser.add_option("-n", "--prname", dest="prname", help="Project Name e.g. ARS400_PR")

        cmd_options = optparser.parse_args()
        self.__dbfile = cmd_options[0].dbfile
        self.__masterdbdsn = cmd_options[0].masterdbdsn
        self.__masterdbdbq = cmd_options[0].masterdbdbq
        self.__masterdbuser = cmd_options[0].masterdbuser
        self.__masterdbpassword = cmd_options[0].masterdbpassword
        self.__masterdbschemaprefix = cmd_options[0].masterdbschemaprefix
        if cmd_options[0].limit is not None:
            self.__limit = int(cmd_options[0].limit)
        self.__trname = cmd_options[0].trname
        self.__checkpoint = cmd_options[0].checkpoint
        self.__projname = cmd_options[0].prname

    def DeleteTestRunData(self):
        """
        Main function of DB Delete Testrun
        """
        start_date = datetime.now()
        self.__logger.info("Starting TestRun Delete at %s" % start_date.strftime("%d-%m-%Y %H:%M:%S"))
        self.__Initialize()
        if self.__projname is not None:
            pid = self.__AdasConnection[GBL].GetProjectId(self.__projname.upper())
        else:
            pid = None
        self.__trids = self.__AdasConnection[VAL].GetDeletedTestRunIds(name=self.__trname,
                                                                       checkpoint=self.__checkpoint,
                                                                       pid=pid, limit=self.__limit)
        for trid in reversed(self.__trids):
            self.__DeleteTestRun(trid)
        for trid in reversed(self.__trids):
            tr = self.__AdasConnection[VAL].GetTestRun(tr_id=trid)
            if COL_NAME_TR_ID in tr:
                self.__logger.error("Testrun with Id = %d delete attempt failed" % trid)
                self.__logger.error("Delete operation Aborted with no Commit Changes in Database")
                raise

        end_date = datetime.now()
        duration = end_date - start_date
        self.__AdasConnection[VAL].Commit()
        print str(tuple(self.__trids))
        self.__logger.info("Delete Finshed with Total Duration = %s "
                           % ((str(duration))))
        self.__logger.info("Total Testrun deleted = %s "
                           % (str(len(self.__trids))))
        print "exit"

    def __DeleteTestRun(self, trid):
        """
        Memory and DB Optimized Delete testrun
        :param trid: testrun id
        :type trid: int
        """
        connection = self.__AdasConnection[VAL]
        testrundata = {COL_NAME_TR_ID: [trid]}
        data = self.__SelectRecord(connection, [COL_NAME_RES_ID, COL_NAME_EVENTS_RESASSID],
                                   COL_NAME_TR_ID, trid, TABLE_NAME_RESULT_INFO)
        data = zip(*data)  # pylint: disable=W0142
        if len(data) > 0:
            testrundata[COL_NAME_RES_ID] = list(data[0])
            testrundata[COL_NAME_RES_RESASSID] = list(data[1])

        data = self.__SelectRecord(connection, [COL_NAME_EVENTS_SEID, COL_NAME_EVENTS_RESASSID],
                                   COL_NAME_TR_ID, trid, TABLE_NAME_EVENTS_INFO)
        data = zip(*data)  # pylint: disable=W0142
        if len(data) > 0:
            testrundata[COL_NAME_EVENTS_SEID] = list(data[0])
            if COL_NAME_RES_RESASSID in testrundata:
                testrundata[COL_NAME_RES_RESASSID] += list(data[1])
            else:
                testrundata[COL_NAME_RES_RESASSID] = list(data[1])

        if COL_NAME_RES_RESASSID in testrundata:
            testrundata[COL_NAME_RES_RESASSID] = list(set(testrundata[COL_NAME_RES_RESASSID]))
            if None in testrundata[COL_NAME_RES_RESASSID]:
                testrundata[COL_NAME_RES_RESASSID].remove(None)

        if COL_NAME_EVENTS_SEID in testrundata:
            testrundata[COL_NAME_EVENT_DET_EDID] = []
            testrundata[COL_NAME_EVENT_IMG_ATTRID] = []
            for seid in testrundata[COL_NAME_EVENTS_SEID]:
                edids = self.__SelectRecord(connection,
                                            [COL_NAME_EVENT_DET_EDID],
                                            COL_NAME_EVENTS_SEID, seid,
                                            TABLE_NAME_EVENT_DETAILS_INFO)[0]
                testrundata[COL_NAME_EVENT_DET_EDID] += edids
                for edid in edids:
                    testrundata[COL_NAME_EVENT_IMG_ATTRID] += self.__SelectRecord(connection,
                                                                                  [COL_NAME_EVENT_IMG_ATTRID],
                                                                                  COL_NAME_EVENT_DET_EDID, edid,
                                                                                  TABLE_NAME_EVENT_ATTR_INFO)[0]

        for tr_dataset in reversed(TRUN_DATA_SETTING):
            for key, values in tr_dataset.items():
                if key in testrundata:
                    self.__DeleteRecord(self.__AdasConnection[VAL], testrundata[key], key, values)

    def __DeleteRecord(self, connection, id_list, column_name, table_info_list):  # pylint: disable=R0201
        """
        Delete records from database if exist
        :param connection: db connection of the database
        :param id_list: list of ids to be deleted
        :type id_list: list
        :param column_name: column name of the id
        :type column_name: str
        :param table_info_list: list of table info from databaes model defination
        :type table_info: list
        """

        if len(id_list) <= 0:
            return
        values = []
        for rec in id_list:
            values.append(tuple([rec]))
        for table_info in table_info_list:
            stmt = "DELETE FROM %s " % str(connection.GetQualifiedTableName(table_info[NAME]))
            stmt += "where %s =:1" % column_name
            cursor = connection.db_connection.cursor()
            cursor.executemany(stmt, values)

    def __SelectRecord(self, connection, sel_list, column_name, rec_id, table_info):
        """
        Generic Selection function to retrieve list column values for any table
        :param connection: db connection of the database
        :type connection: Child class of BaseDB
        :param column_name: column name
        :type column_name: string
        :param table_info_list: table_info_list
        :type table_info_list:
        """
        # pylint: disable=R0201
        cond = SQLBinaryExpr(column_name, OP_EQ, rec_id)
        _, entries = connection.SelectGenericDataCompact(select_list=sel_list, table_list=
                                                         [connection.GetQualifiedTableName(table_info[NAME])],
                                                         where=cond)
        return entries

if __name__ == '__main__':
    db_trun_del = DbTestRunDelete()  # pylint: disable=C0103
    db_trun_del.DeleteTestRunData()

"""
CHANGE LOG:
-----------
$Log: db_trun_delete.py  $
Revision 1.1 2021/12/13 17:55:32CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.2 2013/12/09 13:44:29CET Ahmed, Zaheer (uidu7634) 
pep8 fix
- Added comments -  uidu7634 [Dec 9, 2013 1:44:30 PM CET]
Change Package : 210017:1 http://mks-psad:7002/im/viewissue?selection=210017
Revision 1.1 2013/12/09 11:53:54CET Ahmed-EXT, Zaheer (uidu7634)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/cmd/project.pj


"""
