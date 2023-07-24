/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification

PACKAGENAME:               $Source: slate_custom_pdo_tags.c $

DESCRIPTION:               This module contains ACDC custom PDO tags 

AUTHOR:                    $Author: Raj, Rahul (uid41599) $

CREATION DATE:             $Date: 2020/04/28 14:05:03CEST $

VERSION:                   $Revision: 1.4 $
**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#ifdef __PDO__
#include "cp_customfunctions.h"
#include "out_custom.h"

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         slate_pdo pdo tags for slate custom
@ingroup          slate
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/


/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
typedef CP_CustomOvertakeAssistance_t       PDO_CP_CustomOvertakeAssistance_t    ;/*!< @vaddr: FCT_MEAS_ID_CP_CUSTOM_OVERTAKE 
                                                                                       @cycleid: FCT_ENV 
                                                                                       @vname: CP_CustomOvertakeAssistance */
#endif /* (FCT_CFG_CUSTOM_IO_INTERFACE) */

#ifdef FCT_SIMU
#if (OUT_CFG_DRIVE_OFF_MONITOR)
typedef OUT_CustDriveOffMonDebugData_t      PDO_OUT_CustDriveOffMonDebugData_t    ;/*!< @vaddr: OUT_CUST_DRIVEOFFMON_DEBUG_VADDR 
                                                                                        @cycleid: FCT_ENV 
                                                                                        @vname: OUT_CustInternalDriveOffMonDebugData */
#endif /*ENDIF (OUT_CFG_DRIVE_OFF_MONITOR)*/

#if (FCT_CFG_CUSTOM_PASSING_STATE)
typedef OUT_t_CustomOutputDebugInfo         PDO_OUT_t_CustomOutputDebugInfo       ;/*!< @vaddr: OUT_CUSTOM_OUTPUT_DEBUG_VADDR
                                                                                        @cycleid: FCT_ENV 
                                                                                        @vname: OUT_CustomOutputDebugData */
#endif /*ENDIF (FCT_CFG_CUSTOM_PASSING_STATE)*/
#endif  /* FCT_SIMU */
/// @}
#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}
