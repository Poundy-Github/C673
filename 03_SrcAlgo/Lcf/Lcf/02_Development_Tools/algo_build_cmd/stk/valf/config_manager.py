"""
stk/valf/config_manager
-------------------

Reads configuration and creates class instances

:org:           Continental AG
:author:        Sorin Mogos

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:52CET $
"""

# pylint: disable=C0103,W0702,W0703

# Import Python Modules -------------------------------------------------------
import ConfigParser

# Import STK Modules ----------------------------------------------------------
import stk.util.logger as log

# Defines ---------------------------------------------------------------------

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class ConfigManager():
    """ main valf part to manage configuration """
    def __init__(self, data_manager, plugin_manager):
        """TODO
        """
        self.__logger = log.Logger(self.__class__.__name__)
        self.__data_manager = data_manager
        self.__plugin_manager = plugin_manager

        self.__object_map_list = []
        self.__object_map = {}

    def __get_port_names(self, component_name):
        """TODO
        """
        component_ports = None

        try:
            component_ports = self.__ini_reader.GetSectionKeys(component_name)
        except Exception, ex:
            self.__logger.exception(str(ex))

        if component_ports:
            return component_ports

        return None

    def __read(self, config_file_path):
        """TODO
        """
        config = ConfigParser.RawConfigParser()
        try:
            config.read(config_file_path)
        except Exception, ex:
            self.__logger.exception(str(ex))
            self.__logger.error("Couldn't read config file '%s' due to previous exception." % config_file_path)
            return None

        # component_name_list = []
        component_name_list = config.sections()
        if not len(component_name_list):
            self.__logger.error("Invalid configuration file: '%s'" % config_file_path)
            return None

        # component_list = []
        component_map = {}
        try:
            for component_name in component_name_list:
                try:
                    active = config.get(component_name, "Active")
                except:
                    active = True

                # when active is False the component will not be loaded
                try:
                    if active.lower() == "false":
                        continue
                except:
                    pass

                # key_name_list = config.options(component_name)

                try:
                    class_name = config.get(component_name, "ClassName")
                    if len(class_name):
                        class_name = eval(class_name)
                except:
                    class_name = None

                try:
                    port_out = config.get(component_name, "PortOut")
                    if len(port_out):
                        port_out_list = []
                        try:
                            port_out_list = eval(port_out)
                        except:
                            tmp = "Invalid port value. "
                            tmp += "[Component: '%s', Port: '%s'.]" % (component_name, "PortOut")
                            self.__logger.error(tmp)
                            return None
                except:
                    port_out_list = []

                try:
                    input_data = config.get(component_name, "InputData")
                    if len(input_data):
                        input_data_list = []
                        try:
                            input_data_list = eval(input_data)
                        except:
                            tmp = "Invalid parameter value. [Component: "
                            tmp += "'%s', Parameter: '%s']" % (component_name, "InputData")
                            self.__logger.error(tmp)
                            return None
                except:
                    input_data_list = []

                if class_name:
                    order = config.get(component_name, "Order")
                    if len(order):
                        try:
                            order = eval(order)
                        except:
                            tmp = "Invalid parameter value. [Component: "
                            tmp += "'%s', Parameter: '%s']" % (component_name, "Order")
                            self.__logger.error(tmp)
                            return None
                else:
                    order = None

                connect_bus = config.get(component_name, "ConnectBus")
                if len(connect_bus):
                    connect_bus_list = []
                    try:
                        connect_bus_list = eval(connect_bus)
                    except:
                        tmp = "Invalid parameter value. [Component: "
                        tmp += "%s, Parameter: %s]" % (component_name, "ConnectBus")
                        self.__logger.error(tmp)
                        return None
                else:
                    self.__logger.error("'ConnectBus' not specified or is invalid.")
                    return None

                component_map[component_name] = {"ClassName": class_name,
                                                 "PortOut": port_out_list,
                                                 "InputData": input_data_list,
                                                 "ConnectBus": connect_bus_list,
                                                 "Order": order}

        except Exception, ex:
            self.__logger.error(str(ex))
            return None

        if len(component_map):
            return  component_map

        return None

    def get_object_list(self):
        """TODO
        """
        if not len(self.__object_map):
            return None

        return self.__object_map

    def __get_component_order(self, order_list, connection_list):
        """TODO
        """
        max_cnt = 0
        for entry in connection_list:
            max_cnt = max(max_cnt, order_list[entry]["Order"])

        return max_cnt + 1

    def __set_data_port(self, entry):
        """TODO
        """
        component = entry.keys()[0]

        try:
            bus_name = entry[component]["bus"][0]
            if len(bus_name) == 0:
                return None

            for port_name in entry[component].keys():
                if port_name in ["classname", "connectionlist", "bus", "activate"]:
                    continue

                if len(entry[component][port_name]) == 1:
                    self.__data_manager.SetDataPort(port_name, entry[component][port_name][0], bus_name)
                else:
                    port_value_list = []
                    for port_value in entry[component][port_name]:
                        idx = port_value.rfind("%")
                        if idx == -1:
                            port_value_list.append(port_value)
                            continue

                        try:
                            count = int(port_value[idx + 1: len(port_value)].strip())
                        except:
                            port_value_list.append(port_value)
                            continue

                        port_value = port_value[0:idx].strip()

                        if (port_value.find("%d") != -1):
                            for idx in xrange(count):
                                port_value_list.append(port_value.replace("%d", str(idx)))
                        else:
                            break

                    self.__data_manager.SetDataPort(port_name, port_value_list, bus_name)

            return bus_name
        except:
            self.__logger.error("No bus name specified for: '%s'" % component)

        return None

    def load_configuration(self, config_file_path):
        """TODO
        """
        plugin_map = {}
        self.__logger.info("Searching for plug-ins. Please wait...")
        plugin_class_map_list = self.__plugin_manager.get_plugin_class_list()
        if plugin_class_map_list is None:
            self.__logger.error("No plug-ins found.")
            return None

        self.__logger.info("%d plug-ins found." % len(plugin_class_map_list))
        for plugin_class_map in plugin_class_map_list:
            plugin_map[plugin_class_map['name']] = plugin_class_map["type"]

        component_map = self.__read(config_file_path)
        if component_map is None:
            return None

        self.__object_map = {}
        for component_name in component_map.keys():
            class_name = component_map[component_name].get("ClassName")
            port_in_list = component_map[component_name].get("PortIn")
            port_out_list = component_map[component_name].get("PortOut")
            input_data_list = component_map[component_name].get("InputData")
            connect_bus_list = component_map[component_name].get("ConnectBus")

            if not isinstance(connect_bus_list, list):
                connect_bus_list = [connect_bus_list]

            order = component_map[component_name].get("Order")

            if class_name:
                if class_name in plugin_map:
                    # self.__logger.debug("Loading plug-in: '%s'." % component_name)
                    cls_obj = plugin_map[class_name](self.__data_manager, component_name, connect_bus_list)
                else:
                    self.__logger.error("Invalid component name: '%s'." % (class_name))
                    return None

            for port_out in port_out_list:
                for bus_name in connect_bus_list:
                    tmp = "Register port: Provider="
                    tmp += "'%s', PortName='%s', Bus='%s'." % (component_name, port_out, bus_name)
                    self.__logger.debug(tmp)
                    self.__data_manager.RegisterDataPort(port_out, None, bus_name)

            if component_name == "BPLReader":
                pass
            for input_data in input_data_list:
                param_name = input_data[0]
                param_value = input_data[1]
                for bus_name in connect_bus_list:
                    tmp = "Setting input data.[Component='%s', " % (component_name)
                    tmp += "Bus='%s', PortName='%s', " % (bus_name, param_name)
                    tmp += "PortValue=%s]" % str(param_value)
                    self.__logger.debug(tmp)
                    self.__data_manager.SetDataPort(param_name, param_value, bus_name)
            if order is not None:
                self.__object_map_list.append({"Order": order, "ComponentName": component_name, "ClsObj": cls_obj})

        if len(self.__object_map_list):
            self.__object_map_list.sort(lambda x, y: cmp(int(x["Order"]), int(y["Order"])))

            component_list = []
            for object_map in self.__object_map_list:
                component_list.append(object_map["ClsObj"])

            if len(component_list):
                self.__logger.info("%d plug-in(s) loaded." % len(component_list))
                return component_list

        return None

