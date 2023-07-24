/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC (Adaptive Cruise Control - Interface and State Coordinator)

PACKAGENAME:               isc.h

DESCRIPTION:               Internal header for ISC in FCTVEH Task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.12 $

---*/ /*---
CHANGES:                    $Log: isc.h  $
CHANGES:                    Revision 1.12 2018/06/21 16:09:48CEST uidj5069 
CHANGES:                    Meas ID redefined
CHANGES:                    Revision 1.11 2018/06/21 08:40:38CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Additional Component Ports measured
CHANGES:                    Revision 1.10 2018/06/18 16:56:19CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Virtual MEAS Address updated
CHANGES:                    Revision 1.9 2018/06/05 11:05:37CEST Schnellbach, Hans-Juergen (uidg5946) 
CHANGES:                    Improvement of the handling of the rtaConfigurationFiles (xml)
CHANGES:                    Revision 1.8 2018/04/05 15:05:16CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Freezing of ISC Ports added
CHANGES:                    Revision 1.7 2018/03/14 09:55:25CET Mistry, Niraj (uidq5738) 
CHANGES:                    Simplified cdl check (similar to EM implementation)
CHANGES:                    Revision 1.6 2018/02/26 12:00:56CET Mistry, Niraj (uidq5738) 
CHANGES:                    PDO tags moved to new file
CHANGES:                    Revision 1.5 2018/02/23 16:33:53CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Meas freeze of new output ports added
CHANGES:                    Revision 1.4 2017/10/20 14:20:33CEST Mistry, Niraj (uidq5738) 
CHANGES:                    Include isc_ver.h
CHANGES:                    Revision 1.3 2017/10/06 15:29:59CEST Mistry, Niraj (uidq5738) 
CHANGES:                    ACT Gen 4 Frame setup
CHANGES:                    Revision 1.2 2017/10/05 08:32:32CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial Revision for ACC GEN 4
CHANGES:                    Revision 1.1 2017/03/10 10:48:14CET Koschalka, Mike (uidg3250) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOKMC_LongitudinalKinematicMotionControl/04_Engineering/01_Source_Code/LOKMC/frame_lokmc/project.pj
CHANGES:                    Derived from Version 1.9.1.3 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lokmc/project.pj
**************************************************************************** */

#ifndef ISC_H_INCLUDED
#define ISC_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_veh.h"
#include "isc_cfg.h"
#include "isc_types.h"
#include "isc_ver.h"

/* Only process rest of file if ACC enabled and long control enabled */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))


