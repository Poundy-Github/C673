// **********************************************************************
// 
//COMPANY:     Continental Automotive , 
// 
//PROJECT:     SoC
//    
//CPU:         MPC5674x
// 
//Component:   SOC_Common
// 
//MODULNAME:   FullModelElementName
// 
//Description:        Definition of algo services (callbacks)
//Integration notes:  The types are used from modules implementing services
//Package prefix:     -
//
// 
// **********************************************************************         


#ifndef algo_service_types_H
#define algo_service_types_H

#include "Rte_Type.h"
#include "edma_service_inline.h"
#include "glob_type.h"
#include "Dem_IntErrIdSlv.h"
#include "RTA_Types.h"
#include "Meas.h"

/*## class TopLevel::algo_service_types */
/*#[ ignore */
//Description:        Definition of algo services (callbacks)
//Integration notes:  The types are used from modules implementing services
//Package prefix:     -

#ifdef __cplusplus
extern "C"
{
#endif

//


//**************************************************************************
//Type: AS_t_IfVersionNum
//Service interface version number
typedef uint32 AS_t_IfVersionNum;

//**************************************************************************
//Type: AS_t_EDMACopy
//Definition of EDMA service function EDMACopy(..). This service function can be used to copy data from A to B by using DMA.
//
//Parameter:     p_Dst
//Description:   Pointer to the destination buffer.
//
//Parameter:     p_Src
//Description:   Pointer to the source buffer.
//Parameter:     s_SizeBytes
//Description:   Number of bytes to copy.
//Parameter:     p_ChIndexOut
//Description:   Pointer to signed integer value where the service function write the used channel index.
//Return value:  Signed integer
//Description:   The service function returns the following error values:
//               s_NOERROR                     (0): Service function exits without any error.
//               s_ERROR_EDMA_HANDLE           (1): Service function handle not available.
//               s_ERROR_EDMA_DSTBUFFER        (4): Service function parameter <p_Dst> invalid.
//               s_ERROR_EDMA_SRCBUFFER        (5): Service function parameter <p_Src> invalid.
//               s_ERROR_EDMA_CHANNELINDEX     (6): Service function parameter <p_ChIndexOut> invalid.
//               s_ERROR_EDMA_ERRORBIT         (8): Service function is not able to clear error bits.
//               s_ERROR_EDMAPARAMSET          (9): Service function is not able to set the parameter set.
//               s_ERROR_EDMA_ENABLE          (10): Service function is not able to enable transfer engine.
//               s_ERROR_EDMASERVICE          (11): Service function not available.
//               s_ERROR_CHANNELPOOL_EXHAUSED (13): Service function not available due to reserved channels.
typedef sint32 (*AS_t_EDMACopy) (void *p_Dst, void *p_Src, sint32 s_SizeBytes, sint32 *p_ChIndexOut);
/*#]*/

//**************************************************************************
//Type: AS_t_EDMACopy2D
//Definition of EDMA service function EDMACopy2D(..). This service function can be used to copy 2D data from A to B by using DMA.
//
//Parameter:     p_Dst
//Description:   Pointer to the destination buffer.
//
//Parameter:     p_Src
//Description:   Pointer to the source buffer.
//Parameter:     p_DstPitch
//Description:   Pointer to the destination pitch.
//
//Parameter:     p_SrcPitch
//Description:   Pointer to the source pitch.
//Parameter:     s_Width.
//Description:   Width to copy.
//Parameter:     s_Height.
//Description:   Height to copy.
//Parameter:     p_ChIndexOut.
//Description:   Pointer to signed integer value where the service function write the used channel index.
//Return value:  Signed integer.
//Description:   The service function returns the following error values:
//               s_NOERROR                     (0): Service function exits without any error.
//               s_ERROR_EDMA_HANDLE           (1): Service function handle not available.
//               s_ERROR_EDMA_DSTBUFFER        (4): Service function parameter <p_Dst> invalid.
//               s_ERROR_EDMA_SRCBUFFER        (5): Service function parameter <p_Src> invalid.
//               s_ERROR_EDMA_CHANNELINDEX     (6): Service function parameter <p_ChIndexOut> invalid.
//               s_ERROR_EDMA_ERRORBIT         (8): Service function is not able to clear error bits.
//               s_ERROR_EDMAPARAMSET          (9): Service function is not able to set the parameter set.
//               s_ERROR_EDMA_ENABLE          (10): Service function is not able to enable transfer engine.
//               s_ERROR_EDMASERVICE          (11): Service function not available.
//               s_ERROR_CHANNELPOOL_EXHAUSED (13): Service function not available due to reserved channels.
typedef sint32 (*AS_t_EDMACopy2D) (void *p_Dst, void *p_Src, sint32 s_DstPitch, sint32 s_SrcPitch, sint32 s_Width, sint32 s_Height, sint32 *p_ChIndexOut);

//**************************************************************************
//Type: AS_t_EDMACopyChained
//Definition of EDMA service function EDMACopyChained(..). This service function can be used to copy data from A to B by using chaining DMA.
//
//Parameter:     p_PreDst
//Description:   Pointer to the pre destination buffer.
//
//Parameter:     p_PreSrc
//Description:   Pointer to the pre source buffer.
//Parameter:     s_PreNumBytes
//Description:   Number of pre bytes to copy.
//Parameter:     p_PostDst
//Description:   Pointer to the pre destination buffer.
//
//Parameter:     p_PostSrc
//Description:   Pointer to the pre source buffer.
//Parameter:     s_PostNumBytes
//Description:   Number of pre bytes to copy.
//Parameter:     p_PostChIndexOut.
//Description:   Pointer to signed integer value where the service function write the used channel index.
//Return value:  Signed integer.
//Description:   The service function returns the following error values:
//               s_NOERROR                     (0): Service function exits without any error.
//               s_ERROR_EDMA_HANDLE           (1): Service function handle not available.
//               s_ERROR_EDMA_DSTBUFFER        (4): Service function parameter <p_PreDst>, <p_PostDst> invalid.
//               s_ERROR_EDMA_SRCBUFFER        (5): Service function parameter <p_PreSrc>, <p_PostSrc> invalid.
//               s_ERROR_EDMA_CHANNELINDEX     (6): Service function parameter <p_PostChIndexOut> invalid.
//               s_ERROR_EDMA_ERRORBIT         (8): Service function is not able to clear error bits.
//               s_ERROR_EDMAPARAMSET          (9): Service function is not able to set the parameter set.
//               s_ERROR_EDMA_ENABLE          (10): Service function is not able to enable transfer engine.
//               s_ERROR_EDMASERVICE          (11): Service function not available.
//               s_ERROR_EDMA_CHAIN           (12): Service function is not able to chain channels.
//               s_ERROR_CHANNELPOOL_EXHAUSED (13): Service function not available due to reserved channels.
typedef sint32 (*AS_t_EDMACopyChained) (void *p_PreDst, void *p_PreSrc, sint32 s_PreNumBytes, void *p_PostDst, void *p_PostSrc, sint32 s_PostNumBytes, sint32 *p_PostChIndexOut);

//**************************************************************************
//Type: AS_t_EDMAWait
//Definition of EDMA service function EDMAWait(..). This service function can be used to wait for an EDMA finish.
//
//Parameter:     s_ChIndex
//Description:   Channel index fo which to wait.
//Return value:  Signed integer.
//Description:   The service function returns the following error values:
//               s_NOERROR                     (0): Service function exits without any error.
//               s_ERROR_EDMA_HANDLE           (1): Service function handle not available.
//               s_ERROR_FREECHANNEL           (7): Service function is not able to free channel.
//               s_ERROR_EDMA_ERRORBIT         (8): Service function is not able to clear error bits.
//               s_ERROR_EDMASERVICE          (11): Service function not available.
//               s_ERROR_CHANNEL_NOTINUSE     (14): Service function not able to find the channel to release.
typedef sint32 (*AS_t_EDMAWait) (sint32 s_ChIndex);

//**************************************************************************
//Type: AS_t_EDMAMemSet
//Definition of EDMA service function EDMAMemSet(..). This service function can be used to set memory to a desired value by using DMA.
//
//Parameter:     p_MemLoc
//Description:   Pointer to the destination buffer.
//
//Parameter:     p_Pattern
//Description:   Pointer to the desired pattern that shall be written to the memory.
//Parameter:     s_TransferCnt
//Description:   Number of bytes to write.
//Parameter:     p_ChIndexOut.
//Description:   Pointer to signed integer value where the service function write the used channel index.
//Return value:  Signed integer.
//Description:   The service function returns the following error values:
//               s_NOERROR                     (0): Service function exits without any error.
//               s_ERROR_EDMA_HANDLE           (1): Service function handle not available.
//               s_ERROR_EDMA_DSTBUFFER        (4): Service function parameter <p_MemLoc> invalid.
//               s_ERROR_EDMA_CHANNELINDEX     (6): Service function parameter <p_ChIndexOut> invalid.
//               s_ERROR_EDMA_ERRORBIT         (8): Service function is not able to clear error bits.
//               s_ERROR_EDMAPARAMSET          (9): Service function is not able to set the parameter set.
//               s_ERROR_EDMA_ENABLE          (10): Service function is not able to enable transfer engine.
//               s_ERROR_EDMASERVICE          (11): Service function not available.
//               s_ERROR_CHANNELPOOL_EXHAUSED (13): Service function not available due to reserved channels.
//               s_ERROR_OORNUM_OF_PATTERN    (15): Service function parameter <s_TransferCnt> invalid (greather then 0xFFFF).
typedef sint32 (*AS_t_EDMAMemSet) (void *p_MemLoc, const uint32 *p_Pattern, const sint32 s_TransferCnt, sint32 *p_ChIndexOut);

//**************************************************************************
//Type: AS_t_CacheInv
//Definition of Algo Sevice: Cache Invalidate
// - Ext Memory Buffer Ptr (In)
// - Size of Ext Memory (In)
typedef void (*AS_t_CacheInv) (void *p_MemLoc, uint32 u_NumBytes);


//**************************************************************************
//Type: AS_t_CacheWbInv
//Definition of Algo Sevice: Cache Writeback Invalidate
// - Ext Memory Buffer Ptr (In)
// - Size of Ext Memory (In)
typedef void (*AS_t_CacheWbInv) (void *p_MemLoc, uint32 u_NumBytes);


//**************************************************************************
//Type: AS_t_CacheWbInvAll
//Definition of Algo Sevice: Cache Writeback Invalidate All
// - No parameters
typedef void (*AS_t_CacheWbInvAll) (void);


//**************************************************************************
//Type: AS_t_PixelData
//- Description:  type for 16bit imager pixel data (with 12 data lines connected)
//- Resolution:  12bit  @unit: -  @min: 0  @max: 4095
typedef uint16 AS_t_PixelData;
/*#]*/


//**************************************************************************
//Type: AS_EVE_MAX_DST_BUFFER
//Definition of eve service maximum destination buffer
#define AS_EVE_MAX_DST_BUFFER  (32u)


//**************************************************************************
//Type: AS_EVE_MAX_SRC_BUFFER
//Definition of eve service maximum source buffer
#define AS_EVE_MAX_SRC_BUFFER  (12u)


//**************************************************************************
//Type: AS_t_EVEBufferInfo
//Abstract type for EVE buffers
typedef struct
{
  void * p_Buff;       /* Pointer to buffer        */
  uint32 u_BuffLength; /* Length of buffer [bytes] */
} AS_t_EVEBufferInfo;


//**************************************************************************
//Type: AS_t_EVEParams
//Set of parameters and buffers, which is passed to the ARP32/EVE algo component.
typedef struct
{
  uint32 u_LocalFuncID;                             /* Algo internal function ID, which is requested */
  AS_t_EVEBufferInfo parBuf;                        /* EVE algo parameter buffer                     */
  AS_t_EVEBufferInfo srcBuf[AS_EVE_MAX_SRC_BUFFER]; /* Array of source buffers                       */
  AS_t_EVEBufferInfo dstBuf[AS_EVE_MAX_DST_BUFFER]; /* Array of destination buffers                  */
} AS_t_EVEParams;


//**************************************************************************
//Type: AS_t_EVEContainer
//Container structure, which is used to pass parameters, buffers and other data
//from ARM/DSP to ARP32 (EVE).
typedef struct
{
  AS_t_IfVersionNum u_VersionNumber; /* EVE interface version number */
  AS_t_EVEParams eveParams;          /* Parameter structure, which is passed to ARP32/EVE algo component */
} AS_t_EVEContainer;


//**************************************************************************
//Type: AS_t_EVEError
//Return codes of of eve service
typedef enum
{
  EVE_NO_ERROR = 0,
  EVE_ERROR    = 1,
  EVE_ABORTED  = 2,
  EVE_ERROR_FORCE_32 = 65536
}AS_t_EVEError;


//**************************************************************************
//Type: AS_t_EVETrigger
//Prepares EVE-function of interest and specifies input and output buffers and schedules
//this job to the ARP32/EVE. Running jobs or scheduled jobs with higher priority will be
//finished before this job is actually executed on the EVE.
//
//OCM usage:
//  A part of 256kByte EVE OCM RAM is implicitely used, only by algorithm function on EVE
//  (no sharing of EVE OCM between ARP32 and DSP/ARM)
//
//
//Parameter:     p_Container <IN>.
//Description:   Contains info about source-/dest-buffers and function ID
//
//Parameter:     p_Handle <OUT>.
//Description:   Returns an handle identifying the current job, which has to be passed to
//               EVEWait() later.
//
//Parameter:     u_ComponentId <IN>.
//Description:   Identifies the component, which calls this service function. It will be
//               used to select the library on the ARP32/EVE side, which will be called.
//               The component IDs (COMP_ID_*) from file 'glob_comp_id.h' must be used.
typedef AS_t_EVEError (*AS_t_EVETrigger) (const AS_t_EVEContainer *p_Container, sint32 *p_Handle, uint32 u_ComponentId);


//**************************************************************************
//Type: AS_t_EVEWait
//Blocks algorithm (and hands over control to OS-scheduler), until selected job is finished.
//
//Parameter:     u_Handle <IN>.
//Description:   The job-handle, on which this function waits for completion.
//
//Parameter:     p_EveLibReturnCode <OUT>.
//Description:   Returns the return value of the algorithm wrapper (Exec-function) on ARP32
typedef AS_t_EVEError (*AS_t_EVEWait) (sint32 u_Handle, sint32 *p_EveLibReturnCode);


//**************************************************************************
//Type: AS_t_EVEAbort
//Removes the EVETrigger request from the EVE queue. If the specified EVE trigger was
//scheduled alreay and is running on EVE nothing shall happen.
//
//Parameter:     u_Handle <IN>.
//Description:   The job-handle, for which this function aborts for completion.
typedef AS_t_EVEError (*AS_t_EVEAbort) (sint32 u_Handle);


//**************************************************************************
//Type: MEASVirtualAdress_t
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef uint32 MEASVirtualAdress_t;


//**************************************************************************
//Type: MEASLength_t
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef uint32 MEASLength_t;


//**************************************************************************
//Type: MEASFuncID_t
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
//typedef uint8 MEASFuncID_t;


//**************************************************************************
//Type: MEASFuncChannelID_t
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
//typedef uint8 MEASFuncChannelID_t;


//**************************************************************************
//Type: MEAS_Callback_t
//Pointer to Callback function for notification
//typedef void (*MEAS_Callback_t)(void);


//**************************************************************************
//Type: GetTimeMicroSec_t
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef uint32 (*GetTimeMicroSec_t) (void);


//**************************************************************************
//Type: AS_t_RtaEventType
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)

