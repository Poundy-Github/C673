# -*- coding: iso-8859-1 -*-
"""
stk/mts/parser
--------------

Classes for checking the mts output.

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:58:28CET $
"""
# Import Python Modules -------------------------------------------------------
from xml.dom.minidom import parse
import xml.parsers.expat as expat
from re import match

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------

class ErrorItem(object):
    """
    Error Item Element.

    :author:        Robert Hecker
    :date:          10.12.2013
    """
    def __init__(self, severity, errCode, errDesc, errSrc):
        self.severity = severity
        self.errCode = errCode
        self.errDesc = errDesc
        self.errSrc = errSrc


class Crash(object):
    """
    Parse Crashdumps files created by MTS and provide the information due the
    ErrorItem interface.

    :author:        Robert Hecker
    :date:          10.12.2013
    """

    # define levels, counters and attributes
    levels = ["debug", "information", "warning", "error", "alert", "exception", "crash"]

    def __init__(self, filepath):
        """
        Do the Parsing of the given Chrashdump file.

        :param filepath: Url to the File to be used.
        :type filepath:  string
        :author:         Robert Hecker
        :date:           10.12.2013
        """
        self.__filepath = filepath
        self.__results = []

        self.__Parse()

    def __Parse(self):
        """
        Do the real Parsing of the given file.

        :author:         Sven Mertens
        :date:           10.12.2013
        """
        data = {}

        try:
            xml = parse(self.__filepath)
            for elem in xml.getElementsByTagName("general")[0].childNodes:
                if elem.nodeType == elem.ELEMENT_NODE:
                    data[elem.nodeName] = elem.firstChild.data

            for elem in xml.getElementsByTagName("symbol"):
                if "srcfile" and "srcline" in elem.attributes.keys():
                    data["fault_module"] += (" (%s: %s)" % (elem.attributes["srcfile"].value,
                                                            elem.attributes["srcline"].value))
                    break

            self.__results.append(ErrorItem(len(self.levels) - 1, int(data["except_code"], 16),
                                   data["except_descr"], data["fault_module"]))

        except expat.ExpatError:
            self.__results.append(ErrorItem(len(self.levels) - 1, -1, "Unreadable Crashdump", self.__filepath))


    def GetChrashInfo(self):
        """
        Do the real Parsing of the given file.

        :return:         the found crash information
        :rtype:          list[ErrorItem,...]
        :author:         Robert Hecker
        :date:           10.12.2013
        """
        return self.__results


class Xlog(object):
    """
    Parse xlog files created by MTS and provide the information due the
    ErrorItem interface.

    :author:        Robert Hecker
    :date:          10.12.2013
    """

    # define levels, counters and attributes
    levels = ["debug", "information", "warning", "error", "alert", "exception", "crash"]

    def __init__(self, filepath):
        """
        Do the Parsing of the given *.xlog file.

        :param filepath: Url to the File to be used.
        :type filepath:  string
        :author:         Robert Hecker
        :date:           10.12.2013
        """
        self.__filepath = filepath
        self.__results = []  # level, ErrorCode, ErrorDesc, ErrorSource

        self.__Parse()

    def __Parse(self):
        """
        Do the real Parsing of the given file.

        :author:         Sven Mertens
        :date:           10.12.2013
        """
        try:

            for elem in parse(self.__filepath).getElementsByTagName("LogEntry"):
                lev = self.levels.index(elem.getAttribute("Severity").lower())
                if lev == 5:  # exception
                    msg = match(r"^\[(.*)\]:\sException:\s(0x.*)\s\((.*)\)\sat\sAddress:\s(.*)$",
                                elem.firstChild.data.strip('" ').replace("'", r"''")).groups()
                    self.__results.append(ErrorItem(lev, int(msg[1], 16), msg[2], msg[0]))
                else:
                    self.__results.append(ErrorItem(lev, int(elem.getAttribute("Code"), 16),
                                           elem.firstChild.data.strip('" ').replace("'", r"''"),
                                           elem.getAttribute("Reporter")))
        except expat.ExpatError:
            self.__results.append(ErrorItem(-1, -1, "Unreadable xlog", self.__filepath))


    def GetExceptions(self):
        """
        Return all found exceptions in the xlog file.

        :return:         the found exceptions
        :rtype:          list[ErrorItem,...]
        :author:         Robert Hecker
        :date:           10.12.2013
        """
        results = []  # level, ErrorCode, ErrorDesc, ErrorSource

        for elem in self.__results:
            if elem.severity == 5 or elem.severity == -1:  # exception
                results.append(elem)

        return results

    def GetErrors(self):
        """
        Return all found errors in the xlog file.

        :return:         the found errors
        :rtype:          list[ErrorItem,...]
        :author:         Robert Hecker
        :date:           10.12.2013
        """
        results = []  # level, ErrorCode, ErrorDesc, ErrorSource

        for elem in self.__results:
            if elem.severity == 3 or elem.severity == -1:  # error
                results.append(elem)

        return results
"""
CHANGE LOG:
-----------
$Log: parser.py  $
Revision 1.1 2021/12/13 17:58:28CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/mts/project.pj
Revision 1.1 2013/12/10 19:37:12CET Hecker, Robert (heckerr) 
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/mts/project.pj
"""
