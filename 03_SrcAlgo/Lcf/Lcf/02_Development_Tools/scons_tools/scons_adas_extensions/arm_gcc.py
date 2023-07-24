"""
Filename                  :  scons_adas_extensions\arm_gcc.py
Description               :  SCons builder for generating GCC compiled ARM libraries and out files.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: arm_gcc.py
#
# DESCRIPTION: SCons builder for generating GCC compiled ARM libraries and out files.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/11/08
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:49CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: arm_gcc.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:49CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.14 2016/05/27 11:34:53CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.13 2016/03/31 12:08:31CEST Singh, Vishal (uidj9083) 
# CHANGES:                   updated scons_adas_extensions\arm_gcc.py to use correct header for using updated compiler personality
# CHANGES:                   Revision 1.12 2016/01/21 06:50:25CET Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Fixed rebuilt bug in A8-Only target
# CHANGES:                   Revision 1.11 2015/09/23 16:01:43CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   add keys "_TOOLS" and "_TOOL_ADDONS" to environmental construction dictionary 
# CHANGES:                   in order to map dependencies to ti-tools for the build
# CHANGES:                   - Added comments -  uidg5297 [Sep 23, 2015 4:01:44 PM CEST]
# CHANGES:                   Change Package : 379758:1 http://mks-psad:7002/im/viewissue?selection=379758
# CHANGES:                   Revision 1.10 2015/06/26 05:17:22CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:22 AM CEST]
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

    
def FindAllObjects(self, target):
    """
    Function            :  FindAllObjects
    Description         :  Find all dependent objects for target
    target              :  
    Returns             :  Headers
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
                    lst = item.children(scan=1)
                    _find_sources(lst, hdr, all)

    headers = []
    _find_sources(target, headers, {})
    return headers

def eval_map_file(target, source, env):
    """
    Function            :  eval_map_file
    Description         :  Evaluate map file.
    target              :  Map file
    source              :  Source list
    env                 :  Environment object for target variant.
    Returns             :  None
    """
    map_file = os.path.splitext(str(target[0]))[0] + ".map"
    eval_src = env.get('MAP_EVAL_SRC', [])
    objs = env.FindAllObjects(eval_src)
    if len(objs) > 0:
        f=open(map_file,"r")
        text=f.read()
        ram_size = r"([0-9a-f]+)[ \t]+([0-9a-f]+)[^\n]*("
        items = []
        for obj in objs:
            obj = os.path.split(str(obj))[1]
            items.append("(?:"+obj+")")
        ram_size += "|".join(items)
        items = []
        for s in ["text", "code", "far", "const", "cinit", "bss", "switch", "pinit"]:
            items.append("(?:"+s+")")
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
            print "%8s: %dM %3dk %3d" %( s,
                pdlane_mem[s]/(1024*1024),
                (pdlane_mem[s]/(1024))%1024,
                pdlane_mem[s]%1024)

def libEmitter(target, source, env):
    """
    Function            :  libEmitter
    Description         :  Emitter function for sysbios library.
    target              :  Map file
    source              :  Source list
    env                 :  Environment object for target variant.
    Returns             :  Target and source.
    """
    dir = os.path.dirname(target[0].path)
    dirabs = os.path.dirname(target[0].abspath)
    t = str(target[0])
    tb = os.path.splitext(t)[0]
    cmd = dirabs + '\\' + 'gcc.mri'
    t = dir + '\\' + t
    dirabs = dirabs.replace("\\","/")
    # write targets and sources into cmd
    try:
        os.makedirs(dirabs)
    except OSError, e:
        if e.errno != errno.EEXIST:
            raise
    f = open(cmd, "w")
    f.write("""************************
* CREATE A NEW ARCHIVE *
************************
CREATE %(targetlib)s

************************
* ADD FILES TO ARCHIVE *
************************
""" % {
        'targetlib': t
    })
    for src in source:
        f.write('ADDMOD ' + File(str(src)).abspath + '\n')
    
    f.write('************\n')
    f.write('* FINALIZE *\n')
    f.write('************\n')
    f.write('SAVE\n')
    f.close()
    env['ARCMD'] = cmd
    return target, source

                
