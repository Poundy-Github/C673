/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_main.c

DESCRIPTION:               Implementation of the DIM process

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/09/02 15:13:09CEST $

VERSION:                   $Revision: 1.46 $

LEGACY VERSION:            1.37
 
**************************************************************************** */
/**
@defgroup dim_main DIM_MAIN
@ingroup Medic_dim
@{ **/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#include "dim/dim_int.h"
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  CONSTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static void DIMCollectInputs(void);
static void DIMCopyHypothesis(const GDB_DMHypothesis_t *hypIn, GDB_DMHypothesis_t hypOut[], uint8 uiHypNr, uint8 uiTotalHypNr, const DIM_HYPOUT_CAL_DATA_t *DIM_HYPOUT_CAL_DATA);
static void DIMInitHypothesis(GDB_DMHypothesis_t * const hyp);

#if (DIM_CFG_HYPO_EBA)
static void DIMRunModulesEBA(const float32 fCycleTime);
static void DIMInitEba(void);
#endif

/* PRQA S 1055,3240,3242 ALGO_INLINES */ /*Rashmi: Algo inlines are needed*/
ALGO_INLINE void DIMSetInputValueFloat(DIMInputValue_t    *inputValueStruct, float32 FloatValue, DIMInputSignalState_t SignalQuality, float32 StdDev);/* PRQA S 3447 *//*date: 2020-07-02, Reviewer:Nalina M, Reason:suppressing inline function declaration in header file for better code maintainability*/
ALGO_INLINE void DIMSetInputValueUInt(DIMInputValue_t     *inputValueStruct, uint32  UIntValue , DIMInputSignalState_t SignalQuality); /* PRQA S 3447 *//*date: 2020-07-02, Reviewer:Nalina M, Reason:suppressing inline function declaration in header file for better code maintainability*/
ALGO_INLINE void DIMSetInputValueBool(DIMInputValue_t     *inputValueStruct, boolean BoolValue , DIMInputSignalState_t SignalQuality);/* PRQA S 3447 *//*date: 2020-07-02, Reviewer:Nalina M, Reason:suppressing inline function declaration in header file for better code maintainability*/
ALGO_INLINE void DIMSetInputValueBoolTest(DIMInputValue_t *inputValueStruct, boolean BoolValue , DIMInputSignalState_t SignalQuality); /* PRQA S 3447 *//*date: 2020-07-02, Reviewer:Nalina M, Reason:suppressing inline function declaration in header file for better code maintainability*/
/* PRQA L:ALGO_INLINES */
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