/*#[ type AS_t_RtaEventType */
typedef RTA_t_Events AS_t_RtaEventType;

//**************************************************************************
//Type: AS_t_Dem_ReturnType
//Return values of dem interface
typedef uint8 AS_t_Dem_ReturnType;


//**************************************************************************
//Type: AS_t_Dem_EventIDType
//IDs of dems, (test).
//Generated with cessar: unique for SoC: SW and Algo
typedef uint16 AS_t_Dem_EventIDType;


//**************************************************************************
//Type: AS_t_Dem_EventStatusType
//Satus of test: passed, not passed
typedef enum
{
  DEM_EVENT_STATUS_PASSED   = 0,
  DEM_EVENT_STATUS_FAILED    = 1,
  DEM_EVENT_STATUS_LASTENTRY  = 65536
}AS_t_Dem_EventStatusType;


//**************************************************************************
//Type: AS_t_Dem_SetEventStatus
//Definition of Algo Sevice: SetEventStatus
// - Event ID (In)
// - Event Status (In)
typedef AS_t_Dem_ReturnType (*AS_t_Dem_SetEventStatus) (const AS_t_Dem_EventIDType u_Dem_EventIdRaw, 
                                   const AS_t_Dem_EventStatusType u_Dem_EventStatus);


//**************************************************************************
//Type: AS_t_Dem_SetEventStatusPreExtData
//Definition of Algo Sevice: SetEventStatusPreExtData
// - Event ID (In)
// - Event Status (In)
// - Pre Extended Data Ptr (In)
// - Size of Pre Ext Data (In)
typedef AS_t_Dem_ReturnType (*AS_t_Dem_SetEventStatusPreExtData) (const AS_t_Dem_EventIDType u_Dem_EventIdRaw, 
                                   const AS_t_Dem_EventStatusType u_Dem_EventStatus, 
                                   const uint8* const p_Dem_pui8_PreExtData, 
                                   uint8 u_Dem_PreExtDataSize);


