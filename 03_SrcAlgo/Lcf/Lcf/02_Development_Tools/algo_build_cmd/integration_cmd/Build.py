#!/usr/bin/env python
import xml.etree.cElementTree as et
import info
import os
from optparse import OptionParser
import xml.etree.ElementTree as ET
import shlex, subprocess
import timeit
import datetime

def LogFunc(x):
    print(x)

class component(object):
    def __init__(self, name):
        self.name = cname
        self.workspace=""
class ttarget(component):
    def __init__(self, name, filter, desc, execute, sconstruct_dir, attrib,build_log_dir=None,vcproj=None):
        self.name = name
        self.filter = filter
        self.desc = desc
        self.execute = execute
        self.sconstruct_dir = sconstruct_dir
        self.attrib = attrib
        self.build_log_dir = build_log_dir
        self.vcproj = vcproj

os.chdir(os.path.dirname(os.path.realpath(__file__)))    
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD)
MainFile="./04_Engineering/02_Development_Tools/algo_build_cmd/integration_cmd/make_all_tmp.xml"
MainFile = os.path.abspath(MainFile)
#file = os.path.abspath(file)        
LOC_parser = OptionParser()
Email_Address = None
Components = None
target = None
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0

LOC_parser.add_option("-e", "--email", dest="email_list",help="Communication mail", metavar="email address")
LOC_parser.add_option("-c", "--components", dest="__components__",help="__components__", metavar="list of components")
LOC_parser.add_option("-t", "--target", dest="target",help="target", metavar="FILE")
LOC_parser.add_option("-f", "--filter", dest="vfilter",help="filter", metavar="FILE")
LOC_parser.add_option("-r", action="store_true", dest="rebuild",default=False)
(options, args) = LOC_parser.parse_args()
TargetsToBuild = []
#print(options, args)
Stand_Alone = "STD_ON"
#print(options.__dict__)
if options.__dict__['email_list'] and Stand_Alone=="STD_ON":
    Email_Address = options.__dict__['email_list']
else:
    Email_Address = info.MyConf.default_email

if (options.__dict__['__components__'] != None) and (Stand_Alone=="STD_ON"):
    Components = options.__dict__['__components__']
    Build_ALL = "False"
else:
    print("Please use the -c option in order to determine components")
    print("All Components will be Considered...  ")
    Build_ALL = "True"
if options.__dict__['target'] and Stand_Alone=="STD_ON":
    target = options.__dict__['target']
else:
    target = "release"
    #exit(0)        
if options.__dict__['vfilter'] and Stand_Alone=="STD_ON":
    vfilter = options.__dict__['vfilter']
else:
    vfilter = "ecu,sim,vis,svis"
#print("Rebuild",options.rebuild)    
if options.rebuild and Stand_Alone=="STD_ON":
    rebuild = " -r "
else:
    rebuild = ""
def dump(obj):
   print("#"*30)
   for attr in dir(obj):
       if hasattr( obj, attr ):
           if attr != "__doc__" and attr != "__init__" and attr != "__module__" and not("_" in attr):
               print("-"*30)
               print( "obj.%s = %s" % (attr, getattr(obj, attr)))
               print("-"*30)

def PrintTitel(text):
    M = 60
    L = len(text)
    N = M - L
    T = N/2
    print("*"*M)
    print("*"*T+" "*L+"*"*T)
    print("*"*T+text+"*"*T)
    print("*"*T+" "*L+"*"*T)
    print("*"*M)
def PrintList(vlist, Text):
    PrintTitel(Text)
    n =1
    for m in vlist:
        print(str(n) +": "+ str(m.name))
        n = n +1
        
