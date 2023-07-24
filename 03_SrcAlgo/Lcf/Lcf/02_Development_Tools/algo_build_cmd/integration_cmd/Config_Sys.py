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
import re
import info
import timeit
import common
from common import Email_Address, fprint , fo

logName = ""
if info.MyConf.debug_mode == "STD_ON":LogFunc = common.kprint
else:LogFunc = common.fprint; 
start_time = None
logName=""
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0

Auto_Sys_Config = info.MyConf.Auto_Sys_Config

AUTO_CP = info.MyConf.AUTO_CP

#WD =os.path.abspath(info.MyConf.WD)
#os.chdir(WD) 

Stand_Alone="STD_OFF"
Module_Name="Configure SYSTEM"
Module_Description="Update the system folder to contain the released DLLs, to be used afterword in the validation activity ."
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"

Label=""    
class Sandbox:
    def __init__(self):
        self.DevPath = ""
        self.path=""
        self.LatestCP=""
        self.LatestLabel=""
        self.Project=""
        self.RootProject=""


CurrentSandBox = Sandbox        
MainProjectName  ="MFC400"
DevPath  = "SMFC4B0_07.00.00"

ChangePackageList={"MFC400":"263205:1","SRLCam":"203064:1"}


ListOfProjects = ["MFC400", "SRLCam"]
PrjOfDevPath = {"SMFC4B0_07.00.00":"MFC400","MFC4T0_B2_01.02":"MFC400","SRLCam4T0_R2.0.0_INT1":"SRLCam","SRLCam4T0_2.1":"SRLCam","SRLCam4T0_2.2":"SRLCam",}
MainProjectName=PrjOfDevPath[DevPath]
ChangePackage=ChangePackageList[MainProjectName]

if AUTO_CP == "STD_ON":
    ChangePackage = info.MyInfo.cp

RFoldersToConfig = ["../02_System/05_Tools/mts_system/mts_measurement/cfg/algo","../02_System/05_Tools/mts_system/mts_measurement/dll/algo","../02_System/05_Tools/mts_system/mts_measurement/sdl/algo","../02_System/05_Tools/mts_system/mts_measurement/sdl/ti_c674x/","../02_System/05_Tools/mts_system/mts_measurement/sdl/ti_cortex_a8/"]
AFoldersToConfig = []
ASubsToConfig = []

def dump(obj):
   print("#"*30)
   for attr in dir(obj):
       if hasattr( obj, attr ):
           if attr != "__doc__" and attr != "__init__" and attr != "__module__":
               LogFunc("-"*30)
               print( "obj.%s = %s" % (attr, getattr(obj, attr)))
               LogFunc("-"*30)
               
def SandToProj(Sandbox):
    Up1 = os.path.dirname(WD)
    pattern = re.compile(re.escape(Up1), re.IGNORECASE)
    x= re.sub(pattern, "/nfs/projekte1/PROJECTS/"+info.CurrentSandBox.RootProject,Sandbox)
    #x = Sandbox.replace(Up1,"/nfs/projekte1/PROJECTS/"+CurrentSandBox.RootProject)
    return x
    
def ConvertALL():
    for path in RFoldersToConfig:
        AFoldersToConfig.append(os.path.abspath(path))
        ASubsToConfig.append(SandToProj(os.path.abspath(path)))
    

def ConvertFlatToConfigPath(Sub):
    t = Sub.replace("/project.pj","")
    y = t.replace(CurrentSandBox.RootProject+"/", "PROJECTS.pj#"+CurrentSandBox.RootProject+"#d="+info.CurrentSandBox.DevPath+"#")
    y = y.replace(CurrentSandBox.RootProject+"\\", "PROJECTS.pj#"+CurrentSandBox.RootProject+"#d="+info.CurrentSandBox.DevPath+"#")
    #print(t, CurrentSandBox.RootProject)
    #print(y)
    return y
    
def GetRevisionForLabel(DevPath, SharedProject, Label):
        """
        GetRevisionForLabel( SharedProject, Label)

        Description: Get the revision corresponding to a label

        Parameter: -SharedProject the path from where the shared project is shared
                   -Label serach the revision to this label

        return 0 if label could not be found in this shared project
        """
        ret_value = "default"
        if CurrentSandBox.DevPath:
            cmdline_info='si viewprojecthistory --batch  --fields=labels,revision --rfilter=labeled ' +' -P  #p='+ConvertFlatToConfigPath(SharedProject)+''
        else:
            cmdline_info='si viewprojecthistory --batch  --fields=labels,revision --rfilter=labeled   --project='+SharedProject
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
                    if (argu[0] == Label):
                        ret_value = argu[1]
                        #print(cmdline_info)
                        break
#                        print "Return value " + ret_value
        #if ret_value == "default":
            #print(stdout_str)
            #print(stderr_str)
        return ret_value

        
def GetLabelForRevision(DevPath, SharedProject, Rev):
        """
        GetRevisionForLabel( SharedProject, Label)

        Description: Get the revision corresponding to a label

        Parameter: -SharedProject the path from where the shared project is shared
                   -Label serach the revision to this label

        return 0 if label could not be found in this shared project
        """
        ret_value = "default"
        if info.CurrentSandBox.DevPath:
            cmdline_info='si viewprojecthistory --batch  --fields=revision,labels --rfilter=labeled ' +' -P  #p='+ConvertFlatToConfigPath(SharedProject)+''
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

