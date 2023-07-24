"""
stk/hpc/subtask_factory_mts
---------------------------

SubTaskFactoryMTS Module for Hpc.

**User-API Interfaces**

    - `stk.hpc` (complete package)
    - `SubTaskFactoryMTS` (this module)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:02CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import shutil

# Import STK Modules ----------------------------------------------------------
from . subtask_factory import SubTaskFactory
from . error import HpcError

# Defines ---------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class MTSCmdHelper(object):
    """
    Command Helper class which handles all MTS specific commands for the TaskFactoryMTS.

    :author:        Robert Hecker
    :date:          13.09.2012
    """
    def __init__(self):

        self._mode = None
        self.cmdList = []
        self.cmdVarList = {}
        self.cmdVarList['%MeasAppPath%'] = 'd:\\data\\%JobName%\\1_Input\\mts_system\\measapp.exe'

    def __GetMtsStdCMD(self, use_eoe=False):
        """
        Provides the Complete Command Paramter Keys which must be used for standard MTS calls,
        when calling MTS with one *.rec file.

        :param useEOE:  specifiy whether to use EOE Parameter in MTS call or not.
        :type use_eoe:  boolean
        :return:        List of all Command Parameter keys, which must be used.
        :rtype:         list[[string,int],....]

        :author:        Robert Hecker
        :date:          13.09.2012
        """
        cmdList = []

        cmdList.append('%MeasAppPath%')
        cmdList.append('-norestart')

        if(use_eoe):
            cmdList.append('-eoe')

        cmdList.append('-silent')
        cmdList.append('-pal')
        cmdList.append('-eab')
        cmdList.append('-pc%CfgPath%')
        cmdList.append('-lc%CfgName%')
        arg = '-pl' + 'd:\\data\\%JobName%\\2_Output\\%TaskName%\\log'
        cmdList.append(arg)
        cmdList.append('-lr%RecFile%')

        return cmdList

    def __GetMtsStdCMDBpl(self):
        """
        Provides the Complete Command Paramter Keys which must be used for standard MTS calls,
        when calling MTS with one *.bpl file.

        :return:        List of all Command Parameter keys, which must be used.
        :rtype:         list[[string,int],....]

        :author:        Robert Hecker
        :date:          13.09.2012
        """
        cmdList = []

        cmdList.append('%MeasAppPath%')
        cmdList.append('-norestart')
        cmdList.append('-silent')
        cmdList.append('-pal')
        cmdList.append('-eab')
        cmdList.append('-pc%CfgPath%')
        cmdList.append('-lc%CfgName%')
        arg = '-pl' + 'd:\\data\\%JobName%\\2_Output\\%TaskName%\\log'
        cmdList.append(arg)
        cmdList.append('-lb%BatchFile%')

        return cmdList

    def SetAppPath(self, appPath):
        """
        Set the path of the mts application, which is used by hpc to do the calling.
        Path of measapp.exe.
        Following Variables will be resolved automatically:
            - %JobName%
            - %TaskName%

        :param app_path: absolute path to measapp.exe
        :type app_path:  string
        :return:         -

        :author:         Robert Hecker
        :date:           13.09.2012
        """
        self.cmdVarList['%MeasAppPath%'] = appPath

    def SetJobFolderName(self, jobfolder_name):
        """
        Set the job folder name which is used by the Job.

        :param jobfolder_name: Name of the JobFolder
        :type jobfolder_name:  string
        :return:               -

        :author:               Robert Hecker
        :date:                 13.09.2012
        """
        self.cmdVarList['%JobName%'] = jobfolder_name

    def SetRecFilePath(self, recfile_path):
        """
        Set the rec file path parameter for mts.

        :param recfile_path: absolute path to the recfile.
                             typically on LIFS010
        :type recfile_path:  string
        :return:             -

        :author:             Robert Hecker
        :date:               13.09.2012
        """
        if(self._mode == None):
            self._mode = 'rec'

        if(self._mode == 'rec'):
            self.cmdVarList['%RecFile%'] = recfile_path
        else:
            raise Exception('Mode mixing not allowed!')

    def SetBplFilePath(self, bplfile_path):
        """
        Set the bpl file path parameter for mts.

        :param bplfile_path: absolute path to the recfile.
                             typically a subfolder under %JobName%/1_Input
        :type bplfile_path:  string
        :return:             -

        :author:             Robert Hecker
        :date:               13.09.2012
        """
        if(self._mode == None):
            self._mode = 'bpl'

        if(self._mode == 'bpl'):
            self.cmdVarList['%BatchFile%'] = bplfile_path
        else:
            raise HpcError('Mode mixing not allowed!')

    def SetConfigFolder(self, folder):
        """
        Set the config file path parameter for mts.

        :param folder: folder to the mts (*.cfg) file
                       without the filename itself.
        :type folder:  string
        :return:       -

        :author:       Robert Hecker
        :date:         13.09.2012
        """
        self.cmdVarList['%CfgPath%'] = folder

    def SetConfigFileName(self, filename):
        """
        Set the config file name parameter for mts.

        :param filename: name of the mts cfg file, or a
                         relative path to the mts.cfg file
                         based on the config folder parameter.

        :type filename:  string
        :return:         -

        :author:         Robert Hecker
        :date:           13.09.2012
        """
        self.cmdVarList['%CfgName%'] = filename

    def SetDataFolder(self, folder):
        """
        Set the output data folder for MTS.

        Typicall the Data Folder will be set to the local or to the global folder::

        - local: "d:\\data\\%JobName%\\2_Output\\%TaskName%\\data"
        - global: "d:\\data\\%JobName%\\2_Output\\_data"

        :note: When using the global Data Folder, the Job must be configured with
               JobUnitType.Node

        :param folder:   path to the output data folder on the hpc-client.
        :type folder:    string
        :return:       -

        :author:       Robert Hecker
        :date:         13.09.2012
        """
        self.cmdVarList['%DataFolder%'] = folder

    def GetCmdList(self):
        """
        Prepare the whole cmdlist, either for *.bpl or *.rec usage.
        Replace all internal used placeholder with the data given by the user,
        and provide it to the user.

        :return:      cmdlist
        :rtype:       list[[string,int],....]

        :author:       Robert Hecker
        :date:         13.09.2012
        """
        if(self._mode == 'rec'):
            cmdList = self.__GetMtsStdCMD()
        elif(self._mode == 'bpl'):
            cmdList = self.__GetMtsStdCMDBpl()
        else:
            raise HpcError('Mode (rec or bpl) not specified!')

        # Go though the whole dict and replace the placeholder with
        # real Data

        for item in self.cmdVarList:
            list2 = []
            for el in cmdList:
                if(el.find(item) != -1):
                    tmp = el.replace(item, self.cmdVarList[item])
                    list2.append(tmp)
                else:
                    list2.append(el)
            cmdList = list2

        for item in self.cmdVarList:
            list2 = []
            for el in cmdList:
                if(el.find(item) != -1):
                    tmp = el.replace(item, self.cmdVarList[item])
                    list2.append(tmp)
                else:
                    list2.append(el)
            cmdList = list2

        # Check after Append Data Folder, if yes, do it
        if('%DataFolder%' in self.cmdVarList):
            cmdList.append('-pd' + self.cmdVarList['%DataFolder%'])

        return cmdList

    def GetCmdVarList(self):
        return self.cmdVarList


class SubTaskFactoryMTS(SubTaskFactory):
    """
    - Specialized class for creating Hpc SubTasks which run out MTS.
    - Typicall usage is first to set all information, which is the same for all Tasks. (SetConfigFolder,SetConfigFile,...)
    - After that, multiple calls of the "CreateTask" - for the real MTS-Task creation.
    - This class is derived from the `SubTaskFactory`, this means all methods from there can also be used.

    :author:        Robert Hecker
    :date:          16.04.2012
    """
    def __init__(self, hpc):

        SubTaskFactory.__init__(self, hpc)

        self.mtsCmdHelper = MTSCmdHelper()

    def SetAppPath(self, appPath="d:\\data\\%JobName%\\1_Input\\mts_system\\measapp.exe"):
        """
        Provide the possibility to set the path to the measapp.exe to the correct one, if
        the default path can't be used.

        :note: %JobName% will be replaced with the real JobName.

        :param appPath:    Absolute path to the measapp.exe, which is used to start the Task.
        :type appPath:     string

        :author:           Robert Hecker
        """
        self.mtsCmdHelper.SetAppPath(appPath)

    def SetConfigFolder(self, folder):
        """
        Set the folder, where MTS will find the given config file.
        This folder will also be used, if you have multiple configuration, which depends via a relative
        path from each other. So this Folder will also be used as the base config folder to resolve
        the relative paths to other given config files.

        :param folder:    path to the base config folder.
        :type folder:     string

        :author:           Robert Hecker
        """
        tmp = self.hpc.PrjHdl.GetClientJobInPath()
        path = os.path.join(tmp, folder)
        self.mtsCmdHelper.SetConfigFolder(path)

    def SetConfigFileName(self, fileName):
        """
        Set the config file name, which shall be used by MTS.
        This FileName can also contain a relative path to the config file, if the Base Config Folder feature is needed.
        Please see also `SubTaskFactoryMTS.SetConfigFolder`

        :param fileName:    Name of Config File or relative path to config file.
        :type fileName:     string

        :author:           Robert Hecker
        """
        self.mtsCmdHelper.SetConfigFileName(fileName)

    def _SetRecFilePath(self, recFilePath):
        """
        Set the path for the used rec file for a task.

        :param recfilePath:    absolute path to the input RecFile.
        :type recfilePath:     string

        :author:               Robert Hecker
        """
        self.mtsCmdHelper.SetRecFilePath(recFilePath)

    def _SetBplFilePath(self, bplFilePath):
        """
        Set the path for the used *.bpl file for a task.

        :param bplFilePath:   absolute path to the input Batchplaylist.
        :type bplFilePath:    string

        :author:              Robert Hecker
        """
        self.mtsCmdHelper.SetBplFilePath(bplFilePath)

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
        self.mtsCmdHelper.SetDataFolder(dataFolder)

    def CreateTask(self, bplRecFilePath, checker=True):
        """
        Set the correct RecFilePath for the Task and
        Create the Task for the Job.

        :param bplRecFilepath:   Bpl or Rec File URL which must be used for MTS.
                                 Type depends on initializer mode ('rec', 'bpl').
        :type bplRecFilepath:    string
        :param checker:          Enables a second SubTask which checks the MTS Output (xlog, crash)
        :type checker:           boolean

        :note:                   When param is a RecFilePath:
                                 The paths to the single rec files should not contain the
                                 server "\\LIFS010S", just use "\\LIFS010"
                                 On hpc, the extension "S" will be added automatically.


        :author:                 Robert Hecker
        """
        subtasklist = []

        if(bplRecFilePath.endswith('.rec')):
            self._SetRecFilePath(bplRecFilePath)
        elif(bplRecFilePath.endswith('.bpl')):
            self._SetBplFilePath(bplRecFilePath)
        else:
            raise HpcError('Unsupported file Type!')

        subtasklist.append(self._CreateTask(self.mtsCmdHelper))

        if(checker):
            # Create the Checker Subtask
            mtschecker = SubTaskFactory(self.hpc)
            subtasklist.append(mtschecker.CreateTask("d:\\data\\%JobName%\\1_Input\\stk\\cmd\\mts_check.py -m -i d:\\Data\\%JobName%\\2_Output\\%TaskName%"))

        return subtasklist

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
        net_job_folder = self.hpc.PrjHdl.GetNetJobInPath()
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
$Log: subtask_factory_mts.py  $
Revision 1.1 2021/12/13 17:57:02CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/project.pj
Revision 1.11 2013/12/12 14:05:24CET Hecker, Robert (heckerr) 
Added mts_checker Functionality to TaskFactoryMTS and SubTaskFactoryMTS.
- Added comments -  heckerr [Dec 12, 2013 2:05:24 PM CET]
Change Package : 210873:1 http://mks-psad:7002/im/viewissue?selection=210873
Revision 1.10 2013/09/13 16:51:59CEST Hecker, Robert (heckerr)
Dervided HPCError Exception handling class from StkError base exception.
--- Added comments ---  heckerr [Sep 13, 2013 4:51:59 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.9 2013/09/06 14:59:49CEST Hecker, Robert (heckerr)
Added more detailed docu.
--- Added comments ---  heckerr [Sep 6, 2013 2:59:49 PM CEST]
Change Package : 193310:1 http://mks-psad:7002/im/viewissue?selection=193310
Revision 1.8 2013/09/06 13:21:54CEST Hecker, Robert (heckerr)
Updated docu, to link to old method UseGlobalDataFolder()
--- Added comments ---  heckerr [Sep 6, 2013 1:21:54 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.7 2013/09/05 11:44:39CEST Hecker, Robert (heckerr)
Replaced Exception with HpcError Exception class.
--- Added comments ---  heckerr [Sep 5, 2013 11:44:39 AM CEST]
Change Package : 196378:1 http://mks-psad:7002/im/viewissue?selection=196378
Revision 1.6 2013/09/03 16:12:10CEST Hecker, Robert (heckerr)
Updated Module Header once more....
--- Added comments ---  heckerr [Sep 3, 2013 4:12:10 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.5 2013/09/03 15:14:48CEST Hecker, Robert (heckerr)
Updated Hpc Dokumentation for User-API.
--- Added comments ---  heckerr [Sep 3, 2013 3:14:48 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.4 2013/08/08 11:16:02CEST Hecker, Robert (heckerr)
BugFix.
--- Added comments ---  heckerr [Aug 8, 2013 11:16:03 AM CEST]
Change Package : 192377:1 http://mks-psad:7002/im/viewissue?selection=192377
Revision 1.3 2013/08/08 08:50:57CEST Hecker, Robert (heckerr)
Added bpl support to Subtaskfactory.
--- Added comments ---  heckerr [Aug 8, 2013 8:50:57 AM CEST]
Change Package : 192878:1 http://mks-psad:7002/im/viewissue?selection=192878
Revision 1.2 2013/05/29 17:09:47CEST Raedler, Guenther (uidt9430)
- fixed bug with instance name
--- Added comments ---  uidt9430 [May 29, 2013 5:09:47 PM CEST]
Change Package : 184344:1 http://mks-psad:7002/im/viewissue?selection=184344
Revision 1.1 2013/05/16 08:06:06CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
