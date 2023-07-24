/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCTVEH (Frame Vehicle)

PACKAGENAME:               fct_veh.h

DESCRIPTION:               FCT Component internal header file for FCTVEH

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.18 $

LEGACY VERSION:            Revision: 1.87

**************************************************************************** */

/* Bedingte Einbindung */
#ifndef FCT_VEH_H_INCLUDED
#define FCT_VEH_H_INCLUDED

/* Additional check to assure that the FCT pars running in two different task
contexts do not try to access the same data - possibly corrupting each other's
states, leading to reproducibility issues in simulation */
#ifdef FCT_SEN_H_INCLUDED
#error fct_sen.h and fct_veh.h shall not be included in the same context!
#endif

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_veh_access_func.h"
#include "frame_veh_cfg.h"
#include "frame_veh_custom_types.h"
#if (FCT_CFG_USE_ALGO_MATH)
#include "algo_math_ext.h"
#elif (FCT_CFG_USE_CML)
#include "cml_ext.h"
#endif

#ifdef __cplusplus
/* C++ extern C declarations, to allow directly including them in C++ sources. */
extern "C" {
#endif

#if (FCT_CFG_MEDIC_COMPONENT)
#include "medic_ext.h"
#endif
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))
#include "frame_lopc_ext.h"
#endif

		/* added DW */
#if (FCT_CFG_DW_PROCESSING)
#include "dw_ext.h"
#endif



#if (FCT_CFG_ACT_CODE_VERSION)
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))
#include "isc_ext.h"
#endif
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT))
#include "frame_locc_ext.h"
#endif
#endif /* FCT_CFG_ACT_CODE_VERSION */
  /**
@addtogroup frame_veh
@{ */

/*****************************************************************************
  MACROS
*****************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
#define FCT_FREEZE_DATA(pInfo, pData, Callback)        (pFCTVehServiceFuncts->pfMeasFreeze)((pInfo), (pData), (Callback))   /*!<macro to service function measfreeze*/
#else
#define FCT_FREEZE_DATA(pInfo, pData, Callback)         MEASFreezeDataMTS((pInfo), (pData), (Callback))                     /*!<macro to internal measfreeze procedure*/
#endif


//#define GET_EBA_BUS_DEBUG_DATA                    FCTVEH_pEbaBusDebugData   /*!<alias for pointer to EBABusDebugData OUTPUT interface*/

//#define GET_EGO_RAW_DATA_PTR                      FCTVEH_pEgoDynRaw         /*!<alias for pointer to raw ego dynamics data INPUT interface*/
//#define GET_EGO_STATIC_DATA_PTR                   FCTVEH_pGlobEgoStatic     /*!<alias for pointer to ego vehicle parameters INPUT interface*/

#define GET_FCT_HMI_DATA_PTR                      FCT_pHMIData              /*!<alias for pointer to HMI INPUT interface*/

#define FCT_BSW_ALGO_PARAM_PTR                    FCTVEH_pBswAlgoParameters /*!<alias for pointer to BSW algo parameters interface*/
/**************************DW ADDED**********************************************************/
#define GET_FCT_DW_CUSTOM_IN_DATA_PTR                 FCT_pDWCustomDataIn
#define GET_FCT_DW_CPAR_DATA_PTR                      FCT_pDWCPAR 
#define GET_FCT_VEH_SIG_DATA_PTR                      FCT_pVehSig  
#define GET_FCT_DW_FCT_CUSTOM_ACC_OUTPUT_IN_DATA_PTR  FCT_pFCTCustomACCOutput_DWIn                                                    /*!<alias for pointer to DW INPUT for ACC Object List interface*/
#define GET_FCT_DW_CUSTOM_OUTPUT_DATA_PTR             FCT_pDWCustomDataOut
/********************************************************************************************/

/* task monitoring checkpoints */
#define FCT_CHECKPOINT_PROCESS_INPUT              /* add one */                   /*!<not used*/
#define FCT_CHECKPOINT_PROCESS_OUTPUT             /* add one */                   /*!<not used*/
#define FCT_EVALUATE_CHECKPOINT                   /* TPEvaluateCheckpoint() */    /*!<not used*/

#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
  #ifndef e_RTA_EVT_AlgoStart
    #define e_RTA_EVT_AlgoStart                 RTA_EVT_ALGOSTART
  #endif
  #ifndef e_RTA_EVT_AlgoEnd
    #define e_RTA_EVT_AlgoEnd                   RTA_EVT_ALGOEND
  #endif
