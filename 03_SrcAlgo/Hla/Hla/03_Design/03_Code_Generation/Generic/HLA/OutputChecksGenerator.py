# OutputChecksGenerator.py:
# -------------------------
#
# This python script is intended to parse RTE interface excel and create relevant output checks.
# It's configured by corresponding xml file.
# NOTE: Run this script in component repository context due to dependency to our private python_tools

# -------------------------
# import
# -------------------------
from __future__ import print_function

import sys
import stat
import re
import os
import logging
import argparse

# Added path to our python packages
sys.path.extend([os.path.abspath(r".\..\..\..\..\04_Engineering\02_Development_Tools\python_tools\packages")])
# noinspection PyUnresolvedReferences
from excelaccess.libwrappers.excel_file_reader import ExcelFileReader
# noinspection PyUnresolvedReferences
from excelaccess.utils import unorderd_tree as utree
# noinspection PyUnresolvedReferences
from excelaccess.utils.general_functions import get_doxygen_legacy, get_doxygen
# noinspection PyUnresolvedReferences
from excelaccess.xmldescriptor.xml_defs import function_name_prefix, function_name_infix, error_code_prefix, \
    warning_code_prefix, indentation_baseline, indentation_step, doxygen_line_length, doxygen_line_start, \
    function_local_declaration_start, function_local_declaration_end, function_global_definition_start, \
    function_global_definition_end, function_call_main_start, function_call_main_end, error_enum_start, error_enum_end, \
    warning_enum_start, warning_enum_end, error_draw_start, error_draw_end, warning_draw_start, warning_draw_end, \
    error_handling_header, template_name, output_file_name, visu_error, c_warning_function_name, c_error_function_name, \
    c_error_or_warning_number_function, name_clearing_regex, code_clearing_regex, excel_http_path, doxy_comment_start_column
from OutputChecksGeneratorCCode import SwitchCase, OutputBlockComposer, IfThenElse, Function, ForLoop

# regular expressions for string matching and string substitution
# TODO: movable if just locally needed
regex_int = re.compile(r"(u)?(int)")
regex_float = re.compile(r"(float)")
regex_decnum = re.compile(r"([+-]?[0-9]+)([.,][0-9]*)?(e[0-9]+)?([fu])?")
regex_hexnum = re.compile(r"(0x)([0]*)([0-9A-F]+)")
# 1st match optional type cast to uint8/uint16/uint32/sint8/sint16/sint32
# 2nd match obligatory match arbitrary amount of uppercase letters, underscores and numbers but starting with an
# uppercase letter
# 3rd match optional -1 with optional single whitespaces in between and optional u literal
regex_enum = re.compile(r"(\([su]int[12368]{1,2}\))?(\(?[A-Z][A-Z_0-9]+)(\s?-\s?1u?\s?\)?)?")

# logging
logger = None

# TODO: find cleaner solution (more reliable mapping, see also below header mapping function); best: updating if
# TODO: header changed (e.g. correcting the 'ussed' to 'used' would break it just like misspellings in different
# TODO: versions of the Excel sheets)? ; e.g. just rebuild base class from which others inherit
header_mapping_dict = {"data element": "data_element", "description": "description", "reference": "reference",
                       "data type": "data_type", "array size": "array_size",
                       "typ. resolution": "typ_resolution", "physical unit": "physical_unit", "typ. range": "typ_range",
                       "fs range": "fs_range", "fs ussed array size": "fs_ussed_array_size",
                       "fs rel. gradient rangeper sec in %": "fs_rel_gradient_rangeper_sec_in_per",
                       "fs abs. gradient rangeper sec": "fs_abs_gradient_rangeper_sec", "fs comment": "fs_comment",
                       "plausibility checks": "plausibility_checks", "default value": "default_value",
                       "output check fallback value": "output_check_fallback_value", "mts name": "mts_name",
                       "virtual address": "virtual_address", "cycleid": "cycleid", "projects": "projects",
                       "generic interface": "generic_interface", "remark": "remark"}

# data type mappings (from Excel file: 'Misc' sheet)
data_type_struct = "struct"
data_type_reference = "ref"
data_type_enum = "enum"
data_type_uint8 = "uint8"
data_type_uint16 = "uint16"
data_type_uint32 = "uint32"
data_type_uint64 = "uint64"
data_type_float32 = "float32"
data_type_float64 = "float64"
data_type_boolean = "boolean"
data_type_sint8 = "sint8"
data_type_sint16 = "sint16"
data_type_sint32 = "sint32"
data_type_sint64 = "sint64"


def main():
    # argument parsing taking one or no input
    parser = argparse.ArgumentParser(description="Input (relative) path to configuration XML file.")
    parser.add_argument("xml_configuration_file_path",
                        help="Input (relative) path to configuration XML file. Defaults to looking for next .xml in same directory.",
                        nargs="?", type=str, default=None)
    args = parser.parse_args()
    xml_configuration_file_path = args.xml_configuration_file_path
    if xml_configuration_file_path is None:
        # get path where script is located and look for config file by extension
        root_path = os.path.split(os.path.realpath(__file__))[0]
        for file_ in os.listdir(root_path):
            if file_.endswith(".xml"):
                xml_configuration_file_path = os.path.join(root_path, file_)
                break
    else:
        xml_configuration_file_path = os.path.abspath(xml_configuration_file_path)

    # get excel file reader and compute Excel in a first step; also takes xml config in
    component_efo = ExcelFileReader(xml_configuration_file_path).read_excel_file()
    component_efo.get_sheet_contents(component_efo.xml_parser.get_sheet_names())

    output_checks = OutputChecks(component_efo)
    # first step, create kind of ordered data structure
    output_checks.precompute_sheets()
    # use data structure for ordered computing and printing of inherent data
    output_checks.write_output()


