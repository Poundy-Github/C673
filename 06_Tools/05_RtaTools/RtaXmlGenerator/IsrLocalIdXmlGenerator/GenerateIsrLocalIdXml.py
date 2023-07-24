import os
import stat
import sys
import argparse
import re

try:
# python 2
  import tkMessageBox as tkinter_messagebox
except ImportError:
# python 3
  import tkinter.messagebox as tkinter_messagebox
from datetime import datetime

sys.path.append(os.path.join(sys.path[0],'../'))
sys.path.append(os.path.join(sys.path[0],'../../ToolChainCommon'))

from GeneratorCommon          import GeneratorCommon



#################################################################################
# The IsrLocalIdXmlGenerator
#################################################################################
class IsrLocalIdXmlGenerator(GeneratorCommon):
  ''' This generator generates the localIdXml based on the interrupts defined given files.
      Currently it is written for the c6xx from TI. Additionally to the interrupts from the inputFile the 
      user can add further interrupts in the generatorConfigFile.   
  '''

  INFO_TEXT_GENERATOR_CFG_FILE_NOT_FOUND = '''Given generatorConfigurationFile could not be found:
  
{}
  
'''
    
  INFO_TEXT_INPUT_REF_PATH_INVALID = '''Provided inputRefPath is invalid: 
{0}''' 
  
  INFO_TEXT_GEN_CFG_FILE_NO_DICT = 'The data contained in the generatorConfiguratonFile is not provided as a dictionary.\n'

  INFO_TEXT_GEN_CFG_FILE_KEY_MISSING = 'The key "{0}" is missing in the generatorConfiguratonFile.\n'
  
  
  INFO_TEXT_GEN_CFG_FILE_KEY_MISSING_IN_ADD_ISR_ENTRY = '''The key "{0}" in additionalInterruptEntry "{1}" is missing in the generatorConfiguratonFile.
''' # 0: key, 1: index of additional interrupt entry 

  INFO_TEXT_GEN_CFG_ADD_ISR_ENTRY_NO_INT = ''' {0} of additionalInterruptEntry "{1}" in the generatorConfiguratonFile is not an integer.
  It has to be an integer in the range 0 ... {2} and it must NOT overlap with other predefined interrupt IDs given in the inputFiles.   
''' # 0: self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE, 1: index of given entry, 2 localIdRange (= globalID range)

  INFO_TEXT_GEN_CFG_ADD_ISR_ENTRY_VALUE_OUT_OF_RANGE = '''The value given as {0} of additionalInterruptEntry "{1}" in the generatorConfiguratonFile is out of range.
  It has to be an integer in the range 0 ... {2} and it must NOT overlap with other predefined interrupt IDs given in the inputFiles.
'''
 
  INFO_TEXT_GEN_CFG_ADD_ISR_ENTRY_DOUBLE_NAME = '''In the list of additional interrupts we have the name "{0}" at least twice. 
The names of additional interrupts IDs MUST be unique!
''' # The name of the additional interrupt which appears more than once. 
  
  INFO_TEXT_GEN_CFG_ADD_ISR_ENTRY_DOUBLE_VALUE = '''In the list of additional interrupts we have the value "{0}" at least twice. 
The values of additional interrupts IDs MUST be unique!
''' # The name of the additional interrupt which appears more than once. 
  
  INFO_TEXT_INTERRUPT_IDS_DOUBLE_NAME = '''We have two or more interrupts with the same name: "{0}". 
The names of interrupts IDs MUST be unique!
Most probably this name is used in the inputFile and also in the additionalInterrupts given in the generatorCfgFile:
{1}
''' # The name of the additional interrupt which appears more than once. 
  
  INFO_TEXT_INTERRUPT_IDS_DOUBLE_VALUE = '''We have two or more interrupts with the same value: "{0}". 
The values of additional interrupts IDs MUST be unique!
Most probably this value is used in the inputFile and also in the additionalInterrupts given in the generatorCfgFile:
{1}
''' # The name of the additional interrupt which appears more than once. 
  
  
   
  INFO_TEXT_GEN_CFG_FILE_ADD_ISR_ENTRY_NO_DICT = '''The additionalInterruptEntry "{0}" in the generatorConfiguratonFile is not a dictionary. 
'''  
  
  INFO_TEXT_GEN_CFG_FILE_NO_INPUT_FILE = '''There is no inputFile given! At least one file is required in which the interrupt definitions can be found. 
'''
  INFO_TEXT_GEN_CFG_INPUT_HEADER_FILE_MISSING = '''The following input header file mentioned in the gerneratorConfigurationFile is missing:
{0}
''' # The missing file
  
  INFO_TEXT_GEN_CFG_ISR_XML_OFFSET_NO_INT = '''The {0} in the gerneratorConfigurationFile is not an integer! 
  It has to be an integer in the range of 0 ... {1} and it has to match with the rtaConfiguration of this buildUnit
''' # 0: self.GENCFG_DICT_KEY_ISR_XML_OFFSET, 1: self.GLOBAL_ID_MAX_VALUE

  INFO_TEXT_GEN_CFG_ISR_XML_OFFSET_OUT_OF_RANGE = '''The {0} in the gerneratorConfigurationFile is out of range! 
  It has to be an integer in the range of 0 ... {1} and it has to match with the rtaConfiguration of this buildUnit
''' # 0: self.GENCFG_DICT_KEY_ISR_XML_OFFSET, 1: self.GLOBAL_ID_MAX_VALUE


  #Initialize RtaXmlGenerator class
  def __init__(self):
    self.logLines = list()

    # Get provided arguments 
    self.args = self.check_args()

    try:
      if not os.path.exists(self.args.outputPath):
        # Given output path does not exist - generate it
        os.makedirs(self.args.outputPath, exist_ok=True)

      if not os.path.isfile(self.args.generatorCfgFile):
        # GeneratorConfigFile is not available 
        raise Exception(self.INFO_TEXT_GENERATOR_CFG_FILE_NOT_FOUND.format(self.args.generatorCfgFile))

      # Check validity of pdoRefPath
      if not os.path.exists(self.args.inputRefPath):
        raise Exception(self.INFO_TEXT_INPUT_REF_PATH_INVALID.format(self.args.inputRefPath))
        
      # Load the generatorCfgFile and check it  
      self.generatorCfg = self.load_yaml(self.args.generatorCfgFile)
      self.checkGeneratorCfgFileAndConvertToAbsPaths(self.generatorCfg, self.args.inputRefPath)

      # Have the IsrLocalIdXml-File generated
      self.doIt()


      # Prepare the text for the logFile
      infoTxt ='''The IsrLocalIdXML-file has been generated successfully to that directory:
{0}
'''.format(self.args.outputPath)
      
      self.logLines.append('\n\n')
      self.logLines.extend(infoTxt)
      if self.args.gui:
        #generate messageBox
        tkinter_messagebox.showinfo(self.MsgBoxTitle, infoTxt)

    except Exception as ex:
      # Some error occurred 
      print(ex)

      #Prepare the text for the logFile
      self.logLines.append('The following error occurred during generator run: \n\n')
      self.logLines.extend(str(ex))

      if self.args.gui:
        tkinter_messagebox.showerror(self.MsgBoxTitle, str(ex)) 

    finally:
      # Create the logFile finally
      self.createLogFile(self.logLines, self.args.outputPath)


  #This is the main function calling all other generators ###################################################################################
  def doIt(self):
    
    nameAndValueList = list()
    localIdList      = list()
    nameList         = list()
    valueList        = list()
    
    searchConditions = {
      'searchStr'      : r' *#define +CSL_DSS_INTR_([\S]+) +([\d]+)',
      'numberOfGroups' : 2
    }
    
    # Get all interruptIds of all given files 
    for inputFile in self.generatorCfg[self.GENCFG_DICT_KEY_ISR_XML_INPUT_FILES]:
      nameAndValueList.extend(self.getElementsFromMatchingLines(inputFile, searchConditions))
    
    # Add additional events given in the generatorConfig if there  are some
    if self.generatorCfg[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR]:
      for entry in self.generatorCfg[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR]:
        nameAndValueList.append([entry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_NAME], entry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE]])
      
    # Check for double names and values in the idList
    for entry in nameAndValueList: 
      nameList.append(entry[0])
      valueList.append(str(entry[1]))
      
    for name in nameList:
      if 1 < nameList.count(name):
        raise Exception(self.INFO_TEXT_INTERRUPT_IDS_DOUBLE_NAME.format(name, self.args.generatorCfgFile))
      
    for value in valueList:
      if 1 < valueList.count(value):
        raise Exception(self.INFO_TEXT_INTERRUPT_IDS_DOUBLE_VALUE.format(value, self.args.generatorCfgFile))
        
    # Fill a list of dictionaries required for the function generateLocalIdXmlFile
    # Value: Add the offset to value, convert it to string and fill it into the dictionary
    for entry in nameAndValueList:
      localIdDict = dict()
      # Fill the dictionary and append it to the final list  
      localIdDict[self.LOCAL_ID_LIST_KEY_NAME              ] = entry[0]
      localIdDict[self.LOCAL_ID_LIST_KEY_VALUE             ] = str(int(entry[1]) + self.generatorCfg[self.GENCFG_DICT_KEY_ISR_XML_OFFSET])
      localIdDict[self.LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE] = False
      localIdDict[self.LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP   ] = False
      
      localIdList.append(localIdDict) 
    
    xmlFile = os.path.join(self.args.outputPath, self.FILE_NAME_ISR_LOCAL_ID_XML)
    
    # Have the localIdXmlFile generated 
    self.generateLocalIdXmlFile(localIdList, xmlFile)
    
  
  ##################################################################################################################
  def getElementsFromMatchingLines(self, file, searchConditions):
    idList = list()
    
    lines = self.getLinesOfFile(file)
    
    for line in lines:
      obj = re.match(searchConditions['searchStr'], line)
      if obj:
        # OK, this is a matching line - get all relevant parts (groups) of this line
        groupList = list()
        index = 0
        # Collect all groups in groupList
        for index in range(1, searchConditions['numberOfGroups']+1):
          groupList.append(obj.group(index))
        
        # Finally add it to the idList
        idList.append(groupList)
    
    return idList

