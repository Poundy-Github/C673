"""
MKS Scripting toolbox: class CheckInMembers_obj

:org:           Continental AG
"""

MEMBER_VERSION = "$Revision: 1.1 $"
print "%s %s" % (__file__, MEMBER_VERSION)

import os
# import copy
# import stat
import sys
import subprocess
import traceback
# import xml.dom.minidom
# import posixpath as posixpath



# import win32com.client
from optparse import OptionParser
# from datetime import datetime, time
# from mks_utils import ProgressBar_obj
from mks_config_tools import mks_obj, logging_obj, xml_obj, ConfigSharedSubProjets_obj

def formatExceptionInfo(maxTBlevel=5):
    cla, exc, trbk = sys.exc_info()
    excName = cla.__name__
    try:
        excArgs = exc.__dict__["args"]
    except KeyError:
        excArgs = "<no args>"
    excTb = traceback.format_tb(trbk, maxTBlevel)
    return (excName, excArgs, excTb)

class RestoreFromProject_obj(ConfigSharedSubProjets_obj, mks_obj, logging_obj, xml_obj):

    """
    Description: Class for automated check-in members
    """

    def __init__(self):
        mks_obj.__init__(self)
        logging_obj.__init__(self)
        xml_obj.__init__(self)
        ConfigSharedSubProjets_obj.__init__(self)
        self.Host = ""
        self.Port = ""
        self.cpid = ""
        # Flag used for  dryrun of MKS commands e.g. ConfigureSharedSubproject
        self.dryrun = False

    def RestoreFromProject(self,argu):
        usage = "to be updated"
        parser = OptionParser(usage)
        parser.add_option("-H", "--Host", dest="Host",
                  help="e.g. mks-psad (mandatory)", metavar="ims-adas")
        parser.add_option("-P", "--Portconfig", dest="Port",
                  help=" e.g. 7001 (mandatory)", metavar="7001")
        parser.add_option("-C", "--ChangePackage", dest="CpId", default="",
                  help="changePackeageID e.g. 33131:1 (mandatory)")
        parser.add_option("-l", "--log", dest="Logging", action="store_true", default=False,
                  help="log(on/off)")
        parser.add_option("-o", "--output", dest="LogDir", default='.\\',
                  help="output log directory")		
        parser.add_option("--SourceSandboxPath", dest="SourceSandboxPath",
                  help="Path of the source sandbox e.g D:\mks\EUNCAP18_ARS4xx\project.pj")
        parser.add_option("--TargetSandboxPath", dest="TargetSandboxPath",
                  help="Path of the target sandbox e.g D:\mks\EUNCAP18_ARS4xx\project.pj")
        parser.add_option("--TargetProjectPath", dest="TargetProjectPath",
                  help="Path of the target project e.g /nfs/projekte1/REPOSITORY/Function_Projects/EUNCAP18/06_Algorithm/project.pj")
        parser.add_option("--TargetDevPath", dest="TargetDevPath", default = "",
                  help="Target development path e.g EUNCAP18_ARS4xx")
        
        '''
        Example arguments:
        -H ims-adas -P 7001 -l -C 505912:1 --SourceSandboxPath=f:\mks\RapidCV_setup\project.pj --TargetSandboxPath=f:\mks\RCV_RapidComputerVisionVehicleDemo\project.pj --TargetProjectPath=/nfs/projekte1/REPOSITORY/Base_Development/RCV_RapidComputerVisionVehicleDemo/project.pj
        '''
        (options, args) = parser.parse_args(argu)
        self.Host = options.Host
        self.Port = options.Port
        self.CpId = options.CpId
        self.Logging = options.Logging
        self.LogDir = options.LogDir
        self.LogFileName = "Logging_RestoreInfo.txt"
        TargetDevPath = options.TargetDevPath
        TargetProjectPath = options.TargetProjectPath
        
        self.UseDatabase = False
        self.LogType["Info"] = 1
        
        error = 0
        
        self.LogType["Info"] = 1
        self.LogType["Debug"] = 1

        error = 0
        # check output log directory
        if ((os.path.isdir(self.LogDir) is False) and (self.Logging is True)):
            self.Log("Error", "log directory does not exist e.g. -o c:\temp \n")
            error = 1
            return error
        else:
            logTypes = {}
            logTypes["Info"] = 1
