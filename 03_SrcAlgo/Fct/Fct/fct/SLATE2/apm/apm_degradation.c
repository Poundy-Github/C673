/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 APM (system performance monitoring)

MODULNAME:                 apm_degradation.c

DESCRIPTION:               This module determines the degradation (maximum longitudinal distances) for ACC

AUTHOR:                    Björn Hackel

CREATION DATE:             20.10.2014

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
//#include "si.h"
//#include "spm.h"
//#include "spm_par.h"
#include "apm.h"//PRQA S 0380 
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (SLATE_CFG_ACC_PERF_MONITORING)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup apm_degradation Degradation
@ingroup apm
@brief          Determines the degradation (maximum longitudinal distances) for ACC. \n\n

@description    The following functionalities are provided by this module:
                - Initializes and freezes the APM degrdation data.
                - Calculates the performance degradation.
				- Calculates the max allowed x dist based on ALN-, VDY data and the max. allowed lateral deviation.
				- Calculates the minimal required performance distance.

@{
*/


/*****************************************************************************
  MACROS
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

#define APM_f_Delta           (0.000001f)       /*!< APM minimum value for zero comparision */
#define APM_DEGR_EVENTCOUNT   (5)               /*!< Degradation event counter */
#define APM_CYCLES_MASK_15    (0x7FFFu)         /*!< Degradation bitmask */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  MODULEGLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULELOKAL VARIABLES
*****************************************************************************/


SET_MEMSEC_VAR(t_APM_DegData)
static APM_Degradation_Data_t t_APM_DegData;  /*!< APM degradation data */


/*! Meas freeze structure */
SET_MEMSEC_VAR(t_APMDegradationMeasInfo)
static const MEASInfo_t t_APMDegradationMeasInfo =// PRQA S 3207
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: Unused, but may be used in future*/
{
  FCT_MEAS_ID_APM_DEGRADATION_DATA,       /*!<.VirtualAddress */
  sizeof(t_APM_DegData),                  /*!<.Length */
  FCT_ACC_MEAS_FUNC_ID,                       /*!<.FuncID */
  FCT_ACC_MEAS_FUNC_CHAN_ID                   /*!<.FuncChannelID */
};

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void APM_v_CalcMaxDist(APM_Degradation_t * p_a_Degradation, APM_MaxDist_t *p_a_DegrDist, const APM_ThresQuotas_t *p_a_ThresQuota,  boolean b_PerfDist); // duplicate to SPM_v_CalcMaxDist
//static void     SPM_v_CalcMaxDist( SPM_t_a_Degradation *p_a_Degradation, SPM_t_a_MaxDist* p_a_DegrDist, const SPM_t_a_ThresQuotas *p_a_ThresQuota,  boolean b_PerfDist );
static float32 APM_f_CalcMinPerfDist(void);
static void APM_v_DegrSetDEMEvents(void);

/*****************************************************************************
  FUNCTION
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:    APM_v_InitDegradationData                                                                        */ /*!

  @brief           Initialize APM degrdation data

  @description     Initialize APM degrdation data

  @startuml 
    Partition APM_v_InitDegradationData
    Start
      Note right: This function initializes APM degradation data
      - Depending on the available sources \n update APM degradation data
  End
  @enduml

  @return          -

  @param[in]       -

  @glob_out        t_APM_DegData.a_DegradationACC.a_QuotasPerf.f_MaxQuotaALN : [0.f]
  @glob_out        t_APM_DegData.a_DegradationACC.a_QuotasPerf.f_MaxQuotaVDY : [0.f]
  @glob_out        t_APM_DegData.a_DegradationACC.a_QuotasPerf.f_MaxLatDist : [0.f]
  @glob_out        t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDist : [0.f]
  @glob_out        t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistALN : [0.f]
  @glob_out        t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistVDY : [0.f]
  @glob_out        t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistELV : [0.f]
  @glob_out        t_APM_DegData.a_DegradationACC.f_MaxDistPerfMin : [0.f]
  @glob_out        t_APM_DegData.SPMDegradationACC : [0.f]

  @glob_in         -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void APM_v_InitDegradationData(void)
{
  t_APM_DegData.a_DegradationACC.a_QuotasPerf.f_MaxQuotaALN = 0.f;
  t_APM_DegData.a_DegradationACC.a_QuotasPerf.f_MaxQuotaVDY = 0.f;
  t_APM_DegData.a_DegradationACC.a_QuotasPerf.f_MaxLatDist = 0.f;

  t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDist = 0.f;
  t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistALN = 0.f;
  t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistVDY = 0.f;
  t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistELV = 0.f;
 
  t_APM_DegData.a_DegradationACC.f_MaxDistPerfMin = 0.f;

  t_APM_DegData.SPMDegradationACC = 0u;
}


/*************************************************************************************************************************
  Functionname:    APM_v_MeasFreezeDegradationData                                                                  */ /*!

  @brief           Freeze APM degradation data

  @description     Freeze APM degradation data

  @startuml 
  Partition APM_v_MeasFreezeDegradationData
  Start
    Note right: This function freezes APM degradation data
    - Freeze APM degradation data structure
  End
  @enduml

  @return          -

  @param[in]       -

  @glob_in         t_APMDegradationMeasInfo : Meas freeze structure
  @glob_in         t_APM_DegData : data to be freezed
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void APM_v_MeasFreezeDegradationData(void)
{
  /*! Freeze degradation data */
  Meas_Freeze_Stack_Var(FCT_MEAS_ID_APM_DEGRADATION_DATA, &t_APM_DegData, sizeof(APM_Degradation_Data_t));
}

