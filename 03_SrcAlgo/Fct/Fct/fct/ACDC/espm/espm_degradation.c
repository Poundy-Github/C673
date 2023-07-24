/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ESPM (EBA Signal Performance Monitoring)

PACKAGENAME:               espm_degradation.c

DESCRIPTION:               Implementation of the ESPM process

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/07/20 07:32:31CEST $

VERSION:                   $Revision: 1.29 $

**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "espm_int.h"

#if (ACDC_CFG_ESPM)
/*****************************************************************************
  INCLUDES
*****************************************************************************/
/*!
@defgroup espm_degradation Degradation
@ingroup espm

@brief          The module degradation evaluates the current alignment.
                It writes the result to the output structure in the hypotheses interface.\n\n
@description    The following functionalities are provided by the module:
                - Initialize the degradation data : @ref ESPM_v_InitDegradationData
                - Calculate the current performance degradation : @ref ESPM_v_PerfDegradation
                - Initialize the ESPM output interface : @ref ESPM_v_InitOutput
                - Freezing of the main global variable for MTS : @ref ESPM_v_MeasFreezeDegradationData
                - Write the degradation information to the output interface : @ref ESPM_v_FillOutputports
@{
*/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/



/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

#if (ESPM_CFG_USE_SPM_OUTPUT)
static void  ESPM_v_CalcMaxDist( ESPM_Degradation_t *p_Degradation, ESPM_MaxDist_t* p_DegrDist, const ESPM_ThresQuotas_t *p_ThresQuota,  boolean b_PerfDist );
#else
static fDistance_t ESPMCalcMaxDistHRZ( fDistance_t fMaxLatErrDist, fDistance_t fMaxDist );
#endif
static fDistance_t ESPMCalcMaxDistVIS( fDistance_t fMaxDist );

#if (ESPM_CFG_USE_SPM_OUTPUT)
static fDistance_t ESPM_f_GetMaxDistSafeALN(void);
#if(FCT_HYPOTHESIS_INTFVER >= 0x00001F)
static fDistance_t ESPM_f_GetMaxDistSafeVDY(void); 
#endif
static fDistance_t ESPM_f_GetMaxDistPerfEBA(void);
static fDistance_t ESPM_f_GetMaxDistPerfALN(void);
static fDistance_t ESPM_f_GetMaxDistSafeEBA(void);
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         ESPM_v_FillOutputports                                                                       */ /*!

  @brief                Fills the degradation information of the hypotheses interface (@ref ACDC_pHypotheses).

  @description          Fills the degradation information of the hypotheses interface (@ref ACDC_pHypotheses).
                        Therefore the function follows the subsequent steps:
                        @startuml ESPM_v_FillOutputports_activity.png
                        start
partition #LightBlue **ESPM_CFG_USE_SPM_OUTPUT** {
                          :Get MaxDist for safety and performance and write
                          them to the output structure;
}
partition #LightBlue **!ESPM_CFG_USE_SPM_OUTPUT** {
                          #Orange: Calculate MaxDistVis:
                          <b>ESPMCalcMaxDistVIS</b> >
                          #Orange:Calculate and smooth MaxDistHRZ
                          <b>ESPMCalcMaxDistHRZ</b> >
                          :Change mapping of distances>;
}
partition #LightBlue **ESPM_USE_CUST_SAFETY_DIST** {
                          if (Safety Distance is less than <b>ESPM_SAFETY_DISTANCE_INIT_VALUE</b> ?) then (Yes)
                            #Orange:Set Safety Distance as <b>ESPM_SAFETY_DISTANCE_INIT_VALUE</b> and state as <b>AL_SIG_STATE_INIT</b>;
                          endif
}

                        stop
                        @enduml

  @return               void

  @param[out]           pOutputData : Pointer to the output data containing information about the current degradation state
  @param[out]           pErrorOut   : Pointer to the error data containing information about the current degradation state

  @glob_in              @ref ESPM_f_GetMaxDistSafeEBA \n
                        @ref ESPM_f_GetMaxDistSafeALN \n
                        @ref ESPM_f_GetMaxDistSafeVDY \n 
                        @ref ESPM_f_GetMaxDistPerfEBA \n
                        @ref ESPM_f_GetMaxDistPerfALN \n
                        @ref ESPMCalcMaxDistVIS       \n
                        @ref ESPMCalcMaxDistHRZ  
  @glob_out             None

  @c_switch_part        @ref ESPM_CFG_USE_SPM_OUTPUT\n
                        @ref ESPM_USE_CUST_SAFETY_DIST\n
                        @ref FCT_HYPOTHESIS_INTFVER
  @c_switch_full        @ref ACDC_CFG_ESPM

  @pre                  None
  @post                 Customer specific performance degradation information is set.

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_V_FILLOUTPUTPORTS_001

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
void ESPM_v_FillOutputports(HypoIntfDegr_t  *pOutputData, ACDCErrorOutProPort_t *pErrorOut)
{
#if (ESPM_CFG_USE_SPM_OUTPUT)

  pOutputData->Safety.fMaxDist    = ESPM_f_GetMaxDistSafeEBA();
  pOutputData->Safety.fMaxDistALN = ESPM_f_GetMaxDistSafeALN();
#if(FCT_HYPOTHESIS_INTFVER >= 0x00001F)
  pOutputData->Safety.fMaxDistVDY = ESPM_f_GetMaxDistSafeVDY(); 
#endif
  pOutputData->Safety.fMaxDistVIS = 0.0F;
  pOutputData->Safety.fMaxDistHRZ = 0.0F;
  pOutputData->Performance.fMaxDist    = ESPM_f_GetMaxDistPerfEBA();
  pOutputData->Performance.fMaxDistALN = ESPM_f_GetMaxDistPerfALN();
  pOutputData->Performance.fMaxDistVIS = ESPMCalcMaxDistVIS( ESPM_PERF_DEG_MAX_DIST ); 
  pOutputData->Performance.fMaxDistHRZ = 0.0F;

#else
  fDistance_t fDist = ESPMCalcMaxDistHRZ( ESPM_PERF_DEG_MAX_LAT_ERR_DIST_SFTY, ESPM_PERF_DEG_MAX_DIST ); 
  /* calculate safety distances */

  pOutputData->Safety.fMaxDistALN = ESPM_PERF_DEG_MAX_DIST;
