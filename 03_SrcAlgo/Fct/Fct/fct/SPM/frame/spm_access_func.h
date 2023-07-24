#ifndef SPM_ACCESS_H_INCLUDED
#define SPM_ACCESS_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_types.h"
#include "spm_ext.h"
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
  #include "fct_sen_access_func.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
/* SPM ports handler list */
extern MEMSEC_REF SPMPortHandlerList_t SPMPortHandlerList;

#if(FCT_CFG_ERROR_OUTPUT_SEN)
  extern MEMSEC_REF SPMErrorOutProPort_t * SPM_pErrorOut;
#endif

/* Meas freeze reference */
extern MEMSEC_REF FCTSen_SPMSyncRef_t t_FCTSenSPMSyncRef;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  extern MEMSEC_REF const AS_t_ServiceFuncts *pFCTSenSPMServiceFuncts;
#endif

#if (FCT_CFG_EM_FCT_CYCLEMODE)
extern MEMSEC_REF const EmFctCycleMode_t       * FCTSEN_pSPMEmFctCycleMode;   /* Global system cycle mode etc. data */
#endif

extern MEMSEC_REF const PerfDegr_t             * FCTSEN_pSPMPerfDegrData;     /* Performance degradation input data */

extern MEMSEC_REF const VehDyn_t               * FCTSEN_pSPMEgoDynRaw;     /* Performance degradation input data */

extern MEMSEC_REF const VehDyn_t               * pSPMEgoDynObjSync;       /* The dynamic vehicle ego data object sync */

#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  extern MEMSEC_REF const FctVeh2SenInfo_t   * pFctVehLongOut;              /* Longitudinal control */
#endif

extern MEMSEC_REF SysPerfMonStates_t           * FCTSEN_pSPMSysPerfMonStates; /* System performance monitor output data */

#if (FCT_CFG_OBJECT_LIST_PROC)
  #if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  extern MEMSEC_REF const AssessedObjList_t * FCTSEN_pSPMPubFctObj;         /* The public FCT object data */
  #endif
  #if (FCT_USE_EM_GENERIC_OBJECT_LIST)
    extern MEMSEC_REF const EM_t_GenObjectList * FCTSEN_pSPMEmGenObjList;     /* The generic EM object data */
    #if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
      extern MEMSEC_REF const EM_t_ARSObjectList * FCTSEN_pSPMEmARSObjList;
    #endif
  #else
    extern MEMSEC_REF const ObjectList_t * FCTSEN_pSPMEmObjList;        /* The public EM object data */
  #endif
#endif

#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    extern MEMSEC_REF const PerfDegrExtInput_t * pSPMPerfDegrExtInput;
#endif

extern MEMSEC_REF const FCTCtrlData_t * pSPMCtrlData;

extern MEMSEC_REF const BSW_s_AlgoParameters_t * pSPMBswAlgoParameters;

#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
  extern MEMSEC_REF const SLATE_SPM_Data_t * FCTSEN_pSLATE_SPM_Data;
#endif

#if (SYS_PERF_MON_OUT_INTFVER >= 3u)
  #if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
    #if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
      extern MEMSEC_REF SysPerfMonStates_t * pSPMSysPerfMonStates;
    #endif
  #endif
#endif

#if(FCT_CFG_LOHP_COMPONENT)
  extern MEMSEC_REF SPM_HC_Data_t * pSPMHCData;
#endif

#if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE)
  extern MEMSEC_REF e_AlignState_t * pAlignState;
#endif

#if((FCT_CFG_ALIGNMENT_MONITORING_INPUT) && (FCT_CFG_ALIGNMENT_MONITORING_INPUT))
  extern MEMSEC_REF const ALN_S_Monitoring_t * pALNMonitoring;
#endif

#endif

#ifdef __cplusplus
};
#endif

#endif
