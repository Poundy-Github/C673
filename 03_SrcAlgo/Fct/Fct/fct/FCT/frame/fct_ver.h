/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_ver.h

DESCRIPTION:               FCT Component version header file

AUTHOR:                    $Author: Pathak, Praveen (uib42092) (uib42092) $

CREATION DATE:             $Date: 2021/04/21 14:02:55CEST $

VERSION:                   $Revision: 1.96.2.15 $

LEGACY VERSION:            Revision: 2.74

**************************************************************************** */

#ifndef FCT_VER_H_INCLUDED
#define FCT_VER_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "fct_project_id.h"
#include "fct_ver_custom.h"

/*****************************************************************************
  Version: FCT
*****************************************************************************/

/*  The Component version number is stored as 3 bytes: GEN.CTT.INT
                    SW_FCT_XX.YY.Z1Z2 with XX = GEN, YY = CTT, Z1Z2 = INT
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
#define FCTALL_SW_GEN_VER_NO              0x01

/*   Content version number*/
#define FCTALL_SW_CONTENT_VER_NO          0x50

/*!   Integration level number*/
#define FCTALL_SW_INT_LEV_NO              0x14

#define FCTALL_SW_VERSION_NUMBER     (   ( ( (uint32)FCTALL_SW_GEN_VER_NO ) << 16) \
                                       | ( ( (uint32)FCTALL_SW_CONTENT_VER_NO  ) << 8) \
                                       | ( ( (uint32)FCTALL_SW_INT_LEV_NO )))

/* This part is for filling the array uiAlgoVersionNumber in SEN and VEH components */

#define STR_SW_VERSION_NUMBER_TEXT(x) #x
#define STR_SW_VERSION_INFO(m,s,i)  FCT_ALL_SW_PROJECT_NAME STR_SW_VERSION_NUMBER_TEXT(m) STR_SW_VERSION_NUMBER_TEXT(s) STR_SW_VERSION_NUMBER_TEXT(i) FCTALL_SW_ALGO_OFFICIAL FCTALL_SW_MODIFICATION_SUMMARY 
#define VERSION_INFO_AS_TEXT  STR_SW_VERSION_INFO(FCTALL_SW_GEN_VER_NO, FCTALL_SW_CONTENT_VER_NO, FCTALL_SW_INT_LEV_NO)

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*! @brief to validate the CDL used for data interpretation the current
 version number is also stored as signal name in the CDL.
 Stringify of macro arguments required a two level macro */

#define X_FCT_MAJOR(m)    ui_##m
#define X_FCT_SUB(m,s)    m##s
#define X_FCT_INT(s,i)    s##i
#define X_FCT_APPEND_(a)  a##_
#define FCT_MAJOR(m)    X_FCT_MAJOR(m)
#define FCT_SUB(m,s)    X_FCT_SUB(m,s)
#define FCT_INT(s,i)    X_FCT_INT(s,i)
#define FCT_APPEND_(a)  X_FCT_APPEND_(a)

#define STR_FCT_VERSION_AS_TEXT(m,s,i)    FCT_INT(FCT_APPEND_(FCT_SUB(FCT_APPEND_(FCT_MAJOR(m)),s)),i)
#define X_STR_FCT_VERSION_AS_TEXT(m,s,i)  STR_FCT_VERSION_AS_TEXT(m,s,i)
#define FCT_VERSION_AS_TEXT                X_STR_FCT_VERSION_AS_TEXT(FCTALL_SW_GEN_VER_NO, FCTALL_SW_CONTENT_VER_NO, FCTALL_SW_INT_LEV_NO)


/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* _FCT_VER_H_INCLUDED */
