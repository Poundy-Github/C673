/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  SwcRoElite.c
 *     Workspace:  D:/Sandboxes/MFC300/MFC300_Base/05_Software/MCU/03_Design/05_DaVinci/mfc310_SMPC.dev
 *   ECU-Project:  MPC
 *     SW-C Type:  SwcRoElite
 *  Generated at:  Wed May 25 10:08:03 2011
 *
 *     Generator:  MICROSAR RTE Generator Version 2.17.3
 *       License:  License CBD1000091 valid for CBD1000091 A.D.C. GmbH Continental  Package: Daimler Car SLP10  Micro: MPC567xK / MPC5675K  Compiler: Metrowerks V4.0.0
 *
 *   Description:  C-Code implementation template for SW-C <SwcRoElite>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Stefan Kagerbauer             Skr           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  01.00.00  2008-10-07  Skr     ---------     Intitial revision of the implementation
 *  01.00.01  2008-11-28  Skr     ---------     Generated with RTE generator 2.9 
 *  01.00.02  2008-12-17  Skr     ESCAN00032105 Corrected name of operation of port interface
 *  01.00.03  2009-01-21  Skr                   Generated with RTE generator 2.10
 *  01.00.04  2009-03-04  Skr                   Optimized SwcRoElite_QueueAddElement 
 *  01.00.05  2009-07-14  Her     ESCAN00036455 Protect RoE queue access for parallel access
 *  01.01.00  2010-03-02  Tne     ESCAN00041103 Adapt SWC RoElite to DAG Extract of System Description Naming ROE_<>_XX
 *                                ESCAN00041104 Adapt SWC RoElite to DAG Extract of System Description using Intel
 *                                              instead of Motorola Byte Format for RoElite Messages
 *                                ---------     Corrected compiler abstraction for version info
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************

 Per-Instance Memory:
 ====================
  SwcRoElite_DiagData
    Die Per-Instance Memory Variablen werden mit der Speicherklasse RTE_VAR_DEFAULT_RET_PIM_GROUP angelegt 
     und in die Sektion RTE_START_SEC_VAR_DEFAULT_RTE_PIM_GROUP_UNSPECIFIED gelegt.
     
     Diese Variable wird aber als Parameter für den Sendeport und den StatusAvailabilityMask Port benutzt.
     Die Portdefinitionen erwarten als Parameter einen Zeiger auf eine Variable mit Speicherklasse RTE_SWCROELITE_APPL_DATA.
     
     -> Es muss sichergestellt werden, dass beide Speicherklassen eine gleiche Zeigerreichweite aufweisen.

 *********************************************************************************************************************/

#include "Rte_SwcRoElite.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "SwcRoElite.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* Vendor specific version information is BCD coded */
#if ((DIAG_ASRSWCROELITE_DAIMLER_VERSION         != 0x0101u)|| \
     (DIAG_ASRSWCROELITE_DAIMLER_RELEASE_VERSION != 0x00u  )  )
# error "Vendor specific version numbers of SwcRoElite.c and SwcRoElite.h are inconsistent"
#endif

#define ROELITE_DEBUG_MODE (STD_OFF) /* To check the correct size of the queue. STD_ON/STD_OFF */

#define ROELITE_DTC_STATUS_TESTFAILED                         (0x01u)
#define ROELITE_DTC_STATUS_TESTFAILEDTHISOPERATIONCYCLE       (0x02u)
#define ROELITE_DTC_STATUS_PENDINGDTC                         (0x04u)
#define ROELITE_DTC_STATUS_CONFIRMEDDTC                       (0x08u)
#define ROELITE_DTC_STATUS_TESTNOTCOMPLETEDSINCELASTCLEAR     (0x10u)
#define ROELITE_DTC_STATUS_TESTFAILEDSINCELASTCLEAR           (0x20u)
#define ROELITE_DTC_STATUS_TESTNOTCOMPLETEDTHISOPERATIONCYCLE (0x40u)
#define ROELITE_DTC_STATUS_WARNINGINDICATORREQUESTED          (0x80u)

