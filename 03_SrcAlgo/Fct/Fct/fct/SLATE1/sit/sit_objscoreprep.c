/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_objscoreprep.c

DESCRIPTION:               SIT object scoring module (abstract object scores for
                           lane assignment)

AUTHOR:                    Gergely Ungvary

CREATION DATE:             -

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)

/* Disable complete module if scoring is disabled */
#if (SIT_CFG_OBJECT_SCORING)
#include "sit_objscore.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit_objscore
@{ */

/*****************************************************************************
  MODULEGLOBAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  MODULGLOBAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*! Configuration switch enabling use of lane width directly from
road estimation. This makes sense for all projects, where a camera
supplied lane width is available. If disable, lane width class is
used as fall-back */
#define SIT_CFG_SCORING_USE_LANE_WIDTH_DIRECTLY  1

/*! Minimum ego speed to assume when calculating ego speed inverse. This
value is used to assure that no divison by zero takes place @min:C_F32_DELTA */
#define SIT_MIN_EGO_SPEED_FOR_INVERSE      (30.f / C_KMH_MS)

/*! Value used to initialize scores */
#define SIT_INIT_SCORE_VAL               0u

/*! The scaling factor for convering ego curvature variance to sigma */
#define SIT_EGO_CURVE_VAR_2_SIGMA_FACT   4e6f

/*! The minimum sigma to use for ego dynamics based scoring */
#define SIT_EGO_MIN_SIGMA                1.0f

/*! The maximum sigma to use for ego dynamics based scoring */
#define SIT_EGO_MAX_SIGMA                5.0f

/*! Weighting parameters for road estimation. Road estimation weight is linearly increased
between the given ego speed points */
#define SIT_PAR_ROAD_SCORE_MAX_SCALE_FACT    1.0f
#define SIT_PAR_ROAD_SCORE_MIN_SCALE_FACT    0.2f
#define SIT_PAR_ROAD_SCORE_MIN_EGO_SPEED     (30.0f / C_KMH_MS)
#define SIT_PAR_ROAD_SCORE_MAX_EGO_SPEED     (100.0f / C_KMH_MS)

/*lane width - class based constants*/
#define SIT_LANEWIDTH_MIN_LIMIT   (2.0f)
#define SIT_LANEWIDTH_MAX_LIMIT   (4.0f)
#define SIT_LANEWIDTH_NORMAL      (3.4f)
#define SIT_LANEWIDTH_NARROW      (2.8f)
#define SIT_LANEWIDTH_MORE_NARROW (2.2f)
#define SIT_LANEWIDTH_UNKNOWN     (2.75f)


/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/

#ifndef STATIC_INLINE
#ifdef _MSC_VER
#define STATIC_INLINE static
#else
#define STATIC_INLINE inline
#endif
#endif

/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void SIT_v_InitLaneInformation(SITLaneInformation_t * const pLane);

/*************************************************************************************************************************
  Functionname:    SIT_f_SetInvEgoSpeed                                                                               */ /*!

  @brief           Calculate the value of inverse of ego speed

  @description     Calculate the value of inverse of ego speed
  
		@startuml
		Start
		Partition SIT_f_SetInvEgoSpeed {
			If (absolute ego speed is below minimum threshold) then (yes)
		If (Ego Speed is smaller than SIT_MIN_EGO_SPEED_FOR_INVERSE) then (yes)
					: Set it to -SIT_MIN_EGO_SPEED_FOR_INVERSE;
				Endif
			Else (no)
				If (Ego Speed is more then - SIT_MIN_EGO_SPEED_FOR_INVERSE)then (yes)
					: Set it to SIT_MIN_EGO_SPEED_FOR_INVERSE;
				Endif
			Endif
			: Using the corrected (non-zero) ego speed calculate the inverse;
		}
		End
		@enduml  

  @return          f_InvEgoSpeed : Inverse Ego Speed [-(1.0f/SIT_MIN_EGO_SPEED_FOR_INVERSE)   (1.0f/SIT_MIN_EGO_SPEED_FOR_INVERSE)] s/m

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING          : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24/07/2017
  @changed         -

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
float32 SIT_f_SetInvEgoSpeed(void)
{
  float32 f_EgoSpeed, f_InvEgoSpeed;

  f_EgoSpeed = *pt_SITInput->t_RTE.pf_EgoLongVel;
  /* If absolute ego speed is below minimum threshold, then set it to the minimum
  with the proper sign (i.e.: if smaller zero, then -SIT_MIN_EGO_SPEED_FOR_INVERSE,
  otherwise to SIT_MIN_EGO_SPEED_FOR_INVERSE) */
  if (f_EgoSpeed >= 0.0f)
  {
    if (f_EgoSpeed < SIT_MIN_EGO_SPEED_FOR_INVERSE)
    {
      f_EgoSpeed = SIT_MIN_EGO_SPEED_FOR_INVERSE;
    }
  }
  else
  {
    if (f_EgoSpeed > -SIT_MIN_EGO_SPEED_FOR_INVERSE)
    {
      f_EgoSpeed = -SIT_MIN_EGO_SPEED_FOR_INVERSE;
    }
  }

  /* Using the corrected (non-zero) ego speed calculate the inverse */
  f_InvEgoSpeed = (1.0f / f_EgoSpeed);

  return(f_InvEgoSpeed);
}