#if(FCT_HYPOTHESIS_INTFVER >= 0x00001F)
  pOutputData->Safety.fMaxDistVDY = ESPM_PERF_DEG_MAX_DIST; 
#endif

  /* QAC-Fix: transposed from fDist = ( 1 - CD_PERF_DEG_HRZ_DIST_PT1_CONST ) * pOutputData->pDegradation->Safety.fMaxDistHRZ + CD_PERF_DEG_HRZ_DIST_PT1_CONST * fDist */
  fDist = pOutputData->Safety.fMaxDistHRZ + ( ESPM_PERF_DEG_HRZ_DIST_PT1_CONST * ( fDist - pOutputData->Safety.fMaxDistHRZ ));
  pOutputData->Safety.fMaxDistHRZ = fDist;
  pOutputData->Safety.fMaxDistVIS = ESPMCalcMaxDistVIS( ESPM_PERF_DEG_MAX_DIST );
  /* @attention: If the function shall take the other monitors into account, change here */
  pOutputData->Safety.fMaxDist = pOutputData->Safety.fMaxDistALN;
  pOutputData->Performance.fMaxDistALN = ESPM_PERF_DEG_MAX_DIST;

  fDist = ESPMCalcMaxDistHRZ( ESPM_PERF_DEG_MAX_LAT_ERR_DIST_PERF, ESPM_PERF_DEG_MAX_DIST ); 
  /* QAC-Fix: transposed from fDist = ( 1 - CD_PERF_DEG_HRZ_DIST_PT1_CONST ) * pOutputData->pDegradation->Performance.fMaxDistHRZ + CD_PERF_DEG_HRZ_DIST_PT1_CONST * fDist */
  fDist = pOutputData->Performance.fMaxDistHRZ + ( ESPM_PERF_DEG_HRZ_DIST_PT1_CONST * ( fDist - pOutputData->Performance.fMaxDistHRZ ));
  pOutputData->Performance.fMaxDistHRZ = fDist;

  pOutputData->Performance.fMaxDistVIS = ESPMCalcMaxDistVIS( ESPM_PERF_DEG_MAX_DIST );
  /* @attention: If the function shall take the other monitors into account, change here */
  pOutputData->Performance.fMaxDist = pOutputData->Performance.fMaxDistALN;

#endif

  /* Fill error out. */
  pErrorOut->fSafetyDistanceEBA      = pOutputData->Safety.fMaxDist;
  pErrorOut->eSafetyDistanceEBAState = AL_SIG_STATE_OK;
#if(ESPM_USE_CUST_SAFETY_DIST)
  if (pOutputData->Safety.fMaxDist < ESPM_SAFETY_DISTANCE_INIT_VALUE)
  {
      pOutputData->Safety.fMaxDist       = ESPM_SAFETY_DISTANCE_INIT_VALUE;
      pErrorOut->fSafetyDistanceEBA      = ESPM_SAFETY_DISTANCE_INIT_VALUE;
      /* Fill eSafetyDistStateEBA according to the value of tSafetyDistanceEBA */
      pErrorOut->eSafetyDistanceEBAState = AL_SIG_STATE_INIT;
  }
#endif
}

#if (ESPM_CFG_USE_SPM_OUTPUT)
/*************************************************************************************************************************
  Functionname:         ESPM_v_PerfDegradation                                                                       */ /*!

  @brief                Main function to coordinate the calculations for the performance degradation.

  @description          Main function to coordinate the calculations for the performance degradation. 
                        Based on the performance degradation a maximum distance is determined for which  \n
                        a function shall work. This calculation is executed by the function @ref ESPM_v_CalcMaxDist.
                        The function follows the subsequent steps:
                        @startuml ESPM_v_PerfDegradation_activity.png
                        start
                          :Get current Alignment state;
                          :Set default safety and performance 
                          distance values;
                          #Orange:Calculate maximum distance 
                          for performance functions
                          <b>ESPM_v_CalcMaxDist</b> >
                          #Orange:Calculate maximum distance 
                          for safety functions
                          <b>ESPM_v_CalcMaxDist</b> >
                          :Set Maximum distances to 0 in 
                          case of unsafe alignment state;
                        stop
                        @enduml

  @return               void

  @param[in]            void

  @glob_in              @ref ACDC_p_GetAlnMonInput -> e_AlignState : State of the alignment component [e_AlignState_t as in Rte_Type.h]
  @glob_out             @ref ACDC_p_ModPerformanceDegrationData
                        - DegradationEBA.DegrDistPerf.f_MaxDist,    @phys_unit [m], @range [0,+...[
                        - DegradationEBA.DegrDistPerf.f_MaxDistALN  @phys_unit [m], @range [0,+...[
                        - DegradationEBA.DegrDistSafe.f_MaxDist     @phys_unit [m], @range [0,+...[
                        - DegradationEBA.DegrDistSafe.f_MaxDistALN  @phys_unit [m], @range [0,+...[
                        - DegradationEBA.b_LoudDegradation
                        
  @c_switch_part        None
  @c_switch_full        @ref ESPM_CFG_USE_SPM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_V_PERFDEGRADATION_001\n
                        @ref TEST_ESPM_V_PERFDEGRADATION_002

  @traceability         Design Decision

  @author               Bjoern Hackel | bjoern.hackel@continental-corporation.com | +49 (8382) 9699-477
*************************************************************************************************************************/
void ESPM_v_PerfDegradation(void)
{
  ESPM_ThresQuotas_t        EBASafeThresQuotas, EBAPerfThresQuotas;
  ESPM_Degradation_t *const pPerfDegrEBA = &(ACDC_p_ModPerformanceDegrationData()->DegradationEBA);
  e_AlignState_t            e_AlignState = ACDC_p_GetAlnMonInput()->e_AlignState;
  
  EBASafeThresQuotas.f_MaxLatDist     = ESPM_MAX_LAT_DIST_SAFE;
  EBASafeThresQuotas.f_MaxLatDistALN  = ESPM_MAX_LAT_DIST_SAFE_ALN;
  EBASafeThresQuotas.f_MaxLatDistVDY  = ESPM_MAX_LAT_DIST_SAFE_VDY;

  EBAPerfThresQuotas.f_MaxLatDist     = ESPM_MAX_LAT_DIST_PERF;
  EBAPerfThresQuotas.f_MaxLatDistALN  = ESPM_MAX_LAT_DIST_PERF_ALN;
  EBAPerfThresQuotas.f_MaxLatDistVDY  = ESPM_MAX_LAT_DIST_PERF_VDY;

  ESPM_v_CalcMaxDist( pPerfDegrEBA, &pPerfDegrEBA->DegrDistPerf, &EBAPerfThresQuotas, TRUE);
  
  ESPM_v_CalcMaxDist( pPerfDegrEBA, &pPerfDegrEBA->DegrDistSafe, &EBASafeThresQuotas, FALSE );

  if(e_AlignState != ALNMonNormal)
  {  
    pPerfDegrEBA->DegrDistPerf.f_MaxDist = 0.f;
    pPerfDegrEBA->DegrDistPerf.f_MaxDistALN = 0.f;
    pPerfDegrEBA->DegrDistSafe.f_MaxDist = 0.f;
    pPerfDegrEBA->DegrDistSafe.f_MaxDistALN = 0.f;
    pPerfDegrEBA->b_LoudDegrdation = TRUE;
  }
  else
  {
     pPerfDegrEBA->b_LoudDegrdation = FALSE;
  }
}

