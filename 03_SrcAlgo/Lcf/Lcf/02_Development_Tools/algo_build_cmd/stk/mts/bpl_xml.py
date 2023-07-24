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
import re
import xml.dom.minidom

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------
import bpl

# Defines ---------------------------------------------------------------------
BPL_SECTION_START_TIME_NAME = "startTime"
BPL_SECTION_END_TIME_NAME = "endTime"
STRING_TARGET_ENCODING = "utf-8"

BATCH_ENTRY_TAG_NAME = "BatchEntry"
BATCH_SECTION_LIST_TAG_NAME = "SectionList"
BATCH_SECTION_TAG_NAME = "Section"
BATCH_FILE_NAME_ATTR_NAME = "fileName"

# Clases ----------------------------------------------------------------------


class BPLXml(object):
    """
    Specialized BPL Class which handles only writing and reading of
    *.bpl Files.
    This class is not a customer Interface, it should only be used internal of stk.

    :author:        Robert Hecker
    :date:          12.02.2013
    """
    def __init__(self, filepath):
        self._filepath = filepath  # :FilePath of bpl file to use.
        self._reclist = bpl.BplList()

    def __getStartTimestamp(self, section):
        # Set Relative time usage to False
        relative_time = False

        start_time = section.getAttribute(BPL_SECTION_START_TIME_NAME)
        start_timestamp = re.search(r'\d+', start_time)
        is_relative_time = re.search(r'R', start_time)
        if start_timestamp:
            start_timestamp = long(start_timestamp.group(0))
        if is_relative_time:
            relative_time = True

        return start_timestamp, relative_time

    def __getEndTimestamp(self, section):
        # Get End Timestamp
        relative_time = False

        end_time = section.getAttribute(BPL_SECTION_END_TIME_NAME)
        end_timestamp = re.search(r'\d+', end_time)
        is_relative_time = re.search(r'R', end_time)
        if end_timestamp:
            end_timestamp = long(end_timestamp.group(0))
        if is_relative_time:
            relative_time = True

        return end_timestamp, relative_time

    def read(self):
        """
        Read the whole content of the Batch Play List into internal storage,
        and return all entries as a list.

        :return:        List of Recording Objects
        :rtype:         BplList
        :author:        Robert Hecker
        :date:          12.02.2013
        """
        # Parse the complete *.bpl file
        batch_dom = xml.dom.minidom.parse(self._filepath)

        # Get the complete BatchEntry List
        batch_entry_list = batch_dom.getElementsByTagName(BATCH_ENTRY_TAG_NAME)

        # Parse the whole list into a own format
        for batch_entry in batch_entry_list:

            # Get the RecFileName
            file_pathname = str(batch_entry.getAttribute(BATCH_FILE_NAME_ATTR_NAME).encode(STRING_TARGET_ENCODING))
            # member_obj = BPLXMLMember(file_pathname)
            entry = bpl.BplListEntry(file_pathname)

            # Get a Section List
            section_list = []
            batch_entry_section_list = batch_entry.getElementsByTagName(BATCH_SECTION_LIST_TAG_NAME)

            # Parse the whole Section List
            for batch_entry_section in batch_entry_section_list:
                # Get one Section
                section_list = batch_entry_section.getElementsByTagName(BATCH_SECTION_TAG_NAME)
                # Get the Attributes from the Section
                for section in section_list:

                    # Get Start Timestamp
                    start_timestamp, rel_ts_1 = self.__getStartTimestamp(section)

                    # Get End Timestamp
                    end_timestamp, rel_ts_2 = self.__getEndTimestamp(section)

                    # Add Timestamps to Section Entry if valid
                    if((start_timestamp is not None) and
                       (rel_ts_1 is not None) and
                       (rel_ts_1 == rel_ts_2)):
                        entry.append(start_timestamp, end_timestamp, rel_ts_1)

            self._reclist.append(entry)

        # Cleanup DOM
        batch_dom.unlink()

        if len(self._reclist):
            return self._reclist

    def __writeSection(self, hfile, section):
        """
        Write one Section to the Output File.

        :raise e:    if file writing fails.
        :author:     Robert Hecker
        :date:       12.02.2013
        """
        if(section.rel is True):
            tmp = "\t\t<Section startTime=\"%sR\" " % (section.startTS)
            tmp += "endTime=\"%sR\"/>\n" % (section.endTS)
            hfile.write(tmp)
        else:
            tmp = "\t\t<Section startTime=\"%s\" " % (section.startTS)
            tmp += "endTime=\"%s\"/>\n" % (section.endTS)
            hfile.write(tmp)

    def __writeSectionList(self, hfile, sectionList):
        """
        Write the whole SectionList to the Output File.

        :raise e:    if file writing fails.
        :author:     Robert Hecker
        :date:       12.02.2013
        """
        hfile.write("\t\t<SectionList>\n")

        for section in sectionList:
            self.__writeSection(hfile, section)

        hfile.write("\t\t</SectionList>\n")

    def __writeBplListEntry(self, hfile, bpllistentry):
        """
        Write one BplListEntry with included Sections to the
        Output File.

        :raise e:    if file writing fails.
        :author:     Robert Hecker
        :date:       12.02.2013
        """
        tmp = "\t<BatchEntry fileName=\"%s\">\n" % bpllistentry.filepath
        hfile.write(tmp)

        if len(bpllistentry.sectionlist) == 0:
            hfile.write("\t\t<SectionList/>\n")
        else:
            self.__writeSectionList(hfile, bpllistentry.sectionlist)

        hfile.write("\t</BatchEntry>\n")

    def write(self):
        """
        Write the complete list inside the internal storage into a file.

        :return:     nothing
        :rtype:      None
        :raise e:    if file writing fails.
        :author:     Robert Hecker
        :date:       12.02.2013
        """
        hfile = open(self._filepath, "w")
        tmp = "<?xml version=\"1.0\" encoding=\"UTF-8\" "
        tmp += "standalone=\"yes\"?>\n"
        hfile.write(tmp)
        hfile.write("<BatchList>\n")

        for entry in self._reclist:
            self.__writeBplListEntry(hfile, entry)

        hfile.write("</BatchList>")
        hfile.close()

        return 0

    def append(self, value):
        """
        Appends a new BPL-Entry into the internal Storage.

        :return:     nothing
        :rtype:      None
        :raise e:    if append fails.
        :author:     Robert Hecker
        :date:       12.02.2013
        """
        self._reclist.append(value)