class OutputChecks:
    """Takes an excel file object to read and compute its data in order to create appropriate C code from it.

    :param excel_file_object: an excel file object
    :type excel_file_object: ExcelFileObject
    """

    def __init__(self, excel_file_object):
        self.efo = excel_file_object
        self.reference_dict = {}
        self.unresolved_references_dict = {}
        self.unresolvable_references_dict = {}
        self.single_occurrence_dict = {}
        self.sheet_obj_list = []

        # TODO: move below stuff all to an own class in ExcelAccess which gets then imported instead of all keys etc.?
        self.excel_file_name = os.path.basename(self.efo.xml_parser.get_excel_path())
        self.excel_http_path = self.get_configuration_attribute(excel_http_path)
        self.doxy_comment_start_column = int(self.get_configuration_attribute(doxy_comment_start_column))

        # name prefixes which are used for output strings
        self.function_name_prefix = self.get_configuration_attribute(function_name_prefix)
        self.function_name_infix = self.get_configuration_attribute(function_name_infix)
        self.error_code_prefix = self.get_configuration_attribute(error_code_prefix)
        self.warning_code_prefix = self.get_configuration_attribute(warning_code_prefix)

        # output file line marker strings needed to find lines for inserting generated code
        self.function_local_declaration_start = self.get_configuration_attribute(function_local_declaration_start)
        self.function_local_declaration_end = self.get_configuration_attribute(function_local_declaration_end)
        self.function_global_definition_start = self.get_configuration_attribute(function_global_definition_start)
        self.function_global_definition_end = self.get_configuration_attribute(function_global_definition_end)
        self.function_call_main_start = self.get_configuration_attribute(function_call_main_start)
        self.function_call_main_end = self.get_configuration_attribute(function_call_main_end)

        # error/warning starts/ends file line marker strings needed to find lines for inserting generated code
        self.error_enum_start = self.get_configuration_attribute(error_enum_start)
        self.error_enum_end = self.get_configuration_attribute(error_enum_end)
        self.warning_enum_start = self.get_configuration_attribute(warning_enum_start)
        self.warning_enum_end = self.get_configuration_attribute(warning_enum_end)

        # output destinations, meaning where and in which file to print generated code
        self.error_handling_header = self.get_configuration_attribute(error_handling_header)
        self.output_checks_file_name = self.get_configuration_attribute(output_file_name)

        # output specification (stuff like general formatting information)
        self.indentation_baseline = self.get_configuration_attribute(indentation_baseline)
        self.indentation_step = self.get_configuration_attribute(indentation_step)
        self.name_clearing_regex = re.compile(self.get_configuration_attribute(name_clearing_regex))
        self.code_clearing_regex = re.compile(self.get_configuration_attribute(code_clearing_regex))

        # doxygen formatting information
        self.doxygen_line_length = int(self.get_configuration_attribute(doxygen_line_length))
        self.doxygen_line_start = int(self.get_configuration_attribute(doxygen_line_start))
        self.doxygen_line_border = self.doxygen_line_length - self.doxygen_line_start

        function_call_postfix = "({0});"
        self.set_warning_function_template = self.get_configuration_attribute(
            c_warning_function_name) + "({0});"
        self.set_error_function_template = self.get_configuration_attribute(
            c_error_function_name) + "({0});"
        self.get_error_or_warning_number = self.get_configuration_attribute(
            c_error_or_warning_number_function) + "{0}s()"

        # utility variables (e.g. for data staging before output
        self.function_declarations = None
        self.function_main_calls = None
        self.function_definitions = None

        self.function_declaration_template = "static void {prefix}{fn_name}({class_name}{class_suffix}* const p{field_name})"

        init_logger()

    def get_configuration_attribute(self, attribute_name):
        """Simple wrapper, which gets the specified attribute from XML.

        :param str attribute_name: name of the attribute to retrieved
        """
        return self.efo.xml_parser.get_excel_configuration().get(attribute_name)

    def precompute_sheets(self):
        """Compute excel file on sheet level."""
        # iterate over all sheets from excel file object and compute tables of each
        for sheet in self.efo.get_sheets():
            sheet_obj = Sheet(sheet, self)
            self.precompute_tables(sheet_obj)
            if sheet_obj not in self.sheet_obj_list:
                self.sheet_obj_list.append(sheet_obj)
        self.resolve_references()

    def precompute_tables(self, sheet_obj):
        """Compute excel sheet on table level.

        :param Sheet sheet_obj: sheet object to be computed
        """
        # iterate over all tables of a sheet object (in this special case should be one) and compute its content
        for table in sheet_obj.sheet.get_tables():
            table_obj = Table(table, sheet_obj.name)
            sheet_obj.add_table(table_obj)
            self.check_reference_status(table_obj)

            log = "\n{lines}\n{name}:\n{lines}\n".format(name=sheet_obj.name, lines="-" * (len(sheet_obj.name) + 1))
            for struct in table_obj.struct_list:
                log += "{0}: ".format(struct.data_element)
                for field in struct.field_list:
                    log += field.data_element + ("\n" if field is struct.field_list[-1] else ", ")
            log += "\n" * 2
            logger.info(log)

        logger.debug("reference_dict: {0}".format(self.reference_dict))
        logger.debug("unresolved_ref_dict: {0}".format(self.unresolved_references_dict))
        logger.debug("single_occurrence_dict: {0}".format(self.single_occurrence_dict))

    def check_reference_status(self, table_obj, last_struct=""):
        """Takes a table object and can take the last struct which may occur by recursion. Computes all lines of
        the corresponding excel file inherent in the table and creates a hierarchical data structure from that
        information.

        :param Table table_obj: current table to work with
        :param Struct last_struct: provides last struct created
        """
        last_struct = last_struct if last_struct != "" else None

        # TODO: better comments; data types somehow without hardcoding?; centralize
        # three needed columns for categorization of lines
        data_element_col = table_obj.get_header_column("Data Element")
        reference_col = table_obj.get_header_column("Reference")
        data_type_col = table_obj.get_header_column("Data Type")

        # compute all rows in the provided table
        for row in table_obj.table.data_list:
            # get column data from current row
            data_element = row[data_element_col]
            data_type = row[data_type_col]
            reference = row[reference_col]
            # determine 'fingerprint' of this row: what kind of information is it?
            if data_type == data_type_struct:
                # is a struct; save latest in order to add related fields and references
                last_struct = Struct(table_obj.is_nvm,
                                     **dict(zip(map_header_fields(table_obj.header_leave_list), row)))
                table_obj.add_struct(last_struct)
                self.bookmark_as_reference(data_element, last_struct)
            elif reference == "":
                # is a simple field, just add to latest struct
                field_obj = Field(table_obj.is_nvm,
                                  **dict(zip(map_header_fields(table_obj.header_leave_list), row)))
                last_struct.add_field(field_obj)
            elif data_type == data_type_reference:
                # is a reference, add to latest struct and bookmark it as reference to be resolved
                field_obj = Field(table_obj.is_nvm,
                                  **dict(zip(map_header_fields(table_obj.header_leave_list), row)))
                last_struct.add_field(field_obj)
                self.bookmark_as_unresolved_reference("{0}.{1}".format(last_struct.data_element, reference), field_obj)
            else:
                # might be a field not related to some struct, so check if there is a struct and add it
                # otherwise add it as possibly referenced and as single occurring field
                field_obj = Field(table_obj.is_nvm,
                                  **dict(zip(map_header_fields(table_obj.header_leave_list), row)))
                if last_struct is None:
                    field_obj.set_context(self)
                    self.bookmark_as_reference(reference, field_obj)
                    self.bookmark_as_single_occurrence(reference, field_obj)
                else:
                    last_struct.add_field(field_obj)
                    self.bookmark_as_reference(reference, field_obj)

    def bookmark_as_reference(self, key, reference_object):
        """Save a reference object to respective dictionary for later easy retrieval.

        :param str key: key for reference object
        :param reference_object: the reference object itself
        :return: False if key already in dictionary, True otherwise
        :rtype Boolean
        """
        if key in self.reference_dict:
            return False
        else:
            self.reference_dict[key] = reference_object
            return True

    def bookmark_as_unresolved_reference(self, reference_key, referencing_object):
        """Save a 'link' to an yet unconfirmed reference object.

        :param str reference_key: key of referenced object
        :param referencing_object: the object referencing and reference object
        :return: False if key already in dictionary, True otherwise
        :rtype bool
        """
        referencing_list = self.unresolved_references_dict.setdefault(reference_key, [])
        if referencing_object not in referencing_list:
            referencing_list.append(referencing_object)
            return True
        else:
            return False

    def bookmark_as_single_occurrence(self, key, reference_object):
        """Save a reference object occurring once and/or outside a struct.

        :param key: key for reference object
        :param reference_object: the reference object itself
        :return: False if key already in dictionary, True otherwise
        :rtype bool
        """
        if key in self.single_occurrence_dict:
            return False
        else:
            self.single_occurrence_dict[key] = reference_object
            return True

    def resolve_references(self):
        """Try to resolve yet unconfirmed referencing from respective dictionary."""
        # iterate unresolved
        for key, value in self.unresolved_references_dict.items():
            reference = key.split(".")[1]
            # check if the inquired reference is available
            if reference not in self.reference_dict:
                self.unresolvable_references_dict[key] = value
                logger.info("not resolvable: {0} ({1}): {2}".format(key, key.split(".")[1], value))
            else:
                # multiple referring objects are possible, so set the link for all of them
                for obj in self.unresolved_references_dict[key]:
                    obj.reference_obj = self.reference_dict[reference]
        logger.info("unresolvable_ref_dict: {0}".format(self.unresolvable_references_dict))

        # filter unresolvable references which are allowed
        unresolvable_list = []
        for reference in self.unresolvable_references_dict.keys():
            if not ("SignalHeader_t" in reference or "AlgoInterfaceVersionNumber_t" in reference):
                unresolvable_list.append(reference)

        # still unresolvable reference(s) left so something has to be wrong
        if len(unresolvable_list) > 0:
            logger.error("Unresolvable reference(s) found: {0}".format(", ".join(unresolvable_list)))
            sys.exit(-1)

    def compose_output(self):
        """Simply applying method calls to generate the different parts of c code."""
        self.function_declarations = self.compose_function_declarations()
        self.function_main_calls = self.compose_main_calls()
        self.function_definitions = self.compose_function_definitions()

    def compose_function_declarations(self):
        """Compose all single occurrences and references (such as structs and definitions).

        :return list of declarations
        :rtype list(str)
        """
        log = "\nReferences:\n"
        for key, value in self.reference_dict.items():
            log += "{0} : {1}\n".format(key, value)
        log += "Count: {0}\n".format(len(self.reference_dict.items()))

        log += "\n\n\nSingle occurrences:\n"
        for key, value in self.single_occurrence_dict.items():
            log += "{0} : {1}\n".format(key, value)
        log += "Count: {0}\n".format(len(self.single_occurrence_dict.items()))

        logger.info(log)

        declarations = []
        # all references will have an function declaration, so collect them
        for sheet_obj in self.sheet_obj_list:
            declarations.extend(sheet_obj.get_declarations())

        # references occurring once need there own declaration since they are not contained in a struct and have to be
        # treated differently
        for _, field in self.single_occurrence_dict.items():
            declarations.extend(field.get_declaration())

        return declarations

    def compose_main_calls(self):
        """Compose main function calls for top level structures.

        :return functions calls for C main
        :rtype list(str)
        """
        # iterate just top level structs; maybe just low idea of using first struct in list per sheet
        function_main_call_template = "  {prefix}{sheet}(pProPorts->{field});\n"
        function_main_call_out = []
        # extract top level structs from sheets and add their call to the list
        for sheet_obj in self.sheet_obj_list:
            struct = sheet_obj.get_top_level_struct_obj()
            if struct is not None:
                field_name = sheet_obj.sheet.get_port_name()
                function_main_call_out.append(
                    function_main_call_template.format(prefix=struct.get_function_prefix(),
                                                       sheet=struct.get_clean_name(), field=field_name))
        return function_main_call_out

    def compose_function_definitions(self):
        """Compose all function definitions.

        :return function definitions
        :rtype list(str)
        """
        definitions = []
        # get definitions from all sheets
        for sheet_obj in self.sheet_obj_list:
            definitions.extend(sheet_obj.get_definitions())

        # get definitions of references occurring once
        for _, field in self.single_occurrence_dict.items():
            field_reference = field.get_reference()
            if field_reference:
                definitions.extend(field_reference.get_direct_output())

        return definitions

    def write_output(self):
        """Write the compositions to the respective output files using the provided marker lines."""
        contents, declaration_start, declaration_end, definition_start, definition_end, main_start, main_end = self.get_out_c_line_numbers()

        self.compose_output()

        # write out generated code to file
        try:
            # Remove write protection
            os.chmod(self.output_checks_file_name, stat.S_IWRITE)

            out_file = open(self.output_checks_file_name, "w")
        except IOError:
            logger.error("Could not open file '{0}'.".format(self.output_checks_file_name))
        else:
            out_file.writelines(contents[:declaration_start])
            out_file.writelines(self.function_declarations)
            out_file.writelines(contents[declaration_end - 1:main_start])
            out_file.writelines(self.function_main_calls)
            out_file.writelines(contents[main_end - 1:definition_start])
            out_file.writelines(self.function_definitions)
            out_file.writelines(contents[definition_end - 1:])
            out_file.close()

        # buffer variables for output
        warning_ids = []
        error_ids = []
        top_level_error_ids = []
        top_level_warnings_ids = []

        code_template = "  {0},{1}\n"

        # iterate sheets and collect errors and warnings which are used
        for sheet_obj in self.sheet_obj_list:
            for table_obj in sheet_obj.table_list:
                for struct_obj in table_obj.struct_list:
                    if struct_obj.error_code is not None:
                        error = struct_obj.get_error_code(True)
                        if struct_obj.is_top_level_struct:
                            top_level_error_ids.append(code_template.format(error[0], error[1]))
                        else:
                            error_ids.append(code_template.format(error[0], error[1]))
                    elif struct_obj.warning_code is not None:
                        warning = struct_obj.get_warning_code(True)
                        if struct_obj.is_top_level_struct:
                            top_level_warnings_ids.append(code_template.format(warning[0], warning[1]))
                        else:
                            warning_ids.append(code_template.format(warning[0], warning[1]))
                    for field_obj in struct_obj.field_list:
                        if field_obj.error_code is not None:
                            error = field_obj.get_error_code(True)
                            error_ids.append(code_template.format(error[0], error[1]))
                        elif field_obj.warning_code is not None:
                            warning = field_obj.get_warning_code(True)
                            warning_ids.append(code_template.format(warning[0], warning[1]))

        # TODO: integrate somehow in other loop?
        # iterate special case of references occurring once and add their errors and warnings, too
        for _, field in self.single_occurrence_dict.items():
            if field.error_code is not None:
                error = field.get_error_code(True)
                error_ids.append(code_template.format(error[0], error[1]))
            if field.warning_code is not None:
                warning = field.get_warning_code(True)
                warning_ids.append(code_template.format(warning[0], warning[1]))

        handler_contents, errors_start, errors_end, warnings_start, warnings_end = self.get_out_error_handling_line_numbers()

        # print("TL_ERRORS: \n\n{0}".format("".join(top_level_error_ids)))
        # print("ERRORS: \n{0}\n\n".format("".join(error_ids)))

        # print("TL_WARNINGS: \n\n{0}".format("".join(top_level_warnings_ids)))
        # print("WARNINGS: \n{0}\n\n".format("".join(warning_ids)))

        # Remove write protection
        os.chmod(self.error_handling_header, stat.S_IWRITE)

        # write error and warning enumerations to respective header file
        with open(self.error_handling_header, "w") as handler:
            handler.writelines(handler_contents[:errors_start])
            handler.writelines(top_level_error_ids)
            handler.write("\n")
            handler.writelines(error_ids)
            handler.writelines(handler_contents[errors_end - 1:warnings_start])
            handler.writelines(top_level_warnings_ids)
            handler.write("\n")
            handler.writelines(warning_ids)
            handler.writelines(handler_contents[warnings_end - 1:])

    def get_out_c_line_numbers(self):
        """Find the line numbers of markers in the output checks file in order to insert code.

        :return file contents and line marker positions
        :rtype (list(str), int, int, int, int, int, int)
        """
        # read in base file for C output
        contents = None
        try:
            out_file = open(self.output_checks_file_name, "r")
        except IOError:
            logger.error("Could not open file '{0}'.".format(self.output_checks_file_name))
        else:
            contents = out_file.readlines()
            out_file.close()

        # init vars for marker locations in input file definied through .INI file
        function_local_declarations_start = None
        function_local_declarations_end = None
        function_global_definitions_start = None
        function_global_definitions_end = None
        function_calls_main_start = None
        function_calls_main_end = None

        # determine index of markers in file where to insert generated code
        for i, line in enumerate(contents, 1):
            stripped_line = line.strip()
            if stripped_line == self.function_local_declaration_start:
                function_local_declarations_start = i
            elif stripped_line == self.function_local_declaration_end:
                function_local_declarations_end = i
            elif stripped_line == self.function_global_definition_start:
                function_global_definitions_start = i
            elif stripped_line == self.function_global_definition_end:
                function_global_definitions_end = i
            elif stripped_line == self.function_call_main_start:
                function_calls_main_start = i
            elif stripped_line == self.function_call_main_end:
                function_calls_main_end = i

        return contents, function_local_declarations_start, function_local_declarations_end, function_global_definitions_start, function_global_definitions_end, function_calls_main_start, function_calls_main_end

    def get_out_error_handling_line_numbers(self):
        """Find the line numbers of markers in the error handler file in order to insert code.

        :return file contents and line marker positions
        :rtype (list(str), int, int, int, int)
        """
        # read the whole existing error handling file to the memory; might not be the most elegant way of doing this but
        # is nice and simple
        handler_contents = None
        try:
            handler = open(self.error_handling_header, "r")
        except IOError:
            logger.error("Could not open file '{0}'.".format(self.error_handling_header))
        else:
            handler_contents = handler.readlines()
            handler.close()

        # init vars for marker locations
        errors_start = None
        errors_end = None
        warnings_start = None
        warnings_end = None

        # determine index for markers
        for i, line in enumerate(handler_contents, 1):
            stripped_line = line.strip()
            if stripped_line == self.error_enum_start:
                errors_start = i
            elif stripped_line == self.error_enum_end:
                errors_end = i
            elif stripped_line == self.warning_enum_start:
                warnings_start = i
            elif stripped_line == self.warning_enum_end:
                warnings_end = i

        return handler_contents, errors_start, errors_end, warnings_start, warnings_end


