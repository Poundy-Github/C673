/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_pdo_tags.c

DESCRIPTION:               This module contains LOHP PDO tags 

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2018

VERSION:                   $Revision: 1.8 $

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         lohp_pdo   Frame_lohp_pdo
@ingroup          lohp_base_frame
@brief            This module contains all tags for the PDO scan.
@{
*/

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "frame_lohp.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
#include "hp_ext.h"
#endif

#ifdef __PDO__
/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

typedef LOHPFrame_t                 PDO_LOHPFrame_t;               /*!< @VADDR:   FCT_MEAS_ID_LOHP_FRAME_DATA
                                                                        @CYCLEID: FCT_ENV
                                                                        @VNAME:   LOHP_FrameData */

typedef LOHP_SyncRef_t              PDO_LOHP_SyncRef_t;            /*!< @VADDR:   FCT_MEAS_ID_LOHP_INPUT_SIGHEADERS
                                                                        @CYCLEID: FCT_ENV
                                                                        @VNAME:   LOHP_SyncRef */

#if (FCT_CFG_RUNTIME_MEAS)
typedef FCT_HCRuntimeInfo_t         PDO_FCT_HCRuntimeInfo_t;       /*!< @VADDR:   FCT_MEAS_ID_HC_RUNTIME_DEBUG
                                                                        @CYCLEID: FCT_ENV
                                                                        @VNAME:   FCTSEN_HCRuntimeInfo */
#endif

#if (FCT_CFG_ACC_HEADWAY_PLANNER)
typedef hp_static_mem_u_t           PDO_hp_static_mem_u_t;         /*!< @VADDR:   FCT_MEAS_ID_LOHP_HP_STATIC_MEM
                                                                        @CYCLEID: FCT_ENV
                                                                        @VNAME:   LOHP_HP_Data */
#endif  /* FCT_CFG_ACC_HEADWAY_PLANNER */

#if ( LOHP_CFG_PRED )
typedef PRED_StaticMemUnion_u_t    PDO_PRED_StaticMemUnion_u_t;  /*!< @VADDR:   FCT_MEAS_ID_LOHP_PRED_OUTPUT_DATA
                                                                        @CYCLEID: FCT_ENV
                                                                        @VNAME:   LOHP_PRED_Data */
#endif

#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}

#endif  /* ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

/** @} end defgroup */
