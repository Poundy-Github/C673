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
from argparse import ArgumentParser, RawDescriptionHelpFormatter

logging.basicConfig(level=logging.INFO)

def parse_args():
    """
    parses arguments
    :return: return arguments
    """
    conf_parser = ArgumentParser(add_help=False)

    conf_parser.add_argument('-r', '--root-directory',
                             help="Path to the root directory of the project-adc420ha10-pad21",
                            )
    conf_parser.add_argument('-v', '--verbose',
                             help="verbose output",
                             action="store_true",
                             default=False,
                            )
    conf_parser.add_argument('-p', '--pdo-tool',
                             help="PDO data path",
                            )
    conf_parser.add_argument('-d', '--pdo-tool-data',
                             help="PDO data path",
                            )
    conf_parser.add_argument('-o', '--output-directory-fsf',
                             help="OUTPUT for FSF directory of m3a57 partition",
                            )
    conf_parser.add_argument('-a', '--algo-base-dir',
                             help="FSF500 component path",
                            )
    conf_parser.add_argument('-i', '--rte-gen-include-directory',
                             help="Generated include directory from OUTPUT",
                            )
    conf_parser.add_argument('-s', '--pdo-scan-exe',
                             help="pdo_scan.exe path",
                            )
    conf_parser.add_argument('-t', '--pdo-tool-exe',
                             help="pdo_tool.exe path",
                            )

    args = conf_parser.parse_args()

    if args.verbose:
        print('Arguments:')
        print(vars(args))

    return args

class pdoScan:
    """parsing propetary commented C sources"""
    def __init__(self, args):
        self.algo_base_dir = args.algo_base_dir
        logging.info("pdoScan init  %s",self.algo_base_dir)
        self.out_dir = args.output_directory_fsf
        self.rte_gen_include_directory = args.rte_gen_include_directory
        self.EB_inlcude_dir = os.path.join(args.pdo_tool_data,"EB_Rte_4_pdo")
        self.ACDC2_proj_dir = os.path.join(self.algo_base_dir, r'ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21')
        self.ACDC2_src_dir = os.path.join(self.algo_base_dir,  r'ACDC2/04_Engineering/01_Source_Code')
        self.MEDIC_proj_dir = os.path.join(self.algo_base_dir, r'MEDIC/04_Engineering/00_Projects/ADC420HA10')
        self.MEDIC_src_dir = os.path.join(self.algo_base_dir,  r'MEDIC/04_Engineering/01_Source_Code')
        self.include_dirs = []
        self.include_dirs.append(self.rte_gen_include_directory)
        self.include_dirs.append(self.EB_inlcude_dir)
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/01_Source_Code/ACDC2"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/01_Source_Code"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21/ACDC2"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21/GA"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21/ACDC2/ports"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21/ACDC2/ps"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21/ACDC2/sa"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21/ACDC2/sa/hypothesis"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "MEDIC/04_Engineering/01_Source_Code/MEDIC"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "MEDIC/04_Engineering/01_Source_Code/MEDIC/frame_medic"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "MEDIC/04_Engineering/00_Projects/ADC420HA10/MEDIC"))
        self.include_dirs.append(os.path.join(self.algo_base_dir, "MEDIC/04_Engineering/00_Projects/ADC420HA10/MEDIC/frame_medic"))
        self.include_dir_str = ""

        # Directories and files
        self.pdo_scan_exe =args.pdo_scan_exe

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


    def pdo_scan(self, args):   #from system
        self.build_inc_str()
        pdo_scan_debug = " -d 3 "
        pdo_scan_cfg = " -c"+ os.path.join(args.pdo_tool_data,"arm_a53_pdo_cmt.cfg")
        pdo_scan_log = " -l" + os.path.join(args.output_directory_fsf,"pdoscan.log")
        #pdo_scan_log = "-l" + out_dir
        #pdo_scan_out = "-o" + out_dir
        pdo_scan_out = "-o"  + os.path.join(args.output_directory_fsf,"FSF500.pdo")
        pdo_src_file =  os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/01_Source_Code/ACDC2/acdc_pdo_tags.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "ACDC2/04_Engineering/00_Projects/ADC420HA10-PAD21/GA/ga_acdc2_wrapper.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "MEDIC/04_Engineering/00_Projects/ADC420HA10/MEDIC/frame_medic/medic_custom_pdo_tags.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "MEDIC/04_Engineering/00_Projects/ADC420HA10/MEDIC/frame_medic/medic_ga_wrapper.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "MEDIC/04_Engineering/01_Source_Code/MEDIC/frame_medic/medic_pdo_tags.c")
        pdo_scan_cmd = self.pdo_scan_exe +" "+ pdo_scan_out + pdo_scan_cfg + pdo_scan_log  +" "+ pdo_scan_debug +" "+ self.include_dir_str +" "+ pdo_src_file
        print(pdo_scan_cmd)
        os.system(pdo_scan_cmd)



class pdoTool:
    """combining the results of all parsed sources"""
    def __init__(self, args, pdo_scan_result):
        logging.info("pdoTool init  %s",pdo_scan_result)
        self.pdo_scan_result = pdo_scan_result
        self.out_dir = args.output_directory_fsf
        # Directories and files
        self.pdo_tool_exe = args.pdo_tool_exe
        #this file name is hard coded in the SWC generator script
        self.sdl_file=os.path.join(args.pdo_tool, "build_dir", "sdl", "ap_pdo_gen.sdl")

    def pdo_scan(self,args):
        cycleinfo = " FCT_VEH 60 " # ????
        pdo_tool_cfg = " -f sdl2.0 --disable normalobj --enable virtualobj --cycleinfo default,ACDC2_ENV,MEDIC_ENV FSF500_view 60 " #+ cycleinfo
        # log level 9 (debug) produces ~70MB log output! Use only if really needed.
        pdo_log_level = "3"
        pdo_tool_log = " -d " + pdo_log_level + "  -l " + os.path.join(args.output_directory_fsf,"pdotool.log")
        pdo_tool_va = " -v 0x00000000-0xFFFFFFFF --checkvirtrange 0x00000000-0xFFFFFFFF "
        #pdo_scan_out = "-o" + out_dir
        pdo_tool_out = "-o"  + self.sdl_file
        pdo_src_file =  os.path.join(args.algo_base_dir, "MEDIC/04_Engineering/01_Source_Code/MEDIC/frame_medic/medic_pdo_tags.c")
        pdo_tool_cmd = self.pdo_tool_exe + pdo_tool_cfg + pdo_tool_log + pdo_tool_va +" "+ self.pdo_scan_result + " " + pdo_tool_out
        print(pdo_tool_cmd)
        os.system(pdo_tool_cmd)


def main():
    """Main program"""
    logging.info("PDO scan script start")
    args = parse_args()


    logging.info("")


    scan = pdoScan(args)
    scan_dir = os.path.join(args.output_directory_fsf,"scan")
    scan_result = os.path.join(args.output_directory_fsf, "FSF500.pdo")
    scan.pdo_scan(args)


    tool = pdoTool(args,scan_result)
    tool.pdo_scan(args)

    sys.exit(0) # no error

if __name__ == '__main__':
    main()
