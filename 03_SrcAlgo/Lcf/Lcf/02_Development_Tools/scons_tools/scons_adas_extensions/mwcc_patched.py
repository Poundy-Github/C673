"""SCons.Tool.mwcc
Filename                  :  scons_adas_extensions\mwcc_patched.py

Tool-specific initialization for the Metrowerks CodeWarrior compiler.

There normally shouldn't be any need to import this module directly.
It will usually be imported through the generic SCons.Tool.Tool()
selection method.
"""

#
# Copyright (c) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 The SCons Foundation
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

__revision__ = "src/engine/SCons/Tool/mwcc.py 4720 2010/03/24 03:14:11 jars"

import os
import os.path
import string

import SCons.Util
from SCons.Script import *

def set_vars(env):
    """
    Function        :  set_vars
    Description     :  
    env             :  
    Returns         :  
    """
    """Set MWCW_VERSION, MWCW_VERSIONS, and some codewarrior environment vars

    MWCW_VERSIONS is set to a list of objects representing installed versions

    MWCW_VERSION  is set to the version object that will be used for building.
                  MWCW_VERSION can be set to a string during Environment
                  construction to influence which version is chosen, otherwise
                  the latest one from MWCW_VERSIONS is used.

    Returns true if at least one version is found, false otherwise
    """
    desired = env.get('MWCW_VERSION', '')

    # return right away if the variables are already set
    if isinstance(desired, MWVersion):
        return 1
    elif desired is None:
        return 0

    versions = find_versions()
    version = None

    if desired:
        for v in versions:
            if str(v) == desired:
                version = v
    elif versions:
        version = versions[-1]

    env['MWCW_VERSIONS'] = versions
    env['MWCW_VERSION'] = version

    if version is None:
      env['_MW_CW_PATH'] = Dir(env.subst('$MW_CW_PATH')).abspath
      env.PrependENVPath('PATH', env.subst('$_MW_CW_PATH') + "/PowerPC_EABI_Tools/Command_Line_Tools")
      ENV = env['ENV']
      ENV['CWFolder'] = env.subst('"$_MW_CW_PATH"')
      ENV['LM_LICENSE_FILE'] = env.subst('$_MW_CW_PATH') + "/PowerPC_EABI_Tools/Command_Line_Tools/license.dat"

      # set includes and lib directories
      cw_ppcinc   = env.subst('$_MW_CW_PATH') + "/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include"
      cw_mslinc   = env.subst('$_MW_CW_PATH') + "/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include"
      cw_runtlib  = env.subst('$_MW_CW_PATH') + "/PowerPC_EABI_Support/Runtime/Lib"
      cw_mslclib  = env.subst('$_MW_CW_PATH') + "/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Lib"
      cw_mathinc  = env.subst('$_MW_CW_PATH') + "/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Include"
      ENV['MWCIncludes'] = [ cw_ppcinc, cw_mslinc, cw_mathinc ]
      ENV['MWLibraries'] = [ cw_runtlib, cw_mslclib ]
      #print "CW: ", ENV['CWFolder'], ENV['LM_LICENSE_FILE'] 
      return 0

    env.PrependENVPath('PATH', version.clpath)
    env.PrependENVPath('PATH', version.dllpath)
    ENV = env['ENV']
    ENV['CWFolder'] = version.path
    ENV['LM_LICENSE_FILE'] = version.license
    #print "CW version: ", version.path, version.license
    plus = lambda x: '+%s' % x
    ENV['MWCIncludes'] = string.join(map(plus, version.includes), os.pathsep)
    ENV['MWLibraries'] = string.join(map(plus, version.libs), os.pathsep)
    return 1


def find_versions():
    """
    Function        :  find_versions
    Description     :  
    Returns         :  
    """
    """Return a list of MWVersion objects representing installed versions"""
    versions = []

    ### This function finds CodeWarrior by reading from the registry on
    ### Windows. Some other method needs to be implemented for other
    ### platforms, maybe something that calls env.WhereIs('mwcc')

    if SCons.Util.can_read_reg:
        try:
            HLM = SCons.Util.HKEY_LOCAL_MACHINE
            product = 'SOFTWARE\\Metrowerks\\CodeWarrior\\Product Versions'
            product_key = SCons.Util.RegOpenKeyEx(HLM, product)

            i = 0
            while 1:
                name = product + '\\' + SCons.Util.RegEnumKey(product_key, i)
                name_key = SCons.Util.RegOpenKeyEx(HLM, name)

                try:
                    version = SCons.Util.RegQueryValueEx(name_key, 'VERSION')
                    path = SCons.Util.RegQueryValueEx(name_key, 'PATH')
                    mwv = MWVersion(version[0], path[0], 'Win32-X86')
                    versions.append(mwv)
                except SCons.Util.RegError:
                    pass

                i = i + 1

        except SCons.Util.RegError:
            pass

    return versions


