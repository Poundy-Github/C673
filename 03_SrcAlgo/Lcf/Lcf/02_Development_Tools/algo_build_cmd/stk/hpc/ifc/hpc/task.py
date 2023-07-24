"""
task
----

Interface File to be able to access the Task interface from
Microsoft HPC inside Python. This Module exactly reflects all Task
interfaces from HPC into Python.
No other high level Functions should be included here.

The module gives no garantee, that the whole interface is reflected,
so that missing classes, methods or functions related to the task interface can
be added.

Available Interfaces
====================

    - `TaskState`
    - `TaskType`
    - `Task`

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:16CET $
"""
# Import Python Modules -------------------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class TaskState:
    """
    TaskStateEnumeration, defines the state of the task.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.properties.taskstate(v=vs.85)

    :author:        Robert Hecker
    :date:          29.06.2012
    """
    Configuring = 1
    Submitted = 2
    Validating = 4
    Queued = 8
    Dispatching = 16
    Running = 32
    Finishing = 64
    Finished = 128
    Failed = 256
    Canceled = 512
    Canceling = 1024
    All = 2047

    STATES_STR = {1: "Configuring",
                  2: "Submitted",
                  4: "Validating",
                  8: "ExternalValidating",
                  16: "Queued",
                  32: "Runnning",
                  64: "Finishing",
                  128: "Finished",
                  256: "Failed",
                  512: "Canceled",
                  1024: "Canceling"}

class TaskType:
    """
    TaskTypeEnumeration, defines how to run the Command from a Task
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.properties.tasktype(v=vs.85).aspx

    :author:        Robert Hecker
    :date:          16.04.2012
    """
    Basic, ParametricSweep, NodePrep, NodeRelease, Service = range(5)


class Task(object):
    """
    Class, which reflects the whole functionality of
    the ISchedulerTask Interface from Microsoft HPC.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.ischedulertask(v=vs.85)

    :author:        Robert Hecker
    :date:          16.04.2012
    """

    def __init__(self, scheduler, hpc_task):

        self.scheduler = scheduler
        self.hpc_task = hpc_task

        # Read/Write Properties
        self.Name
        self.CommandLine
        self.StdOutFilePath
        self.StdErrFilePath
        self.WorkDirectory
        self.Type
        self.DependsOn

        # Read Only Properties
        self.TaskId
        self.ExitCode
        self.StartTime
        self.EndTime
        self.State
        self.AllocatedNodes

    def __setattr__(self, name, value):

        if(name == 'Name'):
            self.hpc_task.Name = value

        if(name == 'CommandLine'):
            self.hpc_task.CommandLine = value

        if(name == 'StdOutFilePath'):
            self.hpc_task.StdOutFilePath = value

        if(name == 'StdErrFilePath'):
            self.hpc_task.StdErrFilePath = value

        if(name == 'WorkDirectory'):
            self.hpc_task.WorkDirectory = value

        if(name == 'WorkDirectory'):
            AttributeError('WorkDirectory')

        if(name == 'TaskId'):
            AttributeError('TaskId')

        if(name == 'StartTime'):
            AttributeError('StartTime')

        if(name == 'EndTime'):
            AttributeError('EndTime')

        if(name == 'Type'):
            self.hpc_task.Type = value

        if(name == 'State'):
            AttributeError('State')

        if(name == 'DependsOn'):
            tmp = self.scheduler.CreateStringCollection()
            for i in value:
                tmp.Add(i)

            self.hpc_task.DependsOn = tmp

        if(name == 'AllocatedNodes'):
            AttributeError('AllocatedNodes')

        self.__dict__[name] = value

    def __getattribute__(self, name):

        if(name == 'Name'):
            self.Name = self.hpc_task.Name

        if(name == 'TaskId'):
            self.TaskId = self.hpc_task.TaskId.JobTaskId

        if(name == 'CommandLine'):
            self.CommandLine = self.hpc_task.CommandLine

        if(name == 'StdOutFilePath'):
            self.StdOutFilePath = self.hpc_task.StdOutFilePath

        if(name == 'StdErrFilePath'):
            self.StdErrFilePath = self.hpc_task.StdErrFilePath

        if(name == 'WorkDirectory'):
            self.WorkDirectory = self.hpc_task.WorkDirectory

        if(name == 'ExitCode'):
            self.ExitCode = self.hpc_task.ExitCode

        if(name == 'StartTime'):
            self.StartTime = self.hpc_task.StartTime

        if(name == 'EndTime'):
            self.EndTime = self.hpc_task.EndTime

        if(name == 'Type'):
            self.Type = self.hpc_task.Type

        if(name == 'State'):
            self.State = self.hpc_task.State

        if(name == 'DependsOn'):
            DependsOn = []

            for i in range(self.hpc_task.DependsOn.Count):
                DependsOn.append(self.hpc_task.DependsOn.Item(i))

            self.DependsOn = DependsOn

        if(name == 'AllocatedNodes'):
            AllocatedNodes = []

            for i in range(self.hpc_task.AllocatedNodes.Count):
                AllocatedNodes.append(self.hpc_task.AllocatedNodes.Item(i))

            self.AllocatedNodes = AllocatedNodes

        # Default behaviour
        return object.__getattribute__(self, name)

    def Commit(self):
        """
        Commits the local task changes to the server.
        See http://msdn.microsoft.com/en-us/library/
        microsoft.hpc.scheduler.ischedulertask.commit(v=vs.85)

        :author:        Robert Hecker
        :date:          16.04.2012
        """
        self.hpc_task.Commit()

"""
CHANGE LOG:
-----------
$Log: task.py  $
Revision 1.1 2021/12/13 17:57:16CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/hpc/project.pj
Revision 1.5 2013/05/23 12:53:22CEST Raedler, Guenther (uidt9430) 
- added mapping definition to write string into log file
- removed commented defintions
- Added comments -  uidt9430 [May 23, 2013 12:53:22 PM CEST]
Change Package : 183658:1 http://mks-psad:7002/im/viewissue?selection=183658
Revision 1.4 2013/02/07 17:14:16CET Hecker, Robert (heckerr) 
BugFix in wrong identation.
--- Added comments ---  heckerr [Feb 7, 2013 5:14:16 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/14 16:22:46CET Hecker, Robert (heckerr) 
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:46 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:49CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:49 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:36:19CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
