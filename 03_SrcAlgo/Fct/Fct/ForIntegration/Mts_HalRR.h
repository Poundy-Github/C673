//Suppressed QAC Messages:
//PRQA S 1271, 2217, 3132, 3429, 3453, 6005 MtsBlockDisable
// **********************************************************************
// 
//COMPANY:     Continental Automotive 
// 
//PROJECT:     ARS400
//    
//CPU:         MPC577xN, MPC567xK, SPC56AP60
// 
//Component:   Mts_Adaption_Cmp
// 
//MODULNAME:   FullModelElementName
// 
//Description:	MTS Hal set the selected lane configuration or disable the MTS. Also provides some different timestamps and the HW interrupt callback for transfer finish. To start a transmission the hw MTA counters will be set and also the MTA frame is prepared. Then the sw header is sent. 
//
// 
// **********************************************************************         


#ifndef Mts_HalRR_H
#define Mts_HalRR_H

#include "glob_type.h"
//mts adaption
#include "Mts_Adaption.h"
/*## package ARS400_SW_Algo_Pkg::CoreComponents_Pkg::Mts_Pkg */

/*## class TopLevel::Mts_HalRR */
/*#[ ignore */
//Description:	MTS Hal set the selected lane configuration or disable the MTS. Also provides some different timestamps and the HW interrupt callback for transfer finish. To start a transmission the hw MTA counters will be set and also the MTA frame is prepared. Then the sw header is sent. 

/*#]*/

#ifndef Std_Types_H
#include "Std_Types.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif


//Description:  language, some specific parts
//Range:        -
//Resolution:   -
//Unit:         -



// Dummy implenentation, will be removed in next versions
// Testenvironment


///----------------

#if 1

//------------------------------------------------------------------
//#define LLM_STM_GET_COUNTER()       STM_0.CNT.R
#define MTS_GLOB_SYS_FREQUENCY0       (133)                                 /* [MHz] clock Core0 */
//#define FSMON_TICKS_2_US(ticks)     (((ticks)*2)/(GLOB_SYS_FREQUENCY0))
//------------------------------------------------------------------
// re-mapping to use in old structure
#define MTS_SYS_TICKS_2_MICROSECONDS(ticks)     (((ticks)*2)/(MTS_GLOB_SYS_FREQUENCY0)) //FSMON_TICKS_2_US(ticks)
//------------------------------------------------------------------

#define TME_MSMT_DIFF_CALC(x,y)  (float32)MTS_SYS_TICKS_2_MICROSECONDS((float32)MTI_aui32_TimeMsmt[x] - (float32)MTI_aui32_TimeMsmt[y])

typedef enum MTI_TmeMsmt_e
{
/* 00 */  Tme_Mti_10msTask,
/* 01 */  Tme_Mti_10msTaskEnd,
/* 02 */  Tme_Mti_CycleStart,
/* 03 */  Tme_Mti_MtaFrameStart,
/* 04 */  Tme_Mti_MtaPeakFrameStart,
/* xx */  Tme_Mti_Max
}MTI_TmeMsmt_e;

extern uint32 MTI_aui32_TimeMsmt[Tme_Mti_Max];

typedef struct MTI_TmeMsmt_t
{
  //float32 f_MsmtCycleTime;
  float32 f_TaskTime;
  float32 f_TaskRuntime;
  float32 f_CycleRuntime;
  float32 f_BufferRuntime;
  //float32 f_SendJobDuration;
  //float32 f_SendJobDurPerCycle;
  //float32 f_MtaFrameStart;
  //float32 f_RtMainFuncServ;
}MTI_TmeMsmt_t;

extern MTI_TmeMsmt_t MTI_TmeMsmt;

// usecase: aui32_TimeMsmt[Tme_Enter]   = STM_GET_COUNTER();

#endif


