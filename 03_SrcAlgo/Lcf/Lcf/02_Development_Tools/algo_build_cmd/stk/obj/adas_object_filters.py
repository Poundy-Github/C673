"""
stk/obj/adas_object_filters.py
-------------------

Base implementations of the object filters

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:33CET $
"""
# Import Python Modules -------------------------------------------------------
from abc import ABCMeta, abstractmethod
import math
from stk.obj.pythonext.ordereddict import OrderedDict

# Import STK Modules ----------------------------------------------------------
from stk.obj.geo.rect import Rectangle
from stk.obj.adas_objects import OBJ_2_DB_NAME, OBJ_LENGTH, OBJ_WIDTH, OBJ_DISTX, OBJ_DISTY, OBJ_VELX, OBJ_ORIENT


# Class Implementations -------------------------------------------------------
class ObjectFilterIf(object):  # pylint: disable=R0903
    """ Object filter interface """
    __metaclass__ = ABCMeta

    @abstractmethod
    def __init__(self):
        """ Constructor """
        pass

    @abstractmethod
    def GetFilteredObjects(self, obj_list, ref_obj, startts=None, stopts=None, **kwargs):
        """ GetFilteredObjects abstractmethod"""
        pass


class FilterReference():   # pylint: disable=R0903
    """
    result of a filtering is dependent of the reference object and the used filter
    """
    def __init__(self, ref_obj, obj_filter_if):
        """
        :param ref_obj: reference object
        :param obj_filter_if: object filter interface e.g. ObjectByGateFilter
        """
        self.ref_obj = ref_obj
        self.obj_filter_if = obj_filter_if


