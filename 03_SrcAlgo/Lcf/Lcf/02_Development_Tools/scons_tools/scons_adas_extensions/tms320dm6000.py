"""
Filename                  :  scons_adas_extensions\tms320dm6000.py
Description               :  Script used to setup DSP build environment. It specifies the TI DSP compiler used, include directories and library directories.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: tms320dm6000.py
#
# DESCRIPTION: Script used to setup DSP build environment. It specifies the TI DSP   
#              compiler used, include directories and library directories.
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
# CHANGES:                   $Log: tms320dm6000.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:04:00CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.21 2016/05/27 12:57:23CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.20 2015/09/23 16:04:14CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add keys "_TOOLS" and "_TOOL_ADDONS" to environmental construction dictionary 
# CHANGES:                   in order to map dependencies to ti-tools for the build
# CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:04:14 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.19 2015/06/26 05:17:30CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:30 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

from SCons.Script import *

import SCons.Tool
import SCons.Tool.cc
import SCons.Tool.link
import SCons.Scanner
import SCons.Util
import re, os.path, string, errno
cplusplus = __import__('SCons.Tool.cpp', globals(), locals(), ["SCons.Tool"])

def tconfScannerFunc(node, env, path):
    """
    Function          :  tconfScannerFunc
    Description       :  
    node              :  
    env               :  
    path              :  
    Returns           :  
    """
    lookout = []
    lookout.extend(env.subst(env['TCONFPATH']))
    lookout.append(str(node.rfile().dir))
    includes = re.findall("utils.importFile\\s*\\(\\s*['\"]([^']+)['\"]\\s*\\)", node.get_contents())
    #print includes, lookout
    result = []
    for incFile in includes:
        dep = env.FindFile(incFile,lookout)
        if dep:
            result.append(dep)
    #print "tconf scanner result: ", str(node), "<-", map(str, result)
    return result

tconfScanner = SCons.Scanner.Base(tconfScannerFunc,
                                  name = "TconfScanner", 
                                  node_class = SCons.Node.FS.File,
                                  node_factory = SCons.Node.FS.File,
                                  recursive = 1)

def tconfEmitter(target, source, env):
    """
    Function            :  tconfEmitter
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    p = os.path.dirname(str(target[0]))
    b = os.path.splitext(os.path.basename(str(source[0])))[0]
    if p != "":
        pref = p + "/" + b
    else:
        pref = b
    target = map(env.File, [
        pref + ".cdb",
        pref + "cfg.cmd",
        pref + "cfg_c.c",
        pref + "cfg.s62",
        pref + "cfg.h62",
        pref + "cfg.h",
        #pref + "idedummy.tcf"])
        ])
    return target, source
    
def _tconfIncFlags(env):
    """
    Function        :  _tconfIncFlags
    Description     :  
    env             :  
    Returns         :  
    """
    res = "-Dconfig.importPath="
    for p in env.subst(env['TCONFPATH']):
        p = Dir(p).abspath
        p.replace("\\", "/")
        res += p + ";"
    return res

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
    cmd = dirabs + '\\' + 'ar6x.cmd'
    t = dir + '\\' + t
    dirabs = dirabs.replace("\\", "/")
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
                #print obj, segment, M.group(1), M.group(2)
            #print pdlane_mem
        print "Memory usage evaluation with focus on %s:" % (" ".join(map(str, eval_src)))
        for s in pdlane_mem.keys():
            print "%8s: %dM %3dk %3d" % (s,
                pdlane_mem[s] / (1024 * 1024),
                (pdlane_mem[s] / (1024)) % 1024,
                pdlane_mem[s] % 1024)

def buildCCSPjt(target, source, env):
    """
    Function            :  buildCCSPjt
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    srcs = env.get('srcs', [])
    buildtarget = env['buildtarget']
    if not type(buildtarget) in [type([]), type(())]:
        buildtarget = [buildtarget]
    variants = env['variants']
    if not type(variants) in [type([]), type(())]:
        variants = [variants]
    assert len(variants) == len(buildtarget), "lengths of buildtarget and variants must be the same"
    ccsscons = env['CCSSCONS']
    search_path = env['search_path']
    f = open(str(target[0]), "w")
    f.write("""; Code Composer Project File, Version 2.0 (do not modify or remove this line)

