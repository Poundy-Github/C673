"""
stk/valf/data_manager
-----------------

Implements the data communcation mechanism between the validation components
and also generic data storage.

:org:           Continental AG
:author:        Gicu Benchea

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:52CET $
"""

# pylint: disable=C0103

# Import Python Modules -------------------------------------------------------

# Import STK Modules ----------------------------------------------------------
import stk.util.logger as log

# Defines ---------------------------------------------------------------------
PORT_STAT_RUN = False

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


class DataManager():
    """
    handling ports to exchange data between components
    """
    def __init__(self, name="DataManager"):
        self.__logger = log.Logger(self.__class__.__name__)

        self.__name = name
        self.__data_port_map = {}
        self.__data_port_acces_map = {}

    def __str__(self):
        """returns the name
        """
        return self.__name

    def RegisterDataPort(self, port_name, port_value, bus_name="Global"):
        """
        Registers port data with given name, value and bus

        :note: use SetDataPort instead
        :param port_name: The name of the port
        :param port_value: The value of the port
        :param bus_name: opt. bus name, default: "Global"
        """
        self.SetDataPort(port_name, port_value, bus_name)

    def ExistsDataPort(self, port_name, bus_name="BUS_BASE"):
        """
        Checks if the DataPort is already registred in the data_manager

        :param port_name: the port name
        :param bus_name: the bus name
        :return: True  - the data port data is registred
                False - the data port is not registred
        :author:          Gicu Benchea
        """
        if not self.__data_port_map.get(bus_name.lower()):
            self.__logger.error("Invalid bus name. [Bus name: '%s']." % (bus_name))
            return None

        if not port_name.lower() in self.__data_port_map[bus_name.lower()]:
            self.__logger.error("Invalid port name. [PortName: '%s']." % (port_name))
            return  False

        return True

    def SetDataPort(self, port_name, port_value, bus_name="Global"):
        """
        Sets the given port with value and bus

        :param port_name: The name of the port
        :param port_value: The value of the port
        :param bus_name: opt. bus name, default: "Global"
        """

        try:
            self.__data_port_map[bus_name.lower()].update({port_name.lower(): port_value})
        except KeyError:
            self.__data_port_map[bus_name.lower()] = {port_name.lower(): port_value}

        self.__update_port_access_stat(port_name, bus_name, False)

    def ClearDataPorts(self, port_name_list, apl_name="Global", bus_name="BUS_BASE"):  # pylint: disable=W0613
        """
        deletes all ports in given list

        :param port_name_list: list [] of ports
        :param apl_name: opt. component name, default: "Global"
        :param bus_name: opt. bus name, default "BUS_BASE"
        """
        if not isinstance(port_name_list, list):
            tmp = "Expected instance of type 'list' but instance of type "
            tmp += "'%s' found instead." % str(type(port_name_list))
            self.__logger.error(tmp)
            return False

        if not self.__data_port_map.get(bus_name.lower()):
            self.__logger.error("Invalid bus name. [Bus name :'%s']." % (bus_name))
            return None

        for port_name in port_name_list:
            if port_name.lower() in self.__data_port_map[bus_name.lower()]:
                del self.__data_port_map[bus_name.lower()][port_name.lower()]

    def GetDataPortPool(self):
        """
        returns internal port map

        :return: complete dict with bus/ports/value pairs
        """
        return self.__data_port_map

    def GetDataPort(self, port_name, bus_name="Global"):
        """
        Returns the value of the named data port / bus from the data manger

        :param port_name: name of value to be returned
        :param bus_name: opt. name of the bus providing the port, default "Global"
        :return: value or None
        :author: Gicu Benchea
        """
        if not self.__data_port_map.get(bus_name.lower()):
            self.__logger.error("Invalid bus name: '%s'." % str(bus_name))
            return None

        self.__update_port_access_stat(port_name, bus_name)

        return self.__data_port_map[bus_name.lower()].get(port_name.lower())

    def get_registered_bus_list(self):
        """
        provides list of all registerd busses

        :return: bus list or None
        """
        if self.__data_port_map:
            return self.__data_port_map.keys()

        return None

    def get_registered_ports(self, bus_name):
        """
        Returns registered ports for specified bus

        :param bus_name: name of bus to get the ports from
        :return: list of port names
        """
        if not self.__data_port_map.get(bus_name.lower()):
            self.__logger.error("Invalid bus name: '%s'." % str(bus_name))

        return self.__data_port_map[bus_name.lower()].keys()

    def __update_port_access_stat(self, port_name, bus_name, read=True):
        """
        updates port usage statistic: increaments internal map with [write_no, read_no]
        statistic reported with 'port_access_stat()'

        :param port_name:
        :param bus_name:
        :param read: opt., True (default): data read, False: data written
        """
        if not PORT_STAT_RUN:
            return

        data = None
        if self.__data_port_acces_map.get(bus_name.lower()):
            data = self.__data_port_acces_map[bus_name.lower()].get(port_name.lower())

        if not data:
            data = [0, 0]

        if read:
            data[1] += 1
        else:
            data[0] += 1

        try:
            self.__data_port_acces_map[bus_name.lower()].update({port_name.lower(): data})
        except KeyError:
            self.__data_port_acces_map[bus_name.lower()] = {port_name.lower(): data}

    def port_access_stat(self):
        """
        writes statistic in logger of all unused ports (only read, only written)

        """
        for bus_name, ports in self.__data_port_acces_map.iteritems():
            self.__logger.error("Status of : '%s'." % str(bus_name))
            for port_name, data in ports.iteritems():
                if data[0] == 0:
                    self.__logger.error("  Port '%s' was only readen." % str(port_name))
                if data[1] == 0:
                    self.__logger.error("  Port '%s' was only written." % str(port_name))
        return

    def __del__(self):
        print ("DataManager '%s' exited" % self.__name)