//**************************************************************************
//Type: AS_t_RTAAlgoServiceAddEvent
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef sint32 (*AS_t_RTAAlgoServiceAddEvent)(const AS_t_RtaEventType RtaEvtType, const uint8 u_IdGlobal, const uint8 u_IdLocal, const uint8 u_OptData);


//**************************************************************************
//Type: AS_t_MeasErrors
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef enum  {
    e_MEAS_OK                           = 0, //No error - anything ok
    e_MEAS_ALREADY_INIT                 = 1, //The module has been already initialized
    e_MEAS_PTR_INVALID                  = 2, //Any provided pointer is invalid
    e_MEAS_READPTR_OUT_OF_RANGE         = 3, //The read pointer of ringbuffer is out of range
    e_MEAS_BUFFER_FULL                  = 4, //The meas ringbuffer is full
    e_MEAS_NOT_INIT                     = 5, //The module has not been initialized up to now
    e_MEAS_MESSAGE_NOT_SENT             = 6, //The message hasn't been sent
    e_MEAS_TASK_ID_OUT_OF_RANGE         = 7, //The provided task id is out of range
    e_MEAS_FEX_MESSAGE_NOT_FREE         = 8, //The fex message is not free, that one received before has not been sent
    e_MEAS_FEX_MESSAGE_BUFFER_FULL      = 9, //The ringbuffer for fexMessages is full - no free entry left
    e_MEAS_FEX_NOTIFY_ERROR             = 10, //Notification error of fex Messages
    e_MEAS_FEX_RUN_TIME_MSG_BUFFER_FULL = 11, //The msg buffer is full - previous msg hasn't been sent, current freeze is not possible
    e_MEAS_NO_FEX_RUNTIME_MSG           = 12, //This virtual address is no fexRuntimeMessage - implementation error!
    e_MEAS_MSG_BLOCK_ID_OUT_OF_RANGE    = 13, //The received msgBlockId is out of range
    e_MEAS_NO_FEX_RUNTIME_MSG_TO_SEND   = 14, //Currently there is no fexRuntimeMsg to send - task triggered by mistake
    e_ARRAY_INDEX_OUT_OF_BOUNDS         = 15, //Local Array Index Out of Bounds
    e_MEAS_MCU_SIZE_WRONG               = 16, //Size of MEAS from MCU exceeded the maximum expected size
    e_MEAS_NO_FEX_STARTUP_MSG_TO_SEND   = 17, //Currently there is no fexStartupMsg to send
    e_MEAS_WRITEPTR_OUT_OF_RANGE        = 18, //Currently there is no fexStartupMsg to send
    e_MEAS_BLOCKSIZE_MEASINFO_MISSMATCH = 19, //The block sizes passed to e_fpgaSendEmergencyData() do not match the value in p_MeasInfo
    e_MEAS_FREEZE_BEFORE_CYCLE_START    = 20, //Until meas cycle was started meas freezes will be ignored
    e_MEAS_BUDGET_EXCEEDED              = 21, //task budget was violated
    e_MEAS_ILLEGAL_ARGUMENTS            = 90, //Generic error code: Illegal arguments passed to function
    e_MEAS_GENERIC_ERROR                = 99, //Generic error code: Unspecified error occurred
    e_MEAS_FORCE_32 = 0x1FFFF //Only to force 4 byte size
} AS_t_MeasErrors;

