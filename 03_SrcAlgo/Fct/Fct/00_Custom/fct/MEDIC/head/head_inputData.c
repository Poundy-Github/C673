/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_inputData.h

DESCRIPTION:               Implementation of the head output arbitration

AUTHOR:                    $Author: Veerashettappa, Nagaraja (uidp9076) $

CREATION DATE:             $Date: 2020/07/29 05:20:55CEST $

VERSION:                   $Revision: 1.3.13.13 $

LEGACY VERSION:            1.1.1.9.1.4 (+ mainstream changes)

**************************************************************************** */

/**
@defgroup head_inputData HEAD_INPUTDATA
@ingroup Medic_head
@{ **/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#include "head/head_int.h"
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/
#define EGOVELOCITY_THRESHOLD_35kph     (9.72f)
#define EGOVELOCITY_THRESHOLD_48kph     (13.33f)
#define EGOVELOCITY_THRESHOLD_61kph     (16.94f)
#define EGOVELOCITY_THRESHOLD_22kph     (6.111f)
#define EGOVELOCITY_THRESHOLD_10kph     (2.778f)
#define EGOVELOCITY_THRESHOLD_15kph     (4.167f)
#define EGOVELOCITY_THRESHOLD_8kph      (2.222f)
#define LATERAL_VELOCITY_THRESOLD_9kph  (2.5f)
#define DISTY_THRESHOLD_1_6_5           (1.65f)
#define DISTY_THRESHOLD_1_5             (1.5f)
#define DISTY_THRESHOLD_1_0             (1.0f)
#define DISTY_THRESHOLD_1_2             (1.2f)
#define DISTY_THRESHOLD_1_8             (1.8f)
#define DISTY_THRESHOLD_2_8             (2.8f)
#define DRIVER_BRAKING                  (1)
#define EGO_ACCELL						(-1.0f)
/*****************************************************************************
  MACROS
*****************************************************************************/
/*Counter Measure for PED Collision False Triggering*/
#define INHIBIT_PEDCYCCOLL              (1024)    // 0000 0100 0000 0000
/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/*****************************************************************************
  CONSTS
*****************************************************************************/
/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*!  @cond Doxygen_Suppress */
/*! @brief HEAD Extra Input Value List*/
HEADExtraInputValueList_t HEADExtraInputValueList;

/*! @brief Main HEAD input scalar signal list*/
static HEADInputValueList_t    HEADInputValues; /* PRQA S 3218 *//* date: 2018-10-26, reviewer:Krupa H R, reason:suppressing HEADInputValues for better code maintainability */

/*! @brief Bool variable to indicate the HEAD is Initialized or not.*/
boolean bHEADInitialized = FALSE;
/*! @endcond */
/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static void HEADFilterDriverFeedback(const HEADInputData_t *pInputData, float32 *OutValue);
/* Application callback of HEAD */
static eGDBError_t HEADCustomGetHypValue(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, float32 *retValue);
static eGDBError_t HEADCustomFilterHypValue(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, uint8 uiModuleNr, float32 *pInOutValue );
static eGDBError_t HEADCustomGetIndependentValue(const HEADInputData_t *pInputData, eHEADParamOutType_t eIndOutType, float32 *pretValue,  uint8 uiModuleNr);
static eGDBError_t HEADCustomFilterIndependentValue(const HEADInputData_t *pInputData, eHEADParamOutType_t eIndOutType, uint8 uiModuleNr, float32 *pInOutValue );

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         HEADInitInput                                                                               */ /*!

  @brief                Initializes the HEAD input data

  @description          The function initializes the HEAD input data for the first time

                        @startuml
                        start
                            partition HeadInitialization{
                            if(Check for the NULL pointer) then (Yes)
                            :Null pointer error are updated;
                            else
                            :Head input intializes for first time;
                            Note right
                            pModuleList,pInputValueList and 
                            eOpMode etc are intialized.
                            endnote
                            endif
                            }
                            :Return error type;
                        stop
                        @enduml

  @return               eGDBError_t  : GDB error type is returned

  @param[in]            pModuleList  : Pointer to module list
  @param[in]            fCycleTime   : The function cycle time
  

  @glob_in              @ref HEADHypothesisList\n @ref HEADInputValues\n
  @glob_out             @ref HEADInputData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADInitInput(HEADModuleList_t *pModuleList, float32 fCycleTime)
{
  eGDBError_t retValue = GDB_ERROR_NONE;

  if(pModuleList == NULL)
  {
    retValue = GDB_ERROR_POINTER_NULL;
  }
  else
  {
    MEDIC_p_ModHEADInputData()->pModuleList      = pModuleList;
    MEDIC_p_ModHEADInputData()->eHEADMainMode    = HEAD_PAR_MODE_SETTING_INIT; /* Cust-Req-ID: 37217 */
    MEDIC_p_ModHEADInputData()->pInputValueList  = &HEADInputValues;
    MEDIC_p_ModHEADInputData()->eOpMode          = HEADOpMode_Running;

    MEDIC_p_ModHEADInputData()->fCycleTime       = fCycleTime;
    MEDIC_p_ModHEADInputData()->uiCurrentCycle   = 0u;

    /* Initialise application callbacks of HEAD */
    MEDIC_p_ModHEADInputData()->CustCallbacks.fpCustomGetHypValue = &HEADCustomGetHypValue;
    MEDIC_p_ModHEADInputData()->CustCallbacks.fpCustomFilterHypValue = &HEADCustomFilterHypValue;
    MEDIC_p_ModHEADInputData()->CustCallbacks.fpCustomGetIndValue = &HEADCustomGetIndependentValue;
    MEDIC_p_ModHEADInputData()->CustCallbacks.fpCustomFilterIndValue = &HEADCustomFilterIndependentValue;

    MEDIC_p_ModHEADInputData()->rgHypothesisList = (const HEADHypothesisList_t*)&HEADHypothesisList;
  }

  return retValue;
}