class ObjectByGateFilter(ObjectFilterIf):  # pylint: disable=R0903
    """ Object filter by gate """
    def __init__(self):
        """ Constructor """
        ObjectFilterIf.__init__(self)

    def GetFilteredObjects(self, obj_list, ref_obj, startts=None, stopts=None, **kwargs):
        """ Returns a best matching object list to ref_obj
            from the obj_list for each time slot {ts1:[obj1, obj2, obj3], ts2:[obj1, obj2]}
            if ref_obj=None, it returns all object ids in time slot 0
            :param obj_list: object list from which to select
            :param ref_obj: reference object
            :param startts: start time slot
            :param stopts: stop time slot
            :param gate_dist_x: gate value for x distance (diff to ref obj must be less)
            :param gate_dist_y: gate value for y distance (diff to ref obj must be less)
            :param gate_vrelx: gate value for x velocity (diff to ref obj must be less)
            @return: OrderedDict() {ts0:[obj0,obj1,...], ts1:[obj0,obj1,...],...} where ts0 < ts1
                     The objects itself are assigned a classification norm (~distance),
                     which can be used in further matching/tracking algorithms
INPUT:
--------------------------------------------------------
distance from the ref_obj for a given time slot:
d(obj1) < d(obj2) < d(obj3), gate_x, gate_y, gate_vel


|--0--||--1--||--2--||--3--||--4--||--5--|   => startts = 0, stopts = 5

       |-----||-----||-----||-----|          => ref_obj
              |-----||-----|                 => obj1
|-----||-----||-----||-----|                 => obj2
|-----||-----||-----||-----||-----|          => obj3

CASE1: OUTPUT: best_object_list
--------------------------------------------------------
       |-----|                               => obj2
              |-----||-----|                 => obj1
                            |-----|          => obj3

        """

        gate_dist_x = 3
        gate_dist_y = 6
        gate_vrelx = 5
        if "gate_dist_x" in kwargs.keys():
            gate_dist_x = kwargs["gate_dist_x"]
        if "gate_dist_y" in kwargs.keys():
            gate_dist_y = kwargs["gate_dist_y"]
        if "gate_vrelx" in kwargs.keys():
            gate_vrelx = kwargs["gate_vrelx"]

        best_object_list_for_all_ts = OrderedDict()
        # find the best matching object
        # within the timespan of the ref_obj for each time slot
        ref_obj_distx_sig = (ref_obj.GetSignal(OBJ_2_DB_NAME[OBJ_DISTX])).GetSubsetForTimeInterval(startts, stopts)
        ref_obj_disty_sig = (ref_obj.GetSignal(OBJ_2_DB_NAME[OBJ_DISTY])).GetSubsetForTimeInterval(startts, stopts)
        ref_obj_velx_sig = (ref_obj.GetSignal(OBJ_2_DB_NAME[OBJ_VELX])).GetSubsetForTimeInterval(startts, stopts)

        # find startts and stopts of ref_obj and
        # filter out the other objects for this interval
        ref_obj_timestamps = ref_obj_distx_sig.GetTimestamps()

        for tstamp in ref_obj_timestamps:
            #best_obj_distance_in_ts = None
            best_obj_list = []
            ref_obj_distx = ref_obj_distx_sig.GetValueAtTimestamp(tstamp)
            ref_obj_disty = ref_obj_disty_sig.GetValueAtTimestamp(tstamp)
            ref_obj_velx = ref_obj_velx_sig.GetValueAtTimestamp(tstamp)
            for obj in obj_list:
                obj_distx = (obj.GetSignal(OBJ_2_DB_NAME[OBJ_DISTX])).GetValueAtTimestamp(tstamp)
                obj_disty = (obj.GetSignal(OBJ_2_DB_NAME[OBJ_DISTY])).GetValueAtTimestamp(tstamp)
                obj_velx = (obj.GetSignal(OBJ_2_DB_NAME[OBJ_VELX])).GetValueAtTimestamp(tstamp)

                if (obj_distx is not None) and \
                   (obj_disty is not None) and \
                   (obj_velx is not None):

                    # get all objects in the gate and calculate distance
                    if (ObjectByGateFilter.__IsObjInGate(obj_distx, obj_disty, obj_velx,
                                                         ref_obj_distx, ref_obj_disty, ref_obj_velx,
                                                         gate_dist_x, gate_dist_y, gate_vrelx)):

                        curr_obj_distance = ObjectByGateFilter.__EuclideanDistance2D(obj_distx, obj_disty,
                                                                                     ref_obj_distx, ref_obj_disty)
                        obj.SetClassNorm(FilterReference(ref_obj, self), curr_obj_distance)
                        best_obj_list.append(obj)

                        '''
                        # if only the best distance would be selected
                        if (best_obj_distance_in_ts is None):
                            best_obj_distance_in_ts = curr_obj_distance
                            best_obj_list.append(obj)
                        elif (best_obj_distance_in_ts == curr_obj_distance):
                            best_obj_list.append(obj)
                        elif (best_obj_distance_in_ts > curr_obj_distance):
                            best_obj_distance_in_ts = curr_obj_distance
                            best_obj_list = []
                            best_obj_list.append(obj)
                        '''

            best_object_list_for_all_ts[tstamp] = best_obj_list

        return best_object_list_for_all_ts

    @staticmethod
    def __EuclideanDistance2D(xc1, yc1, xc2, yc2):
        """ Euclidean Distance between two signals in 2D """
        # ..or numpy.linalg.norm( array([x1,y1], array([x2, y2]) )
        return math.sqrt(math.pow(xc1 - xc2, 2) + math.pow(yc1 - yc2, 2))

    @staticmethod
    def __IsObjInGate(obj_x, obj_y, obj_velx, ref_obj_x, ref_obj_y, ref_obj_velx,
                      gate_dist_x, gate_dist_y, gate_vrelx):
        # pylint: disable=R0913
        """ distance is smaller than threshold for the whole list"""
        return ((math.fabs(obj_x - ref_obj_x) < gate_dist_x) and
                (math.fabs(obj_y - ref_obj_y) < gate_dist_y) and
                (math.fabs(obj_velx - ref_obj_velx) < gate_vrelx))


class ObjectByReflectionPoint(ObjectFilterIf):  # pylint: disable=R0903
    """ Object Filter by Reflexionpoint """
    def __init__(self):
        """ Constructor """
        ObjectFilterIf.__init__(self)

    def GetFilteredObjects(self, obj_list, ref_obj,
                           startts=None, stopts=None, **kwargs):
        pass


