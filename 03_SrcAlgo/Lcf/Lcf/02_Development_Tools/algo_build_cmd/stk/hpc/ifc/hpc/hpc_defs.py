"""
stk/hpc/hpc_defs
----------------

hpc_defs Module for Hpc.

**User-API Interfaces**

    - `stk.hpc` (complete package)
    - `JobState` (this module)
    - `JobUnitType` (this module)
    - `JobPriority` (this module)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:15CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class JobState:
    """
    JobStateEnumeration, defines the state of a job.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.properties.jobstate(v=vs.85).aspx

    :author:        Robert Hecker
    :date:          14.09.2012
    """
    Configuring = 1
    Submitted = 2
    Validating = 4
    ExternalValidation = 8
    Queued = 16
    Running = 32
    Finishing = 64
    Finished = 128
    Failed = 256
    Canceled = 512
    Canceling = 1024
    All = 2047


class JobUnitType:
    """
    Determines whether cores, nodes, or sockets are used to allocate resources
    for the job.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.ischedulerjob.unittype(v=vs.85).aspx

    :author:        Robert Hecker
    :date:          16.04.2012
    """
    Core, Socket, Node = range(3)


class JobPriority:
    """
    Defines the priorities that you can specify for a job.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.properties.jobpriority(v=vs.85).aspx

    :author:        Robert Hecker
    :date:          16.04.2012
    """
    Lowest, BelowNormal, Normal, AboveNormal, Highest = range(5)


class TaskState:
    """
    Defines the single states, which a Task can have.
    See http://msdn.microsoft.com/en-us/library/
    microsoft.hpc.scheduler.properties.taskstate(v=vs.85).aspx
    """

    Configuring = 1  # The task is being configured.
    Submitted = 2  # The task was added to the scheduling queue.
    Validating = 4  # The scheduler is determining if the task is correctly configured and can run
    Queued = 8  # The task was added to the scheduling queue.
    Dispatching = 16  # The scheduler is in the process of sending the task to the node to run.
    Running = 32  # The task is running.
    Finishing = 64  # The node is cleaning up the resources that were allocated to the task.
    Finished = 128  # The task successfully finished.
    Failed = 256  # The task failed, the job was canceled, or a system error occurred on the compute node.
    Canceled = 512  # The task was canceled (see ISchedulerJob.CancelTask(ITaskId)).
    Canceling = 1024  # The task is in the process of being canceled.
    All = 2047  # A mask used to indicate all states


"""
CHANGE LOG:
-----------
$Log: hpc_defs.py  $
Revision 1.1 2021/12/13 17:57:15CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/ifc/hpc/project.pj
Revision 1.7 2013/09/13 16:52:01CEST Hecker, Robert (heckerr) 
Dervided HPCError Exception handling class from StkError base exception.
- Added comments -  heckerr [Sep 13, 2013 4:52:01 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.6 2013/09/12 11:34:51CEST Hecker, Robert (heckerr)
Added TaskState class to definitions.
--- Added comments ---  heckerr [Sep 12, 2013 11:34:51 AM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.5 2013/09/05 11:42:41CEST Hecker, Robert (heckerr)
Added HpcError Exception class tho hpc package.
--- Added comments ---  heckerr [Sep 5, 2013 11:42:41 AM CEST]
Change Package : 196378:1 http://mks-psad:7002/im/viewissue?selection=196378
Revision 1.4 2013/09/03 16:12:12CEST Hecker, Robert (heckerr)
Updated Module Header once more....
--- Added comments ---  heckerr [Sep 3, 2013 4:12:12 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.3 2013/09/03 15:53:46CEST Hecker, Robert (heckerr)
Updated Module Header to link also to the Main Package.
--- Added comments ---  heckerr [Sep 3, 2013 3:53:47 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.2 2013/03/22 08:24:32CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
--- Added comments ---  uidv7805 [Mar 22, 2013 8:24:32 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.1 2013/02/19 20:30:50CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/hpc/project.pj
"""
