"""
stk/rep/pdf/base/template.py
----------------------------

Template Module for pdf Reports

Module which contains the needed interfaces to:

**Internal-API Interfaces**

    - `Style`
    - `PortraitPageTemplate`
    - `LandscapePageTemplate`
    - `PdfDocTemplate`

**User-API Interfaces**

    - `stk.rep` (complete package)

:org:           Continental AG
:author:        Robert Hecker

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:32CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
import reportlab.platypus.doctemplate as dtp
from reportlab.lib.styles import getSampleStyleSheet

# Import STK Modules --------------------------------------------------------------------------------------------------

# Defines -------------------------------------------------------------------------------------------------------------
PAGE_TEMPLATE_PORTRAIT = 'portrait'
PAGE_TEMPLATE_LANDSCAPE = 'landscape'

# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class Style(object):
    def __init__(self):
        self._styles = getSampleStyleSheet()

        self.header = None

    @property
    def styles(self):
        return self._styles


class PortraitPageTemplate(dtp.PageTemplate):
    """
    **Page Template for basic Pages in portrait orientation.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    ID = PAGE_TEMPLATE_PORTRAIT

    def __init__(self, doctemplate):
        self.frames = [dtp.Frame(doctemplate.leftMargin, doctemplate.bottomMargin,  # pylint: disable=E1101
                                 doctemplate.width, doctemplate.height, id='F0')]  # pylint: disable=E1101
        dtp.PageTemplate.__init__(self, self.ID, self.frames, onPage=self.OnPage, pagesize=doctemplate.pagesize)

    def OnPage(self, canv, doc):
        """
        Callback Method, which will be called during the rendering process, to draw on every page
        identical items, like header of footers.
        """
        pass


class LandscapePageTemplate(dtp.PageTemplate):
    """
    **Page Template for basic Pages in landscape orientation.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    ID = PAGE_TEMPLATE_LANDSCAPE

    def __init__(self, doctemplate):
        self.frames = [dtp.Frame(doctemplate.leftMargin, doctemplate.bottomMargin,  # pylint: disable=E1101
                                 doctemplate.width, doctemplate.height, id='F0')]  # pylint: disable=E1101
        dtp.PageTemplate.__init__(self, self.ID, self.frames, onPage=self.OnPage,
                                  pagesize=(doctemplate.pagesize[1], doctemplate.pagesize[0]))

    def OnPage(self, canv, doc):
        """
        Callback Method, which will be called during the rendering process, to draw on every page
        identical items, like header of footers.
        """
        pass


class PdfDocTemplate(dtp.BaseDocTemplate):  # pylint: disable=R0904
    """
    **Document Template for basic pdf document.**

    :author:        Robert Hecker
    :date:          22.09.2013
    """
    def __init__(self, style, filepath):
        dtp.BaseDocTemplate.__init__(self, filepath)
        self._style = style

        self.addPageTemplates([PortraitPageTemplate(self), LandscapePageTemplate(self)])


"""
CHANGE LOG:
-----------
$Log: template.py  $
Revision 1.1 2021/12/13 17:59:32CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/rep/pdf/base/project.pj
Revision 1.2 2013/10/25 09:02:34CEST Hecker, Robert (heckerr) 
Removed Pep8 Issues.
- Added comments -  heckerr [Oct 25, 2013 9:02:35 AM CEST]
Change Package : 202843:1 http://mks-psad:7002/im/viewissue?selection=202843
Revision 1.1 2013/10/18 09:22:14CEST Hecker, Robert (heckerr)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/
STK_ScriptingToolKit/04_Engineering/stk/rep/pdf/base/project.pj
"""
