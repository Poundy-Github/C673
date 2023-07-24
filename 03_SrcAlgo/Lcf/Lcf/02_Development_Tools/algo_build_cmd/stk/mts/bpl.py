# -*- coding: iso-8859-1 -*-
"""
stk/mts/bpl
-----------

Classes for BPL (BatchPlayList) Handling

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:28CET $
"""
# Import Python Modules -------------------------------------------------------
import os

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------
from . import bpl_xml
from . import bpl_ini

# Functions -------------------------------------------------------------------


def __getFileSizeMB(filepath):  # pylint: disable=C0103
    """
    Returns the File Size of a File in Megabytes (MB)
    """
    if os.path.isfile(filepath):
        file_size = os.path.getsize(filepath)
        file_size /= 1024  # B  -> KB
        file_size /= 1024  # KB -> MB
    else:
        file_size = 1.0

    return file_size


def singleSplit(bplfilepath, outfolder):  # pylint: disable=C0103
    """
    Split a bpl-file into singel bpl's which
    contians the original section information.

    :param bplfilepath: Filepath(url) to the bpl file..
    :type bplfilepath:  string
    :param outfolder:   Folder to store the generated bpl files.
    :type outfolder:    string
    :return:            Array of created bpl files.
    :rtype:             list of bpl paths.
    :author:            Robert Hecker
    :date:              06.08.2013
    """
    bpllist = []

    # Open the *.bpl file
    bpl = Bpl(bplfilepath)
    # Read the whole list
    inputlist = bpl.read()

    counter = 1

    for item in inputlist:
        # Create a new BPL File in TaskName style
        fileName = "Rec%05d.bpl" % counter
        counter += 1
        outBpl = Bpl(os.path.join(outfolder, fileName))
        outBpl.append(item)
        outBpl.write()
        bpllist.append(os.path.join(outfolder, fileName))

    return bpllist

def split(bplfilepath, task_size, outfolder=None):  # pylint: disable=C0103
    """
    Split a bpl-file into bpl's with the given task_size which
    contians the original section information.

    :param bplfilepath: Filepath(url) to the bpl file..
    :type bplfilepath:  string
    :param task_size:   Number of recordings per file.
    :type task_size:    int
    :param outfolder:   Folder to store the generated bpl files.
    :type outfolder:    string
    :return:            Array of created bpl files.
    :rtype:             list of bpl paths.
    :author:            Guenther Raedler
    :date:              16.09.2013
    """
    bpllist = []

    # Open the *.bpl file
    bpl = Bpl(bplfilepath)
    # Read the whole list
    inputlist = bpl.read()

    task_cnt = 0
    counter = 0
    while counter < len(inputlist):
        # Create a new BPL File in TaskName style
        fileName = "T%05d.bpl" % (task_cnt + 1)
        outBpl = Bpl(os.path.join(outfolder, fileName))
        file_cnt = 0
        while file_cnt < task_size and counter < len(inputlist):
            item = inputlist[counter]
            outBpl.append(item)
            file_cnt += 1
            counter += 1

        task_cnt += 1
        outBpl.write()
        bpllist.append(os.path.join(outfolder, fileName))

    return bpllist



def split_parts(bplfilepath, parts, outfolder=None):  # pylint: disable=C0103
    """
    Split a Bpl BatchList into n parts.
    The splitting algorithm tries to split all files regarding the filesize
    of the recording. So one split.bpl file could contain less files,
    if the files have a bigger filesize.
    The pbl Files which are splitted, will be saved in the same folder like
    the original bplfile was found.

    :param bplfilepath: Filepath(url) to the bpl or ini file.
    :type bplfilepath:  string
    :param part:        Number of wanted splits.
    :type part:         integer
    :return:            nothing
    :rtype:             None
    :author:            Robert Hecker
    :date:              12.02.2013
    """

    if(outfolder is None):
        outfolder = os.path.split(bplfilepath)[0]

    # Open the existing bplfilelist and get all members
    bpl = Bpl(bplfilepath)
    recList = bpl.read()

    # Get for every File the Filesize
    fileSizeList = []
    for item in recList:
        fileSizeList.append(__getFileSizeMB(str(item)))

    # Calculate the Total Size
    totalSize = 0
    for size in fileSizeList:
        totalSize += size

    file_part_size = totalSize / parts

    filePart = 0
    idx = 0
    filePartList = []
    # Create all Filepart lists
    while idx < len(fileSizeList):

        # Create One Bpl-Content
        bplSize = 0
        bplList = []
        while(bplSize < file_part_size or (filePart + 1) == parts):
            # Append New Element to Current BPL List
            bplList.append(recList[idx])
            # Increase BplSize
            bplSize += fileSizeList[idx]
            idx += 1
            if(idx >= len(fileSizeList)):
                break
        # Increase FilePart Index
        filePart += 1
        # Add BplList to final List
        filePartList.append(bplList)

    # Writes the BPL File Parts into new BPL Files
    head, ext = os.path.splitext(bplfilepath)

    for idx in xrange(0, len(filePartList)):
        file_part = filePartList[idx]
        tmp = "_part_%02d_of_%02d%s" % (idx + 1, parts, ext)
        file_part_pathname = os.path.join(outfolder, head + tmp)
        writer = Bpl(file_part_pathname)
        for file_part_member in file_part:
            writer.append(file_part_member)
        writer.write()

