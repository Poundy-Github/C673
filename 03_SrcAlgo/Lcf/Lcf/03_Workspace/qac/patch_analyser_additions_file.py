#!/usr/bin/env python

###############################################################################
# Script patches the given file by the build target name.
#
# Run script with parameters:
# param: Analyser additions file
#
# e.g.: patch_analyser_additions_file.py dpu_arm_a_analyser_additions.txt
###############################################################################

import os
import re
import string
import sys
import shutil

###############################################################################
XDC_CFG_XHEADER = os.environ['XDC_CFG_XHEADER']

###############################################################################
def patch_file(file):
  if os.path.exists('out'):
    shutil.rmtree('out')
  os.mkdir('out')

  fin = open(file, 'r')
  fout_name, fout_ext = os.path.splitext(os.path.basename(fin.name))
  fout = open(os.path.join('out', fout_name + '_patched' + fout_ext), 'w')
  for line in fin:
    fout.write( line.replace('xdc_cfg_xheader_patch', XDC_CFG_XHEADER) )
  fin.close()
  fout.close()

###############################################################################
if __name__ == '__main__':
  if len(sys.argv) < 1:
    print("Input missing.")
  else:
    file = sys.argv[1]
    if os.path.exists(file):
      patch_file(file)
    else:
      print 'File does not exist!'