/*************************************************************************************************************************
  Functionname:         HEADGetInputData                                                                        */ /*!

  @brief                Gets data from Vehicle 

  @description          Gets data from Vehicle
                        @startuml
                        Start
                        Partition #LightBlue **((HEAD_CFG_TURN_ASSIST))** {
                        :Set Turn Indicator in steering Direction flag;
                        Note
                        True:If the Turn Indicator in steering Direction
                        False:If the Turn Indicator is not in steering Direction
                        End note
                        }
                        :Set Cycel time;
                        Note left:Set Cycel time to current value
                        :Update HEAD Hypotheses list;
                        Note right
                        ->if CD Hypothesis signal states is OK: copy CD Hypothesis list to 
                          HEAD Hypothisis list
                        ->if CD Hypothesis signal states is INIT: Update HEAD CD hypothesis 
                          signal quality as default. 
                        ->if CD Hypothesis signal states is INVALID: Update HEAD CD hypothesis 
                          signal quality as Missing. 
                        End note
                        :Update HEAD Main Mode to HEAD Input Data;
                        Note right
                        Update HEAD Main Mode based on the Mode Setting from DIM.
                        (If ACC is active then Set HEAD main mode to ACC,
                        Else Set HEAD main mode correspond to Driver settings.)
                        End note
                        :Get Ego velocity to HEAD Input Data;
                        Note left: Get ego velocity from VDY and update it to HEAD Input Data
                        :Get Ego acceleration to HEAD Input Data;
                        Note left: Get Ego acceleration from VDY and update it to HEAD Input Data
                        :Get trajectory curvature to HEAD Input Data;
                        Note left: Get Ego trajectory curvature from VDY and update it to HEAD Input Data
                        :Update Ego yaw rate to HEAD Input Data;
                        Note left: Get Ego Yaw rate from VDY and update it to HEAD Input Data
                        Partition #LightBlue **((HEAD_CFG_TURN_ASSIST))** {
                        :Update Steering Angle to HEAD Input Data;
                        :Update Is the Turn Indicator is in same direction;
                        :Update Gas pedal position to HEAD Input Data;
                        }
                        :Update DIM Values to HEAD Input Data;
                        Note right
                        ->Get probability values from DIM and update it to HEAD Input Data
                          correspond to DriverFeedback, DriverActivity and DriverAttention.
                        ->check for the DIM hypothesis confidence as Normal, Min or less than Min
                          acording to the confidence value set the HeadInputsignal state OK,
                          Badquality or Missing.
                        End note
                        :Update DIM Hypotheses count to HEAD;
                        :Update Extra prebrake settings;
                        Note right:Update based on CodingSwitches or Head Main Switch.
                        :Update DIM Input Validity;
                        Note left:DIM Input is Valid if DIM Header Signal status is OK, \nElse DIM Input is Not Valid.
                        Partition #LightBlue **((HEAD_CFG_TURN_ASSIST))** {  
                        :Update Camera Ready;
                        Note left
                        High deceleration braking only if camera is
                        available and delivers valid objects
                        End note
                        }
                        :Update DrivingDirection to HEAD Input Data;
                        Note right
                        ->Get Drive Direction from VDY.
                        ->Set Drive Direction as true if forward driving.
                        End note
                        :Update Safe Object Distance;
                        Note left:Get Safe object Distance from CD and update it to HEAD.
                        stop
                        @enduml

  @return               void

  @param[in]            fCycleTime

  @glob_in              @ref DIMHypothesisList\n @ref MEDIC_p_GetHypothesisIntf()\n @ref MEDIC_p_ModDIMOutCustom()\n @ref MEDIC_p_GetDIMInGeneric()\n @ref MEDIC_p_GetHeadInCustom()
                        @ref MEDIC_p_GetHeadInGeneric()\n @ref HEADExtraInputValueList\n @ref HEADInputData
  @glob_out             @ref bHEADInitialized\n @ref HEADInputData

  @c_switch_part        @ref MEDIC_CFG_USE_EM_GENERIC_OBJECT_LIST
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
void HEADGetInputData(const float32 fCycleTime)
{
  uint8 uiDIMHypIndex;
  uint8 uiDIMHypNumber = 0;

  #if HEAD_CFG_TURN_ASSIST
  const boolean bTurnIndicatorInSteeringDirection = (boolean)
    ((
    (MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngle >=  -HEAD_PAR_TURN_INDICATOR_IN_STEERING_DIRECTION_STEERING_WHEEL_ANGLE_THRESHOLD) &&
    (MEDIC_p_GetDIMInGeneric()->eTurnIndicator == eTurnIndicator_Left)
    )
    ||
    (
    (MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngle <=   HEAD_PAR_TURN_INDICATOR_IN_STEERING_DIRECTION_STEERING_WHEEL_ANGLE_THRESHOLD) &&
    (MEDIC_p_GetDIMInGeneric()->eTurnIndicator == eTurnIndicator_Right)
    ));
  #endif /* HEAD_CFG_TURN_ASSIST */

  const HEADInputSignalState_t isHeadInCustOK 
    = (MEDIC_p_GetHeadInCustom()->sSigHeader.eSigStatus == AL_SIG_STATE_OK )? HEADInputSignalState_OK : HEADInputSignalState_Missing;

  /* Set Cycle time to current value*/
  MEDIC_p_ModHEADInputData()->fCycleTime = fCycleTime;
  
  #if (MEDIC_CFG_USE_EM_GENERIC_OBJECT_LIST)
  switch( MEDIC_p_GetHypothesisIntf()->sSigHeader.eSigStatus )
  #else
  switch( MEDIC_p_GetHypothesisIntf()->eSigStatus  )
  #endif
  {
    case (AlgoSignalState_t)AL_SIG_STATE_INIT:
    {
      MEDIC_p_ModHEADInputData()->pInputValueList->CDHypotheses.eSignalQuality = HEADInputSignalState_Default;
    }
    break;
    
    case (AlgoSignalState_t)AL_SIG_STATE_OK:
    {
      (void)HEADSetupInputHypRef();
    }
    break;
  
    case (AlgoSignalState_t)AL_SIG_STATE_INVALID:
    default:
    {
      MEDIC_p_ModHEADInputData()->pInputValueList->CDHypotheses.eSignalQuality = HEADInputSignalState_Missing;
    }
    break;
  }

  /*-------------------------- get driver setting -------------------*/
  if(MEDIC_p_GetDIMInGeneric()->bACCActive != FALSE)
  {
    MEDIC_p_ModHEADInputData()->eHEADMainMode = HEAD_PAR_MODE_SETTING_ACC;
  }
  else
  {
    switch(MEDIC_p_GetDIMInGeneric()->eDriverSetting)
    {
      case (eDriverSetting_t)eDriverSetting_Late:
        MEDIC_p_ModHEADInputData()->eHEADMainMode = HEAD_PAR_MODE_SETTING_LATE;
        break;    
      case (eDriverSetting_t)eDriverSetting_Early:
        MEDIC_p_ModHEADInputData()->eHEADMainMode = HEAD_PAR_MODE_SETTING_EARLY;
        break;
      case (eDriverSetting_t)eDriverSetting_Middle:
        MEDIC_p_ModHEADInputData()->eHEADMainMode = HEAD_PAR_MODE_SETTING_MIDDLE;
        break;
      case (eDriverSetting_t)eDriverSetting_Invalid:
      default:
        /* Use last-is-best semantic => keep last valid value or init value */
        break;
    }
  }

  /* get ego velocity */
  if ((MEDIC_f_GetEgoVelVarianceRaw() >= 0) && IS_SIGNAL_STATUS_OK(MEDIC_u_GetIOStateEgoSpeedX()))
  {
    #if (VDY_VEH_DYN_INTFVER >= 32)
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->LongVelocity), MEDIC_f_GetEgoVelRaw(), HEADInputSignalState_OK, MEDIC_p_GetVDYDynRaw()->Longitudinal.varVelocity);
    #else
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->LongVelocity), MEDIC_f_GetEgoVelRaw(), HEADInputSignalState_OK, MEDIC_p_GetVDYDynRaw()->Longitudinal.MotVar.varVelocity);
    #endif
  }
  else
  {
    MEDIC_p_ModHEADInputData()->pInputValueList->LongVelocity.eSignalQuality = HEADInputSignalState_Missing;
  }

  /* get ego acceleration */
  #if (VDY_VEH_DYN_INTFVER >= 32)
  if ((MEDIC_p_GetVDYDynRaw()->Longitudinal.varAccel >= 0) && IS_SIGNAL_STATUS_OK(MEDIC_u_GetIOStateEgoAccelX()))
  #else
  if ((MEDIC_p_GetVDYDynRaw()->Longitudinal.AccelCorr.corrAccelVar >= 0) && IS_SIGNAL_STATUS_OK(MEDIC_u_GetIOStateEgoAccelX()))
  #endif
  {
    #if (VDY_VEH_DYN_INTFVER >= 32)
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->LongAcceleration), MEDIC_f_GetEgoAccelRaw(), HEADInputSignalState_OK, MEDIC_p_GetVDYDynRaw()->Longitudinal.varAccel);
    #else
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->LongAcceleration), MEDIC_f_GetEgoAccelRaw(), HEADInputSignalState_OK, MEDIC_p_GetVDYDynRaw()->Longitudinal.MotVar.varAccel);
    #endif
  }
  else
  {
    MEDIC_p_ModHEADInputData()->pInputValueList->LongAcceleration.eSignalQuality = HEADInputSignalState_Missing;
  }

  /* get ego trajectory curvature */
  #if (VDY_VEH_DYN_INTFVER >= 32)
  if ((MEDIC_p_GetVDYDynRaw()->Lateral.Curve.VarCurve >= 0) && IS_SIGNAL_STATUS_OK(MEDIC_u_GetIOStateEgoCurve()))
  #else
  if ((MEDIC_p_GetVDYDynRaw()->Lateral.Curve.varC0 >= 0) && IS_SIGNAL_STATUS_OK(MEDIC_u_GetIOStateEgoCurve()))
  #endif
  {
    #if (VDY_VEH_DYN_INTFVER >= 32)
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->EgoLatCurvature), MEDIC_p_GetVDYDynRaw()->Lateral.Curve.Curve, HEADInputSignalState_OK, MEDIC_p_GetVDYDynRaw()->Lateral.Curve.VarCurve);
    #else
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->EgoLatCurvature), MEDIC_p_GetVDYDynRaw()->Lateral.Curve.Curve, HEADInputSignalState_OK, MEDIC_p_GetVDYDynRaw()->Lateral.Curve.varC0);
    #endif
  }
  else
  {
    MEDIC_p_ModHEADInputData()->pInputValueList->EgoLatCurvature.eSignalQuality = HEADInputSignalState_Missing;
  }

  /* get ego yaw rate */
  if ((MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.Variance >= 0) && IS_SIGNAL_STATUS_OK(MEDIC_u_GetIOStateEgoYawRate()))
  {
    /*set true if forward driving*/
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->YawRate), MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.YawRate, HEADInputSignalState_OK, MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.Variance);
  }
  else
  {
    MEDIC_p_ModHEADInputData()->pInputValueList->YawRate.eSignalQuality = HEADInputSignalState_Missing;
  }
  
  #if HEAD_CFG_TURN_ASSIST
  /* Steering Angle */
  HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->SteeringAngle), fABS(MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngle), HEADInputSignalState_OK, 0);
  
  /* Turn Indicator in Steering Direction*/
  HEADSetInputValueBool(&(MEDIC_p_ModHEADInputData()->pInputValueList->TurnIndicatorInSteeringDirection), bTurnIndicatorInSteeringDirection, HEADInputSignalState_OK);

  /* Gas Pedal */
  HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->GasPedal), MEDIC_p_GetDIMInGeneric()->fAccelPedalPos, HEADInputSignalState_OK, 0);
  #endif /* HEAD_CFG_TURN_ASSIST */

  /* set DIM Values (handled as Hypotheses) to HEADInputData (handled as Signals) */
  for(uiDIMHypIndex = 0u; uiDIMHypIndex < HEAD_MAX_NUMBER_OF_DM_HYPS; uiDIMHypIndex++)
  {
    /* get the pointer to the DIM hyp */
    const GDB_DMHypothesis_t *pDimHyp = &(MEDIC_p_GetDIMHypothesisList()->rgDimHypEBA[(uint32)uiDIMHypIndex]);
      
    if(pDimHyp != NULL)
    {
      switch(pDimHyp->eType)
      {
        case DIMHypoType_Feedback:
        {
          /*get driver feedback*/
          if (pDimHyp->Confidence >= HEAD_DM_HYP_NORMAL_CONFIDENCE)
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverFeedback), pDimHyp->Probability, HEADInputSignalState_OK);
            uiDIMHypNumber++;
          }
          else if (pDimHyp->Confidence >= HEAD_DM_HYP_MIN_CONFIDENCE)
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverFeedback), pDimHyp->Probability, HEADInputSignalState_BadQuality);
            uiDIMHypNumber++;
          }
          else
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverFeedback), 0, HEADInputSignalState_Missing);
          }
        }
        break;
        case DIMHypoType_Activity:
        {
          /*get driver activity*/
          if (pDimHyp->Confidence >= HEAD_DM_HYP_NORMAL_CONFIDENCE)
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverActivity), pDimHyp->Probability, HEADInputSignalState_OK);
            uiDIMHypNumber++;
          }
          else if (pDimHyp->Confidence >= HEAD_DM_HYP_MIN_CONFIDENCE)
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverActivity), pDimHyp->Probability, HEADInputSignalState_BadQuality);
            uiDIMHypNumber++;
          }
          else
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverActivity), 0, HEADInputSignalState_Missing);
          }
        }
        break;
        case DIMHypoType_Attention:
        {
          /*get driver attention*/
          if (pDimHyp->Confidence >= HEAD_DM_HYP_NORMAL_CONFIDENCE)
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverAttention), pDimHyp->Probability, HEADInputSignalState_OK);
            uiDIMHypNumber++;
          }
          else if (pDimHyp->Confidence >= HEAD_DM_HYP_MIN_CONFIDENCE)
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverAttention), pDimHyp->Probability, HEADInputSignalState_BadQuality);
            uiDIMHypNumber++;
          }
          else
          {
            HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DriverAttention), 0, HEADInputSignalState_Missing);
          }
        }
        break;
        default:
          /*not set in DIM Wrapper-> ERROR*/
          break;
      }
    }
    else
    {
      /*Review this:*/
      bHEADInitialized = FALSE;
    }   
  }

  HEADSetInputValueSInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DIMHypotheses), uiDIMHypNumber, HEADInputSignalState_OK);

  if(HEADCodingInfo.CodeGenIgnoreActivationSwitch == TRUE) 
  {
    HEADSetInputValueBoolTest(&(HEADExtraInputValueList.ExtPreBrakeSetting), TRUE, HEADInputSignalState_OK);
  }
  /* external prebrake setting */
  else if (MEDIC_p_GetHeadInGeneric()->eMainSwitch != eMainSwitch_Invalid)
  {
    HEADSetInputValueBoolTest(&(HEADExtraInputValueList.ExtPreBrakeSetting), MEDIC_p_GetHeadInGeneric()->eMainSwitch == eMainSwitch_Active, HEADInputSignalState_OK);
  }
  else
  {
    HEADSetInputValueBool(&(HEADExtraInputValueList.ExtPreBrakeSetting), FALSE, HEADInputSignalState_Missing);
  }

  if (MEDIC_p_ModDIMOutCustom()->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
  {
    /*DIM inputs were valid*/
    HEADSetInputValueUInt(&(HEADExtraInputValueList.DIMInputsValid), MEDIC_p_ModDIMOutCustom()->eDriverMonitoringState, HEADInputSignalState_OK);
  }
  else
  {
    HEADSetInputValueUInt(&(HEADExtraInputValueList.DIMInputsValid), FALSE, HEADInputSignalState_Missing);
  }

  #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  /* allow high decel braking only if camera is available and delivers valid objects */
  if(  ( MEDIC_pHEADInputCustom->ucCameraStatus == HEAD_CAMERA_AVAILABLE_YES ) 
    && ( MEDIC_pHEADInputCustom->ucCameraObjectStatus == HEAD_CAMERA_OBJ_STATUS_OK ) )
  {
    HEADSetInputValueBool(&(HEADExtraInputValueList.CameraReady), TRUE, isHeadInCustOK);
  }
  else
  {
    HEADSetInputValueBool(&(HEADExtraInputValueList.CameraReady), FALSE, isHeadInCustOK);
  }
  #else
  _PARAM_UNUSED(isHeadInCustOK);
  #endif

  if (IS_SIGNAL_STATUS_OK(MEDIC_u_GetIOStateEgoMotion()))
  {
    #if (MEDIC_CFG_VEH_SIG_INPUT) && (HEAD_CFG_TURN_ASSIST)
    if (MEDIC_p_GetVehSig()->VehSigMain.VehLongMotStateExt == VDY_VEH_MOT_STATE_FAST_STST)
    {
      // The raw vehicle signal indicates standstill => Do not use VDY raw ego dynamics but set motion state to standstill
      HEADSetInputValueUInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DrivingDirection), VDY_LONG_MOT_STATE_STDST, HEADInputSignalState_OK);
    }
    else
    {
      // The raw vehicle signal is not indicating standstill => Take motion state from VDY raw ego dynamics
      HEADSetInputValueUInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DrivingDirection), MEDIC_u_GetEgoMotionState(), HEADInputSignalState_OK);
    }
    #else
    // The raw vehicle signal is not indicating standstill => Take motion state from VDY raw ego dynamics
    HEADSetInputValueUInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->DrivingDirection), MEDIC_u_GetEgoMotionState(), HEADInputSignalState_OK);
    #endif // MEDIC_CFG_VEH_SIG_INPUT && HEAD_CFG_TURN_ASSIST
  }
  else
  {
    HEADSetInputValueUIntTest(&(MEDIC_p_ModHEADInputData()->pInputValueList->DrivingDirection), FALSE, HEADInputSignalState_Missing);
  }

  if (MEDIC_p_GetHypothesisIntf()->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
  {
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->SafeObjDistSfty), MEDIC_p_GetHypothesisIntf()->Degradation.Safety.fMaxDist     , HEADInputSignalState_OK, 0.F);
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->SafeObjDistPerf), MEDIC_p_GetHypothesisIntf()->Degradation.Performance.fMaxDist, HEADInputSignalState_OK, 0.F);
  }
  else
  {
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->SafeObjDistSfty), FALSE, HEADInputSignalState_Missing, 0);
    HEADSetInputValueFloat(&(MEDIC_p_ModHEADInputData()->pInputValueList->SafeObjDistPerf), FALSE, HEADInputSignalState_Missing, 0);
  }
} /* PRQA S 7004 *//* date: 2018-10-26, reviewer:Krupa H R, reason: suppressing cyclomatic complexity for better code maintainability*/