typedef struct MTS_Wkaround
{
  boolean b_SetSystemCounter;
  boolean b_Freeze_1;
  boolean b_Freeze_2;
  boolean b_Freeze_3;
  boolean b_Freeze_4;
  boolean b_Freeze_5;
  boolean b_Freeze_6;
  boolean b_Freeze_7;
  boolean b_Freeze_8;
  boolean b_Freeze_9;
  boolean b_Freeze_CtrlVar;  
  boolean b_TestFreeze;   
  boolean b_TestPeakFreeze;
  boolean b_JustOneFreeze;   
  boolean b_JustOnePeakFreeze_1;
  boolean b_JustOnePeakFreeze_2;
  boolean b_JustOnePeakFreeze_3;
  boolean b_JustOnePeakFreeze_4;
  boolean b_JustOnePeakFreeze_5;
  boolean b_JustOnePeakFreeze_6;
  boolean b_JustOnePeakFreeze_7;
  boolean b_JustOnePeakFreeze_8;
  boolean b_JustOnePeakFreeze_9;
  boolean b_PeakFreeze_9;  
  boolean b_QcsRdy;
  boolean b_TxCtrTxEn;
  boolean b_DataXferViaCpu;
  boolean b_TestFreezeLane2;
  uint16  SndMtiMsg_ErrorCnt;
  boolean b_GetNextJob;
  uint16 u_MtsFrzeDtaRes;
  uint16 u_TaskCounterErr;
  uint32 u_RejectedFreezes;
  uint32 u_RejectedPeakFreezes;
  uint32 u_RejectedSptFreezes;

  //boolean b_CallFze1;
  //boolean b_CallFze2;
  //boolean b_CallFze3;
  //boolean b_CallFze4;
  //boolean b_CallFze5;
  //boolean b_CallFze6;
  //boolean b_enaMtsConfig;
  //boolean b_InitBuffer;
  //uint32  u_CbkCounter;
  //uint32  SW_QCS0_FIFO_U_T;
  //uint32  SW_QCS_FIFO_UF;
  //boolean b_IN_STCLR_L1TX_PIC_waitEna;
  //boolean b_continousMode;
  //boolean mti_trigger;
  //boolean b_PrepareBuffer;
  //boolean b_SendMtiMsg;
  //boolean b_CallDyFze1;
  //boolean b_CallDyFze2;
  //boolean b_CallDyFze3;
  //uint32  SndMtiDly;
  //uint32  SndMtiDlyDflt;
  //uint32  CalcPacketlength;
  //boolean IN_STCLR_L1TX_PIC_rst;
  //uint16  SndMtiMsg_BufExeedCnt;
  //boolean b_FreezeConti;
  //boolean b_FreezeNow;
}MTS_Wkaround;


typedef enum MtsCheckPoint
{
  SC_EMTPY,
  SC_10ms_TASK_Start,
  SC_SendTimeSyncPacket,
  SC_SET_FREEZE_1,
  SC_SET_FREEZE_2,
  SC_SET_FREEZE_3,
  SC_SET_FREEZE_4,
  SC_SET_FREEZE_5,
  SC_SET_FREEZE_6,  
  SC_SET_FREEZE_7,
  SC_SET_FREEZE_8,
  SC_SET_FREEZE_CRTLVAR,  
  SC_FEEZEDATA_FUNC_0,
  SC_FEEZE_PEAKLIST,
  SC_GET_NEXT_PEAKJOB,
  SC_PREP_BUFF_22,
  SC_PREP_BUFF_16,
  SC_PREP_BUFF_CPY_PYLD_22,
  SC_PREP_BUFF_CPY_PYLD_16,
  SC_INC_HEADER_SW_L1,
  SC_INC_HEADER_SW_L2,
  SC_INC_HEADER_SW_L3,
  SC_INC_HEADER_SW_L4,
  SC_INC_HEADER_SW_L5,
  SC_SEND_JOB_HEADER,
  SC_SEND_JOB_DATA,
  SC_SEND_JOB_0,
  SC_GET_NEXT_JOB_0,
  SC_JOB_DONE_0,
  SC_PEAKJOB_DONE,
  SC_StartNewMtaFrame_1,
  SC_StartNewMtaFrame_2
}MtsCheckPoint;

#define MtsCheckPointMax 70
extern uint8 MtsCheckPointIdx;
extern MtsCheckPoint a_MtsCheckPoint[MtsCheckPointMax]; 
extern MTS_Wkaround Wkaround;

                  
                  
//Description:  virtual address for MTS main structure
//define has to be in top of the file because of type-generation for sdl file
//Range:        -
//Resolution:   -
//Unit:         -
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
///* some special virtual addresses */
/*## attribute MTS_VA_MTS_CTRL_VAR */
#define MTS_VA_MTS_CTRL_VAR 0x80050500uL  


//Description:  virtual address for MTS error structure
//define has to be in top of the file because of type-generation for sdl file
//Range:        -
//Resolution:   -
//Unit:         -

///* some special virtual addresses */
/*## attribute MTS_VA_MTS_ERR_LIST */
#define MTS_VA_MTS_ERR_LIST 0x80050F00uL

//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)

/* NOTE: define located in MTS_VA_MTS_ERR_LIST field */
/*## attribute MTS_INFO_DATA_ERR_MAX */
#define MTS_INFO_DATA_ERR_MAX 31u


