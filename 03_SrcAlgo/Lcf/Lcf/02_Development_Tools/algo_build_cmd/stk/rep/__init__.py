"""
stk/rep/__init__.py
-------------------

**Report generation package for different validation aspects and report formats.**

.. packagetree::
   :style: UML

**User-API Interfaces**

  - `pdf`
  - `Excel`
  - `Word`

**To generate a simple AlgoTestReport from your code do following:**

  .. python::

    # Import stk.rep
    import stk.rep as rep

    # Create a instance of the reporter class.
    report = rep.AlgoTestReport()

    # Create a Testrun Object
    testrun = rep.TestRun()

    # Fill in Data into the TestRun
    ...

    # Add one ore multiple Testcases into the report
    report.SetTestRun(testrun)

    # Save the Report to Disk
    report.Build("AlgoTestReport.pdf")

    ...


:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:02CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------
from . pdf.base.pdf import Pdf
from . pdf.algo_test.report import AlgoTestReport
from . pdf.algo_test import ifc

from . report_base import *

from reportlab.platypus.flowables import *
from reportlab.lib.units import *

"""
CHANGE LOG:
-----------
$Log: __init__.py  $
Revision 1.1 2021/12/13 17:59:02CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/project.pj
Revision 1.11 2013/10/25 09:02:28CEST Hecker, Robert (heckerr) 
Removed Pep8 Issues.
- Added comments -  heckerr [Oct 25, 2013 9:02:29 AM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.10 2013/10/24 17:39:00CEST Hecker, Robert (heckerr)
to get unittest working again.
--- Added comments ---  heckerr [Oct 24, 2013 5:39:01 PM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.9 2013/10/21 08:41:20CEST Hecker, Robert (heckerr)
updated doxygen description.
--- Added comments ---  heckerr [Oct 21, 2013 8:41:20 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.8 2013/10/18 09:34:28CEST Hecker, Robert (heckerr)
Changed to new AlgoTestReporter Class.
--- Added comments ---  heckerr [Oct 18, 2013 9:34:28 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
"""
