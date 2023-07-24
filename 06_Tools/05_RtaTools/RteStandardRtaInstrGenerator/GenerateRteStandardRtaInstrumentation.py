import os
import stat
import re
import sys
import argparse
try:
# python 2
    import tkMessageBox as tkinter_messagebox
except ImportError:
# python 3
    import tkinter.messagebox as tkinter_messagebox

from shutil import copyfile
from datetime import datetime

from InstrGeneratorBase               import InstrGenBase
from RteRtaInstConfigurator           import RteRtaInstConfigurator
from TraceHooksHeaderPatcher          import TraceHooksHeaderPatcher
from TraceHooksSourcePatcher          import TraceHooksSourcePatcher
from TraceHooksSourcePatcherPartition import TraceHooksPatcherPartition
from TraceHooksSourcePartitionCleaner import TraceHooksSourcePartitionCleaner
from StepCounterFilesPatcher          import StepCounterFilesPatcher
from RteLocalIdXmlGenerator           import RteLocalIdXmlGenerator
from LocalIdsShortenList              import GENERIC_LOCAL_ID_SHORTEN_LIST

sys.path.append('../ToolChainCommon')

from ChainCommon              import ChainCommon

#################################################################################
#
#################################################################################
class RteStandardRtaInstrumentationGenerator(InstrGenBase):

  #The error codes
  ERR_OK                           =  0
  ERR_MISSING_ARGUMENT             =  1
  ERR_OUTPUT_PATH_INVALID          =  2
  ERR_RTE_C_NOT_FOUND              =  3
  ERR_RTE_CFG_H_NOT_FOUND          =  4
  ERR_INPUT_CFG_FILE_MISSING       =  5
  ERR_INPUT_CFG_FILE_ERROR         =  6
  ERR_RTE_GEN_NOT_SUPPORTED        =  7
  ERR_XML_PATH_INVALID             =  8
  ERR_OS_TYPE_NOT_SUPPORTED        =  9
  ERR_NUMBER_OF_TASKS_OUT_OF_RANGE = 10

  #The indexes for the shortenLists which have entries of this format: [ IDX_SHORTEN_ORIGIN, IDX_SHORTEN_NEW ]
  IDX_SHORTEN_ORIGIN =  0
  IDX_SHORTEN_NEW    =  1

  #The error Messages Dictionary
  errorMsgDict = \
  {
    ERR_MISSING_ARGUMENT              : 'At least one argument is missing, please ensure that all required arguments are provided!',
    ERR_OUTPUT_PATH_INVALID           : 'Provided output path is not valid !',
    ERR_RTE_C_NOT_FOUND               : 'Rte.c not found, please ensure that it is available at specified output path!',
    ERR_RTE_CFG_H_NOT_FOUND           : 'Rte_Cfg.h not found, please ensure that it is available at specified output path!',
    ERR_INPUT_CFG_FILE_MISSING        : 'InputCfgFile is missing. The InputCfgFile shall provide all information regarding needed files and folders',
    ERR_INPUT_CFG_FILE_ERROR          : 'There is any problem regarding the inputCfgFile (Invalid format, given path or file not available, ...)',
    ERR_RTE_GEN_NOT_SUPPORTED         : 'Provided RTE_GEN_TYPE is unknown. Currently supported RTE_GEN_TYPES are: "RTE_GEN_TYPE_TRESOS" and "RTE_GEN_TYPE_DA_VINCI" ',
    ERR_XML_PATH_INVALID              : 'Provided xmlPath is invalid. Either provide an abs. path or provide a relative path AND the prjRefPath',
    ERR_OS_TYPE_NOT_SUPPORTED         : 'Provided os_type is unknown. Currently supported os_type are: "OS_TYPE_EB_S", "OS_TYPE_EB" and "OS_TYPE_VECTOR" ',
    ERR_NUMBER_OF_TASKS_OUT_OF_RANGE  : 'Too many tasks in the project - one RteGlobalID needed per task and the range for RteGlobalIDs is from 4000 - 4094',
  }

  #The StandardTexts for the final user information
  FINAL_USER_INFO_HEADER_TEXT_OK = '''
  RteStandardRtaInstrumentationGenerator successfully run!
'''
  FINAL_USER_INFO_HEADER_TEXT_ERROR_AND_WARNING = '''
  In the run of the RteStandardRtaInstrumentationGenerator the the following errors or warnings occured:
'''
  FINAL_USER_INFO_TRAILER_TEXT_WARNING_AND_OK = '''
Please continue with the following:

- Check in the updated files
  (Rte_Trace_Hooks.c,  maybe other Rte_xxx_Trace_Hooks.c, Rte_Trace_Hooks.h, Rte_StepCounter.c and Rte_StepCounter.h)
  together with the other rte files.

- Check in also the updated generatorConfigurationFiles (RteInstr_BasisConfig.py and RteInstr_TaskAndRunnableConfig.py)
  which are located in

  {0}

  These files are needed to remember your settings for the next generator run!

''' # {0} -> configurationDirectory

  FINAL_USER_INFO_TRAILER_TEXT_WARNING = '''
  But if it is OK for you then ...

'''

  FINAL_USER_INFO_TRAILER_TEXT_LOG_FILE_HINT = '''
  Please have also a look into the logFile:

  {0}
'''  #{0} -> logFile


  #The warning texts related to the projectSpecific localIdShortenList
  WARNING_TEXT_PRJ_SHORTEN_LIST_NOT_FOUND = '''
No projectSpecific shortenListFile for the localIDs available.
No problem, use the generic shortenList only.
'''

  WARNING_TEXT_PRJ_SHORTEN_LIST_NOT_OK = '''

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
The projectSpecific shortenListFile has been found but something is wrong with it.
Either its format is not OK or the attribute "PROJECT_LOCAL_ID_SHORTEN_LIST" is missing.
Please doubleCheck the file.
--> For this run only the generic shortenList is used.
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

'''


  #The lines of our logFile
  linesLogFile   = []

  #The list of all tasks, will be filled with taskNames provided by OS. Mainly it is needed to keep the order of appearance in the RTE.c
  taskList       = []
  #The dictionary containing the whole information about every task. It has the following structure
  #  taskInfo= {
  #    <__TaskName_0__>:{  'taskName'         :  taskName,
  #                        'partitionName'    :  partitionName,
  #                        'globalID'         :  globIdDefine,
  #                        'enumName'         :  localIdEnum,
  #                        'taskRunTime'      :  True,
  #                        'extendedTask'     :  False,
  #                        'osTaskID'         :  the taskID from the osConfigFile
  #                        'runnableCfgList'  :  [[INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS, INDEX_STEP_CNT_ID ],
  #                                                :
  #                                                :
  #                                               [INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS, INDEX_STEP_CNT_ID ],
  #                     },
  #    <__TaskName_n__>:{  'taskName'         :  taskName,
  #                        'partitionName'    :  partitionName,
  #                        'globalID'         :  globIdDefine,
  #                        'enumName'         :  localIdEnum,
  #                        'taskRunTime'      :  True,
  #                        'extendedTask'     :  False,
  #                        'osTaskID'         :  the taskID from the osConfigFile
  #                        'runnableCfgList'  :  [[ INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS, INDEX_STEP_CNT_ID ],
  #                                                :
  #                                                :
  #                                               [ INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS, INDEX_STEP_CNT_ID ],
  #                     },
  #  }

  taskInfo = {}

  # The dictionary containing all runnables which are called in different tasks. It has the following structure.
  #   runnablesMultipeTasks = {
  #     <__RunnableName_0__>: {
  #       targetPartition: <__partitionName__>,
  #       taskSettings: {
  #         <__TaskName_0__> : [ INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS, INDEX_STEP_CNT_ID ],
  #         <__TaskName_1__> : [ INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS, INDEX_STEP_CNT_ID ],
  #         :
  #         :
  #         <__TaskName_n__> :  [INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS, INDEX_STEP_CNT_ID  ],
  #       },
  #     },
  #     :
  #     :
  #     <__RunnableName_n__>: {
  #       targetPartition: <__partitionName__>,
  #       taskSettings :{
  #         <__TaskName_0__> : [ INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS ],
  #         <__TaskName_1__> : [ INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS ],
  #         :
  #         :
  #         <__TaskName_n__> : [ INDEX_RUNNABLE, INDEX_HOOK, INDEX_LOCAL_ID, INDEX_ENABLED, INDEX_MULTI_TASKS ],
  #       },
  #     },
  #   }
  runnablesMultipeTasks = {}

  # The dictionary containing all objects of TraceHooksPatcherPartition and the name including the full path of the related traceHookFile
  # partitionInfo = {
  #  <__PartitionName_0__>: [ INDEX_PARTITION_OBJECT, INDEX_PARTITION_FILE ],
  #  <__PartitionName_1__>: [ INDEX_PARTITION_OBJECT, INDEX_PARTITION_FILE ],
  #     :
  #     :
  #  <__PartitionName_0__>: [ INDEX_PARTITION_OBJECT, INDEX_PARTITION_FILE ],
  # }

  partitionInfo = {}


  # The dictionary containing additionalFeatureCfg like
  # StepCounter instrumentation enabled
  # selfTestCheckpoint instrumentation enabled
  # additionalFeatureCfg = {
  #   'stepCountersEnabled':True,         or False
  #   'selfTestCheckpointsEnabled':True   or False
  # }

  additionalFeatureCfg = {}
  
  # The list of all tasks in the order of osTaskIDs (0, 1, 2, ...)
  # This list is filled based on the osConfiguration file
  osTaskList = []

  InputCfgFileCheckList = [
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_PROJECT                    , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_BUILD_UNIT                 , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OUTPUT_PATH_SRC            , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OUTPUT_PATH_INCL           , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_GEN_CFG_PATH               , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_SRC   , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_INCL  , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_RTE_GEN_TYPE               , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OS_CFG_FILE                , 'runTest' : ChainCommon.RUN_TEST_FILE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True    },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OS_TYPE                    , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE , 'mandatory' : True    },
  ]                          
  
     
  # argument parsing ############################################################################
  def check_args(self):
    parser = argparse.ArgumentParser(prog="RteStandardRtaInstrGenerator",
                                     formatter_class=argparse.RawTextHelpFormatter,
                                     description="RteStandardRtaInstrumentationGenerator is generating RTE RTA calls in the postgenProcess of Tresos.")

    parser.add_argument('inputCfgFile',
                        action = 'store',
                        help ='The input configuration file in which all relevant files and folders are provided.')
    
    parser.add_argument('-r', '--prjRefPath',
                        action ='store',
                        help = '''The project referencePath is used as a base to determine the absolutePaths for all 
relativePaths given in the corresponding RtaXmlGenerator_InputCfg*.yaml.
This argument is not necessary in case all the paths in the RtaXmlGenerator_InputCfg*.yaml are provided as absolute paths.''')

    parser.add_argument('-x', '--xmlPath',
                        action ='store',
                        help = '''In case the xmlPath is provided the generator will also generate all the localID-Xmls related to RTE.
The xmlPath can be provided as relative path in this case it will be combined with the prjRefPath to build the absolute path.''')

    parser.add_argument('-g', '--gui',
                        action ='store_true',
                        default = False,
                        help = 'enables/disables configuration GUI')
    
    return parser.parse_args()

  #Initialize the class
  def __init__(self):
    print ('RteStandardRtaInstrumentationGenerator started!')

    errorCode    = self.ERR_OK  # @UnusedVariable
    errorInfo    = ''
    inputCfgInfo = []
    refPathDict  = {}
    
    # Init logPat and project - these variables will be updated in case we have a valid inputCfgFile 
    self.logPath    =  self.getDefaultLocationForLogFile()
    self.project    = 'UnknownProject'
    self.buildUnit  = 'UnknownBuildUnit'

    args = self.check_args()

    #Get the GuiEnabled flag
    self.guiEnabled = args.gui

    if not os.path.isfile(args.inputCfgFile):
      errorCode = self.ERR_INPUT_CFG_FILE_MISSING
      errorInfo = self.INFO_TEXT_INPUT_CFG_FILE_MISSING.format(args.inputCfgFile)
      
      #Prepare the logFile
      self.prepareLogFile(inputCfgInfo)
      
    if self.ERR_OK == errorCode:
      inputCfg = self.load_yaml(args.inputCfgFile)
      
      try:
        #Prepare the dictionary required for calling the function checkInputCfgFileAndConvertToAbsPaths()
        if args.prjRefPath:
          refPathDict[ChainCommon.REF_PATH_PRJ] = args.prjRefPath
          
        templateFile = os.path.join(os.getcwd(), 'TemplateFiles\RteStandardRtaInstrGenerator_InputCfg_Template.yaml')
        self.checkInputCfgFileAndConvertToAbsPaths(inputCfg, refPathDict, self.InputCfgFileCheckList, inputCfgInfo, args.inputCfgFile, templateFile)
        
      except Exception as ex:
        print(ex)
        errorInfo = str(ex)
        errorCode = self.ERR_INPUT_CFG_FILE_ERROR
        
      finally:
        if self.INPUT_DICT_KEY_OUTPUT_PATH_SRC in inputCfg:
          if args.prjRefPath:
            self.logPath  = self.getAbsolutePath(args.prjRefPath, inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH_SRC])
          else:
            self.logPath  = inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH_SRC]

        if self.INPUT_DICT_KEY_PROJECT in inputCfg:
          self.project = inputCfg[self.INPUT_DICT_KEY_PROJECT]
        if self.INPUT_DICT_KEY_BUILD_UNIT in inputCfg:
          self.buildUnit = inputCfg[self.INPUT_DICT_KEY_BUILD_UNIT]
          
        self.prepareLogFile(inputCfgInfo)
         
    if self.ERR_OK == errorCode:
      #The very first steps has to be the initialization of the outputPath and the preparation of the logFile!
      #Note: It has to be checked if it is valid - before usage!
      self.outputPathSrc  = inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH_SRC]
      self.outputPathIncl = inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH_INCL]
      self.rteCfgFile     = self.outputPathIncl + '/Rte_Cfg.h'
      
      #get the path to projectSpecific configFile
      self.cfgDir = inputCfg[self.INPUT_DICT_KEY_GEN_CFG_PATH]
      #Add the directory to systemPath
      sys.path.append(self.cfgDir)
      
      #get RteGeneratorType
      self.rteGenType = inputCfg[self.INPUT_DICT_KEY_RTE_GEN_TYPE]
      
      #get OsType
      self.osType = inputCfg[self.INPUT_DICT_KEY_OS_TYPE]
      
      #Check whether we have a xmlPath given - this would mean we have to generate also the localId XMLs for RTE
      if args.xmlPath:
        #Combine prjRefPath with given xmlPath to ensure that we have an absolute path 
        self.xmlPath = self.getAbsolutePath(args.prjRefPath, args.xmlPath)
      else:
        self.xmlPath = None
        
      #Run precondition check
      errorCode = self.checkPreconditions()


    if self.ERR_OK == errorCode:
      # Get the osTasks from the osConfigFile
      self.getTasksFromOsCfgFile(inputCfg[self.INPUT_DICT_KEY_OS_CFG_FILE], self.osTaskList, self.osType)
      if len(self.osTaskList) > self.MAX_NUMBER_RTE_GLOBAL_IDS:
        errorCode = self.ERR_NUMBER_OF_TASKS_OUT_OF_RANGE
    
    if self.ERR_OK == errorCode:
      #Have the combined shortenList for the localIDs generated - the generic and if available the project specific one combined
      self.combinedShortenList = self.createCombinedShortenList()
      #Ensure that the current Rte_Trace_Hook files are available in ouputPath
      self.copyOldTraceHookFilesToOutputPathIfNeeded(inputCfg)
      #Generate an instance of the configurator
      self.configurator = RteRtaInstConfigurator(self.project, self.cfgDir, self.logFile, self.guiEnabled, self.rteGenType)
      #Generate instance of both the sourcePatcher and the headerPatcher
      self.sourcePatcher      = TraceHooksSourcePatcher(self.DEFAULT_PARTITION, self.outputPathSrc + '/' + self.RTE_TRACE_HOOK_SRC, self.rteGenType)
      self.headerPatcher      = TraceHooksHeaderPatcher(self.outputPathIncl)
      self.stepCounterPatcher = StepCounterFilesPatcher(self.outputPathIncl, self.outputPathSrc, self.rteGenType)

      #Run the generator
      self.doIt()
    else:
      #Preconditions are not fulfilled
      self.generateUserErrorInfo(errorCode, errorInfo)
      
    
    print(self.INFO_TEXT_LOG_FILE_GENERATION.format(self.logFile))

    print ('RteStandardRtaInstrumentationGenerator terminated!')

  #########################################################################################################################################################
  def doIt(self):
    errorWarningTextForTraceHookHeader = []

    #Get all needed infos from RTE.c
    self.ExtractRequiredInfoFromRteSourceFiles()

    #Collect all runnables called from different tasks
    self.collectAllRunnablesCalledInMutipleTasks()

    #Based on the taskList create instances of TraceHooksPatcherPartition - one per partition
    self.createInstancesOfTraceHooksPatcherPartition()
    # Open a userDialog to adapt the instrumentationConfiguration (disable/enable rtaInstrumentation of runnables and tasks)
    cfgErrorWarningList = self.configurator.configurate(self.taskInfo, self.additionalFeatureCfg, self.rteCfgFile, errorWarningTextForTraceHookHeader)
    #Now it is time to have the traceHookFiles updated!
    self.headerPatcher.updateTraceHooksHeader(self.taskList, self.taskInfo, errorWarningTextForTraceHookHeader)
    self.sourcePatcher.updateTraceHooksSource(self.taskList, self.taskInfo, self.runnablesMultipeTasks, self.additionalFeatureCfg)

    #Have the traceHooksSources updated for all partitions we have
    allPartitions = list(self.partitionInfo.keys())
    for partition in allPartitions:
      self.partitionInfo[partition][self.INDEX_PARTITION_OBJECT].updateTraceHooksSource(self.taskList, self.taskInfo, self.runnablesMultipeTasks, self.additionalFeatureCfg)

    #Cleanup all files of removed partitions
    self.cleanupTraceHookSourcesOfRemovedPartitions()

    #Update the stepCounterFiles
    self.stepCounterPatcher.updateStepCounterFiles(self.taskList, self.taskInfo, self.additionalFeatureCfg)
    
    if self.xmlPath:
      #xmlPath is provided this means we have to generate the localID-XMLs related to RTE 
      localXmlGenerator  = RteLocalIdXmlGenerator(self.xmlPath)
      localXmlGenerator.generateLocalIdXmls(self.taskInfo)

    #Generate the final user info
    self.generateFinalUserInfo(cfgErrorWarningList)


  #########################################################################################################################################################
  def cleanupTraceHookSourcesOfRemovedPartitions(self):
    #Get all traceHookSources generated by RteStandardRtaInstrGenerator
    allGeneratedTraceHookSources = self.GetAll_C_FilesGeneratedByRteStandardRtaInstrGenerator_WithAbsPath(self.outputPathSrc)
    #Find files which are not needed anymore
    # The StandardHoockSoureFile (Rte_Trace_Hooks.c) is needed in any case - it must not be deleted or cleaned up here
    RTE_TRACE_HOOK_FILE = self.DEFAULT_PARTITION + self.TRACE_HOOKS_C_FILE_END_PATTERN
    notNeededFiles = []
    for traceHookSource in allGeneratedTraceHookSources:
      if RTE_TRACE_HOOK_FILE != os.path.basename(traceHookSource):
        #Ok it is not the standardHookFile - check if this file is still needed
        fileStillNeeded = False
        allPartitions = list(self.partitionInfo.keys())
        for partition in allPartitions:
          if traceHookSource == self.partitionInfo[partition][self.INDEX_PARTITION_FILE]:
            #Ok this file is still needed
            fileStillNeeded = True
            break

        if not fileStillNeeded:
          #This file is not needed any more as the related partition has been removed - add it to the list
          notNeededFiles.append(traceHookSource)

    if len(notNeededFiles):
      #There are files which are not needed any more - clean them up as much as possible
      TraceHooksSourcePartitionCleaner(notNeededFiles)

  #########################################################################################################################################################
  def prepareLogFile(self, inputCfgInfo):
    #check if file exists
    self.logFile = self.getLogFile()
    if os.path.isfile(self.logFile):
      # file already exists - remove writeProtection and open it
      st_mode = os.stat(self.logFile).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(self.logFile, st_mode)

    #Add new lines
    self.linesLogFile.append('\n' * 2)
    #Add headerLine
    self.linesLogFile.append('LogFile of the RteStandardRtaInstrGenerator')
    #Add new lines
    self.linesLogFile.append('\n' * 2)
    #ProjectInfo and date
    self.linesLogFile.append('Project:   {}\n'.format(self.project))
    self.linesLogFile.append('BuildUnit: {}\n'.format(self.buildUnit))
    self.linesLogFile.append('Date:      {}\n'.format(datetime.now().strftime('%d.%m.%Y %H:%M:%S')))
    #Add new lines
    self.linesLogFile.append('\n' * 2)
    #Add lines given by 
    self.linesLogFile.extend(inputCfgInfo)
    #Add new lines
    self.linesLogFile.append('\n' * 2)
    

    #Write all lines to logFile to ensure that it can be written by the configurator afterwards as well
    self.writeLinesintoFile(self.logFile, self.linesLogFile)


  #########################################################################################################################################################
  def getLogFile(self):
    #Check whether given outputPath exists - if yes then use it as the preferred location for the logFile
    if os.path.exists(self.logPath):
      logFilePath = self.logPath
    else:
      logFilePath = self.getDefaultLocationForLogFile()

    logFile = logFilePath + '/{0}_{1}_StandardRtaInstGen.log'.format(self.project, self.buildUnit)

    return logFile


  #########################################################################################################################################################
  def createInstancesOfTraceHooksPatcherPartition(self):
    #Loop over all tasks and create one object of
    allTasks = list(self.taskInfo.keys())

    for task in allTasks:
      #Get the partitionInfo of current task
      partition = self.taskInfo[task].get('partitionName')

      #Check if it is not the 'RTE' partition - as this is the 'default' partition which we have acually only in case we have no multi partitioning
      if partition.upper() != self.DEFAULT_PARTITION.upper():
        if not partition in self.partitionInfo:
          #This is a new partition create an instance of the class TraceHooksPatcherPartition
          traceHookFile = self.outputPathSrc + '/' + partition + self.TRACE_HOOKS_C_FILE_END_PATTERN
          #Ensure that we have no backslashes in the path
          traceHookFile = traceHookFile.replace('\\', '/')
          obj           = TraceHooksPatcherPartition(partition, traceHookFile)
          #And add a new key to the partitionInfo dict
          self.partitionInfo[partition] = [obj, traceHookFile]


  #Generate the final user info ##########################################################################################################################################
  def generateUserErrorInfo(self, errorCode, errorInfo):
    print ('''Error happened during generatorRun: 
{0} 

'''.format(self.errorMsgDict[errorCode]))
    
    #Create userInformationWindow in case GUI is enabled
    errorExpl = self.errorMsgDict.get(errorCode, 'Unknown error!!')
    if self.ERR_OK != errorCode:
      if self.guiEnabled:
        tkinter_messagebox.showerror("RteStandardRtaInstrumentationGenerator", errorExpl)

      #Add the error information also to the logFile
      errorText = '''!!! Error !!!
  The generator could not be run successfully due to the folling error:

    -> '''

      #Get all lines which are already written to the logFile
      self.linesLogFile = self.getLinesOfFile(self.logFile)

      #Add the errorInformation
      self.linesLogFile.append(errorText)
      self.linesLogFile.append(errorExpl)
      self.linesLogFile.append('\n')
      self.linesLogFile.append(errorInfo)
      self.linesLogFile.append('\n' * 2)

      #Write all lines to logFile to ensure that it can be written by the configurator afterwars as well
      self.writeLinesintoFile(self.logFile, self.linesLogFile)


  ###########################################################################################################################################################################
  def generateFinalUserInfo(self, cfgErrorWarningList):

    isError    = False
    infoString = ''

    if not len(cfgErrorWarningList):
      #ErrorList is empty - fine!
      infoString += self.FINAL_USER_INFO_HEADER_TEXT_OK
      infoString += self.FINAL_USER_INFO_TRAILER_TEXT_WARNING_AND_OK.format(self.cfgDir)
    else:
      #OK we have some errors/warnings get all of them
      infoString += self.FINAL_USER_INFO_HEADER_TEXT_ERROR_AND_WARNING
      for entry in cfgErrorWarningList:
        errorMessage = self.cfgErrorWarningMsgDict.get(entry)
        if errorMessage:
          infoString += errorMessage['msgText']
          print(infoString)
          
          if self.MSG_TYPE_ERROR == errorMessage['msgType']:
            isError = True
        else:
          infoString += 'Unknown errorMessage!'

      #Check whether we had an error
      if not isError:
        infoString += self.FINAL_USER_INFO_TRAILER_TEXT_WARNING
        infoString += self.FINAL_USER_INFO_TRAILER_TEXT_WARNING_AND_OK.format(self.cfgDir)


    #Update the logFile
    #Get all lines which are already written to the logFile
    self.linesLogFile = self.getLinesOfFile(self.logFile)

    #Add the information
    infoText = 'Final result: \n\n'
    self.linesLogFile.append(infoText)
    self.linesLogFile.append(infoString)
    self.linesLogFile.append('\n' * 2)

    #Write all lines to logFile to ensure that it can be written by the configurator afterwards as well
    self.writeLinesintoFile(self.logFile, self.linesLogFile)

    #Create userInformationWindow in case GUI is enabled
    if self.guiEnabled:
      if len(cfgErrorWarningList):
        #We had some errors/warnings - add the hint to the logFile
        infoString += self.FINAL_USER_INFO_TRAILER_TEXT_LOG_FILE_HINT.format(self.logFile)
      #Create messageBox
      tkinter_messagebox.showinfo("RteStandardRtaInstrumentationGenerator", infoString)


  #Check if all required preconditions are fulfilled ######################################################################################################################
  def checkPreconditions(self):
    errorCode = self.ERR_OK

    #Check whether we have at least one c-file generated by tresos
    fileList = self.GetAll_C_FilesGeneratedByTresos_WithAbsPath(self.outputPathSrc)
    if not len(fileList):
      #No tresosGenerated files found in provided outputPath!
      errorCode = self.ERR_RTE_C_NOT_FOUND

    if self.ERR_OK == errorCode:
      if not os.path.isfile(self.rteCfgFile):
        #Rte.c can not be found in provided outputPath!
        errorCode = self.ERR_RTE_CFG_H_NOT_FOUND
        
    if self.ERR_OK == errorCode:
      if(     (self.RTE_GEN_TYPE_DA_VINCI  !=  self.rteGenType)
          and (self.RTE_GEN_TYPE_TRESOS    !=  self.rteGenType)
        ):
        #rteGenerator not supported
        errorCode = self.ERR_RTE_GEN_NOT_SUPPORTED 

    if self.ERR_OK == errorCode:
      if(     (self.OS_TYPE_EB_S   !=  self.osType)
          and (self.OS_TYPE_EB     !=  self.osType)
          and (self.OS_TYPE_VECTOR !=  self.osType)
        ):
        #rteGenerator not supported
        errorCode = self.ERR_OS_TYPE_NOT_SUPPORTED 

    if self.ERR_OK == errorCode:
      if self.xmlPath:
        if not os.path.isdir(self.xmlPath):
          #Given xmlPath is invalid
          errorCode = self.ERR_XML_PATH_INVALID

    return errorCode

  ###########################################################################################################################################################################
  def copyOldTraceHookFilesToOutputPathIfNeeded(self, inputCfg):

    # Check whether the rte_eb_check_in_path is different then the outputPath
    # Note: It may be that these path are exactly the same 
    if (inputCfg[self.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_INCL] != self.outputPathIncl):
      
      fileInCheckInPath = inputCfg[self.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_INCL] + '/' + self.RTE_TRACE_HOOK_HEADER
      #Find the TraceHeaderFile in checkInPath and copy it to the output path
      if os.path.isfile(fileInCheckInPath):
        #Remove writeProtection of related file in the outputPath in case it exists there already
        fileInOutputPath = self.outputPathIncl + '/' + self.RTE_TRACE_HOOK_HEADER
        if os.path.isfile(fileInOutputPath):
          st_mode = os.stat(fileInOutputPath).st_mode | stat.S_IWRITE | stat.S_IREAD
          os.chmod(fileInOutputPath, st_mode)

        #Copy the file from the checkInPath to the outputPath
        copyfile(fileInCheckInPath, fileInOutputPath)

      #Find the StepCounterHeaderFile in checkInPath and copy it to the outputPath
      fileInCheckInPath = inputCfg[self.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_INCL] + '/' + self.RTE_STEP_CNT_HEADER 
      if os.path.isfile(fileInCheckInPath):
        #Remove writeProtection of related file in the outputPath in case it exists there already
        fileInOutputPath = self.outputPathIncl + '/' + self.RTE_STEP_CNT_HEADER
        if os.path.isfile(fileInOutputPath):
          st_mode = os.stat(fileInOutputPath).st_mode | stat.S_IWRITE | stat.S_IREAD
          os.chmod(fileInOutputPath, st_mode)

        #Copy the file from the checkInPath to the outputPath
        copyfile(fileInCheckInPath, fileInOutputPath)

    if (inputCfg[self.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_SRC] != self.outputPathSrc):

      #Get all the c-files generated by RteStandardRtaInstrGenerator
      allTraceHookFiles = self.GetAll_C_FilesGeneratedByRteStandardRtaInstrGenerator_WithRelPath(inputCfg[self.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_SRC])

      for traceHookFile in allTraceHookFiles:
        #Remove writeProtection of related file in the outputPath in case it exists there already
        fileInOutputPath = self.outputPathSrc + traceHookFile
        if os.path.isfile(fileInOutputPath):
          st_mode = os.stat(fileInOutputPath).st_mode | stat.S_IWRITE | stat.S_IREAD
          os.chmod(fileInOutputPath, st_mode)

        #Create the subFolder if it does not exist
        if not os.path.exists(os.path.dirname(fileInOutputPath)):
          os.makedirs(os.path.dirname(fileInOutputPath))

        #Copy the file from the checkInPath to the outputPath
        copyfile(inputCfg[self.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_SRC] + traceHookFile, fileInOutputPath)

      #Find the StepCounterSourceFile in checkInPath and copy it to the outputPath
      fileInCheckInPath = inputCfg[self.INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_SRC] + '/' + self.RTE_STEP_CNT_SRC
      if os.path.isfile(fileInCheckInPath):
        #Remove writeProtection of related file in the outputPath in case it exists there already
        fileInOutputPath = self.outputPathSrc + '/' + self.RTE_STEP_CNT_SRC
        if os.path.isfile(fileInOutputPath):
          st_mode = os.stat(fileInOutputPath).st_mode | stat.S_IWRITE | stat.S_IREAD
          os.chmod(fileInOutputPath, st_mode)

        #Copy the file from the checkInPath to the outputPath
        copyfile(fileInCheckInPath, fileInOutputPath)

  ############################################################################################################################################################################
  def GetAll_C_FilesGeneratedByRteStandardRtaInstrGenerator_WithRelPath(self, path):
    fileList = []
    for root, dirs, files in os.walk(path):  # @UnusedVariable
      for name in files:
        if name.endswith(self.TRACE_HOOKS_C_FILE_END_PATTERN):
          if root != path:
            #File found in a subDirectory of path - add also the relative path
            relPath = root[len(path):]
            File = os.path.join(relPath, name)
          else:
            File = '/' + name
          #Ensure that we have only slashes in the path
          File = File.replace('\\', '/')
          fileList.append(File)

    return fileList


  ############################################################################################################################################################################
  def GetAll_C_FilesGeneratedByTresos_WithAbsPath(self, path):
    fileList = []
    for root, dirs, files in os.walk(path):  # @UnusedVariable
      for name in files:
        if not name.endswith(self.TRACE_HOOKS_C_FILE_END_PATTERN):
          if name.endswith('.c'):
            File = os.path.join(root, name)
            #Ensure that we have only slashes in the path
            File = File.replace('\\', '/')
            fileList.append(File)

    return fileList


  ############################################################################################################################################################################
  def GetAll_C_FilesGeneratedByRteStandardRtaInstrGenerator_WithAbsPath(self, path):
    fileList = []
    for root, dirs, files in os.walk(path):  # @UnusedVariable
      for name in files:
        if name.endswith(self.TRACE_HOOKS_C_FILE_END_PATTERN):
          if name.endswith('.c'):
            File = os.path.join(root, name)
            #Ensure that we have only slashes in the path
            File = File.replace('\\', '/')
            fileList.append(File)

    return fileList


  ############################################################################################################################################################################
  def ExtractRequiredInfoFromRteSourceFiles(self):
    # All values for 'state'
    STATE_BEFORE_TASK = 0
    STATE_IN_TASK     = 1

    #All values for 'subState'
    SUBSTATE_BEFORE_TRIPLE  = 0
    SUBSTATE_START_FOUND    = 1
    SUBSTATE_RUNNABLE_FOUND = 2

    PATTERN_TASK_START = r' *TASK\(([\S]*)\)'
    PATTERN_TASK_END   = r' *\} *\/\* *TASK\([\S]*\) *\*\/'

    PATTERN_TRIPLE_START      = r' *([\S]*)_Start\(\);'
    PATTERN_TRIPLE_RUNNABLE   = r' *([\S]*)\([\s\S]*\);'
    PATTERN_TRIPLE_RETURN     = r' *([\S]*)_Return\(\);'

    PATTERN_EXTENDED_TASK_TRESOS = '(void)Rte_WaitGetClearEvent{0}('  # {0} Has to be the name of the partition without leading 'Rte'
    PATTERN_EXTENDED_TASK_DA_VINC = '(void)GetEvent({0},&ev)'  # {0} Has to be the name of the task

    #All needed matchObjecst to find triples of StartHoook, Runnable and ReturnHook
    matchObjTripleStart                 = None
    matchObjTripleRunnable              = None
    matchObjTripleReturn                = None
    matchObjPotentialNextTripleStart    = None
    matchObjPotentialNextTripleRunnable = None

    taskName               = ''

    #Get all tresosGenerated Files
    allRteFiles = self.GetAll_C_FilesGeneratedByTresos_WithAbsPath(self.outputPathSrc)

    for rteFile in allRteFiles:

      #Get all lines of the current file
      lines = self.getLinesOfFile(rteFile)
      #Get the partitionName from the fileName
      partitionName = os.path.basename(rteFile).replace('.c','')
      #Reset state and subState - to ensure the correct states at the beginning of a new file
      state    = STATE_BEFORE_TASK
      subState = SUBSTATE_BEFORE_TRIPLE

      inMultiLineComment = [False]
