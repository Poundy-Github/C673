"""
Filename            :  scons_adas_extensions\sconstruct_helpers.py
Description         :  Script that contains helpful functions used by Scons build environment.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: sconstruct_helpers.py
#
# DESCRIPTION: Script that contains helpful functions used by Scons build environment
#
# INITIAL AUTHOR: Spruck, Jochen (spruckj)
#
# CREATION DATE: - 2013/01/29
#
# LAST CHANGE:      $Date: 2021/12/13 19:04:00CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: sconstruct_helpers.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:00CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.25 2017/09/21 13:09:43CEST Singh, Vishal (uidj9083) 
# CHANGES:                   update for getting full TASK ID
# CHANGES:                   Revision 1.24 2016/05/27 12:48:50CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.23 2016/03/04 10:12:18CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Error and Warnings summary report to be provide in build log for the scons targets
# CHANGES:                   Revision 1.22 2015/09/24 14:45:26CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add sandbox name to link folder under C:\ for when ti-tools are unzipped
# CHANGES:                   - Added comments -  uidg5297 [Sep 24, 2015 2:45:26 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.21 2015/09/23 16:03:42CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add functions extract_archives() and get_newer_file()
# CHANGES:                   --- Added comments ---  uidg5297 [Sep 23, 2015 4:03:43 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.20 2015/07/22 10:56:38CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add function resolve_incompatible_ccflags_vs
# CHANGES:                   rename resolve_contradicting_ccflags to resolve_incompatible_ccflags
# CHANGES:                   add call of resolve_incompatible_ccflags_vs to resolve_incompatible_ccflags
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 22, 2015 10:56:38 AM CEST]
# CHANGES:                   Change Package : 359738:1 http://mks-psad:7002/im/viewissue?selection=359738
# CHANGES:                   Revision 1.19 2015/07/06 10:02:51CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add function resolve_contradicting_ccflags
# CHANGES:                   --- Added comments ---  uidg5297 [Jul 6, 2015 10:02:51 AM CEST]
# CHANGES:                   Change Package : 353994:1 http://mks-psad:7002/im/viewissue?selection=353994
# CHANGES:                   Revision 1.18 2015/06/26 05:17:31CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:31 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************


# Helper functions
# ----------------

import stat
import subprocess
import datetime
from SCons.Script import *
from os import walk
import re
import os


def unique(l):
    """
    Function      :  unique
    Description   :  unify a list.
    l             :  list provided.
    Returns       :  
    """
    r = []
    m = {}
    for e in l:
        m[e] = None
    for e in l:
        if m.has_key(e):
            r.append(e)
            del m[e]
    return r

def find_incs(env, targets):
    """
    Function             :  find_incs
    Description          :  Function for finding .h files with the same base name as the sources.
    env                  :  The build environment.
    targets              :  
    Returns              :  
    """
    incs = env.FindAllIncludes(targets)
    root = Dir('#/..').abspath
    res = []
    for i in incs:
        if i.find(root) == 0:
            res.append(i[len(root):])
    return res

def find_all_incs(env, targets):
    """
    Function             :  find_all_incs
    Description          :  Function for finding all .h files.
    env                  :  The build environment.
    targets              :  
    Returns              :  Absolute paths
    """
    incs = env.FindAllIncludes(targets)
    res = []
    for i in incs:
        res.append(i)
    return res

def find_all_h_files(dir_list):
    """
    Function             :  find_all_h_files
    Description          :  Function for finding all -h files below a given directory
    dir_list             :  
    Returns              :  Relative paths
    """
    h_files = []
    for dir in dir_list:
        dir_path = Dir(dir).abspath
        # check if directory exists
        if not os.path.isdir(dir_path):
           continue
        # collect all .h files
        for file in os.listdir(dir_path):
            if file.endswith('.h'):
                h_files.append(dir_path + '/' + file)
    return h_files

def add_dirpath(file_list, dirpath):
    """
    Function              :  add_dirpath
    Description           :  Sometimes source file names appear without the directory path they are situated in.
	                         In order to use those sources also from other locations, the dirpath can be added to the string by the following function.
    file_list             :  
    dirpath               :  
    Returns               :  
    """
    file_list_mod = []
    for file in file_list:
        # print Dir(dirpath).abspath + "/" + file
        file_list_mod.append(Dir(dirpath).abspath + "/" + file)
    return file_list_mod


def filter_src(x):
    """
    Function      :  filter_src
    Description   :  Filter sources
    x             :  Source
    Returns       :  
    """
    if type(x) == type("") or len(x.sources) == 0:
        return str(x)
    else:
        assert len(x.sources) == 1
        return str(x.sources[0])

def make_files_writable(files):
    """
    Function          :  make_files_writable
    Description       :  Make sure that the given files are writable.
    files             :  Given file.
    Returns           :  
    """
    for n in files:
        try:
            os.chmod(n.abspath, stat.S_IRWXU)
        except OSError:
            pass

# convert filenames in files to their absolute paths if not already given
def abspath_filenames(files):
    """
    Function          :  abspath_filenames
    Description       :  Convert filenames in files to their absolute paths if not already given.
    files             :  Given file.
    Returns           :  Absolute path.
    """
    absfiles = []
    for f in files:
        if not os.path.isabs(f):
            absfiles.append(os.path.normpath(os.path.abspath(Dir('.').srcnode().abspath + '/' + f)))
        else:
            absfiles.append(f)
    return absfiles

def create_lint_paths(paths):
    """
    Function          :  create_lint_paths
    Description       :  convert paths in paths to their absolute paths if not starting with '#' or if not already given
    paths             :  Given path.
    Returns           :  Absolute path.
    """
    abspaths = []
    for p in paths:
        if not '#' in p:
            if not os.path.isabs(p):
                abspaths.append(os.path.normpath(os.path.abspath(p)))
            else:
                absfiles.append(p)
        else:
            abspaths.append(p)
    return abspaths

def get_number_of_processors():
    """
    Function        :  get_number_of_processors
    Description     :  Guess number of processors of current machine for -j option.
    Returns         :  
    """
    try:
        num_proc      = os.environ["NUMBER_OF_PROCESSORS"]
    except:
        num_proc      = '1'
    return num_proc

def get_list_of_dirs(path):
  """
  Function         :  get_list_of_dirs
  Description      :  Return list of directories with and below path.
  path             :  Given path.
  Returns          :  Directories.
  """
  dirs = []
  if os.path.lexists(path):
    wdirs = os.walk(path)
    for d in wdirs:
      dirs.append(os.path.abspath(d[0]))
  return dirs

def get_c6000_codegen_version(codegendir):
  """
  Function               :  get_c6000_codegen_version
  Description            :  Parse version output of ticcs compiler to get codegen version.
  codegendir             :  
  Returns                :  
  """
  version = os.path.basename(codegendir)
  call = codegendir + '/bin/cl6x.exe'
  if os.path.isdir(codegendir):
    if os.path.lexists(call):

      # call compiler with version argument
      comp_cmd = subprocess.Popen([call, '', '-version'], shell = False, stdout = subprocess.PIPE, stderr = subprocess.STDOUT)
      call_output = comp_cmd.communicate()[0]
      #print call_output

      # parse output for version information of compiler
      for line in call_output.split('\r\n'):
        if line.find('Compiler') != -1:
          fields = line.split()
          if len(fields) == 4:
            version = fields[0].lower() + '_' + fields[3].replace('.', '_')
            #print version
    else:
      print 'get_c6000_codegen_version(): Could not find ' + call
  else:
    print 'get_c6000_codegen_version(): Not exisiting directory: ' + codegendir
    print 'setting c6000 version number to 99.99.99'
    version = version + "_v99_99_99"
  return version


def get_arm_codegen_version(codegendir):
  """
  Function               :  get_arm_codegen_version
  Description            :  Parse version output of ticcs compiler to get codegen version
  codegendir             :  
  Returns                :  
  """
  version = os.path.basename(codegendir)
  call = codegendir + '/bin/armcl.exe'
  if os.path.isdir(codegendir):
    if os.path.lexists(call):

      # call compiler with version argument
      comp_cmd = subprocess.Popen([call, '', '-version'], shell = False, stdout = subprocess.PIPE, stderr = subprocess.STDOUT)
      call_output = comp_cmd.communicate()[0]
      #print call_output

      # parse output for version information of compiler
      for line in call_output.split('\r\n'):
        if line.find('Compiler') != -1:
          fields = line.split()
          if len(fields) == 5:
            version = fields[1].lower() + '_' + fields[4].replace('.', '_')
            #print version
    else:
      print 'get_arm_codegen_version(): Could not find ' + call
  else:
    print 'get_arm_codegen_version(): Not exisiting directory: ' + codegendir
    print 'setting arm version number to 99.99.99'
    version = version + "_v99_99_99"
  return version


def get_arm_gcc_codegen_version(codegendir):
  """
  Function               :  get_arm_gcc_codegen_version
  Description            :  Parse version output of GCC compiler to get codegen version.
  codegendir             :  
  Returns                :  
  """
  version = os.path.basename(codegendir)
  call = codegendir + '/bin/arm-none-eabi-gcc.exe'
  if os.path.isdir(codegendir):
    if os.path.lexists(call):

      # call compiler with version argument
      comp_cmd = subprocess.Popen([call, '', '--version'], shell=False, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
      call_output = comp_cmd.communicate()[0]
      #print call_output

      # parse output for version information of compiler
      for line in call_output.split('\r\n'):
        if line.find('(GNU Tools for ARM Embedded Processors)') != -1:
          fields = line.split()
          if len(fields) >= 8:
            version = 'gcc_v' + fields[7]
            #print version
    else:
      print 'get_arm_gcc_codegen_version(): Could not find ' + call
  else:
    print 'get_arm_gcc_codegen_version(): Not exisiting directory: ' + codegendir
    print 'setting gcc version number to 99.99.99'
    version = version + "_v99_99_99"
  return version

def get_arp32_codegen_version(codegendir):
  """
  Function               :  get_arp32_codegen_version
  Description            :  Parse version output of arp32 compiler to get codegen version.
  codegendir             :  
  Returns                :  
  """
  version = os.path.basename(codegendir)
  call = codegendir + '/bin/cl-arp32.exe'
  if os.path.isdir(codegendir):
    if os.path.lexists(call):

      # call compiler with version argument
      comp_cmd = subprocess.Popen([call, '', '-version'], shell = False, stdout = subprocess.PIPE, stderr = subprocess.STDOUT)
      call_output = comp_cmd.communicate()[0]
      #print call_output

      # parse output for version information of compiler
      for line in call_output.split('\r\n'):
        if line.find('Compiler') != -1:
          fields = line.split()
          if len(fields) == 4:
            version = fields[0].lower() + '_' + fields[3].replace('.', '_')
            #print version
    else:
      print 'get_arp32_codegen_version(): Could not find ' + call
  else:
    print 'get_arp32_codegen_version(): Not exisiting directory: ' + codegendir
    print 'setting arp32 version number to 99.99.99'
    version = version + "_v99_99_99"
  return version

def get_mwcc_codegen_version(codegendir):
  """
  Function               :  get_mwcc_codegen_version
  Description            :  Parse version output of codewarrior compiler to get codegen version.
  codegendir             :  
  Returns                :  
  """
  version = os.path.basename(codegendir)
  #print version
  call = codegendir + '/PowerPC_EABI_Tools/Command_Line_Tools/mwcceppc.exe'
  if os.path.isdir(codegendir):
    if os.path.lexists(call):

      # call compiler with version argument
      comp_cmd = subprocess.Popen([call, '', '-version'], shell = False, stdout = subprocess.PIPE, stderr = subprocess.STDOUT)
      call_output = comp_cmd.communicate()[0]
      #print call_output

      # parse output for version information of compiler
      for line in call_output.split('\r\n'):
        if line.find('Version') != -1:
          fields = line.split()

          if len(fields) == 4:
            version = 'mwcc' + '_v' + fields[1].replace('.', '_') + '_' + fields[3]
            print version
    else:
      print 'get_mwcc_codegen_version(): Could not find ' + call
  else:
    print 'get_mwcc_codegen_version(): Not exisiting directory: ' + codegendir
  return version

def build_objects(sources, env, suffix = ''):
  """
  Function             :  build_objects
  Description          :  Build object file for each source file.
  sources              :  
  env                  :  
  suffix               :  
  Returns              :  
  """
  list = []
  # no suffix
  if (suffix == ''):
    for s in sources:
      list += env.Object(s)
  # append suffix for files used in multiple targets
  else:
    for s in sources:
      list += env.Object(s + suffix, s)
  return list

def current_date_time():
  """
  Function        :  current_date_time
  Description     :  Return string with current date and time info.
  Returns         :  String of date and time.
  """
  strdatetime = datetime.datetime.today().strftime("%Y-%m-%d %H:%M:%S")
  return strdatetime

def display_build_status():
  """
  Function        :  display_build_status
  Description     :  Display the build status.
  Returns         :  
  """
  """Display the build status. will be called by atexit."""
  from SCons.Script import GetBuildFailures
  build_failures = GetBuildFailures()
  if build_failures:
    print "\nBuild FAILED!!!!"
  else:
    print "\nBuild succeeded."

def display_total_errors_warnings(file):
    """
    Function         :  display_total_errors_warnings
    Description      :  Display the total no of compiler errors and warnings.
    file             :  Given file.
    Returns          :  
    """
    errors = 0
    warnings = 0
    list_of_errors_warnings = []
    f = open(file, "r")
    searchlines = f.readlines()
    f.close()
    for line in searchlines:
        if 'error:' in line:
            errors += 1
            list_of_errors_warnings.append(line)
    for line in searchlines:
        if ('warning' in line) and ('MS_LINK' not in line):
            warnings += 1
            list_of_errors_warnings.append(line)
    print "%d error(s), %d warning(s)" %(errors,warnings)
		
def get_define_value_from_file(header_file, define):
  """
  Function                :  get_define_value_from_file
  Description             :  Get c-preprocesser define from header file.
  header_file             :  Give header file.
  define                  :  Macros
  Returns                 :  
  """
  # read header file
  file_obj = open(File(header_file).abspath, 'r')
  file_contents = file_obj.readlines()
  file_obj.close()

  # search line containing c-preprocesser define
  for line in file_contents:
    if define in line.split():	
      #c-preprocesser format: #define AAA value
      #after split, value is in index 2
      substrings = line.split()
      if substrings[0] == "#define":
        return substrings[2]
  # return "0" if string is not found
  return "0"

def GenerateFilenameIDLookup(file, src):
    """
    Function         :  GenerateFilenameIDLookup
    Description      :  Generate a plain text file containing the
                        mapping from a source code filename to an
                        index number which is used for the fingerprint
                        mechanism of GenericScons. The index number is
                        taken from the index of the filename in the
                        FINGERPRINT_ARRAY_OF_FILENAMES array in the
                        LDAlgoFingerprint.h file. This filename
                        index is used when logging errors within LD.
    file             :  
    src              :  
    Returns          :  
    """
    f = open(file, "w")

    for filename_index, filename in enumerate(src):
        f.write(str(filename_index) + "\t" +  os.path.basename(filename) + "\n")

    f.close()

def GenerateFilenameIDCMD(file, src):
    """
    Function         :  GenerateFilenameIDCMD
    Description      :  Generate a cmd file to freeze or thaw all files used for the fingerprint mechanism of GenericScons.
    file             :  
    src              :  
    Returns          :  
    """
    f = open(file, "w")

    f.write( '@echo off\n' +
             'set mks_action=thaw\n'
             'set /p local_key="freeze all fingerprint files (else thaw)? [y,THAW] "\n' +
             'if "%local_key%" == "y" set mks_action=freeze\n' +
             'echo do %mks_action%\n' +
             'pause\n' +
             '@echo on\n' )

    for filename_index, filename in enumerate(src):
        f.write( "si %mks_action% --sandbox=" + os.path.normpath( os.path.dirname( filename )) + "\project.pj " + os.path.normpath(filename) + "\n")

    f.close()
    
def update_vs_data(blds, srcs, cppp, alias, cppdefs, nblds, nsrcs, ncppp, nalias, ncppdefs):
    """
    Function              :  update_vs_data
    Description           :  Generate a cmd file to freeze or thaw all files used for the fingerprint mechanism of GenericScons.
    blds                  :  
    srcs                  :  
    cppp                  :  
    alias                 :  
    cppdefs               :  
    nblds                 :  
    nsrcs                 :  
    ncppp                 :  
    nalias                :  
    ncppdefs              :  
    Returns               :  
    """
    blds.extend(nblds)
    srcs.extend(nsrcs)
    cppp.extend(ncppp)
    alias.extend(nalias) 
    cppdefs.extend(ncppdefs)
    srcs = unique(srcs)
    cppp = unique(cppp)
    # remove all VC includes
    cppp = [path for path in cppp if not path.startswith('C:\\LegacyApp\\VisualStudio2005')]
    return [blds, srcs, cppp, alias, cppdefs]

   
def resolve_incompatible_ccflags_vs(ccflags, target):
    """
    Function            :  resolve_incompatible_ccflags_vs
    Description         :  Function for resolving visual studio compiler flags clashes.
    ccflags             :  ccflags to be checked.
    target              :  Related build target (for helpful warning message.
    Returns             :  
    """
    # check for clash between /fp: and /arch:-flags
    # If /fp:-flag is set, all /arch:-options must be ignored (Issue 358945)
    arch_flags = []
    fp_flags = []
    for flag in ccflags:
        if flag.startswith('/fp:'):
            fp_flags.append(flag)
        elif flag.startswith('/arch:'):
            arch_flags.append(flag)
    if fp_flags and arch_flags:
        print "\nWARNING: For PC simulation target %s" % target
        print "         incompatible options %s and %s have been set." % (' '.join(fp_flags), ' '.join(arch_flags))
        print "         Option(s) %s will be ignored for the build." % ' '.join(arch_flags)
        print "         Please check configuration of %s.\n" % target
        for arch_flag in arch_flags:
            ccflags.remove(arch_flag)
    # Make sure that /fp:strict is applied if  
    # multiple /fp:-flags are set
    fp_strict_flag = '/fp:strict'
    if fp_strict_flag in fp_flags:
        ccflags.remove(fp_strict_flag)
        ccflags.append(fp_strict_flag)
    return ccflags
    
 
def resolve_incompatible_ccflags(ccflags, pattern_to_check, ccflags_local='', target_type = '', target = ''):
    """
    Function                      :  resolve_incompatible_ccflags
    Description                   :  Function for resolving compiler flags clashes.
    ccflags                       :  All ccflags being set by common build settings and component-specific build settings.
    pattern_to_check              :  Dictionary
                                     key : pattern to be searched for, e.g. r'\/W\d' for any flags of form /WN, where N is any digit
                                     value = 'keep_highest' | 'keep_local': mode of handling contradicting flags
                                    'keep_highest': the highest flag is set
                                    'keep_local'  : the relevant flag being set by the component overwrites the global one
    ccflags_local                 :  ccflags set locally by component,required only for 'keep_local'-mode.
    target_type                   :  Specify class of build target, currently only needed for pc simulation targets.
    target                        :  Specify target which is checked.
    Returns                       :  
    """
    debug = False
    if debug:
        print "before", ccflags
    for pattern in pattern_to_check:
        # gather all ccflags which match the pattern in question
        ccflags_discovered = []
        for flag in ccflags:
            m = re.match(pattern, flag)
            if m:
                ccflags_discovered.append(m.group(0))
        # choosing the flag to be used
        if pattern_to_check[pattern] == 'keep_highest':
            for item in sorted(ccflags_discovered, reverse=False)[:-1]:
                ccflags.remove(item)
        elif pattern_to_check[pattern] == 'keep_local':
            # check if relvant flag is locally defined
            ccflags_to_add = []
            for item in sorted(ccflags_local.split()):
                m = re.match(pattern, item)
                if m:
                    ccflags_to_add.append(m.group(0))
            if ccflags_to_add != []:
                # remove all flags of that category from ccflags
                for item in sorted(ccflags_discovered):
                    ccflags.remove(item)
                # append detected local flags
                for item in ccflags_to_add:
                    ccflags.append(item)
    # sort out possible clash of /fp: and /arch: flags for visual studio
    # and make sure that /fp:strict is not overridden by local settings
    if target_type == 'SIM':
        ccflags = resolve_incompatible_ccflags_vs(ccflags, target)
        if debug:
            print "after", ccflags
    return ccflags
    
#------------------------------------
# Function for extracting zipped archives
#------------------------------------

def get_newer_file(file1, file2):
    """
    Function           :  get_newer_file
    Description        :  Out of two files with absolute paths,the file with the latest timestamp is returned.
    file1              :  Given file1.
    file2              :  Given file2.
    Returns            :  file with most recent timestamp
    """
    if os.path.isfile(file1):
        file1CTime = os.path.getmtime(file1)
    else:
        return ''
    if os.path.isfile(file2):
        file2CTime = os.path.getmtime(file2)
    else:
        return ''
    if file1CTime < file2CTime:
        return file2
    else:
        return file1

def unzip_archives(zip_files, unzip_dir, junction_dir):
    """
    Function                  :  unzip_archives
    Description               :  Reads in a dictionary of zip files with corresponding files being zipped and extracts them.
    zip_files                 :  Dictionary. key: zip file, value: list files to be extracted.
    unzip_dir                 :  Location of unzip-tools.
    junction_dir              :  Location of junction tool.
    Returns                   :  None
    """
    env = Environment(# list of scons ADAS extensions used
                      tools = ["unzip"],
                      # path to scons ADAS extensions
                      toolpath = [scons_adas_extensions_path],
                      UNZIP_DIR = unzip_dir,
                      JUNCTION_DIR = junction_dir)
    zip_files_unzipped = []
    for zip in zip_files:
        report_file = str(File(zip).dir) + '/unzip_report.txt'
        target_files = [target for target in zip_files[zip]]
        zip_file = File(zip).abspath
        newer_file = get_newer_file(report_file, zip_file)
        if (not os.path.isfile(File(target_files[0]).abspath)) or (not newer_file == report_file):
            # Create link folder
            # get zip file name (e.g. bios, c6000, etc)
            zip_file_wo_path = zip_file.split('\\')[-1]
            zip_file_name = zip_file_wo_path.split('.')[0]
            # define dummy-files for symbolic link generation under %LINK_FOLDER%\\sandbox_name
            sandbox_path = Dir(engineering_dir + '../').abspath
            sandbox_name = sandbox_path.split('\\')[-1]
            symbolic_link = LINK_FOLDER + sandbox_name + '\\' + zip_file_name + '\\'
            symbolic_link_dummy = symbolic_link + zip_file_name + '_link.lnk'
            zip_link_dummy = symbolic_link + zip_file_name + '_zip.lnk'
            # Create symbolic link
            link_gen = env.CLINK(symbolic_link_dummy, zip_file)
            # Extract archives, if successful, creat a report-file, remove link
            if zip_file.endswith('.zip'):
                zip_files_unzipped += env.XZIP([zip_link_dummy, target_files, report_file], [zip_file, link_gen])
            elif zip_file.endswith('.7z'):
                zip_files_unzipped += env.XZ([zip_link_dummy, target_files, report_file], [zip_file, link_gen])          
    env.NoClean(zip_files_unzipped)
    return zip_files_unzipped
    