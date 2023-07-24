/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     ADC420HA10
  CPU:         AURIX TC38XP
  MODULNAME:   TEMPLATE
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/**
 *  \file      MTSI_Pal.h
 *  \brief     MTSI Platform abstraction layer header file.
 *  \date      05.12.2020
 *  \copyright Continental AG
 *
 *  PAL layer of MTSI used to send MTS debug data using specific platform hardware.
 *
 */

#ifndef MTSI_PAL_H_
#define MTSI_PAL_H_

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================================================================================================= */
/*                                            QAC Warnings Suppressions                                              */
/*                                           (Global Files Suppressions)                                             */
/* ================================================================================================================= */
/* PRQA S 6040 EOF */  /* uib56245: Justification description */

/* ================================================================================================================= */
/*                                                Include Files                                                      */
/* ================================================================================================================= */
#include <Platform_Types_Conti.h>
#include "MTSI_Types.h"
#include "MTSI_Cfg.h"
/** @defgroup Productive Productive code
 *  @{
 */

 /** @defgroup MTSI_PAL MTSI_PAL
 *  @{
 */

/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                                Public Types                                                       */
/* ================================================================================================================= */

/** @brief Function pointer type used for the definition of the "Transmission Done Callback", invoked on a synchronous/asynchronous completed transfer.  */
typedef void (*MTSI_t_TransmissionDoneCbk)(const uint8 LaneId);
/** @brief Function pointer type used for the definition of the "Transmission Trigger", used when necessary to trigger a transmission at PAL level. */
typedef void (*MTSI_t_TransmissionTriggerCbk)(void);

/** @brief Function pointer type used for the definition of the callback invoked on the start a new MTA frame, */
typedef void (*MTSI_t_StartMTAFrameCbk)(const uint8 LaneId);

/** @brief Function pointer for the callback to trigger transmission on core 0 */
typedef void (*MTSI_t_TriggerTransmissionCbk)(void);

/** @brief Enumeration used for PAL status reporting towards the upper MTSi Driver level */
typedef enum
{
  MTSI_E_OK           = 0,  ///< Requested operation (queue/ trigger transmit) completed successfully.
  MTSI_E_NOK          = 1,  ///< Requested operation (queue/ trigger transmit) failed.
  MTSI_E_TRIG_REQUEST = 2,  ///< DMA queuing not possible, buffer full, transmission trigger mandatory. (not a error case)
  MTSI_E_NO_REQUEST   = 3   ///< No operation requested. (eg: nothing to queue at PAL level)
} t_MTSi_Std_ReturnType;

