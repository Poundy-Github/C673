"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:51:00CET $

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
import info
import logging
from time import gmtime, strftime
import timeit
from common import Email_Address, fprint
import common
import  CompareXls
import  make_all_xml
import  check_labels
import  run_config
import  Compare
import  Post_Config
import  Check_mod
import  info
import SmokeTest
import Smoke_Test
import CheckPoint
import Config_Sys
from optparse import OptionParser


parser = OptionParser()
Email_Address = None
CP = info.MyConf.cp
AUTO_CP = info.MyConf.AUTO_CP
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
WD =os.path.abspath(info.MyConf.WD)
os.chdir(WD) 
if info.MyConf.debug_mode == "STD_ON":print("WD: "+ WD + " \n ")
logName = ""
if info.MyConf.debug_mode == "STD_ON":LogFunc = common.kprint
else:LogFunc = common.fprint; 
start_time = None
logName=""
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0
Debug_Mode = info.MyConf.debug_mode
Test_Mode = info.MyConf.tst_mode
GO_MODE = info.MyConf.go_mode
Auto_CP_Creation = info.MyConf.auto_cp_creation
Auto_Sys_Config = info.MyConf.auto_sys_config
fo = None
TimeConsumption = None
GeneralLogFile="log"
Checkpoint_Created="NO"
Session_ID = str(os.getpid())
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
def CallModule(object):
    global CP
    global EndingErrLevel, EndingErrMeg, fo
    if CP:object.CP = CP
    #if object.common: object.common.Init()
    (RetEndingErrLevel , RetEndingErrMeg) = object.Container()
    EndingErrLevel = EndingErrLevel + RetEndingErrLevel
    if RetEndingErrLevel:
        #print(RetEndingErrMeg)
        EndingErrMeg = common.AddLists(EndingErrMeg, RetEndingErrMeg)
    #print(1)
    #print(RetEndingErrMeg)
    common.fo = fo
    return RetEndingErrLevel
def premain():
    global logName
    global GlogName
    global start_time 
    start_time = timeit.default_timer()
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
    GlogName = os.path.abspath("./log/"+GeneralLogFile+".log")
    logging.basicConfig(filename=GlogName, filemode='w',level=logging.DEBUG)
    common.fo = fo

    if info.MyConf.debug_mode == "STD_ON":LogFunc("logging :" + logName)
    
def postmain():
    global logName
    global  TimeConsumption
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
    TimeConsumption = t/60
    s = t %60
    LogFunc("-"*30)
    LogFunc("--- %s seconds ---" % (timeit.default_timer() - start_time))
    print("    "+str(TimeConsumption) + " Minutes ")
    LogFunc("-"*30)
    fo.close()
def FailSafe():
    pass    
def test():
    '''Command = "pass"
    if  CallModule(make_all_xml):
        exec(Command)
    CP = common.CreateCP(make_all_xml.CompareXls.ReleaseInfo.RO) 
    if ":" in CP:
        make_all_xml.CompareXls.ReleaseInfo.cp = CP
    #if CallModule(check_labels):
        #exec(Command)
    #if CallModule(run_config):
        #return
    #run_config.Configure()    
    if CallModule(Compare):
        exec(Command)
    if info.MyConf.debug_mode == "STD_ON":print(make_all_xml.CompareXls.OldLabels)   
    if info.MyConf.debug_mode == "STD_ON":print(Compare.lst)
    x = common.CompLst(make_all_xml.CompareXls.NewLabels,Compare.lst )
    if info.MyConf.debug_mode == "STD_ON":print(x)
    if (x):
        exec(Command)
        
    common.CloseCP(make_all_xml.CompareXls.ReleaseInfo.cp)'''
    if info.MyConf.step_email_notification == "STD_ON":
        common.Init()
        common.ActivityReportMail(aModule_Name="Configurations", aModule_Description="Configure",aEndingErrLevel=1,aTimeConsumption=0, FreeTXT = "I am the free Text")
    '''
    if CallModule(Post_Config):
        exec(Command)
    Check_mod.Comment =  make_all_xml.CompareXls.ReleaseInfo.comment   
    Check_mod.Label =  make_all_xml.CompareXls.ReleaseInfo.label   
    if CallModule(Check_mod):
        exec(Command)
    if CallModule(SmokeTest):
        exec(Command)
    if Auto_CP_Creation == "STD_ON" :
        CheckPoint.Label=make_all_xml.CompareXls.ReleaseInfo.label
        if  not CallModule(CheckPoint):
            if Auto_Sys_Config == "STD_ON":
                Config_Sys.Label = make_all_xml.CompareXls.ReleaseInfo.label
                if CallModule(Config_Sys):
                print("Error configuring System folder !!!")'''
