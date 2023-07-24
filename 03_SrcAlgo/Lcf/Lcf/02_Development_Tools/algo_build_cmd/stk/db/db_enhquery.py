"""
db_enhquery.py
-------------------------

Class for interfaceing with the database.

:org:           Continental AG
:author:        Christoph Castell

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:48CET $
"""

# pylint: disable=C0103

# Imports
#====================================================================
import os
from sys import _getframe
# import sys
# import copy
import time
import datetime
# import string
# import numpy
# import xml.dom.minidom
# import odbc
#====================================================================
# Local Imports
#====================================================================
import stk.util.logger as Logger
import stk.db.db_sql as stk_sql
import stk.db.db_connect as val_db
from stk.db.db_common import ERROR_TOLERANCE_MED, ERROR_TOLERANCE_NONE

import stk.mts.bpl as bpl

import stk.rep.report_base as rep
import stk.db.gbl.gbl as dbgbl
import stk.db.fct.fct as dbfct
import stk.db.lbl.genlabel as dblbl
import stk.db.cat.cat as dbcat
import stk.db.val.val as dbval
import stk.db.obj.objdata as dbobj
import stk.val.asmt as val_asmt
from stk.val.filter import ValEventFilter
import stk.val.results as val_results
import stk.val.testrun as val_testrun
import stk.db.lbl as stk_lbl
import stk.db.gbl.gbl_defs as gbl_defs

RDTYPE_DEFS = stk_lbl.RoadType()
GBL_DEFS = gbl_defs.GblUnits()

# Database modules
DBACC = "dbacc"
DBCAT = "dbcat"
DBOBJ = "dbobj"
DBENV = "dbenv"
DBGBL = "dbgbl"
DBFCT = "dbfct"
DBVAL = "dbval"
DBLBL = "dblbl"
DBPAR = "dbpar"

# Definitions used in the queries
CAT_REC_GLOBAL_LABEL_ABSTS = -1

ACC_PLOT_DAT_FILE = "plot_dat_file"
ACC_VIDEO_SEQ_FILE = "video_seq_file"
ROAD_EVENT_IMAGE = "clothoideventimage"

# Cycle times.
CYCLE_TIME_SHORT_MS = 56.0
CYCLE_TIME_LONG_MS = 76.0

# Other defines
THOUSAND = 1000.0
MILLION = 1000000.0

#====================================================================
# Database data class
#====================================================================


