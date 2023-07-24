import os
import shutil
import stat
import sys
import argparse
import xml.etree.ElementTree as etree


sys.path.append(os.path.join(sys.path[0],'../../ToolChainCommon'))
sys.path.append(os.path.join(sys.path[0],'../'))

from datetime         import datetime
from GeneratorCommon  import GeneratorCommon


#################################################################################
# The XmlMerger
#################################################################################
class XmlMerger(GeneratorCommon):  

  project      = 'Unknown'
  dstPath      = ''
  listSrcPaths = []
  logLines     = []

  #Initialize XmlMerger class
  def __init__(self):

    self.doIt()

# argument parsing ############################################################################
  def check_args(self):
    parser = argparse.ArgumentParser(prog='XmlMerger',
                                     formatter_class=argparse.RawTextHelpFormatter,
                                     description = 'Merges the XML-Files of different buildUnits together. ')
    parser.add_argument('projectName',
                        action = 'store',
                        help ='The name of the project.')
    
    parser.add_argument('dstPath',
                        action = 'store',
                        help ='The path where the merged XMLs shall be copied to.')
    
    parser.add_argument('srcPath_0',
                        action ='store',
                        help = '''The location of the XMLs of buildUnit 0''')
    
    parser.add_argument('-1', '--srcPath_1',
                        action ='store',
                        help = '''The location of the XMLs of buildUnit 1''')

    
    parser.add_argument('-2', '--srcPath_2',
                        action ='store',
                        help = '''The location of the XMLs of buildUnit 2''')
    
    parser.add_argument('-3', '--srcPath_3',
                        action ='store',
                        help = '''The location of the XMLs of buildUnit 3''')
    
    parser.add_argument('-4', '--srcPath_4',
                        action ='store',
                        help = '''The location of the XMLs of buildUnit 4''')
    
    parser.add_argument('-5', '--srcPath_5',
                        action ='store',
                        help = '''The location of the XMLs of buildUnit 5''')
    
    parser.add_argument('-6', '--srcPath_6',
                        action ='store',
                        help = '''The location of the XMLs of buildUnit 6''')
    
    parser.add_argument('-7', '--srcPath_7',
                        action ='store',
                        help = '''The location of the XMLs of buildUnit 7''')


    return parser.parse_args()

  #This is the main function calling all other generators ###################################################################################
  def doIt(self):
    
    
    print('Run the XmlMerger\n')
    self.logLines.append('LogFile of the xmlMerger\n\n')
    
    try:
      self.getAllArguments()
      
      #Delete whole destinationFolder - to ensure that old files which might be in the destFolder are removed
      self.deleteDstFolder()
      
      if 1 == len(self.listSrcPaths):
        #We have just one srcFolder - just copy it to dest, no need for merging
        shutil.copytree(self.listSrcPaths[0], self.dstPath)
    
        self.logLines.append('''There was only one sourcePaths provided. No merging required.  
All files are just copied from source to destination folder.
''')
        
      else:
        #Create destination folder againg 
        os.mkdir(self.dstPath)
        #Merge the XML files of all sourceFolder together 
        #1) copy all localId-XMLs exept the interruptXml
        self.copyAllNormalLocalIdXmlFiles()
        self.logLines.append('--> All localIdXmlFiles copied to destinationFolder. \n')

        #2) Merge all INTERRUPTS_LocalIDs.xml together
        self.mergeInterruptLocalIdXmlFiles()
        self.logLines.append('--> All INTERRUPTS_LocalIDs.xmls merged together and put into destinationFolder. \n')

        #3) In the ComponentID.xml add references to localID.xml, errorID.xml and internalID.xml 
        self.addRefPathsToComponentIdXmlFile()
        self.logLines.append('--> The ComponentID.xmls is updated with refPaths and put into destinationFolder. \n')
        
        #3) Merge all RTA_CORES.xml together
        self.mergeRtaCoreXmlFiles()
        self.logLines.append('--> All RTA_CORES.xmls merged together and put into destinationFolder. \n\n')

        print ('XmlMerger successfully run!\n')
        self.logLines.append('XmlMerger successfully run!\n')

    except Exception as ex:
      print(ex)
      self.logLines.append(ex)
    finally:
      self.createLogFile()

    
  def createLogFile(self):

    if os.path.isdir(self.dstPath):
      logPath = self.dstPath
    else:
      #generate the logFile to defaultLocation
      logPath = self.getDefaultLocationForLogFile()

    #check if file exists
    logFile = logPath + '/{0}_XmlMerger.log'.format(self.project)
    if os.path.isfile(logFile):
      # file already exists - remove writeProtection and open it'
      st_mode = os.stat(logFile).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(logFile, st_mode)
   
    #Write the logFile
    try: 
      fileObj = open(logFile, 'w')
      fileObj.writelines(self.logLines)
      fileObj.close()
      print(self.INFO_TEXT_LOG_FILE_GENERATION.format(logFile))
    except:
      print("RTA Generator ERROR: Cannot write log file - " + logFile)

  def deleteDstFolder(self):
    for root, dirs, files in os.walk(self.dstPath): # @UnusedVariable
      for file in files:
        currentFile = os.path.join(root,file)
        st_mode = os.stat(currentFile).st_mode | stat.S_IWRITE | stat.S_IREAD
        os.chmod(currentFile, st_mode)

    #Delete the whole folder including content
    shutil.rmtree(self.dstPath)

    
    
    
  def mergeRtaCoreXmlFiles(self):
    
    print('Merge all RtaCoresXmlFiles together and put the merged file into the destination folder \n')
    coreList = []
    
    for srcFolder in self.listSrcPaths:
      rtaCoreXmlFile = os.path.join(srcFolder, self.FILE_NAME_RTA_CORES_XML)
      if os.path.isfile(rtaCoreXmlFile):
        #isrLocalIdXmlFile is available in this folder get all localIDs from it
        tree = etree.parse(rtaCoreXmlFile)
        root = tree.getroot()
        
        taskList = []
        for core in root.iter('Core'):
          for task in core.iter('Task'):
            taskList.append(task.attrib)
          coreList.append([core.attrib, taskList])
        
    root = etree.Element('Config')