"""
CHANGE LOG:
-----------
$Log: bpl_xml.py  $
Revision 1.1 2021/12/13 17:58:27CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/mts/project.pj
Revision 1.11 2013/08/27 14:42:07CEST Hecker, Robert (heckerr) 
Resolved returning of empty list.
- Added comments -  heckerr [Aug 27, 2013 2:42:07 PM CEST]
Change Package : 195175:1 http://mks-psad:7002/im/viewissue?selection=195175
Revision 1.10 2013/07/04 17:50:01CEST Hecker, Robert (heckerr) 
Removed pep8 violations.
--- Added comments ---  heckerr [Jul 4, 2013 5:50:01 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.9 2013/07/01 08:55:18CEST Hecker, Robert (heckerr)
Some Renamings from Rec... to Bpl...
Revision 1.8 2013/06/26 17:35:48CEST Hecker, Robert (heckerr)
Made some methods privat, for clear user interface.
--- Added comments ---  heckerr [Jun 26, 2013 5:35:48 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.7 2013/06/26 17:19:02CEST Hecker, Robert (heckerr)
Some finetuning in docstrings and importing.
Revision 1.6 2013/06/26 16:02:40CEST Hecker, Robert (heckerr)
Reworked bpl sub-package.
Revision 1.5 2013/06/26 10:23:25CEST Hecker, Robert (heckerr)
Increased ModuleTest Coverage for Bpl() Class.

- Get split method working and created Module Tests.
- Get write Method working and created Module Tests.
--- Added comments ---  heckerr [Jun 26, 2013 10:23:25 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.4 2013/06/06 12:32:40CEST Raedler, Guenther (uidt9430)
- fix error due to pep8 corrections
--- Added comments ---  uidt9430 [Jun 6, 2013 12:32:41 PM CEST]
Change Package : 184344:1 http://mks-psad:7002/im/viewissue?selection=184344
Revision 1.3 2013/04/03 08:02:20CEST Mertens, Sven (uidv7805)
pylint: minor error, warnings fix
--- Added comments ---  uidv7805 [Apr 3, 2013 8:02:20 AM CEST]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.2 2013/03/01 09:47:22CET Hecker, Robert (heckerr)
Updates Regarding Pep8.
--- Added comments ---  heckerr [Mar 1, 2013 9:47:22 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/13 09:36:18CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/mts/project.pj
"""