class Sheet:
    """Structure element class for storage of excel sheet information and hold its contents.

    :param sheet: sheet object to be wrapped
    :param excel_context: context containing e.g. xml configuration
    """

    def __init__(self, sheet, excel_context):
        self.name = sheet.name
        self.sheet = sheet
        self.excel_context = excel_context
        self.table_list = []
        self.port_name = sheet.get_port_name()
        self.port_list_name = sheet.get_port_list_name()

    def get_top_level_struct_obj(self):
        """just returns the first struct of the first table in this sheet"""
        # TODO: make robust, make checks
        if len(self.table_list) > 0 and len(self.table_list[0].struct_list) > 0:
            return self.table_list[0].struct_list[0]
        else:
            return None

    def get_declarations(self):
        """Collects and returns all declarations of the sheet's tables.

        :return: list of declarations
        :rtype list(str)
        """
        declarations = []
        for table in self.table_list:
            declarations.extend(table.get_declarations())
        return declarations

    def get_definitions(self):
        """Collects and returns all definitions of the sheet's tables.

        :return: list of definitions
        :rtype list(str)
        """
        definitions = []
        for table in self.table_list:
            definitions.extend(table.get_definitions())
        return definitions

    def add_table(self, table_obj):
        """Add a table to the sheet's table list. Adds the contexts of sheet and excel file.

        :param Table table_obj: table to be added
        """
        if table_obj not in self.table_list:
            self.table_list.append(table_obj)
            table_obj.set_context(self.excel_context, self)


