"""
Filename                  : scons_common_scripts\doxygen\convert_xml.py
Description               : Python script for xml conversion for doxygen documentation. 
"""
#***************************************************************************************************
# COMPANY: Continental AG, ADAS, A.D.C. GmbH
#
# PROJECT: ETK/SCT_Sconstools
#
# COMPONENT: scons_common_scripts
#
# MODULE NAME: doxygen\convert_xml.py
#
# DESCRIPTION: Python script for xml conversion for doxygen documentation. 
#
# INITIAL AUTHOR: Jahnke, Andreas (uidw8971)
#
# CREATION DATE: 2014/01/29
#
# LAST CHANGE:      $Date: 2021/12/13 19:05:07CET $
#                   $Author: Wang, David (Wangd3) $
#
# CURRENT VERSION:  $Revision: 1.1 $
#############################################################################
# CHANGES:                   $Log: convert_xml.py  $
# CHANGES:                   Revision 1.1 2021/12/13 19:05:07CET Wang, David (Wangd3) 
# CHANGES:                   Initial revision
# CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/02_Development_Tools/scons_tools/scons_common_scripts/doxygen/project.pj
# CHANGES:                   Revision 1.14 2016/06/30 09:04:28CEST Annashamachar, Shwetha (uidj8746) 
# CHANGES:                   File header added
# CHANGES:                   Revision 1.13 2015/06/26 08:34:51CEST Palanisamy-EXT, Lenin (uidr0826) 
# CHANGES:                   Add revision label with module description for all GSCons files (Issue 320651)
# CHANGES:                   - Added comments -  uidr0826 [Jun 26, 2015 8:34:51 AM CEST]
# CHANGES:                   Change Package : 350940:1 http://mks-psad:7002/im/viewissue?selection=350940

#***************************************************************************************************

from xml.dom.minidom import parse
import string
import sys

base_directory = "./xml"

