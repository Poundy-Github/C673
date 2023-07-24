import os
import stat
import re
import sys
import argparse

from shutil import copyfile

try:
# python 2
    import Tkinter as tk
    import tkMessageBox as tkinter_messagebox
except ImportError:
# python 3
    import tkinter as tk
    import tkinter.messagebox as tkinter_messagebox

from datetime import datetime

import SubstringsToRemoveCfg
import SynonymStringsCfg

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + '/../ToolChainCommon')
from ChainCommon import ChainCommon

#################################################################################
#
#################################################################################
class RtaTaskIdLutGenerator(ChainCommon):

  #The prefix of rtaTaskIds (-> the literals of the enum OS_t_RtaTaskIDs)
  RTA_TASK_ID_INTERRUPTS = ChainCommon.PREFIX_RTA_TASK_IDS + 'Interrupts'

  #The info codes
  INFO_LUT_UPDATED               = 0
  INFO_RTA_TASK_IDS_UPDATED      = 1
  INFO_NO_UPDATE_OF_RTA_TASK_IDS = 2

  projectName     = 'UnkonwnProject'
  buildUnit       = 'UnknownBuildUnit'
  logDirPath      = ''
  osType          = ChainCommon.OS_TYPE_EB_S
  osCfgFilesPath  = ''
  outputPath      = ''
  rtaTaskIdHeader = ''
  osCfgFile       = ''
  osCfgFilePrio   = ''
  
  linesLogFile    = []

  LUT_HEADER_LINE = '\n#define OS_RTA_TASKID_LUT_INITIALIZER \\\n'
  
  LUT_ELEMENT_LINE = '''  (uint8){0}, \\
''' # 0: TaskID from the enumeration OS_t_RtaTaskIDs
  
  COMPATIBILITY_CHECK_LINES = '''
#include <Os_user.h>

#if OS_GENERATION_ID_OS_H != {0}
#error "The taskID_Lut does not match to the os configuration! \
Please update this file by running the RtaTaskIdLutGenerator on current OsConfgFiles."
#endif

'''
  
  GEN_ID_NOT_FOUND_LINES = '''
  
  /* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
     !!!!!   generationID not found in os config file - compatibility check not possible       !!!!!!!!!!
     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
  */
     
'''
  
  NUMBER_OF_TASKS_DEF_LINES = '''
  /// The NumberOfTaskDefine used as array size of the taskLookupTable
  #define OS_NUMBER_OF_TASKS {0}U
  
'''

  LOG_FILE_HEADER_LINES = '''
    
LogFile of the RtaTaskIdLutGenerator

Project:   {0}
BuildUnit: {1}
Date:      {2}

'''

  #Indexes for sortedTaskList
  IDX_SORTED_LIST_OS_TASK     = 0
  IDX_SORTED_LIST_RTA_TASK    = 1
  IDX_SORTED_LIST_OS_CORED_ID = 2

  InputCfgFileCheckList = [
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_PROJECT           , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_BUILD_UNIT        , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OUTPUT_PATH       , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : True  , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OS_DIR_PATH       , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_RTA_TASK_IDS_H    , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OS_TYPE           , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OS_CFG_FILE       , 'runTest' : ChainCommon.RUN_TEST_FILE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ  , 'mandatory' : False },
  ] 

  #Initialize the class
  def __init__(self):

    print ('RtaTaskIdLutGenerator started!')
    self.doIt()
    print ('RtaTaskIdLutGenerator terminated!')

  def doIt(self):
    rawOsTasks      = []
    taskListSorted  = []
    osTasksNoMatch  = []
    osTasks         = []
    rtaTaskIDs      = []
    newTaskIDs      = []
    infoMsgs        = []
    newLut          = []
    hasException    = False

    try:
      self.checkAndPrepare()

      #Get the tasks defined in the osConfigFile
      self.getTasksFromOsCfgFile(self.osCfgFile, rawOsTasks, self.osType)

      #Clean the raw taskNames coming from osConfiguration
      self.cleanOsTaskNames(rawOsTasks, osTasks)
      #Get the rtTaskIDs
      self.getRtaTaskIDs(rtaTaskIDs)
      #Generate the LUT like we need it for the current OS configuration
      self.generateLut(osTasks, osTasksNoMatch, rawOsTasks, rtaTaskIDs, newTaskIDs, newLut)
      #Generate the taskList sorted by priority 
      self.generateTaskListSortedByPrio(rawOsTasks, newLut, taskListSorted)
      #check if new RTA_TaskID has to be generated and ask user if he really want it to do
      if self.shallRtaTaskIdHeaderBeUpdated(infoMsgs, osTasksNoMatch):
        #Have the RtaTaskIdHeader updated if needed
        self.updateRtaTaskIdHeader(infoMsgs, rtaTaskIDs, newTaskIDs)
        self.updateLutCfgFile(newLut, taskListSorted)
        infoMsgs.append(self.INFO_LUT_UPDATED)

    except Exception as ex:
      print (ex)
      hasException = True
      #Add error info to the logFile
      self.linesLogFile.append(str(ex))
      #Create an info window in case the GUI is enabled
      if self.guiEnabled:
        tkinter_messagebox.showerror("rtaTaskIdLutGenerator", ex)

    try:
      #Generate the final user info
      self.generateFinalUserInfo(hasException, infoMsgs)
    except Exception as ex:
      print("Log cannot be created: " + str(ex))
      if self.guiEnabled:
        tkinter_messagebox.showerror("rtaTaskIdLutGenerator", "Log cannot be created: " + str(ex))

  #Generate the final user info ##########################################################################################################################################
  def generateFinalUserInfo(self, hasException, infoMsgs):
    infoString        = '' 
    finalLogFileLines = []
    
    #Add headerLines and the linesLogFile (The information we collected during the run) 
    finalLogFileLines.extend(self.LOG_FILE_HEADER_LINES.format(self.projectName, self.buildUnit, datetime.now().strftime('%d.%m.%Y %H:%M:%S')))
    finalLogFileLines.extend(self.linesLogFile)
    
    if not hasException:
      infoString = '\n\nrtaTaskIdLutGenerator successfully run! \n\n'
    else:
      infoString = '\n\nrtaTaskIdLutGenerator failed! \n\n'
      
    if len(infoMsgs):
      infoString = infoString + '\n-------------------------------------------------------------------\n\n'
      for entry in infoMsgs:
        if self.INFO_LUT_UPDATED == entry:
          infoString = infoString + 'The TaskLut for RTA has been updated. Please check in the file \n  '
          infoString = infoString + self.outputPath + '/{} \n-------------------------------------------------------------------\n\n'.format(self.TASK_LUT_FILE_NAME)
        elif self.INFO_RTA_TASK_IDS_UPDATED == entry:
          infoString = infoString + 'At least one new RTA_TaskID has been added. Please check in the file \n  '
          infoString = infoString + self.rtaTaskIdHeader + '\n-------------------------------------------------------------------\n\n'
        elif self.INFO_NO_UPDATE_OF_RTA_TASK_IDS == entry:
          infoString = infoString + 'Please change the names of new tasks in osConfiguration and run the generation again.'
        else:
          infoString = infoString + 'Unknown infoMessage!'

    #Add infoString to the logFile
    finalLogFileLines.extend(infoString)

    #Create an info window in case the GUI is enabled
    if self.guiEnabled:
      tkinter_messagebox.showinfo("rtaTaskIdLutGenerator", infoString)

    if not os.path.isdir(self.logDirPath):
      # Given logPath is not valid - use defaultLocation 
      self.logDirPath = self.getDefaultLocationForLogFile() 
      
    logFile = self.logDirPath + '/{0}_{1}_RtaTaskIdLutGenerator.log'.format(self.projectName, self.buildUnit)

    if os.path.isfile(logFile):
      # file already exists - remove writeProtection and open it
      st_mode = os.stat(logFile).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(logFile, st_mode)

    try: 
      #Write the logFile
      fileObj = open(logFile, 'w')
      fileObj.writelines(finalLogFileLines)
      fileObj.close()
      print(self.INFO_TEXT_LOG_FILE_GENERATION.format(logFile))
    except:
      print("RTA Generator ERROR: Cannot write log file - " + logFile)


  #Check if RtaTaskIdHeaderBeUpdated has to be updated and - if so - ask the user if he really wants it #####################################################################
  def shallRtaTaskIdHeaderBeUpdated(self, infoMsgs, osTasksNoMatch):
    if  not self.guiEnabled:
      #GUI is disabled -> RtaTaskIdHeader shall be updated, no question
      return True
    else:
      result = True
      #Check if new TaskIDs required
      if len(osTasksNoMatch):
        root = tk.Tk()
        var  = tk.IntVar()

        infoStr = 'The following tasks cannot be mapped to existing tasks in os_rta_task_ids.h \n\n'
        for entry in osTasksNoMatch:
          infoStr = infoStr + entry + '\n'

        infoStr = infoStr + '\nPlease check whether it is possible to rename the related tasks in the osConfiguration that new tasks in os_rta_task_ids.h can be avoided.\n\n'

        #Create the buttons in root
        tk.Label(root, text = infoStr ).pack(anchor = 'w')
        tk.Radiobutton(root, text = 'Continue. It is not possible to avoid new taskNames', variable = var, value = True ).pack(anchor = 'w')
        tk.Radiobutton(root, text = 'Cancel. New taskNames can be avoided. I will change the taskNames in the OsConfiguration',  variable = var, value  = False).pack(anchor = 'w')
        tk.Button(root, text = 'OK', command = root.quit, height = 2, width = 10, bd = 4).pack(anchor = 'center')

        #Wait for user interaction
        root.mainloop()
        # Check users choice
        if not var.get():
          result = False
          infoMsgs.append(self.INFO_NO_UPDATE_OF_RTA_TASK_IDS)

      return result

