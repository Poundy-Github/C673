"""
stk/rep/pdf/algo_test/flowables
-------------------------------

**Specialized Flowables for the AlgoTestReport:**

**Internal-API Interfaces**

    - `Overview`
    - `TestDescription`
    - `TestStatistic`
    - `SummaryResults`
    - `DetailedSummary`
    - `Testcase`
    - `TableOfContents`
    - `TableOfFigures`
    - `TableOfTables`

**User-API Interfaces**

    - `stk.rep` (complete package)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:27CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.styles import ParagraphStyle
import reportlab.platypus as plat
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.lib import colors
from reportlab.lib.units import cm
from reportlab.platypus.tableofcontents import TableOfContents as RepTOC

# Import STK Modules --------------------------------------------------------------------------------------------------
from ..base import flowables as flow

pdfmetrics.registerFont(TTFont('Calibri', 'Calibri.ttf'))
# Defines -------------------------------------------------------------------------------------------------------------
DOC_STYLE_SHEET = getSampleStyleSheet()
NORMAL_STYLE = DOC_STYLE_SHEET["Normal"]

# Functions -----------------------------------------------------------------------------------------------------------


def ColorResult(result):
    if(result == 'PASSED'):
        return '<font color=green>PASSED</font>'
    elif(result == 'FAILED'):
        return '<font color=red>FAILED</font>'
    else:
        return '<font color=orange>TO BE VERIFIED</font>'

# Classes -------------------------------------------------------------------------------------------------------------


class Overview(flow.TableBase):
    """
    **Basic Table with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self):
        flow.TableBase.__init__(self)

        self._name = "Test Overview Table"
        self.title = ""
        self.description = ""
        self.project = ""
        self.component = ""
        self.test_spec = ""

    def _Create(self):
        """
        Does the final creation of the Platypus Table object.
        Including a correct numeration for the Table of Tables list.

        Typically this Method will be called by the _PreBuild-Method of
        the Story class.

        :return: story with all final objects for pdf rendering
        :rtype: list of platypus objects ready for rendering.
        """
        self._style = [('BACKGROUND', (0, 0), (0, -1), colors.lightgrey),
                       ('GRID', (0, 0), (-1, -1), 1.0, colors.black)]

        data = [[plat.Paragraph("Test Title ", NORMAL_STYLE), plat.Paragraph(self.title, NORMAL_STYLE)],
                [plat.Paragraph("Test Description ", NORMAL_STYLE), plat.Paragraph(self.description, NORMAL_STYLE)],
                [plat.Paragraph("Project ", NORMAL_STYLE), plat.Paragraph(self.project, NORMAL_STYLE)],
                [plat.Paragraph("Component ", NORMAL_STYLE), plat.Paragraph(self.component, NORMAL_STYLE)],
                [plat.Paragraph("Test Specification ", NORMAL_STYLE), plat.Paragraph(self.test_spec, NORMAL_STYLE)]]

        story = []

        table = plat.Table(data, style=self._style)

        self.AppendCaption(story)

        story.append(table)

        return story


