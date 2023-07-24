"""
app_monitor.py
--------------

Script used by app_starter.py to collect monitor signals and send them
to the App Watcher and the Oracle DB.

Arguments:
 - process id of the process which should be monitored

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:08CET $
"""

# Import packages ------------------------------------------------------------
import os
import sys
import time
import traceback
from optparse import OptionParser
import socket
import wmi


# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------
PyLibFolder = os.getcwd()

if PyLibFolder not in sys.path:
    sys.path.append(PyLibFolder)

# Import Local Python Modules -----------------------------------------------------------------------------------------
from stk.hpc.ifc.masterdb import master_db_com
import stk.hpc.app.monitor_ipc as monitor_ipc

FAIL_THRESHOLD = 5  # amount of tolerated wmi request fails in a row
EXIT_ERROR = -10  # exit code if internal error occured
EXIT_PID_INVALID = -11

REPORT_WAIT_TIME_CYCLE = 60  # time to wait between to requests in [s]
REPORT_WAIT_TIME_INITIAL = 10  # Initial Wait Time for 1. Report in [s]

TASK_STATE_RUNNING = 32
TASK_STATE_FINISHED = 128


class MonitorData(object):
    """
    Class which works as container for the monitored data of a process

    :author:        Robert Hecker
    :date:          12.09.2013
    """
    def __init__(self):
        self.values = {}
        self.values['CPULoad'] = 0
        self.values['IOLoad'] = 0

    def SetCPULoad(self, value):
        """
        Set the current cpuload into the internal storage.

        :param  value:   cpuload in %
        :type value: string
        """
        self.values['CPULoad'] = value

    def SetIOLoad(self, value):
        """
        Set the current ioload into the internal storage

        :param  value:   ioload kb/sec
        :type value: string
        """
        self.values['IOLoad'] = value

    def GetData(self):
        """
        Get the whole dictionary with the internal stored data.

        :return:   internal dict with all stored data.
        :rtype:    dict
        """
        return self.values


class MonitorDataCollector(object):
    """
    Class which provide all needed moitor values from an process.

    :author:        Robert Hecker
    :date:          12.09.2013
    """
    def __init__(self, proc_id):

        self.fail_count = 0
        self.val1 = self.__RequestProcessStats(proc_id)
        self.collection = MonitorData()

    def GetMonitorValues(self, proc_id):
        """
        Get the whole dictionary with the internal stored data.

        :param poc_id:    The process id, which must be monitored.
        :type proc_id:    integer

        :return:          monitored data.
        :rtype:           dict
        """
        try:
            val2 = self.__RequestProcessStats(proc_id)
        except:
            raise RuntimeWarning('Process is not available')

        if val2 is None:
            self.fail_count += 1
            if self.fail_count > FAIL_THRESHOLD:
                tmp = "App Watcher: Process stat request failed more then "
                tmp += "%d times in a row!!!" % FAIL_THRESHOLD
                print >> sys.stderr, tmp
                return EXIT_ERROR
        else:
            self.fail_count = 0
            # load times are in 100ns ticks -> conversion to seconds
            tmp = (val2['KernelModeTime'] - self.val1['KernelModeTime'])
            kernel_diff_time = tmp / float(10 ** 7)
            tmp = (val2['UserModeTime'] - self.val1['UserModeTime'])
            user_diff_time = tmp / float(10 ** 7)
            tmp = val2['ReadTransferCount'] + val2['WriteTransferCount']
            tmp -= (self.val1['ReadTransferCount'] +
                    self.val1['WriteTransferCount'])
            io_kbytes = tmp / 1024.0
            deltat = val2['time'] - self.val1['time']

            self.val1 = val2

            # percentage from 1s
            kernel_load = kernel_diff_time * 100.0 / deltat
            user_load = user_diff_time * 100.0 / deltat
            # i/o traffic in [kb/s]
            io_load = io_kbytes / deltat

            # CPU load can be greater then 100% due to multi core usage
            # but this is not of interest to us
            cpu_load = kernel_load + user_load

            # Update Monitored Values
            self.collection.SetCPULoad(cpu_load)
            self.collection.SetIOLoad(io_load)

        return self.collection.GetData()

    def __RequestProcessStats(self, proc_id):
        """
        Get the Current Process States from a given proc_id.

        :param poc_id:    The process id, which must be monitored.
        :type proc_id:    integer

        :return:          Process States.
        :rtype:           dict
        """
        result = {}

        wmi_ifc = wmi.WMI('.', namespace="cimv2")

        result['UserModeTime'] = 0
        result['KernelModeTime'] = 0
        result['ReadOperationCount'] = 0
        result['ReadTransferCount'] = 0
        result['WriteOperationCount'] = 0
        result['WriteTransferCount'] = 0

        # get process stats for all processes
        processes = wmi_ifc.query("SELECT * FROM Win32_Process")
        result['time'] = int(time.time())

        if len(processes) != 0:
            subprocesses = {}
            for process in processes:
                pid = process.ProcessId
                parent = process.ParentProcessId
                subprocesses.setdefault(parent, []).append(pid)
                subprocesses.setdefault(pid, [])

            # collect all processes belonging to the tree
            processes_in_tree = [proc_id]
            parent_processes = [proc_id]
            while parent_processes:
                current_pid = parent_processes.pop()
                subps = subprocesses[current_pid]
                parent_processes.extend(subps)
                processes_in_tree.extend(subps)

            # add up performance values for processes in tree
            for process in processes:
                if process.ProcessId in processes_in_tree:
                    result['UserModeTime'] += int(process.UserModeTime)
                    result['KernelModeTime'] += int(process.KernelModeTime)
                    result['ReadOperationCount'] += int(process.ReadOperationCount)
                    result['ReadTransferCount'] += int(process.ReadTransferCount)
                    result['WriteOperationCount'] += int(process.WriteOperationCount)
                    result['WriteTransferCount'] += int(process.WriteTransferCount)
        else:
            result = None

        return result


