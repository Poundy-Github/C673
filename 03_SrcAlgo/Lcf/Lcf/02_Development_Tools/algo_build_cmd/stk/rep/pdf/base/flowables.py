"""
stk/rep/pdf/base/flowables
--------------------------

layout Module for pdf Reports

Module which contains the needed interfaces to:

**Internal-API Interfaces**

    - `Numeration`
    - `TableBase`

**User-API Interfaces**

    - `Table` (this module)
    - `Image` (this module)
    - `Heading` (this module)
    - `stk.rep` (complete package)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:32CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
import os
import reportlab.platypus as plat
from reportlab.lib.styles import ParagraphStyle
from reportlab.lib.units import cm
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.lib import colors
from reportlab.lib import utils

# Import STK Modules --------------------------------------------------------------------------------------------------

# Defines -------------------------------------------------------------------------------------------------------------

# Functions -----------------------------------------------------------------------------------------------------------


def ReplaceHTMLChars(text):
    """
    Replace HTML Characters, e.g. needed for Paragraphs
    """
    return text.replace('&', '&amp').replace('<', '&lt').replace('>', '&gt')

# Classes -------------------------------------------------------------------------------------------------------------


class Numeration(object):  # pylint: disable=R0903
    """
    **Basic Numeration class which manages all continuos number items in a normal or merged pdf document.**

    Other story objects which need to have a numeration inside the report must be dervited from this class.

    Currently followng classes are depending on Numeration:

    - `Heading`
    - `Image`
    - `Heading`

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    _section = [0, 0, 0]
    _fig_num = 1
    _table_num = 1
    _last_level = 0

    def __init__(self):
        pass

    def _Reset(self):  # pylint: disable=R0201
        """
        Possibility to Reset all internal numeration counters.

        :return:         -
        """
        Numeration._section = [0, 0, 0]
        Numeration._fig_num = 1
        Numeration._table_num = 1
        Numeration._last_evel = 0

    def _BuildSectionNumberString(self, level):
        """
        Build a numeration string for a current heading
        with a given level.

        :param level: Defines the Heading level
        :type level:  integer
        :return:      NumerationString (e.g. '1.1.2')
        :rtype:       string
        """
        number_str = ""

        # Remember the level for later usage
        Numeration._last_level = level

        # Increase the correct level-number
        self._section[level] += 1

        # And Reset More detailed Level numbers
        if(level == 1):
            self._section[2] = 0

        if(level == 0):
            self._section[1] = 0
            self._section[2] = 0

        for idx in xrange(0, level + 1):
            number_str = number_str + ("%d" % self._section[idx])
            if(idx < level):
                number_str = number_str + '.'

        return number_str

    def _BuildFigureNumberString(self):
        """
        Build a numeration string for the current figure.

        :return:      NumerationString (e.g. '1.1.2')
        :rtype:       string
        """
        number_str = ""

        # Build First the normal Section Number String.
        for idx in xrange(0, self._last_level + 1):
            number_str = number_str + ("%d" % self._section[idx])
            if(idx < self._last_level):
                number_str = number_str + '.'

        # Append now the Figure Number
        number_str += ".%d" % self._fig_num

        Numeration._fig_num += 1

        return number_str

    def _BuildTableNumberString(self):
        """
        Build a numeration string for the current Table.

        :return:      NumerationString (e.g. '1.1.2')
        :rtype:       string
        """
        number_str = ""

        # Build First the normal Section Number String.
        for idx in xrange(0, self._last_level + 1):
            number_str = number_str + ("%d" % self._section[idx])
            if(idx < self._last_level):
                number_str = number_str + '.'

        # Append now the Table Number
        number_str += ".%d" % self._table_num

        self._table_num += 1

        return number_str


class TableBase(Numeration):
    """
    **Basic Table with integrated Numeration possibility.**

    This Table must be used for all other Table classes as parent class.

    :author:        Robert Hecker
    :date:          09.10.2013
    """
    TABLE_CAPTION = "Table"
    STYLE = ParagraphStyle(name='TableTitleStyle', fontName="Times-Roman", fontSize=10, leading=12)

    def __init__(self):
        Numeration.__init__(self)
        self._name = ""

    def AppendCaption(self, story):

        if self._name is not None:
            tp = plat.Paragraph("<b>%s %s</b>: %s" % (self.TABLE_CAPTION, self._BuildTableNumberString(),
                                                      ReplaceHTMLChars(self._name)), self.STYLE)
            tp.keepWithNext = True
            story.append(tp)


