/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20_hypothesis_mgr.c

DESCRIPTION:               Hypothesis Manager for DIM

AUTHOR:                    $Author: Prakash, Siri (uia98930) (uia98930) $

CREATION DATE:             $Date: 2020/10/22 14:52:14CEST $

VERSION:                   $Revision: 1.33 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_DIM20)

#include "dim20/dim20_int.h"
/*PRQA S 2982, 2983 EOF */ /*date: 2020-08-25, reviewer: Nalina M, reason: Suppressing because the value will be used in future.*/
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static void DIMInitHypothesisOut(GDB_DMHypothesis_t * const hyp);

static eGDBError_t DIMInitModuleActivity(DIMInternalDataModActivity_t *pInternalData);
static eGDBError_t DIMInitModuleAttention(DIMInternalDataModAttention_t *pInternalData);
static eGDBError_t DIMInitModuleFeedback(DIMInternalDataModFeedback_t *pInternalData);

static void DIMUpdateHypoConfidence(DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG]);

static eGDBError_t DIMRunModuleAttention(float32 fCycleTime, GDB_DMHypothesis_t *pOutHypothesis, 
    DIMInternalDataModAttention_t *pInternalData, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG]);

static void DIMAttentionEvalInputData( const DIM_ATTENTION_PAR_struct_t * pDIM_attention_par, 
    DIMInternalDataModAttention_t *pInternalData, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG]);

static eGDBError_t DIMRunModuleActivity(float32 fCycleTime, GDB_DMHypothesis_t *pOutHypothesis, 
    DIMInternalDataModActivity_t *pInternalData, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG]);

static void DIMActivityEvalInputSignals(DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG], 
    const DIM_ACTIVITY_PAR_struct_t * pDIM_activity_par, DIMInternalDataModActivity_t * pInternalData, const float32 fCycleTime);

static eGDBError_t DIMRunModuleFeedback(float32 fCycleTime, GDB_DMHypothesis_t *pOutHypothesis, 
    DIMInternalDataModFeedback_t *pInternalData, const DIM_FEEDBACK_PAR_struct_t *pDIM_feedback_par,
    DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG]);

static void DIMFeedbackProcessCustomInputs(DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG]);

static void DIMFeedbackEvalInputSignals(DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG],
    const DIM_FEEDBACK_PAR_struct_t * pDIM_feedback_par, DIMInternalDataModFeedback_t * pInternalData, const float32 fCycleTime);

#if (DIM_CFG_HYPOTHESIS_AOI_SEEN || DIM_CFG_HYPOTHESIS_OBJECTSEEN)
static eGDBError_t DIMInitModuleDriverLoS(DIMInternalDataModDriverLoS_t *pInternalData);
static eGDBError_t DIMRunModuleDriverLoS(DIMInternalDataModDriverLoS_t *pInternalData, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG]);
static eGDBError_t DIMCalcDrvrLoSDirection(float32* pDrvrLoSAngle, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG]);
static eGDBError_t DIMInitGazeZoneData(DIMInternalDataModDriverLoS_t *pInternalData);
static eGDBError_t DIMCalcZoneSeenProb(DIMInternalDataModDriverLoS_t *pInternalData);
static eGDBError_t DIMEvalZoneSeenProb (DIMInternalDataModDriverLoS_t *pInternalData);
#endif
#if (DIM_CFG_HYPOTHESIS_OBJECTSEEN)
static eGDBError_t DIMInitObjSeenData(DIMInternalDataModDriverLoS_t *pInternalData);
static eGDBError_t DIMProcessTargetObj(DIMInternalDataModDriverLoS_t *pInternalData);
static eGDBError_t DIMGetTargetObj2DrvrCoords(DIMInternalDataModDriverLoS_t *pInternalData);
static eGDBError_t DIMGetObjSeenProb(DIMInternalDataModDriverLoS_t *pInternalData);
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:        DIMInitHypothesisMgr                                                                           */ /*!

  @brief               Fucntion to Initialize DIM hypothesis

  @description         This function intializes the DIM hypothesis parameters to default values. This is generally done 
                       once during the initialization of DIM module.

                       @startuml
                       start
                       :reset hypothesis parameters to defaults;
                       stop
                       @enduml

  @return              void

  @param[in,out]       MEDIC_p_GetDIMData
  @param[in,out]       MEDIC_p_GetDIMHypothesisList

  @glob_in             None 
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                 None 
  @post                None

  @InOutCorrelation    Not Applicable

  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-0007e0f8}

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
void DIMInitHypothesisMgr(void)
{
  uint8 uiI;

  /*@todo: replace with access function when available*/
  (void) DIMInitModuleAttention(&(MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Attention));
  (void) DIMInitModuleFeedback(&(MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Feedback));
  (void) DIMInitModuleActivity(&(MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Activity));
  #if (DIM_CFG_HYPOTHESIS_AOI_SEEN||DIM_CFG_HYPOTHESIS_OBJECTSEEN)
  (void) DIMInitModuleDriverLoS(&(MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_LineOfSight));
  #endif

  for(uiI = 0u; uiI < (uint8)DIM_EBA_HYP_MAX; uiI++)
  {
    DIMInitHypothesisOut(&(MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA[uiI]));
  }
}

/*************************************************************************************************************************
  Functionname:        DIMInitHypothesisOut                                                                           */ /*!

  @brief               Function to Initialize DIM hypothesis results

  @description         This function intializes the DIM hypothesis parameters to default values. This is generally done 
                       once during the initialization of DIM module.

                       @startuml
                       start
                       :reset hypothesis parameters to defaults;
                       stop
                       @enduml

  @return              void

  @param[in,out]       hyp : DIM Hypothesis pointer to initialize with default values

  @glob_in             None 
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                 None 
  @post                None

  @InOutCorrelation    Not Applicable

  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-0007e0f8}

  @author              
*************************************************************************************************************************/
static void DIMInitHypothesisOut(GDB_DMHypothesis_t * const hyp)
{
  hyp->Confidence = (percentage_t) 0;
  hyp->Probability = (sint8) 0;
  hyp->eType = DIMHypoType_No;
  hyp->eGDBError = GDB_ERROR_UNKNOWN_TYPE;
}

#if (DIM_CFG_HYPO_EBA)
/*************************************************************************************************************************
  Functionname:        DIMRunHypothesisEval                                                                          */ /*!

  @brief               Run DIM Module for EBA Hypothesis

  @description         This function will monitor driver's attention, pedal feedback and activity based on 
                       the inputs collected. It will fetch the probability information for each hypothesis
                       using the collected signal information, and saves it for future operations.

                       @startuml
                       Start
                       :start with first hypothesis;
                       repeat
                       :initialize this hypothesis;
                       :run this hypothesis module;
                       if (hypothesis run returned error free value?) then (true)
                       :copy this hypothesis results;
                       else (false) 
                       endif
                       :go to the next hypothesis;
                       repeat while (hypo num < max num of hypothesis?)
                       stop
                       @enduml

  @return              void

  @param[in]           fCycleTime: The cycle time in seconds
  @param[in]           pDimIntHypoVal: ptr to the hypothesis internal parameters
  @param[in]           pDimInputList: pointer to the input signal list

  @glob_in             DIMHypothesisList 
  @glob_out            DIMHypothesisList 

  @c_switch_part       None 
  @c_switch_full       DIM_CFG_HYPO_EBA,MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None 
  @post                None

  @InOutCorrelation    See description

  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1150-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1170-0007e0f8}

  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void DIMRunHypothesisEval(const float32 fCycleTime) 
{
  uint8 uiHypNr;
  GDB_DMHypothesis_t sLocalHyp;
  DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG] = &(MEDIC_p_GetDIMData()->DimInputData.aDIMInputGlobal);

  DIMUpdateHypoConfidence(pDimInputList);

  for(uiHypNr = (uint8)0; uiHypNr < (uint8)DIM_EBA_HYP_MAX; uiHypNr++)
  {
    DIMInitHypothesisOut(&(MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA[uiHypNr]));
    DIMInitHypothesisOut(&sLocalHyp);

    switch (uiHypNr)
    {
      case (uint8)DIM_EBA_HYP_IDX_ATTENTION:
        /*driver attention*/
        sLocalHyp.eGDBError = DIMRunModuleAttention(fCycleTime, &sLocalHyp, 
            &MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Attention, pDimInputList);
        if ( GDB_ERROR_NONE == sLocalHyp.eGDBError )
        {
          DIMFillBaseOutput(&sLocalHyp, MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA, uiHypNr, (uint8)DIM_EBA_HYP_MAX);
        }
        break;

      case (uint8)DIM_EBA_HYP_IDX_FEEDBACK:
        /*driver feedback*/
        DIMFeedbackProcessCustomInputs(pDimInputList);
        sLocalHyp.eGDBError = DIMRunModuleFeedback(fCycleTime, &sLocalHyp, 
            &MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Feedback, &DIM_FEEDBACK_PAR_data_eba, pDimInputList);
        if ( GDB_ERROR_NONE == sLocalHyp.eGDBError )
        {
          DIMFillBaseOutput(&sLocalHyp, MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA, uiHypNr, (uint8)DIM_EBA_HYP_MAX);
        }
        break;

      case (uint8)DIM_EBA_HYP_IDX_ACTIVITY:
        /*driver activity*/
        sLocalHyp.eGDBError = DIMRunModuleActivity(fCycleTime, &sLocalHyp,
            &MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Activity, pDimInputList);
        if ( GDB_ERROR_NONE == sLocalHyp.eGDBError )
        {
          DIMFillBaseOutput(&sLocalHyp, MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA, uiHypNr, (uint8)DIM_EBA_HYP_MAX);
        }
        break;

      #if (DIM_CFG_HYPOTHESIS_AOI_SEEN||DIM_CFG_HYPOTHESIS_OBJECTSEEN)
      case (uint8)DIM_EBA_HYP_IDX_LOS:
        /*evaluation of driver line of sight*/
        sLocalHyp.eGDBError = DIMRunModuleDriverLoS(&MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_LineOfSight, pDimInputList);
        if ( GDB_ERROR_NONE == sLocalHyp.eGDBError )
        {
          DIMFillBaseOutput(&sLocalHyp, MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA, uiHypNr, (uint8)DIM_EBA_HYP_MAX);
        }
        break;
      #endif

      default:
       /*this case is never reached*/
       break;
    }
  }
}
#endif

