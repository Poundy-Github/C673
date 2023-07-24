"""
stk/hpc/__init__.py
-------------------

Subpackage for Handling the ADAS HPC Cluster.

This Subpackage provides a complete Interface to the Cluster, to submit Jobs.

**Following Classes are available for the User-API:**

  - `Hpc`
  - `HpcSim`
  - `HpcError`
  - `TaskFactory`
  - `TaskFactoryMTS`
  - `SubTaskFactory`
  - `SubTaskFactoryMTS`

**Following Defines (classes) are available for the User-API:**
  - `JobState`
  - `JobPriority`
  - `JobUnitType`

**To get more information about the usage of the HPC Cluster, you can also check following Links:**

HPC API Documentation.
    * This Document

HPC Training documents
     * http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/REPOSITORY/Base%5fDevelopment/05%5fAlgorithm/ETK%5fEngineeringToolKit/04%5fEngineering/HPC%5fHighPerformanceComputing/01%5fSupporting%5fProcesses/05%5fPresentation/01%5fInternal/project.pj&selection=hpc%5fuser%5ftraining%5fI.pptx
     * http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/REPOSITORY/Base%5fDevelopment/05%5fAlgorithm/ETK%5fEngineeringToolKit/04%5fEngineering/HPC%5fHighPerformanceComputing/01%5fSupporting%5fProcesses/05%5fPresentation/01%5fInternal/project.pj&selection=hpc%5fuser%5ftraining%5fII.pptx

Wiki Server with FAQ's
     * https://workspace7.conti.de/content/00012124/ADAS%20Algo%20Validation%20Wiki/Home.aspx

Example submit Code under
    * http://mks-psad:7001/si/viewproject?projectName=/nfs/projekte1/REPOSITORY/Base%5fDevelopment/05%5fAlgorithm/ETK%5fEngineeringToolKit/04%5fEngineering/HPC%5fHighPerformanceComputing/05%5fTesting/05%5fTest%5fEnvironment/algo/hpc%5ftraining/project.pj

**To use the hpc package from your code do following:**

  .. python::

    # Import stk.hpc
    import stk.hpc as hpc

    # Create a instance of the Hpc class.
    myhpc = hpc.Hpc()

    myhpc.SetProject('SMFC4B0')

    myhpc.CreateJob('SMFC4B0_HLA_ECU-SIL-Test')

    ...

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:57:01CET $
"""
# Import Python Modules -------------------------------------------------------

# Add PyLib Folder to System Paths --------------------------------------------

# Import STK Modules ----------------------------------------------------------

# Import Local Python Modules -------------------------------------------------
from . hpc import Hpc
from . hpc_sim import HpcSim
from . task_factory import TaskFactory
from . task_factory_mts import TaskFactoryMTS
from . subtask_factory import SubTaskFactory
from . subtask_factory_mts import SubTaskFactoryMTS
from . ifc.hpc.hpc_defs import JobState
from . ifc.hpc.hpc_defs import JobPriority
from . ifc.hpc.hpc_defs import JobUnitType
from . error import HpcError
from . ifc.hpc.scheduler import Scheduler

"""
CHANGE LOG:
-----------
$Log: __init__.py  $
Revision 1.1 2021/12/13 17:57:01CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/hpc/project.pj
Revision 1.12 2013/09/17 16:24:19CEST Hecker, Robert (heckerr) 
Adapted to new internal structure.
- Added comments -  heckerr [Sep 17, 2013 4:24:20 PM CEST]
Change Package : 197682:1 http://mks-psad:7002/im/viewissue?selection=197682
Revision 1.11 2013/09/13 16:51:59CEST Hecker, Robert (heckerr) 
Dervided HPCError Exception handling class from StkError base exception.
--- Added comments ---  heckerr [Sep 13, 2013 4:52:00 PM CEST]
Change Package : 197303:1 http://mks-psad:7002/im/viewissue?selection=197303
Revision 1.10 2013/09/05 11:41:59CEST Hecker, Robert (heckerr)
Added HpcError Exception class tho hpc package.
--- Added comments ---  heckerr [Sep 5, 2013 11:41:59 AM CEST]
Change Package : 196378:1 http://mks-psad:7002/im/viewissue?selection=196378
Revision 1.9 2013/09/03 15:14:49CEST Hecker, Robert (heckerr)
Updated Hpc Dokumentation for User-API.
--- Added comments ---  heckerr [Sep 3, 2013 3:14:50 PM CEST]
Change Package : 192833:1 http://mks-psad:7002/im/viewissue?selection=192833
Revision 1.8 2013/08/05 11:02:58CEST Hecker, Robert (heckerr)
Removed pylint errors (Tailing whitespaces.)
--- Added comments ---  heckerr [Aug 5, 2013 11:02:58 AM CEST]
Change Package : 192625:1 http://mks-psad:7002/im/viewissue?selection=192625
Revision 1.7 2013/08/02 16:29:14CEST Hecker, Robert (heckerr)
Added additional description for our docu.
Revision 1.6 2013/08/01 15:54:07CEST Hecker, Robert (heckerr)
Removed unecessary imports.
--- Added comments ---  heckerr [Aug 1, 2013 3:54:07 PM CEST]
Change Package : 192377:1 http://mks-psad:7002/im/viewissue?selection=192377
Revision 1.5 2013/05/16 08:04:49CEST Hecker, Robert (heckerr)
Added Subtask support to HPC Job Creation.
--- Added comments ---  heckerr [May 16, 2013 8:04:49 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.4 2013/02/19 20:33:27CET Hecker, Robert (heckerr)
Added new module hpc_defs
--- Added comments ---  heckerr [Feb 19, 2013 8:33:27 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/01/23 07:56:34CET Hecker, Robert (heckerr)
Updated epydoc docu.
--- Added comments ---  heckerr [Jan 23, 2013 7:56:34 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2012/12/05 13:49:53CET Hecker, Robert (heckerr)
Updated code to pep8 guidelines.
--- Added comments ---  heckerr [Dec 5, 2012 1:49:53 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2012/12/04 17:36:11CET Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/hpc/project.pj
"""