#ifdef __cplusplus
extern "C" {
#endif

#include "cal_ext.h"
#include "sm_ext.h"
#include "sm_access_func.h"
#include "hmi_ext.h"
#include "hmi_access_func.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef FCT_MEAS_ID_ISC_FRAME_DATA
#define FCT_MEAS_ID_ISC_FRAME_DATA        (0x20274460u)  
#endif

#ifndef FCT_MEAS_ID_ISC_INPUT_SIGHEADERS
#define FCT_MEAS_ID_ISC_INPUT_SIGHEADERS  (0x202745B0u) 
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
#ifndef FCT_MEAS_ID_ISC_COMP_STATE
#define FCT_MEAS_ID_ISC_COMP_STATE        (0x20274600u) 
#endif
#endif

#ifndef FCT_MEAS_ID_ISC_IN_IIP
#define FCT_MEAS_ID_ISC_IN_IIP            (0x20021000u)
#endif

#ifndef FCT_MEAS_ID_ISC_IN_ICP
#define FCT_MEAS_ID_ISC_IN_ICP            (0x20021020u)
#endif

#ifndef FCT_MEAS_ID_ISC_OUT_ISP
#define FCT_MEAS_ID_ISC_OUT_ISP           (0x20021040u)
#endif

#ifndef FCT_MEAS_ID_ISC_IN_CCSP
#define FCT_MEAS_ID_ISC_IN_CCSP           (0x20021068u)
#endif

#ifndef FCT_MEAS_ID_ISC_OUT_CCCP
#define FCT_MEAS_ID_ISC_OUT_CCCP          (0x20021088u)
#endif

#ifndef FCT_MEAS_ID_ISC_IN_LVSP
#define FCT_MEAS_ID_ISC_IN_LVSP           (0x200210A8u)
#endif

#ifndef FCT_MEAS_ID_ISC_OUT_LVCP
#define FCT_MEAS_ID_ISC_OUT_LVCP          (0x200210C8u)
#endif

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
typedef enum
{
  ISC_INIT,     /*!< initialize all    */
  ISC_RUN,      /*!< normal processing */
  ISC_SHUTDOWN  /*!< shutdown (system failure) */
}
ISCState_t;

/*! FCT sub-component version stucture */
typedef struct 
{

  FCTSwVersion_t  FCT_ISC_VERSION_AS_TEXT;
  FCTSwVersion_t  uiIsc;                 /*!< SW verion of FCTVeh*/
}
ISCVersions_t;


typedef struct
{
  AlgoCycleCounter_t    uiCycleCounter;   /*!< The FCT_VEH cycle counter */
  boolean               bFirstCycleDone;  /*!< Boolean flag used for first cycle check */
  FCT_OP_MODE_t         eISCOpMode;       /*!< FCT operation mode */
  ISCState_t            eISCState;        /*!< FCT current operation mode */
  ISCVersions_t         Versions;         /*!< FCT versions */
}
ISCFrame_t;
  
  /*!< aggregation struct of all input port data update information*/
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
  typedef struct
  {
    sMeasCycleMonitor sVehCtrlData;       /*!< Vehicle Control Data input */
    sMeasCycleMonitor sEgoDynRaw;         /*!< EgoDynRaw*/
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    sMeasCycleMonitor sVehSig;
#endif
#if ((CFG_ACC_LEVER_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    sMeasCycleMonitor sAccLeverInput;
#endif
    sMeasCycleMonitor sLongCtrlInput;
#if ((FCT_CFG_ACC_HEADWAY_PLANNER) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    sMeasCycleMonitor sAcc_object;
    sMeasCycleMonitor sAcc_output_data;
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    sMeasCycleMonitor sFCTSenAccOOI;
#endif
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
    sMeasCycleMonitor sFctVehCustInput;   /*!< Custom input for FCT_VEH */
#endif
  } Isc_InputMeasCounter;
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if (FCT_CFG_RTA_PROFILING)// PRQA S 3332
  /* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose*/
  /*!enumeration of RunTimeAssessment events.*/
  typedef enum {
    ISC_RTA_PROCESS            = 0,                  /*!<whole procedure runtime*/
    ISC_RTA_PREPRE_PROCESS     = 1,                  /*!<data preparation runtime*/
    ISC_RTA_LC_PROCESS         = 2,                  /*!<Longitudinal control runtime*/
    ISC_RTA_PROCESSFREEZE      = 3,                  /*!<Process Measfreeze runtime*/
    ISC_RTA_FRAMEFREEZE        = 4,                  /*!<Frame Measfreeze runtime*/
    ISC_RTA_LAST_ENTRY         = 5                   /*!<max enum*/
  } ISC_t_RtaMapping; /* RTA_LOCAL_ID_FOR_XML_GENERATION */
#endif

/*****************************************************************************
  VARIABLES
*****************************************************************************/
  extern MEMSEC_REF boolean b_IscIsInitialized;

/*! sub-module state */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  extern MEMSEC_REF       AlgoCompState_t                 *FCTVEH_pACCCompState;
#endif 

  /*! FCT_VEH ISC frame (cycle time, cycle counter, opmode ...) */
  extern MEMSEC_REF ISCFrame_t                            ISCFrame;
  extern MEMSEC_REF ISC_SyncRef_t                         ISC_SyncRef;

  extern MEMSEC_REF const ACT_ISC_InformationPort_t       *pt_ISC_IN_IIP;
  extern MEMSEC_REF const ACT_ISC_CommandPort_t           *pt_ISC_IN_ICP;
  extern MEMSEC_REF       ACT_ISC_StatusPort_t            *pt_ISC_OUT_ISP;

#if (FCT_CFG_LOCC_COMPONENT)
  extern MEMSEC_REF const ACT_CruiseControlStatePort_t    *pt_ISC_IN_CCSP;
  extern MEMSEC_REF       ACT_CruiseControlCommandPort_t  *pt_ISC_OUT_CCCP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  extern MEMSEC_REF const TargetControlStatePort_t        *pt_ISC_IN_TCSP;
  extern MEMSEC_REF       TargetControlCommandPort_t      *pt_ISC_OUT_TCCP;
#endif

  extern MEMSEC_REF const ACT_LogicVehicleStatePort_t     *pt_ISC_IN_LVSP;
  extern MEMSEC_REF       ACT_LogicVehicleCommandPort_t   *pt_ISC_OUT_LVCP;

/*****************************************************************************
  FUNCTION
*****************************************************************************/

  /*--- isc_algocontrol.c ---*/
extern void ISC_v_ProcessStates (FCT_OP_MODE_t eOpMode);
extern void ISC_v_SignalErrorShutdown(const boolean isRecoveryPossible);

  /*--- isc_main.c ---*/
extern void ISC_v_SetOperationMode(const ISCState_t t_ISCOpModeValue);

  /*--- isc_meas.c ---*/
#if (FCT_MEASUREMENT)
extern void ISC_v_FrameFreeze(void);
extern void ISC_v_ProcessMeasFreeze();
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose*/
extern void IscAlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
#endif

ALGO_INLINE void ISC_v_MeasCallback(void);
ALGO_INLINE void ISC_v_MeasCallback(void)
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

  @author           Florian Foelster

**************************************************************************** */
ALGO_INLINE void MeasFreeze_Isc_GlobVar(uint32 VADDR_,  void * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_Isc_GlobVar(uint32 VADDR_,  void * ADDR_, uint32 SIZE_)
{

  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = TASK_ID_ALGO_VEH_CYCLE;
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  (pFCTVehServiceFuncts->pfMeasFreeze)(&desc, ADDR_, &ISC_v_MeasCallback);
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, &ISC_v_MeasCallback);
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

  @author           Florian Foelster

**************************************************************************** */
ALGO_INLINE void MeasFreeze_Isc_StackVar(uint32 VADDR_, void * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_Isc_StackVar(uint32 VADDR_, void * ADDR_, uint32 SIZE_)
{
  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = TASK_ID_ALGO_VEH_CYCLE;
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  (pFCTVehServiceFuncts->pfMeasFreeze)(&desc, ADDR_, NULL);
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, NULL);
#endif
}


#ifdef __cplusplus
};
#endif

#include "isc_access_func.h"

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL && FCT_CFG_ISC_COMPONENT) */

#endif

