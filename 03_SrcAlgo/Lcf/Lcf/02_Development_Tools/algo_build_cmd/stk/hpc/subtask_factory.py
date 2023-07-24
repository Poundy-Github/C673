"""
stk/hpc/subtask_factory
-----------------------

SubTaskFactory Module for Hpc.

**User-API Interfaces**

    - `stk.hpc` (complete package)
    - `SubTaskFactory` (this module)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:03CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import pickle

# Import STK Modules ----------------------------------------------------------
import util.cmd_cfg as CmdCfg
from . error import HpcError

# Defines ---------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class CmdHelper(object):
    def __init__(self):
        self.cmd = ""
        self.cmdVarList = {}

    def SetCMD(self, cmd):
        self.cmd = cmd

    def GetCmdList(self):
        return CmdCfg.ArgToList2(self.cmd)

    def GetCmdVarList(self):
        return self.cmdVarList


class SubTaskFactory(object):
    """
    - Specialized class for creating Hpc SubTasks which are based on "nomal" commandline call.
    - Typicall usage is first to set all information, which is the same for all Tasks. (environmentvariables, workingdir, ....)
    - After that, multiple calls of the "CreateTask" - for the real Task creation.

    :author:        Robert Hecker
    :date:          16.04.2012
    """
    def __init__(self, hpc):
        self.hpc = hpc
        self.currentWorkDir = ""
        self.enVars = []
        self.nodeFolders = []
        self.appWatcher = True
        self.useGlobalDataFolder = False
        self.counter = 1
        self._firstRun = True
        self.subTaskSettingsId = 0
        self.actualCMDMapping = {}

    def _CreateTaskName(self):
        name = "S%05d" % self.counter
        self.counter += 1
        return name

    def _GetNetJobPath(self):
        return self.hpc.PrjHdl.GetNetJobPath()

    def _CreateTask(self, cmdHelper):
        """
        Base Functionality for creating a new Task

        Due the fact, that HPC is only capable to use 480 Characters
        for the max. Comand Line length, single CommandLine Argumets
        can be marked as static. This static Command Line Arguments
        will be stored to file, to save characters for the
        Normal Command Line of HPC.

        :param CMDLine:    List of CommandLine Arguments

        :author:           Robert Hecker
        """

        # Write the complete SubTask-Settings into the HPC-Database
        if(self._firstRun):

            enVars = pickle.dumps(self.enVars)
            nodeFolders = pickle.dumps(self.nodeFolders)

            self.subTaskSettingsId = self.hpc.JobDB.add_subtask_settings(self.currentWorkDir, enVars, nodeFolders,
                                                                         self.appWatcher, self.useGlobalDataFolder)

            self._firstRun = False

        # Create TaskName with Unique TaskCounter
        name = self._CreateTaskName()

        # Write all new CMDLineVars
        cmdVarList = cmdHelper.GetCmdVarList()
        for key in cmdVarList:
            if(cmdVarList[key][1] == 1):
                # Found updated item -> write to DB
                cmdvarid = self.hpc.JobDB.add_cmdvar(key, cmdVarList[key][0])
                self.actualCMDMapping[key] = cmdvarid
                cmdVarList[key][1] = 0

        # Create correct Mapping entry
        mapping_id = self.hpc.JobDB.add_mapping(self.actualCMDMapping)

        # Create the SubTask
        subtaskid = self.hpc.JobDB.add_subtask(name, pickle.dumps(cmdHelper.GetCmdList()),
                                              self.subTaskSettingsId, mapping_id)

        return subtaskid

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
        self.currentWorkDir = workingDir

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
        self.enVars.append([key, value])

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
        self.nodeFolders.append(folder)

    def ActivateAppWatcher(self, value):
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
        self.appWatcher = value

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
        self.useGlobalDataFolder = value

    def CreateTask(self, cmd):
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

        return self._CreateTask(cmdHelper)

"""
CHANGE LOG:
-----------
$Log: subtask_factory.py  $
Revision 1.1 2021/12/13 17:57:03CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/project.pj
Revision 1.11 2013/09/17 16:21:59CEST Hecker, Robert (heckerr) 
Adapted to new internal structure.
- Added comments -  heckerr [Sep 17, 2013 4:21:59 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.10 2013/09/13 16:51:58CEST Hecker, Robert (heckerr) 
Dervided HPCError Exception handling class from StkError base exception.
--- Added comments ---  heckerr [Sep 13, 2013 4:51:58 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.9 2013/09/11 13:59:23CEST Hecker, Robert (heckerr)
- Added Docu.
- Removed some pylint Issues.
--- Added comments ---  heckerr [Sep 11, 2013 1:59:23 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.8 2013/09/05 11:44:39CEST Hecker, Robert (heckerr)
Replaced Exception with HpcError Exception class.
--- Added comments ---  heckerr [Sep 5, 2013 11:44:39 AM CEST]
Change Package : 196378:1 http://mks-psad:7002/im/viewissue?selection=196378
Revision 1.7 2013/09/03 16:12:09CEST Hecker, Robert (heckerr)
Updated Module Header once more....
--- Added comments ---  heckerr [Sep 3, 2013 4:12:10 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.6 2013/09/03 15:53:44CEST Hecker, Robert (heckerr)
Updated Module Header to link also to the Main Package.
--- Added comments ---  heckerr [Sep 3, 2013 3:53:44 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.5 2013/09/03 15:14:48CEST Hecker, Robert (heckerr)
Updated Hpc Dokumentation for User-API.
--- Added comments ---  heckerr [Sep 3, 2013 3:14:48 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.4 2013/08/09 11:23:45CEST Hecker, Robert (heckerr)
BugFix: Renamed hidden internal member variable.
--- Added comments ---  heckerr [Aug 9, 2013 11:23:45 AM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.3 2013/08/08 11:16:03CEST Hecker, Robert (heckerr)
BugFix.
--- Added comments ---  heckerr [Aug 8, 2013 11:16:03 AM CEST]
Change Package : 192377:1 http://mks-psad:7002/im/viewissue?selection=192377
Revision 1.2 2013/08/05 10:29:16CEST Hecker, Robert (heckerr)
Bug Fix in member name.
--- Added comments ---  heckerr [Aug 5, 2013 10:29:16 AM CEST]
Change Package : 192625:1 http://mks-psad:7002/im/viewissue?selection=192625
Revision 1.1 2013/05/16 08:06:06CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
