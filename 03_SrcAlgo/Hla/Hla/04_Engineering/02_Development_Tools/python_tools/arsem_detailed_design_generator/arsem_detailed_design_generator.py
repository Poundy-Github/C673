"""
Detailed Design Generator for ARS-EM v7
-------------
This script is used to generate detailed design documents
for components within the ARS-EM sub-system
:org: Continental AG
:author: Patrick Hatzelmann
:version: $Revision: 1.5 $
:contact: $Author: Loeffler, Peter (uid32871) $ (last change)
:date: $Date: 2018/09/05 13:32:16CEST $
"""

import os
import sys
import subprocess
import json
import shutil
import string as strg
import xml.etree.ElementTree as ET
import numpy as np

from optparse import OptionParser
from Tkinter import *

RETURN_OK      =  0
RETURN_FAILURE = -1

# Global defines
WD = os.getcwd()
DESIGN      = os.path.join(WD, r"../../../../03_Design")
ENGINEERING = os.path.join(WD, r"../../../../04_Engineering")


# ===========================================================================================================================
# ======================================== DETAILED DESIGN GENERATOR GUI ====================================================
# ===========================================================================================================================
# Global Defines
COMP         = sys.argv[1]
SOURCE_DIR   = os.path.join(WD, r"..\..\..\..\04_Engineering\01_Source_Code")
DOXYGEN_EXE  = os.path.join(WD, r"..\..\..\..\04_Engineering\02_Development_Tools\doxygen\bin\doxygen.exe")
DOXY_CFG     = os.path.join(WD, r"process.doxy")
MOV_PY       = os.path.join(WD, r"..\..\..\..\04_Engineering\02_Development_Tools\movpy\movpy.exe")
GRAPHVIZ_DOT = os.path.join(WD, r"..\..\..\..\04_Engineering\02_Development_Tools\graphviz\bin\dot.exe")
PLANTUML_JAR = os.path.join(WD, r"..\..\..\..\04_Engineering\02_Development_Tools\plant_uml\plantuml.jar")


