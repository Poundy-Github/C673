import os
import re

from InstrGeneratorBase import InstrGenBase

#################################################################################
#
#################################################################################
class StepCounterFilesPatcher(InstrGenBase):

  WARNING_TEXT_STEP_COUNTER_RANGE = '''
In the task {0} the number of runnables exceeds the range of the stepCounter!
Note: For every runnable one stepCounterValue is needed!

'''
  PREPROCESSOR_ERROR_STEP_COUNTER_RANGE = '''
#error the number of runnables exceeds the range of the stepCounter which is  {0} !!!!

'''

  TEXT_FUNCTION_DECLARATION_SetStepCounterArrayStartAddress = '''
/** ***********************************************************************************************
  \\brief  This function sets the pointer p_stepCnt to the address given in p_STEP_CNT_ARRAY. Before
          setting the p_stepCnt it checks if the length of provided array is big enough. It has to be
          at least number of osTasks, as there is one counter needed per task.

  \pre    None
  \post   None

  \param  [in] p_STEP_CNT_ARRAY
          - Description: This argument provides the startAddress of the stepCounterArray.
                         The stepCounterArray has to be located in persistent RAM as it is used for
                         postMortemAnalysis.
  \param  [in] u_ARRAY_LENGHT
          - Description: This argument is used to double-check that the size of given stepCounterArray is
                         big enough. It has to be at least number of osTasks.

  \\return void

\\b Globals \\n
          \parblock \par
          [out] \\b p_stepCnt  \\n
          - Description: The pointer to the stepCounterArray. \\n
          \endparblock
          \parblock \par
***************************************************************************************************/
void RTE_v_SetStepCounterArrayStartAddress(uint8 * const p_STEP_CNT_ARRAY,  const uint8 u_ARRAY_LENGHT);
'''

  TEXT_FUNCTION_DEFINITION_SetStepCounterArrayStartAddress = '''
void RTE_v_SetStepCounterArrayStartAddress(uint8 * const p_STEP_CNT_ARRAY,  const uint8 u_ARRAY_LENGHT)
{{
  if((uint8){0} <= u_ARRAY_LENGHT)
  {{
    p_stepCnt = p_STEP_CNT_ARRAY;
  }}
}}
''' # {0} -> self.numberOfTasksString

  TEXT_FUNCTION_DEFINITION_SetStepCounterArrayStartAddress_FEATURE_DISABLED = '''
void RTE_v_SetStepCounterArrayStartAddress(uint8 * const p_STEP_CNT_ARRAY,  const uint8 u_ARRAY_LENGHT)
{
  //StepCounters disabled - just provide the interface for PMA

  //Avoid compiler warnings
  (void) p_STEP_CNT_ARRAY;
  (void) u_ARRAY_LENGHT;
}
'''

  TEXT_FUNCTION_DECLARATION_SetStepCounterValue = '''
/** ***********************************************************************************************
  \\brief  This function sets the stepCounter related to given task to the provided value.
          It shall be called in the startTraceHookFunctions of the runnables.

  \pre    None
  \post   None

  \param  [in] TASK_ID
          - Description: This argument provides the task for which the stepCounter shall be set.
          - Range:       0 ... (numberOfTasks - 1)

  \param  [in] u_STEP_CNT_VALUE
          - Description: This argument provides the value to which the related stepCounter shall be set
          - Range:       0 ... 0xFF

  \\return void

\\b Globals \\n
          \parblock \par
          [out] \\b p_stepCnt  \\n
          - Description: The pointer to the stepCounterArray \\n
          \endparblock
          \parblock \par
***************************************************************************************************/
void RTE_v_SetStepCounterValue(const TaskType TASK_ID, const uint8 u_STEP_CNT_VALUE);
'''


  TEXT_FUNCTION_DECLARATION_SetStepCounterValue_FEATURE_DISABLED = '''
//The declaration of the function RTE_v_SetStepCounterValue has not been generated as the StepCounterFeature is disabled!!
'''

  TEXT_FUNCTION_DEFINITION_SetStepCounterValue = '''
void RTE_v_SetStepCounterValue(const TaskType TASK_ID, const uint8 u_STEP_CNT_VALUE)
{{
  if( ({0} > TASK_ID) && (NULL != p_stepCnt) )
  {{
    p_stepCnt[TASK_ID] = u_STEP_CNT_VALUE;
  }}
}}
'''  # {0} -> self.numberOfTasksString


  TEXT_DECLARATION_StepCounterPointer = '''
/** ***********************************************************************************************
\description This pointer is used by the function RTE_v_SetStepCounterValue to set the counter of
             given task to provided value. The pointer points to the a_stepCntDefault as long as
             it has been set to the real stepCounterArray which has to be located in persistent
             RAM.
***************************************************************************************************/
static uint8 * p_stepCnt = NULL;
'''


  TEXT_DECLARATION_StepCounterPointer_FEATURE_DISABLED = '''
// This section is empty as the StepCounterFeature is disabled!!
'''

  #All the generatorTags:
  GEN_TAG_ENUMERATIONS_START       = '___GENERATOR_TAG___STEP_COUNTER_ENUMERATIONS___SECTION_START___'
  GEN_TAG_ENUMERATIONS_END         = '___GENERATOR_TAG___STEP_COUNTER_ENUMERATIONS___SECTION_END___'
  GEN_TAG_FUNCTIONS_START          = '___GENERATOR_TAG___STEP_COUNTER_FUNCTIONS___SECTION_START___'
  GEN_TAG_FUNCTIONS_END            = '___GENERATOR_TAG___STEP_COUNTER_FUNCTIONS___SECTION_END___'
  GEN_TAG_STEP_CNT_ARRAY_START     = '___GENERATOR_TAG___STEP_COUNTER_ARRAY___SECTION_START___'
  GEN_TAG_STEP_CNT_ARRAY_END       = '___GENERATOR_TAG___STEP_COUNTER_ARRAY___SECTION_END___'

  #The header and tailer texts for the stepCounterEnumerations
  ENUM_HEADER_TEXT = '\ntypedef enum {\n'
  ENUM_TRAILER_TEXT = '}} {0};\n'  # {0} -> EnumName
  ENUM_LITERAL_LINE_PATTERN = '  {0} = {1}, \n' # {0} -> LiteralName, {1} -> literalValue

  STEP_CNT_ENUM_NAME_PATTERN = 'RTE_{0}_StepCounterValues' # {0} -> TaskName
  TASK_NOT_STARTED_STRING = 'TASK_NOT_STARTED_YET'

  #Indexes of the one dimensonal list 'enumStartEndPos'
  INDEX_ENUM_START  = 0
  INDEX_ENUM_END    = 1

  #Indexes of the one dimensonal list 'literalNameAndValuePair'
  INDEX_LITERAL_NAME  = 0
  INDEX_LITERAL_VALUE = 1


  #The files to be updated
  fileStepCntHeader   = ''
  fileStepCntSource   = ''

  #The lines of relevant files
  linesStepCntHeader  = []
  linesStepCntSource  = []

  #Initialise the class################################################################################################################################################################################
  def __init__(self, outputPathIncl, outputPathScr, rteGenType):

    # The list of generatorTags like they have to appear in that order in a valid Rte_StepCounter.h
    tagListHeader = [
      self.GEN_TAG_FUNCTIONS_START   ,
      self.GEN_TAG_FUNCTIONS_END     ,
      self.GEN_TAG_ENUMERATIONS_START,
      self.GEN_TAG_ENUMERATIONS_END  ,
    ]

    # The list of generatorTags like they have to appear in that order in a valid Rte_StepCounter.h
    tagListSource = [
      self.GEN_TAG_STEP_CNT_ARRAY_START,
      self.GEN_TAG_STEP_CNT_ARRAY_END  ,
      self.GEN_TAG_FUNCTIONS_START     ,
      self.GEN_TAG_FUNCTIONS_END       ,
    ]


    #Get the Rte_StepCounter.h and read all lines of it.
    #Read the lines of related template file if Rte_StepCounter.h does not exist or it is corrupt
    useTemplateFile = True
    listIdx = 0

    self.fileStepCntHeader = outputPathIncl + '/' + self.RTE_STEP_CNT_HEADER

    #Get all lines of the headerFile
    self.linesStepCntHeader = self.getLinesOfFile(self.fileStepCntHeader)

    # Check whether the file contains all needed tags in the right order
    for line in self.linesStepCntHeader:
      #Find next tag
      if -1 != line.find(tagListHeader[listIdx]):
        #Ok - next tag found just increment index
        listIdx += 1
        #Check whether this was already the last index to be found
        if len(tagListHeader) <= listIdx:
          # ok, all tags found
          useTemplateFile = False
          break

    if useTemplateFile:
      print ('Use stepCounterTemplateHeader!!!!!!!!!!!!!!!!!!!!!!!!!!')
      #File does not exist - or at least one required generatorTag is missing, the old file cannot be updated.
      #Take the templateFile instead
      template = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/Rte_StepCounter_Template.h'
      self.linesStepCntHeader = self.getLinesOfFile(template)


    #Get the Rte_StepCounter.c and read all lines of it.
    #Read the lines of related template file if Rte_StepCounter.c does not exist or it is corrupt
    useTemplateFile = True
    listIdx = 0

    self.fileStepCntSource = outputPathScr + '/' + self.RTE_STEP_CNT_SRC
    #Get all lines of the headerFile
    self.linesStepCntSource = self.getLinesOfFile(self.fileStepCntSource)

    # Check whether the file contains all needed tags in the right order
    for line in self.linesStepCntSource:
      #Find next tag
      if -1 != line.find(tagListSource[listIdx]):
        #Ok - next tag found just increment index
        listIdx += 1
        #Check whether this was already the last index to be found
        if len(tagListSource) <= listIdx:
          # ok, all tags found
          useTemplateFile = False
          break

    if useTemplateFile:
      print ('Use stepCounterTemplateSource!!!!!!!!!!!!!!!!!!!!!!!!!!')
      #File does not exist - or at least one required generatorTag is missing, the old file cannot be updated.
      #Take the templateFile instead
      if self.RTE_GEN_TYPE_DA_VINCI == rteGenType:
        template = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/Rte_StepCounter_Template_DaVinci.c'
      else:
        template = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/Rte_StepCounter_Template_Tresos.c'
        
      self.linesStepCntSource = self.getLinesOfFile(template)

    #Finally set numberOfTaskString depending on the generatorType (= osType) we have. 
    #It is used to generate the correct code later on. 
    if self.RTE_GEN_TYPE_DA_VINCI == rteGenType:
      self.numberOfTasksString = 'OS_TASKID_COUNT'
    else:
      self.numberOfTasksString = 'OS_NTASKS'


  #####################################################################################################################################################################################################
  def updateStepCounterFiles(self, taskList, taskInfo, additionalFeatureCfg):
    #Have the stepCounterFiles updated
    self.updateStepCounterHeaderFile(taskList, taskInfo, additionalFeatureCfg)
    self.updateStepCounterSourceFile(additionalFeatureCfg)


  #####################################################################################################################################################################################################
  def updateStepCounterHeaderFile(self, taskList, taskInfo, additionalFeatureCfg):
    #Have the stepCounterFiles updated

    #Update the declarations of the interfaceFunctions
    self.updateFunctionDeclarationsHeaderFile(additionalFeatureCfg)

    #Update stepCounterEnumerations
    self.updateEnumerationsHeaderFile(taskList, taskInfo, additionalFeatureCfg)

    #All the updates are done. Now write all the lines back into the file
    self.writeLinesintoFile(self.fileStepCntHeader, self.linesStepCntHeader)


  #####################################################################################################################################################################################################
  def updateFunctionDeclarationsHeaderFile(self, additionalFeatureCfg):
    #Copy all lines below startTag into a separate list
    linesRestOfFile = []
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_FUNCTIONS_START, self.linesStepCntHeader, linesRestOfFile)

    #Add new lines
    self.linesStepCntHeader.append('\n'*1)
    #Add function declaration of RTE_v_SetStepCounterArrayStartAddress
    self.linesStepCntHeader.extend(self.TEXT_FUNCTION_DECLARATION_SetStepCounterArrayStartAddress)
    if True == additionalFeatureCfg['stepCountersEnabled']:
      #Add function declaration of RTE_v_SetStepCounterValue
      self.linesStepCntHeader.extend(self.TEXT_FUNCTION_DECLARATION_SetStepCounterValue)
    else:
      #StepCounterFeature is disabled - just add an info text
      self.linesStepCntHeader.extend(self.TEXT_FUNCTION_DECLARATION_SetStepCounterValue_FEATURE_DISABLED)
    #Add new lines
    self.linesStepCntHeader.append('\n'*1)

    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_FUNCTIONS_END, linesRestOfFile, self.linesStepCntHeader)


  #####################################################################################################################################################################################################
  #Update stepCounterEnumerations
  def updateEnumerationsHeaderFile(self, taskList, taskInfo, additionalFeatureCfg):
    #Copy all lines below startTag into a separate list
    linesRestOfFile = []
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_ENUMERATIONS_START, self.linesStepCntHeader, linesRestOfFile)
    #Loop over all tasks and update/create related stepCounterEnumerationts
    for entry in taskList:
      enumStartEndPos = [0,0]
      #Get the related entry from taskInfo dict
      taskSetup = taskInfo[entry]
      #Check whether there is already an enumeration in the file for given task
      enumName = self.STEP_CNT_ENUM_NAME_PATTERN.format(taskSetup['taskName'])
      if self.findStepCounterEnum(enumName, linesRestOfFile, enumStartEndPos):
        # OK, related enum found - just update it
        numberOfRunnablesInRange = self.updateStepCounterEnum(taskSetup, linesRestOfFile, enumStartEndPos)
      else:
        #Create a new localIdEnum
        numberOfRunnablesInRange = self.createNewStepCounterEnum(taskSetup)

      if True == additionalFeatureCfg['stepCountersEnabled']:
        if not numberOfRunnablesInRange:
          print (self.WARNING_TEXT_STEP_COUNTER_RANGE.format(taskSetup['taskName']))
          self.linesStepCntHeader.append(self.PREPROCESSOR_ERROR_STEP_COUNTER_RANGE.format(self.STEP_COUNTER_RANGE))

    #Add new lines
    self.linesStepCntHeader.append('\n'*2)

    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_ENUMERATIONS_END, linesRestOfFile, self.linesStepCntHeader)

  #####################################################################################################################################################################################################
  def findStepCounterEnum(self, enumName, linesRestOfFile, enumStartEndPos):
    #Clear enumStartEndPos
    enumStartEndPos[self.INDEX_ENUM_START] = 0
    enumStartEndPos[self.INDEX_ENUM_END]   = 0

    for idx in range(len(linesRestOfFile)):
      #Look for the next enum start
      if re.match(r' *typedef *enum *\{', linesRestOfFile[idx]):
        # Start of an enum found - save currend index
        enumStartEndPos[self.INDEX_ENUM_START] = idx
      elif enumStartEndPos[self.INDEX_ENUM_START]:
        #Check if have now the end of the enum we are looking for
        searchString = '}} {0};'.format(enumName)
        if -1 != linesRestOfFile[idx].find(searchString):
          #Ok end of our enumeration found - save currend index
          enumStartEndPos[self.INDEX_ENUM_END] = idx
          break
      #Check whether we reached already the end of the section in which the enums are defined
      if -1 != linesRestOfFile[idx].find(self.GEN_TAG_ENUMERATIONS_END):
        #OK - end of sequence found - terminate the loop immediately
        break

    #Check whether we found desired enumeration
    if enumStartEndPos[self.INDEX_ENUM_END]:
      return True
    else:
      return False


  #####################################################################################################################################################################################################
  def updateStepCounterEnum(self, taskSetup, linesRestOfFile, enumStartEndPos):

    #Get all literals which are still needed inclusive their value
    literalNameAndValuePairs = []
    for idx in range(enumStartEndPos[self.INDEX_ENUM_START]+2, enumStartEndPos[self.INDEX_ENUM_END]):
      #Separate literalName and value
      line = linesRestOfFile[idx].strip('\n')
      line = line.replace(',','')
      line = line.replace(' ','')
      literalNameAndValue = line.split('=')
      #Check whether their is the related runnable still in the task
      for runnableEntry in taskSetup['runnableCfgList']:
        if runnableEntry[self.INDEX_STEP_CNT_ID] == literalNameAndValue[self.INDEX_LITERAL_NAME]:
          literalNameAndValuePairs.append(literalNameAndValue)

    #At the beginning has to be always the not started literal with value 0
    literalNameAndValuePairs.insert(0, [self.STEP_CNT_LITERAL_NAME_PATTERN.format(taskSetup['taskName'], self.TASK_NOT_STARTED_STRING), str(0)])

    #Add literals for new runnables which are not in the list up to now
    for runnableEntry in taskSetup['runnableCfgList']:
      addLiteral = True
      for existingLiteralAndValuePair in literalNameAndValuePairs:
        if runnableEntry[self.INDEX_STEP_CNT_ID] == existingLiteralAndValuePair[self.INDEX_LITERAL_NAME]:
          # Ok for current runnable we have alread a literalAndValuePair
          addLiteral = False
          break

      #Do we have a new literal to be added?
      if addLiteral:
        # Get the last value from the current literalList
        value = int(literalNameAndValuePairs[len(literalNameAndValuePairs)-1][self.INDEX_LITERAL_VALUE])
        if self.STEP_COUNTER_RANGE > value:
          #Ok, there is still space left in the end - add the new literal includingt its value
          literalNameAndValuePairs.append([runnableEntry[self.INDEX_STEP_CNT_ID], str(value + 1)])
        else:
          #No space left in the end of the list, look for the next gap from the beginning
          gapFound = False
          for idx in range(len(literalNameAndValuePairs)-1):
            currentValue = int(literalNameAndValuePairs[idx][self.INDEX_LITERAL_VALUE])
            nextValue    = int(literalNameAndValuePairs[idx+1][self.INDEX_LITERAL_VALUE])
            if nextValue > currentValue + 1:
              #OK - here we have a gap - insert the new literal
              literalNameAndValuePairs.insert(idx + 1, [runnableEntry[self.INDEX_STEP_CNT_ID], str(currentValue + 1)])
              gapFound = True
              break
          #Check if we found a gap
          if not gapFound:
            #No gap found just add the literal to the end - preCompiler error will be created by calling function
            literalNameAndValuePairs.append([runnableEntry[self.INDEX_STEP_CNT_ID], str(value + 1)])

    #Create the updated enumeration
    #Determine the length of longest literalName
    maxLen = 0
    for literalNameAndValue in literalNameAndValuePairs:
      if len(literalNameAndValue[self.INDEX_LITERAL_NAME]) > maxLen:
        maxLen = len(literalNameAndValue[self.INDEX_LITERAL_NAME])

    #Add the enumHeader to the end of linesHooksHeader
    self.linesStepCntHeader.extend(self.ENUM_HEADER_TEXT)

    #Add all literals according runnableCfgList
    for literalNameAndValue in literalNameAndValuePairs:
      literalName = literalNameAndValue[self.INDEX_LITERAL_NAME].ljust(maxLen)
      value       = literalNameAndValue[self.INDEX_LITERAL_VALUE]
      self.linesStepCntHeader.append(self.ENUM_LITERAL_LINE_PATTERN.format(literalName, value))

    #remove trailing comma of last literal line
    self.linesStepCntHeader.extend(self.linesStepCntHeader.pop().replace(',',''))
    #Add enum trailer
    enumName = self.STEP_CNT_ENUM_NAME_PATTERN.format(taskSetup['taskName'])
    self.linesStepCntHeader.extend(self.ENUM_TRAILER_TEXT.format(enumName))

    #Check if number of runnables are in range
    if self.STEP_COUNTER_RANGE < int(literalNameAndValuePairs[len(literalNameAndValuePairs)-1][self.INDEX_LITERAL_VALUE]):
      #The number of runnables exceeds the range of the stepCounter
      #Just return false, a preprocessorError will be generated in calling function
      return False
    else:
      return True


  #####################################################################################################################################################################################################
  def createNewStepCounterEnum(self, taskSetup):

    #Get the taskRuntimeLiteral which has to be the first one (with value 0)
    taskNotStartedLiteral = self.STEP_CNT_LITERAL_NAME_PATTERN.format(taskSetup['taskName'], self.TASK_NOT_STARTED_STRING)
    #Determine the length of longest literal
    maxLen = len(taskNotStartedLiteral)
    for entry in taskSetup['runnableCfgList']:
      if len(entry[self.INDEX_STEP_CNT_ID]) > maxLen:
        maxLen = len(entry[self.INDEX_STEP_CNT_ID])

    #Add the enumHeader to the end of linesHooksHeader
    self.linesStepCntHeader.extend(self.ENUM_HEADER_TEXT)

    value = 0
    #Add the literal for taskRunTime measurement which has to be always the first one
    self.linesStepCntHeader.append(self.ENUM_LITERAL_LINE_PATTERN.format(taskNotStartedLiteral.ljust(maxLen), value))
    #Add all literals according runnableCfgList
    for entry in taskSetup['runnableCfgList']:
      value += 1

      self.linesStepCntHeader.append(self.ENUM_LITERAL_LINE_PATTERN.format(entry[self.INDEX_STEP_CNT_ID].ljust(maxLen), value))

    #remove trailing comma of last literal line
    self.linesStepCntHeader.extend(self.linesStepCntHeader.pop().replace(',',''))
    #Add enum trailer
    enumName = self.STEP_CNT_ENUM_NAME_PATTERN.format(taskSetup['taskName'])
    self.linesStepCntHeader.extend(self.ENUM_TRAILER_TEXT.format(enumName))

    if self.STEP_COUNTER_RANGE < value:
      #The number of runnables exceeds the range of the stepCounter
      #Just return false, a preprocessorError will be generated in calling function
      return False
    else:
      return True




  #####################################################################################################################################################################################################
  def updateStepCounterSourceFile(self, additionalFeatureCfg):
    #Have the stepCounterSourceFile updated

    #Update stepCounterPointer #########################################################################
    #Copy all lines below startTag into a separate list
    linesRestOfFile = []
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_STEP_CNT_ARRAY_START, self.linesStepCntSource, linesRestOfFile)

    #Add new lines
    self.linesStepCntSource.append('\n'*1)

    if True == additionalFeatureCfg['stepCountersEnabled']:
      #Add declaration ofstepCounterPointer
      self.linesStepCntSource.extend(self.TEXT_DECLARATION_StepCounterPointer)
    else:
      #Add declaration ofstepCounterPointer
      self.linesStepCntSource.extend(self.TEXT_DECLARATION_StepCounterPointer_FEATURE_DISABLED)

    #Add new lines
    self.linesStepCntSource.append('\n'*2)

    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_STEP_CNT_ARRAY_END, linesRestOfFile, self.linesStepCntSource)

    #Update stepCounter functions #########################################################################
    #Copy all lines below startTag into a separate list
    del linesRestOfFile[:]
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_FUNCTIONS_START, self.linesStepCntSource, linesRestOfFile)

    #Add new lines
    self.linesStepCntSource.append('\n'*1)

    if True == additionalFeatureCfg['stepCountersEnabled']:
      #StepCounterFeature enabled
      #Add function definition of RTE_v_SetStepCounterArrayStartAddress
      self.linesStepCntSource.extend(self.TEXT_FUNCTION_DEFINITION_SetStepCounterArrayStartAddress.format(self.numberOfTasksString))
      #Add new lines
      self.linesStepCntSource.append('\n'*1)
      #Add function definition of RTE_v_SetStepCounterValue
      self.linesStepCntSource.extend(self.TEXT_FUNCTION_DEFINITION_SetStepCounterValue.format(self.numberOfTasksString))
    else:
      #StepCounterFeature enabled
      #Add function definition of RTE_v_SetStepCounterArrayStartAddress - just an empty function
      self.linesStepCntSource.extend(self.TEXT_FUNCTION_DEFINITION_SetStepCounterArrayStartAddress_FEATURE_DISABLED)

    #Add new lines
    self.linesStepCntSource.append('\n'*1)

    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_FUNCTIONS_END, linesRestOfFile, self.linesStepCntSource)

    #All the updates are done. Now write all the lines back into the file
    self.writeLinesintoFile(self.fileStepCntSource, self.linesStepCntSource)
