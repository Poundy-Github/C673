"""
Filename                  :  scons_adas_extensions\msvs-patched2010.py
Description               :  Script that do the modifications to the Microsoft Visual Studio 2010 builder which is already supplied by SCons.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: msvs-patched.py
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
# CHANGES:                   $Log: msvs-patched2010.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:56CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.3 2017/11/15 07:50:40CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   [Mainstream]Scons issues fixed with the version of VS
# CHANGES:                   Revision 1.2 2016/11/29 06:48:31CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Visual Studio 2010 project creation creates invalid .vcxproj
# CHANGES:                   Revision 1.1 2016/10/05 14:19:15CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/SCT_Sconstools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.6 2016/05/27 11:55:05CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.5 2015/06/26 05:17:41CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:41 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

"""SCons.Tool.msvs

Tool-specific initialization for Microsoft Visual Studio project files.

There normally shouldn't be any need to import this module directly.
It will usually be imported through the generic SCons.Tool.Tool()
selection method.

"""

#
# Copyright (c) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008 The SCons Foundation
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
# KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
# WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#

__revision__ = "src/engine/SCons/Tool/msvs.py 3603 2008/10/10 05:46:45 scons"

import base64
import md5
import os.path
import pickle
import re
import string
import sys

import SCons.Builder
import SCons.Node.FS
import SCons.Platform.win32
import SCons.Script.SConscript
import SCons.Util
import SCons.Warnings

##############################################################################
# Below here are the classes and functions for generation of
# DSP/DSW/SLN/VCPROJ files.
##############################################################################

def _hexdigest(s):
    """
    Function      :  _hexdigest
    Description   :  
    s             :  
    Returns       :  
    """
    """Return a string as a string of hex characters.
    """
    # NOTE:  This routine is a method in the Python 2.0 interface
    # of the native md5 module, but we want SCons to operate all
    # the way back to at least Python 1.5.2, which doesn't have it.
    h = string.hexdigits
    r = ''
    for c in s:
        i = ord(c)
        r = r + h[(i >> 4) & 0xF] + h[i & 0xF]
    return r

def xmlify(s):
    """
    Function      :  xmlify
    Description   :  
    s             :  
    Returns       :  
    """
    s = string.replace(s, "&", "&amp;") # do this first
    s = string.replace(s, "'", "&apos;")
    s = string.replace(s, '"', "&quot;")
    return s

external_makefile_guid = '{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}'

def _generateGUID(slnfile, name):
    """
    Function            :  _generateGUID
    Description         :  
    slnfile             :  
    name                :  
    Returns             :  
    """
    """This generates a dummy GUID for the sln file to use.  It is
    based on the MD5 signatures of the sln filename plus the name of
    the project.  It basically just needs to be unique, and not
    change with each invocation."""
    # TODO(1.5)
    #solution = _hexdigest(md5.new(str(slnfile)+str(name)).digest()).upper()
    solution = string.upper(_hexdigest(md5.new(str(slnfile)+str(name)).digest()))
    # convert most of the signature to GUID form (discard the rest)
    solution = "{" + solution[:8] + "-" + solution[8:12] + "-" + solution[12:16] + "-" + solution[16:20] + "-" + solution[20:32] + "}"
    return solution

version_re = re.compile(r'(\d+\.\d+)(.*)')

def msvs_parse_version(s):
    """
    Function      :  msvs_parse_version
    Description   :  
    s             :  
    Returns       :  
    """
    """
    Split a Visual Studio version, which may in fact be something like
    '7.0Exp', into is version number (returned as a float) and trailing
    "suite" portion.
    """
    num, suite = version_re.match(s).groups()
    return float(num), suite

# This is how we re-invoke SCons from inside MSVS Project files.
# The problem is that we might have been invoked as either scons.bat
# or scons.py.  If we were invoked directly as scons.py, then we could
# use sys.argv[0] to find the SCons "executable," but that doesn't work
# if we were invoked as scons.bat, which uses "python -c" to execute
# things and ends up with "-c" as sys.argv[0].  Consequently, we have
# the MSVS Project file invoke SCons the same way that scons.bat does,
# which works regardless of how we were invoked.
def getExecScriptMain(env, xml=None):
    """
    Function         :  getExecScriptMain
    Description      :  
    env              :  
    xml              :  
    Returns          :  
    """
    scons_home = env.get('SCONS_HOME')
    if not scons_home and os.environ.has_key('SCONS_LIB_DIR'):
        scons_home = os.environ['SCONS_LIB_DIR']
    if scons_home:
        exec_script_main = "from os.path import join; import sys; sys.path = [ r'%s' ] + sys.path; import SCons.Script; SCons.Script.main()" % scons_home
    else:
        version = SCons.__version__
        exec_script_main = "from os.path import join; import sys; sys.path = [ join(sys.prefix, 'Lib', 'site-packages', 'scons-%(version)s'), join(sys.prefix, 'scons-%(version)s'), join(sys.prefix, 'Lib', 'site-packages', 'scons'), join(sys.prefix, 'scons') ] + sys.path; import SCons.Script; SCons.Script.main()" % locals()
    if xml:
        exec_script_main = xmlify(exec_script_main)
    return exec_script_main

# The string for the Python executable we tell the Project file to use
# is either sys.executable or, if an external PYTHON_ROOT environment
# variable exists, $(PYTHON)ROOT\\python.exe (generalized a little to
# pluck the actual executable name from sys.executable).
try:
    python_root = os.environ['PYTHON_ROOT']
except KeyError:
    python_executable = sys.executable
else:
    python_executable = os.path.join('$$(PYTHON_ROOT)',
                                     os.path.split(sys.executable)[1])

class Config:
    pass

def splitFully(path):
    """
    Function         :  splitFully
    Description      :  
    path             :  
    Returns          :  
    """
    dir, base = os.path.split(path)
    if dir and dir != '' and dir != path:
        return splitFully(dir)+[base]
    if base == '':
        return []
    return [base]
	
def makeHierarchy(sources):
    """
    Function            :  makeHierarchy
    Description         :  
    sources             :  
    Returns             :  
    """
    '''Break a list of files into a hierarchy; for each value, if it is a string,
       then it is a file.  If it is a dictionary, it is a folder.  The string is
       the original path of the file.'''
    hierarchy = {}
    for file in sources:
        path = splitFully(file)
        if len(path):
            dict = hierarchy
            for part in path[:-1]:
                if not dict.has_key(part):
                    dict[part] = {}
                dict = dict[part]
            dict[path[-1]] = file
    return hierarchy

class _DSPGenerator:
    """ Base class for DSP generators """

    srcargs = [
        'srcs',
        'incs',
        'localincs',
        'resources',
        'misc']

    def __init__(self, dspfile, source, env):
        """
        Function             :  __init__
        Description          :  
        dspfile              :  
        source               :  
        env                  :  
        Returns              :  
        """
        self.dspfile = str(dspfile)
        try:
            get_abspath = dspfile.get_abspath
        except AttributeError:
            self.dspabs = os.path.abspath(dspfile)
        else:
            self.dspabs = get_abspath()
        
        # 2014-10-23 Andre.Fischer-Ext (uidg5297), ITK Engineering AG:
        # ------------------------------------------------------------
        # In case blds, i.e. the nodes to build targets, is specified for the Visual studio project, corresponding header files need to be searched here.
        if not env.has_key('blds'):
            pass
        else:
            # determine includes
            header_files = env.FindAllIncludes(env['blds'])
            # ignore all header files coming from externals
            header_files = [header for header in header_files if not (header.startswith('C:\\LegacyApp') or '02_Development_Tools' in header or '04_Build' in header)]
            # append headers to source files
            env[self.srcargs[0]].extend(header_files)

        if not env.has_key('variant'):
            raise SCons.Errors.InternalError, \
                  "You must specify a 'variant' argument (i.e. 'Debug' or " +\
                  "'Release') to create an MSVSProject."
        elif SCons.Util.is_String(env['variant']):
            variants = [env['variant']]
        elif SCons.Util.is_List(env['variant']):
            variants = env['variant']
            
        if not env.has_key('cppdefs'):
            cppdefines = len(variants) * [env.subst_list('$CPPDEFINES')[0]]
        else:
            cppdefines = env['cppdefs']
            if len(cppdefines) != len(variants):
                raise SCons.Errors.InternalError, \
                    "Number of cppdefine lists must match the length of 'variant' list."

        if not env.has_key('buildtarget') or env['buildtarget'] == None:
            buildtarget = ['']
        elif SCons.Util.is_String(env['buildtarget']):
            buildtarget = [env['buildtarget']]
        elif SCons.Util.is_List(env['buildtarget']):
            if len(env['buildtarget']) != len(variants):
                raise SCons.Errors.InternalError, \
                    "Sizes of 'buildtarget' and 'variant' lists must be the same."
            buildtarget = []
            for bt in env['buildtarget']:
                if SCons.Util.is_String(bt):
                    buildtarget.append(bt)
                else:
                    buildtarget.append(bt.get_abspath())
        else:
            buildtarget = [env['buildtarget'].get_abspath()]
        if len(buildtarget) == 1:
            bt = buildtarget[0]
            buildtarget = []
            for _ in variants:
                buildtarget.append(bt)

        if not env.has_key('outdir') or env['outdir'] == None:
            outdir = ['']
        elif SCons.Util.is_String(env['outdir']):
            outdir = [env['outdir']]
        elif SCons.Util.is_List(env['outdir']):
            if len(env['outdir']) != len(variants):
                raise SCons.Errors.InternalError, \
                    "Sizes of 'outdir' and 'variant' lists must be the same."
            outdir = []
            for s in env['outdir']:
                if SCons.Util.is_String(s):
                    outdir.append(s)
                else:
                    outdir.append(s.get_abspath())
        else:
            outdir = [env['outdir'].get_abspath()]
        if len(outdir) == 1:
            s = outdir[0]
            outdir = []
            for v in variants:
                outdir.append(s)

        if not env.has_key('runfile') or env['runfile'] == None:
            runfile = buildtarget[-1:]
        elif SCons.Util.is_String(env['runfile']):
            runfile = [env['runfile']]
        elif SCons.Util.is_List(env['runfile']):
            if len(env['runfile']) != len(variants):
                raise SCons.Errors.InternalError, \
                    "Sizes of 'runfile' and 'variant' lists must be the same."
            runfile = []
            for s in env['runfile']:
                if SCons.Util.is_String(s):
                    runfile.append(s)
                else:
                    runfile.append(s.get_abspath())
        else:
            runfile = [env['runfile'].get_abspath()]
        if len(runfile) == 1:
            s = runfile[0]
            runfile = []
            for v in variants:
                runfile.append(s)

        self.sconscript = env['MSVSSCONSCRIPT']

        cmdargs = env.get('cmdargs', '')

        self.env = env

        if self.env.has_key('name'):
            self.name = self.env['name']
        else:
            self.name = os.path.basename(SCons.Util.splitext(self.dspfile)[0])
        self.name = self.env.subst(self.name)
		
		# 2014-05-07 Andre Fischer-EXT (uidg5297):
		# The construction environment in use stores the names of all sources in use filtered by
		# 'srcs', 'incs', 'localincs', 'resources', 'misc'. Usually only env['srcs'] (Source Files) 
		# and env['incs'] (Header Files) are non-empty. 
		# Both sets of sources are mapped to 'Source Files' in order to prevent 
		# a separation of those in the Solution Explorer of the VS project.
        sourcenames = [
            'Source Files',
            'Source Files',   # 'Header Files'
            'Local Headers',
            'Resource Files',
            'Other Files']

        self.sources = {}
        for n in sourcenames:
            self.sources[n] = []

        self.configs = {}

        self.nokeep = 0
        if env.has_key('nokeep') and env['variant'] != 0:
            self.nokeep = 1

        if self.nokeep == 0 and os.path.exists(self.dspabs):
            self.Parse()

        for t in zip(sourcenames,self.srcargs):
            if self.env.has_key(t[1]):
                if SCons.Util.is_List(self.env[t[1]]):
                    for i in self.env[t[1]]:
                        if not i in self.sources[t[0]]:
                            self.sources[t[0]].append(i)
                else:
                    if not self.env[t[1]] in self.sources[t[0]]:
                        self.sources[t[0]].append(self.env[t[1]])

        for n in sourcenames:
            # TODO(1.5):
            #self.sources[n].sort(lambda a, b: cmp(a.lower(), b.lower()))
            self.sources[n].sort(lambda a, b: cmp(string.lower(a), string.lower(b)))

        def AddConfig(self, variant, buildtarget, outdir, runfile, cmdargs, cppdefines, dspfile=dspfile):
            """
            Function                 :  AddConfig
            Description              :  
            variant                  :  
            buildtarget              :  
            outdir                   :  
            runfile                  :  
            cmdargs                  :  
            cppdefines               :  
            dspfile                  :  
            Returns                  :  
            """
            config = Config()
            config.buildtarget = buildtarget
            config.outdir = outdir
            config.cmdargs = cmdargs
            config.runfile = runfile
            config.cppdefines = cppdefines

            match = re.match('(.*)\|(.*)', variant)
            if match:
                config.variant = match.group(1)
                config.platform = match.group(2)
            else:
                config.variant = variant
                config.platform = 'Win32'

            self.configs[variant] = config
            print "Adding '" + self.name + ' - ' + config.variant + '|' + config.platform + "' to '" + str(dspfile) + "'"

        for i in range(len(variants)):
            AddConfig(self, variants[i], buildtarget[i], outdir[i], runfile[i], cmdargs, cppdefines[i])

        self.platforms = []
        for key in self.configs.keys():
            platform = self.configs[key].platform
            if not platform in self.platforms:
                self.platforms.append(platform)

    def Build(self):
        """
        Function        :  Build
        Description     :  
        Returns         :  
        """
        pass

		
V8DSPHeader = """\
<?xml version="1.0" encoding="%(encoding)s"?>
<Project DefaultTargets="Build" ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
"""

V8FilterHeader = """\
<?xml version="1.0" encoding="%(encoding)s"?>
<Project ToolsVersion="4.0" xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
"""


V8DSPProjectConfiguration = """\
\t<ProjectConfiguration Include="%(buildtarget)s|Win32">
\t\t<Configuration>%(buildtarget)s</Configuration>
\t\t<Platform>Win32</Platform>
\t</ProjectConfiguration>
"""

V8DSPImportConfiguration = """\
  <PropertyGroup Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'" Label="Configuration">