class GUI(Frame):
    """
    This is the graphical user interface to the detailed design generator
    """
    def __init__(self, projects=[], side=TOP):
        """
        Initialize GUI class
        """
        self.root = Tk()
        Frame.__init__(self, self.root)
        self.root.title("%s Detailed Design Generator v7" % COMP.upper())
        
        self.projects = projects
        self.checkbox_vars = []
        self.build_complete = IntVar()
        self.build_complete.set(0)
        
        # 'Select all' checkbox
        self.select_all = IntVar()
        chk = Checkbutton(self, text="Select all", variable=self.select_all,command=self.checkbox_checked, bg="white")
        chk.pack(side=side, anchor=W, expand=YES)
        
        # Project checkboxes
        for proj in self.projects:
            var = IntVar()
            chk = Checkbutton(self, text=proj, variable=var, bg="white")
            chk.pack(side=side, anchor=W, expand=YES)
            self.checkbox_vars.append(var)

        # Build / build complete radio button
        radiobutton_text = [("Build", 0),
                            ("Build complete", 1)]
        for txt, val in radiobutton_text:
            chk = Radiobutton(self, text=txt, padx=20, variable=self.build_complete, value=val, bg="white")
            chk.pack(side=LEFT, anchor=W, expand=YES)
            
        # Status message
        self.msg = Label(self, bg="white")
        self.update_status_msg(status="Not started", proj="n/a", plantuml=("-","-"), doxy=("-","-"), req=("-","-"))
        self.msg.configure(justify=LEFT)
        self.msg.pack(side=BOTTOM, anchor=W, expand=YES)
        
        # Frame to group the buttons at the bottom
        frm = LabelFrame(self.root, relief=FLAT)
        frm.pack(side=BOTTOM, fill="both", expand="yes")
        
        # Generate design button
        self.genButton = Button(frm, text='Generate design', command=self.setup_tasks, background="green")
        self.genButton.pack(side=LEFT, padx=5)
        
        # Show design button
        self.showDesignButton = Button(frm, text='Show design', command=self.show_selected_designs, background="green")
        self.showDesignButton.pack(side=LEFT, padx=5)
        
        # Show warnings button
        self.showWarnButton = Button(frm, text='Show warnings', command=self.show_selected_warning_files, background="green")
        self.showWarnButton.pack(side=LEFT, padx=5)
        
        self.version_number = None
              
                
    def checkbox_checked(self):
        """
        Callback function for check boxes
        """
        val = self.select_all.get()
        for i in range(0, len(self.checkbox_vars)):
            self.checkbox_vars[i].set(val)
           
    def get_selected_projects(self):
        """
        Return list of all selected projects
        """
        projects = []
        
        for i in range(0,len(self.projects)):
            if self.checkbox_vars[i].get():
                projects.append(self.projects[i])
        
        return projects
        
    def setup_tasks(self):
        """
        Read user input from GUI and start generation of detailed design
        """
        projects = self.get_selected_projects()
                
        if len(projects):
            if self.build_complete.get():
                print_("Generating complete detailed design (incl. requirement linkage) for...")
            else:
                print_("Generating detailed design for...")
            for proj in projects:
                print_(proj)
            self.generate_design(projects, self.build_complete.get())
        else:
            print_("No project selected.")
        
        
    def open(self):
        """
        Opens the GUI
        """
        self.mainloop()
        
        
    def update_status_msg(self, status="unknown", proj="n/a", plantuml=("-","-"), doxy=("-","-"), req=("-","-")):
        """"
        Updates the status message field of the GUI
        """
        self.msg["text"] = "Job status: %s\nProject: %s\nPlantUML build: %s/%s\nDoxygen build: %s/%s\nRequirement linkage: %s/%s" % (status, proj, plantuml[0], plantuml[1], doxy[0], doxy[1], req[0], req[1])
        self.root.update_idletasks()
        
    def disable_buttons(self):
        """
        disable and grey-out bottom buttons
        """
        self.genButton["bg"] = "grey"
        self.genButton["state"] = "disabled"
        self.showDesignButton["bg"] = "grey"
        self.showDesignButton["state"] = "disabled"
        self.showWarnButton["bg"] = "grey"
        self.showWarnButton["state"] = "disabled"
            
    def enable_buttons(self):
        """
        enable and colorize bottom buttons
        """
        self.genButton["bg"] = "green"
        self.genButton["state"] = "normal"
        self.showDesignButton["bg"] = "green"
        self.showDesignButton["state"] = "normal"        
        self.showWarnButton["bg"] = "green"
        self.showWarnButton["state"] = "normal"        
        
    def generate_design(self, projects, build_complete):
        """
        Main entry point to generate the design documents
        """
        self.disable_buttons()
        self.root.update_idletasks()
        
        self.patch_version_number()
        
        for project in projects:
            print_("\n#################### Processing project %s ####################" % project)
            
            # Prepare commonly used paths
            output_dir           = os.path.join(DESIGN,      r"02_Architecture/Project_Specific/%s/%s" % (project, COMP.upper()))
            design_path_generic  = os.path.join(DESIGN,      r"02_Architecture/Generic/%s" % COMP.upper())
            design_path_proj     = os.path.join(DESIGN,      r"02_Architecture/Project_Specific/%s/%s" % (project, COMP.upper()))
            img_path_generic     = os.path.join(DESIGN,      r"02_Architecture/Generic/%s/images" % COMP.upper())
            img_path_proj        = os.path.join(DESIGN,      r"02_Architecture/Project_Specific/%s/%s/gen_images" % (project, COMP.upper()))
            img_path_req         = os.path.join(DESIGN,      r"02_Architecture/Project_Specific/%s/%s/req_images" % (project, COMP.upper()))
            source_path_core     = os.path.join(ENGINEERING, r"01_Source_Code/%s" % COMP.upper())
            source_path_proj     = os.path.join(ENGINEERING, r"00_Projects/%s/%s" % (project, COMP.upper()))
            
            # Prepare parameter strings for doxygen/plant_uml builds
            input_string            = r"INPUT+=%s & echo INPUT+=%s" % (source_path_proj, design_path_proj)
            req_image_string        = r"IMAGE_PATH+=%s & echo IMAGE_PATH+=%s & echo IMAGE_PATH+=%s" % (img_path_generic,
                                                                                                       img_path_proj,
                                                                                                       img_path_req)
            output_string           = r"OUTPUT_DIRECTORY=%s" % design_path_proj
            project_string          =  "PROJECT_BRIEF=\"for %s\"" % (project)
            other_params_string     = r"WARN_LOGFILE=%s & echo HTML_FOOTER=%s" % (os.path.join(output_dir, "warnings.txt"),
                                                                                  os.path.join(design_path_proj, "Conti_footer.html"))
            
            # TODO: Read further PREDEFINED from file
            predifined_string = ""            
            
            compile_plantuml_source = "java -jar %s -v -o \"%s\" \"%s/**.(c|cpp|doc|h|markdown)\"" % (PLANTUML_JAR, img_path_proj, source_path_core)
            compile_plantuml_design = "java -jar %s -v -o \"%s\" \"%s/**.(c|cpp|doc|h|markdown)\"" % (PLANTUML_JAR, img_path_proj, design_path_generic)
            compile_doxygen         = "( type %s & echo %s & echo %s & echo %s & echo %s & echo %s) | %s -" % (DOXY_CFG,
                                                                                                               input_string,
                                                                                                               req_image_string,
                                                                                                               output_string,
                                                                                                               other_params_string,
                                                                                                               project_string,
                                                                                                               DOXYGEN_EXE)       
            self.do_preparations(output_dir, build_complete, project)
                        
            if build_complete:
                # Build plant_uml
                print_("\n#################### Build PlantUML... ####################")
                self.update_status_msg(status="In progress (PlantUML)", proj=project, plantuml=(1,1), doxy=(0,3), req=(0,2))
                self.compile_plantuml([compile_plantuml_source, compile_plantuml_design])
                
                # For complete build, doxygen build and requirement linkage needs to be applied alternating (3 times doxygen, 2 times requirement linkage)
                print_("\n#################### Build doxygen (1/3)... ####################")
                self.compile_doxy(compile_doxygen, proj=project, plantuml=(1,1), doxy=(1,3), req=(0,2))
                print_("\n#################### Requirement linkage (1/2)... ####################")
                self.do_requirement_linkage(output_dir, proj=project, plantuml=(1,1), doxy=(1,3), req=(1,2))
                print_("\n#################### Build doxygen (2/3)... ####################")
                self.compile_doxy(compile_doxygen, proj=project, plantuml=(1,1), doxy=(2,3), req=(1,2))
                print_("\n#################### Requirement linkage (2/2)... ####################")
                self.do_requirement_linkage(output_dir, proj=project, plantuml=(1,1), doxy=(2,3), req=(2,2))
                print_("\n#################### Build doxygen (3/3)... ####################")
                self.compile_doxy(compile_doxygen, proj=project, plantuml=(1,1), doxy=(3,3), req=(2,2))
            else:
                # Build plant_uml
                print_("\n#################### Build PlantUML... ####################")
                self.update_status_msg(status="In progress (PlantUML)", proj=project, plantuml=(1,1), doxy=(0,1), req=("-","-"))
                self.compile_plantuml([compile_plantuml_source, compile_plantuml_design])
                
                # For normal build, doxygen needs to be compiled once, since requirement linkage information is already available
                print_("\n#################### Build doxygen... ####################")
                self.compile_doxy(compile_doxygen, proj=project, plantuml=(1,1), doxy=(1,1), req=("-","-"))
            
            # create warning file without justified warnings
            print_("\n#################### Process warnings... ####################")
            self.process_warnings(output_dir)
            
            # Clean up auxiliary files
            print_("\n#################### Clean-up output folder ####################")
            self.clean_up(output_dir)
                
        self.update_status_msg(status="Done", proj=project, plantuml=("-","-"), doxy=("-","-"), req=("-","-"))
        self.enable_buttons()
        print_("\n\nJob done!")
        
        
    def patch_version_number(self):
        """
        Read the version header of the component and extract the version number
        """
        version_header = os.path.join(ENGINEERING, r"01_Source_Code/%s/%s_ver.h" % (COMP.upper(), COMP))
    
        Version_Pattern_def_GEN = r"#define\W+%s_GEN_VER_NO\W+(0x)?([0-9a-fA-F]+)U?.*" % COMP.upper()
        Version_Pattern_def_IFC = r"#define\W+%s_IFC_VER_NO\W+(0x)?([0-9a-fA-F]+)U?.*" % COMP.upper()
        Version_Pattern_def_CON = r"#define\W+%s_CTT_VER_NO\W+(0x)?([0-9a-fA-F]+)U?.*" % COMP.upper()
        Version_Pattern_def_INT = r"#define\W+%s_INT_LEV_NO\W+(0x)?([0-9a-fA-F]+)U?.*" % COMP.upper()
    
        Version_Pattern_GEN = re.compile(Version_Pattern_def_GEN,flags =re.DOTALL)
        Version_Pattern_IFC = re.compile(Version_Pattern_def_IFC,flags =re.DOTALL)
        Version_Pattern_CON = re.compile(Version_Pattern_def_CON,flags =re.DOTALL)
        Version_Pattern_INT = re.compile(Version_Pattern_def_INT,flags =re.DOTALL)
    
        Version_GEN = r"00"
        Version_IFC = r"00"
        Version_CON = r"00"
        Version_INT = r"00"
    
        print_('Look for version number in file %s' %version_header)
        
        data = open(version_header, 'rt').readlines()
        for l in data:
            SwitchesMatches = Version_Pattern_GEN.finditer(l)
            for Matches in SwitchesMatches:
                if not (Matches.group(1) is None):
                    Version_GEN = "%s%s" % (Matches.group(1), Matches.group(2))
                else:
                    Version_GEN = "%s" % (Matches.group(2))
            SwitchesMatches = Version_Pattern_IFC.finditer(l)
            for Matches in SwitchesMatches:
                Version_IFC = "%s%s" % (Matches.group(1), Matches.group(2))
                if not (Matches.group(1) is None):
                    Version_IFC = "%s%s" % (Matches.group(1), Matches.group(2))
                else:
                    Version_IFC = "%s" % (Matches.group(2))
            SwitchesMatches = Version_Pattern_CON.finditer(l)
            for Matches in SwitchesMatches:
                Version_CON = "%s%s" % (Matches.group(1), Matches.group(2))
                if not (Matches.group(1) is None):
                    Version_CON = "%s%s" % (Matches.group(1), Matches.group(2))
                else:
                    Version_CON = "%s" % (Matches.group(2))
            SwitchesMatches = Version_Pattern_INT.finditer(l)
            for Matches in SwitchesMatches:
                Version_INT = "%s%s" % (Matches.group(1), Matches.group(2))
                if not (Matches.group(1) is None):
                    Version_INT = "%s%s" % (Matches.group(1), Matches.group(2))
                else:
                    Version_INT = "%s" % (Matches.group(2))
    
        # Check if version number is given in hex, and convert it to decimal
        if "0x" in Version_GEN:
            Version_GEN = "%02d" % (int(Version_GEN, 16))
        else:
            Version_GEN = "%02d" % (int(Version_GEN))
        if "0x" in Version_CON:
            Version_IFC = "%02d" % (int(Version_IFC, 16))
        else:
            Version_CON = "%02d" % (int(Version_CON))
        if "0x" in Version_CON:
            Version_CON = "%02d" % (int(Version_CON, 16))
        else:
            Version_CON = "%02d" % (int(Version_CON))
        if "0x" in Version_INT:
            Version_INT = "%d" % (int(Version_INT, 16))
        else:
            Version_INT = "%d" % (int(Version_INT))
    
        self.version_number = '%s.%s.%s_INT-%s \n' %(Version_GEN, Version_IFC, Version_CON, Version_INT)
        print_("Version number found:  %s" % self.version_number)
        sys.stdout.flush()
        
        
    def do_preparations(self, output_dir, build_complete, proj):
        """
        Various preparations needed before running PlantUML / Doxygen / Requirement linkage
        """
        # Remove write protection from doxy file 
        remove_write_protection(DOXY_CFG)
        # Remove write protection from chm file
        remove_write_protection(os.path.join(output_dir, "%s_DetailedDesign.chm" % COMP))
        # Set environment variable for doxy location
        os.environ["CFG_DOXY"] = WD
        
        # Copy html footer to output path
        files_to_copy = ["Conti_footer.html", "conti.png"]
        for f in files_to_copy:
            src = os.path.join(DESIGN, r"02_Architecture/Generic/%s/images/%s" % (COMP, f))
            trg = os.path.join(DESIGN, r"02_Architecture/Project_Specific/%s/%s/%s" % (proj, COMP, f))
            if not os.path.isfile(trg):
                shutil.copy2(src, trg)
        
        if build_complete:
            # Delete xml folder
            remove_dir(os.path.join(output_dir, "xml"))
            # Delete existing requirement related images
            remove_dir(os.path.join(output_dir, "req_images"))
            # Delete existing requirement markdown file
            remove_file(os.path.join(output_dir, "%s_requirements.markdown" %  COMP))
        

    def do_requirement_linkage(self, output_dir, proj=None, plantuml=None, doxy=None, req=None):
        """
        Run requirement lingage
        """
        # Set environment variable properly
        os.environ["GRAPHVIZ_DOT"] = r"..\..\..\..\04_Engineering\02_Development_Tools\graphviz\bin\dot.exe"
        
        # Update status message
        if (not (proj is None) and not (plantuml is None) and not (doxy is None) and not (req is None)):
            self.update_status_msg(status="In progress (requirements)", proj=proj, plantuml=plantuml, doxy=doxy, req=req)
        
        # Run requirement linkage
        req_linkage_main(output_dir)


    def compile_doxy(self, command_string, proj=None, plantuml=None, doxy=None, req=None):
        """
        Run Doxygen compilation
        """
        # Set environment variables properly
        os.environ["GRAPHVIZ_DOT"]             = GRAPHVIZ_DOT
        os.environ["HHC_EXE"]                  = os.path.join(ENGINEERING, r"02_Development_Tools/html_help_workshop/hhc.exe")
        os.environ["COMPONENT_NAME"]           = COMP.upper()
        os.environ["COMPONENT_CHM_FILE"]       = "../%s_DetailedDesign.chm" % COMP.upper()
        os.environ["COMPONENT_PROJECT_NUMBER"] = self.version_number
        
        # Update status message
        if (not (proj is None) and not (plantuml is None) and not (doxy is None) and not (req is None)):
            self.update_status_msg(status="In progress (Doxygen)", proj=proj, plantuml=plantuml, doxy=doxy, req=req)
            
        # Run doxygen compilation
        proc = subprocess.Popen(command_string, shell=True, cwd=WD)
        
        # Wait for subprocess to finish (keeps GUI alive)
        while proc.poll() is None:
            self.root.update()
            
            
    def compile_plantuml(self, command_strings):
        """
        Run PlantUML compilation
        """
        os.environ["GRAPHVIZ_DOT"] = GRAPHVIZ_DOT
        
        for command_string in command_strings:
            # Run doxygen compilation
            proc = subprocess.Popen(command_string, shell=True, cwd=WD)
            
            # Wait for subprocess to finish (keeps GUI alive)
            while proc.poll() is None:
                self.root.update()
                
    def process_warnings(self, out_dir):
        """
        Create addl. warnings file without justified warnings
        """
        warn_file_name = os.path.join(out_dir, "warnings.txt")
        warn_unjust_file_name = os.path.join(out_dir, "warnings_unjustified.txt")
        
        warn_file = open(warn_file_name, 'r')
        warnings = warn_file.readlines()
        warn_file.close()
        
        warn_unjust_file = open(warn_unjust_file_name, 'w')
        for warning in warnings:
            if "startuml command because PLANTUML_JAR_PATH is not set" not in warning:
                warn_unjust_file.write(warning)
        
        warn_unjust_file.close()
                
    def clean_up(self, out_dir):
        """
        Clean up auxiliary files after processing
        """        
        # Clean folders
        folders_to_remove = ["gen_images", "html", "xml"]
        for folder in folders_to_remove:
            if remove_dir(os.path.join(out_dir, folder)) == RETURN_OK:
                state = "ok"
            else:
                state = "not available"
            print_(r"Removing %s/... %s" % (folder, state))
            
        # Clean files
        files_to_remove = ["conti.png", "Conti_footer.html", "doors_requirements.json", "%s_requirements.xls" % COMP]
        for fil in files_to_remove:
            if remove_file(os.path.join(out_dir, fil)) == RETURN_OK:
                state = "ok"
            else:
                state = "not available"
            print_(r"Removing %s... %s" % (fil, state))

    def show_design(self, project):
        output_dir = os.path.join(DESIGN,      r"02_Architecture/Project_Specific/%s/%s" % (project, COMP.upper()))
        chm_file   = os.path.join(output_dir, "%s_DetailedDesign.chm" % COMP)
        os.startfile(chm_file) 
               
    def show_selected_designs(self):
        """
        Open the detailed design documents of the projects checked
        """
        projects = self.get_selected_projects()
        for project in projects:
            self.show_design(project)
            
    def show_warning_file(self, project):
        output_dir     = os.path.join(DESIGN,      r"02_Architecture/Project_Specific/%s/%s" % (project, COMP.upper()))
        warn_file_name = os.path.join(output_dir, "warnings_unjustified.txt")
        os.system("start %s" % warn_file_name) 

    def show_selected_warning_files(self):
        """
        Open the warnings of the projects checked
        """
        projects = self.get_selected_projects()
        for project in projects:
            self.show_warning_file(project)
            
