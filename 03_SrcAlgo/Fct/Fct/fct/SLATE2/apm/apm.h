/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               apm_ext.h

DESCRIPTION:               Internal header file for ACC Performance Monitoring (APM) module in SLATE task

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             21.10.2016

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef APM_INCLUDED
#define APM_INCLUDED
 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h"
#include "apm_par.h"


#if (SLATE_CFG_ACC_PERF_MONITORING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup apm
@{ */

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT INTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERN)
*****************************************************************************/
  typedef struct APM_ThresQuotas
  {
    float32 f_MaxLatDist;
    float32 f_MaxLatDistALN;
    float32 f_MaxLatDistVDY;
  } APM_ThresQuotas_t; // Duplicate to SPM_t_a_ThresQuotas -> RTE/Frame???

  /* Degradation data */
  typedef struct APM_Quotas
  {
    float32 f_MaxQuotaALN;
    float32 f_MaxQuotaVDY;
    float32 f_MaxLatDist;
  } APM_Quotas_t; // Duplicate to SPM_t_a_Quotas -> RTE/Frame???

  typedef struct APM_MaxDist
  {
    float32 f_MaxDistALN;
    float32 f_MaxDistVDY;
    float32 f_MaxDistELV;
    float32 f_MaxDist;
  } APM_MaxDist_t; // Duplicate to SPM_t_a_MaxDist -> RTE/Frame???

  typedef struct APM_Degradation{
    APM_MaxDist_t a_DegrDistPerf;
    fDistance_t f_MaxDistPerfMin;
    APM_Quotas_t a_QuotasPerf;
    boolean b_LoudDegrdation;
  }APM_Degradation_t; // Duplicate to SPM_t_a_Degradation -> RTE/Frame???


  typedef struct APM_Degradation_Data
  {
    uint32 SPMDegradationACC;
    APM_Degradation_t a_DegradationACC;
  } APM_Degradation_Data_t;
/*! Enumeration of errors supported by APM */
typedef enum APMErrorEvents {
  //APM_ERREV_INTERFERENCE_RANGE,
  APM_ERREV_ACC_DEGRADATION_AZ, 
  APM_ERREV_ACC_DEGRADATION_EL, 
  APM_ERREV_ACC_DEGRADATION_VDY,
  APM_ERREV_NUM_ERRORS
} APMErrorEvents_t;

/*****************************************************************************
  CONSTANTS (COMPONENT INTERN)
*****************************************************************************/
/*! Degradation parameters -> degradation distances*/
#define APM_ACC_MAX_LAT_DIST_PERF                 APM_ACC_MAX_LAT_DIST_PERF_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_ACC_MAX_LAT_DIST_PERF_c)

#define APM_ACC_MAX_LAT_DIST_PERF_ALN             APM_ACC_MAX_LAT_DIST_PERF_ALN_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_ACC_MAX_LAT_DIST_PERF_ALN_c)

#define APM_ACC_MAX_LAT_DIST_PERF_VDY             APM_ACC_MAX_LAT_DIST_PERF_VDY_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_ACC_MAX_LAT_DIST_PERF_VDY_c)

#define APM_ACC_PERF_ALN_MAX_QUOTA                APM_ACC_PERF_ALN_MAX_QUOTA_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_ACC_PERF_ALN_MAX_QUOTA_c)
#define APM_ACC_PERF_VDY_MAX_QUOTA                APM_ACC_PERF_VDY_MAX_QUOTA_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_ACC_PERF_VDY_MAX_QUOTA_c)


/*! Degradation parameters -> minimal performance distance - assumptions (worst case) */  
#define APM_MIN_PERF_DIST_V_DIFF_MAX              APM_MIN_PERF_DIST_V_DIFF_MAX_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_MIN_PERF_DIST_V_DIFF_MAX_c)
#define APM_MIN_PERF_DIST_T_REAK                  APM_MIN_PERF_DIST_T_REAK_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_MIN_PERF_DIST_T_REAK_c)
#define APM_MIN_PERF_DIST_A_EGO_MAX               APM_MIN_PERF_DIST_A_EGO_MAX_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_MIN_PERF_DIST_A_EGO_MAX_c)
#define APM_MIN_PERF_DIST_A_TARGET_MAX            APM_MIN_PERF_DIST_A_TARGET_MAX_c
FCT_DECL_FIX_PARAM(MEMSEC_REF float32,                         APM_MIN_PERF_DIST_A_TARGET_MAX_c)

/* Meas Freeze ID */
#ifndef  FCT_MEAS_ID_APM_DEGRADATION_DATA
#define FCT_MEAS_ID_APM_DEGRADATION_DATA (0x20240300u) // 539230720U = (0x20240200u)/* Remark: to be moved to RTE ! */
#endif

/*****************************************************************************
  VARIABLES (COMPONENT INTERN)
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS (COMPONENT INTERN)
*****************************************************************************/

/*--- apm_main.c ---*/
extern void APM_v_SetErrorState(APMErrorEvents_t t_APM_Error, AlgoErrorState_t t_Err_State);

/*--- apm_degradation.c ---*/
extern void APM_v_PerfDegradation(void);
extern void APM_v_InitDegradationData(void);
extern void APM_v_MeasFreezeDegradationData(void);

/*--- apm_interference.c ---*/
//extern void SPMInterferenceRange (void);
//extern void APM_v_InitInterferenceData(void);

#ifdef __cplusplus
};
#endif
///@}
#endif /*!< SLATE_CFG_ACC_PERF_MONITORING */

/* End of conditional inclusion */
#endif  /*!< _APM_INCLUDED */


