"""
stk/obj/label_objects.py
-------------------

Base implementations of the object filters

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:34CET $
"""
# Import Python Modules -------------------------------------------------------
from operator import itemgetter

# Import STK Modules ----------------------------------------------------------
from stk.obj.adas_objects import BaseAdasObject, BaseObjectList, OBJ_2_DB_NAME, OBJ_RECTOBJECT_ID, OBJ_TS
from stk.val.result_types import Signal
from stk.obj.error import AdasObjectLoadError

# Class Implementations -------------------------------------------------------


class DbObjectList(BaseObjectList):
    """
    DbObjectList
    """
    def __init__(self, data_source, sensor, list_name, object_filter_if):
        BaseObjectList.__init__(self, data_source, sensor, list_name, object_filter_if)

    def LoadObjects(self, meas_id, startts=None, stopts=None):
        """Load all tracked Objects in the given timespan for given measid
        :param meas_id: measurement identifier
        :type meas_id: integer
        :param startts: absolute start time stamp
        :type startts: long
        :param stopts: absolute stop time stamp
        :type stopts: long
        :return: True when the query has been successful, otherwise False
        """

        # clear objects:
        self._objects = []

        # get all existing rectangular objects for the given meas id
        object_id_list = self._data_source.GetRectObjectIds(meas_id)

        # exception handling
        if not object_id_list:
            return False

        # create LabelRectObject:
        for obj_id in object_id_list:
            self._objects.append(LabelRectObject(obj_id[OBJ_2_DB_NAME[OBJ_RECTOBJECT_ID]],
                                                 startts, stopts, self._data_source))

        return True


class LabelRectObject(BaseAdasObject):
    """ Object in the label database """
    def __init__(self, obj_id, startts, stopts, data_source, signals=None):
        """Constructor creating a rectangular object either from data_source or from signals if specified
        :param obj_id: object id
        :param startts: absolute start time stamp
        :type startts: long
        :param stopts: absolute stop time stamp
        :type stopts: long
        :param data_source: data source, e.g. DB
        :param signals: if this is specified, signals are directly filled with it; data source is not used for filling
        """
        BaseAdasObject.__init__(self, obj_id, data_source)
        if (signals is not None):
            self._signals = signals
        else:
            self.__FillObjectData(obj_id, startts, stopts)

    def GetSubset(self, startts=None, stopts=None):
        """Makes a subset of the signals within the time interval
        :param startts: start time slot
        :param stopts: stop time slot
        """
        return LabelRectObject(self.GetId(), startts, stopts,
                               self._data_source, self._GetSubsetOfSignals(startts, stopts))

    def __del__(self):
        """List of custom specific object signals. Loaded when object_ext_if is provided.
        """
        pass

    def __FillObjectData(self, obj_id, startts, stopts):
        """Fills in signals from DB within the time interval
        :param obj_id: object id
        :param startts: start time slot
        :param stopts: stop time slot
        """
        # get all kinematics records belonging to the rectangular object id
        #obj_rec = self._data_source.GetRectObjectById(obj_id)
        obj_rec = self._data_source.GetRectObjectByRectObjId(obj_id)

        kin_records = self._data_source.GetRectObjectKinematics(obj_id)
        # exception handling
        if (len(obj_rec) == 0) or (len(obj_rec) > 1) or (not kin_records):
            raise AdasObjectLoadError("Database query returned empty list")
        else:
            obj_rec = obj_rec[0]

        # filter out kinetic records according to startts and stopts if specified
        filtered_kin_records = [rec for rec in kin_records if not
                                (((startts is not None) and (rec[OBJ_2_DB_NAME[OBJ_TS]] < startts)) or
                                 ((stopts is not None) and (rec[OBJ_2_DB_NAME[OBJ_TS]] > stopts)))]

        # sort kinetic records according to time
        filtered_kin_records_by_time = sorted(filtered_kin_records, key=itemgetter(OBJ_2_DB_NAME[OBJ_TS]))

        # ordered list of all time slots occurring in the kinetics table
        time_slot_seq = [d[OBJ_2_DB_NAME[OBJ_TS]] for d in filtered_kin_records_by_time]

        # convert static parameters of rectangular object into Signals
        # value is the same for all time slots
        rect_obj_stat_signals = {}
        for name, val in obj_rec.iteritems():
            # RECTOBJID is not to be converted to a new signal
            if (name != OBJ_2_DB_NAME[OBJ_RECTOBJECT_ID]):
                rect_obj_stat_signals[name] = Signal(name, None, [val] * len(time_slot_seq), time_slot_seq, val, val)

        # convert kinetic parameters belonging to a rectangular object into Signals
        # value can vary depending on the time slot
        rect_obj_kin_signals = {}
        tmp_value_dict_list = {}
        for kin_rec in filtered_kin_records_by_time:
            for field_name, value in kin_rec.iteritems():
                if (field_name in tmp_value_dict_list):
                    tmp_value_dict_list[field_name].append(value)
                else:
                    # KINABSTS is not to be converted to a new signal, it is represented as time_slot_seq above
                    if (field_name != OBJ_2_DB_NAME[OBJ_TS]):
                        tmp_values = []
                        tmp_values.append(value)
                        tmp_value_dict_list[field_name] = tmp_values
        for name, val in tmp_value_dict_list.iteritems():
            rect_obj_kin_signals[name] = Signal(name, None, val, time_slot_seq, min(val), max(val))

        # join static and kinetic signals
        rect_object_complete_signals = rect_obj_stat_signals
        rect_object_complete_signals.update(rect_obj_kin_signals)
        self._signals = rect_object_complete_signals

        return True

"""
$Log: label_objects.py  $
Revision 1.1 2021/12/13 17:58:34CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/project.pj
Revision 1.3 2013/12/03 13:47:38CET uidg3354 
object matching
- Added comments -  uidg3354 [Dec 3, 2013 1:47:39 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
"""