class Table(TableBase):  # pylint: disable=R0903
    """
    **Basic Table with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self, name, data, **kwargs):
        TableBase.__init__(self)
        self._name = name
        self._data = data

        self._kwargs = kwargs

        # Process all kwargs and add some default settings if necessary
        style = kwargs.pop('style', [])
        if "GRID" not in [i[0] for i in style]:
            style.append(('GRID', (0, 0), (-1, -1), 1.0, colors.black))
        if kwargs.pop('topHeader', True):
            style.insert(0, ('BACKGROUND', (0, 0), (-1, 0), colors.lavender))
        self._kwargs['style'] = style

        self._header = kwargs.pop('header', None)
        self._styles = getSampleStyleSheet()

    def __BuildTableHeader(self):
        """
        Create the Table Header Paragraph object.

        :return: ReportLab table header
        :rtype:  list[Paragraph]
        """

        header = []

        if(type(self._header[0]) == str):
            for col_name in self._header:
                header.append(plat.Paragraph("<b>%s</b>" % col_name, self._styles["Normal"]))
        else:
            header = self._header

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
        data = []

        if(self._header is not None):
            data.append(self.__BuildTableHeader())

        data += self._data

        table = plat.Table(data, repeatRows=1, **self._kwargs)

        self.AppendCaption(story)

        story.append(table)
        story.append(plat.Spacer(1, 1 * cm))

        return story


class Image(Numeration):  # pylint: disable=R0903
    """
    **Basic Image with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    FIGURE_CAPTION = "Fig."
    STYLE = ParagraphStyle(name='FigureTitleStyle', fontName="Times-Roman", fontSize=10, leading=12)

    def __init__(self, name, image, **kwargs):
        Numeration.__init__(self)
        self._name = name
        self._image = image
        self._width = kwargs.pop('width', (15 * cm))

    def _Create(self):
        """
        Does the final creation of the Platypus Image object.
        Including a correct numeration for the Figures list.

        Typically this Method will be called by the _PreBuild-Method of
        the Story class.

        :return: story with all final objects for pdf rendering
        :rtype: list of platypus objects ready for rendering.
        """
        story = []

        # Check if image is stored on disk
        if(type(self._image) != plat.Image) and (type(self._image) == str) and (os.path.isfile(self._image)):
            # Create a Platypus Image from the given image path
            im = utils.ImageReader(self._image)
            iw, ih = im.getSize()
            aspect = ih / float(iw)
            img = plat.Image(self._image, width=self._width, height=(self._width * aspect))
        else:
            img = self._image

        # Add Image
        flowables = [plat.Spacer(1, 1 * cm), img]

        # Add Title
        if self._name is not None:
            flowables.append(plat.Paragraph("<b>%s %s</b>: %s" %
                                           (self.FIGURE_CAPTION, self._BuildFigureNumberString(),
                                            ReplaceHTMLChars(self._name)), self.STYLE))
            flowables.append(plat.Spacer(1, 1 * cm))

        # Add everything to story
        story.append(plat.KeepTogether(flowables))

        return story


class Heading(Numeration):  # pylint: disable=R0902, R0903
    """
    **Basic Headings with integrated Numeration possibility.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self, heading="", level=0):
        Numeration.__init__(self)
        self.heading = heading
        self.level = level

        self.header = [ParagraphStyle(name='Heading1', fontSize=16, fontName="Times-Bold", leading=22),
                       ParagraphStyle(name='Heading2', fontSize=14, fontName="Times-Roman", leading=18),
                       ParagraphStyle(name='Heading3', fontSize=12, fontName="Times-Roman", leading=12)]

        self.notoc_h1 = ParagraphStyle(name='NoTOCHeading1', fontSize=16, fontName="Times-Bold", leading=22)
        self.toc_h1 = ParagraphStyle(name='Heading1', fontSize=14, fontName="Times-Bold", leftIndent=6)
        self.notoc_h2 = ParagraphStyle(name='NoTOCHeading2', fontSize=14, fontName="Times-Roman", leading=18)
        self.toc_h2 = ParagraphStyle(name='Heading2', fontSize=12, fontName="Times-Roman", leftIndent=12)
        self.notoc_h3 = ParagraphStyle(name='NoTOCHeading3', fontSize=12, fontName="Times-Roman", leading=12)
        self.toc_h3 = ParagraphStyle(name='Heading3', fontSize=11, fontName="Times-Roman", leftIndent=32)

    def _Create(self):
        """
        Does the final creation of the Platypus Heading object.
        Including a correct numeration for the headings.

        Typically this Method will be called by the _PreBuild-Method of
        the Story class.

        :return: story with all final objects for pdf rendering
        :rtype: list of platypus objects ready for rendering.
        """
        story = []

        # if pageBreak:
        #    self._story.append(PageBreak())

        if self.level > 0:
            story.append(plat.Spacer(1, 1.5 * cm))

        # Get Current Section Number
        num = self._BuildSectionNumberString(self.level)

        story.append(plat.Paragraph(num + " " + self.heading, self.header[self.level]))

        return story


"""
CHANGE LOG:
-----------
$Log: flowables.py  $
Revision 1.1 2021/12/13 17:59:32CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/pdf/base/project.pj
Revision 1.3 2013/10/25 09:02:29CEST Hecker, Robert (heckerr) 
Removed Pep8 Issues.
- Added comments -  heckerr [Oct 25, 2013 9:02:30 AM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.2 2013/10/18 17:21:43CEST Hecker, Robert (heckerr)
Get Image class and Table class working.
--- Added comments ---  heckerr [Oct 18, 2013 5:21:43 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.1 2013/10/18 09:22:13CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/rep/pdf/base/project.pj
"""
