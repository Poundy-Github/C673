/*! \file **********************************************************************
// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.5 $

---*/ /*---

**************************************************************************** */


/*****************************************************************************
  INCLUDE
*****************************************************************************/
#ifdef __PDO__
#include "spm_int.h"
#include "spm.h"
#include "spm_ext.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         spm_pdo   pdo tags for spm
@ingroup          frame
@brief            This module contains all tags for the PDO scan.\n\n
*/


/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
typedef SPMData_t                           PDO_SPMData_t;  /*!< @VADDR:FCT_MEAS_ID_SPM_DATA
                                                                 @CYCLEID: FCT_ENV
                                                                 @VNAME: SPMData */

typedef SPMBlockageParameters_t PDO_SPMBlockageParameters;  /*!< @VADDR:FCT_MEAS_ID_SPM_BLKPAR
                                                                 @CYCLEID: FCT_ENV
                                                                 @VNAME: SPMBlockageParameters */

typedef SPMObjectLoss_t               PDO_SPMObjectLoss_t;  /*!< @VADDR: FCT_MEAS_ID_OBJECTLOSS
                                                                 @CYCLEID: FCT_ENV
                                                                 @VNAME: SPMObjectLoss */

typedef FCTSen_SPMSyncRef_t        PDO_FCTSen_SPMSyncRef_t; /*!< @VADDR:FCT_MEAS_ID_SEN_SPM_INPUT_SIGHEADERS
                                                                 @CYCLEID: FCT_ENV
                                                                 @VNAME: SPMSyncRef*/

typedef FCTSenSPMFrame_t              PDO_FCTSenSPMFrame_t; /*!< @VADDR:FCT_MEAS_ID_SEN_SPM_FRAME_DATA
                                                                 @CYCLEID: FCT_ENV
                                                                 @VNAME:SPMFrameData */

#if(FCT_CFG_RUNTIME_MEAS)
typedef FCT_SPMRuntimeInfo_t      PDO_FCT_SPMRuntimeInfo_t; /*!<@VADDR:FCT_MEAS_ID_SPM_RUNTIME_DEBUG
                                                                @CYCLEID: FCT_ENV
                                                                @VNAME:SPMRuntimeInfo */
#endif

#if(FCT_CFG_USE_ALGOCOMPSTATE)
typedef AlgoCompState_t                PDO_AlgoCompState_t; /* @VADDR:FCT_MEAS_ID_SEN_SPM_COMP_STATE
                                                               @CYCLEID: FCT_ENV
                                                               @VNAME: SPMCompState
                                                            */
#endif

#if(FCT_CFG_ERROR_OUTPUT_SEN)
typedef SPMErrorOutProPort_t      PDO_SPMErrorOutProPort_t; /* @VADDR:SPM_MEAS_ID_ERROR_OUT_PORT
                                                               @CYCLEID: FCT_ENV
                                                               @VNAME: SPMErrorOut
                                                            */
#endif

#if(FCT_CFG_LOHP_COMPONENT)
typedef SPM_HC_Data_t                    PDO_SPM_HC_Data_t; /* @VADDR:SPM_MEAS_ID_HC_DATA_PORT
                                                               @CYCLEID: FCT_ENV
                                                               @VNAME: SPMHcData
                                                             */
#endif
#endif

#endif

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}
