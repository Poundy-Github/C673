"""
stk/obj/clothoid/clothoid.py
-------------------

Classes for Clothoid Object Handling

:org:           Continental AG
:author:        Nassim Ibrouchene

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:47CET $
"""
# --- Import Python Modules -------------------------------------------------------------------------------------------
import numpy as np
import threading
from matplotlib.lines import Line2D
#import matplotlib.pyplot as plt

# --- Import STK Modules ----------------------------------------------------------------------------------------------
# pylint: disable-msg = F0401, W0611
import stk.obj.geo.point as val_pt
import stk.img as val_plot
import stk.util.logger as util_log
import stk.util.helper as val_helper
from stk.val.base_events import ValBaseEvent, ValEventError
import stk.db.lbl.genlabel_defs as lbl_defs
import stk.db.lbl as stk_lbl
# pylint: enable-msg = F0401, W0611

# Defines ---------------------------------------------------------------------
ROAD_PATH = np.arange(0, 211)
ROAD_ONES = np.ones((211))
RDTYPE_DEFS = stk_lbl.RoadType()
EVENT_ATTR_EVENT_IMAGE = "clothoideventimage"
# --- Helper functions -----------------------------------------------------------------------------------------------


def getroadtrajestimationerror(clothoid, transformation_matrix, ego_cog, cycle_index, eval_samples):
    """ Calculates the error made in estimating a trajectory using the clothoid model.
    :param clothoid: The model parameters (c0, c1, m).
    :param transformation_matrix: the list of transformation's matrix parameters [cos,sin,dx,dy].
    :param ego_cog: the center of gravity coordinates of the ego vehicle.
    :param cycle_index: the current cycle index.
    :param eval_samples: The samples (distances) for which the estimation error is calculated.
    """
    EstimationError = []
    cloth = getestimation(clothoid)
    EstimationAbs = np.zeros((2, np.shape(cloth)[0]))
    EstimationAbs[0, ] = (transformation_matrix[0] * ROAD_PATH -
                          transformation_matrix[1] * cloth +
                          transformation_matrix[2] * ROAD_ONES)
    EstimationAbs[1, ] = (transformation_matrix[1] * ROAD_PATH +
                          transformation_matrix[0] * cloth +
                          transformation_matrix[3] * ROAD_ONES)
    EstimateArcLength = np.concatenate((([0]), np.cumsum(np.sqrt(np.power(np.diff(EstimationAbs[0, ]), 2) +
                                                         np.power(np.diff(EstimationAbs[1, ]), 2)))))
    EgoArcLength = np.concatenate((([0]), np.cumsum(np.sqrt(np.power(np.diff(ego_cog[0:1, cycle_index:]), 2) +
                                                    np.power(np.diff(ego_cog[1:2, cycle_index:]), 2)))))

    Estimation = getsamplesbyarclength(EstimationAbs[0:2, :], EstimateArcLength, eval_samples)
    GroundTruth = getsamplesbyarclength(ego_cog[0:2, cycle_index:], EgoArcLength, eval_samples)
    for i in range(0, np.shape(GroundTruth[0])[0]):
        gt_x = (GroundTruth[0])[i] - (GroundTruth[0])[i - 1]
        gt_y = (GroundTruth[1])[i] - (GroundTruth[1])[i - 1]
        dx = (GroundTruth[0])[i] - (Estimation[0])[i]
        dy = (GroundTruth[1])[i] - (Estimation[1])[i]
        EstimationError.append(np.sign(dx * gt_y - dy * gt_x) * np.sqrt(dx ** 2 + dy ** 2))

    return EstimationError


def getestimation(clothoid):
    """ Returns the estimated road.
    @param clothoid: The model parameters (c0, c1, m).
    @param Range: Distance up to which the road is estimated.
    @param Resolution: Resolution.
    @return Output: Estimated road.
    """
    sqrt_road = np.power(ROAD_PATH, 2)  # local variable
    klothoid = (np.dot(clothoid[1] / 6, np.multiply(ROAD_PATH, sqrt_road)) + np.dot(clothoid[0] / 2, sqrt_road) +
                np.dot(clothoid[2], ROAD_PATH))
    return klothoid


def getsamplesbyarclength(CurveSamples, CurveArcLength, ArcLengthSamples):
    """ Gets samples coordinates by arc length.
    @param CurveSamples: raw samples.
    @param CurveArcLength: arc length of CurveSamples.
    @param ArclengthSamples: Distances at which we want to retrive the samples from CurveSamples.
    @return X,Y: x,y coordinates of the samples at ArclengthSamples distance, taken out from CurveSamples.
    """
    idx = []
    distances = list(ArcLengthSamples)
    for dist in distances:
        for i in xrange(0, len(CurveArcLength)):
            if CurveArcLength[i] > dist:
                idx.append(i)
                break
    idx_shifted = map(lambda x: x - 1, idx)
    InterSampleDist = ((ArcLengthSamples - CurveArcLength[idx_shifted]) /
                       (CurveArcLength[idx] - CurveArcLength[idx_shifted]))
    X = CurveSamples[0, idx_shifted] + InterSampleDist * (CurveSamples[0, idx] - CurveSamples[0, idx_shifted])
    Y = CurveSamples[1, idx_shifted] + InterSampleDist * (CurveSamples[1, idx] - CurveSamples[1, idx_shifted])
    return X, Y


class ClothoidEstimation():
    """ A class for the clothoid estimation """
    MAX_PARALLEL_THREADS = 20

    def __init__(self, c0, c1, yaw, ego_motion, veh_speed):
        """ Class constructor """
        self.__logger = util_log.Logger(self.__class__.__name__)
        self.__c0 = c0
        self.__c1 = c1
        self.__yaw = yaw
        self.__ego_motion = ego_motion
        self.__veh_speed = veh_speed
        self.estimation_error = None

    def CalculateEstimationError(self, last_usable_cycle, cog_coordinates, evaluation_samples, time_evaluation=True):
        """ Calculates the estimation error for every usable cycle using the provided evaluation samples.
        :param last_usable_cycle: The last usable cycle.
        :param cog_coordinates: The center of gravity's coordinates.
        :param evaluation_samples: The samples for which the clothoid estimation is evaluated.
        :param time_evaluation: Boolean. True if the evaluation samples are time based,
                                false if they are distance based.
        """
        self.estimation_error = np.zeros((len(evaluation_samples), last_usable_cycle))
        # Multi-threading
        # --- Determine how many threads should be generated ---
        nb_threads = self.__GetNumberofThreads()
        cycles = list(np.arange(0, last_usable_cycle, int(last_usable_cycle / nb_threads)))
        cycles.append(last_usable_cycle)
        # --- Constructing the threads ---
        threads = []
        for index in range(1, len(cycles)):
            threads.append(MultiThreading(index, "Thread-" + "%d" % index,
                                          cog_coordinates,
                                          self.__c0,
                                          self.__c1,
                                          self.__yaw,
                                          self.__ego_motion,
                                          self.__veh_speed,
                                          cycles[index - 1],
                                          cycles[index],
                                          self.estimation_error,
                                          evaluation_samples,
                                          time_evaluation))
        # --- Executing the threads ---
        monitoring = []
        for t in threads:
            t.start()
            monitoring.append(t)
        self.__logger.info("%d Threads are running for this file" % nb_threads)
        for thread in monitoring:
            thread.join()
        self.__logger.info("%d Threads finished running" % nb_threads)

    def __GetNumberofThreads(self):
        """ Determines the number of threads to use
        :return: the number of threads """
        total_nb_cycles = len(self.__c0)
        nb_threads = round(float(total_nb_cycles) / 8000.0)
        nb_threads = np.min(nb_threads, self.MAX_PARALLEL_THREADS)

        return nb_threads

    def GetEstimationError(self):
        """ Returns the time based estimation error
        """
        return self.estimation_error


