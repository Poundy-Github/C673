"""
Filename                  :  scons_adas_extensions\autorel_functions.py
Description               :  Script that contains functions for the automatic release sequence and to generate code handover script.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: autorel_functions.py
#
# DESCRIPTION: Script that contains functions for the automatic release sequence and to generate code handover script.
# PLEASE NOTE NOT ALL FUNCTIONS ARE VALIDATED. THOSE WHO ARE GOT A FUNCTION HEADER COMMENT. ALL
# OTHERS WILL BE INTEGRATED IN A FURTHER STEP.
#
# INITIAL AUTHOR: Roland.Stark-EXT (uidw1169)
#
# CREATION DATE: - 2014/04/17
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:50CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: autorel_functions.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:50CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.35 2016/05/27 11:35:25CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.34 2015/09/29 14:00:59CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Modified for AutoRrelease feature
# CHANGES:                   - Added comments -  uidj9083 [Sep 29, 2015 2:01:00 PM CEST]
# CHANGES:                   Change Package : 374890:1 http://mks-psad:7002/im/viewissue?selection=374890
# CHANGES:                   Revision 1.33 2015/06/26 05:17:43CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:43 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************


#------------------------
#  IMPORTS
#------------------------

import os
import locale
import subprocess
import msvcrt
import xml.dom.minidom


#------------------------
#  GLOBALS
#------------------------

LABEL_REV_PRFX = "Revision "


#------------------------
#  EXCEPTIONS
#------------------------

class FileNotFoundError(RuntimeError): pass
class FileFormatError(RuntimeError): pass


#------------------------
#  FUNCTIONS
#------------------------

#-------------------------------------------------------------------------------
# Reads the version number from a regular version header file.
#
# PARAM   version_file  the version file as string (full path)
#
# RETURN  version number as int array of size 4,
#         [0, 0, 0, 0] in case of an error
#-------------------------------------------------------------------------------
def ReadVersionNumer(version_file, comp):
  """
  Function                 :  ReadVersionNumer
  Description              :  
  version_file             :  
  comp                     :  
  Returns                  :  
  """
  version_number = [-1, -1, -1, -1]
  
  incrementLevel = {}
  incrementLevel["main"] = "#define %sALL_SW_MAIN_VER_NO"  % (comp)
  incrementLevel["sub"]  = "#define %sALL_SW_SUB_VER_NO"   % (comp)
  incrementLevel["fix1"] = "#define %sALL_SW_BUG_FIX_LEV " % (comp)
  incrementLevel["fix2"] = "#define %sALL_SW_BUG_FIX_LEV2" % (comp)

  try:
    file_instream = open(version_file, "r")	
    for line in file_instream:
      if incrementLevel["main"] in line:
        num = line.lower().split()[2].replace("u", "")
        version_number[0] = int(num, 16)
      elif incrementLevel["sub"] in line:
        num = line.lower().split()[2].replace("u", "")
        version_number[1] = int(num, 16)
      elif incrementLevel["fix1"] in line:
        num = line.lower().split()[2].replace("u", "")		
        version_number[2] = int(num, 16)			
      elif incrementLevel["fix2"] in line:
        num = line.lower().split()[2].replace("u", "")
        version_number[3] = int(num, 16)
      
    # check if all segments were found
    if -1 in version_number:
      raise RuntimeError
  except:
    version_number = None
  
  # finally close the version file
  try:
    file_instream.close ()
  except:
    pass

  return version_number
  
#-------------------------------------------------------------------------------
# Replace the version number in the regular version header file <version_file>
# by a new one <version_number>.
#
# PARAM   version_number  version number as int array of size 4
#         version_file    the version file as string (full path)
#         comp_name       the component name (will be used in label)
#         custom_str      custom description (optional, default is "")
#
# RETURN  True is successful, False otherwise
#-------------------------------------------------------------------------------
def WriteVersionNumber(version_number, version_file, comp_name, custom_str=""):
  """
  Function                   :  WriteVersionNumber
  Description                :  
  version_number             :  
  version_file               :  
  comp_name                  :  
  custom_str                 :  
  Returns                    :  
  """
  ret_success = False
  custom_start = None
  buffer = ""
  
  incrementLevel = {}
  incrementLevel["main"]   = "#define %sALL_SW_MAIN_VER_NO"  % (comp_name.upper())
  incrementLevel["sub"]    = "#define %sALL_SW_SUB_VER_NO"   % (comp_name.upper())
  incrementLevel["fix1"]   = "#define %sALL_SW_BUG_FIX_LEV " % (comp_name.upper())
  incrementLevel["fix2"]   = "#define %sALL_SW_BUG_FIX_LEV2" % (comp_name.upper())
  incrementLevel["custom"] = "#define %sALL_SW_CUSTOM_STR"   % (comp_name.upper())
  
  try:
    custom_str_line = "%(define)s\"%(cust_str)s\"\n" % {'define': incrementLevel["custom"].ljust(43), "cust_str": custom_str}
    
    # read old file and replace version defines
    vfile = open(version_file, "r+t")
    for line in vfile:
      if incrementLevel["main"] in line:
        buffer += "%(define)s0x%(version)02xU\n" % {'define': incrementLevel["main"].ljust(43), "version": version_number[0]}
      elif incrementLevel["sub"] in line:
        buffer += "%(define)s0x%(version)02xU\n" % {'define': incrementLevel["sub"].ljust(43),  "version": version_number[1]}
      elif incrementLevel["fix1"] in line:
        buffer += "%(define)s0x%(version)02xU\n" % {'define': incrementLevel["fix1"].ljust(43), "version": version_number[2]}
      elif incrementLevel["fix2"] in line:
        buffer += "%(define)s0x%(version)02xU\n" % {'define': incrementLevel["fix2"].ljust(43), "version": version_number[3]}
        custom_start = len(buffer)
      elif incrementLevel["custom"] in line:
        buffer += custom_str_line
        custom_start = None
      else:
        buffer += line
    vfile.close()
    
    # insert custom text if not existing
    if custom_start:
      buffer = buffer[:custom_start] + custom_str_line + buffer[custom_start:]

    # overwrite version file
    vfile = open(version_file, "w")
    vfile.write(buffer)
    vfile.close()
    
    ret_success = True
    
  except Exception, exc:
    # unexpected fatal exception
    print exc
  
  finally:
    try:
      vfile.close ()
    except:
      # this happens only if file is not open
      # -> ignore this exception
      pass
    
  return ret_success
  
#-------------------------------------------------------------------------------
# In a first step this function asks the user for a modification of the current
# version number. If this is done it asks for a free description text.
#
# The generated label has the following format.
# Format: AL_<COMPONENT>_<MM>.<SS>.<FX>_<DESCR>
#           - MM: major
#           - mm: minor
#           - FX: bugfix
#
# The description text is translated in upper case letters. Leading and trailing
# white spaces are removed. Spaces and tabs within the text will be replaced by
# underscore (_) characters.
#
# Finally there is a confirmation if the label is correct or not. If not the 
# process is repeated. This function has no abort feature.
#
# PARAM   version_number  version number as int array of size 4
#         comp_name       the component name (will be used in label)
#
# RETURN  The generated checkpoint label.
#-------------------------------------------------------------------------------
def GenerateVersionLabel(version_number, comp_name):
  """
  Function                   :  GenerateVersionLabel
  Description                :  
  version_number             :  
  comp_name                  :  
  Returns                    :  
  """
  version_backup = list(version_number)
  menu_opt = ["Major", "Minor", "Bugfix", "Integration"]
  
  # create possible new version numbers
  version_options = []
  for n in xrange(0, len(version_number)):
    # calculate new version number
    version_options += [list(version_number)]
    version_options[n][n] += 1
    version_options[n][n+1:] = [0] * (len(version_number) - n - 1)

    # range check (8 bit unsigned int)
    # => disable invalid version numbers
    num_in_range = True
    for x in version_options[n]:
      if (x > 255):
        num_in_range = False
        version_options[n] = None
        break
    
  PrintTitle("INCREMENT VERSION")  

  label_ok = False
  while not label_ok:
    print "Select the segment of the version number (%s_INT-%i) to be raised:" % (".".join(map(str, version_number[0:3])), version_number[3])
    print

    # print selection menu
    menu_num = 0
    for opt in menu_opt:
      if version_options[menu_num]:
        print "[%i] %-11s (=> %s_INT-%i)" % (menu_num + 1, opt, ".".join(map(str, version_options[menu_num][0:3])), version_options[menu_num][3])
      else:
        print "[%i] %-11s DISABLED (RANGE VALIDATION)" % (menu_num + 1, opt)
      menu_num += 1
    print "----"
    print "[0] None (keep current version number)"

    # chose menu item
    while True:
      try:
        print ""
        user_input = raw_input("Select one of the options above: ")
        version_level = int(user_input)
        if (version_level == 0):
          # use current version number
          break
        elif (1 <= version_level <= len(menu_opt)):
          # use the selected option (if enabled)
          if version_options[version_level-1]:
            version_number[:] = version_options[version_level-1][:]
            break
      except ValueError:
        # non-decimal input -> try again
        pass
    
    # create 1st part of version label
    label = "AL_%(comp)s_%(main)02i.%(sub)02i.%(fix1)02i_INT-%(int)i" % {
      "comp": comp_name.upper(), 
      "main": version_number[0], 
      "sub" : version_number[1], 
      "fix1": version_number[2], 
      "int":  version_number[3]}
      
    # get clear text description part
    print ""
    descr = raw_input("Enter description part of version label: "+ label + "_").strip()
    descr = descr.replace(" ", "_").replace("\t", "_")

    if (len(descr) > 0):
      descr = "_" + descr
      label += descr
    
    print ""
    print "Is the version label '%s' correct? [y/n]" % (label),
    while True:
      ch = msvcrt.getch().lower()
      if (ch == "y") or (ch == "n"):
        label_ok = (ch == "y")
        print ch
        break
        
    # restore original version number if not ok
    if not label_ok:
      version_number[:] = version_backup[:]
      print ""

  return label, descr

#-------------------------------------------------------------------------------
# Determines the type of delivery. First it asks if <default_type> is correct. 
# If not the user can select one of the valid options ("Library" or "Source").
#
# PARAM   default_type  default delivery type as string
#
# RETURN  The delivery type
#-------------------------------------------------------------------------------
def GetDeliveryType(default_type):
  """
  Function                 :  GetDeliveryType
  Description              :  
  default_type             :  
  Returns                  :  
  """
  delivery_types = ["Library", "Source"]
  del_type = default_type
  
  PrintTitle("TYPE OF DELIVERY")
  
  # check if valid default
  if del_type in delivery_types:
    option = GetConfirmation("Is the delivery type '%s' correct?" % (del_type), ["y", "n"])
    if option == "n":
      # switch type
      if del_type == delivery_types[0]:
        del_type = delivery_types[1]
      else:
        del_type = delivery_types[0]
      print "Delivery type '%s' is used." % (del_type)
  else: 
    # menu selection if default is invalid
    menu_num = 1
    menu_options = {}
    for dt in delivery_types:
      print "[%i] %s" % (menu_num, dt)
      menu_options[str(menu_num)] = dt
      menu_num += 1
    print
    print "Select one of the options above:",

    # menu selection
    while True:
      ch = msvcrt.getch().lower()
      if ch in menu_options.keys():
        del_type = menu_options[ch]
        print ch
        break
        
  return del_type

#-------------------------------------------------------------------------------
# This function looks for a file in <base_path> and its sub-folders. If a file
# is found that is equal <filename> then it aborts and returns the file.
#
# PARAM   base_path   the root directory for version file scan
#         filename   the filename to look for
#
# RETURN  The version file or None if not found
#-------------------------------------------------------------------------------
def LookForFile(base_path, filename):
  """
  Function              :  LookForFile
  Description           :  
  base_path             :  
  filename              :  
  Returns               :  
  """
  result_file = None

  # look for version file
  for root,dirs,files in os.walk(Dir(base_path).abspath):
    if filename in files:
      result_file = File(root + "/" + filename).abspath
      break
   
  return result_file
  
#-------------------------------------------------------------------------------
# This function looks scans <base_path> recurse and checks leafs nodes (files) 
# to be part of <lib_names>. These files are only accepted if <comp> is 
# contained in the path. The pat where the files are found is returned.
# The "pc" path is returned in any case.
#
# PARAM   base_path   the root directory for version file scan
#         filename    the filename to look for
#         lib_names   names of libraries to be released
#
# RETURN  The version file or None if not found
#-------------------------------------------------------------------------------
def LookForComponentDirs(base_path, comp, lib_names):
  """
  Function               :  LookForComponentDirs
  Description            :  
  base_path              :  
  comp                   :  
  lib_names              :  
  Returns                :  
  """
  dir_list = []

  # look for version file
  for root,dirs,files in os.walk(base_path):
    if comp in root:
      if "pc" in root:
        dir_list += [Dir(root).abspath]
      else:
        for f in files:
          if f in lib_names:
            dir_list += [Dir(root).abspath]
   
  return dir_list
  
#-------------------------------------------------------------------------------
# This function looks for library size files (created by scons script 
# "ram_rom_algo_libsize.py") in the simulation build folder. The pre-defined
# setups can be selected first. Duplicate libraries are removed from list.
#
# It returns a list of dictionary that is valid to pass it to function 
# "fillReleaseNotes" in this file.
#
# As a second return value a list of build targets of the selected release 
# setups will be returned.
#
# PARAM   base_path   the root directory (string) for simulation build, e.g.
#                     "<sandbox>\04_Engineering\04_Build\algo\<component>_sim"
#         setups      component release setups as defined in auto release 
#                     configuration file
#
# RETURN  - List of dictionary containing ram/rom usage information for every
#           library found.
#         - List of build targets to be rebuild
#         - List of selected architectures
#
# EXCEPT  FileNotFoundError - if library size file was not found
#-------------------------------------------------------------------------------
def ParseRamRomUsages(base_path, setups):
  """
  Function              :  ParseRamRomUsages
  Description           :  
  base_path             :  
  setups                :  
  Returns               :  
  """
  lib_list = []
  build_list = []
  dir_list, build_list, arch_list = GetOutfileDirs(base_path, setups)
  
  for out_dir in dir_list:
    prev_size = len(lib_list)
    for item in os.listdir(out_dir):
      if (item.startswith(component_name.lower())) and (item.endswith("libsize.txt")):
        # read and store libsize
        lib_list += [readLibSizeFile(out_dir + "/" + item)]
        # next file
        break
    # check if a valid file was detected
    if (prev_size == len(lib_list)):
      raise FileNotFoundError, 'missing ram/rom file in path "' + out_dir + '"'
  
  # remove duplicates (tricky) => the strategy is:
  #   -> convert dictionary into tuple (tuples can be hashed)
  #   -> add tuples to a set (duplicates will be removed)
  #   -> convert set back to dictionary
  lib_list = [dict(t) for t in set([tuple(sorted(d.items())) for d in lib_list])]

  return lib_list, build_list, arch_list

#-------------------------------------------------------------------------------
# This function asks the user to select one or multiple of the pre-defined 
# component release setups. If the setups are selected it creates all paths 
# where ram/rom libsize files are expected, removed duplicates and returns it.
#
# If there is only one setup defined it is selected without prompting the user.
#
# As a second return value a list of build targets of the selected release 
# setups will be returned.
#
# PARAM   base_path   the root directory (string) for path generation
#         setups      component release setups as defined in auto release 
#                     configuration file
#
# RETURN  - List of directories where ram/rom libsize files are expected
#         - List of build targets to be rebuild
#         - List of selected architectures
#
# EXCEPT  FileNotFoundError - if the configured build path was not found
#         RuntimeError      - if no setups defined
#-------------------------------------------------------------------------------
def GetOutfileDirs(base_path, setups):
  """
  Function              :  GetOutfileDirs
  Description           :  
  base_path             :  
  setups                :  
  Returns               :  
  """
  dir_list = []
  build_list = []
  
  PrintTitle("COMPONENT RELEASE SETUPS")
  
  if (len(setups) == 0):
    raise RuntimeError("Empty release setup list.")
    
  # single setup (auto mode)
  if (len(setups) == 1):
    print 'Only one setup configured: "%s" (no selection required).' % setups[0]['NAME']
    dir_list   = setups[0]['DIRS']
    build_list = setups[0]['BUILDS']
  
  # more than on1 setup => select it
  else:
    print "Please select the setups you would like to release."
    if (len(setups) >= 3):
      print "Select one setup, all setups or custom selection followed by <ENTER>."
    else:
      print "Select one or all setups followed by <ENTER>."
    print ""

    # init options menu
    menu_num = 1
    menu_options = {}
    menu_options['a'] = []
    menu_options['c'] = []
    build_options = {}
    build_options['a'] = []
    build_options['c'] = []

    for cfg in setups:
      # print option
      print "[" + str(menu_num) + "] " + cfg['NAME']
      # generate action
      menu_options[str(menu_num)]  = cfg['DIRS']
      build_options[str(menu_num)] = cfg['BUILDS']
      menu_options['a']  = menu_options['a']  + cfg['DIRS']
      build_options['a'] = build_options['a'] + cfg['BUILDS']
      menu_num += 1
    # common options
    print "---"
    print "[a] ALL SETUPS"
    
    # offer custom selection only if there are 3 setups a least
    if (len(setups) >= 3):
      print "[c] Custom"
    else:
      # otherwise make the option not selectable
      menu_options.pop('c', None)
      build_options.pop('c', None)
    
    print ""
    print "Select one of the options above:",
    
    # get input
    answer = None
    while True:
      ch = msvcrt.getch().lower()
      if ch in menu_options.keys():
        # valid answer
        if (ch <> answer):
          if (answer):
            # remove last answer from output
            print "\b\b\b",
          # store answer
          answer = ch
          print answer,
      elif (answer) and (ch == "\r"):
        # ENTER key => confirm answer
        dir_list = menu_options[answer]
        build_list = build_options[answer]
        print ""
        break
      else:
        # invalid key => remove last answer from output
        if (answer) and (ch <> answer):
          print "\b\b \b\b",
        answer = None
        
    while (len(dir_list) == 0):
      print ""
      print "Please select the setups you would like to release. You may select all but 1 is required."
      print "Press 'y' or 'n' followed by <ENTER>."
      print ""
      for cfg in setups:
        answer = None
        print cfg['NAME'] + " [y/n]",
        while True:
          ch = msvcrt.getch().lower()
          if (ch == "y") or (ch == "n"):
            # valid answer
            if (ch <> answer):
              if (answer):
                # remove last answer from output
                print "\b\b\b",
              # store answer
              answer = ch
              print answer,
          elif (answer) and (ch == "\r"):
            # ENTER key => confirm answer
            if (answer == "y"):
              dir_list += cfg['DIRS']
              build_list += cfg['BUILDS']
            print ""
            break
          else:
            # invalid key => remove last answer from output
            if (answer) and (ch <> answer):
              print "\b\b \b\b",
            answer = None
    
    if len(dir_list) == 0:
      print ""
      print "Invalid input: no setup selected!"
    
    # remove duplicates and sort result
    dummy = {}
    for e in dir_list:
      dummy[e] = 1
    dir_list = sorted(dummy.keys())
    dummy = {}
    for e in build_list:
      dummy[e] = 1
    build_list = sorted(dummy.keys())
  
  # end of setup selection
  
  # clone before path is added
  arch_list = list(dir_list)
  
  for ix in xrange(len(dir_list)):
    dir_obj = Dir(base_path + "/" + dir_list[ix] + "/release/")
    if not (dir_obj.exists()):
      raise FileNotFoundError, 'could not found path "' + dir_obj.abspath + '"'
    dir_list[ix] = dir_obj.abspath
	
  return dir_list, build_list, arch_list
  
#-------------------------------------------------------------------------------
# This function asks the user for a change package to use. One of the change 
# packages passed by the parameter can be selected. There is additionally the
# option to exit process if a proper change package is not yet existing.
#
# PARAM   chgp_list change packages (list of tuples):
#                   [(ID1, Summary1), (ID2, Summary2)...]
#
# RETURN  Selected change package as string, None if 'exit' was selected
#-------------------------------------------------------------------------------
def SelectChangePackage(chgp_list):
  """
  Function              :  SelectChangePackage
  Description           :  
  chgp_list             :  
  Returns               :  
  """
  cp_id = None
  
  print "The selected change package will be used for locking members."
  print ""
  print "Existing open change packages:"
  print "------------------------------"

  # print selection menu
  menu_num = 1
  for ChngPa in chgp_list:
    print "[%2i] %s - %s" % (menu_num, ChngPa[0], ChngPa[1])
    menu_num += 1
  print "----"
  print "[ s] Scan again"

  # chose menu item
  while (cp_id == None):
    try:
      print ""
      user_input = raw_input("Select one of the options above: ").lower()
      
      if (user_input.lower() == 's'):
        break
      else:
        num = int(user_input)
        if (num >= 1) and (num <= len(chgp_list)):
          cp_id = chgp_list[num - 1][0]
          break
    except ValueError:
      # non-decimal input -> try again
      pass
  
  # log blank line
  print ""
  
  return cp_id
  
#-------------------------------------------------------------------------------
# This function print questions on the console asking the script caller whether
# a test was performed or not. It returns an array of answers, True means "yes",
# False means "No". The order inside the array is exactly the order of the 
# questions asked.
#
# PARAM   -/-
#
# RETURN  Boolean array of a size that matches the number of questions.
#-------------------------------------------------------------------------------
def GetTestInfoFromUser():
  """
  Function        :  GetTestInfoFromUser
  Description     :  
  Returns         :  
  """
  answer_array = []
  
  # map yes-no-answers into boolean
  YES_NO = {"n":False, "y":True}

  # the questions that are asked
  QUESTIONS = ("Tested on SIL?      ",
               "Tested on Evalboard?",
               "Tested on ECU/Lab?  ",
               "Tested on ECU/Car?  ")
               
  PrintTitle("COMPONENT INTEGRATION TESTS")

  print "Please answer the following questions. Press 'y' or 'n' followed by <ENTER>."
  print ""
  
  for qst in QUESTIONS:
    answer = None
    print qst + " [y/n]",
    while True:
      ch = msvcrt.getch().lower()
      if (ch == "y") or (ch == "n"):
        # valid answer
        if (ch <> answer):
          if (answer):
            # remove last answer from output
            print "\b\b\b",
          # store answer
          answer = ch
          print answer,
      elif (answer) and (ch == "\r"):
        # ENTER key => confirm answer
        answer_array += [YES_NO[answer]]
        print ""
        break
      else:
        # invalid key => remove last answer from output
        if (answer) and (ch <> answer):
          print "\b\b \b\b",
        answer = None

  return answer_array

#-------------------------------------------------------------------------------
# This function executes a scons build of all target in <target_list>.
#
# PARAM   target_list   list of build targets as string
#
# RETURN  SCons return code. 0 if ok, a different value if failed.
#-------------------------------------------------------------------------------
def BuildSconsTargets(target_list):
  """
  Function                :  BuildSconsTargets
  Description             :  
  target_list             :  
  Returns                 :  
  """
  ret_val = 0
  
  # python and scons paths
  prog_python  = "../../../02_Development_Tools/movpy/movpy.exe"
  prog_scons   = "..\\..\\..\\02_Development_Tools\\scons_tools\\scons\\scons.py"
  
  # iterate all targets
  for build_target in target_list:
    ProcHandle = subprocess.Popen([prog_python, prog_scons, build_target], cwd=Dir("#").abspath)
    ret_val = ProcHandle.wait()
    # terminate on error
    if ret_val: break
  
  return ret_val
  
#-------------------------------------------------------------------------------
# Opens the code handover template and replaces the defined tags by the values 
# taken from the parameter <param_dict>. Please refer to auto release 
# documentation for further information about the the parameter content.
#
# PARAM   param_dict    contains the keys and values for the replacement
#         target        the code handover document to be generated
#         prev_target   the last code handover document for history
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def CreateCodeHandoverDoc(param_dict, target, prev_target=None):
  """
  Function                 :  CreateCodeHandoverDoc
  Description              :  
  param_dict               :  
  target                   :  
  prev_target              :  
  Returns                  :  
  """
  ret_val = False
  
  try:
    # check type of parameter
    if param_dict['TYPE'] != "AUTOREL":
      raise TypeError
  except:
    print "fillReleaseNotes: passed invalid parameter dictionary."
    return False
    
  # sizes of additional checkpoints must be equal
  if len(param_dict["CP_LABEL_LIST"]) <> len(param_dict["CP_LABEL_PATH"]):
    print "fillReleaseNotes: number additional checkpoint labels and paths mismatch."
    return False
    
  # helpers for content generation
  YES_NO_TEXT = {False : "No", True : "Yes"}
  LINE_FEED   = "\n"
  EMPTY_LINE  = "n/a"
  MAX_LINE    = 120
  
  # format ram/rom usages with thousands separators
  locale.setlocale(locale.LC_NUMERIC, "en")

  # create fields that are presented as list separated by line wraps
  if len(param_dict["CP_LABEL_LIST"]) > 0:
    align_pos = max(len(x) for x in param_dict["CP_LABEL_LIST"])
    block_cp_labels = []
    for x in xrange(len(param_dict["CP_LABEL_LIST"])):
      line = "%s%s  %s" % (param_dict["CP_LABEL_LIST"][x], (" " * (align_pos - len(param_dict["CP_LABEL_LIST"][x]))), param_dict["CP_LABEL_PATH"][x])
      block_cp_labels += [LINE_FEED.join(LineWrapper(line, MAX_LINE, align_pos + 2, '/'))]
    block_cp_labels = LINE_FEED.join(block_cp_labels)
  else:
    block_cp_labels = EMPTY_LINE
    
  if len(param_dict["ISSUE_LIST_PR"]) > 0:
    block_issues_pr = []
    for x in param_dict["ISSUE_LIST_PR"]:
      line = "%i - %s [%s]" % (x['issue_id'], x['issue_sum'], x['issue_state'])
      block_issues_pr += [LINE_FEED.join(LineWrapper(line, MAX_LINE, len(str(x['issue_id'])) + 3, ' '))]
    block_issues_pr = LINE_FEED.join(block_issues_pr)
  else:
    block_issues_pr = EMPTY_LINE
    
  if len(param_dict["ISSUE_LIST_FR"]) > 0:
    block_issues_fr = []
    for x in param_dict["ISSUE_LIST_FR"]:
      line = "%i - %s [%s]" % (x['issue_id'], x['issue_sum'], x['issue_state'])
      block_issues_fr += [LINE_FEED.join(LineWrapper(line, MAX_LINE, len(str(x['issue_id'])) + 3, ' '))]
    block_issues_fr = LINE_FEED.join(block_issues_fr)
  else:
    block_issues_fr = EMPTY_LINE
    
  if len(param_dict["ISSUE_LIST_CR"]) > 0:
    block_issues_cr = []
    for x in param_dict["ISSUE_LIST_CR"]:
      line = "%i - %s [%s]" % (x['issue_id'], x['issue_sum'], x['issue_state'])
      block_issues_cr += [LINE_FEED.join(LineWrapper(line, MAX_LINE, len(str(x['issue_id'])) + 3, ' '))]
    block_issues_cr = LINE_FEED.join(block_issues_cr)
  else:
    block_issues_cr = EMPTY_LINE
	
  if len(param_dict["RO_ISSUE_LIST_NOT_VALID"]) > 0:
    block_ro_issue_not_valid = []
    for x in param_dict["RO_ISSUE_LIST_NOT_VALID"]:
      line = "%i - %s - %s - [%s]" %(x['issue_id'], x['issue_type'], x['issue_sum'], x['issue_state'])
      block_ro_issue_not_valid += [LINE_FEED.join(LineWrapper(line, MAX_LINE, len(str(x['issue_id'])) + 3, ' '))]
    block_ro_issue_not_valid = LINE_FEED.join(block_ro_issue_not_valid)
  else:
    block_ro_issue_not_valid = EMPTY_LINE

  if len(param_dict["RO_LIST_VALID"]) > 0:
    block_ro_valid = []
    for x in param_dict["RO_LIST_VALID"]:
      line = "%i - %s [%s]" % (x['issue_id'], x['issue_sum'], x['issue_state'])
      block_ro_valid += [LINE_FEED.join(LineWrapper(line, MAX_LINE, len(str(x['issue_id'])) + 3, ' '))]
    block_ro_valid = LINE_FEED.join(block_ro_valid)
  else:
    block_ro_valid = EMPTY_LINE  
    
  if len(param_dict["COMPONENT_CONFIG"]) > 0:
    align_pos = max(len(x[0]) for x in param_dict["COMPONENT_CONFIG"])
    block_comp_cfg = LINE_FEED.join(("%s%s   %s" % (x[0], (" " * (align_pos - len(x[0]))), x[1])) for x in param_dict["COMPONENT_CONFIG"])
  else:
    block_comp_cfg  = EMPTY_LINE

  if len(param_dict["RESOURCE_USAGE"]) > 0:
    block_usage_ram = []
    block_usage_rom = []
    for res_usage in param_dict["RESOURCE_USAGE"]:
      block_usage_ram += ['%s bytes (%s)' % (locale.format("%d", res_usage['RAM'], True), res_usage['LIB'])]
      block_usage_rom += ['%s bytes (%s)' % (locale.format("%d", res_usage['ROM'], True), res_usage['LIB'])]
    # join lines
    block_usage_ram = LINE_FEED.join(block_usage_ram)
    block_usage_rom = LINE_FEED.join(block_usage_rom)
  else:
    block_usage_ram = EMPTY_LINE
    block_usage_rom = EMPTY_LINE
  
  # dictionary for filling out template
  content_lookup = {
    'PROJECT_NAME':       		param_dict["PROJECT_NAME"],  
    'COMPONENT_OWNER':    		param_dict["COMPONENT_OWNER"],  
    'DEVELOP_PATH':       		param_dict["DEVELOP_PATH"],
    'COMPONENT_ROOT':     		param_dict["COMPONENT_ROOT"],  
    'CHECKPOINT_LABEL':   		param_dict["CHECKPOINT_LABEL"],
    'ADDITIONAL_CP_LIST': 		block_cp_labels,
    'KIND_OF_DELIVERY':   		param_dict["KIND_OF_DELIVERY"],
    'COMPONENT_CONFIG':   		block_comp_cfg,
    'ISSUE_LIST_PR':      		block_issues_pr,
    'ISSUE_LIST_FR':      		block_issues_fr,
    'ISSUE_LIST_CR':      		block_issues_cr,
    'RO_LIST_VALID' :	  		block_ro_valid,
    'RO_ISSUE_LIST_NOT_VALID':	block_ro_issue_not_valid,
    'TEST_STATE_SIL':     		YES_NO_TEXT[param_dict["TEST_STATE_SIL"]],
    'TEST_STATE_EVM':     		YES_NO_TEXT[param_dict["TEST_STATE_EVM"]],
    'TEST_STATE_ECU_LAB': 		YES_NO_TEXT[param_dict["TEST_STATE_ECU_LAB"]],
    'TEST_STATE_ECU_CAR': 		YES_NO_TEXT[param_dict["TEST_STATE_ECU_CAR"]],
    'USAGE_RAM':          		block_usage_ram,
    'USAGE_ROM':          		block_usage_rom,
    'COMPLIANCE_REPORT':  		param_dict["COMPLIANCE_REPORT"],
    'SIM_HISTORY':        		None,
    'ECU_HISTORY':        		None,
  }

  hist = GetHistoryFromHandover(prev_target)
  if hist:
    content_lookup['SIM_HISTORY'] = hist['SIM_HISTORY']
    content_lookup['ECU_HISTORY'] = hist['ECU_HISTORY']
    
  try:
    # open the template document
    content = None
    
    # read handover template completely
    in_file = open(File("#autorelease/Algorithm_Component_Handover_Template.txt").abspath,'r')
    content = in_file.read()
    in_file.close()
    
    # create handover document
    out_file = open(target,'w')
    for line in content.splitlines():
      #look for tags
      tag_start = line.find('{')
      tag_stop  = line.find('}')
      if (tag_start == -1) or (tag_stop == -1):
        # write line without tags
        out_file.write(line + LINE_FEED)	
      else:
        # TAG found
        tag_name = line[tag_start+1:tag_stop]
        
        # check for characters after the TAG
        rest_of_line = ""
        if (tag_stop < (len(line) - 1)):
          rest_of_line = line[tag_stop+1]
        
        try:
          # skip lines if content is None
          # => this happens only for history (initial code handover)
          if not content_lookup[tag_name]:
            continue
            
          # create line
          line = '%s%s%s' % (line[:tag_start], content_lookup[tag_name], rest_of_line)
          
          # special handling
          if (tag_name == "COMPONENT_ROOT"):			  
            out_file.write(LINE_FEED.join(LineWrapper(line, MAX_LINE, tag_start, '/')) + LINE_FEED)
          elif (tag_name == "USAGE_RAM") or (tag_name == "USAGE_ROM"):		  
            out_file.write(line.replace(LINE_FEED, LINE_FEED + (" " * tag_start)) + LINE_FEED)
          else:
            # normal lines				
            out_file.write(line + LINE_FEED)
        except KeyError:
          # just forward lines with unsupported tags			  
          out_file.write(line + LINE_FEED)
          print 'TAG {%s} is not supported!' % tag_name
            
    # close handover for editing
    out_file.close()
    
    # open with default editor
    os.system("start " + target)
  
    ret_val = True
    
  finally:
    # ensure files are closed
    try:
      in_file.close()
    except:
      pass
    try:
      out_file.close()
    except:
      pass
  
  return ret_val

#-------------------------------------------------------------------------------
# Checks a string whether it exceeds <max_len> characters. If this is the case
# it looks for the last occurrence of <wrap_char> that is inside <max_len>. The
# string is splitted and the <wrap_char> is the end of the previous line. The 
# new line starts with <indent_size> number of spaces.
#
# All new lines are returned as an array to be joint by the calling function.
# If the line doesn't exceed <max_len> characters it is returned as array of
# length 1.
#
# PARAM   input         the one-line input string
#         max_len       the maximum number of characters in each line
#         indent_size   number spaces to indent after wrapping
#         wrap_char     character that initiates a line wrap
#
# RETURN  Array of lines
#-------------------------------------------------------------------------------
def LineWrapper(input, max_len, indent_size, wrap_char):
  """
  Function                 :  LineWrapper
  Description              :  
  input                    :  
  max_len                  :  
  indent_size              :  
  wrap_char                :  
  Returns                  :  
  """
  output = []

  if (len(input) <= max_len):
    output = [input]
  else:
    while (len(input) > max_len):
      last_idx = input.rfind(wrap_char, 0, max_len)
      if (last_idx != -1):
        output += [input[:last_idx + 1].rstrip()]
        input = (" " * indent_size) + input[last_idx + 1:]
      else:
        break
        
    output += [input]
  
  return output

#-------------------------------------------------------------------------------
# Reads <handover_file> which is expected to be the last code handover document
# in text format. It scans for SIM and ECU history blocks as defined in the code
# handover template. If valid history blocks are found it returns a dictionary
# containing the following keys:
#
#   - SIM_HISTORY
#   - ECU_HISTORY
#
# The values are string representations of the history block and may be copied
# to the new code handover.
#
# If file doesn't exist or no valid history block was found, None is returned.
#
# PARAM   handover_file   the code handover file
#
# RETURN  history as dictionary,
#         None in case of any error
#-------------------------------------------------------------------------------
def GetHistoryFromHandover(handover_file):
  """
  Function                  :  GetHistoryFromHandover
  Description               :  
  handover_file             :  
  Returns                   :  
  """
  history_list = None
  
  try:
    # read old handover file
    in_file = open(handover_file, 'r')
    old_content = in_file.read()
    in_file.close()
    
    # position of history in file
    sim_start = old_content.find("SIM Code")
    sim_end   = old_content.find("ECU Code", sim_start)
    ecu_start = sim_end
    ecu_end   = old_content.find("==========", ecu_start)
    
    # check if valid block was found
    if (sim_start == -1) or (sim_end == -1) or (ecu_end == -1):
      raise FileFormatError("no valid history block found in previous handover document.")
      
    # valid block found -> initialize histories
    history_list = {'SIM_HISTORY': "", 'ECU_HISTORY': ""}
    
    # get SIM code history
    skip_header = 2
    for line in old_content[sim_start:sim_end].strip().splitlines():
      # skip 2 header lines
      if not skip_header:
        history_list['SIM_HISTORY'] += line + "\n"
      else:
        skip_header -= 1
    
    # remove trailing new line
    history_list['SIM_HISTORY'] = history_list['SIM_HISTORY'].strip()

    # get ECU code history
    skip_header = 2
    for line in old_content[ecu_start:ecu_end].strip().splitlines():
      # skip 2 header lines
      if not skip_header:
        history_list['ECU_HISTORY'] += line + "\n"
      else:
        skip_header -= 1
      
    # remove trailing new line
    history_list['ECU_HISTORY'] = history_list['ECU_HISTORY'].strip()

  except FileFormatError, exc:
    print "Warning: " + exc.args[0]
    
  except:
    # This happens normally only if the file is not existing.
    # This is the case when generating initial handover doc.
    # => ignore this
    pass

  finally:
    # ensure files are closed
    try:
      in_file.close()
    except:
      pass
  
  return history_list

#-------------------------------------------------------------------------------
# Scans <target> text file for occurrences of '<...>'. If these string is 
# included one or more times the first return value is False.
#
# It also scans <target> text file for occurrences of '\t' characters. If those
# are found all occurrences are replaced by 2 spaces and False is returned as
# 2nd return value.
#
# PARAM   target      the code handover document
#
# RETURN  True if '<...>' doesn't occur, False otherwise
#         True if '\t' doesn't occur, False otherwise
#
# EXCEPT  FileNotFoundError - if the <target> was not found
#-------------------------------------------------------------------------------
def ValidateCodeHandover(target):
  """
  Function           :  ValidateCodeHandover
  Description        :  
  target             :  
  Returns            :  
  """
  validity_fill = False
  validity_tabs = False
  
  try:
    handover_file = open(target, 'r')
    content = handover_file.read()
    handover_file.close()
    
    # skip the first occurrence which is in the 
    # rules-part of document header
    start_index = content.find('"<...>"')
    if start_index == -1:
      start_index = 0
    else:
      start_index += 2
      
    # replace all occurrences
    if content.find("<...>", start_index) == -1:
      validity_fill = True
      
    # look for tabs
    tab_index = content.find('\t')
    if tab_index == -1:
      validity_tabs = True
    else:
      # replace tabs ...
      content = content.replace('\t', '  ')
      # ... and write back to file
      handover_file = open(target, 'w')
      handover_file.write(content)
      handover_file.close()
    
  finally:
    # ensure files are closed
    try:
      handover_file.close()
    except:
      pass

  return validity_fill, validity_tabs

#-------------------------------------------------------------------------------
# This function looks for the MS Word executable. It scans the program folders 
# on drive C.
#
# PARAM   -/-
#
# RETURN  Full absolute path to the MS Word executable
#
# EXCEPT  FileNotFoundError - if the executable was not found
#-------------------------------------------------------------------------------
def GetWinwordExe():
  """
  Function        :  GetWinwordExe
  Description     :  
  Returns         :  
  """
  # custom exception: used inside this function when the word exe was found
  class MSWordFound(Exception): pass
  
  try:
    # try the Office default location
    exe = "c:\\Program Files (x86)\\Microsoft Office\\Office12\\winword.exe"
    if os.path.exists(exe):
      raise MSWordFound
    
    # try alternative Office default location
    exe = "c:\\Program Files (x86)\\Microsoft Office\\Office14\\winword.exe"
    if os.path.exists(exe):
      raise MSWordFound
    
    # scan complete file structure
    for root, dirs, files in os.walk ("c:\\program files (x86)\\"):
      for f in files:
        if "winword.exe" == f.lower ():
          exe = root + "\\winword.exe"
          raise MSWordFound
    
    # scan alternative file structure
    for root, dirs, files in os.walk ("c:\\program files\\"):
      for f in files:
        if "winword.exe" == f.lower ():
          exe = root + "\\winword.exe"
          raise MSWordFound
    
  except MSWordFound:
    # this is the exit point when the file was found
    pass
    
  else:
    # MS Word not found => throw an exception
    raise FileNotFoundError, "Couldn't find MS Word executable file."

  return exe

#-------------------------------------------------------------------------------
# Compares <cur_config> and <comp_config> differences. A list item is considered
# as "different" if neither the version label nor the revision is equal. The 
# first parameter is expected to be a dictionary with shared project names as 
# keys. The value entries are dictionaries as well containing 2 keys: 'LABEL'
# and 'REVISION', each of them is a string.
#
# The result is a list of different shares, each item as dictionary containing 
# the keys 'COMP_NAME', 'FOUND_LABEL', 'FOUND_REV' and 'EXPECTED' for debug.
#
# PARAM   cur_config    current project configuration.
#         comp_config   list as returned by function XML_ParseProjectConfig()
#
# RETURN  List of invalid shared projects
#
# EXCEPT  -/-
#-------------------------------------------------------------------------------
def CheckProjectConfig(cur_config, comp_config):
  """
  Function                 :  CheckProjectConfig
  Description              :  
  cur_config               :  
  comp_config              :  
  Returns                  :  
  """
  global LABEL_REV_PRFX
  num_out_of_sync = []
  
  for conf in comp_config:
    comp_name = conf[0]
    label_or_rev = conf[1]
    
    if label_or_rev.startswith(LABEL_REV_PRFX):
      label_or_rev = label_or_rev[len(LABEL_REV_PRFX):]
    
    try:
      if (label_or_rev <> cur_config[comp_name]['LABEL']) and (label_or_rev <> cur_config[comp_name]['REVISION']):
        
        # add new dictionary to list
        num_out_of_sync += [{
          'COMP_NAME'  :comp_name,
          'FOUND_LABEL':cur_config[comp_name]['LABEL'],
          'FOUND_REV'  :cur_config[comp_name]['REVISION'],
          'EXPECTED'   :label_or_rev,
          }]
    except KeyError:
      # this shared project is not part of the component
      # => this may be ignored
      conf[2] = False
        
  return num_out_of_sync

#-------------------------------------------------------------------------------
# Parses a set of XML file located in <root_dir> that defines the project 
# configuration. The parameter <listfile> defines a file that contains a list
# of files to be parsed. These file will be parsed and then a list of all shared
# projects of type "build" is returned.
#
# PARAM   root_dir    the directory where all XML files have to be located
#         listfile    the filename (w/o path) of the list XML file
#
# RETURN  Config list: [["Name_1", "Label_1"], ["Name_2", "Label_2"], ..]
#
# EXCEPT  FileNotFoundError - if any of the XML files are not existing
#         ExpatError        - if XML document is invalid
#-------------------------------------------------------------------------------
def XML_ParseProjectConfig(root_dir, listfile):
  """
  Function              :  XML_ParseProjectConfig
  Description           :  
  root_dir              :  
  listfile              :  
  Returns               :  
  """
  global LABEL_REV_PRFX
  comp_config = []
  custom_config_v1 = {}
  custom_config_v2 = {}
  
  try:
    # read project configuration list file
    xml_listfile = xml.dom.minidom.parse(File(root_dir + listfile).abspath)
    root = xml_listfile.getElementsByTagName("ConfigSharedProjectsFiles")
    
    if not len(root):
      raise FileFormatError, 'expected root element "ConfigSharedProjectsFiles" in listfile.'

    # list files from config file
    list_FileCfg = root[0].getElementsByTagName("FileCfg")
    for elem_FileCfg in list_FileCfg:
      filename = elem_FileCfg.getAttribute("File")
      
      # read project configuration file
      subfile = xml.dom.minidom.parse(File(root_dir + filename).abspath)
      subfile_root = subfile.getElementsByTagName("ConfigSharedProjects")
      
      if not len(subfile_root):
        raise FileFormatError, 'expected root element "ConfigSharedProjects" in config file.'

      # look for configurations
      list_BaseConfig = subfile_root[0].getElementsByTagName("BaseConfig")
      for elem_BaseConfig in list_BaseConfig:
        list_SharedProject = elem_BaseConfig.getElementsByTagName("SharedProject")
        for elem_SharedProject in list_SharedProject:
          list_Config = elem_SharedProject.getElementsByTagName("Config")
          for elem_Config in list_Config:
            if (elem_Config.getAttribute("Type") == "build"):
              name = elem_SharedProject.getAttribute("CompName")
              label = elem_Config.getAttribute("Label")
              if not label:
                label = LABEL_REV_PRFX + elem_Config.getAttribute("Revision")
              
              # The "True" in index [2] indicates this project occurs in the sandbox
              # It will be reset later if not to remove the project from the list
              comp_config += [[name, label, True]]

      # look for custom configurations (V1)
      list_BaseConfig = subfile_root[0].getElementsByTagName("CustomConfig")
      for elem_BaseConfig in list_BaseConfig:
        list_SharedProject = elem_BaseConfig.getElementsByTagName("SharedProject")
        for elem_SharedProject in list_SharedProject:
          list_Config = elem_SharedProject.getElementsByTagName("Config")
          for elem_Config in list_Config:
            if (elem_Config.getAttribute("Type") == "build"):
              prj_path = elem_SharedProject.getAttribute("SharedPath")
              label = elem_Config.getAttribute("Label")
              if not label:
                label = LABEL_REV_PRFX + elem_Config.getAttribute("Revision")
              name = MKSUTIL_GetSharedProjectNameFromPath(prj_path)
              if name:
                custom_config_v1[name] = label

      # look for custom configurations (V2)
      list_BaseConfig = subfile_root[0].getElementsByTagName("CustomConfigV2")
      for elem_BaseConfig in list_BaseConfig:
        list_SharedProject = elem_BaseConfig.getElementsByTagName("SharedProject")
        for elem_SharedProject in list_SharedProject:
          list_Config = elem_SharedProject.getElementsByTagName("Config")
          for elem_Config in list_Config:
            if (elem_Config.getAttribute("Type") == "build"):
              name = elem_SharedProject.getAttribute("CompName")
              label = elem_Config.getAttribute("Label")
              if not label:
                label = LABEL_REV_PRFX + elem_Config.getAttribute("Revision")
              custom_config_v2[name] = label

      # print warning message if V3 was found
      list_BaseConfig = subfile_root[0].getElementsByTagName("CustomConfigV3")
      if list_BaseConfig:
        print "Warning: custom configuration V3 is not supported (%s)." % filename
          
  except IOError:
    # one of the files
    raise FileNotFoundError, "one of the project configuration XML files was not found."
  
  # replace projects overwritten by custom configs
  for x in comp_config:
    try:
      print 'Custom V2 - "%s" replaced by "%s".' % (x[1], custom_config_v2[x[0]])
      x[1] = custom_config_v2[x[0]]
    except KeyError:
      # not defined in V2 -> try V1 (this is no error)
      try:
        print 'Custom V1 - "%s" replaced by "%s".' % (x[1], custom_config_v1[x[0]])
        x[1] = custom_config_v1[x[0]]
      except KeyError:
        # not defined in V1 => go on with next project (this is no error)
        pass
  
  # sort list by project name (ignore case)
  comp_config = sorted(comp_config, key=lambda k: k[0].upper())
  
  return comp_config

#-------------------------------------------------------------------------------
# Print a message and prompts the user to enter an option. The 2nd parameter
# <options>:
#
#   - must be an array
#   - must consist of 1-character strings an array
#
# The option can be changed and will be confirmed by the ENTER key.
#
# PARAM   message   the printed message
#         options   possible options, e.g. ["y", "n"]
#
# RETURN  the option that was entered by the user
#-------------------------------------------------------------------------------
def GetConfirmation(message, options):
  """
  Function             :  GetConfirmation
  Description          :  
  message              :  
  options              :  
  Returns              :  
  """
  dialog_line = "%s [%s]" % (message, "/".join(options))
  print dialog_line,
  
  answer = None
  while True:
    ch = msvcrt.getch().lower()
    if ch in options:
      # valid answer
      if (ch <> answer):
        if (answer):
          # remove last answer from output
          print "\b\b\b",
        # store answer
        answer = ch
        print answer,
    elif (answer) and (ch == "\r"):
      # ENTER key => confirm answer
      print
      break
    else:
      # invalid key => remove last answer from output
      if (answer) and (ch <> answer):
        print "\b\b \b\b",
      answer = None
  
  return answer

#-------------------------------------------------------------------------------
# This function prints a title header to a console.
#
# PARAM   title   the title string
#
# RETURN  n/a
#-------------------------------------------------------------------------------
def PrintTitle(title):
  """
  Function          :  PrintTitle
  Description       :  
  title             :  
  Returns           :  
  """
  separator = "---------------------------------------------------------------------------------"
  title_end_column = len(title) + 10 + 2
  
  print
  print separator
  print separator[:10] + (" %s " % (title)) + separator[title_end_column:]
  print separator
  print
