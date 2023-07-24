/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOCC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               frame_locc.h

DESCRIPTION:               Internal header for frame locc

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.9.1.6
**************************************************************************** */

#ifndef FRAME_LOCC_H_INCLUDED
#define FRAME_LOCC_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_veh.h"
#include "locc_cfg.h"
#include "frame_locc_ver.h"
#include "frame_locc_types.h"
/* Only process rest of file if ACC enabled and long control enabled */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT))


#ifdef __cplusplus
extern "C" {
#endif

#if (FCT_CFG_ACC_CAL)
#include "cal_ext.h"
#endif

#if (LOCC_CFG_CC)
#include "cc_ext.h"
#endif

//#include "locc_custom_types.h"

/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef FCT_MEAS_ID_LOCC_FRAME_DATA
#define FCT_MEAS_ID_LOCC_FRAME_DATA   (0x20274420)  
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
#ifndef FCT_MEAS_ID_LOCC_COMP_STATE
#define FCT_MEAS_ID_LOCC_COMP_STATE   (0x20274600) 
#endif
#endif

#ifndef FCT_MEAS_ID_LOCC_IN_VSSP
#define FCT_MEAS_ID_LOCC_IN_VSSP      (0x20021100u)
#endif

#ifndef FCT_MEAS_ID_LOCC_OUT_VSCP
#define FCT_MEAS_ID_LOCC_OUT_VSCP     (0x20021120u)
#endif

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
typedef enum {
  LOCC_INIT,     /*!< initialize all    */
  LOCC_RUN,      /*!< normal processing */
  LOCC_SHUTDOWN  /*!< shutdown (system failure) */
} LOCCState_t;

/*! FCT sub-component version stucture */
typedef struct 
{
  FCTSwVersion_t  FCT_LOCC_VERSION_AS_TEXT;
  FCTSwVersion_t  uiLocc;                 /*!< SW verion of FCTVeh*/
}
LOCCVersions_t;


typedef struct LOCCFrame_t
{
  AlgoCycleCounter_t  uiCycleCounter;   /*!< The FCT_VEH cycle counter */
  boolean             bFirstCycleDone;  /*!< Boolean flag used for first cycle check */
  FCT_OP_MODE_t       eLOCCOpMode;      /*!< FCT operation mode */
  LOCCState_t         eLOCCState;       /*!< FCT current operation mode */
  LOCCVersions_t      Versions;         /*!< FCT versions */
}
LOCCFrame_t;
  
  /*!< aggregation struct of all input port data update information*/
#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
  typedef struct
  {
    sMeasCycleMonitor sVehCtrlData;       /*!< Vehicle Control Data input */

  } Locc_InputMeasCounter;
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

#if (FCT_CFG_RTA_PROFILING)// PRQA S 3332
  /* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose*/
  /*!enumeration of RunTimeAssessment events.*/
  typedef enum {
    LOCC_RTA_PROCESS            = 0,                  /*!<whole procedure runtime*/
    LOCC_RTA_PREPRE_PROCESS     = 1,                  /*!<data preparation runtime*/
    LOCC_RTA_CC_PROCESS         = 2,                  /*!<Longitudinal control runtime*/
    LOCC_RTA_PROCESSFREEZE      = 3,                  /*!<Process Measfreeze runtime*/
    LOCC_RTA_FRAMEFREEZE        = 4,                  /*!<Frame Measfreeze runtime*/
    LOCC_RTA_LAST_ENTRY         = 5                   /*!<max enum*/
  } LOCC_t_RtaMapping; /* RTA_LOCAL_ID_FOR_XML_GENERATION */
#endif

/*****************************************************************************
  VARIABLES
*****************************************************************************/
  extern MEMSEC_REF boolean b_LoccIsInitialized;

  /*! FCT_VEH LOCC frame (cycle time, cycle counter, opmode ...) */
  extern MEMSEC_REF LOCCFrame_t LOCCFrame;

  extern MEMSEC_REF LOCC_SyncRef_t LOCC_SyncRef;

/*! Declaration of pointers to LOCC ports for access within this component */
#if (ACT_CFG_CC_VSC_PORT_CNT)
  extern MEMSEC_REF const ACT_CC_VehicleSpeedStatePort_t *pt_LOCC_IN_VSSP;
  extern MEMSEC_REF ACT_CC_VehicleSpeedCommandPort_t *pt_LOCC_OUT_VSCP;
#endif

/*****************************************************************************
  FUNCTION
*****************************************************************************/

  /*--- frame_locc_algocontrol.c ---*/
void LOCC_v_ProcessStates (FCT_OP_MODE_t eOpMode);
  extern void LOCC_v_SignalErrorShutdown(const boolean isRecoveryPossible);

  /*--- frame_locc_main.c ---*/
void LOCC_v_SetOperationMode(const LOCCState_t t_LOCCOpModeValue);

  /*--- frame_locc_meas.c ---*/
#if (FCT_MEASUREMENT)
  extern void LOCC_v_FrameFreeze(void);
  extern void LOCC_v_ProcessMeasFreeze();
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
  /* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Macro Defined Externally for simulation purpose*/
  extern void LOCC_v_AlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
#endif

ALGO_INLINE void LOCC_v_MeasCallback(void);
ALGO_INLINE void LOCC_v_MeasCallback(void)
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
ALGO_INLINE void MeasFreeze_Locc_GlobVar(uint32 VADDR_,  void * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_Locc_GlobVar(uint32 VADDR_,  void * ADDR_, uint32 SIZE_)
{

  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = TASK_ID_ALGO_VEH_CYCLE;
  desc.FuncChannelID  = FCT_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  (pFCTVehServiceFuncts->pfMeasFreeze)(&desc, ADDR_, &LOCC_v_MeasCallback);
#else
  (void)MEASFreezeDataMTS(&desc, ADDR_, &LOCC_v_MeasCallback);
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
ALGO_INLINE void MeasFreeze_Locc_StackVar(uint32 VADDR_, void * ADDR_, uint32 SIZE_);
ALGO_INLINE void MeasFreeze_Locc_StackVar(uint32 VADDR_, void * ADDR_, uint32 SIZE_)
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

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) */

#endif /* ifndef FRAME_LOCC_H_INCLUDED */