/*************************************************************************************************************************
  Functionname:        DIMInitModuleActivity                                                                        */ /*!

  @brief               DIMInitModuleActivity

  @description         This function is used to initialise the DIM module activity hypothesis internal data parameters.
                       This is generally called during the initialization of DIM module.
                       @startuml
                       Start
                       if (null ptr check ok?) then (yes)
                       :Initialization of DIM module activity hypothesis internal data parameters;
                       Note :DIM Activity hypothesis parameters\nare set to default values
                       :return no null ptr error;
                       else (not ok)
                       :return null ptr error;
                       endif
                       stop
                       @enduml

  @return              eGDBError_t

  @param[out]          pInternalData

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None  
  @post                None  

  @InOutCorrelation    See description

  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1150-0007e0f8}

  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMInitModuleActivity(DIMInternalDataModActivity_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  DIMInternalDataModActivity_t reset  ={0};

  if(pInternalData != NULL)
  {
    *pInternalData =reset;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return eRetValue;
}
/*************************************************************************************************************************
  Functionname:        DIMActivityEvalInputSignals                                                                          */ /*!

  @brief               DIMActivityEvalInputSignals

  @description         this function evaluates the various input signals of the DIM module activity hypothesis
                       like fAbsSteeringWheelAngle, fAbsSteeringWheelGrad and fLongVelocity. Based on the evaluation
                       it sets various timers like fActivityTimer, fActivityHoldTimer, fEmergencySteerTimer and
                       fGradPeakTimer

                       @startuml
                       Start
                       : find out steering wheel angle using ego velocity;
                       If(this steering wheel angle<abs.steering wheel angle?) then (yes)
                       :update the timer with max hypothesis hold time;
                       Endif
                       :find out the steering wheel gradient using ego velocity;
                       if(this grad<abs grad?) then (yes)
                       :increment the gradpeak timer by cycle time;
                       If (grad peak timer>threshold time) then (yes)
                       :update the timer with shutdown time;
                       Endif
                       else (no)
                       :clear gradpeak timer;
                       Endif
                       :find out steerwheelgrad low threshold using egovel;
                       if(this low threshold<abs.steerwheelgrad?) then (yes)
                       :update activity timer with shutdowntime for low threshold;
                       endif
                       If(abs.angle is greater than angle in straight position?) then (yes)
                       :update the timer for probability hold time;
                       Endif
                       If(abs.grad is greater than grad in constant position?) then (yes)
                       :update the timer for probability hold time;
                       Endif
                       If(abs.grad > angle for emergency steer?) then (yes)
                       :update emergency steer timer;
                       Endif
                       :feed the grad signal to LPF;
                       If(filtered output>threshold for filtered output?) then (yes)
                       :update the timer for grad filtered output;
                       Endif
                       Stop
                       @enduml

  @return              void

  @param[in]           pDIM_activity_par 
  @param[in]           fAbsSteeringWheelAngle 
  @param[in]           fAbsSteeringWheelGrad 
  @param[in]           fLongVelocity  
  @param[in]           fCycleTime
  @param[out]          pInternalData

  @glob_in             None 
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                 None
  @post                None

  @InOutCorrelation    See description

  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1143-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1147-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1156-0007e0f8}

  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void DIMActivityEvalInputSignals(DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG], 
    const DIM_ACTIVITY_PAR_struct_t * pDIM_activity_par, DIMInternalDataModActivity_t * pInternalData, const float32 fCycleTime) 
{
  float32 fsteerwhlangle = fABS((*pDimInputList)[SteeringWheelAngle].uValue.fValue);
  float32 fsteerwhlgrad = fABS((*pDimInputList)[SteeringWheelGradient].uValue.fValue);
  float32 fegovel = (*pDimInputList)[VehicleVelocity].uValue.fValue;

  #if (DIM_CFG_USE_GREATER_THN_EQUAL_DRV_VRYACTIVE)
  if(fsteerwhlangle >= CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_FronSteerThres_POINTS, pDIM_activity_par->fFronSteerThres, fegovel))
  #else
  if(fsteerwhlangle > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_FronSteerThres_POINTS, pDIM_activity_par->fFronSteerThres, fegovel))
  #endif
  {
    pInternalData->fActivityTimer = MAX_FLOAT(pDIM_activity_par->fAngleShutDownTime, pInternalData->fActivityTimer);
  } 

  #if (DIM_CFG_USE_GREATER_THN_EQUAL_DRV_VRYACTIVE)
  if(fsteerwhlgrad >= CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_SWAGradThres_POINTS, pDIM_activity_par->fSteerAngleGradThres, fegovel) )
  #else
  if(fsteerwhlgrad > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_SWAGradThres_POINTS, pDIM_activity_par->fSteerAngleGradThres, fegovel) )
  #endif
  {
    /* Stabilize DIM against short gradient peaks */
    pInternalData->fGradPeakTimer = pInternalData->fGradPeakTimer + fCycleTime;

    if(pInternalData->fGradPeakTimer > pDIM_activity_par->fGradPeakTime )
    {
      pInternalData->fActivityTimer = MAX_FLOAT(pDIM_activity_par->fGradShutDownTime, pInternalData->fActivityTimer);
    }
  }
  else
  {
    pInternalData->fGradPeakTimer = 0.0f;
  }

  if(fsteerwhlgrad > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_SteerAngleGradLowThres_POINTS, pDIM_activity_par->fSteerAngleGradLowThres, fegovel) )
  {
    pInternalData->fActivityLowTimer = MAX_FLOAT(pDIM_activity_par->fGradShutDownTimeLow, pInternalData->fActivityLowTimer);
  }

  if(fsteerwhlangle > pDIM_activity_par->fFronSteerThresStraight)
  {
    pInternalData->fActivityHoldTimer = MAX_FLOAT(pDIM_activity_par->fAngleHoldTime, pInternalData->fActivityHoldTimer);
  }

  if(fsteerwhlgrad > pDIM_activity_par->fFronSteerGradThresStraight)
  {
    pInternalData->fActivityHoldTimer = MAX_FLOAT(pDIM_activity_par->fGradHoldTime, pInternalData->fActivityHoldTimer);
  }

  if(fsteerwhlgrad > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_Emerg_SWAGradThres_POINTS, pDIM_activity_par->fSteerAngleGradEMThres, fegovel) )
  {
    pInternalData->fEmergencySteerTimer = MAX_FLOAT(pDIM_activity_par->fGradShutDownTimeEM, pInternalData->fEmergencySteerTimer);
  }

  /* calculate the low pass filter output for the signal "fAbsSteeringWheelGrad" */
  pInternalData->fGradLowPassOutput = pInternalData->fGradLowPassOutput + (pDIM_activity_par->fFilterFactorSteeringGrad*(fsteerwhlgrad - pInternalData->fGradLowPassOutput));

  /* check if the threshold is met regarding the low pass filtered signal */
  if(pInternalData->fGradLowPassOutput > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_fSteeringAngleGradFilterThres_POINTS, pDIM_activity_par->fSteeringAngleGradFilterThres, fegovel) )
  {
    pInternalData->fGradLowPassTimer = MAX_FLOAT(pInternalData->fGradLowPassTimer,pDIM_activity_par->fSteeringGradFiltHoldTime);
  }

  /*in case of constant straight steering angle for the last time, the activity shall be 0*/
  if( (fsteerwhlangle < pDIM_activity_par->fFronSteerThresStraight) &&
     (fsteerwhlgrad < pDIM_activity_par->fFronSteerGradThresStraight) && 
     (pInternalData->fEmergencySteerTimer < C_F32_DELTA) &&
     (pInternalData->fActivityHoldTimer < C_F32_DELTA) )
  {
    pInternalData->iProbability = 0;
    /* reset the timer for consistency */
    pInternalData->fActivityTimer = 0.0f;
    /* reset the low timer to reset low activity caused by gradient peaks */
    pInternalData->fActivityLowTimer = 0.0f;
    /* reset the Steering wheel angle gradient filter and the corresponding timer */
    pInternalData->fGradLowPassOutput = 0.0f; 
    pInternalData->fGradLowPassTimer = 0.0f;
  }
}/*PRQA S 7002 */ /*date: 2020-10-21, Reviewer: Siri Prakash, Reason:suppressing cyclomatic complexity for better code maintainability*/  
/*************************************************************************************************************************
  Functionname:        DIMRunModuleActivity                                                                        */ /*!

  @brief               DIMRunModuleActivity 

  @description         This function runs the DIM Activity module to check for an emergency steer situation
                       and calculates the activity hypothesis parameters like Probability, Confidence and eType. Based on the 
                       activity information, the timer values are also updated.
                       @startuml
                       Start
                       :set default values to activity related signals;
                       Note left
                       Signals like steering wheel angle, steering wheel gradient
                       And longitudinal velocity
                       End note
                       If(null ptr check ok for input data and hypothesis?) Then (yes)
                       :Get input signals;
                       Note left: Steering wheel gradient signal\n Steering wheel angle signal\n Valid ego velocity signal
                       :Update the DIM timers;
                       Note left
                       Timers for activity, activity hold,
                       Emergency steer timer
                       End note
                       :Evaluate input signals;
                       Note left : Evaluation of AbsSteeringWheelAngle\n AbsSteeringWheelGrad\n LongVelocity
                       If(activity timer > 0?) then (yes)
                       :mark probability for very active case;
                       Else if(gradlowpasstimer or activitylowtimer>0 ?) then (yes)
                       :mark probability for active case;
                       Else (no)
                       : mark probability as 0;
                       Endif
                       If(steering wheel angle is constant?) Then (yes)
                       :no activity, reset timers and probability;
                       Endif
                       If(emergency steering detected?) then (yes)
                       :set very high probabaility for activity;
                       Endif
                       :fill Dim out with hypothesis info;
                       :return no ptr error;
                       Else (no)
                       :return null pointer error;
                       endif
                       Stop
                       @enduml

  @return              eGDBError_t

  @param[in]           fCycleTime 
  @param[in]           pInputData
  @param[out]          pOutHypothesis 
  @param[out]          pInternalData 
  @param[in]           pDIM_activity_par 

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None  
  @post                None  

  @InOutCorrelation    
                       | Timer value                                            | Probability                           |
                       |:-------------------------------------------------------|:--------------------------------------|
                       | fActivityTimer > 0.0f                                  | DIM_ACTIVITY_PAR_VeryActivePercentage |
                       | ((fGradLowPassTimer> 0.0f)OR(fActivityLowTimer > 0.0f))| DIM_ACTIVITY_PAR_ActivePercentage     |
                       | default                                                | 0                                     |

  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1143-0007e0f8}

  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMRunModuleActivity(float32 fCycleTime, GDB_DMHypothesis_t *pOutHypothesis, 
    DIMInternalDataModActivity_t *pInternalData, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG])
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  if( ( pDimInputList != NULL ) && ( pOutHypothesis != NULL ) && ( pInternalData != NULL ) )
  {
    /*------ decrease timers ---------*/
    pInternalData->fActivityLowTimer    = MAX_FLOAT(pInternalData->fActivityLowTimer - fCycleTime,    0.0f);
    pInternalData->fActivityTimer       = MAX_FLOAT(pInternalData->fActivityTimer - fCycleTime,       0.0f);
    pInternalData->fEmergencySteerTimer = MAX_FLOAT(pInternalData->fEmergencySteerTimer - fCycleTime, 0.0f);
    pInternalData->fActivityHoldTimer   = MAX_FLOAT(pInternalData->fActivityHoldTimer - fCycleTime,   0.0f);
    pInternalData->fGradLowPassTimer    = MAX_FLOAT(pInternalData->fGradLowPassTimer - fCycleTime,    0.0f);

    /*------- evaluate input signals ---------*/
    DIMActivityEvalInputSignals(pDimInputList, &DIM_ACTIVITY_PAR_data_eba, pInternalData, fCycleTime);
    /*------ create probabilities ---------*/
    if(pInternalData->fActivityTimer > 0.0f)
    {
      pInternalData->iProbability = DIM_ACTIVITY_PAR_VeryActivePercentage;
    }
    else if((pInternalData->fGradLowPassTimer> 0.0f ) || (pInternalData->fActivityLowTimer > 0.0f))
    {
      pInternalData->iProbability = DIM_ACTIVITY_PAR_ActivePercentage;
    }
    else 
    {
      pInternalData->iProbability = 0;
    }

    /*in case of an emergency steering situation (and all signals available), the probability is always 100%!*/
    if( (pInternalData->fEmergencySteerTimer > 0.0f) && ( pInternalData->iConfidence == DIM_ACTIVITY_PAR_NormalConfidence ) )
    {
      pInternalData->iProbability = DIM_ACTIVITY_PAR_EmergenySteeringPercentage;
    }

    pOutHypothesis->eType       = DIMHypoType_Activity;
    pOutHypothesis->Confidence  = (percentage_t) pInternalData->iConfidence;
    pOutHypothesis->Probability = (sint8) pInternalData->iProbability;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:        DIMInitModuleAttention                                                                         */ /*!

  @brief               DIMInitModuleAttention 

  @description         Data Initialization of module Attention     
                       @startuml
                       Start
                       if(null ptr check for internal data ok?) then (yes)
                       :Initialization of DIM module\nattention hypothesis internal data parameters;
                       :return no errors for ptr;
                       else (no)
                       :return null ptr error;
                       endif
                       stop
                       @enduml

  @return              error

  @param[in,out]       pInternalData

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING   

  @pre                 None  
  @post                None  

  @InOutCorrelation    See description  

  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1150-0007e0f8}

  @author              Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static eGDBError_t DIMInitModuleAttention(DIMInternalDataModAttention_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  DIMInternalDataModAttention_t reset ={0};

  if(pInternalData != NULL)
  {
    *pInternalData =reset;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  return eRetValue;
}
/*************************************************************************************************************************
  Functionname:         DIMAttentionEvalInputData                                                                         */ /*!

  @brief                Evaluates the input values received for attention hypothesis

  @description          Determines the attention hypothesis parameter values by evaluation the driver information received
                        like turn indicators, gas peda and brake pedal information. With this the driver's attention is 
                        determined and the timer corresponding to attention hypothesis is set accordingly, like higher the 
                        attention, higer the time to activate the brake systems and viceversa. This also checks for the 
                        driving pattern to determine if the driver is a robot or not.

                        @startuml
                        Start
                        :get acceleration threshold for the ego velocity;
                        If(ego acceleration > expected acceleration?) then (yes)
                        :update timer for very high attention;
                        Else (no)
                        If(driver braking, but acc and vel not as expected?) then (yes)
                        :update the timer for higher attention;
                        Else (no)
                        :get expected gas pedal position for ego velocity;
                        If(driver braking or gaspedalpos>expected or indicators are on and vel>expected?) then (yes)
                        :update the timer for high attention;
                        Else (no)
                        If(gas pedal grad and steering wheel angle not as expected?) then (yes)
                        :update the timer for low attention;
                        Endif
                        Endif
                        Endif
                        Endif
                        If(high attention timers have no valid value, and if velocity is constant?) then (yes)
                        If(constant velocity not for a while?)then (yes)
                        :reset the timer for gas pedal grad;
                        Else (no)
                        If(gas pedal pos >0 and no gaspedal grad for a while?) then (yes)
                        :robot condition met, low attention timer updated;
                        Else (no)
                        :reset the gas pedal grad timer;
                        Endif
                        Endif
                        Else (no)
                        :velocity not constant enough, \nstore current velocity and reset timers;
                        endif
                        Stop
                        @enduml

  @return               void

  @param[in]            pDIM_attention_par 
  @param[in,out]        pInternalData  
  @param[in,out]        pDimInputList

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        MEDIC_CFG_DRIVER_INTENTION_MONITORING   

  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)  

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1144-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1147-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1155-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static void DIMAttentionEvalInputData(const DIM_ATTENTION_PAR_struct_t * pDIM_attention_par, 
    DIMInternalDataModAttention_t *pInternalData, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG])
{
  float32 fegovel = (*pDimInputList)[VehicleVelocity].uValue.fValue;
  float32 fegoacc = (*pDimInputList)[VehicleAcceleration].uValue.fValue;
  uint32 udriverbraking = (*pDimInputList)[DriverBraking].uValue.bValue;
  float32 fgaspedpos = (*pDimInputList)[GasPedalPosition].uValue.fValue;
  float32 fgaspedgrad = (*pDimInputList)[GasPedalGradient].uValue.fValue;
  uint32 uturnindicator = (*pDimInputList)[TurnIndicator].uValue.bValue;
  float32 fsteeringgrad = fABS((*pDimInputList)[SteeringWheelGradient].uValue.fValue);

  float32 fTemp = CML_f_CalculatePolygonValue(DIM_ATTENTION_PAR_AccelCurve_POINTS, pDIM_attention_par->fAccelCurve, fegovel);

  if( fegoacc > fTemp )
  {
    #ifdef DIM_ATTENTION_WRONG_ACCELOVERRIDE_PERF_LIMIT_ENABLE
    if(fegovel > DIM_ATTENTION_WRONG_ACCELOVERRIDE_PERF_LIMIT_SPEED ) 
    {
      pInternalData->fVeryHighKeepTime = pDIM_attention_par->fVeryHighTime;
      pInternalData->fHigherKeepTime   = pDIM_attention_par->fHigherTime;
    }
    #else
    pInternalData->fVeryHighKeepTime = pDIM_attention_par->fVeryHighTime;
    pInternalData->fHigherKeepTime   = pDIM_attention_par->fHigherTime;
    #endif 
    pInternalData->fHighKeepTime     = pDIM_attention_par->fHighTime;
    pInternalData->fLowKeepTime      = pDIM_attention_par->fLowTime;
  }
  else 
  {
    /* check for higher attention */
    if ( (udriverbraking != FALSE)
       && (fegovel < pDIM_attention_par->fBrakePedalMaxVelocity )
       && (fegoacc <= pDIM_attention_par->fDriverBrakingMaxAcceleration))
    {
      pInternalData->fHigherKeepTime   = pDIM_attention_par->fHigherTime;
      pInternalData->fHighKeepTime     = pDIM_attention_par->fHighTime;
      pInternalData->fLowKeepTime      = pDIM_attention_par->fLowTime;
    }
    else
    {
      fTemp = CML_f_CalculatePolygonValue(DIM_ATTENTION_PAR_GasPedalPosCurve_POINTS, pDIM_attention_par->fGasPedalPosCurve, fegovel);
      /* check for high attention */
      if ( (udriverbraking != FALSE )
         || (fgaspedpos > fTemp)
         || ( ( (uturnindicator == medic_eTurnIndicator_Left ) || (uturnindicator == medic_eTurnIndicator_Right ) )
         && (fegovel >= pDIM_attention_par->fTurnIndicatorMinVelocity)))
      {
        pInternalData->fHighKeepTime     = pDIM_attention_par->fHighTime;
        pInternalData->fLowKeepTime      = pDIM_attention_par->fLowTime;
      }
      else 
      {
        /* check for low attention */
        if ((fgaspedgrad > pDIM_attention_par->fGasPedalGradLowPositive)
           || ( fgaspedgrad < pDIM_attention_par->fGasPedalGradLowNegative)
           || ( (fgaspedgrad < pDIM_attention_par->fGasPedalLowNegMeasured )
           && (fgaspedpos < pDIM_attention_par->fGasPedalLowNegMeasuredPos ) )
           || ( fsteeringgrad > pDIM_attention_par->fSteeringGradLow) )
        {
           pInternalData->fLowKeepTime      = pDIM_attention_par->fLowTime;
        }
        else
        {
           /*nothing to do for unclear situations*/
        }
      }
    }
  }

  /* check for drive robot */

  /* check for low or unknown state and constant velocity */
  if ( (!( pInternalData->fHighKeepTime > 0.0f) )
      && (!( pInternalData->fHigherKeepTime > 0.0f) )
      && (!( pInternalData->fVeryHighKeepTime > 0.0f) )
      && ( fegovel > 0.0f )
      && ( fegovel > (pInternalData->fConstVelocity - pDIM_attention_par->fRobotControlledVelocityThresh ))
      && ( fegovel < (pInternalData->fConstVelocity + pDIM_attention_par->fRobotControlledVelocityThresh ))
        )
  {
    /* velocity currently constant */
    if ( pInternalData->fConstVelTime > 0.0f )
    {
      /* velocity not constant for a certain time 
      reset timer for gas pedal gradient */
      pInternalData->fNoGasPedalGradTime = pDIM_attention_par->fNoGasPedalGradientTime;
    }
    else
    {
      /* velocity constant for a certain time
      check for test case conditions: gas pedal position > 0 && no gas pedal gradient */
      if (( fgaspedpos > 0.0f )
         && ( fgaspedgrad < pDIM_attention_par->fNoGasPedalGradientThresh )
         && ( fgaspedgrad > -pDIM_attention_par->fNoGasPedalGradientThresh ) )
      {
        /* conditions for decreasing timer of gas pedal gradient met */
        if ( pInternalData->fNoGasPedalGradTime > 0.0f )
        {
          /* there was a gas pedal gradient within a certain time*/
        }
        else
        {
          /* now all conditions for robot detection are met */
          pInternalData->fLowKeepTime = MIN_FLOAT(pInternalData->fLowKeepTime,pDIM_attention_par->fLowKeepRobotTime);
        }
      }
      else
      {
        /* conditions for deccreasing timer of gas pedal gradient not met: reset timer */
        pInternalData->fNoGasPedalGradTime = pDIM_attention_par->fNoGasPedalGradientTime;
      }
    }
  }
  else
  {
    /* velocity not constant enough -> reset timer and store current velocity*/
    pInternalData->fConstVelTime       = pDIM_attention_par->fRobotControlledVelocityTime;
    pInternalData->fNoGasPedalGradTime = pDIM_attention_par->fNoGasPedalGradientTime;
    pInternalData->fConstVelocity      = fegovel;
  }
}

