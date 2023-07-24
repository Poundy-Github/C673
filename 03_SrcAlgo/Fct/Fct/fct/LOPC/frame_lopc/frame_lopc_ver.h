/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_lopc_ver.h

DESCRIPTION:               LOPC Component version header file

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.06.2017

VERSION:                   $Revision: 1.84.1.5 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */

#ifndef _FRAME_LOPC_VER_H_INCLUDED
#define _FRAME_LOPC_VER_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup   frame_lopc_ver Frame_lopc_version
@brief      Version number control file
@ingroup    lopc_base_frame
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "fct_ver.h"

/*****************************************************************************
  Version: LOPC Longitudinal Planner and Controller
*****************************************************************************/

/*  The Component version number is stored as 3 bytes: GEN.CTT.INT
                    SW_LOPC_XX.YY.Z1Z2 with XX = GEN, YY = CTT, Z1Z2 = INT
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
#define LOPC_GEN_VER_NO             0x01

  /*   Content version number*/
#define LOPC_CONTENT_VER_NO         0x4A

  /*!   Integration level number*/
#define LOPC_INT_LEV_NO             0x05

  /*! LOPC Component version number: */
#define LOPC_SW_VERSION_NUMBER          ((LOPC_GEN_VER_NO<<16) | (LOPC_CONTENT_VER_NO<<8) | (LOPC_INT_LEV_NO))

/*****************************************************************************
  MACROS 
*****************************************************************************/

#define STR_SW_LOPC_VERSION_NUMBER_TEXT(x) #x
#define STR_SW_LOPC_VERSION_INFO(m,s,i)  FCT_ALL_SW_PROJECT_NAME STR_SW_LOPC_VERSION_NUMBER_TEXT(m) STR_SW_LOPC_VERSION_NUMBER_TEXT(s) STR_SW_LOPC_VERSION_NUMBER_TEXT(i) FCTALL_SW_ALGO_OFFICIAL FCTALL_SW_MODIFICATION_SUMMARY 
#define VERSION_LOPC_INFO_AS_TEXT  STR_SW_LOPC_VERSION_INFO(LOPC_GEN_VER_NO, LOPC_CONTENT_VER_NO, LOPC_INT_LEV_NO)

/*! @brief  To validate the CDL used for data interpretation the current
            version number is also stored as signal name in the CDL.
            Stringify of macro arguments required a two level macro */
#define X_LOPC_MAJOR(m)    ui_##m
#define X_LOPC_SUB(m,s)    m##s
#define X_LOPC_INT(s,i)    s##i
#define X_LOPC_APPEND_(a)  a##_
#define LOPC_MAJOR(m)      X_LOPC_MAJOR(m)
#define LOPC_SUB(m,s)      X_LOPC_SUB(m,s)
#define LOPC_INT(s,i)      X_LOPC_INT(s,i)
#define LOPC_APPEND_(a)    X_LOPC_APPEND_(a)

#define STR_LOPC_VERSION_AS_TEXT(m,s,i)    LOPC_INT(LOPC_APPEND_(LOPC_SUB(LOPC_APPEND_(LOPC_MAJOR(m)),s)),i)
#define X_STR_LOPC_VERSION_AS_TEXT(m,s,i)  STR_LOPC_VERSION_AS_TEXT(m,s,i)
#define LOPC_VERSION_AS_TEXT               X_STR_LOPC_VERSION_AS_TEXT(LOPC_GEN_VER_NO, LOPC_CONTENT_VER_NO, LOPC_INT_LEV_NO)

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

#endif /* _FRAME_LOPC_VER_H_INCLUDED */
