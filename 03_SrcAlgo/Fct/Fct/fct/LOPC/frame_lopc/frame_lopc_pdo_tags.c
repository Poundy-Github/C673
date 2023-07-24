/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_lopc_pdo_tags.c

DESCRIPTION:               This module contains LOPC PDO tags 

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2018

VERSION:                   $Revision: 1.6 $

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         lopc_pdo   Frame_lopc_pdo
@ingroup          lopc_base_frame
@brief            This module contains all tags for the PDO scan.
@{
*/

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "frame_lopc.h"
#ifdef FCT_SIMU
#if (FCT_CFG_TCI)
#include "tci.h"
#endif
#endif

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))

#ifdef __PDO__

/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

typedef lopc_static_mem_t           PDO_LOPCFrameData_t;           /*!< @VADDR:   FCT_MEAS_ID_LOPC_STATIC_MEM
                                                                        @CYCLEID: FCT_VEH
                                                                        @VNAME:   LOPC_FrameData */


#if (FCT_CFG_ACT_CODE_VERSION == SWITCH_ON)
typedef ACT_EgoVehicleCommandPort_t PDO_EgoVehicleCommandPort_t;   /*!< @VADDR:   FCT_MEAS_ID_LOPC_OUT_EVCP
                                                                        @CYCLEID: FCT_VEH
                                                                        @VNAME:   LOPC_OUT_EVCP */
#else
typedef LOPCErrorOut_t              PDO_LOPCErrorOut_t;            /*!< @VADDR:   FCT_MEAS_ID_LOPC_ERROR_OUT
                                                                        @CYCLEID: FCT_VEH
                                                                        @VNAME:   LOPC_ErrorOut */
#endif

#ifdef FCT_SIMU
#if (FCT_CFG_TCI)
#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 
typedef TCI_SimMeasInfo_t           PDO_TCI_SimMeasInfo_t;         /*!< @VADDR:   FCT_MEAS_ID_TCI_SIM
                                                                        @CYCLEID: FCT_VEH 
                                                                        @VNAME:   TCI_SimMeasInfo */
#endif
#endif
#endif


#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}

#endif  /* ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT)) */

/** @} end defgroup */
