"""
Filename                  :  scons_adas_extensions\generate_DebugServerScripting.py
Description               :  Script used to generate  _CopyDSScriptLoadCmdToClipboard.bat and DebugServerScripting.js
                             which are used to run the debugger and load out files to one or more processor cores.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: generate_DebugServerScripting.py
#
# DESCRIPTION: Script used to generate  _CopyDSScriptLoadCmdToClipboard.bat and DebugServerScripting.js 
#              which are used to run the debugger and load out files to one or more processor cores.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/10/07
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:54CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: generate_DebugServerScripting.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:54CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.13 2016/05/27 11:48:25CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.12 2015/11/05 05:58:24CET Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Reolved the issue with c674x core while writing the .js file.
# CHANGES:                   - Added comments -  uidr0826 [Nov 5, 2015 5:58:25 AM CET]
# CHANGES:                   Change Package : 393421:1 http://mks-psad:7002/im/viewissue?selection=393421
# CHANGES:                   Revision 1.11 2015/11/04 11:33:43CET Bhagawati, Tridip (uidr2134) 
# CHANGES:                   Build-target for pure ARM-simulation needed
# CHANGES:                   --- Added comments ---  uidr2134 [Nov 4, 2015 11:33:43 AM CET]
# CHANGES:                   Change Package : 392739:1 http://mks-psad:7002/im/viewissue?selection=392739
# CHANGES:                   Revision 1.10 2015/06/29 14:56:01CEST Stark-EXT, Roland (uidw1169) 
# CHANGES:                   Fixed generation of CM4 connection function if only C66xx is active.
# CHANGES:                   --- Added comments ---  uidw1169 [Jun 29, 2015 2:56:02 PM CEST]
# CHANGES:                   Change Package : 351977:1 http://mks-psad:7002/im/viewissue?selection=351977
# CHANGES:                   Revision 1.9 2015/06/29 13:35:44CEST Stark-EXT, Roland (uidw1169) 
# CHANGES:                   Added support for CortexM3 and M4
# CHANGES:                   --- Added comments ---  uidw1169 [Jun 29, 2015 1:35:44 PM CEST]
# CHANGES:                   Change Package : 351977:1 http://mks-psad:7002/im/viewissue?selection=351977
# CHANGES:                   Revision 1.8 2015/06/26 05:17:21CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:21 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

import re, os.path, string, errno

def generate_DebugServerScripting(component_name, target_dir, bat_file_name, js_file_name, cortexA8_project, cortexA8_outfile, c674x_outfile, arp32_outfile, 
                                  arp32miniapp_outfile, cortexM3_outfile = None):
    """
    Function                         :  generate_DebugServerScripting
    Description                      :  To generate DebugServerScripting.js for VME.
    component_name                   :  algo name
    target_dir                       :  Directory to where output(.js) will be created.
    bat_file_name                    :  Usually "_CopyDSScriptLoadCmdToClipboard.bat". Get generated in target_dir.
    js_file_name                     :  Usually "DebugServerScripting.js". Get generated in target_dir.
    cortexA8_project                 :  project file of cortexA8.
    cortexA8_outfile                 :  .out file generated for cortexA8.
    c674x_outfile                    :  .out file generated for c674x.
    arp32_outfile                    :  .out file generated for arp32.
    arp32miniapp_outfile             :  .out file generated for arp32miniapp.
    cortexM3_outfile                 :  .out file generated for cortexM3.
    Returns                          :  
    """
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

var CA8_projectPath   = ResourcesPlugin.getWorkspace().getRoot().getProject(CA8_projectName).getLocation();""" % (cortexA8_project))
    
        if cortexM3_outfile != None:
            f.write("""
var CM3_Outfile_DBG = CA8_projectPath + "/../ti_cortex_m3/debug/%s";
var CM3_Outfile_REL = CA8_projectPath + "/../ti_cortex_m3/release/%s";""" % (cortexM3_outfile, cortexM3_outfile))
        # C674x
        if c674x_outfile != None: 
            f.write("""
var C674x_Outfile_DBG = CA8_projectPath + "/../ti_c674x/debug/%s";
var C674x_Outfile_REL = CA8_projectPath + "/../ti_c674x/release/%s";""" % (c674x_outfile, c674x_outfile))
        
        f.write("""
var CA8_Outfile_DBG   = CA8_projectPath + "/debug/%s";
var CA8_Outfile_REL   = CA8_projectPath + "/release/%s";
        """ % (cortexA8_outfile, cortexA8_outfile))
    
        if arp32_outfile != None:
            f.write("""
var ARP32_Outfile_DBG = CA8_projectPath + "/../ti_arp32/debug/%s";
var ARP32_Outfile_REL = CA8_projectPath + "/../ti_arp32/release/%s";""" % (arp32_outfile, arp32_outfile))
        
        if arp32miniapp_outfile != None:
            f.write("""
var ARP32miniapp_Outfile_DBG = CA8_projectPath + "/../ti_arp32_miniapp/debug/%s";
var ARP32miniapp_Outfile_REL = CA8_projectPath + "/../ti_arp32_miniapp/release/%s";""" % (arp32miniapp_outfile, arp32miniapp_outfile))

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
        """)
    
        if cortexM3_outfile != None:
            f.write("""
    print("Using CM3_Outfile (Release):   ", CM3_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(CM3_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(CM3_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using CM3_Outfile (Debug):     ", CM3_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(CM3_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(CM3_Outfile_DBG).length()/1000, " kBytes");
    print("");
        """)
        # C674x
        if c674x_outfile != None: 
            f.write("""
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
			
        if arp32miniapp_outfile != None:
            f.write("""
    print("Using ARP32miniapp_Outfile (Release): ", ARP32miniapp_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(ARP32miniapp_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(ARP32miniapp_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using ARP32miniapp_Outfile (Debug):   ", ARP32miniapp_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(ARP32miniapp_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(ARP32miniapp_Outfile_DBG).length()/1000, " kBytes");
    print("");
            """)       
        
        f.write("""
}


function VmeEvmHil_ConnectAllCores(CA8_REL, ALGO_CORE_REL)
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

    if (ALGO_CORE_REL) {""")
        if cortexM3_outfile != None:
            f.write("""
        CM3_Outfile = CM3_Outfile_REL;
        """)
        # C674x
        if c674x_outfile != None: 
            f.write("""
        C674x_Outfile = C674x_Outfile_REL;
        """)
    
        if arp32_outfile != None:
            f.write("""
        ARP32_Outfile = ARP32_Outfile_REL;
            """)
        
        f.write("""
    }
    else {""")
        if cortexM3_outfile != None:
            f.write("""
        CM3_Outfile = CM3_Outfile_DBG;
        """)
        # C674x
        if c674x_outfile != None: 
            f.write("""
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
        """)
    
        if cortexM3_outfile != None:
            f.write("""
    print("Choosen CortexM3 outfile: ", CM3_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(CM3_Outfile).lastModified()));
    print("           size:          ", java.io.File(CM3_Outfile).length()/1000, " kBytes");
    print("");
        """)
        # C674x
        if c674x_outfile != None: 
            f.write("""
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
        """)
    
        if cortexM3_outfile != None:
            f.write("""
        print("Open a debug session for CortexM3 on VME...");
        debugSessionCM3_0 = debugServer.openSession("EMU/Cortex_M3_RTOS");
        """)
        # C674x
        if c674x_outfile != None: 
            f.write("""
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
        """)
        if cortexM3_outfile != None:
            f.write("""
            print("Connect and reset CortexM3...");
            debugSessionCM3_0.target.connect();
            debugSessionCM3_0.target.reset();
        """)
        # C674x
        if c674x_outfile != None: 
            f.write("""
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
        """)
        if cortexM3_outfile != None:
            f.write("""
            print("Load outfile on CortexM3...");
            print("    ", CM3_Outfile);
            debugSessionCM3_0.memory.loadProgram(CM3_Outfile);
        """)
        # C674x
        if c674x_outfile != None: 
            f.write("""
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

function VmeEvmHil_ConnectStandAloneCores(CA8_REL, ALGO_CORE_REL)
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

    if (ALGO_CORE_REL) {""")
        if arp32miniapp_outfile != None:
            f.write("""
        ARP32miniapp_Outfile = ARP32miniapp_Outfile_REL;
            """)
			
        f.write("""
    }
    else {""")
        if arp32miniapp_outfile != None:
            f.write("""
        ARP32miniapp_Outfile = ARP32miniapp_Outfile_DBG;
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
        """)
    
        if cortexM3_outfile != None:
            f.write("""
    print("Choosen CortexM3 outfile: ", CM3_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(CM3_Outfile).lastModified()));
    print("           size:          ", java.io.File(CM3_Outfile).length()/1000, " kBytes");
    print("");
        """)
        
        if arp32miniapp_outfile != None:
            f.write("""
    print("Choosen ARP32 miniapp outfile:    ", ARP32miniapp_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(ARP32miniapp_Outfile).lastModified()));
    print("           size:          ", java.io.File(ARP32miniapp_Outfile).length()/1000, " kBytes");
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
        """)
    
        if cortexM3_outfile != None:
            f.write("""
        print("Open a debug session for CortexM3 on VME...");
        debugSessionCM3_0 = debugServer.openSession("EMU/Cortex_M3_RTOS");
        """)
        
        if arp32miniapp_outfile != None:
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
        """)
        if cortexM3_outfile != None:
            f.write("""
            print("Connect and reset CortexM3...");
            debugSessionCM3_0.target.connect();
            debugSessionCM3_0.target.reset();
        """)
        if arp32miniapp_outfile != None:
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
        """)
        if arp32miniapp_outfile != None:
            f.write("""
            print("Load outfile on ARP32...");
            print("    ", ARP32miniapp_Outfile);
            debugSessionARP32_0.memory.loadProgram(ARP32miniapp_Outfile);
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
    try
    {""")
        if cortexM3_outfile != None:
            f.write("""
        print("Disconnect CortexM3...");
        debugSessionCM3_0.target.disconnect();
        """)
        # C674x
        if c674x_outfile != None: 
            f.write("""
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
    }""")
        if arp32_outfile != None or arp32miniapp_outfile != None:
            f.write("""
    try
    {
        print("Disconnect ARP32...");
        debugSessionARP32_0.target.disconnect();
    }
    catch(error)
    {
        print("");
        print("ERROR: Unable disconnect targets! A script-based disconnect can only be done, when the cores have been connected via script, before. Other possible root-causes: EVM-power...");
        print("Detailed exception information:");
        print(error);
        print("");
        print("");
    }""")
        f.write("""    
    print("Done!");
}
        """)
        if cortexM3_outfile != None:
            if arp32_outfile != None:
                f.write("""
hotmenu.addJSFunction("%s VME-EVM-HIL: Print scripting status"                                            , "VmeEvmHil_PrintStatus()");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=debug,   CM3,ARP32=debug)..."    , "VmeEvmHil_ConnectAllCores(false, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=debug,   CM3,ARP32=release)..."  , "VmeEvmHil_ConnectAllCores(false, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=release, CM3,ARP32=debug)..."    , "VmeEvmHil_ConnectAllCores(true, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=release, CM3,ARP32=release)..."  , "VmeEvmHil_ConnectAllCores(true, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Disconnect all cores..."                                           , "VmeEvmHil_DisconnectAllCores()");
            """ % (component, component, component, component, component, component))
            else:
                f.write("""
hotmenu.addJSFunction("%s VME-EVM-HIL: Print scripting status"                                      , "VmeEvmHil_PrintStatus()");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=debug,   CM3=debug)..."    , "VmeEvmHil_ConnectAllCores(false, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=debug,   CM3=release)..."  , "VmeEvmHil_ConnectAllCores(false, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=release, CM3=debug)..."    , "VmeEvmHil_ConnectAllCores(true, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect and load all cores (CA8=release, CM3=release)..."  , "VmeEvmHil_ConnectAllCores(true, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Disconnect all cores..."                                     , "VmeEvmHil_DisconnectAllCores()");
            """ % (component, component, component, component, component, component))
            if arp32miniapp_outfile != None:
                f.write("""
hotmenu.addJSFunction("%s VME-EVM-HIL: Print scripting status"                                            , "VmeEvmHil_PrintStatus()");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect A8 and load EVE (CA8, ARP32=debug)..."     , "VmeEvmHil_ConnectAllCores(false, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect A8 and load EVE (CA8=, ARP32=release)..."  , "VmeEvmHil_ConnectAllCores(false, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Disconnect all cores..."                                           , "VmeEvmHil_DisconnectAllCores()");
            """ % (component, component, component, component))
        else: # C674x
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
            if arp32miniapp_outfile != None:
                f.write("""
hotmenu.addJSFunction("%s VME-EVM-HIL: Print scripting status"                                            , "VmeEvmHil_PrintStatus()");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect A8 and load EVE (CA8, ARP32=debug)..."     , "VmeEvmHil_ConnectStandAloneCores(false, false)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Connect A8 and load EVE (CA8, ARP32=release)..."   , "VmeEvmHil_ConnectStandAloneCores(false, true)");
hotmenu.addJSFunction("%s VME-EVM-HIL: Disconnect all cores..."                                           , "VmeEvmHil_DisconnectAllCores()");
            """ % (component, component, component, component))
        f.close()
        
        # also generate a batch file that copies script to console
        generate_BatchFile(dirabs, bat_file_name);
    else:
        print "Please specify target folder"
        
        
def generate_DebugServerScriptingVH28(component_name, target_dir, bat_file_name, js_file_name, cortexM4_project, cortexM4_outfile, cortexA15_outfile, c66xx_outfile, arp32_outfile, arp32e1miniapp_outfile):
    """
    Function                            :  generate_DebugServerScriptingVH28
    Description                         :  To generate DebugServerScripting.js for VH28.
    component_name                      :  algo name
    target_dir                          :  Directory to where output(.js) will be created.
    bat_file_name                       :  Usually "_CopyDSScriptLoadCmdToClipboard.bat". Get generated in target_dir.
    js_file_name                        :  Usually "DebugServerScripting.js". Get generated in target_dir.
    cortexM4_project                    :  project file of cortexM4.
    cortexM4_outfile                    :  .out file generated for cortexM4.
    cortexA15_outfile                   :  .out file generated for cortexA15.
    c66xx_outfile                       :  .out file generated for c66xx.
    arp32_outfile                       :  .out file generated for arp32.
    arp32e1miniapp_outfile              :  .out file generated for arp32miniapp.
    Returns                             :  
    """
    component = component_name.upper()
    if target_dir:
        dirabs = Dir(target_dir).abspath
        try:
            os.makedirs(dirabs)
        except OSError, e:
            if e.errno != errno.EEXIST:
                raise
            
        f = open(os.path.join(dirabs, js_file_name), "w+")
        f.write("""// Java-Script for VH28-EVM-HIL-Startup of CIPP
// Roland Stark (ITK) +49 69 8700008 290
// Based on VME version (U.W. -918)

importPackage(Packages.org.eclipse.core.resources);    // needed for extraction of project directory
importPackage(Packages.java.lang);
importPackage(Packages.java.io);
importPackage(Packages.java.util); 

var SCRIPT_TIMEOUT    = 60; // (seconds)

var CM4_projectName   = "%s";
var CM4_projectPath   = ResourcesPlugin.getWorkspace().getRoot().getProject(CM4_projectName).getLocation();

var CM4_Outfile_DBG   = CM4_projectPath + "/debug/%s";
var CM4_Outfile_REL   = CM4_projectPath + "/release/%s";""" % (cortexM4_project, cortexM4_outfile, cortexM4_outfile))
        if cortexA15_outfile != None:
            f.write("""
var CA15_Outfile_DBG  = CM4_projectPath + "/../ti_cortex_a15/debug/%s";
var CA15_Outfile_REL  = CM4_projectPath + "/../ti_cortex_a15/release/%s";""" % (cortexA15_outfile, cortexA15_outfile))
        if c66xx_outfile != None:
            f.write("""
var C66xx_Outfile_DBG = CM4_projectPath + "/../ti_c66xx/debug/%s";
var C66xx_Outfile_REL = CM4_projectPath + "/../ti_c66xx/release/%s";""" % (c66xx_outfile, c66xx_outfile))
        if arp32_outfile != None:
            f.write("""
var ARP32e1_Outfile_DBG = CM4_projectPath + "/../ti_arp32_vh28e1/debug/%s";
var ARP32e1_Outfile_REL = CM4_projectPath + "/../ti_arp32_vh28e1/release/%s";""" % (arp32_outfile, arp32_outfile))
        if arp32miniapp_outfile != None:
            f.write("""
var ARP32e1miniapp_Outfile_DBG = CM4_projectPath + "/../ti_arp32_vh28e1_miniapp/debug/%s";
var ARP32e1miniapp_Outfile_REL = CM4_projectPath + "/../ti_arp32_vh28e1_miniapp/release/%s";""" % (arp32e1miniapp_outfile, arp32e1miniapp_outfile))
        f.write("""

var DSP_MODE = false;

function VH28EvmHil_PrintStatus()
{
    print("");
    print("VH28-EVM-HIL debug server: Script information");
    print("=============================================");
    print("Script-timeout:                ", SCRIPT_TIMEOUT, "s");
    print("");
    print("Using CM4 project path:        ", CM4_projectPath);
    print("");
    print("Using CM4_Outfile (Release):   ", CM4_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(CM4_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(CM4_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using CM4_Outfile (Debug):     ", CM4_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(CM4_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(CM4_Outfile_DBG).length()/1000, " kBytes");
    print("");""")
        if cortexA15_outfile != None:
            f.write("""
    print("Using CA15_Outfile (Release):  ", CA15_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(CA15_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(CA15_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using CA15_Outfile (Debug):    ", CA15_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(CA15_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(CA15_Outfile_DBG).length()/1000, " kBytes");
    print("");""")
        if c66xx_outfile != None:
            f.write("""
    print("Using C66xx_Outfile (Release): ", C66xx_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(C66xx_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(C66xx_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using C66xx_Outfile (Debug):   ", C66xx_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(C66xx_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(C66xx_Outfile_DBG).length()/1000, " kBytes");
    print("");""")
        if arp32_outfile != None:
            f.write("""
    print("Using ARP32_Outfile (Release): ", ARP32e1_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(ARP32e1_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(ARP32e1_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using ARP32_Outfile (Debug):   ", ARP32e1_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(ARP32e1_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(ARP32e1_Outfile_DBG).length()/1000, " kBytes");
    print("");""")
        if arp32e1miniapp_outfile != None:
            f.write("""
    print("Using ARP32e1miniapp_Outfile (Release): ", ARP32e1miniapp_Outfile_REL);
    print("           last modified:      ", java.util.Date(java.io.File(ARP32e1miniapp_Outfile_REL).lastModified()));
    print("           size:               ", java.io.File(ARP32e1miniapp_Outfile_REL).length()/1000, " kBytes");
    print("");
    print("Using ARP32e1miniapp_Outfile (Debug):   ", ARP32e1miniapp_Outfile_DBG);
    print("           last modified:      ", java.util.Date(java.io.File(ARP32e1miniapp_Outfile_DBG).lastModified()));
    print("           size:               ", java.io.File(ARP32e1miniapp_Outfile_DBG).length()/1000, " kBytes");
    print("");""")
        f.write("""
}
""")
        if c66xx_outfile != None:
            f.write("""
function VH28EvmHil_ConnectAllCores(CM4_REL, C66xx_REL)
{   
    DSP_MODE = true;
    var statusOK = true;
    
    print("");
    print("VH28-EVM-HIL debug server: Connecting all cores and downloading outfiles");
    print("========================================================================");
  
    if (CM4_REL) 
    {
        CM4_Outfile = CM4_Outfile_REL;
    }
    else 
    {
        CM4_Outfile = CM4_Outfile_DBG;
    }

    if (C66xx_REL) 
    {
        C66xx_Outfile = C66xx_Outfile_REL;""")
            if arp32_outfile != None:
                f.write("""
        ARP32_Outfile = ARP32e1_Outfile_REL;""")
            f.write("""
    }
    else 
    {
        C66xx_Outfile = C66xx_Outfile_DBG;""")
            if arp32_outfile != None:
                f.write("""
        ARP32_Outfile = ARP32e1_Outfile_DBG;""")
            f.write("""
    }

    print("");
    print("Script-timeout:           ", SCRIPT_TIMEOUT, "s");
    print("");
    print("Choosen CortexM4 outfile: ", CM4_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(CM4_Outfile).lastModified()));
    print("           size:          ", java.io.File(CM4_Outfile).length()/1000, " kBytes");
    print("");
    print("Choosen C66xx outfile:    ", C66xx_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(C66xx_Outfile).lastModified()));
    print("           size:          ", java.io.File(C66xx_Outfile).length()/1000, " kBytes");
    print("");""")
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
      // core variables
      cpu_a15 = "";
      cpu_m4 = "";
      cpu_dsp = "";""")
            if arp32_outfile != None:
                f.write("""
      cpu_eve = "";""")
            f.write("""
		
      // scan for target cores to connect
      cpu_list = debugServer.getListOfCPUs();
      for(i=0; i < cpu_list.length; i++)
      {
        if (cpu_list[i].indexOf("CortexA15_0") != -1)
        {
          cpu_a15 = cpu_list[i];
        }
        else if (cpu_list[i].indexOf("C66xx_DSP1") != -1)
        {
          cpu_dsp = cpu_list[i];
        }
        else if (cpu_list[i].indexOf("Cortex_M4_IPU1_C0") != -1)
        {
          cpu_m4 = cpu_list[i];
        }""")
            if arp32_outfile != None:
                f.write("""
        else if (cpu_list[i].indexOf("ARP32_EVE_1") != -1)
        {
          cpu_eve = cpu_list[i];
        }""")
            f.write("""
      }
		
      print("Open a debug session for CortexA15 on VH28...");
      debugSessionCA15    = debugServer.openSession(cpu_a15);

      print("Open a debug session for CortexM4 on VH28...");
      debugSessionCM4     = debugServer.openSession(cpu_m4);

      print("Open a debug session for C66xx on VH28...");
      debugSessionC66xx_0 = debugServer.openSession(cpu_dsp);""")
            if arp32_outfile != None:
                f.write("""
            
      print("Open a debug session for ARP32 on VH28...");
      debugSessionARP32_0 = debugServer.openSession(cpu_eve);""")
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
        try
        {
            print("Connect and reset CortexA15...");
            debugSessionCA15.target.connect();
            debugSessionCA15.target.reset();
            
            // Workaround: C66xx timer is only running when A15 is started
            // => if A15 is stopped SYSBIOS application hangs due to time check at startup.
            debugSessionCA15.target.runAsynch();

            print("Connect and reset CortexM4...");
            debugSessionCM4.target.connect();
            debugSessionCM4.target.reset();

            print("Connect and reset C66xx...");
            debugSessionC66xx_0.target.connect();
            debugSessionC66xx_0.target.reset();""")
            if arp32_outfile != None:
                f.write("""

            print("Connect and reset ARP32...");
            debugSessionARP32_0.target.connect();
            debugSessionARP32_0.target.reset();""")
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
            print("Load outfile on CortexM4...");
            print("    ", CM4_Outfile);
            debugSessionCM4.memory.loadProgram(CM4_Outfile);
            
            print("Load outfile on C66xx...");
            print("    ", C66xx_Outfile);
            debugSessionC66xx_0.memory.loadProgram(C66xx_Outfile);""")
            if arp32_outfile != None:
                f.write("""

            print("Load outfile on ARP32...");
            print("    ", ARP32_Outfile);
            debugSessionARP32_0.memory.loadProgram(ARP32_Outfile);""")
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
""")
        elif cortexA15_outfile != None:
            f.write("""
function VH28EvmHil_ConnectAllCoresArm(CM4_REL, CA15_REL)
{   
    DSP_MODE = false;
    var statusOK = true;
    
    print("");
    print("VH28-EVM-HIL debug server: Connecting all cores (ARM) and downloading outfiles");
    print("==============================================================================");
  
    if (CM4_REL) 
    {
        CM4_Outfile = CM4_Outfile_REL;
    }
    else 
    {
        CM4_Outfile = CM4_Outfile_DBG;
    }

    if (CA15_REL) 
    {
        CA15_Outfile = CA15_Outfile_REL;""")
            if arp32_outfile != None:
                f.write("""
        ARP32_Outfile = ARP32e1_Outfile_REL;""")
            f.write("""
    }
    else 
    {
        CA15_Outfile = CA15_Outfile_DBG;""")
            if arp32_outfile != None:
                f.write("""
        ARP32_Outfile = ARP32e1_Outfile_DBG;""")
            f.write("""
    }

    print("");
    print("Script-timeout:           ", SCRIPT_TIMEOUT, "s");
    print("");
    print("Choosen CortexM4 outfile: ", CM4_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(CM4_Outfile).lastModified()));
    print("           size:          ", java.io.File(CM4_Outfile).length()/1000, " kBytes");
    print("");
    print("Choosen CA15 outfile:     ", CA15_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(CA15_Outfile).lastModified()));
    print("           size:          ", java.io.File(CA15_Outfile).length()/1000, " kBytes");
    print("");""")
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
      // core variables
      cpu_a15 = "";
      cpu_m4 = "";""")
            if arp32_outfile != None:
                f.write("""
      cpu_eve = "";""")
            f.write("""
		
      // scan for target cores to connect
      cpu_list = debugServer.getListOfCPUs();
      for(i=0; i < cpu_list.length; i++)
      {
        if (cpu_list[i].indexOf("CortexA15_0") != -1)
        {
          cpu_a15 = cpu_list[i];
        }
        else if (cpu_list[i].indexOf("Cortex_M4_IPU1_C0") != -1)
        {
          cpu_m4 = cpu_list[i];
        }""")
            if arp32_outfile != None:
                f.write("""
        else if (cpu_list[i].indexOf("ARP32_EVE_1") != -1)
        {
          cpu_eve = cpu_list[i];
        }""")
            f.write("""
      }
		
      print("Open a debug session for CortexA15 on VH28...");
      debugSessionCA15    = debugServer.openSession(cpu_a15);

      print("Open a debug session for CortexM4 on VH28...");
      debugSessionCM4     = debugServer.openSession(cpu_m4);""")
            if arp32_outfile != None:
                f.write("""
            
      print("Open a debug session for ARP32 on VH28...");
      debugSessionARP32_0 = debugServer.openSession(cpu_eve);""")
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
        try
        {
            print("Connect and reset CortexA15...");
            debugSessionCA15.target.connect();
            debugSessionCA15.target.reset();
            
            print("Connect and reset CortexM4...");
            debugSessionCM4.target.connect();
            debugSessionCM4.target.reset();""")
            if arp32_outfile != None:
                f.write("""

            print("Connect and reset ARP32...");
            debugSessionARP32_0.target.connect();
            debugSessionARP32_0.target.reset();""")
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
            print("Load outfile on CortexM4...");
            print("    ", CM4_Outfile);
            debugSessionCM4.memory.loadProgram(CM4_Outfile);
            
            print("Load outfile on CortexA15...");
            print("    ", CA15_Outfile);
            debugSessionCA15.memory.loadProgram(CA15_Outfile);""")
            if arp32_outfile != None:
                f.write("""

            print("Load outfile on ARP32...");
            print("    ", ARP32_Outfile);
            debugSessionARP32_0.memory.loadProgram(ARP32_Outfile);""")
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
""")
        else: # CortexM4 only (neither C66 nor CA15 selected)
            f.write("""
function VH28EvmHil_ConnectAllCoresM4(CM4_REL, ARP32_REL)
{   
    DSP_MODE = false;
    var statusOK = true;
    
    print("");
    print("VH28-EVM-HIL debug server: Connecting all cores (CortexM4) and downloading outfiles");
    print("===================================================================================");
  
    if (CM4_REL) 
    {
        CM4_Outfile = CM4_Outfile_REL;
    }
    else 
    {
        CM4_Outfile = CM4_Outfile_DBG;
    }""")
            if arp32_outfile != None:
                f.write("""
    if (ARP32_REL) 
    {
        ARP32_Outfile = ARP32e1_Outfile_REL;
    }
    else 
    {
        ARP32_Outfile = ARP32e1_Outfile_DBG;
    }""")

            f.write("""
    print("");
    print("Script-timeout:           ", SCRIPT_TIMEOUT, "s");
    print("");
    print("Choosen CortexM4 outfile: ", CM4_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(CM4_Outfile).lastModified()));
    print("           size:          ", java.io.File(CM4_Outfile).length()/1000, " kBytes");
    print("");""")
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
      // core variables
      cpu_a15 = "";
      cpu_m4 = "";""")
            if arp32_outfile != None:
                f.write("""
      cpu_eve = "";""")
            f.write("""
		
      // scan for target cores to connect
      cpu_list = debugServer.getListOfCPUs();
      for(i=0; i < cpu_list.length; i++)
      {
        if (cpu_list[i].indexOf("CortexA15_0") != -1)
        {
          cpu_a15 = cpu_list[i];
        }
        else if (cpu_list[i].indexOf("Cortex_M4_IPU1_C0") != -1)
        {
          cpu_m4 = cpu_list[i];
        }""")
            if arp32_outfile != None:
                f.write("""
        else if (cpu_list[i].indexOf("ARP32_EVE_1") != -1)
        {
          cpu_eve = cpu_list[i];
        }""")
            f.write("""
      }
		
      print("Open a debug session for CortexA15 on VH28...");
      debugSessionCA15    = debugServer.openSession(cpu_a15);

      print("Open a debug session for CortexM4 on VH28...");
      debugSessionCM4     = debugServer.openSession(cpu_m4);""")
            if arp32_outfile != None:
                f.write("""
            
      print("Open a debug session for ARP32 on VH28...");
      debugSessionARP32_0 = debugServer.openSession(cpu_eve);""")
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
        try
        {
            print("Connect and reset CortexA15...");
            debugSessionCA15.target.connect();
            debugSessionCA15.target.reset();
            debugSessionCA15.target.runAsynch();
            
            print("Connect and reset CortexM4...");
            debugSessionCM4.target.connect();
            debugSessionCM4.target.reset();""")
            if arp32_outfile != None:
                f.write("""

            print("Connect and reset ARP32...");
            debugSessionARP32_0.target.connect();
            debugSessionARP32_0.target.reset();""")
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
            print("Load outfile on CortexM4...");
            print("    ", CM4_Outfile);
            debugSessionCM4.memory.loadProgram(CM4_Outfile);""")
            if arp32_outfile != None:
                f.write("""

            print("Load outfile on ARP32...");
            print("    ", ARP32_Outfile);
            debugSessionARP32_0.memory.loadProgram(ARP32_Outfile);""")
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
""")

        if arp32e1miniapp_outfile != None: # CortexM4 only (neither C66 nor CA15 selected)
            f.write("""
function VH28EvmHil_ConnectStandAloneCores(CM4_REL, ARP32_REL)
{   
    var statusOK = true;
    
    print("");
    print("VH28-EVM-HIL debug server: Connecting A15, EVE and loading EVE outfile");
    print("===================================================================================");
  
    """)
            f.write("""
    if (ARP32_REL) 
    {
        ARP32e1miniapp_Outfile = ARP32e1miniapp_Outfile_REL;
    }
    else 
    {
        ARP32e1miniapp_Outfile = ARP32e1miniapp_Outfile_DBG;
    }""")

            f.write("""
    print("");
    print("Script-timeout:           ", SCRIPT_TIMEOUT, "s");
    print("");""")
            if arp32e1miniapp_outfile != None:
                f.write("""
    print("Choosen ARP32 miniapp outfile:    ", ARP32e1miniapp_Outfile);
    print("           last modified: ", java.util.Date(java.io.File(ARP32e1miniapp_Outfile).lastModified()));
    print("           size:          ", java.io.File(ARP32e1miniapp_Outfile).length()/1000, " kBytes");
    print("");
        """)
            f.write("""
    script      = env.instance();
    debugServer = script.getServer("DebugServer.1");
    script.setScriptTimeout(SCRIPT_TIMEOUT * 1000);

    try
    {
      // core variables
      cpu_a15 = "";
      """)
            if arp32e1miniapp_outfile != None:
                f.write("""
      cpu_eve = "";""")
            f.write("""
		
      // scan for target cores to connect
      cpu_list = debugServer.getListOfCPUs();
      for(i=0; i < cpu_list.length; i++)
      {
        if (cpu_list[i].indexOf("CortexA15_0") != -1)
        {
          cpu_a15 = cpu_list[i];
        }
        """)
            if arp32e1miniapp_outfile != None:
                f.write("""
        else if (cpu_list[i].indexOf("ARP32_EVE_1") != -1)
        {
          cpu_eve = cpu_list[i];
        }""")
            f.write("""
      }
		
      print("Open a debug session for CortexA15 on VH28...");
      debugSessionCA15    = debugServer.openSession(cpu_a15);
        """)
            if arp32e1miniapp_outfile != None:
                f.write("""
            
      print("Open a debug session for ARP32 on VH28...");
      debugSessionARP32_0 = debugServer.openSession(cpu_eve);""")
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
        try
        {
            print("Connect and reset CortexA15...");
            debugSessionCA15.target.connect();
            debugSessionCA15.target.reset();
            debugSessionCA15.target.runAsynch();
            
            """)
            if arp32e1miniapp_outfile != None:
                f.write("""

            print("Connect and reset ARP32...");
            debugSessionARP32_0.target.connect();
            debugSessionARP32_0.target.reset();""")
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
            """)
            if arp32e1miniapp_outfile != None:
                f.write("""

            print("Load outfile on ARP32...");
            print("    ", ARP32e1miniapp_Outfile);
            debugSessionARP32_0.memory.loadProgram(ARP32e1miniapp_Outfile);""")
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
""")
        f.write("""

