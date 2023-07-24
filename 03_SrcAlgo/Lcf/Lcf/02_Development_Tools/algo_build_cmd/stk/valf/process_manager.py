# -*- coding:utf-8 -*-
"""
stk/valf/process_manager
------------------------

The internal core manager for Validation Framework used by Valf class.

**User-API Interfaces**

    - `stk.valf` (complete package)
    - `Valf`     (where this internal manager is used)


:org:           Continental AG
:author:        Sorin Mogos

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:53CET $
"""

# pylint: disable=R0902,W0702,C0103

# Import Python Modules -----------------------------------------------------------------------------------------------
from os import path as opath
from sys import path as spath, _getframe, exit as sexit
from inspect import currentframe
from ConfigParser import RawConfigParser
from pylint.checkers.base import CLASS_NAME_RGX

# Import STK Modules --------------------------------------------------------------------------------------------------
VALF_DIR = opath.dirname(opath.abspath(currentframe().f_code.co_filename))
if VALF_DIR not in spath:
    spath.append(VALF_DIR)

PYLIB_DIR = opath.abspath(opath.join(VALF_DIR, "..", "stk"))
if PYLIB_DIR not in spath:
    spath.append(PYLIB_DIR)

from stk.util.logger import Logger
from .error import ValfError
from stk.util.find import findClass
from stk.valf import base_component_ifc as base_interface, data_manager, progressbar

# Defines -------------------------------------------------------------------------------------------------------------
PORT_NAME_INDEX = 0
PORT_CLASS_INSTANCE_INDEX = 1
PORT_VALUE_INDEX = 2
RET_VAL_OK = 0
RET_VAL_ERROR = -1

# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class ProcessManager(object):
    """
    valf internal class to provide essential processing for observers

      - initialize

        - start logger
        - initialize data_manager
        - search classes based on class BaseComponentInterface

      - load configuration

        - import declared observer modules
        - set data ports

      - run validation

        - call all methods of all observers sequentially
        - use bpl_reader or similar to run through all recordings

    """
    def __init__(self, plugin_dir):
        """ init essencials
        """
        self.__logger = Logger(self.__class__.__name__)
        self.__logger.debug()

        self.__component_list = []

        self.__version = "$Revision: 1.1 $"

        self.__progressbar = None

        self.__file_count = 0

        self.__data_manager = None
        self.__object_map_list = []

        self.__config_file_loaded = False

        self.__plugin_dir_list = plugin_dir
        if VALF_DIR not in self.__plugin_dir_list:
            self.__plugin_dir_list.append(VALF_DIR)

        self.__plugin_map = {}
        self.__logger.info("Searching for plug-ins. Please wait...")
        plugin_class_map_list, self.__plugin_error_list = findClass(base_interface.BaseComponentInterface,
                                                                    self.__plugin_dir_list, with_error_list=True)
        if plugin_class_map_list is None:
            self.__logger.error("No plug-ins found.")
            return None

        self.__logger.info("%d plug-ins found." % len(plugin_class_map_list))
        for plugin_class_map in plugin_class_map_list:
            self.__plugin_map[plugin_class_map['name']] = plugin_class_map["type"]

        # Create data manager object
        try:
            self.__data_manager = data_manager.DataManager()
        except:
            self.__logger.error("Couldn't instantiate 'DataManager' class.")
            sexit(RET_VAL_ERROR)

    def __initialize(self):
        """calls Initialize and PostInitialize of ordered observers
        """
        self.__logger.debug()

        for component in self.__component_list:
            if not hasattr(component, 'Initialize'):
                self.__logger.error("Class '%s' doesn't contain the Initialize() method." %
                                    component.__class__.__name__)
                return RET_VAL_ERROR
            if not component.Initialize() is RET_VAL_OK:
                self.__logger.error("Class '%s' returned with error from Initialize() method." %
                                    component.__class__.__name__)
                return RET_VAL_ERROR

        # Calls PostInitialize for each component in the list
        for component in self.__component_list:
            if not hasattr(component, 'PostInitialize'):
                self.__logger.error("Class '%s' doesn't contain the PostInitialize() method." %
                                    component.__class__.__name__)
                return RET_VAL_ERROR
            if not component.PostInitialize() is RET_VAL_OK:
                self.__logger.error("Class '%s' returned with error from PostInitialize() method." %
                                    component.__class__.__name__)
                return RET_VAL_ERROR

        self.__file_count = self.__data_manager.GetDataPort("FileCount")
        if self.__file_count > 0:
            self.__progressbar = progressbar.ProgressBar(0, self.__file_count, multiline=True)
        else:
            self.__file_count = 0

        return RET_VAL_OK

    def __process_data(self):
        """calls LoadData and ProcessData as well as PostProcessData of ordered observers
        """
        self.__logger.debug()

        if self.__file_count == 0:
            self.__logger.debug(str(_getframe().f_code.co_name) + "No files to process.")
            return RET_VAL_OK

        pd_ret_val = RET_VAL_ERROR
        counter = 0

        while (not self.__data_manager.GetDataPort("IsFinished")):

            # update progressbar position
            self.__progressbar(counter)

            counter += 1

            for component in self.__component_list:
                if not hasattr(component, 'LoadData'):
                    self.__logger.error("Class '%s' doesn't contain the LoadData() method." %
                                        component.__class__.__name__)
                    return RET_VAL_ERROR
                ret_val = component.LoadData()
                if ret_val is RET_VAL_ERROR:
                    self.__logger.error("Class '%s' returned with error from LoadData() method, "
                                        "continue with next recording." %
                                        component.__class__.__name__)
                    break

            if ret_val is RET_VAL_ERROR:
                continue

            for component in self.__component_list:
                if not hasattr(component, 'ProcessData'):
                    self.__logger.error("Class '%s' doesn't contain the ProcessData() method." %
                                        component.__class__.__name__)
                    return RET_VAL_ERROR
                ret_val = component.ProcessData()
                if ret_val is RET_VAL_ERROR:
                    self.__logger.error("Class '%s' returned with error from ProcessData() method, "
                                        "continue with next recording." %
                                        component.__class__.__name__)
                    break

            if ret_val is RET_VAL_ERROR:
                continue

            for component in self.__component_list:
                if not hasattr(component, 'PostProcessData'):
                    self.__logger.error("Class '%s' doesn't contain the PostProcessData() method." %
                                        component.__class__.__name__)
                    return RET_VAL_ERROR
                ret_val = component.PostProcessData()
                if ret_val is RET_VAL_ERROR:
                    self.__logger.error("Class '%s' returned with error from PostProcessData() method, "
                                        "continue with next recording." %
                                        component.__class__.__name__)
                    break

            if ret_val is RET_VAL_ERROR:
                continue

            # we have processed correctly at least a file,
            # set _process_data return value to OK in order to finish it's process
            pd_ret_val = RET_VAL_OK

        if counter > 0:
            self.__progressbar(counter)

        return pd_ret_val

    def __terminate(self):
        """calls PreTerminate and Terminate of ordered observers
        """
        self.__logger.debug()

        for component in self.__component_list:
            if not hasattr(component, 'PreTerminate'):
                self.__logger.error("Class '%s' doesn't contain the PreTerminate() method." %
                                    component.__class__.__name__)
                return RET_VAL_ERROR
            if not component.PreTerminate() == 0:
                self.__logger.error("Class '%s' returned with error from PreTerminate() method." %
                                    component.__class__.__name__)
                return RET_VAL_ERROR

        for component in self.__component_list:
            if not hasattr(component, 'Terminate'):
                self.__logger.error("Class '%s' doesn't contain the Terminate() method." %
                                    component.__class__.__name__)
                return RET_VAL_ERROR
            if not component.Terminate() == 0:
                self.__logger.error("Class '%s' returned with error from Terminate() method." %
                                    component.__class__.__name__)
                return RET_VAL_ERROR

        return RET_VAL_OK

    def get_data_port(self, port_name, bus_name="Global"):
        """gets data from a bus/port
        :param port_name: port name to use
        :param bus_name: bus name to use
        :return: data from bus/port
        """
        if not self.__data_manager:
            self.__logger.error("Couldn't create instance of class 'DataManager'")
            return None

        return self.__data_manager.GetDataPort(port_name, bus_name)

    def set_data_port(self, port_name, port_value, bus_name="Global"):
        """sets data to a bus/port
        :param port_name: port name to use
        :param port_value: data value to be set
        :param bus_name: bus name to use
        :return: data from bus/port
        """
        if not self.__data_manager:
            self.__logger.error("Couldn't create instance of class 'DataManager'")
            return RET_VAL_ERROR

        self.__data_manager.SetDataPort(port_name, port_value, bus_name)

    def __get_err_trace(self):

        if self.__plugin_error_list:
            err_trace = '\n'.join('++ file: {0}.py -- {1}\n'.format(e[0], e[1].replace('\n', '\n--> '))
                                 for e in self.__plugin_error_list)
        else:
            err_trace = ('no detailed info about failure')

        return err_trace


    def load_configuration(self, configFile):
        """loads configuration from cfg-file
        :param configFile: path/to/file.cfg
        :return: success (bool)
        """
        if not opath.exists(configFile):
            self.__logger.error("Configuration file '%s' doesn't exist or is invalid." % configFile)
            return False

        component_map = self.__readConfig(configFile)

        for componentName in component_map.keys():
            class_name = component_map[componentName].get("ClassName")
            # port_in_list = component_map[componentName].get("PortIn")
            port_out_list = component_map[componentName].get("PortOut")
            input_data_list = component_map[componentName].get("InputData")
            connect_bus_list = component_map[componentName].get("ConnectBus")

            if type(connect_bus_list) != list:
                connect_bus_list = [connect_bus_list]

            order = component_map[componentName].get("Order")

            if class_name:
                if class_name in self.__plugin_map:
                    # Observer can be loaded -> Everything fine.
                    # self.__logger.debug("Loading plug-in: '%s'." % componentName)
                    cls_obj = self.__plugin_map[class_name](self.__data_manager, componentName, connect_bus_list)
                else:
                    # Observer can NOT be loaded -> Create Log Entry and raise Exception !
                    err_trace = self.__get_err_trace()

                    # Create Log Entry
                    self.__logger.error('some python modules have coding errors')
                    self.__logger.error('Please check following list for more details:')
                    self.__logger.error(err_trace)

                    msg = "Observer with ClassName %s not found, please check log for more info!" % class_name
                    self.__logger.error(msg)
                    self.__logger.error("File: \"main.log\"")
                    raise ValfError(msg, ValfError.ERR_OBSERVER_CLASS_NOT_FOUND)

            for port_out in port_out_list:
                for bus_name in connect_bus_list:
                    tmp = "Register port: Provider="
                    tmp += "'%s', PortName='%s', Bus='%s'." % (componentName, port_out, bus_name)
                    self.__logger.debug(tmp)
                    self.__data_manager.RegisterDataPort(port_out, None, bus_name)

            if componentName == "BPLReader":
                pass
            for input_data in input_data_list:
                param_name = input_data[0]
                param_value = input_data[1]
                for bus_name in connect_bus_list:
                    tmp = "Setting input data.[Component='%s', " % (componentName)
                    tmp += "Bus='%s', PortName='%s', " % (bus_name, param_name)
                    tmp += "PortValue=%s]" % str(param_value)
                    self.__logger.debug(tmp)
                    self.__data_manager.SetDataPort(param_name, param_value, bus_name)
            if order is not None:
                self.__object_map_list.append({"Order": order, "ComponentName": componentName, "ClsObj": cls_obj})

        # If whole Observer loading is done successfully,
        # we write anyway all found coding errors into the Log File as warnings
        if self.__plugin_error_list:
            err_trace = self.__get_err_trace()
            self.__logger.warning('some python modules have coding errors')
            self.__logger.warning('Please check following list for more details:')
            self.__logger.warning(err_trace)

        self.__component_list = []
        if len(self.__object_map_list):
            self.__object_map_list.sort(lambda x, y: cmp(int(x["Order"]), int(y["Order"])))

            for object_map in self.__object_map_list:
                self.__component_list.append(object_map["ClsObj"])

        if not self.__component_list:
            self.__logger.error("No component loaded. Please check config file '%s'." % str(configFile))
            return False

        self.__config_file_loaded = True

        return True

    def __readConfig(self, configFile):
        """ read in the configuration file
        :param configFile: path/to/config.file
        :return: component map
        """
        config = RawConfigParser()
        try:
            config.read(configFile)
        except Exception, ex:  # pylint: disable=W0703
            self.__logger.exception(str(ex))
            self.__logger.error("Couldn't read config file '%s' due to previous exception." % configFile)
            return None

        component_name_list = config.sections()
        if not len(component_name_list):
            self.__logger.error("Invalid configuration file: '%s'" % configFile)
            return {}

        componentMap = {}
        # init additional include config file array
        includeConfig = []
        try:
            for componentName in component_name_list:
                # shall we allow include inside all [chapters] or only inside Global?
                if componentName == "Global":
                    try:
                        includeConfig.extend(eval(config.get(componentName, "Include")))
                    except:
                        pass
                try:
                    active = config.get(componentName, "Active")
                except:
                    active = True

                # when active is False the component will not be loaded
                try:
                    if str(active).lower() == "false":
                        continue
                except:
                    pass

                # key_name_list = config.options(componentName)

                try:
                    class_name = config.get(componentName, "ClassName")
                    if len(class_name):
                        class_name = eval(class_name)
                except:
                    class_name = None

                try:
                    port_out = config.get(componentName, "PortOut")
                    if len(port_out):
                        port_out_list = []
                        try:
                            port_out_list = eval(port_out)
                        except:
                            self.__logger.error("Invalid port value. [Component: '%s', Port: '%s'.]" %
                                                (componentName, "PortOut"))
                            return {}
                except:
                    port_out_list = []

                try:
                    input_data = config.get(componentName, "InputData")
                    if len(input_data):
                        input_data_list = []
                        try:
                            input_data_list = eval(input_data)
                        except:
                            self.__logger.error("Invalid parameter value. [Component: '%s', Parameter: '%s']" %
                                                (componentName, "InputData"))
                            return {}
                except:
                    input_data_list = []

                if class_name:
                    order = config.get(componentName, "Order")
                    if len(order):
                        try:
                            order = eval(order)
                        except:
                            self.__logger.error("Invalid parameter value. [Component: '%s', Parameter: '%s']" %
                                                (componentName, "Order"))
                            return {}
                else:
                    order = None

                connect_bus = config.get(componentName, "ConnectBus")
                if len(connect_bus):
                    connect_bus_list = []
                    try:
                        connect_bus_list = eval(connect_bus)
                    except:
                        self.__logger.error("Invalid parameter value. [Component: %s, Parameter: %s]" %
                                            (componentName, "ConnectBus"))
                        return {}
                else:
                    self.__logger.error("'ConnectBus' not specified or is invalid.")
                    return {}

                componentMap[componentName] = {"ClassName": class_name,
                                                 "PortOut": port_out_list,
                                                 "InputData": input_data_list,
                                                 "ConnectBus": connect_bus_list,
                                                 "Order": order}

            # iterate through additional configs by recursivly reading them in
            for inc in includeConfig:
                componentMap.update(self.__readConfig(inc))

        except Exception, ex:  # pylint: disable=W0703
            self.__logger.error(str(ex))

        return componentMap

    def run(self):
        """called by Valf to start state machine
        """
        if not self.__config_file_loaded:
            self.__logger.error("Configuration file was not loaded. Please call 'load_configuration' method.")
            return RET_VAL_ERROR

        try:
            if self.__initialize() is RET_VAL_ERROR:
                return RET_VAL_ERROR
        except Exception, ex:  # pylint: disable=W0703
            self.__logger.exception(str(ex))
            return RET_VAL_ERROR

        try:
            if self.__process_data() is RET_VAL_ERROR:
                return RET_VAL_ERROR
        except Exception, ex:  # pylint: disable=W0703
            self.__logger.exception(str(ex))
            return RET_VAL_ERROR

        try:
            if self.__terminate() is RET_VAL_ERROR:
                return RET_VAL_ERROR
        except Exception, ex:  # pylint: disable=W0703
            self.__logger.exception(str(ex))
            return RET_VAL_ERROR

        return RET_VAL_OK

