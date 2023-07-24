/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim20_input_mgr.c

DESCRIPTION:               Input Manager for DIM

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/09/02 15:39:44CEST $

VERSION:                   $Revision: 1.30 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if (MEDIC_CFG_DIM20)
#include "dim20/dim20_int.h"
/*PRQA S 2982 EOF */ /*date: 2020-08-25, reviewer: Nalina M, reason: Suppressing because the value will be used in future.*/
#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
/****************************************************************************/
static uDIMInputValueUnion_t DIMGetInput(eDIMInputSig_t sig, boolean mux);
static DIMInputSignalState_t DIMGetInputSigSt(eDIMInputSig_t sig);
static float32 DIMInputGetStdDev(eDIMInputSig_t sig);
static DIMInputSignalType_t DIMGetInputSigType(eDIMInputSig_t sig);

/* functions used for signal preprocessing */
#if (DIM_CFG_IN_PREPROC)
static void DimDifferentiatorInit(DimIirFilt_t *pFilt);
static boolean DIMSigPreProcCheckEnableSts(eDIMInputSig_t index);
static DIMInputValue_t* DIMSigPreProcGetOutputPtr(eDIMInputSig_t index, DIMInputValue_t (*const pDimInputs)[NUM_OF_SIG]);
static DimIirFilt_t* DIMSigPreProcGetIirFiltPtr(eDIMInputSig_t index);
#endif

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         DIMInitInputMgr                                                                          */ /*!

  @brief                Function to initialize DIM inputs

  @description          Reset all DIM input signal parameters to their default values

                        @startuml
                        Start
                        :get the DIM input\nsignal list from GA;
                        Partition loop_for_all_signals {
                        :get default signal values and set;
                        :Set signal quality as missing;
                        :set stdev to 0;
                        :set the signal types to actual;
                        }
                        Stop
                        @enduml

  @return               void

  @param[in]            none

  @glob_in              MEDIC_p_GetDIMData
  @glob_out             MEDIC_p_GetDIMData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                  None
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-0007e0f8}
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void DIMInitInputMgr(void)
{
  DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG] = &(MEDIC_p_GetDIMData()->DimInputData.aDIMInputGlobal);
  uint8 index;
  
  for (index=0u; index<(uint8)NUM_OF_SIG; ++index)
  {
    (*pDimInputList)[index].uValue = DIMGetInput((eDIMInputSig_t)index, b_FALSE);/*PRQA S 4342*/ /*Reviewer: Rashmi Ramachandra
    Comment: the type of index cant be changed to enum type at the declaration time as it does not allow arithmetic operatiosn to be performed 
    like incrementing in for loop. Hence the variable is typecasted wherever required in enum form */
    (*pDimInputList)[index].eSignalQuality = DIMInputSignalState_Missing;
    (*pDimInputList)[index].fStdDev = 0.0f;
    (*pDimInputList)[index].eSignalType = DIMGetInputSigType((eDIMInputSig_t)index); /*PRQA S 4342*/
  }
}

/*************************************************************************************************************************
  Functionname:        DIMCollectInputs                                                                    */ /*!

  @brief               fetch inputs to DIM

  @description         This function will collect all the inputs like various signal states that are required
                       for evaluating various DIM hypothesis. The driver information and the vehicle dynamics information
                       both are fetched using this function during every vehicle cycle.

                       @startuml
                       Start
                       :get the DIM input\nsignal list from GA;
                        Partition loop_for_all_signals {
                        :get current signal quality\nand set;
                        :get current signal stdev\nand set;
                         If(DIM is in running state?\nANDsignal quality OK?) then (yes)
                        :get current value of signal;
                        Else (no)
                        :get default value of signal\nand set;
                        endif
                        }
                        Stop
                        @enduml

  @return              none

  @param[in]           none
      
  @glob_in             @ref MEDIC_p_GetDIMData()
  @glob_out            @ref MEDIC_p_GetDIMData() 

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING    

  @pre                 None 
  @post                None

  @InOutCorrelation    See description
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-896-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-931-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-933-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-940-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-945-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-951-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-954-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-955-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-959-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-960-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-961-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-962-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-964-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-965-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-966-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-967-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1154-0007e0f8}
  
  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com  
*************************************************************************************************************************/
void DIMCollectInputs(void)
{
  DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG] = &(MEDIC_p_GetDIMData()->DimInputData.aDIMInputGlobal);
  uint8 index;
  boolean current_value;

  for (index=0u; index<(uint8)NUM_OF_SIG; index++)
  {
    (*pDimInputList)[index].eSignalQuality = DIMGetInputSigSt((eDIMInputSig_t)index); /*PRQA S 4342*/ /*Reviewer: Rashmi Ramachandra
    Comment: the type of index cant be changed to enum type at the declaration time as it does not allow arithmetic operatiosn to be performed 
    like incrementing in for loop. Hence the variable is typecasted wherever required in enum form */
    (*pDimInputList)[index].fStdDev = DIMInputGetStdDev((eDIMInputSig_t)index); /*PRQA S 4342*/ 
    if ((MEDIC_e_GetSubCompState(MEDIC_SUB_COMP_DIM) == COMP_STATE_RUNNING) && (DIMIsInputOK((*pDimInputList)[index]) == b_TRUE))
    {
      current_value = b_TRUE;
    }
    else
    {
      current_value = b_FALSE;
    }
    (*pDimInputList)[index].uValue = DIMGetInput((eDIMInputSig_t)index, current_value); /*PRQA S 4342*/
  }
}

