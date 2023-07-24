"""
Filename                  : scons_common_scripts\modtests\SConscript.py
Description               : Sconscript to create Cantata build environment. 
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: modtests\SConscript.py
#
# DESCRIPTION: Sconscript to create Cantata build environment. 
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/10/07
#
# LAST CHANGE:      $Date: 2021/12/13 19:06:15CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: SConscript.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:06:15CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/modtests/project.pj
# CHANGES:                   Revision 1.21 2017/05/30 13:55:25CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   GSCons update for Mainstream
# CHANGES:                   Revision 1.20 2017/04/27 16:06:39CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Updated for mainstream
# CHANGES:                   Revision 1.19 2016/07/12 06:39:04CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   Error and Exception handled in GSCons.
# CHANGES:                   Revision 1.18 2016/07/01 06:16:30CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.17 2016/05/05 07:47:20CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Generic Scons: To generate stand alone Cantata project
# CHANGES:                   Revision 1.16 2016/04/05 10:42:32CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Same as 1.14 and 1.11
# CHANGES:                   Revision 1.15 2016/04/04 11:38:21CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   same as version 1.13
# CHANGES:                   Revision 1.14 2016/04/04 08:56:03CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Added the content of 1.11
# CHANGES:                   Revision 1.13 2016/03/31 15:22:16CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Generic SCons: To generate stand alone Cantata
# CHANGES:                   Revision 1.12 2016/03/31 06:47:25CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Generic SCons: To generate stand alone Cantata project
# CHANGES:                   Revision 1.11 2016/03/22 05:59:52CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Exception in scons_tools: name 'env' is not defined cause by module tests
# CHANGES:                   Revision 1.10 2015/06/26 08:53:57CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 8:53:57 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# SConscript to build unit tests 

#-------------------------
# import
#-------------------------
import os, operator, SCons, exceptions
Import("skip_ide_generation", "exception_handler_file_list", "exception_handler", "scons_arguments", "component_name", "build_from_ide", "thread_number", "algo_name_list", "profile", "SconscriptTimesTable")

execfile(File("#../GSCons_project_config.scfg").abspath)
if profile:
    execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/profile.py").abspath)
    StartSconscriptEntry('1')
#-------------------------
# read configuration file
#-------------------------
# read file list containing source files and include paths
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_common_config/common_config.scfg").abspath)
# We want to use the compiler settings already set up for the 
# PC sim target. Therefore we source the configuration settings
# for the sim.
# At this point, we are not interested in individual algos, just the component
algo_name = component_name
try:
    execfile(File("#../" + component_name + "_sim/sim_swc_" + component_name + "/simenv_config.scfg").abspath)
except exceptions.NameError, e:
        print "WARNING: custom config stuff not supported."
        print "         File: " + File("#../" + component_name + "_sim/sim_swc_" + component_name + "/simenv_config.scfg").abspath
        print "         " + str(e)
sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)

# read gscons_exception_handler
execfile(File(scons_adas_extensions_path + "gscons_exception_handler.py").abspath)

# ------------------------------------
# Andre.Fischer-Ext (uidg5297) - 2014-09-12:
# ------------------------------------
# For the case unit_test.scfg is not available, 
# a try/except clause is introduced in order to 
# be able to build all non-cantata-related targets,
# see MKS Issue #263831.
# ------------------------------------
try:
    execfile(sconscript_dir + "/unit_test.scfg")
except IOError:
    print "WARNING: Cantata configuration file " + sconscript_dir + "/unit_test.scfg was not found."
    print "         Cantata based unit tests will not build." 
    Return ()

try:
    use_msvc
except NameError,e:
    exception_warning(e,exception_handler,"in unit-test.scfg")
    use_msvc = 1	
#-------------------------
# read helper
#-------------------------
execfile(File(development_tools_path_from_sconstruct + "scons_tools/scons_adas_extensions/sconstruct_helpers.py").abspath)

# ========================
# unit_test
# ========================

#-------------------------
# setup environment
#-------------------------
if use_msvc == 1:
  ut_env = Environment(# list of scons extensions used
                      tools = ["msvc", "msvs-patched", "mslib", "mslink", 
                               "msvc-addon", "doxygen", "fingerprint",
                               "eclipse_cdt", "unittest"], 
                      # path to scons extensions
                      toolpath = [scons_adas_extensions_path], 
                      MSVS_USE_MFC_DIRS = 1, 
                      TARGET_ARCH = "X86",
                      # path to doxygen tool
                      DOXYGEN_TOOLS = doxygen_dir,
                      # manifest files need to be included in the dlls/apps
                      WINDOWS_EMBED_MANIFEST = True, 
                      # use Visual Studio 2005
                      MSVC_VERSION = "8.0",
                      # specify processor for scons build
                      BUILD_TARGET = "SIM")

else:
  ut_env = Environment(# list of scons extensions used
                      tools = ["mingw", "doxygen", "fingerprint",
                               "eclipse_cdt", "unittest"], 
                      # path to scons extensions
                      toolpath = [scons_adas_extensions_path], 
                      MSVS_USE_MFC_DIRS = 0, 
                      TARGET_ARCH = "X86",
                      # path to doxygen tool
                      DOXYGEN_TOOLS = doxygen_dir,
                      # specify processor for scons build
                      _BUILD_TARGET = "SIM")


Export("skip_ide_generation", "scons_arguments", "component_name", "build_from_ide", "thread_number", "algo_name_list", "algo_name")

# First, call the unit test SConscript once for the whole
# module, to build the IDE's
unit_test_build_dir = build_dir + "/algo/" + component_name + "_unittests/debug/" + component_name
ut_env.VariantDir(unit_test_build_dir, "../../../../../../", duplicate = 0)

sconscript_dir = unit_test_build_dir + \
                     "/05_Testing/05_Test_Environment/algo/" + \
                     unit_test_dir + "/" + cantata_unit_test_dir + \
                     "/SConscript_unittests.py"
result = ut_env.SConscript(sconscript_dir,
                    exports = {
                        "env" : ut_env, 
                        "component_name" : component_name,
                        "algo_name" : algo_name,
                        "algo_name_list" : algo_name_list,
			"variant" : "debug",
			"variant_list" : variant_list,
                        "generate_ide" : True
                        })

# Second, call the unit test SConscript for each algo within the
# module, to build and execute the unit tests.
for algo_index, algo_name in enumerate(algo_name_list):

    for variant in variant_list:

        algo_ut_env = ut_env.Clone()

        if use_msvc == 1:
          algo_ut_ccflags = variant[1]
          algo_ut_cppdefines = variant[2]
          algo_ut_linkflags = variant[3]
        else:
          algo_ut_ccflags = "-O0 -g3 -Wall "
          algo_ut_cppdefines = variant[2]
          algo_ut_linkflags = ""
          catd = None
        
          for dir in cantata_tool_dir:
              dir_abspath = Dir(dir).abspath
              if FindFile("cantpp.exe", dir_abspath):
                  catd = os.path.dirname(File(FindFile("cantpp.exe", dir_abspath)).abspath)
                  break

	# Remove the /TP flag from the unit test compilation if so
        # desired, ensures that Cantata generates true C test scripts
        # for C code, and not C++ test scripts.
        if use_msvc == 1:
          if disable_tp_flag:
              algo_ut_ccflags = algo_ut_ccflags.replace("/TP", "")
        else:
          # Replace some Microsoft types
          # But there are more elegant solutions
          algo_ut_cppdefines.append(" __int64=long")
          algo_ut_cppdefines.append(" __int32=int")
          algo_ut_cppdefines.append(" __int16=short")
          algo_ut_cppdefines.append(" __int8=char")

        algo_ut_env.Replace(CCFLAGS = algo_ut_ccflags)
        algo_ut_env.Replace(CPPDEFINES = algo_ut_cppdefines)
        algo_ut_env.Replace(LINKFLAGS = algo_ut_linkflags)

        algo_ut_env.Append(CPPDEFINES = ut_additional_defines[algo_index])

        if use_msvc == 1:
          # Check if the /Zi or /Z7 flag is already included in the compiler
          # configuration. If not, add the /Zi flag to ensure the debugger
          # works with unit test builds. If one of the flags is defined then
          # remove the SCons default of /Z7.
          if algo_ut_ccflags.find("/Zi") > -1 or algo_ut_ccflags.find("/Z7") > -1:
              algo_ut_env['CCPDBFLAGS']  = ['']
          else:
              algo_ut_env["CCPDBFLAGS"]  = "/Zi"	

        unit_test_build_dir = build_dir + "/algo/" + component_name + "_unittests/" + variant[0] + "/" + algo_name
        sconscript_dir = unit_test_build_dir + \
                             "/05_Testing/05_Test_Environment/algo/" + \
                             unit_test_dir + "/" + cantata_unit_test_dir + \
                             "/SConscript_unittests.py"
        algo_ut_env.VariantDir(unit_test_build_dir, "../../../../../../", duplicate = 0)
        result = algo_ut_env.SConscript(sconscript_dir, 
                                        exports = {
                                            "env" : algo_ut_env, 
                                            "component_name" : component_name,
                                            "algo_name" : algo_name,
                                            "algo_name_list" : algo_name_list,
						"variant" : variant[0],
			                        "variant_list" : variant_list,
                                            "generate_ide" : False
                                            })

if profile:
    FinishSconscriptEntry()