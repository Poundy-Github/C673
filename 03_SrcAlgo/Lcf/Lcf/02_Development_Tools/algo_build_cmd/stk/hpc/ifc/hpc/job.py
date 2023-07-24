"""
job
---

Accessing the Microsoft HPC over COM Interface

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:15CET $
"""
# Pylint Module wide settings -----------------------------------------------------------------------------------------

# Using same Variable Names as in the COM-Interface from Microsoft Hpc
# pylint: disable=C0103

# Import Python Modules -----------------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------
from . task import Task
from . hpc_defs import JobPriority
from . hpc_defs import JobUnitType

# Import Local Python Modules -----------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


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
        self.NotifyOnCompletion = False
        self.NotifyOnStart = False

        # Read Only Properties
        self.Id = 0
        self.State = 0
        self.JobTemplate = ''
        self.HoldUntil = 0

    def __setattr__(self, name, value):

        try:
            if(name == 'Name'):
                self.hpc_job.Name = value

            if(name == 'ExpandedPriority'):
                self.hpc_job.ExpandedPriority = value

            if(name == 'NotifyOnStart'):
                self.hpc_job.NotifyOnStart = value

            if(name == 'NotifyOnCompletion'):
                self.hpc_job.NotifyOnCompletion = value

            if(name == 'Priority'):
                self.hpc_job.Priority = value

            if(name == 'Project'):
                self.hpc_job.Project = value

            if(name == 'UnitType'):
                self.hpc_job.UnitType = value

            if(name == 'MaximumNumberOfCores'):
                self.hpc_job.MaximumNumberOfCores = value

            if(name == 'MaximumNumberOfNodes'):
                self.hpc_job.MaximumNumberOfNodes = value

            if(name == 'MaximumNumberOfSockets'):
                self.hpc_job.MaximumNumberOfSockets = value

            if(name == 'MinimumNumberOfCores'):
                self.hpc_job.MinimumNumberOfCores = value

            if(name == 'MinimumNumberOfNodes'):
                self.hpc_job.MinimumNumberOfNodes = value

            if(name == 'MinimumNumberOfSockets'):
                self.hpc_job.MinimumNumberOfSockets = value

            if(name == 'IsExclusive'):
                self.hpc_job.IsExclusive = value

            if(name == 'Id'):
                AttributeError('Id')

            if(name == 'State'):
                AttributeError('State')

            if(name == 'JobTemplate'):
                AttributeError('JobTemplate')

# #            if(name == 'TargetResourceCount'):
# #                self.hpc_job.TargetResourceCount = value

            if(name == 'AutoCalculateMax'):
                self.hpc_job.AutoCalculateMax = value

            if(name == 'AutoCalculateMin'):
                self.hpc_job.AutoCalculateMin = value

            if(name == 'HoldUntil'):
                AttributeError('HoldUntil')

            if(name == 'NodeGroups'):
                # Convert from Python List to String Collection
                Groups = self.scheduler.CreateStringCollection()
                for i in value:
                    Groups.Add(i)

                self.hpc_job.NodeGroups = Groups

            if(name == 'RequestedNodes'):
                # Convert from Python List to String Collection
                Nodes = self.scheduler.CreateStringCollection()
                for i in value:
                    Nodes.Add(i)

                self.hpc_job.RequestedNodes = Nodes
        except:
            pass

        self.__dict__[name] = value

    def __getattribute__(self, name):

        try:
            if(name == 'Name'):
                self.Name = self.hpc_job.Name

            if(name == 'ExpandedPriority'):
                self.ExpandedPriority = self.hpc_job.ExpandedPriority

            if(name == 'NotifyOnStart'):
                self.NotifyOnStart = self.hpc_job.NotifyOnStart

            if(name == 'NotifyOnCompletion'):
                self.NotifyOnCompletion = self.hpc_job.NotifyOnCompletion

            if(name == 'Priority'):
                self.Priority = self.hpc_job.Priority

            if(name == 'Project'):
                self.Project = self.hpc_job.Project

            if(name == 'UnitType'):
                self.UnitType = self.hpc_job.UnitType

            if(name == 'MaximumNumberOfCores'):
                self.MaximumNumberOfCores = self.hpc_job.MaximumNumberOfCores

            if(name == 'MaximumNumberOfNodes'):
                self.MaximumNumberOfNodes = self.hpc_job.MaximumNumberOfNodes

            if(name == 'MaximumNumberOfSockets'):
                tmp = self.hpc_job.MaximumNumberOfSockets
                self.MaximumNumberOfSockets = tmp

            if(name == 'MinimumNumberOfCores'):
                tmp = self.hpc_job.MinimumNumberOfCores
                self.MinimumNumberOfCores = tmp

            if(name == 'MinimumNumberOfNodes'):
                self.MinimumNumberOfNodes = self.hpc_job.MinimumNumberOfNodes

            if(name == 'MinimumNumberOfSockets'):
                tmp = self.hpc_job.MinimumNumberOfSockets
                self.MinimumNumberOfSockets = tmp

            if(name == 'IsExclusive'):
                self.IsExclusive = self.hpc_job.IsExclusive

            if(name == 'Id'):
                self.Id = self.hpc_job.Id

            if(name == 'State'):
                self.State = self.hpc_job.State

            if(name == 'JobTemplate'):
                self.JobTemplate = self.hpc_job.JobTemplate

