"""
valf.py
-------

Class to provide methods to start a validation.

**User-API Interfaces**

    - `stk.valf` (complete package)
    - `Valf` (this module)
    - `GetSwVersion` (this module)


:org:           Continental AG
:author:        Joachim Hospes

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:54CET $
"""

#===============================================================================
# User settings
#===============================================================================

#===============================================================================
# System Imports
#===============================================================================
import os
import shutil
import sys
import time
import inspect
import re

#===============================================================================
# Master settings
#===============================================================================
HEAD_DIR = os.path.abspath(os.path.join(os.path.dirname(inspect.currentframe().f_code.co_filename), "..\\.."))
if HEAD_DIR not in sys.path:
    sys.path.append(HEAD_DIR)

#===============================================================================
# Local Imports
#===============================================================================
import stk.util.logger as log
from stk.util.helper import ListFolders
import stk.db.db_common
import stk.valf as valf
import stk.valf.db_connector as valf_db
import stk.valf.signal_defs as sd
from stk.error import StkError
from stk.valf.error import ValfError

#===============================================================================
# Constant declarations
#===============================================================================
DEFAULT_SLAVE_DATA_PROVIDER = "Microsoft.SQLSERVER.MOBILE.OLEDB.3.0"
DEFAULT_SLAVE_DATA_SOURCE = "db_acc_performance.sdf"
DEFAULT_TABLE_PREFIX = ""
TABLE_PREFIX_PATTERN = "<project>_<function>"

# Error codes.
RET_VAL_OK = 0
RET_GEN_ERROR = -1
RET_SYS_EXIT = -2
RET_CFG_ERROR = -3

DATA_BUS_NAMES = "DataBusNames"


def CreateClearFolder(pathname, purge=True):
    '''
    empty given folder completely or create a new one

    :param pathname: folder to empty or create
    :type pathname:  string

    :param purge:    default ``True``, set to ``False`` if the given path should not be cleared
    :type purge:     boolean
    '''
    if not os.path.exists(pathname):
        try:
            os.makedirs(pathname)
        except StandardError:
            sys.stderr.write("Error while creating folder: '%s'." % pathname)
            sys.exit(RET_GEN_ERROR)
    elif purge is True:
        try:
            pathname = os.path.abspath(pathname)
            for entry in os.listdir(pathname):
                file_path = os.path.join(pathname, entry)
                if os.path.isdir(file_path):
                    shutil.rmtree(file_path)
                elif os.path.isfile(file_path):
                    os.remove(file_path)
        except StandardError:
            sys.stderr.write("Error while removing folder: '%s'." % pathname)
            sys.exit(RET_GEN_ERROR)


def GetSwVersion():
    '''
    get some string as sw version either by

      - checking call arguments of main script for one parameter and take that
      - requesting direct user input if not running on `HPC`

    and raising exit(-3) if called on `HPC` without parameter

    :return: test-sw version
    :rtype:  string

    usage examples
    ==============
    in your start script:

    .. python::

        vsuite = stk.valf.Valf(my_out_path, my_log_level, [my_plugin_path1, ...])
        vsuite.SetSwVersion(stk.valf.GetSwVersion())

    a) call argument

        run your start script like::

            d:\tests\start_vali.py AL_FUNCT_03.05.01-INT2

    a) direct input (only on workstation, not for HPC submits)

        run your start script like::

          d:\tests\start_vali.py

        and get the input request::

          enter test sw version (checkpoint):

    '''
    test_sw_version = None
    if len(sys.argv) > 2:
        sys.exit("ERROR in calling main program, only one argument accepted: test sw version")
    elif len(sys.argv) == 2:
        test_sw_version = sys.argv[1]
    elif os.getenv("TaskName") is None and os.getenv('JobName') is None:
        while test_sw_version is None or len(test_sw_version) < 1:
            test_sw_version = raw_input("enter test sw version (checkpoint):")
    else:
        sys.stderr.write("ERROR: running on HPC but no algo sw version provided as call parameter\n")
        sys.stderr.write("set SW version on data port ")
        sys.exit(RET_CFG_ERROR)
    return test_sw_version

#==============================================================================
# Classes
#==============================================================================


