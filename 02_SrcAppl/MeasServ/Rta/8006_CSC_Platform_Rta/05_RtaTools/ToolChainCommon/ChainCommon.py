import stat
import os
import re
import yaml


#################################################################################
# All the common stuff used anywhere in the toolChain
#################################################################################
class ChainCommon(object):

  #The supported osTypes
  OS_TYPE_EB_S      = 'OS_TYPE_EB_S'     # ElektroBit safety OS
  OS_TYPE_EB        = 'OS_TYPE_EB'       # ElektroBit normal OS
  OS_TYPE_VECTOR    = 'OS_TYPE_VECTOR'   # Vector OS
  OS_TYPE_RTOS      = 'OS_TYPE_RTOS'     # Safe RTOS or free RTOS
  OS_TYPE_SYS_BIOS  = 'OS_TYPE_SYS_BIOS' # SysBios (TexasInstruments)  
  OS_TYPE_NONE      = 'OS_TYPE_NONE'     # No OS used

  PREFIX_RTA_TASK_IDS          = 'OS_RTA_TASKID_'
  TASK_LUT_FILE_NAME           = 'os_rta_taskid_lut_cfg.h'
  TASK_LUT_TEMPLATE_FILE_NAME  = 'os_rta_taskid_lut_cfg_template.h'

  # The searchPattern for lines in rta_globalids.h containing a globalID define, like the following: 
  # #define RTA_GLOBALID_INTERRUPTS          ((RTA_t_GlobalID)   0)  ///< All the interrupts - only for RTA internal usage!!
  GLOBAL_ID_DEFINE_SEARCH_PATTERN = r' *#define +(RTA_GLOBALID_[\S]+) +\(\(RTA_t_GlobalID\) *([\d]+) *\) *[///<]* *(.*)' # Group(1) -> Name, Group(2) -> Value, Group(3) -> Comment  

  # The prefix of globalID defines/static const in rta_globalids.h
  GLOBAL_ID_NAME_PREFIX = 'RTA_GLOBALID_'

  # This is the start of the RteGlobalIDs range 
  # 0 - The invalid globalID
  # 1 - The Interrupt globalID
  # 2 - 3999: Any globalIDs for components 
  # 4000 - 4095: The RteGlobalIDs
#  RTE_GLOBAL_IDS_RANGE_START = 4000
  RTE_GLOBAL_IDS_RANGE_START = 200 # Intermediate solution as long as the MOs not adapted for 12 bit

  # This is the max value of the globalIDs - the max value in the 12-bit range 
  GLOBAL_ID_MAX_VALUE   = 4095
  
  # The max number of RteGlobalIDs which is also the max number of tasks in the project as we need one RteGlobalID per task
#  MAX_NUMBER_RTE_GLOBAL_IDS = (GLOBAL_ID_MAX_VALUE + 1) - RTE_GLOBAL_IDS_RANGE_START
  MAX_NUMBER_RTE_GLOBAL_IDS = 256 - RTE_GLOBAL_IDS_RANGE_START  # Intermediate solution as long as the MOs not adapted for 12 bit
  
  # The generatorTags for the rta_globalids.h
  GEN_TAG_GLOBAL_ID_START   = '___GENERATOR_TAG___RTA_GLOBAL_IDS___START___'
  GEN_TAG_GLOBAL_ID_END     = '___GENERATOR_TAG___RTA_GLOBAL_IDS___END___'
  
  #The names of the configFiles of the supported OS
  #Note: In SafeRTOS and in FreeRTOS the name of the configFile can be chosen by the user therefore we do not have a variable here for it
  OS_CFG_FILE_EB_S      = 'Mk_gen_user.h'
  OS_CFG_FILE_PRIO_EB_S = 'Mk_gen_config.h'
  
  OS_CFG_FILE_EB      = 'Os_user.h'
  OS_CFG_FILE_PRIO_EB = 'Os_config.h' 
  
  OS_CFG_FILE_VECTOR      = 'Os_Types_Lcfg.h'
  OS_CFG_FILE_PRIO_VECTOR = 'Os_Task_Lcfg.c' 

  #The file containing the generationID for file match check
  #In case of EB and EB_S it is the OS_user.h. 
  #In case of Vector we currently do not have such an ID
  OS_GEN_ID_FILE = 'Os_user.h'

  #GeneratorTags used in os_rta_task_ids.h
  GEN_TAG_TASK_IDS_ENUM_START          = '___GENERATOR_TAG___RTA_TASK_ENUM___START___'
  GEN_TAG_TASK_IDS_ENUM_END            = '___GENERATOR_TAG___RTA_TASK_ENUM___END___'

  # GeneratorTags used in os_rta_taskid_lut_cfg.h
  GEN_TAG_COMPAT_CHECK_START    = '___GENERATOR_TAG___COMPATIBILITY_CHECK___SECTION_START___'
  GEN_TAG_COMPAT_CHECK_END      = '___GENERATOR_TAG___COMPATIBILITY_CHECK___SECTION_END___'
  GEN_TAG_AUX_TASK_LIST_START   = '___GENERATOR_TAG___AUX_TASK_LIST___SECTION_START___'
  GEN_TAG_AUX_TASK_LIST_END     = '___GENERATOR_TAG___AUX_TASK_LIST___SECTION_END___'
  GEN_TAG_LUT_START             = '___GENERATOR_TAG___LUT___SECTION_START___'
  GEN_TAG_LUT_END               = '___GENERATOR_TAG___LUT___SECTION_END___'

  # GeneratorTags used in the RTOS (freeRTOS and safeRTOS) configuration header 
  GEN_TAG_RTOS_PRIO_DEFINES_START    ='___GENERATOR_TAG___TASK_PRIORITY_DEFINES_START__'
  GEN_TAG_RTOS_PRIO_DEFINES_END      ='___GENERATOR_TAG___TASK_PRIORITY_DEFINES_END__'
  GEN_TAG_RTOS_TASK_CFG_START        ='___GENERATOR_TAG___TASK_CFG_ARRAY_START__'
  GEN_TAG_RTOS_TASK_CFG_END          ='___GENERATOR_TAG___TASK_CFG_ARRAY_END__'
  
  
  # All the keys for the dictionaries defined in the inputCfgFiles 
  INPUT_DICT_KEY_PROJECT                    = 'project'          
  INPUT_DICT_KEY_BUILD_UNIT                 = 'build_unit'          
  INPUT_DICT_KEY_OUTPUT_PATH                = 'output_path' 
  INPUT_DICT_KEY_OS_DIR_PATH                = 'os_dir_path'      
  INPUT_DICT_KEY_OS_CFG_FILE                = 'os_cfg_file'      
  INPUT_DICT_KEY_LUT_CFG_FILE_PATH          = 'lut_cfg_file_path'
  INPUT_DICT_KEY_PDO_PATH                   = 'pdo_path'         
  INPUT_DICT_KEY_GEN_CFG_FILE               = 'generator_cfg_file'  
  INPUT_DICT_KEY_RTA_GLOBAL_IDS_H           = 'rta_globalids_h'  
  INPUT_DICT_KEY_RTA_TASK_IDS_H             = 'rta_taskids_h'   
  INPUT_DICT_KEY_BUILD_H                    = 'build_h' 
  INPUT_DICT_KEY_OS_TYPE                    = 'os_type'      
  INPUT_DICT_KEY_GEN_CFG_PATH               = 'gen_cfg_path'
  INPUT_DICT_KEY_OUTPUT_PATH_SRC            = 'output_path_src'            
  INPUT_DICT_KEY_OUTPUT_PATH_INCL           = 'output_path_incl'           
  INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_SRC   = 'rte_check_in_dir_path_src'  
  INPUT_DICT_KEY_RTE_CHECKIN_DIR_PATH_INCL  = 'rte_check_in_dir_path_incl' 
  INPUT_DICT_KEY_RTE_GEN_TYPE               = 'rte_gen_type' 
  INPUT_DICT_KEY_LOCAL_ID_XML_PATH          = 'local_id_xml_path'
  
  # All constants used to determine which check shall be done. 
  # These constants shall be used for checking the provided path and files in the inputCfgFile
  RUN_TEST_NONE = 0  # NO test at all
  RUN_TEST_FILE = 1  # Is file available
  RUN_TEST_DIR  = 2  # Is folder available
  
  # All keys used to determine which referencePath shall be used 
  REF_PATH_NONE         = 'none'                # No referencePath is used or needed at all
  REF_PATH_PRJ          = 'prjRefPath'          # The projectReferencePath is used
  REF_PATH_PDO          = 'pdoRefPath'          # The pdoReferencePath is used
  REF_PATH_GLOB_IDS     = 'globIdRefPath'       # The globalIDsReferencePath is used
  REF_PATH_OUTPUT       = 'outputRefPath'       # The outPutReferencePath is used
  REF_PATH_LOCAL_ID_XML = 'localIdXmlsRefPath'  # The localIdXmlsRefPath is used
  
  
  INFO_TEXT_INPUT_CFG_FILE_MISSING = '''The file 
  
  {0} 
  
  provided as argument could not be found!   
  
  Please check the provided argument and ensure that the file is available at given location. 
'''
  INFO_TEXT_INPUT_CFG_FILE_KEY_MISSING = '''The key "{0}" is missing in the inputConfigurationFile 
"{1}" 
Please refer to the corresponding templateFile 
"{2}"
for further information.
'''

  INFO_TEXT_INPUT_CFG_FILE_NOT_A_DICT = 'Data in the inpufCfgFile have to be provided as a dictionary which is not the case'
  
  INFO_TEXT_INPUT_CFG_FILE_OR_DIR_MISSING = '''The file or directory 
"{0}" 
which has been provided as "{1}" in the inputCfgFile
is not available. Please double check related entry in the inputCfgFile: 
"{2}" 

Or you may need to provide the related reference path as an argument at generator call that the absolute path can be built up.

HINT: You can run the generator with the argument "-h" 
      in order to get the information about all the required and optional arguments including description.  
'''
  
  INFO_TEXT_REF_PATH_INVALID = '''The reference path 
{0}  
  given as argument at generator call is invalid. 
'''

  INFO_TEXT_LOG_FILE_GENERATION ='''
Logfile generated: 
{0}
'''
  
  #The string for the idleTask. This is required in case of RTOS (freeRTOS and safeRTOS) as here the ildeTask is created automatically. Therefore it is not in the 
  #configuration array of the normal tasks.
  STRING_IDLE_TASK = 'Idle'
  
  #Initialize the class################################################################################################################################################################################
  def __init__(self):
    print ('chainCommon')

  #########################################################################################################################################################
  def load_yaml(self, yaml_file):
    '''
    Load yaml configuration
    @return: document
    '''
    try:
      with open(yaml_file, 'r') as stream:
        doc = yaml.safe_load(stream)
    except yaml.YAMLError as ex:
      raise Exception('Error parsing ' + yaml_file + '\n' + str(ex))
    return doc

  #########################################################################################################################################################
  def checkInputCfgFileAndConvertToAbsPaths(self, inputCfg, refPathDict, inputCfgFileCheckList, logLines, inputCfgFile, inputCfgFileTemplate):
    '''This function does 
       - a format check of given inputCfg file
       - it does a validyCheck of all refPaths given in refPathDict  
         Then it converts all relative path given in inputCfg to absolute path using the related refPath
       - Finally it does an availability check of all given files and directory according inputCfgFileCheckList 
       - When specified in inputCfgFileCheckList it generates directories in case they are missing ("dirGen = True")
    '''
    
    inputInfo= ''
    keyMaxLength = 0
    
    # Do a formatCheck (is dictionary, are all required keys available) 
    if not isinstance(inputCfg, dict):
      #Data provided in inputCfgFile is not stored as a dictionary!
      raise Exception(self.INFO_TEXT_INPUT_CFG_FILE_NOT_A_DICT)

    else:
      for entry in inputCfgFileCheckList:
        #Check whether generatorConfigFile has all required keys - which are mandatory
        if True == entry['mandatory']:
          if not entry['dictKey'] in inputCfg:
            raise Exception(self.INFO_TEXT_INPUT_CFG_FILE_KEY_MISSING.format(entry['dictKey'], inputCfgFile, inputCfgFileTemplate))
          
    
    # Get all keys from the referencePath dictionary
    refPathKeyList = refPathDict.keys()
    
    for key in refPathKeyList:
      #Check all given referencPaths 
      inputInfo += '''
As {0} the following path has been provided:
    ->{1}
  
'''.format(key, refPathDict[key])
      if not os.path.isdir(refPathDict[key]):
        raise Exception(self.INFO_TEXT_REF_PATH_INVALID.format(refPathDict[key]))

    # All given reference paths are valid - convert all given relPaths to absPaths 
    for entry in inputCfgFileCheckList:
      if entry['dictKey'] in inputCfg:
        #OK, this key is available in the inputCfg 
        if keyMaxLength < len(entry['dictKey']):
          keyMaxLength = len(entry['dictKey'])

        if entry['refPath'] in refPathDict:
          #Convert path to absPath - if needed
          inputCfg[entry['dictKey']] = self.getAbsolutePath(refPathDict[entry['refPath']], inputCfg[entry['dictKey']])
      
    # Collect all input information for the logFile
    inputInfo += 'There are the following inputs given:\n'
    for entry in inputCfgFileCheckList:
      if entry['dictKey'] in inputCfg:
        inputInfo += '- {0}: {1}\n'.format(entry['dictKey'].ljust(keyMaxLength), inputCfg[entry['dictKey']]) 
        
    # Now check whether all given paths and files are available
    for entry in inputCfgFileCheckList:
      if entry['dictKey'] in inputCfg:
        #OK, this key is available in the inputCfg
        #Check whether this list entry provides a file or a directory path 
        if self.RUN_TEST_FILE == entry['runTest']:
          #This is a file - check if it's available
          if not os.path.isfile(inputCfg[entry['dictKey']]):
            raise Exception(self.INFO_TEXT_INPUT_CFG_FILE_OR_DIR_MISSING.format(inputCfg[entry['dictKey']], entry['dictKey'], inputCfgFile))
          
        elif self.RUN_TEST_DIR == entry['runTest']:
          #This is a directory
          if not os.path.isdir(inputCfg[entry['dictKey']]):
            if entry['dirGen']:
              #Generate missing directory
              os.makedirs(inputCfg[entry['dictKey']], exist_ok=True)
            else:
              raise Exception(self.INFO_TEXT_INPUT_CFG_FILE_OR_DIR_MISSING.format(inputCfg[entry['dictKey']], entry['dictKey'], inputCfgFile))
    
    print(inputInfo)
    logLines.append(inputInfo)
    
    
  #########################################################################################################################################################
  def getDefaultLocationForLogFile(self):
    
    #Extract the drive information from current filePath 
    obj = re.match(r'([A-Za-z]{1}:{1}).+', __file__)
    if obj:
      drive = obj.group(1)
    else: 
      # Just use D:\ as default solution 
      drive = 'D:'
    
    logDir = drive + '/temp/RtaGeneratorLogs'

    if not os.path.isdir(logDir):
      # directory not availabe yet - generate it! 
      os.makedirs(logDir, exist_ok=True)    
    
    return logDir
    
    
  ####################################################################################################################################################################################################
  def getAbsolutePath(self, basePath, relPath):

    if os.path.isabs(relPath):
      #It is already an absolute path
      absolutePath = relPath
    else:
      # Remove leading and trailing whiteSpaces and leading slashes and back slashes
      relPath = relPath.strip(' ')
      relPath = relPath.lstrip('/')
      relPath = relPath.lstrip('\\')
      
      absolutePath = os.path.join(basePath, relPath)

    return absolutePath

  #####################################################################################################################################################################################################
  def moveLinesBelowTagToSeparateList(self, tag, srcList, targetList):
    idx   = 0

    #Ensure that targetList is empty
    del targetList[:]
    #Find the tag in srcList
    for line in srcList:
      if -1 != line.find(tag):
        #tag found - copy the rest of the lines to targetList
        targetList.extend(srcList[idx:])
        # Delete the section from sourceList
        del srcList[idx + 1:]
        #terminate the loop immediately
        break
      #Increment running index
      idx += 1


  #####################################################################################################################################################################################################
  def addLinesBelowTag(self, tag, srcList, targetList):
    idx = 0
    #Look for tag in sourceList
    for line in srcList:
      if -1 != line.find(tag):
        #Tag found - copy all lines below to targetList
        targetList.extend(srcList[idx:])
        break
      idx = idx + 1

  #Read the lines of given file ##################################################################################################################################################
  #Note: In case the file does not exist just an empty list of lines is returned!
  def getLinesOfFile(self, fileToRead):
    lines = []
    #Read all lines of given file - if it exists
    if os.path.isfile(fileToRead):
      fileObj = open(fileToRead)
      lines = fileObj.readlines()
      fileObj.close()

    return lines


  #Write the lines into given file ##################################################################################################################################################
  def writeLinesintoFile(self, fileToWrite, lines):

    #Remove writeProtection in case this file already exists
    if os.path.isfile(fileToWrite):
      st_mode = os.stat(fileToWrite).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(fileToWrite, st_mode)

    #Write the lines into file
    fileObj = open(fileToWrite, 'w')
    fileObj.writelines(lines)
    fileObj.close()


  ################################################################################################################################################################
  def readStringOfFile(self, fileToRead):
    string = ''
    if os.path.isfile(fileToRead):
      fileObj = open(fileToRead)
      #read all lines of file and close it afterwards
      string = fileObj.read()
      fileObj.close()

    return string


  ################################################################################################################################################################
  def writeStringToFile(self, fileToWrite, string):
    #Remove writeProtection in case the file already exists
    if os.path.isfile(fileToWrite):
      st_mode = os.stat(fileToWrite).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(fileToWrite, st_mode)

    # Write the string into file
    fileObj = open(fileToWrite, 'w')
    fileObj.write(string)
    fileObj.close()

  ################################################################################################################################################################
  #Functions providing the osTasks from given files
  # Currently the following OS are provided:
  # - EB safety os
  # - EB normal os
  ################################################################################################################################################################
  ################################################################################################################################################################
  def getTasksFromOsCfgFile(self, osCfgFile, osTasks, osType):
    # Ensure that provided taskList is empty
    del osTasks[:]

    if os.path.isfile(osCfgFile):
      #OK - file exists - check which OS we have
      if self.OS_TYPE_EB_S == osType:
        #We have an EB safety OS - call related function
        self.getOsTasksEbSafetyOs(osCfgFile, osTasks)
        
      elif self.OS_TYPE_EB == osType:
        self.getOsTaskEbNormalOs(osCfgFile, osTasks)
      
      elif self.OS_TYPE_VECTOR == osType:
        self.getOsTaskVectorOs(osCfgFile, osTasks)
      
      elif self.OS_TYPE_RTOS == osType:
        self.getOsTasksRTOS(osCfgFile, osTasks)
      
      else:
        raise Exception("OS not supported!") 
       
    else:
      raise Exception("Configuration file " + osCfgFile + " does not exists!")

  #Get all tasks from elektroBit Mk_gen_user.h file   ##########################################################################################################################
  def getOsTasksEbSafetyOs(self, osCfgFile, osTasks):
    #Read all lines of osCfgFile
    fileObj = open(osCfgFile)
    lines = fileObj.readlines()
    fileObj.close()

    #Note: Currently only eletrobitOS is supported
    #All available values for 'state'
    stateSectionNotReached     = 0
    stateSectionReached        = 1
    stateFirstDefinitionFound  = 2
    stateLastDefinitionFound   = 3
    query = '* Tasks'
    state = stateSectionNotReached

    #Find the section where the taskIDs are defined
    for line in lines:
      found = False
      if state == stateSectionNotReached:
        if line.find(query) != -1:
          state = stateSectionReached
      elif state == stateSectionReached:
        if line.startswith('#define'):
          found = True
          state = stateFirstDefinitionFound
      elif state == stateFirstDefinitionFound:
        if line.startswith('#define'):
          found = True
        else:
          state = stateLastDefinitionFound
      #Check if we have a line containing a definition of a taskID
      if found == True:
        # Clean the line that only name and value remain
        line =  line.strip('#define')
        line = line.rstrip('\n')
        line = line.strip()
        #Seperate name and value supposing that we have only name and value in line seperated by space
        NameValue = line.split()
        osTasks.append(NameValue[0])

  #Get all tasks from elektroBit Os_user.h file   ##########################################################################################################################
  def getOsTaskEbNormalOs(self, osCfgFile, osTasks):
    #Read all lines of osCfgFile
    fileObj = open(osCfgFile)
    lines = fileObj.readlines()
    fileObj.close()

    #Note: Currently only eletrobitOS is supported
    #All available values for 'state'
    stateSectionNotReached     = 0
    stateSectionReached        = 1
    stateFirstDefinitionFound  = 2
    stateLastDefinitionFound   = 3
    query = '* Tasks'
    state = stateSectionNotReached

    #Find the section where the taskIDs are defined
    for line in lines:
      found = False
      if state == stateSectionNotReached:
        if line.find(query) != -1:
          state = stateSectionReached
      elif state == stateSectionReached:
        if line.startswith('#define'):
          found = True
          state = stateFirstDefinitionFound
      elif state == stateFirstDefinitionFound:
        if line.startswith('#define'):
          found = True
        elif (not line.startswith('#endif')) and (not line.startswith('#if OS_KERNEL_TYPE')):
          #we already found the last taskDefinition
          state = stateLastDefinitionFound
      #Check if we have a line containing a definition of a taskID
      if found == True:
        # Clean the line that only name and value remain
        line =  line.strip('#define')
        line = line.rstrip('\n')
        line = line.strip()
        #Seperate name and value supposing that we have only name and value in line seperated by space
        NameValue = line.split()
        osTasks.append(NameValue[0])

  def getOsTaskVectorOs(self, osCfgFile, osTasks):
        #Read all lines of osCfgFile
    fileObj = open(osCfgFile)
    lines = fileObj.readlines()
    fileObj.close()

    # In Os_Types_Lcfg.h we expect to find the taskIDs defined in the enumeration TaskType with the following format:
    # 
    # /*! Task identifiers. */
    # typedef enum
    # \{
    #   IdleTask_OsCore0 = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_Appl_HighPrio = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_Background = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_Bsw_StartUp = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_Com = 4,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_Cyclic_BswM = 5,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_Cyclic_SWC = 6,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_Init = 7,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_PduRx = 8,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_SecurityBackground = 9,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   Tsk_SelfTest = 10,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   OS_TASKID_COUNT = 11,
    #   INVALID_TASK = OS_TASKID_COUNT
    # } TaskType;
    # 

    startQuery = '/*! Task identifiers. */'
    inRegionOfInterrest = False

    PATTERN_TASK_LITERAL  = r' *(\S+) *= *\d+ *, *'      # Group(1) is the taskName
    
    #Find the section where the taskIDs are defined
    for line in lines:
      if inRegionOfInterrest == False:
        if line.find(startQuery) != -1:
          #We reached the taskType enum
          inRegionOfInterrest = True
      else:
        obj = re.match(PATTERN_TASK_LITERAL, line)
        if obj:
          taskName = obj.group(1)
          
          #Check whether it's the line of the OS_TASKID_COUNT, which is actually the line after the last taskID
          if 'OS_TASKID_COUNT' == taskName:
            #We reached the end of the task literals in the enum - stop collecting the taskNames 
            break
          else: 
            #Add the task to the list
            osTasks.append(taskName)

  def getOsTasksRTOS(self, osCfgFile, osTasks):
    '''Get all tasks from the osCfgFile of the SafeRTOS or the FreeRTOS'''
    
        #Read all lines of osCfgFile
    fileObj = open(osCfgFile)
    lines = fileObj.readlines()
    fileObj.close()

    ''' In Os_Types_Lcfg.h we expect to find the taskIDs defined in the taskConfig array with the following format:
    // ___GENERATOR_TAG___TASK_CFG_ARRAY_START__
    static const task_config_t taskConfig[NUM_OF_TASKS] = {
    /* Name               Handle              Function                Priority                Stack                    Stack Size                    Privilege level*/
    {"Tsk_Startup",       &Tsk_Startup,       Tsk_Startup_func,       TSK_STARTUP_PRIO,       Tsk_Startup_Stack,       TSK_STARTUP_STACK_SIZE,       safertosapiPRIVILEGED_TASK},
    // ___GENERATOR_TAG___TASK_CFG_ARRAY_END__ 

'''
    
    inRegionOfInterrest = False

    startQuery               = self.GEN_TAG_RTOS_TASK_CFG_START
    endQuery                 = self.GEN_TAG_RTOS_TASK_CFG_END
    PATTERN_TASK_LITERAL     = r' *\{ *" *(\S+) *" *, *&'      # Group(1) is the taskName
    
    #Find the section where the taskIDs are defined
    for line in lines:
      if inRegionOfInterrest == False:
        if line.find(startQuery) != -1:
          #We reached the taskCfg array
          inRegionOfInterrest = True
      else:
        obj = re.match(PATTERN_TASK_LITERAL, line)
        if obj:
          #Add the task to the list
          osTasks.append(obj.group(1))
        else:  
          #Check whether it's the terminating line of the taskCfgArray
          if line.find(endQuery) != -1:
            #We reached the end of the taskCfgArray - stop collecting the taskNames 
            break
    
    #Finally add the idleTask to the list
    #Note: In the RTOS the idleTask is generated automatically, therefore it is not in the list of configured tasks
    osTasks.append(self.STRING_IDLE_TASK)