//Description:  makro for systemcounter access
//Range:        uint32
//Resolution:   -
//Unit:         tick
#define MTS_STM0_GET_SYSCOUNTER()  STM_0.CNT.R

//Description:  makro for high resolution timestamp (1us)
//Range:        uint32
//Resolution:   -
//Unit:         tick
#define MTS_STM1_GET_HIGHRES_TIMESTAMP()  STM_1.CNT.R

//Description:  buffer usage flags for freezes
//Range:        -
//Resolution:   -
//Unit:         -
typedef enum MTS_BufferUsage {
  MTS_BUFFER_NOT_USED,
  MTS_BUFFER_USED
} MTS_BufferUsage;

//Description:  freeze header structure to prepare a job to send from the joblist
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_SwHeader {
  //Description:  virtual address
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_VirtualAddress;		/*## attribute u_VirtualAddress */
  //Description:  payload length
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_ControlPayLoadLength;		/*## attribute u_ControlPayLoadLength */
  //Description:  task / cycle id
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_TaskId;		/*## attribute u_TaskId */
  //Description:  task / cycle counter
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_TaskCnt;		/*## attribute u_TaskCnt */
  //Description:  relative timestamp of freeze
  //Range:        sint16
  //Resolution:   -
  //Unit:         -
  sint16 s_RelTimeStamp;		/*## attribute s_RelTimeStamp */
  //Description:  padding length
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_PaddingLength;		/*## attribute u_PaddingLength */
  //Description:  function channel id. used in prtocol version 2
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_FcnChIdFcnId;		/*## attribute u_FcnChIdFcnId */
  //Description:  high resolution timestamp. points to the time when the freeze is set
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_HighResTimestamp;		/*## attribute u_HighResTimestamp */
  //Description:  payload lenth 2 for local buffered data
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_PayloadLength2;		/*## attribute u_PayloadLength2 */
  //Description:  data pointer to payload
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  puint32 p_Data;		/*## attribute p_Data */
  //Description:  data pointer to payload for buffered data
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  puint32 p_Data2;		/*## attribute p_Data2 */
  //Description:  prepared data to write (from p_data)
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  puint32 p_WriteData;		/*## attribute p_WriteData */
  //Description:  prepared payload length (from u_ControlPayLoadLength)
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_WritePayloadSize;		/*## attribute u_WritePayloadSize */
} MTS_SwHeader;

//Description:  Pointer structure to handle different datatypes
//Range:        -
//Resolution:   -
//Unit:         -
typedef union MTS_t_DataPtr {
  //Description:  Pointer structure to handle different datatypes
  //Range:        pvoid
  //Resolution:   -
  //Unit:         -
  pvoid Generic;		/*## attribute Generic */
  //Description:  Pointer structure to handle different datatypes
  //Range:        uint8
  //Resolution:   -
  //Unit:         -
  puint8 Byte;		/*## attribute Byte */
  //Description:  Pointer structure to handle different datatypes
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  puint16 Word;		/*## attribute Word */
  //Description:  Pointer structure to handle different datatypes
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  puint32 Dword;		/*## attribute Dword */
  //Description:  Pointer structure to handle different datatypes
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 Value;		/*## attribute Value */
} MTS_t_DataPtr;

//Description:  labels for the LVDS lanes
//Range:        -
//Resolution:   -
//Unit:         -
typedef enum MTS_LvdsChannels {
  MTS_LVDS_LANE_1,
  MTS_LVDS_LANE_2,
  MTS_LVDS_LANE_3,
  MTS_LVDS_LANE_4,
  MTS_LVDS_LANE_5
} MTS_LvdsChannels;

//Description:  selectable lane configuration via labels
//Range:        -
//Resolution:   -
//Unit:         -
typedef enum MTS_LaneConfig {
  MTS_LC_CONFIG_1 = 0u,
  MTS_LC_CONFIG_2 = 1u,
  MTS_LC_CONFIG_3 = 2u,
  MTS_LC_CONFIG_4 = 3u,
  MTS_LC_ALL_OFF_EMV = 248u,
  MTS_LC_ALL_OFF = 249u,
  MTS_LC_ERR = 250u,
  MTS_LC_UNDEF = 251u
} MTS_LaneConfig;