# Classes ---------------------------------------------------------------------


class Section(object):  # pylint: disable=R0903
    """                 # container class as used in C++ 
    This class is a Data-Container which hold the Section Information
    for bpl-lists.

    :author:        Robert Hecker
    :date:          26.06.2013
    """
    def __init__(self, startTS, endTS, rel):
        self.startTS = startTS
        self.endTS = endTS
        self.rel = rel


class BplListEntry(object):
    """
    This class is a Data-Container which holds following Information:
     - RecFilePath
     - list of all Sections applied to the file.

    :author:        Robert Hecker
    :date:          26.06.2013
    """
    def __init__(self, filepath):
        self.filepath = filepath
        self.sectionlist = []
                                            # name following general python names
    def append(self, startTS, endTS, rel):  # pylint: disable=C0103
        """
        append one section entry into this BplListEntry.

        :param startTS: StartTimestamp of Section
        :type startTS:  uint
        :param endTS:   EndTimestamp of Section
        :type endTS:    uint
        :param rel:     relative Timestamp Format (true/false)
        :type rel:      bool
        :return:        -
        :rtype:         -
        :author:        Robert Hecker
        :date:          20.06.2013
        """
        section = Section(startTS, endTS, rel)
        self.sectionlist.append(section)

    def __str__(self):
        return self.filepath


class BplList(list):
    """
    This class is the main data-container for the Bpl()-Class.
    It is build out of a list of BplListEntries

    :author:        Robert Hecker
    :date:          26.06.2013
    """
    def __init__(self):
        list.__init__(self)
        self.reclist = []

    def __len__(self):
        return len(self.reclist)

    def __iter__(self):
        return self.reclist.__iter__()

    def __getitem__(self, index):
        return list.__getitem__(self.reclist, index)

                      # name according list type
    def clear(self):  # pylint: disable=C0103
        """
        delete the whole internal RecFileList.

        :author:        Robert Hecker
        :date:          20.06.2013
        """
        self.reclist = []

                                     # name according list type
    def append(self, reclistentry):  # pylint: disable=C0103
        """
        append one reclistentry.

        :param reclistentry: BpllistEntry with Sectioninormation.
        :type reclistentry:  BplListEntry
        :return:             -
        :rtype:              -
        :author:             Robert Hecker
        :date:               20.06.2013
        """
        self.reclist.append(reclistentry)

                                    # name according list type
    def extend(self, reclistlist):  # pylint: disable=C0103
        """
        extend to internal reclist
        """
        self.reclist.extend(reclistlist)

                        # name according list type
    def reverse(self):  # pylint: disable=C0103
        """
        reverse internal reclist
        """
        self.reclist.reverse()


class Bpl(object):
    """
    Possibility to read and write Batch Play Lists supported by mts.
    Currently *.ini and *.bpl based BatchPlayLists are supported.

    :author:        Robert Hecker
    :date:          12.02.2013

    usage (example)
    ---------------
    .. python::

        # Create a Instance of your BPL-Reader
        bpl = stk.mts.Bpl(r"D:/MyBatchPlayList.bpl")

        # Get whole RecFile List out from bpl file
        BplList = bpl.read()

        # Iterate over whole list in a for loop
        for item in BplList:
            print str(item) # Convertion to string is mandatory !!!.

    """
    def __init__(self, filepath):
        """
        Set the filepath to be used later on for reading or writing files.
        Depending of the given Filepath, a internal i/o-class will be called
        either for *.bpl files or *.ini files.

        :param filepath: Url to the File to be used.
        :type filepath:  string
        :return:         nothing
        :rtype:          None
        :raise IOError:  if given filetype is not supported.
        :author:         Robert Hecker
        :date:           12.02.2013
        """
        self.__mode = ""
        self.__reader = None

        self.__open(filepath)

    def __open(self, filepath):
        """
        Set the filepath to be used later on for reading or writing files.
        Depending of the given Filepath, a internal i/o-class will be called
        either for *.bpl files or *.ini files.

        :param filepath: Url to the File to be used.
        :type filepath:  string
        :return:         nothing
        :rtype:          None
        :raise IOError:  if given filetype is not supported.
        :author:         Robert Hecker
        :date:           12.02.2013
        """
        # Determine File type
        ext = os.path.splitext(filepath)

        # Check File Type
        if(ext[1].lower() == ".bpl"):
            # Create Instance of BPLReader
            self.__reader = bpl_xml.BPLXml(filepath)
        elif(ext[1].lower() == ".ini"):
            self.__reader = bpl_ini.BPLIni(filepath)
        else:
            raise IOError("Unsupported File Format")

                     # name according python file handling
    def read(self):  # pylint: disable=C0103
        """
        Read the whole content of the Batch Play List into internal storage,
        and return all entries as a list.

        :return:        List of Recording Objects
        :rtype:         BplList
        :author:        Robert Hecker
        :date:          12.02.2013
        """
        return self.__reader.read()

                      # name according python file handling
    def write(self):  # pylint: disable=C0103
        """
        Write the complete list inside the internal storage into a file.

        :return:     nothing
        :rtype:      None
        :raise e:    if file writing fails.
        :author:     Robert Hecker
        :date:       12.02.2013
        """
        return self.__reader.write()

                              # name according python file handling
    def append(self, value):  # pylint: disable=C0103
        """
        Appends a new BPL-Entry into the internal Storage.

        :return:     nothing
        :rtype:      None
        :raise e:    if append fails.
        :author:     Robert Hecker
        :date:       12.02.2013
        """
        return self.__reader.append(value)

