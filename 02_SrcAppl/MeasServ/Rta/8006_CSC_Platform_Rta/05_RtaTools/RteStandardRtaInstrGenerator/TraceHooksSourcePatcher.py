import os

from TraceHooksSourcePatcherPartition import TraceHooksPatcherPartition

#################################################################################
#
#################################################################################
class TraceHooksSourcePatcher(TraceHooksPatcherPartition):

  # The list of all required generatorTags in the order of expected apperance
  TAG_LIST = [
    TraceHooksPatcherPartition.GEN_TAG_TASK_CFG_START,
    TraceHooksPatcherPartition.GEN_TAG_TASK_CFG_END,
    TraceHooksPatcherPartition.GEN_TAG_TASK_LUT_START,
    TraceHooksPatcherPartition.GEN_TAG_TASK_LUT_END,
    TraceHooksPatcherPartition.GEN_TAG_TASK_CNT_START,
    TraceHooksPatcherPartition.GEN_TAG_TASK_CNT_END,
    TraceHooksPatcherPartition.GEN_TAG_FRAMEWORK_HOOKS_START,
    TraceHooksPatcherPartition.GEN_TAG_FRAMEWORK_HOOKS_END,
    TraceHooksPatcherPartition.GEN_TAG_HOOK_FCT_START,
    TraceHooksPatcherPartition.GEN_TAG_HOOK_FCT_END,
  ]

  #All the strings for typedef of  RTE_TraceHooksTaskCfg
  TASK_CFG_MEMBER_TASK_ID                   = 'taskId'
  TASK_CFG_MEMBER_GLOBAL_ID                 = 'u_globalId'
  TASK_CFG_MEMBER_LOCAL_ID                  = 'u_localId'
  TASK_CFG_MEMBER_TASK_RUNNTIME_ENABLED     = 'b_taskRuntimeEnabled'
  TASK_CFG_MEMBER_IS_EXTENDED_TASK          = 'b_isExtendedTask'

  #The text for typedefinition RTE_TraceHooksTaskCfg
  TYPEDEF_TRACE_HOOK_TASK_CONFIG = \
'''typedef struct
{{
  TaskType {0};
  uint8    {1};
  uint8    {2};
  boolean  {3};
  boolean  {4};
}}RTE_TraceHooksTaskCfg;
'''.format(TASK_CFG_MEMBER_TASK_ID,
           TASK_CFG_MEMBER_GLOBAL_ID,
           TASK_CFG_MEMBER_LOCAL_ID,
           TASK_CFG_MEMBER_TASK_RUNNTIME_ENABLED,
           TASK_CFG_MEMBER_IS_EXTENDED_TASK)

  #The commentLine for the TaskCfgLut
  TASK_CFG_LUT_COMMENT_LINE = '  /* {0}, {1}, {2}, {3}, {4} */\n'

  #The text for the define number of relevant tasks
  DEFINE_NO_RELEVANT_TASKS = '#define RTE_NO_RELEVANT_TASKS ({0})'

  #The header and trailer texts for the a_TASK_CFG_LUT
  TASK_CFG_LUT_HEADER = \
'''static const RTE_TraceHooksTaskCfg a_TASK_CFG_LUT[RTE_NO_RELEVANT_TASKS] =
{
'''

  TASK_CFG_LUT_TRAILER = \
'''};
'''

  PATTERN_TASK_CFG_LUT_ENTRY = \
'''  {{(TaskType){0}, (uint8){1}, (uint8){2}, {3}, {4}}}{5}
'''


  #The texts for the taskCylceCounterArray
  TASK_CYCLE_CNT_HEADER = \
'''static uint32 a_TaskCycleCnt[RTE_NO_RELEVANT_TASKS] =
{
'''

  TASK_CYCLE_CNT_TRAILER = \
'''};
'''

  PATTERN_TASK_CYCLE_CNT_ENTRY = \
'''  (uint32)0x0{0}
'''

  #All the frameworkHooks
  #Texts for Rte_Task_Dispatch
  DISPATCH_HEADER = \
'''FUNC(void, RTE_APPL_CODE) Rte_Task_Dispatch(TaskType task)
'''

  DISPATCH_TRAILER = \
'''} /* Rte_Task_Dispatch */
'''

  DISPATCH_BODY_ENABLED = \
