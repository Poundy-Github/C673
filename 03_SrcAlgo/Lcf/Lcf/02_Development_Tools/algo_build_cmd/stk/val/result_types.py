"""
stk/val/result_types.py
-------------------

    basic result type classes

:org:           Continental AG
:author:        Guenther Raedler

:version    :       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:45CET $
"""
# Import Python Modules -------------------------------------------------------
import numpy as np
import sympy as sym
import sys

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------
import stk.db.gbl.gbl as db_gbl
from stk.db.gbl.gbl import COL_NAME_UNIT_ID, COL_NAME_UNIT_NAME, COL_NAME_UNIT_TYPE, COL_NAME_UNIT_LABEL
import stk.util.logger as log
from stk.db.gbl.gbl_defs import GblUnits
from stk.img.plot import ValidationPlot
# Import Local Python Modules -------------------------------------------------
from bisect import bisect_left
# Constant Definitions --------------------------------------------------------


class ValSaveLoadLevel():
    """ Database laod and save level definitions """
    VAL_DB_LEVEL_1 = int(1)  # includes the description level
    VAL_DB_LEVEL_2 = int(2)  # includes the basic results
    VAL_DB_LEVEL_3 = int(4)  # includes the assessment level
    VAL_DB_LEVEL_4 = int(8)  # includes images, detailed results

    VAL_DB_LEVEL_STRUCT = VAL_DB_LEVEL_1
    VAL_DB_LEVEL_BASIC = VAL_DB_LEVEL_STRUCT + VAL_DB_LEVEL_2
    VAL_DB_LEVEL_INFO = VAL_DB_LEVEL_BASIC + VAL_DB_LEVEL_3
    VAL_DB_LEVEL_ALL = VAL_DB_LEVEL_INFO + VAL_DB_LEVEL_4

    def __init__(self):
        pass

# Class Implementations -------------------------------------------------------


class BaseUnit():
    """ Unit class """

    UNIT_LABEL_MAP = {GblUnits.UNIT_L_MM: sym.Symbol("mm"),
                      GblUnits.UNIT_L_M: sym.Symbol("m"),
                      GblUnits.UNIT_L_KM: sym.Symbol("km"),
                      GblUnits.UNIT_L_US: sym.Symbol("us"),
                      GblUnits.UNIT_L_MS: sym.Symbol("ms"),
                      GblUnits.UNIT_L_S: sym.Symbol("s"),
                      GblUnits.UNIT_L_H: sym.Symbol("h"),
                      GblUnits.UNIT_L_MPS: sym.Symbol("m") / sym.Symbol("s"),
                      GblUnits.UNIT_L_KMPH: sym.Symbol("km") / sym.Symbol("h"),
                      GblUnits.UNIT_L_DEG: sym.Symbol("deg"),
                      GblUnits.UNIT_L_RAD: sym.Symbol("rad"),
                      GblUnits.UNIT_L_MPS2: sym.Symbol("m") / (sym.Symbol("s") ** 2),
                      GblUnits.UNIT_L_DEGPS: sym.Symbol("deg") / sym.Symbol("s"),
                      GblUnits.UNIT_L_RADPS: sym.Symbol("rad") / sym.Symbol("s"),
                      GblUnits.UNIT_L_CURVE: 1 / sym.Symbol("m"),
                      GblUnits.UNIT_L_NONE: sym.Symbol("none"),
                      GblUnits.UNIT_L_BINARY: sym.Symbol("0-1"),
                      GblUnits.UNIT_L_PERCENTAGE: sym.Symbol("%")}

    def __init__(self, name, label="", dbi_gbl=None):
        self.__name = name
        if isinstance(label, basestring):
            self.__label = sym.Symbol(label)
        else:
            self.__label = label

        self.__type = None
        self.__id = None
        if dbi_gbl is not None:
            self.Load(dbi_gbl)
        else:
            if name in self.UNIT_LABEL_MAP:
                self.__label = self.UNIT_LABEL_MAP[name]

    def __str__(self):
        """ Unit string """
        return "[" + str(self.__label) + "]"

    def __mul__(self, other):
        if(isinstance(other, BaseUnit)):
            MulUnit = BaseUnit(self.GetName() + "_x_" + other.GetName(), self.__label * other.GetLabel())
        else:
            MulUnit = None
            log.logging.error("Only BaseUnit multiplication are supported")
        return MulUnit

    def __pow__(self, other):
        if(isinstance(other, (int, float))):
            PowUnit = BaseUnit(self.GetName() + "_^_" + str(other), self.__label ** other)
        else:
            PowUnit = None
            log.logging.error("Exponent must be from type integer or float")
        return PowUnit

    def __div__(self, other):
        return self.__truediv__(other)

    def __truediv__(self, other):
        if(isinstance(other, BaseUnit)):
            DivUnit = BaseUnit(self.GetName() + "_/_" + other.GetName(), str(self.__label / other.GetLabel()))
        else:
            DivUnit = None
            log.logging.error("Only BaseUnit division are supported")
        return DivUnit

    def __floordiv__(self, other):
        return self.__truediv__(other)

    def GetName(self):
        """ Get the unit name """
        return self.__name

    def GetLabel(self):
        """ Get the unit label """
        return self.__label

    def GetId(self):
        """ Get the unit id """
        return self.__id

    def Load(self, dbi_gbl, uid=None):
        """ Load the Unit class from DB """

        if not issubclass(dbi_gbl.__class__, db_gbl.BaseGblDB):
            log.logging.error("GBL Database interface undefined")
            return False

        if uid is not None:
            unit_rec = dbi_gbl.GetUnit(uid=uid)
        else:
            unit_rec = dbi_gbl.GetUnit(name=self.__name)

        if unit_rec is not None:
            self.__name = unit_rec[COL_NAME_UNIT_NAME]
            self.__label = sym.Symbol(unit_rec[COL_NAME_UNIT_LABEL])
            self.__type = unit_rec[COL_NAME_UNIT_TYPE]
            self.__id = unit_rec[COL_NAME_UNIT_ID]
            return True

        return False


class BaseValue(object):
    """ Base Value class supporting unit and name """
    def __init__(self, name, unit, value):
        """ Base Value
        """
        self.__name = name
        self.__unit = unit
        try:
            self.__value = float(value)
        except StandardError:
            self.__value = None

    def __str__(self):
        return str(self.__value) + " " + str(self.__unit)

    def __neg__(self):
        return BaseValue("-" + self.GetName(), self.GetUnit(), -self.GetValue())

    def GetUnit(self):
        """ Get the unit string """
        return self.__unit

    def GetName(self):
        """ Get the Name of the Value """
        return self.__name

    def SetName(self, name):
        """ Get the Name of the Value """
        self.__name = name

    def GetValue(self):
        """ Get the Value """
        return self.__value