#return the make.xml files for the determined components 
def GetMakeFiles(inComps, All="False"):
    ret = []
   
    conf = ET.Element("BuildConfig", encoding="utf-8")
    
    tree = ET.parse(MainFile)
    root = tree.getroot()
    COMPs = root.findall("Component")
     
    C = 0
    for Comp in COMPs :
        CMPName = Comp.get('name')
        SCMPName = Comp.get('sname')
        CMPBuild = Comp.get('build')
        C = 0
        if inComps:
            for inComp in inComps:
                #print(inComp)
                if ((inComp  in SCMPName and CMPBuild == "STD_ON")or All == "True" ) and C == 0:
                    for BuildCfgFile in Comp.getiterator('BuildCfgFile'):
                        if BuildCfgFile.attrib["dep"] != None:
                            t = ET.SubElement(conf, BuildCfgFile.tag, file=BuildCfgFile.attrib["file"], dep=BuildCfgFile.attrib["dep"])
                            ret.append(BuildCfgFile.attrib["file"])
                        else:
                            t = ET.SubElement(conf, BuildCfgFile.tag, file=BuildCfgFile.attrib["file"])
                            ret.append(BuildCfgFile.attrib["file"])
                    C = C + 1
                else:
                    pass
        else:
            if ( All == "True" and CMPBuild == "STD_ON") and C == 0:
                for BuildCfgFile in Comp.getiterator('BuildCfgFile'):
                    if BuildCfgFile.attrib["dep"] != None:
                        t = ET.SubElement(conf, BuildCfgFile.tag, file=BuildCfgFile.attrib["file"], dep=BuildCfgFile.attrib["dep"])
                        ret.append(BuildCfgFile.attrib["file"])
                    else:
                        t = ET.SubElement(conf, BuildCfgFile.tag, file=BuildCfgFile.attrib["file"])
                        ret.append(BuildCfgFile.attrib["file"])
                C = C + 1
            else:
                pass            
    return(ret)

    #print(files)
def parse(files , targets):
    global TargetsToBuild
    t = ".\\04_Engineering\\03_Workspace\\algo"
    for MainFile in files:
        MainFile = os.path.join(WD+t, MainFile)
        print(MainFile)
        #MainFile = os.path.abspath(MainFile)
        tree = et.parse(MainFile)
        #dump(tree)
        root = tree.getroot()
        '''COMPs = tree.findall("BuildComponentCfg")
        print(1)
        for cmp in COMPs:'''
        trgs = root.findall("Build")
        #print(2)
        for trg in trgs:
            #print(3)
            target = ttarget(trg.get('name'), trg.get('filter'),trg.get('desc'),trg.get('execute'),trg.get('sconstruct_dir'),trg.get('attrib'),trg.get('build_log_dir'),trg.get('vcproj'))
            target.cname = root.get('Component')
            target.workspace = os.path.dirname(MainFile)
            if target.filter in targets:
                #dump(target)
                TargetsToBuild.append(target)
def Build():
    global target
    global rebuild
    ltarget=target.split(",")
    OkList=[]
    NokList=[]
    UnknownList=[]
    txt = "%s targets to be built ..."  %len(TargetsToBuild)
    PrintList(TargetsToBuild, txt)
    for vTarget in TargetsToBuild:
        if ltarget:
            for t in ltarget:
                x="_"+t
                print("-"*60)
                print("Building Target %s" %(vTarget.name+x))
                if vTarget.execute == "vcbuild":
                    TAR = "%s" %(t)
                    Build_Command =  "%s %s %s %s" % (vTarget.execute,vTarget.vcproj,vTarget.attrib, TAR)
                else:    
                    Build_Command =  "%s %s%s %s " % (vTarget.execute,vTarget.name,x,vTarget.attrib)
                print(Build_Command)
                
                proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=vTarget.workspace)
                stdout_str, stderr_str = proc.communicate()
                #print(stdout_str, stderr_str)
                if stdout_str != None :
                    fo.write(stdout_str) 
                if stderr_str != None :
                    fo.write(stderr_str) 
                if "Build FAILED" in stdout_str:
                    print("NOK ...")
                    NokList.append(vTarget.name+x)
                    pass
                elif "Build succeeded" in stdout_str or " - 0 error(s)," in stdout_str:
                    print("OK ...")
                    OkList.append(vTarget.name+x)
                    pass
                else:
                    print(stdout_str)
                    UnknownList.append(vTarget.name+x)

                if stderr_str:
                    print(stderr_str)

        else:
            print("-"*60)
            print("Building Target %s" %(vTarget.name))
            Build_Command =  "%s %s %s " % (vTarget.execute,vTarget.name,vTarget.attrib)
            print(Build_Command)
            proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=vTarget.workspace)
            stdout_str, stderr_str = proc.communicate()
            if stdout_str:
                #print(stdout_str)
                pass
            if stderr_str:
                print(stderr_str)
    print("#"*30)            
    print("#"*30)            
    if   OkList:
        for x in   OkList: print(x+"-"*(30-len(x))+"> OK+++")      
    if   NokList:
        for x in   NokList: print(x+"-"*(30-len(x))+"> NOK--")       
    if   UnknownList:
        for x in   UnknownList: print(x+"-"*(30-len(x))+"> UN###")        
