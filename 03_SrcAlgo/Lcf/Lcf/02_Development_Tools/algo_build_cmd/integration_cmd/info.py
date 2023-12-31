"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:44CET $

----------------------------------------------------"""
import os,  stat
import shlex, subprocess
import sys, getopt
import logging
import glob
from os.path import basename , dirname
#import CppHeaderParser
import shutil
import datetime
import configparser
import re

ConfigFile = "Conf.ini"


#print(ConfigFile)
ConfigFile = os.path.abspath(ConfigFile)

def dump(obj):
   print("#"*30)
   for attr in dir(obj):
       if hasattr( obj, attr ):
           if attr != "__doc__" and attr != "__init__" and attr != "__module__":
               print("-"*30)
               print( "obj.%s = %s" % (attr, getattr(obj, attr)))
               print("-"*30)
def ConvertFlatToConfigPath(Sub, Obj):
    t = Sub.replace("/project.pj","")
    y = t.replace(Obj.RootProject+"/", "PROJECTS.pj#"+Obj.RootProject+"#d="+Obj.DevPath+"#")
    y = y.replace(Obj.RootProject+"\\", "PROJECTS.pj#"+Obj.RootProject+"#d="+Obj.DevPath+"#")
    #print(t, Obj.RootProject)
    #print(y)
    return y
def GetLabelForRevision(DevPath, SharedProject, Rev, Obj):
        """
        GetRevisionForLabel( SharedProject, Label)

        Description: Get the revision corresponding to a label

        Parameter: -SharedProject the path from where the shared project is shared
                   -Label serach the revision to this label

        return 0 if label could not be found in this shared project
        """
        ret_value = "default"
        if DevPath:
            cmdline_info='si viewprojecthistory --batch  --fields=revision,labels --rfilter=labeled ' +' -P  #p='+ConvertFlatToConfigPath(SharedProject, Obj)+''
        else:
            cmdline_info='si viewprojecthistory --batch  --fields=revision,labels  --rfilter=labeled   --project='+SharedProject
        #print cmdline_info
        try:
            proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            #print(stdout_str)
            #print(stderr_str)
            stdout_str_lines = stdout_str.splitlines()
        except OSError,ValueError:
            print formatExceptionInfo()
#        print Label
        for line in stdout_str_lines:
            #print line
            if (len(line) > 1):
                argu = line.split()
                #print (argu)
                if (len(argu) > 2):
                    argu[1] = argu[len(argu)-1]
                    argu[0] = line.replace(argu[1],"")
                    argu[0] = argu[0].rstrip()
                    argu[0] = argu[0].replace("\n","")
    #                    print argu[0]
                    if (len(argu) > 1):
    #                    print argu[0]
    #                    print argu[1]

                        # check if unicode
                        try:
                            argu[0].decode('ascii')
                        except UnicodeDecodeError:
                            print("Decoding issue")
                else:
                    # an ascii-encoded unicode string
                    #print(argu[0],1)
                    if (argu[0] == Rev):
                        ret_value = argu[1]
                        #print(cmdline_info)
                        break
#                        print "Return value " + ret_value
        #if ret_value == "default":
            #print(stdout_str)
            #print(stderr_str)
        return ret_value   
class Sandbox:
    def __init__(self):
        self.DevPath = ""
        self.path=""
        self.LatestCP=""
        self.LatestLabel=""
        self.Project=""
        self.RootProject=""
        self.GetSandBoxinfo()
        
    def GetSandBoxinfo(Obj):
        cmdline_info = "si sandboxinfo"
        try:
            proc=subprocess.Popen(cmdline_info, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
            stdout_str, stderr_str = proc.communicate()
            #print(stdout_str)
            #print(stderr_str)
            stdout_str_lines = stdout_str.splitlines()
        except OSError,ValueError:
            print formatExceptionInfo()
        
        for Line in stdout_str_lines:
            if "Development Path:" in Line:
                
                DevPath = Line.replace("Development Path:", "")
                DevPath = DevPath.replace(" ", "")
                Obj.DevPath = DevPath
            elif "Revision:" in Line:
                LatestCP = Line.replace("Revision:", "")
                LatestCP = LatestCP.replace(" ", "")
                Obj.LatestCP = LatestCP
            elif "Configuration Path:" in Line:
                Obj.RootProject=Line.replace("Configuration Path:","")
                x = Obj.RootProject.split("#")
                Obj.RootProject = x[2]
                MainProjectName = Obj.RootProject
            elif "Project Name:" in Line:
                Obj.Project=Line.replace("Project Name:","")
                Obj.Project = Obj.Project.replace(" ", "")
            elif "Variant Sandbox Name:" in Line:
                Obj.path=Line.replace("Variant Sandbox Name:","")
                Obj.path = Obj.path.replace(" ", "")
        Obj.LatestLabel = GetLabelForRevision(Obj.DevPath,Obj.Project, Obj.LatestCP, Obj )

        
        
class UserInfo:
    def __init__(self, id):
        self.ID=""
        self.cp=""
        self.cpList = []
        self.InitUserInfo()
    def InitUserInfo(Obj):
        Build_Command = "si viewcps --fields=user  "
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        print(stderr_str)
        Lines = stdout_str.split()
        p = re.compile('\(\w+\)', re.IGNORECASE)
        m=p.search(stdout_str)
        #if m: 
        x = m.group()
        #print(x)
            #sys.exit(0)
        x = x.replace("(","")
        x = x.replace(")","")
        Obj.ID = x
        #print(x)
        #Build_Command = "si viewcps --fields=id --filter=project:"+CurrentSandBox.RootProject+"  --filter=user:"+Obj.ID+" --filter=state:Open  "
        Build_Command = "si viewcps --fields=id "+"  --filter=user:"+Obj.ID+" --filter=state:Open  "
        #print(Build_Command)
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        #print(stdout_str)
        Lines = stdout_str.split()
        for line in Lines:
            x = line.replace(" ","")
            Obj.cp = x
            Obj.cpList.append(x)
        
        #dump(Obj)
            
def addprop(inst, name, method):
    cls1 = type(inst)
    if not cls1.hasattr('__perinstance'):
        cls1 = type(cls1.__name__, (cls1,), {})
        cls1.__perinstance = True
    setattr(cls1, name, property(method))
  
class UserConf(object):
    def __init__(self, id):
        self.ID=""
        self.cp=""
        self.user = ""
        self.AUTO_CP = ""
        self.WD=""
        self.Rebuild=""
        self.CLEAN=""
        self.Auto_Sys_Config=""
        self.Extra_Build_Options=""
        self.MainPrj = ""
        self.Emergency_Mode = ""
        self.AUTO_XLS = ""
        self.Auto_CP_Creation = ""
        self.InitUserConf()
    def ReadIni(Obj, IniFileName):
        returnValue = {}
        config = configparser.ConfigParser()
        config.read(IniFileName)
        SectionList = config.sections()    
        for section in SectionList:
            for x in config[section]:
                returnValue[x] = config[section][x]
        return (returnValue)
    def addprop1(Obj, name, method):
        cls1 = type(Obj)
        if not hasattr(cls1, '__perinstance'):
            cls1 = type(cls1.__name__, (cls1,), {})
            cls1.__perinstance = True
        setattr(cls1, name, property(method))
        #getattr(cls1, name)
  
    def InitUserConf(self):
        Ret = []
        Ret = self.ReadIni(ConfigFile)
        #print(Ret)
        self.cp=Ret[str("change_package").lower()]
        self.user = Ret["user".lower()]
        self.AUTO_CP = Ret["AUTO_CP".lower()]
        self.WD=Ret["WD".lower()]
        self.Rebuild=Ret["Rebuild".lower()]
        self.CLEAN=Ret["CLEAN".lower()]
        self.Auto_Sys_Config=Ret["Auto_Sys_Config".lower()]
        self.Extra_Build_Options=Ret["Extra_Build_Options".lower()]
        self.MainPrj = Ret["MainPrj".lower()]                        
        self.Emergency_Mode = Ret["Emergency_Mode".lower()]                        
        self.AUTO_XLS = Ret["AUTO_XLS".lower()]                        
        self.Auto_CP_Creation = Ret["Auto_CP_Creation".lower()]        
        #self.Build_ALL = Ret["Build_ALL".lower()]
        #self.addprop1("Build_ALL", Ret["Build_ALL".lower()])
        self.Build_ALL = Ret["Build_ALL".lower()]
        #self.Debug_Mode = Ret["Debug_Mode".lower()]
        for key in Ret:
            #self.addprop1(key, Ret[key.lower()])
            #cc = "I"
            self.__dict__[key] = Ret[str(key).lower()]
             
CurrentSandBox = Sandbox()    
MyInfo =     UserInfo(0)
MyConf =     UserConf(0)
WD =os.path.dirname(os.path.abspath(__file__))
os.chdir(WD)
WD =os.path.abspath(MyConf.WD)
os.chdir(WD) 
CurrentSandBox = Sandbox()   
WD =os.path.dirname(os.path.abspath(__file__))
os.chdir(WD) 
#dump(CurrentSandBox)
    
def main():
    dump(MyInfo)
    dump(CurrentSandBox)
    dump(MyConf )
if __name__ == "__main__":
    Stand_Alone="STD_ON"    
    main()
