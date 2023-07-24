#!/usr/bin/env python3
'''
@brief SWC zip file creation
   1. parse SDL file from PDO generation               from /sdl/ap_pdo_gen.sdl
   2. write SDL file after compile as input for SWC    to  /sdl/ap_pdo_tool.sdl
   3. write manifest.xml.rel                           to /sdl/templateSwc/_rels/  ID => R + CRC32 from file
   4. write manifest.xml                               to /sdl/templateSwc/
   5. generate SWC file from folder /templateSwc       to /sdl
@ReturnCodes:
    0    => ok
    1    => wrong parameter count
    2    => sdl input file not found
    3    => source path not found
    4    => run on jenkins and generation not ok
    255  => other python error  => analyze code
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

class SwcGeneration:
    """SWC generation"""
    def __init__(self, cem_build_dir, sw_project_version):
        self.sdl_build_dir = os.path.join(cem_build_dir, "sdl")
        self.sw_project_version = sw_project_version

        # Directories and files in subdirectory 'sdl'
        self.sdl_input_file = os.path.join(self.sdl_build_dir, "ap_pdo_gen.sdl")
        self.md_5_test_file = os.path.join(self.sdl_build_dir, "ap_pdo_tool_sdl.md5")
        self.sdl_compiled_file = os.path.join(self.sdl_build_dir, "ap_pdo_tool.sdl")
        self.swc_file = os.path.join(self.sdl_build_dir, "ADCU_aurix.swc")
        self.build_template_swc = os.path.join(self.sdl_build_dir, "templateSwc")

        # Directories and files in subdirectory 'sdl/templateSwc'
        self.build_template_swc_sdl = os.path.join(self.build_template_swc, "sdl")
        self.channel_definition_file = os.path.join(self.build_template_swc, "channel-definition", "channel-definition.xml")
        self.channel_mapping_file = os.path.join(self.build_template_swc, "channel-mapping", "channel-mapping.xml")
        self.cycle_definition_file = os.path.join(self.build_template_swc, "cycle-definition", "cycle-definition.xml")
        self.hw_data_cycle_file = os.path.join(self.build_template_swc, "hw-data-cycle", "hw-data-cycle.xml")
        self.manifest_rel = os.path.join(self.build_template_swc, "_rels", "manifest.xml.rels")
        self.comment_type_file = os.path.join(self.build_template_swc, "[Content_Types].xml")
        self.manifest_file = os.path.join(self.build_template_swc, "manifest.xml")

        # Version number
        self.major_version = 1
        self.minor_version = 0
        self.patch_version = 0

    def create_swc(self):
        """Generate swc file from templateSwc folder"""
        ziph = zipfile.ZipFile(self.swc_file, 'w', compression=zipfile.ZIP_DEFLATED)

        for root, _, files in os.walk(self.build_template_swc):
            for file in files:
                absolute_path = os.path.join(root, file)
                relative_path = os.path.relpath(absolute_path, self.build_template_swc)
                ziph.write(absolute_path, relative_path)

        ziph.close()

    @staticmethod
    def get_hexbitmask(size):
        """Bitmask for SDL output if no bitmask is defined in input"""
        lres = "FF"
        if size == "2":
            lres = "FFFF"
        elif size == "4":
            lres = "FFFFFFFF"
        elif size == "8":
            lres = "FFFFFFFFFFFFFFFF"

        return lres

    def indent(self, elem, level=0):
        """Output formatter for XML write

        Taken from http://effbot.org/zone/element-lib.htm#prettyprint
        """
        i = "\n" + level * "\t"
        if elem:
            if not elem.text or not elem.text.strip():
                elem.text = i + "\t"
            if not elem.tail or not elem.tail.strip():
                elem.tail = i
            for elem in elem:
                self.indent(elem, level+1)
            if not elem.tail or not elem.tail.strip():
                elem.tail = i
        else:
            if level and (not elem.tail or not elem.tail.strip()):
                elem.tail = i

    def parse_complex_type(self, root_doc, complex_type, outp):
        """Parse Complex Type input sdl (recursive called)"""
        lres = False
        for tpd in root_doc.findall('Typedef'):
            if complex_type == tpd.attrib.get('Name'):
                lres = True
                if 'Size' in tpd.attrib:
                    if 'Size' not in outp.attrib:
                        outp.set('Size', tpd.attrib.get('Size'))
                for field in tpd.findall('Field'):
                    for signal in field.findall('Signal'):
                        out_signal = etree.SubElement(outp, 'Signal')
                        out_signal.set('Name', field.attrib.get('Name'))
                        out_signal.set('Offset', signal.attrib.get('Offset'))
                        out_signal.set('ArrayLen', signal.attrib.get('ArrayLen'))
                        out_signal.set('Type', signal.attrib.get('Type'))
                        if 'Bitmask' in signal.attrib:
                            out_signal.set('Bitmask', signal.attrib.get('Bitmask'))
                        else:
                            out_signal.set('Bitmask', self.get_hexbitmask(
                                signal.attrib.get('Size')))
                        out_signal.set('ByteOrder', signal.attrib.get('ByteOrder'))
                        if 'Units' in signal.attrib:
                            out_signal.set('Units', signal.attrib.get('Units'))
                        out_signal.set('Size', signal.attrib.get('Size'))

                    for signalg in field.findall('ComplexSignal'):
                        out_sig_grp = etree.SubElement(outp, 'SubGroup')
                        out_sig_grp.set('Name', field.attrib.get('Name'))
                        out_sig_grp.set('Offset', signalg.attrib.get('Offset'))
                        out_sig_grp.set('ArrayLen', signalg.attrib.get('ArrayLen'))
                        if 'Size' in signalg.attrib:
                            out_sig_grp.set('Size', signalg.attrib.get('Size'))
                        self.parse_complex_type(
                            root_doc, signalg.attrib.get('Type'), out_sig_grp)

        return lres

    @staticmethod
    def calc_crc_32_from_file(filename):
        """Calculate CRC32 from file"""
        with open(filename, 'rb') as in_file:
            buf = in_file.read()
            buf = (binascii.crc32(buf) & 0xFFFFFFFF)
            return "%08X" % buf

        return "00000000"

    @staticmethod
    def calc_md_5_from_file(filename):
        """Calculate MD5 checksum from file

        return MD5 string
        """
        with open(filename, mode='rb') as file_handle:
            hash_md5 = hashlib.md5()
            while True:
                # 128 is smaller than the typical filesystem block
                buf = file_handle.read(4096)
                if not buf:
                    break
                hash_md5.update(buf)

            return hash_md5.hexdigest()

    def generate_manif_rel_string(self, folder, file):
        """Generate ManifestRel Item and calculate CRC32 Checksum for referenced XML"""
        file_path = os.path.join(self.build_template_swc, folder, file)
        out_id = 'R00000000'  # id for file not exists
        if not os.path.exists(file_path):
            logging.error("Error file not exists: %s", file_path)
        else:
            out_id = 'R' + self.calc_crc_32_from_file(file_path)
            logging.debug("CRC32 from (%s) : %s", file_path, out_id)
        lres = '<Relationship Target="/'
        lres += folder
        lres += '/'
        lres += file
        lres += '" Id="'
        lres += out_id
        lres += '" Type="http://schemas.continental-corporation.com/mts/2016/relationships/software-container/'
        lres += folder
        lres += '"/>'

        return lres

    def create_manifest_rels(self):
        """Create manifest.xml.rels"""
        with open(self.manifest_rel, "w") as outfile:
            outfile.write(
                '<?xml version="1.0"?><Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">')
            outfile.write(self.generate_manif_rel_string('channel-mapping', 'channel-mapping.xml'))
            outfile.write(self.generate_manif_rel_string('cycle-definition', 'cycle-definition.xml'))
            outfile.write(self.generate_manif_rel_string('channel-definition', 'channel-definition.xml'))
            outfile.write(self.generate_manif_rel_string('sdl', 'ap_pdo_tool.sdl'))
            outfile.write(self.generate_manif_rel_string('hw-data-cycle', 'hw-data-cycle.xml'))
            outfile.write('</Relationships>')
            outfile.close()

    def create_content_types(self):
        """Create [Content_Types].xml"""
        with open(self.comment_type_file, "w") as outfile:
            outfile.write(
                '<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">')
            outfile.write(
                '<Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/>')
            outfile.write(
                '<Default Extension="xml" ContentType="application/vnd.continental-corporation.mts.software-container.channel-definition+xml"/>')
            outfile.write('<Override PartName="/cycle-definition/cycle-definition.xml" ContentType="application/vnd.continental-corporation.mts.software-container.cycle-definition+xml"/>')
            outfile.write(
                '<Default Extension="sdl" ContentType="application/vnd.continental-corporation.mts.software-container.sdl+xml"/>')
            outfile.write('<Override PartName="/channel-mapping/channel-mapping.xml" ContentType="application/vnd.continental-corporation.mts.software-container.channel-mapping+xml"/>')
            outfile.write(
                '<Override PartName="/hw-data-cycle/hw-data-cycle.xml" ContentType="application/vnd.continental-corporation.mts.software-container.hw-data-cycle+xml"/>')
            outfile.write(
                '<Override PartName="/manifest.xml" ContentType="application/vnd.continental-corporation.mts.software-container.manifest+xml"/>')
            outfile.write('</Types>')

    def create_manifest(self):
        """Create manifest.xml"""
        date_ts = datetime.datetime.now()
        crc_val = 0x0
        project = 'CEM200'
        man_out = etree.Element("Container")
        prop_out = etree.SubElement(man_out, "Properties")
        etree.SubElement(prop_out, "Version").text = str(
            self.major_version) + '.' + str(self.minor_version) + '.' + str(self.patch_version)
        etree.SubElement(prop_out, "BuildType").text = '16'
        etree.SubElement(prop_out, "BuildDate").text = str(date_ts)
        etree.SubElement(prop_out, "ProjectId").text = project
        etree.SubElement(prop_out, "SWVersion").text = self.sw_project_version
        etree.SubElement(prop_out, "Crc").text = str(crc_val)
        meta_out = etree.SubElement(man_out, "Metadata")
        etree.SubElement(meta_out, "EntityId").text = '??'
        etree.SubElement(meta_out, "EntityName").text = socket.gethostname()
        etree.SubElement(meta_out, "Maintainer").text = getpass.getuser()
        self.indent(man_out)
        out_tree = etree.ElementTree(man_out)
        out_tree.write(self.manifest_file, xml_declaration=True, encoding='utf8', method='xml')

    def create_compiled_sdl(self):
        """Create compiled sdl file

        return 0 => ok  else return errorcode
        """
        outroot = etree.Element("SdlFile")
        outroot.set('Version', '2.0')
        outroot.set('ByteAlignment', '1')
        if not os.path.exists(self.sdl_input_file):
            logging.error("SWC Inputfile not found: %s", self.sdl_input_file)
            return 2  # exit error 2
        logging.info("SWC Inputfile n: %s", self.sdl_input_file)

        tree = etree.parse(self.sdl_input_file)
        root = tree.getroot()
        logging.debug("Nr of elements: %d", len(root))
        for elem in tree.findall('View'):
            logging.debug("View name: %s Cycle ID: %s Elements: %d", elem.attrib.get('Name'),
                          elem.attrib.get('CycleID'), len(elem))
            out_view = etree.SubElement(outroot, "View")
            out_view.set('Name', elem.attrib.get('Name'))
            out_view.set('CycleID', elem.attrib.get('CycleID'))
            if elem:
                for group in elem.findall('Group'):
                    out_group = etree.SubElement(out_view, "Group")
                    out_group.set('Name', group.attrib.get('Name'))
                    out_group.set('Address', group.attrib.get('Address'))
                    out_group.set('ArrayLen', group.attrib.get('ArrayLen'))
                    out_group.set('Size', group.attrib.get('Size'))

                    for field in group.findall('Field'):
                        for signal in field.findall('Signal'):
                            out_signal = etree.SubElement(out_group, 'Signal')
                            out_signal.set('Name', field.attrib.get('Name'))
                            out_signal.set('Offset', signal.attrib.get('Offset'))
                            out_signal.set(
                                'ArrayLen', signal.attrib.get('ArrayLen'))
                            out_signal.set('Type', signal.attrib.get('Type'))
                            if 'Bitmask' in signal.attrib:
                                out_signal.set(
                                    'Bitmask', signal.attrib.get('Bitmask'))
                            else:
                                out_signal.set('Bitmask', self.get_hexbitmask(
                                    signal.attrib.get('Size')))
                            out_signal.set(
                                'ByteOrder', signal.attrib.get('ByteOrder'))
                            if 'Units' in signal.attrib:
                                out_signal.set('Units', signal.attrib.get('Units'))
                            out_signal.set('Size', signal.attrib.get('Size'))

                        for signalg in field.findall('ComplexSignal'):
                            out_sig_grp = etree.SubElement(out_group, 'SubGroup')
                            out_sig_grp.set('Name', field.attrib.get('Name'))
                            out_sig_grp.set('Offset', signalg.attrib.get('Offset'))
                            out_sig_grp.set(
                                'ArrayLen', signalg.attrib.get('ArrayLen'))
                            if 'Size' in signalg.attrib:
                                out_sig_grp.set('Size', signalg.attrib.get('Size'))
                            self.parse_complex_type(
                                tree, signalg.attrib.get('Type'), out_sig_grp)
            logging.debug("end view")
        self.indent(outroot)
        out_tree = etree.ElementTree(outroot)
        out_tree.write(self.sdl_compiled_file, xml_declaration=True, encoding='utf8', method='xml')

        with open(self.sdl_compiled_file, "r") as myfile:
            data = myfile.readlines()
            myfile.close()
            with open(self.sdl_compiled_file, "w") as outfile:
                data.remove(data[0])
                data.remove(data[0])
                outfile.writelines("<?xmlspysps SDL2-Before-compiler.sps?>\n")
                outfile.writelines("<!--PDO-Tool Revision: 2.14-->\n")
                outfile.writelines(
                    '<SdlFile xmlns:xsd="http://www.w3.org/2001/XMLSchema-instance" xsd:noNamespaceSchemaLocation="sdl2-after-compiler.xsd" ByteAlignment="1" Version="2.0">\n')
                outfile.writelines(["%s" % item for item in data])
                outfile.close()

        return 0

    def create_sdl_folder(self):
        """Create whole sdl folder including swc file

        return 0 => ok else errorcode for cmake
        """
        ret_val = self.create_compiled_sdl()
        if ret_val:
            return ret_val

        # Create missing sdl directory in templateSwc directory
        # Caused due to empty sdl directory in source directory
        if not os.path.exists(self.build_template_swc_sdl):
            logging.debug("Create path %s", self.build_template_swc_sdl)
            os.makedirs(self.build_template_swc_sdl)

        logging.debug("Copy %s to %s", self.sdl_compiled_file, self.build_template_swc_sdl)
        shutil.copy(self.sdl_compiled_file, self.build_template_swc_sdl)

        self.create_manifest_rels()
        self.create_content_types()
        self.create_manifest()

        logging.info("start SWC generation...")
        self.create_swc()
        logging.info("SWC generation finish.")

        self.create_md5_test_file()

        return 0  # no error

    def add_file_item_info(self, name, filename, element):
        """Add file item info"""
        out_file_info = etree.SubElement(element, 'File')
        out_file_info.set('Name', name)
        out_file_info.set('Md5', self.calc_md_5_from_file(filename))

    def create_md5_test_file(self):
        """Create md5 test file"""
        cur_test = etree.Element('SwcCheck')
        cur_test.append(etree.Comment('createSwc.py ' + getpass.getuser() +
                                      ' host: ' + socket.gethostname() + ' Date: ' + str(datetime.datetime.now())))
        self.add_file_item_info('swcInputFile', self.sdl_input_file, cur_test)
        self.add_file_item_info('channel-definition', self.channel_definition_file, cur_test)
        self.add_file_item_info('channel-mapping', self.channel_mapping_file, cur_test)
        self.add_file_item_info('cycle-definition', self.cycle_definition_file, cur_test)
        self.add_file_item_info('hw-data-cycle', self.hw_data_cycle_file, cur_test)
        self.indent(cur_test)

        ver_info = etree.Element('VersionVerification')
        ver_info.set('Major', hex(self.major_version))
        ver_info.set('Minor', hex(self.minor_version))
        ver_info.set('Patch', hex(self.patch_version))

        cur_test.append(ver_info)
        out_tree = etree.ElementTree(cur_test)
        out_tree.write(self.md_5_test_file, xml_declaration=True, encoding='utf8', method='xml')

    def check_new_swc_generation_needed(self):
        """Check if a new SWC generation is needed

        conditions to create:
           - SWC file not exist
           - MD5 ap_pdo_tool.sdl is different to stored MD5
        result == True if a new generation is needed
        on result == True if the MD5 file is written with the current MD5 value
        """
        result = False
        if not os.path.exists(self.sdl_input_file):
            logging.error("SWC Inputfile not found: %s", self.sdl_input_file)
            return result  # False  no build possible
        currend_md_5 = self.calc_md_5_from_file(self.sdl_input_file)
        if not os.path.exists(self.swc_file):
            logging.info("existing SWC file not found so rebuild is required: %s", self.swc_file)
            result = True
        else:
            if not os.path.exists(self.md_5_test_file):
                logging.info("First run for MD5 creation")
                result = True
            else:
                oldtree = etree.parse(self.md_5_test_file)
                oldroot = oldtree.getroot()
                for version_verification in oldroot.findall("VersionVerification"):
                    major = version_verification.attrib.get('Major')
                    minor = version_verification.attrib.get('Minor')
                    patch = version_verification.attrib.get('Patch')
                    self.major_version = int(major, 16)
                    self.minor_version = int(minor, 16)
                    self.patch_version = int(patch, 16)
                logging.info("Found Version: %d.%d.%d", self.major_version, self.minor_version,
                             self.patch_version)
                found_items = 0
                for item in oldroot.findall("File"):
                    name = item.attrib.get("Name")
                    md_5 = item.attrib.get("Md5")
                    check_file = None

                    if name == 'swcInputFile':
                        check_file = self.sdl_input_file
                    elif name == 'channel-definition':
                        check_file = self.channel_definition_file
                    elif name == 'channel-mapping':
                        check_file = self.channel_mapping_file
                    elif name == 'cycle-definition':
                        check_file = self.cycle_definition_file
                    elif name == 'hw-data-cycle':
                        check_file = self.hw_data_cycle_file

                    if check_file is not None:
                        if os.path.exists(check_file):
                            found_items += 1
                            currend_md_5 = self.calc_md_5_from_file(check_file)
                            if currend_md_5 != md_5:
                                result = True
                                logging.info("Compare error in file: %s", check_file)
                        else:
                            logging.error("File not found: %s", check_file)
                if found_items < 4:
                    result = True
                    logging.info("No 4 compare items found")

        return result

    @staticmethod
    def check_run_on_jenkins():
        """Check if script run on local machine or Jenkins  => enviroment JENKINS_URL

        see https://wiki.jenkins.io/display/JENKINS/Building+a+software+project
        return True => jenkins run else false"""
        result = False
        if os.getenv("JENKINS_URL") is not None:
            result = True

        return result

def main():
    """Main program"""
    logging.info("SWC script start")
    try:
        cem_base_dir = sys.argv[1]
        cem_build_dir = sys.argv[2]
        pdo_tool_dir = sys.argv[3]
        target = sys.argv[4]
        sw_project_version = sys.argv[5]
    except IndexError:
        print('Usage: ./createSwc.py <CEM_BASE_DIR> <CEM_BUILD_DIR> /CEM200/ sw_project_versio')
        sys.exit(1)

    template_base_dir = os.path.join(pdo_tool_dir, "pdo_tool")
    if 'CEM200' in target:
        template_base_dir = os.path.join(template_base_dir, "templateSwc")
    else:
        logging.error("ERROR: wrong target")
        sys.exit(1)

    swc_generation = SwcGeneration(cem_build_dir, sw_project_version)

    if swc_generation.check_new_swc_generation_needed():

        shutil.rmtree(swc_generation.build_template_swc, ignore_errors=True)

        # copy whole templateSwc directory to build directory
        shutil.copytree(template_base_dir, swc_generation.build_template_swc)

        swc_ret = swc_generation.create_sdl_folder()
        if swc_ret != 0:
            sys.exit(swc_ret)
    else:
        logging.info("No SWC update needed")
    sys.exit(0)  # no error

if __name__ == '__main__':
    main()