/*************************************************************************************************************************
  Functionname:         HEADSetupInputHypRef                                                                       */ /*!

  @brief                Returns the kinematic hypothesis that activates a given HEAD module  

  @description          If a kinematic hypothesis can be found which causes the module activation, this hypothesis is returned.
                        Otherwise, a null pointer is returned.

                        @startuml
                        start
                            #orange: Update HEAD Hypothesis list
                            <b> HEADUpdateHypothesisList <b> >
                            If(Is the kinematic hypothesis information exist) then (yes)
                            : Signal quality, value and type is updated;
                            Endif
                            : Get maximum number of hypothesis; 
                            : Return the updated error type;
                        Stop
                        @enduml

          
  @return               eGDBError_t  : GDB error type is returned

  @param[in]            void

  @glob_in              @ref HEADSetupInputHypRef \n @ref HEADInputData
  @glob_out             @ref HEADInputData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t HEADSetupInputHypRef(void)
{
  eGDBError_t eError = GDB_ERROR_NONE;

  uint8 uiMaxHypoIndex,uiMaxHypKin;
  /* initialise hypothesis index variables */
  uiMaxHypoIndex = 0u;
  uiMaxHypKin    = 0u;

  eError = HEADUpdateHypothesisList(&uiMaxHypoIndex, &uiMaxHypKin);

  if(eError == GDB_ERROR_NONE)
  {
    HEADSetInputValueUInt(&(MEDIC_p_ModHEADInputData()->pInputValueList->CDHypotheses), uiMaxHypKin, HEADInputSignalState_OK);
  }

  MEDIC_p_ModHEADInputData()->uiNumberOfHEADHypotheses = uiMaxHypoIndex;

  return eError;
}