/** @brief Enumeration used for status of the HSSL module. */
typedef enum
{
  HSSL_TRANSMISSION_IDLE          = 0, ///< No transmission in progress
  HSSL_TRANSMISSION_PENDING       = 1, ///< Transmission waiting to be sent
  HSSL_TRANSMISSION_FREEZE_INFO   = 2, ///< Transmission of Freeze Info is in progress
  HSSL_TRANSMISSION_PAYLOAD       = 3, ///< Transmission of Payload is in progress
  HSSL_TRANSMISSION_MTA_SIGNATURE = 4  ///< Transmission of MTA Signature is in progress
} t_HsslTransmissionState;
/* ================================================================================================================= */
/*                                          Public Variables Declarations                                            */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                           Public Functions Declarations                                           */
/* ================================================================================================================= */
/** ************************************************************************************** 
 @brief Initialization of platform abstraction for MTSI

 @pre                                    MTSI_CustomInit function has been called successfully in MTSI_Driver.c
 @post                                   The MTSi module is fully initialized and can process data freeze requests.

 @param[in] Mode                         Requested Output mode of MTSI [OFF, Mode 1 - 4]
 @param[in] InstanceNr                   Requested Instance number that is sent in MTA frame
 @param[in] p_TransmissionDoneCbk        Callback that is invoked after a asynchronous/synchronous transmission is completed.
 @param[in] p_StartMTAFrameCbk           Callback to finish current MTA frame and start a new one
 @param[in] p_TriggerTransmissionCbk     Callback to trigger transmission from any other core than core 0

 @globals
                    @ref OutputMode \n
                    @ref p_TransmissionDoneCallback \n
                    @ref ModuleStatePAL \n
                    @ref HsslTransmissionState \n
                    @ref FirstFragment

 @InOutCorrelation
                    "OutputMode" is set to the input parameter "Mode". "p_TransmissionDoneCbk" and "p_TriggerTransmissionCbk" are stored in globals.
                    "ModuleStatePAL" is set to "MODULE_INITIALIZED" if calls of other Init functions were successfully finished after "ModuleStatePAL" was "MODULE_UNINITIALIZED".
                    If the ModuleStatePAL was already "MODULE_PREINITIALIZED", it is set to "MODULE_INITIALIZED".

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalInit
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalInit
   activate MTSI_Pal
     alt (MODULE_UNINITIALIZED == ModuleStatePAL) || (MODULE_DEINITIALIZED == ModuleStatePAL)
       MTSI_Pal -> HSSL: HSSL_SetTransmissionDoneCbk
       activate HSSL
       HSSL --> MTSI_Pal
       deactivate HSSL
     end

    MTSI_Pal --> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
   if (Module is Uninit or Deinit) then (yes)
     :Send pointer for Callback function to HSSL layer;
     :Init global variables;
     :Change module state to Init;
   else (no)
   endif
   stop
 @enduml

 @traceability
   @satisfy{ADC420_L3_SW_18582}
 @testmethod
            TEST_MTSI_Pal_Init_Deinit() : Testing of the MTSi PAL initialization phase function with different settings/scenarios. \n
************************************************************************************** **/
void MTSI_PalInit(const uint8 Mode, const uint8 InstanceNr, const MTSI_t_TransmissionDoneCbk p_TransmissionDoneCbk, const MTSI_t_StartMTAFrameCbk p_StartMTAFrameCbk, const MTSI_t_TriggerTransmissionCbk p_TriggerTransmissionCbk);

/** **************************************************************************************
 @brief               Deinitialization of platform abstraction for MTSI

 @pre                 MTSI_PalInit function has been called before.
 @post                The MTSi module cannot process data freeze requests anymore.
 @globals
                      @ref ModuleStatePAL
 @InOutCorrelation
                      "ModuleStatePAL" is set to "MODULE_UNINITIALIZED"

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalDeInit
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalDeInit
  activate MTSI_Pal
  MTSI_Pal --> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     :Change module state to DeInit;
   stop
 @enduml

 @traceability N/A
 @testmethod
              TEST_MTSI_Pal_Init_Deinit() : Testing of the MTSi PAL deinitialization phase function with different settings/scenarios. \n
******************************************************************************************/
void MTSI_PalDeInit(void);

/** **************************************************************************************
 @brief               Exit MTSI Exclusive Area

 @pre                 Exclusive Area was previously entered.
 @post                OS Resource will be released.
 @globals             none
 @InOutCorrelation
                      Exclusive Area will be exited.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalExitExclusiveArea
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalExitExclusiveArea
   activate MTSI_Pal
   MTSI_Pal -> RTE: Rte_Exit_ExclusiveAreaMTSI
     activate RTE
     RTE --> MTSI_Pal
     deactivate RTE
  MTSI_Pal --> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     if(ExclusiveAreaEntered is TRUE(entered)) then(yes)
       :Change ExclusiveAreaEntered to FALSE;
       :Call Rte_Exit_ExclusiveAreaMTSI;
     else(no)
     endif
   stop
 @enduml

 @traceability
   @satisfy{ADC420_L3_SW_22520}
 @testmethod
             TEST_MTSI_PalEnterExitExclusiveArea() : Test the MTSi specific ExclusiveArea is entered/exit properly. \n
****************************************************************************************/
void MTSI_PalExitExclusiveArea(void);