class Clothoid():
    """ A class to handle the clothoid events """
    CLOTHOID_PLOT_KEYWORD = "clothoideventplot"

    def __init__(self, eventtype, event_threshold, estimation_error,
                 timestamps, event_sample, time_based_sample=True):
        """ Constructor for the class
        :param eventtype: The event type.
        :param event_threshold: The threshold (in m) used to trigger an event.
        :param estimation_error: The clothoid estimation error vector.
        :param timestamps: The timestamp vector.
        :param event_sample: The evaluation sample used for event generation.
        :param time_based_sample: Boolean. True if the evaluation samples are time based,
                                  false if they are distance based.
        """
        self.__logger = util_log.Logger(self.__class__.__name__)
        self.__eventtype = eventtype
        self.__threshold = event_threshold
        self.__eventsample = event_sample
        self.__time_based_sample = time_based_sample
        self.__estimation_error = estimation_error
        self.__timestamp = timestamps
        self.__event_list = None
        self.__event_signal = None

    def DetectAndFilterEvents(self, grouping_pattern=None, bool_indexes=None, label_signal=None, min_duration=None):
        """ Detects events for the clothoid estimation and filters them
        :param grouping_pattern: a pattern used to group events that are close to each other.
        :param bool_indexes: An array containing booleans for specific index processing.
        :param label_signal: The road type label signal.
        :param min_duration: Minimal duration in cycles for an event to be taken into consideration.
        """
        self.__DetectThresholdExceed()
        if bool_indexes is not None:
            self.__ProcessSpecialIndexes(bool_indexes)
        if grouping_pattern is not None:
            self.__GroupClothoidEvents(grouping_pattern)
        if label_signal is not None:
            self.__FilterEventsPerRoadType(label_signal)
        if min_duration is not None:
            self.__FilterEventsByDuration(min_duration)

    def __DetectThresholdExceed(self):
        """ Detects events in the estimation error array and sets the event signal attribute.
        """
        # --- Event signal is initialized with zeros ---
        self.__event_signal = np.zeros(np.shape(self.__estimation_error)[0])
        # --- Event signal is equal to one when the error is over the threshold ---
        self.__event_signal[np.nonzero(self.__estimation_error >= self.__threshold)] = 1

    def __ProcessSpecialIndexes(self, boolean_indexes):
        """ Sets the event signal to zero in the specified indexes.
        :param boolean_indexes: An array with the same size as the event signal. Events set to zero where False.
        """
        self.__event_signal[np.logical_not(boolean_indexes)] = 0

    def __GroupClothoidEvents(self, pattern):
        """ Filters the events and creates the event list.
        :param pattern: The pattern for event grouping.
        """
        # --- Convolve event_signal with pattern ---
        convolution = np.convolve(self.__event_signal, pattern)
        # --- Clip values to 0 and 1 ---
        clipped_convolution = np.clip(convolution, 0, 1)
        # --- Get index list ---
        edges = np.convolve(clipped_convolution, [1, -1])
        indexes = np.nonzero(edges)
        edges = edges[indexes]
        idx = list(indexes[0])
        self.__event_list = []
        # --- If len idx is zero then there are no events , also len idx has to be a multiple of 2 ---
        if len(idx) > 0 and not (len(idx) % 2):
            i = 0
            while i < len(idx):
                start = idx[i]
                # --- The convolution shifts the end of the events of (len(smoother) - 1) ---
                stop = idx[i + 1] - (len(pattern) - 1)
                # --- Create new clothoid base event ---
                ev = ValClothoidEvent(self.__timestamp[start], start,
                                      self.__timestamp[stop], stop,
                                      self.__eventtype)
                ev.SetEventThreshold(self.__threshold)
                ev.SetEstimationError(self.__estimation_error[ev.GetStartIndex()])
                ev.SetTimeSample(self.__eventsample)
                self.__event_list.append(ev)
                i += 2

    def __FilterEventsPerRoadType(self, label_signal):
        """ Filters the event per road type, i.e keeps events happening in the same road type.
        :param label_signals: The road type label signal
        """
        filtered_events = []
        for ev in self.__event_list:
            rdtype = label_signal[ev.GetStartIndex():ev.GetStopIndex()]
            # --- Calculate diff, and if sum diff is null then road type is the same during the entire event ---
            if np.sum(np.diff(rdtype)) == 0:
                ev.SetRoadType(rdtype[0])
                filtered_events.append(ev)
        self.__event_list = filtered_events

    def __FilterEventsByDuration(self, nb_cycle_min=None):
        """ Filters the event against a minimal cycle amount.
        :param nb_cycle_min: The minimal cycle number for an event to be kept.
        """
        if nb_cycle_min is not None:
            filtered_events = []
            for ev in self.__event_list:
                if ev.GetEventCycles() >= nb_cycle_min:
                    filtered_events.append(ev)
            self.__event_list = filtered_events

    def SetClothoidParameters(self, c0, c1, yaw, timing=False):
        """ For every event sets the clothoid parameters in the event attributes.
        :param c0, c1, yaw: the clothoid parameters.
        """
        for ev in self.__event_list:
            ev.SetClothoidParams(c0, c1, yaw, timing=timing)

    def SetEgoKinematics(self, vdy_data, timing=False):
        """ Sets the ego kinematics for the events.
        :param vdy_data: the vdy data container.
        """
        filtered_events = []
        for ev in self.__event_list:
            if np.all(np.array(vdy_data["VehicleSpeed"][ev.GetStartIndex():ev.GetStopIndex()]) > 0.0):
                ev.SetEgoKinematics(vdy_data, timing=timing)
                filtered_events.append(ev)
        self.__event_list = filtered_events

    def GetClothoidEventList(self):
        """ Return the clothoid event list """
        return self.__event_list

    def GenerateClothoidPlot(self, c0, c1, yaw, speed, ego_motion, cog_arclength, output):
        """ Generates a plot for the clothoid events.
        :param c0, c1, yaw: The clothoid parameters.
        :param speed: Vehicle speed.
        :param ego_motion: Ego motion.
        :param cog_arclength: The ego car's arc length.
        :param output: the output path folder.
        """
        cog_coordinates = ego_motion[0:2].copy()
        plotter = val_plot.ValidationPlot(output)
        for ev in self.__event_list:
            # --- Get the start index and the index corresponding to a travelled distance of 200m ---
            try:
                start = ev.GetStartIndex()
                stop = np.nonzero(cog_arclength[0, ] >= (cog_arclength[0, start] + 200.0))[0][0]
            except ValueError, ex:
                self.__logger.warning("Could not generate event image because of %s" % ex)
            else:
                # --- Create an empty figure ---
                ax = plotter.GenerateFigure()
                plot_data = []
                legend = []
                # --- Ego vehicle's path ---
                cog_x = cog_coordinates[0, start:stop]
                cog_y = cog_coordinates[1, start:stop]
                cog_z = np.ones((cog_x.size))
                cog_event = np.array([cog_x, cog_y, cog_z])
                cog_alength = np.concatenate((([0]), np.cumsum(np.sqrt(np.power(np.diff(cog_event[0:1]), 2) +
                                                                       np.power(np.diff(cog_event[1:2]), 2)))))
                # --- Switch back to car coordinates ---
                transfo_matrix = np.array([[ego_motion[6][start], ego_motion[5][start], ego_motion[2][start]],
                                           [-ego_motion[5][start], ego_motion[6][start], ego_motion[3][start]],
                                           [0, 0, 1]])
                cog_transformed = np.dot(transfo_matrix, cog_event)
                plot_data.append(val_pt.GetPointPairList(list(cog_transformed[1, ]), list(cog_transformed[0, ])))
                legend.append("Ego vehicle's path")
                # --- Plot clothoid ---
                clt_x = np.arange(0, 200, 0.1)
                clt_y = (yaw[start] * clt_x +
                         (c0[start] / 2.0) * clt_x ** 2 +
                         (c1[start] / 6.0) * clt_x * clt_x ** 2)
                clt_event = np.array([clt_x, clt_y])
                clt_alength = np.concatenate((([0]), np.cumsum(np.sqrt(np.power(np.diff(clt_event[0:1]), 2) +
                                                                       np.power(np.diff(clt_event[1:2]), 2)))))
                plot_data.append(val_pt.GetPointPairList(list(clt_y), list(clt_x)))
                legend.append("Road course estimation")
                # --- Generate plot ---
                img = plotter.GeneratePlot(plot_data, legend, "error e(m)", "P(error > e)", True, True,
                                           title="Event visualization", axes=ax, line_colors=['0.75', 'r'],
                                           line_width=[4.0, 2.0])
                # --- Get comparison points ---
                try:
                    if self.__time_based_sample is True:
                        distance = self.__eventsample * speed[start]
                    else:
                        distance = self.__eventsample
                    cog_cmp_idx = np.nonzero(cog_alength <= distance)[0][-1]
                    clt_cmp_idx = np.nonzero(clt_alength >= distance)[0][0]
                    X1 = clt_x[clt_cmp_idx]
                    Y1 = clt_y[clt_cmp_idx]
                    X2 = cog_transformed[0, ][cog_cmp_idx]
                    Y2 = cog_transformed[1, ][cog_cmp_idx]
                    line = Line2D([Y1, Y2], [X1, X2], color='g', ls='-', linewidth=2.0)
                    ax.add_line(line)
                    ax.text(0.01, 0.9, "|err| = %0.2fm" % ev.GetEstimationError(), transform=ax.transAxes)
                except ValueError, ex:
                    self.__logger.warning("No line could be drawn between the comparion points %s" % ex)
                finally:
                    # --- Set plot parameters ---
                    img.xlim([-40, 40])
                    img.xlabel("Y axis")
                    img.ylim([0, 200])
                    img.ylabel("X axis")
                    img.gca().invert_xaxis()
                    img_buffer = plotter.GetPlotDataBuffer(img)
                    ev.SetEventImage(img_buffer)


