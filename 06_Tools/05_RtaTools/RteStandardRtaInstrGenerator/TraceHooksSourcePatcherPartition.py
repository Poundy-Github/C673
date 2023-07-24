import os
import re

from InstrGeneratorBase import InstrGenBase

#################################################################################
#
#################################################################################
class TraceHooksPatcherPartition(InstrGenBase):

  # The list of all required generatorTags in the order of expected apperance
  TAG_LIST = [
    InstrGenBase.GEN_TAG_HOOK_FCT_START,
    InstrGenBase.GEN_TAG_HOOK_FCT_END,
  ]

  #The pattern for includeLines
  FILE_INCLUDE_PATTERN = '#include <{0}> \n' # {0} -> Header to be included
  #HeaderFile to be included
  FILE_NAME_STEPCOUNTER_HEADER = 'Rte_StepCounter.h'

  #The header and trailer texts for the traceHook functions and the needed tagLines for enclosing generated code
  TRACE_HOOK_HEADER = 'FUNC(void, RTE_APPL_CODE) {0}(void) \n{{\n'

  TRACE_HOOK_TRAILER = '}} /* {0} */\n'

  TRACE_HOOK_GEN_START = '  /* ' + InstrGenBase.GEN_TAG_INSTR_START + ' */\n'

  TRACE_HOOK_GEN_STOP  = '  /* ' +  InstrGenBase.GEN_TAG_INSTR_END + ' */\n\n'

  #Pattern to generate the call of the rtaAddEvent function
  CREATE_RTA_EVENT = '\n{0}RTA_v_AddEvent({1}, {2}, {3}, 0u); \n\n'  # {0} -> "Spaces", {1} ->   EventType, {2} -> GlobalID, {3} ->LocalID

  #Pattern to generate the call of the stepCounter function
  CALL_STEP_CNT_FCT_PATTERN = '\n{0}RTE_v_SetStepCounterValue({1}, (uint8){2}); \n'  # {0} -> "Spaces", {1} -> TASK_ID, {2} -> u_STEP_CNT_VALUE

  TRACE_HOOK_INSTRUMENTATION_DISABLED = '\n{0}/* For this runnable the RTA instrumentation is disabled in the configuration of the RteStandardRtaInstrGenerator! */ \n\n'   # {0} -> "Spaces"

  TRACE_HOOK_TASK_SECTION_DELIMITER = '{0}/* All traceHooks for {1}. [SECTION_{2}] ********************************************************************/ {3}'

  TRACE_HOOKS_IN_MULTIPLE_TASK_SECTION = '''

/* The traceHooks for the runnable {0} are located in the multipleTaskSection as this runnable is called from different tasks. */

'''

  MULTI__GET_CURRENT_TASK = '''  const TaskType CURRENT_TASK_ID = RTA_u_GetCurrentTask();
'''

  MULTI__IF_STATEMENT = '''  {0}(CURRENT_TASK_ID == {1})
  {{
'''

  MULTI__TRAILING_ELSE = '''  }
  else
  {
    /* Nothing to do */
  }
'''

  MULTI_TASK_SECTION_DELIMITER = '{0}/* All traceHooks for runnables called from different tasks. [SECTION_{1}] ********************************************************************/ {2}'


  #The hook suffixes
  HOOK_SUFFIX_START =  '_Start'
  HOOK_SUFFIX_RETURN = '_Return'

  #Indexes of the one dimensonal list 'traceHookStartEndPos'
  INDEX_TRACE_START      = 0
  INDEX_TRACE_START_TAG  = 1
  INDEX_TRACE_END_TAG    = 2
  INDEX_TRACE_END        = 3

  #The files to be updated
  fileHooksSource   = ''

  #The lines of relevant files
  linesHooksSource  = []

  #This list used to store all lines from the start of hookSection until the end of the file of the old version of the <PARTITION_NAME>_Trace_Hooks.c file.
  linesStartHookSectionToEOF = []


  #Initialise the class################################################################################################################################################################################
  def __init__(self, partitionName, outputFile):

    template = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/Rte_Trace_Hooks_Partition_Template.c'

    self.checkForValidOutputFileAndReadInAllLines(outputFile, template)

    #Store the partition name
    self.myPartition = partitionName


  #####################################################################################################################################################################################################
  #This function does the following
  # - store the provided outputFile (absPath + Name)
  # - check whether a file of this name already exist
  # - if there is such a files, check whether it contains all requested tags (according tagList)
  # - in case anything is ok just read all the lines of the file
  # - in case the outputFile is not availabe or it is corrupt then the lines of the templateFile will be read instead
  #####################################################################################################################################################################################################
  def checkForValidOutputFileAndReadInAllLines(self, outputFile, templateFile):
    useTemplateFile = True
    listIdx = 0

    #Store the outputFile
    self.fileHooksSource = outputFile

    #Get all lines of the outputFile
    self.linesHooksSource = self.getLinesOfFile(self.fileHooksSource)

    #Check whether the file contains all needed tags in the right order
    for line in self.linesHooksSource:
      #Find next tag
      if -1 != line.find(self.TAG_LIST[listIdx]):
        #Ok - next tag found just increment index
        listIdx += 1
        #Check whether this was already the last index to be found
        if len(self.TAG_LIST) <= listIdx:
          # ok, all tags found
          useTemplateFile = False
          break

    if useTemplateFile:
      print ('*****************************************Use templateSource!!!!!!!!!!!!!!!!!!!!!!!!!!')
      #File does not exist - or at least one required generatorTag is missing, the old file cannot be updated.
      #Take the templateFile instead
      self.linesHooksSource = self.getLinesOfFile(templateFile)

  #####################################################################################################################################################################################################
  def handleHeaderIncludesForAdditionalFeatures(self, additionalFeatureCfg):

    allIncludeFiles         = []
    lineNoToBeDeleted       = []
    linesToBeAdded          = []
    linesHooksSourePureCode = []
    insertIdx               = 0


    if additionalFeatureCfg['stepCountersEnabled']:
      allIncludeFiles.append([self.FILE_NAME_STEPCOUNTER_HEADER, True])
    else:
      allIncludeFiles.append([self.FILE_NAME_STEPCOUNTER_HEADER, False])

    self.getLinesOfPureCode(self.linesHooksSource, linesHooksSourePureCode)

    #determine lineNumber to insert the new includes
    # They shall be included before the very first include
    for insertIdx in range(len(linesHooksSourePureCode)):
      cleanedLine = linesHooksSourePureCode[insertIdx].lstrip()
      if cleanedLine.startswith('#include'):
        #Ok, first include found - terminate the loop immediately
        break

    #Get all the lines to be deleted
    for includeFile in allIncludeFiles:
      lineNo = 0
      query = self.FILE_INCLUDE_PATTERN.format(includeFile[0]).replace(' ','')
      for lineNo in range(len(linesHooksSourePureCode)):

        if query == linesHooksSourePureCode[lineNo].replace(' ',''):
          #OK, line with fileInclude found - check whether this include shall be removed
          if not includeFile[1]:
            #OK - shall be removed - insert lineIndex to the deleteList (at the beginning)
            lineNoToBeDeleted.append(lineNo)
          break
      else:
        #Line of include for current file not found - check whether we need it
        if includeFile[1]:
          #It's needed - add the corresponding line to the addList
          linesToBeAdded.append(self.FILE_INCLUDE_PATTERN.format(includeFile[0]))

    #Sort the list in decending order, as we have to start deleting lines from the end
    lineNoToBeDeleted.sort(reverse=True)

    #Delete all includes which are not needed anymore
    for lineNo in lineNoToBeDeleted:
      self.linesHooksSource.pop(lineNo)

    #Add all required includeLines
    for line in linesToBeAdded:
      self.linesHooksSource.insert(insertIdx, line)


  #####################################################################################################################################################################################################
  def updateTraceHooksSource(self, taskList, taskInfo, runnablesMultipeTasks, additionalFeatureCfg):
    #Have the rteTraceHook source file updated
    self.updateTraceHooksSection(taskList, taskInfo, runnablesMultipeTasks, additionalFeatureCfg)
    #Add or remove includes according current activated additionalFeatures
    self.handleHeaderIncludesForAdditionalFeatures(additionalFeatureCfg)

    #All the updates are done. Now write all the lines back into the file
    self.writeLinesintoFile(self.fileHooksSource, self.linesHooksSource)


  #####################################################################################################################################################################################################
  def updateTraceHooksSection(self, taskList, taskInfo, runnablesMultipeTasks, additionalFeatureCfg):
    #First copy that lines below the generatorStartTag to a seperate list and remove them from origin lines
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_HOOK_FCT_START, self.linesHooksSource, self.linesStartHookSectionToEOF)

    #Now build the section below the startTag from new.
    #Loop over all tasks and update/create related hooks
    for entry in taskList:
      #Get the related entry from taskInfo dict
      taskSetup = taskInfo[entry]
      #If this task is in our partition
      if self.myPartition == taskSetup['partitionName']:
        #Add the startDelimiter (just a commentline) indicating the beginning of all hooks belonging to the current task
        self.linesHooksSource.append(self.TRACE_HOOK_TASK_SECTION_DELIMITER.format('\n', entry, 'START', '\n' ))

        for runnableCfg in taskSetup['runnableCfgList']:

          if runnableCfg[self.INDEX_MULTI_TASKS]:
            #MultipleTaskFlag is set. The traceHooks have to be generated in the multiTaskSection
            #Just add a comment to the file
            self.linesHooksSource.append(self.TRACE_HOOKS_IN_MULTIPLE_TASK_SECTION.format(runnableCfg[self.INDEX_RUNNABLE] ))
          else:
            #Check whether the current StartHook is already in the file
            hookStartEndPos = [0, 0, 0, 0]
            if self.findTraceHookInSourceFile(runnableCfg, True, hookStartEndPos):
              # OK, related traceHook found - just update it
              self.updateTraceHook(runnableCfg, taskSetup['globalID'], hookStartEndPos, additionalFeatureCfg, taskSetup['taskName'])
            else:
              #Create new startHook
              self.createNewTraceHook(runnableCfg, taskSetup['globalID'], additionalFeatureCfg, True, taskSetup['taskName'])

            #Check whether the current ReturnHook is already in the file
            if self.findTraceHookInSourceFile(runnableCfg, False, hookStartEndPos):
              # OK, related traceHook found - just update it
              self.updateTraceHook(runnableCfg, taskSetup['globalID'], hookStartEndPos, additionalFeatureCfg, taskSetup['taskName'])
            else:
              #Create new returnHook
              self.createNewTraceHook(runnableCfg, taskSetup['globalID'], additionalFeatureCfg, False, taskSetup['taskName'])

        #Add the endDelimiter (just a commentline) indicating the beginning of all hooks belonging to the current task
        self.linesHooksSource.append(self.TRACE_HOOK_TASK_SECTION_DELIMITER.format('', entry, 'END', '\n\n\n' ))

    #Add the multipleTaskSection
    self.createMultipleTaskSection(taskInfo, runnablesMultipeTasks, additionalFeatureCfg)

    # Finally add all the lines  below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_HOOK_FCT_END, self.linesStartHookSectionToEOF, self.linesHooksSource)

  #####################################################################################################################################################################################################
  def createMultipleTaskSection(self, taskInfo, runnablesMultipeTasks, additionalFeatureCfg):

    #Add the section start delimiter
    self.linesHooksSource.append(self.MULTI_TASK_SECTION_DELIMITER.format('\n', 'START', '\n'))

    #Loop over all runnables and create/update the hooks
    allRunnables = list(runnablesMultipeTasks.keys())
    for runnable in allRunnables:
      #Check if targetPatition is our partition
      if self.myPartition == runnablesMultipeTasks[runnable]['targetPartition']:
        #Check whether the current StartHook is already in the file
        hookStartEndPos = [0, 0, 0, 0]
        allTaskSettings = list(runnablesMultipeTasks[runnable]['taskSettings'].keys())
        #In all the tasks the runnable has the same hookFuntion therefore take just the very first setting to find the related hook in the traceHookFile
        if self.findTraceHookInSourceFile(runnablesMultipeTasks[runnable]['taskSettings'][allTaskSettings[0]], True, hookStartEndPos):
          # OK, related traceHook found - just update it
          self.updateTraceHookMultiTask(runnablesMultipeTasks[runnable]['taskSettings'], taskInfo, hookStartEndPos, additionalFeatureCfg)
        else:
          #Create new startHook
          self.createNewTraceHookMultiTask(runnablesMultipeTasks[runnable]['taskSettings'], taskInfo, additionalFeatureCfg, True)

        #Check whether the current ReturnHook is already in the file
        if self.findTraceHookInSourceFile(runnablesMultipeTasks[runnable]['taskSettings'][allTaskSettings[0]], False, hookStartEndPos):
          # OK, related traceHook found - just update it
          self.updateTraceHookMultiTask(runnablesMultipeTasks[runnable]['taskSettings'], taskInfo, hookStartEndPos, additionalFeatureCfg)
        else:
          #Create new returnHook
          self.createNewTraceHookMultiTask(runnablesMultipeTasks[runnable]['taskSettings'], taskInfo, additionalFeatureCfg, False)

    #Add the section end delimiter
    self.linesHooksSource.append(self.MULTI_TASK_SECTION_DELIMITER.format('\n', 'END', '\n\n'))


  #####################################################################################################################################################################################################
  def findTraceHookInSourceFile(self, hookInfo, isStartHook, hookStartEndPos):

    #The queries for  the hooks without any whiteSpaces (in order to get the correct machtes independent of whiteSpaces which may occure in the line)
    QUERY_START_HOOK  = 'FUNC(void,RTE_APPL_CODE){0}{1}(void)'.format(hookInfo[self.INDEX_HOOK], self.HOOK_SUFFIX_START)  # @UnusedVariable
    QUERY_RETURN_HOOK = 'FUNC(void,RTE_APPL_CODE){0}{1}(void)'.format(hookInfo[self.INDEX_HOOK], self.HOOK_SUFFIX_RETURN)  # @UnusedVariable

    PATTERN_HOOK_BEGIN = r' *FUNC *\( *void, *RTE_APPL_CODE *\) *([\S]*) *\( *void *\)'
    PATTERN_HOOK_END   = r' *\} */\* *[\S]* *\*/'

    if isStartHook:
      SUFFIX = self.HOOK_SUFFIX_START
    else:
      SUFFIX = self.HOOK_SUFFIX_RETURN

    startFound = False
    idx           = 0

    #Reset the hookStartEndPos
    hookStartEndPos[self.INDEX_TRACE_START]     = 0
    hookStartEndPos[self.INDEX_TRACE_START_TAG] = 0
    hookStartEndPos[self.INDEX_TRACE_END_TAG]   = 0
    hookStartEndPos[self.INDEX_TRACE_END]       = 0

    for line in self.linesStartHookSectionToEOF:
      if not startFound:
        #Look for the beginning of the next hookFct
        if re.match(PATTERN_HOOK_BEGIN, line) and -1 != line.find(hookInfo[self.INDEX_HOOK] + SUFFIX):
          #Desired traceHook found, store current index
          hookStartEndPos[self.INDEX_TRACE_START] = idx
          startFound = True
      else:
        #Currently we are in a hookFunction
        if -1 != line.find(self.GEN_TAG_INSTR_START):
          # OK, we found the generatorTag indicating the starting point of rtaInstrumentation within the hookFct - save current index
          hookStartEndPos[self.INDEX_TRACE_START_TAG] = idx
        elif -1 != line.find(self.GEN_TAG_INSTR_END):
          # OK, we found the generatorTag indicating the the end point of rtaInstrumentation within the hookFct - save current index
          hookStartEndPos[self.INDEX_TRACE_END_TAG] = idx
        elif re.match(PATTERN_HOOK_END, line) and -1 != line.find(hookInfo[self.INDEX_HOOK] + SUFFIX):
          # OK, we found the end of the hookFct - save current index
          hookStartEndPos[self.INDEX_TRACE_END] = idx
          break

      #Finally increment index
      idx = idx + 1

    #Check whether we found all required tags in the function
    if hookStartEndPos[self.INDEX_TRACE_START] and hookStartEndPos[self.INDEX_TRACE_START_TAG] and hookStartEndPos[self.INDEX_TRACE_END_TAG] and hookStartEndPos[self.INDEX_TRACE_END]:
      return True
    else:
      #Either we did not find the desired function or the function does not have the expected format
      #Return False in order to force newly creation of the function
      return False

  #####################################################################################################################################################################################################
  def updateTraceHook(self, hookInfo, globalID, hookStartEndPos, additionalFeatureCfg, taskName):

    #For easy access - copy indexes from
    LINE_FUNC_START = hookStartEndPos[self.INDEX_TRACE_START]
    LINE_START_TAG  = hookStartEndPos[self.INDEX_TRACE_START_TAG]
    LINE_END_TAG    = hookStartEndPos[self.INDEX_TRACE_END_TAG]
    LINE_FUNC_END   = hookStartEndPos[self.INDEX_TRACE_END]

    stepCntIntrumentation = ''

    #Determine whether it is an start or an end-hook
    if -1 != self.linesStartHookSectionToEOF[LINE_FUNC_START].find(hookInfo[self.INDEX_HOOK] + self.HOOK_SUFFIX_START):
      # -> startHook
      RTA_EVENT            = 'RTA_EVT_ALGOSTART'
      TRAILING_EMPTY_LINES = '\n'

      if additionalFeatureCfg['stepCountersEnabled']:
        stepCntIntrumentation = self.CALL_STEP_CNT_FCT_PATTERN.format(' '*2, taskName, hookInfo[self.INDEX_STEP_CNT_ID])
    else:
      # ->endHook
      RTA_EVENT            = 'RTA_EVT_ALGOEND'
      TRAILING_EMPTY_LINES = '\n\n\n'

    #Check whether rtaInstrumentation shall be done for this hook or not
    if hookInfo[self.INDEX_ENABLED]:
      # -> Create related rtaEvent
      RTA_INSTRUMENTATION = self.CREATE_RTA_EVENT.format(' '*2, RTA_EVENT, globalID, hookInfo[self.INDEX_LOCAL_ID])
    else:
      # no rtaEvent - just a comment
      RTA_INSTRUMENTATION = self.TRACE_HOOK_INSTRUMENTATION_DISABLED.format(' '*2)

    #Copy the first part of the function (until the GeneratorStartTag) into the hookSoure
    self.linesHooksSource.extend(self.linesStartHookSectionToEOF[LINE_FUNC_START:LINE_START_TAG + 1])
    #Add the stepCounterInstrumentation
    self.linesHooksSource.append(stepCntIntrumentation)
    #Add the rtaInstrumentation line
    self.linesHooksSource.append(RTA_INSTRUMENTATION)
    #Copy the rest of the function (from GeneratorEndTag until the end of the function into the hookSoure
    self.linesHooksSource.extend(self.linesStartHookSectionToEOF[LINE_END_TAG:LINE_FUNC_END + 1])
    #Finally add empty lines
    self.linesHooksSource.append(TRAILING_EMPTY_LINES)

  #####################################################################################################################################################################################################
  def createNewTraceHook(self, hookInfo, globalID, additionalFeatureCfg, isStartHook, taskName):

    stepCntIntrumentation = ''

    #Check whether we have to generate a start or returnHook
    if isStartHook:
      # -> startHook
      SUFFIX               = self.HOOK_SUFFIX_START
      RTA_EVENT            = 'RTA_EVT_ALGOSTART'
      TRAILING_EMPTY_LINES = '\n'
      if additionalFeatureCfg['stepCountersEnabled']:
        stepCntIntrumentation = self.CALL_STEP_CNT_FCT_PATTERN.format(' '*2, taskName, hookInfo[self.INDEX_STEP_CNT_ID])
    else:
      # ->endHook
      SUFFIX               = self.HOOK_SUFFIX_RETURN
      RTA_EVENT            = 'RTA_EVT_ALGOEND'
      TRAILING_EMPTY_LINES = '\n\n\n'

    #Check whether rtaInstrumentation shall be done for this hook or not
    if hookInfo[self.INDEX_ENABLED]:
      # -> Create related rtaEvent
      RTA_INSTRUMENTATION = self.CREATE_RTA_EVENT.format(' '*2, RTA_EVENT, globalID, hookInfo[self.INDEX_LOCAL_ID])
    else:
      # no rtaEvent - just a comment
      RTA_INSTRUMENTATION = self.TRACE_HOOK_INSTRUMENTATION_DISABLED.format(' '*2)

    #Generate a list of all textParts to be written
    textList = [ \
      self.TRACE_HOOK_HEADER.format(hookInfo[self.INDEX_HOOK] + SUFFIX),
      self.TRACE_HOOK_GEN_START,
      stepCntIntrumentation,
      RTA_INSTRUMENTATION,
      self.TRACE_HOOK_GEN_STOP,
      self.TRACE_HOOK_TRAILER.format(hookInfo[self.INDEX_HOOK] + SUFFIX),
      TRAILING_EMPTY_LINES,
     ]

    for entry in  textList:
      #Add the next part to the end of the linesHooksSource
      self.linesHooksSource.append(entry)

  #####################################################################################################################################################################################################
  def updateTraceHookMultiTask(self, runnableDict, taskInfo, hookStartEndPos, additionalFeatureCfg):

    #For easy access - copy indexes from
    LINE_FUNC_START = hookStartEndPos[self.INDEX_TRACE_START]
    LINE_START_TAG  = hookStartEndPos[self.INDEX_TRACE_START_TAG]
    LINE_END_TAG    = hookStartEndPos[self.INDEX_TRACE_END_TAG]
    LINE_FUNC_END   = hookStartEndPos[self.INDEX_TRACE_END]

    allInstrLines = []

    #Get all tasks in which this runnable is called
    allTasks = list(runnableDict.keys())
    #Just take the first entry to get the hookName (the hookname is equal in all entries
    hook = runnableDict[allTasks[0]][self.INDEX_HOOK]

    isStartHook = False
    #Determine whether it is an start or an end-hook
    if -1 != self.linesStartHookSectionToEOF[LINE_FUNC_START].find(hook + self.HOOK_SUFFIX_START):
      # -> startHook
      RTA_EVENT            = 'RTA_EVT_ALGOSTART'
      TRAILING_EMPTY_LINES = '\n'
      isStartHook = True
    else:
      # ->endHook
      RTA_EVENT            = 'RTA_EVT_ALGOEND'
      TRAILING_EMPTY_LINES = '\n\n\n'

    #Check whether we have at least one task in which the instrumentation is enabled
    instrEnabled = False
    if isStartHook and additionalFeatureCfg['stepCountersEnabled']:
      instrEnabled = True
    else:
      for task in allTasks:
        if runnableDict[task][self.INDEX_ENABLED]:
          instrEnabled = True

    if instrEnabled:
      allInstrLines.append(self.MULTI__GET_CURRENT_TASK)
      #Generate a hookFunction with RTA instrumentation - at least for one task
      #Add one if/else if statement per key in dict
      ifText = 'if'
      for task in allTasks:
        stepCntIntrumentation = ''
        #Create the stepCounterInstrumentation if it is enabled and we have a startHook
        if isStartHook and additionalFeatureCfg['stepCountersEnabled']:
          stepCntIntrumentation = self.CALL_STEP_CNT_FCT_PATTERN.format(' '*4, taskInfo[task]['taskName'], runnableDict[task][self.INDEX_STEP_CNT_ID])

        #Check whether rtaInstrumentation shall be done for the hook in current task
        if runnableDict[task][self.INDEX_ENABLED]:
          # -> Create related rtaEvent
          RTA_INSTRUMENTATION = self.CREATE_RTA_EVENT.format(' '*4, RTA_EVENT, taskInfo[task]['globalID'], runnableDict[task][self.INDEX_LOCAL_ID])
        else:
          # no rtaEvent - just a comment
          RTA_INSTRUMENTATION = self.TRACE_HOOK_INSTRUMENTATION_DISABLED.format(' '*4) + '\n'

        allInstrLines.append(self.MULTI__IF_STATEMENT.format(ifText, task))
        allInstrLines.append(stepCntIntrumentation)
        allInstrLines.append(RTA_INSTRUMENTATION)
        ifText = '}\n  else if'
      allInstrLines.append(self.MULTI__TRAILING_ELSE)

    else:
      #RTA instrumentation is completely disabled for this runnable in all tasks
      allInstrLines.append('  ' + self.TRACE_HOOK_INSTRUMENTATION_DISABLED.format(' '*4) + '\n')


    #Copy the first part of the function (until the GeneratorStartTag) into the hookSoure
    self.linesHooksSource.extend(self.linesStartHookSectionToEOF[LINE_FUNC_START:LINE_START_TAG + 1])
    #Add the rtaInstrumentation line
    self.linesHooksSource.extend(allInstrLines)
    #Copy the rest of the function (from GeneratorEndTag until the end of the function into the hookSoure
    self.linesHooksSource.extend(self.linesStartHookSectionToEOF[LINE_END_TAG:LINE_FUNC_END + 1])
    #Finally add empty lines
    self.linesHooksSource.append(TRAILING_EMPTY_LINES)

  #####################################################################################################################################################################################################
  def createNewTraceHookMultiTask(self, runnableDict, taskInfo, additionalFeatureCfg, isStartHook):

    #Check whether we have to generate a start or returnHook
    if isStartHook:
      # -> startHook
      SUFFIX               = self.HOOK_SUFFIX_START
      RTA_EVENT            = 'RTA_EVT_ALGOSTART'
      TRAILING_EMPTY_LINES = '\n'
    else:
      # ->endHook
      SUFFIX               = self.HOOK_SUFFIX_RETURN
      RTA_EVENT            = 'RTA_EVT_ALGOEND'
      TRAILING_EMPTY_LINES = '\n\n\n'

    #Get all tasks in which this runnable is called
    allTasks = list(runnableDict.keys())
    #Just take the first entry to get the hookName (the hookname is equal in all entries
    hook = runnableDict[allTasks[0]][self.INDEX_HOOK]

    #Check whether we have at least one task in which the instrumentation is enabled
    instrEnabled = False
    if isStartHook and additionalFeatureCfg['stepCountersEnabled']:
      instrEnabled = True
    else:
      for task in allTasks:
        if runnableDict[task][self.INDEX_ENABLED]:
          instrEnabled = True

    if instrEnabled:
      #Generate a hookFunction with RTA instrumentation - at least for one task
      #Generate a list of all textParts of the header to be written
      textListHeader = [
        self.TRACE_HOOK_HEADER.format(hook + SUFFIX),
        self.TRACE_HOOK_GEN_START,
        self.MULTI__GET_CURRENT_TASK,
       ]

      #Generate a list of all textParts of the trailer to be written
      textListTrailer = [
        self.MULTI__TRAILING_ELSE,
        self.TRACE_HOOK_GEN_STOP,
        self.TRACE_HOOK_TRAILER.format(hook + SUFFIX),
        TRAILING_EMPTY_LINES,
       ]

      #Write all headerLines
      for entry in  textListHeader:
        #Add the next part to the end of the linesHooksSource
        self.linesHooksSource.append(entry)

      #Add one if/else if statement per key in dict
      ifText = 'if'
      for task in allTasks:
        stepCntIntrumentation = ''
        #Create the stepCounterInstrumentation if it is enabled and we have a startHook
        if isStartHook and additionalFeatureCfg['stepCountersEnabled']:
          stepCntIntrumentation = self.CALL_STEP_CNT_FCT_PATTERN.format(' '*4, taskInfo[task]['taskName'], runnableDict[task][self.INDEX_STEP_CNT_ID])

        #Check whether rtaInstrumentation shall be done for the hook in current task
        if runnableDict[task][self.INDEX_ENABLED]:
          # -> Create related rtaEvent
          RTA_INSTRUMENTATION = self.CREATE_RTA_EVENT.format(' '*4, RTA_EVENT, taskInfo[task]['globalID'], runnableDict[task][self.INDEX_LOCAL_ID])
        else:
          # no rtaEvent - just a comment
          RTA_INSTRUMENTATION = self.TRACE_HOOK_INSTRUMENTATION_DISABLED.format(' '*4) + '\n'

        self.linesHooksSource.append(self.MULTI__IF_STATEMENT.format(ifText, task))
        self.linesHooksSource.append(stepCntIntrumentation)
        self.linesHooksSource.append(RTA_INSTRUMENTATION)
        ifText = '}\n  else if'


      #Write all TrailerLines
      for entry in  textListTrailer:
        #Add the next part to the end of the linesHooksSource
        self.linesHooksSource.append(entry)

    else:
      #RTA instrumentation is completely disabled for this runnable in all tasks
      #Generate a list of all textParts to be written
      textList = [
        self.TRACE_HOOK_HEADER.format(hook + SUFFIX),
        self.TRACE_HOOK_GEN_START,
        self.TRACE_HOOK_INSTRUMENTATION_DISABLED.format(' '*2) + '\n',
        self.TRACE_HOOK_GEN_STOP,
        self.TRACE_HOOK_TRAILER.format(hook + SUFFIX),
        TRAILING_EMPTY_LINES,
       ]

      for entry in  textList:
        #Add the next part to the end of the linesHooksSource
        self.linesHooksSource.append(entry)
