import os
import stat
import sys
import argparse

try:
# python 2
    import tkMessageBox as tkinter_messagebox
except ImportError:
# python 3
    import tkinter.messagebox as tkinter_messagebox
from datetime import datetime
from shutil import copy

sys.path.append(os.path.join(sys.path[0],'../ToolChainCommon'))

from ChainCommon              import ChainCommon
from GeneratorCommon          import GeneratorCommon
from GenerateLocalIdXmls      import LocalIdXmlGenerator
from GenerateLocalIdXmlForISR import LocalIdXmlGeneratorForISR
from GenerateComponentIdXml   import ComponentIdGenerator
from GenerateRtaCoresXml      import RtaCoresXmlGenerator



#################################################################################
# The RtaXmlGenerator
#################################################################################
class RtaXmlGenerator(GeneratorCommon):

  INFO_TEXT_GEN_CFG_FILE_NO_DICT = 'The data contained in the generatorConfiguratonFile is not provided as a dictionary.\n'
  
  INFO_TEXT_GEN_CFG_FILE_ELEMENT_MISSING = 'The element "{0}" is missing in the generatorConfiguratonFile.\n'

  INFO_TEXT_GEN_CFG_FILE_KEY_MISSING = 'The key "{0}" is missing in the generatorConfiguratonFile.\n'

  INFO_TEXT_GEN_CFG_FILE_INCORRECT_NO_OF_PARAMS = '''At least one core has an invalid number of parameters.
Every core needs to have exactly {0} parameters in the correct order!
'''
  INFO_TEXT_GEN_CFG_OS_FILE_MISSING = '''The following osCfgfile is not available: 
{0}

'''

  INFO_TEXT_GEN_CFG_DAT_FILE_MISSING = '''The following datFile is not available: 
{0}

'''
  

  INFO_TEXT_CFG_FILE_EXAMPLE = '''
Please refer to RtaXmlGeneratorCfg.yaml stored at

{0}

as an example.
'''
  
  INFO_TEXT_OS_TYPE_NOT_SUPPORTED = '''ConfigurationError: Given OS type not supported: {0}.
Supported OS-Types are {1}
''' # 0 -> given osType, list of supported OS-types 

  INFO_TEXT_OS_DIR_PATH_MISSING = '''ConfigurationError: We have the OS type {0} but no os_dir_path given. Please provide it as {1} in the RtaXmlGenerator_InputCfg.yaml
''' # 0 -> osType; 1 -> os_dir_path       
  
  INFO_TEXT_LUT_CFG_FILE_PATH_MISSING = '''ConfigurationError: We have the OS type {0} but no lut_cfg_file_path given. Please provide it as {1} in the RtaXmlGenerator_InputCfg.yaml           
''' # 0 -> osType; 1 -> lut_cfg_file_path
  
  INFO_TEXT_RTA_TASK_IDS_H = '''ConfigurationError: We have the OS type {0} but no os_rta_task_ids.h given. Please provide it including path as {1} in the RtaXmlGenerator_InputCfg.yaml           
''' # 0 -> osType; 1 -> lut_cfg_file_path
  
  InputCfgFileCheckList = [
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_PROJECT           , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE          , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_BUILD_UNIT        , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE          , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OUTPUT_PATH       , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : True  , 'refPath' : ChainCommon.REF_PATH_OUTPUT        , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_PDO_PATH          , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PDO           , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_GEN_CFG_FILE      , 'runTest' : ChainCommon.RUN_TEST_FILE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ           , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_RTA_GLOBAL_IDS_H  , 'runTest' : ChainCommon.RUN_TEST_FILE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_GLOB_IDS      , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OS_TYPE           , 'runTest' : ChainCommon.RUN_TEST_NONE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_NONE          , 'mandatory' : True  },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_OS_DIR_PATH       , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ           , 'mandatory' : False },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_LUT_CFG_FILE_PATH , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ           , 'mandatory' : False },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_RTA_TASK_IDS_H    , 'runTest' : ChainCommon.RUN_TEST_FILE , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_PRJ           , 'mandatory' : False },
    { 'dictKey' : ChainCommon.INPUT_DICT_KEY_LOCAL_ID_XML_PATH , 'runTest' : ChainCommon.RUN_TEST_DIR  , 'dirGen' : False , 'refPath' : ChainCommon.REF_PATH_LOCAL_ID_XML  , 'mandatory' : False },
  ]
  
  # This list contains all osTypes which are accepted as "os_type" in the xml_generator_input_cfg file.
  ALL_SUPPORTED_OS_TYPES = [
    ChainCommon.OS_TYPE_EB_S    ,  
    ChainCommon.OS_TYPE_EB      ,
    ChainCommon.OS_TYPE_VECTOR  , 
    ChainCommon.OS_TYPE_RTOS    ,
    ChainCommon.OS_TYPE_SYS_BIOS,
    ChainCommon.OS_TYPE_NONE    ,
  ]
 
  #Initialize RtaXmlGenerator class
  def __init__(self):

    #Create objects of all needed generators
    self.localIdGen       = LocalIdXmlGenerator()
    self.localIdForIsrGen = LocalIdXmlGeneratorForISR()
    self.globalIdGen      = ComponentIdGenerator()
    self.rtaCoresGen      = RtaCoresXmlGenerator()

    self.doIt()