class DBReporter(object):
    """
    Class which works as Oracle DB Reporter and send all needed Data
    towards the Database in a xml format.

    :author:        Robert Hecker
    :date:          12.09.2013
    """
    def __init__(self):
        self.starttime = time.time()
        self.node = master_db_com.NodeData()
        self.sensor = master_db_com.SensorData()
        self.com = master_db_com.MasterDBCom()

    def __UpdateNodeData(self, proc_id):
        """
        Update all node related data

        :param poc_id:    The process id, which must be monitored.
        :type proc_id:    integer

        :return:          -
        """
        self.node.SetPID(proc_id)
        self.node.SetName(socket.gethostname())
        self.node.SetIP(socket.gethostbyname(socket.gethostname()))

    def __UpdateSensorData(self, mondata):
        """
        Update all sensor related data

        :param mondata:   all monitored data.
        :type mondata:    dict

        :return:          -
        """
        # Update whole Monitor Information
        # Current Time
        currentTime = time.time()

        duration = currentTime - self.starttime
        self.sensor.SetDuration(duration)
        self.sensor.SetCPU(mondata['CPULoad'])
        self.sensor.SetIOTraffic(mondata['IOLoad'])

    def SendNodeReport(self, jobname, taskname, proc_id):
        """
        Converts all parameter into a xml report, and send
        the node report towards the Oracle Database.

        :param jobname:   Name of the job
        :type jobname:    string
        :param taskname:  Name of the task
        :type taskname:   string
        :param proc_id:   Unique process id
        :type proc_id:    integer

        :return:          -
        """
        # Initialize Node Information
        self.__UpdateNodeData(proc_id)

        # Set TaskStatus in the Database
        self.com.setTaskState(jobname, taskname, TASK_STATE_RUNNING)

        # Update task in the Database
        ret = self.com.updateTask(self.node, jobname, taskname, self.sensor)
        if(ret == -1):
            # Terminate Process needed
            pass

    def SendTaskReport(self, jobname, taskname, mondata):
        """
        Converts all parameter into a xml report, and send
        the task report towards the Oracle Database.

        :param jobname:   Name of the job
        :type jobname:    string
        :param taskname:  Name of the task
        :type taskname:   string
        :param mondata:   monitored data
        :type mondata:    dict

        :return:          -

        :todo:            when update task returns -1 a process termination is required.
        """
        # Update whole Monitor Information
        self.__UpdateSensorData(mondata)

        # Set TaskStatus in the Database
        self.com.setTaskState(jobname, taskname, TASK_STATE_RUNNING)

        # Update task in the Database
        ret = self.com.updateTask(self.node, jobname, taskname, self.sensor)
        if(ret == -1):
            # Terminate Process needed
            pass


def MonitorProcess(proc_id, jobname, taskname, use_db_reporter, use_app_watch):
    """
    Main function, which does the monitoring of the given process in a loop with
    a given interval.

    :param proc_id:          Windows process id, which must be monitored.
    :type proc_id:           integer
    :param jobname:          Name of the job
    :type jobname:           string
    :param taskname:         Name of the task
    :type taskname:          string
    :param use_db_reporter:  Usage of DBReporter (yes/no)
    :type use_db_reporter:   boolean
    :param use_app_watch:    Usage of AppWatcher (yes/no)
    :type use_app_watch:     boolean

    :return:                 -
    """
    print "AppMonitor: Started"
    monitor = MonitorDataCollector(proc_id)

    if(use_app_watch):
        monclient = monitor_ipc.MonitorClient(str(proc_id))

    if(use_db_reporter):
        reporter = DBReporter()

    # Wait the initial Time to collect the first Monitor Dataset
    time.sleep(REPORT_WAIT_TIME_INITIAL)

    # Collect the Monitor Values
    mondata = monitor.GetMonitorValues(proc_id)

    if(use_db_reporter):
        # Send the First Report to Database
        reporter.SendNodeReport(jobname, taskname, proc_id)
        reporter.SendTaskReport(jobname, taskname, mondata)

    while(True):

        # Wait a specific Time frame
        time.sleep(REPORT_WAIT_TIME_CYCLE)
        # Get new Values
        mondata = monitor.GetMonitorValues(proc_id)

        if(use_db_reporter):
            # Send Data to DB
            reporter.SendTaskReport(jobname, taskname, mondata)

        if(use_app_watch):
            # Send Data to App Watcher
            monclient.Send(mondata)

    if(use_app_watch):
        # Close Connection
        monclient.Close()

    # RH Todo which State must be given here !!!!
    reporter.com.setTaskState(jobname, taskname, TASK_STATE_FINISHED)

    return 0

