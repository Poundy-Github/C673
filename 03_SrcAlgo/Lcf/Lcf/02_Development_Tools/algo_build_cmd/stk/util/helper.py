"""
stk/util/helper.py
-------------------

Stand alone utility functions.


:org:           Continental AG
:author:        Christoph Castell

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:38CET $
"""

# pylint: disable=C0103

# Import Python Modules -------------------------------------------------------
from os import path, walk
from sys import version_info
from datetime import datetime
from math import pow as mpow
# import numpy as np
import numpy.core as npc
from warnings import warn

# Import STK Modules ----------------------------------------------------------

# Vehicle Dynamics Definitions
PORT_VDY_VEHICLE_SPEED = "VehicleSpeed"
PORT_VDY_VEHICLE_ACCEL = "VehicleAccelXObjSync"
PORT_VDY_VEHICLE_CURVE = "VehicleCurveObjSync"
PORT_VDY_VEHICLE_YAWRATE = "VehicleYawRateObjSync"

# Functions -------------------------------------------------------------------


def ListFolders(headDir):
    """ Return list of sub folders
    """
    for root, dirs, _ in walk(headDir, topdown=True):
        for dirName in dirs:
            dirPath = path.join(root, dirName)
            yield dirPath


def deprecation(message):
    """helping to write a user deprecation warning"""
    warn(message, UserWarning if version_info[1] <= 7 else PendingDeprecationWarning, stacklevel=2)


def Sec2HmsString(seconds):
    """ Converts seconds to an HMS string of the format 00:00:00.
    @param seconds: Input seconds.
    @return: HMS string
    """
    if seconds is not None:
        mins, secs = divmod(seconds, 60)
        hours, mins = divmod(mins, 60)
        return "%02d:%02d:%02d" % (hours, mins, secs)
    return ""


def GetCurrentDateString():
    """ Get the current date as a string.
    @return: Date string in format DD.MM.YYYY.
    """
    date_time = datetime.now()
    year = "%04d" % date_time.year
    month = "%02d" % date_time.month
    day = "%02d" % date_time.day
    current_date_str = "%s.%s.%s" % (day, month, year)
    return current_date_str


def GetNameFromPath(file_path):
    """ Get a file name froma file path.
    @param file_path: The file path.
    """
    head_tail = path.split(file_path)
    root_ext = path.splitext(head_tail[1])
    return root_ext[0]


def GetReportConfigFromFile(report_module_path):
    """ Extracts the report config data from a file and returns.
    @raise report_module_path: The path to the report module.
    @return: Returns the report config xml string.
    """
    config_xml = ""
    config_found_b = False
    rep_file = open(report_module_path, "r").readlines()
    for line in rep_file:
        if (line.find("<configuration_options>") == 0):
            config_found_b = True
        if (line.find("</configuration_options>") == 0):
            config_xml += line
            config_found_b = False
        if config_found_b:
            config_xml += line
    return config_xml


def GetEgoDispl(vdy_data, cycle_time):
    """ Calculate the EGO displacement for each cycle
    @param vdy_data:    Vehicle Dynamic data (dictionary from data_extractor)
    @param cycle_time:  Time of each cycle (
    @return ego displacement vector
    """
    v = vdy_data[PORT_VDY_VEHICLE_SPEED]
    a = vdy_data[PORT_VDY_VEHICLE_ACCEL]

    ego_displ = [0] * len(v)

    for CycleIdx in xrange(0, len(v)):
        dt = cycle_time[CycleIdx]
        ego_displ[CycleIdx] = (v[CycleIdx] * dt) + (0.5 * a[CycleIdx] * mpow(dt, 2))

    return ego_displ


def StdDev(data):
    """caculates a standard deviation
    """
    tSum = 0.0
    length = len(data)
    meanval = npc.mean(data)
    for i in range(length):
        temp = 0.0
        temp = data[i] - meanval
        temp = temp * temp
        tSum += temp

    if length <= 1:
        std_dev = npc.sqrt(tSum / length)
    else:
        std_dev = npc.sqrt(tSum / (length - 1))

    return std_dev, meanval


def GetCycleTime(time_stamps):
    """ Calculate the cycle time according to the time stamps
    @param time_stamps : time stamps of the signal from data_extractor in micro seconds
    @return: Cycle Time Vector in seconds

    @todo: check usage of cycle time
    """
    length = len(time_stamps)
    total_cycle = [0] * length
    if length > 0:

        for x in xrange(1, length - 1):
            total_cycle[x] = float((time_stamps[x] - time_stamps[x - 1])) / 1000000.0

        if length > 1:
            total_cycle[0] = total_cycle[1]
    return total_cycle


