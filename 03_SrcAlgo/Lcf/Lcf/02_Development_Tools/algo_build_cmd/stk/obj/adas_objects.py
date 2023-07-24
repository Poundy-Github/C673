"""
stk/obj/adas_objects.py
-------------------

 Classes for ADAS Object handling

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:33CET $
"""

# Import Python Modules ---------------------
from os import path
from sys import path as sp
import math
import numpy.core as npc
from scipy import interpolate, unwrap
from random import shuffle
from abc import ABCMeta, abstractmethod
from stk.obj.pythonext.ordereddict import OrderedDict


# Import STK Modules -------------------------
DBFolder = path.abspath(path.join(path.split(__file__)[0], '..'))
if DBFolder not in sp:
    sp.append(DBFolder)

from stk.db.obj.objdata import \
    COL_NAME_KINEMATICS_KINABSTS, COL_NAME_KINEMATICS_RELDISTX, \
    COL_NAME_KINEMATICS_RELDISTY, COL_NAME_KINEMATICS_RELVELX, \
    COL_NAME_KINEMATICS_RECTOBJID, COL_NAME_KINEMATICS_HEADINGOVERGND, \
    COL_NAME_ADMA_KINEMATICS_RELDISTX, COL_NAME_ADMA_KINEMATICS_RELDISTY, \
    COL_NAME_ADMA_KINEMATICS_RELVELX, COL_NAME_ADMA_KINEMATICS_RELVELY, \
    COL_NAME_ADMA_KINEMATICS_HEADINGOG, COL_NAME_ADMA_KINEMATICS_ARELX, \
    COL_NAME_ADMA_KINEMATICS_ADMAOK

from stk.db.db_sql import SQLBinaryExpr, OP_AS
from stk.obj.geo.rect import Rectangle
from stk.db.obj.objdata import COL_NAME_RECT_OBJ_RECTOBJID, \
    COL_NAME_RECT_OBJ_OBJLENGTH, \
    COL_NAME_RECT_OBJ_OBJWIDTH \

import stk.util.logger as log

# Defines ------------------------------------
# OBJECT Definitions
OBJ_OBJECT_INDEX = "Index"
OBJ_GLOBAL_ID = "GlobalObjectId"
OBJ_OBJECT_ID = "ObjectId"
OBJ_DYNAMIC_PROPERTY = "ucDynamicProperty"
OBJ_START_TIME = "StartTime"
OBJ_START_INDEX = "Index"
OBJ_TIME_STAMPS = "Timestamp"
OBJ_RECTOBJECT_ID = "RectObjId"
OBJ_CLASS = "Classification"

OBJ_DISTX = 'DistX'
OBJ_DISTX_STD = 'DistX_Std'
OBJ_DISTY = 'DistY'
OBJ_DISTY_STD = 'DistY_Std'
OBJ_VELX = 'VrelX'
OBJ_VELX_STD = 'VrelX_Std'
OBJ_VELY = 'VrelY'
OBJ_VELY_STD = 'VrelY_Std'
OBJ_ACCELX = 'AccelX'
OBJ_ACCELX_STD = 'AccelX_Std'
OBJ_ACCELY = 'AccelY'
OBJ_ACCELY_STD = 'AccelY_Std'
OBJ_ORIENT = 'Orient'
OBJ_ORIENT_STD = 'Orient_Std'
OBJ_FLAG = 'Flags'
OBJ_OBJECT_ID = 'ObjectId'
OBJ_LENGTH = 'Object_Length'
OBJ_WIDTH = 'Object_Width'
OBJ_TS = 'Object_Ts'


DB_2_OBJ_NAME = {COL_NAME_RECT_OBJ_RECTOBJID: OBJ_RECTOBJECT_ID,
                 COL_NAME_RECT_OBJ_OBJLENGTH: OBJ_LENGTH,
                 COL_NAME_RECT_OBJ_OBJWIDTH: OBJ_WIDTH,
                 COL_NAME_KINEMATICS_RELDISTX: OBJ_DISTX,
                 COL_NAME_KINEMATICS_RELDISTY: OBJ_DISTY,
                 COL_NAME_KINEMATICS_RELVELX: OBJ_VELX,
                 COL_NAME_KINEMATICS_HEADINGOVERGND: OBJ_ORIENT,
                 COL_NAME_KINEMATICS_KINABSTS: OBJ_TS}

OBJ_2_DB_NAME = {OBJ_RECTOBJECT_ID: COL_NAME_RECT_OBJ_RECTOBJID,
                 OBJ_LENGTH: COL_NAME_RECT_OBJ_OBJLENGTH,
                 OBJ_WIDTH: COL_NAME_RECT_OBJ_OBJWIDTH,
                 OBJ_DISTX: COL_NAME_KINEMATICS_RELDISTX,
                 OBJ_DISTY: COL_NAME_KINEMATICS_RELDISTY,
                 OBJ_VELX: COL_NAME_KINEMATICS_RELVELX,
                 OBJ_ORIENT: COL_NAME_KINEMATICS_HEADINGOVERGND,
                 OBJ_TS: COL_NAME_KINEMATICS_KINABSTS}

# Functions ---------------------------------

# Classes -----------------------------------


class ObjectProperty(dict):
    """
    ObjectProperty
    """
    OBJECT_PROPERTY_MOVING = 0,
    OBJECT_PROPERTY_STATIONARY = 1,
    OBJECT_PROPERTY_ONCOMING = 2,
    OBJECT_PROPERTY_STOPPED = 3,
    OBJECT_PROPERTY_FREE = 4,
    OBJECT_PROPERTY_UNDEFINED = 5

OBJ_TYPE_MAP = {ObjectProperty.OBJECT_PROPERTY_MOVING: 'OBJECT_PROPERTY_MOVING',
                ObjectProperty.OBJECT_PROPERTY_STATIONARY: 'OBJECT_PROPERTY_STATIONARY',
                ObjectProperty.OBJECT_PROPERTY_ONCOMING: 'OBJECT_PROPERTY_ONCOMING',
                ObjectProperty.OBJECT_PROPERTY_STOPPED: 'OBJECT_PROPERTY_STOPPED',
                ObjectProperty.OBJECT_PROPERTY_FREE: 'OBJECT_PROPERTY_FREE',
                ObjectProperty.OBJECT_PROPERTY_UNDEFINED: 'OBJECT_PROPERTY_UNDEFINED'
                }

DEBUG_PRINT_BOX_IMAGE = True

ADMA_VALID = "IsAdma"


KINEMATICS_SELECT_LIST = [SQLBinaryExpr(COL_NAME_KINEMATICS_KINABSTS, OP_AS, OBJ_TIME_STAMPS),
                          SQLBinaryExpr(COL_NAME_KINEMATICS_RELDISTX, OP_AS, OBJ_DISTX),
                          SQLBinaryExpr(COL_NAME_KINEMATICS_RELDISTY, OP_AS, OBJ_DISTY),
                          SQLBinaryExpr(COL_NAME_KINEMATICS_RELVELX, OP_AS, OBJ_VELX),
                          SQLBinaryExpr(COL_NAME_KINEMATICS_HEADINGOVERGND, OP_AS, OBJ_ORIENT)]

ADMA_KINEMATICS_SELECT_LIST = [SQLBinaryExpr(COL_NAME_KINEMATICS_KINABSTS, OP_AS, OBJ_TIME_STAMPS),
                               SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_RELDISTX, OP_AS, OBJ_DISTX),
                               SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_RELDISTY, OP_AS, OBJ_DISTY),
                               SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_RELVELX, OP_AS, OBJ_VELX),
                               SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_RELVELY, OP_AS, OBJ_VELY),
                               SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_HEADINGOG, OP_AS, OBJ_ORIENT),
                               SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_ARELX, OP_AS, OBJ_ACCELX),
                               SQLBinaryExpr(COL_NAME_ADMA_KINEMATICS_ADMAOK, OP_AS, ADMA_VALID)]