'''  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */
  {
    uint8 u_idx = 0;
    /* Loop over TaskCfgLut and look for that entry for current task */
    for (u_idx = 0; RTE_NO_RELEVANT_TASKS > u_idx; u_idx++)
    {
      if(a_TASK_CFG_LUT[u_idx].taskId == task)
      {
        if(b_FALSE == a_TASK_CFG_LUT[u_idx].b_isExtendedTask)
        {
          /* Increment taskCycleCounter */
          a_TaskCycleCnt[u_idx]++;

          if(b_TRUE  == a_TASK_CFG_LUT[u_idx].b_taskRuntimeEnabled)
          {
            /* TaskRuntime measurement is enable and it is not an extended task -> generate a RtaStartEvent! */
            RTA_v_AddEvent(RTA_EVT_ALGOSTART, a_TASK_CFG_LUT[u_idx].u_globalId, a_TASK_CFG_LUT[u_idx].u_localId, a_TaskCycleCnt[u_idx]);
          }
        }
        /* Related entry found, terminate the loop immediately */
        break;
      }
    }
  }
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */
'''

  DISPATCH_DISABLED = \
'''  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */
  {
    uint8 u_idx = 0;
    /* Loop over TaskCfgLut and look for that entry for current task */
    for (u_idx = 0; RTE_NO_RELEVANT_TASKS > u_idx; u_idx++)
    {
      if(a_TASK_CFG_LUT[u_idx].taskId == task)
      {
        if(b_FALSE == a_TASK_CFG_LUT[u_idx].b_isExtendedTask)
        {
          /* Increment taskCycleCounter */
          a_TaskCycleCnt[u_idx]++;

          /* ***** RTA instrumentation disabled in configuration of RteStandardRtaInstrGenerator ***** */
        }
        /* Related entry found, terminate the loop immediately */
        break;
      }
    }
  }
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */
'''

  #Texts for Rte_Task_EndHook
  #Note: These texts are for Tresos as rteGenerator. In case we have daVinci these texts will be modified in the initRoutine (different functionName! ).
  END_HOOK_HEADER = \
'''FUNC(void, RTE_APPL_CODE) Rte_Task_EndHook(TaskType task)
'''

  END_HOOK_TRAILER = \
'''} /* Rte_Task_EndHook */
'''

  END_HOOK_BODY_ENABLED = \
'''  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */
  {
    uint8 u_idx = 0;
    /* Loop over TaskCfgLut and look for the entry belonging to current task */
    for (u_idx = 0; RTE_NO_RELEVANT_TASKS > u_idx; u_idx++)
    {
      if(a_TASK_CFG_LUT[u_idx].taskId == task)
      {
        if(  (b_TRUE  == a_TASK_CFG_LUT[u_idx].b_taskRuntimeEnabled)
           &&(b_FALSE == a_TASK_CFG_LUT[u_idx].b_isExtendedTask    )
          )
        {
          /* TaskRuntime measurement is enable and it is not an extended task -> generate a RtaEndEvent! */
          RTA_v_AddEvent(RTA_EVT_ALGOEND, a_TASK_CFG_LUT[u_idx].u_globalId, a_TASK_CFG_LUT[u_idx].u_localId, (uint8)a_TaskCycleCnt[u_idx]);
        }
        /* Related entry found, terminate the loop immediately */
        break;
      }
    }
  }
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */
'''

  END_HOOK_DISABLED = \
'''  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* ***** RTA instrumentation disabled in configuration of RteStandardRtaInstrGenerator ***** */

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */
'''

  #Texts for Rte_Task_WaitEventRet
  WAIT_EVENT_RETURN_HEADER = \
'''FUNC(void, RTE_APPL_CODE) Rte_Task_WaitEventRet(TaskType task, EventMaskType ev)
'''

  WAIT_EVENT_RETURN_TRAILER = \
'''} /* Rte_Task_WaitEventRet */
'''

  WAIT_EVENT_RETURN_BODY_ENABLED = \