#if (DIM_CFG_HYPO_EBA)
/*************************************************************************************************************************
  Functionname:        DIMRunModulesEBA                                                                          */ /*!

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
  
  @glob_in             pDimInputGlobal 
  @glob_out            DIMData 

  @c_switch_part       DIM_CFG_CALC_GAS_PEDAL_GRADIENT 
  @c_switch_full       DIM_CFG_HYPO_EBA,MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None 
  @post                None

  @InOutCorrelation    None
  
  @testmethod          to be determined

  @traceability        Design Decision
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void DIMRunModulesEBA(const float32 fCycleTime) 
{
  uint8 uiHypNr;
  GDB_DMHypothesis_t sLocalHyp;

  for(uiHypNr = 0u; uiHypNr < DIM_NR_OF_EBA_HYPOTHESES; uiHypNr++)
  {
    DIMInitHypothesis(&(MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA[uiHypNr]));
    DIMInitHypothesis(&sLocalHyp);

    switch (uiHypNr)
    {
      case (uint8)DIM_EBA_HYP_IDX_ATTENTION:
      /* driver attention */
      /* Use SpeedLimiter in Attention to apply different logic for calculation. Do NOT manipulate Input values */
      sLocalHyp.eGDBError = DIMRunModuleAttention(fCycleTime, MEDIC_p_GetDimInputGlobal(), &sLocalHyp, &MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Attention, &DIM_ATTENTION_PAR_data_eba);
      
      if (sLocalHyp.eGDBError == GDB_ERROR_NONE)
      {
        DIMCopyHypothesis(&sLocalHyp, MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA, uiHypNr, DIM_NR_OF_EBA_HYPOTHESES, MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA());
      }
      break;
      case (uint8)DIM_EBA_HYP_IDX_FEEDBACK:
      /* driver feedback */
      /* Restore original driver pedal value */
      #if(DIM_CFG_CALC_GAS_PEDAL_GRADIENT == MEDIC_OFF)
      DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->GasPedalGradient), MEDIC_p_GetDIMInGeneric()->fAccelPedalGrad, MEDIC_p_GetDIMInGeneric()->eAccelPadelGradStat, 0.0f);
      DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->GasPedalPosition), MEDIC_p_GetDIMInGeneric()->fAccelPedalPos , MEDIC_p_GetDIMInGeneric()->eAccelPadelStat    , 0.0f);
      #endif
       sLocalHyp.eGDBError = DIMRunModuleFeedback(fCycleTime, MEDIC_p_GetDimInputGlobal(), &sLocalHyp,  &MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Feedback, &DIM_FEEDBACK_PAR_data_eba );
      if (sLocalHyp.eGDBError == GDB_ERROR_NONE)
      {
        DIMCopyHypothesis(&sLocalHyp, MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA, uiHypNr, DIM_NR_OF_EBA_HYPOTHESES, MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA());
      }
      break;
      case (uint8)DIM_EBA_HYP_IDX_ACTIVITY:
      /* driver activity */
      sLocalHyp.eGDBError = DIMRunModuleActivity(fCycleTime, MEDIC_p_GetDimInputGlobal(), &sLocalHyp, &MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Activity, &DIM_ACTIVITY_PAR_data_eba);
      if (sLocalHyp.eGDBError == GDB_ERROR_NONE)
      {
        DIMCopyHypothesis(&sLocalHyp, MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA, uiHypNr, DIM_NR_OF_EBA_HYPOTHESES, MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA());
      }
      break;
      default:
      /* this case is never reached */
      break;
    }
  }
}

/*************************************************************************************************************************
  Functionname:        DIMInitEba                                                                         */ /*!

  @brief               Initialization function for DIM Module

  @description         This function will initialize all currently available EBA hypothesis 
                       and DIM's Attention, Feedback, Activity parameters to default values.

                       @startuml
                       start
                       :reset all hypothesis parameters;
                       :initialize all hypothesis modules;
                       stop
                       @enduml
          
  @return              void

  @param[in]           fCycleTime : The cycle time in seconds
  
  @glob_in             MEDIC_p_GetDIMHypothesisList(), MEDIC_p_GetDIMData()
  @glob_out            MEDIC_p_GetDIMHypothesisList(), MEDIC_p_GetDIMData()

  @c_switch_part       
  @c_switch_full       DIM_CFG_HYPO_EBA,MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                 None 
  @post                None

  @InOutCorrelation    Not defined  
  
  @testmethod          To be determined

  @traceability        Design Decision
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void DIMInitEba(void)
{
  uint8 uiI;

  for(uiI = 0u; uiI < DIM_NR_OF_EBA_HYPOTHESES; uiI++)
  {
    DIMInitHypothesis(&(MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA[uiI]));
  }
    (void)DIMInitModuleAttention(&MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Attention);
    (void)DIMInitModuleFeedback(&MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Feedback);
    (void)DIMInitModuleActivity(&MEDIC_p_GetDIMData()->Internal_Data_EBA.Internal_Activity);
}
#endif /* DIM_CFG_HYPO_EBA */

