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

sys.path.append(os.path.join(sys.path[0],'../'))
sys.path.append(os.path.join(sys.path[0],'../../ToolChainCommon'))

from GeneratorCommon          import GeneratorCommon
from GenerateLocalIdXmls      import LocalIdXmlGenerator



#################################################################################
# The RtaLocalIdXmlOnlyGenerator
#################################################################################
class RtaLocalIdXmlOnlyGenerator(GeneratorCommon):
  ''' This generator is intended to be used by the components to generate their related XML-files based on the 
      datFile(s) of the component(like requested by the camera algorithms. In dependency of the content of  given datFile(s) 
      the following XML file types will be generated:
      - LocalId XML files 
      - ErrorId XML files
      - InternalErrorId XML files 
      - the ErrOffsets XML file (There must be only one ErrOffset in the project!) 
  '''

  INFO_TEXT_GENERATOR_CFG_FILE_NOT_FOUND = '''Given generatorConfigurationFile could not be found:
  
{}
  
'''
    
  INFO_TEXT_PDO_REF_PATH_INVALID = '''Provided pdoRefPath is invalid: 
{0}''' 
  
  INFO_TEXT_GEN_CFG_FILE_NO_DICT = 'The data contained in the generatorConfiguratonFile is not provided as a dictionary.\n'
  
  INFO_TEXT_GEN_CFG_FILE_KEY_MISSING = 'The key "{0}" is missing in the generatorConfiguratonFile.\n'

  INFO_TEXT_NO_DAT_FILE_PROVIDED = '''No datFile provided in the generatorConfiguratonFile! 
At least one datFile is required from which the localIdXml files shall be generated from! 
'''
  INFO_TEXT_GEN_CFG_DAT_FILE_NOT_AVAILABLE = '''The datFile "{0}" is not available.  
There are 2 possibilities: 
1) The dat-File is given with its absolutePath in the generatorCfgFile
2) The dat-File is given with a relative path in the generatorCfgFile. In this case the argument "pdoRefPath" is required at 
   generatorCall which is then used to establish the absolutePath of the datFile.   
Please check the generatorCfgFile"{1}" and maybe also the argument "pdoRefPath".
'''
  INFO_TEXT_OUTPUT_PATH_IS_NOT_ABSOLUT = '''OutputPath is not absolute! Either provide an absolute outputPath in the generatorCfgFile or 
provide an outputRefPath as argument which will be used then to establish an absolute path together with the relative outputPath  
given in the generatorCfgFile: 
'''
  
  #Initialize RtaXmlGenerator class
  def __init__(self):

    #Create objects of all needed generators
    self.localIdGen = LocalIdXmlGenerator()

    self.doIt()

