/*! \file **********************************************************************

  COMPANY:                   Continental ADAS DF

  CPU:                       CPU-Independent

  COMPONENT:                 TJA (Traffic Jam Assist)

  MODULNAME:                 crvKalmanFilter.h

  DESCRIPTION:               Kalman filter heading file

  AUTHOR:                    $Author:  $

  CREATION DATE:             $Date:  $

  VERSION:                   $Revision: 1.0 $

  CHANGES:                
  ---*/ /*---
  CHANGE:                    $Log:  $

**************************************************************************** */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef CRV_KALMAN_FILTER_HEADER_
#define CRV_KALMAN_FILTER_HEADER_
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
#include "abplbp_data.h"
#endif
#endif
/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/
//#ifdef MATH_LOCAL_SFUNCTION /* for SIL mode compatibility. Comment for check-in. */
typedef struct {
   	
    real32_T    sf_Crv_1pm;
    real32_T    sf_CrvChng_1pm2;
	   
    real32_T    sf_CrvStdDev_1pm;
    real32_T    sf_CrvChngStdDev_1pm2;  
	
	real32_T	sf_VehVelX_mps;	
	real32_T	sf_DeltaT_sec;
	
	uint8_T		sf_crvDataValid_bool;
	uint8_T		sf_DegradedUpdate_bool;
	uint8_T 	sf_OverallMeasurementQuality_perc;
	
	real32_T 	sf_CrvKFErrCoeff1_nu;
	real32_T	sf_CrvKFErrCoeff2_nu;
	
	real32_T	sf_CrvKFDefCurve_1pm; 
	real32_T	sf_CrvKFQ11Fac_nu; 
	real32_T	sf_CrvKFQ11FacStraight_nu; 
	
	real32_T	sf_CrvKFInitRFactor_nu;
	uint8_T		sf_CrvKFMnInitQual_perc;
	
	uint8_T		sf_CrvKFMnUpdateQual_perc;
	real32_T	sf_CrvKFDegradeWeight_nu;
	
	real32_T	sf_CrvKFIncQual_1ps;
	real32_T	sf_CrvKFDecQualDeg_1ps;
	real32_T	sf_CrvKFDecQualPred_1ps;
	
} crvKFInTypeV2;

//  Output
typedef struct {
    real32_T    sf_Crv_1pm;
    real32_T    sf_CrvChng_1pm2;
	uint8_T 	sf_KFStatus_btf;
	uint8_T		sf_QualityMeasure_perc;
} crvKFOutType;
//#endif // Comment for check-in



/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

/* ****************************************************************************
Functionname:                                          */ /*!

@brief        
@description     
@param[in]       
@param[out]          

@author          D. Westhofen / S. Hahn / D. Handtke
*****************************************************************************/
void crvKalmanFilter(const crvKFInTypeV2* inputs, crvKFOutType* outputs);
#endif