/*************************************************************************************************************************
  Functionname:         ESPM_v_CalcMaxDist                                                                           */ /*!

  @brief                Calculates the max allowed x dist based on ALN-, VDY data and the max. allowed lateral deviation

  @description          This function calculates the maximum allowed X distance based on Alignment, VDY data and the maximum 
                        allowed lateral deviation. b_PerfDist decides wheter the Performance distance (true) or the Safety \n
                        distance (false) shall be calculated
                        @startuml ESPM_v_CalcMaxDist_activity.png
                        start

                        if (b_PerfDist) Then (True)
                          :1}
                          :Calculate Deadjustment Angle and its Std 
                          Deviation on base of performance data;
                          note left:>see formula **Angle Performance**
                        else (False)
                          :2}
                          :Calculate Deadjustment Angle and its Std 
                          Deviation on base of safety data;
                          note left:>see formula **Angle Safety**
                        endif

                        :Calculate Error_ALN;
                        note left: >see formula **Error ALN**
partition #LightBlue **!ESPM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION** {
                        :Calculate Error_VDY;
                        note left: >see formula **Error VDY**
}
partition #LightBlue **ESPM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION** {
                        :Reset Error_VDY;
}
                        :Calculate MaxDistALN;
                        note left:>see formula **MaxDistALN**

                        :Calculate MaxDistVDY;
                        note left:>see formula **MaxDistVDY**

                        :Calculate MaxDist;
                        note left:>see formula **MaxDist**

                        :Calculate the ALN and VDY Quotas;
                        note left:>see formula **Quotas**

                        if (b_PerfDist) Then (True)
                          :3}
                          :Store the Quotas and the Max dist in the Performance 
                          section of the degradation data;
                        else (False)
                          :4}
                          :Store the Quotas and the Max dist in the Safety
                          section of the degradation data;
                        endif

partition #LightBlue **ESPM_USE_ELEVATION_DEGR_DIST** {
                        if (b_PerfDist) Then (False)
                          :5}
                          :Limit the MaxDist and MaxDistALN to maximum Alignment ObstacleRangeMax, 
                          Set MaxDistELV to Alignment ObstacleRangeMax;
                        else (True)
                          :6}
                        endif
}
                        stop
                        @enduml

  @return               void


  @param[in,out]        *p_Degradation : Current lateral errors.
  @param[in,out]        *p_DegrDist :    Max ranges based on the max allowed lateral errors and the respective module error. @phys_unit [m] @range [0,+...[
  @param[in]            *p_ThresQuota :  The max. allowed lateral error for the different distances.
  @param[in]            b_PerfDist :     Flag indicating whether a performance (True) or a safety distance (False) shall be calculated.

  @glob_in              @ref ACDC_p_GetAlnMonInput 
                        
  @glob_out             None

  @c_switch_part        @ref ESPM_USE_ELEVATION_DEGR_DIST \n
                        @ref ALN_MONITORING_VERSION \n
                        @ref ALGO_CFG_FarScanAvailable\n
                        @ref ESPM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION

  @c_switch_full        @ref ACDC_CFG_ESPM \n
                        @ref ESPM_CFG_USE_SPM_OUTPUT

  @pre                  Assure that pointers are valid.
  @post                 None

  @InOutCorrelation     
                        - **Angle Performance:**\n
                          - Far Scan available    : \n
                            - \f$\alpha_{StdDev} = MAX(\alpha_{StdDev,Performance,NearRange},\alpha_{StdDev,Performance,FarRange})\f$\n
                            - \f$\alpha          = 2 \cdot alpha_{StdDev,Performance}\f$\n
                          - Far Scan not available: \n
                            - \f$\alpha_{StdDev} = \alpha_{StdDev,Performance,NearRange}\f$\n
                            - \f$\alpha          = 2 \cdot alpha_{StdDev,Performance}\f$
                        - **Angle Safety:**\n
                          - Far Scan available    : \n
                            - \f$\alpha_{StdDev} = 0\f$\n
                            - \f$\alpha          = MAX((\alpha_{Safety,NearRange} + \alpha_{StdDev,Safety,NearRange}),(\alpha_{Safety,FarRange} + \alpha_{StdDev,Safety,FarRange}))\f$ \n
                          - Far Scan not available: \n
                            - \f$\alpha_{StdDev} = \alpha_{StdDev,Safety,NearRange}\f$\n
                            - \f$\alpha          = \alpha_{Safety,NearRange}\f$\n
                        - **Error ALN:**\n
                          - \f$Error_{ALN} = MIN(\pi,\alpha)\f$
                        - **Error VDY:**\n
                          - \f$Error_{VDY} = 0.5 \cdot |VDYError_{Curve}|\f$
                        - **MaxDistALN:**\n
                            - For \f$Error_{ALN} > 0 : D_{Degr,MaxALN} = \frac{D_{Max,Lat,ALN}}{Error_{ALN}}\f$
                            - For \f$Error_{ALN} <= 0 : D_{Degr,MaxALN} = 0\f$
                        - **MaxDistVDY:**\n
                            - For \f$Error_{VDY} > 0 : D_{Degr,MaxVDY} = \sqrt{\frac{D_{Max,Lat,VDY}}{Error_{VDY}}}\f$
                            - For \f$Error_{VDY} <= 0 : D_{Degr,MaxVDY} = 0\f$
                        - **MaxDist:**\n
                                  \f$Discr = Error_{ALN}^2 + 4\cdot Error_{VDY}\cdot D_{Max,Lat}\f$ \n
                            - For \f$Discr <= 0 : D_{Degr,Max} = 0\f$
                            - For \f$Error_{VDY} <= 0 : D_{Degr,Max} = D_{Degr,MaxALN}\f$
                            - For \f$Error_{ALN} <= 0 : D_{Degr,Max} = D_{Degr,MaxVDY}\f$
                            - For \f$Discr > 0 : D_{Degr,Max} = \frac{-Error_{ALN} + \sqrt{Discr}}{2 \cdot Error_{VDY}}\f$ \n
                        - **Quotas:** \n
                          -\f$Quota_{VDY} = D_{Degr,Max} ^2 \cdot Error_{VDY}\f$
                          -\f$Quota_{ALN} = D_{Degr,Max}    \cdot Error_{ALN}\f$

  @testmethod           @ref TEST_ESPM_V_CALCMAXDIST_001 \n
                        @ref TEST_ESPM_V_CALCMAXDIST_002 \n
						@ref TEST_ESPM_V_CALCMAXDIST_003 \n
                        @ref TEST_ESPM_V_CALCMAXDIST_004 \n
						@ref TEST_ESPM_V_CALCMAXDIST_005 \n
                        @ref TEST_ESPM_V_CALCMAXDIST_006 \n
						@ref TEST_ESPM_V_CALCMAXDIST_007 \n
                        @ref TEST_ESPM_V_CALCMAXDIST_008 

  @traceability         Design Decision

  @author               Bjoern Hackel
*************************************************************************************************************************/
static void  ESPM_v_CalcMaxDist( ESPM_Degradation_t *p_Degradation, ESPM_MaxDist_t *p_DegrDist, const ESPM_ThresQuotas_t *p_ThresQuota,  boolean b_PerfDist)
{ 
  float32 f_vdy_tmp, f_aln_tmp, f_lat_tmp;
  float32 f_SqrtAttribute;
  float32 f_DeadjustAngle       = 0.0f;
  float32 f_DeadjustAngleStdDev = 0.0f;
  float32 f_VDYQuota, f_ALNQuota; 
  

  /* the ALN values from the NVM shall be used to calculate the performance distance! */
  if (b_PerfDist == TRUE)
  {
    /*maximum from near- and far-scan*/
#if (ALGO_CFG_FarScanAvailable)
    {
      f_DeadjustAngleStdDev = MAX_FLOAT(ACDC_p_GetAlnMonInput()->a_CurrentAzimuthStd[0], ACDC_p_GetAlnMonInput()->a_CurrentAzimuthStd[1]);
    }
#else
    {
#if (ALN_MONITORING_VERSION >= 100)
      f_DeadjustAngleStdDev = ACDC_p_GetAlnMonInput()->Azimuth.f_DegradationComfortStd;
#else
      f_DeadjustAngleStdDev = ACDC_p_GetAlnMonInput()->a_CurrentAzimuthStd[0];
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
      f_DeadjustAngleNear = fABS(ACDC_p_GetAlnMonInput()->Azimuth[0].f_Misalignment) + (2.f * ACDC_p_GetAlnMonInput()->Azimuth[0].f_Std);
      f_DeadjustAngleFar  = fABS(ACDC_p_GetAlnMonInput()->Azimuth[1].f_Misalignment) + (2.f * ACDC_p_GetAlnMonInput()->Azimuth[1].f_Std);
      f_DeadjustAngle = MAX_FLOAT(f_DeadjustAngleNear, f_DeadjustAngleFar);
    }
#else
    {

#if (ALN_MONITORING_VERSION >= 100)
      f_DeadjustAngle = fABS(ACDC_p_GetAlnMonInput()->Azimuth.DegradationSafety.f_Misalignment);
      f_DeadjustAngleStdDev = ACDC_p_GetAlnMonInput()->Azimuth.DegradationSafety.f_Std;
#else
      f_DeadjustAngle = fABS(ACDC_p_GetAlnMonInput()->Azimuth[0].f_Misalignment);
      f_DeadjustAngleStdDev = ACDC_p_GetAlnMonInput()->Azimuth[0].f_Std;  
#endif
    }
#endif
  }
  
  f_DeadjustAngle = f_DeadjustAngle + ( 2.f * f_DeadjustAngleStdDev );

  /* This will make degradation independent of VDY Curve Error
   In certain projects, the curve is not calculated by VDY, but is given
   directly by the customer. This makes it difficult to calculate a 
   proper VDY curve error and the error we get from VDY is always
   high enough to severely bring down the ESPM safety distance. 
   Therefore, VDY curve error is not considered under those circumstances */
#if (ESPM_CFG_CURVEERROR_INDEPENDENT_DEGRADATION)
  f_vdy_tmp = 0.f;
#else
  f_vdy_tmp = 0.5f * fABS(ACDC_p_GetVDYDynRaw()->Lateral.Curve.CrvError);
#endif

  /*prevent an overflow at the beginning of the monitoring through the high number in the variable*/
  f_aln_tmp = MIN_FLOAT(C_PI, f_DeadjustAngle);
   
  f_lat_tmp = p_ThresQuota->f_MaxLatDist;
  

  /*calculate the longitudinal distance for a given lateral error*/

  /*if there is no VDY error just consider ALN */
  if( (f_vdy_tmp <= ESPM_F_DELTA) &&   (f_aln_tmp >= ESPM_F_DELTA)) 
  {
      p_DegrDist->f_MaxDist = p_ThresQuota->f_MaxLatDist / f_aln_tmp;
      p_DegrDist->f_MaxDistALN = p_ThresQuota->f_MaxLatDistALN / f_aln_tmp;                         /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
      p_DegrDist->f_MaxDistVDY = 0.f; 
  }
  /*if there is no ALN error just consider VDY */
  else if((f_vdy_tmp >= ESPM_F_DELTA) && (f_aln_tmp <= ESPM_F_DELTA))
  {
    /*parabolic approximation is used*/
    p_DegrDist->f_MaxDist = SQRT(p_ThresQuota->f_MaxLatDist / f_vdy_tmp); 
    p_DegrDist->f_MaxDistALN = 0.f;                                                             /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
    p_DegrDist->f_MaxDistVDY = SQRT(p_ThresQuota->f_MaxLatDistVDY / f_vdy_tmp);
  }
  /*if there is no ALN error and no VDY error -> not possible*/
  else if((f_vdy_tmp <= ESPM_F_DELTA) && (f_aln_tmp <= ESPM_F_DELTA))
  {
    p_DegrDist->f_MaxDist = 0.f; 
    p_DegrDist->f_MaxDistALN = 0.f; 
    p_DegrDist->f_MaxDistVDY = 0.f;                                                        /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
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
      p_DegrDist->f_MaxDist = ((-f_aln_tmp) + SQRT(f_SqrtAttribute)) / (2.f * f_vdy_tmp);      
    }
    else
    {
      p_DegrDist->f_MaxDist = 0.f;
    }
    
    /*calculate the separated ALN distance*/
    /*check division by zero*/                                                                         /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
    if (f_aln_tmp >= ESPM_F_DELTA)
    {
       p_DegrDist->f_MaxDistALN = p_ThresQuota->f_MaxLatDistALN / f_aln_tmp;                               
    }
    else
    {
      p_DegrDist->f_MaxDistALN = 0.f;
    }

    /*calculate the separated VDY distance*/
    /*check division by zero*/                                                                         /*should be temporary (backup for the EBA Team if the VDY performance is to bad)*/
    if (f_vdy_tmp >= ESPM_F_DELTA)
    {
      p_DegrDist->f_MaxDistVDY = SQRT(p_ThresQuota->f_MaxLatDistVDY / f_vdy_tmp);                               
    }
    else
    {
      p_DegrDist->f_MaxDistVDY = 0.f;
    }
   
  }  
  
  /*calculate the respective lateral errors for a given longitudinal distance*/
  f_VDYQuota = SQR(p_DegrDist->f_MaxDist) * f_vdy_tmp;
  f_ALNQuota = p_DegrDist->f_MaxDist * f_aln_tmp; 

    
  /*store the quotas*/
  if(b_PerfDist == TRUE)
  {
    p_Degradation->QuotasPerf.f_MaxLatDist   = p_ThresQuota->f_MaxLatDist;
    p_Degradation->QuotasPerf.f_MaxQuotaVDY  = f_VDYQuota;
    p_Degradation->QuotasPerf.f_MaxQuotaALN  = f_ALNQuota;
  }
  else
  {
    p_Degradation->QuotasSafe.f_MaxLatDist   = p_ThresQuota->f_MaxLatDist;
    p_Degradation->QuotasSafe.f_MaxQuotaVDY  = f_VDYQuota;
    p_Degradation->QuotasSafe.f_MaxQuotaALN  = f_ALNQuota;
  }


  /*Consider elevation misalignment*/      
