/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_wrapper.c

DESCRIPTION:               wrapper module for DIM component

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/03/03 05:29:09CET $

VERSION:                   $Revision: 1.2.2.22 $

LEGACY VERSION:            1.47

**************************************************************************** */
/**
@defgroup dim_wrapper DIM_WRAPPER
  
@ingroup Medic_dim
@{ **/
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
#include "dim/dim_int.h"

/*! @brief       DIM_OUT_CUSTOM_GAS_PEDAL_THRES
    @general     
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     NormalValue   @unit -     @min -   @max -   */
#define DIM_OUT_CUSTOM_GAS_PEDAL_THRES   (20.0f)
/*---- default values ------*/

/*! @brief       DIM_OUT_CUSTOM_DEFAULT_DRVBRAKING
    @general     
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     False  @unit -     @min -   @max -   */
#define DIM_OUT_CUSTOM_DEFAULT_DRVBRAKING        (FALSE)

/*! @brief       DIM_OUT_CUSTOM_GAS_PEDAL_THRES
    @general     
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     95.0f   @unit -     @min -   @max -   */
#define DIM_OUT_CUSTOM_DEFAULT_GASPEDALPOS         (95.0f)

/*! @brief       DIM_OUT_CUSTOM_DEFAULT_SPEEDLIMITACTIVE
    @general     
    @conseq      @incp  -
                 @decp  -
    @attention   -
    @typical     False   @unit -     @min -   @max -   */
#define DIM_OUT_CUSTOM_DEFAULT_SPEEDLIMITACTIVE  (FALSE)

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief DimOutputState_t

    @general Output signal state ranges from 0 to 2.
    
    @conseq [ None ]
    
    @attention [ None ]
    
    */
typedef enum 
{
  DIM_OUT_OK = 0,
  DIM_OUT_ERROR = 1,
  DIM_OUT_NOK_NO_ERROR = 2
} DimOutputState_t;

/* ****************************************************************
    TYPEDEF ENUM
    **************************************************************** */
/*! @brief DimReportState_t

    @general Output error indication ranges from 0 to 2.
    
    @conseq [ None ]
    
    @attention [ None ]
    
    */
typedef enum 
{
  DIM_REP_NO = 0,
  DIM_REP_SILENT = 1,
  DIM_REP_ALERT = 2
} DimReportState_t;

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/* functions */
static void DIMEvalOutputState(const DIMInputDataGlobal_t  * const pInputData, DimReportState_t *pReport, DimOutputState_t *pState);
static void DIMFillMonitoringState(const DIMInputDataGlobal_t  * const  pInputData);
#if (DIM_CFG_HYPO_EBA)
static void DIMPostProcEBA(void);
#endif

/*************************************************************************************************************************
  Functionname:         DIMFillCustomOut                                                                       */ /*!

  @brief                Provide Custom data filling for DIM module  

  @description          Custom data filling for the DIM monitoring states, Feedback, Attention, Activity\n.
                        This will fill the output buffer with the necessary outputs from the hypothesis calculations, and 
                        also the custom output information apart from the base hypothesis outputs.

                        @startuml
                        Start
                        :Custom data filling for DIM monitoring states;
                        :custom data filling for \n Feedback \n Attention \n Activity;
                        stop
                        @enduml 

  @return               void

  @param[in]            pInputData:

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref DIM_CFG_HYPO_EBA 
                        @ref DIM_CFG_HYPO_SI
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void DIMFillCustomOut(const float32 fCycleTime, const DIMInputDataGlobal_t  * const pInputData)
{
  DIMFillMonitoringState(pInputData);

  #if (DIM_CFG_HYPO_EBA)
  DIMPostProcEBA();
  #endif


  _PARAM_UNUSED(fCycleTime); /*PRQA S 3119 */ /* Raghavendra Nese: This variable would be used in future */
}