class ValueVector(BaseValue):
    """ Value Vector supporting unit and name for an array of values """
    def __init__(self, name, unit, value_vect, range_min, range_max):
        """ initialize the value array
            \todo implement
        :param name: name of the vector
        :param unit: BaseUnit class instance
        :param value_vect: vector of values (list)
        :param range_min: Minimal Value
        :param range_max: Maximal Value
        """
        BaseValue.__init__(self, name, unit, None)
        if value_vect is not None:
            self.__value_vector = value_vect
        else:
            self.__value_vector = []
        self.__value_range_min = range_min
        self.__value_range_max = range_max

    def __str__(self):
        """ Value Vector as sting """
        return str(self.GetValue())

    def __len__(self):
        """ return lenth of the vector """
        return len(self.__value_vector)

    def __getitem__(self, index):
        """ overloaded [] operator for getting """
        return self.GetValue(index)

    def __setitem__(self, index, value):
        """ overloaded [] operator for setting """
        self.SetValue(index, value)

    def GetMeanValue(self):
        """ Get the mean value """
        if(len(self.__value_vector) > 0):
            MeanVal = np.mean(self.__value_vector)
        else:
            log.logging.warning("Signal is empty")
            MeanVal = None
        return MeanVal

    def GetStandardDeviation(self):
        """ Get the standard deviation of the value vector"""
        if(len(self.__value_vector) > 0):
            StdDevVal = np.std(self.__value_vector)
        else:
            log.logging.warning("Signal is empty")
            StdDevVal = None
        return StdDevVal

    def GetMaxValue(self):
        """ Get the max value """
        if(len(self.__value_vector) > 0):
            MaxVal = np.max(self.__value_vector)
        else:
            log.logging.warning("Signal is empty")
            MaxVal = None
        return MaxVal

    def GetMinValue(self):
        """ Get the min value """
        if(len(self.__value_vector) > 0):
            MinVal = np.min(self.__value_vector)
        else:
            log.logging.warning("Signal is empty")
            MinVal = None
        return MinVal

    def GetRangeMin(self):
        """ Get the minimal possible value for the signal """
        return self.__value_range_min

    def GetRangeMax(self):
        """ Get the maximal possible value for the signal """
        return self.__value_range_max

    def GetValue(self, index=None):
        """ Get the vector of values """
        if index is None:
            vect = self.__value_vector
        elif index < len(self):
            vect = self.__value_vector[index]
        else:
            vect = None
        return vect

    def SetValue(self, index, value):
        """ Set vector value at given index """
        if (index < len(self)):
            if((value >= self.__value_range_min) & (value <= self.__value_range_max)):
                self.__value_vector[index] = value

    def InsertValue(self, value, index=None):
        """ Insert a new Value """
        ret = False
        if index is None:
            self.AppendValue(value)
        else:
            if isinstance(value, (list, tuple)):
                for val in reversed(value):
                    if (val >= self.__value_range_min) & (val <= self.__value_range_max):
                        self.__value_vector.insert(index, val)
                        ret = True
            else:
                if (value >= self.__value_range_min) & (value <= self.__value_range_max):
                    self.__value_vector.insert(index, value)
                    ret = True
        return ret

    def AppendValue(self, value):
        """ Append a single value or an array of values """
        ret = False
        if isinstance(value, (list, tuple)):
            for val in value:
                if (val >= self.__value_range_min) & (val <= self.__value_range_max):
                    self.__value_vector.append(val)
                    ret = True
        else:
            if (value >= self.__value_range_min) & (value <= self.__value_range_max):
                self.__value_vector.append(value)
                ret = True
        return ret

    def GetFirstValueOverThres(self, threshold=None):
        """ Get the first value exceeding the given threshold """
        if threshold is None:
            threshold = self.GetRangeMin()

        ValOverThres = [Val for Val in self.__value_vector if Val > threshold]

        if(len(ValOverThres) > 0):
            FirstVal = ValOverThres[0]
        else:
            FirstVal = None
        return FirstVal

    def GetLastValueOverThres(self, threshold=None):
        """ Get the last value exceeding the given threshold """
        if threshold is None:
            threshold = self.GetRangeMin()

        # reverse signal and use bisect_left because the signal can have some gaps
        RevVect = reversed(self.__value_vector)

        ValOverThres = [Val for Val in RevVect if Val > threshold]

        if(len(ValOverThres) > 0):
            LastVal = ValOverThres[0]
        else:
            LastVal = None
        return LastVal

    def GetLastStableSliceOverThres(self, threshold=None, bridgeable_gap=0):
        """ Get the last stable slice over the given threshold """
        ArrayId = 0
        if threshold is None:
            threshold = self.GetRangeMin()

        ValIndexOverThres = [i for i, Val in enumerate(self.__value_vector) if Val > threshold]

        if len(ValIndexOverThres) > 1:
            # reverse the index list since we look for the last stable slice over threshold
            ValIndexOverThres.reverse()
            for ArrayId, Val in enumerate(ValIndexOverThres[:-1]):
                if (Val - ValIndexOverThres[ArrayId + 1]) > (bridgeable_gap + 1):
                    break
            else:
                ArrayId = ArrayId + 1
            Slice = ValueVector(self.GetName() + "_StableSlice", self.GetUnit(),
                                self.__value_vector[ValIndexOverThres[ArrayId]:(ValIndexOverThres[0] + 1)],
                                self.GetRangeMin(),
                                self.GetRangeMax())
        elif(len(ValIndexOverThres) == 1):
            Slice = ValueVector(self.GetName() + "_StableSlice", self.GetUnit(),
                                [self.__value_vector[ValIndexOverThres[0]]],
                                self.GetRangeMin(),
                                self.GetRangeMax())
        else:
            Slice = ValueVector(self.GetName() + "_StableSlice", self.GetUnit(),
                                [],
                                self.GetRangeMin(),
                                self.GetRangeMax())
        return Slice

    def GetHistogram(self, bins=10, norm=False):
        """ Get the histogram of the values

        @param bins: int or sequence of scalars, optional
                If bins is an int, it defines the number of equal-width bins in the given range (10, by default).
                If bins is a sequence, it defines the bin edges, including the rightmost edge,
                allowing for non-uniform bin widths
        """
        hist = Histogram(self.GetName(), self.GetUnit())
        hist.GetHistogram(self, bins, norm=norm)
        return hist

    def PlotMedian(self, out_path=None, box_size=0.5, whisker_ratio=1.5, outlier_symbol='+', bnotched_box=False):
        """ Plot the median of the value vector """
        plotter = ValidationPlot(out_path)
        axes = plotter.GenerateFigure(fig_width=2, fig_height=5, show_grid=False)

        plotter.GetMedianPlot(axes, self.GetValue(), x_axis_name="", y_axis_name=str(self.GetUnit()),
                              title=self.GetName(), xticks_labels=None,
                              y_axis_ext=[self.GetRangeMin(), self.GetRangeMax()], box_width=box_size,
                              whisker_box_ratio=whisker_ratio, notched_box=bnotched_box,
                              outlier_sym=outlier_symbol, vert_orientation=True)

        return plotter.GetDrawingFromBuffer(plotter.GetPlotDataBuffer(), "Median_" + self.GetName().replace(' ', '_'),
                                            width=100, height=300), plotter


