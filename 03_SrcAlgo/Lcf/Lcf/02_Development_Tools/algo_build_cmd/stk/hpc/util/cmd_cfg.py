"""
cmd_cfg.py
----------

Module to read/write (static) parameters to a cfg file.
Here the limited number of Parameters from HPC can be extended.
HPC Parameters for Task Creation are limited to 480 Characters.

Features:
 -

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:43CET $
"""
# Import Python Modules -------------------------------------------------------
import re

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------

# Global Variables ------------------------------------------------------------
STATIC = 0
DYNAMIC = 1

# Functions -------------------------------------------------------------------


def ArgToList(cmdline):
    """
    Convert Standard Commandline to ArgumentList, where all Arguments are
    marked as "Dynamic". -> No characters for argument calls are going to
    saved in a seperate Config File, to have more than 480 Characters for
    a CreateTask in HPC available.

    :param cmdline:   Complete CMDLine for a application call
    :type cmdline:    string
    :return:          List of Arguments
    :rtype:           list[[string, int],...]

    :author:          Robert Hecker
    :date:            23.07.2012
    """

    # Parse the CMDLine and Create a List out of it
    arg = []

    bInString = False
    cmd = ''
    for char in cmdline:
        if char == '"':
            bInString = not bInString
        elif char == ' ' and not bInString:
            arg.append([cmd, DYNAMIC])
            cmd = ''
        else:
            cmd += char
    # append at end of line
    if cmd != '':
        arg.append([cmd, DYNAMIC])

    return arg


def ArgToList2(cmdline):
    """
    Convert Standard Commandline to ArgumentList.
    -> No characters for argument calls are going to
    saved in a seperate Config File, to have more than 480 Characters for
    a CreateTask in HPC available.

    :param cmdline:   Complete CMDLine for a application call
    :type cmdline:    sting
    :return:          List of Arguments
    :rtype:           list[string,...]
    :note:            usage : <usage description>   (optional)
    :author:          Robert Hecker
    :date:            13.05.2013
    """

    # Parse the CMDLine and Create a List out of it
    arg = []

    bInString = False
    cmd = ''
    for char in cmdline:
        if char == '"':
            bInString = not bInString
        elif char == ' ' and not bInString:
            arg.append(cmd)
            cmd = ''
        else:
            cmd += char
    # append at end of line
    if cmd != '':
        arg.append(cmd)

    return arg


def GetDynamicCMDList(cmdlist):
    """
    Goes through the comlete InputList, and filter it after
    the dynamic marked items.

    :param cmdlist:   Input List of Commandline parameters
    :type cmdlist:    list[[string, int],...]
    :return:          Filtered Dynamic List
    :rtype:           list[[string, int],...]
    :author:          Robert Hecker
    :date:            13.05.2013
    """
    outlist = []

    for el in cmdlist:
        if(el[1] == DYNAMIC):
            outlist.append(el[0])

    return outlist


class AppCMDList(object):

    __section = re.compile(r'^\[(.*)\]\s*')

    def __init__(self):
        self.cmdlist = []

    def Set(self, cmdlist):
        self.cmdlist = cmdlist

    def Write(self, cfgfile):
        """
        Write a Config File for Arguments to Disk, including the information
        if parameters are DYNAMIC or STATIC.

        :param cfgfile: cfgfile object for the output file
        :type cfgfile:  object of type file

        :author:          Robert Hecker
        :date:            23.07.2012
        """
        # replacement for fast server connection
        replacements = (('\\\\LIFS010.', '\\\\LIFS010S.'),
                        ('\\\\LIFS010\\', '\\\\LIFS010S\\'))
        for cmd in self.cmdlist:
            for repl in replacements:
                regexp = re.compile(re.escape(repl[0]), re.IGNORECASE)
                cmd[0] = regexp.sub(repl[1].replace('\\', '\\\\'), cmd[0])

        cfgfile.write('[AppCmdList]\n')

        for i in self.cmdlist:
            if(i[1] == STATIC):
                cfgfile.write('s ')
                cfgfile.write(i[0])
                cfgfile.write('\n')
            else:
                cfgfile.write('d ')
                cfgfile.write(i[0])
                cfgfile.write('\n')

    def Read(self, CfgFilePath):

        self.cmdlist = []
        CheckContent = False

        # Open Config File for Reading
        f = file(CfgFilePath, 'r')

        for line in f:
            if(line.find('[AppCmdList]') != -1):
                CheckContent = True
            else:
                matchObj = self.__section.match(line)
                if(matchObj is not None):
                    CheckContent = False

                if(CheckContent is True):
                    el1 = line[2:-1]
                    if(line[:2] == 's '):
                        el2 = STATIC
                    else:
                        el2 = DYNAMIC
                    self.cmdlist.append([el1, el2])

        f.close()

    def replace(self, old, new):

        OutList = []
        for entry in self.cmdlist:
            OutList.append([entry[0].replace(old, new), entry[1]])
        self.cmdlist = OutList

    def Get(self):
        return self.cmdlist

    def GetFinalArgList(self, dynamic_cmdlist):
        arglist = []
        i = 0

        if(len(self.cmdlist) > 0):
            # Go through the whole static CMDList, and
            # Replace every dynamic entry in the List with the correct one.
            for entry in self.cmdlist:
                if(entry[1] == STATIC):
                    arglist.append(entry[0])
                else:
                    arglist.append(dynamic_cmdlist[i])
                    i += 1
        else:
            arglist = dynamic_cmdlist

        return arglist


