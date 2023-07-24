# coding=utf-8
"""
Created on 31.07.2017

@author: uidd8024
"""

import os
import sys
import subprocess
import argparse


def main():
    args = analyse_parameters()

    component = args.component
    component.upper()
    target = args.target
    product = args.product

    test_res_dir = "../../../04_Build/ModuleTests"
    test_dir = "../../../../05_Testing/05_Test_Environment/Dynamic_Tests"

    out_dir = os.path.abspath(os.path.join(os.getcwd(), test_res_dir, product, target, component))
    res_dir = os.path.abspath(os.path.join(out_dir, "Cou"))

    json_dir = os.path.abspath(os.path.join(os.getcwd(), test_dir, component, "Courage", "test_frames.json"))

    subprocess.call(" python update_cou_report.py -r " + res_dir + " -o " + out_dir + " -t -j " + json_dir, shell=True)

    print "generated test report file"
    print "report file location: " + out_dir
    
    out_file_dir = os.path.abspath(os.path.join(out_dir, "cou_summary_ctc.txt"))

    try:
        with open(out_file_dir, "r") as output_file:
            print output_file.read()
    except IOError:
        print "\nReport file was not generated " + out_file_dir
        print "Make sure to run all tests in this component with ctc coverage tool"


def analyse_parameters():
    arg_parser = argparse.ArgumentParser()
    arg_parser.add_argument("--component", "-c", default="",
                            help="MANDATORY: name of component under test")
    arg_parser.add_argument("--target", "-t", default="",
                            help="MANDATORY: name of target under test")
    arg_parser.add_argument("--product", "-p", default="",
                            help="MANDATORY: Name of product under test")
    args = arg_parser.parse_args()

    if not args.component or not args.target or not args.product:
        arg_parser.print_help()
        sys.exit()
    return args


if __name__ == '__main__':
    main()