# @brief parses a doxygen-C xml file and writes function name and brief description to plain text file
# @param in_file_name name of the input xml file
# @param src_file_name name of the source code file
# @param out_file file handle to the output file
# @param heading_number heading number as integer
# @pre file in_file_name must exist and read permissions are required
# @pre out_file is an open file handle with write-access
def ParseCFile(in_file_name, src_file_name, out_file, heading_number):
    # read XML file: returns a Document object
    print in_file_name
    dom = None
    
    out_file.write("0.")
    out_file.write(str(heading_number))
    out_file.write(" ")
    out_file.write(src_file_name)
    out_file.write("\r\n")
    out_file.write("\r\n")    
    
    try:
        dom = parse(in_file_name)
    except:
        print "exception reading file " + in_file_name
        print sys.exc_info()
        print sys.exc_traceback
        return
    if dom != None:
        # function number
        u_fcn_number = 0
        # search for file description compounddef kind ="fil"/detaileddescription
        b_file_description_available = 0
        # search first occurance of "compounddef"
        filedesc_list = dom.getElementsByTagName("compounddef")
        # any occurances found ?
        if filedesc_list != None:
            # YES - search for attribute kind="file"
            for fdesc in filedesc_list:
                # get value of attribute "kind"
                fdesk_attr_kind = fdesc.getAttribute('kind')
                # Attribute value matches "file" ?
                if fdesk_attr_kind == "file":
                    # YES - search detaileddescription
                    detdesc_list = dom.getElementsByTagName("detaileddescription")
                    # detailed description found?
                    if detdesc_list != None:
                        # YES - search for "DESCRIPTION" in values
                        if detdesc_list.length > 0:
                            para_list = detdesc_list[detdesc_list.length-1].getElementsByTagName("para")
                            # search for "DESCRIPTION" in values
                            for para in para_list:
                                try:
                                    para_value = para.firstChild.toxml()
                                except:
                                    continue
                                ind = string.find(para_value, 'DESCRIPTION:')
                                if ind >= 0:
                                    # get description string
                                    description_value = string.replace(para_value, "DESCRIPTION: ", "")
                                    b_file_description_available = 1
                                    out_file.write(description_value)
                                    out_file.write("\r\n")
                                    out_file.write("\r\n")
                                    break
                if b_file_description_available == 1:
                    break
        if b_file_description_available == 0:
            out_file.write("<file description>")
            out_file.write("\r\n")
            out_file.write("\r\n")
            
        # search for all occurances of noed "sectiondef"
        node_list = dom.getElementsByTagName("sectiondef")
        # Is result list not empty?
        if node_list != None:
            # YES - read content
            # Is result collection length > 0 ?
            if node_list.length > 0:
                # YES - precess all seciondef-nodes
                for node in node_list:                   
                    # get attribute value of 'kind'
                    a = node.getAttribute('kind')
                    # Is attribute value equal to "func"
                    if a == "func":
                        # YES - prcess nodes 'memberdef' to find function name and description
                        # search all subnodes 'memberdef'
                        mem = node.getElementsByTagName('memberdef')
                        # process all subnodes
                        for m in mem:
                            # get attribute value of attribute 'kind'
                            am = m.getAttribute('kind')
                            # Is it a function?
                            if am == "function":
                                # YES - search function name
                                b_names_avail = 0
                                # search function name
                                names = m.getElementsByTagName('name')
                                # funcstion name found?
                                if names != None:
                                    # YES - write function name to file
                                    if names.length > 0:
                                        u_fcn_number = u_fcn_number + 1
                                        try:
                                            content = names[0].firstChild.toxml()
                                        except:
                                            continue
                                        #print content
                                        out_file.write("0.")
                                        out_file.write(str(heading_number))
                                        out_file.write(".")
                                        out_file.write(str(u_fcn_number))
                                        out_file.write(" ")
                                        out_file.write(content)
                                        out_file.write("\r\n")
                                        out_file.write("\r\n")
                                        b_names_avail = 1
                                # Is function available ?
                                if b_names_avail == 1:
                                    # YES - search brief function description
                                    briefs = m.getElementsByTagName('briefdescription')
                                    # brief function description found?
                                    if briefs != None:
                                        # YES - write function description to file
                                        if briefs.length > 0:
                                            paras = briefs[briefs.length-1].getElementsByTagName('para')
                                            if paras.length > 0:
                                                try:
                                                    content = paras[0].firstChild.toxml()
                                                except:
                                                    out_file.write("<description>")
                                                    continue
                                                #print content
                                                fcn_ind = string.find(content, 'Description')
                                                if fcn_ind >= 0:
                                                    # get description string
                                                    fcn_desc_value = string.replace(content, "Description", "")
                                                    fcn_desc_value = string.lstrip(fcn_desc_value)
                                                    dp_ind = string.find(fcn_desc_value, ':')
                                                    if dp_ind >= 0:
                                                        fcn_desc_value = string.replace(fcn_desc_value, ":", "")
                                                        fcn_desc_value = string.lstrip(fcn_desc_value)
                                                    out_file.write(fcn_desc_value)
                                                else:
                                                    out_file.write(content)
                                            else:
                                                out_file.write("<description>")
                                        else:
                                            out_file.write("<description>")
                                    else:
                                        out_file.write("<description>")
                                    out_file.write("\r\n")
                                    out_file.write("\r\n")
        # release object
        dom.unlink()

