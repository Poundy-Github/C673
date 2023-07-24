#! /usr/bin/python
#coding: utf-8

#===============================================================================
# IntegrityItem.py
#   Provides a class to import one integrity item (release or issue or RO)
#===============================================================================

import mks                  # Provides MKS access function
import sys                  # Access to command line parameters
from IssuesIntegrated_Parameter import *

#===============================================================================
# Class CItem
#===============================================================================
class CItem:

  #-----------------------------------------------------------------------------
  # Init class:
  #   Request one item from MKS and stores the data to member variable mItemData.
  #
  # Parameter:
  #   ItemId [in] Item ID
  #
  # Return value:
  #   - none -
  #-----------------------------------------------------------------------------
  def __init__(self, ItemID, ExpectedType=""):
    # Import Item
    MksResponse = mks.run("im viewissue --batch %s" % (ItemID,), TIMEOUT_INTEGRITY_ITEM)
    if MksResponse:

      self.mItemData = {}
      for line in MksResponse.splitlines():
        PositionOfColon = line.find(":")
        if PositionOfColon >= 1:
          self.mItemData.update({line[:PositionOfColon]: line[PositionOfColon+1:].strip()})
            
      # Check that the item has the type "Issue"
      if ExpectedType <> "":
        Type = self.mItemData.get("Type", "")
        if Type == "":
          print "Error: Item %s is not an '%s'!" % (ItemID, ExpectedType)
          sys.exit(1) 
        if Type <> ExpectedType:
          print "Error: Item %s is a '%s'! Type '%s' expected." % (ItemID, Type, ExpectedType)
          sys.exit(1) 
    
    # MKS request failed
    else:
      # Just exit. Error reason is lready printed in mks.run function
      sys.exit(1) 

  #-----------------------------------------------------------------------------
  # __str__:
  #   Generate string for print
  #
  # Parameter:
  #   - none -
  #
  # Return value:
  #   "Type ID (State): Summary"
  #-----------------------------------------------------------------------------
  def __str__(self):
    return "%s %s (%s): %s" % (self.mItemData["Type"], self.mItemData["ID"], self.mItemData["State"], self.mItemData["Summary"])

  #-----------------------------------------------------------------------------
  # Compare operators
  #   Operators == != < > <= >=
  #   Used to sort Items by ID
  #
  # Parameter:
  #   right [in] Second compare obejct (type IssueID)
  #
  # Return Value:
  #   True  -> Compare is True
  #   False -> Compare is False
  #-----------------------------------------------------------------------------
  def __eq__(self, right):	# self == right
    return self.mItemData["ID"] == right.mItemData["ID"]
  def __ne__(self, right):	# self != right
    return self.mItemData["ID"] != right.mItemData["ID"]
  def __lt__(self, right):	# self < right
    return self.mItemData["ID"] < right.mItemData["ID"]
  def __gt__(self, right):	# self > right
    return self.mItemData["ID"] > right.mItemData["ID"]
  def __le__(self, right):	# self <= right
    return self.mItemData["ID"] <= right.mItemData["ID"]
  def __ge__(self, right):	# self >= right
    return self.mItemData["ID"] >= right.mItemData["ID"]

#===============================================================================
# main function
#   Imports one integrity item
#
# Parameter:
# - Item ID
#===============================================================================
if __name__ == "__main__":
  if len(sys.argv) <> 2:
    print "Error: IntegrityItem.py needs the item ID as parameter!"
    print "       Example: IntegrityItem.py 123456"
    sys.exit(1) 

  else:
    Item = CItem(sys.argv[1])
    print Item