/** **************************************************************************************
 @brief               Enter MTSI Exclusive Area

 @pre                 none
 @post                OS Resource will be acquired.
 @globals             none
 @InOutCorrelation
                      Exclusive Area will be entered.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalEnterExclusiveArea
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalEnterExclusiveArea
   activate MTSI_Pal
   MTSI_Pal -> RTE: Rte_Enter_ExclusiveAreaMTSI
     activate RTE
     RTE --> MTSI_Pal
     deactivate RTE
  MTSI_Pal --> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     if(ExclusiveAreaEntered is FALSE(not entered)) then(yes)
       :Call Rte_Enter_ExclusiveAreaMTSI;
       :Change ExclusiveAreaEntered to TRUE;
     else(no)
     endif
   stop
 @enduml

 @traceability
   @satisfy{ADC420_L3_SW_22520}
 @testmethod
             TEST_MTSI_PalEnterExitExclusiveArea() : Test the MTSi specific ExclusiveArea is entered/exit properly. \n
****************************************************************************************/
t_MTSi_Std_ReturnType MTSI_PalEnterExclusiveArea(void);

/** **************************************************************************************
 @brief               Get timestamp in microseconds [&mu;s]

 @pre                 none
 @post                none
 @return              uint32
 @globals             none
 @InOutCorrelation
                      StbM interface will be called to retrieve synchronized timestamp.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalGetTimestamp
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalGetTimestamp
   activate MTSI_Pal
   MTSI_Pal -> RTE: Rte_Call_CDD_MTSI_RPortStbMGlobalTimeSlave_GetCurrentTime
     activate RTE
     RTE --> MTSI_Pal
     deactivate RTE
  MTSI_Pal -> ENV: ui32_timeStamp
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     :Call Rte_Call_CDD_MTSI_RPortStbMGlobalTimeSlave_GetCurrentTime;
     :Convert nanoseconds and seconds to microseconds;
   stop
 @enduml

 @traceability N/A
 @testmethod
             TEST_MTSI_Pal_EmptyMTAframe() : Timestamp of Start MTA frame is checked. \n
             TEST_MTSI_Pal_OneAsyncJobMTAframe() : Timestamp of Start MTA frame is checked. \n
             TEST_MTSI_Pal_MultipleMTAFrames_MultipleJobs() : Timestamp of Start MTA frame is checked. \n
****************************************************************************************/
uint32 MTSI_PalGetTimestamp(void);

/** **************************************************************************************
 @brief              Get core ID

 @pre                none
 @post               none
 @return             uint8
 @globals            none
 @InOutCorrelation
                     Returns CoreID.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalGetCoreId
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalGetCoreId
   activate MTSI_Pal
   MTSI_Pal -> ENV: CoreID
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @traceability N/A
 @testmethod
             MTSI_PalGetCoreId() : Test get core ID. \n
****************************************************************************************/
uint8 MTSI_PalGetCoreId(void);

/** **************************************************************************************
 @brief               Trigger transmission from any other core than core 0. Not used for HSSL MTSI

 @pre                 none
 @post                none
 @globals             none

 @traceability N/A
 @testmethod
             TEST_MTSI_Pal_cov() : Basic walkthrough.
****************************************************************************************/
void MTSI_PalSetTriggerTransmissionEvent(void);

/** **************************************************************************************
 @brief               Start a new MTA frame

 @pre                 No active MTA frame on the current lane
 @post                MtaDriverFrameState will change to MTA_DRIVER_FRAME_ACTIVE
 @param[in] LaneId    Number of the lane on which a new MTA frame shall be started
 @return              Std_ReturnType

 @globals
                      @ref MtaFrameStart \n
                      @ref SwPacketsCount \n
                      @ref HsslBlockOffset \n
                      @ref MtaDriverFrameState \n
                      @ref MtaFrameCounter \n
 @InOutCorrelation
                      The current timestamp is stored in "MtaFrameStart". "MtaFrameCounter" is incremented. MtaDriverFrameState will change to MTA_DRIVER_FRAME_ACTIVE.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalStartMTAFrame
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalStartMTAFrame
   activate MTSI_Pal
   MTSI_Pal -> MTSI_Pal: MTSI_PalGetTimestamp
   MTSI_Pal -> MTSI_Pal: GetMoeTimestamp
   MTSI_Pal -> ENV: ReturnValue
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     :Store timestamp of MTA frame start;
     :Reset SwPacketsCount and HsslBlockOffset to zero;
     :Get Timestamp for MTA Signature;
     :Increment MTA frame counter;
     :Change Frame State to ACTIVE;
     :Return OK;
   stop
 @enduml

 @traceability N/A
 @testmethod
             TEST_MTSI_Pal_EmptyMTAframe() : Test case to send empty MTA frame. \n
             TEST_MTSI_Pal_OneAsyncJobMTAframe() : Test case to send MTA frame with one async job. \n
             TEST_MTSI_Pal_PalQueueMaxedOut() : TEST_MTSI_Pal_PalQueueMaxedOut. \n
             TEST_MTSI_Pal_MultipleMTAFrames_MultipleJobs() : Test case to send 2 MTA frame with multiple async jobs. \n
****************************************************************************************/
Std_ReturnType MTSI_PalStartMTAFrame(const uint8 LaneId);

