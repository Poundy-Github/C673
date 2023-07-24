def compiler_cmd_arm_none_eabi_gcc(target, config_pkg_compiler_file):
    if target == 'sbl' or target == 'sbl_loop' or target == 'presbl':
        return '${TEMPFILE("$CC $CCFLAGS $CFLAGS $_CCCOMCOM -E -dM -o $TARGET ' + ' $SOURCE")}'
    else:
        return '${TEMPFILE("$CC $CCFLAGS $CFLAGS $_CCCOMCOM -E -dM -o $TARGET @""' \
               + config_pkg_compiler_file + '"" ' + ' $SOURCE")}'


def compiler_cmd_cl6x(target, config_pkg_compiler_file):
    return '${TEMPFILE("$CC $CCFLAGS $_CCCOMCOM $CFLAGS -ppm=$TARGET $SOURCE")}'


def compiler_cmd_armcl(target, config_pkg_compiler_file):
    return '${TEMPFILE("$CC $CCFLAGS $_CCCOMCOM $CFLAGS -ppm=$TARGET $SOURCE")}'


def compiler_cmd_cl_arp32(target, config_pkg_compiler_file):
    return '${TEMPFILE("$CC $CCFLAGS $_CCCOMCOM $CFLAGS -ppm=$TARGET $SOURCE")}'


GENERAL_BUILD_SETTINGS = {
    'MODULE_TEST_ROOT': r'05_Testing\05_Test_Environment\Dynamic_Tests',
    'REPORT_ROOT': r'05_Testing\02_Reports\Dynamic_Tests\Project_Specific',
    'EXCLUDE_INC_PATH': {
        'dsp_0': [
            'C:/tools/ti_c6000/',
            '04_Engineering/03_Workspace/sw/xdc_packages',
            '04_Engineering/03_Workspace/sw/rtsc_platforms/Conti/MFC400',
            '04_Engineering/03_Workspace/sw/cores/dsp_0',
            ],
        'dsp_1': [
            'C:/tools/ti_c6000/',
            '04_Engineering/03_Workspace/sw/xdc_packages',
            '04_Engineering/03_Workspace/sw/rtsc_platforms/Conti/MFC400',
            '04_Engineering/03_Workspace/sw/cores/dsp_1',
            ],
        'arm-a_0': [
            '04_Engineering/04_Build/tools/edma3_lld/packages',
            '04_Engineering/03_Workspace/sw/cores/arm-a_0',
            'C:/tools/gcc_arm/',
            ],
        'arm-m_0': [
            '04_Engineering/03_Workspace/sw/cores/arm-m_0',
            'C:/tools/ti_arm/',
            ],
        'arm-m_1': [
            '04_Engineering/03_Workspace/sw/cores/arm-m_1',
            'C:/tools/ti_arm/',
            ],
        'eve_0': [
            'C:/tools/ti_arp32/',
            ],
        'eve_1': [
            'C:/tools/ti_arp32/',
            ]
    },
    'DEFAULT_OPTION_SETTINGS': {
        'ENABLED': True,
        'ADDITIONAL_INCLUDES': ['04_Engineering/00_Projects/MFC431/temporary']},
    'COMPILER_PORTINGS': {
        'COMPILER': {
            'C:/tools/ti_c6000/': {
                'CANTATA_PORTING_OPTIONS': [
                    '--parse:--lxts:int_least40_t=int',
                    '--parse:--lxts:uint_least40_t=int',
                    '--parse:--lxts:uint32_t=int',
                    '--parse:--lxtq:far',
                    '--parse:-Dfar=',
                    '--parse:-Dcregister='],
                'COMPILER_CMD_FOR_PREPROCESSOR_LIST': compiler_cmd_cl6x},
            'C:/tools/gcc_arm/':
                {'CANTATA_PORTING_OPTIONS': [
                    '--parse:-D__attribute__(x)=',
                    '--parse:-Daligned(x)='],
                    'COMPILER_CMD_FOR_PREPROCESSOR_LIST': compiler_cmd_arm_none_eabi_gcc},
            'C:/tools/ti_arm/': {
                'CANTATA_PORTING_OPTIONS': [],
                'COMPILER_CMD_FOR_PREPROCESSOR_LIST':compiler_cmd_armcl},
            'C:/tools/ti_arp32/': {
                'CANTATA_PORTING_OPTIONS':
                    ['--parse:-Dcregister='],
                'COMPILER_CMD_FOR_PREPROCESSOR_LIST': compiler_cmd_cl_arp32}
        }
    }
}