class Table:
    """Structure element class for storage of partial excel sheet information.
    (Most of the time there will be just one table, so stores all information of the sheet)

    :param table: table object to be wrapped
    :param str sheet_name: name of the parent sheet
    """

    def __init__(self, table, sheet_name):
        self.table = table
        self.sheet_name = sheet_name
        # TODO: remove hardcoding
        self.is_nvm = bool(self.sheet_name.find("NVM") != -1)
        self.header_leave_dict = utree.get_leave_lambda_dict(table.header_tree,
                                                             lambda node: {node.title: node.get_relative_col()})
        self.header_leave_list = utree.get_leave_lambda(table.header_tree, lambda node: [node.title])
        # following two lines for lazy gaining of header mapping; TODO: make a utility function?
        # print(", ".join(["\"{0}\" : \"{1}\"".format(header.lower(), header.lower().replace(" ", "_").replace(".", "")) for header in self.header_leave_list]))
        # print("\n".join(["self.{0} = {0}".format(header.lower().replace(" ", "_").replace(".", "")) for header in self.header_leave_list]))
        self.struct_list = []

        self.excel_context = None
        self.sheet_context = None

    def get_header_column(self, header):
        """Get column for a header string.

        :return column
        :rtype int
        """
        return self.header_leave_dict.get(header)

    def get_declarations(self):
        """Collect and return all declarations in this table's scope.

        :return: list of declarations
        :rtype list(str)
        """
        declarations = []
        if len(self.struct_list) > 0:
            self.struct_list[0].is_top_level_struct = True
        for checked_struct in [struct for struct in self.struct_list if
                               struct == self.excel_context.reference_dict.get(struct.data_element)]:
            declarations.extend(checked_struct.get_declarations())
        return declarations

    def get_definitions(self):
        """Collect and return all declarations in this table's scope.

        :return: list of definitions
        :rtype list(str)
        """
        definitions = []
        for struct in self.struct_list:
            definitions.append(struct.get_definitions())
        return definitions

    def add_struct(self, struct_obj):
        """Add struct to list and add contexts.

        :param struct_obj: provided struct object
        :type struct_obj: Struct
        """
        struct_obj.set_context(self.excel_context, self.sheet_context)
        if struct_obj not in self.struct_list:
            self.struct_list.append(struct_obj)

    def set_context(self, excel_context, sheet_context=None):
        """Set contexts from excel file and excel sheet level.

        :param excel_context: excel file level context
        :param sheet_context: excel sheet level context
        """
        self.excel_context = excel_context
        self.sheet_context = sheet_context