def gui_main():
    """
    Starts Detailed Design Generator GUI
    """
    project_dirs = os.listdir(os.path.join(ENGINEERING, "00_Projects"))
    gui = GUI(project_dirs)
    gui.pack(side=TOP,  fill=X)
    gui.config(relief=GROOVE, bd=2, bg="white")
    gui.open()
    
# ===========================================================================================================================
# ================================================= REQUIREMENT LINKAGE =====================================================
# ===========================================================================================================================
# --- Component common imports ---
COMPONENT_COMMON_FOLDER = os.path.abspath(WD + '/../../..')
if COMPONENT_COMMON_FOLDER not in sys.path:
    sys.path.append(COMPONENT_COMMON_FOLDER)

# --- Defines ---
PRJ_FOLDER = ''

DATA_FOLDER = PRJ_FOLDER + 'data/'
OUTPUT_FOLDER = PRJ_FOLDER + 'output/'

# List of characters that cause problems in ElementTree parser and need to be replaced
# 'value' of dictionary will be replaced by 'key'
SPECIAL_CHARACTERS = {"degree": "\xb0", " ": "\xa0"}

# Set environment variable for graphviz
os.environ["GRAPHVIZ_DOT"] = os.path.join(WD, r"..\..\..\..\04_Engineering\02_Development_Tools\graphviz\bin\dot.exe")