class MultiThreading(threading.Thread):
    """
    Used in order to process each file in multiple threads.
    """
    def __init__(self, ID, thread_name, COG, c0, c1, yaw, ego, speed,
                 cycle_start, cycle_stop, Error, evaluation_samples, time_evaluation):
        """
        Sets all necessary attributes for processing.
        """
        self.ID = ID  # thread ID
        self.thread_name = thread_name  # thread Name
        self.COG = COG  # Ego path
        self.cyc_start = cycle_start  # Loop start
        self.cyc_stop = cycle_stop  # Loop end
        self.road_c0 = c0  # road's c0 curve
        self.road_c1 = c1  # road's c1 curve
        self.road_yaw = yaw  # road's yaw
        self.ego_motion = ego  # Ego motion
        self.speed = speed  # Ego vehicle's speed
        self.estimation_error = Error
        self.evaluation_samples = evaluation_samples
        self.time_evaluation = time_evaluation
        threading.Thread.__init__(self)  # Thread creation

    def run(self):
        """
        Each thread processes one section of the file.
        """
        for i in xrange(self.cyc_start, self.cyc_stop):
            clothoid = [self.road_c0[i], self.road_c1[i], self.road_yaw[i]]
            transformation_matrix = [self.ego_motion[6, i],
                                     self.ego_motion[5, i],
                                     self.ego_motion[0, i],
                                     self.ego_motion[1, i]]
            VehicleSpeed = self.speed[i]
            if self.time_evaluation is True:
                eval_samples = VehicleSpeed * np.array(self.evaluation_samples)
            else:
                eval_samples = self.evaluation_samples
            Estimation_error = getroadtrajestimationerror(clothoid, transformation_matrix, self.COG, i, eval_samples)

            if len(Estimation_error) > 0:
                for j in xrange(0, len(self.evaluation_samples)):
                    self.estimation_error[j, i] = Estimation_error[j]


