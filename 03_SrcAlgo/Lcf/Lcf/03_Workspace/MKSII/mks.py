#! /usr/bin/python
#coding: utf-8

#===============================================================================
# mks.py
#   Run batch script, by calling function run.
#
# Parameter:
#   cmd                    - batch command to execute (example: 'im viewissue --batch 123456')
#   timeout_sec            - Timeout in seconds
#   IgnoreNegativeResponse - Optional parameter: Set to True if negative response should also returend
#
# Return value:
#   String - Positive response (Negative response if requested)
#   None   - timeout or negative response
#===============================================================================

import sys
import subprocess
import subprocess, shlex
from threading import Timer
import logging
from distutils.version import StrictVersion
import os

#-------------------------------------------------------------------------------
# Run batch script
#-------------------------------------------------------------------------------
def run(cmd, timeout_sec, IgnoreNegativeResponse = False):
  # Add host, port, user, password to command, if they env variables IMS_USER and IMS_PW are defined
  try:
    InsertPos = cmd.find(' ', 3)

    if cmd[:14] == "si viewproject":
      MksPort = "7001"
    else:
      MksPort = "7002" 

    if InsertPos >= 0:
      cmd = "%s --hostname=10.179.151.7 --port=%s --user=%s --password=%s %s" % (cmd[:InsertPos], MksPort, os.environ["IMS_USER"], os.environ["IMS_PW"], cmd[InsertPos+1:])

  except KeyError as err:
    pass
  
  # Generate process to execute PTC command
  proc = subprocess.Popen(shlex.split(cmd), stdout=subprocess.PIPE, stderr=subprocess.PIPE)
  
  # Generate timeout timer
  timeout_occured = []
  timeout_occured.append(False)
  timer = Timer(timeout_sec, kill_process, [proc, cmd, timeout_occured])
  
  # Execute PTC request
  try:
    timer.start()
    stdout,stderr = proc.communicate()
  
  # Request timeout
  finally:
    timer.cancel()
    
    # timeout
    if timeout_occured[0] is True:
      print "  -> MKS request failed: Timeout"
      return None
    
    else:
      if IgnoreNegativeResponse:
        return stdout
      
      else:
        # Negative response
        if len(stderr) != 0:
          print "  -> MKS request failed: %s" % (stderr,)
          return None
        
        # Positive response
        else:
          return stdout

# Timeout handling
def kill_process(proc, cmd, result):
  proc.kill()
  result[0] = True



#===============================================================================
# main function
#   Test code: Request integrety time data from MKS
#===============================================================================
if __name__ == "__main__":
  ItemID = 531320
  print "Import integrety item %s" % (ItemID,)
  
  stdout = run('im viewissue --batch %s' % (ItemID,), 20)
  if stdout:
    print stdout
