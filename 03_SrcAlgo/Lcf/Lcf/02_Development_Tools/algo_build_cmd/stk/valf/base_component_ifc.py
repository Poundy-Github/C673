"""
stk/valf/base_component_ifc
-----------------------------

Main interface for all Framework and Validation PlugIns/Components

:org:           Continental AG
:author:        Gicu Benchea

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:51CET $
"""

# pylint: disable=C0103

# Import Python Modules -------------------------------------------------------

# Import STK Modules ----------------------------------------------------------
from stk.util.logger import Logger

# Defines ---------------------------------------------------------------------

# Functions -------------------------------------------------------------------

# Classes ---------------------------------------------------------------------


# try:
#     from exceptions import StandardError as _BaseException
# except ImportError:
#     _BaseException = Exception


class ValidationException(StandardError):
    """Base of all validation errors"""
    pass


class GetPortError(ValidationException):
    """Raised when an operation attempts to get a port that's not exists.

    Attributes:
        port_name -- the name of the port
        description   -- explanation of the error
    """
    def __init__(self, description):  # pylint: disable=W0231
        self.description = str(description)

    def __str__(self):
        errror_description = "=====================================================\n"
        errror_description += "ERROR: " + self.description
        errror_description += "\n=====================================================\n"

        return str(errror_description)


class BaseComponentInterface:  # pylint: disable=R0923
    """base class for observers
    init can be used to get the general things done, e.g. the logger
    """
    # Error codes.
    RET_VAL_OK = 0
    RET_VAL_ERROR = -1

    def __init__(self, data_manager, component_name, bus_name):
        """all the std things are going here, helping to reduce common code
        """
        self._bus_name = bus_name[0]
        self._component_name = component_name
        self._data_manager = data_manager

        self._version = "$Revision: 1.1 $"

        self._logger = Logger(component_name)

    def GetComponentInterfaceVersion(self):
        """ Return the version of the  component interface"""
        return 1.6

    """ Describe the gemeric interface for the validation components.
       All the components has to inherit this base class and implement the inteface functions for compatibility """
    def Initialize(self):
        """ This function is called only once after the startup. """
        return 0

    def PostInitialize(self):
        """Is called after all the component have been initialized. """
        return 0

    def LoadData(self):
        """ Prepare the input data for processing (ex: read the date from a file). """
        return 0

    def ProcessData(self):
        """ Process the input data. """
        return 0

    def PostProcessData(self):
        """ All the components has terminated the process data and execute post process. """
        return 0

    def PreTerminate(self):
        """ Collect results and generate the final report if necessary. """
        return 0

    def Terminate(self):
        """ The validation session is ended. Release resouces and database connection if necessary. """
        return 0

    def GetComponentVersion(self):
        """ Return the version of the  component"""
        return self._version.split('$')[1].split(' ')[1]

    def GetComponentName(self):
        """ Return the name  of the  component"""
        return self._component_name

"""
$Log: base_component_ifc.py  $
Revision 1.1 2021/12/13 17:59:51CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.7 2013/07/04 14:34:43CEST Mertens, Sven (uidv7805) 
providing a step ahead for oberservers being able to reduce some more code...
- Added comments -  uidv7805 [Jul 4, 2013 2:34:44 PM CEST]
Change Package : 185933:3 http://mks-psad:7002/im/viewissue?selection=185933
Revision 1.6 2013/04/23 14:05:19CEST Raedler, Guenther (uidt9430)
added common return values for all VALF Plugins
--- Added comments ---  uidt9430 [Apr 23, 2013 2:05:20 PM CEST]
Change Package : 180569:2 http://mks-psad:7002/im/viewissue?selection=180569
Revision 1.5 2013/03/28 14:20:09CET Mertens, Sven (uidv7805)
pylint: solving some W0201 (Attribute %r defined outside __init__) errors
--- Added comments ---  uidv7805 [Mar 28, 2013 2:20:09 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/03/28 09:33:22CET Mertens, Sven (uidv7805)
pylint: removing unused imports
--- Added comments ---  uidv7805 [Mar 28, 2013 9:33:23 AM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.3 2013/03/01 10:23:19CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:20 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/19 20:59:01CET Hecker, Robert (heckerr)
Improved Coding style.
--- Added comments ---  heckerr [Feb 19, 2013 8:59:01 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 11:06:04CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.6 2011/07/27 10:37:38CEST Sorin Mogos (mogoss)
* update: added return value 0 for all methods
--- Added comments ---  mogoss [Jul 27, 2011 10:37:38 AM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.5 2011/07/18 10:25:06CEST Sorin Mogos (mogoss)
* update: renamed "GenerateReport" method as "PreTerminate"
Revision 1.4 2011/07/13 12:26:32CEST Sorin Mogos (mogoss)
* update: added "GenerateReport" method to collect results and generate validation report
--- Added comments ---  mogoss [Jul 13, 2011 12:26:32 PM CEST]
Change Package : 72325:1 http://mks-psad:7002/im/viewissue?selection=72325
Revision 1.3 2010/06/28 13:46:23CEST smogos
* added configuration manager
--- Added comments ---  smogos [2010/06/28 11:46:23Z]
Change Package : 37850:1 http://LISS014:6001/im/viewissue?selection=37850
Revision 1.2 2009/11/18 13:09:34EET Sorin Mogos (smogos)
* some bug-fixes
--- Added comments ---  smogos [2009/11/18 11:09:34Z]
Change Package : 33973:1 http://LISS014:6001/im/viewissue?selection=33973
Revision 1.1 2009/10/30 14:17:10EET dkubera
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/ETK_EngineeringToolKit/04_Engineering/VALF_ValidationFrame/
04_Engineering/31_PyLib/project.pj
"""