/*************************************************************************************************************************
  Functionname:        DIMGetInput                                                                          */ /*!

  @brief               DIM input signal value fetching

  @description         Value of a particular DIM input signal is fetched from the required ports
                        @startuml
                        Start
                        :get signal number;
                        Partition check_for_all_signals {
                        #orange:If(flag is set to\nuse current value of sig?) then (yes)
                        :get current value of signal;
                        Else (no)
                        :get default value of signal;
                        endif
                        }
                        :return input value;
                        Stop
                        @enduml

  @return              uDIMInputValueUnion_t: value of the signal

  @param[in]           sig: signal whose value has to be fetched
  @param[in]           mux: switch to choose between default value and actual value of the signal
     
  @glob_in             @ref MEDIC_f_GetEgoVelRaw,
                       @ref MEDIC_f_GetEgoAccelRaw,
                       @ref MEDIC_e_GetDriverBraking,
                       @ref MEDIC_e_GetTurnIndicator,
                       @ref MEDIC_f_GetAccelerationPedalPosition,
                       @ref MEDIC_f_GetGradAccelerationPedalPosition,
                       @ref MEDIC_f_GetSteeringWheelAngle,
                       @ref MEDIC_f_GetSteeringWheelAngleGrad,
                       @ref MEDIC_b_GetKickdown,
                       @ref MEDIC_e_DriverOverride,
                       @ref MEDIC_f_GetSpeedLimitStatus,
                       @ref MEDIC_p_GetDrvHeadPosX,
                       @ref MEDIC_p_GetDrvHeadPosY,
                       @ref MEDIC_p_GetDrvHeadPosZ,
                       @ref MEDIC_p_GetDrvHeadOrientationYaw,
                       @ref MEDIC_p_GetDrvHeadOrientationPitch,
                       @ref MEDIC_p_GetDrvHeadOrientationRoll,
                       @ref MEDIC_p_GetDrvGazeDirX,
                       @ref MEDIC_p_GetDrvGazeDirY,
                       @ref MEDIC_p_GetDrvGazeDirZ,
                       @ref MEDIC_p_GetDrvHeadPosConf,
                       @ref MEDIC_p_GetDrvGazeDirConf,
                       @ref MEDIC_p_GetDrvFatigueLvl,
                       @ref MEDIC_p_GetDrvConverationLvl,
                       @ref MEDIC_p_GetDrvMultitaskingLvl
  @glob_out            None

  @c_switch_part       @ref DIM_CFG_USE_KICKDOWN_INPUT, 
                       @ref DIM_CFG_USE_DRV_OVRRDE_INPUT, 
                       @ref DIM_USE_SWA_OFFSET_CORRECTION,
                       @ref DIM_CFG_USE_HEADPOSX_INPUT,
                       @ref DIM_CFG_USE_HEADPOSY_INPUT,
                       @ref DIM_CFG_USE_HEADPOSZ_INPUT,
                       @ref DIM_CFG_USE_HEADYAW_INPUT,
                       @ref DIM_CFG_USE_HEADPITCH_INPUT,
                       @ref DIM_CFG_USE_HEADROLL_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRX_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRY_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRZ_INPUT,
                       @ref DIM_CFG_USE_HEADPOS_CONF_INPUT,
                       @ref DIM_CFG_USE_GAZEDIR_CONF_INPUT,
                       @ref DIM_CFG_USE_FATIGUELVL_INPUT,
                       @ref DIM_CFG_USE_CONVERSATIONLVL_INPUT,
                       @ref DIM_CFG_USE_MULTITASKINGLVL_INPUT
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING   

  @pre                 None 
  @post                None

  @InOutCorrelation    See description
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1171-0007e0f8}
  
  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com  
*************************************************************************************************************************/
static uDIMInputValueUnion_t DIMGetInput(eDIMInputSig_t sig, boolean mux)
{
  uDIMInputValueUnion_t DIMInputRet;

  switch (sig)
  {
      /***********base inputs******************/
    case VehicleVelocity: 
        DIMInputRet.fValue = (mux==b_TRUE)?MEDIC_f_GetEgoVelRaw():DIM_ATTENTION_DEFAULT_LongVelocity;
        break;
    case VehicleAcceleration:
        DIMInputRet.fValue = (mux== b_TRUE)?MEDIC_f_GetEgoAccelRaw():DIM_ATTENTION_DEFAULT_LongAccel;
        break;
    case DriverBraking:
        DIMInputRet.bValue = (mux== b_TRUE)?((MEDIC_e_GetDriverBraking() != FALSE)?(TRUE):(FALSE)):(FALSE);
        break;
    case TurnIndicator:
        DIMInputRet.uiValue = (mux== b_TRUE)?MEDIC_e_GetTurnIndicator():0u;
        break;
    case GasPedalPosition:
        DIMInputRet.fValue = (mux== b_TRUE)?MEDIC_f_GetAccelerationPedalPosition():DIM_ATTENTION_DEFAULT_GasPedalPos;
        break;
    case GasPedalGradient:
        DIMInputRet.fValue = (mux== b_TRUE)?MEDIC_f_GetGradAccelerationPedalPosition():DIM_ATTENTION_DEFAULT_GasPedalGrad;
        break;
    case SteeringWheelAngle:
        #if (DIM_USE_SWA_OFFSET_CORRECTION)
        DIMInputRet.fValue = (mux== b_TRUE)?(MEDIC_f_GetSteeringWheelAngle()+DIMGetInput_SWA_Offset()):DIM_ACTIVITY_DEFAULT_SteeringWheelAngle;
        #else
        DIMInputRet.fValue = (mux== b_TRUE)?MEDIC_f_GetSteeringWheelAngle():DIM_ACTIVITY_DEFAULT_SteeringWheelAngle;
        #endif
        break;
    case SteeringWheelGradient:
        DIMInputRet.fValue = (mux == b_TRUE) ? MEDIC_f_GetSteeringWheelAngleGrad() : DIM_ACTIVITY_DEFAULT_Gradient_SWA;
        break;
    /***********end of base inputs***************/

    /***********custom inputs*******************/
    #if DIM_CFG_USE_KICKDOWN_INPUT
    case KickDown:
        DIMInputRet.bValue = (mux== b_TRUE)?MEDIC_b_GetKickdown():0;
        break;
    #endif
    #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
    case DriverOverride:
        DIMInputRet.uiValue = (mux== b_TRUE)?MEDIC_e_DriverOverride():0;
        break;
    #endif
    case SpeedLimiter:
        DIMInputRet.bValue = (mux== b_TRUE)?((uint32)MEDIC_f_GetSpeedLimitStatus()):0u;
        break;
    #if (DIM_CFG_USE_HEADPOSX_INPUT)
    case HeadPosX:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvHeadPosX():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_HEADPOSY_INPUT
    case HeadPosY:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvHeadPosY():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_HEADPOSZ_INPUT
    case HeadPosZ:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvHeadPosZ():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_HEADYAW_INPUT
    case HeadOrientationYaw:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvHeadOrientationYaw():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_HEADPITCH_INPUT
    case HeadOrientationPitch:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvHeadOrientationPitch():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_HEADROLL_INPUT
    case HeadOrientationRoll:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvHeadOrientationRoll():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_HEADPOS_CONF_INPUT
    case HeadPosConf:
        DIMInputRet.uiValue = (mux== b_TRUE)?(uint32)*MEDIC_p_GetDrvHeadPosConf():0u;
        break;
    #endif
    #if DIM_CFG_USE_GAZEDIRX_INPUT
    case GazeDirectionX:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvGazeDirX():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_GAZEDIRY_INPUT
    case GazeDirectionY:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvGazeDirY():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_GAZEDIRZ_INPUT
    case GazeDirectionZ:
        DIMInputRet.fValue = (mux== b_TRUE)?*MEDIC_p_GetDrvGazeDirZ():0.0f;
        break;
    #endif
    #if DIM_CFG_USE_GAZEDIR_CONF_INPUT
    case GazeDirConf:
        DIMInputRet.uiValue = (mux== b_TRUE)?(uint32)*MEDIC_p_GetDrvGazeDirConf():0u;
        break;
    #endif
    #if DIM_CFG_USE_FATIGUELVL_INPUT
    case FatigueLevel:
        DIMInputRet.uiValue = (mux== b_TRUE)?*MEDIC_p_GetDrvFatigueLvl():medic_eFatigue_Awake;
        break;
    #endif
    #if DIM_CFG_USE_CONVERSATIONLVL_INPUT
    case ConversationLevel:
        DIMInputRet.uiValue = (mux== b_TRUE)?*MEDIC_p_GetDrvConverationLvl():medic_eConversation_None;
        break;
    #endif
    #if DIM_CFG_USE_MULTITASKINGLVL_INPUT
    case MultitaskingLevel:
        DIMInputRet.uiValue = (mux== b_TRUE)?*MEDIC_p_GetDrvMultitaskingLvl():medic_eMultitasking_None;
        break;
    #endif     /***********end ofcustom inputs*************/

    default:
        DIMInputRet.uiValue = 0u;
        break;
  }
  return(DIMInputRet);
}

