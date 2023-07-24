/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_mts_inputdef.h

DESCRIPTION:               header of the head mts output definiton

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:14:25CEST $

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            1.23

**************************************************************************** */
/**
@ingroup Medic_head
@{ **/
#ifndef HEAD_MTS_INPUTDEFS_H_INCLUDED
#define HEAD_MTS_INPUTDEFS_H_INCLUDED

/** @cond */
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/** @endcond */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS struct HEADMTSInputSignal_t
*****************************************************************************/
/*! @brief Data type to store Input Signals for MTS
    @general Data type to store Input Signals for MTS
    @conseq -
    @attention - */
typedef struct  
{ 
  float32 fValue;             /*!< Value*/
  float32 fStdDev;            /*!< StdDev*/
  uint8   eSigStat;           /*!< ok|default|missing|badqual|susp*/
  uint8   eSigType;           /*!< float|sint|uint|bool*/
  uint8   HEADMTSInSigIdent;  /*!< HEADMTSInSigIdent*/
  boolean isValid;            /*!< isValid*/
} HEADMTSInputSignal_t;

/*****************************************************************************
  TYPEDEFS struct HEADMTSInputSignalListDef_t
*****************************************************************************/
/*! @brief HEAD MTS input signal list definition
    @general This typedef is used to create correct MTS data definition 
             for the Inputdata structure that consists
             HEADMTSInputSignalList_t and custom input data
    @conseq [None]
    @attention [None] */
typedef struct
{
  HEADMTSInputSignal_t LongVelocity;                      /*!< Longitudinal Velocity */
  HEADMTSInputSignal_t LongAcceleration;                  /*!< Longitudinal Acceleration */
  HEADMTSInputSignal_t YawRate;                           /*!< YawRate */
  HEADMTSInputSignal_t DrivingDirection;                  /*!< Driving Direction */
  HEADMTSInputSignal_t EgoLatCurvature;                   /*!< Host vehicle trajectory curvature */
  HEADMTSInputSignal_t CDHypotheses;                      /*!< CD hypotheses */
  HEADMTSInputSignal_t DIMHypotheses;                     /*!< DIM hypotheses */
  HEADMTSInputSignal_t SafeObjDistSfty;                   /*!< Safe Object Distance for Safety functions */
  HEADMTSInputSignal_t SafeObjDistPerf;                   /*!< Safe Object Distance for Performance functions */
  HEADMTSInputSignal_t StabCtrlState;                     /*!< Status of stability control system */
  HEADMTSInputSignal_t BrakeChainState;                   /*!< Status of brake system */
  HEADMTSInputSignal_t WarnChainState;                    /*!< Status of warning chain systems */
  HEADMTSInputSignal_t DriverFeedback;                    /*!< Driver Feedback */
  HEADMTSInputSignal_t DriverActivity;                    /*!< Driver Activity */
  HEADMTSInputSignal_t DriverAttention;                   /*!< Driver Attention */
  #if HEAD_CFG_TURN_ASSIST
  HEADMTSInputSignal_t SteeringAngle;                     /*!< Steering Angle*/
  HEADMTSInputSignal_t TurnIndicatorInSteeringDirection;  /*!< Turn Indicator In Steering Direction*/
  HEADMTSInputSignal_t GasPedal;                          /*!< Gas Pedal*/
  #endif
  /*this is custom data...*/
  HEADMTSInputSignal_t ExtPreBrakeSetting;                /*!< External Pre Brake Settings */
  #if (MEDIC_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  HEADMTSInputSignal_t CameraReady;                       /*!<camera is available and delivers valid objects */ 
  #endif
  HEADMTSInputSignal_t DIMInputsValid;                    /*!< DIM Inputs */
} HEADMTSInputSignalListDef_t;

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif /* _HEAD_MTS_INPUTDEFS_H_INCLUDED */
/**@}*/ 