/*************************************************************************************************************************
  Functionname:         HEADGetExtraInputValueList                                                                        */ /*!

  @brief                Get additional input values 

  @description          Returns pointer of extra input values
                        @startuml
                        Start
                            :HEADextraInputvalueslist; 
                        Stop
                        @enduml
          
  @return               Pointer to extra input values

  @param[in]            Void

  @glob_in              @ref HEADExtraInputValueList
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION   

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         
  
  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
const HEADExtraInputValueList_t *HEADGetExtraInputValueList(void)
{
  return(&HEADExtraInputValueList);
}

/************************************************************************************************************************
  Functionname          HEADFilterDriverFeedback                                                                    */ /*! 
  
  @brief                Filter driver feedback during unattended acceleration pedal
                        activity by driver during function activation.
                 
  @description          Depends on feedback signal the gas pedal and brake pedal will   
                        be applied. If the applied brake is not enough then positive feedback 
                        will be given.

                        @startuml
                        Start
                            :Read break module data;
                            : Filter maximum and minimum driver feedback probability;
                            Note right
                            -90 to -70 is the corresponding maximum and minimum signal 
                            End note
                            If(Detect unintentional weak negative feedback 
                            and check pre brake vehicle active level) then (True)

                            : Unattended feedback given for preventing abortion;
                            Else if (check pre brake vehicle active level) then (True)
                            :minimum driver feedback probability which will be filtered ;
                            Note right
                            If feedback  is still Weak negative feedback then 
                            Weak feedback condition are not longer given
                            End note
                            Else
                            :no braking function module is active, use input value as output;
                            Endif 
                        Stop
                        @enduml                  

  @param[in]            pInputData  : Head input data
  @param[out]           OutValue    : OutValuefiltered value
 
  @return               None
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)

  @traceability 

  @author               Armin Vogl | armin.vogl@continental-corporation.com
**************************************************************************************************************************/
static void HEADFilterDriverFeedback(const HEADInputData_t *pInputData, float32 *OutValue) 
{
  const float32 headCycTime_c = 0.025F; /* Expected head cycle time plus tolerance */
  sint32 siOutValueTemp;
  const HEADModuleOutputBrakeFunction_t *pPreBrake = &HEADModuleOutputData.Veh_AutoBrk1;
  (void) HEADGetInputValue_sint32(pInputData->pInputValueList->DriverFeedback, 0,&siOutValueTemp);
  *OutValue = (float32) siOutValueTemp;
 

  /* Detection function activations, which can cause unattended driver feedbacks */
  if ( (siOutValueTemp >= HEAD_DRV_FDBCK_FILTER_WEAK_PROB_MIN) 
        &&
        (siOutValueTemp <= HEAD_DRV_FDBCK_FILTER_WEAK_PROB_MAX)) 
  {
    if (( (*(pPreBrake->pfActiveTimeVeh1) > HEAD_DRV_FDBCK_IGNORE_MIN_ACT_TIME) 
          && 
          (*(pPreBrake->pfActiveTimeVeh1) <= (HEAD_DRV_FDBCK_IGNORE_MAX_ACT_TIME + headCycTime_c))
          && 
          (*(pPreBrake->pePreBrakeState) == eBrakeState_VEH_LEVEL_1))
        ||
        ( (*(pPreBrake->pfActiveTimeVeh2) > HEAD_DRV_FDBCK_IGNORE_MIN_ACT_TIME) 
          && 
          (*(pPreBrake->pfActiveTimeVeh2) <= (HEAD_DRV_FDBCK_IGNORE_MAX_ACT_TIME + headCycTime_c))
          && 
          (*(pPreBrake->pePreBrakeState) == eBrakeState_VEH_LEVEL_2) )
        ||
        ( (*(pPreBrake->pfActiveTimeVeh3) > HEAD_DRV_FDBCK_IGNORE_MIN_ACT_TIME) 
          && 
          (*(pPreBrake->pfActiveTimeVeh3) <= (HEAD_DRV_FDBCK_IGNORE_MAX_ACT_TIME + headCycTime_c))
          && 
          (*(pPreBrake->pePreBrakeState) == eBrakeState_VEH_LEVEL_3) )
        ||
        ( (*(pPreBrake->pfActiveTimePed1) > HEAD_DRV_FDBCK_IGNORE_MIN_ACT_TIME)
          && 
          (*(pPreBrake->pfActiveTimePed1) <= (HEAD_DRV_FDBCK_IGNORE_MAX_ACT_TIME + headCycTime_c) )
          && 
          (*(pPreBrake->pePreBrakeState) == eBrakeState_PED_LEVEL_1) ) )
    {
      /* unattended feedback caused by function activation, prevent abortion */
      *OutValue = (float32) HEAD_DRV_FDBCK_FILTER_IGNORE_PROB;
    }
    else if ( (*(pPreBrake->pePreBrakeState) == eBrakeState_VEH_LEVEL_1)
              ||
              (*(pPreBrake->pePreBrakeState) == eBrakeState_VEH_LEVEL_2)
              ||
              (*(pPreBrake->pePreBrakeState) == eBrakeState_VEH_LEVEL_3)
              ||
              (*(pPreBrake->pePreBrakeState) == eBrakeState_PED_LEVEL_1) )
    {
      /* After function activation, test if there is still conditions for weak negative feedback */
      if (siOutValueTemp > HEAD_DRV_FDBCK_FILTER_WEAK_PROB_MIN)
      {
        /* Weak feedback condition are not longer given */
        *OutValue = (float32) HEAD_DRV_FDBCK_FILTER_IGNORE_PROB;
      }
    }
    else 
    {
      /* no braking function module is active, use input value as output */
    }
  }
}


