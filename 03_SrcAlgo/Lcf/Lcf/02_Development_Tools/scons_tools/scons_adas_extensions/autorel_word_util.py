"""
Filename                  :  scons_adas_extensions\autorel_word_util.py
Description               :  Script that contains utility functions for generation and modification of Microsoft Word files.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: autorel_word_util.py
#
# DESCRIPTION: Script that contains utility functions for generation and modification of Microsoft Word files.
#
# INITIAL AUTHOR: Roland.Stark-EXT (uidw1169)
#
# CREATION DATE: - 2014/04/17
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:51CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: autorel_word_util.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:51CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.4 2016/05/27 11:39:39CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.3 2015/06/26 05:17:26CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:26 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

from win32com.client import Dispatch

wdStory = 6

class WordDocument (object):
  # Some convenience methods for Word documents accessed through COM.
 
  def __init__ (self, visible = False):
    """
    Function              :  __init__ 
    Description           :  
    visible               :  
    Returns               :  
    """
    self.app = Dispatch ("Word.Application")
    self.app.Visible = visible
   
  def new (self, filename = None):
    """
    Function               :  new 
    Description            :  
    filename               :  
    Returns                :  
    """
    # Create a new Word document. If 'filename' specified, use the file as a template.
    self.app.Documents.Add (filename)
   
  def open (self, filename):
    """
    Function              :  open 
    Description           :  
    filename              :  
    Returns               :  
    """
    # Open an existing Word document for editing.
    self.app.Documents.Open (filename)
   
  def save (self, filename = None):
    """
    Function               :  save 
    Description            :  
    filename               :  
    Returns                :  
    """
    # Save the active document. If 'filename' is given, do a Save As.
    if filename:
      self.app.ActiveDocument.SaveAs (filename)
    else:
      self.app.ActiveDocument.Save ()
   
  def save_as (self, filename):
    """
    Function              :  save_as 
    Description           :  
    filename              :  
    Returns               :  
    """
    return self.save (filename)
   
  def print_out (self):
    """
    Function        :  print_out 
    Description     :  
    Returns         :  
    """
    # Print the active document.
    self.app.Application.PrintOut ()
   
  def close (self):
    """
    Function        :  close 
    Description     :  
    Returns         :  
    """
    # Close the active document.
    self.app.ActiveDocument.Close ()
   
  def quit (self):
    """
    Function        :  quit 
    Description     :  
    Returns         :  
    """
    # Quit Word.
    return self.app.Quit ()
   
  def find_and_replace (self, find_str, replace_str):
    """
    Function                 :  find_and_replace 
    Description              :  
    find_str                 :  
    replace_str              :  
    Returns                  :  
    """
    # Find all occurances of 'find_str' and replace with 'replace_str' in the active document.
    self.app.Selection.HomeKey (Unit = wdStory)
    find = self.app.Selection.Find
    find.Text = find_str
    while self.app.Selection.Find.Execute ():
      self.app.Selection.TypeText (Text = replace_str)


def createWordDocument():
  """
  Function        :  createWordDocument
  Description     :  
  Returns         :  
  """
  word = Dispatch ('Word.Application.8')
  doc = word.Documents.Add ()
  range = doc.Range (0, 0)
  range.InsertBefore ('Hallo Erde')
  doc.SaveAs ("d:\\proj\\test\\erde.doc")
  doc.Close ()
