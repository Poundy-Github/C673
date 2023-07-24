/** \file ******************************************************************
COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

PROJECT:                MFC4xx

COMPONENT:              HLA

FILENAME:               HLA_DecisionParameters.c

DESCRIPTION:            Parameters of decision module

CREATION DATE:          2018-05-14

CPU:                    Independent

VERSION:                $Revision: 1.11.2.2 $
**************************************************************************** */
/* PRQA S 7013 EOF # 2019-05-28 A.Fischer: Number of executable lines as it doesn't make any sense in this file */
/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "HLA_DecisionParameters.h"

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL VARIABLES
*****************************************************************************/
static const t_DecisionParameters m_DecisionParameters =
{
  /* City */
  {
    /* minCityDist_m */             100.0f,
    /* minCityTime_s */             6.0f,
    /* maxMayBeCityDist_m */        200.0f,
    /* minMayBeCityDist_m */        50.0f,
    /* minMayBeCityTime_s */        1.0f
  },

  /* Blockage */
  {
    /* ClearMeas2Blockage_DistThres */    500.0f,
    /* ClearMeas2Blockage_TimeThres */    30.0f,
    /* ClearMeas2NoBlockage_DistThres */  50.0f
  },

  /* Weather */
  {
    /* WiperTriggerEnterTime */ 60.0f,
    /* WiperTriggerLeaveTime */ 60.0f,
    /* WiperStageThreshold */ VEH_SIG_ADD_WIPER_STAGE1,
  },

  /* TurnOnDelay */
  {
    /* initialTurnOnDelay */            1.5f,
    /* OncomingMin_DistThreshold */    30.0f, 
    /* OncomingMin_LatDistThreshold */  1.5f,
    /* PrecedingTimeGap_Threshold */    2.0f,
    /* PrecedingTimeGap */              2.0f
  },
  /* KeepOff */
  {
    /* maxDist2Cover */             80.0f,
    /* minTimeHBOff_s */             3.0f,

    /* KeepOffPotVeh */
    {
      /* Delay_Onc */                0.4f,
      /* Delay_Prec */               1.0f,
      /* Delay_Glob */               1.0f,
      /* high_probability_vehicle */ 50u,
      /* low_probability_vehicle  */ 5u
    },

    /* MayBeCity */
    {
      /* Delay_Onc */               1.0f,
      /* Delay_Prec */              1.0f,
      /* Delay_Glob */              1.0f
    },
    /* minTraceTimeSO */            10u,
    /* minClassConfidenceSO */      80u,
    /* minProbOfExSO */             75u,
    /* maxDeltaXSO */               10.0f,
    /* maxLateralOffsetSO */        10.0f,
    /* minDistanceSO */             10.0f,
    /* maxDeltaSpeedSO */           -5.5f,
    /* smallRadiusRadius2TurnsOnThres */ 120.0f,
    /* swaThreshold*/                    90.0f,
    /* yawrateThreshold*/                0.19f,
    /* lataccThreshold*/                 3.0f,
    /* smallRadiusTurnOnDelay */         0.25f,
    /* bUseMinimumKOR */                 b_FALSE
  },
  /* SceneInfo */
  {
    /* distanceOncoming */  100.0f,
    /* distancePreceding */  50.0f
  },
  /* LSDObjHorAngThreshold */ 16.0f
};
/****************************************************************************
* LOCAL FUNCTIONS DECLARATION
*****************************************************************************/
 
/****************************************************************************
* GLOBAL FUNCTIONS DEFINTION
*****************************************************************************/
/* return pointer to HLA decision parameters */
const t_DecisionParameters* GetDecisionParameters(void)
{
  return &m_DecisionParameters;
}
 
/****************************************************************************
* LOCAL FUNCTIONS DEFINTION
*****************************************************************************/
