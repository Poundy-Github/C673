import os

def CompilereCmd_arm_none_eabi_gcc(target,configPkgCompilerFile):
    if target == 'sbl' or target == 'sbl_loop' or target == 'presbl':
        return '${TEMPFILE("$CC $CCFLAGS $CFLAGS $_CCCOMCOM -E -dM -o $TARGET ' + ' $SOURCE")}'
    else:
        return '${TEMPFILE("$CC $CCFLAGS $CFLAGS $_CCCOMCOM -E -dM -o $TARGET @""' + configPkgCompilerFile + '"" ' + ' $SOURCE")}'

def CompilereCmd_cl6x(target,configPkgCompilerFile):
    return '${TEMPFILE("$CC $CCFLAGS $_CCCOMCOM $CFLAGS -ppm=$TARGET $SOURCE")}'

def CompilereCmd_armcl(target,configPkgCompilerFile):
    return '${TEMPFILE("$CC $CCFLAGS $_CCCOMCOM $CFLAGS -ppm=$TARGET $SOURCE")}'
    
def CompilereCmd_cl_arp32(target,configPkgCompilerFile):
    return '${TEMPFILE("$CC $CCFLAGS $_CCCOMCOM $CFLAGS -ppm=$TARGET $SOURCE")}'

GENERAL_BUILD_SETTINGS = {
    'MODULE_TEST_ROOT':r'05_Testing\05_Test_Environment\Dynamic_Tests',
    'EXCLUDE_INC_PATH':[ # dsp_0
                        'c:/tools/ti_c6000/7.4.20/include',
                        '04_Engineering/03_Workspace/sw/xdc_packages',
                        '04_Engineering/03_Workspace/sw/rtsc_platforms/Conti/MFC400',
                        '04_Engineering/03_Workspace/sw/cores/dsp_0',
                        # arm-a_0
                        #'04_Engineering/04_Build/tools/edma3_lld/packages',
                        '04_Engineering/03_Workspace/sw/cores/arm-a_0',
                        # arm-m_0 
                        '04_Engineering/03_Workspace/sw/cores/arm-m_0',
                        'C:/tools/ti_arm/5.1.5/include/rts',
                        'C:/tools/ti_arm/5.1.5/include',
                        # eve_0
                        'C:/tools/ti_arp32/1.0.8/include',
                        ],
    'LICENSE_SETTING': {'LSFORCEHOST' : os.environ['LSFORCEHOST']},
    'DEFAULT_OPTION_SETTINGS': {'MUT_IN_DRIVER_INCLUDED': True,
                                'ENABLED': True,
                                'ADDITIONAL_DEFINES': [],
                                'ADDITIONAL_INCLUDES': ['04_Engineering/00_Projects/MFC431/temporary'],
                                'ADDITIONAL_SOURCES': [],
                               },
    'COMPILER_PORTINGS':{'COMPILER':{'C:/tools/ti_c6000/7.4.20/bin/cl6x.exe':{'CANTATA_PORTING_OPTIONS':['--parse:--lxts:int_least40_t=int',
                                                                                                                    '--parse:--lxts:uint_least40_t=int',
                                                                                                                    '--parse:--lxts:uint32_t=int',
                                                                                                                    '--parse:--lxtq:far',
                                                                                                                    '--parse:-Dfar=',
                                                                                                                    '--parse:-Dcregister='], 
                                                                                          'COMPILER_CMD_FOR_PREPROCESSOR_LIST':CompilereCmd_cl6x                         
                                                                                         },
                                     'C:/tools/gcc_arm/4.7_2012q4/bin/arm-none-eabi-gcc.exe':{'CANTATA_PORTING_OPTIONS':['--parse:-D__attribute__(x)=',
                                                                                                                                       '--parse:-Daligned(x)='],
                                                                                                            'COMPILER_CMD_FOR_PREPROCESSOR_LIST':CompilereCmd_arm_none_eabi_gcc
                                                                                                                 },
                                     'C:/tools/ti_arm/5.1.5/bin/armcl.exe':{'CANTATA_PORTING_OPTIONS':[],
                                                                                        'COMPILER_CMD_FOR_PREPROCESSOR_LIST':CompilereCmd_armcl                         
                                                                                       },
                                     'C:/tools/ti_arp32/1.0.8/bin/cl-arp32.exe':{'CANTATA_PORTING_OPTIONS':['--parse:-Dcregister='],
                                                                                             'COMPILER_CMD_FOR_PREPROCESSOR_LIST':CompilereCmd_cl_arp32                         
                                                                                            }
                                    }
                        }            
}
