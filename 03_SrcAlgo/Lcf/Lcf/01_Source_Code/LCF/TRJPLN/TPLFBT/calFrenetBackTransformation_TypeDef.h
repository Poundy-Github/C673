/*<BMWHead>********************************************************************

Copyright by BMW Group

PROJECT:        Baukasten

MODULE:         FasQcBplBfrt

Type:           C-Header

CPU:            All

DESCRIPTION:    S-Funktion calFrenetTransformation - Schnittstellendefinitionen

AUTHOR:         JiYa

********************************************************************************

<HISTORY>
#<version>  <modify-date>   <owner>     <comment>
    1.0     14.05.2013      JiYa        Neuerstellung
	        13.11.2015      Removed Dependency on BMW tmwtypes.h
<NEW>
</NEW>
</HISTORY>

*</BMWHead>********************************************************************/

#ifndef CALFRENETRUECKTRANSFORMATION_TYPEDEF_H
#define CALFRENETRUECKTRANSFORMATION_TYPEDEF_H


//#ifdef MATH_LOCAL_SFUNCTION    
#include "P_TrajPlanMathDefs.h"
//#endif 
#ifdef GCC_C
#include "tplfbt_data.h"
#else
#ifndef SILPIL
//  Eingang
typedef struct {
    uint8    	sfunc_NoTrajFound_nu;
    uint8       sfunc_TPLFBT_TrajGuiEnable_nu;
    float32     sfunc_TPLFBT_CridrRightSeg1_Crv_1pm;
    float32     sfunc_TPLFBT_CridrRightSeg1_ChngOfCrv_1pm2;
    float32     sfunc_TPLFBT_TrajDistY_met;
    float32     sfunc_TPLFBT_TrajDistY1stDeriv_nu;
    float32     sfunc_TPLFBT_TrajDistY2ndDeriv_nu;
    float32     sfunc_TPLFBT_TrajDistY3rdDeriv_nu;
    float32     sfunc_TPLFBT_TrajVelRefCurve_mps;
    float32     sfunc_TPLFBT_TrajAclRefCurve_mps2;
    uint8       sfunc_ReplanModeArcLength_nu;
    float32     sfunc_DistYCurValuePreview_met;
    float32     sfunc_DistY1stDerivCurValuePreview_mps;
    float32     sfunc_DevHeading_rad;
    float32     sfunc_DevDistY_met;
    float32     sfunc_YDotTrajFromHeadingPreview_nu;
    float32     sfunc_YDot2TrajFromKappaPrevAndDT_nu;
    float32     sfunc_YDot3TrajFromKappaPrevAndDT_nu;
    float32 	sfunc_YDotDotTrajFromKappaPreview_nu;
} calFBTInType;

//  Ausgang
typedef struct {
    float32     sfunc_TrajDistY_met;
    float32     sfunc_TrajHeading_rad;
    float32     sfunc_TrajTgtCrv_1pm;
    float32     sfunc_TrajTgtCrvGrd_1pms;
    float32		sfunc_TgtCrvGrdTrajInclPrevAndDT_1pms;
    float32     sfunc_HeadingCurValuePreview_rad;
    float32     sfunc_DistYCurValuePreview_met;
    float32     sfunc_TrajHeadingInclPreview_rad;
    float32     sfunc_TgtCrvInclPreviewAndDeadTime_1pm;
    float32     sfunc_TgtCrvTrajInclPreview_1pm;
} calFBTOutType;
#endif

#endif

#endif