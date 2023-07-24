"""
stk.valf.error.py
----------------

This Module contains Error Handling Methods for the subpackage valf.

:org:           Continental AG
:author:        Joachim Hospes

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:52CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------
from stk.error import StkError

# Classes -------------------------------------------------------------------------------------------------------------


class ValfError(StkError):
    """
    Exception Class for all Valf Exceptions.

    :author:        Joachim Hospes
    :date:          26.09.2013
    """
    ERR_OBSERVER_CLASS_NOT_FOUND = 101
    """Observer Class Name not found."""

    def __init__(self, msg, errno=StkError.ERR_UNSPECIFIED, dpth=2):
        """
        Init Method of Exception class

        :param msg:   Error Message string, which explains the user was went wrong.
        :type msg:    string
        :param errno: unique number which represents a Error Code inside the Package.
        :type errno:  integer
        :param dpth:  depth of call stack to start error frame output, StkError is level 1, fist subclass level 2...

        :author:      Joachim Hospes
        :date:        26.09.2013
        """
        StkError.__init__(self, msg, errno=errno, dpth=dpth)


"""
CHANGE LOG:
-----------
$Log: error.py  $
Revision 1.1 2021/12/13 17:59:52CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.2 2013/10/30 10:52:30CET Hecker, Robert (heckerr) 
Replaced Exception with more usefull information for the End User, and put extra information into the log file.
- Added comments -  heckerr [Oct 30, 2013 10:52:30 AM CET]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.1 2013/10/01 13:42:14CEST Hospes, Gerd-Joachim (uidv8815) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
"""