#if (ESPM_USE_ELEVATION_DEGR_DIST)
  if( (b_PerfDist == FALSE) && (ACDC_p_GetAlnMonInput()->u_VersionNumber > 4u) )                                           /* just for the safety distance */
  {
    /*Take the minimum out of fused/azimuth and elevation distance*/
    p_DegrDist->f_MaxDist    = MIN_FLOAT(p_DegrDist->f_MaxDist, ACDC_p_GetAlnMonInput()->f_ObstacleRangeMax);
    p_DegrDist->f_MaxDistALN = MIN_FLOAT(p_DegrDist->f_MaxDistALN, ACDC_p_GetAlnMonInput()->f_ObstacleRangeMax);
    p_DegrDist->f_MaxDistELV = ACDC_p_GetAlnMonInput()->f_ObstacleRangeMax;
  }
#endif

  
  return;
}

/*************************************************************************************************************************
  Functionname:         ESPM_f_GetMaxDistPerfEBA                                                                     */ /*!

  @brief                Returns the maximum activation distance for performance functions.

  @return               fDistance_t : Maximum distance for performance functions. @phys_unit [m] @range [0,+...[

  @param[in]            void

  @glob_in              @ref PerformanceDegrationData
  @glob_out             @ref PerformanceDegrationData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_ESPM \n
                        @ref ESPM_CFG_USE_SPM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_F_GETMAXDISTPERFEBA_001

  @traceability         Design Decision

  @author               Bjoern Hackel
*************************************************************************************************************************/
static fDistance_t ESPM_f_GetMaxDistPerfEBA (void)
{
  return ACDC_p_GetPerformanceDegrationData()->DegradationEBA.DegrDistPerf.f_MaxDist;
}