/*************************************************************************************************************************
  Functionname:    APM_v_PerfDegradation                                                                               */ /*!

  @brief           Main function to coordinate the calculations for the performance degradation

  @description     Main function to coordinate the calculations for the performance degradation

                   Safety Distance: 
                    ACC: No breaking with a higher deceleration than 3.5m/s^2 resp. 4m/s^2 
                    on objects that are outside the safety distance 

                   Performance Distance:
                    ACC: No reaction on objects which are outside the performance distance

                   Min Performance Distance:
                    ACC: If the performance distance is below the min performance distance, the system 
                    shall shut off (loud degradation)
  
  @startuml 
    Partition APM_v_PerfDegradation
    Start
    Note right: Main function to coordinate the calculations for the performance degradation
    Partition ALIGNMENT_MONITORING_INPUT {
      If (ALIGNMENT MONITORING INPUT is present) then (True)
        - Update Alignment state with Alignment state from Alignment monitoring output data
      Else (False)
      Endif
    }
    - Update the ACC Safety Threshold Quotas data structures \n Update the ACC Performance Threshold Quotas data structures 
    - Calculate  minimal required performance distance 
    - Calculate Maximum allowed X distance based on VDY and ALN \n data and maximum allowed lateral deviation for both ACC Safety \n Threshold Quotas and ACC Performance Threshold Quotas
    - Check loud degradation for ACC
    
    Partition ALIGNMENT_MONITORING_INPUT {
    If (ALIGNMENT MONITORING INPUT is present) then (True)
      If (Alignment State is not  equal to Normal Alignment State) Then (True)
        - Update the APM Degradation Performance Distance data structure to zero
      Else (False)
      Endif
    Else (False)
    Endif 
    }
    End
  @enduml

  @return          -

  @param[in]       -

  @glob_in         ALN_MON_INPUT_PTR : Alignment monitoring input
                            e_AlignState : State of the alignment component [e_AlignState_t as in Rte_Type.h]
  @glob_out        t_APM_DegData : Global APM data
                          a_DegradationACC.f_MaxDistPerfMin                   [full range of datatype float32 with >= 0.f ]
                          a_DegradationACC.a_DegrDistPerf.f_MaxDist           [full range of datatype float32 with >= 0.f ]
                          a_DegradationACC.a_DegrDistPerf.f_MaxDistALN        [full range of datatype float32 with >= 0.f ]
                          a_DegradationACC.a_DegrDistSafe.f_MaxDist           [full range of datatype float32 with >= 0.f ]
                          a_DegradationACC.a_DegrDistSafe.f_MaxDistALN        [full range of datatype float32 with >= 0.f ]
                          a_DegradationACC.b_LoudDegrdation                   [TRUE, FALSE]
                          a_DegradationEBA.a_DegrDistPerf.f_MaxDist           [full range of datatype float32 with >= 0.f ]
                          a_DegradationEBA.a_DegrDistPerf.f_MaxDistALN        [full range of datatype float32 with >= 0.f ]
                          a_DegradationEBA.b_LoudDegrdation                   [TRUE, FALSE]


  @c_switch_part   CFG_SI_DTR_OBJ_SELECTION : DTR object selection
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         20.10.2014
  @changed         23.11.2015

  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
void APM_v_PerfDegradation(void)
{   
  APM_ThresQuotas_t a_ACCPerfThresQuotas;//a_EBASafeThresQuotas, a_EBAPerfThresQuotas;
#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  e_AlignState_t e_AlignState = ALN_MON_INPUT_PTR->e_AlignState;
#endif
  /*Initialization of the data structures*/
  a_ACCPerfThresQuotas.f_MaxLatDist     = APM_ACC_MAX_LAT_DIST_PERF;
  a_ACCPerfThresQuotas.f_MaxLatDistALN  = APM_ACC_MAX_LAT_DIST_PERF_ALN;
  a_ACCPerfThresQuotas.f_MaxLatDistVDY  = APM_ACC_MAX_LAT_DIST_PERF_VDY;

  /*a_EBASafeThresQuotas.f_MaxLatDist     = SPM_EBA_MAX_LAT_DIST_SAFE;
  a_EBASafeThresQuotas.f_MaxLatDistALN  = SPM_EBA_MAX_LAT_DIST_SAFE_ALN;
  a_EBASafeThresQuotas.f_MaxLatDistVDY  = SPM_EBA_MAX_LAT_DIST_SAFE_VDY;

  a_EBAPerfThresQuotas.f_MaxLatDist     = SPM_EBA_MAX_LAT_DIST_PERF;
  a_EBAPerfThresQuotas.f_MaxLatDistALN  = SPM_EBA_MAX_LAT_DIST_PERF_ALN;
  a_EBAPerfThresQuotas.f_MaxLatDistVDY  = SPM_EBA_MAX_LAT_DIST_PERF_VDY;*/

  /*Calculation of the degradation distances*/
  t_APM_DegData.a_DegradationACC.f_MaxDistPerfMin = APM_f_CalcMinPerfDist();

  APM_v_CalcMaxDist( &t_APM_DegData.a_DegradationACC, &t_APM_DegData.a_DegradationACC.a_DegrDistPerf, &a_ACCPerfThresQuotas, TRUE);
  //SPM_v_CalcMaxDist( &SPMData.a_DegradationEBA, &SPMData.a_DegradationEBA.a_DegrDistPerf, &a_EBAPerfThresQuotas, TRUE);
  
  /*Check loud degradation for ACC*/
  APM_v_DegrSetDEMEvents();

