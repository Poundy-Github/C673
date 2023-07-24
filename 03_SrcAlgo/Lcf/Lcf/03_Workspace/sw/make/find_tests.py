#!/usr/bin/env python

"""Finds the tests that shall be executed for the given changes. The output is the courage build option that can be forwarded to the sw_build.bat.
If no files are given as argument, the tool will instead read the file list from stdin, which means you can pipe the output of other commands directly to this tool without using `xargs`.

Example usage (from sandbox root, for uncommitted changes):

    git diff --name-only | 04_Engineering/03_Workspace/sw/make/find_test.py
    
Or from 04_Engineering/03_Workspace/sw/make/:

    git diff --name-only | ./find_test.py
    
For committed changes, add `master...` to the git diff command, e.g.:

    git diff --name-only master... | ./find_test.py"""

from __future__ import print_function
import os.path
import sys
import argparse
import re
import fnmatch # for os.walk()
import json # for parsing the test_frames.json files
from collections import namedtuple # allows parsing json files into object-like tuples

def get_root_from_script_path():
    #                                              make  sw    03_W  04_E  sandbox root
    return os.path.realpath(os.path.join(__file__, '..', '..', '..', '..', '..'))

def get_file_list_from_args(arguments):
    if arguments.changed_files:
        file_list = arguments.changed_files
    else:
        #                                       not a delimiter
        #                                       |         quoted string with escaped quotes
        #                                       v-------v v-------------v
        file_string_extractor = re.compile(r'(?:[^\s\n,"]|"(?:\\"|[^"])*")+')
        file_list = file_string_extractor.findall(sys.stdin.read())
        file_list[:] = [x.strip('"') for x in file_list]

    if arguments.root == "sandbox root":
        file_list[:] = [os.path.realpath(os.path.join(get_root_from_script_path(), f)) for f in file_list]
    else:
        file_list[:] = [os.path.realpath(os.path.join(arguments.root, f)) for f in file_list]
    return file_list

def filter_non_files(file_list):
    existing_files = []
    for f in file_list:
        if not os.path.isfile(f):
            print('"' + f + '" is not a readable file and will be skipped!', file=sys.stderr)
        else:
            existing_files.append(f)
    return existing_files

def parse_arguments(arguments):
    parser = argparse.ArgumentParser(description = __doc__,
                                     formatter_class = argparse.RawDescriptionHelpFormatter)
    parser.add_argument('changed_files', help  = "List of files for which you want to search the corresponding tests.",
                                         nargs = '*')
    parser.add_argument('-o', '--outfile', help    = "Output file. Default is stdout.",
                                           default = sys.stdout,
                                           type    = argparse.FileType('w'))
    parser.add_argument('-r', '--root', help    = "The path which the changed files are relative to. Default is your sandbox root.",
                                        default = "sandbox root")
    return parser.parse_args(arguments)

def find_json_files():
    json_files = []
    for root, dirnames, filenames in os.walk(os.path.join(get_root_from_script_path(), '05_Testing', '05_Test_Environment', 'Dynamic_Tests')):
        for filename in fnmatch.filter(filenames, 'test_frames.json'):
            json_files.append(os.path.join(root, filename))
    return json_files

class TestFrame():
    def __init__(self):
        component      = ""
        file_name      = ""
        test_file_name = ""
        short_name     = ""
        test_path      = ""
        enabled        = False
    
    def __str__(self):
        return self.component + '#' + self.short_name

def get_test_specs(json_file_specs):
    """Returns a dictionary with { "c/cpp file path" : TestFrame }."""
    def _json_object_hook(d): return namedtuple('JsonParsedStuff', d.keys())(*d.values())
    def json2obj(file): return json.load(file, object_hook=_json_object_hook)

    test_specs = {}
    for json_file in json_file_specs:
        with open(json_file, 'r') as f:
            #print('> ' + json_file)
            jobj = json2obj(f)
            for frame in jobj.test_frames:
                test_frame = TestFrame()
                test_frame.component      = jobj.component
                test_frame.file_name      = os.path.abspath(os.path.realpath(os.path.join(get_root_from_script_path(), frame.file_name)))
                test_frame.test_file_name = frame.test_file_name
                test_frame.short_name     = frame.short_name
                test_frame.test_path      = frame.test_path
                test_frame.enabled        = frame.enabled

                test_specs[test_frame.file_name] = test_frame
    return test_specs

def build_courage_option_string(components_and_shorts):
    courage_string = "courage#"
    for comp in components_and_shorts:
        courage_string += "#" + comp + ":"
        first_short = True
        for short in components_and_shorts[comp]:
            if first_short:
                first_short = False
            else:
                courage_string += "+"
            courage_string += short
    return courage_string

def main(arguments):
    args            = parse_arguments(arguments)
    changed_files   = get_file_list_from_args(args)
    existing_files  = filter_non_files(changed_files)
    json_file_specs = find_json_files()
    test_specs      = get_test_specs(json_file_specs)
    
    components_and_shorts = {}
    covered_files = []
    for changed_file in existing_files:
        test_spec = test_specs.get(changed_file)
        if test_spec is not None:
            covered_files.append(changed_file)
            if test_spec.enabled:
                if test_spec.component not in components_and_shorts:
                    components_and_shorts[test_spec.component] = [test_spec.short_name]
                else:
                    components_and_shorts[test_spec.component].append(test_spec.short_name)
            else:
                print("Test " + test_spec.component + ":" + test_spec.short_name + " would apply to file " + changed_file + ", but it's disabled!", file=sys.stderr)
        else:
            print("There is apparently no test for " + changed_file, file=sys.stderr)
            
    courage_string = build_courage_option_string(components_and_shorts)

    print(courage_string, file=args.outfile)
    print("The following files are covered by the test:", file=sys.stderr)
    for f in covered_files:
        print("    " + f, file=sys.stderr)
    return 0

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