# @brief parses a C++ class xml file and writes class documentation and function documentation to plain text file
# @param in_file_name name of the input xml file
# @param src_file_name name of the source code file
# @param out_file file handle to the output file
# @param heading_number heading number as integer
# param kind_of_ds kind of data structure as string (class, struct)
# @pre file in_file_name must exist and read permissions are required
# @pre out_file is an open file handle with write-access
def ParseCppFile(in_file_name, out_file, heading_number, kind_of_ds):
    # read XML file: returns a Document object
    print in_file_name
    dom = None
    try:
        # read XML file: returns a Document object
        dom = parse(in_file_name)
    except:
        print "exception reading file " + in_file_name
        print sys.exc_info()
        print sys.exc_traceback
        return
    # loading XML succeeded?
    if dom != None:
        # YES - parse class and function docuementation

        # function index
        u_fcn_number = 0
        # class/struct name
        cl_name = ""

        # parse class name
        compound_name_list = dom.getElementsByTagName("compoundname")
        if compound_name_list != None:
            if compound_name_list.length > 0:
                out_file.write("0.")
                out_file.write(str(heading_number))
                out_file.write(" ")
                out_file.write(kind_of_ds)
                out_file.write(" ")
                try:
                    cl_name = compound_name_list[0].firstChild.toxml()
                except:
                    cl_name = in_file_name
                # C++ template support
                cl_name = string.replace(cl_name, "&lt;", "<")
                cl_name = string.replace(cl_name, "&gt;", ">")
                # write class name
                out_file.write(cl_name)  
        else:
            return
            
        # parse location@file: class' header file
        location_list = dom.getElementsByTagName("location")
        if location_list != None:
            if location_list.length > 0:
                file_path = location_list[location_list.length-1].getAttribute('file')
                file_name_arr = string.split(file_path, '/')
                if file_name_arr.__len__() > 0:
                    file_name = file_name_arr[file_name_arr.__len__() - 1]
                    out_file.write(" (")
                    out_file.write(file_name)
                    out_file.write(") ")
                    out_file.write("\r\n")
        out_file.write("\r\n")
        out_file.write("\r\n")
            
        # parse brief class desription
        brief_desc_available = 0
        brief_list = dom.getElementsByTagName("briefdescription")
        if brief_list != None:
            if brief_list.length > 0:
                brief_node = brief_list[brief_list.length-1]
                para_list = brief_node.getElementsByTagName("para")
                if para_list != None:
                    if para_list.length > 0:
                        brief_desc_str = ""
                        try:
                            brief_desc_str = para_list[0].firstChild.toxml()
                        except:
                            brief_desc_str = "<" + kind_of_ds + " description>"
                        out_file.write(brief_desc_str)
                        out_file.write("\r\n")
                        out_file.write("\r\n")
                        brief_desc_available = 1
        if brief_desc_available == 0:
            out_file.write("<")
            out_file.write(kind_of_ds)
            out_file.write(" description>")
            out_file.write("\r\n")
            out_file.write("\r\n")
            
        # search for all occurances of noed "sectiondef"
        node_list = dom.getElementsByTagName("sectiondef")
        for node in node_list:
            
            kind_attr_str = node.getAttribute('kind')
            if ((kind_attr_str == "public-func") or
                (kind_attr_str == "public-static-func") or
                (kind_attr_str == "protected-func") or
                (kind_attr_str == "protected-static-func") or
                (kind_attr_str == "private-func") or
                (kind_attr_str == "private-static-func")):
                memdef_list = node.getElementsByTagName("memberdef")
                if memdef_list != None:
                    for memdef in memdef_list:
                        fcn_kind = memdef.getAttribute('kind')
                        if fcn_kind == "function":
                            try:
                                # print content heading numbers + class name + "::"
                                u_fcn_number = u_fcn_number + 1
                                out_file.write("0.")
                                out_file.write(str(heading_number))
                                out_file.write(".")
                                out_file.write(str(u_fcn_number))
                                out_file.write(" ")
                                try:
                                    out_file.write(cl_name)
                                except:
                                    print sys.exc_info()
                                    print sys.exc_traceback
                                out_file.write("::")
                            except:
                                print sys.exc_info()
                                print sys.exc_traceback
                            name_list = memdef.getElementsByTagName("name")
                            if name_list != None:
                                if name_list.length > 0:
                                    try:
                                        value = name_list[0].firstChild.toxml()
                                        out_file.write(value)
                                        out_file.write("\r\n")
                                        out_file.write("\r\n")
                                    except:
                                        continue
                            briefs = memdef.getElementsByTagName('briefdescription')
                            # brief function description found?
                            if briefs != None:
                                # YES - write function description to file
                                if briefs.length > 0:
                                    paras = briefs[briefs.length-1].getElementsByTagName("para")
                                    if paras.length > 0:
                                        try:
                                            content = paras[0].firstChild.toxml()
                                        except:
                                            out_file.write("<description>")
                                            continue
                                        #print content
                                        fcn_ind_cpp = string.find(content, 'Description')
                                        if fcn_ind_cpp >= 0:
                                            # get description string
                                            fcn_desc_value_cpp = string.replace(content, "Description", "")
                                            fcn_desc_value_cpp = string.lstrip(fcn_desc_value_cpp)
                                            dp_ind_cpp = string.find(fcn_desc_value_cpp, ':')
                                            if dp_ind_cpp >= 0:
                                                fcn_desc_value_cpp = string.replace(fcn_desc_value_cpp, ":", "")
                                                fcn_desc_value_cpp = string.lstrip(fcn_desc_value_cpp)
                                            out_file.write(fcn_desc_value_cpp)
                                        else:
                                            out_file.write(content)
                                    else:
                                        out_file.write("<description>")
                                else:
                                    out_file.write("<description>")
                            else:
                                out_file.write("<description>")
                            out_file.write("\r\n")
                            out_file.write("\r\n")
        dom.unlink()
        return