/*************************************************************************************************************************
  Functionname:         DIMRunModuleAttention                                                                          */ /*!

  @brief                DIM run for attention 

  @description          This function triggers the evaluation of the input signals collected for checking the attention 
                        hypothesis, and takes the results of the evaluation for creating probability and confidence 
                        for attention hypothesis. The timers for attention are also updated accordingly based on the 
                        attention level.

                        @startuml
                        Start
                        :set default values to attention related signals;
                        If(null ptr check for input data and hypo ok?) then (yes)
                        :Get input signals;
                        Note left
                        Speed Limiter signal
                        Speed Kickdown signal
                        DriverBraking signal
                        GasPedalPosition signal
                        Turn indicator signal
                        Steering wheel gradient signal
                        Ego acceleration signal
                        Ego velocity signal
                        End note 
                        :Update the DIM timers;
                        Note left
                        Timers for very high,
                        Higher, high and low keep time, 
                        Const vel time, no gaspedal grad time
                        End note
                        :Evaluate input signals;
                        Note left :Check for higher, high, low attention
                        :Create probabilities with respect to the DIM timers;
                        Note left
                        If very high keep time is valid,
                        Probability is very high,
                        If high keep time is valid, 
                        Probability is high,
                        And so on
                        End note
                        :fill dim out for feedback hypo;
                        :return no ptr errors;
                        Else (no)
                        :return null ptr error;
                        endif
                        stop
                        @enduml

  @return               error

  @param[in]            fCycleTime 
  @param[in,out]        pDimInputList 
  @param[in,out]        pOutHypothesis 
  @param[in,out]        pInternalData 

  @glob_in              None  
  @glob_out             None  

  @c_switch_part        None  
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING   

  @pre                  None  
  @post                 None  

  @InOutCorrelation     
                        |          Time             |           Probability               |
                        |:--------------------------|:------------------------------------|
                        |  fVeryHighKeepTime > 0.0f | DIM_ATTENTION_PAR_VeryHighPercentage|
                        |  fHigherKeepTime > 0.0f   | DIM_ATTENTION_PAR_HigherPercentage  |
                        |  fHighKeepTime > 0.0f     | DIM_ATTENTION_PAR_HighPercentage    |
                        |  fLowKeepTime > 0.0f      | DIM_ATTENTION_PAR_LowPercentage     |
                        |  Default                  | DIM_ATTENTION_PAR_UnknownPercentage |

  @testmethod           Test of output data (dynamic module test)  

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1144-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static eGDBError_t DIMRunModuleAttention(float32 fCycleTime, GDB_DMHypothesis_t *pOutHypothesis, 
    DIMInternalDataModAttention_t *pInternalData, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG])
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  if(( pOutHypothesis != NULL ) && ( pInternalData != NULL ) && (pDimInputList != NULL))
  {
    /*------ decrease timers ---------*/
    pInternalData->fVeryHighKeepTime   = MAX_FLOAT(pInternalData->fVeryHighKeepTime   - fCycleTime, 0.0f);
    pInternalData->fHigherKeepTime     = MAX_FLOAT(pInternalData->fHigherKeepTime     - fCycleTime, 0.0f);
    pInternalData->fHighKeepTime       = MAX_FLOAT(pInternalData->fHighKeepTime       - fCycleTime, 0.0f);
    pInternalData->fLowKeepTime        = MAX_FLOAT(pInternalData->fLowKeepTime        - fCycleTime, 0.0f);
    pInternalData->fConstVelTime       = MAX_FLOAT(pInternalData->fConstVelTime       - fCycleTime, 0.0f);
    pInternalData->fNoGasPedalGradTime = MAX_FLOAT(pInternalData->fNoGasPedalGradTime - fCycleTime, 0.0f);

    /*------- evaluate input signals ---------*/
    DIMAttentionEvalInputData(&DIM_ATTENTION_PAR_data_eba, pInternalData, pDimInputList);

    /*------ create probabilities ---------*/
    if (pInternalData->fVeryHighKeepTime > 0.0f)
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_VeryHighPercentage;
    }
    else if (pInternalData->fHigherKeepTime > 0.0f)
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_HigherPercentage;
    }
    else if (pInternalData->fHighKeepTime > 0.0f)
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_HighPercentage;
    }
    else if (pInternalData->fLowKeepTime > 0.0f)
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_LowPercentage;
    }
    else
    {
      pInternalData->iProbability = DIM_ATTENTION_PAR_UnknownPercentage;
    }

    pOutHypothesis->eType = DIMHypoType_Attention;
    pOutHypothesis->Confidence  = (percentage_t) pInternalData->iConfidence;
    pOutHypothesis->Probability = (sint8) pInternalData->iProbability;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:        DIMInitModuleFeedback                                                                         */ /*!

  @brief               DIMInitModuleFeedback 

  @description         This functions initializes the DIM feedback hypothesis parameters to default values.
                       This is generally done once during the intialization of DIM module.

                       @startuml
                       Start
                       if(null ptr check for input data ok?) then (yes)
                       :Initialization of DIM module feedback hypothesis internal data parameters;
                       Note :DIM feedback hypothesis parameters\nare set to default values
                       :return no error for ptr;
                       else (no)
                       :return null ptr error;
                       endif
                       stop
                       @enduml

  @return              eGDBError_t

  @param[in]           pInternalData 

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       none  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None  
  @post                None  

  @InOutCorrelation    See description  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1150-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-0007e0f8}

  @author              priyanka gaur | priyanka.gaur@continental-corporation.com
*************************************************************************************************************************/	
static eGDBError_t DIMInitModuleFeedback(DIMInternalDataModFeedback_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  DIMInternalDataModFeedback_t reset ={0};

  if(pInternalData != NULL)
  {
    *pInternalData =reset;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:        DIMFeedbackProcessCustomInputs                                                                         */ /*!

  @brief               DIMFeedbackProcessCustomInputs 

  @description         DIMFeedbackProcessCustomInputs

  @return              eGDBError_t

  @param[in]           pInternalData 

  @glob_in             None  
  @glob_out            None  

  @c_switch_part         
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not Applicable  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1146-0007e0f8}

  @author              priyanka gaur | priyanka.gaur@continental-corporation.com
*************************************************************************************************************************/	
static void DIMFeedbackProcessCustomInputs(DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG])
{
  #if (DIM_CFG_USE_KICKDOWN_INPUT)
  /* If speed limiter is active, the driver pedal gradient shall have no influence on driver attention
  estimation. However, during driver-pedal kick-down the driver attention shall be high */
  if( (*pDimInputList)[SpeedLimiter].eSignalQuality == (uint8)medic_DIMInputSignalState_OK)
  {
    if((*pDimInputList)[SpeedLimiter].uValue.bValue == TRUE)
    {
      if(((*pDimInputList)[KickDown].eSignalQuality == (uint8)medic_DIMInputSignalState_OK)
          && ((*pDimInputList)[KickDown].uValue.bValue == TRUE))
      {
        /* Set the pedal position at high value to enforce high attention */
        (*pDimInputList)[GasPedalPosition].uValue.fValue = DIM_FEEDBACK_PAR_GasPedal_Kickdown_Value;
      }
      else
      {
        /* Keep the pedal position at low value to avoid pedal-off recognition */
        (*pDimInputList)[GasPedalPosition].uValue.fValue = DIM_FEEDBACK_PAR_GasPedal_Passive_Value;
      }
    }
  }
  #else
  _PARAM_UNUSED(pDimInputList);  /* PRQA S 3119 */ /* date: 2020-07-06, Reviewer:Rashmi Ramachandra, Reason: This is needed when DIM_CFG_USE_KICKDOWN_INPUT is off*/
  #endif
}

/*************************************************************************************************************************
  Functionname:         DIMFeedbackEvalInputSignals                                                                      */ /*!

  @brief                Feedback hypothesis evaluation function 

  @description          Function evaluates all feedback relevant signals to generate the hypothesis output

                        @startuml
                        Start
                        :acc buff ptr=(acc buff ptr+1)%buffer size;
                        Note:points to a location in buffer\n and ensures no overflow of buffer
                        :num of frames for acc gradient = \n(grad filter const+(0.5*cycle time))/cycle time;
                        Note:This gives the num of frames in \nacc buffer that should be\nconsidered for acc gradient
                        :limit frame numbers to max 20 and min 1;
                        :loop through the frames until\n driver braking encountered;
                        :acc gradient=(long acc-(acc from acc buffer/10))/cycletime;
                        :store gradient in internal data struct;
                        :store current acc in internal data struture;
                        :store current brake state in intternal data struct;
                        if((gaspedpos and gaspedgrad >= high threshold\n and driver was braking?)\nor(gaspedpos and gaspedgrad >=very high threshold?) then (yes)
                        :set fNegFeedbackTime flag;
                        else if (gaspedpos andr grad >= high threshold?) then (yes)
                        :fNegWeakFeedbackTime flag set;
                        else if (driver is braking?) then (yes)
                        :condition for strong positive satisfied;
                        else if (gaspedpos!=pedal used pos)? then (yes)
                        :fPosFeedbackTime flag set;
                        else (no)
                        endif
                        stop
                        @enduml

  @return               None

  @param[in]            fCycleTime 
  @param[in,out]        pInternalData 
  @param[in,out]        pDIM_feedback_par    
  @param[in,out]        pDimInputList    

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref DIM_CFG_USE_DRV_OVRRDE_INPUT, @ref DIM_CFG_NO_FALL_IN_BRAKE_DETECTION, @ref DIM_CFG_USE_WEAKNEG_HIGHTHRES_CHECK
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                  None  
  @post                 None  

  @InOutCorrelation     See description  
  
  @testmethod           Test of output data (dynamic module test)  

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1142-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1145-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1146-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1147-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static void DIMFeedbackEvalInputSignals(DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG],
    const DIM_FEEDBACK_PAR_struct_t * pDIM_feedback_par, DIMInternalDataModFeedback_t * pInternalData, const float32 fCycleTime)
{
  float32 fTemp;
  uint32 uiTemp;
  uint8  uiNrOfFrames;
  float32 fegoacc = (*pDimInputList)[VehicleAcceleration].uValue.fValue;
  uint32 udriverbraking = (*pDimInputList)[DriverBraking].uValue.bValue;
  float32 fgaspedpos = (*pDimInputList)[GasPedalPosition].uValue.fValue;
  float32 fgaspedgrad = (*pDimInputList)[GasPedalGradient].uValue.fValue;
  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT == MEDIC_ON)
  uint32 udriveroverrideactiv = (*pDimInputList)[DriverOverride].uValue.uiValue;
  #endif
  /*---- monitor current vehicle accel ----*/

  /*move pointer to new location*/
  pInternalData->uiAccelBufferPointer = (pInternalData->uiAccelBufferPointer + 1u) % DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE;    

  /*getting nr of frames from the timer*/
  fTemp = (DIM_FEEDBACK_DEF_GRAD_FILTER_TIME + (0.5f * fCycleTime)) / fCycleTime;   /* PRQA S 3121 *//* physical constant C. Obst 26.08.14 */
  uiNrOfFrames = (uint8) fTemp;
  uiNrOfFrames = MAX(MIN(DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE, uiNrOfFrames), 1u);

  /*getting information from the buffer*/
    
  pInternalData->bDriverWasBraking = b_FALSE;
  for(uiTemp = 0u; uiTemp < ((uint32)uiNrOfFrames); uiTemp++)
  {
    if (pInternalData->bDriverWasBraking == b_FALSE)/*PRQA S 2995, 2991 */ /*date: 2020-08-25, reviewer: Nalina M, reason: Generic implementation, No side effects*/
    {
      if (pInternalData->bBoolBuffer[(((uint32)pInternalData->uiAccelBufferPointer + DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE) - uiTemp) % DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE] == b_TRUE)
      {
         pInternalData->bDriverWasBraking = b_TRUE;
         break;
      }
    }
  }

  /*calculating gradient between current accel and accel uiNrOfFrames before*/
  fTemp = (fegoacc - (((float32)pInternalData->iAccelBuffer[((pInternalData->uiAccelBufferPointer + DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE ) 
      - uiNrOfFrames) % DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE]) / DIM_FEEDBACK_ACCEL_BUFFER_SCALE)) / 
      ((float32)uiNrOfFrames*fCycleTime);

  #if !(DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
  /*check if transition from > pDIM_feedback_par->.fAutoBrakeJerkLimit to < pDIM_feedback_par->fAutoBrakeJerkLimit*/
  if(
      (pInternalData->fCurrentAccelGrad >  pDIM_feedback_par->fAutoBrakeJerkLimit)
      &&
      (fTemp                            <= pDIM_feedback_par->fAutoBrakeJerkLimit)
    )
  {
    pInternalData->fFallIntoBrakeTime = pDIM_feedback_par->fAutoBrkTimeNoPosFdbck;
  }
  #endif
  /*store current accel grad to internal data*/
  pInternalData->fCurrentAccelGrad = fTemp;

  /*store current values into the list*/    
  fTemp = fegoacc * DIM_FEEDBACK_ACCEL_BUFFER_SCALE;
  fTemp = MINMAX_FLOAT(-120.0f, 120.0f, fTemp);               /* PRQA S 3121 *//* make sure that sint8 isn't exceeded C. Obst 26.08.14 */
  pInternalData->iAccelBuffer[pInternalData->uiAccelBufferPointer] = (sint8)fTemp;
  pInternalData->bBoolBuffer[pInternalData->uiAccelBufferPointer] = (udriverbraking != 0u)?b_TRUE:b_FALSE;

  if(
      ( /*normal threshold in case of no auto-brake jerk or driver was braking*/
        (
          #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
          ((udriveroverrideactiv == eOverrideFdbk_Active )              
          ||
          (((fgaspedpos >= pDIM_feedback_par->fHighGasPedalPos)
           ||
           (fgaspedgrad >= pDIM_feedback_par->fHighGasPedalGrad))
           &&
           (udriveroverrideactiv == eOverrideFdbk_NotUsed)))
          #else
          ((fgaspedpos >= pDIM_feedback_par->fHighGasPedalPos)
          ||
          (fgaspedgrad >= pDIM_feedback_par->fHighGasPedalGrad))
          #endif
        )
        && /*to avoid negative feedback due to "falling" into gas pedal after a autobrake jerk*/
        (
          #if !(DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
         (pInternalData->fFallIntoBrakeTime <= DIM_F32_DELTA)
          ||
          #endif
         (pInternalData->bDriverWasBraking == b_TRUE)
        ) 
      )
      /* higher threshold is always active*/
      ||
      #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
      ((udriveroverrideactiv == eOverrideFdbk_Active )
      ||
      (((fgaspedpos >= pDIM_feedback_par->fVeryHighGasPedalPos)      
       || 
      (fgaspedgrad >= pDIM_feedback_par->fVeryHighGasPedalGrad))
       &&
      (udriveroverrideactiv == eOverrideFdbk_NotUsed)))
      #else
      ((fgaspedpos >= pDIM_feedback_par->fVeryHighGasPedalPos)      
      || 
      (fgaspedgrad >= pDIM_feedback_par->fVeryHighGasPedalGrad))
      #endif
    )
  {
    pInternalData->fNegFeedbackTime  = pDIM_feedback_par->fNegFdbckTime;
  }
  #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
  else if ( 
            #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
            /* if available then do not use this states */
            (udriveroverrideactiv == eOverrideFdbk_NotUsed)
            &&
            #endif
             (
              #if (DIM_CFG_USE_WEAKNEG_HIGHTHRES_CHECK)
              (fgaspedpos >= pDIM_feedback_par->fHighGasPedalPosWeakNegH)
              ||
              #endif
              ((fgaspedgrad >= pDIM_feedback_par->fHighGasPedalGradWeakNeg) 
                && 
                (fgaspedpos >= pDIM_feedback_par->fHighGasPedalPosWeakNegL) )
          ))
  {
    pInternalData->fNegWeakFeedbackTime  = pDIM_feedback_par->fNegFdbckTime;
  }
  #endif
  else if (udriverbraking == TRUE) /* Driver braking active */
  {
    pInternalData->fPosFeedbackTime = 0.0f;
  }    
  else if ((fgaspedpos < pDIM_feedback_par->fGasPedalUsedPos) /* No accelerator, check accelerator gradient */
  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
           && (udriveroverrideactiv == eOverrideFdbk_NotUsed)
  #endif 
          )
  {
    if (fgaspedgrad < pDIM_feedback_par->fGasPedelGradNegative)  /* Left accelerator, init positive feedback keep timer */
    {        
      pInternalData->fPosFeedbackTime = pDIM_feedback_par->fPosFdbckTime;
    }
  }
  else
  {
    /* no action */
  }
}
/*************************************************************************************************************************
  Functionname:         DIMRunModuleFeedback                                                                      */ /*!

  @brief                Run function for the feedback module 

  @description          This function triggers the fetching of signal values required for feedback hypothesis, like 
                        brake and gas pedal info. Then evaluates the signals for creating probabilities and confidence
                        for feedback.

                        @startuml
                        Start
                        :set all feedback related \nsignals to default values;
                        Note left
                        Signals like brake, acceleration,
                        Accelerator pedal position,
                        Accelerator pedal gradient
                        End note
                        If(null ptr check for input\n data and hypothesis ok?) then (yes)
                        :check for \nmissing update;
                        Note:if cycle time is less than\nthreshold value then update\nerror flag along with the cycle time 
                        If(brake signal quality ok?) then (yes)
                        :get input signals;
                        Note left
                        Checks for the quality of
                        Input signals to collect
                        the inputs
                        End note
                        Else (no)
                        :decrease the confidence;
                        Endif
                        If(gaspedal pos \nsig quality is ok?) then (yes)
                        If(speed limiter active \nand signal quality is ok?)then(yes)
                        If(kickdown is true and\n signal quality is ok?) then (yes)
                        :set high pedal position \nfor high attention;
                        Else (no)
                        :keep pedal \nposition low;
                        Endif
                        Else if(speedlimiter \nsig qual ok?) then (yes)
                        :speedlimiter inactive,\n get gaspedalpos;
                        Else (no)
                        :speedlimiter nok,\ndecrease confidence;
                        Endif
                        Else (no)
                        :decrease the confidence;
                        Endif
                        If(gaspedal grad \nquality ok?) then (yes)
                        :get gaspedalgrad value;
                        Else(no)
                        :decrease confidence;
                        Endif
                        If(acceleration qual ok?) then (yes)
                        :get acceleration value;
                        Else(no)
                        :decrease confidence;
                        Endif
                        If(driver override \nsignal qual ok?) then (yes)
                        :get driver \noverride value;
                        Else (no)
                        :decrease confidence;
                        Endif
                        :limit the confidence \nto min 0;
                        :count down the timers;
                        Note:Decrease the timer \nvalue by cycle time,\nif it becomes \nnegative then assign 0
                        :evaluate acceleration \nand braking;
                        Note:Checks for the gas pedal\nposition and gas pedal gradient\nto decide the probability
                        If(feedback related signals > \nthreshold for neg feedback?) then (yes)
                        :feedback is negetaive;
                        Else if(negative feedback \ntime is valid?) then (yes)
                        :feedback is negative;
                        Else if(feedback signals >= \nthreshold for weak neg?) then (yes)
                        :feedback is \nweak negative;
                        Else if (weak negative feedback \ntime is valid?) then (yes)
                        :feedback is \nweak negative;
                        Else if (braking is true?) then (yes)
                        :feedback is \nstrong positive;
                        Else if(no acceleration?) then (yes)
                        :check accel grad \nand set probability;
                        Else if(constant acceleration?) then (yes) 
                        :set no negative \nfeedback;
                        Else if(leaving accelerator?) then (yes)
                        :weak pos feedback;
                        Else (no)
                        :no pos feedback;
                        Endif
                        :fill DIM out \nfor hypothesis;
                        :return no \nerrors for ptr;
                        Else (no)
                        :return null \nptr error;
                        endif
                        stop
                        @enduml

  @return               eGDBError_t

  @param[in]            fCycleTime 
  @param[in]            pDimInputList 
  @param[in]            pOutHypothesis 
  @param[in]            pInternalData 
  @param[in]            pDIM_feedback_par    

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref DIM_CFG_USE_DRV_OVRRDE_INPUT, @ref DIM_CFG_NO_FALL_IN_BRAKE_DETECTION, @ref DIM_CFG_USE_KICKDOWN_INPUT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                  None  
  @post                 None  

  @InOutCorrelation     See description  

  @testmethod           Test of output data (dynamic module test)  

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1146-0007e0f8}

  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static eGDBError_t DIMRunModuleFeedback(float32 fCycleTime, GDB_DMHypothesis_t *pOutHypothesis, 
    DIMInternalDataModFeedback_t *pInternalData, const DIM_FEEDBACK_PAR_struct_t *pDIM_feedback_par,
    DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG])
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  if(( pDimInputList != NULL ) && ( pOutHypothesis != NULL ) && ( pInternalData != NULL ))
  {
    if(fCycleTime < CML_f_Delta)     /*check for missing update*/
    {
      /*this error should never occur. Missing cycle time (derived from scheduler control data must be caught in the input port monitoring*/
      /*division by zero protection put here for failsafe -> assuming normal call timing*/
      eRetValue = GDB_ERROR_ZERO_DEVISION;
      fCycleTime = MEDIC_f_GetCycleTime();
    }

    /*count down the timers*/
    pInternalData->fNegFeedbackTime = MAX_FLOAT(pInternalData->fNegFeedbackTime - fCycleTime, 0.0f);
    #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
    pInternalData->fNegWeakFeedbackTime = MAX_FLOAT(pInternalData->fNegWeakFeedbackTime - fCycleTime, 0.0f);
    #else
    pInternalData->fFallIntoBrakeTime = MAX_FLOAT(pInternalData->fFallIntoBrakeTime - fCycleTime, 0.0f);
    #endif
    pInternalData->fPosFeedbackTime = MAX_FLOAT(pInternalData->fPosFeedbackTime - fCycleTime, 0.0f);

    /*---- evaluate driver feedback -------*/
    DIMFeedbackEvalInputSignals(pDimInputList, pDIM_feedback_par, pInternalData, fCycleTime);

    /*------ create probabilities ---------*/
    if(pInternalData->fNegFeedbackTime > 0.0f) 
    {
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckNeg;
    } 
    #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
    else if (pInternalData->fNegWeakFeedbackTime > 0.0f)
    {
      float32 fProb = CML_f_CalculatePolygonValue(DIM_FEEDBACK_PAR_WeakNegCurve_POINTS, pDIM_feedback_par->fWeakNegCurve, pInternalData->fNegWeakFeedbackTime);
      pInternalData->iProbability = (sint16) (ROUND_TO_INT(fProb));
    } 
    #endif
    else if ((*pDimInputList)[DriverBraking].uValue.bValue == TRUE) /* Driver braking active */
    {
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckStrongPos;
    }    
    else if (pInternalData->fPosFeedbackTime > 0.0f)/* Just left accelerator */
    {        
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckPos;
    }
    else if (
             (fABS((*pDimInputList)[GasPedalGradient].uValue.fValue) < pDIM_feedback_par->fHighGasPedalGrad) /* almost constant accelerator */
             #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
             && ((*pDimInputList)[DriverOverride].uValue.uiValue == eOverrideFdbk_NotUsed)
             #endif 
             )
    {
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckNoNeg;
    }    
    else if ((*pDimInputList)[GasPedalGradient].uValue.fValue <= (-pDIM_feedback_par->fHighGasPedalGrad)) /* Leaving accelerator */
    {
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckWeakPos;
    }
    else /* This should not happen, go to save level */
    {
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckNoPos;
    }

    pOutHypothesis->eType = DIMHypoType_Feedback;
    pOutHypothesis->Confidence  = (percentage_t) pInternalData->iConfidence;
    pOutHypothesis->Probability = (sint8)(pInternalData->iProbability );
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return eRetValue;
}

