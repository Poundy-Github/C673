"""
dir
---

documentation of dir
docu docu

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:37CET $
"""
# Import Python Modules -------------------------------------------------------
from os import listdir, path
from fnmatch import filter

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------

# local Functions -------------------------------------------------------------


def list_dir_names(Folder):
    """
    Function returns all DirectoryNames as List, which
    are found inside Folder. Returns empty list for not existing dir.

    :param Folder:     Folder
    :return:           DirNameList
    :author:           Robert Hecker
    """
    FolderNames = []
    try:
        FolderNames = listdir(Folder)
    except:
        return []

    FilteredFolderNames = []
    for item in FolderNames:
        if not path.isfile(str(Folder + "/" + item)):
            FilteredFolderNames.append(item)
    return FilteredFolderNames


def list_file_names(Folder, Filter="*.*"):
    """
    All FileNames will be returned as List.
    Returns empty list for not existing dir.

    :param Folder:     folder to search
    :param Filter:     file filter (e.g. *.rec)

    :return:           FileNameList
    :author:           Robert Hecker
    """
    FileNames = []
    try:
        FileNames = listdir(Folder)
    except:
        return []
    FileNames = filter(FileNames, Filter)
    return FileNames

"""
CHANGE LOG:
-----------
$Log: dir.py  $
Revision 1.1 2021/12/13 17:59:37CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/util/project.pj
Revision 1.5 2013/03/28 15:25:17CET Mertens, Sven (uidv7805) 
pylint: W0311 (indentation), string class
- Added comments -  uidv7805 [Mar 28, 2013 3:25:17 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/03/28 09:33:19CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:19 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.3 2012/12/05 13:49:54CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:54 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 11:30:47CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 11:30:48 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 18:01:45CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/util/project.pj
"""