/*************************************************************************************************************************
  Functionname:    DIMEvalOutputState                                                                               */ /*!

  @brief           Determine output signal state

  @description     Evaluates the output signal states based on the probability, confidence etc., and determines the 
                   output state of the DIM, like   
                   DIM_OUT_OK = 0
                   DIM_OUT_ERROR = 1
                   DIM_OUT_NOK_NO_ERROR = 2

                   which implies that the output can be either fully ok, or partially not ok but no action to be taken on it,
                   or output fully NOK. This is also based on the kind of error that is reported, like:
                   DIM_REP_NO = 0
                   DIM_REP_SILENT = 1
                   DIM_REP_ALERT = 2
                   which implies that no errors reported, or errors reported but no action to be taken and hence silent, or
                   error reported and to be alerted to the receiving module.

                   @startuml
                   Start
                   :check critical signal states for quality;
                   If (critical signal quality ok?) then (yes)
                   :set DIM out state OK;
                   :clear DIM error state;
                   If(less critical signal quality NOK?)
                   :set DIM out error state only;
                   Endif
                   Else (no)
                   :set DIM out state NOK;
                   :set DIM error state as alert;
                   If (only some signals are of bad quality?) then (yes)
                   :edit DIM out NOK but no error;
                   :edit DIM error state as silent;
                   Endif
                   Endif
                   Stop
                   @enduml

  @return          void

  @param[in]       pInputData 
  @param[in,out]   pReport
  @param[in,out]   pState 

  @glob_in         MEDIC_p_GetDIMInCustom() 
  @glob_out        None 

  @c_switch_part   @ref DIM_CFG_USE_DRV_OVRRDE_INPUT 
  @c_switch_full   @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre             [None]
  @post            [None]

  @InOutCorrelation Not defined
  
  @testmethod      Test of output data (dynamic module test) 

  @traceability
     @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_388}

  
  @author          Thomas Diepolder | Thomas.Diepolder@continental-corporation.com
*************************************************************************************************************************/
static void DIMEvalOutputState(const DIMInputDataGlobal_t  * const pInputData, DimReportState_t *pReport, DimOutputState_t *pState)
{
  /* Condition for error state, causing degradation of successive functional component */
  const boolean statErrOK = (
               ( DIMGetInputQuality(pInputData->GasPedalPosition)      != DIMInputSignalState_OK )
            || ( DIMGetInputQuality(pInputData->GasPedalGradient)      != DIMInputSignalState_OK )
            || ( DIMGetInputQuality(pInputData->VehicleVelocity)       != DIMInputSignalState_OK )
            || ( DIMGetInputQuality(pInputData->VehicleAcceleration)   != DIMInputSignalState_OK )
            || ( DIMGetInputQuality(pInputData->DriverBraking)         != DIMInputSignalState_OK ) 
  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
            || ( DIMGetInputQuality(pInputData->DriverOverride)        != DIMInputSignalState_OK )
  #endif
                              )? TRUE : FALSE;

  const boolean statErrBad = (
               ( DIMGetInputQuality(pInputData->SteeringWheelAngle)      != DIMInputSignalState_OK )
            || ( DIMGetInputQuality(pInputData->SteeringWheelGradient)   != DIMInputSignalState_OK )
                              )? TRUE : FALSE;



  if ((statErrOK == FALSE) && (statErrBad == FALSE))
  {
    /* Essential signals are given, report error in case of missing signals, which are uncritical */
    *pState = DIM_OUT_OK;
    *pReport = DIM_REP_NO;

    /* Report error without functional degradation in case of invalid turn indicator or speed limiter */
    if ( (MEDIC_p_GetDIMInCustom()->eSpeedLimitActive == eFCT_STATE_SIG_INVALID)
         || 
         ( DIMGetInputQuality(pInputData->TurnIndicator) != DIMInputSignalState_OK ) )
    {
      *pReport = DIM_REP_ALERT;
    }
  }
  else
  {
    /* set output state to error */
    *pState = DIM_OUT_ERROR;
    *pReport = DIM_REP_ALERT;

    /* Inhibit error indication in case of missing multi-turn detection */
    if ( (statErrOK == FALSE)
         &&
         ( DIMGetInputQuality(pInputData->SteeringWheelAngle)    == DIMInputSignalState_BadQuality )
         && 
         ( DIMGetInputQuality(pInputData->SteeringWheelGradient) == DIMInputSignalState_BadQuality ) 
       )
    {
      *pReport = DIM_REP_SILENT;
      *pState  = DIM_OUT_NOK_NO_ERROR;
    }
  }
}

