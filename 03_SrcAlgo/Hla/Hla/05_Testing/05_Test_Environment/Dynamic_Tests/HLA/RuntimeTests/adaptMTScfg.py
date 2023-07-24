import os, sys, stat, re

print "Python version: " + (sys.version) + "\n"

def main():
  # Define path to MTS config file
  filePath = os.path.abspath("..\\..\\..\\..\\..\\06_Test_Tools\\mts_measurement\\cfg\\algo\\joint\\sim_mfc400.cfg")
  
  if (os.path.isfile(filePath)):
    bAddCctEcuMonitor = True
    bAddRtaAnalysis = True
    
    # Remove write protection
    os.chmod(filePath, stat.S_IWRITE)

    # Open file.
    file = open(filePath, 'r+')
  
    # Search for MOs in file
    for line in file:
      if re.search('\[CctEcuMonitor\]', line):
        print "CctEcuMonitor module already there."
        bAddCctEcuMonitor = False
      if re.search('\[RTA Analysis\]', line):
        print "RTA Analysis module already there."
        bAddRtaAnalysis = False

    string2AddCctEcuMonitro = """\n
[CctEcuMonitor]
ChannelSources="SIM VFB"
ChannelTypes="AUTOSAR"
Class="CctEcuMonitor"
Name="CctEcuMonitor"
Position=0x1900000019
Size=0x28200000514
MinPosition=0x349000000a0
MaxPosition=0xffffffe2fffffff8
ScrollOffset=0x0
WndShowState=0x100000001
WndZOrder=1
PosLock=0
Mute=0
MinRenderInterval=0xa
RTA_CORES.xml=""
CycleCount=0x14
Reference Core=0xc
Comp ID generic adapter instrumentation 1=160
Comp ID generic adapter instrumentation 2=165
IgnoreTskSw=0
"""

    string2AddRtaAnalysis = """\n
[RTA Analysis]
ChannelSources="SIM VFB"
ChannelTypes="AUTOSAR"
Class="RTA Analysis"
Name="RTA Analysis"
Position=0x42000000f7
Size=0x30400000457
MinPosition=0xffffffffffffffff
MaxPosition=0xffffffffffffffff
ScrollOffset=0x0
WndShowState=0x1
WndZOrder=0
PosLock=0
Mute=0
RTA-Cores=""
Default Python Script="..\\\\..\\\\..\\\\..\\\\..\\\\05_Test_Environment\\\\algo\\\\inttests\\\\RuntimeTests\\\\{component}\\\\rta_evm_{component}_vh28.py"
Minimum Active Buffer=0
""".format(component=os.path.basename(os.path.abspath(os.path.join(__file__ ,".."))))
    
    if bAddCctEcuMonitor == True:
      # CctEcuMonitor module is not there -> Let's add it
      file.write(string2AddCctEcuMonitro)
      print "CctEcuMonitor successfully added."
    
    if bAddRtaAnalysis == True:
      # CctEcuMonitor module is not there -> Let's add it
      file.write(string2AddRtaAnalysis)
      print "Rta Analysis successfully added."
    
    file.close()
  else:
    print os.path.basename(__file__) + ': MTS cfg file ' + filePath + ' could not be opened. Please check path.'
    return -1
    
if __name__ == "__main__":
	main()