\t<ConfigurationType>Makefile</ConfigurationType>
\t<UseOfMfc>false</UseOfMfc>
  </PropertyGroup>
"""

v8DSPPropertysheetsConfiguration = """\
  <ImportGroup Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'" Label="PropertySheets">
\t<Import Project="$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props" Condition="exists('$(UserRootDir)\Microsoft.Cpp.$(Platform).user.props')" Label="LocalAppDataPlatform" />
  </ImportGroup>
"""

V8DSPConfiguration = """\
\t<NMakeBuildCommandLine Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">%(buildcmd)s</NMakeBuildCommandLine>
\t<NMakeReBuildCommandLine Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">%(rebuildcmd)s</NMakeReBuildCommandLine>
\t<NMakeCleanCommandLine Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">%(cleancmd)s</NMakeCleanCommandLine>
\t<NMakeOutput Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">%(runfile)s</NMakeOutput>
\t<NMakePreprocessorDefinitions Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">%(preprocdefs)s</NMakePreprocessorDefinitions>
\t<NMakeIncludeSearchPath Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">%(includepath)s</NMakeIncludeSearchPath>
\t<NMakeForcedIncludes Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">$(NMakeForcedIncludes)</NMakeForcedIncludes>
\t<NMakeAssemblySearchPath Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">$(NMakeAssemblySearchPath)</NMakeAssemblySearchPath>
\t<NMakeForcedUsingAssemblies Condition="'$(Configuration)|$(Platform)'=='%(buildtarget)s|Win32'">$(NMakeForcedUsingAssemblies)</NMakeForcedUsingAssemblies>
"""


class _GenerateV7DSP(_DSPGenerator):
    """Generates a Project file for MSVS .NET"""

    def __init__(self, dspfile, source, env):
        """
        Function             :  __init__
        Description          :  
        dspfile              :  
        source               :  
        env                  :  
        Returns              :  
        """
        _DSPGenerator.__init__(self, dspfile, source, env)
        self.version = env['MSVS_VERSION']
        self.version_num, self.suite = msvs_parse_version(self.version)
        self.versionstr = '8.00'
        self.dspheader = V8DSPHeader
        self.dspconfiguration = V8DSPConfiguration
        self.projectConfiguration = V8DSPProjectConfiguration
        self.importConfiguration = V8DSPImportConfiguration
        self.propertysheetsConfiguration = v8DSPPropertysheetsConfiguration
        self.file = None

    def PrintHeader(self):
        """
        Function        :  PrintHeader
        Description     :  
        Returns         :  
        """
        env = self.env
        versionstr = self.versionstr
        name = self.name
        encoding = self.env.subst('$MSVSENCODING')
        scc_provider = env.get('MSVS_SCC_PROVIDER', '')
        scc_project_name = env.get('MSVS_SCC_PROJECT_NAME', '')
        scc_aux_path = env.get('MSVS_SCC_AUX_PATH', '')
        scc_local_path = env.get('MSVS_SCC_LOCAL_PATH', '')
        project_guid = env.get('MSVS_PROJECT_GUID', '')
        if self.version_num >= 8.0 and not project_guid:
            project_guid = _generateGUID(self.dspfile, '')
        if scc_provider != '':
            scc_attrs = ('\tProjectGUID="%s"\n'
                         '\tSccProjectName="%s"\n'
                         '\tSccAuxPath="%s"\n'
                         '\tSccLocalPath="%s"\n'
                         '\tSccProvider="%s"' % (project_guid, scc_project_name, scc_aux_path, scc_local_path, scc_provider))
        else:
            scc_attrs = ('\tProjectGUID="%s"\n'
                         '\tSccProjectName="%s"\n'
                         '\tSccLocalPath="%s"' % (project_guid, scc_project_name, scc_local_path))

        self.file.write(self.dspheader % locals())
        
        self.file.write('  <ItemGroup Label="ProjectConfigurations">\n')
        confkeys = self.configs.keys()
        confkeys.sort()
        for kind in confkeys:
            buildtarget = self.configs[kind].buildtarget
            self.file.write(self.projectConfiguration % locals())
        self.file.write('  </ItemGroup>\n')
        self.file.write('  <PropertyGroup Label="Globals">\n')
        t = ('\t</PropertyGuid>"%s"' % (project_guid))
        self.file.write('\t<ProjectGuid>%s</ProjectGuid>\n' % (project_guid))
        self.file.write('\t<SccProjectName />\n')
        self.file.write('\t<SccLocalPath />\n')
        self.file.write('\t<RootNameSpace>%s</RootNameSpace>\n' % name)
        self.file.write('\t<Keyword>MakeFileProj</Keyword>\n')
        self.file.write('  </PropertyGroup>\n')	

        self.file.write('  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.Default.props" />\n')
        for kind in confkeys:
            buildtarget = self.configs[kind].buildtarget
            self.file.write(self.importConfiguration % locals())

        self.file.write('  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.props" />\n')
        self.file.write('  <ImportGroup Label="ExtensionSettings">\n')
        self.file.write('  </ImportGroup>\n')
		
        for kind in confkeys:
            buildtarget = self.configs[kind].buildtarget
            self.file.write(self.propertysheetsConfiguration % locals())
					
        self.file.write('  <PropertyGroup Label="UserMacros" />\n')

    def PrintAllFiles(self):
        
        self.file.write('  <ItemGroup>\n')
        for file in self.header_files:
            self.file.write('\t<ClInclude Include="%s" />\n' % file)
        self.file.write('  </ItemGroup>\n')

        self.file.write('  <ItemGroup>\n')
        for file in self.source_files:
            self.file.write('\t<ClCompile Include="%s" />\n' % file)
        self.file.write('  </ItemGroup>\n')
		
        self.file.write('  <ItemGroup>\n')
        for file in self.other_source_files:
            self.file.write('\t<None Include="%s" />\n' % file)
        self.file.write('\t<None Include="SConstruct" />\n')
        self.file.write('  </ItemGroup>\n')
        		
        self.file.write('  <Import Project="$(VCTargetsPath)\Microsoft.Cpp.targets" />\n')
        self.file.write('  <ImportGroup Label="ExtensionTargets">\n')
        self.file.write('  </ImportGroup>\n')
		
		
    def PrintProject(self):
        """
        Function        :  PrintProject
        Description     :  
        Returns         :  
        """
        self.file.write('  <PropertyGroup>\n')
        self.file.write('\t<_ProjectFileVersion>10.0.40219.1</_ProjectFileVersion>\n')
        confkeys = self.configs.keys()
        confkeys.sort()
        for kind in confkeys:
            variant = self.configs[kind].variant
            platform = self.configs[kind].platform
            outdir = self.configs[kind].outdir
            buildtarget = self.configs[kind].buildtarget
            runfile     = self.configs[kind].runfile
            cmdargs = self.configs[kind].cmdargs
            cppdefines = self.configs[kind].cppdefines

            env_has_buildtarget = self.env.has_key('MSVSBUILDTARGET')
            if not env_has_buildtarget:
                self.env['MSVSBUILDTARGET'] = buildtarget

            starting = 'echo Starting SCons && '
            if cmdargs:
                cmdargs = ' ' + cmdargs
            else:
                cmdargs = ''
            buildcmd    = xmlify(starting + self.env.subst('$MSVSBUILDCOM', 1) + cmdargs)
            rebuildcmd  = xmlify(starting + self.env.subst('$MSVSREBUILDCOM', 1) + cmdargs)
            cleancmd    = xmlify(starting + self.env.subst('$MSVSCLEANCOM', 1) + cmdargs)

            preprocdefs = xmlify(';'.join(map(str,cppdefines)))
            includepath = xmlify(';'.join(map(str,self.env.subst_list('$CPPPATH')[0])))

            if not env_has_buildtarget:
                del self.env['MSVSBUILDTARGET']
            self.file.write(self.dspconfiguration % locals())
        self.file.write('  </PropertyGroup>\n')
		
    header_ext = ['.h']
    source_ext = ['.c', '.cpp']
    source_files = []
    other_source_files = []
    header_files = []
    filterHeaderPaths = []
    filterSourcePaths = []
    filterOtherSourcePaths = []
    def printSources(self, hierarchy, commonprefix):
        """
        Function                  :  printSources
        Description               :  
        hierarchy                 :  
        commonprefix              :  
        Returns                   :  
        """
        sorteditems = hierarchy.items()
        # TODO(1.5):
        #sorteditems.sort(lambda a, b: cmp(a[0].lower(), b[0].lower()))
        sorteditems.sort(lambda a, b: cmp(string.lower(a[0]), string.lower(b[0])))
        # First folders, then files
        for key, value in sorteditems:
            if SCons.Util.is_Dict(value):
                self.printSources(value, commonprefix)

        for key, value in sorteditems:
            if SCons.Util.is_String(value):
                file = value
                if commonprefix:
                    file = os.path.join(commonprefix, value)
                file = os.path.normpath(file)
                for kind in self.header_ext:
                    if kind in value:
                        self.filterHeaderPaths.append(self.returnFilterPath(value))
                        value = "..\..\..\..\..\\" + value
                        self.header_files.append(value)
                    else:
                        for kind1 in self.source_ext:
                            if kind1 in value: 
                                self.filterSourcePaths.append(self.returnFilterPath(value))
                                value = "..\..\..\..\..\\" + value
                                self.source_files.append(value)
                                break
                            else:
                                self.filterOtherSourcePaths.append(self.returnFilterPath(value))
                                value = "..\..\..\..\..\\" + value
                                self.other_source_files.append(value)
                                break
        

    def PrintSourceFiles(self):
        """
        Function        :  PrintSourceFiles
        Description     :  
        Returns         :  
        """
        categories = {'Source Files': 'cpp;c;cxx;l;y;def;odl;idl;hpj;bat',
                      'Source Files': 'h;hpp;hxx;hm;inl',
                      'Local Headers': 'h;hpp;hxx;hm;inl',
                      'Resource Files': 'r;rc;ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe',
                      'Other Files': ''}
				

        cats = categories.keys()
        # TODO(1.5)
        #cats.sort(lambda a, b: cmp(a.lower(), b.lower()))
        cats.sort(lambda a, b: cmp(string.lower(a), string.lower(b)))
        cats = filter(lambda k, s=self: s.sources[k], cats)
        for kind in cats:

            sources = self.sources[kind]
            # First remove any common prefix
            commonprefix = None
            if len(sources) > 1:
                s = map(os.path.normpath, sources)
                # take the dirname because the prefix may include parts
                # of the filenames (e.g. if you have 'dir\abcd' and
                # 'dir\acde' then the cp will be 'dir\a' )
                cp = os.path.dirname( os.path.commonprefix(s) )
                if cp and s[0][len(cp)] == os.sep:
                    # +1 because the filename starts after the separator
                    sources = map(lambda s, l=len(cp)+1: s[l:], sources)
                    commonprefix = cp
            elif len(sources) == 1:
                commonprefix = os.path.dirname( sources[0] )
                sources[0] = os.path.basename( sources[0] )

            hierarchy = makeHierarchy(sources)
            self.printSources(hierarchy, commonprefix=commonprefix)

            filterFileHierarchy = self.makeFilterFileHierarchy(sources)
            self.GenerateFilter(filterFileHierarchy)

    def Parse(self):
        """
        Function        :  Parse
        Description     :  
        Returns         :  
        """
        try:
            dspfile = open(self.dspabs,'r')
        except IOError:
            return # doesn't exist yet, so can't add anything to configs.

        line = dspfile.readline()
        while line:
            # TODO(1.5)
            #if line.find('<!-- SCons Data:') > -1:
            if string.find(line, '<!-- SCons Data:') > -1:
                break
            line = dspfile.readline()

        line = dspfile.readline()
        datas = line
        while line and line != '\n':
            line = dspfile.readline()
            datas = datas + line

        # OK, we've found our little pickled cache of data.
        try:
            datas = base64.decodestring(datas)
            data = pickle.loads(datas)
        except KeyboardInterrupt:
            raise
        except:
            return # unable to unpickle any data for some reason

        self.configs.update(data)

        data = None
        line = dspfile.readline()
        datas = line
        while line and line != '\n':
            line = dspfile.readline()
            datas = datas + line

        # OK, we've found our little pickled cache of data.
        try:
            datas = base64.decodestring(datas)
            data = pickle.loads(datas)
        except KeyboardInterrupt:
            raise
        except:
            return # unable to unpickle any data for some reason

        self.sources.update(data)
		
    def returnFilterPath(self, sources):
        list = ''
        path = splitFully(sources)
        for count in xrange(len(path) - 1):
            list = list + path[count] + "\\"
        return list[:-1] 
		
    def makeFilterFileHierarchy(self, sources):	
        folderList = []
        folderList1 = []
        count = 0
        list1 = ''
        for file in sources:
            path = splitFully(file)
            if path[:-1] not in folderList:
                folderList.append(path[:-1])
        for item in folderList:
            while(count < len(item)):
                list1 = list1 + item[count] + "\\"
                if list1[:-1] not in folderList1:
                    folderList1.append(list1[:-1])
                count += 1
            count = 0
            list1 = ''
        return folderList1

    def GenerateFilter(self, filterFileHierarchy):
        filterFile = self.dspabs + '.filters'	
        self.filterFile = open(filterFile, 'w')
        encoding = self.env.subst('$MSVSENCODING')
        self.FilterHeader = V8FilterHeader    
        self.filterFile.write(self.FilterHeader % locals())	
        self.filterFile.write('  <ItemGroup>\n')
        for item in filterFileHierarchy:		
            self.filterFile.write('\t<Filter Include="%s">\n' % item)
            s = _generateGUID(item, '')
            self.filterFile.write('\t  <UniqueIdentifier>%s</UniqueIdentifier>\n' % s)
            self.filterFile.write('\t</Filter>\n')
        self.filterFile.write('  </ItemGroup>\n')
		
        self.filterFile.write('  <ItemGroup>\n')		
        for count in xrange(len(self.header_files)):
            self.filterFile.write('\t<ClInclude Include="%s">\n' % self.header_files[count])
            self.filterFile.write('\t  <Filter>%s</Filter>\n' % self.filterHeaderPaths[count])
            self.filterFile.write('\t</ClInclude>\n')
        self.filterFile.write('  </ItemGroup>\n')

        self.filterFile.write('  <ItemGroup>\n')
        for count in xrange(len(self.source_files)):
            self.filterFile.write('\t<ClCompile Include="%s">\n' % self.source_files[count])
            self.filterFile.write('\t  <Filter>%s</Filter>\n' % self.filterSourcePaths[count])
            self.filterFile.write('\t</ClCompile>\n')
        self.filterFile.write('  </ItemGroup>\n')
		
        self.filterFile.write('  <ItemGroup>\n')
        for count in xrange(len(self.other_source_files)):
            self.filterFile.write('\t<None Include="%s">\n' % self.other_source_files[count])
            self.filterFile.write('\t  <Filter>%s</Filter>\n' % self.filterOtherSourcePaths[count])
            self.filterFile.write('\t</None>\n')
        self.filterFile.write('\t<None Include="SConstruct" />\n')
        self.filterFile.write('  </ItemGroup>\n')
        self.filterFile.write('</Project>\n')
		
        self.filterFile.close()
		
    def Build(self):
        """
        Function        :  Build
        Description     :  
        Returns         :  
        """
        try:
            self.file = open(self.dspabs,'w')
        except IOError, detail:
            raise SCons.Errors.InternalError, 'Unable to open "' + self.dspabs + '" for writing:' + str(detail)
        else:
            self.PrintHeader()
            self.PrintProject()
            self.PrintSourceFiles()
            self.file.write('  <ItemDefinitionGroup>\n')
            self.file.write('  </ItemDefinitionGroup>\n')
            self.PrintAllFiles()
            self.file.write('\n</Project>')
            self.file.close()


class _DSWGenerator:
    """ Base class for DSW generators """
    def __init__(self, dswfile, source, env):
        """
        Function             :  __init__
        Description          :  
        dswfile              :  
        source               :  
        env                  :  
        Returns              :  
        """
        self.dswfile = os.path.normpath(str(dswfile))
        self.env = env

        if not env.has_key('projects'):
            raise SCons.Errors.UserError, \
                "You must specify a 'projects' argument to create an MSVSSolution."
        projects = env['projects']
        if not SCons.Util.is_List(projects):
            raise SCons.Errors.InternalError, \
                "The 'projects' argument must be a list of nodes."
        projects = SCons.Util.flatten(projects)
        if len(projects) < 1:
            raise SCons.Errors.UserError, \
                "You must specify at least one project to create an MSVSSolution."
        self.dspfiles = map(str, projects)

        if self.env.has_key('name'):
            self.name = self.env['name']
        else:
            self.name = os.path.basename(SCons.Util.splitext(self.dswfile)[0])
        self.name = self.env.subst(self.name)

    def Build(self):
        """
        Function        :  Build
        Description     :  
        Returns         :  
        """
        pass

class _GenerateV7DSW(_DSWGenerator):
    """Generates a Solution file for MSVS .NET"""
    def __init__(self, dswfile, source, env):
        """
        Function             :  __init__
        Description          :  
        dswfile              :  
        source               :  
        env                  :  
        Returns              :  
        """
        _DSWGenerator.__init__(self, dswfile, source, env)

        self.file = None
        self.version = self.env['MSVS_VERSION']
        self.version_num, self.suite = msvs_parse_version(self.version)
        self.versionstr = '11.00'

        if env.has_key('slnguid') and env['slnguid']:
            self.slnguid = env['slnguid']
        else:
            self.slnguid = _generateGUID(dswfile, self.name)

        self.configs = {}

        self.nokeep = 0
        if env.has_key('nokeep') and env['variant'] != 0:
            self.nokeep = 1

        if self.nokeep == 0 and os.path.exists(self.dswfile):
            self.Parse()

        def AddConfig(self, variant, dswfile=dswfile):
            """
            Function             :  AddConfig
            Description          :  
            variant              :  
            dswfile              :  
            Returns              :  
            """
            config = Config()

            match = re.match('(.*)\|(.*)', variant)
            if match:
                config.variant = match.group(1)
                config.platform = match.group(2)
            else:
                config.variant = variant
                config.platform = 'Win32'

            self.configs[variant] = config
            print "Adding '" + self.name + ' - ' + config.variant + '|' + config.platform + "' to '" + str(dswfile) + "'"

        if not env.has_key('variant'):
            raise SCons.Errors.InternalError, \
                  "You must specify a 'variant' argument (i.e. 'Debug' or " +\
                  "'Release') to create an MSVS Solution File."
        elif SCons.Util.is_String(env['variant']):
            AddConfig(self, env['variant'])
        elif SCons.Util.is_List(env['variant']):
            for variant in env['variant']:
                AddConfig(self, variant)

        self.platforms = []
        for key in self.configs.keys():
            platform = self.configs[key].platform
            if not platform in self.platforms:
                self.platforms.append(platform)

    def Parse(self):
        """
        Function        :  Parse
        Description     :  
        Returns         :  
        """
        try:
            dswfile = open(self.dswfile,'r')
        except IOError:
            return # doesn't exist yet, so can't add anything to configs.

        line = dswfile.readline()
        while line:
            if line[:9] == "EndGlobal":
                break
            line = dswfile.readline()

        line = dswfile.readline()
        datas = line
        while line:
            line = dswfile.readline()
            datas = datas + line

        # OK, we've found our little pickled cache of data.
        try:
            datas = base64.decodestring(datas)
            data = pickle.loads(datas)
        except KeyboardInterrupt:
            raise
        except:
            return # unable to unpickle any data for some reason

        self.configs.update(data)

    def PrintSolution(self):
        """
        Function        :  PrintSolution
        Description     :  
        Returns         :  
        """
        """Writes a solution file"""
        self.file.write('Microsoft Visual Studio Solution File, Format Version %s\n' % self.versionstr )
        self.file.write('# Visual Studio 2010\n')#('# Visual Studio 2005\n')
        for p in self.dspfiles:
            name = os.path.basename(p)
            base, suffix = SCons.Util.splitext(name)
            if suffix == '.vcproj':
                name = base
            guid = _generateGUID(p, '')
            self.file.write('Project("%s") = "%s", "%s", "%s"\n'
                            % ( external_makefile_guid, name, p, guid ) )
            self.file.write('EndProject\n')

        self.file.write('Global\n')

        env = self.env
        if env.has_key('MSVS_SCC_PROVIDER'):
            dspfile_base = os.path.basename(self.dspfile)
            slnguid = self.slnguid
            scc_provider = env.get('MSVS_SCC_PROVIDER', '')
            scc_provider = string.replace(scc_provider, ' ', r'\u0020')
            scc_project_name = env.get('MSVS_SCC_PROJECT_NAME', '')
            # scc_aux_path = env.get('MSVS_SCC_AUX_PATH', '')
            scc_local_path = env.get('MSVS_SCC_LOCAL_PATH', '')
            scc_project_base_path = env.get('MSVS_SCC_PROJECT_BASE_PATH', '')
            # project_guid = env.get('MSVS_PROJECT_GUID', '')

            self.file.write('\tGlobalSection(SourceCodeControl) = preSolution\n'
                            '\t\tSccNumberOfProjects = 2\n'
                            '\t\tSccProjectUniqueName0 = %(dspfile_base)s\n'
                            '\t\tSccLocalPath0 = %(scc_local_path)s\n'
                            '\t\tCanCheckoutShared = true\n'
                            '\t\tSccProjectFilePathRelativizedFromConnection0 = %(scc_project_base_path)s\n'
                            '\t\tSccProjectName1 = %(scc_project_name)s\n'
                            '\t\tSccLocalPath1 = %(scc_local_path)s\n'
                            '\t\tSccProvider1 = %(scc_provider)s\n'
                            '\t\tCanCheckoutShared = true\n'
                            '\t\tSccProjectFilePathRelativizedFromConnection1 = %(scc_project_base_path)s\n'
                            '\t\tSolutionUniqueID = %(slnguid)s\n'
                            '\tEndGlobalSection\n' % locals())

        self.file.write('\tGlobalSection(SolutionConfigurationPlatforms) = preSolution\n')

        confkeys = self.configs.keys()
        confkeys.sort()
        cnt = 0
        for name in confkeys:
            variant = self.configs[name].variant
            platform = self.configs[name].platform
            self.file.write('\t\t%s|%s = %s|%s\n' % (variant, platform, variant, platform))
            cnt = cnt + 1
        self.file.write('\tEndGlobalSection\n')
        self.file.write('\tGlobalSection(ProjectConfigurationPlatforms) = postSolution\n')

        for name in confkeys:
            variant = self.configs[name].variant
            platform = self.configs[name].platform
            for p in self.dspfiles:
                guid = _generateGUID(p, '')
                self.file.write('\t\t%s.%s|%s.ActiveCfg = %s|%s\n'
                                    '\t\t%s.%s|%s.Build.0 = %s|%s\n'  % (guid,variant,platform,variant,platform,guid,variant,platform,variant,platform))

        self.file.write('\tEndGlobalSection\n')

        self.file.write('\tGlobalSection(SolutionProperties) = preSolution\n'
                            '\t\tHideSolutionNode = FALSE\n'
                            '\tEndGlobalSection\n')
        self.file.write('EndGlobal\n')
        if self.nokeep == 0:
            pdata = pickle.dumps(self.configs,1)
            pdata = base64.encodestring(pdata)
            self.file.write(pdata + '\n')

    def Build(self):
        """
        Function        :  Build
        Description     :  
        Returns         :  
        """
        try:
            self.file = open(self.dswfile,'w')
        except IOError, detail:
            raise SCons.Errors.InternalError, 'Unable to open "' + self.dswfile + '" for writing:' + str(detail)
        else:
            self.PrintSolution()
            self.file.close()


def GenerateDSP(dspfile, source, env):
    """
    Function            :  GenerateDSP
    Description         :  
    dspfile             :  
    source              :  
    env                 :  
    Returns             :  
    """
    """Generates a Project file based on the version of MSVS that is being used"""

    version_num = 6.0
    if env.has_key('MSVS_VERSION'):
        version_num, suite = msvs_parse_version(env['MSVS_VERSION'])
    g = _GenerateV7DSP(dspfile, source, env)
    g.Build()

def GenerateDSW(dswfile, source, env):
    """
    Function            :  GenerateDSW
    Description         :  
    dswfile             :  
    source              :  
    env                 :  
    Returns             :  
    """
    """Generates a Solution/Workspace file based on the version of MSVS that is being used"""
    version_num = 6.0
    if env.has_key('MSVS_VERSION'):
        version_num, suite = msvs_parse_version(env['MSVS_VERSION'])
    g = _GenerateV7DSW(dswfile, source, env)
    g.Build()


##############################################################################
# Above here are the classes and functions for generation of
# DSP/DSW/SLN/VCPROJ files.
##############################################################################

def get_default_visualstudio_version(env):
    """
    Function        :  get_default_visualstudio_version
    Description     :  
    env             :  
    Returns         :  
    """
    """Returns the version set in the env, or the latest version
    installed, if it can find it, or '6.0' if all else fails.  Also
    updates the environment with what it found."""

    versions = ['6.0']

    if not env.has_key('MSVS') or not SCons.Util.is_Dict(env['MSVS']):
        v = get_visualstudio_versions()
        if v:
            versions = v
        env['MSVS'] = {'VERSIONS' : versions}
    else:
        versions = env['MSVS'].get('VERSIONS', versions)

    if not env.has_key('MSVS_VERSION'):
        env['MSVS_VERSION'] = versions[0] #use highest version by default

    env['MSVS']['VERSION'] = env['MSVS_VERSION']

    return env['MSVS_VERSION']

def get_visualstudio_versions():
    """
    Function        :  get_visualstudio_versions
    Description     :  
    Returns         :  
    """
    """
    Get list of visualstudio versions from the Windows registry.
    Returns a list of strings containing version numbers.  An empty list
    is returned if we were unable to accees the register (for example,
    we couldn't import the registry-access module) or the appropriate
    registry keys weren't found.
    """

    if not SCons.Util.can_read_reg:
        return []

    HLM = SCons.Util.HKEY_LOCAL_MACHINE
    KEYS = {
        r'Software\Microsoft\VisualStudio'      : '',
        r'Software\Microsoft\VCExpress'         : 'Exp',
    }
    L = []
    for K, suite_suffix in KEYS.items():
        try:
            k = SCons.Util.RegOpenKeyEx(HLM, K)
            i = 0
            while 1:
                try:
                    p = SCons.Util.RegEnumKey(k,i)
                except SCons.Util.RegError:
                    break
                i = i + 1
                if not p[0] in '123456789' or p in L:
                    continue
                # Only add this version number if there is a valid
                # registry structure (includes the "Setup" key),
                # and at least some of the correct directories
                # exist.  Sometimes VS uninstall leaves around
                # some registry/filesystem turds that we don't
                # want to trip over.  Also, some valid registry
                # entries are MSDN entries, not MSVS ('7.1',
                # notably), and we want to skip those too.
                try:
                    SCons.Util.RegOpenKeyEx(HLM, K + '\\' + p + '\\Setup')
                except SCons.Util.RegError:
                    continue

                id = []
                idk = SCons.Util.RegOpenKeyEx(HLM, K + '\\' + p)
                # This is not always here -- it only exists if the
                # user installed into a non-standard location (at
                # least in VS6 it works that way -- VS7 seems to
                # always write it)
                try:
                    id = SCons.Util.RegQueryValueEx(idk, 'InstallDir')
                except SCons.Util.RegError:
                    pass

                # If the InstallDir key doesn't exist,
                # then we check the default locations.
                # Note: The IDE's executable is not devenv.exe for VS8 Express.
                if not id or not id[0]:
                    files_dir = SCons.Platform.win32.get_program_files_dir()
                    version_num, suite = msvs_parse_version(p)
                    if version_num < 7.0:
                        vs = r'Microsoft Visual Studio\Common\MSDev98'
                    elif version_num < 8.0:
                        vs = r'Microsoft Visual Studio .NET\Common7\IDE'
                    else:
                        vs = r'Microsoft Visual Studio 8\Common7\IDE'
                    id = [ os.path.join(files_dir, vs) ]
                if os.path.exists(id[0]):
                    L.append(p + suite_suffix)
        except SCons.Util.RegError:
            pass

    if not L:
        return []

    # This is a hack to get around the fact that certain Visual Studio
    # patches place a "6.1" version in the registry, which does not have
    # any of the keys we need to find include paths, install directories,
    # etc.  Therefore we ignore it if it is there, since it throws all
    # other logic off.
    try:
        L.remove("6.1")
    except ValueError:
        pass

    L.sort()
    L.reverse()

    return L

def get_default_visualstudio8_suite(env):
    """
    Function        :  get_default_visualstudio8_suite
    Description     :  
    env             :  
    Returns         :  
    """
    """
    Returns the Visual Studio 2005 suite identifier set in the env, or the
    highest suite installed.
    """
    if not env.has_key('MSVS') or not SCons.Util.is_Dict(env['MSVS']):
        env['MSVS'] = {}

    if env.has_key('MSVS_SUITE'):
        # TODO(1.5)
        #suite = env['MSVS_SUITE'].upper()
        suite = string.upper(env['MSVS_SUITE'])
        suites = [suite]
    else:
        suite = 'EXPRESS'
        suites = [suite]
        if SCons.Util.can_read_reg:
            suites = get_visualstudio8_suites()
            if suites:
                suite = suites[0] #use best suite by default

    env['MSVS_SUITE'] = suite
    env['MSVS']['SUITES'] = suites
    env['MSVS']['SUITE'] = suite

    return suite

def get_visualstudio8_suites():
    """
    Function        :  get_visualstudio8_suites
    Description     :  
    Returns         :  
    """
    """
    Returns a sorted list of all installed Visual Studio 2005 suites found
    in the registry. The highest version should be the first entry in the list.
    """

    suites = []

    # Detect Standard, Professional and Team edition
    try:
        idk = SCons.Util.RegOpenKeyEx(SCons.Util.HKEY_LOCAL_MACHINE,
            r'Software\Microsoft\VisualStudio\8.0')
        SCons.Util.RegQueryValueEx(idk, 'InstallDir')
        editions = { 'PRO': r'Setup\VS\Pro' }       # ToDo: add standard and team editions
        edition_name = 'STD'
        for name, key_suffix in editions.items():
            try:
                idk = SCons.Util.RegOpenKeyEx(SCons.Util.HKEY_LOCAL_MACHINE,
                    r'Software\Microsoft\VisualStudio\8.0' + '\\' + key_suffix )
                edition_name = name
            except SCons.Util.RegError:
                pass
            suites.append(edition_name)
    except SCons.Util.RegError:
        pass

    # Detect Express edition
    try:
        idk = SCons.Util.RegOpenKeyEx(SCons.Util.HKEY_LOCAL_MACHINE,
            r'Software\Microsoft\VCExpress\8.0')
        SCons.Util.RegQueryValueEx(idk, 'InstallDir')
        suites.append('EXPRESS')
    except SCons.Util.RegError:
        pass

    return suites

def is_msvs_installed():
    """
    Function        :  is_msvs_installed
    Description     :  
    Returns         :  
    """
    """
    Check the registry for an installed visual studio.
    """
    try:
        v = SCons.Tool.msvs.get_visualstudio_versions()
        return v
    except (SCons.Util.RegError, SCons.Errors.InternalError):
        return 0

def get_msvs_install_dirs(version = None, vs8suite = None):
    """
    Function               :  get_msvs_install_dirs
    Description            :  
    version                :  
    vs8suite               :  
    Returns                :  
    """
    """
    Get installed locations for various msvc-related products, like the .NET SDK
    and the Platform SDK.
    """

    if not SCons.Util.can_read_reg:
        return {}

    if not version:
        versions = get_visualstudio_versions()
        if versions:
            version = versions[0] #use highest version by default
        else:
            return {}

    version_num, suite = msvs_parse_version(version)

    K = 'Software\\Microsoft\\VisualStudio\\' + str(version_num)
    if (version_num >= 8.0):
        if vs8suite == None:
            # We've been given no guidance about which Visual Studio 8
            # suite to use, so attempt to autodetect.
            suites = get_visualstudio8_suites()
            if suites:
                vs8suite = suites[0]

        if vs8suite == 'EXPRESS':
            K = 'Software\\Microsoft\\VCExpress\\' + str(version_num)

    # vc++ install dir
    rv = {}
    if (version_num < 7.0):
        key = K + r'\Setup\Microsoft Visual C++\ProductDir'
    else:
        key = K + r'\Setup\VC\ProductDir'
    try:
        (rv['VCINSTALLDIR'], t) = SCons.Util.RegGetValue(SCons.Util.HKEY_LOCAL_MACHINE, key)
    except SCons.Util.RegError:
        pass

    # visual studio install dir
    if (version_num < 7.0):
        try:
            (rv['VSINSTALLDIR'], t) = SCons.Util.RegGetValue(SCons.Util.HKEY_LOCAL_MACHINE,
                                                             K + r'\Setup\Microsoft Visual Studio\ProductDir')
        except SCons.Util.RegError:
            pass

        if not rv.has_key('VSINSTALLDIR') or not rv['VSINSTALLDIR']:
            if rv.has_key('VCINSTALLDIR') and rv['VCINSTALLDIR']:
                rv['VSINSTALLDIR'] = os.path.dirname(rv['VCINSTALLDIR'])
            else:
                rv['VSINSTALLDIR'] = os.path.join(SCons.Platform.win32.get_program_files_dir(),'Microsoft Visual Studio')
    else:
        try:
            (rv['VSINSTALLDIR'], t) = SCons.Util.RegGetValue(SCons.Util.HKEY_LOCAL_MACHINE,
                                                             K + r'\Setup\VS\ProductDir')
        except SCons.Util.RegError:
            pass

    # .NET framework install dir
    try:
        (rv['FRAMEWORKDIR'], t) = SCons.Util.RegGetValue(SCons.Util.HKEY_LOCAL_MACHINE,
            r'Software\Microsoft\.NETFramework\InstallRoot')
    except SCons.Util.RegError:
        pass

    if rv.has_key('FRAMEWORKDIR'):
        # try and enumerate the installed versions of the .NET framework.
        contents = os.listdir(rv['FRAMEWORKDIR'])
        l = re.compile('v[0-9]+.*')
        installed_framework_versions = filter(lambda e, l=l: l.match(e), contents)

        def versrt(a,b):
            """
            Function      :  versrt
            Description   :  
            a             :  
            b             :  
            Returns       :  
            """
            # since version numbers aren't really floats...
            aa = a[1:]
            bb = b[1:]
            aal = string.split(aa, '.')
            bbl = string.split(bb, '.')
            # sequence comparison in python is lexicographical
            # which is exactly what we want.
            # Note we sort backwards so the highest version is first.
            return cmp(bbl,aal)

        installed_framework_versions.sort(versrt)

        rv['FRAMEWORKVERSIONS'] = installed_framework_versions

        # TODO: allow a specific framework version to be set

        # Choose a default framework version based on the Visual
        # Studio version.
        DefaultFrameworkVersionMap = {
            '7.0'   : 'v1.0',
            '7.1'   : 'v1.1',
            '8.0'   : 'v2.0',
            # TODO: Does .NET 3.0 need to be worked into here somewhere?
        }
        try:
            default_framework_version = DefaultFrameworkVersionMap[version[:3]]
        except (KeyError, TypeError):
            pass
        else:
            # Look for the first installed directory in FRAMEWORKDIR that
            # begins with the framework version string that's appropriate
            # for the Visual Studio version we're using.
            for v in installed_framework_versions:
                if v[:4] == default_framework_version:
                    rv['FRAMEWORKVERSION'] = v
                    break

        # If the framework version couldn't be worked out by the previous
        # code then fall back to using the latest version of the .NET
        # framework
        if not rv.has_key('FRAMEWORKVERSION'):
            rv['FRAMEWORKVERSION'] = installed_framework_versions[0]

    # .NET framework SDK install dir
    if rv.has_key('FRAMEWORKVERSION'):
        # The .NET SDK version used must match the .NET version used,
        # so we deliberately don't fall back to other .NET framework SDK
        # versions that might be present.
        ver = rv['FRAMEWORKVERSION'][:4]
        key = r'Software\Microsoft\.NETFramework\sdkInstallRoot' + ver
        try:
            (rv['FRAMEWORKSDKDIR'], t) = SCons.Util.RegGetValue(SCons.Util.HKEY_LOCAL_MACHINE,
                key)
        except SCons.Util.RegError:
            pass

    # MS Platform SDK dir
    try:
        (rv['PLATFORMSDKDIR'], t) = SCons.Util.RegGetValue(SCons.Util.HKEY_LOCAL_MACHINE,
            r'Software\Microsoft\MicrosoftSDK\Directories\Install Dir')
    except SCons.Util.RegError:
        pass

    if rv.has_key('PLATFORMSDKDIR'):
        # if we have a platform SDK, try and get some info on it.
        vers = {}
        try:
            loc = r'Software\Microsoft\MicrosoftSDK\InstalledSDKs'
            k = SCons.Util.RegOpenKeyEx(SCons.Util.HKEY_LOCAL_MACHINE,loc)
            i = 0
            while 1:
                try:
                    key = SCons.Util.RegEnumKey(k,i)
                    sdk = SCons.Util.RegOpenKeyEx(k,key)
                    j = 0
                    name = ''
                    date = ''
                    version = ''
                    while 1:
                        try:
                            (vk,vv,t) = SCons.Util.RegEnumValue(sdk,j)
                            # TODO(1.5):
                            #if vk.lower() == 'keyword':
                            #    name = vv
                            #if vk.lower() == 'propagation_date':
                            #    date = vv
                            #if vk.lower() == 'version':
                            #    version = vv
                            if string.lower(vk) == 'keyword':
                                name = vv
                            if string.lower(vk) == 'propagation_date':
                                date = vv
                            if string.lower(vk) == 'version':
                                version = vv
                            j = j + 1
                        except SCons.Util.RegError:
                            break
                    if name:
                        vers[name] = (date, version)
                    i = i + 1
                except SCons.Util.RegError:
                    break
            rv['PLATFORMSDK_MODULES'] = vers
        except SCons.Util.RegError:
            pass

    return rv

def GetMSVSProjectSuffix(target, source, env, for_signature):
     """
     Function                   :  GetMSVSProjectSuffix
     Description                :  
     target                     :  
     source                     :  
     env                        :  
     for_signature              :  
     Returns                    :  
     """
     return env['MSVS']['PROJECTSUFFIX']

def GetMSVSSolutionSuffix(target, source, env, for_signature):
     """
     Function                   :  GetMSVSSolutionSuffix
     Description                :  
     target                     :  
     source                     :  
     env                        :  
     for_signature              :  
     Returns                    :  
     """
     return env['MSVS']['SOLUTIONSUFFIX']

def GenerateProject(target, source, env):
    """
    Function            :  GenerateProject
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    # generate the dsp file, according to the version of MSVS.
    builddspfile = target[0]
    dspfile = builddspfile.srcnode()
    # this detects whether or not we're using a VariantDir
    if not dspfile is builddspfile:
        try:
            bdsp = open(str(builddspfile), "w+")            
        except IOError, detail:
            print 'Unable to open "' + str(dspfile) + '" for writing:',detail,'\n'
            raise
        bdsp.write("This is just a placeholder file.\nThe real project file is here:\n%s\n" % dspfile.get_abspath())

    GenerateDSP(dspfile, source, env)

    if env.get('auto_build_solution', 1):
        builddswfile = target[1]
        dswfile = builddswfile.srcnode()

        if not dswfile is builddswfile:

            try:
                bdsw = open(str(builddswfile), "w+")
            except IOError, detail:
                print 'Unable to open "' + str(dspfile) + '" for writing:',detail,'\n'
                raise

            bdsw.write("This is just a placeholder file.\nThe real workspace file is here:\n%s\n" % dswfile.get_abspath())

        GenerateDSW(dswfile, source, env)

def GenerateSolution(target, source, env):
    """
    Function            :  GenerateSolution
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    GenerateDSW(target[0], source, env)

def projectEmitter(target, source, env):
    """
    Function            :  projectEmitter
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    """Sets up the DSP dependencies."""

    # todo: Not sure what sets source to what user has passed as target,
    # but this is what happens. When that is fixed, we also won't have
    # to make the user always append env['MSVSPROJECTSUFFIX'] to target.
    if source[0] == target[0]:
        source = []

    # make sure the suffix is correct for the version of MSVS we're running.
    (base, suff) = SCons.Util.splitext(str(target[0]))
    suff = env.subst('$MSVSPROJECTSUFFIX')
    target[0] = base + suff

    if not source:
        source = 'prj_inputs:'
        source = source + env.subst('$MSVSSCONSCOM', 1)
        source = source + env.subst('$MSVSENCODING', 1)

        if env.has_key('buildtarget') and env['buildtarget'] != None:
            if SCons.Util.is_String(env['buildtarget']):
                source = source + ' "%s"' % env['buildtarget']
            elif SCons.Util.is_List(env['buildtarget']):
                for bt in env['buildtarget']:
                    if SCons.Util.is_String(bt):
                        source = source + ' "%s"' % bt
                    else:
                        try: source = source + ' "%s"' % bt.get_abspath()
                        except AttributeError: raise SCons.Errors.InternalError, \
                            "buildtarget can be a string, a node, a list of strings or nodes, or None"
            else:
                try: source = source + ' "%s"' % env['buildtarget'].get_abspath()
                except AttributeError: raise SCons.Errors.InternalError, \
                    "buildtarget can be a string, a node, a list of strings or nodes, or None"

        if env.has_key('outdir') and env['outdir'] != None:
            if SCons.Util.is_String(env['outdir']):
                source = source + ' "%s"' % env['outdir']
            elif SCons.Util.is_List(env['outdir']):
                for s in env['outdir']:
                    if SCons.Util.is_String(s):
                        source = source + ' "%s"' % s
                    else:
                        try: source = source + ' "%s"' % s.get_abspath()
                        except AttributeError: raise SCons.Errors.InternalError, \
                            "outdir can be a string, a node, a list of strings or nodes, or None"
            else:
                try: source = source + ' "%s"' % env['outdir'].get_abspath()
                except AttributeError: raise SCons.Errors.InternalError, \
                    "outdir can be a string, a node, a list of strings or nodes, or None"

        if env.has_key('name'):
            if SCons.Util.is_String(env['name']):
                source = source + ' "%s"' % env['name']
            else:
                raise SCons.Errors.InternalError, "name must be a string"

        if env.has_key('variant'):
            if SCons.Util.is_String(env['variant']):
                source = source + ' "%s"' % env['variant']
            elif SCons.Util.is_List(env['variant']):
                for variant in env['variant']:
                    if SCons.Util.is_String(variant):
                        source = source + ' "%s"' % variant
                    else:
                        raise SCons.Errors.InternalError, "name must be a string or a list of strings"
            else:
                raise SCons.Errors.InternalError, "variant must be a string or a list of strings"
        else:
            raise SCons.Errors.InternalError, "variant must be specified"

        for s in _DSPGenerator.srcargs:
            if env.has_key(s):
                if SCons.Util.is_String(env[s]):
                    source = source + ' "%s' % env[s]
                elif SCons.Util.is_List(env[s]):
                    for t in env[s]:
                        if SCons.Util.is_String(t):
                            source = source + ' "%s"' % t
                        else:
                            raise SCons.Errors.InternalError, s + " must be a string or a list of strings"
                else:
                    raise SCons.Errors.InternalError, s + " must be a string or a list of strings"

        source = source + ' "%s"' % str(target[0])
        source = [SCons.Node.Python.Value(source)]

    targetlist = [target[0]]
    sourcelist = source

    if env.get('auto_build_solution', 1):
        env['projects'] = targetlist
        t, s = solutionEmitter(target, target, env)
        targetlist = targetlist + t

    return (targetlist, sourcelist)

def solutionEmitter(target, source, env):
    """
    Function            :  solutionEmitter
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    """Sets up the DSW dependencies."""
    # todo: Not sure what sets source to what user has passed as target,
    # but this is what happens. When that is fixed, we also won't have
    # to make the user always append env['MSVSSOLUTIONSUFFIX'] to target.
    if source[0] == target[0]:
        source = []

    # make sure the suffix is correct for the version of MSVS we're running.
    (base, suff) = SCons.Util.splitext(str(target[0]))
    suff = env.subst('$MSVSSOLUTIONSUFFIX')
    target[0] = base + suff

    if not source:
        source = 'sln_inputs:'

        if env.has_key('name'):
            if SCons.Util.is_String(env['name']):
                source = source + ' "%s"' % env['name']
            else:
                raise SCons.Errors.InternalError, "name must be a string"

        if env.has_key('variant'):
            if SCons.Util.is_String(env['variant']):
                source = source + ' "%s"' % env['variant']
            elif SCons.Util.is_List(env['variant']):
                for variant in env['variant']:
                    if SCons.Util.is_String(variant):
                        source = source + ' "%s"' % variant
                    else:
                        raise SCons.Errors.InternalError, "name must be a string or a list of strings"
            else:
                raise SCons.Errors.InternalError, "variant must be a string or a list of strings"
        else:
            raise SCons.Errors.InternalError, "variant must be specified"

        if env.has_key('slnguid'):
            if SCons.Util.is_String(env['slnguid']):
                source = source + ' "%s"' % env['slnguid']
            else:
                raise SCons.Errors.InternalError, "slnguid must be a string"

        if env.has_key('projects'):
            if SCons.Util.is_String(env['projects']):
                source = source + ' "%s"' % env['projects']
            elif SCons.Util.is_List(env['projects']):
                for t in env['projects']:
                    if SCons.Util.is_String(t):
                        source = source + ' "%s"' % t

        source = source + ' "%s"' % str(target[0])
        source = [SCons.Node.Python.Value(source)]
    return ([target[0]], source)

projectAction = SCons.Action.Action(GenerateProject, None)

solutionAction = SCons.Action.Action(GenerateSolution, None)

projectBuilder = SCons.Builder.Builder(action = '$MSVSPROJECTCOM',
                                       suffix = '$MSVSPROJECTSUFFIX',
                                       emitter = projectEmitter)

solutionBuilder = SCons.Builder.Builder(action = '$MSVSSOLUTIONCOM',
                                        suffix = '$MSVSSOLUTIONSUFFIX',
                                        emitter = solutionEmitter)

default_MSVS_SConscript = None

def generate(env):
    """
    Function        :  generate
    Description     :  
    env             :  
    Returns         :  
    """
    """Add Builders and construction variables for Microsoft Visual
    Studio project files to an Environment."""
    try:
        env['BUILDERS']['MSVSProject']
    except KeyError:
        env['BUILDERS']['MSVSProject'] = projectBuilder

    try:
        env['BUILDERS']['MSVSSolution']
    except KeyError:
        env['BUILDERS']['MSVSSolution'] = solutionBuilder

    env['MSVSPROJECTCOM'] = projectAction
    env['MSVSSOLUTIONCOM'] = solutionAction
    if SCons.Script.call_stack:
        # XXX Need to find a way to abstract this; the build engine
        # shouldn't depend on anything in SCons.Script.
        env['MSVSSCONSCRIPT'] = SCons.Script.call_stack[0].sconscript
    else:
        global default_MSVS_SConscript
        if default_MSVS_SConscript is None:
            default_MSVS_SConscript = env.File('SConstruct')
        env['MSVSSCONSCRIPT'] = default_MSVS_SConscript

    env['MSVSSCONS'] = '"%s" -c "%s"' % (python_executable, getExecScriptMain(env))
    env['MSVSSCONSFLAGS'] = '-C "${MSVSSCONSCRIPT.dir.abspath}" -f ${MSVSSCONSCRIPT.name}'
    env['MSVSSCONSCOM'] = '$MSVSSCONS $MSVSSCONSFLAGS'
    env['MSVSBUILDCOM'] = '$MSVSSCONSCOM "$MSVSBUILDTARGET"'
    env['MSVSREBUILDCOM'] = '$MSVSSCONSCOM "$MSVSBUILDTARGET"'
    env['MSVSCLEANCOM'] = '$MSVSSCONSCOM -c "$MSVSBUILDTARGET"'
    env['MSVSENCODING'] = 'utf-8'

    try:
        version = get_default_visualstudio_version(env)
        # keep a record of some of the MSVS info so the user can use it.
        dirs = get_msvs_install_dirs(version)
        env['MSVS'].update(dirs)
    except (SCons.Util.RegError, SCons.Errors.InternalError):
        # we don't care if we can't do this -- if we can't, it's
        # because we don't have access to the registry, or because the
        # tools aren't installed.  In either case, the user will have to
        # find them on their own.
        pass

    version_num, suite = msvs_parse_version(env['MSVS_VERSION'])
    env['MSVS']['PROJECTSUFFIX']  = '.vcxproj'
    env['MSVS']['SOLUTIONSUFFIX'] = '.sln'

    env['GET_MSVSPROJECTSUFFIX']  = GetMSVSProjectSuffix
    env['GET_MSVSSOLUTIONSUFFIX']  = GetMSVSSolutionSuffix
    env['MSVSPROJECTSUFFIX']  = '${GET_MSVSPROJECTSUFFIX}'
    env['MSVSSOLUTIONSUFFIX']  = '${GET_MSVSSOLUTIONSUFFIX}'
    env['SCONS_HOME'] = os.environ.get('SCONS_HOME')

def exists(env):
    """
    Function        :  exists
    Description     :  
    env             :  
    Returns         :  
    """
    if not env['PLATFORM'] in ('win32', 'cygwin'):
        return 0

    try:
        v = SCons.Tool.msvs.get_visualstudio_versions()
    except (SCons.Util.RegError, SCons.Errors.InternalError):
        pass

    if not v:
        version_num = 6.0
        if env.has_key('MSVS_VERSION'):
            version_num, suite = msvs_parse_version(env['MSVS_VERSION'])
        if version_num >= 7.0:
            # The executable is 'devenv' in Visual Studio Pro,
            # Team System and others.  Express Editions have different
            # executable names.  Right now we're only going to worry
            # about Visual C++ 2005 Express Edition.
            return env.Detect('devenv') or env.Detect('vcexpress')
        else:
            return env.Detect('msdev')
    else:
        # there's at least one version of MSVS installed.
        return 1
