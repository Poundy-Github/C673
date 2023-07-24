"""
app_watcher.py
--------------

Script used by app_starter.py to monitor the running task.

Arguments:
 - process id of the process which should be monitored

:org:           Continental AG
:author:        Ralf Paulig

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:08CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import sys
import time
import traceback
from optparse import OptionParser
import wmi
import socket

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------
PyLibFolder = os.getcwd()

if PyLibFolder not in sys.path:
    sys.path.append(PyLibFolder)

# Import STK Modules ----------------------------------------------------------
import stk.hpc.app.monitor_ipc as monitor_ipc

# Import Local Python Modules -------------------------------------------------

# Defines ---------------------------------------------------------------------

EXIT_APP_CPU_IDLE = -1  # exit code if app is idle
EXIT_APP_IO_IDLE = -2  # exit code if I/O activity is too low
EXIT_ERROR = -10  # exit code if internal error occured
EXIT_APP_MONITOR_CLOSED = 1  # exit code when AppMonitor Closed

FAIL_THRESHOLD = 5  # amount of tolerated wmi request fails in a row

# current values are tuned to cancel when the process tree
# fullfills one of the following:
#   - no CPU usage for about 5 min or less then 2%
#     on a one core basis for a longer time
#   - less then 6 kb/s I/O traffic for 30 min

REQUEST_CYCLE = 60.0  # time to wait between to requests in [s]
FILTER_STRENGTH_CPU = 0.4  # factor for new value to be combined with the old
FILTER_STRENGTH_IO = 0.11  # factor for new value to be combined with the old

CPU_CONFIDENCE_THRESHOLD = 2.0  # threshold for cpu idle detection in [%]
IO_CONFIDENCE_THRESHOLD = 5.0  # threshold for i/o idle detection in [%]
FILTER_THRESHOLD_IO = 6  # i/o threshold for setting new filter
                                    # value to 0 or 1 [kb/s]


def GetNumCores():
    """
    Determines the number of Cores on this pc via the wmi interface.

    :return:    Number of Cores
    :rtype:     dict
    """
    result = {}

    wmi_ifc = wmi.WMI('.', namespace="cimv2")
    result['time'] = int(time.time())

    for item in wmi_ifc.query("SELECT * FROM Win32_Processor"):
        result['NumberOfCores'] = item.NumberOfCores

    return result['NumberOfCores']


def FilterCPU(conf, value):
    """
    Filter the given cpuvalue with a given confidence and return the new calculated
    confidence.

    :param conf:   confidence
    :type conf:    float
    :param value:  actual cpuload
    :type value:   float

    :return:    filtered cpu-value
    :rtype:     float
    """
    conf = conf * (1 - FILTER_STRENGTH_CPU) + value * FILTER_STRENGTH_CPU
    return conf


def FilterIO(conf, value):
    """
    Filter the given iovalue with a given confidence and return the new calculated
    iovalue.

    :param conf:   confidence
    :type conf:    float
    :param value:  actual ioload
    :type value:   float

    :return:    filtered ioload
    :rtype:     float
    """
    if value < FILTER_THRESHOLD_IO:
        value = 0
    else:
        value = 100
    conf = conf * (1 - FILTER_STRENGTH_IO) + value * FILTER_STRENGTH_IO
    return conf


def WatchProcess(proc_id, bIOWatch):
    """
    This is the Main Function which does the watching of the given Process.

    :param proc_id:      The Win32 ProcessId to watch.
    :type: proc_id:      integer
    :param do_io_watch:  Flag, it io watching must be done or not.
    :type do_io_watch:   boolean
    """

    Conf_CPU = 100.0
    Conf_IO = 100.0
    fail_count = 0

    # ignore number of cores cause we want to detect idle processes,
    # otherwise we would have to make the threshold also depending
    # on this number
    # #NumCores = GetNumCores()

    print "AppWatcher: Started."

    while(True):

        monitor = monitor_ipc.MonitorServer(str(proc_id))

        # Wait for connection
        while(True):
            try:
                monitor.WaitForConnection()
                break
            except socket.timeout:
                pass

        # Receive Input Data from the app_monitor
        while(True):
            data = monitor.Receive(REQUEST_CYCLE)
            if(data is None):
                print "App Watcher: Connection closed from client"
                return EXIT_APP_MONITOR_CLOSED

            if(data is ""):  # Timeout -> check what to do
                fail_count += 1
                if fail_count > FAIL_THRESHOLD:
                    tmp = "App Watcher: Process stat request failed more then "
                    tmp += "%d times in a row!!!" % FAIL_THRESHOLD
                    print >> sys.stderr, tmp
                    return EXIT_ERROR
                continue

            if(len(data) > 0):
                # CPU load can be greater then 100% due to multi core usage
                # but this is not of interest to us
                IOLoad = data['IOLoad']
                CPULoad = data['CPULoad']

                Conf_CPU = FilterCPU(Conf_CPU, CPULoad)
                Conf_IO = FilterIO(Conf_IO, IOLoad)

                # check i/o threshold
                if(bIOWatch and Conf_IO < IO_CONFIDENCE_THRESHOLD):
                    # Cancel Application
                    msg = "App Watcher: Process I/O traffic is too low!!!"
                    print >> sys.stderr, msg
                    return EXIT_APP_IO_IDLE

                # check cpu threshold
                if(Conf_CPU < CPU_CONFIDENCE_THRESHOLD):
                    # Cancel Application
                    print >> sys.stderr, "App Watcher: Process is idle!!!"
                    return EXIT_APP_CPU_IDLE


if __name__ == "__main__":
    optparser = OptionParser()
    optparser.add_option("-o",
                         dest="IOWatch",
                         default=False,
                         action="store_true",
                         help="Enable I/O traffic watch.")

    cmd_options = optparser.parse_args()

    bIOWatch = cmd_options[0].IOWatch

    args = cmd_options[1]
    if len(args) != 1:
        sys.exit(EXIT_ERROR)

    procId = args[0]

    try:
        procId = int(procId)
    except Exception:
        sys.exit(EXIT_ERROR)

    exit_code = EXIT_ERROR
    try:
        exit_code = WatchProcess(procId, bIOWatch)
    except Exception:
        print >> sys.stderr, "Exception in App Watcher module!!!"
        traceback.print_exc()

    sys.exit(exit_code)

"""
CHANGE LOG:
-----------
$Log: app_watcher.py  $
Revision 1.1 2021/12/13 17:57:08CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/app/project.pj
Revision 1.10 2013/10/30 10:09:32CET Hecker, Robert (heckerr) 
Removed unecessary print output to console.
- Added comments -  heckerr [Oct 30, 2013 10:09:32 AM CET]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.9 2013/09/17 14:40:10CEST Hecker, Robert (heckerr) 
updated imports
--- Added comments ---  heckerr [Sep 17, 2013 2:40:11 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.8 2013/09/12 14:23:11CEST Hecker, Robert (heckerr) 
Some updates regarding pep8.
--- Added comments ---  heckerr [Sep 12, 2013 2:23:11 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.7 2013/02/07 17:16:13CET Hecker, Robert (heckerr)
Removed unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:16:13 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/01/22 17:46:30CET Hecker, Robert (heckerr)
Modified IPC Communication from socket to pipe.
--- Added comments ---  heckerr [Jan 22, 2013 5:46:30 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2012/12/12 10:37:23CET Hecker, Robert (heckerr)
Updated Code regarding pep8.
--- Added comments ---  heckerr [Dec 12, 2012 10:37:23 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/11 14:16:10CET Hecker, Robert (heckerr)
Get OracleMasterDB support working.
--- Added comments ---  heckerr [Dec 11, 2012 2:16:13 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/10 16:40:01CET Hecker, Robert (heckerr)
- Moved some Functionality to AppMonitor.
- Added Communication with AppMonitor.
--- Added comments ---  heckerr [Dec 10, 2012 4:40:04 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:50CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:50 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:46:31CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
