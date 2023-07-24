try:
# python 2
    import Tkinter as tk
    import tkMessageBox as tkinter_messagebox
    from Tkinter import W
except ImportError:
# python 3
    import tkinter as tk
    import tkinter.messagebox as tkinter_messagebox
    from tkinter.constants import W

from InstrGeneratorBase  import InstrGenBase
from TaskCfgUserDialog   import TaskConfigurator
from RunnableGroup       import RunnableGroup

##################################################################################################################################################################
#
################################################################################################################################################################
class RunnableGroupsConfigurator(InstrGenBase):

  ################################################################################################################################################################
  def __init__(self, userDialog, runnableGroupsCfgList):

    self.cfgWindowOpen          = False
    self.confirmWindowOpen      = False
    self.addNewGroupWindowOpen  = False

    self.userDialog                 = userDialog
    self.runnableGroupsCfgList      = runnableGroupsCfgList
    self.runnableGroupObjectList    = []




  ################################################################################################################################################################
  def drawRunnableGroupCfgButton(self, parentWindow, row):

    button = tk.Button(parentWindow, text = 'RunnableGroupsConfiguration', command = self.RunnableGroupsCfgUserDialog)
    button.grid(row = row, columnspan = 6, sticky = W, pady = 20)

    self.newGroupPrefix = tk.StringVar() #For the textField to add a new runnableGroup


  ################################################################################################################################################################
  def RunnableGroupsCfgUserDialog(self):

    if TaskConfigurator.noOpenTaskCfgWindows:
      #At least one taskConfigurationWindow is open
      #Generate infoWindow
      tkinter_messagebox.showinfo("Information", 'Please close all open taskConfigurationWindows first!!')

    elif not self.cfgWindowOpen:
      #First set the windowOpenFlag
      self.cfgWindowOpen = True

      #Check if we have already objects in the list
      if not len(self.runnableGroupObjectList):
        #The list is empty, create the runnableGroupsObjects based on the configuration in the configFile
        for runnableGroupCfg in self.runnableGroupsCfgList:
          self.runnableGroupObjectList.append(RunnableGroup(runnableGroupCfg, self))

      #Have the configuration window drawn
      self.DrawRunnableGroupsCfgWindow()


  ################################################################################################################################################################
  def DrawRunnableGroupsCfgWindow(self):

      #Generate a new Toplevel-Window
      self.top = tk.Toplevel()
      self.top.title('The runnableGroup configuration')
      self.top.minsize(400,100)
      self.top.maxsize(800,800)

      rowCnt = 0

      AddNewRunnableGroup = tk.Button(self.top, text = 'Add new runnable group', command = self.fctAddNewRunnableGroup)
      AddNewRunnableGroup.grid(row = rowCnt, pady = 10, padx = 4, sticky = 'news')
      rowCnt += 1

      #Create a frame for the canvas to be scrolled
      canvasFrame = tk.Frame(self.top)
      canvasFrame.grid(row = rowCnt,  columnspan = 4, sticky= 'nw')
      canvasFrame.grid_rowconfigure(0, weight=1)
      canvasFrame.grid_columnconfigure(0, weight=1)
      # Set grid_propagate to False to allow resizing later
      canvasFrame.grid_propagate(False)

      #create the canvas in the canvasFrame
      canvas = tk.Canvas(canvasFrame)
      canvas.grid(sticky = 'news')
      #Create the scrollbar in the canvasFrame
      scrollbar = tk.Scrollbar(canvasFrame, orient = 'vertical', command = canvas.yview)
      scrollbar.grid(row = 0, column = 1,sticky = 'ns')
      canvas.configure(yscrollcommand = scrollbar.set)
      #Create a frame to contain the checkButtons
      buttonFrame = tk.Frame(canvas)
      canvas.create_window((0, 0), window = buttonFrame, anchor='nw')

      #Draw all runnableGroups
      for i in range (len(self.runnableGroupObjectList)):
        self.runnableGroupObjectList[i].drawRunnableGroupEntry(buttonFrame, i)

      # Update buttons frames idle tasks to let tkinter calculate buttons sizes
      # This is needed to make bbox info available
      buttonFrame.update_idletasks()

      #Resize the canvasFrame
      canvasFrame.configure(height = min(500, buttonFrame.winfo_height()), width = buttonFrame.winfo_width() + scrollbar.winfo_width()+ 5)

      # Set the canvas scrolling region
      canvas.config(scrollregion = canvas.bbox("all"))

      rowCnt += 1

      OkButton = tk.Button(self.top, text = 'OK', command = self.fctRunnableGroupsCfgOkButton)
      OkButton.grid(row = rowCnt, ipadx = 10, pady = 10, padx = 4, sticky = 'news')


  ################################################################################################################################################################
  def fctRunnableGroupsCfgOkButton(self):
    if not self.confirmWindowOpen:
      #Update all taskConfigurators
      self.userDialog.updatetaskConfiguratorObjectsBasedOnUpdatedRunnableGroupsConfiguration()

      #Close the window and reset the flag preventing multipe opening of the window
      self.top.destroy()
      #Reset the windowOpenFlag
      self.cfgWindowOpen = False


  ################################################################################################################################################################
  def fctAddNewRunnableGroup(self):

    if not self.addNewGroupWindowOpen:
      self.addNewGroupWindowOpen = True
      rowCnt = 0
      #Reset the textFieldVariable
      self.newGroupPrefix.set('')

      #Create a new window to enter the text
      self.addNewGroupWindow = tk.Toplevel()
      self.addNewGroupWindow.title('Enter the prexif for new runnableGroup')
      self.addNewGroupWindow.minsize(600,80)

      #create the entryField
      entryField = tk.Entry(self.addNewGroupWindow, textvariable = self.newGroupPrefix, width = 50)
      entryField.grid(row = rowCnt, columnspan = 2)
      rowCnt += 1

      OkButton = tk.Button(self.addNewGroupWindow, text = 'OK', command = self.fctAddNewGroupOkButton)
      OkButton.grid(row = rowCnt, pady = 10, padx = 4, sticky = 'news')

      QuitButton = tk.Button(self.addNewGroupWindow, text = 'QUIT', command = self.fctAddNewGroupQuitButton)
      QuitButton.grid(row = rowCnt, column = 1, ipadx = 10, pady = 10, padx = 4, sticky = 'news')


  ################################################################################################################################################################
  def fctAddNewGroupOkButton(self):

    #Create a new groupObject with obtained prefix string
    prefix = self.newGroupPrefix.get()

    #Check if we got a text
    if len(prefix):

      cfg = [prefix, True]
      self.runnableGroupObjectList.append(RunnableGroup(cfg, self))

      #Refresh the window
      self.RefreshRunnableGroupsCfgWindow()

      #Destroy the window an reset the flag
      self.addNewGroupWindow.destroy()
      self.addNewGroupWindowOpen = False

    else:
      #No text entered!
      tkinter_messagebox.showinfo("Information", 'Please Please enter a groupPrefix first!!')


  ################################################################################################################################################################
  def fctAddNewGroupQuitButton(self):
    #Just destroy the window an reset the flag
    self.addNewGroupWindow.destroy()
    self.addNewGroupWindowOpen = False


  ################################################################################################################################################################
  def RefreshRunnableGroupsCfgWindow(self):

    if self.cfgWindowOpen:
      #Destroy the existing window
      self.top.destroy()

      #Draw it from scratch
      self.DrawRunnableGroupsCfgWindow()


  ################################################################################################################################################################
  def updateRunnableGroupsConfiguration(self):
    #First of all check wether has been called in this session at all
    if len(self.runnableGroupObjectList):
      #Ok we have objects in the list this means we have been called once
      #Update the runnableGroupsCfgList according the objects in the list

      #First delete all entries
      del self.runnableGroupsCfgList[:]
      #Run over all runnableGroupObjects and add these which shall not be deleted
      for runnableGroupObj in self.runnableGroupObjectList:
        if not runnableGroupObj.toBeDeleted:
          #This group shall be kept - add it to the list
          self.runnableGroupsCfgList.append([runnableGroupObj.myGroupPrefix , runnableGroupObj.groupEnabled.get()])



  ################################################################################################################################################################
  def runnableGroupsCfgUndoConfiguration(self):
    #Delete all existing runnableGroupObjects
    del self.runnableGroupObjectList[:]
    #Create the object from scratch based on current configuration in configFile
    for runnableGroupCfg in self.runnableGroupsCfgList:
      self.runnableGroupObjectList.append(RunnableGroup(runnableGroupCfg, self))