//**************************************************************************
//Type: AS_t_MeasReturn
//Return values of Meas interface functions
/*## type AS_t_MeasReturn */
typedef MEASReturn_t AS_t_MeasReturn;

//**************************************************************************
//Type: AS_t_MeasCallback
//Pointer to Callback function for notification
/*#[ type AS_t_MeasCallback */
typedef MEAS_Callback_t AS_t_MeasCallback;

//**************************************************************************
//Type: AS_t_MeasFuncChannelID
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
/*## type AS_t_MeasFuncChannelID */
typedef MEASFuncChannelID_t AS_t_MeasFuncChannelID;

//**************************************************************************
//Type: AS_t_MeasFuncID
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
/*## type AS_t_MeasFuncID */
typedef MEASFuncID_t AS_t_MeasFuncID;

//**************************************************************************
//Type: AS_t_MeasLength
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef uint32 AS_t_MeasLength;


//**************************************************************************
//Type: AS_t_MeasVirtualAdress
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef uint32 AS_t_MeasVirtualAdress;


//**************************************************************************
//Type: AS_t_MeasInfo
//Detailed header information of measurement data
/*#[ type AS_t_MeasInfo */
typedef MEASInfo_t AS_t_MeasInfo;

//**************************************************************************
//Type: AS_t_MeasHdlr
//Definition of Algo Sevice: Meas Freez
//- Meas Info Ptr [In]
//- Data Ptr [In]
//- Meas Callback - notification [In]
typedef AS_t_MeasReturn (*AS_t_MeasHdlr)(const AS_t_MeasInfo * const, const void *, AS_t_MeasCallback);


