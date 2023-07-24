"""
master_db_com.py
----------------

Interface File uses to access the oracle database and submit the job.

:org:           science + computing ag
:author:        Jimmy Selatsa

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:36CET $
"""
# Import Python Modules -------------------------------------------------------

# Import STK Modules ----------------------------------------------------------
from cxoracle_ifc import ICXOracle

# Import Local Python Modules -------------------------------------------------

def CreateXmlJobStatus(job, tasks, username):
    """
    Create a *.xml string which describes the complete
    job.

    :param job:     the current job object
    :type job:      object of type `Job`
    :param tasks:   list of all tasks in the job
    :type tasks:    list of `Task` objects
    :return:        xmlstring
    """
    sb = []

    sb.append("<?xml version='1.0'?>")

    sb.append("<jobstatus>")
    sb.append("<joblist>")
    sb.append("<job>")

    sb.append("<hpcjob_id>")
    sb.append(str(job.Id))
    sb.append("</hpcjob_id>")
    sb.append("<hpcjob_status>")
    sb.append(str(job.State))
    sb.append("</hpcjob_status>")
    sb.append("<hpcjob_priority>")
    sb.append(str(job.Priority))
    sb.append("</hpcjob_priority>")
    sb.append("<hpcjob_type>")
    sb.append(str(job.UnitType))
    sb.append("</hpcjob_type>")

    sb.append("<hpcjob_user>")
    sb.append(username)
    sb.append("</hpcjob_user>")

    sb.append("<hpcjob_project>")
    sb.append(str(job.Project))

    sb.append("</hpcjob_project>")
    sb.append("</job>")
    sb.append("</joblist>")
    sb.append("<tasklist>")

    for task in tasks:
        sb.append("<task>")
        sb.append("<task_id name='id'>")
        sb.append(str(task.TaskId))
        sb.append("</task_id>")

        sb.append("<task_name name='name'>")
        sb.append(str(task.Name))
        sb.append("</task_name>")

        sb.append("<task_type name='type'>")
        sb.append(str(task.Type))
        sb.append("</task_type>")

        sb.append("<task_status name='status'>")
        sb.append(str(task.State))
        sb.append("</task_status>")

        sb.append("<task_cmdline name='cmdline'>")
        sb.append(str(task.CommandLine))
        sb.append("</task_cmdline>")

        sb.append("</task>")
    sb.append("</tasklist>")
    sb.append("</jobstatus>")

    jobXML = ''.join(sb)

    return jobXML


def CreateXmlTaskReport(node, jobname, taskname, sensor):
    """
    Create a *.xml string which contains the complete report of one
    tasks which runs on one node, at this time.

    Function will typicaly used for report in a given interval.

    :param node:     the current Node object
    :type node:      object of type `Node`
    :param jobname:  Name of the job
    :type jobname:   string
    :param taskname: Name of the task
    :type tasklname: string
    :param sensor:   all collected sensor informations.
    :type sensor:    object of type Sensor.
    :return:        xmlstring
    """
    sb = []

    sb.append("<?xml version='1.0'?>")

    sb.append("<taskstatus>")

    sb.append("<node_pid>")
    sb.append(str(node.GetPID()))
    sb.append("</node_pid>")

    sb.append("<node_name>")
    sb.append(str(node.GetName()))
    sb.append("</node_name>")

    sb.append("<node_ip>")
    sb.append(str(node.GetIP()))
    sb.append("</node_ip>")

    sb.append("<job_name>")
    sb.append(str(jobname))
    sb.append("</job_name>")

    sb.append("<task_name>")
    sb.append(str(taskname))
    sb.append("</task_name>")

    sb.append("<command_line>")
    sb.append(str("cmdLine"))
    sb.append("</command_line>")

    sb.append("<sensorlist>")

    sb.append("<sensor name='cpu'>")
    sb.append("<sensor_result name='cpu_load'>")
    sb.append(str(sensor.GetCPU()))
    sb.append("</sensor_result>")
    sb.append("</sensor>")

    sb.append("<sensor name='io'>")
    sb.append("<sensor_result name='io_traffic'>")
    sb.append(str(sensor.GetIOTraffic()))
    sb.append("</sensor_result>")
    sb.append("</sensor>")

    sb.append("<sensor name='duration'>")
    sb.append("<sensor_result name='runtime'>")
    sb.append(str(sensor.GetDuration()))
    sb.append("</sensor_result>")
    sb.append("</sensor>")

    sb.append("</sensorlist>")

    sb.append("</taskstatus>")

    taskReportXML = ''.join(sb)

    return taskReportXML


