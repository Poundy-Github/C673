"""
stk/obj/label_objects.py
-------------------

Python implementation of the Class ARS4D0_Object

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:33CET $
"""

from stk.obj.ARS4xxObject import ARS4xxObject


class ARS4D0Object(ARS4xxObject):
    """
    ARS4D0Object
    """
    def __init__(self, obj, **kwargs):
        """Constructor taking the distx, disty and the vrelx as argument
        :param obj: Reference to object in the list of objects
        :param object_ext_if: Project
        (Observer) specific extension interface provider
        """
        ARS4xxObject.__init__()

    def __del__(self):
        """
          List of custom specific object signals.
          Loaded when object_ext_if is provided.
        """
        pass

    def __copy__(self):
        """
          Make a copy of the event object class
          The reference to the object is copied as
        well
        """
        pass
"""
$Log: ARS4D0Object.py  $
Revision 1.1 2021/12/13 17:58:33CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/project.pj
Revision 1.1 2013/12/03 14:29:36CET uidg3354 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/obj/project.pj
"""