#endif
#endif


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#if (FCT_CFG_RTA_PROFILING)// PRQA S 3332
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose*/
/*!enumeration of RunTimeAssessment events.*/
enum FCTVehRtaMapping_t{
  FCTVEH_RTA_PROCESS            = 0,                  /*!<whole procedure runtime*/
  FCTVEH_RTA_PREPRE_PROCESS     = 1,                  /*!<data preparation runtime*/
  FCTVEH_RTA_LC_PROCESS         = 3,                  /*!<Longitudinal control runtime*/
  FCTVEH_RTA_PROCESSFREEZE      = 4,                  /*!<Process Measfreeze runtime*/
  FCTVEH_RTA_FRAMEFREEZE        = 5,                  /*!<Frame Measfreeze runtime*/
  FCTVEH_RTA_LAST_ENTRY         = 6                   /*!<max enum*/
};
#endif

/*! The FCT-Veh FuncID used for meas-freezes */
#if (defined(ALGO_ARS400Sensor) || defined(ALGO_ARS500Sensor)) /* ARS4xx / ARS5xx case */
 #if (defined(ALGO_ARS400Sensor) && (ALGO_ARS400Sensor))
  #define FCT_MEAS_FUNC_ID        TASK_ID_ALGO_VEH_CYCLE    /*!< alias to FCTVehicle ID (for measfreezing)*/
  /*! The FCT-Veh FuncChannelID used for meas-freezes, clarify this later! */
  #define FCT_MEAS_FUNC_CHAN_ID   20u
 #elif (defined(ALGO_ARS500Sensor) && (ALGO_ARS500Sensor))
  #define FCT_MEAS_FUNC_ID        TASK_ID_ALGO_VEH_CYCLE    /*!< alias to FCTVehicle ID (for measfreezing)*/
  /*! The FCT-Veh FuncChannelID used for meas-freezes, clarify this later! */
  #define FCT_MEAS_FUNC_CHAN_ID   20u
 #endif
#else /* camera case */
#define FCT_MEAS_FUNC_ID        TASK_ID_FCT   /*!< alias to FCTVehicle ID (for measfreezing) @todo : 20150611CO: seperate COMP_ID_EBA needed to get better split between FCT and subcomponents*/
#define FCT_MEAS_FUNC_CHAN_ID   TASK_ID_FCT   /*!< The FCT-Veh FuncChannelID used for meas-freezes @todo : 20150611CO: seperate COMP_ID_EBA needed to get better split between FCT and subcomponents*/
#endif

#if (FCT_CFG_USE_BASECTRLDATA)
#ifndef FCT_MEAS_ID_VEH_BASE_CTRL_DATA
#define FCT_MEAS_ID_VEH_BASE_CTRL_DATA (539444479)
#endif
#endif
#if (FCT_CFG_DW_PROCESSING)
extern MEMSEC_REF const FCTDWInputCustom_t     * FCT_pDWCustomDataIn;  /* FCT DW generic input*/
extern MEMSEC_REF const CPAR_DW_Parameters_t   * FCT_pDWCPAR;  /* FCT DW CPAR input*/
extern MEMSEC_REF const VehSig_t               * FCT_pVehSig;  /* FCT Veh signals*/
extern MEMSEC_REF const FCTCustomOutput_t      * FCT_pFCTCustomACCOutput_DWIn;  /* FCT DW generic for ACC Object List input*/
extern MEMSEC_REF FCTDWOutputCustom_t          * FCT_pDWCustomDataOut; /* FCT DW generic output*/
#endif 
 
/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*! Process Custom FCT Veh Output. */
extern void FCTVEHProcessCustomOutput (void);
#if (FCT_CFG_USE_DEM)
/*! set DEM event */
extern void FCTVehSetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus);
#endif

/* Function to fill error output */
#if (FCT_CFG_ERROR_OUTPUT_VEH)
extern void FCTVehFillErrorOut(FCTVehErrorOut_t * pDest);
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose*/
 #if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
  extern void VehAlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, RTA_t_Events      RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
 #else
  extern void VehAlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
 #endif
#endif

#ifdef __cplusplus
};
#endif

/* END of #ifndef FCT_VEH_H_INCLUDED */
#endif

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */



