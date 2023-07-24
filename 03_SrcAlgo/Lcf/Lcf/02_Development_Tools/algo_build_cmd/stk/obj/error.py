"""
stk/error.py
------------

This Module contains the General Exception Handling Methods, which are available inside the stk.

:org:           Continental AG
:author:        Sven Mertens

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:34CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
from sys import _getframe
from os import path as oPath

from .. import error

# Defines -------------------------------------------------------------------------------------------------------------
ERR_OK = 0
"""Code for No Error"""
ERR_UNSPECIFIED = 1
"""Code for an unknown Error"""

# Classes -------------------------------------------------------------------------------------------------------------


class AdasObjectLoadError(error.StkError):
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
Revision 1.1 2021/12/13 17:58:34CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/project.pj
Revision 1.1 2013/12/03 14:12:03CET uidg3354 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/obj/project.pj
"""