"""
CHANGE LOG:
-----------
$Log: config_manager.py  $
Revision 1.1 2021/12/13 17:59:52CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.11 2013/06/21 13:57:42CEST Mertens, Sven (uidv7805) 
removing unneeded find import
- Added comments -  uidv7805 [Jun 21, 2013 1:57:42 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.10 2013/05/29 08:38:11CEST Mertens, Sven (uidv7805)
reverting changes as interface changes shouldn't be
--- Added comments ---  uidv7805 [May 29, 2013 8:38:12 AM CEST]
Change Package : 179495:8 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.9 2013/05/23 07:55:13CEST Mertens, Sven (uidv7805)
adding comments and changing to connectionString and findClass
--- Added comments ---  uidv7805 [May 23, 2013 7:55:14 AM CEST]
Change Package : 179495:8 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.8 2013/04/19 12:48:37CEST Hecker, Robert (heckerr)
Functionality revert to version 1.6.
--- Added comments ---  heckerr [Apr 19, 2013 12:48:37 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.7 2013/04/12 14:47:01CEST Mertens, Sven (uidv7805)
enabling the use of a connection string on observer level.
Each of them is allowed to have an additional InputData in config,
e.g. ("connectionString", "DBQ=racadmpe;Uid=DEV_MFC31X_ADMIN;Pwd=MFC31X_ADMIN"),("dbPrefix", "DEV_MFC31X_ADMIN.").
--- Added comments ---  uidv7805 [Apr 12, 2013 2:47:01 PM CEST]
Change Package : 179495:1 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.6 2013/04/02 10:25:42CEST Raedler, Guenther (uidt9430)
- fixed string convertion errors
--- Added comments ---  uidt9430 [Apr 2, 2013 10:25:44 AM CEST]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.5 2013/03/28 09:33:18CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:19 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/03/01 10:23:22CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:23 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/28 08:12:24CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 28, 2013 8:12:24 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/20 08:21:26CET Hecker, Robert (heckerr)
Adapted to Pep8 Coding Style.
--- Added comments ---  heckerr [Feb 20, 2013 8:21:26 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 11:06:06CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.6 2010/10/03 12:16:24CEST Sorin Mogos (mogoss)
* removed component_name from RegisterDataPort
--- Added comments ---  mogoss [Oct 3, 2010 12:16:24 PM CEST]
Change Package : 51595:1 http://mks-psad:7002/im/viewissue?selection=51595
Revision 1.5 2010/09/28 16:33:31CEST Sorin Mogos (mogoss)
* bug-fix
Revision 1.4 2010/09/23 10:46:25CEST Sorin Mogos (mogoss)
* added 'Active' parameter to enable/disable a component via config file
--- Added comments ---  mogoss [Sep 23, 2010 10:46:25 AM CEST]
Change Package : 51595:1 http://mks-psad:7002/im/viewissue?selection=51595
Revision 1.3 2010/07/28 11:28:51CEST Sorin Mogos (mogoss)
* code customisation
Revision 1.2 2010/06/28 14:46:16EEST Sorin Mogos (smogos)
* added configuration manager
--- Added comments ---  smogos [2010/06/28 11:46:17Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.1 2010/06/17 16:17:52EEST Sorin Mogos (smogos)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/ETK_EngineeringToolKit/04_Engineering/VALF_ValidationFrame/
04_Engineering/31_PyLib/project.pj
"""
