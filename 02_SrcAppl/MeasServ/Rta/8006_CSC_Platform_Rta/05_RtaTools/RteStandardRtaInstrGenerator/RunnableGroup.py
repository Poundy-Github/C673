try:
# python 2
    import Tkinter as tk
except ImportError:
# python 3
    import tkinter as tk

from InstrGeneratorBase         import InstrGenBase

##################################################################################################################################################################
#
################################################################################################################################################################
class RunnableGroup(InstrGenBase):

  ################################################################################################################################################################
  def __init__(self, runnableGroupCfg, runnableGroupsConfigurator):

    self.confirmWindowOpen      = False
    self.toBeDeleted            = False
    self.myGroupPrefix          = runnableGroupCfg[self.IDX_RUNNABLE_GROUP_PREFIX]
    self.myConfiguratorObj      = runnableGroupsConfigurator

    #The checkBoxVariable
    self.groupEnabled           = tk.BooleanVar()
    self.groupEnabled.set(runnableGroupCfg[self.IDX_RUNNABLE_GROUP_SETTING])


  ################################################################################################################################################################
  def drawRunnableGroupEntry(self, parentWindow, row):

    #Only draw it (show it ) if it should not be deleted
    if not self.toBeDeleted:
      checkBox = tk.Checkbutton(parentWindow, text = self.myGroupPrefix.ljust(100), variable = self.groupEnabled)
      checkBox.grid(row = row, sticky = 'nsw')

      delButton = tk.Button(parentWindow, text = 'Delete', command = self.deleteRunnableGroup)
      delButton.grid(row = row,  column = 1, sticky = 'news')


  ################################################################################################################################################################
  def deleteRunnableGroup(self):
    if not self.confirmWindowOpen:
      self.confirmWindowOpen = True
      #Create confirmation window
      self.topConfirm = tk.Toplevel()
      self.topConfirm.title('Shall runnable group be deleted?')

      rowCnt = 0

      infoText = tk.Label(self.topConfirm, text = 'Do you really want to delete this runnableGroup? ')
      infoText.grid(row = rowCnt, columnspan = 4, pady = 10, sticky = 'we')
      rowCnt += 1

      YesButton = tk.Button(self.topConfirm, text = 'YES', command = self.fctDeleteYesButtonConfirm)
      YesButton.grid(row = rowCnt,column = 1, pady = 10, padx = 4, sticky = 'news')

      NoButton = tk.Button(self.topConfirm, text = 'No', command = self.fctDeleteNoButtonConfirm)
      NoButton.grid(row = rowCnt, ipadx = 10, pady = 10, padx = 4, sticky = 'news')



  ################################################################################################################################################################
  def fctDeleteNoButtonConfirm(self):
    #Just close the confirmation window
    self.topConfirm.destroy()
    self.confirmWindowOpen = False


  ################################################################################################################################################################
  def fctDeleteYesButtonConfirm(self):
    #Close the confirmation window
    self.topConfirm.destroy()
    self.confirmWindowOpen = False
    #Set the deleteFlag
    self.toBeDeleted = True

    #Refresh the window!!!
    self.myConfiguratorObj.RefreshRunnableGroupsCfgWindow()