#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  if(e_AlignState != ALNMonNormal)
  {  
    t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDist = 0.f;
    t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistALN = 0.f;
    t_APM_DegData.a_DegradationACC.b_LoudDegrdation = TRUE;

    //SPMData.a_DegradationEBA.a_DegrDistPerf.f_MaxDist = 0.f;
    //SPMData.a_DegradationEBA.a_DegrDistPerf.f_MaxDistALN = 0.f;
    //SPMData.a_DegradationEBA.b_LoudDegrdation = TRUE;
  }
#endif

}


/*************************************************************************************************************************
  Functionname:    SPM_v_CalcMaxDist                                                                                */ /*!

  @brief           Calculates the max allowed x dist based on ALN-, VDY data and the max. allowed lateral deviation

  @description     Calculates the max allowed x dist based on ALN-, VDY data and the max. allowed lateral deviation

  @startuml 
    Partition APM_v_CalcMaxDist
    Start
    Note right: This function calculates the maximum \n allowed X distance based on \n Alignment, VDY data and the \n maximum allowed lateral deviation
    Note right: If Distance (Boolean) is true \n then Performance distance \n otherwise Safety distance
  
    If (Distance is True) Then (True)
      Partition FarScanAvailable {
      If (FarScan is Available) Then (True)
        - Update Misalignment Standard deviation \n Azimuth Angle taking maximum of \n both Near scan and Far Scan \n Standard deviation Azimuth Angle
      Else (False)
        - Update Misalignment Standard deviation \n Azimuth Angle using only Near scan \n Standard deviation Azimuth Angle
      Endif
      }
    Else (False)
      Partition FarScanAvailable {
      If (FarScan is Available) Then (True)
        - Update Misalignment error using \n Near scan and Far scan \n Misalignment Azimuth Angle
      Else (False)
        - Update Misalignment Standard deviation \n Azimuth Angle using only Near scan \nStandard deviation Azimuth Angle
      Endif
      }
    Endif
    
    - Update Misalignment Azimuth Angle, Ego curve path, \n Ego Curve error and Maximum Ego Curve \n Update VDY curve path, Misalignment angle \n and Maximum allowed lateral deviation
  
    If (Alignment values are present) then (True)
      - Update Maximum distance based \n on lateral and alignment inputs
    Else (False)
    if (VDY values are present) then (True)
      - Update Maximum distance based \n on lateral and VDY inputs
    Else(False)
    if (both Alignment and VDY values are not present)(True)
      - Reset the values
    Else (False)
      - Calculate the fused distance from \n VDY, alignment and lateral inputs
      If(Fused distance &gt; zero) then (true)
        - Calculate maximum degradation \n distance using fused distance, \n VDY and alignment inputs
      Else (False)
        - Update maximum degradation distance to zero
      Endif
      
      If (Misalignment Azimuth Angle \n is not equal to zero) then (true)
        - Calculate maximum degradation \n distance using maximum lateral \n distance using alignment inputs
      Else (False)
        - Update maximum degradation distance to zero
      Endif
  
      If (VDY curve path is not equal to zero) then (true)
        - Calculate maximum degradation \n distance using maximum lateral \n distance using VDY inputs
      Else (False)
        - Update maximum degradation distance to zero
      Endif
    Endif
    Endif
    Endif
  
    - Calculate the respective lateral errors \n for a given longitudinal distance
    If (Performance distance is true) then (True)
      - Update the Performance Quotas data structures 
    Else (Flase)
      - Update the Safety Quotas data structures 
    Endif
  
    Partition ELEVATION_ANGLE
      If (ELEVATION ANGLE is present) then (True)
        If ((Performance distance is False) \n AND \n (Alignment monitoring output data version number &gt; 4)) then (True)
          - Take the minimum out of fused/azimuth \n and elevation distance and update \n the Maximum degradation distance \n from alignment and elevation inputs
        Else (False)
        Endif
      Else (False)
      Endif
  
    End
  @enduml

  @return          -

  @param[out]      p_a_Degradation : Current lateral errors
                      a_QuotasPerf.f_MaxLatDist [full range of datatype float32]
                      a_QuotasPerf.f_MaxQuotaVDY [full range of datatype float32]
                      a_QuotasPerf.f_MaxQuotaALN [full range of datatype float32]
  @param[out]      *p_a_DegrDist : Max ranges based on the amx allowed lateral errors and the respective module error
                      f_MaxDist [full range of datatype float32]
                      f_MaxDistALN [full range of datatype float32]
                      f_MaxDistVDY [full range of datatype float32]
                      f_MaxDistELV [full range of datatype float32]
  @param[in]       *p_a_ThresQuota : the max. allowed lateral error for the different distances
                      f_MaxLatDist [full range of datatype float32]
                      f_MaxLatDistALN [full range of datatype float32]
                      f_MaxLatDistVDY [full range of datatype float32]
  @param[in]       b_PerfDist : flag to check if a performance distance shall be calculated or a safety distance [TRUE, FALSE]

  @glob_in         ALN_MON_INPUT_PTR : Alignment monitoring input
                      a_CurrentAzimuthStd[i] [full range of datatype float32]  i = [0u,1u] 0u: Nearscan and 1u: Farscan
                      Azimuth[i].f_Misalignment [full range of datatype float32]  i = [0u,1u] 0u: Nearscan and 1u: Farscan
                      Azimuth[i].f_Std [full range of datatype float32]  i = [0u,1u] 0u: Nearscan and 1u: Farscan
                      u_VersionNumber [1u ... 16777215u]
                      f_ObstacleRangeMax [0.f ... 200.f]
                   SLATE_pf_GetEgoCurveRaw() : Ego vehicle curve [full range of datatype float32] 
                   EGO_CURVE_ERROR_RAW : Ego vehicle curve error [0.f ... 1.f] 
  @glob_out        -

  @c_switch_part   ALGO_CFG_FarScanAvailable : true if separate far scan cluster lists are available
  @c_switch_part   APM_USE_ELEVATION_DEGR_DIST : Switch activates the elevation range in the degradation concept
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         20.10.2014
  @changed         23.11.2015

  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
static void  APM_v_CalcMaxDist( APM_Degradation_t * p_a_Degradation, APM_MaxDist_t * p_a_DegrDist, const APM_ThresQuotas_t * p_a_ThresQuota,  boolean b_PerfDist)
{ 
#if (!APM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION)
  float32 f_EgoCurve, f_EgoCurveErr, f_EgoCurveMax, f_EgoCurveRaw;
#endif
  float32 f_vdy_tmp, f_aln_tmp, f_lat_tmp;
  float32 f_SqrtAttribute;
  float32 f_DeadjustAngle, f_DeadjustAngleStdDev;
  float32 f_VDYQuota, f_ALNQuota; 
  

  f_DeadjustAngle       = 0.f;
  f_DeadjustAngleStdDev = 0.f;

  /* the ALN values from the NVM shall be used to calculate the performance distance! */
  if (b_PerfDist == TRUE)
  {
    /*maximum from near- and far-scan*/
#if (ALGO_CFG_FarScanAvailable)
    {
      f_DeadjustAngleStdDev = MAX_FLOAT(ALN_MON_INPUT_PTR->a_CurrentAzimuthStd[0], ALN_MON_INPUT_PTR->a_CurrentAzimuthStd[1]);  
    }
#else
    {
#if (ALN_MONITORING_VERSION >= 100)
      f_DeadjustAngleStdDev = ALN_MON_INPUT_PTR->Azimuth.f_DegradationComfortStd;
#else
      f_DeadjustAngleStdDev = ALN_MON_INPUT_PTR->a_CurrentAzimuthStd[0];
#endif
    }
#endif
  }
  /* the ALN values from the ALN-monitoring shall be used to calculate the safety distance! */
  else
  {
#if (ALGO_CFG_FarScanAvailable)
    {
      float32 f_DeadjustAngleNear, f_DeadjustAngleFar;
      f_DeadjustAngleNear = fABS(ALN_MON_INPUT_PTR->Azimuth[0].f_Misalignment) + (2.f * ALN_MON_INPUT_PTR->Azimuth[0].f_Std);
      f_DeadjustAngleFar  = fABS(ALN_MON_INPUT_PTR->Azimuth[1].f_Misalignment) + (2.f * ALN_MON_INPUT_PTR->Azimuth[1].f_Std);
      f_DeadjustAngle = MAX_FLOAT(f_DeadjustAngleNear, f_DeadjustAngleFar);
    }
#else
    {
#if (ALN_MONITORING_VERSION >= 100)
      f_DeadjustAngle = fABS(ALN_MON_INPUT_PTR->Azimuth.DegradationSafety.f_Misalignment);
      f_DeadjustAngleStdDev = ALN_MON_INPUT_PTR->Azimuth.DegradationSafety.f_Std;
#else
      f_DeadjustAngle = fABS(ALN_MON_INPUT_PTR->Azimuth[0].f_Misalignment);
      f_DeadjustAngleStdDev = ALN_MON_INPUT_PTR->Azimuth[0].f_Std;  
#endif
    }
#endif
  }
  
  f_DeadjustAngle = f_DeadjustAngle + ( 2.f * f_DeadjustAngleStdDev );

   #if (!APM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION)
  f_EgoCurveRaw = *SLATE_pf_GetEgoCurveRaw();
  f_EgoCurve = fABS(f_EgoCurveRaw);
  f_EgoCurveErr = fABS(EGO_CURVE_ERROR_RAW);
  f_EgoCurveMax = f_EgoCurve + f_EgoCurveErr;
