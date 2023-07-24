"""
stk/valf/bpl_reader
-------------------

The component for reading mts batch play list.

**User-API Interfaces**

    - `stk.valf` (complete package)
    - `BPLReader` (this module)


:org:           Continental AG
:author:        Sorin Mogos

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:51CET $

"""

# pylint: disable=C0103,W0702

# Import Python Modules -----------------------------------------------------------------------------------------------
from os import path, walk, listdir
from sys import _getframe
from re import findall, IGNORECASE

# Import STK Modules --------------------------------------------------------------------------------------------------
import stk.util.logger as log
from stk.valf.base_component_ifc import BaseComponentInterface
import stk.mts.bpl

# Defines -------------------------------------------------------------------------------------------------------------

# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class BPLReader(BaseComponentInterface):
    """

    **Observer class to handle Batch Play Lists**
    provided as bpl or ini file, called by Process_Manager during the different states

    Process Manager states used

    - `Initialize`: read the BPL file
    - `LoadData`: provide the next rec file name

    - all others (PostInitialize, ProcessData to Terminate): dummy

    Ports used on bus "Global":

      - read ``BplFilePath``: path and filename of .bpl or .ini file
      - read ``SimOutputPath``: path to simulation output files
      - read ``SimFileExt``: opt. file extension 'a' or extension list ['a','b'] of simulation files, default .csv
      - read ``SimFileBaseName``: opt. base name of simulation files, default empty string
      - read ``Recurse``: opt. recurse into sub directories if set to True, currently not complete!
      - read ``ExactMatch``: opt. set True if bpl entries should be used without possible expansion,
        default False finds name.bsig and also name_v1.bsig, name_tst.bsig etc.
      - read ``SimSelection``: used by HPC - opt. list of indices to use only particular bpl/cat entries for this run,
        list index starts with '0': e.g. ``[ 1, 3, 5, 7, 9]`` or shorter ``[(1,10,2)]`` (syntax as in range() )
      - set  ``CurrentFile``: name of current rec file as listed in bpl file
      - set  ``CurrentSimFile``: name of current sim output file loaded by BplReader
      - set  ``IsFinished``: True if last file was provided
      - read ``IsFileComplete``: check if file processing is finished,
        set by component, prevents setting ``IsFinished`` if set to True

    **remember:** ports ``BplFilePath`` and ``SimOutputPath`` are mandatory to initialize,
    port ``SimSelection`` used by `HPC` to run only one bpl entry for each task (see `Valf` class how to activate)

    file formats:
    -------------
    two different bpl file formats are supported, file extension defines the format:

    .ini file
    =========

    simple list just defining the filenames and paths::

            [SimBatch]
            FileCount=3
            File0="<path>\\<rec-filename1>"
            File1="<path>\\<rec-filename2>"
            File2="<path>\\<rec-filename3>"


    .bpl file
    =========
    xml file format,  planned to support one or more time sections for each recording::

            <?xml version="1.0" encoding="UTF-8"?>
            <BatchList>
                <BatchEntry fileName="<path>\\<rec-filename1>">
                    <SectionList/>
                </BatchEntry>
                <BatchEntry fileName="<path>\\<rec-filename1>">
                    <SectionList/>
                </BatchEntry>
                <BatchEntry fileName="<path>\\<rec-filename1>">
                    <SectionList/>
                </BatchEntry>
            </BatchList>

    usage examples:
    ---------------

    let's assume a list of recordings for the bpl with:

      rec1, rec2, rec3

    there are simulation files in ``SimOutputPath``::

        rec1.bsig
        rec1_extract.bsig
        rec1_1hil.bsig
        rec2.bsig
        rec2.csv
        rec2_1hil.bsig
        rec2_2hil.bsig
        rec3.csv
        rec3_hil.csv

    minimum setting:
    ================

    (defaults: only \*.csv, no ``ExactMatch``, empty ``SimFileBaseName``, no ``Recurse``, no ``SimSelection``)


    - set ``BplFilePath`` to .ini or .bpl file
    - set ``SimOutputPath`` to path where simulation files (\*.bsig, \*.csv) are stored

    > all \*.csv simulation files::

        rec2.csv
        rec3.csv
        rec3_hil.csv

    use bsig simulation files:
    ==========================
    - set ``SimFileExt`` to 'bsig'

    > this will get all \*.bsig files::

        rec1.bsig
        rec1_extract.bsig
        rec1_1hil.bsig
        rec2.bsig
        rec2_1hil.bsig
        rec2_2hil.bsig

    to get both, the \*.csv and \*.bsig files:
    ==========================================
    - set ``SimFileExt`` to ['bsig', 'csv']

    > this will get all files in this SimOutputPath

    to get only sim files without naming expansion like \*_1sim.bsig:
    =================================================================
    - set ``SimFileExt`` to 'bsig'
    - set ``ExactMatch`` to True

    > only rec?.bsig files::

        rec1.bsig
        rec2.bsig

    to get only sim files with naming expansion \*hil.[csv|bsig]:
    =============================================================
    - set ``SimFileExt`` to ['bsig', 'csv']
    - set ``SimFileBaseName`` to 'sim'

    > all rec\*hil.[csv|bsig] files::

        rec1_1hil.bsig
        rec2_1hil.bsig
        rec2_2hil.bsig
        rec3_hil.csv

    specifying exactly the base file name:
    ======================================
    - set ``SimFileExt`` to 'bsig'
    - set ``ExactMatch`` to True
    - set ``SimFileBaseName`` to '_1hil'

    > only rec?_1hil.bsig files::

        rec1_1hil.bsig
        rec2_1hil.bsig

    further notes:
    --------------

    The files are ordered in following way:

      - all rec1 based simulation files will be listed first
      - all rec2 based simulation files will follow
      - ... and so on

    (order of rec1, rec2,... as configured in bpl file)

    This means:

    if you need to compare several sim files of one recording in your observer you can simply

      #. configure it as listed in one of the above examples
      #. store first signals internally in the Load method of your observer
      #. store the ``CurrentSimFile`` to compare in next loop
      #. if  ``CurrentSimFile`` has not changed in next LoadData than compare signals of both sim files,
      #. otherwise: mark as error for you


    """
    def __init__(self, data_manager, component_name, bus_name=["BUS_BASE"]):  # pylint: disable=W0102
        self.__bus_name = bus_name[0]
        self.__component_name = component_name
        self.__data_manager = data_manager

        self.__logger = log.Logger(self.__component_name)

        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        self.__version = "$Revision: 1.1 $"

        self.__current_meas_file = ""
        self.__current_sim_file = ""

        self.__file_path = None
        self.__signal_names = []
        self.__delimiter = None
        self.__reader = None
        self.__meas_file_list = []
        self.__sim_file_list = []

    def Initialize(self):
        """ called once by Process_Manager, reads BPL list

        Ports "BplFilePath" and "SimOutputPath" have to be set by user
        """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        self.__data_manager.RegisterDataPort("CurrentFile", None)
        self.__data_manager.RegisterDataPort("CurrentSimFile", None, self.__bus_name)
        self.__data_manager.RegisterDataPort("IsFinished", None)
        self.__data_manager.RegisterDataPort("FileCount", None)

        self.__data_manager.SetDataPort("IsFinished", False)

        bpl_file_path = self.__data_manager.GetDataPort("BplFilePath")
        if bpl_file_path is None:
            self.__logger.error("'BplFilePath' port was not set.")
            return -1
        bpl_file_path = str(bpl_file_path).strip()

        if not path.exists(bpl_file_path):
            self.__logger.error("Bpl file path doesn't exist: '%s'" % bpl_file_path)
            return -1

        try:
            self.__reader = stk.mts.bpl.Bpl(bpl_file_path)
        except Exception, ex:  # pylint: disable=W0703
            self.__logger.exception(str(ex))
        if not self.__reader:
            self.__logger.error("Couldn't instantiate 'stkBplReader' due to the previous exception. Bpl file: '%s'." %
                                bpl_file_path)
            return -1
        reclist = self.__reader.read()
        if len(reclist) == 0:
            self.__logger.error("No recording entries found in '%s'" % bpl_file_path)
            return -1

        # Use post selection of sim files if defined
        simSelection = self.__data_manager.GetDataPort("SimSelection")
        if simSelection is not None:
            simSelection = eval(simSelection)
            self.__logger.info("'SimSelection' set to %s." % str(simSelection))

            # select only particular rec files if configured
            # to run on HPC and for developing/debugging usage
            rec_file_list = stk.mts.bpl.BplList()
            for sel in simSelection:
                if isinstance(sel, tuple):
                    sub_list = slice(*sel)  # pylint: disable=W0142
                else:
                    sub_list = slice(sel, sel + 1)
                rec_add = reclist[sub_list]
                if len(rec_add) > 0:
                    rec_file_list.extend(rec_add)
                    self.__logger.debug("select rec index %s: %s" % (sel, rec_add))
            self.__logger.info("selected %s recording file(s) for '%s' file." %
                               (len(rec_file_list), bpl_file_path))
        else:
            rec_file_list = reclist

        sim_file_path = self.__data_manager.GetDataPort("SimOutputPath", self.__bus_name)
        if sim_file_path is None:
            self.__logger.error("'SimOutputPath' port was not set.")
            return -1
        sim_file_path = str(sim_file_path).strip()

        exactMatch = self.__data_manager.GetDataPort("ExactMatch", self.__bus_name)
        if exactMatch is None:
            self.__logger.info("'ExactMatch' port was not set.")
        else:
            exactMatch = True
            self.__logger.info("Using exact match for bin file search")
        # try:
        recurse = self.__data_manager.GetDataPort("Recurse", self.__bus_name)
        # except:
        #    recurse = False   # never called as port is set to None if not set

        sim_file_ext_list = []
        sim_file_ext = self.__data_manager.GetDataPort("SimFileExt", self.__bus_name)
        if sim_file_ext is None:
            sim_file_ext_list = ["csv"]
            self.__logger.warning("'SimFileExt' port was not set. Default used instead: '%s'" % sim_file_ext_list[0])
        elif isinstance(sim_file_ext, str):
            sim_file_ext_list = [sim_file_ext]
        elif isinstance(sim_file_ext, list):
            sim_file_ext_list = sim_file_ext
        else:
            self.__logger.error("Invalid sim file extension: '%s'!" % str(sim_file_ext))
            return -1

        sim_file_base_name = ""
        sim_file_base = self.__data_manager.GetDataPort("SimFileBaseName", self.__bus_name)
        if sim_file_base is not None:
            sim_file_base_name = sim_file_base

        sim_file_path = str(path.abspath(sim_file_path))
        if not path.isdir(sim_file_path):
            self.__logger.error("Simulation output path '%s' doesn't exist." % sim_file_path)
            return -1

        self.__meas_file_list = []
        self.__sim_file_list = []

        if recurse:
            sim_file_list = self._list_files(sim_file_path, None, exactMatch, sim_file_ext_list)
            sim_file_map_list = {}
            for sim_file in sim_file_list:
                sim_file_map_list[path.basename(sim_file).lower()] = sim_file

        # try:
        files_bin_dir = str(listdir(sim_file_path)).lower()
        # except:  # exception will never be raised, if sim_file_path is empty the list is empty,
        #    self.__logger.error("No simulation file found in folder")    # existence is checked earlier
        #    return -1

        for idx in xrange(len(rec_file_list)):
            file_name = path.splitext(path.split(str(rec_file_list[idx]))[1])[0]

            sim_file_path_list = []
            for file_ext in sim_file_ext_list:
                if file_ext[0] == ".":
                    file_ext = file_ext[1:]
                if not recurse:
                    pattern = (r"[\.\w\_\-\+]*%s+[\.\w\_\-\+]*%s.%s" %
                               (file_name.lower(), sim_file_base_name.lower(), file_ext.lower()))
                    matches = findall(pattern, files_bin_dir)
                    if exactMatch is True:
                        if (file_name.lower() + '.' + file_ext) in matches:
                            sim_file_path_list.append(path.join(sim_file_path, (file_name + '.' + file_ext)))
                    else:
                        for match in matches:
                            sim_file_path_list.append(path.join(sim_file_path, match))
                else:
                    try:
                        sim_file_path_list += [sim_file_map_list[file_name.lower() + ".%s" % file_ext]]
                    except:
                        sim_file_path_list = []

            if len(sim_file_path_list) > 0:
                self.__meas_file_list.extend([str(rec_file_list[idx])] * len(sim_file_path_list))
                self.__sim_file_list.extend(sim_file_path_list)
            else:
                self.__logger.warning("No simulation file found for '%s' ending with: %s" %
                                      (str(rec_file_list[idx]),
                                       str(sim_file_base_name) + '.' + str(sim_file_ext_list)))

        if len(self.__meas_file_list) == 0:
            self.__logger.error("No simulation file found for '%s'" % bpl_file_path)
            return -1

        self.__data_manager.SetDataPort("FileCount", len(self.__meas_file_list))

        self.__meas_file_list.reverse()
        self.__sim_file_list.reverse()

        # Done
        return 0

    def PostInitialize(self):
        """ dummy, not used by BPLReader """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def LoadData(self):
        """ provides next measurement and simulation result file name
        and sets "IsFinished" to True if last file is provided
        """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        file_completed = None  # self.__data_manager.GetDataPort('IsFileComplete', self.__bus_name)
        # next_section_last = self.__data_manager.GetDataPort('NextSection', self.__bus_name)
        if file_completed is None:
            # Load full files
            # Load next measurement file
            self.__current_meas_file = self.__meas_file_list.pop()
            # Load next simulation file
            self.__current_sim_file = self.__sim_file_list.pop()

            if len(self.__meas_file_list) == 0:
                # Set next measurement file
                self.__data_manager.SetDataPort("CurrentFile", self.__current_meas_file)

                # Set next simulation file
                self.__data_manager.SetDataPort("CurrentSimFile", self.__current_sim_file, self.__bus_name)

                self.__logger.info("Loading file: '%s'" % self.__current_sim_file)
                self.__data_manager.SetDataPort("IsFinished", True)
                return 0
        else:
            pass
            # this part has to be completely reworked
            # currently it's incomplete with high risk to run into endless loop
            # as the next measurement file is not set for most of the possible permutations of
            # IsFileComplete, NextSection and len(self.__meas_file_list)

            # additionally TimeStamp sections have to be implemented:
            #     - set start/end of section on DataPort
            #     - use these in SignalExtractor