#define ROELITE_DIAGNOSTICDATA_DEFAULT_PCI                    (0x07u)
#define ROELITE_DIAGNOSTICDATA_DEFAULT_POSITIVERESPONSE       (0x59u)
#define ROELITE_DIAGNOSTICDATA_DEFAULT_REPORTEDDTCSTATUS      (0x0Eu)
#define ROELITE_DIAGNOSTICDATA_DEFAULT_STATUSAVAILABILITYMASK (0x00u)

/* internal defines to allow for a quicker change in signal byte ordering
   (DAG changed it end of 2009 / start of 2010 from Big to Little Endian)*/
#define ROELITE_DTC_SIGNAL_BYTE_ORDER                         LOW_BYTE_FIRST
#define ROELITE_DTCHEADER_SIGNAL_BYTE_ORDER                   LOW_BYTE_FIRST

/* Check the byte order */
#if (((ROELITE_DTCHEADER_SIGNAL_BYTE_ORDER == LOW_BYTE_FIRST)  && (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)) || \
     ((ROELITE_DTCHEADER_SIGNAL_BYTE_ORDER == HIGH_BYTE_FIRST) && (CPU_BYTE_ORDER == LOW_BYTE_FIRST)))
  /* signal is little endian, CPU is big endian     -> PCI is at Most Significant Byte */
  /* signal is big endian,    CPU is little endian  -> PCI is at Most Significant Byte */
  #define ROELITE_DIAGNOSTICDATA_PCI_POSITION                    (0x03u)
  #define ROELITE_DIAGNOSTICDATA_POSITIVERESPONSE_POSITION       (0x02u)
  #define ROELITE_DIAGNOSTICDATA_REPORTEDDTCSTATUS_POSITION      (0x01u)
  #define ROELITE_DIAGNOSTICDATA_STATUSAVAILABILITYMASK_POSITION (0x00u)
#elif (((ROELITE_DTCHEADER_SIGNAL_BYTE_ORDER == LOW_BYTE_FIRST)  && (CPU_BYTE_ORDER == LOW_BYTE_FIRST)) || \
       ((ROELITE_DTCHEADER_SIGNAL_BYTE_ORDER == HIGH_BYTE_FIRST) && (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)))
  /* signal is little endian, CPU is little endian  -> PCI is at Least Significant Byte */
  /* signal is big endian,    CPU is big endian     -> PCI is at Least Significant Byte */
  #define ROELITE_DIAGNOSTICDATA_PCI_POSITION                    (0x00u)
  #define ROELITE_DIAGNOSTICDATA_POSITIVERESPONSE_POSITION       (0x01u)
  #define ROELITE_DIAGNOSTICDATA_REPORTEDDTCSTATUS_POSITION      (0x02u)
  #define ROELITE_DIAGNOSTICDATA_STATUSAVAILABILITYMASK_POSITION (0x03u)
#else
  #error "The CPU_BYTE_ORDER or the ROELITE_DTCHEADER_SIGNAL_BYTE_ORDER doesn't have a valid value. Please check Platform_Types.h!"
#endif

#define ROELITE_QUEUE            (*Rte_Pim_SwcRoElite_Queue())
#define ROELITE_QUEUE_SIZE       ((sizeof(SwcRoElite_QueueType))/(sizeof(SwcRoElite_QueueElementType)))
#define ROELITE_DIAGNOSTIC_DATA  (*Rte_Pim_SwcRoElite_DiagData())

#define ROELITE_QUEUE_READ_READINDEX(Runnable)            (Rte_IrvRead_ ## Runnable ## _QueueReadIndex())
#define ROELITE_QUEUE_WRITE_READINDEX(Runnable, Value)    (Rte_IrvWrite_ ## Runnable ## _QueueReadIndex(Value))
#define ROELITE_QUEUE_READ_WRITEINDEX(Runnable)           (Rte_IrvRead_ ## Runnable ## _QueueWriteIndex())
#define ROELITE_QUEUE_WRITE_WRITEINDEX(Runnable, Value)   (Rte_IrvWrite_ ## Runnable ## _QueueWriteIndex(Value))
#define ROELITE_QUEUE_READ_ENTRIES(Runnable)              (Rte_IrvRead_ ## Runnable ## _QueueEntries())
#define ROELITE_QUEUE_WRITE_ENTRIES(Runnable, Value)      (Rte_IrvWrite_ ## Runnable ## _QueueEntries(Value))

