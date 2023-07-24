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
    conf_parser.add_argument('-o', '--output-directory',
                             help="OUTPUT for directory of m3a57 / aurix partition",
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
    conf_parser.add_argument('-c', '--component-name',
                             help="Component name for creating SDL",
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
        self.root_directory = args.root_directory
        logging.info("pdoScan init  %s", self.algo_base_dir)
        self.out_dir = args.output_directory
        self.rte_gen_include_directory = args.rte_gen_include_directory
        self.Component_Name = args.component_name
        self.EB_inlcude_dir = os.path.join(args.pdo_tool_data,"EB_Rte_4_pdo")
        self.include_dirs = []
        self.include_dirs.append(self.rte_gen_include_directory)
        self.include_dirs.append(self.EB_inlcude_dir)
        
        self.include_dirs.append(os.path.join(self.algo_base_dir, "../output/generated/include"))

           
        self.include_dir_str = ""

        # Directories and files
        self.pdo_scan_exe =args.pdo_scan_exe

    def build_inc_str(self):
        for str in self.include_dirs:
            self.include_dir_str += " -I"+str
            print( " -I"+str)

    def pdo_scan(self, args):   #from system
        self.build_inc_str()
        pdo_scan_debug = " -d 5 "
        # "-d 3" for normal use
        pdo_scan_cfg = " -c" + os.path.join(args.pdo_tool_data,"t32_tc_pdo_cmt.cfg")
        # include paths, -c {include_headers_list}
        pdo_scan_cfg = " -c" + os.path.join(args.pdo_tool_data,"../AdditionalSource/MFC5J3_DF_debug_pdo.cfg")
        pdo_scan_log = " -l" + os.path.join(args.output_directory,"pdoscan.log")
        pdo_scan_out = "-o"  + os.path.join(args.output_directory,"{0}.pdo".format(self.Component_Name))

        pdo_src_file =        os.path.join(self.algo_base_dir, "03_SrcAlgo/Fct/FctAdapter/FctAdapter.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Lcf/LcfAdapter/LcfAdapter.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Vdy/VdyAdapter/VdyAdapter.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Hla/HlaAdapter/HlaAdapter.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Tsa/TsaAdapter/TsaAdapter.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Lcf/Lcf/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_SEN/lcf_sen_main.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Lcf/Lcf/01_Source_Code/LCF/LCF_MFC431x/DPU/FRAME_VEH/lcf_veh_main.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Lcf/Lcf/01_Source_Code/LCF/Common/lcf_sen_pdo_tags_file.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Lcf/Lcf/01_Source_Code/LCF/Common/lcf_veh_pdo_tags_file.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Fct/Fct/fct/SLATE/frame_slate/slate_obj_main.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Fct/Fct/fct/LOHP/lohp/lohp_main.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Fct/Fct/fct/FCT/frame_veh/fct_veh_pdo_tags.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Fct/Fct/fct/FCT/frame_sen/fct_sen_pdo_tags.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Fct/Fct/fct/SPM/frame/spm_pdo_tags.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Fct/Fct/fct/SLATE/frame_slate/slate_pdo_tags.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Fct/Fct/fct/LOHP/frame_lohp/frame_lohp_pdo_tags.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Vdy/Vdy/01_Source_Code/VDY/vdy/vdy_main.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "03_SrcAlgo/Hla/Hla/04_Engineering/01_Source_Code/HLA/frame/hla_main.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "02_SrcAppl/SpiServ/Sdc/src/Sdc_Radar.c")
        pdo_src_file += " " + os.path.join(self.algo_base_dir, "02_SrcAppl/FSMonitor/fs_pdo.c")


        pdo_scan_cmd = self.pdo_scan_exe +" "+ pdo_scan_out + pdo_scan_cfg + pdo_scan_log  +" "+ pdo_scan_debug +" "+ self.include_dir_str +" "+ pdo_src_file
        print(pdo_scan_cmd)
        os.system(pdo_scan_cmd)

class pdoTool:
    """combining the results of all parsed sources"""
    def __init__(self, args, pdo_scan_result):
        logging.info("pdoTool init  %s", pdo_scan_result)
        self.pdo_scan_result = pdo_scan_result
        self.out_dir = args.output_directory
        self.algo_base_dir = args.algo_base_dir
        self.Component_Name = args.component_name
        # Directories and files
        self.pdo_tool_exe = args.pdo_tool_exe
        #this file name is hard coded in the SWC generator script
        self.sdl_file = os.path.join(args.output_directory, "sim_swc_{0}.sdl".format(self.Component_Name.lower()))

    def pdo_scan(self,args):
        pdo_tool_cfg = " -f sdl2.0 --disable normalobj --enable virtualobj --config " + os.path.join(args.pdo_tool_data, "tool_cfg_sdl.cfg")
        # log level 9 (debug) produces ~70MB log output! Use only if really needed.
        pdo_log_level = "3"
        pdo_tool_log = " -d " + pdo_log_level + "  -l " + os.path.join(args.output_directory,"pdotool.log")
        pdo_tool_va = " -v 0x00000000-0xFFFFFFFF --checkvirtrange 0x00000000-0xFFFFFFFF "
        pdo_tool_out = "-o"  + self.sdl_file
        pdo_tool_cmd = self.pdo_tool_exe + pdo_tool_cfg + pdo_tool_log + pdo_tool_va +" "+ self.pdo_scan_result + " " + pdo_tool_out
        print(pdo_tool_cmd)
        os.system(pdo_tool_cmd)

def main():
    """Main program"""
    logging.info("PDO scan script start")
    args = parse_args()

    logging.info("")
    
    scan = pdoScan(args)
    scan_dir = os.path.join(args.output_directory,"scan")
    scan_result = os.path.join(args.output_directory, "{0}.pdo".format(args.component_name))
    scan.pdo_scan(args)

    tool = pdoTool(args,scan_result)
    tool.pdo_scan(args)

    sys.exit(0) # no error

if __name__ == '__main__':
    main()
