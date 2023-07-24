"""
signal_extractor.py
-------------------

Extracts signal data from binary file format.

**User-API Interfaces**

    - `stk.valf` (complete package)
    - `SignalExtractor` (this module)

:org:           Continental AG
:author:        Ovidiu Raicu

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:54CET $
"""

# pylint: disable=C0103,W0702

#======================================================================================================================
# Imports
#======================================================================================================================
from os import path
from sys import path as sp, exit as sexit, _getframe
import time
import inspect
import gc

PYLIB = path.abspath(path.join(path.dirname(inspect.currentframe().f_code.co_filename), "..", ".."))
if PYLIB not in sp:
    sp.append(PYLIB)

from stk.valf.base_component_ifc import BaseComponentInterface as bci

import stk.valf.signal_defs as sig_gd
from stk.io.bsig import BsigReader, bsig_200_exception
from stk.util.logger import Logger

#======================================================================================================================
# Global Deffinitions
#======================================================================================================================
# Speed test
SPEED_TEST = False

# Component names
GLOBAL_NAME = "Global"

# Other defines
OBJ_MIN_LIFETIME_DEFAULT = 10
INVALID_OBJECT = [255, -1]
IGNORE_OOI_FIRST_CYCLES = 10
DATA_SOURCE_SIM = 1
DATA_SOURCE_DEVICE = 2

# Ports for object list
PORT_NAME_OBJ_PREFIX = "OBJ_prefix"
PORT_NAME_OBJ_SIGNALS = "OBJ_signals"
PORT_NAME_OBJ_COUNT = "OBJ_number_of_objects"
PORT_NAME_OBJ_MIN_LIFETIME = "OBJ_min_lifetime"

# Ports for OOI
PORT_NAME_OOI_PREFIX = "OOI_prefix"
PORT_NAME_OOI_SIGNALS = "OOI_signals"
PORT_NAME_OOI_COUNT = "OOI_number_of_objects"

# Ports for FCT
PORT_NAME_FCT_PREFIX = "FCT_prefix"
PORT_NAME_FCT_SIGNALS = "FCT_signals"

# Ports for VDYD
PORT_NAME_VDY_PREFIX = "VDY_prefix"
PORT_NAME_VDY_SIGNALS = "VDY_signals"

# Ports for Ibeo data
PORT_NAME_IBEO_OBJ_PREFIX = "IbeoOut_Prefix"
PORT_NAME_IBEO_OBJ_SIGNALS = "IbeoOut_ObjSignals"
PORT_NAME_IBEO_OBJ_LENGTH = "IbeoOut_Length"
PORT_NAME_IBEO_OBJ_COUNT = "IbeoOut_Count"

# Ports for SOD data
PORT_NAME_SOD_OBJ_PREFIX = "SODOut_Prefix"
PORT_NAME_SOD_OBJ_SIGNALS = "SODOut_ObjSignals"
PORT_NAME_SOD_OBJ_LENGTH = "SODOut_Length"
PORT_NAME_SOD_OBJ_COUNT = "SODOut_Count"

# Extra ports
PORT_NAME_ADDIT_SIGNALS = "ADDITIONAL_signals"

# HIL & SIL port with dict names
PORT_NAME_HIL_CONFIG = 'HilValidationConfig'
PORT_NAME_SIL_SYNC_CONFIG = 'SilSilSyncConfig'
ENABLE_CONVERSION = 'EnableTimeConversion'
ORI_TIME_FILE_EXT = 'OriTimeFileExtension'
SYNC_SIGNAL = 'SyncSignalName'
SIL_SYNC_SIGNAL = 'SilSyncSignalName'
SIL_ABSOLUTE_TS = 'AbsoluteTimestamp' #hard coded
SIL_IMAGE_TS = 'ImageTimestamp'
SIL_SYNC_TS = 'SyncTimestamp'
HIL_TIME_SIGNAL = 'HilTimeSignalName'
ORI_TIME_SIGNAL = 'OriTimeSignalName'
HIL_TMSTAMP_FILE_EXT = 'tstp'

# Output ports
PORT_NAME_EXTRACTOR_CONFIG = "SignalExtractorConfig"

# Other
PORT_NAME_REL_OBJ_ID = "rel_obj_id"
PORT_NAME_UILIFETIME = "uiLifeTime"
PORT_NAME = "PortName"
SIGNAL_NAME = "SignalName"
COUNT = "Count"

# Ibeo Port Names
PORT_NAME_IBEO_OBJ_ID = "ObjID"

# Modules
MOD_OBJ = "OBJ"
MOD_OOI = "OOI"
MOD_FCT = "FCT"
MOD_VDY = "VDY"

# Default configuration for data extractor
DEFAULT_SIGNAL_EXTRACTOR_CONFIGURATION = {'EnableOBJList': False,
                                          'EnableOOIList': False,
                                          'EnableFCTData': False,
                                          'EnableVDYData': False,
                                          'DataSource': DATA_SOURCE_SIM}

#======================================================================================================================
# Classes
#======================================================================================================================


