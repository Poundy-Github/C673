/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp.h

DESCRIPTION:               Internal header file for LOHP frame functions

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.14 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

#ifndef _FRAME_LOHP_INCLUDED
#define _FRAME_LOHP_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lohp_h Frame_lohp_h
@ingroup    lohp_base_frame
@brief      Main internal header file for LOHP
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_sen.h"
#include "frame_lohp_access_func.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))

#ifdef __cplusplus
extern "C" {
#endif

#if (FCT_CFG_ACC_CAL)
#include "cal_ext.h"
#endif
#include "lohp_ext.h"

#if (LOHP_CFG_TC)
#include "tc_ext.h"
#include "tc_access_func.h"
#endif

#if ( LOHP_CFG_PRED )
#include "pred_ext.h"
#endif
/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/

  /*! The FCT-Sen FuncID used for meas-freezes */
#if (defined(ALGO_ARS400Sensor) || defined(ALGO_ARS500Sensor)) /* ARS4xx / ARS5xx case */
#if (defined(ALGO_ARS400Sensor) && (ALGO_ARS400Sensor))
#define FCT_HC_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
  /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
#define FCT_HC_MEAS_FUNC_CHAN_ID   60u
#elif (defined(ALGO_ARS500Sensor) && (ALGO_ARS500Sensor))
#define FCT_HC_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
  /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
#define FCT_HC_MEAS_FUNC_CHAN_ID   60u
#else /* SRR case */
#define FCT_HC_MEAS_FUNC_ID        COMP_ID_FCT60
  /*! The FCT-Sen FuncChannelID used for meas-freezes */
#define FCT_HC_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
#endif
#else /* camera case */
#define FCT_HC_MEAS_FUNC_ID        COMP_ID_FCT60
  /*! The FCT-Sen FuncChannelID used for meas-freezes */
#define FCT_HC_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
#define FCT_HC_FREEZE_DATA(pInfo, pData, Callback)        (LOHP_pServiceFuncts->pfMeasFreeze)((pInfo), (pData), (Callback))
#else
#define FCT_HC_FREEZE_DATA(pInfo, pData, Callback)         MEASFreezeDataMTS((pInfo), (pData), (Callback))
#endif

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/

#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

/*--- lohp_main.c ---*/
extern void LOHP_v_SetOperationMode(const LOHPState_t t_OpModeValue);

/*--- frame_lohp_algocontrol.c ---*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern void LOHP_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif
extern void LOHP_v_ProcessStates (FCT_OP_MODE_t eOpMode);
extern void LOHP_v_SignalErrorShutdown(const boolean isRecoveryPossible);

/*--- frame_lohp_io.c ---*/
//extern void FCTSen_v_ACCProcessInput(fTime_t fCycleTime, const VehDyn_t * pEgoDyn);
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
extern uint32 LOHP_v_CheckInputUpdate(const reqLOHPPrtList_t * pRequirePorts, FCTSenHC_InputMeasCounter_t *pFCTSenInputMeasTimeStamps, float32 fTargetCycleTime );
#endif

/*--- frame_lohp_meas.c ---*/
extern void LOHP_v_ProcessMeasFreeze(const LOHP_ProPortList_t * const pProvidePorts);
//extern void FCTSen_v_HCMeasCallback(void);
#if (FCT_MEASUREMENT)
extern void LOHP_v_FrameFreeze(void);
#endif

ALGO_INLINE void LOHP_v_MeasCallback(void);
ALGO_INLINE void LOHP_v_MeasCallback(void)
{
  /*! Callback function is a dummy */
  return;
}

#else   /* GEN 3 */

/*--- lohp_main.c ---*/
extern void LOHP_v_SetOperationMode(const LOHPState_t t_OpModeValue);

/*--- frame_lohp_algocontrol.c ---*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern void LOHP_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif
extern void LOHP_v_ProcessStates (FCT_OP_MODE_t eOpMode);
extern void LOHP_v_SignalErrorShutdown(const boolean isRecoveryPossible);

/*--- frame_lohp_io.c ---*/
//extern void FCTSen_v_ACCProcessInput(fTime_t fCycleTime, const VehDyn_t * pEgoDyn);
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
extern uint32 LOHP_v_CheckInputUpdate(const reqLOHPPrtList_t * pRequirePorts, FCTSenHC_InputMeasCounter_t *pFCTSenInputMeasTimeStamps, float32 fTargetCycleTime );
#endif

/*--- frame_lohp_meas.c ---*/
extern void LOHP_v_ProcessMeasFreeze(const LOHPProPort_t * const pProvidePorts);
//extern void FCTSen_v_HCMeasCallback(void);
#if (FCT_MEASUREMENT)
extern void LOHP_v_FrameFreeze(void);
#endif


/* ****************************************************************************

  Functionname:     LOHP_v_MeasCallback                                   */ /*!

  @brief            Dummy callback function

  @description      -

  @return           void

  @pre              None
  @post             No changes

  @traceability     doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-89-0008a201

  @author           -

**************************************************************************** */
ALGO_INLINE void LOHP_v_MeasCallback(void);
ALGO_INLINE void LOHP_v_MeasCallback(void)
{
  /*! Callback function is a dummy */
  return;
}

#endif /* FCT_CFG_ACT_CODE_VERSION */

/* ****************************************************************************

  Functionname:     MeasFreeze_GlobVar                                   */ /*!

  @brief            Freeze job uses application buffer  
                    -> referenced data has to be kept global or static

  @description      WARNING: this is the UNBUFFERED MEASFREEZE!!  
                    - to be renamed in future.
                    Populates descriptor of the data and address to freeze the data.
                    Throws error if freeze is not successful.

  @param[in]        VADDR_ : Virtual address to copy the data.
  @param[in]        ADDR_ : pointer of the data.
  @param[in]        SIZE_ : size of the data.

  @return           void

  @pre              None
  @post             No changes

  @traceability     doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-90-0008a201

  @author           Florian Foelster

**************************************************************************** */
ALGO_INLINE void MeasFreeze_Lohp_GlobVar(uint32 VADDR_,  void * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_Lohp_GlobVar(uint32 VADDR_,  void * ADDR_, uint32 SIZE_)
{

  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = TASK_ID_ALGO_SEN_CYCLE;
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  (LOHP_pServiceFuncts->pfMeasFreeze)(&desc, ADDR_, &LOHP_v_MeasCallback);
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, &LOHP_v_MeasCallback);
#endif
}
/* ****************************************************************************

  Functionname:     MeasFreeze_StackVar                                   */ /*!

  @brief            Freeze copies data immediately to internal buffer 
                    -> buffer sized is limited

  @description      WARNING: this is the BUFFERED MEASFREEZE!!
                    - to be renamed in future
                    Populates descriptor and freezes the data at given virtual 
                    address. 
                    TODO: If freeze is not successful, error should be thrown  and 
                    counter to detect measurement failures should be incremented

  @param[in]        VADDR_ : virtual address to which data will be copied.
  @param[in]        ADDR_ : pointer to the data
  @param[in]        SIZE_ : size of the data.

  @return           void
  
  @pre              None
  @post             No changes
  
  @traceability     doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-91-0008a201

  @author           Florian Foelster

**************************************************************************** */
ALGO_INLINE void MeasFreeze_Lohp_StackVar(uint32 VADDR_, void * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_Lohp_StackVar(uint32 VADDR_, void * ADDR_, uint32 SIZE_)
{
  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = TASK_ID_ALGO_SEN_CYCLE;
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  (LOHP_pServiceFuncts->pfMeasFreeze)(&desc, ADDR_, NULL);
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, NULL);
#endif
}

#ifdef __cplusplus
};
#endif

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

/** @} end defgroup */

/* End of conditional inclusion */
#endif  /*!< _FRAME_LOHP_INCLUDED */


