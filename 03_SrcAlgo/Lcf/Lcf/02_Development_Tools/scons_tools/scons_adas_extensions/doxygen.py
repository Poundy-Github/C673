"""
Filename                  :  scons_adas_extensions\doxygen.py
Description               :  Script used to generate HTML documentation from doxygen doxyfile.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: doxygen.py
#
# DESCRIPTION: Script used to generate HTML documentation from doxygen doxyfile.
#
# INITIAL AUTHOR: Spruck, Jochen (spruckj)
#
# CREATION DATE: - 2013/01/29
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:51CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: doxygen.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:51CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.4 2016/05/27 11:40:40CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.3 2015/06/26 05:17:33CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 5:17:33 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

# vim: set et sw=3 tw=0 fo=awqorc ft=python:
#
# Astxx, the Asterisk C++ API and Utility Library.
# Copyright (C) 2005, 2006  Matthew A. Nicholson
# Copyright (C) 2006  Tim Blechmann
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License version 2.1 as published by the Free Software Foundation.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

import os
import os.path
import glob
from fnmatch import fnmatch
import shutil

def DoxyfileParse(file_contents):
  """
  Function                  :  DoxyfileParse
  Description               :  
  file_contents             :  
  Returns                   :  
  """
  """
  Parse a Doxygen source file and return a dictionary of all the values.
  Values will be strings and lists of strings.
  """
  data = {}

  import shlex
  lex = shlex.shlex(instream = file_contents, posix = True)
  lex.wordchars += "*+./-:"
  lex.whitespace = lex.whitespace.replace("\n", "")
  lex.escape = ""

  lineno = lex.lineno
  token = lex.get_token()
  key = token  # the first token should be a key
  last_token = ""
  key_token = False
  next_key = False
  new_data = True

  def append_data(data, key, new_data, token):
    """
    Function              :  append_data
    Description           :  
    data                  :  
    key                   :  
    new_data              :  
    token                 :  
    Returns               :  
    """
    if new_data or len(data[key]) == 0:
      data[key].append(token)
    else:
      data[key][-1] += token

  while token:
    if token in ['\n']:
      if last_token not in ['\\']:
        key_token = True
    elif token in ['\\']:
      pass
    elif key_token:
      key = token
      key_token = False
    else:
      if token == "+=":
        if key not in data:
          data[key] = []
      elif token == "=":
        data[key] = []
      else:
        append_data( data, key, new_data, token )
        new_data = True

    last_token = token
    token = lex.get_token()

    if last_token == '\\' and token != '\n':
      new_data = False
      append_data( data, key, new_data, '\\' )

  # compress lists of len 1 into single strings
  for k, v in data.items():
    if len(v) == 0:
      data.pop(k)

    # items in the following list will be kept as lists and not converted to strings
    if k in ["INPUT", "FILE_PATTERNS", "EXCLUDE_PATTERNS"]:
      continue

    if len(v) == 1:
      data[k] = v[0]

  return data

def DoxySourceScan(node, env, path):
  """
  Function          :  DoxySourceScan
  Description       :  
  node              :  
  env               :  
  path              :  
  Returns           :  
  """
  """
  Doxygen Doxyfile source scanner.  This should scan the Doxygen file and add
  any files used to generate docs to the list of source files.
  """
  default_file_patterns = [
    '*.c', '*.cc', '*.cxx', '*.cpp', '*.c++', '*.java', '*.ii', '*.ixx',
    '*.ipp', '*.i++', '*.inl', '*.h', '*.hh ', '*.hxx', '*.hpp', '*.h++',
    '*.idl', '*.odl', '*.cs', '*.php', '*.php3', '*.inc', '*.m', '*.mm',
    '*.py', '*.he',
  ]

  default_exclude_patterns = [
    '*~',
  ]

  sources = []

  data = DoxyfileParse(node.get_contents())

  recursive = data.get("RECURSIVE") == "YES"

  file_patterns = data.get("FILE_PATTERNS", default_file_patterns)
  exclude_patterns = data.get("EXCLUDE_PATTERNS", default_exclude_patterns)

  for node in data.get("INPUT", []):
    if os.path.isfile(node):
      sources.append(node)
    elif os.path.isdir(node):
      if recursive:
        for root, dirs, files in os.walk(node):
          for f in files:
            filename = os.path.join(root, f)

            pattern_check = any(fnmatch(filename, y) for y in file_patterns)
            exclude_check = any(fnmatch(filename, y) for y in exclude_patterns)

            if pattern_check and not exclude_check:
              sources.append(filename)
      else:
        for pattern in file_patterns:
          sources.extend(glob.glob("/".join([node, pattern])))

  sources = [env.File(path) for path in sources]
  return sources


def DoxySourceScanCheck(node, env):
  """
  Function         :  DoxySourceScanCheck
  Description      :  
  node             :  
  env              :  
  Returns          :  
  """
  """Check if we should scan this file"""
  return os.path.isfile(node.path)

def DoxyEmitter(source, target, env):
  """
  Function            :  DoxyEmitter
  Description         :  
  source              :  
  target              :  
  env                 :  
  Returns             :  
  """
  """Doxygen Doxyfile emitter"""
  # possible output formats and their default values and output locations
  output_formats = {
    "HTML": ("YES", "html"),
    "LATEX": ("NO", "latex"),
    "RTF": ("NO", "rtf"),
    "MAN": ("NO", "man"),
    "XML": ("NO", "xml"),
  }

  data = DoxyfileParse(source[0].get_contents())

  targets = []
  out_dir = data.get("OUTPUT_DIRECTORY", ".")
  if not os.path.isabs(out_dir):
    conf_dir = os.path.dirname(str(source[0]))
    out_dir = os.path.join(conf_dir, out_dir)
  
  # add our output locations
  for k, v in output_formats.items():
    if data.get("GENERATE_" + k, v[0]) == "YES":
      targets.append(env.Dir( os.path.join(out_dir, data.get(k + "_OUTPUT", v[1]))) )
      doc_out_dir = os.path.join(out_dir, data.get(k + "_OUTPUT", v[1]))
      if v[1] == "html":
        conti_image_backup_path = os.path.join(doc_out_dir, "..", "style", "conti.png")
        conti_image_path = os.path.join(doc_out_dir, "conti.png")
        if os.path.isfile(conti_image_backup_path):
          pass
        else:
          # backup conti.png to style folder, because clean deletes html folder
          if os.path.isfile(conti_image_path):
            shutil.copy(conti_image_path, os.path.join(doc_out_dir, "..", "style"))
            # remove html folder before building
            if os.path.isdir(os.path.abspath(doc_out_dir)):
              shutil.rmtree(os.path.abspath(doc_out_dir))
              # shutil.rmtree(os.path.abspath(doc_out_dir), ignore_errors=True)
            
  # don't clobber targets
  for node in targets:
    env.Precious(node)

  # set up cleaning stuff
  for node in targets:
    env.Clean(node, node)

  return (targets, source)

def generate(env):
  """
  Function        :  generate
  Description     :  
  env             :  
  Returns         :  
  """
  """
  Add builders and construction variables for the
  Doxygen tool.  This is currently for Doxygen 1.4.6.
  """
  doxyfile_scanner = env.Scanner(
    DoxySourceScan,
    "DoxySourceScan",
    scan_check = DoxySourceScanCheck,
  )

  import SCons.Builder
  doxyfile_builder = SCons.Builder.Builder(
    action = "cd ${SOURCE.dir}  &&  ${DOXYGEN} ${SOURCE.file}",
    emitter = DoxyEmitter,
    target_factory = env.fs.Entry,
    single_source = True,
    source_scanner =  doxyfile_scanner,
  )

  env["_DOXYGEN_TOOLS"] = env.Dir(env.subst('$DOXYGEN_TOOLS')).abspath
  env.PrependENVPath('PATH', env.subst('"$_DOXYGEN_TOOLS"'))

  # ZoM 2010-03-23 Setting path for dot.exe is not working :-(, => hardcoded in Doxygen.cfg
  env["_GRAPHVIZ_TOOLS"] = env.Dir(env.subst('$GRAPHVIZ_TOOLS')).abspath
  env.PrependENVPath('PATH', env.subst('"$_GRAPHVIZ_TOOLS"'))
  
  env.Append(BUILDERS = {
    'Doxygen': doxyfile_builder,
  })

  env.AppendUnique(
    DOXYGEN = 'doxygen',
  )

def exists(env):
  """
  Function        :  exists
  Description     :  
  env             :  
  Returns         :  
  """
  """
  Make sure doxygen exists.
  """
  return (env.Detect("doxygen") and env.Detect("dot"))