class SignalExtractor(bci):  # pylint: disable=R0902,R0923
    """
    observer class to extract single signals or signal objects from simulation result file

    called by process manager in the states:

     - Initialize: get lists of signals and signal objects to register ports and prepare extraction
     - ProcessData: extract configured signals and objects to given ports
     - PostProcessData: clear ports and internal lists to prepare next extraction

    Ports used on bus "BASE_BUS" as listed in state functions
    """
    def __init__(self, data_manager, component_name, bus_name):
        """init the needed
        """
        bci.__init__(self, data_manager, component_name, bus_name)
        # self._logger = Logger(component_name)
        self._version = "$Revision: 1.1 $"

        # Set up the bin reader.
        self.__bin_read = BsigReader()

        # Object counts
        self.__radar_obj_count = 0  # 40 in ARS301
        self.__ooi_obj_count = 0  # 6 in ARS301
        self.__ibeo_obj_length = 0
        self.__sod_obj_length = 0
        self.__ibeo_obj_count_signal_name = 0
        self.__ibeo_obj_count_port_name = 0
        self.__sod_obj_count_signal_name = 0
        self.__sod_obj_count_port_name = 0

        # Signal port and name lists from config file.
        self.__obj_port_and_signal_names = []
        self.__obj_port_and_signal_names_expanded = []
        self.__ooi_port_and_signal_names = []
        self.__ooi_port_and_signal_names_expanded = []
        self.__fct_port_and_signal_names = []
        self.__vdy_port_and_signal_names = []
        self.__ibeo_obj_port_and_signal_names = []
        self.__ibeo_obj_port_and_signal_names_expanded = []
        self.__sod_obj_port_and_signal_names = []
        self.__sod_obj_port_and_signal_names_expanded = []
        self.__addit_port_and_signal_names = []

        # Port names
        self.__obj_port_names = []
        self.__ooi_port_names = []
        self.__ibeo_obj_port_names = []
        self.__sod_obj_port_names = []

        # Data
        self.__objects_list = []
        self.__ooi_obj_list = {}
        self.__ibeo_objects_list = []
        self.__sod_objects_list = []

        # Others
        self.__object_id = 0
        self.__ibeo_object_id = 0
        self.__rel_obj_id = []
        self.__extractor_configuration = {}
        self.__obj_min_lifetime = 0

        # HIL time stamp conversion settings from config file
        self.__use_hil_tmstmp = False
        self.__use_sil_tmstmp = False
        self.__hil_config = None
        self.__sil_config = None

    # --- Framework functions. --------------------------------------------------
    def Initialize(self):  # pylint: disable=R0912
        """
        Read ports OBJ_min_lifetime and SignalExtractorConfig if defined in config, using default values otherwise.
        Initializes ports for signal objects and additional signals as defined.

        default values:

          - 'OBJ_min_lifetime':10
          - 'EnableOBJList'   :False,
          - 'EnableOOIList'   :False,
          - 'EnableFCTData'   :False,
          - 'EnableVDYData'   :False,
          - 'DataSource'      :1

        """
        self._logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        # Get the min object lifetime.
        try:
            self.__obj_min_lifetime = self.__GetDataPort(PORT_NAME_OBJ_MIN_LIFETIME, int, None)
        except:
            # Keep the default.
            self.__obj_min_lifetime = OBJ_MIN_LIFETIME_DEFAULT

        # Read PORT_NAME_EXTRACTOR_CONFIG
        self.__extractor_configuration = self._data_manager.GetDataPort(PORT_NAME_EXTRACTOR_CONFIG, self._bus_name)
        if self.__extractor_configuration is None and self.__extractor_configuration is not False:
            self._logger.info("The port '%s' is not defined. Using default configuration."
                              % PORT_NAME_EXTRACTOR_CONFIG)
            self.__extractor_configuration = DEFAULT_SIGNAL_EXTRACTOR_CONFIGURATION

        # Initialise additional signal list.
        self.__InitAdditionalSignalList()

        # Initialize ObjectList, OOIList, FCTData, VDYData.
        if 'EnableOBJList' in self.__extractor_configuration and self.__extractor_configuration['EnableOBJList']:
            self.__InitObjectList()
        if 'EnableOOIList' in self.__extractor_configuration and self.__extractor_configuration['EnableOOIList']:
            self.__InitOOIList()
        if 'EnableFCTData' in self.__extractor_configuration and self.__extractor_configuration['EnableFCTData']:
            self.__InitFCT()
        if 'EnableVDYData' in self.__extractor_configuration and self.__extractor_configuration['EnableVDYData']:
            self.__InitVDY()
        if 'EnableIBEOList' in self.__extractor_configuration and self.__extractor_configuration['EnableIBEOList']:
            self.__InitIbeoObjectList()
        if 'EnableSODList' in self.__extractor_configuration and self.__extractor_configuration['EnableSODList']:
            self.__InitSodObjectList()

        self.__hil_config = self._data_manager.GetDataPort(PORT_NAME_HIL_CONFIG, self._bus_name)
        self.__sil_config = self._data_manager.GetDataPort(PORT_NAME_SIL_SYNC_CONFIG, self._bus_name)

        if self.__hil_config is not None:
            if ENABLE_CONVERSION in self.__hil_config and self.__hil_config[ENABLE_CONVERSION] is True:
                # ignore HIL config is HIL is not activated
                self.__use_hil_tmstmp = True
                self._logger.info('HIL time stamp conversion activated')

                # check all HIL config and report all errors at once
                # file extension for bsig file with original time stamps
                if ORI_TIME_FILE_EXT not in self.__hil_config:
                    self.__hil_config[ORI_TIME_FILE_EXT] = HIL_TMSTAMP_FILE_EXT
                self._logger.info("HIL time stamp files extension set to '%s'"
                                  % self.__hil_config[ORI_TIME_FILE_EXT])
                # mandatory name of original time stamp signal to copy in HIL output
                if ORI_TIME_SIGNAL in self.__hil_config:
                    # optional name of time stamp signal as stored in HIL output, default same as ori. TS signal name,
                    if HIL_TIME_SIGNAL not in self.__hil_config:
                        self.__hil_config[HIL_TIME_SIGNAL] = self.__hil_config[ORI_TIME_SIGNAL]
                        self._logger.info("name of HIL Time signal to change is not set, using same as %s"
                                          % ORI_TIME_SIGNAL)
                else:
                    self._logger.error("HIL Time Stamp settings wrong, missing value for %s" % ORI_TIME_SIGNAL)
                    return sig_gd.RET_VAL_ERROR
                # mandatory name of signal to synch time stamps, should be embedded time stamp signal
                # it should have same values for both files, so only one config needed
                if SYNC_SIGNAL not in self.__hil_config:
                    self._logger.error("HIL Time Stamp settings wrong, missing value for %s" % SYNC_SIGNAL)
                    return sig_gd.RET_VAL_ERROR

            else:
                self._logger.info("no HIL time conversion used, set value '%s' to True to activate"
                                  % ENABLE_CONVERSION)

        if self.__sil_config is not None:
            if ENABLE_CONVERSION in self.__sil_config and self.__sil_config[ENABLE_CONVERSION] is True:
                self.__use_sil_tmstmp = True
                self._logger.info('SIL time stamp conversion activated')

            if SIL_SYNC_SIGNAL not in self.__sil_config:
                self._logger.error("SIL Time Stamp settings wrong, missing value for %s" % SIL_SYNC_SIGNAL)
                return sig_gd.RET_VAL_ERROR


        return sig_gd.RET_VAL_OK

    def PostInitialize(self):
        """ PostInitialize. not used here. """
        self._logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return sig_gd.RET_VAL_OK

    def LoadData(self):  # pylint: disable=R0912
        """ LoadData. Called for each "CurrentSimFile".
        extracting signals as defined in config, sending to given ports,
        checks existence of bsig reader,
        can log execution time if SPEED_TEST set to True
        """
        self._logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        # Get the current simulation file.
        current_sim_file = self._data_manager.GetDataPort("CurrentSimFile", self._bus_name)
        if current_sim_file is None:
            self._logger.error("The port 'CurrentSimFile' is not available.")
            return sig_gd.RET_VAL_ERROR

        self._logger.info("Reading signal values from '%s'. Please wait..." % current_sim_file)
        try:
            self.__bin_read.open(current_sim_file)
        except bsig_200_exception, ex:
            self._logger.error(str(ex))
            return sig_gd.RET_VAL_ERROR

        if SPEED_TEST is True:
            processing_time_start = time.time()
            self._logger.info("Starting processing ...\n")

        # Load additional signal list. Must contain "MTS.Package.TimeStamp" signal.
        self.__LoadAdditionalSignalList()

        if 'EnableOBJList' in self.__extractor_configuration and self.__extractor_configuration['EnableOBJList']:
            self.__LoadDataObjectList()
        # Load OOI list. Only works if object list is loaded.
        if 'EnableOOIList' in self.__extractor_configuration and self.__extractor_configuration['EnableOOIList']:
            self.__LoadDataOOIList()
        if 'EnableFCTData' in self.__extractor_configuration and self.__extractor_configuration['EnableFCTData']:
            self.__LoadDataFCT()
        if 'EnableVDYData' in self.__extractor_configuration and self.__extractor_configuration['EnableVDYData']:
            self.__LoadDataVDY()
        if 'EnableIBEOList' in self.__extractor_configuration and self.__extractor_configuration['EnableIBEOList']:
            self.__LoadIbeoObjectList()
        if 'EnableSODList' in self.__extractor_configuration and self.__extractor_configuration['EnableSODList']:
            self.__LoadSODSignalList()

        if SPEED_TEST is True:
            processing_time_end = time.time()
            self._logger.info("Total processing time: %f .\n" % (processing_time_end - processing_time_start))

        # Close the binary signal reader.
        self.__bin_read.close()

        ###################################
        # replacing time stamp signal for HIL output
        #
        # the original time stamps can replace the new time stamps if there is
        # a file in bsig format with original time stamps named as configured
        #   - needs original time stamp values and s_EmbeddedRegData.ui64_FrameTimestamp_us
        #     to check synchronisation
        #
        # !! in case of dropped frames in HIL output validation will continue with warnings !!
        #
        ###################################
        if self.__use_hil_tmstmp is True:
            current_tmstmp_file = path.splitext(current_sim_file)[0] + '.' + self.__hil_config[ORI_TIME_FILE_EXT]
            self._logger.info("replacing time stamps with values from %s" % current_tmstmp_file)
            if path.exists(current_tmstmp_file):
                if self.__replace_timestamps(current_tmstmp_file,
                                             self.__hil_config[SYNC_SIGNAL],
                                             self.__hil_config[ORI_TIME_SIGNAL],
                                             self.__hil_config[HIL_TIME_SIGNAL]) is not sig_gd.RET_VAL_OK:
                    return sig_gd.RET_VAL_ERROR
            else:
                self._logger.error("HIL time stamp file %s not found/not readable" % current_tmstmp_file)
                return sig_gd.RET_VAL_ERROR

        if self.__use_sil_tmstmp is True:
            current_sil_tmstmp_file = current_sim_file[:-9] + '_tstp' + '.bsig'
            self._logger.info("replacing time stamps with values from %s" % current_sil_tmstmp_file)
            if path.exists(current_sil_tmstmp_file):
                if self.__replace_sil_timestamps(current_sil_tmstmp_file,
                                                 current_sim_file,
                                                 self.__sil_config[SIL_SYNC_SIGNAL]) is not sig_gd.RET_VAL_OK:

                    return sig_gd.RET_VAL_ERROR

        return sig_gd.RET_VAL_OK

    def ProcessData(self):
        """ ProcessData. not used here. """
        self._logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return sig_gd.RET_VAL_OK

    def PostProcessData(self):
        """ PostProcessData. Called for each file.
        setting ports to 'None', clears internal object lists
        """
        self._logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")

        # Set the data ports and signals to None.
        if 'EnableOBJList' in self.__extractor_configuration and self.__extractor_configuration['EnableOBJList']:
            self._data_manager.SetDataPort(sig_gd.OBJECT_PORT_NAME, None, self._bus_name)
            self.__objects_list = []
        if 'EnableOOIList' in self.__extractor_configuration and self.__extractor_configuration['EnableOOIList']:
            self._data_manager.SetDataPort(sig_gd.OOI_OBJECT_PORT_NAME, None, self._bus_name)
            self.__ooi_obj_list = {}
        if 'EnableFCTData' in self.__extractor_configuration and self.__extractor_configuration['EnableFCTData']:
            self._data_manager.SetDataPort(sig_gd.FCTDATA_PORT_NAME, None, self._bus_name)
        if 'EnableVDYData' in self.__extractor_configuration and self.__extractor_configuration['EnableVDYData']:
            self._data_manager.SetDataPort(sig_gd.VDYDATA_PORT_NAME, None, self._bus_name)
        if 'EnableIBEOList' in self.__extractor_configuration and self.__extractor_configuration['EnableIBEOList']:
            self._data_manager.SetDataPort(sig_gd.IBEO_OBJECT_PORT_NAME, None, self._bus_name)
        if 'EnableSODList' in self.__extractor_configuration and self.__extractor_configuration['EnableSODList']:
            self._data_manager.SetDataPort(sig_gd.SOD_OBJECT_PORT_NAME, None, self._bus_name)

        unreachable_objects = gc.collect()
        if unreachable_objects != 0:
            self._logger.info("Unreachable objects for garbage collector. %d" % unreachable_objects)

        return sig_gd.RET_VAL_OK

    def PreTerminate(self):
        """ PreTerminate. not used here. """
        self._logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return sig_gd.RET_VAL_OK

    def Terminate(self):
        """ Terminate. not used here. """
        self._logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return sig_gd.RET_VAL_OK

    def GetComponentVersion(self):
        """ provide revision number

        :return version with trailing 0 if less then 1:
        """
        self._logger.debug(str(_getframe().f_code.co_name) + "() called.")

        revision = self._version.find("Revision: ")
        if revision > -1:
            version = self._version[revision + 10:-2]
        else:
            version = 0.0

        return version

    def GetComponentName(self):
        """ retur """
        self._logger.debug(str(_getframe().f_code.co_name) + "()" + " called.")
        return self._component_name

    # --- Module functions. Initialize. --------------------------------------------------
    def __InitObjectList(self):
        """
        initialise general signal objects list, create __obj_port_names for each object as:

        [{ 'PortName': <PortName>#, 'Count': #, 'SignalName': <Prefix>+<SignalName>+# } ...]

        using ports
          - OBJ_Prefix,
          - OBJ_Length,
          - OBJ_Count,
          - OBJ_Signals with SignalName and PortName

        """
        # Get the prefix for the OBJ signals.
        obj_name_prefix = self.__GetDataPort(PORT_NAME_OBJ_PREFIX, str, None)
        # Get the number of OBJ objects.
        self.__radar_obj_count = self.__GetDataPort(PORT_NAME_OBJ_COUNT, int, None)
        # Get OBJ port and signal names.
        self.__obj_port_and_signal_names = self.__GetDataPort(PORT_NAME_OBJ_SIGNALS, list, dict, True)
        # Update the signals with prefixes.
        for object_index in xrange(self.__radar_obj_count):
            for obj_port_and_signal_name in self.__obj_port_and_signal_names:
                obj_port_and_signal_name_expanded = {}
                obj_port_and_signal_name_expanded[PORT_NAME] = obj_port_and_signal_name[PORT_NAME] + str(object_index)
                obj_port_and_signal_name_expanded[COUNT] = str(object_index)
                obj_port_and_signal_name_expanded[SIGNAL_NAME] = \
                    (obj_name_prefix +
                     obj_port_and_signal_name[SIGNAL_NAME]).replace("%", '%(iIndex)d' % {'iIndex': object_index})
                self.__obj_port_and_signal_names_expanded.append(obj_port_and_signal_name_expanded)

        # Create a list of port names only.
        self.__obj_port_names = self.GetListFromDictList(self.__obj_port_and_signal_names, PORT_NAME)

    def __InitOOIList(self):
        """
        initialise OOI signal objects list, create __ooi_port_names as

        [{ 'PortName': <PortName>#, 'Count': #, 'SignalName': <Prefix>+<SignalName>+# } ...]

        using ports
          - OOI_Prefix,
          - OOI_number_of_objects,
          - OOI_signals with SignalName and PortName

        """
        # Get the prefix for the OOI signals.
        ooi_name_prefix = self.__GetDataPort(PORT_NAME_OOI_PREFIX, str, None)
        # Get the number of OOI objects.
        self.__ooi_obj_count = self.__GetDataPort(PORT_NAME_OOI_COUNT, int, None)
        # Get OOI port and signal names.
        self.__ooi_port_and_signal_names = self.__GetDataPort(PORT_NAME_OOI_SIGNALS, list, dict, True)
        # Generate the urls for the OOI list.
        for ooi_index in xrange(self.__ooi_obj_count):
            for index, ooi_port_and_signal_name in enumerate(self.__ooi_port_and_signal_names):
                ooi_port_and_signal_name_expanded = {}
                ooi_port_and_signal_name_expanded[PORT_NAME] = ooi_port_and_signal_name[PORT_NAME] + str(ooi_index)
                ooi_port_and_signal_name_expanded[COUNT] = str(ooi_index)
                ooi_port_and_signal_name_expanded[SIGNAL_NAME] = \
                    (ooi_name_prefix +
                     self.__ooi_port_and_signal_names[index][SIGNAL_NAME]).replace("%", '%(iIndex)d'
                                                                                   % {'iIndex': ooi_index})
                self.__ooi_port_and_signal_names_expanded.append(ooi_port_and_signal_name_expanded)

        # Create a list of port names only.
        self.__ooi_port_names = self.GetListFromDictList(self.__ooi_port_and_signal_names, PORT_NAME)

    def __InitFCT(self):
        """ Initialise the FCT data. """
        # Get the prefix for the FCT signals.
        fct_name_prefix = self.__GetDataPort(PORT_NAME_FCT_PREFIX, str, None)
        # Get FCT port and signal names.
        self.__fct_port_and_signal_names = self.__GetDataPort(PORT_NAME_FCT_SIGNALS, list, dict, True)
        # Update the signals with prefixes.
        for fct_port_signal_data in self.__fct_port_and_signal_names:
            fct_port_signal_data[SIGNAL_NAME] = fct_name_prefix + fct_port_signal_data[SIGNAL_NAME]

    def __InitVDY(self):
        """ Initialise the VDY data. """
        # Get the preffix for the VDY signals.
        vdy_name_prefix = self.__GetDataPort(PORT_NAME_VDY_PREFIX, str, None)
        # Get VDY port and signal names.
        self.__vdy_port_and_signal_names = self.__GetDataPort(PORT_NAME_VDY_SIGNALS, list, dict, True)
        # Update the signals with prefixes.
        for vdy_port_signal_data in self.__vdy_port_and_signal_names:
            vdy_port_signal_data[SIGNAL_NAME] = vdy_name_prefix + vdy_port_signal_data[SIGNAL_NAME]

    def __InitIbeoObjectList(self):
        """
        initialise ibeo signal objects list, create __ibeo_obj_port_names for each object as:

        [{ 'PortName': <PortName>#, 'Count': #, 'SignalName': <Prefix>+<SignalName>+# } ...]

        using ports
          - IbeoOut_Prefix,
          - IbeoOut_Length,
          - IbeoOut_Count,
          - IbeoOut_ObjSignals with SignalName and PortName
        """
        # Get the prefix for the OBJ signals.
        obj_name_prefix = self.__GetDataPort(PORT_NAME_IBEO_OBJ_PREFIX, str, None)
        # Get total the number of Ibeo objects.
        self.__ibeo_obj_length = self.__GetDataPort(PORT_NAME_IBEO_OBJ_LENGTH, int, None)
        # Get the actual number of objects
        self.__ibeo_obj_count_signal_name = obj_name_prefix + self.__GetDataPort(PORT_NAME_IBEO_OBJ_COUNT, str, None)
        self.__ibeo_obj_count_port_name = self.__GetDataPort(PORT_NAME_IBEO_OBJ_COUNT, str, None)

        # Get OBJ port and signal names.
        self.__ibeo_obj_port_and_signal_names = self.__GetDataPort(PORT_NAME_IBEO_OBJ_SIGNALS, list, dict, True)
        # Update the signals with prefixes.
        for object_index in xrange(self.__ibeo_obj_length):
            for obj_port_and_signal_name in self.__ibeo_obj_port_and_signal_names:
                obj_port_and_signal_name_expanded = {}
                obj_port_and_signal_name_expanded[PORT_NAME] = obj_port_and_signal_name[PORT_NAME] + str(object_index)
                obj_port_and_signal_name_expanded[COUNT] = str(object_index)
                obj_port_and_signal_name_expanded[SIGNAL_NAME] = \
                    (obj_name_prefix +
                     obj_port_and_signal_name[SIGNAL_NAME]).replace("%", '%(iIndex)d' % {'iIndex': object_index})
                self.__ibeo_obj_port_and_signal_names_expanded.append(obj_port_and_signal_name_expanded)

        # Create a list of port names only.
        self.__ibeo_obj_port_names = self.GetListFromDictList(self.__ibeo_obj_port_and_signal_names, PORT_NAME)

    def __InitSodObjectList(self):
        """
        initialise sod signal objects list, create __sod_obj_port_names for each object as:

        [{ 'PortName': <PortName>#, 'Count': #, 'SignalName': <Prefix>+<SignalName>+# } ...]

        using ports
          - SODOut_Prefix,
          - SODOut_Length,
          - SODOut_Count,
          - SODOut_ObjSignals with SignalName and PortName

        returns nothing
        """
        # Get the prefix for the OBJ signals.
        obj_name_prefix = self.__GetDataPort(PORT_NAME_SOD_OBJ_PREFIX, str, None)
        # Get total the number of SOD objects.
        self.__sod_obj_length = self.__GetDataPort(PORT_NAME_SOD_OBJ_LENGTH, int, None)
        # Get the actual number of objects
        # self.__sod_obj_count_signal_name = obj_name_prefix + self.__GetDataPort(PORT_NAME_SOD_OBJ_COUNT, str, None)
        # self.__sod_obj_count_port_name   = self.__GetDataPort(PORT_NAME_SOD_OBJ_COUNT, str, None)

        # Get OBJ port and signal names.
        self.__sod_obj_port_and_signal_names = self.__GetDataPort(PORT_NAME_SOD_OBJ_SIGNALS, list, dict, True)
        # Update the signals with prefixes.
        for object_index in xrange(self.__sod_obj_length):
            for obj_port_and_signal_name in self.__sod_obj_port_and_signal_names:
                obj_port_and_signal_name_expanded = {}
                obj_port_and_signal_name_expanded[PORT_NAME] = obj_port_and_signal_name[PORT_NAME] + str(object_index)
                obj_port_and_signal_name_expanded[COUNT] = str(object_index)
                obj_port_and_signal_name_expanded[SIGNAL_NAME] = \
                    (obj_name_prefix +
                     obj_port_and_signal_name[SIGNAL_NAME]).replace("%", '%(iIndex)d' % {'iIndex': object_index})
                self.__sod_obj_port_and_signal_names_expanded.append(obj_port_and_signal_name_expanded)

        # Create a list of port names only.
        self.__sod_obj_port_names = self.GetListFromDictList(self.__sod_obj_port_and_signal_names, PORT_NAME)

    def __InitAdditionalSignalList(self):
        """ Initialise the additional signal list:

        get port 'ADDITONAL_signals'
        """
        # Get additional port and signal names.
        self.__addit_port_and_signal_names = self.__GetDataPort(PORT_NAME_ADDIT_SIGNALS, list, dict)

    # --- Module functions. LoadData. --------------------------------------------------
    def __LoadDataObjectList(self):
        """ Load the object list.
        """
        # Get the relevant object data from the additional signals list.
        self.__rel_obj_id = self._data_manager.GetDataPort(PORT_NAME_REL_OBJ_ID, self._bus_name)

        # Set the default relevant index for the first cycles.
        for idx in xrange(min(IGNORE_OOI_FIRST_CYCLES, len(self.__rel_obj_id))):
            self.__rel_obj_id[idx] = INVALID_OBJECT[0]

        # Load the object list.
        self.__objects_list = []
        self.__object_id = 0

        for col_idx in xrange(self.__radar_obj_count):
            self.__LoadDataObject(col_idx)

        # Sort the object list based on the timestamp.
        self.__objects_list.sort(lambda x, y: cmp(long(x["StartTime"]), long(y["StartTime"])))

        self._data_manager.SetDataPort(sig_gd.OBJECT_PORT_NAME, self.__objects_list, self._bus_name)

    def __LoadDataObject(self, col_index):
        """ Load the data for one object.

        :param col_index: The index (0-39 for ARS301)
        """
        Done = False
        last_pos = 0
        signal_data_list = []

        # To generate the object list, port ucLifeTime is required as the first signal.
        if self.__obj_port_names[0] != PORT_NAME_UILIFETIME:
            self._logger.error("Need to place ucLifeTime signal as first signal in the OBJ list in the config file.")
            sexit(sig_gd.RET_VAL_ERROR)

        # Load the lifetime signal.
        obj_signal_urls = self.GetListFromDictList(self.__obj_port_and_signal_names_expanded, SIGNAL_NAME)

        sig_name_uiLifeTime = obj_signal_urls[col_index * len(self.__obj_port_names)]
        try:
            ui_life_time_data = self.__bin_read.get_signal_by_name(sig_name_uiLifeTime)
        except bsig_200_exception, ex:
            self._logger.error(str(ex))
            sexit(sig_gd.RET_VAL_ERROR)

        # Load all the OBJ signals.
        for obj_port_name_idx in xrange(len(self.__obj_port_names)):
            try:
                sig_name = obj_signal_urls[obj_port_name_idx + col_index * len(self.__obj_port_names)]
                obj_signal_data = self.__bin_read.get_signal_by_name(sig_name)
            except bsig_200_exception, ex:
                self._logger.error(str(ex))
                sexit(sig_gd.RET_VAL_ERROR)

            signal_data_list.append(obj_signal_data)

        # Extract objects.
        while not Done:
            object_position = self.__ScanColumn(ui_life_time_data, last_pos)
            if object_position is not None:
                last_pos = object_position[0] + object_position[1]
                self.__ExtractObjectData(col_index, signal_data_list, object_position[0], object_position[1])
            else:
                Done = True

    def __LoadDataOOIList(self):
        """ Load OOI data list. """
        self.__ooi_obj_list = {}

        # Load the OOI list.
        for idx in xrange(self.__ooi_obj_count):
            self.__LoadDataOOI(idx)

        for obj in self.__objects_list:
            obj['OOIHistory'].sort(lambda x, y: cmp(long(x['StartIndexAsOOI']), long(y['StartIndexAsOOI'])))

        self._data_manager.SetDataPort(sig_gd.OOI_OBJECT_PORT_NAME, self.__ooi_obj_list, self._bus_name)

    def __LoadDataOOI(self, ooi_index):  # pylint: disable=R0912,R0915
        """ Load the OOI data.

        :param ooi_index: The OOI index. For ARS301 6 objects (0-5).
        """
        object_name = 'OOIObject[' + str(ooi_index) + ']'
        self.__ooi_obj_list[object_name] = []

        # Read the signal data for an OOI from the binary file.
        ooi_signal_data = []
        first_b = True
        for ooi_port_and_signal_name_expanded in self.__ooi_port_and_signal_names_expanded:
            if ooi_port_and_signal_name_expanded[COUNT] == str(ooi_index):
                try:
                    if first_b:
                        first_b = False
                        sig_data = self.__bin_read.get_signal_by_name(ooi_port_and_signal_name_expanded[SIGNAL_NAME])

                    sig_data2 = self.__bin_read.get_signal_by_name(ooi_port_and_signal_name_expanded[SIGNAL_NAME])
                    ooi_signal_data.append(sig_data2)

                except bsig_200_exception, ex:
                    self._logger.error(str(ex))
                    sexit(sig_gd.RET_VAL_ERROR)

        # Generate OOI object list.
        current_pos = IGNORE_OOI_FIRST_CYCLES
        length = 0
        bNewObject = False
        # Process the object_id data.
        while current_pos < len(sig_data):
            # If the object id is -1 then skip to the next object id.
            if sig_data[current_pos] in INVALID_OBJECT:
                current_pos = current_pos + 1
                length = length + 1
            else:
                # Get the current ooi id.
                current_obj_id = sig_data[current_pos]
                # Set the starting positing and start length of the ooi.
                start_pos = current_pos
                length = 0
                # Move along the data until the ooi id changes.
                while ((current_obj_id == sig_data[current_pos]) and (current_pos < len(sig_data) - 1)):
                    current_pos += 1
                    length += 1
                # The end of the ooi has been reached.
                object_column = None
                if length >= 1:
                    bNewObject = True
                    object_column = {}
                    for ooi_port_name in self.__ooi_port_names:
                        ooi_index = self.__ooi_port_names.index(ooi_port_name)
                        object_column[ooi_port_name] = ooi_signal_data[ooi_index][start_pos:start_pos + length]
                    object_column["start_index"] = start_pos
                    object_column["stop_index"] = start_pos + length
                else:
                    current_pos += 1

                # Complete processing of new ooi.
                if bNewObject is True:
                    bNewObject = False
                    matching_obj = None
                    match_obj_index = 0
                    if object_column is not None:
                        obj_index = 0
                        # Find a matching object in the objects list.
                        for obj in self.__objects_list:
                            if obj['ObjectId'] == object_column['object_id'][0]:
                                if object_column["start_index"] >= obj['Index'] and\
                                   object_column["stop_index"] <= obj['Index'] + len(obj['Timestamp']):
                                    matching_obj = obj
                                    match_obj_index = obj_index
                                    break
                            obj_index += 1

                        # Append the matching object data.
                        if matching_obj is not None:
                            matching_obj['OOIHistory'].append({"OOIObjectIndex": ooi_index,
                                                               "StartIndexAsOOI": start_pos, "Length": length})
                            object_column["obj"] = matching_obj
                            object_column["obj_index"] = match_obj_index
                            self.__ooi_obj_list[object_name].append(object_column)

    def __LoadDataFCT(self):
        """ Load the FCT data. """
        fct_ports_and_data = self.__LoadBinData(self.__fct_port_and_signal_names)
        self._data_manager.SetDataPort(sig_gd.FCTDATA_PORT_NAME, fct_ports_and_data, self._bus_name)

    def __LoadDataVDY(self):
        """ Load the VDY data. """
        vdy_ports_and_data = self.__LoadBinData(self.__vdy_port_and_signal_names)
        self._data_manager.SetDataPort(sig_gd.VDYDATA_PORT_NAME, vdy_ports_and_data, self._bus_name)

    def __LoadIbeoObjectList(self):
        """ Load the object list. """

        self.__ibeo_objects_list = []

        # load the obect counts
        try:
            object_count = self.__bin_read.get_signal_by_name(self.__ibeo_obj_count_signal_name)
        except bsig_200_exception, ex:
            self._logger.error(str(ex))
            sexit(sig_gd.RET_VAL_ERROR)
        self.__ibeo_objects_list.append(object_count)

        for col_idx in xrange(self.__ibeo_obj_length):
            self.__LoadIbeoObject(col_idx)

        self._data_manager.SetDataPort(sig_gd.IBEO_OBJECT_PORT_NAME, self.__ibeo_objects_list, self._bus_name)

    def __LoadIbeoObject(self, col_index):
        """ Load the data for one object.

        :param col_index: The index (0-32 for Ibeo)
        """
        signal_data_list = []

        # To generate the object list, port ObjId is required
        if self.__ibeo_obj_port_names[0] != PORT_NAME_IBEO_OBJ_ID:
            self._logger.error("Need to place the object id signal as first signal "
                               "in the Ibeo OBJ list in the config file.")
            sexit(sig_gd.RET_VAL_ERROR)

        # Load the signals .
        obj_signal_urls = self.GetListFromDictList(self.__ibeo_obj_port_and_signal_names_expanded, SIGNAL_NAME)

        sig_name_obj_id = obj_signal_urls[col_index * len(self.__ibeo_obj_port_names)]
        try:
            # SMe: unused object object_ids???
            # object_ids =
            self.__bin_read.get_signal_by_name(sig_name_obj_id)
        except bsig_200_exception, ex:
            self._logger.error(str(ex))
            sexit(sig_gd.RET_VAL_ERROR)

        # Load all the OBJ signals.
        for obj_port_name_idx in xrange(len(self.__ibeo_obj_port_names)):
            try:
                sig_name = obj_signal_urls[obj_port_name_idx + col_index * len(self.__ibeo_obj_port_names)]
                obj_signal_data = self.__bin_read.get_signal_by_name(sig_name)
            except bsig_200_exception, ex:
                self._logger.error(str(ex))
                sexit(sig_gd.RET_VAL_ERROR)

            signal_data_list.append(obj_signal_data)

        # extract the objects
        objects = {}
        for obj_port_name in self.__ibeo_obj_port_names:
            try:
                objects[obj_port_name] = signal_data_list[self.__ibeo_obj_port_names.index(obj_port_name)]
            except:
                self._logger.error("Error while extracting data for object: %s obj_port_name." % obj_port_name)
                sexit(sig_gd.RET_VAL_ERROR)

        self.__ibeo_objects_list.append(objects)

    def __LoadAdditionalSignalList(self):
        """ Load the additional signals. """
        for addit_port_and_signal_name in self.__addit_port_and_signal_names:
            try:
                signal_data = self.__bin_read.get_signal_by_name(addit_port_and_signal_name[SIGNAL_NAME])
                if signal_data is None:
                    self._logger.debug("There is no data available for %s signal in the binary file." %
                                       addit_port_and_signal_name[SIGNAL_NAME])
            except bsig_200_exception, ex:
                self._logger.error(str(ex))
                signal_data = None
                # sys.sexit(sig_gd.RET_VAL_ERROR)
            self._data_manager.SetDataPort(addit_port_and_signal_name[PORT_NAME], signal_data, self._bus_name)

    def __LoadSODSignalList(self):
        """ Load the additional signals. """
        for addit_port_and_signal_name in self.__sod_obj_port_and_signal_names_expanded:
            try:
                signal_data = self.__bin_read.get_signal_by_name(addit_port_and_signal_name[SIGNAL_NAME])
                if signal_data is None:
                    self._logger.debug("There is no data available for %s signal in the binary file." %
                                       addit_port_and_signal_name[SIGNAL_NAME])
            except bsig_200_exception, ex:
                self._logger.error(str(ex))
                signal_data = None
                # sys.sexit(sig_gd.RET_VAL_ERROR)
            self._data_manager.SetDataPort(addit_port_and_signal_name[PORT_NAME], signal_data, self._bus_name)

    def __LoadBinData(self, port_and_signal_names):
        """ Load binary data from file.

        :param port_and_signal_names: The port and signal name list.
        :return: Ports and data in the form of a dict.
        """
        ports_and_data = {}
        for port_and_signal_name in port_and_signal_names:
            try:
                data = self.__bin_read.get_signal_by_name(port_and_signal_name[SIGNAL_NAME])
            except bsig_200_exception, ex:
                self._logger.error(str(ex))
                sexit(sig_gd.RET_VAL_ERROR)
            ports_and_data[port_and_signal_name[PORT_NAME]] = data
        return ports_and_data

    # --- Helper functions. --------------------------------------------------
    def __ScanColumn(self, ui_life_time_data, start_position):
        """ Scan a column.

        :param ui_life_time_data: The object life time data.
        :param column index: The index.
        :param start_positon: The start position in the cycle array.
        :return: (new start position, length of object)
        """
        current_pos = start_position
        length = 0
        data_len = len(ui_life_time_data) - 1

        while current_pos < data_len:
            if ui_life_time_data[current_pos] == 0:
                current_pos = current_pos + 1
            else:
                new_start_position = current_pos
                while current_pos < data_len and ui_life_time_data[current_pos] != 0 \
                    and ui_life_time_data[current_pos] <= ui_life_time_data[current_pos + 1] \
                        and ui_life_time_data[current_pos + 1] != 1:
                    length = length + 1
                    current_pos = current_pos + 1
                return (new_start_position, length + 1)
        return None

    def __GetDataPort(self, port_name, item_type, subitem_type, check_length=False):
        """ Get the data port.

        :param port_name: The port name (string).
        :param item_type: Eg. int, float, bool, list, tuple
        :param subitem_type: Eg. int, float, bool, list, tuple
        :param check_length: Checks that list element has not 0 length. Default = False.
        """
        data_port = self._data_manager.GetDataPort(port_name, self._bus_name)
        # Check if data port is None.
        if data_port is None:
            self._logger.error("The port with the name '%s' was not found." % port_name)
            sexit(sig_gd.RET_VAL_ERROR)
        # Check data port type.
        if not isinstance(data_port, item_type):
            self._logger.error("Expected " + str(item_type) + " type.")
            sexit(sig_gd.RET_VAL_ERROR)

        # If the port type is a list check each of the element of that list.
        if item_type == list and subitem_type is not None:
            for list_element in data_port:
                # Check type for the element.
                if not isinstance(list_element, subitem_type):
                    self._logger.error("There was an error retrieving data for port %s. Expecting a different type."
                                       % port_name)
                    sexit(sig_gd.RET_VAL_ERROR)
                else:
                    # Check the length of the list element.
                    if check_length is True and len(list_element) == 0:
                        self._logger.error("There was an error retrieving data for port %s. Element list length = 0."
                                           % port_name)
                        sexit(sig_gd.RET_VAL_ERROR)
        else:
            # Check the length of the list element.
            if check_length is True and len(data_port):
                self._logger.error("There was an error retrieving data for port %s." % port_name)
                sexit(sig_gd.RET_VAL_ERROR)

        return data_port

    def __ExtractObjectData(self, object_index, signal_data_list, start_position, length):
        """ Extract object data.

        :param object_index: The object index.
        :param signal_data_list: List of signal data (the signal data is a list of values).
        :param start_position: The start position.
        :param length: The length in cycles of the object.
        """
        b_is_relevant = False
        self.__object_id += 1

        # Get the timestamp data.
        timestamp = self._data_manager.GetDataPort("Timestamp", self._bus_name)
        if len(timestamp) == 0:
            self._logger.error("Timestamp information is not available for bus name %s." % self._bus_name)
            sexit(sig_gd.RET_VAL_ERROR)

        # Calculate the end position.
        end_position = min(len(timestamp) - 1, start_position + length)

        new_obj = {}
        new_obj["GlobalObjectId"] = self.__object_id
        new_obj["ObjectId"] = object_index
        new_obj["StartTime"] = timestamp[start_position]
        new_obj["Timestamp"] = timestamp[start_position:end_position]
        new_obj["Index"] = start_position
        new_obj["OOIHistory"] = []
        new_obj["Relevant"] = []
        new_obj["fDistXAbs"] = []
        new_obj["fDistYAbs"] = []

        for obj_port_name in self.__obj_port_names:
            obj_index = self.__obj_port_names.index(obj_port_name)
            try:
                new_obj[obj_port_name] = signal_data_list[obj_index][start_position:start_position + length]
            except:
                self._logger.error("Error while extracting data for object: %s obj_port_name." % obj_port_name)
                sexit(sig_gd.RET_VAL_ERROR)

        for pos in xrange(start_position, start_position + length):
            if self.__rel_obj_id[pos] == object_index:
                new_obj["Relevant"].append(1)
                b_is_relevant = True
            else:
                new_obj["Relevant"].append(0)

        # object was not already classified as being relevant at some point
        # find out if object is selected as OOI 1 to 5 at some point
        if (b_is_relevant is False) and (new_obj.get("ObjOOI") is not None):
            for ooi_idx in new_obj["ObjOOI"]:
                if (ooi_idx > -1):
                    b_is_relevant = True
                    break

        if b_is_relevant or length > self.__obj_min_lifetime:
            self.__objects_list.append(new_obj)
        else:
            pass

    def __replace_sil_timestamps(self, current_sil_file, current_file , sync_signal_name):

        sil_ts = []
        reader = BsigReader()

        reader.open(current_file)
        sync_ts = reader.get_signal_by_name(sync_signal_name)
        reader.close()

        reader.open(current_sil_file)
        abs_ts = reader.get_signal_by_name(SIL_ABSOLUTE_TS)
        img_ts = reader.get_signal_by_name(SIL_IMAGE_TS)
        reader.close()

        for i in xrange(len(sync_ts)):
            found = False

            for k in xrange(50):
                candidates = []

                if i - k >= 0 and i - k < len(img_ts):
                    candidates.append(i - k)

                if i + k >= 0 and i + k < len(img_ts):
                    candidates.append(i + k)

                for j in candidates:
                    if (img_ts[j] & 0xFFFFFFFF) == (sync_ts[i] & 0xFFFFFFFF):
                        sil_ts.append(abs_ts[j])
                        found = True
                        break
                if found:
                    break

            if not found:
                sil_ts.append(None)

        self._data_manager.SetDataPort(SIL_SYNC_TS, sil_ts, self._bus_name)



    def __replace_timestamps(self, file_name, sync_signal_name, signal_name, new_signal_name=None):
        '''
        - replace given signal name on data port directly with same signal values from given file
        - used here to adapt the time stamp from HIL simulation  to the original one used in label db
        - overwrites the data port 'signal_name' directly with new list

        the embedded frame time stamp should used as sync signal name to synchronise the different files,
        error is raised if a difference in embedded time stamps is found or if number of both doesn't match

        :param file_name: name of !! bsig  !! file where original time stamp is stored
        :param sync_signal_name: name of signal available in both (ori and new) files to synchronise the signals
        :param signal_name: time stamp signal name as used in the HIL run
        :param new_signal_name: new name for time stamp signal to allow HIL output with different names then SIL,
        default is same as signal_name
        :returns: success or error
        '''
        # sync_signal_name hard coded, needed to be configured in a port for general usage
        # sync_signal_name = 'MFC3xx Device.ImagerControl.IC_Common.s_EmbeddedRegData.ui64_FrameTimestamp_us'
        reader = BsigReader()
        reader.open(file_name)
        ori_timestamp = reader.get_signal_by_name(signal_name)
        ori_embedded = reader.get_signal_by_name(sync_signal_name)
        reader.close()
        # hil_timestamp = []  # data port list will be overwritten, no need to get it here
        hil_embedded = self._data_manager.GetDataPort(sync_signal_name, self._bus_name)
        # cut out leading and ending time stamps from original list as HIL recording starts later and ends early
        try:
            timestart = ori_embedded.index(hil_embedded[0])
            timeend = ori_embedded.index(hil_embedded[-1])
        except ValueError:
            self._logger.error("time stamp conversion failed because "
                               "measured embedded time stamps not in original recording")
            return sig_gd.RET_VAL_ERROR
        self._logger.info("list contains frames from time stamp %d to %d"
                          % (ori_timestamp[timestart], ori_timestamp[timeend]))
        self._logger.info("first %4.2f sec and last %4.2f sec missing after conversion"
                          % ((ori_timestamp[timestart] - ori_timestamp[0]) / 1000000.0,
                             (ori_timestamp[-1] - ori_timestamp[timeend]) / 1000000.0))
        ori_timestamp = ori_timestamp[timestart:timeend + 1]
        ori_embedded = ori_embedded[timestart:timeend + 1]
        if len(ori_embedded) != len(hil_embedded):
            self._logger.warning("time stamp conversion could cause errors"
                                 " because of different number of time stamps")
        (dups, adds, drops) = self.__compare_lists(ori_embedded, hil_embedded)
        if len(dups) > 0 or len(adds) > 0 or len(drops) > 0:
            self._logger.warning("time stamp conversion found following errors comparing to %s \n"
                                 "duplicated frames: %s, \nadded frames: %s, \ndropped frames: %s" %
                                 (file_name, dups, adds, drops))
        # hidx = 0
        # workaround as embedded TimeStamps are not synchronised, some frames in HIL output are dropped, others doubled
        # full copy should be replaced with commended code if HIL output is triggered correctly
        hil_timestamp = ori_timestamp[:]