/*************************************************************************************************************************
  Functionname:        DIMProcess                                                                          */ /*!

  @brief               Main process function of DIM

  @description         Main process function of DIM. This function will initialize DIM module if not already initialized,
                       collects the new set of input values for the signals thats are of interest for DIM hypothesis, triggers 
                       evaluations of these input signals for creating DIM hypothesis probabilities during the vehicle cycle time
                       duration. Also this function will trigger the output creation from DIM module using the hypothesis 
                       probability information.

                       @startuml
                       Start
                            :Initialization of Measurment freeze structure;
                       if (Dim state is INIT) then (Initialization)
                        :Initialization of DIM module;
                            Note left
                                Initialization of all currently available 
                                EBA hypothesis, DIM's Attention, Feedback,
                                Activity Modules, driver hypothesis output
                                calibration parameter and DIM differentiator
                            End note
                        elseif (Dim state is OK) then (yes)
                            :Collect the DIM inputs from VDY; 
                            :signal preprocessing of DIM 
                            DIM module run for EBA
                            Freeze the data to MTS;
                            Note: function calls for the DIM module  
                        Endif 
                        Stop
                        @enduml

  @return               void

  @param[in]            fCycleTime : The cycle time in seconds
  

  @glob_in              @ref MEDIC_p_GetDIMInitialized() DIMState   
  @glob_in              @ref DIMState
  @glob_out             @ref DIMState

  @c_switch_part        @ref DIM_CFG_IN_PREPROC
                        @ref DIM_CFG_HYPO_EBA
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING  

  @pre                  None
  @post                 None 

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability        Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com 
*************************************************************************************************************************/
void DIMProcess(const float32 fCycleTime)
{
  MEDICCompState_t DIMState = MEDIC_e_GetSubCompState(MEDIC_SUB_COMP_DIM);
  if( MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.bDIMInitialized == b_FALSE)
  {
    DIMState = COMP_STATE_NOT_INITIALIZED;
  }

  switch (DIMState)
  {
  case COMP_STATE_NOT_INITIALIZED:
    DIMInit(fCycleTime);
    break;

  case COMP_STATE_RUNNING:
    DIMCollectInputs(); 

    #if (DIM_CFG_IN_PREPROC)
    DIMRunSigPreProc(fCycleTime, MEDIC_p_GetDimInputGlobal());
    #endif

    #if (DIM_CFG_HYPO_EBA)
    DIMRunModulesEBA(fCycleTime);
    #endif

    DIMFillCustomOut(fCycleTime, MEDIC_p_GetDimInputGlobal());
    break;

  default:
    DIMInit(fCycleTime);
    break;
  }
  MEDIC_v_SetSubComponentStates(MEDIC_SUB_COMP_DIM,DIMState);
}

