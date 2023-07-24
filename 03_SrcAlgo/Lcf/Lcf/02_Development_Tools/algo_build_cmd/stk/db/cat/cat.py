"""
stk/db/cat/cat.py
-------------------

Python library to access AL FCT Recording Catalog DB

 Sub-Scheme CAT

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:59CET $
"""

# pylint: disable=C0103,W0702,R0201,R0904

# Import Python Modules -----------------------------------------------------------------------------------------------
from Queue import Queue
from datetime import datetime
import logging
from os import path

# Import STK Modules --------------------------------------------------------------------------------------------------
from ..db_common import BaseDB, ERROR_TOLERANCE_LOW, ERROR_TOLERANCE_NONE, AdasDBError, DB_FUNC_NAME_MAX, \
    DB_FUNC_NAME_LOWER, SQLCEBaseDB, OracleBaseDB, SQLite3BaseDB
from ..db_sql import GenericSQLStatementFactory, SQLBinaryExpr, SQLFuncExpr, OP_EQ, SQLLiteral, SQLColumnExpr, \
    SQLTableExpr, SQLNull, OP_AND, OP_IS, OP_AS, SQLJoinExpr, OP_INNER_JOIN, OP_IN, OP_SUB


# Defines -------------------------------------------------------------------------------------------------------------
# Table base names:
TABLE_NAME_KWMAP = "CAT_KeywordMap"
TABLE_NAME_KW = "CAT_Keywords"
TABLE_NAME_COLLMAP = "CAT_CollectionMap"
TABLE_NAME_COLL = "CAT_Collections"
TABLE_NAME_LOCATIONS = "CAT_Locations"
TABLE_NAME_LOCINFO = "CAT_LocInfo"
TABLE_NAME_COUNTRIES = "CAT_Countries"
TABLE_NAME_FILES = "CAT_Files"
TABLE_NAME_PARTCFGS = "CAT_PartCfgs"
TABLE_NAME_PARTTYPES = "CAT_PartTypes"
TABLE_NAME_VEHICLECFGS = "CAT_VehicleCfgs"
TABLE_NAME_VEHICLECFGSTATES = "CAT_VehicleCfgStates"
TABLE_NAME_VEHICLES = "CAT_Vehicles"
TABLE_NAME_FILESTATES = "CAT_FileStates"
TABLE_NAME_DRIVERS = "CAT_Drivers"
TABLE_NAME_DATAINTTESTS = "CAT_DataIntTests"

COL_NAME_DRIVERS_DRIVERID = "DRIVERID"
COL_NAME_DRIVERS_NAME = "NAME"

COL_NAME_FILESTATES_FILESTATEID = "FILESTATEID"
COL_NAME_FILESTATES_NAME = "NAME"

COL_NAME_VEHICLES_VEHICLEID = "VEHICLEID"
COL_NAME_VEHICLES_NAME = "NAME"
COL_NAME_VEHICLES_MODEL = "MODEL"
COL_NAME_VEHICLES_LICNUMBER = "LICNUMBER"
COL_NAME_VEHICLES_VEHCOMMENT = "VEHCOMMENT"

COL_NAME_VEHICLECFGSTATES_VEHICLECFGSTATEID = "VEHCFGSTATEID"
COL_NAME_VEHICLECFGSTATES_NAME = "NAME"

COL_NAME_VEHICLECFGS_VEHCFGID = "VEHICLECFGID"
COL_NAME_VEHICLECFGS_VEHICLEID = "VEHICLEID"
COL_NAME_VEHICLECFGS_VEHICLECFGSTATEID = "VEHCFGSTATEID"
COL_NAME_VEHICLECFGS_NAME = "NAME"
COL_NAME_VEHICLECFGS_SETUPDATE = "SETUPDATE"
COL_NAME_VEHICLECFGS_SETUPBY = "SETUPBY"
COL_NAME_VEHICLECFGS_CFGCOMMENT = "CFGCOMMENT"

COL_NAME_PARTCFGS_PARTCFGID = "PARTCFGID"
COL_NAME_PARTCFGS_VEHCFGID = "VEHICLECFGID"
COL_NAME_PARTCFGS_NAME = "NAME"
COL_NAME_PARTCFGS_HWVERSION = "HWVERSION"
COL_NAME_PARTCFGS_SWVERSION = "SWVERSION"
COL_NAME_PARTCFGS_PARTCOMMENT = "PARTCOMMENT"
COL_NAME_PARTCFGS_PARTTYPEID = "PARTTYPEID"

COL_NAME_PARTTYPES_PARTTYPEID = "PARTTYPEID"
COL_NAME_PARTTYPES_NAME = "NAME"

COL_NAME_FILES_MEASID = "MEASID"
COL_NAME_FILES_RECFILEID = "RECFILEID"
COL_NAME_FILES_BEGINTIMESTAMP = "BEGINABSTS"
COL_NAME_FILES_ENDTIMESTAMP = "ENDABSTS"
COL_NAME_FILES_FILEPATH = "FILEPATH"
COL_NAME_FILES_RECTIME = "RECTIME"
COL_NAME_FILES_IMPORTDATE = "IMPORTDATE"
COL_NAME_FILES_IMPORTBY = "IMPORTBY"
COL_NAME_FILES_FILESTATEID = "FILESTATEID"
COL_NAME_FILES_VEHICLECFGID = "VEHICLECFGID"
COL_NAME_FILES_DRIVERID = "DRIVERID"
COL_NAME_FILES_CONTENTHASH = "CONTENTHASH"
COL_NAME_FILES_RECDRIVENDIST = "RECDRIVENDIST"
COL_NAME_FILES_RECODOSTARTDIST = "RECODOSTARTDIST"
COL_NAME_FILES_DATAINTTESTRESULT = "DATAINTTESTRESULT"
COL_NAME_FILES_DATAINTTESTSTATUS = "DATAINTTESTSTATUS"


COL_NAME_COUNTRIES_COUNTRYID = "COUNTRYID"
COL_NAME_COUNTRIES_NAME = "NAME"

COL_NAME_LOCATION_LOCID = "LOCID"
COL_NAME_LOCATION_NAME = "NAME"

COL_NAME_LOCINFO_LOCINFOID = "LOCINFOID"
COL_NAME_LOCINFO_MEASID = "MEASID"
COL_NAME_LOCINFO_COUNTRYID = "COUNTRYID"
COL_NAME_LOCINFO_LOCID = "LOCID"
COL_NAME_LOCINFO_LOCTIMESTAMP = "LOCRELTS"
COL_NAME_LOCINFO_GPSLATDEG = "GPSLATDEG"
COL_NAME_LOCINFO_GPSLNGDEG = "GPSLNGDEG"
COL_NAME_LOCINFO_GPSALTDEG = "GPSALTDEG"

COL_NAME_KW_KWID = "KWID"
COL_NAME_KW_PARENTID = "PARENTID"
COL_NAME_KW_NAME = "NAME"
COL_NAME_KW_KWCOMMENT = "KWCOMMENT"

COL_NAME_KWMAP_KWMAPID = "KWMAPID"
COL_NAME_KWMAP_KWID = "KWID"
COL_NAME_KWMAP_MEASID = "MEASID"
COL_NAME_KWMAP_BEGINTIMESTAMP = "BEGINRELTS"
COL_NAME_KWMAP_ENDTIMESTAMP = "ENDRELTS"
COL_NAME_KWMAP_ASGNBY = "ASGNBY"
COL_NAME_KWMAP_ASGNDATE = "ASGNDATE"

COL_NAME_COLL_COLLID = "COLLID"
COL_NAME_COLL_PARENTID = "PARENTID"
COL_NAME_COLL_NAME = "NAME"
COL_NAME_COLL_COLLCOMMENT = "COLLCOMMENT"

COL_NAME_COLLMAP_COLLMAPID = "COLLMAPID"
COL_NAME_COLLMAP_COLLID = "COLLID"
COL_NAME_COLLMAP_MEASID = "MEASID"
COL_NAME_COLLMAP_BEGINTIMESTAMP = "BEGINRELTS"
COL_NAME_COLLMAP_ENDTIMESTAMP = "ENDRELTS"
COL_NAME_COLLMAP_ASGNBY = "ASGNBY"
COL_NAME_COLLMAP_ASGNDATE = "ASGNDATE"

COL_NAME_DATAINTTESTS_TESTID = "TESTID"
COL_NAME_DATAINTTESTS_NAME = "NAME"
COL_NAME_DATAINTTESTS_DITCOMMENT = "DITCOMMENT"

PATH_SEPARATOR = "/"

IDENT_STRING = "dbcat"
# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------

# Constraint DB Libary Base Implementation ----------------------------------------------------------------------------