#if (DIM_CFG_HYPOTHESIS_AOI_SEEN||DIM_CFG_HYPOTHESIS_OBJECTSEEN)
/*************************************************************************************************************************
  Functionname:        DIMInitModuleDriverLoS                                                                        */ /*!

  @brief               DIMInitModuleDriverLoS

  @description         Function to initialize the paramters for driver line of sight
                       @startuml
                       Start
                       :Set the local error as None;
                       If (pInternalData is Valid) then (yes)
                       : initialize the paramters for driver line of sight;
                       else (no)
                       : set local error as null pointer;
                       Endif
                       Stop
                       @enduml

  @return              eGDBError_t

  @param[out]          pInternalData

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN
                       @ref DIM_CFG_HYPOTHESIS_AOI_SEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    See description 

  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1150-0007e0f8}

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMInitModuleDriverLoS(DIMInternalDataModDriverLoS_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  DIMInternalDataModDriverLoS_t reset = {0};

  if(pInternalData != NULL)
  {
    *pInternalData = reset;
    pInternalData->uDriverFoVLeftEnd = DRIVER_FOV_LEFT_END;
    pInternalData->uDriverFoVRightEnd = DRIVER_FOV_RIGHT_END;
    pInternalData->uNumOfGazeZones = NUM_OF_GAZE_ZONES;
    pInternalData->fStdDev = DRIVER_LOS_STDEV_NORMDIST;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:        DIMRunModuleDriverLoS                                                                        */ /*!

  @brief               DIMRunModuleDriverLoS 

  @description         Hypothesis to evaluate the driver line of sight
                       @startuml
                       Start
                       :Set the local error as None;
                       If (pInternalData and DIM input data is Valid) then (yes)
                       #orange: initializes the gaze zone parameters to default 
                       <b> DIMInitGazeZoneData </b> > 
                       #orange: Determines the driver line of sight direction
                       <b> DIMCalcDrvrLoSDirection</b> > 
                       #orange: calculates the probability for a zone depending on Driver LoS
                       <b> DIMCalcZoneSeenProb</b> > 
                       #orange: evaluates the zone probabilities to provide an output level
                       <b> DIMEvalZoneSeenProb</b> > 
                       else (no)
                       : set local error as null pointer;
                       Endif
                       Stop
                       @enduml

  @return              eGDBError_t

  @param[in]           fCycleTime 
  @param[in]           pInputData
  @param[out]          pOutHypothesis 
  @param[out]          pInternalData 
  @param[in]           pDIM_objectseen_par 

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN
                       @ref DIM_CFG_HYPOTHESIS_AOI_SEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    See description  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-761-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-774-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-777-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-786-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-792-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-802-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-811-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-813-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-823-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-825-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-831-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-852-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-855-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-867-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-881-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-895-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-897-0007e0f8}

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMRunModuleDriverLoS(DIMInternalDataModDriverLoS_t *pInternalData, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG])
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  if ((pInternalData != NULL) && (pDimInputList != NULL))
  {
    pInternalData->uiModuleCycleCounter++;
    eRetValue = DIMInitGazeZoneData(pInternalData);
    eRetValue = DIMCalcDrvrLoSDirection(&(pInternalData->fLineOfSightAngle), pDimInputList);
    eRetValue = DIMCalcZoneSeenProb(pInternalData);
    eRetValue = DIMEvalZoneSeenProb(pInternalData);
    #if(DIM_CFG_HYPOTHESIS_OBJECTSEEN)
    eRetValue = DIMInitObjSeenData(pInternalData);
    eRetValue = DIMProcessTargetObj(pInternalData);
    #endif
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:        DIMInitGazeZoneData                                                                        */ /*!

  @brief               DIMInitGazeZoneData 

  @description         initializes the gaze zone parameters to default
                       @startuml
                       Start
                       :Set the local error as None;
                       If (pInternalData is Valid) then (yes)
                       While(index is less than NUM_OF_GAZE_ZONES) then (yes)
                       : initializes the gaze zone parameters to default;
                       End while(index is more than NUM_OF_GAZE_ZONES)
                       Else(no)
                       :Set local error as null pointer;
                       EndIf
                       Stop
                       @enduml

  @return              eGDBError_t

  @param[in,out]       pInternalData pointer hypothesis internal parameters

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN
                       @ref DIM_CFG_HYPOTHESIS_AOI_SEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    See description  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMInitGazeZoneData(DIMInternalDataModDriverLoS_t *pInternalData)
{
  uint8 index;
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  if (pInternalData != NULL)
  {
    for (index = 0; index < NUM_OF_GAZE_ZONES; index++)
    {
      pInternalData->GazeZones[index].iConfidence = 0.0f;
      pInternalData->GazeZones[index].iCurrentCycProb = 0.0f;
    }
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return(eRetValue);
}

/*************************************************************************************************************************
  Functionname:        DIMCalcDrvrLoSDirection                                                                        */ /*!

  @brief               DIMCalcDrvrLoSDirection 

  @description         Determines the driver line of sight direction
                       @startuml
                       Start
                       :Set the local error as None;
                       If (Driver line of sight Angle and DIM input list is Valid) then (yes)
                       If (GazeDirectionConfidence_Definite) then (yes)
                       : Update line of sight x direction, y direction and line of sight Angle;
                       Elseif (HeadPositionConfidence_Definite) then (yes)
                       : Update line of sight Angle;
                       Else (no)
                       : Do nothing;
                       Endif
                       Else (no)
                       : update local error as null pointer;
                       EndIf
                       Stop
                       @enduml

  @return              eGDBError_t

  @param[in,out]       DrvrLoSAngle pointer to LoS place holder 
  @param[in]           pDimInputList pointer to the input list

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN
                       @ref DIM_CFG_HYPOTHESIS_AOI_SEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    See description  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMCalcDrvrLoSDirection(float32* pDrvrLoSAngle, DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG])
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  
  #if (DIM_CFG_USE_GAZEDIR_CONF_INPUT) && (DIM_CFG_USE_HEADPOS_CONF_INPUT)
  float32 fDrvrLoSDirX;
  float32 fDrvrLoSDirY;

  if ((pDrvrLoSAngle != NULL) && (pDimInputList != NULL))
  {
    #if (DIM_CFG_USE_GAZEDIR_CONF_INPUT)
    if((*pDimInputList)[GazeDirConf].uValue.uiValue == medic_eGazeDirConfidence_Definite)
    {
      fDrvrLoSDirX =   (*pDimInputList)[GazeDirectionX].uValue.fValue;
      fDrvrLoSDirY =   (*pDimInputList)[GazeDirectionY].uValue.fValue;
      *pDrvrLoSAngle = (float32)RAD2DEG(CML_f_atan2(fDrvrLoSDirY,fDrvrLoSDirX));
    }
    #endif
    #if (DIM_CFG_USE_HEADPOS_CONF_INPUT)
    else if((*pDimInputList)[GazeDirConf].uValue.uiValue == medic_eHeadPosConfidence_Definite)
    {
      *pDrvrLoSAngle = (*pDimInputList)[HeadOrientationYaw].uValue.fValue;
    }
    #endif
    else
    {

    }
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  #endif /* #if (DIM_CFG_USE_GAZEDIR_CONF_INPUT) && (DIM_CFG_USE_HEADPOS_CONF_INPUT) */

  return(eRetValue);
}