#endif

/* This will make degradation independent of VDY Curve Error
   In ARS510GM18, the curve is not calculated by VDY, but is given
   directly by the customer. This makes it difficult to calculate a 
   proper VDY curve error and the error we get from VDY is always
   high enough to severely bring down the APM safety distance. 
   Therefore, VDY curve error is not considered under those circumstances */
#if (APM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION)
  f_vdy_tmp = 0.f;
#else
  f_vdy_tmp = (( f_EgoCurveMax / 2.f ) - ( f_EgoCurve / 2.f));
#endif
  
  /*prevent an overflow at the beginning of the monitoring through the high number in the variable*/
  f_aln_tmp = MIN_FLOAT(C_PI, f_DeadjustAngle);
   
  f_lat_tmp = p_a_ThresQuota->f_MaxLatDist;
  

  /*calculate the longitudinal distance for a given lateral error*/

  /*if there is no VDY error just consider ALN */
  if( (f_vdy_tmp <= APM_f_Delta) &&   (f_aln_tmp >= APM_f_Delta)) 
  {
      p_a_DegrDist->f_MaxDist = p_a_ThresQuota->f_MaxLatDist / f_aln_tmp;
      p_a_DegrDist->f_MaxDistALN = p_a_ThresQuota->f_MaxLatDistALN / f_aln_tmp;                         /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
      p_a_DegrDist->f_MaxDistVDY = 0.f; 
  }
  /*if there is no ALN error just consider VDY */
  else if((f_vdy_tmp >= APM_f_Delta) && (f_aln_tmp <= APM_f_Delta))
  {
    /*parabolic approximation is used*/
    p_a_DegrDist->f_MaxDist = SQRT(p_a_ThresQuota->f_MaxLatDist / f_vdy_tmp); 
    p_a_DegrDist->f_MaxDistALN = 0.f;                                                             /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
    p_a_DegrDist->f_MaxDistVDY = SQRT(p_a_ThresQuota->f_MaxLatDistVDY / f_vdy_tmp);
  }
  /*if there is no ALN error and no VDY error -> not possible*/
  else if((f_vdy_tmp <= APM_f_Delta) && (f_aln_tmp <= APM_f_Delta))
  {
    p_a_DegrDist->f_MaxDist = 0.f; 
    p_a_DegrDist->f_MaxDistALN = 0.f; 
    p_a_DegrDist->f_MaxDistVDY = 0.f;                                                        /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
  }
  /*if there is a ALN error and a VDY error consider both*/
  else
  {
    /*calculate the fused distance (ALN and VDY)*/
    /*check if the square root is not negative*/
    f_SqrtAttribute = SQR(f_aln_tmp) + (4.f * (f_vdy_tmp * f_lat_tmp));
    if(f_SqrtAttribute > 0.f)  
    {
      /*for vdy there is a parabolic approximation used*/
      p_a_DegrDist->f_MaxDist = ((-f_aln_tmp) + SQRT(f_SqrtAttribute)) / (2.f * f_vdy_tmp);      
    }
    else
    {
      p_a_DegrDist->f_MaxDist = 0.f;
    }
    
    /*calculate the separated ALN distance*/
    /*check division by zero*/                                                                         /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
    if (f_aln_tmp >= APM_f_Delta)
    {
       p_a_DegrDist->f_MaxDistALN = p_a_ThresQuota->f_MaxLatDistALN / f_aln_tmp;                               
    }
    else
    {
      p_a_DegrDist->f_MaxDistALN = 0.f;
    }

    /*calculate the separated VDY distance*/
    /*check division by zero*/                                                                         /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
    if (f_vdy_tmp >= APM_f_Delta)
    {
      p_a_DegrDist->f_MaxDistVDY = SQRT(p_a_ThresQuota->f_MaxLatDistVDY / f_vdy_tmp);                               
    }
    else
    {
      p_a_DegrDist->f_MaxDistVDY = 0.f;
    }
   
  }  
  
  /*calculate the respective lateral errors for a given longitudinal distance*/
  f_VDYQuota = SQR(p_a_DegrDist->f_MaxDist) * f_vdy_tmp;
  f_ALNQuota = p_a_DegrDist->f_MaxDist * f_aln_tmp; 

    
  /*store the quotas*/
  if(b_PerfDist == TRUE)
  {
    p_a_Degradation->a_QuotasPerf.f_MaxLatDist   = p_a_ThresQuota->f_MaxLatDist;
    p_a_Degradation->a_QuotasPerf.f_MaxQuotaVDY  = f_VDYQuota;
    p_a_Degradation->a_QuotasPerf.f_MaxQuotaALN  = f_ALNQuota;
  }
  else
  {
    /* dummy else for QAC */
  }


  /*Consider elevation misalignment*/      
