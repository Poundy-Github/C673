"""
Filename                  : scons_common_scripts\evm_hil\evm_hil_env\generate_DebugServerScripting.py
Description               : Script used to generate  _CopyDSScriptLoadCmdToClipboard.bat and DebugServerScripting.js 
							which are used to run the debugger and load out files to one or more processor cores.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: evm_hil\evm_hil_env\generate_DebugServerScripting.py
#
# DESCRIPTION: Script used to generate  _CopyDSScriptLoadCmdToClipboard.bat and DebugServerScripting.js 
#              which are used to run the debugger and load out files to one or more processor cores.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: 2013/06/11
#
# LAST CHANGE:      $Date: 2021/12/13 19:05:10CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: generate_DebugServerScripting.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:05:10CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/evm_hil/evm_hil_env/project.pj
# CHANGES:                   Revision 1.4 2016/06/30 10:49:13CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.3 2015/06/26 11:11:15CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 11:11:15 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

import re, os.path, string, errno

def generate_DebugServerScripting(component_name, target_dir, bat_file_name, js_file_name, cortexA8_project, cortexA8_outfile, c674x_outfile, arp32_outfile):
    component = component_name.upper()
    if target_dir:
        dirabs = Dir(target_dir).abspath
        try:
            os.makedirs(dirabs)
        except OSError, e:
            if e.errno != errno.EEXIST:
                raise
            
        f = open(os.path.join(dirabs, js_file_name), "w+")
        f.write("""
// Java-Script for VME-EVM-HIL-Startup
// U.W. -918

importPackage(Packages.org.eclipse.core.resources);    // needed for extraction of project directory
importPackage(Packages.java.lang);
importPackage(Packages.java.io);
importPackage(Packages.java.util); 

var SCRIPT_TIMEOUT = 60; // (seconds)
var CA8_projectName   = "%s";

var CA8_projectPath   = ResourcesPlugin.getWorkspace().getRoot().getProject(CA8_projectName).getLocation();
var C674x_Outfile_DBG = CA8_projectPath + "/../ti_c674x/debug/%s";
var C674x_Outfile_REL = CA8_projectPath + "/../ti_c674x/release/%s";
var CA8_Outfile_DBG   = CA8_projectPath + "/debug/%s";
var CA8_Outfile_REL   = CA8_projectPath + "/release/%s";
        """ % (cortexA8_project, c674x_outfile, c674x_outfile, cortexA8_outfile, cortexA8_outfile))
    
        if arp32_outfile != None:
            f.write("""
    var ARP32_Outfile_DBG = CA8_projectPath + "/../ti_arp32/debug/%s";
    var ARP32_Outfile_REL = CA8_projectPath + "/../ti_arp32/release/%s";
            """ % (arp32_outfile, arp32_outfile))
    
        f.write("""
