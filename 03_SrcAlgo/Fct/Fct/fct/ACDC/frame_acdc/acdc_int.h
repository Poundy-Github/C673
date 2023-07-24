/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification

PACKAGENAME:               acdc_int.h

DESCRIPTION:               header file for ACDC evaluation module 

AUTHOR:                    $Author: Annareddy, Praveen Kumar Reddy (uic32343) (uic32343) $

CREATION DATE:             $Date: 2020/11/10 05:03:41CET $

VERSION:                   $Revision: 1.40 $

**************************************************************************** */
#ifndef ACDC_INT_H_INCLUDED
#define ACDC_INT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_access_func.h"

#if(ACDC_CFG_FRAME)

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup frame
@{
*/

#if (ACDC_CFG_EMP)
#include "emp_ext.h"
#endif
#if (ACDC_CFG_CD)
#include "cd_ext.h"
#endif
#if (ACDC_CFG_ESPM)
#include "espm_ext.h"
#endif
#if (ACDC_CFG_AIP)
#include "aip_ext.h"
#endif

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
   Reason: Styleguide specifies this as best practice (R231, R238) and 
   ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
   Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
/**************/

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
  /* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */
#pragma PRQA_NO_SIDE_EFFECTS ACDC_e_GetSubCompState
#endif

/*****************************************************************************
  MACROS
*****************************************************************************/
#ifndef FCT_MEAS_ID_SEN_EBA_FRAME_DATA
#define FCT_MEAS_ID_SEN_EBA_FRAME_DATA  (0x20273900u)  
#endif
#ifndef FCT_MEAS_ID_SEN_EBA_INPUT_SIGHEADERS
#define FCT_MEAS_ID_SEN_EBA_INPUT_SIGHEADERS (0x20273C00u) 
#endif

/*! The FCT-Sen FuncID used for meas-freezes */
#if (defined(ALGO_ARS400Sensor) || defined(ALGO_ARS500Sensor)) /* ARS4xx / ARS5xx case */
#if (defined(ALGO_ARS400Sensor) && (ALGO_ARS400Sensor))
#define ACDC_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
  /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
#define ACDC_MEAS_FUNC_CHAN_ID   60u
#elif (defined(ALGO_ARS500Sensor) && (ALGO_ARS500Sensor))
#define ACDC_MEAS_FUNC_ID        TASK_ID_ALGO_SEN_CYCLE
  /*! The FCT-Sen FuncChannelID used for meas-freezes @todo: Clarify later */
#define ACDC_MEAS_FUNC_CHAN_ID   60u
#else /* SRR case */
#define ACDC_MEAS_FUNC_ID        COMP_ID_FCT60
  /*! The FCT-Sen FuncChannelID used for meas-freezes */
#define ACDC_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
#endif
#else /* camera case */
#define ACDC_MEAS_FUNC_ID        TASK_ID_FCT60
  /*! The FCT-Sen FuncChannelID used for meas-freezes */
#define ACDC_MEAS_FUNC_CHAN_ID   TASK_ID_FCT60
#endif

/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
 extern void ACDC_SERVICE_ADD_EVENT( const RTA_t_Events RtaEvtType,  const ACDC_t_RtaMapping u_IDRtaMapping, const uint8 u_OptData);
#else
 extern void ACDC_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType,  const ACDC_t_RtaMapping u_IDRtaMapping, const uint8 u_OptData);
#endif
#else
 extern void ACDC_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType,  const ACDC_t_RtaMapping u_IDRtaMapping, const uint8 u_OptData);
#endif


 /* --- acdc_algo_control.c ---*/
 extern ACDCCompState_t ACDC_e_GetWorstSubComponentState(ACDCSubCompIndices_t const SubCompIndices);
 extern ACDCCompState_t ACDC_e_GetSubCompState(ACDCSubCompIndices_t const SubCompIndex);
 extern void ACDC_v_SetSubComponentStates(ACDCSubCompIndices_t const SubCompIndices, ACDCCompState_t const CompState);

 extern void ACDC_v_InitFrameData(FCT_OP_MODE_t eOpMode);


/*--- fct_sen_eba_algocontrol.c ---*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern void ACDC_v_SetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif
extern void ACDC_v_SignalErrorShutdown(const boolean bIsRecoveryPossible);

/*--- acdc_io.c ---*/
extern void ACDC_v_ProcessPorts(  reqACDCPrtList_t const  * const pRequirePorts,
                                  provACDCPrtList_t       * const pProvidePorts,
                                  ACDCPortHandlerList_t   * const pPortHandlerList
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                               , AS_t_ServiceFuncts const * const pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                              , GenAlgoQualifiers_t       * const pErrorBuffer
#endif
  );

extern void ACDC_v_FillProPortHeaders(ACDCPortHandlerList_t * const pPortHandlerList);



/*--- acdc_meas.c ---*/
extern void ACDC_v_MeasCallback(void);
extern void MeasFreeze_GlobVar(uint32 VADDR_,  void const * ADDR_, uint32 SIZE_);
#if (FCT_MEASUREMENT)
extern void ACDC_v_FreezePorts(ACDCPortHandlerList_t const * const pACDC_PortHandlerList);
extern void ACDC_v_FreezeWorkingData(ACDC_Working_t const * const pWorkData);
extern void ACDC_v_FreezeDebugData(ACDC_Working_t const * const pWorkData);
#endif

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
    Reason: Styleguide specifies this as best practice (R231, R238) and 
    ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
    Review-ID: */
/* PRQA S 3406 ALGO_INLINES */
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

  @glob_in          @ref ACDC_p_GetServiceFunctionsList
  @glob_out         None

  @return           void
  
  @pre              None
  @post             No changes

  @author           Florian Foelster
**************************************************************************** */
ALGO_INLINE void MeasFreeze_StackVar(uint32 VADDR_, void const * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_StackVar(uint32 VADDR_, void const * ADDR_, uint32 SIZE_)
{
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  AS_t_ServiceFuncts const * const pServiceFuncts = ACDC_p_GetServiceFunctionsList();
#endif
  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = ACDC_MEAS_FUNC_ID;
  desc.FuncChannelID  = ACDC_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  if(pServiceFuncts!= NULL )
  {
    if(pServiceFuncts->pfMeasFreeze!=NULL)
    {
      /* PRQA S 311 1 */ /* Andreas Kramer: Cast is OK here, Ensures compatibility with freeze function */
      (pServiceFuncts->pfMeasFreeze)(&desc, (void*)ADDR_, NULL);
    }
  }
#else
  /* PRQA S 311 1 */ /* Andreas Kramer: Cast is OK here, Ensures compatibility with freeze function */
  (void)MEASFreezeDataMTS(&desc, (void*)ADDR_, NULL);
#endif
}

/* PRQA L:ALGO_INLINES */


#ifdef __cplusplus
};
#endif

///@}
#endif /*(ACDC_CFG_FRAME)*/

#endif /* ACDC_INT_H_INCLUDED */