//Description:  sub struture to collect some information about sending data
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_t_StatisticData {
  //Description:  payload for the current job
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_PayloadSizeCurJob;		/*## attribute u_PayloadSizeCurJob */
  //Description:  payload size for the current cycle
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_PayloadSizePerCycleCnt;		/*## attribute u_PayloadSizePerCycleCnt */
  //Description:  start timestamp for one job preapring and sending
  //Range:        float32
  //Resolution:   -
  //Unit:         -
  float32 f_SndJobStart;		/*## attribute f_SndJobStart */
  //Description:  end timestamp for one job preapring and sending
  //Range:        float32
  //Resolution:   -
  //Unit:         -
  float32 f_SndJobEnd;		/*## attribute f_SndJobEnd */
  //Description:  duration to prepare and sending one job
  //Range:        float32
  //Resolution:   -
  //Unit:         -
  float32 f_SendJobDuration;		/*## attribute f_SendJobDuration */
  //Description:  duration of sending jobs in one cycle
  //Range:        float32
  //Resolution:   -
  //Unit:         -
  float32 f_SendJobDurPerCycle;		/*## attribute f_SendJobDurPerCycle */
  //Description:  counts jobs during one cycle
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_SendJobCntPerCycleCnt;		/*## attribute u_SendJobCntPerCycleCnt */
} MTS_t_StatisticData;

//Description:  struture to collect some information about sending data
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_t_Statistic {
  //Description:  array: indicates MTA frame is active (used for each lane)
  //Range:        boolean
  //              0 = not active
  //              1 = active
  //Resolution:   -
  //Unit:         -
  boolean b_MtaFrameActiv[5];		/*## attribute b_MtaFrameActiv */
  //Description:  indicats frame already started
  //Range:        boolean
  //              0 = not started
  //              1 = started
  //Resolution:   -
  //Unit:         -
  boolean b_MtaFrameStartedYet;		/*## attribute b_MtaFrameStartedYet */
  //Description:  indicats frame already started
  //Range:        boolean
  //              0 = not started
  //              1 = started
  //Resolution:   -
  //Unit:         -
  boolean b_MtaPeakFrameStartedYet;		/*## attribute b_MtaPeakFrameStartedYet */
  //Description:  flag for send job pending
  //Range:        boolean
  //Resolution:   -
  //Unit:         -
  boolean b_SendJobPending;		/*## attribute b_SendJobPending */
  //Description:  statistics for Core0
  //Range:        MTS_t_StatisticData
  //Resolution:   -
  //Unit:         -
  MTS_t_StatisticData StatCore0;		/*## attribute StatCore0 */
  //Description:  statistics for Peaklist
  //Range:        MTS_t_StatisticData
  //Resolution:   -
  //Unit:         -
  MTS_t_StatisticData StatPeak;		/*## attribute StatPeak */
} MTS_t_Statistic;

//Description:  substructure for main structure
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_CtrlVarErr {
  //Description:  counter to indicate nothing to do
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_NoAction;		/*## attribute u_NoAction */
  //Description:  counter to show job buffer is full
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_JobLimit;		/*## attribute u_JobLimit */
  //Description:  counter to indicate infoblock is wrong
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_InfoblockWrong;		/*## attribute u_InfoblockWrong */
  //Description:  counter to indicate jobs are lost
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_JobsLost;		/*## attribute u_JobsLost */
  //Description:  counter to indicate payload size exceeds
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_PayloadSizeExeeds;		/*## attribute u_PayloadSizeExeeds */
  //Description:  counter to indicate a error in manage jobs occured
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_ManageJobErr;		/*## attribute u_ManageJobErr */
  //Description:  counter to indicate a error in freeze header check 
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_ChkInfoDataErrResult;		/*## attribute u_ChkInfoDataErrResult */
  //Description:  counter to indicate send job data buffer overflow
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_SndJobDataBufExeedCnt;		/*## attribute u_SndJobDataBufExeedCnt */
  //Description:  counter to indicate a wrong core is selected
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint32 u_GetJobPldIdxWrong;		/*## attribute u_GetJobPldIdxWrong */
} MTS_CtrlVarErr;

//Description:  substructure for main structure
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_CtrlVarCnt {
  //Description:  callback counter
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_CbkCounter;		/*## attribute u_CbkCounter */
} MTS_CtrlVarCnt;

