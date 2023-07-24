"""
Filename                  :  scons_adas_extensions\pclint.py
"""
from SCons.Script import *

import SCons.Tool
import SCons.Tool.cc
import SCons.Tool.link
import SCons.Scanner
import SCons.Util
import re, os.path, string
cplusplus = __import__('SCons.Tool.c++', globals(), locals(), ["SCons.Tool"])
lint_rev  = re.compile(r"^.*Lnt Reviewed\s+--\s+err:\s+(\d+)\s+wrn:\s+(\d+)\s+info:\s+(\d+)\s+note:\s+(\d+).*$", re.M)
lint_open = re.compile(r"^.*Lnt Open\s+--\s+err:\s+(\d+)\s+wrn:\s+(\d+)\s+info:\s+(\d+)\s+note:\s+(\d+).*$", re.M)
misra_rev = re.compile(r"^.*Misra Reviewed\s+--\s+req:\s+(\d+)\s+adv:\s+(\d+).*$", re.M)
misra_open= re.compile(r"^.*Misra Open\s+--\s+req:\s+(\d+)\s+adv:\s+(\d+).*$", re.M)

def emitLint(target, source, env):
    """
    Function            :  emitLint
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    s = str(target[0])
    #print s
    return (target + [s+'.csv', s+'.rev.csv', s+'.rev.vs.txt',s+'.rev.db',s+'.stat.txt'], source + [env['_PCLINT_CONFIG']])

def LintDetails(target, source, env):
    """
    Function            :  LintDetails
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    numLines = 0
    for l in open(str(source[3])).xreadlines(): 
        print l,
        numLines += 1
        if numLines > 300:
            print "More than 300 lines, lint output print aborted."
            break
    open(str(target[0]), "w").write("")

def LintWrapup(target, source, env):
    """
    Function            :  LintWrapup
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    num = [0, 0]
    output = ""
    for src in source:
        s = open(str(src)).read()
        if env.get('PCLINT_VERBOSE', 0):
            print s
        cnt = [0, 0]
        for (r,i) in [(misra_open,0), (lint_open,0), (misra_rev,1), (lint_rev,1)]:
            M = r.search(s)
            if M:
                n = reduce(lambda x, y: x+int(y), M.groups(), 0)
                cnt[i] += n
                num[i] += n
            else:
                output += "Lint Error, no wrap up\n"
        print "Lint: %5d open %5d reviewed    %s" % (cnt[0], cnt[1], str(src.sources[0]))
    output += "Total number of Lint messages: %d open %d reviewed\n" % (num[0], num[1])
    print output,
    open(str(target[0]), "w").write(output)

def LintConfig(target, source, env):
    """
    Function            :  LintConfig
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    f = open(str(target[0]), "w")
    lnt = source[0].get_contents()
    f.write(lnt)
    f.close()

def emitLintConfig(target, source, env):
    """
    Function            :  emitLintConfig
    Description         :  
    target              :  
    source              :  
    env                 :  
    Returns             :  
    """
    source = """
// automatically generated lint configuration wrapper
-i"%(path)s"
-i"%(path)s\lint"
std_%(platform)s.lnt
au_misra2.lnt
-i-
%(additional_options)s
""" % {
        'platform' : env.subst('$PCLINT_PLATFORM'), 
        'path' : env.subst('$_PCLINT_PATH'),
        'additional_options' : env.subst('$PCLINT_ADDITIONAL_OPTIONS'),
    }
    # (target, source)
    return (env.subst('$_PCLINT_CONFIG'), env.Value(source) )

