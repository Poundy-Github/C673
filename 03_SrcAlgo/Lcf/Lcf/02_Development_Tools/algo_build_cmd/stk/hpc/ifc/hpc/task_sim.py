"""
stk.hpc.task_sim
----------------

Virtual job class, needed to make a dry run to create a complete running job on
the local pc under d:\data\1_JobName.

This class is used for job creation simulation without hpc.

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

    def __init__(self, scheduler, idx):

        self.scheduler = scheduler

        # Read/Write Properties
        self.Name = ""
        self.CommandLine = ""
        self.StdOutFilePath = ""
        self.StdErrFilePath = ""
        self.WorkDirectory = ""
        self.Type = ""
        self.DependsOn = ""

        # Read Only Properties
        self.TaskId = idx
        self.ExitCode = 0
        self.StartTime = ""
        self.EndTime = ""
        self.State = ""
        self.AllocatedNodes = ""

    def Commit(self):
        """
        Commits the local task changes to the server.
        See http://msdn.microsoft.com/en-us/library/
        microsoft.hpc.scheduler.ischedulertask.commit(v=vs.85)

        :author:        Robert Hecker
        :date:          16.04.2012
        """
        pass

"""
CHANGE LOG:
-----------
$Log: task_sim.py  $
Revision 1.1 2021/12/13 17:57:16CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/hpc/project.pj
Revision 1.1 2013/05/16 08:06:07CEST Hecker, Robert (heckerr) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
