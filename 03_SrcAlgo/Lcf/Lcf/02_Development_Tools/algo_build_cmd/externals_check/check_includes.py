import os
import sys
import re

skip_file_pattern =["srhcl_clfpar", "srhcl_classifierparamspc", "srhcl_classifierpc", "srcld_color_LUT_day_YUV", "srcld_color_LUT_night_YUV", "ct_day", "ct_night", "mbike_day", "mbike_night", "bicycle_day_detector", "bicycle_night_detector", "ped_day_detector", "ped_night_detector" ]
def checkfile(file):
    for patt in skip_file_pattern:
        if patt in file:
            return True
    return False

def scan_file_for_includes(file, do_file_check = False):
    includes =  []
    size = os.path.getsize(file)
    file_object = open(file, "r")
    if do_file_check == True and checkfile(file) == True:
        #print "skipp"
        lines = file_object.readlines(50)
    else:
        lines = file_object.readlines()
        
    for line in lines:
#        if "include" in line:
#            print line    
        result = re.findall(r'^\s*#include\s+[<"](\w+\.\w+)[>"].*', line)
        if len(result) > 0 and len(result[0]) > 0:
            #print line
            #print result[0]
            includes.append(result[0])
        #print line
    file_object.close()
    return includes

h_hpp_dict = {}
c_cpp_dict = {}
h_hpp_ext_list = [".h",".hpp"]
c_cpp_ext_list = [".c",".cpp"]
for root, dirs, files in os.walk(".", topdown=False):
    for name in files:
        ext =  os.path.splitext(name)[1]
        if ext in h_hpp_ext_list:
            h_hpp_dict[name.lower()] = os.path.join(root, name)
        if ext in c_cpp_ext_list:
            c_cpp_dict[name.lower()] = os.path.join(root, name)

for root, dirs, files in os.walk(r"..\05_Deliverables\include", topdown=False):
    for name in files:
        ext =  os.path.splitext(name)[1]
        if ext in h_hpp_ext_list:
            if name not in h_hpp_dict:
                h_hpp_dict[name.lower()] = os.path.join(root, name)
        if ext in c_cpp_ext_list:
            if name not in c_cpp_dict:
                c_cpp_dict[name.lower()] = os.path.join(root, name)
        
        #print(os.path.join(root, name))
#    for name in dirs:
#        print(os.path.join(root, name))

external_includes = {}
comp_external_includes = {}
print "Scanning h and hpp files for includes"
total = len(h_hpp_dict)
counter = 0
for file in h_hpp_dict:
    print "Scanned %s from %s"%(counter, total)
    print h_hpp_dict[file]
    include_files = scan_file_for_includes(h_hpp_dict[file])
    for include in include_files:
        include_l = include.lower() 
        if include_l not in h_hpp_dict:
            #print h_hpp_dict[file]
            #print include_l
            path_split = h_hpp_dict[file].split('\\')
            if path_split > 3:
                comp_name = path_split[2]
            else:
                comp_name = path_split[1]
            if comp_name not in comp_external_includes:
                comp_external_includes[comp_name] = {}
            if include_l not in comp_external_includes[comp_name]:
                comp_external_includes[comp_name][include_l] = []
            comp_external_includes[comp_name][include_l].append(h_hpp_dict[file])
                
            if include_l not in external_includes:
                external_includes[include_l] = []
            external_includes[include_l].append(h_hpp_dict[file])
            
    counter += 1
    
print "Scanning c and cpp files for includes"
total = len(c_cpp_dict )
counter = 0
for file in c_cpp_dict:
    print "Scanned %s from %s"%(counter, total)
    #print c_cpp_dict[file]
    include_files = scan_file_for_includes(c_cpp_dict[file],True)
    for include in include_files:
        include_l = include.lower() 
        if include_l not in h_hpp_dict and include_l not in c_cpp_dict:
            #print c_cpp_dict[file]
            #print include_l
            path_split = c_cpp_dict[file].split('\\')
            if path_split > 3:
                comp_name = path_split[2]
            else:
                comp_name = path_split[1]
            if comp_name not in comp_external_includes:
                comp_external_includes[comp_name] = {}
            if include_l not in comp_external_includes[comp_name]:
                comp_external_includes[comp_name][include_l] = []
            comp_external_includes[comp_name][include_l].append(c_cpp_dict[file])

            if include_l not in external_includes:
                external_includes[include_l] = []
            external_includes[include_l].append(c_cpp_dict[file])
    counter += 1

len_dict = {}
fo = open("external_or_missing_include_files.log", "w")
fo.write("--- External or missing includes used by module ---\n")
for missing in sorted(external_includes.keys()):
    if len(external_includes[missing]) not in len_dict:
        len_dict[len(external_includes[missing])] = []
    len_dict[len(external_includes[missing])].append(missing)
    print "include %s is external or missing and used by%s"%(missing, external_includes[missing])
    fo.write("include %s is external or missing and used by%s\n"%(missing, external_includes[missing]))
fo.write("\n")
fo.write("\n")
fo.write("--- External or missing includes for each component ---\n")
for comp in sorted(comp_external_includes.keys()):
    fo.write("---- Component %s -----\n"%(comp))
    for include in sorted(comp_external_includes[comp].keys()):
        fo.write("include %s is external or missing and used by%s\n"%(include, comp_external_includes[comp][include]))

fo.write("\n")
fo.write("\n")
fo.write("--- Ranking most used externals ---\n")
counter = 1
for len in sorted(len_dict.keys(), reverse=True):
    for include in len_dict[len]:
        line = "%s. %s is used %s times"%(counter, include, len)
        fo.write("%s \n"%(line))
        counter += 1
        
fo.close()