/*************************************************************************************************************************
  Functionname:        DIMInit                                                                          */ /*!

  @brief                Main init function of DIM 

  @description          Main init function of DIM. This function will reset the signal status that was saved during
                        the last cycles, and also triggers the reset of DIM hypothesis related parameters, their
                        probabilities and confidence.This function is generally executed once during the start of DIM 
                        and the initialization status is retained and monitored, so that in case of any disruption in 
                        DIM operations, the module would be reinitialized. DIMInit is also called by simulation functions

                        @startuml
                        Start
                            :Assign default values to all Input data;
                        Note left
                            All vehicle dynamics inputs
                            are assigned their respective
                            default values. 
                        End note
                            :DIM module is initialized;
                            :Intialization of DIM Hypothesis ;
                        Note left :Initialization of DIM probabality and confidence \n to default values
                            :Initialization of the DIM differentiator function;
                        stop
                        @enduml
  @return               void

  @param[in]            fCycleTime : the nominal cycle time in seconds

  @glob_in              MEDIC_p_GetDimInputGlobal()
  @glob_out             @ref DIMData, @ref MEDIC_p_GetDIMInitialized(), @ref MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA()   

  @c_switch_part        @ref DIM_CFG_USE_DRV_OVRRDE_INPUT\n @ref DIM_CFG_HYPO_EBA, @ref DIM_CFG_OUT_CALIB, @ref DIM_CFG_IN_PREPROC
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                  [none]  
  @post                 [none]

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability        Design Decision
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
/* PRQA S 1505 1*//*DIMInit is also called by simulation functions */
void DIMInit(const float32 fCycleTime)
{
  /* clear input data */
  DIMSetInputValueBool(&(MEDIC_p_GetDimInputGlobal()->DriverBraking)         , b_FALSE , DIMInputSignalState_Missing);
  DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->GasPedalGradient)     , 0.0f     , DIMInputSignalState_Missing, 0.0f);
  DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->GasPedalPosition)     , 100.0f, DIMInputSignalState_Missing, 0.0f); /*PRQA S 3121*/ /* 20150626 CO: intended maximum */
  DIMSetInputValueUInt(&(MEDIC_p_GetDimInputGlobal()->TurnIndicator)         , 0     , DIMInputSignalState_Missing);
  DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->VehicleAcceleration)  , 0.0f     , DIMInputSignalState_Missing, 0.0f);
  DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->VehicleVelocity)      , 0.0f     , DIMInputSignalState_Missing, 0.0f);
  DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->SteeringWheelGradient), 0.0f     , DIMInputSignalState_Missing, 0.0f);
  DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->SteeringWheelAngle)   , 0.0f     , DIMInputSignalState_Missing, 0.0f);
  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
  DIMSetInputValueUInt(&(MEDIC_p_GetDimInputGlobal()->DriverOverride)        , FALSE , DIMInputSignalState_Missing);
  #endif

  #ifdef DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE
  #if (DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE)
  DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->MasterCylPressure)   , 0.0f     , DIMInputSignalState_Missing, 0.0f);
  #endif
  #endif
  
  MEDIC_p_GetWorkingData()->pInterCycleMeas->sGlobData.DIM.bDIMInitialized = b_TRUE;
  MEDIC_p_GetDIMData()->DIMHeaderData.uiBaseVersion = (uint32)DIM_AUTOVERSION;
  MEDIC_p_GetDIMData()->DIMHeaderData.uiStructSize  = sizeof(DIMData_t);
  
  #if (DIM_CFG_HYPO_EBA)
  DIMInitEba();
  #endif

  #if (DIM_CFG_OUT_CALIB)
  {
    uint32 uidx;
    MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA()->CalibMask = 0u;
    for (uidx = 0u; uidx < DIM_NO_CALIB_HYPS; uidx++)
    {
      MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA()->Probability[uidx] = 0;
      MEDIC_p_GetDIM_HYPOUT_CAL_DATA_EBA()->Confidence[uidx]  = (percentage_t)0;
    }
  }
  #endif

  #if (DIM_CFG_IN_PREPROC)
  DIMInitSigPreProc();
  #endif /* DIM_CFG_IN_PREPROC */
  _PARAM_UNUSED(fCycleTime); /* PRQA S 3119 *//* date: 2019-05-30, reviewer:Nalina M, reason: suppressing statement has no side effect - it can be removed */
}