def FindStrFile(templst, file):
    ret = 0
    if not templst:
        print("List is empty !!!");return (ret)
    for str in templst:
        if str not in open(file).read():
            ret = 1
            print ("%s not found in %s") %(str, file)
    return(ret)           
def GO_Mode():
    Command = "pass"
    if  CallModule(make_all_xml):
        exec(Command)
    if info.MyConf.check_labels == "STD_ON":    
        if CallModule(check_labels):
            exec(Command)
    else:
        common.kprint("Check labels were disabled !!! ")
    #if CallModule(run_config):
        #return
    if info.MyConf.run_config == "STD_ON":
        run_config.Configure()
    else:
        common.kprint("info: Configuration is disabled ...")
    if CallModule(Compare):
        exec(Command)
    #print(make_all_xml.CompareXls.NewLabels)   
    #print(Compare.lst)
    x = common.CompLst(make_all_xml.CompareXls.NewLabels,Compare.lst )
    if info.MyConf.debug_mode == "STD_ON":print(x)
    ans = "n"
    if (x[0]):
        exec(Command)
    if CallModule(Post_Config):
        exec(Command)
    Check_mod.Comment =  make_all_xml.CompareXls.ReleaseInfo.comment   
    Check_mod.Label =  make_all_xml.CompareXls.ReleaseInfo.label   
    if CallModule(Check_mod):
        exec(Command)
    if CallModule(SmokeTest):
        exec(Command)
    if Auto_CP_Creation == "STD_USER":
        ans = "n"
        ans = common.GetInput('Create CP ?  y/[n]:')
    if Auto_CP_Creation == "STD_ON" or ans == "y":
        CheckPoint.Label=make_all_xml.CompareXls.ReleaseInfo.label
        if  not CallModule(CheckPoint):
            if Auto_Sys_Config == "STD_ON":
                Config_Sys.Label = make_all_xml.CompareXls.ReleaseInfo.label
                if CallModule(Config_Sys):
                    print("Error configuring System folder !!!")
        