/** **************************************************************************************
 @brief               Finish the current MTA frame

 @pre                 There is an active MTA frame on the current lane
 @post                MtaDriverFrameState will change to MTA_DRIVER_FRAME_INACTIVE
 @param[in] LaneId    Number of the lane on which a new MTA frame shall be finished
 @return              Std_ReturnType

 @globals
                      @ref FirstFragment \n
                      @ref HsslTransmissionState \n
                      @ref HsslBlockIndex \n
                      @ref MtaDriverFrameState \n
 @InOutCorrelation
                      MTA signature will be sent to MTA board. MTA frame will be finished.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalFinishMTAFrame
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalStartMTAFrame
    activate MTSI_Pal
    MTSI_Pal -> HSSL: HSSL_SendStreamBlock
    HSSL -> MTSI_Pal: HsslTransmissionStatus
    deactivate HSSL
  MTSI_Pal -> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     :Update the MTA signature;
     if(FirstFragment is TRUE) then(yes)
       :Set Valid to First Fragment;
     else(no)
     endif
     if(HSSL_TRANSMISSION_IDLE == HsslTransmissionState) then(yes)
       :MTA signature transmission is in progress, change HSSL state to MTA_SIGNATURE;
       :Send the MTA signature over HSSL transmission;
       if(HSSL_E_OK == HsslTransmissionStatus) then(yes)
         :Increment Block Index;
         :Transmission succesfully done, return OK;
       else(no)
         :Transmission not ok, change state to IDLE;
       endif
     else(no)
     endif
   stop
 @enduml

 @traceability N/A
 @testmethod
             TEST_MTSI_Pal_EmptyMTAframe() : Test case to send empty MTA frame. \n
             TEST_MTSI_Pal_OneAsyncJobMTAframe() : Test case to send MTA frame with one async job. \n
             TEST_MTSI_Pal_PalQueueMaxedOut() : TEST_MTSI_Pal_PalQueueMaxedOut. \n
             TEST_MTSI_Pal_MultipleMTAFrames_MultipleJobs() : Test case to send 2 MTA frame with multiple async jobs. \n
****************************************************************************************/
Std_ReturnType MTSI_PalFinishMTAFrame(const uint8 LaneId);

/** **************************************************************************************
 Get the timestamp of the recent MTA frame start

 @pre                 Gets timestamp when MTA frame was started
 @post                none
 @param[in] LaneId    Number of the lane on which the MTA frame has been started
 @return              uint32
 @globals
                      @ref MtaFrameStart
 @InOutCorrelation
                      The timestamp is retrieved from "MtaFrameStart" and is then returned
 @traceability        N/A
 @testmethod
             TEST_MTSI_Pal_EmptyMTAframe() : Timestamp of Start MTA frame is checked. \n
             TEST_MTSI_Pal_OneAsyncJobMTAframe() : Timestamp of Start MTA frame is checked. \n
             TEST_MTSI_Pal_MultipleMTAFrames_MultipleJobs() : Timestamp of Start MTA frame is checked. \n
****************************************************************************************/
uint32 MTSI_PalGetMtaFrameStart(const uint8 LaneId);