class DbData():
    """ Manages requirements data. """
    # pylint: disable=R0902, R0904
    def __init__(self):
        """ Class initialisation. """
        # Initialize Variables.
        self.__DataBaseObjects = []
        self.__DataBaseObjectConnections = []
        self.__DatabaseObjectConnectionsDict = {}
        self.__db_connector = None
        self.__table_name_list = []
        self.__table_name_idx = 0
        self.__column_name_list = []
        self.__column_name = 0
        self.table_data = None
        self.fields = None
        self.data = None
        self.num_columns = 0
        self.num_rows = 0
        self.__logger = Logger.Logger(self.__class__.__name__)
        self.__asmt = None
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        self.__db = {}

    def CreateConnectionObjects(self, connection, db=None):
        """ Creates the DB connection object
        """
        if db is None:

            self.__db_connector = val_db.DBConnect(user=connection["user"],
                                                   pw=connection["pw"],
                                                   master=connection["schema_prefix"],
                                                   # drv=connection["schema_prefix"],
                                                   dsn=connection["dsn"],
                                                   dbq=connection["dbq"],
                                                   error_tolerance=ERROR_TOLERANCE_MED)
        else:
            self.__db_connector = val_db.DBConnect(db_file=connection["name_path"],
                                                   error_tolerance=ERROR_TOLERANCE_NONE)
        self.__db = self.__db_connector

    def AddCollection(self, collection_name, parent_id=None, comment=None):
        """ Add a collection to the CAT_Collections table.
        @param collection_name: The name of the collection.
        @param parent_id: The collection id of the parent. Not required.
        @param comment: An information comment. Not required.
        @return: Returns the collection id or RET_VAL_ERROR.
        """
        collection_record = {}
        collection_record[dbcat.COL_NAME_COLL_NAME] = collection_name
        collection_record[dbcat.COL_NAME_COLL_PARENTID] = parent_id
        collection_record[dbcat.COL_NAME_COLL_COLLCOMMENT] = comment

        self.__db[DBCAT].AddCollection(collection_record)
        self.__db[DBCAT].Commit()

    def AddCollectionMapEntries(self, coll_name, bpl_file_path):
        """ Add a collection map entry. Skip if the COLLID/MEASID/BEGINRELTS combination is in the database.
        The collection map entry consists of one entry, or many entries, if sections are present.
        @param coll_name: The collection name.
        @param bpl_file_path: The bpl file path.
        @return: The COLLMAPID list.
        """
        bpl_data = bpl.Bpl(bpl_file_path)

        bpl_list = bpl_data.read()

        collmapid_list = []

        coll_map_record = {}
        coll_map_record[dbcat.COL_NAME_COLLMAP_COLLID] = self.__db[DBCAT].GetCollectionID(coll_name)
        coll_map_record[dbcat.COL_NAME_COLLMAP_MEASID] = None
        coll_map_record[dbcat.COL_NAME_COLLMAP_ASGNDATE] = self.__db[DBCAT].ConvertTimestampToDate(time.time())
        coll_map_record[dbcat.COL_NAME_COLLMAP_ASGNBY] = os.environ["USERNAME"]
        coll_map_record[dbcat.COL_NAME_COLLMAP_BEGINTIMESTAMP] = None
        coll_map_record[dbcat.COL_NAME_COLLMAP_ENDTIMESTAMP] = None

        for bpl_list_entry in bpl_list:
            measid = self.__db[DBCAT].GetMeasurementID(bpl_list_entry.filepath)
            coll_map_record[dbcat.COL_NAME_COLLMAP_MEASID] = measid

            collmapid = self.__db[DBCAT].AddCollectionMap(coll_map_record)
            self.__db[DBCAT].Commit()
            collmapid_list.append(collmapid)

            for section in bpl_list_entry.sectionlist:
                coll_map_record[dbcat.COL_NAME_COLLMAP_BEGINTIMESTAMP] = section.startTS
                coll_map_record[dbcat.COL_NAME_COLLMAP_ENDTIMESTAMP] = section.endTS
                collmapid = self.__db[DBCAT].AddCollectionMap(coll_map_record)
                self.__db[DBCAT].Commit()
                collmapid_list.append(collmapid)
        return collmapid_list

    def AddCollectionMapEntry(self, coll_name, measid):
        """ Add a collection map entry based on the measid.
        @param coll_name: The collection name.
        @param measid: The measurement id.
        @return: The collection map id.
        """
        coll_map_record = {}
        coll_map_record[dbcat.COL_NAME_COLLMAP_COLLID] = self.__db[DBCAT].GetCollectionID(coll_name)
        coll_map_record[dbcat.COL_NAME_COLLMAP_MEASID] = float(measid)
        coll_map_record[dbcat.COL_NAME_COLLMAP_ASGNDATE] = self.__db[DBCAT].ConvertTimestampToDate(time.time())
        coll_map_record[dbcat.COL_NAME_COLLMAP_ASGNBY] = os.environ["USERNAME"]
        coll_map_record[dbcat.COL_NAME_COLLMAP_BEGINTIMESTAMP] = None
        coll_map_record[dbcat.COL_NAME_COLLMAP_ENDTIMESTAMP] = None

        collmapid = self.__db[DBCAT].AddCollectionMap(coll_map_record)
        self.__db[DBCAT].Commit()

        return collmapid

    def CloseConnection(self):
        """ Close all the database connections. """
        # self.__db_connector.CloseConnections()
        for dbConnection in self.__DataBaseObjectConnections:
            if dbConnection is not None:
                dbConnection.Terminate()
            else:
                self.__logger.error("data base connection not established for %s" %
                                    dbConnection.LocDataBaseObject.__name__)
        self.__DataBaseObjectConnections = []
        return 0

    def GetDatabaseConnection(self, connection_dict):  # pylint: disable=W0613
        """ Get a connection to the database.
        @param connection_dict: The info to open the database connection.
        @return: True on connection.
        """

        self.__DataBaseObjects = []
        self.__DataBaseObjects.append(dbcat)
        self.__DataBaseObjects.append(dbobj)
        self.__DataBaseObjects.append(dbgbl)
        self.__DataBaseObjects.append(dbfct)
        self.__DataBaseObjects.append(dbval)
        self.__DataBaseObjects.append(dblbl)

        # Establish data base connection to all requested data base objects.
        for LocDataBaseObject in self.__DataBaseObjects:
            dbConnection = self.__db_connector.Connect(LocDataBaseObject)
            if dbConnection is not None:
                self.__DataBaseObjectConnections.append(dbConnection)
            else:
                self.__logger.error("Data base connection not established for %s." % LocDataBaseObject.__name__)

        # Set all the connection information in the connector. Only path for SQLite.
        self.__DatabaseObjectConnectionsDict = {}
        for ConnectionObject in self.__DataBaseObjectConnections:
            if isinstance(ConnectionObject, dbcat.BaseRecCatalogDB):
                self.__DatabaseObjectConnectionsDict[DBCAT] = ConnectionObject
                continue
            if isinstance(ConnectionObject, dbobj.BaseObjDataDB):
                self.__DatabaseObjectConnectionsDict[DBOBJ] = ConnectionObject
                continue
            if isinstance(ConnectionObject, dbgbl.BaseGblDB):
                self.__DatabaseObjectConnectionsDict[DBGBL] = ConnectionObject
                continue
            if isinstance(ConnectionObject, dbfct.BaseFctDB):
                self.__DatabaseObjectConnectionsDict[DBFCT] = ConnectionObject
                continue
            if isinstance(ConnectionObject, dbval.BaseValResDB):
                self.__DatabaseObjectConnectionsDict[DBVAL] = ConnectionObject
                continue
            if isinstance(ConnectionObject, dblbl.BaseGenLabelDB):
                self.__DatabaseObjectConnectionsDict[DBLBL] = ConnectionObject
                continue

        self.__db = self.__DatabaseObjectConnectionsDict

        if self.__db is not None:
            # Set the table_name_list.
            self.__table_name_list = self.__db[DBGBL].GetTableNames()
            return True, self.__db
        else:
            return False, self.__db

    def GetAllProjects(self):
        """ Gets all the project names
        """
        return self.__db[DBGBL].GetAllProjectName()

    def GetProjectId(self, proj):
        """ Gets the project id for the project name
        """
        return self.__db[DBGBL].GetProjectId(proj)

    def LoadFilter(self, filter_file, trid=None):
        """ Load Filter using the Filter class from API
        --- interface needed since the database object is used ---
        :param filter_file: the complete path of the filter xml file
        :param trid: the testrun id
        :return filter_names: list of stringscontaining the filter names from xml file
        :return filter_statements: list of sql statements for each of the filter_names
        """

        filter_names = []
        filter_statements = []

        event_filter = ValEventFilter(filter_file, trid)
        if event_filter.Load(self.__db[DBVAL]):
            filter_names = event_filter.GetFilterMapNames()
            for filter_map_name in filter_names:
                filter_statements.append(event_filter.GetFilterMapSqlExpression(filter_map_name))

        return filter_names, filter_statements

    def DeleteCollection(self, collection_name):
        """ Delete a collection. Only works on collections without children and measurements.
        @param collection_name: The name of the collection.
        @return: success, message
        """
        success, message = self.__db[DBCAT].DeleteCollection(collection_name)
        if success:
            self.__db[DBCAT].Commit()

        return success, message

    def DeleteCollectionMapEntry(self, measid, collection_name):
        """ Remove a specific measurement from a collection. Only works on actual members. Not on parent collections.
        @param measid: The measid of the measurement.
        @param collection_name: The name of the collection.
        """
        self.__db[DBCAT].DeleteCollectionMap(measid, collection_name)
        self.__db[DBCAT].Commit()

    def GetCollection(self, collection_id):
        """ Get the collection database entry, given the collection id.
        @param collection_id: The collection id.
        """
        return self.__db[DBCAT].GetCollection(collection_id)

    def GetCollectionNames(self):
        """ Get a list of collection names.
        @return: Collection name list (sorted).
        """
        collections_list = []
        table_data = self.__db[DBGBL].GetTableData(dbcat.TABLE_NAME_COLL,
                                                   [dbcat.COL_NAME_COLL_NAME])

        collections = table_data[1]
        for collection in collections:
            collections_list.append(collection[0])

        collections_list.sort()
        return collections_list

    def GetCollections(self):
        """ Get a list of collections sorted by name.
        @return: Collection list.
        """
        table_data = self.__db[DBGBL].GetTableData(dbcat.TABLE_NAME_COLL,
                                                   [dbcat.COL_NAME_COLL_COLLID,
                                                    dbcat.COL_NAME_COLL_NAME,
                                                    dbcat.COL_NAME_COLL_PARENTID,
                                                    dbcat.COL_NAME_COLL_COLLCOMMENT])
        # Just get the collections data without the headers.
        collections = table_data[1]

        # Sort the collection data based on name.
        sorted_collections = sorted(collections, key=lambda collection: collection[1])

        return sorted_collections

    def GetCollectionPathsSections(self, collection_name):
        """ Get the collection data from the database.
        @param collection_name: The name of the collection.
        @return: The collection in the followig format. [filepath,[(start_time, end_time)]]
        """
        collid = self.__db[DBCAT].GetCollectionID(collection_name)
        meas_ids = self.__db[DBCAT].GetCollectionMeasurements(collid, recurse=True, recfile_paths=False)
        measurements = self.GetMeasurementsPathsSections(meas_ids, collid)

        return measurements

    def GetMeasurementsPathsSections(self, measid_list, collid):
        """ Get the file path and section data for a list of measurements.
        @param measid_list: A list of measids.
        @param collid: The collection id.
        @return: [filepath,[(start_time, end_time)]]
        """
        measurements = []

        for meas_id in measid_list:
            meas_dict, sections = self.__db[DBCAT].GetMeasurementWithSections(meas_id, collid)
            # Put together a collection here with the right format.
            measurement = meas_dict[dbcat.COL_NAME_FILES_FILEPATH], sections
            measurements.append(measurement)

        return measurements

    def GetCollectionNameFromId(self, collection_id):
        """ Get the collection name from the collection id.
        @param collection_id: The id of the collection to find.
        @return: Collection name.
        """
        collection_name = str(self.__db[DBCAT].GetCollectionName(collection_id))
        ret = str.rsplit(collection_name, "/", 1)
        if len(ret) > 1:
            return ret[1]
        else:
            return ret[0]

    def GetCollectionIdFromName(self, collection_name):
        """ Get the collection id from the collection name.
        @param collection_id: The name of the collection to find.
        @return: The collection id.
        """
        return self.__db[DBCAT].GetCollectionID(collection_name)

    def GetCollectionFileData(self, collection_name):
        """ Get collection file data from the database.
        @param collection_name: The name of the collection to query.
        @return: (num_rows, num_columns, field_list, data_list)
        """
        collid = self.__db[DBCAT].GetCollectionID(collection_name)
        meas_ids = self.__db[DBCAT].GetCollectionMeasurements(collid, recurse=True, recfile_paths=False)
        tbl_files = self.__db[DBCAT].GetQualifiedTableName(dbcat.TABLE_NAME_FILES)
        data_list = []
        field_list = []
        temp_list = []
        if len(meas_ids) != 0:
            if len(meas_ids) >= 1000:
                for iters in xrange(len(meas_ids) / 1000):
                    query = ','.join(str(n) for n in meas_ids[iters * 1000: (iters + 1) * 1000])
                    cond = stk_sql.SQLBinaryExpr(dbcat.COL_NAME_FILES_MEASID, stk_sql.OP_IN, "%s" % "(" + query + ")")
                    field_list, temp_list = self.__db[DBCAT].SelectGenericDataCompact(["*"], [tbl_files], cond)
                    data_list += temp_list

                if len(meas_ids) % 1000 != 0:
                    # pylint: disable=W0631
                    query = ','.join(str(n) for n in meas_ids[(iters + 1) * 1000: len(meas_ids)])
                    cond = stk_sql.SQLBinaryExpr(dbcat.COL_NAME_FILES_MEASID, stk_sql.OP_IN, "%s" % "(" + query + ")")
                    field_list, temp_list = self.__db[DBCAT].SelectGenericDataCompact(["*"], [tbl_files], cond)
                    data_list += temp_list
            else:
                query = ','.join(str(n) for n in meas_ids)
                cond = stk_sql.SQLBinaryExpr(dbcat.COL_NAME_FILES_MEASID, stk_sql.OP_IN, "%s" % "(" + query + ")")
                field_list, data_list = self.__db[DBCAT].SelectGenericDataCompact(["*"], [tbl_files], cond)
        num_columns = len(field_list)
        num_rows = len(data_list)

        return (num_rows, num_columns, field_list, data_list)

    def GetCollectionHoursKilometerPerSoftwareVersion(self, collection_name):
        """ Get hours and kilometer per software version.
        @param collection_name: The collection name.
        @return: Array of tuples (software version, hours, files, kilometer).
        """
        hours_per_software_version = self.__db[DBCAT]. \
            GetCollectionHoursKilometerForPartConfigVersion(collection_name, dbcat.COL_NAME_PARTCFGS_SWVERSION)
        return hours_per_software_version

    def GetCollectionHoursKilometerPerHardwareVersion(self, collection_name):
        """ Get hours and kilometer per Hardware version.
        @param collection_name: The collection name.
        @return: Array of tuples (hardware version, hours, files, kilometer).
        """
        hours_per_hardware_version = self.__db[DBCAT]. \
            GetCollectionHoursKilometerForPartConfigVersion(collection_name, dbcat.COL_NAME_PARTCFGS_HWVERSION)
        return hours_per_hardware_version

    def GetCollectionHoursPerRoadtype(self, collection_name):
        """ Get hours per Roadtype Label type.
        @param collection_name: The collection name.
        @return: progress, Array of tuples (label_type, label_state, hours, files).
        """
        # pylint: disable=R0912, R0914, R0915
        progress = 0L
        roadtype_hours_files_list = []
        roadtype_hours_files = []
        # Getting the collection ID from the collection name
        collection_id = self.__db[DBCAT].GetCollectionID(collection_name)
        # Getting the measid's for the collection (also subcollections)
        coll_measid_list = self.__db[DBCAT].GetCollectionMeasurements(collection_id, True, False)
        if len(coll_measid_list) == 0:
            return progress, roadtype_hours_files_list

        # get the typeid for "roadtype"
        road_type_id = self.GetRoadTypeLabelID()
        if road_type_id != -1:
            entries = []
            entry_dict = []

            for measid in coll_measid_list:
                condition1 = stk_sql.SQLBinaryExpr(dblbl.COL_NAME_LABELS_MEASID, stk_sql.OP_EQ, measid)
                condition2 = stk_sql.SQLBinaryExpr(dblbl.COL_NAME_LABELS_TYPEID, stk_sql.OP_EQ, road_type_id)
                condition = stk_sql.SQLBinaryExpr(condition1, stk_sql.OP_AND, condition2)
                order_by_list = [dblbl.COL_NAME_LABELS_MEASID, dblbl.COL_NAME_LABELS_ABSTS]
                sel_list = [dblbl.COL_NAME_LABELS_MEASID, dblbl.COL_NAME_LABELS_ABSTS, dblbl.COL_NAME_LABELS_STATEID]
                tab_name = [self.__db[DBLBL].GetQualifiedTableName(dblbl.TABLE_NAME_LABELS)]
                entry_dict.append(self.__db[DBLBL].SelectGenericData(sel_list,
                                                                     tab_name,
                                                                     where=condition,
                                                                     order_by=order_by_list))

            # wipe out the empty ones ...
            for idx in entry_dict:
                if len(idx) != 0:
                    entries.append(idx)

            # parsing the entries, calculate the duration per label and store it instead of timestamp in the entries
            calculated = []
            for entry in entries:
                for idx in entry:
                    if len(calculated) == 0:
                        calculated.append(idx)
                    else:
                        if calculated[-1][dblbl.COL_NAME_LABELS_MEASID] != idx[dblbl.COL_NAME_LABELS_MEASID]:
                            end_time_stamp = self.GetEndTimestamp(calculated[-1][dblbl.COL_NAME_LABELS_MEASID])
                            calcts = calculated[-1][dblbl.COL_NAME_LABELS_ABSTS]
                            endts = end_time_stamp[0][dbcat.COL_NAME_FILES_ENDTIMESTAMP]
                            calculated[-1][dblbl.COL_NAME_LABELS_ABSTS] = endts - calcts
                            calculated.append(idx)
                        else:
                            if calculated[-1][dblbl.COL_NAME_LABELS_STATEID] != idx[dblbl.COL_NAME_LABELS_STATEID]:
                                calcts = calculated[-1][dblbl.COL_NAME_LABELS_ABSTS]
                                idxts = idx[dblbl.COL_NAME_LABELS_ABSTS]
                                calculated[-1][dblbl.COL_NAME_LABELS_ABSTS] = idxts - calcts
                                calculated.append(idx)
                            else:
                                continue  # normally it should not be reached

            # update the duration for the last entry
            if len(calculated) != 0:
                end_time_stamp = self.GetEndTimestamp(calculated[-1][dblbl.COL_NAME_LABELS_MEASID])
                endts = end_time_stamp[0][dbcat.COL_NAME_FILES_ENDTIMESTAMP]
                calculated[-1][dblbl.COL_NAME_LABELS_ABSTS] = endts - calculated[-1][dblbl.COL_NAME_LABELS_ABSTS]

            # prepare the result table
            measured = []
            current_measid = []
            for idx in calculated:
                if idx[dblbl.COL_NAME_LABELS_STATEID] not in measured:
                    new_entry = True
                else:
                    for roadtype_hours_files in roadtype_hours_files_list:
                        if roadtype_hours_files[0] == idx[dblbl.COL_NAME_LABELS_STATEID]:
                            roadtype_hours_files[1] += idx[dblbl.COL_NAME_LABELS_ABSTS]
                            if idx[dblbl.COL_NAME_LABELS_MEASID] not in current_measid:
                                roadtype_hours_files[2] += 1
                                current_measid.append(idx[dblbl.COL_NAME_LABELS_MEASID])
                            new_entry = False
                if new_entry:
                    if len(current_measid) == 0 or idx[dblbl.COL_NAME_LABELS_MEASID] not in current_measid:
                        current_measid.append(idx[dblbl.COL_NAME_LABELS_MEASID])
                    measured.append(idx[dblbl.COL_NAME_LABELS_STATEID])
                    roadtype_hours_files_list.append([idx[dblbl.COL_NAME_LABELS_STATEID],
                                                      idx[dblbl.COL_NAME_LABELS_ABSTS],
                                                      1])
                    new_entry = False

            # calculate the roadtype labeled percent per collection (progress of roadtype labeling)
            progress = (float(len(current_measid)) * 100.00) / float(len(coll_measid_list))

            # progress, label_hours_files = self.__db[val_db.DBCAT].GetCollectionHoursPerRoadtype(collection_name)
            # replacing the label state id's with names
            for idx in roadtype_hours_files_list:
                idx[0] = self.__db[DBLBL].GetStateName(int(idx[0]))
            label_duration = dict()
            for duration in roadtype_hours_files_list:
                if duration[0] == RDTYPE_DEFS.LABEL_NAME_HIGHWAY:
                    label_duration[RDTYPE_DEFS.HIGHWAY] = duration[1] / MILLION
                elif duration[0] == RDTYPE_DEFS.LABEL_NAME_COUNTRY:
                    label_duration[RDTYPE_DEFS.COUNTRY] = duration[1] / MILLION
                elif duration[0] == RDTYPE_DEFS.LABEL_NAME_CITY:
                    label_duration[RDTYPE_DEFS.CITY] = duration[1] / MILLION
                elif duration[0] == RDTYPE_DEFS.LABEL_NAME_UNDEFINED:
                    label_duration[RDTYPE_DEFS.UNDEFINED] = duration[1] / MILLION
            # return progress, label_hours_files
            return progress, label_duration
        else:
            return None

    def GetRoadTypeLabelID(self):
        """ gets the id of the road type label
        @param db_label: connection to the label tables.
        """
        condition = stk_sql.SQLBinaryExpr(dblbl.COL_NAME_TYPES_NAME,
                                          stk_sql.OP_EQ,
                                          stk_sql.SQLLiteral(RDTYPE_DEFS.LABEL_TYPE_NAME))
        select_list = [dblbl.COL_NAME_TYPES_TYPEID]
        tab_name = [self.__db[DBLBL].GetQualifiedTableName(dblbl.TABLE_NAME_TYPES)]
        entries = self.__db[DBLBL].SelectGenericData(select_list, tab_name, condition)
        if len(entries) != 1:
            return - 1
        else:
            return entries[0][dblbl.COL_NAME_LABELS_TYPEID]

    def GetNumberOfFilesLabeledForRoadType(self, collection_name):
        """ Gets the number of labeled files for the collection
        @param collection_id: ID of the collection.
        @param db_catalogue: connection to the rec cat tables.
        @param db_label: connection to the label tables.
        @return: value indicating the number of files having an entry in the label table for the road type.
        """
        count = 0
        # Getting the collection ID from the collection name
        collection_id = self.__db[DBCAT].GetCollectionID(collection_name)
        coll_measid_list = self.__db[DBCAT].GetCollectionMeasurements(collection_id, True, False)
        road_type_id = self.GetRoadTypeLabelID()
        if (len(coll_measid_list) == 0) or (road_type_id == -1):
            pass
        else:
            for measid in coll_measid_list:
                # --- get conditions: measid and road type ---
                condition1 = stk_sql.SQLBinaryExpr(dblbl.COL_NAME_LABELS_MEASID, stk_sql.OP_EQ, measid)
                condition2 = stk_sql.SQLBinaryExpr(dblbl.COL_NAME_LABELS_TYPEID, stk_sql.OP_EQ, road_type_id)
                condition = stk_sql.SQLBinaryExpr(condition1, stk_sql.OP_AND, condition2)
                select_list = [dblbl.COL_NAME_LABELS_MEASID]
                tab_name = [self.__db[DBLBL].GetQualifiedTableName(dblbl.TABLE_NAME_LABELS)]
                entries = self.__db[DBLBL].SelectGenericData(select_list, tab_name, where=condition)
                if len(entries) != 0:
                    count += 1
            return count

    def CreateRecLabelCondition(self, label_type_name=None, attribute_name=None, collection_name=None):
        """ Create Recordings Label Condition.
        @param label_type_name: label type name.
        @param attribute_name: attribute name.
        @param collection_name: collection name
        @return: record (dictionary).
        """
        # pylint: disable=R0915
