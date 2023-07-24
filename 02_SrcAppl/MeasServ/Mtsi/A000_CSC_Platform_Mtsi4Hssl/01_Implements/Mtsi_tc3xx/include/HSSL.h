/**********************************************************************************************************************
  COMPANY:     Continental Teves AG & Co. OHG
  PROJECT:     ADC420HA22
  CPU:         AURIX TC38XP
  MODULNAME:   HSSL
  VERSION:     $Revision: 1.0 $
 *********************************************************************************************************************/

/**
 *  \file      HSSL.h
 *  \brief     High Speed Serial Link header file.
 *  \date      15.07.2020
 *  \copyright Continental AG
 *
 *  HSSL Module header file.
 *
 */

#ifndef HSSL_H
#define HSSL_H

#ifdef __cplusplus
extern "C"
{
#endif

/* ================================================================================================================= */
/*                                            QAC Warnings Suppressions                                              */
/*                                           (Global Files Suppressions)                                             */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                                Include Files                                                      */
/* ================================================================================================================= */
#include <Platform_Types_Conti.h>
#include "Std_Types.h"
/** @defgroup Productive Productive code
 *  @{
 */
 /** @defgroup HSSL_Module HSSL_Module
 *  @{
 */
/* ================================================================================================================= */
/*                                               Defines & Macros                                                    */
/* ================================================================================================================= */
/** @brief Send frame timeout. */
#define HSSL_SEND_FRAME_TIMEOUT    ((uint16)10000)

/** @brief Frame size. */
#define HSSL_FRAME_SIZE            ((uint8)0x20)
/* ================================================================================================================= */
/*                                                Public Types                                                       */
/* ================================================================================================================= */
/** @brief Enumeration used for status of the HSSL module. */
typedef enum
{
  HSSL_UNINITIALIZED  = 0x00u, ///< HSSL module is uninitiliazed
  HSSL_INIT           = 0x01u, ///< HSSL module is initiliazed
  HSSL_RUN            = 0x02u, ///< HSSL module is in lowspeed mode
  HSSL_SUSPENDED      = 0x03u  ///< HSSL module is in highspeed mode
}HSSL_StateType;

/** @brief Enumeration used for channels of the HSSL module. */
typedef enum
{
  HSSL_CHANNELID_0 = 0x00u, ///< Channel 0
  HSSL_CHANNELID_1 = 0x01u, ///< Channel 1
  HSSL_CHANNELID_2 = 0x02u, ///< Channel 2
  HSSL_CHANNELID_3 = 0x03u  ///< Channel 3
}HSSL_ChannelIdType;

/** @brief Enumeration used for the streaming mode of the HSSL module. */
typedef enum
{
  HSSL_CONTINUOUS = 0x00u,  ///< Streaming mode to Continuous
  HSSL_SINGLE     = 0x01u   ///< Streaming mode to Single
}HSSL_StreamingModeType;

/** @brief Enumeration used for the streaming mode type of the HSSL module. */
typedef enum
{
  HSSL_COMMAND   = 0x00u,  ///< Channel 2 in Command mode
  HSSL_STREAMING = 0x01u   ///< Channel 2 in Streaming mode
}HSSL_StreamingChannelModeType;

/** @brief Enumeration used for the frame request type of the HSSL module. */
typedef enum
{
  HSSL_FRAME_NOACTION = 0x00u,  ///< No action for frame request
  HSSL_FRAME_READ     = 0x01u,  ///< Read frame request
  HSSL_FRAME_WRITE    = 0x02u,  ///< Write frame request
  HSSL_FRAME_TRIGGER  = 0x03u   ///< Trigger frame request
}HSSL_FrameRequestType;

/** @brief Enumeration used for the data length type of the HSSL module. */
typedef enum
{
  HSSL_DATALEN_8BIT   = 0x00u, ///< Data length of 8 bits
  HSSL_DATALEN_16BIT  = 0x01u, ///< Data length of 16 bits
  HSSL_DATALEN_32BIT  = 0x02u  ///< Data length of 32 bits
}HSSL_DataLenType;

/** @brief Enumeration used for the return type of the HSSL module. */
typedef enum
{
  HSSL_E_OK = 0x00u, ///< Return is OK
  HSSL_E_NOK = 0x01u ///< Return is NOK
}HSSL_ReturnType;

/** @brief Enumeration used for the stream setup type of the HSSL module. */
typedef enum
{
  HSSL_SETUP_NOT_STARTED = 0x00u, ///< Setup is not started
  HSSL_STREAM_TSSA_DONE  = 0x01u, ///< Stream for TSSA register is done
  HSSL_STREAM_TSFC_DONE  = 0x02u, ///< Stream for TSFC register is done
  HSSL_STREAM_CFG_DONE   = 0x03u, ///< Stream for CFG register is done
  HSSL_SETUP_DONE        = 0x04u  ///< Setup is done
}HSSL_StreamSetupType;

/** @brief Structure used for config type of the HSSL module */
typedef struct
{
  uint16    PreDiv; ///<Variable which describes the config type of HSSL
}HSSL_ConfigType;

/** @brief Pointer to void used after the transmission is done */
typedef void (*HSSL_TransmissionDoneCbk)(void);

/** @brief Structure used to describe HSSL Internal Data */
typedef struct
{
  HSSL_StateType HsslState; ///< State of HSSL
  uint8 ui8ReceivedCOK; ///< Variable which checks if the ISR COK is received
  HSSL_TransmissionDoneCbk fpTransmissionDoneCbk; ///< Variable which indicate the end of transmission
  uint8 ui8ConfigTargetFlag; ///< Variable for the configure target flag
}HSSL_InternalData_struct;

/* ================================================================================================================= */
/*                                          Public Variables Declarations                                            */
/* ================================================================================================================= */

/* ================================================================================================================= */
/*                                           Public Functions Declarations                                           */
/* ================================================================================================================= */

/// @brief      Init function for HSSL Module.
///
/// @pre        HSSL Module is unitilized
///
/// @post       HSSL Module will be in running
///
/// @param[in] Config Config type of HSSL module
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   HSSL Module is enabled
///   If the HSSL Module is enabled "HSSL_InternalData.HsslState" is set to HSSL_RUN
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSSL_Init
///  activate CDD_MTSI
///  CDD_MTSI -> HSSL : HSSL_Init
///   activate HSSL
///    HSSL --> CDD_MTSI
///   deactivate HSSL
///  deactivate CDD_MTSI
/// @enduml
///
/// @startuml
/// title Activity Diagram for HSSL_Init
///  start
///   :Suspend all interrupts;
///   :Enable HSSL module;
///   :Resume all interrupts;
///   :Waiting for enabling the module;
///   if (HSSL Module is enabled) then (yes)
///      :Set config command to slave;
///      :Initialiaze channels;
///      :Change HsslState to HSSL_RUN;
///   else (no)
///      :Do not change the module state to HSSL_RUN;
///   endif
///  stop
/// @enduml
///
/// @testmethod
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_UnitializedHSSL() \n
///  TEST_HSSL_SendStreamBlockNOKConfigured() \n
///  TEST_HSSL_SendStreamBlockOKNotConfigured() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
///
/// @traceability
///   @satisfy{GUID_a9439b17-1eb3-4e4e-8123-5b55e072fe2f}
extern void            HSSL_Init(HSSL_ConfigType const * const Config);
extern void            HSSL_SendReadID(HSSL_ChannelIdType ChannelId, uint8 ui8TimeOut);
/// @brief      Reset function for HSSL Module.
///
/// @pre        HSSL handshake fails
///
/// @post       HSSL will be initialized
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   Kernel registers are reseted, HSSL module is enable then initialized and two reset frames are sent to the slave.
///   If the slave configurations frames are sent succefully the module will be in HSSL_RUN, if not then the module will be in HSSL_UNINITIALIZED.
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSSL_Reset
///  activate ENV
///   ENV -> HSSL : HSSL_Reset
///   activate HSSL
///    HSSL --> HSSL : HSSL_Init
///    HSSL --> HSSL : HSSL_SendFrameRequest
///    HSSL --> ENV
///   deactivate HSSL
///  deactivate ENV
/// @enduml
///
/// @startuml
/// title Activity Diagram for HSSL_Reset
///  start
///   :Disable all interrupts;
///   :Reset kernel registers;
///   :Enable HSSL module;
///   :Enable all interrupts;
///   :Initialize module;
///   :Send configuration frames to the slave;
///   :Wait for sending of the frames;
///   if (The frame was not successfully sent) then (yes)
///      :Change HsslState to HSSL_UNINITIALIZED;
///   endif
///  stop
/// @enduml
///
/// @testmethod
///  TEST_HSSL_UnitializedHSSL() \n
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_SendStreamBlockNOKConfigured() \n
///  TEST_HSSL_SendStreamBlockOKNotConfigured() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
///
extern void            HSSL_Reset(void);
/// @brief      A function which return the state of HSSL.
///
/// @pre        none
///
/// @post       none
///
/// @return     HSSL_StateType
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   Return the state of HSSL Module
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSSL_GetState
///  activate ENV
///   ENV -> HSSL : HSSL_GetStatet
///   activate HSSL
///    HSSL -> ENV
///   deactivate HSSL
///  deactivate ENV
/// @enduml
///
/// @testmethod
///  TEST_HSSL_InitializedHSCT()
extern HSSL_StateType  HSSL_GetState(void);
/// @brief      Function which triggers a stream between master and slave and if it is wanted it can configure the slave.
///
/// @pre        HSSL module should be in running mode.
///
/// @post       The streaming between master and slave is started and the block of data is sent.
///
/// @param[in]      ui32TargetAddr   The target address where the block will be sent
/// @param[in]      pData            The data from the block
/// @param[in]      ui32Length       The length of data
/// @param[in]      ConfigureTarget  Variable that shows if the target should be configured or not.
///
/// @return     HSSL_StateType
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   Triggers a stream between master and slave according to the input parameters. Also it is configuring the slave if this is wanted.
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSSL_SendStreamBlock
///  activate MTSI_Pal
///   MTSI_Pal -> HSSL : HSSL_SendStreamBlock
///   activate HSSL
///    HSSL -> HSSL : HSSL_Allign_32_Lower
///    HSSL -> HSSL : HSSL_Allign_32_Upper
///    group (HSSL_RUN == HSSL_InternalData.HsslState)
///     HSSL -> HSSL : HSSL_SetupTargetStream
///     HSSL -> HSSL : HSSL_SetupMasterStream
///    end
///    HSSL -> MTSI_Pal
///   deactivate HSSL
///  deactivate MTSI_Pal
/// @enduml
///
/// @startuml
/// title Activity Diagram for HSSL_SendStreamBLock
///  start
///   :Allign addresses;
///   if (Address of last data is bigger then the current one) then (yes)
///      :Add one more frame to length of current data;
///   endif
///   if (HsslState is HSSL_RUN) then (yes)
///      if (ConfigureTarget is true) then (yes)
///         :HSSL_SendStreamBLock gets the return value from HSSL_SetupTargetStream;
///      else (no)
///         :Return value is HSSL_E_OK;
///      endif
///      if (Return value is HSSL_E_OK) then (yes)
///         if (ConfigureTarget is true) then (yes)
///            :Configure master with data length 1;
///         else (no)
///            :Configure master with the "real length";
///         endif
///      else (no)
///         :Return value is HSSL_E_NOK;
///      endif
///   else (no)
///      :Return value is HSSL_E_NOK;
///    endif
///  stop
/// @enduml
///
/// @testmethod
///  TEST_HSSL_UnitializedHSSL() \n
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_SendStreamBlockNOKConfigured() \n
///  TEST_HSSL_SendStreamBlockOKNotConfigured() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
///  TEST_HSSL_SetupTargerStreamFailISR()
///
/// @traceability
///   @satisfy{ADC420_L3_SW_21908}
///   @satisfy{GUID_3b26132d-c6de-4257-bbcd-f9f0d2d98bf0}
extern HSSL_ReturnType HSSL_SendStreamBlock(const uint32 ui32TargetAddr,
                                            void const * const pData,
                                            const uint32 ui32Length,
                                            boolean const ConfigureTarget);
extern HSSL_ReturnType ReadFrameRequestCH1(const uint32 ui32TargetAddr, uint32 * const pui32Data);
/// @brief      Function called when the transmission is done
///
/// @pre        none
///
/// @post       fpTranmissionDoneCbk will be update with pointer to upper layer callback
///
/// @param[in]      fpTransmissionDoneCbk
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   Interface to get the transmission done callback from an upper layer
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSSL_SetTransmissionDoneCbk
///  activate MTSI_Pal
///   MTSI_Pal -> HSSL : HSSL_SetTransmissionDoneCbk
///   activate HSSL
///    HSSL --> MTSI_Pal
///   deactivate HSSL
///  deactivate MTSI_Pal
/// @enduml
///
/// @testmethod
///  TEST_HSSL_UnitializedHSSL() \n
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
extern void            HSSL_SetTransmissionDoneCbk(const HSSL_TransmissionDoneCbk fpTransmissionDoneCbk);
/// @brief      Main function for HSSL Module
///
/// @pre        none
///
/// @post       none
///
/// @globals
///   @ref HSSL_InternalData \n
///
/// @InOutCorrelation
///   According with the HSSL state different functions will be called.
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSSL_MainFunction
///  activate CDD_MTSI
///   CDD_MTSI -> HSSL : HSSL_MainFunction
///   activate HSSL
///    group (case : HSSL_UNINITIALIZED)
///     alt (HSCT_eState != HSCT_UNINITIALIZED)
///      HSSL -> HSSL : HSSL_Init
///     end
///    end
///    HSSL --> CDD_MTSI
///   deactivate HSSL
///  deactivate CDD_MTSI
/// @enduml
///
///@startuml
/// title Activity Diagram for HSSL_MainFunction
/// start
///  if (HSSL state is HSSL_UNINITIALIZED) then (yes)
///   if (HSCT state is different of HSCT_UNINITIALIZED) then (yes)
///      :Init the HSSL module;
///   else (no)
///   endif
///  elseif (HSSL state is HSSL_RUN) then (yes)
///  else (no)
///  endif
///  stop
///@enduml
///
/// @testmethod
///  TEST_HSSL_UnitializedHSSL() \n
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_SendStreamBlockNOKConfigured() \n
///  TEST_HSSL_SendStreamBlockOKNotConfigured() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
///  TEST_HSSL_SetupTargerStreamFailISR()
extern void            HSSL_MainFunction( void );
/// @brief      Alligns upper an address
///
/// @pre        none
///
/// @post       The address will be alligned
///
/// @param[in]  ui32Address The address which will be alligned
///
/// @return     uint32 Address alligned upper
///
/// @InOutCorrelation
///   Gets an address as an input and returns the address alligned upper
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSSL_Allign_32_Upper
///  activate ENV
///   ENV -> HSSL : HSSL_Allign_32_Upper
///   activate HSSL
///    HSSL -> ENV
///   deactivate HSSL
///  deactivate ENV
/// @enduml
///
/// @startuml
/// title Activity Diagram for HSSL_Allign_32_Upper
///  start
///   if (Address is 32bits alligned) then (yes)
///      :Return value gets the address as it is;
///   else (no)
///      :Address is alligned upper;
///   endif
///   :Return the alligned address;
///  stop
/// @enduml
///
/// @testmethod
///  TEST_HSSL_UnitializedHSSL() \n
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_SendStreamBlock_NOK_Configured() \n
///  TEST_HSSL_SendStreamBlock_OK_NotConfigured() \n
///  TEST_HSSL_SendStreamBlock_OK_Configured() \n
///  TEST_HSSL_SetupTargerStream_Fail_ISR()
extern uint32          HSSL_Allign_32_Upper(const uint32 ui32Address);
/// @brief      Alligns lower an address
///
/// @pre        none
///
/// @post       The address will be alligned
///
/// @param[in]  ui32Address The address which will be alligned
///
/// @return     uint32 Address alligned lower
///
/// @InOutCorrelation
///   Gets an address as an input and returns the address alligned lower
///
/// @callsequence
/// @startuml
/// title Sequence Diagram for HSSL_Allign_32_Lower
///  activate ENV
///   ENV -> HSSL : HSSL_Allign_32_Lower
///   activate HSSL
///    HSSL -> ENV
///   deactivate HSSL
///  deactivate ENV
/// @enduml
//
/// @testmethod
///  TEST_HSSL_UnitializedHSSL() \n
///  TEST_HSSL_InitializedHSCT() \n
///  TEST_HSSL_SendStreamBlockNOKConfigured() \n
///  TEST_HSSL_SendStreamBlockOKNotConfigured() \n
///  TEST_HSSL_SendStreamBlockOKConfigured() \n
///  TEST_HSSL_SetupTargerStreamFailISR()
extern uint32          HSSL_Allign_32_Lower(const uint32 ui32Address);
extern uint32 HSSL_GetIsrBlockCount(void);
#ifdef __cplusplus
}
#endif

#endif

/** @} doxygen end group definition  */
/** @} doxygen end group definition  */

/* ================================================================================================================= */
/*                                                     End of File                                                   */
/* ================================================================================================================= */