//**************************************************************************
//Type: AS_t_MeasStartFuncCycle
//Definition of Algo Sevice: Meas StartFuncCycle
//- Function ID used by algo [In]
typedef AS_t_MeasErrors (*AS_t_MeasStartFuncCycle)(const AS_t_MeasFuncID);


//**************************************************************************
//Type: MEASReturn_t
//Return values of Meas interface functions
/*#[ type MEASReturn_t */
//typedef AS_t_MeasReturn MEASReturn_t;


//**************************************************************************
//Type: MEASInfo_t
//Detailed header information of measurement data
//typedef AS_t_MeasInfo MEASInfo_t;


//**************************************************************************
//Type: MeasHdlr_t
//Definition of Algo Sevice: Meas Freez
//- Meas Info Ptr [In]
//- Data Ptr [In]
//- Meas Callback - notification [In]
typedef MEASReturn_t (*MeasHdlr_t)(const MEASInfo_t *, void *, MEAS_Callback_t);


//**************************************************************************
//Type: AS_t_Sched_SubMode
//Return codes of of eve service
typedef enum
{
  AS_SAC_BSW_STANDALONE   = 1,
  AS_SAC_BSW_PARALLEL     = 2,
  AS_DIAG_BSW_ECM          = 3,
  AS_DIAG_BSW_ECS      = 4,
  AS_DIAG_BSW_EC_BOTH    = 5,
  AS_DIAG_BSW_DISTTEST    = 6,
  AS_SCHEDSUBMODE_LASTENTRY = 65536
}AS_t_Sched_SubMode;