class Valf(object):
    """
    class defining methods to easily start validation suites
    by calling a python script without additional option settings (double click in win)

    mandatory settings:

     - outputpath (as instantiation parameter)
     - config file with `load_config`()
     - sw version of sw under test with `set_sw_version`()

    returns error level::

      RET_VAL_OK = 0       suite returned without error
      RET_GEN_ERROR = -1   general error
      RET_SYS_EXIT = -2    sys.exit called
      RET_CFG_ERROR = -3   error in direct settings or configuration file

    **Example:**

    .. python::

        # Import valf module
        from stk.valf import valf

        # set output path for logging ect., logging level and directory of plugins (if not subdir of current HEADDIR):
        vsuite = valf.Valf(os.getenv('HPCTaskDataFolder'), 10)  # logging level DEBUG, default level: INFO

        # mandatory: set config file and version of sw under test
        vsuite.LoadConfig(r'demo\\cfg\\bpl_demo.cfg')
        vsuite.SetSwVersion('AL_STK_V02.00.06')

        # additional defines not already set in config files or to be overwritten:
        vsuite.SetBplFile(r'cfg\\bpl.ini')
        vsuite.SetSimPath(r'\\\\Lifs010.cw01.contiwan.com\\data\\MFC310\\SOD_Development')

        # start validation:
        vsuite.Run()

    :author:        Joachim Hospes
    :date:          29.05.2013

    """
    def __init__(self, outpath, logging_level=log.INFO, plugin_search_path=[HEAD_DIR],  # pylint: disable=W0102
                 clean_folder=True):
        """
        initialise all needed variables and settings

          - creates/cleans output folder
          - start process manager
          - start logging of all events, therefore the output path must be given

        :param outpath:       path to output directory, can be relative to calling script
        :type outpath:        string

        :param logging_level: level of details to be displayed. default: info
                              (10=debug, 20=info, 30=warning, 40=error, 50=critical, 60=exception)
        :type logging_level:  integer [10|20|30|40|50]

        :param plugin_search_path: default: parent dir of stk folder, normally parallel to validation scripts
        :type plugin_search_path:  string

        :param clean_folder:  default ``True``, set to ``False`` if the files in output folder should not be deleted
                              during instantiation of Valf
        :type clean_folder:   boolean
        """
        self.__version = "$Revision: 1.1 $"
        self.__outpath = outpath
        self.__swversion = None

        self.__data_bus_names = []  # store all names of generated data busses like bus#0
        self.__process_mgr = None
        self.__logger = None

        # prep output directory: create or clear content
        outpath = os.path.abspath(outpath)
        CreateClearFolder(outpath, clean_folder)

        # get name of calling function
        frm = sys._current_frames().values()[0].f_back  # pylint: disable=W0212
        frm_filename = os.path.splitext(os.path.basename(frm.f_code.co_filename))[0]
        frm_fct_name = str(frm.f_code.co_name)
        # if not called from function but pure python module set logger name to file name of the module
        if '<' in frm_fct_name:
            print("changed name from %s to: %s" % (str(frm_fct_name), str(frm_filename)))
            frm_fct_name = frm_filename
        # start logger, first with default level, idea for extension: can be changed later
        self.__logger = log.Logger(frm_fct_name, logging_level,
                                   filename=os.path.join(outpath, frm_filename) + ".log")
        self.__logger.info("Validation started at " + time.strftime('%H:%M:%S', time.localtime(time.time())))
        self.__logger.info("Logging level is set to %s." % (log.LEVEL_INFO_MAP.get(logging_level)))

        # find all observers down current path
        plugin_folder_list = []
        for spath in plugin_search_path:
            for folder_path in ListFolders(spath):
                if "stk" not in folder_path:
                    plugin_folder_list.append(folder_path)
                else:
                    print folder_path

            self.__logger.info('added to plugin search path:' + spath)
        # and add all observers down calling script's path
        stk_plugins = [os.path.join(HEAD_DIR, "stk", "valf"), os.path.join(HEAD_DIR, "stk", "val")]

        for spath in plugin_search_path:
            plugin_folder_list.append(spath)

        for spath in stk_plugins:
            plugin_folder_list.append(spath)
            self.__logger.debug('added to plugin search path:' + spath)

        # start process manager
        try:
            self.__process_mgr = valf.ProcessManager(plugin_folder_list)
        except StandardError:
            # standarderror catches all?
            self.__logger.error("Couldn't instantiate 'ProcessManager' class. ")
            sys.exit(RET_GEN_ERROR)

        self.__process_mgr.set_data_port(sd.OUTPUTDIRPATH_PORT_NAME, os.path.abspath(outpath))
        self.__logger.debug("OutputDirPath: '%s'" % outpath)

        self.__SetDefaultSettings()

    def __SetDefaultSettings(self):
        """ private method

        set all default settings as have been in valf.main
        """
        self.SetMasterDbDsn(stk.db.db_common.DEFAULT_MASTER_DSN)
        self.SetMasterDbDbq(stk.db.db_common.DEFAULT_MASTER_DBQ)
        self.SetMasterDbPrefix(stk.db.db_common.DEFAULT_MASTER_SCHEMA_PREFIX)
        self.SetErrorTolerance(stk.db.db_common.ERROR_TOLERANCE_NONE)

        # should be activated some day, for now not all validation suites can be parallelised
        # if set on default we should invent a method DeactivateHpcAutoSplit to run the remaining or old suites
        # self.SetDataPort("HpcAutoSplit", True, "Global")

    def __CheckMandatorySettings(self):
        """ private method

        check if additional mandatory settings are done

        does not run complete sanity check for config, here we just check additional mandatory settings
        that do not prevent the validation to run if they are missing
        e.g. no test if db connection is defined for cat reader, if not set cat reader will stop the initialisation

        :return:   number of missing settings, 0 if settings completed
        :rtype:    integer
        """
        error_cnt = 0

        if self.GetDataPort("SWVersion", "Global") is None:
            self.__logger.error("version of test sw not defined!")
            error_cnt += 1

        if self.GetDataPort("HpcAutoSplit", "Global") is True \
        and self.GetDataPort("SimSelection", "Global") is not None:
            self.__logger.error("DataPort 'SimSelection' used by HPC, not available if 'HpcAutoSplit' is active!")
            self.__logger.error("Set either 'HpcAutoSplit' to False or don't set 'SimSelection'!")
            error_cnt += 1

        return error_cnt

    def __SetHpcSelection(self):
        """ private method

        if the start script is running as HPC task on an HPC machine then
        set SimSelection to use only the entry given by the task number.
        e.g. for HPC task003: set SimSelection to [2]
        """
        # check HPC usage
        if self.GetDataPort("HpcAutoSplit", "Global") is True:
            task_name = os.getenv("TaskName")
            try:
                # T0000x task ids start with 1,  bpl list index with 0
                task_id = int(re.match('T(\d+)', str(task_name)).group(1)) - 1
            except AttributeError:
                self.__logger.error("can't set Hpc Auto Split value as HPC environment variable Task Id"
                                    " is empty or not valid: %s" % task_name)
                sys.exit(RET_CFG_ERROR)
            self.__logger.info("HpcAutoSplit: using entry %d of the sim collection" % task_id)
            self.SetDataPort("SimSelection", "[%d]" % task_id, "Global")

    def LoadConfig(self, filepath):
        """
        load configuration from path/filename, path can be relative to calling script

        :param filepath: path and filename of the config file to load
        :type filepath:  string

        usage (example):

        .. python::

          from stk.valf import Valf

          vrun = stk.valf.Valf()
          vrun.load_config(r'conf/validation.cfg')

        """
        absfile = os.path.abspath(filepath)
        config_filename = self.__process_mgr.get_data_port(sd.CFG_FILE_PORT_NAME)
        if config_filename is None:
            config_filename = absfile
        else:
            config_filename += ', ' + absfile
        self.__process_mgr.set_data_port(sd.CFG_FILE_PORT_NAME, absfile)
        if self.__logger is not None:
            self.__logger.info("Using configuration file: '%s'" % absfile)
            try:
                if not self.__process_mgr.load_configuration(absfile):
                    sys.exit(RET_CFG_ERROR)
            except SystemExit:
                self.__logger.error('system exit by one module during configuration load')
                sys.exit(RET_SYS_EXIT)
            except StkError, details:
                self.__logger.error("StkError raised: %s" % details)
                raise
            except:
                self.__logger.error("unexpected error (%s) during configuration load" % str(sys.exc_info))
                sys.exit(RET_GEN_ERROR)

    def SetBplFile(self, filepath):
        """
        set data port ``BplFilePath`` to path/filename of bpl file (.ini or .bpl)
        path can be relative to starting script, checks existence of file and stops in case of errors

        :param filepath: path/filename of batch play list
        :type filepath:  string
        """
        absfilepath = os.path.abspath(filepath)
        self.__logger.debug("BplFilePath: '%s'" % absfilepath)
        if filepath is not None and os.path.isfile(absfilepath):
            self.__process_mgr.set_data_port(sd.PLAY_LIST_FILE_PORT_NAME, absfilepath)
        else:
            self.__logger.error("Invalid mts batch play list.")
            sys.exit(RET_CFG_ERROR)

    def SetCollectionName(self, collection_name):
        """
        set data port ``RecCatCollectionName`` giving the collection name of rec files in catalog db
        used by the cat reader to select the recording list for a project

        :param collection_name: name of the collection
        :type collection_name:  string
        """
        self.__process_mgr.set_data_port(sd.COLLECTION_NAME_PORT_NAME, collection_name)
        self.__logger.debug("Rec file cataloge collection name is: '%s'" % collection_name)

    def SetDataPort(self, port_name, value, bus_name='Global'):
        """
        set named valf data port at named bus with given value,
        can be repeated for different ports and bus names

        in general these ports should be set using the config file ``InputData`` entry!

        :param port_name: valf data port name, not case sensitiv
        :type port_name:  string
        :param value:     port value, type depends on port usage
        :type value:      user defined
        :param bus_name:  valf data bus name, default: ``Global``, not case sensitiv
        :type bus_name:   string
        """
        self.__process_mgr.set_data_port(port_name, value, bus_name)
        self.__logger.debug('valf script setting port "%s" :' % port_name + str(value))

    def SetDbFile(self, filepath):
        """
        set data port ``dbfile`` to define name of sqlite data base file to be used instead of oracle db
        checks existence of the file and raises an error if it's not readable

        :param filepath: path/name of the database file
        :type filepath:  string
        """
        database_filename = os.path.abspath(filepath)
        if not os.path.exists(database_filename):
            self.__logger.error("defined db file '%s' not found" % filepath)
            sys.exit(RET_CFG_ERROR)
        self.__process_mgr.set_data_port(valf_db.DB_FILE_PORT_NAME, filepath, 'DBBus#1')

    def SetErrorTolerance(self, tolerance):
        """
        set data port ``ErrorTolerance`` to a value as defined in `db_commmon`

        :param tolerance: error tolerance value
        :type tolerance:  integer
        """
        self.__process_mgr.set_data_port(sd.ERROR_TOLERANCE_PORT_NAME, tolerance, "Bus#1")

    def SetMasterDbDbq(self, dbq):
        """
        set data port "masterdbdbq" (name defined in `valf.db_connector`) to given name
        default value defined in db.db_common by DEFAULT_MASTER_DBQ

        :param dbq: data base qualifier for oracle data bases
        :type dbq:  string
        :note:      don't use together with DSN setting
        """
        self.__process_mgr.set_data_port(valf_db.MASTER_DB_DBQ_PORT_NAME, dbq, "DBBus#1")

    def SetMasterDbDsn(self, dsn):
        """
        set data port ``masterdbdsn`` (name defined in `valf.db_connector`) to given name
        default value defined in db.db_common by DEFAULT_MASTER_DSN

        :param dsn: data source name for odbc interface connections
        :type dsn:  string
        :note:      don't use together with DBQ setting
        """
        self.__process_mgr.set_data_port(valf_db.MASTER_DB_DSN_PORT_NAME, dsn, "DBBus#1")

    def SetMasterDbUser(self, user):
        """
        set data port ``masterdbuser`` (name defined in `valf.db_connector`) to given name

        :param user: name of data base user
        :type user:  string
        """
        self.__process_mgr.set_data_port(valf_db.MASTER_DB_USR_PORT_NAME, user, "DBBus#1")

    def SetMasterDbPwd(self, passwd):
        """
        set data port ``masterdbpassword`` (name defined in `valf.db_connector`) to given name

        :param passwd: password for data base user
        :type passwd:  string
        """
        self.__process_mgr.set_data_port(valf_db.MASTER_DB_PW_PORT_NAME, passwd, "DBBus#1")

    def SetMasterDbPrefix(self, prefix):
        """
        set data port ``masterdbschemaprefix`` (name defined in `valf.db_connector`) to given name

        :param prefix: schema prefix for data base table
        :type prefix:  string
        """
        self.__process_mgr.set_data_port(valf_db.MASTER_DB_SPX_PORT_NAME, prefix, "DBBus#1")

    def SetSimPath(self, pathname, bus_name="Bus#1"):
        """
        set data port ``SimOutputPath`` at named bus (default:``Bus#0``) to given path
        where measurement files are stored

        checks if path exists and raises an `ValfError` if not

        for historical reasons the bus_name is set as default to ``bus#0``
        make sure your config sets the similar busses for bpl/cat reader(s)!

        :param pathname: absolute path where simulation result files are stored
        :type pathname:  string
        :param bus_name: data bus name of the bpl/cat reader, default ``bus#0``, not case sensitiv
        :type bus_name:  string
        """
        if os.path.exists(pathname):
            self.__process_mgr.set_data_port(sd.SIM_PATH_PORT_NAME, pathname, bus_name)
            self.__logger.debug("Setting input data. [ Bus='{0}', "
                                "PortName='SimOutputPath', PortValue={1}]".format(bus_name, pathname))
            if bus_name not in self.__data_bus_names:
                self.__data_bus_names.append(bus_name)
                self.__process_mgr.set_data_port(DATA_BUS_NAMES, self.__data_bus_names)
        else:
            # replace StandardError by
            raise ValfError("Sim Output folder providing bsig/csv files does not exist:\n%s\nPlease check your setup"
                           % pathname)

    def SetSwVersion(self, version):
        """
        set data port ``SWVersion`` to given value
        currently mandatory setting!!

        :param version: sw version of sw under test
        :type version:  string
        """
        self.__process_mgr.set_data_port(sd.SWVERSION_PORT_NAME, version)

    def SetRefSwVersion(self, version):
        """
        set data port ``SWVersion_REG`` to given value (optional)

        :param version: sw version of regression sw under test
        :type version:  string
        """
        self.__process_mgr.set_data_port(sd.SWVERSION_REG_PORT_NAME, version)

    def SetSaveResults(self, saveit=True):
        """
        set data port ``SaveResultInDB`` to given value (optional)

        :param saveit: Save the results into the database, default = True
        :type saveit:  boolean
        """
        self.__process_mgr.set_data_port(sd.SAVE_RESULT_IN_DB, saveit)

    def GetDataPort(self, port_name, bus_name='Global'):
        """
        get named valf data port at named bus,
        can be repeated for different ports and bus names

        :param port_name: valf data port name, not case sensitiv
        :type port_name:  string

        :param bus_name: valf data bus name, default: ``Global``, not case sensitiv
        :type bus_name:  string

        :return: port data
        :rtype:  undefined
        """
        return self.__process_mgr.get_data_port(port_name, bus_name)

    def ActivateHpcAutoSplit(self):
        """
        activate auto splitting of bpl/cat list on HPC

        Running on HPC a validation can run in parallel on several tasks. This method sets data port ``HpcAutoSplit``
        to ``True`` so each validation suite running on one task/machine only reads the sim results of one recording::

              bpl / cat list       HPC TaskID
            ---------------------- ----------
            recording_entry_0.rec    T00001
            recording_entry_1.rec    T00002
            recording_entry_2.rec    T00003
            ...                      ...

        """
        self.SetDataPort(sd.HPC_AUTO_SPLIT_PORT_NAME, True, 'global')

    def Run(self):
        """ start the validation after all needed preparations

        :return:  success or error value during validation run
        :rtype:   error codes:
          RET_VAL_OK = 0
          RET_GEN_ERROR = -1
          RET_SYS_EXIT = -2
          RET_CFG_ERROR = -3

        """
        if self.__CheckMandatorySettings() is not 0:
            self.__logger.error("error in setup: mandatory settings missing")
            sys.exit(RET_CFG_ERROR)
        tstart = time.time()
        self.__SetHpcSelection()
        try:
            ret_val = self.__process_mgr.run()
        except SystemError:
            self.__logger.error("general system error called")
            sys.exit(RET_SYS_EXIT)
        except:
            self.__logger.error("unexpected runtime error")
            sys.exit(RET_GEN_ERROR)

        if ret_val is RET_VAL_OK:
            self.__logger.info("Test duration(hh:mm:ss): "
                               + time.strftime('%H:%M:%S', time.gmtime(time.time() - tstart)))
            logger_statistics = self.__logger.get_statistics()
            log_info_list = []
            for logging_level in logger_statistics:
                log_info_list.append("%s: %d" % (logging_level, logger_statistics[logging_level]))

            self.__logger.info("Logging statistics: " + ", ".join(log_info_list))
        else:
            self.__logger.error("runtime error in validation suite, error level %d" % ret_val)

        print 'val run ended with result', ret_val
        return ret_val

