/*! \file **********************************************************************

 COMPANY:                   Continental ADAS DF

 CPU:                       CPU-Independent

 COMPONENT:                 TJA (Traffic Jam Assist)

 MODULNAME:                 objKalmanFilter.h

 DESCRIPTION:               Kalman filter heading file

 AUTHOR:                    $Author: Asong, Wedndah Asaha (uidj2187) $

 CREATION DATE:             $Date: 2019/03/31 23:02:27CEST $

 VERSION:                   $Revision: 1.1 $

 CHANGES:
 ---*//*---
 CHANGE:                    $Log: objTraceKalmanFilter.h  $
 CHANGE:                    Revision 1.1 2019/03/31 23:02:27CEST Asong, Wedndah Asaha (uidj2187) 
 CHANGE:                    Initial revision
 CHANGE:                    Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/ODPR/ODPFOH/project.pj
 CHANGE:                    Revision 1.5 2018/08/29 10:16:08CEST Nastasa, Elena (uidt4846) 
 CHANGE:                    Check-in for Sprint19 wk2 round 2
 CHANGE:                    Revision 1.4 2018/07/06 12:09:51CEST Nastasa, Elena (uidt4846) 
 CHANGE:                    Check-in for Sprint15 Round2
 CHANGE:                    Revision 1.3 2018/04/19 09:28:40CEST Grosu, George (uidl9584) 
 CHANGE:                    8.2 Initial Revision

 **************************************************************************** */

/*****************************************************************************
 INCLUDE PROTECTION
 *****************************************************************************/
#ifndef OBJ_KALMAN_FILTER_HEADER_
#define OBJ_KALMAN_FILTER_HEADER_
 
#define GCC_C //ElNa: Uncomment for check-in. */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#ifdef MATH_LOCAL_SFUNCTION
#include "tmwtypes.h"
typedef boolean_T uint8;
typedef uint8_T uint8;
typedef uint16_T uint16;
typedef real32_T float32;
#ifndef GTYPES_H
typedef uint32_T uint32;
typedef int32_T sint32;
#endif
#else
#ifdef GCC_C
#include "rtwtypes.h"
#include "odpfoh_data.h"
#endif
#endif

/*****************************************************************************
 MACROS
 *****************************************************************************/

/*****************************************************************************
 LOCAL VARIABLES
 *****************************************************************************/

/*****************************************************************************
 TYPEDEFS
 *****************************************************************************/
//#ifdef MATH_LOCAL_SFUNCTION /* for SIL mode compatibility. Comment for check-in. */

typedef struct
{
   real32_T fPosY0_met;
   real32_T fHeadingAngle_rad;
   real32_T fCrv_1pm;
   real32_T fLength_met;
   real32_T fPosY0StdDev_met;
   real32_T fHeadingAngleStdDev_rad;
   real32_T fCrvStdDev_1pm;
   real32_T fVehYawRateStdDev_radps;
   real32_T fVehVelX_mps;
   real32_T fVehYawRate_radps;
   real32_T fDeltaT_sec;
   uint8_T bEnableKF_bool;
   uint8_T bObjDataValid_bool;
   uint8_T bDegradedUpdate_bool;
   uint8_T uOverallMeasurementQuality_perc;
   uint8_T bObjChange_bool;
   real32_T fObjKinMaxLatAccel_mps2;
   real32_T fObjKinMaxLatJerk_mps3;
   real32_T fObjKinRefVel_mps;
   real32_T fObjKFInitRFactor_nu;
   real32_T fObjKFDegradeWeight_nu;
   uint8_T uObjKFMnUpdateQual_perc;
   uint8_T uObjKFMnInitQual_perc;
   real32_T fObjKFIncQual_1ps;
   real32_T fObjKFDecQualDeg_1ps;
   real32_T fObjKFDecQualPred_1ps;
   real32_T fObjKFKGainFac_nu;
   real32_T fObjKFDynYawFactor_nu;
   real32_T fObjKFDynDistYFact_nu; 
   real32_T fObjKFDynCrvFact_nu;
}TgtObjectTraceKF_Input;

//  Output
typedef struct
{
   real32_T fPosY0_met;
   real32_T fHeadingAngle_rad;
   real32_T fCrv_1pm;
   uint8_T uKFStatus_btf;
   uint8_T uQualityMeasure_perc;
}TgtObjectTraceKF_Output;
//#endif // Comment for check-in

/*****************************************************************************
 FUNCTION PROTOTYPES (EXTERNAL SCOPE)
 *****************************************************************************/

/* ****************************************************************************
 Functionname:                                          *//*!

 @brief
 @description
 @param[in]
 @param[out]

 @author          A. Fen / D. Handtke
 *****************************************************************************/
void objTraceKalmanFilter(const TgtObjectTraceKF_Input* input, TgtObjectTraceKF_Output* output);

#endif