#define ROELITE_INVALID_DTC        (0xFFFFFFu)
#define ROELITE_INVALID_DTC_STATUS (0xFFu)

typedef enum
{
  ROELITE_QUEUE_ENTRY_ADDED = 0,
  ROELITE_QUEUE_ENTRY_UPDATED,
  ROELITE_QUEUE_ENTRY_FOUND,
  ROELITE_QUEUE_FULL,
  ROELITE_QUEUE_EMPTY
} SwcRoElite_QueueReturnType;

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* SwcDemSc version */
CONST(uint8, RTE_CONST) SwcRoElite_MainVersion    = SWCROELITE_SW_MAJOR_VERSION;
CONST(uint8, RTE_CONST) SwcRoElite_SubVersion     = SWCROELITE_SW_MINOR_VERSION;
CONST(uint8, RTE_CONST) SwcRoElite_ReleaseVersion = SWCROELITE_SW_PATCH_VERSION;

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (STD_ON == ROELITE_DEBUG_MODE)
  #define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
  #include "MemMap.h"

    STATIC VAR(boolean, RTE_VAR_NOINIT) SwcRoElite_ErrorFlag_bl;

  #define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
  #include "MemMap.h"
#endif

#define RTE_START_SEC_SWCROELITE_APPL_CODE
#include "MemMap.h"

