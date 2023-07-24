"""
stk/mks/__init__.py
-------------------

Classes for MKS Interfaces.

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:16CET $
"""
# Import Python Modules -------------------------------------------------------

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------
from si import MksSIMember
from si import MksSIProject
from si import MksSISandbox
from si import RET_VAL_OK
from si import RET_VAL_ERROR
# Import Local Python Modules -------------------------------------------------

"""
CHANGE LOG:
-----------
$Log: __init__.py  $
Revision 1.1 2021/12/13 17:58:16CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/mks/project.pj
Revision 1.3 2013/03/15 11:43:38CET Raedler, Guenther (uidt9430) 
- add mks si interface
- Added comments -  uidt9430 [Mar 15, 2013 11:43:38 AM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.2 2013/03/01 16:30:51CET Hecker, Robert (heckerr) 
Updates geragding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 4:30:51 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/01/23 07:59:41CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/mks/project.pj
"""
