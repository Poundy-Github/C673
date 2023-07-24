import os
import stat
import re
import xml.etree.ElementTree as etree

from GeneratorCommon import GeneratorCommon
from ChainCommon     import ChainCommon

#################################################################################
#
#################################################################################
class LocalIdXmlGeneratorForISR(GeneratorCommon):


  lastIsrID = 0
  
  ALL_OS_TYPES_SUPPORTED_FOR_ISR_XML = [
    ChainCommon.OS_TYPE_EB_S  ,  
    ChainCommon.OS_TYPE_EB    ,
    ChainCommon.OS_TYPE_VECTOR, 
  ]

  #Initialize LocalIdXmlGeneratorForISR class
  def __init__(self):
    print ('GenerateLocalIdXmlForISR : object generated')

  #Run the LocalIdXmlGeneratorForISR class
  def doIt(self, genCfg, inputCfg):
    
    errorCode = self.ERR_OK
    
    for osType in self.ALL_OS_TYPES_SUPPORTED_FOR_ISR_XML:
      if inputCfg[self.INPUT_DICT_KEY_OS_TYPE] == osType: 
        # Given OsType is supported for interruptXml generation 
        osCfgFiles = []
    
        #Get all relevant osCfgFiles
        self.getRelevantOsCfgFiles(genCfg, osCfgFiles)
    
        #Generate the output file
        errorCode = self.generateXmlFile(osCfgFiles, inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH])

        break

    return errorCode

  ##################################################################################################################
  def generateXmlFile(self, osCfgFiles, outputPath):
    # Note: Here the function generateLocalIdXmlFile defined in XmlGenerationUtils cannot be used as it might be 
    # that the generator is started from different buildUnit. In case they have the same outputPath they are writing 
    # into the very same INTERRUPTS_LocalIDs.xml. Therefore here an existing XML is just updated rather than written 
    # from scratch. 
    errorCode       = self.ERR_OK
    self.lastIsrID  = 0
    
    #Check whether the file already exists
    localIdXml = os.path.join(outputPath, self.FILE_NAME_ISR_LOCAL_ID_XML)
    if os.path.isfile(localIdXml):
      # file already exists - remove writeProtection
      st_mode = os.stat(localIdXml).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(localIdXml, st_mode)

      tree = etree.parse(localIdXml)
      root = tree.getroot()
    else:
      #Create the output file
      root = etree.Element('Events')

    # remove ranges specified in the configuration file that will be changed in this function
    for entry in osCfgFiles:      
      for i in range(entry[1], entry[2]+1):
        el = root.find('.//Event[@localID="' + str(i) + '"]')
        if not el is None: 
          root.remove(el)

    for entry in osCfgFiles:
      isrList = []

      #Determine which OS we have (EB safety, EB normal or vector) and call corresponding function to get all ISR
      if os.path.basename(entry[0]) == self.OS_CFG_FILE_EB_S:
        self.extractIsrAndValuesFromFileEbSafetyOs(entry, isrList)
        
      elif os.path.basename(entry[0]) == self.OS_CFG_FILE_EB:
        self.extractIsrAndValuesFromFileEbNormalOs(entry, isrList)
        
      else: 
        self.extractIsrAndValuesFromFileVectorOs(entry, isrList)

      errorCode = self.checkIsrIDs(isrList)

      if self.ERR_OK == errorCode:
        #Create one subElement per listEntry
        for isrAndValue in isrList:
          etree.SubElement(root, "Event", name=isrAndValue[0], localID=isrAndValue[1])
      else:
        #Terminate the loop immediately
        break

    if self.ERR_OK == errorCode:
      tree = open(localIdXml, 'w')
      self.sortChildrenBy(root, 'localID')
      tree.write(self.prettify(root))
      tree.close()

    return errorCode


  #####################################################################################################################################
  def checkIsrIDs(self, isrList):
    errorCode  = self.ERR_OK

    if len(isrList):
      if int(isrList[len(isrList) - 1][1]) > self.ISR_ID_RANGE:
        #ISR IDs out of range!
        errorCode  = self.ERR_ISR_IDS_OUT_OF_RANGE
      elif (self.lastIsrID != 0) and (self.lastIsrID >= int(isrList[0][1])):
        # We have overlapping IsrIDs!!
        errorCode  = self.ERR_ISR_ID_OVERLAP

      #Update lastIsrID
      self.lastIsrID = int(isrList[len(isrList) - 1][1])

    return errorCode



  #####################################################################################################################################
  def extractIsrAndValuesFromFileEbSafetyOs(self, FileAndOffset, isrList):
    #All available values for 'state'
    stateSectionNotReached     = 0
    stateSectionReached        = 1
    stateFirstDefinitionFound  = 2
    stateLastDefinitionFound   = 3
    query = 'Interrupts'
    state = stateSectionNotReached

    #Read all lines of the osConfigFile
    osFile = open(FileAndOffset[0])
    lines = osFile.readlines()
    osFile.close()

    #Find the section where the interruptIDs are defined
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
        # Clean the line that only name and value remains
        line =  line.strip('#define')
        line = line.rstrip('\n')
        line = line.strip()
        #Separate name and value supposing that we have only name and value in line separated by space
        NameValue = line.split()
        #Add isrOffset
        NameValue[1] = str(int(NameValue[1]) + FileAndOffset[1])
        isrList.append(NameValue)

  #####################################################################################################################################
  def extractIsrAndValuesFromFileEbNormalOs(self, FileAndOffset, isrList):
    #All available values for 'state'
    stateBeforeFirstIsrDefinitionBlock     = 0
    stateExpectLineBeforeIsrDefine         = 1
    stateExpectIsrDefineLine               = 2
    stateExpectLineAfterIsrDefine          = 3
    
    # In the EB normalOs the interruptDefines are distributed to two files the Os_User.h and the Os_config.h
    # In both files we can use the same mechanism to get the interrupt IDs. The interruptIDs are defined in such blocks:
    #
    # #if OS_KERNEL_TYPE != OS_MICROKERNEL 
    # #define InterruptName xx              xx: is the decimal value of the interruptID          
    # #endif  
    # 
    # We strictly expect these blocks without anything else in between. 
    # In case something else is coming after a block we terminate the search immediately. 
    # 
    # The following patterns are used to search for the interrupt definition blocks:                             
    #
    # '#if OS_KERNEL_TYPE != OS_MICROKERNEL'
    PATTERN_LINE_BEFORE_ISR_DEF  = r' *# *if +OS_KERNEL_TYPE *!= *OS_MICROKERNEL *'
    
    # '#define InterruptName 25'
    PATTERN_ISR_DEFINE  = r' *# *define +(\S+) *(\d+) *'      # Group(1) is the interruptName, Group(2) is the idValue
    
    # '#endif'
    PATTERN_LINE_AFTER_ISR_DEF  = r' *# *endif *' 

    # Query to find the starting line of the interrupt stuff
    QUERY = 'Interrupts'
    
    # Assemble a list of both required files
    fileList = list()
    fileList.append(FileAndOffset[0]) 
    fileList.append(FileAndOffset[0][:FileAndOffset[0].rfind('/')] + '/Os_config.h') 
    
    # Get the interruptIdOffset
    isrOffset = FileAndOffset[1]

    # Now extract the interruptIds from given files
    for file in fileList:
      lines         = list()
      relevantLines = list()
      # Set start to initial state 
      state = stateBeforeFirstIsrDefinitionBlock

      #Read all lines from next file 
      osFile = open(file)
      lines  = osFile.readlines()
      osFile.close()
  
      # Get the relevant lines of file where the interrupt stuff starts:
      self.moveLinesBelowTagToSeparateList(QUERY, lines, relevantLines)
      
      #Find the section where the interruptIDs are defined
      for line in relevantLines:
        if state == stateBeforeFirstIsrDefinitionBlock or state == stateExpectLineBeforeIsrDefine:
          # Look for the first or the next IsrDefinitionBlock
          if re.match(PATTERN_LINE_BEFORE_ISR_DEF, line):
            # First line of IsrDefinitionBlock found - set state that the search for the next isrDefineLine can be started
            state = stateExpectIsrDefineLine
          else:
            if state == stateExpectLineBeforeIsrDefine:
              # Here the start of the next IsrDefinitionBlock is expected! 
              # But it is not there, evidently we got all interrupts - terminate the loop 
              break
        elif state == stateExpectIsrDefineLine:
          # Look for the next IsrDefineLine
          obj = re.match(PATTERN_ISR_DEFINE, line)
          if obj:
            # isrDefineLine found - get isrName and isrValue 
            isrName = obj.group(1) 
            isrValue = str(int(obj.group(2)) + isrOffset) 
            isrList.append([isrName, isrValue])
            
            # Set next state that the search of the expected line after the isrDefineLine can be started  
            state = stateExpectLineAfterIsrDefine
            
        elif state == stateExpectLineAfterIsrDefine:
          # Look for the line after interruptDefineLine
          if re.match(PATTERN_LINE_AFTER_ISR_DEF, line):
            # Line after isrDefineLine found - set state that the search for the next isrDefinitionBlock can be started 
            state = stateExpectLineBeforeIsrDefine

  #####################################################################################################################################
  def extractIsrAndValuesFromFileVectorOs(self, FileAndOffset, isrList):
        #Read all lines of osCfgFile
    fileObj = open(FileAndOffset[0])
    lines = fileObj.readlines()
    fileObj.close()

    # In Os_Types_Lcfg.h we expect to find the taskIDs defined in the enumeration TaskType with the following format:
    # 
    # /*! Category 2 ISR identifiers. */
    # typedef enum
    # {
    #   CounterIsr_OsCounter = 0,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   MSS_CR5A_FPU_INT = 1,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   MSS_CR5B_FPU_INT = 2,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   MSS_ESM_HI = 3,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   MSS_ESM_LO = 4,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   MSS_WDT_INT0 = 5,   /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
    #   OS_ISRID_COUNT = 6,
    #   INVALID_ISR = OS_ISRID_COUNT
    # } ISRType;

    startQuery = '/*! Category 2 ISR identifiers. */'
    inRegionOfInterrest = False

    PATTERN_ISR_LITERAL  = r' *(\S+) *= *(\d+) *, *'      # Group(1) is the interruptName, Group(2) is the idValue
    
    #Find the section where the taskIDs are defined
    for line in lines:
      if not inRegionOfInterrest:
        if line.find(startQuery) != -1:
          #We reached the taskType enum
          inRegionOfInterrest = True
      else:
        obj = re.match(PATTERN_ISR_LITERAL, line)
        if obj:
          isrName = obj.group(1)
                    
          #Check whether it's the line of the OS_ISRID_COUNT, which is actually the line after the last isrID
          if 'OS_ISRID_COUNT' == isrName:
            #We reached the end of the ISR literals in the enum - stop collecting the taskNames 
            break
          else: 
            #It's an ISR - calculate idValue (Value from line + offset) and turn it to string afterwards 
            idValue = str(int(obj.group(2)) + FileAndOffset[1]) 
            
            isrList.append([isrName, idValue])
    
  ###########################################################################################################
  def getRelevantOsCfgFiles(self, genCfg, osCfgFiles):
    fileList = []

    #Loop over all cores
    for entry in genCfg[self.GENCFG_DICT_KEY_CORES]:
      fileNotProcessed = True
      #Check if we had this file already - to avoid double entries in XML
      #Note: In multiCoreOs the cores have the same configFiles
      for fileEntry in fileList:
        if fileEntry == entry[self.OS_CFG_FILE]:
          fileNotProcessed = False

      #Check whether we processed this file already
      if fileNotProcessed:
        #Add current file to fileList
        fileList.append(entry[self.OS_CFG_FILE])

        #Get osCfgFile
        osCfgFile = entry[self.OS_CFG_FILE]
        
        #OK file exists - get IsrRange
        rangeStart = 0    
        if len(entry[self.ISR_RANGE_START]):
          rangeStart = int(entry[self.ISR_RANGE_START])

        rangeEnd = 0
        if len(entry[self.ISR_RANGE_END]):
          rangeEnd = int(entry[self.ISR_RANGE_END])
        #Add file to list
        osCfgFiles.append([osCfgFile, rangeStart, rangeEnd])

