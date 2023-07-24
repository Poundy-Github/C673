"""
stk/valf/__init__.py
--------------------

Subpackage for Running ADAS Algo Validation Framework **ValF**.

This Subpackage provides classes and functions to easily validate simulation output.

**Following Classes are available for the User-API:**

  - `Valf`
  - `BPLReader`
  - `CATReader`
  - `SignalExtractor`
  - `DBConnector`
  - `ValfError`

**Following Defines (classes/constants) are available for the User-API:**
  - `BaseComponentInterface`
  - `signal_defs`

**Tool to create empty observer:**
  - `base_component_wizard`

**To get more information about the Validation support you can also check following Links:**

Valf API Documentation.
    * This Document

Valf Training documents
    * https://workspace7.conti.de/content/00012124/Team%20Documents/Trainings/VALF_ValidationFramework/Algo_Validation_Training.pptx
    * https://workspace7.conti.de/content/00012124/Team%20Documents/Trainings/VALF_ValidationFramework

Wiki Server with FAQ's
     * https://workspace7.conti.de/content/00012124/ADAS%20Algo%20Validation%20Wiki/VALF.aspx

Demo example Code under
    * http://mks-psad:7001/si/viewproject?projectName=/nfs/projekte1/REPOSITORY/Base%5fDevelopment/05%5fAlgorithm/STK%5fScriptingToolKit/05%5fTesting/05%5fTest%5fEnvironment/valfdemo/project.pj

**To run a validation suite using Valf class follow this example:**

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


:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:51CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------
from base_component_ifc import ValidationException
from base_component_ifc import BaseComponentInterface

from process_manager import ProcessManager
from data_manager import DataManager
from config_manager import ConfigManager
from plugin_manager import PluginManager

"""
CHANGE LOG:
-----------
$Log: __init__.py  $
Revision 1.1 2021/12/13 17:59:51CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.4 2013/11/13 16:20:40CET Hospes, Gerd-Joachim (uidv8815) 
add ActivateHpcAutoSplit method and usage of port HpcAutoSplit to Valf class, updated tests and epydoc for all related files
- Added comments -  uidv8815 [Nov 13, 2013 4:20:40 PM CET]
Change Package : 206278:1 http://mks-psad:7002/im/viewissue?selection=206278
Revision 1.3 2013/03/21 17:27:57CET Mertens, Sven (uidv7805)
solving minor pylint error issues
--- Added comments ---  uidv7805 [Mar 21, 2013 5:27:57 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.2 2013/02/11 11:07:44CET Raedler, Guenther (uidt9430)
- added valf classes from etk/valf - renamed files
--- Added comments ---  uidt9430 [Feb 11, 2013 11:07:44 AM CET]
Change Package : 174385:1 http://mks-psad:7002/im/viewissue?selection=174385
Revision 1.1 2013/01/23 07:59:44CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/
    stk/valf/project.pj
"""