/*************************************************************************************************************************
  Functionname:         ESPM_f_GetMaxDistPerfALN                                                                     */ /*!

  @brief                Returns the maximum activation distance for performance functions based on alignment information.

  @return               fDistance_t : Maximum distance for performance functions. @phys_unit [m] @range [0,+...[

  @param[in]            void

  @glob_in              @ref PerformanceDegrationData
  @glob_out             @ref PerformanceDegrationData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_ESPM \n
                        @ref ESPM_CFG_USE_SPM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_F_GETMAXDISTPERFALN_001 

  @traceability         Design Decision

  @author               Bjoern Hackel
*************************************************************************************************************************/
static fDistance_t ESPM_f_GetMaxDistPerfALN (void)
{
  return ACDC_p_GetPerformanceDegrationData()->DegradationEBA.DegrDistPerf.f_MaxDistALN;
}

/*************************************************************************************************************************
  Functionname:         ESPM_f_GetMaxDistSafeEBA                                                                     */ /*!

  @brief                Returns the maximum activation distance for safety functions.

  @return               fDistance_t : Maximum distance for safety functions. @phys_unit [m] @range [0,+...[

  @param[in]            void

  @glob_in              @ref PerformanceDegrationData
  @glob_out             @ref PerformanceDegrationData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_ESPM \n
                        @ref ESPM_CFG_USE_SPM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           @ref TEST_ESPM_F_GETMAXDISTSAFEEBA_001 

  @traceability         Design Decision

  @author               Bjoern Hackel
*************************************************************************************************************************/
static fDistance_t ESPM_f_GetMaxDistSafeEBA (void)
{
  return ACDC_p_GetPerformanceDegrationData()->DegradationEBA.DegrDistSafe.f_MaxDist;
}

