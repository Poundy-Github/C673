"""
mts_final_check
---------------

Script to be used as Final Task in HPC to Analyze the whole output from a
MTS Simulation Run. This Script search for MTS Error Entries and Chrashdumps.

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:33CET $
"""
# Import Python Modules -------------------------------------------------------
import os
import sys
import fnmatch
from optparse import OptionParser
from optparse import OptionGroup
from shutil import copy, copyfile
from sqlite3 import connect
from csv import writer
from re import findall

# Add PyLib Folder to System Paths --------------------------------------------
STK_FOLDER = os.path.abspath(os.path.join(os.path.split(__file__)[0], r"..\.."))

if STK_FOLDER not in sys.path:
    sys.path.append(STK_FOLDER)

# Import STK Modules ----------------------------------------------------------
from stk.hpc import Hpc
from stk.hpc.ifc.hpc.task import TaskType, TaskState
from stk.mts.bpl import Bpl, BplListEntry
# Import Local Python Modules -------------------------------------------------

# Classes ---------------------------------------------------------------------


class JobErrorDB:
    """ Database interface for Job Errors (local DB)"""
    def __init__(self):
        self.__connection = None
        self.cursor = None
        return

    def Create(self, FilePath='c:\\test.db'):
        """ Open the DB Connection"""
        self.__connection = connect(FilePath)
        self.cursor = self.__connection.cursor()
        return

    def Commit(self):
        """ Commit changes """
        # Save (commit) the changes
        self.__connection.commit()

    def Close(self):
        """ Close DB connection """
        # We can also close the cursor if we are done with it
        self.__connection.close()

    def CreateMTSChrashTable(self):
        """ Create the Table storing MTS chrashes """
        sql = 'CREATE TABLE MTSChrash (TaskId INTEGER, Filepath char)'
        self.cursor.execute(sql)

    def AddMTSChrashReport(self, TaskId, CrashPath):
        """ Add a new chrash report """
        # Add Entry
        self.cursor.execute('INSERT INTO MTSChrash VALUES (?, ?)',
                            (TaskId, CrashPath))

    def CreateMTSErrorTable(self):
        """ Create the Table storing MTS errors """
        # Create table with MTS Chrashdumps
        sql = 'CREATE TABLE MTSError '
        sql += '(TaskId INTEGER, ErrorPath char, Line char)'
        self.cursor.execute(sql)

    def AddMTSErrorEntry(self, TaskId, ErrorPath, Line):
        """ Add a new error to DB """
        # Add Entry
        self.cursor.execute('INSERT INTO MTSError VALUES (?, ?, ?)',
                            (TaskId, ErrorPath, Line))

    def GetNumChrashs(self, TaskId=None):
        """ Get the number of chrashes """
        query = "SELECT TaskId FROM MTSChrash"
        if TaskId is not None:
            query += " where TaskId='{0}'".format(TaskId)

        self.cursor.execute(query)
        return len(self.cursor.fetchall())

    def GetNumErrors(self, TaskId=None):
        """ Get the number of errors """
        query = "SELECT TaskId FROM MTSError"
        if TaskId is not None:
            query += " where TaskId='{0}'".format(TaskId)

        self.cursor.execute(query)

        return len(self.cursor.fetchall())


def GetTaskId(HpcOutFilePath):
    """ Get the Task ID from the output path name """
    tmp_ = HpcOutFilePath[HpcOutFilePath.find('\\2_Output\\') + 10:]
    tmp_ = tmp_[:tmp_.find('\\')]
    if(tmp_.find('task_') != -1):
        tmp_ = tmp_[5:]
    return str(tmp_)


def find_errors_in_file(db, filepath):
    """ Find Errors in Files  """
    # Open File for Reading
    f = file(filepath)
    # Get TaskId for current FilePath
    TaskId = GetTaskId(filepath)

    # read whole file and process it
    for line_tmp in f:
        # decode and encode from mostly used windows file encoding to
        # standard py-script encoding
        # (line_tmp.decode(SCRIPT_ENCODING)).encode(STRING_TARGET_ENCODING)
        line = line_tmp

        if line.find('Severity=\"Error\"') != -1:
            # print line
            db.AddMTSErrorEntry(TaskId, filepath, line)

    # close file
    f.close()
    # delete file object
    del f