"""
CHANGE LOG:
-----------
$Log: valf.py  $
Revision 1.1 2021/12/13 17:59:54CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.14 2013/11/13 17:50:28CET Hospes, Gerd-Joachim (uidv8815) 
type description in docu fixed
- Added comments -  uidv8815 [Nov 13, 2013 5:50:28 PM CET]
Change Package : 206278:1 http://mks-psad:7002/im/viewissue?selection=206278
Revision 1.13 2013/11/13 16:20:38CET Hospes, Gerd-Joachim (uidv8815) 
add ActivateHpcAutoSplit method and usage of port HpcAutoSplit to Valf class, updated tests and epydoc for all related files
--- Added comments ---  uidv8815 [Nov 13, 2013 4:20:39 PM CET]
Change Package : 206278:1 http://mks-psad:7002/im/viewissue?selection=206278
Revision 1.12 2013/11/05 11:46:25CET Raedler, Guenther (uidt9430)
- add root path for plugins
--- Added comments ---  uidt9430 [Nov 5, 2013 11:46:26 AM CET]
Change Package : 199465:1 http://mks-psad:7002/im/viewissue?selection=199465
Revision 1.11 2013/10/02 11:44:45CEST Mertens, Sven (uidv7805)
well, sys need to be used directly as it seems to differ from imported variable
--- Added comments ---  uidv7805 [Oct 2, 2013 11:44:45 AM CEST]
Change Package : 185933:7 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.10 2013/10/02 11:24:17CEST Mertens, Sven (uidv7805)
removing additional pylint/pep8 warnings
--- Added comments ---  uidv7805 [Oct 2, 2013 11:24:17 AM CEST]
Change Package : 185933:7 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.9 2013/10/02 11:16:19CEST Mertens, Sven (uidv7805)
help to prevent removal of simulation output data from previous tasks,
defaults stay as they are: output folder is cleared
--- Added comments ---  uidv7805 [Oct 2, 2013 11:16:20 AM CEST]
Change Package : 185933:7 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.8 2013/10/01 13:48:09CEST Hospes, Gerd-Joachim (uidv8815)
new error msg for operator load problems
--- Added comments ---  uidv8815 [Oct 1, 2013 1:48:10 PM CEST]
Change Package : 196951:1 http://mks-psad:7002/im/viewissue?selection=196951
Revision 1.7 2013/10/01 07:32:25CEST Raedler, Guenther (uidt9430)
- added new method to get data ports
--- Added comments ---  uidt9430 [Oct 1, 2013 7:32:26 AM CEST]
Change Package : 197855:1 http://mks-psad:7002/im/viewissue?selection=197855
Revision 1.6 2013/09/19 10:42:56CEST Raedler, Guenther (uidt9430)
- added possiblility to customize plugin folder (review by R.H.)
- use signal_def for Ports
- added busname as argument in SetSimPath(). removed automated bus name generation as not useful.
- created new methods SetRefSwVersion() and SetSaveResults()
--- Added comments ---  uidt9430 [Sep 19, 2013 10:42:56 AM CEST]
Change Package : 197855:1 http://mks-psad:7002/im/viewissue?selection=197855
Revision 1.5 2013/07/16 13:16:01CEST Hospes, Gerd-Joachim (uidv8815)
update to new style guide
--- Added comments ---  uidv8815 [Jul 16, 2013 1:16:01 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.4 2013/07/05 11:47:52CEST Hospes, Gerd-Joachim (uidv8815)
remove nasty prints left from testing
--- Added comments ---  uidv8815 [Jul 5, 2013 11:47:52 AM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.3 2013/07/04 14:34:29CEST Hospes, Gerd-Joachim (uidv8815)
pep8 fix
--- Added comments ---  uidv8815 [Jul 4, 2013 2:34:29 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.2 2013/07/04 14:12:59CEST Hospes, Gerd-Joachim (uidv8815)
set simpath second time can't be tested on Jenkins
--- Added comments ---  uidv8815 [Jul 4, 2013 2:12:59 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.1 2013/07/04 11:09:23CEST Hospes, Gerd-Joachim (uidv8815)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
"""
