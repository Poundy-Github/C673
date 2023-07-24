/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_pdo_tags.c

DESCRIPTION:               This module contains MEDIC PDO tags

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2020/05/20 10:57:52CEST $

VERSION:                   $Revision: 1.23 $

**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "frame_medic/medic_int.h"

#if MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
#if MEDIC_CFG_HEAD20
#include "head20/head20_int.h"
#else
#include "head/head_int.h"
#endif // MEDIC_CFG_HEAD20
#endif // MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

#if MEDIC_CFG_DRIVER_INTENTION_MONITORING
#if MEDIC_CFG_DIM20
#include "dim20/dim20_main.h"
#else
#include "dim/dim_main.h"
#endif // MEDIC_CFG_DIM20
#endif // MEDIC_CFG_DRIVER_INTENTION_MONITORING

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static void DummyForCompiler (void);

#ifdef __PDO__
#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         medic_pdo   pdo tags for medic
@ingroup          frame_medic
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/

/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

#if (MEDIC_CFG_USE_ALGOCOMPSTATE)
typedef AlgoCompState_t            PDO_AlgoCompState_t;            /*!< @VADDR:   FCT_MEAS_ID_VEH_EBA_COMP_STATE
                                                                        @CYCLEID: FCT_VEH
                                                                        @VNAME:   MEDIC_CompState */
#endif // MEDIC_CFG_USE_ALGOCOMPSTATE

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
typedef HEADMTSModuleCommonOut_t   PDO_HEADMTSModuleCommonOut_t;   /*!< @VADDR:   FCT_MEAS_ID_CGEB_HEAD_COMMON_OUT
                                                                        @CYCLEID: FCT_VEH
                                                                        @VNAME:   HEADModuleCommonOut */

typedef HEADMTSData_t              PDO_HEADMTSData_t;              /*!< @VADDR:   FCT_MEAS_ID_CGEB_HEAD_DATA
                                                                        @CYCLEID: FCT_VEH
                                                                        @VNAME:   HEAD */

typedef HEADMTSConditionsOKTimer_t PDO_HEADMTSConditionsOKTimer_t; /*!< @VADDR:   FCT_MEAS_ID_CGEB_HEAD_COND_TIMER_DATA
                                                                        @CYCLEID: FCT_VEH
                                                                        @VNAME:   HEADConditionTimerData */

#endif // MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

#if (USE_MEDICWRAPPER_INTERMEAS)
typedef MEDIC_DataWrapperInterMeas_t PDO_MEDIC_DataWrapperInterMeas_t ;   /*!< @VADDR:   GA_MEDIC_MEAS_ID_INTER_CYCLE_MEAS_DATA
                                                                               @CYCLEID: FCT_VEH
                                                                               @VNAME:   MEDIC_InterCycleDataMeas */
#endif

#if (USE_MEDICWRAPPER_INTRAMEAS)
typedef MEDIC_DataWrapperIntraMeas_t PDO_MEDIC_DataWrapperIntraMeas_t ;   /*!< @VADDR:   GA_MEDIC_MEAS_ID_INTRA_CYCLE_MEAS_DATA
                                                                               @CYCLEID: FCT_VEH
                                                                               @VNAME:   MEDIC_IntraCycleDataMeas */
#endif

#ifdef MEDIC_SIMU
#if (USE_MEDICWRAPPER_INTER)
typedef MEDIC_DataWrapperInter_t     PDO_MEDIC_DataWrapperInter_t ;       /*!< @VADDR:   GA_MEDIC_MEAS_ID_INTER_CYCLE_DATA
                                                                               @CYCLEID: FCT_VEH
                                                                               @VNAME:   MEDIC_InterCycleData */
#endif

typedef MEDIC_DataWrapperStack_t      PDO_MEDIC_DataWrapperStack_t    ;   /*!< @VADDR:   GA_MEDIC_MEAS_ID_STACK
                                                                               @CYCLEID: FCT_VEH
                                                                               @VNAME:   MEDIC_StackData */

#endif /* MEDIC_SIMU */
#endif /* MEDIC_CFG_EMERGENCY_BRAKE_ASSIST */
#endif /* MEDIC_ARCHITECTURE_VERSION < 0x10 */
#endif /* __PDO__ */


/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}

