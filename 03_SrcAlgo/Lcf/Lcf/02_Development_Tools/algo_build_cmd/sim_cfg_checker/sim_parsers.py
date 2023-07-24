"""
sim_cfg_checker.sim_parsers
---------

Module for interpreting sim configuration files

:org:           Continental AG
:author:        Alejandro Lopez

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:16CET $

"""

MEMBER_VERSION = "$Revision: 1.1 $"
print "sim_parsers.py {rev}".format(rev=MEMBER_VERSION)

import re
import os


class SimVfbCfgParser(object):

    def __init__(self, file_path):
        """

        :param unicode file_path: Path to the file
        """
        self._filename = file_path
        self._file = open(file_path, 'r')

        # print filename

    @property
    def filename(self):

        return re.search('[^\\\\]+$', self._filename).group(0)

    def close_file(self):

        return self._file.close()


class SimcfgParser(SimVfbCfgParser):

    def __init__(self, file_path):

        super(SimcfgParser, self).__init__(file_path)

    def get_ports_generator(self):
        return [self.get_exposed_request_ports,
                self.get_exposed_provide_ports,
                self.get_exposed_client_ports,
                self.get_exposed_server_ports]

    def _get_exposed_ports(self, cfg_section_type):
        """
        Goes through the simcfg file finding all exposed ports of the specified type
        """
        self._file.seek(0)
        file_content = self._file.xreadlines()
        right_section = False
        ports = {}
        for line in file_content:
            if re.match('CfgSectionType[ \t]*=[ \t]*' + cfg_section_type, line):
                right_section = True
            elif right_section and re.match('(CfgSectionType|\[)', line):
                break
            elif right_section:
                match = re.match('[ \t]*(.+?)[ \t]*=[ \t]*(.+)[ \t]*\n?', line)
                # If there is a match on the pattern "something = something else" and there is no leading ";" the port
                # is accepted as valid
                if match and not re.match('^[ \t]*;', line):
                    ports[match.group(1)] = match.group(2)

        return ports

    def get_exposed_request_ports(self):
        """
        Goes through the simcfg file finding all exposed request ports
        """
        return self._get_exposed_ports('ExposedRequestPort')

    def get_exposed_provide_ports(self):
        """
        Goes through the simcfg file finding all exposed provide ports
        """
        return self._get_exposed_ports('ExposedProvidePort')

    def get_exposed_client_ports(self):
        """
        Goes through the simcfg file finding all exposed client ports
        """
        return self._get_exposed_ports('ExposedClientPort')

    def get_exposed_server_ports(self):
        """
        Goes through the simcfg file finding all exposed server ports
        """
        return self._get_exposed_ports('ExposedServerPort')

    def get_dummy_ini(self):

        ini_file_name = re.sub('\.simcfg', '.ini', self._filename)

        ini_parser = IniParser(ini_file_name)

        return ini_parser

    def get_dummy_simudex(self):

        ini_file_name = re.sub('\.simcfg', '.simudex', self._filename)

        simudex_parser = SimudexParser(ini_file_name)

        return simudex_parser

    def check_plugins_availability(self, root_path):
        """
        Searches the config file for dll paths and checks the availability of such paths
        """
        available_dlls = {}
        abs_path = os.path.abspath(root_path)

        try:
            dll_root_path = abs_path.split('\\')[:abs_path.split('\\').index('cfg')] + ['dll']

            self._file.seek(0)
            file_content = self._file.xreadlines()
            for line in file_content:
                match = re.match('PluginFile[ \t]*=[ \t]*\$UserPathMeasObj\$(.+).dll', line)
                if match:
                    filename = match.group(1) + ".dll"
                    filename = re.sub('\$.+?\$', '', filename)
                    filepath = '\\'.join(dll_root_path) + filename

                    available_dlls[filepath] = os.path.isfile(filepath)

            return available_dlls

        except ValueError:
            raise Exception("Unable to find 'cfg' folder in given path: {0}".format((abs_path,)))


class IniParser(SimVfbCfgParser):

    def __init__(self, file_path):

        super(IniParser, self).__init__(file_path)

        # self._declared_ports_no is only usable as long as "NumPorts" string is part of the ini file
        self._declared_ports_no = None
        self._greatest_port_number = None
        self._ports = set()
        self._errors = []

        self._parse_file()

    @property
    def declared_ports_no(self):

        return self._declared_ports_no

    @property
    def ports(self):

        return self._ports

    @property
    def greatest_port_number(self):

        return self._greatest_port_number

    def _parse_file(self):

        self._file.seek(0)
        file_content = self._file.xreadlines()

        self._greatest_port_number = None

        for line in file_content:

            match = re.match('NumPorts[ \t]*=[ \t]*(\d+)', line)
            match_port = re.match('Name[ \t]*=[ \t]*([^ \t\n]+)', line)
            match_port_tag = re.match('\[Port(\d+)\]', line)

            if match:
                self._declared_ports_no = int(match.group(1))

            elif match_port:
                port_name = match_port.group(1)
                if port_name in self._ports:
                    self._errors.append("The dummy port named " + port_name + " is duplicated!")
                    continue

                self._ports.add("DUMMY." + port_name)

            elif match_port_tag:
                port_number = int(match_port_tag.group(1))

                # Updates the max port number defined
                if self._greatest_port_number is None or port_number > self._greatest_port_number:
                    self._greatest_port_number = port_number


class SimudexParser(SimVfbCfgParser):

    def __init__(self, file_path):

        super(SimudexParser, self).__init__(file_path)

        self._ports = set()
        self._errors = []
        self._parse_file()

    @property
    def ports(self):

        return self._ports

    def _parse_file(self):

        self._file.seek(0)
        file_content = self._file.xreadlines()

        for line in file_content:

            match_port = re.match('Name[ \t]*=[ \t]*([^ \t\n]+)', line)

            if match_port:
                port_name = match_port.group(1)
                if port_name in self._ports:
                    self._errors.append("The provide port named " + port_name + " is duplicated!")
                    continue

                self._ports.add("UDEX." + port_name)