//**************************************************************************
//Type: AS_t_TaskEventID
//- Description:  Task events comming asynch, to which task has to wait
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef enum { 
  e_TASKEVT_FPGA_DISABLE         = 0,
  e_TASKEVT_FPGA_ENABLE          = 1,
    e_TASKEVT_FPGA_CLASSIFIER_INIT = 2,
    e_TASKEVT_LAST_ENTRY            = 65536
} AS_t_TaskEventID;


//**************************************************************************
//Type: AS_t_EVELibExecFunc
//Prototype of algo EVE library execute function (main entry function of library)
//
//Parameter:     p_Container <IN>.
//Description:   Contains info about source-/dest-buffers and function ID.
//               This is passed from the client algo library to the EVE library.
typedef sint32 (*AS_t_EVELibExecFunc)(const AS_t_EVEContainer* p_Container);


//**************************************************************************
//Type: AS_t_MemScratchReqPort
//Definition of memory scratch locking service required port.
//
//Parameter:     u_compId <IN>.
//Description:   The component identifier (COMP_ID_*) from file 'glob_comp_id.h' must be used.
//
//Parameter:     u_memReqId <IN>.
//Description:   The memory request identifier from file 'MFC_Memlock.xml' must be used.
//
//Parameter:     u_sizeL2 <IN>.
//Description:   The needed L2 memory size (number of bytes). It must be zero when memory is not needed.
//
//Parameter:     u_sizeL3 <IN>.
//Description:   The needed L3 memory size (number of bytes). It must be zero when memory is not needed.
//
//Parameter:     b_condWait <IN>.
//Description:   When it is desired to wait for the memory this signal must be 'TRUE'.
typedef struct
{
  uint32  u_compId;
  uint32  u_memReqId;
  uint32  u_sizeL2;
  uint32  u_sizeL3;
  boolean b_condWait;
} AS_t_MemScratchReqPort;


