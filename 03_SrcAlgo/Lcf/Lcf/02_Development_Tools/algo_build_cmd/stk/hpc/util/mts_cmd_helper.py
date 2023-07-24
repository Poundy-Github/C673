# -*- coding: iso-8859-1 -*-
"""
mts_cmd_helper.py
-----------------

Module which helps to handle MTS Configuration for HPC.

Features:
 -

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:43CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import sys

# Import STK Modules ----------------------------------------------------------
import cmd_cfg as CmdCfg

# Import Local Python Modules -------------------------------------------------

# Functions -------------------------------------------------------------------


def GetMtsStdCMD(UseEOE=False):

    CMDList = []

    CMDList.append(['d:\\data\\%JobName%\\1_Input\\mts_system\\measapp.exe',
                   CmdCfg.STATIC])
    CMDList.append(['-norestart', CmdCfg.STATIC])

    if(UseEOE is True):
        CMDList.append(['-eoe', CmdCfg.STATIC])

    CMDList.append(['-silent', CmdCfg.STATIC])
    CMDList.append(['-pal', CmdCfg.STATIC])
    CMDList.append(['-eab', CmdCfg.STATIC])
    CMDList.append(['-pc%CfgPath%', CmdCfg.STATIC])
    CMDList.append(['-lc%CfgName%', CmdCfg.STATIC])
    CMDList.append(['-pl' + 'd:\\data\\%JobName%\\2_Output\\%TaskName%\\log',
                   CmdCfg.STATIC])
    CMDList.append(['-lr%RecFile%', CmdCfg.DYNAMIC])

    return CMDList


def GetMtsStdCMDBpl():

    CMDList = []

    CMDList.append(['d:\\data\\%JobName%\\1_Input\\mts_system\\measapp.exe',
                   CmdCfg.STATIC])
    CMDList.append(['-norestart', CmdCfg.STATIC])
    CMDList.append(['-silent', CmdCfg.STATIC])
    CMDList.append(['-pal', CmdCfg.STATIC])
    CMDList.append(['-eab', CmdCfg.STATIC])
    CMDList.append(['-pc%CfgPath%', CmdCfg.STATIC])
    CMDList.append(['-lc%CfgName%', CmdCfg.STATIC])
    CMDList.append(['-pl' + 'd:\\data\\%JobName%\\2_Output\\%TaskName%\\log',
                   CmdCfg.STATIC])
    CMDList.append(['-lb%BatchFile%', CmdCfg.STATIC])

    return CMDList


def SetRecFilePath(CMDList, RecFilePath):
    OutList = []
    for el in CMDList:
        if(el[0].find('%RecFile%') != -1):
            tmp = el[0].replace('%RecFile%', RecFilePath)
            OutList.append([tmp, el[1]])
        else:
            OutList.append([el[0], el[1]])

    return OutList


def SetBplFilePath(CMDList, BplFilePath):
    OutList = []
    for el in CMDList:
        if(el[0].find('%BatchFile%') != -1):
            tmp = el[0].replace('%BatchFile%', BplFilePath)
            OutList.append([tmp, el[1]])
        else:
            OutList.append([el[0], el[1]])

    return OutList


def SetJobFolderName(CMDList, JobFolderName):
    OutList = []
    for el in CMDList:
        if(el[0].find('%JobName%') != -1):
            tmp = el[0].replace('%JobName%', JobFolderName)
            OutList.append([tmp, el[1]])
        else:
            OutList.append([el[0], el[1]])

    return OutList


def SetLogFolder(CMDList, LogFolder):
    OutList = []
    for el in CMDList:
        if(el[0].find('%LogFolder%') != -1):
            tmp = el[0].replace('%LogFolder%', LogFolder)
            OutList.append([tmp, el[1]])
        else:
            OutList.append([el[0], el[1]])

    return OutList


def SetConfigPath(CMDList, ConfigPath):
    OutList = []
    for el in CMDList:
        if(el[0].find('%CfgPath%') != -1):
            tmp = el[0].replace('%CfgPath%', ConfigPath)
            OutList.append([tmp, el[1]])
        else:
            OutList.append([el[0], el[1]])

    return OutList


def SetConfigFileName(CMDList, ConfigFileName):
    OutList = []
    for el in CMDList:
        if(el[0].find('%CfgName%') != -1):
            tmp = el[0].replace('%CfgName%', ConfigFileName)
            OutList.append([tmp, el[1]])
        else:
            OutList.append([el[0], el[1]])

    return OutList


def AppendDataFolder(CMDList, DataFolder):
    CMDList.append(['-pd' + DataFolder, CmdCfg.STATIC])

    return CMDList


"""
CHANGE LOG:
-----------
$Log: mts_cmd_helper.py  $
Revision 1.1 2021/12/13 17:57:43CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/util/project.pj
Revision 1.7 2013/10/30 09:36:55CET Hecker, Robert (heckerr) 
Added coding settings.
- Added comments -  heckerr [Oct 30, 2013 9:36:55 AM CET]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.6 2013/09/25 09:02:40CEST Hecker, Robert (heckerr) 
Reverted changes from Günther. Wrong checkin.
--- Added comments ---  heckerr [Sep 25, 2013 9:02:40 AM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.5 2013/09/24 12:25:47CEST Raedler, Guenther (uidt9430)
- updated imports according the new structure
--- Added comments ---  uidt9430 [Sep 24, 2013 12:25:47 PM CEST]
Change Package : 198327:1 http://mks-psad:7002/im/viewissue?selection=198327
Revision 1.4 2013/02/07 17:18:37CET Hecker, Robert (heckerr)
Removed unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:18:37 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/14 16:22:47CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:48 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:51CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:51 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:53:15CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
