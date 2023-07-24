/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE

MODULNAME:                 slate_meas.c

DESCRIPTION:               This module manages the measurement output of SLATE.

AUTHOR:                    $Author: uib05783 $

CREATION DATE:             15.02.2017

VERSION:                   $Revision: 1.23 $

---*/ /*---

**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */


#include "slate.h" /*  PRQA S 0380 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Doesnot have any effect on functionality  */
#if (FCT_CFG_SLATE_COMPONENT)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         slate_meas Measurement
@ingroup          frame
@brief            This module manages the measurement output of the SLATE component.\n\n
@description      The following functionalities are provided by this module:
                  - Freezing of all In- and Output interfaces: @ref FCTSen_v_ACCProcessMeasFreeze
@{
*/

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! @cond Doxygen_Suppress */
/* Freeze job uses application buffer  -> referenced data has to be kept global or static */
/* <ln_offset:+1 MISRA Rule 19.7: reviewer name: Ungvary date: 24-09-2012 reason: function-like macro reduces pre-processor branching in code */
//#define MEAS_FREEZE_ACC_BUFFERED(VADDR_,ADDR_,SIZE_) /*lint -e{717} */ do  { 
//  MEASInfo_t desc; 
//  desc.VirtualAddress = (VADDR_);                 
//  desc.Length         = (SIZE_);                  
//  desc.FuncID         = FCT_ACC_MEAS_FUNC_ID;       
//  desc.FuncChannelID  = FCT_ACC_MEAS_FUNC_CHAN_ID;  
//  (void) FCT_ACC_FREEZE_DATA(&desc,(void *)(ADDR_),&FCTSen_v_ACCMeasCallback); 
//} while(0) /* (no trailing ; ) */
// MEAS_FREEZE_ACC_BUFFERED shall be replaced by Meas_Freeze_Slate_Glob_Var Shang 27.01.2017

#if (FCT_SEN_CFG_FREEZE_CTRL_DATA)
#ifndef FCT_MEAS_ID_SEN_ACC_CTRL_DATA
#define FCT_MEAS_ID_SEN_ACC_CTRL_DATA       FCT_MEAS_ID_SEN_CTRL_DATA
#endif
#endif

#if (FCT_CFG_COURSE_PREDICTION)
#ifndef FCT_ACC_MEAS_ID_TRAJECTORIES
#define FCT_ACC_MEAS_ID_TRAJECTORIES (0x20240050u)//FCT_MEAS_ID_TRAJECTORIES	539230208U // 0x20240000u
#endif
#endif


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#if (FCT_MEASUREMENT)

//#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
//SET_MEMSEC_VAR(t_NaviDebugMeasFreeze)
//static NaviDebugInfo_t t_NaviDebugMeasFreeze;       /*!< Navi debug freeze data */// PRQA S 3218
/* date: 2015-06-17, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
//#endif



/****************   Buffers for MeasFreezes *******************/
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
/*input ports*/


/*output ports*/
//#if (FCT_CFG_USE_BUS_DEBUG) // to be removed (not active in VACC)
//SET_MEMSEC_VAR(FCTSen_FreezeBufferBusDebugData)
//  static BusDebugData_t FCTSen_FreezeBufferBusDebugData; /*!< BusDebugData_t freeze data */
//#endif /* FCT_CFG_USE_BUS_DEBUG */
#if (FCT_SEN_CFG_FREEZE_CTRL_DATA) // to be freezed for ACC/HC
SET_MEMSEC_VAR(FCTSen_ACCFreezeBufferSenCtrlData)
static FCTCtrlData_t FCTSen_ACCFreezeBufferSenCtrlData;
#endif

#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
#endif  /* #if (FCT_MEASUREMENT) */


/*****************************************************************************
  VARIABLES
*****************************************************************************/
/****************   Buffers for MeasFreezes *******************/
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
/*input ports*/

/*output ports*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(FCTSen_ACCFreezeBufferSenCompState)
static AlgoCompState_t FCTSen_ACCFreezeBufferSenCompState;
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
/****************   Eof Buffers for MeasFreezes *******************/
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/*! freeze function for FCT-output data (delayed ego signals) */
//static void FCTMeasFreezeFCTOutput (void);  // to be split up after output split up (ACC-SPM)

#if (FCT_MEASUREMENT)
static void FCTSenACCFreezeInput(void);
#endif

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
static void FCT_v_MeasFreezeNaviData (void);
#endif
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Not safety critical.  
 * date: 2020-02-26, reviewer: Dhamodahran Subramanian, reason: Added 3447 - Not safety critical. */
/* PRQA S 3449, 3451, 3447 1*/
void FCTSen_v_ACCMeasCallback(void); // remove a static Shang 27.01.2017  

/*! @endcond Doxygen_Suppress */
/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if ((SLATE_CFG_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING))
/*************************************************************************************************************************
  Functionname:    FCT_v_MeasFreezeNaviData                                                                         */ /*!

  @brief           Freeze navi data (FIP, SI, CP)

  @description     Freeze navi data Related to FIP, SI and CP.

  @return          -

  @param[in]       -

  @glob_in         -

  @glob_out        t_NaviDebugMeasFreeze.FIP.b_ValidNaviData : Valid Navi data of Navi debug information to be freezed in the device                                [TRUE, FALSE]
  @glob_out        t_NaviDebugMeasFreeze.FIP.b_NaviPathPlausible :Plausible navi path of Navi debug information to be freezed in the device                         [TRUE, FALSE]
  @glob_out        t_NaviDebugMeasFreeze.FIP.b_ValidNaviNumberLanes : Valid navi number of Navi debug information to be freezed in the device                       [TRUE, FALSE]
  @glob_out        t_NaviDebugMeasFreeze.CP.b_NaviFusionExternalSwitch : Navi fusion external switch of CP debug information to be freezed in the device            [TRUE, FALSE]
  @glob_out        t_NaviDebugMeasFreeze.CP.b_IsLaneChangeFusion : Is lane change fusion of CP debug information to be freezed in the device                        [TRUE, FALSE]
  @glob_out        t_NaviDebugMeasFreeze.CP.b_ValidPathLengthFusion : Is valid path lengh fusion of CP debug information to be freezed in the device                [TRUE, FALSE]
  @glob_out        t_NaviDebugMeasFreeze.CP.b_ValidSpeedRangeFusion : Is valid speed range fusion of CP debug information to be freezed in the device               [TRUE, FALSE]
  @glob_out        t_NaviDebugMeasFreeze.SI.b_NaviCountryExternalSwitch : Is country external switch of SI debug information to be freezed in the device            [TRUE, FALSE]
  @glob_out        t_NaviDebugMeasFreeze.FIP : FIP related Navi debug information to be freezed in the device of type FIP_NaviDebugMeasInfo_t as defined in fct_sen.h
  @glob_out        t_NaviDebugMeasFreeze.CP : CP related Navi debug information to be freezed in the device of type CP_NaviDebugMeasInfo_t as defined in fct_sen.h
  @glob_out        t_NaviDebugMeasFreeze.SI : SI related Navi debug information to be freezed in the device of type SI_NaviDebugMeasInfo_t as defined in fct_sen.h

  @c_switch_part   FCT_CFG_SLATE_COMPONENT : FCT support for ACC object selection
  
  @c_switch_full   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN as defined in fct_config.h
  @c_switch_full   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP): Need to be switched on for ACC as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/11/2016

  @author          Norman Apel | Norman.Apel@continental-corporation.com | 
*************************************************************************************************************************/
//static void FCT_v_MeasFreezeNaviData(void)
//{
//  /*! Initialize data */
//  t_NaviDebugMeasFreeze.FIP.b_ValidNaviData = FALSE;
//  t_NaviDebugMeasFreeze.FIP.b_NaviPathPlausible = FALSE;
//  t_NaviDebugMeasFreeze.FIP.b_ValidNaviNumberLanes = FALSE;
//  t_NaviDebugMeasFreeze.CP.b_NaviFusionExternalSwitch = FALSE;
//  t_NaviDebugMeasFreeze.CP.b_IsLaneChangeFusion = FALSE;
//  t_NaviDebugMeasFreeze.CP.b_ValidPathLengthFusion = FALSE;
//  t_NaviDebugMeasFreeze.CP.b_ValidSpeedRangeFusion = FALSE;
//  t_NaviDebugMeasFreeze.SI.b_NaviCountryExternalSwitch = FALSE;
//
//  /*! Get FIP specific information */
//  FIP_v_NaviSetMeasData(&t_NaviDebugMeasFreeze.FIP);
//  /*! Get CP specific information */
//  CP_v_NaviSetMeasData(&t_NaviDebugMeasFreeze.CP);
//  /*! Get Si specific information */
//#if (FCT_CFG_SLATE_COMPONENT)
//  SI_v_NaviSetMeasData(&t_NaviDebugMeasFreeze.SI);
//#endif
//  /*! Freeze data */
//  MEAS_FREEZE_BUFFERED(FCT_MEAS_ID_NAVI_DEBUG, &t_NaviDebugMeasFreeze, sizeof(t_NaviDebugMeasFreeze));
//}
#endif

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    FCTSenACCFreezeInput                                                                                */ /*!

  @brief           Freeze Sensor Input

  @description     Freeze Sensor Input
                   @startuml
                 	Start
                 		Partition FCTSenACCFreezeInput
                           - Copy FCT control data to FCT Sensor ACC Freeze Buffer Sensorn Control Data
                 		-Freeze FCT Sensor ACC Freeze Buffer Sensorn Control Data
                 
                 
                 	end
                  @enduml


  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_SEN_CFG_FREEZE_CTRL_DATA : Switch to Freeze FCTSenCtrlData from ECU code as defined in fct_config.h
  @c_switch_part   FCT_SEN_CFG_FREEZE_USE_CALLBACK : Use this functionality if output pointers are non constant (ringbuffer IPC) as defined in fct_config.h
  
  @c_switch_full   FCT_MEASUREMENT: Activate Measurement Output Code as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/11/2016

  @author          Clemens Schnurr | Clemens.Schnurr@continental-corporation.com | 
*************************************************************************************************************************/
static void FCTSenACCFreezeInput(void) 
{
//#if (FCT_SEN_CFG_FREEZE_CTRL_DATA)
//  static const MEASInfo_t FCT_SenACCCtrlMeasInfo = {           
//      FCT_MEAS_ID_SEN_ACC_CTRL_DATA,   /* VirtualAddress */
//      sizeof(FCTCtrlData_t),        /* Length */
//      FCT_ACC_MEAS_FUNC_ID,             /* FuncID */
//      FCT_ACC_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
//  };
//#endif

#if (FCT_SEN_CFG_FREEZE_CTRL_DATA)
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  (void)memcpy(&FCTSen_ACCFreezeBufferSenCtrlData,pSLATE_SenCtrlData,sizeof(FCTCtrlData_t));
  (void)Meas_Freeze_Slate_Glob_Var(FCT_MEAS_ID_SEN_ACC_CTRL_DATA, &FCTSen_ACCFreezeBufferSenCtrlData, sizeof(FCTCtrlData_t));
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
  (void)Meas_Freeze_Stack_Var(FCT_MEAS_ID_SEN_ACC_CTRL_DATA, pSLATE_SenCtrlData, sizeof(FCTCtrlData_t));
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
#endif /*FCT_SEN_CFG_FREEZE_CTRL_DATA*/
}
#endif


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    FCTSen_v_ACCFrameFreeze                                                                                */ /*!

  @brief           Freezes Frame Measurement Data (SW versions)

  @description     Freezes Frame Measurement Data (SW versions)
                   @startuml
	               Start
	               	Partition FCTSen_v_ACCFrameFreeze
	               	-Freeze FCT sensor ACC Frame Data and FCT sensor ACC Input Signal headers
                             If(FCT Sensor Algorithm Component State is not NULL) then (True)
                                -Copy FCT Sensor Algorithm Component State to FCT Sensor ACC Freeze Buffer Sensor Component State
                                 - Freeze Sensor Algorithm Component State
	               	   endif
	               end
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         pSLATE_BswAlgoParameters : Pointer to data type BSW_s_AlgoParameters_t as defined in fct_sen_main.c
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
void FCTSen_v_ACCFrameFreeze(void)
{

#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
  (void)Meas_Freeze_Slate_Glob_Var(FCT_MEAS_ID_SEN_ACC_FRAME_DATA, &t_SLATEFrame, sizeof(SLATEFrame_t));
  (void)Meas_Freeze_Slate_Glob_Var(FCT_MEAS_ID_SEN_ACC_INPUT_SIGHEADERS, &t_SLATESyncRef, sizeof(SLATESyncRef_t));
#else /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/
  (void)Meas_Freeze_Stack_Var(FCT_MEAS_ID_SEN_ACC_FRAME_DATA, &t_SLATEFrame, sizeof(SLATEFrame_t));/*  PRQA S 0315 */
  (void)Meas_Freeze_Stack_Var(FCT_MEAS_ID_SEN_ACC_INPUT_SIGHEADERS, &t_SLATESyncRef, sizeof(SLATESyncRef_t));/*  PRQA S 0315 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Its safe to convert a pointer-to-object to a pointer-to-void  */
#endif /*FCT_SEN_CFG_FREEZE_USE_CALLBACK*/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  if (pSLATE_SenCompState != NULL)
  {
#if (FCT_SEN_CFG_FREEZE_USE_CALLBACK)
    (void)memcpy(&FCTSen_ACCFreezeBufferSenCompState, pSLATE_SenCompState, sizeof(AlgoCompState_t));
    (void)Meas_Freeze_Slate_Glob_Var(FCT_MEAS_ID_SEN_ACC_COMP_STATE, &FCTSen_ACCFreezeBufferSenCompState, sizeof(AlgoCompState_t));
#else
    /* Freeze Sensor Algo Comp State (internal storage -> no need for buffering*/
    (void)Meas_Freeze_Slate_Glob_Var(FCT_MEAS_ID_SEN_ACC_COMP_STATE, (void*) pSLATE_SenCompState, sizeof(AlgoCompState_t));
#endif
  }
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/
}
#endif  /* #if FCT_MEASUREMENT */