# argument parsing ############################################################################
  def check_args(self):
    parser = argparse.ArgumentParser(prog='GenerateLocalIdXmlsOnly',
                                     formatter_class=argparse.RawTextHelpFormatter,
                                     description = 'Generate local ID XML files, errorID XML files, intern errorID XML files and errorOffsetID XML files from given dat-file(s). ')
    parser.add_argument('generatorCfgFile',
                        action = 'store',
                        help ='The generator configuration file in which all relevant datFiles have to be provided.')
    
    parser.add_argument('-p', '--pdoRefPath',
                        action ='store',
                        help = '''This argument has to provide the base path where the datFiles can be found.
This referencePath is used to establish an absolute path together with the "pdo_path" given in the corresponding RtaXmlGenerator_InputCfg*.yaml''')

    parser.add_argument('-o', '--outputRefPath',
                        action ='store',
                        help = '''This argument has to provide the path where the generated XML files shall be stored to. ''')

    parser.add_argument('-g', '--gui',
                        action ='store_true',
                        default = False,
                        help = 'enables/disables configuration GUI')
    return parser.parse_args()

  #This is the main function calling all other generators ###################################################################################
  def doIt(self):
    logLines     = list()
    inputCfg     = dict()

    # Get provided arguments 
    self.args = self.check_args()

    try:
      logLines.append('The following generatorCfgFile is used:\n  {0}\n'.format(self.args.generatorCfgFile))
      
      if not os.path.isfile(self.args.generatorCfgFile):
        # GeneratorConfigFile is not available 
        raise Exception(self.INFO_TEXT_GENERATOR_CFG_FILE_NOT_FOUND.format(self.args.generatorCfgFile))

      # Check validity of pdoRefPath
      if self.args.pdoRefPath:
        logLines.append('The following pdoRefPath is given as argument:\n  {0} \n'.format(self.args.pdoRefPath))
        
        if not os.path.exists(self.args.pdoRefPath):
          raise Exception(self.INFO_TEXT_PDO_REF_PATH_INVALID.format(self.args.pdoRefPath))
      else:
        logLines.append('No pdoRefPath is given as argument\n')
        
      # provide the information regarding the outputRefPath
      if self.args.outputRefPath:
        logLines.append('The following outputRefPath is given as argument:\n  {0} \n'.format(self.args.outputRefPath))
      else:
        logLines.append('No outputRefPath is given as argument\n')

      # Load the generatorCfgFile and check it  
      generatorCfg = self.load_yaml(self.args.generatorCfgFile)
      self.checkGeneratorCfgFileAndConvertToAbsPaths(generatorCfg, logLines)

      #Set outputPath in the inputCfg - the inputCfg is required by the LocalIdXmlGenerator
      inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH] = generatorCfg[self.GENCFG_DICT_KEY_OUTPUT_PATH]
      
      for line in logLines:
        print (line)
        
      # Have the localIdXml-Files generated
      print ('Call the LocalIdXmlGenerator')
      self.localIdGen.doIt(generatorCfg, inputCfg)

      # Prepare the text for the logFile
      infoTxt ='''The localIdXML-files have been generated successfully to that directory:
      
{0}
'''.format(inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH])
      
      logLines.append('\n\n')
      logLines.extend(infoTxt)
      if self.args.gui:
        #generate messageBox
        tkinter_messagebox.showinfo(self.MsgBoxTitle, infoTxt)

    except Exception as ex:
      # Some error occurred 
      print(ex)

      #Prepare the text for the logFile
      logLines.append('The following error occurred during generator run: \n\n')
      logLines.extend(str(ex))

      if self.args.gui:
        tkinter_messagebox.showerror(self.MsgBoxTitle, str(ex)) 

    finally:
      # Create the logFile finally
      self.createLogFile(logLines, generatorCfg[self.GENCFG_DICT_KEY_OUTPUT_PATH])


  #########################################################################################################################################################
  def createLogFile(self, logLines, logPath):

    #Establish the headerLines of the file
    linesToWrite = []
    linesToWrite.append('\n' * 2)
    #Add headerLine
    linesToWrite.append('LogFile of the LocalIdXml ONLY generator')
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
    logFile = logPath + '/RtaLocalIdXmlOnlyGenerator.log'
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
  def checkGeneratorCfgFileAndConvertToAbsPaths(self, genCfg, logLines):
    '''This function does 
       - a format check of given generatorCfg file
       - for all given datFiles it establishes the absolute paths and checks whether theses files are available
    '''

    keyList = [self.GENCFG_DICT_KEY_DAT_FILES,
               self.GENCFG_DICT_KEY_OUTPUT_PATH,
              ]

    # Do a formatCheck (is dictionary, are all required keys available) 
    if not isinstance(genCfg, dict):
      #Data provided in generatorCfgFile is not stored as a dictionary!
      raise Exception(self.INFO_TEXT_GEN_CFG_FILE_NO_DICT)

    for key in keyList:
      # Check whether generatorConfigFile has all required keys
      if not key in genCfg:
        raise Exception(self.INFO_TEXT_GEN_CFG_FILE_KEY_MISSING.format(key))


    if not genCfg[self.GENCFG_DICT_KEY_DAT_FILES]:
      # No datFile provided!
      raise Exception(self.INFO_TEXT_NO_DAT_FILE_PROVIDED)

    logLines.append('The following datFiles are used:\n')
    datFilesWithRealPaths = []
    # Everything OK so far - loop over all datFiles and establish the real absolute path 
    for datFile in genCfg[self.GENCFG_DICT_KEY_DAT_FILES]:

      if(self.args.pdoRefPath):
        # pdoRefPath given - establish the absolutePath of the datFile using the pdoRefPath in case the datFile is not given as an absPaht 
        datFile = self.getAbsolutePath(self.args.pdoRefPath, datFile)
      
      datFilesWithRealPaths.append(datFile)
      logLines.append('- {0}\n'.format(datFile))
      
      if not os.path.isfile(datFile):
        raise Exception(self.INFO_TEXT_GEN_CFG_DAT_FILE_NOT_AVAILABLE.format(datFile, self.args.generatorCfgFile))
    
    #Delete entries from origin datFileList and put the datFiles with real paths to it
    del genCfg[self.GENCFG_DICT_KEY_DAT_FILES][:]
    genCfg[self.GENCFG_DICT_KEY_DAT_FILES].extend(datFilesWithRealPaths)
        
    if(self.args.outputRefPath):
      # outputRefPath given - establish the absolute path in case the outputPath is given as a relative path in the cfgFile
      genCfg[self.GENCFG_DICT_KEY_OUTPUT_PATH] = self.getAbsolutePath(self.args.outputRefPath, genCfg[self.GENCFG_DICT_KEY_OUTPUT_PATH])
      
    if not os.path.isabs(genCfg[self.GENCFG_DICT_KEY_OUTPUT_PATH]):
      # The outputPath is not an absPath
      raise Exception(self.INFO_TEXT_OUTPUT_PATH_IS_NOT_ABSOLUT.format(self.args.generatorCfgFile))
    
    if not os.path.exists(genCfg[self.GENCFG_DICT_KEY_OUTPUT_PATH]):
      # Given output path does not exist - generate it
      os.makedirs(genCfg[self.GENCFG_DICT_KEY_OUTPUT_PATH], exist_ok=True)


RtaLocalIdXmlOnlyGenerator()
