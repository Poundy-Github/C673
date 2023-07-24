"""
stk.hpc.scheduler_sim
---------------------

Virtual job class, needed to make a dry run to create a complete running job on
the local pc under d:\data\1_JobName.

This class is used for job creation simulation without hpc.

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:15CET $
"""
# Import Python Modules -------------------------------------------------------
import win32com.client

# Import STK Modules ----------------------------------------------------------
from job_sim import Job

# Classes ---------------------------------------------------------------------


class SchedulerSim(object):
    """
    Class, which reflects the whole functionality of
    the IScheduler Interface from Microsoft HPC.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.ischeduler(v=vs.85)

    :author:        Robert Hecker
    :date:          16.04.2012
    """

    def __init__(self, HeadNode="LISS006.CW01.CONTIWAN.COM"):
        # Create Microsoft HPC Session
        tmp = "Microsoft.Hpc.Scheduler.Scheduler"
        # self.hpc_scheduler = win32com.client.dynamic.Dispatch(tmp)

        # Conncet to our Default Server
        # self.hpc_scheduler.Connect(HeadNode)

    def OpenJob(self, id):
        hpc_job = self.hpc_scheduler.OpenJob(id)
        job = Job(self)
        job.hpc_job = hpc_job
        return job

    def CreateJob(self):
        job = Job(self)
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
        # self.hpc_scheduler.AddJob(job.GetJob())
        pass

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
$Log: scheduler_sim.py  $
Revision 1.1 2021/12/13 17:57:15CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/hpc/project.pj
Revision 1.2 2013/09/17 15:58:56CEST Hecker, Robert (heckerr) 
changed comments.
- Added comments -  heckerr [Sep 17, 2013 3:58:56 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.1 2013/05/16 08:06:05CEST Hecker, Robert (heckerr) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