BOX_TOLERANCE = 0.1  # 10% Tolerance for the box
DX_OFFSET = 0.5  # 0.5m offset between reflection point and adma reference

TIME_CYCLE = 0
GLOBAL_INDEX = 1
OBJECTS = 2

GLB_INDX = 0
OBJ_INDX = 1
LIFE_COUNT = 2
OBJ = 3

INDEX = "Index"

# create a random color table
COLORS = []
for i in range(4):
    for j in range(4):
        for k in range(4):
            COLORS.append([i / 3.0, j / 3.0, k / 3.0])
shuffle(COLORS)

DEBUG_ENABLE = False
DEBUG_PLOT_ENABLE = False
USE_REFLECTION_POINT = False


class RadarObject ():
    """
    Class holding a reference to a object in the object list, the object ID and
    global ID
    @param obj: Object reference
    @param object_id: Object Id
    @param global_id: Global Id
    @param obj_start_index: Start index of the object with in the measurement
    """
    def __init__(self, obj):
        """
        Constructor taking the distx, disty and the vrelx as argument
        @param obj: Reference to object in the list of objects
        """
        self.__object = obj
        self.__object_id = obj[OBJ_OBJECT_ID]
        self.__global_id = obj[OBJ_GLOBAL_ID]
        self.__obj_start_index = obj[OBJ_START_INDEX]
        self.__obj_type = ObjectProperty.OBJECT_PROPERTY_UNDEFINED

    def __del__(self):
        self.__object = None
        # print "Event Object Reference destroyed"

    def __copy__(self):
        """
        Make a copy of the event object class

        The reference to the object is copied as well
        """
        cpy = RadarObject(self.GetObject())
        return cpy

    def GetStartIndex(self):
        """ Return the Startindex
        @return: Startindex of the object
        """
        return self.__obj_start_index

    def SetObjectType(self, index):
        """
        Set the object type using the given index
        """
        self.__obj_type = self.__object[OBJ_DYNAMIC_PROPERTY][index]

    def GetObjectType(self):
        """
        GetObjectType
        """
        return self.__obj_type

    def GetObjectTypeLabel(self):
        """
        Get the text label of the object type
        """
        return OBJ_TYPE_MAP[self.__obj_type]

    def GetGlobalID(self):
        """ Return the global ID of the object
        @return The Global ID of the object
        """
        return self.__global_id

    def GetObjectID(self):
        """ Return the object ID
        @return The Object ID
        """
        return self.__object_id

    def GetObject(self):
        """ Return the object
        @return The Object
        """
        return self.__object

    def GetStartTime(self):
        """ Return the Starttime of the Radar Object
        @return Get the Starttime of the Object
        """
        return self.__object[OBJ_START_TIME]

    def GetStopTime(self):
        """ Return the Stoptime of the Object
        @return the stoptime of the object
        """
        obj_length = len(self.__object[OBJ_TIME_STAMPS])
        obj_endtime = self.__object[OBJ_TIME_STAMPS][obj_length - 1]
        return obj_endtime

    def GetSignalValueByIndex(self, signal, index):
        """ Get a signal value for the given array index
        If index exceeds, 0 will be returned.

        @return a signal value for the given index
        """
        if (signal == OBJ_OBJECT_ID):
            return self.__object[signal]
        else:
#            if signal not in self.__Object:
#                signal = "f" + signal
            if (len(self.__object[signal]) >= index):
                return self.__object[signal][index]
            else:
                return 0

    def GetSignal(self, signal, start_idx=None, end_idx=None):
        """ Get Signal Values
        @return Return the values of the given signal
        if signal is not an array, just the value is returned
        if signal is an array, values are retuned according to start and stop index
        """
        is_array = isinstance(self.__object[signal], (list, tuple))

        if is_array:
            if start_idx is None:
                start_idx = 0
            if end_idx is None:
                end_idx = len(self.__object[signal])
            if start_idx == end_idx:
                signal_array = [self.__object[signal][start_idx]]
            else:
                signal_array = self.__object[signal][start_idx:end_idx]
            return signal_array
        else:
            return self.__object[signal]


class RadarObjectList ():  # pylint: disable=R0902
    """
    Class supporting operations on Object Lists
    @param __len_of_kinematics: length of the kinematics date
    @param __best_obj_table: table holding information for the best objects in the measurement
    @param obj_start_index: Start index of the object with in the measurement
    """
    def __init__(self, objlist):
        self.__ObjectList = objlist
        self.__BestObjDist = []
        self.__ReflectionPoint = []
        self.__best_obj_table = []
        self.__obj_ids = []
        self.__ObjectsInRect = []
        self.__RelevantObjects = []
        self.__BestObjects = []
        self.__len_of_kinematics = 0

        """ TESTCODE ------------------------------------------------------ """
