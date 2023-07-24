"""----------------------------------------------------
HAI: Highly automated integration

Features:
---------

Automated integration:

:author:        Medhat HUSSAIN
:version:       $Revision: 1.1 $
:date:          $Date: 2021/12/13 17:50:43CET $

----------------------------------------------------"""
import os,  stat
import info
lst= []
EndingErrMeg = []
LineErrMeg = "Generic Error !!!"
EndingErrLevel = 0

fo = None
Stand_Alone="STD_OFF"
Module_Name="Compare"
Module_Description="Compare the System's configurations before and after the configuration activity"
Module_Status="NO_ERROR"
LogFile="./log/Build"+os.path.basename(__file__)+".log"

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

def main():
    file1="pre_config_shared_projects.xml"
    file2="post_config_shared_projects.xml"
    Outfile = "COMP.txt"

    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD) 
    if not os.path.exists(file1):AddErr("File does not exist:"+file1);return
    if not os.path.exists(file2):AddErr("File does not exist:"+file2);return
    fi1 = open(file1, "rb")
    lines1 = fi1.readlines()
    fi2 = open(file2, "rb")
    lines2 = fi2.readlines()
    fo = open(Outfile, "wb")
    labels = []
    global lst
    for line in range(len(lines2)):
        if lines1[line] != lines2[line]:
            if "Label Label" in lines2[line]:
                lines2[line]=lines2[line].replace("<Label Label=\"","")
                lines2[line]=lines2[line].replace("\"/>","")
                lines2[line]=lines2[line].replace(" ","")
                lines2[line]=lines2[line].replace("\r\n","")
                labels.append(lines2[line])
                fo.write(str(line) +": \n")
                fo.write(lines2[line-2] )
                fo.write(lines2[line-1] )
                fo.write(lines1[line] + lines2[line] )
                
    lst = list(set(labels))
    lst.sort()
    if lst:
        fo.write("#"*30+" \n")
        fo.write("#"*30+" \n")
        if info.MyConf.debug_mode == "STD_ON":print("Info. : Labels Modified are : "+str(len(lst))+ " Ones")
        if info.MyConf.debug_mode == "STD_ON":print("Labels Updated as below ... ")
        fo.write("Info. : Labels Modified are : "+str(len(lst))+ " Ones")
        fo.write("Labels Updated as below ... ")
        for i in lst:
            fo.write(str(lst.index(i)+1)+" :"+i)
            if info.MyConf.debug_mode == "STD_ON":print(str(lst.index(i)+1)+" :"+i) 
        fo.write("#"*30+" \n")
        fo.write("#"*30+" \n")
    else:
        fo.write("No differences after the configuration ....")
        print("No differences after the configuration ....")
    fi1.close()
    fi2.close()
    fo.close()
def test():
    pass
def premain():
    pass
def postmain():
    pass    
def Container():
    WD =os.path.dirname(os.path.abspath(__file__))
    os.chdir(WD)    
    WD =os.path.abspath(info.MyConf.WD)
    os.chdir(WD)      
    global lst
    try:
        premain()
        if info.MyConf.tst_mode == "STD_ON": 
            test()
        else:    
            main()
    except OSError,ValueError:
        AddErr(formatExceptionInfo())
    return (EndingErrLevel , (EndingErrMeg))
    #return (lst)

if __name__ == "__main__":
    Container()
    print(lst)