/*************************************************************************************************************************
  Functionname:        DIMCalcZoneSeenProb                                                                        */ /*!

  @brief               DIMCalcZoneSeenProb 

  @description         calculates the probability for a zone depending on Driver LoS

  @return              eGDBError_t

  @param[in,out]       pInternalData pointer hypothesis internal parameters

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN
                       @ref DIM_CFG_HYPOTHESIS_AOI_SEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    see description  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMCalcZoneSeenProb(DIMInternalDataModDriverLoS_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  float32 ftemp1 = 0.0f;
  float32 ftemp2 = 0.0f;
  float32 fZfactor1 = 0.0f;
  float32 fZfactor2 = 0.0f;
  float32 fGazeZonePos = 0.0f;
  float32 fProb = 0.0f;
  float32 fNewMeanProb = 0.0f;
  uint8 index;
  float32 fZoneSize = 0.0f;

  if (pInternalData != NULL)
  {
    if (CML_f_IsNonZero(pInternalData->fStdDev) && (pInternalData->uNumOfGazeZones != 0u))
    {
      float32 fMeanForGaussDist = pInternalData->fLineOfSightAngle;
      float32 fStdDevForGaussDist = pInternalData->fStdDev;

      for (index = 0; index < NUM_OF_GAZE_ZONES; index++)
      {
        /*determine the zone size, all zones are equisized*/
        fZoneSize = (pInternalData->uDriverFoVRightEnd - pInternalData->uDriverFoVLeftEnd) / (float32)pInternalData->uNumOfGazeZones;

        /* use the cumulative distribution function to find the probability distribution across a zone. This is done by
           P(zone_start < X <= zone_end) = P(X < zone_end) - P(X < zone_start)
           that is, the probability of a zone is obtained by subtracting the area under the gaussian curve
           starting from left end till the 2 boundaries of the zone, like
           area under the curve till zone upper boundary - area under the curve till zone lower boundary
              *                    *                        *
            *|  *                *|  *                    *   *
            *|  *       ====     *|  *        ----        *   *
           *x|   *              *x|   *                  *     *
          *|x|    *            *xx|    *                *x|     *
           a b                    b                       a                                            */

           /* find out the gaze zone starting angle */
        fGazeZonePos = pInternalData->uDriverFoVLeftEnd + ((float32)index*fZoneSize);
        fZfactor1 = (fGazeZonePos - fMeanForGaussDist) / fStdDevForGaussDist;

        /* calculate the area until the lower end of the zone under the Gaussian curve */
        ftemp1 = CML_f_calcStdGaussianCDF(fABS(fGazeZonePos), fMeanForGaussDist, fStdDevForGaussDist);

        /* find out the gaze zone ending angle */
        fGazeZonePos = pInternalData->uDriverFoVLeftEnd + (((float32)index + 1.0f)*fZoneSize);
        fZfactor2 = (fGazeZonePos - fMeanForGaussDist) / fStdDevForGaussDist;

        /* calculate the area until the higher end of the zone under the Gaussian curve */
        ftemp2 = CML_f_calcStdGaussianCDF(fABS(fGazeZonePos), fMeanForGaussDist, fStdDevForGaussDist);

        /* check if the gaze zone lies on the negative, if yes, then
          P(-a < X < -b) = P(a) - P(b)                             */
        if ((fZfactor1 < 0.0f) && (fZfactor2 <= 0.0f))
        {
          fProb = ftemp1 - ftemp2;
        }
        /* check if the gaze zone lies partially on the negative side, then
          P(-a < X < b) = P(a) + P(b) - 1                             */
        else if ((fZfactor1 < 0.0f) || (fZfactor2 <= 0.0f))
        {
          fProb = ftemp1 + ftemp2 - 1.0f;
        }
        /* check if the gaze zone lies completely on positive side, then
          P(a < X < b) = P(b) - P(a)                             */
        else
        {
          fProb = ftemp2 - ftemp1;
        }

        pInternalData->GazeZones[index].iCurrentCycProb = fProb;

        if (pInternalData->uiModuleCycleCounter != 0u)
        {
          /* calculate mean over cycles to filter the probability */
          fNewMeanProb = ((pInternalData->GazeZones[index].fMeanProb * (float32)pInternalData->uiModuleCycleCounter) +
            pInternalData->GazeZones[index].iCurrentCycProb) / (float32)pInternalData->uiModuleCycleCounter;
        }
        else
        {
          fNewMeanProb = pInternalData->GazeZones[index].iCurrentCycProb;
        }
        pInternalData->GazeZones[index].fMeanProb = fNewMeanProb;
      }
    }
    else
    {
      eRetValue = GDB_ERROR_ZERO_DEVISION;
    }
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }

  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:        DIMEvalZoneSeenProb                                                                        */ /*!

  @brief               DIMEvalZoneSeenProb

  @description         evaluates the zone probabilities to provide an output level
                       @startuml
                       Start
                       :Set local error as None;
                       If (hypothesis internal parameters is not valid) then (yes)
                       While (index is less than NUM_OF_GAZE_ZONES) then (yes)
                       : Get the probability;
                       If (Probability >= strongly observed threshold) then (yes)
                       : assign the output level for strongly-observed case;
                       ElseIf (Probability >= observed threshold) then (yes)
                       : assign the output level for observed case;
                       ElseIf (Probability >= Weakly observed threshold) then (yes)
                       : assign the output level for weakly observed case;
                       Else (no)
                       : assign the output level for not-observed case;
                       Endif
                       EndWhile (Index is not valid)
                       Else (no)
                       :set local error as null pointer;
                       EndIf
                       : return local error;
                       Stop
                       @enduml

  @return              eGDBError_t

  @param[in,out]       pInternalData pointer hypothesis internal parameters

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN
                       @ref DIM_CFG_HYPOTHESIS_AOI_SEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    See description  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMEvalZoneSeenProb (DIMInternalDataModDriverLoS_t *pInternalData)
{
  float32 fProb;
  uint8 index = 0u;
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  if (pInternalData != NULL)
  {
    for (index = 0u; index < NUM_OF_GAZE_ZONES; index++)
    {
      fProb = pInternalData->GazeZones[index].fMeanProb;

      if (fProb >= DIM_DRVRLOS_PAR_AOI_STRONGLY_OBSRVD_THRES)
      {
        /* assign the output level for strongly-observed case */
      }
      else if (fProb >= DIM_DRVRLOS_PAR_AOI_OBSRVD_THRES)
      {
        /* assign the output level for observed case */
      }
      else if (fProb >= DIM_DRVRLOS_PAR_AOI_WEAKLY_OBSRVD_THRES)
      {
        /* assign the output level for weakly observed case */
      }
      else
      {
        /* assign the output level for not-observed case */
      }
    }
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  return GDB_ERROR_NONE;
}
#endif