/* ***********************************************************************************************************************
  Functionname          HEADCustomGetHypValue                                                                      */ /*! 

  @brief                Custom HYP_DEPENDENT parameter callback function

  @description          Call back function to get the values of  Head hypothesis output type . 
                        Examples of Head hypothesis output type  are HEADHypOutType_TTC,  HEADHypOutType_CustomPar_01, HEADHypOutType_CustomPar_02 etc.

                        If Head hypothesis output type  is set for  Custom parameter for PreBrake Active Time 2
                        Then we return value of counts the time,Brake function is in active2 state. 

                        If Head hypothesis output type  is set for custom parameter for table distance over vrelX, Then we return value of Object high quality life time.
                        If Head hypothesis output type  is set for custom parameter for Driver Feedback, Then we return value of Driver feedback.
                 
                       @startuml
                       Start
                       if(check input parameter availability) then (True)
                       if(check for head hypothesis out type is equal to Hypothesis lifetime) then (Yes)
                       : Hypothesis lifetime will be updated;

                       Else if(check for head hypothesis out type is equal to Object Life Time Quality) then(Yes)
                       : Object Life Time Quality will be updated;

                       Else if(check for head hypothesis out type is equal to application specific dependent driver feedback  ) then (Yes)
                       #orange:driver feedbacks are updated<b> HEADFilterDriverFeedback HEADMTSSetDrvFeedBack<b> >

                       Else if(check for head hypothesis out type is equal to steering wheel angle gradient) then(Yes)
                       : Steering wheel angle gradient will be updated;
                       Endif

                       Else if(check for head hypothesis out type is within object corridor) then (Yes)
                       if(Hypothesis is equal to Ped Collision)then(Yes) 
                       : Check within corridor will be updated;
                       Endif

                       Else if(check for head hypothesis out type is equal to FPS Inhibition for PED Collision ) then (Yes)
                       if(Hypothesis is equal to Ped Collision)then(Yes) 
                       : FPS Inhibition Mask will be updated;
                       Endif

                       Endif

                       Else
                       : set Initialized  to error none;
                       Endif

                       if(Is found flag false?) then (Yes)
                       : filter function doesn't match is updated ;
                       Endif

                       Else
                       : input parameters are Unavailable;
                       Endif

                       :return error type;
                       Stop
                       @enduml


  @return               eGDBError_t  : GDB error type is returned

  @param[in,out]        pInputData   : Head input data
  @param[in,out]        pHyp         : Pointer to the hypothesis
  @param[in,out]        eHypOutType  : Hypothesis output variable type
  @param[in,out]        retValue     : Return error type
  
  @glob_in              None
  @glob_out             @ref HEADInputData

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)
  
  @traceability 
  
  @author               Robert Thiel | robert.thiel@contiautomotive.com
****************************************************************************************************************************/
static eGDBError_t HEADCustomGetHypValue(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, eHEADHypOutType_t eHypOutType, float32 *retValue)
{
  eGDBError_t retError = GDB_ERROR_NONE;
  boolean bFound = FALSE;

  if ( (pHyp != NULL) && (pInputData != NULL) && (pHyp->pHypothesis != NULL) && (retValue != NULL) )
  {
    /*HEADHypOutType_CustomPar_01*/
    if (eHypOutType == HEAD_CUST_PAR_Hypo_Lifetime)
    {
      const Hypothesis_t *pKinHyp = pHyp->pHypothesis;

      *retValue = pKinHyp->fHypothesisLifetime;
      bFound = TRUE;
    }
    /*HEADHypOutType_CustomPar_02*/
    else if ( eHypOutType == HEAD__OBJ_LT_HQ )
    {
      const Hypothesis_t *pKinHyp = pHyp->pHypothesis;

      *retValue = pKinHyp->Custom.fObjLifeTimeHiQual;
      bFound = TRUE;
    }
    /*HEADHypOutType_CustomPar_03*/
    else if (eHypOutType == HEAD_CUST_PAR_DRV_FDBCK)
    {
      HEADFilterDriverFeedback(MEDIC_p_ModHEADInputData(), retValue);
      HEADMTSSetDrvFeedBack(*retValue);
	  bFound = TRUE;
    }
    /*HEADHypOutType_CustomPar_04*/
    else if (eHypOutType == HEAD_CUST_PAR_STEER_GRAD)
    {
      *retValue = fABS(MEDIC_p_GetDIMInGeneric()->fSteeringWheelAngleGrad);
      bFound = TRUE;
    }
    /*HEADHypOutType_CustomPar_05*/
    else if (eHypOutType == HEAD_CUST_PAR_OBJ_CORRIDOR)
    {
                   if ((pHyp->pHypothesis)->eType == CDHypothesisType_PedCollision)
                    {
                         if((pInputData->pInputValueList->LongVelocity.uValue.fValue <= EGOVELOCITY_THRESHOLD_35kph) && (fABS((pHyp->pHypothesis)->fVrelY)<LATERAL_VELOCITY_THRESOLD_9kph))
                           {
                                 if(ABS(((pHyp->pHypothesis)->fDistY + ((pHyp->pHypothesis)->fVrelY * (pHyp->pHypothesis)->fTTC3)))<=DISTY_THRESHOLD_1_0)
                                 {
                                     *retValue = 1.0f;
                                      bFound = b_TRUE;
                                 }
                                else
                                 { 
                                     *retValue = 0.0f;
                                      bFound = b_TRUE;
                                 }
                            }

                        else if((pInputData->pInputValueList->LongVelocity.uValue.fValue <= EGOVELOCITY_THRESHOLD_61kph) 
                                && (fABS((pHyp->pHypothesis)->fVrelY)<LATERAL_VELOCITY_THRESOLD_9kph)
                                && (pInputData->pInputValueList->LongVelocity.uValue.fValue >= EGOVELOCITY_THRESHOLD_48kph))
                        {
                          if(ABS(((pHyp->pHypothesis)->fDistY + ((pHyp->pHypothesis)->fVrelY * (pHyp->pHypothesis)->fTTC4)))<=DISTY_THRESHOLD_1_8)
                                 {
                                     *retValue = 1.0f;
                                      bFound = b_TRUE;
                                 }
                                else
                                 { 
                                     *retValue = 0.0f;
                                      bFound = b_TRUE;
                                 }

                        }
                         else if(ABS(((pHyp->pHypothesis)->fDistY + ((pHyp->pHypothesis)->fVrelY * (pHyp->pHypothesis)->fTTC3)))<=DISTY_THRESHOLD_1_2)
                                {
                                      *retValue = 1.0f;
                                      bFound = b_TRUE;
                                }
                             else
                                 { 
                                     *retValue = 0.0f;
                                      bFound = b_TRUE;
                                 }
                     }
				   else if ((pHyp->pHypothesis)->eType == CDHypothesisType_CyclColl)
				   {
					   if (pInputData->pInputValueList->LongVelocity.uValue.fValue <= EGOVELOCITY_THRESHOLD_35kph)
					   {
							if ((ABS(((pHyp->pHypothesis)->fDistY + ((pHyp->pHypothesis)->fVrelY * (pHyp->pHypothesis)->fTTC3))) <= DISTY_THRESHOLD_1_6_5)
								&& pHyp->pHypothesis->uiHypothesisProbability > 60
								&& pHyp->pHypothesis->fHypothesisLifetime > 0.8)
						   {
							   *retValue = 1.0f;
							   bFound = b_TRUE;
						   }
              else if (ABS(((pHyp->pHypothesis)->fDistY + ((pHyp->pHypothesis)->fVrelY * (pHyp->pHypothesis)->fTTC3))) <= DISTY_THRESHOLD_1_5)
              {
                *retValue = 1.0f;
                bFound = b_TRUE;
              }              
						   else
						   {
							   *retValue = 0.0f;
							   bFound = b_TRUE;
						   }
					   }
					   else if (
						   (pInputData->pInputValueList->LongVelocity.uValue.fValue > EGOVELOCITY_THRESHOLD_35kph)
						   && (pInputData->pInputValueList->LongVelocity.uValue.fValue <= EGOVELOCITY_THRESHOLD_48kph)
						   )
					   {
						   if (ABS(((pHyp->pHypothesis)->fDistY + ((pHyp->pHypothesis)->fVrelY * (pHyp->pHypothesis)->fTTC3))) <= DISTY_THRESHOLD_1_8)
						   {/* PRQA S 0715 *//* date: 2023-02-20, reviewer: Veeresh B, reason: suppressing nesting of control structures   */
							   *retValue = 1.0f;
							   bFound = b_TRUE;
						   }
						   else
						   {/* PRQA S 0715 *//* date: 2023-02-20, reviewer: Veeresh B, reason: suppressing nesting of control structures   */
							   *retValue = 0.0f;
							   bFound = b_TRUE;
						   }
					   }
					   else if (pInputData->pInputValueList->LongVelocity.uValue.fValue > EGOVELOCITY_THRESHOLD_48kph)
						   
					   { /* PRQA S 0715 1 *//* date: 2023-02-20, reviewer: Veeresh B, reason: suppressing nesting of control structures   */
						   if (ABS(((pHyp->pHypothesis)->fDistY + ((pHyp->pHypothesis)->fVrelY * (pHyp->pHypothesis)->fTTC3))) <= DISTY_THRESHOLD_2_8)
						   {
							   *retValue = 1.0f;
							   bFound = b_TRUE;
						   }
						   else
						   {
							   *retValue = 0.0f;
							   bFound = b_TRUE;
						   }
					   }
					   else
					   {
						   *retValue = 0.0f;
						   bFound = b_TRUE;
					   }
				   }
                     else
                     { /*Default*/
                                      *retValue = 0.0f;
                                      bFound = b_TRUE;
                      }
     }
  /* 10(Ped Collision) & 13(Cyc collision)   CustomPar_00_HypDependent       Ped Collision Inhibition based                        brake,warning,prefill,HBA,PBR
                                                                            on Logical AND with INHIBIT_PEDCYCCOLL                                                                      */
     else if(eHypOutType == HEAD_CUST_FPS_INHIBITION_MASK_CHECK)
     { 
                   if ((pHyp->pHypothesis)->eType == CDHypothesisType_PedCollision)
                    {
                   if((pHyp->pHypothesis->eEBAInhibitionMask & INHIBIT_PEDCYCCOLL) != 0u )//0b0010 0000 0000 0000 Ped & Cyc Collision Inhibition based on Logical AND with INHIBIT_PEDCYCCOLL
                        {
                          *retValue = 0.0f;
                           bFound = b_TRUE;
                        }
                        else
                        {
                          *retValue = 1.0f;
                          bFound = b_TRUE; 
                        }
                    }
                   else
                   {
                          *retValue = 1.0f;
                          bFound = b_TRUE; 
                    }
     }

      else if(eHypOutType == HEAD_CUST_PAR_OBJ_VABSX)
    {
      if(((pHyp->pHypothesis)->fVrelX + pInputData->pInputValueList->LongVelocity.uValue.fValue < 10/3.6)
      && (pHyp->pHypothesis)->eEBADynProp == EBADynProp_Mov)
      {
         *retValue = 1.0f;
         bFound = b_TRUE;
      }
      else if(((pHyp->pHypothesis)->fVrelX + pInputData->pInputValueList->LongVelocity.uValue.fValue > 0.6)
      && (pHyp->pHypothesis)->eEBADynProp == EBADynProp_Stat)
      {
         *retValue = 1.0f;
         bFound = b_TRUE;
      }
      else if((pHyp->pHypothesis)->eType == CDHypothesisType_RunUp
      && (pHyp->pHypothesis)->eEBADynProp == EBADynProp_Stat)
      {
         *retValue = 1.0f;
         bFound = b_TRUE;
      }
      else
      {
        *retValue = 0.0f;
        bFound = b_TRUE;
      }
    }

    else if(eHypOutType == HEAD_CUST_PAR_OBJ_VRELY)
    {
       *retValue = fABS((pHyp->pHypothesis)->fVrelY);
       bFound = TRUE;
    }

  else
   {
      ;
    }
    
    /* parameter not handled */
    if( bFound == FALSE )
    {
      retError = GDB_ERROR_FILTER_DOESNT_MATCH;
    }
  }
  else
  {
    retError = GDB_ERROR_POINTER_NULL;
  }
  
  /* done */
  return retError;
}/* PRQA S 7004 *//* date: 2023-02-20, reviewer: Veeresh B, reason: suppressing cyclomatic complexity for better code maintainability*/


