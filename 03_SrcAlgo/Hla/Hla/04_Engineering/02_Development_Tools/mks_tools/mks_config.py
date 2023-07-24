"""
MKS Scripting tool for configuration of sandboxes and projects

Features:
---------

ConfigSharedSubProjects:
------------------------

  Options:
  -h, --help            show this help message and exit
  -H liss014.auto.contiwan.com, --Host=liss014.auto.contiwan.com
                        e.g. liss014.auto.contiwan.com (mandatory)
  -P 6001, --Portconfig=6001
                         e.g. 6001 (mandatory)
  -C CPID, --ChangePackage=CPID
                        changePackeageID e.g. 33131:1 (mandatory)
  -t normal, --type=normal
                        Type(normal/variant/build) (mandatory)
  -c FILE, --config=FILE
                        configuration file name (mandatory)
  -s SANDBOX, --sandbox=SANDBOX
                        sandbox(the direcory of the sandbox which should be
                        configured with the starting project.pj file)
                        (mandatory or project)
  -p PROJECT, --project=PROJECT
                        project(the mks direcory of the project) (mandatory or sandbox)
  -d ACTDEVPATH, --devpath=ACTDEVPATH
                        Development path e.g SMR200_SRR-BSD_G30_A1_V2
  -l, --log             log(on/off)
  -o LOGDIR, --output=LOGDIR
                        logging outputfolder

CheckIfAllBuild:
------------------------

  Options:
  -h, --help            show this help message and exit
  -H liss014.auto.contiwan.com, --Host=liss014.auto.contiwan.com
                        e.g. liss014.auto.contiwan.com (mandatory)
  -P 6001, --Portconfig=6001
                         e.g. 6001 (mandatory)
  -C CPID, --ChangePackage=CPID
                        changePackeageID e.g. 33131:1 (mandatory)
  -s SANDBOX, --sandbox=SANDBOX
                        sandbox(the direcory of the sandbox which should be
                        configured with the starting project.pj file)
                        (mandatory or project)
  -p PROJECT, --project=PROJECT
                        project(the mks direcory of the project) (mandatory or sandbox)
  -d ACTDEVPATH, --devpath=ACTDEVPATH
                        Development path e.g SMR200_SRR-BSD_G30_A1_V2
  -l, --log             log(on/off)
  -o LOGDIR, --output=LOGDIR
                        logging outputfolder


:org:           Continental AG
:author:        Jochen Spruck
:version:       $Revision: 1.19 $
:date:          $Date: 2017/04/25 18:18:25CEST $

"""
import sys
from mks_config_tools import CheckIfAllBuild_obj, mks_obj, ConfigSharedSubProjets_obj, AddPreIntCheckpoint_obj, RenameAllCheckpointLabels_obj, CheckAlgoIntegration_obj, CompareCheckpoints_obj, SyncMksPathes_obj, AddProjectLabelRecursive_obj, RetargetAndResynchSbx_obj, CheckoutSubProjectByLabel_obj
from mks_config_ci import CheckInMembers_obj
from mks_restore_from_project import RestoreFromProject_obj

def PrintHelp():
    """
    PrintHelp()

    Description: Print the Help menu
    """
    print """Usage:
    python mks_config.py ConfigSharedSubProjects [options e.g. -h for help]
    or python mks_config.py CheckIfAllBuild [options e.g. -h for help]
    or python mks_config.py AddPreIntCheckpoint [options e.g. -h for help]
    or python mks_config.py RestorePreIntCheckpointFromXML [options e.g. -h for help]
    or python mks_config.py RenameAllCheckpointLabels [options e.g. -h for help]
    """
#    print "example config xml file:"
#    print "<?xml version=""1.0"" encoding=""UTF-8""?>"
#    print "   <ConfigSharedProjects>"
#    print "      <BaseConfig>"
#    print "         <SharedProject CompName=""RSP_ARS301based_RawSignalProcessing"">"
#    print "            <Config Type=""normal""/>"
#    print "            <Config DevPathName="" Type=""variant""/>"
#    print "            <Config Label="" Revision=""1.1"" Type=""build""/>"
#    print "         </SharedProject>"
#    print "      </BaseConfig>"
#    print "      <CustomConfig>"
#    print "         <SharedProject SharedPath=""/nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/VDY_VehicleDynamics/04_Engineering/01_Source_Code/algo/00_Custom/vdy/project.pj"">"
#    print "            <Config Type=""normal""/>"
#    print "            <Config DevPathName="" Type=""variant""/>"
#    print "            <Config Label=""SMR200_cm-update_20.11.2009"" Revision=""1.5"" Type=""build""/>"
#    print "         </SharedProject>"
#    print "      </CustomConfig>"
#    print "   </ConfigSharedProjects>"

