/*<BMWHead>********************************************************************

Copyright by BMW Group

PROJECT:        Baukasten

MODULE:         FasQcBplBtb

Type:           C-Header

	CPU:            All

DESCRIPTION:    S-Funktion TrajCalc_CalcOptTrajectory - Schnittstellendefinitionen

AUTHOR:         JiYa

********************************************************************************

<HISTORY>
#<version>  <modify-date>   <owner>     <comment>
    1.0     30.04.2013      JiYa        Neuerstellung
	        13.11.2015      Removed Dependency on BMW tmwtypes.h
<NEW>
</NEW>
</HISTORY>

*</BMWHead>********************************************************************/

#ifndef CALOPTTRAJEKTORIE_TYPEDEF_H
#define CALOPTTRAJEKTORIE_TYPEDEF_H

#include "P_TrajPlanMathDefs.h"

#ifdef GCC_C
#include "tpltjc_data.h"
#else

#ifndef SILPIL
typedef struct {
    float32     sfunc_DistYInit_nu;                  
	float32     sfunc_DistY1stDerivInit_nu; 
	float32	    sfunc_DistY2ndDerivInit_nu;
    float32     sfunc_Kd;
    float32     sfunc_Kt;
    float32     sfunc_TrajCalcEgoVelX_mps;
    float32     sfunc_TrajCalcTgtDistY_met[15];
    float32     sfunc_TrajCalcTgtDistY1stDeriv_nu[15];
    float32     sfunc_TrajCalcTgtDistY2ndDeriv_nu[15];
	float32     sfunc_LatCtrlCoordCridrRightSeg1_Crv_1pm;
    float32     sfunc_TolDistYRight_met;
    float32     sfunc_TolDistYLeft_met;
    uint8       sfunc_CheckFtire_nu;
    uint8       sfunc_CheckCridrBoundaries_nu;
    uint8       sfunc_CheckObjects_nu;
    uint8       sfunc_CheckJerk_nu;
    uint8       sfunc_CheckLaneCross_nu;
    float32     sfunc_AclPotVecMin_mps2;
    float32     sfunc_AclPotVecMax_mps2;   
    float32     sfunc_teTrajCalcTgt_nu[15];
    uint8       sfunc_TrajCalcNumTgtPoints_nu;
    float32     sfunc_TrajCalcCircleRadius_met;
    float32     sfunc_TrajCalcCircleDistance_met;
    float32     sfunc_TrajCalcCridrRightSeg1_Length_met;
    float32     sfunc_TrajCalcCridrLeftSeg1_Length_met;
    float32     sfunc_Obstacle_DistX_met;
    float32     sfunc_Obstacle_DistY_met;
    float32     sfunc_Obstacle_Width_met;
    float32     sfunc_TrajCalcDistYLeft_met[100];
    uint8       sfunc_ReplanModeArcLength_nu;
    float32     sfunc_WeightArcLengthPlan_nu;
    float32     sfunc_TrajCalcPlanHorizonTraj_sec;
    float32     sfunc_TrajCalcPlanHorizonVisibility_sec;
    float32     sfunc_TrajCalcTrajVel_mps;
    float32     sfunc_TrajCalcTrajAcl_mps2;
    float32     sfunc_TrajCalcDeadTime_sec;
    uint8       sfunc_TrajCalcNCircles_nu;
    uint8    	sfunc_TrajCalcNumCridrPointsLeft_nu;
    float32		sfunc_TrajCalcObjVelX_mps;
    float32		sfunc_TrajCalcObjAclX_mps2;
    float32     sfunc_CrvChng_1pm2;
    float32     sfunc_AllwdJerkMax_mps3;
    float32     sfunc_LaneWidth_met;
    float32     sfunc_VehicleWidth_met;
    float32     sfunc_AllowedTimetoCross_sec;
} calOptInTypeV3;

typedef struct {
	uint8       sfunc_TrajStatus_nu;
    float32     sfunc_TrajParam_nu[6];
    float32     sfunc_MaxAclTraj_mps2;
    float32     sfunc_TrajCalcTimeTrajEnd_sec;
    float32     sfunc_ArcLengthTrajEnd_met;
    float32     sfunc_OptimalTolerance_nu;
    float32     sfunc_OptimalCost_nu;
    uint8	    sfunc_FtireMinOK_nu;
    uint8	    sfunc_FtireMaxOK_nu;
    uint8       sfunc_CollDetRightOK_nu;
    uint8	    sfunc_CollDetLeftOK_nu;
    uint8	    sfunc_CollDetObjOK_nu;
    uint8	    sfunc_MatrixInverseOK_nu;
    uint8	    sfunc_LaneCrossOK_nu;
    uint8	    sfunc_TrajLengthOK_nu;
    float32     sfunc_MaxJerkTraj_mps3;
    uint8	    sfunc_MaxJerkOK_nu;    
} calOptOutTypeV4;
#endif 

#endif

#endif