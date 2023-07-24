"""
Filename                  :  scons_adas_extensions\ti_eve_arp32.py
Description               :  Script used to setup ARP32 build environment. It specifies the TI 
                             compiler used, include directories and library directories
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: ti_eve_arp32.py
#
# DESCRIPTION: Script used to setup ARP32 build environment. It specifies the TI 
#              compiler used, include directories and library directories.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/03/14
#
# LAST CHANGE:      $Date: 2021/12/13 19:04:00CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: ti_eve_arp32.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:00CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.15 2016/05/27 12:54:25CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.14 2015/09/23 16:04:04CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add keys "_TOOLS" and "_TOOL_ADDONS" to environmental construction dictionary 
# CHANGES:                   in order to map dependencies to ti-tools for the build
# CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:04:05 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.13 2015/06/26 05:17:27CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:27 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

from SCons.Script import *

import SCons.Tool
import SCons.Tool.cc
import SCons.Tool.link
import SCons.Scanner
import SCons.Util
import re, os.path, string, errno

def libEmitter(target, source, env):
    """
    Function            :  libEmitter
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    dir = os.path.dirname(target[0].path)
    dirabs = os.path.dirname(target[0].abspath)
    t = str(target[0])
    tb = os.path.splitext(t)[0]
    cmd = dirabs + '\\' + 'ar-arp32.cmd'
    t = dir + '\\' + t
    dirabs = dirabs.replace("\\","/")
    # write targets and sources into cmd
    try:
        os.makedirs(dirabs)
    except OSError, e:
        if e.errno != errno.EEXIST:
            raise
    f = open(cmd, "w")
    f.write("""; Command file to replace members of the
; modules library with updated files
; Use r command:
r
; Specify library name:
%(targetlib)s
; List filenames to be replaced:
""" % {
        'targetlib': t
    })
    for src in source:
        # f.write(dir + '\\' + str(src) + '\n')
        f.write(File(str(src)).abspath + '\n')
    
    f.close()
    env['ARCMD'] = cmd
    return target, source

def FindAllObjects(self, target):
    """
    Function            :  FindAllObjects
    Description         :  
    target              :  
    Returns             :  
    """
    def _find_sources(tgt, hdr, all):
        for item in tgt:
            if SCons.Util.is_List(item):
                _find_sources(item, src, hdr, all)
            else:
                if all.has_key(item.abspath):
                    continue

                all[item.abspath] = True

                if item.path.endswith('.obj'):
                    if not item.exists():
                        item = item.srcnode()
                    hdr.append(item.abspath)
                else:
                    lst = item.children(scan = 1)
                    _find_sources(lst, hdr, all)

    headers = []
    _find_sources(target, headers, {})
    return headers

