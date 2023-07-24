/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC (Adaptive Cruise Control - Interface and State Coordinator)

PACKAGENAME:               isc_pdo_tags.c

DESCRIPTION:               This module contains ISC PDO tags 

AUTHOR:                    $Author: uidj5069 $

CREATION DATE:             24.02.2018

VERSION:                   $Revision: 1.3 $

**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "isc.h"
#include "isc_ext.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))

#ifdef __PDO__

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         isc_pdo   pdo tags for isc
@ingroup          frame_isc
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/

/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

typedef ISCFrame_t                      PDO_ISCFrame_t;                 /*!< @VADDR:   FCT_MEAS_ID_ISC_FRAME_DATA
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISCFrameData */

typedef ISC_SyncRef_t                   PDO_ISC_SyncRef_t;              /*!< @VADDR:   FCT_MEAS_ID_ISC_INPUT_SIGHEADERS
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISC_SyncRef */

typedef ACT_ISC_InformationPort_t       PDO_ISC_InformationPort_t;      /*!< @VADDR:   FCT_MEAS_ID_ISC_IN_IIP
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISC_IN_IIP */

typedef ACT_ISC_CommandPort_t           PDO_ISC_CommandPort_t;          /*!< @VADDR:   FCT_MEAS_ID_ISC_IN_ICP
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISC_IN_ICP */

typedef ACT_ISC_StatusPort_t            PDO_ISC_StatusPort_t;           /*!< @VADDR:   FCT_MEAS_ID_ISC_OUT_ISP
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISC_OUT_ISP */

typedef ACT_CruiseControlStatePort_t    PDO_CruiseControlStatePort_t;   /*!< @VADDR:   FCT_MEAS_ID_ISC_IN_CCSP
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISC_IN_CCSP */

typedef ACT_CruiseControlCommandPort_t  PDO_CruiseControlCommandPort_t; /*!< @VADDR:   FCT_MEAS_ID_ISC_OUT_CCCP
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISC_OUT_CCCP */

typedef ACT_LogicVehicleStatePort_t     PDO_LogicVehicleStatePort_t;    /*!< @VADDR:   FCT_MEAS_ID_ISC_IN_LVSP
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISC_IN_LVSP */

typedef ACT_LogicVehicleCommandPort_t   PDO_LogicVehicleCommandPort_t;  /*!< @VADDR:   FCT_MEAS_ID_ISC_OUT_LVCP
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   ISC_OUT_LVCP */

#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}

#endif  /* ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT)) */