/*************************************************************************************************************************
  Functionname:    DIMFillMonitoringState                                                                               */ /*!

  @brief           Custom filling of eDriverMonitoringState and eDriverMonitoringErrorReport

  @description     Evaluate input signal states and set return ouptut state for custom conditions of DIM, 
                   Custom filling of MEDIC_p_ModDIMOutCustom()->eDriverMonitoringState and MEDIC_p_ModDIMOutCustom()->eDriverMonitoringErrorReport

                   @startuml
                   Start
                   :get DIM output state info;
                   If(DIM out ok?) then (yes)
                   :report DIM out available \n and fully functional;
                   Elseif(DIM out NOK but no error?) then (yes)
                   :report limited DIM functionality;
                   Elseif (DIM out is error?) then (yes)
                   :report no DIM out possible \nenforce degradation in head;
                   Else (no)
                   :undefined state, report no DIM out possible \nenforce degradation in head;
                   Endif
                   Stop
                   @enduml


  @return          void

  @param[in]       pInputData
 
  @glob_in         None 
  @glob_out        MEDIC_p_ModDIMOutCustom() 

  @c_switch_part   @ref eDimMonState_NotPossible, eDimMonReport_NoError
  @c_switch_full   @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre             [None]
  @post            [None]

  @InOutCorrelation Not defined
  
  @testmethod      Test of output data (dynamic module test) 

  @traceability 
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_388}

  @author          Daniel Herchenbach
*************************************************************************************************************************/
static void DIMFillMonitoringState(const DIMInputDataGlobal_t  * const  pInputData)
{
  /* DIM fill output states*/
  DimOutputState_t OutState;
  DimReportState_t OutReport;

  /* Determine output state */
  DIMEvalOutputState(pInputData, &OutReport, &OutState);

  #ifdef eDimMonState_NotPossible
  switch(OutState)
  {
  case DIM_OUT_OK:
    /* Unlimited functionality */
    MEDIC_p_ModDIMOutCustom()->eDriverMonitoringState = eDimMonState_Unlimited;
    break;

  case DIM_OUT_NOK_NO_ERROR:
    /* Limited functionality, signal error to vehicle network */
    MEDIC_p_ModDIMOutCustom()->eDriverMonitoringState = eDimMonState_Limited;
    break;

  case DIM_OUT_ERROR:
  default:
    /* No reasonable output possible, signal error and enforce degradation (head) */
    MEDIC_p_ModDIMOutCustom()->eDriverMonitoringState = eDimMonState_NotPossible;
    break;
  }
  #endif

  #ifdef eDimMonReport_NoError 
  switch(OutReport)
  {
  case DIM_REP_NO:
    /* Report no error */
    MEDIC_p_ModDIMOutCustom()->eDriverMonitoringErrorReport = eDimMonReport_NoError;
    break;

  case DIM_REP_SILENT:
    /* Limited functionality, inhibit signal error report to vehicle network */
    MEDIC_p_ModDIMOutCustom()->eDriverMonitoringErrorReport = eDimMonReport_Silent;
    break;

  case DIM_REP_ALERT:
  default:
    /* Report error  */
    MEDIC_p_ModDIMOutCustom()->eDriverMonitoringErrorReport = eDimMonReport_Alert;
    break;
  }
  #endif
}

