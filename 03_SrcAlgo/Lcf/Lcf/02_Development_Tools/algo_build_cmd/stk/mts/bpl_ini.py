"""
stk/mts/bpl
-----------

Classes for BPL (BatchPlayList) Handling

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:27CET $
"""
# Import Python Modules -------------------------------------------------------

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------
import stk.util.ini as ini
import bpl

# Import Local Python Modules -------------------------------------------------

# Defines ---------------------------------------------------------------------
INI_FILE_SECTION_NAME = "SimBatch"
INI_FILE_FILE_COUNT = "FileCount"

# Clases ----------------------------------------------------------------------


class BPLIni(object):
    """
    Specialized BPL Class which handles only writing and reading of
    *.ini Files.
    This class is not a customer Interface, it should only be used internal of stk.

    :author:        Robert Hecker
    :date:          12.02.2013
    """
    def __init__(self, filepath):
        self._ini = ini.Ini()
        self._filepath = filepath
        self.__RecList = bpl.BplList()

    def read(self):
        """
        Reads the batch play list file content.

        @rtype: list
        @return: The list of file entries or None if there is no entry.
        """
        self.__RecList.clear()
        self._ini.Open(self._filepath)
        count = int(self._ini.ReadKey(INI_FILE_SECTION_NAME,
                                      INI_FILE_FILE_COUNT))

        for el in range(count):
            url = self._ini.ReadKey(INI_FILE_SECTION_NAME, "File%d" % el)
            url = url.replace("\\\\", "\\")
            url = url.replace('"', '')

            self.__RecList.append(bpl.BplListEntry(url))

        return self.__RecList

    def write(self):
        """
        Write the complete recfilelist to the file.

        @rtype: number or None
        @return: 0 if successfully or None if error
        """
        hfile = open(self._filepath, "w")
        hfile.write("[SimBatch]\n")
        hfile.write("FileCount=%d\n" % len(self.__RecList))

        idx = 0
        for item in self.__RecList:
            item = item.replace("\\", "\\\\")
            hfile.write("File%d=\"%s\"\n" % (idx, item))
            idx = idx + 1

        hfile.close()

    def append(self, value):
        """
        append one reclistentry.

        :param value: BpllistEntry with Sectioninformation.
        :type value:  BplListEntry
        :return:      -
        :rtype:       -
        :author:      Robert Hecker
        :date:        20.06.2013
        """
        self.__RecList.append(str(value))

"""
CHANGE LOG:
-----------
$Log: bpl_ini.py  $
Revision 1.1 2021/12/13 17:58:27CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/mts/project.pj
Revision 1.12 2013/07/04 17:47:12CEST Hecker, Robert (heckerr) 
Removed some pep8 violations.
- Added comments -  heckerr [Jul 4, 2013 5:47:12 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.11 2013/07/01 08:54:25CEST Hecker, Robert (heckerr)
Some Renamings from Rec... to Bpl...
Revision 1.10 2013/06/26 17:35:08CEST Hecker, Robert (heckerr)
REmoved unused Code.
Revision 1.9 2013/06/26 17:19:02CEST Hecker, Robert (heckerr)
Some finetuning in docstrings and importing.
Revision 1.8 2013/06/26 16:02:39CEST Hecker, Robert (heckerr)
Reworked bpl sub-package.
Revision 1.7 2013/06/26 10:23:25CEST Hecker, Robert (heckerr)
Increased ModuleTest Coverage for Bpl() Class.

- Get split method working and created Module Tests.
- Get write Method working and created Module Tests.
Revision 1.6 2013/04/10 09:29:35CEST Mertens, Sven (uidv7805)
file -> f (fix)
--- Added comments ---  uidv7805 [Apr 10, 2013 9:29:36 AM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.5 2013/04/03 08:02:11CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:11 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/03/01 09:47:21CET Hecker, Robert (heckerr)
Updates Regarding Pep8.
--- Added comments ---  heckerr [Mar 1, 2013 9:47:21 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/27 17:55:09CET Hecker, Robert (heckerr)
Removed all E000 - E200 Errors regarding Pep8.
--- Added comments ---  heckerr [Feb 27, 2013 5:55:09 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/20 11:51:39CET Hospes, Gerd-Joachim (uidv8815)
fix bpl ini write to use double backslash in path names
--- Added comments ---  uidv8815 [Feb 20, 2013 11:51:39 AM CET]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.1 2013/02/13 09:36:17CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/mts/project.pj
"""