#if (APM_USE_ELEVATION_DEGR_DIST)
  if( (b_PerfDist == FALSE) && (ALN_MON_INPUT_PTR->u_VersionNumber > 4u) )                                           /* just for the safety distance */
  {
    /*Take the minimum out of fused/azimuth and elevation distance*/
    p_a_DegrDist->f_MaxDist    = MIN_FLOAT(p_a_DegrDist->f_MaxDist, ALN_MON_INPUT_PTR->f_ObstacleRangeMax);
    p_a_DegrDist->f_MaxDistALN = MIN_FLOAT(p_a_DegrDist->f_MaxDistALN, ALN_MON_INPUT_PTR->f_ObstacleRangeMax);
    p_a_DegrDist->f_MaxDistELV = ALN_MON_INPUT_PTR->f_ObstacleRangeMax;
  }
#endif

  return;
}


/*************************************************************************************************************************
  Functionname:    APM_f_CalcMinPerfDist                                                                            */ /*!

  @brief           Calculates the minimal required performance distance

  @description     Calculates the minimal required performance distance based on worst case scenarios

  @startuml 
    Partition APM_f_CalcMinPerfDist
    Start
    Note right: This function calculates \n the minimal required performance distance \n based on worst case scenarios
    - Update Ego Velocity and Target velocity
    - Calculate Time until the velocity of the ego-vehicle \n and the target-vehicle are the same 
    - Calculate minimal performance distance based on the Ego velocity, \n worst case target’s velocity and worst case driver’s reaction
    End
  @enduml

  @return          f_MinPerfDist :  Minimal required performance distance [full range of datatype float32]

  @param[in]       - 

  @glob_in         EGO_SPEED_X_RAW : Ego vehicle speed [0.f ... 128.f]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.11.2015
  @changed         24.11.2015


  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
static float32 APM_f_CalcMinPerfDist(void)
{ 
  float32 f_MinPerfDist;
  float32 f_vEgo;
  float32 f_vTarget;
  float32 f_t; 
  float32 f_tReak;
 
  
  f_vEgo = fABS(EGO_SPEED_X_RAW);
  f_vTarget = f_vEgo * APM_MIN_PERF_DIST_V_DIFF_MAX;
  f_tReak = APM_MIN_PERF_DIST_T_REAK;

  /*Time until the velocity of the ego- and the target-vehicle are the same*/
  f_t = (f_vEgo + (APM_MIN_PERF_DIST_A_EGO_MAX * f_tReak) - f_vTarget) / (APM_MIN_PERF_DIST_A_EGO_MAX - APM_MIN_PERF_DIST_A_TARGET_MAX);

  /*difference between the distance from the ego-vehicle to adapt the velocity from the target-vehicle and the driven distance from the target-vehicle in the same time*/
  f_MinPerfDist = (f_vEgo * f_tReak) - (0.5f * APM_MIN_PERF_DIST_A_EGO_MAX * SQR((f_t-f_tReak))) + (f_vEgo * (f_t-f_tReak)) + (0.5f * APM_MIN_PERF_DIST_A_TARGET_MAX * SQR(f_t)) - (f_vTarget * f_t);

  return f_MinPerfDist;
}


