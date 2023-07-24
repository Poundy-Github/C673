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

from InstrGeneratorBase import InstrGenBase

##################################################################################################################################################################
#
################################################################################################################################################################
class TaskConfigurator(InstrGenBase):

  #Class variable reflecting the number of currently open cfgWindows
  noOpenTaskCfgWindows = 0

  ################################################################################################################################################################
  def __init__(self, taskName, currentTaskCfg, runnableList, runnableGroupCfgObj):

    self.cfgWindowOpen     = False
    self.confirmWindowOpen = False

    self.taskName             = taskName
    self.taskRunTime          = currentTaskCfg['taskRunTime']
    self.runnableGroupCfgObj  = runnableGroupCfgObj
    self.CheckboxVar_runnableEnabledFlags = []

    #Create a list of all runnable including current setting
    #Create a twoDimensional list: [RUNNABLE_NAME][RUNNABLE_ENABLE_FLAG]
    self.RUNNABLE_NAME        = 0
    self.TRACE_HOOK_NAME      = 1
    self.RUNNABLE_ENABLE_FLAG = 2
    self.runnables = []
    for entry in runnableList:
      self.runnables.append([entry[self.INDEX_RUNNABLE], entry[self.INDEX_HOOK], currentTaskCfg['runnables'][entry[self.INDEX_RUNNABLE]]])

  ################################################################################################################################################################
  def drawTaskEntry(self, parentWindow, row):

    button = tk.Button(parentWindow, text = 'Configure', command = self.TaskCfgUserDialog)
    label = tk.Label(parentWindow, text = self.taskName)

    button.grid(row = row,sticky = 'news')
    label.grid(row = row, column = 1, sticky = W)


  ################################################################################################################################################################
  def TaskCfgUserDialog(self):

    if self.runnableGroupCfgObj.cfgWindowOpen:
      #The runnableGroupsConfigurationWindow is currently open
      #Inform the user to close it first
      tkinter_messagebox.showinfo("Information", 'Please close the runnableGroupsConfigurationWindow first!!')
    elif not self.cfgWindowOpen:
      #First increment the openTaskCfgWindow counter and set the windowOpenFlag
      TaskConfigurator.noOpenTaskCfgWindows += 1
      self.cfgWindowOpen = True
      #Generate a new Toplevel-Window
      self.top = tk.Toplevel()
      self.top.title('Configuration of ' + self.taskName)
      self.top.minsize(400,100)
      self.top.maxsize(800,800)

      rowCnt = 0

      self.CheckboxVar_taskRunTimeEnabled = tk.BooleanVar()
      taskRunTimeCheckbox = tk.Checkbutton(self.top, text = 'TaskRunTimeMeasurement', variable = self.CheckboxVar_taskRunTimeEnabled)
      self.CheckboxVar_taskRunTimeEnabled.set(self.taskRunTime)
      taskRunTimeCheckbox.grid(row = rowCnt,  columnspan = 4, pady = 10, sticky = W)
      rowCnt += 1

      taskStartLabel = tk.Label(self.top, text = 'Configure all runnables of the task:')
      taskStartLabel.grid(row = rowCnt, columnspan = 4, pady = 10, sticky = W)
      rowCnt += 1

      EnableAllButton = tk.Button(self.top, text = 'Enable all', command = self.fctTaskCfgEnableAllButton)
      EnableAllButton.grid(row = rowCnt, pady = 10, padx = 4, sticky = 'news')
      DisableAllButton = tk.Button(self.top, text = 'Disable all', command = self.fctTaskCfgDisableAllButton)
      DisableAllButton.grid(row = rowCnt, column = 1, pady = 10, padx = 4, sticky = 'news')
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

      #Create all the checkButtons in buttonFrame
      idx = 0
      runnableCheckBoxex = []
      del self.CheckboxVar_runnableEnabledFlags[:]
      for runnable in self.runnables:
        self.CheckboxVar_runnableEnabledFlags.append(tk.BooleanVar())
        self.CheckboxVar_runnableEnabledFlags[idx].set(runnable[self.RUNNABLE_ENABLE_FLAG])

        runnableCheckBoxex.append(tk.Checkbutton(buttonFrame, text = runnable[self.RUNNABLE_NAME], variable = self.CheckboxVar_runnableEnabledFlags[idx]))
        runnableCheckBoxex[idx].grid(row = idx, sticky = W)
        idx += 1

      # Update buttons frames idle tasks to let tkinter calculate buttons sizes
      # This is needed to make bbox info available
      buttonFrame.update_idletasks()

      #Resize the canvasFrame
      canvasFrame.configure(height = min(500, buttonFrame.winfo_height()), width = buttonFrame.winfo_width() + scrollbar.winfo_width()+ 5)

      # Set the canvas scrolling region
      canvas.config(scrollregion = canvas.bbox("all"))

      rowCnt += 1

      OkButton = tk.Button(self.top, text = 'OK', command = self.fctTaskCfgOkButton)
      OkButton.grid(row = rowCnt, ipadx = 10, pady = 10, padx = 4, sticky = 'news')

      CancelButton = tk.Button(self.top, text = 'CANCEL', command = self.fctTaskCfgCancelButton)
      CancelButton.grid(row = rowCnt,column = 1, pady = 10, padx = 4, sticky = 'news')

  ################################################################################################################################################################
  def fctTaskCfgOkButton(self):
    if not self.confirmWindowOpen:
      #Save the taskRunTimeEnabled flag
      self.taskRunTime = self.CheckboxVar_taskRunTimeEnabled.get()

      #Save the enabledFlags of all runnables
      for i in range(len(self.CheckboxVar_runnableEnabledFlags)):
        self.runnables[i][self.RUNNABLE_ENABLE_FLAG] = self.CheckboxVar_runnableEnabledFlags[i].get()

      #Close the window and reset the flag preventing multipe opening of the window
      self.top.destroy()
      #Decrement the openTaskCfgWindow counter and reset the windowOpenFlag
      TaskConfigurator.noOpenTaskCfgWindows -= 1
      self.cfgWindowOpen = False

  ################################################################################################################################################################
  def fctTaskCfgCancelButton(self):

    if not self.confirmWindowOpen:
      self.confirmWindowOpen = True
      #Create confirmation window
      self.topConfirm = tk.Toplevel()
      self.topConfirm.title('Discard changes?')

      rowCnt = 0

      infoText = tk.Label(self.topConfirm, text = 'Do you wish to discard all your changes? ')
      infoText.grid(row = rowCnt, columnspan = 4, pady = 10, sticky = 'we')
      rowCnt += 1

      YesButton = tk.Button(self.topConfirm, text = 'YES', command = self.fctTaskCfgYesButtonConfirm)
      YesButton.grid(row = rowCnt,column = 1, pady = 10, padx = 4, sticky = 'news')

      NoButton = tk.Button(self.topConfirm, text = 'No', command = self.fctTaskCfgNoButtonConfirm)
      NoButton.grid(row = rowCnt, ipadx = 10, pady = 10, padx = 4, sticky = 'news')

  ################################################################################################################################################################
  def fctTaskCfgNoButtonConfirm(self):
    #Just close the confirmation window, the confgiuration window shall remain open
    self.topConfirm.destroy()
    self.confirmWindowOpen = False

  ################################################################################################################################################################
  def fctTaskCfgYesButtonConfirm(self):
    #Close the confirmation window
    self.topConfirm.destroy()
    self.confirmWindowOpen = False
    #And close the configurationWindow without storing the recently made settings
    self.top.destroy()
    #Decrement the openTaskCfgWindow counter and reset the windowOpenFlag
    TaskConfigurator.noOpenTaskCfgWindows -= 1
    self.cfgWindowOpen = False


  ################################################################################################################################################################
  def fctTaskCfgEnableAllButton(self):
    print ('!!!!Enable all!!!')

    for entry in self.CheckboxVar_runnableEnabledFlags:
      entry.set(True)


  ################################################################################################################################################################
  def fctTaskCfgDisableAllButton(self):
    print ('!!!!Disable all!!!')

    for entry in self.CheckboxVar_runnableEnabledFlags:
      entry.set(False)


  ################################################################################################################################################################
  def getTaskConfiguration(self, taskCfg):

    #Update taskRunTimeEnable Flag
    taskCfg['taskRunTime'] = self.taskRunTime

    for i in range(len(self.runnables)):
      taskCfg['runnables'][self.runnables[i][self.RUNNABLE_NAME]] = self.runnables[i][self.RUNNABLE_ENABLE_FLAG]


  ################################################################################################################################################################
  def taskCfgGetVerificationInfo(self, taskRuntimeEnabled, runnableRuntimeEnabled, stepCountersEnabled):
    verifyDict = {}
    verifyDict['runnables']   = []

    if taskRuntimeEnabled:
      #taskruntime Measurement generally enabled - take the taskSpecific setting
      verifyDict['taskRunTime'] = self.taskRunTime
    else:
      #taskruntime measurement generally disabled
      verifyDict['taskRunTime'] = False


    #Create a list of all runnables for which rtaInstrumentation is configured including traceHookName
    for entry in self.runnables:
      if stepCountersEnabled:
        #StepCounterFeature is enabled - this means that the hookFunctions of all the runnables have to be enabled in RTE VFB Tracing
        verifyDict['runnables'].append([entry[self.RUNNABLE_NAME],entry[self.TRACE_HOOK_NAME]])
      elif runnableRuntimeEnabled:
        #StepCounterFeature is disabled and runableMeasurement is generally enabled
        # -> this means that the hookFunctions only of those runnables have to be enabled which shall be measured
        if entry[self.RUNNABLE_ENABLE_FLAG]:
          verifyDict['runnables'].append([entry[self.RUNNABLE_NAME],entry[self.TRACE_HOOK_NAME]])

    return verifyDict

  ################################################################################################################################################################
  def taskCfgUndoConfigurationChanges(self, taskCfg):

    #Set the taskRunTime measurement flag to the beginning state
    self.taskRunTime = taskCfg['taskRunTime']

    #Set all enableFlags to former state
    for entry in self.runnables:
      entry[self.RUNNABLE_ENABLE_FLAG] = taskCfg['runnables'][entry[self.RUNNABLE_NAME]]

  ################################################################################################################################################################
  def updateRunnableEnabledFlagsBasedOnUpdatedRunnableGroupsCfg(self):

    #Loop over all runnableGroupObjects and adapt the runnableEnabledFlags accordingly
    for groupObj in self.runnableGroupCfgObj.runnableGroupObjectList:
      #Determine the desired setting of the enabledFlag
      if (not groupObj.toBeDeleted) and (not groupObj.groupEnabled.get()):
        enabledFlag = False
      else:
        enabledFlag = True

      #Loop over all runnables and look for runnables with a matching prefix
      for runnable in self.runnables:
        if runnable[self.RUNNABLE_NAME].startswith(groupObj.myGroupPrefix):
          #This runnable has the prefix, update the enabledFlag
          runnable[self.RUNNABLE_ENABLE_FLAG] = enabledFlag


