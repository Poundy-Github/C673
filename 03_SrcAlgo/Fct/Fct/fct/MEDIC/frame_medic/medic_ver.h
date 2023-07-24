/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control) 

PACKAGENAME:               medic_ver.h

DESCRIPTION:               MEDIC Component version header file

AUTHOR:                    $Author: Nese, Raghavendra (uidp8028) $

CREATION DATE:             $Date: 2020/12/14 11:34:08CET $

VERSION:                   $Revision: 1.70.1.2 $

**************************************************************************** */
/**
@ingroup frame_medic
@{ **/

#ifndef MEDIC_VER_H_INCLUDED
#define MEDIC_VER_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_ver_custom.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@brief              Contains the components version number of the current software. \n\n
@description        The Component version number is stored as 3 bytes: GEN.CTT.INT
                    SW_MEDIC_XX.YY.Z1Z2 with XX = GEN, YY = CTT, Z1Z2 = INT
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

/************************************************************************/
/*                    SYMBOLIC CONSTANTS                                */
/************************************************************************/
/*! Generation version number. */
#define MEDIC_GEN_VER_NO           0x01

/*! Content version number     */
#define MEDIC_CONTENT_VER_NO       0x44

/*! Integration level number.  */
#define MEDIC_INT_LEV_NO           0x03

/*! Release Client                 SW_MEDIC_01.68.03 */ 
#define MEDIC_RELEASE_CLIENT       0x00

/*! MEDIC Component version number:          */
#define MEDIC_SW_VERSION_NUMBER    ( ((uint32)MEDIC_GEN_VER_NO<<16) | ((uint32)MEDIC_CONTENT_VER_NO<<8) | ((uint32)MEDIC_INT_LEV_NO) )

/* This part is for filling the array uiAlgoVersionNumber in SEN and VEH components */
#define STR_SW_MEDIC_VERSION_NUMBER_TEXT(x) #x
#define STR_SW_MEDIC_VERSION_INFO(m,s,f,i)  FCT_ALL_SW_PROJECT_NAME STR_SW_MEDIC_VERSION_NUMBER_TEXT(m) STR_SW_MEDIC_VERSION_NUMBER_TEXT(s) STR_SW_MEDIC_VERSION_NUMBER_TEXT(f) STR_SW_MEDIC_VERSION_NUMBER_TEXT(i) FCTALL_SW_ALGO_OFFICIAL FCTALL_SW_MODIFICATION_SUMMARY 
#define VERSION_MEDIC_INFO_AS_TEXT          STR_SW_MEDIC_VERSION_INFO(MEDIC_GEN_VER_NO, MEDIC_CONTENT_VER_NO, MEDIC_INT_LEV_NO)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief  To validate the CDL used for data interpretation the current
            version number is also stored as signal name in the CDL.
            Stringify of macro arguments required a two level macro */
#define X_MEDIC_MAJOR(m)    ui_##m
#define X_MEDIC_SUB(m,s)    m##s
#define X_MEDIC_INT(s,i)    s##i
#define X_MEDIC_APPEND_(a)  a##_
#define MEDIC_MAJOR(m)      X_MEDIC_MAJOR(m)
#define MEDIC_SUB(m,s)      X_MEDIC_SUB(m,s)
#define MEDIC_INT(s,i)      X_MEDIC_INT(s,i)
#define MEDIC_APPEND_(a)    X_MEDIC_APPEND_(a)

#define STR_MEDIC_VERSION_AS_TEXT(m,s,i)   MEDIC_INT(MEDIC_APPEND_(MEDIC_SUB(MEDIC_APPEND_(MEDIC_MAJOR(m)),s)),i)
#define X_STR_MEDIC_VERSION_AS_TEXT(m,s,i) STR_MEDIC_VERSION_AS_TEXT(m,s,i)
#define MEDIC_VERSION_AS_TEXT              X_STR_MEDIC_VERSION_AS_TEXT(MEDIC_GEN_VER_NO, MEDIC_CONTENT_VER_NO, MEDIC_INT_LEV_NO)

#ifdef __cplusplus
}
#endif
#endif

/**@}*/