# --- Base clothoid event ---
class ValClothoidEvent(ValBaseEvent):
    # pylint: disable-msg = E1101
    """ Clothoid Event Class """
    # --- Attribute definitions ---
    BEGIN_ABSTS = "start ts"
    END_ABSTS = "end ts"
    EVENT_ATTR_C0 = "clothoidc0"
    EVENT_ATTR_C1 = "clothoidc1"
    EVENT_ATTR_YAW = "clothoidyaw"
    EVENT_ATTR_ERROR = "clothoidestimationerror"
    EVENT_ATTR_THRESHOLD = "clothoideventthreshold"
    EVENT_ATTR_TIME_SAMPLE = "clothoidtimesample"
    EVENT_ATTR_CONFIDENCE = "clothoidconfidence"
    EVENT_ATTR_TRACKSTAT = "clothoidtrackingstatus"

    def __init__(self, start_time, start_index, stop_time, stop_index,
                 eventtype, timestamps=None, seid=None, assessment_id=None):
        """
        Constructor for clothoid event.
        :param start_time: start timestamp of the event.
        :param start_index: start cycle index of the event.
        :param stop_time: stop timestamp for the event.
        :param stop_index: stop cycle index of the event.
        """
        self.__logger = util_log.Logger(self.__class__.__name__)

        ValBaseEvent.__init__(self, start_time=start_time,
                              start_index=start_index,
                              stop_time=stop_time,
                              stop_index=stop_index,
                              timestamps=timestamps,
                              seid=seid,
                              assessment_id=assessment_id)

        ValBaseEvent.SetType(self, eventtype)
        if assessment_id is None:
            # --- Sets a default assessment ---
            ValBaseEvent.SetAssessment(self, 'Not assessed',
                                       comment="Automatic assessment - Not assessed")

        self.AddAttribute('cycles', (stop_index - start_index), '', 'float')

        self.__start_idx = start_index
        self.__stop_idx = stop_index
        self.__vdy_data = None
        self.__road_type = None
        self.__estimationerror = None
        self.__time_sample = None
        self.__eventthreshold = None
        self.__roadc0 = None
        self.__roadc1 = None
        self.__roadyaw = None
        self.__roadconfidence = None
        self.__roadtrackstat = None

    def SaveEventDB(self, dbval, dbglbl, trid, collid, measid):
        """ Save Event in Database, but before put all necessary data into event details container.
        :param dbval: VAL DB interface.
        :param dbglbl: GBL DB interface.
        :param trid: Testrun identifier.
        :param collid: CAT Collection ID.
        :param measid: Measurement Identifier.
        """
        ValBaseEvent.Save(self, dbval, dbglbl, trid, collid, meas_id=measid)

