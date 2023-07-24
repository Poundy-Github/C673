/*! \file *********************************************************************

  @defgroup InternalConfiguration VDY Internal Configuration

  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_internal_ext.h $

  @brief			This file contains all types, definitions and prototypes needed for this component

  $Descripion:		$
  
  $Revision: 1.1 $

  CHANGES:
  ---*/ /*---

*****************************************************************************/
#ifndef VDY_INT_INCLUDED
#define VDY_INT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "vdy_cfg_ext.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* Activity state values */

/// VDY Activity Sate - Invalid
#define VDY_STAT_INACTIVE              ((VDYActState_t) 0U)

/// VDY Activity Sate - Valid
#define VDY_STAT_ACTIVE                ((VDYActState_t) 1U)

#ifndef AS_SERVICEFUNC_VERSION
/// VDY Callback Disable
#define NO_VDY_CALLBACK                              ((VDYCallBackHdlr_t*)     0)

/// VDY Measurement Callback Disable
#define NO_VDY_MEAS_CALLBACK                         ((MeasHdlr_t )           0)

/// VDY Time Callback Disable
#define NO_VDY_TIME_CALLBACK                         ((TimerHdlr_t *)         0)

/// VDY Exect Checkpoint Callback Disable
#define NO_VDY_CP_CALLBACK                           ((ExecChkpnt_t *)        0)

/// VDY Checkpoint Callback Disable
#define NO_VDY_CHECKPOINT_CALL                       ((CheckPointHdlr_t)      0)

/// VDY Eval Checkpoint Callback Disable
#define NO_VDY_EVAL_CHECKPOINT_CALL                  ((EvalCheckPointHdlr_t)  0)

/// VDY Measurement Callback Disable
#define NO_VDY_TIME_START_STOP_CALL                  ((ProfHdlr_t)            0)
#endif

#if (CFG_VDY_INT_GYRO)

/// Bit mask for lower dword table node flags 0..31 
#define VDY_YWRT_NODES_MAKS_ALL_LO             (0xFFFFFFFFUL)

/// Bit mask for upper dword table node flags 32..63 
#define VDY_YWRT_NODES_MAKS_ALL_HI             ((1UL<<((VDY_YWRT_NO_NODES)-32UL))-1UL)

/// Flag bit position number of total write counts 
#define VDY_YWRT_BIT_POS_CNTR                  VDY_YWRT_NO_NODES

/// Test if all table node flags are set 
#define VDY_YWRT_NODES_ALL_VALID(stat_)        ( (((stat_[0]) & VDY_YWRT_NODES_MAKS_ALL_LO) == VDY_YWRT_NODES_MAKS_ALL_LO) && \
                                                 (((stat_[1]) & VDY_YWRT_NODES_MAKS_ALL_HI) == VDY_YWRT_NODES_MAKS_ALL_HI) )

/// Test if at least one table node flag is set 
#define VDY_YWRT_NODES_ONE_VALID(stat_)        ( (((stat_[0]) & VDY_YWRT_NODES_MAKS_ALL_LO) != 0UL) || \
                                                 (((stat_[1]) & VDY_YWRT_NODES_MAKS_ALL_HI) != 0UL) )


/// Test if specific node flag is set 
#define VDY_YWRT_NODE_IS_VALID(idx_,stat_)     (((1UL<<((idx_)& 0x1FUL)) & (stat_[(uint32)(idx_)>>5UL]))!= 0UL)
/// Set specific node flag 
#define VDY_YWRT_NODE_SET_VALID(idx_,stat_)    ((stat_[(ui32_t)(idx_)>>5UL]) |=  (1UL<<((uint32)(idx_)& 0x1FUL)))
/// Clear specific node flag 
#define VDY_YWRT_NODE_SET_INVALID(idx_,stat_)  ((stat_[(ui32_t)(idx_)>>5UL]) &= ~(1UL<<((uint32)(idx_)& 0x1FUL)))

#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/// \brief  General activity state
/// \details
/// \unit TBD \n
/// \precision TBD \n
/// \min 0 \n
/// \max TBD
typedef uint8   VDYActState_t;

/// \brief  Understeer gradient
/// \details
/// \unit rad/(m/s^2) \n
/// \precision TBD \n
/// \min 0 \n
/// \max 0.5
typedef float32 fVDYSlfStGrad_t;