function VmeEvmHil_PrintStatus()
{
    print("");
    print("VME-EVM-HIL debug server: Script information");
    print("============================================");
    print("Script-timeout:                ", SCRIPT_TIMEOUT, "s");
    print("");
    print("Using CA8 project path:        ", CA8_projectPath);
    print("");
    print("Using CA8_Outfile (Release):   ", CA8_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(CA8_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(CA8_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using CA8_Outfile (Debug):     ", CA8_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(CA8_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(CA8_Outfile_DBG).length()/1000, " kBytes");
    print("");
    print("Using C674x_Outfile (Release): ", C674x_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(C674x_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(C674x_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using C674x_Outfile (Debug):   ", C674x_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(C674x_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(C674x_Outfile_DBG).length()/1000, " kBytes");
    print("");
        """)
    
        if arp32_outfile != None:
            f.write("""
    print("Using ARP32_Outfile (Release): ", ARP32_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(ARP32_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(ARP32_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using ARP32_Outfile (Debug):   ", ARP32_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(ARP32_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(ARP32_Outfile_DBG).length()/1000, " kBytes");
    print("");
            """)
        
        f.write("""
}


function VmeEvmHil_ConnectAllCores(CA8_REL, C674x_REL)
{   
    var statusOK = true;
    
    print("");
    print("VME-EVM-HIL debug server: Connecting all cores and downloading outfiles");
    print("=======================================================================");
  
    if (CA8_REL) {
        CA8_Outfile = CA8_Outfile_REL;
    }
    else {
        CA8_Outfile = CA8_Outfile_DBG;
    }

    if (C674x_REL) {
        C674x_Outfile = C674x_Outfile_REL;
        """)
    
        if arp32_outfile != None:
            f.write("""
        ARP32_Outfile = ARP32_Outfile_REL;
            """)
        
        f.write("""
    }
    else {
        C674x_Outfile = C674x_Outfile_DBG;
        """)
        if arp32_outfile != None:
            f.write("""
        ARP32_Outfile = ARP32_Outfile_DBG;
            """)
        
        f.write("""
    }

    print("");
    print("Script-timeout:           ", SCRIPT_TIMEOUT, "s");
    print("");
    print("Choosen CortexA8 outfile: ", CA8_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(CA8_Outfile).lastModified()));
    print("           size:          ", java.io.File(CA8_Outfile).length()/1000, " kBytes");
    print("");
    print("Choosen C674x outfile:    ", C674x_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(C674x_Outfile).lastModified()));
    print("           size:          ", java.io.File(C674x_Outfile).length()/1000, " kBytes");
    print("");
        """)
    
        if arp32_outfile != None:
            f.write("""
    print("Choosen ARP32 outfile:    ", ARP32_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(ARP32_Outfile).lastModified()));
    print("           size:          ", java.io.File(ARP32_Outfile).length()/1000, " kBytes");
    print("");
            """)
        f.write("""
    script      = env.instance();
    debugServer = script.getServer("DebugServer.1");
    script.setScriptTimeout(SCRIPT_TIMEOUT * 1000);


    try
    {
        print("Open a debug session for CortexA8 on VME...");
        debugSessionCA8     = debugServer.openSession("EMU/CortexA8");

        print("Open a debug session for C674x on VME...");
        debugSessionC674x_0 = debugServer.openSession("EMU/C674X_0");
        """)
    
        if arp32_outfile != None:
            f.write("""
        print("Open a debug session for ARP32 on VME...");
        debugSessionARP32_0 = debugServer.openSession("EMU/ARP32_0");
            """)
        f.write("""
    }
    catch(error)
    {
        print("");
        print("ERROR: Target configuration has not been launched or unexpected EMULATOR/CORE-names in target configuration!");
        print("Detailed exception information:");
        print(error);
        print("");
        print("");
        statusOK = false;
    }

    if (statusOK)
    {
        print("Connect and reset CortexA8...");
        try
        {
            debugSessionCA8.target.connect();
            debugSessionCA8.target.reset();

            print("Connect and reset C674x...");
            debugSessionC674x_0.target.connect();
            debugSessionC674x_0.target.reset();
        """)
        if arp32_outfile != None:
            f.write("""
            print("Connect and reset ARP32...");
            debugSessionARP32_0.target.connect();
            debugSessionARP32_0.target.reset();
            """)
        f.write("""
        }
        catch(error)
        {
            print("");
            print("ERROR: Unable to connect targets! Maybe targets were not disconnected. Other possible reasons: Check previous errors, Script-timeout (", SCRIPT_TIMEOUT, "s), EVM-power...");
            print("Detailed exception information:");
            print(error);
            print("");
            print("");
            statusOK = false;
        }
    }
    
    if (statusOK)
    {
        try
        {
            print("Load outfile on CortexA8...");
            print("    ", CA8_Outfile);
            debugSessionCA8.memory.loadProgram(CA8_Outfile);
            
            print("Load outfile on C674x...");
            print("    ", C674x_Outfile);
            debugSessionC674x_0.memory.loadProgram(C674x_Outfile);
        """)
        if arp32_outfile != None:
            f.write("""
            print("Load outfile on ARP32...");
            print("    ", ARP32_Outfile);
            debugSessionARP32_0.memory.loadProgram(ARP32_Outfile);
            """)
        f.write("""
        }
        catch(error)
        {
            print("");
            print("ERROR: Unable load out-files! Check previous errors, availability of out-files, Script-timeout (", SCRIPT_TIMEOUT, "s), EVM-power...");
            print("Detailed exception information:");
            print(error);
            print("");
            print("");
            statusOK = false;
        }
    }
    print("Done!");
    return;
}

function VmeEvmHil_DisconnectAllCores()
{
    print("");
    print("VME-EVM-HIL debug server: Disconnect all cores...");
    print("=================================================");

    try
    {
        print("Disconnect CortexA8...");
        debugSessionCA8.target.disconnect();

        print("Disconnect C674x...");
        debugSessionC674x_0.target.disconnect();
        """)
        if arp32_outfile != None:
            f.write("""
        print("Disconnect ARP32...");
        debugSessionARP32_0.target.disconnect();
            """)
        f.write("""
    }
    catch(error)
    {
        print("");
        print("ERROR: Unable disconnect targets! A script-based disconnect can only be done, when the cores have been connected via script, before. Other possible root-causes: EVM-power...");
        print("Detailed exception information:");
        print(error);
        print("");
        print("");
    }
    
    print("Done!");
}
        """)
        if arp32_outfile != None:
            f.write("""
hotmenu.addJSFunction("%s VME-EVM-HIL: Print scripting status"                                            , "VmeEvmHil_PrintStatus()");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=debug,   C674x,ARP32=debug)..."    , "VmeEvmHil_ConnectAllCores(false, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=debug,   C674x,ARP32=release)..."  , "VmeEvmHil_ConnectAllCores(false, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=release, C674x,ARP32=debug)..."    , "VmeEvmHil_ConnectAllCores(true, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=release, C674x,ARP32=release)..."  , "VmeEvmHil_ConnectAllCores(true, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Disconnect all cores..."                                           , "VmeEvmHil_DisconnectAllCores()");
            """ % (component, component, component, component, component, component))
        else:
            f.write("""
hotmenu.addJSFunction("%s VME-EVM-HIL: Print scripting status"                                      , "VmeEvmHil_PrintStatus()");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=debug,   C674x=debug)..."    , "VmeEvmHil_ConnectAllCores(false, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=debug,   C674x=release)..."  , "VmeEvmHil_ConnectAllCores(false, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=release, C674x=debug)..."    , "VmeEvmHil_ConnectAllCores(true, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=release, C674x=release)..."  , "VmeEvmHil_ConnectAllCores(true, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Disconnect all cores..."                                     , "VmeEvmHil_DisconnectAllCores()");
            """ % (component, component, component, component, component, component))
        f.close()
        
        f = open(os.path.join(dirabs, bat_file_name), "w+")
        f.write("""
echo off
echo =============================================================
echo This script copies the java-script-command, that is needed to
echo load the debug-server-script into clipboard.
echo Please execute the script and paste clipboard afterwards
echo into the CCS-scripting console. This will register
echo the debug server script in the Eclipse workspace.
echo.
echo U.W., -918
echo =============================================================


set SCRIPT_FILE=DebugServerScripting.js

if not exist %SCRIPT_FILE% goto IllegalFolder

echo loadJSFile "%CD%\%SCRIPT_FILE%" true > temp_ULWA

CLIP < temp_ULWA
del temp_ULWA

echo.
echo The scripting-console-command for registering the Startup-JavaScript into workspace has been stored in clipboard!
echo Please paste it into the CCS-Scripting-Console (ctrl+v)

goto EndOfFile

:IllegalFolder
echo.
echo.
echo ERROR: Current directory must be the folder of java-script-file (CCS-project-directory)!
echo Please start this batch from windows-explorer and NOT from Eclipse-Project-Explorer!
echo.
echo.
pause

:EndOfFile
echo Done!

pause
        """)
        f.close() 
    else:
        print "Please specify target folder"