class TaskStatusCheck:
    """ The class support the check functions of a single task

        Features:
            - Generate stat.csv
            - Copy or Generate the BatchPlayList into the output  tassk folder

        :author:        Guenther Raedler
        :date:          02.08.2012
    """
    def __init__(self, DataBasePath, JobID):
        self.__InputFolder = ""
        self.__OutputFolder = ""
        self.__DataBasePath = DataBasePath
        self.__Issues = 0
        self.__JobId = JobID
        self.__db = None
        # init HPC
        self.__hpc = Hpc()

    def GenPlaylist(self, cmd_options, batch_player_file):
        """ Generate the Batch-Playlist File in the output task folder

        If the MTS (measapp.exe) was start with a single recording
        (option -lr), a new playlist file is generated. In the case,
        the MTS was started with a batch play list (option -lb), the
        playlist will be copied from 1_Input folder into the task
        output folder.

        note:          usage : <usage description> (optional)

        :author:        Guenther Raedler
        :date:          02.08.2012
        """
        pattern_rec = r"-lr+[\\\w\.\-]*"
        pattern_bpl = r"-lb+[\\\w\.\-]*"
        matches = findall(pattern_rec, cmd_options)

        for match in matches:
            match = match.replace("-lr", "")

            bpl_writer = Bpl(batch_player_file)
            bpl_writer.append(BplListEntry(str(match)))
            bpl_writer.write()
            return True

        matches = findall(pattern_bpl, cmd_options)
        for match in matches:
            if os.path.isfile(match):
                copyfile(match, batch_player_file)

            return True

        return False

    def GenStatusFiles(self):
        """ Generate Status Files

        read the HPC simulation result, generate the stat.csv files and provide
        batchplaylist in output folder.

        :author:      Guenther Raedler
        :date:        02.08.2012
        :Todo:        Method is not working
                      Using wrong methods vrom Hpc() Class.
        """
        # open the database
        if self.__DataBasePath != "":
            self.__db = JobErrorDB()
            self.__db.Create(self.__DataBasePath)

        self.__hpc.Job = self.__hpc.Scheduler.OpenJob(int(self.__JobId))
        # JobFolder = self.__hpc.GetCurNetJobPath()

        total_tasks = 0
        finished_tasks = 0

        for task in self.__hpc.Job.GetTaskList():
            if task.GetType() == TaskType.Basic:
                total_tasks += 1
                if not task.IsRunning():
                    task_id = task.GetTaskId()
                    task_name = task.GetName()
                    task_cmd = task.GetCommandLine()
                    nw_path = self.__hpc.GetNetworkTaskOutPath(task_id)
                    if os.path.exists(nw_path):
                        folder = self.__hpc.GetNetworkTaskOutPath(task_id)
                        name = self.__hpc.GetNetworkTaskName(task_id) + ".bpl"
                        play_list_filename = os.path.join(folder, name)
                        folder = self.__hpc.GetNetworkTaskOutPath(task_id)
                        name = self.__hpc.GetNetworkTaskName(task_id)
                        name += ".stat.csv"
                        status_log_filename = os.path.join(folder, name)

                        # Set the Playlist in the task output folder
                        self.GenPlaylist(task_cmd, play_list_filename)

                        status_log_file = open(status_log_filename, "wb")
                        status_log_file_writer = writer(status_log_file, delimiter=';')
                        status_log_file_writer.writerow(["JobTaskResult",
                                                        "JobTaskStartTime",
                                                        "JobTaskEndTime",
                                                        "JobTaskRetrieveTime",
                                                        "JobTaskComputerName",
                                                        "JobTaskLogMsg"])

                        ret_val = task.GetState()
                        start_time = task.GetStartTime()
                        end_time = task.GetEndTime()
                        end_retrieve_time = task.GetEndTime()
                        computer_name = ''
                        log_msg = TaskState.STATES_STR[task.GetState()]

                        if(self.__db is not None):
                            num_crashes = self.__db.GetNumChrashs(TaskId=task_name)
                            if(num_crashes > 0):
                                ret_val = 257
                                log_msg = "MTS CrashRep: {0}.".format(num_crashes)
                            num_errors = self.__db.GetNumErrors(task_name)
                            if(num_errors):
                                log_msg += " MTS Errors: {0}".format(num_errors)

                        status_log_file_writer.writerow([ret_val,
                                                        start_time,
                                                        end_time,
                                                        end_retrieve_time,
                                                        computer_name,
                                                        log_msg])
                        status_log_file.close()

                        finished_tasks += 1

        self.__db.Close()
        self.__db = None


