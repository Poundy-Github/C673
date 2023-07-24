/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_meas.c

DESCRIPTION:               This module manages the measurement output of FCT.

AUTHOR:                    Erik Poesch

CREATION DATE:             15.11.2006

VERSION:                   $Revision: 1.15 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */


/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "fct_sen.h"//PRQA S 0380 
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reviewer: Prabhu Sundaramurthy, reason: This does not effect the functionality*/
/**
@defgroup fct_meas Fct Meas
@ingroup frame_sen
@{
*/
 /* needed for memset*/
#ifndef __PDO__
 #include <string.h>
#endif /* #ifndef __PDO__ */

/*****************************************************************************
  MACROS
*****************************************************************************/
#if (FCT_MEASUREMENT)
#if (FCT_CFG_BSW_ALGO_PARAMS)
#ifndef FCTSEN_BSW_ALGOPARAMETERS_VADDR
#define FCTSEN_BSW_ALGOPARAMETERS_VADDR 0x20900100U
#endif
#endif
#endif
/*! @cond Doxygen_Suppress */
/* Freeze job uses application buffer  -> referenced data has to be kept global or static */
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Ungvary date: 24-09-2012 reason: function-like macro reduces pre-processor branching in code */
#define MEAS_FREEZE_BUFFERED(VADDR_,ADDR_,SIZE_) /*lint -e{717} */ do  { \
  MEASInfo_t desc; \
  desc.VirtualAddress = (VADDR_);                 \
  desc.Length         = (SIZE_);                  \
  desc.FuncID         = FCT_MEAS_FUNC_ID;       \
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;  \
  (void) FCT_FREEZE_DATA(&desc,(void *)(ADDR_),&FCTSenMeasCallback); \
} while(0) /* (no trailing ; ) */


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#if (FCT_MEASUREMENT)

/****************   Buffers for MeasFreezes *******************/
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
/*input ports*/

/*output ports*/
#if (FCT_SEN_CFG_FREEZE_CTRL_DATA)
SET_MEMSEC_VAR(FCTSen_FreezeBufferSenCtrlData)
  static FCTCtrlData_t FCTSen_FreezeBufferSenCtrlData;
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(FCTSen_FreezeBufferSenCompState)
static AlgoCompState_t FCTSen_FreezeBufferSenCompState;
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
/****************   Eof Buffers for MeasFreezes *******************/
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

#endif  /* #if (FCT_MEASUREMENT) */


/*****************************************************************************
  VARIABLES
*****************************************************************************/
/****************   Buffers for MeasFreezes *******************/