class TaskFolderList(object):

    __section = re.compile(r'^\[(.*)\]\s*')

    def __init__(self):
        self.taskfolderlist = []

    def Append(self, TaskFolder):
        self.taskfolderlist.append(TaskFolder)

    def Write(self, f):
        f.write('[TaskFolderList]\n')

        for el in self.taskfolderlist:
            f.write(el)
            f.write('\n')

    def Read(self, FilePath):

        self.taskfolderlist = []
        f = file(FilePath, 'r')
        checkcontent = False

        for line in f:
            if(line.find('[TaskFolderList]') != -1):
                checkcontent = True
            else:
                matchObj = self.__section.match(line)
                if(matchObj is not None):
                    checkcontent = False

                if(checkcontent is True):
                    self.taskfolderlist.append(line[0:len(line) - 1])

    def Get(self):
        return self.taskfolderlist


class EnvironmentVarList(object):

    __section = re.compile(r'^\[(.*)\]\s*')

    def __init__(self):
        self.TaskFolderList = []

    def Append(self, TaskFolder):
        self.TaskFolderList.append(TaskFolder)

    def Write(self, file_obj):
        file_obj.write('[EnvironmentVariablesList]\n')

        for el in self.TaskFolderList:
            file_obj.write(el)
            file_obj.write('\n')

    def Read(self, FilePath):

        self.TaskFolderList = []
        file_obj = file(FilePath, 'r')
        CheckContent = False

        for line in file_obj:
            if(line.find('[EnvironmentVariablesList]') != -1):
                CheckContent = True
            else:
                matchObj = self.__section.match(line)
                if(matchObj is not None):
                    CheckContent = False

                if(CheckContent is True):
                    self.TaskFolderList.append(line[0:len(line) - 1])

    def Get(self):
        return self.TaskFolderList


class GlobalSettingsList(object):

    __section = re.compile(r'^\[(.*)\]\s*')

    def __init__(self):
        self.GlobalSettingsList = []

    def UseGlobal_DataFolder(self, value=True):
        tmp = 'Global_Data_Usage = '
        if(value is True):
            tmp = tmp + 'True'
        else:
            tmp = tmp + 'False'

        self.GlobalSettingsList.append(tmp)

    def UseMasterOracleDB(self, value=True):
        tmp = 'MasterOracleDB = '
        if(value is True):
            tmp = tmp + 'True'
        else:
            tmp = tmp + 'False'

        self.GlobalSettingsList.append(tmp)

    def Write(self, file_obj):
        file_obj.write('[GlobalSettings]\n')

        for el in self.GlobalSettingsList:
            file_obj.write(el)
            file_obj.write('\n')

    def Read(self, FilePath):

        self.GlobalSettingsList = []
        f = file(FilePath, 'r')
        CheckContent = False

        for line in f:
            if(line.find('[GlobalSettings]') != -1):
                CheckContent = True
            else:
                matchObj = self.__section.match(line)
                if(matchObj is not None):
                    CheckContent = False

                if(CheckContent is True):
                    self.GlobalSettingsList.append(line[0:len(line) - 1])

    def Get(self):
        return self.GlobalSettingsList