/*************************************************************************************************************************
  Functionname:        DIMCollectInputs                                                                    */ /*!

  @brief               Reads Inputs from several inputs to DIM

  @description         This function will collect all the inputs like various signal states that are required
                       for evaluating various DIM hypothesis. The driver information and the vehicle dynamics information
                       both are fetched using this function during every vehicle cycle.

                       @startuml
                       start
                       if (generic signal state is ok?) then (yes)
                       :get accel pedal position;
                       :get accel pedal gradient;
                       if(steering wheel offset to be taken?) then (yes)
                       :get steering wheel angle and offset and add them up;
                       else (no)
                       :get steering wheel angle;
                       endif
                       :get steering wheel gradient;
                       :get brake info if signal valid;
                       :get turn indicator info if signal valid;
                       else (no)
                       :set all signal states to signal missing;
                       endif
                       :get speed limiter status;
                       if (VDY inputs state ok?) then (yes)
                       :get ego velocity and acceleration;
                       else (no)
                       :mark the ego velocity and acceleration info as missing;
                       endif
                       stop
                       @enduml

          
  @return              void

  @param[in]           void
      
  @glob_in             MEDIC_p_GetDIMInGeneric(), MEDIC_p_GetDIMInCustom(), EGO_SPEED_X_STATE, EGO_SPEED_X_RAW,EGO_SPEED_X_VAR_RAW,
  @glob_in             EGO_ACCEL_X_VAR_RAW, EGO_ACCEL_X_STATE, EGO_ACCEL_X_RAW, MEDIC_p_GetVehSig()
  @glob_out            MEDIC_p_GetDimInputGlobal() 

  @c_switch_part       DIM_CFG_USE_DRV_OVRRDE_INPUT, DIM_CFG_USE_KICKDOWN_INPUT
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING    

  @pre                 None 
  @post                None

  @InOutCorrelation    Not defined 
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_305}
    @satisfy{/COMMON/L3/Algo/01_RequirementSet/L3_ALGO_Req_Spec_EBA,L3_ALGO_EBA_913}
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com  
*************************************************************************************************************************/
static void DIMCollectInputs(void)
{
  /* Signal Validation is done where the signals are used */
  /* Generic data */
  if (MEDIC_p_GetDIMInGeneric()->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
  {
    /* Driver actions driving pedal */
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->GasPedalPosition), MEDIC_p_GetDIMInGeneric()->fAccelPedalPos,  MEDIC_p_GetDIMInGeneric()->eAccelPadelStat,     0.0f);
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->GasPedalGradient), MEDIC_p_GetDIMInGeneric()->fAccelPedalGrad, MEDIC_p_GetDIMInGeneric()->eAccelPadelGradStat, 0.0f);

    /* Driver actions steering wheel */
    #if (DIM_USE_SWA_OFFSET_CORRECTION)
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->SteeringWheelAngle), (MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngle + FCTVEH_pEgoOffset->Swa.Offset), MEDIC_p_GetDIMInGeneric()->eSteeringWheelAngleStat, 0);
    #else
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->SteeringWheelAngle),  MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngle                                 , MEDIC_p_GetDIMInGeneric()->eSteeringWheelAngleStat, 0.0f);
    #endif /* DIM_USE_SWA_OFFSET_CORRECTION */

    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->SteeringWheelGradient), MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngleGrad, MEDIC_p_GetDIMInGeneric()->eSteeringWheelAngleGradStat, 0.0f);

    #ifdef DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE
    #if (DIM_CFG_FEEDBACK_USE_BRAKE_PRESSURE)
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->MasterCylPressure), DIM_GetValue_BrakeCylinderPressure(), DIM_GetStat_BrakeCylinderPressure(), 0.0f);
    #endif
    #endif

    /* Driver actions brake pedal */
    if (MEDIC_p_GetDIMInGeneric()->eDriverBraking != eFCT_STATE_SIG_INVALID)
    {
      DIMSetInputValueBoolTest(&(MEDIC_p_GetDimInputGlobal()->DriverBraking), (boolean)(MEDIC_p_GetDIMInGeneric()->eDriverBraking == eFCT_STATE_SIG_ACTIVE), DIMInputSignalState_OK);
    }
    else
    {
      MEDIC_p_GetDimInputGlobal()->DriverBraking.eSignalQuality = DIMInputSignalState_Missing;
    }

    if(MEDIC_p_GetDIMInGeneric()->eTurnIndicator != eTurnIndicator_Invalid)
    {
      DIMSetInputValueUInt(&(MEDIC_p_GetDimInputGlobal()->TurnIndicator), MEDIC_p_GetDIMInGeneric()->eTurnIndicator, DIMInputSignalState_OK);
    }
    else
    {
      /* Final default value is determined in attention module */
      DIMSetInputValueUInt(&(MEDIC_p_GetDimInputGlobal()->TurnIndicator), 0u, DIMInputSignalState_Missing);
    }
  }
  else
  {
    /* Generic data - signal state not ok! */

    /* Driver actions driving pedal */
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->GasPedalPosition), 0.0f, DIMInputSignalState_Missing, 0.0f);
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->GasPedalGradient), 0.0f, DIMInputSignalState_Missing, 0.0f);

    /* Driver actions steering wheel */
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->SteeringWheelAngle),    0.0f, DIMInputSignalState_Missing, 0.0f);
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->SteeringWheelGradient), 0.0f, DIMInputSignalState_Missing, 0.0f);

    /* Driver actions brake pedal */
    MEDIC_p_GetDimInputGlobal()->DriverBraking.eSignalQuality = DIMInputSignalState_Missing;

    /* Turn Indicator */
    DIMSetInputValueUInt(&(MEDIC_p_GetDimInputGlobal()->TurnIndicator), 0u, DIMInputSignalState_Missing);
  }

  if (MEDIC_p_GetDIMInCustom()->eSpeedLimitActive != eFCT_STATE_SIG_INVALID)
  {
    DIMSetInputValueBoolTest(&(MEDIC_p_GetDimInputGlobal()->SpeedLimiter), (boolean)(MEDIC_p_GetDIMInCustom()->eSpeedLimitActive == eFCT_STATE_SIG_ACTIVE), DIMInputSignalState_OK);
  }
  else
  {
    MEDIC_p_GetDimInputGlobal()->SpeedLimiter.eSignalQuality = DIMInputSignalState_Missing;
  }

  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
  if (MEDIC_p_GetDIMInCustom()->sDriverInput.eDriverOverride != eFCT_STATE_SIG_INVALID)
  {
    DIMSetInputValueUInt(&(MEDIC_p_GetDimInputGlobal()->DriverOverride), MEDIC_p_GetDIMInCustom()->sDriverInput.eDriverOverride == eFCT_STATE_SIG_ACTIVE, DIMInputSignalState_OK);
  }
  else
  {
    MEDIC_p_GetDimInputGlobal()->DriverOverride.eSignalQuality = DIMInputSignalState_Missing;
  }
  #endif

  if (MEDIC_p_GetVDYDynRaw()->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
  {
    if ((MEDIC_f_GetEgoVelVarianceRaw() >= 0.0f) && (VDY_IO_STATE_VALID == MEDIC_u_GetIOStateEgoSpeedX()))
    {
      DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->VehicleVelocity), MEDIC_f_GetEgoVelRaw(), DIMInputSignalState_OK, MEDIC_f_GetEgoVelVarianceRaw());
    }
    else
    {
      DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->VehicleVelocity), 0.0f, DIMInputSignalState_Missing, 0.0f);
    }

    if ((MEDIC_f_GetEgoAccelVarianceRaw() >= 0.0f) && (VDY_IO_STATE_VALID == MEDIC_u_GetIOStateEgoAccelX()))
    {
      DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->VehicleAcceleration), MEDIC_f_GetEgoAccelRaw(), DIMInputSignalState_OK, MEDIC_f_GetEgoAccelVarianceRaw());
    }
    else
    {
      DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->VehicleAcceleration), 0.0f, DIMInputSignalState_Missing, 0.0f);
    }
  }
  else
  {
    /* VDY data - signal state not ok */
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->VehicleVelocity),     0.0f, DIMInputSignalState_Missing, 0.0f);
    DIMSetInputValueFloat(&(MEDIC_p_GetDimInputGlobal()->VehicleAcceleration), 0.0f, DIMInputSignalState_Missing, 0.0f);
  }

  #if (DIM_CFG_USE_KICKDOWN_INPUT)
  DIMSetInputValueBool(&(MEDIC_p_GetDimInputGlobal()->KickDown), MEDIC_p_GetVehSig()->VehSigAdd.KickDown, DIMInputSignalState_OK);
  #endif

  #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
  DIMSetInputValueUInt(&(MEDIC_p_GetDimInputGlobal()->DriverOverride), MEDIC_p_GetDIMInCustom()->sDriverInput.eDriverOverride, DIMInputSignalState_OK);
  #endif
}