class RequirementLinkage(object):
    """
    This class is used to handle the linkage between requirements in Doors and their implementation
    """
    def __init__(self, doors_fname='', xml_fname='', dox_req_fname='', xml_dir='', img_dir=''):
        
        self.doors_fname    = doors_fname
        self.xml_fname      = xml_fname
        self.dox_req_fname  = dox_req_fname
        self.xml_dir        = xml_dir
        self.img_dir        = img_dir
        
        if not os.path.isdir(self.img_dir):
            os.makedirs(self.img_dir)
        
        self.entries        = dict()
        self.root           = ET.parse(xml_dir + self.xml_fname).getroot()
        
        self.doors_requirements = list()
        self.doors_ids_requirements = dict()
        self.doors_ids_headers = dict()
        
        self.json_req_file      = ''
        self.json_req_impl_file = ''
        self.n_of_link_sets = 0
        
        self.plantuml_path = os.path.join(ENGINEERING, "02_Development_Tools\\plant_uml\\")


    def read_xml_file(self):
        
        self.entries      = dict()
        listitem = self.root.findall(".//listitem")     
        anchor = self.root.findall(".//varlistentry/term/anchor")        
        term = self.root.findall(".//varlistentry/term")
        
        for i in range(len(anchor)):
            for para in listitem[i]:
            
                keys = dict()
                keys['requirement'] = list()
                
                # type
                keys['type'] = anchor[i].tail.lower().strip()
                
                # name
                keys['name'] = term[i].findall(".//ref")[0].text
                
                # refid
                keys['refid'] = term[i].findall(".//ref")[0].get('refid')
                
                # file
                if keys['type'] == 'global':
                    keys['file'] = strg.rsplit(keys['refid'], '_', 1)[0]
                else:
                    keys['file'] = keys['refid']

                if keys['type'] == 'page':
                    keys['source_file'] = keys['file']
                else:
                    keys['source_file'] = strg.replace(keys['file'][::-1], '8_', '.', 1)[::-1]
                    keys['source_file'] = keys['source_file'].replace('__', '_')
                    
                # link to implementation page
                keys['link_impl'] = strg.rsplit(anchor[i].get('id'), '_', 1)[1]
            
                position = 'start'
                first = True
                for element in para.iter():
                    if position == 'start':
                        if element.tag == 'para':
                            position = 'requirements'
                            continue
            
                    if position == 'requirements':
                        if element.tag == 'ref':
                            keys['requirement'].append(element.text)
                        else:
                            position = 'uid'
                            continue
            
                    if position == 'uid':
            
                        if element.tag == 'bold':
                            keys['uid'] = element.tail.strip()
                            if keys['uid'] in ('', '-'):
                                keys['uid'] = 'do_not_link'
                                
                        else:
                            position = 'connect'
                            continue
            
                    if position  == 'connect':
            
                        if element.tag == 'bold':
                            keys['connection'] = strg.split(element.tail.strip(), ',')
                            if keys['connection'] == '':
                                keys['connection'] = 'head'
                        else:
                            position = 'implementation'
                            continue
            
                    links = list()
                    if position == 'implementation':
                        if first == True:
                            total_text = list(para.itertext())
                            keys['implementation'] = ''.join(total_text[total_text.index('Implementation:')+1:]).strip()
                            first = False
                        else:
                            if element.tag == 'ulink':
                                link = dict()
                                
                                link['url'] = element.get('url')
                                link['name'] = element.text
                                
                                links.append(link)
                                
                    keys['links'] = links
                                
                                
                if keys['type'] == 'global':
                    try:
                        tree_tmp = ET.parse(self.xml_dir + keys['file'] + '.xml')
                        root_tmp = tree_tmp.getroot()
                    except ET.ParseError:
                        strTmp = open(self.xml_dir + keys['file'] + '.xml', 'r').read()
                        for key, val in SPECIAL_CHARACTERS.iteritems():
                            strTmp = strTmp.replace(val, key)
                        root_tmp = ET.fromstring(strTmp)                      
                    
                    for member in root_tmp.findall(".//memberdef"):
                        if member.get('id') == keys['refid']:
                            if len(member.findall(".//briefdescription")[0].findall(".//para")) > 0:
                                keys['description'] = (member.findall(".//briefdescription")[0].findall(".//para")[0].text).strip()
                            else:
                                keys['description'] = ''
                                
                if keys['type'] == 'file':
                    root_tmp = ET.parse(self.xml_dir + keys['file'] + '.xml').getroot()
                    if len(root_tmp.findall("compounddef/briefdescription/para")) == 1:
                        keys['description'] = root_tmp.findall("compounddef/briefdescription/para")[0].text
                    else:
                        keys['description'] = ''
                
                for key in keys['requirement']:
                    if key in self.entries.keys():
                        self.entries[key].append(keys)
                    else:
                        self.entries[key] = [keys]
        
        # Sort Page - File - Function
        for key in self.entries.keys():
            tmp = list()
            for i in range(len(self.entries[key])):
                if self.entries[key][i]['type'] == 'page':
                    tmp.append(self.entries[key][i])
            for i in range(len(self.entries[key])):
                if self.entries[key][i]['type'] == 'file':
                    tmp.append(self.entries[key][i])
            for i in range(len(self.entries[key])):
                if self.entries[key][i]['type'] == 'global':
                    tmp.append(self.entries[key][i])
            self.entries[key] = tmp


    def save_requirement_implementation(self, fname = 'req_implementations.json'):
        with open(fname, 'w') as fp:
            json.dump(self.entries, fp)


    def make_plantuml_graph(self, requirement):
        if requirement in self.entries.keys():

            prefix = '@startuml {0}.png\ntitle {0}\n'.format(requirement)
            postfix = '@enduml'
            components = '[{0}] as {0} #Red\n'.format(requirement)
            connections = ''
            

            for i in range(len(self.entries[requirement])):
                implementation = ''
                color = ''
                
                name = self.entries[requirement][i]['name']
                if self.entries[requirement][i]['type'] == 'global':
                    type_tmp = 'Function: '
                    color = ' #Yellow'
                    if self.entries[requirement][i]['implementation'] in ('', '-'):
                        implementation = self.entries[requirement][i]['description']
                    else:
                        implementation = self.entries[requirement][i]['implementation']
                else:
                    if self.entries[requirement][i]['type'] == 'page':
                        type_tmp = 'Design Decision: '
                        implementation = self.entries[requirement][i]['implementation']
                        color = ' #Orange'
                    else:
                        if self.entries[requirement][i]['implementation'] in ('', '-'):
                            type_tmp = 'File: '
                            implementation = self.entries[requirement][i]['description']
                            color = ' #Cyan'
                        else:
                            type_tmp = 'Design Decision: '
                            color = ' #Orange'
                            implementation = self.entries[requirement][i]['implementation']
                        
                tmp = '[**' + type_tmp + name + '** \\n //Uid: ' + self.entries[requirement][i]['uid'] + '// \\n **Implementation:** ' + self.include_line_break(implementation, 40) + '] as ' + self.entries[requirement][i]['uid'].lower() + color + '\n'
                components += tmp
                for j in range(len(self.entries[requirement][i]['connection'])):
                    if self.entries[requirement][i]['connection'][j].strip() == 'head':
                        connections += ('{0}<-down-'.format(requirement) + self.entries[requirement][i]['uid'].lower() + '\n')
                    else:
                        if self.entries[requirement][i]['connection'][j].strip() != '':
                            connections += (self.entries[requirement][i]['uid'].lower() + '<-down-' + self.entries[requirement][i]['connection'][j].strip().lower() + '\n')
                        
            output = prefix + components + connections + postfix
            
            f = open('{0}.txt'.format(requirement), 'w')
            f.write(output)
            f.close()
            
            os.system('java -jar ' + self.plantuml_path + 'plantuml.jar {0}.txt'.format(requirement))
            os.system('del {0}.txt'.format(requirement))
            
            os.system('move /Y %s.png %s' % (requirement, self.img_dir))
        
        
    def make_all_plantuml_graphs(self):
        for req in self.doors_requirements:
            if req['id'] in self.entries.keys():
                self.make_plantuml_graph(req['id'])
        
        
    def read_doors_requirements(self, fname='', doors_location='', link_set=None):
        if fname != '':
            self.doors_fname = fname
        
        with open(self.doors_fname , 'r') as f:
            file_string = f.read() # readlines creates a list of the lines
        
        self.n_of_link_sets += 1
        
        file_string = file_string.replace('\"\",\"\"', '\"\", \"\"')
        file_string = file_string.replace('\"\"\n', '\"\" \n')
        file_string = file_string.replace('<', '\<')
        file_string = file_string.replace('>', '\>')
    
        req_list = strg.split(file_string,'\"\n')[1:]
        
        for req in req_list:
            if req != "":
                req_dict = dict()
                req_items = strg.split(req, '\",\"')
                req_dict['id'] = req_items[0][1:]
                req_dict['description'] = req_items[1].replace('\"\"', '\"')
                req_dict['location'] = doors_location
                if link_set is None:
                    req_dict['link_set'] = self.n_of_link_sets
                else:
                    req_dict['link_set'] = np.abs(link_set)
                self.doors_requirements.append(req_dict)
               
                
    def read_doors_requirements_markus(self, fname='', id_pos=0, description_pos=1, object_type_pos=8, append=False):
        
        if fname != '':
            self.doors_fname = fname
        
        if append == False: 
            self.doors_requirements = list()
        
        with open(self.doors_fname , 'r') as f:
            file_string = f.read() # readlines creates a list of the lines
            
        file_string = file_string.replace('\"\",\"\"', '\"\", \"\"')
        file_string = file_string.replace('\"\"\n', '\"\" \n')
        file_string = file_string.replace(',,', ',\"\",')
        file_string = file_string.replace(',,\n', ',,\"\"\n')
    
        req_list = strg.split(file_string,'\"\n')[1:]
        
        for req in req_list:
            if req != "":
                req_dict = dict()
                req_items = strg.split(req, '\",\"')
                if req_items[object_type_pos] == "Requirement":
                    req_dict['id'] = req_items[id_pos][1:]
                    req_dict['description'] = req_items[description_pos].replace('\"\"', '\"')
                    self.doors_requirements.append(req_dict)


    def save_doors_requirements(self, fname='doors_requirements.json'):
        with open(fname, 'w') as fp:
            json.dump(self.doors_requirements, fp)
            
            
    def save_doxygen_file(self, fname=''):
        if fname != '':
            self.dox_req_fname = fname
            
        prefix = '@page requirementsPage Requirements\n\n@tableofcontents\n\n'
        
        postfix = ''
        
        template = '@section {0} {0}\n\n@subsection {0}_description Description\n\n{1}<br/>\n<b>Doors link:</b> {2}\n\n@subsection {0}_implementation Implementation\n\n{3}\n@subsection {0}_tests Tests\nHere the linkage to the unit tests can appear using the verify tag\n\n@subsection {0}_connectivity Connectivity\n\n{4}\n\n<hr>'
        
        file_string = prefix
        
        for req in self.doors_requirements:
            impl_string = ''
            img_string = ''
            
            if req['id'] in self.entries.keys():
                impl_string = self.get_implementation_string(self.entries[req['id']])
                img_string = '![]({0}.png)'.format(req['id'])
                    
            file_string += template.format(req['id'], req['description'], 'doors link', impl_string, img_string)
        
        file_string += postfix
        
        f = open(self.dox_req_fname, 'w')
        f.write(file_string)
        f.close()


    def get_implementation_string(self, requirement_implementation):
        
        req_string = ''
        for entry in requirement_implementation:
            
            implementation = entry['implementation']
            if entry['type'] == 'page':
                req_entry_string = ' - @ref {0} '.format(entry['refid'])
            elif entry['type'] == 'file':
                req_entry_string = ' - [{0}]({1}.html) '.format(entry['name'], entry['file'])
                if implementation in ('', '-'):
                    implementation = entry['description']

            else:
                req_entry_string = ' - {0}() '.format(entry['name'])
                if implementation == '' or implementation == '-':
                    implementation = entry['description']
                    
            req_entry_string += '([tag information](satisfy.html#{0})) [file/page: {1}]<br/>\n'.format(entry['link_impl'], entry['source_file'])
            req_entry_string += '   @b Description: {0}\n'.format(implementation)
            req_string += req_entry_string
            
        return req_string
        
        
    def get_implementation_string_doors(self, requirement_implementation):
        
        req_string = ''
        for entry in requirement_implementation:
            
            implementation = entry['implementation']
            req_entry_string = '{} '.format(entry['name'])
            if entry['type'] == 'global':
                req_entry_string = '{}() '.format(entry['name'])
            
            if entry['type'] == 'file' or entry['type'] == 'global':
                if implementation in ('', '-'):
                    implementation = entry['description']

                    
            req_entry_string += '(file/page: {0})\n'.format(entry['source_file'])
            req_entry_string += 'Description: {0}\n\n'.format(implementation)
            req_string += req_entry_string
            
        return req_string

        
    def assign_doors_id_to_requirement(self, fname='', n_of_link_sets_old=None):
        from xlrd import open_workbook
        book = open_workbook(fname)
        sheet = book.sheet_by_index(0)
        
        self.doors_ids_requirements = dict()
        self.doors_ids_headers = dict()
        
        if n_of_link_sets_old is None:
            n_of_link_sets = self.n_of_link_sets
        else:
            n_of_link_sets = n_of_link_sets_old
            
        for i in range(sheet.nrows)[1:]:
            for j in range(n_of_link_sets):
                if sheet.cell(i,5+j).value != '':
                    self.doors_ids_requirements[sheet.cell(i,5+j).value] = int(sheet.cell(i,0).value)
                
            if sheet.cell(i,3).value != '':
                self.doors_ids_headers[sheet.cell(i,3).value] = int(sheet.cell(i,0).value)
                
                
    def generate_export_excel_file(self, fname=''):
        import xlwt
        
        def write_header(worksheet, row, oid, name, level=1):
            worksheet.row(row).write(0, 1)
            worksheet.row(row).write(1, level)
            worksheet.row(row).write(2, 'Header')
            worksheet.row(row).write(3, name)
            
            row += 1
            return row
            
        def write_req_entry(worksheet, row, oid, content, link, link_set=0):
            worksheet.row(row).write(0, oid)
            worksheet.row(row).write(1, 2)
            worksheet.row(row).write(2, 'Requirement')
            worksheet.row(row).write(4, content)
            if link_set != -1:
                worksheet.row(row).write(4 + link_set, link)
            
            row += 1
            return row
            
        def get_decription_string(entry):
            
            prefix = ''
            implementation = entry['implementation']
            
            if entry['type'] == 'global':
                prefix = '{0}(): \n'.format(entry['name'])
                if implementation == '' or implementation == '-':
                    implementation = entry['description']
            
            return prefix + implementation
            
        
        wb = xlwt.Workbook()
        ws = wb.add_sheet('%s requirement implementations' % COMP)
        
        column_title_style = xlwt.easyxf('font: bold on;')
        #header_style = xlwt.easyxf('pattern: pattern solid, fore_colour grey25;')
        ws.row(0).write(0, 'Object Identifier', column_title_style)
        ws.row(0).write(1, 'Object Level', column_title_style)
        ws.row(0).write(2, 'Object Type', column_title_style)
        ws.row(0).write(3, 'Object Heading', column_title_style)
        ws.row(0).write(4, 'Object Text', column_title_style)
        
        for i in range(self.n_of_link_sets):
            ws.row(0).write(5 + i, 'LinkSet{}'.format(i+1), column_title_style)
        
        row = 1
        row = write_header(ws, row, row, 'General information')
        
        row = write_header(ws, row, row, 'Requirement implementation')
        
        for key, entry in self.entries.iteritems():
            if key in self.doors_ids_requirements.keys():
                doors_id = self.doors_ids_requirements[key]
            else:
                doors_id = row
            
            links_sets = [x['link_set'] for x in self.doors_requirements if x['id'] == key]
            if len(links_sets) > 0: 
                link_set = [x['link_set'] for x in self.doors_requirements if x['id'] == key][0]
            else:
                link_set = -1
            row = write_req_entry(ws, row, doors_id, self.get_implementation_string_doors(entry), key, link_set)
        
        wb.save(fname)  
    
    def include_line_break(self, text, max_length):
        text = strg.split(text)
        broken_text = ''
        tmp = 0
        for i in range(len(text)):
            broken_text += (text[i] + ' ')
            tmp += len(text[i])
            if tmp > max_length:
                tmp = 0
                broken_text += '\\n'
        return broken_text

