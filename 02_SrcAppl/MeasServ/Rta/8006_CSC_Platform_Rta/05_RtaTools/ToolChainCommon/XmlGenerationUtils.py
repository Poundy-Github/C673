import os
import stat

from xml.dom import minidom
from xml.etree import ElementTree
import xml.etree.ElementTree as etree

#################################################################################
# All helper functions related to XML generation
#################################################################################

class XmlGenerationUtils(object):

  #Expected enumName of the errorOffsetEnum
  EXP_NAME_OF_ERROR_OFFSET_ENUM = 'ErrOffset'
  
  #Types of xmlFiles 
  NO_XML              = 0
  LOCAL_ID_XML        = 1
  ERROR_ID_XML        = 2
  INTERN_ERROR_ID_XML = 3
  ERROR_OFFSETS_XML   = 4
  
  #XmlFile names an suffixes
  SUFFIX_LOCAL_ID_XML         = '_LocalIDs.xml'
  SUFFIX_ERROR_ID_XML         = '_ErrorIDs.xml'
  SUFFIX_INTERN_ERROR_ID_XML  = '_InternalIDs.xml'
  FILE_NAME_RTA_CORES_XML     = 'RTA_CORES.xml'
  FILE_NAME_COMP_IDS_XML      = 'ComponentIDs.xml'
  FILE_NAME_ERROR_OFFSETS_XML = 'ErrOffsets.xml'
  FILE_NAME_ISR_LOCAL_ID_XML  = 'INTERRUPTS' + SUFFIX_LOCAL_ID_XML
  
  #Dictionary for fileNameSuffixes
  XML_NAME_SUFFIXES = {
    LOCAL_ID_XML         : SUFFIX_LOCAL_ID_XML         ,
    ERROR_ID_XML         : SUFFIX_ERROR_ID_XML         ,
    INTERN_ERROR_ID_XML  : SUFFIX_INTERN_ERROR_ID_XML  ,
    ERROR_OFFSETS_XML    : FILE_NAME_ERROR_OFFSETS_XML ,
  }
  
  #Keys for the localIdList used in the function generateLocalIdXmlFile
  LOCAL_ID_LIST_KEY_NAME                = 'name'               # Has to be a string
  LOCAL_ID_LIST_KEY_VALUE               = 'value'              # Has to be a string
  LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE  = 'noneInterruptable'  # True, False
  LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP     = 'useColorSweep'      # True, False
  
  #Initialize the class################################################################################################################################################################################
  def __init__(self):
    print ('xmlGenerationUtils')
    
  # function for sorting XML elements
  def sortChildrenBy(self, parent, attr):
    parent[:] = sorted(parent, key=lambda child: int(child.get(attr)))

  #Used for indentation of the xml output file ###########################################################################################################
  def prettify(self, elem):
    rough_string = ElementTree.tostring(elem, 'utf-8')
    # re.sub('\s+(?=<)', '', rough_string)
    rough_string = rough_string.replace(b'\n', b'').replace(b'\r', b'').replace(b'  ', b'')
    #print (rough_string)
    reparsed = minidom.parseString(rough_string)
    return reparsed.toprettyxml(indent="  ")


  #Assemble fileName of the new localID-XML ##################################################################################################################
  def assembleNameForXmlFile(self, enum_name, xmlType):
    name = ''
    
    #Check whether we got a valid xmlType
    if xmlType in self.XML_NAME_SUFFIXES:
      if self.ERROR_OFFSETS_XML == xmlType:
        #Check whether this is the correct enumeration - there must be only one errorOffsetEnum!
        if self.EXP_NAME_OF_ERROR_OFFSET_ENUM == enum_name:
          #In case of ErrorOffset we just use the suffix as we have only one offsetEnum
          name = self.XML_NAME_SUFFIXES[xmlType]
      else:
        #It's either a localID_xml, an errorId_xml or a internalErrorId_xml -> extract the name from enumName
        #It may be that the name given in dat file starts with 'enum ' . Remove it if its the case
        if enum_name.startswith('enum '):
          enum_name = enum_name.replace('enum ', '')
        # Note: The following format for the enumerations is expected:
        #
        # <SHORTNAME>_ t_[EXT_] FreeTextEnumName
        #
        # Important: The 'FreeTextEnumName' field must not contain underscores ('_')!!!

        #Substitute '_t_' by '_'
        enum_name = enum_name.replace('_t_','_')
        #Now simply take the part before the last underscore - in case there is one 
        if(-1 != enum_name.find('_')): 
          enum_name = enum_name[:enum_name.rfind('_')]

        #Assemble final name and return it
        name = enum_name + self.XML_NAME_SUFFIXES[xmlType]
    
    return name



  #Clean enumLiterals (Remove componentPrefixes, substrings like '_e_' and 'RTA'  ########################################################################################################
  def cleanEnumLiteral(self, literal, file_name):
    #List of subStrings which shall be removed
    #Note: Order is important! The longest strings have to be first
    standardSubStringsToRemove = [
      'Rta_Id_',
      'Rta_Id',
      'RtaId_',
      'RtaId',
      'e_RTA_',
      'e_RTA',
      'eRTA_',
      'eRTA',
      'RTA_e_',
      'RTAe_',
      'RTA_',
      '_e_',
    ]

    #Get the prefix from the file name for cleaning the enum literals
    prefix = file_name[:file_name.rfind('_') + 1]
    #Create a list of prefixes
    prefixList = []

    #Add the prefix like we got it
    prefixList.append(prefix)
    #In case we have an extension in prefix like SR_A_, IPC_TX_ - remove the extension from prefix
    if -1  != prefix.count('_'):
      prefix = prefix[:prefix.find('_') + 1]
      #Add the prefix without extension to the list
      prefixList.append(prefix)

    #create the final list of substrings to be removed
    finalListSubStringsToRemove = []

    for prefixEntry in prefixList:
      for subStr in standardSubStringsToRemove:
        #Add three variants for each entry to finalList
        finalListSubStringsToRemove.append(prefixEntry + subStr)              #prefix including trailing underscore
        finalListSubStringsToRemove.append(prefixEntry.rstrip('_') + subStr)  #prefix without trailing underscore
      finalListSubStringsToRemove.append(prefixEntry.rstrip('_'))          #Just prefix without trailing underscore

    finalListSubStringsToRemove.extend(standardSubStringsToRemove)                       #Just entry without prefix

    for entry in finalListSubStringsToRemove:
      doTheCutOut = True
      #Look for subString - not case sensitive
      idx = (literal.upper()).find(entry.upper())
      if -1 != idx:
        if (file_name.startswith('RTE_')) and (-1 != entry.upper().find('RTA_')) and (-1 != (literal.upper()).find('RTA_MAIN')):
          #Currently we have the literal for the RTA_v_Mainfunction - we must not cut out the string 'RTA'
          doTheCutOut = False

        if doTheCutOut:
          #Cut out the subString - leading or trailing underscores shall remain in the literal
          literal = literal[:idx + len(entry) - len(entry.lstrip('_'))] + literal[idx + len(entry.rstrip('_')):]

    #Remove leading and trailing underscores
    literal = literal.strip('_')
    #Remove multiple '_' in a row
    literal = literal.replace('____', '_')
    literal = literal.replace('___', '_')
    literal = literal.replace('__', '_')

    return literal


  ##################################################################################################################
  def generateLocalIdXmlFile(self, localIdList, xmlFile):
    '''This function generates a localId XML file based on given localIdList
    
       localIdList has to be a list of dictionaries with the following keys: 
          self.LOCAL_ID_LIST_KEY_NAME               -> Has to be a string
          self.LOCAL_ID_LIST_KEY_VALUE              -> Has to be a string             
          self.LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE -> True/False 
          self.LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP    -> True/False 
      
       xmlFile is the file which will be generated. It has to be provided with its full path
       
       Preconditions: 
       - The names of the localIDs have to be unique
       - The values of the localIDs have to be unique 
       - The path of given xmlFile has to be valid
     '''
    # Check if the directory for given xmlFile exists 
    if not os.path.isdir(os.path.dirname(xmlFile)):
      raise Exception('The directory for the following xmlFile does not exist'.format(xmlFile))
        
    if os.path.isfile(xmlFile):
      # file already exists - remove writeProtection
      st_mode = os.stat(xmlFile).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(xmlFile, st_mode)

    #Create the output file
    root = etree.Element('Events')

    #Create one subElement per listEntry
    for entry in localIdList:
      if entry[self.LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE] and entry[self.LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP]:
        etree.SubElement(root, "Event", name = entry[self.LOCAL_ID_LIST_KEY_NAME], localID = entry[self.LOCAL_ID_LIST_KEY_VALUE], notInterruptable = '1', useColorSweep = '1')
        
      elif entry[self.LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE] and not entry[self.LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP]:
        etree.SubElement(root, "Event", name = entry[self.LOCAL_ID_LIST_KEY_NAME], localID = entry[self.LOCAL_ID_LIST_KEY_VALUE], notInterruptable = '1')
        
      elif not entry[self.LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE] and entry[self.LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP]:
        etree.SubElement(root, "Event", name = entry[self.LOCAL_ID_LIST_KEY_NAME], localID = entry[self.LOCAL_ID_LIST_KEY_VALUE], useColorSweep = '1')
        
      else:
        etree.SubElement(root, "Event", name = entry[self.LOCAL_ID_LIST_KEY_NAME], localID = entry[self.LOCAL_ID_LIST_KEY_VALUE])

    if os.path.isfile(xmlFile):
      # file already exists - remove writeProtection
      st_mode = os.stat(xmlFile).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(xmlFile, st_mode)

    # Write tree into xmlFile
    tree = open(xmlFile, 'w')
    self.sortChildrenBy(root, 'localID')
    tree.write(self.prettify(root))
    tree.close()

  def generateNonLocalIdXmlFile(self, localIdList, xmlFile, xmlType):
    '''This function generates either a ErrorIDs.xml, a _InternalIDs.xml or the ErrOffsets.xml based on given localIdList
    
       localIdList has to be a list of dictionaries with the following keys: 
          self.LOCAL_ID_LIST_KEY_NAME               -> Has to be a string
          self.LOCAL_ID_LIST_KEY_VALUE              -> Has to be a string             
      
       xmlFile is the file which will be generated. It has to be provided with its full path
       
       xmlType: self.ERROR_ID_XML, self.INTERN_ERROR_ID_XML, self.ERROR_OFFSETS_XML
   
       Preconditions: 
       - The names of the localIDs have to be unique
       - The values of the localIDs have to be unique 
       - The path of given xmlFile has to be valid
    '''

    if self.ERROR_OFFSETS_XML == xmlType:
      ELEMENT_STR     = 'ErrOffsets'
      SUB_ELEMENT_STR = 'ErrOffset'
    elif self.ERROR_ID_XML == xmlType:
      ELEMENT_STR     = 'Ports'
      SUB_ELEMENT_STR = 'Port'
    else:
      ELEMENT_STR     = 'Events'
      SUB_ELEMENT_STR = 'Event'

    root = etree.Element(ELEMENT_STR)

    for entry in localIdList:

      if self.ERROR_ID_XML == xmlType: 
        # It's an errorID XML
        etree.SubElement(root, SUB_ELEMENT_STR, name = entry[self.LOCAL_ID_LIST_KEY_NAME], idx = entry[self.LOCAL_ID_LIST_KEY_VALUE])
      elif self.INTERN_ERROR_ID_XML == xmlType: 
        # It's an internalErrorID XML
        etree.SubElement(root, SUB_ELEMENT_STR, name = entry[self.LOCAL_ID_LIST_KEY_NAME], internalID = entry[self.LOCAL_ID_LIST_KEY_VALUE])
      else: 
        # It's the errorOffset XML 
        etree.SubElement(root, SUB_ELEMENT_STR, name = entry[self.LOCAL_ID_LIST_KEY_NAME], errorOffset = entry[self.LOCAL_ID_LIST_KEY_VALUE])

    # Check whether the localID-file already exists
    if os.path.isfile(xmlFile):
      # file already exists - remove writeProtection
      st_mode = os.stat(xmlFile).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(xmlFile, st_mode)

    # Open and fill (or update) the XML file
    tree = open(xmlFile, 'w')
    tree.write(self.prettify(root))
    tree.close()