def Normal_Mode():
    global CP
    Command = "return"
    if info.MyConf.update_cfg_files == "STD_ON" or info.MyConf.update_cfg_files == "STD_AUTO":
        if  CallModule(make_all_xml):
            return
            
    else:
        if  CallModule(CompareXls):
            return
    ConfirmRequest()        
    if  info.MyConf.check_devpath  == "STD_ON":
        if make_all_xml.CompareXls.ReleaseInfo.DevPath != info.CurrentSandBox.DevPath:
            AddErr("DevPaths are not Equal: "+make_all_xml.CompareXls.ReleaseInfo.DevPath+" != "+info.CurrentSandBox.DevPath)
            return
    CP = common.GetCP(make_all_xml.CompareXls.ReleaseInfo.RO) 
    if "default" not in CP: make_all_xml.CompareXls.ReleaseInfo.cp = CP
    else: CP = make_all_xml.CompareXls.ReleaseInfo.cp
    #print(CP)
    #print(make_all_xml.CompareXls.ReleaseInfo.cp)
    
    if info.MyConf.check_labels == "STD_ON":    
        if CallModule(check_labels):
            return
    elif  info.MyConf.check_labels == "STD_OFF":
        common.kprint("Check labels were disabled !!! ")
    elif  info.MyConf.check_labels == "STD_AUTO":
        common.kprint("Check labels were disabled !!! ")
    else:
        pass
    #if CallModule(run_config):
        #return
    if info.MyConf.run_config == "STD_ON":
        if "default" not in CP:run_config.CP = CP
        run_config.Configure()
    else:
        common.kprint("info: Configuration was disabled ...")
    if CallModule(Compare):
        return
    #print(make_all_xml.CompareXls.NewLabels)   
    #print(Compare.lst)
    #Copy by Value
    templst = make_all_xml.CompareXls.ModLabels[:]
    for x in templst:
        if "FPGA" in x:
            print("Label has been excluded from the comparison : "+x)
            templst.remove(x)
            
    x = common.CompLst(templst,Compare.lst )
    LogFunc(str(x))
    Cfile = "post_config_shared_projects.xml"
    if not os.path.isfile(Cfile):
        print("file %s does not exist ... ") %Cfile
        return
    LogFunc("Searching post config file ...")
    y = FindStrFile(templst, Cfile)
    if y:
        print("Labels not well configured .")
        return
    ans = "n"
    if (x[0]):
        Text = "Some Labels were already there ..."
        common.PrintList(x[1], Text)
        #return
    LogFunc("Parsing the log file ...") 
    Lfile = "logging.txt"
    SString = "Error: " 
    Ffile = open(Lfile).read()
    Errs = Ffile.count(SString)
    
    if Errs:
        txt = "Log file contains %s errors !!!, kindly check the file %s" %(Errs, os.path.abspath(Lfile))
        print(txt)
        if info.MyConf.check_config_logfile == "STD_ON":AddErr(txt);return
    if info.MyConf.step_email_notification == "STD_ON":
        common.Init()
        common.ActivityReportMail(aModule_Name="Configurations", aModule_Description="Configure the integration project on the server ... ",aEmail_Address=Email_Address,aEndingErrLevel=Errs,alogName=Lfile,aTimeConsumption=0, FreeTXT = common.List2Str(x[1],"\n"))     
    if CallModule(Post_Config):
        if info.MyConf.check_build == "STD_OFF":
            pass
        else:    
            return
    if info.MyConf.invoke_mts  == "STD_AUTO":
        Smoke_Test.Comment =  make_all_xml.CompareXls.ReleaseInfo.comment   
        #Smoke_Test.Label =  make_all_xml.CompareXls.ReleaseInfo.label       
        if CallModule(Smoke_Test):
            return
    else:
        if CallModule(SmokeTest):
            return
        Check_mod.Comment =  make_all_xml.CompareXls.ReleaseInfo.comment   
        Check_mod.Label =  make_all_xml.CompareXls.ReleaseInfo.label   
        if CallModule(Check_mod):
            return
    if Auto_CP_Creation == "STD_USER" and info.MyConf.invoke_mts =="STD_AUTO":
        ans = "n"
        ans = common.GetInput('Create CP ?  y/[n]:')
    elif info.MyConf.auto_cp_creation=="STD_AUTO" and  info.MyConf.invoke_mts == "STD_AUTO":
        ans = "y"
    if Auto_CP_Creation == "STD_ON" or ans == "y":
        CheckPoint.Label=make_all_xml.CompareXls.ReleaseInfo.label
        if  not CallModule(CheckPoint):
            global Checkpoint_Created
            Checkpoint_Created = "YES"
            if Auto_Sys_Config == "STD_ON":
                Config_Sys.Label = make_all_xml.CompareXls.ReleaseInfo.label
                if CallModule(Config_Sys):
                    print("Error configuring System folder !!!")
    if make_all_xml.CompareXls.ReleaseInfo.cp: common.CloseCP(make_all_xml.CompareXls.ReleaseInfo.cp)
#if CallModule(Compare):
    #return
#print(Compare.lst)
    
def main():
    global CP
    global Email_Address
    parser.add_option("-e", "--email", dest="email_list",help="Communication mail", metavar="FILE")
    (options, args) = parser.parse_args()
    #print(options)
    if options.__dict__['email_list']:
        Email_Address = options.__dict__['email_list']
    else:
        Email_Address = info.MyConf.default_email
    common.Email_Address = Email_Address    
    #print(options)
    #print(args)
    #return
        #os.chdir(os.path.dirname(os.path.abspath(__file__)))
        #os.system("make_all.xml.py")
        #os.chdir(os.path.dirname(os.path.abspath(__file__)))
        #os.system("run_config.py")
    if GO_MODE == "STD_ON":
        GO_Mode()
    else:
        Normal_Mode()
        
        
