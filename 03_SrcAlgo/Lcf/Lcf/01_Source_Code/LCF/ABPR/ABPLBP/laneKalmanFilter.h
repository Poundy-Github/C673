/*! \file **********************************************************************

 COMPANY:                   Continental ADAS DF

 CPU:                       CPU-Independent

 COMPONENT:                 TJA (Traffic Jam Assist)

 MODULNAME:                 laneKalmanFilter.h

 DESCRIPTION:               Kalman filter heading file

 AUTHOR:                    $Author:  $

 CREATION DATE:             $Date:  $

 VERSION:                   $Revision: 1.0 $

 CHANGES:
 ---*//*---
 CHANGE:                    $Log:  $

 **************************************************************************** */

/*****************************************************************************
 INCLUDE PROTECTION
 *****************************************************************************/
#ifndef LANE_KALMAN_FILTER_HEADER_
#define LANE_KALMAN_FILTER_HEADER_

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
#include "ABPLBP_data.h"
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
   real32_T sf_PosY0_met;
   real32_T sf_HeadingAngle_rad;
   real32_T sf_Crv_1pm;
   real32_T sf_CrvChng_1pm2;
   real32_T sf_Length_met;

   real32_T sf_PosY0StdDev_met;
   real32_T sf_HeadingAngleStdDev_rad;
   real32_T sf_CrvStdDev_1pm;
   real32_T sf_CrvChngStdDev_1pm2;
   real32_T sf_VehYawRateStdDev_radps;

   real32_T sf_VehVelX_mps;
   real32_T sf_VehYawRate_radps;

   real32_T sf_DeltaT_sec;
   uint8_T sf_LaneDataValid_bool;
   uint8_T sf_DegradedUpdate_bool;
   uint8_T sf_OverallMeasurementQuality_perc;   
   
   uint8_T sf_LaneChange_bool;
   
   real32_T sf_LaneKFErrCoeff1_met;     
   real32_T sf_LaneKFErrCoeff2_mps;     
   real32_T sf_LaneKFInitRFactor_nu;
   real32_T sf_LaneKFDegradeWeight_nu;
   uint8_T sf_LaneKFMnUpdateQual_perc;
   uint8_T sf_LaneKFMnInitQual_perc;
   real32_T sf_LaneKFIncQual_1ps;
   real32_T sf_LaneKFDecQualDeg_1ps;
   real32_T sf_LaneKFDecQualPred_1ps;
   real32_T sf_LaneKFKGainFac_nu;
   real32_T sf_LaneKFDynYawFactor_nu;
   real32_T sf_LaneKFDynDistYFact_nu; 
   real32_T sf_LaneKFDynCrvFact_nu;
   real32_T sf_LaneKFDynCrvRateFact_nu;	
}laneKFInTypeV3;

//  Output
typedef struct
{
   real32_T sf_PosY0_met;
   real32_T sf_HeadingAngle_rad;
   real32_T sf_Crv_1pm;
   real32_T sf_CrvChng_1pm2;
   uint8_T sf_KFStatus_btf;
   uint8_T sf_QualityMeasure_perc;
}laneKFOutType;
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

 @author          D. Westhofen / S. Hahn / D. Handtke
 *****************************************************************************/
void laneKalmanFilter_Left(const laneKFInTypeV3* inputs, laneKFOutType* outputs);
void laneKalmanFilter_Right(const laneKFInTypeV3* inputs, laneKFOutType* outputs);
void laneKalmanFilter_Center(const laneKFInTypeV3* inputs, laneKFOutType* outputs);
#endif