# select
#         lt.name as type, ls.name as state, sum(la.value), lan.name, col.name as collname
#         from lb_labels lb
#         inner join lb_states ls on ls.stateid = lb.stateid
#         inner join lb_types lt on lt.typeid = lb.typeid
#         inner join lb_attributes la on la.lbid = lb.lbid
#         inner join lb_attributenames lan on lan.lbattnameid = la.lbattnameid
#         inner join cat_files cf on cf.measid = lb.measid
#         inner join cat_collectionmap cm on cm.measid = lb.measid
#         inner join cat_collections col on col.collid = cm.collid
#         where col.name = 'POD_001' and lan.name = 'drivendist' and lb.absts = -1
#         group by lt.name, ls.name, lan.name, col.name order by lt.name
        tbl_states = stk_sql.SQLTableExpr(self.__db[DBLBL].GetQualifiedTableName(dblbl.TABLE_NAME_STATES))
        tbl_label = stk_sql.SQLTableExpr(self.__db[DBLBL].GetQualifiedTableName(dblbl.TABLE_NAME_LABELS))
        tbl_types = stk_sql.SQLTableExpr(self.__db[DBLBL].GetQualifiedTableName(dblbl.TABLE_NAME_TYPES))
        tbl_attr = stk_sql.SQLTableExpr(self.__db[DBLBL].GetQualifiedTableName(dblbl.TABLE_NAME_ATTRIBUTES))
        tbl_attr_names = stk_sql.SQLTableExpr(self.__db[DBLBL].
                                              GetQualifiedTableName(dblbl.TABLE_NAME_ATTRIBUTE_NAMES))
        tbl_files = stk_sql.SQLTableExpr(self.__db[DBLBL].GetQualifiedTableName(dbcat.TABLE_NAME_FILES))
        tbl_coll_map = stk_sql.SQLTableExpr(self.__db[DBCAT].GetQualifiedTableName(dbcat.TABLE_NAME_COLLMAP))
        tbl_coll = stk_sql.SQLTableExpr(self.__db[DBCAT].GetQualifiedTableName(dbcat.TABLE_NAME_COLL))

        TypeJoin = stk_sql.SQLJoinExpr(tbl_label, stk_sql.OP_INNER_JOIN, tbl_types,
                    stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_label, dblbl.COL_NAME_LABELS_TYPEID),
                                          stk_sql.OP_EQ,
                                          stk_sql.SQLColumnExpr(tbl_types, dblbl.COL_NAME_TYPES_TYPEID)))

        TypeJoin = stk_sql.SQLJoinExpr(stk_sql.SQLTableExpr(TypeJoin), stk_sql.OP_INNER_JOIN, tbl_states,
                    stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_label, dblbl.COL_NAME_LABELS_STATEID),
                                          stk_sql.OP_EQ,
                                          stk_sql.SQLColumnExpr(tbl_states, dblbl.COL_NAME_STATES_STATEID)))

        TypeJoin = stk_sql.SQLJoinExpr(stk_sql.SQLTableExpr(TypeJoin), stk_sql.OP_INNER_JOIN, tbl_attr,
                    stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_attr, dblbl.COL_NAME_ATTRIBUTES_LBID),
                                          stk_sql.OP_EQ, stk_sql.SQLColumnExpr(tbl_label, dblbl.COL_NAME_LABELS_LBID)))

        TypeJoin = stk_sql.SQLJoinExpr(stk_sql.SQLTableExpr(TypeJoin), stk_sql.OP_INNER_JOIN, tbl_attr_names,
                    stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_attr_names, dblbl.COL_NAME_ATTR_NAMES_LBATTNAMEID),
                                          stk_sql.OP_EQ,
                                          stk_sql.SQLColumnExpr(tbl_attr, dblbl.COL_NAME_ATTRIBUTES_LBATTNAMEID)))

        TypeJoin = stk_sql.SQLJoinExpr(stk_sql.SQLTableExpr(TypeJoin), stk_sql.OP_INNER_JOIN, tbl_files,
                    stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_files, dbcat.COL_NAME_FILES_MEASID),
                                          stk_sql.OP_EQ,
                                          stk_sql.SQLColumnExpr(tbl_label, dblbl.COL_NAME_LABELS_MEASID)))

        if collection_name is not None:
            TypeJoin = stk_sql.SQLJoinExpr(stk_sql.SQLTableExpr(TypeJoin), stk_sql.OP_INNER_JOIN, tbl_coll_map,
                        stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_coll_map, dbcat.COL_NAME_COLLMAP_MEASID),
                                              stk_sql.OP_EQ,
                                              stk_sql.SQLColumnExpr(tbl_files, dbcat.COL_NAME_FILES_MEASID)))

            TypeJoin = stk_sql.SQLJoinExpr(stk_sql.SQLTableExpr(TypeJoin), stk_sql.OP_INNER_JOIN, tbl_coll,
                        stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_coll, dbcat.COL_NAME_COLL_COLLID),
                                              stk_sql.OP_EQ,
                                              stk_sql.SQLColumnExpr(tbl_coll_map, dbcat.COL_NAME_COLLMAP_COLLID)))

        tables = []
        tables.append(TypeJoin)

        cond = stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_label, dblbl.COL_NAME_LABELS_ABSTS),
                                     stk_sql.OP_EQ,
                                     stk_sql.SQLLiteral(CAT_REC_GLOBAL_LABEL_ABSTS))

        if label_type_name is not None:
            condTypeName = stk_sql.SQLBinaryExpr(
                            stk_sql.SQLFuncExpr(self.__db[DBLBL].db_func_map[dblbl.DB_FUNC_NAME_LOWER],
                                                stk_sql.SQLColumnExpr(tbl_types, dblbl.COL_NAME_TYPES_NAME)),
                                                stk_sql.OP_EQ,
                                                stk_sql.SQLLiteral(label_type_name.lower()))
            cond = stk_sql.SQLBinaryExpr(cond, stk_sql.OP_AND, condTypeName)

        if attribute_name is not None:
            condAttrName = stk_sql.SQLBinaryExpr(
                            stk_sql.SQLFuncExpr(self.__db[DBLBL].db_func_map[dblbl.DB_FUNC_NAME_LOWER],
                                                stk_sql.SQLColumnExpr(tbl_attr_names, dblbl.COL_NAME_ATTR_NAMES_NAME)),
                                                stk_sql.OP_EQ,
                                                stk_sql.SQLLiteral(attribute_name.lower()))
            cond = stk_sql.SQLBinaryExpr(cond, stk_sql.OP_AND, condAttrName)

        if collection_name is not None:
            condCollName = stk_sql.SQLBinaryExpr(
                            stk_sql.SQLFuncExpr(self.__db[DBLBL].db_func_map[dblbl.DB_FUNC_NAME_LOWER],
                                                stk_sql.SQLColumnExpr(tbl_coll, dbcat.COL_NAME_COLL_NAME)),
                                                stk_sql.OP_EQ,
                                                stk_sql.SQLLiteral(collection_name.lower()))
            cond = stk_sql.SQLBinaryExpr(cond, stk_sql.OP_AND, condCollName)

        select_list = []
        select_list.append(stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_types,
                            dblbl.COL_NAME_TYPES_NAME), stk_sql.OP_AS, rep.TEST_STAT_RESULT_TYPES))
        select_list.append(stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_states,
                            dblbl.COL_NAME_STATES_NAME), stk_sql.OP_AS, rep.TEST_STAT_RESULT_STATES))
        select_list.append(stk_sql.SQLBinaryExpr(stk_sql.SQLFuncExpr("SUM",
                            stk_sql.SQLColumnExpr(tbl_attr, dblbl.COL_NAME_ATTRIBUTES_VALUE)),
                                                stk_sql.OP_AS, rep.TEST_STAT_VALUE))
        select_list.append(stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_attr_names,
                            dblbl.COL_NAME_ATTR_NAMES_NAME), stk_sql.OP_AS, "ATTRNAME"))

        if collection_name is not None:
            select_list.append(stk_sql.SQLBinaryExpr(stk_sql.SQLColumnExpr(tbl_coll,
                    dbcat.COL_NAME_COLL_NAME), stk_sql.OP_AS, "COLLECTION"))

        group_by = []
        group_by.append(stk_sql.SQLColumnExpr(tbl_types, dblbl.COL_NAME_TYPES_NAME))
        group_by.append(stk_sql.SQLColumnExpr(tbl_states, dblbl.COL_NAME_STATES_NAME))
        group_by.append(stk_sql.SQLColumnExpr(tbl_attr_names, dblbl.COL_NAME_ATTR_NAMES_NAME))
        if collection_name is not None:
            group_by.append(stk_sql.SQLColumnExpr(tbl_coll, dbcat.COL_NAME_COLL_NAME))

        order_by = []
        order_by.append(stk_sql.SQLColumnExpr(tbl_types, dblbl.COL_NAME_TYPES_NAME))
        order_by.append(rep.TEST_STAT_VALUE)
        order_by.append(stk_sql.SQLColumnExpr(tbl_states, dblbl.COL_NAME_STATES_NAME))

        entries = self.__db[DBLBL].SelectGenericData(select_list=select_list, table_list=tables,
                                                     where=cond, group_by=group_by, order_by=order_by)

        record = {}

        if len(entries) <= 0:
            self.__logger.warning("Label Records with labeltype '%s' does not exists in the generic label database." %
                                  label_type_name)
        else:
            record = entries

        # done
        return record

    def __GetAllRecordingTypes(self):
        """ Get all Recordings types.
        @return: Recordingtypes (list): list of all recording types.
        """

        RecordingTypes = []
        db_records = self.CreateRecLabelCondition()
        for entrys in db_records:
            for item in entrys:
                if (item.lower() == rep.TEST_STAT_RESULT_TYPES.lower()) and (not entrys[item] in RecordingTypes):
                    RecordingTypes.append(entrys[item])
        return RecordingTypes

    def PrepareTableDictionary(self, attribute_name, collection_name=None, dictionary=None):  # pylint: disable=W0613
        """ Prepare table dictionary for the report.
        @param attribute_name: attribute name
        @param collection_name: collection name
        @return: table dictionary for the report.
        """
        # pylint: disable=R0912, R0915

        # first add the global poperties for the collections, like the distance
        distance_dict = {}
        target = {}
        db_records = {}
        recording_types = self.__GetAllRecordingTypes()
        TotalDist = None
        if collection_name is not None:
            db_records = self.__db[DBCAT].GetCollectionKilometer(collection_name)
        else:
            db_records = self.__db[DBCAT].GetCollectionKilometer()

        if db_records[dbcat.COL_NAME_FILES_RECDRIVENDIST] is not None:
            if not (rep.TEST_STAT_RESULTS in distance_dict):
                distance_dict[rep.TEST_STAT_RESULTS] = {}
                target = distance_dict[rep.TEST_STAT_RESULTS]

            # total distance
            target[rep.TEST_STAT_RESULTS_DIST] = {}
            TotalDist = db_records[dbcat.COL_NAME_FILES_RECDRIVENDIST]
            target[rep.TEST_STAT_RESULTS_DIST][rep.TEST_STAT_VALUE] = TotalDist
            target[rep.TEST_STAT_RESULTS_DIST][rep.TEST_STAT_UNIT] = "km"

        # Total time over all files
        TotalTime = None
        if collection_name is not None:
            TotalTime = self.__db[DBCAT].GetCollectionTime(collection_name)
        else:
            TotalTime = self.__db[DBCAT].GetCollectionTime()

        if TotalTime is not None:
            if rep.TEST_STAT_RESULTS not in distance_dict:
                distance_dict[rep.TEST_STAT_RESULTS] = {}
                target = distance_dict[rep.TEST_STAT_RESULTS]

            target[rep.TEST_STAT_RESULTS_TIME] = {}
            target[rep.TEST_STAT_RESULTS_TIME][rep.TEST_STAT_VALUE] = \
                str(datetime.timedelta(microseconds=TotalTime)).rsplit('.')[0]
            target[rep.TEST_STAT_RESULTS_TIME][rep.TEST_STAT_UNIT] = "Time"

        # add the mean velocity to the report
        if TotalTime is not None and TotalDist is not None:
            if rep.TEST_STAT_RESULTS not in distance_dict:
                distance_dict[rep.TEST_STAT_RESULTS] = {}
                target = distance_dict[rep.TEST_STAT_RESULTS]

            target[rep.TEST_STAT_RESULTS_MEANVELO] = {}
            if abs(TotalTime) <= 0.001:
                target[rep.TEST_STAT_RESULTS_MEANVELO][rep.TEST_STAT_VALUE] = 0
            else:
                target[rep.TEST_STAT_RESULTS_MEANVELO][rep.TEST_STAT_VALUE] = (TotalDist * 1000000 * 3600) / TotalTime
            target[rep.TEST_STAT_RESULTS_MEANVELO][rep.TEST_STAT_UNIT] = "km/h"

        # add the number of files to the report
        db_records = None
        if collection_name is not None:
            collection_id = None
            try:
                collection_id = self.__db[DBCAT].GetCollectionID(collection_name)
            except BaseException:
                collection_id = None
                # pass
            if collection_id is not None:
                db_records = self.__db[DBCAT].GetCollectionMeasurements(collection_id)
        else:
            db_records = self.__db[DBCAT].GetCollectionMeasurements()

        if db_records is not None:
            if rep.TEST_STAT_RESULTS not in distance_dict:
                distance_dict[rep.TEST_STAT_RESULTS] = {}
                target = distance_dict[rep.TEST_STAT_RESULTS]
            # number of filse
            target[rep.TEST_STAT_RESULTS_FILES] = {}
            target[rep.TEST_STAT_RESULTS_FILES][rep.TEST_STAT_VALUE] = len(db_records)

        # for all recording types like weather, light ..
        for recording_type in recording_types:
            # get for all the states the diven distances
            if collection_name is not None:
                db_records = self.CreateRecLabelCondition(recording_type, "drivendist",
                                                          collection_name=collection_name)
                db_records_time = self.CreateRecLabelCondition(recording_type, "driventime",
                                                               collection_name=collection_name)
            else:
                db_records = self.CreateRecLabelCondition(recording_type, "drivendist")
                db_records_time = self.CreateRecLabelCondition(recording_type, "driventime")

            if (len(db_records) > 0) and (len(db_records_time) > 0):

                target = {}

                if recording_type == rep.TEST_STAT_DB_TYPE_ROADTYPE:
                    distance_dict[rep.TEST_STAT_ROAD_TYPE] = {}
                    target = distance_dict[rep.TEST_STAT_ROAD_TYPE]

                if recording_type == rep.TEST_STAT_DB_TYPE_LIGHT:
                    distance_dict[rep.TEST_STAT_LIGHT_COND] = {}
                    target = distance_dict[rep.TEST_STAT_LIGHT_COND]

                if recording_type == rep.TEST_STAT_DB_TYPE_WEATHER:
                    distance_dict[rep.TEST_STAT_WEATHER_COND] = {}
                    target = distance_dict[rep.TEST_STAT_WEATHER_COND]

                if recording_type == rep.TEST_STAT_DB_TYPE_COUNTRY:
                    distance_dict[rep.TEST_STAT_COUNTRIES] = {}
                    target = distance_dict[rep.TEST_STAT_COUNTRIES]

                if recording_type == rep.TEST_STAT_DB_TYPE_STREET:
                    distance_dict[rep.TEST_STAT_ROAD_COND] = {}
                    target = distance_dict[rep.TEST_STAT_ROAD_COND]

                if recording_type == rep.TEST_STAT_DB_TYPE_NO_PED:
                    distance_dict[rep.TEST_STAT_NO_PED] = {}
                    target = distance_dict[rep.TEST_STAT_NO_PED]

                for entrys in range(len(db_records)):
                    times = {}
                    distances = {}
                    # lower the keys of the db results
                    for item in db_records[entrys]:
                        distances[item.lower()] = db_records[entrys][item]
                        times[item.lower()] = db_records_time[entrys][item]

                    state_key = rep.TEST_STAT_RESULT_STATES.lower()
                    if state_key in distances:
                        state = distances[state_key]
                        if state not in target:
                            target[state] = {}
                        target[state][rep.TEST_STAT_VALUE] = (distances[rep.TEST_STAT_VALUE.lower()] /
                                                              TotalDist) * 100.0
                        target[state][rep.TEST_STAT_UNIT] = "%"
                        target[state][rep.TEST_STAT_DISTANCE] = distances[rep.TEST_STAT_VALUE.lower()]
                        target[state][rep.TEST_STAT_VELOCITY] = "%3.1f" % \
                            ((distances[rep.TEST_STAT_VALUE.lower()] / times[rep.TEST_STAT_VALUE.lower()]) * 3600.0)

        return (distance_dict, [rep.TEST_STAT_DISTANCE, rep.TEST_STAT_VELOCITY])

    def GetEndTimestamp(self, measid):
        """ Get the end timestamp for MEASID.
        @param measid: The measid.
        @return: end_timestamp.
        """
        condition = stk_sql.SQLBinaryExpr(dbcat.COL_NAME_FILES_MEASID, stk_sql.OP_EQ, measid)
        select_list = [dbcat.COL_NAME_FILES_ENDTIMESTAMP]
        end_timestamp = self.__db[DBCAT].SelectGenericData(select_list,
                            [self.__db[DBCAT].GetQualifiedTableName(dbcat.TABLE_NAME_FILES)], condition)

        return end_timestamp

    def GetCollectionHoursKilometerPerRecdate(self, collection_name):
        """ Get hours and kilometer per Driver.
        @param collection_name: The collection name.
        @return: Array of tuples (measid, driverid, hours, files, kilometer).
        """
        recdate_hours_files = self.__db[DBCAT].GetCollectionHoursKilometerPerRecdate(collection_name)
        return recdate_hours_files

    def GetCollectionHoursKilometerPerDriver(self, collection_name):
        """ Get hours and kilometer per Driver.
        @param collection_name: The collection name.
        @return: Array of tuples (measid, driverid, hours, files).
        """
        driver_hours_files = self.__db[DBCAT].GetCollectionHoursKilometerPerDriver(collection_name)
        return driver_hours_files

    def GetCollectionHoursKilometerPerVehicle(self, collection_name):
        """ Get hours and kilometer per vehicle.
        @param collection_name: The collection name.
        @return: Array of tuples (vehicle, hours, files).
        """
        hours_per_vehicle = self.__db[DBCAT].GetCollectionHoursKilometerPerVehicle(collection_name)
        return hours_per_vehicle

    def SetPictureFlagOnEvent(self, seid, timestamp, attribute_name, value, image_files):
        """ Adds and/or sets the picture_flag (as global attribute) for the event
        @param seid: the event id
        @param timestamp: timestamp
        @return: edid
        """
        # add event details
        edid = self.__db[DBVAL].AddEventDetails(seid, timestamp)

        attribute_type_id = self.__db[DBVAL].GetEventAttributeTypeId(attribute_name)
        if attribute_type_id is None:
            unitid = self.__db[DBGBL].GetUnitIdByName(GBL_DEFS.UNIT_L_NONE)

            attribute_type = {}
            attribute_type[dbval.COL_NAME_EVENT_ATTR_TYPES_NAME] = attribute_name
            attribute_type[dbval.COL_NAME_EVENT_ATTR_TYPES_UNITID] = unitid
            attribute_type[dbval.COL_NAME_EVENT_ATTR_TYPES_DESC] = 'auto generated attribute type'
            attribute_type_id = self.__db[DBVAL].AddEventAttributeType(attribute_type)

        attribute_id = self.__db[DBVAL].GetEventAttributeId(edid=edid, attribute_name=attribute_name)
        if attribute_id is None:
            unitid = self.__db[DBGBL].GetUnitIdByName(GBL_DEFS.UNIT_L_NONE)

            attribute = {}
            attribute[dbval.COL_NAME_EVENT_ATTR_EDID] = edid
            attribute[dbval.COL_NAME_EVENT_ATTR_VALUE] = 0
            attribute[dbval.COL_NAME_EVENT_ATTR_ATTRTYPEID] = attribute_type_id
            attribute_id = self.__db[DBVAL].AddEventAttribute(attribute, getattrid=True)

        entries = self.__db[DBVAL].GetEventAttribute(attrid=attribute_id,
                                                     edid=edid, attrtypeid=attribute_type_id)

        if (int)(entries[0][dbval.COL_NAME_EVENT_ATTR_VALUE]) == 0:
        # if entries[dbval.COL_NAME_EVENT_ATTR_VALUE] == 0:
            value = 1
            for filename in image_files:
                image = buffer(open(str(filename), "rb").read())
                if isinstance(image, buffer):
                    event_image = {}
                    event_image[dbval.COL_NAME_EVENT_IMG_ATTRID] = attribute_id
                    event_image[dbval.COL_NAME_EVENT_IMG_FORMAT] = 'jpeg'
                    event_image[dbval.COL_NAME_EVENT_IMG_TITLE] = str('Event image for Attribute ID %s' % attribute_id)
                    event_image[dbval.COL_NAME_EVENT_IMG_IMAGE] = image

                    self.__db[DBVAL].AddEventImage(event_image)
        else:
            value = 0
            self.__db[DBVAL].DeleteEventImage(attribute_id)

        self.__db[DBVAL].UpdateEventAttribute(attrid=attribute_id, value=value)

    def GetAllEventsTypesAssessment(self, tr_id, meas_id, se_id):
        """ Get all events with types and assessment for TRID
        @param tr_id: the selected testrun
        @param mes_id: the selected measid
        @return: events dictionary
        """

        r_time, events = self.__db[DBVAL].GetEventsTypesAssessment(trid=tr_id, measid=meas_id, seid=se_id)
        return r_time, events

    def GetAllAttributesTypes(self):
        """ Get all distinct attributes
        @return: attributes list
        """
        attr_name = []
        attr_typeid = []
        attrs = self.__db[DBVAL].GetEventAttributeType()
        for ix in xrange(len(attrs)):
            attr_name.append(attrs[ix][dbval.COL_NAME_EVENT_ATTR_TYPES_NAME])
            attr_typeid.append(attrs[ix][dbval.COL_NAME_EVENT_ATTR_TYPES_ATTRTYPEID])
        return attr_name, attr_typeid

    def GetAssessmentDict(self, obs_type):
        """ Fill the Assessment dictionary from GBL_Assessment_State table
        """
        assessment_dict = {}
        self.__asmt = val_asmt.ValAssessmentStates(obs_type)
        if self.__asmt.Load(self.__db[DBGBL]):
            assessment_dict = self.__asmt.GetStates(with_id=True)
