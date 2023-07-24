"""
Filename                  :  scons_adas_extensions\msvc-addon.py
Description               :  Script that do the modifications to the Microsoft Visual Studio builder which is already supplied by SCons.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: msvc-addon.py
#
# DESCRIPTION: Script that do the modifications to the Microsoft Visual Studio builder which is already 
#              supplied by SCons.
#
# INITIAL AUTHOR: Spruck, Jochen (spruckj)
#
# CREATION DATE: - 2013/01/29
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:56CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: msvc-addon.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:56CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.6 2016/05/27 11:50:20CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.5 2015/06/26 05:17:23CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:23 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

import SCons.Tool.msvc
import os.path
from SCons.Script import *

# we want to have the debugging settings in the strange .$DOMAINNAME.$USERNAME vcproj extension
def createMSVSDebuggingSettings(target, source, env):
    """
    Function            :  createMSVSDebuggingSettings
    Description         :  To modify the debugging setting of MSVS.
    target              :  
    source              :  
    env                 :  Environment variable.
    Returns             :  
    """
    f = open(target[0].abspath, "w")
    f.write(
"""<?xml version="1.0" encoding="Windows-1252"?>
<VisualStudioUserFile
\tProjectType="Visual C++"
\tVersion="8,00"
\tShowAllFiles="false"
\t>
\t<Configurations>
""")
    for i,v in enumerate(env['variant']):
        f.write(
"""\t\t<Configuration
\t\t\tName="%(variant)s|Win32"
\t\t\t>
\t\t\t<DebugSettings
\t\t\t\tCommand="%(runfile)s"
\t\t\t\tWorkingDirectory="%(rundir)s"
\t\t\t\tCommandArguments="%(runargs)s"
\t\t\t\tEnvironment="%(environment)s"
\t\t\t\tEnvironmentMerge="true"
\t\t\t/>
\t\t</Configuration>
""" % {
    'variant' : v,
    'runfile' : os.path.normcase(env['runfile'][i]),
    'rundir'  : os.path.normcase(env['rundir'][i]),
    'runargs' : os.path.normcase(env['runargs'][i]),
    'environment' : "&#x0A;".join([i + '=' + v + '' for i,v in env.get('environment', {})[i].iteritems()])
    })
    f.write("""\t</Configurations>
</VisualStudioUserFile>
""")

def createMSVSDebuggingSettingsEmitter(target, source, env):
    """
    Function            :  createMSVSDebuggingSettingsEmitter
    Description         :  
    target              :  
    source              :  
    env                 :  Environment variable.
    Returns             :  
    """
    target = [str(source[0]) + "." + os.environ['USERDOMAIN'] + "." + os.environ['USERNAME'] + ".user"]
    return target, source    
    
def FindAllIncludes(self, target):
    """
    Function            :  FindAllIncludes
    Description         :  To find include files.
    target              :  
    Returns             :  
    """
    def _find_sources(tgt, hdr, all):
        for item in tgt:
            if not isinstance(item, SCons.Node.Python.Value):
                if SCons.Util.is_List(item):
                    _find_sources(item, src, hdr, all)
                else:
                    if not hasattr(item, 'abspath'):
                        continue
                    if all.has_key(item.abspath):
                        continue

                    all[item.abspath] = True

                    if item.path.endswith('.h') or item.path.endswith('.he'):
                        if not item.exists():
                            item = item.srcnode()
                        if not item.is_derived():
                            hdr.append(item.abspath)
                    else:
                        lst = item.children(scan=1)
                        _find_sources(lst, hdr, all)

    headers = []
    _find_sources(target, headers, {})
    return headers

    
def generate(env):
    """
    Function        :  generate
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    env.AddMethod(FindAllIncludes)
    env['BUILDERS']['MSVSProjectDebug'] = Builder(action=Action(createMSVSDebuggingSettings, 
                                                                "Creating msvc debugging settings for '$TARGETS'"),
                                                  emitter=createMSVSDebuggingSettingsEmitter)

    # this environment variable is used to determine whether building for ecu or simulation
    env['_BUILD_TARGET'] = env.subst('$BUILD_TARGET')
    
    # overwrite the preprocessor only if it does not exist
    if not ("PreprocessCC" in env['BUILDERS']):
        env['PREPROCESSCCCOM'] = '$CC /E /C $CHANGED_SOURCES $_CPPDEFFLAGS $_CPPINCFLAGS > $TARGET'
        env['PREPROCESSCCCOMSTR'] = '$PREPROCESSCCCOM'
        env['BUILDERS']['PreprocessCC'] = Builder(action = Action('$PREPROCESSCCCOM', '$PREPROCESSCCCOMSTR'),
                                                  suffix='.pp',
                                                  src_suffix=['.c'],
                                                  source_scanner = CScan)
    # set maximal length of command line according to current windows version (Windows 7)
    if env['HOST_OS'] == 'win32':
        # Roland Stark (ITK, +49 69 8700008 290): workaround for SCons v2.2.0 (See also Issue # 256901)
        # The maximum line length for windows is 8192 but the calculation of the real line length is false.
        # Spaces in the command line are ignored. This leads to a problem if a command line is slightly 
        # longer than 8192 characters. So I reduced the threshold from 8192 to 7800 (in the crashing situation
        # I recognized 79 spaces so a reduction by 392 keeps a little space and seems to be save).
        # File:        __init__.py (MKS Rev 1.2, Line 173-175)
        # Member Path: /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/STP_SharedToolProjects/04_Engineering/scons/scons-local/SCons/Platform/__init__.py
        # SCT Path:    /SCT_Sconstools/scons/scons-local/SCons/Platform/__init__.py
        env['MAXLINELENGTH'] = 7800

def exists(env):
    """
    Function        :  exists
    Description     :  Standard SCons function.
    env             :  Environment variable.
    Returns         :  
    """
    return SCons.Tool.msvc.exists(env)                               