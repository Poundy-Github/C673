/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACT/LOCC (Adaptive Cruise Control - Longitudinal Cruise Control)

PACKAGENAME:               frame_locc_pdo_tags.c

DESCRIPTION:               This module contains LOCC PDO tags 

AUTHOR:                    $Author: uidj5069 $

CREATION DATE:             24.02.2018

VERSION:                   $Revision: 1.2 $

**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "frame_locc.h"
#include "frame_locc_ext.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT))

#ifdef __PDO__

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         locc_pdo   pdo tags for locc
@ingroup          frame_locc
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/

/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

typedef LOCC_SyncRef_t                    PDO_LOCC_SyncRef_t;               /*!< @VADDR:   FCT_MEAS_ID_LOCC_INPUT_SIGHEADERS
                                                                                 @CYCLEID: FCT_VEH
                                                                                 @VNAME:   LOCC_SyncRef */

typedef LOCCFrame_t                       PDO_LOCCFrame_t;                  /*!< @VADDR:   FCT_MEAS_ID_LOCC_FRAME_DATA
                                                                                 @CYCLEID: FCT_VEH
                                                                                 @VNAME:   LOCCFrameData */

typedef ACT_CC_VehicleSpeedStatePort_t    PDO_CC_VehicleSpeedStatePort_t;   /*!< @VADDR:   FCT_MEAS_ID_LOCC_IN_VSSP
                                                                                 @CYCLEID: FCT_VEH
                                                                                 @VNAME:   LOCC_IN_VSSP */

typedef ACT_CC_VehicleSpeedCommandPort_t  PDO_CC_VehicleSpeedCommandPort_t; /*!< @VADDR:   FCT_MEAS_ID_LOCC_OUT_VSCP
                                                                                 @CYCLEID: FCT_VEH
                                                                                 @VNAME:   LOCC_OUT_VSCP */

#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}

#endif /* ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT)) */
