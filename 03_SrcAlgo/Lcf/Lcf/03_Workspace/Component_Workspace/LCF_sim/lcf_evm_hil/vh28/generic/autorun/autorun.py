from time import *
import os
import subprocess
import sys

execfile ("../../autorun_config.py")
logfilename = os.environ["logfilename"]

def killProcess (proc):
  subprocess.Popen ("taskkill /F /T /PID %i > nul"%proc.pid, shell=True)
  
def autorun ():
  stepOk = False

  if stepOk == True:  # scons clean
    # start scons clean
    starttimeSconsClean = localtime ()
    starttimeSconsCleanString = strftime ("%H:%M:%S", starttimeSconsClean)
    print  ("")
    print  ("---------------------------------------------------------------------------------")
    print  ("---------- SCONS CLEAN -------------------------------------- %s ----------" % (starttimeSconsCleanString))
    print  ("---------------------------------------------------------------------------------")
    sys.stdout.flush ()
    try:
      p1 = subprocess.Popen (sconsPath + "\\cts.bat NOTIME")
      p1.wait ()
    except:
      print ("an error occured while calling cts.bat!")
      sys.stdout.flush ()
      stepOk = False

  stepOk = True

  if stepOk == True:  # scons build
    # start scons build
    lastline = ""
    starttimeSconsBuild = localtime ()
    starttimeSconsBuildString = strftime ("%H:%M:%S", starttimeSconsBuild)
    print  ("")
    print  ("---------------------------------------------------------------------------------")
    print  ("---------- SCONS BUILD -------------------------------------- %s ----------" % starttimeSconsBuildString)
    print  ("---------------------------------------------------------------------------------")
    sys.stdout.flush ()
    try:
      p2 = subprocess.Popen (sconsPath + "\\bts.bat NOTIME")
      p2.wait ()
    except:
      print ("an error occured while calling bts.bat!")
      sys.stdout.flush ()
      stepOk = False

    # check for build errors
    file = open (logfilename, "r")
    for line in file:
      if "Build" in line:
        lastline = line
      if "Build FAILED" in line:
        print ("an error occured while building process!")
        sys.stdout.flush ()
        stepOk = False
    if not "Build succeeded" in lastline:
      print ("an error occured while building process!")
      sys.stdout.flush ()
      stepOk = False
    file.close ()

  if stepOk == True:  # ccs start
    # start debug scripting server
    starttimeCcs = localtime ()
    starttimeCcsString = strftime ("%H:%M:%S", starttimeCcs)
    print  ("")
    print  ("--------------------------------------------------------------------------------")
    print  ("---------- CCS ---------------------------------------------- %s ---------" % starttimeCcsString)
    print  ("--------------------------------------------------------------------------------")
    sys.stdout.flush ()
    # set needed environmental variables
    os.environ["EVM_CON_OUTFILE_ARM"] = evmConnectorOutFileArm
    os.environ["EVM_CON_CONNECT_DSP"] = evmConnectorConnectDsp
    os.environ["EVM_CON_OUTFILE_DSP"] = evmConnectorOutFileDsp
    os.environ["EVM_CON_CONNECT_EVE"] = evmConnectorConnectEve
    os.environ["EVM_CON_OUTFILE_EVE"] = evmConnectorOutFileEve
    os.environ["EVM_CON_TARGET_CONFIGFILE"] = evmConnectorTargetConfigurationFile
    # combine dss call and arguments
    exe  = evmConnectorJrePath + "java.exe "
    exe += "-Xmx512m -Xms128m -Dxpcom.bridge.executeOnDedicatedThread=no "
    exe += "-Dorg.eclipse.swt.browser.XULRunnerPath=" + debugServerPath + "win32 "
    exe += "-DXPCOM.RUNTIME=" + debugServerPath + " "
    exe += "-cp " + rhinoJar + ";" + scriptingJars + ";" + dvtScriptingJar + " "
    exe += rhinoShell + " "
    exe += "evm_connector.js"
    try:
      p3 = subprocess.Popen (exe)
      # do not wait for ending of this process, when it ends the debugsession will be closed
    except:
      print ("an error occured while starting DebugServerScripting!")
      sys.stdout.flush ()
      stepOk = False

    # check link status
    error = 0
    link = 0
    evmReady = 0
    while (1):
      file = open (logfilename, "r")
      for line in file:
        if "Link Status" in line:
          link = 1
        if "evm ready" in line:
          evmReady = 1
        if "Timed Out looking for a Phy" in line:
          killProcess (p3)
          print ("an error occured while connecting to evalboard!")
          sys.stdout.flush ()
          stepOk = False
          error = 1
      file.close ()
      if error == 1:
        break
      if link == 1 and evmReady == 1:
        break

  if stepOk == True:  # mts start
    starttimeMts = localtime ()
    starttimeMtsString = strftime ("%H:%M:%S", starttimeMts)
    print  ("")
    print  ("---------------------------------------------------------------------------------")
    print  ("---------- MTS ---------------------------------------------- %s ----------" % starttimeMtsString)
    print  ("---------------------------------------------------------------------------------")
    sys.stdout.flush ()
    exe  = mtsPath + "measapp.exe "
    exe += "-lc" + mtsConfigFile + " "
    exe += "-lr" + mtsRecordingFile + " "
    # exe += "-lb" + mtsConfigFile + " "
    exe += "-pal -eab -silent -norestart"
    p4 = subprocess.Popen (exe)
    p4.wait ()

  killProcess (p3)

  endtime = localtime ()
  endtimeString = strftime ("%H:%M:%S", endtime)
  print  ("---------------------------------------------------------------------------------")
  print  ("---------- END ---------------------------------------------- %s ----------" % endtimeString)
  print  ("---------------------------------------------------------------------------------")
  sys.stdout.flush ()

def main ():
  autorun ()

if __name__ == "__main__":
  main ()