class TestDescription(flow.TableBase):
    """
    **Basic Table with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self):
        flow.TableBase.__init__(self)

        self._name = "Test Description"
        self._testcases = []

    def __BuildTableHeader(self, column_names):
        """
        Create the Table Header Paragraph object.

        :return: ReportLab table header
        :rtype:  list[Paragraph]
        """
        header = []

        for col_name in column_names:
            header.append(plat.Paragraph("<b>%s</b>" % col_name, NORMAL_STYLE))

        return header

    def Append(self, testcase):

        self._testcases.append(testcase)

    def _Create(self):
        """
        Does the final creation of the Platypus Table object.
        Including a correct numeration for the Table of Tables list.

        Typically this Method will be called by the _PreBuild-Method of
        the Story class.

        :return: story with all final objects for pdf rendering
        :rtype: list of platypus objects ready for rendering.
        """
        self._style = [('BACKGROUND', (0, 0), (1, 0), colors.lightgrey),
                       ('GRID', (0, 0), (-1, -1), 1.0, colors.black)]

        data = []
        data.append(self.__BuildTableHeader(['Testcase', 'Description']))

        for testcase in self._testcases:
            data.append([plat.Paragraph(testcase.name, NORMAL_STYLE),
                         plat.Paragraph(testcase.description, NORMAL_STYLE)])

        story = []

        table = plat.Table(data, style=self._style)

        self.AppendCaption(story)

        story.append(table)

        return story


class TestStatistic(flow.TableBase):
    """
    **Basic Table with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self):
        flow.TableBase.__init__(self)

        self._name = "Test Statistics table"
        self._statistics = []
        self.title = ""
        self.description = ""
        self.project = ""
        self.component = ""
        self.test_spec = ""

    def __BuildTableHeader(self, column_names):
        """
        Create the Table Header Paragraph object.

        :return: ReportLab table header
        :rtype:  list[Paragraph]
        """
        header = []

        for col_name in column_names:
            header.append(plat.Paragraph("<b>%s</b>" % col_name, NORMAL_STYLE))

        return header

    def Append(self, StatisticDataSet):
        """
        Append one Statstic Data Set to the Table.
        This Method can be called multiple Times, to append more Data Sets.

        :param StatisticDataSet: 2-Dimensional Table with the Statistik Data inside.
                                 The first row is used as title.
        :type StatisticDataSet:
        """
        self._statistics.append(StatisticDataSet)

    def _Create(self):
        """
        Does the final creation of the Platypus Table object.
        Including a correct numeration for the Table of Tables list.

        Typically this Method will be called by the _PreBuild-Method of
        the Story class.

        :return: story with all final objects for pdf rendering
        :rtype: list of platypus objects ready for rendering.
        """
        style = [('GRID', (0, 0), (-1, -1), 1.0, colors.black),
                 ('BACKGROUND', (0, 0), (-1, 0), colors.lightgrey)]

        data = []

        # Add the Header to the data
        data.append(self.__BuildTableHeader(["Results", "Values", "Unit"]))

        rowcount = 0
        for statistic in self._statistics:
            # We have additional Statistic Set
            # Add new Format for the Title
            style.append(('BACKGROUND', (0, rowcount + 1), (-1, rowcount + 1), colors.lightgrey))
            for row in statistic:
                data.append(row)
                rowcount += 1

        story = []

        table = plat.Table(data, style=style)

        self.AppendCaption(story)

        story.append(table)

        return story


