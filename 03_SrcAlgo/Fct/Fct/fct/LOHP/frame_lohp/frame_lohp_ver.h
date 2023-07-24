/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_ver.h

DESCRIPTION:               LOHP Component version header file

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.79.1.6 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef _FRAME_LOHP_VER_H_INCLUDED
#define _FRAME_LOHP_VER_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup   frame_lohp_ver Frame_lohp_version
@brief      Version number control file
@ingroup    lohp_base_frame
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "fct_ver.h"

/*****************************************************************************
  Version: LOHP Longitudinal Headway Planner
*****************************************************************************/

/*  The Component version number is stored as 3 bytes: GEN.CTT.INT
                    SW_LOHP_XX.YY.Z1Z2 with XX = GEN, YY = CTT, Z1Z2 = INT
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
*/
/*   Generation version number.*/
#define LOHP_GEN_VER_NO             0x01

/*   Content version number*/
#define LOHP_CONTENT_VER_NO         0x47

/*!   Integration level number*/
#define LOHP_INT_LEV_NO             0x07

/*! LOHP Component version number: */
#define LOHP_SW_VERSION_NUMBER          ((LOHP_GEN_VER_NO<<16) | (LOHP_CONTENT_VER_NO<<8) | (LOHP_INT_LEV_NO))

/*****************************************************************************
  MACROS 
*****************************************************************************/

#define STR_SW_LOHP_VERSION_NUMBER_TEXT(x) #x
#define STR_SW_LOHP_VERSION_INFO(m,s,i)  FCT_ALL_SW_PROJECT_NAME STR_SW_LOHP_VERSION_NUMBER_TEXT(m) STR_SW_LOHP_VERSION_NUMBER_TEXT(s) STR_SW_LOHP_VERSION_NUMBER_TEXT(i) FCTALL_SW_ALGO_OFFICIAL FCTALL_SW_MODIFICATION_SUMMARY 
#define VERSION_LOHP_INFO_AS_TEXT  STR_SW_LOHP_VERSION_INFO(LOHP_GEN_VER_NO, LOHP_CONTENT_VER_NO, LOHP_INT_LEV_NO)

/*! @brief  To validate the CDL used for data interpretation the current
            version number is also stored as signal name in the CDL.
            Stringify of macro arguments required a two level macro */
#define X_LOHP_MAJOR(m)    ui_##m
#define X_LOHP_SUB(m,s)    m##s
#define X_LOHP_INT(s,i)    s##i
#define X_LOHP_APPEND_(a)  a##_
#define LOHP_MAJOR(m)      X_LOHP_MAJOR(m)
#define LOHP_SUB(m,s)      X_LOHP_SUB(m,s)
#define LOHP_INT(s,i)      X_LOHP_INT(s,i)
#define LOHP_APPEND_(a)    X_LOHP_APPEND_(a)

#define STR_LOHP_VERSION_AS_TEXT(m,s,i)    LOHP_INT(LOHP_APPEND_(LOHP_SUB(LOHP_APPEND_(LOHP_MAJOR(m)),s)),i)
#define X_STR_LOHP_VERSION_AS_TEXT(m,s,i)  STR_LOHP_VERSION_AS_TEXT(m,s,i)
#define LOHP_VERSION_AS_TEXT               X_STR_LOHP_VERSION_AS_TEXT(LOHP_GEN_VER_NO, LOHP_CONTENT_VER_NO, LOHP_INT_LEV_NO)

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

/** @} end defgroup */

#endif /* _FRAME_LOHP_VER_H_INCLUDED */