/** **************************************************************************************
 @brief               Get the number of MTA frames that have been started

 @pre                 MTA frame was started
 @post                none
 @param[in] LaneId    Number of the lane on which the MTA frame has been started
 @return              uint16
 @globals
                      @ref MtaFrameCounter <br>
 @InOutCorrelation
                      The number of MTA frames is retrieved from "MtaFrameCounter" and is then returned
 @traceability        N/A
 @testmethod
             TEST_MTSI_Pal_EmptyMTAframe() : Test case to send empty MTA frame. \n
             TEST_MTSI_Pal_OneAsyncJobMTAframe() : Test case to send MTA frame with one async job. \n
             TEST_MTSI_Pal_PalQueueMaxedOut() : TEST_MTSI_Pal_PalQueueMaxedOut. \n
             TEST_MTSI_Pal_MultipleMTAFrames_MultipleJobs() : Test case to send 2 MTA frame with multiple async jobs. \n
****************************************************************************************/
uint16 MTSI_PalGetMtaFrameCounter(const uint8 LaneId);


/** **************************************************************************************
 @brief                     Flushes the uC cache memory into RAM (synchronizes the RAM memory with the cache memory). Not used for HSSL MTSI.

 @pre                       none
 @post                      none
 @param[in] blockPtr        Memory block address that is targeted for the cache/RAM synchronization. (optional parameter)
 @param[in] byteCnt         Size (in bytes) of the memory area that has to be synchronized with the cache.
 @globals                   none
 @InOutCorrelation          none
 @traceability              N/A
 @testmethod
              TEST_MTSI_Pal_cov() : Basic walkthrough. \n
****************************************************************************************/
void MTSI_PalFlushCache(const void* const blockPtr, const uint32 byteCnt);


/** **************************************************************************************
 @brief                   Convert MTS header endianness <br>
                          The endianness of all elements within the MTS header is converted
 @pre                     Mutual exclusion region was entered before
 @post                    none
 @param[in] p_Header      Mutex region which shall be left
 @return                  MTSI_t_Header
 @globals                 none
 @InOutCorrelation
                          The endianness of each element within the MTS header is converted and the result is returned.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalConvertHeaderEndianness
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalConvertHeaderEndianness
   activate MTSI_Pal
   MTSI_Pal -> ENV: MTSI_t_Header
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     :Convert header endianess;
   stop
 @enduml

 @traceability N/A
 @testmethod
             MTSI_PalConvertHeaderEndianness() : Test convert header endianess.
****************************************************************************************/
MTSI_t_Header MTSI_PalConvertHeaderEndianness(MTSI_t_Header const * const p_Header);

/** **************************************************************************************
 @brief                     Swap the endianness of a uint16 variable <br>

 @pre                       Mutual exclusion region was entered before
 @post                      none
 @param[in] p_Data          Data of which the endianness shall be swapped
 @return                    uint16
 @globals                   none
 @InOutCorrelation
                            The endianness of a uint16 variable is converted and the result is returned.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalSwapUINT16
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalSwapUINT16
   activate MTSI_Pal
   MTSI_Pal -> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     :Swap the endianness of a uint16;
   stop
 @enduml

 @traceability              N/A
 @testmethod
             TEST_MTSI_PalSwapUINT() : Check endianess swap is done properly. \n
****************************************************************************************/
uint16 MTSI_PalSwapUINT16(uint16 const * const p_Data);


/** **************************************************************************************
 @brief                     Swap the endianness of a uint32 variable <br>
 @pre                       Mutual exclusion region was entered before
 @post                      none
 @param[in] p_Data          Data of which the endianness shall be swapped
 @return                    uint32
 @globals                   none
 @InOutCorrelation
                            The endianness of a uint32 variable is converted and the result is returned.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalSwapUINT32
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalSwapUINT32
   activate MTSI_Pal
   MTSI_Pal -> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
     :Swap the endianness of a uint32;
   stop
 @enduml

 @traceability              N/A
 @testmethod
             TEST_MTSI_PalSwapUINT() : Check endianess swap is done properly. \n
****************************************************************************************/
uint32 MTSI_PalSwapUINT32(uint32 const * const p_Data);


