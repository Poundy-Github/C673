"""
stk/db/lbl/__init__.py
-------------------

Classes for Database access of Generic Lables and Camera Labels (ADMS_ADMIN).

 Sub-Scheme LB and ADM_ADMIN

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:22CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------
from genlabel import BaseGenLabelDB      # base class providing common catalog interface methods
from genlabel import OracleGenLabelDB    # oracle implementation (derived from BaseGenLabelDB)
from genlabel import SQLCEGenLabelDB     # SQL Compact implementation (derived from BaseGenLabelDB)
from genlabel import SQLite3GenLabelDB   # SQLite implementation (derived from BaseGenLabelDB)
from camlabel import BaseCameraLabelDB
from genlabel_defs import RoadType  # RoadType label definitions

"""
CHANGE LOG:
-----------
$Log: __init__.py  $
Revision 1.1 2021/12/13 17:56:22CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/lbl/project.pj
Revision 1.5 2013/05/14 10:35:58CEST Ibrouchene, Nassim (uidt5589) (uidt5589) 
Added import of road type definitions.
- Added comments -  uidt5589 [May 14, 2013 10:35:58 AM CEST]
Change Package : 182606:3 http://mks-psad:7002/im/viewissue?selection=182606
Revision 1.4 2013/03/21 17:22:33CET Mertens, Sven (uidv7805) 
solving some pylint warnings / errors
--- Added comments ---  uidv7805 [Mar 21, 2013 5:22:34 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.3 2013/03/13 17:45:02CET Hecker, Robert (heckerr)
imported needed class.
--- Added comments ---  heckerr [Mar 13, 2013 5:45:02 PM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.2 2013/02/19 14:07:27CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:27 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 09:58:40CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/db/lbl/project.pj
"""
