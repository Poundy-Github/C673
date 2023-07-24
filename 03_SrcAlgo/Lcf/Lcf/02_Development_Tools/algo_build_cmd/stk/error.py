"""
stk/error.py
------------

This Module contains the General Exception Handling Methods, which are available inside the stk.

:org:           Continental AG
:author:        Sven Mertens

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:25CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
from sys import _getframe
from os import path as oPath

# Defines -------------------------------------------------------------------------------------------------------------
ERR_OK = 0
"""Code for No Error"""
ERR_UNSPECIFIED = 1
"""Code for an unknown Error"""

# Classes -------------------------------------------------------------------------------------------------------------


class StkError(Exception):
    """
    Base STK exception class, where all other Exceptions
    from the stk sub-packages must be derived from.
    """

    ERR_OK = ERR_OK
    """Code for No Error"""
    ERR_UNSPECIFIED = ERR_UNSPECIFIED
    """Code for an unknown Error"""

    def __init__(self, msg, errno=ERR_UNSPECIFIED, dpth=1):
        """
        retrieve some additional information

        :param msg:   message to announce
        :type msg:    string
        :param errno: related error number
        :type errno:  integer
        :param dpth:  starting frame depth for error trace, increase by 1 for each subclass level of StkError
        :type dpth:   integer
        """
        Exception.__init__(self, msg)
        frame = _getframe(dpth)
        self._error = "'%s' (%d): %s (line %d) attr: %s" % (msg, errno,
                                                            oPath.basename(frame.f_code.co_filename),
                                                            frame.f_lineno, frame.f_code.co_name)

    def __str__(self):
        """
        Return our own string
        """
        return self._error

"""
CHANGE LOG:
-----------
$Log: error.py  $
Revision 1.1 2021/12/13 17:55:25CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/project.pj
Revision 1.5 2013/10/25 16:26:31CEST Hospes, Gerd-Joachim (uidv8815) 
remove 'import stk' and replace missing dependencies
- Added comments -  uidv8815 [Oct 25, 2013 4:26:32 PM CEST]
Change Package : 203191:1 http://mks-psad:7002/im/viewissue?selection=203191
Revision 1.4 2013/10/16 16:08:49CEST Hecker, Robert (heckerr) 
Changed from StandardError to Exception.
--- Added comments ---  heckerr [Oct 16, 2013 4:08:49 PM CEST]
Change Package : 201826:1 http://mks-psad:7002/im/viewissue?selection=201826
Revision 1.3 2013/10/01 13:48:51CEST Hospes, Gerd-Joachim (uidv8815) 
new error msg for observer load problems
--- Added comments ---  uidv8815 [Oct 1, 2013 1:48:51 PM CEST]
Change Package : 196951:1 http://mks-psad:7002/im/viewissue?selection=196951
Revision 1.2 2013/09/13 16:58:18CEST Hecker, Robert (heckerr)
Changed Define to shorter name.
--- Added comments ---  heckerr [Sep 13, 2013 4:58:18 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.1 2013/09/13 16:01:42CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/project.pj
"""