#        entries = self.__db[val_gd.DBGBL].GetAssessmentState(name=None, assstid=None, observer_type_id=obs_type)
#        if len(entries) > 1:
#            for item in entries:
#                assessment_dict[item[dbgbl.COL_NAME_ASSESSMENT_STATE_ASSID]] =
#                        item[dbgbl.COL_NAME_ASSESSMENT_STATE_NAME]
        return assessment_dict

    def GetEventTypeList(self, testrun_id):
        """ Fill the Event type list according to testrun
        """
        eventtype_list = []
        entries = self.__db[DBVAL].GetEventTypesView(trid=testrun_id)
        if len(entries) > 0:
            for item in entries:
                eventtype_list.append(" = '" + str(item[dbval.COL_NAME_EVENTS_VIEW_EVENTTYPE]) + "'")
        return eventtype_list

    def UpdateAssessment(self, resassid, ass_comment=None, user_id=None,
                         ass_date=None, ass_wfid=None, assessment=None, ass_issue=None):  # pylint: disable=W0613
        """ Update the Val_assessment entry
        @return: attributes list
        """
        asse = {}
        asse[dbval.COL_NAME_ASS_ID] = resassid
        if user_id is not None:
            user = self.__db[DBGBL].GetUser(login=os.environ["USERNAME"])
            user_id = user[dbgbl.COL_NAME_USER_ID]
            asse[dbval.COL_NAME_ASS_USER_ID] = user_id

        # asse[dbval.COL_NAME_ASS_WFID]     = assessment
        # if ass_date is not None:
        #    asse[dbval.COL_NAME_ASS_DATE] = ass_date      #datetime.datetime.now()
        if ass_comment is not None:
            asse[dbval.COL_NAME_ASS_COMMENT] = ass_comment
        if ass_wfid is not None:
            asse[dbval.COL_NAME_ASS_WFID] = self.__db[DBGBL].GetWorkflow('manual')['WFID']
        if assessment is not None:
            asse[dbval.COL_NAME_ASS_ASSSTID] = assessment
        if ass_issue is not None:
            asse[dbval.COL_NAME_ASS_TRACKING_ID] = ass_issue

        entries = self.__db[DBVAL].UpdateAssessment(asse, where=None)

        return entries

    def GetAllEventsAttributes(self, se_id, tstamps, attribute_name=None):
        """ Get all attributes for an event
        @param seid: the event id
        @return: attributes dictionary
        """

        ev_name = []
        ev_value = []
        events = self.__db[DBVAL].GetEventDetailsAttributes(seid=se_id, timestamps=tstamps,
                                                            attribute_name=attribute_name)

        for ix in xrange(len(events)):
            if tstamps is None and events[ix][dbval.COL_NAME_EVENT_DET_ABSTS] == -1:
                continue
            ev_name.append(events[ix][dbval.COL_NAME_EVENT_ATTR_TYPES_NAME])
            ev_value.append(events[ix][dbval.COL_NAME_EVENT_ATTR_VALUE])

        return  ev_name, ev_value

    def GetEventRecFilename(self, trid=None, measid=None, seid=None, assessment=None):
        """Get the recording file name for the event
        """
        rec_filename = self.__db[DBVAL].GetEventsView(trid=trid, measid=measid, seid=seid,
                                                      assessment=assessment)[0][dbval.COL_NAME_EVENTS_VIEW_FILE_NAME]
        return rec_filename

    def GetEventImagePlotSeq(self, seid, plot=False):
        """ Get image sequence for an event
        @param seid: the event id
        @return: image file name
        """
        if plot:
            attr_type = ACC_PLOT_DAT_FILE
        else:
            attr_type = ACC_VIDEO_SEQ_FILE

        sequence = self.__db[DBVAL].GetEventImagePlotSeq(seid, attr_type, plot)
        if len(sequence):
            return str(sequence[0][dbval.COL_NAME_EVENT_IMG_IMAGE])
        else:
            return sequence

    def GetResultImageFromDb(self, res_id):
        """ Get Image for a result from database
        @param rs_id: the result id
        @return: image
        """
        image = self.__db[DBVAL].GetResultImage(res_id)
        if len(image):
            return str(image[dbval.COL_NAME_RESIMG_IMAGE])
        else:
            return image

    def GetEventImageFromDb(self, seid, attr_type):
        """ Get Image for an event from database
        @param seid: the event id
        @return: image
        """

        if attr_type == 'clothoid':
            # for roadtype attr_type is ROAD_EVENT_IMAGE
            attr_type = ROAD_EVENT_IMAGE

        image = self.__db[DBVAL].GetEventImagePlotSeq(seid, attr_type, plot=False)
        if len(image):
            return str(image[0][dbval.COL_NAME_EVENT_IMG_IMAGE])
        else:
            return image

    def GetEventPlotSeq(self, seid):
        """ Get plot sequence for an event
        @param seid: the event id
        @return: plot file name
        """

        plot_seq = self.__db[DBVAL].GetEventPlotSeq(seid)
        return plot_seq

    def GetEventTimestamps(self, se_id):
        """ Get all distinct timestamps for an event
        @param seid: the event id
        @return: timestamps list
        """

        timestamps = self.__db[DBVAL].GetEventDetailsTimestamps(seid=se_id)
        return timestamps

    def GetFilteredEventTypesDetailsAttributesAssessment(self, tr_id, mes_id, se_id,
                                                         predef_filter_str, filter_str, how_many):
        """ Get filtered content of Assesment window from VAL_VIEW_EVENTS_ATRIBUTES.
        @param tr_id: the selected testrun
        @param mes_id: the selected measid
        @param se_id: the selected seid
        @param filter_str: the preprocessed filter condition
        :param predef_filter_str: SQLBinaryExpression containing the predefined filter condition
        """

        r_time, events = self.__db[DBVAL].GetFilteredEventTypesDetailsAttributesAssessment(
                                tr_id, mes_id, se_id, predef_filter_str, filter_str, how_many)
        return r_time, events

    def GetFilteredResultsTypesDetailsAssessment(self, tr_id, meas_id, res_id,
                                                 predef_filter_str, filter_str, how_many):
        """ Get filtered content of Assesment window from VAL_RESULTS.
        @param tr_id: the selected testrun
        @param mes_id: the selected measid
        @param se_id: the selected result id
        @param filter_str: the preprocessed filter condition
        :param predef_filter_str: SQLBinaryExpression containing the predefined filter condition
        """
