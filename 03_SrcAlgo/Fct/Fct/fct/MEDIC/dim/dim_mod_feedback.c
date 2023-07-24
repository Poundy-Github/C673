/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_feedback.c

DESCRIPTION:               Implementation of the DIM driver feedback

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/09/02 15:12:28CEST $

VERSION:                   $Revision: 1.26 $

LEGACY VERSION:            1.31
  
**************************************************************************** */
/**
@defgroup dim_mod_feedback DIM_MOD_FEEDBACK 
  
@ingroup Medic_dim
@{ **/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#include "dim/dim_int.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING )

#if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
static void DIMFeedbackEvalInputSignals( const DIM_FEEDBACK_PAR_struct_t * pDIM_feedback_par, 
                                         DIMInternalDataModFeedback_t * pInternalData, 
                                         boolean bDriverBraking,
                                         float32 fGasPedalPosition, 
                                         float32 fGasPedalGradient,
                                         float32 fLongAccel, 
                                         eDriverOverride_t eDriverOverride,
                                         const float32 fCycleTime );
#else
static void DIMFeedbackEvalInputSignals( const DIM_FEEDBACK_PAR_struct_t * pDIM_feedback_par, 
                                         DIMInternalDataModFeedback_t * pInternalData, 
                                         boolean bDriverBraking,
                                         float32 fGasPedalPosition, 
                                         float32 fGasPedalGradient,
                                         float32 fLongAccel,
                                         const float32 fCycleTime );
#endif
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

  @c_switch_part       DIM_CFG_NO_FALL_IN_BRAKE_DETECTION  
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not defined  
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t DIMInitModuleFeedback(DIMInternalDataModFeedback_t *pInternalData)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;
  uint8 uIndex;
  if(pInternalData != NULL)
  {
    pInternalData->iConfidence        = 0;
    pInternalData->iProbability       = 0;
    pInternalData->fPosFeedbackTime   = 0.0f;
    pInternalData->fNegFeedbackTime   = 0.0f;
    #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
    pInternalData->fNegWeakFeedbackTime = 0.0f;
    #endif
    pInternalData->fFallIntoBrakeTime = 0.0f;
    pInternalData->fCurrentAccelGrad  = 0.0f;
    pInternalData->bDriverWasBraking  = b_FALSE;
    pInternalData->uiAccelBufferPointer = 0;
    for (uIndex=0; uIndex<DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE; ++uIndex)
    {
      pInternalData->iAccelBuffer[uIndex] = 0;
      pInternalData->bBoolBuffer[uIndex] = b_FALSE;
    }
  }
  else
  {
    eRetValue = GDB_ERROR_POINTER_NULL;
  }
  return eRetValue;
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
  @param[in]            bDriverBraking 
  @param[in]            pInternalData 
  @param[in]            pDIM_feedback_par    
  @param[in]            fGasPedalPosition    
  @param[in]            fGasPedalGradient    
  @param[in]            fLongAccel    
  @param[in]            eDriverOverride

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref DIM_CFG_USE_DRV_OVRRDE_INPUT, @ref DIM_CFG_NO_FALL_IN_BRAKE_DETECTION, @ref DIM_CFG_USE_WEAKNEG_HIGHTHRES_CHECK
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                  None  
  @post                 None  

  @InOutCorrelation     Not defined  
  
  @testmethod           Test of output data (dynamic module test)  

  @traceability         Design Decision
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_333}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_1316}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_1317}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
#if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
static void DIMFeedbackEvalInputSignals( const DIM_FEEDBACK_PAR_struct_t * pDIM_feedback_par, 
                                         DIMInternalDataModFeedback_t * pInternalData, 
                                         boolean bDriverBraking,
                                         float32 fGasPedalPosition, 
                                         float32 fGasPedalGradient,
                                         float32 fLongAccel, 
                                         eDriverOverride_t eDriverOverride,
                                         const float32 fCycleTime )
