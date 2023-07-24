"""
Filename                  :  scons_adas_extensions\autorel_mks_util.py
Description               :  Script that contains MKS functions for the AutoRelease script.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: autorel_mks_util.py
#
# DESCRIPTION: Script that contains MKS functions for the AutoRelease script.
#
# INITIAL AUTHOR: Roland.Stark-EXT (uidw1169)
#
# CREATION DATE: - 2014/01/26
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:51CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: autorel_mks_util.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:51CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.23 2016/05/27 11:38:32CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.22 2016/01/21 06:56:22CET Singh, Vishal (uidj9083) 
# CHANGES:                   Changes after MKS to PTC
# CHANGES:                   Revision 1.21 2015/09/29 14:01:00CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Modified for AutoRrelease feature
# CHANGES:                   --- Added comments ---  uidj9083 [Sep 29, 2015 2:01:01 PM CEST]
# CHANGES:                   Change Package : 374890:1 http://mks-psad:7002/im/viewissue?selection=374890
# CHANGES:                   Revision 1.20 2015/06/26 05:17:20CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:20 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************


#------------------------
#  IMPORTS
#------------------------

import os
import subprocess
import urllib


#------------------------
#  GLOBALS
#------------------------

# Search order for getting shared projects names. ATTENTION: priority increases with list index! Don't change order!!!
# Each list element is a dictionary:
#   'COMP': Comparator to look for
#   'NAME': Special name of shared project. None to use subdirectory as name.
#   'PRFX': True or False. Only active if 'NAME' is set. If True the name is extended by the subdirectory.
SEARCH_ORDER = [
  {'COMP':'05_Algorithm/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/tools/custom/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/component/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Tools/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Base_Development/Base_CGEB/', 'NAME':'Base_CGEB', 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Base_Development/05_Algorithm/STP_SharedToolProjects/04_Engineering/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Base_Development/05_Algorithm/STK_ScriptingToolKit/04_Engineering/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Base_Development/05_Algorithm/ACC_AdaptiveCruiseControl/05_Testing/05_Test_Environment/acc/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Application_Projects/', 'NAME':'Application_Projects', 'PRFX':False},
  {'COMP':'/nfs/projekte1/REPOSITORY/Base_Development/BaseDevelopment_Camera_SW/02_Engineering/', 'NAME':None, 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Base_Development/Base_CoreMPC567/', 'NAME':'Base_CoreMPC567', 'PRFX':False},
  {'COMP':'/nfs/projekte1/REPOSITORY/Base_Development/Base_CoreMPC567/05_Software/03_Design/02_Architecture/CoreMpc567/core_mpc567_rpy/', 'NAME':'SW_CoreComp_', 'PRFX':True},
  {'COMP':'/nfs/projekte1/REPOSITORY/Base_Development/Base_CoreMPC567/05_Software/03_Design/02_Architecture/CoreMpc567/core_mpc567_rpy/Plugins/', 'NAME':'SW_Plugin_', 'PRFX':True},
  {'COMP':'/nfs/projekte1/REPOSITORY/Base_Development/Base_CoreMPC567/05_Software/03_Design/02_Architecture/CoreMpc567/core_mpc567_rpy/Plugins/project.pj', 'NAME':'SW_Plugins', 'PRFX':False},
  {'COMP':'/projekte1/REPOSITORY/Base_Development/Base_Core/', 'NAME':'Base_Core', 'PRFX':False},
  {'COMP':'/PROJECTS/', 'NAME':None, 'PRFX':False},
  {'COMP':'/SW_MFC4xx/SW_SMFC400_PR/04_Engineering/02_Development_Tools/', 'NAME':'SW_', 'PRFX':True},
  {'COMP':'/SW_MFC4xx/', 'NAME':None, 'PRFX':False},
  {'COMP':'/nfs/projekte1/REPOSITORY/Base_Development/Generic_Software_Modules/MPC56XXK/', 'NAME':'GenSwMod_MPC56XXK_', 'PRFX':True},
  {'COMP':'/nfs/projekte1/REPOSITORY/Base_Projects/SMFC4B0_FBL/05_Software/M11_UFBL/', 'NAME':'SMFC4B0_FBL_M11_UFBL', 'PRFX':False},
  ]

#------------------------
#  FUNCTIONS
#------------------------

#-------------------------------------------------------------------------------
# Check-In all files in <ci_paths> that are locked with <chg_pck>.
#
# PARAM   chg_pck   the change package ID as string, e.g. "123456:14"
#         ci_paths  list of paths to check-in
#         ci_files  list of single files to check-in
#         ci_label  optional label, None is default
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_CheckIn(chg_pck, ci_paths, ci_files, ci_label=None):
  """
  Function              :  MKS_CheckIn
  Description           :  
  chg_pck               :  
  ci_paths              :  
  ci_files              :  
  ci_label              :  
  Returns               :  
  """
  success = True
  
  PrintTitle("CHECK IN")

  # check-in command line options
  opts_chngpk = '--changePackageId=%s' % (chg_pck)
  opts_common = '--nocloseCP --description="New version released" --nolock --unlock --update'
  opts_path   = '--nocheckinUnchanged --recurse'
  opts_label  = ''
  if ci_label:
    opts_label  = '--label=%s' % ci_label

  for path in ci_paths:
    # check in all files in 05_Deliverables\dll
    cmd_line = "C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si ci %s %s %s %s %s\\*.*" % (opts_chngpk, opts_common, opts_path, opts_label, Dir(path).abspath)
    ProcHandle = subprocess.Popen(cmd_line)
    if ProcHandle.wait():
      # exit if process returns a failure
      success = False
      break

  if success:
    # check in single files
    for file in ci_files:
      cmd_line = "C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si ci %s %s %s %s" % (opts_chngpk, opts_common, opts_label, file)
      ProcHandle = subprocess.Popen(cmd_line)
      if ProcHandle.wait():
        # exit if process returns a failure
        success = False
        break

  return success

#-------------------------------------------------------------------------------
# Generate a project checkpoint in <cp_path> recursive. As checkpoint label 
# <cp_label> is used.
#
# PARAM   cp_path   root path to generate checkpoint
#         cp_label  the version label as string (no white spaces allowed).
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_GenerateCheckpoint(cp_path, cp_label):
  """
  Function              :  MKS_GenerateCheckpoint
  Description           :  
  cp_path               :  
  cp_label              :  
  Returns               :  
  """
  success = True
  
  # checkpoint current state
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si checkpoint --batch --description="New version released: %s" --forceConfirm=no --label=%s --cwd=%s' % (cp_label, cp_label, cp_path)
  ProcHandle = subprocess.Popen(cmd_line)
  if ProcHandle.wait():
    success = False

  return success
  
#-------------------------------------------------------------------------------
# Lock all members contained in <path_list>.
#
# PARAM   cp_path   root path to label members
#         cp_label  the version label as string (no white spaces allowed).
#         recurse   True to label all members recursive, False is default.
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_LabelMembers(cp_path, cp_label, recurse=False):
  """
  Function              :  MKS_LabelMembers
  Description           :  
  cp_path               :  
  cp_label              :  
  recurse               :  
  Returns               :  
  """
  success = True
  
  # add a label to all files
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si addlabel --batch --forceConfirm=no --label=%s --cwd="%s"' % (cp_label, cp_path)
  if recurse:
    cmd_line += ' --recurse'
  
  ProcHandle = subprocess.Popen(cmd_line)
  if ProcHandle.wait():
    success = False
  
  return success
  
#-------------------------------------------------------------------------------
# Returns whether <member_file> is a member in MKS or not. 
#
# PARAM   member_file   absolute member path and name
#
# RETURN  True if member exists, False otherwise.
#-------------------------------------------------------------------------------
def MKS_IsMemberExisting(member_file):
  """
  Function                :  MKS_IsMemberExisting
  Description             :  
  member_file             :  
  Returns                 :  
  """
  member_exists = False

  # call MKS command line interface
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si memberinfo --batch "%s"' % (member_file)
  prog = subprocess.Popen(cmd_line)
  ProcHandle = subprocess.Popen(cmd_line)
  if not ProcHandle.wait():
    member_exists = True
  
  return member_exists

#-------------------------------------------------------------------------------
# Adds <member_file> to MKS sandbox. 
#
# PARAM   chg_pck       the change package ID as string, e.g. "123456:14"
#         member_file   absolute member path and name
#
# RETURN  True if successful, False otherwise.
#-------------------------------------------------------------------------------
def MKS_AddMember(chg_pck, member_file):
  """
  Function                 :  MKS_AddMember
  Description              :  
  chg_pck                  :  
  member_file              :  
  Returns                  :  
  """
  success = True

  # call MKS command line interface
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si add --batch --description="%s" --cpid=%s "%s"' % ("Initial revision by AutoRelease.", chg_pck, member_file)
  ProcHandle = subprocess.Popen(cmd_line)
  if ProcHandle.wait():
    success = False
  
  return success

#-------------------------------------------------------------------------------
# Lock all members contained in <path_list>.
#
# PARAM   file_list   list of members to lock
#         cp_id       the change package ID as string
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_LockMembers(file_list, cp_id):
  """
  Function              :  MKS_LockMembers
  Description           :  
  file_list             :  
  cp_id                 :  
  Returns               :  
  """
  success = True
  
  for lock_file in file_list:
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si lock --changePackageId=%s "%s"' % (cp_id, File(lock_file).abspath)
    ProcHandle = subprocess.Popen(cmd_line)
    if ProcHandle.wait():
      # return <> 0 => error
      print "[FAILED]"
      success = False
      break
    print "[OK]"
  
  return success

#-------------------------------------------------------------------------------
# Unlocks all members contained in <file_list>.
#
# PARAM   file_list   list of members to lock
#
# RETURN  False if successful, True otherwise
#-------------------------------------------------------------------------------
def MKS_UnlockMembers(file_list):

  """
  Function              :  MKS_UnlockMembers
  Description           :  
  file_list             :  
  Returns               :  
  """
  for lock_file in file_list:  
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si unlock --action=remove "%s"' % (File(lock_file).abspath)
    ProcHandle = subprocess.Popen(cmd_line)
    ProcHandle.wait()

#-------------------------------------------------------------------------------
# Lock all member recursively in all paths contained in <path_list>.
#
# PARAM   path_list   list of paths to lock
#         cp_id       the change package ID as string
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_LockPathsRecurse(path_list, cp_id):
  """
  Function              :  MKS_LockPathsRecurse
  Description           :  
  path_list             :  
  cp_id                 :  
  Returns               :  
  """
  success = True
  
  for lock_path in path_list:
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si lock --recurse --changePackageId=%s --no --cwd="%s"' % (cp_id, Dir(lock_path).abspath)
    ProcHandle = subprocess.Popen(cmd_line)
    if ProcHandle.wait():
      # abort if an action fails
      success = False
      break
  
  return success

#-------------------------------------------------------------------------------
# Unlocks all locked member recursively in all paths contained in <path_list>.
#
# PARAM   path_list   list of paths to lock
#
# RETURN  n/a
#-------------------------------------------------------------------------------
def MKS_UnlockPathsRecurse(path_list):
  """
  Function              :  MKS_UnlockPathsRecurse
  Description           :  
  path_list             :  
  Returns               :  
  """
  for lock_path in path_list:
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si unlock --recurse --action=remove --cwd="%s"' % (Dir(lock_path).abspath)
    ProcHandle = subprocess.Popen(cmd_line)
    ProcHandle.wait()

#-------------------------------------------------------------------------------
# Freezes all members inside a sandbox (sub-sandbox) or a specific one.
#
# PARAM   freeze_path   working path for freezing (sandbox or sub-sandbox)
#         freeze_file   raw filename inside <freeze_path>, None to freeze all.
#                       Optional -> defaults to None
#         debug         True to print debug information, False to hide.
#                       Optional -> defaults to False
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_FreezeMembers(freeze_path, freeze_file=None, debug=False):
  """
  Function                 :  MKS_FreezeMembers
  Description              :  
  freeze_path              :  
  freeze_file              :  
  debug                    :  
  Returns                  :  
  """
  success = True
  
  options = "--batch --norecurse"
  if not debug:
    options += " --quiet"
  
  if not freeze_file:
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si freeze %s --cwd="%s"' % (options, Dir(freeze_path).abspath)
  else:
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si freeze %s --cwd="%s" %s' % (options, Dir(freeze_path).abspath, freeze_file)
  
  ProcHandle = subprocess.Popen(cmd_line)
  if ProcHandle.wait():
    success = False
    
  if debug: print "Freeze State: %s" % str(success)
  
  return success

#-------------------------------------------------------------------------------
# Thaws all members inside a sandbox (sub-sandbox) or a specific one.
#
# PARAM   thaw_path     working path for thawing (sandbox or sub-sandbox)
#         thaw_file     raw filename inside <thaw_path>, None to thaw all.
#                       Optional -> defaults to None
#         debug         True to print debug information, False to hide.
#                       Optional -> defaults to False
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_ThawMembers(thaw_path, thaw_file=None, debug=False):
  """
  Function               :  MKS_ThawMembers
  Description            :  
  thaw_path              :  
  thaw_file              :  
  debug                  :  
  Returns                :  
  """
  success = True
  
  options = "--batch --norecurse"
  if not debug:
    options += " --quiet"
  
  if not thaw_file:   
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si thaw %s --cwd="%s"' % (options, Dir(thaw_path).abspath)
  else:
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si thaw %s --cwd="%s" %s' % (options, Dir(thaw_path).abspath, thaw_file)	
  
  ProcHandle = subprocess.Popen(cmd_line)
  if ProcHandle.wait():
    success = False
    
  if debug: print "Thaw State: %s" % str(success)
  
  return success

#-------------------------------------------------------------------------------
# Freezes/Thaws all members in non-shared sub-sandboxes recursive. Shared sub-
# sandboxes are ignored completely. Whether this function runs in freeze or thaw
# mode is defined with the 2nd parameter <freeze_mode>.
#
# The root path for the recursive run is <sandbox_path>.
#
# Normally debug output is disabled but could be switched on with the 3rd 
# parameter.
#
# PARAM   sandbox_path  root path for scan
#         freeze_mode   True to freeze, False to thaw
#         debug         True to print debug information, False to hide.
#                       Optional -> defaults to False
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_FreezeOrThawSandboxRecurse(sandbox_path, freeze_mode, debug=False):
  
  """
  Function                 :  MKS_FreezeOrThawSandboxRecurse
  Description              :  
  sandbox_path             :  
  freeze_mode              :  
  debug                    :  
  Returns                  :  
  """
  NONSHARED_SUB_SANDBOXES = ["subsandbox", "variant-subsandbox"]
  
  # handle all members in this sandbox
  success = True
  if freeze_mode:
    success = MKS_FreezeMembers(sandbox_path, debug=debug)
  else:
    success = MKS_ThawMembers(sandbox_path, debug=debug)
    
  if success:
    # call MKS command line interface
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si viewsandbox --batch --cwd="%s" --fields=name,type --forceConfirm=yes --quiet --norecurse' % (Dir(sandbox_path).abspath)
    prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
    stdout,_ = prog.communicate()

    # process non-shared sub-sandboxes
    for line in stdout.splitlines():
      line_tokens = line.strip().split(' ')
      if (line_tokens[-1] in NONSHARED_SUB_SANDBOXES):
        success = MKS_FreezeOrThawSandboxRecurse(line[0:line.find("project.pj")], freeze_mode, debug)
        if not success: break

  return success

#-------------------------------------------------------------------------------
# Returns all members that are locked by current user in a list. Each list entry
# is a dictionary with the following keys:
#
#   'name':       the name of the member (pure filename)
#   'local_path': the local path where the member is located
#   'sandbox':    the name of members archive ('local_path' + /project.pj)
#   'archive':    the database path of member's archive
#
# If there is no member locked, an empty list is returned.
#
# PARAM   sandbox_path  some path inside the sandbox
#
# RETURN  list of locked members ([{},{},...] -> length is zero if none locked)
#-------------------------------------------------------------------------------
def MKS_GetMemersLockedByMe(sandbox_path):
  """
  Function                 :  MKS_GetMemersLockedByMe
  Description              :  
  sandbox_path             :  
  Returns                  :  
  """
  locked_members = []
    
  # call MKS command line interface
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si locks --hostname=IMS-ADAS --locker=%s --cwd="%s" --fields=archive,sandbox,member --quiet' % (os.environ['USERNAME'], Dir(sandbox_path).abspath)
  
  prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)  
  stdout,_ = prog.communicate()

  # process non-shared sub-sandboxes
  for line in stdout.splitlines():
    line_tokens = line.split()
    if (len(line_tokens) == 3):
      # remove '/project.pj' (11 characters at the end)
      local_path = line_tokens[1][:-11]
      locked_members += [{'archive':line_tokens[0], 'sandbox':line_tokens[1], 'name':line_tokens[2], 'local_path':local_path}]

  return locked_members

#-------------------------------------------------------------------------------
# Resynchronizes all files in <file_list> to member revision.
#
# PARAM   file_list   list of members to lock
#
# RETURN  n/a
#-------------------------------------------------------------------------------
def MKS_ResyncMembers(file_list):
  """
  Function              :  MKS_ResyncMembers
  Description           :  
  file_list             :  
  Returns               :  
  """
  for lock_file in file_list:
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si resync --yes "%s"' % (File(lock_file).abspath)
    ProcHandle = subprocess.Popen(cmd_line)
    ProcHandle.wait()

#-------------------------------------------------------------------------------
# Resynchronizes all files in <sync_path> recursively to member revision.
#
# PARAM   sync_path the root path to sync
#
# RETURN  n/a
#-------------------------------------------------------------------------------
def MKS_ResyncPathRecurse(sync_path):
  """
  Function              :  MKS_ResyncPathRecurse
  Description           :  
  sync_path             :  
  Returns               :  
  """
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si resync --batch --overwriteChanged --quiet --cwd="%s"' % (Dir(sync_path).abspath)
  ProcHandle = subprocess.Popen(cmd_line)
  ProcHandle.wait()

#-------------------------------------------------------------------------------
# Returns a list of all available change packages for current MKS user. The list
# is returned as a pair of change package ID and summary, both as a tuple.
#
# PARAM   sandbox_path    any path inside sandbox
#         debug           True for debug output (optional, default is False)
#
# RETURN  List of change packages: [(ID1, Summary1), (ID2, Summary2)...]
#-------------------------------------------------------------------------------
def MKS_ListChangePackages(sandbox_path, debug=False):
  """
  Function                 :  MKS_ListChangePackages
  Description              :  
  sandbox_path             :  
  debug                    :  
  Returns                  :  
  """
  chgp_list = []
  
  # execute request
  cmd_line = "C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si viewcps --hostname=IMS-ADAS --fields=id,summary --cwd=\"%s\"" % (Dir(sandbox_path).abspath)
  prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
  stdout,_ = prog.communicate()

  # scan list
  for line in stdout.splitlines():
    tokens = line.split("\t")
    chgp_list += [(tokens[0], tokens[1].strip())]
    
    if debug:
      print "%s - %s" % (tokens[0], tokens[1])   
  return chgp_list

#-------------------------------------------------------------------------------
# Checks a list of paths [prj_path_list] for inconsistent file, i.e. members
# out of sync, changed or locked files. Then it creates a list of files relative
# to <base_path>. In parallel there is a 2nd list created containing the kind of
# the change. Both lists are returned.
#
# In case of consistency both lists are empty (length = 0).
#
# PARAM   base_path       base path for relative path generation
#         prj_path_list   list of bath for recursive scanning
#         debug           True for debug output (opt., default is False)
#         recurse         True for recurse into projects (opt., default is True)
#
# RETURN  List of files, List of kinds
#-------------------------------------------------------------------------------
def MKS_GetChangedFiles(base_path, prj_path_list, debug=False, recurse=True):
  """
  Function                   :  MKS_GetChangedFiles
  Description                :  
  base_path                  :  
  prj_path_list              :  
  debug                      :  
  recurse                    :  
  Returns                    :  
  """
  file_list = []
  change_kinds = []
  
  # output setup
  if recurse:
    options  = "--recurse"
  else:
    options  = "--norecurse"
    
  filter   = "changed:working,changed:sync,locked:%s" % (os.environ['USERNAME'])
  format   = "{membername}\\t{memberrev}\\t{workingrev}\\t{workingfileexists}\\t{alllockers}\\t{workingrevdelta}\\n"

  for prj_path in prj_path_list:
    # execute request
    cmd_line = "C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si print %s --filter=%s --headerFormat=\"%s\" --cwd=\"%s\"" % (options, filter, format, Dir(prj_path).abspath)
    prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
    stdout,_ = prog.communicate()

    # scan piped output
    for line in stdout.splitlines():
      # add inconsistent file
      out_of_sync_file = line.split("\t")
      rel_file = os.path.relpath(File(prj_path + "/" + out_of_sync_file[0]).abspath, Dir(base_path).abspath)
      file_list += [rel_file]
      
      # kind of difference
      if (out_of_sync_file[3] == '0'):
        change_kinds += ["NO WORKFILE"]
      elif (out_of_sync_file[1] <> out_of_sync_file[2]):
        change_kinds += ["OUT OF SYNC"]
      elif (out_of_sync_file[4]):
        change_kinds += ["LOCKED"]
      elif (out_of_sync_file[5]):
        change_kinds += ["MODIFIED"]

      if debug:
        print "%s (%s)" % (rel_file, change_kinds[-1])
  
  return file_list, change_kinds

#-------------------------------------------------------------------------------
# Creates a list of issues that are planned along with one or multiple releases.
# IDs passed to this function that are not of type "Release" will be ignored and
# a waring message is printed.
# In case of any unexpected exception 3 empty lists are returned.
#
# PARAM   release_ids   list of release ids, all elements integers.
#
# RETURN  [{problem reports}], [{feature requests}], [{change request}]
#-------------------------------------------------------------------------------
def MKS_GetReleaseIssues(release_ids):
  """
  Function                :  MKS_GetReleaseIssues
  Description             :  
  release_ids             :  
  Returns                 :  
  """
  issue_list    = []
  issue_list_pr = []
  issue_list_fr = []
  issue_list_cr = []
  not_valid_state = []
  ro_vaild_state = []  
  # considered item states. DON'T CHANGE ORDER - IT'S ACCORDING TO THE WORKFLOW
  valid_states = ['Closed', 'Realized', 'Accepted', 'Canceled', 'Duplicate']

  try:
    # early exit if no issues are planned for releases
    if len(release_ids) == 0:
      raise RuntimeError
    
    # request planned issues from a release
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/im issues --hostname=IMS-ADAS --fields="ID,Type,Planned Requests,Planned Items,Orders" ' + ' '.join(str(relid) for relid in release_ids)
    prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
    stdout,_ = prog.communicate()

    # scan piped output
    for line in stdout.splitlines():
      planned_req = line.strip().split("\t")
      while '' in planned_req:	
        planned_req.remove('')	  
      
      # check if planned requests exist
      if (planned_req[1] == "Release"):
        issue_RO_len = len(planned_req) - 2	
        for Issue_length in range(0,issue_RO_len):
          issues = map(int, planned_req[2+Issue_length].split(", "))
          issue_list += issues		  
      else:
        print "Warning: Item " + planned_req[0] + " is not a release."
    	
    # early exit if no issues are planned for releases
    if len(issue_list) == 0:
      raise RuntimeError
    
    # remove duplicates and sort result
    dummy = {}
    for e in issue_list:
      dummy[e] = 1
    issue_list = sorted(dummy.keys())
    
    # request issues details
    cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/im issues --hostname=IMS-ADAS --fields="ID,Type,Issue Type,State,Summary" ' + ' '.join(str(issueid) for issueid in issue_list)
    prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
    stdout,_ = prog.communicate()
    # scan piped output
    for line in stdout.splitlines():
      issue_fields = line.strip().split("\t")		  
      if (issue_fields[1] == "Issue") and (issue_fields[3] in valid_states):
        if issue_fields[2] == "Problem Report":	
          issue_list_pr += [{'issue_id':int(issue_fields[0]), 'issue_state':issue_fields[3], 'issue_sum':issue_fields[4]}]
        elif issue_fields[2] == "Feature Request":		
          issue_list_fr += [{'issue_id':int(issue_fields[0]), 'issue_state':issue_fields[3], 'issue_sum':issue_fields[4]}]
        elif issue_fields[2] == "Change Request":		
          issue_list_cr += [{'issue_id':int(issue_fields[0]), 'issue_state':issue_fields[3], 'issue_sum':issue_fields[4]}]
		  
    for line in stdout.splitlines():
      ro_fields = line.strip().split("\t")
      if (ro_fields[1] == "Realization Order") and (ro_fields[3] in valid_states):	  
        ro_vaild_state += [{'issue_id':int(ro_fields[0]), 'issue_type':ro_fields[1], 'issue_state':ro_fields[3], 'issue_sum':ro_fields[4]}]	
	  
		  
    for line in stdout.splitlines():
      issue_fields = line.strip().split("\t")	
      if (issue_fields[1] == "Issue" or issue_fields[1] == "Realization Order")	and (issue_fields[3] not in valid_states):
        not_valid_state += [{'issue_id':int(issue_fields[0]), 'issue_type':issue_fields[1], 'issue_state':issue_fields[3], 'issue_sum':issue_fields[4]}]
	  
    # sort by state (workflow descending)
    issue_list_pr = sorted(issue_list_pr, key=lambda k: valid_states.index(k['issue_state'])) 
    issue_list_fr = sorted(issue_list_fr, key=lambda k: valid_states.index(k['issue_state'])) 
    issue_list_cr = sorted(issue_list_cr, key=lambda k: valid_states.index(k['issue_state']))
  except:
    # init output lists
    issue_list_pr = []
    issue_list_fr = []
    issue_list_cr = []
    not_valid_state = []
    ro_vaild_state = []	
  
  return issue_list_pr, issue_list_fr, issue_list_cr, not_valid_state, ro_vaild_state
  
#-------------------------------------------------------------------------------
# Returns a URL to a the MKS web interface providing information about a 
# project/sub-project. If the sandbox is configured on a development path it
# is also returned.
#
# Example:
#   mks_url, dev_path = MKS_GetProjectInfo("D:/sandbox/project")
#
# PARAM   prj_path    path to mks file "project.pj"
#
# RETURN  - URL to project path if succeeded, "n/a" if failed.
#         - Development Path if available, "n/a" otherwise.
#         - Project database path
#-------------------------------------------------------------------------------
def MKS_GetProjectInfo(prj_path):
  """
  Function             :  MKS_GetProjectInfo
  Description          :  
  prj_path             :  
  Returns              :  
  """
  mks_url  = "n/a"
  dev_path = "n/a"

  try:
    # call MKS command line interface
    cmd_line = "C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si projectinfo --nodevpaths --noassociatedIssues --noshowCheckpointDescription --noattributes --noacl --cwd=\"" + Dir(prj_path).abspath + "\""
    prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
    stdout,_ = prog.communicate()

    prj_url = None
    server = None

    # scan piped output
    for line in stdout.splitlines():
      if "Project Name:" in line:
        prj_url = line.split(":", 1)[1].strip()
      elif "Server:" in line:
        server = line.split(":", 1)[1].strip()
      elif "Development Path:" in line:
        dev_path = line.split(":", 1)[1].strip()

    # check output
    if (server == None) or (prj_url == None):
      raise Exception('unexpected si utility output')
    
    # create quoted URL
    mks_url = "http://" + server + "/si/viewproject?projectName=" + urllib.quote(prj_url)
  except:
    mks_url  = "n/a"
    dev_path = "n/a"
  
  return mks_url, dev_path, prj_url

#-------------------------------------------------------------------------------
# Returns the pure name of an MKS project.
#
# PARAM   prj_path    path to mks file "project.pj"
#
# RETURN  Project name or "--" if an unexpected error occurred.
#-------------------------------------------------------------------------------
def MKS_GetProjectName(prj_path):
  """
  Function             :  MKS_GetProjectName
  Description          :  
  prj_path             :  
  Returns              :  
  """
  pj_name = "--"

  try:
    # call MKS command line interface
    cmd_line = "C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si projectinfo --nodevpaths --noassociatedIssues --noshowCheckpointDescription --noattributes --noacl --cwd=\"" + Dir(prj_path).abspath + "\""
    prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
    stdout,_ = prog.communicate()

    # scan piped output
    for line in stdout.splitlines():
      if "Configuration Path:" in line:
        
        # remove dev path if existing
        dev_path_idx = line.find("#d=")
        if (dev_path_idx != -1):
          line = line[:dev_path_idx]
        
        # use string after last separator as project name
        cfg_path = line.strip().split("/")
        last_index = len(cfg_path) - 1
        if (last_index >= 0):
          pj_name = cfg_path[last_index]
  except:
    pass
  
  return pj_name

#-------------------------------------------------------------------------------
# Scans an MKS project recursive for shared sub-sandboxes. This function is 
# recursive and calls it self for all other sandboxes. To check abort project 
# the "viewsandbox" command of "si" tool is used.
#
# A list of "build" sub-sandboxes is returned as first value.
#
# The 2nd return value is the list of shared sub-sandboxes that are not type
# "build" which is not allowed. Please check in a post process whether the
# non-builds are shared are from the sandbox internally.
#
# The 3rd return value is the list of sub-sandboxes that are not shared.
#
# PARAM   prj_path    root path for scan
#
# RETURN  - list of shared sub-sandboxes
#         - list of non-build shared sub-sandboxes
#         - list of non-shared sub-sandboxes
#-------------------------------------------------------------------------------
def MKS_GetSharedProjListRecurse(prj_path):
  """
  Function             :  MKS_GetSharedProjListRecurse
  Description          :  
  prj_path             :  
  Returns              :  
  """
  list = []
  invalid_list = []
  non_shared_list = []
  
  SUB_SANDBOXES = ["subsandbox", "variant-subsandbox", "build-subsandbox"]
  ILLEGAL_SHARED_SUB_SANDBOXES = ["shared-variant-subsandbox", "shared-subsandbox"]

  # add own dir to non-shared list
  non_shared_list += [Dir(prj_path).abspath]
  
  # call MKS command line interface
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si viewsandbox --batch --cwd="%s" --fields=name,type --forceConfirm=yes --quiet --norecurse' % (non_shared_list[0])
  prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
  stdout,_ = prog.communicate()

  for line in stdout.splitlines():
    line_tokens = line.strip().split(' ')
    
    if (line_tokens[-1] == "shared-build-subsandbox"):
      retDict = {"PROJECT":line_tokens[0], "REVISION":line_tokens[1][1:-1]}
      list += [retDict]
    elif (line_tokens[-1] in ILLEGAL_SHARED_SUB_SANDBOXES):
      shared_dir = Dir(line_tokens[0].replace("project.pj","")).abspath
      invalid_list += [[shared_dir, MKS_GetProjectDatabasePath(shared_dir)]]
    elif (line_tokens[-1] in SUB_SANDBOXES):
      list_1, list_2, list_3 = MKS_GetSharedProjListRecurse(line[0:line.find("project.pj")])
      list += list_1
      invalid_list += list_2
      non_shared_list += list_3

  return list, invalid_list, non_shared_list

#-------------------------------------------------------------------------------
# Scans an MKS project for non-shared sub-sandboxes. The pure names of the 
# sanboxes (without path) are returned as a list.
#
# PARAM   prj_path    path for scan
#
# RETURN  - list of sub-sandbox names
#-------------------------------------------------------------------------------
def MKS_GetSubProjList(prj_path):
  """
  Function             :  MKS_GetSubProjList
  Description          :  
  prj_path             :  
  Returns              :  
  """
  list = []

  NONSHARED_SUB_SANDBOXES = ["subsandbox", "variant-subsandbox"]
  
  # call MKS command line interface
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si viewsandbox --batch --cwd="%s" --fields=name,type --forceConfirm=yes --quiet --norecurse' % (Dir(prj_path).abspath)
  prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
  stdout,_ = prog.communicate()

  for line in stdout.splitlines():
    line_tokens = line.strip().split(' ')
    if (line_tokens[-1] in NONSHARED_SUB_SANDBOXES):
      prj_path = line_tokens[0].replace('\\', '/').split('/')
      list += [prj_path[-2]]

  return list

#-------------------------------------------------------------------------------
# Returns the MKS database path of a shared project.
#
# PARAM   prj_path    local project path
#
# RETURN  MKS database path or None if no matching database path was found
#-------------------------------------------------------------------------------
def MKS_GetProjectDatabasePath(prj_path):
  """
  Function             :  MKS_GetProjectDatabasePath
  Description          :  
  prj_path             :  
  Returns              :  
  """
  shared_path = None

  # call MKS command line interface
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si projectinfo --batch --nodevpaths --noassociatedIssues --noshowCheckpointDescription --noattributes --noacl --cwd="%s"' % (prj_path)
  prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
  stdout,_ = prog.communicate()
  
  # scan piped output
  for line in stdout.splitlines():
    if "Repository Location:" in line:	
      shared_path = line.split(" ")[-1]
      break

  return shared_path

#-------------------------------------------------------------------------------
# Scans MKS project history of <prj_path> for a version label that matches 
# <prj_rev>.
#
# PARAM   prj_path    project path to check history
#         prj_rev     project revision number as string
#
# RETURN  revision label as string or None if version was not found
#-------------------------------------------------------------------------------
def MKS_GetSharedProjectLabel(prj_path, prj_rev):
  """
  Function             :  MKS_GetSharedProjectLabel
  Description          :  
  prj_path             :  
  prj_rev              :  
  Returns              :  
  """
  pj_label = None

  # call MKS command line interface
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si viewprojecthistory --batch --fields=labels,revision --rfilter=labeled --cwd="%s"' % (prj_path)
  prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
  stdout,_ = prog.communicate()

  # scan piped output
  for line in stdout.splitlines():
    # skip 1st line which prints the project path
    if "project.pj" in line:
      continue

    line_tokens = line.strip().split()
    if (prj_rev == line_tokens[1]):
      # get the label that matches revision
      pj_label = line_tokens[0]
      break
  
  return pj_label

#-------------------------------------------------------------------------------
# Determines the names of a shared project. The depends is part of the MKS 
# database path but is handled differently for different projects.
#
# PARAM   prj_path    project path to get name from
#
# RETURN  project name or None if no matching database path was found
#-------------------------------------------------------------------------------
def MKS_GetSharedProjectName(prj_path):
  """
  Function             :  MKS_GetSharedProjectName
  Description          :  
  prj_path             :  
  Returns              :  
  """
  pj_name = None

  shared_path = MKS_GetProjectDatabasePath(prj_path)
  if shared_path:
      pj_name = MKSUTIL_GetSharedProjectNameFromPath(shared_path)
    
  return pj_name

#-------------------------------------------------------------------------------
# Determines the name of a shared project. The is part of the MKS database path 
# but is handled differently for different projects.
#
# PARAM   shared_path   MKS database path
#
# RETURN  project name or None if no matching database path was found
#-------------------------------------------------------------------------------
def MKSUTIL_GetSharedProjectNameFromPath(shared_path):
  """
  Function                :  MKSUTIL_GetSharedProjectNameFromPath
  Description             :  
  shared_path             :  
  Returns                 :  
  """
  global SEARCH_ORDER
  pj_name = None

  for x in reversed(SEARCH_ORDER):
    start = shared_path.find(x['COMP'])
    if (start != -1):
      if x['NAME'] and not x['PRFX']:
        pj_name = x['NAME']
      else:
        end = shared_path.find('/', start + len(x['COMP']))
        pj_name = shared_path[start + len(x['COMP']):end]
        if x['PRFX']:
          pj_name = "%s%s" % (x['PRFX'], pj_name)
      
      # abort search because matching project was found
      break

  return pj_name

#-------------------------------------------------------------------------------
# Scans an MKS project recursive for shared members. All found are returned as a
# list. Each list item is a dictionary with the following keys:
#
#   'name':    full path and filename in the sandbox
#   'archive': MKS database where it was shared from
#   'rev':     the member revision
#
# PARAM   prj_path    root path for scan
#
# RETURN  list of shared members
#-------------------------------------------------------------------------------
def MKS_GetSharedMembersRecurse(prj_path):
  """
  Function             :  MKS_GetSharedMembersRecurse
  Description          :  
  prj_path             :  
  Returns              :  
  """
  member_list = []
  
  # call MKS command line interface
  fields  = 'name,memberarchive,type,memberrev'
  filters = 'archiveshared'
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si viewsandbox --batch --recurse --quiet --fields=%s --filter=%s --cwd="%s"' % (fields, filters, Dir(prj_path).abspath)
  prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
  stdout,_ = prog.communicate()

  for line in stdout.splitlines():
    line_tokens = line.strip().split(' ')
    
    # this ignores projects
    if (len(line_tokens) < 4):
      continue
    
    if (line_tokens[2] == "archived"):
      member_list += [{'name':line_tokens[0], 'archive':line_tokens[1], 'rev':line_tokens[3]}]
      
  return member_list

#-------------------------------------------------------------------------------
# Provides information for a particular member <member_name> as a dictionary 
# with the following keys:
#
#   'name':    full path and filename in the sandbox
#   'archive': MKS database path
#   'rev':     the member revision
#
# PARAM   prj_path      project path for look for member
#         member_name   the pure member name inside <prj_path>
#
# RETURN  member information or 
#         None if member doesn't exist
#-------------------------------------------------------------------------------
def MKS_GetMemberInfo(prj_path, member_name):
  """
  Function                 :  MKS_GetMemberInfo
  Description              :  
  prj_path                 :  
  member_name              :  
  Returns                  :  
  """
  members_info = None
  
  # call MKS command line interface
  fields  = 'name,memberarchive,type,memberrev'
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si viewsandbox --batch --quiet --fields=%s --cwd="%s" %s' % (fields, Dir(prj_path).abspath, member_name)
  prog = subprocess.Popen(cmd_line, stdout=subprocess.PIPE)
  stdout,_ = prog.communicate()

  for line in stdout.splitlines():
    line_tokens = line.strip().split(' ')
    
    # this ignores projects
    if (len(line_tokens) < 4):
      continue
    
    if (line_tokens[2] == "archived"):
      members_info = {'name':line_tokens[0], 'archive':line_tokens[1], 'rev':line_tokens[3]}
      break
      
  return members_info

#-------------------------------------------------------------------------------
# Updates the member revision to a specific revision <new_rev>.
#
# PARAM   member_file   the full path and filename of the file to update
#         chg_pck       the change package ID as string, e.g. "123456:14"
#         new_rev       the new revision number as a string
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_UpdateMemberRev(member_file, chg_pck, new_rev):
  """
  Function                :  MKS_UpdateMemberRev
  Description             :  
  member_file             :  
  chg_pck                 :  
  new_rev                 :  
  Returns                 :  
  """
  success = True
  
  # update command
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si updaterevision --batch --quiet --nocloseCP --changepackageid="%s" --revision="%s" %s' % (chg_pck, new_rev, member_file)
  ProcHandle = subprocess.Popen(cmd_line)
  if ProcHandle.wait():
    success = False
  
  return success

#-------------------------------------------------------------------------------
# Updates the member revision of a complete path to the revision with a specific
# version label.
#
# PARAM   root_path     the full path and filename of the file to update
#         chg_pck       the change package ID as string, e.g. "123456:14"
#         label         the revision label
#
# RETURN  True if successful, False otherwise
#-------------------------------------------------------------------------------
def MKS_UpdateMemberRevRecurse(root_path, chg_pck, label):
  """
  Function              :  MKS_UpdateMemberRevRecurse
  Description           :  
  root_path             :  
  chg_pck               :  
  label                 :  
  Returns               :  
  """
  success = True
  
  # update command
  cmd_line = 'C:/Program Files (x86)/Integrity/IntegrityClient10.6/bin/si updaterevision --batch --quiet --nocloseCP --recurse --changepackageid="%s" --revision="%s" --cwd="%s"' % (chg_pck, label, Dir(root_path).abspath)
  ProcHandle = subprocess.Popen(cmd_line)
  if ProcHandle.wait():
    success = False
  
  return success