/** **************************************************************************************
 @brief               Queue request for a SyncBuffer at MTSi Pal level. \n
                      The actual transmission triggered in the MTSI_PalTriggerTransmission function.

 @pre                 MTSi module must be initialized
 @post                none
 @param[in] LaneId    Number of the lane on which the sync buffer must be sent
 @param[in] p_Data    Pointer to the sync buffer
 @param[in] Length    Length of the sync buffer
 @return              t_MTSi_Std_ReturnType

 @globals             none

 @InOutCorrelation
                      Synchronous measfreezes are not implemented for HSSL MTSI. Function is empty but needed for upper layer MTSI Driver.

 @traceability
 @testmethod
             TEST_MTSI_Pal_cov() : Basic walkthrough. \n
****************************************************************************************/
t_MTSi_Std_ReturnType MTSI_PalQueueSyncBuffer(const uint8 LaneId, void const * const p_Data, const uint32 Length);

/** **************************************************************************************
 @brief               Queue request for a AsyncQueue entry at MTSi Pal AsyncQueue.
                      The actual transmission triggered in the MTSI_PalTriggerTransmission function.

 @pre                 MTSI header is prepared
 @post                PalQueueTail will be incremented.
 @param[in] LaneId    Number of the lane on which the async job shall be sent
 @param[in] p_Header  Pointer to the MTSI header
 @param[in] p_Data    Pointer to the application data
 @return              t_MTSi_Std_ReturnType

 @globals
                      @ref PalAsyncQueue \n
                      @ref PalQueueTail \n
                      @ref QueueNrOfFrames \n

 @InOutCorrelation
                      If PalAsyncQueue can receive one more request, the job will be store in the Queue at PalQueueTail index and
                      PalQueueTail will be incremented. The number of HSSL frames will be incremented one time for FreezeInfo +
                      the required frames for payload.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalQueueAsyncJob
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalQueueAsyncJob
   activate MTSI_Pal
     alt (HSSL_TRANSMISSION_IDLE == HsslTransmissionState) && (MTA_DRIVER_FRAME_ACTIVE == MtaDriverFrameState) && (CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_0 > PalQueueTail)
       MTSI_Pal -> MTSI_Pal: GetNumberOfHsslFrames
     end
   MTSI_Pal -> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
   if (MODULE_INITIALIZED == ModuleStatePAL) then (yes)
     if((HSSL_TRANSMISSION_IDLE == HsslTransmissionState) && (MTA_DRIVER_FRAME_ACTIVE == MtaDriverFrameState) && (CFG_MTSI_SIZE_OF_ASYNC_QUEUE_CORE_0 > PalQueueTail)) then (yes)
       if((NULL != p_Header) && (NULL != p_Data)) then (yes)
         :Update Freeze Info and queue SwFreezeHeader;
         :Queue the pointer for current async job and send it later when PalTriggerTransmission is called;
         :Increment one time the number of freezes for Freeze Info;
         :Increment with the required number of frames for the received freeze payload;
         :Increment the Queue Tail with one more job;
         :Change status to OK;
       else (no)
       endif
     else (no)
       :Request TriggerTransmission;
     endif
   else (no)
   endif
   stop
 @enduml

 @traceability
  @satisfy{ADC420_L3_SW_21911}
  @satisfy{GUID_653db10a-7a5c-47ec-8ffd-a224be02b46f}
 @testmethod
             TEST_MTSI_Pal_NULL_pdata_NULL_header() : Test case to check if MTSI_PalQueueAsyncJob accepts NULL_PTR. \n
             TEST_MTSI_Pal_OneAsyncJobMTAframe() : Timestamp of Start MTA frame is checked. \n
             TEST_MTSI_Pal_PalQueueMaxedOut() : TEST_MTSI_Pal_PalQueueMaxedOut. \n
             TEST_MTSI_Pal_MultipleMTAFrames_MultipleJobs() : Timestamp of Start MTA frame is checked. \n
             TEST_MTSI_Pal_Init_Deinit() : Testing of the MTSi PAL deinitialization phase function with different settings/scenarios. \n
             TEST_MTSI_Pal_HSSL_failing_on_AsyncJobPayload() : Test case where HSSL transmission is failing when called by AsyncJobPayload. \n
             TEST_MTSI_Pal_HSSL_failing_on_AsyncJobFreezeInfo(0 : Test case where HSSL transmission is failing when called by AsyncJobFreezeInfo. \n
****************************************************************************************/
t_MTSi_Std_ReturnType MTSI_PalQueueAsyncJob(const uint8 LaneId, MTSI_t_Header const * const p_Header, void const * const p_Data);