class Signal(ValueVector):
    """ Signal class """

    def __init__(self, name, unit, value_vect, ts_vect, range_min, range_max, default_value=None):
        """ Initialize the  Signal

        :param name: name of the vector
        :param unit: BaseUnit class instance or unit name
        :param value_vect: vector of values (list)
        :param ts_vect: timestamp vector (list)
        :param range_min: Minimal Value
        :param range_max: Maximal Value
        """

        if not (isinstance(unit, BaseUnit)):
            unit = BaseUnit(unit)

        if default_value is None:
            self.__default_value = range_min
        else:
            if default_value > range_max:
                self.__default_value = range_max
            elif default_value < range_min:
                self.__default_value = range_min
            else:
                self.__default_value = default_value

        if isinstance(value_vect, (float, int)):
            ValueVector.__init__(self, name, unit, [value_vect] * len(ts_vect), range_min, range_max)
            self.__ts_vect = ts_vect
        elif len(value_vect) == len(ts_vect):
            ValueVector.__init__(self, name, unit, value_vect, range_min, range_max)
            self.__ts_vect = ts_vect
        elif len(value_vect) < len(ts_vect):
            log.logging.warning("Each timestamp shall have a value")
            ValueVector.__init__(self, name, unit, value_vect, range_min, range_max)
            self.__ts_vect = ts_vect[:len(value_vect)]
        elif len(value_vect) > len(ts_vect):
            log.logging.warning("Each value shall have a timestamp")
            ValueVector.__init__(self, name, unit, value_vect[:len(ts_vect)], range_min, range_max)
            self.__ts_vect = ts_vect
        else:
            log.logging.error("Each Value shall have a timestamp")

    def __str__(self):
        """ Print snap shot vector
        """
        return str(zip(self.GetTimestamps(), self.GetValue()))

    def __GetIndexFromTimestamp(self, ts):
        """ Get the array index where the given timestamp exists or can be inserted"""
        return bisect_left(self.__ts_vect, ts)

    def GetSubsetForTimeInterval(self, startts=None, stopts=None):
        """ Returns a Signal for a selected time interval between start and stop time slot
        if startts is larger than largest value of the time slot list, returning None
        if stopts is less than smallest value of the time slot list, returning None
        :param starts: start time slot
        :param stopts: stop time slot
        """

        time_slots = self.__ts_vect
        values = self.GetValue()
        min_idx = 0
        max_idx = len(time_slots) - 1
        returnNone = False

        if (((startts is None) or (startts <= time_slots[min_idx])) and
                ((stopts is None) or (stopts >= time_slots[max_idx]))):
            return self

        if (startts is None):
            new_startts_idx = min_idx
        elif (startts > time_slots[max_idx]):
            log.logging.warning("startts is larger than largest value of the time slot list, returning None")
            returnNone = True
        else:
            new_startts_idx = None
        if (stopts is None):
            new_stopts_idx = max_idx
        elif (stopts < time_slots[min_idx]):
            log.logging.warning("stopts is less than smallest value of the time slot list, returning None")
            returnNone = True
        else:
            new_stopts_idx = None

        if returnNone:
            return None
        else:
            if ((new_startts_idx is not None) or (stopts is not None)):
                for idx, ts in enumerate(time_slots):
                    if (new_startts_idx is None):
                        if (ts >= startts):
                            new_startts_idx = idx
                    if (new_stopts_idx is None):
                        if (ts == stopts):
                            new_stopts_idx = idx
                        elif (ts > stopts):
                            new_stopts_idx = idx - 1
                            break

            retSignal = Signal(self.GetName(), self.GetUnit(), values[new_startts_idx:new_stopts_idx + 1],
                               time_slots[new_startts_idx:new_stopts_idx + 1], self.GetMinValue(), self.GetMaxValue)

            return retSignal

    def AddTimestampAndValue(self, timestamp, value):
        """ Add a new timestamp and the corresponding value to the signal

        @return: True if passed, False on error
        """
        ret = False
        if isinstance(value, (list, tuple)):
            log.logging.error("Each Value shall have a timestamp")
        else:
            timestamp = [timestamp]
            value = [value]

        for id_ in range(len(value)):
            idx = self.__GetIndexFromTimestamp(timestamp[id_])
            if  idx < len(self):
                if  float(self.__ts_vect[idx]) != float(timestamp[id_]):
                    if self.InsertValue(value[id_], idx):
                        self.__ts_vect.insert(idx, timestamp[id_])
                        ret = True
                    else:
                        log.logging.warning("Value exceeds limits.")
                else:
                    log.logging.warning("Timestamp already exist")
            else:
                if self.AppendValue(value[id_]):
                    self.__ts_vect.append(timestamp[id_])
                    ret = True
                else:
                    log.logging.warning("Value exceeds limits.")
        return ret

    def SetValueAtTimestamp(self, ts, val):
        """ Set the Value at the given timestamp """
        idx = self.__GetIndexFromTimestamp(ts)
        if idx < len(self):
            self[idx] = val
        else:
            self.AddTimestampAndValue(ts, val)
        return True

    def GetValueAtTimestamp(self, ts):
        """ Return the value at the given timestamp """
        if ts in self.GetTimestamps():
            idx = self.__GetIndexFromTimestamp(ts)
            if idx < len(self):
                val = self[idx]
            else:
                val = None
        else:
            val = None
        return val

    def GetTimestamps(self):
        """ Get the Timestamp range of the signal """
        return self.__ts_vect

    def GetStartTimestamp(self):
        """ Get the Start Timestamp """
        if(len(self.__ts_vect) > 0):
            ts = np.min(self.__ts_vect)
        else:
            ts = 0
        return ts

    def GetEndTimestamp(self):
        """ Get the end TimeStamp """
        if(len(self.__ts_vect) > 0):
            ts = np.max(self.__ts_vect)
        else:
            ts = 0
        return ts

    def GetDefaultValue(self):
        """ Get Default Value"""
        return self.__default_value

    def __lt__(self, other):
        """ Override the Less Than '<' operator """
        if(isinstance(other, Signal)):
            SigOut = BinarySignal(self.GetName() + "_lower_than_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    if (Val1 < Val2):
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, BaseValue)):
            SigOut = BinarySignal(self.GetName() + "_lower_than_" + other.GetName(), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) < other.GetValue()):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, (int, float))):
            SigOut = BinarySignal(self.GetName() + "_lower_than_" + str(other), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) < other):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        else:
            log.logging.error("Comparison are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __le__(self, other):
        """ Override the Less or Equal '<=' operator """
        if(isinstance(other, Signal)):
            SigOut = BinarySignal(self.GetName() + "_lower_equal_to_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    if (Val1 <= Val2):
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, BaseValue)):
            SigOut = BinarySignal(self.GetName() + "_lower_equal_to_" + other.GetName(), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) <= other.GetValue()):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, (int, float))):
            SigOut = BinarySignal(self.GetName() + "_lower_equal_to_" + str(other), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) <= other):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        else:
            log.logging.error("Comparison are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def _GetCombinedTimestamps(self, other):
        """ Create a combine timestamp vector of the two signals"""
        ts = list(self.GetTimestamps())
        ts.extend(other.GetTimestamps())
        return sorted(set(ts))

    def __cmp__(self, other):
        log.logging.error("__cmp__ is deprecated it should not be used")

    def __eq__(self, other):
        """ Override the Equal '==' operator """
        if(isinstance(other, Signal)):
            SigOut = BinarySignal(self.GetName() + "_equal_to_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    if (Val1 == Val2):
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, BaseValue)):
            SigOut = BinarySignal(self.GetName() + "_equal_to_" + other.GetName(), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) == other.GetValue()):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, (int, float))):
            SigOut = BinarySignal(self.GetName() + "_equal_to_" + str(other), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) == other):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        else:
            log.logging.error("Comparison are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __ne__(self, other):
        """ Override the not Equal '!=' operator """
        if(isinstance(other, Signal)):
            SigOut = BinarySignal(self.GetName() + "_not_equal_to_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    if (Val1 != Val2):
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, BaseValue)):
            SigOut = BinarySignal(self.GetName() + "_not_equal_to_" + other.GetName(), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) != other.GetValue()):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, (int, float))):
            SigOut = BinarySignal(self.GetName() + "_not_equal_to_" + str(other), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) != other):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        else:
            log.logging.error("Comparison are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __ge__(self, other):
        """ Override the Greater or Equal '>=' operator """
        if(isinstance(other, Signal)):
            SigOut = BinarySignal(self.GetName() + "_greater_equal_to_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)

            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    if (Val1 >= Val2):
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, BaseValue)):
            SigOut = BinarySignal(self.GetName() + "_greater_equal_to_" + other.GetName(), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) >= other.GetValue()):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, (int, float))):
            SigOut = BinarySignal(self.GetName() + "_greater_equal_to_" + str(other), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) >= other):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        else:
            log.logging.error("Comparison are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __gt__(self, other):
        """ Override the Greater Than '>' operator """
        if(isinstance(other, Signal)):
            SigOut = BinarySignal(self.GetName() + "_greater_than_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    if (Val1 > Val2):
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, BaseValue)):
            SigOut = BinarySignal(self.GetName() + "_greater_than_" + other.GetName(), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) > other.GetValue()):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        elif(isinstance(other, (int, float))):
            SigOut = BinarySignal(self.GetName() + "_greater_than_" + str(other), [], [])
            for time in self.GetTimestamps():
                if(self.GetValueAtTimestamp(time) > other):
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        else:
            log.logging.error("Comparison are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __add__(self, other):
        """ Override the Add '+' operator """
        if(isinstance(other, Signal)):
            if(str(self.GetUnit()) != str(other.GetUnit())):
                log.logging.warning("The Signals have different units and should not be added")
            SigOut = Signal(self.GetName() + "_plus_" + other.GetName(), self.GetUnit(), [], [],
                            self.GetRangeMin() + other.GetRangeMin(), self.GetRangeMax() + other.GetRangeMax())
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    SigOut.AddTimestampAndValue(time, Val1 + Val2)

        elif(isinstance(other, BaseValue)):
            if(str(self.GetUnit()) != str(other.GetUnit())):
                log.logging.warning("The Signal and the value have different units and should not be added")
            SigOut = Signal(str(other.GetValue()) + "_plus_" + self.GetName(), self.GetUnit(), [], [],
                            self.GetRangeMin() + other.GetValue(), self.GetRangeMax() + other.GetValue())
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) + other.GetValue())

        elif(isinstance(other, (int, float))):
            SigOut = Signal(str(other) + "_plus_" + self.GetName(), self.GetUnit(), [], [],
                            self.GetRangeMin() + other, self.GetRangeMax() + other)
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) + other)
        else:
            log.logging.error("Addition are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __sub__(self, other):
        """ Override the Sub '-' operator """
        return self +(-other)

    def __mul__(self, other):
        """ Override the Mul '*' operator """
        if(isinstance(other, Signal)):
            if (self.GetRangeMax() <= 0) and (other.GetRangeMax() <= 0):
                newMax = self.GetRangeMin() * other.GetRangeMin()
                newMin = self.GetRangeMax() * other.GetRangeMax()
            elif (self.GetRangeMin() >= 0) and (other.GetRangeMin() >= 0):
                newMax = self.GetRangeMax() * other.GetRangeMax()
                newMin = self.GetRangeMin() * other.GetRangeMin()
            else:
                limits = [self.GetRangeMax() * other.GetRangeMax(), self.GetRangeMin() * other.GetRangeMax(),
                          self.GetRangeMax() * other.GetRangeMin(), self.GetRangeMin() * other.GetRangeMin()]
                newMax = np.max(limits)
                newMin = np.min(limits)

            SigOut = Signal(self.GetName() + "_x_" + other.GetName(), self.GetUnit() * other.GetUnit(), [], [],
                            newMin, newMax)
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if Val1 is not None and Val2 is not None:
                    SigOut.AddTimestampAndValue(time, Val1 * Val2)

        elif(isinstance(other, BaseValue)):
            if(other.GetValue() >= 0):
                SigOut = Signal(str(other.GetValue()) + "x" + self.GetName(), self.GetUnit() * other.GetUnit(), [], [],
                                self.GetRangeMin() * other.GetValue(), self.GetRangeMax() * other.GetValue())
            else:
                SigOut = Signal(str(other.GetValue()) + "x" + self.GetName(), self.GetUnit() * other.GetUnit(), [], [],
                                self.GetRangeMax() * other.GetValue(), self.GetRangeMin() * other.GetValue())
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) * other.GetValue())

        elif(isinstance(other, (int, float))):
            if(other >= 0):
                SigOut = Signal(str(other) + "x" + self.GetName(), self.GetUnit(), [], [],
                                self.GetRangeMin() * other, self.GetRangeMax() * other)
            else:
                SigOut = Signal(str(other) + "x" + self.GetName(), self.GetUnit(), [], [],
                                self.GetRangeMax() * other, self.GetRangeMin() * other)
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) * other)
        else:
            log.logging.error("Multiplication are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __div__(self, other):
        """ Override the Div '/' operator """
        return self.__truediv__(other)

    def __truediv__(self, other):
        """ Override the Div '/' operator """
        if(isinstance(other, Signal)):
            # recalculate the limits
            limits = []
            if (other.GetRangeMin() < 0) and (other.GetRangeMax() > 0):
                other_abs = Signal.Abs(other)
                min_div = other_abs.When(other_abs > 0).GetMinValue()
                limits.extend([self.GetRangeMax() / other.GetRangeMax(), self.GetRangeMin() / other.GetRangeMax()])
                limits.extend([self.GetRangeMax() / other.GetRangeMin(), self.GetRangeMin() / other.GetRangeMin()])
                limits.extend([self.GetRangeMax() / min_div, self.GetRangeMin() / min_div])
            elif (other.GetRangeMin() > 0) or (other.GetRangeMax() < 0):
                limits.extend([self.GetRangeMax() / other.GetRangeMax(), self.GetRangeMin() / other.GetRangeMax()])
                limits.extend([self.GetRangeMax() / other.GetRangeMin(), self.GetRangeMin() / other.GetRangeMin()])
            else:
                limits.extend([sys.float_info.max, sys.float_info.min])
                # log.logging.error("Division per 0 are not defined")

            newMax = np.max(limits)
            newMin = np.min(limits)

            SigOut = Signal("(" + self.GetName() + "_/_" + other.GetName() + ")", self.GetUnit() / other.GetUnit(),
                            [], [], newMin, newMax)
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None) and (np.abs(Val2) > 0)):
                    SigOut.AddTimestampAndValue(time, Val1 / Val2)
        elif(isinstance(other, BaseValue)):
            if (other.GetValue() > 0):
                SigOut = Signal("(" + self.GetName() + "_/_" + str(other.GetValue()) + ")",
                                self.GetUnit() / other.GetUnit(),
                                [], [], self.GetRangeMin() / other.GetValue(), self.GetRangeMax() / other.GetValue())
                for time in self.GetTimestamps():
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) / other.GetValue())
            elif (other.GetValue() < 0):
                SigOut = Signal("(" + self.GetName() + "_/_" + str(other.GetValue()) + ")",
                                self.GetUnit() / other.GetUnit(),
                                [], [], self.GetRangeMax() / other.GetValue(), self.GetRangeMin() / other.GetValue())
                for time in self.GetTimestamps():
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) / other.GetValue())
            else:
                SigOut = None
                log.logging.error("Division per 0 are not defined")
        elif(isinstance(other, (int, float))):
            if (other > 0):
                SigOut = Signal("(" + self.GetName() + "_/_" + str(other) + ")", self.GetUnit(), [], [],
                                self.GetRangeMin() / other, self.GetRangeMax() / other)
                for time in self.GetTimestamps():
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) / other)
            elif (other < 0):
                SigOut = Signal("(" + self.GetName() + "_/_" + str(other) + ")", self.GetUnit(), [], [],
                                self.GetRangeMax() / other, self.GetRangeMin() / other)
                for time in self.GetTimestamps():
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) / other)
            else:
                SigOut = None
                log.logging.error("Division per 0 are not defined")
        else:
            log.logging.error("Division are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __floordiv__(self, other):
        """ Override the integer Div '//' operator """
        if(isinstance(other, Signal)):
            # recalculate the limits
            limits = []
            if (other.GetRangeMin() < 0) and (other.GetRangeMax() > 0):
                other_abs = Signal.Abs(other)
                min_div = other_abs.When(other_abs > 0).GetMinValue()
                limits.extend([self.GetRangeMax() // other.GetRangeMax(), self.GetRangeMin() // other.GetRangeMax()])
                limits.extend([self.GetRangeMax() // other.GetRangeMin(), self.GetRangeMin() // other.GetRangeMin()])
                limits.extend([self.GetRangeMax() // min_div, self.GetRangeMin() // min_div])
            elif (other.GetRangeMin() > 0) or (other.GetRangeMax() < 0):
                limits.extend([self.GetRangeMax() // other.GetRangeMax(), self.GetRangeMin() // other.GetRangeMax()])
                limits.extend([self.GetRangeMax() // other.GetRangeMin(), self.GetRangeMin() // other.GetRangeMin()])
            else:
                limits.extend([sys.float_info.max, sys.float_info.min])
                log.logging.error("Division per 0 are not defined")

            newMax = np.max(limits)
            newMin = np.min(limits)

            SigOut = Signal("(" + self.GetName() + "_//_" + other.GetName() + ")",
                            self.GetUnit() // other.GetUnit(), [], [], newMin, newMax)
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None) and (np.abs(Val2) > 0)):
                    SigOut.AddTimestampAndValue(time, Val1 // Val2)
        elif(isinstance(other, BaseValue)):
            if (other.GetValue() > 0):
                SigOut = Signal("(" + self.GetName() + "_//_" + str(other.GetValue()) + ")",
                                self.GetUnit() // other.GetUnit(),
                                [], [], self.GetRangeMin() // other.GetValue(), self.GetRangeMax() // other.GetValue())
                for time in self.GetTimestamps():
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) // other.GetValue())
            elif (other.GetValue() < 0):
                SigOut = Signal("(" + self.GetName() + "_//_" + str(other.GetValue()) + ")",
                                self.GetUnit() // other.GetUnit(),
                                [], [], self.GetRangeMax() // other.GetValue(), self.GetRangeMin() // other.GetValue())
                for time in self.GetTimestamps():
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) // other.GetValue())
            else:
                SigOut = None
                log.logging.error("Division per 0 are not defined")
        elif(isinstance(other, (int, float))):
            if (other > 0):
                SigOut = Signal("(" + self.GetName() + "_//_" + str(other) + ")", self.GetUnit(), [], [],
                                self.GetRangeMin() // other, self.GetRangeMax() // other)
                for time in self.GetTimestamps():
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) // other)
            elif (other < 0):
                SigOut = Signal("(" + self.GetName() + "_//_" + str(other) + ")", self.GetUnit(), [], [],
                                self.GetRangeMax() // other, self.GetRangeMin() // other)
                for time in self.GetTimestamps():
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) // other)
            else:
                SigOut = None
                log.logging.error("Division per 0 are not defined")
        else:
            log.logging.error("Integer Division are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def __pow__(self, other):
        """ Override the Pow '**' operator """
        if(isinstance(other, Signal)):
            log.logging.error("Power/Exponent is not possible with type Signal")
            SigOut = None
        elif(isinstance(other, BaseValue)):
            min = self.GetRangeMin() ** other.GetValue()
            max = self.GetRangeMax() ** other.GetValue()
            newMax = np.max([0, min, max])
            newMin = np.min([0, min, max])

            SigOut = Signal("(" + self.GetName() + "_**_" + str(other.GetValue()) + ")",
                            self.GetUnit(), [], [], newMin, newMax)
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) ** other.GetValue())

        elif(isinstance(other, (int, float))):
            min = self.GetRangeMin() ** other
            max = self.GetRangeMax() ** other
            newMax = np.max([0, min, max])
            newMin = np.min([0, min, max])

            SigOut = Signal("(" + self.GetName() + "_**_" + str(other) + ")", self.GetUnit(), [], [], newMin, newMax)
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time) ** other)
        else:
            log.logging.error("Power/Exponent is only possible with type BaseValue, Int or float")
            SigOut = None
        return SigOut

    def __neg__(self):
        """ Override the negation '-' operator """
        SigOut = self * (-1)
        SigOut.SetName("-" + self.GetName())
        return SigOut

    def __pos__(self):
        """ Override the positive '+' operator """
        SigOut = Signal(self.getName(), self.GetUnit(), self.GetValue(), self.GetTimestamps(),
                        self.GetRangeMin(), self.GetRangeMax())
        return SigOut

    def When(self, BinSignal):
        """ Generates When condition """
        if not(isinstance(BinSignal, BinarySignal)):
            log.logging.error("Condition vector should be from type BinarySignal")
            SigOut = None
        else:
            if(isinstance(self, BinarySignal)):
                SigOut = BinarySignal(self.GetName() + "_when_" + BinSignal.GetName(), [], [])
            else:
                SigOut = Signal(self.GetName() + "_when_" + BinSignal.GetName(), self.GetUnit(), [], [],
                                self.GetRangeMin(), self.GetRangeMax(), self.GetDefaultValue())
            for time in self.GetTimestamps():
                if(BinSignal.GetValueAtTimestamp(time) == BinarySignal.SIG_TRUE):
                    SigOut.AddTimestampAndValue(time, self.GetValueAtTimestamp(time))
        return SigOut

    def SplitSliceOverThres(self, signal_threshold=None, bridgeable_gap=0):
        SignalSliceList = []
        SigOutTemp = None

        if signal_threshold is None:
            signal_threshold = self.GetRangeMin()

        for time in self.GetTimestamps():
            Val = self.GetValueAtTimestamp(time)
            if (Val > signal_threshold):
                if SigOutTemp is None:
                    if(isinstance(self, BinarySignal)):
                        SigOutTemp = BinarySignal(self.GetName(), [Val], [time])
                    else:
                        SigOutTemp = Signal(self.GetName(), self.GetUnit(), [Val], [time], self.GetRangeMin(),
                                            self.GetRangeMax(), self.GetDefaultValue())
                else:
                    SigOutTemp.AddTimestampAndValue(time, self.GetValueAtTimestamp(time))
            else:
                if SigOutTemp is not None:
                    SignalSliceList.append(SigOutTemp)
                    SigOutTemp = None
        else:
            if SigOutTemp is not None:
                    SignalSliceList.append(SigOutTemp)

        return SignalSliceList

    def Max(self, other):
        """ Get the max value of the signals for each timestamp """
        if(isinstance(other, Signal)):
            SigOut = Signal("Max_from_" + self.GetName() + "_and_" + other.GetName(), self.GetUnit(), [], [],
                            np.max([self.GetRangeMin(), other.GetRangeMin()]),
                            np.max([self.GetRangeMax(), other.GetRangeMax()]))
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    SigOut.AddTimestampAndValue(time, np.max([Val1, Val2]))
                elif(Val1 is not None):
                    SigOut.AddTimestampAndValue(time, Val1)
                elif(Val2 is not None):
                    SigOut.AddTimestampAndValue(time, Val2)
                else:
                    log.logging.warning("a timestamp does not match any signal value")
        elif(isinstance(other, BaseValue)):
            SigOut = Signal("Max_from_" + self.GetName() + "_and_" + other.GetName(), self.GetUnit(), [], [],
                            self.GetRangeMin(),
                            np.max([self.GetRangeMax(), other.GetValue()]))
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, np.max([self.GetValueAtTimestamp(time), other.GetValue()]))
        elif(isinstance(other, (int, float))):
            SigOut = Signal("Max_from_" + self.GetName() + "_and_" + str(other), self.GetUnit(), [], [],
                            self.GetRangeMin(), np.max([self.GetRangeMax(), other]))
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, np.max([self.GetValueAtTimestamp(time), other]))
        else:
            log.logging.error("Comparison are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def Min(self, other):
        """ Get the min value of the signals for each timestamp """
        if(isinstance(other, Signal)):
            SigOut = Signal("Min_from_" + self.GetName() + "_and_" + other.GetName(), self.GetUnit(), [], [],
                            np.min([self.GetRangeMin(), other.GetRangeMin()]),
                            np.min([self.GetRangeMax(), other.GetRangeMax()]))
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if ((Val1 is not None) and (Val2 is not None)):
                    SigOut.AddTimestampAndValue(time, np.min([Val1, Val2]))
                elif(Val1 is not None):
                    SigOut.AddTimestampAndValue(time, Val1)
                elif(Val2 is not None):
                    SigOut.AddTimestampAndValue(time, Val2)
                else:
                    log.logging.warning("a timestamp does not match any signal value")
        elif(isinstance(other, BaseValue)):
            SigOut = Signal("Min_from_" + self.GetName() + "_and_" + other.GetName(), self.GetUnit(), [], [],
                            np.min([self.GetRangeMin(), other.GetValue()]), self.GetRangeMax())
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, np.min([self.GetValueAtTimestamp(time), other.GetValue()]))
        elif(isinstance(other, (int, float))):
            SigOut = Signal("Min_from_" + self.GetName() + "_and_" + str(other), self.GetUnit(), [], [],
                            np.min([self.GetRangeMin(), other]), self.GetRangeMax())
            for time in self.GetTimestamps():
                SigOut.AddTimestampAndValue(time, np.min([self.GetValueAtTimestamp(time), other]))
        else:
            log.logging.error("Comparison are only possible with type BaseValue, Signal, Int or float")
            SigOut = None
        return SigOut

    def Abs(self):
        """ Get the absolute value of the signals for each timestamp """
        return Signal.Max(self.When(self >= 0), -self.When(self < 0))

    def Interpolate(self, int_timestamps):
        """ Interpolate the signal """
        log.logging.error("Method not implemented")
        return []

    def ChangeTimeRange(self, timestamps):
        """ Change the time range on which the signal is defined.
            Set the default value where the signal is not defined
        """
        tmp_u = BaseUnit(GblUnits.UNIT_L_US, "")
        tmp_ts = ValueVector("", tmp_u, timestamps, 0.0, 0.0)
        if timestamps is None:
            SigOut = None
        elif tmp_ts == ValueVector("", tmp_u, self.GetTimestamps(), 0.0, 0.0):
            SigOut = self
        else:
            if(isinstance(self, BinarySignal)):
                SigOut = BinarySignal(self.GetName(), [self.__default_value] * len(timestamps), timestamps)
            else:
                SigOut = Signal(self.GetName(), self.GetUnit(), [self.__default_value] * len(timestamps),
                                timestamps, self.GetRangeMin(), self.GetRangeMax())
            for timestamp in timestamps:
                Val = self.GetValueAtTimestamp(timestamp)
                if (Val is not None):
                    SigOut.SetValueAtTimestamp(timestamp, Val)

            SigOut.SetName(self.GetName())

        return SigOut

    def Plot(self, signal_list=None, timestamps=None, out_path=None, bline=True, marker_list=None,
             color_list=None, linesytle_list=None):
        """ Plot the signal vector as master and as other vectors if they are compatible """
        plotter = ValidationPlot(out_path)

        # Compute the master signal to be plotted
        if timestamps is None:
            MasterSig = self
        else:
            MasterSig = self.ChangeTimeRange(timestamps)

        if len(MasterSig.GetTimestamps()) > 0:
            data = [zip(MasterSig.GetTimestamps(), MasterSig.GetValue())]

            if signal_list is not None:
                title = None
                display_legend = True
                legend = [MasterSig.GetName()]
                max_range = MasterSig.GetRangeMax()
                min_range = MasterSig.GetRangeMin()

                if timestamps is None:
                    timebase = MasterSig.GetTimestamps()
                else:
                    timebase = timestamps

                for more_signal in signal_list:
                    if (str(more_signal.GetUnit()) == str(MasterSig.GetUnit())):
                        PlotSig = more_signal.ChangeTimeRange(timebase)
                        data.append(zip(PlotSig.GetTimestamps(), PlotSig.GetValue()))
                        legend.append(PlotSig.GetName())
                        max_range = np.max([max_range, PlotSig.GetRangeMax()])
                        min_range = np.min([min_range, PlotSig.GetRangeMin()])
                    else:
                        log.logging.warning('The Signal ' + more_signal.GetName() +
                                            ' has a different unit than the master Signal' +
                                            ' and will not be added to the plot')
            else:
                title = MasterSig.GetName()
                legend = [title]
                display_legend = False
                max_range = MasterSig.GetRangeMax()
                min_range = MasterSig.GetRangeMin()

            # Set global Graph property
            x_ext = [MasterSig.GetStartTimestamp(), MasterSig.GetEndTimestamp()]
            if display_legend:
                y_ext = [min_range - 0.05 * (max_range - min_range), max_range + 0.15 * (max_range - min_range)]
            else:
                y_ext = [min_range - 0.05 * (max_range - min_range), max_range + 0.05 * (max_range - min_range)]

            # Generate the Graph
            plotter.GeneratePlot(data, legend, "time [s]", str(MasterSig.GetUnit()), bline, display_legend,
                                 title=title, x_axis_ext=x_ext, y_axis_ext=y_ext,
                                 line_styles=linesytle_list, line_colors=color_list, line_markers=marker_list)
            # Plot the Graph into a picture and return it as a binary buffer
            return plotter.GetDrawingFromBuffer(plotter.GetPlotDataBuffer(),
                                                ("Signal_" + ('_').join(legend)).replace(' ', '_')), plotter
        else:
            return None, None

    def PlotXy(self, signal_list, out_path=None, bline=True, marker_list=None, color_list=None, linesytle_list=None):
        """ Plot the signal on x-axis and the signal list on the y-axis.

            Match signals using the timestamps.
        """
        data = []
        legend = []
        markers = []
        colors = []
        linestyles = []
        plotter = ValidationPlot(out_path)
        master_timestamps = set(self.GetTimestamps())
        common_unit_name = str(signal_list[0].GetUnit()).lower()
        min_range = []
        max_range = []
        for signal_order, plot_signal in enumerate(signal_list):
            if(str(plot_signal.GetUnit()).lower() == common_unit_name):
                plot_signal_timestamps = set(plot_signal.GetTimestamps())
                common_timestamps = sorted(list(set(plot_signal_timestamps & master_timestamps)))
                if len(common_timestamps) > 0:
                    x_Signal = self.ChangeTimeRange(common_timestamps)
                    y_Signal = plot_signal.ChangeTimeRange(common_timestamps)
                    min_range.append(y_Signal.GetRangeMin())
                    max_range.append(y_Signal.GetRangeMax())
                    data.append(zip(x_Signal.GetValue(), y_Signal.GetValue()))
                    legend.append(y_Signal.GetName())
                    if(marker_list is not None):
                        markers.append(marker_list[signal_order])
                    if(color_list is not None):
                        colors.append(color_list[signal_order])
                    if(linesytle_list is not None):
                        linestyles.append(linesytle_list[signal_order])
            else:
                log.logging.warning('All signal on the y-axis shall have the same unit')

        if len(data) > 0:
            min_range = min(min_range)
            max_range = min(max_range)

            # Set global Graph property
            x_ext = [self.GetMinValue(), self.GetMaxValue()]
            y_ext = [min_range - 0.05 * (max_range - min_range), max_range + 0.15 * (max_range - min_range)]

            # Generate the Graph
            plotter.GeneratePlot(data, legend, self.GetName() + ' ' + str(self.GetUnit()),
                                 common_unit_name, bline, True,
                                 x_axis_ext=x_ext, y_axis_ext=y_ext,
                                 line_styles=linestyles, line_colors=colors, line_markers=markers)

            # Plot the Graph into a picture and return it as a binary buffer
            return plotter.GetDrawingFromBuffer(plotter.GetPlotDataBuffer(),
                                                ("Signal_" + ('_').join(legend)).replace(' ', '_')), plotter
        else:
            log.logging.error("The provided signals do not have a common timestamp basis")
            return None, None


class BinarySignal(Signal):
    """ Value Vector taking binary values (0 or 1)

    """
    SIG_TRUE = 1
    SIG_FALSE = 0

    def __init__(self, name, value_vect, ts_vect, dbi_gbl=None):
        """ Initialize the binary value vector

        :param name: name of the vector
        :param unit: BaseUnit class instance or unit Name
        :param value_vect: vector of values (list)
        :param ts_vect: Timestamp vector
        :param dbi_gbl: Database interface to GBL Subscheme (optional)
        """
        unit = BaseUnit(GblUnits.UNIT_L_BINARY, dbi_gbl=dbi_gbl)
        Signal.__init__(self, name, unit, value_vect, ts_vect, self.SIG_FALSE, self.SIG_TRUE)

    def __and__(self, other):
        if not isinstance(other, BinarySignal):
            log.logging.error("Both signals must be from type BinarySignal")
            SigOut = None
        elif self is None or other is None:
            log.logging.warning("One of both signal is None")
            SigOut = None
        else:
            SigOut = BinarySignal(self.GetName() + "_and_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if Val1 is not None and Val2 is not None:
                    if (Val1 == BinarySignal.SIG_TRUE) & (Val2 == BinarySignal.SIG_TRUE):
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        return SigOut

    def __or__(self, other):
        if not isinstance(other, BinarySignal):
            log.logging.error("Both signals must be from type BinarySignal")
            SigOut = None
        elif self is None or other is None:
            log.logging.warning("One of both signal is None")
            SigOut = None
        else:
            SigOut = BinarySignal(self.GetName() + "_or_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if Val1 is not None or Val2 is not None:
                    if Val1 == BinarySignal.SIG_TRUE or Val2 == BinarySignal.SIG_TRUE:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        return SigOut

    def __xor__(self, other):
        """ Override the Exclusive Or  '^' operator """
        if not isinstance(other, BinarySignal):
            log.logging.error("Both signals must be from type BinarySignal")
            SigOut = None
        elif self is None or other is None:
            log.logging.warning("One of both signal is None")
            SigOut = None
        else:
            SigOut = BinarySignal(self.GetName() + "_xor_" + other.GetName(), [], [])
            TimestampsOut = self._GetCombinedTimestamps(other)
            for time in TimestampsOut:
                Val1 = self.GetValueAtTimestamp(time)
                Val2 = other.GetValueAtTimestamp(time)
                if Val1 is not None or Val2 is not None:
                    if Val1 == BinarySignal.SIG_TRUE and Val2 == BinarySignal.SIG_TRUE:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
                    elif Val1 == BinarySignal.SIG_TRUE or Val2 == BinarySignal.SIG_TRUE:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_TRUE)
                    else:
                        SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
                else:
                    SigOut.AddTimestampAndValue(time, BinarySignal.SIG_FALSE)
        return SigOut

    def __invert__(self):
        """ Override the inversion  '~' operator """
        ValVect = []
        for Val in self.GetValue():
            if Val == self.SIG_TRUE:
                ValVect.append(self.SIG_FALSE)
            else:
                ValVect.append(self.SIG_TRUE)
        SigOut = BinarySignal("not_" + self.GetName(), ValVect, self.GetTimestamps())
        return SigOut

    def __lt__(self, other):
        """ Override the Less Than '<' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __le__(self, other):
        """ Override the Less or Equal '<=' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __eq__(self, other):
        """ Override the Equal '==' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __ne__(self, other):
        log.logging.error("Operation is not possible for BinarySignals")

    def __ge__(self, other):
        """ Override the Greater or Equal '>=' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __gt__(self, other):
        """ Override the Greater Than '>' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __add__(self, other):
        """ Override the Add '+' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __sub__(self, other):
        """ Override the Sub '-' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __mul__(self, other):
        """ Override the Mul '*' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __div__(self, other):
        """ Override the Div '/' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __truediv__(self, other):
        """ Override the Div '/' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __floordiv__(self, other):
        """ Override the integer Div '//' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __pow__(self, other):
        """ Override the Pow '^' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __neg__(self):
        """ Override the negation '-' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def __pos__(self):
        """ Override the positive '+' operator """
        log.logging.error("Operation is not possible for BinarySignals")

    def Max(self, other):
        """ Get the max value of the signals for each timestamp """
        log.logging.error("Operation is not possible for BinarySignals")

    def Min(self, other):
        """ Get the min value of the signals for each timestamp """
        log.logging.error("Operation is not possible for BinarySignals")


class PercentageSignal(Signal):
    """ Value Vector taking percentage values in the range 0..100

        Unit instance must be given

        ---> THIS Method is intended to be removed. Please clarify status with Guenther Raedler <----
    """
    def __init__(self, name, value_vect, ts_vect, dbi_gbl=None):
        """ Initialize the percentage value vector
        :param name: name of the vector
        :param unit: BaseUnit class instance
        :param value_vect: vector of values (list)
        :param ts_vect: Timestamp vector
        :param dbi_gbl: Database interface to GBL Subscheme (optional)
        """
        unit = BaseUnit(GblUnits.UNIT_L_BIN, dbi_gbl=dbi_gbl)
        Signal.__init__(self, name, unit, value_vect, ts_vect, 0, 100)

    def __neg__(self):
        """ Override the negation '-' operator """
        log.logging.error("Operation is not possible for PercentageSignals")

    def __pos__(self):
        """ Override the positive '+' operator """
        log.logging.error("Operation is not possible for PercentageSignals")


class Histogram(BaseValue):
    """ Validation Result Histogram class

        The class contains calculated histogram values including the binnings used. The
        original values are not stored within the class
    """
    def __init__(self, name, unit, value_vect=None, bins=10):
        """ Constructor of the histogram class """
        BaseValue.__init__(self, name, unit, 0.0)
        self.__hist_values = []
        self.__max = None
        self.__min = None
        self.__step = None
        self.__hist = None
        self.__pattern = None
        self.__sigma = None
        self.__mean = None
        if value_vect is not None:
            self.GetHistogram(value_vect, bins)

    def __str__(self):
        """Value Vector as sting
        """
        return str(self.GetValue())

    def GetValue(self, index=None):
        """Get the vector of values
        """
        if index is None:
            return self.__hist_values
        else:
            if index < len(self.__hist_values):
                return self.__hist_values[index]
            else:
                return None

    def GetPattern(self, index=None):
        """Get the x-axis value i.e. bins
        """
        if index is None:
            return self.__pattern
        else:
            if index < len(self.__pattern):
                return self.__pattern[index]
            else:
                return None

    def GetHist(self, index=None):
        """Get the y-axis value
        """
        if index is None:
            return self.__hist
        else:
            if index < len(self.__hist):
                return self.__hist[index]
            else:
                return None

    def GetMinValue(self):
        """Get min value of the ValueVector
        """
        return self.__min

    def GetMaxValue(self):
        """Get max value of the ValueVector
        """
        return self.__max

    def GetStandardDeviation(self):
        """Get standard Deviation of the ValueVector
        """
        return self.__sigma

    def GetMeanValue(self):
        """Get mean value of the ValueVector
        """
        return self.__mean

    def SetValue(self, hist_values):
        """ Set the vector of histogram value tuples
            this method is used in load method of ValResult for Histogram
        """
        if hist_values is not None:
            self.__pattern = []
            self.__hist = []
            self.__hist_values = hist_values
            self.__pattern, self.__hist = list(zip(*hist_values[2:])[0]), list(zip(*hist_values[2:-1])[1])
            self.__max = hist_values[0][0]
            self.__min = hist_values[0][1]
            self.__sigma = hist_values[1][0]
            self.__mean = hist_values[1][1]

    def __CalcHistogram(self, values, bins):
        """ Calculate the Histogram values
        """
        try:
            bins = int(bins)
            Step = (max(values) - min(values)) / bins
            pattern = [(min(values) + (x + 1) * Step) for x in range(bins)]
        except:
            pattern = bins

        hist = [0] * (len(pattern) - 1)

        for val in values:
            if val >= pattern[0]:
                for iBin, iBinThres in enumerate(pattern[1:]):
                    if(val < iBinThres):
                        hist[iBin] = hist[iBin] + 1
                        break

        return pattern, hist

    def GetHistogram(self, value_vect, bins, update=True, norm=False):
        """Get the histogram of the values
        :param value_vect: values for histogram calculation with datatype list or ValueVector
        :param bins: list or bin counts used for x-axis
        :param update: flag to update the hist and pattern value
        :param norm: flag to calclulate Normalized value for historgram in Percentage
        """

        pattern, hist = [], []
        if isinstance(value_vect, list):
            value_vect = ValueVector("", "", value_vect, min(value_vect) - 5, max(value_vect) + 5)

        if isinstance(value_vect, ValueVector):
            pattern, hist = self.__CalcHistogram(value_vect.GetValue(), bins)
            total_values = len(value_vect)
        else:
            raise StandardError("Only Value Vector or List data types are allowed")

        if update:
            if norm:
                self.__hist = []
                for hist_entry in hist:
                    self.__hist.append(abs((float(hist_entry) / total_values)) * 100)
                hist = self.__hist
            else:
                self.__hist = hist

            self.__pattern = pattern
            self.__max = value_vect.GetMaxValue()
            self.__min = value_vect.GetMinValue()
            self.__sigma = value_vect.GetStandardDeviation()
            self.__mean = value_vect.GetMeanValue()
            self.__hist_values = [(self.__max, self.__min), (self.__sigma, self.__mean)]
            self.__hist_values += zip(self.__pattern, self.__hist + [0])

        return pattern, hist

    def PlotHistogramBarChart(self, out_path=None, label_list=None, label_rotation=None, label_size=None,
                              relative_bar_size=0.9, bar_orientation='vertical'):
        """Plot the bar chart of the histogram values
        """
        plotter = ValidationPlot(out_path)
        axes = plotter.GenerateFigure(fig_width=5, fig_height=5, show_grid=False)

#        data_vectors = self.__hist_values

        min_tick_width = min([n1 - n for n1, n in zip(self.__pattern[1:], self.__pattern[:-1])])
        bar_middlepos = [n + ((n1 - n) / 2.0) for n1, n in zip(self.__pattern[1:], self.__pattern[:-1])]
        axis_ext = [min(self.__pattern), max(self.__pattern)]

        if bar_orientation == 'vertical':
            plotter.GetBarPlot(axes, self.__hist, bar_middlepos, str(self.GetUnit()), '',
                               title=self.GetName(), xticks=self.__pattern, xticks_labels=label_list,
                               x_axis_ext=axis_ext, yticks=None, yticks_labels=None, y_axis_ext=None,
                               bar_width=relative_bar_size * min_tick_width, bar_orientation=bar_orientation,
                               align='center')
        else:
            plotter.GetBarPlot(axes, self.__hist, bar_middlepos, '', str(self.GetUnit()), title=self.GetName(),
                               xticks=None, xticks_labels=None, x_axis_ext=None, yticks=self.__pattern,
                               yticks_labels=label_list, y_axis_ext=axis_ext,
                               bar_width=relative_bar_size * min_tick_width,
                               bar_orientation=bar_orientation, align='center')
        # Plot the Graph into a picture and return it as a binary buffer
        return plotter.GetDrawingFromBuffer(plotter.GetPlotDataBuffer(), "Hist_" + self.GetName().replace(' ', '_'),
                                            width=300, height=300), plotter

    def PlotHistogramPieChart(self, out_path=None, title=None, label_list=None, legend=None,
                              labels_fontsize=None, legend_fontsize=6, optimised_view=False):
        """Plot the pie chart of the histogram values
        @para title: title of the pie chart
        @param legend:
                if set True: labels are given as a legend
                if list of strings: custom legend
        @para label_list: a list of all the labels for data values... ["sample1", "sample2"....]
        @para labels_fontsize: size for labels
        @para optimised_view: if true will display three largest values on the pie
        chart and rest of the values as others
        @para legend_fontsize: size for legend, by default the value is 6
        """
        plotter = ValidationPlot(out_path)
        pie_axes = plotter.GenerateFigure(fig_width=5, fig_height=5, show_grid=False)
        data_values = self.__hist
        if optimised_view is True:
            zip_values = zip(data_values, label_list)
            tmp = sorted(zip_values)  # Sorts the data values in ascending order
            if len(tmp) > 3:
                # Group lower values together
                lower_vals = 0
                for i in range(0, len(tmp) - 3):
                    lower_vals += tmp[i][0]
                data_values = []
                label_list = []
                for i in range(len(tmp) - 3, len(tmp)):
                    data_values.append(tmp[i][0])
                    label_list.append(tmp[i][1])
                data_values.append(lower_vals)
                label_list.append("Others")

        plotter.GetPieChart(axes=pie_axes, data=data_values, title=title, labels=label_list, legend=legend,
                            labels_fontsize=labels_fontsize, legend_fontsize=legend_fontsize)

        return plotter.GetDrawingFromBuffer(plotter.GetPlotDataBuffer(), "Hist_" + self.GetName().replace(' ', '_'),
                                            width=300, height=300), plotter

    def PlotHistogramDistribution(self, out_path=None, title=None, x_label=None, y_label=None, legend=None,
                                  draw_lines=None, write_text=None):
        """Plot the bar chart of the histogram values
        @param write_text(optional): Writes down the values of sigma and mu.
               Input is the location in the vertical axis, 1 being the top of the axes and 0 the bottom.
        @param draw_lines(optional): Draw lines at mu-sigma, sigma, sigma+mu. Deactivated by default
        """
        plotter = ValidationPlot(out_path)
        axes = plotter.GenerateFigure(fig_width=5, fig_height=5, show_grid=False)

        plotter.GetNormalPdf(axes, self.__pattern, self.__sigma, self.__mean, legend=legend, draw_lines=draw_lines,
                             write_text=write_text, title=title,
                             xlabel=x_label, ylabel=y_label)
        return plotter.GetDrawingFromBuffer(plotter.GetPlotDataBuffer(), "Hist_" + self.GetName().replace(' ', '_'),
                                            width=300, height=300), plotter

"""
CHANGE LOG:
-----------
$Log: result_types.py  $
Revision 1.1 2021/12/13 17:59:45CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/val/project.pj
Revision 1.23 2013/12/03 17:03:55CET uidg3354 
pep8 fixes
- Added comments -  uidg3354 [Dec 3, 2013 5:03:55 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.22 2013/12/03 14:46:12CET Sandor-EXT, Miklos (uidg3354) 
GetSubsetForTimeInterval added
--- Added comments ---  uidg3354 [Dec 3, 2013 2:46:12 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.21 2013/10/30 17:22:49CET Hecker, Robert (heckerr) 
removed try except block.
--- Added comments ---  heckerr [Oct 30, 2013 5:22:50 PM CET]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.20 2013/09/19 13:32:11CEST Ahmed-EXT, Zaheer (uidu7634) 
Added better handling of unxpected datatype  for valuevector in GetHistogram() with raising Exception
--- Added comments ---  uidu7634 [Sep 19, 2013 1:32:11 PM CEST]
Change Package : 196580:1 http://mks-psad:7002/im/viewissue?selection=196580
Revision 1.19 2013/09/13 16:30:45CEST Ahmed-EXT, Zaheer (uidu7634) 
Add Get function for pattern, hist, min, max, StandardDeviation, mean
added mean and sigma storage
improve code reusability GetHistogram() in value_vect
--- Added comments ---  uidu7634 [Sep 13, 2013 4:30:46 PM CEST]
Change Package : 196580:1 http://mks-psad:7002/im/viewissue?selection=196580
Revision 1.18 2013/09/12 17:39:11CEST Verma-EXT, Ajitesh (uidv5394)
added function:
- PlotHistogramPieChart
- PlotHistogramDistribution
--- Added comments ---  uidv5394 [Sep 12, 2013 5:39:11 PM CEST]
Change Package : 196582:1 http://mks-psad:7002/im/viewissue?selection=196582
Revision 1.17 2013/09/10 14:19:30CEST Ahmed-EXT, Zaheer (uidu7634)
Support for normalize historgram
--- Added comments ---  uidu7634 [Sep 10, 2013 2:19:30 PM CEST]
Change Package : 196580:1 http://mks-psad:7002/im/viewissue?selection=196580
Revision 1.16 2013/09/10 10:02:30CEST Ahmed-EXT, Zaheer (uidu7634)
Seperated the hist_Value arrays into pattern and hist
added min and max
Interface change in GetHistogram: returns pattern, hist
--- Added comments ---  uidu7634 [Sep 10, 2013 10:02:31 AM CEST]
Change Package : 196580:1 http://mks-psad:7002/im/viewissue?selection=196580
Revision 1.15 2013/08/09 16:10:07CEST Raedler, Guenther (uidt9430)
- improved bar plot functions (changes by JW)
--- Added comments ---  uidt9430 [Aug 9, 2013 4:10:07 PM CEST]
Change Package : 191955:1 http://mks-psad:7002/im/viewissue?selection=191955
Revision 1.14 2013/08/09 15:32:29CEST Raedler, Guenther (uidt9430)
- fixed errors for pow(signal) when implementing the module test
--- Added comments ---  uidt9430 [Aug 9, 2013 3:32:30 PM CEST]
Change Package : 190322:1 http://mks-psad:7002/im/viewissue?selection=190322
Revision 1.13 2013/08/08 13:35:08CEST Raedler, Guenther (uidt9430)
- fixed errors in module test of baseunit
- removed pep8 warnings
- improved module test coverage
--- Added comments ---  uidt9430 [Aug 8, 2013 1:35:08 PM CEST]
Change Package : 190322:1 http://mks-psad:7002/im/viewissue?selection=190322
Revision 1.12 2013/08/06 16:13:22CEST Raedler, Guenther (uidt9430)
- one more
--- Added comments ---  uidt9430 [Aug 6, 2013 4:13:23 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.11 2013/08/06 16:10:45CEST Raedler, Guenther (uidt9430)
- wrong import
--- Added comments ---  uidt9430 [Aug 6, 2013 4:10:45 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.10 2013/08/06 15:59:34CEST Raedler, Guenther (uidt9430)
- generate warning, if sympy is not installed. if ValBaseUnit is used, sympy is mandatory.
- remove tailing whitespaces
--- Added comments ---  uidt9430 [Aug 6, 2013 3:59:35 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.9 2013/08/06 10:47:04CEST Dintzer, Philippe (dintzerp)
- add not equal operator for Signals
--- Added comments ---  dintzerp [Aug 6, 2013 10:47:04 AM CEST]
Change Package : 175136:3 http://mks-psad:7002/im/viewissue?selection=175136
Revision 1.8 2013/08/02 12:50:48CEST Raedler, Guenther (uidt9430)
- use sympy for units
--- Added comments ---  uidt9430 [Aug 2, 2013 12:50:48 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.7 2013/07/16 07:51:57CEST Raedler, Guenther (uidt9430)
- add GetId into BaseUnit class
--- Added comments ---  uidt9430 [Jul 16, 2013 7:51:57 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.6 2013/07/16 07:28:28CEST Raedler, Guenther (uidt9430)
- fixed error when comparing two timestamp vectors (use ValueVector)
--- Added comments ---  uidt9430 [Jul 16, 2013 7:28:28 AM CEST]
Change Package : 180569:1 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.5 2013/07/11 15:37:46CEST Dintzer, Philippe (dintzerp)
add small bug fixes
add security checks
--- Added comments ---  dintzerp [Jul 11, 2013 3:37:46 PM CEST]
Change Package : 175155:10 http://mks-psad:7002/im/viewissue?selection=175155
Revision 1.4 2013/07/10 09:26:23CEST Raedler, Guenther (uidt9430)
- extensions of math and validation functions for classes Signal(), BaseUnit(), BinarySignal()
- added plot functions for Signal(), ValueVector(), Histogram
Changes implemented by P.Dintzer
--- Added comments ---  uidt9430 [Jul 10, 2013 9:26:23 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.3 2013/06/05 16:26:18CEST Raedler, Guenther (uidt9430)
- added Histogram class
- moved some plot functions from ValueVector into Histogram
- changed return values of plot functions
- changed default values for True and False in BinarySignal class
--- Added comments ---  uidt9430 [Jun 5, 2013 4:26:18 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.2 2013/05/29 10:23:58CEST Raedler, Guenther (uidt9430)
- prepared several override methods to be implemented for signals
- prepared added plot methods for signals and value vectors (histrograms)
- implemented several override methods for binary signals which creates a warning in the log
--- Added comments ---  uidt9430 [May 29, 2013 10:23:59 AM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.1 2013/05/29 08:02:43CEST Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/
04_Engineering/stk/val/project.pj
"""