/*************************************************************************************************************************
  Functionname:         ESPM_f_GetMaxDistSafeALN                                                                     */ /*!

  @brief                Returns the maximum activation distance for safety functions based on alignment information.

  @return               fDistance_t : Maximum distance for safety functions. @phys_unit [m] @range [0,+...[

  @param[in]            void

  @glob_in              @ref PerformanceDegrationData
  @glob_out             @ref PerformanceDegrationData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_ESPM \n
                        @ref ESPM_CFG_USE_SPM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_F_GETMAXDISTSAFEALN_001

  @traceability         Design Decision

  @author               Bjoern Hackel
*************************************************************************************************************************/
static fDistance_t ESPM_f_GetMaxDistSafeALN (void)
{
  return ACDC_p_GetPerformanceDegrationData()->DegradationEBA.DegrDistSafe.f_MaxDistALN;
}


#if(FCT_HYPOTHESIS_INTFVER >= 0x00001F)
/*************************************************************************************************************************
  Functionname:         ESPM_f_GetMaxDistSafeVDY                                                                     */ /*!

  @brief                Returns the maximum activation distance for safety functions based on VDY information.

  @return               fDistance_t : Maximum distance for safety functions. @phys_unit [m] @range [0,+...[

  @param[in]            void

  @glob_in              @ref PerformanceDegrationData
  @glob_out             @ref PerformanceDegrationData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_ESPM \n
                        @ref ESPM_CFG_USE_SPM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Sheetal Kanthi
*************************************************************************************************************************/
static fDistance_t ESPM_f_GetMaxDistSafeVDY (void)
{
  return ACDC_p_GetPerformanceDegrationData()->DegradationEBA.DegrDistSafe.f_MaxDistVDY;
}
#endif /*FCT_HYPOTHESIS_INTFVER >= 0x00001F*/
#endif /*ESPM_CFG_USE_SPM_OUTPUT*/

