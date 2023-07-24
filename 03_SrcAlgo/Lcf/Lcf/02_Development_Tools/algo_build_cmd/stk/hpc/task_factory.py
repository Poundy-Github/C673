"""
stk/hpc/task_factory
--------------------

TaskFactoryMTS Module for Hpc.

**User-API Interfaces**

    - `stk.hpc` (complete package)
    - `TaskFactory` (this module)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:03CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import re

# Import STK Modules ----------------------------------------------------------
from . util import cmd_cfg as CmdCfg
from . util.cmd_cfg import StaticCMDHelper
from .ifc import jobdb as  db
from . error import HpcError
from .util import jobxml

# Defines ---------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class CmdHelper(object):
    def __init__(self):
        self.cmd = ""

    def SetCMD(self, cmd):
        self.cmd = cmd

    def GetCmdList(self):
        return CmdCfg.ArgToList(self.cmd)


class TaskFactory(object):
    """
    **Create Tasks based on "nomal" commandline call.**

    - Typicall usage is first to set all information, which is the same for all Tasks. (environmentvariables, workingdir, ....)
    - After that, multiple calls of the "CreateTask" - for the real Task creation.

    *Example:*

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

    **Creates Tasks based on SubTasks.**

    - Tasks can be the SubTaskIndex from a SubTaskFactory Created Task.

    *Example:*

    .. python::

        # Import stk.hpc
        import stk.hpc as hpc

    :author:        Robert Hecker
    :date:          16.04.2012
    """
    def __init__(self, hpc, configFile='app.cfg'):
        self._CMDHelper = StaticCMDHelper()
        self._CMDHelper.Globs.UseMasterOracleDB(hpc.UseOracleMasterDB)

        self.Hpc = hpc
        self._ConfigFile = configFile
        self._FirstRun = True
        self._TaskNameList = []
        # self.TaskId = 1

        self.AddEnvironmentVariable('MPLCONFIGDIR',
                                    'd:\\data\\%JobName%\\2_Output\\%TaskName%\\tmp')

    def _CreateTaskName(self, taskId):
        return "T%05d" % taskId

    def _GetNetJobPath(self):
        return self.Hpc.PrjHdl.GetNetJobPath()

    def _WriteExampleBat(self, TaskId, CMDLine):

        if(TaskId == 1):
            # Write Example bat File
            batpath = os.path.join(self._GetNetJobPath(),
                                   '1_Input', 'test.bat')
            f = file(batpath, 'w')
            f.write(CMDLine)
            f.close
            del f

    def _SetTaskInfoDB(self, task, taskId):

        dbFileName = self.Hpc.JobDB.filename

        options = ' -i' + dbFileName

        options += ' -t' + task.Name
        cmdLine = os.path.join("stk\\hpc\\app\\app_starter.py " + options)

        if(len(cmdLine) > 479):
            raise HpcError("CMDLine length greater than 480 characters!")

        # Set all needed Task Informations
        task.CommandLine = cmdLine
        tmp = self.Hpc.PrjHdl.GetJobFolderName()
        task.WorkDirectory = os.path.join(r'd:\data', tmp, '1_Input')

        stdout = os.path.join(self.Hpc.PrjHdl.GetClientJobOutPath(),
                              "stdout_" + "%05d.txt" % taskId)
        # stdout = os.path.join(self.Hpc.PrjHdl.GetNetJobOutPath(),
        #                      "stdout_"+"%05d.txt"%Task.TaskId)
        task.StdOutFilePath = stdout

        stderr = os.path.join(self.Hpc.PrjHdl.GetClientJobOutPath(),
                              "stderr_" + "%05d.txt" % taskId)
        # stderr = os.path.join(self.Hpc.PrjHdl.GetNetJobOutPath(),
        #                      "stderr_"+"%05d.txt"%Task.TaskId)
        task.StdErrFilePath = stderr

        return cmdLine

    def _SetTaskInfo(self, task, cmdList, taskId):

        # Get TaskName
        taskName = task.Name

        # Get JobIdName
        jobIdName = "%s_%s" % (str(self.Hpc.Job.Id),
                               self.Hpc.Job.Name)

        # Go through all the Options and split them between static and dynamic
        appCmdList = CmdCfg.GetDynamicCMDList(cmdList)

        # Replace all the place holder variables
        appCmdList = map(lambda l: l.replace('%JobName%', jobIdName),
                         appCmdList)
        appCmdList = map(lambda l: l.replace('%TaskName%', taskName),
                         appCmdList)

        networkPath = self._GetNetJobPath()

        options = '-n' + networkPath + ' -t' + taskName

        if(self._ConfigFile != ''):
            options += ' -c' + self._ConfigFile

        for cmd in appCmdList:
            options += ' -d\"' + cmd + '\"'
        cmdLine = os.path.join("stk\\hpc\\app\\app_starter.py " + options)

        # Replace \\LIFS010 with LIFS010S
        replacements = (('\\\\LIFS010.', '\\\\LIFS010S.'),
                       ('\\\\LIFS010\\', '\\\\LIFS010S\\'))

        for repl in replacements:
            regexp = re.compile(re.escape(repl[0]), re.IGNORECASE)
            cmdLine = regexp.sub(repl[1].replace('\\', '\\\\'), cmdLine)

        if(len(cmdLine) > 479):
            raise HpcError("CMDLine length greater than 480 characters!")

        # Set all needed Task Informations
        task.CommandLine = cmdLine
        tmp = self.Hpc.PrjHdl.GetJobFolderName()
        task.WorkDirectory = os.path.join(r'd:\data', tmp, '1_Input')

        stdout = os.path.join(self.Hpc.PrjHdl.GetClientJobOutPath(),
                              "stdout_" + "%05d.txt" % taskId)
        # stdout = os.path.join(self.Hpc.PrjHdl.GetNetJobOutPath(),
        #                      "stdout_"+"%05d.txt"%Task.TaskId)
        task.StdOutFilePath = stdout

        stderr = os.path.join(self.Hpc.PrjHdl.GetClientJobOutPath(),
                              "stderr_" + "%05d.txt" % taskId)
        # stderr = os.path.join(self.Hpc.PrjHdl.GetNetJobOutPath(),
        #                      "stderr_"+"%05d.txt"%Task.TaskId)
        task.StdErrFilePath = stderr

        return cmdLine

    def _CreateTaskDB(self, dependsOn=None):
        """
        Base Functionality for creating a new Task

        Due the fact, that HPC is only capable to use 480 Characters
        for the max. Comand Line length, single CommandLine Argumets
        can be marked as static. This static Command Line Arguments
        will be stored to file, to save characters for the
        Normal Command Line of HPC.

        :param dependsOn:   list of TaskNames
        :type dependsOn:    list of strings

        :author:           Robert Hecker
        """

        # Write static Config File to Network Job Folder
        if(self._FirstRun):
            # Store Config in Helper class
            # self._CMDHelper.CMDs.Set(CMDHelper.GetCmdList())
            # Build Path where to write Config File
            # path = os.path.join(self._GetNetJobPath(),
            #                    '1_Input',
            #                   self._ConfigFile)
            # self._CMDHelper.Write(path)
#             job = jobxml.Job()
#             job.Name = self.Hpc.Job.Name
#             self.Hpc.hpcXml.createJob(job)
            self._FirstRun = False

        # Create Task
        # Task = self.Hpc.Job.CreateTask()
        task = jobxml.Task()

        # Add Task to Job
        # self.Hpc.Job.AddTask(Task)

        # Create TaskName with Unique TaskCounter
        taskId = self.Hpc.GetNextTaskId()
        task.Name = self._CreateTaskName(taskId)

        # Remember Task Name for Final Task
        self._TaskNameList.append(task.Name)

        # Fill Task with needed Input
        cmdLine = self._SetTaskInfoDB(task, taskId)

        self._WriteExampleBat(taskId, cmdLine)

        if(dependsOn is not None):
            task.DependsOn = dependsOn

        # Task.Commit()

        task.MinNodes = 1
        task.MaxNodes = 1
        task.MinCores = 1
        task.MaxCores = 1

        self.Hpc.hpcXml.AppendTask(task)

        return task

    def _CreateTask(self, cmdHelper, dependsOn=None, sweep=False):
        """
        Base Functionality for creating a new Task

        Due the fact, that HPC is only capable to use 480 Characters
        for the max. Comand Line length, single CommandLine Argumets
        can be marked as static. This static Command Line Arguments
        will be stored to file, to save characters for the
        Normal Command Line of HPC.

        :param cmdHelper:    list of CommandLine Arguments
        :type: cmdHelper:    class object `CMDHelper`
        :param dependsOn:    list of TaskNames
        :type: dependsOn:    list of strings
        :param sweep:        create "sweep"-task
        :type sweep:         boolean

        :author:           Robert Hecker
        """

        # Write static Config File to Network Job Folder
        if(self._FirstRun):
            # Store Config in Helper class
            self._CMDHelper.CMDs.Set(cmdHelper.GetCmdList())
            # Build Path where to write Config File
            path = os.path.join(self._GetNetJobPath(),
                                '1_Input',
                                self._ConfigFile)
            self._CMDHelper.Write(path)
            self._FirstRun = False

        # Create Task
        # RH Task = self.Hpc.Job.CreateTask()
        task = jobxml.Task()

#         if(Sweep is True):
#             Task.hpc_task.IsParametric = True
#             Task.hpc_task.StartValue = 1
#             Task.hpc_task.EndValue = 20
#             Task.hpc_task.IncrementValue = 1

        # Add Task to Job
        # RH self.Hpc.Job.AddTask(Task)

        # Create TaskName with Unique TaskCounter
        taskId = self.Hpc.GetNextTaskId()
        task.Name = self._CreateTaskName(taskId)

        # Remember Task Name for Final Task
        self._TaskNameList.append(task.Name)

        # Fill Task with needed Input
        cmdLine = self._SetTaskInfo(task, cmdHelper.GetCmdList(), taskId)

        self._WriteExampleBat(taskId, cmdLine)

        if(dependsOn is not None):
            task.DependsOn = dependsOn

        task.MinNodes = 1
        task.MaxNodes = 1
        task.MinCores = 1
        task.MaxCores = 1

        self.Hpc.hpcXml.AppendTask(task)
        # Task.Commit()

        return task

    def SetCurWorkingDir(self, workingDir):
        """
        SetCurWorkingDir set the current working dir for your process.
        Per default the current working directory is set to D:/data/%JobName%/1_Input.

        :note:
            - %JobName% will be replaced with the real JobName.
            - %TaskName% will be replaced with the real TaskName.

        :param workingDir:   Name of the Environment Variable.
        :type workingDir:    string

        :author:         Robert Hecker
        """
        self._CMDHelper.CWD.Set(workingDir)

    def AddEnvironmentVariable(self, key, value):
        """
        With this method, you are able to set multiple Environment variables for your Task.
        You can call this method several times, with different key/value - pairs.
        All of them will be set before your task starts with execution.

        :param key:   Name of the Environment Variable.
        :type key:    string
        :param value: Value which is used to set the Environment Variable.
        :type value:  string

        :author:         Robert Hecker
        """
        self._CMDHelper.ENVs.Append(key + '=' + value)

    def AppendNodeFolder(self, folder):
        """
        AppendNodeFolder will create some needed folders localy on the hpc-client, before your real task is starting.
        If your application needs some special folders, they can be created with this method.
        Multiple calls of this method with different arguments will result in creating multiple folders.

        :param folder:   Name of the folder below d:/data/%JobName.(e.g.: "2_Output/data/hugo")
        :type folder:    string

        :author:         Robert Hecker
        """
        if(os.path.isabs(folder)):
            raise HpcError("Only relative Folder below Job Folder are allowed!")
        folder = os.path.join('d:\\data\\%JobName%', folder)
        self._CMDHelper.Folders.Append(folder)

    def ActivateAppWatcher(self, active):
        """
        The ApplicationWatcher normaly checks the real Task, if the task is still running.
        He does this with looking on the cpu-load and the io of the process.
        Is the task under the limit of the minimum cpu-load and/or io, he will kill the process
        to free the node again.

        Sometime it is necessay, to deactivate this, because the ApplicationWatcher kills the
        process in a unwanted situation. For this you can call this Method.

        :param active:   Flag if Application Watcher shall be deactivated or not.
        :type active:    boolean

        :author:         Robert Hecker
        """
        self._CMDHelper.AppWatcher.Set(active)

    def UseGlobalDataFolder(self, value):
        """
        The normal processing of the HPC is to copy the Task results from
        the client (d:/data/%JobName%/2_Output/%TaskName%/data) back to the Server.
        Some Applications can not handle this, so we provide here the possibility
        to copy the results back from (d:/data/%JobName%/2_Output/data) to the Server.
        With calling this method and setting the parameter to "True" exactly this will be done.

        Please be sure, that your Task provide the output then also to this global folder,
        and be aware, that multiple Task can run in parallel on one client, so the enabling
        of this feature can produce some unwanted side effects.

        :note: per default the global data folder will not be used.

        :param value:   ActivationFlag to use GlobalData folder or not.
        :type value:    boolean

        :author:         Robert Hecker
        """
        self._CMDHelper.Globs.UseGlobal_DataFolder(value)

    def _CreateTaskBasic(self, cmd, dependsOn=None, sweep=False):
        """
        Base Functionality for creating a new Task

        Due the fact, that HPC is only capable to use 480 Characters
        for the max. Comand Line length, single CommandLine Arguments
        can be marked as static. This static Command Line Arguments
        will be stored to file, to save characters for the
        Normal Command Line of HPC.

        :param cmd:    Commandline for the executable to start.

        :author:           Robert Hecker
        """
        cmdHelper = CmdHelper()
        cmdHelper.SetCMD(cmd)

        return self._CreateTask(cmdHelper, dependsOn, sweep)

    def _CreateTaskWithSubtask(self, subtasklist, dependsOn=None):

        # Create the HPC Task
        hpc_task = self._CreateTaskDB(dependsOn)

        task_table = db.tabels.Task(hpc_task.Name)
        self.Hpc.JobDB.session.add(task_table)
        self.Hpc.JobDB.session.commit()
        counter = 1
        tid = task_table.id

        # Create all needed Mapping Entries for the Task
        for item in subtasklist:

            mapping = db.tabels.SubTaskMapping(tid, item, counter)
            counter += 1
            self.Hpc.JobDB.session.add(mapping)
            self.Hpc.JobDB.session.commit()

        return hpc_task

    def CreateTask(self, cmd, dependsOn=None):
        """
        Base Functionality for creating a new Task

        Due the fact, that HPC is only capable to use 480 Characters
        for the max. Comand Line length, single CommandLine Arguments
        can be marked as static. This static Command Line Arguments
        will be stored to file, to save characters for the
        Normal Command Line of HPC.

        :param cmd:    Commandline for the executable to start.

        :author:           Robert Hecker
        """
        subtaskmode = True
        result = None

        try:
            # Try to read out integer value
            id1 = cmd[0]
            if type(id1) is str:
                subtaskmode = False

        except:
            subtaskmode = False

        if(subtaskmode):
            result = self._CreateTaskWithSubtask(cmd, dependsOn)
        else:
            result = self._CreateTaskBasic(cmd, dependsOn)

        return result

"""
CHANGE LOG:
-----------
$Log: task_factory.py  $
Revision 1.1 2021/12/13 17:57:03CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/project.pj
Revision 1.29 2013/09/17 16:23:08CEST Hecker, Robert (heckerr) 
Adapted to new internal structure.
- Added comments -  heckerr [Sep 17, 2013 4:23:08 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.28 2013/09/13 16:52:00CEST Hecker, Robert (heckerr) 
Dervided HPCError Exception handling class from StkError base exception.
--- Added comments ---  heckerr [Sep 13, 2013 4:52:01 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.27 2013/09/11 17:32:20CEST Hecker, Robert (heckerr)
updated to correct variable name.
--- Added comments ---  heckerr [Sep 11, 2013 5:32:20 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.26 2013/09/11 13:59:25CEST Hecker, Robert (heckerr)
- Added Docu.
- Removed some pylint Issues.
--- Added comments ---  heckerr [Sep 11, 2013 1:59:25 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.25 2013/09/06 15:01:17CEST Hecker, Robert (heckerr)
Added modifications for parallel submit possibility.
sqlite DB Filename is now the JobName.
--- Added comments ---  heckerr [Sep 6, 2013 3:01:18 PM CEST]
Change Package : 193310:1 http://mks-psad:7002/im/viewissue?selection=193310
Revision 1.24 2013/09/05 11:44:41CEST Hecker, Robert (heckerr)
Replaced Exception with HpcError Exception class.
--- Added comments ---  heckerr [Sep 5, 2013 11:44:41 AM CEST]
Change Package : 196378:1 http://mks-psad:7002/im/viewissue?selection=196378
Revision 1.23 2013/09/03 16:12:11CEST Hecker, Robert (heckerr)
Updated Module Header once more....
--- Added comments ---  heckerr [Sep 3, 2013 4:12:12 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.22 2013/09/03 15:53:46CEST Hecker, Robert (heckerr)
Updated Module Header to link also to the Main Package.
--- Added comments ---  heckerr [Sep 3, 2013 3:53:46 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.21 2013/09/03 15:14:51CEST Hecker, Robert (heckerr)
Updated Hpc Dokumentation for User-API.
--- Added comments ---  heckerr [Sep 3, 2013 3:14:51 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.20 2013/08/05 15:56:47CEST Hecker, Robert (heckerr)
Removed some pylint errors.
Revision 1.19 2013/08/05 10:30:25CEST Hecker, Robert (heckerr)
HPC support for different TaskFactories in one Job.
--- Added comments ---  heckerr [Aug 5, 2013 10:30:26 AM CEST]
Change Package : 192625:1 http://mks-psad:7002/im/viewissue?selection=192625
Revision 1.18 2013/07/09 08:30:34CEST Hecker, Robert (heckerr)
Get xml Interface working again.
--- Added comments ---  heckerr [Jul 9, 2013 8:30:34 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.17 2013/07/01 08:52:33CEST Hecker, Robert (heckerr)
Added JobXML Support for Hpc.
--- Added comments ---  heckerr [Jul 1, 2013 8:52:33 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.16 2013/05/24 10:29:37CEST Hecker, Robert (heckerr)
Updated param type checking.
Revision 1.15 2013/05/16 08:04:50CEST Hecker, Robert (heckerr)
Added Subtask support to HPC Job Creation.
--- Added comments ---  heckerr [May 16, 2013 8:04:50 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.14 2013/05/02 15:11:25CEST Hecker, Robert (heckerr)
Added support for global data folder.
--- Added comments ---  heckerr [May 2, 2013 3:11:25 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.13 2013/03/28 14:43:06CET Mertens, Sven (uidv7805)
pylint: resolving some R0904, R0913, R0914, W0107
--- Added comments ---  uidv7805 [Mar 28, 2013 2:43:06 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.12 2013/03/22 08:24:27CET Mertens, Sven (uidv7805)
aligning bulk of files again for peping 8
Revision 1.11 2013/03/20 18:24:37CET Hecker, Robert (heckerr)
Removed pep8 Message.
--- Added comments ---  heckerr [Mar 20, 2013 6:24:37 PM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.10 2013/03/04 17:41:52CET Hospes, Gerd-Joachim (uidv8815)
add env var MPLCONFIGDIR for temp. dir of matplot used by img.plot
--- Added comments ---  uidv8815 [Mar 4, 2013 5:41:52 PM CET]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.9 2013/02/28 16:24:53CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguide.
--- Added comments ---  heckerr [Feb 28, 2013 4:24:53 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.8 2013/02/11 15:08:13CET Hecker, Robert (heckerr)
Removed duplicated code in CreateTask Method.
Setup new Method _CreateTask.
New Method used from TaskFactory and TaskFactoryMTS.
--- Added comments ---  heckerr [Feb 11, 2013 3:08:13 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2013/02/07 17:13:24CET Hecker, Robert (heckerr)
Removed unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:13:24 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/01/23 07:56:34CET Hecker, Robert (heckerr)
Updated epydoc docu.
--- Added comments ---  heckerr [Jan 23, 2013 7:56:35 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2012/12/14 16:22:45CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:46 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/14 12:59:57CET Hecker, Robert (heckerr)
Added Support for dependencies of Tasks.
--- Added comments ---  heckerr [Dec 14, 2012 12:59:57 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/10 17:37:44CET Hecker, Robert (heckerr)
Modified Code to Support OracleMasterDB.
--- Added comments ---  heckerr [Dec 10, 2012 5:37:45 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:50CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:50 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:36:20CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
