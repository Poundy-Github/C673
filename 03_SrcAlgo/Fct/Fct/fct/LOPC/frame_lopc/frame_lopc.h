/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_lopc.h

DESCRIPTION:               Internal header for frame lopc

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 1.9.1.6
**************************************************************************** */

#ifndef FRAME_LOPC_H_INCLUDED
#define FRAME_LOPC_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lopc_h Frame_lopc_h
@ingroup    lopc_base_frame
@brief      Main internal header file for LOPC
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_lopc_access_func.h"

/* Only process rest of file if ACC enabled and long control enabled */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))


#ifdef __cplusplus
extern "C" {
#endif

#if (FCT_CFG_ACC_CAL)
#include "cal_ext.h"
#endif
#if (LOPC_CFG_KMC)
#include "kmc_inhibit_ext.h"
#if (FCT_CFG_CC)
#include "kmc_ext.h"
#endif
#if (FCT_CFG_TCI)
#include "tci_ext.h"
#endif
#endif
#if (LOPC_CFG_LOC)
#include "loc_ext.h"
#endif
#if (LOPC_CFG_LOP)
#include "lop_ext.h"
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  VARIABLES
*****************************************************************************/

#if (FCT_CFG_ACT_CODE_VERSION)

  extern MEMSEC_REF ACT_EgoVehicleCommandPort_t *pt_LOPC_OUT_EVCP;

#endif


/*****************************************************************************
  FUNCTION
*****************************************************************************/

  /*--- frame_lopc_algocontrol.c ---*/
void LOPC_v_ProcessStates (FCT_OP_MODE_t eOpMode);
extern void LOPC_v_SignalErrorShutdown(const boolean isRecoveryPossible);

  /*--- frame_lopc_main.c ---*/
void LOPC_v_SetOperationMode(const LOPCState_t t_LOPCOpModeValue);

  /*--- frame_lopc_meas.c ---*/
#if (FCT_MEASUREMENT)
extern void LOPC_v_FrameFreeze(void);
extern void LOPC_v_ProcessMeasFreeze(void);
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose*/
extern void LOPC_v_AlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
#endif

ALGO_INLINE void LOPC_v_MeasCallback(void);

/* ****************************************************************************

  Functionname:     LOHP_v_MeasCallback                                   */ /*!

  @brief            Dummy callback function

  @description      -

  @return           void

  @pre              None
  @post             No changes

  @traceability     doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-138-0008a220

  @author           -

**************************************************************************** */
ALGO_INLINE void LOPC_v_MeasCallback(void)
{
  /*! Callback function is a dummy */
  return;
}

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
  @traceability     doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-139-0008a220
  @author           Florian Foelster

**************************************************************************** */
ALGO_INLINE void MeasFreeze_Lopc_GlobVar(uint32 VADDR_,  void * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_Lopc_GlobVar(uint32 VADDR_,  void * ADDR_, uint32 SIZE_)
{

  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = LOPC_MEAS_FUNC_ID;
  desc.FuncChannelID  = LOPC_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  (pFCTVehServiceFuncts->pfMeasFreeze)(&desc, ADDR_, &LOPC_v_MeasCallback);
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, &LOPC_v_MeasCallback);
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
  @traceability     doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-140-0008a220
  @author           Florian Foelster

**************************************************************************** */
ALGO_INLINE void MeasFreeze_Lopc_StackVar(uint32 VADDR_, void * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_Lopc_StackVar(uint32 VADDR_, void * ADDR_, uint32 SIZE_)
{
  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = LOPC_MEAS_FUNC_ID;
  desc.FuncChannelID  = LOPC_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  (pFCTVehServiceFuncts->pfMeasFreeze)(&desc, ADDR_, NULL);
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, NULL);
#endif
}

#ifdef __cplusplus
};
#endif

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT) */

/** @} end defgroup */

#endif /* ifndef FRAME_LOPC_H_INCLUDED */

