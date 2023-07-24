"""
sim_cfg_checker.sim_subcfg_checker_lib
---------

Module for checking the compliance of different kinds of algo components sub-configurations for jointsim

:org:           Continental AG
:author:        Alejandro Lopez

:version:       $Revision: 1.1 $
:contact:       $Author: Wang, David (Wangd3) $ (last change)
:date:          $Date: 2021/12/13 17:55:16CET $

"""

MEMBER_VERSION = "$Revision: 1.1 $"
print "sim_subcfg_checker_lib.py {rev}".format(rev=MEMBER_VERSION)

import os
import re
from sim_parsers import SimcfgParser, IniParser, SimudexParser
from junit_xml import TestSuite, TestCase
from mock import MagicMock
import time

HIL_WHITE_LIST = ["FCT", "VDY", "FEX"]

report_file_name = r'report.xml'
# report_file_path = os.path.join(os.path.dirname(__file__), report_file_name)
report_file_path = report_file_name


class SimVfbCfgParserLibObj(object):
    """
    Description: Check sim cfg files class
    """
    port_mismatch = "PORT_MISMATCH"
    ini_port_mismatch = "INI_PORT_MISMATCH"
    nr_ini_port_mismatch = "NR_INI_PORT_MISMATCH"
    no_ini_file_found = "NO_INI_FILE_FOUND"
    no_udex_file_found = "NO_UDEX_FILE_FOUND"
    udex_port_mismatch = "UDEX_PORT_MISMATCH"
    dll_missing = "DLL_MISSING"
    sub_cfg_missing = "SUB_CFG_MISSING"

    error_types = {port_mismatch, ini_port_mismatch, nr_ini_port_mismatch, no_ini_file_found, no_udex_file_found,
                   udex_port_mismatch, dll_missing, sub_cfg_missing}

    SIM = "sim"
    MEAS = "meas"
    HIL = "hil"

    comps_black_list = ["INGE"]

    def __init__(self, junit=None):

        self.analysis = {}
        self.port_types = ["request", "provide", "client", "server"]
        self.error_count = 0
        self.error_dict = {}

        # : :type: SubCfgReport
        self.report = MagicMock()

        if junit:
            self.report = JUnitReportWrapper(out_path=junit)

    def index_cfg_files(self, scan_folder):
        """
        Browses a folder finding and indexing the config files to analyse later

        :param str scan_folder: path to the folder to scan

        :raise OSError: In case the given directory does not exist

        """
        if not os.path.isdir(scan_folder):
            raise OSError("No folder: %s" % (scan_folder))

        for root, dirs, files in os.walk(scan_folder):
            sub_folder = {self.SIM: {}, self.MEAS: {}, self.HIL: {}, 'path': root}
            search = re.search('\\\\([^\\\\_]+?)$', root)
            if not search:
                continue

            component = search.group(1)

            if component.upper() in self.comps_black_list:
                continue

            for f in files:
                match = re.match(component + '_sim_sub\.(.+)', f)
                # VDY exception implementation
                match = match if match else re.match('vdy_sub\.(.+)', f)
                if match:
                    sub_folder[self.SIM][match.group(1)] = f
                    continue

                match = re.match(component + '_sim_sub_meas\.(.+)', f)
                if match:
                    sub_folder[self.MEAS][match.group(1)] = f
                    continue

                match = re.match(component + '_hil_sub\.(.+)', f)
                if match:
                    sub_folder[self.HIL][match.group(1)] = f
                    continue

            if component and sub_folder[self.SIM]:
                self.analysis[component.upper()] = sub_folder

        # for comp in self.analysis:
        #     print comp, self.analysis[comp]

    def external_port_interface_comparison(self, component, parser1, parser2):
        """
        Compares Provide, Request, Server and Client ports from two subconfig

        :param unicode component: Component short name
        :param SimcfgParser parser1: Parser of the first simcfg file
        :param SimcfgParser parser2: Parser of the second simcfg file

        """
        # Analysis starts
        i = 0
        for port_type_method1, port_type_method2 in zip(
                parser2.get_ports_generator(),
                parser1.get_ports_generator()
        ):
            sim_ports = port_type_method1()
            meas_ports = port_type_method2()
            print "%d/%d %s ports (sim/meas)" % (len(sim_ports), len(meas_ports), self.port_types[i])
            mismatches = set(sim_ports).__xor__(set(meas_ports))
            if mismatches:
                print "ERROR: Mismatch on", self.port_types[i], "ports", ", ".join(mismatches)

                # Add error to log file
                self.log_errors(
                    component,
                    self.port_mismatch,
                    u"'{0}' {1} port is missing in one of: {2}, {3}",
                    mismatches,
                    self.port_types[i],
                    parser1.filename,
                    parser2.filename)

            i += 1

    def parse_all_sim_cfg_files(self, scan_folder):
        """
        parse_all_sim_cfg_files(self, scan_folder)

        Description: Parse all the sim cfg files and stores the errors inside the class

        return the True if parsing was successful
        """

        self.report.add_properties(directory=scan_folder)

        self.index_cfg_files(scan_folder)

        for component, file_names in self.analysis.iteritems():

            self.run_sim(component, file_names, scan_folder)

            self.run_sim_meas(component, file_names)

            self.run_sim_hil(component, file_names)

        print "***********************************"
        print "Number of errors:", self.error_count

        self.report.to_file()

        return self.report

    def run_sim(self, component, file_names, scan_folder):

        self.report.add_test_case(component + ".SIM")

        try:
            sim_parser = SimcfgParser(file_names["path"] + "\\" + file_names[self.SIM]['simcfg'])

            # : :type: dict(str, bool)
            plugins_availability = sim_parser.check_plugins_availability(scan_folder)

            for path, availability in plugins_availability.iteritems():
                if not availability:
                    self.log_errors(
                        component,
                        self.dll_missing,
                        u"The plugin dll is missing at {0}",
                        mismatches={path}
                    )

        except KeyError:
            self.log_errors(
                component,
                self.sub_cfg_missing,
                u"The component {0} is missing files, thus checking sim is not possible",
                mismatches={component})

    def run_sim_meas(self, component, file_names):
        """
        Runs a sim vs meas config comparison

        :param unicode component: Short name of the component
        :param dict file_names: Path to files and file names for the sim, meas and hil subconfig
        """

        self.report.add_test_case(component + ".MEAS")

        # External port interface comparison (SIM vs MEAS) **************************************************
        try:
            sim_parser = SimcfgParser(file_names["path"] + "\\" + file_names[self.SIM]['simcfg'])
            meas_parser = SimcfgParser(file_names["path"] + "\\" + file_names[self.MEAS]['simcfg'])

            print "\n+ " + component.upper() + " (SIM vs MEAS) +++++++++++++++++++++"
            print "Comparing", file_names[self.SIM]['simcfg'], "to", file_names[self.MEAS]['simcfg'], "..."

            self.external_port_interface_comparison(component, sim_parser, meas_parser)

        except KeyError:
            self.log_errors(
                component,
                self.sub_cfg_missing,
                u"The component {0} is missing files, thus checking sim vs meas is not possible",
                mismatches={component})

        # Request ports comparison (SIM vs MEAS) **************************************************
        try:
            dummy_ini = IniParser(file_names["path"] + "\\" + file_names[self.MEAS]['ini'])
            meas_parser = SimcfgParser(file_names["path"] + "\\" + file_names[self.MEAS]['simcfg'])

            req_ports = meas_parser.get_exposed_request_ports()

            # Checks if all exposed ports are defined in the dummy, but allows defined ports not to be
            # exposed
            mismatches = set(req_ports.values()).discard(dummy_ini.ports)
            if mismatches:
                print "ERROR: Meas ini ports mismatch is", ", ".join(mismatches)

                # Add error to log file
                self.log_errors(
                    component,
                    u"'{0}' request signal must be declared by {1}",
                    mismatches,
                    dummy_ini.filename)

            elif dummy_ini.declared_ports_no is not None \
                    and dummy_ini.greatest_port_number != dummy_ini.declared_ports_no:
                print "ERROR:", dummy_ini.filename, "declared ports number mismatch: " \
                                                    "NumPorts=", dummy_ini.declared_ports_no, \
                                                    "Greatest port number defined=", dummy_ini.greatest_port_number
                # Add error to log file
                self.log_errors(
                    component,
                    self.nr_ini_port_mismatch,
                    u"{0} file has declared {1} ports but greatest port number is {2}",
                    {dummy_ini.filename},
                    dummy_ini.declared_ports_no,
                    dummy_ini.greatest_port_number)

            else:
                print dummy_ini.filename, "correct"

        except KeyError:
            # Add error to log file
            self.log_errors(component, self.no_ini_file_found, u"No ini file found for dummy plugin in 'meas' config")

        # Request ports comparison (SIM vs MEAS) **************************************************
        try:
            simudex = SimudexParser(file_names["path"] + "\\" + file_names[self.MEAS]['simudex'])
            meas_parser = SimcfgParser(file_names["path"] + "\\" + file_names[self.MEAS]['simcfg'])

            pro_ports = meas_parser.get_exposed_provide_ports()

            # Checks if all exposed ports are defined in the simudex, but allows defined ports not to be
            # exposed
            mismatches = set(pro_ports.values()).discard(simudex.ports)
            if mismatches:
                print "ERROR: Meas simudex ports mismatch is", ", ".join(mismatches)

                # Add error to log file
                self.log_errors(
                    component,
                    self.udex_port_mismatch,
                    u"'{0}' {1} port is either not exposed by {2} or not provided by {3}",
                    mismatches,
                    "provide",
                    component + '_sim_sub_meas.simcfg',
                    simudex.filename)

            else:
                print simudex.filename, "correct"

        except KeyError:
            # Add error to log file
            self.log_errors(component, self.no_udex_file_found, u"No simudex file found for 'meas' config")

    def run_sim_hil(self, component, file_names):
        """
        Runs a sim vs hil config comparison

        :param unicode component: Short name of the component
        :param dict file_names: Path to files and file names for the sim, meas and hil subconfig
        """

        component_upper = component.upper()

        if component_upper in HIL_WHITE_LIST:
            print "Component {0} is in the HIL white list".format(component_upper)
            return

        self.report.add_test_case(component + ".HIL")

        # External port interface comparison (SIM vs HIL) **************************************************
        try:
            sim_parser = SimcfgParser(file_names["path"] + "\\" + file_names[self.SIM]['simcfg'])
            hil_parser = SimcfgParser(file_names["path"] + "\\" + file_names[self.HIL]['simcfg'])

            print "\n+ " + component_upper + " (SIM vs HIL) +++++++++++++++++++++"
            print "Comparing", file_names[self.SIM]['simcfg'], "to", file_names[self.HIL]['simcfg'], "..."

            self.external_port_interface_comparison(component, sim_parser, hil_parser)

        except KeyError:
            self.log_errors(
                component,
                self.sub_cfg_missing,
                u"The component {0} is missing files, thus checking sim vs hil is not possible",
                {component})

    def log_errors(self, component, type, message, mismatches=set(), *args):
        """
        Generic mismatches log method

        :param unicode component: Short name of the component
        :param basestring type: Type of error
        :param unicode message: Message to be logged
        :param set of unicode mismatches: Found mismatches

        """
        assert type in self.error_types

        for mismatch in mismatches:
            # Init component in dictionary
            if component not in self.error_dict:
                self.error_dict[component] = {}
            # Init port type in dictionary
            if type not in self.error_dict[component]:
                self.error_dict[component][type] = []
            # Add error to log
            self.error_dict[component][type].append(message.format(mismatch, *args))

            report_message = message.format(mismatch, *args)
            if type in self.report.skip_test_reasons:
                self.report.add_skipped_to_current_case(report_message)
            else:
                self.report.add_failure_to_current_case(report_message)

            # Increment the error count
            self.error_count += 1

    def errors(self):
        """
        Getter function to get all the sim file errors, dictionary with component, and file

        :return: The error dict
        :rtype: dict of dict of list

        """
        return self.error_dict

    def errors_no(self):
        """
        Getter function to get the number of errors

        :return: The number of errors found
        :rtype: int

        """
        return self.error_count

    def __str__(self):
        """
        print the error log
        """
        ret_value = ""
        ret_value += "***********************************\n"
        ret_value += "Number of errors: %s\n" % self.error_count

        for comp in self.error_dict:
            ret_value += "-------- Config errors for component " + comp + " ---------\n"
            for item in self.error_dict[comp]:
                for error in self.error_dict[comp][item]:
                    ret_value += error + "\n"

        return ret_value