class ObjectInRectangle(ObjectFilterIf):  # pylint: disable=R0903
    """ Object Filter in Rectangle """
    def __init__(self):
        """ Constructor """
        ObjectFilterIf.__init__(self)

    def GetFilteredObjects(self, obj_list, ref_obj,
                           startts=None, stopts=None, **kwargs):
        # pylint: disable=R0914
        """ Returns an object list from the obj_list for each time slot
            which objects are in the Region of Interest (ROI) = ref_obj
            if ref_obj=None, it returns all object ids in time slot 0
            :param obj_list: object list from which to select
            :param ref_obj: reference object
            :param startts: start time slot
            :param stopts: stop time slot
            @return: OrderedDict() {ts0:[obj0,obj1,...], ts1:[obj0,obj1,...],...} where ts0 < ts1
                     The objects itself are assigned a classification norm (~distance),
                     which can be used in further matching/tracking algorithms
        INPUT:
        --------------------------------------------------------
        distance from the ref_obj for a given time slot:
        ref_obj is a ROI (Region of Interrest), it is chekced, whether all objects are within the ROI

        |--0--||--1--||--2--||--3--||--4--||--5--|   => startts = 0, stopts = 5

               |-----||-----||-----||-----|          => ref_obj
                      |-----||-----|                 => obj1
        |-----||-----||-----||-----|                 => obj2
        |-----||-----||-----||-----||-----|          => obj3

        OUTPUT: for ObjectInRect
        --------------------------------------------------------
                      |-----||-----|                 => obj1
               |-----||-----||-----|                 => obj2
               |-----||-----||-----|                 => obj3 (moved out of ROI for ts4)

        """

        object_in_ref_obj_list_for_all_ts = OrderedDict()
        # find the best matching object
        # within the timespan of the ref_obj for each time slot
        ref_obj_distx_sig = (ref_obj.GetSignal(OBJ_2_DB_NAME[OBJ_DISTX])).GetSubsetForTimeInterval(startts, stopts)
        ref_obj_disty_sig = (ref_obj.GetSignal(OBJ_2_DB_NAME[OBJ_DISTY])).GetSubsetForTimeInterval(startts, stopts)
        ref_obj_head_sig = (ref_obj.GetSignal(OBJ_2_DB_NAME[OBJ_ORIENT])).GetSubsetForTimeInterval(startts, stopts)
        ref_obj_length_sig = (ref_obj.GetSignal(OBJ_2_DB_NAME[OBJ_LENGTH])).GetSubsetForTimeInterval(startts, stopts)
        ref_obj_width_sig = (ref_obj.GetSignal(OBJ_2_DB_NAME[OBJ_WIDTH])).GetSubsetForTimeInterval(startts, stopts)

        # find startts and stopts of ref_obj and filter out the other objects for this interval
        #new_startts = ref_obj_distx_sig.GetStartTimestamp()
        #new_stopts  = ref_obj_distx_sig.GetEndTimestamp()
        ref_obj_timestamps = ref_obj_distx_sig.GetTimestamps()

        for tstamp in ref_obj_timestamps:
            object_in_ref_obj_list = []
            ref_obj_distx = ref_obj_distx_sig.GetValueAtTimestamp(tstamp)
            ref_obj_disty = ref_obj_disty_sig.GetValueAtTimestamp(tstamp)
            ref_obj_head = ref_obj_head_sig.GetValueAtTimestamp(tstamp)
            ref_obj_length = ref_obj_length_sig.GetValueAtTimestamp(tstamp)
            ref_obj_width = ref_obj_width_sig.GetValueAtTimestamp(tstamp)

            box_gate = Rectangle(ref_obj_length / 2, ref_obj_length / 2,
                                 ref_obj_width / 2, ref_obj_width / 2)
            box_gate.Rotate(ref_obj_head)

            for obj in obj_list:
                obj_distx = (obj.GetSignal(OBJ_2_DB_NAME[OBJ_DISTX])).GetValueAtTimestamp(tstamp)
                obj_disty = (obj.GetSignal(OBJ_2_DB_NAME[OBJ_DISTY])).GetValueAtTimestamp(tstamp)
                obj_velx = (obj.GetSignal(OBJ_2_DB_NAME[OBJ_VELX])).GetValueAtTimestamp(tstamp)

                if (obj_distx is not None) and (obj_disty is not None) and (obj_velx is not None):
                    diff_distx = obj_distx - ref_obj_distx
                    diff_disty = obj_disty - ref_obj_disty
                    if box_gate.PolygonContainsPoint(diff_distx, diff_disty):
                        # if in the box, dist is set to zero. could be refined in the future
                        curr_obj_distance = 0
                        obj.SetClassNorm(FilterReference(ref_obj, self), curr_obj_distance)
                        object_in_ref_obj_list.append(obj)
                    #dbg = 1 # breakpoint placeholder

            object_in_ref_obj_list_for_all_ts[tstamp] = object_in_ref_obj_list

        return object_in_ref_obj_list_for_all_ts


"""
$Log: adas_object_filters.py  $
Revision 1.1 2021/12/13 17:58:33CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/project.pj
Revision 1.3 2013/12/03 17:22:49CET uidg3354 
pep8
- Added comments -  uidg3354 [Dec 3, 2013 5:22:49 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.2 2013/12/03 13:46:53CET Sandor-EXT, Miklos (uidg3354)
object matching
--- Added comments ---  uidg3354 [Dec 3, 2013 1:46:53 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
"""
