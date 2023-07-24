#!/usr/bin/env python3
'''

'''
import os
import shutil
import zipfile
import hashlib
import xml.etree.ElementTree as etree
import binascii
import getpass
import socket
import datetime
import sys
import logging

logging.basicConfig(level=logging.INFO)

class pdoScan:
    """parsing propetary commented C sources"""
    def __init__(self, pdo_tool_dir,algo_base_dir,rte_gen_incl_dir):
        self.algo_base_dir = algo_base_dir
        logging.info("pdoScan init  %s",self.algo_base_dir)
        self.out_dir = os.path.join(os.getcwd(), "temp")
        #self.CML_inlcude_dir = r'D:\Work\20200305_PAD21_FSF500\project-adc420ha10-pad21\components\swc\dfunc-common'
        self.EB_inlcude_dir = os.path.join(os.getcwd(), "pdo_tool","EB_Rte_4_pdo")
        self.ACDC2_proj_dir = os.path.join(algo_base_dir, r'ACDC2\04_Engineering\00_Projects\ADC420HA10-PAD21')
        self.ACDC2_src_dir = os.path.join(algo_base_dir,  r'ACDC2\04_Engineering\01_Source_Code')
        self.MEDIC_proj_dir = os.path.join(algo_base_dir, r'MEDIC\04_Engineering\00_Projects\ADC420HA10')
        self.MEDIC_src_dir = os.path.join(algo_base_dir,  r'MEDIC\04_Engineering\01_Source_Code')
        self.include_dirs = []
        self.include_dirs.append(rte_gen_incl_dir)
        self.include_dirs.append(self.EB_inlcude_dir)
        self.include_dirs.append(r'D:\Work\20200305_PAD21_FSF500\project-adc420ha10-pad21\components\swc\FSF500\swc\MEDIC\04_Engineering\01_Source_Code\MEDIC')
        self.include_dirs.append(r'D:\Work\20200305_PAD21_FSF500\project-adc420ha10-pad21\components\swc\FSF500\swc\MEDIC\04_Engineering\00_Projects\ADC420HA10\MEDIC')
        self.include_dir_str = ""

        # Directories and files
        self.pdo_scan_exe = os.path.join(pdo_tool_dir, "pdo_scan.exe")

    def build_inc_str(self):
        #self.add_includes()
        for str in self.include_dirs:
            self.include_dir_str += " -I"+str
            print( " -I"+str)

    def add_includes(self):
        #self.add_include(self.EB_inlcude_dir)
        #self.add_include(self.CML_inlcude_dir)
        self.add_include(self.ACDC2_proj_dir)
        self.add_include(self.ACDC2_src_dir)
        self.add_include(self.MEDIC_proj_dir)
        self.add_include(self.MEDIC_src_dir)
        self.include_dirs = list(set(self.include_dirs))
        #print(self.include_dirs)

    def add_include(self, prjDir):
        #logging.info("add_include %s",prjDir)
        for root, dirs, files in os.walk(prjDir, topdown=False):
            for name in dirs:
                #logging.info("add_include: %s", os.path.join(root, name))
                self.include_dirs.append(os.path.join(root, name))


    def pdo_scan(self,out_dir):
        self.build_inc_str()
        pdo_scan_debug = " -d 3 "
        pdo_scan_cfg = " -c"+ os.path.join(os.getcwd(), "pdo_tool","arm_a53_pdo_cmt.cfg")
        pdo_scan_log = " -l" + os.path.join(out_dir,"pdoscan.log")
        #pdo_scan_log = "-l" + out_dir
        #pdo_scan_out = "-o" + out_dir
        pdo_scan_out = "-o"  + os.path.join(out_dir,"FSF500.pdo")
        pdo_src_file =  r'D:\Work\20200305_PAD21_FSF500\project-adc420ha10-pad21\components\swc\FSF500\swc\MEDIC\04_Engineering\01_Source_Code\MEDIC\frame_medic\medic_pdo_tags.c'
        pdo_scan_cmd = self.pdo_scan_exe +" "+ pdo_scan_out + pdo_scan_cfg + pdo_scan_log  +" "+ pdo_scan_debug +" "+ self.include_dir_str +" "+ pdo_src_file
        print(pdo_scan_cmd)
        os.system(pdo_scan_cmd)



class pdoTool:
    """combining the results of all parsed sources"""
    def __init__(self, pdo_tool_dir, pdo_scan_results_dir):
        logging.info("pdoTool init  %s",pdo_scan_results_dir)
        self.pdo_scan_results_dir = pdo_scan_results_dir
        self.out_dir = os.path.join(os.getcwd(), "temp")
        # Directories and files
        self.pdo_tool_exe = os.path.join(pdo_tool_dir, "pdo_tool.exe")

    def pdo_scan(self,out_dir):
        cycleinfo = " CEM_data 130 "  # ????
        pdo_tool_cfg = " -f sdl2.0 --disable normalobj --enable virtualobj --cycleinfo" + cycleinfo
        # log level 9 (debug) produces ~70MB log output! Use only if really needed.
        pdo_log_level = "4"
        pdo_tool_log = " -l " + pdo_log_level + " " + os.path.join(out_dir,"pdotool.log")
        pdo_tool_va = " -v 0x00000000-0xFFFFFFFF --checkvirtrange 0x00000000-0xFFFFFFFF "
        #pdo_scan_out = "-o" + out_dir
        pdo_too_out = "-o"  + os.path.join(out_dir,"FSF500.pdo")
        pdo_src_file =  r'D:\Work\20200305_PAD21_FSF500\project-adc420ha10-pad21\components\swc\FSF500\swc\MEDIC\04_Engineering\01_Source_Code\MEDIC\frame_medic\medic_pdo_tags.c'
        pdo_tool_cmd = self.pdo_tool_exe + pdo_tool_cfg + pdo_tool_log + pdo_tool_va +" "+ self.pdo_scan_results_dir +" -o "+ out_dir
        print(pdo_tool_cmd)
        os.system(pdo_tool_cmd)


def main():
    """Main program"""
    logging.info("PDO scan script start")
    try:
        pdo_tool_dir  = sys.argv[1]
        out_dir       = sys.argv[2]
        algo_base_dir = sys.argv[3]
        rte_gen_incl_dir = sys.argv[4]
    except IndexError:
        print('Usage:  ')
        sys.exit(1)

    logging.info("pdo_tool_dir: %s",pdo_tool_dir)
    logging.info("out_dir: %s",out_dir)
    logging.info("algo_base_dir: %s",algo_base_dir)


    logging.info("")


    #scan = pdoScan(pdo_tool_dir,algo_base_dir,rte_gen_incl_dir)
    #scan.pdo_scan(out_dir)

    tool = pdoTool(pdo_tool_dir,out_dir)
    tool.pdo_scan(out_dir)


    sys.exit(0)  # no error

if __name__ == '__main__':
    main()