/*************************************************************************************************************************
  Functionname:        DIMInputGetStdDev                                                                          */ /*!

  @brief               Get standard deviation of signals

  @description         Fetching of standard deviation values for DIM input signals
                        @startuml
                        Start
                        :get signal number;
                        If(signal is EgoVel or EgoAcc?) then (yes)
                        :get stdev values from GA;
                        Else (no)
                        :set stdev to 0;
                        endif
                        :return stdev value;
                        Stop
                        @enduml

  @return              float32: standard deviation for a given input signal

  @param[in]           sig: signal for which the standard devaition value has to be fetched
     
  @glob_in             @ref MEDIC_f_GetEgoVelVarianceRaw,
                       @ref MEDIC_f_GetEgoAccelVarianceRaw
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                 None 
  @post                None

  @InOutCorrelation    See description
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1171-0007e0f8}
  
  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static float32 DIMInputGetStdDev(eDIMInputSig_t sig)
{
  float32 StdDevRet = 0.0f;

  if(sig == VehicleVelocity)
  {
    StdDevRet = DIMGetStdDev_VehicleVelocity();
  }
  else if(sig == VehicleAcceleration)
  {
    StdDevRet = DIMGetStdDev_VehicleAcceleration();
  }
  else
  {
     StdDevRet = 0.0f;
  }
  return(StdDevRet);
}

/*************************************************************************************************************************
  Functionname:        DIMGetInputSigSt                                                                          */ /*!

  @brief               DIM input signal state fetching

  @description         State of a particular DIM input signal is fetched from the required ports
                       @startuml
                        Start
                        :get signal number;
                        If(signal is GasPedalPos\nOR GasPedalGrad\nOR SteeringAngle\nOR SteeringGrad?) then (yes)
                        :get signal state\nvalues from GA;
                        Else (no)
                        :set signal state to OK;
                        Endif
                        :return signal state;
                        Stop
                        @enduml
 
  @return              DIMInputSignalState_t: state of the signal

  @param[in]           sig: signal whose state has to be fetched
     
  @glob_in             @ref MEDIC_e_GetAccelerationPedalState,
                       @ref MEDIC_e_GetAccelerationPedalGradState,
                       @ref MEDIC_e_GetSteeringWheelAngleState,
                       @ref MEDIC_e_GetSteeringWheelAngleGradState
  @glob_out            None

  @c_switch_part       @ref DIM_CFG_USE_KICKDOWN_INPUT,
                       @ref DIM_CFG_USE_DRV_OVRRDE_INPUT,
                       @ref DIM_USE_SWA_OFFSET_CORRECTION,
                       @ref DIM_CFG_USE_HEADPOSX_INPUT,
                       @ref DIM_CFG_USE_HEADPOSY_INPUT,
                       @ref DIM_CFG_USE_HEADPOSZ_INPUT,
                       @ref DIM_CFG_USE_HEADYAW_INPUT,
                       @ref DIM_CFG_USE_HEADPITCH_INPUT,
                       @ref DIM_CFG_USE_HEADROLL_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRX_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRY_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRZ_INPUT,
                       @ref DIM_CFG_USE_HEADPOS_CONF_INPUT,
                       @ref DIM_CFG_USE_GAZEDIR_CONF_INPUT,
                       @ref DIM_CFG_USE_FATIGUELVL_INPUT,
                       @ref DIM_CFG_USE_CONVERSATIONLVL_INPUT,
                       @ref DIM_CFG_USE_MULTITASKINGLVL_INPUT
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING

  @pre                 None 
  @post                None

  @InOutCorrelation    See description
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1154-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1171-0007e0f8}
  
  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static DIMInputSignalState_t DIMGetInputSigSt(eDIMInputSig_t sig)
{
  DIMInputSignalState_t DIMInputSigStRet;

  switch (sig)
  {
      /***********base inputs******************/
    case VehicleVelocity:
    case VehicleAcceleration:
      if (MEDIC_p_GetVehicleEgoMotion()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK)
      {
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    case DriverBraking:
      if ((MEDIC_p_GetVehicleData()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK) &&
        (MEDIC_e_GetDriverBraking() != eFCT_STATE_SIG_INVALID))
      {
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    case TurnIndicator:
      if ((MEDIC_p_GetVehicleData()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK) &&
        (MEDIC_e_GetTurnIndicator() != eTurnIndicator_Invalid))
      {
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    case GasPedalPosition:
      if (MEDIC_p_GetVehicleData()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK)
      {
        DIMInputSigStRet = MEDIC_e_GetAccelerationPedalState();
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    case GasPedalGradient:
      if (MEDIC_p_GetVehicleData()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK)
      {
        DIMInputSigStRet = MEDIC_e_GetAccelerationPedalGradState();
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    case SteeringWheelAngle:
      if (MEDIC_p_GetVehicleData()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK)
      {
        DIMInputSigStRet = MEDIC_e_GetSteeringWheelAngleState();
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    case SteeringWheelGradient:
      if (MEDIC_p_GetVehicleData()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK)
      {
        DIMInputSigStRet = MEDIC_e_GetSteeringWheelAngleGradState();
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    /***********end of base inputs***************/

    /***********custom inputs*******************/
    #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
    case DriverOverride:
      if (MEDIC_p_GetVehicleData()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK)
      {
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    #endif
    case SpeedLimiter:
      if ((MEDIC_p_GetVehicleData()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK) &&
        (MEDIC_f_GetSpeedLimitStatus() != eFCT_STATE_SIG_INVALID))
      {
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
    #if (DIM_CFG_USE_KICKDOWN_INPUT)
    case KickDown:
      if (MEDIC_p_GetVehSig()->sigHeader.eSigStatus == (AlgoSignalState_t)AL_SIG_STATE_OK)
      {
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
      }
      else
      {
        DIMInputSigStRet = medic_DIMInputSignalState_Missing;
      }
      break;
     #endif
    #if (DIM_CFG_USE_HEADPOSX_INPUT)
    case HeadPosX:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_HEADPOSY_INPUT
    case HeadPosY:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_HEADPOSZ_INPUT
    case HeadPosZ:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_HEADYAW_INPUT
    case HeadOrientationYaw:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_HEADPITCH_INPUT
    case HeadOrientationPitch:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_HEADROLL_INPUT
    case HeadOrientationRoll:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_GAZEDIRX_INPUT
    case GazeDirectionX:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_GAZEDIRY_INPUT
    case GazeDirectionY:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_GAZEDIRZ_INPUT
    case GazeDirectionZ:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_FATIGUELVL_INPUT
    case FatigueLevel:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_CONVERSATIONLVL_INPUT
    case ConversationLevel:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
    #if DIM_CFG_USE_MULTITASKINGLVL_INPUT
    case MultitaskingLevel:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
    #endif
     /***********end ofcustom inputs*************/
    default:
        DIMInputSigStRet = medic_DIMInputSignalState_OK;
        break;
  }
  return(DIMInputSigStRet);
}

/*************************************************************************************************************************
  Functionname:        DIMGetInputSigType                                                                          */ /*!

  @brief               DIM input signal type fetching

  @description         type of a particular DIM input signal is fetched from the required ports
                       @startuml
                        Start
                        :get signal number;
                        Partition check_for_all_sig {
                        :fill type of this sig;
                        Note right:signal types\nare float,uint,Sint and bool
                        }
                        :return sig type;
                        Stop
                        @enduml
 
  @return              DIMInputSignalType_t: type of the signal

  @param[in]           sig: signal whose type has to be fetched
     
  @glob_in             None
  @glob_out            None

  @c_switch_part       @ref DIM_CFG_USE_KICKDOWN_INPUT,
                       @ref DIM_CFG_USE_DRV_OVRRDE_INPUT,
                       @ref DIM_USE_SWA_OFFSET_CORRECTION,
                       @ref DIM_CFG_USE_HEADPOSX_INPUT,
                       @ref DIM_CFG_USE_HEADPOSY_INPUT,
                       @ref DIM_CFG_USE_HEADPOSZ_INPUT,
                       @ref DIM_CFG_USE_HEADYAW_INPUT,
                       @ref DIM_CFG_USE_HEADPITCH_INPUT,
                       @ref DIM_CFG_USE_HEADROLL_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRX_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRY_INPUT,
                       @ref DIM_CFG_USE_GAZEDIRZ_INPUT,
                       @ref DIM_CFG_USE_HEADPOS_CONF_INPUT,
                       @ref DIM_CFG_USE_GAZEDIR_CONF_INPUT,
                       @ref DIM_CFG_USE_FATIGUELVL_INPUT,
                       @ref DIM_CFG_USE_CONVERSATIONLVL_INPUT,
                       @ref DIM_CFG_USE_MULTITASKINGLVL_INPUT
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING
  @pre                 None 
  @post                None

  @InOutCorrelation    See description
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1171-0007e0f8}
  
  @author              Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static DIMInputSignalType_t DIMGetInputSigType(eDIMInputSig_t sig)
{
  DIMInputSignalType_t DIMInputSigTypeRet;

  switch (sig)
  {
    case VehicleVelocity:
    case VehicleAcceleration:
    case GasPedalPosition:
    case GasPedalGradient:
    case SteeringWheelAngle:
    case SteeringWheelGradient:
    #if (DIM_CFG_USE_HEADPOSX_INPUT)
    case HeadPosX:
    #endif
    #if (DIM_CFG_USE_HEADPOSY_INPUT)
    case HeadPosY:
    #endif
    #if (DIM_CFG_USE_HEADPOSZ_INPUT)
    case HeadPosZ:
    #endif
    #if DIM_CFG_USE_HEADYAW_INPUT
    case HeadOrientationYaw:
    #endif
    #if DIM_CFG_USE_HEADPITCH_INPUT
    case HeadOrientationPitch:
    #endif
    #if DIM_CFG_USE_HEADROLL_INPUT
    case HeadOrientationRoll:
    #endif
    #if DIM_CFG_USE_GAZEDIRX_INPUT
    case GazeDirectionX:
    #endif
    #if DIM_CFG_USE_GAZEDIRY_INPUT
    case GazeDirectionY:
    #endif
    #if DIM_CFG_USE_GAZEDIRZ_INPUT
    case GazeDirectionZ:
    #endif
        DIMInputSigTypeRet = DIMInputSignalType_Float;
        break;

    case DriverBraking:
    case SpeedLimiter:
    #if (DIM_CFG_USE_KICKDOWN_INPUT)
    case KickDown:
    #endif
        DIMInputSigTypeRet = DIMInputSignalType_Bool;
        break;

    case TurnIndicator:
    #if (DIM_CFG_USE_DRV_OVRRDE_INPUT)
    case DriverOverride:
    #endif
    #if DIM_CFG_USE_FATIGUELVL_INPUT
    case FatigueLevel:
    #endif
    #if DIM_CFG_USE_CONVERSATIONLVL_INPUT
    case ConversationLevel:
    #endif
    #if DIM_CFG_USE_MULTITASKINGLVL_INPUT
    case MultitaskingLevel:
    #endif
        DIMInputSigTypeRet = DIMInputSignalType_UInt;
        break;
    default:
        DIMInputSigTypeRet = 0;
        break;
  }
  return(DIMInputSigTypeRet);
}

#if (DIM_CFG_IN_PREPROC)

/*************************************************************************************************************************
  Functionname:         DIMInitSigPreProc                                                                        */ /*!

  @brief                DIM-Preprocessing initialization 

  @description          Triggers the initialization of differentiator.

                        @startuml
                        Start
                        :Initialization of the DIM differentiator;
                         Note left 
                          Initializes the previous input samples and previous cycle time samples 
                          (which is used to validate the steering wheel gradient) to zero
                         End note
                        stop
                        @enduml
          
  @return               Void

  @param[in]            Void

  @glob_in              DimIirFilt_Swa, DimIirFilt_GasPed
  @glob_out             DimIirFilt_Swa, DimIirFilt_GasPed

  @c_switch_part        @ref DIM_CFG_CALC_STEERING_ANGLE_GRADIENT,
                        @ref DIM_CFG_CALC_GAS_PEDAL_GRADIENT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING \n
                        @ref DIM_CFG_IN_PREPROC

  @pre                  None  
  @post                 None

  @InOutCorrelation     Not Applicable
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-0007e0f8}
  
  @author               Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
void DIMInitSigPreProc(void)
{
  /*Initilization of the differentiator*/
  #if (DIM_CFG_CALC_STEERING_ANGLE_GRADIENT)
  DimDifferentiatorInit(MEDIC_p_GetDimIirFiltSteeringAngle());
  #endif

  #if (DIM_CFG_CALC_GAS_PEDAL_GRADIENT)
  DimDifferentiatorInit(MEDIC_p_GetDimIirFiltGasPedal());
  #endif
}

/*************************************************************************************************************************
  Functionname:        DimDifferentiatorInit                                                                          */ /*!

  @brief               DIM differentiator initialization 

  @description         Initializes the differentiator values to default values. This is generally done during
                       the initialization of DIM module.
                       @startuml
                       Start
                       :reset the counter for \nnumber of input values;
                       :reset the input value buffer;
                       :reset the cycle time buffer;
                       Stop
                       @enduml

  @return              void

  @param[in]           pFilt :  pointer to the buffer for a particular signal
     
  @glob_in             None 
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING, @ref DIM_CFG_IN_PREPROC   

  @pre                 None 
  @post                None

  @InOutCorrelation    Not Applicable
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1153-0007e0f8}
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-0007e0f8}
  
  @author              Amr Abdelsabour | Amr Abdelsabour@continental-corporation.com  
*************************************************************************************************************************/
static void DimDifferentiatorInit(DimIirFilt_t *pFilt)
{
  uint8 index;

  pFilt->uiValues = 0u;

  for (index = 0; index < NO_PRE_INPUT_SAMPLES; index++)
  {
    pFilt->fInputs[index] = 0.0f;
  }

  for (index = 0; index < NO_PRE_TIME_SAMPLES; index++)
  {
    pFilt->fCycleTimes[index] = 0.0f;
  }
}

/*************************************************************************************************************************
  Functionname:         DIMRunSigPreProc                                                      */ /*!

  @brief                signal-gradient calculation

  @description          Main function for the preprocessing of DIM signals. This is mainly used for calculating the
                        gradient values of various signals using the differentiator by measuring the signal values for 
                        consecutive cycles.

                        @startuml
                        Start
                        :get DIM input list;
                        Partition loop_over_all_inputs {
                        #orange:if(signal requires gradient calc?) then (yes)
                        :get ptr to the location\nto store gradient output;
                        :get ptr to the buffer\nto store current sig values;
                        #orange:if(current signal quality OK?) then (yes)
                        :calculate gradient for\ncurrent signal and\nstore it in location\npointed by output ptr;
                        :mark gradient calculation\nas passed;
                        Else (no)
                        :mark gradient calc\nas failed;
                        Endif
                        #orange:if(grad calc passed?) then (yes)
                        :set grad signal quality as OK;
                        Else (no)
                        If(current signal quality is NOK?) then (yes)
                        :grad signal quality=\ncurrent signal quality;
                        Else (no)
                        :grad signal quality=\nmissing;
                          Endif
                        :reinit the preproc buffers;
                          Endif
                          Else (no)
                          :set grad calc as failed;
                          Endif
                          }
                          Stop
                          @enduml

  @return               void

  @param[in]            fCycleTime : The function cycle time
  @param[in,out]        pDimInput : The pointer to the structure containing all DIM input signals

  @glob_in              @ref MEDIC_p_GetDIMData
  @glob_out             @ref MEDIC_p_GetDIMData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING \n
                        @ref DIM_CFG_IN_PREPROC

  @pre                  None  
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-0007e0f8}
  
  @author               Amr Abdelsabour | Amr.Abdelsabour@continental-corporation.com
*************************************************************************************************************************/
void DIMRunSigPreProc(float32 fCycleTime)
{
  DIMInputValue_t (*const pDimInputList)[NUM_OF_SIG] = &(MEDIC_p_GetDIMData()->DimInputData.aDIMInputGlobal);
  boolean bGradientValidity = b_FALSE;
  DIMInputValue_t* pDimInputSigPreProc;
  DIMInputValue_t* pDimOutputSigPreProc;
  DimIirFilt_t* pDimIirFilt;
  uint8 index;

  for (index= (uint8)0; index< (uint8)NUM_OF_SIG; index++)
  {
    /* check if the signal is enabled for preproc and then use the signal */
    pDimInputSigPreProc = (DIMSigPreProcCheckEnableSts((eDIMInputSig_t)index) == b_TRUE)?(&(*pDimInputList)[index]):(NULL); /*PRQA S 0315*/ /*PRQA S 4342*/ /*Reviewer: Rashmi Ramachandra
    Comment: the type of index cant be changed to enum type at the declaration time as it does not allow arithmetic operatiosn to be performed 
    like incrementing in for loop. Hence the variable is typecasted wherever required in enum form */

    /* proceed only if there is a valid input signal that is enabled for preproc*/
    if (pDimInputSigPreProc != NULL)
    {
      /* get output ptr for signal preproc output */
      pDimOutputSigPreProc = DIMSigPreProcGetOutputPtr((eDIMInputSig_t)index, pDimInputList);/*PRQA S 4342*/ 

      /* get buffer pointer for the current signal*/
      pDimIirFilt = DIMSigPreProcGetIirFiltPtr((eDIMInputSig_t)index); /*PRQA S 4342*/ 

      /* Check signal quality of the input signal*/
      if(pDimInputSigPreProc->eSignalQuality == (uint8)medic_DIMInputSignalState_OK)
      {
        /* Calculating the gradient from input signal*/
        bGradientValidity = DimDifferentiatorRun(&(pDimOutputSigPreProc->uValue.fValue), pDimInputSigPreProc->uValue.fValue, fCycleTime, pDimIirFilt);
      }
      else
      {
        bGradientValidity = b_FALSE;
      }

      if (bGradientValidity == b_TRUE)
      {
        /* Gradient is valid */
        pDimOutputSigPreProc->eSignalQuality = (uint8)medic_DIMInputSignalState_OK;
      }
      else
      {
        if(pDimInputSigPreProc->eSignalQuality != (uint8)medic_DIMInputSignalState_OK)
        {
          pDimOutputSigPreProc->eSignalQuality = pDimInputSigPreProc->eSignalQuality;
        }
        else
        {
          /* Gradient is invalid */
          pDimOutputSigPreProc->eSignalQuality = (uint8)medic_DIMInputSignalState_Missing;
        }
        /* Reinitialize Differentiator due to invalid gradient */
        DimDifferentiatorInit(pDimIirFilt);
      }
    }
    else
    {
      bGradientValidity = b_FALSE;
    }
  }
}

#if DIM_CFG_USE_GRAD_CALC_TIMEBASED
/*************************************************************************************************************************
  Functionname:        DimDifferentiatorRun                                                                          */ /*!

  @brief               DIM differentiator function to calculate gradient based on varied cycle times

  @description         Main function for calculating the differentiation of DIM signals. This function considers the inputs 
                       for 2 consecutive cycles, calculates the delta change in value and time and find out the dx/dt form
                       of differential input. 
                       @startuml
                       Start
                       :Num of samples=total time frame under observation/current cycle time;
                       :max number of samples\ngreater thancalculated number of samples\ngreater than minimum 1 sample;
                       :total time for grad calc=\nsum of cycle times for\nN number of samples\nwhere N is calculated no.of samples;
                       :sample position in buffer\nto use for gradient calc=\n(buffer ptr current position\n+buffer size - calc no.of samples)\n%buffer size;
                       :gradient=(current signal value -\nsample value at calculated sample position)/\n(calc.no.of samples*curr cycle time);
                       :return diff output;
                       :store current signal value in buffer;
                       :increment the buffer ptr by 1;
                       Stop
                       @enduml
          
  @return              retValid   : A boolean indicating the validity of the calculated output [0:Invalid , 1: Valid]

  @param[in,out]       fOutValue  : The differentiated output signal
  @param[in]           fInValue   : The input signal to be differentiated
  @param[in]           fCycleTime : The function cycle time
  @param[in,out]       pFilt      : The static differentiator structure
     
  @glob_in             None 
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING,DIM_CFG_IN_PREPROC   

  @pre                 None
  @post                None

  @InOutCorrelation    output = d(value)/d(time)
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        
                       @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-0007e0f8}
  
  @author              Rashmi Ramachandra| rashmi.ramachandra@continental-corporation.com  
*************************************************************************************************************************/
boolean DimDifferentiatorRun(float32 *fOutValue, float32 fInValue, float32 fCycleTime, DimIirFilt_t *pFilt)
{
  uint8 uiNumofInSamples;
  float32 fInSigGrad;
  uint8 index;
  float32 fTotalCycleTime;
  boolean bGradValidity;

  /*getting nr of input samples for the current cycle time*/
  if (fCycleTime > C_F32_DELTA)
  {
    /*PRQA S 4395 1 */ /*date: 2020-08-25, reviewer: Nalina M, reason: Supressing because casting is required and no side effects*/
    uiNumofInSamples = (uint8)((DIM_GRAD_FILTER_TIME) / fCycleTime);   /* PRQA S 3121 *//* physical constant C. Obst 26.08.14 */
    uiNumofInSamples = MAX(MIN(NO_PRE_INPUT_SAMPLES, uiNumofInSamples), 1u);

    fTotalCycleTime = fCycleTime;
    for (index = 0; index < (uiNumofInSamples - (uint8)1); index++)
    {
      fTotalCycleTime += pFilt->fCycleTimes[(pFilt->uiValues + NO_PRE_INPUT_SAMPLES - index) % NO_PRE_INPUT_SAMPLES];
    }

    if (fTotalCycleTime > C_F32_DELTA)
    {
      /*calculating gradient between current input sample and sample uiNumofInSamples before*/
      fInSigGrad = (fInValue - ((float32)pFilt->fInputs[((pFilt->uiValues + NO_PRE_INPUT_SAMPLES)
        - uiNumofInSamples) % NO_PRE_INPUT_SAMPLES])) / fTotalCycleTime;
      bGradValidity = b_TRUE;
    }
    else
    {
      fInSigGrad = 0.0f;
      bGradValidity = b_FALSE;
    }
  }
  else
  {
    fInSigGrad = 0.0f;
    bGradValidity = b_FALSE;
  }

  *fOutValue = fInSigGrad;
  pFilt->fInputs[pFilt->uiValues] = fInValue;
  pFilt->fCycleTimes[pFilt->uiValues] = fCycleTime;
  /*move pointer to new location*/
  pFilt->uiValues = (pFilt->uiValues + 1u) % NO_PRE_INPUT_SAMPLES;

  return bGradValidity;
}

#else
 /*************************************************************************************************************************
   Functionname:        DimDifferentiatorRun                                                                          */ /*!

   @brief               DIM differentiator function to calculate gradient of a signal based on fixed cycle time and samples.

   @description         Main function for calculating the differentiation of DIM signals. This function considers the inputs
                        for 2 consecutive cycles, calculates the delta change in value and time and find out the dx/dt form
                        of differential input.
                        @startuml
                        Start
                        If (no samples to consider?) then (yes)
                        :diff time t=0,\ndifferential output 0;
                        Elseif (1 sample available?) then (yes)
                        :diff time t=cycle time;
                        :diff value=input sample-immediate previous sample;
                        Elseif (2 samples available?) then (yes)
                        :diff time t=current cycle time+previous cycle time;
                        :diff value=current input sample-immediate previous sample;
                        Else (no)
                        :diff time t=current cycle time+previous 2 cycle times;
                        :diff value= current input sample-immediate previous sample;
                        Endif
                        If(dt is valid, > 0.0001?) then (yes)
                        :diffout=diff value/diff time;
                        Else (no)
                        :diffout=0;
                        Endif
                        :store the values available till this cycle;
                        :store the time elapsed in each cycle;
                        If(number of values are less then 3?) then (yes)
                        :accommodate next samples;
                        Else (no)
                        :not more than 3 samples to be considered;
                        Endif
                        :return diff output;
                        Stop
                        @enduml


   @return              retValid   : A boolean indicating the validity of the calculated output [0:Invalid , 1: Valid]

   @param[in,out]       fOutValue  : The differentiated output signal
   @param[in]           fInValue   : The input signal to be differentiated
   @param[in]           fCycleTime : The function cycle time
   @param[in,out]       pFilt      : The static differentiator structure

   @glob_in             None
   @glob_out            None

   @c_switch_part       None
   @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING,DIM_CFG_IN_PREPROC

   @pre                 None
   @post                None

   @InOutCorrelation    output = d(value)/d(time)

   @testmethod          Test of output data (dynamic module test)

   @traceability
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-0007e0f8}

   @author              Amr Abdelsabour | Amr Abdelsabour@continental-corporation.com
 *************************************************************************************************************************/
 boolean DimDifferentiatorRun(float32 *fOutValue, float32 fInValue, float32 fCycleTime, DimIirFilt_t *pFilt)
 {
   boolean retValid;       /* Indicator of output validity */
   float32 diffTime;       /* difference in time (dt) */
   float32 diffValue;      /* difference in value (dx) */

   /* At t == 0 the output shall be equal to zero  */
   if (pFilt->uiValues == 0uL)
   {
     diffTime = fCycleTime;
     diffValue = 0.0f;
   }
   /* At t == dt, only 1 previous input value is considered */
   else if (pFilt->uiValues == 1uL)
   {
     diffTime = fCycleTime;
     diffValue = fInValue - pFilt->fInputs[0];
   }
   /* At t == 2dt, 2 previous input values shall be considered */
   else if (pFilt->uiValues == 2uL)
   {
     diffTime = pFilt->fCycleTimes[0] + fCycleTime;
     diffValue = fInValue - pFilt->fInputs[1];
   }
   /* At t >= 3dt, 3 previous input values shall be considered */
   else
   {
     diffTime = pFilt->fCycleTimes[1] + pFilt->fCycleTimes[0] + fCycleTime;
     diffValue = fInValue - pFilt->fInputs[2];
   }

   /* Determining the validity of the output and accordingly calculating the output value */
   if (diffTime > C_F32_DELTA)
   {
     *fOutValue = diffValue / diffTime;
     retValid = b_TRUE;
   }
   else
   {
     *fOutValue = 0.0f;
     retValid = b_FALSE;
   }

   /* Storage of the previous input values to be used in later calculations */
   pFilt->fInputs[2] = pFilt->fInputs[1];
   pFilt->fInputs[1] = pFilt->fInputs[0];
   pFilt->fInputs[0] = fInValue;

   /* Storage of the previous cycle times to be used in later calculations */
   pFilt->fCycleTimes[1] = pFilt->fCycleTimes[0];
   pFilt->fCycleTimes[0] = fCycleTime;

   /* Counter function of the values to be calculated. After t==3dt, no more additional values need to be considered */
   if (pFilt->uiValues < 3U)
   {
     pFilt->uiValues++;
   }

   return retValid;
 }
#endif
/*************************************************************************************************************************
  Functionname:         DIMSigPreProcCheckEnableSts                                                      */ /*!

  @brief                Checks if the signal shall be preprocessed

  @description          Checks if the signal shall be preprocessed
                        @startuml
                        Start
                        If(GasPedalPosition) then (yes)
                        : the input signal is to be preprocessed(flag will set);
                        ElseIf(SteeringWheelAngle) then (yes)
                        : the input signal is to be preprocessed(flag will set);
                        Else (no)
                        : Reset the flag;
                        Stop
                        @enduml

  @return               void

  @param[in]            index: signal number
  @param[out]           boolean : true if the signal is to be preprocessed, else false

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref DIM_CFG_CALC_GAS_PEDAL_GRADIENT \n
                        @ref DIM_CFG_CALC_STEERING_ANGLE_GRADIENT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING \n
                        @ref DIM_CFG_IN_PREPROC

  @pre                  None  
  @post                 None

  @InOutCorrelation     
                       | Input Signal       | enablestatus                        |
                       |:-------------------|:------------------------------------|
                       | GasPedalPosition   | DIM_CFG_CALC_GAS_PEDAL_GRADIENT     |
                       | SteeringWheelAngle | DIM_CFG_CALC_STEERING_ANGLE_GRADIENT|
                       | default            | b_FALSE                             |

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-0007e0f8}
  
  @author               Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static boolean DIMSigPreProcCheckEnableSts(eDIMInputSig_t index)
{
  boolean enablests;

  switch (index)
  {
    case GasPedalPosition:
        enablests = (boolean)DIM_CFG_CALC_GAS_PEDAL_GRADIENT;
        break;
    case SteeringWheelAngle:
        enablests = (boolean)DIM_CFG_CALC_STEERING_ANGLE_GRADIENT;
        break;
    default:
        enablests = b_FALSE;
        break;
  }
  return(enablests);
}

/*************************************************************************************************************************
  Functionname:         DIMSigPreProcGetOutputPtr                                                      */ /*!

  @brief                provides location where the preprocessed signal output shall be saved

  @description          provides location where the preprocessed signal output shall be saved
                        @startuml
                        Start
                        If (GasPedalPosition) then (yes)
                        : provides location where the GasPedalPosition output shall be saved;
                        ElseIf (SteeringWheelAngle) then (yes)
                        : provides location where the SteeringWheelAngle output shall be saved;
                        Else (no)
                        : provides no location;
                        Endif
                        Stop
                        @enduml

  @return               void

  @param[in]            index: signal number
  @param[in]            pDimInputs: input signal list
  @param[out]           ptr to the output loaction

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref DIM_CFG_CALC_GAS_PEDAL_GRADIENT \n
                        @ref DIM_CFG_CALC_STEERING_ANGLE_GRADIENT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING \n
                        @ref DIM_CFG_IN_PREPROC

  @pre                  None  
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-0007e0f8}
  
  @author               Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static DIMInputValue_t* DIMSigPreProcGetOutputPtr(eDIMInputSig_t index, DIMInputValue_t (*const pDimInputs)[NUM_OF_SIG])
{
  DIMInputValue_t* pDimSigPreprocOut;

  switch (index)
  {
    #if (DIM_CFG_CALC_GAS_PEDAL_GRADIENT)
    case GasPedalPosition:
        pDimSigPreprocOut = &((*pDimInputs)[GasPedalGradient]);
        break;
    #endif
    #if (DIM_CFG_CALC_STEERING_ANGLE_GRADIENT)
    case SteeringWheelAngle:
        pDimSigPreprocOut = &((*pDimInputs)[SteeringWheelGradient]);
        break;
    #endif
    default:
        pDimSigPreprocOut = NULL;
        break;
  }
  return(pDimSigPreprocOut);
}

/*************************************************************************************************************************
  Functionname:         DIMSigPreProcGetIirFiltPtr                                                      */ /*!

  @brief                provides location of buffer to store signal samples

  @description          provides location of buffer to store signal samples
                        @startuml
                        Start
                        If (GasPedalPosition) then (yes)
                        : provides location of buffer to store GasPedalPosition;
                        ElseIf (SteeringWheelAngle) then (yes)
                        : provides location of buffer to store SteeringWheelAngle;
                        Else (no)
                        : provides no location;
                        Endif
                        Stop
                        @enduml

  @return               void

  @param[in]            index: signal number
  @param[out]           ptr to the location where signal samples are buffered

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref DIM_CFG_CALC_GAS_PEDAL_GRADIENT \n
                        @ref DIM_CFG_CALC_STEERING_ANGLE_GRADIENT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING \n
                        @ref DIM_CFG_IN_PREPROC

  @pre                  None  
  @post                 None

  @InOutCorrelation     See description
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1157-0007e0f8}
  
  @author               Rashmi Ramachandra | rashmi.ramachandra@continental-corporation.com
*************************************************************************************************************************/
static DimIirFilt_t* DIMSigPreProcGetIirFiltPtr(eDIMInputSig_t index)
{
  DimIirFilt_t* pDimSigPreprocFilt;

  switch (index)
  {
    #if (DIM_CFG_CALC_GAS_PEDAL_GRADIENT)
    case GasPedalPosition:
        pDimSigPreprocFilt = MEDIC_p_GetDimIirFiltGasPedal();
        break;
    #endif
    #if (DIM_CFG_CALC_STEERING_ANGLE_GRADIENT)
    case SteeringWheelAngle:
        pDimSigPreprocFilt = MEDIC_p_GetDimIirFiltSteeringAngle();
        break;
    #endif
    default:
        pDimSigPreprocFilt = NULL;
        break;
  }
  return(pDimSigPreprocFilt);
}
#endif /* DIM_CFG_IN_PREPROC */

#endif  /* #if MEDIC_CFG_DRIVER_INTENTION_MONITORING */
#endif /* MEDIC_CFG_DIM20 */