class MTSFinalCheck:
    """ MTS Final Check Class"""
    def __init__(self):
        self._InputFolder = ""
        self._OutputFolder = ""
        self._DataBasePath = ""
        self._Issues = 0
        self._Errors = 0
        self._db = None

    def _SearchMTSChrashDumps(self, db, filepath, pattern):
        """ Search for MTS chrash dumbs """
        try:
            # Create Table for MTS ChrashDumps
            db.CreateMTSChrashTable()
        except:
            return -1  # Table Already exist, do Nothing

        i = 0
        for (path_, _, files) in os.walk(filepath):
            # Here we have one match with all subdirs and files in the
            # current path
            # Make a for loop to generate the absolute path for all file
            FileNames = fnmatch.filter(files, pattern)
            for i in FileNames:
                f = os.path.join(path_, i)
                # stdout.write("\r%s" % file)
                TaskId = GetTaskId(f)
                db.AddMTSChrashReport(TaskId, f)
        return 0

    def _SearchXLogErrors(self, db, FilePath):
        """ Search for MTS log files in folder """
        return self._SearchMTSXLogFiles(db, FilePath, '*.xlog')

    def _SearchMTSXLogFiles(self, db, filepath, pattern):
        """ Search for MTS log files in folder """
        try:
            # Create Table for MTS ChrashDumps
            db.CreateMTSErrorTable()
        except:
            return -1

        i = 0
        for (path_, _, files) in os.walk(filepath):
            # Here we have one match with all subdirs and files in the
            # current path
            # Make a for loop to generate the absolute path for all file
            FileNames = fnmatch.filter(files, pattern)
            for i in FileNames:
                f = os.path.join(path_, i)
                # stdout.write("\r%s" % f)
                find_errors_in_file(db, f)
        return 0

    def CheckMTSOutput(self):
        """ Check MTS output """
        # Get JobName from Path
        JobName = self._InputFolder[self._InputFolder.find('_HPC'):]
        JobName = JobName[JobName.find('\\') + 1:]
        if(JobName.find('\\') != -1):
            JobName = JobName[:JobName.find('\\')] + '.db'
        JobName = JobName + '.db'

        DataBasePath = self._OutputFolder + '\\' + JobName
        self._DataBasePath = DataBasePath

        # Check if File exists, and delete
        if(os.path.isfile(self._DataBasePath)):
            os.remove(self._DataBasePath)

        if(os.path.isdir(self._OutputFolder) is False):
            os.makedirs(self._OutputFolder)

        # Create Result Database for all Jobs.
        self._db = JobErrorDB()
        self._db.Create(self._DataBasePath)

        # Search for MTS ChrashDumps
        # Find all Chrashdumps for the specified job.
        Error = self._SearchMTSChrashDumps(self._db, self._InputFolder,
                                           '*crash*.dmp')

        # Search in all log files for Errors and list the Reported Files
        if(Error == 0):
            Error = self._SearchXLogErrors(self._db, self._InputFolder)

        self._db.Commit()

        self._CreateSummaryTable(self._db)

        # Get Number of Issues
        self._Issues = self._db.GetNumChrashs()
        self._Errors = self._db.GetNumErrors()

        self._db.Close()
        self._db = None
        return self._DataBasePath

    def GetNumOfFoundIssues(self):
        """ Get number of founf issues """
        return self._Issues

    def _CreateSummaryTable(self, db):
        """ Create a summary table """
        Error = 0
        # Check if Main Table for Analyze is already created
        try:
            # Create a summary DB for the compressed information
            sql = 'CREATE TABLE Main '
            sql += '(TaskId INTEGER, ChrashDumps integer, XLogErrors integer)'
            self._db.cursor.execute(sql)
        except:
            Error = -1

        if(Error == 0):
            # Check how many Chrash Dumps happend
            errors = {}
            self._db.cursor.execute('SELECT * FROM MTSChrash')
            for row in self._db.cursor:
                TaskId = row[0]
                # Filepath = row[1]
                if TaskId in errors:
                    # Increment Counter
                    errors[TaskId] = [errors[TaskId][0] + 1, errors[TaskId][1]]
                else:
                    # TaskId to dumps
                    errors[TaskId] = [1, 0]

            self._db.cursor.execute('SELECT * FROM MTSError')
            for row in self._db.cursor:
                TaskId = row[0]
                # Filepath = row[1]
                if TaskId in errors:
                    # Increment Counter
                    errors[TaskId] = [errors[TaskId][0], errors[TaskId][1] + 1]
                else:
                    # TaskId to dumps
                    errors[TaskId] = [0, 1]

            # Create a summary DB for the compressed information
            for key in errors:
                self._db.cursor.execute('INSERT INTO Main VALUES (?, ?, ?)',
                                        (key, errors[key][0], errors[key][1]))
            self._db.Commit()

    def GetStatstic(self, FilePath):
        """ Get Statistic """
        # Analyze MTS Chrash Dumps
        self._db = JobErrorDB()

        self._db.Create(FilePath)

        # Print Statistic
        print "\n\nStatistic"
        print "=========="
        print "Chrashdumps:   " + str(self._db.GetNumChrashs())
        print "MTSXLogErrors: " + str(self._db.GetNumErrors())

        self._db.Close()
        self._db = None

    def GetNumMTSChrashes(self):
        """ Get number of mts chrashes """
        return self._db.GetNumChrashs()

    def GetNumMTSErrors(self):
        """ Get number of mts errors """
        return self._db.GetNumErrors()

    def SetInputFolder(self, InputFolder):
        """ Set input folder """
        self._InputFolder = InputFolder

    def SetOutputFolder(self, OutputFolder):
        """ Set output folder """
        self._OutputFolder = OutputFolder