def Report():
    try:
        logfile = os.path.abspath("./log/"+logName+".log")
        if (EndingErrLevel != 0) :
            Status = "NOK ---"
        else:
            Status = "OK  +++"
        if     Email_Address :
            common.My_email.recipients = Email_Address.split(",")
            common.My_email.CCrecipients = info.MyConf.admin_email.split(",")
            common.My_email.subject = "HAI: "+ make_all_xml.CompareXls.ReleaseInfo.label+" : " +Status 
            common.My_email.body = "Hi All,\n\nRelease info like below:\n ___________________________\n"+make_all_xml.CompareXls.ReleaseInfo.comment+"\n"
            common.My_email.body = common.My_email.body +"DevPath: "+info.CurrentSandBox.DevPath+"\n\n"
            common.My_email.body = common.My_email.body +"Consumed time: "+str(TimeConsumption)+" Minutes \n\n"
            

            
            n = 1
            if (make_all_xml.CompareXls.NewLabels):
                common.My_email.body = common.My_email.body +"Labels to be included ::\n"+"___________________________\n"
                for x in make_all_xml.CompareXls.NewLabels:
                    common.My_email.body = common.My_email.body +str(n)+": "+x+"\n"
                    n = n +1
                    
            if (EndingErrLevel):
                for i in EndingErrMeg:
                    common.My_email.body = common.My_email.body +i+"\n"
            common.My_email.body = common.My_email.body +"Status : "+Status+"\n"    
            common.My_email.body = common.My_email.body +"Check point Created : "+Checkpoint_Created+"!!! \n"    
            common.My_email.body = common.My_email.body +"Session ID : "+Session_ID+"!!! \n"    
            common.My_email.body = common.My_email.body +" Kindly Consider the Attached log ..."+"\n"    
            common.My_email.attachments = [GlogName]
            common.ReportMail()
    except OSError,ValueError:
        AddErr(str(ValueError))    
    
def ConfirmRequest():
    if (EndingErrLevel != 0) :
        Status = "ERROR ---"
    else:
        Status = "Started  +++"
    common.My_email.recipients = Email_Address.split(",")
    common.My_email.CCrecipients = info.MyConf.admin_email.split(",")
    common.My_email.subject = "HAI: "+make_all_xml.CompareXls.ReleaseInfo.label+" : " +Status 
    common.My_email.body = "Hi All,\n\nRelease info like below:\n ___________________________\n"+make_all_xml.CompareXls.ReleaseInfo.comment+"\n"
    common.My_email.body = common.My_email.body +"DevPath: "+info.CurrentSandBox.DevPath+"\n\n"
    common.My_email.body = common.My_email.body +"Starting time: "+strftime("%a, %d %b %Y %H:%M:%S +0000", gmtime())+"\n\n"
    common.My_email.body = common.My_email.body +"Session ID : "+Session_ID+"!!! \n"    

    n = 1
    if (make_all_xml.CompareXls.NewLabels):
        common.My_email.body = common.My_email.body +"New Labels to be included ::\n"+"___________________________\n"
        for x in make_all_xml.CompareXls.NewLabels:
            common.My_email.body = common.My_email.body +str(n)+": "+x+"\n"
            n = n +1
    n = 1
    if (make_all_xml.CompareXls.OldLabels):
        common.My_email.body = common.My_email.body +"New Labels already included ::\n"+"___________________________\n"
        for x in make_all_xml.CompareXls.OldLabels:
            common.My_email.body = common.My_email.body +str(n)+": "+x+"\n"
            n = n +1
            
            
    if (EndingErrLevel):
        for i in EndingErrMeg:
            common.My_email.body = common.My_email.body +i+"\n"
    common.My_email.body = common.My_email.body +" Status : "+Status+"\n"    
    
    common.My_email.body = common.My_email.body +"\n"    
    common.ReportMail()       
def Container():
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
        AddErr(str(ValueError))
    postmain()
    try:
        Report()
    except OSError,ValueError:
        AddErr(str(ValueError))    
    return (EndingErrLevel , (EndingErrMeg))

if __name__ == "__main__":
    common.Init()
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg)) 
    sys.exit(EndingErrLevel)