class SummaryResults(flow.TableBase):
    """
    **Basic Table with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self):
        flow.TableBase.__init__(self)

        self._name = "Test Statistics table"
        self._testcases = []
        self._failed = 0
        self._passed = 0
        self._verified = 0
        self.summary = True

    def __BuildTableHeader(self, column_names):
        """
        Create the Table Header Paragraph object.

        :return: ReportLab table header
        :rtype:  list[Paragraph]
        """
        header = []

        for col_name in column_names:
            header.append(plat.Paragraph("<b>%s</b>" % col_name, NORMAL_STYLE))

        return header

    def Append(self, testcase):
        """
        Append one Statstic Data Set to the Table.
        This Method can be called multiple Times, to append more Data Sets.

        :param StatisticDataSet: 2-Dimensional Table with the Statistik Data inside.
                                 The first row is used as title.
        :type StatisticDataSet:
        """

        for teststep in testcase.test_steps:
            if(teststep.test_result is teststep.PASSED):
                self._passed += 1
            elif(teststep.test_result is teststep.FAILED):
                self._failed += 1
            else:
                self._verified += 1

        self._testcases.append(testcase)

    def _CreateTestCaseResult(self, test_steps):

        test_result = 'PASSED'
        for step in test_steps:
            if(test_result is 'PASSED'):
                if(step.test_result is 'FAILED'):
                    test_result = 'FAILED'
                elif(step.test_result is 'TO BE VERIFIED'):
                    test_result = 'TO BE_ VERIFIED'
            if(test_result is 'TO BE VERIFIED'):
                if(step.test_result is 'FAILED'):
                    test_result = 'FAILED'
            if(test_result is 'FAILED'):
                break

        return test_result

    def _Create(self):
        """
        Does the final creation of the Platypus Table object.
        Including a correct numeration for the Table of Tables list.

        Typically this Method will be called by the _PreBuild-Method of
        the Story class.

        :return: story with all final objects for pdf rendering
        :rtype: list of platypus objects ready for rendering.
        """
        style = [('GRID', (0, 0), (-1, -1), 1.0, colors.black),
                 ('BACKGROUND', (0, 0), (-1, 0), colors.lightgrey)]

        data = []

        # Add the Header to the data
        data.append(self.__BuildTableHeader(["Testcase_ID", "Name", "Result"]))

        for testcase in self._testcases:
            result = self._CreateTestCaseResult(testcase.test_steps)
            data.append([testcase.id, testcase.name, plat.Paragraph(ColorResult(result), NORMAL_STYLE)])

        story = []

        table = plat.Table(data, style=style)

        self.AppendCaption(story)

        story.append(table)
        story.append(plat.Spacer(1, 1 * cm))

        if(self.summary):
            data2 = []
            # Add the Header to the data
            data2.append(self.__BuildTableHeader(["Test(s) Performed", ColorResult('PASSED'),
                                                  ColorResult('FAILED'), ColorResult('TO BE VERIFIED')]))
            data2.append([self._passed + self._failed + self._verified, self._passed, self._failed, self._verified])

            table2 = plat.Table(data2, style=style)

            story.append(table2)
            story.append(plat.Spacer(1, 1 * cm))

        return story


class DetailedSummary(flow.TableBase):
    """
    **Basic Table with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self):
        flow.TableBase.__init__(self)

        self._name = "Detailed Summary Result table"
        self._testcases = []

    def __BuildTableRow(self, row_items):
        """
        Create the Table Header Paragraph object.

        :return: ReportLab table header
        :rtype:  list[Paragraph]
        """
        row = []

        for item in row_items:
            row.append(plat.Paragraph(item, NORMAL_STYLE))

        return row

    def Append(self, testcase):
        """
        Append one Statstic Data Set to the Table.
        This Method can be called multiple Times, to append more Data Sets.

        :param StatisticDataSet: 2-Dimensional Table with the Statistik Data inside.
                                 The first row is used as title.
        :type StatisticDataSet:
        """

        self._testcases.append(testcase)

    def _Create(self):
        """
        Does the final creation of the Platypus Table object.
        Including a correct numeration for the Table of Tables list.

        Typically this Method will be called by the _PreBuild-Method of
        the Story class.

        :return: story with all final objects for pdf rendering
        :rtype: list of platypus objects ready for rendering.
        """
        style = [('GRID', (0, 0), (-1, -1), 1.0, colors.black),
                 ('BACKGROUND', (0, 0), (-1, 0), colors.darkgrey)]

        data = []

        # Add the Header to the dat
        rowcount = 0
        for testcase in self._testcases:
            # Add TestCase information
            data.append(self.__BuildTableRow([testcase.id, testcase.name, '', '', '', '']))
            rowcount += 1
            style.append(('BACKGROUND', (0, rowcount), (-1, rowcount), colors.lightgrey))
            data.append(self.__BuildTableRow(['Teststep_ID', 'Name', 'Expected Result',
                                              'Measured Result', 'Test Result', 'ASMT']))
            rowcount += 1
            # Ad Teststeps information
            for step in testcase.test_steps:
                data.append(self.__BuildTableRow([step.id, step.name, step.exp_result, step.meas_result,
                                                  ColorResult(step.test_result), step.asmt]))
                rowcount += 1

        story = []

        table = plat.Table(data, style=style)

        self.AppendCaption(story)

        story.append(table)
        story.append(plat.Spacer(1, 1 * cm))

        return story