/*************************************************************************************************************************
  Functionname:        DIMCopyHypothesis                                                                           */ /*!

  @brief               Copy local hypothesis data to output

  @description         This function copies the hypothesis data like probability and confidence to DIm output buffer,
                       by checking whether the DIM hypothesis data should be taken from internal evaluations or from the 
                       caliberation if enabled.

                       @startuml
                       start
                       if (hypothesis to be copied is \n one amongst the listed hypothesis?) then (yes)
                       :copy this hypothesis input to output buffer;
                       If (hypothesis calib data is available?) then (yes)
                       If (this hypothesis is within the range in calib \n and the calib mask is set for this hypo?) then (yes)
                       :save the probability and confidence info from calib to output buffer;
                       endif
                       endif
                       endif
                       stop
                       @enduml

          
  @return              void

  @param[in]           hypIn  : Internal hypothesis data
  @param[in]           uiHypNr  : Hypothesis number
  @param[in]           DIM_HYPOUT_CAL_DATA  : Calibrated Hypothesis data
  @param[in]           uiTotalHypNr : Total number of Hypothesis
  @param[in,out]       hypOut : Updated hypothesis data with calibrated Confidence and Probability values
  
  @glob_in             None 
  @glob_out            None
 
  @c_switch_part       DIM_CFG_OUT_CALIB
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING
  
  @pre                 None 
  @post                None
  
  @InOutCorrelation    Not defined
  
  @testmethod          Not defined

  @traceability        Design Decision
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void DIMCopyHypothesis(const GDB_DMHypothesis_t *hypIn, GDB_DMHypothesis_t hypOut[], uint8 uiHypNr, uint8 uiTotalHypNr, const DIM_HYPOUT_CAL_DATA_t *DIM_HYPOUT_CAL_DATA)
{
  /* Check if sufficient space on output is provided */
  if (uiHypNr < uiTotalHypNr)
  {
    /* Copy whole structure data */
    hypOut[uiHypNr] = *hypIn;

    #if (DIM_CFG_OUT_CALIB)
    /* As soon as calibration bit set for current hypothesis number, use calibration value instead of calculated one */
    if (DIM_HYPOUT_CAL_DATA != NULL)
    {
      if ( ((DIM_HYPOUT_CAL_DATA->CalibMask & (1uL<<uiHypNr)) != 0uL) && (uiHypNr < DIM_NO_CALIB_HYPS))
      {
        hypOut[uiHypNr].Confidence  = DIM_HYPOUT_CAL_DATA->Confidence[uiHypNr];
        hypOut[uiHypNr].Probability = DIM_HYPOUT_CAL_DATA->Probability[uiHypNr];
      }
    }
    #endif /* DIM_CFG_OUT_CALIB */
  }
  _PARAM_UNUSED(DIM_HYPOUT_CAL_DATA); /* PRQA S 3119 *//* date: 2019-05-30, reviewer:Nalina M, reason: suppressing statement has no side effect - it can be removed */
}