#if (!ESPM_CFG_USE_SPM_OUTPUT)
/*************************************************************************************************************************
  Functionname:         ESPMCalcMaxDistHRZ                                                                           */ /*!

  @brief                Calculates the max allowed x-distance based on a max allowed y-error for a moving horizon.

  @description          The moving horizon is the max. long. distance calculated from a max. lateral distance error 
                        and the current std-deviations of the yaw rate and the velocity.\n
                        \n
                        The function calculates two separate maximum distances:
                        1. MaxDistYaw : Maximum distance, based on the standard deviation of the yaw Rate and the ego velocity. 
                           (see formula Maximum Distance Yaw Rate")
                        2. MaxDistDrv : Maximum distance, based on the driver intended curve.
                           (see formula "Maximum Distance Driver Intention")
                        .
                        At an Ego velocity below @ref CD_PERF_DEG_HRZ_DIST_FUSE_VEL_LOW, the returned value is 
                        \f$MaxDist_{DrvCurve}\f$.\n
                        At an Ego velocity above @ref CD_PERF_DEG_HRZ_DIST_FUSE_VEL_HIGH, the returned value is 
                        \f$MaxDist_{Yaw}\f$.\n
                        If the ego velocity is between the two limits, a factor between 0 and one is calculated 
                        based on the interpolation between the limits.\n
                        The returned value is calculated by the formula "Maximum Distance HRZ"\n
                        @startuml ESPMCalcMaxDistHRZ_activity.png
                        start
                          :Get (Ego-) Curve, Velocity, YawRate and the 
                          corresponding standard deviations;
                          if(Signal State of Speed and Yaw Rate is OK?) then (Yes)
                            :Calculate YawRate based MaxDistHRZ;
                            note left: >see formula\n"Maximum Distance Yaw Rate"
                            :Calculate Driver Intention based MaxDistHRZ;
                            note left: >see formula\n"Maximum Distance Driver intention"
                            :Limit calculated distances to upper limit MaxDist
                            (function input parameter);
                            if(Velocity > Upper Threshold)
                              :1}
                              :MaxDistHrz = 
                              Maximum Distance YawRate;
                            elseif (Velocity < Lower Threshold) then (yes)
                              :2}
                              :MaxDistHrz = 
                              Maximum Distance Driver Intention;
                            else (No)
                              :3}
                              :MaxDistHrz = 
                              Fusion of the calculated distances;
                              note left: >see formula\n"Maximum Distance HRZ"
                            endif
                          else(No)
                            :4}
                            :MaxDistHRZ = 0;
                          endif
                        stop
                        @enduml

  @return               fDistance_t : Max allowed x dist based on a max allowed y error based on moving horizon.
                                      @phys_unit [m] @range [0,+...[

  @param[in]            fMaxLatErrDist : The max. lateral distance error at full sensor distance.
  @param[in]            fMaxDist :       The max. sensor distance.

  @glob_in              @ref ACDC_f_GetEgoVelObjSync \n
                        @ref ACDC_p_GetVDYDynObjSync \n
                        @ref ACDC_u_EgoSpeedState    \n
                        @ref ACDC_u_EgoYawRateState
  @glob_out             None

  @c_switch_part        @ref VDY_VEH_DYN_INTFVER
  @c_switch_full        @ref ACDC_CFG_ESPM \n
                        @ref ESPM_CFG_USE_SPM_OUTPUT

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Maximum Distance Yaw Rate:**\n
                          \f$MaxDist_{Yaw} = \sqrt{\frac{2\cdot V\cdot MaxLatError_{MaxDist}}{YawRate_{Std}+|YawRate|\cdot \frac{V_{Std}}{V}}}\f$
                        - **Formula Maximum Distance Driver Intention:**\n
                          \f$MaxDist_{DrvCurve} = \sqrt{\frac{2\cdot MaxLatError_{MaxDist}}{|DrvCurve| + DrvCurve_{Std}}}\f$
                        - **Formula Maximum Distance HRZ**
                          \f$ MaxDist_{HRZ} = ( ( 1 - Fctr ) \cdot MaxDist_{DrvCurve} ) + ( Fctr \cdot MaxDist_{Yaw} )\f$

  @testmethod           @Generic_Testmethods

  @author               Dominik Froehlich
*************************************************************************************************************************/
static fDistance_t ESPMCalcMaxDistHRZ( fDistance_t fMaxLatErrDist, fDistance_t fMaxDist )
{
  fYawRate_t  fYawRateErr;
  fCurve_t    fDrvCurveErr;

  fDistance_t fMaxDistYawHRZ = 0.f;
  fDistance_t fMaxDistDrvHRZ = 0.f;
  fDistance_t fMaxDistHRZ = 0.f;

  float32     fAlpha = 0.f;

  const fVelocity_t fVEgo = ACDC_f_GetEgoVelObjSync();
#if (VDY_VEH_DYN_INTFVER >= 32)
  const fVelocity_t fVEgoStd = SQRT_(ACDC_p_GetVDYDynObjSync()->Longitudinal.varVelocity);
#else
  const fVelocity_t fVEgoStd = SQRT_(ACDC_p_GetVDYDynObjSync()->Longitudinal.MotVar.varVelocity);
#endif
  const fYawRate_t  fYawRate = ACDC_p_GetVDYDynObjSync()->Lateral.YawRate.YawRate;
  const fYawRate_t  fYawRateStd = SQRT_(ACDC_p_GetVDYDynObjSync()->Lateral.YawRate.Variance);
  const fCurve_t    fDrvCurve = ACDC_p_GetVDYDynObjSync()->Lateral.DrvIntCurve.Curve;
  const fCurve_t    fDrvCurveStd = SQRT_(ACDC_p_GetVDYDynObjSync()->Lateral.DrvIntCurve.Variance);

  /* calculate safe distance from ego yaw rate */
  if( ( IS_SIGNAL_STATUS_OK(ACDC_u_GetIOStateEgoSpeedX()) ) 
      &&
      ( IS_SIGNAL_STATUS_OK(ACDC_u_GetIOStateEgoYawRate()) )
      &&
      ( fVEgo > C_F32_DELTA ) 
    )
  {
    fYawRateErr = fYawRateStd + ( fABS( fYawRate ) * ( fVEgoStd / fVEgo ) );
    if( fYawRateErr > C_F32_DELTA )
    {
      fMaxDistYawHRZ = ( 2.0f * ( fVEgo * fMaxLatErrDist ) ) / fYawRateErr;
      fMaxDistYawHRZ = SQRT_( fMaxDistYawHRZ );
      fMaxDistYawHRZ = MIN_FLOAT( fMaxDistYawHRZ, fMaxDist );
    }
    else
    {
      fMaxDistYawHRZ = fMaxDist;
    }
    /* calculate safe distance from driver intended course */
    fDrvCurveErr = fABS( fDrvCurve ) + fDrvCurveStd;
    if( fDrvCurveErr > C_F32_DELTA )
    {
      fMaxDistDrvHRZ = ( 2.0f * fMaxLatErrDist ) / fDrvCurveErr;
      fMaxDistDrvHRZ = SQRT_( fMaxDistDrvHRZ );
      fMaxDistDrvHRZ = MIN_FLOAT( fMaxDistDrvHRZ, fMaxDist );
    }
    else
    {
      fMaxDistDrvHRZ = fMaxDist;
    }
    /* perform blending of distances depending on velocity */
    if( fVEgo > ESPM_PERF_DEG_HRZ_DIST_FUSE_VEL_HIGH )
    {
      fMaxDistHRZ = fMaxDistYawHRZ;
    }
    else if( fVEgo < ESPM_PERF_DEG_HRZ_DIST_FUSE_VEL_LOW ) 
    {
      fMaxDistHRZ = fMaxDistDrvHRZ;
    }
    else /* fusion between lower and upper velocity */
    {
      /*PRQA S 3121 1*//* limits of the interpolated output value */
      fAlpha = CML_f_BoundedLinInterpol2( fVEgo , ESPM_PERF_DEG_HRZ_DIST_FUSE_VEL_LOW, ESPM_PERF_DEG_HRZ_DIST_FUSE_VEL_HIGH, 0.f, 1.0f);
      /* QAC-Fix: transposed from fMaxDistHRZ = ( ( 1.0f - fAlpha ) * fMaxDistDrvHRZ ) + ( fAlpha * fMaxDistYawHRZ ) */
      fMaxDistHRZ = fMaxDistDrvHRZ + ( fAlpha * ( fMaxDistYawHRZ - fMaxDistDrvHRZ ));
    }
  }
  /* done */
  return fMaxDistHRZ;
}
#endif