#    root.append(etree.Comment('RTA configuration generated for:'))
#    root.append(etree.Comment(dictReleaseInfo['projectStr']))
#    root.append(etree.Comment(dictReleaseInfo['releaseVersion']))
#    root.append(etree.Comment(dictReleaseInfo['releaseDate']))
    #Add info about componentIdXml and errorOffsetsXml
    etree.SubElement(root, 'ComponentIDs', file= self.FILE_NAME_COMP_IDS_XML)
    etree.SubElement(root, 'ErrorOffsets', file= self.FILE_NAME_ERROR_OFFSETS_XML)

    #Add all specified cores
    subElemCores = etree.SubElement(root, 'Cores')
    
    for core in coreList:
      #Add a new coreElement
      subElemCore = etree.SubElement(subElemCores, 'Core' , core[0])
      
      for task in core[1]:
        etree.SubElement(subElemCore, 'Task', task)
        
    #Check for unique coreIDs
    coreIdList = []
    for core in root.iter('Core'):
      coreIdList.append(core.get('coreID'))
    
    for coreId in coreIdList:
      if 1 != coreIdList.count(coreId):
        raise Exception('error: There are coreIds which are not unique - doubleCheck the configuration of the buildUnits!')
      
    self.sortChildrenBy(subElemCores, 'coreID')

    #Now write the xmlFile 
    tree = open(os.path.join(self.dstPath, self.FILE_NAME_RTA_CORES_XML), 'w')
    tree.write(self.prettify(root))
    tree.close()
    
    
  def addRefPathsToComponentIdXmlFile(self):
    
    print('Add referencePaths (to localId- , errorId- and internalId-XmlFiles) to the componentIdXml and put it into the destination folder \n')
    
    compIdList          = []
    localIdXMLs         = []
    errorIdXMLs         = []
    internErrorIdXMLs   = []
    compIdXmlFile       = None
    
    #Find the componententIdXmlFile
    for srcFolder in self.listSrcPaths:
      if os.path.isfile(os.path.join(srcFolder, self.FILE_NAME_COMP_IDS_XML)):
        if None == compIdXmlFile:
          #This srcFolder contains the file and it 's the first time we found such a file - save its full path
          compIdXmlFile = os.path.join(srcFolder, self.FILE_NAME_COMP_IDS_XML)
        
        else:
          #There is a second srcFolder containing a componententIdXmlFile - this must not be! 
          raise Exception('''error: More then one srcFolder contains a {0}! There must be only one {0}!
DoubleCheck the configuration of the buildUnits!'''.format(self.FILE_NAME_COMP_IDS_XML))
        
    #Get all componentIDs from current compIdXmlFile
    root = etree.parse(compIdXmlFile).getroot()
    for child in root:
      compIdList.append(child.attrib)
    
    
    #Get lists of all localID-, erorID and internalID-XmlFiles found in dstFolder
    self.getAllXmlFilesOfInterrest(self.dstPath, localIdXMLs, errorIdXMLs, internErrorIdXMLs)

    #Create new compIdXmlFile in destination folder 
    root =etree.Element('Components')
    
    for compIdEntry in compIdList:
      #Add references to files - if available
      compIdEntry['path'    ] = self.findXmlFileMatchingToGlobalID(localIdXMLs      , compIdEntry['name'].upper())
      compIdEntry['error'   ] = self.findXmlFileMatchingToGlobalID(errorIdXMLs      , compIdEntry['name'].upper())
      compIdEntry['internal'] = self.findXmlFileMatchingToGlobalID(internErrorIdXMLs, compIdEntry['name'].upper())
      
      #Add compIdEntry to root 
      etree.SubElement(root, 'Component', compIdEntry)
    
    #Now write the xmlFile 
    tree = open(os.path.join(self.dstPath, self.FILE_NAME_COMP_IDS_XML), 'w')
    tree.write(self.prettify(root))
    tree.close()
    
    
  def mergeInterruptLocalIdXmlFiles(self):
    
    print('Merge all interruptLocalIdXmlFiles together and put the merged file into the destination folder \n')
    localIdList = []
    
    for srcFolder in self.listSrcPaths:
      isrLocalIdXmlFile = os.path.join(srcFolder, self.FILE_NAME_ISR_LOCAL_ID_XML)
      if os.path.isfile(isrLocalIdXmlFile):
        #isrLocalIdXmlFile is available in this folder get all localIDs from it
        tree = etree.parse(isrLocalIdXmlFile)
        root = tree.getroot()
        
        for child in root:
          localIdList.append(child.attrib)

    #Ensure that every localIdValue is unique and in range  
    localIdValueList = []
    for localId in localIdList:
      localIdValueList.append(localId['localID'])
    
    for localIdValue in localIdValueList:
      if 1 != localIdValueList.count(localIdValue):
        raise Exception('error: There are localID values which are not unique - overlapping IdRange of the buildUnits?')
      
      if 0 > int(localIdValue) or self.ISR_ID_RANGE < int(localIdValue):
        raise Exception ('error: LocalID value out of range. Valid range: 0 - {0}'.format(self.ISR_ID_RANGE))
      
    #Create the new interruptLocalId xml file 
    root = etree.Element('Events')
    
    #Add all localIDs and sort them by localID value 
    for localId in localIdList:
      etree.SubElement(root, 'Event', localId)
    self.sortChildrenBy(root, 'localID')
    
    #Now write the xmlFile 
    tree = open(os.path.join(self.dstPath, self.FILE_NAME_ISR_LOCAL_ID_XML), 'w')
    tree.write(self.prettify(root))
    tree.close()


  def copyAllNormalLocalIdXmlFiles(self):
    
    print('Copy all normal localIdXmlFiles, errorIdXmlFiles and internalIdXmlFiles into the destinantion folder.\n')
    for srcFolder in self.listSrcPaths:
      for srcFile in os.listdir(srcFolder):
        if (  srcFile.endswith(self.SUFFIX_LOCAL_ID_XML) and not srcFile.endswith(self.FILE_NAME_ISR_LOCAL_ID_XML)
            or srcFile.endswith(self.SUFFIX_ERROR_ID_XML) 
            or srcFile.endswith(self.SUFFIX_INTERN_ERROR_ID_XML) 
            ):
          #OK, this is a "normal" localID xml, an errorID xml or an internalIDxml, check wehter it's already available in dstFolder 
          if not os.path.isfile(os.path.join(self.dstPath, srcFile)):
            #This localIdXml is not available yet in dest - copy it 
            shutil.copy(os.path.join(srcFolder, srcFile), self.dstPath)
    
  def getAllArguments(self):
    '''This function collects the dstPath and all given srcPath and checks them for valitity
    '''
    
    args = self.check_args()

    self.project     = args.projectName
    self.dstPath     = args.dstPath
    
    self.listSrcPaths.append(args.srcPath_0)

    if args.srcPath_1:
      self.listSrcPaths.append(args.srcPath_1)
    
    if args.srcPath_2:
      self.listSrcPaths.append(args.srcPath_2)
    
    if args.srcPath_3:
      self.listSrcPaths.append(args.srcPath_3)
    
    if args.srcPath_4:
      self.listSrcPaths.append(args.srcPath_4)
    
    if args.srcPath_5:
      self.listSrcPaths.append(args.srcPath_5)
    
    if args.srcPath_6:
      self.listSrcPaths.append(args.srcPath_6)
    
    if args.srcPath_7:
      self.listSrcPaths.append(args.srcPath_7)
    
    #Check dstPath and all srcPaths
    if not os.path.exists(self.dstPath):
      raise Exception('error: Given dstPath ( {0} ) is invalid!'.format(self.dstPath))
    
    for index in range(len(self.listSrcPaths)):
      if not os.path.exists(self.listSrcPaths[index]):
        raise Exception('error: Given srcPath ( {0} ) is invalid!'.format(self.listSrcPaths[index]))

    self.logLines.append('ProjectName: {0}\n'.format(self.project))
    self.logLines.append('Date:      {}\n\n'.format(datetime.now().strftime('%d.%m.%Y %H:%M:%S')))
    
    self.logLines.append('Provided destinationPath: {0}\n\n'.format(self.dstPath))
    self.logLines.append('Provided sourcePaths:\n')
    
    for srcPath in self.listSrcPaths:
      self.logLines.append('- {0}\n'.format(srcPath))
      
    self.logLines.append('\n')
    


XmlMerger()