class Row(object):
    """Base class of a row representing a line in Excel. Below actually almost only all column header from Excel.

    :param bool is_nvm: a check if belongs to NVM
    :param str data_element: data element from Excel
    :param str description: description from Excel
    :param str reference: reference from Excel
    :param str data_type: data type from Excel
    :param str array_size: array size from Excel
    :param str typ_resolution: typ resolution from Excel
    :param str physical_unit: physical unit from Excel
    :param str typ_range: typ range from Excel
    :param str fs_range: fs range from Excel
    :param str fs_ussed_array_size: fs ussed array size from Excel
    :param str fs_rel_gradient_rangeper_sec_in_per: fs rel gradient rangeper sec in percent from Excel
    :param str fs_abs_gradient_rangeper_sec: fs abs gradient rangeper sec from Excel
    :param str fs_comment: fs comment from Excel
    :param str plausibility_checks: plausibility checks from Excel
    :param str default_value: default value from Excel
    :param str output_check_fallback_value: output check fallback value from Excel
    :param str mts_name: mts name from Excel
    :param str virtual_address: virtual adress from Excel
    :param str cycleid: cycleid from Excel
    :param str projects: projects from Excel
    :param str generic_interface: generic interface from Excel
    :param str remark: remark from Excel
    """

    # TODO: naming and self updating script?

    def __init__(self, is_nvm, data_element, description, reference, data_type, array_size, typ_resolution,
                 physical_unit, typ_range, fs_range, fs_ussed_array_size,
                 fs_rel_gradient_rangeper_sec_in_per, fs_abs_gradient_rangeper_sec, fs_comment, plausibility_checks,
                 default_value, output_check_fallback_value,
                 mts_name, virtual_address, cycleid, projects, generic_interface, remark):
        # standard fields from Excel with one to one naming
        self.data_element = data_element
        self.description = description
        self.reference = reference
        self.data_type = data_type
        self.array_size = array_size
        self.typ_resolution = typ_resolution
        self.physical_unit = physical_unit
        self.typ_range = typ_range
        self.fs_range = fs_range
        self.fs_ussed_array_size = fs_ussed_array_size
        self.fs_rel_gradient_rangeper_sec_in_per = fs_rel_gradient_rangeper_sec_in_per
        self.fs_abs_gradient_rangeper_sec = fs_abs_gradient_rangeper_sec
        self.fs_comment = fs_comment
        self.plausibility_checks = plausibility_checks
        self.default_value = default_value
        self.output_check_fallback_value = output_check_fallback_value
        self.mts_name = mts_name
        self.virtual_address = virtual_address
        self.cycleid = cycleid
        self.projects = projects
        self.generic_interface = generic_interface
        self.remark = remark

        # special purpose fields; providing configuration levels from XML as contexts
        self.pointer = None
        self.excel_context = None
        self.sheet_context = None
        self.is_nvm = is_nvm
        self.function_declaration = None
        self.is_top_level_struct = False

        # fields for error and warning generation including documentation an the line end
        self.error_code = None
        self.warning_code = None
        self.status_code_base = None
        self.parent_error_id = None
        self.parent_reference_name = None

        # removes unneeded parts of strings
        self.clean_name = None
        self.clean_reference = None

    def get_pointer(self):
        """Returns a row objects clean name with first letter uppercase.

        :return: cleaned data element
        :rtype str
        """
        if self.pointer is None:
            self.pointer = self.get_clean_name()[0].upper() + self.get_clean_name()[1:]
        return self.pointer

    def get_clean_name(self):
        """Returns a row objects data element field cleaned with regex to be shortened.

        :return: cleaned data element
        :rtype str
        """
        if self.clean_name is None:
            self.clean_name = re.sub(self.excel_context.name_clearing_regex, "", self.data_element)
        return self.clean_name

    def get_clean_reference(self):
        """Returns a row objects reference field cleaned with regex to be shortened.

        :return: cleaned reference
        :rtype str
        """
        if self.clean_reference is None:
            self.clean_reference = re.sub(self.excel_context.name_clearing_regex, "", self.reference)
        return self.clean_reference

    def set_context(self, excel_context, sheet_context=None):
        """Set contexts from excel file and excel sheet level.

        :param excel_context: excel file level context
        :param sheet_context: excel sheet level context
        """
        self.excel_context = excel_context
        self.sheet_context = sheet_context

    def get_status_code_base(self):
        """Returns basic status code string without any prefix.

        :return basic status code
        :rtype str
        """
        if self.status_code_base is None:
            self.status_code_base = "{parent}{error_id}".format(
                parent=self.parent_error_id + "_" if self.parent_error_id else "",
                error_id=self.get_clean_name()).upper()

        return self.status_code_base

    def get_error_code(self, print_=False):
        """Returns either the error code for a Row object or a 2-tuple of the error code and the documentation
        for the latter.

        :param bool print_: indicate usage for error handling header
        :return: error code (+ documentation)
        :rtype str or (str, str)
        """
        if not self.error_code:
            self.error_code = self.excel_context.error_code_prefix + self.get_status_code_base()

        if print_:
            return self.error_code, self.get_error_documentation()
        else:
            return self.error_code

    def get_warning_code(self, print_=False):
        """Returns either the warning code for a Row object or a 2-tuple of the warning code and the documentation
        for the latter.

        :param bool print_: indicate usage for error handling header
        :return: warning code (+ documentation)
        :rtype str or (str, str)
        """
        if not self.warning_code:
            self.warning_code = self.excel_context.warning_code_prefix + self.get_status_code_base()

        if print_:
            return self.warning_code, self.get_warning_documentation()
        else:
            return self.warning_code

    def get_doxygen(self, brief=None, pre=None, post=None, param=None, param_description=None, ret=None, globals_=None,
                    in_out_cor=None,
                    callseq=None, testmthd=None, traceab=None):
        """Creates and returns a doxygen header as formatted string.

        :return doxygen header
        :rtype str
        """
        # special defaults as strings; should not be default in function params because is mutable
        brief = brief if brief else ""
        pre = pre if pre else "None"
        param = param if param else "None"
        ret = ret if ret else "void"
        globals_ = globals_ if globals_ else "None"
        in_out_cor = in_out_cor if in_out_cor else ""
        callseq = callseq if callseq else ""
        testmthd = testmthd if testmthd else ""
        traceab = traceab if traceab else ""

        return get_doxygen(brief, pre, post, "{0}    {1}".format(param, param_description), ret, globals_, in_out_cor,
                           callseq, testmthd, traceab,
                           self.excel_context.doxygen_line_border,
                           self.excel_context.doxygen_line_start)

    def get_base_documentation(self, line_length, bit_type, reference, port_list, port):
        """Returns formatted base doc line for error/warning codes respecting content already provided for this line.

        :param int line_length: length of content for that line
        :param str bit_type: error or warning bit
        :param str reference:
        :param str port:
        :return: docstring
        :rtype str
        """
        if not reference:
          return "{distance}///< {type} bit is set in case {ref} is out of defined range as defined " \
                 "in column <tt>Type Range</tt> in sheet LsdTypes in [{excel}]" \
                 "({excel_http_path})".format(distance=" " * (self.excel_context.doxy_comment_start_column - line_length),
                                              type=bit_type, ref=self.data_element,
                                              excel=self.excel_context.excel_file_name,
                                              excel_http_path=self.excel_context.excel_http_path)
        else:
          return "{distance}///< {type} bit is set in case \\ref {ref} of provide port \\ref {port_list}::{port} is " \
                 "out of defined range as defined in column <tt>Type Range</tt> in [{excel}]" \
                 "({excel_http_path})".format(distance=" " * (self.excel_context.doxy_comment_start_column - line_length),
                                              type=bit_type, ref=reference,
                                              port_list=port_list, port=port,
                                              excel=self.excel_context.excel_file_name,
                                              excel_http_path=self.excel_context.excel_http_path)

    def get_top_level_struct_base_documentation(self, line_length, bit_type):
        """Returns formatted base doc line for error/warning codes respecting content already provided for this line.

        :param int line_length: length of content for that line
        :param str bit_type: error or warning bit
        :return: docstring
        :rtype str
        """
        return "{distance}///< {type} bit is set if any of below defined {type_low} messages were set.".format(
            distance=" " * (self.excel_context.doxy_comment_start_column - line_length), type=bit_type, type_low=bit_type.lower())

    def get_error_documentation(self):
        """Is overridden in child classes. Just here as reminder.

        :raises NotImplementedError
        """
        raise NotImplementedError

    def get_warning_documentation(self):
        """Is overridden in child classes. Just here as reminder.

        :raises NotImplementedError
        """
        raise NotImplementedError


