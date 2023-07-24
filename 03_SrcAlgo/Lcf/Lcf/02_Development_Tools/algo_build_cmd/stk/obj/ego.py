"""
stk/obj/ego.py
-------------------

Classes for ego motion handling

:org:           Continental AG
:author:        Nassim Ibrouchene

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:34CET $
"""
import math
import numpy as np


# --- Unit conversions ---
MPS2KPH = 3.6
KPH2MPS = 1.0 / 3.6


class EgoMotion():
    """ A class for the ego path """
    DISTANCE_TO_COG = 2.75  # Distance from the sensor to the center of gravity.
    DEFAULT_SPEED_BINS = [0.0, 30.0, 60.0, 80.0, 100.0, 140.0, 180.0, 250.0]
    EGO_DISP_OLD = False

    def __init__(self, veh_speed, veh_accel, veh_yaw, time_stamps):
        """ Constructor.
        :param veh_speed: the vehicle's speed.
        :param veh_accel: the vehicle's acceleration.
        :param veh_yaw: the vehicle's yaw rate.
        :param time_stamps: the MTS timestamps.
        """
        self.__cog_curvelength = None
        self.__cog_coordinates = None
        self.__ego_motion = None
        self.__timestamps = time_stamps
        self.__speed = veh_speed
        self.__accel = veh_accel
        self.__yaw = veh_yaw
        # --- Calculates the ego path related ---
        self.__SetEgoPath()
        self.__SetEgoCurveLength()

    def __SetEgoPath(self):
        """ Calculates the ego path.
        """
        # precalculations
        t = np.array(self.GetCycleTime())
        tsqrhalf = t * t * 0.5
        v = np.asarray(self.__speed)
        a = np.asarray(self.__accel)
        psip = np.asarray(self.__yaw)
        psi = psip * t
        cp = np.cos(psi)
        sp = np.sin(psi)
        psisqr = psi * psi
        psicum = np.cumsum(psi)
        slip = 0
        cs = np.cos(slip)
        ss = np.sin(slip)
        dx_taylor_1 = -1.0 / 6.0
        dx_taylor_2 = 1.0 / 120.0
        dx_taylor_3 = -1.0 / 5040.0
        dx_taylor_4 = 1.0 / 362880.0
        dy_taylor_1 = 1.0 / 2.0
        dy_taylor_2 = -1.0 / 24.0
        dy_taylor_3 = 1.0 / 720.0
        dy_taylor_4 = -1.0 / 40320.0
        cs_cp = cs * cp
        ss_sp = ss * sp
        ss_cp = ss * cp
        cs_sp = cs * sp
        # dx = s * sin(psi)/psi
        # dy = s * (1-cos(psi)/psi)
        ds = a * tsqrhalf + v * t
        dx = ds * (1 + (dx_taylor_1 + (dx_taylor_2 + (dx_taylor_3 + dx_taylor_4 * psisqr) * psisqr) * psisqr) * psisqr)
        dy = ds * ((dy_taylor_1 + (dy_taylor_2 + (dy_taylor_3 + dy_taylor_4 * psisqr) * psisqr) * psisqr) * psi)
        dx_abs = self.DISTANCE_TO_COG * (cp - 1.0) - dx * (cs_cp + ss_sp) + dy * (ss_cp - cs_sp)
        dy_abs = -self.DISTANCE_TO_COG * sp + dx * (cs_sp - ss_cp) - dy * (cs_cp + ss_sp)
        # prealocation
        # cumulative orientation angle sin/cos
        abs_dist = np.zeros(len(v))
        abs_angle = np.zeros(len(v))
        abs2rel_cos = np.zeros(len(v))
        abs2rel_sin = np.zeros(len(v))
        # cumaltive (x/y)-translation with VehicleSpeed type
        abs2rel_dx = np.zeros(len(v))
        abs2rel_dy = np.zeros(len(v))
        # cumulative driven distance
        cums = np.cumsum(ds)
        # set first elements
        abs_dist[0] = 0.0
        abs_angle[0] = 0.0
        abs2rel_cos[0] = 1.0
        abs2rel_sin[0] = 0.0
        # for cycle_idx = 2 : length(VehicleSpeed)  :
        for cycle_idx in xrange(1, len(v)):
            abs_dist[cycle_idx] = cums[cycle_idx - 1]
            abs_angle[cycle_idx] = psicum[cycle_idx - 1]
            abs2rel_cos[cycle_idx] = np.cos(psicum[cycle_idx - 1])
            abs2rel_sin[cycle_idx] = np.sin(psicum[cycle_idx - 1])
            abs2rel_dx[cycle_idx] = (cp[cycle_idx - 1] * abs2rel_dx[cycle_idx - 1] + sp[cycle_idx - 1] *
                                     abs2rel_dy[cycle_idx - 1] + dx_abs[cycle_idx - 1])
            abs2rel_dy[cycle_idx] = (-sp[cycle_idx - 1] * abs2rel_dx[cycle_idx - 1] + cp[cycle_idx - 1] *
                                     abs2rel_dy[cycle_idx - 1] + dy_abs[cycle_idx - 1])
        # inverse cumulative translation
        rel2abs_dx = abs2rel_sin * abs2rel_dy - abs2rel_dx * abs2rel_cos
        rel2abs_dy = -abs2rel_cos * abs2rel_dy - abs2rel_dx * abs2rel_sin
        # --- Set class attribute ---
        self.__cog_coordinates = np.array([list(rel2abs_dx), list(rel2abs_dy)])
        self.__ego_motion = np.array([np.array(list(rel2abs_dx)),
                                      np.array(list(rel2abs_dy)),
                                      np.array(list(abs2rel_dx)),
                                      np.array(list(abs2rel_dy)),
                                      np.array(list(abs_angle)),
                                      np.array(list(abs2rel_sin)),
                                      np.array(list(abs2rel_cos))])

    def __SetEgoCurveLength(self):
        """ Calculates the ego curve length.
        """
        dx = np.power(np.diff(self.__cog_coordinates[0, :]), 2)
        dy = np.power(np.diff(self.__cog_coordinates[1, :]), 2)
        temp = np.sqrt(dx + dy)
        self.__cog_curvelength = np.array([np.concatenate((([0]), np.cumsum(temp)))])

    def GetSpeedInkph(self):
        """ Speed in kilometers per hour.
        :return: The speed in kilometers per hour.
        """
        return [s * MPS2KPH for s in self.__speed]

    def GetEgoDisplacement(self, start=None, end=None):
        """ Calculate the ego displacement.
        :param start: Start index.
        :param end: End index.
        """
        if start is None and end is None:
            start = 0
            end = len(self.__speed)
        elif start is None:
            start = 0
        elif end is None:
            end = len(self.__speed)
        ego_displ = np.zeros((end - start))
        ego_displ[0] = 0.0
        for i in range(start + 1, end):
            dx = self.__cog_coordinates[0, i] - self.__cog_coordinates[0, i - 1]
            dy = self.__cog_coordinates[1, i] - self.__cog_coordinates[1, i - 1]
            ego_displ[i] = np.sqrt(np.power(dx, 2) + np.power(dy, 2))
        return ego_displ
        #================= old implementation =============================
        # ego_displ = [0] * len(self.__speed)
        # cycle_time = self.GetCycleTime()
        # if start is None and end is None:
        #    start = 0
        #    end = len(self.__speed)
        # elif start is None:
        #    start = 0
        # elif end is None:
        #    end = len(self.__speed)
        # for cycleidx in range(start, end):
        #    dt = cycle_time[cycleidx]
        #    ego_displ[cycleidx] = (self.__speed[cycleidx] * dt) + (0.5 * self.__accel[cycleidx] * math.pow(dt, 2))
        # return ego_displ
        #===================================================================

    def GetDrivenDistance(self, start=None, end=None):
        """ Returns the driven distance between the provided indexes.
        :param start: Start index.
        :param end: End index.
        """
        if start is None and end is None:  # return the overall driven distance.
            return self.__cog_curvelength[0, -1]
        elif start is None:  # assume start from the beginning.
            return (self.__cog_curvelength[0, end] - self.__cog_curvelength[0, 0])
        elif end is None:  # assume end at the last index
            return (self.__cog_curvelength[0, -1] - self.__cog_curvelength[0, start])
        else:
            return (self.__cog_curvelength[0, end] - self.__cog_curvelength[0, start])

    def GetCycleTimeStatistic(self):
        """ Returns some statistics for the cycle time.
        :return: The following values: mean, std, min, max, total.
        """
        cycle_time_vec = self.GetCycleTime()
        mean_cycle_time = np.average(cycle_time_vec)
        std_cycle_time = np.std(cycle_time_vec)
        min_cycle_time = np.min(cycle_time_vec)
        max_cycle_time = np.max(cycle_time_vec)
        total_time = np.sum(cycle_time_vec)
        return mean_cycle_time, std_cycle_time, min_cycle_time, max_cycle_time, total_time

    def GetSpeedStatistic(self):
        """ Returns some statistics for the speed.
        :return: The following values: mean, std, min, max.
        """
        mean_speed = np.average(self.__speed)
        std_speed = np.std(self.__speed)
        min_speed = np.min(self.__speed)
        max_speed = np.max(self.__speed)
        return mean_speed, std_speed, min_speed, max_speed

    def GetSpeedHistogram(self, speed, hist_bin=None, **kwargs):
        """ Calculates a histogram for the speed using the specified bins.
        :param hist_bin: The binning for the histogram. If not uses a default value defined in the class header.
        :param kwargs: Keyword arguments for the numpy histogram function.
        :return: a histogram array.
        """
        if hist_bin is None:
            hist_bin = self.DEFAULT_SPEED_BINS
        return np.histogram(speed, hist_bin, **kwargs)[0]

    def GetCycleTime(self):
        """ Creates a cycle time vector using the MTS timestamps.
        :note: The first cycle is the same as the second one.
        """
        length = len(self.__timestamps)
        cycle_time = [0] * length
        cycle_time[0] = float((self.__timestamps[1] - self.__timestamps[0])) / 1000000.0
        for i in xrange(1, length):
            cycle_time[i] = float((self.__timestamps[i] - self.__timestamps[i - 1])) / 1000000.0
        return cycle_time

    def GetEgoArcLength(self):
        """ Returns the arc length vector """
        return self.__cog_curvelength

    def GetEgoMotionArray(self):
        """ Return the ego motion array """
        return self.__ego_motion

    def GetEgoCoordinates(self):
        """ Returns the ego coordinates array """
        return self.__cog_coordinates
"""
$Log: ego.py  $
Revision 1.1 2021/12/13 17:58:34CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/project.pj
Revision 1.1 2013/05/14 10:29:07CEST Ibrouchene, Nassim (uidt5589) (uidt5589) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/obj/project.pj
"""
