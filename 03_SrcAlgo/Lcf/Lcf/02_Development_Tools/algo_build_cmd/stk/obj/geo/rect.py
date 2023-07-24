"""
stk/obj/geo/rect.py
-------------------

 Rectangular Class supporting
    - Rotate
    - Shift
    - Reflection Point Calculation (for Radar objects)

:org:           Continental AG
:author:        Guenther Raedler

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:54CET $
"""
# Import Python Modules -------------------------------------------------------
from math import sin, cos

# Import STK Modules ----------------------------------------------------------
from point import SplitPairList

# Defines ---------------------------------------------------------------------

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class Rectangle(object):
    '''
    classdocs
    '''
    def __init__(self, left, right, top, bottom):
        '''
        Constructor
        '''
        point_list = []
        point_list.append([-bottom, left])
        point_list.append([top, left])
        point_list.append([top, -right])
        point_list.append([-bottom, -right])
        point_list.append([-bottom, left])

        self.__point_list = point_list
        # print point_list

    def Rotate(self, orientation):
        """ Rotates the box around the origin [0,0]
        @param point_list: List of Points
        @param orientation: orientation angle in radians
        @return: List of rotated points
        """
        # precompute trig functions
        sin_phi = sin(orientation)
        cos_phi = cos(orientation)

        # rotate points around origin [0,0]
        ret_point_list = []
        for point in self.__point_list:
            x = point[0] * cos_phi - point[1] * sin_phi
            y = point[0] * sin_phi + point[1] * cos_phi
            ret_point_list.append([x, y])

        self.__point_list = ret_point_list

    def Shift(self, x_shift, y_shift):
        """ Rotates the box around the origin [0,0]
        @param x_shift: amount to shift box
        @param y_shift: amount to shift box
        @return: List of shifted points
        """

        # shift points
        ret_point_list = []
        for point in self.__point_list:
            ret_point_list.append([point[0] + x_shift, point[1] + y_shift])

        self.__point_list = ret_point_list

    def CalcReflectionsPoint(self, orientation=None):
        """ Calculate the reflexion point of the Box

            1--------2
            |        |
            |        |
            |        |
            |        |
            0/4------3

        @param point_list: List ox Pointpairs describing the Box
        @return: The reflection point pair
        """
        # get number of points (should be 5)
        point_list = self.__point_list
        npoints = len(point_list)

        # find the nearest point
        x_vec, _ = SplitPairList(point_list)
        index = x_vec.index(min(x_vec))
        point = point_list[index]

        # find neighbouring left and right points connected by vertices to closest point
        if index == 0:
            point_left = point_list[npoints - 2]
        else:
            point_left = point_list[index - 1]

        if index == npoints - 1:
            point_right = point_list[1]
        else:
            point_right = point_list[index + 1]

        # assuming that we have a rectangular box:
        if (abs(point_left[0] - point[0]) < abs(point_left[1] - point[1])):
            # if orientation of left vertex < 45deg (i.e. deltaX < deltaY)
            # then reflection point is in the middle of this vertex
            x = (point[0] + point_left[0]) / 2
            y = (point[1] + point_left[1]) / 2
        else:
            # else orientation is the midlle of the other vertex
            x = (point[0] + point_right[0]) / 2
            y = (point[1] + point_right[1]) / 2

        return [x, y]

    def PolygonContainsPoint(self, x, y):
        """ Is the point in the given polygon (box) ?
        @param  point_list: list of points decribing the polygon (last point == first point)
        @param x: x value of the point to be tested
        @param y: y value of the point to be tested
        @return True if point in the polygon (box)

        assume a semidefinite horizontal ray (x increasing, y = const)
        out from the test point and count how many edges of the polygon
        it crosses. At each crossing, the ray switches between inside and outside.
        This is called the Jordan curve theorem. The point lies outside the polygon
        if the number of crossings is even. This functions counts only edges which
        are to the right of the test point (x_edge > x)
        """

        inside = False
        npoints = len(self.__point_list)

        j = 0
        for i in xrange(1, npoints):
            if (((self.__point_list[i][1] > y) != (self.__point_list[j][1] > y)) and
                (x < (self.__point_list[j][0] - self.__point_list[i][0]) * (y - self.__point_list[i][1]) /
                 (self.__point_list[j][1] - self.__point_list[i][1]) + self.__point_list[i][0])):
                inside = not inside
            j = i

        return inside

"""
CHANGE LOG:
-----------
$Log: rect.py  $
Revision 1.1 2021/12/13 17:58:54CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/obj/geo/project.pj
Revision 1.7 2013/12/03 17:33:06CET uidg3354 
pylint fix
- Added comments -  uidg3354 [Dec 3, 2013 5:33:06 PM CET]
Change Package : 208827:1 http://mks-psad:7002/im/viewissue?selection=208827
Revision 1.6 2013/05/16 07:31:03CEST Raedler, Guenther (uidt9430)
- moved method PolygonContainsPoint(self, x, y) from old vpc into stk
--- Added comments ---  uidt9430 [May 16, 2013 7:31:03 AM CEST]
Change Package : 175136:1 http://mks-psad:7002/im/viewissue?selection=175136
Revision 1.5 2013/03/28 09:33:19CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:20 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/03/01 15:47:40CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 3:47:40 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/28 08:12:29CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:29 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/27 16:20:01CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:20:02 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 10:50:01CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/obj/geo/project.pj
"""