def GetDrivingDistance(ego_displ, start_index, stop_index):
    """ Calculate the Driving Distance
    @param ego_displ: EGO Displacement
    @param start_index: Start index
    @param stop_index: Stop index
    @return: distance between start and end index driven in meters
    """
    driv_dist = 0
    for idx in xrange(start_index, stop_index):
        driv_dist += ego_displ[idx]

    return driv_dist


def GetTimeVecIn_ms(time_vec_us):
    """ converts a given time vector from Microsekonds into milliseconds

    @param time_vec_us: Time vector in micro seconds
    @return: Time Vector in milliseconds
    """
    time_vec_ms = [ts / 1000.0 for ts in time_vec_us]
    return time_vec_ms


def GetTimeVecIn_sec(time_vec_us):
    """ converts a given time vector from Microsekonds into seconds

    @param time_vec_us: Time vector in micro seconds
    @return: Time Vector in seconds
    """
    time_vec_s = [ts / 1000000.0 for ts in time_vec_us]
    return time_vec_s


def GetTimeIn_sec(time_us):
    """ converts a given time from Microsekonds into seconds

    @param time_us: Time in micro seconds
    @return: Time Vector in seconds
    """
    return time_us / 1000000.0


def GetSpeedIn_kmph(speed_vec_mps):
    """ converts a given speed vector from meters per second into kilometers per second

    @param speed_vec_mps: Speed vector in meters per second
    @return: Speed Vector in kilometers per second
    """
    speed_vec = [val * 3.600 for val in speed_vec_mps]
    return speed_vec