class Struct(Row):
    """Class representing c code struct.

    :param bool is_nvm: if is part of NVM
    :param dict header_value_dict: contains all parameters as key-value-pairs
    """

    def __init__(self, is_nvm, **header_value_dict):
        super(Struct, self).__init__(is_nvm, **header_value_dict)
        self.field_list = []
        self.reference_field_list = []
        self.has_iterable = False  # means if c struct has a list/array

        self.prefix = None

        self.function_definition = Function()
        self.output_composer = OutputBlockComposer()

    def add_field(self, field_obj):
        """Adds a field object to field list.

        :param field_obj: a field object
        :type field_obj: Field
        """
        if field_obj not in self.field_list:
            self.field_list.append(field_obj)
            self.has_iterable = self.has_iterable or bool(field_obj.array_size)
            field_obj.set_context(self.excel_context, self.sheet_context)
            field_obj.set_parent(self)

    def get_declarations(self):
        """Returns the declarations of the output check of the given struct and its related fields provided there is
        need to have a function.

        :return: list of declarations
        :rtype list(str)
        """

        logger.info("{0}: {1}".format(self.data_element, [field.data_element for field in self.field_list]))

        declarations = []
        if self.excel_context.reference_dict.get(self.data_element):
            self.function_declaration = self.excel_context.function_declaration_template.format(
                prefix=self.get_function_prefix(),
                fn_name=self.get_clean_name(),
                class_name=self.data_element,
                class_suffix="_t",
                field_name=self.get_pointer())
            declarations.append(self.function_declaration + ";\n")

        # add function declaration if field was referenced
        for field in self.field_list:
            if field == self.excel_context.reference_dict.get(field.reference) and not (field.high_bit is not None and field.high_bit == 255): # workaround for fully utilized 8-bit bit fields
                # also add to list for later composition of function definitions
                self.reference_field_list.append(field)
                declarations.append(field.get_declaration())

        return declarations

    def get_definitions(self):
        """Returns the definitions of the output check of the given struct and its related fields.

        :return: definitions of struct
        :rtype str
        """
        # TODO: (consistency) make same approach (list or string) for defs and decls?
        self.function_definition.set_function_name(self.get_clean_name())
        self.function_definition.add_function_prefix(self.get_function_prefix())
        self.function_definition.add_function_parameter(
            "{class_name}{class_suffix}* const p{field_name}".format(class_name=self.data_element, class_suffix="_t",
                                                                      field_name=self.get_pointer()))
        self.function_definition.add_preamble(
            self.get_doxygen(brief=self.description, pre=None,
                             post="In case of a failed check corresponding error or warning is set.",
                             param="p{field_name}".format(field_name=self.get_pointer()),
                             param_description="Field under test.",
                             ret="void", globals_=None,
                             in_out_cor="Check output ranges and set appropriate error or warning bit respectively "
                                        " if a value is out of range. Value also is set to fallback if provided.",
                             callseq=None, testmthd=None, traceab=None))

        # if there is an iterable, add an iteration variable declaration
        if self.has_iterable:
            self.function_definition.add_main_body("uint32 i;")

        if self.is_top_level_struct:
            type_name = "Warning" if self.is_nvm else "Error"
            checker_function = self.excel_context.get_error_or_warning_number.format(type_name)
            checker_variable = "num{0}s".format(type_name)
            self.function_definition.add_main_body(
                "const uint8 {var} = {fn};".format(var=checker_variable, fn=checker_function))

            # Is a reaction on errors/warnings needed?
            inner_if_clause = IfThenElse("{fn} != {var}".format(fn=checker_function, var=checker_variable))
            if self.is_nvm:
                outer_if_clause = IfThenElse("p{pointer} != NULL".format(pointer=self.get_pointer()),
                                             [field.get_definition() for field in self.field_list if
                                              field.get_definition()])
                outer_if_clause.add_preamble(
                    "/* Pointer could be set to NULL in case of error to prevent overwriting of nvm struct */")
                action = [self.excel_context.set_warning_function_template.format(self.get_warning_code())]
                inner_if_clause.add_main_body(action)
                outer_if_clause.add_main_body(inner_if_clause)
                self.function_definition.add_lower_body(outer_if_clause)
            else:
                # TODO: wrong data element for pointer?
                action = ["p{struct}->sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;".format(struct=self.get_pointer()),
                          self.excel_context.set_error_function_template.format(self.get_error_code())]
                inner_if_clause.add_main_body(action)
                self.function_definition.add_lower_body(inner_if_clause)

        # if is NVM and a top level function
        if not (self.is_nvm and self.is_top_level_struct):
            for field in self.field_list:
                # add non-empty definitions from fields to function body
                if field.get_definition():
                    self.function_definition.add_main_body(field.get_definition())

        # add function block to output composer
        self.output_composer.add_block(self.function_definition)

        # TODO: make block class construct here, too?
        # append earlier declared referenced fields determining they need a function definition
        for field in self.reference_field_list:
            if field.get_definition():
                # add field reference to output composer if it is defined
                field_reference = field.get_reference()
                if field_reference:
                    self.output_composer.add_block(field_reference)
        return self.output_composer.get_output()

    def get_function_prefix(self):
        """Returns the prefix from context.

        :return: function prefix
        :rtype str
        """
        if self.prefix is None:
            self.prefix = self.excel_context.function_name_prefix + self.excel_context.function_name_infix if self.is_top_level_struct else self.excel_context.function_name_prefix
        return self.prefix

    def get_error_documentation(self):
        """Returns top level struct error code documentation.

        :return: top level error code doc
        :rtype str
        """
        distance = len(self.get_error_code())
        if self.is_top_level_struct:
            return self.get_top_level_struct_base_documentation(distance, "Error")

    def get_warning_documentation(self):
        """Returns top level struct warning code documentation.

        :return: top level warning code doc
        :rtype str
        """
        distance = len(self.get_warning_code())
        if self.is_top_level_struct:
            return self.get_top_level_struct_base_documentation(distance, "Warning")