#if (DIM_CFG_HYPO_EBA)
/*************************************************************************************************************************
  Functionname:    DIMPostProcEBA                                                                               */ /*!

  @brief           Custom filling of of attention, feedback and activity state

  @description     Custom filling of MEDIC_p_ModDIMOutCustom()->eDriverAttentionState, ->eDriverFeedbackState and ->eDriverActivityState 
                   after all DIM modules have been processed
                   @startuml
                   Start
                   :set hypothesis outputs to default;
                   :start from first hypothesis;
                   Repeat
                   :get the error status of hypothesis;
                   If(no error?) then (yes)
                   :compare hypo probability against thresholds;
                   :determine hypothesis state;
                   :fill custom out with hypo state;
                   endif
                   :move to the next hypothesis;
                   Repeat while (all hypothesis not checked?)
                   Stop
                   @enduml


  @return          void

  @param[in]       void
 
  @glob_in         MEDIC_p_GetDIMHypothesisList() 
  @glob_out        MEDIC_p_ModDIMOutCustom() 

  @c_switch_part   @ref MEDIC_CFG_USE_SIG_HEADER
  @c_switch_full   @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING, DIM_CFG_HYPO_EBA 

  @pre             [None]
  @post            [None]

  @InOutCorrelation Not defined
  
  @testmethod      Test of output data (dynamic module test) 

  @traceability
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_301}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_4789}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_333}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_379}

  @author          Daniel Herchenbach
*************************************************************************************************************************/
static void DIMPostProcEBA(void)
{
  uint8 uiHypNr;
  GDB_DMHypothesis_t sLocalHyp;

  MEDIC_p_ModDIMOutCustom()->eDriverAttentionState = eDriverAttentionState_Unknown;
  /*!TODO: Introduce default values for feedback and activity state*/

  for(uiHypNr = 0u; uiHypNr < DIM_NR_OF_EBA_HYPOTHESES; uiHypNr++)
  {
    sLocalHyp = MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA[uiHypNr];
    if (GDB_ERROR_NONE == sLocalHyp.eGDBError )
    {
      switch (uiHypNr)
      {
      case (uint8)DIM_EBA_HYP_IDX_ATTENTION:
        /*driver attention*/
        if(sLocalHyp.Probability < DIM_ATTENTION_PROP_THRES_UNKN)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverAttentionState = eDriverAttentionState_Unknown;
        }
        else if(sLocalHyp.Probability < DIM_ATTENTION_PROP_THRES_LOW)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverAttentionState = eDriverAttentionState_Low;
        }
        else if(sLocalHyp.Probability < DIM_ATTENTION_PROP_THRES_HIGH)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverAttentionState = eDriverAttentionState_High;
        }
        else if(sLocalHyp.Probability < DIM_ATTENTION_PROP_THRES_HIGHER)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverAttentionState = eDriverAttentionState_Higher;
        }
        else
        {
          MEDIC_p_ModDIMOutCustom()->eDriverAttentionState = eDriverAttentionState_VeryHigh;
        }
        break;

      case (uint8)DIM_EBA_HYP_IDX_FEEDBACK:
        /*driver feedback*/
        /*! values for sLocalHyp->Probability correspond to percentages; since used only once, no \#defines are used */
        if (sLocalHyp.Probability < DIM_FEEDBACK_PAR_FdbckWeakNeg)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverFeedbackState = eDriverFeedbackState_Negative;
        }
        else if (sLocalHyp.Probability < DIM_FEEDBACK_PAR_FdbckNoNeg)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverFeedbackState = eDriverFeedbackState_WeakNegative;
        }
        else if (sLocalHyp.Probability < DIM_FEEDBACK_PAR_FdbckNoPos)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverFeedbackState = eDriverFeedbackState_NoNegative;
        }
        else if (sLocalHyp.Probability < DIM_FEEDBACK_PAR_FdbckWeakPos)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverFeedbackState = eDriverFeedbackState_NoPositive;
        }
        else if (sLocalHyp.Probability < DIM_FEEDBACK_PAR_FdbckPos)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverFeedbackState = eDriverFeedbackState_WeakPositive;
        }
        else if (sLocalHyp.Probability < DIM_FEEDBACK_PAR_FdbckStrongPos)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverFeedbackState = eDriverFeedbackState_Positive;
        }
        else 
        {
          MEDIC_p_ModDIMOutCustom()->eDriverFeedbackState = eDriverFeedbackState_StrongPositive;
        }
        break;

      case (uint8)DIM_EBA_HYP_IDX_ACTIVITY:
        /*driver activity*/
        if (sLocalHyp.Probability < DIM_ACTIVITY_PAR_ActivePercentage)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverActivityState = eDriverActivity_Inactive;
        }
        else if (sLocalHyp.Probability < DIM_ACTIVITY_PAR_VeryActivePercentage)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverActivityState = eDriverActivity_MissingConf;
        }
        else if (sLocalHyp.Probability < DIM_ACTIVITY_PAR_EmergenySteeringPercentage)
        {
          MEDIC_p_ModDIMOutCustom()->eDriverActivityState = eDriverActivity_VeryActive;
        }
        else
        {
          MEDIC_p_ModDIMOutCustom()->eDriverActivityState = eDriverActivity_EmergencySteer;
        }
        break;

      default:
        /*this case is never reached*/
        break;
      }
    }
  }

  #if (MEDIC_CFG_USE_SIG_HEADER)
  MEDIC_p_ModDIMOutCustom()->sSigHeader.eSigStatus = (AlgoSignalState_t)AL_SIG_STATE_OK;
  #endif
}
#endif


#endif  /* DIM enable switch */
#endif  /* DIM 2.0 switch                 */

/**@}*/
