"""
stk/hpc/task_factory_mts
------------------------

TaskFactoryMTS Module for Hpc.

**User-API Interfaces**

    - `stk.hpc` (complete package)
    - `TaskFactoryMTS` (this module)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:03CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import shutil

# Import STK Modules ----------------------------------------------------------
from . task_factory import TaskFactory
from . subtask_factory_mts import SubTaskFactoryMTS

# Defines ---------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class TaskFactoryMTS(TaskFactory):
    """
    - Specialized class for creating Hpc Tasks which run out MTS.
    - Typicall usage is first to set all information, which is the same for all Tasks.
      (SetConfigFolder,SetConfigFile,...)
    - After that, multiple calls of the "CreateTask" - for the real MTS-Task creation.
    - This class is derived from the `TaskFactory`, this means all methods from there can also be used.

    :author:        Robert Hecker
    :date:          16.04.2012
    """

    def __init__(self, hpc, configFile='mtsapp.cfg'):

        TaskFactory.__init__(self, hpc, configFile)

        self.__subTaskFactoryMTS = SubTaskFactoryMTS(hpc)

    def _CreateFinalTaskName(self, taskId):
        return "F%05d" % taskId

    def SetAppPath(self, appPath="d:\\data\\%JobName%\\1_Input\\mts_system\\measapp.exe"):
        """
        Provide the possibility to set the path to the measapp.exe to the correct one, if
        the default path can't be used.

        :note: %JobName% will be replaced with the real JobName.

        :param appPath:    Absolute path to the measapp.exe, which is used to start the Task.
        :type appPath:     string

        :author:           Robert Hecker
        """
        self.__subTaskFactoryMTS.SetAppPath(appPath)

    def SetConfigFolder(self, folder):
        """
        Set the folder, where MTS will find the given config file.
        This folder will also be used, if you have multiple configuration, which depends via a relative
        path from each other. So this Folder will also be used as the base config folder to resolve
        the relative paths to other given config files.

        :param folder:    path to the base config folder.
        :type folder:     string

        :author:          Robert Hecker
        """
        self.__subTaskFactoryMTS.SetConfigFolder(folder)

    def SetConfigFileName(self, fileName):
        """
        Set the config file name, which shall be used by MTS.
        This FileName can also contain a relative path to the config file, if the Base Config Folder feature is needed.
        Please see also `TaskFactoryMTS.SetConfigFolder`

        :param fileName:    Name of Config File or relative path to config file.
        :type fileName:     string

        :author:            Robert Hecker
        """
        self.__subTaskFactoryMTS.SetConfigFileName(fileName)

    def SetDataFolder(self, dataFolder):
        """
        Set the output data folder for MTS.

        Typicall the Data Folder will be set to the local or to the global folder::

        - local: "d:\\data\\%JobName%\\2_Output\\%TaskName%\\data"
        - global: "d:\\data\\%JobName%\\2_Output\\_data"

        :note: When using the global Data Folder, the Job must be configured with
               JobUnitType.Node

        :param dataFolder:   path to the output data folder on the hpc-client.
        :type dataFolder:    string

        :author:              Robert Hecker
        """
        self.__subTaskFactoryMTS.SetDataFolder(dataFolder)

    def CreateTask(self, bplRecFilepath, dependsOn=None, checker=True):
        """
        Set the correct RecFilePath for the Task and
        Create the Task for the Job.

        :param bplRecFilepath:   Bpl or Rec File URL which must be used for MTS.
                                 Type depends on initializer mode ('rec', 'bpl').
        :type bplRecFilepath:    string
        :param dependsOn:        list of TaskNames
        :type dependsOn:         list of strings
        :param checker:          Enables a second SubTask which checks the MTS Output (xlog, crash)
        :type checker:           boolean

        :note:                   When param is a RecFilePath:
                                 The paths to the single rec files should not contain the
                                 server "\\LIFS010S", just use "\\LIFS010"
                                 On hpc, the extension "S" will be added automatically.

        :author:                 Robert Hecker
        """
        # Create the SubTask for MTS
        subtasklist = self.__subTaskFactoryMTS.CreateTask(bplRecFilepath, checker)

        return self._CreateTaskWithSubtask(subtasklist, dependsOn)

    def CreateFinalTask(self, checkFolder='', genStatFiles=False):
        """
        Create the Last Task from the Job, which will be executed, when all
        other Tasks are finished, with the DependsOn Feature.
        This Task can be used to collect execution information about all other
        Tasks which run before.

        :param CheckFolder:   Value
        :param GenStatFiles:  Value

        :author:           Robert Hecker
        """
        path = os.path.join(self.Hpc.PrjHdl.GetNetJobInPath(), 'stk')
        if not(os.path.isdir(path)):
            # Copy stk
            self.Hpc.CopySTKFolder()

        # Create Task
        task = self.Hpc.Job.CreateTask()
        task.Name = self._CreateFinalTaskName(task.TaskId)

        if(checkFolder == ''):
            task.DependsOn = self._TaskNameList

        # Add Task to Job
        self.Hpc.Job.AddTask(task)

        tmp = self.Hpc.PrjHdl.GetClientJobOutPath()
        outFolder = os.path.join(tmp, task.Name)
        tmp = self.Hpc.PrjHdl.GetNetJobOutPath()
        networkFolder = os.path.join(tmp, task.Name)

        if(checkFolder == ''):
            checkFolder = self.Hpc.PrjHdl.GetNetJobOutPath()

        options = "-c -i" + checkFolder + " -o" + outFolder
        options += " -p -m -d" + networkFolder

        if genStatFiles:
            options += " -j{0}".format(self.Hpc.Job.Id)

        cmdLine = os.path.join(self.Hpc.PrjHdl.GetNetJobInPath(),
                               "mts_final_check.py " + options)
        # Replace \\LIFS010 with LIFS010S
        cmdLine = cmdLine.replace('LIFS010.', 'LIFS010S.')

        # Set all needed Task Informations
        task.CommandLine = cmdLine
        task.WorkDirectory = self.Hpc.PrjHdl.GetClientJobInPath()
        task.Commit()

    def CopyMTSFolders(self, mtsSysFolderName=r'.\mts_system',
                       mtsMeasureFolderName=r'.\mts_measurement',
                       useFilter=True):
        """
        Copy MTS folders from default (or given) directories and
        omit the debug files *.pdb and the mts subfolders that are
        not needed in offline simulation

        :param UseFilter:            optional to deactivate ignore filter
        :param MTSSysFolderName:     optional path to mts_sys folder
        :param MTSMeasureFolderName: optional path to mts_measurement folder

        :author:    Joachim Hospes
        """
        if useFilter:
            mtsfilter = shutil.ignore_patterns('*.pdb',
                                               'doc', 'lib', 'include',
                                               'mi4_system_driver',
                                               'MTSV2AppWizard')
        else:
            mtsfilter = None
        net_job_folder = self.Hpc.PrjHdl.GetNetJobInPath()
        src = os.path.abspath(mtsSysFolderName)
        if os.path.exists(src):
            dest = os.path.join(net_job_folder, 'mts_system')
            shutil.copytree(src, dest, ignore=mtsfilter)
        else:
            errmsg = "can't find path '" + mtsSysFolderName + "'"
            raise ValueError(errmsg)
        src = os.path.abspath(mtsMeasureFolderName)
        if os.path.exists(src):
            dest = os.path.join(net_job_folder, 'mts_measurement')
            shutil.copytree(src, dest, ignore=mtsfilter)
        else:
            errmsg = "can't find path '" + mtsMeasureFolderName + "'"
            raise ValueError(errmsg)
        return


"""
CHANGE LOG:
-----------
$Log: task_factory_mts.py  $
Revision 1.1 2021/12/13 17:57:03CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/project.pj
Revision 1.25 2013/12/12 14:05:23CET Hecker, Robert (heckerr) 
Added mts_checker Functionality to TaskFactoryMTS and SubTaskFactoryMTS.
- Added comments -  heckerr [Dec 12, 2013 2:05:23 PM CET]
Change Package : 210873:1 http://mks-psad:7002/im/viewissue?selection=210873
Revision 1.24 2013/09/17 16:22:34CEST Hecker, Robert (heckerr)
Adapted to new internal structure.
--- Added comments ---  heckerr [Sep 17, 2013 4:22:35 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.23 2013/09/13 16:51:58CEST Hecker, Robert (heckerr)
Dervided HPCError Exception handling class from StkError base exception.
--- Added comments ---  heckerr [Sep 13, 2013 4:51:58 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.22 2013/09/13 11:54:07CEST Hecker, Robert (heckerr)
Updated docu and pep8/pylint issues.
--- Added comments ---  heckerr [Sep 13, 2013 11:54:07 AM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.21 2013/09/06 14:59:48CEST Hecker, Robert (heckerr)
Added more detailed docu.
--- Added comments ---  heckerr [Sep 6, 2013 2:59:49 PM CEST]
Change Package : 193310:1 http://mks-psad:7002/im/viewissue?selection=193310
Revision 1.20 2013/09/06 13:21:53CEST Hecker, Robert (heckerr)
Updated docu, to link to old method UseGlobalDataFolder()
--- Added comments ---  heckerr [Sep 6, 2013 1:21:54 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.19 2013/09/05 11:44:38CEST Hecker, Robert (heckerr)
Replaced Exception with HpcError Exception class.
--- Added comments ---  heckerr [Sep 5, 2013 11:44:39 AM CEST]
Change Package : 196378:1 http://mks-psad:7002/im/viewissue?selection=196378
Revision 1.18 2013/09/03 16:12:09CEST Hecker, Robert (heckerr)
Updated Module Header once more....
--- Added comments ---  heckerr [Sep 3, 2013 4:12:09 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.17 2013/09/03 15:53:43CEST Hecker, Robert (heckerr)
Updated Module Header to link also to the Main Package.
--- Added comments ---  heckerr [Sep 3, 2013 3:53:43 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.16 2013/09/03 15:14:47CEST Hecker, Robert (heckerr)
Updated Hpc Dokumentation for User-API.
--- Added comments ---  heckerr [Sep 3, 2013 3:14:47 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.15 2013/08/08 08:49:10CEST Hecker, Robert (heckerr)
Added bpl Support to Taskfactory.
--- Added comments ---  heckerr [Aug 8, 2013 8:49:11 AM CEST]
Change Package : 192878:1 http://mks-psad:7002/im/viewissue?selection=192878
Revision 1.14 2013/07/12 13:44:02CEST Hecker, Robert (heckerr)
Moved the copy of mts_final_check.py to the Hpc() Class.
--- Added comments ---  heckerr [Jul 12, 2013 1:44:02 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.13 2013/06/25 13:22:24CEST Zechner, Stefan (uidt9253)
- bpl mode for CreateTask(). Calling each MTS task by a play list
--- Added comments ---  uidt9253 [Jun 25, 2013 1:22:24 PM CEST]
Change Package : 162889:30 http://mks-psad:7002/im/viewissue?selection=162889
Revision 1.12 2013/05/24 10:29:36CEST Hecker, Robert (heckerr)
Updated param type checking.
--- Added comments ---  heckerr [May 24, 2013 10:29:36 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.11 2013/05/23 17:07:28CEST Raedler, Guenther (uidt9430)
- added support of subtasks
- fixed error when requesting the job id
--- Added comments ---  uidt9430 [May 23, 2013 5:07:28 PM CEST]
Change Package : 183658:1 http://mks-psad:7002/im/viewissue?selection=183658
Revision 1.10 2013/04/16 11:24:43CEST Hecker, Robert (heckerr)
Needed a Method to set the path to mts
--- Added comments ---  heckerr [Apr 16, 2013 11:24:44 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/02/28 16:31:33CET Hecker, Robert (heckerr)
Updates regarding Pep8.
--- Added comments ---  heckerr [Feb 28, 2013 4:31:34 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.8 2013/02/11 15:08:12CET Hecker, Robert (heckerr)
Removed duplicated code in CreateTask Method.
Setup new Method _CreateTask.
New Method used from TaskFactory and TaskFactoryMTS.
--- Added comments ---  heckerr [Feb 11, 2013 3:08:12 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2013/02/07 17:12:50CET Hecker, Robert (heckerr)
Removed unused Code, BugFix in using variable.
--- Added comments ---  heckerr [Feb 7, 2013 5:12:51 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/01/23 07:56:32CET Hecker, Robert (heckerr)
Updated epydoc docu.
--- Added comments ---  heckerr [Jan 23, 2013 7:56:32 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2012/12/14 16:22:47CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:47 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/13 09:32:00CET Hospes, Gerd-Joachim (uidv8815)
raise and pep8 fixes for CopyMTSFolders
--- Added comments ---  uidv8815 [Dec 13, 2012 9:32:00 AM CET]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.3 2012/12/11 15:54:23CET Hospes, Gerd-Joachim (uidv8815)
add CopyMTSFolders with ignore filter
--- Added comments ---  uidv8815 [Dec 11, 2012 3:54:23 PM CET]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.2 2012/12/05 13:49:46CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:46 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:36:21CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
