"""
stk.hpc.error.py
----------------

This Module contain Error Handling Methods for the subpackage hpc.

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:01CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------
from .. import error

# Defines -------------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class HpcError(error.StkError):
    """
    Exception Class for all HPC Exceptions.

    :author:        Robert Hecker
    :date:          04.09.2013
    """
    def __init__(self, msg, errno=error.ERR_UNSPECIFIED):
        """
        Init Method of Exception class

        :param msg:   Error Message string, which explains the user was went wrong.
        :type msg:    string
        :param errno: unique number which represents a Error Code inside the Package.
        :type errno:  integer

        :author:      Robert Hecker
        :date:        04.09.2013
        """
        error.StkError.__init__(self, msg, errno)


"""
CHANGE LOG:
-----------
$Log: error.py  $
Revision 1.1 2021/12/13 17:57:01CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/project.pj
Revision 1.2 2013/09/13 16:58:18CEST Hecker, Robert (heckerr) 
Changed Define to shorter name.
- Added comments -  heckerr [Sep 13, 2013 4:58:19 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.1 2013/09/13 16:50:45CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
