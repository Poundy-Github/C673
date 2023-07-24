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

import timeit
from common import fprint , fo , Email_Address
import common


CP = info.MyConf.cp
AUTO_CP = info.MyConf.AUTO_CP
if AUTO_CP == "STD_ON":
    CP = info.MyInfo.cp
#WD =os.path.abspath(info.MyConf.WD)
#os.chdir(WD) 
#print("WD: "+ WD + " \n ")
logName = ""
if info.MyConf.debug_mode == "STD_ON":LogFunc = common.kprint
else:LogFunc = common.fprint; 
start_time = None
logName=""
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0
LogFile="./log/Build"+os.path.basename(__file__)+".log"

fo = None
Stand_Alone="STD_OFF"
Module_Name=""
Module_Description=""
Module_Status="NO_ERROR"
stdout_str = ""
stderr_str = ""
from optparse import OptionParser
parser = OptionParser()
Email_Address = None
parser.add_option("-e", "--email", dest="email_list",help="Communication mail", metavar="FILE")
(options, args) = parser.parse_args()
if options.__dict__['email_list'] and Stand_Alone=="STD_ON":
    Email_Address = options.__dict__['email_list']
else:
    Email_Address = info.MyConf.default_email

class TJenkins(object):
    def __init__(self, id,protocol,server,job,username="",pwd="", pwdf="",parameters={}):
        self.ID=id
        self.protocol=protocol
        self.server =server
        self.job=job
        self.username=username
        self.pwd=pwd
        self.pwdf=pwdf
        self.parameters=parameters
        
        
Jenkins = TJenkins(0,"http","lul2yxmg:1111","MFS16_Members","uidg3180", "2005mhhm")
Paremeters={}
JenCli = "./jenkins-cli.jar"

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
    global start_time, logName 
    start_time = timeit.default_timer()
    common.Init()
    logName = os.path.basename(__file__)
    x = logName.split(".")
    if x: logName = x[0]
    logName = logName.replace(".py", "")
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
    if info.MyConf.debug_mode == "STD_ON":LogFunc("logging :" + logName)

def postmain():
    global logName
    global fo
    common.fo  = fo
    fprint("#"*30)
    fprint("#"*30)
    if  EndingErrLevel != 0 and Stand_Alone=="STD_ON": common.PrintList(EndingErrMeg, logName +" ERR MSGS")
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
    global Paremeters
    global stdout_str
    global stderr_str
    opt=""
    #Build_Command = "java -jar D:\\executables\\jenkins-cli.jar -s http://lul2yxmg:1111/ help"
    #Build_Command = "java -jar D:\\executables\\jenkins-cli.jar -s   http://lul2yxmg:1111  -i buildkey build MFS16_Members -p token=build  "
    #Build_Command = "java -jar D:\\executables\\jenkins-cli.jar -s   http://lul2yxmg:1111   build MFS16_Members --username uidg3180 --password 2005mhhm -p token=build  "
    #Build_Command = "java -jar D:\\executables\\jenkins-cli.jar -s   http://lul2yxmg:1111   build MFS16_Members --username uidg3180 --password 2005mhhm  -s  "
    print("Job : %s@%s")%(Jenkins.job,Jenkins.server)
    if Jenkins.parameters:
        #print(Paremeters)
        #opt = " -p "
        for key, value in Jenkins.parameters.iteritems():
            opt=" "+opt+" -p  "+key+"="+value+" "
    #print(opt)
    if  Jenkins.pwdf:
        strPWD = " --password-file "+Jenkins.pwdf+" "
    elif Jenkins.pwd:
        strPWD = " --password "+Jenkins.pwd+" "
    else:
        strPWD = " "
    if Jenkins.username and Jenkins.pwd:
        Build_Command = "java -jar "+JenCli+" -s   "+Jenkins.protocol+"://"+Jenkins.server+"   build "+Jenkins.job+" --username "+Jenkins.username+strPWD+"  -s  "+opt +" "
    else:
        Build_Command = "java -jar "+JenCli+" -s   "+Jenkins.protocol+"://"+Jenkins.server+"   build "+Jenkins.job+"  -s  "+opt +" "

        
    print(Build_Command)#;return
    try:
        proc=subprocess.Popen(Build_Command, shell=True,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        stdout_str, stderr_str = proc.communicate()
        if not "SUCCESS" in stdout_str and stdout_str:
            AddErr(stdout_str)
        #print(stdout_str)
        if (stderr_str):
            AddErr(stderr_str)
    except OSError,ValueError:
        AddErr(str(ValueError))

    
    pass
def test():
    pass    
def Container():
    global JenCli
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)
    JenCli = os.path.abspath(JenCli)    
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
    common.Init()
    Container()
    if EndingErrLevel != 0:
        print(EndingErrLevel , (EndingErrMeg)) 