/* **********************************************************************************************************************
  Functionname          HEADCustomFilterHypValue                                                                   */ /*! 

  @brief                Application specific filtering of value
  
  @description          Call back function to filter hypothesis signals
                        @startuml
                        Start
                            : Custom codes are added;
                            Note right
                            Eliminating the unused variable warning
                            End note
                            :return error type; 
                        Stop
                        @enduml

  @return               eGDBError_t  : GDB error type is returned

  @param[in]            pInputData   : Pointer to input data
  @param[in]            pHyp         : Affected hypothesis
  @param[in]            eHypOutType  : Hypothesis parameter to be tested
  @param[in]            uiModuleNr   : Affected head module
  @param[in,out]        pInOutValue  : Updated value
    
  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)
  
  @traceability 

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADCustomFilterHypValue(const HEADInputData_t *pInputData, const HEADHypothesis_t *pHyp, 
                                            eHEADHypOutType_t eHypOutType, uint8 uiModuleNr, float32 * pInOutValue )
{
  eGDBError_t retError = GDB_ERROR_NONE;
  /*add custom code here*/
  _PARAM_UNUSED(pInputData);
  _PARAM_UNUSED(pHyp);
  _PARAM_UNUSED(eHypOutType);
  _PARAM_UNUSED(uiModuleNr); 
  _PARAM_UNUSED(pInOutValue);
  /* done */
  return retError;
}