#         for idx in xrange(len(ori_embedded)):
#             if ori_embedded[idx] == hil_embedded[hidx]:
#                 hil_timestamp.append(ori_timestamp[idx])
#                 hidx += 1
#             else:
#                 self._logger.warning("time stamp conversion incomplete, "
#                                      "orig. stamp %d in HIL output missing (HIL: %d)"
#                                      % (ori_embedded[idx], hil_embedded[hidx]))
#                 print 'original |HIL-output - embedded timestamps:'
#                 for i,ot in enumerate(ori_embedded[idx-2: idx+5]):
#                      print ot, hil_embedded[hidx+i-2]
#                 continue
        if new_signal_name is not None:
            signal_name = new_signal_name
        self._data_manager.SetDataPort(signal_name, hil_timestamp, self._bus_name)

        return sig_gd.RET_VAL_OK

    def __compare_lists(self, ori, new):
        '''
        two list of values (e.g. time stamps) are compared, this method finds

         - dups: duplicate entries in new list
         - adds: entries only in new list
         - drops: entries not in same order as in ori or missing in new list compared to ori

        the list in ori does not have to been sorted

        used to compare embedded time stamps of original and HIL output simulation files

        :param ori: list of original values to compare to
        :pamam new: list of values to compare to ori
        :returns: touple with lists of duplicated, added and dropped values

        example:

        ::

                           |drop      |drop   |drop
        ori = [  2, 4, 6,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30 ]
        new = [  2, 4, 6, 10, 12, 16, 14, 18, 20, 18, 22, 24, 25, 26, 28 ]
                                                  ^dup        ^add

        results in

        ::

        dups = [ 18 ]
        adds = [ 25 ]
        drops = [ 10, 14, 18 ]
        '''
        # get duplicates in new
        seen = set()
        seen_add = seen.add
        # adds all elements it doesn't know yet to seen and all other to dups
        dups = set(x for x in new if x in seen or seen_add(x))
        # all elements in new but not in ori:
        adds = set(new).difference(ori)
        igns = set().union(dups, adds)

        drops = []
        oidx = 0
        for nidx in xrange(len(new)):
            if new[nidx] in igns:
                # duplicated or additional frame in new, skip immediately
                continue

            while ori[oidx] != new[nidx]:
                if new[nidx] in drops:
                    # already found, stay on current ori element but step to next new
                    oidx -= 1
                    break
                # dropped frame, mark and check next
                drops.append(ori[oidx])
                oidx += 1
                if oidx >= len(ori):
                    oidx = len(ori) - 1
                    break
            oidx += 1

        return (dups, adds, drops)

    def GetListFromDictList(self, dict_list, tag):
        """ Get an individual list of an item from a list of dicts.

        :param dict_list: The dictionary.
        :param tag: The tag in the dictionary to extract as a list.
        :return: List of the tag given.
        :todo: There may be a better way to do this.
        """
        extracted_list = []
        for new_dict in dict_list:
            extracted_list.append(new_dict[tag])
        return extracted_list

