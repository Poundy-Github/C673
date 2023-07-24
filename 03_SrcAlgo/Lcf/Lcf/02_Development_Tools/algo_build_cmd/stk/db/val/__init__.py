"""
stk/db/val/__init__.py
-------------------

Classes for Database access of Validation Results and Events.

 Sub-Scheme VAL


:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:55CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------
from val import BaseValResDB      # base class providing common catalog interface methods
from val import OracleValResDB    # oracle implementation (derived from BaseValResDB)
from val import SQLCEValResDB     # SQL Compact implementation (derived from BaseValResDB)
from val import SQLite3ValResDB   # SQLite implementation (derived from BaseValResDB)


"""
CHANGE LOG:
-----------
$Log: __init__.py  $
Revision 1.1 2021/12/13 17:56:55CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/val/project.pj
Revision 1.3 2013/03/21 17:22:32CET Mertens, Sven (uidv7805) 
solving some pylint warnings / errors
- Added comments -  uidv7805 [Mar 21, 2013 5:22:32 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.2 2013/02/19 14:07:32CET Raedler, Guenther (uidt9430)
- database interface classes derives from common classes for oracle, ...
- use common exception classes
- use common db functions
--- Added comments ---  uidt9430 [Feb 19, 2013 2:07:32 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/02/11 09:59:37CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/db/val/project.pj
"""
