var evmConnectorTargetConfigurationFile = Packages.java.lang.System.getenv ("EVM_CON_TARGET_CONFIGFILE");

var evmConnectorOutFileArm = Packages.java.lang.System.getenv ("EVM_CON_OUTFILE_ARM");
var evmConnectorConnectDsp = Packages.java.lang.System.getenv ("EVM_CON_CONNECT_DSP");
var evmConnectorOutFileDsp = Packages.java.lang.System.getenv ("EVM_CON_OUTFILE_DSP");
var evmConnectorConnectEve = Packages.java.lang.System.getenv ("EVM_CON_CONNECT_EVE");
var evmConnectorOutFileEve = Packages.java.lang.System.getenv ("EVM_CON_OUTFILE_EVE");

var script = Packages.com.ti.ccstudio.scripting.environment.ScriptingEnvironment.instance ();

var debugServer = script.getServer ("DebugServer.1");
debugServer.setConfig (evmConnectorTargetConfigurationFile);

var debugSessionARM = debugServer.openSession ("*", "CortexA8");
script.traceWrite ("connecting to arm");
debugSessionARM.target.connect ();
script.traceWrite ("loading " + evmConnectorOutFileArm + " to arm");
debugSessionARM.memory.loadProgram (evmConnectorOutFileArm);
debugSessionARM.options.setBoolean ("AddCEXITbreakpointAfterLoad", false);
script.traceWrite ("start arm");
debugSessionARM.target.runAsynch ();

if (evmConnectorConnectDsp == "TRUE") {
  var debugSessionDSP = debugServer.openSession ("*", "C674X_0");
  script.traceWrite ("connecting to dsp");
  debugSessionDSP.target.connect ();
  script.traceWrite ("loading " + evmConnectorOutFileDsp + " to dsp");
  debugSessionDSP.memory.loadProgram (evmConnectorOutFileDsp);
  debugSessionDSP.options.setBoolean ("AddCEXITbreakpointAfterLoad", false);
  script.traceWrite ("start dsp");
  debugSessionDSP.target.runAsynch ();
}

if (evmConnectorConnectEve == "TRUE") {
  var debugSessionEVE = debugServer.openSession ("*", "ARP32_0");
  script.traceWrite ("connecting to eve");
  debugSessionEVE.target.connect ();
  script.traceWrite ("loading " + evmConnectorOutFileEve + " to eve");
  debugSessionEVE.memory.loadProgram (evmConnectorOutFileEve);
  debugSessionEVE.options.setBoolean ("AddCEXITbreakpointAfterLoad", false);
  script.traceWrite ("start eve");
  debugSessionEVE.target.runAsynch ();
}

// wait (6000)
script.traceWrite ("evm ready");

while (1) {
}

function wait (ms) {
  var start = (new Date ()).getTime ();
  var end   = start + ms;
  while ((new Date ()).getTime () < end) {};
}