/*************************************************************************************************************************
  Functionname:         ESPMCalcMaxDistVIS                                                                           */ /*!

  @brief                Returns the Max Dist VIS (=visibility dependent).

  @description          Returns the EBABlockageRange that is stored in the variable @ref PerformanceDegrationData if
                        the EBABlockageState is not @ref GDB_NO_DAMP

  @return               fDistance_t : Maximum x distance based on the current visibility range. @phys_unit [m] @range [0,+...[

  @param[in]            fMaxDist : Default value which is written to fMaxDistVIS.

  @glob_in              @ref PerformanceDegrationData
  @glob_out             None

  @c_switch_part        @ref ESPM_CFG_USE_SPM_OUTPUT
  @c_switch_full        @ref ACDC_CFG_ESPM

  @pre                  EBABlockageRange has been filled
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPMCALCMAXDISTVIS_001\n
                        @ref TEST_ESPMCALCMAXDISTVIS_002

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static fDistance_t ESPMCalcMaxDistVIS( fDistance_t fMaxDist )
{
  fDistance_t fMaxDistVIS = fMaxDist;
#if (ESPM_CFG_USE_SPM_OUTPUT)
  if( ACDC_p_GetPerformanceDegrationData()->EBABlockageState != GDB_NO_DAMP )
  {
    fMaxDistVIS = ACDC_p_GetPerformanceDegrationData()->EBABlockageRange;
  }
#endif
  /* done */
  return fMaxDistVIS;
}

/*************************************************************************************************************************
  Functionname:         ESPM_v_InitDegradationData                                                                   */ /*!

  @brief                Initializes all global data that is used in the degradation module

  @description          Initializes all global data that is used in the degradation module.
                        Resets global variable @ref PerformanceDegrationData.

  @return               void

  @param[in]            void

  @glob_in              @ref PerformanceDegrationData
  @glob_out             @ref PerformanceDegrationData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_ESPM

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_V_INITDEGRADATIONDATA_001

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
void ESPM_v_InitDegradationData(void)
{
  ESPM_Degradation_t * const pPerfDegrEBA = &(ACDC_p_ModPerformanceDegrationData()->DegradationEBA);

  pPerfDegrEBA->QuotasPerf.f_MaxQuotaALN = 0.f;
  pPerfDegrEBA->QuotasPerf.f_MaxQuotaVDY = 0.f;
  pPerfDegrEBA->QuotasPerf.f_MaxLatDist = 0.f;

  pPerfDegrEBA->QuotasSafe.f_MaxQuotaALN = 0.f;
  pPerfDegrEBA->QuotasSafe.f_MaxQuotaVDY = 0.f;
  pPerfDegrEBA->QuotasSafe.f_MaxLatDist = 0.f;
                                          
  pPerfDegrEBA->DegrDistPerf.f_MaxDist = 0.f;
  pPerfDegrEBA->DegrDistPerf.f_MaxDistALN = 0.f;
  pPerfDegrEBA->DegrDistPerf.f_MaxDistVDY = 0.f;
  pPerfDegrEBA->DegrDistPerf.f_MaxDistELV = 0.f;
                                          
  pPerfDegrEBA->DegrDistSafe.f_MaxDist = 0.f;
  pPerfDegrEBA->DegrDistSafe.f_MaxDistALN = 0.f;
  pPerfDegrEBA->DegrDistSafe.f_MaxDistVDY = 0.f;
  pPerfDegrEBA->DegrDistSafe.f_MaxDistELV = 0.f;
                                          
  pPerfDegrEBA->f_MaxDistPerfMin = 0.f;
}

/*************************************************************************************************************************
  Functionname:         ESPM_v_InitOutput                                                                            */ /*!

  @brief                Initializes the ESPM output interface.

  @description          Initializes the ESPM output interface by resetting the safety and performance 
                        structures.

  @return               void

  @param[out]           pOutputData : ESPM interface structure that shall be initialized.
  @param[out]           pErrorOut :   ESPM interface structure that shall be initialized.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_HYPOTHESIS_INTFVER
  @c_switch_full        @ref ACDC_CFG_ESPM

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_V_INITOUTPUT_001
  
  @tracebility          Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
void ESPM_v_InitOutput(HypoIntfDegr_t  *pOutputData, ACDCErrorOutProPort_t *pErrorOut)
{
  pOutputData->Performance.fMaxDist     = 0.f;
  pOutputData->Performance.fMaxDistALN  = 0.f;
  pOutputData->Performance.fMaxDistHRZ  = 0.f;
  pOutputData->Performance.fMaxDistVIS  = 0.f;
  pOutputData->Safety.fMaxDist          = 0.f;
  pOutputData->Safety.fMaxDistALN       = 0.f;
#if(FCT_HYPOTHESIS_INTFVER >= 0x00001F)
  pOutputData->Safety.fMaxDistVDY       = 0.f;  
#endif
  pOutputData->Safety.fMaxDistHRZ       = 0.f;
  pOutputData->Safety.fMaxDistVIS       = 0.f;
  pErrorOut->fSafetyDistanceEBA         = 0.f;
  pErrorOut->eSafetyDistanceEBAState    = AL_SIG_STATE_INIT;
}

/*************************************************************************************************************************
  Functionname:         ESPM_v_MeasFreezeDegradationData                                                             */ /*!

  @brief                Freezes the global variable of the degradation module for MTS.

  @description          Freezes the global variable of the degradation module: @ref PerformanceDegrationData

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_ESPM

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_ESPM_V_MEASFREEZEDEGRADATIONDATA_001 

  @traceability         Design Decision

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
void  ESPM_v_MeasFreezeDegradationData(void)
{

}

#endif /* ACDC_CFG_ESPM */
//! @}



