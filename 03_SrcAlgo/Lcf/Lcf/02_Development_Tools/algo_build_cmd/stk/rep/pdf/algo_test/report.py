"""
stk/rep/pdf/algo_test/report
----------------------------

**AlgoTestReport Module**

**User-API Interfaces**

    - `AlgoTestReport` (this module)
    - `stk.rep` (complete package)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:27CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------

# Import STK Modules --------------------------------------------------------------------------------------------------
from ..base import pdf
from ..base import template as temp
from . import template
from . import flowables

# Defines -------------------------------------------------------------------------------------------------------------
PAGE_TEMPLATE_PORTRAIT = template.PAGE_TEMPLATE_PORTRAIT
PAGE_TEMPLATE_LANDSCAPE = template.PAGE_TEMPLATE_LANDSCAPE

# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class AlgoTestReport(pdf.Story):
    """
    The AlgoTestReport class creates a Standard Report for the Algo-Validation
    for different Test-Types.

    **Following Features are included:**

    1. Posibility to define the granularity of the Report with `REP_MANAGEMENT` | `REP_DETAILED` | `REP_DEVELOPER`
    2. Generic `Testcase` and `Teststep` Interface
    3. Possibility to insert into the Developer Chapter every pdf-platypus element you want.

    **Example:**

    .. python::

        # Import stk.rep
        import stk.rep as rep

        # Create a instance of the reporter class.
        report = rep.AlgoTestReport()

        # Create a Testrun Object
        testrun = rep.ifc.TestRun()

        # Fill in Data into the TestRun
        ...

        # Add one ore multiple Testcases into the report
        report.SetTestRun(testrun)

        # Save the Report to Disk
        report.Build("AlgoTestReport.pdf")

        ...

    :author:        Robert Hecker
    :date:          22.01.2012
    """
    REP_MANAGEMENT = 1
    """
    Render only the Management Part inside the Report
    """
    REP_DETAILED = 2
    """
    Render additional to `REP_MANAGEMENT` the Detailed Chapter into the Report
    """
    REP_DEVELOPER = 4
    """
    Render additional to `REP_DETAILED` the Developer Chapter into the Report
    """

    def __init__(self):
        self.style = temp.Style()
        pdf.Story.__init__(self, self.style)
        self._doc = None

        self._TitlePage = template.TitlePageTemplate(template.AlgoTestDocTemplate(self.style, ""))
        self._Overview = template.OverviewTemplate()

        self._TestDetails = template.TestDetails()

        self.Developer = template.DeveloperTemplate()  # pylint: disable=C0103

    def __CreateTableOfContent(self, story):
        """
        Append the Table Of Contents to the story.

        :param story: Pdf-story
        :type story:  ?
        :return:      -
        """
        toc = flowables.TableOfContents()
        story += toc._Create()  # pylint: disable=W0212

    def __CreateTableOfFigures(self, story):
        """
        Append the Table Of Figures to the story.

        :param story: Pdf-story
        :type story:  ?
        :return:      -
        """
        tof = flowables.TableOfFigures()
        story += tof._Create()  # pylint: disable=W0212

    def __CreateTableOfTables(self, story):
        """
        Append the Table Of Tables to the story.

        :param story: Pdf-story
        :type story: ?
        :return:      -
        """
        tot = flowables.TableOfTables()
        story += tot._Create()  # pylint: disable=W0212

    def SetTestRun(self, testrun):
        """
        Specify a Component TestRun which is used to Build a Report.
        This method is used to create a AlgoTestReport on component Level with all the Standrized output.
        The Developer Part of the Report is untouched by this.

        :param testrun: Complete TestRun for one Component.
        :type testrun:  Object of Type `ITestRun`
        """
        # Set Tile in Title Page
        self._TitlePage.title = testrun.name

        # Set Title in Overview Table
        self._Overview.OverviewTable.title = testrun.name

        # Set Checkpoint
        self._TitlePage.checkpoint = testrun.checkpoint

        # Set Description
        self._Overview.OverviewTable.description = testrun.description

        # Set Project
        self._Overview.OverviewTable.project = testrun.project

        # Set Component Name
        self._Overview.OverviewTable.component = testrun.name

        # Set test_spec
        self._Overview.OverviewTable.test_spec = testrun.id

        for testcase in testrun.test_cases:
            self.__AddTestcase(testcase)

    def __AddTestcase(self, testcase):
        """
        Add a complete Testcase to the Report.
        This method can be called multiple times to add multiple Testcases to the Report.

        :param testcase: Complete Testcase Object including all depending Teststeps
        :type testcase:  Object of Type TestCase
        """

        # do a concistency check of the testcase
        for teststep in testcase.test_steps:
            # Check if result is one of the expected values
            if(teststep.test_result is teststep.PASSED or
               teststep.test_result is teststep.FAILED or
               teststep.test_result is teststep.SUSPECT):
                # Everything ok append result
                pass
            else:
                raise ValueError()

        # Get the Testcase Description out of teh Testcase and feed them into Overview
        self._Overview.TestDescription.Append(testcase)

        # Create a entry for the Summary Result
        self._Overview.SummaryResultsTable.Append(testcase)

        # Create a Entry for the Detailed Summary Results Table
        self._TestDetails.SummaryResults.Append(testcase)

        self._TestDetails.Append(testcase)

    def Build(self, filepath, level=REP_DEVELOPER):
        """
        Render the complete AlgoTestReport and save it to file.

        :param filepath: path/name of the pdf report.
        :type filepath:  string
        :param level:    Specifies the detail level of the report
        :type level:     <`REP_MANAGEMENT` | `REP_DETAILED` | `REP_DEVELOPER`>
        """
        # Create a Instance of our Template Document class, which is needed to create our Document
        self._doc = template.AlgoTestDocTemplate(self.style, filepath)

        self.story = []

        # Create the Title Page
        self._TitlePage._Create(self.story)  # pylint: disable=W0212

        # Create TableOfContent
        self.__CreateTableOfContent(self.story)

        # Create Overview Chapter
        self._Overview._Create(self.story)  # pylint: disable=W0212

        if(level is self.REP_DEVELOPER or level is self.REP_DETAILED):
            # Create Test Details Chapter
            self._TestDetails._Create(self.story)  # pylint: disable=W0212

        if(level is self.REP_DEVELOPER):
            # Append the developer story to the main story
            self.story += self.Developer.story

        # Append the Table of Figures to the story
        self.__CreateTableOfFigures(self.story)

        # Append the Table of Tables to the story
        self.__CreateTableOfTables(self.story)

        # First go through the whole story, and Format the story in the wanted way.
        story = self._PreBuild()

        # Do the final Creation of the pdf Doc rendering....
        self._doc.multiBuild(story)

"""
CHANGE LOG:
-----------
$Log: report.py  $
Revision 1.1 2021/12/13 17:59:27CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/pdf/algo_test/project.pj
Revision 1.5 2013/12/04 13:46:13CET Hecker, Robert (heckerr) 
BugFixing.
- Added comments -  heckerr [Dec 4, 2013 1:46:14 PM CET]
Change Package : 209900:1 http://mks-psad:7002/im/viewissue?selection=209900
Revision 1.4 2013/10/25 09:02:33CEST Hecker, Robert (heckerr) 
Removed Pep8 Issues.
--- Added comments ---  heckerr [Oct 25, 2013 9:02:33 AM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.3 2013/10/22 14:27:12CEST Hecker, Robert (heckerr
modified parameter type.
--- Added comments ---  heckerr [Oct 22, 2013 2:27:12 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.2 2013/10/21 08:44:24CEST Hecker, Robert (heckerr)
updated doxygen description.
--- Added comments ---  heckerr [Oct 21, 2013 8:44:24 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.1 2013/10/18 17:45:13CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/rep/pdf/algo_test/project.pj
"""
