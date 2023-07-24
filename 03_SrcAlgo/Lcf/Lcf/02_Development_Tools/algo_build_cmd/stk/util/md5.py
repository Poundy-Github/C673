"""
md5
---

MD5 Checksum calculation

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:39CET $
"""
# Import Python Modules -------------------------------------------------------
from __future__ import absolute_import
import os
import hashlib
import fnmatch
from . import dir

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------

# Functions -------------------------------------------------------------------

def CreateFromString(string, md5=None):
    """
    Creates a MD5 Checksum from a given string

    :param file_path:    Input File to calc MD5 checksum for
    :return:            MD5 Checksum
    :author:            Robert Hecker
    """
    if(md5 is None):
        md5 = hashlib.md5()
    md5.update(string)
    return md5.hexdigest()

def CreateFromFile(file_path, m=None):
    """
    Creates a MD5 Checksum from an whole File

    :param file_path:    Input File to calc MD5 checksum for
    :return:            MD5 Checksum
    :author:            Robert Hecker
    """
    if(m is None):
        m = hashlib.md5()
    f = open(file_path, 'rb')
    filesize = 0
    while True:
        block = f.read(1024)
        if not block:
            break
        filesize += len(block)
        m.update(block)
    f.close()
    return m.hexdigest()


def CreateFromFolder(folder_path, ignorelist=[]):
    """
    calculates md5 checksum recursing through subfolders

    :param folder_path: directory to start
    :param ignorelist:  optional list of folder and file names to ignore
                        e.g. ['doc', '*.bak']
    :return:            md5 checksum
    """

    m = hashlib.md5()
    digest = []
    AbsFolderList = []
    AbsFolderList.append(folder_path)

    for i in AbsFolderList:
        # check for SubFolders
        tmp = dir.list_dir_names(i)
        for j in sorted(tmp):
            if not j in ignorelist:
                AbsFolderList.append(os.path.join(i, j))
        # Check for Files
        fileset = set(dir.list_file_names(i))
        for ignore in ignorelist:
            fileset = fileset - set(fnmatch.filter(fileset, ignore))
        for j in sorted(fileset):
            path = os.path.join(i, j)
            digest = CreateFromFile(path, m)

    return digest

"""
$Log: md5.py  $
Revision 1.1 2021/12/13 17:59:39CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/util/project.pj
Revision 1.7 2013/08/08 09:05:10CEST Hecker, Robert (heckerr) 
Addd new md5 Calculation Function.
- Added comments -  heckerr [Aug 8, 2013 9:05:11 AM CEST]
Change Package : 192878:1 http://mks-psad:7002/im/viewissue?selection=192878
Revision 1.6 2013/01/16 17:11:53CET Hospes, Gerd-Joachim (uidv8815) 
use hashlib library instead of old md5
--- Added comments ---  uidv8815 [Jan 16, 2013 5:11:53 PM CET]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.5 2012/12/14 11:21:20CET Hospes, Gerd-Joachim (uidv8815)
add ignorelist to test_CreateFromFolder
--- Added comments ---  uidv8815 [Dec 14, 2012 11:21:20 AM CET]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.4 2012/12/11 14:39:16CET Hospes, Gerd-Joachim (uidv8815)
fix CreateFromFolder by using sorted lists
--- Added comments ---  uidv8815 [Dec 11, 2012 2:39:18 PM CET]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.3 2012/12/05 13:49:54CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:54 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 09:14:57CET Hecker, Robert (heckerr)
Adapted code to pep8.
--- Added comments ---  heckerr [Dec 5, 2012 9:14:57 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 18:01:47CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/util/project.pj
"""
