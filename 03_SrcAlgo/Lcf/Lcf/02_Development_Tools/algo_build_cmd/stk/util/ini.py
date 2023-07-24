# -*- coding: iso-8859-1 -*-
"""
stk_ini
-------

Reading and Writing *.ini Files

:org:           Continental AG
:author:        Robert Hecker
                David Kubera

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:38CET $
"""
# Import Python Modules -------------------------------------------------------
import re

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------

# Defines ---------------------------------------------------------------------
STRING_TARGET_ENCODING = "utf-8"
SCRIPT_ENCODING = "iso-8859-1"

# Classes ---------------------------------------------------------------------


class Ini:
    """
    Class which hase Base Methods for Reading and Writing Ini Files
    """
    __section = re.compile(r'^\[(.*)\]\s*')
    __key = re.compile(r'^([^\s]*)\s*=\s*(.*)$')

    ## The constructor.
    def __init__(self):
        """
        Initialize all unused Variables
        """
        self.__data = {}
        self.__FilePath = ""

    ## The destructor.
    def __del__(self):
        self.__FilePath = ""

    def __Read(self):
        """
        Read the whole Ini File and creates the
        internal storage for the Ini File.

        :author:                 Robert Hecker
        """
        #Open File for Reading
        f = file(self.__FilePath)
        #initialize section
        sec = ""
        #read whole file and process it
        for line_tmp in f:
            # decode and encode from mostly used windows
            # file encoding to standard py-script encoding
            line = (line_tmp.decode(SCRIPT_ENCODING)).encode(STRING_TARGET_ENCODING)

            #Check after new Section [.....]
            matchObj = self.__section.match(line)
            if(matchObj is not None):
                #Found new Section
                sec = str(matchObj.group(1))
                #Check if section is inside _data
                if not (sec in self.__data):
                    #Add Section to _data
                    self.__data[sec] = {}
            else:
                #Found Key in Section
                matchObj = self.__key.match(line)
                if(matchObj is not None):
                    #Found Key in Line
                    #get key and value
                    key, val = matchObj.group(1, 2)
                    self.__data[sec][str(key)] = val
        #close file
        f.close()
        #delete file object
        del f

    def Write(self):
        """
        Write the whole Ini File to Disk. The FilePath which is
        used is either set by the Open Function or by the SetFilePath Function
        :autho:   Robert Hecker
        """
        #Write actual Dataset to ini File
        f = file(self.__FilePath, 'w')
        #Go through whole dataset and write data
        for section in self.__data:
            f.write('[' + section + ']\n')
            for key in self.__data[section]:
                f.write(key + '=' + str(self.__data[section][str(key)]) + '\n')
            f.write('\n')

        #close file
        f.close()
        #delete file object
        del f

    def SetIniPath(self, FilePath):
        """
        Set the Ini FilePath which must be used to Write the Ini File to Disk
        :author: Robert Hecker
        """
        self.__FilePath = FilePath

    def Open(self, FilePath):
        """
        Open the Ini File specified by Path, and read the whole Ini File
        into internal storage
        :author:  Robert Hecker
        """
        #store FilePath in Member Variable
        self.__FilePath = FilePath
        #Read Ini File
        self.__Read()

    def WriteKey(self, SectionName, KeyName, Value):
        """
        Set the Value specified by KeyName and SectionName to the Internal Ini
        File Storage. When SectionName or KeyName not exist, it will be created

        :param SectionName:    [SectionName]
        :param KeyName:        KeyName=...
        :param Value:              ...=Value

        :author:               Robert Hecker
        """
        #Check if Section is insid _data
        if not SectionName in self.__data:
            #Add Section to _data
            self.__data[SectionName] = {}
        self.__data[SectionName][str(KeyName)] = Value

    def ReadKey(self, SectionName, KeyName, DefaultValue=0):
        """
        Read the Value specified by KeyName and SectionName from the Internal
        Ini File Storage. When SectionName or KeyName not exist, it will be
        created and filled with the Default Value. Value will be returned via
        return Value.

        :param SectionName:    [SectionName]
        :param KeyName:        KeyName=...
        :param DefaultValue:        ..=Value
        :return:               Return value or default value
        :author:               Robert Hecker
        """
        #Check if Section is insid _data
        if not SectionName in self.__data:
            self.WriteKey(SectionName, KeyName, DefaultValue)

        if not KeyName in self.__data[SectionName]:
            self.WriteKey(SectionName, KeyName, DefaultValue)

        return self.__data[SectionName][str(KeyName)]

    def GetSections(self):
        """
        Returns a list with the sections in the ini file.

        :return:               Returns list of sections or None
        :author:               Ovidiu Raicu
        """
        return self.__data.keys()

    def GetSectionKeys(self, section_name):
        """
        Returns a list of keys that bellong to the specified section

        :param section_name:   [section_name]

        :return:               Returns list of keys or None.
        :author:               Ovidiu Raicu
        """
        if section_name in self.__data:
            keys = []
            for item in self.__data[section_name]:
                keys.append(item)

            return keys
        else:
            return None

    def DeleteKey(self, section_name, key_name):
        """
        Returns a list of keys that bellong to the specified section

        :param section_name:   [section_name]
        :param key_name:       key_name=...

        :return:               Returns True if succesfull or False.
        :author:               Ovidiu Raicu
        """
        if section_name in self.__data:
            if key_name in self.__data[section_name]:
                del self.__data[section_name][key_name]
                return True
        return False

"""
$Log: ini.py  $
Revision 1.1 2021/12/13 17:59:38CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/util/project.pj
Revision 1.5 2013/03/05 15:50:42CET Hecker, Robert (heckerr) 
Get Ini Class Full tested and Working.
- Added comments -  heckerr [Mar 5, 2013 3:50:42 PM CET]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.4 2012/12/11 08:14:12CET Hecker, Robert (heckerr)
Removed stk Prefis from stkIni.
--- Added comments ---  heckerr [Dec 11, 2012 8:14:12 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2012/12/05 13:49:49CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:50 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 11:43:02CET Hecker, Robert (heckerr)
Update to pep8 styleguide.
--- Added comments ---  heckerr [Dec 5, 2012 11:43:05 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 18:01:46CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/util/project.pj
"""
