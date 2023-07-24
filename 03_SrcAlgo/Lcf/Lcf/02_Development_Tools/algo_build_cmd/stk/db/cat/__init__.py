"""
stk/db/cat/__init__.py
-------------------

Classes for Database access of the Catalogs and Files.

 Sub-Scheme CAT

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:58CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------


# Import Local Python Modules -----------------------------------------------------------------------------------------
from cat import BaseRecCatalogDB      # base class providing common catalog interface methods
from cat import OracleRecCatalogDB    # oracle implementation (derived from BaseRecCatalogDB)
from cat import SQLCERecCatalogDB     # SQL Compact implementation (derived from BaseRecCatalogDB)
from cat import SQLite3RecCatalogDB   # SQLite implementation (derived from BaseRecCatalogDB)

from cat import PATH_SEPARATOR
"""
CHANGE LOG:
-----------
$Log: __init__.py  $
Revision 1.1 2021/12/13 17:55:58CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/cat/project.pj
Revision 1.2 2013/03/21 17:22:35CET Mertens, Sven (uidv7805) 
solving some pylint warnings / errors
- Added comments -  uidv7805 [Mar 21, 2013 5:22:36 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.1 2013/02/11 09:55:35CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/db/cat/project.pj
"""
