/*! \file **********************************************************************

  COMPANY:                   Continental Teves AG & Co. oHG

  CPU:                       CPU-Independent

  COMPONENT:                 LCF (Lateral Control Funtion)

  MODULNAME:                 polyfitLCF.c

  DESCRIPTION:               implements polyfit of 1st, 2nd and 3rd order for input array of x/y points

  AUTHOR:                    $Author: Handtke, David (uidq4009) $

  CREATION DATE:             $Date: 2019/11/01 18:02:10CET $

  VERSION:                   $Revision: 1.0 $

  CHANGES:                
  ---*/ /*---


**************************************************************************** */

/*****************************************************************************
  INCLUDE PROTECTION
*****************************************************************************/
#ifndef POLYFIT_LCF_
#define POLYFIT_LCF_

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
  TYPEDEFS 
*****************************************************************************/
//#ifdef MATH_LOCAL_SFUNCTION // for SIL mode compatibility. Comment for check-in. 
/*! @brief input to LCF polyfit)*/
typedef struct {
  boolean_T bEnable1st_bool;/*enable 1st order fit*/
  boolean_T bEnable2nd_bool;/*enable 2nd order fit*/
  boolean_T bEnable3rd_bool;/*enable 3rd order fit*/
  real32_T fCrvDecay_nu; /* Curvature change decay factor for polyfit */
  real32_T fCrvChngDecay_nu;/* Curvature change decay factor for polyfit */
  real32_T fXArray_met[20];/*array of x values*/
  real32_T fYArray_met[20];/*array of y values*/
  real32_T fWeight_nu[20];/*weighting for each point*/  
} polyfitLCFInput;

/*! @brief output of LCF polyfit)*/
typedef struct {   
  real32_T fPosY0_1st_met;
  real32_T fPosY0_2nd_met;
  real32_T fPosY0_3rd_met;
  real32_T fHeading_1st_rad;
  real32_T fHeading_2nd_rad;
  real32_T fHeading_3rd_rad;
  real32_T fCrv_2nd_1pm;
  real32_T fCrv_3rd_1pm;  
  real32_T fChngOfCrv_3rd_1pm2;  
  boolean_T bTrajInvalid1st_bool;
  boolean_T bTrajInvalid2nd_bool;
  boolean_T bTrajInvalid3rd_bool;
  real32_T fDevToTraj_1st_met;
  real32_T fDevToTraj_2nd_met;
  real32_T fDevToTraj_3rd_met;
} polyfitLCFOutput;
//#endif // Comment for check-in

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

/* ****************************************************************************
Functionname:    polyfitLCF

@brief           calculates a polynomial fit using least square method

@description     

@param[in]       fObjXPos_met : target object x position

@param[in]       fObjYPos_met : target object y position

@param[out]      vecPolyCoeff : calculated polynomial coefficients

@author          David Handtke
**************************************************************************** */
void polyfitLCF(const polyfitLCFInput* input, polyfitLCFOutput* output);
#endif
