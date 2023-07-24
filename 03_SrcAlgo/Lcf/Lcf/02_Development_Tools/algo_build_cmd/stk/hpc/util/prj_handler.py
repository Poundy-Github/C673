"""
prj_handler
-----------

documentation of <prj_handler>
docu docu

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:43CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import re

# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------
WORKSTATION_NODE_DATA_PATH = "d:\\data"
INPUT_PATH = "1_Input"
OUTPUT_PATH = "2_Output"
OUTPUT_DATA_PATH = os.path.join(OUTPUT_PATH, "_data")

HPC_SUPPORTED_ARSXXX_PROJECTS = ["ARS301",
                                 "ARS302",
                                 "ARS310",
                                 "ARS315",
                                 "ARS316",
                                 "ARS320",
                                 "ARS321",
                                 "ARS322",
                                 "ARS325",
                                 "ARS327",
                                 "ARS330",
                                 "ARS340",
                                 "ARS341",
                                 "ARS342",
                                 "ARS350",
                                 "ARS351",
                                 "ARS352",
                                 "ARS353",
                                 "ARS355",
                                 "ARS3N0",
                                 "ARS400",
                                 "ARS4B0",
                                 "ARS4D0",
                                 "ARS4D1",
                                 "ARS4D2",
                                 "ARS4L0",
                                 "ARS4L1",
                                 "ARS4T0",
                                 "ARS400PR",
                                 "ARS4A0",
                                 "ARS400PP",
                                 "ARS400EN"]

HPC_SUPPORTED_MFCXXX_PROJECTS = ["MFC310",
                                 "SMFC4B0",
                                 "SRLCAM4T0"]

HPC_SUPPORTED_CSF2XX_PROJECTS = ["CSF289"
                                 "CSF2Y0",
                                 "CSF200",
                                 "CSF201",
                                 "CSF230",
                                 "CSF265",
                                 "CSF288",
                                 "CSF289"]

HPC_SUPPORTED_SRL1XX_PROJECTS = ["SRL1H0",
                                 "SRL1M2",
                                 "SRL1P0",
                                 "SRL171",
                                 "SRL188"]

HPC_SUPPORTED_SMR2XX_PROJECTS = ["SRR2C0",
                                 "SRR2S0",
                                 "SRR2T0",
                                 "SRR265",
                                 "SRR225",
                                 "SRR288"]

# Classes ---------------------------------------------------------------------


class ProjectHandler(object):

    def __init__(self, HeadNode, HPCBaseFolder):

        self.__ShortTestQueue = False
        self.__ProjectName = ''
        self.__JobTemplate = ''
        self.__HPCBaseFolder = HPCBaseFolder
        self.__JobName = ''
        self.__JobId = ''
        servername = re.search(r'....[0-9]+', HeadNode).group()
        self.__HPCFolderName = servername.lower()

    def GetBaseFolder(self):
        return self.__HPCBaseFolder

    def GetProjectName(self):
        return self.__ProjectName

    def GetJobTemplateName(self):
        return self.__JobTemplate

    def GetJobFolderName(self):
        return "%s_%s" % (str(self.__JobId), self.__JobName)

    def GetNetJobPath(self):

        path = None

        # Check if path is local
        if(self.__HPCBaseFolder[0] == 'd' or self.__HPCBaseFolder[0] == 'D'):
            path = os.path.join(self.__HPCBaseFolder, self.GetJobFolderName())
        else:

            if(self.__JobId is not 0 and self.__JobName is not ''):
                path = os.path.join(self.__HPCBaseFolder,
                                    self.__HPCFolderName,
                                    self.GetJobFolderName())
        return os.path.normpath(path)

    def GetClientJobOutPath(self):
        return os.path.join(WORKSTATION_NODE_DATA_PATH,
                            self.GetJobFolderName(), OUTPUT_PATH)

    def GetClientJobInPath(self):
        return os.path.join(WORKSTATION_NODE_DATA_PATH,
                            self.GetJobFolderName(), INPUT_PATH)

    def GetNetJobOutPath(self):
        path = os.path.join(self.GetNetJobPath(), OUTPUT_PATH)
        return os.path.normpath(path)

    def GetNetJobOutDataPath(self):
        path = os.path.join(self.GetNetJobPath(), OUTPUT_DATA_PATH)
        return os.path.normpath(path)

    def GetNetJobInPath(self):
        path = os.path.join(self.GetNetJobPath(), INPUT_PATH)
        return os.path.normpath(path)

    def SetJobId(self, JobId):
        self.__JobId = JobId

    def SetJobName(self, JobName):
        self.__JobName = JobName

    def SetProject(self, ProjectName):
        """
        Set the Project which must be used for the Job
        Only Projects which are stored internaly in a list are valid ones.
        Please Check the whole list in self.__SupportedProjects.
        The Project Name is used for:
            1.) The FolderName, where the Job Input/Output will be stored
            2.) For Job Template Names inside Microsoft HPC

        :param JobName:    MFC310

        :author:           Robert Hecker
        """
        result = 0

        # Check if Keyword Test is included
        if(ProjectName.find('_') != -1):
            if(ProjectName.split('_')[1] == 'Test'):
                # Setup Job in ShortTest Pool
                self.__ShortTestQueue = True
                ProjectName = ProjectName.split('_')[0]

        if(ProjectName in HPC_SUPPORTED_ARSXXX_PROJECTS):
            self.__ProjectName = ProjectName
            if(self.__ShortTestQueue):
                self.__JobTemplate = "ShortTest"
            else:
                self.__JobTemplate = "ARS3xx"
            result = 1
        if(ProjectName in HPC_SUPPORTED_MFCXXX_PROJECTS):
            self.__ProjectName = ProjectName
            if(self.__ShortTestQueue):
                self.__JobTemplate = "ShortTest"
            else:
                self.__JobTemplate = "MFC3xx"
            result = 1
        if(ProjectName in HPC_SUPPORTED_CSF2XX_PROJECTS):
            self.__ProjectName = ProjectName
            if(self.__ShortTestQueue):
                self.__JobTemplate = "ShortTest"
            else:
                self.__JobTemplate = "CSF2xx"
            result = 1
        if(ProjectName in HPC_SUPPORTED_SMR2XX_PROJECTS):
            self.__ProjectName = ProjectName
            if(self.__ShortTestQueue):
                self.__JobTemplate = "ShortTest"
            else:
                self.__JobTemplate = "SMR2xx"
            result = 1
        if(ProjectName in HPC_SUPPORTED_SRL1XX_PROJECTS):
            self.__ProjectName = ProjectName
            if(self.__ShortTestQueue):
                self.__JobTemplate = "ShortTest"
            else:
                self.__JobTemplate = "SRL1xx"
            result = 1
        if(ProjectName == "Admin"):
            self.__ProjectName = "MFC310"
            self.__JobTemplate = "Admin"
            result = 1

        if(result == 0):
            tmp = "ProjectName currently not supported!!! "
            tmp += "Please contact one of the Admins to add "
            tmp += "your project to the HPC system."
            raise tmp

    def CreateNetJobSubFolders(self):

        path = self.GetNetJobPath()

        # Create Base HPC Folder (_HPC006) if necessary.
        if(os.path.isdir(os.path.split(path)[0]) is False):
            os.makedirs(os.path.split(path)[0])

        # Create the needed SubFolders
        os.makedirs(path)
        os.makedirs(os.path.join(path, INPUT_PATH))
        os.makedirs(os.path.join(path, OUTPUT_PATH))
        os.makedirs(os.path.join(path, OUTPUT_DATA_PATH))

        return path

"""
CHANGE LOG:
-----------
$Log: prj_handler.py  $
Revision 1.1 2021/12/13 17:57:43CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/util/project.pj
Revision 1.17 2013/11/08 10:47:58CET Hecker, Robert (heckerr) 
Added Additional ARS Projects.
- Added comments -  heckerr [Nov 8, 2013 10:47:58 AM CET]
Change Package : 205337:1 http://mks-psad:7002/im/viewissue?selection=205337
Revision 1.16 2013/10/22 17:52:27CEST Hecker, Robert (heckerr) 
updates for the new hpc-data share folder on liss006
--- Added comments ---  heckerr [Oct 22, 2013 5:52:28 PM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.15 2013/07/31 18:20:30CEST Hecker, Robert (heckerr) 
Added Project Support for ARS3N0.
--- Added comments ---  heckerr [Jul 31, 2013 6:20:30 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.14 2013/07/08 11:48:42CEST Hecker, Robert (heckerr) 
Some minjor bugfixes.
--- Added comments ---  heckerr [Jul 8, 2013 11:48:42 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.13 2013/07/04 16:19:47CEST Hecker, Robert (heckerr) 
Small BugFix, to get Jenkins working.
--- Added comments ---  heckerr [Jul 4, 2013 4:19:47 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.12 2013/06/27 16:32:44CEST Hecker, Robert (heckerr) 
Extended _HPC FolderName with ServerID.
--- Added comments ---  heckerr [Jun 27, 2013 4:32:44 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.11 2013/05/16 08:04:50CEST Hecker, Robert (heckerr)
Added Subtask support to HPC Job Creation.
--- Added comments ---  heckerr [May 16, 2013 8:04:50 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.10 2013/04/25 13:55:50CEST Hecker, Robert (heckerr)
Added SRLCam as new supported project
--- Added comments ---  heckerr [Apr 25, 2013 1:55:51 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/03/18 10:02:29CET Hecker, Robert (heckerr)
Added support for new Projects.
--- Added comments ---  heckerr [Mar 18, 2013 10:02:29 AM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.8 2013/03/01 09:10:11CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 9:10:11 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.7 2013/02/07 17:20:08CET Hecker, Robert (heckerr)
Removed unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:20:08 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.6 2013/01/25 09:24:47CET Paulig, Ralf (uidt3509)
Extended error message for unsupported projects.
--- Added comments ---  uidt3509 [Jan 25, 2013 9:24:47 AM CET]
Change Package : 162647:7 http://mks-psad:7002/im/viewissue?selection=162647
Revision 1.4 2012/12/14 16:22:47CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:47 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/14 12:58:25CET Hecker, Robert (heckerr)
Added Support for a Admin Resource Pool.
--- Added comments ---  heckerr [Dec 14, 2012 12:58:26 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:51CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:51 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:39:35CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
