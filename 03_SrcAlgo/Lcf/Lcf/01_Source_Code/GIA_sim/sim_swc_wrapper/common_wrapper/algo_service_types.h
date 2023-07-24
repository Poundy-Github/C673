// **********************************************************************
// 
//COMPANY:     Continental Automotive , 
// 
//PROJECT:     SOC_M3_Infrastructure
//    
//CPU:         MPC5674x
// 
//Component:   SOC_M3_Infrastructure_C_cmp
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

/*## dependency glob_type */
#include "glob_type.h"
/*## package Types_Pkg */

/*## class TopLevel::algo_service_types */
/*#[ ignore */
//Description:        Definition of algo services (callbacks)
//Integration notes:  The types are used from modules implementing services
//Package prefix:     -
/*#]*/

#ifdef __cplusplus
extern "C"
{
#endif

//**************************************************************************
//Type: AS_t_IfVersionNum
//Service interface version number
/*## type AS_t_IfVersionNum */
typedef uint32 AS_t_IfVersionNum;

//**************************************************************************
//Type: AS_t_EDMACopy
//Definition of Algo Sevice: EDMACopy
// - Dst Buffer Ptr (In)
// - Src Buffer Ptr (In)
// - Buffer Size (In)
// - Channel Index (In/Out)
//
/*#[ type AS_t_EDMACopy */
typedef sint32 (*AS_t_EDMACopy) (void *p_Dst, void *p_Src, sint32 s_SizeBytes, sint32 *p_ChIndexOut);
/*#]*/

//**************************************************************************
//Type: AS_t_EDMACopy2D
//Definition of Algo Sevice: EDMACopy2D
// - Dst Buffer Ptr (In)
// - Src Buffer Ptr (In)
// - Dst Pitch (In)
// - Src Pitch (In)
// - Width (In)
// - Height (In)
// - Channel Index (In/Out)
//
/*#[ type AS_t_EDMACopy2D */
typedef sint32 (*AS_t_EDMACopy2D) (void *p_Dst, void *p_Src, sint32 s_DstPitch, sint32 s_SrcPitch, sint32 s_Width, sint32 s_Height, sint32 *p_ChIndexOut);
/*#]*/

//**************************************************************************
//Type: AS_t_EDMACopyChained
//Definition of Algo Sevice: EDMACopyChain
// - PreDst Buffer Ptr (In)
// - PreSrc Buffer Ptr (In)
// - PreBuffer Size (In)
// - PostDst Buffer Ptr (In)
// - PostSrc Buffer Ptr (In)
// - PostBuffer Size (In)
// - PostChannel Index (In/Out)
//
/*#[ type AS_t_EDMACopyChained */
typedef sint32 (*AS_t_EDMACopyChained) (void *p_PreDst, void *p_PreSrc, sint32 s_PreNumBytes, void *p_PostDst, void *p_PostSrc, sint32 s_PostNumBytes, sint32 *p_PostChIndexOut);
/*#]*/

//**************************************************************************
//Type: AS_t_EDMAWait
//Definition of Algo Sevice: EDMAMemSet
// - Channel Index (In)
//
/*#[ type AS_t_EDMAWait */
typedef sint32 (*AS_t_EDMAWait) (sint32 s_ChIndex);
/*#]*/

//**************************************************************************
//Type: AS_t_EDMAMemSet
//Definition of Algo Sevice: EDMAMemSet
// - Dst Buffer Ptr (In)
// - Pattern (In)
// - Transfer count (In)
// - Channel Index (In/Out)
//
/*#[ type AS_t_EDMAMemSet */
typedef sint32 (*AS_t_EDMAMemSet) (void *p_MemLoc, uint32 u_Pattern, sint32 s_TransferCnt, sint32 *p_ChIndexOut);
/*#]*/

//**************************************************************************
//Type: AS_t_CacheInv
//Definition of Algo Sevice: Cache Invalidate
// - Ext Memory Buffer Ptr (In)
// - Size of Ext Memory (In)
//
/*#[ type AS_t_CacheInv */
typedef void (*AS_t_CacheInv) (void *p_MemLoc, uint32 u_NumBytes);
/*#]*/

//**************************************************************************
//Type: AS_t_CacheWbInv
//Definition of Algo Sevice: Cache Writeback Invalidate
// - Ext Memory Buffer Ptr (In)
// - Size of Ext Memory (In)
//
/*#[ type AS_t_CacheWbInv */
typedef void (*AS_t_CacheWbInv) (void *p_MemLoc, uint32 u_NumBytes);
/*#]*/

//**************************************************************************
//Type: AS_t_CacheWbInvAll
//Definition of Algo Sevice: Cache Writeback Invalidate All
// - No parameters
//
/*#[ type AS_t_CacheWbInvAll */
typedef void (*AS_t_CacheWbInvAll) (void);
/*#]*/

#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: AS_t_GetTimestampuS
//Definition of Algo Sevice: Get Timestamp us
// - No parameters
//
/*#[ type AS_t_GetTimestampuS */
 typedef uint64 (*AS_t_GetTimestampuS) (void);
/*#]*/

#endif /*CODING_GUIDLINE_4 */
//**************************************************************************
//Type: AS_t_GetCoreTicksuS64
//Definition of Algo Sevice: Get Core Ticks
// - No parameters
//
/*#[ type AS_t_GetCoreTicksuS64 */
 typedef uint64 (*AS_t_GetCoreTicksuS64) (void);
/*#]*/

//**************************************************************************
//Type: AS_t_PixelData
//- Description:  type for 16bit imager pixel data (with 12 data lines connected)
//- Resolution:	12bit  @unit: -  @min: 0  @max: 4095
//
/*#[ type AS_t_PixelData */
typedef uint16 AS_t_PixelData;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiBufferType
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_RoiBufferType */
typedef enum
{
  ROI_SINGLE,                 /*!< Roi has only one local buffer. */
  ROI_TOGGLE,                 /*!< Roi has toggle buffer memory. */
  ROI_MODULO,                 /*!< Roi has toggle buffer plus ringbuffer, execution of ringbuffer callback function on highes prio., roi callback on  task prio. */
  ROI_ASYNCHRONOUS,           /*!< legacy, don't use! */
  ROI_FIFO,                   /*!< FIFO is used (MCU used with DRI) */
  ROI_NO_BUFFER,              /*!< Roi has no local buffer memory, Data source is image pointer */
  ROI_FIFO_STATIC_SUB         /*!< Static sub ROI of ROI_FIFO which is used for icons on M32 with DRI to hold parts of the entire ROI without being overwritten */
}  AS_t_RoiBufferType;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiMainCallBk
//Pointer to Callback function for notification)
//
/*#[ type AS_t_RoiMainCallBk */
typedef void  (* AS_t_RoiMainCallBk)(void) ;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiErrorFlags
//- Description:	ROI error flags
//
/*#[ type AS_t_RoiErrorFlags */
typedef struct
{
  ubit32  ucRoiMissedRealtime               : 1;  /*!< signaling the algoritm, that last processing was too long */
  ubit32  ucRoiTimeout                      : 1;  /*!< signal to monitoring, that this Roi has hang up */
  ubit32  ucRoiNumberOfDroppedFrames        : 8;  /*!< eight bit valid if ucRoiTimeout==TRUE */
  ubit32  ucRoiExposureTimePlausiblitiyCeck : 1;  /*!< signal to monitoring, that there is a mismatch of frame number and brightness of current frame in relation to previous frame */
  ubit32  ucRoiTableNotEmpty                : 8;  /*!< eight bit in ucfRoiTableNotEmpty reserved*/
  ubit32  ucRoiError;
  ubit32  u32RoiDataUseStatus;
} AS_t_RoiErrorFlags;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiFlags
//- Description: ROI flag structure
//
/*#[ type AS_t_RoiFlags */
typedef struct
{
  ubit32            ucfMemType          : 1;  /*!< one bit in char for MemType reserved */
  ubit32            ucfToggleSingle     : 1;
  ubit32            ucfProcessRunning   : 1;  /*!< togglebuffer-switch although still processing? 1->wait, 0->don't wait */
  ubit32            ucfOnOff            : 1;  /*!< ROI is active: TRUE -> data is beeing extracted from frame, set by framework, can be polled in application control task */
  ubit32            ucfResolution       : 2;
  ubit32            ucfDMADone          : 1;  /*!< DMA is done, used by framework, ISR resets this flag */
  AS_t_RoiErrorFlags   strErrFlags;
} AS_t_RoiFlags;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiBase
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_RoiBase */
typedef struct
{
  uint16            usX1;
  uint16            usX2;
  uint16            usWidth;
  uint16            usY1;
  uint16            usY2;
  uint16            usHeight;
} AS_t_RoiBase;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiCallBk
//Pointer to Callback function for notification
//
/*#[ type AS_t_RoiCallBk */
typedef void  (* AS_t_RoiCallBk)(void * param) ;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiDataUseErr
//- Description:	ROI error codes
//
/*#[ type AS_t_RoiDataUseErr */
typedef enum
{
  ROI_NO_ERR=0,
  ROI_NO_USEFULL_DATA,
  ROI_XY1_GREATER_XY2,
  ROI_ROI_TO_BIG,
  ROI_DATA_OUT_OF_PICTURE,
  ROI_DATA_OUT_OF_ROIDEF,
  ROI_DATA_MEM_SIZE_OVFL,
  ROI_COUNT_MAX_OVFL,
  ROI_DATA_WIDTH_OUT_OF_PICT,
  ROI_NO_USEFUL_USER_DATA,
  ROI_MAX_NUM_ERR,
  ROI_HAL_ERROR
}  AS_t_RoiDataUseErr;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiDescriptor
//- Description:	ROI descriptor
//
/*#[ type AS_t_RoiDescriptor */
typedef struct
{
  AS_t_RoiBase         strBaseDesc;            /*!< Rectangle */
  AS_t_RoiFlags        strFlagsDesc;           /*!< flags */
  boolean              bSwitchedOn;            /*!< Roi will be updated or not */
  AS_t_RoiBufferType   enumToggleSingle;       /*!< Toggle functionality mode */
  uint16               usModuloCnt;            /*!< Number of rows to collect per modulo application fuction call */
  uint16               usModuloHeight;         /*!< Number of rows which should be stored in FIFO */
  uint16               usModuloWidth;          /*!< Number of columns which should be stored in one FIFO row */
  uint16               usRingBufThreshold;     /*!< max. number of rows between read and write pointer */
  uint32               u32RoiSize;             /*!< For MEM_free */
  uint32               u32ModuloSize;          /*!<  */
  AS_t_RoiCallBk       pfctFuncPreprocRoi;     /*!< pointer to final line function */
  AS_t_RoiCallBk       pfctFuncPreprocToggleRoi; /*!< pointer to pre-process line function */
  AS_t_RoiMainCallBk   pfctFuncMain;           /*!< Pointer to main function */
  uint32               u32Id;                  /*!< Identifier, its free to the user to set this id to identify the window in the application */
  void               * pApp;                   /*!< Pointer to application specific Roi-information, its free to be used by the application */
  AS_t_RoiDataUseErr   enumRoiDataUseErr;
} AS_t_RoiDescriptor;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiUser
//- Description: ROI User Descriptor
//
/*#[ type AS_t_RoiUser */
typedef struct
{
  AS_t_RoiDescriptor   strFromApp;
  AS_t_RoiDescriptor   strToApp;
} AS_t_RoiUser;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiHandle
//- Description: ROI pointer
//
/*#[ type AS_t_RoiHandle */
typedef AS_t_RoiUser * AS_t_RoiHandle;
/*#]*/

//**************************************************************************
//Type: AS_t_RoiPipElem
//- Description: ROI PIP Element
//
/*#[ type AS_t_RoiPipElem */
typedef struct
{
  AS_t_RoiHandle      pRoiHandle;             /*!< Pointer to ROI informations */
  AS_t_PixelData     * pData;                  /*!< Pointer to ROI FIFO start + line offs */
  AS_t_PixelData     * pImageData;             /*!< Pointer to ROI FIFO start (start of complete image in fifo) */
  AS_t_PixelData     * pCurrLine;              /*!< Pointer to start of current image line */
  uint16            usRoiRow;               /*!< Current row in roi. Set before calling modulo processing functions */
  sint32          * pi32References;         /*!< how many ROI are still owner of ImageData (source of ROI) */
  uint32            ui32frameNumber;        /*!< Frame number count (output of IA driver, synchronized to Embedded data) */
  uint32            ui32FrameTimeStamp;     /*!< Frame time stamp (1µs resolution) */
  uint32            ui32CallbackTimeStamp;  /*!< Timestamp, capturing algo callback function time (1µs resolution) */
  AS_t_RoiCallBk     pfctFuncPrep;           /*!< Pointer to func */
  uint16            ui16CurrentMargin;      /*!< Current fifo margin (fill level) - if(ui16CurrentMargin < usRingBufThreshold)=>ABORT */
  boolean           bAborted;               /*!< calling of pre-proc aborted (sampling continues for algo with whole image processing) */
} AS_t_RoiPipElem;
/*#]*/

//**************************************************************************
//Type: AS_EVE_MAX_DST_BUFFER
//Definition of eve service maximum destination buffer
/*#[ type AS_EVE_MAX_DST_BUFFER */
#define AS_EVE_MAX_DST_BUFFER  (32u)
/*#]*/

//**************************************************************************
//Type: AS_EVE_MAX_SRC_BUFFER
//Definition of eve service maximum source buffer
/*#[ type AS_EVE_MAX_SRC_BUFFER */
#define AS_EVE_MAX_SRC_BUFFER  (8u)
/*#]*/

//**************************************************************************
//Type: AS_t_EVEBufferInfo
//Abstract type for EVE buffers
/*#[ type AS_t_EVEBufferInfo */
typedef struct
{
  void * p_Buff;       /* Pointer to buffer        */
  uint32 u_BuffLength; /* Length of buffer [bytes] */
} AS_t_EVEBufferInfo;
/*#]*/

//**************************************************************************
//Type: AS_t_EVEParams
//Set of parameters and buffers, which is passed to the ARP32/EVE algo component.
/*#[ type AS_t_EVEParams */
typedef struct
{
  uint32 u_LocalFuncID;                             /* Algo internal function ID, which is requested */
  AS_t_EVEBufferInfo parBuf;                        /* EVE algo parameter buffer                     */
  AS_t_EVEBufferInfo srcBuf[AS_EVE_MAX_SRC_BUFFER]; /* Array of source buffers                       */
  AS_t_EVEBufferInfo dstBuf[AS_EVE_MAX_DST_BUFFER]; /* Array of destination buffers                  */
} AS_t_EVEParams;
/*#]*/

//**************************************************************************
//Type: AS_t_EVEContainer
//Container structure, which is used to pass parameters, buffers and other data
//from ARM/DSP to ARP32 (EVE).
/*#[ type AS_t_EVEContainer */
typedef struct
{
  AS_t_IfVersionNum u_VersionNumber; /* EVE interface version number */
  AS_t_EVEParams eveParams;          /* Parameter structure, which is passed to ARP32/EVE algo component */
} AS_t_EVEContainer;
/*#]*/

//**************************************************************************
//Type: AS_t_EVEError
//Return codes of of eve service
/*#[ type AS_t_EVEError */
typedef enum
{
  EVE_NO_ERROR = 0,
  EVE_ERROR
}AS_t_EVEError;
/*#]*/

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
/*#[ type AS_t_EVETrigger */
typedef AS_t_EVEError (*AS_t_EVETrigger) (const AS_t_EVEContainer *p_Container, sint32 *p_Handle, uint32 u_ComponentId);
/*#]*/

//**************************************************************************
//Type: AS_t_EVEWait
//Blocks algorithm (and hands over control to OS-scheduler), until selected job is finished.
//
//Parameter:     u_Handle <IN>.
//Description:   The job-handle, on which this function waits for completion.
//
//Parameter:     p_EveLibReturnCode <OUT>.
//Description:   Returns the return value of the algorithm wrapper (Exec-function) on ARP32
//
//
//
/*#[ type AS_t_EVEWait */
typedef AS_t_EVEError (*AS_t_EVEWait) (sint32 u_Handle, sint32 *p_EveLibReturnCode);
/*#]*/

//**************************************************************************
//Type: AS_t_EVEExclusiveClose
//Finish exclusive usage and free allocated OCM memory. From up there, EVE is available
//for other algorithms / processings.
/*#[ type AS_t_EVEExclusiveClose */
typedef AS_t_EVEError (*AS_t_EVEExclusiveClose) (void);
/*#]*/

//**************************************************************************
//Type: AS_t_EVEExclusiveOpen
//This function blocks algorithm (and hands over control to OS-scheduler), until EVE is available.
//When EVE is avaiable, it prepares EVE-function of interest and specifies input and output buffers.
//
//OCM usage:
//  OCM is used by algorithm function on ARP32 and DSP/ARM
//  (sharing of OCM between ARP32 and DSP/ARM for ping/pong)
//
//
//Parameter:     p_Container <IN>.
//Description:   - Contains info about buffers and local function ID
//
//Parameter:     p_pBuffDsp2Eve <OUT>.
//Description:   - SW provides pointer to ping EVE OCM, which has to be filled by algo on DSP
//
//Parameter:     u_Buffsize <IN>.
//Description:   - Algo specifies total size of required ping-buffer in bytes
//                 (actually the double amount of RAM is needed => ping/pong)
//               - SW-service checks, whether enough OCM is available
//
//Parameter:     u_ComponentId <IN>.
//Description:   Identifies the component, which calls this service function. It will be used to
//               select the library on the ARP32/EVE side, which receives all subsequent calls to
//               'EVEExclusiveTrigger()'. The component IDs (COMP_ID_*) from file 'glob_comp_id.h'
//               must be used here.
/*#[ type AS_t_EVEExclusiveOpen */
typedef AS_t_EVEError (*AS_t_EVEExclusiveOpen) (const AS_t_EVEContainer *p_Container, void **p_pBuffDsp2Eve, uint32 u_BuffSize, uint32 u_ComponentId);
/*#]*/

//**************************************************************************
//Type: AS_t_EVEExclusiveTrigger
//Triggers exclusive EVE processing of next chunk of data.
//
//Parameter:     p_pBuffNextDsp2Eve <OUT>.
//Description:   SW provides pointer to next ping- or pong-EVE OCM, which has
//               to be filled by algo on ARM/DSP
/*#[ type AS_t_EVEExclusiveTrigger */
typedef AS_t_EVEError (*AS_t_EVEExclusiveTrigger) (void **p_pBuffNextDsp2Eve);
/*#]*/

//**************************************************************************
//Type: AS_t_EVEExclusiveWait
//Waits until last scheduled EVE-processing is done (busy waiting, so no hand over to OS-scheduler)
/*#[ type AS_t_EVEExclusiveWait */
typedef AS_t_EVEError (*AS_t_EVEExclusiveWait) (void);
/*#]*/

//**************************************************************************
//Type: AS_t_EVESetLockOutState
//Behaviour: Global scheduler will call this service to lock out an algorithm from EVE for certain periods within the cycle. When the flag is set to "true", all EVETrigger-requests of the "u_ComponentId"-component will get stuck within the queue. From the "u_ComponentId"-algo-perspective, it looks like the EVE is still busy (EVEWait() does not return). The requests will be scheduled on EVE, when the state-flag is set back to "false". It has to be assured that only the global scheduler may make use of the service. Other Algorithms must not be able to use the service.
//
//Parameter:     b_State <IN>.
//Description:   Enable the service for a certain algorithm, 
//               if "true" then the algo is locked out from the service, 
//               if "false" the requests will be scheduled
//
//Parameter:     u_ComponentId <IN>.
//Description:   Identifies the component, which calls this service function. It will be
//               used to select the library on the ARP32/EVE side, which will be called.
//               The component IDs (COMP_ID_*) from file 'glob_comp_id.h' must be used.
/*#[ type AS_t_EVESetLockOutState */
typedef AS_t_EVEError (*AS_t_EVESetLockOutState) (uint32 u_ComponentId, boolean b_State);
/*#]*/

#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: MEASVirtualAdress_t
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*## type MEASVirtualAdress_t */
typedef uint32 MEASVirtualAdress_t;

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: MEASLength_t
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*## type MEASLength_t */
typedef uint32 MEASLength_t;

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: MEASFuncID_t
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*## type MEASFuncID_t */
typedef uint8 MEASFuncID_t;

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: MEASFuncChannelID_t
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*## type MEASFuncChannelID_t */
typedef uint8 MEASFuncChannelID_t;

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: MEAS_Callback_t
//Pointer to Callback function for notification
/*#[ type MEAS_Callback_t */
typedef void (*MEAS_Callback_t)(void);
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_ROIDataUseErr
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_ROIDataUseErr */
typedef AS_t_RoiDataUseErr t_ROIDataUseErr;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_RoiBufferType
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_RoiBufferType */
typedef  AS_t_RoiBufferType t_RoiBufferType;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_RoiErrorFlags
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_RoiErrorFlags */
typedef  AS_t_RoiErrorFlags t_RoiErrorFlags;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_RoiFlags
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_RoiFlags */
typedef AS_t_RoiFlags t_RoiFlags;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_RoiBase
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_RoiBase */
typedef AS_t_RoiBase t_RoiBase;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: FCT_RoiCallBk
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type FCT_RoiCallBk */
typedef AS_t_RoiCallBk FCT_RoiCallBk;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: FCT_RoiMainCallBk
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type FCT_RoiMainCallBk */
typedef AS_t_RoiMainCallBk FCT_RoiMainCallBk;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_RoiDescriptor
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_RoiDescriptor */
typedef AS_t_RoiDescriptor t_RoiDescriptor;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_RoiUser
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_RoiUser */
typedef AS_t_RoiUser t_RoiUser;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_pRoiHandle
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_pRoiHandle */
typedef AS_t_RoiHandle t_pRoiHandle;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_RoiPipElem
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_RoiPipElem */
typedef AS_t_RoiPipElem t_RoiPipElem;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: ROIDefine
//Pointer to Callback function for notification)
//
/*#[ type ROIDefine */
extern t_ROIDataUseErr ROIDefine (
                        t_pRoiHandle      *pRoiHandle,
                        uint16            usX1, 
                        uint16            usX2,
                        uint16            usY1,
                        uint16            usY2,
                        boolean           bMainRoi,
                        uint16            usModuloCnt,
                        uint16            usModuloHeight,
                        uint16            usRingBufThreshold,
                        boolean           bSwitchedOn,
                        FCT_RoiCallBk     pfctFuncPreprocRoi,
                        FCT_RoiCallBk     pfctFuncPreprocToggleRoi,
                        uint32            u32Id,
                        void              *pApp
                        );
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: ROIDelete
//Pointer to Callback function for notification)
//
/*#[ type ROIDelete */
extern t_ROIDataUseErr ROIDelete (t_pRoiHandle pRoiHandle);
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: RoiDefine_t
//Pointer to Callback function for notification)
//
/*#[ type RoiDefine_t */
typedef t_ROIDataUseErr (*RoiDefine_t)(
                        t_pRoiHandle      *pRoiHandle,
                        uint16            usX1, 
                        uint16            usX2,
                        uint16            usY1,
                        uint16            usY2,
                        boolean           bMainRoi,
                        uint16            usModuloCnt,
                        uint16            usModuloHeight,
                        uint16            usRingBufThreshold,
                        boolean           bSwitchedOn,
                        FCT_RoiCallBk     pfctFuncPreprocRoi,
                        FCT_RoiCallBk     pfctFuncPreprocToggleRoi,
                        uint32            u32Id,
                        void              *pApp
                        );
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: RoiDelete_t
//Pointer to Callback function for notification)
//
/*#[ type RoiDelete_t */
typedef t_ROIDataUseErr (*RoiDelete_t)(t_pRoiHandle pRoiHandle);
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: GetTimeMicroSec_t
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type GetTimeMicroSec_t */
typedef uint32 (*GetTimeMicroSec_t) (void);
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: t_RoiFrameType
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type t_RoiFrameType */
 typedef enum
{
  ROI_FRAME_SHORT,            /*!< short imager exposure time */
  ROI_FRAME_LONG              /*!< long imager exposure time */
} t_RoiFrameType;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
//**************************************************************************
//Type: AS_t_RtaEventType
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_RtaEventType */
typedef enum {
    e_RTA_EVT_Marker      = 0,
    e_RTA_EVT_AlgoStart   = 1,
    e_RTA_EVT_AlgoEnd     = 2,
    e_RTA_EVT_TSK_Switch  = 3,
    e_RTA_EVT_TSK_Rdy     = 4,
    e_RTA_EVT_MAX_TYPES   = 5,
    /* RTA_EVT_MAX_TYPES must be smaller than 256 */ 
    /* compiler workaround */
    e_RTA_EVT_LAST_ENTRY  = 65536
} AS_t_RtaEventType;
/*#]*/

//**************************************************************************
//Type: AS_t_Dem_ReturnType
//Return values of dem interface
/*## type AS_t_Dem_ReturnType */
typedef uint8 AS_t_Dem_ReturnType;

//**************************************************************************
//Type: AS_t_Dem_EventIDType
//IDs of dems, (test).
//Generated with cessar: unique for SoC: SW and Algo
/*## type AS_t_Dem_EventIDType */
typedef uint16 AS_t_Dem_EventIDType;

//**************************************************************************
//Type: AS_t_Dem_EventStatusType
//Satus of test: passed, not passed
/*#[ type AS_t_Dem_EventStatusType */
typedef enum
{
	DEM_EVENT_STATUS_PASSED 	= 0,
	DEM_EVENT_STATUS_FAILED		= 1,
	DEM_EVENT_STATUS_LASTENTRY	= 65536
}AS_t_Dem_EventStatusType;
/*#]*/

//**************************************************************************
//Type: AS_t_Dem_SetEventStatus
//Definition of Algo Sevice: SetEventStatus
// - Event ID (In)
// - Event Status (In)
//
/*#[ type AS_t_Dem_SetEventStatus */
typedef AS_t_Dem_ReturnType (*AS_t_Dem_SetEventStatus) (const AS_t_Dem_EventIDType u_Dem_EventIdRaw, 
                                   const AS_t_Dem_EventStatusType u_Dem_EventStatus);
/*#]*/

//**************************************************************************
//Type: AS_t_Dem_SetEventStatusPreExtData
//Definition of Algo Sevice: SetEventStatusPreExtData
// - Event ID (In)
// - Event Status (In)
// - Pre Extended Data Ptr (In)
// - Size of Pre Ext Data (In)
//
/*#[ type AS_t_Dem_SetEventStatusPreExtData */
typedef AS_t_Dem_ReturnType (*AS_t_Dem_SetEventStatusPreExtData) (const AS_t_Dem_EventIDType u_Dem_EventIdRaw, 
                                   const AS_t_Dem_EventStatusType u_Dem_EventStatus, 
                                   const uint8* const p_Dem_pui8_PreExtData, 
                                   uint8 u_Dem_PreExtDataSize);
/*#]*/

//**************************************************************************
//Type: AS_t_MemState
//Possible states of memory.
//Type for output parameter of memory services.
/*#[ type AS_t_MemState */
typedef enum
{
	AS_MEM_L2FREE_L3FREE 	= 0,
	AS_MEM_L2USED_L3FREE 	= 1,
	AS_MEM_L2FREE_L3USED 	= 2,
	AS_MEM_L2USED_L3USED 	= 3,
	AS_MEM_L2FREE 			= 4,
	AS_MEM_L2USED 			= 5,
	AS_MEM_L3FREE 			= 6,
	AS_MEM_L3USED 			= 7,
	AS_MEM_STATE_LASTENTRY 	= 65536
}AS_t_MemState;
/*#]*/

//**************************************************************************
//Type: AS_t_MemWaitCondition
//Possible wait conditions.
//Type for input parameter of memory services.
/*#[ type AS_t_MemWaitCondition */
typedef enum
{
	AS_MEM_L2NOWAIT_L3NOWAIT 	= 0,
	AS_MEM_L2WAIT_L3NOWAIT 		= 1,
	AS_MEM_L2NOWAIT_L3WAIT 		= 2,
	AS_MEM_L2WAIT_L3WAIT 		= 3,
	AS_MEM_L2NOWAIT 			= 4,
	AS_MEM_L2WAIT 				= 5,
	AS_MEM_L3NOWAIT 			= 6,
	AS_MEM_L3WAIT 				= 7,
	AS_MEM_WAIT_LASTENTRY 		= 65536
}AS_t_MemWaitCondition ;
/*#]*/

//**************************************************************************
//Type: AS_t_MemLock
//Definition of Algo Sevice: MemLock
//Take L2 and L3 memory: 
// - L2 Buffer Ptr - double indirection (In/Out)
// - L2 Buffer Size Ptr (Out)
// - L3 Buffer Ptr - double indirection (In/Out)
// - L3 Buffer Size Ptr (Out)
// - Memory State Ptr (Out)
// - Wait Condition (In)
//
/*#[ type AS_t_MemLock */
typedef sint32 (*AS_t_MemLock) (void ** p_L2Buffer, 
					  sint32 * p_L2BuffSize, 
					  void ** p_L3Buffer, 
					  sint32 * p_L3BuffSize, 
					  AS_t_MemState * p_State, 
					  AS_t_MemWaitCondition WaitCondition);
/*#]*/

//**************************************************************************
//Type: AS_t_MemUnlock
//Definition of Algo Sevice: MemUnlock
// - Freeing of L2 and L3 memory
// - Mem State Ptr (Out)
//
//
/*#[ type AS_t_MemUnlock */
typedef sint32 (*AS_t_MemUnlock) (AS_t_MemState * p_State);
/*#]*/

//**************************************************************************
//Type: AS_t_MemLockL2
//Definition of Algo Sevice: MemLock
//Take L2 memory: 
// - L2 Buffer Ptr - double indirection (In/Out)
// - L2 Buffer Size Ptr (Out)
// - Memory State Ptr (Out)
// - Wait Condition (In)
//
/*#[ type AS_t_MemLockL2 */
typedef sint32 (*AS_t_MemLockL2) (void ** p_L2Buffer, 
					  sint32 * p_L2BuffSize, 
					  AS_t_MemState * p_State, 
					  AS_t_MemWaitCondition WaitCondition);
/*#]*/

//**************************************************************************
//Type: AS_t_MemUnlockL2
//Definition of Algo Sevice: MemUnlockL2
// - Freeing of L2 memory
// - Mem State Ptr (Out)
//
/*#[ type AS_t_MemUnlockL2 */
typedef sint32 (*AS_t_MemUnlockL2) (AS_t_MemState * p_State);
/*#]*/

//**************************************************************************
//Type: AS_t_MemLockL3
//Definition of Algo Sevice: MemLock
//Take L3 memory:
// - L3 Buffer Ptr - double indirection (In/Out)
// - L3 Buffer Size Ptr (Out)
// - Memory State Ptr (Out)
// - Wait Condition (In)
//
/*#[ type AS_t_MemLockL3 */
typedef sint32 (*AS_t_MemLockL3) (void ** p_L3Buffer, 
					  sint32 * p_L3BuffSize, 
					  AS_t_MemState * p_State, 
					  AS_t_MemWaitCondition WaitCondition);
/*#]*/

//**************************************************************************
//Type: AS_t_MemUnlockL3
//Definition of Algo Sevice: MemUnlockL3
// - Freeing of L3 memory only
// - Mem State Ptr (Out)
//
/*#[ type AS_t_MemUnlockL3 */
typedef sint32 (*AS_t_MemUnlockL3) (AS_t_MemState * p_State);
/*#]*/

//**************************************************************************
//Type: AS_t_RTAAlgoServiceAddEvent
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_RTAAlgoServiceAddEvent */
typedef sint32 (*AS_t_RTAAlgoServiceAddEvent)(AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData);
/*#]*/

//**************************************************************************
//Type: AS_t_GetTimestampuS64
//Definition of Algo Sevice: Get Timestamp us
// - No parameters
//
/*#[ type AS_t_GetTimestampuS64 */
 typedef uint64 (*AS_t_GetTimestampuS64) (void);
/*#]*/

//**************************************************************************
//Type: AS_t_GetTimestampuS32
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_GetTimestampuS32 */
typedef uint32 (*AS_t_GetTimestampuS32) (void);
/*#]*/

//**************************************************************************
//Type: AS_t_MeasReturn
//Return values of Meas interface functions
/*## type AS_t_MeasReturn */
typedef enum AS_t_MeasReturn {
    MEAS_OK = 0, //No error
    MEAS_JOB_LIMIT = 1, //Error: Job limit
    MEAS_FULL_BUFFER = 2, //Error: Full buffer
    MEAS_BAD_GROUP_ID = 3, //Error: Bad group ID
    MEAS_BAD_DATA_ALIGNMENT = 4, //Error: Bad data alignment
    MEAS_CALL_FROM_IRQ_LEVEL = 5 //Error: Call from IRQ level
} AS_t_MeasReturn;

//**************************************************************************
//Type: AS_t_MeasCallback
//Pointer to Callback function for notification
/*#[ type AS_t_MeasCallback */
typedef void (*AS_t_MeasCallback)(void);
/*#]*/

//**************************************************************************
//Type: AS_t_MeasFuncChannelID
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*## type AS_t_MeasFuncChannelID */
typedef uint8 AS_t_MeasFuncChannelID;

//**************************************************************************
//Type: AS_t_MeasFuncID
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*## type AS_t_MeasFuncID */
typedef uint8 AS_t_MeasFuncID;

//**************************************************************************
//Type: AS_t_MeasLength
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*## type AS_t_MeasLength */
typedef uint32 AS_t_MeasLength;

//**************************************************************************
//Type: AS_t_MeasVirtualAdress
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*## type AS_t_MeasVirtualAdress */
typedef uint32 AS_t_MeasVirtualAdress;

//**************************************************************************
//Type: AS_t_MeasInfo
//Detailed header information of measurement data
/*#[ type AS_t_MeasInfo */
typedef struct
{
  AS_t_MeasVirtualAdress VirtualAddress; /*!< Location of data in virtual address space */
  AS_t_MeasLength        Length;         /*!< Length of data in bytes */
  AS_t_MeasFuncID        FuncID;         /*!< Identifier of data source */
  AS_t_MeasFuncChannelID FuncChannelID;  /*!< Data classification (e.g. input, output) */
}AS_t_MeasInfo;
/*#]*/

//**************************************************************************
//Type: AS_t_MeasHdlr
//Definition of Algo Sevice: Meas Freez
//- Meas Info Ptr [In]
//- Data Ptr [In]
//- Meas Callback - notification [In]
//
/*#[ type AS_t_MeasHdlr */
typedef AS_t_MeasReturn (*AS_t_MeasHdlr)(const AS_t_MeasInfo *, void *, AS_t_MeasCallback);
/*#]*/

//**************************************************************************
//Type: AS_t_MeasStartFuncCycle
//Definition of Algo Sevice: Meas StartFuncCycle
//- Function ID used by algo [In]
//
//
/*#[ type AS_t_MeasStartFuncCycle */
typedef void (*AS_t_MeasStartFuncCycle)(const AS_t_MeasFuncID);
/*#]*/

#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: MEASReturn_t
//Return values of Meas interface functions
/*#[ type MEASReturn_t */
typedef AS_t_MeasReturn MEASReturn_t;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: MEASInfo_t
//Detailed header information of measurement data
/*#[ type MEASInfo_t */
typedef struct
{
  MEASVirtualAdress_t VirtualAddress; /*!< Location of data in virtual address space */
  MEASLength_t        Length;         /*!< Length of data in bytes */
  MEASFuncID_t        FuncID;         /*!< Identifier of data source */
  MEASFuncChannelID_t FuncChannelID;  /*!< Data classification (e.g. input, output) */
}MEASInfo_t;
/*#]*/

#endif /*CODING_GUIDLINE_4 */
#ifndef CODING_GUIDLINE_4
//**************************************************************************
//Type: MeasHdlr_t
//Definition of Algo Sevice: Meas Freez
//- Meas Info Ptr [In]
//- Data Ptr [In]
//- Meas Callback - notification [In]
//
/*#[ type MeasHdlr_t */
typedef MEASReturn_t (*MeasHdlr_t)(const MEASInfo_t *, void *, MEAS_Callback_t);
/*#]*/

#endif /*CODING_GUIDLINE_4 */
//**************************************************************************
//Type: AS_t_RoiDefine
//Pointer to Callback function for notification)
//
/*#[ type AS_t_RoiDefine */
typedef t_ROIDataUseErr (*AS_t_RoiDefine)(
                        t_pRoiHandle      *pRoiHandle,
                        uint16            usX1, 
                        uint16            usX2,
                        uint16            usY1,
                        uint16            usY2,
                        boolean           bMainRoi,
                        uint16            usModuloCnt,
                        uint16            usModuloHeight,
                        uint16            usRingBufThreshold,
                        boolean           bSwitchedOn,
                        AS_t_RoiCallBk     pfctFuncPreprocRoi,
                        AS_t_RoiCallBk     pfctFuncPreprocToggleRoi,
                        uint32            u32Id,
                        void              *pApp
                        );
/*#]*/

//**************************************************************************
//Type: AS_t_RoiDelete
//Pointer to Callback function for notification)
//
/*#[ type AS_t_RoiDelete */
typedef t_ROIDataUseErr (*AS_t_RoiDelete)(t_pRoiHandle pRoiHandle);
/*#]*/

//**************************************************************************
//Type: AS_t_Sched_SubMode
//Return codes of of eve service
/*#[ type AS_t_Sched_SubMode */
typedef enum
{
  AS_SAC_BSW_STANDALONE 	= 1,
  AS_SAC_BSW_PARALLEL 		= 2, 
  AS_DIAG_BSW_ECM        	= 3, 
  AS_DIAG_BSW_ECS			= 4,
  AS_DIAG_BSW_EC_BOTH		= 5,
  AS_DIAG_BSW_DISTTEST  	= 6,
  AS_SCHEDSUBMODE_LASTENTRY = 65536
}AS_t_Sched_SubMode;
/*#]*/

//**************************************************************************
//Type: AS_t_Sched_SetSubMode
//Definition of Algo Sevice: EDMACopy
// - Dst Buffer Ptr (In)
// - Src Buffer Ptr (In)
// - Buffer Size (In)
// - Channel Index (In/Out)
//
/*#[ type AS_t_Sched_SetSubMode */
typedef void (*AS_t_Sched_SetSubMode) (const AS_t_Sched_SubMode SchedSubMode);
/*#]*/

//**************************************************************************
//Type: AS_t_TaskEventID
//- Description:	Task events comming asynch, to which task has to wait
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_TaskEventID */
typedef enum { 
	e_TASKEVT_FPGA_DISABLE         = 0,
	e_TASKEVT_FPGA_ENABLE          = 1,
    e_TASKEVT_FPGA_CLASSIFIER_INIT = 2,
    e_TASKEVT_LAST_ENTRY   	       = 65536
} AS_t_TaskEventID;
/*#]*/

//**************************************************************************
//Type: AS_t_TaskWaitForTime
//Definition of Algo Sevice: TaskWaitForTime
// - Time interval which is to be waited non blocking in task (In)
//
/*#[ type AS_t_TaskWaitForTime */
typedef sint32 (*AS_t_TaskWaitForTime) (const uint32);
/*#]*/

//**************************************************************************
//Type: AS_t_TaskWaitForEvent
//Definition of Algo Sevice: TaskWaitForTime
// - Time interval which is to be waited non blocking in task (In)
//
/*#[ type AS_t_TaskWaitForEvent */
typedef sint32 (*AS_t_TaskWaitForEvent) (const AS_t_TaskEventID);
/*#]*/

//**************************************************************************
//Type: AS_t_ServiceFuncts
//- Description:	short description, meaning, usage
//- Range:		range of variable (Min - Max) based on raw value
//- Resolution:	resolution (e.g.: 0.1), only for integer (for float "-")
//- Unit:		physical unit (e.g. m/s^2)
//
/*#[ type AS_t_ServiceFuncts */
typedef struct
{
	uint32             					u_Version;       
    AS_t_MeasHdlr						pfMeasFreeze;
    AS_t_RoiDefine  					pfRoiDefine;
    AS_t_RoiDelete  					pfRoiDelete;
    AS_t_GetCoreTicksuS64				pfGetCoreTicksuS64;
    AS_t_GetTimestampuS32				pfGetTimestampuS32;
    AS_t_GetTimestampuS64				pfGetTimestampuS64;
    AS_t_CacheInv 						pfCacheInv;
    AS_t_CacheWbInv						pfCacheWbInv;
    AS_t_CacheWbInvAll 					pfCacheWbInvAll; 
    AS_t_Dem_SetEventStatus             pfDem_SetEventStatus;
    AS_t_Dem_SetEventStatusPreExtData	pfDem_SetEventStatusPreExtData;
    AS_t_EDMACopy						pfEDMACopy;
    AS_t_EDMACopy2D						pfEDMACopy2D;
    AS_t_EDMACopyChained				pfEDMACopyChained;
    AS_t_EDMAMemSet						pfEDMAMemSet;
    AS_t_EDMAWait						pfEDMAWait;
    AS_t_EVEExclusiveClose				pfEVEExclusiveClose;
    AS_t_EVEExclusiveOpen 				pfEVEExclusiveOpen;
    AS_t_EVEExclusiveTrigger			pfEVEExclusiveTrigger;
    AS_t_EVEExclusiveWait 				pfEVEExclusiveWait;  
    AS_t_EVESetLockOutState             pfEVESetLockOutState;
    AS_t_EVETrigger 					pfEVETrigger;
    AS_t_EVEWait 						pfEVEWait;
    AS_t_MemLock 						pfMemLock;
    AS_t_MemUnlock 						pfMemUnlock;  
    AS_t_RTAAlgoServiceAddEvent 		pfRTAAlgoServiceAddEvent; 
    AS_t_Sched_SetSubMode               p_SchedSetSubMode; 
    AS_t_MemLockL2						pfMemLockL2;
    AS_t_MemUnlockL2                    pfMemUnlockL2;
    AS_t_MemLockL3						pfMemLockL3;
    AS_t_MemUnlockL3					pfMemUnlockL3; 
    AS_t_MeasStartFuncCycle             pfMeasStartFuncCycle;
    AS_t_TaskWaitForTime                pfTaskWaitForTime;
    AS_t_TaskWaitForEvent               pfTaskWaitForEvent;
} AS_t_ServiceFuncts;
/*#]*/

//**************************************************************************
//Type: AS_t_EVELibExecFunc
//Prototype of algo EVE library execute function (main entry function of library)
//
//Parameter:     p_Container <IN>.
//Description:   Contains info about source-/dest-buffers and function ID.
//               This is passed from the client algo library to the EVE library.
/*#[ type AS_t_EVELibExecFunc */
typedef sint32 (*AS_t_EVELibExecFunc)(const AS_t_EVEContainer* p_Container);
/*#]*/

// **************************************************************************
// AS_EVE_IFVERSION: SW_S11_CA8_SMFC400PR_01.01.05_R4I SW_S11_CA8_SMFC400PR_01.01.06_R4I SW_S11_CA8_SMFC400PR_01.01.07_R4I SW_S11_CA8_SMFC400PR_01.01.08_R4I SW_S11_CA8_SMFC400PR_01.01.09_R4I SW_S11_CA8_SMFC400PR_01.01.10_R4I SW_S11_CA8_SMFC400PR_01.01.11_R4I SW_S11_SMFC400PR_01.01.04_R4I SW_S12_M3VIDEO_SMFC400PR_01.01.04_R4I SW_S12_M3VIDEO_SMFC400PR_01.01.07_R4I SW_S12_M3VIDEO_SMFC400PR_01.01.09_R4I SW_S12_M3VIDEO_SMFC400PR_01.01.11_R4I SW_S14_DSP_SMFC400PR_01.01.05_R4I SW_S14_DSP_SMFC400PR_01.01.06_R4I SW_S14_DSP_SMFC400PR_01.01.07_R4I SW_S14_DSP_SMFC400PR_01.01.08_R4I SW_S14_DSP_SMFC400PR_01.01.09_R4I SW_S14_DSP_SMFC400PR_01.01.10_R4I SW_S14_DSP_SMFC400PR_01.01.11_R4I SW_S14_SMFC400PR_01.01.04_R4I  AS_t_IfVersionNum
// Version number of eve interface
/*## attribute AS_EVE_IFVERSION */
#define AS_EVE_IFVERSION 1u

// **************************************************************************
// AS_SERVICEFUNC_VERSION: SW_S11_CA8_SMFC400PR_01.01.05_R4I SW_S11_CA8_SMFC400PR_01.01.06_R4I SW_S11_CA8_SMFC400PR_01.01.07_R4I SW_S11_CA8_SMFC400PR_01.01.08_R4I SW_S11_CA8_SMFC400PR_01.01.09_R4I SW_S11_CA8_SMFC400PR_01.01.10_R4I SW_S11_CA8_SMFC400PR_01.01.11_R4I SW_S11_SMFC400PR_01.01.04_R4I SW_S12_M3VIDEO_SMFC400PR_01.01.04_R4I SW_S12_M3VIDEO_SMFC400PR_01.01.07_R4I SW_S12_M3VIDEO_SMFC400PR_01.01.09_R4I SW_S12_M3VIDEO_SMFC400PR_01.01.11_R4I SW_S14_DSP_SMFC400PR_01.01.05_R4I SW_S14_DSP_SMFC400PR_01.01.06_R4I SW_S14_DSP_SMFC400PR_01.01.07_R4I SW_S14_DSP_SMFC400PR_01.01.08_R4I SW_S14_DSP_SMFC400PR_01.01.09_R4I SW_S14_DSP_SMFC400PR_01.01.10_R4I SW_S14_DSP_SMFC400PR_01.01.11_R4I SW_S14_SMFC400PR_01.01.04_R4I  AS_t_IfVersionNum
// Version number of eve interface
/*## attribute AS_SERVICEFUNC_VERSION */
#define AS_SERVICEFUNC_VERSION 6u

/***    User explicit entries    ***/


#ifdef __cplusplus
}
#endif

/*## package Types_Pkg */

/*## class TopLevel::algo_service_types */

#endif
/*********************************************************************
	File Path	: ..\..\..\04_Engineering\01_Source_Code\_gensrc\rhapsody\algo_service_types.h
*********************************************************************/

