import sys
import os
import string
from sys import exit

def main (Args):
    project = Args[0]
    file_object  = open('../../../00_Projects/'+str(project)+'/MEMMAP_DPU/memory_soc0.cmd', 'r')
    binary_size = os.path.getsize('../../../04_Build/mot/SOC_allCores.bin')
    memory_area = "FLASH_CODE"
    for line in file_object:
        if line.count(memory_area) > 0:
            if line.count("len") > 0:
                i = line.find("len = ")
                size = line[i+6:i+16]
                if binary_size < int(size, 0):
                    print "############ Imagesize OK"
                    print "#### Size of FLASH_CODE section: "+str(int(size, 0))
                    print "#### Size of DPU Binary file: "+str(binary_size)
                    print "#########################"
                    error=False
                    os._exit(error)
                else:
                    print "############ Imagesize NOT OK"
                    print "#### Size of FLASH_CODE section: "+str(int(size, 0))
                    print "#### Size of DPU Binary file: "+str(binary_size)
                    print "##############################"
                    error=True
                    os._exit(error)
                
main(sys.argv[1:])