/*************************************************************************************************************************
  Functionname:    APM_v_DegrSetDEMEvents                                                                           */ /*!

  @brief           DEM event management

  @description     DEM event management

  @startuml 
    Partition APM_v_DegrSetDEMEvents
    Start
    Note right: This function checks loud degradation for ACC
    - Set all the error states to inactive and Loud Degradation to False
    - Shift ACC Degradation field left by 1 bit
    If (Maximum distance of Degaradation Performance Distance &lt; minimal Performance Distance) Then (True)
      - Update ACC Degradation field
      - Calculate number of bits set in ACC Degradation field
      If (Number of bits set in ACC Degradation field &gt;= 5 ) Then (True)
        If (Calcuated Alignment quota &gt; Maximum Alignment quota) Then (True)
          - Set Azimuth Degradation error state to active and Loud Degradation to True
        Elseif (Calcuated VDY quota &gt; Maximum VDY quota) Then (True)
          - Set VDY Degradation error state to active and Loud Degradation to True
        Else (False)
        Endif
      Else (False)
      Endif
    Else (False)
    Endif
    End
  @enduml

  @return          -

  @param[in]       - 

  @glob_in         t_APM_DegData : Global signal performance monitoring data
                      SPMDegradationACC                                   [full range of datatype uint32 with >= 0u ]
                      a_DegradationACC.a_QuotasPerf.f_MaxQuotaALN         [full range of datatype float32 with >= 0u ]
                      a_DegradationACC.a_QuotasPerf.f_MaxQuotaVDY         [full range of datatype float32 with >= 0u ]
                      a_DegradationACC.a_DegrDistPerf.f_MaxDist           [full range of datatype float32]
                      a_DegradationACC.f_MaxDistPerfMin                   [full range of datatype float32]
                      SPMDegradationACC                                   [full range of datatype uint32]
  @glob_out        t_APM_DegData : Global signal performance monitoring data
                      a_DegradationACC.b_LoudDegrdation                   [TRUE, FALSE]
                      a_DegradationEBA.b_LoudDegrdation                   [TRUE, FALSE]

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.12.2015
  @changed         01.12.2015


  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
static void APM_v_DegrSetDEMEvents(void)
{
  sint32 BitCnt15 = 0;

  /*set error states to inactive*/
  APM_v_SetErrorState( APM_ERREV_ACC_DEGRADATION_AZ,AL_ERR_STATE_INACTIVE);
  APM_v_SetErrorState( APM_ERREV_ACC_DEGRADATION_EL,AL_ERR_STATE_INACTIVE);
  APM_v_SetErrorState( APM_ERREV_ACC_DEGRADATION_VDY,AL_ERR_STATE_INACTIVE);
  t_APM_DegData.a_DegradationACC.b_LoudDegrdation = False;
  //SPMData.a_DegradationEBA.b_LoudDegrdation = False;

  /* shift Degradation-field */
  t_APM_DegData.SPMDegradationACC <<= 1;

  /*Check loud degradation for ACC*/
  if(t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDist < t_APM_DegData.a_DegradationACC.f_MaxDistPerfMin)
  {
    t_APM_DegData.SPMDegradationACC |= 1u;
    BitCnt15 = CML_s_CountNrOfBitsSet(t_APM_DegData.SPMDegradationACC & APM_CYCLES_MASK_15);
    
    if(BitCnt15 >= APM_DEGR_EVENTCOUNT)
    {
      /*check if ALN or VDY have exceeded its quota*/ 
      if( t_APM_DegData.a_DegradationACC.a_QuotasPerf.f_MaxQuotaALN > APM_ACC_PERF_ALN_MAX_QUOTA )
      {
        APM_v_SetErrorState( APM_ERREV_ACC_DEGRADATION_AZ,AL_ERR_STATE_ACTIVE);
        t_APM_DegData.a_DegradationACC.b_LoudDegrdation = True;
      }
      else if( t_APM_DegData.a_DegradationACC.a_QuotasPerf.f_MaxQuotaVDY > APM_ACC_PERF_VDY_MAX_QUOTA )
      {
        APM_v_SetErrorState( APM_ERREV_ACC_DEGRADATION_VDY,AL_ERR_STATE_ACTIVE);
        t_APM_DegData.a_DegradationACC.b_LoudDegrdation = True;
      }
      else
      {
        /* everything is OK, nothing to do*/
      }
    } 
  }
}


