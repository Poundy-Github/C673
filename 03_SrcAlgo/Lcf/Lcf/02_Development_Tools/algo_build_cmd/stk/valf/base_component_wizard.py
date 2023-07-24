"""
stk/valf/base_component_wizard
------------------------------

The component for creating plug-ins templates

:org:           Continental AG
:author:        Sorin Mogos

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:59:51CET $
"""
# Import Python Modules -----------------------------------------------------------------------------------------------
import wx
import wx.wizard as wizmod
import os.path
import win32api

# Import STK Modules --------------------------------------------------------------------------------------------------

# Defines -------------------------------------------------------------------------------------------------------------
PADDING = 5

# Functions -----------------------------------------------------------------------------------------------------------

# Classes -------------------------------------------------------------------------------------------------------------


class PluginPage(wizmod.PyWizardPage):
    ''' An extended panel obj with a few methods to keep track of its siblings.
        This should be modified and added to the wizard.  Season to taste.'''
    def __init__(self, parent):
        wx.wizard.PyWizardPage.__init__(self, parent)
        self.next = self.prev = None
        self._vbox = wx.BoxSizer(wx.VERTICAL)
        self._hbox = wx.BoxSizer(wx.HORIZONTAL)

        tmp = u"Please select a name for the new project and choose a "
        tmp += "folder\nwhere you want the new project to be created."
        self._static_text_title = wx.StaticText(self, -1, tmp, wx.DefaultPosition, wx.DefaultSize, 0)
        self._vbox.AddWindow(self._static_text_title, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        self._static_text_project_name = wx.StaticText(self, -1, u"Plug-in File Name:",
                                                       wx.DefaultPosition, wx.DefaultSize, 0)
        self._vbox.AddWindow(self._static_text_project_name, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)
        self._plugin_name = wx.TextCtrl(self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.Size(300, -1))
        self._vbox.AddWindow(self._plugin_name, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        self._static_text_class_name = wx.StaticText(self, -1, u"Plug-in Class Name:",
                                                     wx.DefaultPosition, wx.DefaultSize, 0)
        self._vbox.AddWindow(self._static_text_class_name, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)
        self._plugin_class_name = wx.TextCtrl(self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.Size(300, -1))
        self._vbox.AddWindow(self._plugin_class_name, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        self._static_text_description = wx.StaticText(self, -1, u"Plugin Description:",
                                                      wx.DefaultPosition, wx.DefaultSize, 0)
        self._vbox.AddWindow(self._static_text_description, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)
        self._plugin_description = wx.TextCtrl(self, wx.ID_ANY, wx.EmptyString, wx.DefaultPosition, wx.Size(300, -1))
        self._vbox.AddWindow(self._plugin_description, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        self._static_project_folder = wx.StaticText(self, -1, u"Plug-in Folder:",
                                                    wx.DefaultPosition, wx.DefaultSize, 0)
        self._vbox.AddWindow(self._static_project_folder, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)
        self._vbox.AddWindow(self._hbox)
        self._plugin_folder = wx.TextCtrl(self, -1, wx.EmptyString,
                                          wx.DefaultPosition, wx.Size(220, -1), wx.TE_READONLY)
        self._hbox.AddWindow(self._plugin_folder, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)
        self._hbox.AddSpacer((2, 2), 0, wx.ALIGN_LEFT | wx.ALL, -1)
        self.button_dir_picker = wx.Button(self, -1, u"...", wx.DefaultPosition, wx.Size(35, -1), 0)
        self.button_dir_picker.SetDefault()
        self._hbox.AddWindow(self.button_dir_picker, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        self.SetSizer(self._vbox)

        self.button_dir_picker.Bind(wx.EVT_BUTTON, self.OnButtonChoosePluginDir)

    def OnButtonChoosePluginDir(self, event):
        """ Create an open file dialog"""
        dialog = wx.DirDialog(None, style=wx.OPEN)

        # Show the dialog and get user input
        if dialog.ShowModal() == wx.ID_OK:
            self._plugin_folder.SetValue(dialog.GetPath())
        else:
            wx.LogMessage("No 'Plugin' directory selected.")

        # Destroy the dialog
        dialog.Destroy()

    def get_plugin_file_name(self):
        """ return plugin name"""
        return self._plugin_name.GetValue()

    def get_plugin_class_name(self):
        """return class name"""
        return self._plugin_class_name.GetValue()

    def get_plugin_description(self):
        """return description"""
        return self._plugin_description.GetValue()

    def get_plugin_folder(self):
        """return folder"""
        return self._plugin_folder.GetValue()

    def add_stuff(self, stuff):
        """Add aditional widgets to the bottom of the page"""
        self._sizer.Add(stuff, 0, wx.EXPAND | wx.ALL, PADDING)

    def SetNext(self, next):
        """Set the next page"""
        self.next = next

    def SetPrev(self, prev):
        """Set the previous page"""
        self.prev = prev

    def GetNext(self):
        """Return the next page"""
        return self.next

    def GetPrev(self):
        """Return the previous page"""
        return self.prev


class LibraryPage(wizmod.PyWizardPage):
    """ An extended panel obj with a few methods to keep track of its siblings.
        This should be modified and added to the wizard.  Season to taste."""
    def __init__(self, parent, title):
        wx.wizard.PyWizardPage.__init__(self, parent)
        self.next = self.prev = None
        self._vbox = wx.BoxSizer(wx.VERTICAL)
        self._hbox1 = wx.BoxSizer(wx.HORIZONTAL)
        self._hbox2 = wx.BoxSizer(wx.HORIZONTAL)
        self.SetSizer(self._vbox)

        tmp = u"Please select the STK and VALF libraries path."

        self._static_text_title = wx.StaticText(self, -1, tmp, wx.DefaultPosition, wx.DefaultSize, 0)
        self._vbox.AddWindow(self._static_text_title, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        # STK Library
        self._static_text_project_name = wx.StaticText(self, -1, u"STK Library Path:",
                                                       wx.DefaultPosition, wx.DefaultSize, 0)
        self._vbox.AddWindow(self._static_text_project_name, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        self._vbox.AddWindow(self._hbox1)
        self._stk_path = wx.TextCtrl(self, -1, wx.EmptyString, wx.DefaultPosition, wx.Size(220, -1), wx.TE_READONLY)
        self._hbox1.AddWindow(self._stk_path, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)
        self._hbox1.AddSpacer((2, 2), 0, wx.ALIGN_LEFT | wx.ALL, -1)
        self.button_dir_picker1 = wx.Button(self, -1, u"...", wx.DefaultPosition, wx.Size(35, -1), 0)
        self.button_dir_picker1.SetDefault()
        self._hbox1.AddWindow(self.button_dir_picker1, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        # VALF library
        self._static_valf_path = wx.StaticText(self, -1, u"VALF Library Path:", wx.DefaultPosition, wx.DefaultSize, 0)
        self._vbox.AddWindow(self._static_valf_path, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)

        self._vbox.AddWindow(self._hbox2)
        self._valf_path = wx.TextCtrl(self, -1, wx.EmptyString, wx.DefaultPosition, wx.Size(220, -1), wx.TE_READONLY)
        self._hbox2.AddWindow(self._valf_path, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)
        self._hbox2.AddSpacer((2, 2), 0, wx.ALIGN_LEFT | wx.ALL, -1)
        self.button_dir_picker2 = wx.Button(self, -1, u"...", wx.DefaultPosition, wx.Size(35, -1), 0)
        self._hbox2.AddWindow(self.button_dir_picker2, 0, wx.ALIGN_LEFT | wx.ALL, PADDING)
        self.button_dir_picker2.SetDefault()

        self.button_dir_picker1.Bind(wx.EVT_BUTTON, self.OnButtonChooseStkDir)
        self.button_dir_picker2.Bind(wx.EVT_BUTTON, self.OnButtonChooseValfDir)

    def get_stk_folder_path(self):
        """return internal value"""
        return self._stk_path.GetValue()

    def get_valf_folder_path(self):
        """return internal value"""
        return self._valf_path.GetValue()

    def OnButtonChooseStkDir(self, event):
        """ Create an open file dialog"""
        dialog = wx.DirDialog(None, style=wx.OPEN)

        # Show the dialog and get user input
        if dialog.ShowModal() == wx.ID_OK:
            self._stk_path.SetValue(dialog.GetPath())

        # The user did not select anything
        else:
            wx.LogMessage("No 'STK' directory selected.")

        # Destroy the dialog
        dialog.Destroy()

    def OnButtonChooseValfDir(self, event):
        """select valf dir"""
        #wx.LogMessage(`self.GetChildren()`) #GetSizer().

        # Create an open file dialog
        dialog = wx.DirDialog(None, style=wx.OPEN)

        # Show the dialog and get user input
        if dialog.ShowModal() == wx.ID_OK:
            self._valf_path.SetValue(dialog.GetPath())
        # The user did not select anything
        else:
            wx.LogMessage("No 'VALF' directory selected.")

        # Destroy the dialog
        dialog.Destroy()

    def add_stuff(self, stuff):
        """Add aditional widgets to the bottom of the page'"""
        self._sizer.Add(stuff, 0, wx.EXPAND | wx.ALL, PADDING)

    def SetNext(self, next):
        """Set the next page"""
        self.next = next

    def SetPrev(self, prev):
        """Set the previous page"""
        self.prev = prev

    def GetNext(self):
        """Return the next page"""
        return self.next

    def GetPrev(self):
        """Return the previous page"""
        return self.prev


class VALFWizard(wx.wizard.Wizard):
    """Add pages to this wizard object to make it useful."""
    def __init__(self, title, img_filename=""):
        # img could be replaced by a py string of bytes
        if img_filename and os.path.exists(img_filename):
            img = wx.Bitmap(img_filename)
        else:
            img = wx.NullBitmap

        wx.wizard.Wizard.__init__(self, None, -1, title, img)

        self._pages = []

        # Lets catch the events
        #self.Bind(wizmod.EVT_WIZARD_PAGE_CHANGED, self.on_page_changed)
        #self.Bind(wizmod.EVT_WIZARD_PAGE_CHANGING, self.on_page_changing)
        #self.Bind(wizmod.EVT_WIZARD_CANCEL, self.on_cancel)
        self.Bind(wizmod.EVT_WIZARD_FINISHED, self.on_finished)

    def _write_plugin_header(self, file_obj):
        """write file header"""
        plugin_name = self._pages[0].get_plugin_file_name()
        if plugin_name.endswith(".py"):
            plugin_name = plugin_name[0:-3]

        file_obj.write('"""\n')
        file_obj.write("%s\n" % plugin_name)
        file_obj.write("-" * len(plugin_name))
        file_obj.write("\n\n")
        file_obj.write("%s\n" % self._pages[0].get_plugin_description())
        file_obj.write("\n")
        file_obj.write(":org:\t\tContinental AG\n")
        file_obj.write(":author:\t%s\n\n" % win32api.GetUserNameEx(2))
        file_obj.write(":version:\t$" + "Revision: $\n")
        file_obj.write(":contact:\t$" + "Author: %s $ (last change)\n" % os.environ["USERNAME"])
        file_obj.write(":date:\t\t$" + "Date:  $\n")
        file_obj.write('"""\n')

    def _write_plugin_imports(self, file_obj):
        """write imports to file"""
        try:
            stk_folder_path = self._pages[1].get_stk_folder_path()
        except:
            stk_folder_path = ""

        try:
            valf_folder_path = self._pages[1].get_valf_folder_path()
        except:
            valf_folder_path = ""

        file_obj.write("#" + "=" * 79)
        file_obj.write("\n")
        file_obj.write("# Imports\n")
        file_obj.write("#" + "=" * 79)
        file_obj.write("\n")
        import_module_list = ["os", "sys", "inspect"]
        for import_module in import_module_list:
            file_obj.write("import %s\n" % import_module)

        file_obj.write("\nfrom stk.valf.base_component_ifc import BaseComponentInterface\n\n")

        if len(valf_folder_path):
            file_obj.write("VALF_DIR = \"%s\"\n" % valf_folder_path)
        else:
            file_obj.write("VALF_DIR = os.path.dirname(os.path.abspath(inspect.currentframe().f_code.co_filename))\n")

        file_obj.write("if VALF_DIR not in sys.path:\n")
        file_obj.write("\tsys.path.append(VALF_DIR)\n\n")

        if len(stk_folder_path):
            file_obj.write("STK_LIB = \"%s\"\n" % stk_folder_path)
        else:
            file_obj.write("STK_LIB = os.path.join(VALF_DIR, \"..\", \"stk\")\n")

        file_obj.write("if STK_LIB not in sys.path:\n")
        file_obj.write("\tsys.path.append(STK_LIB)\n")

        file_obj.write("\nfrom stk.util.logger import Logger\n\n")

    def _write_plugin_class(self, file_obj):
        """finally write empty component class"""
        plugin_class_name = self._pages[0].get_plugin_class_name()

        file_obj.write("class %s(BaseComponentInterface):\n" % plugin_class_name)

        file_obj.write("\tdef __init__(self, data_manager, component_name, bus_name = [\"BUS_BASE\"]):\n")
        file_obj.write("\t\tself.__bus_name = bus_name[0]\n")
        file_obj.write("\t\tself.__component_name = component_name\n")
        file_obj.write("\t\tself.__data_manager = data_manager\n")
        file_obj.write("\t\tself.__logger = Logger(self.__component_name)\n\n")

        file_obj.write("\t\tself.__version = \"$" + "Revision:  $\"\n\n")

        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n\n")

        file_obj.write("\tdef Initialize(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n")
        file_obj.write("\n\t\t# Add your code here\n\n")
        file_obj.write("\t\treturn 0\n\n")

        file_obj.write("\tdef PostInitialize(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n")
        file_obj.write("\n\t\t# Add your code here\n\n")
        file_obj.write("\t\treturn 0\n\n")

        file_obj.write("\tdef LoadData(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n")
        file_obj.write("\n\t\t# Add your code here\n\n")
        file_obj.write("\t\treturn 0\n\n")

        file_obj.write("\tdef ProcessData(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n")
        file_obj.write("\n\t\t# Add your code here\n\n")
        file_obj.write("\t\treturn 0\n\n")

        file_obj.write("\tdef PostProcessData(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n")
        file_obj.write("\n\t\t# Add your code here\n\n")
        file_obj.write("\t\treturn 0\n\n")

        file_obj.write("\tdef PreTerminate(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n")
        file_obj.write("\n\t\t# Add your code here\n\n")
        file_obj.write("\t\treturn 0\n\n")

        file_obj.write("\tdef Terminate(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n")
        file_obj.write("\n\t\t# Add your code here\n\n")
        file_obj.write("\t\treturn 0\n\n")

        file_obj.write("\tdef GetComponentVersion(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n")
        file_obj.write("\t\trevision = self.__version.find(\"Revision: \")\n")
        file_obj.write("\t\tif revision > -1:\n")
        file_obj.write("\t\t\tversion = self.__version[revision + 10 :-2]\n")
        file_obj.write("\t\telse:\n")
        file_obj.write("\t\t\tversion = 0.0\n\n")

        file_obj.write("\t\treturn version\n\n")

        file_obj.write("\tdef GetComponentName(self):\n")
        file_obj.write("\t\tself.__logger.debug(str(sys._getframe().f_code.co_name) + \"()\" + \" called.\")\n\n")

        file_obj.write("\t\treturn self.__component_name\n\n")

    def _write_plugin_log(self, file_obj):
        """add log to bottom of page"""
        plugin_name = self._pages[0].get_plugin_file_name()
        if not plugin_name.endswith(".py"):
            plugin_name += ".py"

        file_obj.write("\"\"\"\n")
        file_obj.write("$" + "Log: %s $\n" % plugin_name)
        file_obj.write("\"\"\"\n")

    def _write_plugin_file(self):
        """write new file complete with header, imports, class and log"""
        plugin_path = self._pages[0].get_plugin_folder()
        plugin_file_name = self._pages[0].get_plugin_file_name()
        if not plugin_file_name.endswith(".py"):
            plugin_file_name += ".py"

        if not os.path.isdir(plugin_path) or not len(plugin_file_name):
            wx.LogMessage("Invalid plug-in path or name specified.")
            return False

        plugin_pathname = os.path.join(plugin_path, plugin_file_name)
        file_obj = None
        file_obj = open(plugin_pathname, 'w')
        if file_obj:
            self._write_plugin_header(file_obj)
            self._write_plugin_imports(file_obj)
            self._write_plugin_class(file_obj)
            self._write_plugin_log(file_obj)

            file_obj.close()

        if os.path.isfile(plugin_pathname):
            wx.LogMessage("Plug-in has been successfully generated as: '%s'." % plugin_pathname)

    def add_page(self, page):
        """Add a wizard page to the list."""
        if self._pages:
            previous_page = self._pages[-1]
            page.SetPrev(previous_page)
            previous_page.SetNext(page)

        self._pages.append(page)

    def run(self):
        """start wizard"""
        self.RunWizard(self._pages[0])

#    def on_page_changed(self, evt):
#        'Executed after the page has changed.'
#        if evt.GetDirection():
#            dir = "forward"
#        else:
#            dir = "backward"
#
#        page = evt.GetPage()
#        print "page_changed: %s, %s\n" % (dir, page.__class__)
#
#    def on_page_changing(self, evt):
#        'Executed before the page changes, so we might veto it.'
#        if evt.GetDirection():  dir = "forward"
#        else:                   dir = "backward"
#        page = evt.GetPage()
#        print "page_changing: %s, %s\n" % (dir, page.__class__)
#
#    def on_cancel(self, evt):
#        'Cancel button has been pressed.  Clean up and exit without continuing.'
#        #page = evt.GetPage()
#        #print "on_cancel: %s\n" % page.__class__
#
#        # Prevent cancelling of the wizard.
#        #if page is self.pages[0]:
#        #    wx.MessageBox("Cancelling on the first page has been prevented.", "Sorry")
#        #    evt.Veto()

    def on_finished(self, evt):
        self._write_plugin_file()

if __name__ == '__main__':

    app = wx.PySimpleApp()  # Start the application

    # Create wizard and add any kind pages you'd like
    valf_wizard = VALFWizard('::. VALF Wizard', img_filename='wiz.png')
    plugin_page = PluginPage(valf_wizard)  # Create a first page
    valf_wizard.add_page(plugin_page)
    #valf_wizard.add_page(LibraryPage(valf_wizard))

    valf_wizard.run()  # Show the main window

    # Cleanup
    valf_wizard.Destroy()
    app.MainLoop()

"""
$Log: base_component_wizard.py  $
Revision 1.1 2021/12/13 17:59:51CET Wang, David (Wangd3) 
Initial revision
Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/algo_build_cmd/stk/valf/project.pj
Revision 1.6 2013/04/19 18:31:12CEST Hospes, Gerd-Joachim (uidv8815) 
adapted to stk 2.0, pep8 and some pylint warnings fixed
- Added comments -  uidv8815 [Apr 19, 2013 6:31:12 PM CEST]
Change Package : 169590:1 http://mks-psad:7002/im/viewissue?selection=169590
Revision 1.5 2013/03/21 17:27:59CET Mertens, Sven (uidv7805) 
solving minor pylint error issues
--- Added comments ---  uidv7805 [Mar 21, 2013 5:28:00 PM CET]
Change Package : 178224:1 http://mks-psad:7002/im/viewissue?selection=178224
Revision 1.4 2013/03/01 10:23:20CET Hecker, Robert (heckerr)
Updates regarding Pep8 Styleguides.
--- Added comments ---  heckerr [Mar 1, 2013 10:23:20 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.3 2013/02/27 16:20:02CET Hecker, Robert (heckerr)
Updates regarding Pep8 StyleGuide (partly).
--- Added comments ---  heckerr [Feb 27, 2013 4:20:02 PM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.2 2013/02/20 08:21:24CET Hecker, Robert (heckerr)
Adapted to Pep8 Coding Style.
--- Added comments ---  heckerr [Feb 20, 2013 8:21:25 AM CET]
Change Package : 168499:1 http://mks-psad:7002/im/viewissue?selection=168499
Revision 1.1 2013/02/11 11:06:04CET Raedler, Guenther (uidt9430)
Initial revision
Member added to project /nfs/projekte1/REPOSITORY/Base_Development/
05_Algorithm/STK_ScriptingToolKit/04_Engineering/stk/valf/project.pj
------------------------------------------------------------------------------
-- From etk/valf Archive
------------------------------------------------------------------------------
Revision 1.6 2012/08/22 09:36:51CEST Mogos, Sorin (mogoss)
* update: replaced os.getenv["USERNAME"] by win32api.win32api.GetUserNameEx()
--- Added comments ---  mogoss [Aug 22, 2012 9:36:54 AM CEST]
Change Package : 155168:1 http://mks-psad:7002/im/viewissue?selection=155168
Revision 1.5 2012/07/25 16:17:34CEST Mogos, Sorin (mogoss)
* code improvements
Revision 1.4 2012/07/25 16:10:57CEST Mogos, Sorin (mogoss)
* bug-fix
--- Added comments ---  mogoss [Jul 25, 2012 4:10:58 PM CEST]
Change Package : 134013:1 http://mks-psad:7002/im/viewissue?selection=134013
Revision 1.3 2012/07/25 15:28:08CEST Mogos, Sorin (mogoss)
* bug-fix
Revision 1.2 2012/07/25 12:13:50CEST Mogos, Sorin (mogoss)
* update: added versioning info
--- Added comments ---  mogoss [Jul 25, 2012 12:13:50 PM CEST]
Change Package : 134013:1 http://mks-psad:7002/im/viewissue?selection=134013
"""
