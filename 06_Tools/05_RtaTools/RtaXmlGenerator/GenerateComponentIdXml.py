import os
import stat
import re
import xml.etree.ElementTree as etree

from shutil import copyfile
from GeneratorCommon import GeneratorCommon
from ChainCommon     import ChainCommon


#################################################################################
#
#################################################################################
class ComponentIdGenerator(GeneratorCommon):

  ALL_OS_TYPES_SUPPORTED_FOR_GLOBAL_ID_XML = [
    ChainCommon.OS_TYPE_EB_S  ,  
    ChainCommon.OS_TYPE_EB    ,
    ChainCommon.OS_TYPE_VECTOR, 
    ChainCommon.OS_TYPE_RTOS  ,
  ]          

  #Initialize ComponentIdGenerator class
  def __init__(self):
    print ('GenerateComponentIdXml: object generated!')

  #Run the ComponentIdGenerator class ##########################################################################################################################
  def doIt(self, genCfg, inputCfg):

    errorCode           = self.ERR_OK
    revisionInfo        = []
    globalIdList        = []
    self.genAdaptAdapter_LocalIdXml  = os.path.join(inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH], 'GEN_ADAPT_ADAPTER' + self.SUFFIX_LOCAL_ID_XML)
    self.genAdaptAlgoExec_LocalIdXml = os.path.join(inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH], 'GEN_ADAPT_ALGO_EXEC' + self.SUFFIX_LOCAL_ID_XML)
    self.globalIdXml                 = os.path.join(inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH], self.FILE_NAME_COMP_IDS_XML)

    #It has to be ensured that this file exists before all required information is collected
    #This is important as this file has to be linked to the related globalIDs in the ComponentIDsXML
    self.createLocalIdXMLsForGenericAdapterIfItNotExist()

    #Get all needed information
    errorCode = self.collectAllRequiredInfo(genCfg, inputCfg, revisionInfo, globalIdList)

    if self.ERR_OK == errorCode:
      #Anything is OK - have the XMLs generated
      self.generateComponentIDsXML(revisionInfo, globalIdList)
      self.generateLocalIdXMLsForGenericAdapter(revisionInfo, globalIdList)

    return errorCode

  ##############################################################################################################################################################
  def collectAllRequiredInfo(self, genCfg, inputCfg, revisionInfo, globalIdList):
    errorCode           = self.ERR_OK
    localIdXMLs         = []
    errorIdXMLs         = []
    internErrorIdXMLs   = []
    rteGlobalIdList     = []

    #Get all localIDXml- and erorIDXml-files 
    self.getAllXmlFilesOfInterrest(inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH], localIdXMLs, errorIdXMLs, internErrorIdXMLs)

    #Get the list of all globalIDs for the RTE - sorted by taskPrio including globalID-Value
    self.getRteGlobalIDList(genCfg, inputCfg, rteGlobalIdList)
    
    if len(rteGlobalIdList) >= self.MAX_NUMBER_RTE_GLOBAL_IDS:
      # There are too many tasks in the project
      errorCode = self.ERR_NUMBER_OF_TASKS_OUT_OF_RANGE
    else:
      inFile = open(inputCfg[self.INPUT_DICT_KEY_RTA_GLOBAL_IDS_H])
      lines = inFile.readlines()
      inFile.close()
  
      #Find the revision of rta_globalids.h
      revisionInfo.append('Generated from rta_globalids.h ')

      for line in lines:
        if line.find('$Revision:') != -1:
          #VersionInfo found - add it to desired string
          line = line[line.find('$')+1:line.rfind('$')]
          line = line.lower()
          line = line.replace(':', '')
          revisionInfo[0] = revisionInfo[0] + line
  
      #Get a list of all globalIDs and there values from lines
      self.getAllGlobalIDs(lines, rteGlobalIdList, globalIdList)
      #Find the localId- and errorId-XmlFiles to the globalIDs
      self.addMatchingXmlsToGlobalIDs(localIdXMLs, errorIdXMLs, internErrorIdXMLs, globalIdList)

    return errorCode

  #Provide a list of all RTE-GlobalIDs including value. The list is sorted by taskPrio#########################################################################################
  def getRteGlobalIDList(self, genCfg, inputCfg, rteGlobalIdList):

    # Ensure that the given list is empty 
    rteGlobalIdList.clear()
    
    # Check whether this osType is supported for globalID XML generation
    for osType in self.ALL_OS_TYPES_SUPPORTED_FOR_GLOBAL_ID_XML:
      if inputCfg[self.INPUT_DICT_KEY_OS_TYPE] == osType: 
        # Given OsType is supported for globalIdXml generation 
        #Get the provided osConfiguration file including absolute path
        osCfgFile = genCfg[self.GENCFG_DICT_KEY_CORES][0][self.OS_CFG_FILE]
    
        if len(osCfgFile):
          osTaskListIdSorted = []
          taskListPrioSorted = []
  
          # Get the taskList from taskIDLut_h - this list is sorted by task priorities 
          taskIDLut_h = os.path.join(inputCfg[self.INPUT_DICT_KEY_LUT_CFG_FILE_PATH], self.TASK_LUT_FILE_NAME)
          self.getTaskList(taskListPrioSorted, taskIDLut_h)
  
          # Get all tasks from the OS - this list is sorted by osTaskIDs
          self.getTasksFromOsCfgFile(osCfgFile, osTaskListIdSorted, inputCfg[self.INPUT_DICT_KEY_OS_TYPE])
  
          #Fill the rteGlobalIdList in order of taskPrios with rteGlobalIdName and -value 
          for entry in taskListPrioSorted:
            osTaskName = entry[self.IDX_TASKLIST_OS_TASK_ID]
          
            for idx in range(len(osTaskListIdSorted)):
              if osTaskListIdSorted[idx] == osTaskName:
                # Now we have the related taskId - get the name and calculate value for this RteGlobalID
                name  = 'RTE_' + osTaskName.replace('_','')
                value = str(self.RTE_GLOBAL_IDS_RANGE_START + idx)
              
                # Add it to the list 
                rteGlobalIdList.append([name, value])
                break
        # terminate the outer for-loop
        break


  #Generate a list containing globalIDs, their values and the related path to the localID.xml and errorIDs - if available##########################################
  def addMatchingXmlsToGlobalIDs(self, localIdXMLs, errorIdXMLs, internErrorIdXMLs, globalIdList):
    #Loop over the list of gobalIDs and look for a localID.xml with the name from the componentID
    for globalIdEntry in globalIdList:
      localIDFile = ''
      #Get the current globalID - normated to capital letters (to make the mapping case insensitive)
      globalID = globalIdEntry[0].upper()

      localIDFile = self.findXmlFileMatchingToGlobalID(localIdXMLs, globalID)
      #Add the localIDFile to the current gobalIdEntry
      localIDFile = localIDFile.replace("\\","/")
      globalIdEntry.append(localIDFile)

      errorIDFile = self.findXmlFileMatchingToGlobalID(errorIdXMLs, globalID)
      #Add the errorIDFile to the current gobalIdEntry
      errorIDFile = errorIDFile.replace("\\","/")
      globalIdEntry.append(errorIDFile)

      internErrorIDFile = self.findXmlFileMatchingToGlobalID(internErrorIdXMLs, globalID)
      #Add the internalErrorIDFile to the current gobalIdEntry
      internErrorIDFile = internErrorIDFile.replace("\\","/")
      globalIdEntry.append(internErrorIDFile)


  #Get all globalIDs and there values from lines #####################################################################################################
  def getAllGlobalIDs(self, lines, rteGlobalIdList, globIdsAndValues):
    #All available values for 'state'
    stateBeforeSection        = 0
    stateInSection            = 1
    stateAfterSection         = 2

    startQuery = self.GEN_TAG_GLOBAL_ID_START
    endQuery   = self.GEN_TAG_GLOBAL_ID_END
    state = stateBeforeSection

    myList = []
    #Find all globalID defines and generate a list of all globalIDs including value 
    for line in lines:
      if state == stateBeforeSection:
        if line.find(startQuery) != -1:
          state = stateInSection
      elif state == stateInSection:
        if line.find(endQuery) != -1:
          state = stateAfterSection
        else:
          obj = re.match(self.GLOBAL_ID_DEFINE_SEARCH_PATTERN, line)
          if obj:
            # This is a line defining a globalID -> extract name and value
            name    = obj.group(1).replace(self.GLOBAL_ID_NAME_PREFIX, '')
            value   = obj.group(2)
        
            #Add pair of name and value to the list
            myList.append([name, value])

    #Establish a list of gobalIDs which shall be copied first into the globIdsAndValues
    copyList = ['INTERRUPTS', 'HWI', 'SWI']

    for entryCopyList in copyList:
      #Find corresponding entry in list of all globalIDs
      for idx in range(len(myList)):
        if myList[idx][0] == entryCopyList:
          #Copy the entry from myList into the globIdsAndValues which is provided to caller
          globIdsAndValues.append(myList[idx])
          #remove this entry
          del myList[idx]
          break

    # Now add all rteGlobalIDs to the list - this list is already sorted by priority of the related tasks  
    globIdsAndValues.extend(rteGlobalIdList)
    
    # Finally add all remaining globalIDs to globIdsAndValues
    globIdsAndValues.extend(myList)

  #Create the componentIDsXML file ############################################################################################################################
  def generateComponentIDsXML(self, revisionInfo, globalIdList):

    root = etree.Element("Components")
    root.insert(0, etree.Comment(revisionInfo[0]))
    for entry in globalIdList:
      etree.SubElement(root, "Component", name=entry[0], componentID=entry[1], path=entry[2], error=entry[3], internal=entry[4])

    #Check whether the file already exists
    if os.path.isfile(self.globalIdXml):
      # file already exists - remove writeProtection
      st_mode = os.stat(self.globalIdXml).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(self.globalIdXml, st_mode)
    #Open and fill (or update) the file
    tree = open(self.globalIdXml, 'w')
    tree.write(self.prettify(root))
    tree.close()

  #Create the componentIDsXML file ############################################################################################################################
  # Note: The generic(Algo)Adapter in the DPUs of MFC-Projects and the ARS441-projects implements a generic runtimeInstrumentation using the componentIDs
  # (globalIDs) of the called algoComponents as localIDs. Therefore we need a localID-xml containing all componentIDs as localIDs.
  # This xml-File shall be used for the COMP_ID_SW_GEN_ADAPT_ADAPTER (160) and for the COMP_ID_SW_GEN_ADAPT_ALGO_EXEC (165).
  def generateLocalIdXMLsForGenericAdapter(self, revisionInfo, globalIdList):

    root = etree.Element('Events')
    root.insert(0, etree.Comment(revisionInfo[0]))
    for entry in globalIdList:
      etree.SubElement(root, 'Event', name=entry[0], localID=entry[1], useColorSweep='1')

    #Remove the writeProtection in case the files already exist
    if os.path.isfile(self.genAdaptAdapter_LocalIdXml):
      st_mode = os.stat(self.genAdaptAdapter_LocalIdXml).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(self.genAdaptAdapter_LocalIdXml, st_mode)

    if os.path.isfile(self.genAdaptAlgoExec_LocalIdXml):
      st_mode = os.stat(self.genAdaptAlgoExec_LocalIdXml).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(self.genAdaptAlgoExec_LocalIdXml, st_mode)

    #Open and fill (or update) the genAdaptAdapter_LocalIdXml
    tree = open(self.genAdaptAdapter_LocalIdXml, 'w')
    tree.write(self.prettify(root))
    tree.close()

    #Just copy it both files shall be equal
    #Note: For linking the localIdXmls to the related globalID files with certain names are needed
    copyfile(self.genAdaptAdapter_LocalIdXml, self.genAdaptAlgoExec_LocalIdXml)



  #Create the componentIDsXML file in case they are not exist yet #############################################################################################################
  def createLocalIdXMLsForGenericAdapterIfItNotExist(self):
    #Check wether required files already exist
    if not os.path.isfile(self.genAdaptAdapter_LocalIdXml):
      # file does not exists - create it
      fileObj = open(self.genAdaptAdapter_LocalIdXml, 'w')
      fileObj.close()

    if not os.path.isfile(self.genAdaptAlgoExec_LocalIdXml):
      # file does not exists - create it
      fileObj = open(self.genAdaptAlgoExec_LocalIdXml, 'w')
      fileObj.close()

