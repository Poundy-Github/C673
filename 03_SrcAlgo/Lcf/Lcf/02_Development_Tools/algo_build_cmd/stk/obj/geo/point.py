"""
stk/obj/geo/point.py
-------------------

Functions to generate and split point pair lists

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:54CET $
"""
# Import Python Modules -------------------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Defines ---------------------------------------------------------------------

# Functions -------------------------------------------------------------------


def SplitPairList(pp_list):
    """ converts a point pair list into two arrays
    @param pp_list: Pointer Pair List
    @return : Two array representing column 0 and 1 in the point pairs
    """
    x_vec = [0] * len(pp_list)
    y_vec = [0] * len(pp_list)

    for pp in range(len(pp_list)):
        x_vec[pp] = pp_list[pp][0]
        y_vec[pp] = pp_list[pp][1]

    return x_vec, y_vec


def GetPointPairList(x_vec, y_vec):
    """ converts two arrays into a point pair list
    @param x_vec:
    @param y_vec:
    @return: list of point pairs
    """
    if len(x_vec) != len(y_vec):
        # print "Length of x:{0} y:{1}".format(len(x_vec),len(y_vec))
        return None

    line_data = []
    for pp in range(len(x_vec)):
        line_data.append((x_vec[pp], y_vec[pp]))
    return line_data


def ShiftTimelineOfPointPairList(pp_list):
    """ Resets the time to start from zero.
    @param pp_list: Pointpair list describing a signal.
    @return point pair list with update timeline
    """
    new_pp_list = []
    if pp_list is not None:
        start_time = pp_list[0][0]
        for data in pp_list:
            aPoint = (data[0] - start_time, data[1])
            new_pp_list.append(aPoint)
    return new_pp_list

"""
CHANGE LOG:
-----------
$Log: point.py  $
Revision 1.1 2021/12/13 17:58:54CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/geo/project.pj
Revision 1.6 2013/12/03 17:33:06CET uidg3354 
pylint fix
- Added comments -  uidg3354 [Dec 3, 2013 5:33:07 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.5 2013/05/17 13:17:51CEST Raedler, Guenther (uidt9430)
- added ShiftTimelineOfPointPairList()
--- Added comments ---  uidt9430 [May 17, 2013 1:18:32 PM CEST]
Change Package : 183278:1 http://mks-psad:7002/im/viewissue?selection=183278
Revision 1.4 2013/04/03 08:02:14CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:14 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.3 2013/03/01 15:49:03CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguide.
--- Added comments ---  heckerr [Mar 1, 2013 3:49:03 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/28 08:12:15CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:16 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 10:50:01CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/obj/geo/project.pj
"""