# #            if(name == 'TargetResourceCount'):
# #                self.TargetResourceCount = self.hpc_job.TargetResourceCount

            if(name == 'AutoCalculateMax'):
                self.AutoCalculateMax = self.hpc_job.AutoCalculateMax

            if(name == 'AutoCalculateMin'):
                self.AutoCalculateMin = self.hpc_job.AutoCalculateMin

            if(name == 'HoldUntil'):
                self.HoldUntil = self.hpc_job.HoldUntil

            if(name == 'NodeGroups'):
                Groups = []

                for i in range(self.hpc_job.NodeGroups.Count):
                    Groups.append(self.hpc_job.NodeGroups.Item(i))

                self.NodeGroups = Groups

            if(name == 'RequestedNodes'):
                Nodes = []

                for i in range(self.hpc_job.RequestedNodes.Count):
                    Nodes.append(self.hpc_job.RequestedNodes.Item(i))

                self.RequestedNodes = Nodes

        except:
            pass

        # Default behaviour
        return object.__getattribute__(self, name)

    def Commit(self):
        self.hpc_job.Commit()

    def CreateTask(self):
        task = Task(self.scheduler, self.hpc_job.CreateTask())
        return task

    def AddTask(self, task):
        self.hpc_job.AddTask(task.hpc_task)

    def OpenTask(self, TaskId):
        Id = self.scheduler.CreateTaskId(TaskId)
        task = Task(self.scheduler, self.hpc_job.OpenTask(Id))
        return task

    def Refresh(self):
        self.hpc_job.Refresh()

    def SetJobTemplate(self, JobTemplateName):
        self.hpc_job.SetJobTemplate(JobTemplateName)

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
        mydict = {}
        props = self.hpc_job.GetCustomProperties()

        for i in props:
            mydict[i.Name] = i.Value

        return mydict

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
$Log: job.py  $
Revision 1.1 2021/12/13 17:57:15CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/hpc/project.pj
Revision 1.11 2013/11/08 14:25:18CET Hecker, Robert (heckerr) 
Added support for sending e-mail notifications.
- Added comments -  heckerr [Nov 8, 2013 2:25:19 PM CET]
Change Package : 205391:1 http://mks-psad:7002/im/viewissue?selection=205391
Revision 1.10 2013/09/16 13:20:57CEST Hecker, Robert (heckerr)
fixed relative Import.
--- Added comments ---  heckerr [Sep 16, 2013 1:20:58 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.9 2013/03/28 14:43:03CET Mertens, Sven (uidv7805)
pylint: resolving some R0904, R0913, R0914, W0107
--- Added comments ---  uidv7805 [Mar 28, 2013 2:43:03 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/02/19 20:34:26CET Hecker, Robert (heckerr)
Moved some Functionality to hpc_defs
--- Added comments ---  heckerr [Feb 19, 2013 8:34:26 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2013/02/13 10:07:09CET Hecker, Robert (heckerr)
Minjor change in variable name.
--- Added comments ---  heckerr [Feb 13, 2013 10:07:09 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2012/12/14 16:22:44CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:44 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2012/12/12 09:01:32CET Hecker, Robert (heckerr)
Commented out some Methods / Attributes, which should not be used.
--- Added comments ---  heckerr [Dec 12, 2012 9:01:32 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/11 14:18:47CET Hecker, Robert (heckerr)
Updated GetcustomProperties Method.
--- Added comments ---  heckerr [Dec 11, 2012 2:18:50 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/10 08:41:16CET Hecker, Robert (heckerr)
Renames stkHpcTask class usage to Task.
--- Added comments ---  heckerr [Dec 10, 2012 8:41:16 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:46CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:47 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:36:16CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