#        box = val_fc.BoxGetCorners(5,2)
#        box_car = val_fc.BoxGetCorners(5,2,tolerance = 0.0)
#        data_lines = []
#        legend_list = []
#        degree = 0;
#
#        legend_list.append("car")
#        data_lines.append(box_car)
#
#        for i in xrange(0,3):
#            legend_list.append("box{0}".format(degree))
#            box_rot = val_fc.GetRotatedBox(box, math.radians(degree))
#            box_rot_car = val_fc.GetRotatedBox(box_car, math.radians(degree))
#            val_fc.PolygonContainsPoint(box_rot, 3.0, 0)
#            val_fc.PolygonContainsPoint(box_rot, -1, 3.0)
#            data_lines.append(box_rot)
#            legend_list.append("point{0}".format(degree))
#            data_lines.append([val_fc.BoxCalcReflectionsPoint(box_rot_car,degree)])
#            degree += 90
#
#        plotter = ValidationPlot("d:/temp/")
#        plotter.GetScatterPlot(data_lines, legend_list, "distx","disty", True,
#                               True, fig_width=11, fig_height=11, title = "Box")
#        img_data = plotter.GetPlotDataBuffer()
        """ TESTCODE ------------------------------------------------------ """

    def __GenerateRelevantObjectList(self, rect_obj_ts):
        """
        __GenerateRelevantObjectList
        """
        self.__RelevantObjects = []
        rel_obj_list = []
        for idx in xrange(0, len(rect_obj_ts)):
            temp_obj = [rect_obj_ts[idx], [], []]
            rel_obj_list.append(temp_obj)

        kin_end_index = len(rect_obj_ts) - 1

        for obj in self.__ObjectList:  # for each object in the complete object list

            rad_obj = RadarObject(obj)
            obj_starttime = rad_obj.GetStartTime()
            obj_endtime = rad_obj.GetStopTime()

            obj_ts = rad_obj.GetSignal(OBJ_TIME_STAMPS)
            rad_obj_index = obj_ts.index(obj_starttime)

            if obj_starttime >= rect_obj_ts[kin_end_index]:
                continue
            if obj_endtime <= rect_obj_ts[0]:
                continue

            if obj_starttime < rect_obj_ts[0]:
                obj_starttime = rect_obj_ts[0]

            if obj_endtime > rect_obj_ts[kin_end_index]:
                obj_endtime = rect_obj_ts[kin_end_index]

            glb_start = rect_obj_ts.index(obj_starttime)
            glb_end = rect_obj_ts.index(obj_endtime)

            if (glb_end - glb_start > 0):
                for idx_glb in range(glb_start, glb_end):
                    rel_obj_list[idx_glb][GLOBAL_INDEX].append(rad_obj_index)
                    rel_obj_list[idx_glb][OBJECTS].append(rad_obj)
                    rad_obj_index += 1

        self.__RelevantObjects = rel_obj_list

    def GetBestObjectsList(self, kin_ts, kin_data, rect_obj_properties, crossing=False):
        """
        GetBestObjectsList
        """

        if USE_REFLECTION_POINT:
            self.GetBestObjectsListByReflectionPoint(kin_ts, kin_data, rect_obj_properties)
        else:
            self.GetBestObjectsListByGate(kin_ts, kin_data, rect_obj_properties, crossing)

    def GetBestObjectsListByGate(self, kin_ts, kin_data, crossing=False):  # pylint: disable=R0914
        """the best (closest) radar objects for each time cycle in adma is found"""

        self.__BestObjects = []

        diff_dist_y = 0
        diff_dist_x = 0
        diff_vrel_x = 0

        # coarse gating for selection of ADMA object
        gate_dist_x = 3
        gate_dist_y = 6
        gate_vrel_x = 5

        # MAIN Mahalanobis gate for selection of adma object in [SIGMA]
        gate_stat_dist = 3

        # for crossing situation
        if crossing is True:
            gate_dist_x = 7
            gate_dist_y = 4
            gate_stat_dist = 4.5

        self.__len_of_kinematics = len(kin_ts)
        self.__GenerateRelevantObjectList(kin_ts)

        index_per_timecycle = []
        obj_per_timecycle = []
        for idx_rel_obj, data in enumerate(self.__RelevantObjects):  # for each sorted time cycle
            ts = data[TIME_CYCLE]
            index_per_timecycle = data[GLOBAL_INDEX]
            obj_per_timecycle = data[OBJECTS]

            best_obj_per_timecycle = []  # stores all the best obj for each timecycle
            obj_ind_per_timecycle = []
            dist_per_timecycle = []
            dist_backup_timecycle = []

            for idx_obj_tc in range(len(obj_per_timecycle)):  # for each obect in a time cycle
                current_obj = obj_per_timecycle[idx_obj_tc]

                index = index_per_timecycle[idx_obj_tc]

                object_dist = -1
                disX_ref = kin_data[OBJ_DISTX.upper()][idx_rel_obj]
                disY_ref = kin_data[OBJ_DISTY.upper()][idx_rel_obj]
                velX_ref = kin_data[OBJ_VELX.upper()][idx_rel_obj]

                diff_dist_x = current_obj.GetSignalValueByIndex(OBJ_DISTX, index) - disX_ref
                diff_dist_y = current_obj.GetSignalValueByIndex(OBJ_DISTY, index) - disY_ref
                diff_vrel_x = current_obj.GetSignalValueByIndex(OBJ_VELX, index) - velX_ref

                dist_x_var = math.pow(current_obj.GetSignalValueByIndex(OBJ_DISTX_STD, index), 2) + math.pow(0.8, 2)
                dist_y_var = math.pow(current_obj.GetSignalValueByIndex(OBJ_DISTY_STD, index), 2) + math.pow(0.8, 2)
                vrel_x_var = math.pow(current_obj.GetSignalValueByIndex(OBJ_VELX_STD, index), 2) + math.pow(0.8, 2)

                # Compute statistical distance of object to reference.
                object_dist_pow2 = (math.pow(diff_dist_x, 2) / dist_x_var + math.pow(diff_dist_y, 2) / dist_y_var +
                                    math.pow(diff_vrel_x, 2) / vrel_x_var)
                # Alternative witout standard deviations.
                object_dist = math.sqrt(object_dist_pow2)

                dist_backup_timecycle.append(object_dist)  # this is used in case there are no best object

                if((abs(diff_dist_x) < gate_dist_x) and
                   (abs(diff_dist_y) < gate_dist_y) and
                   (abs(diff_vrel_x) < gate_vrel_x)):

                    if (object_dist < gate_stat_dist and object_dist != -1):
                        best_obj_per_timecycle.append(current_obj)  # all the best objects for each TC is appended
                        obj_ind_per_timecycle.append(index)
                        dist_per_timecycle.append(object_dist)

            if len(best_obj_per_timecycle):
                min_index = dist_per_timecycle.index(min(dist_per_timecycle))
                self.__BestObjDist.append(dist_per_timecycle[min_index])
                # best object for each time cycle
                self.__BestObjects.append([ts, obj_ind_per_timecycle[min_index],
                                           best_obj_per_timecycle[min_index]])
            else:
                self.__BestObjects.append([ts, obj_ind_per_timecycle, best_obj_per_timecycle])
                if len(dist_backup_timecycle):
                    self.__BestObjDist.append(min(dist_backup_timecycle))
                else:
                    self.__BestObjDist.append(dist_backup_timecycle)

        self.GetBestObjectCombination()
        self.PostProcessBestObjects()

    def GetBestObjectsListByReflectionPoint(self, kin_ts, kin_data, rect_obj_properties):
        """the best (closest) radar objects for each time cycle in adma is found"""

        self.__BestObjects = []
        self.__ReflectionPoint = []

        rect_length = rect_obj_properties[COL_NAME_RECT_OBJ_OBJLENGTH]
        rect_width = rect_obj_properties[COL_NAME_RECT_OBJ_OBJWIDTH]

        # coarse gating for selection of ADMA object
        gate_vrel_x = 5
        # MAIN Mahalanobis gate for selection of adma object in [SIGMA]
        gate_stat_dist = 3.5

        self.__len_of_kinematics = len(kin_ts)
        self.__GenerateRelevantObjectList(kin_ts)

        index_per_timecycle = []
        obj_per_timecycle = []
        # for each sorted time cycle
        for i, data in enumerate(self.__RelevantObjects):

            # get timestamp and radar object
            ts = data[TIME_CYCLE]
            index_per_timecycle = data[GLOBAL_INDEX]
            obj_per_timecycle = data[OBJECTS]

            # stores all the best obj for each timecycle
            best_obj_per_timecycle = []
            obj_ind_per_timecycle = []
            dist_per_timecycle = []

            # reference position (ADMA)
            ref_distx = kin_data[OBJ_DISTX.upper()][i]
            ref_disty = kin_data[OBJ_DISTY.upper()][i]
            ref_vrelx = kin_data[OBJ_VELX.upper()][i]
            ref_orient = kin_data[OBJ_ORIENT.upper()][i]

            # calculate the rotated ego vehicle box (assuming that the reference point is the mid of rearend)
            box_ego = Rectangle(rect_width * 0.5, rect_width * 0.5, rect_length, 0)
            box_ego.Rotate(ref_orient)

            # calculate the rotated gating box (assuming that the reference point is the mid of rearend)
            box_gate = Rectangle(rect_width * 0.75, rect_width * 0.75, rect_length * 1.25, rect_length * 0.25)
            box_gate.Rotate(ref_orient)

            # calculate the estimated radar reflection point
            refl_point = box_gate.CalcReflectionsPoint()
            refl_distx = ref_distx + refl_point[0]
            refl_disty = ref_disty + refl_point[1]

            if DEBUG_ENABLE:
                debug_data = []

                # draw car box
                debug_data.append(box_ego.Shift(ref_distx, ref_disty))
                debug_data.append({'color': 'b', 'linestyle': '-',
                                   'label': "car orient:: {0:5.1f}".format(ref_orient * 180 / 3.1415)})

                # draw gate box
                debug_data.append(box_gate.Shift(ref_distx, ref_disty))
                debug_data.append({'color': 'r', 'linestyle': '-', 'label': "gate"})

                # draw reference point
                debug_data.append([[ref_distx, ref_disty]])
                debug_data.append({'color': 'b', 'linestyle': '-', 'marker': '+', 'markersize': 10})

                # draw reflection point
                debug_data.append([[ref_distx + refl_point[0], ref_disty + refl_point[1]]])
                debug_data.append({'color': 'g', 'linestyle': '-', 'marker': '.', 'markersize': 10})

                # draw field of view
                debug_data.append([[0, 0], [200, -40], [200, 40], [0, 0]])
                debug_data.append({'color': 'k', 'linestyle': '-'})

            # for each radar obect in a time cycle
            for j in range(len(obj_per_timecycle)):
                # get object data
                obj = obj_per_timecycle[j]
                index = index_per_timecycle[j]
                current_obj = RadarObject(obj)

                # get object kinematics
                rad_distx = current_obj.GetSignalValueByIndex(OBJ_DISTX, index)
                rad_disty = current_obj.GetSignalValueByIndex(OBJ_DISTY, index)
                rad_vrelx = current_obj.GetSignalValueByIndex(OBJ_VELX, index)

                # compute difference between radar object and reference
                diff_distx = rad_distx - ref_distx
                diff_disty = rad_disty - ref_disty
                diff_vrelx = rad_vrelx - ref_vrelx

                if DEBUG_ENABLE:
                    # draw objects in range
                    debug_data.append([[rad_distx, rad_disty]])
                    debug_data.append({'color': COLORS[obj['Index'] % len(COLORS)],
                                       'linestyle': '-', 'marker': '<', 'markersize': 8})

                # Make coarse box gating
                isInBox = box_gate.PolygonContainsPoint(diff_distx, diff_disty)
                if (isInBox and (abs(diff_vrelx) < gate_vrel_x)):

                    diff_distx = rad_distx - refl_distx
                    diff_disty = rad_disty - refl_disty

                    diff_distx_var = (math.pow(current_obj.GetSignalValueByIndex(OBJ_DISTX_STD, index), 2) +
                                      math.pow(0.8, 2))
                    diff_disty_var = (math.pow(current_obj.GetSignalValueByIndex(OBJ_DISTY_STD, index), 2) +
                                      math.pow(0.8, 2))
                    diff_vrelx_var = (math.pow(current_obj.GetSignalValueByIndex(OBJ_VELX_STD, index), 2) +
                                      math.pow(0.8, 2))

                    # Compute staistical distance of object to reference.
                    stat_obj_dist = ((diff_distx * diff_distx) / diff_distx_var
                                     + (diff_disty * diff_disty) / diff_disty_var
                                     + (diff_vrelx * diff_vrelx) / diff_vrelx_var)

                    # store all objects in the gating box + their statistical (mahalanobis) distance
                    if (stat_obj_dist < math.pow(gate_stat_dist, 2)):
                        best_obj_per_timecycle.append(obj)
                        obj_ind_per_timecycle.append(index)
                        dist_per_timecycle.append(stat_obj_dist)

            # store best objs for each time cycle
            self.__BestObjects.append([ts, obj_ind_per_timecycle, best_obj_per_timecycle, dist_per_timecycle])

            # store reflection point
            self.__ReflectionPoint.append([refl_distx, refl_disty])

            # store stat dist of closes object
            if dist_per_timecycle:
                temp = min(dist_per_timecycle)
                self.__BestObjDist.append(temp)
            else:
                self.__BestObjDist.append(0)