/*************************************************************************************************************************
  Functionname:    SIT_v_InitObjLaneScores                                                                              */ /*!

  @brief           Functional Summary

  @description     This function initializes the passed SITObjLaneScores_t struct

		@startuml
		Start
		Partition SIT_v_InitObjLaneScores {
			Repeat 
				: Initialize Lane Scores with SIT_INIT_SCORE_VAL;
			Repeat While (For all Object Score Lanes)
		}
		End
		@enduml

  @return          This function initializes the passed SITObjLaneScores_t struct

  @param[in,out]   pLaneScores                  [Pointer to structure SITObjLaneScores_t defined in sit_objscore.h]
                    pLaneScores->Lanes[  ]      [0u    SIT_OBJSCORE_MAX]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING          : Configuration switch to enable new object scoring module

  @pre             -
  @post           -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/2/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
void SIT_v_InitObjLaneScores(SITObjLaneScores_t * const pLaneScores)
{
  uint8 eCurLane;
  for (eCurLane = 0u; eCurLane < SIT_OBJ_SCORE_LANE_NUM; eCurLane++)
  {
    pLaneScores->Lanes[eCurLane]   = SIT_INIT_SCORE_VAL;
  }
}

/*************************************************************************************************************************
  Functionname:    SIT_v_InitTraceAddData                                                                               */ /*!

  @brief           This function initializes the passed SITTraceScoreAddData_t struct

  @description     This function initializes the passed SITTraceScoreAddData_t struct

		@startuml
		Start
		Partition SIT_v_InitTraceAddData {
			: Initialize the trace add data;
		}
		End
		@enduml

  @return          -

  @param[in,out]   pTraceAdd    [Pointer to structure SITTraceScoreAddData_t defined in sit_objscore.h]
                    pTraceAdd->iObjNr             [ObjNumber_t defined in Rte_Type.h] [-1   39]
                    pTraceAdd->uNumberOfPoints    [0u   24u]
                    pTraceAdd->uApproxUseLen      [full range uint8]
                    pTraceAdd->uTraceLaneIdx      [full range uint8]
                    pTraceAdd->fApproxCloseDist   [-5*RW_FCT_MAX    5*RW_FCT_MAX] m
                    pTraceAdd->fApproxFarDist     [-5*RW_FCT_MAX    5*RW_FCT_MAX] m
                    pTraceAdd->ApproxPoly.fC0     [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX]
                    pTraceAdd->ApproxPoly.fC1     [full range float32]
                    pTraceAdd->ApproxPoly.fC2     [-1f  1f]
                    pTraceAdd->fSumSqDist         [full range float32>=0] m^2
                    pTraceAdd->fTraceWeightFact   [0f   1f]
                    pTraceAdd->ApproxPoly.isValid [type boolean defined in Platform_Types.h][TRUE,FALSE]
                    pTraceAdd->fTraceWeightedDyn  [0f   1f]
                    pTraceAdd->fTraceOwnConfFact  [0f   1f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_SIMU                     : FCT Simulation
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING        : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/2/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
void SIT_v_InitTraceAddData(SITTraceScoreAddData_t * const pTraceAdd)
{
  pTraceAdd->iObjNr               = OBJ_INDEX_NO_OBJECT;
  pTraceAdd->uNumberOfPoints      = 0u;
  pTraceAdd->uApproxUseLen        = 0u;
  pTraceAdd->uTraceLaneIdx        = SIT_LANE_INDEX_NONE;
  pTraceAdd->fApproxCloseDist     = 0.f;
  pTraceAdd->fApproxFarDist       = 0.f;

  pTraceAdd->ApproxPoly.fC0       = 0.f;
  pTraceAdd->ApproxPoly.fC1       = 0.f;
  pTraceAdd->ApproxPoly.fC2       = 0.f;

  pTraceAdd->fSumSqDist           = 0.f;
  pTraceAdd->fTraceWeightFact     = 0.0f;

  pTraceAdd->ApproxPoly.isValid   = FALSE;

#ifdef FCT_SIMU
  pTraceAdd->fTraceWeightedDyn    = 0.f;
  pTraceAdd->fTraceOwnConfFact    = 0.0f;
#endif
}

/*************************************************************************************************************************
  Functionname:    SIT_v_InitLaneInformation                                                                            */ /*!

  @brief           This function initializes the passed SITLaneInformation_t struct

  @description     This function initializes the passed SITLaneInformation_t struct

		@startuml
		Start
		Partition SIT_v_InitLaneInformation {
			Repeat
				: Set Trace In Lane as 0;
			Repeat While (Up to Max trace Lane)
			: Initialize Lane Information;
		}
		End
		@enduml

  @return          -

  @param[in,out]   pLane  [Pointer to SITLaneInformation_t defined in sit_objscore.h]
                    pLane->NumTraces  : Number of traces assigned to this lane  [type TraceID_t defined in Rte_Type.h] [0  SIT_MAX_NUM_TRACES_PER_LANE]
                    pLane->fCloseDist : smallest X with information             [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                    plane->fFarDist   : largest X with information              [-5*RW_FCT_MAX   5*RW_FCT_MAX] m
                    pLane->pLane->fEstiEgoDist : Estimated distance from ego    [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                    pLane->fLaneSigma          : Lane base sigma spread to use  [full range float32]
                    pLane->ApproxLane.fC0                                       [-PI/2*RW_FCT_MAX   PI/2*RW_FCT_MAX] m
                    pLane->ApproxLane.fC1                                       [full range float32]
                    pLane->ApproxLane.fC2                                       [-1f   1f]


  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING          : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/2/2016
  
  @author         Gergely Ungvary
*************************************************************************************************************************/
static void SIT_v_InitLaneInformation(SITLaneInformation_t * const pLane)
{
  uint8_least uTrace;

  pLane->NumTraces      = 0u;
  for (uTrace = 0u; uTrace < (uint8_least)SIT_MAX_NUM_TRACES_PER_LANE; uTrace++)
  {
    pLane->TracesInLane[uTrace] = 0u;
  }
  pLane->fCloseDist     = 0.0f;
  pLane->fFarDist       = 0.0f;
  pLane->ApproxLane.fC0 = 0.f;
  pLane->ApproxLane.fC1 = 0.f;
  pLane->ApproxLane.fC2 = 0.f;
  pLane->fEstiEgoDist   = 0.f;
  pLane->fLaneSigma     = 0.f;
}

