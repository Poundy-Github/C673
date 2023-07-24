/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)
  
CPU:                       CPU-Independent
  
COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_lanechange.h

DESCRIPTION:               Header file for ACC Situation (SIT) module, lane change detection of the host vehicle.

AUTHOR:                    Christopher Knievel

CREATION DATE:             04.12.2014

VERSION:                   $Revision: 1.11 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef SIT_LANECHANGE_H_INCLUDED
#define SIT_LANECHANGE_H_INCLUDED


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "sit.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit_lanechange
@{ */
#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  MODULEGLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULGLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/

  /*****************************************************************************
  MODULE LOCAL TYPES
  *****************************************************************************/

  

  /*Camera Output struct for use in camera lane change module*/
  /*Added by Ahmed Shabayek*/
#if (FCT_CFG_FIP_LANE_MATRIX_FUSION && SLATE_CFG_CAM_LANE_INTERFACE)
  typedef struct SIT_LC_CFG_USE_CAMERAOutput{
    SITLCStateCamLaneMarkerCrossed_t t_CamLaneMarkerCrossed;
    SITLaneChangeCamPreMove_t t_LaneChangeCamPreMoveState;
    sint16 s_LCProb;
  }SIT_LC_CFG_USE_CAMERAOutput;
#endif /* END IF FCT_CFG_FIP_LANE_MATRIX_FUSION && FCT_CFG_SEN_CAM_LANE_INTERFACE */
  /*Camera Output struct end*/

/*! States for turn light evaluation */
typedef enum SITLCTurnLightPhase{
  SIT_LC_TURN_LIGHT_ACTIVE,        /*!< Lane change probable due to active turn light */
  SIT_LC_TURN_LIGHT_NOT_ACTIVE     /*!< Lane change not probable due to inactive turn light */
}SITLCTurnLightState_t;

/*! Parameter for calculation of the LC probability, which depend on the cycle time */
typedef struct  
{
  float32 fEgoCurvePT1X;          /*!< Filter coefficient for ego curve */
  GDBVector2_t DriverIntCurveFilterConst[SIT_LC_PROB_POINTS_DRIVER_INT_CURVE_FILTER_TABLE]; /*!< Filter coefficient for driver intended curve */
} SITLaneChangeDynPar_t;

/*! LC probability evaluation based on turn light information */
typedef struct SITLCProbTurnLightEval
{
  SITLCTurnLightState_t State;     /*!< State of LC phase based on turn light information */
  float32 fTimeAfterTLActivation;   /*!< Duration after the turn light was switched on the last time */
}SITLCProbTurnLightEval_t;

/*! Global data for lane change probability calculation, which need to be known beyond one cycle or which are used in other modules */
typedef struct
{ 
  sint8 iTLLeftPrevious;         /*!< Turn light status of left turn light last cycle */
  sint8 iTLRightPrevious;        /*!< Turn light status of right turn light last cycle */
  sint16 iProbability;           /*!< Lane change probability [-100 100] -> probabilities for a LC to the left and right side are combined */
  sint16 iProbabilityBefore;     /*!< Lane change probability in last cycle*/
  float32 fDistLat;               /*!< Distance driven in lateral direction during LC */
  float32 fVelLat;                /*!< Velocity in lateral direction during LC */
  float32 fCurveLevel;            /*!< "Mean" curve level: Should be zero on a straight road and non-zero in a curve */
  float32 fLCPsiBefore;           /*!< Last heading angle independent of cycle time*/
  float32 fLCPsiBeforeBuffer;     /*!< Heading angle in last cycle*/
  float32 fFilteredEgoCurve;      /*!< Filtered ego curve */
  float32 fEgoCurvePT1Previous;   /*!< Filtered ego curve last cycle */
  float32 fDrvIntCurvePT1Previous;  /*!< Filtered driver intended curve last cycle */
  float32 afLatDiffFilteredCurvesFilt[2];   /*!< Filtered difference in lateral distance between filtered ego curve and filtered driver intended curve */
  float32 afLatDiffCamCurveFilt[2];         /*!< Filtered difference in lateral distance between camera curve and filtered driver intended curve */
  float32 fLCKinematicProb;       /*!< Lane change probability based on kinematic signals */
  float32 fLCTIEnvProb;           /*!< Lane change probability based on turn signal indicator and environment */
  float32 fLCPhaseProb;         /*!< Probability for time-gap lane change */
  float32 f_LCProbLeft;
  float32 f_LCProbRight;
  float32 fLCProbFollow;
  SITLCProbTurnLightEval_t LCTurnLightEvalLeft;  /*!< LC phase based on turn light for evaluation of a LC left */
  SITLCProbTurnLightEval_t LCTurnLightEvalRight; /*!< LC phase based on turn light for evaluation of a LC right */
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
  uint8 CamLaneMarkerCrossedProbLeft;
  uint8 CamLaneMarkerCrossedProbRight;
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */
} SITLCProbDataGlobal_t;

/*! Data for calculating the LC probability */
typedef struct
{ 
  sint16 iProbabilityLaneChangeLeft;     /*!< Lane change probability for turning left [0 100] */
  sint16 iProbabilityLaneChangeRight;    /*!< Lane change probability for turning right [0 100] */
  SITLaneChangeDynPar_t DynPar;          /*!< Filter constants which need to be calculated for each cycle (depend on cycle time) */
} SITLCProbDataLocal_t;

/*! Camera lane information for lane change probability calculation */
typedef struct SITLCProbCamLaneEval
{
  boolean bCamLaneVisible;                   /*!< Indicates if camera lane visibility is high enough for using information */
  boolean bCamLaneChangeLeft;                /*!< Indicates if a lane change to the left side was detected by the camera */
  boolean bCamLaneChangeRight;               /*!< Indicates if a lane change to the right side was detected by the camera */
  float32 fCameraCurvature;                   /*!< Curvature if the camera lane */
  float32 fLateralVelocityToCamLaneMarker;    /*!< Lateral velocity of the ego vehicle based on the camera */
}SITLCProbCamLaneInfo_t;

/*!< Input data to calculate the probability values */
typedef struct SITLCProbInputData
{
  float32 fEgoCurvePT1;       /*!< Filtered ego curve */
  float32 fDrvIntCurvePT1;    /*!< Filtered driver intended curve */
  float32 fDistLat;           /*!< Driven distance in lateral direction */
  float32 fCurveLevel;        /*!< "Mean" curve level: Should be zero on a straight road and non-zero in a curve */
  SITLCProbCamLaneInfo_t CamLaneInfo;  /*!< Camera based infos */
}SITLCProbInputData_t;

/*! Global data for lane change probability calculation, which need to be known beyond one cycle */
extern MEMSEC_REF SITLCProbDataGlobal_t SITLCProbDataGlobal; 



#ifdef FCT_SIMU

typedef struct
{ 
  SITLCProbDataLocal_t SITLCProbDataLocal;
  SITLCProbDataGlobal_t SITLCProbDataGlobal;
  SITLCProbInputData_t SITLCProbInput;
  uint8 LatDiffFilteredCurvesProb[2];
  uint8 LatDiffCamCurveProb[2];
  uint8 VelLatCamLaneMarkerProb[2];
  uint8 TurnLightProb[2];
  uint8 DistLatProb[2];
  uint8 CamLaneMarkerCrossedProb[2];
  uint8 CurveProb[2];
} SITLCProbDebugData_t;

extern MEMSEC_REF SITLCProbDebugData_t SITInternalLCProbDebugData;

#endif /*!< FCT_SIMU */

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/
#ifdef FCT_SIMU
#ifndef SIT_LC_PROB_DEBUG_VADDR
#define SIT_LC_PROB_DEBUG_VADDR  (0x2020FD00u)
#endif
#endif  /* FCT_SIMU */

/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/*----------------------------------------------------------------------------
  sit_lanechange.c
----------------------------------------------------------------------------*/
extern float32 SIT_f_CalcGEVDProb(float32 fVal, float32 fKappa, float32 fSigma, float32 fMu);
extern float32 SIT_f_CalcGDProb(float32 fVal, float32 fMean, float32 fSigma);
#if (SIT_CFG_LC_USE_TURN_INDICATOR_INPUT) 
extern eTurnIndicator_t SIT_t_SetTurnIndState(void);
#endif /*SIT_CFG_LC_USE_TURN_INDICATOR_INPUT*/

/*----------------------------------------------------------------------------
  sit_lanechange_cam.c
----------------------------------------------------------------------------*/
extern void SIT_v_InitLaneChangeCam(void);
extern void SIT_v_DetectLaneChangeCam(void);

/*----------------------------------------------------------------------------
  sit_lanechange_kinem.c
----------------------------------------------------------------------------*/
extern void SIT_v_InitLaneChangeKinem(void);
extern void SIT_v_CalculateKinematicLCProb(void);
extern float32 SIT_f_GetLaneChangeStateKinem(void);
extern void SIT_v_ResetLaneChangeStateKinem(void);

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
///@}
#endif /* (FCT_CFG_ACC_SITUATION) */

#ifdef __cplusplus
};
#endif

#endif /*_SIT_LANECHANGE_H_INCLUDED*/