def req_linkage_main(outpath=None):
    """
    Entry point for requirement linkage
    """
    try:
        doors_export_file = sys.argv[2]
        doors_link = sys.argv[3]
    except IndexError, e:
        print_(e)
        print_("Please provide name of doors export file and doors link in start_GUI.bat file.")
    
    req = RequirementLinkage('', 'satisfy.xml', "%s\\%s_requirements.markdown" % (outpath, COMP), "%s\\xml\\" % outpath, "%s\\req_images\\" % outpath)
    req.read_doors_requirements(os.path.join(DESIGN, r"02_Architecture/Generic/%s/%s" % (COMP.upper(), doors_export_file)), doors_link, 1)
    req.save_doors_requirements(os.path.join(outpath, "doors_requirements.json"))

    req.read_xml_file()
    req.save_doxygen_file()
    req.make_all_plantuml_graphs()
    
    req.generate_export_excel_file(os.path.join(outpath, "%s_requirements.xls" % COMP))



# ===========================================================================================================================
# ============================================= ACCESS & COMMON FUNCTIONS ===================================================
# ===========================================================================================================================
def print_(msg):
    """
    Print and flush (to see log on console immediately)
    """
    print(msg)
    sys.stdout.flush()
    
    
def remove_dir(path):
    if (os.path.isdir(path)):
        # make path writable
        os.system(r"attrib -r %s\* /s /d >nul" % path)
        try:
            # try to remove - will fail for non-empty folders
            os.rmdir(path)
            return RETURN_OK
        except OSError, e:
            try:
                # try to delete files within folder first
                shutil.rmtree(path, ignore_errors=True)
                return RETURN_OK
            except WindowsError, e:
                return RETURN_FAILURE