def Clean():
    global target
    global rebuild
    ltarget=target.split(",")
    
    print("%s targets to be cleaned ...")  %(len(TargetsToBuild))    
    for vTarget in TargetsToBuild:
        if ltarget:
            for t in ltarget:
                x="_"+t
                print("-"*60)
                print("Building Target %s" %(vTarget.name+x))
                if vTarget.execute == "vcbuild":
                    TAR = "%s" %(t)
                    Build_Command =  "%s %s %s %s" % (vTarget.execute,vTarget.vcproj,vTarget.attrib, TAR)
                    print("Visual studio rebuild is done by default ....")
                    continue
                else:    
                    Build_Command =  "%s %s%s %s %s" % (vTarget.execute,vTarget.name,x,vTarget.attrib, " -c ")
                print(Build_Command)
                
                proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=vTarget.workspace)
                stdout_str, stderr_str = proc.communicate()
                if stdout_str: fo.write(stdout_str)
                
                if stderr_str:fo.write(stderr_str)
                
                #print(stdout_str, stderr_str)
                if "Build succeeded" in stdout_str:
                    print("OK ...")
                    pass
                elif "Build FAILED" in stdout_str:
                    print("NOK ...")
                    pass
                else:
                    print(stdout_str)
                if stderr_str:
                    print(stderr_str)

        else:
            print("-"*60)
            print("Cleaning  Target %s" %(vTarget.name))
            Build_Command =  "%s %s %s " % (vTarget.execute,vTarget.name,vTarget.attrib)
            print(Build_Command)
            proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE, cwd=vTarget.workspace)
            stdout_str, stderr_str = proc.communicate()
            if stdout_str:
                #print(stdout_str)
                pass
            if stderr_str:
                print(stderr_str) 

def premain():
    global logName
    global start_time, logName 
    start_time = timeit.default_timer()
    logName = os.path.basename(__file__)
    x = logName.split(".")
    if x: logName = x[0]
    logName = logName.replace(".py", "")
    if not os.path.exists("log"):
        os.makedirs("log")
    global  fo
    if os.path.isfile("./log/"+logName+".log"):
        time = str(datetime.datetime.now().time())
        time = time.replace(":", ".")
        os.rename("./log/"+logName+".log", "./log/"+logName+"_"+time+".log")
    
    fo = open("./log/"+logName+".log", "wb+")
    if info.MyConf.debug_mode == "STD_ON":LogFunc("logging :" + logName)

def postmain():
    global logName
    global fo
    print("#"*30)
    print("#"*30)
    if  EndingErrLevel != 0 and Stand_Alone=="STD_ON" : PrintList(EndingErrMeg, logName +" ERR MSGS")
    
    if EndingErrLevel != 0:
        if info.MyConf.fail_safe == "STD_ON":
            FailSafe()
    t = timeit.default_timer() - start_time
    m = t/60
    s = t %60
    LogFunc("-"*30)
    LogFunc("--- %s seconds ---" % (timeit.default_timer() - start_time))
    LogFunc("    "+str(m) + " Minutes ")
    LogFunc("-"*30)
    fo.close()
   
def main():
    global rebuild  
    if Components:
        MFiles = GetMakeFiles(Components.split(","),Build_ALL)
    else:
        MFiles = GetMakeFiles([],Build_ALL)
    #print(MFiles)
    MFiles = filter(None, MFiles)
    parse(MFiles, vfilter.split(",")) 
        
    if rebuild == " -r ": Clean()
    Build()
def Container():
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)    
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD)    
    premain()
    if info.MyConf.tst_mode == "STD_ON": 
        test()
    else:    
        main()
    postmain()
    return (EndingErrLevel , (EndingErrMeg))

if __name__ == "__main__":
    Stand_Alone="STD_ON"
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg))   