class Field(Row):
    """Class representing either a field of a struct or a lower level function definition.

    :param bool is_nvm: if is part of NVM
    :param header_value_dict: contains all parameters as key-value-pairs
    """

    def __init__(self, is_nvm, **header_value_dict):
        super(Field, self).__init__(is_nvm, **header_value_dict)

        # TODO: adapt line below to be like the later two method calls?
        self.data_type_extension = self.resolve_data_type_extension()
        self.bounds_list = []
        self.lower_bound = None
        self.upper_bound = None
        self.second_upper_bound = None
        self.lower_fallback = None
        self.upper_fallback = None
        self.parent = None
        self.enum_fields = []
        self.high_bit = None

        self.resolve_bounds()
        self.resolve_fallback_values()
        self.resolve_enum_values()

    def resolve_data_type_extension(self):
        """Method to determine the extension to be printed for the data type.
        (in c code, 'f' for float or 'u' unsigned int)

        :return: data type extension
        :rtype str
        """
        regex_search = regex_int.search(self.data_type)
        if regex_search and regex_search is not None:
            if regex_search.group(1) and regex_search.group(1) is not None:
                return "u"
            else:
                return ""
        else:
            regex_search = regex_float.search(self.data_type)
            if regex_search and regex_search is not None:
                return "f"
        return ""

    def resolve_bounds(self):
        """Resolves the upper and lower bounds of a range."""
        if self.typ_range is not None:
            for line in self.typ_range.splitlines():
                if line and line is not None:
                    self.bounds_list.append(self.resolve_numbers(line.strip()))
            line_count = len(self.bounds_list)
            if line_count > 0:
                self.lower_bound = self.bounds_list[0]
                if line_count > 1:
                    self.upper_bound = self.bounds_list[1]
                    if line_count > 2:
                        # TODO: remove hardcoding
                        self.second_upper_bound = "UI8_T_MAX" if self.bounds_list[2].lower() == "0xFF".lower() else \
                            self.bounds_list[2]

    def resolve_enum_values(self):
        """Resolves enum values."""
        # check data type of this field object
        # TODO: remove hardcoding here
        if self.data_type == data_type_reference and self.reference == "AlgoInterfaceVersionNumber_t":
            self.enum_fields.append(self.EnumField(self.typ_range.strip()))
        elif self.data_type == data_type_enum:
            for line in self.typ_range.splitlines():
                # assuming hexadecimals were set in Excel for continuous bitfields and checking for them
                regex_search = regex_hexnum.search(line.strip())
                if regex_search is not None and self.high_bit is None:
                    # group 3 of this regex is e.g. (0x)(0...00)(80) -> (80); -1 index to get last item (highest
                    # value); full set bitfield would be high bit shifted by one, means multiplied by 2
                    hex_number = regex_hexnum.search(self.typ_range.splitlines()[-1]).group(3)
                    self.high_bit = int(str(hex((int(hex_number[0]) * 2))) + hex_number[1:], 16) - 1
                else:
                    regex_search = regex_enum.search(line.strip())
                    if regex_search is not None and regex_search != "":
                        self.enum_fields.append(self.EnumField(regex_search.group(0)))

    def resolve_fallback_values(self):
        """Resolves fallback values."""
        # TODO: remove hardcoding
        if self.output_check_fallback_value and self.output_check_fallback_value != "-":
            for line_count, line in enumerate(self.output_check_fallback_value.splitlines()):
                if line and line is not None:
                    if line_count == 0:
                        self.lower_fallback = self.resolve_numbers(line.strip())
                    if line_count == 1:
                        self.upper_fallback = self.resolve_numbers(line.strip())

    def resolve_numbers(self, value):
        """Resolves strings to numbers or constants. Numbers get a data type extension if it was missing.

        :param str value: value to be resolved to a number
        :return: resolved value
        :rtype: str
        """
        # encode in utf-8 because python might complain about chars not being ascii
        value = value.encode('utf-8')

        # taking enum regex in order to look for enum values; for now, juts return the whole string if matched
        # assuming enums to not start with numbers
        enum_search = regex_enum.match(value)
        if enum_search is not None:
            out = ""
            if enum_search.group(1):
                out += enum_search.group(1)
            if enum_search.group(2):
                out += enum_search.group(2)
                if enum_search.group(3):
                    out += enum_search.group(3)
                return out

        # looking for hexadecimal values
        hex_search = regex_hexnum.search(value)
        if hex_search is not None:
            if hex_search.group(1):
                out = hex_search.group(1)
                if hex_search.group(2):
                    out += hex_search.group(2)
                if hex_search.group(3):
                    out += hex_search.group(3)
                return out

        # looking for decimal values
        dec_search = regex_decnum.search(value)
        if dec_search is not None:
            # TODO: remove hardcoding
            if re.search("_MAX", value) or re.search("MFC_REDUCED_ROI_", value):
                # This macro shouldn't be truncated
                return value
            out = dec_search.group(1)
            if self.data_type_extension == "f":
                if dec_search.group(2) is not None:
                    out += dec_search.group(2)
                    if dec_search.group(3) is not None:
                        out += dec_search.group(3)
                    if dec_search.group(4) is not None:
                        out += dec_search.group(4)
                    else:
                        out += self.data_type_extension
                else:
                    out += ".0{ext}".format(ext=self.data_type_extension)
            elif self.data_type_extension == "u":
                if dec_search.group(3) is not None:
                    out += dec_search.group(3)
                if dec_search.group(4) is not None:
                    out += dec_search.group(4)
                else:
                    out += self.data_type_extension
            return out
        else:
            # at last if nothing is found just return the raw value
            return value

    def check_fallback(self, field):
        """Checks the fallback of a field.

        :param str field: field to check
        :return: fallback action
        :rtype str
        """
        # TODO: review code, improve and integrate + fill docu
        # TODO: maybe rename method because more than just fallback; defaults, too
        # TODO: remove hardcoding
        # Hack for enums that are referenced on other sheets. Currently, lower_fallback is not available.
        if self.lower_fallback is None and self.data_type == data_type_enum:
            self.lower_fallback = "0u"

        if self.lower_fallback is not None:
            if self.upper_fallback is not None:
                if self.lower_bound == "0u":
                    return ["{field} = {bound};".format(field=field, bound=self.upper_fallback),
                            self.excel_context.set_warning_function_template.format(self.get_warning_code())]
                fallback = "CML_{type}MinMax({min}, {max}, {field})".format(field=field, type="f_" if (
                    self.data_type_extension == "f") else "", min="CML_Deg2Rad({degree_value})".format(
                    degree_value=self.lower_fallback) if (self.physical_unit == "rad") else self.lower_fallback,
                                                                            max="CML_Deg2Rad({degree_value})".format(
                                                                                degree_value=self.upper_fallback) if (
                                                                                self.physical_unit == "rad") else self.upper_fallback)
                return ["{field} = {fallback};".format(field=field, fallback=fallback),
                        self.excel_context.set_warning_function_template.format(self.get_warning_code())]
            else:
                return ["{field} = {bound};".format(field=field,
                                                    bound=self.lower_fallback),
                        self.excel_context.set_warning_function_template.format(self.get_warning_code())]
        # Default case
        return [self.excel_context.set_error_function_template.format(
            self.get_error_code())]  # TODO: so Zeugs auch generischer machen und auslagern?

    def set_parent(self, parent):
        """Set parent of this field.

        :param parent:  parent object
        :type parent: Struct
        """
        self.parent = parent
        self.parent_error_id = self.parent.get_clean_name() if (
            self.parent.reference is None or not self.parent.reference) else self.parent.get_clean_reference()

    def get_declaration(self):
        """Returns the function declaration for this field.

        :return: function declaration
        :rtype str
        """
        # TODO: remove hardcoding
        self.function_declaration = self.excel_context.function_declaration_template.format(
            prefix=self.excel_context.function_name_prefix,
            fn_name=self.get_clean_reference(),
            class_name=self.reference,
            class_suffix="",
            field_name=self.get_pointer())
        return self.function_declaration + ";\n"

    def get_definition(self):
        """Returns the definition for this field.

        :return: definition content
        :rtype BaseBlock, str or None
        """
        # TODO: method for standard printing of c code (definition part, e.g.)
        for_loop = None
        if self.data_type == data_type_reference and self.reference == "AlgoInterfaceVersionNumber_t":
            return None

        # Hack for 8-bit bit-fields that are fully set
        if self.high_bit is not None and self.high_bit == 255:
            return "/* No need to check bit field {bitField} as its value can be of whole range. */".format(bitField=self.data_element)

        ind = 0
        # TODO: introduce boolean for array_size?
        if self.array_size != "" and self.array_size is not None:
            for_loop = ForLoop(end_value=self.array_size, start_value="0u", index_var="i", equality="<", down=False)
            ind = 1

        # check data type of this field object
        field = "p{parent}->{field}".format(parent=self.parent.get_pointer(), field=self.get_clean_name())

        if self.data_type == data_type_reference:
            enhanced_field = "&({field}{index})".format(field=field, index="" if (ind == 0) else "[i]")
            value = "{fn_name_prefix}{ref}({enhanced_field});".format(
                fn_name_prefix=self.excel_context.function_name_prefix,
                ref=self.reference if self.reference == "SignalHeader_t" else self.get_clean_reference(),
                enhanced_field=enhanced_field)
            if for_loop:
                for_loop.add_main_body(value)
                return for_loop
            return value
        elif self.data_type == data_type_enum:
            enhanced_field = "{ref_begin}{field}{index}{ref_end}".format(
                ref_begin="&(" if self.lower_fallback or self.is_nvm else "", field=field,
                index="" if (ind == 0) else "[i]",
                ref_end=")" if self.lower_fallback or self.is_nvm else "")
            value = "{fn_name_prefix}{ref}({enhanced_field});".format(
                fn_name_prefix=self.excel_context.function_name_prefix,
                ref=self.get_clean_reference(),
                enhanced_field=enhanced_field)
            if for_loop:
                for_loop.add_main_body(value)
                return for_loop
            return value
        else:
            if self.lower_bound and self.upper_bound:
                value = "{field}{index}".format(field=field, index="" if (ind == 0) else "[i]")
                bound_degree = "CML_Deg2Rad({deg_value})"
                min_value = bound_degree.format(deg_value=self.lower_bound) if (
                    self.physical_unit == "rad") else self.lower_bound
                max_value = bound_degree.format(deg_value=self.upper_bound) if (
                    self.physical_unit == "rad") else self.upper_bound
                numeric_type = "f_" if (self.data_type_extension == "f") else ""
                value_checks = []
                if self.lower_bound == "0u":
                    """TODO: make some 'better' way of filtering such things from the output"""
                    # TODO: UI8_T_MAX as extra function to filter and add more?
                    value_checks.append("{value} > {max}".format(value=value, max=max_value))
                    if self.second_upper_bound is not None:
                        max_value_second = bound_degree.format(deg_value=self.second_upper_bound) if (
                            self.physical_unit == "rad") else self.second_upper_bound
                        value_checks.append("{value} < {second}".format(value=value, second=max_value_second))
                    if (self.data_type == data_type_uint8 and self.upper_bound == "UI8_T_MAX") or \
                            (self.data_type == data_type_uint16 and self.upper_bound == "UI16_T_MAX"):
                        return None
                else:
                    value_checks.append(
                        "(boolean)CML_{type}IsInRange({min}, {max}, {value}) == b_FALSE".format(min=min_value, max=max_value,
                                                                                                type=numeric_type,
                                                                                                value=value))

                if_clause = IfThenElse(value_checks, self.check_fallback(value))
                if for_loop:
                    for_loop.add_main_body(if_clause)
                    return for_loop
                else:
                    return if_clause
        return None

    def get_reference(self):
        """Returns definition of reference.

        :return: reference definition
        :rtype Function
        """
        # print doxygen, field functions and switch/cases
        reference_function = Function()
        reference_function.add_function_prefix(self.excel_context.function_name_prefix)
        reference_function.set_function_name(self.get_clean_reference())
        reference_function.add_function_parameter(
            "{class_name}{class_suffix}* const p{field}".format(class_name=self.reference, class_suffix="",
                                                                 field=self.get_pointer()))
        reference_function.add_preamble(
            self.get_doxygen(brief=self.description, pre=None,
                             post="In case of a failed check corresponding error or warning is set.",
                             param="p{field_name}".format(field_name=self.get_pointer()),
                             param_description="Field (type: {ref}) under test.".format(
                                 ref=self.reference),
                             ret="void", globals_=None,
                             in_out_cor="Check output ranges and set appropriate error or warning bit respectively "
                                        " if a value is out of range. Value also is set to fallback if provided.",
                             callseq=None, testmthd=None, traceab=None))

        # init just for convenience
        if_clause = None
        switch_case = None
        # TODO: change pointer method?
        value = "*p" + self.get_pointer()

        if self.high_bit is not None:
            # TODO: make general approach
            # Hack for 8-bit bit-fields that are fully set
            if self.high_bit == 255:
                return None
            check = "{value} > {high_bit}u".format(value=value, high_bit=self.high_bit)

            if_clause = IfThenElse(check, self.check_fallback(value))
        else:
            switch_case = SwitchCase(value, self.reference, self.enum_fields, self.check_fallback(value))

        reference_function.add_main_body(if_clause if if_clause else switch_case)
        return reference_function

    def get_error_documentation(self):
        """Returns error code documentation for this field.

        :return: error code documentation
        :rtype str
        """
        # TODO: remove hardcoding?
        distance = len(self.get_error_code())
        return self.get_base_documentation(distance, "Error",
                                           "{struct}_t::{field}".format(struct=self.parent.data_element,
                                                                        field=self.data_element) if self.parent else "",
                                           self.sheet_context.port_list_name if self.sheet_context else "",
                                           self.sheet_context.port_name if self.sheet_context else "")

    def get_warning_documentation(self):
        """Returns warning code documentation for this field.

        :return: warning code documentation
        :rtype str
        """
        # TODO: remove hardcoding?
        distance = len(self.get_warning_code())
        return self.get_base_documentation(distance, "Warning",
                                           "{struct}_t::{field}".format(struct=self.parent.data_element,
                                                                        field=self.data_element) if self.parent else "",
                                           self.sheet_context.port_list_name if self.sheet_context else "",
                                           self.sheet_context.port_name if self.sheet_context else "")

    class EnumField:
        """Internal class for structured printing of enum fields respectively one line of a enum type's
        type.range field in excel.

        :param str identifier: enum name
        """

        def __init__(self, identifier):
            self.identifier = identifier

        def __str__(self):
            """Return string representation.

            :return: identifier
            :rtype str
            """
            return self.identifier


def init_logger():
    """Simple initialization of a global logger."""
    # set up logging
    global logger
    logger = logging.getLogger(__name__)
    logger.setLevel(logging.DEBUG)
    # avoid multiple handlers respectively logs
    if not len(logger.handlers):
        handler = logging.FileHandler("{0}.log".format(__file__.split(".")[0]), mode="w")
        handler.setLevel(logging.DEBUG)
        formatter = logging.Formatter("(l.%(lineno)d) - %(levelname)s - %(message)s")
        handler.setFormatter(formatter)
        logger.addHandler(handler)
        logger.info("Logger initialized.")
    else:
        logger.info("Logger reused.")


def map_header_fields(header_fields):
    """Map header fields from excel to header fields usable in code like keys for dicts.
    (e.g. because of inconvenient spaces or characters)

    :param header_fields: list of header fields
    :return: list of corrected header field names
    :rtype list(str)
    """
    mapping_list = []
    for field in header_fields:
        lower_case_field = field.lower()
        if lower_case_field in header_mapping_dict:
            mapping_list.append(header_mapping_dict[lower_case_field])
        else:
            logger.error("Could not map header field: {0}".format(field))
    return mapping_list


if __name__ == "__main__":
    main()
