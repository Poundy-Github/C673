"""
stk.hpc.job_sim
---------------

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

# Import STK Modules ----------------------------------------------------------
from . task_sim import Task
from . hpc_defs import JobPriority
from . hpc_defs import JobUnitType

# Import Local Python Modules -------------------------------------------------

# Classes ---------------------------------------------------------------------


class Job(object):
    """
    Class, which reflects the whole functionality of
    the ISchedulerJob Interface from Microsoft HPC.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.ischedulerjob(v=vs.85)

    :author:        Robert Hecker
    :date:          16.04.2012
    """

    def __init__(self, scheduler, hpc_job=None):

        self.hpc_job = hpc_job
        self.scheduler = scheduler

        # Read/Write Properties
        self.Name = ''
        self.ExpandedPriority = JobPriority.Normal
        self.Priority = JobPriority.Normal
        self.Project = ''
        self.UnitType = JobUnitType.Core
        self.MaximumNumberOfNodes = 1
        self.MinimumNumberOfNodes = 1
        self.MaximumNumberOfSockets = 1
        self.MinimumNumberOfSockets = 1
        self.MaximumNumberOfCores = 1
        self.MinimumNumberOfCores = 1
        self.IsExclusive = False
# #        self.TargetResourceCount = 0
        self.AutoCalculateMax = True
        self.AutoCalculateMin = True
        self.NodeGroups = []
        self.RequestedNodes = []

        # Read Only Properties
        self.Id = 1
        self.State = 0
        self.JobTemplate = ''
        self.HoldUntil = 0

        # Sim Properties
        self.Tasklist = []

    def Commit(self):
        self.hpc_job.Commit()

    def CreateTask(self):
        idx = len(self.Tasklist) + 1
        task = Task(self.scheduler, idx)
        return task

    def AddTask(self, task):
        self.Tasklist.append(task)

    def OpenTask(self, TaskId):
        Id = self.scheduler.CreateTaskId(TaskId)
        task = Task(self.scheduler, self.hpc_job.OpenTask(Id))
        return task

    def Refresh(self):
        self.hpc_job.Refresh()

    def SetJobTemplate(self, JobTemplateName):
        # self.hpc_job.SetJobTemplate(JobTemplateName)
        pass

# #    def SetHoldUntil(self, value):
# #        self.hpc_job.SetHoldUntil(value)
# #        return

    def ClearHold(self):
        self.hpc_job.ClearHold()

    def GetJob(self):
        return self.hpc_job

    def AddExcludedNodes(self, NodeList):
        collection = self.scheduler.CreateStringCollection()

        for el in NodeList:
            collection.Add(el)

        self.hpc_job.AddExcludedNodes(collection)

    def ClearExcludedNodes(self):
        self.hpc_job.ClearExcludedNodes()

    def SetCustomProperty(self, name, value):
        self.hpc_job.SetCustomProperty(name, value)

    def GetCustomProperties(self):
        dict = {}
        props = self.hpc_job.GetCustomProperties()

        for i in props:
            dict[i.Name] = i.Value

        return dict

    def GetTaskList(self, filter=None, sort=None, expandParametric=False):

        tasks = []

        if(filter is None):
            filter = self.scheduler.CreateFilterCollection()

        if(sort is None):
            sort = self.scheduler.CreateSortCollection()

        for hpc_task in self.hpc_job.GetTaskList(filter, sort, True):
            task = Task(self.scheduler, hpc_task)
            tasks.append(task)

        return tasks

"""
CHANGE LOG:
-----------
$Log: job_sim.py  $
Revision 1.1 2021/12/13 17:57:15CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/hpc/project.pj
Revision 1.2 2013/09/17 15:58:24CEST Hecker, Robert (heckerr) 
changed imports.
- Added comments -  heckerr [Sep 17, 2013 3:58:24 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.1 2013/05/16 08:06:04CEST Hecker, Robert (heckerr) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