#             if file_completed is False and next_section_last is True:
#                 if len(self.__meas_file_list) == 0:
#                     # Final call
#                     self.__data_manager.SetDataPort("IsFinished", True)
#                     return 0
#             elif file_completed is True and next_section_last is False:
#                 if len(self.__meas_file_list) == 0:
#                     return 0
#                 # Load next measurement file
#                 self.__current_meas_file = self.__meas_file_list.pop()
#                 # Load next simulation file
#                 self.__current_sim_file = self.__sim_file_list.pop()
#             elif file_completed is False and next_section_last is False:
#                 if len(self.__current_meas_file) == 0:
#                     # First run
#                     self.__current_meas_file = self.__meas_file_list.pop()
#                     # Load next simulation file
#                     self.__current_sim_file = self.__sim_file_list.pop()

        # Set next measurement file
        self.__data_manager.SetDataPort("CurrentFile", self.__current_meas_file)

        # Set next simulation file
        self.__data_manager.SetDataPort("CurrentSimFile", self.__current_sim_file, self.__bus_name)

        self.__logger.info("Loading file: '%s'" % self.__current_sim_file)

        return 0

    def ProcessData(self):
        """ dummy, not used by BPLReader """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def PostProcessData(self):
        """ dummy, not used by BPLReader """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def PreTerminate(self):
        """ dummy, not used by BPLReader """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def Terminate(self):
        """ dummy, not used by BPLReader """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return 0

    def GetComponentVersion(self):
        """
        returns mks revision number
        :return: version number
        """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        revision = self.__version.find("Revision: ")
        if revision > -1:
            version = self.__version[revision + 10:-2]
        else:
            version = 0.0

        return version

    def GetComponentName(self):
        """
        returns own component name (BPLReader)
        :return: name
        """
        self.__logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        return self.__component_name

    def _list_files(self, head_dir, file_name, exMatch, file_exts=[]):  # pylint: disable=W0102
        """ returns all simulation result files in path with opt. named extension
        and optional sim name add-on

        :param head_dir: directory to search in
        :param file_name: opt file name add-on, default None
        :param exMatch: do an exact match?
        :param file_exts: opt. list of file extensions to search for, default '[]'
        :return: list [] with simulation result files
        """
        base_file_name = ''
        file_ext_list = [ext.lower() for ext in file_exts]

        if file_name is not None:
            base_file_name = path.splitext(file_name)[0]

        sim_file_path_list = []
        for root, _, _ in walk(head_dir, topdown=True):
            for file_ext in file_ext_list:
                if file_ext[0] == ".":
                    file_ext = file_ext[1:]

                sim_out_dirname = str(listdir(root))
                if file_name is not None:
                    pattern = r"[\.\w\_\-\+]*%s+[\.\w\_\-\+]*.%s" % (base_file_name, file_ext)
                    matches = findall(pattern, sim_out_dirname, IGNORECASE)
                else:
                    pattern = r"[\.\w\_\-\+]*.%s" % (file_ext)
                    matches = findall(pattern, sim_out_dirname, IGNORECASE)

                file_list = []
                if exMatch is True and file_name is not None:
                    if (base_file_name + '.' + file_ext) in matches:
                        file_list.append(path.join(root, (base_file_name + '.' + file_ext)))
                else:
                    for match in matches:
                        file_list.append(path.join(root, match))

                if len(file_list):
                    sim_file_path_list += file_list

        return sim_file_path_list