//**************************************************************************
//Type: AS_t_MemScratchProPort
//Definition of memory scratch locking service provided port.
//
//Parameter:     p_memL2 <OUT>.
//Description:   Pointer to the L2 memory. It will be zero when L2 memory was not requested.
//
//Parameter:     p_memL3 <OUT>.
//Description:   Pointer to the L3 memory. It will be zero when L3 memory was not requested.
//
//Parameter:     u_sizeL2 <OUT>.
//Description:   The L2 memory size. It must be zero when memory was not requested.
//
//Parameter:     u_sizeL3 <OUT>.
//Description:   The L3 memory size. It must be zero when memory was not requested.
//
/*#[ type AS_t_MemScratchProPort */
typedef struct
{
  void * p_memL2;
  void * p_memL3;
  uint32 u_sizeL2;
  uint32 u_sizeL3;
} AS_t_MemScratchProPort;


//**************************************************************************
//Type: AS_t_MemScratchReturnCode
//Definition of memory scratch service return code.
typedef enum
{
  AS_MEM_SCRATCH_SRV_SUCCESS       =  0,     /* Service returns without error            */
  AS_MEM_SCRATCH_SRV_NOT_AVL       =  1,     /* Service is not available for use         */
  AS_MEM_SCRATCH_ERR_ID_IN_USE     =  2,     /* Component-Id already in use (lock error) */
  AS_MEM_SCRATCH_ERR_ID_NOT_IN_USE =  4,     /* Component-Id not in use (unlock error)   */
  AS_MEM_SCRATCH_ERR_L2_SIZE       =  8,     /* Requested memory size is too big         */
  AS_MEM_SCRATCH_ERR_L3_SIZE       = 16,     /* Requested memory size is too big         */
  AS_MEM_SCRATCH_L2_NOT_FREE       = 32,     /* L2 memory is not free                    */
  AS_MEM_SCRATCH_L3_NOT_FREE       = 64,     /* L3 memory is not free                    */
  AS_MEM_SCRATCH_FORCE_32BIT       = 0x1FFFF /* Force 32 bit                             */
} AS_t_MemScratchReturnCode;


//**************************************************************************
//Type: AS_t_MemScratchLock
//Definition of memory scratch service locking function. It replaces the previous service 
//types AS_t_MemLock, AS_t_MemLockL2 and AS_t_MemLockL3. 
//
//Parameter:     p_reqPort <IN>.
//Description:   Required port which has to be passed to the service. For details see datatype definition.
//
//Parameter:     p_proPort <OUT>.
//Description:   Provided port which will be returned by the service. For details see datatype definition.
typedef AS_t_MemScratchReturnCode (*AS_t_MemScratchLock) ( const AS_t_MemScratchReqPort * const reqPort, AS_t_MemScratchProPort * const proPort );


//**************************************************************************
//Type: AS_t_MemScratchUnlock
//Definition of memory scratch service unlocking function. It replaces the previous service 
//types AS_t_MemUnlock, AS_t_MemUnlockL2 and AS_t_MemUnlockL3.
//
//Parameter:     u_compId <IN>.
//Description:   The component identifier (COMP_ID_*) from file 'glob_comp_id.h' must be used.
//
//Parameter:     u_memReqId <IN>.
//Description:   The memory request identifier from file 'MFC_Memlock.xml' must be used.
typedef AS_t_MemScratchReturnCode (*AS_t_MemScratchUnlock) ( const uint32 u_compId, const uint32 u_memReqId );