def get_version():
    """ Get module version """
    return 1.0


def get_creation_date():
    """ Get module creation date  """
    # date_str = __date__.find("Date: ")
    return "04.07.2012"


class FinalCheck():
    """ Final Check class """
    def __init__(self, hpc):
        """ Constructor """
        self.__FinalCheckFolder = ""
        self.__hpc = hpc

    def CreateFinalCheckTask(self, bFinal=True):
        """ Create Final Check Task """
        # Create Folder on Network Drive
        tmp_ = os.path.join(self.__hpc.GetCurNetJobInputPath(), "FinalCheck")
        self.__FinalCheckFolder = tmp_

        # Copy Source File to Network
        copyfile(os.path.abspath(__file__), self.__FinalCheckFolder)

        if(bFinal is True):
            # Create HPC Final Task with the necessary Parameters.
            self.__hpc.CreateFinalTask()
        else:
            self.__hpc.CreateTask()


if __name__ == "__main__":

    OutFilePath = ""
    Error = 0
    version = "\n%s " % os.path.split(sys.argv[0])[1]
    version += "Vers. %s, " % get_version()
    version += "Author: Robert Hecker, Creation date: "
    version += "%s\n" % get_creation_date()

    parser = OptionParser(usage="%prog [Options] lint_file",
                          version=version)
    parser.add_option("-c",
                      "--MTSFinalCheck",
                      action="store_true",
                      dest="MTSFinalCheck",
                      default=False,
                      help="Enables the MTS Final Check Run")
    parser.add_option("-p",
                      "--PrintStatistic",
                      dest="PrintStatistic",
                      action="store_true",
                      default=False,
                      help="Print Statistic Output")
    parser.add_option("-m",
                      "--MoveOutFile",
                      dest="MoveOutFile",
                      action="store_true",
                      default=False,
                      help="Move OutputFile to different location")
    parser.add_option("-j",
                      "--JobId",
                      dest="JobId",
                      default=None,
                      help="Job Id to generate the status Files")

    group = OptionGroup(parser,
                        "--MTSFinalCheck",
                        "Search for MTS Error and Chrashdumps")
    group.add_option("-i",
                     dest="InputFolder",
                     default=r'\\LIFS010\data\MFC310\_HPC\???',
                     help="Start Folder used to search for MTS Issues")
    group.add_option("-o",
                     dest="OutFolder",
                     default='c:\\',
                     help="Output Folder for the created error database file")

    parser.add_option_group(group)
    tmp = "PrintReturn an Error Overview for a given FinalCheck Run.\n" ""
    group = OptionGroup(parser,
                        "Final Check Statistic",
                        tmp)
    tmp = "Used filepath for statistic output, "
    tmp += "default is output from MTSFinalCheck"
    group.add_option("-f",
                     dest="FilePath",
                     default="",
                     help=tmp)

    parser.add_option_group(group)

    group = OptionGroup(parser,
                        "--MoveOutFile",
                        "Move the output file to a different destination")
    group.add_option("-d",
                     dest="DestFolder",
                     default="",
                     help="Destination Folder for the File")
    group.add_option("-s",
                     dest="SrcFolderDelete",
                     action="store_true",
                     default=True,
                     help="Delete the Source Folder after move")

    parser.add_option_group(group)

    op = parser.parse_args()

    if(op[0].MTSFinalCheck):
        # Do a MTS Final Check
        mts = MTSFinalCheck()
        mts.SetInputFolder(op[0].InputFolder)
        mts.SetOutputFolder(op[0].OutFolder)
        OutFilePath = mts.CheckMTSOutput()
        if(mts.GetNumOfFoundIssues() != 0):
            Error = -1

    if(op[0].JobId is not None):
        stat = TaskStatusCheck(OutFilePath, op[0].JobId)
        stat.GenStatusFiles()

    if(op[0].PrintStatistic):
        # Print Statistic to sdtout
        if(op[0].FilePath != ""):
            OutFilePath = op[0].FilePath
        mts.GetStatstic(OutFilePath)

    if(op[0].MoveOutFile):
        # Move output file to other location
        # Check if Destionation Directory exist
        if(os.path.isdir(op[0].DestFolder) is False):
            os.makedirs(op[0].DestFolder)
        # Copy output to Final Destination
        copy(OutFilePath, op[0].DestFolder)
        if(op[0].SrcFolderDelete):
            os.remove(OutFilePath)
            os.removedirs(os.path.split(OutFilePath)[0])

    sys.exit(Error)

