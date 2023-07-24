"""
mts_gen_playlist
----------------

Create a mts batch playlist with the given files

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:33CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
import os
import sys
from optparse import OptionParser

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------
STK_FOLDER = os.path.abspath(os.path.join(os.path.split(__file__)[0], r"..\.."))
if STK_FOLDER not in sys.path:
    sys.path.append(STK_FOLDER)

# Import STK Modules --------------------------------------------------------------------------------------------------
from stk.mts.bpl import Bpl, BplListEntry

# Main Entry Point ----------------------------------------------------------------------------------------------------
if __name__ == "__main__":

    Error = 0

    OutFilePath = ""
    Error = 0
    version = "\n%s " % os.path.split(sys.argv[0])[1]
    version += "Vers. $Revision: 1.1 $ "
    version += "Author: Guenther Raedler, Creation date: "
    version += "22.05.2013\n"

    parser = OptionParser(usage="%prog [Options] lint_file",
                          version=version)

    parser.add_option("-o",
                      dest="OutFile",
                      default='mts_playlist.bpl',
                      help="Filename of the mts batch playlist")

    op = parser.parse_args()

    files = op[1]
    bpl_writer = Bpl(str(op[0].OutFile))
    for f in files:
        bpl_writer.append(BplListEntry(str(f)))
    bpl_writer.write()

    sys.exit(Error)

"""
CHANGE LOG:
-----------
$Log: mts_gen_playlist.py  $
Revision 1.1 2021/12/13 17:55:33CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/cmd/project.pj
Revision 1.6 2013/09/26 19:13:28CEST Hecker, Robert (heckerr) 
Removed some pep8 Errors.
- Added comments -  heckerr [Sep 26, 2013 7:13:29 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.5 2013/09/25 09:20:19CEST Hecker, Robert (heckerr)
Removed some Errors and corrected stk import.
--- Added comments ---  heckerr [Sep 25, 2013 9:20:20 AM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
"""
