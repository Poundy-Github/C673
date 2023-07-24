import os
import stat
import re

import xml.etree.ElementTree as etree

from GeneratorCommon import GeneratorCommon

class CommentedTreeBuilder(etree.TreeBuilder):
    def comment(self, data):
        self.start(etree.Comment, {})
        self.data(data)
        self.end(etree.Comment)

#################################################################################
#
#################################################################################
class RtaCoresXmlGenerator(GeneratorCommon):

  #Initialize RtaCoresXmlGenerator class
  def __init__(self):
    print ('GenerateRtaCoresXml : object generated!')

  #Extract the absolute path of the DAT file
  def doIt(self, genCfg, inputCfg, errorInfo):
    errorCode       = self.ERR_OK  # @UnusedVariable

    #Create the output file
    errorCode = self.generateRtaCoresXml(genCfg, inputCfg, errorInfo)

    if self.ERR_OK != errorCode:
      print ('errorCode: ' + str(errorCode))

    return errorCode



  ####################################################################################################################################################
  def generateRtaCoresXml(self, genCfg, inputCfg, errorInfo):
    errorCode = self.ERR_OK
    
    #Check whether the file already exists
    rtaCoresXml = os.path.join(inputCfg[self.INPUT_DICT_KEY_OUTPUT_PATH], self.FILE_NAME_RTA_CORES_XML)
    if os.path.isfile(rtaCoresXml):
      # file already exists - remove writeProtection
      st_mode = os.stat(rtaCoresXml).st_mode | stat.S_IWRITE | stat.S_IREAD
      os.chmod(rtaCoresXml, st_mode)
      
      parser = etree.XMLParser(target=CommentedTreeBuilder())
      tree = etree.parse(rtaCoresXml, parser)
      root = tree.getroot()
      
      # remove ranges specified in the configuration file that will be changed in this function
      for entry in genCfg[self.GENCFG_DICT_KEY_CORES]:
        Cores = root.find('.//Cores')
        el = Cores.find('.//Core[@coreID="' + entry[self.CORE_ID] + '"]')
        if not el is None: 
          Cores.remove(el)
    else:
      root = etree.Element('Config')
      root.append(etree.Comment('RTA configuration generated for:'))
      root.append(etree.Comment('Project: {0} {1}'.format(inputCfg[self.INPUT_DICT_KEY_PROJECT], inputCfg[self.INPUT_DICT_KEY_BUILD_UNIT])))

      #Add info about componentIdXml and errorOffsetsXml
      etree.SubElement(root, 'ComponentIDs', file= self.FILE_NAME_COMP_IDS_XML)
      etree.SubElement(root, 'ErrorOffsets', file= self.FILE_NAME_ERROR_OFFSETS_XML)

      Cores = etree.SubElement(root, 'Cores')

    #Add all specified cores
    for entry in genCfg[self.GENCFG_DICT_KEY_CORES]:
      
      if self.ERR_OK == errorCode:
        attributes = {'name':entry[self.CORE_NAME], 'coreID':entry[self.CORE_ID]}
        #Check whether we have to add the attribute "Group"
        #Check whether we have to add the attributes "wakeupComponent" and "wakeupMarker"
        if ( len(entry[self.GROUP_NAME].strip()) != 0 ):
          attributes['group'] = entry[self.GROUP_NAME].strip()
        else:
          attributes['group'] = 'noGroupSpecified'

        if ( len(entry[self.WAKEUP_COMP].strip()) != 0 ) & ( len(entry[self.WAKEUP_MARKER].strip()) != 0 ):
          attributes['wakeupComponent'] = entry[self.WAKEUP_COMP]
          attributes['wakeupMarker'] = entry[self.WAKEUP_MARKER]

        attrIgnoreLocalIdStrings = entry[self.IGNOR_LOCAL_ID_STRINGS].strip()
        if ( (len(attrIgnoreLocalIdStrings) != 0) and (attrIgnoreLocalIdStrings == '1') ):
          attributes['ignoreLocalIdStrings'] = '1'

        #Add a new coreElement
        Core = etree.SubElement(Cores, 'Core' , attributes)

        # Check whether we have an OS at all
        if self.OS_TYPE_NONE != inputCfg[self.INPUT_DICT_KEY_OS_TYPE]:
          # add task elements if there is a osConfigFile provided
          if len(entry[self.OS_CFG_FILE]) != 0:
            #Add comment
            Core.append(etree.Comment('All tasks:'))
  
            myList = []
            #Add the interrupts which are treated as one "Thread"
            myList.append(['Interrupts', '0'])
            
            #Get the taskIdLut headerFile
            taskIDLut_h = os.path.join(inputCfg[self.INPUT_DICT_KEY_LUT_CFG_FILE_PATH], self.TASK_LUT_FILE_NAME)
  
            #Get all tasks from the osConfigFile
            #Determine whether we have a sysBios or any other OS
            if self.OS_TYPE_SYS_BIOS == inputCfg[self.INPUT_DICT_KEY_OS_TYPE]:
              #we have sysBios - call the function for sysBios
              errorCode = self.getAllTasks_Sysbios(myList, entry[self.OS_CFG_FILE], errorInfo)
            else:
              #Either we have a EB OS, a EB_S_OS or a VectorOS. In all these cases we have a os_rta_taskid_lut_cfg.h in which we find all required 
              #information required to tasks 
              errorCode = self.getAllTasksFromTaskIdLutHeader(myList, taskIDLut_h, entry[self.OS_CORE_ID], inputCfg[self.INPUT_DICT_KEY_RTA_TASK_IDS_H], errorInfo)
  
            #Create one subElement per listEntry
            for element in myList:
              etree.SubElement(Core, "Task", name=element[0], taskID=element[1])

        #Check if there is a barChart for this core provided
        if len(entry[self.BARCHART_XML].strip()) != 0:
          #Add comment
          Core.append(etree.Comment('The barChartXml:'))
          # Create related subElement
          etree.SubElement(Core, 'BarCharts',  file= entry[self.BARCHART_XML])

    if self.ERR_OK == errorCode:
      #Open and fill (or update) the file
      tree = open(rtaCoresXml, 'w')
      self.sortChildrenBy(Cores, 'coreID')
      tree.write(self.prettify(root))
      tree.close()

    return errorCode

  #Get all tasks from osConfigFile for sysBios ############################################################################################################
  def getAllTasks_Sysbios(self, myList, osConfigFile, errorInfo):
    errorCode = self.ERR_OK

    #Check if osConfigFile exists at given location
    if not os.path.isfile(osConfigFile):
      #File not found
      errorCode = self.ERR_OS_CFG_FILE_NOT_FOUND
      errorMsg = 'Please ensure that the following file is available: \n\n{0}'.format(osConfigFile)
      #Provide errorMessage to caller
      errorInfo.extend(errorMsg)
    else:
      #Read all lines of the osConfigFile
      osFile = open(osConfigFile)
      lines = osFile.readlines()
      osFile.close()

      #All available values for 'state'
      lookForNextTaskDef  = 0
      lookForTaskName     = 1
      lookForTaskID       = 2
      queryTaskDef = 'new Task.Params()'
      queryTaskName = '.instance.name'
      queryTaskID = 'arg1'
      state = lookForNextTaskDef
      name = ''
      value = ''
      #Look for all tasks
      for line in lines:
        if state == lookForNextTaskDef:
          if line.find(queryTaskDef) != - 1:
            #Start of new taskDefinition found - change state
            state = lookForTaskName
        elif state == lookForTaskName:
          if line.find(queryTaskName) != -1:
              #Line containing the taskName found - take out only the taskName which is within "  "
              name = line[line.find('"')+1:line.rfind('"')]
              #Change state
              state = lookForTaskID
        else:
          #Look for taskID
          if line.find(queryTaskID) != -1:
            #Line containing taskID found - take out only the id value
            value = line[line.find('=')+1:line.rfind(';')]
            value = value.strip()
            #Add name an value to the list
            myList.append([name, value])
            #reset state in order to look for the next task definition
            state = lookForNextTaskDef
      #remove double entries which are eventually exists
      self.removeDoubleEntriesFromList(myList)
      # Add idleTask which has a special treatment in sysBios
      myList.append (['IS_TASK_HANDLE_IDLE','160'])
    return errorCode

  ##############################################################################################################################################################################################
  def removeDoubleEntriesFromList(self, listToClean):

    multiEntries = []
    idx2Remove   = []
    #find double entries
    for i in range(len(listToClean)):
      noEqualEntries = listToClean.count(listToClean[i])
      if 1 < noEqualEntries:
        #Check if this entry has already been identified as a multiple entry
        if (multiEntries.count(listToClean[i]) + 1) < noEqualEntries:
          idx2Remove.append(i)
          multiEntries.append(listToClean[i])

    #remove double entries
    idx2Remove.reverse()
    for idx in idx2Remove:
      del listToClean[idx]


  #Get all tasks from taskIDLut_h  ############################################################################################################
  def getAllTasksFromTaskIdLutHeader(self, myList, taskIDLut_h, osCoreID, rtaTaskIDs_h, errorInfo):
    errorCode = self.ERR_OK

    #Check whether all required files are found
    if not os.path.isfile(rtaTaskIDs_h):
      #os_rta_task_ids.h not found - set related errorCode
      errorCode = self.ERR_RTA_TASK_IDS_HEADER_NOT_FOUND
      errorMsg = 'Please ensure that the file is available at the following location: \n\n{0}'.format(rtaTaskIDs_h[:rtaTaskIDs_h.rfind('/')])
      #Provide errorMessage to caller
      errorInfo.extend(errorMsg)
    elif not os.path.isfile(taskIDLut_h):
      #TaskLut file not found - set related errorCode
      errorCode = self.ERR_RTA_TASK_ID_LUT_CFG_FILE_NOT_FOUND
      errorMsg = 'Please ensure that the file is available at the following location: \n\n{0}'.format(taskIDLut_h[:taskIDLut_h.rfind('/')])
      #Provide errorMessage to caller
      errorInfo.extend(errorMsg)

    else:
      taskList                 = []
      taskIDList               = []
      listOsTaskIdAndRtaTaskId = []

      #Get the taskList(containing pairs of osTaskIDs and rtaTaskIDs) and the taskIDList (containing pairs of rtaTaskIDs and values)
      self.getTaskIDList(taskIDList, rtaTaskIDs_h)
      self.getTaskList(listOsTaskIdAndRtaTaskId, taskIDLut_h)

      for entry in listOsTaskIdAndRtaTaskId:
        #We have a multiCoreOS - filtered by coreID
        if osCoreID == entry[self.IDX_TASKLIST_OS_CORE_ID]:
          taskList.append(entry[self.IDX_TASKLIST_RTA_TASK_ID])

      #Remove double entries which may be in the list
      #Note: taskList is sorted by priority. The removeDoubleEntriesFromList-Function removes always the first element incase  we have doubles
      # Therefore we reverse the list before and after calling the removeDouble-Fct to have the latest entry removed
      taskList.reverse()
      self.removeDoubleEntriesFromList(taskList)
      taskList.reverse()

      #Now loop over the lut and find related entry in taskIDList
      for taskListEntry in taskList:
        found = False
        for taskIDEntry in taskIDList:
          if taskListEntry == taskIDEntry[0]:
            # Related entry in tasIDList found, append it to myList
            myList.append([taskIDEntry[0].replace(self.PREFIX_RTA_TASK_IDS, 'TASK_'), taskIDEntry[1]])
            found = True
        #Check whether we found related entry, if not set related errorCode
        if not found:
          errorCode = self.ERR_RTA_TASK_ID_NOT_FOUND
          print ('ID not found: ' + str(taskListEntry))

    return errorCode

  #Extract all existing rtaTaskIDs from the file os_rta_task_ids.h #####################################################################################################
  def getTaskIDList(self, taskIDList, rtaTaskIDs_h):

    #Read all lines of the file os_rta_task_ids.h
    inputFile = open(rtaTaskIDs_h)
    lines = inputFile.readlines()
    inputFile.close()

    inRegionOfInterrest = False
    
    for line in lines:
      if not inRegionOfInterrest:
        if (-1 != line.find(self.GEN_TAG_TASK_IDS_ENUM_START)):
          #Now we reached the beginning of the interresting section whihin this file
          inRegionOfInterrest = True
      else:
        #Check whether this line contains a enumeration literal describing a rtaTaskID
        PATTERN_TASK_LITERAL = r' *(OS_RTA_TASKID_\S+) *= *(\d+)' # group(1) is taskName, group (2) is idValue
        obj = re.match(PATTERN_TASK_LITERAL, line)
        if obj:
          #append it to the list
          taskIDList.append([obj.group(1), obj.group(2)])
        #check whether we reached the end of interessting section within this file
        elif -1 != line.find(self.GEN_TAG_TASK_IDS_ENUM_END):
          #OK - we are at the end of interessting section - update state
          break