#      RteNoComment = [] # Generation of the sourceFile without any comments - for visual doublecheck  with beyondCompare if needed
      for line in lines:

        #Get effective code in line without any comments
        pureCode = self.getPureCodeInLine(line, inMultiLineComment)

#        RteNoComment.append(pureCode + '\n')
        if len(pureCode):
          #First remove all whitespaces which are potentually in the line - to increase the robustness
          pureCode = pureCode.replace(' ', '')

          #Check whether this line is the start of the next taskBody
          matchObj = re.match(PATTERN_TASK_START, pureCode)
          if matchObj:
            #OK start of next taskBody found
            state = STATE_IN_TASK
            subState = SUBSTATE_BEFORE_TRIPLE
            #Get taskName from matchObject
            taskName = matchObj.group(1)
            #Add a new task to taskInfo
            self.addNewTask(partitionName, taskName)

          elif STATE_IN_TASK == state:
            #Check whether we reached the end of the taskBody
            #Note: Here the origin line has to be used as also the comment is needed for determination
            if re.match(PATTERN_TASK_END, line):
              #OK end of taskBody found
              state = STATE_BEFORE_TASK
            #Check whether we have an extended task - is the (basic) function  'Rte_WaitGetClearEvent' directly called in this line??
            elif pureCode.startswith(PATTERN_EXTENDED_TASK_TRESOS.format('')):
              #Call of function Rte_WaitGetClearEvent found - set the extended flag in taskConfig
              self.setTaskExtendedFlag(partitionName, taskName)
            #Check whether we have an extended task - is the function 'Rte_WaitGetClearEvent<__PartitionName___> ' called in this line
            #NOTE: In case of mulitPartitioning there is a separate Rte_WaitGetClearEvent-function per partition with the partitionName in the function name
            elif pureCode.startswith(PATTERN_EXTENDED_TASK_TRESOS.format(partitionName[len('Rte'):])):
              #Call of function Rte_WaitGetClearEvent found - set the extended flag in taskConfig
              self.setTaskExtendedFlag(partitionName, taskName)
            #Check whether we have an extended task - is the function 'GetEvent' called in this line  
            elif pureCode.startswith(PATTERN_EXTENDED_TASK_DA_VINC.format(taskName)):
              #Call of function GetEvent found - set the extended flag in taskConfig
              self.setTaskExtendedFlag(partitionName, taskName)
            else:
              #Nothing special (no endTask-Line, no extendedTask-determination line
              # Look for triples
              if SUBSTATE_BEFORE_TRIPLE == subState:
                #Check whether we have the call of a startTraceFunction
                matchObjTripleStart = re.match(PATTERN_TRIPLE_START, pureCode)
                if matchObjTripleStart:
                  #Ok this is the next start, set related state and reset the potentials
                  subState = SUBSTATE_START_FOUND
                  matchObjPotentialNextTripleStart    = None
                  matchObjPotentialNextTripleRunnable = None

              elif SUBSTATE_START_FOUND == subState:
                #Check whether this is the related returnHook
                matchObjTripleReturn = re.match(PATTERN_TRIPLE_RETURN, pureCode)
                if matchObjTripleReturn and (matchObjTripleStart.group(1) == matchObjTripleReturn.group(1) ):
                  #Ok this is the related returnHook.  As we have not found the runnable just go back to SUBSTATE_BEFORE_TRIPLE
                  subState = SUBSTATE_BEFORE_TRIPLE
                else:
                  #Check whether we have a runnable found
                  matchObjTripleRunnable = re.match(PATTERN_TRIPLE_RUNNABLE, pureCode)
                  if matchObjTripleRunnable: # and ( -1 != matchObjTripleStart.group(1).find(matchObjTripleRunnable.group(1)) ): <- second part of statement commented out as it is not necessarily the case that the runnableName is part of hookName!
                    #Matching runnable found
                    subState = SUBSTATE_RUNNABLE_FOUND
                    #To increase the robustness check whether the runnableName is part of the startHook
                    if -1 != matchObjTripleStart.group(1).find(matchObjTripleRunnable.group(1)):
                      #Ok it is the related runnable for sure
                      matchObjPotentialNextTripleStart    = None
                      matchObjPotentialNextTripleRunnable = None
                    else:
                      #It could be also the next startHook in case the returnHook is completely missing
                      #Just store it
                      matchObjPotentialNextTripleStart = re.match(PATTERN_TRIPLE_START, pureCode)

              #Check whether we have a returnHook
              elif SUBSTATE_RUNNABLE_FOUND == subState:
                matchObjTripleReturn = re.match(PATTERN_TRIPLE_RETURN, pureCode)
                if matchObjTripleReturn:
                  #Is it the returnHook related to previous found startHook
                  if matchObjTripleStart.group(1) == matchObjTripleReturn.group(1):
                    #OK call to related returnTraceFunction found
                    #Ensure that we have the runnableName only without trailing assignments
                    idx = matchObjTripleRunnable.group(1).find('=')
                    if -1 != idx:
                      #We have an assingement operator in the supposed runnableName - take only the part after the '='
                      runnable = matchObjTripleRunnable.group(1)[idx+1:]
                    else:
                      #We have the pure runnableName already
                      runnable = matchObjTripleRunnable.group(1)

                    self.addNewTraceHook(taskName, runnable, matchObjTripleStart.group(1))
                    #Reset subState to start the search for a valid triple from new
                    subState = SUBSTATE_BEFORE_TRIPLE
                  elif matchObjPotentialNextTripleStart and matchObjPotentialNextTripleRunnable and matchObjPotentialNextTripleStart.group(1) == matchObjTripleReturn.group(1):
                    #Ok we found the returnHook related to the potenialNextStart and potentialNextRunnable
                    #Ensure that we have the runnableName only without trailing assignments
                    idx = matchObjPotentialNextTripleRunnable.group(1).find('=')
                    if -1 != idx:
                      #We have an assingement operator in the supposed runnableName - take only the part after the '='
                      runnable = matchObjPotentialNextTripleRunnable.group(1)[idx+1:]
                    else:
                      #We have the pure runnableName already
                      runnable = matchObjPotentialNextTripleRunnable.group(1)

                    self.addNewTraceHook(taskName, runnable, matchObjPotentialNextTripleStart.group(1))
                    #Reset subState to start the search for a valid triple from new
                    subState = SUBSTATE_BEFORE_TRIPLE
                    matchObjPotentialNextTripleStart    = None
                    matchObjPotentialNextTripleRunnable = None
                else:
                  if matchObjPotentialNextTripleStart:
                    # We have a potential Next start
                    #Get the next runnable
                    matchObjPotentialNextTripleRunnable = re.match(PATTERN_TRIPLE_RUNNABLE, pureCode)
                  else:
                    #check whether it is a start
                    matchObj = re.match(PATTERN_TRIPLE_START, pureCode)
                    if matchObj:
                      #Ok this is the next start, set related state and reset the potentials
                      matchObjTripleStart = matchObj
                      subState = SUBSTATE_START_FOUND
                      matchObjPotentialNextTripleStart    = None
                      matchObjPotentialNextTripleRunnable = None