"""
CHANGE LOG:
-----------
 $Log: signal_extractor.py  $
 Revision 1.1 2021/12/13 17:59:54CET Wang, David (Wangd3) 
 Initial revision
 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
 Revision 1.17 2013/12/02 10:05:14CET Burdea, Florin (uidv7080) 
 current_sil_tmstmp_file bugfix.
 - Added comments -  uidv7080 [Dec 2, 2013 10:05:14 AM CET]
 Change Package : 199573:3 http://mks-psad:7002/im/viewissue?selection=199573
 Revision 1.16 2013/11/22 10:29:14CET Burdea, Florin (uidv7080) 
 Change of constant HIL_TMSTAMP_FILE_EXT from .'tstp' to 'tstp'.
 --- Added comments ---  uidv7080 [Nov 22, 2013 10:29:15 AM CET]
 Change Package : 199573:3 http://mks-psad:7002/im/viewissue?selection=199573
 Revision 1.15 2013/11/22 08:01:02CET Burdea, Florin (uidv7080) 
 Sil sync and Hil bug fix for .tstp
 --- Added comments ---  uidv7080 [Nov 22, 2013 8:01:03 AM CET]
 Change Package : 199573:3 http://mks-psad:7002/im/viewissue?selection=199573
 Revision 1.13.1.1 2013/11/21 17:22:50CET Burdea, Florin (uidv7080) 
 Sil-Sil synchronization added for the jointSimulation;
 
 Bug-fix for Hil-Sil '.tstp', the dot of the bsig extension was missing.
 --- Added comments ---  uidv7080 [Nov 21, 2013 5:22:51 PM CET]
 Change Package : 199573:3 http://mks-psad:7002/im/viewissue?selection=199573
 Revision 1.13 2013/09/10 16:10:38CEST Hospes, Gerd-Joachim (uidv8815) 
 fix error in HIL settings, fix pep8/pylint errors, update docu
 --- Added comments ---  uidv8815 [Sep 10, 2013 4:10:38 PM CEST]
 Change Package : 190320:1 http://mks-psad:7002/im/viewissue?selection=190320
 Revision 1.12 2013/09/09 17:44:47CEST Hospes, Gerd-Joachim (uidv8815)
 fix indentation
 --- Added comments ---  uidv8815 [Sep 9, 2013 5:44:47 PM CEST]
 Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
 Revision 1.11 2013/09/09 17:33:10CEST Hospes, Gerd-Joachim (uidv8815)
 fix error in time stamp parameter checking
 --- Added comments ---  uidv8815 [Sep 9, 2013 5:33:10 PM CEST]
 Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
 Revision 1.10 2013/09/09 17:13:48CEST Hospes, Gerd-Joachim (uidv8815)
 use util/logger again
 --- Added comments ---  uidv8815 [Sep 9, 2013 5:13:49 PM CEST]
 Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
 Revision 1.9 2013/09/06 10:30:04CEST Mertens, Sven (uidv7805)
 finalizing unittest problems by using new logger functionality
 --- Added comments ---  uidv7805 [Sep 6, 2013 10:30:04 AM CEST]
 Change Package : 196367:2 http://mks-psad:7002/im/viewissue?selection=196367
 Revision 1.8 2013/09/06 09:48:57CEST Mertens, Sven (uidv7805)
 correcting mistake done when rename needed
 --- Added comments ---  uidv7805 [Sep 6, 2013 9:48:57 AM CEST]
 Change Package : 196367:2 http://mks-psad:7002/im/viewissue?selection=196367
 Revision 1.7 2013/09/06 09:28:56CEST Mertens, Sven (uidv7805)
 changing log handler
 --- Added comments ---  uidv7805 [Sep 6, 2013 9:28:56 AM CEST]
 Change Package : 196367:2 http://mks-psad:7002/im/viewissue?selection=196367
 Revision 1.6 2013/08/15 17:24:54CEST Hospes, Gerd-Joachim (uidv8815)
 HIL timestamp conversion added
 --- Added comments ---  uidv8815 [Aug 15, 2013 5:24:54 PM CEST]
 Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
 Revision 1.5 2013/07/30 10:07:03CEST Raedler, Guenther (uidt9430)
 - fixed object extraction error for objects with  lifetime 1
 --- Added comments ---  uidt9430 [Jul 30, 2013 10:07:03 AM CEST]
 Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
 Revision 1.4 2013/06/13 11:24:36CEST Mertens, Sven (uidv7805)
 btw: disabling some pylint errors
 --- Added comments ---  uidv7805 [Jun 13, 2013 11:24:37 AM CEST]
 Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
 Revision 1.3 2013/06/13 11:13:56CEST Mertens, Sven (uidv7805)
 when deleting an variable it cannot be accessed a second time!
 Revision 1.2 2013/05/22 10:37:05CEST Mertens, Sven (uidv7805)
 alignment of imports, pylint error reduction
 --- Added comments ---  uidv7805 [May 22, 2013 10:37:05 AM CEST]
 Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
 Revision 1.1 2013/05/15 18:13:18CEST Hospes, Gerd-Joachim (uidv8815)
 Initial revision
 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
     stk/valf/project.pj
 Revision 2.0 2013/02/20 08:25:23CET Raedler, Guenther (uidt9430)
 - support STK2.0 with packages
 --- Added comments ---  uidt9430 [Feb 20, 2013 8:25:23 AM CET]
 Change Package : 163448:3 http://mks-psad:7002/im/viewissue?selection=163448
 Revision 1.12 2012/07/24 10:13:57CEST Hanel, Nele (haneln)
 ensure, that alle objects, that were selected on any of the 6 OOI-positions once, are extracted from the bin-file
 --- Added comments ---  haneln [Jul 24, 2012 10:14:02 AM CEST]
 Change Package : 103188:10 http://mks-psad:7002/im/viewissue?selection=103188
 Revision 1.11 2012/06/29 10:56:30CEST Spruck, Jochen (spruckj)
 Add IBEO objects reading
 --- Added comments ---  spruckj [Jun 29, 2012 10:56:30 AM CEST]
 Change Package : 98074:5 http://mks-psad:7002/im/viewissue?selection=98074
 Revision 1.10 2012/03/19 15:20:20CET Hielscher, Patrick (uidt6110)
 Removed "-1" cycle which was in the OOI object list every time the object changes
 --- Added comments ---  uidt6110 [Mar 19, 2012 3:20:21 PM CET]
 Change Package : 94393:2 http://mks-psad:7002/im/viewissue?selection=94393
 Revision 1.9 2012/02/08 12:41:12CET Raedler-EXT, Guenther (uidt9430)
 - allow signals not being in the binary file
 --- Added comments ---  uidt9430 [Feb 8, 2012 12:41:13 PM CET]
 Change Package : 93032:2 http://mks-psad:7002/im/viewissue?selection=93032
 Revision 1.8 2011/10/25 09:44:41CEST Castell Christoph (uidt6394) (uidt6394)
 Fixed object_list bug found by Nele.
 --- Added comments ---  uidt6394 [Oct 25, 2011 9:44:41 AM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.7 2011/10/24 19:59:17CEST Castell Christoph (uidt6394) (uidt6394)
 Fixed error with the generation of the OOI list.
 --- Added comments ---  uidt6394 [Oct 24, 2011 7:59:18 PM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.6 2011/10/24 15:38:50CEST Castell Christoph (uidt6394) (uidt6394)
 Changed garbage collector error to info.
 --- Added comments ---  uidt6394 [Oct 24, 2011 3:38:50 PM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.5 2011/10/18 15:54:17CEST Castell Christoph (uidt6394) (uidt6394)
 First new version. Testing and some efficiency updates required.
 --- Added comments ---  uidt6394 [Oct 18, 2011 3:54:17 PM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.4 2011/10/18 08:36:41CEST Castell Christoph (uidt6394) (uidt6394)
 New intermediate version.
 --- Added comments ---  uidt6394 [Oct 18, 2011 8:36:41 AM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.3 2011/08/22 14:48:08CEST Castell Christoph (uidt6394) (uidt6394)
 Updated version.
 --- Added comments ---  uidt6394 [Aug 22, 2011 2:48:08 PM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.2 2011/08/03 14:00:06CEST Castell Christoph (uidt6394) (uidt6394)
 Changed name to ValidationDataExtractor.
 --- Added comments ---  uidt6394 [Aug 3, 2011 2:00:06 PM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.1 2011/08/03 13:56:20CEST Castell Christoph (uidt6394) (uidt6394)
 Initial revision
 Member added to project /nfs/projekte1/PROJECTS/ARS301/06_Algorithm/05_Testing/05_Test_Environment/algo/
                          ars301_req_test/valf_tests/vpc/project.pj
 Revision 1.14 2011/07/21 16:02:45CEST Castell Christoph (uidt6394) (uidt6394)
 Removed unused code.
 --- Added comments ---  uidt6394 [Jul 21, 2011 4:02:46 PM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.13 2011/07/21 11:33:25CEST Castell Christoph (uidt6394) (uidt6394)
 Formatting updates to remove warings.
 Revision 1.12 2011/07/21 11:20:53CEST Castell Christoph (uidt6394) (uidt6394)
 Merge of 1.9.1.5 back into mainline.
 Revision 1.9.1.5 2011/07/21 08:27:05CEST Castell Christoph (uidt6394) (uidt6394)
 Added PreTerminate() function.
 --- Added comments ---  uidt6394 [Jul 21, 2011 8:27:06 AM CEST]
 Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
 Revision 1.9.1.4 2011/01/25 12:28:18CET Ovidiu Raicu (RaicuO)
 Modified data extractor to work with bin file sections. Revision 1.7 or higher of stk_bsig.py must be used.
 --- Added comments ---  RaicuO [Jan 25, 2011 12:28:19 PM CET]
 Change Package : 37852:2 http://mks-psad:7002/im/viewissue?selection=37852
 Revision 1.9.1.3 2010/12/14 10:11:08CET Gicu Benchea (bencheag)
 Add all the relevant objects to the object list
 Increase the minimum cycle time for the processed obejcts to 45 (about 3 seconds)
 --- Added comments ---  bencheag [Dec 14, 2010 10:11:08 AM CET]
 Change Package : 50877:1 http://mks-psad:7002/im/viewissue?selection=50877
 Revision 1.9.1.2 2010/11/17 13:00:49CET Gicu Benchea (bencheag)
 Fix the relevant flag issue at the beginig of the file
 --- Added comments ---  bencheag [Nov 17, 2010 1:00:50 PM CET]
 Change Package : 50877:1 http://mks-psad:7002/im/viewissue?selection=50877
 Revision 1.9.1.1 2010/11/16 09:41:34CET Gicu Benchea (bencheag)
 Update the default object ID with -1
 --- Added comments ---  bencheag [Nov 16, 2010 9:41:34 AM CET]
 Change Package : 50877:1 http://mks-psad:7002/im/viewissue?selection=50877
 Revision 1.9 2010/10/04 06:54:35CEST Sorin Mogos (mogoss)
 * removed component_name from RegisterDataPort
 --- Added comments ---  mogoss [Oct 4, 2010 6:54:35 AM CEST]
 Change Package : 51595:1 http://mks-psad:7002/im/viewissue?selection=51595
 Revision 1.8 2010/10/03 11:39:54CEST Sorin Mogos (mogoss)
 * removed component name from SetDataPort
 --- Added comments ---  mogoss [Oct 3, 2010 11:39:54 AM CEST]
 Change Package : 51595:1 http://mks-psad:7002/im/viewissue?selection=51595
 Revision 1.7 2010/08/25 13:11:43CEST Sorin Mogos (mogoss)
 * updated for ars301 configuration
 --- Added comments ---  mogoss [Aug 25, 2010 1:11:43 PM CEST]
 Change Package : 39236:1 http://mks-psad:7002/im/viewissue?selection=39236
 Revision 1.6 2010/07/28 09:12:35CEST Gicu Benchea (bencheag)
 Use commun structure for Device and simulator object structure
 --- Added comments ---  bencheag [Jul 28, 2010 9:12:36 AM CEST]
 Change Package : 41177:1 http://mks-psad:7002/im/viewissue?selection=41177
 Revision 1.5 2010/07/26 14:32:15CEST Gicu Benchea (bencheag)
 Ignore the first cycles from the OOI list which are by default 0
 Object extractor - avoid to split the object when the counter is repeated
 --- Added comments ---  bencheag [Jul 26, 2010 2:32:16 PM CEST]
 Change Package : 41177:1 http://mks-psad:7002/im/viewissue?selection=41177
 Revision 1.4 2010/07/23 16:02:37CEST Gicu Benchea (bencheag)
 Bug fix in the OOI Relevant object extractor - 0 ID is a valid one
 --- Added comments ---  bencheag [Jul 23, 2010 4:02:37 PM CEST]
 Change Package : 41177:1 http://mks-psad:7002/im/viewissue?selection=41177
 Revision 1.3 2010/06/28 13:35:32CEST smogos
 * code clean-up
 * configuration changes
 --- Added comments ---  smogos [2010/06/28 11:35:32Z]
 Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
 Revision 1.2 2010/06/21 16:24:44EEST Sorin Mogos (smogos)
 * changed according to new configuration format
 --- Added comments ---  smogos [2010/06/21 13:24:45Z]
 Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
 Revision 1.17 2010/04/30 12:22:16EEST Gicu Benchea (gbenchea)
 Change the minimum object length from 2 to 10 cycles
 --- Added comments ---  gbenchea [2010/04/30 09:22:17Z]
 Change Package : 41177:1 http://LISS014:6001/im/viewissue?selection=41177
 Revision 1.16 2010/04/29 14:56:09EEST Gicu Benchea (gbenchea)
 Run time optimisation - remove the SafeListAccess function
 --- Added comments ---  gbenchea [2010/04/29 11:56:10Z]
 Change Package : 41177:1 http://LISS014:6001/im/viewissue?selection=41177
 Revision 1.15 2010/04/23 15:21:54EEST Gicu Benchea (gbenchea)
 Added by default the absoulte distance to the path
 --- Added comments ---  gbenchea [2010/04/23 12:21:54Z]
 Change Package : 41177:1 http://LISS014:6001/im/viewissue?selection=41177
 Revision 1.14 2010/04/19 15:52:29EEST Gicu Benchea (gbenchea)
 Bug fix related to the object index
 --- Added comments ---  gbenchea [2010/04/19 12:52:29Z]
 Change Package : 41177:1 http://LISS014:6001/im/viewissue?selection=41177
 Revision 1.13 2010/04/19 13:49:24EEST Gicu Benchea (gbenchea)
 Added start and stop index to the OOI object structure
 Added a reference pointer to the object dictionary
 Bug fix - Set data of the OOI object list
 --- Added comments ---  gbenchea [2010/04/19 10:49:24Z]
 Change Package : 41177:1 http://LISS014:6001/im/viewissue?selection=41177
 Revision 1.12 2010/03/19 11:51:49EET Sorin Mogos (smogos)
 * code customisation and bug-fixes
 --- Added comments ---  smogos [2010/03/19 09:51:49Z]
 Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
 Revision 1.11 2010/03/05 13:45:22EET Gicu Benchea (gbenchea)
 Add bus parameter to the constructor
 Remove not needed attributes from object and event structures
 Add the logger
 --- Added comments ---  gbenchea [2010/03/05 11:45:22Z]
 Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
 Revision 1.10 2010/03/04 09:08:01EET Gicu Benchea (gbenchea)
 Add the bus conection
 --- Added comments ---  gbenchea [2010/03/04 07:08:02Z]
 Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
 Revision 1.9 2010/02/19 11:28:51EET Ovidiu Raicu (oraicu)
 Added logger support and posibility to use ABAObject.
 --- Added comments ---  oraicu [2010/02/19 09:28:51Z]
 Change Package : 37852:1 http://LISS014:6001/im/viewissue?selection=37852
 Revision 1.8 2010/01/27 12:34:31CET Ovidiu Raicu (oraicu)
 Modified data_extractor to work with binary files.
 --- Added comments ---  oraicu [2010/01/27 11:34:31Z]
 Change Package : 34637:1 http://LISS014:6001/im/viewissue?selection=34637
 Revision 1.7 2010/01/13 14:13:52CET Gicu Benchea (gbenchea)
 Changes to work with Simulated object lists
 --- Added comments ---  gbenchea [2010/01/13 13:13:52Z]
 Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
 Revision 1.6 2009/11/23 14:07:30EET Gicu Benchea (gbenchea)
 Method how to associtate the relevant flag to the objects has been changed
 --- Added comments ---  gbenchea [2009/11/23 12:07:31Z]
 Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
 Revision 1.5 2009/11/23 10:31:58EET Gicu Benchea (gbenchea)
 Bug fix - Index overflow
 --- Added comments ---  gbenchea [2009/11/23 08:31:59Z]
 Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
 Revision 1.4 2009/11/18 08:40:53EET Gicu Benchea (gbenchea)
 Add the object list from the MTS Device
 --- Added comments ---  gbenchea [2009/11/18 06:40:53Z]
 Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
 Revision 1.3 2009/11/16 17:33:21EET Gicu Benchea (gbenchea)
 * Adaption for processing the Device objects
 * Improve drop ins detection
 * Add events plot functionality
 --- Added comments ---  gbenchea [2009/11/16 15:33:21Z]
 Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
 Revision 1.2 2009/11/09 11:22:14EET Sorin Mogos (smogos)
 * added acc statistic collector drop-in detection rule
 --- Added comments ---  smogos [2009/11/09 09:22:14Z]
 Change Package : 32501:1 http://LISS014:6001/im/viewissue?selection=32501
 Revision 1.1 2009/10/30 16:24:55EET dkubera
 Initial revision
 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ACC_AdaptiveCruiseControl/
 05_Testing/05_Test_Environment/acc/30_BBT_BlackBoxTest/20_RequirementTest/ACC_Performance/01_Source_Code/project.pj
"""