STATIC FUNC(SwcRoElite_QueueReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_QueueAddElement(P2CONST(SwcRoElite_QueueElementType, AUTOMATIC, AUTOMATIC) NewElement_pt);
STATIC FUNC(SwcRoElite_QueueReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_QueueGetFirstElement(P2VAR(SwcRoElite_QueueElementType, AUTOMATIC, AUTOMATIC) NewElement_pt);
STATIC FUNC(SwcRoElite_QueueReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_QueueRemoveFirstElement(void);
STATIC FUNC(SwcRoElite_QueueReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_QueueClear(void);

#define RTE_STOP_SEC_SWCROELITE_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Dem_DTCStatusMaskType: Integer in interval [0...255]
 * Dem_DTCType: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255] (standard type)
 * c08_0_255_1_SNA_na: Integer in interval [0...255]
 * c24_0_16777215_1_SNA_na: Integer in interval [0...16777215]
 * c32_0_4294967295_1_SNA_na: Integer in interval [0...4294967295]
 *
 * Enumeration Types:
 * ==================
 * Dem_DTCKindType: Enumeration of integer in interval [1...2] with enumerators
 *   DEM_DTC_KIND_ALL_DTCS (1u)
 *   DEM_DTC_KIND_EMISSION_REL_DTCS (2u)
 *
 * Array Types:
 * ============
 * SwcRoElite_QueueType: Array with 5 element(s) of type SwcRoElite_QueueElementType
 *
 * Record Types:
 * =============
 * SwcRoElite_MsgType: Record with elements
 *   ROE_DTC_XX of type c24_0_16777215_1_SNA_na
 *   ROE_DTC_Stat_XX of type c08_0_255_1_SNA_na
 *   ROE_Header_XX of type c32_0_4294967295_1_SNA_na
 * SwcRoElite_QueueElementType: Record with elements
 *   DTC of type Dem_DTCType
 *   DTCStatus of type Dem_DTCStatusMaskType
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Per-Instance Memory:
 * ====================
#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
 *   SwcRoElite_QueueElementType *Rte_Pim_SwcRoElite_Queue(void)
#else
 *   SwcRoElite_QueueType *Rte_Pim_SwcRoElite_Queue(void)
#endif
 *   SwcRoElite_MsgType *Rte_Pim_SwcRoElite_DiagData(void)
 *
 *********************************************************************************************************************/


#define RTE_START_SEC_SWCROELITE_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SwcRoElite_Cyclic
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 200ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_SwcRoElite_COMSender_ROE_XX(const SwcRoElite_MsgType *data)
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   UInt8 Rte_IrvRead_SwcRoElite_Cyclic_QueueEntries(void)
 *   UInt8 Rte_IrvRead_SwcRoElite_Cyclic_QueueReadIndex(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_SwcRoElite_Cyclic_QueueEntries(UInt8 data)
 *   void Rte_IrvWrite_SwcRoElite_Cyclic_QueueReadIndex(UInt8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_FifoQueue(void)
 *   void Rte_Exit_ExclusiveArea_FifoQueue(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCROELITE_APPL_CODE) SwcRoElite_Cyclic(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcRoElite_Cyclic
 *********************************************************************************************************************/

  SwcRoElite_QueueElementType Element_tloc;
  #if (STD_ON == ROELITE_DEBUG_MODE)
  if(TRUE == SwcRoElite_ErrorFlag_bl)
  {
#if (ROELITE_DTC_SIGNAL_BYTE_ORDER == LOW_BYTE_FIRST)
     /* swap DTC value */
      ROELITE_DIAGNOSTIC_DATA.ROE_DTC_XX =((ROELITE_INVALID_DTC>>16) & 0x000000FF)  | 
                                          ((ROELITE_INVALID_DTC)     & 0x0000FF00)  |
                                          ((ROELITE_INVALID_DTC<<16) & 0x00FF0000);
#elif (ROELITE_DTC_SIGNAL_BYTE_ORDER == HIGH_BYTE_FIRST)
    ROELITE_DIAGNOSTIC_DATA.ROE_DTC_XX = ROELITE_INVALID_DTC;
#else
    #error "The ROELITE_DTC_SIGNAL_BYTE_ORDER doesn't have a valid value."
#endif
    ROELITE_DIAGNOSTIC_DATA.ROE_DTC_Stat_XX = ROELITE_INVALID_DTC_STATUS;
    Rte_Call_SwcRoElite_RPortRoEliteSendRoE_OPSendRoE(&ROELITE_DIAGNOSTIC_DATA);
  }
  else
  #endif
  {
    if(ROELITE_QUEUE_ENTRY_FOUND == SwcRoElite_QueueGetFirstElement(&Element_tloc))
    {
#if (ROELITE_DTC_SIGNAL_BYTE_ORDER == LOW_BYTE_FIRST)
      /* swap DTC value */
      ROELITE_DIAGNOSTIC_DATA.ROE_DTC_XX =((Element_tloc.DTC>>16) & 0x000000FF)  | 
                                          ((Element_tloc.DTC)     & 0x0000FF00)  |
                                          ((Element_tloc.DTC<<16) & 0x00FF0000);
#elif (ROELITE_DTC_SIGNAL_BYTE_ORDER == HIGH_BYTE_FIRST)
      ROELITE_DIAGNOSTIC_DATA.ROE_DTC_XX = Element_tloc.DTC;
#else
  #error "The ROELITE_DTC_SIGNAL_BYTE_ORDER doesn't have a valid value."
#endif
      ROELITE_DIAGNOSTIC_DATA.ROE_DTC_Stat_XX = Element_tloc.DTCStatus;
      (void)Rte_Call_SwcRoElite_RPortRoEliteSendRoE_OPSendRoE(&ROELITE_DIAGNOSTIC_DATA);
      /* Remove the element immediately */
      (void) SwcRoElite_QueueRemoveFirstElement();
    }
  }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SwcRoElite_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Service Calls:
 * ==============
 *   Service Invocation:
 *   -------------------
 *   Std_ReturnType Rte_Call_SwcRoElite_GetStatusMask_GetStatusMask(UInt8 *sam)
 *     Synchronous Service Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_StatusAvailabilityMask_E_NOT_OK
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_FifoQueue(void)
 *   void Rte_Exit_ExclusiveArea_FifoQueue(void)
 *
 *********************************************************************************************************************/

FUNC(void, RTE_SWCROELITE_APPL_CODE) SwcRoElite_Init(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcRoElite_Init
 *********************************************************************************************************************/

  Std_ReturnType ResultValue_t;

  ((uint8*)(&ROELITE_DIAGNOSTIC_DATA.ROE_Header_XX))[ROELITE_DIAGNOSTICDATA_PCI_POSITION] =                 ROELITE_DIAGNOSTICDATA_DEFAULT_PCI;
  ((uint8*)(&ROELITE_DIAGNOSTIC_DATA.ROE_Header_XX))[ROELITE_DIAGNOSTICDATA_POSITIVERESPONSE_POSITION]  =   ROELITE_DIAGNOSTICDATA_DEFAULT_POSITIVERESPONSE;
  ((uint8*)(&ROELITE_DIAGNOSTIC_DATA.ROE_Header_XX))[ROELITE_DIAGNOSTICDATA_REPORTEDDTCSTATUS_POSITION] =   ROELITE_DIAGNOSTICDATA_DEFAULT_REPORTEDDTCSTATUS;
  
  ResultValue_t = Rte_Call_SwcRoElite_GetStatusMask_GetStatusMask( &(((uint8*)(&ROELITE_DIAGNOSTIC_DATA.ROE_Header_XX))[ROELITE_DIAGNOSTICDATA_STATUSAVAILABILITYMASK_POSITION]) );
  
  if(RTE_E_StatusAvailabilityMask_E_NOT_OK == ResultValue_t)
  {
    ((uint8*)(&ROELITE_DIAGNOSTIC_DATA.ROE_Header_XX))[ROELITE_DIAGNOSTICDATA_STATUSAVAILABILITYMASK_POSITION] = ROELITE_DIAGNOSTICDATA_DEFAULT_STATUSAVAILABILITYMASK;
  }
  
  #if (STD_ON == ROELITE_DEBUG_MODE)
    if ((4u > ROELITE_QUEUE_SIZE) || (8u < ROELITE_QUEUE_SIZE))
    {
      SwcRoElite_ErrorFlag_bl = TRUE;
    }
    else
    {
      SwcRoElite_ErrorFlag_bl = FALSE;
    }
  #endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: SwcRoElite_StatusChangeHandler
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <DTCStatusChanged> of PortPrototype <SwcRoElite_DtcStatusChange>
 *
 **********************************************************************************************************************
 *
 * Inter Runnable Variables:
 * =========================
 *   Explicit Read Access:
 *   ---------------------
 *   UInt8 Rte_IrvRead_SwcRoElite_StatusChangeHandler_QueueEntries(void)
 *   UInt8 Rte_IrvRead_SwcRoElite_StatusChangeHandler_QueueReadIndex(void)
 *   UInt8 Rte_IrvRead_SwcRoElite_StatusChangeHandler_QueueWriteIndex(void)
 *
 *   Explicit Write Access:
 *   ----------------------
 *   void Rte_IrvWrite_SwcRoElite_StatusChangeHandler_QueueEntries(UInt8 data)
 *   void Rte_IrvWrite_SwcRoElite_StatusChangeHandler_QueueReadIndex(UInt8 data)
 *   void Rte_IrvWrite_SwcRoElite_StatusChangeHandler_QueueWriteIndex(UInt8 data)
 *
 * Exclusive Area Access:
 * ======================
 *   void Rte_Enter_ExclusiveArea_FifoQueue(void)
 *   void Rte_Exit_ExclusiveArea_FifoQueue(void)
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType SwcRoElite_StatusChangeHandler(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_CallbackDTCStatusChange_E_NOT_OK
 *
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_StatusChangeHandler(Dem_DTCType DTC, Dem_DTCKindType DTCKind, Dem_DTCStatusMaskType DTCStatusOld, Dem_DTCStatusMaskType DTCStatusNew)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: SwcRoElite_StatusChangeHandler (returns application error)
 *********************************************************************************************************************/

  Std_ReturnType ReturnValue_t = RTE_E_OK;
  (void) DTCKind;
  #if (STD_ON == ROELITE_DEBUG_MODE)
    if(TRUE == SwcRoElite_ErrorFlag_bl)
    {
      ReturnValue_t = RTE_E_CallbackDTCStatusChange_E_NOT_OK;
    }
    else
  #endif
  {
    SwcRoElite_QueueElementType Element_tloc;
    if(((DTCStatusOld & ROELITE_DTC_STATUS_TESTNOTCOMPLETEDSINCELASTCLEAR) == 0u) && 
       ((DTCStatusNew & ROELITE_DTC_STATUS_TESTNOTCOMPLETEDSINCELASTCLEAR) != 0u))
    { /* ClearDTC */
      (void) SwcRoElite_QueueClear();
    }
    else if(((DTCStatusOld & ROELITE_DTC_STATUS_TESTFAILED)   != (DTCStatusNew & ROELITE_DTC_STATUS_TESTFAILED)) ||
            ((DTCStatusOld & ROELITE_DTC_STATUS_PENDINGDTC)   != (DTCStatusNew & ROELITE_DTC_STATUS_PENDINGDTC)) ||
            ((DTCStatusOld & ROELITE_DTC_STATUS_CONFIRMEDDTC) != (DTCStatusNew & ROELITE_DTC_STATUS_CONFIRMEDDTC)))
    {
      Element_tloc.DTC = DTC;
      Element_tloc.DTCStatus = DTCStatusNew;
      (void) SwcRoElite_QueueAddElement(&Element_tloc);
    }
    else
    {
      /* no relevant status change */
    }
  }
  return ReturnValue_t;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define RTE_STOP_SEC_SWCROELITE_APPL_CODE
#include "MemMap.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#define RTE_START_SEC_SWCROELITE_APPL_CODE
#include "MemMap.h"

/**************************************************************************************************
   Function name    : SwcRoElite_QueueAddElement
   ------------------------------------------------------------------------------------------------
   Description      : Adds or updates a queue element
   ------------------------------------------------------------------------------------------------
   Called by        : SwcRoElite_StatusChangeHandler
   ------------------------------------------------------------------------------------------------
   Parameter        : IN NewElement_pt: Pointer to the new queue element
   ------------------------------------------------------------------------------------------------
   Returncode       : ROELITE_QUEUE_ENTRY_UPDATED : Element was found in queue and updated
                      ROELITE_QUEUE_FULL          : Queue is full, element was not added
                      ROELITE_QUEUE_ENTRY_ADDED   : Element was added to queue
   ------------------------------------------------------------------------------------------------
   Misc             : 
**************************************************************************************************/
STATIC FUNC(SwcRoElite_QueueReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_QueueAddElement
(
  P2CONST(SwcRoElite_QueueElementType, AUTOMATIC, AUTOMATIC) NewElement_pt
)
{
  SwcRoElite_QueueReturnType ReturnValue_t;
  uint8 Loop_u8loc;
  uint8 ElementIndex_u8loc;
  const uint8 ElementCount_u8loc = ROELITE_QUEUE_READ_ENTRIES(SwcRoElite_StatusChangeHandler);

  Rte_Enter_ExclusiveArea_FifoQueue();
  
  ReturnValue_t      = ROELITE_QUEUE_ENTRY_ADDED;
  ElementIndex_u8loc = ROELITE_QUEUE_READ_READINDEX(SwcRoElite_StatusChangeHandler);
  Loop_u8loc         = 0u;
  while ((Loop_u8loc < ElementCount_u8loc) && (ROELITE_QUEUE_ENTRY_UPDATED != ReturnValue_t))
  {
    if (ROELITE_QUEUE[ElementIndex_u8loc].DTC == NewElement_pt->DTC)
    {
      /* Element already exists */
      ROELITE_QUEUE[ElementIndex_u8loc].DTCStatus = NewElement_pt->DTCStatus;
      ReturnValue_t = ROELITE_QUEUE_ENTRY_UPDATED;
    }
    /* next entry position */
    if (ElementIndex_u8loc == (ROELITE_QUEUE_SIZE - 1))
    {
      ElementIndex_u8loc = 0u;
    }
    else
    {
      ++ElementIndex_u8loc;
    }
    ++Loop_u8loc; /* next entry */
  }

  if(ROELITE_QUEUE_ENTRY_UPDATED == ReturnValue_t)
  {
    /* Queue entry updated, return this */
  }
  else if (ElementCount_u8loc >= ROELITE_QUEUE_SIZE)
  {
    /* write failed -> FIFO is full */
    ReturnValue_t = ROELITE_QUEUE_FULL;
  }
  else
  {
    /* write one new entry */
    ROELITE_QUEUE[ROELITE_QUEUE_READ_WRITEINDEX(SwcRoElite_StatusChangeHandler)].DTC = NewElement_pt->DTC;
    ROELITE_QUEUE[ROELITE_QUEUE_READ_WRITEINDEX(SwcRoElite_StatusChangeHandler)].DTCStatus = NewElement_pt->DTCStatus;

    /* set new write token */
    if (ROELITE_QUEUE_READ_WRITEINDEX(SwcRoElite_StatusChangeHandler) == (ROELITE_QUEUE_SIZE - 1))
    {
      ROELITE_QUEUE_WRITE_WRITEINDEX(SwcRoElite_StatusChangeHandler, 0);
    }
    else
    {
      ROELITE_QUEUE_WRITE_WRITEINDEX(SwcRoElite_StatusChangeHandler, (ROELITE_QUEUE_READ_WRITEINDEX(SwcRoElite_StatusChangeHandler) + 1u));
    }
    /* increment number of fifo entries */
    ROELITE_QUEUE_WRITE_ENTRIES(SwcRoElite_StatusChangeHandler, (ROELITE_QUEUE_READ_ENTRIES(SwcRoElite_StatusChangeHandler) + 1u));
  }
  /* new FIFO entry successful written */

  Rte_Exit_ExclusiveArea_FifoQueue();
  return ReturnValue_t;
}

/**************************************************************************************************
   Function name    : SwcRoElite_QueueGetFirstElement
   ------------------------------------------------------------------------------------------------
   Description      : Returns the first element of the queue
   ------------------------------------------------------------------------------------------------
   Called by        : SwcRoElite_Cyclic
   ------------------------------------------------------------------------------------------------
   Parameter        : OUT NewElement_pt: Placeholder for the first queue element
   ------------------------------------------------------------------------------------------------
   Returncode       : ROELITE_QUEUE_EMPTY       : Queue is empty, no element data was copied
                      ROELITE_QUEUE_ENTRY_FOUND : Entry exists and data was copied to pointer
   ------------------------------------------------------------------------------------------------
   Misc             : 
**************************************************************************************************/
STATIC FUNC(SwcRoElite_QueueReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_QueueGetFirstElement(P2VAR(SwcRoElite_QueueElementType, AUTOMATIC, AUTOMATIC) NewElement_pt)
{
  SwcRoElite_QueueReturnType ReturnValue_t;
  
  ReturnValue_t = ROELITE_QUEUE_ENTRY_FOUND;

  Rte_Enter_ExclusiveArea_FifoQueue();
  if(0u == ROELITE_QUEUE_READ_ENTRIES(SwcRoElite_Cyclic))
  {
    ReturnValue_t = ROELITE_QUEUE_EMPTY;
  }
  else
  {
    NewElement_pt->DTCStatus = ROELITE_QUEUE[ROELITE_QUEUE_READ_READINDEX(SwcRoElite_Cyclic)].DTCStatus;
    NewElement_pt->DTC = ROELITE_QUEUE[ROELITE_QUEUE_READ_READINDEX(SwcRoElite_Cyclic)].DTC;
  }
  Rte_Exit_ExclusiveArea_FifoQueue();

  return ReturnValue_t;
}

/**************************************************************************************************
   Function name    : SwcRoElite_QueueRemoveFirstElement
   ------------------------------------------------------------------------------------------------
   Description      : Removes the first element of the queue
   ------------------------------------------------------------------------------------------------
   Called by        : SwcRoElite_TxAck
   ------------------------------------------------------------------------------------------------
   Parameter        : None
   ------------------------------------------------------------------------------------------------
   Returncode       : ROELITE_QUEUE_EMPTY       : Queue is empty, no element was removed
                      ROELITE_QUEUE_ENTRY_FOUND : Entry exists and was removed from the queue
   ------------------------------------------------------------------------------------------------
   Misc             : 
**************************************************************************************************/
STATIC FUNC(SwcRoElite_QueueReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_QueueRemoveFirstElement(void)
{
  SwcRoElite_QueueReturnType ReturnValue_t;

  ReturnValue_t = ROELITE_QUEUE_ENTRY_FOUND;

  Rte_Enter_ExclusiveArea_FifoQueue();
  if(0u == ROELITE_QUEUE_READ_ENTRIES(SwcRoElite_Cyclic))
  { /* queue empty */
    ReturnValue_t = ROELITE_QUEUE_EMPTY;
  }
  else
  {
    if((ROELITE_QUEUE_SIZE - 1u) == ROELITE_QUEUE_READ_READINDEX(SwcRoElite_Cyclic))
    { /* turnaround - restart with read index from zero */
      ROELITE_QUEUE_WRITE_READINDEX(SwcRoElite_Cyclic, 0u);
    }
    else
    { /* increment read index */
      ROELITE_QUEUE_WRITE_READINDEX(SwcRoElite_Cyclic,(ROELITE_QUEUE_READ_READINDEX(SwcRoElite_Cyclic) + 1u));
    }
    ROELITE_QUEUE_WRITE_ENTRIES(SwcRoElite_Cyclic, (ROELITE_QUEUE_READ_ENTRIES(SwcRoElite_Cyclic) - 1u));
  }
  Rte_Exit_ExclusiveArea_FifoQueue();

  return ReturnValue_t;
}

/**************************************************************************************************
   Function name    : SwcRoElite_QueueClear
   ------------------------------------------------------------------------------------------------
   Description      : Removes all elements from the queue
   ------------------------------------------------------------------------------------------------
   Called by        : SwcRoElite_StatusChangeHandler
   ------------------------------------------------------------------------------------------------
   Parameter        : None
   ------------------------------------------------------------------------------------------------
   Returncode       : ROELITE_QUEUE_EMPTY       : Queue is empty, all elements were removed
   ------------------------------------------------------------------------------------------------
   Misc             : 
**************************************************************************************************/
STATIC FUNC(SwcRoElite_QueueReturnType, RTE_SWCROELITE_APPL_CODE) SwcRoElite_QueueClear(void)
{
  Rte_Enter_ExclusiveArea_FifoQueue();

  if(0u != ROELITE_QUEUE_READ_ENTRIES(SwcRoElite_StatusChangeHandler))
  {
    uint8 Loop_u8loc;
    for(Loop_u8loc=0u;Loop_u8loc<ROELITE_QUEUE_SIZE;Loop_u8loc++)
    {
      ROELITE_QUEUE[Loop_u8loc].DTC = 0u;
      ROELITE_QUEUE[Loop_u8loc].DTCStatus = 0u;
    }
    ROELITE_QUEUE_WRITE_ENTRIES(SwcRoElite_StatusChangeHandler, 0u);
  }
  ROELITE_QUEUE_WRITE_WRITEINDEX(SwcRoElite_StatusChangeHandler, 0u);
  ROELITE_QUEUE_WRITE_READINDEX(SwcRoElite_StatusChangeHandler, 0u);

  Rte_Exit_ExclusiveArea_FifoQueue();
  return ROELITE_QUEUE_EMPTY;
}

#define RTE_STOP_SEC_SWCROELITE_APPL_CODE
#include "MemMap.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
