/** \file ******************************************************************
COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

PROJECT:                MFC4xx

COMPONENT:              HLA

FILENAME:               HLA_MatrixParameters.c

DESCRIPTION:            Parameters of matrix module

CREATION DATE:          2018-05-14

CPU:                    Independent

VERSION:                $Revision: 1.15 $
**************************************************************************** */
/* PRQA S 7013 EOF # 2019-05-28 A.Fischer: Number of executable lines as it doesn't make any sense in this file */
/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "HLA_MatrixParameters.h"

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL VARIABLES
*****************************************************************************/
static const t_MatrixParameters m_MatrixParameters = 
{
  /* SAE */
  {
    /* minIntTurnOff            */ 2000u,  /* ~2cd in 100ft */
    /* minIntTurnOffRightOffset */ 39000u, /* ~50 cd in 100ft */
    /* targetDistance           */ 30.48f, /*[m] (=100ft)*/
    /* targetLateralOffset      */ -2.55f  /*[m] 5 degrees to the right in 100ft => -2.67m (-10cm tolerance)*/
  },

  /* GFA */
  {
    /* KeepGFAMinTime_s */          1.0f,
    /* MaxTruckHeight_m */          5.0f,
    /* AddTruckLightAngle */        0.0349065f, /* CML_Deg2Rad(2.0f) */
  },

  /* ClusterVeh2GFA */
  {
    /* dAngPrec [rad] */            0.03490658f,       /* CML_Deg2Rad(2.0f) */
    /* dAngOnc [rad] */             0.03490658f,       /* CML_Deg2Rad(2.0f) */
    /* dAng [rad] */                0.03490658f,       /* CML_Deg2Rad(2.0f) */
    /* WidthPrec [m] */             0.0f,
    /* WidthOnc [m] */              0.0f,
    /* Width [m] */                 0.0f
  },

  /* Output */
  {
    /* BndryLeft_Ang_Min */         -0.34906585f,       /* CML_Deg2Rad(-20.0f) */
    /* BndryLeft_Ang_Max */         0.34906585f,        /* CML_Deg2Rad(20.0f) */

    /* BndryRight_Ang_Min */        -0.34906585f,       /* CML_Deg2Rad(-20.0f) */
    /* BndryRight_Ang_Max */        0.34906585f,        /* CML_Deg2Rad(20.0f) */

    /* BndryLower_Ang_Min */        -0.08726646f,       /* CML_Deg2Rad(-5.0f) */
    /* BndryLower_Ang_Max */        0.08726646f,        /* CML_Deg2Rad(5.0f) */

    /* BndryUpper_Ang_Min */        -0.17453292f,       /* CML_Deg2Rad(-10.0f) */
    /* BndryUpper_Ang_Max */        0.08726646f,        /* CML_Deg2Rad(5.0f) */

    /* ClosestObj_Dist_Min */       0.0f,
    /* ClosestObj_Dist_Max */       450.0f,

    /* ClosestObj_Ang_Min */        -0.34906585f,       /* CML_Deg2Rad(-20.0f) */
    /* ClosestObj_Ang_Max */        0.34906585f,        /* CML_Deg2Rad(20.0f) */

    /* MinLight_Dist_Min */         0.0f,
    /* MinLight_Dist_Max */         450.0f,

    /* MinLight_Ang_Min */          -0.34906585f,       /* CML_Deg2Rad(-20.0f) */
    /* MinLight_Ang_Max */          0.34906585f,        /* CML_Deg2Rad(20.0f) */

    /* LowBeam_Dist_Default */      65.0f,
    /* LowBeam_Dist_Min */          0.0f,
    /* LowBeam_Dist_Max */          600.0f,
    /* LowBeam_Dist_Onc_Min */      0.0f,
    /* LowBeam_Dist_Onc_Max */      150.0f,
    /* LowBeam_Dist_Prec_Min */     0.0f,
    /* LowBeam_Dist_Prec_Max */     600.0f,

    /* LowBeam_Ang_Default */       0.0f,
    /* LowBeam_Ang_Onc_Min */       -0.34906585f,       /* CML_Deg2Rad(-20.0f) */
    /* LowBeam_Ang_Onc_Max */       0.34906585f         /* CML_Deg2Rad(20.0f) */
  },
  /* Input */
  {
    /* EMObjMaxDist                   */  100.0f,
    /* EMObjUpperProbabilityThresh    */  75u,
    /* EMObjLowerProbabilityThresh    */  25u,
    /* EMObjMinClassConfidence        */  80u,
    /* RadarObjAngleFusionRegion      */  0.33161255f,     /* CML_Deg2Rad(19.0f) */
    /* RadarObjDistFusionRegion       */  10000.0f,
    /* RadarObjAngleRadarOnlyRegion   */  0.45204027f,     /* CML_Deg2Rad(25.9f) */
    /* RadarObjDistRadarOnlyRegion    */  50.0f,
    /* RadarObjLatDistRadarOnlyRegion */  8.0f,
    /* RadarObjMinDynConfidence       */  90u,
    /* RadarObjMinProbOfEx            */  99u,
    /* RadarObjMinClassConfidence     */  50u,
    /* RadarObjCloseObjDist           */  80.0f,
    /* RadarObjMinLifeCycles          */  30u,
    /* RadarOnlyRegionOuterAngle      */  0.43633231f,     /* CML_Deg2Rad(25.0f) */
    /* RadarOnlyRegionInnerAngle      */  0.26179938f,     /* CML_Deg2Rad(15.0f) */
    /* RadarObjAssumedWidth           */  3.0f,
    /* RadarObjRelCountSmallStep      */  1u,
    /* RadarObjRelCountBigStep        */  6u,
    /* RadarObjSmallStepCounterThres  */  2u,
    /* RadarObjRelevanceThres         */  5u,
    /* RadarObjMinVehProb             */  90u,
    /* RadarFusionMaxAngleDiff        */  0.04f,           /* CML_Deg2Rad(2.3f) */
    /* LSDRoiRegionCenterRightOffset  */ -2.0f,
    /* LSDRoiRegionCenterLeftOffset;  */  2.0f,
    /* LSDRoiRegionCenterXDistance;   */  100.0f
  },
  /* Cfg */
  {
    /* bGFACalculationInTwilight */ b_FALSE,
    /* bMotionIndOutputGFAData */   b_FALSE,
    /* bUseEMInputforGFA */         b_TRUE
  }
};
/****************************************************************************
* LOCAL FUNCTIONS DECLARATION
*****************************************************************************/
 
/****************************************************************************
* GLOBAL FUNCTIONS DEFINTION
*****************************************************************************/
/* return pointer to HLA matrix parameters */
const t_MatrixParameters* GetMatrixParameters(void)
{
  return &m_MatrixParameters;
}
/****************************************************************************
* LOCAL FUNCTIONS DEFINTION
*****************************************************************************/