#            if DEBUG_ENABLE:
#                # plot only if more than two objects (the two boxes) are available
#                if i > 50 and i < 25:
#                    plotter = ValidationPlot("d:/temp/")
#                    plotter.GenerateSimplePlot(debug_data, "Time","StatDist", True,
#                                               fig_width=11, fig_height=11, title = "StatDist")
#                    plotter.GetPlotDataBuffer()
#                    os.rename("d:/temp/Temp_File.png", "d:/temp/scatter_{0:04d}.png".format(i))

        self.__obj_ids = [-1] * len(self.__BestObjects)

        self.GetBestObjectCombination()
        self.PostProcessBestObjects()

    def GetObjectsInRectObject(self, kin_ts, kin_data, rect_obj_properties, obj_in_box=False):
        """ return the list of object, closed to the refelection point for each time cycle

            The reflection point is defined by the labeled rectangular object
        """
        # ObjectsInRect = []

        rect_length = rect_obj_properties[COL_NAME_RECT_OBJ_OBJLENGTH]
        rect_width = rect_obj_properties[COL_NAME_RECT_OBJ_OBJWIDTH]

        # coarse gating for selection of ADMA object
        gate_vrel_x = 5

        self.__len_of_kinematics = len(kin_ts)
        self.__GenerateRelevantObjectList(kin_ts)
        self.__ObjectsInRect = []

        index_per_timecycle = []
        obj_per_timecycle = []
        # for each sorted time cycle

        # calculate the rotated gating box (assuming that the reference point is the mid of the box)
        box_gate = Rectangle(rect_width / 2, rect_width / 2, rect_length / 2, rect_length / 2)

        for i, data in enumerate(self.__RelevantObjects):

            # get timestamp and radar object
            ts = data[TIME_CYCLE]
            index_per_timecycle = data[GLOBAL_INDEX]
            obj_per_timecycle = data[OBJECTS]

            # stores all the best obj for each timecycle
            object_idx_list = []
            object_list = []

            # reference position (ADMA)
            ref_distx = round(kin_data[OBJ_DISTX.upper()][i], 5)
            ref_disty = round(kin_data[OBJ_DISTY.upper()][i], 5)
            ref_vrelx = round(kin_data[OBJ_VELX.upper()][i], 5)
            ref_orient = round(kin_data[OBJ_ORIENT.upper()][i], 5)

            box_gate.Rotate(ref_orient)

            # for each radar obect in a time cycle
            for j in range(len(obj_per_timecycle)):
                # get object data
                current_obj = obj_per_timecycle[j]
                index = index_per_timecycle[j]
                # obj_timecycles =
                current_obj.GetSignal(OBJ_TIME_STAMPS)

                # get object kinematics
                rad_distx = round(current_obj.GetSignalValueByIndex(OBJ_DISTX, index), 5)
                rad_disty = round(current_obj.GetSignalValueByIndex(OBJ_DISTY, index), 5)
                rad_vrelx = round(current_obj.GetSignalValueByIndex(OBJ_VELX, index), 5)

                # compute difference between radar object and reference
                diff_distx = round(rad_distx - ref_distx, 5)
                diff_disty = round(rad_disty - ref_disty, 5)
                diff_vrelx = round(rad_vrelx - ref_vrelx, 5)

                # Make coarse box gating

                isInBox = box_gate.PolygonContainsPoint(diff_distx, diff_disty)
                if isInBox:
#                if len(current_obj.GetSignal("OOIHistory"))>0:

                    life_inside_box = False
                    obj_distx = current_obj.GetSignal(OBJ_DISTX)
                    obj_disty = current_obj.GetSignal(OBJ_DISTY)
                    try:

                        ref_distx_current = round(kin_data[OBJ_DISTX.upper()]
                                                          [current_obj.GetSignal(OBJ_START_INDEX)], 5)
                        ref_disty_current = round(kin_data[OBJ_DISTY.upper()]
                                                          [current_obj.GetSignal(OBJ_START_INDEX)], 5)
                        ref_orient_current = round(kin_data[OBJ_ORIENT.upper()]
                                                           [current_obj.GetSignal(OBJ_START_INDEX)], 5)
                    except:

                        ref_distx_current = ref_distx
                        ref_disty_current = ref_disty
                        ref_orient_current = ref_orient
                    box_gate_current = Rectangle(rect_width / 2, rect_width / 2, rect_length / 2, rect_length / 2)
                    box_gate_current.Rotate(ref_orient_current)

                    obj_startx = round(obj_distx[2], 5)
                    obj_starty = round(obj_disty[2], 5)
                    startinbox = box_gate_current.PolygonContainsPoint(round(obj_startx - ref_distx_current, 5),
                                                                       round(obj_starty - ref_disty_current, 5))

                    obj_endx = round(obj_distx[-2], 5)
                    obj_endy = round(obj_disty[-2], 5)
                    stopinbox = box_gate_current.PolygonContainsPoint(round(obj_endx - ref_distx_current, 5),
                                                                      round(obj_endy - ref_disty_current, 5))

                    if (startinbox or stopinbox):
                        life_inside_box = True

                    if obj_in_box is False and (abs(diff_vrelx) < gate_vrel_x):
    #                   if (isInBox):
                        object_list.append(current_obj)
                        object_idx_list.append(index)
                    elif life_inside_box and obj_in_box:
                        object_list.append(current_obj)
                        object_idx_list.append(index)
                    # print "Index: {0} -> obj: {1}".format(index, current_obj.GetObjectID())

            # store best objs for each time cycle
            self.__ObjectsInRect.append([ts, object_idx_list, object_list])

            object_list = []
            object_idx_list = []

        return 0

    def GetBestObjectCombination(self):
        pass
        # debug_data = []

        # creating object id list for calculating id changes