/// \brief  Wheel load dependency 
/// \details
/// \unit 1 \n
/// \precision TBD \n
/// \min 1.0 \n
/// \max 2.0 
typedef float32 fVDYWhlLdDep_t;

/// \brief  VDY Drive Axle
/// \details
/// \unit TBD \n
/// \precision TBD \n
/// \min 0 \n
/// \max TBD
typedef uint8   VDYAxle_t;

/// \brief  Wheel ticks (impulse) deviation
/// \details
/// \unit TBD \n
/// \precision TBD \n
/// \min 0 \n
/// \max TBD
typedef uint8   VDYWhlTicksDev_t;

/// \brief  Actual state of gear box 
/// \details
/// \unit TBD \n
/// \precision TBD \n
/// \min 0 \n
/// \max TBD
typedef uint8   VDYActGearPos_t;

/// \brief  Brake activity level (=torque or pressure in dependence of vehicle)
/// \details
/// \unit TBD \n
/// \precision TBD \n
/// \min 0 \n
/// \max TBD 
typedef uint16  VDYBrkActLevel_t;

/// \brief  Ticks (pulses) per revolution
/// \details
/// \unit 1/rev \n
/// \precision TBD \n
/// \min 0 \n
/// \max TBD
typedef uint8   VDYTcksPerRev_t;

/*<---------------------------------------------------------------------------
  NVN data of the auto code modules
----------------------------------------------------------------------------->*/

/// dummy for pdo tool 
#ifdef __PDO__

#ifndef BIT_FIELD_MSB_FIRST
#define BIT_FIELD_MSB_FIRST  1
#endif

/// \brief NVM State
typedef struct VDYNvState
{
#if (BIT_FIELD_MSB_FIRST)
  uint32      Pad            : 20;		///< Padding
  uint32      Wld            : 2;		///< Wheel load dependency 
  uint32      VelCorr        : 2;		///< Longitudinal velocity correction 
  uint32      LatAcc         : 2;		///< Lateral acceleration zero point offset 
  uint32      YwRate         : 2;		///< Yaw rate zero point offset 
  uint32      SlfstGrad      : 2;		///< Selfsteer gradient 
  uint32      StWhlAng       : 2;		///< Steering wheel angle zero point offset 
#else
  uint32      StWhlAng       : 2;		///< Steering wheel angle zero point offset 
  uint32      SlfstGrad      : 2;		///< Selfsteer gradient 
  uint32      YwRate         : 2;		///< Yaw rate zero point offset 
  uint32      LatAcc         : 2;		///< Lateral acceleration zero point offset 
  uint32      VelCorr        : 2;		///< Longitudinal velocity correction 
  uint32      Wld            : 2;		///< Wheel load dependency 
  uint32      Pad            : 20;		///< Padding
#endif
} VDYNvState_t;

#endif

/// \brief NVM IO Data
typedef struct
{
  VDYNvSlfStGradCal_t SlfstGrad;    ///< Understeer / Oversteer gradient estimation 
  VDYNvWldCal_t       Wld;          ///< Wheel load dependency  
#ifdef __PDO__
  VDYNvState_t        State;
#else
  VDYIoState_t        State;        ///< Read status respective write request 
#endif
} VDYNvAutoIoData_t;


/// \brief Non Volatile Data Interface of the Vehicle Dynamics Module 
typedef struct
{
  VDYNvAutoIoData_t   Read;             ///< Non volatile memory read interface @NAME: In 
  VDYNvAutoIoData_t   Write;            ///< Non volatile memory write interface @NAME: Out 
} VDYNvData_t;         /*!< @VADDR: 0x20012300 @VNAME: VDYNvDataAuto @ALLOW: vdy_pub @cycleid: vdy_cycle_id */                 


/*---- Input Data ----------------------------------------------------------*/

/// \brief VDY Input Frame
typedef struct
{
  uint32         Version;     ///< component version number         
  uint16         CycleCnt;    ///< vdy cycle counts                 
  uiTime_t       CycleTime;   ///< component cycle time             
  VDYCaliState_t CaliMode;    ///< Calibration inhibition states    
  BaseOpMode_t   OpMode;      ///< Operating modes of vdy component 
} VDYInputFrame_t;


/// \brief Input of the Vehicle Dynamics Module 
 