class NodeData(object):

    def __init__(self):
        self.Name = ""
        self.PID = ""
        self.IP = ""

    def SetName(self, Name):
        self.Name = Name

    def GetName(self):
        return self.Name

    def GetPID(self):
        return self.PID

    def SetPID(self, PID):
        self.PID = PID

    def GetIP(self):
        return self.IP

    def SetIP(self, IP):
        self.IP = IP


class SensorData(object):

    def __init__(self):
        self.CPU = ""
        self.IOTraffic = ""
        self.InputFile = ""
        self.OutputFile = ""
        self.LogFile = ""
        self.Duration = ""

    def GetCPU(self):
        return self.CPU

    def SetCPU(self, CPU):
        self.CPU = CPU

    def GetIOTraffic(self):
        return self.IOTraffic

    def SetIOTraffic(self, IOTraffic):
        self.IOTraffic = IOTraffic

    def GetInputFile(self):
        return self.InputFile

    def SetInputFile(self, InputFile):
        self.InputFile = InputFile

    def GetOutputFile(self):
        return self.OutputFile

    def SetOutputFile(self, OutputFile):
        self.OutputFile = OutputFile

    def GetLogFile(self):
        return self.LogFile

    def SetLogFile(self, LogFile):
        self.LogFile = LogFile

    def GetDuration(self):
        return self.Duration

    def SetDuration(self, Duration):
        self.Duration = Duration


class MasterDBCom(ICXOracle):

    def __init__(self):

        ICXOracle.__init__(self)

    def submitJob(self, job, tasks, username):

        # Create XML Mapping for Job
        jobstatus = CreateXmlJobStatus(job, tasks, username)

        priority = ICXOracle.submitJob(self, jobstatus)

        return priority

    def setTaskState(self, JobName, TaskName, TaskStatus):
        """
        Set the actual Task State inside the Oracle DB.

        :param JobName: Name of the Job
        :type  JobName: string
        :param TaskName: Name of the Task
        :type  TaskName: string
        :param TaskStatus: CommandLine used for starting the application.
        :type  TaskStatus: int (Value of the TaskState object)
        :return: ??
        """

        result = ICXOracle.setTaskState(self, JobName, TaskName, TaskStatus)
        return result

    def updateTask(self, node, JobName, TaskName, sensor):
        """
        Update the Task Information in the Oracle DB.

        :param node: collected Node Data.
        :type  node: NodeData object
        :param JobName: Name of the Job
        :type  JobName: string
        :param TaskName: Name of the Task
        :type  TaskName: string
        :param sensor: collection of Sensor Data
        :type  sensor: SensorData object
        :todo: Remove static Data in parameters from this Method.
               Performance Improvement !
        """
        # Create XML Report
        XmlTaskReport = CreateXmlTaskReport(node, JobName, TaskName, sensor)

        result = ICXOracle.updateTask(self, XmlTaskReport)

        return result

"""
CHANGE LOG:
-----------
$Log: master_db_com.py  $
Revision 1.1 2021/12/13 17:57:36CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/masterdb/project.pj
Revision 1.8 2013/09/17 16:16:01CEST Hecker, Robert (heckerr) 
Adapted Interface to S&C delivery.
- Added comments -  heckerr [Sep 17, 2013 4:16:01 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.7 2013/09/11 16:25:45CEST Hecker, Robert (heckerr)
Removed dependency to xmlmapper.py
--- Added comments ---  heckerr [Sep 11, 2013 4:25:46 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.6 2013/04/17 11:54:58CEST Hecker, Robert (heckerr)
Udded epydoc doku.
--- Added comments ---  heckerr [Apr 17, 2013 11:54:58 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.5 2013/02/07 17:17:42CET Hecker, Robert (heckerr)
Removed unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:17:42 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/14 16:22:45CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:45 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/10 16:48:43CET Hecker, Robert (heckerr)
Adapted Code to oracle_ifc
--- Added comments ---  heckerr [Dec 10, 2012 4:48:44 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:51CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:51 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:51:49CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