#xxxx
        r_time, results = self.__db[DBVAL].GetFilteredResultsTypesDetailsAssessment(
                                tr_id, meas_id, res_id, predef_filter_str, filter_str, how_many)
        start_time = time.time()
        for entry in results:
            if entry['FILENAME'] is not None:
                entry['FILENAME'] = self.__db[DBCAT].GetRecFileNameForMeasid(entry['FILENAME']).rsplit("\\")[-1]
            if entry['UNIT'] is not None:
                entry['UNIT'] = self.__db[DBGBL].GetUnit(name=None, uid=entry['UNIT'])['NAME']

        #print "with queries -> " + str(r_time)
        return r_time + (time.time() - start_time), results
#xxxx

    def GetEventsInfoForExportToCsv(self, trid):
        """ Get the content to be exported from VAL_VIEW_EVENTS_ATRIBUTES.
        @param seids: the list of seids
        @return: the list of filtered infos for the export to CSV
        """

        events_to_csv = self.__db[DBVAL].GetEventsInfoForExportToCsv(trid)
        return events_to_csv

    def GetAssesmentResultId(self, seid, event=True):
        """ Get Resassid(VAL_ASSESSMENT).
        @param  seid: the event ID.
        @param event: True for events and False for results
        @return: list of  Resassid(s).
        """
        if event is True:
            resassid = self.__db[DBVAL].GetEvents(seid)
            resassid_row = self.__db[DBVAL].GetAssessment(resassid[0][dbval.COL_NAME_ASS_ID])
            resassid = resassid_row[0][dbval.COL_NAME_ASS_ID]
            assessment = resassid_row[0][dbval.COL_NAME_ASS_ASSSTID]
            asscomment = resassid_row[0][dbval.COL_NAME_ASS_COMMENT]
        else:
            resassid = self.__db[DBVAL].GetResult(tr_id=0, res_id=seid)
            if len(resassid) == 0:
                return 0, 0, ""
            else:
                resassid_row = self.__db[DBVAL].GetAssessment(resassid[dbval.COL_NAME_ASS_ID])
                if len(resassid_row) == 0:
                    return resassid[dbval.COL_NAME_ASS_ID], 0, ""
                resassid = resassid_row[0][dbval.COL_NAME_ASS_ID]
                assessment = resassid_row[0][dbval.COL_NAME_ASS_ASSSTID]
                asscomment = resassid_row[0][dbval.COL_NAME_ASS_COMMENT]
        return resassid, assessment, asscomment

    def GetResultIds(self, testrun, measid):
        """ Get Result IDs(VAL_Results).
        @param  testrun: the testrun ID.
        @return: list of  Result IDs.
        """
        resids = self.__db[DBVAL].GetResultIds(tr_id=testrun, rd_id=None, meas_id=measid)
        return resids

    def GetSeIds(self, testrun, measid):
        """ Get SeIDs(VAL_EVENTS).
        @param  testrun: the testrun ID.
        @return: list of  SeIDs.
        """
        seids = self.__db[DBVAL].GetSeidsForTestrun(testrun, measid)
        return seids

    def GetObserverIds(self):
        """ Get Observer IDs(GBL_VALOBSERVER).
        @param  none.
        @return: list of observer IDs.
        """
        obs_ids = []
        obs_show = []

        entries = self.__db[DBGBL].GetValObserverType(name=None)
        if len(entries) > 1:
            # fill up the lists
            for ix in xrange(len(entries)):
                obs_ids.append(entries[ix][dbgbl.COL_NAME_VO_TYPE_ID])
                obs_show.append(str(entries[ix][dbgbl.COL_NAME_VO_TYPE_NAME]))

        return obs_ids, obs_show

    def GetAccType(self, testrun_id):
        """ Get the ACC test type for the Testrun_id
        """
        acc_type = []
        entries = self.__db[DBVAL].GetTestRun(tr_id=testrun_id)
        if len(entries) != 0:
            tmp = self.__db[DBVAL].GetTestRun(tr_id=entries[dbval.COL_NAME_TR_PARENT])
            if len(tmp):
                acc_type = self.__db[DBGBL].GetValObserverType(type_id=tmp[dbval.COL_NAME_TR_TYPE_ID])
            else:
                acc_type = self.__db[DBGBL].GetValObserverType(type_id=entries[dbval.COL_NAME_TR_TYPE_ID])
        return acc_type[dbgbl.COL_NAME_VO_TYPE_NAME]

    def GetTestRunIds(self, obs_type=None, checkpoint=None, proj_id=None, is_deleted=0):
        """ Get Testrun IDs(VAL_TESTRUN) for the Observer_type.
        @param  obs_type: observer type
        @param proj_id: project id
        @param is_deleted: 0/1 - not/ deleted
        @return: list of testrun IDs.
        """
        testrun_ids = []
        testrun_checkpoint = []
        testrun_show = []
        entries = self.__db[DBVAL].GetAllTestruns(type_id=obs_type, checkpoint=checkpoint,
                                                  proj_id=proj_id, delete_status=is_deleted)
        # fill up the lists and exclude the parent testruns
        for ix in xrange(len(entries)):
            # if entries[ix][dbval.COL_NAME_TR_PARENT] is not None:
            testrun_ids.append(entries[ix][dbval.COL_NAME_TR_ID])
            testrun_checkpoint.append(entries[ix][dbval.COL_NAME_TR_CHECKPOINT])
            #testrun_show.append(str(entries[ix][dbval.COL_NAME_TR_CHECKPOINT]))
            testrun_show.append(str(entries[ix][dbval.COL_NAME_TR_NAME]))

        return testrun_ids, testrun_checkpoint, testrun_show

    def GetRecFileNameForSeid(self, seid):
        """ Get rec file path for SEID
        @param seid: the seid of the event
        @return: the complete filepath
        """
        # filepath = ""
        measid = self.__db[DBVAL].GetMeasidForSeid(seid)
        filepath = self.__db[DBCAT].GetRecFileNameForMeasid(measid)
        return filepath

    def GetMeasIds(self, testrun):
        """ Get Meas IDs for the corresponding testrun (VAL_EVENTS).
        @param  testrun: the testrun ID .
        @return: list of meas IDs.
        """
        measids = self.__db[DBVAL].GetMeasidsForTestrun(testrun)
        return measids

    def GetRecordingLabelConditions(self, label_type_name, attribute_name=None, collection_name=None):
        """ Get the recording labels conditions.
        @param label_type_name: The recording label type name
        @param attribute_name: The recording label attribute name
        @param collection_name: The selected collection name
        @return: dictionary list (attname, state, type, value, (collname))
        """
        # move this form the car_reporter
        pass

    def GetFileList(self):
        """ Get a list of files in the database.
        @return: File path list.
        """
        return self.__db[DBCAT].SelectMeasurements(select_list=[dbcat.COL_NAME_FILES_FILEPATH])

    def GetTableName(self):
        """ Return the current table name.
        @return: The current table name.
        """
        return self.__table_name_list[self.__table_name_idx]

    def GetTableNames(self):
        """ Return the current table name list.
        @return: The current table name list.
        """
        return self.__table_name_list

    def GetColumnName(self):
        """ Return the current column name.
        @return: The current column name.
        """
        return self.__column_name

    def GetColumnNames(self):
        """ Get the column names for the current table.
        @return: The column names.
        """
        return self.__column_name_list

    def GetGeneric(self, field_select, comparitor, value, sort):
        """ A generic 'Get' to select information from the database.
        @param field_select: The field name to retrieve or "*".
        @param comparitor: A comparitor such as >=, >=, =, >, <.
        @param value: A numerical value or a string.
        @param sort: The sort order "Ascending" or "Descending".
        """
        if field_select == "*":
            self.table_data = self.__db[DBGBL].GetTableData(self.GetTableName(), [self.__column_name])
        else:
            if sort == "Ascending":
                sort = "ASC"
            else:
                sort = "DESC"
            self.table_data = self.__db[DBGBL].GetSelectData(self.GetTableName(),
                                                             [self.__column_name],
                                                             field_select,
                                                             comparitor, value, sort)
        self.fields = self.table_data[0]
        self.data = self.table_data[1]
        self.num_columns = len(self.fields)
        self.num_rows = len(self.data)

    def GetMeasurementDurationDistanceSpeedCycleInfo(self, measid):
        """ Get the dureation, distance, average speed and cycle info for a measurement.
        @param measid: The measurement id.
        @return: duration in seconds, distance in km, cycle violations, short cycle, long cycle, cycle max
        """
        ego_kinematics_l = self.__db[DBOBJ].GetEgoKinematics(measid)

        # Duration
        duration_us = ego_kinematics_l[len(ego_kinematics_l) - 1]["KINABSTS"] - ego_kinematics_l[0]["KINABSTS"]
        duration_s = int(duration_us / MILLION)

        dist_m = 0
        cycle_vi = 0
        cycle_short = 0
        cycle_long = 0
        cycle_max_ms = 0.0
        for idx in xrange(1, len(ego_kinematics_l) - 1):
            time_diff_us = ego_kinematics_l[idx]["KINABSTS"] - ego_kinematics_l[idx - 1]["KINABSTS"]
            dist_diff_m = ego_kinematics_l[idx]["VELOCITY"] * time_diff_us / MILLION
            dist_m += dist_diff_m
            time_diff_ms = time_diff_us / THOUSAND
            if time_diff_ms < CYCLE_TIME_SHORT_MS:
                cycle_short += 1
                if time_diff_ms == 0:
                    cycle_vi += 1
            if time_diff_ms > CYCLE_TIME_LONG_MS:
                cycle_long += 1
                if time_diff_ms > cycle_max_ms:
                    cycle_max_ms = time_diff_ms

        dist_m = int(dist_m)
        dist_km = float(dist_m) / THOUSAND

        return measid, duration_s, dist_km, cycle_vi, cycle_short, cycle_long, cycle_max_ms

    def HasCollectionMeasurementsChildren(self, collection_id):
        """ Function that returns true if a collection has measurements or children.
        @param collection_id: The collection id.
        @return: Bool. True is measurements or children are found.
        """
        measurements = self.__db[DBCAT].GetCollectionMeasurements(collection_id)
        child_collections = self.__db[DBCAT].GetCollections(collection_id)

        if len(measurements) > 0 or len(child_collections) > 0:
            return True

        return False

    def HasChildren(self, collection_id):
        """ Function that returns the collection id's of children(s).
        @param collection_id: The collection id.
        @return: children(s) id's if children(s) are found, empty list if not.
        """
        child_collections = self.__db[DBCAT].GetCollections(collection_id)
        return child_collections

    def HasMeasurement(self, filepath):
        """ Get a list of files in the database.
        @return: File path list.
        """
        return self.__db[DBCAT].HasMeasurement(filepath)

    def SetTableName(self, table_name):
        """ Set the table name index based on the given table name.
        @param table_name: The table name to set.
        """
        # On database reconnection, when the list is cleared, this function may be called with a null list.
        if table_name in self.__table_name_list:
            self.__table_name_idx = self.__table_name_list.index(table_name)
            # Update the row list.
            self.__column_name_list = self.__db[DBGBL].GetColumnNames(table_name)

    def SetColumnName(self, column_name):
        """ Set the cloumn name.
        @param column_name: The column name to set.
        """
        self.__column_name = column_name

    def UpdateCollectionParentId(self, collection_id, parent_id=None):
        """ Update a parent collection of a collection.
        If the collection has a parent it is not replaced.
        @param collection_id: The id of the collection.
        @param parent_id: The id of the parent collection.
        """

        # Check that the collection and parent id's are not identical
        if collection_id == parent_id:
            return
        else:
            # or parent has already the same collection as child
            child_ids = self.HasChildren(collection_id)
            if len(child_ids) > 0 and parent_id in child_ids:
                return

        collection_record = {}
        # collection_record[db_cat.COL_NAME_COLL_NAME] = collection_name
        collection_record[dbcat.COL_NAME_COLL_PARENTID] = parent_id
        # collection_record[db_cat.COL_NAME_COLL_COLLCOMMENT] = comment

        where = dbcat.COL_NAME_COLL_COLLID + " = " + str(collection_id)

        self.__db[DBCAT].UpdateCollections(collection_record, where)
        self.__db[DBCAT].Commit()

