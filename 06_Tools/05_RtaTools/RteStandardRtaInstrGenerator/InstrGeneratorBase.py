import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + '/../ToolChainCommon')
from ChainCommon import ChainCommon
from XmlGenerationUtils import XmlGenerationUtils

#################################################################################
#
#################################################################################
class InstrGenBase(ChainCommon, XmlGenerationUtils):

  #Supported RteGenerators 
  RTE_GEN_TYPE_DA_VINCI = 'RTE_GEN_TYPE_DA_VINCI'
  RTE_GEN_TYPE_TRESOS   = 'RTE_GEN_TYPE_TRESOS'
  #StepCounters shall be 8 bit values!
  STEP_COUNTER_RANGE = 255



  #The indexes for the runnableGroupsCfg in BasisConfig   [[IDX_RUNNABLE_GROUP_PREFIX][IDX_RUNNABLE_GROUP_SETTING]]
  IDX_RUNNABLE_GROUP_PREFIX  = 0
  IDX_RUNNABLE_GROUP_SETTING = 1

  #Indexes of the two dimensional runnableCfgList [ [INDEX_RUNNABLE], [INDEX_HOOK], [INDEX_LOCAL_ID][INDEX_ENABLED] ]
  INDEX_RUNNABLE    = 0  # Name of runnable in RTE.c
  INDEX_HOOK        = 1  # Name of related hookFunction
  INDEX_LOCAL_ID    = 2  # Name of related localID
  INDEX_ENABLED     = 3  # EnableFlag [True/False] -> RTA instrumentation done or not
  INDEX_MULTI_TASKS = 4  # Flag [True/False] indicating whether this runnable is called from different tasks
  INDEX_STEP_CNT_ID = 5  # Name of related stepCntID

  #The pattern for the stepCounterLiterals
  STEP_CNT_LITERAL_NAME_PATTERN = 'RTE_STEPCNT_{0}_{1}' # {0} -> TaskName, {1} -> RunnableName


  #All possible errors for the instrumentation configuration done by the user
  CFG_ERROR_OK                                        = 0
  CFG_ERROR_RTA_TASK_RUNTIME_DISABLED                 = 1
  CFG_ERROR_RTA_RUNNABLE_RUNTIME_DISABLED             = 2
  CFG_ERROR_RTE_VFB_TRACE_DEFINE_NOT_FOUND_TRESOS     = 3
  CFG_ERROR_RTE_VFB_TRACE_DEFINE_NOT_FOUND_DA_VINCI   = 4
  CFG_ERROR_RTE_NUMBER_OF_RUNNABLES_OUT_OF_RANGE      = 5

  #Constants for the message types - to be used in cfgErrorMsgDict
  MSG_TYPE_WARNING = 0
  MSG_TYPE_ERROR   = 1

  #The configuration error/warning message dictionary
  cfgErrorWarningMsgDict = {
    CFG_ERROR_RTA_TASK_RUNTIME_DISABLED:{'msgType': MSG_TYPE_WARNING,
      'msgText': '''- WARNING: The taskRunTimeMeasurement is completely disabled!
  -> No taskRuntimes will be available in the rtaOutput!

''',
      'shortMsg': 'No taskRuntime measurement!'},
    CFG_ERROR_RTA_RUNNABLE_RUNTIME_DISABLED:{'msgType': MSG_TYPE_WARNING,
      'msgText':'''- WARNING: The runTimeMeasurement of all runnables is completely disabled!
  -> No runnableRuntimes will be available in the rtaOutput!

''',
      'shortMsg': 'No runnableRuntime measurement!'},
    CFG_ERROR_RTE_VFB_TRACE_DEFINE_NOT_FOUND_TRESOS:{'msgType': MSG_TYPE_ERROR,
      'msgText':'''- ERROR: The define RTE_VFB_TRACE could not be found in Rte_Cfg.h!
  -> Either the Rte_Cfg.h is corrupt
     or the format of the Rte_Cfg.h has been changed. In this case the RteStandardRtaInstrGenerator
     has to be updated accordingly!

  This is a severe error!

''',
      'shortMsg': 'RTE_VFB_TRACE define not available in Rte_cfg.h!!!'},
    CFG_ERROR_RTE_VFB_TRACE_DEFINE_NOT_FOUND_DA_VINCI:{'msgType': MSG_TYPE_ERROR,
      'msgText':'''- ERROR: The define RTE_VFB_TRACE could not be found in Rte_Cfg.h!
  -> Most probably the VFB Tracing has been disabled in DaVinciConfigurator.
     Please doublecheck otherwise you won't see any runtime measurements for RTE!

  This is a severe error!

''',
      'shortMsg': 'RTE_VFB_TRACE define not available in Rte_cfg.h!!! VFB Tracing disabled in DaVinciConfigurator???'},
    CFG_ERROR_RTE_NUMBER_OF_RUNNABLES_OUT_OF_RANGE:{'msgType': MSG_TYPE_ERROR,
      'msgText':'''- ERROR: The number of runnables in at least one task exceeds the range of the stepCounter which is {0}
  -> The stepCounters are needed for postMortemAnalysis.

  This is a severe error!

'''.format(STEP_COUNTER_RANGE),
      'shortMsg': 'Too many runnables - range of stepCounter exceeded!!!'},
  }


  #All indexes used in context of partitionInfo
  INDEX_PARTITION_OBJECT = 0
  INDEX_PARTITION_FILE   = 1

  #All the generatorTags:
  GEN_TAG_HOOK_FCT_START          = '___GENERATOR_TAG___TRACE_HOOK_FUNCTIONS___SECTION_START___'
  GEN_TAG_HOOK_FCT_END            = '___GENERATOR_TAG___TRACE_HOOK_FUNCTIONS___SECTION_END___'
  GEN_TAG_INSTR_START             = '___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_START___'
  GEN_TAG_INSTR_END               = '___GENERATOR_TAG___STANDARD_INSTRUMENTATION___SECTION_END___'
  #The generatorTags needed additionally in TraceHooksSourcePather
  GEN_TAG_TASK_CFG_START          = '___GENERATOR_TAG___TASK_CFG_TYPE___SECTION_START___'
  GEN_TAG_TASK_CFG_END            = '___GENERATOR_TAG___TASK_CFG_TYPE___SECTION_END___'
  GEN_TAG_TASK_LUT_START          = '___GENERATOR_TAG___TASK_LUT___SECTION_START___'
  GEN_TAG_TASK_LUT_END            = '___GENERATOR_TAG___TASK_LUT___SECTION_END___'
  GEN_TAG_TASK_CNT_START          = '___GENERATOR_TAG___TASK_CYCLE_COUNTER___SECTION_START___'
  GEN_TAG_TASK_CNT_END            = '___GENERATOR_TAG___TASK_CYCLE_COUNTER___SECTION_END___'
  GEN_TAG_FRAMEWORK_HOOKS_START   = '___GENERATOR_TAG___FRAMEWORK_HOOKS___SECTION_START___'
  GEN_TAG_FRAMEWORK_HOOKS_END     = '___GENERATOR_TAG___FRAMEWORK_HOOKS___SECTION_END___'


  #All the c-files generated by the RteStandardRtaInstrGenerator have that pattern as the end of the file name.
  #The beginning of the name is equal to the partitionName
  TRACE_HOOKS_C_FILE_END_PATTERN = '_Trace_Hooks.c'

  #The string of the 'default partition'. In case we have no multiPartitioning everything is in the defaulPartition
  DEFAULT_PARTITION = 'Rte'

  #The name of generated files 
  RTE_TRACE_HOOK_HEADER = 'Rte_Trace_Hooks.h'
  RTE_TRACE_HOOK_SRC    = DEFAULT_PARTITION + TRACE_HOOKS_C_FILE_END_PATTERN
  RTE_STEP_CNT_HEADER   = 'Rte_StepCounter.h'
  RTE_STEP_CNT_SRC      = 'Rte_StepCounter.c'
  
  #Initialise the class################################################################################################################################################################################
  def __init__(self):
    print ('base')


  #####################################################################################################################################################################################################
  def createTaskRuntimeLocalID(self, taskName):
    PATTERN = 'RTE_{0}_TaskRuntime'
    literal = PATTERN.format(taskName.replace('_', ''))

    return literal


  #This function returns only the pure code of given line, this means it removes all the comment which may be in the line
  # NOTE: Because of the muliLineComments it is necessary that this function is called for really every line of a file.
  #       Only in this way it is able to intepret the comments in the right way.
  #####################################################################################################################################################################################################
  def getPureCodeInLine(self, line, inMultiLineComment):

    pureCode = ''
    # remove all leading and trailing whitespaces, tabs and newLines of the line
    cleanedLine = line.strip('\n')
    cleanedLine = cleanedLine.replace('\t', '  ') #Convert all tabs into whitespaces
    cleanedLine = cleanedLine.strip()

    if inMultiLineComment[0]:
      #Currently we are in a multiLineComment -> Everything until the next '*/' is comment
      idxCommentEnd = cleanedLine.find('*/')
      if -1 != idxCommentEnd:
        #remove that part until the first '*/' from the line, also remove the '*/' itself from the code
        cleanedLine = cleanedLine[idxCommentEnd + 2:]
        # reset the flag indicating that we are in a multiLineComment
        inMultiLineComment[0] = False
      else:
        #No '*/' in the line - the whole line is comment
        #WE ARE DONE HERE!!
        #Empty the cleanedLine to avoid that we run into the while loop below
        cleanedLine = ''

    while len(cleanedLine):
      #We are not in a multiLineComment check whether we have a singleLineComment in the line
      idxSingleLineComment = cleanedLine.find('//')
      idxCommentStart      = cleanedLine.find('/*')
      if -1 == idxSingleLineComment and -1 == idxCommentStart:
        #We have no further comments in the line - all in the line is code
        pureCode = pureCode + cleanedLine
        #WE ARE DONE HERE!!
        #Empty the cleanedLine in order to stop iteration
        cleanedLine = ''
      else:
        #We still have comments in the line
        if -1 == idxSingleLineComment:
          # We have no singleLineComment in the line set its index to maxValue
          idxSingleLineComment = len(cleanedLine)
        elif -1 == idxCommentStart:
          #We have no multiLineCommentStart in the line - set its index to maxValue
          idxCommentStart = len(cleanedLine)

        if idxSingleLineComment < idxCommentStart:
          # We have a valid sinlgeLine comment - all the rest behind '//' is comment
          #Add the part before '//' to pureCode
          pureCode = pureCode + cleanedLine[:idxSingleLineComment]
          #WE ARE DONE HERE!!
          #Empty the cleanedLine in order to stop iteration
          cleanedLine = ''
        else:
          #We have a valid multiLineCommentStart in the line
          #Add the part before '/*' to pureCode
          pureCode = pureCode + cleanedLine[:idxCommentStart]
          #remove that part until the first '/*' from the line
          cleanedLine = cleanedLine[idxCommentStart:]
          #Check whether we have  also a  multiLineCommentEnd in the line
          idxCommentEnd = cleanedLine.find('*/')
          if -1 == idxCommentEnd:
            #We do not have a multiLineCommentEnd in the line - the rest after the '/*' is comment
            #Set the flag indicating that we are in a multiLineComment
            inMultiLineComment[0] = True
            #WE ARE DONE HERE!!
            #Empty the cleanedLine in order to stop iteration
            cleanedLine = ''
          else:
            #We have a multiLineCommentEnd in the line - the part until the first '/*' is comment
            #Remove the comment including '*/'
            cleanedLine = cleanedLine[idxCommentEnd + 2:]

    return pureCode


  #####################################################################################################################################################################################################
  def getLinesOfPureCode(self, codeLinesWithComments, pureCodeLines):
    inMultiLineComment = [False]
    #For sake of safety remove all lines of given list
    del pureCodeLines [:]

    for line in codeLinesWithComments:
      #Get pureCode of current line
      pureCode = self.getPureCodeInLine(line, inMultiLineComment)
      #Add pureCode of current line
      pureCodeLines.append(pureCode + '\n')