/*************************************************************************************************************************
  Functionname:    SIT_f_SetLaneWidth                                                                               */ /*!

  @brief           Set the value of lanewidth based on input from FIP module

  @description     Set the value of lanewidth based on input from FIP module

		@startuml
		Start
		Partition SIT_f_SetLaneWidth {
			Partition #LightBlue "**~#if SIT_CFG_SCORING_USE_LANE_WIDTH_DIRECTLY && FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING**" {
				: Use the lane width directly from road estimation;
			}
		Partition #LightBlue "**~#if FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING**" {
			If (Lane Width is less than Minimum Lane Width or more than Maximum Lane Width) then (yes)
				If (Normal Lane Width class) then (yes)
					: Set Lane Width as Normal Width;
				Else if (Narrow Lane Width Class) then (yes)
					: Set Lane Width as Narrow Width;
				Else if (More Narrow Lane Width Class) then (yes)
					: Set Lane Width as More Narrow Width;
				Else if (Unknown Lane Width Class) then (yes)
					: Set Lane Width as Unknown Width;
				Else (no)
					: Set Lane Width as Unknown Width;
				Endif
			Endif
		}
		: Update Lane Width;
		}
		End
		@enduml

  @return          f_LaneWidth : Lane Width [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING  :  Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24/07/2017
  @changed         -

  @author          Bharadwaj Gobichettipalayam Sankar | bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
float32 SIT_f_SetLaneWidth(void)
{
    float32 f_LaneWidth = SIT_LANEWIDTH_UNKNOWN;

  /* Determine lane width to use */
#if ((SIT_CFG_SCORING_USE_LANE_WIDTH_DIRECTLY) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING))
  /* Use the lane width directly from road estimation */
  f_LaneWidth = *(FIP_pf_LM_GetLaneWidth());
  /* Do a plausibility check, if it fails, then use lane width
  class based constants instead */
  if ((f_LaneWidth < SIT_LANEWIDTH_MIN_LIMIT) || (f_LaneWidth > SIT_LANEWIDTH_MAX_LIMIT))
#endif /* END IF ((SIT_CFG_SCORING_USE_LANE_WIDTH_DIRECTLY) && (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)) */
#if (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING)
  {
    switch (*(FIP_pt_LM_GetLaneWidthClass()))
    {
    case FIP_LANE_WIDTH_CLASS_NORMAL:
      f_LaneWidth  = SIT_LANEWIDTH_NORMAL;
      break;
    case FIP_LANE_WIDTH_CLASS_NARROW:
      f_LaneWidth  = SIT_LANEWIDTH_NARROW;
      break;
    case FIP_LANE_WIDTH_CLASS_MORE_NARROW:
      f_LaneWidth  = SIT_LANEWIDTH_MORE_NARROW;
      break;
    case FIP_LANE_WIDTH_CLASS_UNKNOWN:
    default:
      f_LaneWidth  = SIT_LANEWIDTH_UNKNOWN;
      break;
    }
  }