"""
$Log: bpl_reader.py  $
Revision 1.1 2021/12/13 17:59:51CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.28 2013/11/13 16:20:39CET Hospes, Gerd-Joachim (uidv8815) 
add ActivateHpcAutoSplit method and usage of port HpcAutoSplit to Valf class, updated tests and epydoc for all related files
- Added comments -  uidv8815 [Nov 13, 2013 4:20:40 PM CET]
Change Package : 206278:1 http://mks-psad:7002/im/viewissue?selection=206278
Revision 1.27 2013/10/18 13:58:53CEST Hospes, Gerd-Joachim (uidv8815) 
correct include to adapt to new stk.__init__
--- Added comments ---  uidv8815 [Oct 18, 2013 1:58:54 PM CEST]
Change Package : 190320:1 http://mks-psad:7002/im/viewissue?selection=190320
Revision 1.26 2013/08/13 17:17:51CEST Hospes, Gerd-Joachim (uidv8815)
pep8 fixes
--- Added comments ---  uidv8815 [Aug 13, 2013 5:17:52 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.25 2013/08/12 16:35:01CEST Hospes, Gerd-Joachim (uidv8815)
fixes found with test_bpl_reader.py,  removed section handling, needs to be reworked
--- Added comments ---  uidv8815 [Aug 12, 2013 4:35:01 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.24 2013/08/07 18:12:31CEST Hospes, Gerd-Joachim (uidv8815)
adapt to new BplList class
--- Added comments ---  uidv8815 [Aug 7, 2013 6:12:32 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.23 2013/07/04 11:17:50CEST Hospes, Gerd-Joachim (uidv8815)
changes for new module valf:
- process_manager initiates data_manager at init instead of load_config
- bpl uses correct module path
- processbar with simple 'include sys' to redirect process bar output
--- Added comments ---  uidv8815 [Jul 4, 2013 11:17:51 AM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.22 2013/05/29 15:55:31CEST Mertens, Sven (uidv7805)
ooops, missing W
--- Added comments ---  uidv7805 [May 29, 2013 3:55:31 PM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.21 2013/05/29 15:48:10CEST Mertens, Sven (uidv7805)
using local pylint ignores
Revision 1.20 2013/05/22 17:56:59CEST Hospes, Gerd-Joachim (uidv8815)
add feature "SimSelection" to enter list of indices for particular bpl/cat list selection
--- Added comments ---  uidv8815 [May 22, 2013 5:56:59 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.19 2013/05/15 18:14:04CEST Hospes, Gerd-Joachim (uidv8815)
pylint/pep8 corrections
--- Added comments ---  uidv8815 [May 15, 2013 6:14:04 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.18 2013/04/12 14:47:07CEST Mertens, Sven (uidv7805)
enabling the use of a connection string on observer level.
Each of them is allowed to have an additional InputData in config,
e.g. ("connectionString", "DBQ=racadmpe;Uid=DEV_MFC31X_ADMIN;Pwd=MFC31X_ADMIN"),("dbPrefix", "DEV_MFC31X_ADMIN.").
--- Added comments ---  uidv7805 [Apr 12, 2013 2:47:08 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.17 2013/04/11 14:29:44CEST Ahmed-EXT, Zaheer (uidu7634)
Exact match feature is added
--- Added comments ---  uidu7634 [Apr 11, 2013 2:29:44 PM CEST]
Change Package : 178419:2 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.16 2013/04/05 14:46:40CEST Ahmed-EXT, Zaheer (uidu7634)
Fixed bug for duplicate entries in simulation files list
--- Added comments ---  uidu7634 [Apr 5, 2013 2:46:41 PM CEST]
Change Package : 178419:2 http://mks-psad:7002/im/viewissue?selection=178419
Revision 1.15 2013/04/05 11:17:41CEST Hospes, Gerd-Joachim (uidv8815)
fix documentation
--- Added comments ---  uidv8815 [Apr 5, 2013 11:17:41 AM CEST]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.14 2013/04/03 17:17:59CEST Hospes, Gerd-Joachim (uidv8815)
next indentations
Revision 1.13 2013/04/03 17:04:27CEST Hospes, Gerd-Joachim (uidv8815)
missing indentation fixed
--- Added comments ---  uidv8815 [Apr 3, 2013 5:04:28 PM CEST]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.11 2013/04/03 13:49:27CEST Hospes, Gerd-Joachim (uidv8815)
added comments for epydoc
--- Added comments ---  uidv8815 [Apr 3, 2013 1:49:28 PM CEST]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.10 2013/04/02 10:25:47CEST Raedler, Guenther (uidt9430)
- fixed string convertion errors
--- Added comments ---  uidt9430 [Apr 2, 2013 10:25:48 AM CEST]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.9 2013/03/28 15:25:21CET Mertens, Sven (uidv7805)
pylint: W0311 (indentation), string class
--- Added comments ---  uidv7805 [Mar 28, 2013 3:25:21 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.8 2013/03/28 09:33:22CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:22 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.7 2013/03/21 17:28:00CET Mertens, Sven (uidv7805)
solving minor pylint error issues
Revision 1.6 2013/03/01 10:23:21CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:22 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.5 2013/02/28 08:12:26CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:27 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.4 2013/02/26 20:18:08CET Raedler, Guenther (uidt9430)
- Updates after Pep8 Styleguides
--- Added comments ---  uidt9430 [Feb 26, 2013 8:18:09 PM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.3 2013/02/20 08:21:25CET Hecker, Robert (heckerr)
Adapted to Pep8 Coding Style.
--- Added comments ---  heckerr [Feb 20, 2013 8:21:25 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/13 09:41:09CET Hecker, Robert (heckerr)
Get bpl_reader working with new stk.mts.Bpl class.
--- Added comments ---  heckerr [Feb 13, 2013 9:41:09 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 11:06:05CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.20 2012/07/26 15:23:45CEST Mogos, Sorin (mogoss)
* code imporvements => sim output file search
--- Added comments ---  mogoss [Jul 26, 2012 3:23:52 PM CEST]
Change Package : 134013:1 http://mks-psad:7002/im/viewissue?selection=134013
Revision 1.19 2012/07/20 13:38:41CEST Raedler-EXT, Guenther (uidt9430)
- improved parsing of sim_output folder. Use regex instead of glob.glob()
--- Added comments ---  uidt9430 [Jul 20, 2012 1:38:52 PM CEST]
Change Package : 136608:1 http://mks-psad:7002/im/viewissue?selection=136608
Revision 1.18 2012/06/15 09:58:48CEST Mogos, Sorin (mogoss)
* bug-fix for the case whne there is no simulation file associated to a recording file
--- Added comments ---  mogoss [Jun 15, 2012 9:58:48 AM CEST]
Change Package : 117828:1 http://mks-psad:7002/im/viewissue?selection=117828
Revision 1.17 2012/06/12 09:15:05CEST Mogos, Sorin (mogoss)
* update: added 'Recurse' port for scanning sub-directories while looking for simulation output files
--- Added comments ---  mogoss [Jun 12, 2012 9:15:14 AM CEST]
Change Package : 117828:1 http://mks-psad:7002/im/viewissue?selection=117828
Revision 1.16 2012/04/24 11:59:32CEST Spruck, Jochen (spruckj)
Add the posibility to read in only export files with a defined post fix name to the recfilename
--- Added comments ---  spruckj [Apr 24, 2012 11:59:40 AM CEST]
Change Package : 98074:3 http://mks-psad:7002/im/viewissue?selection=98074
Revision 1.15 2011/10/31 11:59:24CET Mogos, Sorin (mogoss)
* fix: imported inspect module
--- Added comments ---  mogoss [Oct 31, 2011 11:59:24 AM CET]
Change Package : 85403:1 http://mks-psad:7002/im/viewissue?selection=85403
Revision 1.14 2011/10/31 11:40:16CET Sorin Mogos (mogoss)
* change: changed stk library path
--- Added comments ---  mogoss [Oct 31, 2011 11:40:16 AM CET]
Change Package : 85403:1 http://mks-psad:7002/im/viewissue?selection=85403
Revision 1.13 2011/07/20 18:34:39CEST Castell Christoph (uidt6394) (uidt6394)
Added PreTerminate() function.
--- Added comments ---  uidt6394 [Jul 20, 2011 6:34:42 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.12 2011/02/08 15:54:13CET Sorin Mogos (mogoss)
* update: added support for multiple file extentions
--- Added comments ---  mogoss [Feb 8, 2011 3:54:13 PM CET]
Change Package : 58986:1 http://mks-psad:7002/im/viewissue?selection=58986
Revision 1.11 2011/01/25 12:40:11CET Ovidiu Raicu (RaicuO)
Updated to work with sections.
--- Added comments ---  RaicuO [Jan 25, 2011 12:40:11 PM CET]
Change Package : 37852:2 http://mks-psad:7002/im/viewissue?selection=37852
Revision 1.10 2010/10/03 11:46:13CEST Sorin Mogos (mogoss)
* removed component_name parameter from SetDataPort
--- Added comments ---  mogoss [Oct 3, 2010 11:46:13 AM CEST]
Change Package : 51595:1 http://mks-psad:7002/im/viewissue?selection=51595
Revision 1.9 2010/07/20 12:55:00CEST Sorin Mogos (mogoss)
* code optimisation
--- Added comments ---  mogoss [Jul 20, 2010 12:55:00 PM CEST]
Change Package : 47041:2 http://mks-psad:7002/im/viewissue?selection=47041
Revision 1.8 2010/06/28 14:46:12EEST Sorin Mogos (smogos)
* added configuration manager
--- Added comments ---  smogos [2010/06/28 11:46:12Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.7 2010/03/19 10:33:15EET Sorin Mogos (smogos)
* code customisation and bug-fixes
--- Added comments ---  smogos [2010/03/19 08:33:15Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.6 2010/03/04 09:16:28EET Gicu Benchea (gbenchea)
Add the bus constructor parameter
--- Added comments ---  gbenchea [2010/03/04 07:16:28Z]
Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
Revision 1.5 2010/02/19 12:20:16EET Sorin Mogos (smogos)
* bug-fixes
--- Added comments ---  smogos [2010/02/19 10:20:17Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.4 2010/02/19 11:40:30EET Sorin Mogos (smogos)
* bug-fixes
--- Added comments ---  smogos [2010/02/19 09:40:30Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.3 2010/02/18 15:29:29EET Sorin Mogos (smogos)
* code optimisation and bug-fixes
--- Added comments ---  smogos [2010/02/18 13:29:30Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.2 2009/11/18 13:09:44EET Sorin Mogos (smogos)
* some bug-fixes
--- Added comments ---  smogos [2009/11/18 11:09:44Z]
Change Package : 33973:1 http://LISS014:6001/im/viewissue?selection=33973
Revision 1.1 2009/10/30 14:18:40EET dkubera
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/
    04_Engineering/VALF_ValidationFrame/04_Engineering/31_PyLib/project.pj
"""
