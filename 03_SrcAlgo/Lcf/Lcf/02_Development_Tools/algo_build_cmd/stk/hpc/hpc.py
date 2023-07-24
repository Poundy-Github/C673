"""
stk/hpc
-------

Hpc Module for Hpc.

**User-API Interfaces**

    - `stk.hpc` (complete package)
    - `Hpc` (this module)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:02CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import shutil
import win32api
import datetime
import time
import stat
import warnings

# Import STK Modules ----------------------------------------------------------
from . ifc.hpc.scheduler import Scheduler
from . ifc.hpc.job import JobUnitType
from . ifc.hpc.job import Job
from . ifc.hpc.task import TaskType
from . util.prj_handler import ProjectHandler
from . ifc.masterdb import master_db_com as mdb
from . error import HpcError

from . ifc import jobdb as db
from . util import jobxml

# Defines ---------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class Hpc(object):
    """
    **This is the main Interface regarding HPC for the User-API inside stk.**

    - You can use this class to submit jobs onto the ADAS HPC Cluster.
    - For minimum functionality you need at least the `Hpc` and `TaskFactory`.
    - To simulate a whole submit and execute a testrun, you can use instead of the Hpc the `HpcSim` class.

    **Example:**

    .. python::

        # Import stk.hpc
        import stk.hpc as hpc

        #Connect to the HPC Server
        myHpc = hpc.Hpc()

        #Set Project (Required!)
        myHpc.SetProject('MFC310_Test')

        #Create the Job
        myHpc.CreateJob("Training_Ping")

        factory = hpc.TaskFactory(myHpc)
        factory.CreateTask('ping 127.0.0.1')
        myHpc.SubmitJob()

    :author:        Robert Hecker
    :date:          22.01.2012
    """
    def __init__(self, HeadNode="LISS006.CW01.CONTIWAN.COM",
                 HPCBaseFolder=r"\\LIFS010.cw01.contiwan.com\hpc",
                 UseOracleMasterDB=True):

        # Initialize needed classes
        self.HeadNode = HeadNode
        self.Scheduler = Scheduler(HeadNode)
        """Used Scheduler"""

        self.PrjHdl = ProjectHandler(HeadNode, HPCBaseFolder)
        self.Job = Job(self.Scheduler)
        self.UseOracleMasterDB = UseOracleMasterDB
        self.JobDB = db.ifc.HpcDb()
        self.hpcXml = jobxml.HpcXml()
        self.taskid = 0

        if(UseOracleMasterDB):
            self.MasterDbHdl = mdb.MasterDBCom()

    def GetNextTaskId(self):
        """
        This method is used from the TaskFactory, to get the next free TaskID.
        This is handled on this central place, because the Task ID's are unique,
        to create a unique Folder Name on the File Server for the Task output.

        This method is only for internal usage, and not part of the USER-API.

        :return:        NExt Free Task ID
        :rtype:         int

        :author:        R Hecker
        :date:          05.08.2013
        """
        self.taskid += 1
        return self.taskid

    def __on_rm_error(self, func, path, exc_info):
        """
        Error handler for ``shutil.rmtree``.

        If the error is due to an access error (read only file)
        it attempts to add write permission and then retries.

        If the error is for another reason it re-raises the error.

        Usage : ``shutil.rmtree(path, onerror=onerror)``
        """
        if not os.access(path, os.W_OK):
            # Is the error an access error ?
            # print 'access error, set write attribute & delete: ', path
            os.chmod(path, stat.S_IWUSR)
            func(path)
        else:
            raise

    def __CreateNodePrepTask(self):
        """
        Create A Node Preparation Task to Copy the whole Input Data
        from the Network Job Folder to a local Folder on the client
        This is needed, because various Applications, including
        MTS have a problem, when multiple clients will start the same
        physical binary application. For e.g. MTS will massivly slow down
        the execution of a simulation run, in worst case simulation
        will get stopped.

        :author:           Robert Hecker
        """
        # Create Task
        task = self.Job.CreateTask()
        task.Name = 'NodePreparationTask'
        task.Type = TaskType.NodePrep

        # Add Task to Job
        self.Job.AddTask(task)

        cmdLine = 'nodeprep2.bat '
        cmdLine += self.PrjHdl.GetJobFolderName()
        cmdLine += ' '
        cmdLine += self.PrjHdl.GetNetJobPath()

        # Replace \\LIFS010 with LIFS010S
        cmdLine = cmdLine.replace('LIFS010.', 'LIFS010S.')
        # stdout = CurTaskOutFolder + r'\stdout.txt'
        # stderr = CurTaskOutFolder + r'\stderr.txt'

        # Set all needed Task Informations
        task.CommandLine = cmdLine
        task.WorkDirectory = 'D:\\Apps'
        # task.SetStdOutFilePath(stdout)
        # task.SetStdErrFilePath(stderr)
        task.Commit()

        return cmdLine

    def __CreateNodeReleaseTask(self):

        # Create Task
        task = self.Job.CreateTask()
        task.Name = 'NodeReleaseTask'
        task.Type = TaskType.NodeRelease

        # Add Task to Job
        self.Job.AddTask(task)

        cmdLine = 'deltree.bat d:\\data\\'
        cmdLine += self.PrjHdl.GetJobFolderName()
        # stdout = CurTaskOutFolder + r'\stdout.txt'
        # stderr = CurTaskOutFolder + r'\stderr.txt'

        # Set all needed Task Informations
        task.CommandLine = cmdLine
        task.WorkDirectory = 'D:\\Apps'
        # task.SetStdOutFilePath(stdout)
        # task.SetStdErrFilePath(stderr)
        task.Commit()

        return cmdLine

    def SetProject(self, ProjectName):
        """
        Set the Project which must be used for the Job
        Only Projects which are stored internaly in a list are valid ones.
        Please Check the whole list in the ProjectHandler.
        The Project Name is used for:

        1. The FolderName, where the Job Input/Output will be stored
        2. For Job Template Names inside Microsoft HPC

        :type  ProjectName: string
        :param ProjectName: Name of the Project (e.g. MFC310, ARS301,...)
        :note:              Please Check the whole list for valid
                            ProjectNames in the ProjectHandler.
        """
        self.PrjHdl.SetProject(ProjectName)

    def CreateJob(self, JobName, **kwarg):
        """
        This method creates the HPC Job inside the Microsoft HPC environment.
        Also the Network Job Folders for input and output data will be crated
        with the unique job id given by the HPC System.

        Additional to that the all needed python file will be copied into
        the input data folder [app_starter, app_watcher,....] from the given
        stkFolder.

        When the stkFolder is empty, a default folder will be assumed.

        :type  JobName:   string
        :param JobName:   The Name of the Job; used in HPC.
                          JobName should have less then 32 characters.
                          To get the correct Forecast for the Created Job, the JobName
                          must be created in following style:

                          <TeamName>_<JobType>_[Project]_[Checkpoint]
        """

        if('stkFolder' in kwarg):
            warnings.warn("Parameter 'stkFolder' is deprecated and not more used", stacklevel=2)

        if(len(JobName) > 32):
            raise HpcError("JobName len greater than 32 Characters, Abort operation !")

        # Create Job in HPC
        self.Job = self.Scheduler.CreateJob()
        # Set JobNames
        self.PrjHdl.SetJobName(JobName)
        self.Job.Name = JobName

        # Set Project Name
        self.Job.Project = self.PrjHdl.GetProjectName()

        # Set Job Template
        self.Job.SetJobTemplate(self.PrjHdl.GetJobTemplateName())

        self.Job.UnitType = JobUnitType.Core

        # Add Job to scheduling system
        self.Scheduler.AddJob(self.Job)

        # Set Job Id
        self.PrjHdl.SetJobId(self.Job.Id)

        # Get the Net Job Folder Path
        netJobFolder = self.PrjHdl.CreateNetJobSubFolders()
        print netJobFolder

        # Create local DB with all the needed Entries to Start all Tasks and Subtasks
        self.JobDB.create(os.path.split(netJobFolder)[1] + '.db')

        path = os.path.abspath(__file__)
        stkFolder = os.path.split(os.path.split(path)[0])[0]

        # Copy whole stkFolder to the Input Folder
        dest = os.path.join(netJobFolder, '1_Input', 'stk')
        shutil.copytree(stkFolder, dest)

        job_tabel = db.tabels.Job(self.PrjHdl.GetJobFolderName(), self.PrjHdl.GetBaseFolder(),
                                  self.PrjHdl.GetProjectName(), self.HeadNode, self.UseOracleMasterDB)

        self.JobDB.session.add(job_tabel)
        self.JobDB.session.commit()

        xjob = jobxml.Job()
        xjob.Name = self.Job.Name
        self.hpcXml.createJob(xjob)

        return netJobFolder

    def GetSTKFolder(self):
        """
        provide the currently used stkFolder Path.

        :rtype:  str
        :return: the local used stkFolder.
        :todo: Take care for a non default stkFolder.
        """
        warnings.warn('Method GetSTKFolder() is deprecated and will be removed in STK 2.1.X Version', stacklevel=2)
        path = os.path.abspath(__file__)
        return os.path.split(os.path.split(path)[0])[0]

    def __CopySTKFolder(self, stkFolder=''):

        if(stkFolder == ""):
            stkFolder = self.GetSTKFolder()

        # Copy needed stk onto Network Folder
        dest = os.path.join(self.PrjHdl.GetNetJobInPath(), 'stk')
        shutil.copytree(stkFolder, dest)

    def CopySTKFolder(self, stkFolder=''):

        warnings.warn('Method CopySTKFolder() is deprecated and will be removed in STK 2.1.X Version', stacklevel=2)

    def SetExclusiveFlag(self, Exclusive):
        """
        Determines whether nodes are exclusively allocated to the job.

        :param Exclusive: Exclusive node allocation (True/False)
        :type Exclusive:  bool
        :return:          -
        :note:            use after CreateJob-Method call
        """
        self.Job.IsExclusive = Exclusive
        self.Job.Commit()

    def SetEmailNotification(self, onStart=False, onCompletion=True):
        """
        Turn on the E-Mail notification possibility from HPC.
        With this Method you will get the possibility to be notified,
        whe your job starts or ends.

        :param OnStart:      Enable sendig a e-mail when your job Starts.
        :type OnStart:       bool
        :param OnCompletion: Enable sendig a e-mail when your job completes.
        :type OnCompletion:  bool
        :return:             -
        :note:               use after CreateJob-Method call
        """
        self.Job.NotifyOnStart = onStart
        self.Job.NotifyOnCompletion = onCompletion
        self.Job.Commit()

    def SetPriority(self, Priority):
        """
        Set the job priority.

        :param Priority: Priority Value
        :type Priority:  Constant of class JobPriority.
        :return:         -
        :note:           use after CreateJob-Method call
        """
        self.Job.Priority = Priority
        self.Job.Commit()

    def SetJobUnit(self, JobUnit):
        """
        Set the job unit type.

        :param JobUnit: JobUnit Value
        :type JobUnit:  Constant of class JobUnitType.
        :return:        -
        :note:          use after CreateJob-Method call
        """
        self.Job.UnitType = JobUnit
        self.Job.Commit()

    def SetRequestedNodes(self, RequestedNodes):
        """
        Sets the list of nodes that are requested for the job.

        Example: SetRequestedNodes(["LUS0010M","LUS0011M"])

        :param RequestedNodes: List of all requested nodes.
        :type RequestedNodes:  list
        :return:        -
        :note:          use after CreateJob-Method call
        """
        self.Job.RequestedNodes = RequestedNodes
        self.Job.Commit()

    def SetNodeGroups(self, NodeGroups):
        """
        Sets the names of the node groups that specify the nodes on
        which the job can run.

        Example: SetNodeGroups(["FPGABox_Nodes"])

        :param NodeGroups: List of all group names.
        :type NodeGroups:  list
        :return:        -
        :note:          use after CreateJob-Method call
        """
        self.Job.NodeGroups = NodeGroups
        self.Job.Commit()

    def SetMaxCoreCount(self, MaxCoreCount):
        """
        Sets the maximum number of cores that the scheduler may allocate
        for the job.

        :param MaxCoreCount: max number of cores.
        :type MaxCoreCount:  int
        :return:        -
        :note:          use after CreateJob-Method call
        """
        self.Job.MaximumNumberOfCores = MaxCoreCount
        self.Job.AutoCalculateMax = False
        self.Job.Commit()

    def SetMaxNodeCount(self, MaxNodeCount):
        """
        Sets the maximum number of nodes that the scheduler may
        allocate for the job.

        :param MaxNodeCount: max number of nodes.
        :type MaxNodeCount:  int
        :return:        -
        :note:          use after CreateJob-Method call
        """
        self.Job.MaximumNumberOfNodes = MaxNodeCount
        self.Job.AutoCalculateMax = False
        self.Job.Commit()

    def SetHoldUntil(self, HoldTime):
        """
        Sets the date and time in Coordinated Universal Time
        until which the HPC Job Scheduler Service should wait
        before trying to start the job.

        :param HoldTime: local date/time for first try to start job.
        :type HoldTime:  datetime struct
        :return:        -
        :note:          use after CreateJob-Method call
        """
        if(HoldTime < datetime.datetime.now()):
            raise HpcError("HoldTime is in the past")

        sectohold = int(time.mktime(HoldTime.timetuple()))
        self.Job.SetCustomProperty('HPC_HoldUntil', str(sectohold))
        self.Job.Commit()

    def SubmitJob(self, UserName=win32api.GetUserNameEx(2), pwd=''):
        """
        Adds a job to the scheduling queue.
        If your credentials are cached inside the job manager, you can call
        the method without arguments.
        If you want to submit the job as an different user, please fill in
        the currect UserName and pwd.
        If your credentials are not stored inside the job manager, the hpc will
        ask you for the password.
        If HPC will ask you for the pasword, and you are inside a debug session,
        the submit will get stucked. Password prompting is only working from
        comandline.

        :param UserName: Domain User ID.
        :type UserName:  string
        :param pwd: empty string ("") or password form the Domain account
        :type pwd:  string
        :return:        -
        """
        self.JobDB.session.commit()

        # Get FileName of sqlite job file
        filename = self.JobDB.filename

        # Copy the db file to the Network Folder
        dest = os.path.join(self.PrjHdl.GetNetJobInPath(), filename)
        shutil.copyfile(filename, dest)

        priority = -1

        hfile = file("hpc.xml", "w")
        hfile.write(self.hpcXml.getXml())
        hfile.close()

        # Create all Tasks
        self.Job.hpc_job.RestoreFromXml('hpc.xml')
        self.Job.Commit()

        # Create needed Node Prep/Release Tasks
        self.__CreateNodePrepTask()
        self.__CreateNodeReleaseTask()

        if(self.UseOracleMasterDB):

            # Get all Tasks from our Job
            tasks = self.Job.GetTaskList()

            # Set Job Information into the Oracle DataBase
            # And Get calculated Prio from the Job
            priority = self.MasterDbHdl.submitJob(self.Job,
                                                  tasks,
                                                  UserName)

            if(priority > 0):
                # Set Priority into HPC
                self.Job.ExpandedPriority = priority

            self.Job.Commit()

        self.Scheduler.SubmitJobById(self.Job.Id, UserName, pwd)

        try:
            os.unlink(filename)
        except os.error:
            pass

"""
CHANGE LOG:
-----------
$Log: hpc.py  $
Revision 1.1 2021/12/13 17:57:02CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/project.pj
Revision 1.45 2013/12/04 12:07:46CET Hecker, Robert (heckerr) 
replaced unused argument with deprecation warning.
- Added comments -  heckerr [Dec 4, 2013 12:07:46 PM CET]
Change Package : 209872:1 http://mks-psad:7002/im/viewissue?selection=209872
Revision 1.44 2013/12/04 10:48:41CET Hecker, Robert (heckerr)
Deleting now unused *.db file after submit.
--- Added comments ---  heckerr [Dec 4, 2013 10:48:42 AM CET]
Change Package : 209846:1 http://mks-psad:7002/im/viewissue?selection=209846
Revision 1.43 2013/11/08 15:15:36CET Hecker, Robert (heckerr)
Added E-Mail Notification possibility
--- Added comments ---  heckerr [Nov 8, 2013 3:15:37 PM CET]
Change Package : 205413:1 http://mks-psad:7002/im/viewissue?selection=205413
Revision 1.42 2013/11/08 14:24:38CET Hecker, Robert (heckerr)
Added new Method for supporting E-Mail notifications.
--- Added comments ---  heckerr [Nov 8, 2013 2:24:38 PM CET]
Change Package : 205391:1 http://mks-psad:7002/im/viewissue?selection=205391
Revision 1.41 2013/10/22 17:53:00CEST Hecker, Robert (heckerr)
updates for the new hpc data share on lifs010
--- Added comments ---  heckerr [Oct 22, 2013 5:53:00 PM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.40 2013/09/18 10:35:25CEST Hecker, Robert (heckerr)
BugFix: Referted to old UserInterface, and added some deprecated warnings.
--- Added comments ---  heckerr [Sep 18, 2013 10:35:26 AM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.39 2013/09/18 09:09:13CEST Hecker, Robert (heckerr)
Adapted Interface to new stk copy handling.
COpySTKFolder will do nothing more in future, but is still keept for USA-API backward compatibility.
--- Added comments ---  heckerr [Sep 18, 2013 9:09:13 AM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.38 2013/09/17 17:37:50CEST Hecker, Robert (heckerr)
BugFix: Added already deleted code.
--- Added comments ---  heckerr [Sep 17, 2013 5:37:50 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.37 2013/09/17 16:18:29CEST Hecker, Robert (heckerr)
Adapted to new internal structure.
--- Added comments ---  heckerr [Sep 17, 2013 4:18:29 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.36 2013/09/13 16:51:59CEST Hecker, Robert (heckerr)
Dervided HPCError Exception handling class from StkError base exception.
--- Added comments ---  heckerr [Sep 13, 2013 4:51:59 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.35 2013/09/11 16:25:44CEST Hecker, Robert (heckerr)
Removed dependency to xmlmapper.py
--- Added comments ---  heckerr [Sep 11, 2013 4:25:45 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.34 2013/09/11 13:59:23CEST Hecker, Robert (heckerr)
- Added Docu.
- Removed some pylint Issues.
--- Added comments ---  heckerr [Sep 11, 2013 1:59:23 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.33 2013/09/10 13:57:36CEST Hecker, Robert (heckerr)
Added docu for JobName setup.
--- Added comments ---  heckerr [Sep 10, 2013 1:57:36 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.32 2013/09/06 15:01:16CEST Hecker, Robert (heckerr)
Added modifications for parallel submit possibility.
sqlite DB Filename is now the JobName.
--- Added comments ---  heckerr [Sep 6, 2013 3:01:16 PM CEST]
Change Package : 193310:1 http://mks-psad:7002/im/viewissue?selection=193310
Revision 1.31 2013/09/05 11:44:40CEST Hecker, Robert (heckerr)
Replaced Exception with HpcError Exception class.
--- Added comments ---  heckerr [Sep 5, 2013 11:44:40 AM CEST]
Change Package : 196378:1 http://mks-psad:7002/im/viewissue?selection=196378
Revision 1.30 2013/09/03 16:12:10CEST Hecker, Robert (heckerr)
Updated Module Header once more....
--- Added comments ---  heckerr [Sep 3, 2013 4:12:11 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.29 2013/09/03 15:53:44CEST Hecker, Robert (heckerr)
Updated Module Header to link also to the Main Package.
--- Added comments ---  heckerr [Sep 3, 2013 3:53:45 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.28 2013/09/03 15:14:49CEST Hecker, Robert (heckerr)
Updated Hpc Dokumentation for User-API.
--- Added comments ---  heckerr [Sep 3, 2013 3:14:49 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.27 2013/08/06 15:55:27CEST Mertens, Sven (uidv7805)
reverting changes for prints
--- Added comments ---  uidv7805 [Aug 6, 2013 3:55:28 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.26 2013/08/06 15:51:05CEST Mertens, Sven (uidv7805)
removing starting r as some pylint error occured but other tests seem to fail
--- Added comments ---  uidv7805 [Aug 6, 2013 3:51:05 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.25 2013/08/06 15:34:32CEST Mertens, Sven (uidv7805)
removing unnecessary print out
--- Added comments ---  uidv7805 [Aug 6, 2013 3:34:32 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.24 2013/08/05 14:56:18CEST Hecker, Robert (heckerr)
Added missing documentation for the newly added method.
--- Added comments ---  heckerr [Aug 5, 2013 2:56:18 PM CEST]
Change Package : 192625:1 http://mks-psad:7002/im/viewissue?selection=192625
Revision 1.23 2013/08/05 13:28:55CEST Hecker, Robert (heckerr)
removed pylint error.
--- Added comments ---  heckerr [Aug 5, 2013 1:28:56 PM CEST]
Change Package : 192625:1 http://mks-psad:7002/im/viewissue?selection=192625
Revision 1.22 2013/08/05 11:06:11CEST Hecker, Robert (heckerr)
Removed some pylint messages.
Revision 1.21 2013/08/05 10:27:47CEST Hecker, Robert (heckerr)
HPC support for different TaskFactories in one Job.
--- Added comments ---  heckerr [Aug 5, 2013 10:27:48 AM CEST]
Change Package : 192625:1 http://mks-psad:7002/im/viewissue?selection=192625
Revision 1.20 2013/07/12 13:42:41CEST Hecker, Robert (heckerr)
Moved Copy from TaskFactoryMTS to Hpc-Class for the file
mts_final_check.py.
--- Added comments ---  heckerr [Jul 12, 2013 1:42:41 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.19 2013/07/01 10:26:53CEST Hecker, Robert (heckerr)
fixed wrong import.
--- Added comments ---  heckerr [Jul 1, 2013 10:26:53 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.18 2013/07/01 09:16:36CEST Hecker, Robert (heckerr)
Adapted some minjor pylint findings.
Revision 1.17 2013/07/01 08:46:20CEST Hecker, Robert (heckerr)
Added xml  submit support to hpc ifc.
--- Added comments ---  heckerr [Jul 1, 2013 8:46:20 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.16 2013/06/27 16:33:18CEST Hecker, Robert (heckerr)
Extended _HPC FolderName with ServerID.
--- Added comments ---  heckerr [Jun 27, 2013 4:33:19 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.15 2013/05/23 15:59:04CEST Raedler, Guenther (uidt9430)
- added new util scripts to be copied into the hpc working folder
--- Added comments ---  uidt9430 [May 23, 2013 3:59:05 PM CEST]
Change Package : 180569:1 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.14 2013/05/16 08:04:49CEST Hecker, Robert (heckerr)
Added Subtask support to HPC Job Creation.
--- Added comments ---  heckerr [May 16, 2013 8:04:49 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.13 2013/02/28 08:12:21CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:22 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.12 2013/02/07 17:11:02CET Hecker, Robert (heckerr)
Removed unused Code, Added Documentation.
--- Added comments ---  heckerr [Feb 7, 2013 5:11:02 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.11 2013/01/23 07:56:32CET Hecker, Robert (heckerr)
Updated epydoc docu.
--- Added comments ---  heckerr [Jan 23, 2013 7:56:32 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.10 2012/12/14 16:22:45CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:45 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.9 2012/12/12 10:37:22CET Hecker, Robert (heckerr)
Updated Code regarding pep8.
--- Added comments ---  heckerr [Dec 12, 2012 10:37:22 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.8 2012/12/12 09:00:37CET Hecker, Robert (heckerr)
Implemented Custom JobHoldUntil Feature.
--- Added comments ---  heckerr [Dec 12, 2012 9:00:38 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2012/12/11 14:18:02CET Hecker, Robert (heckerr)
Get OracleMasterDB support working.
--- Added comments ---  heckerr [Dec 11, 2012 2:18:04 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2012/12/10 17:37:42CET Hecker, Robert (heckerr)
Modified Code to Support OracleMasterDB.
--- Added comments ---  heckerr [Dec 10, 2012 5:37:43 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2012/12/10 16:51:15CET Hecker, Robert (heckerr)
Changed the Copying process for supportfiles to a loop with filelist.
--- Added comments ---  heckerr [Dec 10, 2012 4:51:18 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/10 08:40:19CET Hecker, Robert (heckerr)
- Renamed Method "CopystkFolder" to "CopySTKFolder".
- Adapted Code to Master Oracle DB.
--- Added comments ---  heckerr [Dec 10, 2012 8:40:22 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/05 14:21:37CET Hecker, Robert (heckerr)
Updated not working NodePrepare Task.
--- Added comments ---  heckerr [Dec 5, 2012 2:21:37 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:50CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:50 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:36:15CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
