"""
stk/rep/__init__.py
-------------------

**Interface Module for the AlgoTestReport**

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:27CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Add PyLib Folder to System Paths ------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------

# Import Local Python Modules -----------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class TestSuite(object):

    def __init__(self):
        self.name = ""
        """
        :ivar: TestSuite name (same as in DOORS)
        :type: string
        """
        self.id = ""  # Doors Test Run View ID <Project>_yyyy_CWxx_<Reason>_L3
        """
        :ivar: TestRunView ID from DOORS.
               Format: <Project>_yyyy_CWxx_<Reason>_L3
        :type: string
        """
        self.description = ""
        """
        :ivar: TestSuite Description (same as in DOORS)
        :type: string
        """
        self.project = ""
        """
        :ivar: Project Name of TestObject
        :type: string
        """
        self.checkpoint = ""
        """
        :ivar: AlgoCheckpoint which is used in this TestSuite
        :type: string
        """
        self.date = ""
        """
        :ivar: Date, when TestSuite was created.
        :type: string
        """
        self.test_runs = []
        """
        :ivar: TestRuns which are connected to this TestSuite.
        :type: `TestRun`
        """


class TestRun(object):
    def __init__(self):
        self.name = ""
        """
        :ivar: TestRun name (same as in DOORS)
        :type: string
        """
        self.id = ""
        """
        :ivar: Testcase Identifier (from DOORS)
        :type: string
        """
        self.description = ""
        """
        :ivar: TestRun Description (same as in DOORS)
        :type: string
        """
        self.project = ""
        """
        :ivar: Project Name of TestObject
        :type: string
        """
        self.checkpoint = ""
        """
        :ivar: ComponentCheckpoint which is used in this TestRun
        :type: string
        """
        self.user_name = ""
        """
        :ivar: User, who executed the TestRun
        :type: string
        """
        self.collection = ""
        """
        :ivar: Collection/Playlist which is used in this TestRun
        :type: string
        """
        self.processed_files = 0
        """
        :ivar: Number of processed files in this TestRun.
        :type: integer
        """
        self.processing_time = 0
        """
        :ivar: Needed Processing time to execute this TestRun
        :type: string <days:hour:minute>
        """
        self.processed_distance = 0
        """
        :ivar: Processed distance inside the playlist
        :type: string <km>
        """
        self.test_cases = []
        """
        :ivar: TestCases connected to this TestRun.
        :type: `TestCase`
        """


class TestCase(object):
    def __init__(self):
        """
        :ivar: Foreign Key, to Identify the assigned TestRun (Internal table handling).
        :type: integer
        """
        self.name = ""
        """
        :ivar: Testcase name (from DOORS)
        :type: string
        """
        self.id = ""
        """
        :ivar: Testcase Identifier (from DOORS)
        :type: string
        """
        self.description = ""
        """
        :ivar: Testcase Description (from DOORS)
        :type: string
        """
        self.collection = ""
        """
        :ivar: used collection/playlist for this Testcase
        :type: string
        """

        self.test_steps = []
        """
        :ivar: all conected Test Steps to this TestCase.
        :type: `TestStep`
        """


class TestStep(object):
    """
    **This is the Teststep Interface between different stk packages.**

    All needed Teststep Information is stored inside this class,
    and can be used as data exchange between following Classes:

    - `AlgoTestReport`

    :author:        Robert Hecker
    :date:          09.10.2012
    """
    PASSED = 'PASSED'
    """
    :cvar: Predefined test_result (passed)
    :type: string
    """
    FAILED = 'FAILED'
    """
    :cvar: Predefined test_result (failed)
    :type: string
    """
    SUSPECT = 'TO BE VERIFIED'
    """
    :cvar: Predefined test_result (to be verified)
    :type: string
    """
    def __init__(self):
        """
        :ivar: Foreign Key, to Identify the assigned TestCase (Internal table handling).
        :type: integer
        """
        self.name = ""
        """
        :ivar: human readable name of the teststep
        :type: string
        """
        self.id = ""
        """
        :ivar: Unique Identifier (from DOORS)
        :type: string
        """
        self.exp_result = ""
        """
        :ivar: Expected Test Result
        :type: string
        """
        self.meas_result = ""
        """
        :ivar: Measured Test Result:
        :type: string
        """
        self.test_result = ""
        """
        :ivar: Test Result (`PASSED` or `FAILED` or `SUSPECT`)
        :type: string
        """
        self.asmt = ""
        """
        :ivar: Assesment ID.
               Either a real Assesment ID from ??.
               Or a Failure Report Item from MKS (FR:12345)
        :type: string
        """

"""
CHANGE LOG:
-----------
$Log: ifc.py  $
Revision 1.1 2021/12/13 17:59:27CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/pdf/algo_test/project.pj
Revision 1.3 2013/10/25 09:02:32CEST Hecker, Robert (heckerr) 
Removed Pep8 Issues.
- Added comments -  heckerr [Oct 25, 2013 9:02:33 AM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
"""