//Description:  substructure statisic for main structure
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_CtrlVarStatistik {
  //Description:  duration of sending jobs in one cycle
  //Range:        float32
  //Resolution:   -
  //Unit:         -
  float32 f_SendJobDurPerCycle;		/*## attribute f_SendJobDurPerCycle */
  //Description:  payload size for the current cycle
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_PayloadSizePerCycle;		/*## attribute u_PayloadSizePerCycle */
  //Description:  counts jobs during one cycle
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_SendJobCntPerCycle;		/*## attribute u_SendJobCntPerCycle */
  //Description:  free space in job buffer
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_JobBufferFree;		/*## attribute u_JobBufferFree */
  //Description:  free space in payloadbuffer
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_PayloadSizeBufferFree;		/*## attribute u_PayloadSizeBufferFree */
} MTS_CtrlVarStatistik;

//Description:  main mts structure with all important information about MTS
//Range:        -
//Resolution:   -
//Unit:         -
/*! Struct for measurement data @vaddr: MTS_VA_MTS_CTRL_VAR @vname: MTS_CtrlVar @cycleid: MTS_ENV @allow: meas_low */
typedef struct MTS_t_CtrlVar {
  //Description:  Statistic data for each core
  //Range:        MTS_CtrlVarStatistik
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarStatistik DataCore0;		/*## attribute DataCore0 */
  //Description:  Statistic data for each core
  //Range:        MTS_CtrlVarStatistik
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarStatistik DataCore1;		/*## attribute DataCore1 */
  //Description:  Statistic data for each core
  //Range:        MTS_CtrlVarStatistik
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarStatistik DataCore2;		/*## attribute DataCore2 */
  //Description:  Statistic data for peaklist
  //Range:        MTS_CtrlVarStatistik
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarStatistik DataPeak;		/*## attribute DataPeak */
  //Description:  Counter values
  //Range:        MTS_CtrlVarCnt
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarCnt Cnt;		/*## attribute Cnt */
  //Description:  Error values for each core
  //Range:        MTS_CtrlVarErr
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarErr Err0;		/*## attribute Err0 */
  //Description:  Error values for each core
  //Range:        MTS_CtrlVarErr
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarErr Err1;		/*## attribute Err1 */
  //Description:  Error values for each core
  //Range:        MTS_CtrlVarErr
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarErr Err2;		/*## attribute Err2 */
  //Description:  Error values for peaklist
  //Range:        MTS_CtrlVarErr
  //Resolution:   -
  //Unit:         -
  MTS_CtrlVarErr ErrPeak;		/*## attribute ErrPeak */
  //Description:  counts up since power on
  //Range:        uint32
  //Resolution:   10 ms
  //Unit:         -
  uint32 u_UpCounter;		/*## attribute u_UpCounter */
  //Description:  cycle time
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_CycleTime;		/*## attribute u_CycleTime */
  //Description:  last return value from a freeze
  //Range:        uint8
  //Resolution:   -
  //Unit:         -
  uint8 u_MtsFrzeDtaReturn;		/*## attribute u_MtsFrzeDtaReturn */
  //Description:  keeps the racerunner version
  //Range:        uint8
  //Resolution:   -
  //Unit:         -
  uint8 u_RaceRunnerVersion;		/*## attribute u_RaceRunnerVersion */
  //Description:  keeps the current set lane config
  //Range:        MTS_LaneConfig
  //Resolution:   -
  //Unit:         -
  MTS_LaneConfig CurrLaneConfig;		/*## attribute CurrLaneConfig */
  //Description:  indicates if the buffer align check is executed
  //Range:        boolen (0 = no | 1 = yes)
  //Resolution:   -
  //Unit:         -
  uint8 u_BufferAlnCheck;		/*## attribute u_BufferAlnCheck */
  //Description:  store the MTS version (array)
  //Range:        uint8 (* 8)
  //Resolution:   -
  //Unit:         -
  uint8 a_MtsVersion[8];		/*## attribute a_MtsVersion */
  //Description:  dynamic variables to output something (debug values)
  //Range:        float32
  //Resolution:   -
  //Unit:         -
  float32 f_dummy_1;		/*## attribute f_dummy_1 */
  //Description:  dynamic variables to output something (debug values)
  //Range:        float32
  //Resolution:   -
  //Unit:         -
  float32 f_dummy_2;		/*## attribute f_dummy_2 */
  //Description:  dynamic variables to output something (debug values)
  //Range:        float32
  //Resolution:   -
  //Unit:         -
  float32 f_dummy_3;		/*## attribute f_dummy_3 */
} MTS_t_CtrlVar;