typedef struct
{
  VDYInputFrame_t          Frame;         ///< Control frame                      
  VehParMain_t             Parameter;     ///< Vehicle parameters @NAME: Para     
  VehSigMain_t             Signals;       ///< Vehicle sensor signals @NAME: Sig  
} VDYInputData_t;  


/// \brief List of input ports.
/// \details the replica of request port - used for nvmRead element initialization in vdy simulation as reqVdyPrtList_t is const & cannot be initialized. 
typedef struct
{
  BaseCtrlData_t*  pBaseCtrlData;			///< Control data giving information about the current mode
  VDYNvIoData_t*   pNVMRead;				///< The vdy nvm input and output data stuct 
  VehSig_t*        pVehicleInputSignals;	///< Main Vehicle dynacmis sensor signals 
  VehPar_t*        pVehicleParameter;		///< Static Vehicle parameters all values are vehicle dependent, therefore no default values are given
} reqVdyPort_t;


/*---- Callback functions for meas, checkpoint and profiling ----------------------------------------------------*/
#ifndef AS_SERVICEFUNC_VERSION
/// \brief Task Monitoring
/// \details particular MON checkpoint values
typedef enum 
{ 
  VDY_CHECKPOINT_1=0x20010001,		///< 0x20010001
  VDY_CHECKPOINT_2,					///< 0x20010002
  VDY_CHECKPOINT_3,					///< 0x20010003
  VDY_CHECKPOINT_4,					///< 0x20010004
  VDY_CHECKPOINT_5,					///< 0x20010005
  VDY_CHECKPOINT_6,					///< 0x20010006
  VDY_CHECKPOINT_7,					///< 0x20010007
  VDY_CHECKPOINT_8,					///< 0x20010008
  VDY_CHECKPOINT_9,					///< 0x20010009
  VDY_CHECKPOINT_10,				///< 0x2001000A
  VDY_CHECKPOINT_11,				///< 0x2001000B
  VDY_CHECKPOINT_12,				///< 0x2001000C
  VDY_CHECKPOINT_13,				///< 0x2001000D
  VDY_CHECKPOINT_14,				///< 0x2001000E
  VDY_CHECKPOINT_15					///< 0x2001000F
} VDYCheckpoint_t;

/// Prototpyes for profiling handlers 
typedef void (*ProfHdlr_t)(void);

/// \brief Profiling Handler
typedef struct
{
  ProfHdlr_t                Start;           ///< Handler to start profile timing 
  ProfHdlr_t                Stop;            ///< Handler to stop profile timing 
} TimerHdlr_t;

/// Prototpyes for Set Checkpoint handlers 
typedef void (*CheckPointHdlr_t)(VDYCheckpoint_t VDYCheckpoint);

/// Prototpyes for Eval Checkpoint handlers 
typedef void (*EvalCheckPointHdlr_t)(void);

/// \brief Checkpoint handler
typedef struct
{
  CheckPointHdlr_t          SetCheckPoint;   ///< Handler to Set the task Mon checkpoint 
  EvalCheckPointHdlr_t      EvalCheckPoints; ///< Handler to evaluate the Task Monitoring checkpoints  
} ExecChkpnt_t;

/// \brief Measfreeze handler
typedef struct
{
  MeasHdlr_t              pfMeasFreeze;            ///< Global meas freeze (copy)handler 
  TimerHdlr_t           * pfProfTimer;             ///< Profile timer handler 
  ExecChkpnt_t          * pfExecChckpnt;           ///< Execution checkpoint handler 
} VDYCallBackHdlr_t;
#endif



/*****************************************************************************
  GLOBAL CONSTANTS (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT EXTERNAL SCOPE)
*****************************************************************************/

#ifdef CFG_VDY_MEASUREMENT
extern void VDY_MTS_Callback (void);
#endif
extern void vdy_memset_s(void* src_ptr, uint8 u_val, uint32 u_size);
extern void vdy_memcpy_s(void* dst_ptr,const void* src_ptr, uint32 u_size);
extern uint8 vdy_matrix_multiplication(float32 matrix_A[], float32 matrix_B[], float32 matrix_BxA[], uint8 col_A_dim, uint8 row_A_dim, uint8 col_B_dim);


/** @} end defgroup */
#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

/*** END OF SINLGE INCLUDE SECTION ******************************************/
#endif

/** @} */ 
/* EOF */