#if (FCT_CFG_BSW_ALGO_PARAMS)
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
/*! Debug information  */
static BSW_s_AlgoParameters_t  FCTSEN_BswAlgoParameters;// PRQA S 3218
/* date: 2015-06-17, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
#endif
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#if (FCT_MEASUREMENT)
static void FCTSenFreezeInput(void);
#endif

/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    FCTSenFreezeInput                                                                                */ /*!

  @brief           Freeze Sensor Input

  @description     Freeze Sensor Input

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_SEN_CFG_FREEZE_CTRL_DATA : Switch to Freeze FCTSenCtrlData from ECU code as defined in fct_config.h
  @c_switch_part   FCT_SEN_CFG_FREEZE_USE_CALLBACK : Use this functionality if output pointers are non constant (ringbuffer IPC) as defined in fct_config.h
  
  @c_switch_full   FCT_MEASUREMENT: Activate Measurement Output Code as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/11/2016

  @author          Clemens Schnurr | Clemens.Schnurr@continental-corporation.com | 
*************************************************************************************************************************/
static void FCTSenFreezeInput(void) 
{
#if (FCT_SEN_CFG_FREEZE_CTRL_DATA)
  static const MEASInfo_t FCT_SenCtrlMeasInfo = {           
      FCT_MEAS_ID_SEN_CTRL_DATA,   /* VirtualAddress */
      sizeof(FCTCtrlData_t),        /* Length */
      FCT_MEAS_FUNC_ID,             /* FuncID */
      FCT_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
#endif

#if (FCT_SEN_CFG_FREEZE_CTRL_DATA)
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  (void)memcpy(&FCTSen_FreezeBufferSenCtrlData,FCTSEN_pSenCtrlData,sizeof(FCTCtrlData_t));
  (void)FCT_FREEZE_DATA(&FCT_SenCtrlMeasInfo, &FCTSen_FreezeBufferSenCtrlData, &FCTSenMeasCallback);
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
  (void)FCT_FREEZE_DATA(&FCT_SenCtrlMeasInfo, FCTSEN_pSenCtrlData, NULL);
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
#endif /*FCT_SEN_CFG_FREEZE_CTRL_DATA*/
}
#endif




#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    FCTSenFrameFreeze                                                                                */ /*!

  @brief           Freezes Frame Measurement Data (SW versions)

  @description     Freezes Frame Measurement Data (SW versions)

  @return          -

  @param[in]       -

  @glob_in         FCTSEN_pBswAlgoParameters : Pointer to data type BSW_s_AlgoParameters_t as defined in fct_sen_main.c
  @glob_out        -

  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of algo parameters to the FCT
                          component. This should be enabled, if the SW environment provides this information as defined in fct_config.h
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface as defined in fct_config.h
  @c_switch_part   FCT_SEN_CFG_FREEZE_USE_CALLBACK : Use this functionality if output pointers are non constant (ringbuffer IPC) in fct_config.h

  @c_switch_full   FCT_MEASUREMENT : Activate Measurement Output Code as defined in fct_config.h

  @pre             The passed pFrame pointer filled, and the area pointed to remains static (i.e.: buffered meas freeze may be used)
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/14/2016

  @author          Jochen Spruck & Gergely Ungvary | Jochen.Spruck & Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSenFrameFreeze(void)
{
  static const MEASInfo_t FCT_SenFrameMeasInfo = {
      FCT_MEAS_ID_SEN_FRAME_DATA,   /* VirtualAddress */
      sizeof(FCTSenFrame_t),        /* Length */
      FCT_MEAS_FUNC_ID,             /* FuncID */
      FCT_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
  static const MEASInfo_t FCT_SenSyncRefMeasInfo = {
      FCT_MEAS_ID_SEN_INPUT_SIGHEADERS,   /* VirtualAddress */
      sizeof(FCTSen_SyncRef_t),        /* Length */
      FCT_MEAS_FUNC_ID,             /* FuncID */
      FCT_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
#if (FCT_CFG_BSW_ALGO_PARAMS)
  static const MEASInfo_t FCTSEN_BSW_ALGO_PARAM_MeasInfo = {
      FCTSEN_BSW_ALGOPARAMETERS_VADDR,   /* VirtualAddress */
      sizeof(BSW_s_AlgoParameters_t),        /* Length */
      FCT_MEAS_FUNC_ID,             /* FuncID */
      FCT_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  static const MEASInfo_t FCT_Sen_CompStateMeasInfo = {
    FCT_MEAS_ID_SEN_COMP_STATE,         /* VirtualAddress */
    sizeof(AlgoCompState_t),         /* Length */
    FCT_MEAS_FUNC_ID,                 /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID             /* FuncChannelID */
  };
#endif


#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  (void)FCT_FREEZE_DATA(&FCT_SenFrameMeasInfo, &FCTSenFrame, &FCTSenMeasCallback);
  (void)FCT_FREEZE_DATA(&FCT_SenSyncRefMeasInfo, &FCTSenSyncRef, &FCTSenMeasCallback);
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
  (void)FCT_FREEZE_DATA(&FCT_SenFrameMeasInfo, &FCTSenFrame, NULL);//PRQA S 0315 2
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Case to void intended as use of generic interface */
  (void)FCT_FREEZE_DATA(&FCT_SenSyncRefMeasInfo, &FCTSenSyncRef, NULL);
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

#if (FCT_CFG_BSW_ALGO_PARAMS)
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  /* debug freeze of Radar BSW ALGO Params*/
  if (FCTSEN_pBswAlgoParameters)
  {
    FCTSEN_BswAlgoParameters = *FCTSEN_pBswAlgoParameters;
  }
  else
  {
    (void)memset(&FCTSEN_BswAlgoParameters, 0, sizeof(BSW_s_AlgoParameters_t));
  }
   (void)FCT_FREEZE_DATA(&FCTSEN_BSW_ALGO_PARAM_MeasInfo, &FCTSEN_BswAlgoParameters,        &FCTSenMeasCallback);  
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
   (void)FCT_FREEZE_DATA(&FCTSEN_BSW_ALGO_PARAM_MeasInfo, (void*)FCTSEN_pBswAlgoParameters, NULL               );// PRQA S 311, 314
  /* date: 2018-03-26, reviewer: Ravi kiran Gurrala, reason: Not a safety critical */  
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  if (FCTSEN_pSenCompState != NULL)
  {
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
    (void)memcpy(&FCTSen_FreezeBufferSenCompState, FCTSEN_pSenCompState, sizeof(AlgoCompState_t));
    (void)FCT_FREEZE_DATA(&FCT_Sen_CompStateMeasInfo, &FCTSen_FreezeBufferSenCompState, &FCTSenMeasCallback);
#else
    /* Freeze Sensor Algo Comp State (internal storage -> no need for buffering*/
    (void)FCT_FREEZE_DATA(&FCT_Sen_CompStateMeasInfo, (void*) FCTSEN_pSenCompState, &FCTSenMeasCallback);
#endif
  }
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
}
#endif  /* #if FCT_MEASUREMENT */

/*************************************************************************************************************************
  Functionname:    FCTSenProcessMeasFreeze                                                                          */ /*!

  @brief           Freeze FCT measurement data

  @description     Freeze FCT measurement data

  @return          -

  @param[in]       pProvidePorts : Pointer to proFCTSenPrtList_t as defined in fct_sen_ext.h

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT : FCT config for sensor to vehicle ACC Object of interest Port as defined in Rte_SWCEmAdapt_Type.h
  @c_switch_part   FCT_CFG_USE_BUS_DEBUG : Configuration switch for enabling BusDebugMessages as defined in fct_config.h
  @c_switch_part   FCT_MEASUREMENT : Activate Measurement Output Code as defined in fct_config.h
  @c_switch_part   FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE : FCT CD sub-component custom output interface as defined in fct_config.h
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN : FCT error output from FCT_SEN as defined in fct_config.h
  @c_switch_part   FCT_CFG_COLLISION_DETECTION : FCT collision detection (CD) switch as defined in fct_config.h
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output as defined in fct_config.h
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP), Need to be switched on for ACC as defined in fct_config.h

  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/14/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSenProcessMeasFreeze(const proFCTSenPrtList_t * const pProvidePorts)
{
#if (FCT_CFG_ERROR_OUTPUT_SEN)
  SET_MEMSEC_CONST(FCT_SenErrorsMeasInfo)
  static const MEASInfo_t FCT_SenErrorsMeasInfo = {
    FCT_MEAS_ID_SEN_ERROR_OUT_VADDR,  /* VirtualAddress */
    sizeof(FCTSenErrorOut_t),         /* Length */
    FCT_MEAS_FUNC_ID,                 /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID             /* FuncChannelID */
  };
#endif /* #if (FCT_CFG_ERROR_OUTPUT_SEN) */

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
  static const MEASInfo_t FCTSenCustomOutputMeasInfo = {
    FCT_MEAS_ID_CUSTOM_OUTPUT,          /* Virtual Address */
    sizeof(FCTCustomOutput_t),          /* Length */
    FCT_MEAS_FUNC_ID,                   /* Func ID */
    FCT_MEAS_FUNC_CHAN_ID               /* Func Channel ID */
  };
#endif

#if (FCT_CFG_USE_BUS_DEBUG)
  static const MEASInfo_t FCT_Sen_BusDebugInfo = {
    FCT_MEAS_ID_SEN_BUS_DEBUG,         /* VirtualAddress */
    sizeof(BusDebugData_t),         /* Length */
    FCT_MEAS_FUNC_ID,                 /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID             /* FuncChannelID */
  };
#endif /*FCT_CFG_USE_BUS_DEBUG*/

  /*******************/
  /* INPUT-Port-Data */
  /*******************/
#if (FCT_MEASUREMENT)
  FCTSenFreezeInput();//PRQA S 2987
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Function call not redundant */
#endif

  /**********************/
  /* OUTPUT PORT-Data   */
  /**********************/
  /*! Freeze delayed input data of FCTOutput data */


#if (FCT_MEASUREMENT)

#if (FCT_CFG_ERROR_OUTPUT_SEN)
  (void)FCT_FREEZE_DATA(&FCT_SenErrorsMeasInfo, (void*)pProvidePorts->pErrorOut, NULL);// PRQA S  314
  /* date:2019-06-28, reviewer:Prabhu Sundaramurthy , reason: Cast to void is intended as to allow generic port handling */
#endif

#if (FCT_CFG_USE_BUS_DEBUG)
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
    (void)memcpy(&FCTSen_FreezeBufferBusDebugData, FCTSEN_pBusDebugData, sizeof(BusDebugData_t));
    (void)FCT_FREEZE_DATA(&FCT_Sen_BusDebugInfo, &FCTSen_FreezeBufferBusDebugData, &FCTSenMeasCallback);
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
    (void)FCT_FREEZE_DATA(&FCT_Sen_BusDebugInfo, FCTSEN_pBusDebugData, NULL);
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
#endif /*FCT_CFG_USE_BUS_DEBUG*/

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
	(void)FCT_FREEZE_DATA(&FCTSenCustomOutputMeasInfo, FCTSEN_pCustomOutput, NULL);  //PRQA S 0315
/* date: 2019-06-28, reviewer:Prabhu Sundaramurthy, reason:Cast to void intended as use of generic interface */
#endif

#endif /* #if (FCT_MEASUREMENT) */

#if (!FCT_MEASUREMENT)|| (!FCT_CFG_ERROR_OUTPUT_SEN)
  _PARAM_UNUSED(pProvidePorts); /* PRQA S 3112 */
#endif

}

/*************************************************************************************************************************
  Functionname:    FCTSenMeasCallback                                                                               */ /*!

  @brief           FCT MEAS callback function

  @description     Callback function as requested by MEASFreezeData. Right now this is dummy function.

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/15/2016

  @author          Jochen Spruck | Jochen.Spruck@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSenMeasCallback(void)
{
  /*! Callback function is a dummy */
  return;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* *///PRQA S 0861
