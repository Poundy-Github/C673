# generateEnumHashCfg.py:
#-------------------------
#
# This python script is intended to define component specific variables that are used 
# in generateEnumHash.py

ERROR_HANDLING_HEADER_FILE = '../../../01_Source_Code/HLA/hla_errorhandling.h'
PATH_VIS_ERROR_CPP = "../hla_sim/sim_swc_hla/sim_hla_visu/sim_hla_visu_error.cpp"

ENUM_ERROR       = 'e_ErrorHandling_Errors'
ENUM_WARNING     = 'e_ErrorHandling_Warnings'
ENUM_INFORMATION = 'e_ErrorHandling_Information'

ENUM_PREFIX_ERROR       = 'HLA_ERROR_'
ENUM_PREFIX_WARNING     = 'HLA_WARNING_'
ENUM_PREFIX_INFORMATION = 'HLA_INFORMATION_'

HASH_NAME_PREFIX      = 'HLA_ERROR_HASH_'
HASH_NAME_ERROR       = HASH_NAME_PREFIX + 'ERRORS'
HASH_NAME_WARNING     = HASH_NAME_PREFIX + 'WARNINGS'
HASH_NAME_INFORMATION = HASH_NAME_PREFIX + 'INFORMATION'

# markers in PATH_VIS_ERROR_CPP
DELIMITER_ERROR_START   = '/* ### START_GENERATED_ERRORS ### */'
DELIMITER_ERROR_END     = '/* ### END_GENERATED_ERRORS ### */'
DELIMITER_WARNING_START = '/* ### START_GENERATED_WARNINGS ### */'
DELIMITER_WARNING_END   = '/* ### END_GENERATED_WARNINGS ### */'
DELIMITER_INFO_START    = '/* ### START_GENERATED_INFOS ### */'
DELIMITER_INFO_END      = '/* ### END_GENERATED_INFOS ### */'
