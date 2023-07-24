MEMBER_VERSION = "$Revision: 1.1 $"
print "sim_subcfg_checker.py {rev}".format(rev=MEMBER_VERSION)

__author__ = 'uidw6142'

import sys

from argparse import ArgumentParser
from sim_subcfg_checker_lib import *
import os


class SimSubCfgCheckerObj():
    """
    Description: sim sub config checker command line class
    """
    def __init__(self):
        pass

    @staticmethod
    def check(args):
        """
        SimSubCfgChecker(self, args)

        Description: the sim config checker main class

        Parameter:    -args the command line options and arguments
        """
        
        #parse the arguments
        parser = ArgumentParser()
        parser.add_argument("-f", "--folder", dest="folder_to_check",
                            help="Defines the folder that has to be checked", metavar="Folder")
        parser.add_argument("-j", "--junit", dest="junit",
                            help="Tells the script to return in junit structure")
        
        options = parser.parse_args(args)
        
        #create object
        sim_vfb_cfg_parser_lib = SimVfbCfgParserLibObj(junit=options.junit)

        starting_abs_path = os.path.abspath(options.folder_to_check)
        print "Starting folder: {0}".format((starting_abs_path,))

        if not sim_vfb_cfg_parser_lib.parse_all_sim_cfg_files(starting_abs_path):
            print "Error"
        else:
            print sim_vfb_cfg_parser_lib
            # print sim_vfb_cfg_parser_lib.report
            # print sim_vfb_cfg_parser_lib.error_dict


def print_help():
    """
    PrintHelp()

    Description: Print the Help menu 
    """
    print """Usage: 
python sim_subcfg_checker.py check [options e.g. -h for help]
"""


def main(args):
    """
    main()

    Description: the main function 
    """
    
    #check for script
    if args[1] == "check":
        if len(args) < 3:
            args.append("-h")

        try:
            SimSubCfgCheckerObj.check(args[2:])
            # Exit code 1 (Ok) for algo build farm
            sys.exit(0)
        except Exception as e:
            # Catch all exceptions and return error code
            print "Execution exception:", e
            print "ABORT"
            # Exit code 0 (nOk) for algo build farm
            sys.exit(1)
    else:
        print_help()

    # Exit code -1 (args failure) for algo build farm
    sys.exit(-1)
    
# check input args
if len(sys.argv) > 1:
    main(sys.argv)
else:
    print_help()