class MWVersion:
    def __init__(self, version, path, platform):
        """
        Function              :  __init__
        Description           :  
        version               :  
        path                  :  
        platform              :  
        Returns               :  
        """
        self.version = version
        self.path = path
        self.platform = platform
        self.clpath = os.path.join(path, 'Other Metrowerks Tools',
                                   'Command Line Tools')
        self.dllpath = os.path.join(path, 'Bin')

        # The Metrowerks tools don't store any configuration data so they
        # are totally dumb when it comes to locating standard headers,
        # libraries, and other files, expecting all the information
        # to be handed to them in environment variables. The members set
        # below control what information scons injects into the environment

        ### The paths below give a normal build environment in CodeWarrior for
        ### Windows, other versions of CodeWarrior might need different paths.

        msl = os.path.join(path, 'MSL')
        support = os.path.join(path, '%s Support' % platform)

        self.license = os.path.join(path, 'license.dat')
        self.includes = [msl, support]
        self.libs = [msl, support]

    def __str__(self):
        """
        Function        :  __str__
        Description     :  
        Returns         :  
        """
        return self.version


CSuffixes = ['.c', '.C']
CXXSuffixes = ['.cc', '.cpp', '.cxx', '.c++', '.C++']


def generate(env):
    """
    Function        :  generate
    Description     :  
    env             :  
    Returns         :  
    """
    """Add Builders and construction variables for the mwcc to an Environment."""
    import SCons.Defaults
    import SCons.Tool
    
    set_vars(env)

    static_obj, shared_obj = SCons.Tool.createObjBuilders(env)

    for suffix in CSuffixes:
        static_obj.add_action(suffix, SCons.Defaults.CAction)
        shared_obj.add_action(suffix, SCons.Defaults.ShCAction)

    for suffix in CXXSuffixes:
        static_obj.add_action(suffix, SCons.Defaults.CXXAction)
        shared_obj.add_action(suffix, SCons.Defaults.ShCXXAction)

    env['CCCOMFLAGS'] = '$CPPFLAGS $_CPPDEFFLAGS $_CPPINCFLAGS -nolink -o $TARGET $SOURCES'

    env['CC']         = 'mwcceppc'
    env['CCCOM']      = '$CC $CFLAGS $CCFLAGS $CCCOMFLAGS'

    env['CXX']        = 'mwcceppc'
    env['CXXCOM']     = '$CXX $CXXFLAGS $CCCOMFLAGS'

    env['SHCC']       = '$CC'
    env['SHCCFLAGS']  = '$CCFLAGS'
    env['SHCFLAGS']   = '$CFLAGS'
    env['SHCCCOM']    = '$SHCC $SHCFLAGS $SHCCFLAGS $CCCOMFLAGS'

    env['SHCXX']       = '$CXX'
    env['SHCXXFLAGS']  = '$CXXFLAGS'
    env['SHCXXCOM']    = '$SHCXX $SHCXXFLAGS $CCCOMFLAGS'

    env['CFILESUFFIX'] = '.c'
    env['CXXFILESUFFIX'] = '.cpp'
    env['CPPDEFPREFIX']  = '-D'
    env['CPPDEFSUFFIX']  = ''
    env['INCPREFIX']  = '-I'
    env['INCSUFFIX']  = ''

    env['BUILDERS']['PreprocessCC'] = Builder(action="$CCCOM -preprocess -ppopt comment,noline,nobreak,nopragma",
                                              suffix='.pp',
                                              src_suffix=['.c'])
    env['BUILDERS']['PreprocessCXX']= Builder(action="$CXXCOM -preprocess -ppopt comment,noline,nobreak,nopragma",
                                              suffix='.pp',
                                              src_suffix=['.cpp', '.cxx'])
    env['BUILDERS']['AssemblyCC']= Builder(action="$CCCOM -S $CFLAGS $CCFLAGS $CCCOMFLAGS",
                                           suffix='.S',
                                           src_suffix=['.c'])
    env['BUILDERS']['AssemblyCXX']= Builder(action="$CXXCOM -S $CXXFLAGS $CCCOMFLAGS",
                                            suffix='.S',
                                            src_suffix=['.cpp', '.cxx'])
                                              
    #env['PCH'] = ?
    #env['PCHSTOP'] = ?


def exists(env):
    """
    Function        :  exists
    Description     :  
    env             :  
    Returns         :  
    """
    return set_vars(env)

# Local Variables:
# tab-width:4
# indent-tabs-mode:nil
# End:
# vim: set expandtab tabstop=4 shiftwidth=4:
