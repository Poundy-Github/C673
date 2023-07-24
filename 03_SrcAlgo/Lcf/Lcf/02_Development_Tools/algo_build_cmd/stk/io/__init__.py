"""
stk/io/__init__.py
-------------------

Classes for io handling.

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:04CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------

from req_data import RequirementsData
from bsig import BsigReader
import dlm

"""
CHANGE LOG:
-----------
$Log: __init__.py  $
Revision 1.1 2021/12/13 17:58:04CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/io/project.pj
Revision 1.5 2013/03/22 08:24:34CET Mertens, Sven (uidv7805) 
aligning bulk of files again for peping 8
- Added comments -  uidv7805 [Mar 22, 2013 8:24:34 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/03/01 16:38:33CET Hecker, Robert (heckerr)
Update regarding Pep8 Styleguide.
--- Added comments ---  heckerr [Mar 1, 2013 4:38:34 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/26 17:11:40CET Hecker, Robert (heckerr)
Added reference to dlm
--- Added comments ---  heckerr [Feb 26, 2013 5:11:41 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/11 10:33:50CET Raedler, Guenther (uidt9430)
- added bsig from stk 1.0 and req_data from etk/vpc
--- Added comments ---  uidt9430 [Feb 11, 2013 10:33:50 AM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/01/23 07:59:40CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/io/project.pj
"""