#        for i in range(50, 250):   #len(self.__BestObjects)
#
#            dist_per_timecycle = self.__BestObjects[i][OBJECTS+1]
#            obj_per_ts = self.__BestObjects[i][OBJECTS]
#
#            if dist_per_timecycle:
#                for j in range(len(dist_per_timecycle)):
#                    obj_index = obj_per_ts[j]["Index"]
#                    if DEBUG_ENABLE:
#                        debug_data.append([[i,dist_per_timecycle[j]]])
#                        debug_data.append({'color':COLORS[obj_index%len(COLORS)], 'linestyle':'',
#                                           'marker':'.', 'markersize':8})

#        if DEBUG_ENABLE:
#            plotter = ValidationPlot("d:/temp/")
#            plotter.GenerateSimplePlot(debug_data, "Time","StatDist", True, fig_width=11,
#                                       fig_height=11, title = "StatDist")
#            plotter.GetPlotDataBuffer()
#            os.rename("d:/temp/Temp_File.png", "d:/temp/__StatDist.png")
#            #sys.exit()

    def PostProcessBestObjects(self):

        prev_id = -1
        obj_start_indx = -1
        global_indx = 0
        life_count = 0
        best_objects_list = []
        stored_obj = None
        # creating object id list for calculating id changes
        for i in range(len(self.__BestObjects)):

            obj_per_ts = self.__BestObjects[i][OBJECTS]
            id_per_ts = -1

            if obj_per_ts:
                current_obj = obj_per_ts
                id_per_ts = current_obj.GetSignal(OBJ_OBJECT_ID)

                # self.__obj_ids[i] = id_per_ts

            if prev_id != id_per_ts:
                # Change
                if life_count > 0:
                    raw = [global_indx, obj_start_indx, life_count, stored_obj]
                    best_objects_list.append(raw)
                    obj_start_indx = -1
                    life_count = 0

                if id_per_ts != -1:
                    obj_start_indx = self.__BestObjects[i][GLOBAL_INDEX]
                    global_indx = i
                    stored_obj = current_obj
                    life_count = 0

            if obj_start_indx != -1:
                life_count += 1

            prev_id = id_per_ts

        if obj_start_indx != -1 and life_count > 0:
            raw = [global_indx, obj_start_indx, life_count, stored_obj]
            best_objects_list.append(raw)

        self.GetBestObjectTable(best_objects_list)

    def GetBestObjectTable(self, best_objects_list):
        # post processing of the best objects list
        total_length = len(best_objects_list)
        i = 0
        best_objects_list_filtered = []
        prev_raw_data = None

        while i < total_length:

            raw_data = best_objects_list[i]

            if prev_raw_data is None:
                if raw_data[LIFE_COUNT] >= 2:
                    best_objects_list_filtered.append(raw_data)
                    prev_raw_data = raw_data
            else:
                if prev_raw_data[OBJ].GetStartIndex() == raw_data[OBJ].GetStartIndex():  # same object ID ?
                    # merge object entries
                    prev_raw_data[LIFE_COUNT] = raw_data[GLB_INDX] + raw_data[LIFE_COUNT] - prev_raw_data[GLB_INDX]

                else:
                    if raw_data[LIFE_COUNT] > 3:  # ignore short lifecycle
                        best_objects_list_filtered.append(raw_data)
                        prev_raw_data = raw_data

            i += 1
        self.__best_obj_table = best_objects_list_filtered

        self.CalculateObjectIds()
        self.CalculateMinDist()

        # clear temporary attributes
        self.__RelevantObjects = []
        self.__BestObjects = []

    def CalculateObjectIds(self):
        """returns the object IDs of the best objects
        """

        self.__obj_ids = [-1] * len(self.__BestObjects)

        for best_obj in self.__best_obj_table:
            start = best_obj[GLB_INDX]
            lifecount = best_obj[LIFE_COUNT]
            stop = start + lifecount - 1
            obj = best_obj[OBJ]

            for x in range(start, stop):
                self.__obj_ids[x] = obj.GetObjectID()

    def CalculateMinDist(self):
        """calculated the mindist for the best objects
        """
        mindist = [-1] * len(self.__BestObjects)

        for best_obj in self.__best_obj_table:
            start = best_obj[GLB_INDX]
            lifecount = best_obj[LIFE_COUNT]
            stop = start + lifecount - 1

            mindist[start:stop] = [self.__BestObjDist[x] for x in range(start, stop)]
        self.__BestObjDist = []
        self.__BestObjDist = mindist

    def InterpolateAdmaKinematicsForTimeShift(self, kinematic_data, adma_delay, on_coming=False):
        """ Correct the ADMA data for the 100ms time delay. """

        kin_time_stamps = kinematic_data[OBJ_TIME_STAMPS.upper()]
        kin_time_ar = npc.array(kin_time_stamps)
        kinematics_interp = {}

        # Remove the latency delay for each value by interpolation
        for sig in kinematic_data:
            # do not interpolate timestamp
            if sig == OBJ_TIME_STAMPS.upper():
                interp_sig = kinematic_data[sig]
            # flags are interpolated using 'nearest' method
            elif sig == ADMA_VALID.upper():
                func_interp = interpolate.interp1d(kin_time_stamps, kinematic_data[sig], kind='nearest',
                                                   axis=-1, copy=True, bounds_error=False, fill_value=npc.nan)
                interp_sig = list(func_interp(kin_time_ar - adma_delay))
            # angles must be interpolated considering wrapping
            elif sig == OBJ_ORIENT.upper():
                func_interp = interpolate.interp1d(kin_time_stamps, unwrap(kinematic_data[sig]), kind='linear',
                                                   axis=-1, copy=True, bounds_error=False, fill_value=npc.nan)
                interp_sig = func_interp(kin_time_ar - adma_delay)
                interp_sig = list(((interp_sig + math.pi) % (2 * math.pi)) - math.pi)  # wrap back to -pi...pi
            # continuous signals are interpolated lineary
            else:
                func_interp = interpolate.interp1d(kin_time_stamps, kinematic_data[sig], kind='linear',
                                                   axis=-1, copy=True, bounds_error=False, fill_value=npc.nan)
                interp_sig = list(func_interp(kin_time_ar - adma_delay))

            # due to interpolation some data points are lost at the beginning/and of signal and filled with NaN
            # replace these values with uninterpolated data
            for iid in range(len(interp_sig)):
                if  math.isnan(interp_sig[iid]):
                    interp_sig[iid] = kinematic_data[sig][iid]
                    # kinematic_data[upper(ADMA_VALID)][iid] = 0  # set adma flag to invalid

            # overwrite old data with compensated one
            kinematics_interp[sig] = interp_sig

            if (on_coming is True and sig == OBJ_DISTX.upper()):
                temp = []
                oncome_change = 5.0
                temp = [value - oncome_change for value in kinematics_interp[sig]]
                kinematics_interp[sig] = temp
        return kinematics_interp

    def Flags(self, flags_result_ar):

        sig_vec = [0] * self.__len_of_kinematics
        sig_vec_long = [0] * self.__len_of_kinematics  # default vector
        sig_vec_cross = [0] * self.__len_of_kinematics  # default vector
        sig_vec_oncome = [0] * self.__len_of_kinematics  # default vector
        sig_vec_ped = [0] * self.__len_of_kinematics  # default vector
        flags_total = 0
        flags_error = [0] * 4

        for i in range(len(self.__best_obj_table)):
            start = self.__best_obj_table[i][GLB_INDX]
            stop = start + self.__best_obj_table[i][LIFE_COUNT] - 1
            obj = self.__best_obj_table[i][OBJ]
            # obj_indx_start = self.__best_obj_table[i][1]
            start_indx = self.__best_obj_table[i][OBJ_INDX]
            stop_indx = start_indx + self.__best_obj_table[i][LIFE_COUNT] - 1
            if (stop_indx > len(obj.GetSignal(OBJ_FLAG))):
                return flags_total, flags_error, sig_vec_long, sig_vec_oncome, sig_vec_cross, sig_vec_ped

            sig_vec[start:stop] = obj.GetSignal(OBJ_FLAG)[start_indx:stop_indx]

            for j in range(start, stop):
                pre_sel_flag = sig_vec[j]
                if pre_sel_flag != -1:
                    presel_flags = pre_sel_flag
                    flags_total += 1

                    if presel_flags & 0x1:
                        sig_vec_long[j] = 1
                    if presel_flags & 0x2:
                        sig_vec_oncome[j] = 1
                    if presel_flags & 0x4:
                        sig_vec_cross[j] = 1
                    if presel_flags & 0x8:
                        sig_vec_ped[j] = 1

                    flags_error[0] += int(bool(flags_result_ar[0]) ^ bool(sig_vec_long[j]))
                    flags_error[1] += int(bool(flags_result_ar[1]) ^ bool(sig_vec_oncome[j]))
                    flags_error[2] += int(bool(flags_result_ar[2]) ^ bool(sig_vec_cross[j]))
                    flags_error[3] += int(bool(flags_result_ar[3]) ^ bool(sig_vec_ped[j]))

                else:
                    presel_flags = 0
                # obj_indx_start = obj_indx_start+1

        return flags_total, flags_error, sig_vec_long, sig_vec_oncome, sig_vec_cross, sig_vec_ped

    def SignalOfBestObject(self, signal, add_filter=None):

        sig_vec = [0] * self.__len_of_kinematics  # default vector
        filter_vec = [0] * len(sig_vec)
        # generate the signal vector
        # temp_sig_vec = obj[SIG_NAME_OBJ_FLAG][start:stop]

        for best_obj in self.__best_obj_table:
            start = best_obj[GLB_INDX]
            lifecount = best_obj[LIFE_COUNT]
            stop = start + lifecount - 1
            rel_start_indx = best_obj[OBJ_INDX]
            rel_stop_indx = rel_start_indx + lifecount - 1
            obj = best_obj[OBJ]

            if (signal == OBJ_OBJECT_ID):
                temp_sig = obj.GetSignal(signal)
                return sig_vec
            elif signal == OBJ_ORIENT or signal == OBJ_ORIENT_STD:
                temp_sig = [math.degrees(x) for x in obj.GetSignal(signal)[rel_start_indx:rel_stop_indx]]
            else:
                temp_sig = obj.GetSignal(signal)[rel_start_indx:rel_stop_indx]

            sig_vec[start:stop] = temp_sig
            filter_vec[start:stop] = [1] * len(temp_sig)

        if add_filter:
            return sig_vec, filter_vec

        return sig_vec

    def ErrorOfBestObject(self, signal, adma_datas):

        radar_sig_vec, filter_vec = self.SignalOfBestObject(signal, True)
        error_data = [0.0] * len(radar_sig_vec)

        try:
            for j in xrange(1, len(radar_sig_vec)):
                if filter_vec[j] == 1:
                    error_data[j] = math.fabs(adma_datas[j] - radar_sig_vec[j])
        except:
            print signal

        return error_data

    def GetObjectIds(self):
        return self.__obj_ids

    def GetObjectDist(self):
        return self.__BestObjDist

    def GetObjectReflectionPoint(self):
        return self.__ReflectionPoint

    def GetObjectInRect(self):
        return self.__ObjectsInRect

    def GetIdChanges(self):
        id_ch = 0

        if len(self.__best_obj_table) > 1:

            prev_indx = None
            for i, best_obj in enumerate(self.__best_obj_table):
                curr_indx = best_obj[GLB_INDX]

                if i == 1:
                    prev_indx = curr_indx
                elif prev_indx is not None:
                    if (curr_indx - prev_indx) < int(1000 / 0.060):
                        id_ch += 1

        return id_ch