/*************************************************************************************************************************
  Functionname:        DIMInitHypothesis                                                                           */ /*!

  @brief               Fucntion to Initialize DIM hypothesis

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

  @InOutCorrelation    Not defined
  
  @testmethod          Not defined

  @traceability        Design Decision
  
  @author              Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static void DIMInitHypothesis(GDB_DMHypothesis_t *const hyp)
{
  hyp->Confidence  = (percentage_t)0;
  hyp->Probability = (sint8)0;
  hyp->eType       = DIMHypoType_No;
  hyp->eGDBError   = GDB_ERROR_UNKNOWN_TYPE;
}

/*************************************************************************************************************************
  Functionname:        DIM_v_SetState                                                                           */ /*!

  @brief               Save the DIM operation mode
  
  @description         DIM operation status like initialized or not is saved using this function.

                       Detailed Design
                       @startuml
                       Start
                        :Set operation mode;
                       Note left
                        Two Dim operation modes are STATE_INIT and STATE_OK 
                       End note
                       stop
                       @enduml

  @return              void
  
  @param[in,out]       hyp : DIM Hypothesis pointer to initialize with default values
  
  @glob_in             None  
  @glob_out            @ref DIMState 

  @c_switch_part       None 
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                 None  
  @post                None  

  @InOutCorrelation    Not defined   
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Not defined
  
  @author              Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com 
*************************************************************************************************************************/
/* PRQA S 1055,3240,3242 EOF */
/*************************************************************************************************************************
  Functionname:    DIMSetInputValueFloat                                                                            */ /*!

  @brief           Set the input value as a float

  @description     Set the input value as of float type

  @return          ALGO_INLINE void

  @param[in,out]   *inputValueStruct : 
  @param[in]       FloatValue : 
  @param[in]       SignalQuality : 
  @param[in]       StdDev : 

  @pre             [ None ]
  @post            [ None ]
*************************************************************************************************************************/
ALGO_INLINE void DIMSetInputValueFloat(DIMInputValue_t *inputValueStruct, float32 FloatValue, DIMInputSignalState_t SignalQuality, float32 StdDev) /* PRQA S 1055 *//*suppressing inline function declaration in header file for better code maintainability*/
{
  inputValueStruct->eSignalType    = DIMInputSignalType_Float;
  inputValueStruct->uValue.fValue  = FloatValue;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev        = StdDev;
}