class CurrentWorkingDir(object):

    __section = re.compile(r'^\[(.*)\]\s*')

    def __init__(self):
        self.CurrentWorkingDir = ""

    def Set(self, value):

        self.CurrentWorkingDir = value

    def Write(self, file_obj):
        file_obj.write('[CurrentWorkingDir]\n')
        file_obj.write(self.CurrentWorkingDir)
        file_obj.write('\n')

    def Read(self, FilePath):

        self.CurrentWorkingDir = []
        file_obj = file(FilePath, 'r')
        CheckContent = False

        for line in file_obj:
            if(line.find('[CurrentWorkingDir]') != -1):
                CheckContent = True
            else:
                matchObj = self.__section.match(line)
                if(matchObj is not None):
                    CheckContent = False

                if(CheckContent is True):
                    self.CurrentWorkingDir = line[0:len(line) - 1]

    def Get(self):
        return self.CurrentWorkingDir

    def replace(self, old, new):
        self.CurrentWorkingDir = self.CurrentWorkingDir.replace(old, new)


class AppWatcher(object):

    __section = re.compile(r'^\[(.*)\]\s*')

    def __init__(self):
        self.appwatcher = True

    def Set(self, value):
        if type(value) == bool:
            self.appwatcher = value

    def Write(self, file_obj):
        file_obj.write('[AppWatcher]\n')
        file_obj.write(str(self.appwatcher))
        file_obj.write('\n')

    def Read(self, FilePath):
        file_obj = file(FilePath, 'r')
        checkcontent = False

        for line in file_obj:
            if(line.find('[AppWatcher]') != -1):
                checkcontent = True
            else:
                matchObj = self.__section.match(line)
                if(matchObj is not None):
                    checkcontent = False

                line = line.replace('\n', '')
                if(checkcontent is True):
                    if(line == 'False'):
                        self.appwatcher = False
                    elif(line == 'True'):
                        self.appwatcher = True

    def Get(self):
        return self.appwatcher


class StaticCMDHelper(object):
    def __init__(self):
        self.Folders = TaskFolderList()
        self.CMDs = AppCMDList()
        self.ENVs = EnvironmentVarList()
        self.Globs = GlobalSettingsList()
        self.CWD = CurrentWorkingDir()
        self.AppWatcher = AppWatcher()

    def Write(self, helperpath_cfg):
        file_obj = file(helperpath_cfg, 'w')
        self.CMDs.Write(file_obj)
        self.Folders.Write(file_obj)
        self.ENVs.Write(file_obj)
        self.Globs.Write(file_obj)
        self.CWD.Write(file_obj)
        self.AppWatcher.Write(file_obj)
        file_obj.close()

    def Read(self, helperpath_cfg):
        self.CMDs.Read(helperpath_cfg)
        self.Folders.Read(helperpath_cfg)
        self.ENVs.Read(helperpath_cfg)
        self.Globs.Read(helperpath_cfg)
        self.CWD.Read(helperpath_cfg)
        self.AppWatcher.Read(helperpath_cfg)


"""
CHANGE LOG:
-----------
$Log: cmd_cfg.py  $
Revision 1.1 2021/12/13 17:57:43CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/util/project.pj
Revision 1.7 2013/09/12 18:18:54CEST Hecker, Robert (heckerr) 
updates regarding pep8 and pylint.
- Added comments -  heckerr [Sep 12, 2013 6:18:54 PM CEST]
Change Package : 196568:1 http://mks-psad:7002/im/viewissue?selection=196568
Revision 1.6 2013/05/16 08:04:50CEST Hecker, Robert (heckerr)
Added Subtask support to HPC Job Creation.
--- Added comments ---  heckerr [May 16, 2013 8:04:50 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.5 2013/03/28 14:43:08CET Mertens, Sven (uidv7805)
pylint: resolving some R0904, R0913, R0914, W0107
--- Added comments ---  uidv7805 [Mar 28, 2013 2:43:08 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/02/07 17:16:42CET Hecker, Robert (heckerr)
REmoved unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:16:43 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/11 14:16:40CET Hecker, Robert (heckerr)
Get OracleMasterDB support working.
--- Added comments ---  heckerr [Dec 11, 2012 2:16:44 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:47CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:48 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:47:50CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
