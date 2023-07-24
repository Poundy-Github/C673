import os
import stat
import xml.etree.ElementTree as etree

from InstrGeneratorBase import InstrGenBase
#################################################################################
#
#################################################################################
class RteLocalIdXmlGenerator(InstrGenBase):

  #Initialise the class################################################################################################################################################################################
  def __init__(self, xmlPath):
    self.infoTxt = []
    self.infoTxt.append(xmlPath)
    print ("RteLocalIdXmlGenerator")
    #Get the outputPath for the XMLs
    self.xmlPath = xmlPath
    print ('self.xmlPath:' + str(self.xmlPath))


  #####################################################################################################################################################################################################
  def generateLocalIdXmls(self, taskInfo):

    # Generate one XML-File per task
    allTasks = list(taskInfo.keys())

    for task in allTasks:
      localIdList = list()
      localIdDict = dict()
      # Set noneInterruptable and colorSweep keys to False as they are always false
      localIdDict[self.LOCAL_ID_LIST_KEY_NONE_INTERRUPTABLE] = False
      localIdDict[self.LOCAL_ID_LIST_KEY_USE_COLOR_SWEEP   ] = False
            
      # Get the fileName and assemble the whole path
      file_name = self.assembleNameForXmlFile(taskInfo[task]['enumName'], self.LOCAL_ID_XML)
      xmlFile = os.path.join(self.xmlPath,file_name)
      
      # Get taskrunTimeLiteral
      literal = self.createTaskRuntimeLocalID(taskInfo[task]['taskName'])
      # Clean the literal - remove prefixes
      literal = self.cleanEnumLiteral(literal, file_name)

      # Fill the dictionary and append it to the final list  
      localIdDict[self.LOCAL_ID_LIST_KEY_NAME ] = literal
      localIdDict[self.LOCAL_ID_LIST_KEY_VALUE] = str(0)

      localIdList.append(localIdDict) 

      # Add the literals for all the runnables
      for i in range(len(taskInfo[task]['runnableCfgList'])):
        literal = taskInfo[task]['runnableCfgList'][i][self.INDEX_LOCAL_ID]
        # Clean the literal - remove prefixes
        literal = self.cleanEnumLiteral(literal, file_name)

        # Fill the dictionary and append it to the final list  
        localIdDict[self.LOCAL_ID_LIST_KEY_NAME ] = literal
        localIdDict[self.LOCAL_ID_LIST_KEY_VALUE] = str(i + 1)
  
        localIdList.append(localIdDict) 
    
      # Have the localIdXmlFile generated 
      self.generateLocalIdXmlFile(localIdList, xmlFile)