#            logTypes["Warn"]=2
#            logTypes["Debug"]=3
            if self.Logging is True:
                logfile = os.path.join(self.LogDir, self.LogFileName)
                print "logfile=%s" % (logfile)
                if (os.path.isfile(logfile) is True):
                    if (self.RenameFileAndAddDateTime(logfile) != 0):
                        self.Log("Error", "RenameFileAndAddDateTime fails")

                self.SetupLogging(logfile, "file", self.LogType)
            else:
                self.SetupLogging(logfile, "console", self.LogType)
        
        SourceSandboxPath = options.SourceSandboxPath
        TargetSandboxPath = options.TargetSandboxPath
        
        self.Log("Info","================================================================")
        self.Log("Info","Start getting list of notshared subprojects from Source Sandbox")
        
        notshared_path_list_source, SourceProjectPath, error = self.GetListOfNonSharedSubprojectsFromSandbox(SourceSandboxPath)
        self.Log("Info","SourceProjectPath = "+SourceProjectPath)
        self.Log("Info","Stop getting list of notshared subprojects from Source Sandbox")
        self.Log("Info","================================================================")
        
        
        self.Log("Info","================================================================")
        self.Log("Info","Start getting list of notshared subprojects from Target Sandbox")
        
        notshared_path_list_target, TargetProjectPath, error = self.GetListOfNonSharedSubprojectsFromSandbox(TargetSandboxPath)
        self.Log("Info","TargetProjectPath = "+TargetProjectPath)
        self.Log("Info","Stop getting list of notshared subprojects from Target Sandbox")
        self.Log("Info","================================================================")
        
        self.Log("Info","================================================================")
        self.Log("Info","Missing non-shared subprojects on the target project path as follow\n")
        #Comparison between the projects on the sandboxes
        count = 0
        missing_subprojects_target = []
        c = 0
        for mem in notshared_path_list_source:
            #Test script
            mem = TargetProjectPath+mem[mem.find(SourceProjectPath)+len(SourceProjectPath):]
            if mem not in notshared_path_list_target:
                count += 1
                missing_subprojects_target.append(mem)
                self.Log("Info", mem)
        self.Log("Info","Total missing non-shared subprojects: "+ str(count))
        self.Log("Info","================================================================")
        
        self.Log("Info","================================================================")
        self.Log("Info","Start creating notshared subprojects acquired from Source Sandbox")
        count = 0
        count_error = 0
        uncreated_subprojects = []
        for mem in missing_subprojects_target:
            error= self.CreateSubproject(mem, self.CpId, TargetDevPath)
            #self.Log("Info", "Dummy: Creating subproject - "+mem)
            if error == 0:
                count += 1
            else:
                uncreated_subprojects.append(mem)
                count_error += 1
            
        self.Log("Info","Stop creating notshared subprojects acquired from Source Sandbox")
        self.Log("Info","Number of Subprojects created: "+ str(count))
        self.Log("Info","Number of Subprojects not created due to errors: "+ str(count_error))
        self.Log("Info","================================================================")
        
        if len(uncreated_subprojects) > 0:
            error = 1
            return error
            
        get_pre_cfg_dict = self.ParseForSharedSandboxProject(SourceSandboxPath, False, True)
        
        if get_pre_cfg_dict == 1:
            self.Log("Error", "Couldnot get shared project Dictionary")
            error = 1
            return error
        else:
            SharedProjectDict = self.PreConfigSharedProjectDict
        
        missing_subprojects = []
        count  = 0
        for path in SharedProjectDict:
            shared_path = SharedProjectDict[path]['SharedPath']
            target_path = TargetProjectPath+path[path.find(SourceProjectPath)+len(SourceProjectPath):]
            
            temp_str = target_path[:target_path.rfind('/')]
            temp_str = temp_str[:temp_str.rfind('/')]
            temp_str = temp_str+'/project.pj'
            path_exist = self.GetProjectView(temp_str, TargetDevPath) # works but implementation to be investigated
            
            self.Log("Info","Source Project Path:        %s" % path)
            self.Log("Info","Target Project Path: %s" % target_path)
            if path_exist == None:
                missing_subprojects.append(temp_str)
            self.Log("Info","Shared Path:         %s \n" % shared_path)
            
            '''
            ################## Work Around - to be removed #################
            find_path_1 = '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/RSP_ARS4xxRawSignalProcessing'
            find_1=  shared_path.find(find_path_1)
            replace_path_1 = '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/RSP_ARS_SRR_500_SignalProcessing'
            
            find_path_2 = '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SPT_SignalProcessingToolBox' 
            find_2 =  shared_path.find(find_path_2)
            replace_path_2 = '/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SPT_ARS_SRR_500_ProcessingToolbox'
            
            
            if find_1 != -1:
                shared_path = replace_path_1+shared_path[len(find_path_1):]
                self.Log("Info","New Shared Path:     %s \n" % shared_path)
                SharedProjectDict[path]['SharedPath'] = shared_path
        
            if find_2 != -1:
                shared_path = replace_path_2+shared_path[len(find_path_2):]
                self.Log("Info","New Shared Path:     %s \n" % shared_path)
                SharedProjectDict[path]['SharedPath'] = shared_path
            '''
            #######################################################################################
            #self.Log("Info","Dummy: Adding shared subproject - "+ shared_path)
            #self.Log("Info","Dummy: Target for shared subproject - "+ target_path)
            self.AddSharedSubProject(shared_path, target_path, TargetDevPath, None, '1.1', "build")
            #######################################################################################
            count+=1
            
        self.Log("Info"," \n ==========================================\n Number of newly Shared Subprojects: %s \n ==========================================" % count)
            
            
        self.Log("Info"," \n =================================================================================================================")
        missing_subprojects = list(set(missing_subprojects))
        num_missing_subprojs = len(missing_subprojects)
        if num_missing_subprojs > 0:
            for missing_subproj in missing_subprojects:
                self.Log("Info","Non existing subprojects:         %s \n" % missing_subproj)
                self.Log("Info"," \n ==========================================\n Number of still non existing Subprojects: %s \n ==========================================" % num_missing_subprojs)
                error = 1
                return error
        return error