class BaseRecCatalogDB(BaseDB):
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

    def Terminate(self):
        """Terminate the database proxy"""
        BaseDB.Terminate(self)

    #====================================================================
    # Handling of file data
    #====================================================================
    def SelectMeasurements(self, select_list=["*"], where=None, group_by=None,
                           having=None, order_by=None):
        """Get all measurements which fulfill some condition.
        :param select_list: List of selected table columns.
        :param where: The additional condition that must hold for the scenarios to be returned.
        :param group_by: Expression defining the columns by which selected data is grouped.
        :param having: Expression defining the conditions that determine groups.
        :param order_by: Expression that defines the order of the returned records.
        :return: Returns the list of scenarios.
        """
        return self.SelectGenericData(select_list,
                                      [self.GetQualifiedTableName(TABLE_NAME_FILES)],
                                      where, group_by, having, order_by)

    def AddMeasurement(self, measurement):
        """Add new file to database.
        :param measurement: The measurement record.
        :return: Returns the measurement ID. If a recording with the
                same recfileid exists already an exception is raised.
        """
        # check for duplicate recfileid
        recfileid_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER], COL_NAME_FILES_RECFILEID),
                                       OP_EQ, SQLLiteral(measurement[COL_NAME_FILES_RECFILEID].lower()))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_FILES)],
                                         where=recfileid_cond)
        if len(entries) <= 0:
            measid = self._GetNextID(TABLE_NAME_FILES, COL_NAME_FILES_MEASID)
            measurement[COL_NAME_FILES_MEASID] = measid
            self.AddGenericData(measurement, self.GetQualifiedTableName(TABLE_NAME_FILES))
        else:
            tmp = "Recording '%s' " % measurement[COL_NAME_FILES_FILEPATH]
            tmp += "exists already in the catalog."
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    measid = entries[0][COL_NAME_FILES_MEASID]
                elif len(entries) > 1:
                    tmp = "File '%s' " % (measurement[COL_NAME_FILES_RECFILEID])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        return measid

    def HasMeasurement(self, filepath):
        """ Function to check if a file is in the database.
        :param filepath: The filepath.
        :return: True or False.
        """
        _, recfileid = path.split(filepath)
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_FILES_RECFILEID),
                             OP_EQ, SQLLiteral(recfileid.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_FILES_MEASID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_FILES)],
                                         where=cond)
        if len(entries) == 1:
            return True
        return False

    def GetMeasurementID(self, recfile):
        """ Get a measurement ID of a file
        :param recfile: The file path name to be resolved.
        :return: Returns the ID for the file path or None if file not exists.
        """
        _, recfileid = path.split(recfile)
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_FILES_RECFILEID),
                             OP_EQ, SQLLiteral(recfileid.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_FILES_MEASID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_FILES)],
                                         where=cond)
        if len(entries) == 1:
            measid = entries[0][COL_NAME_FILES_MEASID]
        elif len(entries) > 1:
            raise AdasDBError("File '%s' cannot be resolved because it is ambiguous. (%s)" % (recfileid, entries))
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (recfileid, entries))
        return measid

    def GetMeasurementWithSections(self, measid, collid=None):
        """ Get all the data from a measurement, including a list of the sections.
        :param measid: The measurement id.
        :param collid: The collection id. If None, sections from all collections are retreived.
        :return: (Dict of measurement record, list of sections (BEGINRELTS, ENDRELTS) which may be empty).
        """

        BPL_ATTR_NAME_START_TIME = "startTime"
        BPL_ATTR_NAME_END_TIME = "endTime"

        cond = SQLBinaryExpr(COL_NAME_FILES_MEASID, OP_EQ, measid)
        measurement_list = self.SelectGenericData(select_list=["*"],
                                                  table_list=[self.GetQualifiedTableName(TABLE_NAME_FILES)],
                                                  where=cond)
        if len(measurement_list) != 1:
            raise AdasDBError("No resolution of measid: '%s'" % measid)

        measurement = measurement_list[0]

        # get sections of this measurement
        coll_cond = None
        if collid is None:
            coll_cond = SQLBinaryExpr(COL_NAME_COLLMAP_MEASID, OP_EQ, measid)
        else:
            coll_cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_COLLMAP_COLLID, OP_EQ, collid),
                                      OP_AND,
                                      SQLBinaryExpr(COL_NAME_COLLMAP_MEASID, OP_EQ, measid))

        order_expr = [SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_COLLMAP)),
                                    COL_NAME_COLLMAP_BEGINTIMESTAMP)]

        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_COLLMAP)],
                                         where=coll_cond, order_by=order_expr)

        # create section list
        section_list = []
        for entry in entries:
            if((entry[COL_NAME_COLLMAP_BEGINTIMESTAMP] is not None) or
               (entry[COL_NAME_COLLMAP_ENDTIMESTAMP] is not None)):
                section = {}
                section[BPL_ATTR_NAME_START_TIME] = str("%d" % entry[COL_NAME_COLLMAP_BEGINTIMESTAMP])

                if entry[COL_NAME_COLLMAP_ENDTIMESTAMP] is not None:
                    section[BPL_ATTR_NAME_END_TIME] = str("%d" % entry[COL_NAME_COLLMAP_ENDTIMESTAMP])

                section_list.append(section)

        return measurement, section_list

    def CheckMeasurementAvailability(self, recfile):
        """ Check, if a measurement is available in the database
        :param recfile: The file path name to be resolved.
        :return: Returns true if file is available or false if file does not exist.
        """
        raise DeprecationWarning("Use HasMeasurement and check the existing methods before implementing new ones!")

    def UpdateMeasurements(self, measurement, where=None):
        """Update existing file records.
        :param measurement: The file record update.
        :param where: The condition to be fulfilled by the files to the updated.
        :return: Returns the number of affected files.
        """
        rowcount = 0
        if measurement is not None:
            self.UpdateGenericData(measurement, self.GetQualifiedTableName(TABLE_NAME_FILES), where)
        # done
        return rowcount

    #====================================================================
    # Handling of collection data
    #====================================================================

    def AddCollection(self, collection):
        """Add collection state to database.
        :param collection: The collection record.
        :return: Returns the collection ID.
        """
        parentid_expr = SQLNull()
        parentid_op = OP_IS
        if collection[COL_NAME_COLL_PARENTID] is not None:
            parentid_expr = SQLLiteral(collection[COL_NAME_COLL_PARENTID])
            parentid_op = OP_EQ
        coll_cond = SQLBinaryExpr(SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                            COL_NAME_COLL_NAME),
                                                OP_EQ,
                                                SQLLiteral(collection[COL_NAME_COLL_NAME].lower())),
                                  OP_AND,
                                  SQLBinaryExpr(COL_NAME_COLL_PARENTID, parentid_op, parentid_expr))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_COLL)], where=coll_cond)
        if len(entries) <= 0:
            collid = self._GetNextID(TABLE_NAME_COLL, COL_NAME_COLL_COLLID)
            collection[COL_NAME_COLL_COLLID] = collid
            self.AddGenericData(collection, self.GetQualifiedTableName(TABLE_NAME_COLL))
        else:
            tmp = "Collection '%s' " % collection[COL_NAME_COLL_NAME]
            tmp += "exists already in the catalog for this parent."
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    collid = entries[0][COL_NAME_COLL_COLLID]
                elif len(entries) > 1:
                    tmp = "Collection '%s' " % (collection[COL_NAME_COLL_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return collid

    def UpdateCollections(self, collection, where=None):
        """Update existing collection records.
        :param collection: The collection record update.
        :param where: The condition to be fulfilled by the collections to the updated.
        :return: Returns the number of affected collections.
        """
        rowcount = 0
        if collection is not None:
            self.UpdateGenericData(collection, self.GetQualifiedTableName(TABLE_NAME_COLL), where)
        # done
        return rowcount

    def AddCollectionMap(self, collmap):
        """Add collection mapping to database.
        :param collmap: The collection mapping record.
        :return: Returns the collection map ID.
        """
        coll_cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_COLLMAP_COLLID, OP_EQ, collmap[COL_NAME_COLLMAP_COLLID]),
                                  OP_AND,
                                  SQLBinaryExpr(COL_NAME_COLLMAP_MEASID, OP_EQ, collmap[COL_NAME_COLLMAP_MEASID]))
        if COL_NAME_COLLMAP_BEGINTIMESTAMP in collmap and collmap[COL_NAME_COLLMAP_BEGINTIMESTAMP] is not None:
            coll_cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_COLLMAP_BEGINTIMESTAMP,
                                                    OP_EQ,
                                                    collmap[COL_NAME_COLLMAP_BEGINTIMESTAMP]),
                                      OP_AND,
                                      coll_cond)
        if COL_NAME_COLLMAP_ENDTIMESTAMP in collmap and collmap[COL_NAME_COLLMAP_ENDTIMESTAMP] is not None:
            coll_cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_COLLMAP_ENDTIMESTAMP,
                                                    OP_EQ,
                                                    collmap[COL_NAME_COLLMAP_ENDTIMESTAMP]),
                                      OP_AND,
                                      coll_cond)
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_COLLMAP)], where=coll_cond)
        if len(entries) <= 0:
            collmapid = self._GetNextID(TABLE_NAME_COLLMAP, COL_NAME_COLLMAP_COLLMAPID)
            collmap[COL_NAME_COLLMAP_COLLMAPID] = collmapid
            self.AddGenericData(collmap, self.GetQualifiedTableName(TABLE_NAME_COLLMAP))
        else:
            tmp = "File '%s' " % (collmap[COL_NAME_COLLMAP_MEASID])
            tmp += "is already assigned to collection "
            tmp += "'%s'." % (collmap[COL_NAME_COLLMAP_COLLID])
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    collmapid = entries[0][COL_NAME_COLLMAP_COLLMAPID]
                elif len(entries) > 1:
                    tmp = "Collection mapping of file '%s' " % (collmap[COL_NAME_COLLMAP_MEASID])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return collmapid

    def DeleteCollectionMap(self, measid, collection_name):
        """ Delete a collection map based on measid and collection name.
        :param measid: The measurement id.
        :param collection_name: The collection name.
        """
        # Find the collection id.
        collection_id = self.GetCollectionID(collection_name)

        pre_cond = SQLBinaryExpr(COL_NAME_COLLMAP_MEASID, OP_EQ, measid)
        cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_COLLMAP_COLLID, OP_EQ, collection_id), OP_AND, pre_cond)

        self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_COLLMAP), where=cond)

    def DeleteCollection(self, collection_name):
        """ Delete a collection based on the collection name.
        This function requires that all the collection map entries relating to the collection have been removed.
        This function requires that the collection is not referenced by any other collections.
        This is a safety feature to prevent the accidental removal of collections and inconsistency in the
        database.
        :param collection_name: The collection name.
        :return: bool, error string
        """
        # Find the collection id.
        collection_id = self.GetCollectionID(collection_name)

        # Get the measurements. There should be none.
        measurements = self.GetCollectionMeasurements(collection_id)
        if len(measurements) != 0:
            return False, "Delete measurements prior to deleting collection."

        # Find collections with the collection id as parent. There should be none.
        sub_collections = self.GetCollections(collection_id)
        if len(sub_collections) != 0:
            return False, "Delete sub-collections prior to deleting collection."

        cond = SQLBinaryExpr(COL_NAME_COLL_COLLID, OP_EQ, collection_id)
        self.DeleteGenericData(self.GetQualifiedTableName(TABLE_NAME_COLL), where=cond)

        return True, ""

    def GetCollection(self, coll_id):
        """ Return all the collection entry based on the collection id.
        :param coll_id: The collection id.
        :return: Collection record in dict format.
        """
        cond = SQLBinaryExpr(COL_NAME_COLL_COLLID, OP_EQ, coll_id)
        collection_list = self.SelectGenericData(["*"], [self.GetQualifiedTableName(TABLE_NAME_COLL)], where=cond)
        if len(collection_list) == 0:
            return None
        return collection_list[0]

    def GetCollectionID(self, coll_name):
        """Find a collection with a given name (absolute or basic).
        :param coll_name: The collection name.
        :return: Returns the collection ID or None if not exists.
        """
        is_rooted = False
        coll_name = coll_name.rstrip(PATH_SEPARATOR)
        if self.IsAbsoluteName(coll_name):
            coll_name = coll_name.lstrip(PATH_SEPARATOR)
            is_rooted = True
        coll_name_parts = coll_name.split(PATH_SEPARATOR)

        collid = None
        parentid = None
        for coll_name_part in coll_name_parts:
            coll_name_part = coll_name_part.strip()
            if len(coll_name_part) == 0:
                continue
            parentid_op = OP_IS
            parentid_expr = SQLNull()
            if parentid is not None:
                parentid_op = OP_EQ
                parentid_expr = SQLLiteral(parentid)
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_COLL_NAME),
                                 OP_EQ, SQLLiteral(coll_name_part.lower()))
            if is_rooted:
                cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_COLL_PARENTID, parentid_op, parentid_expr), OP_AND, cond)

            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_COLL)], where=cond)
            if len(entries) == 1:
                collid = entries[0][COL_NAME_COLL_COLLID]
                parentid = collid
            elif len(entries) <= 0:
                raise AdasDBError("Collection '%s' doesn't exists in the catalog." % coll_name)
            else:
                tmp = "Collection name '%s' cannot be resolved because it is ambiguous. (%s)" % (coll_name, entries)
                raise AdasDBError(tmp)
        # done
        return collid

    def GetCollectionName(self, collid):
        """Get the name of a collection either basic or absolute.
        :param colli: The collection ID.
        :return: Returns the collection name or None if not exists.
        """
        coll_name = None
        while collid is not None:
            cond = SQLBinaryExpr(COL_NAME_COLL_COLLID, OP_EQ, SQLLiteral(collid))
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_COLL)], where=cond)
            if len(entries) == 1:
                if coll_name is not None:
                    coll_name = "%s%s%s" % (entries[0][COL_NAME_COLL_NAME], PATH_SEPARATOR, coll_name)
                else:
                    coll_name = entries[0][COL_NAME_COLL_NAME]
                collid = entries[0][COL_NAME_COLL_PARENTID]
            elif len(entries) <= 0:
                raise AdasDBError("Collection '%s' doesn't exists in the catalog." % collid)
            else:
                tmp = "Collection name '%s' cannot be resolved because it is ambiguous. (%s)" % (collid, entries)
                raise AdasDBError(tmp)
        if len(coll_name) > 0:
            coll_name = "%s%s" % (PATH_SEPARATOR, coll_name)
        return coll_name

    def GetCollections(self, collid, recurse=True):
        """Get the sub-collections of a collection.
        :param collid: The ID of the collection.
        :param recurse: Set True, if sub-collections shall be searched recursively.
        :return: Returns the sub-collections of a collection. The list contains
        the collection IDs.
        """
        collid_list = []

        collid_queue = Queue()
        collid_queue.put(collid)
        while not collid_queue.empty():
            collid = collid_queue.get()
            # select all collections which have the current collection as parent
            cond = SQLBinaryExpr(COL_NAME_COLL_PARENTID, OP_EQ, SQLLiteral(collid))
            subcolls = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_COLL)], where=cond)
            for subcoll in subcolls:
                subcollid = subcoll[COL_NAME_COLL_COLLID]
                if recurse:
                    collid_queue.put(subcollid)
                collid_list.append(subcollid)

        return collid_list

    def GetAllCollectionsNames(self):
        """Get the Names of all collections.
        :return: Returns all collections names list
        """
        collnames_list = []

        select_list = []
        select_list.append(SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_COLL)),
                                                       COL_NAME_COLL_NAME),
                                         OP_AS, COL_NAME_COLL_NAME))

        entries = self.SelectGenericData(select_list=select_list,
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_COLL)])
        for entrie in entries:
            name = entrie[COL_NAME_COLL_NAME]
            collnames_list.append(name)

        return collnames_list

    def GetCollectionMeasurements(self, collid, recurse=True, recfile_paths=False, recfile_dict=False):
        """Get the sub-collections of a collection.
        :param collid: The ID of the collection.
        :param recurse: Set @b True, if sub-collections shall be searched recursively.
        :param recfile_paths: Set @b True if the recfile paths shall be returned.
               Otherwise the measurement IDs are returned.
        :return: Returns the recfile paths of IDs of the the measurements in the collection.
        """
        recfile_list = []
        recfile_data_dict = {}

        tables = []
        columns = ["*"]
        tblCollMap = self.GetQualifiedTableName(TABLE_NAME_COLLMAP)
        tblFiles = self.GetQualifiedTableName(TABLE_NAME_FILES)
        if recfile_paths or recfile_dict:
            tables.append(SQLJoinExpr(SQLTableExpr(tblCollMap),
                                      OP_INNER_JOIN,
                                      SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                      SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblCollMap), COL_NAME_COLLMAP_MEASID),
                                                    OP_EQ,
                                                    SQLColumnExpr(SQLTableExpr(tblFiles),
                                                                  COL_NAME_FILES_MEASID))))
            columns = [SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblFiles),
                                                   COL_NAME_FILES_MEASID), OP_AS, COL_NAME_FILES_MEASID),
                       SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblFiles),
                                                   COL_NAME_FILES_FILEPATH), OP_AS, COL_NAME_FILES_FILEPATH)]
        else:
            tables.append(self.GetQualifiedTableName(TABLE_NAME_COLLMAP))
            columns = [SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblCollMap),
                                                   COL_NAME_COLLMAP_MEASID), OP_AS, COL_NAME_COLLMAP_MEASID)]

        collid_queue = Queue()
        collid_queue.put(collid)
        while not collid_queue.empty():
            collid = collid_queue.get()
            if recurse:
                # select all collections which have the current collection as parent
                cond = SQLBinaryExpr(COL_NAME_COLL_PARENTID, OP_EQ, SQLLiteral(collid))
                subcolls = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_COLL)], where=cond)
                for subcoll in subcolls:
                    subcollid = subcoll[COL_NAME_COLL_COLLID]
                    collid_queue.put(subcollid)
            cond = SQLBinaryExpr(COL_NAME_COLL_COLLID, OP_EQ, SQLLiteral(collid))
            recfiles = self.SelectGenericData(select_list=columns, table_list=tables, where=cond, distinct_rows=True)
            for recfile in recfiles:
                if recfile_paths:
                    # Check for duplicates.
                    if recfile[COL_NAME_FILES_FILEPATH] not in recfile_list:
                        recfile_list.append(recfile[COL_NAME_FILES_FILEPATH])
                        if recfile_dict:
                            recfile_data_dict[recfile[COL_NAME_FILES_FILEPATH]] = recfile[COL_NAME_COLLMAP_MEASID]
                else:
                    # Check for duplicates.
                    if recfile[COL_NAME_COLLMAP_MEASID] not in recfile_list:
                        recfile_list.append(recfile[COL_NAME_COLLMAP_MEASID])
                        if recfile_dict:
                            recfile_data_dict[recfile[COL_NAME_COLLMAP_MEASID]] = recfile[COL_NAME_FILES_FILEPATH]

        if recfile_dict:
            return recfile_data_dict
        else:
            return recfile_list

    def GetRecFileNameForMeasid(self, measid):
        """Returns the filepath for a measid
        :param measid: the measurement id
        :return: Returns the corresponding filepath
        """
        columns = [COL_NAME_FILES_FILEPATH]
        measid_cond = SQLBinaryExpr(COL_NAME_FILES_MEASID , OP_EQ, measid)
        return self.SelectGenericData(select_list=columns,
                                      table_list=[self.GetQualifiedTableName(TABLE_NAME_FILES)],
                                      where=measid_cond)[0][COL_NAME_FILES_FILEPATH]

    def GetMeasurementCollectionNames(self, file_path):
        """Get the Collection Names of a measurement.
        :param file_path: The file_path of the measurement.
        :return: Returns the Collection Names to which the measurement is
                assigned, if file is not assigned return empty list.
        """
        CollectionNames = []

        tblColl = self.GetQualifiedTableName(TABLE_NAME_COLL)
        tblCollMap = self.GetQualifiedTableName(TABLE_NAME_COLLMAP)
        tblFiles = self.GetQualifiedTableName(TABLE_NAME_FILES)
        columns = [SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblColl), COL_NAME_COLL_NAME),
                                 OP_AS, COL_NAME_COLL_NAME)]

        tables = []

        CollMapCollJoin = SQLJoinExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_COLLMAP)),
                                      OP_INNER_JOIN,
                                      SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_COLL)),
                                      SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblCollMap), COL_NAME_COLLMAP_COLLID),
                                                    OP_EQ,
                                                    SQLColumnExpr(SQLTableExpr(tblColl), COL_NAME_COLL_COLLID)))

        tables.append(SQLJoinExpr(SQLTableExpr(CollMapCollJoin),
                                  OP_INNER_JOIN,
                                  SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                  SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblCollMap), COL_NAME_COLLMAP_MEASID),
                                                OP_EQ,
                                                SQLColumnExpr(SQLTableExpr(tblFiles), COL_NAME_FILES_MEASID))))

        cond = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblFiles), COL_NAME_FILES_FILEPATH),
                             OP_EQ,
                             SQLLiteral(file_path))

        entries = self.SelectGenericData(columns, tables, cond)

        if len(entries) >= 1:
            for ent in range(len(entries)):
                CollectionNames.append(entries[ent][COL_NAME_COLL_NAME])
        else:
            logging.info("Rec file '%s' is not assigned to a collection" % file_path) # pylint: disable=W6501

        return CollectionNames


    def GetCollectionHoursKilometerForPartConfigVersion(self, collection_name, version_type):
        """ Get hours for Part Configuration version.
        :param collection_name: The name of the collection,
        :param version_type: HW oder SW version
        :return: [version string, time in us, number of files, kilometer]
        """
        version_time_files_list = []
        entries = []
        collection_id = self.GetCollectionID(collection_name)

        select_list = [SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                     COL_NAME_FILES_MEASID),
                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_PARTCFGS)),
                                     version_type),
                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                     COL_NAME_FILES_BEGINTIMESTAMP),
                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                     COL_NAME_FILES_ENDTIMESTAMP),
                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                     COL_NAME_FILES_RECDRIVENDIST)]

        tables = []
        join_cond_col1 = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                       COL_NAME_FILES_VEHICLECFGID)
        join_cond_col2 = SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_PARTCFGS)),
                                       COL_NAME_PARTCFGS_VEHCFGID)
        join_cond = SQLBinaryExpr(join_cond_col1, OP_EQ, join_cond_col2)

        first_join = SQLJoinExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                 OP_INNER_JOIN,
                                 SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_PARTCFGS)),
                                 join_cond)
        tables.append(first_join)

        # get measid's for collection (with subcollections)
        coll_measid_list = self.GetCollectionMeasurements(collection_id, True, False)
        if len(coll_measid_list) == 0:
            return version_time_files_list
        else:

            # to change it for more than 1000 entries (limitation for OP_IN in Oracle)
            if len(coll_measid_list) >= 1000:
                for ent in xrange(len(coll_measid_list) / 1000):
                    query = ','.join(str(n) for n in coll_measid_list[ent * 1000: (ent + 1) * 1000])
                    cond = SQLBinaryExpr(COL_NAME_FILES_MEASID, OP_IN, "%s" % "(" + query + ")")
                    entries += self.SelectGenericData(select_list, tables, where=cond)

                if len(coll_measid_list) % 1000 != 0:
                    query = ','.join(str(n) for n in coll_measid_list[(ent + 1) * 1000: len(coll_measid_list)])
                    cond = SQLBinaryExpr(COL_NAME_FILES_MEASID, OP_IN, "%s" % "(" + query + ")")
                    entries += self.SelectGenericData(select_list, tables, where=cond)
            else:
                query = ','.join(str(n) for n in coll_measid_list)
                cond = SQLBinaryExpr(COL_NAME_FILES_MEASID, OP_IN, "%s" % "(" + query + ")")
                entries = self.SelectGenericData(select_list, tables, where=cond)

        # Check for measurement duplicates.
        measurements = []

        for entry in entries:
            if entry[COL_NAME_FILES_MEASID] in measurements:
                continue
            new_entry = True
            for version_time_files in version_time_files_list:
                if version_time_files[0] == entry[version_type]:
                    version_time_files[1] += (entry[COL_NAME_FILES_ENDTIMESTAMP] -
                                              entry[COL_NAME_FILES_BEGINTIMESTAMP])
                    version_time_files[2] += 1
                    if entry[COL_NAME_FILES_RECDRIVENDIST] is not None:
                        version_time_files[3] += entry[COL_NAME_FILES_RECDRIVENDIST]
                    measurements.append(entry[COL_NAME_FILES_MEASID])
                    new_entry = False
            if new_entry:
                time = (entry[COL_NAME_FILES_ENDTIMESTAMP] - entry[COL_NAME_FILES_BEGINTIMESTAMP])
                version_time_files_list.append([entry[version_type], time, 1, entry[COL_NAME_FILES_RECDRIVENDIST]])
                measurements.append(entry[COL_NAME_FILES_MEASID])

        return version_time_files_list

    def GetCollectionHoursKilometerPerRecdate(self, collection_name):
        """ Get hours and kilometer per recording date.
        :param collection_name: The collection name.
        :return: Array of tuples (recording_date, hours, files, kilometer).
        """
        recdate_hours_files_list = []
        raw_recdate_hours_files = []

        # Getting the collection ID from the collection name
        collection_id = self.GetCollectionID(collection_name)

        # Getting the MEASID's for collection with subcollections
        coll_measid_list = self.GetCollectionMeasurements(collection_id, True, False)
        if len(coll_measid_list) == 0:
            return recdate_hours_files_list

        recdate_list = []

        for measid in coll_measid_list:
            condition = SQLBinaryExpr(COL_NAME_FILES_MEASID, OP_EQ, measid)
            select_list = [COL_NAME_FILES_MEASID, COL_NAME_FILES_RECTIME,
                           COL_NAME_FILES_BEGINTIMESTAMP,
                           COL_NAME_FILES_ENDTIMESTAMP,
                           COL_NAME_FILES_RECDRIVENDIST]
            order_by_list = [COL_NAME_FILES_RECTIME]
            recdate_list.append(self.SelectGenericData(select_list,
                                                       [self.GetQualifiedTableName(TABLE_NAME_FILES)],
                                                       where=condition,
                                                       order_by=order_by_list))

        for first_lst in recdate_list:
            for recdate_idx in first_lst:
                recdate = {}
                recdate[COL_NAME_FILES_MEASID] = recdate_idx[COL_NAME_FILES_MEASID]
                recdate[COL_NAME_FILES_RECTIME] = recdate_idx[COL_NAME_FILES_RECTIME]
                recdate["Timestamp"] = (recdate_idx[COL_NAME_FILES_ENDTIMESTAMP] -
                                        recdate_idx[COL_NAME_FILES_BEGINTIMESTAMP])
                recdate[COL_NAME_FILES_RECDRIVENDIST] = recdate_idx[COL_NAME_FILES_RECDRIVENDIST]
                raw_recdate_hours_files.append(recdate)

        for idx in raw_recdate_hours_files:
            new_entry = True
            for recdate_hours_files in recdate_hours_files_list:
                if recdate_hours_files[0] == datetime.date(idx[COL_NAME_FILES_RECTIME]):
                    recdate_hours_files[1] += idx["Timestamp"]
                    recdate_hours_files[2] += 1
                    if idx[COL_NAME_FILES_RECDRIVENDIST] is not None:
                        recdate_hours_files[3] += idx[COL_NAME_FILES_RECDRIVENDIST]
                    new_entry = False
            if new_entry:
                time = idx["Timestamp"]
                recdate_hours_files_list.append([datetime.date(idx[COL_NAME_FILES_RECTIME]),
                                                time, 1, idx[COL_NAME_FILES_RECDRIVENDIST]])

        return recdate_hours_files_list

    def GetCollectionHoursKilometerPerDriver(self, collection_name):
        """ Get the Driver hours and kilometer for the collection
        :param collection_name: The name of the collection.
        :return: [driver_id, time in us, number of files, kilometer]
        """
        raw_driver_hours_files = []
        driver_hours_files_list = []
        # Getting the collection ID from the collection name
        collection_id = self.GetCollectionID(collection_name)

        # Getting the MEASID's for collection with subcollections
        coll_measid_list = self.GetCollectionMeasurements(collection_id, True, False)
        if len(coll_measid_list) == 0:
            return driver_hours_files_list

        driver_list = []

        for measid in coll_measid_list:
            condition = SQLBinaryExpr(COL_NAME_FILES_MEASID, OP_EQ, measid)
            select_list = [COL_NAME_FILES_MEASID,
                           COL_NAME_FILES_DRIVERID,
                           COL_NAME_FILES_BEGINTIMESTAMP,
                           COL_NAME_FILES_ENDTIMESTAMP,
                           COL_NAME_FILES_RECDRIVENDIST]
            order_by_list = [COL_NAME_FILES_DRIVERID]
            driver_list.append(self.SelectGenericData(select_list,
                                                      [self.GetQualifiedTableName(TABLE_NAME_FILES)],
                                                      where=condition,
                                                      order_by=order_by_list))

        for first_lst in driver_list:
            for driver_idx in first_lst:
                driver = {}
                driver[COL_NAME_FILES_MEASID] = driver_idx[COL_NAME_FILES_MEASID]
                driver[COL_NAME_FILES_DRIVERID] = driver_idx[COL_NAME_FILES_DRIVERID]
                driver["Timestamp"] = (driver_idx[COL_NAME_FILES_ENDTIMESTAMP] -
                                       driver_idx[COL_NAME_FILES_BEGINTIMESTAMP])
                driver[COL_NAME_FILES_RECDRIVENDIST] = driver_idx[COL_NAME_FILES_RECDRIVENDIST]
                raw_driver_hours_files.append(driver)

        for idx in raw_driver_hours_files:
            new_entry = True
            for driver_hours_files in driver_hours_files_list:
                if driver_hours_files[0] == idx[COL_NAME_FILES_DRIVERID]:
                    driver_hours_files[1] += idx["Timestamp"]
                    driver_hours_files[2] += 1
                    if idx[COL_NAME_FILES_RECDRIVENDIST] is not None:
                        driver_hours_files[3] += idx[COL_NAME_FILES_RECDRIVENDIST]
                    new_entry = False
            if new_entry:
                time = idx["Timestamp"]
                driver_hours_files_list.append([idx[COL_NAME_FILES_DRIVERID],
                                               time, 1,
                                               idx[COL_NAME_FILES_RECDRIVENDIST]])

        # replace driverid with driver name in driver_hours_files
        for idx in driver_hours_files_list:
            if idx[0] is not None:
                idx[0] = self.GetDriverName(idx[0])

        return driver_hours_files_list

    def GetCollectionHoursKilometerPerVehicle(self, collection_name):
        """ Get hours and kilometer per vehicle.
        :param collection_name: The name of the collection.
        :return: [vehicle string, time in us,, number of files, kilometer]
        """
        vehicle_time_files_list = []

        collection_id = self.GetCollectionID(collection_name)

        select_list = [SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                     COL_NAME_FILES_MEASID),
                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_VEHICLES)),
                                     COL_NAME_VEHICLES_NAME),
                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                     COL_NAME_FILES_BEGINTIMESTAMP),
                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                     COL_NAME_FILES_ENDTIMESTAMP),
                       SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES)),
                                     COL_NAME_FILES_RECDRIVENDIST)]

        tables = []
        tblFiles = self.GetQualifiedTableName(TABLE_NAME_FILES)
        tblVCfg = self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGS)
        tblVeh = self.GetQualifiedTableName(TABLE_NAME_VEHICLES)
        join_cond_col1 = SQLColumnExpr(SQLTableExpr(tblFiles), COL_NAME_FILES_VEHICLECFGID)
        join_cond_col2 = SQLColumnExpr(SQLTableExpr(tblVCfg), COL_NAME_VEHICLECFGS_VEHCFGID)
        join_cond = SQLBinaryExpr(join_cond_col1, OP_EQ, join_cond_col2)

        first_join = SQLJoinExpr(SQLTableExpr(tblFiles),
                                 OP_INNER_JOIN,
                                 SQLTableExpr(tblVCfg),
                                 join_cond)

        join_cond_col1_3 = SQLColumnExpr(SQLTableExpr(tblVCfg), COL_NAME_VEHICLECFGS_VEHICLEID)
        join_cond_col2_3 = SQLColumnExpr(SQLTableExpr(tblVeh), COL_NAME_VEHICLES_VEHICLEID)
        join_cond_3 = SQLBinaryExpr(join_cond_col1_3, OP_EQ, join_cond_col2_3)

        tables.append(SQLJoinExpr(SQLTableExpr(first_join),
                                  OP_INNER_JOIN,
                                  SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_VEHICLES)),
                                  join_cond_3))

        # Get the measid's for the collection (with subcollections)
        coll_measid_list = self.GetCollectionMeasurements(collection_id, True, False)
        if len(coll_measid_list) == 0:
            return vehicle_time_files_list

        query = ','.join(str(n) for n in coll_measid_list)
        cond = SQLBinaryExpr(COL_NAME_FILES_MEASID, OP_IN, "%s" % "(" + query + ")")

        try:
            entries = self.SelectGenericData(select_list, tables, where=cond)

            # Check for measurement duplicates.
            measurements = []

            for entry in entries:
                if entry[COL_NAME_FILES_MEASID] in measurements:
                    continue
                new_entry = True
                for vehicle_time_files in vehicle_time_files_list:
                    if vehicle_time_files[0] == entry[COL_NAME_VEHICLES_NAME]:
                        vehicle_time_files[1] += (entry[COL_NAME_FILES_ENDTIMESTAMP] -
                                                  entry[COL_NAME_FILES_BEGINTIMESTAMP])
                        vehicle_time_files[2] += 1
                        if entry[COL_NAME_FILES_RECDRIVENDIST] is not None:
                            vehicle_time_files[3] += entry[COL_NAME_FILES_RECDRIVENDIST]
                        measurements.append(entry[COL_NAME_FILES_MEASID])
                        new_entry = False
                if new_entry:
                    time = (entry[COL_NAME_FILES_ENDTIMESTAMP] - entry[COL_NAME_FILES_BEGINTIMESTAMP])
                    vehicle_time_files_list.append([entry[COL_NAME_VEHICLES_NAME],
                                                   time, 1,
                                                   entry[COL_NAME_FILES_RECDRIVENDIST]])
                    measurements.append(entry[COL_NAME_FILES_MEASID])

        except:
            pass

        return vehicle_time_files_list

    def GetCollectionKilometer(self, collection_name=None):
        """ Get collection kilometers.
        :param collection_name: The name of the collectio, if None sum of all files.
        :return: driven distance
        """
        record = {}

        TypeJoin = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES))

        cond = []
        tblColMap = self.GetQualifiedTableName(TABLE_NAME_COLLMAP)
        tblFiles = self.GetQualifiedTableName(TABLE_NAME_FILES)
        tblColl = self.GetQualifiedTableName(TABLE_NAME_COLL)
        if not collection_name is None:
            TypeJoin = SQLJoinExpr(SQLTableExpr(TypeJoin),
                                   OP_INNER_JOIN,
                                   SQLTableExpr(tblColMap),
                                   SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblColMap), COL_NAME_COLLMAP_MEASID),
                                                 OP_EQ,
                                                 SQLColumnExpr(SQLTableExpr(tblFiles), COL_NAME_FILES_MEASID)))

            TypeJoin = SQLJoinExpr(SQLTableExpr(TypeJoin),
                                   OP_INNER_JOIN,
                                   SQLTableExpr(tblColl),
                                   SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblColl), COL_NAME_COLL_COLLID),
                                                 OP_EQ,
                                                 SQLColumnExpr(SQLTableExpr(tblColMap), COL_NAME_COLLMAP_COLLID)))

            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                 SQLColumnExpr(SQLTableExpr(tblColl), COL_NAME_COLL_NAME)),
                                 OP_EQ,
                                 SQLLiteral(collection_name.lower()))

        tables = []
        tables.append(TypeJoin)

        select_list = []
        select_list.append(SQLBinaryExpr(SQLFuncExpr("SUM",
                                                     SQLColumnExpr(SQLTableExpr(tblFiles),
                                                     COL_NAME_FILES_RECDRIVENDIST)),
                                         OP_AS, COL_NAME_FILES_RECDRIVENDIST))

        try:
            entries = self.SelectGenericData(select_list, tables, where=cond)
            record = entries[0]
        except:
            pass

        # done
        return record

    def GetCollectionTime(self, collection_name=None):
        """ Get collection time in us.
        :param collection_name: The name of the collectio, if None sum of all files.
        :return: the total time over all the files
        """
        record = {}

        TypeJoin = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_FILES))

        cond = []
        tblCollMap = self.GetQualifiedTableName(TABLE_NAME_COLLMAP)
        tblColl = self.GetQualifiedTableName(TABLE_NAME_COLL)
        tblFiles = self.GetQualifiedTableName(TABLE_NAME_FILES)
        if not collection_name is None:
            TypeJoin = SQLJoinExpr(SQLTableExpr(TypeJoin),
                                   OP_INNER_JOIN,
                                   SQLTableExpr(tblCollMap),
                                   SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblCollMap), COL_NAME_COLLMAP_MEASID),
                                                 OP_EQ,
                                                 SQLColumnExpr(SQLTableExpr(tblFiles), COL_NAME_FILES_MEASID)))

            TypeJoin = SQLJoinExpr(SQLTableExpr(TypeJoin),
                                   OP_INNER_JOIN,
                                   SQLTableExpr(tblColl),
                                   SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblColl), COL_NAME_COLL_COLLID),
                                                 OP_EQ,
                                                 SQLColumnExpr(SQLTableExpr(tblCollMap), COL_NAME_COLLMAP_COLLID)))

            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             SQLColumnExpr(SQLTableExpr(tblColl),
                                                           COL_NAME_COLL_NAME)),
                                 OP_EQ,
                                 SQLLiteral(collection_name.lower()))

        tables = []
        tables.append(TypeJoin)

        delta = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblFiles), COL_NAME_FILES_ENDTIMESTAMP),
                              OP_SUB,
                              SQLColumnExpr(SQLTableExpr(tblFiles), COL_NAME_FILES_BEGINTIMESTAMP))
        select_list = []
        select_list.append(SQLBinaryExpr(SQLFuncExpr("SUM", delta), OP_AS, "TOTAL"))

        try:
            entries = self.SelectGenericData(select_list, tables, where=cond)
            record = entries[0]["TOTAL"]
        except:
            pass

        # done
        return record

    #====================================================================
    # Handling of keyword data
    #====================================================================

    def AddKeyword(self, keyword):
        """Add keyword state to database.
        :param keyword: The keyword record.
        :return: Returns the keyword ID.
        """
        parentid_expr = SQLNull()
        parentid_op = OP_IS
        if keyword[COL_NAME_KW_PARENTID] is not None:
            parentid_expr = SQLLiteral(keyword[COL_NAME_KW_PARENTID])
            parentid_op = OP_EQ
        kw_cond = SQLBinaryExpr(SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                          COL_NAME_KW_NAME),
                                              OP_EQ,
                                              SQLLiteral(keyword[COL_NAME_KW_NAME].lower())),
                                OP_AND,
                                SQLBinaryExpr(COL_NAME_KW_PARENTID, parentid_op, parentid_expr))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_KW)], where=kw_cond)
        if len(entries) <= 0:
            kwid = self._GetNextID(TABLE_NAME_KW, COL_NAME_KW_KWID)
            keyword[COL_NAME_KW_KWID] = kwid
            self.AddGenericData(keyword, self.GetQualifiedTableName(TABLE_NAME_KW))
        else:
            tmp = "Keyword '%s' " % keyword[COL_NAME_KW_NAME]
            tmp += "exists already in the catalog for this parent."
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    kwid = entries[0][COL_NAME_KW_KWID]
                elif len(entries) > 1:
                    tmp = "Keyword name '%s' " % (keyword[COL_NAME_KW_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return kwid

    def UpdateKeywords(self, keyword, where=None):
        """Update existing keyword records.
        :param keyword: The keyword record update.
        :param where: The condition to be fulfilled by the keywords to the updated.
        :return: Returns the number of affected keywords.
        """
        rowcount = 0
        if keyword is not None:
            self.UpdateGenericData(keyword, self.GetQualifiedTableName(TABLE_NAME_KW), where)
        # done
        return rowcount

    def AddKeywordMap(self, kwmap):
        """Add keyword mapping to database.
        :param kwmap: The keyword mapping record.
        :return: Returns the keyword map ID.
        """
        kw_cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_KWMAP_KWID, OP_EQ, kwmap[COL_NAME_KWMAP_KWID]),
                                OP_AND,
                                SQLBinaryExpr(COL_NAME_KWMAP_MEASID, OP_EQ, kwmap[COL_NAME_KWMAP_MEASID]))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_KWMAP)], where=kw_cond)
        if len(entries) <= 0:
            kwmapid = self._GetNextID(TABLE_NAME_KWMAP, COL_NAME_KWMAP_KWMAPID)
            kwmap[COL_NAME_KWMAP_KWMAPID] = kwmapid
            self.AddGenericData(kwmap, self.GetQualifiedTableName(TABLE_NAME_KWMAP))
        else:
            tmp = "Keyword '%s' " % (kwmap[COL_NAME_KWMAP_KWID])
            tmp += "is already assigned to file "
            tmp += "'%s'." % (kwmap[COL_NAME_KWMAP_MEASID])
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError(tmp)
            else:
                logging.warn(tmp)
                if len(entries) == 1:
                    kwmapid = entries[0][COL_NAME_KWMAP_KWMAPID]
                elif len(entries) > 1:
                    tmp = "Keyword mapping of file '%s' " % (kwmap[COL_NAME_KWMAP_MEASID])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return kwmapid

    def GetKeywordID(self, kw_name):
        """Find a keyword with a given name (absolute or basic).
        :param kw_name: The keyword name.
        :return: Returns the keyword ID or None if not exists.
        """
        is_rooted = False
        kw_name = kw_name.rstrip(PATH_SEPARATOR)
        if self.IsAbsoluteName(kw_name):
            kw_name = kw_name.lstrip(PATH_SEPARATOR)
            is_rooted = True
        kw_name_parts = kw_name.split(PATH_SEPARATOR)

        kwid = None
        parentid = None
        for kw_name_part in kw_name_parts:
            kw_name_part = kw_name_part.strip()
            if len(kw_name_part) == 0:
                continue
            parentid_op = OP_IS
            parentid_expr = SQLNull()
            if parentid is not None:
                parentid_op = OP_EQ
                parentid_expr = SQLLiteral(parentid)
            cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_KW_NAME),
                                 OP_EQ, SQLLiteral(kw_name_part.lower()))
            if is_rooted:
                cond = SQLBinaryExpr(SQLBinaryExpr(COL_NAME_KW_PARENTID, parentid_op, parentid_expr),
                                     OP_AND,
                                     cond)
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_KW)], where=cond)
            if len(entries) == 1:
                kwid = entries[0][COL_NAME_KW_KWID]
                parentid = kwid
            elif len(entries) <= 0:
                raise AdasDBError("Keyword '%s' doesn't exists in the catalog." % kw_name)
            else:
                tmp = "Keyword name '%s' " % (kw_name)
                tmp += "cannot be resolved because it is ambiguous. "
                tmp += "(%s)" % (entries)
                raise AdasDBError(tmp)
        # done
        return kwid

    def GetKeywordName(self, kwid):
        """Get the name of a keyword either basic or absolute.
        :param colli: The keyword ID.
        :return: Returns the keyword name or None if not exists.
        """
        kw_name = None
        while kwid is not None:
            cond = SQLBinaryExpr(COL_NAME_KW_KWID, OP_EQ, SQLLiteral(kwid))
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_KW)], where=cond)
            if len(entries) == 1:
                if kw_name is not None:
                    kw_name = "%s%s%s" % (entries[0][COL_NAME_KW_NAME], PATH_SEPARATOR, kw_name)
                else:
                    kw_name = entries[0][COL_NAME_KW_NAME]
                kwid = entries[0][COL_NAME_KW_PARENTID]
            elif len(entries) <= 0:
                raise AdasDBError("Keyword '%s' doesn't exists in the catalog." % kwid)
            else:
                tmp = "Keyword name '%s' " % (kwid)
                tmp += "cannot be resolved because it is ambiguous. "
                tmp += "(%s)" % (entries)
                raise AdasDBError(tmp)
        if len(kw_name) > 0:
            kw_name = "%s%s" % (PATH_SEPARATOR, kw_name)
        return kw_name

    #====================================================================
    # Handling of location data
    #====================================================================

    def AddCountry(self, country):
        """Add new country to database.
        :param country: The country record.
        :return: Returns the country ID.
        """
        cntry_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                               COL_NAME_COUNTRIES_NAME),
                                   OP_EQ, SQLLiteral(country[COL_NAME_COUNTRIES_NAME].lower()))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_COUNTRIES)],
                                         where=cntry_cond)
        if len(entries) <= 0:
            cntryid = self._GetNextID(TABLE_NAME_COUNTRIES, COL_NAME_COUNTRIES_COUNTRYID)
            country[COL_NAME_COUNTRIES_COUNTRYID] = cntryid
            self.AddGenericData(country, self.GetQualifiedTableName(TABLE_NAME_COUNTRIES))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("Country '%s' exists already in the catalog." % country[COL_NAME_COUNTRIES_NAME])
            else:
                logging.warn("Country '%s' already exists in the catalog." % country[COL_NAME_COUNTRIES_NAME]) # pylint: disable=W6501
                if len(entries) == 1:
                    cntryid = entries[0][COL_NAME_COUNTRIES_COUNTRYID]
                elif len(entries) > 1:
                    tmp = "Country '%s' " % (country[COL_NAME_COUNTRIES_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return cntryid

    def UpdateCountries(self, country, where=None):
        """Update countries in database.
        :param country: The country record.
        :param where: The condition to be fulfilled by the countries to the updated.
        :return: Returns the number of affected countries.
        """
        rowcount = 0
        if country is not None:
            self.UpdateGenericData(country, self.GetQualifiedTableName(TABLE_NAME_COUNTRIES), where)
        # done
        return rowcount

    def GetCountryID(self, country):
        """ Get a ID of a country
        :param country: The country name to be resolved.
        :return: Returns the ID for the country or None if country not exists.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_COUNTRIES_NAME),
                             OP_EQ, SQLLiteral(country.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_COUNTRIES_COUNTRYID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_COUNTRIES)],
                                         where=cond)
        if len(entries) == 1:
            cntryid = entries[0][COL_NAME_COUNTRIES_COUNTRYID]
        elif len(entries) > 1:
            raise AdasDBError("Country '%s' cannot be resolved because it is ambiguous. (%s)" % (country, entries))
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (country, entries))
        return int(cntryid)

    def GetCountryName(self, cntryid):
        """ Get the name of a country
        :param cntryid: The country ID to be resolved.
        :return: Returns the name for the country or None if the country not exists.
        """
        cond = SQLBinaryExpr(COL_NAME_COUNTRIES_COUNTRYID, OP_EQ, SQLLiteral(cntryid))
        entries = self.SelectGenericData(select_list=[COL_NAME_COUNTRIES_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_COUNTRIES)],
                                         where=cond)
        if len(entries) == 1:
            country = entries[0][COL_NAME_COUNTRIES_NAME]
        elif len(entries) > 1:
            raise AdasDBError("Country '%s' cannot be resolved because it is ambiguous. (%s)" % (cntryid, entries))
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (cntryid, entries))
        return country

    def AddLocation(self, location):
        """Add new location to database.
        :param location: The location record.
        :return: Returns the location ID.
        """
        locid = self._GetNextID(TABLE_NAME_LOCATIONS, COL_NAME_LOCATION_LOCID)
        location[COL_NAME_LOCATION_LOCID] = locid
        self.AddGenericData(location, self.GetQualifiedTableName(TABLE_NAME_LOCATIONS))
        return locid

    def GetLocationID(self, location):
        """ Get a ID of a location
        :param location: The location name to be resolved.
        :return: Returns the ID for the location or None if location not exists.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_LOCATION_NAME),
                             OP_EQ, SQLLiteral(location.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_LOCATION_LOCID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_LOCATIONS)],
                                         where=cond)
        if len(entries) == 1:
            locid = entries[0][COL_NAME_LOCATION_LOCID]
        elif len(entries) > 1:
            raise AdasDBError("Location '%s' cannot be resolved because it is ambiguous. (%s)" % (location, entries))
        else:
            locid = None
        return locid

    def UpdateLocations(self, location, where=None):
        """Update locations in database.
        :param country: The location record.
        :param where: The condition to be fulfilled by the locations to the updated.
        :return: Returns the number of affected countries.
        """
        rowcount = 0
        if location is not None:
            self.UpdateGenericData(location, self.GetQualifiedTableName(TABLE_NAME_LOCATIONS), where)
        # done
        return rowcount

    def AddLocationInfo(self, location):
        """Add new location info to database.
        :param location: The location record.
        :return: Returns the location ID.
        """
        locid = self._GetNextID(TABLE_NAME_LOCINFO, COL_NAME_LOCINFO_LOCINFOID)
        location[COL_NAME_LOCINFO_LOCINFOID] = locid
        self.AddGenericData(location, self.GetQualifiedTableName(TABLE_NAME_LOCINFO))
        return locid

    def GetLocationInfo(self, locinfoid):
        """ Get a location info record with the location info id
        :param locinfoid: The location info id to be resolved.
        :return: Returns the location records for the location or None if location not exists.
        """
        tblname = self.GetQualifiedTableName(TABLE_NAME_LOCINFO)
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         SQLColumnExpr(SQLTableExpr(tblname),
                                         COL_NAME_LOCINFO_LOCID)),
                             OP_EQ,
                             locinfoid)

        entries = self.SelectGenericData(select_list=[COL_NAME_LOCATION_LOCID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_LOCATIONS)],
                                         where=cond)
        locationinfo = None
        if len(entries) == 1:
            locationinfo = entries[0]
        elif len(entries) > 1:
            tmp = "Location with id '%s' " % (locinfoid)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of location info id '%s'. (%s)" % (locinfoid, entries))
        return locationinfo

    def __GetLocationInfoBaseConditions(self, measid, location):
        """ Get the base conditions for getting locations
        :param location: The location name to be resolved.
        :param measid: The measid to be resolved.
        :return: Returns the location condition table and cond
        """
        TypeJoin = SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LOCINFO))

        # cond = []
        tblLoc = self.GetQualifiedTableName(TABLE_NAME_LOCATIONS)
        TypeJoin = SQLJoinExpr(SQLTableExpr(TypeJoin),
                               OP_INNER_JOIN,
                               SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LOCATIONS)),
                               SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(tblLoc),
                                                           COL_NAME_LOCINFO_LOCID),
                                             OP_EQ,
                                             SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(
                                                                        TABLE_NAME_LOCINFO)),
                                                           COL_NAME_LOCATION_LOCID)))

        tables = []
        tables.append(TypeJoin)

        cond_name = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                              SQLColumnExpr(SQLTableExpr(tblLoc),
                                                            COL_NAME_LOCATION_NAME)),
                                  OP_EQ,
                                  SQLLiteral(location.lower()))

        cond_measid = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LOCINFO)),
                                                  COL_NAME_LOCINFO_MEASID),
                                    OP_EQ, measid)

        cond = SQLBinaryExpr(cond_name, OP_AND, cond_measid)

        return (tables, cond)

    def GetLocationInfoIDs(self, measid, location):
        """ Get a ID of a location infos for location and measid
        :param location: The location name to be resolved.
        :param measid: The measid to be resolved.
        :return: Returns the location id's records for the locations or None if locations not exists.
        """
        (tables, cond) = self.__GetLocationInfoBaseConditions(measid, location)

        select_list = []
        select_list.append(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LOCINFO)),
                                         COL_NAME_LOCINFO_LOCINFOID))

        entries = self.SelectGenericData(select_list=select_list, table_list=tables, where=cond)
        locinfoid = None
        if len(entries) > 1:
            locinfoid = []
            for entrie in entries:
                locinfoid.append(entrie[COL_NAME_LOCINFO_LOCINFOID])
        else:
            raise AdasDBError("No resolution of '%s' with meas id (%s)" % (location, measid))
        return locinfoid

    def _GetLocationInfoRelTimeConditions(self, measid, location, reltime):
        """ Get the base + time conditions for getting locations
        :param location: The location name to be resolved.
        :param measid: The measid to be resolved.
        :param reltime: The relative timestamp.
        :return: Returns the location condition table and cond
        """
        (tables, cond) = self.__GetLocationInfoBaseConditions(measid, location)

        cond_reltime = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LOCINFO)),
                                                   COL_NAME_LOCINFO_LOCTIMESTAMP), OP_EQ, reltime)

        cond = SQLBinaryExpr(cond_reltime, OP_AND, cond)

        return (tables, cond)

    def GetLocationInfoIDatRelTime(self, measid, location, reltime):
        """ Get a location infos for location and measid and reltime
        :param location: The location name to be resolved.
        :param measid: The measid to be resolved.
        :param reltime: The relative timestamp.
        :return: Returns the location record for the location or None if locations not exists.
        """
        (tables, cond) = self._GetLocationInfoRelTimeConditions(measid, location, reltime)

        entries = self.SelectGenericData(table_list=tables, where=cond)
        locationinfo = None
        if len(entries) == 1:
            locationinfo = entries[0]
        elif len(entries) > 1:
            tmp = "Location with id '%s' " % (location)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            locationinfo = None

        return locationinfo

    def _GetUpdateLocationsBaseCondition(self, measid, location_id, reltime):
        """ Get the base conditions for updating locations
        :param location_id: The location id to be resolved.
        :param measid: The measid to be resolved.
        :param reltime: The relative timestamp.
        :return: Returns the location condition
        """

        cond_name = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LOCINFO)),
                                                COL_NAME_LOCINFO_LOCID), OP_EQ, location_id)

        cond_measid = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LOCINFO)),
                                                  COL_NAME_LOCINFO_MEASID), OP_EQ, measid)

        cond = SQLBinaryExpr(cond_name, OP_AND, cond_measid)

        cond_reltime = SQLBinaryExpr(SQLColumnExpr(SQLTableExpr(self.GetQualifiedTableName(TABLE_NAME_LOCINFO)),
                                                   COL_NAME_LOCINFO_LOCTIMESTAMP), OP_EQ, reltime)

        cond = SQLBinaryExpr(cond_reltime, OP_AND, cond)

        return cond

    def UpdateLocationsInfo(self, location, where=None):
        """Update locations info in database.
        :param country: The location record.
        :param where: The condition to be fulfilled by the locations to the updated.
        :return: Returns the number of affected countries.
        """
        rowcount = 0
        if location is not None:
            self.UpdateGenericData(location, self.GetQualifiedTableName(TABLE_NAME_LOCINFO), where)
        # done
        return rowcount

    #====================================================================
    # Handling of vehicle configuration data
    #====================================================================

    def AddVehicle(self, vehicle):
        """Add new vehicle to database.
        :param vehicle: The vehicle record.
        :return: Returns the vehicle ID.
        """
        veh_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_VEHICLES_NAME),
                                 OP_EQ, SQLLiteral(vehicle[COL_NAME_VEHICLES_NAME].lower()))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_VEHICLES)], where=veh_cond)
        if len(entries) <= 0:
            vehid = self._GetNextID(TABLE_NAME_VEHICLES, COL_NAME_VEHICLES_VEHICLEID)
            vehicle[COL_NAME_VEHICLES_VEHICLEID] = vehid
            self.AddGenericData(vehicle, self.GetQualifiedTableName(TABLE_NAME_VEHICLES))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("Vehicle '%s' exists already in the catalog." % vehicle[COL_NAME_VEHICLES_NAME])
            else:
                logging.warn("Vehicle '%s' already exists in the catalog." % vehicle[COL_NAME_VEHICLES_VEHICLEID]) # pylint: disable=W6501
                if len(entries) == 1:
                    vehid = entries[0][COL_NAME_VEHICLES_VEHICLEID]
                elif len(entries) > 1:
                    tmp = "Vehicle '%s' " % (vehicle[COL_NAME_VEHICLES_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        return vehid

    def UpdateVehicles(self, vehicle, where=None):
        """Update existing vehicle records.
        :param vehicle: The vehicle record update.
        :param where: The condition to be fulfilled by the vehicles to the updated.
        :return: Returns the number of affected vehicles.
        """
        rowcount = 0
        if vehicle is not None:
            self.UpdateGenericData(vehicle, self.GetQualifiedTableName(TABLE_NAME_VEHICLES), where)
        # done
        return rowcount

    def GetVehicleID(self, veh_name):
        """ Get a vehicle ID for a vehicle name
        :param veh_name: The vehicle name to be resolved.
        :return: Returns the ID for the vehicle or None if not exists.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_VEHICLES_NAME),
                             OP_EQ, SQLLiteral(veh_name.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_VEHICLES_VEHICLEID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_VEHICLES)],
                                         where=cond)
        if len(entries) == 1:
            vehid = entries[0][COL_NAME_VEHICLES_VEHICLEID]
        elif len(entries) > 1:
            raise AdasDBError("Vehicle '%s' cannot be resolved because it is ambiguous. (%s)" % (veh_name, entries))
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (veh_name, entries))
        # done
        return vehid

    def GetVehicleName(self, vehid):
        """ Get a vehicle name for a ID
        :param vehid: The vehicle ID to be resolved.
        :return: Returns the name for the vehicle or None if not exists.
        """
        vehid_cond = SQLBinaryExpr(COL_NAME_VEHICLES_VEHICLEID, OP_EQ, SQLLiteral(vehid))
        entries = self.SelectGenericData(select_list=[COL_NAME_VEHICLES_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_VEHICLES)],
                                         where=vehid_cond)
        if len(entries) == 1:
            veh_name = entries[0][COL_NAME_VEHICLES_NAME]
        elif len(entries) > 1:
            raise AdasDBError("Vehicle ID '%s' cannot be resolved because it is ambiguous. (%s)" % (vehid, entries))
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (vehid, entries))
        # done
        return veh_name

    def AddVehicleCfg(self, vehiclecfg):
        """Add new vehicle cfg to database.
        :param filestate: The vehicle cfg record.
        :return: Returns the vehicle cfg ID.
        """
        vehcfgid = self._GetNextID(TABLE_NAME_VEHICLECFGS, COL_NAME_VEHICLECFGS_VEHCFGID)
        vehiclecfg[COL_NAME_VEHICLECFGS_VEHCFGID] = vehcfgid
        self.AddGenericData(vehiclecfg, self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGS))
        return vehcfgid

    def UpdateVehicleCfgs(self, vehiclecfg, where=None):
        """Update existing vehicle cfg records.
        :param vehiclecfg: The vehicle cfg record update.
        :param where: The condition to be fulfilled by the vehicle cfgs to the updated.
        :return: Returns the number of affected vehicle cfgs.
        """
        rowcount = 0
        if vehiclecfg is not None:
            self.UpdateGenericData(vehiclecfg, self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGS), where)
        # done
        return rowcount

    def GetVehicleCfgID(self, vehcfg_name):
        """ Get a vehicle cfg ID for a vehicle cfg name
        :param vehcfg_name: The vehicle cfg name to be resolved.
        :return: Returns the ID for the vehicle cfg or None if not exists.
        """
        is_rooted = False
        cfg_name = vehcfg_name.rstrip(PATH_SEPARATOR)
        if self.IsAbsoluteName(cfg_name):
            cfg_name = cfg_name.lstrip(PATH_SEPARATOR)
            is_rooted = True
        cfg_name_parts = cfg_name.split(PATH_SEPARATOR)
        # if absolute name, get vehicle ID
        vehid_cond = None
        if is_rooted:
            if len(cfg_name_parts) != 2:
                tmp = "Vehicle configuration name '%s' " % vehcfg_name
                tmp += "cannot be resolved. Name must have format '/vehicle/config'."
                raise AdasDBError(tmp)
            vehid = self.GetVehicleID(cfg_name_parts[0])
            vehid_cond = SQLBinaryExpr(COL_NAME_VEHICLECFGS_VEHICLEID, OP_EQ, SQLLiteral(vehid))
            cfg_name = cfg_name_parts[1].strip()
        # get configuration id (for vehicle, if absolute)
        cfg_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_VEHICLECFGS_NAME),
                                 OP_EQ, SQLLiteral(cfg_name.lower()))
        if vehid_cond is not None:
            cfg_cond = SQLBinaryExpr(vehid_cond, OP_AND, cfg_cond)
        entries = self.SelectGenericData(select_list=[COL_NAME_VEHICLECFGS_VEHCFGID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGS)],
                                         where=cfg_cond)
        if len(entries) == 1:
            vehcfgid = entries[0][COL_NAME_VEHICLECFGS_VEHCFGID]
        elif len(entries) > 1:
            tmp = "Vehicle configuration '%s' " % (vehcfg_name)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (vehcfg_name, entries))
        # done
        return vehcfgid

    def GetVehicleCfgName(self, vehcfgid, absolute=True):
        """ Get a vehicle configuration name for a ID
        :param vehid: The vehicle configuration ID to be resolved.
        :param absolute: Set @b True if the absolute name shall be returned.
        :return: Returns the name for the vehicle configuration or None if not exists.
        """
        vehcfgid_cond = SQLBinaryExpr(COL_NAME_VEHICLECFGS_VEHCFGID, OP_EQ, SQLLiteral(vehcfgid))
        entries = self.SelectGenericData(select_list=[COL_NAME_VEHICLECFGS_NAME,
                                                      COL_NAME_VEHICLECFGS_VEHICLEID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGS)],
                                         where=vehcfgid_cond)
        if len(entries) == 1:
            vehcfg_name = entries[0][COL_NAME_VEHICLECFGS_NAME]
            if absolute:
                veh_name = self.GetVehicleName(entries[0][COL_NAME_VEHICLECFGS_VEHICLEID])
                vehcfg_name = "%s%s%s" % (veh_name, PATH_SEPARATOR, vehcfg_name)
        elif len(entries) > 1:
            tmp = "Vehicle configuration ID '%s' " % (vehcfgid)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (vehcfgid, entries))
        # done
        return vehcfg_name

    def AddVehicleCfgState(self, vehiclecfgstate):
        """Add new vehicle cfg to database.
        :param vehiclecfgstate: The vehicle cfg state record.
        :return: Returns the vehicle cfg state ID.
        """
        vehcfgstateid = self._GetNextID(TABLE_NAME_VEHICLECFGSTATES, COL_NAME_VEHICLECFGSTATES_VEHICLECFGSTATEID)
        vehiclecfgstate[COL_NAME_VEHICLECFGSTATES_VEHICLECFGSTATEID] = vehcfgstateid
        self.AddGenericData(vehiclecfgstate, self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGSTATES))
        return vehcfgstateid

    def UpdateVehicleCfgStates(self, vehiclecfgstate, where=None):
        """Update vehicle cfg in database.
        :param vehiclecfgstate: The vehicle cfg state record.
        :param where: The condition to be fulfilled by the vehicle cfgs to the updated.
        :return: Returns the number of affected vehicle cfgs.
        """
        rowcount = 0
        if vehiclecfgstate is not None:
            self.UpdateGenericData(vehiclecfgstate, self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGSTATES), where)
        # done
        return rowcount

    def GetVehicleCfgStateID(self, vehcfgstate_name):
        """ Get a vehicle cfg ID for a vehicle cfg name
        :param vehcfgstate_name: The vehicle cfg state name to be resolved.
        :return: Returns the ID for the vehicle cfg or None if not exists.
        """
        # is_rooted = False
        cfg_name = vehcfgstate_name.rstrip(PATH_SEPARATOR)
        # get configuration id (for vehicle, if absolute)
        cfg_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_VEHICLECFGSTATES_NAME),
                                 OP_EQ, SQLLiteral(cfg_name.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_VEHICLECFGSTATES_VEHICLECFGSTATEID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGSTATES)],
                                         where=cfg_cond)
        if len(entries) == 1:
            vehcfgid = entries[0][COL_NAME_VEHICLECFGSTATES_VEHICLECFGSTATEID]
        elif len(entries) > 1:
            tmp = "Vehicle configuration state '%s' " % (vehcfgstate_name)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of vehicle configuration state '%s'. (%s)" % (vehcfgstate_name, entries))
        # done
        return vehcfgid

    def GetVehicleCfgStateName(self, vehcfgstateid):
        """ Get a vehicle configuration name for a ID
        :param vehcfgstateid: The vehicle configuration state ID to be resolved.
        :param absolute: Set @b True if the absolute name shall be returned.
        :return: Returns the name for the vehicle configuration or None if not exists.
        """
        vehcfgid_cond = SQLBinaryExpr(COL_NAME_VEHICLECFGSTATES_VEHICLECFGSTATEID, OP_EQ, SQLLiteral(vehcfgstateid))
        entries = self.SelectGenericData(select_list=[COL_NAME_VEHICLECFGSTATES_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_VEHICLECFGSTATES)],
                                         where=vehcfgid_cond)
        if len(entries) == 1:
            vehcfg_name = entries[0][COL_NAME_VEHICLECFGSTATES_NAME]
        elif len(entries) > 1:
            tmp = "Vehicle configuration state ID '%s' " % (vehcfgstateid)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (vehcfgstateid, entries))
        # done
        return vehcfg_name

    def AddVehicleCfgPart(self, vehiclecfgpart):
        """Add new vehicle cfg part to database.
        :param vehiclecfgpart: The vehicle cfg part record.
        :return: Returns the vehicle cfg ID.
        """
        partid = self._GetNextID(TABLE_NAME_PARTCFGS, COL_NAME_PARTCFGS_PARTCFGID)
        vehiclecfgpart[COL_NAME_PARTCFGS_PARTCFGID] = partid
        self.AddGenericData(vehiclecfgpart, self.GetQualifiedTableName(TABLE_NAME_PARTCFGS))
        # done
        return partid

    def UpdateVehicleCfgParts(self, vehiclecfgpart, where=None):
        """Update vehicle cfg parts in database.
        :param vehiclecfgpart: The vehicle cfg part record.
        :param where: The condition to be fulfilled by the vehicle cfg parts to the updated.
        :return: Returns the number of affected vehicle cfg parts.
        """
        rowcount = 0
        if vehiclecfgpart is not None:
            self.UpdateGenericData(vehiclecfgpart, self.GetQualifiedTableName(TABLE_NAME_PARTCFGS), where)
        # done
        return rowcount

    def GetVehiclePartCfgID(self, partcfg_name):
        """ Get a vehicle cfg ID for a vehicle cfg name
        :param partcfg_name: The vehicle cfg name to be resolved.
        :return: Returns the ID for the vehicle cfg or None if not exists.
        """
        is_rooted = False
        cfg_name = partcfg_name.rstrip(PATH_SEPARATOR)
        if self.IsAbsoluteName(cfg_name):
            cfg_name = cfg_name.lstrip(PATH_SEPARATOR)
            is_rooted = True
        cfg_name_parts = cfg_name.split(PATH_SEPARATOR)
        # if absolute name, get vehicle ID
        # partcfgid_cond = None
        if is_rooted:
            if len(cfg_name_parts) != 3:
                tmp = "Part configuration name '%s' " % partcfg_name
                tmp += "cannot be resolved. Name must have format "
                tmp += "'/vehicle/config/part'."
                raise AdasDBError(tmp)
            vehcfgid = self.GetVehicleCfgID("%s%s%s" % (cfg_name_parts[0], PATH_SEPARATOR, cfg_name_parts[1]))
            vehcfgid_cond = SQLBinaryExpr(COL_NAME_PARTCFGS_VEHCFGID, OP_EQ, SQLLiteral(vehcfgid))
            cfg_name = cfg_name_parts[2].strip()
        # get configuration id (for vehicle configuration, if absolute)
        cfg_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_PARTCFGS_NAME),
                                 OP_EQ, SQLLiteral(cfg_name.lower()))
        if vehcfgid_cond is not None:
            cfg_cond = SQLBinaryExpr(vehcfgid_cond, OP_AND, cfg_cond)
        entries = self.SelectGenericData(select_list=[COL_NAME_PARTCFGS_VEHCFGID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_PARTCFGS)],
                                         where=cfg_cond)
        if len(entries) == 1:
            partcfgid = entries[0][COL_NAME_PARTCFGS_PARTCFGID]
        elif len(entries) > 1:
            tmp = "Part configuration '%s' " % (partcfg_name)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (partcfg_name, entries))
        # done
        return partcfgid

    def GetVehicleCfgPartName(self, partid, absolute=True):
        """ Get a part name for a ID
        :param partid: The part ID to be resolved.
        :param absolute: Set @b True if the absolute name shall be returned.
        :return: Returns the name for the part or None if not exists.
        """
        partid_cond = SQLBinaryExpr(COL_NAME_PARTCFGS_PARTCFGID, OP_EQ, SQLLiteral(partid))
        entries = self.SelectGenericData(select_list=[COL_NAME_PARTCFGS_VEHCFGID,
                                                      COL_NAME_PARTCFGS_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_PARTCFGS)],
                                         where=partid_cond)
        if len(entries) == 1:
            part_name = entries[0][COL_NAME_PARTCFGS_NAME]
            if absolute:
                vehcfg_name = self.GetVehicleCfgName(entries[0][COL_NAME_PARTCFGS_VEHCFGID])
                part_name = "%s%s%s" % (part_name, PATH_SEPARATOR, vehcfg_name)
        elif len(entries) > 1:
            tmp = "Part configuration ID '%s' " % (partid)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (partid, entries))
        # done
        return part_name

    def AddVehicleCfgPartType(self, parttype):
        """Add new part type to database.
        :param parttype: The part type record.
        :return: Returns the part type ID.
        """
        pt_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                            COL_NAME_PARTTYPES_NAME),
                                OP_EQ, SQLLiteral(parttype[COL_NAME_PARTTYPES_NAME].lower()))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_PARTTYPES)], where=pt_cond)
        if len(entries) <= 0:
            ptid = self._GetNextID(TABLE_NAME_PARTTYPES, COL_NAME_PARTTYPES_PARTTYPEID)
            parttype[COL_NAME_PARTTYPES_PARTTYPEID] = ptid
            self.AddGenericData(parttype, self.GetQualifiedTableName(TABLE_NAME_PARTTYPES))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("Part type '%s' exists already in the catalog." % parttype[COL_NAME_PARTTYPES_NAME])
            else:
                logging.warn("Part type '%s' already exists in the catalog." % parttype[COL_NAME_PARTTYPES_NAME]) # pylint: disable=W6501
                if len(entries) == 1:
                    ptid = entries[0][COL_NAME_PARTTYPES_PARTTYPEID]
                elif len(entries) > 1:
                    tmp = "Part type '%s' " % (parttype[COL_NAME_PARTTYPES_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return ptid

    def UpdateVehicleCfgPartTypes(self, vehiclecfgparttype, where=None):
        """Update vehicle cfg parts in database.
        :param vehiclecfgpart: The vehicle cfg part type record.
        :param where: The condition to be fulfilled by the vehicle cfg part types to the updated.
        :return: Returns the number of affected vehicle cfg part types.
        """
        rowcount = 0
        if vehiclecfgparttype is not None:
            self.UpdateGenericData(vehiclecfgparttype, self.GetQualifiedTableName(TABLE_NAME_PARTTYPES), where)
        # done
        return rowcount

    def GetPartTypeID(self, parttype_name):
        """ Get a parttype ID for a parttype name
        :param parttype_name: The parttype name to be resolved.
        :return: Returns the ID for the parttype or None if parttype not exists.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_PARTTYPES_NAME),
                             OP_EQ, SQLLiteral(parttype_name.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_PARTTYPES_PARTTYPEID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_PARTTYPES)],
                                         where=cond)
        if len(entries) == 1:
            ptid = entries[0][COL_NAME_PARTTYPES_PARTTYPEID]
        elif len(entries) > 1:
            tmp = "Part type '%s' " % (parttype_name)
            tmp += "cannot be resolved because it is ambiguous. "
            tmp += "(%s)" % (entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (parttype_name, entries))
        # done
        return ptid

    def GetVehicleCfgPartTypeName(self, parttypeid):
        """ Get a part type name for a ID
        :param parttypeid: The parttype ID to be resolved.
        :return: Returns the name for the part type or None if not exists.
        """
        partid_cond = SQLBinaryExpr(COL_NAME_PARTTYPES_PARTTYPEID, OP_EQ, SQLLiteral(parttypeid))
        entries = self.SelectGenericData(select_list=[COL_NAME_PARTTYPES_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_PARTTYPES)],
                                         where=partid_cond)
        if len(entries) == 1:
            parttype_name = entries[0][COL_NAME_PARTTYPES_NAME]
        elif len(entries) > 1:
            tmp = "Part type ID '%s' cannot be resolved because it is ambiguous. (%s)" % (parttypeid, entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (parttypeid, entries))
        # done
        return parttype_name

    #====================================================================
    # Handling of driver data
    #====================================================================

    def AddDriver(self, driver):
        """Add new driver to database.
        :param driver: The driver record.
        :return: Returns the driver ID.
        """
        drv_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                             COL_NAME_DRIVERS_NAME),
                                 OP_EQ, SQLLiteral(driver[COL_NAME_DRIVERS_NAME].lower()))
        entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_DRIVERS)], where=drv_cond)
        if len(entries) <= 0:
            drvid = self._GetNextID(TABLE_NAME_DRIVERS, COL_NAME_DRIVERS_DRIVERID)
            driver[COL_NAME_DRIVERS_DRIVERID] = drvid
            self.AddGenericData(driver, self.GetQualifiedTableName(TABLE_NAME_DRIVERS))
        else:
            if self.error_tolerance < ERROR_TOLERANCE_LOW:
                raise AdasDBError("Driver '%s' exists already in the catalog." % driver[COL_NAME_DRIVERS_NAME])
            else:
                logging.warn("Driver '%s' already exists in the catalog." % entries[COL_NAME_DRIVERS_NAME]) # pylint: disable=W6501
                if len(entries) == 1:
                    drvid = entries[0][COL_NAME_DRIVERS_DRIVERID]
                elif len(entries) > 1:
                    tmp = "Driver'%s' " % (driver[COL_NAME_DRIVERS_NAME])
                    tmp += "cannot be resolved because it is ambiguous. "
                    tmp += "(%s)" % (entries)
                    raise AdasDBError(tmp)
        # done
        return drvid

    def UpdateDrivers(self, driver, where=None):
        """Update drivers in database.
        :param driver: The driver record.
        :param where: The condition to be fulfilled by the drivers to the updated.
        :return: Returns the number of affected drivers.
        """
        rowcount = 0
        if driver is not None:
            self.UpdateGenericData(driver, self.GetQualifiedTableName(TABLE_NAME_DRIVERS), where)
        # done
        return rowcount

    def GetDriverID(self, driver_name):
        """ Get a driver ID for a driver name
        :param driver_name: The driver name to be resolved.
        :return: Returns the ID for the driver or None if driver not exists.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_DRIVERS_NAME),
                             OP_EQ, SQLLiteral(driver_name.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_DRIVERS_DRIVERID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_DRIVERS)],
                                         where=cond)
        if len(entries) == 1:
            driverid = entries[0][COL_NAME_DRIVERS_DRIVERID]
        elif len(entries) > 1:
            raise AdasDBError("Driver '%s' cannot be resolved because it is ambiguous. (%s)" % (driver_name, entries))
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (driver_name, entries))
        # done
        return driverid

    def GetDriverName(self, driverid):
        """ Get a driver name for a ID
        :param driverid: The driver ID to be resolved.
        :return: Returns the name for the driver or None if not exists.
        """
        drv_cond = SQLBinaryExpr(COL_NAME_DRIVERS_DRIVERID, OP_EQ, SQLLiteral(driverid))
        entries = self.SelectGenericData(select_list=[COL_NAME_DRIVERS_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_DRIVERS)],
                                         where=drv_cond)
        if len(entries) == 1:
            drv_name = entries[0][COL_NAME_DRIVERS_NAME]
        elif len(entries) > 1:
            raise AdasDBError("Driver ID '%s' cannot be resolved because it is ambiguous. (%s)" % (driverid, entries))
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (driverid, entries))
        # done
        return drv_name

    #====================================================================
    # Handling of auxiliary data
    #====================================================================

    def AddFileState(self, filestate):
        """Add new file state to database.
        :param filestate: The file state record.
        :return: Returns the file state ID.
        """
        fsid = None
        if filestate is not None:
            fs_cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                                COL_NAME_FILESTATES_NAME),
                                    OP_EQ, SQLLiteral(filestate[COL_NAME_FILESTATES_NAME]))
            entries = self.SelectGenericData(table_list=[self.GetQualifiedTableName(TABLE_NAME_FILESTATES)],
                                             where=fs_cond)
            if len(entries) <= 0:
                fsid = self._GetNextID(TABLE_NAME_FILESTATES, COL_NAME_FILESTATES_FILESTATEID)
                filestate[COL_NAME_FILESTATES_FILESTATEID] = fsid
                self.AddGenericData(filestate, self.GetQualifiedTableName(TABLE_NAME_FILESTATES))
            else:
                if self.error_tolerance < ERROR_TOLERANCE_LOW:
                    tmp = "File state '%s' exists already in the catalog." % filestate[COL_NAME_FILESTATES_NAME]
                    raise AdasDBError(tmp)
                else:
                    logging.warn("File state '%s' already exists in the catalog." % # pylint: disable=W6501
                                 filestate[COL_NAME_FILESTATES_NAME])
                    if len(entries) == 1:
                        fsid = entries[0][COL_NAME_FILESTATES_FILESTATEID]
                    elif len(entries) > 1:
                        tmp = "File state '%s' " % (filestate[COL_NAME_FILESTATES_NAME])
                        tmp += "cannot be resolved because it is ambiguous. "
                        tmp += "(%s)" % (entries)
                        raise AdasDBError(tmp)
        # done
        return fsid

    def UpdateFileStates(self, filestate, where=None):
        """Update file states in database.
        :param filestate: The file state record.
        :param where: The condition to be fulfilled by the file states to the updated.
        :return: Returns the number of affected file states.
        """
        rowcount = 0
        if filestate is not None:
            self.UpdateGenericData(filestate, self.GetQualifiedTableName(TABLE_NAME_FILESTATES), where)
        # done
        return rowcount

    def GetFileStateID(self, fstate_name):
        """ Get a file state ID for a file state name
        :param fstate_name: The file state name to be resolved.
        :return: Returns the ID for the file state or None if file state not exists.
        """
        cond = SQLBinaryExpr(SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_LOWER],
                                         COL_NAME_FILESTATES_NAME),
                             OP_EQ, SQLLiteral(fstate_name.lower()))
        entries = self.SelectGenericData(select_list=[COL_NAME_FILESTATES_FILESTATEID],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_FILESTATES)],
                                         where=cond)
        if len(entries) == 1:
            fstateid = entries[0][COL_NAME_FILESTATES_FILESTATEID]
        elif len(entries) > 1:
            tmp = "File state '%s' cannot be resolved because it is ambiguous. (%s)" % (fstate_name, entries)
            raise AdasDBError(tmp)
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (fstate_name, entries))
        # done
        return fstateid

    def GetFileStateName(self, fstateid):
        """ Get a file state name for a file state ID
        :param fstateid: The file state ID to be resolved.
        :return: Returns the name for the file state or None if file state not exists.
        """
        cond = SQLBinaryExpr(COL_NAME_FILESTATES_FILESTATEID, OP_EQ, SQLLiteral(fstateid))
        entries = self.SelectGenericData(select_list=[COL_NAME_FILESTATES_NAME],
                                         table_list=[self.GetQualifiedTableName(TABLE_NAME_FILESTATES)],
                                         where=cond)
        if len(entries) == 1:
            fstate_name = entries[0][COL_NAME_FILESTATES_NAME]
        elif len(entries) > 1:
            raise AdasDBError("File state '%s' cannot be resolved because it is ambiguous. (%s)" % (fstateid, entries))
        else:
            raise AdasDBError("No resolution of '%s'. (%s)" % (fstateid, entries))
        # done
        return fstate_name

    #====================================================================
    # Rec File Catalog Helper Functions
    #====================================================================

    def IsAbsoluteName(self, name):
        """ Check if a name is absolute.
        :param name: The name to check.
        :return: Returns true if the name is an absolute path name.
        @remark Absolute names start with path separator.
        """
        if name is None:
            raise AdasDBError("Invalid name '%s'." % name)
        return name.startswith(PATH_SEPARATOR)

    def IsBasicName(self, name):
        """ Check if a name is basic (doesnt contain path separator).
        :param name: The name to check.
        :return: Returns true if the name is an basic name.
        @remark Basic names do not contain path separator.
        """
        if name is None:
            raise AdasDBError("Invalid name '%s'." % name)
        return name.find(PATH_SEPARATOR)

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

    def GetCurrDateTime(self):
        """Get the current date/time of the database.
        :return: Returns the current date time of the database
        """
        db_datetime = None
        sql_select_stmt = self.sql_factory.GetSelectBuilder()
        # sql_select_stmt.select_list = [SQLFuncExpr(self.db_func_map[DB_FUNC_NAME_GETDATE])]
        stmt = str(sql_select_stmt)
        cursor = self.db_connection.cursor()
        try:
            logging.debug(stmt)
            cursor.execute(stmt)
            db_datetime = cursor.fetchone()[0]
        finally:
            cursor.close()
        # done
        return db_datetime


#====================================================================
# Constraint DB Libary SQL Server Compact Implementation
#====================================================================
class SQLCERecCatalogDB(BaseRecCatalogDB, SQLCEBaseDB):
    """SQL Server Compact Edition Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseRecCatalogDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLCEBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseRecCatalogDB.Initialize(self)
        SQLCEBaseDB.Initialize(self)


