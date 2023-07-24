"""
stk/db/lbl/genlabel_defs.py
-------------------

Definitions for the labels.


:org:           Continental AG
:author:        Nassim Ibrouchene

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:56:22CET $
"""


class RoadType():  # pylint: disable-msg=W0232
    # Road type label definitions as in the DB
    LABEL_TYPE_NAME = "roadtype"
    LABEL_VALUE_HIGHWAY = 3
    LABEL_VALUE_COUNTRY = 2
    LABEL_VALUE_CITY = 1
    LABEL_VALUE_UNDEFINED = 0
    LABEL_VALUE_UNLABELED = -1
    LABEL_NAME_HIGHWAY = "ROAD TYPE HIGHWAY"
    LABEL_NAME_COUNTRY = "ROAD TYPE COUNTRY"
    LABEL_NAME_CITY = "ROAD TYPE CITY"
    LABEL_NAME_UNDEFINED = "ROAD TYPE UNDEFINED"
    # Road type keywords
    HIGHWAY = "Highway"
    COUNTRY = "Country"
    CITY = "City"
    UNDEFINED = "Undefined"
    UNLABELED = "Unlabeled"
    RD_DICT = {}
    RD_DICT[HIGHWAY] = LABEL_VALUE_HIGHWAY
    RD_DICT[COUNTRY] = LABEL_VALUE_COUNTRY
    RD_DICT[CITY] = LABEL_VALUE_CITY
    RD_DICT[UNDEFINED] = LABEL_VALUE_UNDEFINED
    RD_DICT[UNLABELED] = LABEL_VALUE_UNLABELED
    TYPES = [HIGHWAY, COUNTRY, CITY, UNLABELED]
    # Road type attribute definition
    EVENT_ATTR_ROAD_TYPE = "roadtype"

"""
CHANGE LOG:
-----------
$Log: genlabel_defs.py  $
Revision 1.1 2021/12/13 17:56:22CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/db/lbl/project.pj
Revision 1.3 2013/07/29 10:03:42CEST Ibrouchene, Nassim (uidt5589) (uidt5589) 
Added entry for unlabeled status for the road type.
- Added comments -  uidt5589 [Jul 29, 2013 10:03:43 AM CEST]
Change Package : 182606:3 http://mks-psad:7002/im/viewissue?selection=182606
Revision 1.2 2013/05/29 13:22:24CEST Mertens, Sven (uidv7805) 
removing the only pylint error visible
--- Added comments ---  uidv7805 [May 29, 2013 1:22:24 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.1 2013/05/14 10:36:36CEST Ibrouchene-EXT, Nassim (uidt5589)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/db/lbl/project.pj
"""