/*************************************************************************************************************************
  Functionname:    FCTSen_v_ACCProcessMeasFreeze                                                                          */ /*!

  @brief           Freeze FCT measurement data

  @description     Freeze FCT measurement data
                   @startuml
                   Start
                   	Partition FCTSen_v_ACCProcessMeasFreeze
                   	Partition FCTSenACCFreezeInput{
                   
                         - Freeze Sensor Input
                         
                   
                      }
                       Repeat
                        If (provide port is not Empty and the port is not freezed)then(True)
                            -Freeze the provide port
                        endif
                   
                       Repeat while (for all Ports stored in the provide port handler list)  
                   
                   
                   end
                   @enduml

  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_MEASUREMENT : Activate Measurement Output Code as defined in fct_config.h

  @c_switch_full   FCT_CFG_SLATE_COMPONENT : FCT support for ACC object selection as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/02/2018

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSen_v_ACCProcessMeasFreeze(void)
{
  SLATEPortHandlerList_t * pSLATE_PortHandlerList = &t_SLATEPortHandlerList;
  uint8 u_PortNo;

  /*******************/
  /* INPUT-Port-Data */
  /*******************/
#if (FCT_MEASUREMENT)
  FCTSenACCFreezeInput();/* PRQA S 2987 */  
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:not safety critical */
#endif

  /**********************/
  /* OUTPUT PORT-Data   */
  /**********************/

  for (u_PortNo = 0u; u_PortNo < pSLATE_PortHandlerList->uNofProPorts; u_PortNo++)
  {
    SLATEProPortHandler_t * pCurrPort = &(pSLATE_PortHandlerList->ProPortHandler[u_PortNo]);
    if  ( (pCurrPort->pGlobal            != NULL) /* PRQA S 3004 */ /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Implict conversion is safe here.  */
       && (pCurrPort->uMeasFreezeAddress != 0   ) )/* PRQA S 1843 */
   /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Implict conversion is safe here.  */
    {
      Meas_Freeze_Stack_Var(pCurrPort->uMeasFreezeAddress, *(pCurrPort->pGlobal), pCurrPort->uSize);
    }
  }
}

/*************************************************************************************************************************
  Functionname:    FCTSen_v_ACCMeasCallback                                                                               */ /*!

  @brief           FCT MEAS callback function

  @description     Callback function as requested by MEASFreezeData. Right now this is dummy function.
                   @startuml
                   Start
                   Partition FCTSen_v_ACCMeasCallback
                   - callback function as requested by MEASFreezeData. Right now this is dummy function
                   
                   end
                   @enduml


  @return          -

  @param[in]       -

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/15/2016

  @author          Jochen Spruck | Jochen.Spruck@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSen_v_ACCMeasCallback(void)
{
  /*! Callback function is a dummy */
  return;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
/// @}
#endif /* (FCT_CFG_SLATE_COMPONENT) */

