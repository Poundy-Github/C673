import os
import sys
import argparse
import re

try:
# python 2
    import Tkinter as tk
    import tkMessageBox as tkinter_messagebox
except ImportError:
# python 3
    import tkinter as tk
    import tkinter.messagebox as tkinter_messagebox

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + '/../ToolChainCommon')
from ChainCommon import ChainCommon

#################################################################################
#
#################################################################################
class RtaGlobalIDGenerator(ChainCommon):

  #All errors/warnings related to adding new globalIDs
  ERR_ADD_ID_OK                         = 0
  ERR_ADD_ID_GIVEN_ID_OUT_OF_RANGE      = 1
  ERR_ADD_ID_GIVEN_ID_ALREADY_IN_USE    = 2
  ERR_ADD_ID_TOO_MANY_GLOBAL_IDS        = 3
  ERR_ADD_ID_NAME_ALREADY_IN_USE        = 4

  #The error Messages Dictionary
  errorMsgDictAddNewGlobalIDs = \
  {
    ERR_ADD_ID_OK                      : 'Everything OK - new globalID added!',
    ERR_ADD_ID_GIVEN_ID_OUT_OF_RANGE   : 'Desired ID is out of range (max value is 4000!) The next free ID has been taken.',
    ERR_ADD_ID_GIVEN_ID_ALREADY_IN_USE : 'Desired ID is already in use. The next free ID has been taken.',
    ERR_ADD_ID_TOO_MANY_GLOBAL_IDS     : 'The max. number of globalIDs has been reached. No more IDs can be added.',
    ERR_ADD_ID_NAME_ALREADY_IN_USE     : 'There is already a globalID with desired name. Please chose any other name!',
 }


  #The indexes for the GlobalID-List
  ID_LIST_IDX_NAME      = 0
  ID_LIST_IDX_VALUE     = 1
  ID_LIST_IDX_COMMENT   = 2

  #List of all globalIDs inclusive value and comment
  #     [[ID_LIST_IDX_NAME],[ID_LIST_IDX_VALUE],[ID_LIST_IDX_COMMENT]]
  idList = []

  IDS_HEADER_TXT = '''
//  Number of free globalIDs: {0}
//  Note: For the globalIDs we have a 12 bit range -> 4096 IDs. 
//        The range 4000 ... 4095 is reserved for the RTE GlobalIDs. 

#ifndef __cplusplus

''' # {0} -> number of free global IDs

  IDS_MID_TXT = '''
  
#else // #ifndef __cplusplus

'''

  IDS_TRAILOR_TXT = '''
#endif // #ifndef __cplusplus

'''

  ID_DEFINE_LINE            ='#define {0} ((RTA_t_GlobalID){1})  ///< {2}\n' # {0} -> Name, {1} -> Value, {2} -> Comment
  ID_DEFINE_LINE_NO_COMMENT ='#define {0} ((RTA_t_GlobalID){1})\n'           # {0} -> Name, {1} -> Value
  
  ID_STATIC_CONST_LINE            ='static const RTA_t_GlobalID {0} = (RTA_t_GlobalID){1};  ///< {2}\n' # {0} -> Name, {1} -> Value, {2} -> Comment
  ID_STATIC_CONST_LINE_NO_COMMENT ='static const RTA_t_GlobalID {0} = (RTA_t_GlobalID){1};\n'           # {0} -> Name, {1} -> Value


  ################################################################################################################################################################
  def __init__(self):
    try:
      args = self.check_args()

      self.headerFile = args.rta_globalids_path
      if os.path.isfile(self.headerFile):
        linesHeaderFile = self.getLinesOfFile(self.headerFile)
        #Check the file
        if self.isGlobalIDHeaderFileValid(linesHeaderFile):
          # Get a list of all globalIDs and check it for doubles and range 
          self.getIDListAndCheckIt(linesHeaderFile)

        else:
          raise Exception ("The rta_globalids.h is not valid, generatorTags are missing!")
      else:
        raise Exception ("The rta_globalids.h could not be found.")

      print ('#Run the generator')
      self.doIt()
    except Exception as ex:
      self.generateUserErrorInfo(str(ex))