# --- Functions for setting the attributes of the event --------------------------------------------------------------

    def SetClothoidParams(self, curve0, curve1, yaw, timing=False):
        """ Sets the road clothoid parameters y(x) = m * x + (c0 / 2) * x^2 + (c1 / 6) * x^3.
        :param curve0: c0.
        :param curve1: c1.
        :param yaw: m.
        :note input format: Either floats or list of floats.
        """
        self.__roadc0 = curve0
        self.__roadc1 = curve1
        self.__roadyaw = yaw
        start_idx = self.GetStartIndex()
        stop_idx = self.GetStopIndex()
        if timing is False:
            self.AddAttribute(self.EVENT_ATTR_C0, curve0[start_idx], '', 'float')
            self.AddAttribute(self.EVENT_ATTR_C1, curve1[start_idx], '', 'float')
            self.AddAttribute(self.EVENT_ATTR_YAW, yaw[start_idx], '', 'float')
        else:
            self.AddTimingAttribute(self.EVENT_ATTR_C0, curve0[start_idx:stop_idx], '', 'float')
            self.AddTimingAttribute(self.EVENT_ATTR_C1, curve1[start_idx:stop_idx], '', 'float')
            self.AddTimingAttribute(self.EVENT_ATTR_YAW, yaw[start_idx:stop_idx], '', 'float')

    def GetClothoidParams(self):
        """ Returns c0,c1, yaw.
        """
        return self.__roadc0, self.__roadc1, self.__roadyaw

    def GetStartIndex(self):
        """ Returns the start index of the event.
        """
        return self.__start_idx

    def SetRoadInfo(self, confidence, tracking_status, timing=False):
        """ Sets road info parameters.
        :param confidence: confidence in the road estimation.
        :param tracking_status: tracking status.
        """
        self.__roadconfidence = confidence
        self.__roadtrackstat = tracking_status
        start_idx = self.GetStartIndex()
        stop_idx = self.GetStopIndex()
        if timing is False:
            self.AddAttribute(self.EVENT_ATTR_CONFIDENCE, confidence[start_idx], '', 'float')
            self.AddAttribute(self.EVENT_ATTR_TRACKSTAT, tracking_status[start_idx], '', 'float')
        else:
            self.AddTimingAttribute(self.EVENT_ATTR_CONFIDENCE, confidence[start_idx:stop_idx], '', 'float')
            self.AddTimingAttribute(self.EVENT_ATTR_TRACKSTAT, tracking_status[start_idx:stop_idx], '', 'float')

    def SetEgoKinematics(self, vdy_data, timing=False):
        """
        Sets the vehicle dynamics info.
        :param vdy_data: vdy_data dictionnary containing the necessary signals.
        """
        self.__vdy_data = vdy_data
        start_idx = self.GetStartIndex()
        stop_idx = self.GetStopIndex()
        try:
            if len(self.__vdy_data) > 0:
                if timing is True:
                    veh_speed = vdy_data["VehicleSpeed"][start_idx:stop_idx]
                    yawrate = vdy_data["VehicleYawRateObjSync"][start_idx:stop_idx]
                    acceleration = vdy_data["VehicleAccelXObjSync"][start_idx:stop_idx]
                    veh_curve = vdy_data["VehicleCurveObjSync"][start_idx:stop_idx]
                    self.AddTimingAttribute('acceleration', acceleration, '', 'float')
                    self.AddTimingAttribute('radius', veh_curve, '', 'float')
                    self.AddTimingAttribute('vehspeed', veh_speed, '', 'float')
                    self.AddTimingAttribute('yawrate', yawrate, '', 'float')
                else:
                    veh_speed = vdy_data["VehicleSpeed"][start_idx]
                    yawrate = vdy_data["VehicleYawRateObjSync"][start_idx]
                    acceleration = vdy_data["VehicleAccelXObjSync"][start_idx]
                    veh_curve = vdy_data["VehicleCurveObjSync"][start_idx]
                    self.AddAttribute('acceleration', acceleration, '', 'float')
                    self.AddAttribute('radius', veh_curve, '', 'float')
                    self.AddAttribute('vehspeed', veh_speed, '', 'float')
                    self.AddAttribute('yawrate', yawrate, '', 'float')
        except:
            raise ValEventError('Class Type of kinematic information is not correct')

    def GetVDYData(self):
        """ Returns the vdy data at the time of the event.
        """
        return self.__vdy_data

    def SetEstimationError(self, error):
        """ Sets the estimation error attribute for the detected event.
        """
        self.__estimationerror = error
        if isinstance(error, float):
            self.AddAttribute(self.EVENT_ATTR_ERROR, error, 'meter', 'float')
        else:
            raise ValEventError('Time sample is a global attribute --> has to be a float')

    def GetEstimationError(self):
        """ Returns the estimation error for the current event.
        """
        return self.__estimationerror

    def SetTimeSample(self, time_sample):
        """ Sets the time sample for which the event is detected.
        :param time_sample: time sample where the event is generated.
        """
        self.__time_sample = time_sample
        if isinstance(time_sample, float):
            self.AddAttribute(self.EVENT_ATTR_TIME_SAMPLE, time_sample, 'second', 'float')
        else:
            raise ValEventError('Time sample is a global attribute --> has to be a float')

    def SetRoadType(self, road_type):
        """ Sets the road type.
        :param road_type: road type as a string.
        """
        self.__road_type = road_type
        if isinstance(road_type, float):
            self.AddAttribute(RDTYPE_DEFS.EVENT_ATTR_ROAD_TYPE, road_type, '', 'float')
        else:
            raise ValEventError('Road type is a global attribute --> has to be a float')

    def GetRoadType(self):
        """ Returns the road type for the event.
        :return: road type.
        """
        return self.__road_type

    def SetEventThreshold(self, threshold):
        """ Sets the event triggering threshold used.
        :param threshold: event threshold in meters.
        """
        self.__eventthreshold = threshold
        if isinstance(threshold, float):
            self.AddAttribute(self.EVENT_ATTR_THRESHOLD, threshold, '', 'float')
        else:
            raise ValEventError('Threshold is a global attribute --> has to be a float')

    def SetEventImage(self, buff):
        """ Stores the event image in the database.
        :param buff: the image buffer.
        """
        self.AddAttribute(EVENT_ATTR_EVENT_IMAGE, image=buff)
# pylint: disable-msg = W0105
"""
CHANGE LOG:
-----------
$Log: clothoid.py  $
Revision 1.1 2021/12/13 17:58:47CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/clothoid/project.pj
Revision 1.4 2013/12/03 17:33:07CET uidg3354 
pylint fix
- Added comments -  uidg3354 [Dec 3, 2013 5:33:07 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.3 2013/07/29 09:55:15CEST Ibrouchene, Nassim (uidt5589)
Uses Save instead of SaveEventDB for event save.
Clothoid error estimation can be chosen to be done with time based samples or distance based samples.
--- Added comments ---  uidt5589 [Jul 29, 2013 9:55:15 AM CEST]
Change Package : 182606:2 http://mks-psad:7002/im/viewissue?selection=182606
Revision 1.2 2013/05/14 10:46:55CEST Ibrouchene-EXT, Nassim (uidt5589)
Moved some functions away from helper.py.
--- Added comments ---  uidt5589 [May 14, 2013 10:46:55 AM CEST]
Change Package : 182606:2 http://mks-psad:7002/im/viewissue?selection=182606
"""
