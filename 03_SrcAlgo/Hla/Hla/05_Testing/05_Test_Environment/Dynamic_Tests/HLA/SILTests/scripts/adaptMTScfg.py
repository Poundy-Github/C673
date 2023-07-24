import os, sys, stat, re

print("Python version: {version} \n".format(version=sys.version))

def main():
  # Define relevant project
  project = "MFC431"
  if str(sys.argv[1]) != "":
    project = str(sys.argv[1])

  adaptCfgFile(project)
  adaptSimCfgFile(project)

def adaptCfgFile(project):
  # Define path to CFG file
  filePath = os.path.abspath("..\\..\\..\\..\\..\\..\\MTS\\05_Testing\\MTS\\mts_measurement\\cfg\\00_Projects\\" + project + "\\JOINT\\jointsim.cfg")
  
  if (os.path.isfile(filePath)):
    # Remove write protection
    os.chmod(filePath, stat.S_IWRITE)

    # Open file.
    file = open(filePath, 'r+')
  
    # Search for SIM Exporter in file
    for line in file:
      if re.search('SIM Exporter', line):
        print("SIM Exporter module already there. Nothing to do anymore.")
        return 0
        
    # SIM Exporter module is not there -> Let's add it
    string2Add = """\n
[SIM Exporter]
ChannelSources="SIM VFB"
ChannelTypes="AUTOSAR"
TabNames="SIM Exporter"
TabStates=1
Class="SIM Exporter"
Name="SIM Exporter"
Output Base File Name=""
Output Directory="..\\\\..\\\\..\\\\..\\\\..\\\\DPU\\\\05_Testing\\\\05_Test_Environment\\\\Dynamic_Tests\\\\HLA\\\\SILTests\\\\outputs"
Use Relative Path=1
Use Rec FileName=1
Signal URL Count=3
Signal URL List="SIM VFB.HLA.RTE_HLAF_HeadlightControl.sSigHeader.uiMeasurementCounter",\\
  "SIM VFB.HLA.RTE_HLAF_HeadlightControl.Matrix.HighBeamState",\\
  "SIM VFB.HLA.RTE_HLAF_HeadlightControl.Matrix.TurnOffReason"
Wildcard URL Count=0
Is Exporting=1
Trigger Type=0x0
Trigger Pos=0x1
Signal Type=0x0
Selected Time=0x186a0
Is Cycle Selected=0
Selected Cycle Source=""
Selected Cycle ID=0x0
Selected Signal=""
Export Plugin DLL="Csv Exporter"
Buffer Size="4Kb Block"
RequestPort Count=0
FileName Extension=0
RecFileName Extension=0
Section based Export=0
Export UTC Timestamp=0
"""
    
    file.write(string2Add)
    
    file.close()
      
    print("SIM Exporter successfully added to {filePath}".format(filePath=filePath))
  else:
    print("{fileName} MTS cfg file {filePath} could not be opened. Please check path.".format(fileName=os.path.basename(__file__), filePath=filePath))
    return -1


def adaptSimCfgFile(project):
  # Define path to SIM CFG file
  filePath = os.path.abspath(
    "..\\..\\..\\..\\..\\..\\MTS\\05_Testing\\MTS\\mts_measurement\\cfg\\00_Projects\\MFC431x\\JOINT\\algo_sim_all.simcfg")

  if (os.path.isfile(filePath)):
    # Remove write protection
    os.chmod(filePath, stat.S_IWRITE)

    # Open file.
    file = open(filePath, 'r+')
    fileContent = file.readlines()

    # Search for CB configuration in file
    for index, line in enumerate(fileContent):
      line = fileContent[index]

      if re.search('cb_sim_sub_meas.simcfg', line):
        print("CB already configured to meas. Nothing to do anymore.")
        return 0

      regex = re.search('(cb_sim_sub.simcfg)', line)
      if regex != None:
        # Exchange sim by meas
        fileContent[index] = line.replace(regex.group(1), 'cb_sim_sub_meas.simcfg')
        print("CB set to meas successfully in file {filePath}".format(filePath=filePath))

    # Return to beginning of source file and write back new content if needed
    file.seek(0)
    file.writelines(fileContent)

    file.close()
    return 0

    print("Pattern not found in file {filePath}".format(filePath=filePath))
  else:
    print("{fileName} MTS cfg file {filePath} could not be opened. Please check path.".format(
      fileName=os.path.basename(__file__), filePath=filePath))
    return -1

if __name__ == "__main__":
	main()