# argument parsing ############################################################################
  def check_args(self):
    parser = argparse.ArgumentParser(prog="RtaGlobalIDGenerator",
                                     formatter_class=argparse.RawTextHelpFormatter,
                                     description="Generate RTA Global IDs")
    parser.add_argument("rta_globalids_path",
                        action="store",
                        help="Location of the rta_globalids.h file")
    return parser.parse_args()

  ################################################################################################################################################################
  def getIDListAndCheckIt(self, linesHeaderFile):

    linesBelowStartTag = []

    #Get the lines after the startTag
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_GLOBAL_ID_START, linesHeaderFile, linesBelowStartTag)

    for line in linesBelowStartTag:
      # find lines with globalID defines
      

      obj = re.match(self.GLOBAL_ID_DEFINE_SEARCH_PATTERN, line)
      if obj:
        # This is a line defining a globalID -> extract name, value and comment
        name    = obj.group(1)
        value   = int(obj.group(2))
        comment = obj.group(3)
        
        # Add the found id to the list - if it is not the INVALID_GLOBAL_ID. The INVALID_GLOBAL_ID will be added again just before the file is written
        self.idList.append([name, value, comment])
          
      elif -1 != line.find(self.GEN_TAG_GLOBAL_ID_END):
        # section end reached, terminate the loop
        break

    #check for doubleEntries
    self.checkForDoubleEntries()
    
    # Check for IDs which are out or range 
    self.checkForOutOfRangeIDs()
     
    # Sort the globalID list by values  
    self.sortListByIDValue(self.idList)


  def checkForOutOfRangeIDs(self):
    '''This function checks whether there are IdValues in the file which are out of range.
    '''
    for entry in self.idList:
      if self.RTE_GLOBAL_IDS_RANGE_START <= entry[self.ID_LIST_IDX_VALUE]:
        raise Exception ('Value {0} of ID {1} is out of range'.format(entry[self.ID_LIST_IDX_VALUE], entry[self.ID_LIST_IDX_NAME]))
        break
        

  def checkForDoubleEntries(self):
    '''This function checks whether there are double IDs in the file. It checks 
       for double names and for double values as well. 
    '''
    #Get a list of all values and another list with all names 
    valueList = []
    nameList  = []
    for entry in self.idList:
      valueList.append(entry[self.ID_LIST_IDX_VALUE])
      nameList.append(entry[self.ID_LIST_IDX_NAME])

    #Check for double values
    doubleListValue = []
    for entry in valueList:
      #Check if this entry is more than once in the list and not in the doubleList yet
      if 1 < valueList.count(entry) and not doubleListValue.count(entry):
        doubleListValue.append(entry)
        print ('Double values:' + str(entry))

    #Check for double names
    doubleListName = []
    for entry in nameList:
      #Check if this entry is more than once in the list and not in the doubleList yet
      if 1 < nameList.count(entry) and not doubleListName.count(entry):
        doubleListName.append(entry)
        print ('Double names:' + str(entry))

    if len(doubleListValue):
      raise Exception ("We have at least two IDs with the same value!!")
     
    elif len(doubleListName):
      raise Exception ("We have at least two IDs with the same name!!")


  #Sort the list by value of entries in increasing order ######################################################################################################################
  def sortListByIDValue(self, listToSort):
    swapped    = True

    while swapped:
      swapped = False
      i = 0
      for i in range (len(listToSort) - 1):
        if (listToSort[i + 1][self.ID_LIST_IDX_VALUE]) < (listToSort[i][self.ID_LIST_IDX_VALUE]):
          #Swap both indexes
          entry = listToSort.pop(i+1)
          listToSort.insert(i, entry)
          print ('Sort!!!')
          swapped = True


  ################################################################################################################################################################
  def generateUserErrorInfo(self, errorExpl):
    print ('ErrorCode: ' + str(errorExpl))
    #Create errorWindow
    tkinter_messagebox.showerror("RtaGlobalIDGenerator", errorExpl)


  ################################################################################################################################################################
  def doIt(self):
    #Generate a the rootWindow to keep the GUI alive
    self.root = tk.Tk()

    self.root.title('The globalID generator')
    self.root.minsize(200,100)
    self.root.maxsize(200,100)

    self.confirmWindowOpen    = False
    self.addNewIdWindowOpen   = False
    self.newIdName            = tk.StringVar()
    self.newIdValue           = tk.StringVar()
    self.newIdComment         = tk.StringVar()


    rowCnt = 0

    AddIdButton = tk.Button(self.root, text = 'Add new GlobalID', command = self.fctAddGlobalIdButton)
    AddIdButton.grid(row = rowCnt, columnspan = 2, pady = 10, padx = 4, sticky = 'news')
    rowCnt += 1

    OkButton = tk.Button(self.root, text = 'OK', command = self.fctGlobalIdOkButton)
    OkButton.grid(row = rowCnt, ipadx = 20, pady = 20, padx = 4, sticky = 'news')

    CancelButton = tk.Button(self.root, text = 'CANCEL', command = self.fctGlobalIdCancelButton)
    CancelButton.grid(row = rowCnt, column = 1, ipadx = 10, pady = 20, padx = 4, sticky = 'news')

    #Draw globlaIdListWindow
    self.drawGlobalIDListWindow()

    #Wait for user interaction
    self.root.mainloop()

  ################################################################################################################################################################
  def refreshGlobalIDListWindow(self):
    #Destroy mainWindow
    self.globalIDListWindow.destroy()
    #And draw it new
    self.drawGlobalIDListWindow()

  ################################################################################################################################################################
  def drawGlobalIDListWindow(self):
    #Generate a new Toplevel-Window
    self.globalIDListWindow = tk.Toplevel()
    rowCnt = 0

    #Add an empty line
    label = tk.Label(self.globalIDListWindow, text = '')
    label.grid(row = rowCnt)
    rowCnt += 1

    #Add the headerLine
    label = tk.Label(self.globalIDListWindow, text = 'Current list of rtaGlobalIDs: ')
    label.grid(row = rowCnt)
    rowCnt += 1

    #Add an empty line
    label = tk.Label(self.globalIDListWindow, text = '')
    label.grid(row = rowCnt)
    rowCnt += 1

    #Create a frame for the canvas to be scrolled
    canvasFrame = tk.Frame(self.globalIDListWindow)
    canvasFrame.grid(row = rowCnt,  columnspan = 4, sticky= 'nw')
    canvasFrame.grid_rowconfigure(0, weight=1)
    canvasFrame.grid_columnconfigure(0, weight=1)
    # Set grid_propagate to False to allow resizing later
    canvasFrame.grid_propagate(False)

    #create the canvas in the canvasFrame
    canvas = tk.Canvas(canvasFrame)
    canvas.grid(sticky = 'news')
    #Create the scrollbar in the canvasFrame
    scrollbar = tk.Scrollbar(canvasFrame, orient = 'vertical', command = canvas.yview)
    scrollbar.grid(row = 0, column = 1,sticky = 'ns')
    canvas.configure(yscrollcommand = scrollbar.set)
    #Create a frame to contain the list of current globalIDs
    idListFrame = tk.Frame(canvas)
    canvas.create_window((0, 0), window = idListFrame, anchor='nw')

    #Create the table header line
    label = tk.Label(idListFrame, text = 'Name')
    label.grid(row = rowCnt, column = 0, sticky = 'w')
    label = tk.Label(idListFrame, text = 'Value')
    label.grid(row = rowCnt, column = 1, sticky = 'w')

    #Add an empty line
    rowCnt += 1
    label = tk.Label(idListFrame, text = '')
    label.grid(row = rowCnt)
    rowCnt += 1

    #Create a table of all current globalIDs
    for entry in self.idList:
      label = tk.Label(idListFrame, text = entry[self.ID_LIST_IDX_NAME])
      label.grid(row = rowCnt, column = 0, sticky = 'w')
      label = tk.Label(idListFrame, text = entry[self.ID_LIST_IDX_VALUE])
      label.grid(row = rowCnt, column = 1, sticky = 'e')
      rowCnt += 1

    # Update buttons frames idle tasks to let tkinter calculate buttons sizes
    # This is needed to make bbox info available
    idListFrame.update_idletasks()

    #Resize the canvasFrame
    canvasFrame.configure(height = min(500, idListFrame.winfo_height()), width = idListFrame.winfo_width() + scrollbar.winfo_width()+ 5)

    # Set the canvas scrolling region
    canvas.config(scrollregion = canvas.bbox("all"))

    #Add an empty line
    rowCnt += 1
    label = tk.Label(self.globalIDListWindow, text = '')
    label.grid(row = rowCnt)




  ################################################################################################################################################################
  def fctAddGlobalIdButton(self):

    if not self.addNewIdWindowOpen:
      self.addNewIdWindowOpen = True
      rowCnt = 0
      #Reset the textFieldVariable
      self.newIdName.set('')
      self.newIdValue.set('')
      self.newIdComment.set('')

      #Create a new window to enter the text
      self.addNewIdWindow = tk.Toplevel()
      self.addNewIdWindow.title('Create a new globalID')
      self.addNewIdWindow.minsize(600,80)

      #Create infoText for the nameField
      infoText = tk.Label(self.addNewIdWindow, text = 'Please enter the name of the new globalID without the prefix "{0}" (!!!mandatory!!!)'.format(self.GLOBAL_ID_NAME_PREFIX))
      infoText.grid(row = rowCnt, columnspan = 110, pady = 10, sticky = 'ws')
      rowCnt += 1
      #Create the entryField for the name
      entryField = tk.Entry(self.addNewIdWindow, textvariable = self.newIdName, width = 50)
      entryField.grid(row = rowCnt, columnspan = 10, sticky = 'wn')
      rowCnt += 3

      #Create infoText for the valueField
      infoText = tk.Label(self.addNewIdWindow, text = 'Please enter the preferred value for the globalID (optional)')
      infoText.grid(row = rowCnt, columnspan = 10, pady = 10, sticky = 'ws')
      rowCnt += 1
      #Create the entryField for the value
      entryField = tk.Entry(self.addNewIdWindow, textvariable = self.newIdValue, width = 50)
      entryField.grid(row = rowCnt, columnspan = 10, sticky = 'wn')
      rowCnt += 3

      #Create infoText for the commentField
      infoText = tk.Label(self.addNewIdWindow, text = 'Please enter the description of the new globalID (optional)')
      infoText.grid(row = rowCnt, columnspan = 10, pady = 10, sticky = 'ws')
      rowCnt += 1
      #Create the entryField
      entryField = tk.Entry(self.addNewIdWindow, textvariable = self.newIdComment, width = 200)
      entryField.grid(row = rowCnt, columnspan = 10, sticky = 'wn')
      rowCnt += 1

      OkButton = tk.Button(self.addNewIdWindow, text = 'OK', command = self.fctAddNewIdOkButton)
      OkButton.grid(row = rowCnt, pady = 10, padx = 4, sticky = 'news')

      QuitButton = tk.Button(self.addNewIdWindow, text = 'QUIT', command = self.fctAddNewIdQuitButton)
      QuitButton.grid(row = rowCnt, column = 1, ipadx = 10, pady = 10, padx = 4, sticky = 'news')


  ################################################################################################################################################################
  def fctAddNewIdOkButton(self):

    #Get all the strings from the entryFields
    name    = self.newIdName.get()
    value   = self.newIdValue.get()
    comment = self.newIdComment.get()

    #convert to upperCases and remove leading and trailing spaces 
    name = name.upper()
    name = name.strip()
    #remove prefix from the name - if given (common error while entering the name of the globalID 
    if name.startswith(self.GLOBAL_ID_NAME_PREFIX):
      name = name.replace(self.GLOBAL_ID_NAME_PREFIX, '')

    #Check if we got at least a name for the new globalID
    if len(name):
      #remove spaces from value
      value = value.replace(' ','')
      if len(value) and not str(value).isdigit():
          #Provided value is not a number!
          tkinter_messagebox.showinfo("Information", 'Provided value is not a number. Please Please enter a number of leave it empty!')
      else:
        errorCode = self.addNewGlobalID(name, value, comment)
        if (   self.ERR_ADD_ID_TOO_MANY_GLOBAL_IDS == errorCode
            or self.ERR_ADD_ID_NAME_ALREADY_IN_USE == errorCode):
          #Range exceeded - create an error Window
          errorExpl = self.errorMsgDictAddNewGlobalIDs.get(errorCode, 'Unknown error!!')
          tkinter_messagebox.showerror("Error!!", errorExpl)
        else:
          # GlobalID added create infoWindow according returnValue
          infoExpl = self.errorMsgDictAddNewGlobalIDs.get(errorCode, 'Unknown info!!')
          tkinter_messagebox.showinfo("Information", infoExpl)
          #Refresh the window
          self.refreshGlobalIDListWindow()

        if self.ERR_ADD_ID_NAME_ALREADY_IN_USE != errorCode:
          #Destroy the window an reset the flag
          self.addNewIdWindow.destroy()
          self.addNewIdWindowOpen = False

    else:
      #No name entered!
      tkinter_messagebox.showinfo("Information", 'Please enter at least the name of desired globalID - or press "QUIT"!!')


  ################################################################################################################################################################
  def addNewGlobalID(self, name, value, comment):
    print ('value: ' + str(value))
    error = self.ERR_ADD_ID_OK

    #First of all check if there are still free IDs in the range
    if self.RTE_GLOBAL_IDS_RANGE_START <= len(self.idList):
      #We reached already the maximal number of globalIDs!!
      error = self.ERR_ADD_ID_TOO_MANY_GLOBAL_IDS
    else:
      #There are still free IDs available - ensure that given name is not in use already
      nameList = []
      for entry in self.idList:
        nameList.append(entry[self.ID_LIST_IDX_NAME])
    #Convert given name into capital letters and add the prefix
      name = self.GLOBAL_ID_NAME_PREFIX + name.upper()
      if 0 < nameList.count(name):
        #Given name is already in use
        error = self.ERR_ADD_ID_NAME_ALREADY_IN_USE
      else:
        #Everything is ok so far - new globalID can be added
        useProvidedID = False
        idx           = 0

        #Check if we got a preferred ID
        if len(value):
          #Convert value string -> int
          print ('value provided: ' + str(value))
          value = int(value)
          if self.RTE_GLOBAL_IDS_RANGE_START > value:
            for entry in self.idList:
              if value == entry[self.ID_LIST_IDX_VALUE]:
                #Preferred Id can be used, we have already an globalID with that value
                error = self.ERR_ADD_ID_GIVEN_ID_ALREADY_IN_USE
                break
            else:
              #Preferred ID can be used
              useProvidedID = True
          else:
            error = self.ERR_ADD_ID_GIVEN_ID_OUT_OF_RANGE

        print ('useProvidedID: ' + str(useProvidedID))
        if useProvidedID:
          #Look for the right place in the current list - it has to be in increasing order
          for idx in range(len(self.idList)):
            if value < self.idList[idx][self.ID_LIST_IDX_VALUE]:
              #Ok - the new ID shall be inserted after the current index
              print ('Location found to insert the new id - idx: {0}'.format(idx))
              #Terminate the loop immediately, to keep the index unchanged for later instertion of the new ID
              break
          else:
            print ('Add new id at the end of the list - idx: {0}'.format(idx))
            #increment index to ensure that new id is add at the end of the list
            idx += 1
        else:
          #No preferred value - just determine the next free value and also the correct place in the list
          #Check if the list starts with the value 0
          # If it does not start with 0 then the new globalID shall be insterted at index 0 with value 0
          if len(self.idList) and (0 == self.idList[0][self.ID_LIST_IDX_VALUE]):
            #Ok the value 0 is already in use - look for the next gap in the list
            for idx in range(1, len(self.idList)):
              if self.idList[idx-1][self.ID_LIST_IDX_VALUE]+1 < self.idList[idx][self.ID_LIST_IDX_VALUE]:
                #Ok, there is a gap - the new globalID shall be inserted at current index
                #Terminate the loop immediately to to keep the index unchanged for later instertion of the new ID
                break
            else:
              #increment index to ensure that new id is add at the end of the list
              idx += 1

          #Set the value on the current value of the index.
          #From the beginning of the list we a list without gaps therefore the value is equal to the index
          value = idx
          print ('New location to insert the new id - idx: {0}'.format(idx))

        # Based on idx determine whether we have to insert the new id somewhere in the list or if we have to add it at the end of the list
        if len(self.idList) <= idx:
          #We are at the end of the list - just append the new ID
          print ('endOfList reached - append the new ID')
          self.idList.append([name, value, comment])
        else:
          #Insert a new entry into the idList
          print ('Instert the new ID to the right position in the list')
          self.idList.insert(idx, [name, value, comment])

    return error

  ################################################################################################################################################################
  def fctAddNewIdQuitButton(self):
    #Just destroy the window an reset the flag
    self.addNewIdWindow.destroy()
    self.addNewIdWindowOpen = False




  ################################################################################################################################################################
  def fctGlobalIdOkButton(self):
    if not self.confirmWindowOpen:
      #Save the taskRunTimeEnabled flag
      self.updateHeaderFile()

      #Close the window
      self.root.destroy()

  ################################################################################################################################################################
  def updateHeaderFile(self):
    linesHeaderFile    = self.getLinesOfFile(self.headerFile)
    linesBelowStartTag = []
    #Remove the lines below the startTag
    self.moveLinesBelowTagToSeparateList(self.GEN_TAG_GLOBAL_ID_START, linesHeaderFile, linesBelowStartTag)

    #Add id headerText including information regarding free IDs
    linesHeaderFile.extend(self.IDS_HEADER_TXT.format(self.RTE_GLOBAL_IDS_RANGE_START - len(self.idList)))

    #Determine maxLenght of all names
    maxLength = 0
    for entry in self.idList:
      if len(entry[self.ID_LIST_IDX_NAME]) > maxLength:
        maxLength = len(entry[self.ID_LIST_IDX_NAME])

    #Add all the define lines of the globalIDs
    for entry in self.idList:
      if len(entry[self.ID_LIST_IDX_COMMENT]):
        #Add comment to the line
        newLine = self.ID_DEFINE_LINE.format(entry[self.ID_LIST_IDX_NAME].ljust(maxLength), str(entry[self.ID_LIST_IDX_VALUE]).rjust(4), entry[self.ID_LIST_IDX_COMMENT])
      else:
        newLine = self.ID_DEFINE_LINE_NO_COMMENT.format(entry[self.ID_LIST_IDX_NAME].ljust(maxLength), str(entry[self.ID_LIST_IDX_VALUE]).rjust(4))
      #Append the newLine
      linesHeaderFile.append(newLine)

    #Add the midText - between define lines and static const lines 
    linesHeaderFile.extend(self.IDS_MID_TXT)
    
    #Add all the define lines of the globalIDs
    for entry in self.idList:
      if len(entry[self.ID_LIST_IDX_COMMENT]):
        #Add comment to the line
        newLine = self.ID_STATIC_CONST_LINE.format(entry[self.ID_LIST_IDX_NAME].ljust(maxLength), str(entry[self.ID_LIST_IDX_VALUE]).rjust(4), entry[self.ID_LIST_IDX_COMMENT])
      else:
        newLine = self.ID_STATIC_CONST_LINE_NO_COMMENT.format(entry[self.ID_LIST_IDX_NAME].ljust(maxLength), str(entry[self.ID_LIST_IDX_VALUE]).rjust(4))
      #Append the newLine
      linesHeaderFile.append(newLine)

    # Add id trailorText
    linesHeaderFile.extend(self.IDS_TRAILOR_TXT)

    #Add the lines below the endTag
    self.addLinesBelowTag(self.GEN_TAG_GLOBAL_ID_END, linesBelowStartTag, linesHeaderFile)
    #Write the all the lines into the headerFile
    self.writeLinesintoFile(self.headerFile, linesHeaderFile)


  ################################################################################################################################################################
  def fctGlobalIdCancelButton(self):

    if not self.confirmWindowOpen:
      self.confirmWindowOpen = True
      #Create confirmation window
      self.topConfirm = tk.Toplevel()
      self.topConfirm.title('Discard changes?')

      rowCnt = 0

      infoText = tk.Label(self.topConfirm, text = 'Do you wish to discard all your changes? ')
      infoText.grid(row = rowCnt, columnspan = 4, pady = 10, sticky = 'we')
      rowCnt += 1

      YesButton = tk.Button(self.topConfirm, text = 'YES', command = self.fctGlobalIdCancelYesButtonConfirm)
      YesButton.grid(row = rowCnt,column = 1, pady = 10, padx = 4, sticky = 'news')

      NoButton = tk.Button(self.topConfirm, text = 'No', command = self.fctGlobalIdCancelNoButtonConfirm)
      NoButton.grid(row = rowCnt, ipadx = 10, pady = 10, padx = 4, sticky = 'news')

  ################################################################################################################################################################
  def fctGlobalIdCancelNoButtonConfirm(self):
    #Just close the confirmation window, the confgiuration window shall remain open
    self.topConfirm.destroy()
    self.confirmWindowOpen = False

  ################################################################################################################################################################
  def fctGlobalIdCancelYesButtonConfirm(self):
    #Close the confirmation window
    self.topConfirm.destroy()
    self.confirmWindowOpen = False

    #And close the configurationWindow without storing the recently made settings
    self.root.destroy()




  ################################################################################################################################################################
  def isGlobalIDHeaderFileValid(self, linesHeaderFile):

    tagList = [
      self.GEN_TAG_GLOBAL_ID_START,
      self.GEN_TAG_GLOBAL_ID_END,
    ]

    listIdx = 0
    isValid = False

    # Check whether the file contains all needed tags in the right order
    for line in linesHeaderFile:
      #Find next tag
      if -1 != line.find(tagList[listIdx]):
        #Ok - next tag found just increment index
        listIdx = listIdx + 1
        #Check whether this was already the last index to be found
        if len(tagList) <= listIdx:
          # ok, all tags found
          isValid = True
          break

    return isValid


RtaGlobalIDGenerator()