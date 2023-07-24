import os
import re
import xml.etree.ElementTree as etree

from GeneratorCommon import GeneratorCommon

#################################################################################
# Extract enum information from DAT files to generate separate enum output files
#################################################################################
class LocalIdXmlGenerator(GeneratorCommon):

  STR_TYPE_REF                               = 'typeref'
  STR_TYPE_ENUM                              = 'enum'
  STR_GENERATOR_TAG_LOCAL_ID_ENUM            = 'RTA_LOCAL_ID_FOR_XML_GENERATION'
  STR_GENERATOR_TAG_ERROR_ID_ENUM            = 'RTA_PRTID_FOR_XML_GENERATION'
  STR_GENERATOR_TAG_INTERN_ERROR_ID_ENUM     = 'RTA_INTERNAL_ID_FOR_XML_GENERATION'
  STR_GENERATOR_TAG_ERROR_OFFSET_ENUM        = 'RTA_ERROFFSET_ID_FOR_XML_GENERATION'

  #Initialize RTA_XmlGenerator class
  def __init__(self):
    print ('GenerateLocalIdXmls : object generated')


  #
  def doIt(self, genCfg, inputCfg):

    # In case no datFile is provided genCfg[self.GENCFG_DICT_KEY_DAT_FILES] is None
    # Note: For easy debugging it might be the case that no datFile is delivered
    if genCfg[self.GENCFG_DICT_KEY_DAT_FILES]:
      # Get the outputPath 
      outputPath = inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH]
      #Generate the localIDXmlFiles
      for filepath in genCfg[self.GENCFG_DICT_KEY_DAT_FILES]:
        tree = etree.parse(filepath)
        root = tree.getroot()
        listTypeRefEnums = []
  
        for elem in root:
          for items in elem.findall('.//COMMENT'):                    #check for all 'COMMENT' nodes in DAT file
            s_items = items.text.strip('\t\n')
            #Determine xmlFileType to be generated 
            if re.search(self.STR_GENERATOR_TAG_LOCAL_ID_ENUM, s_items):   
              xmlType = self.LOCAL_ID_XML
            elif re.search(self.STR_GENERATOR_TAG_ERROR_ID_ENUM, s_items): 
              xmlType = self.ERROR_ID_XML
            elif re.search(self.STR_GENERATOR_TAG_INTERN_ERROR_ID_ENUM, s_items): 
              xmlType = self.INTERN_ERROR_ID_XML
            elif re.search(self.STR_GENERATOR_TAG_ERROR_OFFSET_ENUM, s_items): 
              xmlType = self.ERROR_OFFSETS_XML
            else:
              #No XML to be generated! 
              xmlType = self.NO_XML
                          
            if self.NO_XML !=  xmlType:          
              list_enumVariable_value = []                        #List for enum variable and their values
              enum_name = elem.attrib['name']                     #get the enumeration name
              for child in elem:
                if 'TLE' in child.tag:
                  if self.STR_TYPE_ENUM == child.attrib['type']:
                    #OK it is an enumeration - get all literals
                    for children in child:
                      enumVariable = children.attrib['name']            #get the member name
                      value = children.attrib['value']                  #get the member value
                      if list(children):
                        for subchildren in children.iter('COMMENT'):
                          comment = subchildren.text.strip('\t\n')
                          list_enumVariable_value.append((enumVariable, value, comment))
                      else:
                        list_enumVariable_value.append((enumVariable, value, ''))
  
                    if len(list_enumVariable_value):
                      #OK - we got some literals - create the related XML
                      self.generate_output(outputPath, enum_name, list_enumVariable_value, xmlType)
                  elif self.STR_TYPE_REF == child.attrib['type']:
                    #It's a typeRef
                    #Add an new listElement containing enumName and def_type
                    listTypeRefEnums.append([enum_name, child.attrib['def_type'], xmlType])
                  break #Terminate loop [for child in elem:]
              break #Terminate the loop immediately [for items in elem.findall('.//COMMENT'):]
  
        #Run the special treatment for "typeRefEnums" if needed
        if len(listTypeRefEnums):
          for elem in root:
            name = elem.get('name')
            for entry in listTypeRefEnums:
              if name == entry[1]:
                list_enumVariable_value = []                            #List for enum variable and their values
                for child in elem:
                  if 'TLE' in child.tag:
                    enum_name = entry[0]                     #get the enumeration name from the list
                    for children in child:
                      enumVariable = children.attrib['name']            #get the member name
                      value = children.attrib['value']                  #get the member value
  
                      if list(children):
                        for subchildren in children.iter('COMMENT'):
                          comment = subchildren.text.strip('\t\n')
                          list_enumVariable_value.append((enumVariable, value, comment))
                      else:
                        list_enumVariable_value.append((enumVariable, value, ''))
                    if len(list_enumVariable_value):
                      self.generate_output(outputPath, enum_name, list_enumVariable_value, entry[2])
                  break # Terminate loop [for child in elem:]
                break #Terminate loop [for entry in listTypeRefEnums:]

    return self.ERR_OK
  
  
########################################
  #Create a new output file for every enumeration
  def generate_output(self, outputPath, enum_name, list_enumVariable_value, xmlType):

    # Get the fileName
    file_name = self.assembleNameForXmlFile(enum_name, xmlType)
    
    #Check whether we got a fileName - for sake of safety 
    if len(file_name):
      # Assemble file name and path
      xmlFile = os.path.join(outputPath,file_name)

      localIdList = list()
      for entry in list_enumVariable_value:
        localIdDict = dict()

        # Fill the dictionary and append it to the final list  
        localIdDict[self.LOCAL_ID_LIST_KEY_NAME ] = self.cleanEnumLiteral(entry[0], file_name)
        localIdDict[self.LOCAL_ID_LIST_KEY_VALUE] = entry[1]
        
        if (-1 != entry[2].find('RTA_XML_GEN_PARAMS')) and (-1 != entry[2].find('non-interruptible')):
          localIdDict[self.LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE] = True
        else:
          localIdDict[self.LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE] = False
        
        if (-1 != entry[2].find('RTA_XML_GEN_PARAMS')) and (-1 != entry[2].find('useColorSweep')):
          localIdDict[self.LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP   ] = True
        else:
          localIdDict[self.LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP   ] = False
  
        localIdList.append(localIdDict)
      
      if self.LOCAL_ID_XML == xmlType: 
        # Have the localIdXmlFile generated 
        self.generateLocalIdXmlFile(localIdList, xmlFile)

      else:
        self.generateNonLocalIdXmlFile(localIdList, xmlFile, xmlType)        
