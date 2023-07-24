"""
Filename                  :  scons_adas_extensions\autorel_main.py
Description               :  Script that controls the automatic release sequence and to generate code handover.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: autorel_main.py
#
# DESCRIPTION: Script that controls the automatic release sequence and to generate code handover.
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
# CHANGES:                   $Log: autorel_main.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:51CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.38 2016/05/27 11:37:03CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.37 2015/09/29 14:00:58CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Modified for AutoRrelease feature
# CHANGES:                   - Added comments -  uidj9083 [Sep 29, 2015 2:00:58 PM CEST]
# CHANGES:                   Change Package : 374890:1 http://mks-psad:7002/im/viewissue?selection=374890
# CHANGES:                   Revision 1.36 2015/06/26 05:17:19CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:19 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************


#------------------------
#  IMPORTS
#------------------------

import os
import shutil


#------------------------
#  EXCEPTIONS
#------------------------

class AutoReleaseAbortException(RuntimeError): pass
class AutoReleaseRestoreException(RuntimeError): pass
class UserTerminationException(RuntimeError): pass


#------------------------
#  EXTERNAL SCRIPTS
#------------------------

# read other file of the auto release package from same directory
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
execfile(sconscript_dir + "/autorel_functions.py")
execfile(sconscript_dir + "/autorel_mks_util.py")
execfile(sconscript_dir + "/autorel_word_util.py")
execfile(sconscript_dir + "/ram_rom_algo_libsize.py")

#------------------------
#  GLOBALS
#------------------------

# List of AutoRelease return values
RETVAL_AUTOREL = {
  'AUTOREL_OK'                :   0,  # no errors
  'AUTOREL_ERR_CONSCHECK'     :   1,  # consistency check failed
  'AUTOREL_ERR_LISTCHGP'      :   2,  # DEPRECATED(not used): getting change packages failed
  'AUTOREL_ERR_VERFILE'       :   3,  # the version file was not found
  'AUTOREL_ERR_INVVERFILE'    :   4,  # invalid version file format (unexpected content)
  'AUTOREL_ERR_LOCKMEM'       :   5,  # locking single member failed
  'AUTOREL_ERR_LOCKDIRS'      :   6,  # locking release paths failed
  'AUTOREL_ERR_WRITEVERFILE'  :   7,  # changing version file failed
  'AUTOREL_ERR_LIBSIZE'       :   8,  # libsize files were not found
  'AUTOREL_ERR_REBUILD'       :   9,  # rebuilding libs failed
  'AUTOREL_ERR_HANDOVER'      :  10,  # creating code handover document failed
  'AUTOREL_ERR_INSTALL'       :  11,  # the installation of the code handover failed
  'AUTOREL_ERR_CHECKIN'       :  12,  # check-in failed
  'AUTOREL_ERR_CHECKPOINT'    :  13,  # creating checkpoint failed
  'AUTOREL_ERR_PROJCONF'      :  14,  # parsing xml project configuration failed
  'AUTOREL_ERR_INV_VERNUM'    :  15,  # invalid version number (8 bit unsigned it expected)
  'AUTOREL_ERR_ADD_HANDOVER'  :  16,  # adding handover to MKS sandbox failed
  'AUTOREL_ERR_NON_BUILD'     :  17,  # shared sub-projects found that are not of type build
  'AUTOREL_ERR_UPDT_VER_DELIV':  18,  # Updating delivered version file revision failed.
  'AUTOREL_ERR_FREEZE'        :  19,  # Freezing complete sandbox or single member failed. See detailed error message.
  'AUTOREL_ERR_THAW'          :  20,  # Thawing complete sandbox or single member failed. See detailed error message.
  'AUTOREL_ERR_MANUAL_TEST'   :  21,  # Manual tests were not successful.
  'AUTOREL_ERR_RO_NOT_VALLID' :  22,  # RO or Issue state is not valid.
  'AUTOREL_ERR_USERTERM_CP'   : 100,  # DEPRECATED(not used): user terminated the script at change package selection
  'AUTOREL_ERR_USERTERM_CI'   : 101,  # user terminated the script before committing the release
}

# SWITCHES TO SKIP STEPS AT DEVELOPMENT TIME
DO_FREEZE_THAW    = True
DO_CONS_CHECK     = True
DO_COMPILE        = True
DO_CODE_HANDOVER  = True
DO_USER_CONF      = True
DO_CHECKPOINT     = True


#------------------------
#  FUNCTIONS
#------------------------

#-------------------------------------------------------------------------------
# Controls the auto release sequence.
#
# PARAM   target  the code handover file
#
# RETURN  n/a
#-------------------------------------------------------------------------------
def autorelease(target):
  """
  Function           :  autorelease
  Description        :  
  target             :  
  Returns            :  
  """
  error_code = RETVAL_AUTOREL['AUTOREL_OK']
  lock_paths = None
  ver_file_delivered = None
  build_targets = []
  lock_members  = []
  non_shared_list = []
  
  # instances for handover installation
  handover_inst_dir  = Dir(engineering_dir + "../01_Supporting_Processes/01_Project_Management/05_Release").abspath
  handover_inst_file = File(handover_inst_dir + "/" + os.path.basename(target)).abspath
  
  try:
    mks_url, dev_path, mks_path = MKS_GetProjectInfo(sandbox_root)

    # initial environment
    my_env = {'TYPE':'AUTOREL'}
    my_env['PROJECT_NAME'] = MKS_GetProjectName(sandbox_root)
    my_env['COMPONENT_OWNER']	 = component_owner
    my_env['CP_LABEL_LIST'] = []
    my_env['CP_LABEL_PATH'] = []
    my_env['COMPLIANCE_REPORT'] = compl_report_link
    my_env['COMPONENT_ROOT'] = mks_url
    my_env['DEVELOP_PATH'] = dev_path
    
    for add_cp in additional_checkpoints:
      my_env['CP_LABEL_LIST'] += [add_cp['LABEL']]
      my_env['CP_LABEL_PATH'] += [add_cp['LINK']]
      
    # delivery type
    my_env['KIND_OF_DELIVERY'] = GetDeliveryType(kind_of_delivery)

    if DO_FREEZE_THAW:
      PrintTitle("FREEZING SANDBOX MEMBERS")
      if not MKS_FreezeOrThawSandboxRecurse(sandbox_root, True):
        print "Failed."
        raise AutoReleaseAbortException("Freezing entire sandbox failed.", RETVAL_AUTOREL['AUTOREL_ERR_FREEZE'])
      print "Succeeded."

    # parse the project configuration from root folder
    try:
      PrintTitle("READING SANDBOX CONFIGURATION")
      my_env['COMPONENT_CONFIG'] = XML_ParseProjectConfig(sandbox_root, config_list_file)
      print "Succeeded."
    except Exception, exc:
      raise AutoReleaseAbortException(str(exc), RETVAL_AUTOREL['AUTOREL_ERR_PROJCONF'])

    if DO_CONS_CHECK:
      non_shared_list, ver_file_delivered = ExecConsistencyCheck(my_env, mks_path)

    PrintTitle("CHANGE PACKAGE SELECTION")
  
    chgp_id = None
    while not chgp_id:
      chgp_list = MKS_ListChangePackages(sandbox_root)
      chgp_id = SelectChangePackage(chgp_list)
    
    # collect all RAM/ROM usage information
    try:
      build_sim_path = build_dir + "algo/"  + component_name.lower() + "_sim/"  
      my_env['RESOURCE_USAGE'], build_targets, arch_list = ParseRamRomUsages(build_sim_path, component_release_setups)	  
    except Exception, exc:
      raise AutoReleaseAbortException(str(exc), RETVAL_AUTOREL['AUTOREL_ERR_LIBSIZE'])
    
    # get library names from selected setup
    lib_names = []
    for x in my_env['RESOURCE_USAGE']:
      lib_names += [x['LIB']]
    
    # read version number from file
    version_file = LookForFile(source_code_dir + "algo/", component_name.lower() + "_ver.h")
    if not version_file:
      raise AutoReleaseAbortException("No version file was found.", RETVAL_AUTOREL['AUTOREL_ERR_VERFILE'])
    cur_version = ReadVersionNumer(version_file, component_name.upper())
    if not cur_version:
      raise AutoReleaseAbortException("Invalid version file.", RETVAL_AUTOREL['AUTOREL_ERR_INVVERFILE'])
    
    # check range of version number
    for x in cur_version:
      if not (0 <= x <= 255):
        str_cur_ver = ".".join(map(str, cur_version))
        raise AutoReleaseAbortException("Version number out of range (%s)." % str_cur_ver, RETVAL_AUTOREL['AUTOREL_ERR_INV_VERNUM'])
    if (min(cur_version[0:3]) == 255):
      str_cur_ver = ".".join(map(str, cur_version))
      raise AutoReleaseAbortException("Max version number reached (%s)." % str_cur_ver, RETVAL_AUTOREL['AUTOREL_ERR_INV_VERNUM'])
    
    # increment version number and create label
    my_env['CHECKPOINT_LABEL'],custom_str = GenerateVersionLabel(cur_version, component_name)
    
    # lock the member revisions of version file and some paths (the paths are returned by the function)
    # => raises an exception if failed
    lock_members += [version_file]
    if MKS_IsMemberExisting(handover_inst_file):
      lock_members += [handover_inst_file]
    lock_paths, shared_lock_paths, shared_orig_paths = ExecLockMembers(lock_members, chgp_id, lib_names, arch_list, (my_env['KIND_OF_DELIVERY'] == "Source"))
      
    # write the new version to the version file
    PrintTitle("WRITE VERSION-FILE")
    if not WriteVersionNumber(cur_version, version_file, component_name, custom_str):
      raise AutoReleaseRestoreException("Writing version number failed.", RETVAL_AUTOREL['AUTOREL_ERR_WRITEVERFILE'])
    print "OK: " + version_file
      
    if DO_COMPILE:
      PrintTitle("RE-COMPILE (VERSION NUMBER CHANGED)")
      if BuildSconsTargets(build_targets):
        raise AutoReleaseRestoreException("Couldn't re-compile.", RETVAL_AUTOREL['AUTOREL_ERR_REBUILD'])
    
    PrintTitle("MANUAL TESTS")
    print "The script is interrupted for manual execution of tests. If the tests were"
    print "successful, return to this screen and confirm with 'y'. Otherwise the script will"
    print "abort!"
    print
    option = GetConfirmation("Were the tests successfully?", ["y", "n"])
    if (option == "n"):
      raise AutoReleaseRestoreException("Manual tests failed.", RETVAL_AUTOREL['AUTOREL_ERR_LIBSIZE'])

    # get user response
    test_answers = GetTestInfoFromUser()
    if (len(test_answers) == 4):
      my_env['TEST_STATE_SIL']     = test_answers[0]
      my_env['TEST_STATE_EVM']     = test_answers[1]
      my_env['TEST_STATE_ECU_LAB'] = test_answers[2]
      my_env['TEST_STATE_ECU_CAR'] = test_answers[3]

    # list of issues related to releases
    list_pr, list_fr, list_cr, issue_ro_list_not_valid, ro_vaild_state = MKS_GetReleaseIssues(release_id_list)
    my_env['ISSUE_LIST_PR'] = list_pr
    my_env['ISSUE_LIST_FR'] = list_fr
    my_env['ISSUE_LIST_CR'] = list_cr
    my_env['RO_ISSUE_LIST_NOT_VALID'] = issue_ro_list_not_valid
    my_env['RO_LIST_VALID'] = 	ro_vaild_state

    if len(issue_ro_list_not_valid) != 0:
      PrintTitle("Below Realization Orders or Issues are not in Valid state")
      for line in issue_ro_list_not_valid:
        print line["issue_id"], "   ",line["issue_type"], "   ",line["issue_state"]		
      option = GetConfirmation("Would you like to continue", ["y", "n"])
      if option == "n":
        raise UserTerminationException("Realization Orders or Issues are not in Valid state.", RETVAL_AUTOREL['AUTOREL_ERR_RO_NOT_VALLID'])	
    
    if DO_CODE_HANDOVER:
      CreateCodeHandover(my_env, target, handover_inst_dir)
    
    if DO_USER_CONF:
      # THIS STEP IS MEANT FOR DEVELOPMENT TO SKIP THE LONG PROCESS OF CHECKPOINTING
      # AND TO CHECK THE FILES BEFORE CHECK-IN.
      PrintTitle("SUBMIT CHANGES")
      option = GetConfirmation("Would you like to submit the release?", ["y", "n"])
      if (option == "n"):
        raise UserTerminationException("Check-in confirmation", RETVAL_AUTOREL['AUTOREL_ERR_USERTERM_CI'])		
      
    if DO_FREEZE_THAW:
      # thaw only locked members before checking in
      locked_by_me = MKS_GetMemersLockedByMe(sandbox_root)
      for member in locked_by_me:  
        MKS_ThawMembers(member['local_path'], member['name'], debug=True)
    
    # check in all locked files
    if not MKS_CheckIn(chgp_id, lock_paths + shared_lock_paths, lock_members, my_env['CHECKPOINT_LABEL']):
      raise AutoReleaseRestoreException("Check-in failed. See log for further information.", RETVAL_AUTOREL['AUTOREL_ERR_CHECKIN'])
      
    if DO_FREEZE_THAW:
      # freeze members checked-in again
      for member in locked_by_me:
        MKS_FreezeMembers(member['local_path'], member['name'], debug=True)
    
    # this release the lock of unchanged files (that are still locked)
    PrintTitle("REMOVE LOCKS FROM UNCHANGED")
    MKS_UnlockPathsRecurse(lock_paths + shared_lock_paths)
    
    # update member revisions of shared paths
    for path in shared_orig_paths:
      if DO_FREEZE_THAW:
        # thaw members
        MKS_FreezeOrThawSandboxRecurse(path, False, debug=True)

      # update shared deliverables
      MKS_UpdateMemberRevRecurse(path, chgp_id, my_env['CHECKPOINT_LABEL'])
      MKS_ResyncPathRecurse(path)

      if DO_FREEZE_THAW:
        # freeze again
        MKS_FreezeOrThawSandboxRecurse(path, True, debug=True)
    
    # also update member revision of version file
    if ver_file_delivered:
      # get the new revision from 01_Source_Code
      last_sep = ver_file_delivered['src_name'].rfind("\\") + 1
      info = MKS_GetMemberInfo(ver_file_delivered['src_name'][:last_sep], ver_file_delivered['src_name'][last_sep:])
      if info:
        if DO_FREEZE_THAW:
          # thaw version file to update member revision
          last_sep = ver_file_delivered['name'].rfind("\\") + 1
          MKS_ThawMembers(ver_file_delivered['name'][:last_sep], ver_file_delivered['name'][last_sep:], debug=True)

        # update the revision in 05_Deliverables\include
        if MKS_UpdateMemberRev(ver_file_delivered['name'], chgp_id, info['rev']):
          MKS_ResyncMembers([ver_file_delivered['name']])
        else:
          # this should not happen
          raise AutoReleaseRestoreException("Updating delivered version file revision failed.", RETVAL_AUTOREL['AUTOREL_ERR_UPDT_VER_DELIV'])
        
        if DO_FREEZE_THAW:
          # freeze version file again => ensure correct version in checkpoint
          MKS_FreezeMembers(ver_file_delivered['name'][:last_sep], ver_file_delivered['name'][last_sep:], debug=True)
      else:
        # this should not happen
        raise AutoReleaseRestoreException("Getting version information of delivered version file failed.", RETVAL_AUTOREL['AUTOREL_ERR_UPDT_VER_DELIV'])
    
    # add handover document at the first time
    if not handover_inst_file in lock_members:
      if not MKS_AddMember(chgp_id, handover_inst_file):
        raise AutoReleaseRestoreException("Adding handover document to sandbox failed.", RETVAL_AUTOREL['AUTOREL_ERR_ADD_HANDOVER'])
      
    if DO_CHECKPOINT:
      PrintTitle("GENERATE CHECKPOINT")
      if not MKS_GenerateCheckpoint(Dir(sandbox_root).abspath, my_env['CHECKPOINT_LABEL']):
        raise AutoReleaseAbortException("Generating checkpoint failed.", RETVAL_AUTOREL['AUTOREL_ERR_CHECKPOINT'])
      for non_shared_dir in non_shared_list:
        if not MKS_LabelMembers(non_shared_dir, my_env['CHECKPOINT_LABEL']):
          raise AutoReleaseAbortException("Label members failed.", RETVAL_AUTOREL['AUTOREL_ERR_CHECKPOINT'])
    
  # normal termination due to an error => no further action required
  except AutoReleaseAbortException, exc:
    print
    print "The auto release script was terminated due to an error."
    print "Error description: " + exc.args[0]
    print
    error_code = exc.args[1]

  # normal termination due to an error => clean-up actions required!!
  except AutoReleaseRestoreException, exc:
    print
    print "The auto release script was terminated due to an error."
    print "This error requires restore actions."
    print "Error description: " + exc.args[0]
    
    # release locked files
    PrintTitle("RELEASE LOCKS (ERROR CLEAN-UP)")
    if lock_paths:
      MKS_UnlockPathsRecurse(lock_paths)
    MKS_UnlockMembers(lock_members)
    MKS_ResyncMembers(lock_members)
    
    error_code = exc.args[1]
  
  # user termination
  except UserTerminationException, exc:
    print
    print "The user terminated the script at '%s'." % (exc.args[0])
    print
    PrintTitle("RELEASE LOCKS (ERROR CLEAN-UP)")
    if lock_paths:
      MKS_UnlockPathsRecurse(lock_paths)
    MKS_UnlockMembers(lock_members)
    MKS_ResyncMembers(lock_members)	
    error_code = exc.args[1]
    
  finally:
    if DO_FREEZE_THAW:
      PrintTitle("THAWING SANDBOX MEMBERS")
      if not MKS_FreezeOrThawSandboxRecurse(sandbox_root, False):
        print "Failed."
        raise AutoReleaseAbortException("Thawing entire sandbox failed.", RETVAL_AUTOREL['AUTOREL_ERR_THAW'])
      print "Succeeded."
  
  return error_code

#-------------------------------------------------------------------------------
# Controls the consistency check. It creates a list of directories and prints 
# detailed error information if there were found some files. This check covers:
# 
# - Members that are out of sync, locked by current user, modified
# - Shared projects version that are not configured as defined in XML files
#
# The auto release environment is passed in the first parameter. This is needed
# to compare the current project configuration with the definition in the XML
# files.
#
# If there was a version file found in the "\05_Deliverables\include" folder
# it is returned as a dictionary with the following keys:
#
#   'name':     full path and filename in the sandbox
#   'src_name': full path and filename in the 01_Source_Code folder
#   'archive':  MKS database path
#   'rev':      the current member revision
#
# PARAM   env       the environment dictionary that is used for auto release
#         mks_path  the root database path
#
# RETURN  - list of lokal sandbox paths that are not shared
#         - version file information (None if not found)
#
# EXCEPT  AutoReleaseAbortException - if inconsistent files were found
#-------------------------------------------------------------------------------
def ExecConsistencyCheck(env, mks_path):
  """
  Function              :  ExecConsistencyCheck
  Description           :  
  env                   :  
  mks_path              :  
  Returns               :  
  """
  PrintTitle("CONSISTENCY CHECK")
  print "Checking members..............",
  
  # directories of interest
  dir_list = [source_code_dir]
  for root,dirs,files in os.walk(Dir(workspace_dir + "algo/").abspath):
    for subdir in dirs:
      if (subdir.startswith(component_name.lower())):
        dir_list += [Dir(root + "/" + subdir).abspath]
    break
  dir_list += [deliverables_dir + "cfg"]
  dir_list += [deliverables_dir + "include"]

  # look for inconsistent files
  file_list,change_types = MKS_GetChangedFiles(sandbox_root, [Dir(sandbox_root).abspath], recurse=False)
  temp_file_list,temp_change_types = MKS_GetChangedFiles(sandbox_root, dir_list)
  
  # merge lists => this is expected to be empty
  file_list += temp_file_list
  change_types += temp_change_types
  
  if len(file_list):
    # print detailed error information
    print "\bfailed"
    print
    for ix in xrange(0, len(file_list)):
      print "> %s (%s)" % (file_list[ix], change_types[ix])
    print
    
    # force script to abort
    raise AutoReleaseAbortException("%i inconsistent files found." % (len(file_list)), RETVAL_AUTOREL['AUTOREL_ERR_CONSCHECK'])
  else:
    print "\bok"

  print "Looking for shared projects...",
  list, invalid_list, non_shared_list = MKS_GetSharedProjListRecurse(sandbox_root)
  
  # shared projects that are not of type "build"
  # => filter out those who are internal shares
  idx = 0
  while idx < len(invalid_list):
    if IsInternalShare(mks_path, invalid_list[idx][1]):
      del invalid_list[idx]
    else:
      idx += 1
  
  # check whether non-build shared projects existing
  if len(invalid_list):
    print "\bfailed"
    print
    print 'Found shared projects that are not of type "build":'
    for x in invalid_list:
      print "> %s" % x[0]
      print "  Shared from: %s" % x[1]
    print
    # force script to abort
    raise AutoReleaseAbortException("%i non-build shared-projects found." % (len(invalid_list)), RETVAL_AUTOREL['AUTOREL_ERR_NON_BUILD'])
  else:
    print "\bok"
  
  cur_proj_conf = {}

  print "Checking shared projects......",
  for x in list:
    pj_label = MKS_GetSharedProjectLabel(x["PROJECT"], x["REVISION"])
    pj_name  = MKS_GetSharedProjectName(x["PROJECT"])
    cur_proj_conf[pj_name] = {'REVISION':x['REVISION'], 'LABEL':pj_label}
  
  proj_list = CheckProjectConfig(cur_proj_conf, env['COMPONENT_CONFIG'])
  
  # filter out configured projects that don't occur in the sandbox
  env['COMPONENT_CONFIG'] = filter(lambda a: a[2], env['COMPONENT_CONFIG'])
  
  if len(proj_list):
    print "\bfailed"
    print
    for comp in proj_list:
      print 'Compontent "%s":' % comp['COMP_NAME']
      print '     Found: Label="%s", Rev.=%s' % (comp['FOUND_LABEL'], comp['FOUND_REV'])
      print '     Exp  : "%s"' % (comp['EXPECTED'])
    print
    
    # force script to abort
    raise AutoReleaseAbortException("%i inconsistent shared projects found." % (len(proj_list)), RETVAL_AUTOREL['AUTOREL_ERR_CONSCHECK'])
  else:
    print "\bok"
  
  print "Checking includes.............",
  
  # get include-deliverables
  inc_deliveries = MKS_GetSharedMembersRecurse(deliverables_dir + "include")
  
  version_delivered = None
  
  # remove those members not shared from 01_Source_Code
  _,_,src_path = MKS_GetProjectInfo(source_code_dir)
  for idx in range(len(inc_deliveries) - 1, -1, -1):
    if not IsInternalShare(src_path, inc_deliveries[idx]['archive']):
      del inc_deliveries[idx]
    else:
      # create expected location in 01_Source_Code
      src_path = src_path.replace("project.pj", "")
      src_member = inc_deliveries[idx]['archive'][len(src_path):]
      last_sep = src_member.rfind("/") + 1
      src_member_path = source_code_dir + src_member[:last_sep]
      src_member_name = src_member[last_sep:]

      # check if file is existing
      # => if not, look for file inside 01_Source_Code and set the real path
      # => this happens if the member archive has moved inside 01_Source_Code
      if not os.path.isfile(File(src_member_path + "/" + src_member_name).abspath):
        tempfile = LookForFile(source_code_dir, src_member_name)
        if tempfile:
          src_member_path = str(File(tempfile).dir)
        else:
          src_member_name = None

      # get the member revision set in 01_Source_Code
      info = None
      if src_member_name:
        info = MKS_GetMemberInfo(src_member_path, src_member_name)
      
      # compare revisions
      if info:
        if (inc_deliveries[idx]['rev'] == info['rev']) and (inc_deliveries[idx]['archive'] == info['archive']):
          # Store a copy of version file for later usage.
          # => since this file is shared the member revision has to 
          #    be updated finally!
          if (src_member_name == (component_name.lower() + "_ver.h")):
            version_delivered = inc_deliveries[idx].copy()
            version_delivered['src_name'] = info['name']
          
          # remove from list if identical
          del inc_deliveries[idx]
        else:
          #difference found:
          inc_deliveries[idx]['src_rev'] = info['rev']
          inc_deliveries[idx]['src_name'] = info['name']
      else:
        # member was not found (this should not happen)
        del inc_deliveries[idx]
  
  if len(inc_deliveries):
    # print detailed error information
    print "\bfailed"
    path_idx = len(Dir(engineering_dir).abspath) + 1
    for x in inc_deliveries:
      print
      print "> File:        " + x['name'][path_idx:]
      print "  Shared from: " + x['src_name'][path_idx:]
      print "  Rev. in 05_Deliverables: " + (x['rev'])
      print "  Rev. in 01_Source_Code:  " + (x['src_rev'])
    
    # force script to abort
    raise AutoReleaseAbortException("%i inconsistent include delivery files found." % (len(inc_deliveries)), RETVAL_AUTOREL['AUTOREL_ERR_CONSCHECK'])
  else:
    print "\bok"
  
  return non_shared_list, version_delivered

#-------------------------------------------------------------------------------
# Checks whether <test_path> is a sub-path of <root_path>, which means this is
# an internal share.
# 
# PARAM   root_path   sandbox root MKS path
#         test_path   the MKS path to check
#
# RETURN  True if <test_path> is a sub-path of <root_path>, False otherwise
#-------------------------------------------------------------------------------
def IsInternalShare(root_path, test_path):
  """
  Function               :  IsInternalShare
  Description            :  
  root_path              :  
  test_path              :  
  Returns                :  
  """
  raw_root_path = root_path[0:root_path.rfind('/')]
  test_strip = test_path[0:len(raw_root_path)]

  return (raw_root_path == test_strip)

#-------------------------------------------------------------------------------
# Controls the lock process. It creates a list of directories to be locked and
# executes the lock on these dirs as well as on <file_list>.
#
# PARAM   file_list     list of members to lock
#         chgp_id       the change package ID as string 
#         lib_names     names of libraries to be released
#         arch_list     architectures to lock
#         src_delivery  True if delivery type is "Source", False otherwise
#
# RETURN  - list if paths that were locked
#         - list if paths shared from 04_Engineering/04_Build that were locked
#         - list if paths that share members from 04_Engineering/04_Build
#
# EXCEPT  AutoReleaseAbortException - if any locking failed
#-------------------------------------------------------------------------------
def ExecLockMembers(file_list, chgp_id, lib_names, arch_list, src_delivery):
  """
  Function                  :  ExecLockMembers
  Description               :  
  file_list                 :  
  chgp_id                   :  
  lib_names                 :  
  arch_list                 :  
  src_delivery              :  
  Returns                   :  
  """
  lock_paths = []
  shared_orig_paths = []
  shared_lock_paths = []
  
  if not src_delivery:
    lock_paths += [deliverables_dir + "dll"]
    lock_paths += LookForComponentDirs(Dir(deliverables_dir + "lib").abspath, component_name.lower(), lib_names)
  
  # eliminate VH28 and CA8-Only extensions from arch list
  for x in range(len(arch_list)):
    idx = arch_list[x].find("_vh28")
    if (idx <> -1):
      arch_list[x] = arch_list[x][:idx]
    else:
      idx = arch_list[x].find("_only")
      if (idx <> -1):
        arch_list[x] = arch_list[x][:idx]

  dummy = {}
  for e in arch_list:
    dummy[e] = 1
  arch_list = sorted(dummy.keys())
  print arch_list
  
  if not src_delivery:
    # add only directories in SDL that are released
    subdirs = MKS_GetSubProjList(deliverables_dir + "sdl")
    for sub in subdirs:
      # support new and old structure of sdl delivery
      if (sub in arch_list) or (sub == "algo"):
        lock_paths += [Dir(deliverables_dir + "sdl/" + sub).abspath]	
  
    # look for members shared from /04_Engineering/04_Build
    path_temp = {}
    for path in reversed(lock_paths):
      # look for shared members
      shared_members = MKS_GetSharedMembersRecurse(path)  
      shared_from_build = False
      for member in shared_members:
        # check if shared members are from 04_Build folder
        start_idx = member['archive'].find('04_Build')
        if (start_idx != -1):
          # if shared from release folder -> use parent directory
          # => this is because in 04_Build contains both release and debug
          last_idx = member['archive'].rfind('release/')
          if (last_idx == -1):
            last_idx = member['archive'].rfind('/')
          test_dir = Dir(build_dir + member['archive'][start_idx + len('04_Build'):last_idx]).abspath
          # add only existing directories (not dropped)
          if os.path.isdir(test_dir):
            path_temp[test_dir] = 1
            shared_from_build = True
      
      # remove the 05_Deliverables path from list if shares from 04_Build were found
      # => we do not accept both styles of delivering members
      if shared_from_build:
        shared_orig_paths += [path]
        lock_paths.remove(path)
    
    shared_lock_paths = sorted(path_temp.keys())
    
  PrintTitle("LOCK MEMBERS")
  
  if not MKS_LockMembers(file_list, chgp_id):
    raise AutoReleaseAbortException("Locking version file failed.", RETVAL_AUTOREL['AUTOREL_ERR_LOCKMEM'])
    
  if not MKS_LockPathsRecurse(lock_paths, chgp_id):
    raise AutoReleaseRestoreException("Locking release paths failed.", RETVAL_AUTOREL['AUTOREL_ERR_LOCKDIRS'])
  
  if not MKS_LockPathsRecurse(shared_lock_paths, chgp_id):
    raise AutoReleaseRestoreException("Locking release paths failed.", RETVAL_AUTOREL['AUTOREL_ERR_LOCKDIRS'])
  
  return lock_paths, shared_lock_paths, shared_orig_paths

#-------------------------------------------------------------------------------
# Controls the code handover genaration process.
#
# PARAM   env                 the environment dictionary that is used for auto 
#                             release
#         target              the code handover file
#         handover_inst_dir   place where code handover is installed
#
# RETURN  -/-
#
# EXCEPT  AutoReleaseRestoreException - if code handover couldn't created or 
#                                       installed to target location
#-------------------------------------------------------------------------------
def CreateCodeHandover(env, target, handover_inst_dir):
  """
  Function                       :  CreateCodeHandover
  Description                    :  
  env                            :  
  target                         :  
  handover_inst_dir              :  
  Returns                        :  
  """
  PrintTitle("EDIT HANDOVER DOCUMENT")
  print "Please edit the code handover document. Since the document will not be changed"
  print "later, please make sure that all required parts - marked as '<...>' - are filled."
  print "Finally save the document and return to this console window."
  print
  print "- PRESS ANY KEY TO OPEN THE DOCUMENT -"
  msvcrt.getch()

  handover_inst_file = File(handover_inst_dir + "/" + os.path.basename(target)).abspath
  if not CreateCodeHandoverDoc(env, target, handover_inst_file):
    raise AutoReleaseRestoreException("Couldn't re-compile.", RETVAL_AUTOREL['AUTOREL_ERR_HANDOVER'])
  
  validity_fill = False
  validity_tabs = False
  while not (validity_fill and validity_tabs):
    print
    print "Have you finished editing the document? [press any key]"
    msvcrt.getch()
    validity_fill, validity_tabs = ValidateCodeHandover(target)
    
    if not validity_fill:
      print
      print "There are still occurrences of '<...>' in the document. Since the filling of"
      print "these parts is required, the document is reopened."
    if not validity_tabs:
      print
      print "The document contains TAB characters, which may lead to faulty representation in"
      print "other editors. The TAB characters are replaced by spaces. To check the formatting"
      print "the document is reopened."
    
    if validity_fill and validity_tabs:
      print
      print "Document validation successful."
    else:
      print
      print "- PRESS ANY KEY TO OPEN THE DOCUMENT -"
      msvcrt.getch()
      # open with default editor
      os.system("start " + target)
  
  try:
    shutil.copy(target, handover_inst_dir)
  except Exception, exc:
    raise AutoReleaseRestoreException(str(exc), RETVAL_AUTOREL['AUTOREL_ERR_INSTALL'])