class ACCMatchObjectList_Class():  # pylint: disable=R0903, R0902
    """
    Constructor taking the event, database kinematics at specific timestamp as argument
    @param event: Event
    @param dbObjectKin: DatabaseKinematicsList (RECTOBJID, RELDISTX, RELDISTY, RELVELX) at specific timestamp
    """

    def __init__(self, event, dbObjectKin):
        self.__bestDBObjectIDTable = []
        self.__event = event
        self.__dbObjectKinematics = dbObjectKin
        self.__eventRadarObject = self.__event.GetEventObject().GetObject()
        self.__radarObjectStartIndex = None

        self.__SetBestDBObjectIDTable()

        self.__dxGate = None
        self.__dyGate = None
        self.__dVxGate = None

    def __del__(self):
        self.__event = None
        self.__eventRadarObject = None
        self.__radarObjectStartIndex = None

        self.__dbObjectKinematics = None
        self.__dxGate = None
        self.__dyGate = None
        self.__dVxGate = None

    def __CalcGates(self, dbObject):
        """ Set dx-, dx-, dVxGate
        """
        ind_obj = self.__event.GetWStartIndex()

        self.__dxGate = abs(dbObject[COL_NAME_KINEMATICS_RELDISTX] -
                            self.__eventRadarObject[OBJ_DISTX][ind_obj])
        self.__dyGate = abs(dbObject[COL_NAME_KINEMATICS_RELDISTY] -
                            self.__eventRadarObject[OBJ_DISTY][ind_obj])
        self.__dVxGate = abs(dbObject[COL_NAME_KINEMATICS_RELVELX] -
                             self.__eventRadarObject[OBJ_VELX][ind_obj])

    def __GetDistBetweenObjects(self):
        """ Return the EuclidDistance
        @return euclidDistance
        """
        return math.pow(self.__dxGate, 2) + math.pow(self.__dyGate, 2) + math.pow(self.__dVxGate, 2)

    def __SetBestDBObjectIDTable(self):
        """ Set/ Add RectObjID's in a RectObjIDList, depends on calculations of euclidDistance and the Gates
        """
        bestObjectEuclidDistance = []

        for dbObject in self.__dbObjectKinematics:
            self.__CalcGates(dbObject)

            euclidDistance = self.__GetDistBetweenObjects()

            if(self.__dxGate < 1.5 and self.__dyGate < 1.5 and
               self.__dVxGate < 3 and euclidDistance < bestObjectEuclidDistance):
                self.__bestDBObjectIDTable.append(dbObject[COL_NAME_KINEMATICS_RECTOBJID])
                bestObjectEuclidDistance = euclidDistance

    def GetBestDBObjectIDTable(self):
        """ Return the List of the RectObjID which were matched with an RadarObject
        @return RectObjIDList
        """
        if len(self.__bestDBObjectIDTable):
            return self.__bestDBObjectIDTable[0]
        else:
            return []


