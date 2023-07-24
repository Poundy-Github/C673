"""
scheduler
---------

Interface File to be able to access the scheduler interface from
Microsoft HPC inside Python. This Module exactly reflects all scheduler
interfaces from HPC into Python.
No other high level Functions should be included here.

The module gives no garantee, that the whole interface is reflected,
so that missing classes, methods or functions related to the scheduler
interface can be added.

Available Interfaces
====================

    - `Scheduler`

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:15CET $
"""
# Import Python Modules -------------------------------------------------------
import win32com.client

# Import STK Modules ----------------------------------------------------------
from job import Job

# Classes ---------------------------------------------------------------------


class Scheduler(object):
    """
    Class, which reflects the whole functionality of
    the IScheduler Interface from Microsoft HPC.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.ischeduler(v=vs.85)

    :author:        Robert Hecker
    :date:          16.04.2012
    """

    def __init__(self, HeadNode):
        # Create Microsoft HPC Session
        tmp = "Microsoft.Hpc.Scheduler.Scheduler"
        self.hpc_scheduler = win32com.client.dynamic.Dispatch(tmp)

        # Connect to our Default Server
        self.hpc_scheduler.Connect(HeadNode)

    def OpenJob(self, id):
        hpc_job = self.hpc_scheduler.OpenJob(id)
        job = Job(self)
        job.hpc_job = hpc_job
        return job

    def CreateJob(self):
        job = Job(self, self.hpc_scheduler.CreateJob())
        return job

    def CreateTaskId(self, TaskId):
        """
        Creates a task identifier that identifies a task.
        See http://msdn.microsoft.com/en-us/library/
        microsoft.hpc.scheduler.ischeduler.createtaskid(v=vs.85).aspx

        :author:        Robert Hecker
        :date:          25.09.2012
        """
        return self.hpc_scheduler.CreateTaskId(TaskId)

    def AddJob(self, job):
        self.hpc_scheduler.AddJob(job.GetJob())

    def SubmitJob(self, Job, UserName, UserPassword=''):
        self.hpc_scheduler.SubmitJob(Job.hpc_job, UserName, UserPassword)

    def CreateStringCollection(self):
        return self.hpc_scheduler.CreateStringCollection()

    def SubmitJobById(self, Id, UserName, UserPassword=''):
        self.hpc_scheduler.SubmitJobById(Id, UserName, UserPassword)

    def CancelJob(self, JobId, Message):
        self.hpc_scheduler.CancelJob(JobId, Message)

    def GetJobList(self, filter=None, sort=None):
        return self.hpc_scheduler.GetJobList(filter, sort)

    def GetNodeList(self, filter=None, sort=None):
        return self.hpc_scheduler.GetNodeList(filter, sort)

    def ConfigureJob(self, JobId):
        self.hpc_scheduler.ConfigureJob(JobId)

    def CreateFilterCollection(self):
        return self.hpc_scheduler.CreateFilterCollection()

    def CreateSortCollection(self):
        return self.hpc_scheduler.CreateSortCollection()

"""
CHANGE LOG:
-----------
$Log: scheduler.py  $
Revision 1.1 2021/12/13 17:57:15CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/hpc/project.pj
Revision 1.5 2013/06/27 16:34:00CEST Hecker, Robert (heckerr) 
Removed default HeadNodeName
- Added comments -  heckerr [Jun 27, 2013 4:34:00 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.4 2013/02/07 17:11:52CET Hecker, Robert (heckerr) 
Removed unused Code.
--- Added comments ---  heckerr [Feb 7, 2013 5:11:52 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/14 16:22:45CET Hecker, Robert (heckerr) 
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:45 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:52CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:52 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:36:18CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