"""
CHANGE LOG:
-----------
$Log: mts_final_check.py  $
Revision 1.1 2021/12/13 17:55:33CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.16 2013/09/26 19:13:28CEST Hecker, Robert (heckerr) 
Removed some pep8 Errors.
- Added comments -  heckerr [Sep 26, 2013 7:13:28 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.15 2013/09/25 09:20:19CEST Hecker, Robert (heckerr)
Removed some Errors and corrected stk import.
--- Added comments ---  heckerr [Sep 25, 2013 9:20:19 AM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.14 2013/09/24 12:26:02CEST Raedler, Guenther (uidt9430)
- updated imports according the new structure
--- Added comments ---  uidt9430 [Sep 24, 2013 12:26:02 PM CEST]
Change Package : 198327:1 http://mks-psad:7002/im/viewissue?selection=198327
Revision 1.13 2013/07/01 08:56:31CEST Hecker, Robert (heckerr)
Adapted to new bpl list.
--- Added comments ---  heckerr [Jul 1, 2013 8:56:31 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.12 2013/07/01 08:28:16CEST Hecker, Robert (heckerr)
Changed to new Bpl class.
--- Added comments ---  heckerr [Jul 1, 2013 8:28:17 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.11 2013/05/23 15:38:40CEST Raedler, Guenther (uidt9430)
- made private members and methods protected
--- Added comments ---  uidt9430 [May 23, 2013 3:38:40 PM CEST]
Change Package : 183658:1 http://mks-psad:7002/im/viewissue?selection=183658
Revision 1.10 2013/05/23 12:52:00CEST Raedler, Guenther (uidt9430)
- fixed some error due to pylint corrections (path, file, ...)
- fixed support of GenPlaylist using the BPLXml class
- added doc strings
- changed version to 1.10
--- Added comments ---  uidt9430 [May 23, 2013 12:52:00 PM CEST]
Change Package : 183658:1 http://mks-psad:7002/im/viewissue?selection=183658
Revision 1.9 2013/04/03 08:02:14CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:14 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/28 15:25:18CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:19 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/28 14:43:07CET Mertens, Sven (uidv7805)
pylint: resolving some R0904, R0913, R0914, W0107
--- Added comments ---  uidv7805 [Mar 28, 2013 2:43:07 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/28 13:31:26CET Mertens, Sven (uidv7805)
minor pep8
Revision 1.5 2013/02/28 08:12:15CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:15 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/07 17:19:03CET Hecker, Robert (heckerr)
Removed unused code.
--- Added comments ---  heckerr [Feb 7, 2013 5:19:03 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/14 16:22:47CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:47 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:49CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:49 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:54:44CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