#      self.writeLinesintoFile(rteFile + '.txt', RteNoComment)


  ###########################################################################################################################################################################################
  def setTaskExtendedFlag(self, partitionName, taskName):  # @UnusedVariable
    #Set the extendedFlag
    self.taskInfo[taskName]['extendedTask'] = True


  ##########################################################################################################################################################################################
  def addNewTask(self, partitionName, taskName):
    #Check if this is a new task
    if not taskName in self.taskInfo:

      #First add the new task to the taskList
      self.taskList.append(taskName)
      #Assemble name of globalIdDefine
      globIdDefine = 'RTE_GLOBAL_ID_{0}'.format(taskName)
      #Assemble name of related localIdEnumeration
      localIdEnum = 'RTE_t_{0}_LocalIDs'.format(taskName.replace('_',''))
      
      # Determine the osTaskID for given task, the order of the list is according the IDs: 0, 1, 2
      for idx in range(len(self.osTaskList)):
        if taskName == self.osTaskList[idx]:
          osTaskID = idx
          break
      else:
        # No matching taskName found - set the maxValue for RteGlobalIDs
        osTaskID = self.MAX_NUMBER_RTE_GLOBAL_IDS - 1

      #Add the new task to the dictionary collecting all the information concerning the tasks and related runnables
      self.taskInfo[taskName]= { 'taskName'         :  taskName,
                                 'partitionName'    :  partitionName,
                                 'globalID'         :  globIdDefine,
                                 'enumName'         :  localIdEnum,
                                 'taskRunTime'      :  True,
                                 'extendedTask'     :  False,
                                 'osTaskID'         :  osTaskID,
                                 'runnableCfgList'  :  []}

  ##########################################################################################################################################################################################
  def addNewTraceHook(self, taskName, runnable, hookFct):
    #Flag indicating whether there is already one entry in list
    notInList = True

    #Get current list of hooks for given task
    runnableCfgs = self.taskInfo[taskName]['runnableCfgList']

    #Check whether there is already one entry for this hookFunction the list. Therefore we are checking the runnables
    for entry in runnableCfgs:
      if entry[self.INDEX_RUNNABLE] == runnable:
        notInList = False

    #Only update the list in case the runnable is really new  - to avoid double entries
    if notInList:
      localID   = self.assembleLocalIDName(taskName, runnable)
      stepCntID = self.STEP_CNT_LITERAL_NAME_PATTERN.format(taskName, runnable)

      runnableCfgs.append([runnable, hookFct, localID, True, False, stepCntID])
      self.taskInfo[taskName]['runnableCfgList'] = runnableCfgs


  ##########################################################################################################################################################################################
  def collectAllRunnablesCalledInMutipleTasks(self):

    #Get a list keys of all entries in taskInfoDict
    allTasks = list(self.taskInfo.keys())

    #Now look for runnables called in more than one task

    for outerIdx in range(len(allTasks) - 1):
      #Get the runnableCfgList with outerIdx
      outerList = self.taskInfo[allTasks[outerIdx]]['runnableCfgList']
      #Loop over all entries in  outerList
      for outerEntry in outerList:
        #Check if this entry has been already marked as multipe
        if not outerEntry[self.INDEX_MULTI_TASKS]:
          #Not marked - get its runnable
          runnableOuter = outerEntry[self.INDEX_RUNNABLE]
          #Now loop overall remaining dictEntries in taskInfo dictionary
          for innerIdx in range(outerIdx +1, len(allTasks)):
            #Get the list with innerIdx
            innerList = self.taskInfo[allTasks[innerIdx]]['runnableCfgList']
            #Now run over the listInner and look for the same runnable
            for innerEntry in innerList:
              runnableInner = innerEntry[self.INDEX_RUNNABLE]
              if runnableOuter == runnableInner:
                #Ok the same runnable found
                #Check if this is the first time we found this runnable
                if not runnableOuter in self.runnablesMultipeTasks:
                  #Create a new entry -again a dict -  in dict with the runnableName as key
                  self.runnablesMultipeTasks[runnableOuter] = {}
                  self.runnablesMultipeTasks[runnableOuter]['taskSettings'] = {}
                  #Add outerEntry to the recently created dict using the taskName as key and set the multipleTaskFlag
                  self.runnablesMultipeTasks[runnableOuter]['taskSettings'][allTasks[outerIdx]] = outerEntry
                  outerEntry[self.INDEX_MULTI_TASKS] = True

                #In any case add innerEntry to the dict of current Runnable and set the multipleTaskFlag
                self.runnablesMultipeTasks[runnableInner]['taskSettings'][allTasks[innerIdx]] = innerEntry
                innerEntry[self.INDEX_MULTI_TASKS] = True
                #Terminate loop over innerList as we found already a matching runnable - it is ensured by that no runnable is twice in one list (by function addNewTraceHook)
                break

    #Determine the targetPartitions of the runnables
    allRunnables = list(self.runnablesMultipeTasks.keys())
    for runnable in allRunnables:
      allPartitions = []
      #Get all taskSettings
      allTasks = list(self.runnablesMultipeTasks[runnable]['taskSettings'].keys())
      for task in allTasks:
        partitionNotInList = True
        #get the partition in which the task is running
        partitionOfTask = self.taskInfo[task]['partitionName']
        #Check whether we have this partion already in our list
        for partition in allPartitions:
          if partition ==  partitionOfTask:
            partitionNotInList = False
            break

        if partitionNotInList:
          #This is a new partition - add it to the list
          allPartitions.append(partitionOfTask)

      if 1 < len(allPartitions):
        #We have at least two partions in which this runnable is called -> target partition is the default partition
        self.runnablesMultipeTasks[runnable]['targetPartition'] = self.DEFAULT_PARTITION
      else:
        #This runnable is always called in the same partion -> just assing given partition
        self.runnablesMultipeTasks[runnable]['targetPartition'] = allPartitions[0]

  #####################################################################################################################################################################################################
  def assembleLocalIDName(self, taskName, runnableName):
    PATTERN = 'RTE_{0}_{1}'

    shortName = runnableName
    for originalStr, newStr in self.combinedShortenList:

      idx = shortName.upper().find(originalStr.upper())
      while -1 != idx:
        shortName = shortName[:idx] + newStr + shortName[idx + len(originalStr):]
        idx = shortName.upper().find(originalStr.upper())

    #Remove leading and trailing Substrings
    #Remove multiple underscors in a row
    shortName = shortName.strip('_')
    shortName = shortName.replace('_' * 4, '_')
    shortName = shortName.replace('_' * 3, '_')
    shortName = shortName.replace('_' * 2, '_')

    literal = PATTERN.format(taskName.replace('_', ''), shortName)

    return literal


  #####################################################################################################################################################################################################
  def createCombinedShortenList(self):
    combinedshortenList = []
    copyTemplateFile = True

    #Check wether we have a projectSpecific shortenList
    prjShortenFile = self.cfgDir + '/RteInstr_LocalIdShortenList.py'
    if os.path.isfile(prjShortenFile):
      #File exists - try to import the projectSpecific shortenList
      try:
        import RteInstr_LocalIdShortenList  # @UnresolvedImport
      except:
        print (self.WARNING_TEXT_PRJ_SHORTEN_LIST_NOT_OK)
      else:
        #Import was successful - check whether the expected attribute is available
        if not hasattr(RteInstr_LocalIdShortenList, 'PROJECT_LOCAL_ID_SHORTEN_LIST'):
          print (self.WARNING_TEXT_PRJ_SHORTEN_LIST_NOT_OK)
        else:
          #Anything is OK - copy the projectSpecific shortenList to the combined one
          combinedshortenList.extend(RteInstr_LocalIdShortenList.PROJECT_LOCAL_ID_SHORTEN_LIST)
          copyTemplateFile = False
    else:
      #projectSpecific shortenlist not available
      print (self.WARNING_TEXT_PRJ_SHORTEN_LIST_NOT_FOUND)

    if copyTemplateFile:
      # projectShortenFile is not available or corrupt - copy the templateFile that it can be used at the next run
      if os.path.isfile(prjShortenFile):
        st_mode = os.stat(prjShortenFile).st_mode | stat.S_IWRITE | stat.S_IREAD
        os.chmod(prjShortenFile, st_mode)


      templateFile = os.path.dirname(os.path.realpath(__file__)) + '/TemplateFiles/RteInstr_LocalIdShortenList_Template.py'
      copyfile(templateFile, prjShortenFile)

    #Remove double entries from the list - we must not have two or more etries with the same originSubString
    self.removeDoublesFrom2DimensionalList(combinedshortenList, self.IDX_SHORTEN_ORIGIN)
    #Now add all the entries of the genericList to the combinedShortenList
    #But add only these entries which are not in the projectSpecific list
    # ->  The entry in the combinedShortenList - which contains at the beginning exactly the entries from the projectSpecific list  -
    #     are used prior to the same one in the generic list

    for entryGeneric in GENERIC_LOCAL_ID_SHORTEN_LIST:
      #Check if we have already the same entry in the combinedshortenList list
      #The originSubStrings have to be compared
      for entryCombined in combinedshortenList:
        if entryGeneric[self.IDX_SHORTEN_ORIGIN] == entryCombined[self.IDX_SHORTEN_ORIGIN]:
          # Ok we have already an equal entry in the list
          break
      else:
        #We do not have an equal entry in the list - add it
        combinedshortenList.append(entryGeneric)

    #Have the list sorted by the length of the originSubStrings
    #This is important in case we have a short originSubString which is a subString of a longer one
    #In case the shorter one would be substituted first the longer one would not match any more
    self.sort2DimensionalListByLength(combinedshortenList, self.IDX_SHORTEN_ORIGIN)

    return combinedshortenList


  #Remove double entries from twoDimensional List #########################################################################################################################################
  #criteriaIndex is that index which has to be compared
  def removeDoublesFrom2DimensionalList(self, listToClean, criteriaIndex):

    idxToRemoveList = [] # List of indexes which have to be removed

    #Find all entries which have multiple occurances in the list and store always the first found index in a list of indexes to be removed
    for outerIdx in range(len(listToClean) - 1):
      for innerIdx in range(outerIdx + 1, len(listToClean)):
        if listToClean[outerIdx][criteriaIndex].upper() == listToClean[innerIdx][criteriaIndex].upper():
          #DoubleEntry found - store outerIdx in the list of indexes to be removed
          idxToRemoveList.append(outerIdx)
          #terminate inner loop to avoid multiple entries in idxToRemove which would happen if there is a 3rd or 4th, 5th, ... occurance of the same entry
          break

    #Now delete all multipeIndexes from the list
    #We have to do it backwards therefore reverse the obtained indexList
    idxToRemoveList.reverse()
    for idx in idxToRemoveList:
      del listToClean[idx]


  #Sort two-dimensional list by lenght of entries in decending order ######################################################################################################################
  #criteriaIndex is that index by which the list shall be sorted
  def sort2DimensionalListByLength(self, listToSort, criteriaIndex):
    swapped    = True

    while swapped:
      swapped = False
      for idx in range(len(listToSort) - 1):
        if len(listToSort[idx + 1][criteriaIndex]) > len(listToSort[idx][criteriaIndex]):
          #Swap both indexes
          entry = listToSort[idx+1]
          listToSort.remove(listToSort[idx+1])
          listToSort.insert(idx, entry)
          swapped = True



RteStandardRtaInstrumentationGenerator()