#else
static void DIMFeedbackEvalInputSignals( const DIM_FEEDBACK_PAR_struct_t * pDIM_feedback_par, 
                                         DIMInternalDataModFeedback_t * pInternalData, 
                                         boolean bDriverBraking,
                                         float32 fGasPedalPosition, 
                                         float32 fGasPedalGradient,
                                         float32 fLongAccel,
                                         const float32 fCycleTime )
#endif
{
  float32 fTemp;
  uint32 uiTemp;
  uint8  uiNrOfFrames;

  #ifdef DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE
  #if (DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE)
  float32 fMasterCylPressure = DIM_FEEDBACK_DEFAULT_BrakePressure;


  if(MEDIC_p_GetDimInputGlobal()->MasterCylPressure.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(MEDIC_p_GetDimInputGlobal()->MasterCylPressure, fMasterCylPressure, DIM_FEEDBACK_DEFAULT_BrakePressure, float32);   /* PRQA S 3212 *//* redundant casting needed for type safety */
  }
  #endif
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
  for(uiTemp = 0u; (uiTemp < uiNrOfFrames) && (pInternalData->bDriverWasBraking == b_FALSE); uiTemp++)
  {
    if( pInternalData->bBoolBuffer[(((uint32)pInternalData->uiAccelBufferPointer + DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE ) - uiTemp) % DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE] == b_TRUE)
    {
      pInternalData->bDriverWasBraking = b_TRUE;
    }
  }

  /*calculating gradient between current accel and accel uiNrOfFrames before*/
  fTemp = (fLongAccel 
    - (((float32)pInternalData->iAccelBuffer[((pInternalData->uiAccelBufferPointer + DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE ) - uiNrOfFrames) 
                                              % DIM_FEEDBACK_DEF_ACCELBUFFER_SIZE]) 
       / DIM_FEEDBACK_ACCEL_BUFFER_SCALE)) / ((float32)uiNrOfFrames*fCycleTime);

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
  fTemp = fLongAccel * DIM_FEEDBACK_ACCEL_BUFFER_SCALE;
  fTemp = MINMAX_FLOAT(-120.0f, 120.0f, fTemp);               /* PRQA S 3121 *//* make sure that sint8 isn't exceeded C. Obst 26.08.14 */
  pInternalData->iAccelBuffer[pInternalData->uiAccelBufferPointer] = (sint8)fTemp;
  pInternalData->bBoolBuffer[pInternalData->uiAccelBufferPointer] = bDriverBraking;

  if(
      ( /*normal threshold in case of no auto-brake jerk or driver was braking*/
        (
          #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
          ((eDriverOverride == eOverrideFdbk_Active )              
          ||
          (((fGasPedalPosition >= pDIM_feedback_par->fHighGasPedalPos)
           ||
           (fGasPedalGradient >= pDIM_feedback_par->fHighGasPedalGrad))
           &&
           (eDriverOverride == eOverrideFdbk_NotUsed)))
          #else
          ((fGasPedalPosition >= pDIM_feedback_par->fHighGasPedalPos)
          ||
          (fGasPedalGradient >= pDIM_feedback_par->fHighGasPedalGrad))
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
      ((eDriverOverride == eOverrideFdbk_Active )
      ||
      (((fGasPedalPosition >= pDIM_feedback_par->fVeryHighGasPedalPos)      
       || 
      (fGasPedalGradient >= pDIM_feedback_par->fVeryHighGasPedalGrad))
       &&
      (eDriverOverride == eOverrideFdbk_NotUsed)))
      #else
      ((fGasPedalPosition >= pDIM_feedback_par->fVeryHighGasPedalPos)      
      || 
      (fGasPedalGradient >= pDIM_feedback_par->fVeryHighGasPedalGrad))
      #endif
    )
  {
    pInternalData->fNegFeedbackTime  = pDIM_feedback_par->fNegFdbckTime;
  }
  #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
  else if ( 
            #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
            /* if available then do not use this states */
            (eDriverOverride == eOverrideFdbk_NotUsed)
            &&
            #endif
             (
              #if (DIM_CFG_USE_WEAKNEG_HIGHTHRES_CHECK)
              (fGasPedalPosition >= pDIM_feedback_par->fHighGasPedalPosWeakNegH)
              ||
              #endif
              ((fGasPedalGradient >= pDIM_feedback_par->fHighGasPedalGradWeakNeg) 
                && 
                (fGasPedalPosition >= pDIM_feedback_par->fHighGasPedalPosWeakNegL) )
          ))
  {
    pInternalData->fNegWeakFeedbackTime  = pDIM_feedback_par->fNegFdbckTime;
  }
  #endif
  else if ( (bDriverBraking == b_TRUE) /* Driver braking active */
#ifdef DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE
#if (DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE)
      || (BrakeMasterCylinderPressureOK(fMasterCylPressure) == b_TRUE)
#endif
#endif
      )
  {
    pInternalData->fPosFeedbackTime = 0.0f;
  }    
  else if ((fGasPedalPosition < pDIM_feedback_par->fGasPedalUsedPos) /* No accelerator, check accelerator gradient */
  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
           && (eDriverOverride == eOverrideFdbk_NotUsed)
  #endif 
          )
  {
    if (fGasPedalGradient < pDIM_feedback_par->fGasPedelGradNegative)  /* Left accelerator, init positive feedback keep timer */
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
  @param[in]            pInputData 
  @param[in]            pOutHypothesis 
  @param[in]            pInternalData 
  @param[in]            pDIM_feedback_par    

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref DIM_CFG_USE_DRV_OVRRDE_INPUT, @ref DIM_CFG_NO_FALL_IN_BRAKE_DETECTION, @ref DIM_CFG_USE_KICKDOWN_INPUT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING


  @pre                  None  
  @post                 None  

  @InOutCorrelation     Not defined  
  
  @testmethod           Test of output data (dynamic module test)  

  @traceability         
     @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_333}
     @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_793}
     @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_794}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
eGDBError_t DIMRunModuleFeedback(float32 fCycleTime, const DIMInputDataGlobal_t *pInputData, 
                                 GDB_DMHypothesis_t *pOutHypothesis, DIMInternalDataModFeedback_t *pInternalData, 
                                 const DIM_FEEDBACK_PAR_struct_t *pDIM_feedback_par)
{
  eGDBError_t eRetValue = GDB_ERROR_NONE;

  boolean bDriverBraking      = DIM_FEEDBACK_DEFAULT_DrvBraking;        /*default value for driver braking*/
  float32 fGasPedalPosition   = DIM_FEEDBACK_DEFAULT_GasPedalPos;       /*default value for gas pedal position*/
  float32 fGasPedalGradient   = DIM_FEEDBACK_DEFAULT_GasPedalGrad;      /*default value for gas pedal gradient*/
  float32 fLongAccel          = DIM_FEEDBACK_DEFAULT_LongAccel;         /*default value for long accel*/
  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
  eDriverOverride_t eDriverOverride = DIM_FEEDBACK_DEFAULT_DriverOverride;    /*default value for driver override*/
  #endif

  #ifdef DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE
  #if (DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE)
  float32 fMasterCylPressure = DIM_FEEDBACK_DEFAULT_BrakePressure;
  #endif
  #endif

  
  if(( pInputData != NULL ) && ( pOutHypothesis != NULL ) && ( pInternalData != NULL ) )
  {
    if (fCycleTime < CML_f_Delta)     /*check for missing update*/
    {
      /*this error should never occur. Missing cycle time (derived from scheduler control data must be caught in the input port monitoring*/
      /*division by zero protection put here for failsafe -> assuming normal call timing*/
      eRetValue = GDB_ERROR_ZERO_DEVISION;
      fCycleTime = MEDIC_f_GetCycleTime();
    }

    /*-------- get input signals -----------*/
    pInternalData->iConfidence = DIM_FEEDBACK_PAR_NormalConfidence;

    /*in case of a valid driver braking signal - use this for evaluation - else use the default "false" value*/
    if(pInputData->DriverBraking.eSignalQuality == (uint8)DIMInputSignalState_OK)
    {
       DIMGetInputValue(pInputData->DriverBraking, bDriverBraking, DIM_FEEDBACK_DEFAULT_DrvBraking, boolean);   /*PRQA S 3212, 4350 #date: 2020-06-11, reviewer: Nalina M, reason: redundant casting needed for type safety*/
    }
    else
    {
      pInternalData->iConfidence-= DIM_FEEDBACK_PAR_MissingConfidenceDelta;
    }
    /*in case of a valid gas pedal position signal - use this for evaluation - else use the default "100.0" value*/
    if(pInputData->GasPedalPosition.eSignalQuality == (uint8)DIMInputSignalState_OK)
    {
      #if (DIM_CFG_USE_KICKDOWN_INPUT)
      /* If speed limiter is active, the driver pedal gradient shall have no influence on driver attention
      estimation. However, during driver-pedal kick-down the driver attention shall be high */
      if( (pInputData->SpeedLimiter.eSignalQuality == (uint8)DIMInputSignalState_OK)
        &&(pInputData->SpeedLimiter.uValue.bValue == TRUE) )
      {
        if ( (pInputData->KickDown.eSignalQuality == (uint8)DIMInputSignalState_OK)
          && (pInputData->KickDown.uValue.bValue == TRUE) )
        {
          /* Set the pedal position at high value to enforce high attention */
          fGasPedalPosition = DIM_FEEDBACK_PAR_GasPedal_Kickdown_Value;
        }
        else
        {
          /* Keep the pedal position at low value to avoid pedal-off recognition */
          fGasPedalPosition = DIM_FEEDBACK_PAR_GasPedal_Passive_Value;
        }
      }
      else if(pInputData->SpeedLimiter.eSignalQuality == (uint8)DIMInputSignalState_OK)
      {
        /* Speed limiter is inactive */
        DIMGetInputValue(pInputData->GasPedalPosition, fGasPedalPosition, DIM_FEEDBACK_DEFAULT_GasPedalPos, float32);    /* PRQA S 3212 *//* redundant casting needed for type safety */
      }
      else
      {
        /*set GasPedalPostion-Signal to missing if Speedlimiter-Signal is not ok*/
        pInternalData->iConfidence-= DIM_FEEDBACK_PAR_MissingConfidenceDelta;
      }
      #else /*DIM_CFG_USE_KICKDOWN_INPUT*/
      DIMGetInputValue(pInputData->GasPedalPosition, fGasPedalPosition, DIM_FEEDBACK_DEFAULT_GasPedalPos, float32);    /* PRQA S 3212 *//* redundant casting needed for type safety */
      #endif
    }
    else
    {
      pInternalData->iConfidence-= DIM_FEEDBACK_PAR_MissingConfidenceDelta;
    }

    /*in case of a valid gas pedal gradient signal - use this for evaluation - else use the default "0.0" value*/
    if(pInputData->GasPedalGradient.eSignalQuality == (uint8)DIMInputSignalState_OK)
    {
       DIMGetInputValue(pInputData->GasPedalGradient, fGasPedalGradient, DIM_FEEDBACK_DEFAULT_GasPedalGrad, float32);   /* PRQA S 3212 *//* redundant casting needed for type safety */
    }
    else
    {
      pInternalData->iConfidence-= DIM_FEEDBACK_PAR_MissingConfidenceDelta;
    }

    /*in case of a valid ego accel signal - use this for evaluation - else use the default "0.0" value*/
    if(pInputData->VehicleAcceleration.eSignalQuality == (uint8)DIMInputSignalState_OK)
    {
       DIMGetInputValue(pInputData->VehicleAcceleration, fLongAccel, DIM_FEEDBACK_DEFAULT_LongAccel, float32);        /* PRQA S 3212 *//* redundant casting needed for type safety */
    }
    else
    {
      pInternalData->iConfidence-= DIM_FEEDBACK_PAR_MissingConfidenceDelta;
    }

    #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
    if(pInputData->DriverOverride.eSignalQuality == (uint8)DIMInputSignalState_OK)
    {
        DIMGetInputValue(pInputData->DriverOverride, eDriverOverride, DIM_FEEDBACK_DEFAULT_DriverOverride, eDriverOverride_t);
    }
    else
    {
      /* safe fallback state is non-fire AEB intervention */
      eDriverOverride = eOverrideFdbk_Active; /* TODO: is this usefull to have in worst case an abortion ? Better us invalid? */
      pInternalData->iConfidence-= DIM_FEEDBACK_PAR_MissingConfidenceDelta;
    }
    #endif

  #ifdef DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE
  #if (DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE)
  if(pInputData->MasterCylPressure.eSignalQuality == (uint8)DIMInputSignalState_OK)
  {
    DIMGetInputValue(MEDIC_p_GetDimInputGlobal()->MasterCylPressure, fMasterCylPressure, DIM_FEEDBACK_DEFAULT_BrakePressure, float32);   /* PRQA S 3212 *//* redundant casting needed for type safety */
  }
  else
  {
    pInternalData->iConfidence-= DIM_FEEDBACK_PAR_MissingConfidenceDelta;
  }
  #endif
  #endif

    /*-------safeguarding Confidence degradation below 0%-------*/
    /*PRQA S 2996,2998 1*/ /* date: 2019-05-22, reviewer: Schnurr, Clemens, reason: defensive programming with parameters*/
    pInternalData->iConfidence = CML_Max (0, pInternalData->iConfidence);            /*parameters can change -> safeguarding*/

    /*-------count down the timers---------------*/
    pInternalData->fNegFeedbackTime = MAX_FLOAT(pInternalData->fNegFeedbackTime - fCycleTime, 0.0f);
    #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
    pInternalData->fNegWeakFeedbackTime = MAX_FLOAT(pInternalData->fNegWeakFeedbackTime - fCycleTime, 0.0f);
    #else
    pInternalData->fFallIntoBrakeTime = MAX_FLOAT(pInternalData->fFallIntoBrakeTime - fCycleTime, 0.0f);
    #endif
    pInternalData->fPosFeedbackTime = MAX_FLOAT(pInternalData->fPosFeedbackTime - fCycleTime, 0.0f);

    /*---- evaluate driver feedback -------*/
    #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
    DIMFeedbackEvalInputSignals(pDIM_feedback_par, pInternalData, bDriverBraking, fGasPedalPosition, fGasPedalGradient, fLongAccel, eDriverOverride, fCycleTime);
    #else
    DIMFeedbackEvalInputSignals(pDIM_feedback_par, pInternalData, bDriverBraking, fGasPedalPosition, fGasPedalGradient, fLongAccel, fCycleTime);
    #endif

    /*------ create probabilities ---------*/

    if(pInternalData->fNegFeedbackTime > 0.0f)
    {
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckNeg;
    }
    #if (DIM_CFG_NO_FALL_IN_BRAKE_DETECTION)
    else if(pInternalData->fNegWeakFeedbackTime > 0.0f)
    {
      float32 fProb = CML_f_CalculatePolygonValue(DIM_FEEDBACK_PAR_WeakNegCurve_POINTS, pDIM_feedback_par->fWeakNegCurve, pInternalData->fNegWeakFeedbackTime);
      pInternalData->iProbability = (sint16) (ROUND_TO_INT(fProb));
    } 
    #endif
    else if ( (bDriverBraking == b_TRUE) /* Driver braking active */
#ifdef DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE
#if (DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE)
      || (BrakeMasterCylinderPressureOK(fMasterCylPressure) == b_TRUE)
#endif
#endif
      ) /* Driver braking active */
    {
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckStrongPos;
    }    
    else if (pInternalData->fPosFeedbackTime > 0.0f)/* Just left accelerator */
    {        
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckPos;
    }
    else if (
             (fABS(fGasPedalGradient) < pDIM_feedback_par->fHighGasPedalGrad) /* almost constant accelerator */
             #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
             && (eDriverOverride == eOverrideFdbk_NotUsed)
             #endif 
              )
    {
      pInternalData->iProbability = DIM_FEEDBACK_PAR_FdbckNoNeg;
    }    
    else if (fGasPedalGradient <= (-pDIM_feedback_par->fHighGasPedalGrad)) /* Leaving accelerator */
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
}/* PRQA S 7004, 7002 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability*/
#endif  /* end of check for MEDIC DIM switch */
#endif  /* end of check for DIM2.0 */

/**@}*/