/*************************************************************************************************************************
  Functionname:    APM_f_GetMaxDistPerfACC                                                                          */ /*!

  @brief           Get ACC performance distance

  @description     Get ACC performance distance, accessible from other modules.

  @startuml 
    Partition APM_f_GetMaxDistPerfACC
    Start
    - This function returns ACC performance distance, accessible from other modules
    End
  @enduml

  @return          fDistance_t : ACC performance distance [full range of datatype float32 with >= 0u ]

  @param[in]       -

  @glob_in         t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDist : Static ACC performance distance [full range of datatype float32 with >= 0u ]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.12.2015
  @changed         01.12.2015


  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
fDistance_t APM_f_GetMaxDistPerfACC (void)
{
  return t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDist;
}


/*************************************************************************************************************************
  Functionname:    SPM_f_GetMaxDistPerfEBA                                                                          */ /*!

  @brief           Get EBA performance distance 

  @description     Get EBA performance distance, accessible from other modules.

  @return          fDistance_t : EBA performance distance [full range of datatype float32 with >= 0u ]

  @param[in]       -

  @glob_in         SPMData.a_DegradationEBA.a_DegrDistPerf.f_MaxDist : Static EBA performance distance [full range of datatype float32 with >= 0u ]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.12.2015
  @changed         01.12.2015


  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
//fDistance_t SPM_f_GetMaxDistPerfEBA (void)
//{
//  return SPMData.a_DegradationEBA.a_DegrDistPerf.f_MaxDist;
//}


/*************************************************************************************************************************
  Functionname:    APM_f_GetMaxDistPerfMinACC                                                                          */ /*!

  @brief           Get ACC minimal performance distance 

  @description     Get ACC minimal performance distance, accessible from other modules. 

  @startuml 
    Partition APM_f_GetMaxDistPerfMinACC
    Start
    - This function returns ACC minimal performance distance, accessible from other modules
  End
  @enduml

  @return          fDistance_t : ACC minimal performance distance [full range of datatype float32 with >= 0u ]

  @param[in]       -

  @glob_in         t_APM_DegData.a_DegradationACC.f_MaxDistPerfMin : Static ACC minimal performance distance [full range of datatype float32 with >= 0u ]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.12.2015
  @changed         01.12.2015


  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
fDistance_t APM_f_GetMaxDistPerfMinACC (void)
{
  return t_APM_DegData.a_DegradationACC.f_MaxDistPerfMin;
}


/*************************************************************************************************************************
  Functionname:    SPM_f_GetMaxDistPerfMinEBA                                                                          */ /*!

  @brief           Get EBA minimal performance distance

  @description     Get EBA minimal performance distance, accessible from other modules. 

  @return          fDistance_t : EBA minimal performance distance[full range of datatype float32 with >= 0u ]

  @param[in]       -

  @glob_in         t_APM_DegData.a_DegradationEBA.f_MaxDistPerfMin : Static EBA minimal performance distance [full range of datatype float32 with >= 0u ]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.12.2015
  @changed         01.12.2015


  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
//fDistance_t SPM_f_GetMaxDistPerfMinEBA (void)
//{
//  return SPMData.a_DegradationEBA.f_MaxDistPerfMin;
//}



/*************************************************************************************************************************
  Functionname:    SPM_f_GetMaxDistPerfALN                                                                          */ /*!

  @brief           Get EBA performance distance (ALN only)

  @description     Get EBA performance distance (ALN only), accessible from other modules.

  @return          fDistance_t : EBA performance distance (ALN only) [full range of datatype float32 with >= 0u ]

  @param[in]       - 

  @glob_in         SPMData.a_DegradationEBA.a_DegrDistPerf.f_MaxDistALN : Static EBA performance distance (ALN only) [full range of datatype float32 with >= 0u ]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.12.2015
  @changed         01.12.2015


  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
//fDistance_t SPM_f_GetMaxDistPerfALN (void)
//{
//  return SPMData.a_DegradationEBA.a_DegrDistPerf.f_MaxDistALN;
//}


/*************************************************************************************************************************
  Functionname:    APM_f_GetMaxDistPerfACC_ALN                                                                          */ /*!

  @brief           Get ACC performance distance (ALN only)

  @description     Get ACC performance distance (ALN only), accessible from other modules.

  @startuml 
    Partition APM_f_GetMaxDistPerfACC_ALN
    Start
      - This function returns Get ACC performance distance (ALN only), accessible from other modules
    End
  @enduml

  @return          fDistance_t : ACC performance distance (ALN only) [full range of datatype float32 with >= 0u ]

  @param[in]       - 

  @glob_in         t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistALN : Static ACC performance distance (ALN only) [full range of datatype float32 with >= 0u ]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SLATE_CFG_ACC_PERF_MONITORING : FCT switch for ACC Performance Monitoring (APM)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.12.2015
  @changed         01.12.2015


  @author          Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
fDistance_t APM_f_GetMaxDistPerfACC_ALN (void)
{
  return t_APM_DegData.a_DegradationACC.a_DegrDistPerf.f_MaxDistALN;
}
///@}
#endif /*!< SLATE_CFG_ACC_PERF_MONITORING */

