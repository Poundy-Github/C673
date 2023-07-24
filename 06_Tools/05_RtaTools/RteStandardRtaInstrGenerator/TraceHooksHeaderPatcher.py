import os
import re

from InstrGeneratorBase import InstrGenBase
from ChainCommon import ChainCommon

#################################################################################
#
#################################################################################
class TraceHooksHeaderPatcher(InstrGenBase):

  #All the generatorTags:
  GEN_TAG_GLOB_IDS_START           = '___GENERATOR_TAG___GLOBAL_ID_DEFINES___SECTION_START___'
  GEN_TAG_GLOB_IDS_END             = '___GENERATOR_TAG___GLOBAL_ID_DEFINES___SECTION_END___'
  GEN_TAG_LOCAL_ID_ENUM_START      = '___GENERATOR_TAG___LOCAL_ID_ENUM___SECTION_START___'
  GEN_TAG_LOCAL_ID_ENUM_END        = '___GENERATOR_TAG___LOCAL_ID_ENUM___SECTION_END___'
  GEN_TAG_ERROR_WARNING_INFO_START = '___GENERATOR_TAG___ERROR_WARNING_INFO___SECTION_START___'
  GEN_TAG_ERROR_WARNING_INFO_END   = '___GENERATOR_TAG___ERROR_WARNING_INFO___SECTION_END___'
  GEN_TAG_MAN_ADDED_LITERALS       = '___GENERATOR_TAG___MANUALLY_ADDED_LITERALS___BELOW___'

  #The string for the RTE globalID defines 
  DEFINE_LINE_RTE_GLOBAL_ID            = '#define {0} ((RTA_t_GlobalID){1})\n' # 0 -> defineName, 1 ->  globalIdValue

  #The header and tailer texts for the localID enumerations
  LOCAL_ID_ENUM_HEADER = '\ntypedef enum {\n'

  LOCAL_ID_ENUM_TERMINATION_LINE = '}} {0}; /* RTA_LOCAL_ID_FOR_XML_GENERATION */\n'

  LOCAL_ID_ENUM_MAN_ADDED_LITERALS__TAG_AND_EXPLANATION = '  /* ' + GEN_TAG_MAN_ADDED_LITERALS +  '''
   * In the following you can add literals manually for rtaInstrumentation beyond the standard rtaInstrumentation done by the generator.
   * Note: Only add those localIDs which shall be sent with the same globalID as all the other one in that enumeration.
   * PLEASE DO NOT CHANGE OR REMOVE THIS COMMENT BLOCK!!!
   */
'''

  LOCAL_ID_ENUM_TRAILER = LOCAL_ID_ENUM_MAN_ADDED_LITERALS__TAG_AND_EXPLANATION + LOCAL_ID_ENUM_TERMINATION_LINE


  LITERAL_LINE_PATTERN = '  {0}{1} = {2} \n'

  #Indexes of the one dimensional list 'enumStartEndPos'
  INDEX_ENUM_START  = 0
  INDEX_ENUM_TAG    = 1
  INDEX_ENUM_END    = 2

  #Indexes of the one dimensional list 'traceHookStartEndPos'
  INDEX_TRACE_START      = 0
  INDEX_TRACE_START_TAG  = 1
  INDEX_TRACE_END_TAG    = 2
  INDEX_TRACE_END        = 3

  #The files to be updated
  fileHooksHeader   = ''

  #The lines of relevant files
  linesHooksHeader  = []

  #Initialize the class################################################################################################################################################################################
  def __init__(self, outputPath):
    useTemplateFile = True

    tagList = [
      self.GEN_TAG_GLOB_IDS_START,
      self.GEN_TAG_GLOB_IDS_END,
      self.GEN_TAG_LOCAL_ID_ENUM_START,
      self.GEN_TAG_LOCAL_ID_ENUM_END,
      self.GEN_TAG_ERROR_WARNING_INFO_START,
      self.GEN_TAG_ERROR_WARNING_INFO_END,
    ]

    listIdx = 0

    #Get the Rte_Trace_Hooks.h and read all lines of it. Read the lines of related template file if Rte_TraceHook.h does not exist
    self.fileHooksHeader = outputPath + '/' + self.RTE_TRACE_HOOK_HEADER
    #Get all lines of the headerFile
    self.linesHooksHeader = self.getLinesOfFile(self.fileHooksHeader)

    # Check whether the file contains all needed tags in the right order
    for line in self.linesHooksHeader:
      #Find next tag
      if -1 != line.find(tagList[listIdx]):
        #OK - next tag found just increment index
        listIdx = listIdx + 1
        #Check whether this was already the last index to be found
        if len(tagList) <= listIdx:
          # OK, all tags found
          useTemplateFile = False
          break

    if useTemplateFile:
      print ('Use templateHeader!!!!!!!!!!!!!!!!!!!!!!!!!!')
      #File does not exist - or at least one required generatorTag is missing, the old file cannot be updated.
      #Take the templateFile instead
      template = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/Rte_Trace_Hooks_Template.h'
      self.linesHooksHeader = self.getLinesOfFile(template)
    else:
      #Remove include of glob_comp_id.h - it's not needed anymore
      self.removeIncluteOf_glob_comp_id_h()


  #####################################################################################################################################################################################################
  #This function is only needed to remove the include of glob_comp_id.h and substitute it by an include of RTA.h in already existing Rte_Trace_Hooks.h files
  # It can be removed later on when it is ensured that there are no Rte_Trace_Hooks.h in the field anymore including glob_comp_id.h
  def removeIncluteOf_glob_comp_id_h(self):

    glob_comp_id_h_Include = '#include<glob_comp_id.h>'
    linesPureCode = []

    #Remove the comments from the lines
    self.getLinesOfPureCode(self.linesHooksHeader, linesPureCode)

    for i in range(len(linesPureCode)):
      currentLine = linesPureCode[i].replace(' ','')

      if -1 != currentLine.find(glob_comp_id_h_Include):
        #ok, this is the line including glob_comp_id.h
        #Remove it from the origin lines
        self.linesHooksHeader.pop(i)
        break

  #####################################################################################################################################################################################################
  def updateTraceHooksHeader(self, taskList, taskInfo, errorWarningText):
    #Have the rteTraceHook source file updated

    self.updateGlobalIdDefinesInTraceHooksHeader(taskList, taskInfo)

    self.updateLocalIDEnumsInTraceHooksHeader(taskList, taskInfo)

    self.updateErrorWarningInformation(errorWarningText)

    #All the updates are done. Now write all the lines back into the file
    self.writeLinesintoFile(self.fileHooksHeader, self.linesHooksHeader)


  #####################################################################################################################################################################################################
  def updateGlobalIdDefinesInTraceHooksHeader(self, taskList, taskInfo):

    maxStrLen   = 0

    #Get the maxStrLen of all strings in list
    for entry in taskList:
      if len(entry) > maxStrLen:
        maxStrLen = len(entry)

    #Copy all lines below startTag into a separate list
    linesRestOfFile = []
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_GLOB_IDS_START, self.linesHooksHeader, linesRestOfFile)

    #Fist add an empty line
    self.linesHooksHeader.append('\n')
    
    #For every task generate a globalID define
    for entry in taskList:
      # Get globalIdDefine and taskID for current task from taskInfo
      globalIdName  = taskInfo[entry]['globalID']
      globalIdValue = str(taskInfo[entry]['osTaskID'] + self.RTE_GLOBAL_IDS_RANGE_START)
      
      newDefine = self.DEFINE_LINE_RTE_GLOBAL_ID.format(globalIdName.ljust(maxStrLen + 16), globalIdValue)
      self.linesHooksHeader.append(newDefine)

    #Add an empty line
    self.linesHooksHeader.append('\n')
    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_GLOB_IDS_END, linesRestOfFile, self.linesHooksHeader)


  #####################################################################################################################################################################################################
  def updateLocalIDEnumsInTraceHooksHeader(self, taskList, taskInfo):
    #Copy all lines below startTag into a separate list
    linesRestOfFile = []
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_LOCAL_ID_ENUM_START, self.linesHooksHeader, linesRestOfFile)

    #Loop over all tasks and update/create related localIDEnum
    for entry in taskList:
      enumStartEndPos = [0,0,0]
      #Get the related entry from taskInfo dict
      taskSetup = taskInfo[entry]
      #Check whether there is already an enumeration in the file for given task
      if self.findLocalIdEnum(taskSetup['enumName'], linesRestOfFile, enumStartEndPos):
        # OK, related enum found - just update it
        self.updateLocalIdEnum(taskSetup, linesRestOfFile, enumStartEndPos)
      else:
        #Create a new localIdEnum
        self.createNewLocalIdEnum(taskSetup)
    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_LOCAL_ID_ENUM_END, linesRestOfFile, self.linesHooksHeader)


  #####################################################################################################################################################################################################
  def updateErrorWarningInformation(self, errorWarningText):
    #Copy all lines below startTag into a separate list
    linesRestOfFile = []
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_ERROR_WARNING_INFO_START, self.linesHooksHeader, linesRestOfFile)

    #Just add the errorWarningText to the headerLine
    self.linesHooksHeader.extend(errorWarningText)

    # Finally add all the lines below the endTag of old file
    self.addLinesBelowTag(self.GEN_TAG_ERROR_WARNING_INFO_END, linesRestOfFile, self.linesHooksHeader)


  #####################################################################################################################################################################################################
  def findLocalIdEnum(self, enumName, linesRestOfFile, enumStartEndPos):
    idx = 0
    #Clear enumStartEndPos
    enumStartEndPos[self.INDEX_ENUM_START] = 0
    enumStartEndPos[self.INDEX_ENUM_TAG]   = 0
    enumStartEndPos[self.INDEX_ENUM_END]   = 0

    for line in linesRestOfFile:
      #Look for the next enum start
      if re.match(r' *typedef *enum *\{',line):
        # Start of an enum found - save currend index
        enumStartEndPos[self.INDEX_ENUM_START] = idx
        # Reset enumManualTagIdx as it could be set at previously found enum
        enumStartEndPos[self.INDEX_ENUM_TAG] = 0
      elif enumStartEndPos[self.INDEX_ENUM_START]:
        #We already found an start of an enum, now look for the manualTag inside the enum
        if -1 != line.find(self.GEN_TAG_MAN_ADDED_LITERALS):
          #OK, tag found - save current index
          enumStartEndPos[self.INDEX_ENUM_TAG] = idx
        else:
          #Check if have now the end of the enum we are looking for
          PATTERN = r' *\}.*\/\* *RTA_LOCAL_ID_FOR_XML_GENERATION *\*\/'
          if re.match(PATTERN, line) and ( -1 != line.find(enumName) ):
            #Ok end of our enumeration found - save currend index
            enumStartEndPos[self.INDEX_ENUM_END] = idx
            break
      #Check whether we reached already the end of the section in which the enums are defined
      if -1 != line.find(self.GEN_TAG_LOCAL_ID_ENUM_END):
        #OK - end of sequence found - terminate the loop immediately
        break
      #Increment running index
      idx = idx + 1

    #Check whether we found desired enumeration including required tags
    if enumStartEndPos[self.INDEX_ENUM_TAG] and enumStartEndPos[self.INDEX_ENUM_END]:
      return True
    else:
      return False

  #####################################################################################################################################################################################################
  def updateLocalIdEnum(self, taskSetup, linesRestOfFile, enumStartEndPos):

    #Get the taskRuntimeLiteral
    taskRuntimeLiteral = self.createTaskRuntimeLocalID(taskSetup['taskName'])
    #Get a list of manually added literals
    linesOfInterrest = linesRestOfFile[enumStartEndPos[self.INDEX_ENUM_TAG]:enumStartEndPos[self.INDEX_ENUM_END]]
    manualAddedLiterals = self.getManuallyAddedLiterals(linesOfInterrest)

    #Determine the length of longest literal
    maxLen = len(taskRuntimeLiteral)

    for entry in taskSetup['runnableCfgList']:
      if len(entry[self.INDEX_LOCAL_ID])> maxLen:
        maxLen = len(entry[self.INDEX_LOCAL_ID])

    for entry in manualAddedLiterals:
      if len(entry)> maxLen:
        maxLen = len(entry)

    #Add the enumHeader to the end of linesHooksHeader
    self.linesHooksHeader.extend(self.LOCAL_ID_ENUM_HEADER)

    value = 0
    comma = ''
    #Add the literal for taskRunTime measurement which has to be always the first one
    literal = taskRuntimeLiteral.ljust(maxLen + 2)
    self.linesHooksHeader.append(self.LITERAL_LINE_PATTERN.format(comma,literal, value))
    #Add all literals according runnableCfgList
    comma = ', '
    for entry in taskSetup['runnableCfgList']:
      value += 1
      literal = entry[self.INDEX_LOCAL_ID].ljust(maxLen)
      self.linesHooksHeader.append(self.LITERAL_LINE_PATTERN.format(comma, literal, value))

    #Now add generatorTag and the explanation text concerning manually adding of literals
    self.linesHooksHeader.extend(self.LOCAL_ID_ENUM_MAN_ADDED_LITERALS__TAG_AND_EXPLANATION)

    #add the manually added literals if there are some
    for entry in manualAddedLiterals:
      value += 1
      literal = entry.ljust(maxLen)
      self.linesHooksHeader.append(self.LITERAL_LINE_PATTERN.format(comma, literal, value))

    #Finally add termination line of the enumeration
    self.linesHooksHeader.append(self.LOCAL_ID_ENUM_TERMINATION_LINE.format(taskSetup['enumName']))


  #####################################################################################################################################################################################################
  def createNewLocalIdEnum(self, taskSetup):

    #Get the taskRuntimeLiteral
    taskRuntimeLiteral = self.createTaskRuntimeLocalID(taskSetup['taskName'])
    #Determine the length of longest literal
    maxLen = len(taskRuntimeLiteral)

    for entry in taskSetup['runnableCfgList']:
      if len(entry[self.INDEX_LOCAL_ID])> maxLen:
        maxLen = len(entry[self.INDEX_LOCAL_ID])

    #Add the enumHeader to the end of linesHooksHeader
    self.linesHooksHeader.extend(self.LOCAL_ID_ENUM_HEADER)

    value = 0
    comma = ''
    #Add the literal for taskRunTime measurement which has to be always the first one
    literal = taskRuntimeLiteral.ljust(maxLen + 2)
    self.linesHooksHeader.append(self.LITERAL_LINE_PATTERN.format(comma, literal, value))
    #Add all literals according runnableCfgList
    comma = ', '
    for entry in taskSetup['runnableCfgList']:
      value += 1
      literal = entry[self.INDEX_LOCAL_ID].ljust(maxLen)
      self.linesHooksHeader.append(self.LITERAL_LINE_PATTERN.format(comma, literal, value))

    #Add enum trailer
    self.linesHooksHeader.extend(self.LOCAL_ID_ENUM_TRAILER.format(taskSetup['enumName']))


  #####################################################################################################################################################################################################
  def getManuallyAddedLiterals(self, linesOfInterrest):
    manualAddedLiterals = []
    linesPureCode = []
    #Remove the comments from the lines
    self.getLinesOfPureCode(linesOfInterrest, linesPureCode)

    for i in range(len(linesPureCode)):
      #Get the current line and clean it
      line = linesPureCode[i]
      line = line.replace(',','')  # Remove the commas
      line = line.replace('\n','') # Remove new line
      line = line.replace('\t','') # Remove tabs
      line = line.strip()          # Remove all leading and trailing blanks

      if len(line):
        # OK, here we have a  line with an literal - just take the literal
        if -1 != line.find('='):
          literal = line[:line.find('=')]
          literal = literal.replace(' ', '')
        else:
          if -1 != line.find(' '):
            literal = line[:line.find(' ')]
          else:
            #No assignment operator, no blanks -> just take the whole line as literal
            literal = line

        #Add the new literal to the list
        manualAddedLiterals.append(literal)

    return manualAddedLiterals
