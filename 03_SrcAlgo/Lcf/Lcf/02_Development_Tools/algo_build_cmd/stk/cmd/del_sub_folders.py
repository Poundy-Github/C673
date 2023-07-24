"""
stk/cmd/del_sub_folders.py
--------------------------

Delete Subfolder which fulfill the filter criteria

:org:           Continental AG
:author:        Robert Hecker,
                Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:32CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
from optparse import OptionParser
import sys
import os
import shutil

# Defines -------------------------------------------------------------------------------------------------------------
ERR_OK = 0
ERR_TO_LESS_ARGS = -2

# Main Entry Point ----------------------------------------------------------------------------------------------------
if __name__ == "__main__":

    Error = 0

    OutFilePath = ""
    Error = 0
    version = "\n%s " % os.path.split(sys.argv[0])[1]
    version += "Vers. $Revision: 1.1 $ "
    version += "Author: Guenther Raedler, Creation date: "
    version += "22.05.2013\n"

    PARSER = OptionParser(usage="%prog [Options] lint_file",
                          version=version)

    PARSER.add_option("-o",
                      dest="DelPath",
                      default=None,
                      help="Folder to be deleted")
    PARSER.add_option("-f",
                      dest="Filter",
                      default=None,
                      help="String filter")

    OP = PARSER.parse_args()[0]

    ARGS = PARSER.parse_args()[1]

    if(len(ARGS) < 1):
        sys.exit(ERR_TO_LESS_ARGS)

    for path_, subdirs, _ in os.walk(OP.DelPath):
        for sd in subdirs:
            delete_sd = False

            if OP.Filter is not None:
                if OP.Filter in sd:
                    delete_sd = True
            else:
                delete_sd = True

            if delete_sd:
                sd = os.path.join(path_, sd)
                shutil.rmtree(sd)
                print "Deleted folder: " + sd

    sys.exit(Error)


"""
CHANGE LOG:
-----------
$Log: del_sub_folders.py  $
Revision 1.1 2021/12/13 17:55:32CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.6 2013/09/26 19:13:27CEST Hecker, Robert (heckerr) 
Removed some pep8 Errors.
- Added comments -  heckerr [Sep 26, 2013 7:13:27 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.5 2013/09/26 18:22:56CEST Hecker, Robert (heckerr)
Added Error to check jenkins.
--- Added comments ---  heckerr [Sep 26, 2013 6:22:56 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.4 2013/09/26 17:42:22CEST Hecker, Robert (heckerr)
Removed some Pylint Errors.
--- Added comments ---  heckerr [Sep 26, 2013 5:42:23 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.3 2013/09/25 09:20:19CEST Hecker, Robert (heckerr)
Removed some Errors and corrected stk import.
--- Added comments ---  heckerr [Sep 25, 2013 9:20:19 AM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
"""