class OracleRecCatalogDB(BaseRecCatalogDB, OracleBaseDB):
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseRecCatalogDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        OracleBaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseRecCatalogDB.Initialize(self)
        OracleBaseDB.Initialize(self)


class SQLite3RecCatalogDB(BaseRecCatalogDB, SQLite3BaseDB):
    """Oracle Implementation of rec file DB access"""
    def __init__(self, db_connection, table_prefix=None,
                 sql_factory=GenericSQLStatementFactory(),
                 error_tolerance=ERROR_TOLERANCE_NONE):
        """Initialize database
        :param table_prefix: The table name prefix
        :param db_connection: The database connection to be used
        :param stmt_factory: The SQL statement factory to be used
        """
        BaseRecCatalogDB.__init__(self, db_connection, table_prefix, sql_factory, error_tolerance)
        SQLite3BaseDB.__init__(self)

    def Initialize(self):
        """Initialize the database proxy"""
        BaseRecCatalogDB.Initialize(self)
        SQLite3BaseDB.Initialize(self)


"""
$Log: cat.py  $
Revision 1.1 2021/12/13 17:55:59CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/cat/project.pj
Revision 1.23 2013/07/29 09:28:32CEST Raedler, Guenther (uidt9430) 
- revert changes of rev. 1.22
- Added comments -  uidt9430 [Jul 29, 2013 9:28:32 AM CEST]
Change Package : 191735:1 http://mks-psad:7002/im/viewissue?selection=191735
Revision 1.22 2013/07/04 15:01:42CEST Mertens, Sven (uidv7805) 
providing tableSpace to BaseDB for what sub-schema space each module is intended to be responsible
--- Added comments ---  uidv7805 [Jul 4, 2013 3:01:43 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.21 2013/04/26 15:39:09CEST Mertens, Sven (uidv7805)
resolving some pep8 / pylint errors
--- Added comments ---  uidv7805 [Apr 26, 2013 3:39:10 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.20 2013/04/26 10:46:06CEST Mertens, Sven (uidv7805)
moving strIdent
Revision 1.19 2013/04/25 14:35:12CEST Mertens, Sven (uidv7805)
epydoc adaptation to colon instead of at
--- Added comments ---  uidv7805 [Apr 25, 2013 2:35:12 PM CEST]
Change Package : 179495:2 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.17 2013/04/19 13:41:47CEST Hecker, Robert (heckerr)
- adding GetRecFleForMeasid function
--- Added comments ---  uidu8192 [Apr 25, 2013 8:31:57 AM CEST]
Change Package : 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.15 2013/04/05 11:17:40CEST Hospes, Gerd-Joachim (uidv8815)
fix documentation
--- Added comments ---  uidv8815 [Apr 5, 2013 11:17:40 AM CEST]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.14 2013/04/03 08:02:12CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:12 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.13 2013/04/02 10:01:20CEST Raedler, Guenther (uidt9430)
- use logging for all log messages again
- added column names for cat_files
--- Added comments ---  uidt9430 [Apr 2, 2013 10:01:21 AM CEST]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.12 2013/03/27 11:37:24CET Mertens, Sven (uidv7805)
pep8 & pylint: rowalignment and error correction
--- Added comments ---  uidv7805 [Mar 27, 2013 11:37:24 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.11 2013/03/26 16:19:34CET Mertens, Sven (uidv7805)
pylint: using direct imports, no stars any more
--- Added comments ---  uidv7805 [Mar 26, 2013 4:19:34 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/03/26 13:00:20CET Mertens, Sven (uidv7805)
reverting error for keyword argument spaces
--- Added comments ---  uidv7805 [Mar 26, 2013 1:00:21 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.9 2013/03/26 11:53:19CET Mertens, Sven (uidv7805)
reworking imports on cat, cl and db_common to start testing with.
--- Added comments ---  uidv7805 [Mar 26, 2013 11:53:19 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/21 17:22:38CET Mertens, Sven (uidv7805)
solving some pylint warnings / errors
--- Added comments ---  uidv7805 [Mar 21, 2013 5:22:39 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/04 07:41:35CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 4, 2013 7:41:35 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/02/28 08:12:14CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:14 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/27 14:51:10CET Hecker, Robert (heckerr)
Updated regarding Pep8 partly.
--- Added comments ---  heckerr [Feb 27, 2013 2:51:11 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/26 20:10:33CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:10:33 PM CET]
Change Package: 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.3 2013/02/19 14:07:25CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:26 PM CET]
Change Package: 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/02/11 10:09:51CET Raedler, Guenther (uidt9430)
- fixed wrong intension in comment section
--- Added comments ---  uidt9430 [Feb 11, 2013 10:09:53 AM CET]
Change Package: 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 09:55:37CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/db/cat/project.pj
------------------------------------------------------------------------------
-- From CGEB Archive
------------------------------------------------------------------------------
Revision 1.52 2012/10/19 10:40:04CEST Hammernik-EXT, Dmitri (uidu5219)
- changed type of the return value in GetCountryID function
--- Added comments ---  uidu5219 [Oct 19, 2012 10:40:05 AM CEST]
Change Package: 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.51 2012/08/21 10:08:27CEST Sav, Claudiu (uid95402)
Updated GetCollectionMeasurements - it can also return a dictionary with MeasID and FilePath.
--- Added comments ---  uid95402 [Aug 21, 2012 10:08:31 AM CEST]
Change Package: 93290:1 http://mks-psad:7002/im/viewissue?selection=93290
Revision 1.50 2012/07/06 15:24:33CEST Spruck, Jochen (spruckj)
Add get Collection time,
Correct location info and location name interface regarding the db struct
--- Added comments ---  spruckj [Jul 6, 2012 3:24:33 PM CEST]
Change Package: 98074:5 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.49 2012/04/23 10:55:52CEST Bratoi, Bogdan-Horia (uidu8192)
Override the WHERE IN limitations from Oracle
--- Added comments ---  uidu8192 [Apr 23, 2012 10:55:56 AM CEST]
Change Package: 112275:1 http://mks-psad:7002/im/viewissue?selection=112275
Revision 1.48 2012/03/20 11:10:45CET Spruck, Jochen (spruckj)
Add funktion to get the collection kilometers
--- Added comments ---  spruckj [Mar 20, 2012 11:10:45 AM CET]
Change Package: 98074:2 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.47 2012/03/02 13:49:04CET Bratoi, Bogdan-Horia (uidu8192)
Added some new functions.
- GetCollectionHoursKilometerPerRoadtype(self,collection_name)
- GetCollectionHoursKilometerPerRecdate(self,collection_name)
- GetCollectionHoursKilometerPerDriver(self,collection_name)
Updated functions: GetCollectionHoursKilometerPerVehicle
Removed function: GetCollectionHoursPerSoftwareVersion
Supporting 2 new columns in CAT_FILES (RECDRIVENDIST, RECODOSTARTDIST)
--- Added comments ---  uidu8192 [Mar 2, 2012 1:49:07 PM CET]
Change Package: 100767:1 http://mks-psad:7002/im/viewissue?selection=100767
Revision 1.46 2012/02/06 08:23:58CET Raedler Guenther (uidt9430) (uidt9430)
- cast new ID as integer value
--- Added comments ---  uidt9430 [Feb 6, 2012 8:23:59 AM CET]
Change Package: 95134:1 http://mks-psad:7002/im/viewissue?selection=95134
Revision 1.45 2011/12/22 17:33:47CET Castell, Christoph (uidt6394)
Added two new functions. GetCollectionHoursPerSoftwareVersion() and GetCollectionHoursPerVehicle().
--- Added comments ---  uidt6394 [Dec 22, 2011 5:33:47 PM CET]
Change Package: 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.44 2011/12/12 10:29:00CET Castell, Christoph (uidt6394)
Fixed bug in GetMeasurementWithSections() function.
Revision 1.43 2011/12/08 18:18:39CET Froehlich, Dominik01 (froehlichd1)
* change: removed CheckMeasurementAvailability because its redundant with HasMeasurement
--- Added comments ---  froehlichd1 [Dec 8, 2011 6:18:39 PM CET]
Change Package: 45990:65 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.40 2011/10/26 15:00:27CEST Castell Christoph (uidt6394) (uidt6394)
Added code to GetCollectionMeasurements() to remove duplicates.
--- Added comments ---  uidt6394 [Oct 26, 2011 3:00:30 PM CEST]
Change Package: 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.39 2011/10/07 14:25:03CEST Castell Christoph (uidt6394) (uidt6394)
Added DeleteCollectionMap function.
--- Added comments ---  uidt6394 [Oct 7, 2011 2:25:03 PM CEST]
Change Package: 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.38 2011/09/22 13:45:00CEST Castell Christoph (uidt6394) (uidt6394)
Added:
HasMeasurement(self, filepath)
GetMeasurementWithSections(self, measid, collid=None)
functions.
--- Added comments ---  uidt6394 [Sep 22, 2011 1:45:01 PM CEST]
Change Package: 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.37 2011/09/07 19:11:34CEST Ibrouchene Nassim (uidt5589) (uidt5589)
Deleted GetTotalDuration and GetListOfFiles functions
--- Added comments ---  uidt5589 [Sep 7, 2011 7:11:35 PM CEST]
Change Package: 69072:2 http://mks-psad:7002/im/viewissue?selection=69072
Revision 1.36 2011/08/29 16:45:11CEST Ibrouchene Nassim (uidt5589) (uidt5589)
Added GetListOfFiles() and GetTotalDuration() functions
--- Added comments ---  uidt5589 [Aug 29, 2011 4:45:12 PM CEST]
Change Package: 69072:2 http://mks-psad:7002/im/viewissue?selection=69072
Revision 1.35 2011/08/24 09:26:25CEST Hanel Nele (haneln) (haneln)
add again changes from Rev. 1.27, which got lost somehow
--- Added comments ---  haneln [Aug 24, 2011 9:26:26 AM CEST]
Change Package: 70482:6 http://mks-psad:7002/im/viewissue?selection=70482
Revision 1.34 2011/08/19 10:31:31CEST Raedler Guenther (uidt9430) (uidt9430)
-- fixed wrong column selection when using qualified column names in select statement - use alias
--- Added comments ---  uidt9430 [Aug 19, 2011 10:31:32 AM CEST]
Change Package: 67780:2 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.33 2011/08/18 13:57:38CEST Froehlich Dominik (froehlichd1) (froehlichd1)
* fix: fixed qualified column names in get collection measurements
--- Added comments ---  froehlichd1 [Aug 18, 2011 1:57:39 PM CEST]
Change Package: 45990:62 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.32 2011/08/18 09:18:07CEST Froehlich Dominik (froehlichd1) (froehlichd1)
* added data integrity tests to table export and catalog
Revision 1.31 2011/08/12 14:51:00CEST Froehlich Dominik (froehlichd1) (froehlichd1)
* fix: fixed bug with adding files to collections
--- Added comments ---  froehlichd1 [Aug 12, 2011 2:51:01 PM CEST]
Change Package: 45990:56 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.30 2011/08/11 20:04:04CEST Froehlich Dominik (froehlichd1) (froehlichd1)
* fix: added distinct for colelction measurements due to section functionality
--- Added comments ---  froehlichd1 [Aug 11, 2011 8:04:04 PM CEST]
Change Package: 45990:53 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.29 2011/08/11 19:58:30CEST Froehlich Dominik (froehlichd1) (froehlichd1)
* fix: fixed add collection map check of duplicate sections
* add: added insert of batches incl. sections to collections
Revision 1.28 2011/08/11 15:40:49CEST Froehlich Dominik (froehlichd1) (froehlichd1)
* fix: fixed columns in get colelction measurements method
--- Added comments ---  froehlichd1 [Aug 11, 2011 3:40:49 PM CEST]
Change Package: 45990:49 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.26.1.1 2011/08/11 15:38:50CEST Froehlich Dominik (froehlichd1) (froehlichd1)
* fix: fixed columns in get collection measurements method
--- Added comments ---  froehlichd1 [Aug 11, 2011 3:38:50 PM CEST]
Change Package: 45990:49 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.26 2011/07/11 09:22:17CEST Spruck Jochen (spruckj) (spruckj)
Add function to get all collection names
--- Added comments ---  spruckj [Jul 11, 2011 9:22:19 AM CEST]
Change Package: 69027:1 http://mks-psad:7002/im/viewissue?selection=69027
Revision 1.25 2011/07/07 09:14:46CEST Raedler Guenther (uidt9430) (uidt9430)
-- fixed bug in GetComponentIDs(). It returns the correct list of childs now
--- Added comments ---  uidt9430 [Jul 7, 2011 9:14:47 AM CEST]
Change Package: 67780:5 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.24 2011/06/17 08:30:56CEST Raedler Guenther (uidt9430) (uidt9430)
- fixed error when rec files is assigned to more than 1 collection
--- Added comments ---  uidt9430 [Jun 17, 2011 8:30:57 AM CEST]
Change Package: 67780:3 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.23 2011/06/14 13:40:51CEST Spruck Jochen (spruckj) (spruckj)
add additional function, get all collection names assigned to a recording
Revision 1.22 2011/03/10 09:21:51CET Froehlich Dominik (froehlichd1) (froehlichd1)
* added missing columns
--- Added comments ---  froehlichd1 [Mar 10, 2011 9:21:52 AM CET]
Change Package: 33544:84 http://mks-psad:7002/im/viewissue?selection=33544
Revision 1.21 2011/02/16 10:00:43CET Froehlich Dominik (froehlichd1) (froehlichd1)
* fixed missing GetLocationID
--- Added comments ---  froehlichd1 [Feb 16, 2011 10:00:43 AM CET]
Change Package: 30321:300 http://mks-psad:7002/im/viewissue?selection=30321
Revision 1.20 2011/01/20 15:43:54CET Norman Apel (apeln)
- add CAT subscheme prefix to table names
--- Added comments ---  apeln [Jan 20, 2011 3:43:55 PM CET]
Change Package: 43037:6 http://mks-psad:7002/im/viewissue?selection=43037
Revision 1.19 2010/11/18 19:59:04CET Dominik Froehlich (froehlichd1)
* fix: corrected support of Oracle date/time format strings
* change: added support of error tolerance levels in rec catalog library
--- Added comments ---  froehlichd1 [Nov 18, 2010 7:59:04 PM CET]
Change Package: 45990:36 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.18 2010/11/18 17:35:54CET Dominik Froehlich (froehlichd1)
* change: support special date time format per dbms
Revision 1.17 2010/09/27 10:06:19CEST Dominik Froehlich (froehlichd1)
* change: implemented update function
Revision 1.16 2010/09/24 13:50:19CEST Dominik Froehlich (froehlichd1)
* fix: fixed add file command
* add: added update file command
* add: added update coll command
* add: added update kw command
Revision 1.15 2010/09/20 12:30:02CEST Dominik Froehlich (froehlichd1)
* corercted GetXXName methods of db_reccatalog.py
Revision 1.14 2010/09/17 15:09:00CEST Dominik Froehlich (froehlichd1)
* add aprtcfg
* add vehcfgstate
* add parttype
* diverse fixes
* list cmds not adapted yet
--- Added comments ---  froehlichd1 [Sep 17, 2010 3:09:01 PM CEST]
Change Package: 45990:25 http://mks-psad:7002/im/viewissue?selection=45990
Revision 1.13 2010/07/14 11:57:14CEST Dominik Froehlich (froehlichd1)
* update
--- Added comments ---  froehlichd1 [Jul 14, 2010 11:57:15 AM CEST]
Change Package: 45990:20 http://fras236:8002/im/viewissue?selection=45990
Revision 1.12 2010/07/06 12:45:11CEST Dominik Froehlich (dfroehlich)
* added list for vehicle cfgs
* added list for part cfgs
--- Added comments ---  dfroehlich [2010/07/06 10:45:11Z]
Change Package: 45990:19 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.11 2010/07/05 11:56:07CEST Dominik Froehlich (dfroehlich)
* implemented list cmd for keywords an collections
--- Added comments ---  dfroehlich [2010/07/05 09:56:08Z]
Change Package: 45990:17 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.10 2010/07/01 14:05:52CEST Dominik Froehlich (dfroehlich)
* support of location info
--- Added comments ---  dfroehlich [2010/07/01 12:05:52Z]
Change Package: 45990:12 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.9 2010/07/01 11:37:42CEST Dominik Froehlich (dfroehlich)
* update
--- Added comments ---  dfroehlich [2010/07/01 09:37:42Z]
Change Package: 45990:11 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.8 2010/06/30 17:26:53CEST Dominik Froehlich (dfroehlich)
* cleanup
--- Added comments ---  dfroehlich [2010/06/30 15:26:53Z]
Change Package: 45990:10 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.7 2010/06/30 10:39:12CEST Dominik Froehlich (dfroehlich)
* add: support of keyword to collection insertion
--- Added comments ---  dfroehlich [2010/06/30 08:39:13Z]
Change Package: 45990:6 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.6 2010/06/29 17:16:52CEST Dominik Froehlich (dfroehlich)
* change: support vehicle configurations
--- Added comments ---  dfroehlich [2010/06/29 15:16:52Z]
Change Package: 45990:8 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.5 2010/06/28 17:13:02CEST Dominik Froehlich (dfroehlich)
* add: support of file->coll assoc.
* add: support of kw->file assoc.
--- Added comments ---  dfroehlich [2010/06/28 15:13:02Z]
Change Package: 45990:5 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.4 2010/06/28 09:34:14CEST Dominik Froehlich (dfroehlich)
* update
--- Added comments ---  dfroehlich [2010/06/28 07:34:14Z]
Change Package: 45990:5 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.3 2010/06/25 14:22:12CEST Dominik Froehlich (dfroehlich)
* update
--- Added comments ---  dfroehlich [2010/06/25 12:22:12Z]
Change Package: 45990:3 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.2 2010/06/18 16:01:24CEST Dominik Froehlich (dfroehlich)
* update
--- Added comments ---  dfroehlich [2010/06/18 14:01:24Z]
Change Package: 45990:2 http://LISS014:6001/im/viewissue?selection=45990
Revision 1.1 2010/06/17 13:30:10CEST Dominik Froehlich (dfroehlich)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
Base_CGEB/06_Algorithm/04_Engineering/02_Development_Tools/scripts/project.pj
"""