class Testcase(flow.TableBase):
    """
    **Basic Table with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self, testcase):
        flow.TableBase.__init__(self)

        self._name = "Detailed Summary Result table"
        self._testcase = testcase

    def __BuildTableHeader(self, column_names):
        """
        Create the Table Header Paragraph object.

        :return: ReportLab table header
        :rtype:  list[Paragraph]
        """
        header = []

        for col_name in column_names:
            header.append(plat.Paragraph("<b>%s</b>" % col_name, NORMAL_STYLE))

        return header

    def _Create(self):
        """
        Does the final creation of the Platypus Table object.
        Including a correct numeration for the Table of Tables list.

        Typically this Method will be called by the _PreBuild-Method of
        the Story class.

        :return: story with all final objects for pdf rendering
        :rtype: list of platypus objects ready for rendering.
        """
        story = []

        style = [('GRID', (0, 0), (-1, -1), 1.0, colors.black),
                 ('BACKGROUND', (0, 0), (0, 5), colors.lightgrey)]

        data = []

        data.append([plat.Paragraph('Testcase Name', NORMAL_STYLE), self._testcase.name])
        data.append(['Testcase Identifier', self._testcase.id])
        data.append(['Playlist/Recording', self._testcase.collection])
        # data.append(['Files Processed', self._testcase.processed_files]) #Todo: rh
        # data.append(['Times Processed', self._testcase.processing_time]) #Todo: rh
        # data.append(['Distance Processed', self._testcase.processed_distance]) #Todo: rh

        table = plat.Table(data, style=style)
        story.append(table)

        style = [('GRID', (0, 0), (-1, -1), 1.0, colors.black),
                 ('BACKGROUND', (0, 0), (3, 0), colors.lightgrey)]

        data = []
        data.append(self.__BuildTableHeader(['Teststep', 'Measured Result', 'Expected Result', 'Test Result']))

        for step in self._testcase.test_steps:
            data.append([step.id, step.meas_result, step.exp_result, plat.Paragraph(ColorResult(step.test_result), NORMAL_STYLE)])

        table = plat.Table(data, style=style)
        story.append(table)

        story.append(plat.Spacer(1, 1 * cm))

        return story


class TableOfContents(RepTOC):
    def __init__(self):
        RepTOC.__init__(self)

        self.toc_h1 = ParagraphStyle(name='Heading1', fontSize=14, fontName="Times-Bold", leftIndent=6)
        self.toc_h2 = ParagraphStyle(name='Heading2', fontSize=12, fontName="Times-Roman", leftIndent=12)
        self.toc_h3 = ParagraphStyle(name='Heading3', fontSize=11, fontName="Times-Roman", leftIndent=32)

        self.levelStyles = [self.toc_h1, self.toc_h2, self.toc_h3]

    def _Create(self):

        story = []
        story.append(plat.Paragraph("Table of Content", ParagraphStyle(name='Heading1', fontSize=0)))
        story.append(self)
        story.append(plat.PageBreak())

        return story


class TableOfFigures(TableOfContents):
    figureTS = ParagraphStyle(name='FigureTitleStyle', fontName="Times-Roman", fontSize=10, leading=12)

    """ helper class to create a table of figure """
    def notify(self, kind, stuff):
        """ The notification hook called to register all kinds of events.
            Here we are interested in 'Figure' events only.
        """
        if kind == 'TOFigure':
            self.addEntry(*stuff)  # pylint: disable=W0142

    def _Create(self):

        story = []
        story.append(plat.PageBreak())
        self.levelStyles = [self.figureTS]
        story.append(plat.Paragraph("Table of Figures", self.toc_h1))
        story.append(self)

        return story


class TableOfTables(TableOfContents):
    tableTS = ParagraphStyle(name='TableTitleStyle', fontName="Times-Roman", fontSize=10, leading=12)
    """ helper class to create a table of tables """
    def notify(self, kind, stuff):
        """ The notification hook called to register all kinds of events.
            Here we are interested in 'Figure' events only.
        """
        if kind == 'TOTable':
            self.addEntry(*stuff)  # pylint: disable=W0142

    def _Create(self):

        story = []
        story.append(plat.PageBreak())
        self.levelStyles = [self.tableTS]
        story.append(plat.Paragraph("Table of Tables", self.toc_h1))
        story.append(self)
        return story


"""
CHANGE LOG:
-----------
$Log: flowables.py  $
Revision 1.1 2021/12/13 17:59:27CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/pdf/algo_test/project.pj
Revision 1.4 2013/12/04 13:46:12CET Hecker, Robert (heckerr) 
BugFixing.
- Added comments -  heckerr [Dec 4, 2013 1:46:13 PM CET]
Change Package : 209900:1 http://mks-psad:7002/im/viewissue?selection=209900
Revision 1.3 2013/10/25 09:02:31CEST Hecker, Robert (heckerr) 
Removed Pep8 Issues.
--- Added comments ---  heckerr [Oct 25, 2013 9:02:31 AM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.2 2013/10/21 08:44:23CEST Hecker, Robert (heckerr)
updated doxygen description.
--- Added comments ---  heckerr [Oct 21, 2013 8:44:23 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.1 2013/10/18 17:45:12CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/rep/pdf/algo_test/project.pj
"""
