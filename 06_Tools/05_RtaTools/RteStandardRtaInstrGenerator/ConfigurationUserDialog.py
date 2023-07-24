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

from TaskCfgUserDialog          import TaskConfigurator
from RunnableGroupCfgUserDialog import RunnableGroupsConfigurator
#################################################################################
#
#################################################################################
class UserDialog(InstrGenBase):

  #The indexes for taskConfiguratorObjects [[TASK_CFG_OBJS_INDEX_CONFIG_OBJ][TASK_CFG_OBJS_INDEX_TASK_CFG]]
  TASK_CFG_OBJS_INDEX_CONFIG_OBJ = 0
  TASK_CFG_OBJS_INDEX_TASK_CFG   = 1
  # Two dimensonal list of taskConfiguratorObjects and taskNames
  taskConfiguratorObjects = []

  #The error- OR warning text which shall be copied into the TraceHookHeaderFile
  errorWarningText = []

  #The configurationErrorWarningList containing errors and warnings which is returned ... TODO
  cfgErrorWarningList = []

  #The indexes for the verificationInfo
  VERIFY_IDX_RUNNABLE_NAME     = 0
  VERIFY_IDX_TRACE_HOOK_NAME   = 1

  #The indexes for the  MissingTraceHooks
  MISSING_TRACE_HOOKS_IDX_RUNNABLE            = 0
  MISSING_TRACE_HOOKS_IDX_START_HOOK_FOUND    = 1
  MISSING_TRACE_HOOKS_IDX_RETURN_HOOK_FOUND   = 2

  confirmWindowOpen          = False
  warningWindowOpen          = False

  #Flag indicating first run of function assembleErrorWarningTextAndUpdateLogFile
  isFirstRun                 = True

  #The info texts used for warningWindow, logFile and warning entries into the Rte_Trace_Hooks.h
  taskRuntimeDisabledLabelText          = 'The RTA taskRuntimeMeasurement has been disabled!'
  taskRuntimeDisabledExplLabelText      = 'With the current configuration no taskRuntimes will be measured!'
  runnableRuntimeDisabledLabelText      = 'The RTA runnableRuntimeMeasurement has been disabled!'
  runnableRuntimeDisabledExplLabelText  = 'With the current configuration no runnableRuntimes will be measured!'
  tracingDisabledLabelText              = 'Tracing has been globally disabled in RTE Configuration!'
  tracingDisExplLabelText               = '    For the RtaInstrumentation it is necessary that the Tracing (RTE_VFB_TRACE) is enabled in RTE!'
  FrameWorkHookTitleLabelText           = 'The following frameWorkHooks are disabled in RTE Configuration:'
  FrameWorkHookExplLabelText            = '    Without enabled frameWorkHooks the RtaTaskRuntimeMeasurement will not work!!'
  missingFrameWorkHookText              = '  - {0}'
  TraceHookTitleLabelText               = 'The tracehooks for the following runnables are disabled in RTE configuration:'
  TraceHookExplLabelText                = 'Without enabled traceHooks the RtaRuntimeMeasurement will not work for related runnables!'

  TaskLabelText                         = 'TASK  {0} :'
  missingRunnableLabelText              = ' - {0}'
  StartHookDisabledLabelText            = '    -> StartHook disabled'
  ReturnHookDisabledLabelText           = '    -> ReturnHook disabled'

  #The frameWorkHooks - needed for taskRuntimeMeasurement
  ALL_FRAMEWORK_HOOKS = [
    'Rte_Task_Dispatch',
    'Rte_Task_EndHook',
    'Rte_Task_WaitEventRet',
    'Rte_Task_WaitEvent',
  ]

  PATTERN_HOOK_DEFINE = '#define {0} \n'
  PATTERN_START_HOOK  = '{0}_Start'
  PATTERN_RETURN_HOOK = '{0}_Return'



  QUERY_DEFINE_RTE_VFB_TRACE = '#define RTE_VFB_TRACE {0}' # {0} -> 0, 1 or empty

  COMMENT_VFB_TRACE_ENABLED = ' /******* VFB Tracing enabled by RteStandardRtaInstrGenerator! *******/\n'

  RTE_CFG_H_MODIFIED_HEADER_TEXT = '''
/***********************************************************************************************
 * HookFunctions enabled by RteStandardRtaInstrGenerator   --> START <-- ***********************
 ***********************************************************************************************/

'''

  RTE_CFG_H_MODIFIED_TRAILER_TEXT = '''
/***********************************************************************************************
 * HookFunctions enabled by RteStandardRtaInstrGenerator   -->  END  <-- ***********************
 ***********************************************************************************************/

'''

  ################################################################################################################################################################
  def __init__(self, logFile, guiEnabled):
    print ('The configuration user dialog')
    #Save projectInfo
    self.logFile = logFile
    # Save guiSettings
    self.guiEnabled = guiEnabled

  ################################################################################################################################################################
  def askUserForConfig(self, basisCfg, taskAndRunnableCfg, taskInfo, rteCfgFile, errorWarningTextForTraceHookHeader):
    #Save current configuration in member
    self.currentBasisCfg           = basisCfg
    self.currenttaskAndRunnableCfg = taskAndRunnableCfg
    #Save Lines of RteCfg in member
    self.rteCfgFile = rteCfgFile


    #Create the runnableGroupConfiguratorObject
    self.runnableGroupCfgObj = RunnableGroupsConfigurator(self, basisCfg['runnableGroupsCfg'])
      
    #For every task create a TaskConfigurator object and put them into a list together with the taskName
    for task in list(taskInfo.keys()):
      obj = TaskConfigurator(task, taskAndRunnableCfg[task], taskInfo[task]['runnableCfgList'], self.runnableGroupCfgObj)
      self.taskConfiguratorObjects.append( [obj, taskAndRunnableCfg[task]] )

    if self.guiEnabled:
      #GUI is enabled - prepare and open the userDialog
      rowCnt = 0
      
      # Create root window 
      self.root = tk.Tk()
      self.root.title('Configuration RTE StandardRtaInstrumentation')
      self.root.minsize(400, 200)
      self.root.maxsize(800, 800)

      self.stepCountersEnabled = tk.BooleanVar()
      enableCheckbox = tk.Checkbutton(self.root, text = 'StepCounters enabled', variable = self.stepCountersEnabled)
      self.stepCountersEnabled.set(basisCfg['stepCountersEnabled'])
      enableCheckbox.grid(row = rowCnt, columnspan = 4, sticky = W, pady = 10)
      rowCnt += 1

      self.taskRuntimeEnabled = tk.BooleanVar()
      enableCheckbox = tk.Checkbutton(self.root, text = 'TaskRuntimeMeasurement enabled', variable = self.taskRuntimeEnabled)
      self.taskRuntimeEnabled.set(basisCfg['taskRuntimeMeasurementEnabled'])
      enableCheckbox.grid(row = rowCnt, columnspan = 4, sticky = W, pady = 10)
      rowCnt += 1

      self.runnableRuntimeEnabled = tk.BooleanVar()
      enableCheckbox = tk.Checkbutton(self.root, text = 'RunnableRuntimeMeasurement enabled', variable = self.runnableRuntimeEnabled)
      self.runnableRuntimeEnabled.set(basisCfg['runnableRuntimeMeasurementEnabled'])
      enableCheckbox.grid(row = rowCnt, columnspan = 4, sticky = W, pady = 10)
      rowCnt += 1

      self.runnableGroupCfgObj.drawRunnableGroupCfgButton(self.root, rowCnt)
      rowCnt += 1

      #Create a frame for the canvas to be scrolled
      canvasFrame = tk.Frame(self.root)
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
      #Create a frame to contain all the tasks 
      taskFrame = tk.Frame(canvas)
      canvas.create_window((0, 0), window = taskFrame, anchor='nw')

      idx = 0
      #Create all the tasks in canvas
      for entry in self.taskConfiguratorObjects:
        entry[self.TASK_CFG_OBJS_INDEX_CONFIG_OBJ].drawTaskEntry(taskFrame, idx)
        idx += 1

      # Update buttons frames idle tasks to let tkinter calculate buttons sizes
      # This is needed to make bbox info available
      taskFrame.update_idletasks()

      #Resize the canvasFrame
      canvasFrame.configure(height = min(500, taskFrame.winfo_height()), width = taskFrame.winfo_width() + scrollbar.winfo_width()+ 5)

      # Set the canvas scrolling region
      canvas.config(scrollregion = canvas.bbox("all"))

      rowCnt += 1

      OkButton = tk.Button(self.root, text = 'OK', command = self.fctOkButton)
      OkButton.grid(row = rowCnt, pady = 10, ipadx = 40, sticky = 'sn')

      CancelButton = tk.Button(self.root, text = 'UNDO CHANGES', command = self.fctUndoCfgChangesButton)
      CancelButton.grid(row = rowCnt,column = 1, pady = 10,  padx = 4, sticky = 'sn')


      self.root.mainloop()
      print ('After root mainLoop!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')

    else:
      #GUI is disabled just run the verification
      self.verifyConfiguration()

    #Update the argument errorWarningText
    del errorWarningTextForTraceHookHeader[:] # Ensure that this list is empty
    errorWarningTextForTraceHookHeader.extend(self.errorWarningText)
    return self.cfgErrorWarningList


  ################################################################################################################################################################
  def fctOkButton(self):
    if (not self.confirmWindowOpen) and (not self.warningWindowOpen):
      if not TaskConfigurator.noOpenTaskCfgWindows:
        #Check whether all relevant hooks are enabled in the rteConfig
        if self.verifyConfiguration():
          #Verification was ok -  update the configuration and close the window
          self.updateConfig()
          self.root.destroy()
      else:
        #Generate infoWindow
        tkinter_messagebox.showinfo("Information", 'Please close all open taskConfigurationWindows first!!')


  ################################################################################################################################################################
  def verifyConfiguration(self):

    linesRteCfgPureCode = []

    #Clear the configurationErrorList
    del self.cfgErrorWarningList [:]

    enableVfbTracing        = False  # @UnusedVariable
    stepCountersEnabled     = False
    taskRuntimeEnabled      = False
    runnableRuntimeEnabled  = False
    MissingFrameWorkHooks   = []
    MissingTraceHooks       = []
    verificationInfo        = {}


    if self.guiEnabled:
      if self.taskRuntimeEnabled.get():
        taskRuntimeEnabled = True
      if self.runnableRuntimeEnabled.get():
        runnableRuntimeEnabled = True
      if self.stepCountersEnabled.get():
        stepCountersEnabled = True
    else:
      if self.currentBasisCfg['taskRuntimeMeasurementEnabled']:
        taskRuntimeEnabled = True
      if self.currentBasisCfg['runnableRuntimeMeasurementEnabled']:
        runnableRuntimeEnabled = True
      if self.currentBasisCfg['stepCountersEnabled']:
        stepCountersEnabled = True

    for i in range(len(self.taskConfiguratorObjects)):
      #Get current taskConfiguratorObject and taskConfiguration
      taskConfigurator =  self.taskConfiguratorObjects[i][self.TASK_CFG_OBJS_INDEX_CONFIG_OBJ]
      verificationInfo[taskConfigurator.taskName] = taskConfigurator.taskCfgGetVerificationInfo(taskRuntimeEnabled, runnableRuntimeEnabled, stepCountersEnabled)

    #Get the lines of Rte_Cfg.h - it may be updated since the last iteration
    linesRteCfg = self.getLinesOfFile(self.rteCfgFile)
    #Get pureCode only without any comments or commented out code
    self.getLinesOfPureCode(linesRteCfg, linesRteCfgPureCode)

    enableVfbTracing = self.shallVfbTracingBeEnabled(linesRteCfgPureCode, verificationInfo, stepCountersEnabled)

    self.getListOfMissingFrameWorkHooks(linesRteCfgPureCode, verificationInfo, MissingFrameWorkHooks)

    self.getListsOfMissingTraceHooks(linesRteCfgPureCode, verificationInfo, MissingTraceHooks)

    if not self.patchRteCfgHeaderAccordingGeneratorCfg(linesRteCfg, linesRteCfgPureCode, enableVfbTracing, MissingFrameWorkHooks, MissingTraceHooks):
      if self.RTE_GEN_TYPE_TRESOS == self.rteGenType: 
        self.cfgErrorWarningList.append(self.CFG_ERROR_RTE_VFB_TRACE_DEFINE_NOT_FOUND_TRESOS)
      else:
        self.cfgErrorWarningList.append(self.CFG_ERROR_RTE_VFB_TRACE_DEFINE_NOT_FOUND_DA_VINCI)

    if not self.isMaxNumberOfRunnablesInRange(verificationInfo, stepCountersEnabled):
      self.cfgErrorWarningList.append(self.CFG_ERROR_RTE_NUMBER_OF_RUNNABLES_OUT_OF_RANGE)

    #Determine the configuration errors/warnings which we may have
    if not taskRuntimeEnabled:
      self.cfgErrorWarningList.append(self.CFG_ERROR_RTA_TASK_RUNTIME_DISABLED)

    if not runnableRuntimeEnabled:
      self.cfgErrorWarningList.append(self.CFG_ERROR_RTA_RUNNABLE_RUNTIME_DISABLED)

    self.assembleErrorWarningTextAndUpdateLogFile()

    if not taskRuntimeEnabled or not runnableRuntimeEnabled:
      if self.guiEnabled:
        #Something is not ok - create warningWindow
        self.createWarningWindow(taskRuntimeEnabled, runnableRuntimeEnabled)
      return False
    else:
      return True


  ################################################################################################################################################################
  def isMaxNumberOfRunnablesInRange(self, verificationInfo, stepCountersEnabled):
    maxNumberRunnablesInRange = True

    if stepCountersEnabled:
      #StepCounters enabled - check if the number of runnables of every task fits into the stepCounterRange
      allTasks = list(verificationInfo.keys())
      for task in allTasks:
        if self.STEP_COUNTER_RANGE < len(verificationInfo[task]['runnables']):
          maxNumberRunnablesInRange = False
          break

    return maxNumberRunnablesInRange

  ################################################################################################################################################################
  def patchRteCfgHeaderAccordingGeneratorCfg(self, linesRteCfg, linesRteCfgPureCode, enableVfbTracing, MissingFrameWorkHooks, MissingTraceHooks):
    vfbTraceDefineFound = True
    #First of all check whether there is somethig to do
    if enableVfbTracing or len(MissingFrameWorkHooks) or len(MissingTraceHooks):
      lineNo = 0
      #Find vfbTrace define in RteCfg.h
      query = self.QUERY_DEFINE_RTE_VFB_TRACE.format('').replace(' ','') #Query is definition of RTE_VFB_TRACE without whiteSpaces
      for lineNo in range(len(linesRteCfgPureCode)):
        if -1 != linesRteCfgPureCode[lineNo].replace(' ','').find(query):
          # Ok - line of VfbTraceDefine found
          if self.RTE_GEN_TYPE_TRESOS == self.rteGenType:
            # We have Tresos as rteGenerator - modify the Rte_Cfg.h according to our configuration
            # Note: In case of DaVinci it makes no sense to modifiy Rte_Cfg.h as in case the tracing is disabled for 
            #       single runables also the related hookFunction is not called and therefore the related runnable is 
            #       not considered by our generator. 
            if enableVfbTracing:
              #Substitue the line containing the vfbTraceDefine with the "enabled" define
              linesRteCfg[lineNo] =  self.QUERY_DEFINE_RTE_VFB_TRACE.format('1   ') + self. COMMENT_VFB_TRACE_ENABLED
    
            if len(MissingFrameWorkHooks) or len(MissingTraceHooks):
              lineNo += 1
    
              #Instert trailerText
              linesRteCfg.insert(lineNo, self.RTE_CFG_H_MODIFIED_TRAILER_TEXT)
    
              #Add missing runnableHooks
              MissingTraceHooks.reverse()
              for hook in MissingTraceHooks:
                linesRteCfg.insert(lineNo, self.PATTERN_HOOK_DEFINE.format(hook))
    
              #Add missing frameWorkHooks
              MissingFrameWorkHooks.reverse()
              for hook in MissingFrameWorkHooks:
                linesRteCfg.insert(lineNo, self.PATTERN_HOOK_DEFINE.format(hook))
    
              #Finally insert trailerText
              linesRteCfg.insert(lineNo, self.RTE_CFG_H_MODIFIED_HEADER_TEXT)
    
            #Update the Rte_Cfg.h file
            self.writeLinesintoFile(self.rteCfgFile , linesRteCfg)
          #Finally terminate loop
          break
      else:
        #VFB Trace define not found!!
        vfbTraceDefineFound = False

    return vfbTraceDefineFound




  ################################################################################################################################################################
  def assembleErrorWarningTextAndUpdateLogFile(self):

    TEXT_EVERYTHING_OK   = 'No error, no warnings - FINE!! \n'

    preDirective = ''

    headerText   = ['\n']
    warningLines = []
    trailerText  = ['\n*/\n\n']

    for entry in self.cfgErrorWarningList:
      errorMessage = self.cfgErrorWarningMsgDict.get(entry)
      if errorMessage:
        warningLines.extend(errorMessage['msgText'])
        if self.MSG_TYPE_ERROR == errorMessage['msgType']:
          preDirective += '#error  ' + errorMessage['shortMsg'] + '\n'
        else:
          preDirective += '#warning ' + errorMessage['shortMsg'] + '\n'

    #Add preProcessorDirective for traceHookHeader
    headerText.append(preDirective)


    #Update logFile
    #Get all lines from the logFile
    linesLogFile = self.getLinesOfFile(self.logFile)
    if self.guiEnabled and not self.isFirstRun:
      linesLogFile.append('\n\nNext configuration iteration ##################################################################\n')
      linesLogFile.append('NOTE: Only the last one in the logFile is valid\n')
    #Add all the warning lines
    linesLogFile.extend(warningLines)
    #Write all lines back to logFile
    self.writeLinesintoFile(self.logFile, linesLogFile)

    headerText.append('\n/* \n') #Add start of multi line comment
    if not len(warningLines):
      #Evidently everything is ok - add related text to warninglines
      warningLines.append(TEXT_EVERYTHING_OK)

    #Update the errorWarningText
    del self.errorWarningText[:] #Ensure that the errorWarningText is empty
    self.errorWarningText.extend(headerText)
    self.errorWarningText.extend(warningLines)
    self.errorWarningText.extend(trailerText)

    #reset firstRunFlag
    self.isFirstRun = False


  ################################################################################################################################################################
  def createWarningWindow(self, taskRuntimeEnabled, runnableRuntimeEnabled):

    #Set flag preventing multiple opening of warning window
    self.warningWindowOpen = True

    #Create the warningWindow
    self.topWarning = tk.Toplevel()
    self.topWarning.title('Warning!!!')
    self.topWarning.minsize(400,100)
    self.topWarning.maxsize(1000,1000)

    rowCnt = 0
    if not taskRuntimeEnabled:
      instrDisabledLabel = tk.Label(self.topWarning, text = self.taskRuntimeDisabledLabelText)
      instrDisabledLabel.grid(row = rowCnt, columnspan = 2, pady = (20,0), sticky = 'w')
      rowCnt += 1
      instrDisExplLabel = tk.Label(self.topWarning, text = self.taskRuntimeDisabledExplLabelText)
      instrDisExplLabel.grid(row = rowCnt, columnspan = 2, pady = (0,10), sticky = 'w')
      rowCnt += 1

    if not runnableRuntimeEnabled:
      instrDisabledLabel = tk.Label(self.topWarning, text = self.runnableRuntimeDisabledLabelText)
      instrDisabledLabel.grid(row = rowCnt, columnspan = 2, pady = (20,0), sticky = 'w')
      rowCnt += 1
      instrDisExplLabel = tk.Label(self.topWarning, text = self.runnableRuntimeDisabledExplLabelText)
      instrDisExplLabel.grid(row = rowCnt, columnspan = 2, pady = (0,10), sticky = 'w')
      rowCnt += 1

    rowCnt += 1


    OkButton = tk.Button(self.topWarning, text = "It's OK - Continue", command = self.fctWarningWindowOkButton)
    OkButton.grid(row = rowCnt, ipadx = 30, pady = 10, padx = 4, sticky = 'news')

    QuitButton = tk.Button(self.topWarning, text = 'Stop - Go back to RtaInstrumentationCfg', command = self.fctWarningWindowQuitButton)
    QuitButton.grid(row = rowCnt, column = 1,  ipadx = 10, pady = 10, padx = 4, sticky = 'news')


  ################################################################################################################################################################
  def fctWarningWindowOkButton(self):
    #Update configuration
    self.updateConfig()
    self.topWarning.destroy()
    self.root.destroy()
    #Finally reset flag preventing multipe openings of warningWindow
    self.warningWindowOpen = False


  ################################################################################################################################################################
  def fctWarningWindowQuitButton(self):
    #Just terminate warningWindow
    self.topWarning.destroy()
    #Reset flag preventing multipe openings of warningWindow
    self.warningWindowOpen = False


  ################################################################################################################################################################
  def shallVfbTracingBeEnabled(self, linesRteCfgPureCode, verificationInfo, stepCountersEnabled):
    vfbTracingNeeded = False
    enableVfbTracing = False

    if stepCountersEnabled:
      vfbTracingNeeded = True
    else:
      #Get a keyList of the verificationInfo
      keyList = list(verificationInfo.keys())
      #Loop over all tasks in verificationInfo and check whether we need an enabled tracing for rtaInstrumentation
      for key in keyList:
        if verificationInfo[key]['taskRunTime'] or len(verificationInfo[key]['runnables']):
          #OK we have a task with an activated rtaInstrumentation - VFB Tracing is needed
          vfbTracingNeeded = True
          #Terminate loop immediately
          break

    if vfbTracingNeeded:
      enableVfbTracing = True

      #Loop over the lines of Rte_Cfg.h (pure code only) and look for the RTE_VFB_TRACE define
      query = self.QUERY_DEFINE_RTE_VFB_TRACE.format('1').replace(' ','') #Query is definition of RTE_VFB_TRACE without whiteSpaces
      for line in linesRteCfgPureCode:
        if -1 != line.replace(' ','').find(query):
          # Ok define found and value is correct
          enableVfbTracing = False

    return enableVfbTracing


  ################################################################################################################################################################
  def getListOfMissingFrameWorkHooks(self, linesRteCfgPureCode, verificationInfo, MissingFrameWorkHooks):

    #For sake of safety clean the list
    del MissingFrameWorkHooks[:]

    #Get a keyList of the verificationInfo
    keyList = list(verificationInfo.keys())

    #Determine whether all frameWorkHooks are enabled
    #Loop over all tasks and check whether the frameworkHooks are needed
    for key in keyList:
      if verificationInfo[key]['taskRunTime']:
        #For this task the taskRuntime shall be measured - frameWorkHooks needed
        #loop over all needed frameWorkHooks and look for their definition in Rte_Cfg.h
        for hook in self.ALL_FRAMEWORK_HOOKS:
          query = self.PATTERN_HOOK_DEFINE.format(hook)
          #Remove all whitespaces to increase the chance to find a matching line
          query = query.replace(' ', '')
          for line in linesRteCfgPureCode:
            cleanedLine = line.replace(' ','')
            if cleanedLine == query:
              #Ok define found - terminate inner loop
              break
          else:
            #Add current hook to the list of Missing FrameHooks
            MissingFrameWorkHooks.append(hook)
        #Terminate outer loop
        break


  ################################################################################################################################################################
  def getListsOfMissingTraceHooks(self, linesRteCfgPureCode, verificationInfo, MissingTraceHooks):
    # For sake of savety remove all entries in MissingTraceHooks dictionary
    del MissingTraceHooks[:]

    #Get a keyList of the verificationInfo
    keyList = list(verificationInfo.keys())

    #Loop over all tasks and look for the defines of required runnableHooks
    for key in keyList:
      #Loop over all enabled runnables an look for related traceHookDefines
      for entry in verificationInfo[key]['runnables']:
        startHookFound  = False
        returnHookFound = False

        #Remove all whitespaces to increase the chance to find a matching line
        queryStartHook  = self.PATTERN_START_HOOK.format(entry[self.VERIFY_IDX_TRACE_HOOK_NAME])
        queryStartHook  = self.PATTERN_HOOK_DEFINE.format(queryStartHook).replace(' ', '')

        queryReturnHook = self.PATTERN_RETURN_HOOK.format(entry[self.VERIFY_IDX_TRACE_HOOK_NAME])
        queryReturnHook = self.PATTERN_HOOK_DEFINE.format(queryReturnHook).replace(' ', '')

        #Look for matching lines
        for line in linesRteCfgPureCode:
          cleanedLine = line.replace(' ','')
          if cleanedLine == queryStartHook:
            #define for startHook found
            startHookFound = True
          elif cleanedLine == queryReturnHook:
            #define for returnHook found
            returnHookFound = True
          if startHookFound and returnHookFound:
            #Ok both defines are found - terminate the loop
            break
        else:
          #At least one define has not been found -  add it to the list
          if not startHookFound:
            MissingTraceHooks.append(self.PATTERN_START_HOOK.format(entry[self.VERIFY_IDX_TRACE_HOOK_NAME]))
          if not returnHookFound:
            MissingTraceHooks.append(self.PATTERN_RETURN_HOOK.format(entry[self.VERIFY_IDX_TRACE_HOOK_NAME]))


  ################################################################################################################################################################
  def fctUndoCfgChangesButton(self):
    if not self.confirmWindowOpen:
      if (not TaskConfigurator.noOpenTaskCfgWindows) and not (self.runnableGroupCfgObj.cfgWindowOpen):
        self.confirmWindowOpen = True
        #Create confirmation window
        self.topConfirm = tk.Toplevel()
        self.topConfirm.title('Reset changes in instrumentationConfiguration?')

        rowCnt = 0

        infoText = tk.Label(self.topConfirm, text = 'Do you wish to reset all your changes in instrumentationConfiguration? ')
        infoText.grid(row = rowCnt, columnspan = 4, pady = 10, sticky = 'we')
        rowCnt += 1

        YesButton = tk.Button(self.topConfirm, text = 'YES', command = self.fctYesButtonConfirm)
        YesButton.grid(row = rowCnt,column = 1, pady = 10, padx = 4, sticky = 'news')

        NoButton = tk.Button(self.topConfirm, text = 'No', command = self.fctNoButtonConfirm)
        NoButton.grid(row = rowCnt, ipadx = 10, pady = 10, padx = 4, sticky = 'news')
      else:
        #Generate infoWindow
        tkinter_messagebox.showinfo("Information", 'Please close all open cfgWindows (taskConfigurationWindows / runnableGroupConfigurationWindows  first!!')

  ################################################################################################################################################################
  def fctNoButtonConfirm(self):
    #Just close the confirmation window, the confgiuration window shall remain open
    self.topConfirm.destroy()
    self.confirmWindowOpen = False

  ################################################################################################################################################################
  def fctYesButtonConfirm(self):
    #Reset all configuration changes
    self.undoCfgChanges()
    #Close the confirmation window
    self.topConfirm.destroy()
    self.confirmWindowOpen = False
    self.cfgWindowOpen = False


  ################################################################################################################################################################
  def updateConfig(self):
    #Update the basisConfig
    self.currentBasisCfg['stepCountersEnabled']               = self.stepCountersEnabled.get()
    self.currentBasisCfg['taskRuntimeMeasurementEnabled']     = self.taskRuntimeEnabled.get()
    self.currentBasisCfg['runnableRuntimeMeasurementEnabled'] = self.runnableRuntimeEnabled.get()
    self.runnableGroupCfgObj.updateRunnableGroupsConfiguration()

    #Update the configurations of the tasks
    for i in range(len(self.taskConfiguratorObjects)):
      #Get current taskConfiguratorObject and taskConfiguration
      taskConfigurator =  self.taskConfiguratorObjects[i][self.TASK_CFG_OBJS_INDEX_CONFIG_OBJ]
      taskCfg          = self.taskConfiguratorObjects[i][self.TASK_CFG_OBJS_INDEX_TASK_CFG]
      taskConfigurator.getTaskConfiguration(taskCfg)


  ################################################################################################################################################################
  def undoCfgChanges(self):
    #Set the global instrumentationEnableFlag to the former state
    self.stepCountersEnabled.set(self.currentBasisCfg['stepCountersEnabled'])
    self.taskRuntimeEnabled.set(self.currentBasisCfg['taskRuntimeMeasurementEnabled'])
    self.runnableRuntimeEnabled.set(self.currentBasisCfg['runnableRuntimeMeasurementEnabled'])
    self.runnableGroupCfgObj.runnableGroupsCfgUndoConfiguration()

    #Reset all changes in the tasks
    for i in range(len(self.taskConfiguratorObjects)):
      #Get current taskConfiguratorObject and taskConfiguration
      taskConfigurator =  self.taskConfiguratorObjects[i][self.TASK_CFG_OBJS_INDEX_CONFIG_OBJ]
      taskCfg          = self.taskConfiguratorObjects[i][self.TASK_CFG_OBJS_INDEX_TASK_CFG]
      taskConfigurator.taskCfgUndoConfigurationChanges(taskCfg)


  ################################################################################################################################################################
  def updatetaskConfiguratorObjectsBasedOnUpdatedRunnableGroupsConfiguration(self):
    #Loop over all taskConfiguratorObjects and update them according the updated runnableGroupsConfiguration
    for taskCfgObj in self.taskConfiguratorObjects:
      taskCfgObj[self.TASK_CFG_OBJS_INDEX_CONFIG_OBJ].updateRunnableEnabledFlagsBasedOnUpdatedRunnableGroupsCfg()
