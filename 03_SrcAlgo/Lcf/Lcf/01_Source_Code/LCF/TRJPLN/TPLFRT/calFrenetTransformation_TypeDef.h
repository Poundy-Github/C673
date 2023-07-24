/*<BMWHead>********************************************************************

Copyright by BMW Group

PROJECT:        Baukasten

MODULE:         FasQcBplBft

Type:           C-Header

CPU:            All

DESCRIPTION:    S-Funktion calFrenetTransformation - Schnittstellendefinitionen

AUTHOR:         JiYa

********************************************************************************

<HISTORY>
#<version>  <modify-date>   <owner>     <comment>
    1.0     28.03.2013      JiYa        Neuerstellung
	        13.11.2015      Removed Dependency on BMW tmwtypes.h
<NEW>
</NEW>
</HISTORY>

*</BMWHead>********************************************************************/

#ifndef CALFRENETTRANSFORMATION_TYPEDEF_H
#define CALFRENETTRANSFORMATION_TYPEDEF_H

//#ifdef MATH_LOCAL_SFUNCTION
#include "P_TrajPlanMathDefs.h"
//#endif

#ifdef GCC_C
#include "tplfrt_data.h"
#else

#ifndef SILPIL
//  Eingang
typedef struct {
    float32     sf_DevDistY_met;
    float32     sf_DevHeading_rad;
    float32     sf_CridrRightSg1_Crv_1pm;
    float32     sf_CridrRightSg1_ChOfCrv_1pm2;
    float32     sf_CridrRightSg1_Length_met;
    float32     sf_CridrLeftSg1_DistY_met;
    float32     sf_CridrLeftSg1_Heading_rad;
    float32     sf_CridrLeftSg1_Crv_1pm;
    float32     sf_CridrLeftSg1_ChOfCrv_1pm2;
    float32     sf_CridrLeftSg1_Length_met;
    float32     sf_TgtTrajSg1_DistY_met;
    float32     sf_TgtTrajSg1_Heading_rad;
    float32     sf_TgtTrajSg1_Crv_1pm;
    float32     sf_TgtTrajSg1_ChngOfCrv_1pm2;
    float32     sf_TgtTrajSg1_Length_met;
    uint8       sf_TrajPlanEnbl_nu;
    uint8       sf_TrigRecalc_nu;
    float32     sf_PlanningHorizon_sec;
    float32     sf_CurCrvVehMotion_1pm;
    float32     sf_StartCrv_1pm;
    float32     sf_EgoVelX_mps;
    float32     sf_EgoAclX_mps2;
    float32     sf_TgtCrvTrajPrev_1pm;
    float32     sf_TgtTrajSg1_DistX_met;
    uint8       sf_ReplanModeArcLength_nu;
    uint8       sf_LeftCridrActive_nu;
    float32     sf_DistYTrajPrev_met;
    float32     sf_HeadingTrajPrev_rad;
    float32     sf_CurHdngAndDeltaHdng_rad;
    float32     sf_PreviewTimeHeading_sec;
    float32 	sf_DeadTime_sec;
    uint8       sf_TrigTgtTrajCalc_nu;
    float32		sf_CridrRightSg1_DistX_met;
    float32		sf_CridrLeftSg1_DistX_met;
    uint8		sf_UseTgtTrajX0_nu;
    uint8		sf_UseCridrRightX0_nu;
    float32		sf_CridrRightSg1_Heading_rad;
    float32		sf_CridrRightSg1_DistY_met;
    uint8       sf_ReplanCurValues_nu;
} calFTInTypeV3;

//  Ausgang
typedef struct {
    float32     sf_DistYCurValue_met;
    float32     sf_DistY1stDerivCurValue_nu;
    float32     sf_DistY2ndDerivCurValue_nu;
    float32     sf_TrajVel_mps;
    float32     sf_TrajAcl_mps2;
    float32     sf_TgtDistY_met[15];
    float32     sf_TgtDistY1stDeriv_nu[15];
    float32     sf_TgtDistY2ndDeriv_nu[15];
    float32     sf_DistYLeft_met[100];
    float32     sf_TrajDistYPrevious_met;
    float32     sf_TrajDistYPrev1stDeriv_nu;
    float32     sf_TrajDistYPrev2ndDeriv_nu;
    uint8       sf_NumTgtPoints_nu;
    float32     sf_TgtPoints_nu[15];
    float32     sf_TrajPlanningHorizon_sec;
    float32     sf_PlanHorizonVisRange_sec;
    float32     sf_1stDerivDevHeading_nu;
    float32     sf_2ndDerivDevHeading_nu;
    float32     sf_DstYCurValuePreview_met;
    float32     sf_DstY1stDrvCurValPrvw_mps;
    float32     sf_FrenTrafHeadingPrvw_sec;
    uint8       sf_NumPointsCridrLeft_nu;
    float32		sf_CridrRight_Crv_1pm[15];
    uint8 		sf_NumPointsCridrRight_nu;
} calFTOutType;
#endif

#endif

#endif
