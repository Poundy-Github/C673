"""
Filename                  : scons_common_scripts\fingerprint\SConscript_fingerprint.py
Description               : SConscript to build fingerprint. 
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: fingerprint\SConscript_fingerprint.py
#
# DESCRIPTION: SConscript to build fingerprint. 
#
# INITIAL AUTHOR: Fischer-EXT, Andre (uidg5297)
#
# CREATION DATE: 2014/06/24
#
# LAST CHANGE:      $Date: 2021/12/13 19:06:07CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript_fingerprint.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:06:07CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/fingerprint/project.pj
# CHANGES:                   Revision 1.15 2017/05/30 13:54:15CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.14 2017/04/27 16:06:40CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.13 2016/07/01 06:13:28CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.12 2015/06/26 08:34:50CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 8:34:50 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build fingerprint

#-------------------------
# import
#-------------------------
Import("algo_name", "component_name", "help_dict", "verbose", "bld", "src", "core")
import os

execfile(File("#../GSCons_project_config.scfg").abspath)
#-------------------------
# read configuration file
#-------------------------
execfile(File(source_code_path_from_sconstruct + component_name + "/algo_config.scfg").abspath)

# get common scons config containing tool paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)

#-------------------------
# read helper file
#-------------------------
# read sconstruct_helpers.py
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/help_menu.py").abspath)

#-------------------------
# setup environment
#-------------------------
fp_env = Environment(# list of scons ADAS extensions used
                      tools = ["fingerprint", "msvc-addon"],
                      # path to scons ADAS extensions
                      toolpath = [scons_adas_extensions_path])

if not verbose:
    fp_env['FINGERPRINTCOMSTR'] = "generating fingerprint..."

#-----------------------------
# generate algo fingerprint
#-----------------------------
fingerprint_file = []
lookup_file = []
fingerprint_src = []

if core == "c674x":
    # import version history
    execfile(File("#/" + algo_name + "_algo_ver_history.scfg").abspath)
    # get absolute include paths
    fingerprint_src += src
    # get all header files in include directories
    h_files = fp_env.FindAllIncludes(bld)
    fingerprint_src += h_files
    # remove version file and the fingerprint file from source list
    fingerprint_src_list = filter(lambda x:
                                      algo_name + "_ver.h" not in x and
                                      algo_name.upper() + "AlgoFingerprint.h" not in x and
                                      algo_name.upper() + "AlgoArpFingerprint.h" not in x and
                                      "02_Development_Tools" not in x and
                                      "01_Source_Code\\common" not in x, fingerprint_src)

    # generate XXXAlgoFingerprint.h
    fingerprint_file += fp_env.Fingerprint(
                        # name of the header file
                        build_dir + "/algo/" + algo_name + "/fingerprint/" + algo_name.upper() + "AlgoFingerprint.h",
                        # source file containing PDO tags
                        fingerprint_src_list + [Value({"ul_FP_" + algo_name.upper() + "Algo" : Versions})],
                        FINGERPRINT_VARS={"ul_FP_PdLaneInfo":[0], "ul_FP_" + algo_name.upper() + "Algo":None})

    #---------------------------------------------
    # Generate a plain text file containing the
    # mapping from a source code filename to an
    # index number. The index number is taken
    # from the index of the filename in the
    # FINGERPRINT_ARRAY_OF_FILENAMES array in the
    # LDAlgoFingerprint.h file. This filename
    # index is used when logging errors within LD.
    #---------------------------------------------
    lookup_filename = algo_name + "FilenameIDLookup.txt"
    lookup_cmd_filename = algo_name + "FilenameIDFreeze.cmd"
    GenerateFilenameIDLookup(lookup_filename, fingerprint_src_list)
    GenerateFilenameIDCMD(lookup_cmd_filename, fingerprint_src_list)

    lookup_file += fp_env.Install(build_dir + "/algo/" + algo_name + "/fingerprint/",
                          [lookup_filename, lookup_cmd_filename])

# #-----------------------------
# # generate algo arp fingerprint
# #-----------------------------

if core == "arp32":
    fingerprint_arp_src = []
    # import version history
    execfile(File("#/" + algo_name + "_arp_ver_history.scfg").abspath)
    # get absolute include paths
    fingerprint_src += src
    # get all header files in include directories
    h_files = fp_env.FindAllIncludes(bld)
    fingerprint_src += h_files
    # remove version file and fingerprint file from source list
    fingerprint_src_list = filter(lambda x:
                                      algo_name + "_ver.h" not in x and
                                      algo_name.upper() + "AlgoFingerprint.h" not in x and
                                      algo_name.upper() + "AlgoArpFingerprint.h" not in x and
                                      "02_Development_Tools" not in x and
                                      "01_Source_Code/common" not in x, fingerprint_src)

    fingerprint_file += fp_env.Fingerprint(
                        # name of the header file
                        build_dir + "/algo/" + algo_name + "/fingerprint/" + algo_name.upper() + "AlgoArpFingerprint.h",
                        # source file containing PDO tags
                        fingerprint_src_list + [Value({"ul_FP_" + algo_name.upper() + "AlgoArp" : Versions})],
                        FINGERPRINT_VARS={"ul_FP_PdLaneInfo":[0], "ul_FP_" + algo_name.upper() + "AlgoArp":None})

    lookup_arp_filename = algo_name + "ArpFilenameIDLookup.txt"
    GenerateFilenameIDLookup(lookup_arp_filename, fingerprint_src_list)

    lookup_file += fp_env.Install(build_dir + "/algo/" + algo_name + "/fingerprint/",
                      lookup_arp_filename)

Requires(lookup_file, fingerprint_file)
generate_alias(algo_name + "_fingerprint", [fingerprint_file, lookup_file], component_name + ':fingerprint', ['fingerprint header files'])