def main(argv):
    """
    main()

    Description: the main function
    """
    res = 0
    if (argv[1] == "AddPreIntCheckpoint"):
        if len(argv) < 3:
            argv.append("-h")
        AddPreIntCheckpoint_obj().AddPreIntCheckpoint(argv)
        sys.exit()
    elif (argv[1] == "RestorePreIntCheckpointFromXML"):
        if len(argv) < 3:
            argv.append("-h")
        AddPreIntCheckpoint_obj().RestorePreIntCheckpointFromXML(argv)
        sys.exit()
    elif (argv[1] == "CheckIfAllBuild"):
        if len(argv) < 3:
            argv.append("-h")
        res = CheckIfAllBuild_obj().CheckIfAllBuild(argv)
        sys.exit(res)
    elif (argv[1] == "ConfigSharedSubProjects"):
        if len(argv) < 3:
            argv.append("-h")
        res = ConfigSharedSubProjets_obj().ConfigSharedSubProjects(argv)
        sys.exit(res)
    elif (argv[1] == "RenameAllCheckpointLabels"):
        if len(argv) < 3:
            argv.append("-h")
        RenameAllCheckpointLabels_obj().RenameAllCheckpointLabels(argv)
        sys.exit()
    elif (argv[1] == "CheckCurrentDevPathWithXmlPath"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CheckCurrentDevPathWithXmlPath(argv)
        sys.exit()
    elif (argv[1] == "CheckDLLVersionP1NotSmallerP2"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CheckDLLVersionP1NotSmallerP2(argv)
        sys.exit()
    elif (argv[1] == "CheckDLLVersionWithXmlLabel"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CheckDLLVersionWithXmlLabel(argv)
        sys.exit()
    elif (argv[1] == "CheckIfSharedSubSubsandboxBuild"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CheckIfSharedSubSubsandboxBuild(argv)
        sys.exit()
    elif (argv[1] == "CheckIsInputyn"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CheckIsInputyn(argv)
        sys.exit()
    elif (argv[1] == "CheckProjectType"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CheckProjectType(argv)
        sys.exit()
    elif (argv[1] == "CheckSameFile"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CheckSameFile(argv)
        sys.exit()
    elif (argv[1] == "CheckSameFolder"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CheckSameFolder(argv)
        sys.exit()
    elif (argv[1] == "CompareDLLVersion"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CompareDLLVersion(argv)
        sys.exit()
    elif (argv[1] == "CompareSandboxWithProject"):
        if len(argv) < 3:
            argv.append("-h")
        CheckAlgoIntegration_obj().CompareSandboxWithProject(argv)
        sys.exit()
    elif (argv[1] == "CompareCheckpoints"):
        if len(argv) < 3:
            argv.append("-h")
        CompareCheckpoints_obj().CompareCheckpoints(argv)
        sys.exit()
    elif (argv[1] == "SyncMksPathes"):
        if len(argv) < 3:
            argv.append("-h")
        SyncMksPathes_obj().SyncMksPathes(argv)
        sys.exit()
    elif (argv[1] == "AddProjectLabelRecursive"):
        if len(argv) < 3:
            argv.append("-h")
        AddProjectLabelRecursive_obj().AddProjectLabel(argv)
        sys.exit()
    elif (argv[1] == "RetargetAndResynchSbx"):
        if len(argv) < 3:
            argv.append("-h")
        res = RetargetAndResynchSbx_obj().RetargetAndResynchSbx(argv)
        sys.exit(res)
    elif (argv[1] == "CheckInMembers"):
        if len(argv) < 3:
            argv.append("-h")
        res = CheckInMembers_obj().CheckInMembers(argv)
        sys.exit(res)
    elif (argv[1] == "GetPreConfigSharesProjects"):
        if len(argv) < 3:
            argv.append("-h")
        res = ConfigSharedSubProjets_obj().GetPreConfigSharesProjects(argv)
        sys.exit(res)
    elif (argv[1] == "UpdateConfig"):
        if len(argv) < 3:
            argv.append("-h")
        res = ConfigSharedSubProjets_obj().UpdateConfig(argv)
        sys.exit(res)
    elif (argv[1] == "CheckPostConfig"):
        if len(argv) < 3:
            argv.append("-h")
        res = ConfigSharedSubProjets_obj().CheckPostConfig(argv)
        sys.exit(res)
    elif (argv[1] == "RestoreFromProject"):
        if len(argv) < 3:
            argv.append("-h")
        print argv
        res = RestoreFromProject_obj().RestoreFromProject(argv)
        sys.exit(res)
    else:
        PrintHelp()

    sys.exit(res)

# check input args
if (len(sys.argv) > 1):
    main(sys.argv)
else:
    PrintHelp()


"""
CHANGE LOG:
-----------
$Log: mks_config.py  $
Revision 1.19 2017/04/25 18:18:25CEST uidg4889 
Merging from GIT 2017/1.027
Revision 1.18 2016/09/16 16:26:43CEST Azam, Saad (uidg4889) 
Fixes related to mks_restore_from_project script
Revision 1.17 2016/05/18 10:48:58CEST Azam, Saad (uidg4889) 
Added entry for option "RestoreFromProject"
Revision 1.16 2016/02/02 13:25:11CET Sinnwell-EXT, Wolfgang (uidj6607) 
added CheckPostConfig()
Revision 1.15 2015/08/26 11:28:51CEST Sinnwell-EXT, Wolfgang (uidj6607) 
fixed return value of CheckIfAllBuild
--- Added comments ---  uidj6607 [Aug 26, 2015 11:28:52 AM CEST]
Change Package : 269733:1 http://mks-psad:7002/im/viewissue?selection=269733
Revision 1.14 2015/08/25 13:26:55CEST Sinnwell-EXT, Wolfgang (uidj6607) 
fixed return values
added GetPreConfigSharesProjects()
added UpdateConfig()
--- Added comments ---  uidj6607 [Aug 25, 2015 1:26:55 PM CEST]
Change Package : 269733:1 http://mks-psad:7002/im/viewissue?selection=269733
Revision 1.13.1.3 2015/08/10 17:34:06CEST Sinnwell-EXT, Wolfgang (uidj6607) 
fixed return of CheckInMembers()
--- Added comments ---  uidj6607 [Aug 10, 2015 5:34:07 PM CEST]
Change Package : 269733:1 http://mks-psad:7002/im/viewissue?selection=269733
Revision 1.13.1.2 2015/07/28 10:52:08CEST Azam, Saad (uidg4889) 
elif (argv[1] == "CheckInMembers"):
        if len(argv) < 3:
          argv.append("-h")
        CheckInMembers_obj().CheckInMembers(argv)
        sys.exit()
--- Added comments ---  uidg4889 [Jul 28, 2015 10:52:09 AM CEST]
Change Package : 279146:1 http://mks-psad:7002/im/viewissue?selection=279146
Revision 1.13.1.1 2015/06/15 17:30:55CEST Azam, Saad (uidg4889) 
Update for CheckInMember functions
--- Added comments ---  uidg4889 [Jun 15, 2015 5:30:56 PM CEST]
Change Package : 279146:1 http://mks-psad:7002/im/viewissue?selection=279146
Revision 1.13 2014/02/25 15:00:45CET Gressmann, Markus (uidw1565) 
added CheckoutSubProjectByLabel and RetargetAndResynchSbx
--- Added comments ---  uidw1565 [Feb 25, 2014 3:00:45 PM CET]
Change Package : 188681:2 http://mks-psad:7002/im/viewissue?selection=188681
Revision 1.12 2013/07/03 16:56:23CEST Friebertshaeuser, Markus (uidt0551) 
Added option to apply project labels recursive for specific checkpoint
--- Added comments ---  uidt0551 [Jul 3, 2013 4:56:23 PM CEST]
Change Package : 162889:10 http://mks-psad:7002/im/viewissue?selection=162889
Revision 1.11 2013/02/05 09:17:21CET Spruck, Jochen (spruckj) 
Add SyncMksPathes
--- Added comments ---  spruckj [Feb 5, 2013 9:17:21 AM CET]
Change Package : 162889:25 http://mks-psad:7002/im/viewissue?selection=162889
Revision 1.10 2012/03/16 08:48:25CET uidt9433 
New AddPreIntCheckpoint_obj Function added:
        
        RestorePreIntCheckpointFromXML(self,argu)
	
	If AddPreIntCheckpoint fails you can restore the old 
	configuration from pre_config_shared_project_preint.xml now
--- Added comments ---  uidt9433 [Mar 16, 2012 8:48:25 AM CET]
Change Package : 97470:1 http://mks-psad:7002/im/viewissue?selection=97470
Revision 1.9 2012/03/12 09:57:36CET Hotjakov-EXT, Ilja (uidt9433) 
New CheckAlgoIntegration_obj class added with following main functions:
	
	CheckCurrentDevPathWithXmlPath(argv)
	CheckDLLVersionP1NotSmallerP2(argv)
	CheckDLLVersionWithXmlLabel(argv)
	CheckIfSharedSubSubsandboxBuild(argv)
	CheckIsInputyn(argv)
	CheckProjectType(argv)
	CheckSameFile(argv)
	CheckSameFolder(argv)
	CompareDLLVersion(argv)
	CompareSandboxWithProject(argv)
--- Added comments ---  uidt9433 [Mar 12, 2012 9:57:42 AM CET]
Change Package : 97470:1 http://mks-psad:7002/im/viewissue?selection=97470
Revision 1.8 2012/02/09 13:05:30CET Spruck, Jochen (spruckj)
Add new mks si / im script to if all tasks with working packages are assigned to releases
--- Added comments ---  spruckj [Feb 9, 2012 1:05:41 PM CET]
Change Package : 46866:11 http://mks-psad:7002/im/viewissue?selection=46866
Revision 1.7 2010/09/10 14:57:54CEST Jochen Spruck (spruckj)
Update to new version of mks tools
--- Added comments ---  spruckj [Sep 10, 2010 2:57:54 PM CEST]
Change Package : 46866:1 http://mks-psad:7002/im/viewissue?selection=46866
"""