'''  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */
  {
    uint8 u_idx = 0;
    /* Loop over TaskCfgLut and look for that entry for current task */
    for (u_idx = 0; RTE_NO_RELEVANT_TASKS > u_idx; u_idx++)
    {
      if(a_TASK_CFG_LUT[u_idx].taskId == task)
      {
        /* Increment taskCycleCounter */
        a_TaskCycleCnt[u_idx]++;
        if(b_TRUE  == a_TASK_CFG_LUT[u_idx].b_taskRuntimeEnabled)
        {
          /* TaskRuntime measurement is enable and it is not an extended task -> generate a RtaStartEvent! */
          RTA_v_AddEvent(RTA_EVT_ALGOSTART, a_TASK_CFG_LUT[u_idx].u_globalId, a_TASK_CFG_LUT[u_idx].u_localId, (uint8)a_TaskCycleCnt[u_idx]);
        }
        /* Related entry found, terminate the loop immediately */
        break;
      }
    }
  }
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */
'''

  WAIT_EVENT_RETURN_DISABLED = \
'''  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */
  {
    uint8 u_idx = 0;
    /* Loop over TaskCfgLut and look for that entry for current task */
    for (u_idx = 0; RTE_NO_RELEVANT_TASKS > u_idx; u_idx++)
    {
      if(a_TASK_CFG_LUT[u_idx].taskId == task)
      {
        /* Increment taskCycleCounter */
        a_TaskCycleCnt[u_idx]++ ;

        /* ***** RTA instrumentation disabled in configuration of RteStandardRtaInstrGenerator ***** */

        /* Related entry found, terminate the loop immediately */
        break;
      }
    }
  }
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */
'''

  #Texts for Rte_Task_WaitEvent
  WAIT_EVENT_HEADER = \
'''FUNC(void, RTE_APPL_CODE) Rte_Task_WaitEvent(TaskType task, EventMaskType ev)
'''

  WAIT_EVENT_TRAILER = \
'''} /* Rte_Task_WaitEvent */
'''

  WAIT_EVENT_BODY_ENABLED = \
'''  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */
  {
    uint8 u_idx = 0;
    /* Loop over TaskCfgLut and look for that entry for current task */
    for (u_idx = 0; RTE_NO_RELEVANT_TASKS > u_idx; u_idx++)
    {
      if(a_TASK_CFG_LUT[u_idx].taskId == task)
      {
        if(b_TRUE  == a_TASK_CFG_LUT[u_idx].b_taskRuntimeEnabled)
        {
          /* TaskRuntime measurement is enable and it is not an extended task -> generate a RtaEndEvent! */
          RTA_v_AddEvent(RTA_EVT_ALGOEND, a_TASK_CFG_LUT[u_idx].u_globalId, a_TASK_CFG_LUT[u_idx].u_localId, (uint8)a_TaskCycleCnt[u_idx]);
        }
        /* Related entry found, terminate the loop immediately */
        break;
      }
    }
  }
  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */
'''

  WAIT_EVENT_DISABLED = \
'''  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___ */

  /* ***** RTA instrumentation disabled in configuration of RteStandardRtaInstrGenerator ***** */

  /* ___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___ */
'''

  #The framework HookDictionaries
  Dispatch_Hook = {
    'header'        : DISPATCH_HEADER,
    'trailer'       : DISPATCH_TRAILER,
    'bodyEnabled'   : DISPATCH_BODY_ENABLED,
    'bodyDisabled'  : DISPATCH_DISABLED,
  }

  End_Hook = {
    'header'        : END_HOOK_HEADER,
    'trailer'       : END_HOOK_TRAILER,
    'bodyEnabled'   : END_HOOK_BODY_ENABLED,
    'bodyDisabled'  : END_HOOK_DISABLED,
  }

  WaitEventReturn_Hook = {
    'header'        : WAIT_EVENT_RETURN_HEADER,
    'trailer'       : WAIT_EVENT_RETURN_TRAILER,
    'bodyEnabled'   : WAIT_EVENT_RETURN_BODY_ENABLED,
    'bodyDisabled'  : WAIT_EVENT_RETURN_DISABLED,
  }

  WaitEvent_Hook = {
    'header'        : WAIT_EVENT_HEADER,
    'trailer'       : WAIT_EVENT_TRAILER,
    'bodyEnabled'   : WAIT_EVENT_BODY_ENABLED,
    'bodyDisabled'  : WAIT_EVENT_DISABLED,
  }

  FrameWorkHookDictList = [
    Dispatch_Hook,
    End_Hook,
    WaitEventReturn_Hook,
    WaitEvent_Hook,
  ]


  #Initialise the class################################################################################################################################################################################
  def __init__(self, partitionName, outputFile, rteGenType):
    print ('Create single instance of TraceHooksSourcePatcher')

    if self.RTE_GEN_TYPE_DA_VINCI == rteGenType:
      templateFile = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/Rte_Trace_Hooks_Template_DaVinci.c'
    else:
      templateFile = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/Rte_Trace_Hooks_Template_Tresos.c'
      

    self.checkForValidOutputFileAndReadInAllLines(outputFile, templateFile)

    #Store the partition name
    self.myPartition = partitionName
    
    if self.RTE_GEN_TYPE_DA_VINCI == rteGenType:
      #We have daVinci as a rteGenerator. Here we have a different name for the TaskEndHookFunction
      #Modify it accordingly
      self.End_Hook['header'] = \