def GetSandBoxinfo():
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
            CurrentSandBox.DevPath = DevPath
        elif "Revision:" in Line:
            LatestCP = Line.replace("Revision:", "")
            LatestCP = LatestCP.replace(" ", "")
            CurrentSandBox.LatestCP = LatestCP
        elif "Configuration Path:" in Line:
            CurrentSandBox.RootProject=Line.replace("Configuration Path:","")
            x = CurrentSandBox.RootProject.split("#")
            CurrentSandBox.RootProject = x[2]
            MainProjectName = CurrentSandBox.RootProject
        elif "Project Name:" in Line:
            CurrentSandBox.Project=Line.replace("Project Name:","")
            CurrentSandBox.Project = CurrentSandBox.Project.replace(" ", "")
    CurrentSandBox.LatestLabel = GetLabelForRevision(info.CurrentSandBox.DevPath,CurrentSandBox.Project, CurrentSandBox.LatestCP )
def getLabel():
    Label = common.GetInput('Enter the label: ')
    return Label



def ConfigSub(Sub, CP):
    ProjectToBeConfigured = Sub+"/project.pj"
    RootProjectToBeConfigured = os.path.dirname(Sub)+"/project.pj"
    if CP != "default":
        print("#"*30)
        print("#"*30)
        print(" ---- Start Config-----")
        print("Subproject: "+ProjectToBeConfigured)
        #print("Label: "+Label)
        print("Checkpoint: "+CP)
        Build_Command="si configuresubproject  --type=build --cpid="+ChangePackage+" --subprojectRevision="+CP+" --nocloseCP --project="+RootProjectToBeConfigured +" --devpath="+info.CurrentSandBox.DevPath +" "+ProjectToBeConfigured
        ret = proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if stdout_str :
            print("Out: \n" + stdout_str+"\n")
                
        if stderr_str:
            print("Messages: \n"+stderr_str+"\n")
        print(Build_Command)


def ConfigALL(Label):
    for Sub in ASubsToConfig:
        CP = GetRevisionForLabel(info.CurrentSandBox.DevPath,Sub+"/project.pj",Label)
        #print(DevPath,Sub,Label)
        if CP != "default":
            ConfigSub(Sub, CP)
            #print("Project : "+ Sub+"\n")
            #print("Label : "+ Label+"\n")
            #print("CP : "+ CP+"\n")
        else:
            err_txt = "Invalid Label !!! " +Label
            print(err_txt)
            AddErr(err_txt)





def test():
    GetSandBoxinfo()
    dump(CurrentSandBox)

def AddErr(err=LineErrMeg):
    global logName
    global EndingErrMeg, EndingErrLevel
    logName = os.path.basename(__file__)
    logName = logName.replace(".pyc", "")
    logName = logName.replace(".py", "")
    EndingErrLevel = EndingErrLevel + 1
    strx = ""
    if info.MyConf.debug_mode == "STD_ON":strx =str(EndingErrLevel)+": "+logName
    EndingErrMeg.append( strx+": "+err)    

def premain():
    global logName
    global start_time 
    start_time = timeit.default_timer()
    common.Init()
    logName = os.path.basename(__file__)
    logName = logName.replace(".py", "")
    if not os.path.exists("log"):
        os.makedirs("log")
    global  fo
    if os.path.isfile("./log/"+logName+".log"):
        time = str(datetime.datetime.now().time())
        time = time.replace(":", ".")
        os.rename("./log/"+logName+".log", "./log/"+logName+"_"+time+".log")
    
    fo = open("./log/"+logName+".log", "wb+")
    common.fo = fo
    LogFunc("logging :" + logName)
def postmain():
    global logName
    global fo
    common.fo  = fo
    fprint("#"*30)
    fprint("#"*30)
    if  EndingErrLevel != 0: common.PrintList(EndingErrMeg, logName +" ERR MSGS")
    #fo.close()
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
    if info.MyConf.step_email_notification == "STD_ON":
        common.ActivityReportMail(aModule_Name=Module_Name, aModule_Description=Module_Description,aEndingErrLevel=EndingErrLevel,alogName=LogFile,aTimeConsumption=m,aEmail_Address=common.Email_Address)
    
def FailSafe():
    pass
def main():
    #print(Stand_Alone)
    GetSandBoxinfo()
    if Stand_Alone=="STD_ON":       
        L = CurrentSandBox.LatestLabel
        if Auto_Sys_Config != "STD_ON":
            L = getLabel()
    elif Label and Stand_Alone=="STD_OFF":
        L = Label
    else:
        print("Error label !!!")
        return
    print("#"*30)
    print("Label to be configured : "+L)
    print("#"*30)
    ConvertALL()
    ConfigALL(L)
    

def Container():
    global WD
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)    
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD)    
    try:
        premain()
        if info.MyConf.tst_mode == "STD_ON": 
            test()
        else:    
            main()
    except OSError,ValueError:
        AddErr(formatExceptionInfo())
    postmain()
    return (EndingErrLevel , (EndingErrMeg))

if __name__ == "__main__":
    Stand_Alone="STD_ON"
    common.Init()
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg)) 