if __name__ == "__main__":

    PARSER = OptionParser()

    PARSER.add_option("-p",
                      type=int,
                      dest="ProcId",
                      default=0,
                      action="store",
                      help="Set ProcessID to Monitor")
    PARSER.add_option("-j",
                      type=str,
                      dest="JobName",
                      default="",
                      action="store",
                      help="JobName")
    PARSER.add_option("-t",
                      type=str,
                      dest="TaskName",
                      default="",
                      action="store",
                      help="TaskName")
    PARSER.add_option("-r",
                      dest="DBReport",
                      default=False,
                      action="store_true",
                      help="Use DB-Reporting.")
    PARSER.add_option("-w",
                      dest="AppWatch",
                      default=False,
                      action="store_true",
                      help="Send Data to App Watcher")

    OP = PARSER.parse_args()[0]

    exit_code = EXIT_ERROR
    try:
        exit_code = MonitorProcess(OP.ProcId, OP.JobName, OP.TaskName, OP.DBReport, OP.AppWatch)
    except RuntimeWarning:
        exit_code = EXIT_PID_INVALID
    except Exception:
        print >> sys.stderr, "Exception in App Monitor module!!!"
        traceback.print_exc()

    sys.exit(exit_code)

"""
CHANGE LOG:
-----------
$Log: app_monitor.py  $
Revision 1.1 2021/12/13 17:57:08CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/app/project.pj
Revision 1.15 2013/10/30 10:09:31CET Hecker, Robert (heckerr) 
Removed unecessary print output to console.
- Added comments -  heckerr [Oct 30, 2013 10:09:31 AM CET]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.14 2013/09/25 13:41:35CEST Hecker, Robert (heckerr) 
Updated app_monitor regarding the new MasterOracleDB Interface.
--- Added comments ---  heckerr [Sep 25, 2013 1:41:35 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.13 2013/09/17 14:40:09CEST Hecker, Robert (heckerr)
updated imports
--- Added comments ---  heckerr [Sep 17, 2013 2:40:10 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.12 2013/09/12 14:14:18CEST Hecker, Robert (heckerr)
Removed trailing whitespaces.
--- Added comments ---  heckerr [Sep 12, 2013 2:14:18 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.11 2013/09/12 13:37:54CEST Hecker, Robert (heckerr)
updates regarding pylint and adaption to new S&C Interface.
--- Added comments ---  heckerr [Sep 12, 2013 1:37:54 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.10 2013/07/04 17:26:34CEST Hecker, Robert (heckerr)
Removed some pep8 Violations.
--- Added comments ---  heckerr [Jul 4, 2013 5:26:34 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/04/17 11:55:43CEST Hecker, Robert (heckerr)
Updated Appwatcher regarding  Oracle DB submit functions.
--- Added comments ---  heckerr [Apr 17, 2013 11:55:43 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.8 2013/04/02 10:24:54CEST Mertens, Sven (uidv7805)
pylint: E0213, E1123, E9900, E9904, E1003, E9905, E1103
--- Added comments ---  uidv7805 [Apr 2, 2013 10:24:55 AM CEST]
Change Package : 176171:9 http://mks-psad:7002/im/viewissue?selection=176171
Revision 1.7 2013/03/28 14:43:08CET Mertens, Sven (uidv7805)
pylint: resolving some R0904, R0913, R0914, W0107
Revision 1.6 2013/02/07 17:15:03CET Hecker, Robert (heckerr)
Removed unused Code, BugFix in Assignments.
--- Added comments ---  heckerr [Feb 7, 2013 5:15:03 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/01/22 17:46:30CET Hecker, Robert (heckerr)
Modified IPC Communication from socket to pipe.
--- Added comments ---  heckerr [Jan 22, 2013 5:46:30 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/14 16:22:47CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:47 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/12 10:37:21CET Hecker, Robert (heckerr)
Updated Code regarding pep8.
--- Added comments ---  heckerr [Dec 12, 2012 10:37:21 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/11 14:14:46CET Hecker, Robert (heckerr)
Get OracleMasterDB working.
--- Added comments ---  heckerr [Dec 11, 2012 2:14:47 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/10 16:37:56CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
