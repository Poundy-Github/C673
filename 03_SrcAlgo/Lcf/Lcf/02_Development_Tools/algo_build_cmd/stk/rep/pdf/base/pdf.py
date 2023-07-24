"""
stk/rep/pdf/base/pdf
--------------------

**Module for writing basic pdf Reports.**

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:32CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
from reportlab.lib.units import cm
import reportlab.platypus as plat
import reportlab.platypus.doctemplate as dtp

# Import STK Modules --------------------------------------------------------------------------------------------------
from . import flowables as flow
from . import template as template

# Defines -------------------------------------------------------------------------------------------------------------
PAGE_TEMPLATE_PORTRAIT = template.PAGE_TEMPLATE_PORTRAIT
PAGE_TEMPLATE_LANDSCAPE = template.PAGE_TEMPLATE_LANDSCAPE

# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class Story(object):
    """
    **Wrapper class around the story list container.**

    This container collects the whole pdf-story which will be rendered at a later point of time.

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self, style):
        self._story = []
        self.style = style
        self.styles = style.styles

    def __GetStory(self):
        return self._story

    def __SetStory(self, value):
        self._story = value

    story = property(__GetStory, __SetStory)
    """
    Internal story, which will be stored for later usage.

    :type: list of pdf/helper objects.
    """

    def AddParagraph(self, text):
        """
        Add a new Paragraph to the story.

        :param text: text, which must be added to the story.
        :type text:  string
        :return:         -
        """
        self._story.append(plat.Paragraph(text, self.styles["Normal"]))

    def AddPageBreak(self):
        """
        Add a new PageBreak to the story.

        :return:         -
        """
        self._story.append(plat.PageBreak())

    def AddSpace(self, space):
        """
        Add a Space for the next Item to the story.

        :param space: wanted space in cm.
        :type space:  float
        :return:      -
        """
        self._story.append(plat.Spacer(1, space * cm))

    def AddTable(self, name, data, **kwarg):
        """
        Add a Space for the next Item to the story.

        :param name:       Name of table
        :type name:        string
        :param data:       values of the table
        :type data:        list[list[string]]
        :Param kwarg:      list of optional parameters
        :kwarg header:     separate headerline in standard format
        :type header:      list[strings]
        :kwarg colWidths:  specify the column With of every column
        :type colWidths:   list[float]
        :kwarg topHeader:  Used to specify a background for the header line
        :type topHeader:   `True` when header should have background colour grey.
        :return:           -
        """
        table = flow.Table(name, data, **kwarg)

        self._story.append(table)

    def AddImage(self, name, image, **kwarg):
        """
        Add a Image to the story.
        This method can append following images to the story:
        - Images given via file path (e.g.: c:/test.jpeg)
        - Images given as platypus.Image

        :param name:    name or description to be added below the image
        :type name:     string
        :param image:   The image itself.
        :type image:    path (string) or platypus.Image
        :Param kwarg:   list of optional parameters
        :kwarg width:   width of image. (e.g. width=(15 * cm))
                        if width is specified aspect ratio will be keept.
                        width will only work, if image parameter is a path to a file.
        :type width:    float
        """
        # Create Own Image Container for the Image
        img = flow.Image(name, image, **kwarg)

        # Append Image Container to the story.
        self._story.append(img)

    def AddHeading(self, heading, level):
        """
        Add a new Heading to the story.

        :param heading:  the heading name which shall be printed.
        :type heading:   string
        :param level:    The level of the heading.
        :type level:     integer [0,1,2]
        """
        head = flow.Heading(heading, level)
        self._story.append(head)

    def ChangePageTemplate(self, template):
        """
        This Method is used to switch between different supported PageTemplates.

        Valid Templates are:

        - 'PAGE_TEMPLATE_PORTRAIT'
        - 'PAGE_TEMPLATE_LANDSCAPE'

        :param template: The Template which must be used for the next Page.
        :type template:  integer
        :return:         -
        """
        # Check if we get a valid template
        if((template == PAGE_TEMPLATE_PORTRAIT) or
           (template == PAGE_TEMPLATE_LANDSCAPE)):
            # Set the Template
            self._story.append(dtp.NextPageTemplate(template))

    def _PreBuild(self):
        """
        This Method is used to go through the whole story, and prepare
        the numeration for Headings, Tables and figures.

        :return:   story ready for a doc build.
        :rtype:    story (Paragraph object formatted in the correct way.)
        """
        # Initialize the new Story
        story = []
        # Reset all Counters for the "new" story
        flow.Numeration()._Reset()

        for item in self._story:
            if(isinstance(item, flow.Numeration) is True):
                # Do the final Creation of the story object here.
                story += item._Create()
            else:
                story.append(item)

        return story

    def Append(self, story):
        self._story.append(story)


class Pdf(Story):
    """
    **This is the main Interface for creating a pdf-document.**

    Use this class to create simple pdf - documents.
    Use this class as an example how following elements are connected together

    - Pdf class
    - Story
    - BaseDocTemmplates
    - PageTemplates
    - Helper classes like Numeration, Image, Heading, Table,......

    **Example:**

    .. python::

        # Import stk.hpc
        import stk.io.pdf as pdf

        # Create a instance of the Pdf class.
        doc = pdf.Pdf()

        # Write Something into the pdf
        doc.AddParagraph("Hello World")

        # Render pdf story to file
        doc.Build('out.pdf')

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self):
        self.style = template.Style()
        Story.__init__(self, self.style)
        self._doc = None

    def Build(self, filepath):
        """
        Build the final *.pdf document including following steps:

        - Creating a Template.
        - Prebuilding of the internal Story (assign of numerations)
        - Rendering of the document.

        :param filepath: whole path of the file which must be created.
        :type filepath:  sting
        :return:         -

        :author:         Robert Hecker
        :date:           22.09.2013
        """
        # Create a Instance of our Template Document class, which is needed to create our Document
        self._doc = template.PdfDocTemplate(self.style, filepath)

        # First go through the whole story, and Format the story in the wanted way.
        story = self._PreBuild()

        # Do the final Creation of the pdf Docu rendering....
        self._doc.multiBuild(story)


"""
CHANGE LOG:
-----------
$Log: pdf.py  $
Revision 1.1 2021/12/13 17:59:32CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/pdf/base/project.pj
Revision 1.4 2013/10/25 09:02:36CEST Hecker, Robert (heckerr) 
Removed Pep8 Issues.
- Added comments -  heckerr [Oct 25, 2013 9:02:36 AM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.3 2013/10/21 15:03:34CEST Hecker, Robert (heckerr)
Added the Append command;
updated epydoc.
--- Added comments ---  heckerr [Oct 21, 2013 3:03:34 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.2 2013/10/18 17:20:28CEST Hecker, Robert (heckerr)
Get AddImage and AddTable working.
--- Added comments ---  heckerr [Oct 18, 2013 5:20:28 PM CEST]
Change Package : 106870:1 http://mks-psad:7002/im/viewissue?selection=106870
Revision 1.1 2013/10/18 09:22:13CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/rep/pdf/base/project.pj
"""
