"""
Filename                  :  scons_adas_extensions\ram_rom_algo_libsize.py
Description               :  Script that determines RAM/ROM usage information from a library.This script file runs in a python main environment as well as a SCons script.
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_adas_extensions
#
# MODULE NAME: ram_rom_algo_libsize.py
#
# DESCRIPTION: Script that determines RAM/ROM usage information from a library.
#              This script file runs in a python main environment as well as a SCons script.
#
# INITIAL AUTHOR: Hendra.Sasmito-EXT (uidw1406)
#
# CREATION DATE: - 2013/10/07
#
# LAST CHANGE:      $Date: 2021/12/13 19:03:59CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: ram_rom_algo_libsize.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:03:59CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_adas_extensions/project.pj
# CHANGES:                   Revision 1.23 2016/05/31 07:47:58CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Display summary of VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.22 2016/05/30 14:49:41CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Display summary of VME and VH28 ram/rom calculation
# CHANGES:                   Revision 1.21 2016/05/27 12:06:32CEST Bhagawati, Tridip (uidr2134) 
# CHANGES:                   File and function header updated
# CHANGES:                   Revision 1.20 2016/05/13 10:44:16CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Removed unwanted space between the functions writeVME_VH28LibsizeFile and generateVME_VH28LibSize
# CHANGES:                   Update the function description and RETURN in function generateVME_VH28LibSize
# CHANGES:                   Revision 1.19 2016/05/12 14:05:49CEST Singh, Vishal (uidj9083) 
# CHANGES:                   Introduced alias for VME and VH28 libsize calculation
# CHANGES:                   Revision 1.18 2015/09/25 10:22:27CEST Fischer-EXT, Andre (uidg5297) 
# CHANGES:                   Add FUSI-RXM to RXM
# CHANGES:                   --- Added comments ---  uidg5297 [Sep 25, 2015 10:22:27 AM CEST]
# CHANGES:                   Change Package : 380452:1 http://mks-psad:7002/im/viewissue?selection=380452
# CHANGES:                   Revision 1.17 2015/09/10 11:05:10CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Fixing the ValueError issue for LIbsize and EVM HIL targets
# CHANGES:                   --- Added comments ---  uidr0826 [Sep 10, 2015 11:05:11 AM CEST]
# CHANGES:                   Change Package : 375157:1 http://mks-psad:7002/im/viewissue?selection=375157
# CHANGES:                   Revision 1.16 2015/08/26 12:02:33CEST Verzilov-EXT, Evgenii (uidg4013) 
# CHANGES:                   introduced new memory blocks for FUSI-RAM and FUSI-ROM
# CHANGES:                   --- Added comments ---  uidg4013 [Aug 26, 2015 12:02:34 PM CEST]
# CHANGES:                   Change Package : 301231:2 http://mks-psad:7002/im/viewissue?selection=301231
# CHANGES:                   Revision 1.15 2015/06/26 05:17:34CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   --- Added comments ---  uidr0826 [Jun 26, 2015 5:17:35 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

import os

try:
    # Use this statement when running as a Python script.
    # => Throws a "NameError" inside SCons because the symbol "__file__" is unknown!
    # => When running from a different path "__file__" is the calling file and an IOError is thrown!
    execfile(os.path.dirname(os.path.realpath(__file__)) + "/areas.py")
except (NameError, IOError):
  # Use this statement when running as a SCons script
  sconscript_dir = os.path.dirname((lambda x:x).func_code.co_filename)
  execfile(sconscript_dir + "/areas.py")
  
def getLibInfo(mapfile, libname, debug=True, printDetails=False):
  """
  Function                  :  getLibInfo
  Description               :  Parses and returns library informations. It parses a mapfile for occurrences of a specific library and 
                               calculates a summary for all parts in ram/rom sections and for all those that couldn't be classified.
  mapfile                   :  The mapfile to parse.
  libname                   :  The name of the relevant library.
  debug                     :  True enables console output, False hides it.True is default.
  printDetails              :  True enables detailed console output, False hides it.False is default.
  Returns                   :  ram, rom, fusi_ram, fusi_rom, unknown
  """
  showAddressPerObject = False
  showEmptySections = False
  useAreas = True
  
  content = []
  areaSizes = {}
  startSections = False
  SectionTitle = "DummyTitle"
  BlockAddress = ""
  BlockWidth = ""
  BlockObj = ""
  lineskip = False
  objsInSections = 0
  objSize = 0
  objsInSectionSize = 0
  overallSize = 0
  overallObjs = 0
  templine = ""
  lastline = ""
  newline = ""
  
  if debug:
    print "================================================================================"
    print "Library RAM/ROM Information: \"%s\"" % libname
  
  # pass 1: parse map file (only section info)
  file = open (mapfile, "r")
  lastLibName = ""

  start_count = False
  counter = 0
  if "Archive" in file.readline(): # i.e. we have a gcc compiled map-file
    counter += 1
    for line in file:
      counter += 1
      if line.startswith("Linker script and memory map"):
        startSections = True  
      if startSections == True:
        if (line.lstrip().startswith("*(")):
          # below this line new sections will start
          if lastline:
            # process last valid line
            length_lastline = len(lastline.split())
            if length_lastline < 4:
              lastline = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2] + " . . \n"
            else:
              lastline = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2] + "  " + lastline.split()[3].replace("("," : ").replace(")","") + " . \n"
            content.append(lastline)
          templine = ""
          lastline = ""
          continue
        if (not line.strip()) or ("0x00000000" in line) or (" 0x0 " in line) or ("(size before relaxing)" in line) or ("CREATE" in line) or ("START" in line) or ("LOAD" in line) or ("END" in line):
          BlockObj = " . "
          continue
        if len(line.split()) == 2 and ("0x" in line.split()[0] and "0x" in line.split()[1]):
          BlockObj = " . "
          continue
        if ("*fill*" in line):
          # 1st finalize last block ...
          if templine: # i.e. previous line starts with "0x"
            temp_diff = int(BlockAddress, 16) + int(BlockWidth,16) - int(templine.split()[0],16)
            if temp_diff != 0:
              templine = " " + templine.split()[0].replace("0x","") + " " + hex(temp_diff).replace("L","") + " " + templine.split()[1].replace("("," : ").replace(")","") + " (:" + templine.split()[2].replace(":",";")   + ") \n"
              if not " : " in templine:
                pass
              content.append(templine)
          if lastline: # i.e. previous line starts with "."
            length_lastline = len(lastline.split())
            if length_lastline < 4:
              lastline = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2] + " . . \n"
            else:
              lastline = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2] + "  " + lastline.split()[3].replace("("," : ").replace(")","") + " . \n"
            content.append(lastline)
            lastline = ""
          # ... then add the hole
          templine = " " + line.split()[1].replace("0x","") + " " + line.split()[2] + " " + "--HOLE--  [fill = 0] \n"
          content.append(templine)
          templine = ""
          continue
        if lineskip:
          lineskip = False
          if ("0x" in line.split()[0]):
            line = " " + start_line + line + "\n"
          start_line = ""			
        if len(line.split()) == 1:
          lineskip = True
          start_line = line.split()[0]
          continue
        if (line.startswith(".") or line.startswith(" .")) or line.split()[0] == "COMMON" or ("xdc" in line.split()[0]) or ("ti" in line.split()[0]):  # old Section or Block needs to be finished
          if templine: # i.e. previous line starts with "0x"
            temp_diff = int(BlockAddress, 16) + int(BlockWidth,16) - int(templine.split()[0],16)
            if temp_diff != 0:
              templine = " " + templine.split()[0].replace("0x","") + " " + hex(temp_diff).replace("L","") + " " + templine.split()[1].replace("("," : ").replace(")","") + " (:" + templine.split()[2].replace(":",";")   + ") \n"
              if not " : " in templine:
                pass
              content.append(templine)
            templine = "" 
          if lastline: # i.e. previous line starts with "."
            length_lastline = len(lastline.split())
            if length_lastline < 4:
              lastline = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2] + " . . \n"
            else:
              lastline = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2] + "  " + lastline.split()[3].replace("("," : ").replace(")","") + " . \n"
            content.append(lastline)
            lastline = ""
          if not (line.startswith(SectionTitle) or line.startswith(" " + SectionTitle)): # check whether there is a new kind of objects
            SectionTitle = line.split()[0]
            try:
              tempIndex = SectionTitle.index('.', 1)
              SectionTitle = SectionTitle[0:tempIndex]
            except:
              pass
            try:
              tempIndex = SectionTitle.index(':', 0)
              SectionTitle = SectionTitle[0:tempIndex]
            except:
              pass			
            templine = SectionTitle + " \n"
            content.append(templine)
            BlockAddress = line.split()[1]
            templine = ""
          BlockObj = " . "		  
        if line.startswith(" .") or (line.split()[0] == "COMMON") or line.split()[0].startswith("ti"): # New block starts
          # Initialize new section block:
          BlockAddress = line.split()[1]
          BlockWidth = line.split()[2]
          BlockObj = line.split()[3]
          lastline = line
          templine = ""	
          try:
            # check if the line contained a valid hex-numbers
            int(BlockAddress, 16)
            int(BlockWidth,16)
          except:
            lastline = ""
            templine = ""	
            BlockAddress = 0
            BlockWidth = 0
            continue
        if line.split()[0].startswith("0x"): 
          if not (templine or lastline):
            continue		  
          if templine: # previous line starts with "0x"
            temp_diff = int(line.split()[0],16)- int(templine.split()[0], 16)
            if temp_diff != 0:
              if len(templine.split()) < 3:
                templine = " " + templine.split()[0].replace("0x","") + " " + hex(temp_diff).replace("L","") + " " + templine.split()[1].replace("("," : ").replace(")","") + " \n"
              else:
                templine = " " + templine.split()[0].replace("0x","") + " " + hex(temp_diff).replace("L","") + " " + templine.split()[1].replace("("," : ").replace(")","") + " (:" + templine.split()[2].replace(":",";") + ") \n"			  
              content.append(templine)
            templine = ""
          if lastline: # i.e. previous line starts with "."			
            if lastline.split()[1] != line.split()[0]:
              temp_diff = int(line.split()[0],16)- int(lastline.split()[1], 16)
              if len(lastline.split()) < 4:
                newline = " " + lastline.split()[1].replace("0x","") + " " + hex(temp_diff).replace("L","") + " " + BlockObj + " . " + " \n"
              else:
                newline = " " + lastline.split()[1].replace("0x","") + " " + hex(temp_diff).replace("L","") + " " + lastline.split()[3].replace("("," : ").replace(")","") + " (:.) " + " \n"
              content.append(newline)
            else:
              if len(lastline.split()) < 4:
                templine = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2] + " . . \n"
              else:
                templine = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2] + " " + lastline.split()[3].replace("("," : ").replace(")","") + " " + line.split()[1] + " " + "\n" 
            lastline = ""
          if len(line.split()) < 3:
            templine = " " + line.split()[0].replace("0x","") + " " + BlockObj + " " + line.split()[1] + " \n"
          else:
            templine = " " + line.split()[0].replace("0x","") + " " + BlockObj + " " + line.split()[1] + " " + line.split()[2] + " \n"	  
    if templine: # finish up last block
      temp_diff = int(BlockAddress, 16) + int(BlockWidth,16) - int(templine.split()[0],16)
      templine = " " + templine.split()[0].replace("0x","") + " " + hex(temp_diff).replace("L","") + " " + templine.split()[1].replace("("," : ").replace(")","") + " " + templine.split()[2]  + "\n"
      content.append(templine)
      templine = "" 
    if lastline:
      length_lastline = len(lastline.split())
      if length_lastline < 4:
        templine = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2].replace("("," : ").replace(")","") + "\n"
      else:
        templine = " " + lastline.split()[1].replace("0x","") + " " + lastline.split()[2].replace("("," : ").replace(")","") + "  " + lastline.split()[3] + "\n"
      content.append(templine)
      lastline = ""	          
  else: # i.e. an ordinary map-file
    for line in file:
      if "SECTION ALLOCATION MAP" in line:
          start_count = True
      if start_count == True:
          counter += 1
      if counter > 5: # jump over table heading
          startSections = True
      if startSections == True:
          try:
              if line.split () [3] == ":":
                  lastLibName = line.split () [2]
              elif line.split () [2] == ":":
                  line = line.split ()
                  line.insert (2, lastLibName)
                  line = "  " + " ".join (line) + "\n"
          except:
              pass
          content.append (line)
      if "LINKER GENERATED" in line:
        startSection = 0
        break
  
  # close map file
  file.close ()

  # init pass 2: scan for sections
  sectionArea = ""
  sectionContent = ""
  holeSize = 0
  if useAreas == True:
    if not "UNKNOWN" in areas:
      areas.append ("UNKNOWN")
    for a in areas:
      areaSizes [a] = 0

  # Processing Sections part (stored in content)	  
  for line in content:
    # Case 1: a new subsection starts
    if not line.startswith (" ") and not line.startswith ("*"): 
      if showEmptySections == False and objsInSections == 0:
        sectionContent = ""		
      # Wrapping up former subsection, if available
      if sectionContent != "":
        sectionContent += str (objsInSections) + " objects"
        sectionContent += " (" + str (objsInSectionSize) + ")"
        if useAreas == True:
          for a in areas:
            if sectionName in a:
              sectionArea = a.split (",") [0]
              areaSizes[a] += objsInSectionSize
              break
          if sectionArea == "":
            sectionArea = "UNKNOWN"
            areaSizes ["UNKNOWN"] += objsInSectionSize
          sectionContent += " (" + sectionArea + ")"
        if holeSize != 0:
          sectionContent += " (HOLE: " + str (holeSize) + ")"
          holeSize = 0
        if printDetails == True:
          print sectionContent
        # Initialize new sectionContent	for new subsection	
        sectionContent = ""
        sectionArea = ""
      sectionContent += "--------------------------------------------------------------------------------\n"
      sectionName = line.split (" ") [0]
      # In order to get rid of additive numbers in the Subsection title (e.g. .text.2), need to manipulate sectionName
      try:
        tempIndex = sectionName.index('.', 1)
        sectionName = sectionName[0:tempIndex]
      except:
        pass
      sectionContent += sectionName + "\n"
      # count and reset overallObjects/-Sizes		
      overallObjs += objsInSections
      objsInSections = 0
      overallSize += objsInSectionSize
      objsInSectionSize = 0
	  
    # Case 2: Within a subsection 
    else:
      if libname in line.replace("/", " ").replace("\\", " ").split():
        objsInSections += 1
        objSize = int (line.split () [1], 16)
        objsInSectionSize += objSize
        sectionContent += "   -> "
        try:
          if libname in line.split () [2] and line.split () [3] == ":":
            sectionContent += line.split () [4]
          elif libname in line.split () [2]:
            sectionContent += " (UNINITIALIZED)"
          else:
            sectionContent += line.split () [2]
        except IndexError:
          sectionContent += line.split () [2]
        sectionContent += " (" + str (objSize) + ")"
        temp = line.split ("(") [-1]
        temp = temp.split (":") [-1]
        temp = temp.replace ("\n", "")
        temp = temp.replace (")", "")	
        sectionContent += " (" + temp + ")"
        if showAddressPerObject == True:
          sectionContent += " (Addr: 0x" + line.split () [0] + ")"
        sectionContent += "\n"
      elif "--HOLE--" == line.split () [2]:  # sth wrong?!
        objSize = int (line.split () [1], 16)
        holeSize += objSize
  
  if showEmptySections == False and objsInSections == 0:
    sectionContent = ""
  
  # Wrapping up last subsection
  if sectionContent != "":
    # count overallObjects/-Sizes		
    overallObjs += objsInSections
    overallSize += objsInSectionSize
    sectionContent += str (objsInSections) + " objects"
    sectionContent += " (" + str (objsInSectionSize) + ")"
    if useAreas == True:
      for a in areas:
        if sectionName in a:
          sectionArea = a.split (",") [0]
          areaSizes[a] += objsInSectionSize
          break
      if sectionArea == "":
        areaSizes ["UNKNOWN"] += objsInSectionSize
      sectionContent += " (" + sectionArea + ")"
      if holeSize != 0:
        sectionContent += " (HOLE: " + str (holeSize) + ")"
        holeSize = 0
  if overallObjs == -1:
    overallObjs = 0
	
  if printDetails == True:
    print sectionContent
    
  ret_values = {}
  
  if debug:
    print "--------------------------------------------------------------------------------"
    print "SUMMARY (total):"
    print "    %d objects (%d bytes)" % (overallObjs, overallSize)
    print "--------------------------------------------------------------------------------"
    print "SUMMARY (separated into RAM/ROM/FUSI RAM/FUSI ROM/unknown):"
  
  for a in areas:
    area_type = a.split(',')[0]
    ret_values[area_type] = areaSizes[a]

  # Add FUSI-RXM to RXM
  ret_values["ROM"] += ret_values["FUSI-ROM"]
  ret_values["RAM"] += ret_values["FUSI-RAM"]
  
  for area_type in ['RAM', 'ROM', 'FUSI-RAM', 'FUSI-ROM', 'IGNORED', 'UNKNOWN']:
    if debug:
      print "    %-9s : %7d bytes" %(area_type, ret_values[area_type])
      pass
  
  if debug:
    print "--------------------------------------------------------------------------------"
    print "NOTE: FUSI-RXM is contained in RXM!!"
    print "      FUSI-RXM only indicates the part of RXM, which is dedicated to FUSI."
    print "--------------------------------------------------------------------------------"
    print "If interested in details (e.g. source of unknown or ignored areas):"
    print "Set 'printDetails' to 'True' (ram_rom_algo_libsize.py)"
    print "--------------------------------------------------------------------------------"
    print "Ignored areas are those containing buffers in shared regions or memory that is"
    print "used by multiple algorithms."
    print "================================================================================"
    print ""
  
  return ret_values["RAM"], ret_values["ROM"], ret_values["FUSI-RAM"], ret_values["FUSI-ROM"], ret_values["UNKNOWN"]

def writeLibSizeFile(filename, libname, ram_usage, rom_usage, fusi_ram_usage, fusi_rom_usage, unkn_area):
  """
  Function                    :  writeLibSizeFile
  Description                 :  Writes the ram/rom usage result to a text file.
  filename                    :  The target text file.
  libname                     :  Name of the library without path (String).
  ram_usage                   :  Used RAM in bytes
  rom_usage                   :  Used ROM in bytes
  fusi_ram_usage              :  Used FUSI RAM in bytes
  fusi_rom_usage              :  Used FUSI ROM in bytes
  unkn_area                   :  Used space that is neither ram nor rom (in bytes)
  Returns                     :  
  """
  f = open(filename, "w+")
  f.write("# RAM/ROM usage summary\n")
  f.write("lib=%s\n" % libname)
  f.write("ram=%i\n" % ram_usage)
  f.write("rom=%i\n" % rom_usage)
  f.write("FUSI RAM=%i\n" % fusi_ram_usage)
  f.write("FUSI ROM=%i\n" % fusi_rom_usage)
  f.write("unknown=%i\n" % unkn_area)
  f.write("total=%i\n" % (ram_usage + rom_usage + fusi_ram_usage + fusi_rom_usage + unkn_area))
  f.close()

def readLibSizeFile(filename):
  """
  Function             :  readLibSizeFile
  Description          :  Reads the ram/rom usage result from a file and returns the key-value pairs as a dictionary.
                          The keys will be converted to upper case letters. Numeric values are converted to integers, others will be kept as string.
  filename             :  The libsize text file.
  Returns              :  The content as dictionary {}
  """
  file_content = {}
  
  hFile = open(filename, "r")
  first_line = hFile.readline().strip()
  
  if (first_line == "# RAM/ROM usage summary"):
    for line in hFile:
      fields = line.strip().split("=")
      if (fields[0] == "lib"):
        file_content[fields[0].upper()] = fields[1]
      else:
        file_content[fields[0].upper()] = int(fields[1])
  
  hFile.close()
  
  return file_content

def libsize_builder(target, source, env):
  """
  Function            :  libsize_builder
  Description         :  The libsize builder callback function.
  target              :  libsize output text file.
  source              :  library
  env                 :  mapfile
  Returns             :  None
  """
  ram, rom, fusi_ram, fusi_rom, unknown = getLibInfo(str(source[1]), source[0].name)
  writeLibSizeFile(str(target[0]), File(source[0]).name, ram, rom, fusi_ram, fusi_rom, unknown)
  return None

def generateLibSize(env, libfile, mapfile, outfile):
  """
  Function             :  generateLibSize
  Description          :  Adds a new libsize builder to an environment.
  env                  :  The environment to add builder.
  libfile              :  The library to look for in mapfile (File).
  mapfile              :  The mapfile to scan (File).
  outfile              :  The file where results are written to (File).
  Returns              :  The build target.
  """
  bld_libsize = Builder(action = libsize_builder)
  env.Append(BUILDERS = {'LibSizeBuilder' : bld_libsize})
  
  return env.LibSizeBuilder([outfile], [libfile, mapfile])
  
def writeVME_VH28LibsizeFile(target, source, env):

  """
  Function            :  writeVME_VH28LibsizeFile
  Description         :  Writes the ram/rom usage result to a text file for VME/VH28 from the list of files.
  target              :  The target text file.
  source              :  list of files for VME/VH28.
  env                 :  The build environment (ignored).
  Returns             :  None
  """
  Libsize_values = {}  
  fusi_rom_all  = 0
  fusi_ram_all = 0
  rom_all = 0
  lib_all = []
  unknown_all = 0
  ram_all = 0  
  total_all = 0  
  for str1 in source:
      file_content = readLibSizeFile(str(str1))
      fusi_rom_all = fusi_rom_all + file_content['FUSI ROM']
      fusi_ram_all = fusi_ram_all + file_content['FUSI RAM']
      rom_all = rom_all + file_content['ROM']
      lib_all.append(file_content['LIB'])
      unknown_all = unknown_all + file_content['UNKNOWN']
      ram_all = ram_all + file_content['RAM']
      total_all = total_all + file_content['TOTAL']
	  
  Libsize_values["RAM"] = ram_all
  Libsize_values["ROM"] = rom_all
  Libsize_values["FUSI-RAM"] = fusi_ram_all
  Libsize_values["FUSI-ROM"] = fusi_rom_all
  Libsize_values["UNKNOWN"] = unknown_all
  Libsize_values["TOTAL"] = total_all	  
 
  f = open(str(target[0]), "w+")

  f.write("# RAM/ROM usage summary\n")
  f.write("lib = %s\n" % ', '.join(lib_all))
  f.write("ram = %i\n" % ram_all) 
  f.write("rom = %i\n" % rom_all)
  f.write("FUSI RAM = %i\n" % fusi_ram_all)
  f.write("FUSI ROM = %i\n" % fusi_rom_all)
  f.write("unknown = %i\n" % unknown_all)
  f.write("total = %i\n" % total_all)
  f.close()

  head, tail = os.path.split(str(target[0]))

  if tail in "vh28_ramrom.txt":
    print "\n"
    print "============================================================================"
    print "SUMMARY of VH28 RAM/ROM CALCULATION REPORT"	
  elif tail in "vme_ramrom.txt":
    print "\n"
    print "============================================================================"
    print "SUMMARY of VME RAM/ROM CALCULATION REPORT"  
  
  print "================================================================================"
  print "Library RAM/ROM Information: \"%s\"" % lib_all 
  print "--------------------------------------------------------------------------------"
  print "SUMMARY (separated into RAM/ROM/FUSI RAM/FUSI ROM/unknown):"
	
  for area_type in ['RAM', 'ROM', 'FUSI-RAM', 'FUSI-ROM', 'UNKNOWN', 'TOTAL']:
    print "    %-9s : %7d bytes" %(area_type, Libsize_values[area_type])
    pass
  
  print "--------------------------------------------------------------------------------"
  print "NOTE: FUSI-RXM is contained in RXM!!"
  print "      FUSI-RXM only indicates the part of RXM, which is dedicated to FUSI."
  print "--------------------------------------------------------------------------------"
  print "If interested in details (e.g. source of unknown or ignored areas):"
  print "Set 'printDetails' to 'True' (ram_rom_algo_libsize.py)"
  print "--------------------------------------------------------------------------------"
  print "Ignored areas are those containing buffers in shared regions or memory that is"
  print "used by multiple algorithms."
  print "================================================================================"
  print ""	
  return None  
    
def generateVME_VH28LibSize(env, file_list, outfile):
  """
  Function               :  generateVME_VH28LibSize
  Description            :  Adds a new VME_VH28libsize builder to an environment for VME/VH28.
  env                    :  The environment to add builder.
  file_list              :  List of files for VME/VH28 of the library/object with path (String).
  outfile                :  The file where results are written to (File).
  Returns                :  The build target.
  """
  bld_VME_VH28 = Builder(action = writeVME_VH28LibsizeFile)
  env.Append(BUILDERS = {'VME_VH28LibSizeBuilder' : bld_VME_VH28})
  
  return env.VME_VH28LibSizeBuilder([outfile], file_list)  

def main():
  
  """
  Function        :  main
  Description     :  Runs the ram/rom libsize in a python script (instead of scons).
  Returns         :  
  """
  algo_name = []
  
  try:
    algo_name.extend(os.environ ["algo"].split(","))
  except:
    pass
  
  if not algo_name:
    try:
      algo_name.append(os.environ ["component"])
    except:
      pass

  for comp in algo_name:
    try:
      execfile (os.path.abspath("../../../04_Build/" + comp + "_rrals.py"))
      mapfile = os.environ ["mapfile"]
      libname = os.environ ["libname"]
    except:
      pass
    
    try:
      getLibInfo (mapfile, libname)
    except:
      pass

if __name__ == "__main__":
  main()