def ParseIndexFile(index_file_name, out_file):
    global base_directory
    # file counter used as heading number
    u_HeadingNr = 0
    # parse XML file
    dom = parse(index_file_name)
    # get all elements of tag name "compound"
    node_list = dom.getElementsByTagName('compound')
    # Any elements found ?
    if node_list != None:
        # YES - over all compound elements and search all file documentations
        for node in node_list:
            # get value of attribute "kind"
            attr_kind_str = node.getAttribute('kind')
            # Does current element point to a file documentation ?
            if attr_kind_str == "file":
                # YES - get all subnodes of tag name "name"
                name_list = node.getElementsByTagName('name')
                # Is result list not empty ?
                if name_list != None:
                    # YES - get element value
                    name_value = name_list[0].firstChild.toxml()
                    # Search file extension ".c"
                    str_index = string.rfind(name_value, '.c')
                    if str_index > 0:
                        # YES - parse c/CPP file
                        # 1 if functions in struct
                        b_c_has_functions = 0
                        # get member list
                        member_list = node.getElementsByTagName('member')
                        # search for functions
                        for member in member_list:
                            # get attribute 'kind'
                            mem_kind = member.getAttribute('kind')
                            # Is struct member a function ?
                            if mem_kind == "function":
                                # YES - set flog to parse the struct XML file
                                b_c_has_functions = 1
                                break
                        # Functions defined in struct ?
                        if b_c_has_functions == 1:
                            # YES - parse struct XML
                            # increase heading number
                            u_HeadingNr = u_HeadingNr + 1
                            # create XML file name
                            file_name = node.getAttribute('refid')
                            file_name = file_name + ".xml"
                            # parse C file
                            c_file = base_directory  + "/" + file_name
                            ParseCFile(c_file, name_value, out_file, u_HeadingNr)
                            out_file.write("\r\n")
                            out_file.write("\r\n")
                        else:
                            print "no functions defined in " + name_value
                    else:
                        # Search file extension ".cpp"
                        str_index = string.rfind(name_value, '.cpp')
                        # Is it a C++ file ?
                        if str_index > 0:
                            # YES - parse it if functions are available
                            # 1 if functions in struct
                            b_cpp_has_functions = 0
                            # get member list
                            member_list = node.getElementsByTagName('member')
                            # search for functions
                            for member in member_list:
                                # get attribute 'kind'
                                mem_kind = member.getAttribute('kind')
                                # Is struct member a function ?
                                if mem_kind == "function":
                                    # YES - set flog to parse the struct XML file
                                    b_cpp_has_functions = 1
                                    break
                            # Functions defined in CPP file ?
                            if b_cpp_has_functions == 1:                            
                                # YES - parse c/CPP file
                                u_HeadingNr = u_HeadingNr + 1
                                # create XML file name
                                file_name = node.getAttribute('refid')
                                file_name = file_name + ".xml"
                                # parse C file
                                c_file = base_directory  + "/" + file_name
                                ParseCFile(c_file, name_value, out_file, u_HeadingNr)
                                out_file.write("\r\n")
                                out_file.write("\r\n")
                            else:
                                print "no functions defined in " + name_value
            elif attr_kind_str == "class":
                # YES - parse CPP file
                # 1 if functions definitions in class
                b_class_has_functions = 0
                # get member list
                member_list = node.getElementsByTagName('member')
                # search for functions
                for member in member_list:
                    # get attribute 'kind'
                    mem_kind = member.getAttribute('kind')
                    # Is struct member a function ?
                    if mem_kind == "function":
                        # YES - set flog to parse the struct XML file
                        b_class_has_functions = 1
                        break
                # Any function definitions in class?
                if b_class_has_functions == 1:
                    # YES - parse class XML
                    # increase heading number
                    u_HeadingNr = u_HeadingNr + 1
                    # create XML file name
                    file_name = node.getAttribute('refid')
                    file_name = file_name + ".xml"
                    # parse C file
                    c_file = base_directory  + "/" + file_name
                    ParseCppFile(c_file, out_file, u_HeadingNr, "class")
                    out_file.write("\r\n")
                    out_file.write("\r\n")
                else:
                    #read class name
                    name_list = node.getElementsByTagName('name')
                    warn_name = node.getAttribute('refid')
                    # Is result list not empty ?
                    if name_list != None:
                        # YES - get element value
                        try:
                            warn_name = name_list[0].firstChild.toxml()
                        except:
                            print sys.exc_info()
                            print sys.exc_traceback
                    # Other members than functions?
                    if member_list.length > 0:
                        # YES - get all subnodes of tag name "name"
                        print "no functions defined in " + warn_name
                    else:
                        print warn_name + ": class definition seems to be empty, please check your doxygen paths"
            elif attr_kind_str == "struct":
                # YES - parse strzct file
                # 1 if functions in struct
                b_struct_has_functions = 0
                # get member list
                member_list = node.getElementsByTagName('member')
                # search for functions
                for member in member_list:
                    # get attribute 'kind'
                    mem_kind = member.getAttribute('kind')
                    # Is struct member a function ?
                    if mem_kind == "function":
                        # YES - set flog to parse the struct XML file
                        b_struct_has_functions = 1
                        break
                # Functions defined in struct ?
                if b_struct_has_functions == 1:
                    # YES - parse struct XML
                    # increase heading number
                    u_HeadingNr = u_HeadingNr + 1
                    # create XML file name
                    file_name = node.getAttribute('refid')
                    file_name = file_name + ".xml"
                    # parse struct XML file
                    c_file = base_directory  + "/" + file_name
                    ParseCppFile(c_file, out_file, u_HeadingNr, "struct")                
                    out_file.write("\r\n")
                    out_file.write("\r\n")
                else:
                    print "no functions defined in " + node.getAttribute('refid') + ".xml"

def main():
    global base_directory
    base_directory = "./xml/"
    out_file_name = "doors.txt"

    base_directory = sys.argv[1]
    out_file_name = sys.argv[2]
    
    f = open (out_file_name, "wb")    

    in_file_name = base_directory + "/index.xml"    
    ParseIndexFile(in_file_name, f)
    f.close()
if __name__ == "__main__":
    main()