#endif/* END IF  (FCT_CFG_LANE_MATRIX_INPUT_PREPROCESSSING) */
  return (f_LaneWidth);
}

/*************************************************************************************************************************
  Functionname:    SIT_v_InitObjScoreData                                                                               */ /*!

  @brief           Functional Summary

  @description     Detailed Design

		@startuml
		Start
		Partition SIT_v_InitObjScoreData {
		#Orange :<b>SIT_v_InitObjLaneScores</b>: Call internal score initialization function for the seperate scores of ego dynamics, road estimation, trace and summary scores;
		: Set assigned lane to unknown;
		}
		End
		@enduml

  @return          -

  @param[in,out]   pScore  [Pointer to structure SITObjScoreData_t defined in sit_objscore.h]
                    pScore->SumScore  [Structure of type SITObjLaneScores_t defined in sit_objscore.h]
                    pScore->eLane     [type eAssociatedLane_t defined in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING          : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/2/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
void SIT_v_InitObjScoreData(SITObjScoreData_t * const pScore)
{
  /* Call internal score initialization function for the seperate scores of
  ego dynamics, road estimation, trace and summary scores */
  SIT_v_InitObjLaneScores(&pScore->SumScore);

  /* Set assigned lane to unknown */
  pScore->eLane = ASSOC_LANE_UNKNOWN;
}


/*************************************************************************************************************************
  Functionname:    SIT_v_InitObjectScores                                                                               */ /*!

  @brief           This function initializes object scoring module

  @description     This function is the initialization routine for data structures
                   in this module. Always call this before any calls to the main
                   SIT_v_CalculateObjectScores function!

		@startuml
		Start
		Partition SIT_v_InitObjectScores {
		Repeat 
			: Initialize score data (Reset scores for each object);
		Repeat While (For each Object)
		Repeat
			: Initialize trace data (Reset trace information for each trace);
		Repeat While (For each Trace)
		Repeat
			: Initialize trace lanes: note only relevant for simulation as lanes are recreated in each cycle anyway;
		Repeat While (For each Trace Lane)
		}
		End
		@enduml

  @return          -

  @param[in]       -

  @glob_in         SITObjectScoreAdd[  ]       [array of structures of type SIObjectScoreAddData_t defined in sit_objscore.c]
  @glob_in         SITObjScores[  ]            [array of structures of type SITObjScoreData_t  defined in sit_objscore.h]
  @glob_in         SITTraceScoreAdd            [structure of type SITTraceScoreAddData_t defined in sit_objscore.h]
  @glob_in         pSITraceLanes              [Pointer to structure SITTraceLanes_t defined in sit_objscore.h]
                     pSITraceLanes->Lanes[ ]  [array of structures of type SITLaneInformation_t defined in sit_objscore.h]

  @glob_out        -

  @c_switch_part   FCT_CFG_ROAD_INPUT             : Road estimation input to FCT

  @c_switch_full   FCT_CFG_ACC_SITUATION   :  FCT support for ACC SIT (situation) sub-component
  @c_switch_full   SIT_CFG_OBJECT_SCORING          : Configuration switch to enable new object scoring module

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/2/2016

  @author          Gergely Ungvary
*************************************************************************************************************************/
void SIT_v_InitObjectScores(void)
{
  ObjNumber_t iObjNr;
  TraceID_t iTrNr;
  SITTraceLanes_t * pSITraceLanes = SIT_pt_GetTraceLanes();

  /* Reset scores for each object */
  for (iObjNr=0; iObjNr < EM_N_OBJECTS; iObjNr++)
  {
    /* Initialize score data */
    SIT_v_InitObjScoreData(&SITObjScores[iObjNr]);
  }

  /* Reset trace information for each trace */
  for (iTrNr = 0u; iTrNr < (TraceID_t)SIT_SCORING_NUM_TRACES; iTrNr++)
  {
    SIT_v_InitTraceAddData(&SITTraceScoreAdd[iTrNr]);
  }
  
  /* Initialize trace lanes : note only relevant for simulation as lanes are
  recreated in each cycle anyway */
  pSITraceLanes->uTrNumLanes = 0u;
  for (iTrNr = 0u; iTrNr < (TraceID_t)SIT_MAX_NUM_TRACE_LANES; iTrNr++)
  {
    SIT_v_InitLaneInformation(&pSITraceLanes->Lanes[iTrNr]);
  }
}
///@}
#endif    /* #if (SIT_CFG_OBJECT_SCORING) */

#endif /* (FCT_CFG_ACC_SITUATION) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