/** **************************************************************************************
 @brief               Trigger a HSSL transfer of the currently queued MTSi data.

 @pre                 MTSI is initialized.
 @post                none
 @param[in] LaneId    Number of the lane on which the data transfer must be initiated.
 @return              t_MTSi_Std_ReturnType
 @globals
                      @ref HsslTransmissionState \n
 @InOutCorrelation
                      If data is available in the PalQueue, a HSSL transfer will be triggered.

 @callsequence
 @startuml
  title Sequence Diagram for MTSI_PalTriggerTransmission
  activate ENV
  ENV -> MTSI_Pal: MTSI_PalTriggerTransmission
   activate MTSI_Pal
   alt (0u != PalQueueTail) && (0u == PalQueueHead)
       MTSI_Pal -> MTSI_Pal: HsslSendAsyncJob
   end
   MTSI_Pal -> ENV
  deactivate MTSI_Pal
  deactivate ENV
 @enduml

 @startuml
   title Activity Diagram
   start
   if (MTSI_OUTPUTMODE_1 == OutputMode) then (yes)
     if((0u != PalQueueTail) && (0u == PalQueueHead)) then (yes)
       :Set transmission state to PENDING;
       :Send the Async Job over HSSL;
       :Change status to OK;
     else (no)
     endif
   else (no)
   endif
   stop
 @enduml

 @traceability
   @satisfy{ADC420_L3_SW_22051}
   @satisfy{GUID_3b26132d-c6de-4257-bbcd-f9f0d2d98bf0}
 @testmethod
             TEST_MTSI_Pal_NULL_pdata_NULL_header() : Test case to check if MTSI_PalQueueAsyncJob accepts NULL_PTR. \n
             TEST_MTSI_Pal_OneAsyncJobMTAframe() : Timestamp of Start MTA frame is checked. \n
             TEST_MTSI_Pal_PalQueueMaxedOut() : TEST_MTSI_Pal_PalQueueMaxedOut. \n
             TEST_MTSI_Pal_MultipleMTAFrames_MultipleJobs() : Timestamp of Start MTA frame is checked. \n
             TEST_MTSI_Pal_Init_Deinit() : Testing of the MTSi PAL deinitialization phase function with different settings/scenarios. \n
             TEST_MTSI_Pal_HSSL_failing_on_AsyncJobPayload() : Test case where HSSL transmission is failing when called by AsyncJobPayload. \n
             TEST_MTSI_Pal_HSSL_failing_on_AsyncJobFreezeInfo() : Test case where HSSL transmission is failing when called by AsyncJobFreezeInfo. \n
****************************************************************************************/
t_MTSi_Std_ReturnType MTSI_PalTriggerTransmission(const uint8 LaneId);

/** **************************************************************************************
 @brief               Updates the MTSi statistic information and sends it via the generic freeze interface
 @pre                 none
 @post                none
 @globals             none
 @InOutCorrelation
                      Function not used in HSSL MTSI.

 @traceability        N/A
 @testmethod
             TEST_MTSI_Pal_cov() : Basic walkthrough.
****************************************************************************************/
void MTSI_PalUpdateStatistics(void);


/** **************************************************************************************
 @brief               Function to get HsslTransmissionState.
 @pre                 none
 @post                none
 @return              t_HsslTransmissionState
 @globals
                      @ref HsslTransmissionState
 @InOutCorrelation
                      Returns HsslTransmissionState

 @traceability        N/A
 @testmethod
             TEST_MTSI_Pal_HSSL_failing_on_AsyncJobPayload() : Test case where HSSL transmission is failing when called by AsyncJobPayload. \n
****************************************************************************************/
t_HsslTransmissionState MTSI_PalGetHsslTransmissionState(void);

#ifdef __cplusplus
}
#endif

#endif /* MTSI_PAL_H */

/** @} doxygen end group definition  */

/** @} doxygen end group definition  */

/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
