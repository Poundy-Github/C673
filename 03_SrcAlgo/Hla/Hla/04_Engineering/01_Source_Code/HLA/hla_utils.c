/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx
 
  COMPONENT:              HLA
 
  FILENAME:               hla_utils.c
 
  DESCRIPTION:            Collection of commonly used utilities like ...
                          ... trigonometric functions
                          ... other mathematical functions
                          ... time measurement
 
  CREATION DATE:          2014-05-28
 
  CPU:                    Independent
 
  VERSION:                $Revision: 1.10 $
*************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_utils.h"
#if defined(_TMS320C6X) || defined(__ARP32__) || defined(__ARMCC_VERSION)
  #include <math.h>
#else
  #include <float.h>
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLA_CYCLE_TIME_ARP32_US  (0.004f)   /* arp32 running with 250 MHz and VCOP with 500 MHz */
#define HLA_CYCLE_TIME_DSP_US    (0.002f)   /* c674x runs with 500 MHz */


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/



/*****************************************************************************
  VARIABLES 
*****************************************************************************/
#ifdef HLA_TIME_MEAS_DETAILED
static AS_t_RTAAlgoServiceAddEvent HlaUtilsRtaServiceFunction = NULL;
#endif

/*****************************************************************************
  LOCAL FUNCTION DECLARATIONS
*****************************************************************************/

/*****************************************************************************
  GLOBAL FUNCTIONS DEFINITION
*****************************************************************************/

#ifdef HLA_TIME_MEAS_DETAILED
void HLAUtilsRegisterRtaService(const AS_t_RTAAlgoServiceAddEvent rtaServiceFunction)
{
  HlaUtilsRtaServiceFunction = rtaServiceFunction;
}
#endif /* #ifdef HLA_TIME_MEAS_DETAILED */

/*********************************************************************************
 * Adds an RTA event to RTE buffer via corresponding service function.
 *********************************************************************************/
/* PRQA S 3206 ++ # 2019-05-28 M.Mutschler: This approach is chosen to avoid many #ifdef HLA_TIME_MEAS_DETAILED in the code. */
void HLAUtilsAddDetailedRtaEvent( const AS_t_RtaEventType RtaEvtType,
                                  const uint8             IdGlobal,
                                  const uint8             IdLocal,
                                  const uint8             OptData
                                 )
{
#ifdef HLA_TIME_MEAS_DETAILED
  if(HlaUtilsRtaServiceFunction != NULL)
  {
    HlaUtilsRtaServiceFunction( RtaEvtType,
                                IdGlobal,
                                IdLocal,
                                OptData
                               );
  }
#endif /* #ifdef HLA_TIME_MEAS_DETAILED */
}
/* PRQA S 3206 -- */


/*********************************************************************************
 * Checks whether a floating point number is not-a-number - platform independent.
 *********************************************************************************/
boolean HLAUtilsIsNAN(const float32 x)
{
#if defined(_TMS320C6X) || defined(__ARP32__) || defined(__ARMCC_VERSION)
  /* PRQA S ALL 1 # 2019-05-29 M.Mutschler: Suppress all warning related to isnan() internal implementation */
  return (boolean)isnan(x);
#else
  return (boolean)_isnan(x);
#endif
}

/*********************************************************************************
 * Checks whether a floating point number is finite - platform independent.
 *********************************************************************************/
boolean HLAUtilsIsFinite(const float32 x)
{
#if defined(_TMS320C6X) || defined(__ARP32__) || defined(__ARMCC_VERSION)
  /* PRQA S ALL 1 # 2019-05-29 M.Mutschler: Suppress all warning related to isnan() internal implementation */
  return (boolean)isfinite(x);
#else
  #ifdef _TASKING_C_TRICORE_
    return (boolean)_isfinitef(x);
  #else
    return (boolean)_finite(x);
  #endif
  
#endif
}


/*****************************************************************************
  LOCAL FUNCTIONS DEFINITION
*****************************************************************************/