/*************************************************************************************************************************
  Functionname:         HEADCustomGetIndependentValue                                                               */ /*!

  @brief                Custom INDPENDENT parameter callback function

  @description          Custom INDPENDENT parameter callback function

                        @startuml
                        Start
                            if( check input parameter availability) then (True)                           
                            if(check Head Hypothesis output type ) then (True)
                            if(check for custom parameter deactivation Stand Still) then (Yes)
                            :update the return value;
                            Else if(check for custom parameter DriverDoor and Seatbelt) then (Yes)
                            :update the return value;
                            Else if(check for custom parameter Brake chain state) then (Yes)
                            :update the return value;
                            Else if(check for custom parameter Warn chain state) then (Yes)
                            :update the return value;
                            Else if(check for custom parameter Prefill qualifier) then (Yes)
                            :update the return value;
                            Else if(check for custom parameter HBA qualifier) then (Yes)
                            :update the return value;
                            else if(is it Hypothesis Independent parameter?) then (Yes)
                            :update the return value;
                            Note left 
                            Its specifies  application specific INDEPENDENT parameter
                            End note
                            Else (No)
                            : reset local variables;
                            Endif
                            If(None of the Head Hypothesis output type is not matched  ) then (True)
                            :Error type is updated;
                            Endif
                            Endif
                            Else
                            : Error type is updated; 
                            Endif
                            :return error type;
                        Stop
                        @enduml

  @return               eGDBError_t  : GDB error type is returned

  @param[in]            pInputData   : Pointer to input data
  @param[in]            eIndOutType  : Hypothesis output variable type
  @param[in,out]        pretValue    : Update the output value

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None
  
  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)
  
  @traceability 

  @author               Andreas Jakob | andreas.jakob-ext@conti-engineering.com
*************************************************************************************************************************/
static eGDBError_t HEADCustomGetIndependentValue(const HEADInputData_t *pInputData, eHEADParamOutType_t eIndOutType, float32 *pretValue,  uint8 uiModuleNr)
{
  eGDBError_t retError = GDB_ERROR_NONE;
  boolean bFound = FALSE;
  
  if ( (pInputData != NULL) && (pretValue != NULL) )
  {
    /* add custom code here!!!change custom parameter names with defines */
    switch(eIndOutType)
    {
      case HEAD_CUST_ABS_YAWRATE:
        *pretValue = fABS(MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.YawRate);
        bFound = TRUE;
        break;

      case HEAD_CUST_PAR_STILLSTAND_EXT_DEACT:
          if (bHEADDeactivationStandStill == TRUE)
        {
            *pretValue = 1.f;
        }
        else
        {
            *pretValue = 0.f;
        }
        bFound = TRUE;
        break;

      case HEAD_CUST_PAR_Driver_Seatbelt:
          //if ((MEDIC_p_GetHeadInCustom()->b_Airbag_Deployed_eba == GEAR_POSITION_PARK || MEDIC_p_GetHeadInCustom()->b_Airbag_Deployed_eba == GEAR_POSITION_REVERSE)) //GEAR
          if ((MEDIC_p_GetHeadInCustom()->SCS_HBA_resp == GEAR_POSITION_PARK) || (MEDIC_p_GetHeadInCustom()->SCS_HBA_resp == GEAR_POSITION_REVERSE)) //GEAR        
        {
              *pretValue = 0.f;
        }
        else
        {
            *pretValue = 1.f;
        }
        bFound = True;
        break;
      case HEAD_CUST_PAR_BrakeChainState: //AEB_Available
        if((MEDIC_p_GetHeadInCustom()->eQualifierBrakeChain != eSystemOn) //ESP_AEBAvailable
        ||(MEDIC_p_GetHeadInCustom()->eBCM_Status == eBcmStateOff) //SEAT BELT
        ||((MEDIC_p_GetHeadInCustom()->SCS_AEB_decel_resp == eBcmStateOff) && (MEDIC_p_GetHeadInCustom()->Mcylinder_Pressure > 3.0f)))  //Mcylinder Pressure
        {
          *pretValue = 0.f;
        }
        else
        {
          *pretValue = 1.f;
        }		
		
        bFound = TRUE;
        break;
      case HEAD_CUST_PAR_WarnChainState:  // HaptWarn AWB_Changan
        if((MEDIC_p_GetHeadInCustom()->eQualifierWarnChain != eSystemOn)) //ESP_WarningAvailable
        {
          *pretValue = 0.f;
        }
        else
        {
          *pretValue = 1.f;
        }		
        bFound = TRUE;
        break;
      case HEAD_CUST_PAR_Prefill_Qualifier:  //Prefill_Available
        if((MEDIC_p_GetHeadInCustom()->eQualifierPrefill != eSystemOn)//ESP_PrefillAvailable
        || ((MEDIC_p_GetHeadInCustom()->SCS_AEB_decel_resp == eBcmStateOff) && (MEDIC_p_GetHeadInCustom()->Mcylinder_Pressure > 3.0f))) //Mcylinder Pressure
        {
          *pretValue = 0.f;
        }
        else
        {
          *pretValue = 1.f;
        }
        bFound = TRUE;
        break;
      case HEAD_CUST_PAR_HBA_Qualifier: //HBA_Available  ABA Changan
        if((MEDIC_p_GetHeadInCustom()->eQualifierHBA != eSystemOn) //ESP_ABAAvailable
        || ((MEDIC_p_GetHeadInCustom()->SCS_AEB_decel_resp == eBcmStateOff) && (MEDIC_p_GetHeadInCustom()->Mcylinder_Pressure > 3.0f))) //Mcylinder Pressure
        {
          *pretValue = 0.f;
        }
        else
        {
          *pretValue = 1.f;
        }
        bFound = TRUE;
        break;

      case HEAD_CUST_PAR_AEB_Switch:
      if((MEDIC_p_GetHeadInCustom()->EBA_Active_Condition_Custom_input != eSystemOn)) //Brake Switch
      {
        *pretValue = 0.f;
      }
      else
      {
        *pretValue = 1.f;
      }
      bFound = TRUE;
      break;

	  case HEAD_CUST_PAR_Diver_Braking: //low speed driver braking
		  // if ((MEDIC_p_GetDIMInGeneric()->eDriverBraking == DRIVER_BRAKING) && (MEDIC_f_GetEgoAccelRaw() <= EGO_ACCELL)
			//   && (pInputData->pInputValueList->LongVelocity.uValue.fValue <= EGOVELOCITY_THRESHOLD_10kph))
        if ((MEDIC_p_GetDIMInGeneric()->eDriverBraking == DRIVER_BRAKING)
			  && (pInputData->pInputValueList->LongVelocity.uValue.fValue <= EGOVELOCITY_THRESHOLD_15kph))
		  {
			  *pretValue = 0.f;
		  }
		  else
		  {
			  *pretValue = 1.f;
		  }
		  bFound = TRUE;
		  break;

	  case HEAD_CUST_PAR_Diver_Braking_Delay: //Check if driver brake
		  if (MEDIC_p_GetDIMInGeneric()->eDriverBraking != DRIVER_BRAKING)
		  {
			  *pretValue = 0.f;
		  }
		  else
		  {
			  *pretValue = 1.f;
		  }
		  bFound = TRUE;
		  break;

      default:
        bFound = FALSE;
        break;


    }
    
    /* parameter not handled */
    if( bFound == FALSE )
    {
      retError = GDB_ERROR_FILTER_DOESNT_MATCH;
    }
  }
  else
  {
    retError = GDB_ERROR_POINTER_NULL;
  }
 _PARAM_UNUSED(uiModuleNr);
  return retError;
}


