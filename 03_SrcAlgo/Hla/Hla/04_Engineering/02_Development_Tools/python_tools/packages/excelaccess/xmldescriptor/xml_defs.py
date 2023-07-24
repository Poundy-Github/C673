"""
@author: uidq3472
"""

""" Just for defining xml tags and attribute stuff. """

""" xml tags """

xml_root_tag = "excel_file"
root_configuration_tag = "excel_config"
sheet_tag = "excel_sheet"
sheet_configuration_tag = "sheet_config"
table_tag = "table"
table_configuration_tag = "table_config"
header_tag = "header"
header_configuration_tag = "header_config"
header_field_tag = "header_field"
header_field_configuration_tag = "header_field_config"

""" xml tag attributes """

# root attrs
excel_path_attr = "file_path"

# root config attrs
## general
root_configuration_dump_path = "dump_path"

general_config_attributes = [root_configuration_dump_path]

## output checks attributes
### naming convention
function_name_prefix = "fn_name_prefix"
function_name_infix = "fn_name_infix"
error_code_prefix = "error_code_prefix"
warning_code_prefix = "warning_code_prefix"

### output formatting
indentation_baseline = "indention_baseline"
indentation_step = "indention_step"
doxygen_line_length = "doxygen_line_length"
doxygen_line_start = "doxygen_line_start"

### marker
function_local_declaration_start = "fn_loc_decl_start"
function_local_declaration_end = "fn_loc_decl_end"
function_global_definition_start = "fn_glob_def_start"
function_global_definition_end = "fn_glob_def_end"
function_call_main_start = "fn_call_main_start"
function_call_main_end = "fn_call_main_end"
error_enum_start = "error_enum_start"
error_enum_end = "error_enum_end"
warning_enum_start = "warning_enum_start"
warning_enum_end = "warning_enum_end"
error_draw_start = "error_draw_start"
error_draw_end = "error_draw_end"
warning_draw_start = "warning_draw_start"
warning_draw_end = "warning_draw_end"

### I/O options
error_handling_header = "error_handling_header"
template_name = "template_name"
output_file_name = "output_file_name"
visu_error = "visu_error"

output_checks_config_attributes = [function_name_prefix, function_name_infix, error_code_prefix, warning_code_prefix, indentation_baseline,
                                   indentation_step, doxygen_line_length, doxygen_line_start,
                                   function_local_declaration_start, function_local_declaration_end, function_global_definition_start, function_global_definition_end,
                                   function_call_main_start, function_call_main_end, error_enum_start, error_enum_end,
                                   warning_enum_start, warning_enum_end, error_draw_start,
                                   error_draw_end, warning_draw_start, warning_draw_end, error_handling_header,
                                   template_name, output_file_name, visu_error]

# sheet attributes
sheet_name_attr = "sheet_name"

# sheet config attributes
sheet_port_attr = "port_name"

# table attributes
table_start_attr = "table_start"
table_end_attr = "table_end"
header_rows_attr = "header_rows"

# header attributes
header_field_title = "header_title"

""" xml tag attribute lists (ordering attrs) """

xml_root_attributes = [excel_path_attr]
root_config_attributes = general_config_attributes.extend(output_checks_config_attributes)
sheet_attributes = [sheet_name_attr]
sheet_configuration_attributes = [sheet_port_attr]
table_attributes = [table_start_attr, table_end_attr, header_rows_attr]
header_attributes = [""]
header_field_attributes = [header_field_title]