class BaseAdasObject(object):
    """
    base class for all adas objects
    """

    __metaclass__ = ABCMeta

    def __init__(self, obj_id, data_source):
        """Constructor taking the distx, disty and the vrelx as argument
        :param obj_id: object id
        :param data_source: data source e.g. DB
        """
        self.__id = obj_id
        self._data_source = data_source
        # Signals
        self._signals = {}
        self.__class_norm = {}

    def SetClassNorm(self, filter_reference, class_norm):
        """
        Sets the classification norm for a
        FilterReference
        :param filter_reference: FilterReference (reference object, object filter interface) tuple
        :param class_norm: classification norm, abstracted term for distance to referece object
        """
        self.__class_norm[(filter_reference.ref_obj, filter_reference.obj_filter_if)] = class_norm

    def GetClassNorm(self, ref_obj, filter_if):
        """
        Gets the classification norm belonging to a
        (reference object, object filter interface) tuple
        :param filter_reference: FilterReference (reference object, object filter interface) tuple
        :param class_norm: classification norm, abstracted term for distance to referece object
        """
        return self.__class_norm[(ref_obj, filter_if)]

    def _GetSubsetOfSignals(self, startts=None, stopts=None):

        """Makes a subset of the signals within the time interval
        :param startts: start time slot
        :param stopts: stop time slot
        """
        subset_signals = {}
        for sig_name, sig_val in self._signals.iteritems():
            subset_signals[sig_name] = \
                sig_val.GetSubsetForTimeInterval(startts, stopts)
        return subset_signals

    @abstractmethod
    def GetSubset(self, startts=None, stopts=None):
        """
        abstact method
        """
        pass

    def GetId(self):
        """
        Get Object Id
        """
        return self.__id

    def GetStartTime(self):
        """Get the Start Time of the Object
        @return: start time slot or None if no signals
        """
        sig_names = self._signals.keys()
        if sig_names:
            return self._signals[sig_names[0]].GetStartTimestamp()
        else:
            log.logging.error("No signals available")
            return None

    def GetEndTime(self):
        """Get the Start Time of the Object
        @return: start time slot or None if no signals
        """
        sig_names = self._signals.keys()
        if sig_names:
            return self._signals[sig_names[0]].GetEndTimestamp()
        else:
            log.logging.error("No signals available")
            return None

    def GetSignalValue(self, signal_name, timestamp):
        """Get the Object Signal Value for the given Timestamp
        @return: signal value at the given time stamp (GetValueAtTimestamp) or None if no such signal
        """
        if signal_name in self._signals.keys():
            return self._signals[signal_name].GetValueAtTimestamp(timestamp)
        else:
            log.logging.error("No such signal available")
            return None

    def GetSignal(self, signal_name):
        """
        Return an Get the Object Signal Value
        for the given Timestamp  enumerable
        GetFirstTrackedObjSnapshot()
        @return: Signals by the signal_name
        """
        if signal_name in self._signals.keys():
            return self._signals[signal_name]
        else:
            log.logging.error("No such signal available")
            return None


class BaseObjectList:
    """Base Object List
    """
    __metaclass__ = ABCMeta

    @abstractmethod
    def __init__(self, data_source, sensor, list_name, object_filter_if):
        """Initialize the Object List
        :param data_source: data source e.g. db
        :param sensor: Sensor Name (ARS4xx, ...)
        :param list_name: list name
        :param object_filter_if: filter object
        """
        self._data_source = data_source
        self.__sensor = sensor
        self.__list_name = list_name
        self.__object_filter_if = object_filter_if
        self._objects = []

    def __str__(self):
        pass

    def GetSensor(self):
        """Get the sensor name
        @return: name of the sensor
        """
        return self.__sensor

    def GetName(self):
        """Get the list name
        @return: list name
        """
        return self.__list_name

    def GetObjectById(self, obj_id):
        """Get the object
        :param obj_id: object id for lookup
        @return: list of objects where obj_id matches
        """
        return [x for x in self._objects if x.GetId() == obj_id]

    def GetObjects(self):
        """Get all objects
        @return: list of adas objects
        """
        return self._objects

    def GetObjectsByTimeStamp(self, ref_obj, startts=None, stopts=None, **kwargs):
        """GetObjectsByTimeStamp
        :param ref_obj: reference object
        :param startts: start time slot
        :param stopts: stop time slot
        @return: dictionary of matching objects (list) per time slot(=key)
            {ts1:[obj1, obj2, obj3], ts2:[obj1, obj2]}
        """
        return self.__object_filter_if.GetFilteredObjects(self._objects, ref_obj, startts, stopts, **kwargs)

    def GetBestTrackedObject(self, ref_obj, startts=None, stopts=None, **kwargs):
        """GetBestTrackedObject
        :param ref_obj: reference object
        :param startts: start time slot
        :param stopts: stop time slot
        @return:  [best_obj1, best_obj2] with Signals best_obj1: ts1..ts2 best_obj2: ts3..ts4 where ts2<ts3 etc.
        """
        objects_by_time_stamp = \
            self.GetObjectsByTimeStamp(ref_obj, startts, stopts, **kwargs)

        prev_best_obj = None
        #dictionary of matching object (one single) per time slot(=key)
        best_object_by_time_stamp = OrderedDict()
        for ts, obj_list in objects_by_time_stamp.iteritems():
            if (len(obj_list) == 1):
                best_object_by_time_stamp[ts] = obj_list[0]
            elif(len(obj_list) == 0):
                best_object_by_time_stamp[ts] = None
            else:
                # select best object from multiple candidates based on the classification norm
                best_obj = None
                for obj in obj_list:
                    if best_obj is None:
                        best_obj = obj
                    else:
                        curr_obj_dist_to_ref_obj = obj.GetClassNorm(ref_obj, self.__object_filter_if)
                        best_obj_dist_to_ref_obj = obj.GetClassNorm(ref_obj, self.__object_filter_if)
                        # if obj is closer to ref_obj than the best in the candidate list until now,
                        # it is a better match, add as the best
                        if curr_obj_dist_to_ref_obj < best_obj_dist_to_ref_obj:
                            best_obj = obj
                        # if obj is as close to ref_obj as the best in the candidate list until now,
                        # it can win if it was also the best obj in the previous time stamp, ...
                        elif curr_obj_dist_to_ref_obj == best_obj_dist_to_ref_obj:
                            if (prev_best_obj is not None) and (obj == prev_best_obj):
                                best_obj = obj
                            # ...otherwise the first equally good candidate remains the winner
                        # obj is worse than the current best
                        else:
                            pass
                # assign best object to ts
                prev_best_obj = best_obj
                best_object_by_time_stamp[ts] = best_obj

        return BaseObjectList.__CreateObjListFromBestObjPerTs(best_object_by_time_stamp)

    @staticmethod
    def __CreateObjListFromBestObjPerTs(best_object_by_time_stamp_ordered_dict):
        """
        best_object_by_time_stamp_ordered_dict must be an OrderedDict
        Converts [ts1: [best_obj1], ts2: [best_obj2], ts3: [best_obj2]] to
                 [best_obj1, best_obj2] with Signals best_obj1: ts1, best_obj2: ts2..ts3
        """
        start_ts = None
        end_ts = None
        best_object_list = []
        prev_obj = None
        time_slots = best_object_by_time_stamp_ordered_dict.keys()
        last_ts = max(time_slots)
        for tstamp, obj in best_object_by_time_stamp_ordered_dict.iteritems():
            if obj is not None:
                # init
                if start_ts is None:
                    start_ts = tstamp
                    prev_obj = obj
                else:
                    # new track
                    if (obj is not prev_obj):
                        best_object_list.append(prev_obj.GetSubset(start_ts, end_ts))
                        start_ts = tstamp
                    # end of interval
                    if (tstamp == last_ts):
                        best_object_list.append(obj.GetSubset(start_ts, tstamp))
                end_ts = tstamp
                prev_obj = obj

        return best_object_list

    def SetFilter(self, obj_filter_if):
        """Set Filter Object
        @param obj_filter_if: object filter
        """
        self.__object_filter_if = obj_filter_if

    @abstractmethod
    def LoadObjects(self, meas_id, startts=None, stopts=None, **kwargs):
        """Load all tracked Objects in the given timespan.
        @param startts: Abs Start Timestamp
        @param stopts: Abs Stop Timestamp
        @param kwargs: optional arguments ('testcase_types')
        """
        pass