def generate(env):
    """
    Function        :  generate
    Description     :  
    env             :  
    Returns         :  
    """
    """Add Builders and construction variables for gcc to an Environment."""
    
    env['_PCLINT_CONFIG'] = File(env.subst('$PCLINT_CONFIG')).abspath
    env['_PCLINT_PATH'] = Dir(env.subst('$PCLINT_PATH')).abspath
    env.PrependENVPath('PATH', env.subst('"$_PCLINT_PATH"'))

    env['_PCLINTDEFFLAGS'] = '${_defines(PCLINTDEFPREFIX, CPPDEFINES, PCLINTDEFSUFFIX, __env__)}'
    env['_PCLINTINCFLAGS'] = '${_concat(PCLINTINCPREFIX, CPPPATH, PCLINTINCSUFFIX, __env__, RDirs, TARGET, SOURCE)}'
    
    env['PCLINTDEFPREFIX'] = '-d'
    env['PCLINTDEFSUFFIX'] = ''
    env['PCLINTINCPREFIX'] = '-i'
    env['PCLINTINCSUFFIX'] = ''
    env['PCLINT'] = 'lint-nt'
    # lint flag explanations:
    #  +b      put banner to stdout instead of stderr
    #  -zero   force zero exit state even if lint errors occured
    env['PCLINTFLAGS'] = r'+b -zero'
    
    # -zero: force zero exit status, so no termination
    env['PCLINTCOM'] = ['$PCLINT $PCLINTFLAGS -i"$_PCLINT_PATH" "$_PCLINT_CONFIG" -i- $_PCLINTDEFFLAGS $_PCLINTINCFLAGS $SOURCE > ${TARGETS[0]}']
    env['PCLINTCOMSTR'] = '$PCLINTCOM'
    
    env['LINTCONFIGSTR'] = '[py]LintConfig $PCLINT_PLATFORM > $TARGET'
    env['LINTDETAILSTR'] = '[py]LintDetails $SOURCE > $TARGET'
    env['LINTWRAPUPSTR'] = '[py]LintWrapup $SOURCES > $TARGET'
    env['PYTHON'] = "../02_Development_Tools/movpy-0.4.4-2.4-standard/movpy/movpy.exe"
        
    env['LINT2CSVCOM'] = '"$PYTHON" -u ../../05_Testing/06_Test_Tools/lnt_check_review/lnt2csv.py ${TARGETS[0]} ${TARGETS[1]} >NUL'
    env['LINTADDREVIEWINFOCOM'] = '"$PYTHON" -u ../../05_Testing/06_Test_Tools/lnt_check_review/lnt_csv_add_review_info.py ${TARGETS[1]} ${TARGETS[2]} >NUL'
    env['LINTCSV2VSCOM'] = '"$PYTHON" -u ../../05_Testing/06_Test_Tools/lnt_check_review/lnt_csv2vs.py -f${TARGETS[2]} -o${TARGETS[3]} -r >NUL'
    env['LINTCSV2DBCOM'] = '"$PYTHON" -u ../../05_Testing/06_Test_Tools/lnt_check_review/csv2db.py ${TARGETS[2]} ${TARGETS[4]} >NUL'
    env['LINTCALCSTATSCOM'] = '"$PYTHON" -u ../../05_Testing/06_Test_Tools/lnt_check_review/calc_stats.py ${TARGETS[4]} > ${TARGETS[5]}'
    
    env['BUILDERS']['LintConfig'] = Builder(action=SCons.Action.Action(LintConfig, '$LINTCONFIGSTR'),
                                            suffix='.lnt',
                                            emitter=emitLintConfig)
    # -> generate lint configuration for this platform
    env.LintConfig('$_PCLINT_CONFIG')
    env['BUILDERS']['Lint'] = Builder(action=SCons.Action.Action(['$PCLINTCOM','$LINT2CSVCOM','$LINTADDREVIEWINFOCOM','$LINTCSV2VSCOM','$LINTCSV2DBCOM','$LINTCALCSTATSCOM'], 
                                                                 '$PCLINTCOMSTR'),
                                      suffix='.lint',
                                      src_suffix=SCons.Tool.CSuffixes,
                                      source_scanner = SCons.Tool.SourceFileScanner,
                                      emitter=emitLint)
    env['BUILDERS']['LintDetails'] = Builder(action=SCons.Action.Action(LintDetails,'$LINTDETAILSTR'),
                                             suffix='.lint_details')
    env['BUILDERS']['LintWrapup'] = Builder(action=SCons.Action.Action(LintWrapup,'$LINTWRAPUPSTR'),
                                            suffix='.lint_wrapup',
                                            src_suffix='.lint.rev.db')

def exists(env):
    """
    Function        :  exists
    Description     :  
    env             :  
    Returns         :  
    """
    return env.Detect('lint-nt')
