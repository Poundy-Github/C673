/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification 

PACKAGENAME:               acdc_ver.h

DESCRIPTION:               ACDC Component version header file

AUTHOR:                    $Author: uidn3976 $

CREATION DATE:             $Date: 2020/11/18 11:17:41CET $

VERSION:                   $Revision: 1.129 $

**************************************************************************** */

#ifndef ACDC_VER_H_INCLUDED
#define ACDC_VER_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_ver_custom.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup frame_ver Version
@ingroup frame


@brief              Contains the components version number of the current software. \n\n
@description        The Component version number is stored as 3 bytes: GEN.CTT.INT
                    SW_ACDC_XX.YY.Z1Z2 with XX = GEN, YY = CTT, Z1Z2 = INT
                    XX is incremented for major functionality increases => GEN
                    YY is incremented for regular (biweekly) component releases => CTT
                    Z1 is incremented for manual component releases created in between => INT
                    Z2 is incremented for checkpoints on integration branches => INT
                    
                    GEN: Generation version number.
                         - This number describes the generation of the component
                         - The number starts with 01 for a new component
                         - The number is increased after major changes of the 
                           component architecture
                    CTT: Content version number.
                         - This number describes the functional content (component behaviour).
                         - The number is increased at every biweekly component release
                           the functional content of the component has changed
                    INT: Integration level number.
                         - The number describes the number of integration of the same functional 
                           content but with different bugfixes
                         - The number starts with 00
                         - The number is increased everytime a bugfix release of the component
                           is integrated
                         - The number is set back to 00 everytime CTT is incremented
@{
*/

/************************************************************************/
/*                    SYMBOLIC CONSTANTS                                */
/************************************************************************/
/*!   Generation version number.*/
#define ACDC_GEN_VER_NO                      0x01
/*!   Content version number*/
#define ACDC_CONTENT_VER_NO                  0x3E
/*!   Integration level number.*/
#define ACDC_INT_LEV_NO                      0x01

  /*! ACDC Component version number: */
#define ACDC_SW_VERSION_NUMBER    ( (((uint32)ACDC_GEN_VER_NO)<<16) | (((uint32)ACDC_CONTENT_VER_NO)<<8) | ((uint32)ACDC_INT_LEV_NO) )

/* This part is for filling the array uiAlgoVersionNumber in SEN and VEH components */
#define STR_SW_ACDC_VERSION_NUMBER_TEXT(x) #x
#define STR_SW_ACDC_VERSION_INFO(m,s,i)    FCT_ALL_SW_PROJECT_NAME STR_SW_ACDC_VERSION_NUMBER_TEXT(m) STR_SW_ACDC_VERSION_NUMBER_TEXT(s) STR_SW_ACDC_VERSION_NUMBER_TEXT(i) FCTALL_SW_ALGO_OFFICIAL FCTALL_SW_MODIFICATION_SUMMARY 
#define VERSION_ACDC_INFO_AS_TEXT          STR_SW_ACDC_VERSION_INFO(ACDC_GEN_VER_NO, ACDC_CONTENT_VER_NO, ACDC_INT_LEV_NO)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief  To validate the CDL used for data interpretation the current
            version number is also stored as signal name in the CDL.
            Stringify of macro arguments required a two level macro */
#define X_ACDC_MAJOR(m)    ui_##m
#define X_ACDC_SUB(m,s)    m##s
#define X_ACDC_INT(s,i)    s##i
#define X_ACDC_APPEND_(a)  a##_
#define ACDC_MAJOR(m)      X_ACDC_MAJOR(m)
#define ACDC_SUB(m,s)      X_ACDC_SUB(m,s)
#define ACDC_INT(s,i)      X_ACDC_INT(s,i)
#define ACDC_APPEND_(a)    X_ACDC_APPEND_(a)

#define STR_ACDC_VERSION_AS_TEXT(m,s,i)    ACDC_INT(ACDC_APPEND_(ACDC_SUB(ACDC_APPEND_(ACDC_MAJOR(m)),s)),i)
#define X_STR_ACDC_VERSION_AS_TEXT(m,s,i)  STR_ACDC_VERSION_AS_TEXT(m,s,i)
#define ACDC_VERSION_AS_TEXT               X_STR_ACDC_VERSION_AS_TEXT(ACDC_GEN_VER_NO, ACDC_CONTENT_VER_NO, ACDC_INT_LEV_NO)
  

#ifdef __cplusplus
}
#endif

///@}

#endif /* ACDC_VER_H_INCLUDED */
