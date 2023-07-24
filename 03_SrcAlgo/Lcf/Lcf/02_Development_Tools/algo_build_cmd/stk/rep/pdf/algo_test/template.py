"""
stk/rep/pdf/algo_test/template
------------------------------

**Template/Layout module of AlgoTestReport**

**Internal-API Interfaces**

    - `TestDetails`
    - `OverviewTemplate`
    - `DeveloperTemplate`
    - `TitlePageTemplate`
    - `PortraitTemplate`
    - `LandscapePageTemplate`
    - `AlgoTestDocTemplate`

**User-API Interfaces**

    - `stk.rep` (complete package)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:27CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
import os
import time
from StringIO import StringIO
from reportlab.lib import colors
from reportlab.lib.units import cm
from reportlab.lib.enums import TA_CENTER
from reportlab.pdfbase import pdfmetrics
from reportlab.pdfbase.ttfonts import TTFont
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.lib.styles import ParagraphStyle
import reportlab.platypus.doctemplate as dtp
import reportlab.platypus as plat

# Import STK Modules --------------------------------------------------------------------------------------------------
from ..base import template as temp
from ..base import pdf
from stk.rep.image import logo
from . import flowables as flow

pdfmetrics.registerFont(TTFont('Calibri', 'Calibri.ttf'))
# Defines -------------------------------------------------------------------------------------------------------------
PAGE_TEMPLATE_TITLE_PAGE = 'TitlePageTemplate'
COPYRIGHT = "COPYRIGHT. CONFIDENTIAL AND PROPRIETARY. ALL RIGHTS RESERVED - Property of Continental AG. " \
            "This information carrier and the information it contains are the property of Continental AG. " \
            "Any reproduction, disclosure or use of either is prohibited without the prior written consent " \
            "of Continental AG. Continental AG reserves worldwide all rights also in the case of industrial" \
            " property rights being granted. The same provisions apply to any oral communications related" \
            " thereto accordingly."

# Functions -----------------------------------------------------------------------------------------------------------
PAGE_TEMPLATE_PORTRAIT = temp.PAGE_TEMPLATE_PORTRAIT
PAGE_TEMPLATE_LANDSCAPE = temp.PAGE_TEMPLATE_LANDSCAPE

# Classes -------------------------------------------------------------------------------------------------------------


class TestDetails(object):
    def __init__(self):
        self.SummaryResults = flow.DetailedSummary()

        self._testcases = []

    def Append(self, testcase):

        self._testcases.append(testcase)

    def _Create(self, story):

        local_story = pdf.Story(temp.Style())

        local_story.AddHeading("Test Details", 0)
        local_story.AddHeading("Overview", 1)
        local_story.AddSpace(1)

        local_story.Append(self.SummaryResults)
        local_story.AddSpace(1)

        for testcase in self._testcases:
            local_story.AddHeading('Testcase ' + testcase.name, 1)
            local_story.AddSpace(1)
            local_story.AddParagraph(testcase.description)
            local_story.AddSpace(1)
            # Create Table and add Table to Report
            tc_table = flow.Testcase(testcase)
            local_story.Append(tc_table)

        story += local_story.story


class OverviewTemplate(object):
    def __init__(self):
        self.OverviewTable = flow.Overview()
        self.TestDescription = flow.TestDescription()
        self.StatisticTable = flow.TestStatistic()
        self.SummaryResultsTable = flow.SummaryResults()

    def _Create(self, story):

        local_story = pdf.Story(temp.Style())

        local_story.AddHeading("Test Overview", 0)
        local_story.AddHeading("Testcase Overview", 1)

        local_story.AddParagraph('Hello World')
        local_story.AddSpace(1)

        local_story.Append(self.OverviewTable)
        local_story.AddSpace(1)

        local_story.AddHeading("Testcases", 1)
        local_story.AddSpace(1)
        local_story.Append(self.TestDescription)

        local_story.AddHeading("Test Statistics", 1)
        local_story.AddSpace(1)

        local_story.Append(self.StatisticTable)

        local_story.AddHeading("Summary Results of Testcases", 1)
        local_story.Append(self.SummaryResultsTable)

        local_story.AddPageBreak()

        story += local_story.story


class DeveloperTemplate(pdf.Story):
    def __init__(self):
        self.style = temp.Style()
        pdf.Story.__init__(self, self.style)

        self.AddHeading("Development details", 0)


class TitlePageTemplate(dtp.PageTemplate):

    CONF_LEVEL_UNCLASSIFIED = "- Unclassified -"
    CONF_LEVEL_CONFIDENTIAL = "- Confidential -"
    CONF_LEVEL_STRICTLY = "- Strictly Confidential -"
    DRAFT_STATEMENT = "DRAFT"
    DOC_STYLE_SHEET = getSampleStyleSheet()
    TITLE_STYLE = DOC_STYLE_SHEET["Title"]
    NORMAL_STYLE = DOC_STYLE_SHEET["Normal"]
    ID = PAGE_TEMPLATE_TITLE_PAGE

    def __init__(self, doc):
        self._doc = doc
        self.title = "Not Set"
        self.checkpoint = "AL_SMFC4B0_00.00.00"
        self.author = os.environ["USERNAME"]
        self.subject = "Unknown"
        self.status = "draft"
        self.date = time.asctime()
        self.confidential_level = self.CONF_LEVEL_STRICTLY
        self.CENTER_STYLE = self.NORMAL_STYLE
        self.CENTER_STYLE.alignment = 1
        self.frames = [dtp.Frame(doc.leftMargin, doc.bottomMargin,  # pylint: disable=E1101
                                 doc.width, doc.height, id='F0')]  # pylint: disable=E1101
        dtp.PageTemplate.__init__(self, self.ID, self.frames, onPage=self.OnPage, pagesize=doc.pagesize)

    def OnPage(self, canv, doc):
        canv.saveState()
        canv.setTitle(self.title)
        if self.author is not None:
            canv.setAuthor(self.author)
        if self.subject is not None:
            canv.setSubject(self.subject)
        if self.status == "draft":
            canv.setFillColor(colors.gray)
            canv.setStrokeColor(colors.gray)
            canv.setFont("Helvetica-Bold", 85)
            canv.drawCentredString(10.5 * cm, 8 * cm, self.DRAFT_STATEMENT)
        canv.restoreState()
        self._doc.handle_nextPageTemplate(temp.PAGE_TEMPLATE_PORTRAIT)

    def _Create(self, story):
        """Create title page.
        """
        # add logo
        story.append(plat.Image(StringIO(logo.CONTI_CORP_LOGO),
                     width=logo.CONTI_LOGO_SIZE[0] * 0.5, height=logo.CONTI_LOGO_SIZE[1] * 0.5))
        story.append(plat.Spacer(1, 2 * cm))

        # add title
        story.append(plat.Paragraph(self.title, self.TITLE_STYLE))
        story.append(plat.Spacer(1, 1 * cm))

        # add title
        story.append(plat.Paragraph("for", self.TITLE_STYLE))
        story.append(plat.Spacer(1, 1 * cm))

        # add checkpoint
        story.append(plat.Paragraph(self.checkpoint, self.TITLE_STYLE))
        story.append(plat.Spacer(1, 3 * cm))

        # confidence statement
        story.append(plat.Paragraph('<para alignment="center">%s</para>' % self.confidential_level, self.TITLE_STYLE))
        story.append(plat.Spacer(1, 3 * cm))

        # Add Date
        story.append(plat.Spacer(1, 7 * cm))
        story.append(plat.Paragraph(self.date, self.CENTER_STYLE))

        story.append(plat.PageBreak())


class PortraitPageTemplate(temp.PortraitPageTemplate):

    GLOB_PAGE_BOTTOM_MARGIN = 1.8 * cm
    GLOB_PAGE_HEIGHT = 25 * cm
    GLOB_PAGE_WIDTH = 15 * cm

    def __init__(self, doctemplate):
        temp.PortraitPageTemplate.__init__(self, doctemplate)

    def OnPage(self, canv, doc):
        """This function is uses to write pages.
        :param canv: -- widget that provides structured graphics facilities
        :param doc: -- document template
        """
        canv.saveState()

        pl = plat.Paragraph("Continental<br/>ADAS",
                            ParagraphStyle(name="plb", fontSize=8, fontName="Calibri",
                                           alignment=TA_CENTER, leading=12))

        pc = plat.Paragraph(COPYRIGHT, ParagraphStyle(name="pcb", fontSize=6, fontName="Calibri",
                                                      alignment=TA_CENTER, leading=5))
        ww = 10 * cm
        _, hh = pc.wrap(ww, doc.bottomMargin)
        pr = plat.Paragraph("%s" % (doc.BuildPageIndexString()),  # doc.page
                            ParagraphStyle(name="pr", fontSize=8, fontName="Calibri", alignment=TA_CENTER))

        tf = plat.Table([[pl, pc, pr]], [3.2 * cm, ww, 3.2 * cm], ident="bottomTable")
        tf.setStyle(plat.TableStyle([('INNERGRID', (0, 0), (-1, -1), 0.25, colors.black),
                                     ('BOX', (0, 0), (-1, -1), 0.25, colors.black), ]))
        tf.wrapOn(canv, ww, hh)
        tf.drawOn(canv, doc.leftMargin, self.GLOB_PAGE_BOTTOM_MARGIN - 0.2 * cm)

        pl = plat.Image(StringIO(logo.CONTI_CORP_LOGO),
                        4 * cm, 4 * cm * logo.CONTI_LOGO_SIZE[1] / float(logo.CONTI_LOGO_SIZE[0]))
        ps = ParagraphStyle(name="pst", fontSize=14, FontName="Calibri", alignment=TA_CENTER)
        pc = plat.Paragraph("Algorithm Test Results", ps)
        # pr = Paragraph(self._headerInfo[4], ps)
        tf = plat.Table([[pl, pc]], [4.2 * cm, 12.2 * cm], ident="topTable")
        tf.setStyle(plat.TableStyle([('INNERGRID', (0, 0), (-1, -1), 0.25, colors.black),
                                     ('BOX', (0, 0), (-1, -1), 0.25, colors.black),
                                     ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
                                     ('VALIGN', (0, 0), (-1, -1), 'MIDDLE'), ]))
        tf.wrapOn(canv, 10 * cm, hh)
        tf.drawOn(canv, doc.leftMargin, self.GLOB_PAGE_HEIGHT + 2.4 * cm)
        canv.restoreState()


class LandscapePageTemplate(temp.LandscapePageTemplate):

    GLOB_PAGE_BOTTOM_MARGIN = 1.8 * cm
    GLOB_PAGE_HEIGHT = 25 * cm
    GLOB_PAGE_WIDTH = 15 * cm

    def __init__(self, doctemplate):
        temp.LandscapePageTemplate.__init__(self, doctemplate)

    def OnPage(self, canv, doc):
        """This function is uses to write pages.
        :param canv: -- widget that provides structured graphics facilities
        :param doc: -- document template
        """
        canv.saveState()

        pl = plat.Paragraph("Continental<br/>ADAS",
                            ParagraphStyle(name="plb", fontSize=8, fontName="Calibri",
                                           alignment=TA_CENTER, leading=8))

        pc = plat.Paragraph(COPYRIGHT, ParagraphStyle(name="pcb", fontSize=6, fontName="Calibri",
                                                      alignment=TA_CENTER, leading=5))
        ww = 18.7 * cm
        _, hh = pc.wrap(ww, doc.bottomMargin)
        pr = plat.Paragraph("%s" % (doc.BuildPageIndexString()),  # doc.page
                            ParagraphStyle(name="pr", fontSize=8, fontName="Calibri", alignment=TA_CENTER))
        tf = plat.Table([[pl, pc, pr]], [3.2 * cm, ww, 3.2 * cm], ident="bottomTable")
        tf.setStyle(plat.TableStyle([('INNERGRID', (0, 0), (-1, -1), 0.25, colors.black),
                                     ('BOX', (0, 0), (-1, -1), 0.25, colors.black), ]))
        tf.wrapOn(canv, ww, hh)
        tf.drawOn(canv, doc.leftMargin, self.GLOB_PAGE_BOTTOM_MARGIN - 0.2 * cm)

        pl = plat.Image(StringIO(logo.CONTI_CORP_LOGO),
                        4 * cm, 4 * cm * logo.CONTI_LOGO_SIZE[1] / float(logo.CONTI_LOGO_SIZE[0]))
        ps = ParagraphStyle(name="pst", fontSize=14, FontName="Calibri", alignment=TA_CENTER)
        pc = plat.Paragraph("Algorithm Test Results", ps)
        # pr = Paragraph(self._headerInfo[4], ps)
        tf = plat.Table([[pl, pc]], [4.2 * cm, 20.9 * cm], ident="topTable")
        tf.setStyle(plat.TableStyle([('INNERGRID', (0, 0), (-1, -1), 0.25, colors.black),
                                    ('BOX', (0, 0), (-1, -1), 0.25, colors.black),
                                    ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
                                    ('VALIGN', (0, 0), (-1, -1), 'MIDDLE'), ]))
        tf.wrapOn(canv, 10 * cm, hh)
        tf.drawOn(canv, doc.leftMargin, self.GLOB_PAGE_WIDTH + 3.5 * cm)
        canv.restoreState()


class AlgoTestDocTemplate(dtp.BaseDocTemplate):

    def __init__(self, style, filepath):
        dtp.BaseDocTemplate.__init__(self, filepath)
        self._style = style
        self._maxTextWidth = 70
        self._lastnumPages = 2
        self.numPages = 1

        self.addPageTemplates([TitlePageTemplate(self), PortraitPageTemplate(self), LandscapePageTemplate(self)])

    def afterFlowable(self, flowable):
        self.numPages = max(self.canv.getPageNumber(), self.numPages)

        "Registers TOC entries."
        if flowable.__class__.__name__ == 'Paragraph':
            text = flowable.getPlainText()
            style = flowable.style.name
            if style == 'Heading1':
                key = 'h1-%s' % self.seq.nextf('heading1')
                self.canv.bookmarkPage(key)
                self.notify('TOCEntry', (0, text, self.page, key))
                self.canv.addOutlineEntry(text, key, 0)
            elif style == 'Heading2':
                key = 'h2-%s' % self.seq.nextf('heading2')
                self.canv.bookmarkPage(key)
                self.notify('TOCEntry', (1, text, self.page, key))
                self.canv.addOutlineEntry(text, key, 1)
            elif style == 'Heading3':
                key = 'h3-%s' % self.seq.nextf('heading3')
                self.canv.bookmarkPage(key)
                self.notify('TOCEntry', (2, text, self.page, key))
                self.canv.addOutlineEntry(text, key, 2)
            elif style == 'TableTitleStyle':
                key = 't-%s' % self.seq.nextf('tabletitlestyle')
                self.canv.bookmarkPage(key)
                self.notify('TOTable', (1, text, self.page, key))
                self.canv.addOutlineEntry(text, key, 1)
            elif style == 'FigureTitleStyle':
                key = 'f-%s' % self.seq.nextf('figuretitlestyle')
                self.canv.bookmarkPage(key)
                self.notify('TOFigure', (1, text, self.page, key))
                self.canv.addOutlineEntry(text, key, 1)

    def BuildPageIndexString(self):
        """Return page index string for the footer."""
        if self.page < self.numPages:
            self._lastnumPages += 1

        return 'page %(current_page)d of %(total_pages)d' % {'current_page': self.page, 'total_pages': self.numPages}


"""
CHANGE LOG:
-----------
$Log: template.py  $
Revision 1.1 2021/12/13 17:59:27CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/pdf/algo_test/project.pj
Revision 1.3 2013/10/25 09:02:35CEST Hecker, Robert (heckerr) 
Removed Pep8 Issues.
- Added comments -  heckerr [Oct 25, 2013 9:02:35 AM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.2 2013/10/21 08:44:24CEST Hecker, Robert (heckerr)
updated doxygen description.
--- Added comments ---  heckerr [Oct 21, 2013 8:44:24 AM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.1 2013/10/18 17:45:13CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/rep/pdf/algo_test/project.pj
"""
