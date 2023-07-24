/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_defs.h

  DESCRIPTION:            Definition file for head light assist.

  CREATION DATE:          2010-09-30
  
  CPU:                    Independent

  VERSION:                $Revision: 1.13.1.1 $
**************************************************************************** */
#ifndef H_HLA_DEFS_H
#define H_HLA_DEFS_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include <stddef.h>
#include <stdint.h>
#include "hla_project_defs.h"
#include "hla_ext.h"
#include "hla_rta_type.h"
#include "RTA_GlobalIDs.h"
#ifdef PC_SIM
  #include "hla_SDS.h" /* Include overview page of detailed design so that it is part of visual studio solution */
#endif

/*****************************************************************************
  SWITCHES 
*****************************************************************************/
/*-------------------
   TESTING SWITCHES:
  -------------------*/
/* Check if we are in QAC: PRQA_SIZE_T is defined in QAC environment. */
#ifdef PRQA_SIZE_T
  #define HLA_QAC_ACTIVE                  ///< A simple switch for conditional code only relevant for QAC
#endif /* PRQA_SIZE_T */
/*-------------------
   PLATFORM SWITCHES:
  -------------------*/


/*-------------------
   PROJECT SWITCHES:
  -------------------*/

#define HLA_CHANGAN_CURVE_FEATURE            ///< ChangAn feature: swa, latacc, yawrate,abs, esp, udlc suppression
#define HLA_REMOVE_VERSIONNUMBER_CHECK       ///< remove version number check 
#define HLA_REMOVE_ALIVE_CHECK               ///< remove timestamp and measurementcounter check 

// #define HLA_REMOVE_SIGSTATUS_CHECK           ///< remove eSigStatus invalid check 


// #define HLA_REMOVE_SERVICEFCT      ///< remove service functions for temp integration

/*----------------------
   GENERIC HLA SWITCHES:
  ----------------------*/
#define HLA_ENABLE_INTERNAL_MEASFREEZES   ///< HLA internal meas freezes are enabled

/*----------------
   DEBUG SWITCHES:
  ----------------*/

/*---------------------
   SIMULATION SWITCHES:
  ---------------------*/
#if defined(PC_SIM) || defined(__COURAGE_TEST_SWITCH__)
  #define HLA_GLOBAL_STATIC               ///< removes/adds static to function, used for simulation/module tests
#else
  /* PRQA S 3414 1 # 2019-05-28 A.Fischer: static definition is wanted. Only used in module test or simulation */
  #define HLA_GLOBAL_STATIC static        ///< removes/adds static to function, used for simulation/module tests
#endif /* #if defined(PC_SIM) || defined(__COURAGE_TEST_SWITCH__) */

/*-------------------
   EVALUATION BOARD:
  -------------------*/
#ifdef EVM_HIL
  #define HLA_TIME_MEAS_DETAILED
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* min/max values for different types */
#define UI32_T_MAX   (4294967295u)        ///< maximal uint32 value to check for overflow
#define UI16_T_MAX        (65535u)        ///< maximal uint16 value to check for overflow
#define UI13_T_MAX         (8191u)        ///< maximal 13 bit value to check for overflow
#define UI12_T_MAX         (4095u)        ///< maximal 12 bit value to check for overflow
#define UI8_T_MAX           (255u)        ///< maximal uint8 value to check for overflow
#define UI6_T_MAX            (63u)        ///< maximal 6 bit value to check for overflow
#define SI32_T_MIN  (-2147483648)         ///< minimal sint32 value to check for overflow
#define SI32_T_MAX   (2147483647)         ///< maximal sint32 value to check for overflow
#define SI16_T_MIN       (-32768)         ///< minimal sint16 value to check for overflow
#define SI16_T_MAX        (32767)         ///< maximal sint16 value to check for overflow
#define SI8_T_MIN          (-128)         ///< minimal sint8 value to check for overflow
#define SI8_T_MAX           (127)         ///< maximal sint8 value to check for overflow

#define MAX_DFRAME 10                     ///< maximum allowed difference between two frames
#define MAX_FRAMENUMBER (sint16)UI8_T_MAX ///< maximum allowed frame number

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/
/* There shouldn't be any functions here. They should be defined in hla_utils.c/h */

#endif /* #ifndef H_HLA_DEFS_H */