[Project Settings]
ProjectDir="%(ProjectDir)s"
ProjectType=External
CPUFamily=TMS320C64XX
Tool="Compiler"
Tool="CustomBuilder"
Tool="DspBiosBuilder"
Tool="Linker"
%(configtext)s

[External Makefile]
ExtMakefile="%(SConstructRelPath)s"

[Search Path]
Path="%(SearchPath)s"
%(searchpathtext)s

[Source Files]
Source="%(SConstructRelPath)s"
%(srcfiletext)s
""" % {
        'ProjectDir' : os.path.dirname(target[0].abspath),
        'SConstructRelPath' : File("./SConstruct").abspath,
        'srcfiletext' : string.join(map(lambda x: 'Source="' + Dir(".").File(x).abspath + '"', srcs),"\n"),
        'SearchPath' : Dir(".").abspath,
        'searchpathtext' : string.join(map(lambda x: 'Path="' + Dir(x).abspath + '"', search_path),"\n"),
        'configtext' : string.join(map(lambda x: 'Config="' + x + '"', variants), "\n"),
    })
    for vi, variant in enumerate(variants):
        f.write("""
["Compiler" Settings: "%(variant)s"]
Options=hopefullyunused

["Linker" Settings: "%(variant)s"]
Options=hopefullyunused

["DspBiosBuilder" Settings: "%(variant)s"]
Options=%(searchpathtext)s

["%(SConstructRelPath)s" Settings: "%(variant)s"]
UseCustomBuild=true
CustomBuildCmd=%(ccsscons)s "%(buildtarget)s"
CustomBuildOutput="%(buildtarget)s"
CustomCleanCmd=%(ccsscons)s -c "%(buildtarget)s" 
Run=Always

%(donotbuildsrc)s
""" % {
                    'ProjectDir' : os.path.dirname(target[0].abspath),
                    'SConstructRelPath' : File("./SConstruct").abspath,
                    'srcfiletext' : string.join(map(lambda x: 'Source="' + Dir(".").File(x).abspath + '"', srcs),"\n"),
                    'SearchPath' : Dir(".").abspath,
                    'buildtarget' : buildtarget[vi].abspath,
                    'ccsscons' : env.subst(ccsscons),
                    'variant' : variant, 
                    'donotbuildsrc' : string.join(map(lambda x: '["' + Dir(".").File(x).abspath + '" Settings: "%s"]\nExcludeFromBuild=true\n' % (variant), srcs), "\n"),
                    'searchpathtext' : env.subst("$_TCONFINCFLAGS"),
                })  
    f.close()

def xsEmitter(target, source, env):
    """
    Function            :  xsEmitter
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    target_dir = os.path.dirname(target[0].path)
    # add generated linker file, compiler option file and sysbios lib as target  
    linker_file = "\configPkg\linker.cmd"
    option_file = "\configPkg\compiler.opt"
    # note: new version of sysbios uses different file extension
    sysbios_lib = getSysbiosLibrary(env)

    # Remove the first target (as there is no such target)
    temp = target[0]
    target.remove(temp)
    target.append(target_dir + linker_file)
    target.append(target_dir + option_file)
    target.append(target_dir + sysbios_lib)
    # note: check for additional source to add for building sysbios library.
    additional_source = getAdditionalSource(str(source[0]), env)
    if additional_source != None:
		source.append(additional_source)

    # Explicit dependencies for target
    env.Depends(target, source)
    return target, source
    
def Xs(self, target, source, **kw):
    """
    Function            :  Xs
    Description         :  
    target              :  
    source              :  
    **kw                :  
    Returns             :  
    """
    build_dir = os.path.dirname(Dir(target).path)
    linker_file = "\configPkg\linker.cmd"
    option_file = "\configPkg\compiler.opt"
    # note: new version of sysbios uses different file extension
    sysbios_lib = getSysbiosLibrary(self)	

    # target will be rebuilt if there is any change in the source    
    self.XsBuilder(target, source, **kw)
	
    generated_target = []
    generated_target.append(Entry(target))
    generated_target.append(build_dir + linker_file)
    generated_target.append(build_dir + option_file)
    generated_target.append(build_dir + sysbios_lib)
    return generated_target