# argument parsing ############################################################################
  def check_args(self):
    parser = argparse.ArgumentParser(prog='IsrLocalIdXmlGenerator',
                                     formatter_class=argparse.RawTextHelpFormatter,
                                     description = 'Generates the IsrLocalID XML file based on given input header files')
    parser.add_argument('project',
                        action = 'store',
                        help ='The name of the project.')
    
    parser.add_argument('build_unit',
                        action ='store',
                        help = 'The name of the buildUnit')

    parser.add_argument('generatorCfgFile',
                        action = 'store',
                        help ='The generator configuration file in which all relevant input header files have to be provided.')
    
    parser.add_argument('outputPath',
                        action ='store',
                        help = '''This argument has to provide the path where the generated XML file shall be stored to. ''')

    parser.add_argument('inputRefPath',
                        action ='store',
                        help = '''This argument has to provide the input reference path which is used as a basePath 
for given input header files  in the generator configuration file. ''')

    parser.add_argument('-g', '--gui',
                        action ='store_true',
                        default = False,
                        help = 'enables/disables configuration GUI')
    return parser.parse_args()

  #########################################################################################################################################################
  def createLogFile(self, logLines, logPath):

    #Establish the headerLines of the file
    linesToWrite = []
    linesToWrite.append('\n' * 2)
    #Add headerLine
    linesToWrite.append('LogFile of the interrupt LocalIdXml generator')
    #Add new lines
    linesToWrite.append('\n' * 2)
    #ProjectInfo and date
    linesToWrite.append('Date:      {}\n'.format(datetime.now().strftime('%d.%m.%Y %H:%M:%S')))
    #Add new lines
    linesToWrite.append('\n' * 2)

    #Add lines provided as argument
    linesToWrite.extend(logLines)


    if not os.path.isdir(logPath):
      #generate the logFile to defaultLocation
      logPath = self.getDefaultLocationForLogFile()

    #check if file exists
    logFile = logPath + '/RtaIsrLocalIdGenerator.log'
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
  def checkGeneratorCfgFileAndConvertToAbsPaths(self, genCfg, inputRefPath):
    '''This function does 
       - a format check of given generatorCfg file
       - for all given datFiles it establishes the absolute paths and checks whether theses files are available
    '''

    inputInfo = ''
    index = 0

    keyList = [self.GENCFG_DICT_KEY_ISR_XML_INPUT_FILES,
               self.GENCFG_DICT_KEY_ISR_XML_OFFSET     ,
               self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR    ,
              ]
    
    keyListAddIsr = [ self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_NAME ,
                      self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE, 
                    ]
    
    # Do a formatCheck (is dictionary, are all required keys available) 
    if not isinstance(genCfg, dict):
      #Data provided in generatorCfgFile is not stored as a dictionary!
      raise Exception(self.INFO_TEXT_GEN_CFG_FILE_NO_DICT)

    for key in keyList:
      # Check whether generatorConfigFile has all required keys
      if not key in genCfg:
        raise Exception(self.INFO_TEXT_GEN_CFG_FILE_KEY_MISSING.format(key))

    # Check whether there is at least one interrupt input file given 
    if not genCfg[self.GENCFG_DICT_KEY_ISR_XML_INPUT_FILES]:
      raise Exception(self.INFO_TEXT_GEN_CFG_FILE_NO_INPUT_FILE)
      
    inputInfo += 'The following inputHeaderFiles are used:\n'

    for index in range(len(genCfg[self.GENCFG_DICT_KEY_ISR_XML_INPUT_FILES])):
      # Remove leading and trailing whiteSpaces and leading slashes and back slashes
      inputFile = genCfg[self.GENCFG_DICT_KEY_ISR_XML_INPUT_FILES][index]

      inputFile = inputFile.strip(' ')
      inputFile = inputFile.lstrip('/')
      inputFile = inputFile.lstrip('\\')
        
      # Establish the absolutePath of the inputFile using the inputRefPath in case the inputFile is not given as an absPath 
      inputFile = self.getAbsolutePath(inputRefPath, inputFile)
        
      inputInfo += '- {0}\n'.format(inputFile)
      
      if not os.path.isfile(inputFile):
        raise Exception(self.INFO_TEXT_GEN_CFG_INPUT_HEADER_FILE_MISSING.format(inputFile))
      else: 
        #Update fileEntry in genCfg with absolute path
        genCfg[self.GENCFG_DICT_KEY_ISR_XML_INPUT_FILES][index] = inputFile
      
    if not isinstance(genCfg[self.GENCFG_DICT_KEY_ISR_XML_OFFSET], int):
      # Given IsrXmlOffset is not an integer! 
      raise Exception(self.INFO_TEXT_GEN_CFG_ISR_XML_OFFSET_NO_INT.format(self.GENCFG_DICT_KEY_ISR_XML_OFFSET, self.GLOBAL_ID_MAX_VALUE))
    
    if(   (0                        > genCfg[self.GENCFG_DICT_KEY_ISR_XML_OFFSET])
       or (self.GLOBAL_ID_MAX_VALUE < genCfg[self.GENCFG_DICT_KEY_ISR_XML_OFFSET])
      ):
      # Given IsrXmlOffset is out of range  
      raise Exception(self.INFO_TEXT_GEN_CFG_ISR_XML_OFFSET_OUT_OF_RANGE.format(self.GENCFG_DICT_KEY_ISR_XML_OFFSET, self.GLOBAL_ID_MAX_VALUE))

    if not genCfg[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR]:
      inputInfo += '''
No additional interrupt IDs are given.
'''
    else:
      nameList  = list()
      valueList = list()
      inputInfo += '''
There are the following additional interrupt IDs are given: 
'''
      for index in range(len(genCfg[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR])):
        # Check whether this additional interrupt entry is a dictionary 
        if not isinstance(genCfg[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR][index], dict):
          raise Exception(self.INFO_TEXT_GEN_CFG_FILE_ADD_ISR_ENTRY_NO_DICT.format(index))
           
        # Check whether there are all required keys given for this additional interrupt entry 
        for key in keyListAddIsr: 
          if not key in genCfg[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR][index]:
            raise Exception(self.INFO_TEXT_GEN_CFG_FILE_KEY_MISSING_IN_ADD_ISR_ENTRY.format(key, index))


      for index in range(len(genCfg[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR])):
        addIsrEntry = genCfg[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR][index]
        if not isinstance(addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE], int):
          # Value in current addIsrEntry is not an integer
          raise Exception(self.INFO_TEXT_GEN_CFG_ADD_ISR_ENTRY_NO_INT.format(self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE, index, self.GLOBAL_ID_MAX_VALUE))
        
        if(   (0                        > addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE])
           or (self.GLOBAL_ID_MAX_VALUE < addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE])
          ):
          # Given IsrXmlOffset is out of range  
          raise Exception(self.INFO_TEXT_GEN_CFG_ADD_ISR_ENTRY_VALUE_OUT_OF_RANGE.format(self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE, index, self.GLOBAL_ID_MAX_VALUE))
        
        # Remove whiteSpaces from the name
        addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_NAME] = addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_NAME].replace(' ', '')
        
        inputInfo += '- {0}: {1}\n'.format(addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_NAME], addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE])

        nameList.append(addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_NAME])
        valueList.append(addIsrEntry[self.GENCFG_DICT_KEY_ISR_XML_ADD_ISR_VALUE])
      
      # Check for double names in additional interrupt IDs
      for name in nameList:
        if 1 < nameList.count(name):
          raise Exception(self.INFO_TEXT_GEN_CFG_ADD_ISR_ENTRY_DOUBLE_NAME.format(name))
        
      # Check for double values in additional interrupt IDs
      for value in valueList:
        if 1 < valueList.count(value):
          raise Exception(self.INFO_TEXT_GEN_CFG_ADD_ISR_ENTRY_DOUBLE_VALUE.format(value))
        
    self.logLines.extend(inputInfo)
    print(inputInfo)


IsrLocalIdXmlGenerator()