#if (DIM_CFG_HYPOTHESIS_OBJECTSEEN)
/*************************************************************************************************************************
  Functionname:        DIMInitObjSeenData                                                                        */ /*!

  @brief               DIMInitObjSeenData 

  @description         initializes object related parameters to defaults

  @return              eGDBError_t

  @param[in,out]       pInternalData pointer hypothesis internal parameters

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not defined  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        Not defined

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMInitObjSeenData(DIMInternalDataModObjectSeen_t *pInternalData)
{
  uint8 index;
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  if (pInternalData != NULL)
  {
    for (index = 0; index < ACDC_MAX_NUM_OF_HYPS; index++)
    {
      pInternalData->uObjectSeenProbLevel[index] = 0u;
    }
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  return(eRetValue);
}

/*************************************************************************************************************************
  Functionname:        DIMProcessTargetObj                                                                        */ /*!

  @brief               DIMProcessTargetObj 

  @description         processes target objects using the active hypothesis information and
                       determines wheteher these critical objects were seen by the driver or not

  @return              eGDBError_t

  @param[in,out]       pInternalData pointer hypothesis internal parameters

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not defined  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        Not defined

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMProcessTargetObj(DIMInternalDataModObjectSeen_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  if ( (pInternalData != NULL) && (MEDIC_p_GetHypothesisIntf() != NULL) && (MEDIC_p_GetNumOfHyp() > 0u) )
  {
    DIMGetTargetObj2DrvrCoords(pInternalData);
    DIMGetObjSeenProb(pInternalData);
    eRetValue = GDB_ERROR_NONE;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  return eRetValue;
}

/*************************************************************************************************************************
  Functionname:        DIMGetTargetObj2DrvrCoords                                                                        */ /*!

  @brief               DIMGetTargetObj2DrvrCoords 

  @description         translates the object position from vehicle coordinates to driver coordinates

  @return              eGDBError_t

  @param[in,out]       pInternalData pointer hypothesis internal parameters

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not defined  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        Not defined

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMGetTargetObj2DrvrCoords(DIMInternalDataModObjectSeen_t *pInternalData)
{
  /* critcal object position translation from vehicle coords to driver coords to be done */
  return GDB_ERROR_NONE;
}

