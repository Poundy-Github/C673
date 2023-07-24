import os
import sys

from ConfigurationUserDialog import UserDialog

#################################################################################
#
#################################################################################
class RteRtaInstConfigurator(UserDialog):

  #The indexes for the REQUIRED_KEY_VALUE_PAIRS
  IDX_BASE_CFG_KEY   = 0
  IDX_BASE_CFG_DEFAULT_VALUE = 1

  # This two dimensional list is used to maintain and repair the RteInstr_BasisConfig.py
  # It contains all base configuration options including their default values.
  #
  # REQUIRED_KEY_VALUE_PAIRS[[IDX_BASE_CFG_KEY], [IDX_BASE_CFG_DEFAULT_VALUE],
  #                          [IDX_BASE_CFG_KEY], [IDX_BASE_CFG_DEFAULT_VALUE],
  #                           ]
  REQUIRED_KEY_VALUE_PAIRS = [

    ['stepCountersEnabled'                , False],
    ['selfTestCheckpointsEnabled'         , False],
    ['taskRuntimeMeasurementEnabled'      , True],
    ['runnableRuntimeMeasurementEnabled'  , True],
    ['runnableGroupsCfg'                  , []],
  ]


  cfgFile = ''


  ################################################################################################################################################################
  def __init__(self, project, tresosProjectPath, logFile, guiEnabled, rteGenType):

    #call constructor of base class
    super(RteRtaInstConfigurator, self).__init__(logFile, guiEnabled)

    self.project    = project
    self.rteGenType = rteGenType
    #get the path to projectSpecific configFile
    self.cfgDir = tresosProjectPath

    #Add the directory to systemPath
    sys.path.append(self.cfgDir)
    #Get both generator configuration files
    self.basisCfgFile           = self.cfgDir + '/RteInstr_BasisConfig.py'
    self.taskAndRunnableCfgFile = self.cfgDir + '/RteInstr_TaskAndRunnableConfig.py'

    self.basisCfgTemplateFile           = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/RteInstr_BasisConfig_Template.py'
    self.taskAndRunnableCfgTemplateFile = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/RteInstr_TaskAndRunnableConfig_Template.py'

    self.checkAndImportBasisConfigFile()
    self.checkAndImportTaskAndRunnableConfigFile()

    print ('Configurator init done!')


  ################################################################################################################################################################
  def checkAndImportBasisConfigFile(self):
    useTemplateCfg = True
    importCfg      = True
    updateCfgFile  = False

    if os.path.isfile(self.basisCfgFile):
      #File already exists - try to import it
      try:
        import RteInstr_BasisConfig  # @UnresolvedImport
      except:
        print ('Import of basisConfigFile failed!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
      else:
        #Import was successful - reset related flag
        importCfg = False
        #Check whether the expected attribute is available
        if hasattr(RteInstr_BasisConfig, 'BasisConfig'):
          #Reset useTemplateCfg - the current cfgFile is valid - no need to use the templateFile
          useTemplateCfg = False

    if useTemplateCfg:
      #ConfigFile is not available or invalid -> use the templateFile
      print ('Read BaseconfigTemplateFile!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
      #Get the content of the templateFile
      templateString = self.readStringOfFile(self.basisCfgTemplateFile)

      #Write the content into the projectSpecific configFile - with adapted projectInfo
      self.writeStringToFile(self.basisCfgFile, templateString.replace('<___project___>', self.project))
      if importCfg:
        import RteInstr_BasisConfig  # @UnresolvedImport @Reimport
      else:
        reload (RteInstr_BasisConfig)  # @UndefinedVariable
    else:
      #Check if all keys in the cfgFile are still needed
      currentKeys = list(RteInstr_BasisConfig.BasisConfig.keys())
      for currentKey in currentKeys:
        for reqKeyAndValue in self.REQUIRED_KEY_VALUE_PAIRS:
          if reqKeyAndValue[self.IDX_BASE_CFG_KEY] == currentKey:
            #OK, this key is still needed - just terminate the inner loop
            break
        else:
          #this key is not needed anymore - remove it
          del RteInstr_BasisConfig.BasisConfig[currentKey]
          #Set the flag indicating that the cfgFile needs to be updated
          updateCfgFile = True

    #Check if all required keys are available
    for reqKeyAndValue in self.REQUIRED_KEY_VALUE_PAIRS:
      if not reqKeyAndValue[self.IDX_BASE_CFG_KEY] in RteInstr_BasisConfig.BasisConfig:
        #Key not available - add it
        RteInstr_BasisConfig.BasisConfig[reqKeyAndValue[self.IDX_BASE_CFG_KEY]] = reqKeyAndValue[self.IDX_BASE_CFG_DEFAULT_VALUE]
        #Set the flag indicating that the cfgFile needs to be updated
        updateCfgFile = True

    if updateCfgFile:
      print ('updateCfgFile!!!##############################################')
      print ('RteInstr_BasisConfig.BasisConfig:' + str(RteInstr_BasisConfig.BasisConfig))
      self.updateConfigFile(self.basisCfgFile, RteInstr_BasisConfig.BasisConfig)


  ################################################################################################################################################################
  def checkAndImportTaskAndRunnableConfigFile(self):
    useTemplateCfg = True
    importCfg      = True

    if os.path.isfile(self.taskAndRunnableCfgFile):
      #File already exists - try to import it
      try:
        import RteInstr_TaskAndRunnableConfig  # @UnresolvedImport
      except:
        print ('Import of TaskAndRunnableConfigFile failed!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
      else:
        #Import was successful - reset related flag
        importCfg = False
        #Check whether the expected attribute is available
        if hasattr(RteInstr_TaskAndRunnableConfig, 'TaskAndRunnableConfig'):
          #Reset useTemplateCfg - will be set in the following loop - if needed
          useTemplateCfg = False

    if useTemplateCfg:
      #ConfigFile is not available or invalid -> use the templateFile
      print ('Read TaskAndRunnableConfigTemplateFile!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!')
      #Get the content of the templateFile
      templateString = self.readStringOfFile(self.taskAndRunnableCfgTemplateFile)

      #Write the content into the projectSpecific configFile - with adapted projectInfo
      self.writeStringToFile(self.taskAndRunnableCfgFile, templateString.replace('<___project___>', self.project))
      if importCfg:
        import RteInstr_TaskAndRunnableConfig  # @UnresolvedImport @Reimport
      else:
        reload (RteInstr_TaskAndRunnableConfig)  # @UndefinedVariable


  ################################################################################################################################################################
  def configurate(self, taskInfo, additionalFeatureCfg, rteCfgFile, errorWarningTextForTraceHookHeader):
    from RteInstr_BasisConfig           import BasisConfig  # @UnresolvedImport
    from RteInstr_TaskAndRunnableConfig import TaskAndRunnableConfig  # @UnresolvedImport

    #Cleanup the current config - obtained from related configFile - if needed
    self.cleanupTaskAndRunnableConfig(TaskAndRunnableConfig, taskInfo)

    #Update the configuration dictionary (add new tasks and runnables)
    self.updateTaskAndRunnableConfigDict(BasisConfig, TaskAndRunnableConfig, taskInfo)

    #Open user dialog for configuration
    cfgErrorWarningList = self.askUserForConfig(BasisConfig, TaskAndRunnableConfig, taskInfo, rteCfgFile, errorWarningTextForTraceHookHeader)

    #Update taskInfo according current configuration in order to become it effective in current generator run
    self.updateTaskInfo(BasisConfig, TaskAndRunnableConfig, taskInfo)

    #Update configuration of additional features (stepCounters, selfTestCheckpointFct.) according current configuration in order to become it effective in current generator run
    self.updateAdditionalFeatureCfg(BasisConfig, additionalFeatureCfg)

    #Update configurationFiles for next generator run
    self.updateConfigFile(self.taskAndRunnableCfgFile, TaskAndRunnableConfig)
    if self.guiEnabled:
      self.updateConfigFile(self.basisCfgFile, BasisConfig)

    return cfgErrorWarningList


  ################################################################################################################################################################
  def cleanupTaskAndRunnableConfig(self, taskAndRunnableCfg, taskInfo):

    allTasks = list(taskAndRunnableCfg.keys())

    #Loop over all tasks in cfg and check whether they are still needed
    for task in allTasks:
      #Check whether this task is still in taskInfo
      if task in taskInfo:
        #Create a list of all runnables of this task
        neededRunnables = []

        for entry in taskInfo[task]['runnableCfgList']:
          neededRunnables.append(entry[self.INDEX_RUNNABLE])

        #Remove all hooks from config which are not needed anymore
        allRunnablesInCfg = list(taskAndRunnableCfg[task]['runnables'].keys())

        for runnable in allRunnablesInCfg:
          if not neededRunnables.count(runnable):
            #This runnable is not existend anymore, delete related dictEntry
            del taskAndRunnableCfg[task]['runnables'][runnable]
      else:
        #This task is no longer existent - remove also related config
        del taskAndRunnableCfg[task]

  ################################################################################################################################################################
  def updateTaskAndRunnableConfigDict(self, basisConfig, taskAndRunnableCfg, taskInfo):

    allNeededTasks = list(taskInfo.keys())

    for task in allNeededTasks:
      if task in taskAndRunnableCfg:
        # Ok this task is already in config - just add runnables if not there
        for runnable in taskInfo[task]['runnableCfgList']:
          enabledFlag = self.getRunnableGroupCfg(basisConfig, runnable[self.INDEX_RUNNABLE], True)
          taskAndRunnableCfg[task]['runnables'].setdefault(runnable[self.INDEX_RUNNABLE], enabledFlag)
      else:
        #This task is not in cfg - create a new entry
        newTaskEntry = { task: {\
          'taskRunTime':True, \
          'runnables':{}}}
        #Add all the runnables of this task
        for runnable in taskInfo[task]['runnableCfgList']:
          enabledFlag = self.getRunnableGroupCfg(basisConfig, runnable[self.INDEX_RUNNABLE], True)
          newTaskEntry[task]['runnables'][runnable[self.INDEX_RUNNABLE]] = enabledFlag

        #Add newEntry to config
        taskAndRunnableCfg.update(newTaskEntry)


  ################################################################################################################################################################
  def updateAdditionalFeatureCfg(self, basisCfg, additionalFeatureCfg):

    additionalFeatureCfg['stepCountersEnabled']        = basisCfg['stepCountersEnabled']
    additionalFeatureCfg['selfTestCheckpointsEnabled'] = basisCfg['selfTestCheckpointsEnabled']


  ################################################################################################################################################################
  def updateTaskInfo(self, basisCfg, taskAndRunnableCfg, taskInfo):

    #Get a list of all tasks in taskInfo
    allTasks = list(taskInfo.keys())

    for task in allTasks:
      if basisCfg['taskRuntimeMeasurementEnabled']:
        #taskRuntimeMeasurement generally enabled - take the setting from the given configuration
        taskInfo[task]['taskRunTime'] = taskAndRunnableCfg[task]['taskRunTime']
      else:
        #taskRuntimeMeasurement generally disabled
        taskInfo[task]['taskRunTime'] = False

      #Loop over the list of runnableConfigurations
      for entry in taskInfo[task]['runnableCfgList']:
        if basisCfg['runnableRuntimeMeasurementEnabled']:
          #runnableRuntimeMeasurement generally enabled - take the setting from the given configuration
          entry[self.INDEX_ENABLED] = taskAndRunnableCfg[task]['runnables'][entry[self.INDEX_RUNNABLE]]
        else:
          #runnableRuntimeMeasurement generally disabled
          entry[self.INDEX_ENABLED] = False


  ################################################################################################################################################################
  def updateConfigFile(self, cfgFile, cfg):

    #Determine which configuration file we have in order to get the correct startString of the configurationDictionary
    if cfgFile == self.basisCfgFile:
      START_STRING = 'BasisConfig={\n'
    else:
      START_STRING = 'TaskAndRunnableConfig={\n'

    #Indexes for accessing the symbolList
    LIST_INDEX_CURLY_OPEN   = 0
    LIST_INDEX_CURLY_CLOSE  = 1
    LIST_INDEX_SQUARE_OPEN  = 2
    LIST_INDEX_SQUARE_CLOSE = 3
    LIST_INDEX_COMMA        = 4

    INDENT_WIDE = 2
    indentLevel = 1

    #Get all lines of configFile
    linesCfgFile = self.getLinesOfFile(cfgFile)
    #Delete the lines containing old configuration
    idx = 0
    #find the startLine of the dictionary
    for line in linesCfgFile:
      idx += 1
      #Remove all witheSpaces to increase the macthing probability
      if line.replace(' ','') == START_STRING:
        break

    del linesCfgFile[idx:]

    #Get the string of the configuration string
    cfgStr = str(cfg)
    #Remove all whiteSpaces and the leading '{'
    cfgStr = cfgStr.replace(' ','')
    cfgStr = cfgStr.lstrip('{')
    while len(cfgStr):
      #Set the breakLineIdx to the current lenght of the string which is the max value
      breakLineIdx = len(cfgStr)
      indexList = []
      #Look for next occurance of separationSymbol
      indexList.append(cfgStr.find('{')) # [LIST_INDEX_CURLY_OPEN]
      indexList.append(cfgStr.find('}')) # [LIST_INDEX_CURLY_CLOSE]
      indexList.append(cfgStr.find('[')) # [LIST_INDEX_SQUARE_OPEN]
      indexList.append(cfgStr.find(']')) # [LIST_INDEX_SQUARE_CLOSE]
      indexList.append(cfgStr.find(',')) # [LIST_INDEX_COMMA]

      #Set stringIndex to max value in case symbol was not found in string anymore
      for idx in range(len(indexList)):
        if -1 == indexList[idx]:
          indexList[idx] = len(cfgStr)

      #Now find the entry with the smallest index
      for idx in range(len(indexList)):
        if indexList[idx] < breakLineIdx:
          breakLineIdx = indexList[idx]
          listIdx = idx

      if (LIST_INDEX_CURLY_CLOSE == listIdx) or (LIST_INDEX_SQUARE_CLOSE == listIdx):
        #Special treatment with closing brackets:
        if 0 < indexList[listIdx]:
          #Bracket is not the very first character in the string - lineBreak shall be before
          breakLineIdx = indexList[listIdx] - 1
        elif(indexList[listIdx] + 1 == indexList[LIST_INDEX_COMMA]):
          #Next is a comma - break after the comma
          breakLineIdx = indexList[listIdx] + 1
        else:
          #Break after bracket
          breakLineIdx = indexList[listIdx]
      elif LIST_INDEX_SQUARE_OPEN == listIdx:
        #Special treatment with open square brackets '['
        #Here shall be only a lineBreak if it is directly followed by another '['
        if '[' == cfgStr[indexList[listIdx] + 1]:
          #ok do a linebreak right after the first opening square bracket
          breakLineIdx = indexList[listIdx]
        else:
          #The open square bracked is not followed by another one
          #Therefore the lineBreak shall be after the next closing sqare bracket
          # If the closing one is followed by ',' this should be even after the comma
          if(    (len(cfgStr) > indexList[LIST_INDEX_SQUARE_CLOSE]  + 1)
             and (',' == cfgStr[indexList[LIST_INDEX_SQUARE_CLOSE] + 1])
            ):
            #Next is a comma - break after the comma
            breakLineIdx = indexList[LIST_INDEX_SQUARE_CLOSE] + 1
          else:
            #Break after bracket
            breakLineIdx = indexList[LIST_INDEX_SQUARE_CLOSE]
      elif LIST_INDEX_CURLY_OPEN == listIdx:
        #Check if the very next character is a close curly bracket
        if indexList[listIdx] + 1 == indexList[LIST_INDEX_CURLY_CLOSE]:
          #Do the lineBreak after the close bracket
          breakLineIdx = indexList[LIST_INDEX_CURLY_CLOSE]

      #Create the new line to be added and append it to linesCfgFile
      newLine = cfgStr[:breakLineIdx + 1] + ' \n'
      leadingWhiteSpaces = ' ' * (indentLevel * INDENT_WIDE)
      newLine = leadingWhiteSpaces + newLine
      linesCfgFile.append(newLine)

      #Update indentLevel for next iteration - if needed
      if len(cfgStr) > breakLineIdx:
        #Still we are not at the end of the string
        if(    ('{'  == cfgStr[breakLineIdx])
            or ('['  == cfgStr[breakLineIdx])
          ):
          # We had a lineBreak on an open bracked - increase level
          indentLevel += 1
        elif len(cfgStr) > (breakLineIdx + 1):
          #Check wether the very next character is one of closing brackets
          if(    ('}'  == cfgStr[breakLineIdx + 1])
              or (']'  == cfgStr[breakLineIdx + 1])
            ):
            #Decrease indentLevel
            indentLevel -= 1

      #remove that leading part of the cfgString which has recently copied to linesCfgFile
      cfgStr = cfgStr[breakLineIdx + 1:]

    # Remove '\n' from the last line
    lastLine = linesCfgFile.pop()
    lastLine = lastLine.replace('\n', '')
    # Append the line againg
    linesCfgFile.append(lastLine)

    #Finally write all lines to file
    self.writeLinesintoFile(cfgFile, linesCfgFile)

  ######################################################################################################################################################################################
  def getRunnableGroupCfg(self, basisConfig, runnableName, defaultSetting):

    #Check whether we have runnableGroups at all
    if not len(basisConfig['runnableGroupsCfg']):
      # No runnable groups - just return the defaultSetting
      return defaultSetting
    else:
      # We have entries in the runnableGroupsCfg list
      setting = defaultSetting
      # Check whether the runnable belongs to a certain group and get the setting for the found group
      for entry in basisConfig['runnableGroupsCfg']:
        if runnableName.startswith(entry[self.IDX_RUNNABLE_GROUP_PREFIX]):
          setting = entry[self.IDX_RUNNABLE_GROUP_SETTING]
          break

      return setting

