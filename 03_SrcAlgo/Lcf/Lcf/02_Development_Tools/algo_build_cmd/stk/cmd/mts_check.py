"""
mts_check
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

# Add PyLib Folder to System Paths --------------------------------------------
STK_FOLDER = os.path.abspath(os.path.join(os.path.split(__file__)[0], r"..\.."))

if STK_FOLDER not in sys.path:
    sys.path.append(STK_FOLDER)

# Import STK Modules ----------------------------------------------------------
from stk.mts.parser import Crash
from stk.mts.parser import Xlog
from stk.hpc.ifc.masterdb.error_db import HpcErrorDB

# Import Local Python Modules -------------------------------------------------

# Classes ---------------------------------------------------------------------


def GetTaskId(filePath):
    """ Get the Task ID from the output path name """
    tmp_ = filePath[filePath.find('\\2_Output\\') + 10:]
    tmp_ = tmp_[:tmp_.find('\\')]
    if(tmp_.find('task_') != -1):
        tmp_ = tmp_[5:]
    return int(tmp_[1:])


def GetJobId(filePath):
    """ Get the Job ID from the output path name """
    tmp_ = filePath[:filePath.find('\\2_Output\\')]
    tmp_ = tmp_[tmp_.rfind('\\') + 1:]
    tmp_ = tmp_[:tmp_.find('_')]

    return int(tmp_)


def MTSCheck(inputFolder):
    """
    Scans the given Input Folder for MTS Chrashdumps and xlog-Files.
    Analyse the Files, and store some information inside the Database.
    """
    # Connect to the DB
    db = HpcErrorDB()
    db.Open('oracle://hpc_user:Baba1234@racadmpe')

    # Check for MTS ChrashDumps
    for (path_, _, files) in os.walk(inputFolder):
        fileNames = fnmatch.filter(files, '*crash*.xml')
        for fileName in fileNames:
            filePath = os.path.join(path_, fileName)
            jobId = GetJobId(filePath)
            taskId = GetTaskId(filePath)
            crash = Crash(filePath)
            info = crash.GetChrashInfo()
            db.AddCrash(jobId, taskId, info[0].errCode, info[0].errDesc, info[0].errSrc)

    # Check MTS xlog Files
    for (path_, _, files) in os.walk(inputFolder):
        fileNames = fnmatch.filter(files, '*.xlog')
        for fileName in fileNames:
            filePath = os.path.join(path_, fileName)
            jobId = GetJobId(filePath)
            taskId = GetTaskId(filePath)

            xlog = Xlog(filePath)

            results = xlog.GetExceptions()
            for res in results:
                db.AddException(jobId, taskId, res.errCode, res.errDesc, res.errSrc)

            results = xlog.GetErrors()
            for res in results:
                db.AddError(jobId, taskId, res.errCode, res.errDesc, res.errSrc)

    db.Close()

    return 0


def PrintStatistic(jobId):
    """
    Open a Connection to the Oracle DB and returns the number of issues
    given by the JobId.
    """

    # Connect to the DB
    db = HpcErrorDB()
    db.Open('oracle://hpc_user:Baba1234@racadmpe')

    # Print Statistic
    print "\n\nStatistic"
    print "=========="
    print "Chrashdumps:  " + str(db.GetNumCrashs(jobId))
    print "Exceptions:   " + str(db.GetNumExceptions(jobId))
    print "Errors:       " + str(db.GetNumErrors(jobId))

    db.Close()

    return 0

def get_version():
    """ Get module version """
    return 1.0


def get_creation_date():
    """ Get module creation date  """
    return "04.07.2012"


if __name__ == "__main__":

    OutFilePath = ""
    Error = 0
    version = "\n%s " % os.path.split(sys.argv[0])[1]
    version += "Vers. %s, " % get_version()
    version += "Author: Robert Hecker, Creation date: "
    version += "%s\n" % get_creation_date()

    parser = OptionParser(usage="%prog [Options]",
                          version=version)
    parser.add_option("-m",
                      "--MTSCheck",
                      action="store_true",
                      dest="MTSCheck",
                      default=False,
                      help="Perform an check of the MTS Output after Chrashes, Exceptions and Errors")
    parser.add_option("-p",
                      "--PrintStatistic",
                      dest="PrintStatistic",
                      action="store_true",
                      default=False,
                      help="Print Statistic Output for a Single Job")

    group = OptionGroup(parser,
                        "--MTSCheck",
                        "Search for MTS Errors, Exceptions and Chrashdumps")
    group.add_option("-i",
                     dest="InputFolder",
                     default=r'\\LIFS010\data\MFC310\_HPC\2744_HPC_MTS_SR_Job\2_Output\T00006',
                     help="Start Folder used to search for MTS Issues")

    parser.add_option_group(group)
    group = OptionGroup(parser,
                        "--PrintStatistic",
                        "Print Statistic Output for a single Job")
    group.add_option("-j",
                     dest="JobId",
                     default="",
                     help="Hpc Job Id which must be analyzed")

    parser.add_option_group(group)

    OP = parser.parse_args()

    if(OP[0].MTSCheck):
        # Do a MTS Check
        Error = MTSCheck(OP[0].InputFolder)

    if(OP[0].PrintStatistic):
        # Print Statistic to sdtout
        Error = PrintStatistic(OP[0].JobId)

    sys.exit(Error)

"""
CHANGE LOG:
-----------
$Log: mts_check.py  $
Revision 1.1 2021/12/13 17:55:33CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.3 2013/12/15 14:37:20CET Hecker, Robert (heckerr) 
Moved to correct User Account.
- Added comments -  heckerr [Dec 15, 2013 2:37:20 PM CET]
Change Package : 210873:1 http://mks-psad:7002/im/viewissue?selection=210873
Revision 1.2 2013/12/13 13:05:23CET Hecker, Robert (heckerr)
Changed Oracle DB User Account.
--- Added comments ---  heckerr [Dec 13, 2013 1:05:23 PM CET]
Change Package : 210873:1 http://mks-psad:7002/im/viewissue?selection=210873
Revision 1.1 2013/12/12 13:21:35CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/cmd/project.pj
"""