def getSysbiosLibrary(env):
    """
    Function        :  getSysbiosLibrary
    Description     :  
    env             :  
    Returns         :  
    """
    # note: new version of sysbios uses different file extension
    if env['XDC_PLATFORM'] == 'vme_evm_hil_c674x' :
        sysbios_lib = "\configPkg\src\sysbios\sysbios.ae674"        
    elif env['XDC_PLATFORM'] == 'vh28_evm_hil_c66xx' :
        sysbios_lib = "\configPkg\src\sysbios\sysbios.ae66"

    return sysbios_lib
    
def getAdditionalSource(source, env):
    """
    Function           :  getAdditionalSource
    Description        :  
    source             :  
    env                :  
    Returns            :  
    """
    additional_source = None
    if env['XDC_PLATFORM'] == 'vme_evm_hil_c674x' :
        return additional_source     
    elif env['XDC_PLATFORM'] == 'vh28_evm_hil_c66xx' :
        head, tail = source.split("vh28")
        add_source = "vh28\generic\os\sysbios_c6000_default.cfg"
        source_dir = head + add_source
        if File(source_dir).exists:
            additional_source = File(source_dir).abspath

    return additional_source	
	
def generate(env):
    """
    Function        :  generate
    Description     :  
    env             :  
    Returns         :  
    """
    """Add Builders and construction variables for gcc to an Environment."""
    
    env.AddMethod(Xs)
    
    # compiler stuff
    SCons.Tool.cc.generate(env)
    cplusplus.generate(env)
    
    # this environment variable is used to determine whether building for ecu or simulation
    env['_BUILD_TARGET'] = env.subst('$BUILD_TARGET')
    
    env['_C6000_CODE_GEN_TOOL_PATH'] = Dir(env.subst('$C6000_CODE_GEN_TOOL_PATH')).abspath
    
    dsp_bios_path = env.subst('$DSP_BIOS_PATH')
    xdctools_path = env.subst('$DSP_XDCTOOLS_PATH')
    if dsp_bios_path:
        env['_DSP_BIOS_PATH'] = Dir(dsp_bios_path).abspath
    if xdctools_path:
        env['_DSP_XDCTOOLS_PATH'] = Dir(xdctools_path).abspath
    
    env['DSP_LCF_FILE'] = ''
    env['DSP_LCF_FILE_PREFIX'] = "-l"
    env['DSP_LCF_FILE_SUFFIX'] = ""
    env['_DSP_LCF_FILE'] = '${_concat(DSP_LCF_FILE_PREFIX, DSP_LCF_FILE, DSP_LCF_FILE_SUFFIX, __env__)}'
    
    env['CMD_OPT_FILE'] = ''
    env['CMD_OPT_FILE_PREFIX'] = "--cmd_file="
    env['CMD_OPT_FILE_SUFFIX'] = ""
    env['_CMD_OPT_FILE'] = '${_concat(CMD_OPT_FILE_PREFIX, CMD_OPT_FILE, CMD_OPT_FILE_SUFFIX, __env__)}'
    
    env.PrependENVPath('PATH', env.subst('"$_C6000_CODE_GEN_TOOL_PATH/bin"'))
    if xdctools_path:
        env.PrependENVPath('PATH', env.subst('"$_DSP_XDCTOOLS_PATH"'))

    static_obj, shared_obj = SCons.Tool.createObjBuilders(env)
    asm_suffixes = ['.s62', '.s64', '.s64P', '.asm']
    for suffix in asm_suffixes:
        static_obj.add_action(suffix, SCons.Defaults.CAction)
        shared_obj.add_action(suffix, SCons.Defaults.ShCAction)
        static_obj.add_emitter(suffix, SCons.Defaults.StaticObjectEmitter)
        shared_obj.add_emitter(suffix, SCons.Defaults.SharedObjectEmitter)

    env['CC'] = 'cl6x'
    env['CCCOM'] = '$CC $CFLAGS $CCFLAGS $_CCCOMCOM ${SOURCES} $_CMD_OPT_FILE -fb${TARGET.dir} -fs${TARGET.dir} -ff${TARGET.dir} -fr${TARGET.dir} -ft${TARGET.dir}'
    env['CCCOMSTR'] = '\n[$SOURCES]\n$CCCOM'
    env['CXX'] = '$CC'
    env['CXXCOM'] = '$CXX $CFLAGS $CCFLAGS $_CCCOMCOM --cpp_file=${SOURCES} $_CMD_OPT_FILE -fb${TARGET.dir} -fs${TARGET.dir} -ff${TARGET.dir} -fr${TARGET.dir} -ft${TARGET.dir}'
    env['CXXCOMSTR'] = '[${SOURCE.abspath}] $CXXCOM'
    env['OBJSUFFIX'] = '.obj'
    
    # env.SetDefault(DSP_CPU_VERSION = '6400+')
    # env.SetDefault(DSP_ABI = 'coffabi')
    # #env.Append(CCFLAGS=["-mv$DSP_CPU_VERSION -abi=$DSP_ABI"])
    # env.Append(CCFLAGS = ["-mv$DSP_CPU_VERSION"])
    # if env['DSP_CPU_VERSION'] == "6400+":
        # env.Append(CCFLAGS = ["--c64p_l1d_workaround=on"])
    
    # add include paths
    env.Append(CPPPATH = [env['_C6000_CODE_GEN_TOOL_PATH'] + "/include"])
    # add include path from DSP_BIOS
    if dsp_bios_path:
        env.Append(CPPPATH = env['_DSP_BIOS_PATH'] + "/packages")
    # add include path from XDC_TOOLS
    if xdctools_path:
        env.Append(CPPPATH = env['_DSP_XDCTOOLS_PATH'] + "/packages")
    
    # linker stuff
    SCons.Tool.link.generate(env)
    
    env['LINK']        = '$CC'
    env['LINKCOM']     = ['$LINK -z -m${TARGET.base}.map -o $TARGET $LINKFLAGS $_LIBDIRFLAGS $_DSP_LCF_FILE  $_LIBFLAGS $SOURCES',
                          eval_map_file]
    env['LIBDIRPREFIX'] = '-i'
    
    env.Append(LIBPATH = [env['_C6000_CODE_GEN_TOOL_PATH'] + "/lib"])
    
    # archiver stuff
    
    env['AR']          = 'ar6x'
    env['ARFLAGS']     = SCons.Util.CLVar('-@')
    env['ARCMD']       = ''
    env['ARCOM']       = '$AR $ARFLAGS$ARCMD'
    env['ARCOMSTR']    = '$ARCOM'
    env['LIBPREFIX']   = ''
    env['LIBSUFFIX']   = ''
    env['LIBEMITTER']  = libEmitter

    # xs
    env['XS']               = 'xs'
    # env['XDC_PACKAGE_PATH'] = []
    env['XS_COMP_OPTIONS']  = ''
    env['XSCOM']            = ['$XS --xdcpath="$XDC_PACKAGE_PATH" xdc.tools.configuro -o ${TARGET.dir} -t $XDC_TARGET -p $XDC_PLATFORM -r $variant -c $_C6000_CODE_GEN_TOOL_PATH $XS_COMP_OPTIONS $SOURCE']
    env['XSCOMSTR']         = '$XSCOM'
    env['XSSUFFIX']         = '.cfg'
    env['XDC_TARGET']       = '$XDC_TARGET'
    env['XDC_PLATFORM']     = '$XDC_PLATFORM'
    # env['XDC_PACKAGE_PATH'] = '$XDC_PACKAGE_PATH'
    
    # tconf according to spru007h.pdf
    env['TCONF']           = 'tconf'
    env['TCONFPATH']       = []
    env['_tconfIncFlags']  = _tconfIncFlags
    env['_TCONFINCFLAGS']  = '$( ${_tconfIncFlags(__env__)} $)'
    env['_TCONFOUTFLAGS']  = '-Dconfig.programName=${TARGETS[0].dir}/${SOURCES[0].filebase}'
    env['TCONFCOM']        = ['$TCONF $_TCONFINCFLAGS $_TCONFOUTFLAGS -Dconfig._${DSP_CPU_VERSION[:2]}_ $SOURCES',
                              Chmod('${TARGETS[0]}', 0755),
                              #SCons.Action.Action(generateGuiTcf)]
                              ]
    env['TCONFCOMSTR']     = '$TCONFCOM'
   
    env['TCONFSUFFIX']     = '.tcf'
    
    env['_TOOLS'] = [env.subst('$_C6000_CODE_GEN_TOOL_PATH/bin/$CC') + '.exe']
    env['_TOOL_ADDONS'] = []
    if xdctools_path:
        env['_TOOLS'].append(env.subst('$_DSP_XDCTOOLS_PATH/$XS') + '.exe')
        env['_TOOL_ADDONS'].append(env.subst('$_DSP_BIOS_PATH'))
        env['_TOOL_ADDONS'].extend(env.subst('$XDC_PACKAGE_PATH').split(';'))
        env['_TOOL_ADDONS'] = filter(lambda path : path!='', env['_TOOL_ADDONS'])
        
        
    tconfBld = Builder(action = SCons.Action.Action('$TCONFCOM', '$TCONFCOMSTR'),
                       emitter = tconfEmitter,
                       src_suffix = '$TCONFSUFFIX',
                       source_scanner = tconfScanner)
    ccspjtBld = Builder(action = SCons.Action.Action(buildCCSPjt, "Building ccs project file '$TARGETS'"),
                        suffix = 'pjt')
    xsBld = Builder(action = SCons.Action.Action('$XSCOM', '$XSCOMSTR'),
                    emitter = xsEmitter,
                    src_suffix = '$XSSUFFIX')

    env['BUILDERS']['Tconf'] = tconfBld
    env['BUILDERS']['CCSProject'] = ccspjtBld
    env['BUILDERS']['XsBuilder'] = xsBld
    
    env['PREPROCESSCCCOM'] = '$CCCOM -ppc --pp_directory=${TARGET.dir}'
    env['PREPROCESSCCCOMSTR'] = '$PREPROCESSCCCOM'
    env['PREPROCESSCXXCOM'] = '$CXXCOM -ppc --pp_directory=${TARGET.dir}'
    env['PREPROCESSCXXCOMSTR'] = '$PREPROCESSCXXCOM'
    
    env['BUILDERS']['PreprocessCC'] = Builder(action = Action('$PREPROCESSCCCOM', '$PREPROCESSCCCOMSTR'),
                                              suffix = '.pp',
                                              src_suffix = ['.c'],
                                              source_scanner = CScanner)
    env['BUILDERS']['PreprocessCXX'] = Builder(action = Action('$PREPROCESSCXXCOM', '$PREPROCESSCXXCOMSTR'),
                                              suffix = '.pp',
                                              src_suffix = ['.cpp', '.cxx'])
    # new StaticLibrary builder based on command file
    # slBld = Builder(action=SCons.Action.Action('$ARCOM', '$ARCOMSTR'),
                       # src_suffix='.obj',
                       # emitter=slEmitter)
    action_list = [SCons.Action.Action('$ARCOM', '$ARCOMSTR')]
    slBld = SCons.Builder.Builder(action = action_list,
                                           emitter = '$LIBEMITTER',
                                           prefix = '$LIBPREFIX',
                                           suffix = '$LIBSUFFIX',
                                           src_suffix = '$OBJSUFFIX',
                                           src_builder = 'StaticObject')
    
    env['BUILDERS']['StaticLibrary'] = slBld
    #env['BUILDERS']['Library'] = slBld

    env.AddMethod(FindAllObjects)
    
def exists(env):
    """
    Function        :  exists
    Description     :  
    env             :  
    Returns         :  
    """
    return env.Detect(compilers)