function VH28EvmHil_DisconnectAllCores()
{
    print("");
    print("VH28-EVM-HIL debug server: Disconnect all cores...");
    print("==================================================");

    try
    {
        print("Disconnect CortexA15...");
        debugSessionCA15.target.disconnect();
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
    try
    {
        print("Disconnect CortexM4...");
        debugSessionCM4.target.disconnect();
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
		""")
        if c66xx_outfile != None:
            f.write("""
       
    if (DSP_MODE)
    {
        try
        {
              print("Disconnect C66xx...");
              debugSessionC66xx_0.target.disconnect();
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
    }""")
        if arp32_outfile != None:
            f.write("""
    try
    { 
        print("Disconnect ARP32...");
        debugSessionARP32_0.target.disconnect();
    }
    catch(error)
    {
        print("");
        print("ERROR: Unable disconnect targets! A script-based disconnect can only be done, when the cores have been connected via script, before. Other possible root-causes: EVM-power...");
        print("Detailed exception information:");
        print(error);
        print("");
        print("");
    }""")
        f.write("""
    DSP_MODE = false;
    print("Done!");
}
        """)
        if (c66xx_outfile == None) and (cortexA15_outfile == None) and (arp32_outfile != None):
            f.write("""
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   ARP32=debug)..."   , "VH28EvmHil_ConnectAllCoresM4(false, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   ARP32=release)..." , "VH28EvmHil_ConnectAllCoresM4(false, true)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, ARP32=debug)..."   , "VH28EvmHil_ConnectAllCoresM4(true, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, ARP32=release)..." , "VH28EvmHil_ConnectAllCoresM4(true, true)");""" % (component, component, component, component))
        elif (c66xx_outfile == None) and (cortexA15_outfile == None) and (arp32_outfile == None):
            f.write("""
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug)..."   , "VH28EvmHil_ConnectAllCoresM4(false, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release)..."   , "VH28EvmHil_ConnectAllCoresM4(true, true)");""" % (component, component))
        if (c66xx_outfile != None) and (arp32_outfile != None):
            f.write("""
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   C66xx,ARP32=debug)..."   , "VH28EvmHil_ConnectAllCores(false, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   C66xx,ARP32=release)..." , "VH28EvmHil_ConnectAllCores(false, true)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, C66xx,ARP32=debug)..."   , "VH28EvmHil_ConnectAllCores(true, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, C66xx,ARP32=release)..." , "VH28EvmHil_ConnectAllCores(true, true)");""" % (component, component, component, component))
        elif (c66xx_outfile != None) and (arp32_outfile == None):
            f.write("""
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   C66xx=debug)..."         , "VH28EvmHil_ConnectAllCores(false, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   C66xx=release)..."       , "VH28EvmHil_ConnectAllCores(false, true)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, C66xx=debug)..."         , "VH28EvmHil_ConnectAllCores(true, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, C66xx=release)..."       , "VH28EvmHil_ConnectAllCores(true, true)");""" % (component, component, component, component))
        if (cortexA15_outfile != None) and (arp32_outfile != None):
            f.write("""
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   CA15,ARP32=debug)..."    , "VH28EvmHil_ConnectAllCoresArm(false, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   CA15,ARP32=release)..."  , "VH28EvmHil_ConnectAllCoresArm(false, true)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, CA15,ARP32=debug)..."    , "VH28EvmHil_ConnectAllCoresArm(true, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, CA15,ARP32=release)..."  , "VH28EvmHil_ConnectAllCoresArm(true, true)");""" % (component, component, component, component))
        elif (cortexA15_outfile != None) and (arp32_outfile == None):
            f.write("""
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   CA15=debug)..."          , "VH28EvmHil_ConnectAllCoresArm(false, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=debug,   CA15=release)..."        , "VH28EvmHil_ConnectAllCoresArm(false, true)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, CA15=debug)..."          , "VH28EvmHil_ConnectAllCoresArm(true, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4=release, CA15=release)..."        , "VH28EvmHil_ConnectAllCoresArm(true, true)");""" % (component, component, component, component))
        if (arp32miniapp_outfile != None):
            f.write("""
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4,   ARP32=debug)..."          , "VH28EvmHil_ConnectStandAloneCores(false, false)");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Connect and load all cores (CM4,   ARP32=release)..."        , "VH28EvmHil_ConnectStandAloneCores(false, true)");""" % (component, component))
        f.write("""
hotmenu.addJSFunction("%s VH28-EVM-HIL: Disconnect all cores..."                                          , "VH28EvmHil_DisconnectAllCores()");
hotmenu.addJSFunction("%s VH28-EVM-HIL: Print scripting status..."                                        , "VH28EvmHil_PrintStatus()");
            """ % (component, component))
        f.close()
        
        # also generate a batch file that copies script to console
        generate_BatchFile(dirabs, bat_file_name);
    else:
        print "Please specify target folder"

        
def generate_BatchFile(dirabs, bat_file_name):
        """
        Function                   :  generate_BatchFile
        Description                :  Generate the batch file.
        dirabs                     :  Output path of batch file.
        bat_file_name              :  Usually "_CopyDSScriptLoadCmdToClipboard.bat".
        Returns                    :  
        """
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