def buildCCSPjt(target, source, env):
    """
    Function            :  buildCCSPjt
    Description         :  Build CCS project.
    target              :  out file.
    source              :  source list.
    env                 :  Environment object for target variant.
    Returns             :  None
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
CPUFamily=ARMv7A8
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
        'srcfiletext' : string.join(map(lambda x: 'Source="'+Dir(".").File(x).abspath+'"', srcs),"\n"),
        'SearchPath' : Dir(".").abspath,
        'searchpathtext' : string.join(map(lambda x: 'Path="'+Dir(x).abspath+'"', search_path),"\n"),
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
                    'srcfiletext' : string.join(map(lambda x: 'Source="'+Dir(".").File(x).abspath+'"', srcs),"\n"),
                    'SearchPath' : Dir(".").abspath,
                    'buildtarget' : buildtarget[vi].abspath,
                    'ccsscons' : env.subst(ccsscons),
                    'variant' : variant, 
                    'donotbuildsrc' : string.join(map(lambda x: '["'+Dir(".").File(x).abspath+'" Settings: "%s"]\nExcludeFromBuild=true\n' % (variant), srcs), "\n"),
                    'searchpathtext' : env.subst("$_TCONFINCFLAGS"),
                })  
    f.close()
    
def xsEmitter(target, source, env):
    """
    Function            :  xsEmitter
    Description         :  Generate sysbios library.
    target              :  Map file, link file, sysbios library.
    source              :  Source list
    env                 :  Environment object for target variant.
    Returns             :  Target and source.
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
    build_dir = os.path.dirname(Dir(None).path)
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
    if env['XDC_PLATFORM'] == 'vme_evm_hil_ca8' :
        sysbios_lib = "\configPkg\src\sysbios\sysbios.aa8fg"        
    elif env['XDC_PLATFORM'] == 'vh28_evm_hil_ca15' :
        sysbios_lib = "\configPkg\src\sysbios\sysbios.aa15fg"

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
    if env['XDC_PLATFORM'] == 'vme_evm_hil_ca8' :
        return additional_source     
    elif env['XDC_PLATFORM'] == 'vh28_evm_hil_ca15' :
        head, tail = source.split("vh28")
        add_source = "vh28\generic\os\sysbios_arm_default.cfg"
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
    
    env['_ARM_GCC_CODE_GEN_TOOL_PATH'] = Dir(env.subst('$ARM_GCC_CODE_GEN_TOOL_PATH')).abspath
    dsp_bios_path = env.subst('$DSP_BIOS_PATH')
    xdctools_path = env.subst('$DSP_XDCTOOLS_PATH')
    if dsp_bios_path:
        env['_DSP_BIOS_PATH'] = Dir(dsp_bios_path).abspath
    if xdctools_path:
        env['_DSP_XDCTOOLS_PATH'] = Dir(xdctools_path).abspath

    env['ARM_LCF_FILE'] = ''
    env['ARM_LCF_FILE_PREFIX'] = '-Wl,-T"'
    env['ARM_LCF_FILE_SUFFIX'] = '"'
    env['_ARM_LCF_FILE'] = '${_concat(ARM_LCF_FILE_PREFIX, ARM_LCF_FILE, ARM_LCF_FILE_SUFFIX, __env__)}'
    
    env.PrependENVPath('PATH', env.subst("$_ARM_GCC_CODE_GEN_TOOL_PATH/bin"))
    if xdctools_path:
        env.PrependENVPath('PATH', env.subst('"$_DSP_XDCTOOLS_PATH"'))
    
    
    static_obj, shared_obj = SCons.Tool.createObjBuilders(env)
    asm_suffixes = ['.asm', '.s']
    for suffix in asm_suffixes:
        static_obj.add_action(suffix, SCons.Defaults.CAction)
        shared_obj.add_action(suffix, SCons.Defaults.ShCAction)
        static_obj.add_emitter(suffix, SCons.Defaults.StaticObjectEmitter)
        shared_obj.add_emitter(suffix, SCons.Defaults.SharedObjectEmitter)
        
    # # check for which core to build
    # env.SetDefault(ARM_CPU_VERSION = '7A8')
    # if "7A15" in env.subst('$ARM_CPU_VERSION'):
      # env['ARM_CPU_VERSION'] = '7A15'

    env['CC'] = 'arm-none-eabi-gcc'
    env['CCCOM'] = '$CC $CFLAGS $CCFLAGS $_CCCOMCOM ${SOURCES} -Drestrict=__restrict__ -o ${TARGETS}'
    env['CCCOMSTR'] = '\n[$SOURCES]\n$CC $CFLAGS $CCFLAGS \n$CCCOM'
    env['CXX'] = '$CC'
    env['CXXCOM'] = '$CXX $CFLAGS $CCFLAGS $_CCCOMCOM ${SOURCES} -Drestrict=__restrict__ -o ${TARGETS}'
    env['CXXCOMSTR'] = '[${SOURCE.abspath}] \n$CC $CFLAGS $CCFLAGS \n$CXXCOM'
    env['OBJSUFFIX'] = '.o'

    # add include paths
    env.Append(CPPPATH=[env["_ARM_GCC_CODE_GEN_TOOL_PATH"] + "/arm-none-eabi/include"])
    env.Append(CPPPATH=[env["_ARM_GCC_CODE_GEN_TOOL_PATH"] + "/lib/gcc/arm-none-eabi/4.7.3/include"])	

    # linker stuff
    SCons.Tool.link.generate(env)
    
    env['LINK']        = '$CC'
    env['LINKCOM']     = ['$LINK $LINKFLAGS -Wl,-Map,"${TARGET.base}.map" $_LIBDIRFLAGS -o"$TARGET" $SOURCES $_ARM_LCF_FILE -Wl,--start-group $_LIBFLAGS -Wl,--end-group',
                          eval_map_file]
    env['LIBDIRPREFIX']= '-L"'
    env['LIBDIRSUFFIX']= '"'
    
    #env.Append(LIBPATH=["$ARM_GCC_CODE_GEN_TOOL_PATH/lib"])
    #env['LIBS']=[]
    
    # archiver stuff
    env['AR']          = 'arm-none-eabi-ar'
    env['ARFLAGS']     = '-M < '
    env['ARCMD']       = ''
    env['ARCOM']       = '$AR $ARFLAGS $ARCMD'
    env['ARCOMSTR']    = '$ARCOM'
    env['LIBPREFIX']   = ''
    env['LIBSUFFIX']   = ''
    env['LIBEMITTER']   = libEmitter
    
    # xs
    env['XS']               = 'xs'
    # env['XDC_PACKAGE_PATH'] = []
    env['XS_COMP_OPTIONS']  = ''
    env['XSCOM']            = ['$XS --xdcpath="$XDC_PACKAGE_PATH" xdc.tools.configuro -o ${TARGET.dir} -t $XDC_TARGET -p $XDC_PLATFORM -r $variant -c $_ARM_GCC_CODE_GEN_TOOL_PATH $XS_COMP_OPTIONS $SOURCE']
    env['XSCOMSTR']         = '$XSCOM'
    env['XSSUFFIX']         = '.cfg'
    env['XDC_TARGET']       = '$XDC_TARGET'
    env['XDC_PLATFORM']     = '$XDC_PLATFORM'
    # env['XDC_PACKAGE_PATH'] = '$XDC_PACKAGE_PATH'
    
    env['_TOOLS'] = [env.subst("$_ARM_GCC_CODE_GEN_TOOL_PATH/bin/$CC") + ".exe"]
    env['_TOOL_ADDONS'] = []
    if xdctools_path:
        env['_TOOLS'] +=[env.subst('$_DSP_XDCTOOLS_PATH/$XS') + ".exe"]
        env['_TOOLS'].append(env.subst('$_DSP_XDCTOOLS_PATH/$XS') + '.exe')
        env['_TOOL_ADDONS'].append(env.subst('$_DSP_BIOS_PATH'))
        env['_TOOL_ADDONS'].extend(env.subst('$XDC_PACKAGE_PATH').split(';'))
        env['_TOOL_ADDONS'] = filter(lambda path : path!='', env['_TOOL_ADDONS'])

    xsBld = Builder(action = SCons.Action.Action('$XSCOM', '$XSCOMSTR'),
                    emitter = xsEmitter,
                    src_suffix = '$XSSUFFIX')
    env['BUILDERS']['XsBuilder'] = xsBld

    # Code Composer Project stuff
    ccspjtBld = Builder(action=SCons.Action.Action(buildCCSPjt, "Building ccs project file '$TARGETS'"),
                        suffix='pjt')
    env['BUILDERS']['CCSProject'] = ccspjtBld
    
    # Pre processor stuff
    env['BUILDERS']['PreprocessCC'] = Builder(action="$CCCOM -C -E", 
                                              suffix='.pp', 
                                              src_suffix=['.c'],
                                              source_scanner = CScanner)
    env['BUILDERS']['PreprocessCXX']= Builder(action="$CXXCOM -C -E", 
                                              suffix='.pp', 
                                              src_suffix=['.cpp', '.cxx'])
    
    action_list=[SCons.Action.Action('$ARCOM', '$ARCOMSTR')]
    slBld = SCons.Builder.Builder(action = action_list,
                                  emitter = '$LIBEMITTER',
                                  prefix = '$LIBPREFIX',
                                  suffix = '$LIBSUFFIX',
                                  src_suffix = '$OBJSUFFIX',
                                  src_builder = 'StaticObject')
    
    env['BUILDERS']['StaticLibrary'] = slBld
    env['BUILDERS']['Library'] = slBld
                                              
    env.AddMethod(FindAllObjects)
   
    
def exists(env):
    """
    Function        :  exists
    Description     :  
    env             :  
    Returns         :  
    """
    return env.Detect(compilers)
