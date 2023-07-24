# The task and runnable configuration file for the RteStandardRtaInstrGenerator
# Project: S202

#Note: This file is updated automatically at every generator run. 
#      The default setting is ENABLED. But it can be changed in the GUI of the RteStandardRtaInstrGenerator 
#      To run the generator with GUI the generator has to be called with 'True' as an additional argument. 'True'has to be the last argument.



# The dictionary contains one key per task. Every task contains again a dictionary in which the 
# runtimeMeasurement of the task can be enabled/disabled and of every single runtime within the task. 
#
#TaskAndRunnableConfig = {
#    'TaskName_0':{ 
#      'taskRunTime':True,       -> Enable/Disable runtime measurement of this task
#      'runnables':{ 
#        'Runnable_0':True,     -> Enable/Disable runtime measurement of this runnable
#        'Runnable_1':True,     -> Enable/Disable runtime measurement of this runnable
#        :
#        :
#      'Runnable_n':True,     -> Enable/Disable runtime measurement of this runnable
#      }
#    }
#    :
#    :
#    'TaskName_n':{ 
#      'taskRunTime':True,       -> Enable/Disable runtime measurement of this task
#      'runnables':{ 
#        'Runnable_0':True,     -> Enable/Disable runtime measurement of this runnable
#        'Runnable_1':True,     -> Enable/Disable runtime measurement of this runnable
#        :
#         :
#        'Runnable_n':True,     -> Enable/Disable runtime measurement of this runnable
#      }
#    }
#  }
#}

TaskAndRunnableConfig = {
  'Core0_OsTask_Bsw_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'ComM_MainFunction_0':False, 
      'ComM_MainFunction_1':False, 
      'EcuM_MainFunction':False, 
      'BswM_1_OsApplication_C0_MainFunction':False, 
      'Xcp_MainFunction':False 
    } 
  }, 
  'Core0_OsTask_Bsw_5ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Com_MainFunctionRx':False, 
      'Com_MainFunctionRouteSignals':False, 
      'Com_MainFunctionTx':False, 
      'CanTp_MainFunction':False, 
      'CanSM_MainFunction':False, 
      'CanTSyn_MainFunction':False, 
      'StbM_MainFunction':False, 
      'Can_17_McmCan_MainFunction_Mode':False, 
      'Spi_MainFunction_Handling':False, 
      'CanNm_MainFunction':False, 
      'Nm_MainFunction':False 
    } 
  }, 
  'Core0_OsTask_Bsw_10ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Dcm_MainFunction':False, 
      'Dem_MainFunction':False, 
      'NvM_MainFunction':False, 
      'Fee_MainFunction':False, 
      'Fls_17_Dmu_MainFunction':False 
    } 
  }, 
  'Core0_OsTask_Appl_5ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'CtCdSPI_5ms':False, 
      'SpiSync_MainFunction':True 
    } 
  }, 
  'Core0_InitTask_Appl':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'HwAbs_InitFunction':False, 
      'Med_InitFunction':False, 
      'Sed_InitFunction':False, 
      'Cpr_InitFunction':False, 
      'Cps_InitFunction':False, 
      'Fcu_InitFunction':False, 
      'Cdm_InitFunction':False, 
      'HlaAdapter_InitFunction':False, 
      'TsaAdapter_InitFunction':False, 
      'Dsm_InitFunction':False, 
      'Esm_InitFunction':False, 
      'SpiSync_InitFunction':False 
    } 
  }, 
  'Core0_OsTask_Appl_10ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Cpr_MainFunction':False, 
      'Fcu_MainFunction_Rx':False, 
      'Fcu_MainFunction_Tx':False, 
      'Cps_MainFunction':False, 
      'Fcu_MainFunction':False, 
      'HwAbs_MainFunction':False, 
      'Med_MainFunction':False, 
      'Sed_MainFunction':False, 
      'Cdm_MainFunction':False, 
      'Dsm_MainFunction':False, 
      'Comco_MainFunction':False 
    } 
  }, 
  'Core0_OsTask_OperationInovkedProxy':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Det_Rte_ReportError':False, 
      'EcuM_SelectShutdownTarget':False 
    } 
  }, 
  'Core0_OsTask_Appl_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Esm_MainFunction':False 
    } 
  }, 
  'Core0_OsTask_Appl_60ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'HlaAdapter_MainFunction':False, 
      'HlaAdapter_HlaExec':False, 
      'TsaAdapter_MainFunction':False, 
      'TsaAdapter_TsaExec':False 
    } 
  }, 
  'Core1_OsTask_Bsw_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_1_MainFunction':False, 
      'BswM_1_OsApplication_C1_MainFunction':False, 
      'Esm_Core1_MainFunction':False 
    } 
  }, 
  'Core1_OsTask_OperationInovkedProxy':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_1_UpdateSleepMode':False, 
      'BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B':False, 
      'BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D':False 
    } 
  }, 
  'Core1_InitTask_Appl':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Esm_Core1_InitFunction':False, 
      'VdyAdapter_InitFunction':False, 
      'FctAdapter_InitFunction':False, 
      'LcfAdapter_InitFunction':False 
    } 
  }, 
  'Core1_OsTask_Appl_60ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'FctAdapter_FCTSen_Exec':True 
    } 
  }, 
  'Core1_OsTask_Appl_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'VdyAdapter_MainFunction':True, 
      'VdyAdapter_VdyExec':True, 
      'FctAdapter_FCTVeh_Exec':True 
    } 
  }, 
  'Core1_OsTask_Appl_10ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'LcfAdapter_MainFunction':True, 
      'LcfAdapter_LcfVehExec':True, 
      'FctAdapter_MainFunction':True, 
      'FctAdapter_LodmcMainFunction':True 
    } 
  }, 
  'Core1_OsTask_Appl_50ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'LcfAdapter_LcfSenExec':True 
    } 
  }, 
  'Core2_OsTask_Bsw_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_2_MainFunction':False, 
      'BswM_1_OsApplication_C2_MainFunction':False, 
      'Esm_Core2_MainFunction':False, 
      'BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B':False, 
      'BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D':False 
    } 
  }, 
  'Core2_OsTask_OperationInovkedProxy':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_2_UpdateSleepMode':False 
    } 
  }, 
  'Core2_InitTask_Appl':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Esm_Core2_InitFunction':False, 
      'Sdc_InitFunction':False 
    } 
  }, 
  'Core2_OsTask_Appl_10ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Sdc_MainFunction_Rx':False, 
      'Sdc_MainFunction_Tx':False, 
      'Sdc_Rid_OtaUpdatedCmd':False 
    } 
  }, 
  'Core2_OsTask_Appl_5ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Sdc_MainFunction':False 
    } 
  }, 
  'Core3_OsTask_Bsw_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_3_MainFunction':False, 
      'BswM_1_OsApplication_C3_MainFunction':False, 
      'Esm_Core3_MainFunction':False, 
      'BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B':False, 
      'BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D':False 
    } 
  }, 
  'Core3_OsTask_OperationInovkedProxy':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_3_UpdateSleepMode':False, 
      'MtsiAdapter_MeasFreezeData':False, 
      'CDD_MTSI_Callback':False 
    } 
  }, 
  'Core3_InitTask_Appl':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'MtsiAdapter_InitFunction':True, 
      'Esm_Core3_InitFunction':False 
    } 
  }, 
  'Core3_OsTask_Appl_60ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'MtsiAdapter_MainFunction':True 
    } 
  } 
} 