import os
import sys
import re

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + '/../ToolChainCommon')
from ChainCommon import ChainCommon
from XmlGenerationUtils import XmlGenerationUtils

#################################################################################
# All the common stuff used in the classes of the rtaXmlGenerator
#################################################################################

class GeneratorCommon(ChainCommon, XmlGenerationUtils):

  #The indexes of the entries in 'CORES' in the generatorConfigurationFiles (RtaXmlGeneratorCfg.yaml)
  CORE_NAME              =  0
  CORE_ID                =  1
  OS_CFG_FILE            =  2
  OS_CORE_ID             =  3
  ISR_RANGE_START        =  4
  ISR_RANGE_END          =  5
  GROUP_NAME             =  6
  WAKEUP_COMP            =  7
  WAKEUP_MARKER          =  8
  BARCHART_XML           =  9
  IGNOR_LOCAL_ID_STRINGS = 10
  NO_OF_PARAMETERS_IN_CORE_DESCRIPTOR = IGNOR_LOCAL_ID_STRINGS + 1


  #All keys used in the generator configuration dictionary which is loaded from the generatorCfgFile (e.g.RtaXmlGeneratorCfg.yaml)
  GENCFG_DICT_KEY_CORES               = 'CORES'
  GENCFG_DICT_KEY_DAT_FILES           = 'DAT_FILES'
  GENCFG_DICT_KEY_OUTPUT_PATH         = 'OUTPUT_PATH'
  GENCFG_DICT_KEY_GEN_GLOBALID        = 'GENERATE_GLOBALID_FEAT'
  GENCFG_DICT_KEY_ISR_XML_INPUT_FILES = 'ISR_XML_INPUT_FILES'
  GENCFG_DICT_KEY_ISR_XML_OFFSET      = 'ISR_XML_OFFSET'
  GENCFG_DICT_KEY_ISR_XML_ADD_ISR     = 'ISR_XML_ADD_ISR'
  
  GENCFG_DICT_KEY_ISR_XML_ADD_ISR_NAME  = 'ADD_ISR_NAME' 
  GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE = 'ADD_ISR_VALUE'


  #Indexes used for the taskList which is provided by the function getTaskList
  IDX_TASKLIST_OS_TASK_ID  = 0
  IDX_TASKLIST_RTA_TASK_ID = 1
  IDX_TASKLIST_OS_CORE_ID  = 2

  # The title for the messageBoxes
  MsgBoxTitle = 'RtaXmlGenerator'

  #The project replace pattern - will be replaced by real project name
  PROJECT_REPLACE_PATTERN        = '<___project___>'
  OS_PATH_REPLACE_PATTERN        = '<___OsPath___>'
  PDO_PATH_REPLACE_PATTERN       = '<___pdoPath___>'
  
  
  #The errorCodes
  ERR_OK                                    =  0
  ERR_GENERATOR_CFG_FILE_NOT_FOUND          =  1
  ERR_DAT_FILE_NOT_FOUND                    =  2
  ERR_OS_CFG_FILE_NOT_FOUND                 =  3
  ERR_RTA_TASK_IDS_HEADER_NOT_FOUND         =  4
  ERR_RTA_TASK_ID_LUT_CFG_FILE_NOT_FOUND    =  5
  ERR_RTA_TASK_ID_NOT_FOUND                 =  6
  ERR_GLOB_COMP_ID_HEADER_NOT_FOUND         =  7
  ERR_ISR_ID_OVERLAP                        =  8
  ERR_ISR_IDS_OUT_OF_RANGE                  =  9
  ERR_GENERATOR_CFG_FILE_INVALID            = 10
  ERR_INPUT_CFG_FILE_MISSING                = 11
  ERR_INPUT_CFG_FILE_ERROR                  = 12
  ERR_REFERENCE_PATH_INVALID                = 13
  ERR_NUMBER_OF_TASKS_OUT_OF_RANGE          = 14
  
  #The error Messages Dictionary
  errorMsgDict = \
  {
    ERR_GENERATOR_CFG_FILE_NOT_FOUND        : 'RtaXmlGeneratorCfg.py could not be found!\n\n',
    ERR_DAT_FILE_NOT_FOUND                  : 'At least one datFile provided in RtaXmlGeneratorCfg.py could not be found, check if the paths are ok and if the files really exist.',
    ERR_OS_CFG_FILE_NOT_FOUND               : 'At least one osConfigFile provided in RtaXmlGeneratorCfg.py could not be found, check if the paths are ok and if the files really exist.',
    ERR_RTA_TASK_IDS_HEADER_NOT_FOUND       : 'os_rta_task_ids.h could not be found!\n',
    ERR_RTA_TASK_ID_LUT_CFG_FILE_NOT_FOUND  : '{} could not be found!\n'.format(ChainCommon.TASK_LUT_FILE_NAME),
    ERR_RTA_TASK_ID_NOT_FOUND               : '{} contains a taskID which is not present in os_rta_task_ids.h. Please ensure that both files are up to date, run the tresosGeneration of the os again - if needed.'.format(ChainCommon.TASK_LUT_FILE_NAME),
    ERR_GLOB_COMP_ID_HEADER_NOT_FOUND       : 'rta_globalids.h could not be found!\n ',
    ERR_ISR_ID_OVERLAP                      : 'We have overlapping ISR-IDs. Please rearrange the ISR-offsets in the RTA_Cfg.h files and in RtaXmlGeneratorCfg.py as well! \n' ,
    ERR_ISR_IDS_OUT_OF_RANGE                : 'ISR-IDs out of range (255)Either it can be solved in rearranging the ISR-offsets in the RTA_Cfg.h files and in RtaXmlGeneratorCfg.py as well or we simply have too many interrupts! \n' ,
    ERR_GENERATOR_CFG_FILE_INVALID          : 'RtaXmlGeneratorCfg.yaml has an invalid format!',
    ERR_INPUT_CFG_FILE_MISSING              : 'InputCfgFile is missing. The InputCfgFile shall provide all information regarding needed files and folders',
    ERR_INPUT_CFG_FILE_ERROR                : 'There is any problem regarding the inputCfgFile (Invalid format, given path or file not available, ...)',
    ERR_REFERENCE_PATH_INVALID              : 'Reference path is invalid',
    ERR_NUMBER_OF_TASKS_OUT_OF_RANGE        : 'Too many tasks in the project - one RteGlobalID needed per task and the range for RteGlobalIDs is from 4000 - 4094',
  }

  #The ISR_Id_Range (8 bit)
  ISR_ID_RANGE = 255

  #Initialize the class################################################################################################################################################################################
  def __init__(self):
    print ('common')


  ###########################################################################################################################################################
  #Extract the taskIDLut from the file taskIDLut_h #####################################################################################################
  def getTaskList(self, taskList, taskIDLut_h):

    #Read all lines of the file taskIDLut_h
    inputFile = open(taskIDLut_h)
    lines = inputFile.readlines()
    inputFile.close()

    inRegionOfInterrest = False

    for line in lines:
      if not inRegionOfInterrest:
        if -1 != line.find(self.GEN_TAG_AUX_TASK_LIST_START):
          #Now we reached the beginning of the interesting section within this file
          inRegionOfInterrest = True
      else:
        PATTERN_TASK_LITERAL = r' *(\S+) *, *(OS_RTA_TASKID_\S+) *, *(\S+)' # group(1) is osTaskID, group (2) is rtaTaskID, group(3) is coreID
        obj = re.match(PATTERN_TASK_LITERAL, line)
        if obj:
          #append it to the list
          taskList.append([obj.group(1), obj.group(2), obj.group(3)])
        #check whether we reached the end of interesting section within this file
        elif -1 != line.find(self.GEN_TAG_AUX_TASK_LIST_END):
          break


  #Find that XML-file which matches best to given globalID#######################################################################################################
  def findXmlFileMatchingToGlobalID(self, XMLs, globalID):
    xmlFile = ''
  
    #First try to find a xml which matches completely only the suffix (_LocalIDs.xml, _ErrorIDs.xml) shall not be considered 
    for entry in XMLs:
      #Get the name of the next localIdXml-file normated to capital letters (to make the mapping case insensitive)
      fileName = entry[0].upper()
      if globalID == fileName[:fileName.rfind('_')]:
        #combine path and fileName of localID-file
        xmlFile = os.path.join(entry[1], entry[0])
        break

    if not len(xmlFile) and globalID.startswith('SW_'):
      # localID-xml not found yet but the globalID starts with "SW_" which can be ignored
      for entry in XMLs:
        fileName = entry[0].upper()
        if globalID[len('SW_'):] == fileName[:fileName.rfind('_')]:
          #combine path and fileName of localID-file
          xmlFile = os.path.join(entry[1], entry[0])
          break

    if not len(xmlFile) and (-1 != globalID.find('_')):
      # LocalID-xml not found yet but we have a globalID with at least one underscore, it could be a globalID like SR_A or IPC_RX
      #Look for a localID.xml which has a name which partly matches with the name of the globalID eg: SR_A -> SR or IPC_RX -> IPC
      for entry in XMLs:
        fileName = entry[0].upper()
        fileName = fileName[:fileName.rfind('_')]

        currentGlobalID = globalID

        for index in range(currentGlobalID.count('_')):  # @UnusedVariable
          #Remove the part after the last underscore including the underscore itself
          currentGlobalID = currentGlobalID[:currentGlobalID.rfind('_')]

          if currentGlobalID == fileName:
            #OK - the fileName of current xlm machtes with the first part of globalID-Name!
            #combine path and fileName of localID-file
            xmlFile = os.path.join(entry[1], entry[0])
            break

        if len(xmlFile):
          #LocalID xml found - terminate outher loop
          break

    return xmlFile


  #Generate a list of all interresting localID.xml- and errorID.xml-Files, including their relativ pathes######################################################################
  def getAllXmlFilesOfInterrest(self, outputPath, localIdXMLs, errorIdXMLs, internErrorIdXMLs):
    
    for root, dirs, files in os.walk(outputPath):  # @UnusedVariable
      for name in files:
        if name.endswith(self.XML_NAME_SUFFIXES[self.LOCAL_ID_XML]):
          listToExtend = localIdXMLs
        elif name.endswith(self.XML_NAME_SUFFIXES[self.ERROR_ID_XML]):
          listToExtend = errorIdXMLs
        elif name.endswith(self.XML_NAME_SUFFIXES[self.INTERN_ERROR_ID_XML]):
          listToExtend = internErrorIdXMLs
        else: 
          listToExtend = None
          
        if None != listToExtend: 
          path = ''
          if root != outputPath:
            path = root[len(outputPath):]
            path = '..' + path
          listToExtend.append([name, path])
        