def eval_map_file(target, source, env):
    """
    Function            :  eval_map_file
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    map_file = os.path.splitext(str(target[0]))[0] + ".map"
    eval_src = env.get('MAP_EVAL_SRC', [])
    objs = env.FindAllObjects(eval_src)
    if len(objs) > 0:
        f = open(map_file,"r")
        text = f.read()
        ram_size = r"([0-9a-f]+)[ \t]+([0-9a-f]+)[^\n]*("
        items = []
        for obj in objs:
            obj = os.path.split(str(obj))[1]
            items.append("(?:" + obj + ")")
        ram_size += "|".join(items)
        items = []
        for s in ["text", "code", "far", "const", "cinit", "bss", "switch", "pinit"]:
            items.append("(?:" + s + ")")
        ram_size += ") \(\.(" + "|".join(items) + ")"
        matches = re.compile(ram_size).findall(text)
        pdlane_mem = {}
        for M in matches:
            if not M is None:
                start = M[0]
                length = M[1]
                file = M[2]
                segment = M[3]
                if not segment in pdlane_mem:
                    pdlane_mem[segment] = 0
                pdlane_mem[segment] += eval("0x" + length)
        print "Memory usage evaluation with focus on %s:" % (" ".join(map(str, eval_src)))
        for s in pdlane_mem.keys():
            print "%8s: %dM %3dk %3d" % (s,
                pdlane_mem[s] / (1024 * 1024),
                (pdlane_mem[s] / (1024)) % 1024,
                pdlane_mem[s] % 1024)
    
def generate(env):
    """
    Function        :  generate
    Description     :  
    env             :  
    Returns         :  
    """
    """Add Builders and construction variables for gcc to an Environment."""
    
    # compiler stuff
    SCons.Tool.cc.generate(env)
    
    # this environment variable is used to determine whether building for ecu or simulation
    env['_BUILD_TARGET'] = env.subst('$BUILD_TARGET')
    
    env['_ARP32_CODE_GEN_TOOL_PATH'] = Dir(env.subst('$ARP32_CODE_GEN_TOOL_PATH')).abspath
    env['_EVE_EDMA_CSL_PATH'] = Dir(env.subst('$EVE_EDMA_CSL_PATH')).abspath
    env['ARP32_EVE_LCF_FILE'] = ''
    env['ARP32_EVE_LCF_FILE_PREFIX'] = "-l "
    env['ARP32_EVE_LCF_FILE_SUFFIX'] = ""
    env['_ARP32_EVE_LCF_FILE'] = '${_concat(ARP32_EVE_LCF_FILE_PREFIX, ARP32_EVE_LCF_FILE, ARP32_EVE_LCF_FILE_SUFFIX, __env__)}'
    env['ARP32_ENTRY_POINT'] = ''
    env['ARP32_ENTRY_POINT_PREFIX'] = "-e "
    env['ARP32_ENTRY_POINT_SUFFIX'] = ""
    env['_ARP32_ENTRY_POINT'] = '${_concat(ARP32_ENTRY_POINT_PREFIX, ARP32_ENTRY_POINT, ARP32_ENTRY_POINT_SUFFIX, __env__)}'

    env.PrependENVPath('PATH', env.subst('"$_ARP32_CODE_GEN_TOOL_PATH/bin"'))
    static_obj, shared_obj = SCons.Tool.createObjBuilders(env)
    asm_suffixes = ['.asm']
    for suffix in asm_suffixes:
        static_obj.add_action(suffix, SCons.Defaults.CAction)
        shared_obj.add_action(suffix, SCons.Defaults.ShCAction)
        static_obj.add_emitter(suffix, SCons.Defaults.StaticObjectEmitter)
        shared_obj.add_emitter(suffix, SCons.Defaults.SharedObjectEmitter)
   
    env['CC'] = 'cl-arp32'
    env['CCCOM'] = '$CC $CFLAGS $CCFLAGS $_CCCOMCOM ${SOURCES} -fb=${TARGET.dir} -fs=${TARGET.dir} -ff=${TARGET.dir} -fr=${TARGET.dir} -ft=${TARGET.dir} --pp_directory=${TARGET.dir} ' 
    env['CCCOMSTR'] = '$CCCOM'

    env['_TOOLS'] = env.subst('$_ARP32_CODE_GEN_TOOL_PATH/bin/$CC') + '.exe'
    env['_TOOL_ADDONS'] = env.subst('$_EVE_EDMA_CSL_PATH')

    # add include paths
    env.Append(CPPPATH = [env['_ARP32_CODE_GEN_TOOL_PATH'] + "/include", env['_ARP32_CODE_GEN_TOOL_PATH'] + "/include/vcop", env['_EVE_EDMA_CSL_PATH'], "${TARGET.dir}"])
            
    # linker stuff
    SCons.Tool.link.generate(env)
    
    env['LINK']        = 'lnk-arp32'
    env['LINKCOM']     = ['$LINK -cr $SOURCES $_LIBDIRFLAGS $_LIBFLAGS $LINKFLAGS $_ARP32_ENTRY_POINT -o $TARGET $_ARP32_EVE_LCF_FILE -m${TARGET.base}.map',
                          eval_map_file]
    env['LIBDIRPREFIX'] = '-i'
    
    env.Append(LIBPATH = [env['_ARP32_CODE_GEN_TOOL_PATH'] + "/lib"])
    
    # archiver stuff
    
    env['AR']          = 'ar-arp32'
    env['ARFLAGS']     = SCons.Util.CLVar('-@')
    env['ARCMD']       = ''
    env['ARCOM']       = '$AR $ARFLAGS$ARCMD'
    env['ARCOMSTR']    = '$ARCOM'
    env['LIBPREFIX']   = ''
    env['LIBSUFFIX']   = ''
    env['LIBEMITTER']   = libEmitter
       
    env['PREPROCESSCCCOM'] = '$CCCOM -ppc'
    env['PREPROCESSCCCOMSTR'] = '$PREPROCESSCCCOM'
    
    env['BUILDERS']['PreprocessCC'] = Builder(action = Action('$PREPROCESSCCCOM', '$PREPROCESSCCCOMSTR'),
                                              suffix = '.pp',
                                              src_suffix = ['.c'])
    env['BUILDERS']['StaticObject'] = Builder(action = Action('$CCCOM', '$CCCOMSTR'),
                                              suffix = '.obj',
                                              src_suffix = ['.k', '.c'],
                                              source_scanner = SourceFileScanner
                                              )
    action_list = [SCons.Action.Action('$ARCOM', '$ARCOMSTR')]
    slBld = SCons.Builder.Builder(action = action_list,
                                           emitter = '$LIBEMITTER',
                                           prefix = '$LIBPREFIX',
                                           suffix = '$LIBSUFFIX',
                                           src_suffix = '$OBJSUFFIX',
                                           src_builder = 'StaticObject')
    
    env['BUILDERS']['StaticLibrary'] = slBld

    env.AddMethod(FindAllObjects)
    
def exists(env):
    """
    Function        :  exists
    Description     :  
    env             :  
    Returns         :  
    """
    return env.Detect(compilers)