# argument parsing ############################################################################
  def check_args(self):
    parser = argparse.ArgumentParser(prog='GenerateRtaXmls',
                                     formatter_class=argparse.RawTextHelpFormatter,
                                     description = 'Generate all RtaXmlFiles.')
    parser.add_argument('inputCfgFile',
                        action = 'store',
                        help ='The input configuration file in which all relevant files and folders are provided.')
    
    parser.add_argument('-r', '--prjRefPath',
                        action ='store',
                        help = '''The project referencePath is used as a base to determine the absolutePaths for the following elements 
in the RtaXmlGenerator_InputCfg*.yaml:  "generator_cfg_file", "os_dir_path", "lut_cfg_file_path", "rta_taskids_h"
This argument is not necessary in case all these elements are provided with absolute paths in the RtaXmlGenerator_InputCfg*.yaml.''')

    parser.add_argument('-p', '--pdoRefPath',
                        action ='store',
                        help = '''This argument has to provide the base path where the DAT files are stored to by the pdoTool.
This referencePath is used to establish an absolute path together with the "pdo_path" given in the corresponding RtaXmlGenerator_InputCfg*.yaml
This argument is not necessary in case "pdo_path" in the RtaXmlGenerator_InputCfg*.yaml is given as an absolute path.''')

    parser.add_argument('-i', '--globIdRefPath',
                        action ='store',
                        help = '''This argument has to provide the base path to the rta_globalids.h - e.g. the package path in which the globalID file can be found. 
This referencePath is used to establish an absolute path together with the "rta_globalids_h" given in the corresponding RtaXmlGenerator_InputCfg*.yaml
This argument is not necessary in case "rta_globalids_h" in the RtaXmlGenerator_InputCfg*.yaml is given as an absolute path.''')

    parser.add_argument('-o', '--outputRefPath',
                        action ='store',
                        help = '''This argument has to provide the base path to the desired outputPath. 
This referencePath is used to establish an absolute path together with the "output_path" given in the corresponding RtaXmlGenerator_InputCfg*.yaml.
This argument is not necessary in case "output_path" in the RtaXmlGenerator_InputCfg*.yaml is given as an absolute path. 
''')

    parser.add_argument('-l', '--localIdXmlsRefPath',
                        action ='store',
                        help = '''This argument has to provide the base path to the path where preGenerated localIdXml files are located. 
This referencePath is used to establish an absolute path together with the "local_id_xml_path" given in the corresponding RtaXmlGenerator_InputCfg*.yaml.
In case there are no preGenerated localIdXml files, which means the "local_id_xml_path" is not given in the corresponding RtaXmlGenerator_InputCfg*.yaml 
then it is not relevant at all.
This argument is also not necessary in case "local_id_xml_path" in the RtaXmlGenerator_InputCfg*.yaml is given as an absolute path. ''')

    parser.add_argument('-g', '--gui',
                        action ='store_true',
                        default = False,
                        help = 'enables/disables configuration GUI')
    return parser.parse_args()

  #This is the main function calling all other generators ###################################################################################
  def doIt(self):
    errorCode    = self.ERR_OK
    info         = []
    errorInfo    = []
    logLines     = []
    project      = 'UnknownProject'
    buildUnit    = 'UnknownBuildUnit'
    logPath      = ''
    refPathDict  = {}

    args = self.check_args()
    
    # Set the guiEnabledFlag in dependency of given argument 
    self.guiEnabled = args.gui

    if not os.path.isfile(args.inputCfgFile):
      errorCode = self.ERR_INPUT_CFG_FILE_MISSING
      errorInfo.append(self.INFO_TEXT_INPUT_CFG_FILE_MISSING.format(args.inputCfgFile))
      
    if self.ERR_OK == errorCode:
      inputCfg = self.load_yaml(args.inputCfgFile)
      
      # Collect all refPaths in the dictionary required for calling the function checkInputCfgFileAndConvertToAbsPaths()
      if args.prjRefPath:
        refPathDict[ChainCommon.REF_PATH_PRJ] = args.prjRefPath
        
      if args.pdoRefPath:
        refPathDict[ChainCommon.REF_PATH_PDO] = args.pdoRefPath
      
      if args.globIdRefPath:
        refPathDict[ChainCommon.REF_PATH_GLOB_IDS] = args.globIdRefPath
      
      if args.outputRefPath:
        # outputRefPath given - use it instead of the project reference path 
        refPathDict[ChainCommon.REF_PATH_OUTPUT] = args.outputRefPath
        
      if args.localIdXmlsRefPath:
        # localIdXmlsRefPath given - use it instead of the PDO reference path
        refPathDict[ChainCommon.REF_PATH_LOCAL_ID_XML] = args.localIdXmlsRefPath
       
      
      try:
        templateFile = os.path.join(os.getcwd(), 'ConfigurationTemplate\RtaXmlGenerator_InputCfg.yaml')
        self.checkInputCfgFileAndConvertToAbsPaths(inputCfg, refPathDict, self.InputCfgFileCheckList, logLines, args.inputCfgFile, templateFile)
        
        # Check validity of given OS_TYPE  
        for osType in self.ALL_SUPPORTED_OS_TYPES:
          if inputCfg[self.INPUT_DICT_KEY_OS_TYPE] == osType: 
            # Given OsType is supported
            break
        else:
          # Given OsType is invalid! 
          raise Exception(self.INFO_TEXT_OS_TYPE_NOT_SUPPORTED.format(inputCfg[self.INPUT_DICT_KEY_OS_TYPE], self.ALL_SUPPORTED_OS_TYPES))
        
        if inputCfg[self.INPUT_DICT_KEY_OS_TYPE] != self.OS_TYPE_NONE:
          # We have an OS in use - check whether we have also os_dir_path and lut_cfg_file_path provided
          # Note: As these are optional keys in the inputCfg we cannot test it in the function checkInputCfgFileAndConvertToAbsPaths()
          if not self.INPUT_DICT_KEY_OS_DIR_PATH in inputCfg:
            raise Exception(self.INFO_TEXT_OS_DIR_PATH_MISSING.format(inputCfg[self.INPUT_DICT_KEY_OS_TYPE], self.INPUT_DICT_KEY_OS_TYPE))
          
          if not self.INPUT_DICT_KEY_LUT_CFG_FILE_PATH in inputCfg:
            raise Exception(self.INFO_TEXT_LUT_CFG_FILE_PATH_MISSING.format(inputCfg[self.INPUT_DICT_KEY_OS_TYPE], self.INPUT_DICT_KEY_LUT_CFG_FILE_PATH))
          
          if not self.INPUT_DICT_KEY_RTA_TASK_IDS_H in inputCfg: 
            raise Exception(self.INFO_TEXT_RTA_TASK_IDS_H.format(inputCfg[self.INPUT_DICT_KEY_OS_TYPE], self.INPUT_DICT_KEY_RTA_TASK_IDS_H))

      except Exception as ex:
        print(ex)
        errorInfo.append(str(ex))
        errorCode = self.ERR_INPUT_CFG_FILE_ERROR
      finally:
        #Update project, buildUnit and logPath with given values as far as available
        if self.INPUT_DICT_KEY_PROJECT in inputCfg:
          project   = inputCfg[self.INPUT_DICT_KEY_PROJECT]     
        if self.INPUT_DICT_KEY_BUILD_UNIT in inputCfg:
          buildUnit = inputCfg[self.INPUT_DICT_KEY_BUILD_UNIT]
        if self.INPUT_DICT_KEY_OUTPUT_PATH in inputCfg: 
          if ChainCommon.REF_PATH_OUTPUT in refPathDict:
            #Set logPath to given output path 
            logPath  = self.getAbsolutePath(refPathDict[ChainCommon.REF_PATH_OUTPUT], inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH])
          else:
            logPath  = inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH]
        
    if self.ERR_OK == errorCode:
      

      #Load the generatorCfgFile
      generatorCfg = self.load_yaml(inputCfg[self.INPUT_DICT_KEY_GEN_CFG_FILE])
      
      #Check format and content of XmlGeneratorConfigFile
      errorCode = self.checkGeneratorCfgFileAndConvertToAbsPaths(generatorCfg, inputCfg, errorInfo, logLines)

    if self.ERR_OK == errorCode:
      # Copy preGenerated localIdXmls to the outputFolder - if there are some
      self.copyPreGeneratedLocalIdXmlsToOutputFolder(inputCfg, logLines)
      
      #Have the localIdXml-Files generated
      print ('Call the LocalIdXmlGenerator')
      errorCode = self.localIdGen.doIt(generatorCfg, inputCfg)

    if self.ERR_OK == errorCode:
      if inputCfg[self.INPUT_DICT_KEY_OS_TYPE] != self.OS_TYPE_NONE:
        #Anything OK so far - have the localIdXml for the Interrupts generated
        print ('Call the LocalIdXmlGeneratorForISR')
        errorCode = self.localIdForIsrGen.doIt(generatorCfg, inputCfg)

    if self.ERR_OK == errorCode:
      #Anything OK so far - have the ComponentIdXml generated
      if generatorCfg[self.GENCFG_DICT_KEY_GEN_GLOBALID]:
        print ('Call the ComponentIdGenerator')
        errorCode = self.globalIdGen.doIt(generatorCfg, inputCfg)

    if self.ERR_OK == errorCode:
      #Anything OK so far - have the ComponentIdXml generated
      print ('Call the RtaCoresXmlGenerator')
      errorCode = self.rtaCoresGen.doIt(generatorCfg, inputCfg, errorInfo)

    if self.ERR_OK == errorCode:
      #Workaround - just copy the barchartXmls to the outputPath - as long as we are not generate them from the sourceCode
      self.copyBarCharts(generatorCfg, inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH])

      #Prepare the text for the logFile
      info.append('''The RtaXml-files have been generated to that directory:
      
{0}

If the location is not part of the MTS/mts_measurement/ini path, please copy the folder "RTA_xml" to a correct location'''.format(inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH]))
      logLines.append('\n\n')
      logLines.extend(info[0])
      if self.guiEnabled:
        #generate messageBox
        tkinter_messagebox.showinfo(self.MsgBoxTitle, info[0])
    else:
      print ('Error:  ' + self.errorMsgDict.get(errorCode, 'Unknown error!!'))
      #Prepare the text for the logFile
      logLines.append('The following error occurred during generator run: \n\n')
      logLines.append(self.errorMsgDict.get(errorCode, 'Unknown error!!'))
      logLines.append('\n' * 2)
      logLines.extend(errorInfo)

      if self.guiEnabled:
        errorText = self.errorMsgDict.get(errorCode, 'Unknown error!!')
        errorText += '\n' * 2
        for entry in errorInfo:
          errorText += entry
        #GeneratorCfgFile not found - generate messageBox
        tkinter_messagebox.showerror(self.MsgBoxTitle, errorText)

    #The logFile finally
    self.createLogFile(project, buildUnit, logLines, logPath)


  #########################################################################################################################################################
  def copyPreGeneratedLocalIdXmlsToOutputFolder(self, inputCfg, logLines):
    '''This function copies all relevant xmlFiles found in INPUT_DICT_KEY_LOCAL_ID_XML_PATH to the outputPath. It copies the files of following type:
       - *_LocalIDs.xml
       - *_ErrorIDs.xml
       - *_InternalIDs.xml
       - ErrOffsets.xml
       In case INPUT_DICT_KEY_LOCAL_ID_XML_PATH is not given it does nothing. 
    '''
    if self.INPUT_DICT_KEY_LOCAL_ID_XML_PATH in inputCfg:
      # OK there is a path for the localIdXml files given - get all files of interest
      print('\nThe following preGenerated XML files are used: \n')
      logLines.append('\nThe following preGenerated XML files are used: \n')
      
      for root, dirs, files in os.walk(inputCfg[self.INPUT_DICT_KEY_LOCAL_ID_XML_PATH]):  # @UnusedVariable
        for name in files:
          if(    name.endswith(self.XML_NAME_SUFFIXES[self.LOCAL_ID_XML])
              or name.endswith(self.XML_NAME_SUFFIXES[self.ERROR_ID_XML])
              or name.endswith(self.XML_NAME_SUFFIXES[self.INTERN_ERROR_ID_XML])
              or name == self.XML_NAME_SUFFIXES[self.ERROR_OFFSETS_XML]
            ):
              # This is a file of interest copy it to the outputFolder  
              src = os.path.join(root, name)
              dst = os.path.join(inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH], name)
              copy(src, dst)
              
              print('- ' + src)
              logLines.append('- ' + src + '\n')
      
      print('\n')
      logLines.append('\n')
    else:
      print('\nNo preGenerated XML files are used.\n')
      logLines.append('\nNo preGenerated XML files are used.\n')
      

  #########################################################################################################################################################
  def createLogFile(self, project, buildUnit, logLines, logPath):

    #Establish the headerLines of the file
    linesToWrite = []
    linesToWrite.append('\n' * 2)
    #Add headerLine
    linesToWrite.append('LogFile of the RtaXmlGenerator')
    #Add new lines
    linesToWrite.append('\n' * 2)
    #ProjectInfo and date
    linesToWrite.append('Project:   {}\n'.format(project))
    linesToWrite.append('BuildUnit: {}\n'.format(buildUnit))
    linesToWrite.append('Date:      {}\n'.format(datetime.now().strftime('%d.%m.%Y %H:%M:%S')))
    #Add new lines
    linesToWrite.append('\n' * 2)

    #Add lines provided as argument
    linesToWrite.extend(logLines)


    if not os.path.isdir(logPath):
      #generate the logFile to defaultLocation
      logPath = self.getDefaultLocationForLogFile()

    #check if file exists
    logFile = logPath + '/{0}_{1}_RtaXmlGenerator.log'.format(project, buildUnit)
    if os.path.isfile(logFile):
      # file already exists - remove writeProtection and open it'
      st_mode = os.stat(logFile).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(logFile, st_mode)
   
    # Write the log file
    try: 
      fileObj = open(logFile, 'w')
      fileObj.writelines(linesToWrite)
      fileObj.close()
      print(self.INFO_TEXT_LOG_FILE_GENERATION.format(logFile))
    except:
      print("RTA Generator ERROR: Cannot write log file - " + logFile)

  #############################################################################################################################################################################
  def checkGeneratorCfgFileAndConvertToAbsPaths(self, genCfg, inputCfg, errorInfo, logLines):
    '''This function does 
       - a format check of given generatorCfg file
       - for all given osCfgFiles and datFiles it replaces the REPLACE_PATTERNs then 
         it checks whether theses files are available
    '''

    errorCode = self.ERR_OK
    errorMsg  = []
    inputInfo= '\nThe following osConfigFiles  are used:\n'

    keyList = [self.GENCFG_DICT_KEY_CORES, 
               self.GENCFG_DICT_KEY_DAT_FILES,
               self.GENCFG_DICT_KEY_GEN_GLOBALID,
              ]

    # Do a formatCheck (is dictionary, are all required keys available) 
    if not isinstance(genCfg, dict):
      #Data provided in generatorCfgFile is not stored as a dictionary!
      errorCode = self.ERR_GENERATOR_CFG_FILE_INVALID
      errorMsg.append(self.INFO_TEXT_GEN_CFG_FILE_NO_DICT)

    if self.ERR_OK == errorCode:
      for key in keyList:
        #Check whether generatorConfigFile has all required keys
        if not key in genCfg:
          errorCode = self.ERR_GENERATOR_CFG_FILE_INVALID
          errorMsg.append(self.INFO_TEXT_GEN_CFG_FILE_KEY_MISSING.format(key))

    if self.ERR_OK == errorCode:
      #Check whether every core description has enough parameters
      for coreDescriptor in genCfg[self.GENCFG_DICT_KEY_CORES]:
        if self.NO_OF_PARAMETERS_IN_CORE_DESCRIPTOR != len(coreDescriptor):
          errorCode = self.ERR_GENERATOR_CFG_FILE_INVALID
          errorMsg.append(self.INFO_TEXT_GEN_CFG_FILE_INCORRECT_NO_OF_PARAMS.format(self.NO_OF_PARAMETERS_IN_CORE_DESCRIPTOR))
          break
    
    if self.ERR_OK == errorCode:
      # Everything OK so far - loop over all cores and establish the real absolute path for given osConfigFiles
      for core in genCfg[self.GENCFG_DICT_KEY_CORES]:
        # Check whether we have an OS at all
        if self.OS_TYPE_NONE != inputCfg[self.INPUT_DICT_KEY_OS_TYPE]:
          # Remove leading and trailing whiteSpaces and leading slashes and back slashes
          core[self.OS_CFG_FILE] = core[self.OS_CFG_FILE].strip(' ')
          core[self.OS_CFG_FILE] = core[self.OS_CFG_FILE].lstrip('/')
          core[self.OS_CFG_FILE] = core[self.OS_CFG_FILE].lstrip('\\')
          
          # Check whether there is a file given
          if len(core[self.OS_CFG_FILE]):  
            # Replace PROJECT_REPLACE_PATTERN and OS_PATH_REPLACE_PATTERN if there are some in given path
            core[self.OS_CFG_FILE] = core[self.OS_CFG_FILE].replace(self.PROJECT_REPLACE_PATTERN, inputCfg[self.INPUT_DICT_KEY_PROJECT])
            core[self.OS_CFG_FILE] = core[self.OS_CFG_FILE].replace(self.OS_PATH_REPLACE_PATTERN, inputCfg[self.INPUT_DICT_KEY_OS_DIR_PATH])
            inputInfo += '- {0}\n'.format(core[self.OS_CFG_FILE])
  
            if not os.path.isfile(core[self.OS_CFG_FILE]):
              errorCode = self.ERR_OS_CFG_FILE_NOT_FOUND
              errorMsg.append(self.INFO_TEXT_GEN_CFG_OS_FILE_MISSING.format(core[self.OS_CFG_FILE]))
          
    if self.ERR_OK == errorCode:
      inputInfo += '\n\nThe following datFiles are used:\n'
      # In case no datFile is provided genCfg[self.GENCFG_DICT_KEY_DAT_FILES] is None
      # Note: For easy debugging it might be the case that no datFile is delivered
      if genCfg[self.GENCFG_DICT_KEY_DAT_FILES]:
        datFilesWithRealPaths = []
        # Everything OK so far - loop over all datFiles and establish the real absolute path 
        for datFile in genCfg[self.GENCFG_DICT_KEY_DAT_FILES]:
          # Remove leading and trailing whiteSpaces and leading slashes and back slashes
          datFile = datFile.strip(' ')
          datFile = datFile.lstrip('/')
          datFile = datFile.lstrip('\\')
          
          # Replace PROJECT_REPLACE_PATTERN and PDO_PATH_REPLACE_PATTERN if there are some in given path
          datFile = datFile.replace(self.PROJECT_REPLACE_PATTERN, inputCfg[self.INPUT_DICT_KEY_PROJECT])
          datFile = datFile.replace(self.PDO_PATH_REPLACE_PATTERN, inputCfg[self.INPUT_DICT_KEY_PDO_PATH])
          
          datFilesWithRealPaths.append(datFile)
          inputInfo += '- {0}\n'.format(datFile)
          
          if not os.path.isfile(datFile):
            errorCode = self.ERR_DAT_FILE_NOT_FOUND
            errorMsg.append(self.INFO_TEXT_GEN_CFG_DAT_FILE_MISSING.format(datFile))
        
        #Delete entries from origin datFileList and put the datFiles with real paths to it
        del genCfg[self.GENCFG_DICT_KEY_DAT_FILES][:]
        genCfg[self.GENCFG_DICT_KEY_DAT_FILES].extend(datFilesWithRealPaths)
        
    # Provide additional information to caller in case genCfgFile is invalid 
    if self.ERR_GENERATOR_CFG_FILE_INVALID == errorCode:
      #GeneratorConfigurationFile is invalid. Get the location of the example configuration file
      exampleLocation = os.path.dirname(os.path.abspath(__file__)) + '/ConfigurationTemplate'
      errorMsg.append(self.INFO_TEXT_CFG_FILE_EXAMPLE.format(exampleLocation))
          

    #Provide errorMessage to caller
    errorInfo.extend(errorMsg)
      
    logLines.extend(inputInfo)
    print(inputInfo)
      
    return errorCode

  #############################################################################################################################################################################
  def copyBarCharts(self, genCfg, outputPath):

    barChartXmls = []
    #Find all required barChartXmls
    for core in genCfg[self.GENCFG_DICT_KEY_CORES]:
      requiredXml = core[self.BARCHART_XML].strip()
      if len(requiredXml) != 0:
        #check if it is already in the list
        notInList = True
        for xmlFile in barChartXmls:
          if xmlFile == requiredXml:
            #The required XML is already in the list
            notInList = False
            break

        if notInList:
          #add the currently required file to the list
          barChartXmls.append(requiredXml)

    #Copy all required barChartXmls
    for xmlFile in barChartXmls:
      #Get file including full path
      fileToCopy = '{0}/BarChartXmls/{1}'.format(os.path.dirname(os.path.abspath(__file__)),xmlFile)
      #Copy the file in case it exists
      if os.path.isfile(fileToCopy):
        #Remove writeProtection of destinationFile in case this already exists
        destFile = '{0}/{1}'.format(outputPath, xmlFile)
        if os.path.isfile(destFile):
          st_mode = os.stat(destFile).st_mode | stat.S_IWRITE | stat.S_IREAD
          os.chmod(destFile, st_mode)
        #Copy the barChart-XML
        copy(fileToCopy, outputPath)

RtaXmlGenerator()