//Description:  Sub structure to identify a wrong freeze by a caller
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_InfoDataError {
  //Description:  virtual address
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_VirtualAddress;		/*## attribute u_VirtualAddress */
  //Description:  payload length
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_PayLoadLength;		/*## attribute u_PayLoadLength */
  //Description:  task / cycle id
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_TaskId;		/*## attribute u_TaskId */
  //Description:  function id
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_FuncID;		/*## attribute u_FuncID */
  //Description:  flag for buffer used
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_BufferUsed;		/*## attribute u_BufferUsed */
  //Description:  errorcode
  //Range:        uint32
  //Resolution:   -
  //Unit:         -
  uint32 u_ErrorCode;		/*## attribute u_ErrorCode */
} MTS_InfoDataError;

//Description:  Mainstructure for Infoblock wrong
//Range:        -
//Resolution:   -
//Unit:         -
/*! Struct for measurement data @vaddr: MTS_VA_MTS_ERR_LIST @vname: MTS_ErrList @cycleid: MTS_ENV @allow: meas_low */
typedef struct MTS_InfoDataErrorAll {
  //Description:  Errorinformation for wrong infoblock of a freeze
  //Range:        MTS_InfoDataError
  //Resolution:   -
  //Unit:         -
  MTS_InfoDataError Core0[MTS_INFO_DATA_ERR_MAX];		/*## attribute Core0 */
  //Description:  Errorinformation for wrong infoblock of a freeze
  //Range:        MTS_InfoDataError
  //Resolution:   -
  //Unit:         -
  MTS_InfoDataError Core1[MTS_INFO_DATA_ERR_MAX];		/*## attribute Core1 */
  //Description:  Errorinformation for wrong infoblock of a freeze
  //Range:        MTS_InfoDataError
  //Resolution:   -
  //Unit:         -
  MTS_InfoDataError Core2[MTS_INFO_DATA_ERR_MAX];		/*## attribute Core2 */
  //Description:  index for array
  //Range:        uint8
  //Resolution:   -
  //Unit:         -
  uint8 Core0Idx;		/*## attribute Core0Idx */
  //Description:  index for array
  //Range:        uint8
  //Resolution:   -
  //Unit:         -
  uint8 Core1Idx;		/*## attribute Core1Idx */
  //Description:  index for array
  //Range:        uint8
  //Resolution:   -
  //Unit:         -
  uint8 Core2Idx;		/*## attribute Core2Idx */
} MTS_InfoDataErrorAll;

//Description:  sub structre to count all job / cycle
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_JobsPerCycleCntElements_t {
  //Description:  all jobs send during one cycle 
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_CycleCnt;		/*## attribute u_CycleCnt */
  //Description:  max value of counted job per cycle
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_CycleCntMax;		/*## attribute u_CycleCntMax */
  //Description:  job counter
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint32 u_Cnt;		/*## attribute u_Cnt */
} MTS_JobsPerCycleCntElements_t;

//Description:  structure for counts all jobs during one cycle and split it into the different cycle ids
//Range:        -
//Resolution:   -
//Unit:         -
typedef struct MTS_JobsPerCycleCnt_t {
  //Description:  count values for each cycle id
  //Range:        MTS_JobsPerCycleCnt_t
  //Resolution:   -
  //Unit:         -
  MTS_JobsPerCycleCntElements_t Cnt204;		/*## attribute Cnt204 */
  //Description:  count values for each cycle id
  //Range:        MTS_JobsPerCycleCnt_t
  //Resolution:   -
  //Unit:         -
  MTS_JobsPerCycleCntElements_t Cnt205;		/*## attribute Cnt205 */
  //Description:  count values for each cycle id
  //Range:        MTS_JobsPerCycleCnt_t
  //Resolution:   -
  //Unit:         -
  MTS_JobsPerCycleCntElements_t CntRest;		/*## attribute CntRest */
  //Description:  count values for each cycle id
  //Range:        MTS_JobsPerCycleCnt_t
  //Resolution:   -
  //Unit:         -
  MTS_JobsPerCycleCntElements_t CntAll;		/*## attribute CntAll */
  //Description:  clear counter
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_ResetAfterTimeCnt;		/*## attribute u_ResetAfterTimeCnt */
  //Description:  clear after a given time the max counter
  //Range:        uint16
  //Resolution:   -
  //Unit:         -
  uint16 u_ResetAfterTime;		/*## attribute u_ResetAfterTime */
} MTS_JobsPerCycleCnt_t;

//Description:  version numer of header file
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_VER_HAL_H */
#define MTS_VER_HAL_H ((uint8) 39) // HAL version *.h

//Description:  virtual adress for time base 
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_VA_MTS_TIME_BASE */
#define MTS_VA_MTS_TIME_BASE 0xFFFFFFF0uL