class SubCfgReport(object):

    skip_test_reasons = set()

    def add_test_case(self, name):
        raise NotImplementedError()

    def add_properties(self, **properties):
        raise NotImplementedError()

    def add_failure_to_current_case(self, failure_message):
        raise NotImplementedError()

    def add_skipped_to_current_case(self, skipped_message):
        raise NotImplementedError()

    def to_file(self):
        raise NotImplementedError()

    def set_test_case_elapsed_time(self, secs):
        raise NotImplementedError()


class JUnitReportWrapper(SubCfgReport):

    skip_test_reasons = {SimVfbCfgParserLibObj.sub_cfg_missing, }

    def __init__(self, out_path=report_file_path, **kwargs):
        super(JUnitReportWrapper, self).__init__()

        # test_cases = [TestCase('Test1', 'some.class.name', 123.345, 'I am stdout!', 'I am stderr!')]
        self.test_suite = TestSuite(name="SimSubCfg Checker", properties=kwargs)
        # pretty printing is on by default but can be disabled using prettyprint=False
        # print(TestSuite.to_xml_string([ts]))

        # : :type: TestCase
        self.last_test_case = None

        # : :type: str|unicode
        self.out_path = out_path

    def add_test_case(self, name):

        try:
            self.last_test_case.elapsed_sec = time.time() - self.last_test_case.sec
        except AttributeError:
            pass

        test_case = TestCase(name=name)
        self.test_suite.test_cases.append(test_case)
        self.last_test_case = test_case

        self.last_test_case.sec = time.time()

    def __str__(self):
        return TestSuite.to_xml_string(test_suites=[self.test_suite])

    def add_properties(self, **properties):
        self.test_suite.properties = properties

    def add_failure_to_current_case(self, failure_message):
        if self.last_test_case.is_failure():
            message = " | ".join((self.last_test_case.failure_message, failure_message))
        else:
            message = failure_message
        self.last_test_case.add_failure_info(message=message)

    def add_skipped_to_current_case(self, skipped_message):
        if self.last_test_case.is_skipped():
            message = " | ".join((self.last_test_case.failure_message, skipped_message))
        else:
            message = skipped_message
        self.last_test_case.add_skipped_info(message=message)

    def to_file(self):
        fd = open(self.out_path, 'w')
        TestSuite.to_file(fd, [self.test_suite])