/*************************************************************************************************************************
  Functionname:    DIMSetInputValueUInt                                                                             */ /*!

  @brief           Set the input value as unsigned int

  @description     Set the input value as unsigned int

  @return          ALGO_INLINE void

  @param[in,out]   *inputValueStruct : 
  @param[in]       UIntValue : 
  @param[in]       SignalQuality : 

  @pre             [ None ]
  @post            [ None ]
*************************************************************************************************************************/
ALGO_INLINE void DIMSetInputValueUInt(DIMInputValue_t *inputValueStruct, uint32 UIntValue, DIMInputSignalState_t SignalQuality)  /* PRQA S 1055 *//*suppressing inline function declaration in header file for better code maintainability*/
{
  inputValueStruct->eSignalType    = DIMInputSignalType_UnsignedInt;
  inputValueStruct->uValue.uiValue = UIntValue;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev        = 0.0f;
}

/*************************************************************************************************************************
  Functionname:    DIMSetInputValueSInt                                                                             */ /*!

  @brief           Set the input value as signed int

  @description     Set the input value as signed int

  @return          ALGO_INLINE void

  @param[in,out]   *inputValueStruct : 
  @param[in]       SIntValue : 
  @param[in]       SignalQuality : 

  @pre             [ None ]
  @post            [ None ]
*************************************************************************************************************************/
/* -- ALGO_INLINE void DIMSetInputValueSInt(DIMInputValue_t *inputValueStruct, sint32 SIntValue, DIMInputSignalState_t SignalQuality)
{
  inputValueStruct->eSignalType    = DIMInputSignalType_SignedInt
  inputValueStruct->uValue.iValue  = SIntValue
  inputValueStruct->eSignalQuality = SignalQuality
  inputValueStruct->fStdDev        = 0.0f
}  -- */

/*************************************************************************************************************************
  Functionname:    DIMSetInputValueBool                                                                             */ /*!

  @brief           Set the input value as boolean

  @description     Set the input value as boolean

  @return          ALGO_INLINE void

  @param[in,out]   *inputValueStruct : 
  @param[in]       BoolValue : 
  @param[in]       SignalQuality : 

  @pre             [ None ]
  @post            [ None ]
*************************************************************************************************************************/
ALGO_INLINE void DIMSetInputValueBool(DIMInputValue_t *inputValueStruct, boolean BoolValue, DIMInputSignalState_t SignalQuality) /* PRQA S 1055 *//*suppressing inline function declaration in header file for better code maintainability*/
{
  inputValueStruct->eSignalType    = DIMInputSignalType_Bool;
  inputValueStruct->uValue.bValue  = (BoolValue != b_FALSE) ? 1u : 0u;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev        = 0.0f;
}

/*************************************************************************************************************************
  Functionname:    DIMSetInputValueBoolTest                                                                         */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          ALGO_INLINE void

  @param[in,out]   *inputValueStruct : 
  @param[in]       BoolValue : 
  @param[in]       SignalQuality : 

  @pre             [ None ]
  @post            [ None ]
*************************************************************************************************************************/
ALGO_INLINE void DIMSetInputValueBoolTest(DIMInputValue_t *inputValueStruct, boolean BoolValue, DIMInputSignalState_t SignalQuality) /* PRQA S 1055 *//*suppressing inline function declaration in header file for better code maintainability*/
{
  inputValueStruct->eSignalType    = DIMInputSignalType_Bool;
  inputValueStruct->uValue.bValue  = (BoolValue != b_FALSE) ? 1u : 0u;
  inputValueStruct->eSignalQuality = SignalQuality;
  inputValueStruct->fStdDev        = 0.0f;
}

#endif  /* end of check for MEDIC DIM switch */
#endif  /* end of check for DIM2.0 switch */

/**\}*/