"""
$Log: process_manager.py  $
Revision 1.1 2021/12/13 17:59:53CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.13 2013/10/30 10:52:29CET Hecker, Robert (heckerr) 
Replaced Exception with more usefull information for the End User, and put extra information into the log file.
- Added comments -  heckerr [Oct 30, 2013 10:52:29 AM CET]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.12 2013/10/16 14:27:02CEST Hospes, Gerd-Joachim (uidv8815) 
add error messages if observer method returns with error
--- Added comments ---  uidv8815 [Oct 16, 2013 2:27:02 PM CEST]
Change Package : 199263:1 http://mks-psad:7002/im/viewissue?selection=199263
Revision 1.11 2013/10/01 13:45:16CEST Hospes, Gerd-Joachim (uidv8815)
new error msg for operator load problems
--- Added comments ---  uidv8815 [Oct 1, 2013 1:45:17 PM CEST]
Change Package : 196951:1 http://mks-psad:7002/im/viewissue?selection=196951
Revision 1.10 2013/07/04 11:17:49CEST Hospes, Gerd-Joachim (uidv8815)
changes for new module valf:
- process_manager initiates data_manager at init instead of load_config
- bpl uses correct module path
- processbar with simple 'include sys' to redirect process bar output
--- Added comments ---  uidv8815 [Jul 4, 2013 11:17:49 AM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.9 2013/05/29 08:37:44CEST Mertens, Sven (uidv7805)
adaptation for config loading without ConfigManager
--- Added comments ---  uidv7805 [May 29, 2013 8:37:44 AM CEST]
Change Package : 179495:8 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.8 2013/05/23 11:31:42CEST Mertens, Sven (uidv7805)
adding some comments
Revision 1.7 2013/05/23 07:55:12CEST Mertens, Sven (uidv7805)
adding comments and changing to connectionString and findClass
--- Added comments ---  uidv7805 [May 23, 2013 7:55:12 AM CEST]
Change Package : 179495:8 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.6 2013/04/19 12:44:28CEST Hecker, Robert (heckerr)
Revert to working version.
--- Added comments ---  heckerr [Apr 19, 2013 12:44:29 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.5 2013/04/12 14:46:52CEST Mertens, Sven (uidv7805)
enabling the use of a connection string on observer level.
Each of them is allowed to have an additional InputData in config,
e.g. ("connectionString", "DBQ=racadmpe;Uid=DEV_MFC31X_ADMIN;Pwd=MFC31X_ADMIN"),("dbPrefix", "DEV_MFC31X_ADMIN.").
--- Added comments ---  uidv7805 [Apr 12, 2013 2:46:53 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.4 2013/03/21 17:28:00CET Mertens, Sven (uidv7805)
solving minor pylint error issues
Revision 1.3 2013/03/01 10:23:24CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:24 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/19 21:25:39CET Hecker, Robert (heckerr)
Updates according Pep8 Styleguides.
--- Added comments ---  heckerr [Feb 19, 2013 9:25:39 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 11:06:08CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.16 2012/04/30 10:16:49CEST Mogos, Sorin (mogoss)
* change: if at least one file was processed correctely then __process_data returns 0 (RET_VAL_OK)
--- Added comments ---  mogoss [Apr 30, 2012 10:16:49 AM CEST]
Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
Revision 1.15 2011/10/31 11:40:16CET Sorin Mogos (mogoss)
* change: changed stk library path
--- Added comments ---  mogoss [Oct 31, 2011 11:40:16 AM CET]
Change Package : 85403:1 http://mks-psad:7002/im/viewissue?selection=85403
Revision 1.14 2011/08/12 09:21:01CEST Sorin Mogos (mogoss)
* update: improved error handling
--- Added comments ---  mogoss [Aug 12, 2011 9:21:01 AM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.13 2011/07/20 18:18:34CEST Castell Christoph (uidt6394) (uidt6394)
Added error handling for the case when one of the framework functions is missing from a module.
--- Added comments ---  uidt6394 [Jul 20, 2011 6:18:34 PM CEST]
Change Package : 54841:1 http://mks-psad:7002/im/viewissue?selection=54841
Revision 1.12 2011/07/18 10:25:07CEST Sorin Mogos (mogoss)
* update: renamed "GenerateReport" method as "PreTerminate"
--- Added comments ---  mogoss [Jul 18, 2011 10:25:07 AM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.11 2011/07/13 12:26:33CEST Sorin Mogos (mogoss)
* update: added "GenerateReport" method to collect results and generate validation report
Revision 1.10 2011/05/19 12:04:03CEST Sorin Mogos (mogoss)
* update: added get_data_port method
--- Added comments ---  mogoss [May 19, 2011 12:04:03 PM CEST]
Change Package : 65320:1 http://mks-psad:7002/im/viewissue?selection=65320
Revision 1.9 2010/07/28 11:28:52CEST Sorin Mogos (mogoss)
* code customisation
Revision 1.8 2010/06/28 14:46:26EEST Sorin Mogos (smogos)
* added configuration manager
--- Added comments ---  smogos [2010/06/28 11:46:26Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.7 2010/03/19 10:39:10EET Sorin Mogos (smogos)
* code customisation and bug-fixes
--- Added comments ---  smogos [2010/03/19 08:39:11Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.6 2010/03/04 09:16:28EET Gicu Benchea (gbenchea)
Add the bus constructor parameter
--- Added comments ---  gbenchea [2010/03/04 07:16:28Z]
Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
Revision 1.5 2010/02/18 16:19:15EET Sorin Mogos (smogos)
* code optimisation and bug-fixes
--- Added comments ---  smogos [2010/02/18 14:19:16Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.3 2009/11/18 13:10:39EET Sorin Mogos (smogos)
* some bug-fixes
--- Added comments ---  smogos [2009/11/18 11:10:39Z]
Change Package : 33973:1 http://LISS014:6001/im/viewissue?selection=33973
Revision 1.2 2009/10/30 18:25:28EET dkubera
make initial call generic : valf_process_manager <config_file>
--- Added comments ---  dkubera [2009/10/30 16:25:29Z]
Change Package : 32862:1 http://LISS014:6001/im/viewissue?selection=32862
Revision 1.1 2009/10/30 13:18:43CET dkubera
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/
    04_Engineering/VALF_ValidationFrame/04_Engineering/31_PyLib/project.pj
"""  # pylint: disable=W0105