'''FUNC(void, RTE_APPL_CODE) Rte_Task_Terminate(TaskType task)
'''
      self.End_Hook['trailer'] = \
'''} /* Rte_Task_Terminate */
'''

  #####################################################################################################################################################################################################
  def updateTraceHooksSource(self, taskList, taskInfo, runnablesMultipeTasks, additionalFeatureCfg):
    #Have the rteTraceHook source file updated

    self.updateTaskCfgTypeSection(taskList)

    self.updateTaskLutSection(taskList, taskInfo)

    self.updateTaskCycleCounterSection(taskList)

    self.updateFrameworkHooksSection(taskList, taskInfo)

    self.updateTraceHooksSection(taskList, taskInfo, runnablesMultipeTasks, additionalFeatureCfg)

    #Add or remove includes according current activated additionalFeatures
    self.handleHeaderIncludesForAdditionalFeatures(additionalFeatureCfg)

    #All the updates are done. Now write all the lines back into the file
    self.writeLinesintoFile(self.fileHooksSource, self.linesHooksSource)


  #####################################################################################################################################################################################################
  def updateTaskCfgTypeSection(self, taskList):

    #First copy that lines below the generatorStartTag to a seperate list and remove them from origin lines
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_TASK_CFG_START, self.linesHooksSource, self.linesStartHookSectionToEOF)

    #Add empty lines
    self.linesHooksSource.append('\n' * 1)

    #Add the typedef for the taskConfiguration
    self.linesHooksSource.append(self.TYPEDEF_TRACE_HOOK_TASK_CONFIG)

    #Add empty lines
    self.linesHooksSource.append('\n' * 2)

    #Add the numberOfTasksDefine
    self.linesHooksSource.append(self.DEFINE_NO_RELEVANT_TASKS.format(len(taskList)))

    #Add empty lines
    self.linesHooksSource.append('\n' * 2)

    # Finally add all the lines  below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_TASK_CFG_END, self.linesStartHookSectionToEOF, self.linesHooksSource)

  #####################################################################################################################################################################################################
  def updateTaskLutSection(self, taskList, taskInfo):

    #Determine length of the longest strings
    maxLenTaskName      = len(self.TASK_CFG_MEMBER_TASK_ID)
    maxLenGlobalID      = len(self.TASK_CFG_MEMBER_GLOBAL_ID)
    maxLenLocalID       = len(self.TASK_CFG_MEMBER_LOCAL_ID)
    maxLenTaskRuntime   = len(self.TASK_CFG_MEMBER_TASK_RUNNTIME_ENABLED)
    maxLenExtendedTask  = len(self.TASK_CFG_MEMBER_IS_EXTENDED_TASK)


    for entry in taskList:
      if len(entry) > maxLenTaskName:
        maxLenTaskName = len(entry)

      if len(taskInfo[entry]['globalID']) > maxLenGlobalID:
        maxLenGlobalID = len(taskInfo[entry]['globalID'])

      if len(self.createTaskRuntimeLocalID(taskInfo[entry]['taskName'])) > maxLenLocalID:
        maxLenLocalID = len(self.createTaskRuntimeLocalID(taskInfo[entry]['taskName']))

    if len('False') > maxLenTaskRuntime:
      maxLenTaskRuntime = maxLenExtendedTask

    if len('False') > maxLenExtendedTask:
      maxLenExtendedTask = len('False')

    #First copy that lines below the generatorStartTag to a seperate list and remove them from origin lines
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_TASK_LUT_START, self.linesHooksSource, self.linesStartHookSectionToEOF)

    #Add empty lines
    self.linesHooksSource.append('\n' * 1)

    #Now start with the taskCfgArray
    self.linesHooksSource.append(self.TASK_CFG_LUT_HEADER)

    #Add the commmentLine
    self.linesHooksSource.append(self.TASK_CFG_LUT_COMMENT_LINE.format(
      self.TASK_CFG_MEMBER_TASK_ID.ljust(maxLenTaskName + len('(TaskType)') - 2),
      self.TASK_CFG_MEMBER_GLOBAL_ID.ljust(maxLenGlobalID + len('(uint8)')),
      self.TASK_CFG_MEMBER_LOCAL_ID.ljust(maxLenLocalID + len('(uint8)')),
      self.TASK_CFG_MEMBER_TASK_RUNNTIME_ENABLED.ljust(maxLenTaskRuntime),
      self.TASK_CFG_MEMBER_IS_EXTENDED_TASK.ljust(maxLenExtendedTask)))

    #Add one entry per task
    comma = ','
    for i in range(len(taskList)):
      if len(taskList) - 1 == i:
        #This is the last entry - it should not have a trailing comma!
        comma = ''

      taskName     = taskList[i].ljust(maxLenTaskName)
      globalId     = taskInfo[taskList[i]]['globalID'].ljust(maxLenGlobalID)
      localId      = self.createTaskRuntimeLocalID(taskInfo[taskList[i]]['taskName']).ljust(maxLenLocalID)
      if taskInfo[taskList[i]]['taskRunTime']:
        taskRuntime  = 'b_TRUE '.ljust(maxLenTaskRuntime)
      else:
        taskRuntime  = 'b_FALSE'.ljust(maxLenTaskRuntime)
      if taskInfo[taskList[i]]['extendedTask']:
        extendedTask = 'b_TRUE '.ljust(maxLenExtendedTask)
      else:
        extendedTask = 'b_FALSE'.ljust(maxLenExtendedTask)

      self.linesHooksSource.append(self.PATTERN_TASK_CFG_LUT_ENTRY.format(taskName, globalId, localId, taskRuntime, extendedTask, comma))

    #Add trailing lines of the lut
    self.linesHooksSource.append(self.TASK_CFG_LUT_TRAILER)

    #Add empty lines
    self.linesHooksSource.append('\n' * 1)

    # Finally add all the lines  below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_TASK_LUT_END, self.linesStartHookSectionToEOF, self.linesHooksSource)

  #####################################################################################################################################################################################################
  def updateTaskCycleCounterSection(self, taskList):

    #First copy that lines below the generatorStartTag to a seperate list and remove them from origin lines
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_TASK_CNT_START, self.linesHooksSource, self.linesStartHookSectionToEOF)

    #Add empty lines
    self.linesHooksSource.append('\n' * 1)

    #Create the array for the taskCycleCounters
    #Add headerLines
    self.linesHooksSource.append(self.TASK_CYCLE_CNT_HEADER)

    #Add the element initialization lines
    comma = ','
    for i in range(len(taskList)):
      if len(taskList) - 1 == i:
        #This is the last entry - it should not have a trailing comma!
        comma = ''
      self.linesHooksSource.append(self.PATTERN_TASK_CYCLE_CNT_ENTRY.format(comma))
    #Add trailerLines
    self.linesHooksSource.append(self.TASK_CYCLE_CNT_TRAILER)

    #Add empty lines
    self.linesHooksSource.append('\n' * 1)

    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_TASK_CNT_END, self.linesStartHookSectionToEOF, self.linesHooksSource)


  #####################################################################################################################################################################################################
  def updateFrameworkHooksSection(self, taskList, taskInfo):

    instEnabled = False
    #First copy that lines below the generatorStartTag to a seperate list and remove them from origin lines
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_FRAMEWORK_HOOKS_START, self.linesHooksSource, self.linesStartHookSectionToEOF)

    #Add empty lines
    self.linesHooksSource.append('\n' * 1)

    for entry in taskList:
      if taskInfo[entry]['taskRunTime']:
        instEnabled = True

    for entry in self.FrameWorkHookDictList:
      #Check whether the current FrameWorkHook is already in the file
      hookStartEndPos = [0, 0, 0, 0]
      if self.findFrameWorkHook(entry, hookStartEndPos):

        # OK, related frameWorkHook found - just update it
        self.updateFrameWorkHook(entry, instEnabled, hookStartEndPos)
      else:
        #Create frameWorkHook from scratch
        self.createFrameWorkHook(entry, instEnabled)
      #Add empty lines
      self.linesHooksSource.append('\n' * 3)

    #Add empty lines
    self.linesHooksSource.append('\n' * 1)

    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_FRAMEWORK_HOOKS_END, self.linesStartHookSectionToEOF, self.linesHooksSource)


  #####################################################################################################################################################################################################
  def findFrameWorkHook(self, hookDict, hookStartEndPos):

    #For sake of safety remove all whitespaces
    PATTERN_HOOK_BEGIN = hookDict['header'].replace(' ', '')
    PATTERN_HOOK_END   = hookDict['trailer'].replace(' ', '')

    #Reset the hookStartEndPos
    hookStartEndPos[self.INDEX_TRACE_START]     = 0
    hookStartEndPos[self.INDEX_TRACE_START_TAG] = 0
    hookStartEndPos[self.INDEX_TRACE_END_TAG]   = 0
    hookStartEndPos[self.INDEX_TRACE_END]       = 0

    startFound = False
    idx = 0
    for line in self.linesStartHookSectionToEOF:
      if not startFound:
        #Look for the beginning of the next hookFct

        if -1 != line.replace(' ','').find(PATTERN_HOOK_BEGIN):
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
        elif -1 != line.replace(' ','').find(PATTERN_HOOK_END):
          # OK, we found the end of the hookFct - save current index
          hookStartEndPos[self.INDEX_TRACE_END] = idx
          break

      #Finally increment index
      idx += 1

    #Check whether we found all required tags in the function
    if hookStartEndPos[self.INDEX_TRACE_START] and hookStartEndPos[self.INDEX_TRACE_START_TAG] and hookStartEndPos[self.INDEX_TRACE_END_TAG] and hookStartEndPos[self.INDEX_TRACE_END]:
      return True
    else:
      #Either we did not find the desired function or the function does not have the expected format
      #Return False in order to force newly creation of the function
      return False

  #####################################################################################################################################################################################################
  def updateFrameWorkHook(self, hookDict, instrEnabled, hookStartEndPos):

    #For easy access - copy indexes from
    LINE_FUNC_START = hookStartEndPos[self.INDEX_TRACE_START]
    LINE_START_TAG  = hookStartEndPos[self.INDEX_TRACE_START_TAG]
    LINE_END_TAG    = hookStartEndPos[self.INDEX_TRACE_END_TAG]
    LINE_FUNC_END   = hookStartEndPos[self.INDEX_TRACE_END]

    #Copy the first part of the function (until the GeneratorStartTag) into the hookSoure
    self.linesHooksSource.extend(self.linesStartHookSectionToEOF[LINE_FUNC_START:LINE_START_TAG])
    #Add the rtaInstrumentation line
    if instrEnabled:
      self.linesHooksSource.append(hookDict['bodyEnabled'])
    else:
      self.linesHooksSource.append(hookDict['bodyDisabled'])
    #Copy the rest of the function (from GeneratorEndTag until the end of the function into the hookSoure
    self.linesHooksSource.extend(self.linesStartHookSectionToEOF[LINE_END_TAG + 1:LINE_FUNC_END + 1])


  #####################################################################################################################################################################################################
  def createFrameWorkHook(self, hookDict, instrEnabled):
    #Add empty lines
    self.linesHooksSource.append('\n' * 1)
    #Add headerLine
    self.linesHooksSource.extend(hookDict['header'])
    self.linesHooksSource.append('{\n\n')
    #Add body
    if instrEnabled:
      self.linesHooksSource.extend(hookDict['bodyEnabled'])
    else:
      self.linesHooksSource.extend(hookDict['bodyDisabled'])
    #Add trailerLines
    self.linesHooksSource.append('\n' * 1)
    self.linesHooksSource.extend(hookDict['trailer'])

    #Add empty lines
    self.linesHooksSource.append('\n' * 1)