"""
CHANGE LOG:
-----------
$Log: bpl.py  $
Revision 1.1 2021/12/13 17:58:28CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/mts/project.pj
Revision 1.18 2013/09/24 15:50:07CEST Raedler, Guenther (uidt9430) 
- enable original split function and renamed it
- Added comments -  uidt9430 [Sep 24, 2013 3:50:07 PM CEST]
Change Package : 198327:1 http://mks-psad:7002/im/viewissue?selection=198327
Revision 1.17 2013/09/24 15:47:07CEST Raedler, Guenther (uidt9430) 
- Add new splitting function to support BLF section simulations (ARS353, ARs4xx)
--- Added comments ---  uidt9430 [Sep 24, 2013 3:47:08 PM CEST]
Change Package : 198327:1 http://mks-psad:7002/im/viewissue?selection=198327
Revision 1.16 2013/08/08 08:37:11CEST Hospes, Gerd-Joachim (uidv8815) 
fix pylint and pep8 problems
--- Added comments ---  uidv8815 [Aug 8, 2013 8:37:11 AM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.15 2013/08/07 18:13:43CEST Hospes, Gerd-Joachim (uidv8815)
fix class BplList to support extend, append and other list methods
--- Added comments ---  uidv8815 [Aug 7, 2013 6:13:44 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.14 2013/08/06 15:48:00CEST Hecker, Robert (heckerr)
Added new singleSplit Funtion to bpl module.
--- Added comments ---  heckerr [Aug 6, 2013 3:48:01 PM CEST]
Change Package : 192878:1 http://mks-psad:7002/im/viewissue?selection=192878
Revision 1.13 2013/07/04 17:45:35CEST Hecker, Robert (heckerr)
Removed pep8 violations.
--- Added comments ---  heckerr [Jul 4, 2013 5:45:36 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.12 2013/07/01 08:55:18CEST Hecker, Robert (heckerr)
Some Renamings from Rec... to Bpl...
Revision 1.11 2013/06/26 17:19:02CEST Hecker, Robert (heckerr)
Some finetuning in docstrings and importing.
Revision 1.10 2013/06/26 16:02:40CEST Hecker, Robert (heckerr)
Reworked bpl sub-package.
Revision 1.9 2013/06/26 10:51:40CEST Hecker, Robert (heckerr)
Reduced pylint errors.
--- Added comments ---  heckerr [Jun 26, 2013 10:51:40 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.8 2013/06/26 10:23:24CEST Hecker, Robert (heckerr)
Increased ModuleTest Coverage for Bpl() Class.

- Get split method working and created Module Tests.
- Get write Method working and created Module Tests.
Revision 1.7 2013/03/28 11:10:55CET Mertens, Sven (uidv7805)
pylint: last unused import removed
--- Added comments ---  uidv7805 [Mar 28, 2013 11:10:55 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.6 2013/03/01 09:47:22CET Hecker, Robert (heckerr)
Updates Regarding Pep8.
--- Added comments ---  heckerr [Mar 1, 2013 9:47:22 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/13 09:39:38CET Hecker, Robert (heckerr)
Improved usability of BPL io.
--- Added comments ---  heckerr [Feb 13, 2013 9:39:38 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2012/12/14 16:22:48CET Hecker, Robert (heckerr)
Removed stk Prefixes in Classes, Member Variables,....
--- Added comments ---  heckerr [Dec 14, 2012 4:22:48 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/05 13:49:48CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:48 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 09:59:25CET Hecker, Robert (heckerr)
Updated Code partly regarding pep8
--- Added comments ---  heckerr [Dec 5, 2012 9:59:25 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:56:53CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/mts/project.pj
"""