"""
CHANGE LOG:
-----------
$Log: helper.py  $
Revision 1.1 2021/12/13 17:59:38CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/util/project.pj
Revision 1.11 2013/10/01 16:41:25CEST Mertens, Sven (uidv7805) 
last fine adjustment
- Added comments -  uidv7805 [Oct 1, 2013 4:41:25 PM CEST]
Change Package : 185933:7 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.10 2013/09/09 12:13:57CEST Raedler, Guenther (uidt9430)
- removed old function already supported by stk.geo
- cleared import which is  not valid in this module
--- Added comments ---  uidt9430 [Sep 9, 2013 12:13:57 PM CEST]
Change Package : 196676:1 http://mks-psad:7002/im/viewissue?selection=196676
Revision 1.9 2013/05/23 06:24:08CEST Mertens, Sven (uidv7805)
removed some pylint errors
--- Added comments ---  uidv7805 [May 23, 2013 6:24:08 AM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.8 2013/05/14 10:49:43CEST Ibrouchene-EXT, Nassim (uidt5589)
Removed functions that are now in the clothoid package.
--- Added comments ---  uidt5589 [May 14, 2013 10:49:43 AM CEST]
Change Package : 182606:2 http://mks-psad:7002/im/viewissue?selection=182606
Revision 1.7 2013/03/28 09:33:13CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:14 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/22 09:20:49CET Mertens, Sven (uidv7805)
last pep8 update on non-trailing white space errors
--- Added comments ---  uidv7805 [Mar 22, 2013 9:20:50 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.5 2013/03/01 15:39:18CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 3:39:18 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/28 08:12:21CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:21 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/27 16:19:58CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:19:58 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/19 14:40:41CET Raedler, Guenther (uidt9430)
added helper function to list folders
--- Added comments ---  uidt9430 [Feb 19, 2013 2:40:42 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 10:56:34CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/util/project.pj
------------------------------------------------------------------------------
-- From etk/vpc Archive
------------------------------------------------------------------------------
Revision 1.19 2012/05/08 16:32:57CEST Ibrouchene-EXT, Nassim (uidt5589)
Improved computation time for the road functions.
--- Added comments ---  uidt5589 [May 8, 2012 4:33:00 PM CEST]
Change Package : 94467:3 http://mks-psad:7002/im/viewissue?selection=94467
Revision 1.18 2012/03/27 14:31:41CEST Raedler-EXT, Guenther (uidt9430)
reintegrate changes from branch into common trunk
--- Added comments ---  uidt9430 [Mar 27, 2012 2:31:42 PM CEST]
Change Package : 88554:1 http://mks-psad:7002/im/viewissue?selection=88554
Revision 1.17 2012/02/28 10:13:52CET Ibrouchene-EXT, Nassim (uidt5589)
Added a few functions common to road and trajectory estimation.
--- Added comments ---  uidt5589 [Feb 28, 2012 10:13:52 AM CET]
Change Package : 94467:1 http://mks-psad:7002/im/viewissue?selection=94467
Revision 1.16 2012/02/01 11:47:37CET Raedler-EXT, Guenther (uidt9430)
- added common std and mean calculation
--- Added comments ---  uidt9430 [Feb 1, 2012 11:47:38 AM CET]
Change Package : 88150:1 http://mks-psad:7002/im/viewissue?selection=88150
Revision 1.15 2011/12/15 14:15:57CET Raedler-EXT, Guenther (uidt9430)
- added function GetTimeVecIn_sec and GetTimeIn_sec
- added function GetSpeedInKmph
--- Added comments ---  uidt9430 [Dec 15, 2011 2:15:58 PM CET]
Change Package : 88150:1 http://mks-psad:7002/im/viewissue?selection=88150
Revision 1.14 2011/11/18 13:17:40CET Raedler Guenther (uidt9430) (uidt9430)
- added new function ShiftTimelineOfPointPairList()
- added some documentation
--- Added comments ---  uidt9430 [Nov 18, 2011 1:17:41 PM CET]
Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.13 2011/11/16 12:57:18CET Castell Christoph (uidt6394) (uidt6394)
Return types not clear from function name and also not commented. Left for author to fix.
Replaced magic number with val_gd.CYCLE_TIME_S (bad programming parctice).
Inconsistent localy defined cycle time in ADMA and some other modules also need to be replaced.
--- Added comments ---  uidt6394 [Nov 16, 2011 12:57:19 PM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.12 2011/11/16 10:35:11CET Raedler Guenther (uidt9430) (uidt9430)
- fixed error due to renamed port name
--- Added comments ---  uidt9430 [Nov 16, 2011 10:35:11 AM CET]
Change Package : 76661:1 http://mks-psad:7002/im/viewissue?selection=76661
Revision 1.11 2011/11/15 10:33:47CET Raedler Guenther (uidt9430) (uidt9430)
- addef function to calculate the corrct cycle time of the measurement
--- Added comments ---  uidt9430 [Nov 15, 2011 10:33:47 AM CET]
Change Package : 76661:1 http://mks-psad:7002/im/viewissue?selection=76661
Revision 1.10 2011/11/11 09:33:31CET Castell Christoph (uidt6394) (uidt6394)
Made VDY port names global.
--- Added comments ---  uidt6394 [Nov 11, 2011 9:33:31 AM CET]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.9 2011/11/07 15:32:37CET Raedler Guenther (uidt9430) (uidt9430)
- added new functions for boxes and polygons
--- Added comments ---  uidt9430 [Nov 7, 2011 3:32:37 PM CET]
Change Package : 67780:7 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.8 2011/10/07 07:45:12CEST Raedler Guenther (uidt9430) (uidt9430)
- extened validation event class
- added new class for stationary obstacles
- added global defines
--- Added comments ---  uidt9430 [Oct 7, 2011 7:45:12 AM CEST]
Change Package : 76661:3 http://mks-psad:7002/im/viewissue?selection=76661
Revision 1.7 2011/09/20 12:30:16CEST Castell Christoph (uidt6394) (uidt6394)
Added GetNameFromPath() function.
--- Added comments ---  uidt6394 [Sep 20, 2011 12:30:16 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.6 2011/08/11 10:51:29CEST Raedler Guenther (uidt9430) (uidt9430)
-- checks for None
--- Added comments ---  uidt9430 [Aug 11, 2011 10:51:29 AM CEST]
Change Package : 67780:5 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.5 2011/08/03 13:01:07CEST Castell Christoph (uidt6394) (uidt6394)
Added function to get report config from file.
--- Added comments ---  uidt6394 [Aug 3, 2011 1:01:07 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.4 2011/08/02 07:11:32CEST Raedler Guenther (uidt9430) (uidt9430)
- added functions to get and split a pointpair lists
- added function to change a time vector from us to ms
--- Added comments ---  uidt9430 [Aug 2, 2011 7:11:32 AM CEST]
Change Package : 67780:5 http://mks-psad:7002/im/viewissue?selection=67780
Revision 1.3 2011/07/29 09:36:39CEST Castell Christoph (uidt6394) (uidt6394)
New GetEgoPath(VDYData) function. Not the ideal location for this function.
May move in future if better location found.
--- Added comments ---  uidt6394 [Jul 29, 2011 9:36:39 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.2 2011/07/28 08:29:27CEST Castell Christoph (uidt6394) (uidt6394)
Added Sec2HmsString() and GetCurrentDateString() functions.
--- Added comments ---  uidt6394 [Jul 28, 2011 8:29:28 AM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.1 2011/07/21 15:09:57CEST Castell Christoph (uidt6394) (uidt6394)
Initial revision
Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/05_Testing/
05_Test_Environment/algo/ars301_req_test/valf_tests/vpc/project.pj

"""