# argument parsing ############################################################################
  def check_args(self):
    parser = argparse.ArgumentParser(prog="GenerateRtaTaskIdLut",
                                     formatter_class=argparse.RawTextHelpFormatter,
                                     description="Generate TaskID lookup table")
    parser.add_argument('inputCfgFile',
                        action = 'store',
                        help ='The input configuration file in which all relevant files and folders are provided.')
    
    parser.add_argument('-r', '--prjRefPath',
                        action ='store',
                        help = '''The project referencePath is used as a base to determine the absolutePaths for all 
relativePaths given in the corresponding RtaXmlGenerator_InputCfg*.yaml.
This argument is not necessary in case all the paths in the RtaXmlGenerator_InputCfg*.yaml are provided as absolute paths.''')

    parser.add_argument('-g', '--gui',
                        action ='store_true',
                        default = False,
                        help = 'enables/disables configuration GUI')
    return parser.parse_args()

  #Check all relevant preconditions and to needed preparations ##########################################################################################################################################
  def checkAndPrepare(self):
    refPathDict = dict()
    
    #Get all arguments 
    args = self.check_args()

    self.guiEnabled  = args.gui

    if not os.path.isfile(args.inputCfgFile):
      #Provided file does not exist!!
      raise Exception("Provided inputConfigFile cannot be found \n{0}".format(args.inputCfgFile))
    else:
      # inputConfigFile is available -load it and have it checked
      inputCfg = self.load_yaml(args.inputCfgFile)
      
      #Update project, buildUnit and logPath with given values as far as available
      #This information is needed for the logFile 
      if self.INPUT_DICT_KEY_PROJECT in inputCfg:
          self.projectName = inputCfg[self.INPUT_DICT_KEY_PROJECT]     
      if self.INPUT_DICT_KEY_BUILD_UNIT in inputCfg:
          self.buildUnit   = inputCfg[self.INPUT_DICT_KEY_BUILD_UNIT]
      if self.INPUT_DICT_KEY_OUTPUT_PATH in inputCfg: 
        if args.prjRefPath:
          self.logDirPath  = self.getAbsolutePath(args.prjRefPath, inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH])
        else:
          self.logDirPath = inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH]

      #Prepare the dictionary required for calling the function checkInputCfgFileAndConvertToAbsPaths()
      if args.prjRefPath:
        refPathDict[ChainCommon.REF_PATH_PRJ] = args.prjRefPath

      templateFile = os.path.join(os.getcwd(), 'templates\TaskIdLutGenerator_InputCfg_Template.yaml')
      self.checkInputCfgFileAndConvertToAbsPaths(inputCfg, refPathDict, self.InputCfgFileCheckList, self.linesLogFile, args.inputCfgFile, templateFile)
      
    # Copy templateFile in case rta_taskids_h does not exist yet.  
    self.specialTreatmentForRtaTaskIdHeader(inputCfg,args)
    
    self.osCfgFilesPath  = inputCfg[self.INPUT_DICT_KEY_OS_DIR_PATH   ]
    self.outputPath      = inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH   ]
    self.rtaTaskIdHeader = inputCfg[self.INPUT_DICT_KEY_RTA_TASK_IDS_H]

    self.osType          = inputCfg[self.INPUT_DICT_KEY_OS_TYPE]
    # Check whether we got a valid osType and get the osConfigFiles accordingly 
    if (self.osType == self.OS_TYPE_EB_S):
      self.osCfgFile       = self.osCfgFilesPath + '/' + self.OS_CFG_FILE_EB_S
      self.osCfgFilePrio   = self.osCfgFilesPath + '/' + self.OS_CFG_FILE_PRIO_EB_S
    elif (self.osType == self.OS_TYPE_EB):
      self.osCfgFile       = self.osCfgFilesPath + '/' + self.OS_CFG_FILE_EB
      self.osCfgFilePrio   = self.osCfgFilesPath + '/' + self.OS_CFG_FILE_PRIO_EB
    elif (self.osType == self.OS_TYPE_VECTOR):  
      self.osCfgFile       = self.osCfgFilesPath + '/' + self.OS_CFG_FILE_VECTOR
      self.osCfgFilePrio   = self.osCfgFilesPath + '/' + self.OS_CFG_FILE_PRIO_VECTOR
    elif (self.osType == self.OS_TYPE_RTOS):  
      if self.INPUT_DICT_KEY_OS_CFG_FILE in inputCfg:
        #OK, osCfgFile given, assign it to both to osCfgFile and osCfgFilePrio as well
        self.osCfgFile       = inputCfg[self.INPUT_DICT_KEY_OS_CFG_FILE]
        self.osCfgFilePrio   = inputCfg[self.INPUT_DICT_KEY_OS_CFG_FILE]
      else:
        raise Exception("\nFor the safeRTOS and the freeRTOS the osConfigFile needs to be provided in the lutGeneratorInputCfg.yaml! ")
    else:
      raise Exception('Given OS type not supported: {0}'.format(self.osType))

    if not os.path.isfile(self.osCfgFile):
      raise Exception("The OsConfigFile could not be found. \n Please check provided os_cfg_files_path. " + str(self.osCfgFile))

    if not os.path.isfile(self.osCfgFilePrio):
      raise Exception("The osCfgFilePrio could not be found. \n Please check provided os_cfg_files_path. " + str(self.osCfgFilePrio))

    if (  (self.OS_TYPE_EB_S == self.osType)
        or(self.OS_TYPE_EB   == self.osType)
       ):
      #We have a EB OS where a generation ID is available 
      self.osGenIDFile     = self.osCfgFilesPath + '/' + self.OS_GEN_ID_FILE
      if not os.path.isfile(self.osGenIDFile):
        raise Exception("The Os_user.h could not be found!")


  
  ##################################################################################################################################################################################
  def specialTreatmentForRtaTaskIdHeader(self, inputCfg, args):
    '''This function whether the rta_taskids_h exists. If not it checks whether given path of rta_taskids_h exists.
       It the path exists it copies the os_rta_task_ids_Template.h to given path renaming it to os_rta_task_ids_Template.h.  
    '''
    if not os.path.isfile(inputCfg[self.INPUT_DICT_KEY_RTA_TASK_IDS_H] ):
      # Given os_rta_task_ids.h does not exist
      # Check whether the folder exists
      if os.path.isdir(os.path.dirname(inputCfg[self.INPUT_DICT_KEY_RTA_TASK_IDS_H])):
        # OK - path exist copy template file to given path
        srcFile  = os.path.join(os.getcwd(), 'templates/os_rta_task_ids_Template.h')

        copyfile(srcFile, inputCfg[self.INPUT_DICT_KEY_RTA_TASK_IDS_H])
      
      else: 
        raise Exception('''The folder of given rta_taskids_h file "{0}" does not exist.
Please double check corresponding configuration in the generatorCfgFile: "{1}"
''' .format(inputCfg[self.INPUT_DICT_KEY_RTA_TASK_IDS_H], args.inputCfgFile))
        
        

  ##################################################################################################################################################################################
  def getTaskListWithPrioAndCoreInfo(self, taskList):

    #Ensure that provided list is empty
    del taskList[:]

    #Read all lines of osCfgFile
    fileObj = open(self.osCfgFilePrio)
    lines = fileObj.readlines()
    fileObj.close()

    if self.OS_TYPE_EB_S == self.osType:
      PATTERN_TASK_CFG_START      = r' *#define *MK_TASKCFG_([\S]+) *[MK_ETASKCFG]|[MK_TASKCFG] *\(' # Group(1) is the taskName
      PATTERN_CORE_ID             = r' *([\d]+)U?, */\* *coreId *\*/'          # Group(1) is coreID
    elif self.OS_TYPE_EB == self.osType:
      PATTERN_TASK_CFG_START      = r' *[#define]* *[OS_TASKCONFIG]* *OS_TASKCONFIG_INIT\( */\* ([\S]+) *\*/' # Group(1) is the taskName
      PATTERN_CORE_ID             = r' *\&OS_taskDynamic_core([\d]+)\[[\d]+\] *, */\* *Dynamic task structure *\*/ '          # Group(1) is coreID                               
    else:
      #We have a vector OS
      PATTERN_TASK_CFG_START      = r' *CONST\( *Os_TaskConfigType *, *OS_CONST *\) *OsCfg_Task_(\S+) *= *'  # Group(1) is the taskName
      PATTERN_CORE_ID             = r' */\* *\. *Core *= *\*/ *&(.+) *, *' # Group(1) is coreID
    
    if self.OS_TYPE_VECTOR == self.osType: 
      # We have a vectorOS
      PATTERN_QUEUE_PRIO          = r' */\* *\.HomePriority *= *\*/ *\( *Os_TaskPrioType *\)(\d+) *(u|uL) *, *'  # Group(1) is the Queuing prio which is called HomePriority in case of Vector 
      PATTERN_RUN_PRIO            = r' */\* *\.RunningPriority *= *\*/ *\( *Os_TaskPrioType *\)(\d+) *(u|uL) *, *'         # Group(1) is the Run prio
    else:
      # We have a EB OS - either safety or normal
      PATTERN_QUEUE_PRIO          = r' *([\d]+)U?, */\* *Queuing  *priority *\*/'      # Group(1) is the Queuing prio
      PATTERN_RUN_PRIO            = r' *([\d]+)U?, */\* *Run  *priority *\*/'          # Group(1) is the Run prio



    isMultiCoreOS  = False
    lookForPrios   = False
    queuePrioFound = False
    runPrioFound   = False
    coreIdFound    = True

    taskName  = ''
    queuePrio = 0
    runPrio   = 0
    #In case of multiCoreOs 'coreID' will be overwritten - otherwise it just stays unchanged
    coreId    = '0'

    #Determine if we have a multiCoreOS
    for line in lines:
      if re.match(PATTERN_CORE_ID, line):
        #OK, we have a multiCoreOS 
        isMultiCoreOS = True
        break

    #Find the section where the taskIDs are defined
    for line in lines:
      #Do we have the start of the next taskCfg?
      obj = re.match(PATTERN_TASK_CFG_START, line)
      if obj:
        # This is the start of the next taskCfg - save the taskName and update the flags
        taskName = obj.group(1)
        lookForPrios   = True
        queuePrioFound = False
        runPrioFound   = False
        #In case of multicoreOS reset also this flag - otherwise it just shall stay True
        if isMultiCoreOS:
          coreIdFound = False

      elif lookForPrios:
        obj = re.match(PATTERN_QUEUE_PRIO, line)
        if obj:
          queuePrio      = int(obj.group(1))
          queuePrioFound = True

        obj = re.match(PATTERN_RUN_PRIO, line)
        if obj:
          runPrio      = int(obj.group(1))
          runPrioFound = True

        obj = re.match(PATTERN_CORE_ID, line)
        if obj:
          coreId      = obj.group(1)
          coreIdFound = True

        if queuePrioFound and runPrioFound and coreIdFound:
          #Both prios and the coreId are found already - add all the infos to the list
          #               [IDX_TASK_NAME, IDX_QUEUE_PRIO,IDX_RUN_PRIO, IDX_OS_CORE_ID]
          taskList.append([taskName, queuePrio, runPrio, coreId])
          lookForPrios = False

  ##################################################################################################################################################################################
  def getTaskListWithPrioAndCoreInfo_RTOS(self, taskList):

    #Ensure that provided list is empty
    del taskList[:]

    #Read all lines of osCfgFile
    fileObj = open(self.osCfgFilePrio)
    lines = fileObj.readlines()
    fileObj.close()
    
    '''Now look for the taskPriority defines. The sequence of these prioDefines looks like:
    
    // Task priorities
    // ___GENERATOR_TAG___TASK_PRIORITY_DEFINES_START__
    #define TSK_STARTUP_PRIO                9
    // ___GENERATOR_TAG___TASK_PRIORITY_DEFINES_END__ 
    '''
    
    inRegionOfInterrest = False
    taskPrioDict = {}
    
    startQuery           = self.GEN_TAG_RTOS_PRIO_DEFINES_START
    endQuery             = self.GEN_TAG_RTOS_PRIO_DEFINES_END
    PATTERN_PRIO_DEFINE  = r' *# *define +(\S+) +(\d+)' #Group(1) is taskPrioDefine, group(2) is taskPriority
    
    for line in lines:
      if not inRegionOfInterrest:
        #We are not in the block of prioDefines yet - look for the startPattern
        if line.find(startQuery) != -1:
          #StartLine found - set flag
          inRegionOfInterrest = True
      else:
        #Look for prioDefines
        obj = re.match(PATTERN_PRIO_DEFINE, line)
        if obj:
          # we have a prioDefine - save defineName and prioValue
          taskPrioDict[obj.group(1)] = int(obj.group(2))
        else:  
          #Check whether it's the terminating line of the priorityDefines
          if line.find(endQuery) != -1:
            #We reached the end of the priorityDefines - stop collecting the taskPriorities 
            break
    else:
      raise Exception('Too less taskPrioDefines found in the file {0}'.format(self.osCfgFilePrio))
      
    '''Next look for taskConfigurationLines to map the related Priority to every task. The taskConfigLines looks like: 
    
    // ___GENERATOR_TAG___TASK_CFG_ARRAY_START__
    static const task_config_t taskConfig[NUM_OF_TASKS] = {
    /* Name               Handle              Function                Priority                Stack                    Stack Size                    Privilege level*/
    {"Tsk_Startup",       &Tsk_Startup,       Tsk_Startup_func,       TSK_STARTUP_PRIO,       Tsk_Startup_Stack,       TSK_STARTUP_STACK_SIZE,       safertosapiPRIVILEGED_TASK},
    };    
    // ___GENERATOR_TAG___TASK_CFG_ARRAY_END__ 
    '''
    
    startQuery               = self.GEN_TAG_RTOS_TASK_CFG_START
    endQuery                 = self.GEN_TAG_RTOS_TASK_CFG_END
    PATTERN_TASK_CONFIG_LINE = r' *\{ *" *(\S+) *" *, *& *\S+ *, *\S+ *, *(\S+) *,[\s\S]+\}' # Group(1) is TaskName, group(2) is taskPrioDefine

    inRegionOfInterrest = False

    for line in lines:
      if not inRegionOfInterrest:
        #We are not in the taskConfig array yet - look for the startPattern
        if line.find(startQuery) != -1:
          #StartLine found - set flag
          inRegionOfInterrest = True
      else:
        #Look for prioDefines
        obj = re.match(PATTERN_TASK_CONFIG_LINE, line)
        if obj:
          #Now we have a taskConfiguration line 
          #Check whether we have the corresponding TaskPrioDefine
          if obj.group(2) in taskPrioDict:
            #               [IDX_TASK_NAME, IDX_QUEUE_PRIO,IDX_RUN_PRIO, IDX_OS_CORE_ID]
            # In RTOS we have just one priority, simply assing it to both priorities
            # RTOS is a singleCore OS - just assing '0' as coreID
            taskList.append([obj.group(1), taskPrioDict[obj.group(2)], taskPrioDict[obj.group(2)], 0])
          else:
            raise Exception('There is no such a taskPrioDefine: {0}. Please doublecheck configuration.'.format(obj.group(2)))
        else:  
          #Check whether it's the terminating line of the taskCfgArray
          if line.find(endQuery) != -1:
            #We reached the end of the taskCfgArray - stop collecting tasks
            break
    else:
      raise Exception('Too less taskConfigurationLines found in the file {0}'.format(self.osCfgFilePrio))
      
    
    #Finally add the idleTask to the list- with lowest priority ( 0 )
    #Note: In the RTOS the idleTask is generated automatically, therefore it is not in the list of configured tasks
    taskList.append([self.STRING_IDLE_TASK, 0, 0, 0])


  ##################################################################################################################################################################################
  def generateTaskListSortedByPrio(self, rawOsTasks, taskLut, taskListSorted):

    IDX_TASK_NAME  = 0
    IDX_QUEUE_PRIO = 1
    IDX_RUN_PRIO   = 2
    IDX_OS_CORE_ID = 3

    #List of all tasks
    # [IDX_TASK_NAME, IDX_QUEUE_PRIO, IDX_RUN_PRIO, IDX_OS_CORE_ID ]
    taskList = []
    sortedTasks = []

    #Get all Tasks including information according prio and core 
    if self.OS_TYPE_RTOS == self.osType:
      self.getTaskListWithPrioAndCoreInfo_RTOS(taskList)
    else:
      self.getTaskListWithPrioAndCoreInfo(taskList)


    #Create the sortedTaskList in decending order of priority
    for task in taskList:
      taskEnqueued = False

      for idx in range(len(sortedTasks)):
        if self.OS_TYPE_VECTOR == self.osType:
          #We have a vector OS where the lower number of runPrio has the higher priority
          if (   (task[IDX_RUN_PRIO] < sortedTasks[idx][IDX_RUN_PRIO])
              or ((task[IDX_RUN_PRIO] == sortedTasks[idx][IDX_RUN_PRIO]) and (task[IDX_QUEUE_PRIO] < sortedTasks[idx][IDX_QUEUE_PRIO]))
             ):
            # current task has a bigger prio then that task on this idx in sortedList
            sortedTasks.insert(idx, task)
            taskEnqueued = True
            break
        else:
          #We have a EB OS or an RTOS where the higher number of runPrio has the higher priority
          if (   (task[IDX_RUN_PRIO] > sortedTasks[idx][IDX_RUN_PRIO])
              or ((task[IDX_RUN_PRIO] == sortedTasks[idx][IDX_RUN_PRIO]) and (task[IDX_QUEUE_PRIO] < sortedTasks[idx][IDX_QUEUE_PRIO]))
             ):
            # current task has a bigger prio then that task on this idx in sortedList
            sortedTasks.insert(idx, task)
            taskEnqueued = True
            break

      if not taskEnqueued:
        #Current task has a lower prio than all the other tasks in the list so far
        # Just append it to the end of the list
        sortedTasks.append(task)

    #Ensure that provided list is empty
    del taskListSorted[:]
    #Now fill the list with OsTaskName and RtaTaskName
    for sortedTask in sortedTasks:
      #Find corresponding index of current task in rawOsTasks
      for idx in range(len(rawOsTasks)):
        if sortedTask[IDX_TASK_NAME] == rawOsTasks[idx]:
          #OK, found - create new entry in taskListSorted with osTaskName and RtaTaskId
          #Create a new entry:  [IDX_SORTED_LIST_OS_TASK,  IDX_SORTED_LIST_RTA_TASK, IDX_SORTED_LIST_OS_CORED_ID]
          taskListSorted.append([sortedTask[IDX_TASK_NAME], taskLut[idx], sortedTask[IDX_OS_CORE_ID]])
          break


  #Clean the taskNames in taskList, but keep the case (lower/upper) like originally comming from osConfig###########################################################################
  def cleanOsTaskNames(self, rawOsTasks, osTasks):
    preliminaryTaskList = []

    #Ensure that we have only upper cases in the subStrings
    for i in range(len(SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE)):
      SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE[i] = SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE[i].upper()

    #Remove double entries from subStringsToRemove and sort it by length
    self.removeDoublesFromList(SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE)
    self.sortListByLength(SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE)

    #Change the strings that related synonyms are used for dedicated strings
    #Ensure that we have only upper cases in the keyStrings of synonyms
    keyList = list(SynonymStringsCfg.SYNONYM_STRINGS.keys())

    for entry in keyList:
      if not entry.isupper():
        #create a new dictionary entry
        SynonymStringsCfg.SYNONYM_STRINGS[entry.upper()] = SynonymStringsCfg.SYNONYM_STRINGS[entry]
        #Remove origin dictionary entry
        del SynonymStringsCfg.SYNONYM_STRINGS[entry]

    #Get a new list of keys, now they contains only upperCases in their strings
    upperKeyList = list(SynonymStringsCfg.SYNONYM_STRINGS.keys())
    self.sortListByLength(upperKeyList)

    #No run over all tasks, clean them and substitute some substrings by dedicated synonyms
    for task in rawOsTasks:
      #Remove subStrings to be removed
      for subString in SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE:
        #check if we have the subString in the current taskName - not caseSensitive
        idx = task.upper().find(subString)
        if -1 != idx:
          #OK - subString is part of taskName
          #Ensure that we do not remove the whole taskName
          if len(task.replace('_', '')) > len(subString):
            #OK - we have a remaining part - cut the subString out
            task = task[:idx] + task[idx + len(subString):]

      #Remove underscores in the name
      task = task.replace('_', '')

      for key in upperKeyList:
        #check if the key is part of current taskName
        idx = task.upper().find(key)
        if -1 != idx:
          #OK this key is part of the taskName substitute it by related synonym
          task = task[:idx] + SynonymStringsCfg.SYNONYM_STRINGS[key] + task[idx + len(key):]

      #Add cleaned taskName to a preliminary taskList
      preliminaryTaskList.append(task)

    #Finally remove further subStrings but only in case we do not end up with two or more equal taskNames
    #Ensure that we have only upper cases in the subStringsToRemoveNoDoubles
    for i in range(len(SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE_NO_DOUBLES)):
      SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE_NO_DOUBLES[i] = SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE_NO_DOUBLES[i].upper()

    #Remove double entries from subStringsToRemoveNoDoubles and sort it by length
    self.removeDoublesFromList(SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE_NO_DOUBLES)
    self.sortListByLength(SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE_NO_DOUBLES)

    for task in preliminaryTaskList:
      #Remove subStrings to be removed
      for subString in SubstringsToRemoveCfg.SUB_STRINGS_TO_REMOVE_NO_DOUBLES:
        #check if we have the subString in the current taskName - not caseSensitive
        idx = task.upper().find(subString)
        if -1 != idx:
          #OK - subString is part of taskName
          #Ensure that we do not remove the whole taskName
          if len(task.replace('_', '')) > len(subString):
            #OK - we have a remaining part - ensure that we do not endup with two equal taskNames
            taskNameWithoutSubString = task[:idx] + task[idx + len(subString):]

            if 0 == preliminaryTaskList.count(taskNameWithoutSubString):
              #Ok we can remove the subString from the taskname - update task with the final (cleaned) taskName
              task = taskNameWithoutSubString

      #Add final taskName to given list
      osTasks.append(task)

  # Provide a list of all TaskIDs defined in rtTaskIDHeader ####################################################################################################################
  def getRtaTaskIDs(self, rtaTaskIDs):

    #All available values for 'state'
    STATE_BEFORE_ENUM     = 0
    STATE_IN_ENUM         = 1
    STATE_AFTER_ENUM      = 2

    state = STATE_BEFORE_ENUM

    #Read all lines of osCfgFile
    fileObj = open(self.rtaTaskIdHeader)
    lines = fileObj.readlines()
    fileObj.close()

    #step over all lines and look for rtaTaskIDs
    for line in lines:
      if STATE_BEFORE_ENUM == state:
        if line.find(self.GEN_TAG_TASK_IDS_ENUM_START) != -1:
          #Start of enum found - update state
          state = STATE_IN_ENUM
      elif STATE_IN_ENUM == state:
        #we are in the enum, check whether this line is a enumLiteral, but not that one for the interrupts
        if (-1 != line.find(self.PREFIX_RTA_TASK_IDS)) and (-1 == line.find(self.RTA_TASK_ID_INTERRUPTS)):
          # clean the line that only name and value remain
          line = line.replace('\t', '')  #remove tabs
          line = line.replace(' ', '')   # remove spaces
          line = line.strip('\n')
          line = line.strip(',')
          #Seperate name and value supposing that we have only name and value in line seperated by '='
          NameValue = line.split('=')
          rtaTaskIDs.append(NameValue)
        elif line.find(self.GEN_TAG_TASK_IDS_ENUM_END) != -1:
          #end of enum found, update state accordingly
          state = STATE_AFTER_ENUM
          break


  #Generate the lut ######################################################################################################################################################
  def generateLut(self, osTasks, osTasksNoMatch, rawOsTasks, rtaTaskIDs, newTaskIDs, newLut):
    #loop over osTasks and find matching entry in rtaTaskIDs
    idx = 0
    for osTask in osTasks:
      found = False
      for rtaTaskID in rtaTaskIDs:
        if osTask.upper() == rtaTaskID[0].replace(self.PREFIX_RTA_TASK_IDS, '').upper():
          #Matching taskID found - append it to lut
          newLut.append(rtaTaskID[0])
          found = True
      if not found:
        #No match found, create a new rtaTaskID
        newTaskID = self.PREFIX_RTA_TASK_IDS + osTask
        #Append new id to lut and to newTaskIDs as well
        newLut.append(newTaskID)

        newTaskIDs.append(newTaskID)
        #Store related rawTaskName to ask/inform the user that new taskNames are needed in rtaTaskIDs
        osTasksNoMatch.append(rawOsTasks[idx])
      idx += 1

  #Update the lutConfigFile #############################################################################################################################################
  def updateLutCfgFile(self, lut, taskListSorted):

    startSeq      = [] #The sequence before the compatibilityCheck
    middleSeq_1   = [] #The sequence  between compatibilityCheck and taskList
    middleSeq_2   = [] #The sequence  between taskList and lut
    endSeq        = [] #The sequence after the lut

    beginMiddleSeq_1 = 0
    beginMiddleSeq_2 = 0

    compatCheckLines     = []
    taskListLines        = []
    lutLines             = []
    noTasksDefineLines   = []
    maxLenOsTaskName     = 0
    maxLenRtaTaskName    = 0
    
    #Get the OS_GENERATION_ID_OS_H from OS_user.h
    osGenID = self.getOsGenerationID()
    if len(osGenID):
      compatCheckLines.append(self.COMPATIBILITY_CHECK_LINES.format(osGenID))
    else:
      compatCheckLines.append(self.GEN_ID_NOT_FOUND_LINES)

    #Find the maxStringLength of osTaskName and rtaTaskName
    for entry in taskListSorted:
      if len(entry[0]) > maxLenOsTaskName:
        maxLenOsTaskName = len(entry[0])

      if len(entry[1]) > maxLenRtaTaskName:
        maxLenRtaTaskName = len(entry[1])

    #Create taskListLines
    taskListLines.append('\n') #Add empty line
    #Create lines for taskList
    for entry in taskListSorted:
      # We have coreIds provided assign them also to the entries together with osTaskIDs and rtaTaskIDs
      taskListLines.append('  {0}, {1}, {2}\n'.format(entry[self.IDX_SORTED_LIST_OS_TASK].ljust(maxLenOsTaskName),
                                                      entry[self.IDX_SORTED_LIST_RTA_TASK].ljust(maxLenRtaTaskName),
                                                      entry[self.IDX_SORTED_LIST_OS_CORED_ID]))

    taskListLines.append('\n'*1) #Add empty line

    #Create lutLines
    lutLines.append(self.LUT_HEADER_LINE)
    for entry in lut:
      lutLines.append(self.LUT_ELEMENT_LINE.format(entry.ljust(maxLenRtaTaskName)))
    #remove ', \' from the last line
    lutLines[len(lutLines) - 1] = lutLines[len(lutLines) - 1].replace(', \\', '')
    lutLines.append('\n') #Add an empty line

    #Prepare the lines of numberOfTasks define - the length of taskListSorted is equal to number of tasks 
    noTasksDefineLines.append(self.NUMBER_OF_TASKS_DEF_LINES.format(len(taskListSorted)))
    
    outputFile = self.outputPath + '/' + self.TASK_LUT_FILE_NAME
    #Get all lines from the outputFile in case it exists and is valid - otherwise just get the lines of the template file
    lines = []
    self.checkForValidOutputFileAndReadInAllLines(outputFile, lines)

    #split the current lines into sequences
    for idx in range(len(lines)):

      if not len(startSeq):
        #Look for line with the generatorTag indicating the start of the taskList which is the end of the StartSeq
        if -1 != lines[idx].find(self.GEN_TAG_COMPAT_CHECK_START):
          # End of startSequence found - copy related lines
          startSeq = lines[:idx + 1]

      elif not len(middleSeq_1):
        if not beginMiddleSeq_1:
          #Look for line with the generatorTag indicating the end of the taskList which is the begin of the middleSeq
          if -1 != lines[idx].find(self.GEN_TAG_COMPAT_CHECK_END):
            # Begin of middleSequence found - save current index
            beginMiddleSeq_1 = idx
        else:
          #Look for line with the generatorTag indicating the begin of the taskLut which is the end of the middleSeq
          if -1 != lines[idx].find(self.GEN_TAG_AUX_TASK_LIST_START):
            # End of middleSequence found - copy related lines
            middleSeq_1 = lines[beginMiddleSeq_1:idx + 1]

      elif not len(middleSeq_2):
        if not beginMiddleSeq_2:
          #Look for line with the generatorTag indicating the end of the taskList which is the begin of the middleSeq
          if -1 != lines[idx].find(self.GEN_TAG_AUX_TASK_LIST_END):
            # Begin of middleSequence found - save current index
            beginMiddleSeq_2 = idx
        else:
          #Look for line with the generatorTag indicating the begin of the taskLut which is the end of the middleSeq
          if -1 != lines[idx].find(self.GEN_TAG_LUT_START):
            # End of middleSequence found - copy related lines
            middleSeq_2 = lines[beginMiddleSeq_2:idx + 1]

      else:
        #Look for line with the generatorTag indicating the end of the lut
        if -1 != lines[idx].find(self.GEN_TAG_LUT_END):
          # End of middleSequence found - copy related
          endSeq = lines[idx:]


    #Bring all sequences together again including the taskListLines and the LutLines
    startSeq.extend(compatCheckLines)
    startSeq.extend(middleSeq_1)
    startSeq.extend(taskListLines)
    startSeq.extend(middleSeq_2)
    startSeq.extend(lutLines)
    startSeq.extend(noTasksDefineLines)
    startSeq.extend(endSeq)

    #Write all lines to lutConfigFile
    fileObj = open(outputFile, 'w')
    fileObj.writelines(startSeq)
    fileObj.close()


  #############################################################################################################################################################################################
  def getOsGenerationID(self):
    generationID = ''

    if (  (self.OS_TYPE_EB_S == self.osType)
        or(self.OS_TYPE_EB   == self.osType)
       ):
      #We have a EB os where a generation id is available
      #read all lines of file and close it afterwards
      fileObj = open(self.osGenIDFile)
      myLines = fileObj.readlines()
      fileObj.close()
      
      #find line with generationID define
      for line in myLines:
        matchObj = re.match(r' *# *define +OS_GENERATION_ID_OS_H +(.+)', line)
        if matchObj: 
          #Ok - interresting line found - clean it that only the ID remains
          generationID = matchObj.group(1)
          generationID = generationID.rstrip('\n')
          generationID = generationID.strip()
          #check for any whiteSpaces in the remaining string
          if -1 != generationID.find(' '):
            #There is a whitespace - take the part only left to it
            generationID = generationID[:generationID.find(' ')]
          
          break

    return generationID
  
  #############################################################################################################################################################################################
  def checkForValidOutputFileAndReadInAllLines(self, outputFile,  lines):
    useTemplateFile = True
    listIdx = 0

    #The list of required task in the right order
    tagList = [
                self.GEN_TAG_COMPAT_CHECK_START,
                self.GEN_TAG_COMPAT_CHECK_END,
                self.GEN_TAG_AUX_TASK_LIST_START,
                self.GEN_TAG_AUX_TASK_LIST_END,
                self.GEN_TAG_LUT_START,
                self.GEN_TAG_LUT_END,
              ]

    if os.path.isfile(outputFile):
      # file already exists - remove writeProtection and open it
      st_mode = os.stat(outputFile).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(outputFile, st_mode)

      fileObj = open(outputFile)
      #read all lines of file and close it afterwards
      myLines = fileObj.readlines()
      fileObj.close()

      #Check whether the file contains all needed tags in the right order
      for line in myLines:
        #Find next tag
        if -1 != line.find(tagList[listIdx]):
          #Ok - next tag found just increment index
          listIdx += 1
          #Check whether this was already the last index to be found
          if len(tagList) <= listIdx:
            # ok, all tags found
            useTemplateFile = False
            break

    if useTemplateFile:
      print ('Use templateSource!!!!!!!!!!!!!!!!!!!!!!!!!!')
      #File does not exist - or at least one required generatorTag is missing, the old file cannot be updated.
      #Take the templateFile instead
      fileObj = open(os.path.dirname(os.path.realpath(__file__)) + '/templates/' + self.TASK_LUT_TEMPLATE_FILE_NAME)
      #read all lines of file and close it afterwards
      myLines = fileObj.readlines()
      fileObj.close()

    #Provide the lines to caller
    del lines[:]
    lines.extend(myLines)


  #Update rtaTaskIdHeader if needed ##########################################################################################################################################
  def updateRtaTaskIdHeader(self, infoMsgs, currentTaskIDs, newTaskIDs):

    #All available values for 'state' used for splitting the file into startSeq and endSeq
    STATE_BEFORE_ENUM     = 0
    STATE_IN_ENUM         = 1

    #Check wehther an update of rtaTaskIdHeader is needed at all
    if len(newTaskIDs) > 0:
      #ok update is required
      indexCurrentTaskIDs = 0
      indexNewTaskIDs     = 0
      cnt                 = 0
      newList             = []
      nextPossibleValue   = 1 # Note: 0 is reserved for interrups which are considered as a task (All Interrupts are provided with ID 0)

      #Remove double entries which are potentually in the list
      self.removeDoublesFromList(newTaskIDs)

      #Check whether total number of needed tasksID fits into 8-bit-range
      if 256 >= (len(currentTaskIDs) + len(newTaskIDs) + 1):
        #At first add the literal for the interrupts which is not part of the currentTaskIDs
        newList.append([self.RTA_TASK_ID_INTERRUPTS, 0])
        while(len(currentTaskIDs) + len(newTaskIDs)) > cnt:
          found = False
          if len(currentTaskIDs) > indexCurrentTaskIDs:
            if nextPossibleValue == int(currentTaskIDs[indexCurrentTaskIDs][1]):
              #OK - this entry of currentTaskIDs has the matching id - copy it to newList
              newList.append(currentTaskIDs[indexCurrentTaskIDs])
              #Increment index and nextValue and set found-Flag
              indexCurrentTaskIDs += 1
              nextPossibleValue = nextPossibleValue + 1
              found = True
          #Check if matching entry has been found already
          if not found:
            #We have a gap in the values of currentTaskIDs
            #Check whether there are entries in newTaskIDs left
            if len(newTaskIDs) > indexNewTaskIDs:
              #Copy current entry to newList and increment related index and nextPossibleValue
              newList.append([newTaskIDs[indexNewTaskIDs], nextPossibleValue])
              indexNewTaskIDs   += 1
              nextPossibleValue += 1
              found             = True
          #Check if matching entry has been found already
          if not found:
            #Check whether there are entries left in currentTaskIDs
            if len(currentTaskIDs) > indexCurrentTaskIDs:
              #Copy current entry into newList
              newList.append(currentTaskIDs[indexCurrentTaskIDs])
              indexCurrentTaskIDs += 1
          #Finally increment loopCounter
          cnt += 1

        #Now update the rtaTaskIDHeader
        #read all lines of header
        fileObj = open(self.rtaTaskIdHeader)
        lines = fileObj.readlines()
        fileObj.close()

        state     = STATE_BEFORE_ENUM
        i         = 0
        startSeq  = []
        endSeq    = []
        maxStrLen = 0
        #step over all lines and get the startSequence and the endSequence
        for line in lines:
          i += 1
          if STATE_BEFORE_ENUM == state:
            if -1 != line.find(self.GEN_TAG_TASK_IDS_ENUM_START):
              #Start of enum found - update state
              state = STATE_IN_ENUM
          elif STATE_IN_ENUM == state:
            if len(startSeq) == 0:
              #StartSeq not obtained so far check whether this line is the line with the first enumLiteral
              if -1 != line.find(self.PREFIX_RTA_TASK_IDS):
                # ok, this is the first enumLiteral, save all line up to here in startSeq
                startSeq = lines[:i-1]
            elif -1 != line.find(self.GEN_TAG_TASK_IDS_ENUM_END):
              #end of enum found, save the rest of the lines in endSeq
              endSeq = lines[i-2:]
              break

        #Find the maxStringLength of taskName
        for entry in newList:
          if len(entry[0]) > maxStrLen:
            maxStrLen = len(entry[0])

        #Add for each entry in newList one line with name and value to startSeq
        for entry in newList:
          startSeq.append('  ' + entry[0].ljust(maxStrLen) + ' = ' + str(entry[1]).rjust(3) + ', \n')
        #remove trailing ','
        startSeq[len(startSeq) - 1] = startSeq[len(startSeq) - 1].replace(',' , '')

        #add endSeq to startSeq and write it into file
        startSeq.extend(endSeq)
        #remove writeProtection from rtaTaskIdHeader and open it
        st_mode = os.stat(self.rtaTaskIdHeader).st_mode | stat.S_IWRITE | stat.S_IREAD
        os.chmod(self.rtaTaskIdHeader, st_mode)
        
        fileObj = open(self.rtaTaskIdHeader, 'w')
        #write all lines collected in startSeq and close the file afterwards
        fileObj.writelines(startSeq)
        fileObj.close()
        #Add infoMsg
        infoMsgs.append(self.INFO_RTA_TASK_IDS_UPDATED)
      else:
        raise Exception("""New RtaTaskIDs have to be generated but 8 bit-Range will be exeeded! 
Check if you really need new taskNames.
If yes check if all taskIDs defined in os_rta_task_ids.h are still needed.
Please be aware that os_rta_task_ids.h is used in all current projects!""")

  #Remove double entries from list #########################################################################################################################################
  def removeDoublesFromList(self, listToClean):

    #First create a list with the same entries  - just transfered to upperCases

    upperList = []
    for entry in listToClean:
      upperList.append(entry.upper())

    #Now remove doubles from the upperList
    doubles = True
    while doubles:
      doubles = False
      for entry in upperList:
        #As long as we found no double in current iteration look for doubles and remove first occurance
        if not doubles:
          if 1 < upperList.count(entry):
            #Double found - remove first occurance
            upperList.remove(entry)
            doubles = True

    #Make a copy of the listToClean and delete all entries of listToClean afterwards
    listToCleanOrigin = []
    listToCleanOrigin.extend(listToClean)
    del listToClean[:]

    #Compare both list and remove double entries in origin list non case sensitive (upper/lower)
    for entryUpper in upperList:
      for entryOrigin in listToCleanOrigin:
        if entryUpper == entryOrigin.upper():
          #matching entry found - copy it to the list to be cleaned
          listToClean.append(entryOrigin)
          break


  #Sort the list by lenght of entries in decending order ######################################################################################################################
  def sortListByLength(self, listToSort):
    swapped    = True

    while swapped:
      swapped = False
      i = 0
      while (len(listToSort) - 1) > i:
        if len(listToSort[i + 1]) > len(listToSort[i]):
          #Swap both indexes
          string = listToSort[i+1]
          listToSort.remove(listToSort[i+1])
          listToSort.insert(i, string)
          swapped = True
        i = i + 1



RtaTaskIdLutGenerator()
