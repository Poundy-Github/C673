

/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_activity.c

DESCRIPTION:               Implementation of the DIM driver activity

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/17 13:39:40CEST $

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            1.26

**************************************************************************** */
/**
@defgroup dim_mod_activity DIM_MOD_ACTIVITY 
  
@ingroup Medic_dim
@{ **/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#include "dim/dim_int.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

static void DIMActivityGetInputValues( DIMInternalDataModActivity_t * pInternalData, 
                                          const DIMInputDataGlobal_t * pInputData, 
                                          float32 *fAbsSteeringWheelAngle, 
                                          float32 *fAbsSteeringWheelGrad, 
                                          float32 *fLongVelocity );

static void DIMActivityEvalInputSignals( const DIM_ACTIVITY_PAR_struct_t * pDIM_activity_par, 
                                         DIMInternalDataModActivity_t * pInternalData, 
                                         float32 fAbsSteeringWheelAngle,
                                         float32 fAbsSteeringWheelGrad, 
                                         float32 fLongVelocity,
                                         const float32 fCycleTime ) ;

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

  @InOutCorrelation    Not defined 
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        Design Decision
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t DIMInitModuleActivity(DIMInternalDataModActivity_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  if(pInternalData != NULL)
  {
    pInternalData->fActivityLowTimer  = 0.0f;
    pInternalData->fActivityTimer     = 0.0f;
    pInternalData->fActivityHoldTimer = 0.0f;
    pInternalData->fGradPeakTimer     = 0.0f;
    pInternalData->iConfidence        = 0;
    pInternalData->iProbability       = 0;
    pInternalData->fEmergencySteerTimer = 0.0f;
    pInternalData->fGradLowPassOutput= 0.0f;
    pInternalData->fGradLowPassTimer= 0.0f;
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  return eRetValue;
}
/*************************************************************************************************************************
  Functionname:        DIMActivityGetInputValues                                                                         */ /*!

  @brief               DIMActivityGetInputValues

  @description         This function checks the quality of various input signals related to DIM activity hypothesis
                       and save in the corresponding variables if the signals quality is OK and valid. 

                       @startuml
                       start
                       :set full confidence value initially;
                       If (steering wheel gradient signal quality OK?) then (yes)
                       :consider the signal and confidence is retained as it is;
                       elseif (steering wheel gradient signal quality is bad?) then (yes)
                       :do not consider the signal, and use confidence as default 0;
                       else (no)
                       :decrease the confidence by predefined factor;
                       endif
                       If (steering wheel angle signal quality OK?) then (yes)
                       :consider the signal and confidence is retained as it is;
                       elseif (steering wheel angle signal quality is bad?) then (yes)
                       :do not consider the signal, and use confidence as default 0;
                       else (no)
                       :decrease the confidence by predefined factor;
                       Endif
                       If (ego velocity signal quality OK?) then (yes)
                       :consider the signal, confidence is retained as it is;
                       else (no)
                       :decrease the confidence by predefined factor;
                       Endif
                       If (confidence is negative?) then (yes)
                       :adjust the confidence value to 0;
                       Endif
                       Stop
                       @enduml

  @return              void

  @param[out]          pInternalData
  @param[in]           pInputData 
  @param[out]          fAbsSteeringWheelAngle 
  @param[out]          fAbsSteeringWheelGrad 
  @param[out]          fLongVelocity
  
  @glob_in             None   
  @glob_out            None  

  @c_switch_part       None  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not defined  
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision 
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void DIMActivityGetInputValues( DIMInternalDataModActivity_t * pInternalData, 
                                          const DIMInputDataGlobal_t * pInputData, 
                                          float32 *fAbsSteeringWheelAngle, 
                                          float32 *fAbsSteeringWheelGrad, 
                                          float32 *fLongVelocity ) 
{

  pInternalData->iConfidence = DIM_ACTIVITY_PAR_NormalConfidence;

  /*in case of a valid steering wheel gradient signal - use this for evaluation - else use the default "0.0" value*/
  if(pInputData->SteeringWheelGradient.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->SteeringWheelGradient, (*fAbsSteeringWheelGrad), DIM_ACTIVITY_DEFAULT_SteeringWheelGrad, float32);
    (*fAbsSteeringWheelGrad) = fABS((*fAbsSteeringWheelGrad));
  }
  else if(pInputData->SteeringWheelGradient.eSignalQuality == (uint8)DIMInputSignalState_BadQuality)
  {
    (*fAbsSteeringWheelGrad) = 0.0f; /*Multi-Turn-Loss shall not influence actitvity-confidence*/
  }
  else
  {
    pInternalData->iConfidence-= DIM_ACTIVITY_PAR_MissingConfidenceDelta;
  }
  /*in case of a valid steering wheel angle signal - use this for evaluation - else use the default "0.0" value*/
  if(pInputData->SteeringWheelAngle.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->SteeringWheelAngle, (*fAbsSteeringWheelAngle), DIM_ACTIVITY_DEFAULT_SteeringWheelAngle, float32);
    (*fAbsSteeringWheelAngle) = fABS((*fAbsSteeringWheelAngle));
  }
  else if(pInputData->SteeringWheelAngle.eSignalQuality == (uint8)DIMInputSignalState_BadQuality)
  {
    (*fAbsSteeringWheelAngle) = 0.0f; /*Multi-Turn-Loss shall not influence actitvity-confidence*/
  }
  else
  {
    pInternalData->iConfidence-= DIM_ACTIVITY_PAR_MissingConfidenceDelta;
  }    
  /*in case of a valid ego velocity signal - use this for evaluation - else use the default "0.0" value*/
  if(pInputData->VehicleVelocity.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(pInputData->VehicleVelocity, (*fLongVelocity), DIM_ACTIVITY_DEFAULT_LongVelocity, float32);
  }
  else
  {
    pInternalData->iConfidence-= DIM_ACTIVITY_PAR_MissingConfidenceDelta;
  }

  if(pInternalData->iConfidence < 0)
  {
    pInternalData->iConfidence = 0;
  }
}/* PRQA S 7002,7004,7012 *//*suppressing cyclomatic complexity for better code maintainability*/
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
                       if(this swa not to be considered \napart from greater values?) then (yes)
                       If(this steering wheel angle<abs.steering wheel angle?) then (yes)
                       :update the timer with max hypothesis hold time;
                       Endif
                       else (this swa also to be considered \nalong with greater values)
                       If(this steering wheel angle<=abs.steering wheel angle?) then (yes)
                       :update the timer with max hypothesis hold time;
                       Endif
                       endif
                       :find out the steering wheel gradient using ego velocity;
                       if(this swg not to be considered \napart from greater values?) then (yes)
                       if(this grad<abs grad?) then (yes)
                       :increment the gradpeak timer by cycle time;
                       If (grad peak timer>threshold time) then (yes)
                       :update the timer with shutdown time;
                       Endif
                       else (no)
                       :clear gradpeak timer;
                       Endif
                       else (this swg also to be considered \nalong with greater values)
                       if(this grad<=abs grad?) then (yes)
                       :increment the gradpeak timer by cycle time;
                       If (grad peak timer>threshold time) then (yes)
                       :update the timer with shutdown time;
                       Endif
                       else (no)
                       :clear gradpeak timer;
                       Endif
                       endif
                       :find out steerwheelgrad low threshold using egovel;
                       if(this low threshold<abs.steerwheelgrad?) then (yes)
                       :update activity timer with shutdowntime for low threshold;
                       endif
                       if(SWA signal allowed to use?) then (yes)
                       if(absolute SWA > SWA threshold for corresponding ego velocity) then (yes)
                       :set the flag for low activity;
                       endif
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

  @InOutCorrelation    Not defined
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_379}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_1318}
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void DIMActivityEvalInputSignals( const DIM_ACTIVITY_PAR_struct_t * pDIM_activity_par, 
                                         DIMInternalDataModActivity_t * pInternalData, 
                                         float32 fAbsSteeringWheelAngle,
                                         float32 fAbsSteeringWheelGrad, 
                                         float32 fLongVelocity,
                                         const float32 fCycleTime ) 
{
  #if (DIM_CFG_USE_GREATER_THN_EQUAL_DRV_VRYACTIVE)
  if(fAbsSteeringWheelAngle >= CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_FronSteerThres_POINTS, pDIM_activity_par->fFronSteerThres, fLongVelocity) )
  #else
  if(fAbsSteeringWheelAngle > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_FronSteerThres_POINTS, pDIM_activity_par->fFronSteerThres, fLongVelocity) )
  #endif
  {
    pInternalData->fActivityTimer = MAX_FLOAT(pDIM_activity_par->fAngleShutDownTime, pInternalData->fActivityTimer);
  } 
  #if (DIM_CFG_USE_GREATER_THN_EQUAL_DRV_VRYACTIVE)
  if(fAbsSteeringWheelGrad >= CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_SteerAngleGradThres_POINTS, pDIM_activity_par->fSteerAngleGradThres, fLongVelocity) )
  #else
  if(fAbsSteeringWheelGrad > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_SteerAngleGradThres_POINTS, pDIM_activity_par->fSteerAngleGradThres, fLongVelocity) )
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

  if(fAbsSteeringWheelGrad > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_SteerAngleGradLowThres_POINTS, pDIM_activity_par->fSteerAngleGradLowThres, fLongVelocity) )
  {
    pInternalData->fActivityLowTimer = MAX_FLOAT(pDIM_activity_par->fGradShutDownTimeLow, pInternalData->fActivityLowTimer);
  }

  #if (DIM_CFG_ACTIVITY_USE_STEERWHLANGLE)
  //if(fAbsSteeringWheelAngle > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_SteerAngleLowThres_POINTS, pDIM_activity_par->fSteerAngleLowThres, fLongVelocity) )
  if(fAbsSteeringWheelAngle > 90.f ) //For Changan
  {
    pInternalData->fActivityLowTimer = MAX_FLOAT(1.f, pInternalData->fActivityLowTimer);
  }
  #endif

  if(fAbsSteeringWheelAngle > pDIM_activity_par->fFronSteerThresStraight)
  {
    pInternalData->fActivityHoldTimer = MAX_FLOAT(pDIM_activity_par->fAngleHoldTime, pInternalData->fActivityHoldTimer);
  }
  
  if(fAbsSteeringWheelGrad > pDIM_activity_par->fFronSteerGradThresStraight)
  {
    pInternalData->fActivityHoldTimer = MAX_FLOAT(pDIM_activity_par->fGradHoldTime, pInternalData->fActivityHoldTimer);
  }

  if(fAbsSteeringWheelGrad > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_SteerAngleGradEMThres_POINTS, pDIM_activity_par->fSteerAngleGradEMThres, fLongVelocity) )
  {
    pInternalData->fEmergencySteerTimer = MAX_FLOAT(pDIM_activity_par->fGradShutDownTimeEM, pInternalData->fEmergencySteerTimer);
  }

  /* calculate the low pass filter output for the signal "fAbsSteeringWheelGrad" */
  pInternalData->fGradLowPassOutput = pInternalData->fGradLowPassOutput + (pDIM_activity_par->fFilterFactorSteeringGrad*(fAbsSteeringWheelGrad - pInternalData->fGradLowPassOutput));

  /* check if the threshold is met regarding the low pass filtered signal */
  if(pInternalData->fGradLowPassOutput > CML_f_CalculatePolygonValue(DIM_ACTIVITY_PAR_fSteeringAngleGradFilterThres_POINTS, pDIM_activity_par->fSteeringAngleGradFilterThres, fLongVelocity) )
  {
    pInternalData->fGradLowPassTimer = MAX_FLOAT(pInternalData->fGradLowPassTimer,pDIM_activity_par->fSteeringGradFiltHoldTime);
  }
}/* PRQA S 7002 *//*suppressing cyclomatic complexity for better code maintainability*/

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

  @InOutCorrelation    Not defined  
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t DIMRunModuleActivity(const float32 fCycleTime, const DIMInputDataGlobal_t *pInputData, 
                                 GDB_DMHypothesis_t *pOutHypothesis, DIMInternalDataModActivity_t *pInternalData, 
                                 const DIM_ACTIVITY_PAR_struct_t *pDIM_activity_par)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  float32 fAbsSteeringWheelAngle = DIM_ACTIVITY_DEFAULT_SteeringWheelAngle; /*default value for steering wheel angle*/
  float32 fAbsSteeringWheelGrad  = DIM_ACTIVITY_DEFAULT_SteeringWheelGrad;  /*default value for steering wheel gradient*/
  float32 fLongVelocity          = DIM_ACTIVITY_DEFAULT_LongVelocity;       /*default value for long velocity*/

  if( ( pInputData != NULL ) && ( pOutHypothesis != NULL ) && ( pInternalData != NULL ) )
  {
    /*-------- get input signals -----------*/
    DIMActivityGetInputValues(pInternalData, pInputData, &fAbsSteeringWheelAngle, &fAbsSteeringWheelGrad, &fLongVelocity);

    /*------ decrease timers ---------*/
    pInternalData->fActivityLowTimer    = MAX_FLOAT(pInternalData->fActivityLowTimer - fCycleTime,    0.0f);
    pInternalData->fActivityTimer       = MAX_FLOAT(pInternalData->fActivityTimer - fCycleTime,       0.0f);
    pInternalData->fEmergencySteerTimer = MAX_FLOAT(pInternalData->fEmergencySteerTimer - fCycleTime, 0.0f);
    pInternalData->fActivityHoldTimer   = MAX_FLOAT(pInternalData->fActivityHoldTimer - fCycleTime,   0.0f);
    pInternalData->fGradLowPassTimer    = MAX_FLOAT(pInternalData->fGradLowPassTimer - fCycleTime,    0.0f);

    /*------- evaluate input signals ---------*/
    DIMActivityEvalInputSignals(pDIM_activity_par, pInternalData, fAbsSteeringWheelAngle, fAbsSteeringWheelGrad, fLongVelocity, fCycleTime);

    /*------ create probabilities ---------*/
    if(pInternalData->fActivityTimer > 0.0f)
    {
      pInternalData->iProbability = DIM_ACTIVITY_PAR_VeryActivePercentage;
    }
    else if((pInternalData->fGradLowPassTimer>0.0f)
      || (pInternalData->fActivityLowTimer>0.0f))
    {
      pInternalData->iProbability = DIM_ACTIVITY_PAR_ActivePercentage;
    }
    else 
    {
      pInternalData->iProbability = 0;
    }


    /*in case of constant straight steering angle for the last time, the activity shall be 0*/
    if(
        (fAbsSteeringWheelAngle < pDIM_activity_par->fFronSteerThresStraight)
        &&
        (fAbsSteeringWheelGrad < pDIM_activity_par->fFronSteerGradThresStraight)
        && 
        (pInternalData->fEmergencySteerTimer < C_F32_DELTA)
        &&
        (pInternalData->fActivityHoldTimer < C_F32_DELTA)
      )
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
#endif  /* end of check for MEDIC DIM switch */
#endif  /* end of check for DIM2.0 switch */
/**@}*/ 