/*************************************************************************************************************************
  Functionname:         HEADCustomFilterIndependentValue                                                            */ /*!

  @brief                Application specific filtering of value

  @description          Call back function to filter Independent signals
                        @startuml
                        Start
                            :Custom codes are added;
                            Note right
                            Eliminating the unused variable warning
                            End note
                            :return error type; 
                        Stop
                        @enduml

  @return               eGDBError_t  : GDB error type is returned

  @param[in]            pInputData   : Pointer to input data
  @param[in]            eIndOutType  : Hypothesis output variable type
  @param[in]            uiModuleNr   : Affected head module
  @param[in,out]        pInOutValue  : Update the output value

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           Test of output data (dynamic module test)
  
  @traceability 

  @author               Armin Vogl | armin.vogl@continental-corporation.com
*************************************************************************************************************************/
static eGDBError_t HEADCustomFilterIndependentValue(const HEADInputData_t *pInputData, eHEADParamOutType_t eIndOutType, 
                                                    uint8 uiModuleNr, float32 *pInOutValue )
{
  eGDBError_t retError = GDB_ERROR_NONE;
  /*add custom code here*/
  _PARAM_UNUSED(pInputData);
  _PARAM_UNUSED(eIndOutType);
  _PARAM_UNUSED(uiModuleNr);
  _PARAM_UNUSED(pInOutValue);
  return retError;
}

#endif /*#ifdef MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* !(MEDIC_CFG_HEAD20) */

/**@}*/