/*************************************************************************************************************************
  Functionname:        DIMGetObjSeenProb                                                                        */ /*!

  @brief               DIMGetObjSeenProb 

  @description         maps objects to driver gaze zones and derives the object-seen probability

  @return              eGDBError_t

  @param[in,out]       pInternalData pointer hypothesis internal parameters

  @glob_in             None  
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING 
                       @ref DIM_CFG_HYPOTHESIS_OBJECTSEEN

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not defined  

  @testmethod          Test of output data (dynamic module test) 

  @traceability        Not defined

  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t DIMGetObjSeenProb(DIMInternalDataModObjectSeen_t *pInternalData)
{
  /* mapping object to zone and transferring zone probability to object to be done */
  return GDB_ERROR_NONE;
}
#endif
/*************************************************************************************************************************
  Functionname:         DIMUpdateHypoConfidence                                                                     */ /*!

  @brief                Get input signal values

  @description          This function extracts the value of the input signals which can be used for
                        hypothesis evaluation
                        @startuml
                        Start
                        :Set local error as None;
                        :Set confidence for Activity, Attention and feedback as Normal Confidance;
                        While(index is less than NUM_OF_GAZE_ZONES) then (yes)
                        :Set GazeZones as Normal Confidance;
                        End While(index is greater than NUM_OF_GAZE_ZONES)
                        If(DIM input list is valid) then (yes)
                          While(index is less than DIM_INPUT_NUM_OF_VEH_SIG) then (yes)
                            If (DIM input signal quality is FALSE)then (yes)
                            #orange: get the mask that marks which hypothesis makes use of this signal
                            <b> DIMSelectSiganlsForHypo </b> >
                              If((hypothesis mask)AND(signal to hypothesis mapping for attention hypothesis)!=0) then (yes)
                              :Set confidence as MissingConfidenceDelta;
                              Elseif((hypothesis mask)AND(signal to hypothesis mapping for feedback hypothesis)!=0) then (yes)
                              :Set confidence as MissingConfidenceDelta;
                              Elseif((hypothesis mask)AND(signal to hypothesis mapping for activity hypothesis)!=0) then (yes)
                              :Set confidence as MissingConfidenceDelta;
                              EndIf
                            Endif
                          End while(index greater than DIM_INPUT_NUM_OF_VEH_SIG)
                        else
                        :Set local error as Null pointer;
                        EndIf
                        Stop
                        @enduml

  @return               eGDBError_t

  @param[in]            pInternalData: pointer to the hypothesis internal data 
  @param[in]            pDimInputList: pointer to the list of DIM inputs 
  @param[in]            pDIM_parameters: pointer to the structure that would contain the signal values for different hypothesis 

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref DIM_CFG_USE_DRV_OVRRDE_INPUT, @ref DIM_CFG_USE_KICKDOWN_INPUT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                  None  
  @post                 None  

  @InOutCorrelation     See description  

  @testmethod           Test of output data (dynamic module test)  

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1139-0007e0f8}

  @author               Rashmi Ramachandra|rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static void DIMUpdateHypoConfidence(DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG])
{
  uint8 index;
  uint8 sig2hypomask;
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Activity.iConfidence = DIM_ACTIVITY_PAR_NormalConfidence;
  MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Attention.iConfidence = DIM_ATTENTION_PAR_NormalConfidence;
  MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Feedback.iConfidence = DIM_FEEDBACK_PAR_NormalConfidence;
  #if (DIM_CFG_HYPOTHESIS_AOI_SEEN|DIM_CFG_HYPOTHESIS_OBJECTSEEN)
  for (index = 0u; index < NUM_OF_GAZE_ZONES; index++)
  {
    MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_LineOfSight.GazeZones[index].iConfidence = (float32)DIM_FEEDBACK_PAR_NormalConfidence;
  }
  #endif

  if (pDimInputList != NULL)
  {
    for (index = 0u; index < DIM_INPUT_NUM_OF_VEH_SIG; index++)
    {
      if (DIMIsInputOK((*pDimInputList)[index]) == b_FALSE)
      {
        /* get the mask that marks which hypothesis makes use of this signal*/
        sig2hypomask = DIMSelectSiganlsForHypo(index);

        if ((sig2hypomask & DIM_SIG_ATTENTION_MASK) != (uint8)0)
        {
          MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Attention.iConfidence -= DIM_ATTENTION_PAR_MissingConfidenceDelta;
        }
        if ((sig2hypomask & DIM_SIG_FEEDBACK_MASK) != (uint8)0)
        {
          MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Feedback.iConfidence -= DIM_FEEDBACK_PAR_MissingConfidenceDelta;
        }
        if ((sig2hypomask & DIM_SIG_ACTIVITY_MASK) != (uint8)0)
        {
          MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Activity.iConfidence -= DIM_ACTIVITY_PAR_MissingConfidenceDelta;
        }
      } /* end if */
    } /* end of signal loop */
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
}

#endif /* MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /* MEDIC_CFG_DIM20 */
