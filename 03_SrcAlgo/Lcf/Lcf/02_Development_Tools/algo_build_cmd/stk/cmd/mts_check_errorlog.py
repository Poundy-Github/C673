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
# Import Python Modules -----------------------------------------------------------------------------------------------
import sys
from optparse import OptionParser
from optparse import OptionGroup
from sys import path as sp, argv

from os import path, remove, makedirs

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------
STK_FOLDER = path.abspath(path.join(path.split(__file__)[0], r"..\.."))
if STK_FOLDER not in sp:
    sp.append(STK_FOLDER)

# Import STK Modules --------------------------------------------------------------------------------------------------
from stk.hpc import Hpc
from . mts_final_check import JobErrorDB, TaskStatusCheck, MTSFinalCheck

# Import Local Python Modules -----------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class MTSErrorLogCheck(MTSFinalCheck):
    """ MTS Final Check Class"""
    def __init__(self):
        MTSFinalCheck.__init__(self)

    def CheckMTSOutput(self):

        # Get JobName from Path
        jobname = "mts_error_log.db"

        self._DataBasePath = self._OutputFolder + '\\' + jobname

        # Check if File exists, and delete
        if(path.isfile(self._DataBasePath)):
            remove(self._DataBasePath)

        if(path.isdir(self._OutputFolder) is False):
            makedirs(self._OutputFolder)

        # Create Result Database for all Jobs.
        self._db = JobErrorDB()
        self._db.Create(self._DataBasePath)

        # Search for MTS ChrashDumps
        # Find all Chrashdumps for the specified job.
        error = self._SearchMTSChrashDumps(self._db, self._InputFolder,
                                           '*crash*.dmp')

        # Search in all log files for Errors and list the Reported Files
        if(error == 0):
            error = self._SearchXLogErrors(self._db, self._InputFolder)

        self._db.Commit()

        self._CreateSummaryTable(self._db)

        # Get Number of Issues
        self._Issues = self._db.GetNumChrashs()
        self._Errors = self._db.GetNumErrors()

        self._db.Close()
        self._db = None
        return self._DataBasePath


def get_version():
    version = 0.1
    return version


def get_creation_date():
    """ Get module creation date  """
    # date_str = __date__.find("Date: ")
    return "22.05.2013"


if __name__ == "__main__":

    OutFilePath = ""
    Error = 0
    version = "\n%s " % path.split(argv[0])[1]
    version += "Vers. %s, " % get_version()
    version += "Author: Guenther Raedler, Creation date: "
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
        mts = MTSErrorLogCheck()
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

    sys.exit(Error)

"""
CHANGE LOG:
-----------
$Log: mts_check_errorlog.py  $
Revision 1.1 2021/12/13 17:55:33CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.5 2013/09/27 11:19:19CEST Hecker, Robert (heckerr) 
* :-)
- Added comments -  heckerr [Sep 27, 2013 11:19:19 AM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.4 2013/09/26 19:13:27CEST Hecker, Robert (heckerr)
Removed some pep8 Errors.
--- Added comments ---  heckerr [Sep 26, 2013 7:13:28 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.3 2013/09/25 09:20:19CEST Hecker, Robert (heckerr)
Removed some Errors and corrected stk import.
--- Added comments ---  heckerr [Sep 25, 2013 9:20:19 AM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.2 2013/09/24 12:25:54CEST Raedler, Guenther (uidt9430)
- updated imports according the new structure
--- Added comments ---  uidt9430 [Sep 24, 2013 12:25:54 PM CEST]
Change Package : 198327:1 http://mks-psad:7002/im/viewissue?selection=198327
Revision 1.1 2013/05/23 16:00:52CEST Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/hpc/util/project.pj
"""