"""
CHANGE LOG:
-----------
$Log: data_manager.py  $
Revision 1.1 2021/12/13 17:59:52CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.8 2013/07/04 14:24:14CEST Mertens, Sven (uidv7805) 
exiting is more friendly than dying: could be misunderstood with a crash
- Added comments -  uidv7805 [Jul 4, 2013 2:24:15 PM CEST]
Change Package : 185933:1 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.7 2013/05/29 08:38:56CEST Mertens, Sven (uidv7805)
adding local pylint ignore and str representation as intended
--- Added comments ---  uidv7805 [May 29, 2013 8:38:56 AM CEST]
Change Package : 179495:7 http://mks-psad:7002/im/viewissue?selection=179495
Revision 1.6 2013/04/03 15:57:44CEST Hospes, Gerd-Joachim (uidv8815)
style fix
--- Added comments ---  uidv8815 [Apr 3, 2013 3:57:44 PM CEST]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.5 2013/04/03 15:28:47CEST Hospes, Gerd-Joachim (uidv8815)
fixed dublicate code in SetDataPort and RegisterDataPort, added epydoc content
--- Added comments ---  uidv8815 [Apr 3, 2013 3:28:48 PM CEST]
Change Package : 169590:2 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.4 2013/03/28 09:33:18CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:18 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.3 2013/03/01 10:23:23CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:23 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/20 08:21:26CET Hecker, Robert (heckerr)
Adapted to Pep8 Coding Style.
--- Added comments ---  heckerr [Feb 20, 2013 8:21:27 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 11:06:07CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm
/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.8 2012/04/30 10:16:38CEST Mogos, Sorin (mogoss)
* change: if at least one file was processed correctely then
__process_data returns 0 (RET_VAL_OK)
--- Added comments ---  mogoss [Apr 30, 2012 10:16:39 AM CEST]
Change Package : 104217:1 http://mks-psad:7002/im/viewissue?selection=104217
Revision 1.7 2011/07/19 12:57:46CEST Sorin Mogos (mogoss)
* update: added 'bus_name' parameter to 'get_registered_ports' method
* fix: some minor bug-fixes
--- Added comments ---  mogoss [Jul 19, 2011 12:57:48 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.6 2010/10/01 13:31:25CEST Sorin Mogos (mogoss)
* removed component_name dependencies
Revision 1.5 2010/06/28 13:46:21CEST smogos
* added configuration manager
--- Added comments ---  smogos [2010/06/28 11:46:21Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.4 2010/03/19 10:35:11EET Sorin Mogos (smogos)
* code customisation and bug-fixes
--- Added comments ---  smogos [2010/03/19 08:35:11Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.3 2010/03/04 09:16:27EET Gicu Benchea (gbenchea)
Add the bus constructor parameter
--- Added comments ---  gbenchea [2010/03/04 07:16:27Z]
Change Package : 31947:1 http://LISS014:6001/im/viewissue?selection=31947
Revision 1.2 2010/02/18 15:29:21EET Sorin Mogos (smogos)
* code optimisation and bug-fixes
--- Added comments ---  smogos [2010/02/18 13:29:21Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.1 2009/10/30 14:18:41EET dkubera
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/ETK_EngineeringToolKit/04_Engineering/VALF_ValidationFrame/
04_Engineering/31_PyLib/project.pj
"""