"""
CHANGE LOG:
-----------
$Log: db_enhquery.py  $
Revision 1.1 2021/12/13 17:55:48CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/project.pj
Revision 1.18 2013/12/13 14:48:31CET Zafar, Sohaib (uidu6396) 
fixing pep8 errors (some under and over visual indentations are kept for better readability)
- Added comments -  uidu6396 [Dec 13, 2013 2:48:31 PM CET]
Change Package : 208164:1 http://mks-psad:7002/im/viewissue?selection=208164
Revision 1.17 2013/12/13 11:13:53CET Zafar-EXT, Sohaib (uidu6396)
Adding FCT Database Connection
--- Added comments ---  uidu6396 [Dec 13, 2013 11:13:53 AM CET]
Change Package : 208164:1 http://mks-psad:7002/im/viewissue?selection=208164
Revision 1.16 2013/12/11 16:25:39CET Bratoi-EXT, Bogdan-Horia (uidu8192)
- further changes related to DB changes
--- Added comments ---  uidu8192 [Dec 11, 2013 4:25:40 PM CET]
Change Package : 193409:1 http://mks-psad:7002/im/viewissue?selection=193409
Revision 1.15 2013/11/26 14:48:07CET Bratoi-EXT, Bogdan-Horia (uidu8192)
Project_id and filter implementation
--- Added comments ---  uidu8192 [Nov 26, 2013 2:48:07 PM CET]
Change Package : 193409:1 http://mks-psad:7002/im/viewissue?selection=193409
Revision 1.14 2013/11/06 14:00:49CET Bratoi-EXT, Bogdan-Horia (uidu8192)
- cleared the dependencies to valgui
- cleaned up the imports
--- Added comments ---  uidu8192 [Nov 6, 2013 2:00:49 PM CET]
Change Package : 190325:1 http://mks-psad:7002/im/viewissue?selection=190325
Revision 1.13 2013/10/30 10:06:49CET Hecker, Robert (heckerr)
removed not working imports -> leads to not working methods, but import can be done sucessfull.
--- Added comments ---  heckerr [Oct 30, 2013 10:06:49 AM CET]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.12 2013/10/30 09:38:34CET Hecker, Robert (heckerr)
Added dependencies to valgui -> Are they realy needed ?
--- Added comments ---  heckerr [Oct 30, 2013 9:38:35 AM CET]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.11 2013/09/18 08:16:42CEST Bratoi-EXT, Bogdan-Horia (uidu8192)
- cleaned some more pep8 warnings
--- Added comments ---  uidu8192 [Sep 18, 2013 8:16:42 AM CEST]
Change Package : 190325:1 http://mks-psad:7002/im/viewissue?selection=190325
Revision 1.10 2013/08/08 09:29:05CEST Raedler, Guenther (uidt9430)
- fixed several pep8 warnings
- made code more readable
--- Added comments ---  uidt9430 [Aug 8, 2013 9:29:05 AM CEST]
Change Package : 192838:1 http://mks-psad:7002/im/viewissue?selection=192838
Revision 1.9 2013/08/07 15:00:45CEST Raedler, Guenther (uidt9430)
- removed tailing whitespaces
--- Added comments ---  uidt9430 [Aug 7, 2013 3:00:45 PM CEST]
Change Package : 192838:1 http://mks-psad:7002/im/viewissue?selection=192838
Revision 1.8 2013/07/04 07:57:50CEST Bratoi, Bogdan-Horia (uidu8192)
- ui and results updates
--- Added comments ---  uidu8192 [Jul 4, 2013 7:57:50 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.7 2013/06/11 09:09:22CEST Bratoi, Bogdan-Horia (uidu8192)
- small change related the connection to sqlite DB
--- Added comments ---  uidu8192 [Jun 11, 2013 9:09:22 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.6 2013/05/16 09:34:15CEST Bratoi, Bogdan-Horia (uidu8192)
- changed the error tolerance
- updated the SetPictureFlagOnEvent
--- Added comments ---  uidu8192 [May 16, 2013 9:34:15 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.5 2013/05/14 10:42:35CEST Ibrouchene-EXT, Nassim (uidt5589)
Modified road type label reading function to use the global definitions.
Added two extra road type label reading utility functions.
--- Added comments ---  uidt5589 [May 14, 2013 10:42:35 AM CEST]
Change Package : 182606:4 http://mks-psad:7002/im/viewissue?selection=182606
Revision 1.4 2013/05/03 10:04:59CEST Bratoi, Bogdan-Horia (uidu8192)
- implementation of the ValAssessmentStates class in the  GetAssessmentDict
--- Added comments ---  uidu8192 [May 3, 2013 10:04:59 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.3 2013/05/02 09:12:16CEST Bratoi, Bogdan-Horia (uidu8192)
- small bugfix
--- Added comments ---  uidu8192 [May 2, 2013 9:12:17 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.2 2013/04/25 08:34:37CEST Bratoi, Bogdan-Horia (uidu8192)
- clearing some Pylint problems
--- Added comments ---  uidu8192 [Apr 25, 2013 8:34:37 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.1 2013/04/15 12:45:40CEST Bratoi, Bogdan-Horia (uidu8192)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EM_EnvironmentModel/
05_Testing/05_Test_Environment/algo/stk/db/project.pj
Revision 1.42 2012/12/13 08:50:37CET Bratoi, Bogdan-Horia (uidu8192)
- updates to load the image from DB
--- Added comments ---  uidu8192 [Dec 13, 2012 8:50:37 AM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.41 2012/12/03 09:27:14CET Bratoi, Bogdan-Horia (uidu8192)
- Changed SetPictureFlagOnEvent
--- Added comments ---  uidu8192 [Dec 3, 2012 9:27:14 AM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.40 2012/11/26 16:06:36CET Bratoi, Bogdan-Horia (uidu8192)
- fixed an import
--- Added comments ---  uidu8192 [Nov 26, 2012 4:06:37 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.39 2012/11/26 14:42:59CET Bratoi, Bogdan-Horia (uidu8192)
- Changed an interface function
--- Added comments ---  uidu8192 [Nov 26, 2012 2:43:02 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.38 2012/11/21 12:58:06CET Bratoi, Bogdan-Horia (uidu8192)
- UI updates
--- Added comments ---  uidu8192 [Nov 21, 2012 12:58:06 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.37 2012/11/15 10:29:20CET Hammernik-EXT, Dmitri (uidu5219)
- added posibilty to save images in database, if click on CaptureImage button
--- Added comments ---  uidu5219 [Nov 15, 2012 10:29:22 AM CET]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.36 2012/11/08 10:18:53CET Bratoi, Bogdan-Horia (uidu8192)
- Adding GetAccType function
--- Added comments ---  uidu8192 [Nov 8, 2012 10:18:53 AM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.35 2012/11/06 15:39:26CET Bratoi, Bogdan-Horia (uidu8192)
- bugfix in GetAllEventsAttributes
--- Added comments ---  uidu8192 [Nov 6, 2012 3:39:26 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.34 2012/11/06 15:23:08CET Bratoi, Bogdan-Horia (uidu8192)
- Added SetPictureFlagOnEvent function for assessment tool
--- Added comments ---  uidu8192 [Nov 6, 2012 3:23:08 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.33 2012/11/05 13:31:43CET Bratoi, Bogdan-Horia (uidu8192)
- changed the filtering functionality
--- Added comments ---  uidu8192 [Nov 5, 2012 1:31:43 PM CET]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.32 2012/10/23 14:35:53CEST Bratoi, Bogdan-Horia (uidu8192)
- update the filter implementation of the Assessment tool
--- Added comments ---  uidu8192 [Oct 23, 2012 2:35:54 PM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.30 2012/10/10 10:14:08CEST Hammernik-EXT, Dmitri (uidu5219)
- added the Assessment tool
--- Added comments ---  uidu5219 [Oct 10, 2012 10:14:08 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.28 2012/07/06 15:00:32CEST Spruck, Jochen (spruckj)
Move collection distance summary calculation to val
--- Added comments ---  spruckj [Jul 6, 2012 3:00:33 PM CEST]
Change Package : 98074:5 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.27 2012/06/11 10:27:13CEST Bratoi, Bogdan-Horia (uidu8192)
small bugfix in the search queries
--- Added comments ---  uidu8192 [Jun 11, 2012 10:27:13 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.26 2012/04/23 10:49:49CEST Bratoi, Bogdan-Horia (uidu8192)
Override the WHERE IN limitations
Improve the speed fo the searches
--- Added comments ---  uidu8192 [Apr 23, 2012 10:49:49 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.25 2012/04/19 14:23:22CEST Bratoi, Bogdan-Horia (uidu8192)
Update proress display
--- Added comments ---  uidu8192 [Apr 19, 2012 2:23:23 PM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.24 2012/03/21 15:58:08CET Raedler-EXT, Guenther (uidt9430)
- revert changes caused by not synchronized code
--- Added comments ---  uidt9430 [Mar 21, 2012 3:58:10 PM CET]
Change Package : 100768:2 http://mks-psad:7002/im/viewissue?selection=100768
Revision 1.23 2012/03/20 11:33:48CET Spruck, Jochen (spruckj)
Add recording driven distances for different types to the base report
--- Added comments ---  spruckj [Mar 20, 2012 11:33:48 AM CET]
Change Package : 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.22 2012/03/02 14:00:42CET Bratoi, Bogdan-Horia (uidu8192)
Added new functions:
    - GetCollectionHoursKilometerPerRoadtype(self,collection_name)
    - GetCollectionHoursKilometerPerRecdate(self,collection_name)
    - GetCollectionHoursKilometerPerDriver(self,collection_name)
    - GetCollectionHoursKilometerPerHardwareVersion(self,collection_name)
    - GetEndTimestamp(self,measid)
    - HasChildren(self, collection_id)
Updated functions:
    - GetCollectionHoursPerSoftwareVersion -> GetCollectionHoursKilometerPerSoftwareVersion
    - GetCollectionHoursPerVehicle -> GetCollectionHoursKilometerPerVehicle
    - UpdateCollectionParentId
--- Added comments ---  uidu8192 [Mar 2, 2012 2:00:42 PM CET]
Change Package : 100767:1 http://mks-psad:7002/im/viewissue?selection=100767
Revision 1.21 2011/12/22 17:36:32CET Castell, Christoph (uidt6394)
Updated names of two functions to include the word collection.
--- Added comments ---  uidt6394 [Dec 22, 2011 5:36:34 PM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.20 2011/12/22 17:24:29CET Castell, Christoph (uidt6394)
New GetHoursPerSoftwareVersion() and GetHoursPerVehicle() functions.
--- Added comments ---  uidt6394 [Dec 22, 2011 5:24:29 PM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.19 2011/12/05 18:06:29CET Castell, Christoph (uidt6394)
Added
DeleteCollection()
HascollectionMeasurementsChildren()
functions.
--- Added comments ---  uidt6394 [Dec 5, 2011 6:06:31 PM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.18 2011/11/25 16:58:20CET Castell, Christoph (uidt6394)
New GetCollection(self, collection_id) and UpdateCollectionParentId() functions.
--- Added comments ---  uidt6394 [Nov 25, 2011 4:58:21 PM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.17 2011/11/16 09:35:24CET Castell Christoph (uidt6394) (uidt6394)
Updates to measurement validation check. Report on max cycle time.
--- Added comments ---  uidt6394 [Nov 16, 2011 9:35:25 AM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.16 2011/11/15 13:25:19CET Castell Christoph (uidt6394) (uidt6394)
New file check functionality for cycle violation and collection file length and distance.
--- Added comments ---  uidt6394 [Nov 15, 2011 1:25:19 PM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.15 2011/11/14 11:47:31CET Castell Christoph (uidt6394) (uidt6394)
Updated pupup menu to permit getting file time and distance information.
Revision 1.14 2011/11/10 12:02:56CET Castell Christoph (uidt6394) (uidt6394)
Added functionality to export subsets of rec files as BPL.
--- Added comments ---  uidt6394 [Nov 10, 2011 12:02:57 PM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.13 2011/10/11 11:42:40CEST Castell Christoph (uidt6394) (uidt6394)
Addition of tree display for collections.
--- Added comments ---  uidt6394 [Oct 11, 2011 11:42:41 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.12 2011/10/07 14:26:48CEST Castell Christoph (uidt6394) (uidt6394)
New AddCollectionMapEntry and DeleteCollectionMapEntry functions.
--- Added comments ---  uidt6394 [Oct 7, 2011 2:26:48 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.11 2011/09/23 16:10:43CEST Castell Christoph (uidt6394) (uidt6394)
Updated to get subcollection data.
--- Added comments ---  uidt6394 [Sep 23, 2011 4:10:44 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.10 2011/09/22 13:30:12CEST Castell Christoph (uidt6394) (uidt6394)
Added collection management functions.
--- Added comments ---  uidt6394 [Sep 22, 2011 1:30:13 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.9 2011/09/20 09:09:58CEST Castell Christoph (uidt6394) (uidt6394)
Changed column and table name access as old szntax no longer worked.
--- Added comments ---  uidt6394 [Sep 20, 2011 9:09:59 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.8 2011/09/19 12:52:25CEST Castell Christoph (uidt6394) (uidt6394)
Added comments and removed strings from code.
Revision 1.7 2011/09/19 10:40:37CEST Castell Christoph (uidt6394) (uidt6394)
Removed some unused imports.
--- Added comments ---  uidt6394 [Sep 19, 2011 10:40:38 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.6 2011/09/09 14:08:46CEST Castell Christoph (uidt6394) (uidt6394)
SetTableName() may be called with a blank list when a new database is connected. Fix to prevent crash.
--- Added comments ---  uidt6394 [Sep 9, 2011 2:08:46 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.5 2011/09/08 17:02:13CEST Castell Christoph (uidt6394) (uidt6394)
Updates to implement database query.
Revision 1.4 2011/08/10 11:06:19CEST Castell Christoph (uidt6394) (uidt6394)
Moved various items to valgui_db_connector.
Revision 1.3 2011/07/18 17:13:02CEST Castell Christoph (uidt6394) (uidt6394)
Added QueryDatabaseCollection. This function needs to be moved and placed in reccatlog at some stage.
--- Added comments ---  uidt6394 [Jul 18, 2011 5:13:02 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.2 2011/07/07 12:39:35CEST Castell Christoph (uidt6394) (uidt6394)
Added database connection.
Revision 1.1 2011/07/04 10:18:07CEST Castell Christoph (uidt6394) (uidt6394)
Initial revision
Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/05_Testing/05_Test_Environment/
algo/ars301_req_test/valf_tests/vpc/project.pj
"""