//Description:  MTS lane test. Support for engineering support. Must be 0
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_ALL_LINES_GENERIC_TEST */
#define MTS_ALL_LINES_GENERIC_TEST 0

//Description:  header information for preparing to send
//Range:        MTS_SwHeader
//Resolution:   -
//Unit:         -
/*## attribute MTS_SwDataHeader */
extern MTS_SwHeader MTS_SwDataHeader;

//Description:  header information for preparing to send
//Range:        MTS_SwHeader
//Resolution:   -
//Unit:         -
/*## attribute MTS_SwPeakDataHeader */
extern MTS_SwHeader MTS_SwPeakDataHeader;

//Description:  main structure to keep all important information about MTS
//Range:        MTS_t_CtrlVar
//Resolution:   -
//Unit:         -
/*## attribute MTS_CtrlVar */
extern MTS_t_CtrlVar MTS_CtrlVar;

//Description:  collects some statitic data like amount of job and payload during one cycle
//Range:        MTS_t_Statistic
//Resolution:   -
//Unit:         -
/*## attribute MTS_StatisticC0 */
extern MTS_t_Statistic MTS_StatisticC0;

//Description:  indicates peak job is pending
//Range:        boolean (0 = no | 1 = yes)
//Resolution:   -
//Unit:         -
/*## attribute b_PeakJobPending */
extern boolean b_PeakJobPending;

//Description:  keep the timestamp when the MTA frame is started
//Range:        uint32
//Resolution:   66,66 MHz
//Unit:         tick
/*## attribute u_CycleStartTimeStamp */
extern uint32 u_CycleStartTimeStamp;

//Description:  keep the timestamp when the MTA frame is started
//Range:        uint32
//Resolution:   66,66 MHz
//Unit:         tick
/*## attribute u_PeakCycleStartTimeStamp */
extern uint32 u_PeakCycleStartTimeStamp;

//Description:  Counts all job during one cycle and split it into the different cycle ids
//Range:        MTS_JobsPerCycleCnt_t
//Resolution:   -
//Unit:         -
/*## attribute MTS_JobsPerCycCnt */
extern MTS_JobsPerCycleCnt_t MTS_JobsPerCycCnt;

/***    User explicit entries    ***/


/* Operations */

//METHOD: void MTS_v_InitHalLaneConfig1().
//**************************************************************************
//Description:    lane configuration default settings
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_InitHalLaneConfig1() */
void MTS_v_InitHalLaneConfig1(void);

//METHOD: void MTS_v_InitHalLaneConfig2().
//**************************************************************************
//Description:    lane configuration default settings
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_InitHalLaneConfig2() */
void MTS_v_InitHalLaneConfig2(void);

//METHOD: void MTS_v_InitHalLaneConfig3().
//**************************************************************************
//Description:    lane configuration default settings
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_InitHalLaneConfig3() */
void MTS_v_InitHalLaneConfig3(void);

//METHOD: void MTS_v_InitHalLaneConfig4().
//**************************************************************************
//Description:    lane configuration default settings
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_InitHalLaneConfig4() */
void MTS_v_InitHalLaneConfig4(void);

//METHOD: void MTS_v_InitHalDisableMts().
//**************************************************************************
//Description:    mode to switch off mts (runtime neutral)
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_InitHalDisableMts() */
void MTS_v_InitHalDisableMts(void);

//METHOD: void MTS_v_InitHalDisableMtsForEmv().
//**************************************************************************
//Description:    mode to switch off mts (pin defined pegel)
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_InitHalDisableMtsForEmv() */
void MTS_v_InitHalDisableMtsForEmv(void);

//METHOD: void MTS_v_InitDma().
//**************************************************************************
//Description:    initialise DMA TCB area
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_InitDma() */
void MTS_v_InitDma(void);

//METHOD: void MTS_v_MainfunctionHal().
//**************************************************************************
//Description:    mainfunction of mts hal
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_MainfunctionHal() */
void MTS_v_MainfunctionHal(void);

//METHOD: boolean MTS_b_SendJobHeader().
//**************************************************************************
//Description:    send the sw header of a job
//Return value:   boolean
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_b_SendJobHeader() */
boolean MTS_b_SendJobHeader(void);

//METHOD: void MTS_v_NewMtaFrame(MTS_LvdsChannels LvdsChannel).
//**************************************************************************
//Description:    update MTA frame by setting new payload data
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# LvdsChannel [In] Description:  selected lvds channel
//Range:        MTS_LvdsChannels
//Resolution:   -
//Unit:         -
//
//**************************************************************************
/*## operation MTS_v_NewMtaFrame(MTS_LvdsChannels) */
void MTS_v_NewMtaFrame(const MTS_LvdsChannels LvdsChannel);

