/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_sen.h

DESCRIPTION:               FCT component intern header FCT_SEN

AUTHOR:                    Gergely Ungvary

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.1.1.2

**************************************************************************** */

/* Bedingte Einbindung */
#ifndef FCT_SEN_H_INCLUDED
#define FCT_SEN_H_INCLUDED

/* Additional check to assure that the FCT pars running in two different task
contexts do not try to access the same data - possibly corrupting each other's
states, leading to reproducibility issues in simulation */
#ifdef FCT_VEH_H_INCLUDED
#error fct_sen.h and fct_veh.h shall not be included in the same context!
#endif

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_sen_access_func.h"
#include "fct_ver.h"
#if (FCT_CFG_USE_ALGO_MATH)
#include "algo_math_ext.h"
#elif (FCT_CFG_USE_CML)
#include "cml_ext.h"
#endif
#if (FCT_CFG_ACC_CAL)
#include "cal_ext.h"
#endif

#ifdef __cplusplus
/* @todo: later on all internal _ext headers shall contain proper C++ extern C
declarations, to allow directly including them in C++ sources. */
extern "C" {
#endif

#if ((FCT_CFG_SLATE_COMPONENT)&&(FCT_CFG_ADAPTIVE_CRUISE_CONTROL))
#include "slate_ext.h"
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
#include "spm_ext.h"
#endif

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))
#include "frame_lohp_ext.h"
#endif

#if (FCT_CFG_ACDC_COMPONENT)
#include "acdc_ext.h"
#endif
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup frame_sen
@{ */

/*****************************************************************************
  MACROS
*****************************************************************************/


#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
#define FCT_FREEZE_DATA(pInfo, pData, Callback)        (pFCTSenServiceFuncts->pfMeasFreeze)((pInfo), (pData), (Callback))
#else
#define FCT_FREEZE_DATA(pInfo, pData, Callback)         MEASFreezeDataMTS((pInfo), (pData), (Callback))
#endif


#define GET_RSP_PD_OUTPUT_DATA_PTR                FCTSEN_pRSPOutputPD // wer braucht das?


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*! The FCT-Sen FuncID used for meas-freezes */
#if (defined(ALGO_ARS400Sensor) || defined(ALGO_ARS500Sensor)) /* ARS4xx / ARS5xx case */
 #if (defined(ALGO_ARS400Sensor) && (ALGO_ARS400Sensor))
  #define FCT_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
  /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
  #define FCT_MEAS_FUNC_CHAN_ID   60u
 #elif (defined(ALGO_ARS500Sensor) && (ALGO_ARS500Sensor))
  #define FCT_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
  /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
  #define FCT_MEAS_FUNC_CHAN_ID   60u
 #endif
#else /* camera case */
  #define FCT_MEAS_FUNC_ID        TASK_ID_FCT60
  /*! The FCT-Sen FuncChannelID used for meas-freezes */
  #define FCT_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
#endif

/*****************************************************************************
  FUNCTION
*****************************************************************************/
#if (FCT_CFG_USE_DEM)
extern void FCTSenSetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus);
#endif /*FCT_CFG_USE_DEM*/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern void FCTSenSetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif

#if (FCT_CFG_SENSOR_CONTROL_INTF)
/* Sensor specific processing call */
extern void FCTSensorSpecificProc(const FCTSenErrorOut_t * pSenErrorOut, FCTSensorControl_t * pSensorCtrl);
#endif

/*! set states of subcomponents according to FCT_OP_MODE */
extern void FCTSenProcessStates(FCT_OP_MODE_t eOpMode);

/*! set states of subcomponents to save state and signal Error on FCT level */
extern void FCTSenSignalErrorShutdown (const boolean isRecoveryPossible);

/*! Process FCT Input. */
extern void FCTSenProcessInput(fTime_t fCycleTime, const VehDyn_t * pEgoDyn);

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
extern uint32 FCTSenCheckInputUpdate(const reqFCTSenPrtList_t * pRequirePorts, FCTSen_InputMeasCounter_t *pFCTSenInputMeasTimeStamps, float32 fTargetCycleTime );
#endif

#if (FCT_SEN_CFG_CUSTOM_POST_PROC)
extern void FCTSenCustomProc(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts);
#endif 

/*! Process FCT Meas */
extern void FCTSenProcessMeasFreeze(const proFCTSenPrtList_t * const pProvidePorts);
extern void FCTSenMeasCallback(void);
#if (FCT_MEASUREMENT)
extern void FCTSenFrameFreeze(void);
#endif

#if (defined(RTA_INTERFACE_VERSION))
/* These defines have to be added to make the identifier for RTA unique */
#define ACDC_RTA_OFFSET      0
#define SLATE_RTA_OFFSET     100
#define SPM_RTA_OFFSET       200
#define FCTFRAME_RTA_OFFSET  230

#if (RTA_INTERFACE_VERSION >= 4)
 void FCTSEN_SERVICE_ADD_EVENT( const RTA_t_Events      RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData);
#else
 void FCTSEN_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData);
#endif
#else
 void FCTSEN_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType,  const uint8 u_IdLocal, const uint8 u_OptData);
#endif

#ifdef __cplusplus
};
#endif


/* END of #ifndef FCT_SEN_H_INCLUDED */
#endif

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
