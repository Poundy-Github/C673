/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE

PACKAGENAME:               slate_ver.h

DESCRIPTION:               SLATE Component version header file

AUTHOR:                    $Author: Raj, Rahul (uid41599) $

CREATION DATE:             26.01.2017

VERSION:                   $Revision: 1.84.1.3 $

LEGACY VERSION:            Revision: 2.80.1.1


**************************************************************************** */

#ifndef  SLATE_VER_H_INCLUDED
#define  SLATE_VER_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "fct_ver.h"
#include "slate_ver_custom.h"

/*****************************************************************************
  Version: SLATE Situation Lane Association Trajectory Estimation
*****************************************************************************/
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup slate_ver Version
@ingroup frame
@brief           Comprises the component's version number of current software
@description        The Component version number is stored as 3 bytes: GEN.CTT.INT
                    SW_SLATE_XX.YY.Z1Z2 with XX = GEN, YY = CTT, Z1Z2 = INT
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

/*!   Generation version number.*/
#define SLATE_GEN_VER_NO                      0x01
/*!   Content version number*/
#define SLATE_CONTENT_VER_NO                  0x46
/*!   Integration level number.*/
#define SLATE_INT_LEV_NO                      0x03

  /*! SLATE Component version number: */
#define SLATE_SW_VERSION_NUMBER    ( (SLATE_GEN_VER_NO<<16) | (SLATE_CONTENT_VER_NO<<8) | (SLATE_INT_LEV_NO) )

/* This part is for filling the array uiAlgoVersionNumber in SEN and VEH components */
#define STR_SW_SLATE_VERSION_NUMBER_TEXT(x) #x
#define STR_SW_SLATE_VERSION_INFO(m,s,i)    FCT_ALL_SW_PROJECT_NAME STR_SW_SLATE_VERSION_NUMBER_TEXT(m) STR_SW_SLATE_VERSION_NUMBER_TEXT(s) STR_SW_SLATE_VERSION_NUMBER_TEXT(i) FCTALL_SW_ALGO_OFFICIAL FCTALL_SW_MODIFICATION_SUMMARY 
#define VERSION_SLATE_INFO_AS_TEXT          STR_SW_SLATE_VERSION_INFO(SLATE_GEN_VER_NO, SLATE_CONTENT_VER_NO, SLATE_INT_LEV_NO)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief to validate the CDL used for data interpretation the current
 version number is also stored as signal name in the CDL.
 Stringify of macro arguments required a two level macro */

#define X_SLATE_MAJOR(m)    ui_##m
#define X_SLATE_SUB(m,s)    m##s
#define X_SLATE_INT(s,i)    s##i
#define X_SLATE_APPEND_(a)  a##_
#define SLATE_MAJOR(m)      X_SLATE_MAJOR(m)
#define SLATE_SUB(m,s)      X_SLATE_SUB(m,s)
#define SLATE_INT(s,i)      X_SLATE_INT(s,i)
#define SLATE_APPEND_(a)    X_SLATE_APPEND_(a)

#define STR_SLATE_VERSION_AS_TEXT(m,s,i)    SLATE_INT(SLATE_APPEND_(SLATE_SUB(SLATE_APPEND_(SLATE_MAJOR(m)),s)),i)
#define X_STR_SLATE_VERSION_AS_TEXT(m,s,i)  STR_SLATE_VERSION_AS_TEXT(m,s,i)
#define SLATE_VERSION_AS_TEXT               X_STR_SLATE_VERSION_AS_TEXT(SLATE_GEN_VER_NO, SLATE_CONTENT_VER_NO, SLATE_INT_LEV_NO)

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/



/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

#ifdef __cplusplus
}
#endif

///@}

#endif /* _SLATE_VER_H_INCLUDED */