"""
$Log: adas_objects.py  $
Revision 1.1 2021/12/13 17:58:33CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/project.pj
Revision 1.18 2013/12/05 07:34:20CET uidg3354 
commented out part was added again
- Added comments -  uidg3354 [Dec 5, 2013 7:34:20 AM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.17 2013/12/03 17:52:06CET Sandor-EXT, Miklos (uidg3354) 
commented out not implemented and used extensions because of coverage
--- Added comments ---  uidg3354 [Dec 3, 2013 5:52:06 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.16 2013/12/03 17:22:50CET Sandor-EXT, Miklos (uidg3354) 
pep8
--- Added comments ---  uidg3354 [Dec 3, 2013 5:22:51 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.15 2013/12/03 13:47:38CET Sandor-EXT, Miklos (uidg3354)
object matching
--- Added comments ---  uidg3354 [Dec 3, 2013 1:47:38 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.14 2013/04/05 07:04:58CEST Raedler, Guenther (uidt9430)
- fixed renaming error
--- Added comments ---  uidt9430 [Apr 5, 2013 7:04:59 AM CEST]
Change Package : 175136:1 http://mks-psad:7002/im/viewissue?selection=175136
Revision 1.13 2013/04/03 08:02:16CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:16 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.12 2013/03/28 15:25:15CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:16 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.11 2013/03/28 14:43:06CET Mertens, Sven (uidv7805)
pylint: resolving some R0904, R0913, R0914, W0107
--- Added comments ---  uidv7805 [Mar 28, 2013 2:43:07 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.10 2013/03/28 14:20:07CET Mertens, Sven (uidv7805)
pylint: solving some W0201 (Attribute %r defined outside __init__) errors
Revision 1.9 2013/03/28 10:05:27CET Mertens, Sven (uidv7805)
removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 10:05:28 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/28 09:33:17CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:17 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/22 08:24:26CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
Revision 1.6 2013/03/01 15:52:54CET Hecker, Robert (heckerr)
Updates recording Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 3:52:54 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/28 08:12:20CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:21 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/27 17:55:12CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:12 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/27 16:19:57CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:58 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/26 20:14:24CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:14:24 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 10:49:59CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/obj/project.pj
------------------------------------------------------------------------------
-- from ETK/VPC/validation_radar_objects.py Archive
------------------------------------------------------------------------------
Revision 1.17 2012/11/23 11:00:52CET Hammernik-EXT, Dmitri (uidu5219)
- bugfix: added changes from revision 1.15
--- Added comments ---  uidu5219 [Nov 23, 2012 11:00:53 AM CET]
Change Package : 163367:1 http://mks-psad:7002/im/viewissue?selection=163367
Revision 1.16 2012/10/10 11:16:15CEST Hammernik-EXT, Dmitri (uidu5219)
- removed rectobjid attribute
--- Added comments ---  uidu5219 [Oct 10, 2012 11:16:15 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.15 2012/09/18 08:47:05CEST Sampat, Janani Vasumathy (uidu5218)
- bug fix for detecting objects inside the ROI that start and stop within the ROI (GetObjectsInRectObject)
--- Added comments ---  uidu5218 [Sep 18, 2012 8:47:08 AM CEST]
Change Package : 148800:1 http://mks-psad:7002/im/viewissue?selection=148800
Revision 1.14 2012/09/13 12:20:04CEST Hammernik-EXT, Dmitri (uidu5219)
- bugfix in GetSignal: end_idx=len(self.__object[signal])
- added functionalty to get Signal information for same start and end index
--- Added comments ---  uidu5219 [Sep 13, 2012 12:20:04 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.13 2012/08/24 09:01:25CEST Hammernik-EXT, Dmitri (uidu5219)
- added rectobjid to the object
--- Added comments ---  uidu5219 [Aug 24, 2012 9:01:25 AM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.12 2012/08/10 10:35:01CEST Sampat-EXT, Janani Vasumathy (uidu5218)
- option to retrieve only objects inside a rectangular object that line inside the rect
--- Added comments ---  uidu5218 [Aug 10, 2012 10:35:01 AM CEST]
Change Package : 110628:1 http://mks-psad:7002/im/viewissue?selection=110628
Revision 1.11 2012/07/02 13:51:00CEST Hammernik-EXT, Dmitri (uidu5219)
- defined get/set methods for rectobjid from DB
--- Added comments ---  uidu5219 [Jul 2, 2012 1:51:01 PM CEST]
Change Package : 100180:1 http://mks-psad:7002/im/viewissue?selection=100180
Revision 1.10 2012/04/17 17:44:04CEST Sampat-EXT, Janani Vasumathy (uidu5218)
- gating and box calulation changed
- values are rounded
--- Added comments ---  uidu5218 [Apr 17, 2012 5:44:06 PM CEST]
Change Package : 110628:1 http://mks-psad:7002/im/viewissue?selection=110628
Revision 1.9 2012/03/28 13:44:31CEST Sampat-EXT, Janani Vasumathy (uidu5218)
- enhanced GetSignal function to return a list with start and stop index
--- Added comments ---  uidu5218 [Mar 28, 2012 1:44:31 PM CEST]
Change Package : 97504:2 http://mks-psad:7002/im/viewissue?selection=97504
Revision 1.8 2012/03/27 16:26:24CEST Raedler-EXT, Guenther (uidt9430)
- added new function GetObjectsInRectObject() to find all objects which are inside the given label
- use RadarObject class to encapsulate the object dictionary
- renamed some variables
--- Added comments ---  uidt9430 [Mar 27, 2012 4:26:25 PM CEST]
Change Package : 88554:1 http://mks-psad:7002/im/viewissue?selection=88554
Revision 1.7 2012/03/27 15:41:43CEST Raedler-EXT, Guenther (uidt9430)
- reintegrate branch into trunk
- add function GetBestObjectsListByReflectionPoint() for the new approach
- add function  GetBestObjectsListByGate() for the old approach
- use existing function GetBestObjectsList() as interface for existing observers
--- Added comments ---  uidt9430 [Mar 27, 2012 3:41:44 PM CEST]
Change Package : 88554:1 http://mks-psad:7002/im/viewissue?selection=88554
Revision 1.4.1.2 2012/01/24 16:48:44CET Oprisan, Dan (oprisand)
- further development of FindBestObject startegy
--- Added comments ---  oprisand [Jan 24, 2012 4:48:45 PM CET]
Change Package : 46865:30 http://mks-psad:7002/im/viewissue?selection=46865
Revision 1.4.1.1 2012/01/16 10:41:33CET Oprisan, Dan (oprisand)
- improvement of object selection (find best objects)
--- Added comments ---  oprisand [Jan 16, 2012 10:41:33 AM CET]
Change Package : 46865:30 http://mks-psad:7002/im/viewissue?selection=46865
Revision 1.6 2012/02/01 11:49:44CET Raedler-EXT, Guenther (uidt9430)
- change ObjectID change conditions
--- Added comments ---  uidt9430 [Feb 1, 2012 11:49:45 AM CET]
Change Package : 90579:1 http://mks-psad:7002/im/viewissue?selection=90579
Revision 1.5 2012/01/17 16:54:32CET Raedler-EXT, Guenther (uidt9430)
- fixed error in interpolation of the orientation signal
- improved best object selection
- fixed error in post processing
Revision 1.4 2011/11/29 13:11:33CET Sampat-EXT, Janani Vasumathy (uidu5218)
- Index list removed
- Best Objects complete calculation split into 3 functions
- Table column values are given generic names instead of numbers
--- Added comments ---  uidu5218 [Nov 29, 2011 1:11:33 PM CET]
Change Package : 88149:1 http://mks-psad:7002/im/viewissue?selection=88149
Revision 1.3 2011/11/25 09:57:17CET Raedler-EXT, Guenther (uidt9430)
- improved relevant object detection
- added oncoming
- changed gating
- fixed error in the best object detection
--- Added comments ---  uidt9430 [Nov 25, 2011 9:57:18 AM CET]
Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.2 2011/11/08 08:36:26CET Raedler Guenther (uidt9430) (uidt9430)
- started to implement GetBestObjectsList using Boxes and Reflectionpoints (effective code is commented out)
--- Added comments ---  uidt9430 [Nov 8, 2011 8:36:26 AM CET]
Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.1 2011/10/27 15:38:30CEST Raedler Guenther (uidt9430) (uidt9430)
Initial revision
Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/
05_Testing/05_Test_Environment/algo/ars301_req_test/valf_tests/vpc/project.pj

"""