//**************************************************************************
//Type: AS_t_EDMAGet
//Definition of EDMA service function EDMAGet(..). This service function can be used to get the handle to a DMA channel.
//
//Parameter:     Flags
//Description:   DMA or QDMA.
//
//Parameter:     Regs
//Description:   Pointer to the EDMA handle.
//Return value:  Signed integer.
//Description:   The service function returns the following error values:
//               s_NOERROR                     (0): Service function exits without any error.
//               s_ERROR_EDMASERVICE          (11): Service function not available.
//               s_ERROR_CHANNELPOOL_EXHAUSED (13): Service function not available due to reserved channels.
typedef sint32 (*AS_t_EDMAGet) (AS_t_EdmaFlags Flags, AS_t_EdmaHandle * Regs);


//**************************************************************************
//Type: AS_t_EDMARelease
//Definition of EDMA service function EDMARelease(..). This service function can be used to release the DMA channel.
//
//Parameter:     Regs
//Description:   Pointer to the EDMA handle.
//Return value:  Signed integer.
//Description:   The service function returns the following error values:
//               s_NOERROR                     (0): Service function exits without any error.
//               s_ERROR_EDMASERVICE          (11): Service function not available.
//               s_ERROR_CHANNELPOOL_EXHAUSED (13): Service function not available due to reserved channels.
//               s_ERROR_CHANNEL_NOTINUSE     (14): Service function not able to find the channel to release.
typedef sint32 (*AS_t_EDMARelease) (AS_t_EdmaHandle * Regs);


//**************************************************************************
//Type: AS_t_EDMATranslateAddress
//Definition of EDMA service function EDMATranslateAddress(..). This service function translates the memory address from CPU perspective to EDMA perspective.
//
//Parameter:     Addr
//Description:   Address that needs to be translated.
//Return value:  Unsigned integer.
//Description:   The service function returns the translated address.
typedef void * (*AS_t_EDMATranslateAddress) (void * Addr);


//**************************************************************************
//Type: AS_t_ServiceFuncts
//- Description:  short description, meaning, usage
//- Range:    range of variable (Min - Max) based on raw value
//- Resolution:  resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:    physical unit (e.g. m/s^2)
typedef struct
{
    AS_t_MeasHdlr                     pfMeasFreeze;
    AS_t_CacheInv                     pfCacheInv;
    AS_t_CacheWbInv                   pfCacheWbInv;
    AS_t_CacheWbInvAll                pfCacheWbInvAll;
    AS_t_Dem_SetEventStatus           pfDem_SetEventStatus;
    AS_t_Dem_SetEventStatusPreExtData pfDem_SetEventStatusPreExtData;
    AS_t_EDMACopy                     pfEDMACopy;
    AS_t_EDMACopy2D                   pfEDMACopy2D;
    AS_t_EDMACopyChained              pfEDMACopyChained;
    AS_t_EDMAMemSet                   pfEDMAMemSet;
    AS_t_EDMAWait                     pfEDMAWait;
    AS_t_EVETrigger                   pfEVETrigger;
	AS_t_EVEAbort                     pfEVEAbort;
    AS_t_EVEWait                      pfEVEWait;
    AS_t_RTAAlgoServiceAddEvent       pfRTAAlgoServiceAddEvent;
    AS_t_MeasStartFuncCycle           pfMeasStartFuncCycle;
    AS_t_MemScratchLock               pfMemScratchLock;
    AS_t_MemScratchUnlock             pfMemScratchUnlock;
    AS_t_EDMAGet                      pfEDMAGet;
    AS_t_EDMARelease                  pfEDMARelease;
    AS_t_EDMATranslateAddress         pfEDMATranslateAddress;
} AS_t_ServiceFuncts;


// **************************************************************************
// Version number of eve interface
#define AS_EVE_IFVERSION 1u

// **************************************************************************
// Version number of eve interface
#define AS_SERVICEFUNC_VERSION 9u

/***    User explicit entries    ***/


#ifdef __cplusplus
}
#endif

#endif