def remove_file(f):
    try:
        remove_write_protection(f)
        os.remove(f)
        return RETURN_OK
    except WindowsError, e:
        return RETURN_FAILURE
    

def remove_write_protection(f):
    if (os.path.isfile(f)):
        os.system(r"attrib -R %s" % f)
        return RETURN_OK
    else:
        return RETURN_FAILURE
    
    
if __name__ == "__main__":
    """
    Main function
    Expected arguments:
    1) Component name (e.g. srp, rmp, ooc, ...)
       --> Mandatory
    2) Doors export csv file name (e.g. _COMMON_L3_SW_ARS-EM_01_RequirementSet_L4_SW_SRS_ARSEM_SRP.CSV)
       --> Optional, only needed for requirement linkage
    3) Doors location link (e.g. /COMMON/L3/SW/ARS-EM/01_RequirementSet)
       --> Optional, only needed for requirement linkage
    """
    if (len(sys.argv) > 1):   
        gui_main()
    else:
        raise Exception("No component name provided")
    
    
"""
CHANGE LOG:
-----------
$Log: arsem_detailed_design_generator.py  $
Revision 1.5 2018/09/05 13:32:16CEST Loeffler, Peter (uid32871) 
in requirements, add escape character before angle brackets
Revision 1.4 2018/08/13 09:25:58CEST Loeffler, Peter (uid32871) 
- added button to display design
- added button to display warnings
Revision 1.3 2018/07/03 13:15:09CEST Hatzelmann, Patrick (uidr9263) 
Adapted pattern for version number macros. Version number macros are now expected as:
- <COMPONENT>_GEN_VER_NO
- <COMPONENT>_IFC_VER_NO
- <COMPONENT>_CTT_VER_NO
- <COMPONENT>_INT_LEV_NO
Revision 1.2 2018/06/26 13:56:56CEST Hatzelmann, Patrick (uidr9263) 
* New feature: Delete auxiliary files
* Bugfix: Empty page in chm when creating requirement page
Revision 1.1 2018/06/26 08:49:03CEST Hatzelmann, Patrick (uidr9263) 
Initial revision
Member added to project /ADAS/SW/Components/MCC/04_Engineering/02_Development_Tools/python_tools/arsem_detailed_design_generator/project.pj
"""