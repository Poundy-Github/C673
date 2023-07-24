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
      'Nm_MainFunction':False, 
      'Time_MainFunction':True, 
      'WdgM_MainFunction':True 
    } 
  }, 
  'Core0_OsTask_Bsw_10ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Dcm_MainFunction':False, 
      'Dem_MainFunction':False, 
      'NvM_MainFunction':False, 
      'Fee_MainFunction':False, 
      'Fls_17_Dmu_MainFunction':False, 
      'BswM_1_OsApplication_C0_MainFunction':True, 
      'FiM_MainFunction':True 
    } 
  }, 
  'Core0_OsTask_Appl_5ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'CtCdSPI_5ms':False, 
      'SpiSync_MainFunction':True, 
      'Cdd_HeartbeatDet_MainFunction':True, 
      'Cdd_EvAdc_MainFunction':True, 
      'Sdc_MainFunction_5ms':True, 
      'AebDsMainFunction':True, 
      'Logging_MainFunction':True 
    } 
  }, 
  'Core0_InitTask_Appl':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Med_InitFunction':False, 
      'Sed_InitFunction':False, 
      'Cpr_InitFunction':False, 
      'Cps_InitFunction':False, 
      'Fcu_InitFunction':False, 
      'Cdm_InitFunction':False, 
      'HlaAdapter_InitFunction':False, 
      'TsaAdapter_InitFunction':False, 
      'Esm_InitFunction':False, 
      'SpiSync_InitFunction':False, 
      'Time_InitFunction':True, 
      'RtaAdapter_C0_InitFunction':True, 
      'Cdd_HeartbeatDet_InitFunction':True, 
      'FSMonitor_InitFunction':True, 
      'VdyAdapter_InitFunction':True, 
      'Dsm_v_Init':True, 
      'Sdc_InitFunction':True, 
      'VoltMonI_InitFunction':True, 
      'Esh_InitFunction':True, 
      'Qsm_InitFunction':True, 
      'AebDsInitFunction':True, 
      'Logging_InitFunction':True 
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
      'Med_MainFunction':False, 
      'Sed_MainFunction':False, 
      'Cdm_MainFunction':False, 
      'Comco_MainFunction':False, 
      'Dsm_v_MainFunction':True, 
      'VoltMonI_MainFunction':True, 
      'Cpr_DataProcessFunction':True, 
      'Cps_DataProcessFunction':True, 
      'Esh_MainFunction':True, 
      'Qsm_MainFunction':True, 
      'Sdc_MainFunction_10ms':True, 
      'ModM_MainFunction':True 
    } 
  }, 
  'Core0_OsTask_OperationInovkedProxy':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Det_Rte_ReportError':False, 
      'EcuM_SelectShutdownTarget':False, 
      'StbM_GetCurrentTime':True, 
      'StbM_GetRateDeviation':True, 
      'StbM_GetTimeBaseStatus':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_EXECUTE':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_HARD':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_JUMPTOBOOTLOADER':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_JUMPTOSYSSUPPLIERBOOTLOADER':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_KEYONOFF':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_NONE':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmEcuReset_SOFT':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_TX_NM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_TX_NM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_TX_NORM_NM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_ENABLE_RX_DISABLE_TX_NORM_NM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_ENABLE_TX_NORM_NM':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMBswModeNotification_DcmCommunicationControl_DCM_DISABLE_RX_TX_NORM_NM':True, 
      'Comco_u_NMWakupFlag_Read':True, 
      'Time_GetTimeStampMs':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMSwcModeNotification_Comco_RxReq':True, 
      'BswM_1_OsApplication_C0_MRPFunc_BswMSwcModeNotification_Comco_TxReq':True 
    } 
  }, 
  'Core0_OsTask_Appl_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Esm_MainFunction':False, 
      'VdyAdapter_MainFunction':True, 
      'VdyAdapter_VdyExec':True, 
      'Sdc_MainFunction_20ms':True 
    } 
  }, 
  'Core0_OsTask_Appl_60ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'HlaAdapter_MainFunction':False, 
      'HlaAdapter_HlaExec':False, 
      'TsaAdapter_MainFunction':False, 
      'TsaAdapter_TsaExec':False, 
      'RtaAdapter_C0_MainFunction':True 
    } 
  }, 
  'Core1_OsTask_Bsw_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_1_MainFunction':False, 
      'BswM_1_OsApplication_C1_MainFunction':False, 
      'Esm_Core1_MainFunction':False, 
      'BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D':True, 
      'BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B':True, 
      'BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D':True, 
      'BswM_1_OsApplication_C1_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1':True 
    } 
  }, 
  'Core1_OsTask_OperationInovkedProxy':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_1_UpdateSleepMode':False 
    } 
  }, 
  'Core1_InitTask_Appl':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Esm_Core1_InitFunction':False, 
      'FctAdapter_InitFunction':False, 
      'RtaAdapter_C1_InitFunction':True 
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
      'FctAdapter_FCTVeh_Exec':True 
    } 
  }, 
  'Core1_OsTask_Appl_10ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'FctAdapter_MainFunction':True, 
      'RtaAdapter_C1_MainFunction':True, 
      'WdgM_1_CORE_1_MainFunction':True 
    } 
  }, 
  'Core2_OsTask_Bsw_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_2_MainFunction':False, 
      'BswM_1_OsApplication_C2_MainFunction':False, 
      'BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D':True, 
      'BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B':True, 
      'BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D':True, 
      'BswM_1_OsApplication_C2_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1':True 
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
      'RtaAdapter_C2_InitFunction':True 
    } 
  }, 
  'Core2_OsTask_Appl_5ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'Esm_Core2_MainFunction':True, 
      'RtaAdapter_C2_MainFunction':True 
    } 
  }, 
  'Core3_OsTask_Bsw_20ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_3_MainFunction':False, 
      'BswM_1_OsApplication_C3_MainFunction':False, 
      'Esm_Core3_MainFunction':False, 
      'BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_GO_OFF_ONE_D':True, 
      'BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_B':True, 
      'BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_STARTUP_TWO_D':True, 
      'BswM_1_OsApplication_C3_MRPFunc_BswMModeRequestPort_Slave_BSWM_SWC_CYCLIC_SHUTDOWN_C1':True 
    } 
  }, 
  'Core3_OsTask_OperationInovkedProxy':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'EcuM_1_Core_3_UpdateSleepMode':False, 
      'CDD_MTSI_Callback':False, 
      'MtsiAdapter_MeasFreezeData':True, 
      'MtsiAdapter_UpdateTaskCycle':True 
    } 
  }, 
  'Core3_InitTask_Appl':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'MtsiAdapter_InitFunction':True, 
      'Esm_Core3_InitFunction':False, 
      'LcfAdapter_InitFunction':True, 
      'RtaAdapter_C3_InitFunction':True 
    } 
  }, 
  'Core3_OsTask_Appl_60ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'MtsiAdapter_MainFunction':True, 
      'RtaAdapter_C3_MainFunction':True 
    } 
  }, 
  'Core3_OsTask_Appl_50ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'LcfAdapter_LcfSenExec':True 
    } 
  }, 
  'Core3_OsTask_Appl_10ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'LcfAdapter_LcfVehExec':True, 
      'LcfAdapter_MainFunction':True 
    } 
  }, 
  'Core0_OsTask_FunctionSafety_5ms':{ 
    'taskRunTime':True, 
    'runnables':{ 
      'FSMonitor_MainFunction':True 
    } 
  } 
} 