//METHOD: uint32 MTS_u_GetHighResTimestamp().
//**************************************************************************
//Description:    returning high resolution time stamp (1us)
//Return value:   uint32
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_u_GetHighResTimestamp() */
uint32 MTS_u_GetHighResTimestamp(void);

//METHOD: uint32 MTS_u_GetSystemCounter().
//**************************************************************************
//Description:    returning system counter (66,6 MHz)
//return value:   uint32
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_u_GetSystemCounter() */
uint32 MTS_u_GetSystemCounter(void);

//METHOD: void MTS_v_TransmitFinished_ISRfunc().
//**************************************************************************
//Description:    interrupt call back. When a transmission is finish, this function is called and finish the pending job
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_TransmitFinished_ISRfunc() */
void MTS_v_TransmitFinished_ISRfunc(void);

//METHOD: void MTS_v_DmaTransmitLane2Finished_ISRfunc().
//**************************************************************************
//Description:    isr callback. currently not connected to MTI DMA
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_DmaTransmitLane2Finished_ISRfunc() */
void MTS_v_DmaTransmitLane2Finished_ISRfunc(void);

//METHOD: void MTS_v_DmaTransmitLane2HiFinished_ISRfunc().
//**************************************************************************
//Description:    interrupt call back (peaklist). When a transmission is finish, this function is called and finish the pending job
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_DmaTransmitLane2HiFinished_ISRfunc() */
void MTS_v_DmaTransmitLane2HiFinished_ISRfunc(void);

//METHOD: void MTS_v_DmaTransmitPeaklistFinished_ISR().
//**************************************************************************
//Description:    interrupt call back. calls MTS_v_DmaTransmitPeaklistFinished_ISR()
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_DmaTransmitPeaklistFinished_ISR() */
void MTS_v_DmaTransmitPeaklistFinished_ISR(void);

//METHOD: void MTS_v_IncMtiHdCounter(MTS_LvdsChannels ChannelSelection).
//**************************************************************************
//Description:    update MTA HW header counter
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# ChannelSelection [In] Description:  selected lvds channel
//Range:        MTS_LvdsChannels
//Resolution:   -
//Unit:         -
//
//**************************************************************************
/*## operation MTS_v_IncMtiHdCounter(MTS_LvdsChannels) */
void MTS_v_IncMtiHdCounter(const MTS_LvdsChannels ChannelSelection);

//METHOD: void MTS_v_EnableStm1().
//**************************************************************************
//Description:    enables the high resolution time for MTS
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_v_EnableStm1() */
void MTS_v_EnableStm1(void);

//METHOD: void MTS_v_CheckPoint(MtsCheckPoint state).
//**************************************************************************
//Description:    checkpoint function for debugging. In Appl it is deactivated
//Return value:   none
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//# state [In] Description:  checkpoint number
//Range:        MtsCheckPoint
//Resolution:   -
//Unit:         -
//
//**************************************************************************
/*## operation MTS_v_CheckPoint(MtsCheckPoint) */
void MTS_v_CheckPoint(MtsCheckPoint state);

//METHOD: boolean MTS_b_GetPeakJobPending().
//**************************************************************************
//Description:    returning peaklist pending flag
//Return value:   boolean
//                0 = not pending
//                1 = pending
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_b_GetPeakJobPending() */
boolean MTS_b_GetPeakJobPending(void);

//METHOD: uint8 MTS_u_GetHalVersion().
//**************************************************************************
//Description:    returning source file version number
//Return value:   uint8
//Preconditions:  none
//Postconditions: none
//**************************************************************************
//PARAMETERS: 
//
//
//**************************************************************************
/*## operation MTS_u_GetHalVersion() */
uint8 MTS_u_GetHalVersion(void);

/***    User explicit entries    ***/


#ifdef __cplusplus
}
#endif


#endif
/*
  1271) Using a non-int expression to define an enum constant: no change
  2217) Line length exceeds 200 characters: description is longer, no change
  3132) Hard coded 'magic' number: ok
  3429) A function-like macro is being defined: for fast access
  3453) A function could probably be used instead of this function-like macro: macro is faster
  6005) Unknown error: no change
*/
/* date: 2014-03-03, reviewer: Sauter, reason: see above, proven in use */
// PRQA L:MtsBlockDisable

/*********************************************************************
	File Path	: ..\..\..\04_Engineering\_gensrc\rhapsody\Mts_HalRR.h
*********************************************************************/

